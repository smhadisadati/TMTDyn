/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xdotc.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 14-Oct-2020 16:42:47
 */

/* Include Files */
#include "EOM.h"
#include "EOM_input.h"
#include "xdotc.h"

/* Function Definitions */

/*
 * Arguments    : int n
 *                const double x[1024]
 *                int ix0
 *                const double y[1024]
 *                int iy0
 * Return Type  : double
 */
double xdotc(int n, const double x[1024], int ix0, const double y[1024], int iy0)
{
  double d;
  int ix;
  int iy;
  int k;
  d = 0.0;
  if (n >= 1) {
    ix = ix0;
    iy = iy0;
    for (k = 0; k < n; k++) {
      d += x[ix - 1] * y[iy - 1];
      ix++;
      iy++;
    }
  }

  return d;
}

/*
 * File trailer for xdotc.c
 *
 * [EOF]
 */
