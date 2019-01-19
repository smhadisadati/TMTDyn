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
#include "sqrt.h"
#include "EOM_data.h"

/* Variable Definitions */
static emlrtRSInfo ub_emlrtRSI = { 42, /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

static emlrtRSInfo vb_emlrtRSI = { 44, /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

static emlrtRSInfo wb_emlrtRSI = { 45, /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

static emlrtRSInfo xb_emlrtRSI = { 48, /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

static emlrtRSInfo yb_emlrtRSI = { 50, /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

static emlrtRSInfo ac_emlrtRSI = { 51, /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

static emlrtRSInfo bc_emlrtRSI = { 60, /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

static emlrtRSInfo cc_emlrtRSI = { 62, /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

static emlrtRSInfo dc_emlrtRSI = { 64, /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

static emlrtRSInfo ec_emlrtRSI = { 65, /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

static emlrtRSInfo fc_emlrtRSI = { 81, /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

static emlrtRSInfo gc_emlrtRSI = { 82, /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

static emlrtRSInfo hc_emlrtRSI = { 83, /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

static emlrtRSInfo ic_emlrtRSI = { 85, /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

static emlrtRSInfo jc_emlrtRSI = { 86, /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

static emlrtRSInfo kc_emlrtRSI = { 114,/* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

static emlrtRSInfo lc_emlrtRSI = { 154,/* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

/* Function Definitions */
void massF1(const emlrtStack *sp, const real_T in1[34], const real_T in2[48],
            real_T s, real_T out1[36], real_T out2[144], real_T out3[144],
            real_T out4[6])
{
  real_T t2;
  real_T t4;
  real_T t5;
  real_T t7;
  real_T t8;
  real_T t80;
  real_T t43;
  real_T t83;
  real_T t22;
  real_T t23;
  real_T t24;
  real_T t25;
  real_T t26;
  real_T t31;
  real_T t36;
  real_T t41;
  real_T t42;
  real_T t44;
  real_T t45;
  real_T t46;
  real_T t47_tmp;
  real_T t47;
  real_T t48_tmp;
  real_T t219;
  real_T t48;
  real_T t230;
  real_T t49_tmp;
  real_T t49;
  real_T t222;
  real_T t231;
  real_T t50;
  real_T t51_tmp;
  real_T t51;
  real_T t221;
  real_T t225;
  real_T t52;
  real_T t53;
  real_T t54;
  real_T t55;
  real_T t56;
  real_T t57;
  real_T t58;
  real_T t59;
  real_T t60;
  real_T t64_tmp;
  real_T t65;
  real_T t217;
  real_T t66;
  real_T t67;
  real_T t68_tmp;
  real_T t68;
  real_T t224;
  real_T t69;
  real_T t70;
  real_T t72;
  real_T t73;
  real_T t75;
  real_T t76;
  real_T t78;
  real_T t79;
  real_T t81;
  real_T t82;
  real_T t84;
  real_T t85;
  real_T t87;
  real_T t88;
  real_T t90;
  real_T t91;
  real_T t93;
  real_T t94_tmp;
  real_T t94;
  real_T t96;
  real_T t97;
  real_T t99;
  real_T t100;
  real_T t102;
  real_T t103_tmp;
  real_T t103;
  real_T t105;
  real_T t106;
  real_T t108;
  real_T t109;
  real_T t110;
  real_T t112;
  real_T t113_tmp;
  real_T t113;
  real_T t115;
  real_T t116;
  real_T t117;
  real_T t118;
  real_T t120;
  real_T t122;
  real_T t124;
  real_T t125;
  real_T t126;
  real_T t127;
  real_T t129;
  real_T t131;
  real_T t133;
  real_T t135;
  real_T t136;
  real_T t140;
  real_T t142;
  real_T t143;
  real_T t144;
  real_T t145;
  real_T t146;
  real_T t149;
  real_T t150;
  real_T t151;
  real_T t152;
  real_T t155;
  real_T t156;
  real_T t157;
  real_T t158;
  real_T t159;
  real_T t160;
  real_T t161;
  real_T t162;
  real_T t163;
  real_T t164;
  real_T t165;
  real_T t167;
  real_T t168;
  real_T t169;
  real_T t172;
  real_T t173;
  real_T t174;
  real_T t175;
  real_T t176;
  real_T t177;
  real_T t178;
  real_T t179;
  real_T t181;
  real_T t182;
  real_T t183;
  real_T t184;
  real_T t185;
  real_T t186;
  real_T t187;
  real_T t188;
  real_T t190;
  real_T t191;
  real_T t193;
  real_T t195;
  real_T t197;
  real_T t199;
  real_T t201;
  real_T t203;
  real_T t205;
  real_T t207;
  real_T t209;
  real_T t210;
  real_T t212;
  real_T t213;
  real_T t215;
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
  /*     05-Jan-2019 01:25:15 */
  st.site = &ub_emlrtRSI;
  b_st.site = &rb_emlrtRSI;
  t2 = in1[18] * in1[18];
  st.site = &vb_emlrtRSI;
  b_st.site = &rb_emlrtRSI;
  t4 = in1[2] * in1[2];
  st.site = &wb_emlrtRSI;
  b_st.site = &rb_emlrtRSI;
  t5 = in1[3] * in1[3];
  t7 = muDoubleScalarSin(in1[20]);
  st.site = &xb_emlrtRSI;
  b_st.site = &rb_emlrtRSI;
  t8 = 1.0 / (t7 * t7);
  t80 = muDoubleScalarCos(in1[20]);
  st.site = &yb_emlrtRSI;
  b_st.site = &rb_emlrtRSI;
  st.site = &ac_emlrtRSI;
  b_st.site = &rb_emlrtRSI;
  t80 = in1[33] * in1[33] * (t80 * t80);
  t43 = in1[0] * (t4 - t5);
  st.site = &bc_emlrtRSI;
  b_st.site = &rb_emlrtRSI;
  st.site = &cc_emlrtRSI;
  b_st.site = &rb_emlrtRSI;
  st.site = &cc_emlrtRSI;
  b_st.site = &rb_emlrtRSI;
  st.site = &cc_emlrtRSI;
  b_st.site = &rb_emlrtRSI;
  t83 = -in1[0] * ((t2 * 6.0 + t4) - t5) * 3.1415926535897931;
  out1[0] = t83;
  out1[1] = 0.0;
  out1[2] = 0.0;
  out1[3] = 0.0;
  out1[4] = 0.0;
  out1[5] = 0.0;
  out1[6] = 0.0;
  out1[7] = t83;
  out1[8] = 0.0;
  out1[9] = 0.0;
  out1[10] = 0.0;
  out1[11] = 0.0;
  out1[12] = 0.0;
  out1[13] = 0.0;
  out1[14] = t83;
  out1[15] = 0.0;
  out1[16] = 0.0;
  out1[17] = 0.0;
  out1[18] = 0.0;
  out1[19] = 0.0;
  out1[20] = 0.0;
  t83 = t43 * (t4 / 4.0 - t5 / 4.0) * 3.1415926535897931 - in1[0] * t2 * t8 *
    (t80 - 1.0) * 3.1415926535897931 * (t2 * t8 * (t80 - 1.0) * 1.5 + 1.0 / in1
    [33] * (in1[19] * in1[19]) * 3.0);
  out1[21] = t83;
  out1[22] = 0.0;
  out1[23] = 0.0;
  out1[24] = 0.0;
  out1[25] = 0.0;
  out1[26] = 0.0;
  out1[27] = 0.0;
  out1[28] = t83;
  out1[29] = 0.0;
  out1[30] = 0.0;
  out1[31] = 0.0;
  out1[32] = 0.0;
  out1[33] = 0.0;
  out1[34] = 0.0;
  out1[35] = t43 * 3.1415926535897931 * (t4 / 2.0 - t5 / 2.0) - in1[0] * (t2 *
    t2) / muDoubleScalarPower(t7, 4.0) * ((t80 - 1.0) * (t80 - 1.0)) *
    3.1415926535897931 * 3.0;
  st.site = &dc_emlrtRSI;
  b_st.site = &rb_emlrtRSI;
  t22 = s * s;
  st.site = &ec_emlrtRSI;
  b_st.site = &rb_emlrtRSI;
  t23 = t22 * t22;
  t24 = ((in2[12] * s + in2[13] * t22) + in2[14] * s * t22) + in2[15] * t23;
  t25 = ((in2[16] * s + in2[17] * t22) + in2[18] * s * t22) + in2[19] * t23;
  t26 = ((in2[20] * s + in2[21] * t22) + in2[22] * s * t22) + in2[23] * t23;
  st.site = &fc_emlrtRSI;
  b_st.site = &rb_emlrtRSI;
  t31 = t24 * t24;
  st.site = &gc_emlrtRSI;
  b_st.site = &rb_emlrtRSI;
  t36 = t25 * t25;
  st.site = &hc_emlrtRSI;
  b_st.site = &rb_emlrtRSI;
  t41 = t26 * t26;
  t42 = ((-t31 - t36) - t41) + 1.0;
  t43 = t42;
  st.site = &ic_emlrtRSI;
  b_sqrt(&st, &t43);
  t80 = t42;
  st.site = &jc_emlrtRSI;
  b_sqrt(&st, &t80);
  t44 = 1.0 / t80;
  t45 = s * t26 * 2.0;
  t80 = s * t24;
  t46 = t80 * t25 * t44 * 2.0;
  t47_tmp = t22 * t26;
  t47 = t47_tmp * 2.0;
  t48_tmp = t22 * t24;
  t219 = t48_tmp * t25;
  t48 = t219 * t44 * 2.0;
  t230 = s * t22;
  t49_tmp = t230 * t26;
  t49 = t49_tmp * 2.0;
  t222 = t230 * t24;
  t231 = t222 * t25;
  t50 = t231 * t44 * 2.0;
  t51_tmp = t23 * t26;
  t51 = t51_tmp * 2.0;
  t221 = t23 * t24;
  t225 = t221 * t25;
  t52 = t225 * t44 * 2.0;
  t53 = s * t43 * 2.0;
  t54 = t22 * t43 * 2.0;
  t55 = t230 * t43 * 2.0;
  t56 = t23 * t43 * 2.0;
  t57 = t80 * t26 * t44 * 2.0;
  t58 = t48_tmp * t26 * t44 * 2.0;
  t59 = t222 * t26 * t44 * 2.0;
  t60 = t221 * t26 * t44 * 2.0;
  t5 = t80 * 2.0;
  t80 = s * t25;
  t7 = t80 * t26 * t44 * 2.0;
  t8 = t48_tmp * 2.0;
  t64_tmp = t22 * t25;
  t43 = t64_tmp * t26 * t44 * 2.0;
  t65 = t222 * 2.0;
  t217 = t230 * t25;
  t66 = t217 * t26 * t44 * 2.0;
  t67 = t221 * 2.0;
  t68_tmp = t23 * t25;
  t68 = t68_tmp * t26 * t44 * 2.0;
  out2[0] = t22;
  out2[1] = 0.0;
  out2[2] = 0.0;
  out2[3] = 0.0;
  out2[4] = 0.0;
  out2[5] = 0.0;
  out2[6] = t230;
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
  t224 = s * t23;
  out2[18] = t224;
  out2[19] = 0.0;
  out2[20] = 0.0;
  out2[21] = 0.0;
  out2[22] = 0.0;
  out2[23] = 0.0;
  out2[24] = 0.0;
  out2[25] = t22;
  out2[26] = 0.0;
  out2[27] = 0.0;
  out2[28] = 0.0;
  out2[29] = 0.0;
  out2[30] = 0.0;
  out2[31] = t230;
  out2[32] = 0.0;
  out2[33] = 0.0;
  out2[34] = 0.0;
  out2[35] = 0.0;
  out2[36] = 0.0;
  out2[37] = t23;
  out2[38] = 0.0;
  out2[39] = 0.0;
  out2[40] = 0.0;
  out2[41] = 0.0;
  out2[42] = 0.0;
  out2[43] = t224;
  out2[44] = 0.0;
  out2[45] = 0.0;
  out2[46] = 0.0;
  out2[47] = 0.0;
  out2[48] = 0.0;
  out2[49] = 0.0;
  out2[50] = t22;
  out2[51] = 0.0;
  out2[52] = 0.0;
  out2[53] = 0.0;
  out2[54] = 0.0;
  out2[55] = 0.0;
  out2[56] = t230;
  out2[57] = 0.0;
  out2[58] = 0.0;
  out2[59] = 0.0;
  out2[60] = 0.0;
  out2[61] = 0.0;
  out2[62] = t23;
  out2[63] = 0.0;
  out2[64] = 0.0;
  out2[65] = 0.0;
  out2[66] = 0.0;
  out2[67] = 0.0;
  out2[68] = t224;
  out2[69] = 0.0;
  out2[70] = 0.0;
  out2[71] = 0.0;
  out2[72] = 0.0;
  out2[73] = 0.0;
  out2[74] = 0.0;
  out2[75] = t53 + s * t31 * t44 * 2.0;
  out2[76] = -t45 + t46;
  t80 *= 2.0;
  out2[77] = t57 + t80;
  out2[78] = 0.0;
  out2[79] = 0.0;
  out2[80] = 0.0;
  out2[81] = t54 + t22 * t31 * t44 * 2.0;
  out2[82] = -t47 + t48;
  t83 = t64_tmp * 2.0;
  out2[83] = t58 + t83;
  out2[84] = 0.0;
  out2[85] = 0.0;
  out2[86] = 0.0;
  out2[87] = t55 + t230 * t31 * t44 * 2.0;
  out2[88] = -t49 + t50;
  t2 = t217 * 2.0;
  out2[89] = t59 + t2;
  out2[90] = 0.0;
  out2[91] = 0.0;
  out2[92] = 0.0;
  out2[93] = t56 + t23 * t31 * t44 * 2.0;
  out2[94] = -t51 + t52;
  t4 = t68_tmp * 2.0;
  out2[95] = t60 + t4;
  out2[96] = 0.0;
  out2[97] = 0.0;
  out2[98] = 0.0;
  out2[99] = t45 + t46;
  out2[100] = t53 + s * t36 * t44 * 2.0;
  out2[101] = -t5 + t7;
  out2[102] = 0.0;
  out2[103] = 0.0;
  out2[104] = 0.0;
  out2[105] = t47 + t48;
  out2[106] = t54 + t22 * t36 * t44 * 2.0;
  out2[107] = -t8 + t43;
  out2[108] = 0.0;
  out2[109] = 0.0;
  out2[110] = 0.0;
  out2[111] = t49 + t50;
  out2[112] = t55 + t230 * t36 * t44 * 2.0;
  out2[113] = -t65 + t66;
  out2[114] = 0.0;
  out2[115] = 0.0;
  out2[116] = 0.0;
  out2[117] = t51 + t52;
  out2[118] = t56 + t23 * t36 * t44 * 2.0;
  out2[119] = -t67 + t68;
  out2[120] = 0.0;
  out2[121] = 0.0;
  out2[122] = 0.0;
  out2[123] = t57 - t80;
  out2[124] = t5 + t7;
  out2[125] = t53 + s * t41 * t44 * 2.0;
  out2[126] = 0.0;
  out2[127] = 0.0;
  out2[128] = 0.0;
  out2[129] = t58 - t83;
  out2[130] = t8 + t43;
  out2[131] = t54 + t22 * t41 * t44 * 2.0;
  out2[132] = 0.0;
  out2[133] = 0.0;
  out2[134] = 0.0;
  out2[135] = t59 - t2;
  out2[136] = t65 + t66;
  out2[137] = t55 + t230 * t41 * t44 * 2.0;
  out2[138] = 0.0;
  out2[139] = 0.0;
  out2[140] = 0.0;
  out2[141] = t60 - t4;
  out2[142] = t67 + t68;
  out2[143] = t56 + t23 * t41 * t44 * 2.0;
  st.site = &kc_emlrtRSI;
  b_st.site = &rb_emlrtRSI;
  if (t42 < 0.0) {
    c_st.site = &sb_emlrtRSI;
    error(&c_st);
  }

  t69 = 1.0 / muDoubleScalarPower(t42, 1.5);
  t70 = t222 * t44 * 2.0;
  t72 = t70 + t222 * t31 * t69 * 2.0;
  t73 = t221 * t44 * 2.0;
  t75 = t73 + t221 * t31 * t69 * 2.0;
  t66 = t224 * t24;
  t76 = t66 * t44 * 2.0;
  t78 = t76 + t66 * t31 * t69 * 2.0;
  t79 = t217 * t44 * 2.0;
  t80 = t217 * t31 * t69 * 2.0;
  t81 = t79 + t80;
  t82 = t68_tmp * t44 * 2.0;
  t83 = t68_tmp * t31 * t69 * 2.0;
  t84 = t82 + t83;
  t53 = t224 * t25;
  t85 = t53 * t44 * 2.0;
  t2 = t53 * t31 * t69 * 2.0;
  t87 = t85 + t2;
  t88 = t49_tmp * t44 * 2.0;
  t57 = t49_tmp * t31 * t69 * 2.0;
  t90 = t88 + t57;
  t91 = t51_tmp * t44 * 2.0;
  t58 = t51_tmp * t31 * t69 * 2.0;
  t93 = t91 + t58;
  t94_tmp = t224 * t26;
  t94 = t94_tmp * t44 * 2.0;
  t59 = t94_tmp * t31 * t69 * 2.0;
  t96 = t94 + t59;
  t5 = t22 * t23;
  t60 = t5 * t24;
  t97 = t60 * t44 * 2.0;
  t99 = t97 + t60 * t31 * t69 * 2.0;
  t55 = t5 * t25;
  t100 = t55 * t44 * 2.0;
  t4 = t55 * t31 * t69 * 2.0;
  t102 = t100 + t4;
  t103_tmp = t5 * t26;
  t103 = t103_tmp * t44 * 2.0;
  t45 = t103_tmp * t31 * t69 * 2.0;
  t105 = t103 + t45;
  t8 = t230 * t23;
  t46 = t8 * t24;
  t106 = t46 * t44 * 2.0;
  t108 = t106 + t46 * t31 * t69 * 2.0;
  st.site = &lc_emlrtRSI;
  b_st.site = &rb_emlrtRSI;
  t109 = t23 * t23;
  t42 = t8 * t25;
  t110 = t42 * t44 * 2.0;
  t7 = t42 * t31 * t69 * 2.0;
  t112 = t110 + t7;
  t113_tmp = t8 * t26;
  t113 = t113_tmp * t44 * 2.0;
  t47 = t113_tmp * t31 * t69 * 2.0;
  t115 = t113 + t47;
  t116 = t48_tmp * t44 * 2.0;
  t117 = t64_tmp * t44 * 2.0;
  t118 = t64_tmp * t31 * t69 * 2.0;
  t50 = t222 * t36 * t69 * 2.0;
  t120 = t70 + t50;
  t51 = t221 * t36 * t69 * 2.0;
  t122 = t73 + t51;
  t52 = t66 * t36 * t69 * 2.0;
  t124 = t76 + t52;
  t125 = t79 - t80;
  t126 = t82 - t83;
  t127 = t85 - t2;
  t56 = t230 * 2.0;
  t67 = t231 * t26 * t69 * 2.0;
  t129 = t56 - t67;
  t68 = t23 * 2.0;
  t2 = t225 * t26 * t69 * 2.0;
  t131 = t68 - t2;
  t43 = t224 * 2.0;
  t65 = t66 * t25 * t26 * t69 * 2.0;
  t133 = t43 - t65;
  t49 = t60 * t36 * t69 * 2.0;
  t135 = t97 + t49;
  t136 = t100 - t4;
  t4 = t5 * 2.0;
  t5 = t60 * t25 * t26 * t69 * 2.0;
  t140 = t4 - t5;
  t48 = t46 * t36 * t69 * 2.0;
  t142 = t106 + t48;
  t143 = t24 * t44 * t109 * 2.0;
  t144 = t110 - t7;
  t145 = t25 * t44 * t109 * 2.0;
  t146 = t25 * t31 * t69 * t109 * 2.0;
  t7 = t8 * 2.0;
  t8 = t46 * t25 * t26 * t69 * 2.0;
  t149 = t7 - t8;
  t150 = t47_tmp * t44 * 2.0;
  t151 = t47_tmp * t31 * t69 * 2.0;
  t152 = t22 * 2.0;
  t54 = t222 * t41 * t69 * 2.0;
  t155 = t70 + t54;
  t156 = t221 * t41 * t69 * 2.0;
  t157 = t73 + t156;
  t158 = t66 * t41 * t69 * 2.0;
  t159 = t76 + t158;
  t160 = t88 - t57;
  t161 = t91 - t58;
  t162 = t94 - t59;
  t163 = t56 + t67;
  t164 = t68 + t2;
  t165 = t43 + t65;
  t57 = t60 * t41 * t69 * 2.0;
  t167 = t97 + t57;
  t168 = t103 - t45;
  t169 = t4 + t5;
  t56 = t46 * t41 * t69 * 2.0;
  t172 = t106 + t56;
  t173 = t113 - t47;
  t174 = t26 * t44 * t109 * 2.0;
  t175 = t26 * t31 * t69 * t109 * 2.0;
  t176 = t7 + t8;
  t177 = t109 * 2.0;
  t178 = t48_tmp * t36 * t69 * 2.0;
  t179 = t117 + t118;
  t43 = t219 * t26 * t69 * 2.0;
  t181 = t152 + t43;
  t182 = t70 - t50;
  t183 = t73 - t51;
  t184 = t76 - t52;
  t185 = t97 - t49;
  t186 = t106 - t48;
  t187 = t24 * t36 * t69 * t109 * 2.0;
  t188 = t145 + t146;
  t65 = t24 * t25 * t26 * t69 * t109 * 2.0;
  t190 = t177 + t65;
  t191 = t116 + t178;
  t193 = t79 + t217 * t36 * t69 * 2.0;
  t195 = t82 + t68_tmp * t36 * t69 * 2.0;
  t197 = t85 + t53 * t36 * t69 * 2.0;
  t2 = t49_tmp * t36 * t69 * 2.0;
  t199 = t88 + t2;
  t4 = t51_tmp * t36 * t69 * 2.0;
  t201 = t91 + t4;
  t5 = t94_tmp * t36 * t69 * 2.0;
  t203 = t94 + t5;
  t205 = t100 + t55 * t36 * t69 * 2.0;
  t7 = t103_tmp * t36 * t69 * 2.0;
  t207 = t103 + t7;
  t209 = t110 + t42 * t36 * t69 * 2.0;
  t210 = t143 + t187;
  t8 = t113_tmp * t36 * t69 * 2.0;
  t212 = t113 + t8;
  t213 = t47_tmp * t36 * t69 * 2.0;
  t66 = t217 * t41 * t69 * 2.0;
  t215 = t79 + t66;
  t67 = t68_tmp * t41 * t69 * 2.0;
  t217 = t82 + t67;
  t68 = t53 * t41 * t69 * 2.0;
  t219 = t85 + t68;
  t44 = t88 - t2;
  t221 = t91 - t4;
  t222 = t94 - t5;
  t4 = t55 * t41 * t69 * 2.0;
  t224 = t100 + t4;
  t225 = t103 - t7;
  t2 = t42 * t41 * t69 * 2.0;
  t23 = t110 + t2;
  t80 = t113 - t8;
  t83 = t26 * t36 * t69 * t109 * 2.0;
  t230 = t48_tmp * t41 * t69 * 2.0;
  t231 = t150 + t151;
  t42 = t152 - t43;
  t55 = t70 - t54;
  t54 = t73 - t156;
  t53 = t76 - t158;
  t52 = t97 - t57;
  t49 = t106 - t56;
  t50 = t24 * t41 * t69 * t109 * 2.0;
  t51 = t174 + t175;
  t46 = t177 - t65;
  t47 = t64_tmp * t41 * t69 * 2.0;
  t48 = t150 + t213;
  t45 = t79 - t66;
  t60 = t82 - t67;
  t59 = t85 - t68;
  t58 = t100 - t4;
  t66 = t110 - t2;
  t67 = t25 * t41 * t69 * t109 * 2.0;
  t68 = t174 + t83;
  t56 = t116 + t230;
  t57 = t117 + t47;
  t65 = t88 + t49_tmp * t41 * t69 * 2.0;
  t43 = t91 + t51_tmp * t41 * t69 * 2.0;
  t8 = t94 + t94_tmp * t41 * t69 * 2.0;
  t7 = t103 + t103_tmp * t41 * t69 * 2.0;
  t2 = t113 + t113_tmp * t41 * t69 * 2.0;
  t4 = t143 + t50;
  t5 = t145 + t67;
  memset(&out3[0], 0, 75U * sizeof(real_T));
  out3[75] = ((((((((((t72 * in2[37] + t75 * in2[38]) + t78 * in2[39]) + t81 *
                     in2[41]) + t84 * in2[42]) + t87 * in2[43]) + t90 * in2[45])
                 + t93 * in2[46]) + t96 * in2[47]) + t179 * in2[40]) + t231 *
              in2[44]) + in2[36] * (t116 + t48_tmp * t31 * t69 * 2.0);
  out3[76] = ((((((((((t81 * in2[37] + t84 * in2[38]) + t87 * in2[39]) + t163 *
                     in2[45]) + t164 * in2[46]) + t165 * in2[47]) + t179 * in2
                  [36]) - t182 * in2[41]) + t181 * in2[44]) - t183 * in2[42]) -
              t184 * in2[43]) - in2[40] * (t116 - t178);
  out3[77] = ((((((((((t90 * in2[37] + t93 * in2[38]) + t96 * in2[39]) - t129 *
                     in2[41]) - t131 * in2[42]) - t133 * in2[43]) + t231 * in2
                  [36]) - t42 * in2[40]) - t55 * in2[45]) - t54 * in2[46]) - t53
              * in2[47]) - in2[44] * (t116 - t230);
  out3[78] = 0.0;
  out3[79] = 0.0;
  out3[80] = 0.0;
  out3[81] = ((((((((((t72 * in2[36] + t75 * in2[37]) + t78 * in2[38]) + t81 *
                     in2[40]) + t84 * in2[41]) + t87 * in2[42]) + t90 * in2[44])
                 + t93 * in2[45]) + t99 * in2[39]) + t96 * in2[46]) + t102 *
              in2[43]) + t105 * in2[47];
  out3[82] = ((((((((((t81 * in2[36] + t84 * in2[37]) + t87 * in2[38]) + t102 *
                     in2[39]) + t163 * in2[44]) + t164 * in2[45]) + t165 * in2
                  [46]) + t169 * in2[47]) - t182 * in2[40]) - t183 * in2[41]) -
              t184 * in2[42]) - t185 * in2[43];
  out3[83] = ((((((((((t90 * in2[36] + t93 * in2[37]) + t96 * in2[38]) + t105 *
                     in2[39]) - t129 * in2[40]) - t131 * in2[41]) - t133 * in2
                  [42]) - t140 * in2[43]) - t55 * in2[44]) - t54 * in2[45]) -
              t53 * in2[46]) - t52 * in2[47];
  out3[84] = 0.0;
  out3[85] = 0.0;
  out3[86] = 0.0;
  out3[87] = ((((((((((t75 * in2[36] + t78 * in2[37]) + t84 * in2[40]) + t87 *
                     in2[41]) + t93 * in2[44]) + t99 * in2[38]) + t96 * in2[45])
                 + t102 * in2[42]) + t108 * in2[39]) + t105 * in2[46]) + t112 *
              in2[43]) + t115 * in2[47];
  out3[88] = ((((((((((t84 * in2[36] + t87 * in2[37]) + t102 * in2[38]) + t112 *
                     in2[39]) + t164 * in2[44]) + t165 * in2[45]) + t169 * in2
                  [46]) + t176 * in2[47]) - t183 * in2[40]) - t184 * in2[41]) -
              t185 * in2[42]) - t186 * in2[43];
  out3[89] = ((((((((((t93 * in2[36] + t96 * in2[37]) + t105 * in2[38]) + t115 *
                     in2[39]) - t131 * in2[40]) - t133 * in2[41]) - t140 * in2
                  [42]) - t149 * in2[43]) - t54 * in2[44]) - t53 * in2[45]) -
              t52 * in2[46]) - t49 * in2[47];
  out3[90] = 0.0;
  out3[91] = 0.0;
  out3[92] = 0.0;
  out3[93] = ((((((((((t78 * in2[36] + t87 * in2[40]) + t99 * in2[37]) + t96 *
                     in2[44]) + t102 * in2[41]) + t108 * in2[38]) + t105 * in2
                  [45]) + t112 * in2[42]) + t115 * in2[46]) + t188 * in2[43]) +
              t51 * in2[47]) + in2[39] * (t143 + t24 * t31 * t69 * t109 * 2.0);
  out3[94] = ((((((((((t87 * in2[36] + t102 * in2[37]) + t112 * in2[38]) + t165 *
                     in2[44]) + t169 * in2[45]) + t176 * in2[46]) - t184 * in2
                  [40]) - t185 * in2[41]) + t188 * in2[39]) - t186 * in2[42]) +
              t190 * in2[47]) - in2[43] * (t143 - t187);
  out3[95] = ((((((((((t96 * in2[36] + t105 * in2[37]) + t115 * in2[38]) - t133 *
                     in2[40]) - t140 * in2[41]) - t149 * in2[42]) + t51 * in2[39])
                 - t53 * in2[44]) - t52 * in2[45]) - t49 * in2[46]) - t46 * in2
              [43]) - in2[47] * (t143 - t50);
  out3[96] = 0.0;
  out3[97] = 0.0;
  out3[98] = 0.0;
  out3[99] = ((((((((((t120 * in2[41] - t125 * in2[37]) + t122 * in2[42]) - t126
                     * in2[38]) - t127 * in2[39]) + t124 * in2[43]) - t129 *
                  in2[45]) - t131 * in2[46]) - t133 * in2[47]) + t191 * in2[40])
              - in2[44] * (t152 - t22 * t24 * t25 * t26 * t69 * 2.0)) - in2[36] *
    (t117 - t118);
  out3[100] = ((((((((((t120 * in2[37] + t122 * in2[38]) + t124 * in2[39]) +
                      t191 * in2[36]) + t193 * in2[41]) + t195 * in2[42]) + t197
                   * in2[43]) + t199 * in2[45]) + t201 * in2[46]) + t203 * in2
                [47]) + t48 * in2[44]) + in2[40] * (t117 + t64_tmp * t36 * t69 *
    2.0);
  out3[101] = ((((((((((t163 * in2[37] + t164 * in2[38]) + t165 * in2[39]) +
                      t181 * in2[36]) + t199 * in2[41]) + t201 * in2[42]) + t203
                   * in2[43]) + t48 * in2[40]) - t45 * in2[45]) - t60 * in2[46])
               - t59 * in2[47]) - in2[44] * (t117 - t47);
  out3[102] = 0.0;
  out3[103] = 0.0;
  out3[104] = 0.0;
  out3[105] = ((((((((((t120 * in2[40] - t125 * in2[36]) + t122 * in2[41]) -
                      t126 * in2[37]) - t127 * in2[38]) + t124 * in2[42]) - t129
                   * in2[44]) - t136 * in2[39]) - t131 * in2[45]) + t135 * in2
                [43]) - t133 * in2[46]) - t140 * in2[47];
  out3[106] = ((((((((((t120 * in2[36] + t122 * in2[37]) + t124 * in2[38]) +
                      t135 * in2[39]) + t193 * in2[40]) + t195 * in2[41]) + t197
                   * in2[42]) + t199 * in2[44]) + t201 * in2[45]) + t205 * in2
                [43]) + t203 * in2[46]) + t207 * in2[47];
  out3[107] = ((((((((((t163 * in2[36] + t164 * in2[37]) + t165 * in2[38]) +
                      t169 * in2[39]) + t199 * in2[40]) + t201 * in2[41]) + t203
                   * in2[42]) + t207 * in2[43]) - t45 * in2[44]) - t60 * in2[45])
               - t59 * in2[46]) - t58 * in2[47];
  out3[108] = 0.0;
  out3[109] = 0.0;
  out3[110] = 0.0;
  out3[111] = ((((((((((t122 * in2[40] - t126 * in2[36]) - t127 * in2[37]) +
                      t124 * in2[41]) - t136 * in2[38]) - t131 * in2[44]) + t135
                   * in2[42]) - t133 * in2[45]) - t144 * in2[39]) + t142 * in2
                [43]) - t140 * in2[46]) - t149 * in2[47];
  out3[112] = ((((((((((t122 * in2[36] + t124 * in2[37]) + t135 * in2[38]) +
                      t142 * in2[39]) + t195 * in2[40]) + t197 * in2[41]) + t201
                   * in2[44]) + t205 * in2[42]) + t203 * in2[45]) + t209 * in2
                [43]) + t207 * in2[46]) + t212 * in2[47];
  out3[113] = ((((((((((t164 * in2[36] + t165 * in2[37]) + t169 * in2[38]) +
                      t176 * in2[39]) + t201 * in2[40]) + t203 * in2[41]) + t207
                   * in2[42]) + t212 * in2[43]) - t60 * in2[44]) - t59 * in2[45])
               - t58 * in2[46]) - t66 * in2[47];
  out3[114] = 0.0;
  out3[115] = 0.0;
  out3[116] = 0.0;
  out3[117] = ((((((((((-t127 * in2[36] + t124 * in2[40]) - t136 * in2[37]) +
                      t135 * in2[41]) - t133 * in2[44]) - t144 * in2[38]) + t142
                   * in2[42]) - t140 * in2[45]) - t149 * in2[46]) + t210 * in2
                [43]) - in2[47] * (t177 - t24 * t25 * t26 * t69 * t109 * 2.0)) -
    in2[39] * (t145 - t146);
  out3[118] = ((((((((((t124 * in2[36] + t135 * in2[37]) + t142 * in2[38]) +
                      t197 * in2[40]) + t205 * in2[41]) + t203 * in2[44]) + t210
                   * in2[39]) + t209 * in2[42]) + t207 * in2[45]) + t212 * in2
                [46]) + t68 * in2[47]) + in2[43] * (t145 + t25 * t36 * t69 *
    t109 * 2.0);
  out3[119] = ((((((((((t165 * in2[36] + t169 * in2[37]) + t176 * in2[38]) +
                      t190 * in2[39]) + t203 * in2[40]) + t207 * in2[41]) + t212
                   * in2[42]) - t59 * in2[44]) - t58 * in2[45]) + t68 * in2[43])
               - t66 * in2[46]) - in2[47] * (t145 - t67);
  out3[120] = 0.0;
  out3[121] = 0.0;
  out3[122] = 0.0;
  out3[123] = ((((((((((-t160 * in2[37] - t161 * in2[38]) + t155 * in2[45]) -
                      t162 * in2[39]) + t157 * in2[46]) + t163 * in2[41]) + t159
                   * in2[47]) + t164 * in2[42]) + t165 * in2[43]) + t181 * in2
                [40]) + t56 * in2[44]) - in2[36] * (t150 - t151);
  out3[124] = ((((((((((-t129 * in2[37] - t131 * in2[38]) - t133 * in2[39]) +
                      t215 * in2[45]) - t44 * in2[41]) + t217 * in2[46]) - t221 *
                   in2[42]) - t222 * in2[43]) + t219 * in2[47]) - t42 * in2[36])
               + t57 * in2[44]) - in2[40] * (t150 - t213);
  out3[125] = ((((((((((t155 * in2[37] + t157 * in2[38]) + t159 * in2[39]) +
                      t215 * in2[41]) + t217 * in2[42]) + t219 * in2[43]) + t56 *
                   in2[36]) + t57 * in2[40]) + t65 * in2[45]) + t43 * in2[46]) +
               t8 * in2[47]) + in2[44] * (t150 + t47_tmp * t41 * t69 * 2.0);
  out3[126] = 0.0;
  out3[127] = 0.0;
  out3[128] = 0.0;
  out3[129] = ((((((((((-t160 * in2[36] - t161 * in2[37]) + t155 * in2[44]) -
                      t162 * in2[38]) + t157 * in2[45]) + t163 * in2[40]) + t159
                   * in2[46]) + t164 * in2[41]) + t165 * in2[42]) - t168 * in2
                [39]) + t169 * in2[43]) + t167 * in2[47];
  out3[130] = ((((((((((-t129 * in2[36] - t131 * in2[37]) - t133 * in2[38]) -
                      t140 * in2[39]) + t215 * in2[44]) - t44 * in2[40]) + t217 *
                   in2[45]) - t221 * in2[41]) - t222 * in2[42]) + t219 * in2[46])
               - t225 * in2[43]) + t224 * in2[47];
  out3[131] = ((((((((((t155 * in2[36] + t157 * in2[37]) + t159 * in2[38]) +
                      t167 * in2[39]) + t215 * in2[40]) + t217 * in2[41]) + t219
                   * in2[42]) + t224 * in2[43]) + t65 * in2[44]) + t43 * in2[45])
               + t8 * in2[46]) + t7 * in2[47];
  out3[132] = 0.0;
  out3[133] = 0.0;
  out3[134] = 0.0;
  out3[135] = ((((((((((-t161 * in2[36] - t162 * in2[37]) + t157 * in2[44]) +
                      t159 * in2[45]) + t164 * in2[40]) + t165 * in2[41]) - t168
                   * in2[38]) + t169 * in2[42]) - t173 * in2[39]) + t167 * in2
                [46]) + t172 * in2[47]) + t176 * in2[43];
  out3[136] = ((((((((((-t131 * in2[36] - t133 * in2[37]) - t140 * in2[38]) -
                      t149 * in2[39]) + t217 * in2[44]) - t221 * in2[40]) - t222
                   * in2[41]) + t219 * in2[45]) - t225 * in2[42]) + t224 * in2
                [46]) - t80 * in2[43]) + t23 * in2[47];
  out3[137] = ((((((((((t157 * in2[36] + t159 * in2[37]) + t167 * in2[38]) +
                      t172 * in2[39]) + t217 * in2[40]) + t219 * in2[41]) + t224
                   * in2[42]) + t23 * in2[43]) + t43 * in2[44]) + t8 * in2[45])
               + t7 * in2[46]) + t2 * in2[47];
  out3[138] = 0.0;
  out3[139] = 0.0;
  out3[140] = 0.0;
  out3[141] = ((((((((((-t162 * in2[36] + t159 * in2[44]) + t165 * in2[40]) -
                      t168 * in2[37]) + t169 * in2[41]) - t173 * in2[38]) + t167
                   * in2[45]) + t172 * in2[46]) + t176 * in2[42]) + t190 * in2
                [43]) + t4 * in2[47]) - in2[39] * (t174 - t175);
  out3[142] = ((((((((((-t133 * in2[36] - t140 * in2[37]) - t149 * in2[38]) -
                      t222 * in2[40]) + t219 * in2[44]) - t225 * in2[41]) + t224
                   * in2[45]) - t80 * in2[42]) + t23 * in2[46]) - t46 * in2[39])
               + t5 * in2[47]) - in2[43] * (t174 - t83);
  out3[143] = ((((((((((t159 * in2[36] + t167 * in2[37]) + t172 * in2[38]) +
                      t219 * in2[40]) + t224 * in2[41]) + t23 * in2[42]) + t8 *
                   in2[44]) + t4 * in2[39]) + t7 * in2[45]) + t5 * in2[43]) + t2
               * in2[46]) + in2[47] * (t174 + t26 * t41 * t69 * t109 * 2.0);
  out4[0] = in1[12];
  out4[1] = in1[13];
  out4[2] = in1[14];
  out4[3] = 0.0;
  out4[4] = 0.0;
  out4[5] = 0.0;
}

/* End of code generation (massF1.c) */
