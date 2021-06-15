/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_EOM_modal_mex.c
 *
 * Code generation for function '_coder_EOM_modal_mex'
 *
 */

/* Include files */
#include "EOM_modal.h"
#include "_coder_EOM_modal_mex.h"
#include "EOM_modal_terminate.h"
#include "_coder_EOM_modal_api.h"
#include "EOM_modal_initialize.h"
#include "EOM_modal_data.h"

/* Function Declarations */
static void EOM_modal_mexFunction(EOM_modalStackData *SD, int32_T nlhs, mxArray *
  plhs[3], int32_T nrhs, const mxArray *prhs[2]);

/* Function Definitions */
static void EOM_modal_mexFunction(EOM_modalStackData *SD, int32_T nlhs, mxArray *
  plhs[3], int32_T nrhs, const mxArray *prhs[2])
{
  const mxArray *outputs[3];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4, 9,
                        "EOM_modal");
  }

  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 9,
                        "EOM_modal");
  }

  /* Call the function. */
  EOM_modal_api(SD, prhs, nlhs, outputs);

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
  EOM_modalStackData *EOM_modalStackDataGlobal = NULL;
  EOM_modalStackDataGlobal = (EOM_modalStackData *)emlrtMxCalloc(1, 1U * sizeof
    (EOM_modalStackData));
  mexAtExit(EOM_modal_atexit);

  /* Module initialization. */
  EOM_modal_initialize();

  /* Dispatch the entry-point. */
  EOM_modal_mexFunction(EOM_modalStackDataGlobal, nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  EOM_modal_terminate();
  emlrtMxFree(EOM_modalStackDataGlobal);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_EOM_modal_mex.c) */
