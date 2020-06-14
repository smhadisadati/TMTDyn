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
#include "fj_kF.h"
#include "fj_vdF.h"
#include "massF1.h"
#include "massF2.h"
#include "massF3.h"
#include "loadsF1.h"
#include "mldivide.h"
#include "EOM_mexutil.h"
#include "fj_inF.h"
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

static emlrtRSInfo c_emlrtRSI = { 13,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 14,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 15,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 26,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 27,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 28,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 35,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 36,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 37,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 44,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 45,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 46,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 49,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 55,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo bc_emlrtRSI = { 21, /* lineNo */
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

static emlrtRTEInfo d_emlrtRTEI = { 43,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 34,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 25,/* lineNo */
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
  24,                                  /* iLast */
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
void EOM(const emlrtStack *sp, real_T t, const real_T z[24], struct0_T *b_par,
         real_T dz_data[], int32_T dz_size[1])
{
  real_T alpha1;
  int32_T i0;
  int32_T i;
  int32_T u_size_idx_0_tmp;
  int32_T k;
  real_T u_data[24];
  int32_T loop_ub;
  int32_T iv0[2];
  real_T uq_data[24];
  real_T fj_k[12];
  real_T fj_vd[12];
  real_T fj_in[12];
  real_T TMT[144];
  real_T TMfd[12];
  real_T s0;
  real_T ds;
  int32_T s;
  real_T M[36];
  real_T T[72];
  real_T Dd[72];
  real_T fg[6];
  int32_T aoffset;
  real_T a[72];
  int32_T i1;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  char_T TRANSA;
  char_T TRANSB;
  real_T y[144];
  real_T b_y[6];
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
  if (alpha1 > 24.0) {
    i0 = 0;
    i = 0;
  } else {
    if (alpha1 != (int32_T)muDoubleScalarFloor(alpha1)) {
      emlrtIntegerCheckR2012b(alpha1, &b_emlrtDCI, sp);
    }

    i0 = (int32_T)alpha1;
    if ((i0 < 1) || (i0 > 24)) {
      emlrtDynamicBoundsCheckR2012b(i0, 1, 24, &c_emlrtBCI, sp);
    }

    i0--;
    i = 24;
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
  st.site = &c_emlrtRSI;
  fj_kF(b_par->var, z, fj_k);
  st.site = &d_emlrtRSI;
  fj_vdF(b_par->var, z, fj_vd);
  st.site = &e_emlrtRSI;
  fj_inF(&st, b_par->var, fj_in);
  memset(&TMT[0], 0, 144U * sizeof(real_T));
  memset(&TMfd[0], 0, 12U * sizeof(real_T));
  s0 = 1.0E-6;
  ds = b_par->rom.mass[0] / b_par->n_int;
  if (b_par->rom.mass[0] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = b_par->rom.mass[0] - s0;
  i0 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i0, &f_emlrtRTEI,
    sp);
  for (s = 0; s < i0; s++) {
    st.site = &f_emlrtRSI;
    massF1(b_par->var, z, M, T, Dd, fg);
    for (i = 0; i < 12; i++) {
      for (k = 0; k < 6; k++) {
        aoffset = i + 12 * k;
        a[aoffset] = 0.0;
        alpha1 = 0.0;
        for (i1 = 0; i1 < 6; i1++) {
          alpha1 += T[i1 + 6 * i] * M[i1 + 6 * k];
        }

        a[aoffset] = alpha1;
      }
    }

    st.site = &g_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)12;
    n_t = (ptrdiff_t)12;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)12;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)12;
    TRANSA = 'N';
    TRANSB = 'N';
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &s0, &y[0], &ldc_t);
    for (i = 0; i < 144; i++) {
      TMT[i] += y[i] * ds;
    }

    st.site = &h_emlrtRSI;
    for (i = 0; i < 72; i++) {
      Dd[i] = -Dd[i];
    }

    b_st.site = &bc_emlrtRSI;
    if (12 != loop_ub) {
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

    for (k = 0; k < 12; k++) {
      aoffset = k * 6;
      for (i = 0; i < 6; i++) {
        b_y[i] += u_data[k] * Dd[aoffset + i];
      }
    }

    for (i = 0; i < 6; i++) {
      b_y[i] += fg[i];
    }

    for (i = 0; i < 12; i++) {
      alpha1 = 0.0;
      for (k = 0; k < 6; k++) {
        alpha1 += a[i + 12 * k] * b_y[k];
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
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i0, &e_emlrtRTEI,
    sp);
  for (s = 0; s < i0; s++) {
    st.site = &i_emlrtRSI;
    massF2(b_par->var, z, M, T, Dd, fg);
    for (i = 0; i < 12; i++) {
      for (k = 0; k < 6; k++) {
        aoffset = i + 12 * k;
        a[aoffset] = 0.0;
        alpha1 = 0.0;
        for (i1 = 0; i1 < 6; i1++) {
          alpha1 += T[i1 + 6 * i] * M[i1 + 6 * k];
        }

        a[aoffset] = alpha1;
      }
    }

    st.site = &j_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)12;
    n_t = (ptrdiff_t)12;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)12;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)12;
    TRANSA = 'N';
    TRANSB = 'N';
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &s0, &y[0], &ldc_t);
    for (i = 0; i < 144; i++) {
      TMT[i] += y[i] * ds;
    }

    st.site = &k_emlrtRSI;
    for (i = 0; i < 72; i++) {
      Dd[i] = -Dd[i];
    }

    b_st.site = &bc_emlrtRSI;
    if (12 != loop_ub) {
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

    for (k = 0; k < 12; k++) {
      aoffset = k * 6;
      for (i = 0; i < 6; i++) {
        b_y[i] += u_data[k] * Dd[aoffset + i];
      }
    }

    for (i = 0; i < 6; i++) {
      b_y[i] += fg[i];
    }

    for (i = 0; i < 12; i++) {
      alpha1 = 0.0;
      for (k = 0; k < 6; k++) {
        alpha1 += a[i + 12 * k] * b_y[k];
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
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i0, &d_emlrtRTEI,
    sp);
  for (s = 0; s < i0; s++) {
    st.site = &l_emlrtRSI;
    massF3(b_par->var, z, M, T, Dd, fg);
    for (i = 0; i < 12; i++) {
      for (k = 0; k < 6; k++) {
        aoffset = i + 12 * k;
        a[aoffset] = 0.0;
        alpha1 = 0.0;
        for (i1 = 0; i1 < 6; i1++) {
          alpha1 += T[i1 + 6 * i] * M[i1 + 6 * k];
        }

        a[aoffset] = alpha1;
      }
    }

    st.site = &m_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)12;
    n_t = (ptrdiff_t)12;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)12;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)12;
    TRANSA = 'N';
    TRANSB = 'N';
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &s0, &y[0], &ldc_t);
    for (i = 0; i < 144; i++) {
      TMT[i] += y[i] * ds;
    }

    st.site = &n_emlrtRSI;
    for (i = 0; i < 72; i++) {
      Dd[i] = -Dd[i];
    }

    b_st.site = &bc_emlrtRSI;
    if (12 != loop_ub) {
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

    for (k = 0; k < 12; k++) {
      aoffset = k * 6;
      for (i = 0; i < 6; i++) {
        b_y[i] += u_data[k] * Dd[aoffset + i];
      }
    }

    for (i = 0; i < 6; i++) {
      b_y[i] += fg[i];
    }

    for (i = 0; i < 12; i++) {
      alpha1 = 0.0;
      for (k = 0; k < 6; k++) {
        alpha1 += a[i + 12 * k] * b_y[k];
      }

      TMfd[i] += alpha1 * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  st.site = &o_emlrtRSI;
  loadsF1(b_par->var, z, T, fg);

  /*  EOM */
  for (i = 0; i < 12; i++) {
    alpha1 = 0.0;
    for (i0 = 0; i0 < 6; i0++) {
      alpha1 += T[i + 12 * i0] * fg[i0];
    }

    fj_k[i] = (((TMfd[i] + fj_k[i]) + fj_vd[i]) + fj_in[i]) + alpha1;
  }

  st.site = &p_emlrtRSI;
  mldivide(&st, TMT, fj_k);
  dz_size[0] = u_size_idx_0_tmp + 12;
  if (0 <= u_size_idx_0_tmp - 1) {
    memcpy(&dz_data[0], &u_data[0], (uint32_T)(u_size_idx_0_tmp * (int32_T)
            sizeof(real_T)));
  }

  memcpy(&dz_data[u_size_idx_0_tmp], &fj_k[0], 12U * sizeof(real_T));
}

/* End of code generation (EOM.c) */
