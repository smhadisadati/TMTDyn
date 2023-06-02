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
static emlrtRSInfo ye_emlrtRSI = { 21, /* lineNo */
  "pinv",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m"/* pathName */
};

static emlrtRSInfo af_emlrtRSI = { 42, /* lineNo */
  "eml_pinv",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m"/* pathName */
};

static emlrtRSInfo bf_emlrtRSI = { 46, /* lineNo */
  "eml_pinv",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m"/* pathName */
};

static emlrtRSInfo cf_emlrtRSI = { 53, /* lineNo */
  "eml_pinv",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m"/* pathName */
};

static emlrtRSInfo df_emlrtRSI = { 68, /* lineNo */
  "eml_pinv",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m"/* pathName */
};

static emlrtRSInfo ef_emlrtRSI = { 69, /* lineNo */
  "eml_pinv",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m"/* pathName */
};

static emlrtRSInfo ff_emlrtRSI = { 72, /* lineNo */
  "eml_pinv",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m"/* pathName */
};

static emlrtRSInfo gf_emlrtRSI = { 29, /* lineNo */
  "anyNonFinite",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\anyNonFinite.m"/* pathName */
};

static emlrtRSInfo hf_emlrtRSI = { 44, /* lineNo */
  "vAllOrAny",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\vAllOrAny.m"/* pathName */
};

static emlrtRSInfo if_emlrtRSI = { 103,/* lineNo */
  "flatVectorAllOrAny",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\vAllOrAny.m"/* pathName */
};

