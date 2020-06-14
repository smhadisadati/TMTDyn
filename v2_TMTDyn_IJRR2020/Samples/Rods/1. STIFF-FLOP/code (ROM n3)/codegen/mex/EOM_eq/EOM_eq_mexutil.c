/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EOM_eq_mexutil.c
 *
 * Code generation for function 'EOM_eq_mexutil'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "EOM_eq.h"
#include "EOM_eq_mexutil.h"
#include "EOM_eq_data.h"

/* Function Declarations */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[7658]);
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, b_struct_T *y);
static const mxArray *b_emlrt_marshallOut(const real_T u[4376]);
static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[5470]);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static const mxArray *c_emlrt_marshallOut(const real_T u[9]);
static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[9]);
static uint64_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[18]);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[4]);
static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2]);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_par_i, const
  char_T *identifier, b_struct_T *y);
static const mxArray *emlrt_marshallOut(const b_struct_T *u);
static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[19]);
static boolean_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[34]);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[4376]);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[7658]);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[5470]);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[9]);
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[18]);
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct_T *y);
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2]);
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[19]);
static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static uint64_T t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[4]);
static real_T v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static boolean_T w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[34]);
static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[4376]);

/* Function Definitions */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[7658])
{
  static const int32_T dims[2] = { 1094, 7 };

  real_T (*r3)[7658];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r3 = (real_T (*)[7658])emlrtMxGetData(src);
  memcpy(&ret[0], &(*r3)[0], 7658U * sizeof(real_T));
  emlrtDestroyArray(&src);
}

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, b_struct_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[41] = { "sym", "timer", "elapsed_time",
    "derive", "derive_collect", "derive_mex", "opv", "Anim", "movie", "equil",
    "modal", "simdyn", "t_rep", "n_int", "n_animpoints", "n_datasample", "var",
    "p", "f_ex", "tip_exp", "tip_RQ", "t_exp", "t_exp_equil", "t_init",
    "t_final", "t_equil", "dt", "stepT", "fig", "skip", "animPause", "pause",
    "t_equil_i", "nq", "nlambda", "qf0", "n_m", "n_sd", "n_cn", "n_ex", "rom" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 41, fieldNames, 0U, &dims);
  thisId.fIdentifier = "sym";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "sym")),
                     &thisId);
  thisId.fIdentifier = "timer";
  y->timer = d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1,
    "timer")), &thisId);
  thisId.fIdentifier = "elapsed_time";
  e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2,
    "elapsed_time")), &thisId, y->elapsed_time);
  thisId.fIdentifier = "derive";
  y->derive = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3,
    "derive")), &thisId);
  thisId.fIdentifier = "derive_collect";
  y->derive_collect = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp,
    u, 0, 4, "derive_collect")), &thisId);
  thisId.fIdentifier = "derive_mex";
  y->derive_mex = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    5, "derive_mex")), &thisId);
  thisId.fIdentifier = "opv";
  y->opv = g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 6,
    "opv")), &thisId);
  thisId.fIdentifier = "Anim";
  y->Anim = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 7,
    "Anim")), &thisId);
  thisId.fIdentifier = "movie";
  y->movie = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 8,
    "movie")), &thisId);
  thisId.fIdentifier = "equil";
  y->equil = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 9,
    "equil")), &thisId);
  thisId.fIdentifier = "modal";
  y->modal = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 10,
    "modal")), &thisId);
  thisId.fIdentifier = "simdyn";
  y->simdyn = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 11,
    "simdyn")), &thisId);
  thisId.fIdentifier = "t_rep";
  y->t_rep = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 12,
    "t_rep")), &thisId);
  thisId.fIdentifier = "n_int";
  y->n_int = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 13,
    "n_int")), &thisId);
  thisId.fIdentifier = "n_animpoints";
  y->n_animpoints = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u,
    0, 14, "n_animpoints")), &thisId);
  thisId.fIdentifier = "n_datasample";
  y->n_datasample = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u,
    0, 15, "n_datasample")), &thisId);
  thisId.fIdentifier = "var";
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 16, "var")),
                     &thisId, y->var);
  thisId.fIdentifier = "p";
  i_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 17, "p")),
                     &thisId, y->p);
  thisId.fIdentifier = "f_ex";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 18, "f_ex")),
                     &thisId, y->f_ex);
  thisId.fIdentifier = "tip_exp";
  i_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 19, "tip_exp")),
                     &thisId, y->tip_exp);
  thisId.fIdentifier = "tip_RQ";
  k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 20, "tip_RQ")),
                     &thisId, y->tip_RQ);
  thisId.fIdentifier = "t_exp";
  l_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 21, "t_exp")),
                     &thisId, y->t_exp);
  thisId.fIdentifier = "t_exp_equil";
  l_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 22,
    "t_exp_equil")), &thisId, y->t_exp_equil);
  thisId.fIdentifier = "t_init";
  y->t_init = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 23,
    "t_init")), &thisId);
  thisId.fIdentifier = "t_final";
  y->t_final = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    24, "t_final")), &thisId);
  thisId.fIdentifier = "t_equil";
  l_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 25, "t_equil")),
                     &thisId, y->t_equil);
  thisId.fIdentifier = "dt";
  y->dt = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 26,
    "dt")), &thisId);
  thisId.fIdentifier = "stepT";
  y->stepT = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 27,
    "stepT")), &thisId);
  thisId.fIdentifier = "fig";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 28, "fig")),
                     &thisId);
  thisId.fIdentifier = "skip";
  y->skip = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 29,
    "skip")), &thisId);
  thisId.fIdentifier = "animPause";
  y->animPause = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    30, "animPause")), &thisId);
  thisId.fIdentifier = "pause";
  y->pause = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 31,
    "pause")), &thisId);
  thisId.fIdentifier = "t_equil_i";
  y->t_equil_i = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    32, "t_equil_i")), &thisId);
  thisId.fIdentifier = "nq";
  y->nq = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 33,
    "nq")), &thisId);
  thisId.fIdentifier = "nlambda";
  y->nlambda = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    34, "nlambda")), &thisId);
  thisId.fIdentifier = "qf0";
  m_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 35, "qf0")),
                     &thisId, y->qf0);
  thisId.fIdentifier = "n_m";
  y->n_m = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 36,
    "n_m")), &thisId);
  thisId.fIdentifier = "n_sd";
  y->n_sd = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 37,
    "n_sd")), &thisId);
  thisId.fIdentifier = "n_cn";
  y->n_cn = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 38,
    "n_cn")), &thisId);
  thisId.fIdentifier = "n_ex";
  y->n_ex = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 39,
    "n_ex")), &thisId);
  thisId.fIdentifier = "rom";
  n_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 40, "rom")),
                     &thisId, &y->rom);
  emlrtDestroyArray(&u);
}

