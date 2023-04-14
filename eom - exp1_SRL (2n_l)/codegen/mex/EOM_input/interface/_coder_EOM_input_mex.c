/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_EOM_input_mex.c
 *
 * Code generation for function '_coder_EOM_input_mex'
 *
 */

/* Include files */
#include "_coder_EOM_input_mex.h"
#include "EOM_input_data.h"
#include "EOM_input_initialize.h"
#include "EOM_input_terminate.h"
#include "_coder_EOM_input_api.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void EOM_input_mexFunction(int32_T nlhs, mxArray *plhs[4], int32_T nrhs)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *outputs[4];
  int32_T b_nlhs;
  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 0, 4, 9,
                        "EOM_input");
  }

  if (nlhs > 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 9,
                        "EOM_input");
  }

  /* Call the function. */
  EOM_input_api(nlhs, outputs);

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
  (void)prhs;
  mexAtExit(&EOM_input_atexit);

  /* Module initialization. */
  EOM_input_initialize();

  /* Dispatch the entry-point. */
  EOM_input_mexFunction(nlhs, plhs, nrhs);

  /* Module termination. */
  EOM_input_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_EOM_input_mex.c) */
