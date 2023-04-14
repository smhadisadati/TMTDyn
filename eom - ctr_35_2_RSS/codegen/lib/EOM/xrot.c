/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xrot.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 10-Mar-2021 22:46:32
 */

/* Include Files */
#include "xrot.h"

/* Function Definitions */
/*
 * Arguments    : double x[576]
 *                int ix0
 *                int iy0
 *                double c
 *                double s
 * Return Type  : void
 */
void xrot(double x[576], int ix0, int iy0, double c, double s)
{
  double temp;
  int ix;
  int iy;
  int k;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (k = 0; k < 24; k++) {
    temp = c * x[ix] + s * x[iy];
    x[iy] = c * x[iy] - s * x[ix];
    x[ix] = temp;
    iy++;
    ix++;
  }
}

/*
 * File trailer for xrot.c
 *
 * [EOF]
 */
