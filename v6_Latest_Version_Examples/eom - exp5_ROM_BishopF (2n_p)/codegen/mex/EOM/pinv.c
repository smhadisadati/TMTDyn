/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pinv.c
 *
 * Code generation for function 'pinv'
 *
 */

/* Include files */
#include "pinv.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <math.h>
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo bd_emlrtRSI = { 21, /* lineNo */
  "pinv",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m"/* pathName */
};

static emlrtRSInfo cd_emlrtRSI = { 42, /* lineNo */
  "eml_pinv",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m"/* pathName */
};

static emlrtRSInfo dd_emlrtRSI = { 46, /* lineNo */
  "eml_pinv",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m"/* pathName */
};

static emlrtRSInfo ed_emlrtRSI = { 53, /* lineNo */
  "eml_pinv",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m"/* pathName */
};

static emlrtRSInfo fd_emlrtRSI = { 68, /* lineNo */
  "eml_pinv",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m"/* pathName */
};

static emlrtRSInfo gd_emlrtRSI = { 69, /* lineNo */
  "eml_pinv",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m"/* pathName */
};

static emlrtRSInfo hd_emlrtRSI = { 72, /* lineNo */
  "eml_pinv",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m"/* pathName */
};

static emlrtRSInfo id_emlrtRSI = { 29, /* lineNo */
  "anyNonFinite",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\anyNonFinite.m"/* pathName */
};

static emlrtRSInfo jd_emlrtRSI = { 44, /* lineNo */
  "vAllOrAny",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\vAllOrAny.m"/* pathName */
};

static emlrtRSInfo kd_emlrtRSI = { 103,/* lineNo */
  "flatVectorAllOrAny",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\vAllOrAny.m"/* pathName */
};

