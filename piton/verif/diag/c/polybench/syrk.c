/**
 * syrk.c: This file is part of the PolyBench/C 3.2 test suite.
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

#define N 32

  static
void init_array(int ni, int nj,
    int *alpha,
    int *beta,
    int C[ni][ni],
    int A[ni][nj])
{
  int i, j;

  *alpha = 32412;
  *beta = 2123;
  for (i = 0; i < ni; i++)
    for (j = 0; j < nj; j++)
      A[i][j] = ((int) i*j) / ni;
  for (i = 0; i < ni; i++)
    for (j = 0; j < ni; j++)
      C[i][j] = ((int) i*j) / ni;
}




  static
void print_array(int ni,
    int C[ni][ni])
{
  int i, j;

  for (i = 0; i < ni; i++)
    for (j = 0; j < ni; j++) {
      printf("%d ", C[i][j]);
      if ((i * ni + j) % 20 == 0) printf("\n");
    }
  printf("\n");
}




  static
void kernel_syrk(int ni, int nj,
    int alpha,
    int beta,
    int C[ni][ni],
    int A[ni][nj])
{
  int i, j, k;

#pragma scop

  for (i = 0; i < ni; i++)
    for (j = 0; j < ni; j++)
      C[i][j] *= beta;
  for (i = 0; i < ni; i++)
    for (j = 0; j < ni; j++)
      for (k = 0; k < nj; k++)
        C[i][j] += alpha * A[i][k] * A[j][k];
#pragma endscop

}


int main(int argc, char** argv)
{
  int ni = N;
  int nj = N;

  int alpha;
  int beta;
  int C[ni][ni];
  int A[ni][nj];


  init_array (ni, nj, &alpha, &beta, C, A);

  kernel_syrk (ni, nj, alpha, beta, C, A);

  print_array(ni, C);

  return 0;
}
