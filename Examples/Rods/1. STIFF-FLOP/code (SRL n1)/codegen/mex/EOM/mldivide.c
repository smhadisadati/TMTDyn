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
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "EOM.h"
#include "mldivide.h"
#include "warning.h"
#include "eml_int_forloop_overflow_check.h"

/* Variable Definitions */
static emlrtRSInfo xb_emlrtRSI = { 34, /* lineNo */
  "mldivide",                          /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/mldivide.m"/* pathName */
};

static emlrtRSInfo yb_emlrtRSI = { 67, /* lineNo */
  "lusolve",                           /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pathName */
};

static emlrtRSInfo ac_emlrtRSI = { 109,/* lineNo */
  "lusolve",                           /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pathName */
};

static emlrtRSInfo bc_emlrtRSI = { 107,/* lineNo */
  "lusolve",                           /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pathName */
};

static emlrtRSInfo cc_emlrtRSI = { 30, /* lineNo */
  "xgetrf",                            /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+lapack/xgetrf.m"/* pathName */
};

static emlrtRSInfo dc_emlrtRSI = { 50, /* lineNo */
  "xzgetrf",                           /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+reflapack/xzgetrf.m"/* pathName */
};

static emlrtRSInfo ec_emlrtRSI = { 58, /* lineNo */
  "xzgetrf",                           /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+reflapack/xzgetrf.m"/* pathName */
};

static emlrtRSInfo fc_emlrtRSI = { 21, /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo gc_emlrtRSI = { 45, /* lineNo */
  "xgeru",                             /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+blas/xgeru.m"/* pathName */
};

static emlrtRSInfo hc_emlrtRSI = { 45, /* lineNo */
  "xger",                              /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+blas/xger.m"/* pathName */
};

static emlrtRSInfo ic_emlrtRSI = { 15, /* lineNo */
  "xger",                              /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+refblas/xger.m"/* pathName */
};

static emlrtRSInfo jc_emlrtRSI = { 54, /* lineNo */
  "xgerx",                             /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+refblas/xgerx.m"/* pathName */
};

static emlrtRSInfo kc_emlrtRSI = { 90, /* lineNo */
  "lusolve",                           /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pathName */
};

/* Function Definitions */
void mldivide(const emlrtStack *sp, const real_T A[36], real_T B[6])
{
  real_T b_A[36];
  int32_T iy;
  int32_T info;
  int8_T ipiv[6];
  int32_T j;
  int32_T b;
  int32_T jj;
  int32_T jp1j;
  int32_T n;
  int32_T jA;
  int32_T ix;
  real_T smax;
  int32_T k;
  real_T s;
  int32_T i;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack j_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &xb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  j_st.prev = &i_st;
  j_st.tls = i_st.tls;
  b_st.site = &yb_emlrtRSI;
  c_st.site = &bc_emlrtRSI;
  memcpy(&b_A[0], &A[0], 36U * sizeof(real_T));
  d_st.site = &cc_emlrtRSI;
  for (iy = 0; iy < 6; iy++) {
    ipiv[iy] = (int8_T)(1 + iy);
  }

  info = 0;
  for (j = 0; j < 5; j++) {
    b = j * 7;
    jj = j * 7;
    jp1j = b + 2;
    n = 6 - j;
    jA = 0;
    ix = b;
    smax = muDoubleScalarAbs(b_A[b]);
    for (k = 2; k <= n; k++) {
      ix++;
      s = muDoubleScalarAbs(b_A[ix]);
      if (s > smax) {
        jA = k - 1;
        smax = s;
      }
    }

    if (b_A[jj + jA] != 0.0) {
      if (jA != 0) {
        iy = j + jA;
        ipiv[j] = (int8_T)(iy + 1);
        ix = j;
        for (k = 0; k < 6; k++) {
          smax = b_A[ix];
          b_A[ix] = b_A[iy];
          b_A[iy] = smax;
          ix += 6;
          iy += 6;
        }
      }

      jA = (jj - j) + 6;
      e_st.site = &dc_emlrtRSI;
      for (i = jp1j; i <= jA; i++) {
        b_A[i - 1] /= b_A[jj];
      }
    } else {
      info = j + 1;
    }

    n = 4 - j;
    iy = b + 6;
    e_st.site = &ec_emlrtRSI;
    f_st.site = &gc_emlrtRSI;
    g_st.site = &hc_emlrtRSI;
    h_st.site = &ic_emlrtRSI;
    jA = jj + 8;
    for (i = 0; i <= n; i++) {
      smax = b_A[iy];
      if (b_A[iy] != 0.0) {
        ix = jj + 1;
        b = (jA - j) + 4;
        i_st.site = &jc_emlrtRSI;
        if ((jA <= b) && (b > 2147483646)) {
          j_st.site = &fc_emlrtRSI;
          check_forloop_overflow_error(&j_st);
        }

        for (jp1j = jA; jp1j <= b; jp1j++) {
          b_A[jp1j - 1] += b_A[ix] * -smax;
          ix++;
        }
      }

      iy += 6;
      jA += 6;
    }
  }

  if ((info == 0) && (!(b_A[35] != 0.0))) {
    info = 6;
  }

  if (info > 0) {
    c_st.site = &ac_emlrtRSI;
    d_st.site = &kc_emlrtRSI;
    warning(&d_st);
  }

  for (jA = 0; jA < 5; jA++) {
    if (ipiv[jA] != jA + 1) {
      smax = B[jA];
      iy = ipiv[jA] - 1;
      B[jA] = B[iy];
      B[iy] = smax;
    }
  }

  for (k = 0; k < 6; k++) {
    iy = 6 * k;
    if (B[k] != 0.0) {
      for (i = k + 2; i < 7; i++) {
        B[i - 1] -= B[k] * b_A[(i + iy) - 1];
      }
    }
  }

  for (k = 5; k >= 0; k--) {
    iy = 6 * k;
    if (B[k] != 0.0) {
      B[k] /= b_A[k + iy];
      for (i = 0; i < k; i++) {
        B[i] -= B[k] * b_A[i + iy];
      }
    }
  }
}

/* End of code generation (mldivide.c) */
