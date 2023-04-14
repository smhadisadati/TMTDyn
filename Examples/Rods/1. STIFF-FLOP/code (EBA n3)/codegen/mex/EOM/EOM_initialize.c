/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EOM_initialize.c
 *
 * Code generation for function 'EOM_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "EOM_mexutil.h"
#include "EOM.h"
#include "EOM_initialize.h"
#include "_coder_EOM_mex.h"
#include "EOM_data.h"

/* Named Constants */
#define b_t_report                     (0.0)

/* Function Declarations */
static void EOM_once(const emlrtStack *sp);

/* Function Definitions */
static void EOM_once(const emlrtStack *sp)
{
  t_report = b_t_report;
  t_report_dirty = 1U;
  emlrtSetGlobalSyncFcn(sp, (void (*)(const void *))emlrt_synchGlobalsToML);
}

void EOM_initialize(void)
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
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    EOM_once(&st);
  }
}

/* End of code generation (EOM_initialize.c) */
