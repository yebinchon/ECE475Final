/**
 * doitgen.c: This file is part of the PolyBench/C 3.2 test suite.
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
#define NR 1024
#define NQ 1024
#define NP 1024

  static
void init_array(int nr, int nq, int np,
    int A[nr][nq][np],
    int C4[np][np])
{
  int i, j, k;

  for (i = 0; i < nr; i++)
    for (j = 0; j < nq; j++)
      for (k = 0; k < np; k++)
        A[i][j][k] = ((int) i*j + k) / np;
  for (i = 0; i < np; i++)
    for (j = 0; j < np; j++)
      C4[i][j] = ((int) i*j) / np;
}




  static
void print_array(int nr, int nq, int np,
    int A[nr][nq][np])
{
  int i, j, k;

  for (i = 0; i < nr; i++)
    for (j = 0; j < nq; j++)
      for (k = 0; k < np; k++) {
        printf ("%0.2lf ", A[i][j][k]);
        if (i % 20 == 0) printf ("\n");
      }
  printf ("\n");
}




  static
void kernel_doitgen(int nr, int nq, int np,
    int A[nr][nq][np],
    int C4[np][np],
    int sum[nr][nq][np])
{
  int r, q, p, s;

#pragma scop
  for (r = 0; r < nr; r++)
    for (q = 0; q < nq; q++) {
      for (p = 0; p < np; p++) {
        sum[r][q][p] = 0;
        for (s = 0; s < np; s++)
          sum[r][q][p] = sum[r][q][p] + A[r][q][s] * C4[s][p];
      }
      for (p = 0; p < np; p++)
        A[r][q][p] = sum[r][q][p];
    }
#pragma endscop

}


int main(int argc, char** argv)
{

  int dump_code = DUMP_CODE;
  int nr = NR;
  int nq = NQ;
  int np = NP;

  int (A)[nr][nq][np];
  int (sum)[nr][nq][np];
  int (C4)[np][np];


  init_array (nr, nq, np,
      A,
      C4);




  kernel_doitgen (nr, nq, np,
      A,
      C4,
      sum);





  if (dump_code == 1) print_array(nr, nq, np, A);

  return 0;
}
