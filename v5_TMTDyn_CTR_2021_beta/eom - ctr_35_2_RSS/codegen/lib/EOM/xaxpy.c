/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xaxpy.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 10-Mar-2021 22:46:32
 */

/* Include Files */
#include "xaxpy.h"

/* Function Definitions */
/*
 * Arguments    : int n
 *                double a
 *                const double x[576]
 *                int ix0
 *                double y[24]
 *                int iy0
 * Return Type  : void
 */
void b_xaxpy(int n, double a, const double x[576], int ix0, double y[24], int
             iy0)
{
  int i;
  int ix;
  int iy;
  int k;
  if ((n >= 1) && (a != 0.0)) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    i = n - 1;
    for (k = 0; k <= i; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

/*
 * Arguments    : int n
 *                double a
 *                const double x[24]
 *                int ix0
 *                double y[576]
 *                int iy0
 * Return Type  : void
 */
void c_xaxpy(int n, double a, const double x[24], int ix0, double y[576], int
             iy0)
{
  int i;
  int ix;
  int iy;
  int k;
  if ((n >= 1) && (a != 0.0)) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    i = n - 1;
    for (k = 0; k <= i; k++) {
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
 *                double y[576]
 *                int iy0
 * Return Type  : void
 */
void xaxpy(int n, double a, int ix0, double y[576], int iy0)
{
  int i;
  int ix;
  int iy;
  int k;
  if ((n >= 1) && (a != 0.0)) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    i = n - 1;
    for (k = 0; k <= i; k++) {
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
