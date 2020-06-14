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
#include "sprdmpF7.h"

/* Variable Definitions */
static emlrtRSInfo j_emlrtRSI = { 5,   /* lineNo */
  "int_mid_step",                      /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/int_mid_step.m"/* pathName */
};

static emlrtDCInfo c_emlrtDCI = { 11,  /* lineNo */
  20,                                  /* colNo */
  "int_mid_step",                      /* fName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/int_mid_step.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { 1,   /* iFirst */
  1094,                                /* iLast */
  11,                                  /* lineNo */
  20,                                  /* colNo */
  "par.f_ex",                          /* aName */
  "int_mid_step",                      /* fName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/int_mid_step.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void int_mid_step(const emlrtStack *sp, real_T t, const real_T z[12], b_struct_T
                  *par)
{
  real_T unusedU1[6];
  real_T unusedU2[6];
  real_T unusedU3[6];
  real_T dl;
  real_T step;
  int32_T i8;
  int32_T i9;
  static const int8_T iv14[6] = { 0, 0, 1, 1, 2, 2 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &j_emlrtRSI;
  sprdmpF7(&st, par->var, z, unusedU1, unusedU2, unusedU3, &dl);

  /*  6 * n_s + 1 : n_sd = 6 * n_s + n_s */
  /*  input p & ext. forces */
  /*  temp = interp1( par.f_ex(:,1) , [ par.f_ex(:,2:7) par.p(:,2:4) ] , t , 'nearest' ) ; */
  step = muDoubleScalarFloor(t / 0.05);
  i8 = (int32_T)step;
  if (step != i8) {
    emlrtIntegerCheckR2012b(step, &c_emlrtDCI, sp);
  }

  if ((i8 < 1) || (i8 > 1094)) {
    emlrtDynamicBoundsCheckR2012b(i8, 1, 1094, &d_emlrtBCI, sp);
  }

  step = par->var[4];
  for (i9 = 0; i9 < 6; i9++) {
    par->var[21 + i9] = par->p[(i8 + 1094 * (1 + iv14[i9])) - 1];
    par->var[i9 + 27] = par->f_ex[(i8 + 1094 * (1 + i9)) - 1];
  }

  par->var[33] = 1.0 + dl / step;
}

/* End of code generation (int_mid_step.c) */
