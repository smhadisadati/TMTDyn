/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_EOM_input_api.c
 *
 * Code generation for function '_coder_EOM_input_api'
 *
 */

/* Include files */
#include "_coder_EOM_input_api.h"
#include "EOM_input.h"
#include "EOM_input_types.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static const mxArray *b_emlrt_marshallOut(const real_T u);
static const mxArray *c_emlrt_marshallOut(const real_T u[34]);
static const mxArray *d_emlrt_marshallOut(const struct0_T *u);
static const mxArray *e_emlrt_marshallOut(const real_T u[10242]);
static const mxArray *emlrt_marshallOut(const real_T u[3]);
static const mxArray *f_emlrt_marshallOut(const real_T u[6828]);

/* Function Definitions */
static const mxArray *b_emlrt_marshallOut(const real_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *c_emlrt_marshallOut(const real_T u[34])
{
  static const int32_T iv[1] = { 0 };

  static const int32_T iv1[1] = { 34 };

  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(1, &iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, iv1, 1);
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *d_emlrt_marshallOut(const struct0_T *u)
{
  static const int32_T iv[2] = { 1710, 4 };

  static const int32_T iv1[2] = { 1, 27 };

  static const char_T *sv1[4] = { "n_t", "motor_in", "tip_pos", "tip_load" };

  static const char_T *sv[3] = { "user_pars", "var", "t_equil_i" };

  static const char_T *sv2[3] = { "pos", "vel", "acc" };

  static const char_T *sv3[3] = { "tube1", "tube1_vel", "tube1_acc" };

  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T b_i;
  int32_T c_i;
  int32_T i;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 3, sv));
  b_y = NULL;
  emlrtAssign(&b_y, emlrtCreateStructMatrix(1, 1, 4, sv1));
  emlrtSetFieldR2017b(b_y, 0, "n_t", b_emlrt_marshallOut(u->user_pars.n_t), 0);
  c_y = NULL;
  emlrtAssign(&c_y, emlrtCreateStructMatrix(1, 1, 3, sv2));
  emlrtSetFieldR2017b(c_y, 0, "pos", e_emlrt_marshallOut
                      (u->user_pars.motor_in.pos), 0);
  emlrtSetFieldR2017b(c_y, 0, "vel", e_emlrt_marshallOut
                      (u->user_pars.motor_in.vel), 1);
  emlrtSetFieldR2017b(c_y, 0, "acc", e_emlrt_marshallOut
                      (u->user_pars.motor_in.acc), 2);
  emlrtSetFieldR2017b(b_y, 0, "motor_in", c_y, 1);
  d_y = NULL;
  emlrtAssign(&d_y, emlrtCreateStructMatrix(1, 1, 3, sv3));
  emlrtSetFieldR2017b(d_y, 0, "tube1", f_emlrt_marshallOut
                      (u->user_pars.tip_pos.tube1), 0);
  emlrtSetFieldR2017b(d_y, 0, "tube1_vel", f_emlrt_marshallOut
                      (u->user_pars.tip_pos.tube1_vel), 1);
  emlrtSetFieldR2017b(d_y, 0, "tube1_acc", f_emlrt_marshallOut
                      (u->user_pars.tip_pos.tube1_acc), 2);
  emlrtSetFieldR2017b(b_y, 0, "tip_pos", d_y, 2);
  e_y = NULL;
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < 4; b_i++) {
    for (c_i = 0; c_i < 1710; c_i++) {
      pData[i] = u->user_pars.tip_load[c_i + 1710 * b_i];
      i++;
    }
  }

  emlrtAssign(&e_y, m);
  emlrtSetFieldR2017b(b_y, 0, "tip_load", e_y, 3);
  emlrtSetFieldR2017b(y, 0, "user_pars", b_y, 0);
  f_y = NULL;
  m = emlrtCreateNumericArray(2, &iv1[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < 27; b_i++) {
    pData[i] = u->var[b_i];
    i++;
  }

  emlrtAssign(&f_y, m);
  emlrtSetFieldR2017b(y, 0, "var", f_y, 1);
  emlrtSetFieldR2017b(y, 0, "t_equil_i", b_emlrt_marshallOut(u->t_equil_i), 2);
  return y;
}

static const mxArray *e_emlrt_marshallOut(const real_T u[10242])
{
  static const int32_T iv[2] = { 1707, 6 };

  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T b_i;
  int32_T c_i;
  int32_T i;
  y = NULL;
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < 6; b_i++) {
    for (c_i = 0; c_i < 1707; c_i++) {
      pData[i] = u[c_i + 1707 * b_i];
      i++;
    }
  }

  emlrtAssign(&y, m);
  return y;
}

static const mxArray *emlrt_marshallOut(const real_T u[3])
{
  static const int32_T iv[2] = { 0, 0 };

  static const int32_T iv1[2] = { 1, 3 };

  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, iv1, 2);
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *f_emlrt_marshallOut(const real_T u[6828])
{
  static const int32_T iv[2] = { 1707, 4 };

  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T b_i;
  int32_T c_i;
  int32_T i;
  y = NULL;
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < 4; b_i++) {
    for (c_i = 0; c_i < 1707; c_i++) {
      pData[i] = u[c_i + 1707 * b_i];
      i++;
    }
  }

  emlrtAssign(&y, m);
  return y;
}

void EOM_input_api(EOM_inputStackData *SD, int32_T nlhs, const mxArray *plhs[4])
{
  real_T (*z0)[34];
  real_T (*tspan)[3];
  real_T nz;
  tspan = (real_T (*)[3])mxMalloc(sizeof(real_T [3]));
  z0 = (real_T (*)[34])mxMalloc(sizeof(real_T [34]));

  /* Invoke the target function */
  EOM_input(*tspan, &nz, *z0, &SD->f0.par_mex);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*tspan);
  if (nlhs > 1) {
    plhs[1] = b_emlrt_marshallOut(nz);
  }

  if (nlhs > 2) {
    plhs[2] = c_emlrt_marshallOut(*z0);
  }

  if (nlhs > 3) {
    plhs[3] = d_emlrt_marshallOut(&SD->f0.par_mex);
  }
}

/* End of code generation (_coder_EOM_input_api.c) */
