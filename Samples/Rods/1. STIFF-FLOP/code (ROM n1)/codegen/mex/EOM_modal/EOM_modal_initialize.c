/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EOM_modal_initialize.c
 *
 * Code generation for function 'EOM_modal_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "EOM_modal.h"
#include "EOM_modal_initialize.h"
#include "_coder_EOM_modal_mex.h"
#include "EOM_modal_data.h"

/* Function Definitions */
void EOM_modal_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (EOM_modal_initialize.c) */
