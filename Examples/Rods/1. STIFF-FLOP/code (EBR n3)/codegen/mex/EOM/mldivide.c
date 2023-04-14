/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mldivide.c
 *
 * Code generation for function 'mldivide'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "EOM.h"
#include "mldivide.h"
#include "warning.h"
#include "xgetrf.h"

/* Variable Definitions */
static emlrtRSInfo fe_emlrtRSI = { 34, /* lineNo */
  "mldivide",                          /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/mldivide.m"/* pathName */
};

static emlrtRSInfo ge_emlrtRSI = { 67, /* lineNo */
  "lusolve",                           /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pathName */
};

static emlrtRSInfo he_emlrtRSI = { 109,/* lineNo */
  "lusolve",                           /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pathName */
};

static emlrtRSInfo ie_emlrtRSI = { 107,/* lineNo */
  "lusolve",                           /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pathName */
};

static emlrtRSInfo ve_emlrtRSI = { 90, /* lineNo */
  "lusolve",                           /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pathName */
};

/* Function Definitions */
void mldivide(const emlrtStack *sp, const real_T A[324], real_T B[18])
{
  real_T b_A[324];
  int32_T ipiv[18];
  int32_T info;
  real_T temp;
  int32_T kAcol;
  int32_T i4;
  int32_T i;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &fe_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &ge_emlrtRSI;
  memcpy(&b_A[0], &A[0], 324U * sizeof(real_T));
  c_st.site = &ie_emlrtRSI;
  xgetrf(&c_st, b_A, ipiv, &info);
  if (info > 0) {
    c_st.site = &he_emlrtRSI;
    d_st.site = &ve_emlrtRSI;
    warning(&d_st);
  }

  for (info = 0; info < 17; info++) {
    if (ipiv[info] != info + 1) {
      temp = B[info];
      B[info] = B[ipiv[info] - 1];
      B[ipiv[info] - 1] = temp;
    }
  }

  for (info = 0; info < 18; info++) {
    kAcol = 18 * info;
    if (B[info] != 0.0) {
      i4 = info + 2;
      for (i = i4; i < 19; i++) {
        B[i - 1] -= B[info] * b_A[(i + kAcol) - 1];
      }
    }
  }

  for (info = 17; info >= 0; info--) {
    kAcol = 18 * info;
    if (B[info] != 0.0) {
      B[info] /= b_A[info + kAcol];
      for (i = 0; i < info; i++) {
        B[i] -= B[info] * b_A[i + kAcol];
      }
    }
  }
}

/* End of code generation (mldivide.c) */
