/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_EOM_eq_api.c
 *
 * Code generation for function '_coder_EOM_eq_api'
 *
 */

/* Include files */
#include "_coder_EOM_eq_api.h"
#include "EOM_eq.h"
#include "EOM_eq_data.h"
#include "EOM_eq_types.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, b_struct_T *y);
static const mxArray *b_emlrt_marshallOut(const real_T u[4376]);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[34]);
static const mxArray *c_emlrt_marshallOut(const real_T u[12]);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct_T *y);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[4376]);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_par_mex,
  const char_T *identifier, b_struct_T *y);
static const mxArray *emlrt_marshallOut(const b_struct_T *u);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[5470]);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[7658]);
static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *z, const
  char_T *identifier))[12];
static real_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[12];
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[34]);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[4376]);
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[5470]);
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[7658]);
static real_T o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static real_T (*p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[12];

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, b_struct_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[3] = { "var", "user_pars", "t_equil_i" };

  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 3, fieldNames, 0U, &dims);
  thisId.fIdentifier = "var";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "var")),
                     &thisId, y->var);
  thisId.fIdentifier = "user_pars";
  d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1, "user_pars")),
                     &thisId, &y->user_pars);
  thisId.fIdentifier = "t_equil_i";
  y->t_equil_i = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    2, "t_equil_i")), &thisId);
  emlrtDestroyArray(&u);
}

static const mxArray *b_emlrt_marshallOut(const real_T u[4376])
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

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[34])
{
  k_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *c_emlrt_marshallOut(const real_T u[12])
{
  static const int32_T iv[1] = { 0 };

  static const int32_T iv1[1] = { 12 };

  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(1, &iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, iv1, 1);
  emlrtAssign(&y, m);
  return y;
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[5] = { "p", "tip_pos", "tip_RQ", "f_ex", "n_l"
  };

  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 5, fieldNames, 0U, &dims);
  thisId.fIdentifier = "p";
  e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "p")),
                     &thisId, y->p);
  thisId.fIdentifier = "tip_pos";
  e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1, "tip_pos")),
                     &thisId, y->tip_pos);
  thisId.fIdentifier = "tip_RQ";
  f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2, "tip_RQ")),
                     &thisId, y->tip_RQ);
  thisId.fIdentifier = "f_ex";
  g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3, "f_ex")),
                     &thisId, y->f_ex);
  thisId.fIdentifier = "n_l";
  y->n_l = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 4,
    "n_l")), &thisId);
  emlrtDestroyArray(&u);
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[4376])
{
  l_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_par_mex,
  const char_T *identifier, b_struct_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(b_par_mex), &thisId, y);
  emlrtDestroyArray(&b_par_mex);
}

