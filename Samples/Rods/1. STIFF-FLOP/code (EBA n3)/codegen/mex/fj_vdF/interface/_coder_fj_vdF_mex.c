/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_fj_vdF_mex.c
 *
 * Code generation for function '_coder_fj_vdF_mex'
 *
 */

/* Include files */
#include "fj_vdF.h"
#include "_coder_fj_vdF_mex.h"
#include "fj_vdF_terminate.h"
#include "_coder_fj_vdF_api.h"
#include "fj_vdF_initialize.h"
#include "fj_vdF_data.h"

/* Function Declarations */
static void fj_vdF_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
  const mxArray *prhs[3]);

/* Function Definitions */
static void fj_vdF_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
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
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4, 6,
                        "fj_vdF");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 6,
                        "fj_vdF");
  }

  /* Call the function. */
  fj_vdF_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(fj_vdF_atexit);

  /* Module initialization. */
  fj_vdF_initialize();

  /* Dispatch the entry-point. */
  fj_vdF_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  fj_vdF_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_fj_vdF_mex.c) */