static const mxArray *b_emlrt_marshallOut(const real_T u[4376])
{
  const mxArray *y;
  const mxArray *m44;
  static const int32_T iv13[2] = { 1094, 4 };

  real_T *pData;
  int32_T i2;
  int32_T i;
  int32_T b_i;
  y = NULL;
  m44 = emlrtCreateNumericArray(2, iv13, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m44);
  i2 = 0;
  for (i = 0; i < 4; i++) {
    for (b_i = 0; b_i < 1094; b_i++) {
      pData[i2] = u[b_i + 1094 * i];
      i2++;
    }
  }

  emlrtAssign(&y, m44);
  return y;
}

static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[5470])
{
  static const int32_T dims[2] = { 1094, 5 };

  real_T (*r4)[5470];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r4 = (real_T (*)[5470])emlrtMxGetData(src);
  memcpy(&ret[0], &(*r4)[0], 5470U * sizeof(real_T));
  emlrtDestroyArray(&src);
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  s_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
}

static const mxArray *c_emlrt_marshallOut(const real_T u[9])
{
  const mxArray *y;
  const mxArray *m45;
  static const int32_T iv14[2] = { 1, 9 };

  real_T *pData;
  int32_T i3;
  int32_T i;
  y = NULL;
  m45 = emlrtCreateNumericArray(2, iv14, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m45);
  i3 = 0;
  for (i = 0; i < 9; i++) {
    pData[i3] = u[i];
    i3++;
  }

  emlrtAssign(&y, m45);
  return y;
}

static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[9])
{
  static const int32_T dims[2] = { 1, 9 };

  real_T (*r5)[9];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r5 = (real_T (*)[9])emlrtMxGetData(src);
  memcpy(&ret[0], &(*r5)[0], 9U * sizeof(real_T));
  emlrtDestroyArray(&src);
}

