/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fj_vd_matF_initialize.c
 *
 * Code generation for function 'fj_vd_matF_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "fj_vd_matF.h"
#include "fj_vd_matF_initialize.h"
#include "_coder_fj_vd_matF_mex.h"
#include "fj_vd_matF_data.h"

/* Variable Definitions */
static const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;

/* Function Definitions */
void fj_vd_matF_initialize(void)
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

/* End of code generation (fj_vd_matF_initialize.c) */
