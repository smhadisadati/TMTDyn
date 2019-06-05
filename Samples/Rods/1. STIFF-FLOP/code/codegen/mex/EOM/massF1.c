/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * massF1.c
 *
 * Code generation for function 'massF1'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "EOM.h"
#include "massF1.h"
#include "error.h"
#include "EOM_data.h"

/* Variable Definitions */
static emlrtRSInfo ub_emlrtRSI = { 30, /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/massF1.m"/* pathName */
};

static emlrtRSInfo vb_emlrtRSI = { 32, /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/massF1.m"/* pathName */
};

static emlrtRSInfo wb_emlrtRSI = { 33, /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/massF1.m"/* pathName */
};

static emlrtRSInfo xb_emlrtRSI = { 36, /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/massF1.m"/* pathName */
};

static emlrtRSInfo yb_emlrtRSI = { 38, /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/massF1.m"/* pathName */
};

static emlrtRSInfo ac_emlrtRSI = { 39, /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/massF1.m"/* pathName */
};

static emlrtRSInfo bc_emlrtRSI = { 48, /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/massF1.m"/* pathName */
};

static emlrtRSInfo cc_emlrtRSI = { 50, /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/massF1.m"/* pathName */
};

static emlrtRSInfo dc_emlrtRSI = { 52, /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/massF1.m"/* pathName */
};

static emlrtRSInfo ec_emlrtRSI = { 62, /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/massF1.m"/* pathName */
};

static emlrtRSInfo fc_emlrtRSI = { 63, /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/massF1.m"/* pathName */
};

static emlrtRSInfo gc_emlrtRSI = { 64, /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/massF1.m"/* pathName */
};

static emlrtRSInfo hc_emlrtRSI = { 66, /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/massF1.m"/* pathName */
};

static emlrtRSInfo ic_emlrtRSI = { 67, /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/massF1.m"/* pathName */
};

static emlrtRSInfo jc_emlrtRSI = { 83, /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/massF1.m"/* pathName */
};

static emlrtRSInfo kc_emlrtRSI = { 87, /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/massF1.m"/* pathName */
};

