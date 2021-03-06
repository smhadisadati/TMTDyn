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
#include "sprdmpF7.h"
#include "massF2.h"
#include "massF1.h"
#include "int_mid_step.h"
#include "indexShapeCheck.h"
#include "EOM_eq_data.h"

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

static emlrtRSInfo d_emlrtRSI = { 27,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 34,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 36,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 43,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 49,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 21,  /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pathName */
};

static emlrtDCInfo emlrtDCI = { 7,     /* lineNo */
  8,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM_eq.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo emlrtBCI = { 1,     /* iFirst */
  12,                                  /* iLast */
  7,                                   /* lineNo */
  8,                                   /* colNo */
  "z",                                 /* aName */
  "EOM_eq",                            /* fName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM_eq.m",/* pName */
  0                                    /* checkKind */
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

static emlrtDCInfo b_emlrtDCI = { 8,   /* lineNo */
  13,                                  /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM_eq.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  13,                                  /* colNo */
  "u",                                 /* aName */
  "EOM_eq",                            /* fName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM_eq.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = { 24,  /* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 33,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 42,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 88,/* lineNo */
  23,                                  /* colNo */
  "eml_mtimes_helper",                 /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 83,/* lineNo */
  23,                                  /* colNo */
  "eml_mtimes_helper",                 /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pName */
};

/* Function Definitions */
void EOM_eq(const emlrtStack *sp, const real_T z[6], real_T fval[6])
{
  int32_T i1;
  real_T d0;
  real_T b_z[12];
  int32_T aoffset;
  int32_T i;
  int32_T i2;
  real_T u_data[12];
  int32_T loop_ub;
  int32_T iv0[2];
  real_T uq_data[12];
  b_struct_T par;
  real_T s0;
  real_T TMfd[6];
  real_T ds;
  real_T w_sd[6];
  real_T w_in[6];
  int32_T s;
  real_T M[36];
  real_T T[36];
  real_T Dd[36];
  real_T fg[6];
  int32_T k;
  real_T y[6];
  real_T in[6];
  static const int8_T a[36] = { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2 };

  static const real_T b[36] = { 0.01347, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.01347,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.01347, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.133444375E-6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.133444375E-6, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 3.7884375E-7 };

  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  for (i1 = 0; i1 < 6; i1++) {
    b_z[i1] = z[i1];
    b_z[i1 + 6] = 0.0 * z[i1];
  }

  d0 = (par_i.nq + par_i.nlambda) + 1.0;
  if (d0 > 12.0) {
    i1 = 1;
    aoffset = 1;
  } else {
    if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
      emlrtIntegerCheckR2012b(d0, &emlrtDCI, sp);
    }

    i1 = (int32_T)d0;
    if ((i1 < 1) || (i1 > 12)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, 12, &emlrtBCI, sp);
    }

    aoffset = 13;
  }

  i = aoffset - i1;
  for (i2 = 0; i2 < i; i2++) {
    u_data[i2] = b_z[(i1 + i2) - 1];
  }

  if (1.0 > par_i.nq) {
    loop_ub = 0;
  } else {
    if (1 > i) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i, &b_emlrtBCI, sp);
    }

    if (par_i.nq != (int32_T)muDoubleScalarFloor(par_i.nq)) {
      emlrtIntegerCheckR2012b(par_i.nq, &b_emlrtDCI, sp);
    }

    loop_ub = (int32_T)par_i.nq;
    if ((loop_ub < 1) || (loop_ub > i)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i, &c_emlrtBCI, sp);
    }
  }

  iv0[0] = 1;
  iv0[1] = loop_ub;
  st.site = &emlrtRSI;
  indexShapeCheck(&st, aoffset - i1, iv0);
  if (0 <= loop_ub - 1) {
    memcpy(&uq_data[0], &u_data[0], (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
  }

  par = par_i;
  st.site = &b_emlrtRSI;
  int_mid_step(&st, par_i.t_equil_i, b_z, &par);
  for (i = 0; i < 6; i++) {
    TMfd[i] = 0.0;
    w_sd[i] = 0.0;
    w_in[i] = 0.0;
  }

  s0 = 1.0E-6;
  ds = par.rom.mass[0] / par.n_int;
  if (par.rom.mass[0] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  d0 = par.rom.mass[0] - s0;
  i1 = (int32_T)((d0 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, d0, mxDOUBLE_CLASS, i1, &emlrtRTEI, sp);
  for (s = 0; s < i1; s++) {
    st.site = &c_emlrtRSI;
    massF1(&st, par.var, b_z, M, T, Dd, fg);
    st.site = &d_emlrtRSI;
    for (aoffset = 0; aoffset < 36; aoffset++) {
      Dd[aoffset] = -Dd[aoffset];
    }

    b_st.site = &y_emlrtRSI;
    if (6 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &e_emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &d_emlrtRTEI, "MATLAB:innerdim",
          "MATLAB:innerdim", 0);
      }
    }

    for (i = 0; i < 6; i++) {
      y[i] = 0.0;
    }

    for (k = 0; k < 6; k++) {
      aoffset = k * 6;
      for (i = 0; i < 6; i++) {
        y[i] += u_data[k] * Dd[aoffset + i];
      }
    }

    for (aoffset = 0; aoffset < 6; aoffset++) {
      for (i2 = 0; i2 < 6; i2++) {
        i = aoffset + 6 * i2;
        Dd[i] = 0.0;
        d0 = 0.0;
        for (k = 0; k < 6; k++) {
          d0 += T[k + 6 * aoffset] * M[k + 6 * i2];
        }

        Dd[i] = d0;
      }

      y[aoffset] += fg[aoffset];
    }

    for (aoffset = 0; aoffset < 6; aoffset++) {
      d0 = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        d0 += Dd[aoffset + 6 * i2] * y[i2];
      }

      TMfd[aoffset] += d0 * ds;
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

  d0 = par.rom.mass[1] - s0;
  i1 = (int32_T)((d0 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, d0, mxDOUBLE_CLASS, i1, &b_emlrtRTEI, sp);
  for (s = 0; s < i1; s++) {
    st.site = &e_emlrtRSI;
    massF2(&st, b_z, T, Dd, fg);
    st.site = &f_emlrtRSI;
    for (aoffset = 0; aoffset < 36; aoffset++) {
      Dd[aoffset] = -Dd[aoffset];
    }

    b_st.site = &y_emlrtRSI;
    if (6 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &e_emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &d_emlrtRTEI, "MATLAB:innerdim",
          "MATLAB:innerdim", 0);
      }
    }

    for (i = 0; i < 6; i++) {
      y[i] = 0.0;
    }

    for (k = 0; k < 6; k++) {
      aoffset = k * 6;
      for (i = 0; i < 6; i++) {
        y[i] += u_data[k] * Dd[aoffset + i];
      }
    }

    for (aoffset = 0; aoffset < 6; aoffset++) {
      for (i2 = 0; i2 < 6; i2++) {
        i = aoffset + 6 * i2;
        Dd[i] = 0.0;
        d0 = 0.0;
        for (k = 0; k < 6; k++) {
          d0 += T[k + 6 * aoffset] * b[k + 6 * i2];
        }

        Dd[i] = d0;
      }

      y[aoffset] += fg[aoffset];
    }

    for (aoffset = 0; aoffset < 6; aoffset++) {
      d0 = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        d0 += Dd[aoffset + 6 * i2] * y[i2];
      }

      TMfd[aoffset] += d0 * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.sprdmp[6] / par.n_int;
  if (par.rom.sprdmp[6] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  d0 = par.rom.sprdmp[6] - s0;
  i1 = (int32_T)((d0 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, d0, mxDOUBLE_CLASS, i1, &c_emlrtRTEI, sp);
  for (s = 0; s < i1; s++) {
    st.site = &g_emlrtRSI;
    b_sprdmpF7(&st, par.var, b_z, fg, y, in);
    for (aoffset = 0; aoffset < 6; aoffset++) {
      d0 = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        d0 += (real_T)a[aoffset + 6 * i2] * fg[i2];
      }

      w_sd[aoffset] += d0 * ds;
    }

    for (aoffset = 0; aoffset < 6; aoffset++) {
      d0 = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        d0 += (real_T)a[aoffset + 6 * i2] * in[i2];
      }

      w_in[aoffset] += d0 * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  st.site = &h_emlrtRSI;
  loadsF1(&st, par.var, b_z, M, fg);

  /*  EOM */
  for (i1 = 0; i1 < 6; i1++) {
    d0 = 0.0;
    for (aoffset = 0; aoffset < 6; aoffset++) {
      d0 += M[i1 + 6 * aoffset] * fg[aoffset];
    }

    fval[i1] = ((TMfd[i1] + w_sd[i1]) + w_in[i1]) + d0;
  }
}

/* End of code generation (EOM_eq.c) */
