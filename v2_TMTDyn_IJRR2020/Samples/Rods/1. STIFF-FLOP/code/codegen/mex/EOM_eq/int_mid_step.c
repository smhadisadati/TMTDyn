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
#include "EOM_eq.h"
#include "int_mid_step.h"
#include "sprdmpF13.h"
#include "EOM_eq_data.h"

/* Variable Definitions */
static emlrtRSInfo l_emlrtRSI = { 8,   /* lineNo */
  "int_mid_step",                      /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/int_mid_step.m"/* pathName */
};

static emlrtRTEInfo h_emlrtRTEI = { 7, /* lineNo */
  9,                                   /* colNo */
  "int_mid_step",                      /* fName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/int_mid_step.m"/* pName */
};

static emlrtDCInfo c_emlrtDCI = { 16,  /* lineNo */
  20,                                  /* colNo */
  "int_mid_step",                      /* fName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/int_mid_step.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { 1,   /* iFirst */
  1094,                                /* iLast */
  16,                                  /* lineNo */
  20,                                  /* colNo */
  "par.f_ex",                          /* aName */
  "int_mid_step",                      /* fName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/int_mid_step.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { 1,   /* iFirst */
  13,                                  /* iLast */
  5,                                   /* lineNo */
  6,                                   /* colNo */
  "par.rom.sprdmp",                    /* aName */
  "int_mid_step",                      /* fName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/int_mid_step.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 5,   /* lineNo */
  6,                                   /* colNo */
  "int_mid_step",                      /* fName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/int_mid_step.m",/* pName */
  1                                    /* checkKind */
};

/* Function Definitions */
void int_mid_step(const emlrtStack *sp, real_T t, const real_T z[24], b_struct_T
                  *par)
{
  real_T l;
  int32_T i5;
  real_T ds;
  int32_T s;
  real_T unusedU0[72];
  real_T unusedU1[6];
  real_T unusedU2[6];
  real_T unusedU3[6];
  real_T dl[3];
  static const int8_T iv14[6] = { 0, 0, 1, 1, 2, 2 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  l = 0.0;
  if (par->n_sd != (int32_T)muDoubleScalarFloor(par->n_sd)) {
    emlrtIntegerCheckR2012b(par->n_sd, &d_emlrtDCI, sp);
  }

  i5 = (int32_T)par->n_sd;
  if ((i5 < 1) || (i5 > 13)) {
    emlrtDynamicBoundsCheckR2012b(i5, 1, 13, &e_emlrtBCI, sp);
  }

  ds = par->rom.sprdmp[i5 - 1] / par->n_int;
  if (par->rom.sprdmp[(int32_T)par->n_sd - 1] == 0.0) {
    ds = 1.0;
  }

  i5 = (int32_T)(((par->rom.sprdmp[(int32_T)par->n_sd - 1] - 1.0E-6) + (ds -
    1.0E-6)) / ds);
  emlrtForLoopVectorCheckR2012b(1.0E-6, ds, par->rom.sprdmp[(int32_T)par->n_sd -
    1] - 1.0E-6, mxDOUBLE_CLASS, i5, &h_emlrtRTEI, sp);
  for (s = 0; s < i5; s++) {
    st.site = &l_emlrtRSI;
    sprdmpF13(&st, par->var, z, 1.0E-6 + (real_T)s * ds, unusedU0, unusedU1,
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
  i5 = (int32_T)ds;
  if (ds != i5) {
    emlrtIntegerCheckR2012b(ds, &c_emlrtDCI, sp);
  }

  if ((i5 < 1) || (i5 > 1094)) {
    emlrtDynamicBoundsCheckR2012b(i5, 1, 1094, &d_emlrtBCI, sp);
  }

  ds = par->var[4];
  for (s = 0; s < 6; s++) {
    par->var[21 + s] = par->p[(i5 + 1094 * (1 + iv14[s])) - 1];
    par->var[s + 27] = par->f_ex[(i5 + 1094 * (1 + s)) - 1];
  }

  par->var[33] = l / ds;
}

/* End of code generation (int_mid_step.c) */
