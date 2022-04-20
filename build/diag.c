/**
 * 2mm.c: This file is part of the PolyBench/C 3.2 test suite.
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

#define DUMP_CODE 1
#define NI 10
#define NJ 10
#define NL 10
#define NK 10


  static
void init_array(int ni, int nj, int nk, int nl,
    double *alpha,
    double *beta,
    double A[ni][nl],
    double B[nk][nj],
    double C[nl][nj],
    double D[ni][nl])
{
  int i, j;

  *alpha = 32412;
  *beta = 2123;
  for (i = 0; i < ni; i++)
    for (j = 0; j < nk; j++)
      A[i][j] = ((double) i*j) / ni;
  for (i = 0; i < nk; i++)
    for (j = 0; j < nj; j++)
      B[i][j] = ((double) i*(j+1)) / nj;
  for (i = 0; i < nl; i++)
    for (j = 0; j < nj; j++)
      C[i][j] = ((double) i*(j+3)) / nl;
  for (i = 0; i < ni; i++)
    for (j = 0; j < nl; j++)
      D[i][j] = ((double) i*(j+2)) / nk;
}




  static
void print_array(int ni, int nl,
    double D[ni][nl])
{
  int i, j;

  for (i = 0; i < ni; i++)
    for (j = 0; j < nl; j++) {
      printf ("%0.2lf ", D[i][j]);
      if ((i * ni + j) % 20 == 0) printf ("\n");
    }
  printf ("\n");
}




  static
void kernel_2mm(int ni, int nj, int nk, int nl,
    double alpha,
    double beta,
    double tmp[ni][nj],
    double A[ni][nk],
    double B[nk][nj],
    double C[nl][nj],
    double D[ni][nl])
{
  int i, j, k;

#pragma scop

  for (i = 0; i < ni; i++)
    for (j = 0; j < nj; j++)
    {
      tmp[i][j] = 0;
      for (k = 0; k < nk; ++k)
        tmp[i][j] += alpha * A[i][k] * B[k][j];
    }
  for (i = 0; i < ni; i++)
    for (j = 0; j < nl; j++)
    {
      D[i][j] *= beta;
      for (k = 0; k < nj; ++k)
        D[i][j] += tmp[i][k] * C[k][j];
    }
#pragma endscop

}


int main(int argc, char** argv)
{
  int dump_code = DUMP_CODE;
  int ni = NI;
  int nj = NJ;
  int nk = NK;
  int nl = NL;


  double alpha;
  double beta;
  double tmp[ni][nj];
  double A[ni][nk];
  double B[nk][nj];
  double C[nl][nj];
  double D[ni][nl];


  init_array (ni, nj, nk, nl, &alpha, &beta,
      A,
      B,
      C,
      D);




  kernel_2mm (ni, nj, nk, nl,
      alpha, beta,
      tmp,
      A,
      B,
      C,
      D);





  if (dump_code == 1) print_array(ni, nl, D);

  return 0;
}
