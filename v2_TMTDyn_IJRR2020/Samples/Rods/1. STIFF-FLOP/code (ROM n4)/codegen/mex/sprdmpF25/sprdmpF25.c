/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sprdmpF25.c
 *
 * Code generation for function 'sprdmpF25'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "sprdmpF25.h"
#include "sqrt.h"
#include "error.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 76,    /* lineNo */
  "sprdmpF25",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF25.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 77,  /* lineNo */
  "sprdmpF25",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF25.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 93,  /* lineNo */
  "sprdmpF25",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF25.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 94,  /* lineNo */
  "sprdmpF25",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF25.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 95,  /* lineNo */
  "sprdmpF25",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF25.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 97,  /* lineNo */
  "sprdmpF25",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF25.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 128, /* lineNo */
  "sprdmpF25",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF25.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 175, /* lineNo */
  "sprdmpF25",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF25.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 311, /* lineNo */
  "sprdmpF25",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF25.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 312, /* lineNo */
  "sprdmpF25",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF25.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 315, /* lineNo */
  "sprdmpF25",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF25.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 317, /* lineNo */
  "sprdmpF25",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF25.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 318, /* lineNo */
  "sprdmpF25",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF25.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 319, /* lineNo */
  "sprdmpF25",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF25.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 324, /* lineNo */
  "sprdmpF25",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF25.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 325, /* lineNo */
  "sprdmpF25",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF25.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 326, /* lineNo */
  "sprdmpF25",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF25.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 329, /* lineNo */
  "sprdmpF25",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF25.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 330, /* lineNo */
  "sprdmpF25",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF25.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 331, /* lineNo */
  "sprdmpF25",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF25.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 335, /* lineNo */
  "sprdmpF25",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF25.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 455, /* lineNo */
  "sprdmpF25",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF25.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 562, /* lineNo */
  "sprdmpF25",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF25.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 665, /* lineNo */
  "sprdmpF25",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF25.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 720, /* lineNo */
  "sprdmpF25",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF25.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 775,/* lineNo */
  "sprdmpF25",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF25.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 832,/* lineNo */
  "sprdmpF25",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF25.m"/* pathName */
};

static emlrtRSInfo cb_emlrtRSI = { 833,/* lineNo */
  "sprdmpF25",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF25.m"/* pathName */
};

