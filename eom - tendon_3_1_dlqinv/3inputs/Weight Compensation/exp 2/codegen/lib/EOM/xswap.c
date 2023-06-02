/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xswap.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 08-May-2021 03:55:48
 */

/* Include Files */
#include "xswap.h"

/* Function Definitions */
/*
 * Arguments    : double x[54]
 *                int ix0
 *                int iy0
 * Return Type  : void
 */
void b_xswap(double x[54], int ix0, int iy0)
{
  double temp;
  int ix;
  int iy;
  int k;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (k = 0; k < 18; k++) {
    temp = x[ix];
    x[ix] = x[iy];
    x[iy] = temp;
    ix++;
    iy++;
  }
}

/*
 * Arguments    : double x[324]
 *                int ix0
 *                int iy0
 * Return Type  : void
 */
void c_xswap(double x[324], int ix0, int iy0)
{
  double temp;
  int ix;
  int iy;
  int k;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (k = 0; k < 18; k++) {
    temp = x[ix];
    x[ix] = x[iy];
    x[iy] = temp;
    ix++;
    iy++;
  }
}

/*
 * Arguments    : double x[9]
 *                int ix0
 *                int iy0
 * Return Type  : void
 */
void xswap(double x[9], int ix0, int iy0)
{
  double temp;
  temp = x[ix0 - 1];
  x[ix0 - 1] = x[iy0 - 1];
  x[iy0 - 1] = temp;
  temp = x[ix0];
  x[ix0] = x[iy0];
  x[iy0] = temp;
  temp = x[ix0 + 1];
  x[ix0 + 1] = x[iy0 + 1];
  x[iy0 + 1] = temp;
}

/*
 * File trailer for xswap.c
 *
 * [EOF]
 */
