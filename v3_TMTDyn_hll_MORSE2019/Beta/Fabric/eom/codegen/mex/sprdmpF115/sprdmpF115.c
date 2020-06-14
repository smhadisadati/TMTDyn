/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sprdmpF115.c
 *
 * Code generation for function 'sprdmpF115'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "sprdmpF115.h"
#include "sqrt.h"
#include "error.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 41,    /* lineNo */
  "sprdmpF115",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF115.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 42,  /* lineNo */
  "sprdmpF115",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF115.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 43,  /* lineNo */
  "sprdmpF115",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF115.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 44,  /* lineNo */
  "sprdmpF115",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF115.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 54,  /* lineNo */
  "sprdmpF115",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF115.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 55,  /* lineNo */
  "sprdmpF115",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF115.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 56,  /* lineNo */
  "sprdmpF115",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF115.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 57,  /* lineNo */
  "sprdmpF115",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF115.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 59,  /* lineNo */
  "sprdmpF115",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF115.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 60,  /* lineNo */
  "sprdmpF115",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF115.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 61,  /* lineNo */
  "sprdmpF115",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF115.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 79,  /* lineNo */
  "sprdmpF115",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF115.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 124, /* lineNo */
  "sprdmpF115",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF115.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 190, /* lineNo */
  "sprdmpF115",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF115.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 191, /* lineNo */
  "sprdmpF115",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF115.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 241, /* lineNo */
  "sprdmpF115",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF115.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 287, /* lineNo */
  "sprdmpF115",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF115.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 331, /* lineNo */
  "sprdmpF115",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF115.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 383, /* lineNo */
  "sprdmpF115",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF115.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 430, /* lineNo */
  "sprdmpF115",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF115.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 475, /* lineNo */
  "sprdmpF115",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF115.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 486, /* lineNo */
  "sprdmpF115",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF115.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 49,  /* lineNo */
  "power",                             /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 61,  /* lineNo */
  "power",                             /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

