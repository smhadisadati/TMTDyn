/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_sprdmpF99_mex.c
 *
 * Code generation for function '_coder_sprdmpF99_mex'
 *
 */

/* Include files */
#include "sprdmpF99.h"
#include "_coder_sprdmpF99_mex.h"
#include "sprdmpF99_terminate.h"
#include "_coder_sprdmpF99_api.h"
#include "sprdmpF99_initialize.h"
#include "sprdmpF99_data.h"

/* Function Declarations */
static void sprdmpF99_mexFunction(int32_T nlhs, mxArray *plhs[8], int32_T nrhs,
  const mxArray *prhs[3]);

/* Function Definitions */
static void sprdmpF99_mexFunction(int32_T nlhs, mxArray *plhs[8], int32_T nrhs,
  const mxArray *prhs[3])
{
  const mxArray *outputs[8];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4, 9,
                        "sprdmpF99");
  }

  if (nlhs > 8) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 9,
                        "sprdmpF99");
  }

  /* Call the function. */
  sprdmpF99_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(sprdmpF99_atexit);

  /* Module initialization. */
  sprdmpF99_initialize();

  /* Dispatch the entry-point. */
  sprdmpF99_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  sprdmpF99_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_sprdmpF99_mex.c) */
