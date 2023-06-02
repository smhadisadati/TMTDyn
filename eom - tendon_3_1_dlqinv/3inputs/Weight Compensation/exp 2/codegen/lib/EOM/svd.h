/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: svd.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 08-May-2021 03:55:48
 */

#ifndef SVD_H
#define SVD_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>
#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  void b_svd(const double A[324], double U[324], double s[18], double V[324]);
  void svd(const double A[54], double U[54], double s[3], double V[9]);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for svd.h
 *
 * [EOF]
 */
