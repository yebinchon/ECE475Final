/**
 * fdtd-2d.c: This file is part of the PolyBench 3.0 test suite.
 *
 *
 * Contact: Louis-Noel Pouchet <pouchet@cse.ohio-state.edu>
 * Web address: http://polybench.sourceforge.net
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

/* Include benchmark-specific header. */
/* Default data type is int, default size is 50x1000x1000. */
#define TMAX 2
#define NX 16
#define NY 16


/* Array initialization. */
static
void init_array (int nx,
		 int ny,
		 int ex[nx][ny],
		 int ey[nx][ny],
		 int hz[nx][ny],
		 int _fict_[ny])
{
  int i, j;

  for (i = 0; i < ny; i++)
    _fict_[i] = (int) i;
  for (i = 0; i < nx; i++)
    for (j = 0; j < ny; j++)
      {
	ex[i][j] = ((int) i*(j+1)) / nx;
	ey[i][j] = ((int) i*(j+2)) / ny;
	hz[i][j] = ((int) i*(j+3)) / nx;
      }
}


/* DCE code. Must scan the entire live-out data.
   Can be used also to check the correctness of the output. */
static
void print_array(int nx,
		 int ny,
		 int ex[nx][ny],
		 int ey[nx][ny],
		 int hz[nx][ny])
{
  int i, j;

  for (i = 0; i < nx; i++)
    for (j = 0; j < ny; j++) {
      printf("%d ", ex[i][j]);
      printf("%d ", ey[i][j]);
      printf("%d ", hz[i][j]);
      if ((i * nx + j) % 20 == 0) printf("\n");
    }
  printf("\n");
}


/* Main computational kernel. The whole function will be timed,
   including the call and return. */
static
void kernel_fdtd_2d(int tmax,
		    int nx,
		    int ny,
		    int ex[nx][ny],
		    int ey[nx][ny],
		    int hz[nx][ny],
		    int _fict_[ny])
{
  int t, i, j;

#pragma scop

  for(t = 0; t < tmax; t++)
    {
      for (j = 0; j < ny; j++)
	ey[0][j] = _fict_[t];
      for (i = 1; i < nx; i++)
	for (j = 0; j < ny; j++)
	  ey[i][j] = ey[i][j] - 0.5*(hz[i][j]-hz[i-1][j]);
      for (i = 0; i < nx; i++)
	for (j = 1; j < ny; j++)
	  ex[i][j] = ex[i][j] - 0.5*(hz[i][j]-hz[i][j-1]);
      for (i = 0; i < nx - 1; i++)
	for (j = 0; j < ny - 1; j++)
	  hz[i][j] = hz[i][j] - 0.7*  (ex[i][j+1] - ex[i][j] +
				       ey[i+1][j] - ey[i][j]);
    }

#pragma endscop
}


int main(int argc, char** argv)
{
  /* Retrieve problem size. */
  int tmax = TMAX;
  int nx = NX;
  int ny = NY;

  /* Variable declaration/allocation. */
  int ex[nx][ny];
  int ey[nx][ny];
  int hz[nx][ny];
  int _fict_[ny];

  /* Initialize array(s). */
  init_array (nx, ny,
	      ex,
	      ey,
	      hz,
	      _fict_);

  /* Run kernel. */
  kernel_fdtd_2d (tmax, nx, ny,
	      ex,
	      ey,
	      hz,
	      _fict_);

  /* Prevent dead-code elimination. All live-out data must be printed
     by the function call in argument. */
  print_array(nx, ny, ex, ey, hz);

  return 0;
}
