/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xrot.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 08-May-2021 03:55:48
 */

#ifndef XROT_H
#define XROT_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>
#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  void b_xrot(double x[54], int ix0, int iy0, double c, double s);
  void c_xrot(double x[324], int ix0, int iy0, double c, double s);
  void xrot(double x[9], int ix0, int iy0, double c, double s);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for xrot.h
 *
 * [EOF]
 */
