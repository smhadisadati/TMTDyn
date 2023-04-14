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
#include "xtrsm.h"
#include "lusolve.h"
#include "xgetrf.h"

/* Variable Definitions */
static emlrtRSInfo agb_emlrtRSI = { 34,/* lineNo */
  "mldivide",                          /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/mldivide.m"/* pathName */
};

static emlrtRSInfo bgb_emlrtRSI = { 67,/* lineNo */
  "lusolve",                           /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pathName */
};

static emlrtRSInfo cgb_emlrtRSI = { 109,/* lineNo */
  "lusolve",                           /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pathName */
};

static emlrtRSInfo dgb_emlrtRSI = { 107,/* lineNo */
  "lusolve",                           /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pathName */
};

/* Function Definitions */
void mldivide(EOMStackData *SD, const emlrtStack *sp, const real_T b_A[10609],
              real_T B[103])
{
  int32_T ipiv[103];
  int32_T info;
  real_T temp;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &agb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &bgb_emlrtRSI;
  memcpy(&SD->f0.A[0], &b_A[0], 10609U * sizeof(real_T));
  c_st.site = &dgb_emlrtRSI;
  xgetrf(&c_st, SD->f0.A, ipiv, &info);
  if (info > 0) {
    c_st.site = &cgb_emlrtRSI;
    warn_singular(&c_st);
  }

  for (info = 0; info < 102; info++) {
    if (ipiv[info] != info + 1) {
      temp = B[info];
      B[info] = B[ipiv[info] - 1];
      B[ipiv[info] - 1] = temp;
    }
  }

  xtrsm(SD->f0.A, B);
  b_xtrsm(SD->f0.A, B);
}

/* End of code generation (mldivide.c) */
