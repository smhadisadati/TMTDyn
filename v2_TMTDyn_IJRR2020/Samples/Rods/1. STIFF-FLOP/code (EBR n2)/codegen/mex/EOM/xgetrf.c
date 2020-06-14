/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgetrf.c
 *
 * Code generation for function 'xgetrf'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "EOM.h"
#include "xgetrf.h"
#include "error.h"
#include "EOM_mexutil.h"
#include "lapacke.h"

/* Type Definitions */
#include <stdlib.h>

/* Variable Definitions */
static emlrtRSInfo xc_emlrtRSI = { 27, /* lineNo */
  "xgetrf",                            /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+lapack/xgetrf.m"/* pathName */
};

static emlrtRSInfo yc_emlrtRSI = { 90, /* lineNo */
  "xgetrf",                            /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+lapack/xgetrf.m"/* pathName */
};

static emlrtRSInfo ad_emlrtRSI = { 82, /* lineNo */
  "xgetrf",                            /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+lapack/xgetrf.m"/* pathName */
};

static emlrtRSInfo bd_emlrtRSI = { 78, /* lineNo */
  "xgetrf",                            /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+lapack/xgetrf.m"/* pathName */
};

static emlrtRSInfo cd_emlrtRSI = { 58, /* lineNo */
  "xgetrf",                            /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+lapack/xgetrf.m"/* pathName */
};

static emlrtRSInfo dd_emlrtRSI = { 57, /* lineNo */
  "xgetrf",                            /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+lapack/xgetrf.m"/* pathName */
};

static emlrtRSInfo ed_emlrtRSI = { 50, /* lineNo */
  "xgetrf",                            /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+lapack/xgetrf.m"/* pathName */
};

static emlrtRSInfo hd_emlrtRSI = { 45, /* lineNo */
  "infocheck",                         /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+lapack/infocheck.m"/* pathName */
};

static emlrtRSInfo id_emlrtRSI = { 48, /* lineNo */
  "infocheck",                         /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+lapack/infocheck.m"/* pathName */
};

/* Function Definitions */
void xgetrf(const emlrtStack *sp, real_T A[144], int32_T ipiv[12], int32_T *info)
{
  ptrdiff_t info_t;
  ptrdiff_t ipiv_t[12];
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &xc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &ed_emlrtRSI;
  b_st.site = &dd_emlrtRSI;
  b_st.site = &cd_emlrtRSI;
  b_st.site = &bd_emlrtRSI;
  b_st.site = &ad_emlrtRSI;
  emlrt_checkEscapedGlobals();
  info_t = LAPACKE_dgetrf_work(102, (ptrdiff_t)12, (ptrdiff_t)12, &A[0],
    (ptrdiff_t)12, &ipiv_t[0]);
  *info = (int32_T)info_t;
  b_st.site = &yc_emlrtRSI;
  if (*info < 0) {
    if (*info == -1010) {
      c_st.site = &hd_emlrtRSI;
      b_error(&c_st);
    } else {
      c_st.site = &id_emlrtRSI;
      c_error(&c_st, *info);
    }
  }

  for (k = 0; k < 12; k++) {
    ipiv[k] = (int32_T)ipiv_t[k];
  }
}

/* End of code generation (xgetrf.c) */
