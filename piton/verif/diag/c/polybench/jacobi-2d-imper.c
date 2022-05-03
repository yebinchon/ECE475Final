/**
 * jacobi-2d-imper.c: This file is part of the PolyBench/C 3.2 test suite.
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

#define N 512
#define T 5

  static
void init_array (int n,
    int A[n][n],
    int B[n][n])
{
  int i, j;

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
    {
      A[i][j] = ((int) i*(j+2) + 2) / n;
      B[i][j] = ((int) i*(j+3) + 3) / n;
    }
}




  static
void print_array(int n,
    int A[n][n])

{
  int i, j;

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
      printf("%d ", A[i][j]);
      if ((i * n + j) % 20 == 0) printf("\n");
    }
  printf("\n");
}




  static
void kernel_jacobi_2d_imper(int tsteps,
    int n,
    int A[n][n],
    int B[n][n])
{
  int t, i, j;

#pragma scop
  for (t = 0; t < tsteps; t++)
  {
    for (i = 1; i < n - 1; i++)
      for (j = 1; j < n - 1; j++)
        B[i][j] = 0.2 * (A[i][j] + A[i][j-1] + A[i][1+j] + A[1+i][j] + A[i-1][j]);
    for (i = 1; i < n-1; i++)
      for (j = 1; j < n-1; j++)
        A[i][j] = B[i][j];
  }
#pragma endscop

}


int main(int argc, char** argv)
{

  int n = N;
  int tsteps = T;


  int A[n][n];
  int B[n][n];



  init_array (n, A, B);




  kernel_jacobi_2d_imper (tsteps, n, A, B);





  print_array(n, A);

  return 0;
}
