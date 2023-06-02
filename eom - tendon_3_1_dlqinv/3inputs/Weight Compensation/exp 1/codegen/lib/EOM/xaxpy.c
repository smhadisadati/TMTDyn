/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xaxpy.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 08-May-2021 03:51:05
 */

/* Include Files */
#include "xaxpy.h"

/* Function Definitions */
/*
 * Arguments    : int n
 *                double a
 *                const double x[54]
 *                int ix0
 *                double y[18]
 *                int iy0
 * Return Type  : void
 */
void b_xaxpy(int n, double a, const double x[54], int ix0, double y[18], int iy0)
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
 *                const double x[18]
 *                int ix0
 *                double y[54]
 *                int iy0
 * Return Type  : void
 */
void c_xaxpy(int n, double a, const double x[18], int ix0, double y[54], int iy0)
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
 *                double y[9]
 *                int iy0
 * Return Type  : void
 */
void d_xaxpy(int n, double a, int ix0, double y[9], int iy0)
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
 * Arguments    : int n
 *                double a
 *                int ix0
 *                double y[324]
 *                int iy0
 * Return Type  : void
 */
void e_xaxpy(int n, double a, int ix0, double y[324], int iy0)
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
 * Arguments    : int n
 *                double a
 *                const double x[324]
 *                int ix0
 *                double y[18]
 *                int iy0
 * Return Type  : void
 */
void f_xaxpy(int n, double a, const double x[324], int ix0, double y[18], int
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
 *                const double x[18]
 *                int ix0
 *                double y[324]
 *                int iy0
 * Return Type  : void
 */
void g_xaxpy(int n, double a, const double x[18], int ix0, double y[324], int
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
 *                double y[54]
 *                int iy0
 * Return Type  : void
 */
void xaxpy(int n, double a, int ix0, double y[54], int iy0)
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
