/**
 * symm.c: This file is part of the PolyBench/C 3.2 test suite.
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
    int C[ni][nj],
    int A[nj][nj],
    int B[ni][nj])
{
  int i, j;

  *alpha = 32412;
  *beta = 2123;
  for (i = 0; i < ni; i++)
    for (j = 0; j < nj; j++) {
      C[i][j] = ((int) i*j) / ni;
      B[i][j] = ((int) i*j) / ni;
    }
  for (i = 0; i < nj; i++)
    for (j = 0; j < nj; j++)
      A[i][j] = ((int) i*j) / ni;
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
void kernel_symm(int ni, int nj,
    int alpha,
    int beta,
    int C[ni][nj],
    int A[nj][nj],
    int B[ni][nj])
{
  int i, j, k;
  int acc;

#pragma scop

  for (i = 0; i < ni; i++)
    for (j = 0; j < nj; j++)
    {
      acc = 0;
      for (k = 0; k < j - 1; k++)
      {
        C[k][j] += alpha * A[k][i] * B[i][j];
        acc += B[k][j] * A[k][i];
      }
      C[i][j] = beta * C[i][j] + alpha * A[i][i] * B[i][j] + alpha * acc;
    }
#pragma endscop

}


int main(int argc, char** argv)
{
  int ni = N;
  int nj = N;

  int alpha;
  int beta;
  int C[ni][nj];
  int A[nj][nj];
  int B[ni][nj];


  init_array (ni, nj, &alpha, &beta,
      C,
      A,
      B);




  kernel_symm (ni, nj,
      alpha, beta,
      C,
      A,
      B);





  print_array(ni, nj, C);

  return 0;
}
