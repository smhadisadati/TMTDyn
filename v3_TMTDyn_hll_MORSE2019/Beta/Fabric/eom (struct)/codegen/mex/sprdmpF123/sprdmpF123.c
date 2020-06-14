/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sprdmpF123.c
 *
 * Code generation for function 'sprdmpF123'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "sprdmpF123.h"
#include "sqrt.h"
#include "error.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 41,    /* lineNo */
  "sprdmpF123",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF123.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 42,  /* lineNo */
  "sprdmpF123",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF123.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 43,  /* lineNo */
  "sprdmpF123",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF123.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 44,  /* lineNo */
  "sprdmpF123",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF123.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 52,  /* lineNo */
  "sprdmpF123",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF123.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 55,  /* lineNo */
  "sprdmpF123",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF123.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 93,  /* lineNo */
  "sprdmpF123",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF123.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 94,  /* lineNo */
  "sprdmpF123",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF123.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 95,  /* lineNo */
  "sprdmpF123",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF123.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 96,  /* lineNo */
  "sprdmpF123",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF123.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 98,  /* lineNo */
  "sprdmpF123",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF123.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 106, /* lineNo */
  "sprdmpF123",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF123.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 168, /* lineNo */
  "sprdmpF123",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF123.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 190, /* lineNo */
  "sprdmpF123",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF123.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 191, /* lineNo */
  "sprdmpF123",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF123.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 242, /* lineNo */
  "sprdmpF123",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF123.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 288, /* lineNo */
  "sprdmpF123",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF123.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 332, /* lineNo */
  "sprdmpF123",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF123.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 387, /* lineNo */
  "sprdmpF123",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF123.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 436, /* lineNo */
  "sprdmpF123",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF123.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 481, /* lineNo */
  "sprdmpF123",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF123.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 493, /* lineNo */
  "sprdmpF123",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF123.m"/* pathName */
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
void sprdmpF123(const emlrtStack *sp, const real_T in1[6], const real_T in2[224],
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
  real_T t404;
  real_T t50;
  real_T t26;
  real_T t27;
  real_T t28;
  real_T t350;
  real_T t48;
  real_T t401;
  real_T t29;
  real_T t30;
  real_T t403;
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
  real_T t349;
  real_T t405;
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
  real_T t400;
  real_T t96;
  real_T t402;
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
  real_T t151;
  real_T t152;
  real_T t153_tmp;
  real_T t154;
  real_T t155;
  real_T t156;
  real_T t157_tmp;
  real_T t158;
  real_T t163_tmp;
  real_T t164_tmp;
  real_T t170;
  real_T t174_tmp;
  real_T t175;
  real_T t176;
  real_T t177;
  real_T t178;
  real_T t179_tmp;
  real_T b_t179_tmp;
  real_T t179;
  real_T t198_tmp;
  real_T t181_tmp;
  real_T b_t181_tmp;
  real_T c_t181_tmp;
  real_T t181;
  real_T t195;
  real_T t204;
  real_T t205;
  real_T t206;
  real_T t207;
  real_T t208;
  real_T t209;
  real_T t210;
  real_T t211_tmp;
  real_T t212;
  real_T t213;
  real_T t214;
  real_T t215;
  real_T t216_tmp;
  real_T t222;
  real_T t223;
  real_T t224;
  real_T t225_tmp;
  real_T t225;
  real_T t226_tmp;
  real_T b_t226_tmp;
  real_T t226;
  real_T t228_tmp;
  real_T b_t228_tmp;
  real_T c_t228_tmp;
  real_T t228;
  real_T t230_tmp;
  real_T b_t230_tmp;
  real_T t230;
  real_T t239;
  real_T t250;
  real_T t251;
  real_T t252;
  real_T t253;
  real_T t259;
  real_T t260;
  real_T t261;
  real_T t262;
  real_T t263;
  real_T t264;
  real_T t265;
  real_T t266;
  real_T t267;
  real_T t268;
  real_T t269_tmp;
  real_T t269;
  real_T t270_tmp;
  real_T b_t270_tmp;
  real_T t270;
  real_T t274_tmp;
  real_T b_t274_tmp;
  real_T c_t274_tmp;
  real_T t274;
  real_T t276_tmp;
  real_T t276;
  real_T t283;
  real_T t294_tmp;
  real_T t298_tmp;
  real_T t301_tmp;
  real_T t306_tmp;
  real_T t328_tmp;
  real_T t307;
  real_T t308_tmp;
  real_T t309;
  real_T t310;
  real_T t311;
  real_T t336_tmp;
  real_T t314;
  real_T t316;
  real_T t426;
  real_T t423;
  real_T t418;
  real_T t322;
  real_T t417;
  real_T t411;
  real_T t327;
  real_T t333_tmp;
  real_T t333;
  real_T t334;
  real_T t339_tmp;
  real_T t341;
  real_T t344;
  real_T t353_tmp;
  real_T t355;
  real_T t357_tmp;
  real_T t359_tmp;
  real_T t388_tmp;
  real_T t365;
  real_T t366;
  real_T t372;
  real_T t373;
  real_T t378_tmp;
  real_T t379;
  real_T t382;
  real_T t385;
  real_T t386;
  real_T t392;
  real_T t398;
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

  /* SPRDMPF123 */
  /*     [OUT1,OUT2,OUT3,OUT4,OUT5,OUT6,OUT7,OUT8] = SPRDMPF123(IN1,IN2,S) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.2. */
  /*     06-Jul-2019 05:50:00 */
  st.site = &emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t2 = in2[52] * in2[52];
  st.site = &b_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t3 = in2[53] * in2[53];
  st.site = &c_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t4 = in2[54] * in2[54];
  st.site = &d_emlrtRSI;
  b_st.site = &w_emlrtRSI;
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
  t14 = in2[49] - in2[70];
  t15 = in2[50] - in2[71];
  st.site = &f_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  if (t6 < 0.0) {
    c_st.site = &x_emlrtRSI;
    error(&c_st);
  }

  t16 = 1.0 / muDoubleScalarPower(t6, 1.5);
  t17 = in2[51] - in2[72];
  t20_tmp = in2[52] * t13;
  b_t20_tmp = in2[55] * t13;
  c_t20_tmp = in2[54] * t13;
  t20 = (t20_tmp * t14 + b_t20_tmp * t15) - c_t20_tmp * t17;
  t23_tmp = in2[53] * t13;
  t23 = (t20_tmp * t15 + t23_tmp * t17) - b_t20_tmp * t14;
  t24 = t13 * t15;
  t25 = t77 * t14 * t16;
  t404 = t33 * t16;
  t50 = t404 * t17;
  t26 = ((t24 + t25) - t2 * t15 * t16) - t50;
  t27 = t13 * t17;
  t28 = t33 * t15 * t16;
  t350 = in2[52] * in2[54];
  t48 = t350 * t14 * t16;
  t401 = t2 * t16;
  t29 = ((t27 + t28) - t401 * t17) - t48;
  t30 = t13 * t14;
  t403 = t350 * t16;
  t31 = t403 * t17;
  t52 = t77 * t15 * t16;
  t32 = ((t30 + t31) - t2 * t14 * t16) - t52;
  t33 = t33 * t14 * t16;
  t34 = t350 * t15 * t16;
  t35_tmp = t77 * t16;
  t35 = t35_tmp * t17;
  t36 = (t33 + t34) + t35;
  t40 = (c_t20_tmp * t14 + t20_tmp * t17) - t23_tmp * t15;
  t44 = (t23_tmp * t14 + c_t20_tmp * t15) + b_t20_tmp * t17;
  st.site = &g_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t54 = in2[73] * in2[73];
  st.site = &h_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t55 = in2[74] * in2[74];
  st.site = &i_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t56 = in2[75] * in2[75];
  st.site = &j_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t57 = in2[76] * in2[76];
  t58 = ((t54 + t55) + t56) + t57;
  t78 = t58;
  st.site = &k_emlrtRSI;
  b_sqrt(&st, &t78);
  t59 = 1.0 / t78;
  t60 = t23_tmp - in2[74] * t59;
  t62 = c_t20_tmp - in2[75] * t59;
  t64 = t13 - t401;
  st.site = &l_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t65 = 1.0 / (t6 * t6);
  t67 = t20_tmp - in2[73] * t59;
  t70 = b_t20_tmp - in2[76] * t59;
  t74_tmp = in2[53] * in2[54];
  t6 = t74_tmp * t14 * t16;
  t75 = ((t24 + t50) + t6) - t3 * t15 * t16;
  t77 = t74_tmp * t15 * t16;
  t349 = in2[53] * in2[55];
  t405 = t349 * t16;
  t78 = t405 * t17;
  t79 = ((-t30 + t3 * t14 * t16) + t77) + t78;
  t80 = t349 * t14 * t16;
  t81_tmp = t3 * t16;
  t81 = ((t27 - t28) + t80) - t81_tmp * t17;
  t82 = t349 * t15 * t16;
  t86_tmp = t74_tmp * t16;
  t50 = t86_tmp * t17;
  t83 = (t33 + t82) - t50;
  t87 = t404 * t40;
  t88 = t13 - t81_tmp;
  t90 = t404 * t70 * 2.0;
  t91 = t403 * t20;
  t92 = t86_tmp * t44;
  t93 = ((t30 - t31) + t77) - t4 * t14 * t16;
  t77 = in2[54] * in2[55];
  t400 = t77 * t16;
  t28 = t400 * t17;
  t96 = ((-t24 + t6) + t4 * t15 * t16) + t28;
  t6 = t77 * t15 * t16;
  t402 = t4 * t16;
  t48 = ((t27 + t48) + t6) - t402 * t17;
  t33 = t77 * t14 * t16;
  t99 = (t34 + t50) - t33;
  t103 = t403 * t60 * 2.0;
  t104 = t13 * t67 * 2.0;
  t105 = t13 - t402;
  t107_tmp = t13 * t23;
  t31 = t405 * t44;
  t78 = ((t30 + t52) + t78) - t5 * t14 * t16;
  t34 = ((t24 - t25) + t28) - t5 * t15 * t16;
  t112_tmp = t5 * t16;
  t28 = ((-t27 + t80) + t6) + t112_tmp * t17;
  t50 = (t35 - t82) + t33;
  t114 = t35_tmp * t23;
  t115 = t400 * t44;
  t118 = t405 * t23;
  t119_tmp = t13 * t62 * 2.0;
  t120 = t13 - t112_tmp;
  t121 = t35_tmp * t62 * 2.0;
  t123 = t405 * t62 * 2.0;
  t124_tmp = t350 * t7;
  t124 = t124_tmp * 2.0;
  t125_tmp = t74_tmp * t7 * 2.0;
  t126_tmp = t2 * t7;
  t127_tmp = t349 * t7 * 2.0;
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
  t134_tmp = in2[55] * in2[73];
  t134 = t134_tmp * in2[74] * t13 * t129 * 2.0;
  t33 = in2[53] * in2[73];
  t135 = t33 * in2[75] * t13 * t129 * 2.0;
  t136 = t59 - t56 * t129;
  t138 = t59 - t57 * t129;
  t77 = in2[54] * in2[73];
  t139 = t77 * in2[76] * t13 * t129 * 2.0;
  t141_tmp = in2[54] * in2[74];
  t141 = t141_tmp * in2[76] * t13 * t129 * 2.0;
  t6 = in1[4] / 2.0;
  t143 = muDoubleScalarCos(t6);
  t144 = muDoubleScalarSin(t6);
  t147 = t143 * 0.162 - t144 / 25.0;
  t150 = t143 / 25.0 + t144 * 0.162;
  st.site = &n_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t151 = t143 * t143;
  st.site = &o_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t152 = t144 * t144;
  t153_tmp = t13 * t20;
  t154 = c_t20_tmp * t29;
  t155 = t23_tmp * t36;
  t156 = t401 * t20;
  t157_tmp = t403 * t40;
  t158 = t404 * t44;
  t163_tmp = t86_tmp * t40;
  t164_tmp = t13 * t40;
  t170 = (((((((t91 + t92) + t164_tmp) + c_t20_tmp * t93) + t20_tmp * t48) +
            t23_tmp * t96) + b_t20_tmp * t99) + t400 * t23) - t402 * t40;
  t174_tmp = t35_tmp * t20;
  t175 = (((((((-t107_tmp + t31) + b_t20_tmp * t78) + t23_tmp * t28) + t112_tmp *
             t23) + t174_tmp) - t20_tmp * t34) - c_t20_tmp * t50) - t400 * t40;
  t176 = t8 + t125_tmp;
  t177 = t124 - t127_tmp;
  t178 = ((-t9 - t10) + t12_tmp) + t126_tmp;
  t179_tmp = b_t20_tmp * t26;
  b_t179_tmp = t20_tmp * t32;
  t179 = (((((((t114 - t153_tmp) + t154) + t155) + t156) - t157_tmp) + t158) -
          b_t179_tmp) - t179_tmp;
  t198_tmp = t13 * t44;
  t181_tmp = (((t118 + t23_tmp * t79) + t20_tmp * t83) + t81_tmp * t44) + t404 *
    t20;
  b_t181_tmp = c_t20_tmp * t75;
  c_t181_tmp = b_t20_tmp * t81;
  t181 = (((t181_tmp - t163_tmp) - t198_tmp) - b_t181_tmp) - c_t181_tmp;
  st.site = &p_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t195 = muDoubleScalarPower(muDoubleScalarAbs(((((((((t179 * in2[164] + t181 *
    in2[165]) + t170 * in2[166]) + t175 * in2[167]) + t177 * in2[163]) + t176 *
    in2[183]) + t178 * in2[182]) - t176 * in2[162]) - t177 * in2[184]) - t178 *
    in2[161]), in1[1] - 1.0);
  t204 = b_t20_tmp * t32;
  t205 = c_t20_tmp * t36;
  t206 = t401 * t23;
  t207 = t403 * t44;
  t208 = t23_tmp * t75;
  t209 = c_t20_tmp * t79;
  t210 = t81_tmp * t40;
  t211_tmp = t404 * t23;
  t212 = c_t20_tmp * t96;
  t213 = t20_tmp * t99;
  t214 = t402 * t44;
  t215 = t403 * t23;
  t216_tmp = t400 * t20;
  t222 = (((((((t114 + t115) + t153_tmp) + t20_tmp * t78) + b_t20_tmp * t34) +
            c_t20_tmp * t28) + t23_tmp * t50) + t405 * t40) - t112_tmp * t20;
  t223 = t11 + t128_tmp;
  t224 = t8 - t125_tmp;
  t225_tmp = t9 - t10;
  t225 = (t225_tmp - t12_tmp) + t126_tmp;
  t226_tmp = t20_tmp * t26;
  b_t226_tmp = t23_tmp * t29;
  t226 = (((((((t87 - t107_tmp) - t174_tmp) + t204) + t205) + t206) + t207) -
          t226_tmp) - b_t226_tmp;
  t228_tmp = t20_tmp * t81;
  b_t228_tmp = b_t20_tmp * t83;
  c_t228_tmp = t405 * t20;
  t228 = (((((((t92 - t164_tmp) + t208) + t209) + t210) + t211_tmp) - t228_tmp)
          - b_t228_tmp) - c_t228_tmp;
  t230_tmp = t23_tmp * t93;
  b_t230_tmp = b_t20_tmp * t48;
  t230 = (((((((t163_tmp - t198_tmp) + t212) + t213) + t214) + t215) - t216_tmp)
          - t230_tmp) - b_t230_tmp;
  st.site = &q_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t239 = muDoubleScalarPower(muDoubleScalarAbs(((((((((t226 * in2[164] + t228 *
    in2[165]) + t230 * in2[166]) + t222 * in2[167]) + t224 * in2[161]) + t223 *
    in2[184]) + t225 * in2[183]) - t223 * in2[163]) - t224 * in2[182]) - t225 *
    in2[162]), in1[1] - 1.0);
  t250 = t23_tmp * t26;
  t251 = b_t20_tmp * t36;
  t252 = t401 * t40;
  t253 = t35_tmp * t44;
  t259 = (((((((t87 + t107_tmp) + t31) + t20_tmp * t75) + b_t20_tmp * t79) +
            t23_tmp * t81) + c_t20_tmp * t83) + t86_tmp * t20) - t81_tmp * t23;
  t260 = c_t20_tmp * t48;
  t261 = b_t20_tmp * t96;
  t262 = t402 * t20;
  t263 = b_t20_tmp * t28;
  t264 = t20_tmp * t50;
  t265 = t112_tmp * t44;
  t266 = t35_tmp * t40;
  t267 = t124 + t127_tmp;
  t268 = t11 - t128_tmp;
  t269_tmp = -t9 + t10;
  t269 = (t269_tmp - t12_tmp) + t126_tmp;
  t270_tmp = t20_tmp * t29;
  b_t270_tmp = c_t20_tmp * t32;
  t270 = (((((((t91 - t164_tmp) - t211_tmp) + t250) + t251) + t252) + t253) -
          t270_tmp) - b_t270_tmp;
  t274_tmp = t20_tmp * t93;
  b_t274_tmp = t23_tmp * t99;
  c_t274_tmp = t86_tmp * t23;
  t274 = (((((((t115 - t153_tmp) + t157_tmp) + t260) + t261) + t262) - t274_tmp)
          - b_t274_tmp) - c_t274_tmp;
  t276_tmp = t23_tmp * t78;
  t75 = c_t20_tmp * t34;
  t276 = (((((((-t118 - t198_tmp) + t216_tmp) + t263) + t264) + t265) + t266) -
          t276_tmp) - t75;
  st.site = &r_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t283 = muDoubleScalarPower(muDoubleScalarAbs(((((((((t270 * in2[164] + t259 *
    in2[165]) + t274 * in2[166]) + t276 * in2[167]) + t268 * in2[162]) + t267 *
    in2[182]) + t269 * in2[184]) - t267 * in2[161]) - t268 * in2[183]) - t269 *
    in2[163]), in1[1] - 1.0);
  t294_tmp = t13 * t60 * 2.0;
  t79 = t401 * t60 * 2.0;
  t26 = t23_tmp * t64 * 2.0;
  t99 = in2[53] * t2 * t65 * 2.0;
  t298_tmp = t403 * t70 * 2.0;
  t93 = t404 * t60 * 2.0;
  t29 = t86_tmp * t70 * 2.0;
  t301_tmp = t13 * t70 * 2.0;
  t32 = t400 * t62 * 2.0;
  t306_tmp = t35_tmp * t60 * 2.0;
  t328_tmp = t405 * t67 * 2.0;
  t307 = (((((-t119_tmp + t112_tmp * t62 * 2.0) + c_t20_tmp * t120 * 2.0) + in2
            [54] * t5 * t65 * 2.0) + t306_tmp) - t328_tmp) - t400 * t70 * 2.0;
  t308_tmp = t134_tmp * in2[75] * t13 * t129 * 2.0;
  t309 = t20_tmp * t132 * 2.0;
  t310 = t33 * in2[74] * t13 * t129 * 2.0;
  t50 = in2[55] * in2[74];
  t311 = t50 * in2[75] * t13 * t129 * 2.0;
  t6 = in2[52] * in2[74];
  t336_tmp = t6 * in2[75] * t13 * t129 * 2.0;
  t314 = ((t135 + b_t20_tmp * t136 * 2.0) + in2[54] * in2[75] * in2[76] * t13 *
          t129 * 2.0) - t336_tmp;
  t59 = t33 * in2[76] * t13 * t129 * 2.0;
  t57 = t404 * t67 * 2.0;
  t316 = (((((t121 - t294_tmp) + t79) + t26) + t99) - t298_tmp) - t57;
  t426 = in2[52] * t3 * t65 * 2.0;
  t423 = t20_tmp * t88 * 2.0;
  t418 = t81_tmp * t67 * 2.0;
  t322 = (((((-t104 - t123) - t93) + t29) + t418) + t423) + t426;
  t417 = t86_tmp * t67 * 2.0;
  t411 = in2[55] * t4 * t65 * 2.0;
  t96 = b_t20_tmp * t105 * 2.0;
  t83 = t402 * t70 * 2.0;
  t327 = (((((-t103 - t301_tmp) - t32) + t83) + t96) + t411) + t417;
  t333_tmp = in2[52] * in2[73];
  t81 = t23_tmp * t130 * 2.0;
  t36 = t333_tmp * in2[74] * t13 * t129 * 2.0;
  t333 = ((-t139 + t308_tmp) + t81) + t36;
  t334 = ((t141 + t309) + t310) - t311;
  t339_tmp = t6 * in2[76] * t13 * t129 * 2.0;
  t27 = c_t20_tmp * t138 * 2.0;
  t74_tmp = in2[55] * in2[75] * in2[76] * t13 * t129 * 2.0;
  t341 = ((-t59 + t27) + t339_tmp) + t74_tmp;
  st.site = &s_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t344 = muDoubleScalarPower(muDoubleScalarAbs(((((((t316 * in2[164] + t307 *
    in2[167]) + t334 * in2[186]) + t314 * in2[187]) - t322 * in2[165]) - t327 *
    in2[166]) - t333 * in2[185]) - t341 * in2[188]), in1[1] - 1.0);
  t349 = t401 * t62 * 2.0;
  t350 = c_t20_tmp * t64 * 2.0;
  t58 = in2[54] * t2 * t65 * 2.0;
  t54 = t403 * t62 * 2.0;
  t353_tmp = t400 * t60 * 2.0;
  t55 = t81_tmp * t70 * 2.0;
  t355 = b_t20_tmp * t88 * 2.0;
  t56 = in2[55] * t3 * t65 * 2.0;
  t357_tmp = t404 * t62 * 2.0;
  t16 = t405 * t70 * 2.0;
  t359_tmp = t77 * in2[74] * t13 * t129 * 2.0;
  t35 = t20_tmp * t136 * 2.0;
  t25 = t77 * in2[75] * t13 * t129 * 2.0;
  t24 = in2[53] * in2[75] * in2[76] * t13 * t129 * 2.0;
  t388_tmp = in2[52] * in2[75] * in2[76] * t13 * t129 * 2.0;
  t365 = ((t139 + t23_tmp * t138 * 2.0) + t50 * in2[76] * t13 * t129 * 2.0) -
    t388_tmp;
  t80 = t403 * t67 * 2.0;
  t366 = (((((t90 - t119_tmp) - t306_tmp) + t349) + t350) + t58) - t80;
  t82 = in2[52] * t4 * t65 * 2.0;
  t30 = t20_tmp * t105 * 2.0;
  t52 = t402 * t67 * 2.0;
  t372 = (((((-t104 - t29) - t54) + t353_tmp) + t52) + t30) + t82;
  t78 = t405 * t60 * 2.0;
  t373 = (((((-t301_tmp - t417) + t55) + t355) + t56) + t357_tmp) - t78;
  t378_tmp = t400 * t67 * 2.0;
  t50 = in2[53] * t5 * t65 * 2.0;
  t28 = t23_tmp * t120 * 2.0;
  t33 = t112_tmp * t60 * 2.0;
  t379 = (((((-t121 - t294_tmp) - t16) + t33) + t28) + t50) + t378_tmp;
  t77 = c_t20_tmp * t130 * 2.0;
  t31 = t333_tmp * in2[75] * t13 * t129 * 2.0;
  t382 = ((-t134 + t59) + t77) + t31;
  t6 = in2[53] * in2[74];
  t48 = b_t20_tmp * t132 * 2.0;
  t34 = t6 * in2[76] * t13 * t129 * 2.0;
  t385 = ((t336_tmp - t359_tmp) + t48) + t34;
  t386 = ((t311 + t35) + t25) - t24;
  st.site = &t_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t392 = muDoubleScalarPower(muDoubleScalarAbs(((((((t366 * in2[164] + t373 *
    in2[165]) + t386 * in2[187]) + t365 * in2[188]) - t372 * in2[166]) - t379 *
    in2[167]) - t382 * in2[185]) - t385 * in2[186]), in1[1] - 1.0);
  t398 = t401 * t70 * 2.0;
  t64 = b_t20_tmp * t64 * 2.0;
  t400 = in2[55] * t2 * t65 * 2.0;
  t401 = t86_tmp * t60 * 2.0;
  t402 = t402 * t60 * 2.0;
  t403 = t23_tmp * t105 * 2.0;
  t404 = in2[53] * t4 * t65 * 2.0;
  t405 = t35_tmp * t70 * 2.0;
  t105 = c_t20_tmp * t132 * 2.0;
  t132 = t6 * in2[75] * t13 * t129 * 2.0;
  t138 = ((-t141 + t24) + t20_tmp * t138 * 2.0) + t134_tmp * in2[76] * t13 *
    t129 * 2.0;
  memset(&out1[0], 0, 49U * sizeof(real_T));
  out1[49] = ((t9 + t10) - t126_tmp) - t12_tmp;
  out1[50] = -t8 - t125_tmp;
  out1[51] = t124 - in2[53] * in2[55] * t7 * 2.0;
  out1[52] = (((((((t114 + t154) + t155) + t156) + t158) - t153_tmp) - t179_tmp)
              - b_t179_tmp) - t157_tmp;
  out1[53] = (((t181_tmp - t198_tmp) - b_t181_tmp) - c_t181_tmp) - t163_tmp;
  out1[54] = t170;
  out1[55] = t175;
  memset(&out1[56], 0, 14U * sizeof(real_T));
  out1[70] = t178;
  out1[71] = t176;
  out1[72] = -t124 + t127_tmp;
  memset(&out1[73], 0, 82U * sizeof(real_T));
  out1[155] = t8 - in2[53] * in2[54] * t7 * 2.0;
  out1[156] = (t269_tmp + t12_tmp) - t126_tmp;
  out1[157] = -t11 - t128_tmp;
  out1[158] = (((((((t87 + t204) + t205) + t206) + t207) - t107_tmp) - t226_tmp)
               - b_t226_tmp) - t174_tmp;
  out1[159] = (((((((t92 + t208) + t209) + t210) + t211_tmp) - t164_tmp) -
                t228_tmp) - b_t228_tmp) - c_t228_tmp;
  out1[160] = (((((((t163_tmp + t212) + t213) + t214) + t215) - t198_tmp) -
                t230_tmp) - b_t230_tmp) - t216_tmp;
  out1[161] = t222;
  memset(&out1[162], 0, 14U * sizeof(real_T));
  out1[176] = -t8 + t125_tmp;
  out1[177] = t225;
  out1[178] = t223;
  memset(&out1[179], 0, 82U * sizeof(real_T));
  out1[261] = t124_tmp * -2.0 - t127_tmp;
  out1[262] = t11 - in2[54] * in2[55] * t7 * 2.0;
  out1[263] = (t225_tmp + t12_tmp) - t126_tmp;
  out1[264] = (((((((t91 + t250) + t251) + t252) + t253) - t164_tmp) - t270_tmp)
               - b_t270_tmp) - t211_tmp;
  out1[265] = t259;
  out1[266] = (((((((t115 + t157_tmp) + t260) + t261) + t262) - t153_tmp) -
                t274_tmp) - b_t274_tmp) - c_t274_tmp;
  out1[267] = (((((((-t118 + t216_tmp) + t263) + t264) + t265) + t266) -
                t198_tmp) - t276_tmp) - t75;
  memset(&out1[268], 0, 14U * sizeof(real_T));
  out1[282] = t267;
  out1[283] = -t11 + t128_tmp;
  out1[284] = t269;
  memset(&out1[285], 0, 85U * sizeof(real_T));
  out1[370] = (((((t121 + t79) + t26) + t99) - t294_tmp) - t57) - t298_tmp;
  out1[371] = (((((t104 + t123) + t93) - t426) - t423) - t418) - t29;
  out1[372] = (((((t103 + t301_tmp) + t32) - t411) - t96) - t83) - t417;
  out1[373] = t307;
  memset(&out1[374], 0, 17U * sizeof(real_T));
  out1[391] = ((t139 - t81) - t36) - t308_tmp;
  out1[392] = ((t141 + t309) + t310) - in2[55] * in2[74] * in2[75] * t13 * t129 *
    2.0;
  out1[393] = t314;
  out1[394] = ((t59 - t27) - t339_tmp) - t74_tmp;
  memset(&out1[395], 0, 81U * sizeof(real_T));
  out1[476] = (((((t90 + t349) + t350) + t58) - t119_tmp) - t306_tmp) - t80;
  out1[477] = (((((t55 + t355) + t56) + t357_tmp) - t301_tmp) - t78) - t417;
  out1[478] = (((((t104 + t29) + t54) - t82) - t30) - t52) - t353_tmp;
  out1[479] = (((((t121 + t294_tmp) + t16) - t50) - t28) - t33) - t378_tmp;
  memset(&out1[480], 0, 17U * sizeof(real_T));
  out1[497] = ((t134 - t77) - t31) - t59;
  out1[498] = ((t359_tmp - t48) - t336_tmp) - t34;
  out1[499] = ((t311 + t35) + t25) - in2[53] * in2[75] * in2[76] * t13 * t129 *
    2.0;
  out1[500] = t365;
  memset(&out1[501], 0, 81U * sizeof(real_T));
  t82 = t35_tmp * t67 * 2.0;
  out1[582] = (((((t103 + t398) + t64) + t400) - t301_tmp) - t357_tmp) - t82;
  t30 = t81_tmp * t62 * 2.0;
  t80 = c_t20_tmp * t88 * 2.0;
  t48 = in2[54] * t3 * t65 * 2.0;
  out1[583] = (((((t90 + t119_tmp) + t401) - t48) - t80) - t30) - t328_tmp;
  t34 = t86_tmp * t62 * 2.0;
  out1[584] = (((((t298_tmp + t402) + t403) + t404) - t294_tmp) - t34) -
    t378_tmp;
  t78 = t112_tmp * t67 * 2.0;
  t31 = t20_tmp * t120 * 2.0;
  t28 = in2[52] * t5 * t65 * 2.0;
  out1[585] = (((((t104 - t123) + t353_tmp) + t405) - t28) - t31) - t78;
  memset(&out1[586], 0, 17U * sizeof(real_T));
  t33 = b_t20_tmp * t130 * 2.0;
  t50 = t333_tmp * in2[76] * t13 * t129 * 2.0;
  out1[603] = ((t135 - t33) - t50) - t359_tmp;
  out1[604] = ((t134 + t105) + t132) - t339_tmp;
  t77 = t23_tmp * t136 * 2.0;
  t6 = t141_tmp * in2[75] * t13 * t129 * 2.0;
  out1[605] = ((t308_tmp - t77) - t388_tmp) - t6;
  out1[606] = t138;
  memset(&out1[607], 0, 29U * sizeof(real_T));
  t411 = (((((t103 - t301_tmp) - t357_tmp) + t398) + t64) + t400) - t82;
  t417 = (((((-t90 - t119_tmp) + t328_tmp) - t401) + t30) + t80) + t48;
  t418 = (((((-t294_tmp + t298_tmp) - t378_tmp) + t402) + t403) + t404) - t34;
  t423 = (((((-t104 + t123) - t353_tmp) - t405) + t78) + t31) + t28;
  t426 = ((-t135 + t359_tmp) + t33) + t50;
  t355 = ((t134 - t339_tmp) + t105) + t132;
  t29 = ((-t308_tmp + t388_tmp) + t77) + t6;
  st.site = &u_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t32 = muDoubleScalarPower(muDoubleScalarAbs(((((((t411 * in2[164] + t418 *
    in2[166]) + t355 * in2[186]) + t138 * in2[188]) - t417 * in2[165]) - t423 *
    in2[167]) - t426 * in2[185]) - t29 * in2[187]), in1[1] - 1.0);
  t50 = t143 * t147;
  t28 = t152 * 0.162;
  out2[0] = in1[0] * ((((((t143 * t144 * 0.324 - t144 * t147) - t143 * t150) +
    t20_tmp * t20) + b_t20_tmp * t23) - c_t20_tmp * t40) + t23_tmp * t44) *
    0.00026666666666666668;
  out2[1] = in1[0] * (((((t151 * 0.02259459459505023 + t152 *
    0.02259459459505023) - t20_tmp * t23) + b_t20_tmp * t20) - t23_tmp * t40) -
                      c_t20_tmp * t44) * -0.00026666666666666668;
  t6 = t144 * t150;
  out2[2] = in1[0] * (((((((t151 * -0.162 + t50) + t28) - t6) + c_t20_tmp * t20)
                        - t23_tmp * t23) + t20_tmp * t40) + b_t20_tmp * t44) *
    0.0008;
  out2[3] = in1[0] * (((t20_tmp * t60 * 2.0 + b_t20_tmp * t62 * 2.0) - t23_tmp *
                       t67 * 2.0) - c_t20_tmp * t70 * 2.0) *
    4.2666666666666668E-11;
  out2[4] = in1[0] * (((t20_tmp * t62 * 2.0 - b_t20_tmp * t60 * 2.0) - c_t20_tmp
                       * t67 * 2.0) + t23_tmp * t70 * 2.0) *
    1.421066666666666E-8;
  out2[5] = in1[0] * (((c_t20_tmp * t60 * 2.0 - t23_tmp * t62 * 2.0) + t20_tmp *
                       t70 * 2.0) - b_t20_tmp * t67 * 2.0) * 4.75111111111111E-9;
  t80 = in1[2] * t176 * t195;
  t82 = in1[2] * t178 * t195;
  t30 = in1[2] * t177 * t195;
  t52 = -in1[2] * t170 * t195;
  out3[0] = ((((((((t52 * in2[166] + t80 * in2[162]) + t82 * in2[161]) - t30 *
                  in2[163]) - in1[2] * t175 * t195 * in2[167]) - in1[2] * t179 *
                t195 * in2[164]) - in1[2] * t181 * t195 * in2[165]) - t80 * in2
              [183]) - t82 * in2[182]) + t30 * in2[184];
  t24 = in1[2] * t223 * t239;
  t25 = in1[2] * t225 * t239;
  t16 = -in1[2] * t224 * t239;
  t35 = in1[2] * t224 * t239;
  out3[1] = ((((((((t16 * in2[161] + t24 * in2[163]) + t25 * in2[162]) - in1[2] *
                  t222 * t239 * in2[167]) - in1[2] * t226 * t239 * in2[164]) -
                in1[2] * t228 * t239 * in2[165]) - in1[2] * t230 * t239 * in2
               [166]) + t35 * in2[182]) - t24 * in2[184]) - t25 * in2[183];
  t27 = in1[2] * t267 * t283;
  t74_tmp = in1[2] * t268 * t283;
  t349 = in1[2] * t269 * t283;
  t350 = -in1[2] * t259 * t283;
  out3[2] = ((((((((t350 * in2[165] + t27 * in2[161]) - t74_tmp * in2[162]) +
                  t349 * in2[163]) - in1[2] * t270 * t283 * in2[164]) - in1[2] *
                t274 * t283 * in2[166]) - in1[2] * t276 * t283 * in2[167]) - t27
              * in2[182]) + t74_tmp * in2[183]) - t349 * in2[184];
  t58 = in1[3] * t322 * t344;
  t54 = in1[3] * t327 * t344;
  t55 = -in1[3] * t307 * t344;
  t56 = in1[3] * t333 * t344;
  t59 = in1[3] * t341 * t344;
  out3[3] = ((((((t55 * in2[167] - in1[3] * t316 * t344 * in2[164]) + t58 * in2
                 [165]) + t54 * in2[166]) - in1[3] * t314 * t344 * in2[187]) +
              t56 * in2[185]) - in1[3] * t334 * t344 * in2[186]) + t59 * in2[188];
  t57 = -in1[3] * t366 * t392;
  t96 = in1[3] * t372 * t392;
  t83 = in1[3] * t379 * t392;
  t81 = in1[3] * t382 * t392;
  t36 = in1[3] * t385 * t392;
  out3[4] = ((((((t57 * in2[164] + t96 * in2[166]) - in1[3] * t373 * t392 * in2
                 [165]) + t83 * in2[167]) - in1[3] * t365 * t392 * in2[188]) +
              t81 * in2[185]) + t36 * in2[186]) - in1[3] * t386 * t392 * in2[187];
  t75 = -in1[3] * t411 * t32;
  t79 = in1[3] * t417 * t32;
  t26 = in1[3] * t423 * t32;
  t99 = in1[3] * t426 * t32;
  t93 = in1[3] * t29 * t32;
  out3[5] = ((((((t75 * in2[164] + t79 * in2[165]) - in1[3] * t418 * t32 * in2
                 [166]) + t26 * in2[167]) - in1[3] * t138 * t32 * in2[188]) +
              t99 * in2[185]) - in1[3] * t355 * t32 * in2[186]) + t93 * in2[187];
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
  *out5 = (((t151 * 0.162 - t50) - t28) + t78) + t6;
  t78 = in1[0] * t177 * 0.00026666666666666668;
  t48 = in1[0] * t224 * 0.00026666666666666668;
  t34 = in1[0] * t268 * 0.0008;
  memset(&out6[0], 0, 294U * sizeof(real_T));
  t31 = in1[0] * t178;
  out6[294] = t31 * -0.00026666666666666668;
  out6[295] = t48;
  t77 = in1[0] * t267;
  out6[296] = t77 * -0.0008;
  out6[297] = 0.0;
  out6[298] = 0.0;
  out6[299] = 0.0;
  t33 = in1[0] * t176;
  out6[300] = t33 * -0.00026666666666666668;
  t28 = in1[0] * t225;
  out6[301] = t28 * -0.00026666666666666668;
  out6[302] = t34;
  out6[303] = 0.0;
  out6[304] = 0.0;
  out6[305] = 0.0;
  out6[306] = t78;
  t50 = in1[0] * t223;
  out6[307] = t50 * -0.00026666666666666668;
  t6 = in1[0] * t269;
  out6[308] = t6 * -0.0008;
  out6[309] = 0.0;
  out6[310] = 0.0;
  out6[311] = 0.0;
  out6[312] = in1[0] * t179 * 0.00026666666666666668;
  out6[313] = in1[0] * t226 * 0.00026666666666666668;
  out6[314] = in1[0] * t270 * 0.0008;
  out6[315] = in1[0] * t316 * 4.2666666666666668E-11;
  out6[316] = in1[0] * t366 * 1.421066666666666E-8;
  out6[317] = in1[0] * t411 * 4.75111111111111E-9;
  out6[318] = in1[0] * t181 * 0.00026666666666666668;
  out6[319] = in1[0] * t228 * 0.00026666666666666668;
  out6[320] = in1[0] * t259 * 0.0008;
  out6[321] = in1[0] * t322 * -4.2666666666666668E-11;
  out6[322] = in1[0] * t373 * 1.421066666666666E-8;
  out6[323] = in1[0] * t417 * -4.75111111111111E-9;
  out6[324] = in1[0] * t170 * 0.00026666666666666668;
  out6[325] = in1[0] * t230 * 0.00026666666666666668;
  out6[326] = in1[0] * t274 * 0.0008;
  out6[327] = in1[0] * t327 * -4.2666666666666668E-11;
  out6[328] = in1[0] * t372 * -1.421066666666666E-8;
  out6[329] = in1[0] * t418 * 4.75111111111111E-9;
  out6[330] = in1[0] * t175 * 0.00026666666666666668;
  out6[331] = in1[0] * t222 * 0.00026666666666666668;
  out6[332] = in1[0] * t276 * 0.0008;
  out6[333] = in1[0] * t307 * 4.2666666666666668E-11;
  out6[334] = in1[0] * t379 * -1.421066666666666E-8;
  out6[335] = in1[0] * t423 * -4.75111111111111E-9;
  memset(&out6[336], 0, 84U * sizeof(real_T));
  out6[420] = t31 * 0.00026666666666666668;
  out6[421] = -t48;
  out6[422] = t77 * 0.0008;
  out6[423] = 0.0;
  out6[424] = 0.0;
  out6[425] = 0.0;
  out6[426] = t33 * 0.00026666666666666668;
  out6[427] = t28 * 0.00026666666666666668;
  out6[428] = -t34;
  out6[429] = 0.0;
  out6[430] = 0.0;
  out6[431] = 0.0;
  out6[432] = -t78;
  out6[433] = t50 * 0.00026666666666666668;
  out6[434] = t6 * 0.0008;
  out6[435] = 0.0;
  out6[436] = 0.0;
  out6[437] = 0.0;
  out6[438] = 0.0;
  out6[439] = 0.0;
  out6[440] = 0.0;
  out6[441] = in1[0] * t333 * -4.2666666666666668E-11;
  out6[442] = in1[0] * t382 * -1.421066666666666E-8;
  out6[443] = in1[0] * t426 * -4.75111111111111E-9;
  out6[444] = 0.0;
  out6[445] = 0.0;
  out6[446] = 0.0;
  out6[447] = in1[0] * t334 * 4.2666666666666668E-11;
  out6[448] = in1[0] * t385 * -1.421066666666666E-8;
  out6[449] = in1[0] * t355 * 4.75111111111111E-9;
  out6[450] = 0.0;
  out6[451] = 0.0;
  out6[452] = 0.0;
  out6[453] = in1[0] * t314 * 4.2666666666666668E-11;
  out6[454] = in1[0] * t386 * 1.421066666666666E-8;
  out6[455] = in1[0] * t29 * -4.75111111111111E-9;
  out6[456] = 0.0;
  out6[457] = 0.0;
  out6[458] = 0.0;
  out6[459] = in1[0] * t341 * -4.2666666666666668E-11;
  out6[460] = in1[0] * t365 * 1.421066666666666E-8;
  out6[461] = in1[0] * t138 * 4.75111111111111E-9;
  memset(&out6[462], 0, 174U * sizeof(real_T));
  memset(&out7[0], 0, 294U * sizeof(real_T));
  out7[294] = t82;
  out7[295] = t16;
  out7[296] = t27;
  out7[297] = 0.0;
  out7[298] = 0.0;
  out7[299] = 0.0;
  out7[300] = t80;
  out7[301] = t25;
  out7[302] = -in1[2] * t268 * t283;
  out7[303] = 0.0;
  out7[304] = 0.0;
  out7[305] = 0.0;
  out7[306] = -in1[2] * t177 * t195;
  out7[307] = t24;
  out7[308] = t349;
  out7[309] = 0.0;
  out7[310] = 0.0;
  out7[311] = 0.0;
  out7[312] = -in1[2] * t179 * t195;
  out7[313] = -in1[2] * t226 * t239;
  out7[314] = -in1[2] * t270 * t283;
  out7[315] = -in1[3] * t316 * t344;
  out7[316] = t57;
  out7[317] = t75;
  out7[318] = -in1[2] * t181 * t195;
  out7[319] = -in1[2] * t228 * t239;
  out7[320] = t350;
  out7[321] = t58;
  out7[322] = -in1[3] * t373 * t392;
  out7[323] = t79;
  out7[324] = t52;
  out7[325] = -in1[2] * t230 * t239;
  out7[326] = -in1[2] * t274 * t283;
  out7[327] = t54;
  out7[328] = t96;
  out7[329] = -in1[3] * t418 * t32;
  out7[330] = -in1[2] * t175 * t195;
  out7[331] = -in1[2] * t222 * t239;
  out7[332] = -in1[2] * t276 * t283;
  out7[333] = t55;
  out7[334] = t83;
  out7[335] = t26;
  memset(&out7[336], 0, 84U * sizeof(real_T));
  out7[420] = -t82;
  out7[421] = t35;
  out7[422] = -t27;
  out7[423] = 0.0;
  out7[424] = 0.0;
  out7[425] = 0.0;
  out7[426] = -t80;
  out7[427] = -t25;
  out7[428] = t74_tmp;
  out7[429] = 0.0;
  out7[430] = 0.0;
  out7[431] = 0.0;
  out7[432] = t30;
  out7[433] = -t24;
  out7[434] = -t349;
  out7[435] = 0.0;
  out7[436] = 0.0;
  out7[437] = 0.0;
  out7[438] = 0.0;
  out7[439] = 0.0;
  out7[440] = 0.0;
  out7[441] = t56;
  out7[442] = t81;
  out7[443] = t99;
  out7[444] = 0.0;
  out7[445] = 0.0;
  out7[446] = 0.0;
  out7[447] = -in1[3] * t334 * t344;
  out7[448] = t36;
  out7[449] = -in1[3] * t355 * t32;
  out7[450] = 0.0;
  out7[451] = 0.0;
  out7[452] = 0.0;
  out7[453] = -in1[3] * t314 * t344;
  out7[454] = -in1[3] * t386 * t392;
  out7[455] = t93;
  out7[456] = 0.0;
  out7[457] = 0.0;
  out7[458] = 0.0;
  out7[459] = t59;
  out7[460] = -in1[3] * t365 * t392;
  out7[461] = -in1[3] * t138 * t32;
  memset(&out7[462], 0, 174U * sizeof(real_T));
  *out8 = 1.0;
}

/* End of code generation (sprdmpF123.c) */
