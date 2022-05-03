/**
 * gesummv.c: This file is part of the PolyBench 3.0 test suite.
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
		int *alpha,
		int *beta,
		int A[n][n],
		int B[n][n],
		int x[n])
{
  int i, j;

  *alpha = 43532;
  *beta = 12313;
  for (i = 0; i < n; i++)
    {
      x[i] = ((int) i) / n;
      for (j = 0; j < n; j++) {
	A[i][j] = ((int) i*j) / n;
	B[i][j] = ((int) i*j) / n;
      }
    }
}


/* DCE code. Must scan the entire live-out data.
   Can be used also to check the correctness of the output. */
static
void print_array(int n,
		 int y[n])

{
  int i;

  for (i = 0; i < n; i++) {
    printf("%d ", y[i]);
    if (i % 20 == 0) printf("\n");
  }
}


/* Main computational kernel. The whole function will be timed,
   including the call and return. */
static
void kernel_gesummv(int n,
		    int alpha,
		    int beta,
		    int A[n][n],
		    int B[n][n],
		    int tmp[n],
		    int x[n],
		    int y[n])
{
  int i, j;

#pragma scop
  for (i = 0; i < n; i++)
    {
      tmp[i] = 0;
      y[i] = 0;
      for (j = 0; j < n; j++)
	{
	  tmp[i] = A[i][j] * x[j] + tmp[i];
	  y[i] = B[i][j] * x[j] + y[i];
	}
      y[i] = alpha * tmp[i] + beta * y[i];
    }
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
  int B[n][n];
  int tmp[n];
  int x[n];
  int y[n];


  /* Initialize array(s). */
  init_array (n, &alpha, &beta,
	      A,
	      B,
	      x);

  /* Run kernel. */
  kernel_gesummv (n, alpha, beta,
		  A,
		  B,
		  tmp,
		  x,
		  y);

  /* Prevent dead-code elimination. All live-out data must be printed
     by the function call in argument. */
  print_array(n, y);

  return 0;
}
