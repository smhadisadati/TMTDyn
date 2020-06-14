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
#include "mldivide.h"
#include "loadsF1.h"
#include "fj_inF.h"
#include "int_mid_step.h"
#include "indexShapeCheck.h"
#include "EOM_mexutil.h"
#include "EOM_data.h"

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

static emlrtRSInfo g_emlrtRSI = { 28,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 35,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 37,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 46,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pathName */
};

static emlrtRSInfo rb_emlrtRSI = { 21, /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pathName */
};

static emlrtDCInfo emlrtDCI = { 8,     /* lineNo */
  8,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo emlrtBCI = { 1,     /* iFirst */
  12,                                  /* iLast */
  8,                                   /* lineNo */
  8,                                   /* colNo */
  "z",                                 /* aName */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m",/* pName */
  0                                    /* checkKind */
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

static emlrtDCInfo b_emlrtDCI = { 9,   /* lineNo */
  13,                                  /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  9,                                   /* lineNo */
  13,                                  /* colNo */
  "u",                                 /* aName */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = { 25,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 34,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM.m"/* pName */
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
void EOM(const emlrtStack *sp, real_T t, const real_T z[12], struct0_T *b_par,
         real_T dz_data[], int32_T dz_size[1])
{
  real_T d0;
  int32_T i0;
  int32_T k;
  int32_T u_size_idx_0_tmp;
  int32_T aoffset;
  real_T u_data[12];
  int32_T loop_ub;
  int32_T iv0[2];
  real_T uq_data[12];
  real_T fj_k[6];
  real_T fj_vd[6];
  real_T fj_in[6];
  real_T TMT[36];
  int32_T i;
  real_T s0;
  real_T TMfd[6];
  real_T ds;
  int32_T s;
  real_T M[36];
  real_T T[36];
  real_T Dd[36];
  real_T dzt[6];
  real_T TMT_tmp[36];
  int32_T i1;
  real_T y[6];
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

  d0 = (b_par->nq + b_par->nlambda) + 1.0;
  if (d0 > 12.0) {
    i0 = 1;
    k = 1;
  } else {
    if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
      emlrtIntegerCheckR2012b(d0, &emlrtDCI, sp);
    }

    i0 = (int32_T)d0;
    if ((i0 < 1) || (i0 > 12)) {
      emlrtDynamicBoundsCheckR2012b(i0, 1, 12, &emlrtBCI, sp);
    }

    k = 13;
  }

  u_size_idx_0_tmp = k - i0;
  for (aoffset = 0; aoffset < u_size_idx_0_tmp; aoffset++) {
    u_data[aoffset] = z[(i0 + aoffset) - 1];
  }

  if (1.0 > b_par->nq) {
    loop_ub = 0;
  } else {
    if (1 > u_size_idx_0_tmp) {
      emlrtDynamicBoundsCheckR2012b(1, 1, u_size_idx_0_tmp, &b_emlrtBCI, sp);
    }

    if (b_par->nq != (int32_T)muDoubleScalarFloor(b_par->nq)) {
      emlrtIntegerCheckR2012b(b_par->nq, &b_emlrtDCI, sp);
    }

    loop_ub = (int32_T)b_par->nq;
    if ((loop_ub < 1) || (loop_ub > u_size_idx_0_tmp)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, u_size_idx_0_tmp, &c_emlrtBCI,
        sp);
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
  int_mid_step(&st, t, b_par);
  st.site = &c_emlrtRSI;
  fj_kF(b_par->var, z, fj_k);
  st.site = &d_emlrtRSI;
  fj_vdF(b_par->var, z, fj_vd);
  st.site = &e_emlrtRSI;
  fj_inF(&st, b_par->var, fj_in);
  memset(&TMT[0], 0, 36U * sizeof(real_T));
  for (i = 0; i < 6; i++) {
    TMfd[i] = 0.0;
  }

  s0 = 1.0E-6;
  ds = b_par->rom.mass[0] / b_par->n_int;
  if (b_par->rom.mass[0] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  d0 = b_par->rom.mass[0] - s0;
  i0 = (int32_T)((d0 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, d0, mxDOUBLE_CLASS, i0, &b_emlrtRTEI, sp);
  for (s = 0; s < i0; s++) {
    st.site = &f_emlrtRSI;
    massF1(b_par->var, z, M, T, Dd, dzt);
    for (k = 0; k < 6; k++) {
      for (aoffset = 0; aoffset < 6; aoffset++) {
        i = k + 6 * aoffset;
        TMT_tmp[i] = 0.0;
        d0 = 0.0;
        for (i1 = 0; i1 < 6; i1++) {
          d0 += T[i1 + 6 * k] * M[i1 + 6 * aoffset];
        }

        TMT_tmp[i] = d0;
      }
    }

    for (k = 0; k < 6; k++) {
      for (aoffset = 0; aoffset < 6; aoffset++) {
        i = k + 6 * aoffset;
        M[i] = 0.0;
        d0 = 0.0;
        for (i1 = 0; i1 < 6; i1++) {
          d0 += TMT_tmp[k + 6 * i1] * T[i1 + 6 * aoffset];
        }

        M[i] = d0;
      }
    }

    for (k = 0; k < 36; k++) {
      TMT[k] += M[k] * ds;
    }

    st.site = &g_emlrtRSI;
    for (k = 0; k < 36; k++) {
      Dd[k] = -Dd[k];
    }

    b_st.site = &rb_emlrtRSI;
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

    for (k = 0; k < 6; k++) {
      y[k] += dzt[k];
    }

    for (k = 0; k < 6; k++) {
      d0 = 0.0;
      for (aoffset = 0; aoffset < 6; aoffset++) {
        d0 += TMT_tmp[k + 6 * aoffset] * y[aoffset];
      }

      TMfd[k] += d0 * ds;
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

  d0 = b_par->rom.mass[1] - s0;
  i0 = (int32_T)((d0 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, d0, mxDOUBLE_CLASS, i0, &c_emlrtRTEI, sp);
  for (s = 0; s < i0; s++) {
    st.site = &h_emlrtRSI;
    massF2(b_par->var, z, M, T, Dd, dzt);
    for (k = 0; k < 6; k++) {
      for (aoffset = 0; aoffset < 6; aoffset++) {
        i = k + 6 * aoffset;
        TMT_tmp[i] = 0.0;
        d0 = 0.0;
        for (i1 = 0; i1 < 6; i1++) {
          d0 += T[i1 + 6 * k] * M[i1 + 6 * aoffset];
        }

        TMT_tmp[i] = d0;
      }
    }

    for (k = 0; k < 6; k++) {
      for (aoffset = 0; aoffset < 6; aoffset++) {
        i = k + 6 * aoffset;
        M[i] = 0.0;
        d0 = 0.0;
        for (i1 = 0; i1 < 6; i1++) {
          d0 += TMT_tmp[k + 6 * i1] * T[i1 + 6 * aoffset];
        }

        M[i] = d0;
      }
    }

    for (k = 0; k < 36; k++) {
      TMT[k] += M[k] * ds;
    }

    st.site = &i_emlrtRSI;
    for (k = 0; k < 36; k++) {
      Dd[k] = -Dd[k];
    }

    b_st.site = &rb_emlrtRSI;
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

    for (k = 0; k < 6; k++) {
      y[k] += dzt[k];
    }

    for (k = 0; k < 6; k++) {
      d0 = 0.0;
      for (aoffset = 0; aoffset < 6; aoffset++) {
        d0 += TMT_tmp[k + 6 * aoffset] * y[aoffset];
      }

      TMfd[k] += d0 * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  loadsF1(b_par->var, z, M, dzt);

  /*  EOM */
  for (i0 = 0; i0 < 6; i0++) {
    d0 = 0.0;
    for (k = 0; k < 6; k++) {
      d0 += M[i0 + 6 * k] * dzt[k];
    }

    y[i0] = (((TMfd[i0] + fj_k[i0]) + fj_vd[i0]) + fj_in[i0]) + d0;
  }

  for (i = 0; i < 6; i++) {
    dzt[i] = y[i];
  }

  st.site = &j_emlrtRSI;
  mldivide(&st, TMT, dzt);
  dz_size[0] = u_size_idx_0_tmp + 6;
  if (0 <= u_size_idx_0_tmp - 1) {
    memcpy(&dz_data[0], &u_data[0], (uint32_T)(u_size_idx_0_tmp * (int32_T)
            sizeof(real_T)));
  }

  for (i0 = 0; i0 < 6; i0++) {
    dz_data[i0 + u_size_idx_0_tmp] = dzt[i0];
  }
}

/* End of code generation (EOM.c) */
