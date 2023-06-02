/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: svd.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 08-May-2021 01:57:20
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
  void b_svd(const double A[289], double U[289], double s[17], double V[289]);
  void svd(const double A[34], double U[34], double s[2], double V[4]);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for svd.h
 *
 * [EOF]
 */
