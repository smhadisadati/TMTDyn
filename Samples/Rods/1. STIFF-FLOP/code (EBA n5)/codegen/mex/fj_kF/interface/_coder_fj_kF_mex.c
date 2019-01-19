/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_fj_kF_mex.c
 *
 * Code generation for function '_coder_fj_kF_mex'
 *
 */

/* Include files */
#include "fj_kF.h"
#include "_coder_fj_kF_mex.h"
#include "fj_kF_terminate.h"
#include "_coder_fj_kF_api.h"
#include "fj_kF_initialize.h"
#include "fj_kF_data.h"

/* Function Declarations */
static void fj_kF_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
  const mxArray *prhs[3]);

/* Function Definitions */
static void fj_kF_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
  const mxArray *prhs[3])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4, 5,
                        "fj_kF");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 5,
                        "fj_kF");
  }

  /* Call the function. */
  fj_kF_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(fj_kF_atexit);

  /* Module initialization. */
  fj_kF_initialize();

  /* Dispatch the entry-point. */
  fj_kF_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  fj_kF_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_fj_kF_mex.c) */
