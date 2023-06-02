/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xaxpy.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 08-May-2021 03:55:48
 */

#ifndef XAXPY_H
#define XAXPY_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>
#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  void b_xaxpy(int n, double a, const double x[54], int ix0, double y[18], int
               iy0);
  void c_xaxpy(int n, double a, const double x[18], int ix0, double y[54], int
               iy0);
  void d_xaxpy(int n, double a, int ix0, double y[9], int iy0);
  void e_xaxpy(int n, double a, int ix0, double y[324], int iy0);
  void f_xaxpy(int n, double a, const double x[324], int ix0, double y[18], int
               iy0);
  void g_xaxpy(int n, double a, const double x[18], int ix0, double y[324], int
               iy0);
  void xaxpy(int n, double a, int ix0, double y[54], int iy0);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for xaxpy.h
 *
 * [EOF]
 */
