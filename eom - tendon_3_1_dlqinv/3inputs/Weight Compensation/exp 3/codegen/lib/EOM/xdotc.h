/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xdotc.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 08-May-2021 04:24:39
 */

#ifndef XDOTC_H
#define XDOTC_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>
#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  double b_xdotc(int n, const double x[9], int ix0, const double y[9], int iy0);
  double c_xdotc(int n, const double x[324], int ix0, const double y[324], int
                 iy0);
  double xdotc(int n, const double x[54], int ix0, const double y[54], int iy0);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for xdotc.h
 *
 * [EOF]
 */
