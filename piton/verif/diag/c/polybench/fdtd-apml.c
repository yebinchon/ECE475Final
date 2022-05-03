/**
 * fdtd-apml.c: This file is part of the PolyBench 3.0 test suite.
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

#define CZ 8
#define CYM 8
#define CXM 8


/* Array initialization. */
static
void init_array (int cz,
		 int cxm,
		 int cym,
		 int *mui,
		 int *ch,
		 int Ax[cz+1][cym+1],
		 int Ry[cz+1][cym+1],
		 int Ex[cz+1][cym+1][cxm+1],
		 int Ey[cz+1][cym+1][cxm+1],
		 int Hz[cz+1][cym+1][cxm+1],
		 int czm[cz+1],
		 int czp[cz+1],
		 int cxmh[cxm+1],
		 int cxph[cxm+1],
		 int cymh[cym+1],
		 int cyph[cym+1])
{
  int i, j, k;
  *mui = 2341;
  *ch = 42;
  for (i = 0; i <= cz; i++)
    {
      czm[i] = ((int) i + 1) / cxm;
      czp[i] = ((int) i + 2) / cxm;
    }
  for (i = 0; i <= cxm; i++)
    {
      cxmh[i] = ((int) i + 3) / cxm;
      cxph[i] = ((int) i + 4) / cxm;
    }
  for (i = 0; i <= cym; i++)
    {
      cymh[i] = ((int) i + 5) / cxm;
      cyph[i] = ((int) i + 6) / cxm;
    }

  for (i = 0; i <= cz; i++)
    for (j = 0; j <= cym; j++)
      {
	Ry[i][j] = ((int) i*(j+1) + 10) / cym;
	Ax[i][j] = ((int) i*(j+2) + 11) / cym;
	for (k = 0; k <= cxm; k++)
	  {
	    Ex[i][j][k] = ((int) i*(j+3) + k + 1) / cxm;
	    Ey[i][j][k] = ((int) i*(j+4) + k + 2) / cym;
	    Hz[i][j][k] = ((int) i*(j+5) + k + 3) / cz;
	  }
      }
}


/* DCE code. Must scan the entire live-out data.
   Can be used also to check the correctness of the output. */
static
void print_array(int cz,
		 int cxm,
		 int cym,
		 int Bza[cz+1][cym+1][cxm+1],
		 int Ex[cz+1][cym+1][cxm+1],
		 int Ey[cz+1][cym+1][cxm+1],
		 int Hz[cz+1][cym+1][cxm+1])
{
  int i, j, k;

  for (i = 0; i <= cz; i++)
    for (j = 0; j <= cym; j++)
      for (k = 0; k <= cxm; k++) {
	printf("%d ", Bza[i][j][k]);
	printf("%d ", Ex[i][j][k]);
	printf("%d ", Ey[i][j][k]);
	printf("%d ", Hz[i][j][k]);
	if ((i * cxm + j) % 20 == 0) printf("\n");
      }
  printf("\n");
}


/* Main computational kernel. The whole function will be timed,
   including the call and return. */
