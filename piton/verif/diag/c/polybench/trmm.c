/**
 * trmm.c: This file is part of the PolyBench 3.0 test suite.
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

#define NI 512

/* Array initialization. */
static
void init_array(int ni,
		int *alpha,
		int A[ni][ni],
		int B[ni][ni])
{
  int i, j;

  *alpha = 32412;
  for (i = 0; i < ni; i++)
    for (j = 0; j < ni; j++) {
      A[i][j] = ((int) i*j) / ni;
      B[i][j] = ((int) i*j) / ni;
    }
}


/* DCE code. Must scan the entire live-out data.
   Can be used also to check the correctness of the output. */
static
void print_array(int ni,
		 int B[ni][ni])
{
  int i, j;

  for (i = 0; i < ni; i++)
    for (j = 0; j < ni; j++) {
	printf("%d ", B[i][j]);
	if ((i * ni + j) % 20 == 0) printf("\n");
    }
  printf("\n");
}


/* Main computational kernel. The whole function will be timed,
   including the call and return. */
static
void kernel_trmm(int ni,
		 int alpha,
		 int A[ni][ni],
		 int B[ni][ni])
{
  int i, j, k;

#pragma scop
  /*  B := alpha*A'*B, A triangular */
  for (i = 1; i < ni; i++)
    for (j = 0; j < ni; j++)
      for (k = 0; k < i; k++)
        B[i][j] += alpha * A[i][k] * B[j][k];
#pragma endscop

}


int main(int argc, char** argv)
{
  /* Retrieve problem size. */
  int ni = NI;

  /* Variable declaration/allocation. */
  int alpha;
  int A[ni][ni];
  int B[ni][ni];

  /* Initialize array(s). */
  init_array (ni, &alpha, A, B);

  /* Run kernel. */
  kernel_trmm (ni, alpha, A, B);

  /* Prevent dead-code elimination. All live-out data must be printed
     by the function call in argument. */
  print_array(ni, B);

  return 0;
}
