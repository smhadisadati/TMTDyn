/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xaxpy.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 30-Apr-2021 21:54:05
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
  void b_xaxpy(int n, double a, const double x[289], int ix0, double y[17], int
               iy0);
  void c_xaxpy(int n, double a, const double x[17], int ix0, double y[289], int
               iy0);
  void xaxpy(int n, double a, int ix0, double y[289], int iy0);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for xaxpy.h
 *
 * [EOF]
 */
