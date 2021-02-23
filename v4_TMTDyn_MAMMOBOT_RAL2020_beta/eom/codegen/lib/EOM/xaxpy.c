/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xaxpy.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 14-Oct-2020 22:53:18
 */

/* Include Files */
#include "EOM.h"
#include "EOM_input.h"
#include "xaxpy.h"

/* Function Definitions */

/*
 * Arguments    : int n
 *                double a
 *                const double x[1024]
 *                int ix0
 *                double y[32]
 *                int iy0
 * Return Type  : void
 */
void b_xaxpy(int n, double a, const double x[1024], int ix0, double y[32], int
             iy0)
{
  int ix;
  int iy;
  int i6;
  int k;
  if ((n < 1) || (a == 0.0)) {
  } else {
    ix = ix0 - 1;
    iy = iy0 - 1;
    i6 = n - 1;
    for (k = 0; k <= i6; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

/*
 * Arguments    : int n
 *                double a
 *                const double x[32]
 *                int ix0
 *                double y[1024]
 *                int iy0
 * Return Type  : void
 */
void c_xaxpy(int n, double a, const double x[32], int ix0, double y[1024], int
             iy0)
{
  int ix;
  int iy;
  int i7;
  int k;
  if ((n < 1) || (a == 0.0)) {
  } else {
    ix = ix0 - 1;
    iy = iy0 - 1;
    i7 = n - 1;
    for (k = 0; k <= i7; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

/*
 * Arguments    : int n
 *                double a
 *                int ix0
 *                double y[1024]
 *                int iy0
 * Return Type  : void
 */
void xaxpy(int n, double a, int ix0, double y[1024], int iy0)
{
  int ix;
  int iy;
  int i5;
  int k;
  if ((n < 1) || (a == 0.0)) {
  } else {
    ix = ix0 - 1;
    iy = iy0 - 1;
    i5 = n - 1;
    for (k = 0; k <= i5; k++) {
      y[iy] += a * y[ix];
      ix++;
      iy++;
    }
  }
}

/*
 * File trailer for xaxpy.c
 *
 * [EOF]
 */
