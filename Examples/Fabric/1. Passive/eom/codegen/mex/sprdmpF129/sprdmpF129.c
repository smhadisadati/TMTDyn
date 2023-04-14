/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sprdmpF129.c
 *
 * Code generation for function 'sprdmpF129'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "sprdmpF129.h"
#include "sqrt.h"
#include "error.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 41,    /* lineNo */
  "sprdmpF129",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF129.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 42,  /* lineNo */
  "sprdmpF129",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF129.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 43,  /* lineNo */
  "sprdmpF129",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF129.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 44,  /* lineNo */
  "sprdmpF129",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF129.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 52,  /* lineNo */
  "sprdmpF129",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF129.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 55,  /* lineNo */
  "sprdmpF129",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF129.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 93,  /* lineNo */
  "sprdmpF129",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF129.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 94,  /* lineNo */
  "sprdmpF129",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF129.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 95,  /* lineNo */
  "sprdmpF129",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF129.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 96,  /* lineNo */
  "sprdmpF129",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF129.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 98,  /* lineNo */
  "sprdmpF129",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF129.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 106, /* lineNo */
  "sprdmpF129",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF129.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 168, /* lineNo */
  "sprdmpF129",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF129.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 184, /* lineNo */
  "sprdmpF129",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF129.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 185, /* lineNo */
  "sprdmpF129",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF129.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 236, /* lineNo */
  "sprdmpF129",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF129.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 282, /* lineNo */
  "sprdmpF129",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF129.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 326, /* lineNo */
  "sprdmpF129",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF129.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 381, /* lineNo */
  "sprdmpF129",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF129.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 430, /* lineNo */
  "sprdmpF129",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF129.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 478, /* lineNo */
  "sprdmpF129",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF129.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 485, /* lineNo */
  "sprdmpF129",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF129.m"/* pathName */
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
void sprdmpF129(const emlrtStack *sp, const real_T in1[6], const real_T in2[224],
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
  real_T t398;
  real_T t50;
  real_T t26;
  real_T t27;
  real_T t28;
  real_T t346;
  real_T t48;
  real_T t395;
  real_T t29;
  real_T t30;
  real_T t397;
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
  real_T t343;
  real_T t75;
  real_T t345;
  real_T t399;
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
  real_T t394;
  real_T t96;
  real_T t396;
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
  real_T t142;
  real_T t144;
  real_T t145;
  real_T t146;
  real_T t147_tmp;
  real_T t148;
  real_T t149;
  real_T t150;
  real_T t151_tmp;
  real_T t152;
  real_T t157_tmp;
  real_T t158_tmp;
  real_T t164;
  real_T t168_tmp;
  real_T t169;
  real_T t170;
  real_T t171;
  real_T t172;
  real_T t173_tmp;
  real_T b_t173_tmp;
  real_T t173;
  real_T t192_tmp;
  real_T t175_tmp;
  real_T b_t175_tmp;
  real_T c_t175_tmp;
  real_T t175;
  real_T t189;
  real_T t198;
  real_T t199;
  real_T t200;
  real_T t201;
  real_T t202;
  real_T t203;
  real_T t204;
  real_T t205_tmp;
  real_T t206;
  real_T t207;
  real_T t208;
  real_T t209;
  real_T t210_tmp;
  real_T t216;
  real_T t217;
  real_T t218;
  real_T t219_tmp;
  real_T t219;
  real_T t220_tmp;
  real_T b_t220_tmp;
  real_T t220;
  real_T t222_tmp;
  real_T b_t222_tmp;
  real_T c_t222_tmp;
  real_T t222;
  real_T t224_tmp;
  real_T b_t224_tmp;
  real_T t224;
  real_T t233;
  real_T t244;
  real_T t245;
  real_T t246;
  real_T t247;
  real_T t253;
  real_T t254;
  real_T t255;
  real_T t256;
  real_T t257;
  real_T t258;
  real_T t259;
  real_T t260;
  real_T t261;
  real_T t262;
  real_T t263_tmp;
  real_T t263;
  real_T t264_tmp;
  real_T b_t264_tmp;
  real_T t264;
  real_T t268_tmp;
  real_T b_t268_tmp;
  real_T c_t268_tmp;
  real_T t268;
  real_T t270_tmp;
  real_T t270;
  real_T t277;
  real_T t288_tmp;
  real_T t292_tmp;
  real_T t295_tmp;
  real_T t322_tmp;
  real_T t301;
  real_T t302_tmp;
  real_T t303;
  real_T t304;
  real_T t305;
  real_T t330_tmp;
  real_T t308;
  real_T t310_tmp;
  real_T t310;
  real_T t316;
  real_T t411;
  real_T t405;
  real_T t321_tmp;
  real_T t321;
  real_T t327_tmp;
  real_T t327;
  real_T t328;
  real_T t333_tmp;
  real_T t420;
  real_T t335;
  real_T t338;
  real_T t344;
  real_T t347_tmp;
  real_T t350;
  real_T t351_tmp;
  real_T t353_tmp;
  real_T t382_tmp;
  real_T t359;
  real_T t360;
  real_T t366;
  real_T t367;
  real_T t372_tmp;
  real_T t373;
  real_T t376;
  real_T t379;
  real_T t380;
  real_T t386;
  real_T t392;
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

  /* SPRDMPF129 */
  /*     [OUT1,OUT2,OUT3,OUT4,OUT5,OUT6,OUT7,OUT8] = SPRDMPF129(IN1,IN2,S) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.2. */
  /*     06-Jul-2019 08:24:35 */
  st.site = &emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t2 = in2[94] * in2[94];
  st.site = &b_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t3 = in2[95] * in2[95];
  st.site = &c_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t4 = in2[96] * in2[96];
  st.site = &d_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t5 = in2[97] * in2[97];
  t6 = ((t2 + t3) + t4) + t5;
  t7 = 1.0 / t6;
  t77 = in2[94] * in2[97];
  t8 = t77 * t7 * 2.0;
  t9 = t4 * t7;
  t10 = t5 * t7;
  t33 = in2[94] * in2[95];
  t11 = t33 * t7 * 2.0;
  t12_tmp = t3 * t7;
  t78 = t6;
  st.site = &e_emlrtRSI;
  b_sqrt(&st, &t78);
  t13 = 1.0 / t78;
  t14 = in2[91] - in2[98];
  t15 = in2[92] - in2[99];
  st.site = &f_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  if (t6 < 0.0) {
    c_st.site = &x_emlrtRSI;
    error(&c_st);
  }

  t16 = 1.0 / muDoubleScalarPower(t6, 1.5);
  t17 = in2[93] - in2[100];
  t20_tmp = in2[94] * t13;
  b_t20_tmp = in2[97] * t13;
  c_t20_tmp = in2[96] * t13;
  t20 = (t20_tmp * t14 + b_t20_tmp * t15) - c_t20_tmp * t17;
  t23_tmp = in2[95] * t13;
  t23 = (t20_tmp * t15 + t23_tmp * t17) - b_t20_tmp * t14;
  t24 = t13 * t15;
  t25 = t77 * t14 * t16;
  t398 = t33 * t16;
  t50 = t398 * t17;
  t26 = ((t24 + t25) - t2 * t15 * t16) - t50;
  t27 = t13 * t17;
  t28 = t33 * t15 * t16;
  t346 = in2[94] * in2[96];
  t48 = t346 * t14 * t16;
  t395 = t2 * t16;
  t29 = ((t27 + t28) - t395 * t17) - t48;
  t30 = t13 * t14;
  t397 = t346 * t16;
  t31 = t397 * t17;
  t52 = t77 * t15 * t16;
  t32 = ((t30 + t31) - t2 * t14 * t16) - t52;
  t33 = t33 * t14 * t16;
  t34 = t346 * t15 * t16;
  t35_tmp = t77 * t16;
  t35 = t35_tmp * t17;
  t36 = (t33 + t34) + t35;
  t40 = (c_t20_tmp * t14 + t20_tmp * t17) - t23_tmp * t15;
  t44 = (t23_tmp * t14 + c_t20_tmp * t15) + b_t20_tmp * t17;
  st.site = &g_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t54 = in2[101] * in2[101];
  st.site = &h_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t55 = in2[102] * in2[102];
  st.site = &i_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t56 = in2[103] * in2[103];
  st.site = &j_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t57 = in2[104] * in2[104];
  t58 = ((t54 + t55) + t56) + t57;
  t78 = t58;
  st.site = &k_emlrtRSI;
  b_sqrt(&st, &t78);
  t59 = 1.0 / t78;
  t60 = t23_tmp - in2[102] * t59;
  t62 = c_t20_tmp - in2[103] * t59;
  t64 = t13 - t395;
  st.site = &l_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t65 = 1.0 / (t6 * t6);
  t67 = t20_tmp - in2[101] * t59;
  t70 = b_t20_tmp - in2[104] * t59;
  t343 = in2[95] * in2[96];
  t6 = t343 * t14 * t16;
  t75 = ((t24 + t50) + t6) - t3 * t15 * t16;
  t77 = t343 * t15 * t16;
  t345 = in2[95] * in2[97];
  t399 = t345 * t16;
  t78 = t399 * t17;
  t79 = ((-t30 + t3 * t14 * t16) + t77) + t78;
  t80 = t345 * t14 * t16;
  t81_tmp = t3 * t16;
  t81 = ((t27 - t28) + t80) - t81_tmp * t17;
  t82 = t345 * t15 * t16;
  t86_tmp = t343 * t16;
  t50 = t86_tmp * t17;
  t83 = (t33 + t82) - t50;
  t87 = t398 * t40;
  t88 = t13 - t81_tmp;
  t90 = t398 * t70 * 2.0;
  t91 = t397 * t20;
  t92 = t86_tmp * t44;
  t93 = ((t30 - t31) + t77) - t4 * t14 * t16;
  t77 = in2[96] * in2[97];
  t394 = t77 * t16;
  t28 = t394 * t17;
  t96 = ((-t24 + t6) + t4 * t15 * t16) + t28;
  t6 = t77 * t15 * t16;
  t396 = t4 * t16;
  t48 = ((t27 + t48) + t6) - t396 * t17;
  t33 = t77 * t14 * t16;
  t99 = (t34 + t50) - t33;
  t103 = t397 * t60 * 2.0;
  t104 = t13 * t67 * 2.0;
  t105 = t13 - t396;
  t107_tmp = t13 * t23;
  t31 = t399 * t44;
  t78 = ((t30 + t52) + t78) - t5 * t14 * t16;
  t34 = ((t24 - t25) + t28) - t5 * t15 * t16;
  t112_tmp = t5 * t16;
  t28 = ((-t27 + t80) + t6) + t112_tmp * t17;
  t50 = (t35 - t82) + t33;
  t114 = t35_tmp * t23;
  t115 = t394 * t44;
  t118 = t399 * t23;
  t119_tmp = t13 * t62 * 2.0;
  t120 = t13 - t112_tmp;
  t121 = t35_tmp * t62 * 2.0;
  t123 = t399 * t62 * 2.0;
  t124_tmp = t346 * t7;
  t124 = t124_tmp * 2.0;
  t125_tmp = t343 * t7 * 2.0;
  t126_tmp = t2 * t7;
  t127_tmp = t345 * t7 * 2.0;
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
  t134_tmp = in2[97] * in2[101];
  t134 = t134_tmp * in2[102] * t13 * t129 * 2.0;
  t33 = in2[95] * in2[101];
  t135 = t33 * in2[103] * t13 * t129 * 2.0;
  t136 = t59 - t56 * t129;
  t138 = t59 - t57 * t129;
  t77 = in2[96] * in2[101];
  t139 = t77 * in2[104] * t13 * t129 * 2.0;
  t141_tmp = in2[96] * in2[102];
  t141 = t141_tmp * in2[104] * t13 * t129 * 2.0;
  t6 = in1[4] / 2.0;
  t142 = muDoubleScalarCos(t6);
  t144 = muDoubleScalarSin(t6);
  st.site = &n_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t145 = t142 * t142;
  st.site = &o_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t146 = t144 * t144;
  t147_tmp = t13 * t20;
  t148 = c_t20_tmp * t29;
  t149 = t23_tmp * t36;
  t150 = t395 * t20;
  t151_tmp = t397 * t40;
  t152 = t398 * t44;
  t157_tmp = t86_tmp * t40;
  t158_tmp = t13 * t40;
  t164 = (((((((t91 + t92) + t158_tmp) + c_t20_tmp * t93) + t20_tmp * t48) +
            t23_tmp * t96) + b_t20_tmp * t99) + t394 * t23) - t396 * t40;
  t168_tmp = t35_tmp * t20;
  t169 = (((((((-t107_tmp + t31) + b_t20_tmp * t78) + t23_tmp * t28) + t112_tmp *
             t23) + t168_tmp) - t20_tmp * t34) - c_t20_tmp * t50) - t394 * t40;
  t170 = t8 + t125_tmp;
  t171 = t124 - t127_tmp;
  t172 = ((-t9 - t10) + t12_tmp) + t126_tmp;
  t173_tmp = b_t20_tmp * t26;
  b_t173_tmp = t20_tmp * t32;
  t173 = (((((((t114 - t147_tmp) + t148) + t149) + t150) - t151_tmp) + t152) -
          b_t173_tmp) - t173_tmp;
  t192_tmp = t13 * t44;
  t175_tmp = (((t118 + t23_tmp * t79) + t20_tmp * t83) + t81_tmp * t44) + t398 *
    t20;
  b_t175_tmp = c_t20_tmp * t75;
  c_t175_tmp = b_t20_tmp * t81;
  t175 = (((t175_tmp - t157_tmp) - t192_tmp) - b_t175_tmp) - c_t175_tmp;
  st.site = &p_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t189 = muDoubleScalarPower(muDoubleScalarAbs(((((((((t173 * in2[206] + t175 *
    in2[207]) + t164 * in2[208]) + t169 * in2[209]) + t171 * in2[205]) + t170 *
    in2[211]) + t172 * in2[210]) - t170 * in2[204]) - t171 * in2[212]) - t172 *
    in2[203]), in1[1] - 1.0);
  t198 = b_t20_tmp * t32;
  t199 = c_t20_tmp * t36;
  t200 = t395 * t23;
  t201 = t397 * t44;
  t202 = t23_tmp * t75;
  t203 = c_t20_tmp * t79;
  t204 = t81_tmp * t40;
  t205_tmp = t398 * t23;
  t206 = c_t20_tmp * t96;
  t207 = t20_tmp * t99;
  t208 = t396 * t44;
  t209 = t397 * t23;
  t210_tmp = t394 * t20;
  t216 = (((((((t114 + t115) + t147_tmp) + t20_tmp * t78) + b_t20_tmp * t34) +
            c_t20_tmp * t28) + t23_tmp * t50) + t399 * t40) - t112_tmp * t20;
  t217 = t11 + t128_tmp;
  t218 = t8 - t125_tmp;
  t219_tmp = t9 - t10;
  t219 = (t219_tmp - t12_tmp) + t126_tmp;
  t220_tmp = t20_tmp * t26;
  b_t220_tmp = t23_tmp * t29;
  t220 = (((((((t87 - t107_tmp) - t168_tmp) + t198) + t199) + t200) + t201) -
          t220_tmp) - b_t220_tmp;
  t222_tmp = t20_tmp * t81;
  b_t222_tmp = b_t20_tmp * t83;
  c_t222_tmp = t399 * t20;
  t222 = (((((((t92 - t158_tmp) + t202) + t203) + t204) + t205_tmp) - t222_tmp)
          - b_t222_tmp) - c_t222_tmp;
  t224_tmp = t23_tmp * t93;
  b_t224_tmp = b_t20_tmp * t48;
  t224 = (((((((t157_tmp - t192_tmp) + t206) + t207) + t208) + t209) - t210_tmp)
          - t224_tmp) - b_t224_tmp;
  st.site = &q_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t233 = muDoubleScalarPower(muDoubleScalarAbs(((((((((t220 * in2[206] + t222 *
    in2[207]) + t224 * in2[208]) + t216 * in2[209]) + t218 * in2[203]) + t217 *
    in2[212]) + t219 * in2[211]) - t217 * in2[205]) - t218 * in2[210]) - t219 *
    in2[204]), in1[1] - 1.0);
  t244 = t23_tmp * t26;
  t245 = b_t20_tmp * t36;
  t246 = t395 * t40;
  t247 = t35_tmp * t44;
  t253 = (((((((t87 + t107_tmp) + t31) + t20_tmp * t75) + b_t20_tmp * t79) +
            t23_tmp * t81) + c_t20_tmp * t83) + t86_tmp * t20) - t81_tmp * t23;
  t254 = c_t20_tmp * t48;
  t255 = b_t20_tmp * t96;
  t256 = t396 * t20;
  t257 = b_t20_tmp * t28;
  t258 = t20_tmp * t50;
  t259 = t112_tmp * t44;
  t260 = t35_tmp * t40;
  t261 = t124 + t127_tmp;
  t262 = t11 - t128_tmp;
  t263_tmp = -t9 + t10;
  t263 = (t263_tmp - t12_tmp) + t126_tmp;
  t264_tmp = t20_tmp * t29;
  b_t264_tmp = c_t20_tmp * t32;
  t264 = (((((((t91 - t158_tmp) - t205_tmp) + t244) + t245) + t246) + t247) -
          t264_tmp) - b_t264_tmp;
  t268_tmp = t20_tmp * t93;
  b_t268_tmp = t23_tmp * t99;
  c_t268_tmp = t86_tmp * t23;
  t268 = (((((((t115 - t147_tmp) + t151_tmp) + t254) + t255) + t256) - t268_tmp)
          - b_t268_tmp) - c_t268_tmp;
  t270_tmp = t23_tmp * t78;
  t36 = c_t20_tmp * t34;
  t270 = (((((((-t118 - t192_tmp) + t210_tmp) + t257) + t258) + t259) + t260) -
          t270_tmp) - t36;
  st.site = &r_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t277 = muDoubleScalarPower(muDoubleScalarAbs(((((((((t264 * in2[206] + t253 *
    in2[207]) + t268 * in2[208]) + t270 * in2[209]) + t262 * in2[204]) + t261 *
    in2[210]) + t263 * in2[212]) - t261 * in2[203]) - t262 * in2[211]) - t263 *
    in2[205]), in1[1] - 1.0);
  t288_tmp = t13 * t60 * 2.0;
  t75 = t395 * t60 * 2.0;
  t79 = t23_tmp * t64 * 2.0;
  t26 = in2[95] * t2 * t65 * 2.0;
  t292_tmp = t397 * t70 * 2.0;
  t99 = t398 * t60 * 2.0;
  t93 = t86_tmp * t70 * 2.0;
  t295_tmp = t13 * t70 * 2.0;
  t29 = t394 * t62 * 2.0;
  t32 = t35_tmp * t60 * 2.0;
  t322_tmp = t399 * t67 * 2.0;
  t301 = (((((-t119_tmp + t112_tmp * t62 * 2.0) + c_t20_tmp * t120 * 2.0) + in2
            [96] * t5 * t65 * 2.0) + t32) - t322_tmp) - t394 * t70 * 2.0;
  t302_tmp = t134_tmp * in2[103] * t13 * t129 * 2.0;
  t303 = t20_tmp * t132 * 2.0;
  t304 = t33 * in2[102] * t13 * t129 * 2.0;
  t50 = in2[97] * in2[102];
  t305 = t50 * in2[103] * t13 * t129 * 2.0;
  t6 = in2[94] * in2[102];
  t330_tmp = t6 * in2[103] * t13 * t129 * 2.0;
  t308 = ((t135 + b_t20_tmp * t136 * 2.0) + in2[96] * in2[103] * in2[104] * t13 *
          t129 * 2.0) - t330_tmp;
  t55 = t33 * in2[104] * t13 * t129 * 2.0;
  t310_tmp = t398 * t67 * 2.0;
  t310 = (((((t121 - t288_tmp) + t75) + t79) + t26) - t292_tmp) - t310_tmp;
  t56 = in2[94] * t3 * t65 * 2.0;
  t59 = t20_tmp * t88 * 2.0;
  t57 = t81_tmp * t67 * 2.0;
  t316 = (((((-t104 - t123) - t99) + t93) + t57) + t59) + t56;
  t411 = t86_tmp * t67 * 2.0;
  t405 = in2[97] * t4 * t65 * 2.0;
  t321_tmp = b_t20_tmp * t105 * 2.0;
  t96 = t396 * t70 * 2.0;
  t321 = (((((-t103 - t295_tmp) - t29) + t96) + t321_tmp) + t405) + t411;
  t327_tmp = in2[94] * in2[101];
  t83 = t23_tmp * t130 * 2.0;
  t81 = t327_tmp * in2[102] * t13 * t129 * 2.0;
  t327 = ((-t139 + t302_tmp) + t83) + t81;
  t328 = ((t141 + t303) + t304) - t305;
  t333_tmp = t6 * in2[104] * t13 * t129 * 2.0;
  t27 = c_t20_tmp * t138 * 2.0;
  t420 = in2[97] * in2[103] * in2[104] * t13 * t129 * 2.0;
  t335 = ((-t55 + t27) + t333_tmp) + t420;
  st.site = &s_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t338 = muDoubleScalarPower(muDoubleScalarAbs(((((((t310 * in2[206] + t301 *
    in2[209]) + t328 * in2[214]) + t308 * in2[215]) - t316 * in2[207]) - t321 *
    in2[208]) - t327 * in2[213]) - t335 * in2[216]), in1[1] - 1.0);
  t343 = t395 * t62 * 2.0;
  t344 = c_t20_tmp * t64 * 2.0;
  t345 = in2[96] * t2 * t65 * 2.0;
  t346 = t397 * t62 * 2.0;
  t347_tmp = t394 * t60 * 2.0;
  t58 = t81_tmp * t70 * 2.0;
  t54 = b_t20_tmp * t88 * 2.0;
  t350 = in2[97] * t3 * t65 * 2.0;
  t351_tmp = t398 * t62 * 2.0;
  t16 = t399 * t70 * 2.0;
  t353_tmp = t77 * in2[102] * t13 * t129 * 2.0;
  t35 = t20_tmp * t136 * 2.0;
  t25 = t77 * in2[103] * t13 * t129 * 2.0;
  t24 = in2[95] * in2[103] * in2[104] * t13 * t129 * 2.0;
  t382_tmp = in2[94] * in2[103] * in2[104] * t13 * t129 * 2.0;
  t359 = ((t139 + t23_tmp * t138 * 2.0) + t50 * in2[104] * t13 * t129 * 2.0) -
    t382_tmp;
  t80 = t397 * t67 * 2.0;
  t360 = (((((t90 - t119_tmp) - t32) + t343) + t344) + t345) - t80;
  t82 = in2[94] * t4 * t65 * 2.0;
  t30 = t20_tmp * t105 * 2.0;
  t52 = t396 * t67 * 2.0;
  t366 = (((((-t104 - t93) - t346) + t347_tmp) + t52) + t30) + t82;
  t78 = t399 * t60 * 2.0;
  t367 = (((((-t295_tmp - t411) + t58) + t54) + t350) + t351_tmp) - t78;
  t372_tmp = t394 * t67 * 2.0;
  t50 = in2[95] * t5 * t65 * 2.0;
  t28 = t23_tmp * t120 * 2.0;
  t33 = t112_tmp * t60 * 2.0;
  t373 = (((((-t121 - t288_tmp) - t16) + t33) + t28) + t50) + t372_tmp;
  t77 = c_t20_tmp * t130 * 2.0;
  t31 = t327_tmp * in2[103] * t13 * t129 * 2.0;
  t376 = ((-t134 + t55) + t77) + t31;
  t6 = in2[95] * in2[102];
  t48 = b_t20_tmp * t132 * 2.0;
  t34 = t6 * in2[104] * t13 * t129 * 2.0;
  t379 = ((t330_tmp - t353_tmp) + t48) + t34;
  t380 = ((t305 + t35) + t25) - t24;
  st.site = &t_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t386 = muDoubleScalarPower(muDoubleScalarAbs(((((((t360 * in2[206] + t367 *
    in2[207]) + t380 * in2[215]) + t359 * in2[216]) - t366 * in2[208]) - t373 *
    in2[209]) - t376 * in2[213]) - t379 * in2[214]), in1[1] - 1.0);
  t392 = t395 * t70 * 2.0;
  t64 = b_t20_tmp * t64 * 2.0;
  t394 = in2[97] * t2 * t65 * 2.0;
  t395 = t86_tmp * t60 * 2.0;
  t396 = t396 * t60 * 2.0;
  t397 = t23_tmp * t105 * 2.0;
  t398 = in2[95] * t4 * t65 * 2.0;
  t399 = t35_tmp * t70 * 2.0;
  t105 = c_t20_tmp * t132 * 2.0;
  t132 = t6 * in2[103] * t13 * t129 * 2.0;
  t138 = ((-t141 + t24) + t20_tmp * t138 * 2.0) + t134_tmp * in2[104] * t13 *
    t129 * 2.0;
  memset(&out1[0], 0, 91U * sizeof(real_T));
  out1[91] = ((t9 + t10) - t126_tmp) - t12_tmp;
  out1[92] = -t8 - t125_tmp;
  out1[93] = t124 - in2[95] * in2[97] * t7 * 2.0;
  out1[94] = (((((((t114 + t148) + t149) + t150) + t152) - t147_tmp) - t173_tmp)
              - b_t173_tmp) - t151_tmp;
  out1[95] = (((t175_tmp - t192_tmp) - b_t175_tmp) - c_t175_tmp) - t157_tmp;
  out1[96] = t164;
  out1[97] = t169;
  out1[98] = t172;
  out1[99] = t170;
  out1[100] = -t124 + t127_tmp;
  memset(&out1[101], 0, 96U * sizeof(real_T));
  out1[197] = t8 - in2[95] * in2[96] * t7 * 2.0;
  out1[198] = (t263_tmp + t12_tmp) - t126_tmp;
  out1[199] = -t11 - t128_tmp;
  out1[200] = (((((((t87 + t198) + t199) + t200) + t201) - t107_tmp) - t220_tmp)
               - b_t220_tmp) - t168_tmp;
  out1[201] = (((((((t92 + t202) + t203) + t204) + t205_tmp) - t158_tmp) -
                t222_tmp) - b_t222_tmp) - c_t222_tmp;
  out1[202] = (((((((t157_tmp + t206) + t207) + t208) + t209) - t192_tmp) -
                t224_tmp) - b_t224_tmp) - t210_tmp;
  out1[203] = t216;
  out1[204] = -t8 + t125_tmp;
  out1[205] = t219;
  out1[206] = t217;
  memset(&out1[207], 0, 96U * sizeof(real_T));
  out1[303] = t124_tmp * -2.0 - t127_tmp;
  out1[304] = t11 - in2[96] * in2[97] * t7 * 2.0;
  out1[305] = (t219_tmp + t12_tmp) - t126_tmp;
  out1[306] = (((((((t91 + t244) + t245) + t246) + t247) - t158_tmp) - t264_tmp)
               - b_t264_tmp) - t205_tmp;
  out1[307] = t253;
  out1[308] = (((((((t115 + t151_tmp) + t254) + t255) + t256) - t147_tmp) -
                t268_tmp) - b_t268_tmp) - c_t268_tmp;
  out1[309] = (((((((-t118 + t210_tmp) + t257) + t258) + t259) + t260) -
                t192_tmp) - t270_tmp) - t36;
  out1[310] = t261;
  out1[311] = -t11 + t128_tmp;
  out1[312] = t263;
  memset(&out1[313], 0, 99U * sizeof(real_T));
  out1[412] = (((((t121 + t75) + t79) + t26) - t288_tmp) - t310_tmp) - t292_tmp;
  out1[413] = (((((t104 + t123) + t99) - t56) - t59) - t57) - t93;
  out1[414] = (((((t103 + t295_tmp) + t29) - t405) - t321_tmp) - t96) - t411;
  out1[415] = t301;
  out1[416] = 0.0;
  out1[417] = 0.0;
  out1[418] = 0.0;
  out1[419] = ((t139 - t83) - t81) - t302_tmp;
  out1[420] = ((t141 + t303) + t304) - in2[97] * in2[102] * in2[103] * t13 *
    t129 * 2.0;
  out1[421] = t308;
  out1[422] = ((t55 - t27) - t333_tmp) - t420;
  memset(&out1[423], 0, 95U * sizeof(real_T));
  out1[518] = (((((t90 + t343) + t344) + t345) - t119_tmp) - t32) - t80;
  out1[519] = (((((t58 + t54) + t350) + t351_tmp) - t295_tmp) - t78) - t411;
  out1[520] = (((((t104 + t93) + t346) - t82) - t30) - t52) - t347_tmp;
  out1[521] = (((((t121 + t288_tmp) + t16) - t50) - t28) - t33) - t372_tmp;
  out1[522] = 0.0;
  out1[523] = 0.0;
  out1[524] = 0.0;
  out1[525] = ((t134 - t77) - t31) - t55;
  out1[526] = ((t353_tmp - t48) - t330_tmp) - t34;
  out1[527] = ((t305 + t35) + t25) - in2[95] * in2[103] * in2[104] * t13 * t129 *
    2.0;
  out1[528] = t359;
  memset(&out1[529], 0, 95U * sizeof(real_T));
  t82 = t35_tmp * t67 * 2.0;
  out1[624] = (((((t103 + t392) + t64) + t394) - t295_tmp) - t351_tmp) - t82;
  t310_tmp = t81_tmp * t62 * 2.0;
  t80 = c_t20_tmp * t88 * 2.0;
  t48 = in2[96] * t3 * t65 * 2.0;
  out1[625] = (((((t90 + t119_tmp) + t395) - t48) - t80) - t310_tmp) - t322_tmp;
  t34 = t86_tmp * t62 * 2.0;
  out1[626] = (((((t292_tmp + t396) + t397) + t398) - t288_tmp) - t34) -
    t372_tmp;
  t78 = t112_tmp * t67 * 2.0;
  t31 = t20_tmp * t120 * 2.0;
  t28 = in2[94] * t5 * t65 * 2.0;
  out1[627] = (((((t104 - t123) + t347_tmp) + t399) - t28) - t31) - t78;
  out1[628] = 0.0;
  out1[629] = 0.0;
  out1[630] = 0.0;
  t33 = b_t20_tmp * t130 * 2.0;
  t50 = t327_tmp * in2[104] * t13 * t129 * 2.0;
  out1[631] = ((t135 - t33) - t50) - t353_tmp;
  out1[632] = ((t134 + t105) + t132) - t333_tmp;
  t77 = t23_tmp * t136 * 2.0;
  t6 = t141_tmp * in2[103] * t13 * t129 * 2.0;
  out1[633] = ((t302_tmp - t77) - t382_tmp) - t6;
  out1[634] = t138;
  out1[635] = 0.0;
  out2[0] = in1[0] * (((((t145 * -0.03599999999999999 + t146 *
    0.03599999999999999) + t20_tmp * t20) + b_t20_tmp * t23) - c_t20_tmp * t40)
                      + t23_tmp * t44) * 0.00026666666666666668;
  out2[1] = in1[0] * (((((t145 * 0.044000000000011939 + t146 *
    0.044000000000011939) + t20_tmp * t23) - b_t20_tmp * t20) + t23_tmp * t40) +
                      c_t20_tmp * t44) * 0.00026666666666666668;
  t321_tmp = t142 * t144;
  out2[2] = in1[0] * ((((t321_tmp * -0.072 + c_t20_tmp * t20) - t23_tmp * t23) +
                       t20_tmp * t40) + b_t20_tmp * t44) * 0.0008;
  out2[3] = in1[0] * (((t20_tmp * t60 * 2.0 + b_t20_tmp * t62 * 2.0) - t23_tmp *
                       t67 * 2.0) - c_t20_tmp * t70 * 2.0) *
    4.2666666666666668E-11;
  out2[4] = in1[0] * (((t20_tmp * t62 * 2.0 - b_t20_tmp * t60 * 2.0) - c_t20_tmp
                       * t67 * 2.0) + t23_tmp * t70 * 2.0) *
    1.421066666666666E-8;
  out2[5] = in1[0] * (((c_t20_tmp * t60 * 2.0 - t23_tmp * t62 * 2.0) + t20_tmp *
                       t70 * 2.0) - b_t20_tmp * t67 * 2.0) * 4.75111111111111E-9;
  t405 = (((((t103 - t295_tmp) - t351_tmp) + t392) + t64) + t394) - t82;
  t411 = (((((-t90 - t119_tmp) + t322_tmp) - t395) + t310_tmp) + t80) + t48;
  t350 = (((((-t288_tmp + t292_tmp) - t372_tmp) + t396) + t397) + t398) - t34;
  t344 = (((((-t104 + t123) - t347_tmp) - t399) + t78) + t31) + t28;
  t420 = ((-t135 + t353_tmp) + t33) + t50;
  t32 = ((t134 - t333_tmp) + t105) + t132;
  t80 = ((-t302_tmp + t382_tmp) + t77) + t6;
  st.site = &u_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t82 = muDoubleScalarPower(muDoubleScalarAbs(((((((t405 * in2[206] + t350 *
    in2[208]) + t32 * in2[214]) + t138 * in2[216]) - t411 * in2[207]) - t344 *
    in2[209]) - t420 * in2[213]) - t80 * in2[215]), in1[1] - 1.0);
  t30 = in1[2] * t170 * t189;
  t52 = in1[2] * t172 * t189;
  t24 = in1[2] * t171 * t189;
  t25 = -in1[2] * t164 * t189;
  out3[0] = ((((((((t25 * in2[208] + t30 * in2[204]) + t52 * in2[203]) - t24 *
                  in2[205]) - in1[2] * t169 * t189 * in2[209]) - in1[2] * t173 *
                t189 * in2[206]) - t30 * in2[211]) - t52 * in2[210]) - in1[2] *
             t175 * t189 * in2[207]) + t24 * in2[212];
  t16 = in1[2] * t217 * t233;
  t35 = in1[2] * t219 * t233;
  t27 = -in1[2] * t218 * t233;
  t343 = in1[2] * t218 * t233;
  out3[1] = ((((((((t27 * in2[203] + t16 * in2[205]) + t35 * in2[204]) - in1[2] *
                  t216 * t233 * in2[209]) - in1[2] * t220 * t233 * in2[206]) +
                t343 * in2[210]) - t16 * in2[212]) - in1[2] * t222 * t233 * in2
              [207]) - t35 * in2[211]) - in1[2] * t224 * t233 * in2[208];
  t345 = in1[2] * t261 * t277;
  t346 = in1[2] * t262 * t277;
  t58 = in1[2] * t263 * t277;
  t54 = -in1[2] * t253 * t277;
  out3[2] = ((((((((t54 * in2[207] + t345 * in2[203]) - t346 * in2[204]) + t58 *
                  in2[205]) - in1[2] * t264 * t277 * in2[206]) - t345 * in2[210])
               + t346 * in2[211]) - t58 * in2[212]) - in1[2] * t268 * t277 *
             in2[208]) - in1[2] * t270 * t277 * in2[209];
  t55 = in1[3] * t316 * t338;
  t310_tmp = in1[3] * t321 * t338;
  t56 = -in1[3] * t301 * t338;
  t59 = in1[3] * t327 * t338;
  t57 = in1[3] * t335 * t338;
  out3[3] = ((((((t56 * in2[209] - in1[3] * t310 * t338 * in2[206]) - in1[3] *
                 t308 * t338 * in2[215]) + t55 * in2[207]) + t310_tmp * in2[208])
              + t59 * in2[213]) - in1[3] * t328 * t338 * in2[214]) + t57 * in2
    [216];
  t96 = -in1[3] * t360 * t386;
  t83 = in1[3] * t366 * t386;
  t81 = in1[3] * t373 * t386;
  t36 = in1[3] * t376 * t386;
  t75 = in1[3] * t379 * t386;
  out3[4] = ((((((t96 * in2[206] + t83 * in2[208]) - in1[3] * t367 * t386 * in2
                 [207]) - in1[3] * t359 * t386 * in2[216]) + t81 * in2[209]) +
              t36 * in2[213]) + t75 * in2[214]) - in1[3] * t380 * t386 * in2[215];
  t79 = -in1[3] * t405 * t82;
  t26 = in1[3] * t411 * t82;
  t99 = in1[3] * t344 * t82;
  t93 = in1[3] * t420 * t82;
  t29 = in1[3] * t80 * t82;
  out3[5] = ((((((t79 * in2[206] + t26 * in2[207]) - in1[3] * t138 * t82 * in2
                 [216]) - in1[3] * t350 * t82 * in2[208]) + t99 * in2[209]) +
              t93 * in2[213]) - in1[3] * t32 * t82 * in2[214]) + t29 * in2[215];
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
  *out5 = t78 + t321_tmp * 0.072;
  t78 = in1[0] * t171 * 0.00026666666666666668;
  t48 = in1[0] * t218 * 0.00026666666666666668;
  t34 = in1[0] * t262 * 0.0008;
  memset(&out6[0], 0, 546U * sizeof(real_T));
  t31 = in1[0] * t172;
  out6[546] = t31 * -0.00026666666666666668;
  out6[547] = t48;
  t77 = in1[0] * t261;
  out6[548] = t77 * -0.0008;
  out6[549] = 0.0;
  out6[550] = 0.0;
  out6[551] = 0.0;
  t33 = in1[0] * t170;
  out6[552] = t33 * -0.00026666666666666668;
  t28 = in1[0] * t219;
  out6[553] = t28 * -0.00026666666666666668;
  out6[554] = t34;
  out6[555] = 0.0;
  out6[556] = 0.0;
  out6[557] = 0.0;
  out6[558] = t78;
  t50 = in1[0] * t217;
  out6[559] = t50 * -0.00026666666666666668;
  t6 = in1[0] * t263;
  out6[560] = t6 * -0.0008;
  out6[561] = 0.0;
  out6[562] = 0.0;
  out6[563] = 0.0;
  out6[564] = in1[0] * t173 * 0.00026666666666666668;
  out6[565] = in1[0] * t220 * 0.00026666666666666668;
  out6[566] = in1[0] * t264 * 0.0008;
  out6[567] = in1[0] * t310 * 4.2666666666666668E-11;
  out6[568] = in1[0] * t360 * 1.421066666666666E-8;
  out6[569] = in1[0] * t405 * 4.75111111111111E-9;
  out6[570] = in1[0] * t175 * 0.00026666666666666668;
  out6[571] = in1[0] * t222 * 0.00026666666666666668;
  out6[572] = in1[0] * t253 * 0.0008;
  out6[573] = in1[0] * t316 * -4.2666666666666668E-11;
  out6[574] = in1[0] * t367 * 1.421066666666666E-8;
  out6[575] = in1[0] * t411 * -4.75111111111111E-9;
  out6[576] = in1[0] * t164 * 0.00026666666666666668;
  out6[577] = in1[0] * t224 * 0.00026666666666666668;
  out6[578] = in1[0] * t268 * 0.0008;
  out6[579] = in1[0] * t321 * -4.2666666666666668E-11;
  out6[580] = in1[0] * t366 * -1.421066666666666E-8;
  out6[581] = in1[0] * t350 * 4.75111111111111E-9;
  out6[582] = in1[0] * t169 * 0.00026666666666666668;
  out6[583] = in1[0] * t216 * 0.00026666666666666668;
  out6[584] = in1[0] * t270 * 0.0008;
  out6[585] = in1[0] * t301 * 4.2666666666666668E-11;
  out6[586] = in1[0] * t373 * -1.421066666666666E-8;
  out6[587] = in1[0] * t344 * -4.75111111111111E-9;
  out6[588] = t31 * 0.00026666666666666668;
  out6[589] = -t48;
  out6[590] = t77 * 0.0008;
  out6[591] = 0.0;
  out6[592] = 0.0;
  out6[593] = 0.0;
  out6[594] = t33 * 0.00026666666666666668;
  out6[595] = t28 * 0.00026666666666666668;
  out6[596] = -t34;
  out6[597] = 0.0;
  out6[598] = 0.0;
  out6[599] = 0.0;
  out6[600] = -t78;
  out6[601] = t50 * 0.00026666666666666668;
  out6[602] = t6 * 0.0008;
  out6[603] = 0.0;
  out6[604] = 0.0;
  out6[605] = 0.0;
  out6[606] = 0.0;
  out6[607] = 0.0;
  out6[608] = 0.0;
  out6[609] = in1[0] * t327 * -4.2666666666666668E-11;
  out6[610] = in1[0] * t376 * -1.421066666666666E-8;
  out6[611] = in1[0] * t420 * -4.75111111111111E-9;
  out6[612] = 0.0;
  out6[613] = 0.0;
  out6[614] = 0.0;
  out6[615] = in1[0] * t328 * 4.2666666666666668E-11;
  out6[616] = in1[0] * t379 * -1.421066666666666E-8;
  out6[617] = in1[0] * t32 * 4.75111111111111E-9;
  out6[618] = 0.0;
  out6[619] = 0.0;
  out6[620] = 0.0;
  out6[621] = in1[0] * t308 * 4.2666666666666668E-11;
  out6[622] = in1[0] * t380 * 1.421066666666666E-8;
  out6[623] = in1[0] * t80 * -4.75111111111111E-9;
  out6[624] = 0.0;
  out6[625] = 0.0;
  out6[626] = 0.0;
  out6[627] = in1[0] * t335 * -4.2666666666666668E-11;
  out6[628] = in1[0] * t359 * 1.421066666666666E-8;
  out6[629] = in1[0] * t138 * 4.75111111111111E-9;
  out6[630] = 0.0;
  out6[631] = 0.0;
  out6[632] = 0.0;
  out6[633] = 0.0;
  out6[634] = 0.0;
  out6[635] = 0.0;
  memset(&out7[0], 0, 546U * sizeof(real_T));
  out7[546] = t52;
  out7[547] = t27;
  out7[548] = t345;
  out7[549] = 0.0;
  out7[550] = 0.0;
  out7[551] = 0.0;
  out7[552] = t30;
  out7[553] = t35;
  out7[554] = -in1[2] * t262 * t277;
  out7[555] = 0.0;
  out7[556] = 0.0;
  out7[557] = 0.0;
  out7[558] = -in1[2] * t171 * t189;
  out7[559] = t16;
  out7[560] = t58;
  out7[561] = 0.0;
  out7[562] = 0.0;
  out7[563] = 0.0;
  out7[564] = -in1[2] * t173 * t189;
  out7[565] = -in1[2] * t220 * t233;
  out7[566] = -in1[2] * t264 * t277;
  out7[567] = -in1[3] * t310 * t338;
  out7[568] = t96;
  out7[569] = t79;
  out7[570] = -in1[2] * t175 * t189;
  out7[571] = -in1[2] * t222 * t233;
  out7[572] = t54;
  out7[573] = t55;
  out7[574] = -in1[3] * t367 * t386;
  out7[575] = t26;
  out7[576] = t25;
  out7[577] = -in1[2] * t224 * t233;
  out7[578] = -in1[2] * t268 * t277;
  out7[579] = t310_tmp;
  out7[580] = t83;
  out7[581] = -in1[3] * t350 * t82;
  out7[582] = -in1[2] * t169 * t189;
  out7[583] = -in1[2] * t216 * t233;
  out7[584] = -in1[2] * t270 * t277;
  out7[585] = t56;
  out7[586] = t81;
  out7[587] = t99;
  out7[588] = -t52;
  out7[589] = t343;
  out7[590] = -t345;
  out7[591] = 0.0;
  out7[592] = 0.0;
  out7[593] = 0.0;
  out7[594] = -t30;
  out7[595] = -t35;
  out7[596] = t346;
  out7[597] = 0.0;
  out7[598] = 0.0;
  out7[599] = 0.0;
  out7[600] = t24;
  out7[601] = -t16;
  out7[602] = -t58;
  out7[603] = 0.0;
  out7[604] = 0.0;
  out7[605] = 0.0;
  out7[606] = 0.0;
  out7[607] = 0.0;
  out7[608] = 0.0;
  out7[609] = t59;
  out7[610] = t36;
  out7[611] = t93;
  out7[612] = 0.0;
  out7[613] = 0.0;
  out7[614] = 0.0;
  out7[615] = -in1[3] * t328 * t338;
  out7[616] = t75;
  out7[617] = -in1[3] * t32 * t82;
  out7[618] = 0.0;
  out7[619] = 0.0;
  out7[620] = 0.0;
  out7[621] = -in1[3] * t308 * t338;
  out7[622] = -in1[3] * t380 * t386;
  out7[623] = t29;
  out7[624] = 0.0;
  out7[625] = 0.0;
  out7[626] = 0.0;
  out7[627] = t57;
  out7[628] = -in1[3] * t359 * t386;
  out7[629] = -in1[3] * t138 * t82;
  out7[630] = 0.0;
  out7[631] = 0.0;
  out7[632] = 0.0;
  out7[633] = 0.0;
  out7[634] = 0.0;
  out7[635] = 0.0;
  *out8 = 1.0;
}

/* End of code generation (sprdmpF129.c) */
