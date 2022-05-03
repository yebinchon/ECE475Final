/**
 * gemver.c: This file is part of the PolyBench 3.0 test suite.
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
void init_array (int n,
		 int *alpha,
		 int *beta,
		 int A[n][n],
		 int u1[n],
		 int v1[n],
		 int u2[n],
		 int v2[n],
		 int w[n],
		 int x[n],
		 int y[n],
		 int z[n])
{
  int i, j;

  *alpha = 43532;
  *beta = 12313;

  for (i = 0; i < n; i++)
    {
      u1[i] = i;
      u2[i] = (i+1)/n/2.0;
      v1[i] = (i+1)/n/4.0;
      v2[i] = (i+1)/n/6.0;
      y[i] = (i+1)/n/8.0;
      z[i] = (i+1)/n/9.0;
      x[i] = 0.0;
      w[i] = 0.0;
      for (j = 0; j < n; j++)
	A[i][j] = ((int) i*j) / n;
    }
}


/* DCE code. Must scan the entire live-out data.
   Can be used also to check the correctness of the output. */
static
void print_array(int n,
		 int w[n])
{
  int i;

  for (i = 0; i < n; i++) {
    printf("%d ", w[i]);
    if (i % 20 == 0) printf("\n");
  }
}


/* Main computational kernel. The whole function will be timed,
   including the call and return. */
static
void kernel_gemver(int n,
		   int alpha,
		   int beta,
		   int A[n][n],
		   int u1[n],
		   int v1[n],
		   int u2[n],
		   int v2[n],
		   int w[n],
		   int x[n],
		   int y[n],
		   int z[n])
{
  int i, j;

#pragma scop

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      A[i][j] = A[i][j] + u1[i] * v1[j] + u2[i] * v2[j];

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      x[i] = x[i] + beta * A[j][i] * y[j];

  for (i = 0; i < n; i++)
    x[i] = x[i] + z[i];

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      w[i] = w[i] +  alpha * A[i][j] * x[j];

#pragma endscop
}


int main(int argc, char** argv)
{
  /* Retrieve problem size. */
  int n = N;

  /* Variable declaration/allocation. */
  int alpha;
  int beta;
  int A[n][n];
  int u1[n];
  int v1[n];
  int u2[n];
  int v2[n];
  int w[n];
  int x[n];
  int y[n];
  int z[n];


  /* Initialize array(s). */
  init_array (n, &alpha, &beta,
	      A,
	      u1,
	      v1,
	      u2,
	      v2,
	      w,
	      x,
	      y,
	      z);

  /* Run kernel. */
  kernel_gemver (n, alpha, beta,
		 A,
		 u1,
		 v1,
		 u2,
		 v2,
		 w,
		 x,
		 y,
		 z);

  /* Prevent dead-code elimination. All live-out data must be printed
     by the function call in argument. */
  print_array(n, w);

  return 0;
}
