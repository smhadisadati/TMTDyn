/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sprdmpF46_terminate.c
 *
 * Code generation for function 'sprdmpF46_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "sprdmpF46.h"
#include "sprdmpF46_terminate.h"
#include "_coder_sprdmpF46_mex.h"
#include "sprdmpF46_data.h"

/* Function Definitions */
void sprdmpF46_atexit(void)
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

void sprdmpF46_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (sprdmpF46_terminate.c) */
