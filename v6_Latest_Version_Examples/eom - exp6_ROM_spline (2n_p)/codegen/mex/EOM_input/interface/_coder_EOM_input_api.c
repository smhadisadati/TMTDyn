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
static const mxArray *c_emlrt_marshallOut(const real_T u[18]);
static const mxArray *d_emlrt_marshallOut(const struct0_T *u);
static const mxArray *e_emlrt_marshallOut(const real_T u[4376]);
static const mxArray *emlrt_marshallOut(const real_T u[3]);

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

static const mxArray *c_emlrt_marshallOut(const real_T u[18])
{
  static const int32_T iv[1] = { 0 };

  static const int32_T iv1[1] = { 18 };

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
  static const int32_T iv[2] = { 1094, 5 };

  static const int32_T iv1[2] = { 1094, 7 };

  static const int32_T iv2[2] = { 1, 34 };

  static const char_T *sv1[5] = { "p", "tip_pos", "tip_RQ", "f_ex", "n_l" };

  static const char_T *sv[3] = { "user_pars", "var", "t_equil_i" };

  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T b_i;
  int32_T c_i;
  int32_T i;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 3, sv));
  b_y = NULL;
  emlrtAssign(&b_y, emlrtCreateStructMatrix(1, 1, 5, sv1));
  emlrtSetFieldR2017b(b_y, 0, "p", e_emlrt_marshallOut(u->user_pars.p), 0);
  emlrtSetFieldR2017b(b_y, 0, "tip_pos", e_emlrt_marshallOut
                      (u->user_pars.tip_pos), 1);
  c_y = NULL;
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < 5; b_i++) {
    for (c_i = 0; c_i < 1094; c_i++) {
      pData[i] = u->user_pars.tip_RQ[c_i + 1094 * b_i];
      i++;
    }
  }

  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(b_y, 0, "tip_RQ", c_y, 2);
  d_y = NULL;
  m = emlrtCreateNumericArray(2, &iv1[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < 7; b_i++) {
    for (c_i = 0; c_i < 1094; c_i++) {
      pData[i] = u->user_pars.f_ex[c_i + 1094 * b_i];
      i++;
    }
  }

  emlrtAssign(&d_y, m);
  emlrtSetFieldR2017b(b_y, 0, "f_ex", d_y, 3);
  emlrtSetFieldR2017b(b_y, 0, "n_l", b_emlrt_marshallOut(u->user_pars.n_l), 4);
  emlrtSetFieldR2017b(y, 0, "user_pars", b_y, 0);
  e_y = NULL;
  m = emlrtCreateNumericArray(2, &iv2[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < 34; b_i++) {
    pData[i] = u->var[b_i];
    i++;
  }

  emlrtAssign(&e_y, m);
  emlrtSetFieldR2017b(y, 0, "var", e_y, 1);
  emlrtSetFieldR2017b(y, 0, "t_equil_i", b_emlrt_marshallOut(u->t_equil_i), 2);
  return y;
}

static const mxArray *e_emlrt_marshallOut(const real_T u[4376])
{
  static const int32_T iv[2] = { 1094, 4 };

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
    for (c_i = 0; c_i < 1094; c_i++) {
      pData[i] = u[c_i + 1094 * b_i];
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

void EOM_input_api(int32_T nlhs, const mxArray *plhs[4])
{
  struct0_T par_mex;
  real_T (*z0)[18];
  real_T (*tspan)[3];
  real_T nz;
  tspan = (real_T (*)[3])mxMalloc(sizeof(real_T [3]));
  z0 = (real_T (*)[18])mxMalloc(sizeof(real_T [18]));

  /* Invoke the target function */
  EOM_input(*tspan, &nz, *z0, &par_mex);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*tspan);
  if (nlhs > 1) {
    plhs[1] = b_emlrt_marshallOut(nz);
  }

  if (nlhs > 2) {
    plhs[2] = c_emlrt_marshallOut(*z0);
  }

  if (nlhs > 3) {
    plhs[3] = d_emlrt_marshallOut(&par_mex);
  }
}

/* End of code generation (_coder_EOM_input_api.c) */