/* Function Definitions */
void massF1(const emlrtStack *sp, const real_T in1[34], const real_T in2[24],
            real_T s, real_T out1[36], real_T out2[72], real_T out3[72], real_T
            out4[6])
{
  real_T t2;
  real_T t4;
  real_T t5;
  real_T t7;
  real_T t8;
  real_T t56;
  real_T t46;
  real_T t47;
  real_T t18;
  real_T t21;
  real_T t43;
  real_T t22;
  real_T t23;
  real_T t24;
  real_T t25;
  real_T t28;
  real_T t31;
  real_T t34;
  real_T t37;
  real_T t39;
  real_T t40_tmp;
  real_T t40;
  real_T t41_tmp;
  real_T t101;
  real_T t41;
  real_T t42;
  real_T t49_tmp;
  real_T t104;
  real_T t50;
  real_T t53;
  real_T t54;
  real_T t55;
  real_T t57;
  real_T t58_tmp;
  real_T t58;
  real_T t60;
  real_T t61;
  real_T t62;
  real_T t63;
  real_T t65;
  real_T t67;
  real_T t68;
  real_T t69;
  real_T t70;
  real_T t71;
  real_T t72;
  real_T t74;
  real_T t75;
  real_T t76;
  real_T t77;
  real_T t79;
  real_T t80;
  real_T t81;
  real_T t82;
  real_T t84;
  real_T t85;
  real_T t86;
  real_T t88;
  real_T t89;
  real_T t90;
  real_T t91;
  real_T t92;
  real_T t94;
  real_T t95;
  real_T t97;
  real_T t98;
  real_T t100;
  real_T t102;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;

  /* MASSF1 */
  /*     [OUT1,OUT2,OUT3,OUT4] = MASSF1(IN1,IN2,S) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.2. */
  /*     04-Jan-2019 15:00:18 */
  st.site = &ub_emlrtRSI;
  t2 = in1[18] * in1[18];
  st.site = &vb_emlrtRSI;
  t4 = in1[2] * in1[2];
  st.site = &wb_emlrtRSI;
  t5 = in1[3] * in1[3];
  t7 = muDoubleScalarSin(in1[20]);
  st.site = &xb_emlrtRSI;
  t8 = 1.0 / (t7 * t7);
  t56 = muDoubleScalarCos(in1[20]);
  st.site = &yb_emlrtRSI;
  st.site = &ac_emlrtRSI;
  t46 = in1[33] * in1[33] * (t56 * t56);
  t47 = in1[0] * (t4 - t5);
  t18 = t47 * (t4 / 4.0 - t5 / 4.0) * 3.1415926535897931;
  st.site = &bc_emlrtRSI;
  t21 = t2 * t8 * (t46 - 1.0) * 1.5;
  st.site = &cc_emlrtRSI;
  st.site = &cc_emlrtRSI;
  st.site = &cc_emlrtRSI;
  t43 = -in1[0] * ((t2 * 6.0 + t4) - t5) * 3.1415926535897931;
  out1[0] = t43;
  out1[1] = 0.0;
  out1[2] = 0.0;
  out1[3] = 0.0;
  out1[4] = 0.0;
  out1[5] = 0.0;
  out1[6] = 0.0;
  out1[7] = t43;
  out1[8] = 0.0;
  out1[9] = 0.0;
  out1[10] = 0.0;
  out1[11] = 0.0;
  out1[12] = 0.0;
  out1[13] = 0.0;
  out1[14] = t43;
  out1[15] = 0.0;
  out1[16] = 0.0;
  out1[17] = 0.0;
  out1[18] = 0.0;
  out1[19] = 0.0;
  out1[20] = 0.0;
  t43 = 1.0 / in1[33] * (in1[19] * in1[19]);
  t56 = in1[0] * t2 * t8 * (t46 - 1.0) * 3.1415926535897931;
  out1[21] = t18 - t56 * (t21 + t43 * 3.0);
  out1[22] = 0.0;
  out1[23] = 0.0;
  out1[24] = 0.0;
  out1[25] = 0.0;
  out1[26] = 0.0;
  out1[27] = 0.0;
  out1[28] = t18 - t56 * (t21 + t43 * 2.9999999999999991);
  out1[29] = 0.0;
  out1[30] = 0.0;
  out1[31] = 0.0;
  out1[32] = 0.0;
  out1[33] = 0.0;
  out1[34] = 0.0;
  out1[35] = t47 * 3.1415926535897931 * (t4 / 2.0 - t5 / 2.0) - in1[0] * (t2 *
    t2) / muDoubleScalarPower(t7, 4.0) * ((t46 - 1.0) * (t46 - 1.0)) *
    3.1415926535897931 * 3.0;
  st.site = &dc_emlrtRSI;
  t22 = s * s;
  t23 = in2[6] * s + in2[7] * t22;
  t24 = in2[8] * s + in2[9] * t22;
  t25 = in2[10] * s + in2[11] * t22;
  st.site = &ec_emlrtRSI;
  t28 = t23 * t23;
  st.site = &fc_emlrtRSI;
  t31 = t24 * t24;
  st.site = &gc_emlrtRSI;
  t34 = t25 * t25;
  t5 = ((-t28 - t31) - t34) + 1.0;
  st.site = &hc_emlrtRSI;
  if (t5 < 0.0) {
    b_st.site = &tb_emlrtRSI;
    b_error(&b_st);
  }

  t56 = muDoubleScalarSqrt(t5);
  st.site = &ic_emlrtRSI;
  t37 = 1.0 / t56;
  t7 = s * t25 * 2.0;
  t8 = s * t23;
  t39 = t8 * t24 * t37 * 2.0;
  t40_tmp = t22 * t25;
  t40 = t40_tmp * 2.0;
  t41_tmp = t22 * t23;
  t101 = t41_tmp * t24;
  t41 = t101 * t37 * 2.0;
  t42 = s * t56 * 2.0;
  t43 = t22 * t56 * 2.0;
  t2 = t8 * t25 * t37 * 2.0;
  t4 = t41_tmp * t25 * t37 * 2.0;
  t46 = t8 * 2.0;
  t56 = s * t24;
  t47 = t56 * t25 * t37 * 2.0;
  t18 = t41_tmp * 2.0;
  t49_tmp = t22 * t24;
  t21 = t49_tmp * t25 * t37 * 2.0;
  out2[0] = t22;
  out2[1] = 0.0;
  out2[2] = 0.0;
  out2[3] = 0.0;
  out2[4] = 0.0;
  out2[5] = 0.0;
  t104 = s * t22;
  out2[6] = t104;
  out2[7] = 0.0;
  out2[8] = 0.0;
  out2[9] = 0.0;
  out2[10] = 0.0;
  out2[11] = 0.0;
  out2[12] = 0.0;
  out2[13] = t22;
  out2[14] = 0.0;
  out2[15] = 0.0;
  out2[16] = 0.0;
  out2[17] = 0.0;
  out2[18] = 0.0;
  out2[19] = t104;
  out2[20] = 0.0;
  out2[21] = 0.0;
  out2[22] = 0.0;
  out2[23] = 0.0;
  out2[24] = 0.0;
  out2[25] = 0.0;
  out2[26] = t22;
  out2[27] = 0.0;
  out2[28] = 0.0;
  out2[29] = 0.0;
  out2[30] = 0.0;
  out2[31] = 0.0;
  out2[32] = t104;
  out2[33] = 0.0;
  out2[34] = 0.0;
  out2[35] = 0.0;
  out2[36] = 0.0;
  out2[37] = 0.0;
  out2[38] = 0.0;
  out2[39] = t42 + s * t28 * t37 * 2.0;
  out2[40] = -t7 + t39;
  t56 *= 2.0;
  out2[41] = t2 + t56;
  out2[42] = 0.0;
  out2[43] = 0.0;
  out2[44] = 0.0;
  out2[45] = t43 + t22 * t28 * t37 * 2.0;
  out2[46] = -t40 + t41;
  t8 = t49_tmp * 2.0;
  out2[47] = t4 + t8;
  out2[48] = 0.0;
  out2[49] = 0.0;
  out2[50] = 0.0;
  out2[51] = t7 + t39;
  out2[52] = t42 + s * t31 * t37 * 2.0;
  out2[53] = -t46 + t47;
  out2[54] = 0.0;
  out2[55] = 0.0;
  out2[56] = 0.0;
  out2[57] = t40 + t41;
  out2[58] = t43 + t22 * t31 * t37 * 2.0;
  out2[59] = -t18 + t21;
  out2[60] = 0.0;
  out2[61] = 0.0;
  out2[62] = 0.0;
  out2[63] = t2 - t56;
  out2[64] = t46 + t47;
  out2[65] = t42 + s * t34 * t37 * 2.0;
  out2[66] = 0.0;
  out2[67] = 0.0;
  out2[68] = 0.0;
  out2[69] = t4 - t8;
  out2[70] = t18 + t21;
  out2[71] = t43 + t22 * t34 * t37 * 2.0;
  st.site = &jc_emlrtRSI;
  t50 = 1.0 / muDoubleScalarPower(t5, 1.5);
  t21 = t104 * t23;
  t46 = t21 * t37 * 2.0;
  t53 = t46 + t21 * t28 * t50 * 2.0;
  st.site = &kc_emlrtRSI;
  t54 = t22 * t22;
  t5 = t104 * t24;
  t55 = t5 * t37 * 2.0;
  t56 = t5 * t28 * t50 * 2.0;
  t57 = t55 + t56;
  t58_tmp = t104 * t25;
  t58 = t58_tmp * t37 * 2.0;
  t2 = t58_tmp * t28 * t50 * 2.0;
  t60 = t58 + t2;
  t61 = t41_tmp * t37 * 2.0;
  t62 = t49_tmp * t37 * 2.0;
  t63 = t49_tmp * t28 * t50 * 2.0;
  t8 = t104 * 2.0;
  t18 = t21 * t24 * t25 * t50 * 2.0;
  t65 = t8 - t18;
  t4 = t21 * t31 * t50 * 2.0;
  t67 = t46 + t4;
  t68 = t55 - t56;
  t69 = t23 * t37 * t54 * 2.0;
  t70 = t24 * t37 * t54 * 2.0;
  t71 = t24 * t28 * t50 * t54 * 2.0;
  t72 = t22 * 2.0;
  t74 = t40_tmp * t37 * 2.0;
  t75 = t40_tmp * t28 * t50 * 2.0;
  t76 = t8 + t18;
  t77 = t54 * 2.0;
  t7 = t21 * t34 * t50 * 2.0;
  t79 = t46 + t7;
  t80 = t58 - t2;
  t81 = t25 * t37 * t54 * 2.0;
  t82 = t25 * t28 * t50 * t54 * 2.0;
  t18 = t101 * t25 * t50 * 2.0;
  t84 = t72 + t18;
  t85 = t41_tmp * t31 * t50 * 2.0;
  t86 = t62 + t63;
  t21 = t23 * t24 * t25 * t50 * t54 * 2.0;
  t88 = t77 + t21;
  t89 = t46 - t4;
  t90 = t23 * t31 * t50 * t54 * 2.0;
  t91 = t70 + t71;
  t92 = t61 + t85;
  t94 = t55 + t5 * t31 * t50 * 2.0;
  t95 = t69 + t90;
  t8 = t58_tmp * t31 * t50 * 2.0;
  t97 = t58 + t8;
  t98 = t40_tmp * t31 * t50 * 2.0;
  t2 = t5 * t34 * t50 * 2.0;
  t100 = t55 + t2;
  t101 = t58 - t8;
  t102 = t25 * t31 * t50 * t54 * 2.0;
  t56 = t72 - t18;
  t104 = t41_tmp * t34 * t50 * 2.0;
  t37 = t74 + t75;
  t42 = t77 - t21;
  t47 = t46 - t7;
  t43 = t23 * t34 * t50 * t54 * 2.0;
  t39 = t81 + t82;
  t40 = t49_tmp * t34 * t50 * 2.0;
  t41 = t74 + t98;
  t2 = t55 - t2;
  t4 = t24 * t34 * t50 * t54 * 2.0;
  t5 = t81 + t102;
  t7 = t61 + t104;
  t46 = t62 + t40;
  t8 = t58 + t58_tmp * t34 * t50 * 2.0;
  t18 = t69 + t43;
  t21 = t70 + t4;
  memset(&out3[0], 0, 39U * sizeof(real_T));
  out3[39] = ((((t53 * in2[19] + t57 * in2[21]) + t60 * in2[23]) + t86 * in2[20])
              + t37 * in2[22]) + in2[18] * (t61 + t41_tmp * t28 * t50 * 2.0);
  out3[40] = ((((t57 * in2[19] + t76 * in2[23]) + t86 * in2[18]) + t84 * in2[22])
              - t89 * in2[21]) - in2[20] * (t61 - t85);
  out3[41] = ((((t60 * in2[19] - t65 * in2[21]) - t56 * in2[20]) + t37 * in2[18])
              - t47 * in2[23]) - in2[22] * (t61 - t104);
  out3[42] = 0.0;
  out3[43] = 0.0;
  out3[44] = 0.0;
  out3[45] = ((((t53 * in2[18] + t57 * in2[20]) + t60 * in2[22]) + t91 * in2[21])
              + t39 * in2[23]) + in2[19] * (t69 + t23 * t28 * t50 * t54 * 2.0);
  out3[46] = ((((t57 * in2[18] + t76 * in2[22]) - t89 * in2[20]) + t91 * in2[19])
              + t88 * in2[23]) - in2[21] * (t69 - t90);
  out3[47] = ((((t60 * in2[18] - t65 * in2[20]) - t42 * in2[21]) + t39 * in2[19])
              - t47 * in2[22]) - in2[23] * (t69 - t43);
  out3[48] = 0.0;
  out3[49] = 0.0;
  out3[50] = 0.0;
  out3[51] = ((((-t68 * in2[19] - t65 * in2[23]) + t67 * in2[21]) + t92 * in2[20])
              - in2[22] * (t72 - t22 * t23 * t24 * t25 * t50 * 2.0)) - in2[18] *
    (t62 - t63);
  out3[52] = ((((t67 * in2[19] + t92 * in2[18]) + t94 * in2[21]) + t97 * in2[23])
              + t41 * in2[22]) + in2[20] * (t62 + t49_tmp * t31 * t50 * 2.0);
  out3[53] = ((((t76 * in2[19] + t84 * in2[18]) + t97 * in2[21]) + t41 * in2[20])
              - t2 * in2[23]) - in2[22] * (t62 - t40);
  out3[54] = 0.0;
  out3[55] = 0.0;
  out3[56] = 0.0;
  out3[57] = ((((-t68 * in2[18] - t65 * in2[22]) + t67 * in2[20]) + t95 * in2[21])
              - in2[23] * (t77 - t23 * t24 * t25 * t50 * t54 * 2.0)) - in2[19] *
    (t70 - t71);
  out3[58] = ((((t67 * in2[18] + t94 * in2[20]) + t95 * in2[19]) + t97 * in2[22])
              + t5 * in2[23]) + in2[21] * (t70 + t24 * t31 * t50 * t54 * 2.0);
  out3[59] = ((((t76 * in2[18] + t88 * in2[19]) + t97 * in2[20]) - t2 * in2[22])
              + t5 * in2[21]) - in2[23] * (t70 - t4);
  out3[60] = 0.0;
  out3[61] = 0.0;
  out3[62] = 0.0;
  out3[63] = ((((t76 * in2[21] - t80 * in2[19]) + t79 * in2[23]) + t84 * in2[20])
              + t7 * in2[22]) - in2[18] * (t74 - t75);
  out3[64] = ((((-t65 * in2[19] - t56 * in2[18]) - t101 * in2[21]) + t100 * in2
               [23]) + t46 * in2[22]) - in2[20] * (t74 - t98);
  out3[65] = ((((t79 * in2[19] + t100 * in2[21]) + t7 * in2[18]) + t46 * in2[20])
              + t8 * in2[23]) + in2[22] * (t74 + t40_tmp * t34 * t50 * 2.0);
  out3[66] = 0.0;
  out3[67] = 0.0;
  out3[68] = 0.0;
  out3[69] = ((((t76 * in2[20] - t80 * in2[18]) + t79 * in2[22]) + t88 * in2[21])
              + t18 * in2[23]) - in2[19] * (t81 - t82);
  out3[70] = ((((-t65 * in2[18] - t101 * in2[20]) + t100 * in2[22]) - t42 * in2
               [19]) + t21 * in2[23]) - in2[21] * (t81 - t102);
  out3[71] = ((((t79 * in2[18] + t100 * in2[20]) + t18 * in2[19]) + t8 * in2[22])
              + t21 * in2[21]) + in2[23] * (t81 + t25 * t34 * t50 * t54 * 2.0);
  out4[0] = in1[12];
  out4[1] = in1[13];
  out4[2] = in1[14];
  out4[3] = 0.0;
  out4[4] = 0.0;
  out4[5] = 0.0;
}

/* End of code generation (massF1.c) */
