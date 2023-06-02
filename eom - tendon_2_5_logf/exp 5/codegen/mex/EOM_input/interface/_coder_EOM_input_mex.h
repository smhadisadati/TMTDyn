/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_EOM_input_mex.h
 *
 * Code generation for function '_coder_EOM_input_mex'
 *
 */

#pragma once

/* Include files */
#include "EOM_input_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void EOM_input_mexFunction(EOM_inputStackData *SD, int32_T nlhs, mxArray *plhs[4],
  int32_T nrhs);
MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
  const mxArray *prhs[]);
emlrtCTX mexFunctionCreateRootTLS(void);

/* End of code generation (_coder_EOM_input_mex.h) */
