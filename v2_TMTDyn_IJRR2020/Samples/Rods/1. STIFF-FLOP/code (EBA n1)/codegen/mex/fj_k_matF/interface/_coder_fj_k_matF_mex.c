/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_fj_k_matF_mex.c
 *
 * Code generation for function '_coder_fj_k_matF_mex'
 *
 */

/* Include files */
#include "fj_k_matF.h"
#include "_coder_fj_k_matF_mex.h"
#include "fj_k_matF_terminate.h"
#include "_coder_fj_k_matF_api.h"
#include "fj_k_matF_initialize.h"
#include "fj_k_matF_data.h"

/* Function Declarations */
static void fj_k_matF_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
  const mxArray *prhs[3]);

/* Function Definitions */
static void fj_k_matF_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
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
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4, 9,
                        "fj_k_matF");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 9,
                        "fj_k_matF");
  }

  /* Call the function. */
  fj_k_matF_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(fj_k_matF_atexit);

  /* Module initialization. */
  fj_k_matF_initialize();

  /* Dispatch the entry-point. */
  fj_k_matF_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  fj_k_matF_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_fj_k_matF_mex.c) */
