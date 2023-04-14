/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * warning.c
 *
 * Code generation for function 'warning'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "EOM.h"
#include "warning.h"
#include "EOM_mexutil.h"

/* Variable Definitions */
static emlrtMCInfo emlrtMCI = { 14,    /* lineNo */
  25,                                  /* colNo */
  "warning",                           /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/shared/coder/coder/+coder/+internal/warning.m"/* pName */
};

static emlrtMCInfo b_emlrtMCI = { 14,  /* lineNo */
  9,                                   /* colNo */
  "warning",                           /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/shared/coder/coder/+coder/+internal/warning.m"/* pName */
};

static emlrtRSInfo xc_emlrtRSI = { 14, /* lineNo */
  "warning",                           /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/shared/coder/coder/+coder/+internal/warning.m"/* pathName */
};

/* Function Declarations */
static void b_feval(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    emlrtMCInfo *location);
static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location);

/* Function Definitions */
static void b_feval(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  pArrays[0] = b;
  pArrays[1] = c;
  emlrtCallMATLABR2012b(sp, 0, NULL, 2, pArrays, "feval", true, location);
}

static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m9;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(sp, 1, &m9, 2, pArrays, "feval", true, location);
}

void warning(const emlrtStack *sp)
{
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv1[2] = { 1, 7 };

  static const char_T u[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *m1 = NULL;
  const mxArray *m2;
  static const int32_T iv2[2] = { 1, 7 };

  static const char_T b_u[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  const mxArray *m3 = NULL;
  const mxArray *m4;
  static const int32_T iv3[2] = { 1, 27 };

  static const char_T msgID[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a', 't',
    'r', 'i', 'x' };

  const mxArray *m5 = NULL;
  const mxArray *m6 = NULL;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  y = NULL;
  m0 = emlrtCreateCharArray(2, iv1);
  emlrtInitCharArrayR2013a(sp, 7, m0, &u[0]);
  emlrtAssign(&y, m0);
  emlrtAssign(&m1, y);
  y = NULL;
  m2 = emlrtCreateCharArray(2, iv2);
  emlrtInitCharArrayR2013a(sp, 7, m2, &b_u[0]);
  emlrtAssign(&y, m2);
  emlrtAssign(&m3, y);
  y = NULL;
  m4 = emlrtCreateCharArray(2, iv3);
  emlrtInitCharArrayR2013a(sp, 27, m4, &msgID[0]);
  emlrtAssign(&y, m4);
  emlrtAssign(&m5, y);
  emlrt_synchGlobalsToML(sp);
  st.site = &xc_emlrtRSI;
  emlrtAssign(&m6, feval(&st, emlrtAlias(m3), emlrtAlias(m5), &emlrtMCI));
  emlrt_synchGlobalsFromML(sp);
  emlrt_synchGlobalsToML(sp);
  st.site = &xc_emlrtRSI;
  b_feval(&st, emlrtAlias(m1), emlrtAlias(m6), &b_emlrtMCI);
  emlrt_synchGlobalsFromML(sp);
  emlrtDestroyArray(&m1);
  emlrtDestroyArray(&m6);
  emlrtDestroyArray(&m3);
  emlrtDestroyArray(&m5);
}

/* End of code generation (warning.c) */
