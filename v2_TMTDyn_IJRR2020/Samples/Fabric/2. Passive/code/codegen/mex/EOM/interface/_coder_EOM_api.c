/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_EOM_api.c
 *
 * Code generation for function '_coder_EOM_api'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "EOM.h"
#include "_coder_EOM_api.h"
#include "EOM_mexutil.h"
#include "EOM_data.h"

/* Function Declarations */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[202]);
static const mxArray *b_emlrt_marshallOut(const real_T u_data[], const int32_T
  u_size[1]);
static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[606]);
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *z, const
  char_T *identifier))[206];
static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[91]);
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[206];
static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[16]);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *par, const
  char_T *identifier, struct0_T *y);
static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[115]);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y);
static char_T fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static uint64_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[6]);
static boolean_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[5]);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[202]);
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[606]);
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[91]);
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T *y);
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[16]);
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[115]);
static char_T r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static real_T (*t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[206];
static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static uint64_T v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[6]);
static boolean_T x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[5]);

/* Function Definitions */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[202])
{
  static const int32_T dims[2] = { 1, 202 };

  real_T (*r2)[202];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r2 = (real_T (*)[202])emlrtMxGetData(src);
  memcpy(&ret[0], &(*r2)[0], 202U * sizeof(real_T));
  emlrtDestroyArray(&src);
}

static const mxArray *b_emlrt_marshallOut(const real_T u_data[], const int32_T
  u_size[1])
{
  const mxArray *y;
  const mxArray *m8;
  static const int32_T iv4[1] = { 0 };

  y = NULL;
  m8 = emlrtCreateNumericArray(1, iv4, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m8, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m8, u_size, 1);
  emlrtAssign(&y, m8);
  return y;
}

static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[606])
{
  static const int32_T dims[2] = { 202, 3 };

  real_T (*r3)[606];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r3 = (real_T (*)[606])emlrtMxGetData(src);
  memcpy(&ret[0], &(*r3)[0], 606U * sizeof(real_T));
  emlrtDestroyArray(&src);
}

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *z, const
  char_T *identifier))[206]
{
  real_T (*y)[206];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(z), &thisId);
  emlrtDestroyArray(&z);
  return y;
}
  static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId, real_T ret[91])
{
  static const int32_T dims[2] = { 1, 91 };

  real_T (*r4)[91];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r4 = (real_T (*)[91])emlrtMxGetData(src);
  memcpy(&ret[0], &(*r4)[0], 91U * sizeof(real_T));
  emlrtDestroyArray(&src);
}

static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[206]
{
  real_T (*y)[206];
  y = t_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId, real_T ret[16])
{
  static const int32_T dims[2] = { 1, 16 };

  real_T (*r5)[16];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r5 = (real_T (*)[16])emlrtMxGetData(src);
  memcpy(&ret[0], &(*r5)[0], sizeof(real_T) << 4);
  emlrtDestroyArray(&src);
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *par, const
  char_T *identifier, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  f_emlrt_marshallIn(sp, emlrtAlias(par), &thisId, y);
  emlrtDestroyArray(&par);
}

