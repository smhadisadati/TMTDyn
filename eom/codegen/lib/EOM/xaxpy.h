/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xaxpy.h
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 14-Oct-2020 22:53:18
 */

#ifndef XAXPY_H
#define XAXPY_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "EOM_types.h"

/* Function Declarations */
extern void b_xaxpy(int n, double a, const double x[1024], int ix0, double y[32],
                    int iy0);
extern void c_xaxpy(int n, double a, const double x[32], int ix0, double y[1024],
                    int iy0);
extern void xaxpy(int n, double a, int ix0, double y[1024], int iy0);

#endif

/*
 * File trailer for xaxpy.h
 *
 * [EOF]
 */
