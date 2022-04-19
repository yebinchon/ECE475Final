/**
 * 3mm.c: This file is part of the PolyBench/C 3.2 test suite.
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
#define NK 10
#define NJ 10
#define NL 10
#define NM 10

  static
void init_array(int ni, int nj, int nk, int nl, int nm,
    int A[ni][nk],
    int B[nk][nj],
    int C[nj][nm],
    int D[nm][nl])
{
  int i, j;

  for (i = 0; i < ni; i++)
    for (j = 0; j < nk; j++)
      A[i][j] = ((int) i*j) / ni;
  for (i = 0; i < nk; i++)
    for (j = 0; j < nj; j++)
      B[i][j] = ((int) i*(j+1)) / nj;
  for (i = 0; i < nj; i++)
    for (j = 0; j < nm; j++)
      C[i][j] = ((int) i*(j+3)) / nl;
  for (i = 0; i < nm; i++)
    for (j = 0; j < nl; j++)
      D[i][j] = ((int) i*(j+2)) / nk;
}




  static
void print_array(int ni, int nl,
    int G[ni][nl])
{
  int i, j;

  for (i = 0; i < ni; i++)
    for (j = 0; j < nl; j++) {
      printf ("%d ", G[i][j]);
      if ((i * ni + j) % 20 == 0) printf ("\n");
    }
  printf ("\n");
}




  static
void kernel_3mm(int ni, int nj, int nk, int nl, int nm,
    int E[ni][nj],
    int A[ni][nk],
    int B[nk][nj],
    int F[nj][nl],
    int C[nj][nm],
    int D[nm][nl],
    int G[ni][nl])
{
  int i, j, k;

#pragma scop

  for (i = 0; i < ni; i++)
    for (j = 0; j < nj; j++)
    {
      E[i][j] = 0;
      for (k = 0; k < nk; ++k)
        E[i][j] += A[i][k] * B[k][j];
    }

  for (i = 0; i < nj; i++)
    for (j = 0; j < nl; j++)
    {
      F[i][j] = 0;
      for (k = 0; k < nm; ++k)
        F[i][j] += C[i][k] * D[k][j];
    }

  for (i = 0; i < ni; i++)
    for (j = 0; j < nl; j++)
    {
      G[i][j] = 0;
      for (k = 0; k < nj; ++k)
        G[i][j] += E[i][k] * F[k][j];
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
  int nm = NM;


  int (E)[ni][nj];
  int (A)[ni][nk];
  int (B)[nk][nj];
  int (F)[nj][nl];
  int (C)[nj][nm];
  int (D)[nm][nl];
  int (G)[ni][nl];


  init_array (ni, nj, nk, nl, nm,
      A,
      B,
      C,
      D);




  kernel_3mm (ni, nj, nk, nl, nm,
      E,
      A,
      B,
      F,
      C,
      D,
      G);





  if (dump_code == 1) print_array(ni, nl, G);

  return 0;
}
