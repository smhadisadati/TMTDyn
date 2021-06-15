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
static uint64_T ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static const mxArray *b_emlrt_marshallOut(const real_T u_data[], const int32_T
  u_size[1]);
static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[8]);
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *z, const
  char_T *identifier))[24];
static boolean_T cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[24];
static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[34]);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_par, const
  char_T *identifier, struct0_T *y);
static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[4376]);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y);
static void fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[7658]);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[5470]);
static uint64_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void hb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[9]);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[8]);
static void ib_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[12]);
static boolean_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static void jb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2]);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[34]);
static void kb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[13]);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[4376]);
static void lb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[4]);
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[7658]);
static char_T mb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[5470]);
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[9]);
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[12]);
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T *y);
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2]);
static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[13]);
static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct2_T *y);
static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[4]);
static char_T v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static real_T (*x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[24];
static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);

/* Function Definitions */
static uint64_T ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  uint64_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "uint64", false, 0U, &dims);
  ret = *(uint64_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
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
  emlrtMsgIdentifier *msgId, real_T ret[8])
{
  static const int32_T dims[2] = { 1, 8 };

  real_T (*r0)[8];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r0 = (real_T (*)[8])emlrtMxGetData(src);
  memcpy(&ret[0], &(*r0)[0], sizeof(real_T) << 3);
  emlrtDestroyArray(&src);
}

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *z, const
  char_T *identifier))[24]
{
  real_T (*y)[24];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(z), &thisId);
  emlrtDestroyArray(&z);
  return y;
}
  static boolean_T cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  boolean_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "logical", false, 0U, &dims);
  ret = *emlrtMxGetLogicals(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[24]
{
  real_T (*y)[24];
  y = x_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId, real_T ret[34])
{
  static const int32_T dims[2] = { 1, 34 };

  real_T (*r1)[34];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r1 = (real_T (*)[34])emlrtMxGetData(src);
  memcpy(&ret[0], &(*r1)[0], 34U * sizeof(real_T));
  emlrtDestroyArray(&src);
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_par, const
  char_T *identifier, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  f_emlrt_marshallIn(sp, emlrtAlias(b_par), &thisId, y);
  emlrtDestroyArray(&b_par);
}

static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[4376])
{
  static const int32_T dims[2] = { 1094, 4 };

  real_T (*r2)[4376];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r2 = (real_T (*)[4376])emlrtMxGetData(src);
  memcpy(&ret[0], &(*r2)[0], 4376U * sizeof(real_T));
  emlrtDestroyArray(&src);
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[46] = { "sym", "timer", "elapsed_time",
    "derive", "derive_collect", "derive_mex", "opv", "Anim", "movie", "equil",
    "modal", "simdyn", "t_rep", "n_int", "n_animpoints", "n_datasample", "var",
    "p", "f_ex", "tip_exp", "tip_RQ", "t_exp", "t_exp_equil", "t_init",
    "t_final", "t_equil", "dt", "stepT", "fig", "skip", "animPause", "pause",
    "t_equil_i", "nq", "nlambda", "qf0", "n_m", "n_sd", "n_cn", "n_ex", "rom",
    "par_mex", "n_mass_anim", "n_ks_anim", "linetype", "t0" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 46, fieldNames, 0U, &dims);
  thisId.fIdentifier = "sym";
  g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "sym")),
                     &thisId);
  thisId.fIdentifier = "timer";
  y->timer = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1,
    "timer")), &thisId);
  thisId.fIdentifier = "elapsed_time";
  i_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2,
    "elapsed_time")), &thisId, y->elapsed_time);
  thisId.fIdentifier = "derive";
  y->derive = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3,
    "derive")), &thisId);
  thisId.fIdentifier = "derive_collect";
  y->derive_collect = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp,
    u, 0, 4, "derive_collect")), &thisId);
  thisId.fIdentifier = "derive_mex";
  y->derive_mex = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    5, "derive_mex")), &thisId);
  thisId.fIdentifier = "opv";
  y->opv = j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 6,
    "opv")), &thisId);
  thisId.fIdentifier = "Anim";
  y->Anim = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 7,
    "Anim")), &thisId);
  thisId.fIdentifier = "movie";
  y->movie = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 8,
    "movie")), &thisId);
  thisId.fIdentifier = "equil";
  y->equil = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 9,
    "equil")), &thisId);
  thisId.fIdentifier = "modal";
  y->modal = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 10,
    "modal")), &thisId);
  thisId.fIdentifier = "simdyn";
  y->simdyn = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 11,
    "simdyn")), &thisId);
  thisId.fIdentifier = "t_rep";
  y->t_rep = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 12,
    "t_rep")), &thisId);
  thisId.fIdentifier = "n_int";
  y->n_int = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 13,
    "n_int")), &thisId);
  thisId.fIdentifier = "n_animpoints";
  y->n_animpoints = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u,
    0, 14, "n_animpoints")), &thisId);
  thisId.fIdentifier = "n_datasample";
  y->n_datasample = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u,
    0, 15, "n_datasample")), &thisId);
  thisId.fIdentifier = "var";
  k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 16, "var")),
                     &thisId, y->var);
  thisId.fIdentifier = "p";
  l_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 17, "p")),
                     &thisId, y->p);
  thisId.fIdentifier = "f_ex";
  m_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 18, "f_ex")),
                     &thisId, y->f_ex);
  thisId.fIdentifier = "tip_exp";
  l_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 19, "tip_exp")),
                     &thisId, y->tip_exp);
  thisId.fIdentifier = "tip_RQ";
  n_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 20, "tip_RQ")),
                     &thisId, y->tip_RQ);
  thisId.fIdentifier = "t_exp";
  o_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 21, "t_exp")),
                     &thisId, y->t_exp);
  thisId.fIdentifier = "t_exp_equil";
  o_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 22,
    "t_exp_equil")), &thisId, y->t_exp_equil);
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
  p_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 35, "qf0")),
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
  q_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 40, "rom")),
                     &thisId, &y->rom);
  thisId.fIdentifier = "par_mex";
  t_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 41, "par_mex")),
                     &thisId, &y->par_mex);
  thisId.fIdentifier = "n_mass_anim";
  y->n_mass_anim = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u,
    0, 42, "n_mass_anim")), &thisId);
  thisId.fIdentifier = "n_ks_anim";
  y->n_ks_anim = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    43, "n_ks_anim")), &thisId);
  thisId.fIdentifier = "linetype";
  y->linetype = v_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    44, "linetype")), &thisId);
  thisId.fIdentifier = "t0";
  y->t0 = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 45,
    "t0")), &thisId);
  emlrtDestroyArray(&u);
}

