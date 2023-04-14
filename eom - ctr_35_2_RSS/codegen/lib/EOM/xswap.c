/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xswap.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 10-Mar-2021 22:46:32
 */

/* Include Files */
#include "xswap.h"

/* Function Definitions */
/*
 * Arguments    : double x[576]
 *                int ix0
 *                int iy0
 * Return Type  : void
 */
void xswap(double x[576], int ix0, int iy0)
{
  double temp;
  int ix;
  int iy;
  int k;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (k = 0; k < 24; k++) {
    temp = x[ix];
    x[ix] = x[iy];
    x[iy] = temp;
    ix++;
    iy++;
  }
}

/*
 * File trailer for xswap.c
 *
 * [EOF]
 */
