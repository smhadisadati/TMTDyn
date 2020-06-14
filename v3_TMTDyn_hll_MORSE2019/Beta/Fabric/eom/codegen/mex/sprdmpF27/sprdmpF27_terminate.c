/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sprdmpF27_terminate.c
 *
 * Code generation for function 'sprdmpF27_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "sprdmpF27.h"
#include "sprdmpF27_terminate.h"
#include "_coder_sprdmpF27_mex.h"
#include "sprdmpF27_data.h"

/* Function Definitions */
void sprdmpF27_atexit(void)
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

void sprdmpF27_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (sprdmpF27_terminate.c) */
