/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_rjtipF_mex.c
 *
 * Code generation for function '_coder_rjtipF_mex'
 *
 */

/* Include files */
#include "rjtipF.h"
#include "_coder_rjtipF_mex.h"
#include "rjtipF_terminate.h"
#include "_coder_rjtipF_api.h"
#include "rjtipF_initialize.h"
#include "rjtipF_data.h"

/* Function Declarations */
static void rjtipF_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
  const mxArray *prhs[3]);

/* Function Definitions */
static void rjtipF_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
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
                        "rjtipF");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 6,
                        "rjtipF");
  }

  /* Call the function. */
  rjtipF_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(rjtipF_atexit);

  /* Module initialization. */
  rjtipF_initialize();

  /* Dispatch the entry-point. */
  rjtipF_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  rjtipF_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_rjtipF_mex.c) */
