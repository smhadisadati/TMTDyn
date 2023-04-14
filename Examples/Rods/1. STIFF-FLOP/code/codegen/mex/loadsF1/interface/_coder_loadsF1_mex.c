/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_loadsF1_mex.c
 *
 * Code generation for function '_coder_loadsF1_mex'
 *
 */

/* Include files */
#include "loadsF1.h"
#include "_coder_loadsF1_mex.h"
#include "loadsF1_terminate.h"
#include "_coder_loadsF1_api.h"
#include "loadsF1_initialize.h"
#include "loadsF1_data.h"

/* Function Declarations */
static void loadsF1_mexFunction(int32_T nlhs, mxArray *plhs[2], int32_T nrhs,
  const mxArray *prhs[3]);

/* Function Definitions */
static void loadsF1_mexFunction(int32_T nlhs, mxArray *plhs[2], int32_T nrhs,
  const mxArray *prhs[3])
{
  const mxArray *outputs[2];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4, 7,
                        "loadsF1");
  }

  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 7,
                        "loadsF1");
  }

  /* Call the function. */
  loadsF1_api(prhs, nlhs, outputs);

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
  mexAtExit(loadsF1_atexit);

  /* Module initialization. */
  loadsF1_initialize();

  /* Dispatch the entry-point. */
  loadsF1_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  loadsF1_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_loadsF1_mex.c) */
