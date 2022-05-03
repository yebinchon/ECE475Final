/**
 * atax.c: This file is part of the PolyBench 3.0 test suite.
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
/* Default data type is int, default size is 4000. */
#define NX 40
#define NY 40

/* Array initialization. */
static
void init_array (int nx, int ny,
		 int A[nx][ny],
		 int x[ny])
{
  int i, j;

  for (i = 0; i < ny; i++)
      x[i] = i * M_PI;
  for (i = 0; i < nx; i++)
    for (j = 0; j < ny; j++)
      A[i][j] = ((int) i*(j+1)) / nx;
}


/* DCE code. Must scan the entire live-out data.
   Can be used also to check the correctness of the output. */
static
void print_array(int nx,
		 int y[nx])

{
  int i;

  for (i = 0; i < nx; i++) {
    printf("%d ", y[i]);
    if (i % 20 == 0) printf("\n");
  }
  printf("\n");
}


/* Main computational kernel. The whole function will be timed,
   including the call and return. */
static
void kernel_atax(int nx, int ny,
		 int A[nx][ny],
		 int x[ny],
		 int y[nx],
		 int tmp[ny])
{
  int i, j;

#pragma scop
  for (i= 0; i < nx; i++)
    y[i] = 0;
  for (i = 0; i < ny; i++)
    {
      tmp[i] = 0;
      for (j = 0; j < ny; j++)
	tmp[i] = tmp[i] + A[i][j] * x[j];
      for (j = 0; j < ny; j++)
	y[j] = y[j] + A[i][j] * tmp[i];
    }
#pragma endscop

}


int main(int argc, char** argv)
{
  /* Retrieve problem size. */
  int nx = NX;
  int ny = NY;

  /* Variable declaration/allocation. */
  int A[nx][ny];
  int x[ny];
  int y[nx];
  int tmp[ny];

  /* Initialize array(s). */
  init_array (nx, ny, A, x);


  /* Run kernel. */
  kernel_atax (nx, ny,
        A, x, y, tmp);


  /* Prevent dead-code elimination. All live-out data must be printed
     by the function call in argument. */
  print_array(nx, y);

  return 0;
}
