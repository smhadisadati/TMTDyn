/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * massF7.h
 *
 * Code generation for function 'massF7'
 *
 */

#ifndef MASSF7_H
#define MASSF7_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "massF7_types.h"

/* Function Declarations */
extern void massF7(const emlrtStack *sp, const real_T in1[6], const real_T in2
                   [224], real_T s, real_T out1[36], real_T out2[636], real_T
                   out3[636], real_T out4[6]);

#endif

/* End of code generation (massF7.h) */
