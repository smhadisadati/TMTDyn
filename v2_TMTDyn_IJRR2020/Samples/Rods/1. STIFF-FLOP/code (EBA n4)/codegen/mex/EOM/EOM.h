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

#ifndef EOM_H
#define EOM_H

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
extern void EOM(const emlrtStack *sp, real_T t, const real_T z[48], struct0_T
                *b_par, real_T dz_data[], int32_T dz_size[1]);

#endif

/* End of code generation (EOM.h) */
