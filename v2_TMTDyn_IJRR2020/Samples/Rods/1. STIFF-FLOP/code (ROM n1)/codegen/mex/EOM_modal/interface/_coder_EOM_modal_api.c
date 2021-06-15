/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_EOM_modal_api.c
 *
 * Code generation for function '_coder_EOM_modal_api'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "EOM_modal.h"
#include "_coder_EOM_modal_api.h"
#include "EOM_modal_data.h"

/* Function Declarations */
static boolean_T ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[6];
static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[34]);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *par, const
  char_T *identifier, struct0_T *y);
static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[4376]);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y);
static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[7658]);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[5470]);
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *z, const
  char_T *identifier))[6];
static const mxArray *emlrt_marshallOut(const real_T u[36]);
static uint64_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[9]);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[7]);
static void gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[6]);
static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void hb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2]);
static boolean_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static void ib_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[4]);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[34]);
static char_T jb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[4376]);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[7658]);
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[5470]);
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[9]);
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[6]);
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T *y);
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2]);
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct2_T *y);
static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[4]);
static char_T t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static real_T (*u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[6];
static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static uint64_T w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[7]);
static real_T y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);

/* Function Definitions */
static boolean_T ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  boolean_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "logical", false, 0U, &dims);
  ret = *emlrtMxGetLogicals(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[6]
{
  real_T (*y)[6];
  y = u_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId, real_T ret[34])
{
  static const int32_T dims[2] = { 1, 34 };

  real_T (*r1)[34];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r1 = (real_T (*)[34])emlrtMxGetData(src);
  memcpy(&ret[0], &(*r1)[0], 34U * sizeof(real_T));
  emlrtDestroyArray(&src);
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *par, const
  char_T *identifier, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(par), &thisId, y);
  emlrtDestroyArray(&par);
}