static uint64_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  uint64_T y;
  y = t_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[18])
{
  static const int32_T dims[2] = { 1, 18 };

  real_T (*r6)[18];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r6 = (real_T (*)[18])emlrtMxGetData(src);
  memcpy(&ret[0], &(*r6)[0], 18U * sizeof(real_T));
  emlrtDestroyArray(&src);
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[4])
{
  u_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2])
{
  static const int32_T dims[2] = { 1, 2 };

  real_T (*r7)[2];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r7 = (real_T (*)[2])emlrtMxGetData(src);
  ret[0] = (*r7)[0];
  ret[1] = (*r7)[1];
  emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_par_i, const
  char_T *identifier, b_struct_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(b_par_i), &thisId, y);
  emlrtDestroyArray(&b_par_i);
}

static const mxArray *emlrt_marshallOut(const b_struct_T *u)
{
  const mxArray *y;
  static const char * sv0[41] = { "sym", "timer", "elapsed_time", "derive",
    "derive_collect", "derive_mex", "opv", "Anim", "movie", "equil", "modal",
    "simdyn", "t_rep", "n_int", "n_animpoints", "n_datasample", "var", "p",
    "f_ex", "tip_exp", "tip_RQ", "t_exp", "t_exp_equil", "t_init", "t_final",
    "t_equil", "dt", "stepT", "fig", "skip", "animPause", "pause", "t_equil_i",
    "nq", "nlambda", "qf0", "n_m", "n_sd", "n_cn", "n_ex", "rom" };

  const mxArray *b_y;
  const mxArray *m7;
  static const int32_T iv4[2] = { 0, 0 };

  const mxArray *m8;
  const mxArray *m9;
  static const int32_T iv5[2] = { 1, 4 };

  real_T *pData;
  const mxArray *m10;
  const mxArray *m11;
  const mxArray *m12;
  const mxArray *m13;
  const mxArray *m14;
  const mxArray *m15;
  const mxArray *m16;
  const mxArray *m17;
  const mxArray *m18;
  const mxArray *m19;
  const mxArray *m20;
  const mxArray *m21;
  const mxArray *m22;
  const mxArray *m23;
  static const int32_T iv6[2] = { 1, 34 };

  real_T *b_pData;
  int32_T i1;
  int32_T i;
  const mxArray *m24;
  static const int32_T iv7[2] = { 1094, 7 };

  real_T *c_pData;
  int32_T b_i;
  const mxArray *m25;
  static const int32_T iv8[2] = { 1094, 5 };

  real_T *d_pData;
  const mxArray *m26;
  const mxArray *m27;
  const mxArray *m28;
  const mxArray *m29;
  const mxArray *m30;
  static const int32_T iv9[2] = { 0, 0 };

  const mxArray *m31;
  const mxArray *m32;
  const mxArray *m33;
  const mxArray *m34;
  const mxArray *m35;
  const mxArray *m36;
  const mxArray *m37;
  static const int32_T iv10[2] = { 1, 18 };

  real_T *e_pData;
  const mxArray *m38;
  const mxArray *m39;
  const mxArray *m40;
  const mxArray *m41;
  static const char * sv1[2] = { "mass", "sprdmp" };

  const mxArray *c_y;
  const mxArray *m42;
  static const int32_T iv11[2] = { 1, 2 };

  real_T *f_pData;
  const mxArray *m43;
  static const int32_T iv12[2] = { 1, 19 };

  real_T *g_pData;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 41, sv0));
  b_y = NULL;
  m7 = emlrtCreateNumericArray(2, iv4, mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&b_y, m7);
  emlrtSetFieldR2017b(y, 0, "sym", b_y, 0);
  b_y = NULL;
  m8 = emlrtCreateNumericMatrix(1, 1, mxUINT64_CLASS, mxREAL);
  *(uint64_T *)emlrtMxGetData(m8) = u->timer;
  emlrtAssign(&b_y, m8);
  emlrtSetFieldR2017b(y, 0, "timer", b_y, 1);
  b_y = NULL;
  m9 = emlrtCreateNumericArray(2, iv5, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m9);
  pData[0] = u->elapsed_time[0];
  pData[1] = u->elapsed_time[1];
  pData[2] = u->elapsed_time[2];
  pData[3] = u->elapsed_time[3];
  emlrtAssign(&b_y, m9);
  emlrtSetFieldR2017b(y, 0, "elapsed_time", b_y, 2);
  b_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->derive);
  emlrtAssign(&b_y, m10);
  emlrtSetFieldR2017b(y, 0, "derive", b_y, 3);
  b_y = NULL;
  m11 = emlrtCreateDoubleScalar(u->derive_collect);
  emlrtAssign(&b_y, m11);
  emlrtSetFieldR2017b(y, 0, "derive_collect", b_y, 4);
  b_y = NULL;
  m12 = emlrtCreateDoubleScalar(u->derive_mex);
  emlrtAssign(&b_y, m12);
  emlrtSetFieldR2017b(y, 0, "derive_mex", b_y, 5);
  b_y = NULL;
  m13 = emlrtCreateLogicalScalar(u->opv);
  emlrtAssign(&b_y, m13);
  emlrtSetFieldR2017b(y, 0, "opv", b_y, 6);
  b_y = NULL;
  m14 = emlrtCreateDoubleScalar(u->Anim);
  emlrtAssign(&b_y, m14);
  emlrtSetFieldR2017b(y, 0, "Anim", b_y, 7);
  b_y = NULL;
  m15 = emlrtCreateDoubleScalar(u->movie);
  emlrtAssign(&b_y, m15);
  emlrtSetFieldR2017b(y, 0, "movie", b_y, 8);
  b_y = NULL;
  m16 = emlrtCreateDoubleScalar(u->equil);
  emlrtAssign(&b_y, m16);
  emlrtSetFieldR2017b(y, 0, "equil", b_y, 9);
  b_y = NULL;
  m17 = emlrtCreateDoubleScalar(u->modal);
  emlrtAssign(&b_y, m17);
  emlrtSetFieldR2017b(y, 0, "modal", b_y, 10);
  b_y = NULL;
  m18 = emlrtCreateDoubleScalar(u->simdyn);
  emlrtAssign(&b_y, m18);
  emlrtSetFieldR2017b(y, 0, "simdyn", b_y, 11);
  b_y = NULL;
  m19 = emlrtCreateDoubleScalar(u->t_rep);
  emlrtAssign(&b_y, m19);
  emlrtSetFieldR2017b(y, 0, "t_rep", b_y, 12);
  b_y = NULL;
  m20 = emlrtCreateDoubleScalar(u->n_int);
  emlrtAssign(&b_y, m20);
  emlrtSetFieldR2017b(y, 0, "n_int", b_y, 13);
  b_y = NULL;
  m21 = emlrtCreateDoubleScalar(u->n_animpoints);
  emlrtAssign(&b_y, m21);
  emlrtSetFieldR2017b(y, 0, "n_animpoints", b_y, 14);
  b_y = NULL;
  m22 = emlrtCreateDoubleScalar(u->n_datasample);
  emlrtAssign(&b_y, m22);
  emlrtSetFieldR2017b(y, 0, "n_datasample", b_y, 15);
  b_y = NULL;
  m23 = emlrtCreateNumericArray(2, iv6, mxDOUBLE_CLASS, mxREAL);
  b_pData = emlrtMxGetPr(m23);
  i1 = 0;
  for (i = 0; i < 34; i++) {
    b_pData[i1] = u->var[i];
    i1++;
  }

  emlrtAssign(&b_y, m23);
  emlrtSetFieldR2017b(y, 0, "var", b_y, 16);
  emlrtSetFieldR2017b(y, 0, "p", b_emlrt_marshallOut(u->p), 17);
  b_y = NULL;
  m24 = emlrtCreateNumericArray(2, iv7, mxDOUBLE_CLASS, mxREAL);
  c_pData = emlrtMxGetPr(m24);
  i1 = 0;
  for (i = 0; i < 7; i++) {
    for (b_i = 0; b_i < 1094; b_i++) {
      c_pData[i1] = u->f_ex[b_i + 1094 * i];
      i1++;
    }
  }

  emlrtAssign(&b_y, m24);
  emlrtSetFieldR2017b(y, 0, "f_ex", b_y, 18);
  emlrtSetFieldR2017b(y, 0, "tip_exp", b_emlrt_marshallOut(u->tip_exp), 19);
  b_y = NULL;
  m25 = emlrtCreateNumericArray(2, iv8, mxDOUBLE_CLASS, mxREAL);
  d_pData = emlrtMxGetPr(m25);
  i1 = 0;
  for (i = 0; i < 5; i++) {
    for (b_i = 0; b_i < 1094; b_i++) {
      d_pData[i1] = u->tip_RQ[b_i + 1094 * i];
      i1++;
    }
  }

  emlrtAssign(&b_y, m25);
  emlrtSetFieldR2017b(y, 0, "tip_RQ", b_y, 20);
  emlrtSetFieldR2017b(y, 0, "t_exp", c_emlrt_marshallOut(u->t_exp), 21);
  emlrtSetFieldR2017b(y, 0, "t_exp_equil", c_emlrt_marshallOut(u->t_exp_equil),
                      22);
  b_y = NULL;
  m26 = emlrtCreateDoubleScalar(u->t_init);
  emlrtAssign(&b_y, m26);
  emlrtSetFieldR2017b(y, 0, "t_init", b_y, 23);
  b_y = NULL;
  m27 = emlrtCreateDoubleScalar(u->t_final);
  emlrtAssign(&b_y, m27);
  emlrtSetFieldR2017b(y, 0, "t_final", b_y, 24);
  emlrtSetFieldR2017b(y, 0, "t_equil", c_emlrt_marshallOut(u->t_equil), 25);
  b_y = NULL;
  m28 = emlrtCreateDoubleScalar(u->dt);
  emlrtAssign(&b_y, m28);
  emlrtSetFieldR2017b(y, 0, "dt", b_y, 26);
  b_y = NULL;
  m29 = emlrtCreateDoubleScalar(u->stepT);
  emlrtAssign(&b_y, m29);
  emlrtSetFieldR2017b(y, 0, "stepT", b_y, 27);
  b_y = NULL;
  m30 = emlrtCreateNumericArray(2, iv9, mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&b_y, m30);
  emlrtSetFieldR2017b(y, 0, "fig", b_y, 28);
  b_y = NULL;
  m31 = emlrtCreateDoubleScalar(u->skip);
  emlrtAssign(&b_y, m31);
  emlrtSetFieldR2017b(y, 0, "skip", b_y, 29);
  b_y = NULL;
  m32 = emlrtCreateDoubleScalar(u->animPause);
  emlrtAssign(&b_y, m32);
  emlrtSetFieldR2017b(y, 0, "animPause", b_y, 30);
  b_y = NULL;
  m33 = emlrtCreateDoubleScalar(u->pause);
  emlrtAssign(&b_y, m33);
  emlrtSetFieldR2017b(y, 0, "pause", b_y, 31);
  b_y = NULL;
  m34 = emlrtCreateDoubleScalar(u->t_equil_i);
  emlrtAssign(&b_y, m34);
  emlrtSetFieldR2017b(y, 0, "t_equil_i", b_y, 32);
  b_y = NULL;
  m35 = emlrtCreateDoubleScalar(u->nq);
  emlrtAssign(&b_y, m35);
  emlrtSetFieldR2017b(y, 0, "nq", b_y, 33);
  b_y = NULL;
  m36 = emlrtCreateDoubleScalar(u->nlambda);
  emlrtAssign(&b_y, m36);
  emlrtSetFieldR2017b(y, 0, "nlambda", b_y, 34);
  b_y = NULL;
  m37 = emlrtCreateNumericArray(2, iv10, mxDOUBLE_CLASS, mxREAL);
  e_pData = emlrtMxGetPr(m37);
  i1 = 0;
  for (i = 0; i < 18; i++) {
    e_pData[i1] = u->qf0[i];
    i1++;
  }

  emlrtAssign(&b_y, m37);
  emlrtSetFieldR2017b(y, 0, "qf0", b_y, 35);
  b_y = NULL;
  m38 = emlrtCreateDoubleScalar(u->n_m);
  emlrtAssign(&b_y, m38);
  emlrtSetFieldR2017b(y, 0, "n_m", b_y, 36);
  b_y = NULL;
  m39 = emlrtCreateDoubleScalar(u->n_sd);
  emlrtAssign(&b_y, m39);
  emlrtSetFieldR2017b(y, 0, "n_sd", b_y, 37);
  b_y = NULL;
  m40 = emlrtCreateDoubleScalar(u->n_cn);
  emlrtAssign(&b_y, m40);
  emlrtSetFieldR2017b(y, 0, "n_cn", b_y, 38);
  b_y = NULL;
  m41 = emlrtCreateDoubleScalar(u->n_ex);
  emlrtAssign(&b_y, m41);
  emlrtSetFieldR2017b(y, 0, "n_ex", b_y, 39);
  b_y = NULL;
  emlrtAssign(&b_y, emlrtCreateStructMatrix(1, 1, 2, sv1));
  c_y = NULL;
  m42 = emlrtCreateNumericArray(2, iv11, mxDOUBLE_CLASS, mxREAL);
  f_pData = emlrtMxGetPr(m42);
  f_pData[0] = u->rom.mass[0];
  f_pData[1] = u->rom.mass[1];
  emlrtAssign(&c_y, m42);
  emlrtSetFieldR2017b(b_y, 0, "mass", c_y, 0);
  c_y = NULL;
  m43 = emlrtCreateNumericArray(2, iv12, mxDOUBLE_CLASS, mxREAL);
  g_pData = emlrtMxGetPr(m43);
  i1 = 0;
  for (i = 0; i < 19; i++) {
    g_pData[i1] = u->rom.sprdmp[i];
    i1++;
  }

  emlrtAssign(&c_y, m43);
  emlrtSetFieldR2017b(b_y, 0, "sprdmp", c_y, 1);
  emlrtSetFieldR2017b(y, 0, "rom", b_y, 40);
  return y;
}

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = v_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[19])
{
  static const int32_T dims[2] = { 1, 19 };

  real_T (*r8)[19];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r8 = (real_T (*)[19])emlrtMxGetData(src);
  memcpy(&ret[0], &(*r8)[0], 19U * sizeof(real_T));
  emlrtDestroyArray(&src);
}

