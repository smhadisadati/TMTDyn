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
#include "EOM_eq.h"
#include "sprdmpF13.h"
#include "sqrt.h"
#include "error.h"
#include "EOM_eq_data.h"

/* Variable Definitions */
static emlrtRSInfo m_emlrtRSI = { 52,  /* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 62,  /* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 63,  /* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 64,  /* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 66,  /* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 86,  /* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 118, /* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 186, /* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 187, /* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 190, /* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 192, /* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 193, /* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 194, /* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 199,/* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 200,/* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo cb_emlrtRSI = { 201,/* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo db_emlrtRSI = { 204,/* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo eb_emlrtRSI = { 205,/* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo fb_emlrtRSI = { 206,/* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 210,/* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo hb_emlrtRSI = { 272,/* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo ib_emlrtRSI = { 327,/* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo jb_emlrtRSI = { 331,/* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo kb_emlrtRSI = { 384,/* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo lb_emlrtRSI = { 388,/* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo mb_emlrtRSI = { 417,/* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo nb_emlrtRSI = { 446,/* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo ob_emlrtRSI = { 477,/* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/sprdmpF13.m"/* pathName */
};

static emlrtRSInfo pb_emlrtRSI = { 478,/* lineNo */
  "sprdmpF13",                         /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/sprdmpF13.m"/* pathName */
};

