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
#include "sprdmpF25.h"
#include "EOM_mexutil.h"
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
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM.m"/* pName */
};

static emlrtRSInfo emlrtRSI = { 10,    /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 12,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 27,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 28,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 29,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 36,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 37,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 38,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 45,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 51,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 57,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM.m"/* pathName */
};

static emlrtRSInfo pc_emlrtRSI = { 21, /* lineNo */
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

static emlrtRTEInfo d_emlrtRTEI = { 44,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 35,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 26,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  10,                                  /* lineNo */
  13,                                  /* colNo */
  "u",                                 /* aName */
  "EOM",                               /* fName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo emlrtDCI = { 10,    /* lineNo */
  13,                                  /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  10,                                  /* lineNo */
  9,                                   /* colNo */
  "u",                                 /* aName */
  "EOM",                               /* fName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { 1,   /* iFirst */
  48,                                  /* iLast */
  9,                                   /* lineNo */
  8,                                   /* colNo */
  "z",                                 /* aName */
  "EOM",                               /* fName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 9,   /* lineNo */
  8,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM.m",/* pName */
  1                                    /* checkKind */
};

/* Function Definitions */
void EOM(const emlrtStack *sp, real_T t, const real_T z[48], const struct0_T
         *b_par, real_T dz_data[], int32_T dz_size[1])
{
  real_T alpha1;
  int32_T i0;
  int32_T i;
  int32_T u_size_idx_0_tmp;
  int32_T k;
  real_T u_data[48];
  int32_T loop_ub;
  int32_T iv0[2];
  real_T uq_data[48];
  struct0_T c_par;
  real_T TMT[576];
  real_T TMfd[24];
  real_T w_vd_j[24];
  real_T w_sd[24];
  real_T w_in[24];
  real_T s0;
  real_T ds;
  int32_T s;
  real_T M[36];
  real_T T[144];
  real_T Dd[144];
  real_T fg[6];
  real_T a_tmp[144];
  real_T beta1;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  char_T TRANSA;
  real_T y[6];
  real_T in[6];
  char_T TRANSB;
  real_T a[144];
  real_T b_y[576];
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
  if (alpha1 > 48.0) {
    i0 = 0;
    i = 0;
  } else {
    if (alpha1 != (int32_T)muDoubleScalarFloor(alpha1)) {
      emlrtIntegerCheckR2012b(alpha1, &b_emlrtDCI, sp);
    }

    i0 = (int32_T)alpha1;
    if ((i0 < 1) || (i0 > 48)) {
      emlrtDynamicBoundsCheckR2012b(i0, 1, 48, &c_emlrtBCI, sp);
    }

    i0--;
    i = 48;
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

  c_par = *b_par;
  st.site = &b_emlrtRSI;
  int_mid_step(&st, t, z, &c_par);
  memset(&TMT[0], 0, 576U * sizeof(real_T));
  memset(&TMfd[0], 0, 24U * sizeof(real_T));
  memset(&w_vd_j[0], 0, 24U * sizeof(real_T));
  memset(&w_sd[0], 0, 24U * sizeof(real_T));
  memset(&w_in[0], 0, 24U * sizeof(real_T));
  s0 = 1.0E-6;
  ds = c_par.rom.mass[0] / c_par.n_int;
  if (c_par.rom.mass[0] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = c_par.rom.mass[0] - s0;
  i0 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i0, &f_emlrtRTEI,
    sp);
  for (s = 0; s < i0; s++) {
    st.site = &c_emlrtRSI;
    massF1(&st, c_par.var, z, s0 + (real_T)s * ds, M, T, Dd, fg);
    st.site = &d_emlrtRSI;
    for (i = 0; i < 6; i++) {
      for (k = 0; k < 24; k++) {
        a_tmp[k + 24 * i] = T[i + 6 * k];
      }
    }

    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)24;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)24;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)24;
    TRANSA = 'N';
    TRANSB = 'N';
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &M[0],
          &ldb_t, &beta1, &a[0], &ldc_t);
    st.site = &d_emlrtRSI;
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)24;
    n_t = (ptrdiff_t)24;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)24;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)24;
    TRANSA = 'N';
    TRANSB = 'N';
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &beta1, &b_y[0], &ldc_t);
    for (i = 0; i < 576; i++) {
      TMT[i] += b_y[i] * ds;
    }

    st.site = &e_emlrtRSI;
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)24;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)24;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)24;
    TRANSA = 'N';
    TRANSB = 'N';
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &M[0],
          &ldb_t, &beta1, &T[0], &ldc_t);
    st.site = &e_emlrtRSI;
    for (i = 0; i < 144; i++) {
      Dd[i] = -Dd[i];
    }

    b_st.site = &pc_emlrtRSI;
    if (24 != loop_ub) {
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
      y[i] = 0.0;
    }

    for (k = 0; k < 24; k++) {
      aoffset = k * 6;
      for (i = 0; i < 6; i++) {
        y[i] += u_data[k] * Dd[aoffset + i];
      }
    }

    for (i = 0; i < 6; i++) {
      y[i] += fg[i];
    }

    for (i = 0; i < 24; i++) {
      alpha1 = 0.0;
      for (k = 0; k < 6; k++) {
        alpha1 += T[i + 24 * k] * y[k];
      }

      TMfd[i] += alpha1 * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = c_par.rom.mass[1] / c_par.n_int;
  if (c_par.rom.mass[1] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = c_par.rom.mass[1] - s0;
  i0 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i0, &e_emlrtRTEI,
    sp);
  for (s = 0; s < i0; s++) {
    st.site = &f_emlrtRSI;
    massF2(&st, c_par.var, z, M, T, Dd, fg);
    st.site = &g_emlrtRSI;
    for (i = 0; i < 6; i++) {
      for (k = 0; k < 24; k++) {
        a_tmp[k + 24 * i] = T[i + 6 * k];
      }
    }

    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)24;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)24;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)24;
    TRANSA = 'N';
    TRANSB = 'N';
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &M[0],
          &ldb_t, &beta1, &a[0], &ldc_t);
    st.site = &g_emlrtRSI;
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)24;
    n_t = (ptrdiff_t)24;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)24;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)24;
    TRANSA = 'N';
    TRANSB = 'N';
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &beta1, &b_y[0], &ldc_t);
    for (i = 0; i < 576; i++) {
      TMT[i] += b_y[i] * ds;
    }

    st.site = &h_emlrtRSI;
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)24;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)24;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)24;
    TRANSA = 'N';
    TRANSB = 'N';
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &M[0],
          &ldb_t, &beta1, &T[0], &ldc_t);
    st.site = &h_emlrtRSI;
    for (i = 0; i < 144; i++) {
      Dd[i] = -Dd[i];
    }

    b_st.site = &pc_emlrtRSI;
    if (24 != loop_ub) {
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
      y[i] = 0.0;
    }

    for (k = 0; k < 24; k++) {
      aoffset = k * 6;
      for (i = 0; i < 6; i++) {
        y[i] += u_data[k] * Dd[aoffset + i];
      }
    }

    for (i = 0; i < 6; i++) {
      y[i] += fg[i];
    }

    for (i = 0; i < 24; i++) {
      alpha1 = 0.0;
      for (k = 0; k < 6; k++) {
        alpha1 += T[i + 24 * k] * y[k];
      }

      TMfd[i] += alpha1 * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = c_par.rom.sprdmp[24] / c_par.n_int;
  if (c_par.rom.sprdmp[24] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = c_par.rom.sprdmp[24] - s0;
  i0 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i0, &d_emlrtRTEI,
    sp);
  for (s = 0; s < i0; s++) {
    st.site = &i_emlrtRSI;
    b_sprdmpF25(&st, c_par.var, z, s0 + (real_T)s * ds, T, fg, y, in);
    for (i = 0; i < 24; i++) {
      alpha1 = 0.0;
      for (k = 0; k < 6; k++) {
        alpha1 += T[i + 24 * k] * y[k];
      }

      w_vd_j[i] += alpha1 * ds;
    }

    for (i = 0; i < 24; i++) {
      alpha1 = 0.0;
      for (k = 0; k < 6; k++) {
        alpha1 += T[i + 24 * k] * fg[k];
      }

      w_sd[i] += alpha1 * ds;
    }

    for (i = 0; i < 24; i++) {
      alpha1 = 0.0;
      for (k = 0; k < 6; k++) {
        alpha1 += T[i + 24 * k] * in[k];
      }

      w_in[i] += alpha1 * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  st.site = &j_emlrtRSI;
  loadsF1(&st, c_par.var, z, T, fg);

  /*  EOM */
  for (i = 0; i < 24; i++) {
    alpha1 = 0.0;
    for (i0 = 0; i0 < 6; i0++) {
      alpha1 += T[i + 24 * i0] * fg[i0];
    }

    TMfd[i] = (((TMfd[i] + w_sd[i]) + w_in[i]) + w_vd_j[i]) + alpha1;
  }

  st.site = &k_emlrtRSI;
  mldivide(&st, TMT, TMfd);
  dz_size[0] = u_size_idx_0_tmp + 24;
  if (0 <= u_size_idx_0_tmp - 1) {
    memcpy(&dz_data[0], &u_data[0], (uint32_T)(u_size_idx_0_tmp * (int32_T)
            sizeof(real_T)));
  }

  memcpy(&dz_data[u_size_idx_0_tmp], &TMfd[0], 24U * sizeof(real_T));
}

/* End of code generation (EOM.c) */
