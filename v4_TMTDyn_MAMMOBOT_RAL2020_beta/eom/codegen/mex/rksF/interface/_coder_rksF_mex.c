/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_rksF_mex.c
 *
 * Code generation for function '_coder_rksF_mex'
 *
 */

/* Include files */
#include "rksF.h"
#include "_coder_rksF_mex.h"
#include "rksF_terminate.h"
#include "_coder_rksF_api.h"
#include "rksF_initialize.h"
#include "rksF_data.h"

/* Function Declarations */
static void rksF_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs, const
  mxArray *prhs[3]);

/* Function Definitions */
static void rksF_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs, const
  mxArray *prhs[3])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4, 4,
                        "rksF");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 4,
                        "rksF");
  }

  /* Call the function. */
  rksF_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(rksF_atexit);

  /* Module initialization. */
  rksF_initialize();

  /* Dispatch the entry-point. */
  rksF_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  rksF_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_rksF_mex.c) */
