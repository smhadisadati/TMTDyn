/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * massF10.h
 *
 * Code generation for function 'massF10'
 *
 */

#ifndef MASSF10_H
#define MASSF10_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "EOM_eq_types.h"

/* Function Declarations */
extern void massF10(const emlrtStack *sp, const real_T in2[198], real_T out2[546],
                    real_T out3[546], real_T out4[6]);

#endif

/* End of code generation (massF10.h) */
