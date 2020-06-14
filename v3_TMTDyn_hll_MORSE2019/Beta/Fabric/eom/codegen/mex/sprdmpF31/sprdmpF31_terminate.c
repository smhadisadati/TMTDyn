/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sprdmpF31_terminate.c
 *
 * Code generation for function 'sprdmpF31_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "sprdmpF31.h"
#include "sprdmpF31_terminate.h"
#include "_coder_sprdmpF31_mex.h"
#include "sprdmpF31_data.h"

/* Function Definitions */
void sprdmpF31_atexit(void)
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

void sprdmpF31_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (sprdmpF31_terminate.c) */