static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[115])
{
  static const int32_T dims[2] = { 1, 115 };

  real_T (*r6)[115];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r6 = (real_T (*)[115])emlrtMxGetData(src);
  memcpy(&ret[0], &(*r6)[0], 115U * sizeof(real_T));
  emlrtDestroyArray(&src);
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[45] = { "sym", "timer", "elapsed_time",
    "exp_case", "derive", "derive_collect", "derive_mex", "opv", "Anim", "movie",
    "equil", "modal", "simdyn", "t_rep", "n_int", "n_animpoints", "n_datasample",
    "var", "var2", "sample_t", "t_exp", "r_arm", "r_fab", "t_init", "t_final",
    "t_equil", "dt", "stepT", "fig", "skip", "animPause", "pause", "t_equil_i",
    "nq", "nlambda", "qf0", "n_m", "n_sd", "n_cn", "n_ex", "rom", "n_mass_anim",
    "n_ks_anim", "linetype", "t0" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 45, fieldNames, 0U, &dims);
  thisId.fIdentifier = "sym";
  g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "sym")),
                     &thisId);
  thisId.fIdentifier = "timer";
  y->timer = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1,
    "timer")), &thisId);
  thisId.fIdentifier = "elapsed_time";
  i_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2,
    "elapsed_time")), &thisId, y->elapsed_time);
  thisId.fIdentifier = "exp_case";
  y->exp_case = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    3, "exp_case")), &thisId);
  thisId.fIdentifier = "derive";
  y->derive = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 4,
    "derive")), &thisId);
  thisId.fIdentifier = "derive_collect";
  y->derive_collect = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp,
    u, 0, 5, "derive_collect")), &thisId);
  thisId.fIdentifier = "derive_mex";
  y->derive_mex = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    6, "derive_mex")), &thisId);
  thisId.fIdentifier = "opv";
  y->opv = j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 7,
    "opv")), &thisId);
  thisId.fIdentifier = "Anim";
  y->Anim = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 8,
    "Anim")), &thisId);
  thisId.fIdentifier = "movie";
  y->movie = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 9,
    "movie")), &thisId);
  thisId.fIdentifier = "equil";
  y->equil = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 10,
    "equil")), &thisId);
  thisId.fIdentifier = "modal";
  y->modal = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 11,
    "modal")), &thisId);
  thisId.fIdentifier = "simdyn";
  y->simdyn = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 12,
    "simdyn")), &thisId);
  thisId.fIdentifier = "t_rep";
  y->t_rep = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 13,
    "t_rep")), &thisId);
  thisId.fIdentifier = "n_int";
  y->n_int = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 14,
    "n_int")), &thisId);
  thisId.fIdentifier = "n_animpoints";
  y->n_animpoints = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u,
    0, 15, "n_animpoints")), &thisId);
  thisId.fIdentifier = "n_datasample";
  y->n_datasample = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u,
    0, 16, "n_datasample")), &thisId);
  thisId.fIdentifier = "var";
  i_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 17, "var")),
                     &thisId, y->var);
  thisId.fIdentifier = "var2";
  k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 18, "var2")),
                     &thisId, y->var2);
  thisId.fIdentifier = "sample_t";
  y->sample_t = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    19, "sample_t")), &thisId);
  thisId.fIdentifier = "t_exp";
  l_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 20, "t_exp")),
                     &thisId, y->t_exp);
  thisId.fIdentifier = "r_arm";
  m_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 21, "r_arm")),
                     &thisId, y->r_arm);
  thisId.fIdentifier = "r_fab";
  m_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 22, "r_fab")),
                     &thisId, y->r_fab);
  thisId.fIdentifier = "t_init";
  y->t_init = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 23,
    "t_init")), &thisId);
  thisId.fIdentifier = "t_final";
  y->t_final = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    24, "t_final")), &thisId);
  thisId.fIdentifier = "t_equil";
  y->t_equil = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    25, "t_equil")), &thisId);
  thisId.fIdentifier = "dt";
  y->dt = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 26,
    "dt")), &thisId);
  thisId.fIdentifier = "stepT";
  y->stepT = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 27,
    "stepT")), &thisId);
  thisId.fIdentifier = "fig";
  g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 28, "fig")),
                     &thisId);
  thisId.fIdentifier = "skip";
  y->skip = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 29,
    "skip")), &thisId);
  thisId.fIdentifier = "animPause";
  y->animPause = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    30, "animPause")), &thisId);
  thisId.fIdentifier = "pause";
  y->pause = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 31,
    "pause")), &thisId);
  thisId.fIdentifier = "t_equil_i";
  y->t_equil_i = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    32, "t_equil_i")), &thisId);
  thisId.fIdentifier = "nq";
  y->nq = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 33,
    "nq")), &thisId);
  thisId.fIdentifier = "nlambda";
  y->nlambda = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    34, "nlambda")), &thisId);
  thisId.fIdentifier = "qf0";
  n_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 35, "qf0")),
                     &thisId, y->qf0);
  thisId.fIdentifier = "n_m";
  y->n_m = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 36,
    "n_m")), &thisId);
  thisId.fIdentifier = "n_sd";
  y->n_sd = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 37,
    "n_sd")), &thisId);
  thisId.fIdentifier = "n_cn";
  y->n_cn = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 38,
    "n_cn")), &thisId);
  thisId.fIdentifier = "n_ex";
  y->n_ex = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 39,
    "n_ex")), &thisId);
  thisId.fIdentifier = "rom";
  o_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 40, "rom")),
                     &thisId, &y->rom);
  thisId.fIdentifier = "n_mass_anim";
  y->n_mass_anim = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u,
    0, 41, "n_mass_anim")), &thisId);
  thisId.fIdentifier = "n_ks_anim";
  y->n_ks_anim = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    42, "n_ks_anim")), &thisId);
  thisId.fIdentifier = "linetype";
  y->linetype = r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    43, "linetype")), &thisId);
  thisId.fIdentifier = "t0";
  y->t0 = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 44,
    "t0")), &thisId);
  emlrtDestroyArray(&u);
}

