/**
 * seidel-2d.c: This file is part of the PolyBench/C 3.2 test suite.
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


#define N 400
#define T 5

  static
void init_array (int n,
    int A[n][n])
{
  int i, j;

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      A[i][j] = ((int) i*(j+2) + 2) / n;
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
void kernel_seidel_2d(int tsteps,
    int n,
    int A[n][n])
{
  int t, i, j;

#pragma scop
  for (t = 0; t <= tsteps - 1; t++)
    for (i = 1; i<= n - 2; i++)
      for (j = 1; j <= n - 2; j++)
        A[i][j] = (A[i-1][j-1] + A[i-1][j] + A[i-1][j+1]
            + A[i][j-1] + A[i][j] + A[i][j+1]
            + A[i+1][j-1] + A[i+1][j] + A[i+1][j+1])/9.0;
#pragma endscop

}


int main(int argc, char** argv)
{
  int n = N;
  int tsteps = T;

  int A[n][n];



  init_array (n, A);




  kernel_seidel_2d (tsteps, n, A);





  print_array(n, A);

  return 0;
}