static boolean_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = w_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[34])
{
  x_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[4376])
{
  y_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[7658])
{
  ab_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[5470])
{
  bb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[9])
{
  cb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[18])
{
  db_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[2] = { "mass", "sprdmp" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 2, fieldNames, 0U, &dims);
  thisId.fIdentifier = "mass";
  o_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "mass")),
                     &thisId, y->mass);
  thisId.fIdentifier = "sprdmp";
  p_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1, "sprdmp")),
                     &thisId, y->sprdmp);
  emlrtDestroyArray(&u);
}

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2])
{
  eb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[19])
{
  fb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  static const int32_T dims[2] = { 0, 0 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

static uint64_T t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  uint64_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "uint64", false, 0U, &dims);
  ret = *(uint64_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[4])
{
  static const int32_T dims[2] = { 1, 4 };

  real_T (*r0)[4];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r0 = (real_T (*)[4])emlrtMxGetData(src);
  ret[0] = (*r0)[0];
  ret[1] = (*r0)[1];
  ret[2] = (*r0)[2];
  ret[3] = (*r0)[3];
  emlrtDestroyArray(&src);
}

static real_T v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static boolean_T w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  boolean_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "logical", false, 0U, &dims);
  ret = *emlrtMxGetLogicals(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[34])
{
  static const int32_T dims[2] = { 1, 34 };

  real_T (*r1)[34];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r1 = (real_T (*)[34])emlrtMxGetData(src);
  memcpy(&ret[0], &(*r1)[0], 34U * sizeof(real_T));
  emlrtDestroyArray(&src);
}

