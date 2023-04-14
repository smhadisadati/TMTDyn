/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_EOM_api.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 10-Mar-2021 22:46:32
 */

/* Include Files */
#include "_coder_EOM_api.h"
#include "_coder_EOM_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131595U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "EOM",                               /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static const mxArray *b_emlrt_marshallOut(const real_T u);
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *z, const
  char_T *identifier))[48];
static const mxArray *c_emlrt_marshallOut(void);
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[48];
static const mxArray *d_emlrt_marshallOut(const real_T u[3]);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *par_mex,
  const char_T *identifier, struct0_T *y);
static const mxArray *e_emlrt_marshallOut(const struct0_T *u);
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *t, const
  char_T *identifier);
static const mxArray *emlrt_marshallOut(const real_T u[48]);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y);
static const mxArray *f_emlrt_marshallOut(const real_T u[2618]);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T *y);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct2_T *y);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2618]);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct3_T *y);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[16024]);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[15832]);
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[60]);
static real_T n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static real_T (*o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[48];
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2618]);
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[16024]);
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[15832]);
static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[60]);

/* Function Definitions */
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T
 */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = n_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const real_T u
 * Return Type  : const mxArray *
 */
static const mxArray *b_emlrt_marshallOut(const real_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *z
 *                const char_T *identifier
 * Return Type  : real_T (*)[48]
 */
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *z, const
  char_T *identifier))[48]
{
  emlrtMsgIdentifier thisId;
  real_T (*y)[48];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(z), &thisId);
  emlrtDestroyArray(&z);
  return y;
}
/*
 * Arguments    : void
 * Return Type  : const mxArray *
 */
  static const mxArray *c_emlrt_marshallOut(void)
{
  static const int32_T iv[2] = { 0, 0 };

  static const int32_T iv1[2] = { 0, 0 };

  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, NULL);
  emlrtSetDimensions((mxArray *)m, iv1, 2);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[48]
 */
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[48]
{
  real_T (*y)[48];
  y = o_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
/*
 * Arguments    : const real_T u[3]
 * Return Type  : const mxArray *
 */
  static const mxArray *d_emlrt_marshallOut(const real_T u[3])
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

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *par_mex
 *                const char_T *identifier
 *                struct0_T *y
 * Return Type  : void
 */
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *par_mex,
  const char_T *identifier, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  f_emlrt_marshallIn(sp, emlrtAlias(par_mex), &thisId, y);
  emlrtDestroyArray(&par_mex);
}

/*
 * Arguments    : const struct0_T *u
 * Return Type  : const mxArray *
 */