static emlrtRSInfo ld_emlrtRSI = { 21, /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo md_emlrtRSI = { 53, /* lineNo */
  "svd",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m"/* pathName */
};

static emlrtRSInfo nd_emlrtRSI = { 90, /* lineNo */
  "callLAPACK",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m"/* pathName */
};

static emlrtRSInfo od_emlrtRSI = { 82, /* lineNo */
  "callLAPACK",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m"/* pathName */
};

static emlrtRSInfo pd_emlrtRSI = { 209,/* lineNo */
  "xgesdd",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgesdd.m"/* pathName */
};

static emlrtRSInfo qd_emlrtRSI = { 31, /* lineNo */
  "xgesvd",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgesvd.m"/* pathName */
};

static emlrtRSInfo rd_emlrtRSI = { 197,/* lineNo */
  "ceval_xgesvd",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgesvd.m"/* pathName */
};

static emlrtRSInfo sd_emlrtRSI = { 31, /* lineNo */
  "xscal",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xscal.m"/* pathName */
};

static emlrtRSInfo td_emlrtRSI = { 18, /* lineNo */
  "xscal",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xscal.m"/* pathName */
};

static emlrtRSInfo ud_emlrtRSI = { 46, /* lineNo */
  "eps",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\elmat\\eps.m"/* pathName */
};

static emlrtRSInfo vd_emlrtRSI = { 75, /* lineNo */
  "xgemm",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgemm.m"/* pathName */
};

static emlrtRSInfo wd_emlrtRSI = { 92, /* lineNo */
  "xgemm_blas",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgemm.m"/* pathName */
};

static emlrtRTEInfo b_emlrtRTEI = { 47,/* lineNo */
  13,                                  /* colNo */
  "infocheck",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\infocheck.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 44,/* lineNo */
  13,                                  /* colNo */
  "infocheck",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\infocheck.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 112,/* lineNo */
  5,                                   /* colNo */
  "callLAPACK",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m"/* pName */
};

/* Function Definitions */
void pinv(const emlrtStack *sp, const real_T A[225], real_T X[225])
{
  static const char_T b_fname[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_',
    'd', 'g', 'e', 's', 'v', 'd' };

  static const char_T fname[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'd',
    'g', 'e', 's', 'd', 'd' };

  ptrdiff_t info_t;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  real_T U[225];
  real_T V[225];
  real_T Vt[225];
  real_T b_A[225];
  real_T S[15];
  real_T superb[14];
  real_T absx;
  real_T beta1;
  int32_T info;
  int32_T j;
  int32_T k;
  int32_T vcol;
  char_T TRANSA1;
  char_T TRANSB1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &bd_emlrtRSI;
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
  memset(&X[0], 0, 225U * sizeof(real_T));
  b_st.site = &cd_emlrtRSI;
  c_st.site = &id_emlrtRSI;
  d_st.site = &jd_emlrtRSI;
  p = true;
  e_st.site = &kd_emlrtRSI;
  for (k = 0; k < 225; k++) {
    if ((!p) || (muDoubleScalarIsInf(A[k]) || muDoubleScalarIsNaN(A[k]))) {
      p = false;
    }
  }

  if (!p) {
    for (info = 0; info < 225; info++) {
      X[info] = rtNaN;
    }
  } else {
    b_st.site = &dd_emlrtRSI;
    c_st.site = &md_emlrtRSI;
    memcpy(&V[0], &A[0], 225U * sizeof(real_T));
    d_st.site = &od_emlrtRSI;
    memcpy(&b_A[0], &A[0], 225U * sizeof(real_T));
    info_t = LAPACKE_dgesdd(102, 'S', (ptrdiff_t)15, (ptrdiff_t)15, &b_A[0],
      (ptrdiff_t)15, &S[0], &U[0], (ptrdiff_t)15, &Vt[0], (ptrdiff_t)15);
    info = (int32_T)info_t;
    e_st.site = &pd_emlrtRSI;
    if (info < 0) {
      if (info == -1010) {
        emlrtErrorWithMessageIdR2018a(&e_st, &c_emlrtRTEI, "MATLAB:nomem",
          "MATLAB:nomem", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&e_st, &b_emlrtRTEI,
          "Coder:toolbox:LAPACKCallErrorInfo",
          "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, fname, 12, info);
      }
    }

    if (info > 0) {
      d_st.site = &nd_emlrtRSI;
      e_st.site = &qd_emlrtRSI;
      info_t = LAPACKE_dgesvd(102, 'S', 'S', (ptrdiff_t)15, (ptrdiff_t)15, &V[0],
        (ptrdiff_t)15, &S[0], &U[0], (ptrdiff_t)15, &Vt[0], (ptrdiff_t)15,
        &superb[0]);
      info = (int32_T)info_t;
      for (j = 0; j < 15; j++) {
        for (k = 0; k < 15; k++) {
          V[k + 15 * j] = Vt[j + 15 * k];
        }
      }

      f_st.site = &rd_emlrtRSI;
      if (info < 0) {
        if (info == -1010) {
          emlrtErrorWithMessageIdR2018a(&f_st, &c_emlrtRTEI, "MATLAB:nomem",
            "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(&f_st, &b_emlrtRTEI,
            "Coder:toolbox:LAPACKCallErrorInfo",
            "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, b_fname, 12, info);
        }
      }
    } else {
      for (j = 0; j < 15; j++) {
        for (k = 0; k < 15; k++) {
          V[k + 15 * j] = Vt[j + 15 * k];
        }
      }
    }

    if (info > 0) {
      emlrtErrorWithMessageIdR2018a(&c_st, &d_emlrtRTEI,
        "Coder:MATLAB:svd_NoConvergence", "Coder:MATLAB:svd_NoConvergence", 0);
    }

    b_st.site = &ed_emlrtRSI;
    c_st.site = &ud_emlrtRSI;
    absx = muDoubleScalarAbs(S[0]);
    if ((!muDoubleScalarIsInf(absx)) && (!muDoubleScalarIsNaN(absx))) {
      if (absx <= 2.2250738585072014E-308) {
        absx = 4.94065645841247E-324;
      } else {
        frexp(absx, &vcol);
        absx = ldexp(1.0, vcol - 53);
      }
    } else {
      absx = rtNaN;
    }

    absx *= 15.0;
    info = 0;
    k = 0;
    while ((k < 15) && (S[k] > absx)) {
      info++;
      k++;
    }

    if (info > 0) {
      vcol = 15;
      b_st.site = &fd_emlrtRSI;
      if (info > 2147483646) {
        c_st.site = &ld_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (j = 0; j < info; j++) {
        absx = 1.0 / S[j];
        b_st.site = &gd_emlrtRSI;
        c_st.site = &sd_emlrtRSI;
        d_st.site = &td_emlrtRSI;
        if ((vcol - 14 <= vcol) && (vcol > 2147483646)) {
          e_st.site = &ld_emlrtRSI;
          check_forloop_overflow_error(&e_st);
        }

        for (k = vcol - 14; k <= vcol; k++) {
          V[k - 1] *= absx;
        }

        vcol += 15;
      }

      b_st.site = &hd_emlrtRSI;
      c_st.site = &vd_emlrtRSI;
      d_st.site = &wd_emlrtRSI;
      absx = 1.0;
      beta1 = 0.0;
      TRANSB1 = 'C';
      TRANSA1 = 'N';
      info_t = (ptrdiff_t)15;
      n_t = (ptrdiff_t)15;
      k_t = (ptrdiff_t)info;
      lda_t = (ptrdiff_t)15;
      ldb_t = (ptrdiff_t)15;
      ldc_t = (ptrdiff_t)15;
      dgemm(&TRANSA1, &TRANSB1, &info_t, &n_t, &k_t, &absx, &V[0], &lda_t, &U[0],
            &ldb_t, &beta1, &X[0], &ldc_t);
    }
  }
}

/* End of code generation (pinv.c) */
