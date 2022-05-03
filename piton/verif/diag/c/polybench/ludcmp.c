/**
 * ludcmp.c: This file is part of the PolyBench/C 3.2 test suite.
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

  static
void init_array (int n,
    int A[n+1][n+1],
    int b[n+1],
    int x[n+1],
    int y[n+1])
{
  int i, j;

  for (i = 0; i <= n; i++)
  {
    x[i] = i + 1;
    y[i] = (i+1)/n/2.0 + 1;
    b[i] = (i+1)/n/2.0 + 42;
    for (j = 0; j <= n; j++) {
      A[i][j] = ((int) (i+1)*(j+1)) / n;
    }
  }
}




  static
void print_array(int n,
    int x[n+1])

{
  int i;

  for (i = 0; i <= n; i++) {
    printf("%d ", x[i]);
    if (i % 20 == 0) printf("\n");
  }
}




  static
void kernel_ludcmp(int n,
    int A[n+1][n+1],
    int b[n+1],
    int x[n+1],
    int y[n+1])
{
  int i, j, k;

  int w;

#pragma scop
  b[0] = 1.0;
  for (i = 0; i < n; i++)
  {
    for (j = i+1; j <= n; j++)
    {
      w = A[j][i];
      for (k = 0; k < i; k++)
        w = w- A[j][k] * A[k][i];
      A[j][i] = w / A[i][i];
    }
    for (j = i+1; j <= n; j++)
    {
      w = A[i+1][j];
      for (k = 0; k <= i; k++)
        w = w - A[i+1][k] * A[k][j];
      A[i+1][j] = w;
    }
  }
  y[0] = b[0];
  for (i = 1; i <= n; i++)
  {
    w = b[i];
    for (j = 0; j < i; j++)
      w = w - A[i][j] * y[j];
    y[i] = w;
  }
  x[n] = y[n] / A[n][n];
  for (i = 0; i <= n - 1; i++)
  {
    w = y[n - 1 - (i)];
    for (j = n - i; j <= n; j++)
      w = w - A[n - 1 - i][j] * x[j];
    x[n - 1 - i] = w / A[n - 1 - (i)][n - 1-(i)];
  }
#pragma endscop

}


int main(int argc, char** argv)
{

  int n = N;


  int A[n+1][n+1];
  int b[n+1];
  int x[n+1];
  int y[n+1];



  init_array (n,
      A,
      b,
      x,
      y);




  kernel_ludcmp (n,
      A,
      b,
      x,
      y);





  print_array(n, x);

  return 0;
}
