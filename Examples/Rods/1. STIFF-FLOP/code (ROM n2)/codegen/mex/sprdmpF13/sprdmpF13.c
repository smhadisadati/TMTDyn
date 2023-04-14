/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sprdmpF13.c
 *
 * Code generation for function 'sprdmpF13'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "sprdmpF13.h"
#include "sqrt.h"
#include "error.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 52,    /* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 62,  /* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 63,  /* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 64,  /* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 66,  /* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 86,  /* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 118, /* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 186, /* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 187, /* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 190, /* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 192, /* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 193, /* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 194, /* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 199, /* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 200, /* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 201, /* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 204, /* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 205, /* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 206, /* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 210, /* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 272, /* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 327, /* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 331, /* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 384, /* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 388, /* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 417,/* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 446,/* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo cb_emlrtRSI = { 477,/* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo db_emlrtRSI = { 478,/* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo eb_emlrtRSI = { 49, /* lineNo */
  "power",                             /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

static emlrtRSInfo fb_emlrtRSI = { 61, /* lineNo */
  "power",                             /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

/* Function Definitions */
void sprdmpF13(const emlrtStack *sp, const real_T in1[34], const real_T in2[24],
               real_T s, real_T out1[72], real_T out2[6], real_T out3[6], real_T
               out4[6], real_T out5[3], real_T out6[72], real_T out7[72], real_T
               *out8)
{
  real_T t3;
  real_T t77;
  real_T t87;
  real_T t2;
  real_T t137;
  real_T t141;
  real_T t4;
  real_T t5_tmp;
  real_T t233;
  real_T t5;
  real_T t8;
  real_T t11;
  real_T t14;
  real_T t15;
  real_T t16;
  real_T t17;
  real_T t18_tmp;
  real_T t393;
  real_T t18;
  real_T t379;
  real_T t19;
  real_T t20_tmp;
  real_T t402;
  real_T t20;
  real_T t383;
  real_T t21;
  real_T t22_tmp;
  real_T t22;
  real_T t23_tmp;
  real_T t23;
  real_T t24_tmp;
  real_T t24;
  real_T t25_tmp;
  real_T t25;
  real_T t26_tmp;
  real_T t26;
  real_T t27_tmp;
  real_T t27;
  real_T t28_tmp;
  real_T t28;
  real_T t376;
  real_T t29;
  real_T t32;
  real_T t35;
  real_T t36;
  real_T t39;
  real_T t40;
  real_T t42_tmp;
  real_T t42;
  real_T t44_tmp;
  real_T t44;
  real_T t48;
  real_T t51;
  real_T t53;
  real_T t56;
  real_T t59;
  real_T t61;
  real_T t62;
  real_T t63;
  real_T t64;
  real_T t65_tmp;
  real_T t65;
  real_T t66;
  real_T t70;
  real_T t73;
  real_T t348;
  real_T t76;
  real_T t78_tmp;
  real_T t78;
  real_T t82;
  real_T t83;
  real_T t84;
  real_T t85;
  real_T t88_tmp;
  real_T t88;
  real_T t90_tmp;
  real_T t90;
  real_T t91;
  real_T t93;
  real_T t94;
  real_T t95;
  real_T t96;
  real_T t99_tmp;
  real_T t100_tmp;
  real_T t100;
  real_T t101;
  real_T t103_tmp;
  real_T t103;
  real_T t105_tmp;
  real_T t105;
  real_T t106;
  real_T t108;
  real_T t109;
  real_T t110;
  real_T t112_tmp;
  real_T t113;
  real_T t115_tmp;
  real_T b_t115_tmp;
  real_T t115;
  real_T t116;
  real_T t118_tmp;
  real_T t118;
  real_T t120_tmp;
  real_T t121_tmp;
  real_T t122;
  real_T t123;
  real_T t124;
  real_T t125_tmp;
  real_T b_t125_tmp;
  real_T t125;
  real_T t127;
  real_T t128;
  real_T t130_tmp;
  real_T t131;
  real_T t132;
  real_T t133;
  real_T t134;
  real_T t140;
  real_T t142;
  real_T t145_tmp;
  real_T t147;
  real_T t158;
  real_T t159;
  real_T t163_tmp;
  real_T t166;
  real_T t168_tmp;
  real_T t172;
  real_T t174;
  real_T t175_tmp;
  real_T b_t175_tmp;
  real_T t178_tmp;
  real_T t178;
  real_T t180;
  real_T t181;
  real_T t184_tmp;
  real_T t184;
  real_T t185_tmp;
  real_T b_t185_tmp;
  real_T t190_tmp;
  real_T b_t190_tmp;
  real_T c_t190_tmp;
  real_T d_t190_tmp;
  real_T t190;
  real_T t198_tmp;
  real_T b_t198_tmp;
  real_T c_t198_tmp;
  real_T d_t198_tmp;
  real_T t198;
  real_T t203;
  real_T t204_tmp;
  real_T t205_tmp;
  real_T t205;
  real_T t212_tmp;
  real_T t213_tmp;
  real_T t213;
  real_T t217;
  real_T t226;
  real_T t231;
  real_T t234;
  real_T t237;
  real_T t239;
  real_T t242;
  real_T t243_tmp;
  real_T t251_tmp;
  real_T b_t251_tmp;
  real_T c_t251_tmp;
  real_T d_t251_tmp;
  real_T t251;
  real_T t259_tmp;
  real_T b_t259_tmp;
  real_T c_t259_tmp;
  real_T d_t259_tmp;
  real_T t259;
  real_T t261;
  real_T t264;
  real_T t269;
  real_T t273;
  real_T t281;
  real_T t282;
  real_T t286;
  real_T t291;
  real_T t292;
  real_T t295;
  real_T t296;
  real_T t299;
  real_T t304;
  real_T t312;
  real_T t330_tmp;
  real_T t318;
  real_T t322;
  real_T t326;
  real_T t338;
  real_T t341;
  real_T t343;
  real_T t345;
  real_T t347;
  real_T t351;
  real_T t362;
  real_T t366;
  real_T t370;
  real_T t373;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;

  /* SPRDMPF13 */
  /*     [OUT1,OUT2,OUT3,OUT4,OUT5,OUT6,OUT7,OUT8] = SPRDMPF13(IN1,IN2,S) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.2. */
  /*     04-Jan-2019 15:17:20 */
  st.site = &emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t3 = s * s;
  t77 = in2[6] * s;
  t87 = in2[7] * t3;
  t2 = t77 + t87;
  t137 = in2[8] * s;
  t141 = in2[9] * t3;
  t4 = t137 + t141;
  t5_tmp = in2[10] * s;
  t233 = in2[11] * t3;
  t5 = t5_tmp + t233;
  st.site = &b_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t8 = t2 * t2;
  st.site = &c_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t11 = t4 * t4;
  st.site = &d_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t14 = t5 * t5;
  t15 = ((-t8 - t11) - t14) + 1.0;
  t16 = t15;
  st.site = &e_emlrtRSI;
  b_sqrt(&st, &t16);
  t17 = ((t8 + t11) + t14) - 1.0;
  t18_tmp = s * t2;
  t393 = t18_tmp * t4;
  t18 = t393 * 4.0;
  t379 = s * t8;
  t19 = t379 * 2.0;
  t20_tmp = t2 * t3;
  t402 = t20_tmp * t4;
  t20 = t402 * 6.0;
  t383 = t3 * t8;
  t21 = t383 * 3.0;
  t22_tmp = t18_tmp * t5;
  t22 = t22_tmp * 4.0;
  t23_tmp = s * t4;
  t23 = t23_tmp * t16 * 4.0;
  t24_tmp = t23_tmp * t5;
  t24 = t24_tmp * 4.0;
  t25_tmp = s * t11;
  t25 = t25_tmp * 2.0;
  t26_tmp = t3 * t4;
  t26 = t26_tmp * t16 * 6.0;
  t27_tmp = t20_tmp * t5;
  t27 = t27_tmp * 6.0;
  t28_tmp = t26_tmp * t5;
  t28 = t28_tmp * 6.0;
  t376 = t3 * t11;
  t29 = t376 * 3.0;
  t32 = (in2[4] * s * 2.0 + in2[5] * t3 * 3.0) + 1.0;
  t35 = in2[2] * s * 2.0 + in2[3] * t3 * 3.0;
  t8 = t15;
  st.site = &f_emlrtRSI;
  b_sqrt(&st, &t8);
  t36 = 1.0 / t8;
  t39 = in2[0] * s * 2.0 + in2[1] * t3 * 3.0;
  t40 = s * t35;
  t42_tmp = t18_tmp * t32;
  t42 = t40 + t42_tmp * t36;
  t8 = s * t32;
  t44_tmp = t18_tmp * t35;
  t44 = t8 - t44_tmp * t36;
  t48 = (t16 * t35 + t2 * t32) - t5 * t39;
  t51 = (t16 * t32 + t4 * t39) - t2 * t35;
  t53 = in2[6] + in2[7] * s * 2.0;
  t56 = in2[8] + in2[9] * s * 2.0;
  t59 = in2[10] + in2[11] * s * 2.0;
  t61 = (t2 * t53 * 2.0 + t4 * t56 * 2.0) + t5 * t59 * 2.0;
  t62 = t77 * 2.0;
  t63 = t87 * 2.0;
  t64 = s * t53 * 2.0;
  t65_tmp = t62 + t63;
  t65 = t65_tmp + t64;
  st.site = &g_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  if (t15 < 0.0) {
    c_st.site = &fb_emlrtRSI;
    error(&c_st);
  }

  t66 = 1.0 / muDoubleScalarPower(t15, 1.5);
  t70 = (t2 * t39 + t4 * t35) + t5 * t32;
  t73 = (t16 * t39 + t5 * t35) - t4 * t32;
  t15 = t3 * t35;
  t348 = t20_tmp * t32;
  t76 = t15 + t348 * t36;
  t77 = t3 * t32;
  t78_tmp = t20_tmp * t35;
  t78 = t77 - t78_tmp * t36;
  t82 = t18_tmp * 4.0;
  t83 = t3 * t53 * 2.0;
  t84 = t82 + t83;
  t85 = s * t51;
  t87 = s * t39;
  t88_tmp = t23_tmp * t32;
  t88 = t87 - t88_tmp * t36;
  t90_tmp = t23_tmp * t36;
  t90 = t8 + t90_tmp * t39;
  t91 = s * t70;
  t93 = s * t59 * 2.0;
  t94 = t137 * 2.0;
  t95 = t141 * 2.0;
  t96 = t393 * t61 * t66;
  t99_tmp = s * t56 * 2.0;
  t100_tmp = t94 + t95;
  t100 = t100_tmp + t99_tmp;
  t101 = t3 * t51;
  t8 = t3 * t39;
  t103_tmp = t26_tmp * t32;
  t103 = t8 - t103_tmp * t36;
  t105_tmp = t26_tmp * t36;
  t105 = t77 + t105_tmp * t39;
  t106 = t3 * t70;
  t108 = t3 * t59 * 2.0;
  t109 = t23_tmp * 4.0;
  t110 = t402 * t61 * t66;
  t112_tmp = t3 * t56 * 2.0;
  t113 = t109 + t112_tmp;
  t115_tmp = s * t5;
  b_t115_tmp = t115_tmp * t36;
  t115 = t40 - b_t115_tmp * t39;
  t116 = s * t73;
  t118_tmp = t115_tmp * t35;
  t118 = t87 + t118_tmp * t36;
  t120_tmp = t5_tmp * 2.0;
  t121_tmp = t233 * 2.0;
  t122 = t22_tmp * t61 * t66;
  t123 = (t93 + t120_tmp) + t121_tmp;
  t124 = t24_tmp * t61 * t66;
  t125_tmp = t3 * t5;
  b_t125_tmp = t125_tmp * t36;
  t125 = t15 - b_t125_tmp * t39;
  t5_tmp = t125_tmp * t35;
  t127 = t8 + t5_tmp * t36;
  t128 = t3 * t73;
  t130_tmp = t115_tmp * 4.0;
  t131 = t27_tmp * t61 * t66;
  t132 = t108 + t130_tmp;
  t133 = t28_tmp * t61 * t66;
  t134 = 1.0 / in1[33];
  t8 = muDoubleScalarCos(in1[20]);
  st.site = &h_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t15 = in1[2] * in1[2];
  st.site = &i_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t137 = in1[3] * in1[3];
  st.site = &j_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t140 = in1[18] * in1[18];
  t141 = muDoubleScalarSin(in1[20]);
  st.site = &k_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t142 = 1.0 / (t141 * t141);
  st.site = &l_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  st.site = &m_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t77 = in1[33] * in1[33];
  t145_tmp = t77 * (t8 * t8);
  t147 = t134 * (t15 - t137) - t140 * t142 * (t145_tmp - 1.0) * 6.0;
  st.site = &n_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  st.site = &o_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  st.site = &p_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  st.site = &q_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  st.site = &r_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  st.site = &s_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t158 = 1.0 / t77 * (t15 * t15 - t137 * t137) + t140 * t140 * (1.0 /
    muDoubleScalarPower(t141, 4.0)) * ((t145_tmp - 1.0) * (t145_tmp - 1.0)) *
    6.0;
  t159 = t158 * 3.1415926535897931 / 4.0;
  st.site = &t_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t163_tmp = t3 * t48;
  t166 = ((((t16 * t125 + t163_tmp) + t348) + t28_tmp * t32 * t36) - t5 * t127)
    - b_t125_tmp * t73;
  t168_tmp = s * t48;
  t172 = ((((t168_tmp + t16 * t115) + t42_tmp) + t24_tmp * t32 * t36) - t5 *
          t118) - b_t115_tmp * t73;
  t8 = t125_tmp * t16 * 6.0;
  t174 = t20 + t8;
  t175_tmp = t3 * t14;
  b_t175_tmp = t175_tmp * 3.0;
  t178_tmp = t18_tmp * t36;
  t178 = ((t91 + t4 * t42) + t5 * t44) - t178_tmp * t73;
  t15 = t115_tmp * t16 * 4.0;
  t180 = t18 + t15;
  t181 = t22 - t23;
  t184_tmp = t20_tmp * t36;
  t184 = ((t106 + t4 * t76) + t5 * t78) - t184_tmp * t73;
  t185_tmp = s * t14;
  b_t185_tmp = t185_tmp * 2.0;
  t190_tmp = t4 * t103;
  b_t190_tmp = t16 * t105;
  c_t190_tmp = t105_tmp * t73;
  d_t190_tmp = t28_tmp * t35 * t36;
  t190 = ((((t101 - t78_tmp) + t190_tmp) + b_t190_tmp) + c_t190_tmp) +
    d_t190_tmp;
  t198_tmp = t4 * t88;
  b_t198_tmp = t16 * t90;
  c_t198_tmp = t90_tmp * t73;
  d_t198_tmp = t24_tmp * t35 * t36;
  t198 = ((((t85 - t44_tmp) + t198_tmp) + b_t198_tmp) + c_t198_tmp) + d_t198_tmp;
  t203 = t26 - t27;
  t204_tmp = t3 * t17 * 3.0;
  t205_tmp = -t21 + t29;
  t205 = (t205_tmp + b_t175_tmp) + t204_tmp;
  t212_tmp = s * t17 * 2.0;
  t213_tmp = -t19 + t25;
  t213 = (t213_tmp + b_t185_tmp) + t212_tmp;
  st.site = &u_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t217 = muDoubleScalarPower(muDoubleScalarAbs(((((((((((t166 * in2[23] + t172 *
    in2[22]) + t174 * in2[15]) + t178 * in2[18]) + t180 * in2[14]) + t181 * in2
    [16]) + t184 * in2[19]) - t190 * in2[21]) - t198 * in2[20]) - t203 * in2[17])
    - t205 * in2[13]) - t213 * in2[12]), in1[11] - 1.0);
  t226 = ((((t101 + t16 * t78) + t26_tmp * t39) + t27_tmp * t36 * t39) - t2 *
          t76) - t184_tmp * t48;
  t231 = ((((t85 + t16 * t44) + t23_tmp * t39) + t22_tmp * t36 * t39) - t2 * t42)
    - t178_tmp * t48;
  t233 = t20_tmp * t16 * 6.0;
  t234 = t28 + t233;
  t237 = ((t91 + t2 * t88) + t5 * t90) - t90_tmp * t48;
  t137 = t18_tmp * t16 * 4.0;
  t239 = t24 + t137;
  t242 = ((t106 + t2 * t103) + t5 * t105) - t105_tmp * t48;
  t243_tmp = t20 - t8;
  t251_tmp = t5 * t125;
  b_t251_tmp = t16 * t127;
  c_t251_tmp = b_t125_tmp * t48;
  d_t251_tmp = t27_tmp * t32 * t36;
  t251 = ((((t128 - t103_tmp) + t251_tmp) + b_t251_tmp) + c_t251_tmp) +
    d_t251_tmp;
  t259_tmp = t5 * t115;
  b_t259_tmp = t16 * t118;
  c_t259_tmp = b_t115_tmp * t48;
  d_t259_tmp = t22_tmp * t32 * t36;
  t259 = ((((t116 - t88_tmp) + t259_tmp) + b_t259_tmp) + c_t259_tmp) +
    d_t259_tmp;
  t261 = ((t21 - t29) + b_t175_tmp) + t204_tmp;
  t264 = t18 - t15;
  t269 = ((t19 - t25) + b_t185_tmp) + t212_tmp;
  t8 = t251 * in2[23];
  t15 = t259 * in2[22];
  t77 = t261 * in2[15];
  t40 = t269 * in2[14];
  st.site = &v_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t87 = (((((t226 * in2[19] + t231 * in2[18]) + t234 * in2[17]) + t237 * in2[20])
          + t264 * in2[12]) + t239 * in2[16]) + t242 * in2[21];
  t273 = muDoubleScalarPower(muDoubleScalarAbs(((((t87 + t243_tmp * in2[13]) -
    t8) - t15) - t77) - t40), in1[11] - 1.0);
  st.site = &w_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t281 = muDoubleScalarPower(muDoubleScalarAbs(((((t87 - t8) - t15) - t77) - t40)
    + in2[13] * t243_tmp), in1[11] - 1.0);
  t282 = t125_tmp * t39;
  t286 = ((((t128 + t16 * t103) + t5_tmp) + t402 * t35 * t36) - t4 * t105) -
    t105_tmp * t51;
  t103 = t115_tmp * t39;
  t291 = ((((t116 + t16 * t88) + t118_tmp) + t393 * t35 * t36) - t4 * t90) -
    t90_tmp * t51;
  t292 = t26 + t27;
  t295 = ((t91 + t2 * t118) + t4 * t115) - b_t115_tmp * t51;
  t296 = t22 + t23;
  t299 = ((t106 + t2 * t127) + t4 * t125) - b_t125_tmp * t51;
  t105 = t2 * t78;
  t27_tmp = t16 * t76;
  t22_tmp = t184_tmp * t51;
  t18_tmp = t402 * t36 * t39;
  t304 = ((((t163_tmp - t282) + t105) + t27_tmp) + t22_tmp) + t18_tmp;
  t23_tmp = t2 * t44;
  t17 = t16 * t42;
  t26_tmp = t178_tmp * t51;
  t24_tmp = t393 * t36 * t39;
  t312 = ((((t168_tmp - t103) + t23_tmp) + t17) + t26_tmp) + t24_tmp;
  t330_tmp = t28 - t233;
  t318 = ((t21 + t29) - b_t175_tmp) + t204_tmp;
  t78 = t295 * in2[22];
  t76 = t296 * in2[12];
  t322 = t24 - t137;
  t8 = t322 * in2[14];
  t15 = t299 * in2[23];
  t326 = ((t19 + t25) - b_t185_tmp) + t212_tmp;
  t77 = t304 * in2[19];
  t40 = t312 * in2[18];
  t87 = t318 * in2[17];
  t106 = t326 * in2[16];
  st.site = &x_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t91 = (t286 * in2[21] + t291 * in2[20]) + t292 * in2[13];
  t233 = muDoubleScalarPower(muDoubleScalarAbs(((((((((t91 + t330_tmp * in2[15])
    + t78) + t76) + t8) + t15) - t77) - t40) - t87) - t106), in1[11] - 1.0);
  st.site = &y_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t338 = muDoubleScalarPower(muDoubleScalarAbs(((((((((t91 + t78) + t76) + t8) +
    t15) - t77) - t40) - t87) - t106) + in2[15] * t330_tmp), in1[11] - 1.0);
  t125_tmp = t2 * t36;
  t77 = s * t16 * 4.0 + t3 * t36 * t61;
  t341 = ((t77 + t125_tmp * t84) + t383 * t61 * t66) - t184_tmp * t53 * 2.0;
  t343 = (((-t108 + t110) + t130_tmp) + t125_tmp * t113) - t105_tmp * t53 * 2.0;
  t345 = (((-t109 + t112_tmp) + t131) + t125_tmp * t132) - b_t125_tmp * t53 *
    2.0;
  t347 = ((((-t93 + t96) + t120_tmp) + t121_tmp) + t125_tmp * t100) - t90_tmp *
    t53 * 2.0;
  t348 = t125_tmp * t123;
  t115 = t16 * 2.0 + s * t36 * t61;
  t351 = ((t115 + t125_tmp * t65) + t379 * t61 * t66) - t178_tmp * t53 * 2.0;
  t90 = b_t115_tmp * t53 * 2.0;
  t14 = t100_tmp - t99_tmp;
  t362 = ((t14 - t122) - t348) + t90;
  st.site = &ab_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t366 = muDoubleScalarPower(muDoubleScalarAbs(((((t341 * in2[19] + t343 * in2
    [21]) + t345 * in2[23]) + t347 * in2[20]) + t351 * in2[18]) - t362 * in2[22]),
    in1[11] - 1.0);
  t20_tmp = t4 * t36;
  t370 = ((t77 + t20_tmp * t113) + t376 * t61 * t66) - t105_tmp * t56 * 2.0;
  t137 = t20_tmp * t84;
  t373 = (((t82 - t83) + t133) + t20_tmp * t132) - b_t125_tmp * t56 * 2.0;
  t141 = t20_tmp * t65;
  t42_tmp = t65_tmp - t64;
  t376 = ((t42_tmp + t124) + t20_tmp * t123) - b_t115_tmp * t56 * 2.0;
  t379 = ((t115 + t20_tmp * t100) + t25_tmp * t61 * t66) - t90_tmp * t56 * 2.0;
  t87 = t108 + t110;
  t5_tmp = t184_tmp * t56 * 2.0;
  t383 = ((t87 - t130_tmp) + t137) - t5_tmp;
  t8 = t93 + t96;
  t15 = t178_tmp * t56 * 2.0;
  t42 = (((t8 - t120_tmp) - t121_tmp) + t141) - t15;
  st.site = &bb_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t393 = muDoubleScalarPower(muDoubleScalarAbs(((((t370 * in2[21] + t383 * in2
    [19]) + t373 * in2[23]) + t42 * in2[18]) + t376 * in2[22]) + t379 * in2[20]),
    in1[11] - 1.0);
  t28_tmp = t5 * t36;
  t44 = ((t77 + t28_tmp * t132) + t175_tmp * t61 * t66) - b_t125_tmp * t59 * 2.0;
  t22 = t28_tmp * t84;
  t402 = (((-t82 + t83) + t133) + t28_tmp * t113) - t105_tmp * t59 * 2.0;
  t77 = t28_tmp * t65;
  t40 = t28_tmp * t100;
  t23 = ((t115 + t28_tmp * t123) + t185_tmp * t61 * t66) - b_t115_tmp * t59 *
    2.0;
  out1[0] = ((t19 - s * t11 * 2.0) - b_t185_tmp) - t212_tmp;
  out1[1] = ((t21 - t3 * t11 * 3.0) - b_t175_tmp) - t204_tmp;
  out1[2] = t180;
  out1[3] = t174;
  out1[4] = t181;
  out1[5] = -t26 + t27;
  out1[6] = t178;
  out1[7] = t184;
  out1[8] = ((((-t85 + t44_tmp) - t198_tmp) - b_t198_tmp) - c_t198_tmp) -
    d_t198_tmp;
  out1[9] = ((((-t101 + t78_tmp) - t190_tmp) - b_t190_tmp) - c_t190_tmp) -
    d_t190_tmp;
  out1[10] = t172;
  out1[11] = t166;
  out1[12] = t18 - s * t5 * t16 * 4.0;
  out1[13] = t20 - t3 * t5 * t16 * 6.0;
  out1[14] = (t213_tmp - b_t185_tmp) - t212_tmp;
  out1[15] = (t205_tmp - b_t175_tmp) - t204_tmp;
  out1[16] = t239;
  out1[17] = t234;
  out1[18] = t231;
  out1[19] = t226;
  out1[20] = t237;
  out1[21] = t242;
  out1[22] = ((((-t116 + t88_tmp) - t259_tmp) - b_t259_tmp) - c_t259_tmp) -
    d_t259_tmp;
  out1[23] = ((((-t128 + t103_tmp) - t251_tmp) - b_t251_tmp) - c_t251_tmp) -
    d_t251_tmp;
  out1[24] = t296;
  out1[25] = t292;
  out1[26] = t24 - s * t2 * t16 * 4.0;
  out1[27] = t28 - t2 * t3 * t16 * 6.0;
  out1[28] = ((-t19 - t25) + b_t185_tmp) - t212_tmp;
  out1[29] = ((-t21 - t29) + b_t175_tmp) - t204_tmp;
  out1[30] = ((((t103 - t168_tmp) - t23_tmp) - t17) - t26_tmp) - t24_tmp;
  out1[31] = ((((t282 - t163_tmp) - t105) - t27_tmp) - t22_tmp) - t18_tmp;
  out1[32] = t291;
  out1[33] = t286;
  out1[34] = t295;
  out1[35] = t299;
  out1[36] = 0.0;
  out1[37] = 0.0;
  out1[38] = 0.0;
  out1[39] = 0.0;
  out1[40] = 0.0;
  out1[41] = 0.0;
  out1[42] = t351;
  out1[43] = t341;
  out1[44] = t347;
  out1[45] = t343;
  out1[46] = ((((-t94 - t95) + t99_tmp) + t122) + t348) - t90;
  out1[47] = t345;
  out1[48] = 0.0;
  out1[49] = 0.0;
  out1[50] = 0.0;
  out1[51] = 0.0;
  out1[52] = 0.0;
  out1[53] = 0.0;
  out1[54] = (((t8 + t141) - t120_tmp) - t121_tmp) - t15;
  out1[55] = ((t87 + t137) - t130_tmp) - t5_tmp;
  out1[56] = t379;
  out1[57] = t370;
  out1[58] = t376;
  out1[59] = t373;
  out1[60] = 0.0;
  out1[61] = 0.0;
  out1[62] = 0.0;
  out1[63] = 0.0;
  out1[64] = 0.0;
  out1[65] = 0.0;
  t15 = t178_tmp * t59 * 2.0;
  out1[66] = (((t100_tmp + t122) + t77) - t99_tmp) - t15;
  t8 = t184_tmp * t59 * 2.0;
  out1[67] = (((t109 + t131) + t22) - t112_tmp) - t8;
  t87 = t90_tmp * t59 * 2.0;
  out1[68] = ((((-t62 - t63) + t64) + t124) + t40) - t87;
  out1[69] = t402;
  out1[70] = t23;
  out1[71] = t44;
  t88 = (((t109 - t112_tmp) + t131) + t22) - t8;
  t90 = ((t14 + t122) + t77) - t15;
  t118 = ((t42_tmp - t124) - t40) + t87;
  st.site = &cb_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t115 = muDoubleScalarPower(muDoubleScalarAbs(((((t44 * in2[23] + t88 * in2[19])
    + t402 * in2[21]) + t90 * in2[18]) + t23 * in2[22]) - t118 * in2[20]), in1
    [11] - 1.0);
  t8 = in1[33];
  st.site = &db_emlrtRSI;
  b_sqrt(&st, &t8);
  t105 = 1.0 / t8;
  t8 = t134 * t140 * t142 * (t145_tmp - 1.0) * (in1[19] * in1[19]) *
    3.1415926535897931;
  t125 = t159 - t8 * 3.0;
  t127 = t159 - t8 * 2.9999999999999991;
  t103 = in1[1] * t134;
  t115_tmp = t103 * t147;
  t118_tmp = t115_tmp * 3.1415926535897931;
  out2[0] = t118_tmp * (((t5 * t48 - t4 * t51) + t2 * t70) + t16 * t73) / 3.0;
  out2[1] = t118_tmp * (((t2 * t51 + t16 * t48) + t4 * t70) - t5 * t73) / 3.0;
  out2[2] = t118_tmp * ((((-t2 * t48 + t16 * t51) + t5 * t70) + t4 * t73) - 1.0);
  out2[3] = t103 * t125 * (((t5 * t56 * 2.0 - t4 * t59 * 2.0) + t16 * t53 * 2.0)
    + t125_tmp * t61);
  out2[4] = t103 * t127 * (((t5 * t53 * -2.0 + t2 * t59 * 2.0) + t16 * t56 * 2.0)
    + t20_tmp * t61);
  t118_tmp = t103 * t158;
  out2[5] = t118_tmp * 3.1415926535897931 * (((t4 * t53 * 2.0 - t2 * t56 * 2.0)
    + t16 * t59 * 2.0) + t28_tmp * t61) / 6.0;
  t91 = in1[5] * t213 * t217;
  t26_tmp = in1[5] * t205 * t217;
  t78 = in1[5] * t203 * t217;
  t76 = in1[5] * t198 * t217;
  t23_tmp = in1[5] * t190 * t217;
  t20_tmp = -in1[5] * t166 * t217;
  out3[0] = ((((((((((t20_tmp * in2[23] - in1[5] * t174 * t217 * in2[15]) - in1
                     [5] * t172 * t217 * in2[22]) - in1[5] * t180 * t217 * in2
                    [14]) - in1[5] * t178 * t217 * in2[18]) - in1[5] * t181 *
                  t217 * in2[16]) - in1[5] * t184 * t217 * in2[19]) + t23_tmp *
                in2[21]) + t76 * in2[20]) + t26_tmp * in2[13]) + t78 * in2[17])
    + t91 * in2[12];
  t18_tmp = in1[6] * t269 * t281;
  t27_tmp = in1[6] * t261 * t281;
  t22 = -in1[6] * t234;
  t22_tmp = in1[6] * t259 * t281;
  t125_tmp = in1[6] * t251 * t281;
  out3[1] = ((((((((((t22 * t273 * in2[17] - in1[6] * t226 * t281 * in2[19]) -
                     in1[6] * t243_tmp * t273 * in2[13]) - in1[6] * t231 * t281 *
                    in2[18]) - in1[6] * t239 * t281 * in2[16]) - in1[6] * t237 *
                  t281 * in2[20]) - in1[6] * t242 * t281 * in2[21]) + t125_tmp *
                in2[23]) + t27_tmp * in2[15]) - in1[6] * t264 * t281 * in2[12])
             + t22_tmp * in2[22]) + t18_tmp * in2[14];
  t14 = -in1[7] * t292;
  t28_tmp = in1[7] * t326 * t338;
  t24_tmp = in1[7] * t318 * t338;
  t17 = in1[7] * t312 * t338;
  t106 = in1[7] * t304 * t338;
  out3[2] = ((((((((((t14 * t233 * in2[13] - in1[7] * t286 * t338 * in2[21]) -
                     in1[7] * t296 * t338 * in2[12]) - in1[7] * t291 * t338 *
                    in2[20]) - in1[7] * t295 * t338 * in2[22]) - in1[7] * t299 *
                  t338 * in2[23]) + t106 * in2[19]) + t17 * in2[18]) + t24_tmp *
               in2[17]) - in1[7] * t322 * t338 * in2[14]) - in1[7] * t233 *
             t330_tmp * in2[15]) + t28_tmp * in2[16];
  t40 = -in1[8] * t341 * t366;
  t5_tmp = in1[8] * t362 * t366;
  out3[3] = ((((t40 * in2[19] - in1[8] * t343 * t366 * in2[21]) - in1[8] * t347 *
               t366 * in2[20]) - in1[8] * t345 * t366 * in2[23]) - in1[8] * t351
             * t366 * in2[18]) + t5_tmp * in2[22];
  t233 = -in1[9] * t370 * t393;
  out3[4] = ((((t233 * in2[21] - in1[9] * t373 * t393 * in2[23]) - in1[9] * t376
               * t393 * in2[22]) - in1[9] * t379 * t393 * in2[20]) - in1[9] *
             t383 * t393 * in2[19]) - in1[9] * t393 * t42 * in2[18];
  t348 = in1[10] * t118 * t115;
  t42_tmp = -in1[10] * t44 * t115;
  out3[5] = ((((t42_tmp * in2[23] - in1[10] * t402 * t115 * in2[21]) - in1[10] *
               t23 * t115 * in2[22]) - in1[10] * t88 * t115 * in2[19]) - in1[10]
             * t90 * t115 * in2[18]) + t348 * in2[20];
  out4[0] = 0.0;
  out4[1] = 0.0;
  out4[2] = -t140 * t142 * (t145_tmp - 1.0) * 3.1415926535897931 * (((((in1[21]
    + in1[22]) + in1[23]) + in1[24]) + in1[25]) + in1[26]);
  t87 = in1[21] * in1[19] * t140 * t142 * (t145_tmp - 1.0) * t105 *
    3.1415926535897931;
  t15 = in1[22] * in1[19] * t140 * t142 * (t145_tmp - 1.0) * t105 *
    3.1415926535897931;
  t137 = in1[23] * in1[19] * t140 * t142 * (t145_tmp - 1.0) * t105 *
    3.1415926535897931;
  t141 = in1[24] * in1[19] * t140 * t142 * (t145_tmp - 1.0) * t105 *
    3.1415926535897931;
  t77 = in1[25] * in1[19] * t140 * t142 * (t145_tmp - 1.0) * t105 *
    3.1415926535897931;
  t8 = in1[26] * in1[19] * t140 * t142 * (t145_tmp - 1.0) * t105 *
    3.1415926535897931;
  out4[3] = ((((t87 * -0.91522491349480972 - t15 * 0.91522491349480972) + t137 *
               0.1086532638769295) + t141 * 0.80657164961788008) + t77 *
             0.80657164961787986) + t8 * 0.1086532638769295;
  out4[4] = ((((t87 * -0.40294336787992679 + t15 * 0.40294336787992691) + t137 *
               0.99407970920288391) + t141 * 0.59113634132295712) - t77 *
             0.59113634132295745) - t8 * 0.99407970920288391;
  out4[5] = 0.0;
  out5[0] = t39;
  out5[1] = t35;
  out5[2] = t32;
  out6[0] = t115_tmp * t213 * 3.1415926535897931 / 3.0;
  out6[1] = t115_tmp * t264 * 3.1415926535897931 * -0.33333333333333331;
  t77 = -in1[1] * t134;
  t8 = t77 * t147;
  out6[2] = t8 * t296 * 3.1415926535897931;
  out6[3] = 0.0;
  out6[4] = 0.0;
  out6[5] = 0.0;
  out6[6] = t115_tmp * t205 * 3.1415926535897931 / 3.0;
  out6[7] = t115_tmp * t243_tmp * 3.1415926535897931 * -0.33333333333333331;
  out6[8] = t8 * t292 * 3.1415926535897931;
  out6[9] = 0.0;
  out6[10] = 0.0;
  out6[11] = 0.0;
  out6[12] = t115_tmp * t180 * 3.1415926535897931 * -0.33333333333333331;
  out6[13] = t115_tmp * t269 * 3.1415926535897931 / 3.0;
  out6[14] = t8 * t322 * 3.1415926535897931;
  out6[15] = 0.0;
  out6[16] = 0.0;
  out6[17] = 0.0;
  out6[18] = t115_tmp * t174 * 3.1415926535897931 * -0.33333333333333331;
  out6[19] = t115_tmp * t261 * 3.1415926535897931 / 3.0;
  out6[20] = t8 * t330_tmp * 3.1415926535897931;
  out6[21] = 0.0;
  out6[22] = 0.0;
  out6[23] = 0.0;
  out6[24] = t115_tmp * t181 * 3.1415926535897931 * -0.33333333333333331;
  out6[25] = t115_tmp * t239 * 3.1415926535897931 * -0.33333333333333331;
  out6[26] = t115_tmp * t326 * 3.1415926535897931;
  out6[27] = 0.0;
  out6[28] = 0.0;
  out6[29] = 0.0;
  out6[30] = t115_tmp * t203 * 3.1415926535897931 / 3.0;
  out6[31] = t115_tmp * t234 * 3.1415926535897931 * -0.33333333333333331;
  out6[32] = t115_tmp * t318 * 3.1415926535897931;
  out6[33] = 0.0;
  out6[34] = 0.0;
  out6[35] = 0.0;
  out6[36] = t115_tmp * t178 * 3.1415926535897931 * -0.33333333333333331;
  out6[37] = t115_tmp * t231 * 3.1415926535897931 * -0.33333333333333331;
  out6[38] = t115_tmp * t312 * 3.1415926535897931;
  out6[39] = t77 * t351 * t125;
  out6[40] = t77 * t42 * t127;
  out6[41] = t118_tmp * t90 * 3.1415926535897931 * -0.16666666666666666;
  out6[42] = t115_tmp * t184 * 3.1415926535897931 * -0.33333333333333331;
  out6[43] = t115_tmp * t226 * 3.1415926535897931 * -0.33333333333333331;
  out6[44] = t115_tmp * t304 * 3.1415926535897931;
  out6[45] = t77 * t341 * t125;
  out6[46] = t77 * t383 * t127;
  out6[47] = t118_tmp * t88 * 3.1415926535897931 * -0.16666666666666666;
  out6[48] = t115_tmp * t198 * 3.1415926535897931 / 3.0;
  out6[49] = t115_tmp * t237 * 3.1415926535897931 * -0.33333333333333331;
  out6[50] = t8 * t291 * 3.1415926535897931;
  out6[51] = t77 * t347 * t125;
  out6[52] = t77 * t379 * t127;
  out6[53] = t118_tmp * t118 * 3.1415926535897931 / 6.0;
  out6[54] = t115_tmp * t190 * 3.1415926535897931 / 3.0;
  out6[55] = t115_tmp * t242 * 3.1415926535897931 * -0.33333333333333331;
  out6[56] = t8 * t286 * 3.1415926535897931;
  out6[57] = t77 * t343 * t125;
  out6[58] = t77 * t370 * t127;
  out6[59] = t118_tmp * t402 * 3.1415926535897931 * -0.16666666666666666;
  out6[60] = t115_tmp * t172 * 3.1415926535897931 * -0.33333333333333331;
  out6[61] = t115_tmp * t259 * 3.1415926535897931 / 3.0;
  out6[62] = t8 * t295 * 3.1415926535897931;
  out6[63] = t103 * t362 * t125;
  out6[64] = t77 * t376 * t127;
  out6[65] = t118_tmp * t23 * 3.1415926535897931 * -0.16666666666666666;
  out6[66] = t115_tmp * t166 * 3.1415926535897931 * -0.33333333333333331;
  out6[67] = t115_tmp * t251 * 3.1415926535897931 / 3.0;
  out6[68] = t8 * t299 * 3.1415926535897931;
  out6[69] = t77 * t345 * t125;
  out6[70] = t77 * t373 * t127;
  out6[71] = t118_tmp * t44 * 3.1415926535897931 * -0.16666666666666666;
  out7[0] = t91;
  out7[1] = -in1[6] * t264 * t281;
  out7[2] = -in1[7] * t296 * t338;
  out7[3] = 0.0;
  out7[4] = 0.0;
  out7[5] = 0.0;
  out7[6] = t26_tmp;
  out7[7] = -in1[6] * t243_tmp * t281;
  out7[8] = t14 * t338;
  out7[9] = 0.0;
  out7[10] = 0.0;
  out7[11] = 0.0;
  out7[12] = -in1[5] * t180 * t217;
  out7[13] = t18_tmp;
  out7[14] = -in1[7] * t322 * t338;
  out7[15] = 0.0;
  out7[16] = 0.0;
  out7[17] = 0.0;
  out7[18] = -in1[5] * t174 * t217;
  out7[19] = t27_tmp;
  out7[20] = -in1[7] * t330_tmp * t338;
  out7[21] = 0.0;
  out7[22] = 0.0;
  out7[23] = 0.0;
  out7[24] = -in1[5] * t181 * t217;
  out7[25] = -in1[6] * t239 * t281;
  out7[26] = t28_tmp;
  out7[27] = 0.0;
  out7[28] = 0.0;
  out7[29] = 0.0;
  out7[30] = t78;
  out7[31] = t22 * t281;
  out7[32] = t24_tmp;
  out7[33] = 0.0;
  out7[34] = 0.0;
  out7[35] = 0.0;
  out7[36] = -in1[5] * t178 * t217;
  out7[37] = -in1[6] * t231 * t281;
  out7[38] = t17;
  out7[39] = -in1[8] * t351 * t366;
  out7[40] = -in1[9] * t393 * t42;
  out7[41] = -in1[10] * t90 * t115;
  out7[42] = -in1[5] * t184 * t217;
  out7[43] = -in1[6] * t226 * t281;
  out7[44] = t106;
  out7[45] = t40;
  out7[46] = -in1[9] * t383 * t393;
  out7[47] = -in1[10] * t88 * t115;
  out7[48] = t76;
  out7[49] = -in1[6] * t237 * t281;
  out7[50] = -in1[7] * t291 * t338;
  out7[51] = -in1[8] * t347 * t366;
  out7[52] = -in1[9] * t379 * t393;
  out7[53] = t348;
  out7[54] = t23_tmp;
  out7[55] = -in1[6] * t242 * t281;
  out7[56] = -in1[7] * t286 * t338;
  out7[57] = -in1[8] * t343 * t366;
  out7[58] = t233;
  out7[59] = -in1[10] * t402 * t115;
  out7[60] = -in1[5] * t172 * t217;
  out7[61] = t22_tmp;
  out7[62] = -in1[7] * t295 * t338;
  out7[63] = t5_tmp;
  out7[64] = -in1[9] * t376 * t393;
  out7[65] = -in1[10] * t23 * t115;
  out7[66] = t20_tmp;
  out7[67] = t125_tmp;
  out7[68] = -in1[7] * t299 * t338;
  out7[69] = -in1[8] * t345 * t366;
  out7[70] = -in1[9] * t373 * t393;
  out7[71] = t42_tmp;
  *out8 = 1.0;
}

/* End of code generation (sprdmpF13.c) */
