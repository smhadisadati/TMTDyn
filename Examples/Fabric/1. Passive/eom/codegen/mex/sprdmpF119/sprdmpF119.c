/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sprdmpF119.c
 *
 * Code generation for function 'sprdmpF119'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "sprdmpF119.h"
#include "sqrt.h"
#include "error.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 41,    /* lineNo */
  "sprdmpF119",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF119.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 42,  /* lineNo */
  "sprdmpF119",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF119.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 43,  /* lineNo */
  "sprdmpF119",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF119.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 44,  /* lineNo */
  "sprdmpF119",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF119.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 52,  /* lineNo */
  "sprdmpF119",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF119.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 55,  /* lineNo */
  "sprdmpF119",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF119.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 93,  /* lineNo */
  "sprdmpF119",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF119.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 94,  /* lineNo */
  "sprdmpF119",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF119.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 95,  /* lineNo */
  "sprdmpF119",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF119.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 96,  /* lineNo */
  "sprdmpF119",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF119.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 98,  /* lineNo */
  "sprdmpF119",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF119.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 106, /* lineNo */
  "sprdmpF119",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF119.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 168, /* lineNo */
  "sprdmpF119",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF119.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 243, /* lineNo */
  "sprdmpF119",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF119.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 289, /* lineNo */
  "sprdmpF119",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF119.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 333, /* lineNo */
  "sprdmpF119",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF119.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 388, /* lineNo */
  "sprdmpF119",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF119.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 437, /* lineNo */
  "sprdmpF119",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF119.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 482, /* lineNo */
  "sprdmpF119",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF119.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 487, /* lineNo */
  "sprdmpF119",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF119.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 496, /* lineNo */
  "sprdmpF119",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF119.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 49,  /* lineNo */
  "power",                             /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 61,  /* lineNo */
  "power",                             /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

