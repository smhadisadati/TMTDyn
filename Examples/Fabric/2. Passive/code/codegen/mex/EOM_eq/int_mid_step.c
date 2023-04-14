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

/* Variable Definitions */
static emlrtDCInfo c_emlrtDCI = { 4,   /* lineNo */
  20,                                  /* colNo */
  "int_mid_step",                      /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/int_mid_step.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { 1,   /* iFirst */
  220,                                 /* iLast */
  4,                                   /* lineNo */
  20,                                  /* colNo */
  "par.ddr_arm",                       /* aName */
  "int_mid_step",                      /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/int_mid_step.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void int_mid_step(const emlrtStack *sp, real_T t, b_struct_T *par)
{
  real_T d0;
  int32_T i8;
  d0 = muDoubleScalarFloor(t / 0.05);
  i8 = (int32_T)d0;
  if (d0 != i8) {
    emlrtIntegerCheckR2012b(d0, &c_emlrtDCI, sp);
  }

  if ((i8 < 1) || (i8 > 220)) {
    emlrtDynamicBoundsCheckR2012b(i8, 1, 220, &d_emlrtBCI, sp);
  }

  par->var[4] = par->ddr_arm[i8 - 1];
  par->var[5] = par->ddr_arm[i8 + 439];
}

/* End of code generation (int_mid_step.c) */