static
void kernel_fdtd_apml(int cz,
		      int cxm,
		      int cym,
		      int mui,
		      int ch,
		 int Ax[cz+1][cym+1],
		 int Ry[cz+1][cym+1],
     int clf[cym+1][cxm+1],
     int tmp[cym+1][cxm+1],
     int Bza[cz+1][cym+1][cxm+1],
		 int Ex[cz+1][cym+1][cxm+1],
		 int Ey[cz+1][cym+1][cxm+1],
		 int Hz[cz+1][cym+1][cxm+1],
		 int czm[cz+1],
		 int czp[cz+1],
		 int cxmh[cxm+1],
		 int cxph[cxm+1],
		 int cymh[cym+1],
		 int cyph[cym+1])
{
  int iz, iy, ix;

#pragma scop
  for (iz = 0; iz < cz; iz++)
    {
      for (iy = 0; iy < cym; iy++)
	{
	  for (ix = 0; ix < cxm; ix++)
	    {
	      clf[iz][iy] = Ex[iz][iy][ix] - Ex[iz][iy+1][ix] + Ey[iz][iy][ix+1] - Ey[iz][iy][ix];
	      tmp[iz][iy] = (cymh[iy] / cyph[iy]) * Bza[iz][iy][ix] - (ch / cyph[iy]) * clf[iz][iy];
	      Hz[iz][iy][ix] = (cxmh[ix] /cxph[ix]) * Hz[iz][iy][ix]
		+ (mui * czp[iz] / cxph[ix]) * tmp[iz][iy]
		- (mui * czm[iz] / cxph[ix]) * Bza[iz][iy][ix];
	      Bza[iz][iy][ix] = tmp[iz][iy];
	    }
	  clf[iz][iy] = Ex[iz][iy][cxm] - Ex[iz][iy+1][cxm] + Ry[iz][iy] - Ey[iz][iy][cxm];
	  tmp[iz][iy] = (cymh[iy] / cyph[iy]) * Bza[iz][iy][cxm] - (ch / cyph[iy]) * clf[iz][iy];
	  Hz[iz][iy][cxm]=(cxmh[cxm] / cxph[cxm]) * Hz[iz][iy][cxm]
	    + (mui * czp[iz] / cxph[cxm]) * tmp[iz][iy]
	    - (mui * czm[iz] / cxph[cxm]) * Bza[iz][iy][cxm];
	  Bza[iz][iy][cxm] = tmp[iz][iy];
	  for (ix = 0; ix < cxm; ix++)
	    {
	      clf[iz][iy] = Ex[iz][cym][ix] - Ax[iz][ix] + Ey[iz][cym][ix+1] - Ey[iz][cym][ix];
	      tmp[iz][iy] = (cymh[cym] / cyph[iy]) * Bza[iz][iy][ix] - (ch / cyph[iy]) * clf[iz][iy];
	      Hz[iz][cym][ix] = (cxmh[ix] / cxph[ix]) * Hz[iz][cym][ix]
		+ (mui * czp[iz] / cxph[ix]) * tmp[iz][iy]
		- (mui * czm[iz] / cxph[ix]) * Bza[iz][cym][ix];
	      Bza[iz][cym][ix] = tmp[iz][iy];
	    }
	  clf[iz][iy] = Ex[iz][cym][cxm] - Ax[iz][cxm] + Ry[iz][cym] - Ey[iz][cym][cxm];
	  tmp[iz][iy] = (cymh[cym] / cyph[cym]) * Bza[iz][cym][cxm] - (ch / cyph[cym]) * clf[iz][iy];
	  Hz[iz][cym][cxm] = (cxmh[cxm] / cxph[cxm]) * Hz[iz][cym][cxm]
	    + (mui * czp[iz] / cxph[cxm]) * tmp[iz][iy]
	    - (mui * czm[iz] / cxph[cxm]) * Bza[iz][cym][cxm];
	  Bza[iz][cym][cxm] = tmp[iz][iy];
	}
    }
#pragma endscop

}


int main(int argc, char** argv)
{
  /* Retrieve problem size. */
  int cz = CZ;
  int cym = CYM;
  int cxm = CXM;

  /* Variable declaration/allocation. */
  int mui;
  int ch;
  int Ax[cz+1][cym+1];
  int Ry[cz+1][cym+1];
  int clf[cym+1][cxm+1];
  int tmp[cym+1][cxm+1];
  int Bza[cz+1][cym+1][cxm+1];
  int Ex[cz+1][cym+1][cxm+1];
  int Ey[cz+1][cym+1][cxm+1];
  int Hz[cz+1][cym+1][cxm+1];
  int czm[cz+1];
  int czp[cz+1];
  int cxmh[cxm+1];
  int cxph[cxm+1];
  int cymh[cym+1];
  int cyph[cym+1];

  /* Initialize array(s). */
  init_array (cz, cxm, cym, &mui, &ch,
  	      Ax,
  	      Ry,
  	      Ex,
  	      Ey,
  	      Hz,
  	      czm,
  	      czp,
  	      cxmh,
  	      cxph,
  	      cymh,
  	      cyph);

  /* Run kernel. */
  kernel_fdtd_apml (cz, cxm, cym, mui, ch,
  		    Ax,
  		    Ry,
  		    clf,
  		    tmp,
  		    Bza,
  		    Ex,
  		    Ey,
  		    Hz,
  		    czm,
  		    czp,
  		    cxmh,
  		    cxph,
  		    cymh,
  		    cyph);

  /* Prevent dead-code elimination. All live-out data must be printed
     by the function call in argument. */
  print_array(cz,cxm, cym, Bza, Ex, Ey, Hz);


  return 0;
}

