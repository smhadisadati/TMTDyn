/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xaxpy.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 10-Mar-2021 22:46:32
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
  void b_xaxpy(int n, double a, const double x[576], int ix0, double y[24], int
               iy0);
  void c_xaxpy(int n, double a, const double x[24], int ix0, double y[576], int
               iy0);
  void xaxpy(int n, double a, int ix0, double y[576], int iy0);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for xaxpy.h
 *
 * [EOF]
 */