static emlrtRSInfo jf_emlrtRSI = { 21, /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo kf_emlrtRSI = { 53, /* lineNo */
  "svd",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m"/* pathName */
};

static emlrtRSInfo lf_emlrtRSI = { 90, /* lineNo */
  "callLAPACK",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m"/* pathName */
};

static emlrtRSInfo mf_emlrtRSI = { 82, /* lineNo */
  "callLAPACK",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m"/* pathName */
};

static emlrtRSInfo nf_emlrtRSI = { 209,/* lineNo */
  "xgesdd",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgesdd.m"/* pathName */
};

static emlrtRSInfo of_emlrtRSI = { 31, /* lineNo */
  "xgesvd",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgesvd.m"/* pathName */
};

static emlrtRSInfo pf_emlrtRSI = { 197,/* lineNo */
  "ceval_xgesvd",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgesvd.m"/* pathName */
};

static emlrtRSInfo qf_emlrtRSI = { 31, /* lineNo */
  "xscal",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xscal.m"/* pathName */
};

static emlrtRSInfo rf_emlrtRSI = { 18, /* lineNo */
  "xscal",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xscal.m"/* pathName */
};

static emlrtRSInfo sf_emlrtRSI = { 46, /* lineNo */
  "eps",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\elmat\\eps.m"/* pathName */
};

static emlrtRSInfo tf_emlrtRSI = { 75, /* lineNo */
  "xgemm",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgemm.m"/* pathName */
};

static emlrtRSInfo uf_emlrtRSI = { 92, /* lineNo */
  "xgemm_blas",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgemm.m"/* pathName */
};

static emlrtRTEInfo d_emlrtRTEI = { 47,/* lineNo */
  13,                                  /* colNo */
  "infocheck",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\infocheck.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 44,/* lineNo */
  13,                                  /* colNo */
  "infocheck",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\infocheck.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 112,/* lineNo */
  5,                                   /* colNo */
  "callLAPACK",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m"/* pName */
};

/* Function Definitions */
void pinv(const emlrtStack *sp, const real_T A[289], real_T X[289])
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
  real_T U[289];
  real_T V[289];
  real_T Vt[289];
  real_T b_A[289];
  real_T S[17];
  real_T superb[16];
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
  st.site = &ye_emlrtRSI;
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
  memset(&X[0], 0, 289U * sizeof(real_T));
  b_st.site = &af_emlrtRSI;
  c_st.site = &gf_emlrtRSI;
  d_st.site = &hf_emlrtRSI;
  p = true;
  e_st.site = &if_emlrtRSI;
  for (k = 0; k < 289; k++) {
    if ((!p) || (muDoubleScalarIsInf(A[k]) || muDoubleScalarIsNaN(A[k]))) {
      p = false;
    }
  }

  if (!p) {
    for (info = 0; info < 289; info++) {
      X[info] = rtNaN;
    }
  } else {
    b_st.site = &bf_emlrtRSI;
    c_st.site = &kf_emlrtRSI;
    memcpy(&V[0], &A[0], 289U * sizeof(real_T));
    d_st.site = &mf_emlrtRSI;
    memcpy(&b_A[0], &A[0], 289U * sizeof(real_T));
    info_t = LAPACKE_dgesdd(102, 'S', (ptrdiff_t)17, (ptrdiff_t)17, &b_A[0],
      (ptrdiff_t)17, &S[0], &U[0], (ptrdiff_t)17, &Vt[0], (ptrdiff_t)17);
    info = (int32_T)info_t;
    e_st.site = &nf_emlrtRSI;
    if (info < 0) {
      if (info == -1010) {
        emlrtErrorWithMessageIdR2018a(&e_st, &e_emlrtRTEI, "MATLAB:nomem",
          "MATLAB:nomem", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&e_st, &d_emlrtRTEI,
          "Coder:toolbox:LAPACKCallErrorInfo",
          "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, fname, 12, info);
      }
    }

    if (info > 0) {
      d_st.site = &lf_emlrtRSI;
      e_st.site = &of_emlrtRSI;
      info_t = LAPACKE_dgesvd(102, 'S', 'S', (ptrdiff_t)17, (ptrdiff_t)17, &V[0],
        (ptrdiff_t)17, &S[0], &U[0], (ptrdiff_t)17, &Vt[0], (ptrdiff_t)17,
        &superb[0]);
      info = (int32_T)info_t;
      for (j = 0; j < 17; j++) {
        for (k = 0; k < 17; k++) {
          V[k + 17 * j] = Vt[j + 17 * k];
        }
      }

      f_st.site = &pf_emlrtRSI;
      if (info < 0) {
        if (info == -1010) {
          emlrtErrorWithMessageIdR2018a(&f_st, &e_emlrtRTEI, "MATLAB:nomem",
            "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(&f_st, &d_emlrtRTEI,
            "Coder:toolbox:LAPACKCallErrorInfo",
            "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, b_fname, 12, info);
        }
      }
    } else {
      for (j = 0; j < 17; j++) {
        for (k = 0; k < 17; k++) {
          V[k + 17 * j] = Vt[j + 17 * k];
        }
      }
    }

    if (info > 0) {
      emlrtErrorWithMessageIdR2018a(&c_st, &f_emlrtRTEI,
        "Coder:MATLAB:svd_NoConvergence", "Coder:MATLAB:svd_NoConvergence", 0);
    }

    b_st.site = &cf_emlrtRSI;
    c_st.site = &sf_emlrtRSI;
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

    absx *= 17.0;
    info = 0;
    k = 0;
    while ((k < 17) && (S[k] > absx)) {
      info++;
      k++;
    }

    if (info > 0) {
      vcol = 17;
      b_st.site = &df_emlrtRSI;
      if (info > 2147483646) {
        c_st.site = &jf_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (j = 0; j < info; j++) {
        absx = 1.0 / S[j];
        b_st.site = &ef_emlrtRSI;
        c_st.site = &qf_emlrtRSI;
        d_st.site = &rf_emlrtRSI;
        if ((vcol - 16 <= vcol) && (vcol > 2147483646)) {
          e_st.site = &jf_emlrtRSI;
          check_forloop_overflow_error(&e_st);
        }

        for (k = vcol - 16; k <= vcol; k++) {
          V[k - 1] *= absx;
        }

        vcol += 17;
      }

      b_st.site = &ff_emlrtRSI;
      c_st.site = &tf_emlrtRSI;
      d_st.site = &uf_emlrtRSI;
      absx = 1.0;
      beta1 = 0.0;
      TRANSB1 = 'C';
      TRANSA1 = 'N';
      info_t = (ptrdiff_t)17;
      n_t = (ptrdiff_t)17;
      k_t = (ptrdiff_t)info;
      lda_t = (ptrdiff_t)17;
      ldb_t = (ptrdiff_t)17;
      ldc_t = (ptrdiff_t)17;
      dgemm(&TRANSA1, &TRANSB1, &info_t, &n_t, &k_t, &absx, &V[0], &lda_t, &U[0],
            &ldb_t, &beta1, &X[0], &ldc_t);
    }
  }
}

/* End of code generation (pinv.c) */
