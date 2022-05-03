/**
 * gemm.c: This file is part of the PolyBench/C 3.2 test suite.
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
void init_array(int ni, int nj, int nk,
    int *alpha,
    int *beta,
    int C[ni][nj],
    int A[ni][nk],
    int B[nk][nj])
{
  int i, j;

  *alpha = 32412;
  *beta = 2123;
  for (i = 0; i < ni; i++)
    for (j = 0; j < nj; j++)
      C[i][j] = ((int) i*j) / ni;
  for (i = 0; i < ni; i++)
    for (j = 0; j < nk; j++)
      A[i][j] = ((int) i*j) / ni;
  for (i = 0; i < nk; i++)
    for (j = 0; j < nj; j++)
      B[i][j] = ((int) i*j) / ni;
}




  static
void print_array(int ni, int nj,
    int C[ni][nj])
{
  int i, j;

  for (i = 0; i < ni; i++)
    for (j = 0; j < nj; j++) {
      printf("%d ", C[i][j]);
      if ((i * ni + j) % 20 == 0) printf("\n");
    }
  printf("\n");
}




  static
void kernel_gemm(int ni, int nj, int nk,
    int alpha,
    int beta,
    int C[ni][nj],
    int A[ni][nk],
    int B[nk][nj])
{
  int i, j, k;

#pragma scop

  for (i = 0; i < ni; i++)
    for (j = 0; j < nj; j++)
    {
      C[i][j] *= beta;
      for (k = 0; k < nk; ++k)
        C[i][j] += alpha * A[i][k] * B[k][j];
    }
#pragma endscop

}


int main(int argc, char** argv)
{

  int ni = N;
  int nj = N;
  int nk = N;

  int alpha;
  int beta;
  int C[ni][nj];
  int A[ni][nk];
  int B[nk][nj];


  init_array (ni, nj, nk, &alpha, &beta,
      C,
      A,
      B);




  kernel_gemm (ni, nj, nk,
      alpha, beta,
      C,
      A,
      B);



  print_array(ni, nj, C);

  return 0;
}
