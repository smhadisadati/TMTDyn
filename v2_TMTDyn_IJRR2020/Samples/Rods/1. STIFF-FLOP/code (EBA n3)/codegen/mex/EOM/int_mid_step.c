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

/* Variable Definitions */
static emlrtDCInfo c_emlrtDCI = { 13,  /* lineNo */
  20,                                  /* colNo */
  "int_mid_step",                      /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/int_mid_step.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { 1,   /* iFirst */
  1094,                                /* iLast */
  13,                                  /* lineNo */
  20,                                  /* colNo */
  "par.f_ex",                          /* aName */
  "int_mid_step",                      /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/int_mid_step.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void int_mid_step(const emlrtStack *sp, real_T t, struct0_T *b_par)
{
  real_T step;
  int32_T i1;
  int32_T i2;
  static const int8_T iv5[6] = { 0, 0, 1, 1, 2, 2 };

  /*  l = 0 ; */
  /*  [ ~ , ~ , ~ , ~ , dl ] = sprdmpF19( par.var , z.' , 0 ) ; l = l + dl ; % 6 * n_s + 1 : n_sd = 6 * n_s + n_s */
  /*  [ ~ , ~ , ~ , ~ , dl ] = sprdmpF20( par.var , z.' , 0 ) ; l = l + dl ; % 6 * n_s + 1 : n_sd = 6 * n_s + n_s */
  /*  [ ~ , ~ , ~ , ~ , dl ] = sprdmpF21( par.var , z.' , 0 ) ; l = l + dl ; % 6 * n_s + 1 : n_sd = 6 * n_s + n_s */
  /*  lambda = 1 + l / par.var(5) ;  */
  /*  input p & ext. forces */
  /*  temp = interp1( par.f_ex(:,1) , [ par.f_ex(:,2:7) par.p(:,2:4) ] , t , 'nearest' ) ; */
  step = muDoubleScalarFloor(t / 0.05);
  i1 = (int32_T)step;
  if (step != i1) {
    emlrtIntegerCheckR2012b(step, &c_emlrtDCI, sp);
  }

  if ((i1 < 1) || (i1 > 1094)) {
    emlrtDynamicBoundsCheckR2012b(i1, 1, 1094, &d_emlrtBCI, sp);
  }

  for (i2 = 0; i2 < 6; i2++) {
    b_par->var[21 + i2] = b_par->p[(i1 + 1094 * (1 + iv5[i2])) - 1];
    b_par->var[i2 + 27] = b_par->f_ex[(i1 + 1094 * (1 + i2)) - 1];
  }

  b_par->var[33] = 1.0;
}

/* End of code generation (int_mid_step.c) */
