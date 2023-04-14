/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sprdmpF29_terminate.c
 *
 * Code generation for function 'sprdmpF29_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "sprdmpF29.h"
#include "sprdmpF29_terminate.h"
#include "_coder_sprdmpF29_mex.h"
#include "sprdmpF29_data.h"

/* Function Definitions */
void sprdmpF29_atexit(void)
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

void sprdmpF29_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (sprdmpF29_terminate.c) */
