/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sprdmpF19.c
 *
 * Code generation for function 'sprdmpF19'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "sprdmpF19.h"
#include "sqrt.h"
#include "error.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 64,    /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 77,  /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 78,  /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 79,  /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 81,  /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 109, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 146, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 248, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 249, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 252, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 254, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 255, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 256, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 261, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 262, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 263, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 266, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 267, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 268, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 272, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 363, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 444, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 522, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 564, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 606, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 650,/* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 651,/* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo cb_emlrtRSI = { 674,/* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo db_emlrtRSI = { 678,/* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
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
void sprdmpF19(const emlrtStack *sp, const real_T in1[34], const real_T in2[36],
               real_T s, real_T out1[108], real_T out2[6], real_T out3[6],
               real_T out4[6], real_T out5[3], real_T out6[108], real_T out7[108],
               real_T *out8)
{
  real_T t2;
  real_T t92;
  real_T t90;
  real_T t102;
  real_T t3;
  real_T t143;
  real_T t187;
  real_T t191;
  real_T t4;
  real_T t548;
  real_T t5_tmp;
  real_T b_t5_tmp;
  real_T t5;
  real_T t9;
  real_T t13;
  real_T t17;
  real_T t18;
  real_T t19;
  real_T t20;
  real_T t21_tmp;
  real_T t511;
  real_T t21;
  real_T t22_tmp;
  real_T t22;
  real_T t23_tmp;
  real_T t520;
  real_T t23;
  real_T t514;
  real_T t24;
  real_T t480;
  real_T t25_tmp;
  real_T t494;
  real_T t25;
  real_T t501;
  real_T t26;
  real_T t27_tmp;
  real_T t27;
  real_T t28_tmp;
  real_T t28;
  real_T t29_tmp;
  real_T t29;
  real_T t30_tmp;
  real_T t30;
  real_T t31_tmp;
  real_T t31;
  real_T t32_tmp;
  real_T t32;
  real_T t33_tmp;
  real_T t33;
  real_T t34_tmp;
  real_T t34;
  real_T t35_tmp;
  real_T t35;
  real_T t36_tmp;
  real_T t36;
  real_T t37_tmp;
  real_T t37;
  real_T t38_tmp;
  real_T t38;
  real_T t42;
  real_T t46;
  real_T t47;
  real_T t51;
  real_T t53_tmp;
  real_T t53;
  real_T t54;
  real_T t56_tmp;
  real_T t56;
  real_T t59;
  real_T t63;
  real_T t66;
  real_T t70;
  real_T t74;
  real_T t76;
  real_T t77;
  real_T t78;
  real_T t79;
  real_T t80;
  real_T t81;
  real_T t82;
  real_T t86;
  real_T t89;
  real_T t91_tmp;
  real_T t91;
  real_T t94_tmp;
  real_T t94;
  real_T t98;
  real_T t99;
  real_T t100;
  real_T t103_tmp;
  real_T t103;
  real_T t104;
  real_T t474;
  real_T t106;
  real_T t108;
  real_T t109;
  real_T t110;
  real_T t111;
  real_T t113_tmp;
  real_T t113;
  real_T t115_tmp;
  real_T t115;
  real_T t116;
  real_T t118;
  real_T t119;
  real_T t120;
  real_T t121;
  real_T t122;
  real_T t124_tmp;
  real_T t125_tmp;
  real_T t125;
  real_T t127;
  real_T t128;
  real_T t130_tmp;
  real_T t130;
  real_T t132_tmp;
  real_T t132;
  real_T t134;
  real_T t135;
  real_T t136;
  real_T t138_tmp;
  real_T t139;
  real_T t141;
  real_T t142;
  real_T t144_tmp;
  real_T t144;
  real_T t146_tmp;
  real_T t146;
  real_T t148;
  real_T t149;
  real_T t150;
  real_T t153_tmp;
  real_T t154;
  real_T t156_tmp;
  real_T t588;
  real_T t156;
  real_T t157;
  real_T t158_tmp;
  real_T t158;
  real_T t160_tmp;
  real_T t161_tmp;
  real_T t162_tmp;
  real_T t163;
  real_T t164;
  real_T t165;
  real_T t167_tmp;
  real_T t167;
  real_T t168_tmp;
  real_T t168;
  real_T t169;
  real_T t171_tmp;
  real_T t172;
  real_T t173;
  real_T t174;
  real_T t177_tmp;
  real_T t178;
  real_T t180_tmp;
  real_T t181;
  real_T t182;
  real_T t183;
  real_T t184;
  real_T t190;
  real_T t192;
  real_T t195_tmp;
  real_T t197;
  real_T t208;
  real_T t209;
  real_T t212;
  real_T t213;
  real_T t215;
  real_T t216;
  real_T t217_tmp;
  real_T b_t217_tmp;
  real_T t218_tmp;
  real_T b_t218_tmp;
  real_T t222_tmp;
  real_T t225;
  real_T t227_tmp;
  real_T t230;
  real_T t233_tmp;
  real_T t236;
  real_T t238;
  real_T t239_tmp;
  real_T b_t239_tmp;
  real_T t242_tmp;
  real_T t242;
  real_T t245_tmp;
  real_T t245;
  real_T t248_tmp;
  real_T t248;
  real_T t249_tmp;
  real_T t250_tmp;
  real_T t250;
  real_T t255_tmp;
  real_T t256_tmp;
  real_T t256;
  real_T t257_tmp;
  real_T t258_tmp;
  real_T t258;
  real_T t263_tmp;
  real_T b_t263_tmp;
  real_T c_t263_tmp;
  real_T d_t263_tmp;
  real_T t263;
  real_T t268_tmp;
  real_T b_t268_tmp;
  real_T c_t268_tmp;
  real_T d_t268_tmp;
  real_T t268;
  real_T t279_tmp;
  real_T b_t279_tmp;
  real_T c_t279_tmp;
  real_T d_t279_tmp;
  real_T t279;
  real_T t284;
  real_T t294;
  real_T t303;
  real_T t305;
  real_T t309;
  real_T t313;
  real_T t319;
  real_T t321;
  real_T t322;
  real_T t325;
  real_T t328;
  real_T t331;
  real_T t332;
  real_T t333;
  real_T t336;
  real_T t339;
  real_T t340;
  real_T t351_tmp;
  real_T b_t351_tmp;
  real_T c_t351_tmp;
  real_T d_t351_tmp;
  real_T t351;
  real_T t356_tmp;
  real_T b_t356_tmp;
  real_T c_t356_tmp;
  real_T d_t356_tmp;
  real_T t356;
  real_T t364_tmp;
  real_T b_t364_tmp;
  real_T c_t364_tmp;
  real_T d_t364_tmp;
  real_T t364;
  real_T t382_tmp;
  real_T t366;
  real_T t368;
  real_T t370;
  real_T t372;
  real_T t376;
  real_T t377;
  real_T t378;
  real_T t379;
  real_T t380;
  real_T t381;
  real_T t375_tmp;
  real_T t375;
  real_T t383;
  real_T t384;
  real_T t390;
  real_T t394;
  real_T t399;
  real_T t400;
  real_T t403;
  real_T t406;
  real_T t409;
  real_T t410;
  real_T t412;
  real_T t415;
  real_T t417;
  real_T t418;
  real_T t423;
  real_T t428;
  real_T t439;
  real_T t460_tmp;
  real_T t446;
  real_T t448;
  real_T t450;
  real_T t454;
  real_T t455;
  real_T t456;
  real_T t457;
  real_T t458;
  real_T t459;
  real_T t453_tmp;
  real_T t453;
  real_T t463;
  real_T t465;
  real_T t467;
  real_T t469;
  real_T t471;
  real_T t473;
  real_T t477;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;

  /* SPRDMPF19 */
  /*     [OUT1,OUT2,OUT3,OUT4,OUT5,OUT6,OUT7,OUT8] = SPRDMPF19(IN1,IN2,S) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.2. */
  /*     04-Jan-2019 17:12:12 */
  st.site = &emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t2 = s * s;
  t92 = in2[9] * s;
  t90 = in2[10] * t2;
  t102 = in2[11] * s * t2;
  t3 = (t92 + t90) + t102;
  t143 = in2[12] * s;
  t187 = in2[13] * t2;
  t191 = in2[14] * s * t2;
  t4 = (t143 + t187) + t191;
  t548 = in2[15] * s;
  t5_tmp = in2[16] * t2;
  b_t5_tmp = in2[17] * s * t2;
  t5 = (t548 + t5_tmp) + b_t5_tmp;
  st.site = &b_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t9 = t3 * t3;
  st.site = &c_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t13 = t4 * t4;
  st.site = &d_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t17 = t5 * t5;
  t18 = ((-t9 - t13) - t17) + 1.0;
  t19 = t18;
  st.site = &e_emlrtRSI;
  b_sqrt(&st, &t19);
  t20 = ((t9 + t13) + t17) - 1.0;
  t21_tmp = s * t3;
  t511 = t21_tmp * t4;
  t21 = t511 * 4.0;
  t22_tmp = s * t9;
  t22 = t22_tmp * 2.0;
  t23_tmp = t2 * t3;
  t520 = t23_tmp * t4;
  t23 = t520 * 6.0;
  t514 = t2 * t9;
  t24 = t514 * 3.0;
  t480 = s * t2;
  t25_tmp = t480 * t3;
  t494 = t25_tmp * t4;
  t25 = t494 * 8.0;
  t501 = t480 * t9;
  t26 = t501 * 4.0;
  t27_tmp = s * t4;
  t27 = t27_tmp * t19 * 4.0;
  t28_tmp = t21_tmp * t5;
  t28 = t28_tmp * 4.0;
  t29_tmp = t27_tmp * t5;
  t29 = t29_tmp * 4.0;
  t30_tmp = s * t13;
  t30 = t30_tmp * 2.0;
  t31_tmp = t23_tmp * t5;
  t31 = t31_tmp * 6.0;
  t32_tmp = t2 * t4;
  t32 = t32_tmp * t19 * 6.0;
  t33_tmp = t32_tmp * t5;
  t33 = t33_tmp * 6.0;
  t34_tmp = t2 * t13;
  t34 = t34_tmp * 3.0;
  t35_tmp = t25_tmp * t5;
  t35 = t35_tmp * 8.0;
  t36_tmp = t480 * t4;
  t36 = t36_tmp * t19 * 8.0;
  t37_tmp = t36_tmp * t5;
  t37 = t37_tmp * 8.0;
  t38_tmp = t480 * t13;
  t38 = t38_tmp * 4.0;
  t42 = ((in2[6] * s * 2.0 + in2[7] * t2 * 3.0) + in2[8] * s * t2 * 4.0) + 1.0;
  t46 = (in2[3] * s * 2.0 + in2[4] * t2 * 3.0) + in2[5] * s * t2 * 4.0;
  t9 = t18;
  st.site = &f_emlrtRSI;
  b_sqrt(&st, &t9);
  t47 = 1.0 / t9;
  t51 = (in2[0] * s * 2.0 + in2[1] * t2 * 3.0) + in2[2] * s * t2 * 4.0;
  t9 = s * t42;
  t53_tmp = t21_tmp * t46;
  t53 = t9 - t53_tmp * t47;
  t54 = s * t46;
  t56_tmp = t21_tmp * t42;
  t56 = t54 + t56_tmp * t47;
  t59 = (t3 * t42 + t19 * t46) - t5 * t51;
  t63 = (t4 * t51 + t19 * t42) - t3 * t46;
  t66 = (in2[9] + in2[10] * s * 2.0) + in2[11] * t2 * 3.0;
  t70 = (in2[12] + in2[13] * s * 2.0) + in2[14] * t2 * 3.0;
  t74 = (in2[15] + in2[16] * s * 2.0) + in2[17] * t2 * 3.0;
  t76 = (t3 * t66 * 2.0 + t4 * t70 * 2.0) + t5 * t74 * 2.0;
  t77 = t92 * 2.0;
  t78 = s * t66 * 2.0;
  t79 = t90 * 2.0;
  t80 = t102 * 2.0;
  t81 = ((t77 + t78) + t79) + t80;
  st.site = &g_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  if (t18 < 0.0) {
    c_st.site = &fb_emlrtRSI;
    error(&c_st);
  }

  t82 = 1.0 / muDoubleScalarPower(t18, 1.5);
  t86 = (t3 * t51 + t4 * t46) + t5 * t42;
  t89 = (t5 * t46 + t19 * t51) - t4 * t42;
  t90 = t2 * t42;
  t91_tmp = t23_tmp * t46;
  t91 = t90 - t91_tmp * t47;
  t92 = t2 * t46;
  t94_tmp = t23_tmp * t42;
  t94 = t92 + t94_tmp * t47;
  t98 = t21_tmp * 4.0;
  t99 = t2 * t66 * 2.0;
  t100 = t98 + t99;
  t102 = t480 * t42;
  t103_tmp = t25_tmp * t46;
  t103 = t102 - t103_tmp * t47;
  t104 = t480 * t46;
  t474 = t25_tmp * t42;
  t106 = t104 + t474 * t47;
  t108 = t23_tmp * 6.0;
  t109 = t480 * t66 * 2.0;
  t110 = t108 + t109;
  t111 = s * t63;
  t18 = s * t51;
  t113_tmp = t27_tmp * t42;
  t113 = t18 - t113_tmp * t47;
  t115_tmp = t27_tmp * t47;
  t115 = t9 + t115_tmp * t51;
  t116 = s * t86;
  t118 = s * t74 * 2.0;
  t119 = t143 * 2.0;
  t120 = t187 * 2.0;
  t121 = t191 * 2.0;
  t122 = t511 * t76 * t82;
  t124_tmp = s * t70 * 2.0;
  t125_tmp = (t119 + t120) + t121;
  t125 = t125_tmp + t124_tmp;
  t127 = t2 * t63;
  t128 = t2 * t86;
  t9 = t2 * t51;
  t130_tmp = t32_tmp * t42;
  t130 = t9 - t130_tmp * t47;
  t132_tmp = t32_tmp * t47;
  t132 = t90 + t132_tmp * t51;
  t134 = t2 * t74 * 2.0;
  t135 = t27_tmp * 4.0;
  t136 = t520 * t76 * t82;
  t138_tmp = t2 * t70 * 2.0;
  t139 = t135 + t138_tmp;
  t141 = t480 * t63;
  t142 = t480 * t86;
  t143 = t480 * t51;
  t144_tmp = t36_tmp * t42;
  t144 = t143 - t144_tmp * t47;
  t146_tmp = t36_tmp * t47;
  t146 = t102 + t146_tmp * t51;
  t148 = t480 * t74 * 2.0;
  t149 = t32_tmp * 6.0;
  t150 = t494 * t76 * t82;
  t153_tmp = t480 * t70 * 2.0;
  t154 = t149 + t153_tmp;
  t156_tmp = s * t5;
  t588 = t156_tmp * t46;
  t156 = t18 + t588 * t47;
  t157 = s * t89;
  t158_tmp = t156_tmp * t47;
  t158 = t54 - t158_tmp * t51;
  t160_tmp = t548 * 2.0;
  t161_tmp = t5_tmp * 2.0;
  t162_tmp = b_t5_tmp * 2.0;
  t163 = t28_tmp * t76 * t82;
  t164 = ((t118 + t160_tmp) + t161_tmp) + t162_tmp;
  t165 = t29_tmp * t76 * t82;
  t5_tmp = t2 * t5;
  t167_tmp = t5_tmp * t46;
  t167 = t9 + t167_tmp * t47;
  t168_tmp = t5_tmp * t47;
  t168 = t92 - t168_tmp * t51;
  t169 = t2 * t89;
  t171_tmp = t156_tmp * 4.0;
  t172 = t31_tmp * t76 * t82;
  t173 = t134 + t171_tmp;
  t174 = t33_tmp * t76 * t82;
  t548 = t480 * t5;
  b_t5_tmp = t548 * t46;
  t143 += b_t5_tmp * t47;
  t177_tmp = t548 * t47;
  t92 = t104 - t177_tmp * t51;
  t178 = t480 * t89;
  t180_tmp = t5_tmp * 6.0;
  t181 = t35_tmp * t76 * t82;
  t182 = t148 + t180_tmp;
  t183 = t37_tmp * t76 * t82;
  t184 = 1.0 / in1[33];
  t9 = muDoubleScalarCos(in1[20]);
  st.site = &h_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t18 = in1[2] * in1[2];
  st.site = &i_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t187 = in1[3] * in1[3];
  st.site = &j_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t190 = in1[18] * in1[18];
  t191 = muDoubleScalarSin(in1[20]);
  st.site = &k_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t192 = 1.0 / (t191 * t191);
  st.site = &l_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  st.site = &m_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t90 = in1[33] * in1[33];
  t195_tmp = t90 * (t9 * t9);
  t197 = t184 * (t18 - t187) - t190 * t192 * (t195_tmp - 1.0) * 6.0;
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
  t208 = 1.0 / t90 * (t18 * t18 - t187 * t187) + t190 * t190 * (1.0 /
    muDoubleScalarPower(t191, 4.0)) * ((t195_tmp - 1.0) * (t195_tmp - 1.0)) *
    6.0;
  t209 = t208 * 3.1415926535897931 / 4.0;
  st.site = &t_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t9 = t5_tmp * t19 * 6.0;
  t212 = t23 + t9;
  t213 = t31 - t32;
  t18 = t548 * t19 * 8.0;
  t215 = t25 + t18;
  t216 = t35 - t36;
  t217_tmp = t2 * t17;
  b_t217_tmp = t217_tmp * 3.0;
  t218_tmp = t480 * t17;
  b_t218_tmp = t218_tmp * 4.0;
  t222_tmp = t2 * t59;
  t225 = ((((t19 * t168 + t222_tmp) + t94_tmp) + t33_tmp * t42 * t47) - t5 *
          t167) - t168_tmp * t89;
  t227_tmp = t480 * t59;
  t230 = ((((t19 * t92 + t227_tmp) + t474) + t37_tmp * t42 * t47) - t5 * t143) -
    t177_tmp * t89;
  t233_tmp = s * t59;
  t236 = ((((t19 * t158 + t233_tmp) + t56_tmp) + t29_tmp * t42 * t47) - t5 *
          t156) - t158_tmp * t89;
  t90 = t156_tmp * t19 * 4.0;
  t238 = t21 + t90;
  t239_tmp = s * t17;
  b_t239_tmp = t239_tmp * 2.0;
  t242_tmp = t21_tmp * t47;
  t242 = ((t116 + t4 * t56) + t5 * t53) - t242_tmp * t89;
  t245_tmp = t23_tmp * t47;
  t245 = ((t128 + t4 * t94) + t5 * t91) - t245_tmp * t89;
  t248_tmp = t25_tmp * t47;
  t248 = ((t142 + t4 * t106) + t5 * t103) - t248_tmp * t89;
  t249_tmp = s * t20 * 2.0;
  t250_tmp = -t22 + t30;
  t250 = (t250_tmp + b_t239_tmp) + t249_tmp;
  t255_tmp = t2 * t20 * 3.0;
  t256_tmp = -t24 + t34;
  t256 = (t256_tmp + b_t217_tmp) + t255_tmp;
  t257_tmp = t480 * t20 * 4.0;
  t258_tmp = -t26 + t38;
  t258 = (t258_tmp + b_t218_tmp) + t257_tmp;
  t263_tmp = t4 * t130;
  b_t263_tmp = t19 * t132;
  c_t263_tmp = t132_tmp * t89;
  d_t263_tmp = t33_tmp * t46 * t47;
  t263 = ((((t127 - t91_tmp) + b_t263_tmp) + t263_tmp) + c_t263_tmp) +
    d_t263_tmp;
  t268_tmp = t4 * t144;
  b_t268_tmp = t19 * t146;
  c_t268_tmp = t146_tmp * t89;
  d_t268_tmp = t37_tmp * t46 * t47;
  t268 = ((((t141 - t103_tmp) + b_t268_tmp) + t268_tmp) + c_t268_tmp) +
    d_t268_tmp;
  t279_tmp = t4 * t113;
  b_t279_tmp = t19 * t115;
  c_t279_tmp = t115_tmp * t89;
  d_t279_tmp = t29_tmp * t46 * t47;
  t279 = ((((t111 - t53_tmp) + b_t279_tmp) + t279_tmp) + c_t279_tmp) +
    d_t279_tmp;
  t284 = t27 - t28;
  st.site = &u_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t294 = muDoubleScalarPower(muDoubleScalarAbs(((((((((((((((((t212 * in2[22] +
    t213 * in2[25]) + t215 * in2[23]) + t216 * in2[26]) + t225 * in2[34]) + t230
    * in2[35]) + t236 * in2[33]) + t238 * in2[21]) + t242 * in2[27]) + t245 *
    in2[28]) + t248 * in2[29]) - t256 * in2[19]) - t258 * in2[20]) - t263 * in2
    [31]) - t268 * in2[32]) - t279 * in2[30]) - t284 * in2[24]) - t250 * in2[18]),
    in1[11] - 1.0);
  t102 = t23_tmp * t19 * 6.0;
  t303 = t33 + t102;
  t54 = t25_tmp * t19 * 8.0;
  t305 = t37 + t54;
  t309 = ((((t127 + t19 * t91) + t32_tmp * t51) + t31_tmp * t47 * t51) - t3 *
          t94) - t245_tmp * t59;
  t313 = ((((t141 + t19 * t103) + t36_tmp * t51) + t35_tmp * t47 * t51) - t3 *
          t106) - t248_tmp * t59;
  t319 = ((((t111 + t19 * t53) + t27_tmp * t51) + t28_tmp * t47 * t51) - t3 *
          t56) - t242_tmp * t59;
  t321 = t21_tmp * t19 * 4.0;
  t322 = t29 + t321;
  t325 = ((t116 + t3 * t113) + t5 * t115) - t115_tmp * t59;
  t328 = ((t128 + t3 * t130) + t5 * t132) - t132_tmp * t59;
  t331 = ((t142 + t3 * t144) + t5 * t146) - t146_tmp * t59;
  t332 = ((t22 - t30) + b_t239_tmp) + t249_tmp;
  t333 = t23 - t9;
  t336 = t25 - t18;
  t339 = ((t24 - t34) + b_t217_tmp) + t255_tmp;
  t340 = ((t26 - t38) + b_t218_tmp) + t257_tmp;
  t351_tmp = t5 * t168;
  b_t351_tmp = t19 * t167;
  c_t351_tmp = t168_tmp * t59;
  d_t351_tmp = t31_tmp * t42 * t47;
  t351 = ((((t169 - t130_tmp) + b_t351_tmp) + t351_tmp) + c_t351_tmp) +
    d_t351_tmp;
  t356_tmp = t5 * t92;
  b_t356_tmp = t19 * t143;
  c_t356_tmp = t177_tmp * t59;
  d_t356_tmp = t35_tmp * t42 * t47;
  t356 = ((((t178 - t144_tmp) + b_t356_tmp) + t356_tmp) + c_t356_tmp) +
    d_t356_tmp;
  t364_tmp = t5 * t158;
  b_t364_tmp = t19 * t156;
  c_t364_tmp = t158_tmp * t59;
  d_t364_tmp = t28_tmp * t42 * t47;
  t364 = ((((t157 - t113_tmp) + b_t364_tmp) + t364_tmp) + c_t364_tmp) +
    d_t364_tmp;
  t382_tmp = t21 - t90;
  t366 = t322 * in2[24];
  t368 = t325 * in2[30];
  t370 = t328 * in2[31];
  t372 = t331 * in2[32];
  t376 = t339 * in2[22];
  t377 = t340 * in2[23];
  t378 = t351 * in2[34];
  t379 = t356 * in2[35];
  t380 = t364 * in2[33];
  t381 = t332 * in2[21];
  st.site = &v_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t375_tmp = (((((t333 * in2[19] + t303 * in2[25]) + t336 * in2[20]) + t305 *
                in2[26]) + t309 * in2[28]) + t313 * in2[29]) + t319 * in2[27];
  t375 = muDoubleScalarPower(muDoubleScalarAbs(((((((((((t375_tmp + t382_tmp *
    in2[18]) + t366) + t368) + t370) + t372) - t376) - t377) - t378) - t379) -
    t380) - t381), in1[11] - 1.0);
  t383 = t31 + t32;
  t384 = t35 + t36;
  t32 = t5_tmp * t51;
  t31 = t548 * t51;
  t390 = ((((t169 + t19 * t130) + t167_tmp) + t520 * t46 * t47) - t4 * t132) -
    t132_tmp * t63;
  t394 = ((((t178 + t19 * t144) + b_t5_tmp) + t494 * t46 * t47) - t4 * t146) -
    t146_tmp * t63;
  t132 = t156_tmp * t51;
  t399 = ((((t157 + t19 * t113) + t588) + t511 * t46 * t47) - t4 * t115) -
    t115_tmp * t63;
  t400 = t27 + t28;
  t403 = ((t116 + t3 * t156) + t4 * t158) - t158_tmp * t63;
  t406 = ((t128 + t3 * t167) + t4 * t168) - t168_tmp * t63;
  t409 = ((t142 + t3 * t143) + t4 * t92) - t177_tmp * t63;
  t410 = ((t22 + t30) - b_t239_tmp) + t249_tmp;
  t412 = t33 - t102;
  t415 = t37 - t54;
  t417 = ((t24 + t34) - b_t217_tmp) + t255_tmp;
  t418 = ((t26 + t38) - b_t218_tmp) + t257_tmp;
  t28_tmp = t3 * t91;
  t31_tmp = t19 * t94;
  t35_tmp = t245_tmp * t63;
  t21_tmp = t520 * t47 * t51;
  t423 = ((((t222_tmp - t32) + t31_tmp) + t28_tmp) + t35_tmp) + t21_tmp;
  t27_tmp = t3 * t103;
  t25_tmp = t19 * t106;
  t32_tmp = t248_tmp * t63;
  t23_tmp = t494 * t47 * t51;
  t428 = ((((t227_tmp - t31) + t25_tmp) + t27_tmp) + t32_tmp) + t23_tmp;
  t29_tmp = t3 * t53;
  t17 = t19 * t56;
  t20 = t242_tmp * t63;
  t56_tmp = t511 * t47 * t51;
  t439 = ((((t233_tmp - t132) + t17) + t29_tmp) + t20) + t56_tmp;
  t460_tmp = t29 - t321;
  t446 = t403 * in2[33];
  t448 = t406 * in2[34];
  t450 = t409 * in2[35];
  t454 = t417 * in2[25];
  t455 = t418 * in2[26];
  t456 = t423 * in2[28];
  t457 = t428 * in2[29];
  t458 = t439 * in2[27];
  t459 = t410 * in2[24];
  st.site = &w_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t453_tmp = ((((((t383 * in2[19] + t412 * in2[22]) + t384 * in2[20]) + t415 *
                 in2[23]) + t390 * in2[31]) + t394 * in2[32]) + t399 * in2[30])
    + t400 * in2[18];
  t453 = muDoubleScalarPower(muDoubleScalarAbs((((((((((t453_tmp + t460_tmp *
    in2[21]) + t446) + t448) + t450) - t454) - t455) - t456) - t457) - t458) -
    t459), in1[11] - 1.0);
  t168 = t3 * t47;
  t90 = s * t19 * 4.0 + t2 * t47 * t76;
  t463 = ((t90 + t168 * t100) + t514 * t76 * t82) - t245_tmp * t66 * 2.0;
  t465 = (((-t148 + t150) + t180_tmp) + t168 * t154) - t146_tmp * t66 * 2.0;
  t467 = (((-t149 + t153_tmp) + t181) + t168 * t182) - t177_tmp * t66 * 2.0;
  t469 = (((-t134 + t136) + t171_tmp) + t168 * t139) - t132_tmp * t66 * 2.0;
  t471 = (((-t135 + t138_tmp) + t172) + t168 * t173) - t168_tmp * t66 * 2.0;
  t473 = (((((-t118 + t122) + t160_tmp) + t161_tmp) + t162_tmp) + t168 * t125) -
    t115_tmp * t66 * 2.0;
  t474 = t168 * t164;
  t191 = t2 * t19 * 6.0 + t480 * t47 * t76;
  t477 = ((t191 + t168 * t110) + t501 * t76 * t82) - t248_tmp * t66 * 2.0;
  t588 = t19 * 2.0 + s * t47 * t76;
  t480 = ((t588 + t168 * t81) + t22_tmp * t76 * t82) - t242_tmp * t66 * 2.0;
  t94_tmp = t158_tmp * t66 * 2.0;
  t33_tmp = t125_tmp - t124_tmp;
  t494 = ((t33_tmp - t163) - t474) + t94_tmp;
  st.site = &x_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t501 = muDoubleScalarPower(muDoubleScalarAbs((((((((t463 * in2[28] + t465 *
    in2[32]) + t467 * in2[35]) + t469 * in2[31]) + t471 * in2[34]) + t473 * in2
    [30]) + t477 * in2[29]) + t480 * in2[27]) - t494 * in2[33]), in1[11] - 1.0);
  t167_tmp = t4 * t47;
  t106 = ((t90 + t167_tmp * t139) + t34_tmp * t76 * t82) - t132_tmp * t70 * 2.0;
  t143 = t167_tmp * t110;
  t56 = (((t108 - t109) + t183) + t167_tmp * t182) - t177_tmp * t70 * 2.0;
  t104 = t167_tmp * t100;
  t511 = (((t98 - t99) + t174) + t167_tmp * t173) - t168_tmp * t70 * 2.0;
  t187 = t167_tmp * t81;
  t37_tmp = ((t77 - t78) + t79) + t80;
  t514 = ((t37_tmp + t165) + t167_tmp * t164) - t158_tmp * t70 * 2.0;
  t53 = ((t191 + t167_tmp * t154) + t38_tmp * t76 * t82) - t146_tmp * t70 * 2.0;
  t520 = ((t588 + t167_tmp * t125) + t30_tmp * t76 * t82) - t115_tmp * t70 * 2.0;
  b_t5_tmp = t134 + t136;
  t92 = t245_tmp * t70 * 2.0;
  t103 = ((b_t5_tmp - t171_tmp) + t104) - t92;
  t9 = t148 + t150;
  t18 = t248_tmp * t70 * 2.0;
  t91 = ((t9 - t180_tmp) + t143) - t18;
  t5_tmp = t242_tmp * t70 * 2.0;
  t116 = (((((-t118 - t122) + t160_tmp) + t161_tmp) + t162_tmp) - t187) + t5_tmp;
  st.site = &y_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t94 = muDoubleScalarPower(muDoubleScalarAbs((((((((t106 * in2[31] + t91 * in2
    [29]) + t56 * in2[35]) + t103 * in2[28]) + t511 * in2[34]) + t514 * in2[33])
    + t53 * in2[32]) + t520 * in2[30]) - t116 * in2[27]), in1[11] - 1.0);
  t36_tmp = t5 * t47;
  t113 = ((t90 + t36_tmp * t173) + t217_tmp * t76 * t82) - t168_tmp * t74 * 2.0;
  t548 = t36_tmp * t110;
  t142 = (((-t108 + t109) + t183) + t36_tmp * t154) - t146_tmp * t74 * 2.0;
  t54 = t36_tmp * t100;
  t128 = (((-t98 + t99) + t174) + t36_tmp * t139) - t132_tmp * t74 * 2.0;
  t90 = t36_tmp * t81;
  t102 = t36_tmp * t125;
  t115 = ((t191 + t36_tmp * t182) + t218_tmp * t76 * t82) - t177_tmp * t74 * 2.0;
  t36 = ((t588 + t36_tmp * t164) + t239_tmp * t76 * t82) - t158_tmp * t74 * 2.0;
  out1[0] = ((t22 - s * t13 * 2.0) - b_t239_tmp) - t249_tmp;
  out1[1] = ((t24 - t2 * t13 * 3.0) - b_t217_tmp) - t255_tmp;
  out1[2] = ((t26 - s * t2 * t13 * 4.0) - b_t218_tmp) - t257_tmp;
  out1[3] = t238;
  out1[4] = t212;
  out1[5] = t215;
  out1[6] = -t27 + t28;
  out1[7] = t213;
  out1[8] = t216;
  out1[9] = t242;
  out1[10] = t245;
  out1[11] = t248;
  out1[12] = ((((-t111 + t53_tmp) - t279_tmp) - b_t279_tmp) - c_t279_tmp) -
    d_t279_tmp;
  out1[13] = ((((-t127 + t91_tmp) - t263_tmp) - b_t263_tmp) - c_t263_tmp) -
    d_t263_tmp;
  out1[14] = ((((-t141 + t103_tmp) - t268_tmp) - b_t268_tmp) - c_t268_tmp) -
    d_t268_tmp;
  out1[15] = t236;
  out1[16] = t225;
  out1[17] = t230;
  out1[18] = t21 - s * t5 * t19 * 4.0;
  out1[19] = t23 - t2 * t5 * t19 * 6.0;
  out1[20] = t25 - s * t2 * t5 * t19 * 8.0;
  out1[21] = (t250_tmp - b_t239_tmp) - t249_tmp;
  out1[22] = (t256_tmp - b_t217_tmp) - t255_tmp;
  out1[23] = (t258_tmp - b_t218_tmp) - t257_tmp;
  out1[24] = t322;
  out1[25] = t303;
  out1[26] = t305;
  out1[27] = t319;
  out1[28] = t309;
  out1[29] = t313;
  out1[30] = t325;
  out1[31] = t328;
  out1[32] = t331;
  out1[33] = ((((-t157 + t113_tmp) - t364_tmp) - b_t364_tmp) - c_t364_tmp) -
    d_t364_tmp;
  out1[34] = ((((-t169 + t130_tmp) - t351_tmp) - b_t351_tmp) - c_t351_tmp) -
    d_t351_tmp;
  out1[35] = ((((-t178 + t144_tmp) - t356_tmp) - b_t356_tmp) - c_t356_tmp) -
    d_t356_tmp;
  out1[36] = t400;
  out1[37] = t383;
  out1[38] = t384;
  out1[39] = t29 - s * t3 * t19 * 4.0;
  out1[40] = t33 - t2 * t3 * t19 * 6.0;
  out1[41] = t37 - s * t2 * t3 * t19 * 8.0;
  out1[42] = ((-t22 - t30) + b_t239_tmp) - t249_tmp;
  out1[43] = ((-t24 - t34) + b_t217_tmp) - t255_tmp;
  out1[44] = ((-t26 - t38) + b_t218_tmp) - t257_tmp;
  out1[45] = ((((t132 - t233_tmp) - t29_tmp) - t17) - t20) - t56_tmp;
  out1[46] = ((((t32 - t222_tmp) - t28_tmp) - t31_tmp) - t35_tmp) - t21_tmp;
  out1[47] = ((((t31 - t27_tmp) - t25_tmp) - t227_tmp) - t32_tmp) - t23_tmp;
  out1[48] = t399;
  out1[49] = t390;
  out1[50] = t394;
  out1[51] = t403;
  out1[52] = t406;
  out1[53] = t409;
  memset(&out1[54], 0, 9U * sizeof(real_T));
  out1[63] = t480;
  out1[64] = t463;
  out1[65] = t477;
  out1[66] = t473;
  out1[67] = t469;
  out1[68] = t465;
  out1[69] = (((((-t119 - t120) - t121) + t124_tmp) + t163) + t474) - t94_tmp;
  out1[70] = t471;
  out1[71] = t467;
  memset(&out1[72], 0, 9U * sizeof(real_T));
  out1[81] = (((((t118 + t122) + t187) - t160_tmp) - t161_tmp) - t162_tmp) -
    t5_tmp;
  out1[82] = ((b_t5_tmp + t104) - t171_tmp) - t92;
  out1[83] = ((t9 + t143) - t180_tmp) - t18;
  out1[84] = t520;
  out1[85] = t106;
  out1[86] = t53;
  out1[87] = t514;
  out1[88] = t511;
  out1[89] = t56;
  memset(&out1[90], 0, 9U * sizeof(real_T));
  t187 = t242_tmp * t74 * 2.0;
  out1[99] = (((t125_tmp + t163) + t90) - t124_tmp) - t187;
  t9 = t245_tmp * t74 * 2.0;
  out1[100] = (((t135 + t172) + t54) - t138_tmp) - t9;
  t18 = t248_tmp * t74 * 2.0;
  out1[101] = (((t149 + t181) + t548) - t153_tmp) - t18;
  t143 = t115_tmp * t74 * 2.0;
  out1[102] = (((((-t77 + t78) - t79) - t80) + t165) + t102) - t143;
  out1[103] = t128;
  out1[104] = t142;
  out1[105] = t36;
  out1[106] = t113;
  out1[107] = t115;
  t35 = (((t135 - t138_tmp) + t172) + t54) - t9;
  t32 = (((t149 - t153_tmp) + t181) + t548) - t18;
  t31 = ((t33_tmp + t163) + t90) - t187;
  t158 = ((t37_tmp - t165) - t102) + t143;
  st.site = &ab_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t156 = muDoubleScalarPower(muDoubleScalarAbs((((((((t113 * in2[34] + t32 *
    in2[29]) + t142 * in2[32]) + t35 * in2[28]) + t128 * in2[31]) + t31 * in2[27])
    + t115 * in2[35]) + t36 * in2[33]) - t158 * in2[30]), in1[11] - 1.0);
  t9 = in1[33];
  st.site = &bb_emlrtRSI;
  b_sqrt(&st, &t9);
  t92 = 1.0 / t9;
  t9 = t184 * t190 * t192 * (t195_tmp - 1.0) * (in1[19] * in1[19]) *
    3.1415926535897931;
  t588 = t209 - t9 * 3.0;
  t146 = t209 - t9 * 2.9999999999999991;
  t130 = in1[1] * t184;
  t144 = t130 * t197;
  t156_tmp = t144 * 3.1415926535897931;
  out2[0] = t156_tmp * (((t5 * t59 - t4 * t63) + t3 * t86) + t19 * t89) / 3.0;
  out2[1] = t156_tmp * (((t3 * t63 + t19 * t59) + t4 * t86) - t5 * t89) / 3.0;
  out2[2] = t156_tmp * ((((-t3 * t59 + t19 * t63) + t5 * t86) + t4 * t89) - 1.0);
  out2[3] = t130 * t588 * (((t5 * t70 * 2.0 - t4 * t74 * 2.0) + t19 * t66 * 2.0)
    + t168 * t76);
  out2[4] = t130 * t146 * (((t5 * t66 * -2.0 + t3 * t74 * 2.0) + t19 * t70 * 2.0)
    + t167_tmp * t76);
  t156_tmp = t130 * t208;
  out2[5] = t156_tmp * 3.1415926535897931 * (((t4 * t66 * 2.0 - t3 * t70 * 2.0)
    + t19 * t74 * 2.0) + t36_tmp * t76) / 6.0;
  t54 = in1[5] * t250 * t294;
  t548 = in1[5] * t256 * t294;
  t5_tmp = in1[5] * t258 * t294;
  b_t5_tmp = -in1[5] * t212 * t294;
  t143 = in1[5] * t284 * t294;
  t104 = in1[5] * t279 * t294;
  t94_tmp = in1[5] * t263 * t294;
  t474 = in1[5] * t268 * t294;
  out3[0] = ((((((((((((((((b_t5_tmp * in2[22] - in1[5] * t213 * t294 * in2[25])
    - in1[5] * t215 * t294 * in2[23]) - in1[5] * t216 * t294 * in2[26]) - in1[5]
    * t225 * t294 * in2[34]) - in1[5] * t238 * t294 * in2[21]) - in1[5] * t230 *
                       t294 * in2[35]) + t54 * in2[18]) - in1[5] * t236 * t294 *
                     in2[33]) - in1[5] * t242 * t294 * in2[27]) - in1[5] * t245 *
                   t294 * in2[28]) + t548 * in2[19]) - in1[5] * t248 * t294 *
                 in2[29]) + t5_tmp * in2[20]) + t94_tmp * in2[31]) + t474 * in2
              [32]) + t143 * in2[24]) + t104 * in2[30];
  t56_tmp = in1[6] * t332;
  t17 = in1[6] * t339;
  t20 = in1[6] * t340;
  t33_tmp = -in1[6] * t303;
  t37_tmp = in1[6] * t364;
  t29_tmp = in1[6] * t351;
  t23_tmp = in1[6] * t356;
  out3[1] = ((((((((((((((((t33_tmp * t375 * in2[25] - in1[6] * t305 * t375 *
    in2[26]) - in1[6] * t309 * t375 * in2[28]) - in1[6] * t313 * t375 * in2[29])
    - in1[6] * t319 * t375 * in2[27]) - in1[6] * t322 * t375 * in2[24]) - in1[6]
                       * t333 * t375 * in2[19]) + t56_tmp * t375 * in2[21]) -
                     in1[6] * t325 * t375 * in2[30]) - in1[6] * t336 * t375 *
                    in2[20]) - in1[6] * t328 * t375 * in2[31]) + t17 * t375 *
                  in2[22]) - in1[6] * t331 * t375 * in2[32]) + t20 * t375 * in2
                [23]) + t29_tmp * t375 * in2[34]) + t23_tmp * t375 * in2[35]) +
             t37_tmp * t375 * in2[33]) - in1[6] * t375 * t382_tmp * in2[18];
  t25_tmp = -in1[7] * t383 * t453;
  t32_tmp = in1[7] * t410;
  t36_tmp = in1[7] * t417;
  t27_tmp = in1[7] * t418;
  t21_tmp = in1[7] * t439;
  t31_tmp = in1[7] * t423;
  t35_tmp = in1[7] * t428;
  out3[2] = ((((((((((((((((t25_tmp * in2[19] - in1[7] * t384 * t453 * in2[20])
    - in1[7] * t400 * t453 * in2[18]) - in1[7] * t390 * t453 * in2[31]) - in1[7]
    * t394 * t453 * in2[32]) - in1[7] * t399 * t453 * in2[30]) + t32_tmp * t453 *
                       in2[24]) - in1[7] * t412 * t453 * in2[22]) - in1[7] *
                     t403 * t453 * in2[33]) - in1[7] * t415 * t453 * in2[23]) -
                   in1[7] * t406 * t453 * in2[34]) + t36_tmp * t453 * in2[25]) -
                 in1[7] * t409 * t453 * in2[35]) + t27_tmp * t453 * in2[26]) +
               t31_tmp * t453 * in2[28]) + t35_tmp * t453 * in2[29]) + t21_tmp *
             t453 * in2[27]) - in1[7] * t453 * t460_tmp * in2[21];
  t28_tmp = -in1[8] * t463 * t501;
  t167_tmp = in1[8] * t494 * t501;
  out3[3] = (((((((t28_tmp * in2[28] - in1[8] * t465 * t501 * in2[32]) - in1[8] *
                  t469 * t501 * in2[31]) - in1[8] * t467 * t501 * in2[35]) -
                in1[8] * t473 * t501 * in2[30]) - in1[8] * t471 * t501 * in2[34])
              - in1[8] * t477 * t501 * in2[29]) - in1[8] * t480 * t501 * in2[27])
    + t167_tmp * in2[33];
  t168 = in1[9] * t116 * t94;
  t167 = -in1[9] * t106 * t94;
  out3[4] = (((((((t167 * in2[31] - in1[9] * t56 * t94 * in2[35]) - in1[9] *
                  t511 * t94 * in2[34]) - in1[9] * t514 * t94 * in2[33]) - in1[9]
                * t53 * t94 * in2[32]) - in1[9] * t103 * t94 * in2[28]) - in1[9]
              * t520 * t94 * in2[30]) - in1[9] * t91 * t94 * in2[29]) + t168 *
    in2[27];
  t321 = in1[10] * t158 * t156;
  t132 = -in1[10] * t113 * t156;
  out3[5] = (((((((t132 * in2[34] - in1[10] * t142 * t156 * in2[32]) - in1[10] *
                  t128 * t156 * in2[31]) - in1[10] * t35 * t156 * in2[28]) -
                in1[10] * t115 * t156 * in2[35]) - in1[10] * t36 * t156 * in2[33])
              - in1[10] * t32 * t156 * in2[29]) - in1[10] * t31 * t156 * in2[27])
    + t321 * in2[30];
  out4[0] = 0.0;
  out4[1] = 0.0;
  out4[2] = -t190 * t192 * (t195_tmp - 1.0) * 3.1415926535897931 * (((((in1[21]
    + in1[22]) + in1[23]) + in1[24]) + in1[25]) + in1[26]);
  t18 = in1[21] * in1[19] * t190 * t192 * (t195_tmp - 1.0) * t92 *
    3.1415926535897931;
  t187 = in1[22] * in1[19] * t190 * t192 * (t195_tmp - 1.0) * t92 *
    3.1415926535897931;
  t191 = in1[23] * in1[19] * t190 * t192 * (t195_tmp - 1.0) * t92 *
    3.1415926535897931;
  t90 = in1[24] * in1[19] * t190 * t192 * (t195_tmp - 1.0) * t92 *
    3.1415926535897931;
  t102 = in1[25] * in1[19] * t190 * t192 * (t195_tmp - 1.0) * t92 *
    3.1415926535897931;
  t9 = in1[26] * in1[19] * t190 * t192 * (t195_tmp - 1.0) * t92 *
    3.1415926535897931;
  out4[3] = ((((t18 * -0.91522491349480972 - t187 * 0.91522491349480972) + t191 *
               0.1086532638769295) + t90 * 0.80657164961788008) + t102 *
             0.80657164961787986) + t9 * 0.1086532638769295;
  out4[4] = ((((t18 * -0.40294336787992679 + t187 * 0.40294336787992691) + t191 *
               0.99407970920288391) + t90 * 0.59113634132295712) - t102 *
             0.59113634132295745) - t9 * 0.99407970920288391;
  out4[5] = 0.0;
  out5[0] = t51;
  out5[1] = t46;
  out5[2] = t42;
  out6[0] = t144 * t250 * 3.1415926535897931 / 3.0;
  out6[1] = t144 * t382_tmp * 3.1415926535897931 * -0.33333333333333331;
  t18 = -in1[1] * t184;
  t9 = t18 * t197;
  out6[2] = t9 * t400 * 3.1415926535897931;
  out6[3] = 0.0;
  out6[4] = 0.0;
  out6[5] = 0.0;
  out6[6] = t144 * t256 * 3.1415926535897931 / 3.0;
  out6[7] = t144 * t333 * 3.1415926535897931 * -0.33333333333333331;
  out6[8] = t9 * t383 * 3.1415926535897931;
  out6[9] = 0.0;
  out6[10] = 0.0;
  out6[11] = 0.0;
  out6[12] = t144 * t258 * 3.1415926535897931 / 3.0;
  out6[13] = t144 * t336 * 3.1415926535897931 * -0.33333333333333331;
  out6[14] = t9 * t384 * 3.1415926535897931;
  out6[15] = 0.0;
  out6[16] = 0.0;
  out6[17] = 0.0;
  out6[18] = t144 * t238 * 3.1415926535897931 * -0.33333333333333331;
  out6[19] = t144 * t332 * 3.1415926535897931 / 3.0;
  out6[20] = t9 * t460_tmp * 3.1415926535897931;
  out6[21] = 0.0;
  out6[22] = 0.0;
  out6[23] = 0.0;
  out6[24] = t144 * t212 * 3.1415926535897931 * -0.33333333333333331;
  out6[25] = t144 * t339 * 3.1415926535897931 / 3.0;
  out6[26] = t9 * t412 * 3.1415926535897931;
  out6[27] = 0.0;
  out6[28] = 0.0;
  out6[29] = 0.0;
  out6[30] = t144 * t215 * 3.1415926535897931 * -0.33333333333333331;
  out6[31] = t144 * t340 * 3.1415926535897931 / 3.0;
  out6[32] = t9 * t415 * 3.1415926535897931;
  out6[33] = 0.0;
  out6[34] = 0.0;
  out6[35] = 0.0;
  out6[36] = t144 * t284 * 3.1415926535897931 / 3.0;
  out6[37] = t144 * t322 * 3.1415926535897931 * -0.33333333333333331;
  out6[38] = t144 * t410 * 3.1415926535897931;
  out6[39] = 0.0;
  out6[40] = 0.0;
  out6[41] = 0.0;
  out6[42] = t144 * t213 * 3.1415926535897931 * -0.33333333333333331;
  out6[43] = t144 * t303 * 3.1415926535897931 * -0.33333333333333331;
  out6[44] = t144 * t417 * 3.1415926535897931;
  out6[45] = 0.0;
  out6[46] = 0.0;
  out6[47] = 0.0;
  out6[48] = t144 * t216 * 3.1415926535897931 * -0.33333333333333331;
  out6[49] = t144 * t305 * 3.1415926535897931 * -0.33333333333333331;
  out6[50] = t144 * t418 * 3.1415926535897931;
  out6[51] = 0.0;
  out6[52] = 0.0;
  out6[53] = 0.0;
  out6[54] = t144 * t242 * 3.1415926535897931 * -0.33333333333333331;
  out6[55] = t144 * t319 * 3.1415926535897931 * -0.33333333333333331;
  out6[56] = t144 * t439 * 3.1415926535897931;
  out6[57] = t18 * t480 * t588;
  out6[58] = t130 * t116 * t146;
  out6[59] = t156_tmp * t31 * 3.1415926535897931 * -0.16666666666666666;
  out6[60] = t144 * t245 * 3.1415926535897931 * -0.33333333333333331;
  out6[61] = t144 * t309 * 3.1415926535897931 * -0.33333333333333331;
  out6[62] = t144 * t423 * 3.1415926535897931;
  out6[63] = t18 * t463 * t588;
  out6[64] = t18 * t103 * t146;
  out6[65] = t156_tmp * t35 * 3.1415926535897931 * -0.16666666666666666;
  out6[66] = t144 * t248 * 3.1415926535897931 * -0.33333333333333331;
  out6[67] = t144 * t313 * 3.1415926535897931 * -0.33333333333333331;
  out6[68] = t144 * t428 * 3.1415926535897931;
  out6[69] = t18 * t477 * t588;
  out6[70] = t18 * t91 * t146;
  out6[71] = t156_tmp * t32 * 3.1415926535897931 * -0.16666666666666666;
  out6[72] = t144 * t279 * 3.1415926535897931 / 3.0;
  out6[73] = t144 * t325 * 3.1415926535897931 * -0.33333333333333331;
  out6[74] = t9 * t399 * 3.1415926535897931;
  out6[75] = t18 * t473 * t588;
  out6[76] = t18 * t520 * t146;
  out6[77] = t156_tmp * t158 * 3.1415926535897931 / 6.0;
  out6[78] = t144 * t263 * 3.1415926535897931 / 3.0;
  out6[79] = t144 * t328 * 3.1415926535897931 * -0.33333333333333331;
  out6[80] = t9 * t390 * 3.1415926535897931;
  out6[81] = t18 * t469 * t588;
  out6[82] = t18 * t106 * t146;
  out6[83] = t156_tmp * t128 * 3.1415926535897931 * -0.16666666666666666;
  out6[84] = t144 * t268 * 3.1415926535897931 / 3.0;
  out6[85] = t144 * t331 * 3.1415926535897931 * -0.33333333333333331;
  out6[86] = t9 * t394 * 3.1415926535897931;
  out6[87] = t18 * t465 * t588;
  out6[88] = t18 * t53 * t146;
  out6[89] = t156_tmp * t142 * 3.1415926535897931 * -0.16666666666666666;
  out6[90] = t144 * t236 * 3.1415926535897931 * -0.33333333333333331;
  out6[91] = t144 * t364 * 3.1415926535897931 / 3.0;
  out6[92] = t9 * t403 * 3.1415926535897931;
  out6[93] = t130 * t494 * t588;
  out6[94] = t18 * t514 * t146;
  out6[95] = t156_tmp * t36 * 3.1415926535897931 * -0.16666666666666666;
  out6[96] = t144 * t225 * 3.1415926535897931 * -0.33333333333333331;
  out6[97] = t144 * t351 * 3.1415926535897931 / 3.0;
  out6[98] = t9 * t406 * 3.1415926535897931;
  out6[99] = t18 * t471 * t588;
  out6[100] = t18 * t511 * t146;
  out6[101] = t156_tmp * t113 * 3.1415926535897931 * -0.16666666666666666;
  out6[102] = t144 * t230 * 3.1415926535897931 * -0.33333333333333331;
  out6[103] = t144 * t356 * 3.1415926535897931 / 3.0;
  out6[104] = t9 * t409 * 3.1415926535897931;
  out6[105] = t18 * t467 * t588;
  out6[106] = t18 * t56 * t146;
  out6[107] = t156_tmp * t115 * 3.1415926535897931 * -0.16666666666666666;
  st.site = &cb_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t92 = muDoubleScalarPower(muDoubleScalarAbs(((((((((((t375_tmp + t366) + t368)
    + t370) + t372) - t376) - t377) - t378) - t379) - t380) - t381) + in2[18] *
    t382_tmp), in1[11] - 1.0);
  st.site = &db_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t9 = muDoubleScalarPower(muDoubleScalarAbs((((((((((t453_tmp + t446) + t448) +
    t450) - t454) - t455) - t456) - t457) - t458) - t459) + in2[21] * t460_tmp),
    in1[11] - 1.0);
  out7[0] = t54;
  out7[1] = -in1[6] * t375 * t382_tmp;
  out7[2] = -in1[7] * t400 * t453;
  out7[3] = 0.0;
  out7[4] = 0.0;
  out7[5] = 0.0;
  out7[6] = t548;
  out7[7] = -in1[6] * t333 * t375;
  out7[8] = t25_tmp;
  out7[9] = 0.0;
  out7[10] = 0.0;
  out7[11] = 0.0;
  out7[12] = t5_tmp;
  out7[13] = -in1[6] * t336 * t375;
  out7[14] = -in1[7] * t384 * t453;
  out7[15] = 0.0;
  out7[16] = 0.0;
  out7[17] = 0.0;
  out7[18] = -in1[5] * t238 * t294;
  out7[19] = t56_tmp * t92;
  out7[20] = -in1[7] * t453 * t460_tmp;
  out7[21] = 0.0;
  out7[22] = 0.0;
  out7[23] = 0.0;
  out7[24] = b_t5_tmp;
  out7[25] = t17 * t92;
  out7[26] = -in1[7] * t412 * t453;
  out7[27] = 0.0;
  out7[28] = 0.0;
  out7[29] = 0.0;
  out7[30] = -in1[5] * t215 * t294;
  out7[31] = t20 * t92;
  out7[32] = -in1[7] * t415 * t453;
  out7[33] = 0.0;
  out7[34] = 0.0;
  out7[35] = 0.0;
  out7[36] = t143;
  out7[37] = -in1[6] * t322 * t92;
  out7[38] = t32_tmp * t9;
  out7[39] = 0.0;
  out7[40] = 0.0;
  out7[41] = 0.0;
  out7[42] = -in1[5] * t213 * t294;
  out7[43] = t33_tmp * t92;
  out7[44] = t36_tmp * t9;
  out7[45] = 0.0;
  out7[46] = 0.0;
  out7[47] = 0.0;
  out7[48] = -in1[5] * t216 * t294;
  out7[49] = -in1[6] * t305 * t92;
  out7[50] = t27_tmp * t9;
  out7[51] = 0.0;
  out7[52] = 0.0;
  out7[53] = 0.0;
  out7[54] = -in1[5] * t242 * t294;
  out7[55] = -in1[6] * t319 * t92;
  out7[56] = t21_tmp * t9;
  out7[57] = -in1[8] * t480 * t501;
  out7[58] = t168;
  out7[59] = -in1[10] * t31 * t156;
  out7[60] = -in1[5] * t245 * t294;
  out7[61] = -in1[6] * t309 * t92;
  out7[62] = t31_tmp * t9;
  out7[63] = t28_tmp;
  out7[64] = -in1[9] * t103 * t94;
  out7[65] = -in1[10] * t35 * t156;
  out7[66] = -in1[5] * t248 * t294;
  out7[67] = -in1[6] * t313 * t92;
  out7[68] = t35_tmp * t9;
  out7[69] = -in1[8] * t477 * t501;
  out7[70] = -in1[9] * t91 * t94;
  out7[71] = -in1[10] * t32 * t156;
  out7[72] = t104;
  out7[73] = -in1[6] * t325 * t92;
  out7[74] = -in1[7] * t399 * t9;
  out7[75] = -in1[8] * t473 * t501;
  out7[76] = -in1[9] * t520 * t94;
  out7[77] = t321;
  out7[78] = t94_tmp;
  out7[79] = -in1[6] * t328 * t92;
  out7[80] = -in1[7] * t390 * t9;
  out7[81] = -in1[8] * t469 * t501;
  out7[82] = t167;
  out7[83] = -in1[10] * t128 * t156;
  out7[84] = t474;
  out7[85] = -in1[6] * t331 * t92;
  out7[86] = -in1[7] * t394 * t9;
  out7[87] = -in1[8] * t465 * t501;
  out7[88] = -in1[9] * t53 * t94;
  out7[89] = -in1[10] * t142 * t156;
  out7[90] = -in1[5] * t236 * t294;
  out7[91] = t37_tmp * t92;
  out7[92] = -in1[7] * t403 * t9;
  out7[93] = t167_tmp;
  out7[94] = -in1[9] * t514 * t94;
  out7[95] = -in1[10] * t36 * t156;
  out7[96] = -in1[5] * t225 * t294;
  out7[97] = t29_tmp * t92;
  out7[98] = -in1[7] * t406 * t9;
  out7[99] = -in1[8] * t471 * t501;
  out7[100] = -in1[9] * t511 * t94;
  out7[101] = t132;
  out7[102] = -in1[5] * t230 * t294;
  out7[103] = t23_tmp * t92;
  out7[104] = -in1[7] * t409 * t9;
  out7[105] = -in1[8] * t467 * t501;
  out7[106] = -in1[9] * t56 * t94;
  out7[107] = -in1[10] * t115 * t156;
  *out8 = 1.0;
}

/* End of code generation (sprdmpF19.c) */
