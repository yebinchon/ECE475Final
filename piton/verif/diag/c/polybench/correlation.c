/**
 * correlation.c: This file is part of the PolyBench/C 3.2 test suite.
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
#define M 40

  static
void init_array (int m,
    int n,
    int *float_n,
    int data[m][n])
{
  int i, j;

  *float_n = 1;

  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
      data[i][j] = ((int) i*j) / 1000;
}




  static
void print_array(int m,
    int symmat[m][m])

{
  int i, j;

  for (i = 0; i < m; i++)
    for (j = 0; j < m; j++) {
      printf("%d ", symmat[i][j]);
      if ((i * m + j) % 20 == 0) printf("\n");
    }
  printf("\n");
}




  static
void kernel_correlation(int m, int n,
    int float_n,
    int data[m][n],
    int symmat[m][m],
    int mean[m],
    int stddev[m])
{
  int i, j, j1, j2;

  double eps = 0.1f;



#pragma scop

  for (j = 0; j < m; j++)
  {
    mean[j] = 0.0;
    for (i = 0; i < n; i++)
      mean[j] += data[i][j];
    mean[j] /= float_n;
  }


  for (j = 0; j < m; j++)
  {
    stddev[j] = 0.0;
    for (i = 0; i < n; i++)
      stddev[j] += (data[i][j] - mean[j]) * (data[i][j] - mean[j]);
    stddev[j] /= float_n;
    stddev[j] = sqrt(stddev[j]);



    stddev[j] = stddev[j] <= eps ? 1.0 : stddev[j];
  }


  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
    {
      data[i][j] -= mean[j];
      data[i][j] /= sqrt(float_n) * stddev[j];
    }


  for (j1 = 0; j1 < m-1; j1++)
  {
    symmat[j1][j1] = 1.0;
    for (j2 = j1+1; j2 < m; j2++)
    {
      symmat[j1][j2] = 0.0;
      for (i = 0; i < n; i++)
        symmat[j1][j2] += (data[i][j1] * data[i][j2]);
      symmat[j2][j1] = symmat[j1][j2];
    }
  }
  symmat[m-1][m-1] = 1.0;
#pragma endscop

}


int main(int argc, char** argv)
{

  int n = N;
  int m = M;

  int float_n;
  int data[m][n];
  int symmat[m][m];
  int mean[m];
  int stddev[m];


  init_array (m, n, &float_n, data);




  kernel_correlation (m, n, float_n,
      data,
      symmat,
      mean,
      stddev);





  print_array(m, symmat);

  return 0;
}