static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[4376])
{
  static const int32_T dims[2] = { 1094, 4 };

  real_T (*r2)[4376];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r2 = (real_T (*)[4376])emlrtMxGetData(src);
  memcpy(&ret[0], &(*r2)[0], 4376U * sizeof(real_T));
  emlrtDestroyArray(&src);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[45] = { "sym", "timer", "elapsed_time",
    "derive", "derive_collect", "derive_mex", "opv", "Anim", "movie", "equil",
    "modal", "simdyn", "t_rep", "n_int", "n_animpoints", "n_datasample", "var",
    "p", "f_ex", "tip_exp", "tip_RQ", "t_exp", "t_exp_equil", "t_init",
    "t_final", "t_equil", "dt", "stepT", "fig", "skip", "animPause", "pause",
    "t_equil_i", "nq", "nlambda", "qf0", "n_m", "n_sd", "n_cn", "n_ex", "rom",
    "par_mex", "n_mass_anim", "n_ks_anim", "linetype" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 45, fieldNames, 0U, &dims);
  thisId.fIdentifier = "sym";
  e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "sym")),
                     &thisId);
  thisId.fIdentifier = "timer";
  y->timer = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1,
    "timer")), &thisId);
  thisId.fIdentifier = "elapsed_time";
  g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2,
    "elapsed_time")), &thisId, y->elapsed_time);
  thisId.fIdentifier = "derive";
  y->derive = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3,
    "derive")), &thisId);
  thisId.fIdentifier = "derive_collect";
  y->derive_collect = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp,
    u, 0, 4, "derive_collect")), &thisId);
  thisId.fIdentifier = "derive_mex";
  y->derive_mex = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    5, "derive_mex")), &thisId);
  thisId.fIdentifier = "opv";
  y->opv = i_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 6,
    "opv")), &thisId);
  thisId.fIdentifier = "Anim";
  y->Anim = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 7,
    "Anim")), &thisId);
  thisId.fIdentifier = "movie";
  y->movie = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 8,
    "movie")), &thisId);
  thisId.fIdentifier = "equil";
  y->equil = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 9,
    "equil")), &thisId);
  thisId.fIdentifier = "modal";
  y->modal = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 10,
    "modal")), &thisId);
  thisId.fIdentifier = "simdyn";
  y->simdyn = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 11,
    "simdyn")), &thisId);
  thisId.fIdentifier = "t_rep";
  y->t_rep = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 12,
    "t_rep")), &thisId);
  thisId.fIdentifier = "n_int";
  y->n_int = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 13,
    "n_int")), &thisId);
  thisId.fIdentifier = "n_animpoints";
  y->n_animpoints = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u,
    0, 14, "n_animpoints")), &thisId);
  thisId.fIdentifier = "n_datasample";
  y->n_datasample = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u,
    0, 15, "n_datasample")), &thisId);
  thisId.fIdentifier = "var";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 16, "var")),
                     &thisId, y->var);
  thisId.fIdentifier = "p";
  k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 17, "p")),
                     &thisId, y->p);
  thisId.fIdentifier = "f_ex";
  l_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 18, "f_ex")),
                     &thisId, y->f_ex);
  thisId.fIdentifier = "tip_exp";
  k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 19, "tip_exp")),
                     &thisId, y->tip_exp);
  thisId.fIdentifier = "tip_RQ";
  m_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 20, "tip_RQ")),
                     &thisId, y->tip_RQ);
  thisId.fIdentifier = "t_exp";
  n_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 21, "t_exp")),
                     &thisId, y->t_exp);
  thisId.fIdentifier = "t_exp_equil";
  n_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 22,
    "t_exp_equil")), &thisId, y->t_exp_equil);
  thisId.fIdentifier = "t_init";
  y->t_init = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 23,
    "t_init")), &thisId);
  thisId.fIdentifier = "t_final";
  y->t_final = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    24, "t_final")), &thisId);
  thisId.fIdentifier = "t_equil";
  y->t_equil = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    25, "t_equil")), &thisId);
  thisId.fIdentifier = "dt";
  y->dt = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 26,
    "dt")), &thisId);
  thisId.fIdentifier = "stepT";
  y->stepT = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 27,
    "stepT")), &thisId);
  thisId.fIdentifier = "fig";
  e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 28, "fig")),
                     &thisId);
  thisId.fIdentifier = "skip";
  y->skip = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 29,
    "skip")), &thisId);
  thisId.fIdentifier = "animPause";
  y->animPause = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    30, "animPause")), &thisId);
  thisId.fIdentifier = "pause";
  y->pause = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 31,
    "pause")), &thisId);
  thisId.fIdentifier = "t_equil_i";
  y->t_equil_i = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    32, "t_equil_i")), &thisId);
  thisId.fIdentifier = "nq";
  y->nq = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 33,
    "nq")), &thisId);
  thisId.fIdentifier = "nlambda";
  y->nlambda = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    34, "nlambda")), &thisId);
  thisId.fIdentifier = "qf0";
  o_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 35, "qf0")),
                     &thisId, y->qf0);
  thisId.fIdentifier = "n_m";
  y->n_m = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 36,
    "n_m")), &thisId);
  thisId.fIdentifier = "n_sd";
  y->n_sd = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 37,
    "n_sd")), &thisId);
  thisId.fIdentifier = "n_cn";
  y->n_cn = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 38,
    "n_cn")), &thisId);
  thisId.fIdentifier = "n_ex";
  y->n_ex = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 39,
    "n_ex")), &thisId);
  thisId.fIdentifier = "rom";
  p_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 40, "rom")),
                     &thisId, &y->rom);
  thisId.fIdentifier = "par_mex";
  r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 41, "par_mex")),
                     &thisId, &y->par_mex);
  thisId.fIdentifier = "n_mass_anim";
  y->n_mass_anim = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u,
    0, 42, "n_mass_anim")), &thisId);
  thisId.fIdentifier = "n_ks_anim";
  y->n_ks_anim = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    43, "n_ks_anim")), &thisId);
  thisId.fIdentifier = "linetype";
  y->linetype = t_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    44, "linetype")), &thisId);
  emlrtDestroyArray(&u);
}

static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[7658])
{
  static const int32_T dims[2] = { 1094, 7 };

  real_T (*r3)[7658];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r3 = (real_T (*)[7658])emlrtMxGetData(src);
  memcpy(&ret[0], &(*r3)[0], 7658U * sizeof(real_T));
  emlrtDestroyArray(&src);
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  v_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
}