/* Function Definitions */
void sprdmpF115(const emlrtStack *sp, const real_T in1[6], const real_T in2[224],
                real_T s, real_T out1[636], real_T out2[6], real_T out3[6],
                real_T out4[6], real_T *out5, real_T out6[636], real_T out7[636],
                real_T *out8)
{
  real_T t2;
  real_T t3;
  real_T t4;
  real_T t5;
  real_T t6;
  real_T t7;
  real_T t120;
  real_T t8;
  real_T t9;
  real_T t10;
  real_T t58;
  real_T t11;
  real_T t102;
  real_T t12;
  real_T t13_tmp;
  real_T t13;
  real_T t14;
  real_T t15;
  real_T t16;
  real_T t17;
  real_T t18;
  real_T t19;
  real_T t20;
  real_T t22;
  real_T t21;
  real_T t23;
  real_T t25;
  real_T t27_tmp;
  real_T t27;
  real_T t393;
  real_T t28;
  real_T t29;
  real_T t31;
  real_T t32_tmp;
  real_T t32;
  real_T t394;
  real_T t34;
  real_T t35;
  real_T t36_tmp;
  real_T t37_tmp;
  real_T t38;
  real_T t39;
  real_T t40;
  real_T t41;
  real_T t44_tmp;
  real_T b_t44_tmp;
  real_T c_t44_tmp;
  real_T t44;
  real_T t47_tmp;
  real_T t47;
  real_T t48;
  real_T t49;
  real_T t74_tmp;
  real_T t50;
  real_T t51;
  real_T t72;
  real_T t53_tmp;
  real_T t53;
  real_T t54;
  real_T t402;
  real_T t55;
  real_T t76;
  real_T t56;
  real_T t59_tmp;
  real_T t59;
  real_T t60;
  real_T t64;
  real_T t68;
  real_T t78;
  real_T t80;
  real_T t82;
  real_T t83;
  real_T t85;
  real_T t88;
  real_T t92;
  real_T t94;
  real_T t401;
  real_T t98;
  real_T t99;
  real_T t100_tmp;
  real_T t100;
  real_T t107_tmp;
  real_T t103;
  real_T t104;
  real_T t108;
  real_T t109;
  real_T t110;
  real_T t111;
  real_T t113;
  real_T t116_tmp;
  real_T t117;
  real_T t119_tmp;
  real_T t121;
  real_T t122;
  real_T t126;
  real_T t127;
  real_T t128;
  real_T t129;
  real_T t130;
  real_T t132;
  real_T t133;
  real_T t400;
  real_T t141;
  real_T t142;
  real_T t144;
  real_T t145;
  real_T t147;
  real_T t149;
  real_T t150;
  real_T t151;
  real_T t152;
  real_T t154;
  real_T t155;
  real_T t156;
  real_T t157_tmp;
  real_T t158;
  real_T t159;
  real_T t160;
  real_T t161;
  real_T t162;
  real_T t163;
  real_T t164;
  real_T t169_tmp;
  real_T t170_tmp;
  real_T b_t170_tmp;
  real_T c_t170_tmp;
  real_T d_t170_tmp;
  real_T t170;
  real_T t176_tmp;
  real_T b_t176_tmp;
  real_T c_t176_tmp;
  real_T d_t176_tmp;
  real_T t176;
  real_T t182_tmp;
  real_T t183_tmp;
  real_T t185_tmp;
  real_T b_t185_tmp;
  real_T c_t185_tmp;
  real_T d_t185_tmp;
  real_T e_t185_tmp;
  real_T t185;
  real_T t190_tmp;
  real_T t191_tmp;
  real_T b_t191_tmp;
  real_T c_t191_tmp;
  real_T t191;
  real_T t199;
  real_T t203;
  real_T t204;
  real_T t205;
  real_T t206;
  real_T t207;
  real_T t208;
  real_T t209;
  real_T t210;
  real_T t211;
  real_T t212;
  real_T t213;
  real_T t217_tmp;
  real_T t219_tmp;
  real_T b_t219_tmp;
  real_T c_t219_tmp;
  real_T d_t219_tmp;
  real_T t219;
  real_T t224_tmp;
  real_T b_t224_tmp;
  real_T c_t224_tmp;
  real_T t224;
  real_T t230_tmp;
  real_T b_t230_tmp;
  real_T c_t230_tmp;
  real_T d_t230_tmp;
  real_T t230;
  real_T t237_tmp;
  real_T t238_tmp;
  real_T b_t238_tmp;
  real_T c_t238_tmp;
  real_T d_t238_tmp;
  real_T e_t238_tmp;
  real_T t238;
  real_T t245;
  real_T t249;
  real_T t250;
  real_T t251;
  real_T t252;
  real_T t253;
  real_T t254;
  real_T t255;
  real_T t256;
  real_T t257;
  real_T t258;
  real_T t259;
  real_T t264_tmp;
  real_T b_t264_tmp;
  real_T c_t264_tmp;
  real_T d_t264_tmp;
  real_T t264;
  real_T t271_tmp;
  real_T b_t271_tmp;
  real_T t271;
  real_T t276;
  real_T t406;
  real_T t282_tmp;
  real_T b_t282_tmp;
  real_T c_t282_tmp;
  real_T t282;
  real_T t289;
  real_T t296;
  real_T t298_tmp;
  real_T t303;
  real_T t304_tmp;
  real_T t310;
  real_T t315_tmp;
  real_T t426;
  real_T t430;
  real_T t319;
  real_T t322_tmp;
  real_T t422;
  real_T t421;
  real_T t324_tmp;
  real_T t324;
  real_T t329_tmp;
  real_T b_t329_tmp;
  real_T t329;
  real_T t330;
  real_T t335_tmp;
  real_T t337_tmp;
  real_T b_t337_tmp;
  real_T t337;
  real_T t340;
  real_T t348;
  real_T t349;
  real_T t353;
  real_T t354;
  real_T t356;
  real_T t357;
  real_T t383_tmp;
  real_T t361;
  real_T t368;
  real_T t374;
  real_T t377;
  real_T t380;
  real_T t381;
  real_T t387;
  int32_T i;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  (void)s;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;

  /* SPRDMPF115 */
  /*     [OUT1,OUT2,OUT3,OUT4,OUT5,OUT6,OUT7,OUT8] = SPRDMPF115(IN1,IN2,S) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.2. */
  /*     06-Jul-2019 05:49:30 */
  st.site = &emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t2 = in2[80] * in2[80];
  st.site = &b_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t3 = in2[81] * in2[81];
  st.site = &c_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t4 = in2[82] * in2[82];
  st.site = &d_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t5 = in2[83] * in2[83];
  t6 = ((t2 + t3) + t4) + t5;
  t7 = 1.0 / t6;
  t120 = in2[81] * in2[82];
  t8 = t120 * t7 * 2.0;
  t9 = t2 * t7;
  t10 = t3 * t7;
  t58 = in2[80] * in2[82];
  t11 = t58 * t7 * 2.0;
  t102 = in2[81] * in2[83];
  t12 = t102 * t7 * 2.0;
  t13_tmp = in2[82] * in2[83];
  t13 = t13_tmp * t7 * 2.0;
  t14 = t4 * t7;
  st.site = &e_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t15 = in2[31] * in2[31];
  st.site = &f_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t16 = in2[32] * in2[32];
  st.site = &g_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t17 = in2[33] * in2[33];
  st.site = &h_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t18 = in2[34] * in2[34];
  t19 = ((t15 + t16) + t17) + t18;
  st.site = &i_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  if (t19 < 0.0) {
    c_st.site = &x_emlrtRSI;
    error(&c_st);
  }

  t20 = 1.0 / muDoubleScalarPower(t19, 1.5);
  t22 = t6;
  st.site = &j_emlrtRSI;
  b_sqrt(&st, &t22);
  t21 = 1.0 / t22;
  st.site = &k_emlrtRSI;
  b_sqrt(&st, &t19);
  t22 = 1.0 / t19;
  t23 = t22 - t15 * t20;
  t25 = t22 - t16 * t20;
  t27_tmp = in2[31] * in2[32];
  t27 = t27_tmp * in2[83] * t20 * t21 * 2.0;
  t393 = in2[31] * in2[33];
  t28 = t393 * in2[81] * t20 * t21 * 2.0;
  t29 = t22 - t17 * t20;
  t31 = t22 - t18 * t20;
  t32_tmp = in2[31] * in2[34];
  t32 = t32_tmp * in2[82] * t20 * t21 * 2.0;
  t394 = in2[32] * in2[34];
  t34 = t394 * in2[82] * t20 * t21 * 2.0;
  t35 = t5 * t7;
  t15 = in2[80] * in2[83];
  t36_tmp = t15 * t7 * 2.0;
  t19 = in2[80] * in2[81];
  t37_tmp = t19 * t7 * 2.0;
  t38 = in2[28] - in2[77];
  t39 = in2[29] - in2[78];
  st.site = &l_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  if (t6 < 0.0) {
    c_st.site = &x_emlrtRSI;
    error(&c_st);
  }

  t40 = 1.0 / muDoubleScalarPower(t6, 1.5);
  t41 = in2[30] - in2[79];
  t44_tmp = in2[80] * t21;
  b_t44_tmp = in2[83] * t21;
  c_t44_tmp = in2[82] * t21;
  t44 = (t44_tmp * t38 + b_t44_tmp * t39) - c_t44_tmp * t41;
  t47_tmp = in2[81] * t21;
  t47 = (t44_tmp * t39 + t47_tmp * t41) - b_t44_tmp * t38;
  t48 = t21 * t39;
  t49 = t15 * t38 * t40;
  t74_tmp = t19 * t40;
  t16 = t74_tmp * t41;
  t50 = ((t48 + t49) - t2 * t39 * t40) - t16;
  t51 = t21 * t41;
  t17 = t19 * t39 * t40;
  t72 = t58 * t38 * t40;
  t53_tmp = t2 * t40;
  t53 = ((t51 + t17) - t53_tmp * t41) - t72;
  t54 = t21 * t38;
  t402 = t58 * t40;
  t55 = t402 * t41;
  t76 = t15 * t39 * t40;
  t56 = ((t54 + t55) - t2 * t38 * t40) - t76;
  t19 = t19 * t38 * t40;
  t58 = t58 * t39 * t40;
  t59_tmp = t15 * t40;
  t59 = t59_tmp * t41;
  t60 = (t19 + t58) + t59;
  t64 = (c_t44_tmp * t38 + t44_tmp * t41) - t47_tmp * t39;
  t68 = (t47_tmp * t38 + c_t44_tmp * t39) + b_t44_tmp * t41;
  t78 = in2[32] * t22 - t47_tmp;
  t80 = in2[33] * t22 - c_t44_tmp;
  t82 = t21 - t53_tmp;
  st.site = &m_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t83 = 1.0 / (t6 * t6);
  t85 = in2[31] * t22 - t44_tmp;
  t88 = in2[34] * t22 - b_t44_tmp;
  t92 = t21 * t64;
  t18 = t120 * t38 * t40;
  t94 = ((t48 + t16) + t18) - t3 * t39 * t40;
  t15 = t120 * t39 * t40;
  t401 = t102 * t40;
  t6 = t401 * t41;
  t98 = ((-t54 + t3 * t38 * t40) + t15) + t6;
  t99 = t102 * t38 * t40;
  t100_tmp = t3 * t40;
  t100 = ((t51 - t17) + t99) - t100_tmp * t41;
  t22 = t102 * t39 * t40;
  t107_tmp = t120 * t40;
  t16 = t107_tmp * t41;
  t102 = (t19 + t22) - t16;
  t103 = t74_tmp * t47;
  t104 = t21 * t47;
  t108 = t21 * t88 * 2.0;
  t109 = t21 - t100_tmp;
  t110 = t74_tmp * t80 * 2.0;
  t111 = t21 * t80 * 2.0;
  t113 = t21 * t68;
  t55 = ((t54 - t55) + t15) - t4 * t38 * t40;
  t116_tmp = t13_tmp * t40;
  t19 = t116_tmp * t41;
  t117 = ((-t48 + t18) + t4 * t39 * t40) + t19;
  t17 = t13_tmp * t39 * t40;
  t119_tmp = t4 * t40;
  t72 = ((t51 + t72) + t17) - t119_tmp * t41;
  t15 = t13_tmp * t38 * t40;
  t120 = (t58 + t16) - t15;
  t121 = t107_tmp * t64;
  t122 = t21 * t44;
  t126 = t402 * t64;
  t127 = t107_tmp * t85 * 2.0;
  t128 = t21 - t119_tmp;
  t129 = t107_tmp * t88 * 2.0;
  t130 = t21 * t78 * 2.0;
  t132 = t402 * t88 * 2.0;
  t133 = t59_tmp * t44;
  t18 = ((t54 + t76) + t6) - t5 * t38 * t40;
  t16 = ((t48 - t49) + t19) - t5 * t39 * t40;
  t400 = t5 * t40;
  t17 = ((-t51 + t99) + t17) + t400 * t41;
  t15 += t59 - t22;
  t141 = t116_tmp * t44;
  t142 = t401 * t85 * 2.0;
  t6 = t59_tmp * t78 * 2.0;
  t144 = t21 - t400;
  t145 = t116_tmp * t85 * 2.0;
  t147 = t116_tmp * t78 * 2.0;
  t19 = in1[4] / 2.0;
  t149 = muDoubleScalarCos(t19);
  t150 = muDoubleScalarSin(t19);
  st.site = &n_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t151 = t149 * t149;
  st.site = &o_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t152 = t150 * t150;
  t58 = t44_tmp * t56;
  t154 = b_t44_tmp * t50;
  t155 = c_t44_tmp * t94;
  t156 = b_t44_tmp * t100;
  t157_tmp = t401 * t47;
  t158 = t119_tmp * t64;
  t159 = t44_tmp * t16;
  t160 = c_t44_tmp * t15;
  t161 = t116_tmp * t64;
  t162 = t8 + t36_tmp;
  t163 = t11 - t12;
  t164 = ((t9 + t10) - t14) - t35;
  t169_tmp = t59_tmp * t47;
  t170_tmp = c_t44_tmp * t53;
  b_t170_tmp = t47_tmp * t60;
  c_t170_tmp = t53_tmp * t44;
  d_t170_tmp = t74_tmp * t68;
  t170 = (((((((-t122 - t126) - t58) - t154) + t170_tmp) + b_t170_tmp) +
           c_t170_tmp) + d_t170_tmp) + t169_tmp;
  t176_tmp = t47_tmp * t98;
  b_t176_tmp = t44_tmp * t102;
  c_t176_tmp = t100_tmp * t68;
  d_t176_tmp = t74_tmp * t44;
  t176 = (((((((-t113 - t121) - t155) - t156) + t157_tmp) + t176_tmp) +
           b_t176_tmp) + c_t176_tmp) + d_t176_tmp;
  t182_tmp = t402 * t44;
  t183_tmp = t107_tmp * t68;
  t185_tmp = c_t44_tmp * t55;
  b_t185_tmp = t47_tmp * t117;
  c_t185_tmp = t44_tmp * t72;
  d_t185_tmp = b_t44_tmp * t120;
  e_t185_tmp = t116_tmp * t47;
  t185 = (((((((t92 - t158) + t185_tmp) + c_t185_tmp) + b_t185_tmp) + d_t185_tmp)
           + t182_tmp) + t183_tmp) + e_t185_tmp;
  t190_tmp = t401 * t68;
  t191_tmp = b_t44_tmp * t18;
  b_t191_tmp = t47_tmp * t17;
  c_t191_tmp = t400 * t47;
  t191 = (((((((-t104 + t133) - t159) - t160) - t161) + t191_tmp) + b_t191_tmp)
          + c_t191_tmp) + t190_tmp;
  st.site = &p_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t199 = muDoubleScalarPower(muDoubleScalarAbs(((((((((t170 * in2[192] + t176 *
    in2[193]) + t185 * in2[194]) + t191 * in2[195]) + t163 * in2[142]) + t162 *
    in2[190]) + t164 * in2[189]) - t162 * in2[141]) - t163 * in2[191]) - t164 *
    in2[140]), in1[1] - 1.0);
  t203 = t44_tmp * t50;
  t204 = t47_tmp * t53;
  t205 = t44_tmp * t100;
  t206 = b_t44_tmp * t102;
  t207 = t401 * t44;
  t208 = t47_tmp * t55;
  t209 = b_t44_tmp * t72;
  t210 = t400 * t44;
  t211 = -t8 + t36_tmp;
  t212 = t13 + t37_tmp;
  t19 = t9 - t10;
  t213 = (t19 + t14) - t35;
  t217_tmp = t74_tmp * t64;
  t219_tmp = b_t44_tmp * t56;
  b_t219_tmp = c_t44_tmp * t60;
  c_t219_tmp = t53_tmp * t47;
  d_t219_tmp = t402 * t68;
  t219 = (((((((-t104 - t133) - t203) - t204) + t219_tmp) + b_t219_tmp) +
           c_t219_tmp) + t217_tmp) + d_t219_tmp;
  t224_tmp = t47_tmp * t94;
  b_t224_tmp = c_t44_tmp * t98;
  c_t224_tmp = t100_tmp * t64;
  t224 = (((((((-t92 + t103) + t183_tmp) - t205) - t206) - t207) + t224_tmp) +
          b_t224_tmp) + c_t224_tmp;
  t230_tmp = c_t44_tmp * t117;
  b_t230_tmp = t44_tmp * t120;
  c_t230_tmp = t119_tmp * t68;
  d_t230_tmp = t402 * t47;
  t230 = (((((((-t113 + t121) - t141) - t208) - t209) + t230_tmp) + b_t230_tmp)
          + c_t230_tmp) + d_t230_tmp;
  t237_tmp = t116_tmp * t68;
  t238_tmp = t44_tmp * t18;
  b_t238_tmp = b_t44_tmp * t16;
  c_t238_tmp = t47_tmp * t15;
  d_t238_tmp = c_t44_tmp * t17;
  e_t238_tmp = t401 * t64;
  t238 = (((((((t122 + t169_tmp) - t210) + t238_tmp) + b_t238_tmp) + d_t238_tmp)
           + c_t238_tmp) + e_t238_tmp) + t237_tmp;
  st.site = &q_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t245 = muDoubleScalarPower(muDoubleScalarAbs(((((((((t219 * in2[192] + t224 *
    in2[193]) + t230 * in2[194]) + t238 * in2[195]) + t211 * in2[140]) + t212 *
    in2[191]) + t213 * in2[190]) - t212 * in2[142]) - t211 * in2[189]) - t213 *
    in2[141]), in1[1] - 1.0);
  t249 = t44_tmp * t53;
  t250 = c_t44_tmp * t56;
  t251 = t100_tmp * t47;
  t252 = t44_tmp * t55;
  t253 = t47_tmp * t120;
  t254 = t107_tmp * t47;
  t255 = t47_tmp * t18;
  t256 = c_t44_tmp * t16;
  t257 = t11 + t12;
  t258 = -t13 + t37_tmp;
  t259 = (t19 - t14) + t35;
  t264_tmp = t47_tmp * t50;
  b_t264_tmp = b_t44_tmp * t60;
  c_t264_tmp = t53_tmp * t64;
  d_t264_tmp = t59_tmp * t68;
  t264 = (((((((-t92 - t103) + t182_tmp) - t249) - t250) + t264_tmp) +
           b_t264_tmp) + c_t264_tmp) + d_t264_tmp;
  t271_tmp = t44_tmp * t94;
  b_t271_tmp = t47_tmp * t100;
  t50 = b_t44_tmp * t98;
  t94 = c_t44_tmp * t102;
  t100 = t107_tmp * t44;
  t271 = (((((((t104 + t190_tmp) + t217_tmp) - t251) + t271_tmp) + t50) +
           b_t271_tmp) + t94) + t100;
  t102 = b_t44_tmp * t117;
  t120 = c_t44_tmp * t72;
  t60 = t119_tmp * t44;
  t276 = (((((((-t122 + t126) + t237_tmp) - t252) - t253) - t254) + t120) + t102)
    + t60;
  t406 = t44_tmp * t15;
  t282_tmp = b_t44_tmp * t17;
  b_t282_tmp = t400 * t68;
  c_t282_tmp = t59_tmp * t64;
  t282 = (((((((-t113 + t141) - t157_tmp) - t255) - t256) + t282_tmp) + t406) +
          b_t282_tmp) + c_t282_tmp;
  st.site = &r_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t289 = muDoubleScalarPower(muDoubleScalarAbs(((((((((t264 * in2[192] + t271 *
    in2[193]) + t276 * in2[194]) + t282 * in2[195]) + t258 * in2[141]) + t257 *
    in2[189]) + t259 * in2[191]) - t257 * in2[140]) - t258 * in2[190]) - t259 *
    in2[142]), in1[1] - 1.0);
  t13_tmp = t59_tmp * t80 * 2.0;
  t296 = (((((t130 + t132) + t47_tmp * t82 * 2.0) + in2[81] * t2 * t83 * 2.0) +
           t74_tmp * t85 * 2.0) - t53_tmp * t78 * 2.0) - t13_tmp;
  t99 = t100_tmp * t85 * 2.0;
  t298_tmp = t401 * t80 * 2.0;
  t54 = t119_tmp * t88 * 2.0;
  t303 = (((((t111 + t142) - t6) + c_t44_tmp * t144 * 2.0) + in2[82] * t5 * t83 *
           2.0) + t116_tmp * t88 * 2.0) - t400 * t80 * 2.0;
  t304_tmp = t393 * in2[83] * t20 * t21 * 2.0;
  t76 = t44_tmp * t25 * 2.0;
  t48 = t27_tmp * in2[81] * t20 * t21 * 2.0;
  t117 = in2[32] * in2[33];
  t49 = t117 * in2[83] * t20 * t21 * 2.0;
  t59 = t117 * in2[80] * t20 * t21 * 2.0;
  t19 = in2[33] * in2[34];
  t310 = ((t28 + b_t44_tmp * t29 * 2.0) + t19 * in2[82] * t20 * t21 * 2.0) - t59;
  t40 = t32_tmp * in2[81] * t20 * t21 * 2.0;
  t315_tmp = t21 * t85 * 2.0;
  t51 = in2[80] * t3 * t83 * 2.0;
  t426 = t44_tmp * t109 * 2.0;
  t430 = t74_tmp * t78 * 2.0;
  t319 = (((((-t129 - t99) + t298_tmp) + t315_tmp) + t426) + t51) + t430;
  t322_tmp = t402 * t78 * 2.0;
  t422 = in2[83] * t4 * t83 * 2.0;
  t421 = b_t44_tmp * t128 * 2.0;
  t324_tmp = t116_tmp * t80 * 2.0;
  t324 = (((((t108 - t127) - t54) + t421) + t422) + t322_tmp) + t324_tmp;
  t329_tmp = t47_tmp * t23 * 2.0;
  b_t329_tmp = t27_tmp * in2[80] * t20 * t21 * 2.0;
  t329 = ((-t32 + t304_tmp) + t329_tmp) + b_t329_tmp;
  t330 = ((t34 + t76) + t48) - t49;
  t335_tmp = t394 * in2[80] * t20 * t21 * 2.0;
  t337_tmp = c_t44_tmp * t31 * 2.0;
  b_t337_tmp = t19 * in2[83] * t20 * t21 * 2.0;
  t337 = ((-t40 + t337_tmp) + t335_tmp) + b_t337_tmp;
  st.site = &s_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t340 = muDoubleScalarPower(muDoubleScalarAbs(((((((t296 * in2[192] + t303 *
    in2[195]) + t330 * in2[144]) + t310 * in2[145]) - t319 * in2[193]) - t324 *
    in2[194]) - t329 * in2[143]) - t337 * in2[146]), in1[1] - 1.0);
  t98 = t74_tmp * t88 * 2.0;
  t348 = (((((t111 + t6) + c_t44_tmp * t82 * 2.0) + in2[82] * t2 * t83 * 2.0) +
           t402 * t85 * 2.0) - t53_tmp * t80 * 2.0) - t98;
  t349 = t119_tmp * t85 * 2.0;
  t353 = (((((t108 - t110) + t127) + b_t44_tmp * t109 * 2.0) + in2[83] * t3 *
           t83 * 2.0) + t401 * t78 * 2.0) - t100_tmp * t88 * 2.0;
  t354 = t400 * t78 * 2.0;
  t116_tmp = t27_tmp * in2[82] * t20 * t21 * 2.0;
  t356 = t44_tmp * t29 * 2.0;
  t357 = t393 * in2[82] * t20 * t21 * 2.0;
  t6 = t19 * in2[81] * t20 * t21 * 2.0;
  t383_tmp = t19 * in2[80] * t20 * t21 * 2.0;
  t361 = ((t32 + t47_tmp * t31 * 2.0) + t394 * in2[83] * t20 * t21 * 2.0) -
    t383_tmp;
  t74_tmp = in2[80] * t4 * t83 * 2.0;
  t27_tmp = t44_tmp * t128 * 2.0;
  t22 = t402 * t80 * 2.0;
  t368 = (((((t129 - t147) + t315_tmp) - t349) + t27_tmp) + t74_tmp) + t22;
  t55 = in2[81] * t5 * t83 * 2.0;
  t72 = t47_tmp * t144 * 2.0;
  t17 = t401 * t88 * 2.0;
  t374 = (((((t130 - t145) + t13_tmp) - t354) + t72) + t55) + t17;
  t18 = c_t44_tmp * t23 * 2.0;
  t15 = t393 * in2[80] * t20 * t21 * 2.0;
  t377 = ((-t27 + t40) + t18) + t15;
  t16 = b_t44_tmp * t25 * 2.0;
  t19 = t394 * in2[81] * t20 * t21 * 2.0;
  t380 = ((t59 - t116_tmp) + t16) + t19;
  t381 = ((t49 + t356) + t357) - t6;
  st.site = &t_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t387 = muDoubleScalarPower(muDoubleScalarAbs(((((((t348 * in2[192] + t353 *
    in2[193]) + t381 * in2[145]) + t361 * in2[146]) - t368 * in2[194]) - t374 *
    in2[195]) - t377 * in2[143]) - t380 * in2[144]), in1[1] - 1.0);
  t56 = b_t44_tmp * t82 * 2.0;
  t393 = in2[83] * t2 * t83 * 2.0;
  t394 = t59_tmp * t85 * 2.0;
  t53 = t100_tmp * t80 * 2.0;
  t132 = (((((t130 - t132) + t145) + t47_tmp * t128 * 2.0) + in2[81] * t4 * t83 *
           2.0) + t107_tmp * t80 * 2.0) - t119_tmp * t78 * 2.0;
  t400 = t400 * t85 * 2.0;
  t401 = c_t44_tmp * t25 * 2.0;
  t402 = t117 * in2[81] * t20 * t21 * 2.0;
  t128 = ((-t34 + t6) + t44_tmp * t31 * 2.0) + t32_tmp * in2[83] * t20 * t21 *
    2.0;
  memset(&out1[0], 0, 28U * sizeof(real_T));
  out1[28] = ((t9 + t10) - t4 * t7) - t5 * t7;
  out1[29] = t162;
  out1[30] = -t11 + t12;
  memset(&out1[31], 0, 46U * sizeof(real_T));
  out1[77] = ((-t9 - t10) + t14) + t35;
  out1[78] = -t8 - t36_tmp;
  out1[79] = t163;
  out1[80] = (((((((t122 + t126) + t58) + t154) - t170_tmp) - b_t170_tmp) -
               c_t170_tmp) - t169_tmp) - d_t170_tmp;
  out1[81] = (((((((t113 + t121) + t155) + t156) - t176_tmp) - b_t176_tmp) -
               c_t176_tmp) - d_t176_tmp) - t157_tmp;
  out1[82] = (((((((-t92 + t158) - t185_tmp) - b_t185_tmp) - c_t185_tmp) -
                d_t185_tmp) - t182_tmp) - e_t185_tmp) - t183_tmp;
  out1[83] = (((((((t104 - t133) + t159) + t160) + t161) - t191_tmp) -
               b_t191_tmp) - c_t191_tmp) - t190_tmp;
  memset(&out1[84], 0, 50U * sizeof(real_T));
  out1[134] = t8 - t36_tmp;
  out1[135] = ((t9 - t10) + t14) - t5 * t7;
  out1[136] = t212;
  memset(&out1[137], 0, 46U * sizeof(real_T));
  out1[183] = t211;
  t58 = -t9 + t10;
  out1[184] = (t58 - t14) + t35;
  out1[185] = -t13 - t37_tmp;
  out1[186] = (((((((t104 + t133) + t203) + t204) - t219_tmp) - b_t219_tmp) -
                c_t219_tmp) - t217_tmp) - d_t219_tmp;
  out1[187] = (((((((t92 - t103) + t205) + t206) + t207) - t224_tmp) -
                b_t224_tmp) - c_t224_tmp) - t183_tmp;
  out1[188] = (((((((t113 - t121) + t141) + t208) + t209) - t230_tmp) -
                b_t230_tmp) - c_t230_tmp) - d_t230_tmp;
  out1[189] = (((((((-t122 + t210) - t238_tmp) - b_t238_tmp) - c_t238_tmp) -
                 d_t238_tmp) - t169_tmp) - e_t238_tmp) - t237_tmp;
  memset(&out1[190], 0, 50U * sizeof(real_T));
  out1[240] = t257;
  out1[241] = t13 - t37_tmp;
  out1[242] = t259;
  memset(&out1[243], 0, 46U * sizeof(real_T));
  out1[289] = -t11 - t12;
  out1[290] = t258;
  out1[291] = (t58 + t14) - t35;
  out1[292] = (((((((t92 + t103) + t249) + t250) - t264_tmp) - b_t264_tmp) -
                c_t264_tmp) - t182_tmp) - d_t264_tmp;
  out1[293] = (((((((-t104 + t251) - t271_tmp) - b_t271_tmp) - t50) - t94) -
                t100) - t217_tmp) - t190_tmp;
  out1[294] = (((((((t122 - t126) + t252) + t253) + t254) - t102) - t120) - t60)
    - t237_tmp;
  out1[295] = (((((((t113 - t141) + t157_tmp) + t255) + t256) - t406) - t282_tmp)
               - b_t282_tmp) - c_t282_tmp;
  memset(&out1[296], 0, 53U * sizeof(real_T));
  out1[349] = ((t32 - t329_tmp) - b_t329_tmp) - t304_tmp;
  out1[350] = ((t34 + t76) + t48) - in2[32] * in2[33] * in2[83] * t20 * t21 *
    2.0;
  out1[351] = t310;
  out1[352] = ((t40 - t337_tmp) - t335_tmp) - b_t337_tmp;
  memset(&out1[353], 0, 45U * sizeof(real_T));
  out1[398] = t296;
  out1[399] = (((((t129 + t99) - t315_tmp) - t51) - t426) - t430) - t298_tmp;
  out1[400] = (((((-t108 + t127) + t54) - t422) - t421) - t322_tmp) - t324_tmp;
  out1[401] = t303;
  memset(&out1[402], 0, 53U * sizeof(real_T));
  out1[455] = ((t27 - t18) - t15) - t40;
  out1[456] = ((t116_tmp - t16) - t59) - t19;
  out1[457] = ((t49 + t356) + t357) - in2[33] * in2[34] * in2[81] * t20 * t21 *
    2.0;
  out1[458] = t361;
  memset(&out1[459], 0, 45U * sizeof(real_T));
  out1[504] = t348;
  out1[505] = t353;
  out1[506] = (((((-t129 + t147) + t349) - t315_tmp) - t74_tmp) - t27_tmp) - t22;
  out1[507] = (((((-t130 + t145) + t354) - t55) - t72) - t13_tmp) - t17;
  memset(&out1[508], 0, 53U * sizeof(real_T));
  t58 = b_t44_tmp * t23 * 2.0;
  t102 = t32_tmp * in2[80] * t20 * t21 * 2.0;
  out1[561] = ((t28 - t58) - t116_tmp) - t102;
  out1[562] = ((t27 + t401) + t402) - t335_tmp;
  t72 = t47_tmp * t29 * 2.0;
  t55 = t117 * in2[82] * t20 * t21 * 2.0;
  out1[563] = ((t304_tmp - t72) - t55) - t383_tmp;
  out1[564] = t128;
  memset(&out1[565], 0, 45U * sizeof(real_T));
  t120 = t108 + t110;
  t6 = t53_tmp * t88 * 2.0;
  out1[610] = ((((t120 + t56) + t393) + t394) - t6) - t322_tmp;
  t22 = c_t44_tmp * t109 * 2.0;
  t18 = in2[82] * t3 * t83 * 2.0;
  t16 = t107_tmp * t78 * 2.0;
  out1[611] = (((((-t111 + t142) + t53) - t18) - t22) - t16) - t98;
  out1[612] = t132;
  t17 = t44_tmp * t144 * 2.0;
  t15 = in2[80] * t5 * t83 * 2.0;
  t19 = t59_tmp * t88 * 2.0;
  out1[613] = (((((-t147 + t298_tmp) + t400) - t315_tmp) - t15) - t17) - t19;
  memset(&out1[614], 0, 22U * sizeof(real_T));
  t406 = ((((t120 - t322_tmp) + t56) + t393) + t394) - t6;
  t394 = (((((t111 - t142) + t98) - t53) + t22) + t18) + t16;
  t393 = (((((t147 - t298_tmp) + t315_tmp) - t400) + t17) + t15) + t19;
  t421 = ((-t28 + t116_tmp) + t58) + t102;
  t422 = ((t27 - t335_tmp) + t401) + t402;
  t426 = ((-t304_tmp + t383_tmp) + t72) + t55;
  st.site = &u_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t430 = muDoubleScalarPower(muDoubleScalarAbs(((((((t406 * in2[192] + t132 *
    in2[194]) + t422 * in2[144]) + t128 * in2[146]) - t394 * in2[193]) - t393 *
    in2[195]) - t421 * in2[143]) - t426 * in2[145]), in1[1] - 1.0);
  out2[0] = in1[0] * ((((t149 * t150 * -0.166 + t44_tmp * t44) + b_t44_tmp * t47)
                       - c_t44_tmp * t64) + t47_tmp * t68) *
    -0.00026666666666666668;
  out2[1] = in1[0] * (((((t151 * 0.01096696696710326 + t152 *
    0.01096696696710326) - t44_tmp * t47) + b_t44_tmp * t44) - t47_tmp * t64) -
                      c_t44_tmp * t68) * 0.00026666666666666668;
  t19 = t152 * -0.083 + t151 * 0.083;
  out2[2] = in1[0] * ((((t19 + c_t44_tmp * t44) - t47_tmp * t47) + t44_tmp * t64)
                      + b_t44_tmp * t68) * -0.0008;
  out2[3] = in1[0] * (((t44_tmp * t78 * 2.0 + b_t44_tmp * t80 * 2.0) - t47_tmp *
                       t85 * 2.0) - c_t44_tmp * t88 * 2.0) *
    -4.2666666666666668E-11;
  out2[4] = in1[0] * (((t44_tmp * t80 * 2.0 - b_t44_tmp * t78 * 2.0) - c_t44_tmp
                       * t85 * 2.0) + t47_tmp * t88 * 2.0) *
    -1.421066666666666E-8;
  out2[5] = in1[0] * (((c_t44_tmp * t78 * 2.0 - t47_tmp * t80 * 2.0) + t44_tmp *
                       t88 * 2.0) - b_t44_tmp * t85 * 2.0) *
    -4.75111111111111E-9;
  t120 = in1[2] * t164 * t199;
  t55 = in1[2] * t163 * t199;
  t72 = -in1[2] * t162 * t199;
  t13_tmp = in1[2] * t162 * t199;
  t99 = in1[2] * t170 * t199;
  t54 = in1[2] * t176 * t199;
  t76 = in1[2] * t185 * t199;
  t48 = in1[2] * t191 * t199;
  out3[0] = ((((((((t72 * in2[141] - t120 * in2[140]) + t55 * in2[142]) +
                  t13_tmp * in2[190]) + t120 * in2[189]) - t55 * in2[191]) + t99
               * in2[192]) + t54 * in2[193]) + t76 * in2[194]) + t48 * in2[195];
  t49 = in1[2] * t211 * t245;
  t59 = in1[2] * t212 * t245;
  t40 = in1[2] * t213 * t245;
  t51 = in1[2] * t219 * t245;
  t53 = in1[2] * t224 * t245;
  t56 = in1[2] * t230 * t245;
  t60 = in1[2] * t238 * t245;
  out3[1] = ((((((((t49 * in2[140] - t59 * in2[142]) - t40 * in2[141]) - t49 *
                  in2[189]) + t59 * in2[191]) + t40 * in2[190]) + t51 * in2[192])
              + t53 * in2[193]) + t56 * in2[194]) + t60 * in2[195];
  t117 = in1[2] * t258 * t289;
  t94 = in1[2] * t259 * t289;
  t100 = -in1[2] * t257 * t289;
  t50 = in1[2] * t257 * t289;
  t98 = in1[2] * t264 * t289;
  t116_tmp = in1[2] * t271 * t289;
  t74_tmp = in1[2] * t276 * t289;
  t27_tmp = in1[2] * t282 * t289;
  out3[2] = ((((((((t100 * in2[140] + t117 * in2[141]) - t94 * in2[142]) + t50 *
                  in2[189]) - t117 * in2[190]) + t94 * in2[191]) + t98 * in2[192])
              + t116_tmp * in2[193]) + t74_tmp * in2[194]) + t27_tmp * in2[195];
  t356 = in1[3] * t329 * t340;
  t357 = -in1[3] * t310 * t340;
  t349 = in1[3] * t337 * t340;
  t354 = in1[3] * t319 * t340;
  t400 = in1[3] * t324 * t340;
  out3[3] = ((((((t357 * in2[145] + t356 * in2[143]) - in1[3] * t330 * t340 *
                 in2[144]) + t349 * in2[146]) - in1[3] * t296 * t340 * in2[192])
              - in1[3] * t303 * t340 * in2[195]) + t354 * in2[193]) + t400 *
    in2[194];
  t401 = in1[3] * t377 * t387;
  t402 = in1[3] * t380 * t387;
  t324_tmp = -in1[3] * t361 * t387;
  t329_tmp = in1[3] * t368 * t387;
  b_t329_tmp = in1[3] * t374 * t387;
  out3[4] = ((((((t324_tmp * in2[146] + t401 * in2[143]) + t402 * in2[144]) -
                in1[3] * t381 * t387 * in2[145]) - in1[3] * t348 * t387 * in2
               [192]) - in1[3] * t353 * t387 * in2[193]) + t329_tmp * in2[194])
    + b_t329_tmp * in2[195];
  t337_tmp = in1[3] * t421 * t430;
  b_t337_tmp = in1[3] * t426 * t430;
  t282_tmp = -in1[3] * t128 * t430;
  b_t282_tmp = in1[3] * t394 * t430;
  c_t282_tmp = in1[3] * t393 * t430;
  out3[5] = ((((((t282_tmp * in2[146] + t337_tmp * in2[143]) - in1[3] * t422 *
                 t430 * in2[144]) + b_t337_tmp * in2[145]) - in1[3] * t132 *
               t430 * in2[194]) - in1[3] * t406 * t430 * in2[192]) + b_t282_tmp *
             in2[193]) + c_t282_tmp * in2[195];
  for (i = 0; i < 6; i++) {
    out4[i] = 0.0;
  }

  st.site = &v_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  st.site = &v_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  st.site = &v_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t22 = (t38 * t38 + t39 * t39) + t41 * t41;
  st.site = &v_emlrtRSI;
  b_sqrt(&st, &t22);
  *out5 = t19 + t22;
  t102 = in1[0] * t164 * 0.00026666666666666668;
  t58 = in1[0] * t162 * 0.00026666666666666668;
  t6 = in1[0] * t213 * 0.00026666666666666668;
  t22 = in1[0] * t212 * 0.00026666666666666668;
  t17 = in1[0] * t257 * 0.0008;
  t18 = in1[0] * t259 * 0.0008;
  memset(&out6[0], 0, 168U * sizeof(real_T));
  out6[168] = t102;
  t16 = in1[0] * t211;
  out6[169] = t16 * -0.00026666666666666668;
  out6[170] = t17;
  out6[171] = 0.0;
  out6[172] = 0.0;
  out6[173] = 0.0;
  out6[174] = t58;
  out6[175] = t6;
  t15 = in1[0] * t258;
  out6[176] = t15 * -0.0008;
  out6[177] = 0.0;
  out6[178] = 0.0;
  out6[179] = 0.0;
  t19 = in1[0] * t163;
  out6[180] = t19 * -0.00026666666666666668;
  out6[181] = t22;
  out6[182] = t18;
  out6[183] = 0.0;
  out6[184] = 0.0;
  out6[185] = 0.0;
  out6[186] = 0.0;
  out6[187] = 0.0;
  out6[188] = 0.0;
  out6[189] = in1[0] * t329 * -4.2666666666666668E-11;
  out6[190] = in1[0] * t377 * -1.421066666666666E-8;
  out6[191] = in1[0] * t421 * -4.75111111111111E-9;
  out6[192] = 0.0;
  out6[193] = 0.0;
  out6[194] = 0.0;
  out6[195] = in1[0] * t330 * 4.2666666666666668E-11;
  out6[196] = in1[0] * t380 * -1.421066666666666E-8;
  out6[197] = in1[0] * t422 * 4.75111111111111E-9;
  out6[198] = 0.0;
  out6[199] = 0.0;
  out6[200] = 0.0;
  out6[201] = in1[0] * t310 * 4.2666666666666668E-11;
  out6[202] = in1[0] * t381 * 1.421066666666666E-8;
  out6[203] = in1[0] * t426 * -4.75111111111111E-9;
  out6[204] = 0.0;
  out6[205] = 0.0;
  out6[206] = 0.0;
  out6[207] = in1[0] * t337 * -4.2666666666666668E-11;
  out6[208] = in1[0] * t361 * 1.421066666666666E-8;
  out6[209] = in1[0] * t128 * 4.75111111111111E-9;
  memset(&out6[210], 0, 252U * sizeof(real_T));
  out6[462] = -t102;
  out6[463] = t16 * 0.00026666666666666668;
  out6[464] = -t17;
  out6[465] = 0.0;
  out6[466] = 0.0;
  out6[467] = 0.0;
  out6[468] = -t58;
  out6[469] = -t6;
  out6[470] = t15 * 0.0008;
  out6[471] = 0.0;
  out6[472] = 0.0;
  out6[473] = 0.0;
  out6[474] = t19 * 0.00026666666666666668;
  out6[475] = -t22;
  out6[476] = -t18;
  out6[477] = 0.0;
  out6[478] = 0.0;
  out6[479] = 0.0;
  out6[480] = in1[0] * t170 * -0.00026666666666666668;
  out6[481] = in1[0] * t219 * -0.00026666666666666668;
  out6[482] = in1[0] * t264 * -0.0008;
  out6[483] = in1[0] * t296 * 4.2666666666666668E-11;
  out6[484] = in1[0] * t348 * 1.421066666666666E-8;
  out6[485] = in1[0] * t406 * 4.75111111111111E-9;
  out6[486] = in1[0] * t176 * -0.00026666666666666668;
  out6[487] = in1[0] * t224 * -0.00026666666666666668;
  out6[488] = in1[0] * t271 * -0.0008;
  out6[489] = in1[0] * t319 * -4.2666666666666668E-11;
  out6[490] = in1[0] * t353 * 1.421066666666666E-8;
  out6[491] = in1[0] * t394 * -4.75111111111111E-9;
  out6[492] = in1[0] * t185 * -0.00026666666666666668;
  out6[493] = in1[0] * t230 * -0.00026666666666666668;
  out6[494] = in1[0] * t276 * -0.0008;
  out6[495] = in1[0] * t324 * -4.2666666666666668E-11;
  out6[496] = in1[0] * t368 * -1.421066666666666E-8;
  out6[497] = in1[0] * t132 * 4.75111111111111E-9;
  out6[498] = in1[0] * t191 * -0.00026666666666666668;
  out6[499] = in1[0] * t238 * -0.00026666666666666668;
  out6[500] = in1[0] * t282 * -0.0008;
  out6[501] = in1[0] * t303 * 4.2666666666666668E-11;
  out6[502] = in1[0] * t374 * -1.421066666666666E-8;
  out6[503] = in1[0] * t393 * -4.75111111111111E-9;
  memset(&out6[504], 0, 132U * sizeof(real_T));
  memset(&out7[0], 0, 168U * sizeof(real_T));
  out7[168] = -in1[2] * t164 * t199;
  out7[169] = t49;
  out7[170] = t100;
  out7[171] = 0.0;
  out7[172] = 0.0;
  out7[173] = 0.0;
  out7[174] = t72;
  out7[175] = -in1[2] * t213 * t245;
  out7[176] = t117;
  out7[177] = 0.0;
  out7[178] = 0.0;
  out7[179] = 0.0;
  out7[180] = t55;
  out7[181] = -in1[2] * t212 * t245;
  out7[182] = -in1[2] * t259 * t289;
  out7[183] = 0.0;
  out7[184] = 0.0;
  out7[185] = 0.0;
  out7[186] = 0.0;
  out7[187] = 0.0;
  out7[188] = 0.0;
  out7[189] = t356;
  out7[190] = t401;
  out7[191] = t337_tmp;
  out7[192] = 0.0;
  out7[193] = 0.0;
  out7[194] = 0.0;
  out7[195] = -in1[3] * t330 * t340;
  out7[196] = t402;
  out7[197] = -in1[3] * t422 * t430;
  out7[198] = 0.0;
  out7[199] = 0.0;
  out7[200] = 0.0;
  out7[201] = t357;
  out7[202] = -in1[3] * t381 * t387;
  out7[203] = b_t337_tmp;
  out7[204] = 0.0;
  out7[205] = 0.0;
  out7[206] = 0.0;
  out7[207] = t349;
  out7[208] = t324_tmp;
  out7[209] = t282_tmp;
  memset(&out7[210], 0, 252U * sizeof(real_T));
  out7[462] = t120;
  out7[463] = -t49;
  out7[464] = t50;
  out7[465] = 0.0;
  out7[466] = 0.0;
  out7[467] = 0.0;
  out7[468] = t13_tmp;
  out7[469] = t40;
  out7[470] = -t117;
  out7[471] = 0.0;
  out7[472] = 0.0;
  out7[473] = 0.0;
  out7[474] = -t55;
  out7[475] = t59;
  out7[476] = t94;
  out7[477] = 0.0;
  out7[478] = 0.0;
  out7[479] = 0.0;
  out7[480] = t99;
  out7[481] = t51;
  out7[482] = t98;
  out7[483] = -in1[3] * t296 * t340;
  out7[484] = -in1[3] * t348 * t387;
  out7[485] = -in1[3] * t406 * t430;
  out7[486] = t54;
  out7[487] = t53;
  out7[488] = t116_tmp;
  out7[489] = t354;
  out7[490] = -in1[3] * t353 * t387;
  out7[491] = b_t282_tmp;
  out7[492] = t76;
  out7[493] = t56;
  out7[494] = t74_tmp;
  out7[495] = t400;
  out7[496] = t329_tmp;
  out7[497] = -in1[3] * t132 * t430;
  out7[498] = t48;
  out7[499] = t60;
  out7[500] = t27_tmp;
  out7[501] = -in1[3] * t303 * t340;
  out7[502] = b_t329_tmp;
  out7[503] = c_t282_tmp;
  memset(&out7[504], 0, 132U * sizeof(real_T));
  *out8 = 1.0;
}

/* End of code generation (sprdmpF115.c) */
