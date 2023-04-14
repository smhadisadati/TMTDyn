/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sprdmpF66_terminate.c
 *
 * Code generation for function 'sprdmpF66_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "sprdmpF66.h"
#include "sprdmpF66_terminate.h"
#include "_coder_sprdmpF66_mex.h"
#include "sprdmpF66_data.h"

/* Function Definitions */
void sprdmpF66_atexit(void)
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

void sprdmpF66_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (sprdmpF66_terminate.c) */
