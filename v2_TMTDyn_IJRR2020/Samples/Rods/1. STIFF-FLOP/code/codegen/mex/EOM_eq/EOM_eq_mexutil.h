/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EOM_eq_mexutil.h
 *
 * Code generation for function 'EOM_eq_mexutil'
 *
 */

#ifndef EOM_EQ_MEXUTIL_H
#define EOM_EQ_MEXUTIL_H

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
extern void MEXGlobalSyncInFunction(const emlrtStack *sp);
extern void MEXGlobalSyncOutFunction(boolean_T skipDirtyCheck);
extern void emlrt_synchGlobalsFromML(const emlrtStack *sp);
extern void emlrt_synchGlobalsToML(const emlrtStack *sp);

#endif

/* End of code generation (EOM_eq_mexutil.h) */
