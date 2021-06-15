/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EOM_eq_data.c
 *
 * Code generation for function 'EOM_eq_data'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "EOM_eq.h"
#include "EOM_eq_data.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
b_struct_T par_i;
uint32_T par_i_dirty;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131467U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "EOM_eq",                            /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

emlrtRSInfo p_emlrtRSI = { 49,         /* lineNo */
  "power",                             /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

emlrtRSInfo q_emlrtRSI = { 12,         /* lineNo */
  "sqrt",                              /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/elfun/sqrt.m"/* pathName */
};

const real_T dv0[6] = { 0.0, 0.0, 9.81, 0.0, 0.0, 0.0 };

/* End of code generation (EOM_eq_data.c) */
