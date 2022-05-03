/**
 * mvt.c: This file is part of the PolyBench 3.0 test suite.
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
#define N 400

/* Array initialization. */
static
void init_array(int n,
		int x1[n],
		int x2[n],
		int y_1[n],
		int y_2[n],
		int A[n][n])
{
  int i, j;

  for (i = 0; i < n; i++)
    {
      x1[i] = ((int) i) / n;
      x2[i] = ((int) i + 1) / n;
      y_1[i] = ((int) i + 3) / n;
      y_2[i] = ((int) i + 4) / n;
      for (j = 0; j < n; j++)
	A[i][j] = ((int) i*j) / n;
    }
}


/* DCE code. Must scan the entire live-out data.
   Can be used also to check the correctness of the output. */
static
void print_array(int n,
		 int x1[n],
		 int x2[n])

{
  int i;

  for (i = 0; i < n; i++) {
    printf("%d", x1[i]);
    printf("%d", x2[i]);
    if (i % 20 == 0) printf("\n");
  }
}


/* Main computational kernel. The whole function will be timed,
   including the call and return. */
static
void kernel_mvt(int n,
		int x1[n],
		int x2[n],
		int y_1[n],
		int y_2[n],
		int A[n][n])
{
  int i, j;

#pragma scop
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      x1[i] = x1[i] + A[i][j] * y_1[j];
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      x2[i] = x2[i] + A[j][i] * y_2[j];
#pragma endscop

}


int main(int argc, char** argv)
{
  /* Retrieve problem size. */
  int n = N;

  /* Variable declaration/allocation. */
  int A[n][n];
  int x1[n];
  int x2[n];
  int y_1[n];
  int y_2[n];


  /* Initialize array(s). */
  init_array (n,
	      x1,
	      x2,
	      y_1,
	      y_2,
	      A);

  /* Run kernel. */
  kernel_mvt (n,
	      x1,
	      x2,
	      y_1,
	      y_2,
	      A);

  /* Prevent dead-code elimination. All live-out data must be printed
     by the function call in argument. */
  print_array(n, x1, x2);

  return 0;
}
