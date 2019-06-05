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
#include "loadsF1.h"
#include "sprdmpF13.h"
#include "massF2.h"
#include "massF1.h"
#include "int_mid_step.h"
#include "indexShapeCheck.h"
#include "EOM_eq_data.h"
#include "blas.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 8,     /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 10,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 25,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 26,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 27,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 34,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 35,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 36,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 43,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 49,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo nc_emlrtRSI = { 21, /* lineNo */
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

static emlrtRTEInfo c_emlrtRTEI = { 42,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 33,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 24,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM_eq.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  13,                                  /* colNo */
  "u",                                 /* aName */
  "EOM_eq",                            /* fName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM_eq.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo emlrtDCI = { 8,     /* lineNo */
  13,                                  /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM_eq.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  9,                                   /* colNo */
  "u",                                 /* aName */
  "EOM_eq",                            /* fName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM_eq.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { 1,   /* iFirst */
  24,                                  /* iLast */
  7,                                   /* lineNo */
  8,                                   /* colNo */
  "z",                                 /* aName */
  "EOM_eq",                            /* fName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM_eq.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 7,   /* lineNo */
  8,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM_eq.m",/* pName */
  1                                    /* checkKind */
};

/* Function Definitions */
void EOM_eq(const emlrtStack *sp, const real_T z[12], real_T fval[12])
{
  int32_T i0;
  real_T alpha1;
  real_T b_z[24];
  int32_T aoffset;
  int32_T loop_ub_tmp;
  int32_T i1;
  real_T u_data[24];
  int32_T loop_ub;
  int32_T iv0[2];
  real_T uq_data[24];
  b_struct_T par;
  real_T TMfd[12];
  real_T w_sd[12];
  real_T w_in[12];
  real_T s0;
  real_T ds;
  int32_T s;
  real_T M[36];
  real_T T[72];
  real_T Dd[72];
  real_T fg[6];
  real_T a[72];
  int32_T k;
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
  real_T b_y[144];
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  for (i0 = 0; i0 < 12; i0++) {
    b_z[i0] = z[i0];
    b_z[i0 + 12] = 0.0 * z[i0];
  }

  alpha1 = (par_i.nq + par_i.nlambda) + 1.0;
  if (alpha1 > 24.0) {
    i0 = 0;
    aoffset = 0;
  } else {
    if (alpha1 != (int32_T)muDoubleScalarFloor(alpha1)) {
      emlrtIntegerCheckR2012b(alpha1, &b_emlrtDCI, sp);
    }

    i0 = (int32_T)alpha1;
    if ((i0 < 1) || (i0 > 24)) {
      emlrtDynamicBoundsCheckR2012b(i0, 1, 24, &c_emlrtBCI, sp);
    }

    i0--;
    aoffset = 24;
  }

  loop_ub_tmp = aoffset - i0;
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    u_data[i1] = b_z[i0 + i1];
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
  indexShapeCheck(&st, aoffset - i0, iv0);
  if (0 <= loop_ub - 1) {
    memcpy(&uq_data[0], &u_data[0], (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
  }

  par = par_i;
  st.site = &b_emlrtRSI;
  int_mid_step(&st, par_i.t_equil_i, b_z, &par);
  memset(&TMfd[0], 0, 12U * sizeof(real_T));
  memset(&w_sd[0], 0, 12U * sizeof(real_T));
  memset(&w_in[0], 0, 12U * sizeof(real_T));
  s0 = 1.0E-6;
  ds = par.rom.mass[0] / par.n_int;
  if (par.rom.mass[0] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.mass[0] - s0;
  i0 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i0, &e_emlrtRTEI,
    sp);
  for (s = 0; s < i0; s++) {
    st.site = &c_emlrtRSI;
    massF1(&st, par.var, b_z, s0 + (real_T)s * ds, M, T, Dd, fg);
    for (aoffset = 0; aoffset < 12; aoffset++) {
      for (i1 = 0; i1 < 6; i1++) {
        loop_ub_tmp = aoffset + 12 * i1;
        a[loop_ub_tmp] = 0.0;
        alpha1 = 0.0;
        for (k = 0; k < 6; k++) {
          alpha1 += T[k + 6 * aoffset] * M[k + 6 * i1];
        }

        a[loop_ub_tmp] = alpha1;
      }
    }

    st.site = &d_emlrtRSI;
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)12;
    n_t = (ptrdiff_t)12;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)12;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)12;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &beta1, &b_y[0], &ldc_t);
    st.site = &e_emlrtRSI;
    for (aoffset = 0; aoffset < 72; aoffset++) {
      Dd[aoffset] = -Dd[aoffset];
    }

    b_st.site = &nc_emlrtRSI;
    if (12 != loop_ub) {
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

    for (k = 0; k < 12; k++) {
      aoffset = k * 6;
      for (loop_ub_tmp = 0; loop_ub_tmp < 6; loop_ub_tmp++) {
        y[loop_ub_tmp] += u_data[k] * Dd[aoffset + loop_ub_tmp];
      }
    }

    for (aoffset = 0; aoffset < 6; aoffset++) {
      y[aoffset] += fg[aoffset];
    }

    for (aoffset = 0; aoffset < 12; aoffset++) {
      alpha1 = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        alpha1 += a[aoffset + 12 * i1] * y[i1];
      }

      TMfd[aoffset] += alpha1 * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.mass[1] / par.n_int;
  if (par.rom.mass[1] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.mass[1] - s0;
  i0 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i0, &d_emlrtRTEI,
    sp);
  for (s = 0; s < i0; s++) {
    st.site = &f_emlrtRSI;
    massF2(&st, par.var, b_z, M, T, Dd, fg);
    for (aoffset = 0; aoffset < 12; aoffset++) {
      for (i1 = 0; i1 < 6; i1++) {
        loop_ub_tmp = aoffset + 12 * i1;
        a[loop_ub_tmp] = 0.0;
        alpha1 = 0.0;
        for (k = 0; k < 6; k++) {
          alpha1 += T[k + 6 * aoffset] * M[k + 6 * i1];
        }

        a[loop_ub_tmp] = alpha1;
      }
    }

    st.site = &g_emlrtRSI;
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)12;
    n_t = (ptrdiff_t)12;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)12;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)12;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &beta1, &b_y[0], &ldc_t);
    st.site = &h_emlrtRSI;
    for (aoffset = 0; aoffset < 72; aoffset++) {
      Dd[aoffset] = -Dd[aoffset];
    }

    b_st.site = &nc_emlrtRSI;
    if (12 != loop_ub) {
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

    for (k = 0; k < 12; k++) {
      aoffset = k * 6;
      for (loop_ub_tmp = 0; loop_ub_tmp < 6; loop_ub_tmp++) {
        y[loop_ub_tmp] += u_data[k] * Dd[aoffset + loop_ub_tmp];
      }
    }

    for (aoffset = 0; aoffset < 6; aoffset++) {
      y[aoffset] += fg[aoffset];
    }

    for (aoffset = 0; aoffset < 12; aoffset++) {
      alpha1 = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        alpha1 += a[aoffset + 12 * i1] * y[i1];
      }

      TMfd[aoffset] += alpha1 * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.sprdmp[12] / par.n_int;
  if (par.rom.sprdmp[12] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.sprdmp[12] - s0;
  i0 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i0, &c_emlrtRTEI,
    sp);
  for (s = 0; s < i0; s++) {
    st.site = &i_emlrtRSI;
    b_sprdmpF13(&st, par.var, b_z, s0 + (real_T)s * ds, T, fg, y, in);
    for (aoffset = 0; aoffset < 12; aoffset++) {
      alpha1 = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        alpha1 += T[aoffset + 12 * i1] * fg[i1];
      }

      w_sd[aoffset] += alpha1 * ds;
    }

    for (aoffset = 0; aoffset < 12; aoffset++) {
      alpha1 = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        alpha1 += T[aoffset + 12 * i1] * in[i1];
      }

      w_in[aoffset] += alpha1 * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  st.site = &j_emlrtRSI;
  loadsF1(&st, par.var, b_z, T, fg);

  /*  EOM */
  for (i0 = 0; i0 < 12; i0++) {
    alpha1 = 0.0;
    for (aoffset = 0; aoffset < 6; aoffset++) {
      alpha1 += T[i0 + 12 * aoffset] * fg[aoffset];
    }

    fval[i0] = ((TMfd[i0] + w_sd[i0]) + w_in[i0]) + alpha1;
  }
}

/* End of code generation (EOM_eq.c) */