static const mxArray *emlrt_marshallOut(const b_struct_T *u)
{
  static const int32_T iv[2] = { 1, 34 };

  static const int32_T iv1[2] = { 1094, 5 };

  static const int32_T iv2[2] = { 1094, 7 };

  static const char_T *sv1[5] = { "p", "tip_pos", "tip_RQ", "f_ex", "n_l" };

  static const char_T *sv[3] = { "var", "user_pars", "t_equil_i" };

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
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < 34; b_i++) {
    pData[i] = u->var[b_i];
    i++;
  }

  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, "var", b_y, 0);
  c_y = NULL;
  emlrtAssign(&c_y, emlrtCreateStructMatrix(1, 1, 5, sv1));
  emlrtSetFieldR2017b(c_y, 0, "p", b_emlrt_marshallOut(u->user_pars.p), 0);
  emlrtSetFieldR2017b(c_y, 0, "tip_pos", b_emlrt_marshallOut
                      (u->user_pars.tip_pos), 1);
  d_y = NULL;
  m = emlrtCreateNumericArray(2, &iv1[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < 5; b_i++) {
    for (c_i = 0; c_i < 1094; c_i++) {
      pData[i] = u->user_pars.tip_RQ[c_i + 1094 * b_i];
      i++;
    }
  }

  emlrtAssign(&d_y, m);
  emlrtSetFieldR2017b(c_y, 0, "tip_RQ", d_y, 2);
  e_y = NULL;
  m = emlrtCreateNumericArray(2, &iv2[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < 7; b_i++) {
    for (c_i = 0; c_i < 1094; c_i++) {
      pData[i] = u->user_pars.f_ex[c_i + 1094 * b_i];
      i++;
    }
  }

  emlrtAssign(&e_y, m);
  emlrtSetFieldR2017b(c_y, 0, "f_ex", e_y, 3);
  f_y = NULL;
  m = emlrtCreateDoubleScalar(u->user_pars.n_l);
  emlrtAssign(&f_y, m);
  emlrtSetFieldR2017b(c_y, 0, "n_l", f_y, 4);
  emlrtSetFieldR2017b(y, 0, "user_pars", c_y, 1);
  g_y = NULL;
  m = emlrtCreateDoubleScalar(u->t_equil_i);
  emlrtAssign(&g_y, m);
  emlrtSetFieldR2017b(y, 0, "t_equil_i", g_y, 2);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[5470])
{
  m_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[7658])
{
  n_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = o_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *z, const
  char_T *identifier))[12]
{
  emlrtMsgIdentifier thisId;
  real_T (*y)[12];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = j_emlrt_marshallIn(sp, emlrtAlias(z), &thisId);
  emlrtDestroyArray(&z);
  return y;
}
  static real_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[12]
{
  real_T (*y)[12];
  y = p_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[34])
{
  static const int32_T dims[2] = { 1, 34 };

  real_T (*r)[34];
  int32_T i;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r = (real_T (*)[34])emlrtMxGetData(src);
  for (i = 0; i < 34; i++) {
    ret[i] = (*r)[i];
  }

  emlrtDestroyArray(&src);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[4376])
{
  static const int32_T dims[2] = { 1094, 4 };

  real_T (*r)[4376];
  int32_T i;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r = (real_T (*)[4376])emlrtMxGetData(src);
  for (i = 0; i < 4376; i++) {
    ret[i] = (*r)[i];
  }

  emlrtDestroyArray(&src);
}

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[5470])
{
  static const int32_T dims[2] = { 1094, 5 };

  real_T (*r)[5470];
  int32_T i;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r = (real_T (*)[5470])emlrtMxGetData(src);
  for (i = 0; i < 5470; i++) {
    ret[i] = (*r)[i];
  }

  emlrtDestroyArray(&src);
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[7658])
{
  static const int32_T dims[2] = { 1094, 7 };

  real_T (*r)[7658];
  int32_T i;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r = (real_T (*)[7658])emlrtMxGetData(src);
  for (i = 0; i < 7658; i++) {
    ret[i] = (*r)[i];
  }

  emlrtDestroyArray(&src);
}

static real_T o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[12]
{
  static const int32_T dims[2] = { 1, 12 };

  real_T (*ret)[12];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[12])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  void EOM_eq_api(const mxArray * const prhs[1], const mxArray *plhs[1])
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  real_T (*res)[12];
  real_T (*z)[12];
  st.tls = emlrtRootTLSGlobal;
  res = (real_T (*)[12])mxMalloc(sizeof(real_T [12]));

  /* Marshall function inputs */
  z = i_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "z");

  /* Marshall in global variables */
  MEXGlobalSyncInFunction(&st);

  /* Invoke the target function */
  EOM_eq(&st, *z, *res);

  /* Marshall out global variables */
  MEXGlobalSyncOutFunction(true);

  /* Marshall function outputs */
  plhs[0] = c_emlrt_marshallOut(*res);
}

void MEXGlobalSyncInFunction(const emlrtStack *sp)
{
  const mxArray *tmp;

  /* Marshall in global variables */
  tmp = emlrtGetGlobalVariable("par_mex");
  if (tmp != NULL) {
    emlrt_marshallIn(sp, tmp, "par_mex", &par_mex);
    par_mex_dirty = 0U;
  }
}

void MEXGlobalSyncOutFunction(boolean_T skipDirtyCheck)
{
  /* Marshall out global variables */
  if (skipDirtyCheck || (par_mex_dirty != 0U)) {
    emlrtPutGlobalVariable("par_mex", emlrt_marshallOut(&par_mex));
  }
}

void emlrt_synchGlobalsFromML(const emlrtStack *sp)
{
  MEXGlobalSyncInFunction(sp);
  par_mex_dirty = 0U;
}

void emlrt_synchGlobalsToML(const emlrtStack *sp)
{
  (void)sp;
  MEXGlobalSyncOutFunction(false);
}

/* End of code generation (_coder_EOM_eq_api.c) */
