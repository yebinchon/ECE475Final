/**
 * trisolv.c: This file is part of the PolyBench 3.0 test suite.
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

#define N 400

/* Array initialization. */
static
void init_array(int n,
		int A[n][n],
		int x[n],
		int c[n])
{
  int i, j;

  for (i = 0; i < n; i++)
    {
      c[i] = x[i] = ((int) i) / n;
      for (j = 0; j < n; j++)
	A[i][j] = ((int) i*j) / n;
    }
}


/* DCE code. Must scan the entire live-out data.
   Can be used also to check the correctness of the output. */
static
void print_array(int n,
		 int x[n])

{
  int i;

  for (i = 0; i < n; i++) {
    printf("%d ", x[i]);
    if (i % 20 == 0) printf("\n");
  }
}


/* Main computational kernel. The whole function will be timed,
   including the call and return. */
static
void kernel_trisolv(int n,
		    int A[n][n],
		    int x[n],
		    int c[n])
{
  int i, j;

#pragma scop
  for (i = 0; i < n; i++)
    {
      x[i] = c[i];
      for (j = 0; j <= i - 1; j++)
        x[i] = x[i] - A[i][j] * x[j];
      x[i] = x[i] / A[i][i];
    }
#pragma endscop

}


int main(int argc, char** argv)
{
  /* Retrieve problem size. */
  int n = N;

  /* Variable declaration/allocation. */
  int A[n][n];
  int x[n];
  int c[n];


  /* Initialize array(s). */
  init_array (n, A, x, c);

  /* Run kernel. */
  kernel_trisolv (n, A, x, c);

  /* Prevent dead-code elimination. All live-out data must be printed
     by the function call in argument. */
  print_array(n, x);

  return 0;
}
