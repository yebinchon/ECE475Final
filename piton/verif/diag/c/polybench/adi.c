/**
 * adi.c: This file is part of the PolyBench 3.0 test suite.
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
/* Default data type is int, default size is 10x1024x1024. */
#define N 16
#define TSTEPS 5


/* Array initialization. */
static
void init_array (int n,
		 int X[n][n],
		 int A[n][n],
		 int B[n][n])
{
  int i, j;

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      {
	    X[i][j] = ((int) i*(j+1) + 1) / n;
	    A[i][j] = ((int) i*(j+2) + 2) / n;
	    B[i][j] = ((int) i*(j+3) + 3) / n;
      }
}


/* DCE code. Must scan the entire live-out data.
   Can be used also to check the correctness of the output. */
static
void print_array(int n,
		 int X[n][n])

{
  int i, j;

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
      printf("%0.2lf ", X[i][j]);
      if ((i * n + j) % 20 == 0) printf("\n");
    }
  printf("\n");
}


/* Main computational kernel. The whole function will be timed,
   including the call and return. */
static
void kernel_adi(int tsteps,
		int n,
		int X[n][n],
		int A[n][n],
		int B[n][n])
{
  int t, i1, i2;

#pragma scop
  for (t = 0; t < tsteps; t++)
    {
      for (i1 = 0; i1 < n; i1++)
	for (i2 = 1; i2 < n; i2++)
	  {
	    X[i1][i2] = X[i1][i2] - X[i1][i2-1] * A[i1][i2] / B[i1][i2-1];
	    B[i1][i2] = B[i1][i2] - A[i1][i2] * A[i1][i2] / B[i1][i2-1];
	  }

      for (i1 = 0; i1 < n; i1++)
	X[i1][n-1] = X[i1][n-1] / B[i1][n-1];

      for (i1 = 0; i1 < n; i1++)
	for (i2 = 0; i2 < n-2; i2++)
	  X[i1][n-i2-2] = (X[i1][n-2-i2] - X[i1][n-2-i2-1] * A[i1][n-i2-3]) / B[i1][n-3-i2];

      for (i1 = 1; i1 < n; i1++)
	for (i2 = 0; i2 < n; i2++) {
	  X[i1][i2] = X[i1][i2] - X[i1-1][i2] * A[i1][i2] / B[i1-1][i2];
	  B[i1][i2] = B[i1][i2] - A[i1][i2] * A[i1][i2] / B[i1-1][i2];
	}

      for (i2 = 0; i2 < n; i2++)
	X[n-1][i2] = X[n-1][i2] / B[n-1][i2];

      for (i1 = 0; i1 < n-2; i1++)
	for (i2 = 0; i2 < n; i2++)
	  X[n-2-i1][i2] = (X[n-2-i1][i2] - X[n-i1-3][i2] * A[n-3-i1][i2]) / B[n-2-i1][i2];
    }
#pragma endscop

}


int main(int argc, char** argv)
{
  /* Retrieve problem size. */
  int n = N;
  int tsteps = TSTEPS;

  /* Variable declaration/allocation. */

  int X[n][n];
  int A[n][n];
  int B[n][n];


  /* Initialize array(s). */
  init_array (n, X, A, B);

  /* Run kernel. */
  kernel_adi (tsteps, n, X, A, B);


  /* Prevent dead-code elimination. All live-out data must be printed
     by the function call in argument. */
  print_array(n, X);

  return 0;
}
