/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xdotc.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 08-May-2021 03:51:05
 */

/* Include Files */
#include "xdotc.h"

/* Function Definitions */
/*
 * Arguments    : int n
 *                const double x[9]
 *                int ix0
 *                const double y[9]
 *                int iy0
 * Return Type  : double
 */
double b_xdotc(int n, const double x[9], int ix0, const double y[9], int iy0)
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
 * Arguments    : int n
 *                const double x[324]
 *                int ix0
 *                const double y[324]
 *                int iy0
 * Return Type  : double
 */
double c_xdotc(int n, const double x[324], int ix0, const double y[324], int iy0)
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
 * Arguments    : int n
 *                const double x[54]
 *                int ix0
 *                const double y[54]
 *                int iy0
 * Return Type  : double
 */
double xdotc(int n, const double x[54], int ix0, const double y[54], int iy0)
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