static emlrtRSInfo db_emlrtRSI = { 834,/* lineNo */
  "sprdmpF25",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF25.m"/* pathName */
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
void sprdmpF25(const emlrtStack *sp, const real_T in1[34], const real_T in2[48],
               real_T s, real_T out1[144], real_T out2[6], real_T out3[6],
               real_T out4[6], real_T out5[3], real_T out6[144], real_T out7[144],
               real_T *out8)
{
  real_T t2;
  real_T t4;
  real_T t107;
  real_T t119;
  real_T t128;
  real_T t138;
  real_T t3;
  real_T t169;
  real_T t183;
  real_T t238;
  real_T t242;
  real_T t5;
  real_T t220;
  real_T t397;
  real_T t211;
  real_T t218;
  real_T t6;
  real_T t11;
  real_T t16;
  real_T t21;
  real_T t22;
  real_T t23;
  real_T t24;
  real_T t25_tmp;
  real_T t671;
  real_T t25;
  real_T t26_tmp;
  real_T t26;
  real_T t27_tmp;
  real_T t713;
  real_T t27;
  real_T t596;
  real_T t28;
  real_T t29_tmp;
  real_T b_t29_tmp;
  real_T t704;
  real_T t29;
  real_T t30_tmp;
  real_T t30;
  real_T t31_tmp;
  real_T t691;
  real_T t31;
  real_T t32_tmp;
  real_T t32;
  real_T t665;
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
  real_T t39_tmp;
  real_T t39;
  real_T t40_tmp;
  real_T t40;
  real_T t41_tmp;
  real_T t41;
  real_T t42_tmp;
  real_T t42;
  real_T t43_tmp;
  real_T t43;
  real_T t44_tmp;
  real_T t44;
  real_T t45_tmp;
  real_T t45;
  real_T t46_tmp;
  real_T t46;
  real_T t47_tmp;
  real_T t47;
  real_T t48_tmp;
  real_T t48;
  real_T t53;
  real_T t54;
  real_T t59;
  real_T t64;
  real_T t65;
  real_T t67_tmp;
  real_T t67;
  real_T t69_tmp;
  real_T t69;
  real_T t73;
  real_T t76;
  real_T t80;
  real_T t85;
  real_T t90;
  real_T t92;
  real_T t93;
  real_T t94;
  real_T t95;
  real_T t96;
  real_T t97;
  real_T t98;
  real_T t99;
  real_T t103;
  real_T t106;
  real_T t108_tmp;
  real_T t108;
  real_T t615;
  real_T t112;
  real_T t115;
  real_T t116;
  real_T t117;
  real_T t120_tmp;
  real_T t120;
  real_T t121;
  real_T t123_tmp;
  real_T t123;
  real_T t125;
  real_T t126;
  real_T t127;
  real_T t129_tmp;
  real_T t129;
  real_T t130;
  real_T t132_tmp;
  real_T t132;
  real_T t134;
  real_T t135;
  real_T t136;
  real_T t137;
  real_T t139_tmp;
  real_T t139;
  real_T t141_tmp;
  real_T t141;
  real_T t142;
  real_T t144;
  real_T t145;
  real_T t146;
  real_T t147;
  real_T t148;
  real_T t149;
  real_T t151_tmp;
  real_T t152_tmp;
  real_T t152;
  real_T t154;
  real_T t156_tmp;
  real_T t156;
  real_T t158_tmp;
  real_T t158;
  real_T t159;
  real_T t161;
  real_T t162;
  real_T t163;
  real_T t165_tmp;
  real_T t166;
  real_T t168;
  real_T t170_tmp;
  real_T t170;
  real_T t172_tmp;
  real_T t172;
  real_T t173;
  real_T t175;
  real_T t176;
  real_T t177;
  real_T t179_tmp;
  real_T t180;
  real_T t182;
  real_T t184_tmp;
  real_T t184;
  real_T t186_tmp;
  real_T t186;
  real_T t187;
  real_T t189;
  real_T t190;
  real_T t191;
  real_T t193_tmp;
  real_T t194;
  real_T t196_tmp_tmp;
  real_T t196_tmp;
  real_T t196;
  real_T t198;
  real_T t199;
  real_T t201_tmp;
  real_T t202_tmp;
  real_T t203_tmp;
  real_T t204_tmp;
  real_T t205;
  real_T t206;
  real_T t207;
  real_T t209_tmp;
  real_T t209;
  real_T t210;
  real_T t213_tmp;
  real_T t214;
  real_T t215;
  real_T t216;
  real_T t218_tmp_tmp;
  real_T t218_tmp;
  real_T t219;
  real_T t222_tmp;
  real_T t223;
  real_T t224;
  real_T t225;
  real_T t227_tmp;
  real_T t227;
  real_T t228;
  real_T t231_tmp;
  real_T t232;
  real_T t233;
  real_T t234;
  real_T t235;
  real_T t241;
  real_T t243;
  real_T t246_tmp;
  real_T t248;
  real_T t259;
  real_T t262;
  real_T t263;
  real_T t264;
  real_T t266_tmp;
  real_T t269;
  real_T t271_tmp;
  real_T t274;
  real_T t276_tmp;
  real_T t279;
  real_T t281;
  real_T t282;
  real_T t283;
  real_T t285_tmp;
  real_T t288;
  real_T t291;
  real_T t294;
  real_T t297;
  real_T t298_tmp;
  real_T b_t298_tmp;
  real_T t300;
  real_T t301;
  real_T t303;
  real_T t304;
  real_T t306;
  real_T t307;
  real_T t308_tmp;
  real_T b_t308_tmp;
  real_T t309_tmp;
  real_T b_t309_tmp;
  real_T t310_tmp;
  real_T b_t310_tmp;
  real_T t313;
  real_T t319_tmp;
  real_T b_t319_tmp;
  real_T c_t319_tmp;
  real_T d_t319_tmp;
  real_T t319;
  real_T t324_tmp;
  real_T b_t324_tmp;
  real_T c_t324_tmp;
  real_T d_t324_tmp;
  real_T t324;
  real_T t329_tmp;
  real_T b_t329_tmp;
  real_T c_t329_tmp;
  real_T d_t329_tmp;
  real_T t329;
  real_T t345_tmp;
  real_T b_t345_tmp;
  real_T c_t345_tmp;
  real_T d_t345_tmp;
  real_T t345;
  real_T t354_tmp;
  real_T t355_tmp;
  real_T t355;
  real_T t362_tmp;
  real_T t363_tmp;
  real_T t363;
  real_T t364_tmp;
  real_T t365_tmp;
  real_T t365;
  real_T t366_tmp;
  real_T t367_tmp;
  real_T t367;
  real_T t373;
  real_T t385;
  real_T t389;
  real_T t393;
  real_T t398;
  real_T t402;
  real_T t406;
  real_T t409;
  real_T t412;
  real_T t414;
  real_T t416;
  real_T t418;
  real_T t421;
  real_T t436_tmp;
  real_T b_t436_tmp;
  real_T c_t436_tmp;
  real_T d_t436_tmp;
  real_T t436;
  real_T t441_tmp;
  real_T b_t441_tmp;
  real_T c_t441_tmp;
  real_T d_t441_tmp;
  real_T t441;
  real_T t446_tmp;
  real_T b_t446_tmp;
  real_T c_t446_tmp;
  real_T d_t446_tmp;
  real_T t446;
  real_T t447;
  real_T t457_tmp;
  real_T b_t457_tmp;
  real_T c_t457_tmp;
  real_T d_t457_tmp;
  real_T t457;
  real_T t463;
  real_T t464;
  real_T t466;
  real_T t469;
  real_T t473;
  real_T t474;
  real_T t475;
  real_T t480;
  real_T t489;
  real_T t490;
  real_T t491;
  real_T t495;
  real_T t499;
  real_T t503;
  real_T t504;
  real_T t509;
  real_T t512;
  real_T t515;
  real_T t518;
  real_T t519;
  real_T t520;
  real_T t521;
  real_T t524;
  real_T t530;
  real_T t535;
  real_T t540;
  real_T t551;
  real_T t557;
  real_T t566;
  real_T t568;
  real_T t571;
  real_T t574;
  real_T t576;
  real_T t577;
  real_T t578;
  real_T t583;
  real_T t598;
  real_T t600;
  real_T t602;
  real_T t604;
  real_T t606;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;

  /* SPRDMPF25 */
  /*     [OUT1,OUT2,OUT3,OUT4,OUT5,OUT6,OUT7,OUT8] = SPRDMPF25(IN1,IN2,S) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.2. */
  /*     05-Jan-2019 04:40:27 */
  st.site = &emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t2 = s * s;
  st.site = &b_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t4 = t2 * t2;
  t107 = in2[12] * s;
  t119 = in2[13] * t2;
  t128 = in2[14] * s * t2;
  t138 = in2[15] * t4;
  t3 = ((t107 + t119) + t128) + t138;
  t169 = in2[16] * s;
  t183 = in2[17] * t2;
  t238 = in2[18] * s * t2;
  t242 = in2[19] * t4;
  t5 = ((t169 + t183) + t238) + t242;
  t220 = in2[20] * s;
  t397 = in2[21] * t2;
  t211 = in2[22] * s * t2;
  t218 = in2[23] * t4;
  t6 = ((t220 + t397) + t211) + t218;
  st.site = &c_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t11 = t3 * t3;
  st.site = &d_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t16 = t5 * t5;
  st.site = &e_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t21 = t6 * t6;
  t22 = ((-t11 - t16) - t21) + 1.0;
  t23 = t22;
  st.site = &f_emlrtRSI;
  b_sqrt(&st, &t23);
  t24 = ((t11 + t16) + t21) - 1.0;
  t25_tmp = s * t3;
  t671 = t25_tmp * t5;
  t25 = t671 * 4.0;
  t26_tmp = s * t11;
  t26 = t26_tmp * 2.0;
  t27_tmp = t2 * t3;
  t713 = t27_tmp * t5;
  t27 = t713 * 6.0;
  t596 = t2 * t11;
  t28 = t596 * 3.0;
  t29_tmp = s * t2;
  b_t29_tmp = t29_tmp * t3;
  t704 = b_t29_tmp * t5;
  t29 = t704 * 8.0;
  t30_tmp = t29_tmp * t11;
  t30 = t30_tmp * 4.0;
  t31_tmp = t3 * t4;
  t691 = t31_tmp * t5;
  t31 = t691 * 10.0;
  t32_tmp = t4 * t11;
  t32 = t32_tmp * 5.0;
  t665 = t25_tmp * t6;
  t33 = t665 * 4.0;
  t34_tmp = s * t5;
  t34 = t34_tmp * t23 * 4.0;
  t35_tmp = t34_tmp * t6;
  t35 = t35_tmp * 4.0;
  t36_tmp = s * t16;
  t36 = t36_tmp * 2.0;
  t37_tmp = t27_tmp * t6;
  t37 = t37_tmp * 6.0;
  t38_tmp = t2 * t5;
  t38 = t38_tmp * t23 * 6.0;
  t39_tmp = t38_tmp * t6;
  t39 = t39_tmp * 6.0;
  t40_tmp = t2 * t16;
  t40 = t40_tmp * 3.0;
  t41_tmp = b_t29_tmp * t6;
  t41 = t41_tmp * 8.0;
  t42_tmp = t29_tmp * t5;
  t42 = t42_tmp * t23 * 8.0;
  t43_tmp = t42_tmp * t6;
  t43 = t43_tmp * 8.0;
  t44_tmp = t29_tmp * t16;
  t44 = t44_tmp * 4.0;
  t45_tmp = t31_tmp * t6;
  t45 = t45_tmp * 10.0;
  t46_tmp = t4 * t5;
  t46 = t46_tmp * t23 * 10.0;
  t47_tmp = t46_tmp * t6;
  t47 = t47_tmp * 10.0;
  t48_tmp = t4 * t16;
  t48 = t48_tmp * 5.0;
  t53 = (((in2[8] * s * 2.0 + in2[9] * t2 * 3.0) + in2[10] * s * t2 * 4.0) +
         in2[11] * t4 * 5.0) + 1.0;
  t11 = t22;
  st.site = &g_emlrtRSI;
  b_sqrt(&st, &t11);
  t54 = 1.0 / t11;
  t59 = ((in2[4] * s * 2.0 + in2[5] * t2 * 3.0) + in2[6] * s * t2 * 4.0) + in2[7]
    * t4 * 5.0;
  t64 = ((in2[0] * s * 2.0 + in2[1] * t2 * 3.0) + in2[2] * s * t2 * 4.0) + in2[3]
    * t4 * 5.0;
  t65 = s * t59;
  t67_tmp = t25_tmp * t53;
  t67 = t65 + t67_tmp * t54;
  t11 = s * t53;
  t69_tmp = t25_tmp * t54;
  t69 = t11 - t69_tmp * t59;
  t73 = (t3 * t53 + t23 * t59) - t6 * t64;
  t76 = (t5 * t64 + t23 * t53) - t3 * t59;
  t80 = ((in2[12] + in2[13] * s * 2.0) + in2[14] * t2 * 3.0) + in2[15] * s * t2 *
    4.0;
  t85 = ((in2[16] + in2[17] * s * 2.0) + in2[18] * t2 * 3.0) + in2[19] * s * t2 *
    4.0;
  t90 = ((in2[20] + in2[21] * s * 2.0) + in2[22] * t2 * 3.0) + in2[23] * s * t2 *
    4.0;
  t92 = (t3 * t80 * 2.0 + t5 * t85 * 2.0) + t6 * t90 * 2.0;
  t93 = s * t80 * 2.0;
  t94 = t107 * 2.0;
  t95 = t119 * 2.0;
  t96 = t128 * 2.0;
  t97 = t138 * 2.0;
  t98 = (((t93 + t94) + t95) + t96) + t97;
  st.site = &h_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  if (t22 < 0.0) {
    c_st.site = &fb_emlrtRSI;
    error(&c_st);
  }

  t99 = 1.0 / muDoubleScalarPower(t22, 1.5);
  t103 = (t3 * t64 + t5 * t59) + t6 * t53;
  t106 = (t6 * t59 + t23 * t64) - t5 * t53;
  t107 = t2 * t53;
  t108_tmp = t27_tmp * t54;
  t108 = t107 - t108_tmp * t59;
  t22 = t2 * t59;
  t615 = t27_tmp * t53;
  t112 = t22 + t615 * t54;
  t115 = t25_tmp * 4.0;
  t116 = t2 * t80 * 2.0;
  t117 = t115 + t116;
  t119 = t29_tmp * t53;
  t120_tmp = b_t29_tmp * t54;
  t120 = t119 - t120_tmp * t59;
  t121 = t29_tmp * t59;
  t123_tmp = b_t29_tmp * t53;
  t123 = t121 + t123_tmp * t54;
  t125 = t29_tmp * t80 * 2.0;
  t126 = t27_tmp * 6.0;
  t127 = t125 + t126;
  t128 = t4 * t53;
  t129_tmp = t31_tmp * t54;
  t129 = t128 - t129_tmp * t59;
  t130 = t4 * t59;
  t132_tmp = t31_tmp * t53;
  t132 = t130 + t132_tmp * t54;
  t134 = t4 * t80 * 2.0;
  t135 = b_t29_tmp * 8.0;
  t136 = t134 + t135;
  t137 = s * t76;
  t138 = s * t64;
  t139_tmp = t34_tmp * t53;
  t139 = t138 - t139_tmp * t54;
  t141_tmp = t34_tmp * t54;
  t141 = t11 + t141_tmp * t64;
  t142 = s * t103;
  t144 = s * t90 * 2.0;
  t145 = t169 * 2.0;
  t146 = t183 * 2.0;
  t147 = t238 * 2.0;
  t148 = t242 * 2.0;
  t149 = t671 * t92 * t99;
  t151_tmp = s * t85 * 2.0;
  t152_tmp = ((t145 + t146) + t147) + t148;
  t152 = t152_tmp + t151_tmp;
  t154 = t2 * t76;
  t11 = t2 * t64;
  t156_tmp = t38_tmp * t53;
  t156 = t11 - t156_tmp * t54;
  t158_tmp = t38_tmp * t54;
  t158 = t107 + t158_tmp * t64;
  t159 = t2 * t103;
  t161 = t2 * t90 * 2.0;
  t162 = t34_tmp * 4.0;
  t163 = t713 * t92 * t99;
  t165_tmp = t2 * t85 * 2.0;
  t166 = t162 + t165_tmp;
  t168 = t29_tmp * t76;
  t169 = t29_tmp * t64;
  t170_tmp = t42_tmp * t53;
  t170 = t169 - t170_tmp * t54;
  t172_tmp = t42_tmp * t54;
  t172 = t119 + t172_tmp * t64;
  t173 = t29_tmp * t103;
  t175 = t29_tmp * t90 * 2.0;
  t176 = t38_tmp * 6.0;
  t177 = t704 * t92 * t99;
  t179_tmp = t29_tmp * t85 * 2.0;
  t180 = t176 + t179_tmp;
  t182 = t4 * t76;
  t183 = t4 * t64;
  t184_tmp = t46_tmp * t53;
  t184 = t183 - t184_tmp * t54;
  t186_tmp = t46_tmp * t54;
  t186 = t128 + t186_tmp * t64;
  t187 = t4 * t103;
  t189 = t4 * t90 * 2.0;
  t190 = t42_tmp * 8.0;
  t191 = t691 * t92 * t99;
  t193_tmp = t4 * t85 * 2.0;
  t194 = t190 + t193_tmp;
  t196_tmp_tmp = s * t6;
  t196_tmp = t196_tmp_tmp * t54;
  t196 = t65 - t196_tmp * t64;
  t198 = t138 + t196_tmp * t59;
  t199 = s * t106;
  t201_tmp = t220 * 2.0;
  t202_tmp = t397 * 2.0;
  t203_tmp = t211 * 2.0;
  t204_tmp = t218 * 2.0;
  t205 = t665 * t92 * t99;
  t206 = (((t144 + t201_tmp) + t202_tmp) + t203_tmp) + t204_tmp;
  t207 = t35_tmp * t92 * t99;
  t128 = t2 * t6;
  t209_tmp = t128 * t54;
  t209 = t11 + t209_tmp * t59;
  t210 = t2 * t106;
  t211 = t22 - t209_tmp * t64;
  t213_tmp = t196_tmp_tmp * 4.0;
  t214 = t37_tmp * t92 * t99;
  t215 = t161 + t213_tmp;
  t216 = t39_tmp * t92 * t99;
  t218_tmp_tmp = t29_tmp * t6;
  t218_tmp = t218_tmp_tmp * t54;
  t218 = t169 + t218_tmp * t59;
  t219 = t29_tmp * t106;
  t220 = t121 - t218_tmp * t64;
  t222_tmp = t128 * 6.0;
  t223 = t41_tmp * t92 * t99;
  t224 = t175 + t222_tmp;
  t225 = t43_tmp * t92 * t99;
  t138 = t4 * t6;
  t227_tmp = t138 * t54;
  t227 = t183 + t227_tmp * t59;
  t228 = t4 * t106;
  t65 = t130 - t227_tmp * t64;
  t231_tmp = t218_tmp_tmp * 8.0;
  t232 = t45_tmp * t92 * t99;
  t233 = t189 + t231_tmp;
  t234 = t47_tmp * t92 * t99;
  t235 = 1.0 / in1[33];
  t11 = muDoubleScalarCos(in1[20]);
  st.site = &i_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t22 = in1[2] * in1[2];
  st.site = &j_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t238 = in1[3] * in1[3];
  st.site = &k_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t241 = in1[18] * in1[18];
  t242 = muDoubleScalarSin(in1[20]);
  st.site = &l_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t243 = 1.0 / (t242 * t242);
  st.site = &m_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  st.site = &n_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t107 = in1[33] * in1[33];
  t246_tmp = t107 * (t11 * t11);
  t248 = t235 * (t22 - t238) - t241 * t243 * (t246_tmp - 1.0) * 6.0;
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
  st.site = &t_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t259 = 1.0 / t107 * (t22 * t22 - t238 * t238) + t241 * t241 * (1.0 /
    muDoubleScalarPower(t242, 4.0)) * ((t246_tmp - 1.0) * (t246_tmp - 1.0)) *
    6.0;
  st.site = &u_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t262 = t27_tmp * t59;
  t263 = b_t29_tmp * t59;
  t264 = t31_tmp * t59;
  t266_tmp = t2 * t73;
  t269 = ((((t23 * t211 + t266_tmp) + t615) + t39_tmp * t53 * t54) - t6 * t209)
    - t209_tmp * t106;
  t271_tmp = t29_tmp * t73;
  t274 = ((((t23 * t220 + t271_tmp) + t123_tmp) + t43_tmp * t53 * t54) - t6 *
          t218) - t218_tmp * t106;
  t276_tmp = t4 * t73;
  t279 = ((((t23 * t65 + t276_tmp) + t132_tmp) + t47_tmp * t53 * t54) - t6 *
          t227) - t227_tmp * t106;
  t11 = t196_tmp_tmp * t23 * 4.0;
  t281 = t25 + t11;
  t282 = t33 - t34;
  t283 = t25_tmp * t59;
  t285_tmp = s * t73;
  t288 = ((((t23 * t196 + t285_tmp) + t67_tmp) + t35_tmp * t53 * t54) - t6 *
          t198) - t196_tmp * t106;
  t291 = ((t159 + t5 * t112) + t6 * t108) - t108_tmp * t106;
  t294 = ((t173 + t5 * t123) + t6 * t120) - t120_tmp * t106;
  t297 = ((t187 + t5 * t132) + t6 * t129) - t129_tmp * t106;
  t298_tmp = s * t21;
  b_t298_tmp = t298_tmp * 2.0;
  t22 = t128 * t23 * 6.0;
  t300 = t27 + t22;
  t301 = t37 - t38;
  t107 = t218_tmp_tmp * t23 * 8.0;
  t303 = t29 + t107;
  t304 = t41 - t42;
  t119 = t138 * t23 * 10.0;
  t306 = t31 + t119;
  t307 = t45 - t46;
  t308_tmp = t2 * t21;
  b_t308_tmp = t308_tmp * 3.0;
  t309_tmp = t29_tmp * t21;
  b_t309_tmp = t309_tmp * 4.0;
  t310_tmp = t4 * t21;
  b_t310_tmp = t310_tmp * 5.0;
  t313 = ((t142 + t5 * t67) + t6 * t69) - t69_tmp * t106;
  t319_tmp = t5 * t156;
  b_t319_tmp = t23 * t158;
  c_t319_tmp = t158_tmp * t106;
  d_t319_tmp = t39_tmp * t54 * t59;
  t319 = ((((t154 - t262) + b_t319_tmp) + t319_tmp) + c_t319_tmp) + d_t319_tmp;
  t324_tmp = t5 * t170;
  b_t324_tmp = t23 * t172;
  c_t324_tmp = t172_tmp * t106;
  d_t324_tmp = t43_tmp * t54 * t59;
  t324 = ((((t168 - t263) + b_t324_tmp) + t324_tmp) + c_t324_tmp) + d_t324_tmp;
  t329_tmp = t5 * t184;
  b_t329_tmp = t23 * t186;
  c_t329_tmp = t186_tmp * t106;
  d_t329_tmp = t47_tmp * t54 * t59;
  t329 = ((((t182 - t264) + b_t329_tmp) + t329_tmp) + c_t329_tmp) + d_t329_tmp;
  t345_tmp = t5 * t139;
  b_t345_tmp = t23 * t141;
  c_t345_tmp = t141_tmp * t106;
  d_t345_tmp = t35_tmp * t54 * t59;
  t345 = ((((t137 - t283) + t345_tmp) + b_t345_tmp) + c_t345_tmp) + d_t345_tmp;
  t354_tmp = s * t24 * 2.0;
  t355_tmp = -t26 + t36;
  t355 = (t355_tmp + b_t298_tmp) + t354_tmp;
  t362_tmp = t2 * t24 * 3.0;
  t363_tmp = -t28 + t40;
  t363 = (t363_tmp + b_t308_tmp) + t362_tmp;
  t364_tmp = t29_tmp * t24 * 4.0;
  t365_tmp = -t30 + t44;
  t365 = (t365_tmp + b_t309_tmp) + t364_tmp;
  t366_tmp = t4 * t24 * 5.0;
  t367_tmp = -t32 + t48;
  t367 = (t367_tmp + b_t310_tmp) + t366_tmp;
  st.site = &v_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t373 = muDoubleScalarPower(muDoubleScalarAbs(((((((((((((((((((((((t269 * in2
    [45] + t274 * in2[46]) + t279 * in2[47]) + t281 * in2[28]) + t282 * in2[32])
    + t288 * in2[44]) + t291 * in2[37]) + t294 * in2[38]) + t297 * in2[39]) +
    t300 * in2[29]) + t301 * in2[33]) + t303 * in2[30]) + t304 * in2[34]) + t306
    * in2[31]) + t307 * in2[35]) + t313 * in2[36]) - t319 * in2[41]) - t324 *
    in2[42]) - t329 * in2[43]) - t345 * in2[40]) - t355 * in2[24]) - t363 * in2
    [25]) - t365 * in2[26]) - t367 * in2[27]), in1[11] - 1.0);
  t385 = ((((t154 + t23 * t108) + t38_tmp * t64) + t37_tmp * t54 * t64) - t3 *
          t112) - t108_tmp * t73;
  t389 = ((((t168 + t23 * t120) + t42_tmp * t64) + t41_tmp * t54 * t64) - t3 *
          t123) - t120_tmp * t73;
  t393 = ((((t182 + t23 * t129) + t46_tmp * t64) + t45_tmp * t54 * t64) - t3 *
          t132) - t129_tmp * t73;
  t397 = t25_tmp * t23 * 4.0;
  t398 = t35 + t397;
  t402 = ((((t137 + t23 * t69) + t34_tmp * t64) + t665 * t54 * t64) - t3 * t67)
    - t69_tmp * t73;
  t406 = ((t159 + t3 * t156) + t6 * t158) - t158_tmp * t73;
  t409 = ((t173 + t3 * t170) + t6 * t172) - t172_tmp * t73;
  t412 = ((t187 + t3 * t184) + t6 * t186) - t186_tmp * t73;
  t169 = t27_tmp * t23 * 6.0;
  t414 = t39 + t169;
  t121 = b_t29_tmp * t23 * 8.0;
  t416 = t43 + t121;
  t183 = t31_tmp * t23 * 10.0;
  t418 = t47 + t183;
  t421 = ((t142 + t3 * t139) + t6 * t141) - t141_tmp * t73;
  t436_tmp = t6 * t211;
  b_t436_tmp = t23 * t209;
  c_t436_tmp = t209_tmp * t73;
  d_t436_tmp = t37_tmp * t53 * t54;
  t436 = ((((t210 - t156_tmp) + b_t436_tmp) + t436_tmp) + c_t436_tmp) +
    d_t436_tmp;
  t441_tmp = t6 * t220;
  b_t441_tmp = t23 * t218;
  c_t441_tmp = t218_tmp * t73;
  d_t441_tmp = t41_tmp * t53 * t54;
  t441 = ((((t219 - t170_tmp) + b_t441_tmp) + t441_tmp) + c_t441_tmp) +
    d_t441_tmp;
  t446_tmp = t6 * t65;
  b_t446_tmp = t23 * t227;
  c_t446_tmp = t227_tmp * t73;
  d_t446_tmp = t45_tmp * t53 * t54;
  t446 = ((((t228 - t184_tmp) + b_t446_tmp) + t446_tmp) + c_t446_tmp) +
    d_t446_tmp;
  t447 = t25 - t11;
  t457_tmp = t6 * t196;
  b_t457_tmp = t23 * t198;
  c_t457_tmp = t196_tmp * t73;
  d_t457_tmp = t665 * t53 * t54;
  t457 = ((((t199 - t139_tmp) + t457_tmp) + b_t457_tmp) + c_t457_tmp) +
    d_t457_tmp;
  t463 = ((t26 - t36) + b_t298_tmp) + t354_tmp;
  t464 = t27 - t22;
  t466 = t29 - t107;
  t469 = t31 - t119;
  t473 = ((t28 - t40) + b_t308_tmp) + t362_tmp;
  t474 = ((t30 - t44) + b_t309_tmp) + t364_tmp;
  t475 = ((t32 - t48) + b_t310_tmp) + t366_tmp;
  st.site = &w_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t480 = muDoubleScalarPower(muDoubleScalarAbs(((((((((((((((((((((((t385 * in2
    [37] + t389 * in2[38]) + t393 * in2[39]) + t447 * in2[24]) + t398 * in2[32])
    + t402 * in2[36]) + t406 * in2[41]) + t409 * in2[42]) + t412 * in2[43]) +
    t464 * in2[25]) + t466 * in2[26]) + t414 * in2[33]) + t469 * in2[27]) + t416
    * in2[34]) + t418 * in2[35]) + t421 * in2[40]) - t436 * in2[45]) - t441 *
    in2[46]) - t446 * in2[47]) - t457 * in2[44]) - t463 * in2[28]) - t473 * in2
    [29]) - t474 * in2[30]) - t475 * in2[31]), in1[11] - 1.0);
  t489 = t128 * t64;
  t490 = t218_tmp_tmp * t64;
  t491 = t138 * t64;
  t11 = t713 * t54;
  t495 = ((((t210 + t23 * t156) + t128 * t59) + t11 * t59) - t5 * t158) -
    t158_tmp * t76;
  t22 = t704 * t54;
  t499 = ((((t219 + t23 * t170) + t218_tmp_tmp * t59) + t22 * t59) - t5 * t172)
    - t172_tmp * t76;
  t107 = t691 * t54;
  t503 = ((((t228 + t23 * t184) + t138 * t59) + t107 * t59) - t5 * t186) -
    t186_tmp * t76;
  t504 = t33 + t34;
  t158 = t196_tmp_tmp * t64;
  t119 = t671 * t54;
  t509 = ((((t199 + t23 * t139) + t196_tmp_tmp * t59) + t119 * t59) - t5 * t141)
    - t141_tmp * t76;
  t512 = ((t159 + t3 * t209) + t5 * t211) - t209_tmp * t76;
  t515 = ((t173 + t3 * t218) + t5 * t220) - t218_tmp * t76;
  t518 = ((t187 + t3 * t227) + t5 * t65) - t227_tmp * t76;
  t519 = t37 + t38;
  t520 = t41 + t42;
  t521 = t45 + t46;
  t524 = ((t142 + t3 * t198) + t5 * t196) - t196_tmp * t76;
  t45_tmp = t3 * t108;
  t37_tmp = t23 * t112;
  t41_tmp = t108_tmp * t76;
  b_t29_tmp = t11 * t64;
  t530 = ((((t266_tmp - t489) + t37_tmp) + t45_tmp) + t41_tmp) + b_t29_tmp;
  t27_tmp = t3 * t120;
  t25_tmp = t23 * t123;
  t34_tmp = t120_tmp * t76;
  t46_tmp = t22 * t64;
  t535 = ((((t271_tmp - t490) + t25_tmp) + t27_tmp) + t34_tmp) + t46_tmp;
  t42_tmp = t3 * t129;
  t24 = t23 * t132;
  t38_tmp = t129_tmp * t76;
  t35_tmp = t107 * t64;
  t540 = ((((t276_tmp - t491) + t24) + t42_tmp) + t38_tmp) + t35_tmp;
  t551 = t35 - t397;
  t47_tmp = t3 * t69;
  t39_tmp = t23 * t67;
  t43_tmp = t69_tmp * t76;
  t67_tmp = t119 * t64;
  t557 = ((((t285_tmp - t158) + t47_tmp) + t39_tmp) + t43_tmp) + t67_tmp;
  t566 = ((t26 + t36) - b_t298_tmp) + t354_tmp;
  t568 = t39 - t169;
  t571 = t43 - t121;
  t574 = t47 - t183;
  t576 = ((t28 + t40) - b_t308_tmp) + t362_tmp;
  t577 = ((t30 + t44) - b_t309_tmp) + t364_tmp;
  t578 = ((t32 + t48) - b_t310_tmp) + t366_tmp;
  st.site = &x_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t583 = muDoubleScalarPower(muDoubleScalarAbs(((((((((((((((((((((((t495 * in2
    [41] + t499 * in2[42]) + t503 * in2[43]) + t504 * in2[24]) + t551 * in2[28])
    + t509 * in2[40]) + t512 * in2[45]) + t515 * in2[46]) + t518 * in2[47]) +
    t519 * in2[25]) + t568 * in2[29]) + t520 * in2[26]) + t571 * in2[30]) + t521
    * in2[27]) + t574 * in2[31]) + t524 * in2[44]) - t530 * in2[37]) - t535 *
    in2[38]) - t540 * in2[39]) - t557 * in2[36]) - t566 * in2[32]) - t576 * in2
    [33]) - t577 * in2[34]) - t578 * in2[35]), in1[11] - 1.0);
  t218_tmp_tmp = t3 * t54;
  t107 = s * t23 * 4.0 + t2 * t54 * t92;
  t67 = ((t107 + t218_tmp_tmp * t117) + t596 * t92 * t99) - t108_tmp * t80 * 2.0;
  t596 = (((-t175 + t177) + t222_tmp) + t218_tmp_tmp * t180) - t172_tmp * t80 *
    2.0;
  t598 = (((-t189 + t191) + t231_tmp) + t218_tmp_tmp * t194) - t186_tmp * t80 *
    2.0;
  t600 = (((-t176 + t179_tmp) + t223) + t218_tmp_tmp * t224) - t218_tmp * t80 *
    2.0;
  t602 = (((-t190 + t193_tmp) + t232) + t218_tmp_tmp * t233) - t227_tmp * t80 *
    2.0;
  t604 = (((-t161 + t163) + t213_tmp) + t218_tmp_tmp * t166) - t158_tmp * t80 *
    2.0;
  t606 = (((-t162 + t165_tmp) + t214) + t218_tmp_tmp * t215) - t209_tmp * t80 *
    2.0;
  t169 = t2 * t23 * 6.0 + t29_tmp * t54 * t92;
  t69 = ((t169 + t218_tmp_tmp * t127) + t30_tmp * t92 * t99) - t120_tmp * t80 *
    2.0;
  t119 = t29_tmp * t23 * 8.0 + t4 * t54 * t92;
  t129 = ((t119 + t218_tmp_tmp * t136) + t32_tmp * t92 * t99) - t129_tmp * t80 *
    2.0;
  t132 = ((((((-t144 + t149) + t201_tmp) + t202_tmp) + t203_tmp) + t204_tmp) +
          t218_tmp_tmp * t152) - t141_tmp * t80 * 2.0;
  t615 = t218_tmp_tmp * t206;
  t242 = t23 * 2.0 + s * t54 * t92;
  t46 = ((t242 + t218_tmp_tmp * t98) + t26_tmp * t92 * t99) - t69_tmp * t80 *
    2.0;
  t130 = t196_tmp * t80 * 2.0;
  t21 = t152_tmp - t151_tmp;
  t120 = ((t21 - t205) - t615) + t130;
  st.site = &y_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t123 = muDoubleScalarPower(muDoubleScalarAbs(((((((((((t67 * in2[37] + t596 *
    in2[42]) + t598 * in2[43]) + t600 * in2[46]) + t602 * in2[47]) + t604 * in2
    [41]) + t606 * in2[45]) + t69 * in2[38]) + t129 * in2[39]) + t132 * in2[40])
    + t46 * in2[36]) - t120 * in2[44]), in1[11] - 1.0);
  t31_tmp = t5 * t54;
  t38 = ((t107 + t31_tmp * t166) + t40_tmp * t92 * t99) - t158_tmp * t85 * 2.0;
  t121 = t31_tmp * t127;
  t183 = t31_tmp * t136;
  t41 = (((-t125 + t126) + t225) + t31_tmp * t224) - t218_tmp * t85 * 2.0;
  t42 = (((-t134 + t135) + t234) + t31_tmp * t233) - t227_tmp * t85 * 2.0;
  t238 = t31_tmp * t117;
  t45 = (((t115 - t116) + t216) + t31_tmp * t215) - t209_tmp * t85 * 2.0;
  t37 = ((t169 + t31_tmp * t180) + t44_tmp * t92 * t99) - t172_tmp * t85 * 2.0;
  t108 = ((t119 + t31_tmp * t194) + t48_tmp * t92 * t99) - t186_tmp * t85 * 2.0;
  t665 = t31_tmp * t98;
  t123_tmp = (((-t93 + t94) + t95) + t96) + t97;
  t112 = ((t123_tmp + t207) + t31_tmp * t206) - t196_tmp * t85 * 2.0;
  t142 = ((t242 + t31_tmp * t152) + t36_tmp * t92 * t99) - t141_tmp * t85 * 2.0;
  t196_tmp_tmp = t175 + t177;
  t159 = t120_tmp * t85 * 2.0;
  t671 = ((t196_tmp_tmp - t222_tmp) + t121) - t159;
  t138 = t189 + t191;
  t184 = t129_tmp * t85 * 2.0;
  t34 = ((t138 - t231_tmp) + t183) - t184;
  t11 = t161 + t163;
  t22 = t108_tmp * t85 * 2.0;
  t139 = ((t11 - t213_tmp) + t238) - t22;
  t128 = t69_tmp * t85 * 2.0;
  t691 = ((((((-t144 - t149) + t201_tmp) + t202_tmp) + t203_tmp) + t204_tmp) -
          t665) + t128;
  st.site = &ab_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t33 = muDoubleScalarPower(muDoubleScalarAbs(((((((((((t38 * in2[41] + t671 *
    in2[38]) + t34 * in2[39]) + t41 * in2[46]) + t42 * in2[47]) + t139 * in2[37])
    + t45 * in2[45]) + t37 * in2[42]) + t108 * in2[43]) + t112 * in2[44]) + t142
    * in2[40]) - t691 * in2[36]), in1[11] - 1.0);
  t132_tmp = t6 * t54;
  t704 = ((t107 + t132_tmp * t215) + t308_tmp * t92 * t99) - t209_tmp * t90 *
    2.0;
  t65 = t132_tmp * t127;
  t186 = t132_tmp * t136;
  t141 = (((t125 - t126) + t225) + t132_tmp * t180) - t172_tmp * t90 * 2.0;
  t196 = (((t134 - t135) + t234) + t132_tmp * t194) - t186_tmp * t90 * 2.0;
  t170 = t132_tmp * t117;
  t713 = (((-t115 + t116) + t216) + t132_tmp * t166) - t158_tmp * t90 * 2.0;
  t198 = ((t169 + t132_tmp * t224) + t309_tmp * t92 * t99) - t218_tmp * t90 *
    2.0;
  t187 = ((t119 + t132_tmp * t233) + t310_tmp * t92 * t99) - t227_tmp * t90 *
    2.0;
  t107 = t132_tmp * t98;
  t119 = t132_tmp * t152;
  t173 = ((t242 + t132_tmp * t206) + t298_tmp * t92 * t99) - t196_tmp * t90 *
    2.0;
  out1[0] = ((t26 - s * t16 * 2.0) - b_t298_tmp) - t354_tmp;
  out1[1] = ((t28 - t2 * t16 * 3.0) - b_t308_tmp) - t362_tmp;
  out1[2] = ((t30 - s * t2 * t16 * 4.0) - b_t309_tmp) - t364_tmp;
  out1[3] = ((t32 - t4 * t16 * 5.0) - b_t310_tmp) - t366_tmp;
  out1[4] = t281;
  out1[5] = t300;
  out1[6] = t303;
  out1[7] = t306;
  out1[8] = t282;
  out1[9] = t301;
  out1[10] = t304;
  out1[11] = t307;
  out1[12] = t313;
  out1[13] = t291;
  out1[14] = t294;
  out1[15] = t297;
  out1[16] = ((((-t137 + t283) - t345_tmp) - b_t345_tmp) - c_t345_tmp) -
    d_t345_tmp;
  out1[17] = ((((-t154 + t262) - t319_tmp) - b_t319_tmp) - c_t319_tmp) -
    d_t319_tmp;
  out1[18] = ((((-t168 + t263) - t324_tmp) - b_t324_tmp) - c_t324_tmp) -
    d_t324_tmp;
  out1[19] = ((((-t182 + t264) - t329_tmp) - b_t329_tmp) - c_t329_tmp) -
    d_t329_tmp;
  out1[20] = t288;
  out1[21] = t269;
  out1[22] = t274;
  out1[23] = t279;
  out1[24] = t25 - s * t6 * t23 * 4.0;
  out1[25] = t27 - t2 * t6 * t23 * 6.0;
  out1[26] = t29 - s * t2 * t6 * t23 * 8.0;
  out1[27] = t31 - t4 * t6 * t23 * 10.0;
  out1[28] = (t355_tmp - b_t298_tmp) - t354_tmp;
  out1[29] = (t363_tmp - b_t308_tmp) - t362_tmp;
  out1[30] = (t365_tmp - b_t309_tmp) - t364_tmp;
  out1[31] = (t367_tmp - b_t310_tmp) - t366_tmp;
  out1[32] = t398;
  out1[33] = t414;
  out1[34] = t416;
  out1[35] = t418;
  out1[36] = t402;
  out1[37] = t385;
  out1[38] = t389;
  out1[39] = t393;
  out1[40] = t421;
  out1[41] = t406;
  out1[42] = t409;
  out1[43] = t412;
  out1[44] = ((((-t199 + t139_tmp) - t457_tmp) - b_t457_tmp) - c_t457_tmp) -
    d_t457_tmp;
  out1[45] = ((((-t210 + t156_tmp) - t436_tmp) - b_t436_tmp) - c_t436_tmp) -
    d_t436_tmp;
  out1[46] = ((((-t219 + t170_tmp) - t441_tmp) - b_t441_tmp) - c_t441_tmp) -
    d_t441_tmp;
  out1[47] = ((((-t228 + t184_tmp) - t446_tmp) - b_t446_tmp) - c_t446_tmp) -
    d_t446_tmp;
  out1[48] = t504;
  out1[49] = t519;
  out1[50] = t520;
  out1[51] = t521;
  out1[52] = t35 - s * t3 * t23 * 4.0;
  out1[53] = t39 - t2 * t3 * t23 * 6.0;
  out1[54] = t43 - s * t2 * t3 * t23 * 8.0;
  out1[55] = t47 - t3 * t4 * t23 * 10.0;
  out1[56] = ((-t26 - t36) + b_t298_tmp) - t354_tmp;
  out1[57] = ((-t28 - t40) + b_t308_tmp) - t362_tmp;
  out1[58] = ((-t30 - t44) + b_t309_tmp) - t364_tmp;
  out1[59] = ((-t32 - t48) + b_t310_tmp) - t366_tmp;
  out1[60] = ((((t158 - t285_tmp) - t47_tmp) - t39_tmp) - t43_tmp) - t67_tmp;
  out1[61] = ((((t489 - t266_tmp) - t45_tmp) - t37_tmp) - t41_tmp) - b_t29_tmp;
  out1[62] = ((((t490 - t27_tmp) - t25_tmp) - t271_tmp) - t34_tmp) - t46_tmp;
  out1[63] = ((((t491 - t276_tmp) - t42_tmp) - t24) - t38_tmp) - t35_tmp;
  out1[64] = t509;
  out1[65] = t495;
  out1[66] = t499;
  out1[67] = t503;
  out1[68] = t524;
  out1[69] = t512;
  out1[70] = t515;
  out1[71] = t518;
  memset(&out1[72], 0, 12U * sizeof(real_T));
  out1[84] = t46;
  out1[85] = t67;
  out1[86] = t69;
  out1[87] = t129;
  out1[88] = t132;
  out1[89] = t604;
  out1[90] = t596;
  out1[91] = t598;
  out1[92] = ((((((-t145 - t146) - t147) - t148) + t151_tmp) + t205) + t615) -
    t130;
  out1[93] = t606;
  out1[94] = t600;
  out1[95] = t602;
  memset(&out1[96], 0, 12U * sizeof(real_T));
  out1[108] = ((((((t144 + t149) + t665) - t201_tmp) - t202_tmp) - t204_tmp) -
               t203_tmp) - t128;
  out1[109] = ((t11 + t238) - t213_tmp) - t22;
  out1[110] = ((t196_tmp_tmp + t121) - t222_tmp) - t159;
  out1[111] = ((t138 + t183) - t231_tmp) - t184;
  out1[112] = t142;
  out1[113] = t38;
  out1[114] = t37;
  out1[115] = t108;
  out1[116] = t112;
  out1[117] = t45;
  out1[118] = t41;
  out1[119] = t42;
  memset(&out1[120], 0, 12U * sizeof(real_T));
  t169 = t69_tmp * t90 * 2.0;
  out1[132] = (((t152_tmp + t205) + t107) - t151_tmp) - t169;
  t22 = t108_tmp * t90 * 2.0;
  out1[133] = (((t162 + t214) + t170) - t165_tmp) - t22;
  t11 = t120_tmp * t90 * 2.0;
  out1[134] = (((t176 + t223) + t65) - t179_tmp) - t11;
  t128 = t129_tmp * t90 * 2.0;
  out1[135] = (((t190 + t232) + t186) - t193_tmp) - t128;
  t138 = t141_tmp * t90 * 2.0;
  out1[136] = ((((((t93 - t94) - t95) - t96) - t97) + t207) + t119) - t138;
  out1[137] = t713;
  out1[138] = t141;
  out1[139] = t196;
  out1[140] = t173;
  out1[141] = t704;
  out1[142] = t198;
  out1[143] = t187;
  t172 = (((t176 - t179_tmp) + t223) + t65) - t11;
  t156 = (((t190 - t193_tmp) + t232) + t186) - t128;
  t209 = (((t162 - t165_tmp) + t214) + t170) - t22;
  t158 = ((t21 + t205) + t107) - t169;
  t665 = ((t123_tmp - t207) - t119) + t138;
  st.site = &bb_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  t227 = muDoubleScalarPower(muDoubleScalarAbs(((((((((((t704 * in2[45] + t172 *
    in2[38]) + t156 * in2[39]) + t141 * in2[42]) + t196 * in2[43]) + t209 * in2
    [37]) + t713 * in2[41]) + t198 * in2[46]) + t187 * in2[47]) + t158 * in2[36])
    + t173 * in2[44]) - t665 * in2[40]), in1[11] - 1.0);
  t11 = in1[33];
  st.site = &cb_emlrtRSI;
  b_sqrt(&st, &t11);
  t11 = 1.0 / t11;
  t119 = 70.0;
  st.site = &db_emlrtRSI;
  b_sqrt(&st, &t119);
  t186 = t259 * 3.1415926535897931 / 4.0 - t235 * t241 * t243 * (t246_tmp - 1.0)
    * (in1[19] * in1[19]) * 3.1415926535897931 * 3.0;
  t184 = in1[1] * t235;
  t196_tmp_tmp = t184 * t248;
  t159 = t196_tmp_tmp * 3.1415926535897931;
  out2[0] = t159 * (((t6 * t73 - t5 * t76) + t3 * t103) + t23 * t106) / 3.0;
  out2[1] = t159 * (((t3 * t76 + t23 * t73) + t5 * t103) - t6 * t106) / 3.0;
  out2[2] = t159 * ((((-t3 * t73 + t23 * t76) + t6 * t103) + t5 * t106) - 1.0);
  out2[3] = t184 * t186 * (((t6 * t85 * 2.0 - t5 * t90 * 2.0) + t23 * t80 * 2.0)
    + t218_tmp_tmp * t92);
  out2[4] = in1[1] * t235 * t186 * (((t6 * t80 * -2.0 + t3 * t90 * 2.0) + t23 *
    t85 * 2.0) + t31_tmp * t92);
  t159 = t184 * t259;
  out2[5] = t159 * 3.1415926535897931 * (((t5 * t80 * 2.0 - t3 * t85 * 2.0) +
    t23 * t90 * 2.0) + t132_tmp * t92) / 6.0;
  t242 = in1[5] * t355 * t373;
  t107 = in1[5] * t363 * t373;
  t128 = in1[5] * t365 * t373;
  t65 = in1[5] * t367 * t373;
  t220 = -in1[5] * t281 * t373;
  t397 = in1[5] * t345 * t373;
  t211 = in1[5] * t319 * t373;
  t218 = in1[5] * t324 * t373;
  t121 = in1[5] * t329 * t373;
  out3[0] = ((((((((((((((((((((((t220 * in2[28] - in1[5] * t269 * t373 * in2[45])
    - in1[5] * t282 * t373 * in2[32]) - in1[5] * t274 * t373 * in2[46]) - in1[5]
    * t279 * t373 * in2[47]) - in1[5] * t291 * t373 * in2[37]) - in1[5] * t300 *
    t373 * in2[29]) - in1[5] * t288 * t373 * in2[44]) - in1[5] * t294 * t373 *
    in2[38]) - in1[5] * t303 * t373 * in2[30]) - in1[5] * t301 * t373 * in2[33])
                        - in1[5] * t297 * t373 * in2[39]) - in1[5] * t306 * t373
                       * in2[31]) - in1[5] * t304 * t373 * in2[34]) - in1[5] *
                     t307 * t373 * in2[35]) - in1[5] * t313 * t373 * in2[36]) +
                   t211 * in2[41]) + t218 * in2[42]) + t121 * in2[43]) + t242 *
                in2[24]) + t397 * in2[40]) + t107 * in2[25]) + t128 * in2[26]) +
    t65 * in2[27];
  t130 = in1[6] * t463 * t480;
  t615 = in1[6] * t473 * t480;
  t123_tmp = in1[6] * t474 * t480;
  t132_tmp = in1[6] * t475 * t480;
  t67_tmp = -in1[6] * t385 * t480;
  t21 = in1[6] * t457 * t480;
  t39_tmp = in1[6] * t436 * t480;
  t43_tmp = in1[6] * t441 * t480;
  t47_tmp = in1[6] * t446 * t480;
  out3[1] = ((((((((((((((((((((((t67_tmp * in2[37] - in1[6] * t389 * t480 *
    in2[38]) - in1[6] * t398 * t480 * in2[32]) - in1[6] * t393 * t480 * in2[39])
    - in1[6] * t402 * t480 * in2[36]) - in1[6] * t406 * t480 * in2[41]) - in1[6]
    * t414 * t480 * in2[33]) - in1[6] * t416 * t480 * in2[34]) - in1[6] * t409 *
    t480 * in2[42]) - in1[6] * t418 * t480 * in2[35]) - in1[6] * t412 * t480 *
    in2[43]) - in1[6] * t421 * t480 * in2[40]) - in1[6] * t447 * t480 * in2[24])
                      + t39_tmp * in2[45]) + t43_tmp * in2[46]) - in1[6] * t464 *
                    t480 * in2[25]) + t130 * in2[28]) - in1[6] * t466 * t480 *
                  in2[26]) + t47_tmp * in2[47]) - in1[6] * t469 * t480 * in2[27])
               + t21 * in2[44]) + t615 * in2[29]) + t123_tmp * in2[30]) +
    t132_tmp * in2[31];
  t35_tmp = -in1[7] * t504 * t583;
  t24 = in1[7] * t566 * t583;
  t38_tmp = in1[7] * t576 * t583;
  t42_tmp = in1[7] * t577 * t583;
  t46_tmp = in1[7] * t578 * t583;
  t25_tmp = in1[7] * t557 * t583;
  t34_tmp = in1[7] * t530 * t583;
  t27_tmp = in1[7] * t535 * t583;
  b_t29_tmp = in1[7] * t540 * t583;
  out3[2] = ((((((((((((((((((((((t35_tmp * in2[24] - in1[7] * t495 * t583 *
    in2[41]) - in1[7] * t499 * t583 * in2[42]) - in1[7] * t519 * t583 * in2[25])
    - in1[7] * t503 * t583 * in2[43]) - in1[7] * t520 * t583 * in2[26]) - in1[7]
    * t521 * t583 * in2[27]) - in1[7] * t509 * t583 * in2[40]) - in1[7] * t512 *
    t583 * in2[45]) - in1[7] * t515 * t583 * in2[46]) - in1[7] * t518 * t583 *
    in2[47]) + t34_tmp * in2[37]) - in1[7] * t524 * t583 * in2[44]) + t27_tmp *
                      in2[38]) + b_t29_tmp * in2[39]) - in1[7] * t551 * t583 *
                    in2[28]) + t25_tmp * in2[36]) - in1[7] * t568 * t583 * in2
                  [29]) + t24 * in2[32]) - in1[7] * t571 * t583 * in2[30]) -
               in1[7] * t574 * t583 * in2[31]) + t38_tmp * in2[33]) + t42_tmp *
             in2[34]) + t46_tmp * in2[35];
  t31_tmp = -in1[8] * t67 * t123;
  t37_tmp = in1[8] * t120 * t123;
  out3[3] = ((((((((((t31_tmp * in2[37] - in1[8] * t596 * t123 * in2[42]) - in1
                     [8] * t598 * t123 * in2[43]) - in1[8] * t604 * t123 * in2
                    [41]) - in1[8] * t600 * t123 * in2[46]) - in1[8] * t69 *
                  t123 * in2[38]) - in1[8] * t602 * t123 * in2[47]) - in1[8] *
                t606 * t123 * in2[45]) - in1[8] * t129 * t123 * in2[39]) - in1[8]
              * t132 * t123 * in2[40]) - in1[8] * t46 * t123 * in2[36]) +
    t37_tmp * in2[44];
  t170 = in1[9] * t691 * t33;
  t41_tmp = -in1[9] * t38 * t33;
  out3[4] = ((((((((((t41_tmp * in2[41] - in1[9] * t41 * t33 * in2[46]) - in1[9]
                     * t42 * t33 * in2[47]) - in1[9] * t45 * t33 * in2[45]) -
                   in1[9] * t37 * t33 * in2[42]) - in1[9] * t108 * t33 * in2[43])
                 - in1[9] * t671 * t33 * in2[38]) - in1[9] * t142 * t33 * in2[40])
               - in1[9] * t112 * t33 * in2[44]) - in1[9] * t34 * t33 * in2[39])
             - in1[9] * t139 * t33 * in2[37]) + t170 * in2[36];
  t45_tmp = in1[10] * t665 * t227;
  t218_tmp_tmp = -in1[10] * t704 * t227;
  out3[5] = ((((((((((t218_tmp_tmp * in2[45] - in1[10] * t141 * t227 * in2[42])
                     - in1[10] * t196 * t227 * in2[43]) - in1[10] * t713 * t227 *
                    in2[41]) - in1[10] * t198 * t227 * in2[46]) - in1[10] * t172
                  * t227 * in2[38]) - in1[10] * t187 * t227 * in2[47]) - in1[10]
                * t173 * t227 * in2[44]) - in1[10] * t156 * t227 * in2[39]) -
              in1[10] * t209 * t227 * in2[37]) - in1[10] * t158 * t227 * in2[36])
    + t45_tmp * in2[40];
  out4[0] = 0.0;
  out4[1] = 0.0;
  out4[2] = -t241 * t243 * (t246_tmp - 1.0) * 3.1415926535897931 * (((((in1[21]
    + in1[22]) + in1[23]) + in1[24]) + in1[25]) + in1[26]);
  t138 = in1[23] * in1[19] * t241 * t243 * (t246_tmp - 1.0) * t11 *
    3.1415926535897931;
  t22 = in1[24] * in1[19] * t241 * t243 * (t246_tmp - 1.0) * t11 *
    3.1415926535897931;
  t169 = in1[25] * in1[19] * t241 * t243 * (t246_tmp - 1.0) * t11 *
    3.1415926535897931;
  t183 = in1[26] * in1[19] * t241 * t243 * (t246_tmp - 1.0) * t11 *
    3.1415926535897931;
  t238 = in1[21] * in1[19] * t241 * t243 * (t246_tmp - 1.0) * t11;
  t11 *= in1[22] * in1[19] * t241 * t243 * (t246_tmp - 1.0);
  out4[3] = ((((t238 * 3.1415926535897931 * -0.93771626297577859 - t11 *
                3.1415926535897931 * 0.93771626297577859) + t138 *
               0.167999098695029) + t22 * 0.76971716428074954) + t169 *
             0.76971716428074932) + t183 * 0.16799909869502891;
  out4[4] = ((((t138 * 0.9857871488499218 + t22 * 0.63838506170774523) - t169 *
               0.63838506170774545) - t183 * 0.9857871488499218) - t238 * t119 *
             3.1415926535897931 * 0.041522491349480967) + t11 * t119 *
    3.1415926535897931 * 0.041522491349480967;
  out4[5] = 0.0;
  out5[0] = t64;
  out5[1] = t59;
  out5[2] = t53;
  out6[0] = t196_tmp_tmp * t355 * 3.1415926535897931 / 3.0;
  out6[1] = t196_tmp_tmp * t447 * 3.1415926535897931 * -0.33333333333333331;
  t119 = -in1[1] * t235;
  t11 = t119 * t248;
  out6[2] = t11 * t504 * 3.1415926535897931;
  out6[3] = 0.0;
  out6[4] = 0.0;
  out6[5] = 0.0;
  out6[6] = t196_tmp_tmp * t363 * 3.1415926535897931 / 3.0;
  out6[7] = t196_tmp_tmp * t464 * 3.1415926535897931 * -0.33333333333333331;
  out6[8] = t11 * t519 * 3.1415926535897931;
  out6[9] = 0.0;
  out6[10] = 0.0;
  out6[11] = 0.0;
  out6[12] = t196_tmp_tmp * t365 * 3.1415926535897931 / 3.0;
  out6[13] = t196_tmp_tmp * t466 * 3.1415926535897931 * -0.33333333333333331;
  out6[14] = t11 * t520 * 3.1415926535897931;
  out6[15] = 0.0;
  out6[16] = 0.0;
  out6[17] = 0.0;
  out6[18] = t196_tmp_tmp * t367 * 3.1415926535897931 / 3.0;
  out6[19] = t196_tmp_tmp * t469 * 3.1415926535897931 * -0.33333333333333331;
  out6[20] = t11 * t521 * 3.1415926535897931;
  out6[21] = 0.0;
  out6[22] = 0.0;
  out6[23] = 0.0;
  out6[24] = t196_tmp_tmp * t281 * 3.1415926535897931 * -0.33333333333333331;
  out6[25] = t196_tmp_tmp * t463 * 3.1415926535897931 / 3.0;
  out6[26] = t11 * t551 * 3.1415926535897931;
  out6[27] = 0.0;
  out6[28] = 0.0;
  out6[29] = 0.0;
  out6[30] = t196_tmp_tmp * t300 * 3.1415926535897931 * -0.33333333333333331;
  out6[31] = t196_tmp_tmp * t473 * 3.1415926535897931 / 3.0;
  out6[32] = t11 * t568 * 3.1415926535897931;
  out6[33] = 0.0;
  out6[34] = 0.0;
  out6[35] = 0.0;
  out6[36] = t196_tmp_tmp * t303 * 3.1415926535897931 * -0.33333333333333331;
  out6[37] = t196_tmp_tmp * t474 * 3.1415926535897931 / 3.0;
  out6[38] = t11 * t571 * 3.1415926535897931;
  out6[39] = 0.0;
  out6[40] = 0.0;
  out6[41] = 0.0;
  out6[42] = t196_tmp_tmp * t306 * 3.1415926535897931 * -0.33333333333333331;
  out6[43] = t196_tmp_tmp * t475 * 3.1415926535897931 / 3.0;
  out6[44] = t11 * t574 * 3.1415926535897931;
  out6[45] = 0.0;
  out6[46] = 0.0;
  out6[47] = 0.0;
  out6[48] = t196_tmp_tmp * t282 * 3.1415926535897931 * -0.33333333333333331;
  out6[49] = t196_tmp_tmp * t398 * 3.1415926535897931 * -0.33333333333333331;
  out6[50] = t196_tmp_tmp * t566 * 3.1415926535897931;
  out6[51] = 0.0;
  out6[52] = 0.0;
  out6[53] = 0.0;
  out6[54] = t196_tmp_tmp * t301 * 3.1415926535897931 * -0.33333333333333331;
  out6[55] = t196_tmp_tmp * t414 * 3.1415926535897931 * -0.33333333333333331;
  out6[56] = t196_tmp_tmp * t576 * 3.1415926535897931;
  out6[57] = 0.0;
  out6[58] = 0.0;
  out6[59] = 0.0;
  out6[60] = t196_tmp_tmp * t304 * 3.1415926535897931 * -0.33333333333333331;
  out6[61] = t196_tmp_tmp * t416 * 3.1415926535897931 * -0.33333333333333331;
  out6[62] = t196_tmp_tmp * t577 * 3.1415926535897931;
  out6[63] = 0.0;
  out6[64] = 0.0;
  out6[65] = 0.0;
  out6[66] = t196_tmp_tmp * t307 * 3.1415926535897931 * -0.33333333333333331;
  out6[67] = t196_tmp_tmp * t418 * 3.1415926535897931 * -0.33333333333333331;
  out6[68] = t196_tmp_tmp * t578 * 3.1415926535897931;
  out6[69] = 0.0;
  out6[70] = 0.0;
  out6[71] = 0.0;
  out6[72] = t196_tmp_tmp * t313 * 3.1415926535897931 * -0.33333333333333331;
  out6[73] = t196_tmp_tmp * t402 * 3.1415926535897931 * -0.33333333333333331;
  out6[74] = t196_tmp_tmp * t557 * 3.1415926535897931;
  out6[75] = t119 * t46 * t186;
  out6[76] = t184 * t691 * t186;
  out6[77] = t159 * t158 * 3.1415926535897931 * -0.16666666666666666;
  out6[78] = t196_tmp_tmp * t291 * 3.1415926535897931 * -0.33333333333333331;
  out6[79] = t196_tmp_tmp * t385 * 3.1415926535897931 * -0.33333333333333331;
  out6[80] = t196_tmp_tmp * t530 * 3.1415926535897931;
  out6[81] = t119 * t67 * t186;
  out6[82] = t119 * t139 * t186;
  out6[83] = t159 * t209 * 3.1415926535897931 * -0.16666666666666666;
  out6[84] = t196_tmp_tmp * t294 * 3.1415926535897931 * -0.33333333333333331;
  out6[85] = t196_tmp_tmp * t389 * 3.1415926535897931 * -0.33333333333333331;
  out6[86] = t196_tmp_tmp * t535 * 3.1415926535897931;
  out6[87] = t119 * t69 * t186;
  out6[88] = t119 * t671 * t186;
  out6[89] = t159 * t172 * 3.1415926535897931 * -0.16666666666666666;
  out6[90] = t196_tmp_tmp * t297 * 3.1415926535897931 * -0.33333333333333331;
  out6[91] = t196_tmp_tmp * t393 * 3.1415926535897931 * -0.33333333333333331;
  out6[92] = t196_tmp_tmp * t540 * 3.1415926535897931;
  out6[93] = t119 * t129 * t186;
  out6[94] = t119 * t34 * t186;
  out6[95] = t159 * t156 * 3.1415926535897931 * -0.16666666666666666;
  out6[96] = t196_tmp_tmp * t345 * 3.1415926535897931 / 3.0;
  out6[97] = t196_tmp_tmp * t421 * 3.1415926535897931 * -0.33333333333333331;
  out6[98] = t11 * t509 * 3.1415926535897931;
  out6[99] = t119 * t132 * t186;
  out6[100] = t119 * t142 * t186;
  out6[101] = t159 * t665 * 3.1415926535897931 / 6.0;
  out6[102] = t196_tmp_tmp * t319 * 3.1415926535897931 / 3.0;
  out6[103] = t196_tmp_tmp * t406 * 3.1415926535897931 * -0.33333333333333331;
  out6[104] = t11 * t495 * 3.1415926535897931;
  out6[105] = t119 * t604 * t186;
  out6[106] = t119 * t38 * t186;
  out6[107] = t159 * t713 * 3.1415926535897931 * -0.16666666666666666;
  out6[108] = t196_tmp_tmp * t324 * 3.1415926535897931 / 3.0;
  out6[109] = t196_tmp_tmp * t409 * 3.1415926535897931 * -0.33333333333333331;
  out6[110] = t11 * t499 * 3.1415926535897931;
  out6[111] = t119 * t596 * t186;
  out6[112] = t119 * t37 * t186;
  out6[113] = t159 * t141 * 3.1415926535897931 * -0.16666666666666666;
  out6[114] = t196_tmp_tmp * t329 * 3.1415926535897931 / 3.0;
  out6[115] = t196_tmp_tmp * t412 * 3.1415926535897931 * -0.33333333333333331;
  out6[116] = t11 * t503 * 3.1415926535897931;
  out6[117] = t119 * t598 * t186;
  out6[118] = t119 * t108 * t186;
  out6[119] = t159 * t196 * 3.1415926535897931 * -0.16666666666666666;
  out6[120] = t196_tmp_tmp * t288 * 3.1415926535897931 * -0.33333333333333331;
  out6[121] = t196_tmp_tmp * t457 * 3.1415926535897931 / 3.0;
  out6[122] = t11 * t524 * 3.1415926535897931;
  out6[123] = t184 * t120 * t186;
  out6[124] = t119 * t112 * t186;
  out6[125] = t159 * t173 * 3.1415926535897931 * -0.16666666666666666;
  out6[126] = t196_tmp_tmp * t269 * 3.1415926535897931 * -0.33333333333333331;
  out6[127] = t196_tmp_tmp * t436 * 3.1415926535897931 / 3.0;
  out6[128] = t11 * t512 * 3.1415926535897931;
  out6[129] = t119 * t606 * t186;
  out6[130] = t119 * t45 * t186;
  out6[131] = t159 * t704 * 3.1415926535897931 * -0.16666666666666666;
  out6[132] = t196_tmp_tmp * t274 * 3.1415926535897931 * -0.33333333333333331;
  out6[133] = t196_tmp_tmp * t441 * 3.1415926535897931 / 3.0;
  out6[134] = t11 * t515 * 3.1415926535897931;
  out6[135] = t119 * t600 * t186;
  out6[136] = t119 * t41 * t186;
  out6[137] = t159 * t198 * 3.1415926535897931 * -0.16666666666666666;
  out6[138] = t196_tmp_tmp * t279 * 3.1415926535897931 * -0.33333333333333331;
  out6[139] = t196_tmp_tmp * t446 * 3.1415926535897931 / 3.0;
  out6[140] = t11 * t518 * 3.1415926535897931;
  out6[141] = t119 * t602 * t186;
  out6[142] = t119 * t42 * t186;
  out6[143] = t159 * t187 * 3.1415926535897931 * -0.16666666666666666;
  out7[0] = t242;
  out7[1] = -in1[6] * t447 * t480;
  out7[2] = t35_tmp;
  out7[3] = 0.0;
  out7[4] = 0.0;
  out7[5] = 0.0;
  out7[6] = t107;
  out7[7] = -in1[6] * t464 * t480;
  out7[8] = -in1[7] * t519 * t583;
  out7[9] = 0.0;
  out7[10] = 0.0;
  out7[11] = 0.0;
  out7[12] = t128;
  out7[13] = -in1[6] * t466 * t480;
  out7[14] = -in1[7] * t520 * t583;
  out7[15] = 0.0;
  out7[16] = 0.0;
  out7[17] = 0.0;
  out7[18] = t65;
  out7[19] = -in1[6] * t469 * t480;
  out7[20] = -in1[7] * t521 * t583;
  out7[21] = 0.0;
  out7[22] = 0.0;
  out7[23] = 0.0;
  out7[24] = t220;
  out7[25] = t130;
  out7[26] = -in1[7] * t551 * t583;
  out7[27] = 0.0;
  out7[28] = 0.0;
  out7[29] = 0.0;
  out7[30] = -in1[5] * t300 * t373;
  out7[31] = t615;
  out7[32] = -in1[7] * t568 * t583;
  out7[33] = 0.0;
  out7[34] = 0.0;
  out7[35] = 0.0;
  out7[36] = -in1[5] * t303 * t373;
  out7[37] = t123_tmp;
  out7[38] = -in1[7] * t571 * t583;
  out7[39] = 0.0;
  out7[40] = 0.0;
  out7[41] = 0.0;
  out7[42] = -in1[5] * t306 * t373;
  out7[43] = t132_tmp;
  out7[44] = -in1[7] * t574 * t583;
  out7[45] = 0.0;
  out7[46] = 0.0;
  out7[47] = 0.0;
  out7[48] = -in1[5] * t282 * t373;
  out7[49] = -in1[6] * t398 * t480;
  out7[50] = t24;
  out7[51] = 0.0;
  out7[52] = 0.0;
  out7[53] = 0.0;
  out7[54] = -in1[5] * t301 * t373;
  out7[55] = -in1[6] * t414 * t480;
  out7[56] = t38_tmp;
  out7[57] = 0.0;
  out7[58] = 0.0;
  out7[59] = 0.0;
  out7[60] = -in1[5] * t304 * t373;
  out7[61] = -in1[6] * t416 * t480;
  out7[62] = t42_tmp;
  out7[63] = 0.0;
  out7[64] = 0.0;
  out7[65] = 0.0;
  out7[66] = -in1[5] * t307 * t373;
  out7[67] = -in1[6] * t418 * t480;
  out7[68] = t46_tmp;
  out7[69] = 0.0;
  out7[70] = 0.0;
  out7[71] = 0.0;
  out7[72] = -in1[5] * t313 * t373;
  out7[73] = -in1[6] * t402 * t480;
  out7[74] = t25_tmp;
  out7[75] = -in1[8] * t46 * t123;
  out7[76] = t170;
  out7[77] = -in1[10] * t158 * t227;
  out7[78] = -in1[5] * t291 * t373;
  out7[79] = t67_tmp;
  out7[80] = t34_tmp;
  out7[81] = t31_tmp;
  out7[82] = -in1[9] * t139 * t33;
  out7[83] = -in1[10] * t209 * t227;
  out7[84] = -in1[5] * t294 * t373;
  out7[85] = -in1[6] * t389 * t480;
  out7[86] = t27_tmp;
  out7[87] = -in1[8] * t69 * t123;
  out7[88] = -in1[9] * t671 * t33;
  out7[89] = -in1[10] * t172 * t227;
  out7[90] = -in1[5] * t297 * t373;
  out7[91] = -in1[6] * t393 * t480;
  out7[92] = b_t29_tmp;
  out7[93] = -in1[8] * t129 * t123;
  out7[94] = -in1[9] * t34 * t33;
  out7[95] = -in1[10] * t156 * t227;
  out7[96] = t397;
  out7[97] = -in1[6] * t421 * t480;
  out7[98] = -in1[7] * t509 * t583;
  out7[99] = -in1[8] * t132 * t123;
  out7[100] = -in1[9] * t142 * t33;
  out7[101] = t45_tmp;
  out7[102] = t211;
  out7[103] = -in1[6] * t406 * t480;
  out7[104] = -in1[7] * t495 * t583;
  out7[105] = -in1[8] * t604 * t123;
  out7[106] = t41_tmp;
  out7[107] = -in1[10] * t713 * t227;
  out7[108] = t218;
  out7[109] = -in1[6] * t409 * t480;
  out7[110] = -in1[7] * t499 * t583;
  out7[111] = -in1[8] * t596 * t123;
  out7[112] = -in1[9] * t37 * t33;
  out7[113] = -in1[10] * t141 * t227;
  out7[114] = t121;
  out7[115] = -in1[6] * t412 * t480;
  out7[116] = -in1[7] * t503 * t583;
  out7[117] = -in1[8] * t598 * t123;
  out7[118] = -in1[9] * t108 * t33;
  out7[119] = -in1[10] * t196 * t227;
  out7[120] = -in1[5] * t288 * t373;
  out7[121] = t21;
  out7[122] = -in1[7] * t524 * t583;
  out7[123] = t37_tmp;
  out7[124] = -in1[9] * t112 * t33;
  out7[125] = -in1[10] * t173 * t227;
  out7[126] = -in1[5] * t269 * t373;
  out7[127] = t39_tmp;
  out7[128] = -in1[7] * t512 * t583;
  out7[129] = -in1[8] * t606 * t123;
  out7[130] = -in1[9] * t45 * t33;
  out7[131] = t218_tmp_tmp;
  out7[132] = -in1[5] * t274 * t373;
  out7[133] = t43_tmp;
  out7[134] = -in1[7] * t515 * t583;
  out7[135] = -in1[8] * t600 * t123;
  out7[136] = -in1[9] * t41 * t33;
  out7[137] = -in1[10] * t198 * t227;
  out7[138] = -in1[5] * t279 * t373;
  out7[139] = t47_tmp;
  out7[140] = -in1[7] * t518 * t583;
  out7[141] = -in1[8] * t602 * t123;
  out7[142] = -in1[9] * t42 * t33;
  out7[143] = -in1[10] * t187 * t227;
  *out8 = 1.0;
}

/* End of code generation (sprdmpF25.c) */