/* Function Definitions */
void b_sprdmpF13(const emlrtStack *sp, const real_T in1[34], const real_T in2[24],
                 real_T s, real_T out1[72], real_T out2[6], real_T out3[6],
                 real_T out4[6])
{
  real_T t3;
  real_T t87;
  real_T t74;
  real_T t2;
  real_T t332;
  real_T t277;
  real_T t4;
  real_T t125;
  real_T t127;
  real_T t5;
  real_T t8;
  real_T t11;
  real_T t14;
  real_T t15;
  real_T t16;
  real_T t17;
  real_T t396;
  real_T t18_tmp;
  real_T t18;
  real_T t19_tmp;
  real_T t19;
  real_T t20_tmp;
  real_T b_t20_tmp;
  real_T t20;
  real_T t21_tmp;
  real_T t21;
  real_T t383;
  real_T t22;
  real_T t23_tmp;
  real_T t23;
  real_T t399;
  real_T t24;
  real_T t25_tmp;
  real_T t25;
  real_T t26_tmp;
  real_T t26;
  real_T t393;
  real_T t27;
  real_T t374;
  real_T t28;
  real_T t29_tmp;
  real_T t29;
  real_T t32;
  real_T t35;
  real_T t36;
  real_T t39;
  real_T t40;
  real_T t238;
  real_T t42;
  real_T t43;
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
  real_T t402;
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
  real_T t351;
  real_T t115_tmp;
  real_T t115;
  real_T t116;
  real_T t362;
  real_T t118;
  real_T t120_tmp;
  real_T t121_tmp;
  real_T t122;
  real_T t123;
  real_T t124;
  real_T t125_tmp;
  real_T t128;
  real_T t130_tmp;
  real_T t131;
  real_T t132;
  real_T t133;
  real_T t134;
  real_T t136;
  real_T t137;
  real_T t140;
  real_T t142;
  real_T t145_tmp;
  real_T t158;
  real_T t159;
  real_T t163_tmp;
  real_T t166;
  real_T t168_tmp;
  real_T t172;
  real_T t174;
  real_T t175_tmp;
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
  real_T t287;
  real_T t291;
  real_T t292;
  real_T t295;
  real_T t296;
  real_T t299;
  real_T t304_tmp;
  real_T b_t304_tmp;
  real_T c_t304_tmp;
  real_T d_t304_tmp;
  real_T t304;
  real_T t312;
  real_T t318;
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
  st.site = &m_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  t3 = s * s;
  t87 = in2[6] * s;
  t74 = in2[7] * t3;
  t2 = t87 + t74;
  t332 = in2[8] * s;
  t277 = in2[9] * t3;
  t4 = t332 + t277;
  t125 = in2[10] * s;
  t127 = in2[11] * t3;
  t5 = t125 + t127;
  st.site = &n_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  t8 = t2 * t2;
  st.site = &o_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  t11 = t4 * t4;
  st.site = &p_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  t14 = t5 * t5;
  t15 = ((-t8 - t11) - t14) + 1.0;
  t16 = t15;
  st.site = &q_emlrtRSI;
  b_sqrt(&st, &t16);
  t17 = ((t8 + t11) + t14) - 1.0;
  t396 = s * t2;
  t18_tmp = t396 * t4;
  t18 = t18_tmp * 4.0;
  t19_tmp = s * t8;
  t19 = t19_tmp * 2.0;
  t20_tmp = t2 * t3;
  b_t20_tmp = t20_tmp * t4;
  t20 = b_t20_tmp * 6.0;
  t21_tmp = t3 * t8;
  t21 = t21_tmp * 3.0;
  t383 = t396 * t5;
  t22 = t383 * 4.0;
  t23_tmp = s * t4;
  t23 = t23_tmp * t16 * 4.0;
  t399 = t23_tmp * t5;
  t24 = t399 * 4.0;
  t25_tmp = s * t11;
  t25 = t25_tmp * 2.0;
  t26_tmp = t3 * t4;
  t26 = t26_tmp * t16 * 6.0;
  t393 = t20_tmp * t5;
  t27 = t393 * 6.0;
  t374 = t26_tmp * t5;
  t28 = t374 * 6.0;
  t29_tmp = t3 * t11;
  t29 = t29_tmp * 3.0;
  t32 = (in2[4] * s * 2.0 + in2[5] * t3 * 3.0) + 1.0;
  t35 = in2[2] * s * 2.0 + in2[3] * t3 * 3.0;
  t8 = t15;
  st.site = &r_emlrtRSI;
  b_sqrt(&st, &t8);
  t36 = 1.0 / t8;
  t39 = in2[0] * s * 2.0 + in2[1] * t3 * 3.0;
  t40 = s * t35;
  t238 = t396 * t32;
  t42 = t40 + t238 * t36;
  t43 = s * t32;
  t44_tmp = t396 * t35;
  t44 = t43 - t44_tmp * t36;
  t48 = (t16 * t35 + t2 * t32) - t5 * t39;
  t51 = (t16 * t32 + t4 * t39) - t2 * t35;
  t53 = in2[6] + in2[7] * s * 2.0;
  t56 = in2[8] + in2[9] * s * 2.0;
  t59 = in2[10] + in2[11] * s * 2.0;
  t61 = (t2 * t53 * 2.0 + t4 * t56 * 2.0) + t5 * t59 * 2.0;
  t62 = t87 * 2.0;
  t63 = t74 * 2.0;
  t64 = s * t53 * 2.0;
  t65_tmp = t62 + t63;
  t65 = t65_tmp + t64;
  st.site = &s_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  if (t15 < 0.0) {
    c_st.site = &rb_emlrtRSI;
    error(&c_st);
  }

  t66 = 1.0 / muDoubleScalarPower(t15, 1.5);
  t70 = (t2 * t39 + t4 * t35) + t5 * t32;
  t73 = (t16 * t39 + t5 * t35) - t4 * t32;
  t74 = t3 * t35;
  t402 = t20_tmp * t32;
  t76 = t74 + t402 * t36;
  t8 = t3 * t32;
  t78_tmp = t20_tmp * t35;
  t78 = t8 - t78_tmp * t36;
  t82 = t396 * 4.0;
  t83 = t3 * t53 * 2.0;
  t84 = t82 + t83;
  t85 = s * t51;
  t87 = s * t39;
  t88_tmp = t23_tmp * t32;
  t88 = t87 - t88_tmp * t36;
  t90_tmp = t23_tmp * t36;
  t90 = t43 + t90_tmp * t39;
  t91 = s * t70;
  t93 = s * t59 * 2.0;
  t94 = t332 * 2.0;
  t95 = t277 * 2.0;
  t96 = t18_tmp * t61 * t66;
  t99_tmp = s * t56 * 2.0;
  t100_tmp = t94 + t95;
  t100 = t100_tmp + t99_tmp;
  t101 = t3 * t51;
  t15 = t3 * t39;
  t103_tmp = t26_tmp * t32;
  t103 = t15 - t103_tmp * t36;
  t105_tmp = t26_tmp * t36;
  t105 = t8 + t105_tmp * t39;
  t106 = t3 * t70;
  t108 = t3 * t59 * 2.0;
  t109 = t23_tmp * 4.0;
  t110 = b_t20_tmp * t61 * t66;
  t112_tmp = t3 * t56 * 2.0;
  t113 = t109 + t112_tmp;
  t351 = s * t5;
  t115_tmp = t351 * t36;
  t115 = t40 - t115_tmp * t39;
  t116 = s * t73;
  t362 = t351 * t35;
  t118 = t87 + t362 * t36;
  t120_tmp = t125 * 2.0;
  t121_tmp = t127 * 2.0;
  t122 = t383 * t61 * t66;
  t123 = (t93 + t120_tmp) + t121_tmp;
  t124 = t399 * t61 * t66;
  t40 = t3 * t5;
  t125_tmp = t40 * t36;
  t125 = t74 - t125_tmp * t39;
  t87 = t40 * t35;
  t127 = t15 + t87 * t36;
  t128 = t3 * t73;
  t130_tmp = t351 * 4.0;
  t131 = t393 * t61 * t66;
  t132 = t108 + t130_tmp;
  t133 = t374 * t61 * t66;
  t134 = 1.0 / in1[33];
  t8 = muDoubleScalarCos(in1[20]);
  st.site = &t_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  t136 = in1[2] * in1[2];
  st.site = &u_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  t137 = in1[3] * in1[3];
  st.site = &v_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  t140 = in1[18] * in1[18];
  t15 = muDoubleScalarSin(in1[20]);
  st.site = &w_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  t142 = 1.0 / (t15 * t15);
  st.site = &x_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  st.site = &y_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  t43 = in1[33] * in1[33];
  t145_tmp = t43 * (t8 * t8);
  st.site = &ab_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  st.site = &bb_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  st.site = &cb_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  st.site = &db_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  st.site = &eb_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  st.site = &fb_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  t158 = 1.0 / t43 * (t136 * t136 - t137 * t137) + t140 * t140 * (1.0 /
    muDoubleScalarPower(t15, 4.0)) * ((t145_tmp - 1.0) * (t145_tmp - 1.0)) * 6.0;
  t159 = t158 * 3.1415926535897931 / 4.0;
  st.site = &gb_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  t163_tmp = t3 * t48;
  t166 = ((((t16 * t125 + t163_tmp) + t402) + t374 * t32 * t36) - t5 * t127) -
    t125_tmp * t73;
  t168_tmp = s * t48;
  t172 = ((((t168_tmp + t16 * t115) + t238) + t399 * t32 * t36) - t5 * t118) -
    t115_tmp * t73;
  t8 = t40 * t16 * 6.0;
  t174 = t20 + t8;
  t402 = t3 * t14;
  t175_tmp = t402 * 3.0;
  t178_tmp = t396 * t36;
  t178 = ((t91 + t4 * t42) + t5 * t44) - t178_tmp * t73;
  t15 = t351 * t16 * 4.0;
  t180 = t18 + t15;
  t181 = t22 - t23;
  t184_tmp = t20_tmp * t36;
  t184 = ((t106 + t4 * t76) + t5 * t78) - t184_tmp * t73;
  t185_tmp = s * t14;
  b_t185_tmp = t185_tmp * 2.0;
  t190_tmp = t4 * t103;
  b_t190_tmp = t16 * t105;
  c_t190_tmp = t105_tmp * t73;
  d_t190_tmp = t374 * t35 * t36;
  t190 = ((((t101 - t78_tmp) + t190_tmp) + b_t190_tmp) + c_t190_tmp) +
    d_t190_tmp;
  t198_tmp = t4 * t88;
  b_t198_tmp = t16 * t90;
  c_t198_tmp = t90_tmp * t73;
  d_t198_tmp = t399 * t35 * t36;
  t198 = ((((t85 - t44_tmp) + t198_tmp) + b_t198_tmp) + c_t198_tmp) + d_t198_tmp;
  t203 = t26 - t27;
  t204_tmp = t3 * t17 * 3.0;
  t205_tmp = -t21 + t29;
  t205 = (t205_tmp + t175_tmp) + t204_tmp;
  t212_tmp = s * t17 * 2.0;
  t213_tmp = -t19 + t25;
  t213 = (t213_tmp + b_t185_tmp) + t212_tmp;
  st.site = &hb_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  t217 = muDoubleScalarPower(muDoubleScalarAbs(((((((((((t166 * in2[23] + t172 *
    in2[22]) + t174 * in2[15]) + t178 * in2[18]) + t180 * in2[14]) + t181 * in2
    [16]) + t184 * in2[19]) - t190 * in2[21]) - t198 * in2[20]) - t203 * in2[17])
    - t205 * in2[13]) - t213 * in2[12]), in1[11] - 1.0);
  t226 = ((((t101 + t16 * t78) + t26_tmp * t39) + t393 * t36 * t39) - t2 * t76)
    - t184_tmp * t48;
  t231 = ((((t85 + t16 * t44) + t23_tmp * t39) + t383 * t36 * t39) - t2 * t42) -
    t178_tmp * t48;
  t74 = t20_tmp * t16 * 6.0;
  t234 = t28 + t74;
  t237 = ((t91 + t2 * t88) + t5 * t90) - t90_tmp * t48;
  t238 = t396 * t16 * 4.0;
  t239 = t24 + t238;
  t242 = ((t106 + t2 * t103) + t5 * t105) - t105_tmp * t48;
  t243_tmp = t20 - t8;
  t251_tmp = t5 * t125;
  b_t251_tmp = t16 * t127;
  c_t251_tmp = t125_tmp * t48;
  d_t251_tmp = t393 * t32 * t36;
  t251 = ((((t128 - t103_tmp) + t251_tmp) + b_t251_tmp) + c_t251_tmp) +
    d_t251_tmp;
  t259_tmp = t5 * t115;
  b_t259_tmp = t16 * t118;
  c_t259_tmp = t115_tmp * t48;
  d_t259_tmp = t383 * t32 * t36;
  t259 = ((((t116 - t88_tmp) + t259_tmp) + b_t259_tmp) + c_t259_tmp) +
    d_t259_tmp;
  t261 = ((t21 - t29) + t175_tmp) + t204_tmp;
  t264 = t18 - t15;
  t269 = ((t19 - t25) + b_t185_tmp) + t212_tmp;
  t8 = t251 * in2[23];
  t15 = t259 * in2[22];
  t43 = t261 * in2[15];
  t277 = t269 * in2[14];
  st.site = &ib_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  t332 = (((((t226 * in2[19] + t231 * in2[18]) + t234 * in2[17]) + t237 * in2[20])
           + t264 * in2[12]) + t239 * in2[16]) + t242 * in2[21];
  t273 = muDoubleScalarPower(muDoubleScalarAbs(((((t332 + t243_tmp * in2[13]) -
    t8) - t15) - t43) - t277), in1[11] - 1.0);
  st.site = &jb_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  t281 = muDoubleScalarPower(muDoubleScalarAbs(((((t332 - t8) - t15) - t43) -
    t277) + in2[13] * t243_tmp), in1[11] - 1.0);
  t282 = t40 * t39;
  t286 = ((((t128 + t16 * t103) + t87) + b_t20_tmp * t35 * t36) - t4 * t105) -
    t105_tmp * t51;
  t287 = t351 * t39;
  t291 = ((((t116 + t16 * t88) + t362) + t18_tmp * t35 * t36) - t4 * t90) -
    t90_tmp * t51;
  t292 = t26 + t27;
  t295 = ((t91 + t2 * t118) + t4 * t115) - t115_tmp * t51;
  t296 = t22 + t23;
  t299 = ((t106 + t2 * t127) + t4 * t125) - t125_tmp * t51;
  t304_tmp = t2 * t78;
  b_t304_tmp = t16 * t76;
  c_t304_tmp = t184_tmp * t51;
  d_t304_tmp = b_t20_tmp * t36 * t39;
  t304 = ((((t163_tmp - t282) + t304_tmp) + b_t304_tmp) + c_t304_tmp) +
    d_t304_tmp;
  b_t20_tmp = t2 * t44;
  t22 = t16 * t42;
  t23 = t178_tmp * t51;
  t35 = t18_tmp * t36 * t39;
  t312 = ((((t168_tmp - t287) + b_t20_tmp) + t22) + t23) + t35;
  t18_tmp = t28 - t74;
  t318 = ((t21 + t29) - t175_tmp) + t204_tmp;
  t127 = t295 * in2[22];
  t74 = t296 * in2[12];
  t44 = t24 - t238;
  t8 = t44 * in2[14];
  t15 = t299 * in2[23];
  t42 = ((t19 + t25) - b_t185_tmp) + t212_tmp;
  t43 = t304 * in2[19];
  t332 = t312 * in2[18];
  t40 = t318 * in2[17];
  t87 = t42 * in2[16];
  st.site = &kb_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  t125 = (t286 * in2[21] + t291 * in2[20]) + t292 * in2[13];
  t39 = muDoubleScalarPower(muDoubleScalarAbs(((((((((t125 + t18_tmp * in2[15])
    + t127) + t74) + t8) + t15) - t43) - t332) - t40) - t87), in1[11] - 1.0);
  st.site = &lb_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  t78 = muDoubleScalarPower(muDoubleScalarAbs(((((((((t125 + t127) + t74) + t8)
    + t15) - t43) - t332) - t40) - t87) + in2[15] * t18_tmp), in1[11] - 1.0);
  t76 = t2 * t36;
  t43 = s * t16 * 4.0 + t3 * t36 * t61;
  t90 = ((t43 + t76 * t84) + t21_tmp * t61 * t66) - t184_tmp * t53 * 2.0;
  t88 = (((-t108 + t110) + t130_tmp) + t76 * t113) - t105_tmp * t53 * 2.0;
  t106 = (((-t109 + t112_tmp) + t131) + t76 * t132) - t125_tmp * t53 * 2.0;
  t91 = ((((-t93 + t96) + t120_tmp) + t121_tmp) + t76 * t100) - t90_tmp * t53 *
    2.0;
  t332 = t76 * t123;
  t277 = t16 * 2.0 + s * t36 * t61;
  t351 = ((t277 + t76 * t65) + t19_tmp * t61 * t66) - t178_tmp * t53 * 2.0;
  t17 = t115_tmp * t53 * 2.0;
  t20_tmp = t100_tmp - t99_tmp;
  t362 = ((t20_tmp - t122) - t332) + t17;
  st.site = &mb_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  t118 = muDoubleScalarPower(muDoubleScalarAbs(((((t90 * in2[19] + t88 * in2[21])
    + t106 * in2[23]) + t91 * in2[20]) + t351 * in2[18]) - t362 * in2[22]), in1
    [11] - 1.0);
  t115 = t4 * t36;
  t127 = ((t43 + t115 * t113) + t29_tmp * t61 * t66) - t105_tmp * t56 * 2.0;
  t14 = t115 * t84;
  t103 = (((t82 - t83) + t133) + t115 * t132) - t125_tmp * t56 * 2.0;
  t374 = t115 * t65;
  t26_tmp = t65_tmp - t64;
  t105 = ((t26_tmp + t124) + t115 * t123) - t115_tmp * t56 * 2.0;
  t32 = ((t277 + t115 * t100) + t25_tmp * t61 * t66) - t90_tmp * t56 * 2.0;
  t87 = t108 + t110;
  t238 = t184_tmp * t56 * 2.0;
  t383 = ((t87 - t130_tmp) + t14) - t238;
  t8 = t93 + t96;
  t15 = t178_tmp * t56 * 2.0;
  t396 = (((t8 - t120_tmp) - t121_tmp) + t374) - t15;
  st.site = &nb_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  t393 = muDoubleScalarPower(muDoubleScalarAbs(((((t127 * in2[21] + t383 * in2
    [19]) + t103 * in2[23]) + t396 * in2[18]) + t105 * in2[22]) + t32 * in2[20]),
    in1[11] - 1.0);
  t23_tmp = t5 * t36;
  t399 = ((t43 + t23_tmp * t132) + t402 * t61 * t66) - t125_tmp * t59 * 2.0;
  t74 = t23_tmp * t84;
  t402 = (((-t82 + t83) + t133) + t23_tmp * t113) - t105_tmp * t59 * 2.0;
  t43 = t23_tmp * t65;
  t40 = t23_tmp * t100;
  t125 = ((t277 + t23_tmp * t123) + t185_tmp * t61 * t66) - t115_tmp * t59 * 2.0;
  out1[0] = ((t19 - s * t11 * 2.0) - b_t185_tmp) - t212_tmp;
  out1[1] = ((t21 - t3 * t11 * 3.0) - t175_tmp) - t204_tmp;
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
  out1[15] = (t205_tmp - t175_tmp) - t204_tmp;
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
  out1[29] = ((-t21 - t29) + t175_tmp) - t204_tmp;
  out1[30] = ((((t287 - t168_tmp) - b_t20_tmp) - t22) - t23) - t35;
  out1[31] = ((((t282 - t163_tmp) - t304_tmp) - b_t304_tmp) - c_t304_tmp) -
    d_t304_tmp;
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
  out1[43] = t90;
  out1[44] = t91;
  out1[45] = t88;
  out1[46] = ((((-t94 - t95) + t99_tmp) + t122) + t332) - t17;
  out1[47] = t106;
  out1[48] = 0.0;
  out1[49] = 0.0;
  out1[50] = 0.0;
  out1[51] = 0.0;
  out1[52] = 0.0;
  out1[53] = 0.0;
  out1[54] = (((t8 + t374) - t120_tmp) - t121_tmp) - t15;
  out1[55] = ((t87 + t14) - t130_tmp) - t238;
  out1[56] = t32;
  out1[57] = t127;
  out1[58] = t105;
  out1[59] = t103;
  out1[60] = 0.0;
  out1[61] = 0.0;
  out1[62] = 0.0;
  out1[63] = 0.0;
  out1[64] = 0.0;
  out1[65] = 0.0;
  t15 = t178_tmp * t59 * 2.0;
  out1[66] = (((t100_tmp + t122) + t43) - t99_tmp) - t15;
  t8 = t184_tmp * t59 * 2.0;
  out1[67] = (((t109 + t131) + t74) - t112_tmp) - t8;
  t87 = t90_tmp * t59 * 2.0;
  out1[68] = ((((-t62 - t63) + t64) + t124) + t40) - t87;
  out1[69] = t402;
  out1[70] = t125;
  out1[71] = t399;
  t332 = (((t109 - t112_tmp) + t131) + t74) - t8;
  t43 = ((t20_tmp + t122) + t43) - t15;
  t74 = ((t26_tmp - t124) - t40) + t87;
  st.site = &ob_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  t15 = muDoubleScalarPower(muDoubleScalarAbs(((((t399 * in2[23] + t332 * in2[19])
    + t402 * in2[21]) + t43 * in2[18]) + t125 * in2[22]) - t74 * in2[20]), in1
    [11] - 1.0);
  t8 = in1[33];
  st.site = &pb_emlrtRSI;
  b_sqrt(&st, &t8);
  t277 = 1.0 / t8;
  t87 = in1[1] * t134;
  t8 = t87 * (t134 * (t136 - t137) - t140 * t142 * (t145_tmp - 1.0) * 6.0) *
    3.1415926535897931;
  out2[0] = t8 * (((t5 * t48 - t4 * t51) + t2 * t70) + t16 * t73) / 3.0;
  out2[1] = t8 * (((t2 * t51 + t16 * t48) + t4 * t70) - t5 * t73) / 3.0;
  out2[2] = t8 * ((((-t2 * t48 + t16 * t51) + t5 * t70) + t4 * t73) - 1.0);
  t8 = t134 * t140 * t142 * (t145_tmp - 1.0) * (in1[19] * in1[19]) *
    3.1415926535897931;
  out2[3] = t87 * (t159 - t8 * 3.0) * (((t5 * t56 * 2.0 - t4 * t59 * 2.0) + t16 *
    t53 * 2.0) + t76 * t61);
  out2[4] = t87 * (t159 - t8 * 2.9999999999999991) * (((t5 * t53 * -2.0 + t2 *
    t59 * 2.0) + t16 * t56 * 2.0) + t115 * t61);
  out2[5] = t87 * t158 * 3.1415926535897931 * (((t4 * t53 * 2.0 - t2 * t56 * 2.0)
    + t16 * t59 * 2.0) + t23_tmp * t61) / 6.0;
  out3[0] = ((((((((((-in1[5] * t166 * t217 * in2[23] - in1[5] * t174 * t217 *
                      in2[15]) - in1[5] * t172 * t217 * in2[22]) - in1[5] * t180
                    * t217 * in2[14]) - in1[5] * t178 * t217 * in2[18]) - in1[5]
                  * t181 * t217 * in2[16]) - in1[5] * t184 * t217 * in2[19]) +
                in1[5] * t190 * t217 * in2[21]) + in1[5] * t198 * t217 * in2[20])
              + in1[5] * t205 * t217 * in2[13]) + in1[5] * t203 * t217 * in2[17])
    + in1[5] * t213 * t217 * in2[12];
  out3[1] = ((((((((((-in1[6] * t234 * t273 * in2[17] - in1[6] * t226 * t281 *
                      in2[19]) - in1[6] * t243_tmp * t273 * in2[13]) - in1[6] *
                    t231 * t281 * in2[18]) - in1[6] * t239 * t281 * in2[16]) -
                  in1[6] * t237 * t281 * in2[20]) - in1[6] * t242 * t281 * in2
                 [21]) + in1[6] * t251 * t281 * in2[23]) + in1[6] * t261 * t281 *
               in2[15]) - in1[6] * t264 * t281 * in2[12]) + in1[6] * t259 * t281
             * in2[22]) + in1[6] * t269 * t281 * in2[14];
  out3[2] = ((((((((((-in1[7] * t292 * t39 * in2[13] - in1[7] * t286 * t78 *
                      in2[21]) - in1[7] * t296 * t78 * in2[12]) - in1[7] * t291 *
                    t78 * in2[20]) - in1[7] * t295 * t78 * in2[22]) - in1[7] *
                  t299 * t78 * in2[23]) + in1[7] * t304 * t78 * in2[19]) + in1[7]
                * t312 * t78 * in2[18]) + in1[7] * t318 * t78 * in2[17]) - in1[7]
              * t44 * t78 * in2[14]) - in1[7] * t39 * t18_tmp * in2[15]) + in1[7]
    * t42 * t78 * in2[16];
  out3[3] = ((((-in1[8] * t90 * t118 * in2[19] - in1[8] * t88 * t118 * in2[21])
               - in1[8] * t91 * t118 * in2[20]) - in1[8] * t106 * t118 * in2[23])
             - in1[8] * t351 * t118 * in2[18]) + in1[8] * t362 * t118 * in2[22];
  out3[4] = ((((-in1[9] * t127 * t393 * in2[21] - in1[9] * t103 * t393 * in2[23])
               - in1[9] * t105 * t393 * in2[22]) - in1[9] * t32 * t393 * in2[20])
             - in1[9] * t383 * t393 * in2[19]) - in1[9] * t393 * t396 * in2[18];
  out3[5] = ((((-in1[10] * t399 * t15 * in2[23] - in1[10] * t402 * t15 * in2[21])
               - in1[10] * t125 * t15 * in2[22]) - in1[10] * t332 * t15 * in2[19])
             - in1[10] * t43 * t15 * in2[18]) + in1[10] * t74 * t15 * in2[20];
  out4[0] = 0.0;
  out4[1] = 0.0;
  out4[2] = -t140 * t142 * (t145_tmp - 1.0) * 3.1415926535897931 * (((((in1[21]
    + in1[22]) + in1[23]) + in1[24]) + in1[25]) + in1[26]);
  t87 = in1[21] * in1[19] * t140 * t142 * (t145_tmp - 1.0) * t277 *
    3.1415926535897931;
  t74 = in1[22] * in1[19] * t140 * t142 * (t145_tmp - 1.0) * t277 *
    3.1415926535897931;
  t15 = in1[23] * in1[19] * t140 * t142 * (t145_tmp - 1.0) * t277 *
    3.1415926535897931;
  t43 = in1[24] * in1[19] * t140 * t142 * (t145_tmp - 1.0) * t277 *
    3.1415926535897931;
  t332 = in1[25] * in1[19] * t140 * t142 * (t145_tmp - 1.0) * t277 *
    3.1415926535897931;
  t8 = in1[26] * in1[19] * t140 * t142 * (t145_tmp - 1.0) * t277 *
    3.1415926535897931;
  out4[3] = ((((t87 * -0.91522491349480972 - t74 * 0.91522491349480972) + t15 *
               0.1086532638769295) + t43 * 0.80657164961788008) + t332 *
             0.80657164961787986) + t8 * 0.1086532638769295;
  out4[4] = ((((t87 * -0.40294336787992679 + t74 * 0.40294336787992691) + t15 *
               0.99407970920288391) + t43 * 0.59113634132295712) - t332 *
             0.59113634132295745) - t8 * 0.99407970920288391;
  out4[5] = 0.0;
}

