/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EOM_eq.c
 *
 * Code generation for function 'EOM_eq'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "EOM_eq.h"
#include "mldivide.h"
#include "loadsF1.h"
#include "sprdmpF19.h"
#include "EOM_eq_mexutil.h"
#include "massF2.h"
#include "massF1.h"
#include "int_mid_step.h"
#include "indexShapeCheck.h"
#include "EOM_eq_data.h"
#include "blas.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 7,     /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 9,   /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 24,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 25,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 26,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 32,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 33,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 34,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 40,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 46,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 52,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo mc_emlrtRSI = { 21, /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 83,  /* lineNo */
  23,                                  /* colNo */
  "eml_mtimes_helper",                 /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 88,/* lineNo */
  23,                                  /* colNo */
  "eml_mtimes_helper",                 /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 39,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 31,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 23,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM_eq.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  7,                                   /* lineNo */
  13,                                  /* colNo */
  "u",                                 /* aName */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM_eq.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo emlrtDCI = { 7,     /* lineNo */
  13,                                  /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM_eq.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  7,                                   /* lineNo */
  9,                                   /* colNo */
  "u",                                 /* aName */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM_eq.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { 1,   /* iFirst */
  36,                                  /* iLast */
  6,                                   /* lineNo */
  8,                                   /* colNo */
  "z",                                 /* aName */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM_eq.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 6,   /* lineNo */
  8,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM_eq.m",/* pName */
  1                                    /* checkKind */
};

/* Function Definitions */
void EOM_eq(const emlrtStack *sp, const real_T z[18], real_T fval[18])
{
  b_struct_T par;
  int32_T i0;
  real_T alpha1;
  real_T b_z[36];
  int32_T k;
  int32_T loop_ub_tmp;
  int32_T aoffset;
  real_T u_data[36];
  int32_T loop_ub;
  int32_T iv0[2];
  real_T uq_data[36];
  real_T TMT[324];
  real_T TMfd[18];
  real_T w_sd[18];
  real_T w_in[18];
  real_T ds;
  int32_T s;
  real_T T[108];
  real_T Dd[108];
  real_T fg[6];
  real_T a_tmp[108];
  real_T beta1;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t k_t;
  real_T y[6];
  real_T in[6];
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  char_T TRANSA;
  char_T TRANSB;
  real_T a[108];
  real_T b_y[324];
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  par = par_i;
  for (i0 = 0; i0 < 18; i0++) {
    b_z[i0] = z[i0];
    b_z[i0 + 18] = 0.0 * z[i0];
  }

  alpha1 = (par_i.nq + par_i.nlambda) + 1.0;
  if (alpha1 > 36.0) {
    i0 = 0;
    k = 0;
  } else {
    if (alpha1 != (int32_T)muDoubleScalarFloor(alpha1)) {
      emlrtIntegerCheckR2012b(alpha1, &b_emlrtDCI, sp);
    }

    i0 = (int32_T)alpha1;
    if ((i0 < 1) || (i0 > 36)) {
      emlrtDynamicBoundsCheckR2012b(i0, 1, 36, &c_emlrtBCI, sp);
    }

    i0--;
    k = 36;
  }

  loop_ub_tmp = k - i0;
  for (aoffset = 0; aoffset < loop_ub_tmp; aoffset++) {
    u_data[aoffset] = b_z[i0 + aoffset];
  }

  if (1.0 > par_i.nq) {
    loop_ub = 0;
  } else {
    if (1 > loop_ub_tmp) {
      emlrtDynamicBoundsCheckR2012b(1, 1, loop_ub_tmp, &b_emlrtBCI, sp);
    }

    if (par_i.nq != (int32_T)muDoubleScalarFloor(par_i.nq)) {
      emlrtIntegerCheckR2012b(par_i.nq, &emlrtDCI, sp);
    }

    loop_ub = (int32_T)par_i.nq;
    if ((loop_ub < 1) || (loop_ub > loop_ub_tmp)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, loop_ub_tmp, &emlrtBCI, sp);
    }
  }

  iv0[0] = 1;
  iv0[1] = loop_ub;
  st.site = &emlrtRSI;
  indexShapeCheck(&st, k - i0, iv0);
  if (0 <= loop_ub - 1) {
    memcpy(&uq_data[0], &u_data[0], (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
  }

  st.site = &b_emlrtRSI;
  int_mid_step(&st, par.t_equil_i, b_z, &par);
  memset(&TMT[0], 0, 324U * sizeof(real_T));
  memset(&TMfd[0], 0, 18U * sizeof(real_T));
  memset(&w_sd[0], 0, 18U * sizeof(real_T));
  memset(&w_in[0], 0, 18U * sizeof(real_T));
  ds = par.rom.mass[0] / par.n_int;
  if (par.rom.mass[0] == 0.0) {
    ds = 1.0;
  }

  i0 = (int32_T)(((par.rom.mass[0] - 1.0E-6) + (ds - 1.0E-6)) / ds);
  emlrtForLoopVectorCheckR2012b(1.0E-6, ds, par.rom.mass[0] - 1.0E-6,
    mxDOUBLE_CLASS, i0, &e_emlrtRTEI, sp);
  for (s = 0; s < i0; s++) {
    st.site = &c_emlrtRSI;
    massF1(&st, par.var, b_z, 1.0E-6 + (real_T)s * ds, uq_data, T, Dd, fg);
    st.site = &d_emlrtRSI;
    for (k = 0; k < 6; k++) {
      for (aoffset = 0; aoffset < 18; aoffset++) {
        a_tmp[aoffset + 18 * k] = T[k + 6 * aoffset];
      }
    }

    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)18;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)18;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)18;
    TRANSA = 'N';
    TRANSB = 'N';
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t,
          &uq_data[0], &ldb_t, &beta1, &a[0], &ldc_t);
    st.site = &d_emlrtRSI;
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)18;
    n_t = (ptrdiff_t)18;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)18;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)18;
    TRANSA = 'N';
    TRANSB = 'N';
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &beta1, &b_y[0], &ldc_t);
    for (k = 0; k < 324; k++) {
      TMT[k] += b_y[k] * ds;
    }

    st.site = &e_emlrtRSI;
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)18;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)18;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)18;
    TRANSA = 'N';
    TRANSB = 'N';
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t,
          &uq_data[0], &ldb_t, &beta1, &T[0], &ldc_t);
    st.site = &e_emlrtRSI;
    for (k = 0; k < 108; k++) {
      Dd[k] = -Dd[k];
    }

    b_st.site = &mc_emlrtRSI;
    if (18 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI, "MATLAB:innerdim",
          "MATLAB:innerdim", 0);
      }
    }

    for (loop_ub_tmp = 0; loop_ub_tmp < 6; loop_ub_tmp++) {
      y[loop_ub_tmp] = 0.0;
    }

    for (k = 0; k < 18; k++) {
      aoffset = k * 6;
      for (loop_ub_tmp = 0; loop_ub_tmp < 6; loop_ub_tmp++) {
        y[loop_ub_tmp] += u_data[k] * Dd[aoffset + loop_ub_tmp];
      }
    }

    for (k = 0; k < 6; k++) {
      y[k] += fg[k];
    }

    for (k = 0; k < 18; k++) {
      alpha1 = 0.0;
      for (aoffset = 0; aoffset < 6; aoffset++) {
        alpha1 += T[k + 18 * aoffset] * y[aoffset];
      }

      TMfd[k] += alpha1 * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  ds = par.rom.mass[1] / par.n_int;
  if (par.rom.mass[1] == 0.0) {
    ds = 1.0;
  }

  i0 = (int32_T)(((par.rom.mass[1] - 1.0E-6) + (ds - 1.0E-6)) / ds);
  emlrtForLoopVectorCheckR2012b(1.0E-6, ds, par.rom.mass[1] - 1.0E-6,
    mxDOUBLE_CLASS, i0, &d_emlrtRTEI, sp);
  for (s = 0; s < i0; s++) {
    st.site = &f_emlrtRSI;
    massF2(&st, par.var, b_z, uq_data, T, Dd, fg);
    st.site = &g_emlrtRSI;
    for (k = 0; k < 6; k++) {
      for (aoffset = 0; aoffset < 18; aoffset++) {
        a_tmp[aoffset + 18 * k] = T[k + 6 * aoffset];
      }
    }

    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)18;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)18;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)18;
    TRANSA = 'N';
    TRANSB = 'N';
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t,
          &uq_data[0], &ldb_t, &beta1, &a[0], &ldc_t);
    st.site = &g_emlrtRSI;
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)18;
    n_t = (ptrdiff_t)18;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)18;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)18;
    TRANSA = 'N';
    TRANSB = 'N';
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &beta1, &b_y[0], &ldc_t);
    for (k = 0; k < 324; k++) {
      TMT[k] += b_y[k] * ds;
    }

    st.site = &h_emlrtRSI;
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)18;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)18;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)18;
    TRANSA = 'N';
    TRANSB = 'N';
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t,
          &uq_data[0], &ldb_t, &beta1, &T[0], &ldc_t);
    st.site = &h_emlrtRSI;
    for (k = 0; k < 108; k++) {
      Dd[k] = -Dd[k];
    }

    b_st.site = &mc_emlrtRSI;
    if (18 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI, "MATLAB:innerdim",
          "MATLAB:innerdim", 0);
      }
    }

    for (loop_ub_tmp = 0; loop_ub_tmp < 6; loop_ub_tmp++) {
      y[loop_ub_tmp] = 0.0;
    }

    for (k = 0; k < 18; k++) {
      aoffset = k * 6;
      for (loop_ub_tmp = 0; loop_ub_tmp < 6; loop_ub_tmp++) {
        y[loop_ub_tmp] += u_data[k] * Dd[aoffset + loop_ub_tmp];
      }
    }

    for (k = 0; k < 6; k++) {
      y[k] += fg[k];
    }

    for (k = 0; k < 18; k++) {
      alpha1 = 0.0;
      for (aoffset = 0; aoffset < 6; aoffset++) {
        alpha1 += T[k + 18 * aoffset] * y[aoffset];
      }

      TMfd[k] += alpha1 * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  ds = par.rom.sprdmp[18] / par.n_int;
  if (par.rom.sprdmp[18] == 0.0) {
    ds = 1.0;
  }

  i0 = (int32_T)(((par.rom.sprdmp[18] - 1.0E-6) + (ds - 1.0E-6)) / ds);
  emlrtForLoopVectorCheckR2012b(1.0E-6, ds, par.rom.sprdmp[18] - 1.0E-6,
    mxDOUBLE_CLASS, i0, &c_emlrtRTEI, sp);
  for (s = 0; s < i0; s++) {
    st.site = &i_emlrtRSI;
    b_sprdmpF19(&st, par.var, b_z, 1.0E-6 + (real_T)s * ds, T, fg, y, in);
    for (k = 0; k < 18; k++) {
      alpha1 = 0.0;
      for (aoffset = 0; aoffset < 6; aoffset++) {
        alpha1 += T[k + 18 * aoffset] * fg[aoffset];
      }

      w_sd[k] += alpha1 * ds;
    }

    for (k = 0; k < 18; k++) {
      alpha1 = 0.0;
      for (aoffset = 0; aoffset < 6; aoffset++) {
        alpha1 += T[k + 18 * aoffset] * in[aoffset];
      }

      w_in[k] += alpha1 * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  st.site = &j_emlrtRSI;
  loadsF1(&st, par.var, b_z, T, fg);

  /*  EOM */
  for (i0 = 0; i0 < 18; i0++) {
    alpha1 = 0.0;
    for (k = 0; k < 6; k++) {
      alpha1 += T[i0 + 18 * k] * fg[k];
    }

    fval[i0] = ((TMfd[i0] + w_sd[i0]) + w_in[i0]) + alpha1;
  }

  st.site = &k_emlrtRSI;
  mldivide(&st, TMT, fval);
}

/* End of code generation (EOM_eq.c) */
