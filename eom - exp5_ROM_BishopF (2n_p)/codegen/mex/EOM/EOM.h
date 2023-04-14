/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EOM.h
 *
 * Code generation for function 'EOM'
 *
 */

#pragma once

/* Include files */
#include "EOM_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void EOM(const emlrtStack *sp, real_T t, const real_T z[18], const struct0_T
         *par_mex, real_T dz[18], real_T *flag);

/* End of code generation (EOM.h) */
