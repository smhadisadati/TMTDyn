/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EOM.c
 *
 * Code generation for function 'EOM'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "EOM.h"
#include "mldivide.h"
#include "loadsF1.h"
#include "sprdmpF35.h"
#include "sprdmpF34.h"
#include "sprdmpF33.h"
#include "sprdmpF32.h"
#include "sprdmpF31.h"
#include "EOM_mexutil.h"
#include "massF6.h"
#include "massF5.h"
#include "massF4.h"
#include "massF3.h"
#include "massF2.h"
#include "massF1.h"
#include "int_mid_step.h"
#include "indexShapeCheck.h"
#include "EOM_data.h"
#include "blas.h"

/* Variable Definitions */
static emlrtRTEInfo emlrtRTEI = { 4,   /* lineNo */
  5,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pName */
};

static emlrtRSInfo emlrtRSI = { 9,     /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 11,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 26,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 27,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 28,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 35,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 36,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 37,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 44,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 45,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 46,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 53,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 54,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 55,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 62,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 63,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 64,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 71,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 72,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 73,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 80,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 90,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 100, /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 110, /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 120, /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 126,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 132,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo tb_emlrtRSI = { 21, /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pathName */
};

static emlrtRTEInfo b_emlrtRTEI = { 83,/* lineNo */
  23,                                  /* colNo */
  "eml_mtimes_helper",                 /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 88,/* lineNo */
  23,                                  /* colNo */
  "eml_mtimes_helper",                 /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 119,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 109,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 99,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 89,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 79,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 70,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 61,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 52,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 43,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pName */
};

static emlrtRTEInfo m_emlrtRTEI = { 34,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 25,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  9,                                   /* lineNo */
  13,                                  /* colNo */
  "u",                                 /* aName */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo emlrtDCI = { 9,     /* lineNo */
  13,                                  /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  9,                                   /* lineNo */
  9,                                   /* colNo */
  "u",                                 /* aName */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { 1,   /* iFirst */
  60,                                  /* iLast */
  8,                                   /* lineNo */
  8,                                   /* colNo */
  "z",                                 /* aName */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 8,   /* lineNo */
  8,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m",/* pName */
  1                                    /* checkKind */
};

/* Function Definitions */
void EOM(const emlrtStack *sp, real_T t, const real_T z[60], struct0_T *b_par,
         real_T dz_data[], int32_T dz_size[1])
{
  real_T alpha1;
  int32_T i0;
  int32_T i;
  int32_T u_size_idx_0_tmp;
  int32_T k;
  real_T u_data[60];
  int32_T loop_ub;
  int32_T iv0[2];
  real_T uq_data[60];
  real_T TMT[900];
  real_T TMfd[30];
  real_T w_vd_j[30];
  real_T w_sd[30];
  real_T w_in[30];
  real_T s0;
  real_T ds;
  int32_T s;
  real_T M[36];
  real_T T[180];
  real_T Dd[180];
  real_T fg[6];
  real_T a_tmp[180];
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  char_T TRANSA;
  char_T TRANSB;
  real_T a[180];
  real_T y[900];
  real_T b_y[6];
  real_T in[6];
  static const int8_T b_a[180] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0 };

  int32_T aoffset;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (t > t_report) {
    emlrtDisplayR2012b(emlrt_marshallOut(t), "t", &emlrtRTEI, sp);
    t_report = t + b_par->t_rep;
    t_report_dirty |= 1U;
  }

  alpha1 = (b_par->nq + b_par->nlambda) + 1.0;
  if (alpha1 > 60.0) {
    i0 = 0;
    i = 0;
  } else {
    if (alpha1 != (int32_T)muDoubleScalarFloor(alpha1)) {
      emlrtIntegerCheckR2012b(alpha1, &b_emlrtDCI, sp);
    }

    i0 = (int32_T)alpha1;
    if ((i0 < 1) || (i0 > 60)) {
      emlrtDynamicBoundsCheckR2012b(i0, 1, 60, &c_emlrtBCI, sp);
    }

    i0--;
    i = 60;
  }

  u_size_idx_0_tmp = i - i0;
  for (k = 0; k < u_size_idx_0_tmp; k++) {
    u_data[k] = z[i0 + k];
  }

  if (1.0 > b_par->nq) {
    loop_ub = 0;
  } else {
    if (1 > u_size_idx_0_tmp) {
      emlrtDynamicBoundsCheckR2012b(1, 1, u_size_idx_0_tmp, &b_emlrtBCI, sp);
    }

    if (b_par->nq != (int32_T)muDoubleScalarFloor(b_par->nq)) {
      emlrtIntegerCheckR2012b(b_par->nq, &emlrtDCI, sp);
    }

    loop_ub = (int32_T)b_par->nq;
    if ((loop_ub < 1) || (loop_ub > u_size_idx_0_tmp)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, u_size_idx_0_tmp, &emlrtBCI, sp);
    }
  }

  iv0[0] = 1;
  iv0[1] = loop_ub;
  st.site = &emlrtRSI;
  indexShapeCheck(&st, i - i0, iv0);
  if (0 <= loop_ub - 1) {
    memcpy(&uq_data[0], &u_data[0], (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
  }

  st.site = &b_emlrtRSI;
  int_mid_step(&st, t, b_par);
  memset(&TMT[0], 0, 900U * sizeof(real_T));
  memset(&TMfd[0], 0, 30U * sizeof(real_T));
  memset(&w_vd_j[0], 0, 30U * sizeof(real_T));
  memset(&w_sd[0], 0, 30U * sizeof(real_T));
  memset(&w_in[0], 0, 30U * sizeof(real_T));
  s0 = 1.0E-6;
  ds = b_par->rom.mass[0] / b_par->n_int;
  if (b_par->rom.mass[0] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = b_par->rom.mass[0] - s0;
  i0 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i0, &n_emlrtRTEI,
    sp);
  for (s = 0; s < i0; s++) {
    st.site = &c_emlrtRSI;
    massF1(&st, b_par->var, z, M, T, Dd, fg);
    st.site = &d_emlrtRSI;
    for (i = 0; i < 6; i++) {
      for (k = 0; k < 30; k++) {
        a_tmp[k + 30 * i] = T[i + 6 * k];
      }
    }

    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)30;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)30;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)30;
    TRANSA = 'N';
    TRANSB = 'N';
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &M[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &d_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)30;
    n_t = (ptrdiff_t)30;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)30;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)30;
    TRANSA = 'N';
    TRANSB = 'N';
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &s0, &y[0], &ldc_t);
    for (i = 0; i < 900; i++) {
      TMT[i] += y[i] * ds;
    }

    st.site = &e_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)30;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)30;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)30;
    TRANSA = 'N';
    TRANSB = 'N';
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &M[0],
          &ldb_t, &s0, &T[0], &ldc_t);
    st.site = &e_emlrtRSI;
    for (i = 0; i < 180; i++) {
      Dd[i] = -Dd[i];
    }

    b_st.site = &tb_emlrtRSI;
    if (30 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI, "MATLAB:innerdim",
          "MATLAB:innerdim", 0);
      }
    }

    for (i = 0; i < 6; i++) {
      b_y[i] = 0.0;
    }

    for (k = 0; k < 30; k++) {
      aoffset = k * 6;
      for (i = 0; i < 6; i++) {
        b_y[i] += u_data[k] * Dd[aoffset + i];
      }
    }

    for (i = 0; i < 6; i++) {
      b_y[i] += fg[i];
    }

    for (i = 0; i < 30; i++) {
      alpha1 = 0.0;
      for (k = 0; k < 6; k++) {
        alpha1 += T[i + 30 * k] * b_y[k];
      }

      TMfd[i] += alpha1 * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = b_par->rom.mass[1] / b_par->n_int;
  if (b_par->rom.mass[1] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = b_par->rom.mass[1] - s0;
  i0 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i0, &m_emlrtRTEI,
    sp);
  for (s = 0; s < i0; s++) {
    st.site = &f_emlrtRSI;
    massF2(&st, b_par->var, z, M, T, Dd, fg);
    st.site = &g_emlrtRSI;
    for (i = 0; i < 6; i++) {
      for (k = 0; k < 30; k++) {
        a_tmp[k + 30 * i] = T[i + 6 * k];
      }
    }

    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)30;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)30;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)30;
    TRANSA = 'N';
    TRANSB = 'N';
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &M[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &g_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)30;
    n_t = (ptrdiff_t)30;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)30;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)30;
    TRANSA = 'N';
    TRANSB = 'N';
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &s0, &y[0], &ldc_t);
    for (i = 0; i < 900; i++) {
      TMT[i] += y[i] * ds;
    }

    st.site = &h_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)30;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)30;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)30;
    TRANSA = 'N';
    TRANSB = 'N';
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &M[0],
          &ldb_t, &s0, &T[0], &ldc_t);
    st.site = &h_emlrtRSI;
    for (i = 0; i < 180; i++) {
      Dd[i] = -Dd[i];
    }

    b_st.site = &tb_emlrtRSI;
    if (30 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI, "MATLAB:innerdim",
          "MATLAB:innerdim", 0);
      }
    }

    for (i = 0; i < 6; i++) {
      b_y[i] = 0.0;
    }

    for (k = 0; k < 30; k++) {
      aoffset = k * 6;
      for (i = 0; i < 6; i++) {
        b_y[i] += u_data[k] * Dd[aoffset + i];
      }
    }

    for (i = 0; i < 6; i++) {
      b_y[i] += fg[i];
    }

    for (i = 0; i < 30; i++) {
      alpha1 = 0.0;
      for (k = 0; k < 6; k++) {
        alpha1 += T[i + 30 * k] * b_y[k];
      }

      TMfd[i] += alpha1 * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = b_par->rom.mass[2] / b_par->n_int;
  if (b_par->rom.mass[2] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = b_par->rom.mass[2] - s0;
  i0 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i0, &l_emlrtRTEI,
    sp);
  for (s = 0; s < i0; s++) {
    st.site = &i_emlrtRSI;
    massF3(&st, b_par->var, z, M, T, Dd, fg);
    st.site = &j_emlrtRSI;
    for (i = 0; i < 6; i++) {
      for (k = 0; k < 30; k++) {
        a_tmp[k + 30 * i] = T[i + 6 * k];
      }
    }

    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)30;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)30;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)30;
    TRANSA = 'N';
    TRANSB = 'N';
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &M[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &j_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)30;
    n_t = (ptrdiff_t)30;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)30;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)30;
    TRANSA = 'N';
    TRANSB = 'N';
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &s0, &y[0], &ldc_t);
    for (i = 0; i < 900; i++) {
      TMT[i] += y[i] * ds;
    }

    st.site = &k_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)30;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)30;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)30;
    TRANSA = 'N';
    TRANSB = 'N';
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &M[0],
          &ldb_t, &s0, &T[0], &ldc_t);
    st.site = &k_emlrtRSI;
    for (i = 0; i < 180; i++) {
      Dd[i] = -Dd[i];
    }

    b_st.site = &tb_emlrtRSI;
    if (30 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI, "MATLAB:innerdim",
          "MATLAB:innerdim", 0);
      }
    }

    for (i = 0; i < 6; i++) {
      b_y[i] = 0.0;
    }

    for (k = 0; k < 30; k++) {
      aoffset = k * 6;
      for (i = 0; i < 6; i++) {
        b_y[i] += u_data[k] * Dd[aoffset + i];
      }
    }

    for (i = 0; i < 6; i++) {
      b_y[i] += fg[i];
    }

    for (i = 0; i < 30; i++) {
      alpha1 = 0.0;
      for (k = 0; k < 6; k++) {
        alpha1 += T[i + 30 * k] * b_y[k];
      }

      TMfd[i] += alpha1 * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = b_par->rom.mass[3] / b_par->n_int;
  if (b_par->rom.mass[3] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = b_par->rom.mass[3] - s0;
  i0 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i0, &k_emlrtRTEI,
    sp);
  for (s = 0; s < i0; s++) {
    st.site = &l_emlrtRSI;
    massF4(&st, b_par->var, z, M, T, Dd, fg);
    st.site = &m_emlrtRSI;
    for (i = 0; i < 6; i++) {
      for (k = 0; k < 30; k++) {
        a_tmp[k + 30 * i] = T[i + 6 * k];
      }
    }

    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)30;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)30;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)30;
    TRANSA = 'N';
    TRANSB = 'N';
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &M[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &m_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)30;
    n_t = (ptrdiff_t)30;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)30;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)30;
    TRANSA = 'N';
    TRANSB = 'N';
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &s0, &y[0], &ldc_t);
    for (i = 0; i < 900; i++) {
      TMT[i] += y[i] * ds;
    }

    st.site = &n_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)30;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)30;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)30;
    TRANSA = 'N';
    TRANSB = 'N';
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &M[0],
          &ldb_t, &s0, &T[0], &ldc_t);
    st.site = &n_emlrtRSI;
    for (i = 0; i < 180; i++) {
      Dd[i] = -Dd[i];
    }

    b_st.site = &tb_emlrtRSI;
    if (30 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI, "MATLAB:innerdim",
          "MATLAB:innerdim", 0);
      }
    }

    for (i = 0; i < 6; i++) {
      b_y[i] = 0.0;
    }

    for (k = 0; k < 30; k++) {
      aoffset = k * 6;
      for (i = 0; i < 6; i++) {
        b_y[i] += u_data[k] * Dd[aoffset + i];
      }
    }

    for (i = 0; i < 6; i++) {
      b_y[i] += fg[i];
    }

    for (i = 0; i < 30; i++) {
      alpha1 = 0.0;
      for (k = 0; k < 6; k++) {
        alpha1 += T[i + 30 * k] * b_y[k];
      }

      TMfd[i] += alpha1 * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = b_par->rom.mass[4] / b_par->n_int;
  if (b_par->rom.mass[4] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = b_par->rom.mass[4] - s0;
  i0 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i0, &j_emlrtRTEI,
    sp);
  for (s = 0; s < i0; s++) {
    st.site = &o_emlrtRSI;
    massF5(&st, b_par->var, z, M, T, Dd, fg);
    st.site = &p_emlrtRSI;
    for (i = 0; i < 6; i++) {
      for (k = 0; k < 30; k++) {
        a_tmp[k + 30 * i] = T[i + 6 * k];
      }
    }

    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)30;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)30;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)30;
    TRANSA = 'N';
    TRANSB = 'N';
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &M[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &p_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)30;
    n_t = (ptrdiff_t)30;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)30;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)30;
    TRANSA = 'N';
    TRANSB = 'N';
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &s0, &y[0], &ldc_t);
    for (i = 0; i < 900; i++) {
      TMT[i] += y[i] * ds;
    }

    st.site = &q_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)30;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)30;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)30;
    TRANSA = 'N';
    TRANSB = 'N';
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &M[0],
          &ldb_t, &s0, &T[0], &ldc_t);
    st.site = &q_emlrtRSI;
    for (i = 0; i < 180; i++) {
      Dd[i] = -Dd[i];
    }

    b_st.site = &tb_emlrtRSI;
    if (30 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI, "MATLAB:innerdim",
          "MATLAB:innerdim", 0);
      }
    }

    for (i = 0; i < 6; i++) {
      b_y[i] = 0.0;
    }

    for (k = 0; k < 30; k++) {
      aoffset = k * 6;
      for (i = 0; i < 6; i++) {
        b_y[i] += u_data[k] * Dd[aoffset + i];
      }
    }

    for (i = 0; i < 6; i++) {
      b_y[i] += fg[i];
    }

    for (i = 0; i < 30; i++) {
      alpha1 = 0.0;
      for (k = 0; k < 6; k++) {
        alpha1 += T[i + 30 * k] * b_y[k];
      }

      TMfd[i] += alpha1 * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = b_par->rom.mass[5] / b_par->n_int;
  if (b_par->rom.mass[5] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = b_par->rom.mass[5] - s0;
  i0 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i0, &i_emlrtRTEI,
    sp);
  for (s = 0; s < i0; s++) {
    st.site = &r_emlrtRSI;
    massF6(&st, b_par->var, z, M, T, Dd, fg);
    st.site = &s_emlrtRSI;
    for (i = 0; i < 6; i++) {
      for (k = 0; k < 30; k++) {
        a_tmp[k + 30 * i] = T[i + 6 * k];
      }
    }

    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)30;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)30;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)30;
    TRANSA = 'N';
    TRANSB = 'N';
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &M[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &s_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)30;
    n_t = (ptrdiff_t)30;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)30;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)30;
    TRANSA = 'N';
    TRANSB = 'N';
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &s0, &y[0], &ldc_t);
    for (i = 0; i < 900; i++) {
      TMT[i] += y[i] * ds;
    }

    st.site = &t_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)30;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)30;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)30;
    TRANSA = 'N';
    TRANSB = 'N';
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &M[0],
          &ldb_t, &s0, &T[0], &ldc_t);
    st.site = &t_emlrtRSI;
    for (i = 0; i < 180; i++) {
      Dd[i] = -Dd[i];
    }

    b_st.site = &tb_emlrtRSI;
    if (30 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI, "MATLAB:innerdim",
          "MATLAB:innerdim", 0);
      }
    }

    for (i = 0; i < 6; i++) {
      b_y[i] = 0.0;
    }

    for (k = 0; k < 30; k++) {
      aoffset = k * 6;
      for (i = 0; i < 6; i++) {
        b_y[i] += u_data[k] * Dd[aoffset + i];
      }
    }

    for (i = 0; i < 6; i++) {
      b_y[i] += fg[i];
    }

    for (i = 0; i < 30; i++) {
      alpha1 = 0.0;
      for (k = 0; k < 6; k++) {
        alpha1 += T[i + 30 * k] * b_y[k];
      }

      TMfd[i] += alpha1 * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = b_par->rom.sprdmp[30] / b_par->n_int;
  if (b_par->rom.sprdmp[30] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = b_par->rom.sprdmp[30] - s0;
  i0 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i0, &h_emlrtRTEI,
    sp);
  for (s = 0; s < i0; s++) {
    st.site = &u_emlrtRSI;
    sprdmpF31(&st, b_par->var, z, fg, b_y, in);
    for (i = 0; i < 30; i++) {
      alpha1 = 0.0;
      for (k = 0; k < 6; k++) {
        alpha1 += (real_T)b_a[i + 30 * k] * b_y[k];
      }

      w_vd_j[i] += alpha1 * ds;
    }

    for (i = 0; i < 30; i++) {
      alpha1 = 0.0;
      for (k = 0; k < 6; k++) {
        alpha1 += (real_T)b_a[i + 30 * k] * fg[k];
      }

      w_sd[i] += alpha1 * ds;
    }

    for (i = 0; i < 30; i++) {
      alpha1 = 0.0;
      for (k = 0; k < 6; k++) {
        alpha1 += (real_T)b_a[i + 30 * k] * in[k];
      }

      w_in[i] += alpha1 * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = b_par->rom.sprdmp[31] / b_par->n_int;
  if (b_par->rom.sprdmp[31] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = b_par->rom.sprdmp[31] - s0;
  i0 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i0, &g_emlrtRTEI,
    sp);
  for (s = 0; s < i0; s++) {
    st.site = &v_emlrtRSI;
    sprdmpF32(&st, b_par->var, z, T, fg, b_y, in);
    for (i = 0; i < 30; i++) {
      alpha1 = 0.0;
      for (k = 0; k < 6; k++) {
        alpha1 += T[i + 30 * k] * b_y[k];
      }

      w_vd_j[i] += alpha1 * ds;
    }

    for (i = 0; i < 30; i++) {
      alpha1 = 0.0;
      for (k = 0; k < 6; k++) {
        alpha1 += T[i + 30 * k] * fg[k];
      }

      w_sd[i] += alpha1 * ds;
    }

    for (i = 0; i < 30; i++) {
      alpha1 = 0.0;
      for (k = 0; k < 6; k++) {
        alpha1 += T[i + 30 * k] * in[k];
      }

      w_in[i] += alpha1 * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = b_par->rom.sprdmp[32] / b_par->n_int;
  if (b_par->rom.sprdmp[32] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = b_par->rom.sprdmp[32] - s0;
  i0 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i0, &f_emlrtRTEI,
    sp);
  for (s = 0; s < i0; s++) {
    st.site = &w_emlrtRSI;
    sprdmpF33(&st, b_par->var, z, T, fg, b_y, in);
    for (i = 0; i < 30; i++) {
      alpha1 = 0.0;
      for (k = 0; k < 6; k++) {
        alpha1 += T[i + 30 * k] * b_y[k];
      }

      w_vd_j[i] += alpha1 * ds;
    }

    for (i = 0; i < 30; i++) {
      alpha1 = 0.0;
      for (k = 0; k < 6; k++) {
        alpha1 += T[i + 30 * k] * fg[k];
      }

      w_sd[i] += alpha1 * ds;
    }

    for (i = 0; i < 30; i++) {
      alpha1 = 0.0;
      for (k = 0; k < 6; k++) {
        alpha1 += T[i + 30 * k] * in[k];
      }

      w_in[i] += alpha1 * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = b_par->rom.sprdmp[33] / b_par->n_int;
  if (b_par->rom.sprdmp[33] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = b_par->rom.sprdmp[33] - s0;
  i0 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i0, &e_emlrtRTEI,
    sp);
  for (s = 0; s < i0; s++) {
    st.site = &x_emlrtRSI;
    sprdmpF34(&st, b_par->var, z, T, fg, b_y, in);
    for (i = 0; i < 30; i++) {
      alpha1 = 0.0;
      for (k = 0; k < 6; k++) {
        alpha1 += T[i + 30 * k] * b_y[k];
      }

      w_vd_j[i] += alpha1 * ds;
    }

    for (i = 0; i < 30; i++) {
      alpha1 = 0.0;
      for (k = 0; k < 6; k++) {
        alpha1 += T[i + 30 * k] * fg[k];
      }

      w_sd[i] += alpha1 * ds;
    }

    for (i = 0; i < 30; i++) {
      alpha1 = 0.0;
      for (k = 0; k < 6; k++) {
        alpha1 += T[i + 30 * k] * in[k];
      }

      w_in[i] += alpha1 * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = b_par->rom.sprdmp[34] / b_par->n_int;
  if (b_par->rom.sprdmp[34] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = b_par->rom.sprdmp[34] - s0;
  i0 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i0, &d_emlrtRTEI,
    sp);
  for (s = 0; s < i0; s++) {
    st.site = &y_emlrtRSI;
    sprdmpF35(&st, b_par->var, z, T, fg, b_y, in);
    for (i = 0; i < 30; i++) {
      alpha1 = 0.0;
      for (k = 0; k < 6; k++) {
        alpha1 += T[i + 30 * k] * b_y[k];
      }

      w_vd_j[i] += alpha1 * ds;
    }

    for (i = 0; i < 30; i++) {
      alpha1 = 0.0;
      for (k = 0; k < 6; k++) {
        alpha1 += T[i + 30 * k] * fg[k];
      }

      w_sd[i] += alpha1 * ds;
    }

    for (i = 0; i < 30; i++) {
      alpha1 = 0.0;
      for (k = 0; k < 6; k++) {
        alpha1 += T[i + 30 * k] * in[k];
      }

      w_in[i] += alpha1 * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  st.site = &ab_emlrtRSI;
  loadsF1(&st, b_par->var, z, T, fg);

  /*  EOM */
  for (i = 0; i < 30; i++) {
    alpha1 = 0.0;
    for (i0 = 0; i0 < 6; i0++) {
      alpha1 += T[i + 30 * i0] * fg[i0];
    }

    TMfd[i] = (((TMfd[i] + w_sd[i]) + w_in[i]) + w_vd_j[i]) + alpha1;
  }

  st.site = &bb_emlrtRSI;
  mldivide(&st, TMT, TMfd);
  dz_size[0] = u_size_idx_0_tmp + 30;
  if (0 <= u_size_idx_0_tmp - 1) {
    memcpy(&dz_data[0], &u_data[0], (uint32_T)(u_size_idx_0_tmp * (int32_T)
            sizeof(real_T)));
  }

  memcpy(&dz_data[u_size_idx_0_tmp], &TMfd[0], 30U * sizeof(real_T));
}

/* End of code generation (EOM.c) */