static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[5470])
{
  static const int32_T dims[2] = { 1094, 5 };

  real_T (*r4)[5470];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r4 = (real_T (*)[5470])emlrtMxGetData(src);
  memcpy(&ret[0], &(*r4)[0], 5470U * sizeof(real_T));
  emlrtDestroyArray(&src);
}

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *z, const
  char_T *identifier))[6]
{
  real_T (*y)[6];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(z), &thisId);
  emlrtDestroyArray(&z);
  return y;
}
  static const mxArray *emlrt_marshallOut(const real_T u[36])
{
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv1[2] = { 0, 0 };

  static const int32_T iv2[2] = { 6, 6 };

  y = NULL;
  m0 = emlrtCreateNumericArray(2, iv1, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m0, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m0, iv2, 2);
  emlrtAssign(&y, m0);
  return y;
}

static uint64_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  uint64_T y;
  y = w_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[9])
{
  static const int32_T dims[2] = { 1, 9 };

  real_T (*r5)[9];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r5 = (real_T (*)[9])emlrtMxGetData(src);
  memcpy(&ret[0], &(*r5)[0], 9U * sizeof(real_T));
  emlrtDestroyArray(&src);
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[7])
{
  x_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[6])
{
  static const int32_T dims[2] = { 1, 6 };

  real_T (*r6)[6];
  int32_T i5;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r6 = (real_T (*)[6])emlrtMxGetData(src);
  for (i5 = 0; i5 < 6; i5++) {
    ret[i5] = (*r6)[i5];
  }

  emlrtDestroyArray(&src);
}

static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = y_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void hb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
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

