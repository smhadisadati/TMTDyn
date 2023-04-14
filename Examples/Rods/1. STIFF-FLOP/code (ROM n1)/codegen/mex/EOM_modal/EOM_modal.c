/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EOM_modal.c
 *
 * Code generation for function 'EOM_modal'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "EOM_modal.h"
#include "sprdmpF7.h"
#include "massF2.h"
#include "massF1.h"
#include "EOM_modal_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 4,     /* lineNo */
  "EOM_modal",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM_modal.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 15,  /* lineNo */
  "EOM_modal",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM_modal.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 22,  /* lineNo */
  "EOM_modal",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM_modal.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 29,  /* lineNo */
  "EOM_modal",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM_modal.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 8,   /* lineNo */
  "int_mid_step",                      /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/int_mid_step.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 14,  /* lineNo */
  9,                                   /* colNo */
  "EOM_modal",                         /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM_modal.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 21,/* lineNo */
  9,                                   /* colNo */
  "EOM_modal",                         /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM_modal.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 28,/* lineNo */
  9,                                   /* colNo */
  "EOM_modal",                         /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/EOM_modal.m"/* pName */
};

static emlrtDCInfo emlrtDCI = { 7,     /* lineNo */
  34,                                  /* colNo */
  "int_mid_step",                      /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/int_mid_step.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo emlrtBCI = { 1,     /* iFirst */
  7,                                   /* iLast */
  7,                                   /* lineNo */
  34,                                  /* colNo */
  "par.rom.sprdmp",                    /* aName */
  "int_mid_step",                      /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/int_mid_step.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo d_emlrtRTEI = { 7, /* lineNo */
  9,                                   /* colNo */
  "int_mid_step",                      /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/int_mid_step.m"/* pName */
};

static emlrtDCInfo b_emlrtDCI = { 16,  /* lineNo */
  20,                                  /* colNo */
  "int_mid_step",                      /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/int_mid_step.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { 1,   /* iFirst */
  1094,                                /* iLast */
  16,                                  /* lineNo */
  20,                                  /* colNo */
  "par.f_ex",                          /* aName */
  "int_mid_step",                      /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/int_mid_step.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { 1,   /* iFirst */
  7,                                   /* iLast */
  5,                                   /* lineNo */
  6,                                   /* colNo */
  "par.rom.sprdmp",                    /* aName */
  "int_mid_step",                      /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/int_mid_step.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 5,   /* lineNo */
  6,                                   /* colNo */
  "int_mid_step",                      /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/int_mid_step.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { 1,   /* iFirst */
  7,                                   /* iLast */
  6,                                   /* lineNo */
  4,                                   /* colNo */
  "par.rom.sprdmp",                    /* aName */
  "int_mid_step",                      /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/int_mid_step.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 6,   /* lineNo */
  4,                                   /* colNo */
  "int_mid_step",                      /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/int_mid_step.m",/* pName */
  1                                    /* checkKind */
};

/* Function Definitions */
void EOM_modal(const emlrtStack *sp, const real_T z[6], struct0_T *par, real_T
               TMT[36], real_T TKT[36], real_T TVT[36])
{
  int32_T i0;
  real_T b_z[12];
  real_T l;
  real_T step;
  real_T ds;
  int32_T s;
  real_T unusedU0[36];
  real_T unusedU1[6];
  real_T unusedU2[6];
  real_T unusedU3[6];
  real_T dl[3];
  int32_T i1;
  static const int8_T iv0[6] = { 0, 0, 1, 1, 2, 2 };

  real_T T[36];
  int32_T i2;
  real_T b_T[36];
  int32_T T_tmp;
  real_T c_T[36];
  int32_T i3;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  for (i0 = 0; i0 < 6; i0++) {
    b_z[i0] = z[i0];
    b_z[i0 + 6] = 0.0 * z[i0];
  }

  st.site = &emlrtRSI;
  l = 0.0;
  step = (int32_T)muDoubleScalarFloor(par->n_sd);
  if (par->n_sd != step) {
    emlrtIntegerCheckR2012b(par->n_sd, &c_emlrtDCI, &st);
  }

  i0 = (int32_T)par->n_sd;
  if ((i0 < 1) || (i0 > 7)) {
    emlrtDynamicBoundsCheckR2012b(i0, 1, 7, &c_emlrtBCI, &st);
  }

  ds = par->rom.sprdmp[i0 - 1] / par->n_int;
  if (par->n_sd != step) {
    emlrtIntegerCheckR2012b(par->n_sd, &d_emlrtDCI, &st);
  }

  if ((i0 < 1) || (i0 > 7)) {
    emlrtDynamicBoundsCheckR2012b(i0, 1, 7, &d_emlrtBCI, &st);
  }

  if (par->rom.sprdmp[i0 - 1] == 0.0) {
    ds = 1.0;
  }

  if (par->n_sd != step) {
    emlrtIntegerCheckR2012b(par->n_sd, &emlrtDCI, &st);
  }

  if ((i0 < 1) || (i0 > 7)) {
    emlrtDynamicBoundsCheckR2012b(i0, 1, 7, &emlrtBCI, &st);
  }

  i0 = (int32_T)(((par->rom.sprdmp[(int32_T)par->n_sd - 1] - 1.0E-6) + (ds -
    1.0E-6)) / ds);
  emlrtForLoopVectorCheckR2012b(1.0E-6, ds, par->rom.sprdmp[(int32_T)par->n_sd -
    1] - 1.0E-6, mxDOUBLE_CLASS, i0, &d_emlrtRTEI, &st);
  for (s = 0; s < i0; s++) {
    b_st.site = &e_emlrtRSI;
    sprdmpF7(&b_st, par->var, b_z, 1.0E-6 + (real_T)s * ds, unusedU0, unusedU1,
             unusedU2, unusedU3, dl);

    /*  n_r * 6 + 1 */
    l += dl[2] * ds;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /*  input p & ext. forces */
  /*  temp = interp1( par.f_ex(:,1) , [ par.f_ex(:,2:7) par.p(:,2:4) ] , t , 'nearest' ) ; */
  step = muDoubleScalarFloor(par->t_equil_i / 0.05);
  i0 = (int32_T)step;
  if (step != i0) {
    emlrtIntegerCheckR2012b(step, &b_emlrtDCI, &st);
  }

  if ((i0 < 1) || (i0 > 1094)) {
    emlrtDynamicBoundsCheckR2012b(i0, 1, 1094, &b_emlrtBCI, &st);
  }

  step = par->var[4];
  for (i1 = 0; i1 < 6; i1++) {
    par->var[21 + i1] = par->p[(i0 + 1094 * (1 + iv0[i1])) - 1];
    par->var[i1 + 27] = par->f_ex[(i0 + 1094 * (1 + i1)) - 1];
  }

  par->var[33] = l / step;
  memset(&TKT[0], 0, 36U * sizeof(real_T));
  memset(&TVT[0], 0, 36U * sizeof(real_T));
  memset(&TMT[0], 0, 36U * sizeof(real_T));
  ds = par->rom.mass[0] / par->n_int;
  if (par->rom.mass[0] == 0.0) {
    ds = 1.0;
  }

  i0 = (int32_T)(((par->rom.mass[0] - 1.0E-6) + (ds - 1.0E-6)) / ds);
  emlrtForLoopVectorCheckR2012b(1.0E-6, ds, par->rom.mass[0] - 1.0E-6,
    mxDOUBLE_CLASS, i0, &emlrtRTEI, sp);
  for (s = 0; s < i0; s++) {
    st.site = &b_emlrtRSI;
    massF1(&st, par->var, b_z, 1.0E-6 + (real_T)s * ds, unusedU0, T);
    for (i1 = 0; i1 < 6; i1++) {
      for (i2 = 0; i2 < 6; i2++) {
        T_tmp = i1 + 6 * i2;
        c_T[T_tmp] = 0.0;
        step = 0.0;
        for (i3 = 0; i3 < 6; i3++) {
          step += T[i3 + 6 * i1] * unusedU0[i3 + 6 * i2];
        }

        c_T[T_tmp] = step;
      }

      for (i2 = 0; i2 < 6; i2++) {
        T_tmp = i1 + 6 * i2;
        b_T[T_tmp] = 0.0;
        step = 0.0;
        for (i3 = 0; i3 < 6; i3++) {
          step += c_T[i1 + 6 * i3] * T[i3 + 6 * i2];
        }

        b_T[T_tmp] = step;
      }
    }

    for (i1 = 0; i1 < 36; i1++) {
      TMT[i1] += b_T[i1] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  ds = par->rom.mass[1] / par->n_int;
  if (par->rom.mass[1] == 0.0) {
    ds = 1.0;
  }

  i0 = (int32_T)(((par->rom.mass[1] - 1.0E-6) + (ds - 1.0E-6)) / ds);
  emlrtForLoopVectorCheckR2012b(1.0E-6, ds, par->rom.mass[1] - 1.0E-6,
    mxDOUBLE_CLASS, i0, &b_emlrtRTEI, sp);
  for (s = 0; s < i0; s++) {
    st.site = &c_emlrtRSI;
    massF2(&st, par->var, b_z, unusedU0, T);
    for (i1 = 0; i1 < 6; i1++) {
      for (i2 = 0; i2 < 6; i2++) {
        T_tmp = i1 + 6 * i2;
        c_T[T_tmp] = 0.0;
        step = 0.0;
        for (i3 = 0; i3 < 6; i3++) {
          step += T[i3 + 6 * i1] * unusedU0[i3 + 6 * i2];
        }

        c_T[T_tmp] = step;
      }

      for (i2 = 0; i2 < 6; i2++) {
        T_tmp = i1 + 6 * i2;
        b_T[T_tmp] = 0.0;
        step = 0.0;
        for (i3 = 0; i3 < 6; i3++) {
          step += c_T[i1 + 6 * i3] * T[i3 + 6 * i2];
        }

        b_T[T_tmp] = step;
      }
    }

    for (i1 = 0; i1 < 36; i1++) {
      TMT[i1] += b_T[i1] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  ds = par->rom.sprdmp[6] / par->n_int;
  if (par->rom.sprdmp[6] == 0.0) {
    ds = 1.0;
  }

  i0 = (int32_T)(((par->rom.sprdmp[6] - 1.0E-6) + (ds - 1.0E-6)) / ds);
  emlrtForLoopVectorCheckR2012b(1.0E-6, ds, par->rom.sprdmp[6] - 1.0E-6,
    mxDOUBLE_CLASS, i0, &c_emlrtRTEI, sp);
  for (s = 0; s < i0; s++) {
    st.site = &d_emlrtRSI;
    b_sprdmpF7(&st, par->var, b_z, 1.0E-6 + (real_T)s * ds, unusedU0, unusedU3,
               unusedU1, unusedU2, dl, T, b_T);
    for (i1 = 0; i1 < 6; i1++) {
      for (i2 = 0; i2 < 6; i2++) {
        T_tmp = i1 + 6 * i2;
        c_T[T_tmp] = 0.0;
        step = 0.0;
        for (i3 = 0; i3 < 6; i3++) {
          step += unusedU0[i1 + 6 * i3] * T[i3 + 6 * i2];
        }

        c_T[T_tmp] = step;
      }
    }

    for (i1 = 0; i1 < 36; i1++) {
      TKT[i1] += c_T[i1] * ds;
    }

    for (i1 = 0; i1 < 6; i1++) {
      for (i2 = 0; i2 < 6; i2++) {
        T_tmp = i1 + 6 * i2;
        c_T[T_tmp] = 0.0;
        step = 0.0;
        for (i3 = 0; i3 < 6; i3++) {
          step += unusedU0[i1 + 6 * i3] * b_T[i3 + 6 * i2];
        }

        c_T[T_tmp] = step;
      }
    }

    for (i1 = 0; i1 < 36; i1++) {
      TVT[i1] += c_T[i1] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }
}

/* End of code generation (EOM_modal.c) */