static const mxArray *e_emlrt_marshallOut(const struct0_T *u)
{
  static const int32_T iv[2] = { 2003, 8 };

  static const int32_T iv1[2] = { 1979, 8 };

  static const int32_T iv2[2] = { 1, 60 };

  static const char_T *sv[3] = { "user_pars", "var", "t_equil_i" };

  static const char_T *sv1[3] = { "n_t", "motor_in", "tip_pos" };

  static const char_T *sv2[3] = { "pos", "vel", "acc" };

  static const char_T *sv3[2] = { "tube1", "tube2" };

  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T b_i;
  int32_T c_i;
  int32_T i;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 3, sv));
  b_y = NULL;
  emlrtAssign(&b_y, emlrtCreateStructMatrix(1, 1, 3, sv1));
  emlrtSetFieldR2017b(b_y, 0, "n_t", b_emlrt_marshallOut(u->user_pars.n_t), 0);
  c_y = NULL;
  emlrtAssign(&c_y, emlrtCreateStructMatrix(1, 1, 3, sv2));
  emlrtSetFieldR2017b(c_y, 0, "pos", f_emlrt_marshallOut
                      (u->user_pars.motor_in.pos), 0);
  emlrtSetFieldR2017b(c_y, 0, "vel", f_emlrt_marshallOut
                      (u->user_pars.motor_in.vel), 1);
  emlrtSetFieldR2017b(c_y, 0, "acc", f_emlrt_marshallOut
                      (u->user_pars.motor_in.acc), 2);
  emlrtSetFieldR2017b(b_y, 0, "motor_in", c_y, 1);
  d_y = NULL;
  emlrtAssign(&d_y, emlrtCreateStructMatrix(1, 1, 2, sv3));
  e_y = NULL;
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < 8; b_i++) {
    for (c_i = 0; c_i < 2003; c_i++) {
      pData[i] = u->user_pars.tip_pos.tube1[c_i + 2003 * b_i];
      i++;
    }
  }

  emlrtAssign(&e_y, m);
  emlrtSetFieldR2017b(d_y, 0, "tube1", e_y, 0);
  f_y = NULL;
  m = emlrtCreateNumericArray(2, &iv1[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < 8; b_i++) {
    for (c_i = 0; c_i < 1979; c_i++) {
      pData[i] = u->user_pars.tip_pos.tube2[c_i + 1979 * b_i];
      i++;
    }
  }

  emlrtAssign(&f_y, m);
  emlrtSetFieldR2017b(d_y, 0, "tube2", f_y, 1);
  emlrtSetFieldR2017b(b_y, 0, "tip_pos", d_y, 2);
  emlrtSetFieldR2017b(y, 0, "user_pars", b_y, 0);
  g_y = NULL;
  m = emlrtCreateNumericArray(2, &iv2[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < 60; b_i++) {
    pData[i] = u->var[b_i];
    i++;
  }

  emlrtAssign(&g_y, m);
  emlrtSetFieldR2017b(y, 0, "var", g_y, 1);
  emlrtSetFieldR2017b(y, 0, "t_equil_i", b_emlrt_marshallOut(u->t_equil_i), 2);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *t
 *                const char_T *identifier
 * Return Type  : real_T
 */
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *t, const
  char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(t), &thisId);
  emlrtDestroyArray(&t);
  return y;
}

/*
 * Arguments    : const real_T u[48]
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const real_T u[48])
{
  static const int32_T iv[1] = { 0 };

  static const int32_T iv1[1] = { 48 };

  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(1, &iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, iv1, 1);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                struct0_T *y
 * Return Type  : void
 */
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[3] = { "user_pars", "var", "t_equil_i" };

  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 3, fieldNames, 0U, &dims);
  thisId.fIdentifier = "user_pars";
  g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "user_pars")),
                     &thisId, &y->user_pars);
  thisId.fIdentifier = "var";
  m_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1, "var")),
                     &thisId, y->var);
  thisId.fIdentifier = "t_equil_i";
  y->t_equil_i = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    2, "t_equil_i")), &thisId);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const real_T u[2618]
 * Return Type  : const mxArray *
 */
