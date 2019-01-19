/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EOM_modal.h
 *
 * Code generation for function 'EOM_modal'
 *
 */

#ifndef EOM_MODAL_H
#define EOM_MODAL_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "EOM_modal_types.h"

/* Function Declarations */
extern void EOM_modal(const emlrtStack *sp, const real_T z[6], struct0_T *par,
                      real_T TMT[36], real_T TKT[36], real_T TVT[36]);

#endif

/* End of code generation (EOM_modal.h) */
