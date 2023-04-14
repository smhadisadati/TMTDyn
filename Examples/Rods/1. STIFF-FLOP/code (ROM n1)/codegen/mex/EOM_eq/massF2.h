/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * massF2.h
 *
 * Code generation for function 'massF2'
 *
 */

#ifndef MASSF2_H
#define MASSF2_H

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
extern void massF2(const emlrtStack *sp, const real_T in1[34], const real_T in2
                   [12], real_T out1[36], real_T out2[36], real_T out3[36],
                   real_T out4[6]);

#endif

/* End of code generation (massF2.h) */