static void fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[7658])
{
  static const int32_T dims[2] = { 1094, 7 };

  real_T (*r3)[7658];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r3 = (real_T (*)[7658])emlrtMxGetData(src);
  memcpy(&ret[0], &(*r3)[0], 7658U * sizeof(real_T));
  emlrtDestroyArray(&src);
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  y_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
}

static void gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[5470])
{
  static const int32_T dims[2] = { 1094, 5 };

  real_T (*r4)[5470];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r4 = (real_T (*)[5470])emlrtMxGetData(src);
  memcpy(&ret[0], &(*r4)[0], 5470U * sizeof(real_T));
  emlrtDestroyArray(&src);
}

static uint64_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  uint64_T y;
  y = ab_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void hb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[9])
{
  static const int32_T dims[2] = { 1, 9 };

  real_T (*r5)[9];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r5 = (real_T (*)[9])emlrtMxGetData(src);
  memcpy(&ret[0], &(*r5)[0], 9U * sizeof(real_T));
  emlrtDestroyArray(&src);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[8])
{
  bb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void ib_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[12])
{
  static const int32_T dims[2] = { 1, 12 };

  real_T (*r6)[12];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r6 = (real_T (*)[12])emlrtMxGetData(src);
  memcpy(&ret[0], &(*r6)[0], 12U * sizeof(real_T));
  emlrtDestroyArray(&src);
}

