/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: pinv.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 08-May-2021 03:55:48
 */

#ifndef PINV_H
#define PINV_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>
#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  void b_pinv(const double A[324], double tol, double X[324]);
  void pinv(const double A[54], double X[54]);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for pinv.h
 *
 * [EOF]
 */
