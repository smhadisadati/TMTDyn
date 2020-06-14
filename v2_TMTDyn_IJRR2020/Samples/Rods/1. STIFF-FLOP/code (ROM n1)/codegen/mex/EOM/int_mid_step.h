/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * int_mid_step.h
 *
 * Code generation for function 'int_mid_step'
 *
 */

#ifndef INT_MID_STEP_H
#define INT_MID_STEP_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "EOM_types.h"

/* Function Declarations */
extern void int_mid_step(const emlrtStack *sp, real_T t, const real_T z[12],
  struct0_T *b_par);

#endif

/* End of code generation (int_mid_step.h) */
