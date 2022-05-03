/**
 * lu.c: This file is part of the PolyBench/C 3.2 test suite.
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

  static
void init_array (int n,
    int A[n][n])
{
  int i, j;

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      A[i][j] = ((int) (i+1)*(j+1)) / n;
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
void kernel_lu(int n,
    int A[n][n])
{
  int i, j, k;

#pragma scop
  for (k = 0; k < n; k++)
  {
    for (j = k + 1; j < n; j++)
      A[k][j] = A[k][j] / A[k][k];
    for(i = k + 1; i < n; i++)
      for (j = k + 1; j < n; j++)
        A[i][j] = A[i][j] - A[i][k] * A[k][j];
  }
#pragma endscop

}


int main(int argc, char** argv)
{

  int n = N;


  int A[n][n];



  init_array (n, A);




  kernel_lu (n, A);





  print_array(n, A);

  return 0;
}
