/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fj_vd_matF_terminate.c
 *
 * Code generation for function 'fj_vd_matF_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "fj_vd_matF.h"
#include "fj_vd_matF_terminate.h"
#include "_coder_fj_vd_matF_mex.h"
#include "fj_vd_matF_data.h"

/* Function Definitions */
void fj_vd_matF_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void fj_vd_matF_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (fj_vd_matF_terminate.c) */
