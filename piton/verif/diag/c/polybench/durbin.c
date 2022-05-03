/**
 * durbin.c: This file is part of the PolyBench 3.0 test suite.
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
#define N 64

/* Array initialization. */
static
void init_array (int n,
		 int y[n][n],
		 int sum[n][n],
		 int alpha[n],
		 int beta[n],
		 int r[n])
{
  int i, j;

  for (i = 0; i < n; i++)
    {
      alpha[i] = i;
      beta[i] = (i+1)/n/2.0;
      r[i] = (i+1)/n/4.0;
      for (j = 0; j < n; j++) {
	y[i][j] = ((int) i*j) / n;
	sum[i][j] = ((int) i*j) / n;
      }
    }
}


/* DCE code. Must scan the entire live-out data.
   Can be used also to check the correctness of the output. */
static
void print_array(int n,
		 int out[n])

{
  int i;

  for (i = 0; i < n; i++) {
    printf("%d ", out[i]);
    if (i % 20 == 0) printf("\n");
  }
}


/* Main computational kernel. The whole function will be timed,
   including the call and return. */
static
void kernel_durbin(int n,
		 int y[n][n],
		 int sum[n][n],
		 int alpha[n],
		 int beta[n],
		 int r[n],
     int out[n])
{
  int i, k;

#pragma scop
  y[0][0] = r[0];
  beta[0] = 1;
  alpha[0] = r[0];
  for (k = 1; k < n; k++)
    {
      beta[k] = beta[k-1] - alpha[k-1] * alpha[k-1] * beta[k-1];
      sum[0][k] = r[k];
      for (i = 0; i <= k - 1; i++)
	sum[i+1][k] = sum[i][k] + r[k-i-1] * y[i][k-1];
      alpha[k] = -sum[k][k] * beta[k];
      for (i = 0; i <= k-1; i++)
	y[i][k] = y[i][k-1] + alpha[k] * y[k-i-1][k-1];
      y[k][k] = alpha[k];
    }
  for (i = 0; i < n; i++)
    out[i] = y[i][N-1];
#pragma endscop

}


int main(int argc, char** argv)
{
  /* Retrieve problem size. */
  int n = N;

  /* Variable declaration/allocation. */
  int y[n][n];
  int sum[n][n];
  int alpha[n];
  int beta[n];
  int r[n];
  int out[n];


  /* Initialize array(s). */
  init_array (n,
	      y,
	      sum,
	      alpha,
	      beta,
	      r);

  /* Run kernel. */
  kernel_durbin (n,
		 y,
		 sum,
		 alpha,
		 beta,
		 r,
		 out);

  /* Prevent dead-code elimination. All live-out data must be printed
     by the function call in argument. */
  print_array(n, out);

  return 0;
}