static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[4376])
{
  static const int32_T dims[2] = { 1094, 4 };

  real_T (*r2)[4376];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r2 = (real_T (*)[4376])emlrtMxGetData(src);
  memcpy(&ret[0], &(*r2)[0], 4376U * sizeof(real_T));
  emlrtDestroyArray(&src);
}

void MEXGlobalSyncInFunction(const emlrtStack *sp)
{
  const mxArray *tmp;

  /* Marshall in global variables */
  tmp = emlrtGetGlobalVariable("par_i");
  if (tmp != NULL) {
    emlrt_marshallIn(sp, tmp, "par_i", &par_i);
    par_i_dirty = 0U;
  }
}

void MEXGlobalSyncOutFunction(boolean_T skipDirtyCheck)
{
  /* Marshall out global variables */
  if (skipDirtyCheck || (par_i_dirty != 0U)) {
    emlrtPutGlobalVariable("par_i", emlrt_marshallOut(&par_i));
  }
}

void emlrt_checkEscapedGlobals(void)
{
  par_i_dirty |= par_i_dirty >> 1U;
}

void emlrt_synchGlobalsFromML(const emlrtStack *sp)
{
  MEXGlobalSyncInFunction(sp);
  par_i_dirty = 0U;
}

void emlrt_synchGlobalsToML(const emlrtStack *sp)
{
  (void)sp;
  MEXGlobalSyncOutFunction(false);
}

/* End of code generation (EOM_eq_mexutil.c) */