static boolean_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = ab_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void ib_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[4])
{
  static const int32_T dims[2] = { 1, 4 };

  real_T (*r8)[4];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r8 = (real_T (*)[4])emlrtMxGetData(src);
  ret[0] = (*r8)[0];
  ret[1] = (*r8)[1];
  ret[2] = (*r8)[2];
  ret[3] = (*r8)[3];
  emlrtDestroyArray(&src);
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[34])
{
  bb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static char_T jb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  char_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 0U, &dims);
  emlrtImportCharR2015b(sp, src, &ret);
  emlrtDestroyArray(&src);
  return ret;
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[4376])
{
  cb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[7658])
{
  db_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[5470])
{
  eb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[9])
{
  fb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[6])
{
  gb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[2] = { "mass", "sprdmp" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 2, fieldNames, 0U, &dims);
  thisId.fIdentifier = "mass";
  q_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "mass")),
                     &thisId, y->mass);
  thisId.fIdentifier = "sprdmp";
  g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1, "sprdmp")),
                     &thisId, y->sprdmp);
  emlrtDestroyArray(&u);
}

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2])
{
  hb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
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
  e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "sym")),
                     &thisId);
  thisId.fIdentifier = "timer";
  y->timer = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1,
    "timer")), &thisId);
  thisId.fIdentifier = "elapsed_time";
  s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2,
    "elapsed_time")), &thisId, y->elapsed_time);
  thisId.fIdentifier = "derive";
  y->derive = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3,
    "derive")), &thisId);
  thisId.fIdentifier = "derive_collect";
  y->derive_collect = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp,
    u, 0, 4, "derive_collect")), &thisId);
  thisId.fIdentifier = "derive_mex";
  y->derive_mex = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    5, "derive_mex")), &thisId);
  thisId.fIdentifier = "opv";
  y->opv = i_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 6,
    "opv")), &thisId);
  thisId.fIdentifier = "Anim";
  y->Anim = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 7,
    "Anim")), &thisId);
  thisId.fIdentifier = "movie";
  y->movie = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 8,
    "movie")), &thisId);
  thisId.fIdentifier = "equil";
  y->equil = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 9,
    "equil")), &thisId);
  thisId.fIdentifier = "modal";
  y->modal = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 10,
    "modal")), &thisId);
  thisId.fIdentifier = "simdyn";
  y->simdyn = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 11,
    "simdyn")), &thisId);
  thisId.fIdentifier = "t_rep";
  y->t_rep = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 12,
    "t_rep")), &thisId);
  thisId.fIdentifier = "n_int";
  y->n_int = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 13,
    "n_int")), &thisId);
  thisId.fIdentifier = "n_animpoints";
  y->n_animpoints = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u,
    0, 14, "n_animpoints")), &thisId);
  thisId.fIdentifier = "n_datasample";
  y->n_datasample = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u,
    0, 15, "n_datasample")), &thisId);
  thisId.fIdentifier = "var";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 16, "var")),
                     &thisId, y->var);
  thisId.fIdentifier = "p";
  k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 17, "p")),
                     &thisId, y->p);
  thisId.fIdentifier = "f_ex";
  l_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 18, "f_ex")),
                     &thisId, y->f_ex);
  thisId.fIdentifier = "tip_exp";
  k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 19, "tip_exp")),
                     &thisId, y->tip_exp);
  thisId.fIdentifier = "tip_RQ";
  m_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 20, "tip_RQ")),
                     &thisId, y->tip_RQ);
  thisId.fIdentifier = "t_exp";
  n_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 21, "t_exp")),
                     &thisId, y->t_exp);
  thisId.fIdentifier = "t_exp_equil";
  n_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 22,
    "t_exp_equil")), &thisId, y->t_exp_equil);
  thisId.fIdentifier = "t_init";
  y->t_init = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 23,
    "t_init")), &thisId);
  thisId.fIdentifier = "t_final";
  y->t_final = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    24, "t_final")), &thisId);
  thisId.fIdentifier = "t_equil";
  y->t_equil = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    25, "t_equil")), &thisId);
  thisId.fIdentifier = "dt";
  y->dt = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 26,
    "dt")), &thisId);
  thisId.fIdentifier = "stepT";
  y->stepT = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 27,
    "stepT")), &thisId);
  thisId.fIdentifier = "fig";
  e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 28, "fig")),
                     &thisId);
  thisId.fIdentifier = "skip";
  y->skip = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 29,
    "skip")), &thisId);
  thisId.fIdentifier = "animPause";
  y->animPause = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    30, "animPause")), &thisId);
  thisId.fIdentifier = "pause";
  y->pause = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 31,
    "pause")), &thisId);
  thisId.fIdentifier = "t_equil_i";
  y->t_equil_i = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    32, "t_equil_i")), &thisId);
  thisId.fIdentifier = "nq";
  y->nq = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 33,
    "nq")), &thisId);
  thisId.fIdentifier = "nlambda";
  y->nlambda = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    34, "nlambda")), &thisId);
  thisId.fIdentifier = "qf0";
  o_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 35, "qf0")),
                     &thisId, y->qf0);
  thisId.fIdentifier = "n_m";
  y->n_m = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 36,
    "n_m")), &thisId);
  thisId.fIdentifier = "n_sd";
  y->n_sd = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 37,
    "n_sd")), &thisId);
  thisId.fIdentifier = "n_cn";
  y->n_cn = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 38,
    "n_cn")), &thisId);
  thisId.fIdentifier = "n_ex";
  y->n_ex = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 39,
    "n_ex")), &thisId);
  thisId.fIdentifier = "rom";
  p_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 40, "rom")),
                     &thisId, &y->rom);
  emlrtDestroyArray(&u);
}

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[4])
{
  ib_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static char_T t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  char_T y;
  y = jb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[6]
{
  real_T (*ret)[6];
  static const int32_T dims[2] = { 1, 6 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[6])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  static const int32_T dims[2] = { 0, 0 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

static uint64_T w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  uint64_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "uint64", false, 0U, &dims);
  ret = *(uint64_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[7])
{
  static const int32_T dims[2] = { 1, 7 };

  real_T (*r0)[7];
  int32_T i4;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r0 = (real_T (*)[7])emlrtMxGetData(src);
  for (i4 = 0; i4 < 7; i4++) {
    ret[i4] = (*r0)[i4];
  }

  emlrtDestroyArray(&src);
}

static real_T y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void EOM_modal_api(EOM_modalStackData *SD, const mxArray * const prhs[2],
                   int32_T nlhs, const mxArray *plhs[3])
{
  real_T (*TMT)[36];
  real_T (*TKT)[36];
  real_T (*TVT)[36];
  real_T (*z)[6];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  TMT = (real_T (*)[36])mxMalloc(sizeof(real_T [36]));
  TKT = (real_T (*)[36])mxMalloc(sizeof(real_T [36]));
  TVT = (real_T (*)[36])mxMalloc(sizeof(real_T [36]));

  /* Marshall function inputs */
  z = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "z");
  c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "par", &SD->f0.par);

  /* Invoke the target function */
  EOM_modal(&st, *z, &SD->f0.par, *TMT, *TKT, *TVT);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*TMT);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(*TKT);
  }

  if (nlhs > 2) {
    plhs[2] = emlrt_marshallOut(*TVT);
  }
}

/* End of code generation (_coder_EOM_modal_api.c) */