/* Function Definitions */
void sprdmpF119(const emlrtStack *sp, const real_T in1[6], const real_T in2[224],
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
  real_T t405;
  real_T t50;
  real_T t26;
  real_T t27;
  real_T t28;
  real_T t351;
  real_T t48;
  real_T t402;
  real_T t29;
  real_T t30;
  real_T t404;
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
  real_T t350;
  real_T t406;
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
  real_T t401;
  real_T t96;
  real_T t403;
  real_T t98;
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
  real_T t145;
  real_T t147;
  real_T t148;
  real_T t149;
  real_T t151;
  real_T t153;
  real_T t154_tmp;
  real_T t155;
  real_T t156;
  real_T t157;
  real_T t158_tmp;
  real_T t159;
  real_T t164_tmp;
  real_T t165_tmp;
  real_T t171;
  real_T t175_tmp;
  real_T t176;
  real_T t177;
  real_T t178;
  real_T t179;
  real_T t180_tmp;
  real_T b_t180_tmp;
  real_T t180;
  real_T t199_tmp;
  real_T t182_tmp;
  real_T b_t182_tmp;
  real_T c_t182_tmp;
  real_T t182;
  real_T t196;
  real_T t205;
  real_T t206;
  real_T t207;
  real_T t208;
  real_T t209;
  real_T t210;
  real_T t211;
  real_T t212_tmp;
  real_T t213;
  real_T t214;
  real_T t215;
  real_T t216;
  real_T t217_tmp;
  real_T t223;
  real_T t224;
  real_T t225;
  real_T t226_tmp;
  real_T t226;
  real_T t227_tmp;
  real_T b_t227_tmp;
  real_T t227;
  real_T t229_tmp;
  real_T b_t229_tmp;
  real_T c_t229_tmp;
  real_T t229;
  real_T t231_tmp;
  real_T b_t231_tmp;
  real_T t231;
  real_T t240;
  real_T t251;
  real_T t252;
  real_T t253;
  real_T t254;
  real_T t260;
  real_T t261;
  real_T t262;
  real_T t263;
  real_T t264;
  real_T t265;
  real_T t266;
  real_T t267;
  real_T t268;
  real_T t269;
  real_T t270_tmp;
  real_T t270;
  real_T t271_tmp;
  real_T b_t271_tmp;
  real_T t271;
  real_T t275_tmp;
  real_T b_t275_tmp;
  real_T c_t275_tmp;
  real_T t275;
  real_T t277_tmp;
  real_T t277;
  real_T t284;
  real_T t295_tmp;
  real_T t299_tmp;
  real_T t302_tmp;
  real_T t307_tmp;
  real_T t329_tmp;
  real_T t308;
  real_T t309_tmp;
  real_T t310;
  real_T t311;
  real_T t312;
  real_T t337_tmp;
  real_T t315;
  real_T t427;
  real_T t317;
  real_T t424;
  real_T t419;
  real_T t418;
  real_T t323;
  real_T t412;
  real_T t328;
  real_T t334_tmp;
  real_T t334;
  real_T t335;
  real_T t340_tmp;
  real_T t342;
  real_T t345;
  real_T t354_tmp;
  real_T t358_tmp;
  real_T t360_tmp;
  real_T t389_tmp;
  real_T t366;
  real_T t367;
  real_T t373;
  real_T t374;
  real_T t379_tmp;
  real_T t380;
  real_T t383;
  real_T t386;
  real_T t387;
  real_T t393;
  real_T t399;
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

  /* SPRDMPF119 */
  /*     [OUT1,OUT2,OUT3,OUT4,OUT5,OUT6,OUT7,OUT8] = SPRDMPF119(IN1,IN2,S) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.2. */
  /*     06-Jul-2019 07:07:12 */
  st.site = &emlrtRSI;
  b_st.site = &v_emlrtRSI;
  t2 = in2[52] * in2[52];
  st.site = &b_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  t3 = in2[53] * in2[53];
  st.site = &c_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  t4 = in2[54] * in2[54];
  st.site = &d_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  t5 = in2[55] * in2[55];
  t6 = ((t2 + t3) + t4) + t5;
  t7 = 1.0 / t6;
  t77 = in2[52] * in2[55];
  t8 = t77 * t7 * 2.0;
  t9 = t4 * t7;
  t10 = t5 * t7;
  t33 = in2[52] * in2[53];
  t11 = t33 * t7 * 2.0;
  t12_tmp = t3 * t7;
  t78 = t6;
  st.site = &e_emlrtRSI;
  b_sqrt(&st, &t78);
  t13 = 1.0 / t78;
  t14 = in2[49] - in2[56];
  t15 = in2[50] - in2[57];
  st.site = &f_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  if (t6 < 0.0) {
    c_st.site = &w_emlrtRSI;
    error(&c_st);
  }

  t16 = 1.0 / muDoubleScalarPower(t6, 1.5);
  t17 = in2[51] - in2[58];
  t20_tmp = in2[52] * t13;
  b_t20_tmp = in2[55] * t13;
  c_t20_tmp = in2[54] * t13;
  t20 = (t20_tmp * t14 + b_t20_tmp * t15) - c_t20_tmp * t17;
  t23_tmp = in2[53] * t13;
  t23 = (t20_tmp * t15 + t23_tmp * t17) - b_t20_tmp * t14;
  t24 = t13 * t15;
  t25 = t77 * t14 * t16;
  t405 = t33 * t16;
  t50 = t405 * t17;
  t26 = ((t24 + t25) - t2 * t15 * t16) - t50;
  t27 = t13 * t17;
  t28 = t33 * t15 * t16;
  t351 = in2[52] * in2[54];
  t48 = t351 * t14 * t16;
  t402 = t2 * t16;
  t29 = ((t27 + t28) - t402 * t17) - t48;
  t30 = t13 * t14;
  t404 = t351 * t16;
  t31 = t404 * t17;
  t52 = t77 * t15 * t16;
  t32 = ((t30 + t31) - t2 * t14 * t16) - t52;
  t33 = t33 * t14 * t16;
  t34 = t351 * t15 * t16;
  t35_tmp = t77 * t16;
  t35 = t35_tmp * t17;
  t36 = (t33 + t34) + t35;
  t40 = (c_t20_tmp * t14 + t20_tmp * t17) - t23_tmp * t15;
  t44 = (t23_tmp * t14 + c_t20_tmp * t15) + b_t20_tmp * t17;
  st.site = &g_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  t54 = in2[59] * in2[59];
  st.site = &h_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  t55 = in2[60] * in2[60];
  st.site = &i_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  t56 = in2[61] * in2[61];
  st.site = &j_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  t57 = in2[62] * in2[62];
  t58 = ((t54 + t55) + t56) + t57;
  t78 = t58;
  st.site = &k_emlrtRSI;
  b_sqrt(&st, &t78);
  t59 = 1.0 / t78;
  t60 = t23_tmp - in2[60] * t59;
  t62 = c_t20_tmp - in2[61] * t59;
  t64 = t13 - t402;
  st.site = &l_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  t65 = 1.0 / (t6 * t6);
  t67 = t20_tmp - in2[59] * t59;
  t70 = b_t20_tmp - in2[62] * t59;
  t74_tmp = in2[53] * in2[54];
  t6 = t74_tmp * t14 * t16;
  t75 = ((t24 + t50) + t6) - t3 * t15 * t16;
  t77 = t74_tmp * t15 * t16;
  t350 = in2[53] * in2[55];
  t406 = t350 * t16;
  t78 = t406 * t17;
  t79 = ((-t30 + t3 * t14 * t16) + t77) + t78;
  t80 = t350 * t14 * t16;
  t81_tmp = t3 * t16;
  t81 = ((t27 - t28) + t80) - t81_tmp * t17;
  t82 = t350 * t15 * t16;
  t86_tmp = t74_tmp * t16;
  t50 = t86_tmp * t17;
  t83 = (t33 + t82) - t50;
  t87 = t405 * t40;
  t88 = t13 - t81_tmp;
  t90 = t405 * t70 * 2.0;
  t91 = t404 * t20;
  t92 = t86_tmp * t44;
  t93 = ((t30 - t31) + t77) - t4 * t14 * t16;
  t77 = in2[54] * in2[55];
  t401 = t77 * t16;
  t28 = t401 * t17;
  t96 = ((-t24 + t6) + t4 * t15 * t16) + t28;
  t6 = t77 * t15 * t16;
  t403 = t4 * t16;
  t98 = ((t27 + t48) + t6) - t403 * t17;
  t33 = t77 * t14 * t16;
  t99 = (t34 + t50) - t33;
  t103 = t404 * t60 * 2.0;
  t104 = t13 * t67 * 2.0;
  t105 = t13 - t403;
  t107_tmp = t13 * t23;
  t48 = t406 * t44;
  t78 = ((t30 + t52) + t78) - t5 * t14 * t16;
  t34 = ((t24 - t25) + t28) - t5 * t15 * t16;
  t112_tmp = t5 * t16;
  t31 = ((-t27 + t80) + t6) + t112_tmp * t17;
  t28 = (t35 - t82) + t33;
  t114 = t35_tmp * t23;
  t115 = t401 * t44;
  t118 = t406 * t23;
  t119_tmp = t13 * t62 * 2.0;
  t120 = t13 - t112_tmp;
  t121 = t35_tmp * t62 * 2.0;
  t123 = t406 * t62 * 2.0;
  t124_tmp = t351 * t7;
  t124 = t124_tmp * 2.0;
  t125_tmp = t74_tmp * t7 * 2.0;
  t126_tmp = t2 * t7;
  t127_tmp = t350 * t7 * 2.0;
  t128_tmp = t77 * t7 * 2.0;
  st.site = &m_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  if (t58 < 0.0) {
    c_st.site = &w_emlrtRSI;
    error(&c_st);
  }

  t129 = 1.0 / muDoubleScalarPower(t58, 1.5);
  t130 = t59 - t54 * t129;
  t132 = t59 - t55 * t129;
  t134_tmp = in2[55] * in2[59];
  t134 = t134_tmp * in2[60] * t13 * t129 * 2.0;
  t33 = in2[53] * in2[59];
  t135 = t33 * in2[61] * t13 * t129 * 2.0;
  t136 = t59 - t56 * t129;
  t138 = t59 - t57 * t129;
  t77 = in2[54] * in2[59];
  t139 = t77 * in2[62] * t13 * t129 * 2.0;
  t141_tmp = in2[54] * in2[60];
  t141 = t141_tmp * in2[62] * t13 * t129 * 2.0;
  t6 = in1[4] / 2.0;
  t143 = muDoubleScalarCos(t6);
  t50 = t143 / 25.0;
  t145 = muDoubleScalarSin(t6);
  t147 = t145 / 25.0;
  t148 = t143 * 0.162 - t147;
  t149 = t143 * 0.077;
  t151 = t50 + t145 * 0.162;
  t153 = t50 + t145 * 0.077;
  t154_tmp = t13 * t20;
  t155 = c_t20_tmp * t29;
  t156 = t23_tmp * t36;
  t157 = t402 * t20;
  t158_tmp = t404 * t40;
  t159 = t405 * t44;
  t164_tmp = t86_tmp * t40;
  t165_tmp = t13 * t40;
  t171 = (((((((t91 + t92) + t165_tmp) + c_t20_tmp * t93) + t20_tmp * t98) +
            t23_tmp * t96) + b_t20_tmp * t99) + t401 * t23) - t403 * t40;
  t175_tmp = t35_tmp * t20;
  t176 = (((((((-t107_tmp + t48) + b_t20_tmp * t78) + t23_tmp * t31) + t112_tmp *
             t23) + t175_tmp) - t20_tmp * t34) - c_t20_tmp * t28) - t401 * t40;
  t177 = t8 + t125_tmp;
  t178 = t124 - t127_tmp;
  t179 = ((-t9 - t10) + t12_tmp) + t126_tmp;
  t180_tmp = b_t20_tmp * t26;
  b_t180_tmp = t20_tmp * t32;
  t180 = (((((((t114 - t154_tmp) + t155) + t156) + t157) - t158_tmp) + t159) -
          b_t180_tmp) - t180_tmp;
  t199_tmp = t13 * t44;
  t182_tmp = (((t118 + t23_tmp * t79) + t20_tmp * t83) + t81_tmp * t44) + t405 *
    t20;
  b_t182_tmp = c_t20_tmp * t75;
  c_t182_tmp = b_t20_tmp * t81;
  t182 = (((t182_tmp - t164_tmp) - t199_tmp) - b_t182_tmp) - c_t182_tmp;
  st.site = &n_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  t196 = muDoubleScalarPower(muDoubleScalarAbs(((((((((t180 * in2[164] + t182 *
    in2[165]) + t171 * in2[166]) + t176 * in2[167]) + t178 * in2[163]) + t177 *
    in2[169]) + t179 * in2[168]) - t177 * in2[162]) - t178 * in2[170]) - t179 *
    in2[161]), in1[1] - 1.0);
  t205 = b_t20_tmp * t32;
  t206 = c_t20_tmp * t36;
  t207 = t402 * t23;
  t208 = t404 * t44;
  t209 = t23_tmp * t75;
  t210 = c_t20_tmp * t79;
  t211 = t81_tmp * t40;
  t212_tmp = t405 * t23;
  t213 = c_t20_tmp * t96;
  t214 = t20_tmp * t99;
  t215 = t403 * t44;
  t216 = t404 * t23;
  t217_tmp = t401 * t20;
  t223 = (((((((t114 + t115) + t154_tmp) + t20_tmp * t78) + b_t20_tmp * t34) +
            c_t20_tmp * t31) + t23_tmp * t28) + t406 * t40) - t112_tmp * t20;
  t224 = t11 + t128_tmp;
  t225 = t8 - t125_tmp;
  t226_tmp = t9 - t10;
  t226 = (t226_tmp - t12_tmp) + t126_tmp;
  t227_tmp = t20_tmp * t26;
  b_t227_tmp = t23_tmp * t29;
  t227 = (((((((t87 - t107_tmp) - t175_tmp) + t205) + t206) + t207) + t208) -
          t227_tmp) - b_t227_tmp;
  t229_tmp = t20_tmp * t81;
  b_t229_tmp = b_t20_tmp * t83;
  c_t229_tmp = t406 * t20;
  t229 = (((((((t92 - t165_tmp) + t209) + t210) + t211) + t212_tmp) - t229_tmp)
          - b_t229_tmp) - c_t229_tmp;
  t231_tmp = t23_tmp * t93;
  b_t231_tmp = b_t20_tmp * t98;
  t231 = (((((((t164_tmp - t199_tmp) + t213) + t214) + t215) + t216) - t217_tmp)
          - t231_tmp) - b_t231_tmp;
  st.site = &o_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  t240 = muDoubleScalarPower(muDoubleScalarAbs(((((((((t227 * in2[164] + t229 *
    in2[165]) + t231 * in2[166]) + t223 * in2[167]) + t225 * in2[161]) + t224 *
    in2[170]) + t226 * in2[169]) - t224 * in2[163]) - t225 * in2[168]) - t226 *
    in2[162]), in1[1] - 1.0);
  t251 = t23_tmp * t26;
  t252 = b_t20_tmp * t36;
  t253 = t402 * t40;
  t254 = t35_tmp * t44;
  t260 = (((((((t87 + t107_tmp) + t48) + t20_tmp * t75) + b_t20_tmp * t79) +
            t23_tmp * t81) + c_t20_tmp * t83) + t86_tmp * t20) - t81_tmp * t23;
  t261 = c_t20_tmp * t98;
  t262 = b_t20_tmp * t96;
  t263 = t403 * t20;
  t264 = b_t20_tmp * t31;
  t265 = t20_tmp * t28;
  t266 = t112_tmp * t44;
  t267 = t35_tmp * t40;
  t268 = t124 + t127_tmp;
  t269 = t11 - t128_tmp;
  t270_tmp = -t9 + t10;
  t270 = (t270_tmp - t12_tmp) + t126_tmp;
  t271_tmp = t20_tmp * t29;
  b_t271_tmp = c_t20_tmp * t32;
  t271 = (((((((t91 - t165_tmp) - t212_tmp) + t251) + t252) + t253) + t254) -
          t271_tmp) - b_t271_tmp;
  t275_tmp = t20_tmp * t93;
  b_t275_tmp = t23_tmp * t99;
  c_t275_tmp = t86_tmp * t23;
  t275 = (((((((t115 - t154_tmp) + t158_tmp) + t261) + t262) + t263) - t275_tmp)
          - b_t275_tmp) - c_t275_tmp;
  t277_tmp = t23_tmp * t78;
  t75 = c_t20_tmp * t34;
  t277 = (((((((-t118 - t199_tmp) + t217_tmp) + t264) + t265) + t266) + t267) -
          t277_tmp) - t75;
  st.site = &p_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  t284 = muDoubleScalarPower(muDoubleScalarAbs(((((((((t271 * in2[164] + t260 *
    in2[165]) + t275 * in2[166]) + t277 * in2[167]) + t269 * in2[162]) + t268 *
    in2[168]) + t270 * in2[170]) - t268 * in2[161]) - t269 * in2[169]) - t270 *
    in2[163]), in1[1] - 1.0);
  t295_tmp = t13 * t60 * 2.0;
  t79 = t402 * t60 * 2.0;
  t26 = t23_tmp * t64 * 2.0;
  t99 = in2[53] * t2 * t65 * 2.0;
  t299_tmp = t404 * t70 * 2.0;
  t93 = t405 * t60 * 2.0;
  t29 = t86_tmp * t70 * 2.0;
  t302_tmp = t13 * t70 * 2.0;
  t32 = t401 * t62 * 2.0;
  t307_tmp = t35_tmp * t60 * 2.0;
  t329_tmp = t406 * t67 * 2.0;
  t308 = (((((-t119_tmp + t112_tmp * t62 * 2.0) + c_t20_tmp * t120 * 2.0) + in2
            [54] * t5 * t65 * 2.0) + t307_tmp) - t329_tmp) - t401 * t70 * 2.0;
  t309_tmp = t134_tmp * in2[61] * t13 * t129 * 2.0;
  t310 = t20_tmp * t132 * 2.0;
  t311 = t33 * in2[60] * t13 * t129 * 2.0;
  t50 = in2[55] * in2[60];
  t312 = t50 * in2[61] * t13 * t129 * 2.0;
  t6 = in2[52] * in2[60];
  t337_tmp = t6 * in2[61] * t13 * t129 * 2.0;
  t315 = ((t135 + b_t20_tmp * t136 * 2.0) + in2[54] * in2[61] * in2[62] * t13 *
          t129 * 2.0) - t337_tmp;
  t57 = t33 * in2[62] * t13 * t129 * 2.0;
  t427 = t405 * t67 * 2.0;
  t317 = (((((t121 - t295_tmp) + t79) + t26) + t99) - t299_tmp) - t427;
  t424 = in2[52] * t3 * t65 * 2.0;
  t419 = t20_tmp * t88 * 2.0;
  t418 = t81_tmp * t67 * 2.0;
  t323 = (((((-t104 - t123) - t93) + t29) + t418) + t419) + t424;
  t412 = t86_tmp * t67 * 2.0;
  t98 = in2[55] * t4 * t65 * 2.0;
  t96 = b_t20_tmp * t105 * 2.0;
  t83 = t403 * t70 * 2.0;
  t328 = (((((-t103 - t302_tmp) - t32) + t83) + t96) + t98) + t412;
  t334_tmp = in2[52] * in2[59];
  t81 = t23_tmp * t130 * 2.0;
  t36 = t334_tmp * in2[60] * t13 * t129 * 2.0;
  t334 = ((-t139 + t309_tmp) + t81) + t36;
  t335 = ((t141 + t310) + t311) - t312;
  t340_tmp = t6 * in2[62] * t13 * t129 * 2.0;
  t27 = c_t20_tmp * t138 * 2.0;
  t74_tmp = in2[55] * in2[61] * in2[62] * t13 * t129 * 2.0;
  t342 = ((-t57 + t27) + t340_tmp) + t74_tmp;
  st.site = &q_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  t345 = muDoubleScalarPower(muDoubleScalarAbs(((((((t317 * in2[164] + t308 *
    in2[167]) + t335 * in2[172]) + t315 * in2[173]) - t323 * in2[165]) - t328 *
    in2[166]) - t334 * in2[171]) - t342 * in2[174]), in1[1] - 1.0);
  t350 = t402 * t62 * 2.0;
  t351 = c_t20_tmp * t64 * 2.0;
  t58 = in2[54] * t2 * t65 * 2.0;
  t54 = t404 * t62 * 2.0;
  t354_tmp = t401 * t60 * 2.0;
  t55 = t81_tmp * t70 * 2.0;
  t56 = b_t20_tmp * t88 * 2.0;
  t59 = in2[55] * t3 * t65 * 2.0;
  t358_tmp = t405 * t62 * 2.0;
  t16 = t406 * t70 * 2.0;
  t360_tmp = t77 * in2[60] * t13 * t129 * 2.0;
  t35 = t20_tmp * t136 * 2.0;
  t25 = t77 * in2[61] * t13 * t129 * 2.0;
  t24 = in2[53] * in2[61] * in2[62] * t13 * t129 * 2.0;
  t389_tmp = in2[52] * in2[61] * in2[62] * t13 * t129 * 2.0;
  t366 = ((t139 + t23_tmp * t138 * 2.0) + t50 * in2[62] * t13 * t129 * 2.0) -
    t389_tmp;
  t80 = t404 * t67 * 2.0;
  t367 = (((((t90 - t119_tmp) - t307_tmp) + t350) + t351) + t58) - t80;
  t82 = in2[52] * t4 * t65 * 2.0;
  t30 = t20_tmp * t105 * 2.0;
  t52 = t403 * t67 * 2.0;
  t373 = (((((-t104 - t29) - t54) + t354_tmp) + t52) + t30) + t82;
  t78 = t406 * t60 * 2.0;
  t374 = (((((-t302_tmp - t412) + t55) + t56) + t59) + t358_tmp) - t78;
  t379_tmp = t401 * t67 * 2.0;
  t50 = in2[53] * t5 * t65 * 2.0;
  t28 = t23_tmp * t120 * 2.0;
  t33 = t112_tmp * t60 * 2.0;
  t380 = (((((-t121 - t295_tmp) - t16) + t33) + t28) + t50) + t379_tmp;
  t77 = c_t20_tmp * t130 * 2.0;
  t31 = t334_tmp * in2[61] * t13 * t129 * 2.0;
  t383 = ((-t134 + t57) + t77) + t31;
  t6 = in2[53] * in2[60];
  t48 = b_t20_tmp * t132 * 2.0;
  t34 = t6 * in2[62] * t13 * t129 * 2.0;
  t386 = ((t337_tmp - t360_tmp) + t48) + t34;
  t387 = ((t312 + t35) + t25) - t24;
  st.site = &r_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  t393 = muDoubleScalarPower(muDoubleScalarAbs(((((((t367 * in2[164] + t374 *
    in2[165]) + t387 * in2[173]) + t366 * in2[174]) - t373 * in2[166]) - t380 *
    in2[167]) - t383 * in2[171]) - t386 * in2[172]), in1[1] - 1.0);
  t399 = t402 * t70 * 2.0;
  t64 = b_t20_tmp * t64 * 2.0;
  t401 = in2[55] * t2 * t65 * 2.0;
  t402 = t86_tmp * t60 * 2.0;
  t403 = t403 * t60 * 2.0;
  t404 = t23_tmp * t105 * 2.0;
  t405 = in2[53] * t4 * t65 * 2.0;
  t406 = t35_tmp * t70 * 2.0;
  t105 = c_t20_tmp * t132 * 2.0;
  t132 = t6 * in2[61] * t13 * t129 * 2.0;
  t138 = ((-t141 + t24) + t20_tmp * t138 * 2.0) + t134_tmp * in2[62] * t13 *
    t129 * 2.0;
  memset(&out1[0], 0, 49U * sizeof(real_T));
  out1[49] = ((t9 + t10) - t126_tmp) - t12_tmp;
  out1[50] = -t8 - t125_tmp;
  out1[51] = t124 - in2[53] * in2[55] * t7 * 2.0;
  out1[52] = (((((((t114 + t155) + t156) + t157) + t159) - t154_tmp) - t180_tmp)
              - b_t180_tmp) - t158_tmp;
  out1[53] = (((t182_tmp - t199_tmp) - b_t182_tmp) - c_t182_tmp) - t164_tmp;
  out1[54] = t171;
  out1[55] = t176;
  out1[56] = t179;
  out1[57] = t177;
  out1[58] = -t124 + t127_tmp;
  memset(&out1[59], 0, 96U * sizeof(real_T));
  out1[155] = t8 - in2[53] * in2[54] * t7 * 2.0;
  out1[156] = (t270_tmp + t12_tmp) - t126_tmp;
  out1[157] = -t11 - t128_tmp;
  out1[158] = (((((((t87 + t205) + t206) + t207) + t208) - t107_tmp) - t227_tmp)
               - b_t227_tmp) - t175_tmp;
  out1[159] = (((((((t92 + t209) + t210) + t211) + t212_tmp) - t165_tmp) -
                t229_tmp) - b_t229_tmp) - c_t229_tmp;
  out1[160] = (((((((t164_tmp + t213) + t214) + t215) + t216) - t199_tmp) -
                t231_tmp) - b_t231_tmp) - t217_tmp;
  out1[161] = t223;
  out1[162] = -t8 + t125_tmp;
  out1[163] = t226;
  out1[164] = t224;
  memset(&out1[165], 0, 96U * sizeof(real_T));
  out1[261] = t124_tmp * -2.0 - t127_tmp;
  out1[262] = t11 - in2[54] * in2[55] * t7 * 2.0;
  out1[263] = (t226_tmp + t12_tmp) - t126_tmp;
  out1[264] = (((((((t91 + t251) + t252) + t253) + t254) - t165_tmp) - t271_tmp)
               - b_t271_tmp) - t212_tmp;
  out1[265] = t260;
  out1[266] = (((((((t115 + t158_tmp) + t261) + t262) + t263) - t154_tmp) -
                t275_tmp) - b_t275_tmp) - c_t275_tmp;
  out1[267] = (((((((-t118 + t217_tmp) + t264) + t265) + t266) + t267) -
                t199_tmp) - t277_tmp) - t75;
  out1[268] = t268;
  out1[269] = -t11 + t128_tmp;
  out1[270] = t270;
  memset(&out1[271], 0, 99U * sizeof(real_T));
  out1[370] = (((((t121 + t79) + t26) + t99) - t295_tmp) - t427) - t299_tmp;
  out1[371] = (((((t104 + t123) + t93) - t424) - t419) - t418) - t29;
  out1[372] = (((((t103 + t302_tmp) + t32) - t98) - t96) - t83) - t412;
  out1[373] = t308;
  out1[374] = 0.0;
  out1[375] = 0.0;
  out1[376] = 0.0;
  out1[377] = ((t139 - t81) - t36) - t309_tmp;
  out1[378] = ((t141 + t310) + t311) - in2[55] * in2[60] * in2[61] * t13 * t129 *
    2.0;
  out1[379] = t315;
  out1[380] = ((t57 - t27) - t340_tmp) - t74_tmp;
  memset(&out1[381], 0, 95U * sizeof(real_T));
  out1[476] = (((((t90 + t350) + t351) + t58) - t119_tmp) - t307_tmp) - t80;
  out1[477] = (((((t55 + t56) + t59) + t358_tmp) - t302_tmp) - t78) - t412;
  out1[478] = (((((t104 + t29) + t54) - t82) - t30) - t52) - t354_tmp;
  out1[479] = (((((t121 + t295_tmp) + t16) - t50) - t28) - t33) - t379_tmp;
  out1[480] = 0.0;
  out1[481] = 0.0;
  out1[482] = 0.0;
  out1[483] = ((t134 - t77) - t31) - t57;
  out1[484] = ((t360_tmp - t48) - t337_tmp) - t34;
  out1[485] = ((t312 + t35) + t25) - in2[53] * in2[61] * in2[62] * t13 * t129 *
    2.0;
  out1[486] = t366;
  memset(&out1[487], 0, 95U * sizeof(real_T));
  t82 = t35_tmp * t67 * 2.0;
  out1[582] = (((((t103 + t399) + t64) + t401) - t302_tmp) - t358_tmp) - t82;
  t30 = t81_tmp * t62 * 2.0;
  t80 = c_t20_tmp * t88 * 2.0;
  t48 = in2[54] * t3 * t65 * 2.0;
  out1[583] = (((((t90 + t119_tmp) + t402) - t48) - t80) - t30) - t329_tmp;
  t34 = t86_tmp * t62 * 2.0;
  out1[584] = (((((t299_tmp + t403) + t404) + t405) - t295_tmp) - t34) -
    t379_tmp;
  t78 = t112_tmp * t67 * 2.0;
  t31 = t20_tmp * t120 * 2.0;
  t28 = in2[52] * t5 * t65 * 2.0;
  out1[585] = (((((t104 - t123) + t354_tmp) + t406) - t28) - t31) - t78;
  out1[586] = 0.0;
  out1[587] = 0.0;
  out1[588] = 0.0;
  t33 = b_t20_tmp * t130 * 2.0;
  t50 = t334_tmp * in2[62] * t13 * t129 * 2.0;
  out1[589] = ((t135 - t33) - t50) - t360_tmp;
  out1[590] = ((t134 + t105) + t132) - t340_tmp;
  t77 = t23_tmp * t136 * 2.0;
  t6 = t141_tmp * in2[61] * t13 * t129 * 2.0;
  out1[591] = ((t309_tmp - t77) - t389_tmp) - t6;
  out1[592] = t138;
  memset(&out1[593], 0, 43U * sizeof(real_T));
  t412 = (((((t103 - t302_tmp) - t358_tmp) + t399) + t64) + t401) - t82;
  t418 = (((((-t90 - t119_tmp) + t329_tmp) - t402) + t30) + t80) + t48;
  t419 = (((((-t295_tmp + t299_tmp) - t379_tmp) + t403) + t404) + t405) - t34;
  t424 = (((((-t104 + t123) - t354_tmp) - t406) + t78) + t31) + t28;
  t427 = ((-t135 + t360_tmp) + t33) + t50;
  t32 = ((t134 - t340_tmp) + t105) + t132;
  t93 = ((-t309_tmp + t389_tmp) + t77) + t6;
  st.site = &s_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  t29 = muDoubleScalarPower(muDoubleScalarAbs(((((((t412 * in2[164] + t419 *
    in2[166]) + t32 * in2[172]) + t138 * in2[174]) - t418 * in2[165]) - t424 *
    in2[167]) - t427 * in2[171]) - t93 * in2[173]), in1[1] - 1.0);
  t33 = t143 * t148;
  t50 = t143 * (t147 - t149);
  t28 = t145 * t153;
  st.site = &t_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  st.site = &t_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  out2[0] = in1[0] * (((((((t145 * t148 + t143 * t151) - t143 * t153) + t145 *
    (t145 / 25.0 - t149)) - t20_tmp * t20) - b_t20_tmp * t23) + c_t20_tmp * t40)
                      - t23_tmp * t44) * -0.00026666666666666668;
  out2[1] = in1[0] * (((((t143 * t143 * 2.635724972E-14 + t145 * t145 *
    2.635724972E-14) - t20_tmp * t23) + b_t20_tmp * t20) - t23_tmp * t40) -
                      c_t20_tmp * t44) * -0.00026666666666666668;
  t6 = t145 * t151;
  out2[2] = in1[0] * (((((((t33 + t50) + t28) - t6) + c_t20_tmp * t20) - t23_tmp
                        * t23) + t20_tmp * t40) + b_t20_tmp * t44) * 0.0008;
  out2[3] = in1[0] * (((t20_tmp * t60 * 2.0 + b_t20_tmp * t62 * 2.0) - t23_tmp *
                       t67 * 2.0) - c_t20_tmp * t70 * 2.0) *
    4.2666666666666668E-11;
  out2[4] = in1[0] * (((t20_tmp * t62 * 2.0 - b_t20_tmp * t60 * 2.0) - c_t20_tmp
                       * t67 * 2.0) + t23_tmp * t70 * 2.0) *
    1.421066666666666E-8;
  out2[5] = in1[0] * (((c_t20_tmp * t60 * 2.0 - t23_tmp * t62 * 2.0) + t20_tmp *
                       t70 * 2.0) - b_t20_tmp * t67 * 2.0) * 4.75111111111111E-9;
  t80 = in1[2] * t177 * t196;
  t82 = in1[2] * t179 * t196;
  t30 = in1[2] * t178 * t196;
  t52 = -in1[2] * t171 * t196;
  out3[0] = ((((((((t52 * in2[166] + t80 * in2[162]) + t82 * in2[161]) - t30 *
                  in2[163]) - in1[2] * t176 * t196 * in2[167]) - in1[2] * t180 *
                t196 * in2[164]) - t80 * in2[169]) - t82 * in2[168]) - in1[2] *
             t182 * t196 * in2[165]) + t30 * in2[170];
  t24 = in1[2] * t224 * t240;
  t25 = in1[2] * t226 * t240;
  t16 = -in1[2] * t225 * t240;
  t35 = in1[2] * t225 * t240;
  out3[1] = ((((((((t16 * in2[161] + t24 * in2[163]) + t25 * in2[162]) - in1[2] *
                  t223 * t240 * in2[167]) - in1[2] * t227 * t240 * in2[164]) +
                t35 * in2[168]) - t24 * in2[170]) - in1[2] * t229 * t240 * in2
              [165]) - t25 * in2[169]) - in1[2] * t231 * t240 * in2[166];
  t27 = in1[2] * t268 * t284;
  t74_tmp = in1[2] * t269 * t284;
  t350 = in1[2] * t270 * t284;
  t351 = -in1[2] * t260 * t284;
  out3[2] = ((((((((t351 * in2[165] + t27 * in2[161]) - t74_tmp * in2[162]) +
                  t350 * in2[163]) - in1[2] * t271 * t284 * in2[164]) - t27 *
                in2[168]) + t74_tmp * in2[169]) - t350 * in2[170]) - in1[2] *
             t275 * t284 * in2[166]) - in1[2] * t277 * t284 * in2[167];
  t58 = in1[3] * t323 * t345;
  t54 = in1[3] * t328 * t345;
  t55 = -in1[3] * t308 * t345;
  t56 = in1[3] * t334 * t345;
  t59 = in1[3] * t342 * t345;
  out3[3] = ((((((t55 * in2[167] - in1[3] * t317 * t345 * in2[164]) - in1[3] *
                 t315 * t345 * in2[173]) + t58 * in2[165]) + t54 * in2[166]) +
              t56 * in2[171]) - in1[3] * t335 * t345 * in2[172]) + t59 * in2[174];
  t57 = -in1[3] * t367 * t393;
  t98 = in1[3] * t373 * t393;
  t96 = in1[3] * t380 * t393;
  t83 = in1[3] * t383 * t393;
  t81 = in1[3] * t386 * t393;
  out3[4] = ((((((t57 * in2[164] + t98 * in2[166]) - in1[3] * t374 * t393 * in2
                 [165]) - in1[3] * t366 * t393 * in2[174]) + t96 * in2[167]) +
              t83 * in2[171]) + t81 * in2[172]) - in1[3] * t387 * t393 * in2[173];
  t36 = -in1[3] * t412 * t29;
  t75 = in1[3] * t418 * t29;
  t79 = in1[3] * t424 * t29;
  t26 = in1[3] * t427 * t29;
  t99 = in1[3] * t93 * t29;
  out3[5] = ((((((t36 * in2[164] + t75 * in2[165]) - in1[3] * t138 * t29 * in2
                 [174]) - in1[3] * t419 * t29 * in2[166]) + t79 * in2[167]) +
              t26 * in2[171]) - in1[3] * t32 * t29 * in2[172]) + t99 * in2[173];
  for (i = 0; i < 6; i++) {
    out4[i] = 0.0;
  }

  st.site = &u_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  st.site = &u_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  st.site = &u_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  t78 = (t14 * t14 + t15 * t15) + t17 * t17;
  st.site = &u_emlrtRSI;
  b_sqrt(&st, &t78);
  *out5 = (((-t33 - t50) - t28) + t78) + t6;
  t78 = in1[0] * t178 * 0.00026666666666666668;
  t48 = in1[0] * t225 * 0.00026666666666666668;
  t34 = in1[0] * t269 * 0.0008;
  memset(&out6[0], 0, 294U * sizeof(real_T));
  t31 = in1[0] * t179;
  out6[294] = t31 * -0.00026666666666666668;
  out6[295] = t48;
  t77 = in1[0] * t268;
  out6[296] = t77 * -0.0008;
  out6[297] = 0.0;
  out6[298] = 0.0;
  out6[299] = 0.0;
  t33 = in1[0] * t177;
  out6[300] = t33 * -0.00026666666666666668;
  t28 = in1[0] * t226;
  out6[301] = t28 * -0.00026666666666666668;
  out6[302] = t34;
  out6[303] = 0.0;
  out6[304] = 0.0;
  out6[305] = 0.0;
  out6[306] = t78;
  t50 = in1[0] * t224;
  out6[307] = t50 * -0.00026666666666666668;
  t6 = in1[0] * t270;
  out6[308] = t6 * -0.0008;
  out6[309] = 0.0;
  out6[310] = 0.0;
  out6[311] = 0.0;
  out6[312] = in1[0] * t180 * 0.00026666666666666668;
  out6[313] = in1[0] * t227 * 0.00026666666666666668;
  out6[314] = in1[0] * t271 * 0.0008;
  out6[315] = in1[0] * t317 * 4.2666666666666668E-11;
  out6[316] = in1[0] * t367 * 1.421066666666666E-8;
  out6[317] = in1[0] * t412 * 4.75111111111111E-9;
  out6[318] = in1[0] * t182 * 0.00026666666666666668;
  out6[319] = in1[0] * t229 * 0.00026666666666666668;
  out6[320] = in1[0] * t260 * 0.0008;
  out6[321] = in1[0] * t323 * -4.2666666666666668E-11;
  out6[322] = in1[0] * t374 * 1.421066666666666E-8;
  out6[323] = in1[0] * t418 * -4.75111111111111E-9;
  out6[324] = in1[0] * t171 * 0.00026666666666666668;
  out6[325] = in1[0] * t231 * 0.00026666666666666668;
  out6[326] = in1[0] * t275 * 0.0008;
  out6[327] = in1[0] * t328 * -4.2666666666666668E-11;
  out6[328] = in1[0] * t373 * -1.421066666666666E-8;
  out6[329] = in1[0] * t419 * 4.75111111111111E-9;
  out6[330] = in1[0] * t176 * 0.00026666666666666668;
  out6[331] = in1[0] * t223 * 0.00026666666666666668;
  out6[332] = in1[0] * t277 * 0.0008;
  out6[333] = in1[0] * t308 * 4.2666666666666668E-11;
  out6[334] = in1[0] * t380 * -1.421066666666666E-8;
  out6[335] = in1[0] * t424 * -4.75111111111111E-9;
  out6[336] = t31 * 0.00026666666666666668;
  out6[337] = -t48;
  out6[338] = t77 * 0.0008;
  out6[339] = 0.0;
  out6[340] = 0.0;
  out6[341] = 0.0;
  out6[342] = t33 * 0.00026666666666666668;
  out6[343] = t28 * 0.00026666666666666668;
  out6[344] = -t34;
  out6[345] = 0.0;
  out6[346] = 0.0;
  out6[347] = 0.0;
  out6[348] = -t78;
  out6[349] = t50 * 0.00026666666666666668;
  out6[350] = t6 * 0.0008;
  out6[351] = 0.0;
  out6[352] = 0.0;
  out6[353] = 0.0;
  out6[354] = 0.0;
  out6[355] = 0.0;
  out6[356] = 0.0;
  out6[357] = in1[0] * t334 * -4.2666666666666668E-11;
  out6[358] = in1[0] * t383 * -1.421066666666666E-8;
  out6[359] = in1[0] * t427 * -4.75111111111111E-9;
  out6[360] = 0.0;
  out6[361] = 0.0;
  out6[362] = 0.0;
  out6[363] = in1[0] * t335 * 4.2666666666666668E-11;
  out6[364] = in1[0] * t386 * -1.421066666666666E-8;
  out6[365] = in1[0] * t32 * 4.75111111111111E-9;
  out6[366] = 0.0;
  out6[367] = 0.0;
  out6[368] = 0.0;
  out6[369] = in1[0] * t315 * 4.2666666666666668E-11;
  out6[370] = in1[0] * t387 * 1.421066666666666E-8;
  out6[371] = in1[0] * t93 * -4.75111111111111E-9;
  out6[372] = 0.0;
  out6[373] = 0.0;
  out6[374] = 0.0;
  out6[375] = in1[0] * t342 * -4.2666666666666668E-11;
  out6[376] = in1[0] * t366 * 1.421066666666666E-8;
  out6[377] = in1[0] * t138 * 4.75111111111111E-9;
  memset(&out6[378], 0, 258U * sizeof(real_T));
  memset(&out7[0], 0, 294U * sizeof(real_T));
  out7[294] = t82;
  out7[295] = t16;
  out7[296] = t27;
  out7[297] = 0.0;
  out7[298] = 0.0;
  out7[299] = 0.0;
  out7[300] = t80;
  out7[301] = t25;
  out7[302] = -in1[2] * t269 * t284;
  out7[303] = 0.0;
  out7[304] = 0.0;
  out7[305] = 0.0;
  out7[306] = -in1[2] * t178 * t196;
  out7[307] = t24;
  out7[308] = t350;
  out7[309] = 0.0;
  out7[310] = 0.0;
  out7[311] = 0.0;
  out7[312] = -in1[2] * t180 * t196;
  out7[313] = -in1[2] * t227 * t240;
  out7[314] = -in1[2] * t271 * t284;
  out7[315] = -in1[3] * t317 * t345;
  out7[316] = t57;
  out7[317] = t36;
  out7[318] = -in1[2] * t182 * t196;
  out7[319] = -in1[2] * t229 * t240;
  out7[320] = t351;
  out7[321] = t58;
  out7[322] = -in1[3] * t374 * t393;
  out7[323] = t75;
  out7[324] = t52;
  out7[325] = -in1[2] * t231 * t240;
  out7[326] = -in1[2] * t275 * t284;
  out7[327] = t54;
  out7[328] = t98;
  out7[329] = -in1[3] * t419 * t29;
  out7[330] = -in1[2] * t176 * t196;
  out7[331] = -in1[2] * t223 * t240;
  out7[332] = -in1[2] * t277 * t284;
  out7[333] = t55;
  out7[334] = t96;
  out7[335] = t79;
  out7[336] = -t82;
  out7[337] = t35;
  out7[338] = -t27;
  out7[339] = 0.0;
  out7[340] = 0.0;
  out7[341] = 0.0;
  out7[342] = -t80;
  out7[343] = -t25;
  out7[344] = t74_tmp;
  out7[345] = 0.0;
  out7[346] = 0.0;
  out7[347] = 0.0;
  out7[348] = t30;
  out7[349] = -t24;
  out7[350] = -t350;
  out7[351] = 0.0;
  out7[352] = 0.0;
  out7[353] = 0.0;
  out7[354] = 0.0;
  out7[355] = 0.0;
  out7[356] = 0.0;
  out7[357] = t56;
  out7[358] = t83;
  out7[359] = t26;
  out7[360] = 0.0;
  out7[361] = 0.0;
  out7[362] = 0.0;
  out7[363] = -in1[3] * t335 * t345;
  out7[364] = t81;
  out7[365] = -in1[3] * t32 * t29;
  out7[366] = 0.0;
  out7[367] = 0.0;
  out7[368] = 0.0;
  out7[369] = -in1[3] * t315 * t345;
  out7[370] = -in1[3] * t387 * t393;
  out7[371] = t99;
  out7[372] = 0.0;
  out7[373] = 0.0;
  out7[374] = 0.0;
  out7[375] = t59;
  out7[376] = -in1[3] * t366 * t393;
  out7[377] = -in1[3] * t138 * t29;
  memset(&out7[378], 0, 258U * sizeof(real_T));
  *out8 = 1.0;
}

/* End of code generation (sprdmpF119.c) */