static const mxArray *f_emlrt_marshallOut(const real_T u[2618])
{
  static const int32_T iv[2] = { 374, 7 };

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
  for (b_i = 0; b_i < 7; b_i++) {
    for (c_i = 0; c_i < 374; c_i++) {
      pData[i] = u[c_i + 374 * b_i];
      i++;
    }
  }

  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                struct1_T *y
 * Return Type  : void
 */
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[3] = { "n_t", "motor_in", "tip_pos" };

  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 3, fieldNames, 0U, &dims);
  thisId.fIdentifier = "n_t";
  y->n_t = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0,
    "n_t")), &thisId);
  thisId.fIdentifier = "motor_in";
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1, "motor_in")),
                     &thisId, &y->motor_in);
  thisId.fIdentifier = "tip_pos";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2, "tip_pos")),
                     &thisId, &y->tip_pos);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                struct2_T *y
 * Return Type  : void
 */
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct2_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[3] = { "pos", "vel", "acc" };

  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 3, fieldNames, 0U, &dims);
  thisId.fIdentifier = "pos";
  i_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "pos")),
                     &thisId, y->pos);
  thisId.fIdentifier = "vel";
  i_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1, "vel")),
                     &thisId, y->vel);
  thisId.fIdentifier = "acc";
  i_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2, "acc")),
                     &thisId, y->acc);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T y[2618]
 * Return Type  : void
 */
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2618])
{
  p_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                struct3_T *y
 * Return Type  : void
 */
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct3_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[2] = { "tube1", "tube2" };

  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 2, fieldNames, 0U, &dims);
  thisId.fIdentifier = "tube1";
  k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "tube1")),
                     &thisId, y->tube1);
  thisId.fIdentifier = "tube2";
  l_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1, "tube2")),
                     &thisId, y->tube2);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T y[16024]
 * Return Type  : void
 */
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[16024])
{
  q_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T y[15832]
 * Return Type  : void
 */
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[15832])
{
  r_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T y[60]
 * Return Type  : void
 */
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[60])
{
  s_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T
 */
static real_T n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[48]
 */
static real_T (*o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[48]
{
  static const int32_T dims[1] = { 48 };

  real_T (*ret)[48];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims);
  ret = (real_T (*)[48])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[2618]
 * Return Type  : void
 */
  static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2618])
{
  static const int32_T dims[2] = { 374, 7 };

  real_T (*r)[2618];
  int32_T i;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r = (real_T (*)[2618])emlrtMxGetData(src);
  for (i = 0; i < 2618; i++) {
    ret[i] = (*r)[i];
  }

  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[16024]
 * Return Type  : void
 */
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[16024])
{
  static const int32_T dims[2] = { 2003, 8 };

  real_T (*r)[16024];
  int32_T i;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r = (real_T (*)[16024])emlrtMxGetData(src);
  for (i = 0; i < 16024; i++) {
    ret[i] = (*r)[i];
  }

  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[15832]
 * Return Type  : void
 */
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[15832])
{
  static const int32_T dims[2] = { 1979, 8 };

  real_T (*r)[15832];
  int32_T i;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r = (real_T (*)[15832])emlrtMxGetData(src);
  for (i = 0; i < 15832; i++) {
    ret[i] = (*r)[i];
  }

  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[60]
 * Return Type  : void
 */
static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[60])
{
  static const int32_T dims[2] = { 1, 60 };

  real_T (*r)[60];
  int32_T i;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r = (real_T (*)[60])emlrtMxGetData(src);
  for (i = 0; i < 60; i++) {
    ret[i] = (*r)[i];
  }

  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const mxArray * const prhs[3]
 *                int32_T nlhs
 *                const mxArray *plhs[3]
 * Return Type  : void
 */
void EOM_api(const mxArray * const prhs[3], int32_T nlhs, const mxArray *plhs[3])
{
  static struct0_T par_mex;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  real_T (*dz)[48];
  real_T (*z)[48];
  real_T flag;
  real_T t;
  st.tls = emlrtRootTLSGlobal;
  dz = (real_T (*)[48])mxMalloc(sizeof(real_T [48]));
  mxMalloc(0U);

  /* Marshall function inputs */
  t = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "t");
  z = c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "z");
  e_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "par_mex", &par_mex);

  /* Invoke the target function */
  EOM(t, *z, &par_mex, *dz, &flag);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*dz);
  if (nlhs > 1) {
    plhs[1] = b_emlrt_marshallOut(flag);
  }

  if (nlhs > 2) {
    plhs[2] = c_emlrt_marshallOut();
  }
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void EOM_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  EOM_xil_terminate();
  EOM_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void EOM_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : int32_T nlhs
 *                const mxArray *plhs[4]
 * Return Type  : void
 */
void EOM_input_api(int32_T nlhs, const mxArray *plhs[4])
{
  static struct0_T par_mex;
  real_T (*z0)[48];
  real_T (*tspan)[3];
  real_T nz;
  tspan = (real_T (*)[3])mxMalloc(sizeof(real_T [3]));
  z0 = (real_T (*)[48])mxMalloc(sizeof(real_T [48]));

  /* Invoke the target function */
  EOM_input(*tspan, &nz, *z0, &par_mex);

  /* Marshall function outputs */
  plhs[0] = d_emlrt_marshallOut(*tspan);
  if (nlhs > 1) {
    plhs[1] = b_emlrt_marshallOut(nz);
  }

  if (nlhs > 2) {
    plhs[2] = emlrt_marshallOut(*z0);
  }

  if (nlhs > 3) {
    plhs[3] = e_emlrt_marshallOut(&par_mex);
  }
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void EOM_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_EOM_api.c
 *
 * [EOF]
 */
