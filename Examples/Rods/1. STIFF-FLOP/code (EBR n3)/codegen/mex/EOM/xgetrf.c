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
static emlrtRSInfo ke_emlrtRSI = { 27, /* lineNo */
  "xgetrf",                            /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+lapack/xgetrf.m"/* pathName */
};

static emlrtRSInfo le_emlrtRSI = { 90, /* lineNo */
  "xgetrf",                            /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+lapack/xgetrf.m"/* pathName */
};

static emlrtRSInfo me_emlrtRSI = { 82, /* lineNo */
  "xgetrf",                            /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+lapack/xgetrf.m"/* pathName */
};

static emlrtRSInfo ne_emlrtRSI = { 78, /* lineNo */
  "xgetrf",                            /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+lapack/xgetrf.m"/* pathName */
};

static emlrtRSInfo oe_emlrtRSI = { 58, /* lineNo */
  "xgetrf",                            /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+lapack/xgetrf.m"/* pathName */
};

static emlrtRSInfo pe_emlrtRSI = { 57, /* lineNo */
  "xgetrf",                            /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+lapack/xgetrf.m"/* pathName */
};

static emlrtRSInfo qe_emlrtRSI = { 50, /* lineNo */
  "xgetrf",                            /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+lapack/xgetrf.m"/* pathName */
};

static emlrtRSInfo te_emlrtRSI = { 45, /* lineNo */
  "infocheck",                         /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+lapack/infocheck.m"/* pathName */
};

static emlrtRSInfo ue_emlrtRSI = { 48, /* lineNo */
  "infocheck",                         /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+lapack/infocheck.m"/* pathName */
};

/* Function Definitions */
void xgetrf(const emlrtStack *sp, real_T A[324], int32_T ipiv[18], int32_T *info)
{
  ptrdiff_t info_t;
  ptrdiff_t ipiv_t[18];
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ke_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &qe_emlrtRSI;
  b_st.site = &pe_emlrtRSI;
  b_st.site = &oe_emlrtRSI;
  b_st.site = &ne_emlrtRSI;
  b_st.site = &me_emlrtRSI;
  emlrt_checkEscapedGlobals();
  info_t = LAPACKE_dgetrf_work(102, (ptrdiff_t)18, (ptrdiff_t)18, &A[0],
    (ptrdiff_t)18, &ipiv_t[0]);
  *info = (int32_T)info_t;
  b_st.site = &le_emlrtRSI;
  if (*info < 0) {
    if (*info == -1010) {
      c_st.site = &te_emlrtRSI;
      b_error(&c_st);
    } else {
      c_st.site = &ue_emlrtRSI;
      c_error(&c_st, *info);
    }
  }

  for (k = 0; k < 18; k++) {
    ipiv[k] = (int32_T)ipiv_t[k];
  }
}

/* End of code generation (xgetrf.c) */
