/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EOM_mexutil.h
 *
 * Code generation for function 'EOM_mexutil'
 *
 */

#ifndef EOM_MEXUTIL_H
#define EOM_MEXUTIL_H

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
extern void MEXGlobalSyncInFunction(const emlrtStack *sp);
extern void MEXGlobalSyncOutFunction(boolean_T skipDirtyCheck);
extern real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
extern void emlrt_checkEscapedGlobals(void);
extern real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *c_t_report,
  const char_T *identifier);
extern const mxArray *emlrt_marshallOut(const real_T u);
extern void emlrt_synchGlobalsFromML(const emlrtStack *sp);
extern void emlrt_synchGlobalsToML(const emlrtStack *sp);

#endif

/* End of code generation (EOM_mexutil.h) */
