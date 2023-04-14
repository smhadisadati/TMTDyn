/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * massF2.c
 *
 * Code generation for function 'massF2'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "EOM.h"
#include "massF2.h"
#include "error.h"
#include "sqrt.h"
#include "EOM_data.h"

/* Variable Definitions */
static emlrtRSInfo nc_emlrtRSI = { 33, /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

static emlrtRSInfo oc_emlrtRSI = { 34, /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

static emlrtRSInfo pc_emlrtRSI = { 42, /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

static emlrtRSInfo qc_emlrtRSI = { 55, /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

static emlrtRSInfo rc_emlrtRSI = { 56, /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

static emlrtRSInfo sc_emlrtRSI = { 57, /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

static emlrtRSInfo tc_emlrtRSI = { 59, /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

static emlrtRSInfo uc_emlrtRSI = { 60, /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

static emlrtRSInfo vc_emlrtRSI = { 61, /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

static emlrtRSInfo wc_emlrtRSI = { 89, /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

/* Function Definitions */
void massF2(const emlrtStack *sp, const real_T in1[34], const real_T in2[36],
            real_T out1[36], real_T out2[108], real_T out3[108], real_T out4[6])
{
  real_T t2;
  real_T t3;
  real_T t9;
  real_T t13;
  real_T t17;
  real_T t21;
  real_T t22;
  real_T t23;
  real_T t24;
  real_T t25;
  real_T t26;
  real_T t28;
  real_T t279;
  real_T t29;
  real_T t30_tmp;
  real_T t30;
  real_T t31_tmp;
  real_T t31;
  real_T t270;
  real_T t271;
  real_T t274;
  real_T t35_tmp;
  real_T t35;
  real_T t259;
  real_T t262;
  real_T t36;
  real_T t37_tmp;
  real_T t37;
  real_T t38_tmp;
  real_T t258;
  real_T t38;
  real_T t266;
  real_T t39_tmp;
  real_T t39;
  real_T t261;
  real_T t263;
  real_T t40;
  real_T t41;
  real_T t42;
  real_T t45;
  real_T t46;
  real_T t47;
  real_T t48_tmp;
  real_T t48;
  real_T t49;
  real_T t50_tmp;
  real_T t50;
  real_T t51;
  real_T t255;
  real_T t52;
  real_T t268;
  real_T t280;
  real_T t273;
  real_T t109;
  real_T out2_tmp;
  real_T t275;
  real_T b_out2_tmp;
  real_T t114;
  real_T t269;
  real_T t278;
  real_T t272;
  real_T t76;
  real_T t53;
  real_T t56;
  real_T t59;
  real_T t62;
  real_T t65;
  real_T t67;
  real_T t68_tmp;
  real_T t69;
  real_T t72;
  real_T t75;
  real_T t77_tmp;
  real_T t78;
  real_T t79_tmp;
  real_T t81;
  real_T t84;
  real_T t87;
  real_T t90;
  real_T t93;
  real_T t94_tmp;
  real_T t96;
  real_T t99;
  real_T t102;
  real_T t103_tmp;
  real_T t106;
  real_T t108;
  real_T t111;
  real_T t113;
  real_T t116;
  real_T t117_tmp;
  real_T t120;
  real_T t121_tmp;
  real_T t122;
  real_T t124;
  real_T t126;
  real_T t128;
  real_T t131;
  real_T t134;
  real_T t136;
  real_T t138;
  real_T t141;
  real_T t143;
  real_T t144;
  real_T t145;
  real_T t148;
  real_T t149;
  real_T t151;
  real_T t153;
  real_T t155;
  real_T t157;
  real_T t158;
  real_T t161;
  real_T t164;
  real_T t165;
  real_T t167;
  real_T t168;
  real_T t170;
  real_T t173;
  real_T t176;
  real_T t179;
  real_T t180;
  real_T t182;
  real_T t185;
  real_T t186;
  real_T t187;
  real_T t188;
  real_T t190;
  real_T t192;
  real_T t193;
  real_T t194;
  real_T t196;
  real_T t198;
  real_T t200;
  real_T t201;
  real_T t202;
  real_T t203;
  real_T t204;
  real_T t207;
  real_T t208;
  real_T t209;
  real_T t210;
  real_T t213;
  real_T t215;
  real_T t216;
  real_T t217;
  real_T t218;
  real_T t219;
  real_T t222;
  real_T t223;
  real_T t224;
  real_T t225;
  real_T t226;
  real_T t227;
  real_T t231;
  real_T t232;
  real_T t233;
  real_T t234;
  real_T t235;
  real_T t236;
  real_T t238;
  real_T t239;
  real_T t241;
  real_T t243;
  real_T t245;
  real_T t247;
  real_T t248;
  real_T t250;
  real_T t252;
  real_T t253;
  real_T t257;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;

  /* MASSF2 */
  /*     [OUT1,OUT2,OUT3,OUT4] = MASSF2(IN1,IN2,S) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.2. */
  /*     04-Jan-2019 16:03:13 */
  st.site = &nc_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t2 = in1[16] * in1[16];
  st.site = &oc_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t3 = in1[17] * in1[17];
  t2 = in1[15] * (t2 + t3 * 3.0) / 12.0 + in1[15] * t2 / 4.0;
  out1[0] = in1[15];
  out1[1] = 0.0;
  out1[2] = 0.0;
  out1[3] = 0.0;
  out1[4] = 0.0;
  out1[5] = 0.0;
  out1[6] = 0.0;
  out1[7] = in1[15];
  out1[8] = 0.0;
  out1[9] = 0.0;
  out1[10] = 0.0;
  out1[11] = 0.0;
  out1[12] = 0.0;
  out1[13] = 0.0;
  out1[14] = in1[15];
  out1[15] = 0.0;
  out1[16] = 0.0;
  out1[17] = 0.0;
  out1[18] = 0.0;
  out1[19] = 0.0;
  out1[20] = 0.0;
  out1[21] = t2;
  out1[22] = 0.0;
  out1[23] = 0.0;
  out1[24] = 0.0;
  out1[25] = 0.0;
  out1[26] = 0.0;
  out1[27] = 0.0;
  out1[28] = t2;
  out1[29] = 0.0;
  out1[30] = 0.0;
  out1[31] = 0.0;
  out1[32] = 0.0;
  out1[33] = 0.0;
  out1[34] = 0.0;
  out1[35] = in1[15] * t3 / 2.0;
  st.site = &pc_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t9 = in1[4] * in1[4];
  t13 = (in1[4] * in2[9] + in2[10] * t9) + in1[4] * in2[11] * t9;
  t17 = (in1[4] * in2[12] + in2[13] * t9) + in1[4] * in2[14] * t9;
  t21 = (in1[4] * in2[15] + in2[16] * t9) + in1[4] * in2[17] * t9;
  st.site = &qc_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t22 = t13 * t13;
  st.site = &rc_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t23 = t17 * t17;
  st.site = &sc_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t24 = t21 * t21;
  t25 = ((-t22 - t23) - t24) + 1.0;
  t2 = t25;
  st.site = &tc_emlrtRSI;
  b_sqrt(&st, &t2);
  t26 = 1.0 / t2;
  t2 = t25;
  st.site = &uc_emlrtRSI;
  b_sqrt(&st, &t2);
  st.site = &vc_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t28 = t9 * t9;
  t279 = in1[16] * in1[4];
  t29 = t279 * t2;
  t30_tmp = in1[16] * t9;
  t30 = t30_tmp * t2;
  t31_tmp = t279 * t9;
  t31 = t31_tmp * t2;
  t270 = t279 * t21;
  t271 = t30_tmp * t21;
  t274 = t31_tmp * t21;
  t35_tmp = in1[4] * t21;
  t35 = t35_tmp * 2.0;
  t259 = in1[4] * t13;
  t262 = t259 * t17;
  t36 = t262 * t26 * 2.0;
  t37_tmp = t9 * t21;
  t37 = t37_tmp * 2.0;
  t38_tmp = t9 * t13;
  t258 = t38_tmp * t17;
  t38 = t258 * t26 * 2.0;
  t266 = in1[4] * t9;
  t39_tmp = t266 * t21;
  t39 = t39_tmp * 2.0;
  t261 = t266 * t13;
  t263 = t261 * t17;
  t40 = t263 * t26 * 2.0;
  t41 = in1[4] * t2 * 2.0;
  t42 = t9 * t2 * 2.0;
  t2 = t266 * t2 * 2.0;
  t3 = t259 * t21 * t26 * 2.0;
  t45 = t38_tmp * t21 * t26 * 2.0;
  t46 = t261 * t21 * t26 * 2.0;
  t47 = t259 * 2.0;
  t48_tmp = in1[4] * t17;
  t48 = t48_tmp * t21 * t26 * 2.0;
  t49 = t38_tmp * 2.0;
  t50_tmp = t9 * t17;
  t50 = t50_tmp * t21 * t26 * 2.0;
  t51 = t261 * 2.0;
  t255 = t266 * t17;
  t52 = t255 * t21 * t26 * 2.0;
  out2[0] = t9;
  out2[1] = 0.0;
  out2[2] = 0.0;
  out2[3] = 0.0;
  out2[4] = 0.0;
  out2[5] = 0.0;
  out2[6] = t266;
  out2[7] = 0.0;
  out2[8] = 0.0;
  out2[9] = 0.0;
  out2[10] = 0.0;
  out2[11] = 0.0;
  out2[12] = t28;
  out2[13] = 0.0;
  out2[14] = 0.0;
  out2[15] = 0.0;
  out2[16] = 0.0;
  out2[17] = 0.0;
  out2[18] = 0.0;
  out2[19] = t9;
  out2[20] = 0.0;
  out2[21] = 0.0;
  out2[22] = 0.0;
  out2[23] = 0.0;
  out2[24] = 0.0;
  out2[25] = t266;
  out2[26] = 0.0;
  out2[27] = 0.0;
  out2[28] = 0.0;
  out2[29] = 0.0;
  out2[30] = 0.0;
  out2[31] = t28;
  out2[32] = 0.0;
  out2[33] = 0.0;
  out2[34] = 0.0;
  out2[35] = 0.0;
  out2[36] = 0.0;
  out2[37] = 0.0;
  out2[38] = t9;
  out2[39] = 0.0;
  out2[40] = 0.0;
  out2[41] = 0.0;
  out2[42] = 0.0;
  out2[43] = 0.0;
  out2[44] = t266;
  out2[45] = 0.0;
  out2[46] = 0.0;
  out2[47] = 0.0;
  out2[48] = 0.0;
  out2[49] = 0.0;
  out2[50] = t28;
  out2[51] = 0.0;
  out2[52] = 0.0;
  out2[53] = 0.0;
  t268 = t279 * t13;
  t280 = t268 * t17;
  t273 = t280 * t26;
  out2[54] = t270 - t273;
  out2[55] = -t29 + t279 * t22 * t26;
  out2[56] = t268 * -2.0;
  out2[57] = t41 + in1[4] * t22 * t26 * 2.0;
  out2[58] = -t35 + t36;
  t109 = t48_tmp * 2.0;
  out2[59] = t3 + t109;
  out2_tmp = t30_tmp * t13;
  t275 = out2_tmp * t17;
  b_out2_tmp = t275 * t26;
  out2[60] = t271 - b_out2_tmp;
  out2[61] = -t30 + t30_tmp * t22 * t26;
  out2[62] = out2_tmp * -2.0;
  out2[63] = t42 + t9 * t22 * t26 * 2.0;
  out2[64] = -t37 + t38;
  t114 = t50_tmp * 2.0;
  out2[65] = t45 + t114;
  t269 = t31_tmp * t13;
  t278 = t269 * t17;
  t272 = t278 * t26;
  out2[66] = t274 - t272;
  out2[67] = -t31 + t31_tmp * t22 * t26;
  out2[68] = t269 * -2.0;
  out2[69] = t2 + t266 * t22 * t26 * 2.0;
  out2[70] = -t39 + t40;
  t76 = t255 * 2.0;
  out2[71] = t46 + t76;
  out2[72] = t29 - t279 * t23 * t26;
  out2[73] = t270 + t273;
  t273 = t279 * t17;
  out2[74] = t273 * -2.0;
  out2[75] = t35 + t36;
  out2[76] = t41 + in1[4] * t23 * t26 * 2.0;
  out2[77] = -t47 + t48;
  out2[78] = t30 - t30_tmp * t23 * t26;
  out2[79] = t271 + b_out2_tmp;
  b_out2_tmp = t30_tmp * t17;
  out2[80] = b_out2_tmp * -2.0;
  out2[81] = t37 + t38;
  out2[82] = t42 + t9 * t23 * t26 * 2.0;
  out2[83] = -t49 + t50;
  out2[84] = t31 - t31_tmp * t23 * t26;
  out2[85] = t274 + t272;
  t272 = t31_tmp * t17;
  out2[86] = t272 * -2.0;
  out2[87] = t39 + t40;
  out2[88] = t2 + t266 * t23 * t26 * 2.0;
  out2[89] = -t51 + t52;
  out2[90] = t268 - t273 * t21 * t26;
  out2[91] = t273 + t268 * t21 * t26;
  out2[92] = 0.0;
  out2[93] = t3 - t109;
  out2[94] = t47 + t48;
  out2[95] = t41 + in1[4] * t24 * t26 * 2.0;
  out2[96] = out2_tmp - b_out2_tmp * t21 * t26;
  out2[97] = b_out2_tmp + out2_tmp * t21 * t26;
  out2[98] = 0.0;
  out2[99] = t45 - t114;
  out2[100] = t49 + t50;
  out2[101] = t42 + t9 * t24 * t26 * 2.0;
  out2[102] = t269 - t272 * t21 * t26;
  out2[103] = t272 + t269 * t21 * t26;
  out2[104] = 0.0;
  out2[105] = t46 - t76;
  out2[106] = t51 + t52;
  out2[107] = t2 + t266 * t24 * t26 * 2.0;
  st.site = &wc_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  if (t25 < 0.0) {
    c_st.site = &qb_emlrtRSI;
    error(&c_st);
  }

  t53 = 1.0 / muDoubleScalarPower(t25, 1.5);
  t31 = t269 * t26;
  t56 = t31 + t269 * t23 * t53;
  t35 = in1[16] * t13;
  t36 = t35 * t26 * t28;
  t59 = t36 + t35 * t23 * t28 * t53;
  t3 = t272 * t26;
  t62 = t3 + t272 * t22 * t53;
  t45 = in1[16] * t17;
  t46 = t45 * t26 * t28;
  t65 = t46 + t45 * t22 * t28 * t53;
  t109 = t278 * t21 * t53;
  t67 = t31_tmp - t109;
  t68_tmp = in1[16] * t28;
  t76 = t35 * t17 * t21 * t28 * t53;
  t69 = t68_tmp - t76;
  t37 = t268 * t26 * t28;
  t72 = t37 + t268 * t23 * t28 * t53;
  t47 = t273 * t26 * t28;
  t75 = t47 + t273 * t22 * t28 * t53;
  t77_tmp = t279 * t28;
  t114 = t280 * t21 * t28 * t53;
  t78 = t77_tmp - t114;
  t79_tmp = out2_tmp * t26;
  t2 = out2_tmp * t23;
  t81 = t79_tmp + t2 * t53;
  t49 = t274 * t26;
  t84 = t49 + t274 * t23 * t53;
  t50 = in1[16] * t21;
  t51 = t50 * t26 * t28;
  t87 = t51 + t50 * t23 * t28 * t53;
  t90 = t272 * t23 * t53 + t3 * 3.0;
  t93 = t45 * t23 * t28 * t53 + t46 * 3.0;
  t94_tmp = t79_tmp * t28;
  t96 = t94_tmp + t2 * t28 * t53;
  t52 = t270 * t26 * t28;
  t99 = t52 + t270 * t23 * t28 * t53;
  t102 = t273 * t23 * t28 * t53 + t47 * 3.0;
  t103_tmp = b_out2_tmp * t26;
  t29 = t271 * t26;
  t2 = t271 * t23;
  t106 = t29 + t2 * t53;
  t48 = t275 * t21;
  t30 = t48 * t53;
  t108 = t30_tmp - t30;
  t111 = t3 + t272 * t24 * t53;
  t113 = t46 + t45 * t24 * t28 * t53;
  t116 = t47 + t273 * t24 * t28 * t53;
  t117_tmp = t103_tmp * t28;
  t45 = t29 * t28;
  t120 = t45 + t2 * t28 * t53;
  t121_tmp = t30_tmp * t28;
  t3 = t48 * t28 * t53;
  t122 = t121_tmp - t3;
  t2 = b_out2_tmp * t22;
  t124 = t103_tmp + t2 * t53;
  t126 = t49 + t274 * t22 * t53;
  t128 = t51 + t50 * t22 * t28 * t53;
  t131 = t269 * t22 * t53 + t31 * 3.0;
  t134 = t35 * t22 * t28 * t53 + t36 * 3.0;
  t136 = t117_tmp + t2 * t28 * t53;
  t138 = t52 + t270 * t22 * t28 * t53;
  t141 = t268 * t22 * t28 * t53 + t37 * 3.0;
  t143 = t31_tmp + t109;
  t144 = t68_tmp + t76;
  t145 = t77_tmp + t114;
  t2 = t271 * t22;
  t148 = t29 + t2 * t53;
  t149 = t30_tmp + t30;
  t151 = t31 + t269 * t24 * t53;
  t153 = t36 + t35 * t24 * t28 * t53;
  t155 = t37 + t268 * t24 * t28 * t53;
  t157 = t45 + t2 * t28 * t53;
  t158 = t121_tmp + t3;
  t42 = t255 * t26 * 2.0;
  t2 = t255 * t22 * t53 * 2.0;
  t161 = t42 + t2;
  t25 = t17 * t26 * t28 * 2.0;
  t3 = t17 * t22 * t28 * t53 * 2.0;
  t164 = t25 + t3;
  t165 = t39_tmp * t26 * 2.0;
  t52 = t39_tmp * t22 * t53 * 2.0;
  t167 = t165 + t52;
  t168 = t21 * t26 * t28 * 2.0;
  t29 = t21 * t22 * t28 * t53 * 2.0;
  t170 = t168 + t29;
  t39 = t261 * t26 * 2.0;
  t173 = t39 + t261 * t22 * t53 * 2.0;
  t40 = t13 * t26 * t28 * 2.0;
  t176 = t40 + t13 * t22 * t28 * t53 * 2.0;
  t109 = t48_tmp * t26 * t28 * 2.0;
  t46 = t48_tmp * t22 * t28 * t53 * 2.0;
  t179 = t109 + t46;
  t180 = t35_tmp * t26 * t28 * 2.0;
  t30 = t35_tmp * t22 * t28 * t53 * 2.0;
  t182 = t180 + t30;
  t41 = t259 * t26 * t28 * 2.0;
  t185 = t41 + t259 * t22 * t28 * t53 * 2.0;
  t45 = t38_tmp * t26;
  t186 = t45 * 2.0;
  t47 = t50_tmp * t26;
  t187 = t47 * 2.0;
  t48 = t50_tmp * t22;
  t188 = t48 * t53 * 2.0;
  t35 = t261 * t23 * t53 * 2.0;
  t190 = t39 + t35;
  t36 = t13 * t23 * t28 * t53 * 2.0;
  t192 = t40 + t36;
  t193 = t42 - t2;
  t194 = t25 - t3;
  t49 = t266 * 2.0;
  t3 = t263 * t21 * t53 * 2.0;
  t196 = t49 - t3;
  t50 = t28 * 2.0;
  t51 = t13 * t17 * t21 * t28 * t53 * 2.0;
  t198 = t50 - t51;
  t31 = t259 * t23 * t28 * t53 * 2.0;
  t200 = t41 + t31;
  t201 = t45 * t28 * 2.0;
  t202 = t109 - t46;
  t203 = t47 * t28 * 2.0;
  t204 = t48 * t28 * t53 * 2.0;
  t47 = in1[4] * t28 * 2.0;
  t46 = t262 * t21 * t28 * t53 * 2.0;
  t207 = t47 - t46;
  t2 = t37_tmp * t26;
  t208 = t2 * 2.0;
  t45 = t37_tmp * t22;
  t209 = t45 * t53 * 2.0;
  t210 = t9 * 2.0;
  t37 = t261 * t24 * t53 * 2.0;
  t213 = t39 + t37;
  t38 = t13 * t24 * t28 * t53 * 2.0;
  t215 = t40 + t38;
  t216 = t165 - t52;
  t217 = t168 - t29;
  t218 = t49 + t3;
  t219 = t50 + t51;
  t51 = t259 * t24 * t28 * t53 * 2.0;
  t222 = t41 + t51;
  t223 = t180 - t30;
  t224 = t2 * t28 * 2.0;
  t225 = t45 * t28 * t53 * 2.0;
  t226 = t47 + t46;
  t227 = t9 * t28 * 2.0;
  t2 = t38_tmp * t23;
  t52 = t2 * t53 * 2.0;
  t26 = t187 + t188;
  t3 = t258 * t21;
  t47 = t3 * t53 * 2.0;
  t231 = t210 + t47;
  t232 = t39 - t35;
  t233 = t40 - t36;
  t234 = t41 - t31;
  t235 = t2 * t28 * t53 * 2.0;
  t236 = t203 + t204;
  t48 = t3 * t28 * t53 * 2.0;
  t238 = t227 + t48;
  t239 = t186 + t52;
  t2 = t39_tmp * t23 * t53 * 2.0;
  t241 = t165 + t2;
  t3 = t21 * t23 * t28 * t53 * 2.0;
  t243 = t168 + t3;
  t245 = t42 + t255 * t23 * t53 * 2.0;
  t247 = t25 + t17 * t23 * t28 * t53 * 2.0;
  t248 = t201 + t235;
  t45 = t35_tmp * t23 * t28 * t53 * 2.0;
  t250 = t180 + t45;
  t252 = t109 + t48_tmp * t23 * t28 * t53 * 2.0;
  t46 = t37_tmp * t23;
  t253 = t46 * t53 * 2.0;
  t49 = t255 * t24 * t53 * 2.0;
  t255 = t42 + t49;
  t50 = t17 * t24 * t28 * t53 * 2.0;
  t257 = t25 + t50;
  t258 = t165 - t2;
  t259 = t168 - t3;
  t3 = t48_tmp * t24 * t28 * t53 * 2.0;
  t261 = t109 + t3;
  t262 = t180 - t45;
  t263 = t46 * t28 * t53 * 2.0;
  t2 = t38_tmp * t24;
  t45 = t2 * t53 * 2.0;
  t46 = t208 + t209;
  t266 = t210 - t47;
  t47 = t39 - t37;
  t268 = t40 - t38;
  t269 = t41 - t51;
  t270 = t2 * t28 * t53 * 2.0;
  t271 = t224 + t225;
  t272 = t227 - t48;
  t2 = t50_tmp * t24;
  t273 = t2 * t53 * 2.0;
  t274 = t208 + t253;
  t275 = t42 - t49;
  t76 = t25 - t50;
  t114 = t109 - t3;
  t278 = t2 * t28 * t53 * 2.0;
  t279 = t224 + t263;
  t280 = t186 + t45;
  t109 = t187 + t273;
  t25 = t165 + t39_tmp * t24 * t53 * 2.0;
  t40 = t168 + t21 * t24 * t28 * t53 * 2.0;
  t41 = t201 + t270;
  t42 = t203 + t278;
  t30 = t180 + t35_tmp * t24 * t28 * t53 * 2.0;
  memset(&out3[0], 0, 54U * sizeof(real_T));
  t31 = t62 * in2[28];
  t35 = t59 * in2[32];
  t36 = t65 * in2[29];
  t37 = t81 * in2[30];
  t38 = t124 * in2[27];
  out3[54] = (((((((-t56 * in2[31] - t31) - t35) - t36) + t67 * in2[34]) + t69 *
                in2[35]) - t37) + t108 * in2[33]) - t38;
  t39 = out2_tmp * t22;
  out3[55] = (((((((t62 * in2[31] + t65 * in2[32]) + t124 * in2[30]) + t131 *
                  in2[28]) + t126 * in2[34]) + t128 * in2[35]) + t134 * in2[29])
              + t148 * in2[33]) + in2[27] * (t79_tmp * 3.0 + t39 * t53);
  out3[56] = (t30_tmp * in2[27] * -2.0 - t68_tmp * in2[29] * 2.0) - t31_tmp *
    in2[28] * 2.0;
  t29 = t38_tmp * t22;
  out3[57] = (((((((t161 * in2[31] + t164 * in2[32]) + t167 * in2[34]) + t173 *
                  in2[28]) + t170 * in2[35]) + t176 * in2[29]) + t26 * in2[30])
              + t46 * in2[33]) + in2[27] * (t186 + t29 * t53 * 2.0);
  out3[58] = (((((((t161 * in2[28] + t164 * in2[29]) + t218 * in2[34]) + t219 *
                  in2[35]) + t26 * in2[27]) - t232 * in2[31]) + t231 * in2[33])
              - t233 * in2[32]) - in2[30] * (t186 - t52);
  out3[59] = (((((((t167 * in2[28] + t170 * in2[29]) - t196 * in2[31]) - t198 *
                  in2[32]) + t46 * in2[27]) - t266 * in2[30]) - t47 * in2[34]) -
              t268 * in2[35]) - in2[33] * (t186 - t45);
  t48 = t62 * in2[27];
  t49 = t59 * in2[31];
  t50 = t65 * in2[28];
  t51 = t72 * in2[32];
  t52 = t75 * in2[29];
  out3[60] = (((((((-t56 * in2[30] - t48) - t49) - t50) + t67 * in2[33]) + t69 *
                in2[34]) - t51) - t52) + t78 * in2[35];
  out3[61] = (((((((t62 * in2[30] + t65 * in2[31]) + t75 * in2[32]) + t131 *
                  in2[27]) + t126 * in2[33]) + t128 * in2[34]) + t134 * in2[28])
              + t141 * in2[29]) + t138 * in2[35];
  out3[62] = (t68_tmp * in2[28] * -2.0 - t31_tmp * in2[27] * 2.0) - t77_tmp *
    in2[29] * 2.0;
  out3[63] = (((((((t161 * in2[30] + t164 * in2[31]) + t167 * in2[33]) + t173 *
                  in2[27]) + t170 * in2[34]) + t176 * in2[28]) + t179 * in2[32])
              + t185 * in2[29]) + t182 * in2[35];
  out3[64] = (((((((t161 * in2[27] + t164 * in2[28]) + t179 * in2[29]) + t218 *
                  in2[33]) + t219 * in2[34]) + t226 * in2[35]) - t232 * in2[30])
              - t233 * in2[31]) - t234 * in2[32];
  out3[65] = (((((((t167 * in2[27] + t170 * in2[28]) + t182 * in2[29]) - t196 *
                  in2[30]) - t198 * in2[31]) - t207 * in2[32]) - t47 * in2[33])
              - t268 * in2[34]) - t269 * in2[35];
  t2 = t65 * in2[27];
  t3 = t72 * in2[31];
  t45 = t75 * in2[28];
  t46 = t96 * in2[32];
  t47 = t136 * in2[29];
  out3[66] = (((((((-t59 * in2[30] - t2) + t69 * in2[33]) - t3) - t45) + t78 *
                in2[34]) - t46) + t122 * in2[35]) - t47;
  out3[67] = (((((((t65 * in2[30] + t75 * in2[31]) + t128 * in2[33]) + t134 *
                  in2[27]) + t136 * in2[32]) + t141 * in2[28]) + t138 * in2[34])
              + t157 * in2[35]) + in2[29] * (t94_tmp * 3.0 + t39 * t28 * t53);
  out3[68] = (t68_tmp * in2[27] * -2.0 - t77_tmp * in2[28] * 2.0) - t121_tmp *
    in2[29] * 2.0;
  out3[69] = (((((((t164 * in2[30] + t170 * in2[33]) + t176 * in2[27]) + t179 *
                  in2[31]) + t185 * in2[28]) + t182 * in2[34]) + t236 * in2[32])
              + t271 * in2[35]) + in2[29] * (t201 + t29 * t28 * t53 * 2.0);
  out3[70] = (((((((t164 * in2[27] + t179 * in2[28]) + t219 * in2[33]) + t226 *
                  in2[34]) - t233 * in2[30]) - t234 * in2[31]) + t236 * in2[29])
              + t238 * in2[35]) - in2[32] * (t201 - t235);
  out3[71] = (((((((t170 * in2[27] + t182 * in2[28]) - t198 * in2[30]) - t207 *
                  in2[31]) + t271 * in2[29]) - t268 * in2[33]) - t269 * in2[34])
              - t272 * in2[32]) - in2[35] * (t201 - t270);
  t39 = b_out2_tmp * t23;
  out3[72] = (((((((-t56 * in2[28] - t59 * in2[29]) - t81 * in2[27]) - t84 *
                  in2[34]) - t90 * in2[31]) - t87 * in2[35]) - t93 * in2[32]) -
              t106 * in2[33]) - in2[30] * (t103_tmp * 3.0 + t39 * t53);
  out3[73] = (((((((t56 * in2[31] + t31) + t35) + t36) + t37) + t38) + t143 *
               in2[34]) + t144 * in2[35]) + t149 * in2[33];
  out3[74] = (t30_tmp * in2[30] * -2.0 - t68_tmp * in2[32] * 2.0) - t31_tmp *
    in2[31] * 2.0;
  out3[75] = (((((((t190 * in2[31] - t193 * in2[28]) - t194 * in2[29]) + t192 *
                  in2[32]) - t196 * in2[34]) - t198 * in2[35]) + t239 * in2[30])
              - in2[33] * (t210 - t9 * t13 * t17 * t21 * t53 * 2.0)) - in2[27] *
    (t187 - t188);
  t31 = t50_tmp * t23;
  out3[76] = (((((((t190 * in2[28] + t192 * in2[29]) + t239 * in2[27]) + t241 *
                  in2[34]) + t245 * in2[31]) + t243 * in2[35]) + t247 * in2[32])
              + t274 * in2[33]) + in2[30] * (t187 + t31 * t53 * 2.0);
  out3[77] = (((((((t218 * in2[28] + t219 * in2[29]) + t231 * in2[27]) + t241 *
                  in2[31]) + t243 * in2[32]) + t274 * in2[30]) - t275 * in2[34])
              - t76 * in2[35]) - in2[33] * (t187 - t273);
  out3[78] = (((((((-t56 * in2[27] - t59 * in2[28]) - t72 * in2[29]) - t84 *
                  in2[33]) - t90 * in2[30]) - t87 * in2[34]) - t93 * in2[31]) -
              t99 * in2[35]) - t102 * in2[32];
  out3[79] = (((((((t56 * in2[30] + t48) + t49) + t50) + t51) + t52) + t143 *
               in2[33]) + t144 * in2[34]) + t145 * in2[35];
  out3[80] = (t68_tmp * in2[31] * -2.0 - t31_tmp * in2[30] * 2.0) - t77_tmp *
    in2[32] * 2.0;
  out3[81] = (((((((t190 * in2[30] - t193 * in2[27]) - t194 * in2[28]) + t192 *
                  in2[31]) - t196 * in2[33]) - t202 * in2[29]) - t198 * in2[34])
              + t200 * in2[32]) - t207 * in2[35];
  out3[82] = (((((((t190 * in2[27] + t192 * in2[28]) + t200 * in2[29]) + t241 *
                  in2[33]) + t245 * in2[30]) + t243 * in2[34]) + t247 * in2[31])
              + t252 * in2[32]) + t250 * in2[35];
  out3[83] = (((((((t218 * in2[27] + t219 * in2[28]) + t226 * in2[29]) + t241 *
                  in2[30]) + t243 * in2[31]) + t250 * in2[32]) - t275 * in2[33])
              - t76 * in2[34]) - t114 * in2[35];
  out3[84] = (((((((-t59 * in2[27] - t72 * in2[28]) - t87 * in2[33]) - t93 *
                  in2[30]) - t96 * in2[29]) - t99 * in2[34]) - t102 * in2[31]) -
              t120 * in2[35]) - in2[32] * (t117_tmp * 3.0 + t39 * t28 * t53);
  out3[85] = (((((((t59 * in2[30] + t2) + t3) + t45) + t46) + t47) + t144 * in2
               [33]) + t145 * in2[34]) + t158 * in2[35];
  out3[86] = (t68_tmp * in2[30] * -2.0 - t77_tmp * in2[31] * 2.0) - t121_tmp *
    in2[32] * 2.0;
  out3[87] = (((((((-t194 * in2[27] + t192 * in2[30]) - t202 * in2[28]) - t198 *
                  in2[33]) + t200 * in2[31]) - t207 * in2[34]) + t248 * in2[32])
              - in2[29] * (t203 - t204)) - in2[35] * (t227 - t9 * t13 * t17 *
    t21 * t28 * t53 * 2.0);
  out3[88] = (((((((t192 * in2[27] + t200 * in2[28]) + t243 * in2[33]) + t247 *
                  in2[30]) + t248 * in2[29]) + t252 * in2[31]) + t250 * in2[34])
              + t279 * in2[35]) + in2[32] * (t203 + t31 * t28 * t53 * 2.0);
  out3[89] = (((((((t219 * in2[27] + t226 * in2[28]) + t238 * in2[29]) + t243 *
                  in2[30]) + t250 * in2[31]) - t76 * in2[33]) - t114 * in2[34])
              + t279 * in2[32]) - in2[35] * (t203 - t278);
  t31 = b_out2_tmp * t24;
  out3[90] = (((((((-in2[33] * (t103_tmp + t31 * t53) + t67 * in2[28]) + t69 *
                   in2[29]) - t84 * in2[31]) - t87 * in2[32]) + t108 * in2[27])
               - t106 * in2[30]) - t111 * in2[34]) - t113 * in2[35];
  t35 = out2_tmp * t24;
  out3[91] = (((((((in2[33] * (t79_tmp + t35 * t53) + t126 * in2[28]) + t128 *
                   in2[29]) + t143 * in2[31]) + t148 * in2[27]) + t144 * in2[32])
               + t149 * in2[30]) + t151 * in2[34]) + t153 * in2[35];
  out3[92] = 0.0;
  out3[93] = (((((((-t216 * in2[28] - t217 * in2[29]) + t213 * in2[34]) + t218 *
                  in2[31]) + t215 * in2[35]) + t219 * in2[32]) + t231 * in2[30])
              + t280 * in2[33]) - in2[27] * (t208 - t209);
  out3[94] = (((((((-t196 * in2[28] - t198 * in2[29]) + t255 * in2[34]) - t258 *
                  in2[31]) - t259 * in2[32]) + t257 * in2[35]) - t266 * in2[27])
              + t109 * in2[33]) - in2[30] * (t208 - t253);
  t36 = t37_tmp * t24;
  out3[95] = (((((((t213 * in2[28] + t215 * in2[29]) + t255 * in2[31]) + t257 *
                  in2[32]) + t280 * in2[27]) + t109 * in2[30]) + t25 * in2[34])
              + t40 * in2[35]) + in2[33] * (t208 + t36 * t53 * 2.0);
  out3[96] = (((((((t67 * in2[27] + t69 * in2[28]) + t78 * in2[29]) - t84 * in2
                  [30]) - t87 * in2[31]) - t99 * in2[32]) - t111 * in2[33]) -
              t113 * in2[34]) - t116 * in2[35];
  out3[97] = (((((((t126 * in2[27] + t128 * in2[28]) + t138 * in2[29]) + t143 *
                  in2[30]) + t144 * in2[31]) + t145 * in2[32]) + t151 * in2[33])
              + t153 * in2[34]) + t155 * in2[35];
  out3[98] = 0.0;
  out3[99] = (((((((-t216 * in2[27] - t217 * in2[28]) + t213 * in2[33]) + t218 *
                  in2[30]) + t215 * in2[34]) + t219 * in2[31]) - t223 * in2[29])
              + t222 * in2[35]) + t226 * in2[32];
  out3[100] = (((((((-t196 * in2[27] - t198 * in2[28]) - t207 * in2[29]) + t255 *
                   in2[33]) - t258 * in2[30]) - t259 * in2[31]) + t257 * in2[34])
               - t262 * in2[32]) + t261 * in2[35];
  out3[101] = (((((((t213 * in2[27] + t215 * in2[28]) + t222 * in2[29]) + t255 *
                   in2[30]) + t257 * in2[31]) + t261 * in2[32]) + t25 * in2[33])
               + t40 * in2[34]) + t30 * in2[35];
  out3[102] = (((((((t69 * in2[27] + t78 * in2[28]) - t87 * in2[30]) - t99 *
                   in2[31]) - t113 * in2[33]) - t116 * in2[34]) + t122 * in2[29])
               - t120 * in2[32]) - in2[35] * (t117_tmp + t31 * t28 * t53);
  out3[103] = (((((((t128 * in2[27] + t138 * in2[28]) + t144 * in2[30]) + t145 *
                   in2[31]) + t153 * in2[33]) + t157 * in2[29]) + t155 * in2[34])
               + t158 * in2[32]) + in2[35] * (t94_tmp + t35 * t28 * t53);
  out3[104] = 0.0;
  out3[105] = (((((((-t217 * in2[27] + t215 * in2[33]) + t219 * in2[30]) - t223 *
                   in2[28]) + t222 * in2[34]) + t226 * in2[31]) + t238 * in2[32])
               + t41 * in2[35]) - in2[29] * (t224 - t225);
  out3[106] = (((((((-t198 * in2[27] - t207 * in2[28]) - t259 * in2[30]) + t257 *
                   in2[33]) - t262 * in2[31]) + t261 * in2[34]) - t272 * in2[29])
               + t42 * in2[35]) - in2[32] * (t224 - t263);
  out3[107] = (((((((t215 * in2[27] + t222 * in2[28]) + t257 * in2[30]) + t261 *
                   in2[31]) + t41 * in2[29]) + t40 * in2[33]) + t42 * in2[32]) +
               t30 * in2[34]) + in2[35] * (t224 + t36 * t28 * t53 * 2.0);
  out4[0] = in1[12];
  out4[1] = in1[13];
  out4[2] = in1[14];
  out4[3] = 0.0;
  out4[4] = 0.0;
  out4[5] = 0.0;
}

/* End of code generation (massF2.c) */
