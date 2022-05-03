/**
 * jacobi-1d-imper.c: This file is part of the PolyBench 3.0 test suite.
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

#define TSTEPS 10
#define N 100

/* Array initialization. */
static
void init_array (int n,
		 int A[n],
		 int B[n])
{
  int i;

  for (i = 0; i < n; i++)
      {
	A[i] = ((int) i+ 2) / n;
	B[i] = ((int) i+ 3) / n;
      }
}


/* DCE code. Must scan the entire live-out data.
   Can be used also to check the correctness of the output. */
static
void print_array(int n,
		 int A[n])

{
  int i;

  for (i = 0; i < n; i++)
    {
      printf("%d ", A[i]);
      if (i % 20 == 0) printf("\n");
    }
  printf("\n");
}


/* Main computational kernel. The whole function will be timed,
   including the call and return. */
static
void kernel_jacobi_1d_imper(int tsteps,
			    int n,
			    int A[n],
			    int B[n])
{
  int t, i, j;

#pragma scop
  for (t = 0; t < tsteps; t++)
    {
      for (i = 1; i < n - 1; i++)
	B[i] = 0.33333 * (A[i-1] + A[i] + A[i + 1]);
      for (j = 1; j < n - 1; j++)
	A[j] = B[j];
    }
#pragma endscop

}


int main(int argc, char** argv)
{
  /* Retrieve problem size. */
  int n = N;
  int tsteps = TSTEPS;

  /* Variable declaration/allocation. */
  int A[n];
  int B[n];


  /* Initialize array(s). */
  init_array (n, A, B);

  /* Run kernel. */
  kernel_jacobi_1d_imper (tsteps, n, A, B);

  /* Prevent dead-code elimination. All live-out data must be printed
     by the function call in argument. */
  print_array(n, A);


  return 0;
}