static boolean_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = cb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void jb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
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

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[34])
{
  db_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void kb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[13])
{
  static const int32_T dims[2] = { 1, 13 };

  real_T (*r8)[13];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r8 = (real_T (*)[13])emlrtMxGetData(src);
  memcpy(&ret[0], &(*r8)[0], 13U * sizeof(real_T));
  emlrtDestroyArray(&src);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[4376])
{
  eb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void lb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[4])
{
  static const int32_T dims[2] = { 1, 4 };

  real_T (*r9)[4];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r9 = (real_T (*)[4])emlrtMxGetData(src);
  ret[0] = (*r9)[0];
  ret[1] = (*r9)[1];
  ret[2] = (*r9)[2];
  ret[3] = (*r9)[3];
  emlrtDestroyArray(&src);
}

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[7658])
{
  fb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static char_T mb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  char_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 0U, &dims);
  emlrtImportCharR2015b(sp, src, &ret);
  emlrtDestroyArray(&src);
  return ret;
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[5470])
{
  gb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[9])
{
  hb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[12])
{
  ib_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[2] = { "mass", "sprdmp" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 2, fieldNames, 0U, &dims);
  thisId.fIdentifier = "mass";
  r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "mass")),
                     &thisId, y->mass);
  thisId.fIdentifier = "sprdmp";
  s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1, "sprdmp")),
                     &thisId, y->sprdmp);
  emlrtDestroyArray(&u);
}

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2])
{
  jb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[13])
{
  kb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct2_T *y)
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
  g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "sym")),
                     &thisId);
  thisId.fIdentifier = "timer";
  y->timer = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1,
    "timer")), &thisId);
  thisId.fIdentifier = "elapsed_time";
  u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2,
    "elapsed_time")), &thisId, y->elapsed_time);
  thisId.fIdentifier = "derive";
  y->derive = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3,
    "derive")), &thisId);
  thisId.fIdentifier = "derive_collect";
  y->derive_collect = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp,
    u, 0, 4, "derive_collect")), &thisId);
  thisId.fIdentifier = "derive_mex";
  y->derive_mex = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    5, "derive_mex")), &thisId);
  thisId.fIdentifier = "opv";
  y->opv = j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 6,
    "opv")), &thisId);
  thisId.fIdentifier = "Anim";
  y->Anim = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 7,
    "Anim")), &thisId);
  thisId.fIdentifier = "movie";
  y->movie = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 8,
    "movie")), &thisId);
  thisId.fIdentifier = "equil";
  y->equil = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 9,
    "equil")), &thisId);
  thisId.fIdentifier = "modal";
  y->modal = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 10,
    "modal")), &thisId);
  thisId.fIdentifier = "simdyn";
  y->simdyn = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 11,
    "simdyn")), &thisId);
  thisId.fIdentifier = "t_rep";
  y->t_rep = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 12,
    "t_rep")), &thisId);
  thisId.fIdentifier = "n_int";
  y->n_int = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 13,
    "n_int")), &thisId);
  thisId.fIdentifier = "n_animpoints";
  y->n_animpoints = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u,
    0, 14, "n_animpoints")), &thisId);
  thisId.fIdentifier = "n_datasample";
  y->n_datasample = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u,
    0, 15, "n_datasample")), &thisId);
  thisId.fIdentifier = "var";
  k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 16, "var")),
                     &thisId, y->var);
  thisId.fIdentifier = "p";
  l_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 17, "p")),
                     &thisId, y->p);
  thisId.fIdentifier = "f_ex";
  m_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 18, "f_ex")),
                     &thisId, y->f_ex);
  thisId.fIdentifier = "tip_exp";
  l_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 19, "tip_exp")),
                     &thisId, y->tip_exp);
  thisId.fIdentifier = "tip_RQ";
  n_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 20, "tip_RQ")),
                     &thisId, y->tip_RQ);
  thisId.fIdentifier = "t_exp";
  o_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 21, "t_exp")),
                     &thisId, y->t_exp);
  thisId.fIdentifier = "t_exp_equil";
  o_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 22,
    "t_exp_equil")), &thisId, y->t_exp_equil);
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
  p_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 35, "qf0")),
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
  q_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 40, "rom")),
                     &thisId, &y->rom);
  emlrtDestroyArray(&u);
}

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[4])
{
  lb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static char_T v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  char_T y;
  y = mb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[24]
{
  real_T (*ret)[24];
  static const int32_T dims[1] = { 24 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims);
  ret = (real_T (*)[24])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  static const int32_T dims[2] = { 0, 0 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

void EOM_api(EOMStackData *SD, const mxArray * const prhs[3], int32_T nlhs,
             const mxArray *plhs[1])
{
  real_T (*dz_data)[36];
  real_T t;
  real_T (*z)[24];
  int32_T dz_size[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;
  dz_data = (real_T (*)[36])mxMalloc(sizeof(real_T [36]));

  /* Marshall function inputs */
  t = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "t");
  z = c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "z");
  e_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "par", &SD->f0.par);

  /* Marshall in global variables */
  MEXGlobalSyncInFunction(&st);

  /* Invoke the target function */
  EOM(&st, t, *z, &SD->f0.par, *dz_data, dz_size);

  /* Marshall out global variables */
  MEXGlobalSyncOutFunction(true);

  /* Marshall function outputs */
  plhs[0] = b_emlrt_marshallOut(*dz_data, dz_size);
}

/* End of code generation (_coder_EOM_api.c) */
