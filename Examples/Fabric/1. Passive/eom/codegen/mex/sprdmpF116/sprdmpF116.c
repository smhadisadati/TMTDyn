/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sprdmpF116.c
 *
 * Code generation for function 'sprdmpF116'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "sprdmpF116.h"
#include "sqrt.h"
#include "error.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 41,    /* lineNo */
  "sprdmpF116",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF116.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 42,  /* lineNo */
  "sprdmpF116",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF116.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 43,  /* lineNo */
  "sprdmpF116",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF116.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 44,  /* lineNo */
  "sprdmpF116",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF116.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 52,  /* lineNo */
  "sprdmpF116",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF116.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 55,  /* lineNo */
  "sprdmpF116",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF116.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 93,  /* lineNo */
  "sprdmpF116",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF116.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 94,  /* lineNo */
  "sprdmpF116",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF116.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 95,  /* lineNo */
  "sprdmpF116",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF116.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 96,  /* lineNo */
  "sprdmpF116",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF116.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 98,  /* lineNo */
  "sprdmpF116",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF116.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 106, /* lineNo */
  "sprdmpF116",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF116.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 168, /* lineNo */
  "sprdmpF116",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF116.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 240, /* lineNo */
  "sprdmpF116",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF116.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 286, /* lineNo */
  "sprdmpF116",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF116.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 330, /* lineNo */
  "sprdmpF116",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF116.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 385, /* lineNo */
  "sprdmpF116",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF116.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 434, /* lineNo */
  "sprdmpF116",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF116.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 479, /* lineNo */
  "sprdmpF116",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF116.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 481, /* lineNo */
  "sprdmpF116",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF116.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 483, /* lineNo */
  "sprdmpF116",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF116.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 493, /* lineNo */
  "sprdmpF116",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF116.m"/* pathName */
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
void sprdmpF116(const emlrtStack *sp, const real_T in1[6], const real_T in2[224],
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
  real_T t77;
  real_T t8;
  real_T t9;
  real_T t10;
  real_T t33;
  real_T t11;
  real_T t12_tmp;
  real_T t78;
  real_T t13;
  real_T t14;
  real_T t15;
  real_T t16;
  real_T t17;
  real_T t20_tmp;
  real_T b_t20_tmp;
  real_T c_t20_tmp;
  real_T t20;
  real_T t23_tmp;
  real_T t23;
  real_T t24;
  real_T t25;
  real_T t402;
  real_T t50;
  real_T t26;
  real_T t27;
  real_T t28;
  real_T t348;
  real_T t48;
  real_T t399;
  real_T t29;
  real_T t30;
  real_T t401;
  real_T t31;
  real_T t52;
  real_T t32;
  real_T t34;
  real_T t35_tmp;
  real_T t35;
  real_T t36;
  real_T t40;
  real_T t44;
  real_T t54;
  real_T t55;
  real_T t56;
  real_T t57;
  real_T t58;
  real_T t59;
  real_T t60;
  real_T t62;
  real_T t64;
  real_T t65;
  real_T t67;
  real_T t70;
  real_T t74_tmp;
  real_T t75;
  real_T t347;
  real_T t403;
  real_T t79;
  real_T t80;
  real_T t81_tmp;
  real_T t81;
  real_T t82;
  real_T t86_tmp;
  real_T t83;
  real_T t87;
  real_T t88;
  real_T t90;
  real_T t91;
  real_T t92;
  real_T t93;
  real_T t398;
  real_T t96;
  real_T t400;
  real_T t99;
  real_T t103;
  real_T t104;
  real_T t105;
  real_T t107_tmp;
  real_T t112_tmp;
  real_T t114;
  real_T t115;
  real_T t118;
  real_T t119_tmp;
  real_T t120;
  real_T t121;
  real_T t123;
  real_T t124_tmp;
  real_T t124;
  real_T t125_tmp;
  real_T t126_tmp;
  real_T t127_tmp;
  real_T t128_tmp;
  real_T t129;
  real_T t130;
  real_T t132;
  real_T t134_tmp;
  real_T t134;
  real_T t135;
  real_T t136;
  real_T t138;
  real_T t139;
  real_T t141_tmp;
  real_T t141;
  real_T t143;
  real_T t144;
  real_T t147;
  real_T t150;
  real_T t151_tmp;
  real_T t152;
  real_T t153;
  real_T t154;
  real_T t155_tmp;
  real_T t156;
  real_T t161_tmp;
  real_T t162_tmp;
  real_T t168;
  real_T t172_tmp;
  real_T t173;
  real_T t174;
  real_T t175;
  real_T t176;
  real_T t177_tmp;
  real_T b_t177_tmp;
  real_T t177;
  real_T t196_tmp;
  real_T t179_tmp;
  real_T b_t179_tmp;
  real_T c_t179_tmp;
  real_T t179;
  real_T t193;
  real_T t202;
  real_T t203;
  real_T t204;
  real_T t205;
  real_T t206;
  real_T t207;
  real_T t208;
  real_T t209_tmp;
  real_T t210;
  real_T t211;
  real_T t212;
  real_T t213;
  real_T t214_tmp;
  real_T t220;
  real_T t221;
  real_T t222;
  real_T t223_tmp;
  real_T t223;
  real_T t224_tmp;
  real_T b_t224_tmp;
  real_T t224;
  real_T t226_tmp;
  real_T b_t226_tmp;
  real_T c_t226_tmp;
  real_T t226;
  real_T t228_tmp;
  real_T b_t228_tmp;
  real_T t228;
  real_T t237;
  real_T t248;
  real_T t249;
  real_T t250;
  real_T t251;
  real_T t257;
  real_T t258;
  real_T t259;
  real_T t260;
  real_T t261;
  real_T t262;
  real_T t263;
  real_T t264;
  real_T t265;
  real_T t266;
  real_T t267_tmp;
  real_T t267;
  real_T t268_tmp;
  real_T b_t268_tmp;
  real_T t268;
  real_T t272_tmp;
  real_T b_t272_tmp;
  real_T c_t272_tmp;
  real_T t272;
  real_T t274_tmp;
  real_T t274;
  real_T t281;
  real_T t292_tmp;
  real_T t296_tmp;
  real_T t299_tmp;
  real_T t304_tmp;
  real_T t326_tmp;
  real_T t305;
  real_T t306_tmp;
  real_T t307;
  real_T t308;
  real_T t309;
  real_T t334_tmp;
  real_T t312;
  real_T t314;
  real_T t424;
  real_T t421;
  real_T t416;
  real_T t320;
  real_T t415;
  real_T t409;
  real_T t325;
  real_T t331_tmp;
  real_T t331;
  real_T t332;
  real_T t337_tmp;
  real_T t339;
  real_T t342;
  real_T t351_tmp;
  real_T t353;
  real_T t355_tmp;
  real_T t357_tmp;
  real_T t386_tmp;
  real_T t363;
  real_T t364;
  real_T t370;
  real_T t371;
  real_T t376_tmp;
  real_T t377;
  real_T t380;
  real_T t383;
  real_T t384;
  real_T t390;
  real_T t396;
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

  /* SPRDMPF116 */
  /*     [OUT1,OUT2,OUT3,OUT4,OUT5,OUT6,OUT7,OUT8] = SPRDMPF116(IN1,IN2,S) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.2. */
  /*     06-Jul-2019 08:05:39 */
  st.site = &emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t2 = in2[31] * in2[31];
  st.site = &b_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t3 = in2[32] * in2[32];
  st.site = &c_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t4 = in2[33] * in2[33];
  st.site = &d_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t5 = in2[34] * in2[34];
  t6 = ((t2 + t3) + t4) + t5;
  t7 = 1.0 / t6;
  t77 = in2[31] * in2[34];
  t8 = t77 * t7 * 2.0;
  t9 = t4 * t7;
  t10 = t5 * t7;
  t33 = in2[31] * in2[32];
  t11 = t33 * t7 * 2.0;
  t12_tmp = t3 * t7;
  t78 = t6;
  st.site = &e_emlrtRSI;
  b_sqrt(&st, &t78);
  t13 = 1.0 / t78;
  t14 = in2[28] - in2[35];
  t15 = in2[29] - in2[36];
  st.site = &f_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  if (t6 < 0.0) {
    c_st.site = &x_emlrtRSI;
    error(&c_st);
  }

  t16 = 1.0 / muDoubleScalarPower(t6, 1.5);
  t17 = in2[30] - in2[37];
  t20_tmp = in2[31] * t13;
  b_t20_tmp = in2[34] * t13;
  c_t20_tmp = in2[33] * t13;
  t20 = (t20_tmp * t14 + b_t20_tmp * t15) - c_t20_tmp * t17;
  t23_tmp = in2[32] * t13;
  t23 = (t20_tmp * t15 + t23_tmp * t17) - b_t20_tmp * t14;
  t24 = t13 * t15;
  t25 = t77 * t14 * t16;
  t402 = t33 * t16;
  t50 = t402 * t17;
  t26 = ((t24 + t25) - t2 * t15 * t16) - t50;
  t27 = t13 * t17;
  t28 = t33 * t15 * t16;
  t348 = in2[31] * in2[33];
  t48 = t348 * t14 * t16;
  t399 = t2 * t16;
  t29 = ((t27 + t28) - t399 * t17) - t48;
  t30 = t13 * t14;
  t401 = t348 * t16;
  t31 = t401 * t17;
  t52 = t77 * t15 * t16;
  t32 = ((t30 + t31) - t2 * t14 * t16) - t52;
  t33 = t33 * t14 * t16;
  t34 = t348 * t15 * t16;
  t35_tmp = t77 * t16;
  t35 = t35_tmp * t17;
  t36 = (t33 + t34) + t35;
  t40 = (c_t20_tmp * t14 + t20_tmp * t17) - t23_tmp * t15;
  t44 = (t23_tmp * t14 + c_t20_tmp * t15) + b_t20_tmp * t17;
  st.site = &g_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t54 = in2[38] * in2[38];
  st.site = &h_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t55 = in2[39] * in2[39];
  st.site = &i_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t56 = in2[40] * in2[40];
  st.site = &j_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t57 = in2[41] * in2[41];
  t58 = ((t54 + t55) + t56) + t57;
  t78 = t58;
  st.site = &k_emlrtRSI;
  b_sqrt(&st, &t78);
  t59 = 1.0 / t78;
  t60 = t23_tmp - in2[39] * t59;
  t62 = c_t20_tmp - in2[40] * t59;
  t64 = t13 - t399;
  st.site = &l_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t65 = 1.0 / (t6 * t6);
  t67 = t20_tmp - in2[38] * t59;
  t70 = b_t20_tmp - in2[41] * t59;
  t74_tmp = in2[32] * in2[33];
  t6 = t74_tmp * t14 * t16;
  t75 = ((t24 + t50) + t6) - t3 * t15 * t16;
  t77 = t74_tmp * t15 * t16;
  t347 = in2[32] * in2[34];
  t403 = t347 * t16;
  t78 = t403 * t17;
  t79 = ((-t30 + t3 * t14 * t16) + t77) + t78;
  t80 = t347 * t14 * t16;
  t81_tmp = t3 * t16;
  t81 = ((t27 - t28) + t80) - t81_tmp * t17;
  t82 = t347 * t15 * t16;
  t86_tmp = t74_tmp * t16;
  t50 = t86_tmp * t17;
  t83 = (t33 + t82) - t50;
  t87 = t402 * t40;
  t88 = t13 - t81_tmp;
  t90 = t402 * t70 * 2.0;
  t91 = t401 * t20;
  t92 = t86_tmp * t44;
  t93 = ((t30 - t31) + t77) - t4 * t14 * t16;
  t77 = in2[33] * in2[34];
  t398 = t77 * t16;
  t28 = t398 * t17;
  t96 = ((-t24 + t6) + t4 * t15 * t16) + t28;
  t6 = t77 * t15 * t16;
  t400 = t4 * t16;
  t48 = ((t27 + t48) + t6) - t400 * t17;
  t33 = t77 * t14 * t16;
  t99 = (t34 + t50) - t33;
  t103 = t401 * t60 * 2.0;
  t104 = t13 * t67 * 2.0;
  t105 = t13 - t400;
  t107_tmp = t13 * t23;
  t31 = t403 * t44;
  t78 = ((t30 + t52) + t78) - t5 * t14 * t16;
  t34 = ((t24 - t25) + t28) - t5 * t15 * t16;
  t112_tmp = t5 * t16;
  t28 = ((-t27 + t80) + t6) + t112_tmp * t17;
  t50 = (t35 - t82) + t33;
  t114 = t35_tmp * t23;
  t115 = t398 * t44;
  t118 = t403 * t23;
  t119_tmp = t13 * t62 * 2.0;
  t120 = t13 - t112_tmp;
  t121 = t35_tmp * t62 * 2.0;
  t123 = t403 * t62 * 2.0;
  t124_tmp = t348 * t7;
  t124 = t124_tmp * 2.0;
  t125_tmp = t74_tmp * t7 * 2.0;
  t126_tmp = t2 * t7;
  t127_tmp = t347 * t7 * 2.0;
  t128_tmp = t77 * t7 * 2.0;
  st.site = &m_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  if (t58 < 0.0) {
    c_st.site = &x_emlrtRSI;
    error(&c_st);
  }

  t129 = 1.0 / muDoubleScalarPower(t58, 1.5);
  t130 = t59 - t54 * t129;
  t132 = t59 - t55 * t129;
  t134_tmp = in2[34] * in2[38];
  t134 = t134_tmp * in2[39] * t13 * t129 * 2.0;
  t33 = in2[32] * in2[38];
  t135 = t33 * in2[40] * t13 * t129 * 2.0;
  t136 = t59 - t56 * t129;
  t138 = t59 - t57 * t129;
  t77 = in2[33] * in2[38];
  t139 = t77 * in2[41] * t13 * t129 * 2.0;
  t141_tmp = in2[33] * in2[39];
  t141 = t141_tmp * in2[41] * t13 * t129 * 2.0;
  t6 = in1[4] / 2.0;
  t143 = muDoubleScalarCos(t6);
  t144 = muDoubleScalarSin(t6);
  t147 = t143 * 0.333 - t144 / 25.0;
  t150 = t143 / 25.0 + t144 * 0.333;
  t151_tmp = t13 * t20;
  t152 = c_t20_tmp * t29;
  t153 = t23_tmp * t36;
  t154 = t399 * t20;
  t155_tmp = t401 * t40;
  t156 = t402 * t44;
  t161_tmp = t86_tmp * t40;
  t162_tmp = t13 * t40;
  t168 = (((((((t91 + t92) + t162_tmp) + c_t20_tmp * t93) + t20_tmp * t48) +
            t23_tmp * t96) + b_t20_tmp * t99) + t398 * t23) - t400 * t40;
  t172_tmp = t35_tmp * t20;
  t173 = (((((((-t107_tmp + t31) + b_t20_tmp * t78) + t23_tmp * t28) + t112_tmp *
             t23) + t172_tmp) - t20_tmp * t34) - c_t20_tmp * t50) - t398 * t40;
  t174 = t8 + t125_tmp;
  t175 = t124 - t127_tmp;
  t176 = ((-t9 - t10) + t12_tmp) + t126_tmp;
  t177_tmp = b_t20_tmp * t26;
  b_t177_tmp = t20_tmp * t32;
  t177 = (((((((t114 - t151_tmp) + t152) + t153) + t154) - t155_tmp) + t156) -
          b_t177_tmp) - t177_tmp;
  t196_tmp = t13 * t44;
  t179_tmp = (((t118 + t23_tmp * t79) + t20_tmp * t83) + t81_tmp * t44) + t402 *
    t20;
  b_t179_tmp = c_t20_tmp * t75;
  c_t179_tmp = b_t20_tmp * t81;
  t179 = (((t179_tmp - t161_tmp) - t196_tmp) - b_t179_tmp) - c_t179_tmp;
  st.site = &n_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t193 = muDoubleScalarPower(muDoubleScalarAbs(((((((((t177 * in2[143] + t179 *
    in2[144]) + t168 * in2[145]) + t173 * in2[146]) + t175 * in2[142]) + t174 *
    in2[148]) + t176 * in2[147]) - t174 * in2[141]) - t175 * in2[149]) - t176 *
    in2[140]), in1[1] - 1.0);
  t202 = b_t20_tmp * t32;
  t203 = c_t20_tmp * t36;
  t204 = t399 * t23;
  t205 = t401 * t44;
  t206 = t23_tmp * t75;
  t207 = c_t20_tmp * t79;
  t208 = t81_tmp * t40;
  t209_tmp = t402 * t23;
  t210 = c_t20_tmp * t96;
  t211 = t20_tmp * t99;
  t212 = t400 * t44;
  t213 = t401 * t23;
  t214_tmp = t398 * t20;
  t220 = (((((((t114 + t115) + t151_tmp) + t20_tmp * t78) + b_t20_tmp * t34) +
            c_t20_tmp * t28) + t23_tmp * t50) + t403 * t40) - t112_tmp * t20;
  t221 = t11 + t128_tmp;
  t222 = t8 - t125_tmp;
  t223_tmp = t9 - t10;
  t223 = (t223_tmp - t12_tmp) + t126_tmp;
  t224_tmp = t20_tmp * t26;
  b_t224_tmp = t23_tmp * t29;
  t224 = (((((((t87 - t107_tmp) - t172_tmp) + t202) + t203) + t204) + t205) -
          t224_tmp) - b_t224_tmp;
  t226_tmp = t20_tmp * t81;
  b_t226_tmp = b_t20_tmp * t83;
  c_t226_tmp = t403 * t20;
  t226 = (((((((t92 - t162_tmp) + t206) + t207) + t208) + t209_tmp) - t226_tmp)
          - b_t226_tmp) - c_t226_tmp;
  t228_tmp = t23_tmp * t93;
  b_t228_tmp = b_t20_tmp * t48;
  t228 = (((((((t161_tmp - t196_tmp) + t210) + t211) + t212) + t213) - t214_tmp)
          - t228_tmp) - b_t228_tmp;
  st.site = &o_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t237 = muDoubleScalarPower(muDoubleScalarAbs(((((((((t224 * in2[143] + t226 *
    in2[144]) + t228 * in2[145]) + t220 * in2[146]) + t222 * in2[140]) + t221 *
    in2[149]) + t223 * in2[148]) - t221 * in2[142]) - t222 * in2[147]) - t223 *
    in2[141]), in1[1] - 1.0);
  t248 = t23_tmp * t26;
  t249 = b_t20_tmp * t36;
  t250 = t399 * t40;
  t251 = t35_tmp * t44;
  t257 = (((((((t87 + t107_tmp) + t31) + t20_tmp * t75) + b_t20_tmp * t79) +
            t23_tmp * t81) + c_t20_tmp * t83) + t86_tmp * t20) - t81_tmp * t23;
  t258 = c_t20_tmp * t48;
  t259 = b_t20_tmp * t96;
  t260 = t400 * t20;
  t261 = b_t20_tmp * t28;
  t262 = t20_tmp * t50;
  t263 = t112_tmp * t44;
  t264 = t35_tmp * t40;
  t265 = t124 + t127_tmp;
  t266 = t11 - t128_tmp;
  t267_tmp = -t9 + t10;
  t267 = (t267_tmp - t12_tmp) + t126_tmp;
  t268_tmp = t20_tmp * t29;
  b_t268_tmp = c_t20_tmp * t32;
  t268 = (((((((t91 - t162_tmp) - t209_tmp) + t248) + t249) + t250) + t251) -
          t268_tmp) - b_t268_tmp;
  t272_tmp = t20_tmp * t93;
  b_t272_tmp = t23_tmp * t99;
  c_t272_tmp = t86_tmp * t23;
  t272 = (((((((t115 - t151_tmp) + t155_tmp) + t258) + t259) + t260) - t272_tmp)
          - b_t272_tmp) - c_t272_tmp;
  t274_tmp = t23_tmp * t78;
  t75 = c_t20_tmp * t34;
  t274 = (((((((-t118 - t196_tmp) + t214_tmp) + t261) + t262) + t263) + t264) -
          t274_tmp) - t75;
  st.site = &p_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t281 = muDoubleScalarPower(muDoubleScalarAbs(((((((((t268 * in2[143] + t257 *
    in2[144]) + t272 * in2[145]) + t274 * in2[146]) + t266 * in2[141]) + t265 *
    in2[147]) + t267 * in2[149]) - t265 * in2[140]) - t266 * in2[148]) - t267 *
    in2[142]), in1[1] - 1.0);
  t292_tmp = t13 * t60 * 2.0;
  t79 = t399 * t60 * 2.0;
  t26 = t23_tmp * t64 * 2.0;
  t99 = in2[32] * t2 * t65 * 2.0;
  t296_tmp = t401 * t70 * 2.0;
  t93 = t402 * t60 * 2.0;
  t29 = t86_tmp * t70 * 2.0;
  t299_tmp = t13 * t70 * 2.0;
  t32 = t398 * t62 * 2.0;
  t304_tmp = t35_tmp * t60 * 2.0;
  t326_tmp = t403 * t67 * 2.0;
  t305 = (((((-t119_tmp + t112_tmp * t62 * 2.0) + c_t20_tmp * t120 * 2.0) + in2
            [33] * t5 * t65 * 2.0) + t304_tmp) - t326_tmp) - t398 * t70 * 2.0;
  t306_tmp = t134_tmp * in2[40] * t13 * t129 * 2.0;
  t307 = t20_tmp * t132 * 2.0;
  t308 = t33 * in2[39] * t13 * t129 * 2.0;
  t50 = in2[34] * in2[39];
  t309 = t50 * in2[40] * t13 * t129 * 2.0;
  t6 = in2[31] * in2[39];
  t334_tmp = t6 * in2[40] * t13 * t129 * 2.0;
  t312 = ((t135 + b_t20_tmp * t136 * 2.0) + in2[33] * in2[40] * in2[41] * t13 *
          t129 * 2.0) - t334_tmp;
  t59 = t33 * in2[41] * t13 * t129 * 2.0;
  t57 = t402 * t67 * 2.0;
  t314 = (((((t121 - t292_tmp) + t79) + t26) + t99) - t296_tmp) - t57;
  t424 = in2[31] * t3 * t65 * 2.0;
  t421 = t20_tmp * t88 * 2.0;
  t416 = t81_tmp * t67 * 2.0;
  t320 = (((((-t104 - t123) - t93) + t29) + t416) + t421) + t424;
  t415 = t86_tmp * t67 * 2.0;
  t409 = in2[34] * t4 * t65 * 2.0;
  t96 = b_t20_tmp * t105 * 2.0;
  t83 = t400 * t70 * 2.0;
  t325 = (((((-t103 - t299_tmp) - t32) + t83) + t96) + t409) + t415;
  t331_tmp = in2[31] * in2[38];
  t81 = t23_tmp * t130 * 2.0;
  t36 = t331_tmp * in2[39] * t13 * t129 * 2.0;
  t331 = ((-t139 + t306_tmp) + t81) + t36;
  t332 = ((t141 + t307) + t308) - t309;
  t337_tmp = t6 * in2[41] * t13 * t129 * 2.0;
  t27 = c_t20_tmp * t138 * 2.0;
  t74_tmp = in2[34] * in2[40] * in2[41] * t13 * t129 * 2.0;
  t339 = ((-t59 + t27) + t337_tmp) + t74_tmp;
  st.site = &q_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t342 = muDoubleScalarPower(muDoubleScalarAbs(((((((t314 * in2[143] + t305 *
    in2[146]) + t332 * in2[151]) + t312 * in2[152]) - t320 * in2[144]) - t325 *
    in2[145]) - t331 * in2[150]) - t339 * in2[153]), in1[1] - 1.0);
  t347 = t399 * t62 * 2.0;
  t348 = c_t20_tmp * t64 * 2.0;
  t58 = in2[33] * t2 * t65 * 2.0;
  t54 = t401 * t62 * 2.0;
  t351_tmp = t398 * t60 * 2.0;
  t55 = t81_tmp * t70 * 2.0;
  t353 = b_t20_tmp * t88 * 2.0;
  t56 = in2[34] * t3 * t65 * 2.0;
  t355_tmp = t402 * t62 * 2.0;
  t16 = t403 * t70 * 2.0;
  t357_tmp = t77 * in2[39] * t13 * t129 * 2.0;
  t35 = t20_tmp * t136 * 2.0;
  t25 = t77 * in2[40] * t13 * t129 * 2.0;
  t24 = in2[32] * in2[40] * in2[41] * t13 * t129 * 2.0;
  t386_tmp = in2[31] * in2[40] * in2[41] * t13 * t129 * 2.0;
  t363 = ((t139 + t23_tmp * t138 * 2.0) + t50 * in2[41] * t13 * t129 * 2.0) -
    t386_tmp;
  t80 = t401 * t67 * 2.0;
  t364 = (((((t90 - t119_tmp) - t304_tmp) + t347) + t348) + t58) - t80;
  t82 = in2[31] * t4 * t65 * 2.0;
  t30 = t20_tmp * t105 * 2.0;
  t52 = t400 * t67 * 2.0;
  t370 = (((((-t104 - t29) - t54) + t351_tmp) + t52) + t30) + t82;
  t78 = t403 * t60 * 2.0;
  t371 = (((((-t299_tmp - t415) + t55) + t353) + t56) + t355_tmp) - t78;
  t376_tmp = t398 * t67 * 2.0;
  t50 = in2[32] * t5 * t65 * 2.0;
  t28 = t23_tmp * t120 * 2.0;
  t33 = t112_tmp * t60 * 2.0;
  t377 = (((((-t121 - t292_tmp) - t16) + t33) + t28) + t50) + t376_tmp;
  t77 = c_t20_tmp * t130 * 2.0;
  t31 = t331_tmp * in2[40] * t13 * t129 * 2.0;
  t380 = ((-t134 + t59) + t77) + t31;
  t6 = in2[32] * in2[39];
  t48 = b_t20_tmp * t132 * 2.0;
  t34 = t6 * in2[41] * t13 * t129 * 2.0;
  t383 = ((t334_tmp - t357_tmp) + t48) + t34;
  t384 = ((t309 + t35) + t25) - t24;
  st.site = &r_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t390 = muDoubleScalarPower(muDoubleScalarAbs(((((((t364 * in2[143] + t371 *
    in2[144]) + t384 * in2[152]) + t363 * in2[153]) - t370 * in2[145]) - t377 *
    in2[146]) - t380 * in2[150]) - t383 * in2[151]), in1[1] - 1.0);
  t396 = t399 * t70 * 2.0;
  t64 = b_t20_tmp * t64 * 2.0;
  t398 = in2[34] * t2 * t65 * 2.0;
  t399 = t86_tmp * t60 * 2.0;
  t400 = t400 * t60 * 2.0;
  t401 = t23_tmp * t105 * 2.0;
  t402 = in2[32] * t4 * t65 * 2.0;
  t403 = t35_tmp * t70 * 2.0;
  t105 = c_t20_tmp * t132 * 2.0;
  t132 = t6 * in2[40] * t13 * t129 * 2.0;
  t138 = ((-t141 + t24) + t20_tmp * t138 * 2.0) + t134_tmp * in2[41] * t13 *
    t129 * 2.0;
  memset(&out1[0], 0, 28U * sizeof(real_T));
  out1[28] = ((t9 + t10) - t126_tmp) - t12_tmp;
  out1[29] = -t8 - t125_tmp;
  out1[30] = t124 - in2[32] * in2[34] * t7 * 2.0;
  out1[31] = (((((((t114 + t152) + t153) + t154) + t156) - t151_tmp) - t177_tmp)
              - b_t177_tmp) - t155_tmp;
  out1[32] = (((t179_tmp - t196_tmp) - b_t179_tmp) - c_t179_tmp) - t161_tmp;
  out1[33] = t168;
  out1[34] = t173;
  out1[35] = t176;
  out1[36] = t174;
  out1[37] = -t124 + t127_tmp;
  memset(&out1[38], 0, 96U * sizeof(real_T));
  out1[134] = t8 - in2[32] * in2[33] * t7 * 2.0;
  out1[135] = (t267_tmp + t12_tmp) - t126_tmp;
  out1[136] = -t11 - t128_tmp;
  out1[137] = (((((((t87 + t202) + t203) + t204) + t205) - t107_tmp) - t224_tmp)
               - b_t224_tmp) - t172_tmp;
  out1[138] = (((((((t92 + t206) + t207) + t208) + t209_tmp) - t162_tmp) -
                t226_tmp) - b_t226_tmp) - c_t226_tmp;
  out1[139] = (((((((t161_tmp + t210) + t211) + t212) + t213) - t196_tmp) -
                t228_tmp) - b_t228_tmp) - t214_tmp;
  out1[140] = t220;
  out1[141] = -t8 + t125_tmp;
  out1[142] = t223;
  out1[143] = t221;
  memset(&out1[144], 0, 96U * sizeof(real_T));
  out1[240] = t124_tmp * -2.0 - t127_tmp;
  out1[241] = t11 - in2[33] * in2[34] * t7 * 2.0;
  out1[242] = (t223_tmp + t12_tmp) - t126_tmp;
  out1[243] = (((((((t91 + t248) + t249) + t250) + t251) - t162_tmp) - t268_tmp)
               - b_t268_tmp) - t209_tmp;
  out1[244] = t257;
  out1[245] = (((((((t115 + t155_tmp) + t258) + t259) + t260) - t151_tmp) -
                t272_tmp) - b_t272_tmp) - c_t272_tmp;
  out1[246] = (((((((-t118 + t214_tmp) + t261) + t262) + t263) + t264) -
                t196_tmp) - t274_tmp) - t75;
  out1[247] = t265;
  out1[248] = -t11 + t128_tmp;
  out1[249] = t267;
  memset(&out1[250], 0, 99U * sizeof(real_T));
  out1[349] = (((((t121 + t79) + t26) + t99) - t292_tmp) - t57) - t296_tmp;
  out1[350] = (((((t104 + t123) + t93) - t424) - t421) - t416) - t29;
  out1[351] = (((((t103 + t299_tmp) + t32) - t409) - t96) - t83) - t415;
  out1[352] = t305;
  out1[353] = 0.0;
  out1[354] = 0.0;
  out1[355] = 0.0;
  out1[356] = ((t139 - t81) - t36) - t306_tmp;
  out1[357] = ((t141 + t307) + t308) - in2[34] * in2[39] * in2[40] * t13 * t129 *
    2.0;
  out1[358] = t312;
  out1[359] = ((t59 - t27) - t337_tmp) - t74_tmp;
  memset(&out1[360], 0, 95U * sizeof(real_T));
  out1[455] = (((((t90 + t347) + t348) + t58) - t119_tmp) - t304_tmp) - t80;
  out1[456] = (((((t55 + t353) + t56) + t355_tmp) - t299_tmp) - t78) - t415;
  out1[457] = (((((t104 + t29) + t54) - t82) - t30) - t52) - t351_tmp;
  out1[458] = (((((t121 + t292_tmp) + t16) - t50) - t28) - t33) - t376_tmp;
  out1[459] = 0.0;
  out1[460] = 0.0;
  out1[461] = 0.0;
  out1[462] = ((t134 - t77) - t31) - t59;
  out1[463] = ((t357_tmp - t48) - t334_tmp) - t34;
  out1[464] = ((t309 + t35) + t25) - in2[32] * in2[40] * in2[41] * t13 * t129 *
    2.0;
  out1[465] = t363;
  memset(&out1[466], 0, 95U * sizeof(real_T));
  t82 = t35_tmp * t67 * 2.0;
  out1[561] = (((((t103 + t396) + t64) + t398) - t299_tmp) - t355_tmp) - t82;
  t30 = t81_tmp * t62 * 2.0;
  t80 = c_t20_tmp * t88 * 2.0;
  t48 = in2[33] * t3 * t65 * 2.0;
  out1[562] = (((((t90 + t119_tmp) + t399) - t48) - t80) - t30) - t326_tmp;
  t34 = t86_tmp * t62 * 2.0;
  out1[563] = (((((t296_tmp + t400) + t401) + t402) - t292_tmp) - t34) -
    t376_tmp;
  t78 = t112_tmp * t67 * 2.0;
  t31 = t20_tmp * t120 * 2.0;
  t28 = in2[31] * t5 * t65 * 2.0;
  out1[564] = (((((t104 - t123) + t351_tmp) + t403) - t28) - t31) - t78;
  out1[565] = 0.0;
  out1[566] = 0.0;
  out1[567] = 0.0;
  t33 = b_t20_tmp * t130 * 2.0;
  t50 = t331_tmp * in2[41] * t13 * t129 * 2.0;
  out1[568] = ((t135 - t33) - t50) - t357_tmp;
  out1[569] = ((t134 + t105) + t132) - t337_tmp;
  t77 = t23_tmp * t136 * 2.0;
  t6 = t141_tmp * in2[40] * t13 * t129 * 2.0;
  out1[570] = ((t306_tmp - t77) - t386_tmp) - t6;
  out1[571] = t138;
  memset(&out1[572], 0, sizeof(real_T) << 6);
  t409 = (((((t103 - t299_tmp) - t355_tmp) + t396) + t64) + t398) - t82;
  t415 = (((((-t90 - t119_tmp) + t326_tmp) - t399) + t30) + t80) + t48;
  t416 = (((((-t292_tmp + t296_tmp) - t376_tmp) + t400) + t401) + t402) - t34;
  t421 = (((((-t104 + t123) - t351_tmp) - t403) + t78) + t31) + t28;
  t424 = ((-t135 + t357_tmp) + t33) + t50;
  t353 = ((t134 - t337_tmp) + t105) + t132;
  t29 = ((-t306_tmp + t386_tmp) + t77) + t6;
  st.site = &s_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t32 = muDoubleScalarPower(muDoubleScalarAbs(((((((t409 * in2[143] + t416 *
    in2[145]) + t353 * in2[151]) + t138 * in2[153]) - t415 * in2[144]) - t421 *
    in2[146]) - t424 * in2[150]) - t29 * in2[152]), in1[1] - 1.0);
  t50 = t144 * t150;
  st.site = &t_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t28 = t143 * t143 * 0.333;
  st.site = &u_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t33 = t144 * t144;
  out2[0] = in1[0] * ((((((t143 * t144 * -0.666 + t144 * t147) + t143 * t150) +
    t20_tmp * t20) + b_t20_tmp * t23) - c_t20_tmp * t40) + t23_tmp * t44) *
    0.00026666666666666668;
  out2[1] = in1[0] * (((t20_tmp * t23 - b_t20_tmp * t20) + t23_tmp * t40) +
                      c_t20_tmp * t44) * 0.00026666666666666668;
  t6 = t143 * t147;
  out2[2] = in1[0] * (((((((t50 + t28) - t33 * 0.333) - t6) + c_t20_tmp * t20) -
                        t23_tmp * t23) + t20_tmp * t40) + b_t20_tmp * t44) *
    0.0008;
  out2[3] = in1[0] * (((t20_tmp * t60 * 2.0 + b_t20_tmp * t62 * 2.0) - t23_tmp *
                       t67 * 2.0) - c_t20_tmp * t70 * 2.0) *
    4.2666666666666668E-11;
  out2[4] = in1[0] * (((t20_tmp * t62 * 2.0 - b_t20_tmp * t60 * 2.0) - c_t20_tmp
                       * t67 * 2.0) + t23_tmp * t70 * 2.0) *
    1.421066666666666E-8;
  out2[5] = in1[0] * (((c_t20_tmp * t60 * 2.0 - t23_tmp * t62 * 2.0) + t20_tmp *
                       t70 * 2.0) - b_t20_tmp * t67 * 2.0) * 4.75111111111111E-9;
  t80 = in1[2] * t174 * t193;
  t82 = in1[2] * t176 * t193;
  t30 = in1[2] * t175 * t193;
  t52 = -in1[2] * t168 * t193;
  out3[0] = ((((((((t52 * in2[145] + t80 * in2[141]) + t82 * in2[140]) - t30 *
                  in2[142]) - in1[2] * t173 * t193 * in2[146]) - in1[2] * t177 *
                t193 * in2[143]) - t80 * in2[148]) - t82 * in2[147]) - in1[2] *
             t179 * t193 * in2[144]) + t30 * in2[149];
  t24 = in1[2] * t221 * t237;
  t25 = in1[2] * t223 * t237;
  t16 = -in1[2] * t222 * t237;
  t35 = in1[2] * t222 * t237;
  out3[1] = ((((((((t16 * in2[140] + t24 * in2[142]) + t25 * in2[141]) - in1[2] *
                  t220 * t237 * in2[146]) - in1[2] * t224 * t237 * in2[143]) +
                t35 * in2[147]) - t24 * in2[149]) - in1[2] * t226 * t237 * in2
              [144]) - t25 * in2[148]) - in1[2] * t228 * t237 * in2[145];
  t27 = in1[2] * t265 * t281;
  t74_tmp = in1[2] * t266 * t281;
  t347 = in1[2] * t267 * t281;
  t348 = -in1[2] * t257 * t281;
  out3[2] = ((((((((t348 * in2[144] + t27 * in2[140]) - t74_tmp * in2[141]) +
                  t347 * in2[142]) - in1[2] * t268 * t281 * in2[143]) - t27 *
                in2[147]) + t74_tmp * in2[148]) - t347 * in2[149]) - in1[2] *
             t272 * t281 * in2[145]) - in1[2] * t274 * t281 * in2[146];
  t58 = in1[3] * t320 * t342;
  t54 = in1[3] * t325 * t342;
  t55 = -in1[3] * t305 * t342;
  t56 = in1[3] * t331 * t342;
  t59 = in1[3] * t339 * t342;
  out3[3] = ((((((t55 * in2[146] - in1[3] * t314 * t342 * in2[143]) - in1[3] *
                 t312 * t342 * in2[152]) + t58 * in2[144]) + t54 * in2[145]) +
              t56 * in2[150]) - in1[3] * t332 * t342 * in2[151]) + t59 * in2[153];
  t57 = -in1[3] * t364 * t390;
  t96 = in1[3] * t370 * t390;
  t83 = in1[3] * t377 * t390;
  t81 = in1[3] * t380 * t390;
  t36 = in1[3] * t383 * t390;
  out3[4] = ((((((t57 * in2[143] + t96 * in2[145]) - in1[3] * t371 * t390 * in2
                 [144]) - in1[3] * t363 * t390 * in2[153]) + t83 * in2[146]) +
              t81 * in2[150]) + t36 * in2[151]) - in1[3] * t384 * t390 * in2[152];
  t75 = -in1[3] * t409 * t32;
  t79 = in1[3] * t415 * t32;
  t26 = in1[3] * t421 * t32;
  t99 = in1[3] * t424 * t32;
  t93 = in1[3] * t29 * t32;
  out3[5] = ((((((t75 * in2[143] + t79 * in2[144]) - in1[3] * t138 * t32 * in2
                 [153]) - in1[3] * t416 * t32 * in2[145]) + t26 * in2[146]) +
              t99 * in2[150]) - in1[3] * t353 * t32 * in2[151]) + t93 * in2[152];
  for (i = 0; i < 6; i++) {
    out4[i] = 0.0;
  }

  st.site = &v_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  st.site = &v_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  st.site = &v_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t78 = (t14 * t14 + t15 * t15) + t17 * t17;
  st.site = &v_emlrtRSI;
  b_sqrt(&st, &t78);
  *out5 = (((-t50 - t28) + t33 * 0.333) + t78) + t6;
  t78 = in1[0] * t175 * 0.00026666666666666668;
  t48 = in1[0] * t222 * 0.00026666666666666668;
  t34 = in1[0] * t266 * 0.0008;
  memset(&out6[0], 0, 168U * sizeof(real_T));
  t31 = in1[0] * t176;
  out6[168] = t31 * -0.00026666666666666668;
  out6[169] = t48;
  t77 = in1[0] * t265;
  out6[170] = t77 * -0.0008;
  out6[171] = 0.0;
  out6[172] = 0.0;
  out6[173] = 0.0;
  t33 = in1[0] * t174;
  out6[174] = t33 * -0.00026666666666666668;
  t28 = in1[0] * t223;
  out6[175] = t28 * -0.00026666666666666668;
  out6[176] = t34;
  out6[177] = 0.0;
  out6[178] = 0.0;
  out6[179] = 0.0;
  out6[180] = t78;
  t50 = in1[0] * t221;
  out6[181] = t50 * -0.00026666666666666668;
  t6 = in1[0] * t267;
  out6[182] = t6 * -0.0008;
  out6[183] = 0.0;
  out6[184] = 0.0;
  out6[185] = 0.0;
  out6[186] = in1[0] * t177 * 0.00026666666666666668;
  out6[187] = in1[0] * t224 * 0.00026666666666666668;
  out6[188] = in1[0] * t268 * 0.0008;
  out6[189] = in1[0] * t314 * 4.2666666666666668E-11;
  out6[190] = in1[0] * t364 * 1.421066666666666E-8;
  out6[191] = in1[0] * t409 * 4.75111111111111E-9;
  out6[192] = in1[0] * t179 * 0.00026666666666666668;
  out6[193] = in1[0] * t226 * 0.00026666666666666668;
  out6[194] = in1[0] * t257 * 0.0008;
  out6[195] = in1[0] * t320 * -4.2666666666666668E-11;
  out6[196] = in1[0] * t371 * 1.421066666666666E-8;
  out6[197] = in1[0] * t415 * -4.75111111111111E-9;
  out6[198] = in1[0] * t168 * 0.00026666666666666668;
  out6[199] = in1[0] * t228 * 0.00026666666666666668;
  out6[200] = in1[0] * t272 * 0.0008;
  out6[201] = in1[0] * t325 * -4.2666666666666668E-11;
  out6[202] = in1[0] * t370 * -1.421066666666666E-8;
  out6[203] = in1[0] * t416 * 4.75111111111111E-9;
  out6[204] = in1[0] * t173 * 0.00026666666666666668;
  out6[205] = in1[0] * t220 * 0.00026666666666666668;
  out6[206] = in1[0] * t274 * 0.0008;
  out6[207] = in1[0] * t305 * 4.2666666666666668E-11;
  out6[208] = in1[0] * t377 * -1.421066666666666E-8;
  out6[209] = in1[0] * t421 * -4.75111111111111E-9;
  out6[210] = t31 * 0.00026666666666666668;
  out6[211] = -t48;
  out6[212] = t77 * 0.0008;
  out6[213] = 0.0;
  out6[214] = 0.0;
  out6[215] = 0.0;
  out6[216] = t33 * 0.00026666666666666668;
  out6[217] = t28 * 0.00026666666666666668;
  out6[218] = -t34;
  out6[219] = 0.0;
  out6[220] = 0.0;
  out6[221] = 0.0;
  out6[222] = -t78;
  out6[223] = t50 * 0.00026666666666666668;
  out6[224] = t6 * 0.0008;
  out6[225] = 0.0;
  out6[226] = 0.0;
  out6[227] = 0.0;
  out6[228] = 0.0;
  out6[229] = 0.0;
  out6[230] = 0.0;
  out6[231] = in1[0] * t331 * -4.2666666666666668E-11;
  out6[232] = in1[0] * t380 * -1.421066666666666E-8;
  out6[233] = in1[0] * t424 * -4.75111111111111E-9;
  out6[234] = 0.0;
  out6[235] = 0.0;
  out6[236] = 0.0;
  out6[237] = in1[0] * t332 * 4.2666666666666668E-11;
  out6[238] = in1[0] * t383 * -1.421066666666666E-8;
  out6[239] = in1[0] * t353 * 4.75111111111111E-9;
  out6[240] = 0.0;
  out6[241] = 0.0;
  out6[242] = 0.0;
  out6[243] = in1[0] * t312 * 4.2666666666666668E-11;
  out6[244] = in1[0] * t384 * 1.421066666666666E-8;
  out6[245] = in1[0] * t29 * -4.75111111111111E-9;
  out6[246] = 0.0;
  out6[247] = 0.0;
  out6[248] = 0.0;
  out6[249] = in1[0] * t339 * -4.2666666666666668E-11;
  out6[250] = in1[0] * t363 * 1.421066666666666E-8;
  out6[251] = in1[0] * t138 * 4.75111111111111E-9;
  memset(&out6[252], 0, 384U * sizeof(real_T));
  memset(&out7[0], 0, 168U * sizeof(real_T));
  out7[168] = t82;
  out7[169] = t16;
  out7[170] = t27;
  out7[171] = 0.0;
  out7[172] = 0.0;
  out7[173] = 0.0;
  out7[174] = t80;
  out7[175] = t25;
  out7[176] = -in1[2] * t266 * t281;
  out7[177] = 0.0;
  out7[178] = 0.0;
  out7[179] = 0.0;
  out7[180] = -in1[2] * t175 * t193;
  out7[181] = t24;
  out7[182] = t347;
  out7[183] = 0.0;
  out7[184] = 0.0;
  out7[185] = 0.0;
  out7[186] = -in1[2] * t177 * t193;
  out7[187] = -in1[2] * t224 * t237;
  out7[188] = -in1[2] * t268 * t281;
  out7[189] = -in1[3] * t314 * t342;
  out7[190] = t57;
  out7[191] = t75;
  out7[192] = -in1[2] * t179 * t193;
  out7[193] = -in1[2] * t226 * t237;
  out7[194] = t348;
  out7[195] = t58;
  out7[196] = -in1[3] * t371 * t390;
  out7[197] = t79;
  out7[198] = t52;
  out7[199] = -in1[2] * t228 * t237;
  out7[200] = -in1[2] * t272 * t281;
  out7[201] = t54;
  out7[202] = t96;
  out7[203] = -in1[3] * t416 * t32;
  out7[204] = -in1[2] * t173 * t193;
  out7[205] = -in1[2] * t220 * t237;
  out7[206] = -in1[2] * t274 * t281;
  out7[207] = t55;
  out7[208] = t83;
  out7[209] = t26;
  out7[210] = -t82;
  out7[211] = t35;
  out7[212] = -t27;
  out7[213] = 0.0;
  out7[214] = 0.0;
  out7[215] = 0.0;
  out7[216] = -t80;
  out7[217] = -t25;
  out7[218] = t74_tmp;
  out7[219] = 0.0;
  out7[220] = 0.0;
  out7[221] = 0.0;
  out7[222] = t30;
  out7[223] = -t24;
  out7[224] = -t347;
  out7[225] = 0.0;
  out7[226] = 0.0;
  out7[227] = 0.0;
  out7[228] = 0.0;
  out7[229] = 0.0;
  out7[230] = 0.0;
  out7[231] = t56;
  out7[232] = t81;
  out7[233] = t99;
  out7[234] = 0.0;
  out7[235] = 0.0;
  out7[236] = 0.0;
  out7[237] = -in1[3] * t332 * t342;
  out7[238] = t36;
  out7[239] = -in1[3] * t353 * t32;
  out7[240] = 0.0;
  out7[241] = 0.0;
  out7[242] = 0.0;
  out7[243] = -in1[3] * t312 * t342;
  out7[244] = -in1[3] * t384 * t390;
  out7[245] = t93;
  out7[246] = 0.0;
  out7[247] = 0.0;
  out7[248] = 0.0;
  out7[249] = t59;
  out7[250] = -in1[3] * t363 * t390;
  out7[251] = -in1[3] * t138 * t32;
  memset(&out7[252], 0, 384U * sizeof(real_T));
  *out8 = 1.0;
}

/* End of code generation (sprdmpF116.c) */
