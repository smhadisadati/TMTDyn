/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * int_mid_step.c
 *
 * Code generation for function 'int_mid_step'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "EOM.h"
#include "int_mid_step.h"
#include "sprdmpF7.h"
#include "EOM_data.h"

/* Variable Definitions */
static emlrtRSInfo k_emlrtRSI = { 8,   /* lineNo */
  "int_mid_step",                      /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/int_mid_step.m"/* pathName */
};

static emlrtRTEInfo j_emlrtRTEI = { 7, /* lineNo */
  9,                                   /* colNo */
  "int_mid_step",                      /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/int_mid_step.m"/* pName */
};

static emlrtDCInfo c_emlrtDCI = { 16,  /* lineNo */
  20,                                  /* colNo */
  "int_mid_step",                      /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/int_mid_step.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { 1,   /* iFirst */
  795,                                 /* iLast */
  16,                                  /* lineNo */
  20,                                  /* colNo */
  "par.f_ex",                          /* aName */
  "int_mid_step",                      /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/int_mid_step.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { 1,   /* iFirst */
  7,                                   /* iLast */
  5,                                   /* lineNo */
  6,                                   /* colNo */
  "par.rom.sprdmp",                    /* aName */
  "int_mid_step",                      /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/int_mid_step.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 5,   /* lineNo */
  6,                                   /* colNo */
  "int_mid_step",                      /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/int_mid_step.m",/* pName */
  1                                    /* checkKind */
};

/* Function Definitions */
void int_mid_step(const emlrtStack *sp, real_T t, const real_T z[12], struct0_T *
                  b_par)
{
  real_T l;
  int32_T i4;
  real_T ds;
  int32_T s;
  real_T unusedU0[36];
  real_T unusedU1[6];
  real_T unusedU2[6];
  real_T unusedU3[6];
  real_T dl[3];
  static const int8_T iv5[6] = { 0, 0, 1, 1, 2, 2 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  l = 0.0;
  if (b_par->n_sd != (int32_T)muDoubleScalarFloor(b_par->n_sd)) {
    emlrtIntegerCheckR2012b(b_par->n_sd, &d_emlrtDCI, sp);
  }

  i4 = (int32_T)b_par->n_sd;
  if ((i4 < 1) || (i4 > 7)) {
    emlrtDynamicBoundsCheckR2012b(i4, 1, 7, &e_emlrtBCI, sp);
  }

  ds = b_par->rom.sprdmp[i4 - 1] / b_par->n_int;
  if (b_par->rom.sprdmp[(int32_T)b_par->n_sd - 1] == 0.0) {
    ds = 1.0;
  }

  i4 = (int32_T)(((b_par->rom.sprdmp[(int32_T)b_par->n_sd - 1] - 1.0E-6) + (ds -
    1.0E-6)) / ds);
  emlrtForLoopVectorCheckR2012b(1.0E-6, ds, b_par->rom.sprdmp[(int32_T)
    b_par->n_sd - 1] - 1.0E-6, mxDOUBLE_CLASS, i4, &j_emlrtRTEI, sp);
  for (s = 0; s < i4; s++) {
    st.site = &k_emlrtRSI;
    sprdmpF7(&st, b_par->var, z, 1.0E-6 + (real_T)s * ds, unusedU0, unusedU1,
             unusedU2, unusedU3, dl);

    /*  n_r * 6 + 1 */
    l += dl[2] * ds;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  /*  input p & ext. forces */
  /*  temp = interp1( par.f_ex(:,1) , [ par.f_ex(:,2:7) par.p(:,2:4) ] , t , 'nearest' ) ; */
  ds = muDoubleScalarFloor(t / 0.05);
  i4 = (int32_T)ds;
  if (ds != i4) {
    emlrtIntegerCheckR2012b(ds, &c_emlrtDCI, sp);
  }

  if ((i4 < 1) || (i4 > 795)) {
    emlrtDynamicBoundsCheckR2012b(i4, 1, 795, &d_emlrtBCI, sp);
  }

  ds = b_par->var[4];
  for (s = 0; s < 6; s++) {
    b_par->var[21 + s] = b_par->p[(i4 + 795 * (1 + iv5[s])) - 1];
    b_par->var[s + 27] = b_par->f_ex[(i4 + 795 * (1 + s)) - 1];
  }

  b_par->var[33] = l / ds;
}

/* End of code generation (int_mid_step.c) */