void sprdmpF13(const emlrtStack *sp, const real_T in1[34], const real_T in2[24],
               real_T s, real_T out1[72], real_T out2[6], real_T out3[6], real_T
               out4[6], real_T out5[3])
{
  real_T t3;
  real_T t87;
  real_T t74;
  real_T t2;
  real_T t332;
  real_T t277;
  real_T t4;
  real_T t125;
  real_T t127;
  real_T t5;
  real_T t8;
  real_T t11;
  real_T t14;
  real_T t15;
  real_T t16;
  real_T t17;
  real_T t18_tmp;
  real_T t322;
  real_T t18;
  real_T t19_tmp;
  real_T t19;
  real_T t20_tmp;
  real_T b_t20_tmp;
  real_T t20;
  real_T t21_tmp;
  real_T t21;
  real_T t393;
  real_T t22;
  real_T t23_tmp;
  real_T t23;
  real_T t399;
  real_T t24;
  real_T t25_tmp;
  real_T t25;
  real_T t348;
  real_T t26;
  real_T t396;
  real_T t27;
  real_T t374;
  real_T t28;
  real_T t29_tmp;
  real_T t29;
  real_T t32;
  real_T t35;
  real_T t36;
  real_T t39;
  real_T t40;
  real_T t238;
  real_T t42;
  real_T t43;
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
  real_T t402;
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
  real_T t370;
  real_T t115_tmp;
  real_T t115;
  real_T t116;
  real_T t373;
  real_T t118;
  real_T t120_tmp;
  real_T t121_tmp;
  real_T t122;
  real_T t123;
  real_T t124;
  real_T t125_tmp;
  real_T t128;
  real_T t130_tmp;
  real_T t131;
  real_T t132;
  real_T t133;
  real_T t134;
  real_T t136;
  real_T t137;
  real_T t140;
  real_T t142;
  real_T t145_tmp;
  real_T t158;
  real_T t159;
  real_T t163_tmp;
  real_T t166;
  real_T t168_tmp;
  real_T t172;
  real_T t174;
  real_T t175_tmp;
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
  real_T t287;
  real_T t291;
  real_T t292;
  real_T t295;
  real_T t296;
  real_T t299;
  real_T t304_tmp;
  real_T b_t304_tmp;
  real_T c_t304_tmp;
  real_T d_t304_tmp;
  real_T t304;
  real_T t312_tmp;
  real_T t312;
  real_T t330_tmp;
  real_T t318;
  real_T t326;
  real_T t329;
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
  st.site = &m_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  t3 = s * s;
  t87 = in2[6] * s;
  t74 = in2[7] * t3;
  t2 = t87 + t74;
  t332 = in2[8] * s;
  t277 = in2[9] * t3;
  t4 = t332 + t277;
  t125 = in2[10] * s;
  t127 = in2[11] * t3;
  t5 = t125 + t127;
  st.site = &n_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  t8 = t2 * t2;
  st.site = &o_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  t11 = t4 * t4;
  st.site = &p_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  t14 = t5 * t5;
  t15 = ((-t8 - t11) - t14) + 1.0;
  t16 = t15;
  st.site = &q_emlrtRSI;
  b_sqrt(&st, &t16);
  t17 = ((t8 + t11) + t14) - 1.0;
  t18_tmp = s * t2;
  t322 = t18_tmp * t4;
  t18 = t322 * 4.0;
  t19_tmp = s * t8;
  t19 = t19_tmp * 2.0;
  t20_tmp = t2 * t3;
  b_t20_tmp = t20_tmp * t4;
  t20 = b_t20_tmp * 6.0;
  t21_tmp = t3 * t8;
  t21 = t21_tmp * 3.0;
  t393 = t18_tmp * t5;
  t22 = t393 * 4.0;
  t23_tmp = s * t4;
  t23 = t23_tmp * t16 * 4.0;
  t399 = t23_tmp * t5;
  t24 = t399 * 4.0;
  t25_tmp = s * t11;
  t25 = t25_tmp * 2.0;
  t348 = t3 * t4;
  t26 = t348 * t16 * 6.0;
  t396 = t20_tmp * t5;
  t27 = t396 * 6.0;
  t374 = t348 * t5;
  t28 = t374 * 6.0;
  t29_tmp = t3 * t11;
  t29 = t29_tmp * 3.0;
  t32 = (in2[4] * s * 2.0 + in2[5] * t3 * 3.0) + 1.0;
  t35 = in2[2] * s * 2.0 + in2[3] * t3 * 3.0;
  t8 = t15;
  st.site = &r_emlrtRSI;
  b_sqrt(&st, &t8);
  t36 = 1.0 / t8;
  t39 = in2[0] * s * 2.0 + in2[1] * t3 * 3.0;
  t40 = s * t35;
  t238 = t18_tmp * t32;
  t42 = t40 + t238 * t36;
  t43 = s * t32;
  t44_tmp = t18_tmp * t35;
  t44 = t43 - t44_tmp * t36;
  t48 = (t16 * t35 + t2 * t32) - t5 * t39;
  t51 = (t16 * t32 + t4 * t39) - t2 * t35;
  t53 = in2[6] + in2[7] * s * 2.0;
  t56 = in2[8] + in2[9] * s * 2.0;
  t59 = in2[10] + in2[11] * s * 2.0;
  t61 = (t2 * t53 * 2.0 + t4 * t56 * 2.0) + t5 * t59 * 2.0;
  t62 = t87 * 2.0;
  t63 = t74 * 2.0;
  t64 = s * t53 * 2.0;
  t65_tmp = t62 + t63;
  t65 = t65_tmp + t64;
  st.site = &s_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  if (t15 < 0.0) {
    c_st.site = &rb_emlrtRSI;
    error(&c_st);
  }

  t66 = 1.0 / muDoubleScalarPower(t15, 1.5);
  t70 = (t2 * t39 + t4 * t35) + t5 * t32;
  t73 = (t16 * t39 + t5 * t35) - t4 * t32;
  t74 = t3 * t35;
  t402 = t20_tmp * t32;
  t76 = t74 + t402 * t36;
  t8 = t3 * t32;
  t78_tmp = t20_tmp * t35;
  t78 = t8 - t78_tmp * t36;
  t82 = t18_tmp * 4.0;
  t83 = t3 * t53 * 2.0;
  t84 = t82 + t83;
  t85 = s * t51;
  t87 = s * t39;
  t88_tmp = t23_tmp * t32;
  t88 = t87 - t88_tmp * t36;
  t90_tmp = t23_tmp * t36;
  t90 = t43 + t90_tmp * t39;
  t91 = s * t70;
  t93 = s * t59 * 2.0;
  t94 = t332 * 2.0;
  t95 = t277 * 2.0;
  t96 = t322 * t61 * t66;
  t99_tmp = s * t56 * 2.0;
  t100_tmp = t94 + t95;
  t100 = t100_tmp + t99_tmp;
  t101 = t3 * t51;
  t15 = t3 * t39;
  t103_tmp = t348 * t32;
  t103 = t15 - t103_tmp * t36;
  t105_tmp = t348 * t36;
  t105 = t8 + t105_tmp * t39;
  t106 = t3 * t70;
  t108 = t3 * t59 * 2.0;
  t109 = t23_tmp * 4.0;
  t110 = b_t20_tmp * t61 * t66;
  t112_tmp = t3 * t56 * 2.0;
  t113 = t109 + t112_tmp;
  t370 = s * t5;
  t115_tmp = t370 * t36;
  t115 = t40 - t115_tmp * t39;
  t116 = s * t73;
  t373 = t370 * t35;
  t118 = t87 + t373 * t36;
  t120_tmp = t125 * 2.0;
  t121_tmp = t127 * 2.0;
  t122 = t393 * t61 * t66;
  t123 = (t93 + t120_tmp) + t121_tmp;
  t124 = t399 * t61 * t66;
  t40 = t3 * t5;
  t125_tmp = t40 * t36;
  t125 = t74 - t125_tmp * t39;
  t87 = t40 * t35;
  t127 = t15 + t87 * t36;
  t128 = t3 * t73;
  t130_tmp = t370 * 4.0;
  t131 = t396 * t61 * t66;
  t132 = t108 + t130_tmp;
  t133 = t374 * t61 * t66;
  t134 = 1.0 / in1[33];
  t8 = muDoubleScalarCos(in1[20]);
  st.site = &t_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  t136 = in1[2] * in1[2];
  st.site = &u_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  t137 = in1[3] * in1[3];
  st.site = &v_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  t140 = in1[18] * in1[18];
  t15 = muDoubleScalarSin(in1[20]);
  st.site = &w_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  t142 = 1.0 / (t15 * t15);
  st.site = &x_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  st.site = &y_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  t43 = in1[33] * in1[33];
  t145_tmp = t43 * (t8 * t8);
  st.site = &ab_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  st.site = &bb_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  st.site = &cb_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  st.site = &db_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  st.site = &eb_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  st.site = &fb_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  t158 = 1.0 / t43 * (t136 * t136 - t137 * t137) + t140 * t140 * (1.0 /
    muDoubleScalarPower(t15, 4.0)) * ((t145_tmp - 1.0) * (t145_tmp - 1.0)) * 6.0;
  t159 = t158 * 3.1415926535897931 / 4.0;
  st.site = &gb_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  t163_tmp = t3 * t48;
  t166 = ((((t16 * t125 + t163_tmp) + t402) + t374 * t32 * t36) - t5 * t127) -
    t125_tmp * t73;
  t168_tmp = s * t48;
  t172 = ((((t168_tmp + t16 * t115) + t238) + t399 * t32 * t36) - t5 * t118) -
    t115_tmp * t73;
  t8 = t40 * t16 * 6.0;
  t174 = t20 + t8;
  t402 = t3 * t14;
  t175_tmp = t402 * 3.0;
  t178_tmp = t18_tmp * t36;
  t178 = ((t91 + t4 * t42) + t5 * t44) - t178_tmp * t73;
  t15 = t370 * t16 * 4.0;
  t180 = t18 + t15;
  t181 = t22 - t23;
  t184_tmp = t20_tmp * t36;
  t184 = ((t106 + t4 * t76) + t5 * t78) - t184_tmp * t73;
  t185_tmp = s * t14;
  b_t185_tmp = t185_tmp * 2.0;
  t190_tmp = t4 * t103;
  b_t190_tmp = t16 * t105;
  c_t190_tmp = t105_tmp * t73;
  d_t190_tmp = t374 * t35 * t36;
  t190 = ((((t101 - t78_tmp) + t190_tmp) + b_t190_tmp) + c_t190_tmp) +
    d_t190_tmp;
  t198_tmp = t4 * t88;
  b_t198_tmp = t16 * t90;
  c_t198_tmp = t90_tmp * t73;
  d_t198_tmp = t399 * t35 * t36;
  t198 = ((((t85 - t44_tmp) + t198_tmp) + b_t198_tmp) + c_t198_tmp) + d_t198_tmp;
  t203 = t26 - t27;
  t204_tmp = t3 * t17 * 3.0;
  t205_tmp = -t21 + t29;
  t205 = (t205_tmp + t175_tmp) + t204_tmp;
  t212_tmp = s * t17 * 2.0;
  t213_tmp = -t19 + t25;
  t213 = (t213_tmp + b_t185_tmp) + t212_tmp;
  st.site = &hb_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  t217 = muDoubleScalarPower(muDoubleScalarAbs(((((((((((t166 * in2[23] + t172 *
    in2[22]) + t174 * in2[15]) + t178 * in2[18]) + t180 * in2[14]) + t181 * in2
    [16]) + t184 * in2[19]) - t190 * in2[21]) - t198 * in2[20]) - t203 * in2[17])
    - t205 * in2[13]) - t213 * in2[12]), in1[11] - 1.0);
  t226 = ((((t101 + t16 * t78) + t348 * t39) + t396 * t36 * t39) - t2 * t76) -
    t184_tmp * t48;
  t231 = ((((t85 + t16 * t44) + t23_tmp * t39) + t393 * t36 * t39) - t2 * t42) -
    t178_tmp * t48;
  t74 = t20_tmp * t16 * 6.0;
  t234 = t28 + t74;
  t237 = ((t91 + t2 * t88) + t5 * t90) - t90_tmp * t48;
  t238 = t18_tmp * t16 * 4.0;
  t239 = t24 + t238;
  t242 = ((t106 + t2 * t103) + t5 * t105) - t105_tmp * t48;
  t243_tmp = t20 - t8;
  t251_tmp = t5 * t125;
  b_t251_tmp = t16 * t127;
  c_t251_tmp = t125_tmp * t48;
  d_t251_tmp = t396 * t32 * t36;
  t251 = ((((t128 - t103_tmp) + t251_tmp) + b_t251_tmp) + c_t251_tmp) +
    d_t251_tmp;
  t259_tmp = t5 * t115;
  b_t259_tmp = t16 * t118;
  c_t259_tmp = t115_tmp * t48;
  d_t259_tmp = t393 * t32 * t36;
  t259 = ((((t116 - t88_tmp) + t259_tmp) + b_t259_tmp) + c_t259_tmp) +
    d_t259_tmp;
  t261 = ((t21 - t29) + t175_tmp) + t204_tmp;
  t264 = t18 - t15;
  t269 = ((t19 - t25) + b_t185_tmp) + t212_tmp;
  t8 = t251 * in2[23];
  t15 = t259 * in2[22];
  t43 = t261 * in2[15];
  t277 = t269 * in2[14];
  st.site = &ib_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  t332 = (((((t226 * in2[19] + t231 * in2[18]) + t234 * in2[17]) + t237 * in2[20])
           + t264 * in2[12]) + t239 * in2[16]) + t242 * in2[21];
  t273 = muDoubleScalarPower(muDoubleScalarAbs(((((t332 + t243_tmp * in2[13]) -
    t8) - t15) - t43) - t277), in1[11] - 1.0);
  st.site = &jb_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  t281 = muDoubleScalarPower(muDoubleScalarAbs(((((t332 - t8) - t15) - t43) -
    t277) + in2[13] * t243_tmp), in1[11] - 1.0);
  t282 = t40 * t39;
  t286 = ((((t128 + t16 * t103) + t87) + b_t20_tmp * t35 * t36) - t4 * t105) -
    t105_tmp * t51;
  t287 = t370 * t39;
  t291 = ((((t116 + t16 * t88) + t373) + t322 * t35 * t36) - t4 * t90) - t90_tmp
    * t51;
  t292 = t26 + t27;
  t295 = ((t91 + t2 * t118) + t4 * t115) - t115_tmp * t51;
  t296 = t22 + t23;
  t299 = ((t106 + t2 * t127) + t4 * t125) - t125_tmp * t51;
  t304_tmp = t2 * t78;
  b_t304_tmp = t16 * t76;
  c_t304_tmp = t184_tmp * t51;
  d_t304_tmp = b_t20_tmp * t36 * t39;
  t304 = ((((t163_tmp - t282) + t304_tmp) + b_t304_tmp) + c_t304_tmp) +
    d_t304_tmp;
  t312_tmp = t2 * t44;
  t44 = t16 * t42;
  t42 = t178_tmp * t51;
  t22 = t322 * t36 * t39;
  t312 = ((((t168_tmp - t287) + t312_tmp) + t44) + t42) + t22;
  t330_tmp = t28 - t74;
  t318 = ((t21 + t29) - t175_tmp) + t204_tmp;
  t127 = t295 * in2[22];
  t74 = t296 * in2[12];
  t322 = t24 - t238;
  t8 = t322 * in2[14];
  t15 = t299 * in2[23];
  t326 = ((t19 + t25) - b_t185_tmp) + t212_tmp;
  t43 = t304 * in2[19];
  t332 = t312 * in2[18];
  t40 = t318 * in2[17];
  t87 = t326 * in2[16];
  st.site = &kb_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  t125 = (t286 * in2[21] + t291 * in2[20]) + t292 * in2[13];
  t329 = muDoubleScalarPower(muDoubleScalarAbs(((((((((t125 + t330_tmp * in2[15])
    + t127) + t74) + t8) + t15) - t43) - t332) - t40) - t87), in1[11] - 1.0);
  st.site = &lb_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  t23 = muDoubleScalarPower(muDoubleScalarAbs(((((((((t125 + t127) + t74) + t8)
    + t15) - t43) - t332) - t40) - t87) + in2[15] * t330_tmp), in1[11] - 1.0);
  b_t20_tmp = t2 * t36;
  t40 = s * t16 * 4.0 + t3 * t36 * t61;
  t106 = ((t40 + b_t20_tmp * t84) + t21_tmp * t61 * t66) - t184_tmp * t53 * 2.0;
  t91 = (((-t108 + t110) + t130_tmp) + b_t20_tmp * t113) - t105_tmp * t53 * 2.0;
  t78 = (((-t109 + t112_tmp) + t131) + b_t20_tmp * t132) - t125_tmp * t53 * 2.0;
  t76 = ((((-t93 + t96) + t120_tmp) + t121_tmp) + b_t20_tmp * t100) - t90_tmp *
    t53 * 2.0;
  t348 = b_t20_tmp * t123;
  t17 = t16 * 2.0 + s * t36 * t61;
  t118 = ((t17 + b_t20_tmp * t65) + t19_tmp * t61 * t66) - t178_tmp * t53 * 2.0;
  t277 = t115_tmp * t53 * 2.0;
  t18_tmp = t100_tmp - t99_tmp;
  t115 = ((t18_tmp - t122) - t348) + t277;
  st.site = &mb_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  t90 = muDoubleScalarPower(muDoubleScalarAbs(((((t106 * in2[19] + t91 * in2[21])
    + t78 * in2[23]) + t76 * in2[20]) + t118 * in2[18]) - t115 * in2[22]), in1
    [11] - 1.0);
  t88 = t4 * t36;
  t370 = ((t40 + t88 * t113) + t29_tmp * t61 * t66) - t105_tmp * t56 * 2.0;
  t14 = t88 * t84;
  t373 = (((t82 - t83) + t133) + t88 * t132) - t125_tmp * t56 * 2.0;
  t374 = t88 * t65;
  t23_tmp = t65_tmp - t64;
  t103 = ((t23_tmp + t124) + t88 * t123) - t115_tmp * t56 * 2.0;
  t127 = ((t17 + t88 * t100) + t25_tmp * t61 * t66) - t90_tmp * t56 * 2.0;
  t43 = t108 + t110;
  t238 = t184_tmp * t56 * 2.0;
  t105 = ((t43 - t130_tmp) + t14) - t238;
  t8 = t93 + t96;
  t15 = t178_tmp * t56 * 2.0;
  t396 = (((t8 - t120_tmp) - t121_tmp) + t374) - t15;
  st.site = &nb_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  t393 = muDoubleScalarPower(muDoubleScalarAbs(((((t370 * in2[21] + t105 * in2
    [19]) + t373 * in2[23]) + t396 * in2[18]) + t103 * in2[22]) + t127 * in2[20]),
    in1[11] - 1.0);
  t20_tmp = t5 * t36;
  t399 = ((t40 + t20_tmp * t132) + t402 * t61 * t66) - t125_tmp * t59 * 2.0;
  t74 = t20_tmp * t84;
  t402 = (((-t82 + t83) + t133) + t20_tmp * t113) - t105_tmp * t59 * 2.0;
  t40 = t20_tmp * t65;
  t87 = t20_tmp * t100;
  t125 = ((t17 + t20_tmp * t123) + t185_tmp * t61 * t66) - t115_tmp * t59 * 2.0;
  out1[0] = ((t19 - s * t11 * 2.0) - b_t185_tmp) - t212_tmp;
  out1[1] = ((t21 - t3 * t11 * 3.0) - t175_tmp) - t204_tmp;
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
  out1[15] = (t205_tmp - t175_tmp) - t204_tmp;
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
  out1[29] = ((-t21 - t29) + t175_tmp) - t204_tmp;
  out1[30] = ((((t287 - t168_tmp) - t312_tmp) - t44) - t42) - t22;
  out1[31] = ((((t282 - t163_tmp) - t304_tmp) - b_t304_tmp) - c_t304_tmp) -
    d_t304_tmp;
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
  out1[42] = t118;
  out1[43] = t106;
  out1[44] = t76;
  out1[45] = t91;
  out1[46] = ((((-t94 - t95) + t99_tmp) + t122) + t348) - t277;
  out1[47] = t78;
  out1[48] = 0.0;
  out1[49] = 0.0;
  out1[50] = 0.0;
  out1[51] = 0.0;
  out1[52] = 0.0;
  out1[53] = 0.0;
  out1[54] = (((t8 + t374) - t120_tmp) - t121_tmp) - t15;
  out1[55] = ((t43 + t14) - t130_tmp) - t238;
  out1[56] = t127;
  out1[57] = t370;
  out1[58] = t103;
  out1[59] = t373;
  out1[60] = 0.0;
  out1[61] = 0.0;
  out1[62] = 0.0;
  out1[63] = 0.0;
  out1[64] = 0.0;
  out1[65] = 0.0;
  t43 = t178_tmp * t59 * 2.0;
  out1[66] = (((t100_tmp + t122) + t40) - t99_tmp) - t43;
  t8 = t184_tmp * t59 * 2.0;
  out1[67] = (((t109 + t131) + t74) - t112_tmp) - t8;
  t15 = t90_tmp * t59 * 2.0;
  out1[68] = ((((-t62 - t63) + t64) + t124) + t87) - t15;
  out1[69] = t402;
  out1[70] = t125;
  out1[71] = t399;
  t332 = (((t109 - t112_tmp) + t131) + t74) - t8;
  t43 = ((t18_tmp + t122) + t40) - t43;
  t74 = ((t23_tmp - t124) - t87) + t15;
  st.site = &ob_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  t15 = muDoubleScalarPower(muDoubleScalarAbs(((((t399 * in2[23] + t332 * in2[19])
    + t402 * in2[21]) + t43 * in2[18]) + t125 * in2[22]) - t74 * in2[20]), in1
    [11] - 1.0);
  t8 = in1[33];
  st.site = &pb_emlrtRSI;
  b_sqrt(&st, &t8);
  t277 = 1.0 / t8;
  t87 = in1[1] * t134;
  t8 = t87 * (t134 * (t136 - t137) - t140 * t142 * (t145_tmp - 1.0) * 6.0) *
    3.1415926535897931;
  out2[0] = t8 * (((t5 * t48 - t4 * t51) + t2 * t70) + t16 * t73) / 3.0;
  out2[1] = t8 * (((t2 * t51 + t16 * t48) + t4 * t70) - t5 * t73) / 3.0;
  out2[2] = t8 * ((((-t2 * t48 + t16 * t51) + t5 * t70) + t4 * t73) - 1.0);
  t8 = t134 * t140 * t142 * (t145_tmp - 1.0) * (in1[19] * in1[19]) *
    3.1415926535897931;
  out2[3] = t87 * (t159 - t8 * 3.0) * (((t5 * t56 * 2.0 - t4 * t59 * 2.0) + t16 *
    t53 * 2.0) + b_t20_tmp * t61);
  out2[4] = t87 * (t159 - t8 * 2.9999999999999991) * (((t5 * t53 * -2.0 + t2 *
    t59 * 2.0) + t16 * t56 * 2.0) + t88 * t61);
  out2[5] = t87 * t158 * 3.1415926535897931 * (((t4 * t53 * 2.0 - t2 * t56 * 2.0)
    + t16 * t59 * 2.0) + t20_tmp * t61) / 6.0;
  out3[0] = ((((((((((-in1[5] * t166 * t217 * in2[23] - in1[5] * t174 * t217 *
                      in2[15]) - in1[5] * t172 * t217 * in2[22]) - in1[5] * t180
                    * t217 * in2[14]) - in1[5] * t178 * t217 * in2[18]) - in1[5]
                  * t181 * t217 * in2[16]) - in1[5] * t184 * t217 * in2[19]) +
                in1[5] * t190 * t217 * in2[21]) + in1[5] * t198 * t217 * in2[20])
              + in1[5] * t205 * t217 * in2[13]) + in1[5] * t203 * t217 * in2[17])
    + in1[5] * t213 * t217 * in2[12];
  out3[1] = ((((((((((-in1[6] * t234 * t273 * in2[17] - in1[6] * t226 * t281 *
                      in2[19]) - in1[6] * t243_tmp * t273 * in2[13]) - in1[6] *
                    t231 * t281 * in2[18]) - in1[6] * t239 * t281 * in2[16]) -
                  in1[6] * t237 * t281 * in2[20]) - in1[6] * t242 * t281 * in2
                 [21]) + in1[6] * t251 * t281 * in2[23]) + in1[6] * t261 * t281 *
               in2[15]) - in1[6] * t264 * t281 * in2[12]) + in1[6] * t259 * t281
             * in2[22]) + in1[6] * t269 * t281 * in2[14];
  out3[2] = ((((((((((-in1[7] * t292 * t329 * in2[13] - in1[7] * t286 * t23 *
                      in2[21]) - in1[7] * t296 * t23 * in2[12]) - in1[7] * t291 *
                    t23 * in2[20]) - in1[7] * t295 * t23 * in2[22]) - in1[7] *
                  t299 * t23 * in2[23]) + in1[7] * t304 * t23 * in2[19]) + in1[7]
                * t312 * t23 * in2[18]) + in1[7] * t318 * t23 * in2[17]) - in1[7]
              * t322 * t23 * in2[14]) - in1[7] * t329 * t330_tmp * in2[15]) +
    in1[7] * t326 * t23 * in2[16];
  out3[3] = ((((-in1[8] * t106 * t90 * in2[19] - in1[8] * t91 * t90 * in2[21]) -
               in1[8] * t76 * t90 * in2[20]) - in1[8] * t78 * t90 * in2[23]) -
             in1[8] * t118 * t90 * in2[18]) + in1[8] * t115 * t90 * in2[22];
  out3[4] = ((((-in1[9] * t370 * t393 * in2[21] - in1[9] * t373 * t393 * in2[23])
               - in1[9] * t103 * t393 * in2[22]) - in1[9] * t127 * t393 * in2[20])
             - in1[9] * t105 * t393 * in2[19]) - in1[9] * t393 * t396 * in2[18];
  out3[5] = ((((-in1[10] * t399 * t15 * in2[23] - in1[10] * t402 * t15 * in2[21])
               - in1[10] * t125 * t15 * in2[22]) - in1[10] * t332 * t15 * in2[19])
             - in1[10] * t43 * t15 * in2[18]) + in1[10] * t74 * t15 * in2[20];
  out4[0] = 0.0;
  out4[1] = 0.0;
  out4[2] = -t140 * t142 * (t145_tmp - 1.0) * 3.1415926535897931 * (((((in1[21]
    + in1[22]) + in1[23]) + in1[24]) + in1[25]) + in1[26]);
  t87 = in1[21] * in1[19] * t140 * t142 * (t145_tmp - 1.0) * t277 *
    3.1415926535897931;
  t74 = in1[22] * in1[19] * t140 * t142 * (t145_tmp - 1.0) * t277 *
    3.1415926535897931;
  t15 = in1[23] * in1[19] * t140 * t142 * (t145_tmp - 1.0) * t277 *
    3.1415926535897931;
  t43 = in1[24] * in1[19] * t140 * t142 * (t145_tmp - 1.0) * t277 *
    3.1415926535897931;
  t332 = in1[25] * in1[19] * t140 * t142 * (t145_tmp - 1.0) * t277 *
    3.1415926535897931;
  t8 = in1[26] * in1[19] * t140 * t142 * (t145_tmp - 1.0) * t277 *
    3.1415926535897931;
  out4[3] = ((((t87 * -0.91522491349480972 - t74 * 0.91522491349480972) + t15 *
               0.1086532638769295) + t43 * 0.80657164961788008) + t332 *
             0.80657164961787986) + t8 * 0.1086532638769295;
  out4[4] = ((((t87 * -0.40294336787992679 + t74 * 0.40294336787992691) + t15 *
               0.99407970920288391) + t43 * 0.59113634132295712) - t332 *
             0.59113634132295745) - t8 * 0.99407970920288391;
  out4[5] = 0.0;
  out5[0] = t39;
  out5[1] = t35;
  out5[2] = t32;
}

/* End of code generation (sprdmpF13.c) */
