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
#include "massF1.h"
#include "error.h"
#include "sqrt.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 36,    /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 38,  /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 39,  /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 42,  /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 44,  /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 45,  /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 54,  /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 56,  /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 58,  /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 59,  /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 72,  /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 73,  /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 74,  /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 76,  /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 77,  /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 99,  /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 49,  /* lineNo */
  "power",                             /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 61,  /* lineNo */
  "power",                             /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

/* Function Definitions */
void massF1(const emlrtStack *sp, const real_T in1[34], const real_T in2[36],
            real_T s, real_T out1[36], real_T out2[108], real_T out3[108],
            real_T out4[6])
{
  real_T t2;
  real_T t4;
  real_T t5;
  real_T t7;
  real_T t8;
  real_T t62;
  real_T t116;
  real_T t54;
  real_T t18;
  real_T t21;
  real_T t57;
  real_T t22;
  real_T t23;
  real_T t24;
  real_T t25;
  real_T t26;
  real_T t30;
  real_T t34;
  real_T t38;
  real_T t39;
  real_T t41;
  real_T t42;
  real_T t43;
  real_T t44_tmp;
  real_T t44;
  real_T t45_tmp;
  real_T t161;
  real_T t45;
  real_T t167;
  real_T t46_tmp;
  real_T t46;
  real_T t165;
  real_T t168;
  real_T t47;
  real_T t48;
  real_T t49;
  real_T t52;
  real_T t53;
  real_T t57_tmp;
  real_T t160;
  real_T t60;
  real_T t61;
  real_T t63;
  real_T t64;
  real_T t66;
  real_T t67;
  real_T t69;
  real_T t70_tmp;
  real_T t70;
  real_T t72;
  real_T t75;
  real_T t77;
  real_T t78;
  real_T t79;
  real_T t81;
  real_T t82_tmp;
  real_T t82;
  real_T t84;
  real_T t86;
  real_T t87;
  real_T t88;
  real_T t89;
  real_T t90;
  real_T t92;
  real_T t94;
  real_T t96;
  real_T t98;
  real_T t99;
  real_T t100;
  real_T t103;
  real_T t105;
  real_T t106_tmp;
  real_T t106;
  real_T t107;
  real_T t108_tmp;
  real_T t108;
  real_T t109;
  real_T t110;
  real_T t112;
  real_T t113;
  real_T t114;
  real_T t115;
  real_T t118;
  real_T t120;
  real_T t121;
  real_T t122;
  real_T t123;
  real_T t124;
  real_T t126;
  real_T t127;
  real_T t128_tmp;
  real_T t128;
  real_T t129;
  real_T t131;
  real_T t132;
  real_T t133;
  real_T t134;
  real_T t135;
  real_T t137;
  real_T t138;
  real_T t139;
  real_T t140;
  real_T t141;
  real_T t143;
  real_T t145;
  real_T t147;
  real_T t149;
  real_T t150;
  real_T t152;
  real_T t154;
  real_T t155;
  real_T t157;
  real_T t159;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;

  /* MASSF1 */
  /*     [OUT1,OUT2,OUT3,OUT4] = MASSF1(IN1,IN2,S) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.2. */
  /*     04-Jan-2019 16:01:56 */
  st.site = &emlrtRSI;
  b_st.site = &q_emlrtRSI;
  t2 = in1[18] * in1[18];
  st.site = &b_emlrtRSI;
  b_st.site = &q_emlrtRSI;
  t4 = in1[2] * in1[2];
  st.site = &c_emlrtRSI;
  b_st.site = &q_emlrtRSI;
  t5 = in1[3] * in1[3];
  t7 = muDoubleScalarSin(in1[20]);
  st.site = &d_emlrtRSI;
  b_st.site = &q_emlrtRSI;
  t8 = 1.0 / (t7 * t7);
  t62 = muDoubleScalarCos(in1[20]);
  st.site = &e_emlrtRSI;
  b_st.site = &q_emlrtRSI;
  st.site = &f_emlrtRSI;
  b_st.site = &q_emlrtRSI;
  t116 = in1[33] * in1[33] * (t62 * t62);
  t54 = in1[0] * (t4 - t5);
  t18 = t54 * (t4 / 4.0 - t5 / 4.0) * 3.1415926535897931;
  st.site = &g_emlrtRSI;
  b_st.site = &q_emlrtRSI;
  t21 = t2 * t8 * (t116 - 1.0) * 1.5;
  st.site = &h_emlrtRSI;
  b_st.site = &q_emlrtRSI;
  st.site = &h_emlrtRSI;
  b_st.site = &q_emlrtRSI;
  st.site = &h_emlrtRSI;
  b_st.site = &q_emlrtRSI;
  t57 = -in1[0] * ((t2 * 6.0 + t4) - t5) * 3.1415926535897931;
  out1[0] = t57;
  out1[1] = 0.0;
  out1[2] = 0.0;
  out1[3] = 0.0;
  out1[4] = 0.0;
  out1[5] = 0.0;
  out1[6] = 0.0;
  out1[7] = t57;
  out1[8] = 0.0;
  out1[9] = 0.0;
  out1[10] = 0.0;
  out1[11] = 0.0;
  out1[12] = 0.0;
  out1[13] = 0.0;
  out1[14] = t57;
  out1[15] = 0.0;
  out1[16] = 0.0;
  out1[17] = 0.0;
  out1[18] = 0.0;
  out1[19] = 0.0;
  out1[20] = 0.0;
  t57 = 1.0 / in1[33] * (in1[19] * in1[19]);
  t62 = in1[0] * t2 * t8 * (t116 - 1.0) * 3.1415926535897931;
  out1[21] = t18 - t62 * (t21 + t57 * 3.0);
  out1[22] = 0.0;
  out1[23] = 0.0;
  out1[24] = 0.0;
  out1[25] = 0.0;
  out1[26] = 0.0;
  out1[27] = 0.0;
  out1[28] = t18 - t62 * (t21 + t57 * 2.9999999999999991);
  out1[29] = 0.0;
  out1[30] = 0.0;
  out1[31] = 0.0;
  out1[32] = 0.0;
  out1[33] = 0.0;
  out1[34] = 0.0;
  out1[35] = t54 * 3.1415926535897931 * (t4 / 2.0 - t5 / 2.0) - in1[0] * (t2 *
    t2) / muDoubleScalarPower(t7, 4.0) * ((t116 - 1.0) * (t116 - 1.0)) *
    3.1415926535897931 * 3.0;
  st.site = &i_emlrtRSI;
  b_st.site = &q_emlrtRSI;
  t22 = s * s;
  st.site = &j_emlrtRSI;
  b_st.site = &q_emlrtRSI;
  t23 = t22 * t22;
  t24 = (in2[9] * s + in2[10] * t22) + in2[11] * s * t22;
  t25 = (in2[12] * s + in2[13] * t22) + in2[14] * s * t22;
  t26 = (in2[15] * s + in2[16] * t22) + in2[17] * s * t22;
  st.site = &k_emlrtRSI;
  b_st.site = &q_emlrtRSI;
  t30 = t24 * t24;
  st.site = &l_emlrtRSI;
  b_st.site = &q_emlrtRSI;
  t34 = t25 * t25;
  st.site = &m_emlrtRSI;
  b_st.site = &q_emlrtRSI;
  t38 = t26 * t26;
  t39 = ((-t30 - t34) - t38) + 1.0;
  t8 = t39;
  st.site = &n_emlrtRSI;
  b_sqrt(&st, &t8);
  t62 = t39;
  st.site = &o_emlrtRSI;
  b_sqrt(&st, &t62);
  t41 = 1.0 / t62;
  t42 = s * t26 * 2.0;
  t62 = s * t24;
  t43 = t62 * t25 * t41 * 2.0;
  t44_tmp = t22 * t26;
  t44 = t44_tmp * 2.0;
  t45_tmp = t22 * t24;
  t161 = t45_tmp * t25;
  t45 = t161 * t41 * 2.0;
  t167 = s * t22;
  t46_tmp = t167 * t26;
  t46 = t46_tmp * 2.0;
  t165 = t167 * t24;
  t168 = t165 * t25;
  t47 = t168 * t41 * 2.0;
  t48 = s * t8 * 2.0;
  t49 = t22 * t8 * 2.0;
  t5 = t167 * t8 * 2.0;
  t7 = t62 * t26 * t41 * 2.0;
  t52 = t45_tmp * t26 * t41 * 2.0;
  t53 = t165 * t26 * t41 * 2.0;
  t54 = t62 * 2.0;
  t62 = s * t25;
  t18 = t62 * t26 * t41 * 2.0;
  t21 = t45_tmp * 2.0;
  t57_tmp = t22 * t25;
  t57 = t57_tmp * t26 * t41 * 2.0;
  t2 = t165 * 2.0;
  t160 = t167 * t25;
  t4 = t160 * t26 * t41 * 2.0;
  out2[0] = t22;
  out2[1] = 0.0;
  out2[2] = 0.0;
  out2[3] = 0.0;
  out2[4] = 0.0;
  out2[5] = 0.0;
  out2[6] = t167;
  out2[7] = 0.0;
  out2[8] = 0.0;
  out2[9] = 0.0;
  out2[10] = 0.0;
  out2[11] = 0.0;
  out2[12] = t23;
  out2[13] = 0.0;
  out2[14] = 0.0;
  out2[15] = 0.0;
  out2[16] = 0.0;
  out2[17] = 0.0;
  out2[18] = 0.0;
  out2[19] = t22;
  out2[20] = 0.0;
  out2[21] = 0.0;
  out2[22] = 0.0;
  out2[23] = 0.0;
  out2[24] = 0.0;
  out2[25] = t167;
  out2[26] = 0.0;
  out2[27] = 0.0;
  out2[28] = 0.0;
  out2[29] = 0.0;
  out2[30] = 0.0;
  out2[31] = t23;
  out2[32] = 0.0;
  out2[33] = 0.0;
  out2[34] = 0.0;
  out2[35] = 0.0;
  out2[36] = 0.0;
  out2[37] = 0.0;
  out2[38] = t22;
  out2[39] = 0.0;
  out2[40] = 0.0;
  out2[41] = 0.0;
  out2[42] = 0.0;
  out2[43] = 0.0;
  out2[44] = t167;
  out2[45] = 0.0;
  out2[46] = 0.0;
  out2[47] = 0.0;
  out2[48] = 0.0;
  out2[49] = 0.0;
  out2[50] = t23;
  out2[51] = 0.0;
  out2[52] = 0.0;
  out2[53] = 0.0;
  out2[54] = 0.0;
  out2[55] = 0.0;
  out2[56] = 0.0;
  out2[57] = t48 + s * t30 * t41 * 2.0;
  out2[58] = -t42 + t43;
  t62 *= 2.0;
  out2[59] = t7 + t62;
  out2[60] = 0.0;
  out2[61] = 0.0;
  out2[62] = 0.0;
  out2[63] = t49 + t22 * t30 * t41 * 2.0;
  out2[64] = -t44 + t45;
  t8 = t57_tmp * 2.0;
  out2[65] = t52 + t8;
  out2[66] = 0.0;
  out2[67] = 0.0;
  out2[68] = 0.0;
  out2[69] = t5 + t167 * t30 * t41 * 2.0;
  out2[70] = -t46 + t47;
  t116 = t160 * 2.0;
  out2[71] = t53 + t116;
  out2[72] = 0.0;
  out2[73] = 0.0;
  out2[74] = 0.0;
  out2[75] = t42 + t43;
  out2[76] = t48 + s * t34 * t41 * 2.0;
  out2[77] = -t54 + t18;
  out2[78] = 0.0;
  out2[79] = 0.0;
  out2[80] = 0.0;
  out2[81] = t44 + t45;
  out2[82] = t49 + t22 * t34 * t41 * 2.0;
  out2[83] = -t21 + t57;
  out2[84] = 0.0;
  out2[85] = 0.0;
  out2[86] = 0.0;
  out2[87] = t46 + t47;
  out2[88] = t5 + t167 * t34 * t41 * 2.0;
  out2[89] = -t2 + t4;
  out2[90] = 0.0;
  out2[91] = 0.0;
  out2[92] = 0.0;
  out2[93] = t7 - t62;
  out2[94] = t54 + t18;
  out2[95] = t48 + s * t38 * t41 * 2.0;
  out2[96] = 0.0;
  out2[97] = 0.0;
  out2[98] = 0.0;
  out2[99] = t52 - t8;
  out2[100] = t21 + t57;
  out2[101] = t49 + t22 * t38 * t41 * 2.0;
  out2[102] = 0.0;
  out2[103] = 0.0;
  out2[104] = 0.0;
  out2[105] = t53 - t116;
  out2[106] = t2 + t4;
  out2[107] = t5 + t167 * t38 * t41 * 2.0;
  st.site = &p_emlrtRSI;
  b_st.site = &q_emlrtRSI;
  if (t39 < 0.0) {
    c_st.site = &r_emlrtRSI;
    error(&c_st);
  }

  t60 = 1.0 / muDoubleScalarPower(t39, 1.5);
  t61 = t160 * t41 * 2.0;
  t62 = t160 * t30 * t60 * 2.0;
  t63 = t61 + t62;
  t46 = t23 * t25;
  t64 = t46 * t41 * 2.0;
  t8 = t46 * t30 * t60 * 2.0;
  t66 = t64 + t8;
  t67 = t46_tmp * t41 * 2.0;
  t54 = t46_tmp * t30 * t60 * 2.0;
  t69 = t67 + t54;
  t70_tmp = t23 * t26;
  t70 = t70_tmp * t41 * 2.0;
  t57 = t70_tmp * t30 * t60 * 2.0;
  t72 = t70 + t57;
  t39 = t165 * t41 * 2.0;
  t75 = t165 * t30 * t60 * 2.0 + t39;
  t7 = t23 * t24;
  t77 = t7 * t41 * 2.0;
  t78 = t7 * t30 * t60 * 2.0 + t77;
  t116 = s * t23;
  t49 = t116 * t25;
  t79 = t49 * t41 * 2.0;
  t18 = t49 * t30 * t60 * 2.0;
  t81 = t79 + t18;
  t82_tmp = t116 * t26;
  t82 = t82_tmp * t41 * 2.0;
  t42 = t82_tmp * t30 * t60 * 2.0;
  t84 = t82 + t42;
  t53 = t116 * t24;
  t86 = t53 * t41 * 2.0;
  t87 = t53 * t30 * t60 * 2.0 + t86;
  t88 = t45_tmp * t41 * 2.0;
  t89 = t57_tmp * t41 * 2.0;
  t90 = t57_tmp * t30 * t60 * 2.0;
  t2 = t167 * 2.0;
  t21 = t168 * t26 * t60 * 2.0;
  t92 = t2 - t21;
  t4 = t23 * 2.0;
  t5 = t7 * t25 * t26 * t60 * 2.0;
  t94 = t4 - t5;
  t43 = t165 * t34 * t60 * 2.0;
  t96 = t39 + t43;
  t44 = t7 * t34 * t60 * 2.0;
  t98 = t77 + t44;
  t99 = t61 - t62;
  t100 = t64 - t8;
  t8 = t116 * 2.0;
  t116 = t53 * t25 * t26 * t60 * 2.0;
  t103 = t8 - t116;
  t45 = t53 * t34 * t60 * 2.0;
  t105 = t86 + t45;
  t52 = t22 * t23;
  t106_tmp = t52 * t24;
  t106 = t106_tmp * t41 * 2.0;
  t107 = t79 - t18;
  t108_tmp = t52 * t25;
  t108 = t108_tmp * t41 * 2.0;
  t109 = t108_tmp * t30 * t60 * 2.0;
  t110 = t22 * 2.0;
  t112 = t44_tmp * t41 * 2.0;
  t113 = t44_tmp * t30 * t60 * 2.0;
  t114 = t2 + t21;
  t115 = t4 + t5;
  t47 = t165 * t38 * t60 * 2.0;
  t118 = t39 + t47;
  t48 = t7 * t38 * t60 * 2.0;
  t120 = t77 + t48;
  t121 = t67 - t54;
  t122 = t70 - t57;
  t123 = t8 + t116;
  t124 = t52 * 2.0;
  t54 = t53 * t38 * t60 * 2.0;
  t126 = t86 + t54;
  t127 = t82 - t42;
  t128_tmp = t52 * t26;
  t128 = t128_tmp * t41 * 2.0;
  t129 = t128_tmp * t30 * t60 * 2.0;
  t2 = t161 * t26 * t60 * 2.0;
  t131 = t110 + t2;
  t132 = t45_tmp * t34 * t60 * 2.0;
  t133 = t89 + t90;
  t134 = t39 - t43;
  t135 = t77 - t44;
  t4 = t106_tmp * t25 * t26 * t60 * 2.0;
  t137 = t124 + t4;
  t138 = t86 - t45;
  t139 = t106_tmp * t34 * t60 * 2.0;
  t140 = t108 + t109;
  t141 = t88 + t132;
  t8 = t46_tmp * t34 * t60 * 2.0;
  t143 = t67 + t8;
  t18 = t70_tmp * t34 * t60 * 2.0;
  t145 = t70 + t18;
  t147 = t61 + t160 * t34 * t60 * 2.0;
  t149 = t64 + t46 * t34 * t60 * 2.0;
  t150 = t106 + t139;
  t21 = t82_tmp * t34 * t60 * 2.0;
  t152 = t82 + t21;
  t154 = t79 + t49 * t34 * t60 * 2.0;
  t155 = t44_tmp * t34 * t60 * 2.0;
  t5 = t160 * t38 * t60 * 2.0;
  t157 = t61 + t5;
  t7 = t46 * t38 * t60 * 2.0;
  t159 = t64 + t7;
  t160 = t67 - t8;
  t161 = t70 - t18;
  t8 = t49 * t38 * t60 * 2.0;
  t41 = t79 + t8;
  t116 = t82 - t21;
  t165 = t128_tmp * t34 * t60 * 2.0;
  t62 = t110 - t2;
  t167 = t45_tmp * t38 * t60 * 2.0;
  t168 = t112 + t113;
  t39 -= t47;
  t49 = t77 - t48;
  t48 = t124 - t4;
  t43 = t86 - t54;
  t44 = t106_tmp * t38 * t60 * 2.0;
  t45 = t128 + t129;
  t46 = t57_tmp * t38 * t60 * 2.0;
  t47 = t112 + t155;
  t42 = t61 - t5;
  t53 = t64 - t7;
  t5 = t79 - t8;
  t7 = t108_tmp * t38 * t60 * 2.0;
  t54 = t128 + t165;
  t57 = t88 + t167;
  t52 = t89 + t46;
  t4 = t67 + t46_tmp * t38 * t60 * 2.0;
  t18 = t70 + t70_tmp * t38 * t60 * 2.0;
  t21 = t106 + t44;
  t2 = t108 + t7;
  t8 = t82 + t82_tmp * t38 * t60 * 2.0;
  memset(&out3[0], 0, 57U * sizeof(real_T));
  out3[57] = (((((((t63 * in2[31] + t66 * in2[32]) + t69 * in2[34]) + t75 * in2
                  [28]) + t72 * in2[35]) + t78 * in2[29]) + t133 * in2[30]) +
              t168 * in2[33]) + in2[27] * (t88 + t45_tmp * t30 * t60 * 2.0);
  out3[58] = (((((((t63 * in2[28] + t66 * in2[29]) + t114 * in2[34]) + t115 *
                  in2[35]) + t133 * in2[27]) + t131 * in2[33]) - t134 * in2[31])
              - t135 * in2[32]) - in2[30] * (t88 - t132);
  out3[59] = (((((((t69 * in2[28] + t72 * in2[29]) - t92 * in2[31]) - t94 * in2
                  [32]) + t168 * in2[27]) - t62 * in2[30]) - t39 * in2[34]) -
              t49 * in2[35]) - in2[33] * (t88 - t167);
  out3[60] = 0.0;
  out3[61] = 0.0;
  out3[62] = 0.0;
  out3[63] = (((((((t63 * in2[30] + t66 * in2[31]) + t69 * in2[33]) + t75 * in2
                  [27]) + t72 * in2[34]) + t78 * in2[28]) + t81 * in2[32]) + t87
              * in2[29]) + t84 * in2[35];
  out3[64] = (((((((t63 * in2[27] + t66 * in2[28]) + t81 * in2[29]) + t114 *
                  in2[33]) + t115 * in2[34]) + t123 * in2[35]) - t134 * in2[30])
              - t135 * in2[31]) - t138 * in2[32];
  out3[65] = (((((((t69 * in2[27] + t72 * in2[28]) + t84 * in2[29]) - t92 * in2
                  [30]) - t94 * in2[31]) - t103 * in2[32]) - t39 * in2[33]) -
              t49 * in2[34]) - t43 * in2[35];
  out3[66] = 0.0;
  out3[67] = 0.0;
  out3[68] = 0.0;
  out3[69] = (((((((t66 * in2[30] + t72 * in2[33]) + t78 * in2[27]) + t81 * in2
                  [31]) + t87 * in2[28]) + t84 * in2[34]) + t140 * in2[32]) +
              t45 * in2[35]) + in2[29] * (t106 + t106_tmp * t30 * t60 * 2.0);
  out3[70] = (((((((t66 * in2[27] + t81 * in2[28]) + t115 * in2[33]) + t123 *
                  in2[34]) - t135 * in2[30]) - t138 * in2[31]) + t140 * in2[29])
              + t137 * in2[35]) - in2[32] * (t106 - t139);
  out3[71] = (((((((t72 * in2[27] + t84 * in2[28]) - t94 * in2[30]) - t103 *
                  in2[31]) - t49 * in2[33]) - t48 * in2[32]) + t45 * in2[29]) -
              t43 * in2[34]) - in2[35] * (t106 - t44);
  out3[72] = 0.0;
  out3[73] = 0.0;
  out3[74] = 0.0;
  out3[75] = (((((((-t92 * in2[34] + t96 * in2[31]) - t99 * in2[28]) - t94 *
                  in2[35]) - t100 * in2[29]) + t98 * in2[32]) + t141 * in2[30])
              - in2[33] * (t110 - t22 * t24 * t25 * t26 * t60 * 2.0)) - in2[27] *
    (t89 - t90);
  out3[76] = (((((((t96 * in2[28] + t98 * in2[29]) + t141 * in2[27]) + t143 *
                  in2[34]) + t147 * in2[31]) + t145 * in2[35]) + t149 * in2[32])
              + t47 * in2[33]) + in2[30] * (t89 + t57_tmp * t34 * t60 * 2.0);
  out3[77] = (((((((t114 * in2[28] + t115 * in2[29]) + t131 * in2[27]) + t143 *
                  in2[31]) + t145 * in2[32]) + t47 * in2[30]) - t42 * in2[34]) -
              t53 * in2[35]) - in2[33] * (t89 - t46);
  out3[78] = 0.0;
  out3[79] = 0.0;
  out3[80] = 0.0;
  out3[81] = (((((((-t92 * in2[33] + t96 * in2[30]) - t99 * in2[27]) - t94 *
                  in2[34]) - t100 * in2[28]) + t98 * in2[31]) - t107 * in2[29])
              + t105 * in2[32]) - t103 * in2[35];
  out3[82] = (((((((t96 * in2[27] + t98 * in2[28]) + t105 * in2[29]) + t143 *
                  in2[33]) + t147 * in2[30]) + t145 * in2[34]) + t149 * in2[31])
              + t154 * in2[32]) + t152 * in2[35];
  out3[83] = (((((((t114 * in2[27] + t115 * in2[28]) + t123 * in2[29]) + t143 *
                  in2[30]) + t145 * in2[31]) + t152 * in2[32]) - t42 * in2[33])
              - t53 * in2[34]) - t5 * in2[35];
  out3[84] = 0.0;
  out3[85] = 0.0;
  out3[86] = 0.0;
  out3[87] = (((((((-t94 * in2[33] - t100 * in2[27]) + t98 * in2[30]) - t107 *
                  in2[28]) + t105 * in2[31]) - t103 * in2[34]) + t150 * in2[32])
              - in2[29] * (t108 - t109)) - in2[35] * (t124 - t22 * t23 * t24 *
    t25 * t26 * t60 * 2.0);
  out3[88] = (((((((t98 * in2[27] + t105 * in2[28]) + t145 * in2[33]) + t149 *
                  in2[30]) + t150 * in2[29]) + t154 * in2[31]) + t152 * in2[34])
              + t54 * in2[35]) + in2[32] * (t108 + t108_tmp * t34 * t60 * 2.0);
  out3[89] = (((((((t115 * in2[27] + t123 * in2[28]) + t137 * in2[29]) + t145 *
                  in2[30]) + t152 * in2[31]) - t53 * in2[33]) - t5 * in2[34]) +
              t54 * in2[32]) - in2[35] * (t108 - t7);
  out3[90] = 0.0;
  out3[91] = 0.0;
  out3[92] = 0.0;
  out3[93] = (((((((t114 * in2[31] + t115 * in2[32]) - t121 * in2[28]) - t122 *
                  in2[29]) + t118 * in2[34]) + t120 * in2[35]) + t131 * in2[30])
              + t57 * in2[33]) - in2[27] * (t112 - t113);
  out3[94] = (((((((-t92 * in2[28] - t94 * in2[29]) + t157 * in2[34]) - t160 *
                  in2[31]) - t161 * in2[32]) - t62 * in2[27]) + t159 * in2[35])
              + t52 * in2[33]) - in2[30] * (t112 - t155);
  out3[95] = (((((((t118 * in2[28] + t120 * in2[29]) + t157 * in2[31]) + t159 *
                  in2[32]) + t57 * in2[27]) + t52 * in2[30]) + t4 * in2[34]) +
              t18 * in2[35]) + in2[33] * (t112 + t44_tmp * t38 * t60 * 2.0);
  out3[96] = 0.0;
  out3[97] = 0.0;
  out3[98] = 0.0;
  out3[99] = (((((((t114 * in2[30] + t115 * in2[31]) - t121 * in2[27]) - t122 *
                  in2[28]) + t118 * in2[33]) + t120 * in2[34]) + t123 * in2[32])
              - t127 * in2[29]) + t126 * in2[35];
  out3[100] = (((((((-t92 * in2[27] - t94 * in2[28]) - t103 * in2[29]) + t157 *
                   in2[33]) - t160 * in2[30]) - t161 * in2[31]) + t159 * in2[34])
               - t116 * in2[32]) + t41 * in2[35];
  out3[101] = (((((((t118 * in2[27] + t120 * in2[28]) + t126 * in2[29]) + t157 *
                   in2[30]) + t159 * in2[31]) + t41 * in2[32]) + t4 * in2[33]) +
               t18 * in2[34]) + t8 * in2[35];
  out3[102] = 0.0;
  out3[103] = 0.0;
  out3[104] = 0.0;
  out3[105] = (((((((t115 * in2[30] - t122 * in2[27]) + t120 * in2[33]) + t123 *
                   in2[31]) - t127 * in2[28]) + t126 * in2[34]) + t137 * in2[32])
               + t21 * in2[35]) - in2[29] * (t128 - t129);
  out3[106] = (((((((-t94 * in2[27] - t103 * in2[28]) - t161 * in2[30]) + t159 *
                   in2[33]) - t116 * in2[31]) + t41 * in2[34]) - t48 * in2[29])
               + t2 * in2[35]) - in2[32] * (t128 - t165);
  out3[107] = (((((((t120 * in2[27] + t126 * in2[28]) + t159 * in2[30]) + t41 *
                   in2[31]) + t21 * in2[29]) + t18 * in2[33]) + t2 * in2[32]) +
               t8 * in2[34]) + in2[35] * (t128 + t128_tmp * t38 * t60 * 2.0);
  out4[0] = in1[12];
  out4[1] = in1[13];
  out4[2] = in1[14];
  out4[3] = 0.0;
  out4[4] = 0.0;
  out4[5] = 0.0;
}

/* End of code generation (massF1.c) */
