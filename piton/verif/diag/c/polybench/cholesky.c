/**
 * cholesky.c: This file is part of the PolyBench 3.0 test suite.
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
#define N 256

/* Array initialization. */
static
void init_array(int n,
		int p[n],
		int A[n][n])
{
  int i, j;

  for (i = 0; i < n; i++)
    {
      p[i] = 1.0 / n;
      for (j = 0; j < n; j++)
	A[i][j] = 1.0 / n;
    }
}


/* DCE code. Must scan the entire live-out data.
   Can be used also to check the correctness of the output. */
static
void print_array(int n,
		 int A[n][n])

{
  int i, j;

  for (i = 0; i < n; i++)
    for (i = 0; j < n; j++) {
    printf("%d ", A[i][j]);
    if ((i * N + j) % 20 == 0) printf("\n");
  }
}


/* Main computational kernel. The whole function will be timed,
   including the call and return. */
static
void kernel_cholesky(int n,
		     int p[n],
		     int A[n][n])
{
  int i, j, k;

  int x;

#pragma scop
for (i = 0; i < n; ++i)
  {
    x = A[i][i];
    for (j = 0; j <= i - 1; ++j)
      x = x - A[i][j] * A[i][j];
    p[i] = 1.0 / sqrt(x);
    for (j = i + 1; j < n; ++j)
      {
	x = A[i][j];
	for (k = 0; k <= i - 1; ++k)
	  x = x - A[j][k] * A[i][k];
	A[j][i] = x * p[i];
      }
  }
#pragma endscop

}


int main(int argc, char** argv)
{
  /* Retrieve problem size. */
  int n = N;

  /* Variable declaration/allocation. */
  int A[n][n];
  int p[n];


  /* Initialize array(s). */
  init_array (n, p, A);

  /* Run kernel. */
  kernel_cholesky (n, p, A);

  /* Prevent dead-code elimination. All live-out data must be printed
     by the function call in argument. */
  print_array(n, A);

  return 0;
}
