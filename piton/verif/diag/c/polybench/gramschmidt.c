/**
 * gramschmidt.c: This file is part of the PolyBench/C 3.2 test suite.
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

#define N 40


  static
void init_array(int ni, int nj,
    int A[ni][nj],
    int R[nj][nj],
    int Q[ni][nj])
{
  int i, j;

  for (i = 0; i < ni; i++)
    for (j = 0; j < nj; j++) {
      A[i][j] = ((int) i*j) / ni;
      Q[i][j] = ((int) i*(j+1)) / nj;
    }
  for (i = 0; i < nj; i++)
    for (j = 0; j < nj; j++)
      R[i][j] = ((int) i*(j+2)) / nj;
}




  static
void print_array(int ni, int nj,
    int A[ni][nj],
    int R[nj][nj],
    int Q[ni][nj])
{
  int i, j;

  for (i = 0; i < ni; i++)
    for (j = 0; j < nj; j++) {
      printf("%d ", A[i][j]);
      if (i % 20 == 0) printf("\n");
    }
  printf("\n");
  for (i = 0; i < nj; i++)
    for (j = 0; j < nj; j++) {
      printf("%d ", R[i][j]);
      if (i % 20 == 0) printf("\n");
    }
  printf("\n");
  for (i = 0; i < ni; i++)
    for (j = 0; j < nj; j++) {
      printf("%d ", Q[i][j]);
      if (i % 20 == 0) printf("\n");
    }
  printf("\n");
}




  static
void kernel_gramschmidt(int ni, int nj,
    int A[ni][nj],
    int R[nj][nj],
    int Q[ni][nj])
{
  int i, j, k;

  int nrm;

#pragma scop
  for (k = 0; k < nj; k++)
  {
    nrm = 0;
    for (i = 0; i < ni; i++)
      nrm += A[i][k] * A[i][k];
    R[k][k] = sqrt(nrm);
    for (i = 0; i < ni; i++)
      Q[i][k] = A[i][k] / R[k][k];
    for (j = k + 1; j < nj; j++)
    {
      R[k][j] = 0;
      for (i = 0; i < ni; i++)
        R[k][j] += Q[i][k] * A[i][j];
      for (i = 0; i < ni; i++)
        A[i][j] = A[i][j] - Q[i][k] * R[k][j];
    }
  }
#pragma endscop

}


int main(int argc, char** argv)
{

  int ni = N;
  int nj = N;

  int A[ni][nj];
  int R[nj][nj];
  int Q[ni][nj];


  init_array (ni, nj,
      A,
      R,
      Q);




  kernel_gramschmidt (ni, nj,
      A,
      R,
      Q);


  print_array(ni, nj, A, R, Q);

  return 0;
}
