/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_EOM_api.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 08-May-2021 01:57:20
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
  char_T *identifier))[38];
static const mxArray *c_emlrt_marshallOut(void);
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[38];
static const mxArray *d_emlrt_marshallOut(const real_T u[3]);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *par_mex,
  const char_T *identifier, struct0_T *y);
static const mxArray *e_emlrt_marshallOut(const struct0_T *u);
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *t, const
  char_T *identifier);
static const mxArray *emlrt_marshallOut(const real_T u[38]);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y);
static const mxArray *f_emlrt_marshallOut(const real_T u[87522]);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T *y);
static const mxArray *g_emlrt_marshallOut(const real_T u[58336]);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct2_T *y);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[87522]);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct3_T *y);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[58336]);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[72935]);
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[33]);
static real_T n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static real_T (*o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[38];
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[87522]);
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[58336]);
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[72935]);
static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[33]);

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
 * Return Type  : real_T (*)[38]
 */
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *z, const
  char_T *identifier))[38]
{
  emlrtMsgIdentifier thisId;
  real_T (*y)[38];
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
 * Return Type  : real_T (*)[38]
 */
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[38]
{
  real_T (*y)[38];
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
  static const int32_T iv[2] = { 14587, 5 };

  static const int32_T iv1[2] = { 1, 33 };

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
  emlrtSetFieldR2017b(c_y, 0, "pos", f_emlrt_marshallOut
                      (u->user_pars.motor_in.pos), 0);
  emlrtSetFieldR2017b(c_y, 0, "vel", f_emlrt_marshallOut
                      (u->user_pars.motor_in.vel), 1);
  emlrtSetFieldR2017b(c_y, 0, "acc", f_emlrt_marshallOut
                      (u->user_pars.motor_in.acc), 2);
  emlrtSetFieldR2017b(b_y, 0, "motor_in", c_y, 1);
  d_y = NULL;
  emlrtAssign(&d_y, emlrtCreateStructMatrix(1, 1, 3, sv3));
  emlrtSetFieldR2017b(d_y, 0, "tube1", g_emlrt_marshallOut
                      (u->user_pars.tip_pos.tube1), 0);
  emlrtSetFieldR2017b(d_y, 0, "tube1_vel", g_emlrt_marshallOut
                      (u->user_pars.tip_pos.tube1_vel), 1);
  emlrtSetFieldR2017b(d_y, 0, "tube1_acc", g_emlrt_marshallOut
                      (u->user_pars.tip_pos.tube1_acc), 2);
  emlrtSetFieldR2017b(b_y, 0, "tip_pos", d_y, 2);
  e_y = NULL;
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < 5; b_i++) {
    for (c_i = 0; c_i < 14587; c_i++) {
      pData[i] = u->user_pars.tip_load[c_i + 14587 * b_i];
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
  for (b_i = 0; b_i < 33; b_i++) {
    pData[i] = u->var[b_i];
    i++;
  }

  emlrtAssign(&f_y, m);
  emlrtSetFieldR2017b(y, 0, "var", f_y, 1);
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
 * Arguments    : const real_T u[38]
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const real_T u[38])
{
  static const int32_T iv[1] = { 0 };

  static const int32_T iv1[1] = { 38 };

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
 * Arguments    : const real_T u[87522]
 * Return Type  : const mxArray *
 */
static const mxArray *f_emlrt_marshallOut(const real_T u[87522])
{
  static const int32_T iv[2] = { 14587, 6 };

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
    for (c_i = 0; c_i < 14587; c_i++) {
      pData[i] = u[c_i + 14587 * b_i];
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
  static const char_T *fieldNames[4] = { "n_t", "motor_in", "tip_pos",
    "tip_load" };

  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 4, fieldNames, 0U, &dims);
  thisId.fIdentifier = "n_t";
  y->n_t = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0,
    "n_t")), &thisId);
  thisId.fIdentifier = "motor_in";
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1, "motor_in")),
                     &thisId, &y->motor_in);
  thisId.fIdentifier = "tip_pos";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2, "tip_pos")),
                     &thisId, &y->tip_pos);
  thisId.fIdentifier = "tip_load";
  l_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3, "tip_load")),
                     &thisId, y->tip_load);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const real_T u[58336]
 * Return Type  : const mxArray *
 */
static const mxArray *g_emlrt_marshallOut(const real_T u[58336])
{
  static const int32_T iv[2] = { 14584, 4 };

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
    for (c_i = 0; c_i < 14584; c_i++) {
      pData[i] = u[c_i + 14584 * b_i];
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
 *                real_T y[87522]
 * Return Type  : void
 */
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[87522])
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
  static const char_T *fieldNames[3] = { "tube1", "tube1_vel", "tube1_acc" };

  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 3, fieldNames, 0U, &dims);
  thisId.fIdentifier = "tube1";
  k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "tube1")),
                     &thisId, y->tube1);
  thisId.fIdentifier = "tube1_vel";
  k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1, "tube1_vel")),
                     &thisId, y->tube1_vel);
  thisId.fIdentifier = "tube1_acc";
  k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2, "tube1_acc")),
                     &thisId, y->tube1_acc);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T y[58336]
 * Return Type  : void
 */
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[58336])
{
  q_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T y[72935]
 * Return Type  : void
 */
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[72935])
{
  r_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T y[33]
 * Return Type  : void
 */
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[33])
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
 * Return Type  : real_T (*)[38]
 */
static real_T (*o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[38]
{
  static const int32_T dims[1] = { 38 };

  real_T (*ret)[38];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims);
  ret = (real_T (*)[38])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[87522]
 * Return Type  : void
 */
  static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[87522])
{
  static const int32_T dims[2] = { 14587, 6 };

  real_T (*r)[87522];
  int32_T i;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r = (real_T (*)[87522])emlrtMxGetData(src);
  for (i = 0; i < 87522; i++) {
    ret[i] = (*r)[i];
  }

  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[58336]
 * Return Type  : void
 */
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[58336])
{
  static const int32_T dims[2] = { 14584, 4 };

  real_T (*r)[58336];
  int32_T i;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r = (real_T (*)[58336])emlrtMxGetData(src);
  for (i = 0; i < 58336; i++) {
    ret[i] = (*r)[i];
  }

  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[72935]
 * Return Type  : void
 */
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[72935])
{
  static const int32_T dims[2] = { 14587, 5 };

  real_T (*r)[72935];
  int32_T i;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r = (real_T (*)[72935])emlrtMxGetData(src);
  for (i = 0; i < 72935; i++) {
    ret[i] = (*r)[i];
  }

  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[33]
 * Return Type  : void
 */
static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[33])
{
  static const int32_T dims[2] = { 1, 33 };

  real_T (*r)[33];
  int32_T i;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r = (real_T (*)[33])emlrtMxGetData(src);
  for (i = 0; i < 33; i++) {
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

  real_T (*dz)[38];
  real_T (*z)[38];
  real_T flag;
  real_T t;
  st.tls = emlrtRootTLSGlobal;
  dz = (real_T (*)[38])mxMalloc(sizeof(real_T [38]));
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
  real_T (*z0)[38];
  real_T (*tspan)[3];
  real_T nz;
  tspan = (real_T (*)[3])mxMalloc(sizeof(real_T [3]));
  z0 = (real_T (*)[38])mxMalloc(sizeof(real_T [38]));

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