static char_T fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  char_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 0U, &dims);
  emlrtImportCharR2015b(sp, src, &ret);
  emlrtDestroyArray(&src);
  return ret;
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  u_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
}

static uint64_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  uint64_T y;
  y = v_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[6])
{
  w_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static boolean_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = x_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[5])
{
  y_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[202])
{
  ab_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[606])
{
  bb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[91])
{
  cb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[2] = { "mass", "sprdmp" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 2, fieldNames, 0U, &dims);
  thisId.fIdentifier = "mass";
  p_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "mass")),
                     &thisId, y->mass);
  thisId.fIdentifier = "sprdmp";
  q_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1, "sprdmp")),
                     &thisId, y->sprdmp);
  emlrtDestroyArray(&u);
}

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[16])
{
  db_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[115])
{
  eb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static char_T r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  char_T y;
  y = fb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[206]
{
  real_T (*ret)[206];
  static const int32_T dims[1] = { 206 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims);
  ret = (real_T (*)[206])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  static const int32_T dims[2] = { 0, 0 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

static uint64_T v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  uint64_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "uint64", false, 0U, &dims);
  ret = *(uint64_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[6])
{
  static const int32_T dims[2] = { 1, 6 };

  real_T (*r0)[6];
  int32_T i2;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r0 = (real_T (*)[6])emlrtMxGetData(src);
  for (i2 = 0; i2 < 6; i2++) {
    ret[i2] = (*r0)[i2];
  }

  emlrtDestroyArray(&src);
}

static boolean_T x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  boolean_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "logical", false, 0U, &dims);
  ret = *emlrtMxGetLogicals(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[5])
{
  static const int32_T dims[2] = { 1, 5 };

  real_T (*r1)[5];
  int32_T i3;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r1 = (real_T (*)[5])emlrtMxGetData(src);
  for (i3 = 0; i3 < 5; i3++) {
    ret[i3] = (*r1)[i3];
  }

  emlrtDestroyArray(&src);
}

void EOM_api(EOMStackData *SD, const mxArray * const prhs[3], int32_T nlhs,
             const mxArray *plhs[1])
{
  real_T (*dz_data)[309];
  real_T t;
  real_T (*z)[206];
  struct0_T par;
  int32_T dz_size[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;
  dz_data = (real_T (*)[309])mxMalloc(sizeof(real_T [309]));

  /* Marshall function inputs */
  t = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "t");
  z = c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "z");
  e_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "par", &par);

  /* Marshall in global variables */
  MEXGlobalSyncInFunction(&st);

  /* Invoke the target function */
  EOM(SD, &st, t, *z, &par, *dz_data, dz_size);

  /* Marshall out global variables */
  MEXGlobalSyncOutFunction(true);

  /* Marshall function outputs */
  plhs[0] = b_emlrt_marshallOut(*dz_data, dz_size);
}

/* End of code generation (_coder_EOM_api.c) */
