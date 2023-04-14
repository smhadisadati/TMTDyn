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
#include "EOM.h"
#include "sprdmpF19.h"
#include "sqrt.h"
#include "error.h"
#include "EOM_data.h"

/* Variable Definitions */
static emlrtRSInfo n_emlrtRSI = { 64,  /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 77,  /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 78,  /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 79,  /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 81,  /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 109, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 146, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 248, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 249, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 252, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 254, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 255, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 256,/* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 261,/* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo cb_emlrtRSI = { 262,/* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo db_emlrtRSI = { 263,/* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo eb_emlrtRSI = { 266,/* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo fb_emlrtRSI = { 267,/* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 268,/* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo hb_emlrtRSI = { 272,/* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo ib_emlrtRSI = { 363,/* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo jb_emlrtRSI = { 444,/* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo kb_emlrtRSI = { 522,/* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo lb_emlrtRSI = { 564,/* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo mb_emlrtRSI = { 606,/* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo nb_emlrtRSI = { 650,/* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo ob_emlrtRSI = { 651,/* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

/* Function Definitions */
void b_sprdmpF19(const emlrtStack *sp, const real_T in1[34], const real_T in2[36],
                 real_T s, real_T out1[108], real_T out2[6], real_T out3[6],
                 real_T out4[6])
{
  real_T t2;
  real_T t102;
  real_T t92;
  real_T t104;
  real_T t3;
  real_T t554;
  real_T t304;
  real_T t302;
  real_T t4;
  real_T t168;
  real_T t176;
  real_T t167;
  real_T t5;
  real_T t9;
  real_T t13;
  real_T t17;
  real_T t18;
  real_T t19;
  real_T t20;
  real_T t524;
  real_T t21_tmp;
  real_T t21;
  real_T t22_tmp;
  real_T t22;
  real_T t474;
  real_T t469;
  real_T t23;
  real_T t24_tmp;
  real_T t24;
  real_T t25_tmp;
  real_T b_t25_tmp;
  real_T t471;
  real_T t25;
  real_T t26_tmp;
  real_T t26;
  real_T t27_tmp;
  real_T t27;
  real_T t520;
  real_T t28;
  real_T t547;
  real_T t29;
  real_T t30_tmp;
  real_T t30;
  real_T t533;
  real_T t31;
  real_T t32_tmp;
  real_T t32;
  real_T t33_tmp;
  real_T t33;
  real_T t34_tmp;
  real_T t34;
  real_T t542;
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
  real_T t52;
  real_T t53_tmp;
  real_T t53;
  real_T t54;
  real_T t506;
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
  real_T t321;
  real_T t94;
  real_T t98;
  real_T t99;
  real_T t100;
  real_T t103_tmp;
  real_T t103;
  real_T t550;
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
  real_T t517;
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
  real_T t168_tmp;
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
  real_T t186;
  real_T t187;
  real_T t190;
  real_T t192;
  real_T t195_tmp;
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
  real_T t382;
  real_T t375;
  real_T t383;
  real_T t384;
  real_T t385;
  real_T t386;
  real_T t390;
  real_T t394;
  real_T t395;
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
  st.site = &n_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t2 = s * s;
  t102 = in2[9] * s;
  t92 = in2[10] * t2;
  t104 = in2[11] * s * t2;
  t3 = (t102 + t92) + t104;
  t554 = in2[12] * s;
  t304 = in2[13] * t2;
  t302 = in2[14] * s * t2;
  t4 = (t554 + t304) + t302;
  t168 = in2[15] * s;
  t176 = in2[16] * t2;
  t167 = in2[17] * s * t2;
  t5 = (t168 + t176) + t167;
  st.site = &o_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t9 = t3 * t3;
  st.site = &p_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t13 = t4 * t4;
  st.site = &q_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t17 = t5 * t5;
  t18 = ((-t9 - t13) - t17) + 1.0;
  t19 = t18;
  st.site = &r_emlrtRSI;
  b_sqrt(&st, &t19);
  t20 = ((t9 + t13) + t17) - 1.0;
  t524 = s * t3;
  t21_tmp = t524 * t4;
  t21 = t21_tmp * 4.0;
  t22_tmp = s * t9;
  t22 = t22_tmp * 2.0;
  t474 = t2 * t3;
  t469 = t474 * t4;
  t23 = t469 * 6.0;
  t24_tmp = t2 * t9;
  t24 = t24_tmp * 3.0;
  t25_tmp = s * t2;
  b_t25_tmp = t25_tmp * t3;
  t471 = b_t25_tmp * t4;
  t25 = t471 * 8.0;
  t26_tmp = t25_tmp * t9;
  t26 = t26_tmp * 4.0;
  t27_tmp = s * t4;
  t27 = t27_tmp * t19 * 4.0;
  t520 = t524 * t5;
  t28 = t520 * 4.0;
  t547 = t27_tmp * t5;
  t29 = t547 * 4.0;
  t30_tmp = s * t13;
  t30 = t30_tmp * 2.0;
  t533 = t474 * t5;
  t31 = t533 * 6.0;
  t32_tmp = t2 * t4;
  t32 = t32_tmp * t19 * 6.0;
  t33_tmp = t32_tmp * t5;
  t33 = t33_tmp * 6.0;
  t34_tmp = t2 * t13;
  t34 = t34_tmp * 3.0;
  t542 = b_t25_tmp * t5;
  t35 = t542 * 8.0;
  t36_tmp = t25_tmp * t4;
  t36 = t36_tmp * t19 * 8.0;
  t37_tmp = t36_tmp * t5;
  t37 = t37_tmp * 8.0;
  t38_tmp = t25_tmp * t13;
  t38 = t38_tmp * 4.0;
  t42 = ((in2[6] * s * 2.0 + in2[7] * t2 * 3.0) + in2[8] * s * t2 * 4.0) + 1.0;
  t46 = (in2[3] * s * 2.0 + in2[4] * t2 * 3.0) + in2[5] * s * t2 * 4.0;
  t9 = t18;
  st.site = &s_emlrtRSI;
  b_sqrt(&st, &t9);
  t47 = 1.0 / t9;
  t51 = (in2[0] * s * 2.0 + in2[1] * t2 * 3.0) + in2[2] * s * t2 * 4.0;
  t52 = s * t42;
  t53_tmp = t524 * t46;
  t53 = t52 - t53_tmp * t47;
  t54 = s * t46;
  t506 = t524 * t42;
  t56 = t54 + t506 * t47;
  t59 = (t3 * t42 + t19 * t46) - t5 * t51;
  t63 = (t4 * t51 + t19 * t42) - t3 * t46;
  t66 = (in2[9] + in2[10] * s * 2.0) + in2[11] * t2 * 3.0;
  t70 = (in2[12] + in2[13] * s * 2.0) + in2[14] * t2 * 3.0;
  t74 = (in2[15] + in2[16] * s * 2.0) + in2[17] * t2 * 3.0;
  t76 = (t3 * t66 * 2.0 + t4 * t70 * 2.0) + t5 * t74 * 2.0;
  t77 = t102 * 2.0;
  t78 = s * t66 * 2.0;
  t79 = t92 * 2.0;
  t80 = t104 * 2.0;
  t81 = ((t77 + t78) + t79) + t80;
  st.site = &t_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  if (t18 < 0.0) {
    c_st.site = &qb_emlrtRSI;
    error(&c_st);
  }

  t82 = 1.0 / muDoubleScalarPower(t18, 1.5);
  t86 = (t3 * t51 + t4 * t46) + t5 * t42;
  t89 = (t5 * t46 + t19 * t51) - t4 * t42;
  t9 = t2 * t42;
  t91_tmp = t474 * t46;
  t91 = t9 - t91_tmp * t47;
  t92 = t2 * t46;
  t321 = t474 * t42;
  t94 = t92 + t321 * t47;
  t98 = t524 * 4.0;
  t99 = t2 * t66 * 2.0;
  t100 = t98 + t99;
  t102 = t25_tmp * t42;
  t103_tmp = b_t25_tmp * t46;
  t103 = t102 - t103_tmp * t47;
  t104 = t25_tmp * t46;
  t550 = b_t25_tmp * t42;
  t106 = t104 + t550 * t47;
  t108 = t474 * 6.0;
  t109 = t25_tmp * t66 * 2.0;
  t110 = t108 + t109;
  t111 = s * t63;
  t18 = s * t51;
  t113_tmp = t27_tmp * t42;
  t113 = t18 - t113_tmp * t47;
  t115_tmp = t27_tmp * t47;
  t115 = t52 + t115_tmp * t51;
  t116 = s * t86;
  t118 = s * t74 * 2.0;
  t119 = t554 * 2.0;
  t120 = t304 * 2.0;
  t121 = t302 * 2.0;
  t122 = t21_tmp * t76 * t82;
  t124_tmp = s * t70 * 2.0;
  t125_tmp = (t119 + t120) + t121;
  t125 = t125_tmp + t124_tmp;
  t127 = t2 * t63;
  t128 = t2 * t86;
  t52 = t2 * t51;
  t130_tmp = t32_tmp * t42;
  t130 = t52 - t130_tmp * t47;
  t132_tmp = t32_tmp * t47;
  t132 = t9 + t132_tmp * t51;
  t134 = t2 * t74 * 2.0;
  t135 = t27_tmp * 4.0;
  t136 = t469 * t76 * t82;
  t138_tmp = t2 * t70 * 2.0;
  t139 = t135 + t138_tmp;
  t141 = t25_tmp * t63;
  t142 = t25_tmp * t86;
  t9 = t25_tmp * t51;
  t144_tmp = t36_tmp * t42;
  t144 = t9 - t144_tmp * t47;
  t146_tmp = t36_tmp * t47;
  t146 = t102 + t146_tmp * t51;
  t148 = t25_tmp * t74 * 2.0;
  t149 = t32_tmp * 6.0;
  t150 = t471 * t76 * t82;
  t153_tmp = t25_tmp * t70 * 2.0;
  t154 = t149 + t153_tmp;
  t156_tmp = s * t5;
  t517 = t156_tmp * t46;
  t156 = t18 + t517 * t47;
  t157 = s * t89;
  t158_tmp = t156_tmp * t47;
  t158 = t54 - t158_tmp * t51;
  t160_tmp = t168 * 2.0;
  t161_tmp = t176 * 2.0;
  t162_tmp = t167 * 2.0;
  t163 = t520 * t76 * t82;
  t164 = ((t118 + t160_tmp) + t161_tmp) + t162_tmp;
  t165 = t547 * t76 * t82;
  t54 = t2 * t5;
  t554 = t54 * t46;
  t167 = t52 + t554 * t47;
  t168_tmp = t54 * t47;
  t168 = t92 - t168_tmp * t51;
  t169 = t2 * t89;
  t171_tmp = t156_tmp * 4.0;
  t172 = t533 * t76 * t82;
  t173 = t134 + t171_tmp;
  t174 = t33_tmp * t76 * t82;
  t102 = t25_tmp * t5;
  t92 = t102 * t46;
  t176 = t9 + t92 * t47;
  t177_tmp = t102 * t47;
  t104 -= t177_tmp * t51;
  t178 = t25_tmp * t89;
  t180_tmp = t54 * 6.0;
  t181 = t542 * t76 * t82;
  t182 = t148 + t180_tmp;
  t183 = t37_tmp * t76 * t82;
  t184 = 1.0 / in1[33];
  t9 = muDoubleScalarCos(in1[20]);
  st.site = &u_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t186 = in1[2] * in1[2];
  st.site = &v_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t187 = in1[3] * in1[3];
  st.site = &w_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t190 = in1[18] * in1[18];
  t18 = muDoubleScalarSin(in1[20]);
  st.site = &x_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t192 = 1.0 / (t18 * t18);
  st.site = &y_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  st.site = &ab_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t52 = in1[33] * in1[33];
  t195_tmp = t52 * (t9 * t9);
  st.site = &bb_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  st.site = &cb_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  st.site = &db_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  st.site = &eb_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  st.site = &fb_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  st.site = &gb_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t208 = 1.0 / t52 * (t186 * t186 - t187 * t187) + t190 * t190 * (1.0 /
    muDoubleScalarPower(t18, 4.0)) * ((t195_tmp - 1.0) * (t195_tmp - 1.0)) * 6.0;
  t209 = t208 * 3.1415926535897931 / 4.0;
  st.site = &hb_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t9 = t54 * t19 * 6.0;
  t212 = t23 + t9;
  t213 = t31 - t32;
  t18 = t102 * t19 * 8.0;
  t215 = t25 + t18;
  t216 = t35 - t36;
  t217_tmp = t2 * t17;
  b_t217_tmp = t217_tmp * 3.0;
  t218_tmp = t25_tmp * t17;
  b_t218_tmp = t218_tmp * 4.0;
  t222_tmp = t2 * t59;
  t225 = ((((t19 * t168 + t222_tmp) + t321) + t33_tmp * t42 * t47) - t5 * t167)
    - t168_tmp * t89;
  t227_tmp = t25_tmp * t59;
  t230 = ((((t19 * t104 + t227_tmp) + t550) + t37_tmp * t42 * t47) - t5 * t176)
    - t177_tmp * t89;
  t233_tmp = s * t59;
  t236 = ((((t19 * t158 + t233_tmp) + t506) + t547 * t42 * t47) - t5 * t156) -
    t158_tmp * t89;
  t52 = t156_tmp * t19 * 4.0;
  t238 = t21 + t52;
  t239_tmp = s * t17;
  b_t239_tmp = t239_tmp * 2.0;
  t242_tmp = t524 * t47;
  t242 = ((t116 + t4 * t56) + t5 * t53) - t242_tmp * t89;
  t245_tmp = t474 * t47;
  t245 = ((t128 + t4 * t94) + t5 * t91) - t245_tmp * t89;
  t248_tmp = b_t25_tmp * t47;
  t248 = ((t142 + t4 * t106) + t5 * t103) - t248_tmp * t89;
  t249_tmp = s * t20 * 2.0;
  t250_tmp = -t22 + t30;
  t250 = (t250_tmp + b_t239_tmp) + t249_tmp;
  t255_tmp = t2 * t20 * 3.0;
  t256_tmp = -t24 + t34;
  t256 = (t256_tmp + b_t217_tmp) + t255_tmp;
  t257_tmp = t25_tmp * t20 * 4.0;
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
  d_t279_tmp = t547 * t46 * t47;
  t279 = ((((t111 - t53_tmp) + b_t279_tmp) + t279_tmp) + c_t279_tmp) +
    d_t279_tmp;
  t284 = t27 - t28;
  st.site = &ib_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t294 = muDoubleScalarPower(muDoubleScalarAbs(((((((((((((((((t212 * in2[22] +
    t213 * in2[25]) + t215 * in2[23]) + t216 * in2[26]) + t225 * in2[34]) + t230
    * in2[35]) + t236 * in2[33]) + t238 * in2[21]) + t242 * in2[27]) + t245 *
    in2[28]) + t248 * in2[29]) - t256 * in2[19]) - t258 * in2[20]) - t263 * in2
    [31]) - t268 * in2[32]) - t279 * in2[30]) - t284 * in2[24]) - t250 * in2[18]),
    in1[11] - 1.0);
  t302 = t474 * t19 * 6.0;
  t303 = t33 + t302;
  t304 = b_t25_tmp * t19 * 8.0;
  t305 = t37 + t304;
  t309 = ((((t127 + t19 * t91) + t32_tmp * t51) + t533 * t47 * t51) - t3 * t94)
    - t245_tmp * t59;
  t313 = ((((t141 + t19 * t103) + t36_tmp * t51) + t542 * t47 * t51) - t3 * t106)
    - t248_tmp * t59;
  t319 = ((((t111 + t19 * t53) + t27_tmp * t51) + t520 * t47 * t51) - t3 * t56)
    - t242_tmp * t59;
  t321 = t524 * t19 * 4.0;
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
  d_t351_tmp = t533 * t42 * t47;
  t351 = ((((t169 - t130_tmp) + b_t351_tmp) + t351_tmp) + c_t351_tmp) +
    d_t351_tmp;
  t356_tmp = t5 * t104;
  b_t356_tmp = t19 * t176;
  c_t356_tmp = t177_tmp * t59;
  d_t356_tmp = t542 * t42 * t47;
  t356 = ((((t178 - t144_tmp) + b_t356_tmp) + t356_tmp) + c_t356_tmp) +
    d_t356_tmp;
  t364_tmp = t5 * t158;
  b_t364_tmp = t19 * t156;
  c_t364_tmp = t158_tmp * t59;
  d_t364_tmp = t520 * t42 * t47;
  t364 = ((((t157 - t113_tmp) + b_t364_tmp) + t364_tmp) + c_t364_tmp) +
    d_t364_tmp;
  t382 = t21 - t52;
  st.site = &jb_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t375 = muDoubleScalarPower(muDoubleScalarAbs(((((((((((((((((t333 * in2[19] +
    t303 * in2[25]) + t336 * in2[20]) + t305 * in2[26]) + t309 * in2[28]) + t313
    * in2[29]) + t319 * in2[27]) + t382 * in2[18]) + t322 * in2[24]) + t325 *
    in2[30]) + t328 * in2[31]) + t331 * in2[32]) - t339 * in2[22]) - t340 * in2
    [23]) - t351 * in2[34]) - t356 * in2[35]) - t364 * in2[33]) - t332 * in2[21]),
    in1[11] - 1.0);
  t383 = t31 + t32;
  t384 = t35 + t36;
  t385 = t54 * t51;
  t386 = t102 * t51;
  t390 = ((((t169 + t19 * t130) + t554) + t469 * t46 * t47) - t4 * t132) -
    t132_tmp * t63;
  t394 = ((((t178 + t19 * t144) + t92) + t471 * t46 * t47) - t4 * t146) -
    t146_tmp * t63;
  t395 = t156_tmp * t51;
  t399 = ((((t157 + t19 * t113) + t517) + t21_tmp * t46 * t47) - t4 * t115) -
    t115_tmp * t63;
  t400 = t27 + t28;
  t403 = ((t116 + t3 * t156) + t4 * t158) - t158_tmp * t63;
  t406 = ((t128 + t3 * t167) + t4 * t168) - t168_tmp * t63;
  t409 = ((t142 + t3 * t176) + t4 * t104) - t177_tmp * t63;
  t410 = ((t22 + t30) - b_t239_tmp) + t249_tmp;
  t412 = t33 - t302;
  t415 = t37 - t304;
  t417 = ((t24 + t34) - b_t217_tmp) + t255_tmp;
  t418 = ((t26 + t38) - b_t218_tmp) + t257_tmp;
  t46 = t3 * t91;
  t36 = t19 * t94;
  t115 = t245_tmp * t63;
  t158 = t469 * t47 * t51;
  t423 = ((((t222_tmp - t385) + t36) + t46) + t115) + t158;
  t42 = t3 * t103;
  t144 = t19 * t106;
  t156_tmp = t248_tmp * t63;
  t130 = t471 * t47 * t51;
  t428 = ((((t227_tmp - t386) + t144) + t42) + t156_tmp) + t130;
  t132 = t3 * t53;
  t302 = t19 * t56;
  t304 = t242_tmp * t63;
  b_t25_tmp = t21_tmp * t47 * t51;
  t439 = ((((t233_tmp - t395) + t302) + t132) + t304) + b_t25_tmp;
  t56 = t29 - t321;
  st.site = &kb_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t51 = muDoubleScalarPower(muDoubleScalarAbs(((((((((((((((((t383 * in2[19] +
    t412 * in2[22]) + t384 * in2[20]) + t415 * in2[23]) + t390 * in2[31]) + t394
    * in2[32]) + t399 * in2[30]) + t400 * in2[18]) + t56 * in2[21]) + t403 *
    in2[33]) + t406 * in2[34]) + t409 * in2[35]) - t417 * in2[25]) - t418 * in2
    [26]) - t423 * in2[28]) - t428 * in2[29]) - t439 * in2[27]) - t410 * in2[24]),
    in1[11] - 1.0);
  t21_tmp = t3 * t47;
  t52 = s * t19 * 4.0 + t2 * t47 * t76;
  t94 = ((t52 + t21_tmp * t100) + t24_tmp * t76 * t82) - t245_tmp * t66 * 2.0;
  t103 = (((-t148 + t150) + t180_tmp) + t21_tmp * t154) - t146_tmp * t66 * 2.0;
  t106 = (((-t149 + t153_tmp) + t181) + t21_tmp * t182) - t177_tmp * t66 * 2.0;
  t469 = (((-t134 + t136) + t171_tmp) + t21_tmp * t139) - t132_tmp * t66 * 2.0;
  t471 = (((-t135 + t138_tmp) + t172) + t21_tmp * t173) - t168_tmp * t66 * 2.0;
  t53 = (((((-t118 + t122) + t160_tmp) + t161_tmp) + t162_tmp) + t21_tmp * t125)
    - t115_tmp * t66 * 2.0;
  t474 = t21_tmp * t164;
  t54 = t2 * t19 * 6.0 + t25_tmp * t47 * t76;
  t91 = ((t54 + t21_tmp * t110) + t26_tmp * t76 * t82) - t248_tmp * t66 * 2.0;
  t33_tmp = t19 * 2.0 + s * t47 * t76;
  t128 = ((t33_tmp + t21_tmp * t81) + t22_tmp * t76 * t82) - t242_tmp * t66 *
    2.0;
  t37_tmp = t158_tmp * t66 * 2.0;
  t36_tmp = t125_tmp - t124_tmp;
  t142 = ((t36_tmp - t163) - t474) + t37_tmp;
  st.site = &lb_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t113 = muDoubleScalarPower(muDoubleScalarAbs((((((((t94 * in2[28] + t103 *
    in2[32]) + t106 * in2[35]) + t469 * in2[31]) + t471 * in2[34]) + t53 * in2
    [30]) + t91 * in2[29]) + t128 * in2[27]) - t142 * in2[33]), in1[11] - 1.0);
  t116 = t4 * t47;
  t156 = ((t52 + t116 * t139) + t34_tmp * t76 * t82) - t132_tmp * t70 * 2.0;
  t506 = t116 * t110;
  t31 = (((t108 - t109) + t183) + t116 * t182) - t177_tmp * t70 * 2.0;
  t17 = t116 * t100;
  t32 = (((t98 - t99) + t174) + t116 * t173) - t168_tmp * t70 * 2.0;
  t20 = t116 * t81;
  t27_tmp = ((t77 - t78) + t79) + t80;
  t35 = ((t27_tmp + t165) + t116 * t164) - t158_tmp * t70 * 2.0;
  t517 = ((t54 + t116 * t154) + t38_tmp * t76 * t82) - t146_tmp * t70 * 2.0;
  t520 = ((t33_tmp + t116 * t125) + t30_tmp * t76 * t82) - t115_tmp * t70 * 2.0;
  t104 = t134 + t136;
  t321 = t245_tmp * t70 * 2.0;
  t146 = ((t104 - t171_tmp) + t17) - t321;
  t9 = t148 + t150;
  t18 = t248_tmp * t70 * 2.0;
  t524 = ((t9 - t180_tmp) + t506) - t18;
  t92 = t242_tmp * t70 * 2.0;
  t533 = (((((-t118 - t122) + t160_tmp) + t161_tmp) + t162_tmp) - t20) + t92;
  st.site = &mb_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t542 = muDoubleScalarPower(muDoubleScalarAbs((((((((t156 * in2[31] + t524 *
    in2[29]) + t31 * in2[35]) + t146 * in2[28]) + t32 * in2[34]) + t35 * in2[33])
    + t517 * in2[32]) + t520 * in2[30]) - t533 * in2[27]), in1[11] - 1.0);
  t32_tmp = t5 * t47;
  t547 = ((t52 + t32_tmp * t173) + t217_tmp * t76 * t82) - t168_tmp * t74 * 2.0;
  t167 = t32_tmp * t110;
  t550 = (((-t108 + t109) + t183) + t32_tmp * t154) - t146_tmp * t74 * 2.0;
  t52 = t32_tmp * t100;
  t176 = (((-t98 + t99) + t174) + t32_tmp * t139) - t132_tmp * t74 * 2.0;
  t554 = t32_tmp * t81;
  t102 = t32_tmp * t125;
  t168 = ((t54 + t32_tmp * t182) + t218_tmp * t76 * t82) - t177_tmp * t74 * 2.0;
  t54 = ((t33_tmp + t32_tmp * t164) + t239_tmp * t76 * t82) - t158_tmp * t74 *
    2.0;
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
  out1[45] = ((((t395 - t233_tmp) - t132) - t302) - t304) - b_t25_tmp;
  out1[46] = ((((t385 - t222_tmp) - t46) - t36) - t115) - t158;
  out1[47] = ((((t386 - t42) - t144) - t227_tmp) - t156_tmp) - t130;
  out1[48] = t399;
  out1[49] = t390;
  out1[50] = t394;
  out1[51] = t403;
  out1[52] = t406;
  out1[53] = t409;
  memset(&out1[54], 0, 9U * sizeof(real_T));
  out1[63] = t128;
  out1[64] = t94;
  out1[65] = t91;
  out1[66] = t53;
  out1[67] = t469;
  out1[68] = t103;
  out1[69] = (((((-t119 - t120) - t121) + t124_tmp) + t163) + t474) - t37_tmp;
  out1[70] = t471;
  out1[71] = t106;
  memset(&out1[72], 0, 9U * sizeof(real_T));
  out1[81] = (((((t118 + t122) + t20) - t160_tmp) - t161_tmp) - t162_tmp) - t92;
  out1[82] = ((t104 + t17) - t171_tmp) - t321;
  out1[83] = ((t9 + t506) - t180_tmp) - t18;
  out1[84] = t520;
  out1[85] = t156;
  out1[86] = t517;
  out1[87] = t35;
  out1[88] = t32;
  out1[89] = t31;
  memset(&out1[90], 0, 9U * sizeof(real_T));
  t92 = t242_tmp * t74 * 2.0;
  out1[99] = (((t125_tmp + t163) + t554) - t124_tmp) - t92;
  t9 = t245_tmp * t74 * 2.0;
  out1[100] = (((t135 + t172) + t52) - t138_tmp) - t9;
  t18 = t248_tmp * t74 * 2.0;
  out1[101] = (((t149 + t181) + t167) - t153_tmp) - t18;
  t302 = t115_tmp * t74 * 2.0;
  out1[102] = (((((-t77 + t78) - t79) - t80) + t165) + t102) - t302;
  out1[103] = t176;
  out1[104] = t550;
  out1[105] = t54;
  out1[106] = t547;
  out1[107] = t168;
  t304 = (((t135 - t138_tmp) + t172) + t52) - t9;
  t52 = (((t149 - t153_tmp) + t181) + t167) - t18;
  t18 = ((t36_tmp + t163) + t554) - t92;
  t92 = ((t27_tmp - t165) - t102) + t302;
  st.site = &nb_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t104 = muDoubleScalarPower(muDoubleScalarAbs((((((((t547 * in2[34] + t52 *
    in2[29]) + t550 * in2[32]) + t304 * in2[28]) + t176 * in2[31]) + t18 * in2
    [27]) + t168 * in2[35]) + t54 * in2[33]) - t92 * in2[30]), in1[11] - 1.0);
  t9 = in1[33];
  st.site = &ob_emlrtRSI;
  b_sqrt(&st, &t9);
  t554 = 1.0 / t9;
  t102 = in1[1] * t184;
  t9 = t102 * (t184 * (t186 - t187) - t190 * t192 * (t195_tmp - 1.0) * 6.0) *
    3.1415926535897931;
  out2[0] = t9 * (((t5 * t59 - t4 * t63) + t3 * t86) + t19 * t89) / 3.0;
  out2[1] = t9 * (((t3 * t63 + t19 * t59) + t4 * t86) - t5 * t89) / 3.0;
  out2[2] = t9 * ((((-t3 * t59 + t19 * t63) + t5 * t86) + t4 * t89) - 1.0);
  t9 = t184 * t190 * t192 * (t195_tmp - 1.0) * (in1[19] * in1[19]) *
    3.1415926535897931;
  out2[3] = t102 * (t209 - t9 * 3.0) * (((t5 * t70 * 2.0 - t4 * t74 * 2.0) + t19
    * t66 * 2.0) + t21_tmp * t76);
  out2[4] = t102 * (t209 - t9 * 2.9999999999999991) * (((t5 * t66 * -2.0 + t3 *
    t74 * 2.0) + t19 * t70 * 2.0) + t116 * t76);
  out2[5] = t102 * t208 * 3.1415926535897931 * (((t4 * t66 * 2.0 - t3 * t70 *
    2.0) + t19 * t74 * 2.0) + t32_tmp * t76) / 6.0;
  out3[0] = ((((((((((((((((-in1[5] * t212 * t294 * in2[22] - in1[5] * t213 *
    t294 * in2[25]) - in1[5] * t215 * t294 * in2[23]) - in1[5] * t216 * t294 *
    in2[26]) - in1[5] * t225 * t294 * in2[34]) - in1[5] * t238 * t294 * in2[21])
                       - in1[5] * t230 * t294 * in2[35]) + in1[5] * t250 * t294 *
                      in2[18]) - in1[5] * t236 * t294 * in2[33]) - in1[5] * t242
                    * t294 * in2[27]) - in1[5] * t245 * t294 * in2[28]) + in1[5]
                  * t256 * t294 * in2[19]) - in1[5] * t248 * t294 * in2[29]) +
                in1[5] * t258 * t294 * in2[20]) + in1[5] * t263 * t294 * in2[31])
              + in1[5] * t268 * t294 * in2[32]) + in1[5] * t284 * t294 * in2[24])
    + in1[5] * t279 * t294 * in2[30];
  out3[1] = ((((((((((((((((-in1[6] * t303 * t375 * in2[25] - in1[6] * t305 *
    t375 * in2[26]) - in1[6] * t309 * t375 * in2[28]) - in1[6] * t313 * t375 *
    in2[29]) - in1[6] * t319 * t375 * in2[27]) - in1[6] * t322 * t375 * in2[24])
                       - in1[6] * t333 * t375 * in2[19]) + in1[6] * t332 * t375 *
                      in2[21]) - in1[6] * t325 * t375 * in2[30]) - in1[6] * t336
                    * t375 * in2[20]) - in1[6] * t328 * t375 * in2[31]) + in1[6]
                  * t339 * t375 * in2[22]) - in1[6] * t331 * t375 * in2[32]) +
                in1[6] * t340 * t375 * in2[23]) + in1[6] * t351 * t375 * in2[34])
              + in1[6] * t356 * t375 * in2[35]) + in1[6] * t364 * t375 * in2[33])
    - in1[6] * t375 * t382 * in2[18];
  out3[2] = ((((((((((((((((-in1[7] * t383 * t51 * in2[19] - in1[7] * t384 * t51
    * in2[20]) - in1[7] * t400 * t51 * in2[18]) - in1[7] * t390 * t51 * in2[31])
    - in1[7] * t394 * t51 * in2[32]) - in1[7] * t399 * t51 * in2[30]) + in1[7] *
                       t410 * t51 * in2[24]) - in1[7] * t412 * t51 * in2[22]) -
                     in1[7] * t403 * t51 * in2[33]) - in1[7] * t415 * t51 * in2
                    [23]) - in1[7] * t406 * t51 * in2[34]) + in1[7] * t417 * t51
                  * in2[25]) - in1[7] * t409 * t51 * in2[35]) + in1[7] * t418 *
                t51 * in2[26]) + in1[7] * t423 * t51 * in2[28]) + in1[7] * t428 *
              t51 * in2[29]) + in1[7] * t439 * t51 * in2[27]) - in1[7] * t51 *
    t56 * in2[21];
  out3[3] = (((((((-in1[8] * t94 * t113 * in2[28] - in1[8] * t103 * t113 * in2
                   [32]) - in1[8] * t469 * t113 * in2[31]) - in1[8] * t106 *
                 t113 * in2[35]) - in1[8] * t53 * t113 * in2[30]) - in1[8] *
               t471 * t113 * in2[34]) - in1[8] * t91 * t113 * in2[29]) - in1[8] *
             t128 * t113 * in2[27]) + in1[8] * t142 * t113 * in2[33];
  out3[4] = (((((((-in1[9] * t156 * t542 * in2[31] - in1[9] * t31 * t542 * in2
                   [35]) - in1[9] * t32 * t542 * in2[34]) - in1[9] * t35 * t542 *
                 in2[33]) - in1[9] * t517 * t542 * in2[32]) - in1[9] * t146 *
               t542 * in2[28]) - in1[9] * t520 * t542 * in2[30]) - in1[9] * t524
             * t542 * in2[29]) + in1[9] * t533 * t542 * in2[27];
  out3[5] = (((((((-in1[10] * t547 * t104 * in2[34] - in1[10] * t550 * t104 *
                   in2[32]) - in1[10] * t176 * t104 * in2[31]) - in1[10] * t304 *
                 t104 * in2[28]) - in1[10] * t168 * t104 * in2[35]) - in1[10] *
               t54 * t104 * in2[33]) - in1[10] * t52 * t104 * in2[29]) - in1[10]
             * t18 * t104 * in2[27]) + in1[10] * t92 * t104 * in2[30];
  out4[0] = 0.0;
  out4[1] = 0.0;
  out4[2] = -t190 * t192 * (t195_tmp - 1.0) * 3.1415926535897931 * (((((in1[21]
    + in1[22]) + in1[23]) + in1[24]) + in1[25]) + in1[26]);
  t102 = in1[21] * in1[19] * t190 * t192 * (t195_tmp - 1.0) * t554 *
    3.1415926535897931;
  t92 = in1[22] * in1[19] * t190 * t192 * (t195_tmp - 1.0) * t554 *
    3.1415926535897931;
  t104 = in1[23] * in1[19] * t190 * t192 * (t195_tmp - 1.0) * t554 *
    3.1415926535897931;
  t18 = in1[24] * in1[19] * t190 * t192 * (t195_tmp - 1.0) * t554 *
    3.1415926535897931;
  t52 = in1[25] * in1[19] * t190 * t192 * (t195_tmp - 1.0) * t554 *
    3.1415926535897931;
  t9 = in1[26] * in1[19] * t190 * t192 * (t195_tmp - 1.0) * t554 *
    3.1415926535897931;
  out4[3] = ((((t102 * -0.91522491349480972 - t92 * 0.91522491349480972) + t104 *
               0.1086532638769295) + t18 * 0.80657164961788008) + t52 *
             0.80657164961787986) + t9 * 0.1086532638769295;
  out4[4] = ((((t102 * -0.40294336787992679 + t92 * 0.40294336787992691) + t104 *
               0.99407970920288391) + t18 * 0.59113634132295712) - t52 *
             0.59113634132295745) - t9 * 0.99407970920288391;
  out4[5] = 0.0;
}

void sprdmpF19(const emlrtStack *sp, const real_T in1[34], const real_T in2[36],
               real_T s, real_T out1[108], real_T out2[6], real_T out3[6],
               real_T out4[6], real_T out5[3])
{
  real_T t2;
  real_T t102;
  real_T t92;
  real_T t104;
  real_T t3;
  real_T t554;
  real_T t562;
  real_T t302;
  real_T t4;
  real_T t168;
  real_T t176;
  real_T t548;
  real_T t5;
  real_T t9;
  real_T t13;
  real_T t17;
  real_T t18;
  real_T t19;
  real_T t20;
  real_T t21_tmp;
  real_T t460;
  real_T t21;
  real_T t22_tmp;
  real_T t22;
  real_T t23_tmp;
  real_T t467;
  real_T t23;
  real_T t24_tmp;
  real_T t24;
  real_T t25_tmp;
  real_T b_t25_tmp;
  real_T t469;
  real_T t25;
  real_T t26_tmp;
  real_T t26;
  real_T t27_tmp;
  real_T t27;
  real_T t520;
  real_T t28;
  real_T t474;
  real_T t29;
  real_T t30_tmp;
  real_T t30;
  real_T t524;
  real_T t31;
  real_T t32_tmp;
  real_T t32;
  real_T t33_tmp;
  real_T t33;
  real_T t34_tmp;
  real_T t34;
  real_T t533;
  real_T t35;
  real_T t36_tmp;
  real_T t36;
  real_T t547;
  real_T t37;
  real_T t38_tmp;
  real_T t38;
  real_T t42;
  real_T t46;
  real_T t47;
  real_T t51;
  real_T t52;
  real_T t53_tmp;
  real_T t53;
  real_T t54;
  real_T t509;
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
  real_T t550;
  real_T t94;
  real_T t98;
  real_T t99;
  real_T t100;
  real_T t103_tmp;
  real_T t103;
  real_T t506;
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
  real_T b_t156_tmp;
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
  real_T t167;
  real_T t168_tmp;
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
  real_T t186;
  real_T t187;
  real_T t190;
  real_T t192;
  real_T t195_tmp;
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
  real_T t382;
  real_T t375;
  real_T t383;
  real_T t384;
  real_T t385;
  real_T t386;
  real_T t390;
  real_T t394;
  real_T t395;
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
  real_T t453;
  real_T t463_tmp;
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
  st.site = &n_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t2 = s * s;
  t102 = in2[9] * s;
  t92 = in2[10] * t2;
  t104 = in2[11] * s * t2;
  t3 = (t102 + t92) + t104;
  t554 = in2[12] * s;
  t562 = in2[13] * t2;
  t302 = in2[14] * s * t2;
  t4 = (t554 + t562) + t302;
  t168 = in2[15] * s;
  t176 = in2[16] * t2;
  t548 = in2[17] * s * t2;
  t5 = (t168 + t176) + t548;
  st.site = &o_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t9 = t3 * t3;
  st.site = &p_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t13 = t4 * t4;
  st.site = &q_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t17 = t5 * t5;
  t18 = ((-t9 - t13) - t17) + 1.0;
  t19 = t18;
  st.site = &r_emlrtRSI;
  b_sqrt(&st, &t19);
  t20 = ((t9 + t13) + t17) - 1.0;
  t21_tmp = s * t3;
  t460 = t21_tmp * t4;
  t21 = t460 * 4.0;
  t22_tmp = s * t9;
  t22 = t22_tmp * 2.0;
  t23_tmp = t2 * t3;
  t467 = t23_tmp * t4;
  t23 = t467 * 6.0;
  t24_tmp = t2 * t9;
  t24 = t24_tmp * 3.0;
  t25_tmp = s * t2;
  b_t25_tmp = t25_tmp * t3;
  t469 = b_t25_tmp * t4;
  t25 = t469 * 8.0;
  t26_tmp = t25_tmp * t9;
  t26 = t26_tmp * 4.0;
  t27_tmp = s * t4;
  t27 = t27_tmp * t19 * 4.0;
  t520 = t21_tmp * t5;
  t28 = t520 * 4.0;
  t474 = t27_tmp * t5;
  t29 = t474 * 4.0;
  t30_tmp = s * t13;
  t30 = t30_tmp * 2.0;
  t524 = t23_tmp * t5;
  t31 = t524 * 6.0;
  t32_tmp = t2 * t4;
  t32 = t32_tmp * t19 * 6.0;
  t33_tmp = t32_tmp * t5;
  t33 = t33_tmp * 6.0;
  t34_tmp = t2 * t13;
  t34 = t34_tmp * 3.0;
  t533 = b_t25_tmp * t5;
  t35 = t533 * 8.0;
  t36_tmp = t25_tmp * t4;
  t36 = t36_tmp * t19 * 8.0;
  t547 = t36_tmp * t5;
  t37 = t547 * 8.0;
  t38_tmp = t25_tmp * t13;
  t38 = t38_tmp * 4.0;
  t42 = ((in2[6] * s * 2.0 + in2[7] * t2 * 3.0) + in2[8] * s * t2 * 4.0) + 1.0;
  t46 = (in2[3] * s * 2.0 + in2[4] * t2 * 3.0) + in2[5] * s * t2 * 4.0;
  t9 = t18;
  st.site = &s_emlrtRSI;
  b_sqrt(&st, &t9);
  t47 = 1.0 / t9;
  t51 = (in2[0] * s * 2.0 + in2[1] * t2 * 3.0) + in2[2] * s * t2 * 4.0;
  t52 = s * t42;
  t53_tmp = t21_tmp * t46;
  t53 = t52 - t53_tmp * t47;
  t54 = s * t46;
  t509 = t21_tmp * t42;
  t56 = t54 + t509 * t47;
  t59 = (t3 * t42 + t19 * t46) - t5 * t51;
  t63 = (t4 * t51 + t19 * t42) - t3 * t46;
  t66 = (in2[9] + in2[10] * s * 2.0) + in2[11] * t2 * 3.0;
  t70 = (in2[12] + in2[13] * s * 2.0) + in2[14] * t2 * 3.0;
  t74 = (in2[15] + in2[16] * s * 2.0) + in2[17] * t2 * 3.0;
  t76 = (t3 * t66 * 2.0 + t4 * t70 * 2.0) + t5 * t74 * 2.0;
  t77 = t102 * 2.0;
  t78 = s * t66 * 2.0;
  t79 = t92 * 2.0;
  t80 = t104 * 2.0;
  t81 = ((t77 + t78) + t79) + t80;
  st.site = &t_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  if (t18 < 0.0) {
    c_st.site = &qb_emlrtRSI;
    error(&c_st);
  }

  t82 = 1.0 / muDoubleScalarPower(t18, 1.5);
  t86 = (t3 * t51 + t4 * t46) + t5 * t42;
  t89 = (t5 * t46 + t19 * t51) - t4 * t42;
  t9 = t2 * t42;
  t91_tmp = t23_tmp * t46;
  t91 = t9 - t91_tmp * t47;
  t92 = t2 * t46;
  t550 = t23_tmp * t42;
  t94 = t92 + t550 * t47;
  t98 = t21_tmp * 4.0;
  t99 = t2 * t66 * 2.0;
  t100 = t98 + t99;
  t102 = t25_tmp * t42;
  t103_tmp = b_t25_tmp * t46;
  t103 = t102 - t103_tmp * t47;
  t104 = t25_tmp * t46;
  t506 = b_t25_tmp * t42;
  t106 = t104 + t506 * t47;
  t108 = t23_tmp * 6.0;
  t109 = t25_tmp * t66 * 2.0;
  t110 = t108 + t109;
  t111 = s * t63;
  t18 = s * t51;
  t113_tmp = t27_tmp * t42;
  t113 = t18 - t113_tmp * t47;
  t115_tmp = t27_tmp * t47;
  t115 = t52 + t115_tmp * t51;
  t116 = s * t86;
  t118 = s * t74 * 2.0;
  t119 = t554 * 2.0;
  t120 = t562 * 2.0;
  t121 = t302 * 2.0;
  t122 = t460 * t76 * t82;
  t124_tmp = s * t70 * 2.0;
  t125_tmp = (t119 + t120) + t121;
  t125 = t125_tmp + t124_tmp;
  t127 = t2 * t63;
  t128 = t2 * t86;
  t52 = t2 * t51;
  t130_tmp = t32_tmp * t42;
  t130 = t52 - t130_tmp * t47;
  t132_tmp = t32_tmp * t47;
  t132 = t9 + t132_tmp * t51;
  t134 = t2 * t74 * 2.0;
  t135 = t27_tmp * 4.0;
  t136 = t467 * t76 * t82;
  t138_tmp = t2 * t70 * 2.0;
  t139 = t135 + t138_tmp;
  t141 = t25_tmp * t63;
  t142 = t25_tmp * t86;
  t9 = t25_tmp * t51;
  t144_tmp = t36_tmp * t42;
  t144 = t9 - t144_tmp * t47;
  t146_tmp = t36_tmp * t47;
  t146 = t102 + t146_tmp * t51;
  t148 = t25_tmp * t74 * 2.0;
  t149 = t32_tmp * 6.0;
  t150 = t469 * t76 * t82;
  t153_tmp = t25_tmp * t70 * 2.0;
  t154 = t149 + t153_tmp;
  t156_tmp = s * t5;
  b_t156_tmp = t156_tmp * t46;
  t156 = t18 + b_t156_tmp * t47;
  t157 = s * t89;
  t158_tmp = t156_tmp * t47;
  t158 = t54 - t158_tmp * t51;
  t160_tmp = t168 * 2.0;
  t161_tmp = t176 * 2.0;
  t162_tmp = t548 * 2.0;
  t163 = t520 * t76 * t82;
  t164 = ((t118 + t160_tmp) + t161_tmp) + t162_tmp;
  t165 = t474 * t76 * t82;
  t54 = t2 * t5;
  t554 = t54 * t46;
  t167 = t52 + t554 * t47;
  t168_tmp = t54 * t47;
  t168 = t92 - t168_tmp * t51;
  t169 = t2 * t89;
  t171_tmp = t156_tmp * 4.0;
  t172 = t524 * t76 * t82;
  t173 = t134 + t171_tmp;
  t174 = t33_tmp * t76 * t82;
  t562 = t25_tmp * t5;
  t548 = t562 * t46;
  t176 = t9 + t548 * t47;
  t177_tmp = t562 * t47;
  t92 = t104 - t177_tmp * t51;
  t178 = t25_tmp * t89;
  t180_tmp = t54 * 6.0;
  t181 = t533 * t76 * t82;
  t182 = t148 + t180_tmp;
  t183 = t547 * t76 * t82;
  t184 = 1.0 / in1[33];
  t9 = muDoubleScalarCos(in1[20]);
  st.site = &u_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t186 = in1[2] * in1[2];
  st.site = &v_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t187 = in1[3] * in1[3];
  st.site = &w_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t190 = in1[18] * in1[18];
  t18 = muDoubleScalarSin(in1[20]);
  st.site = &x_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t192 = 1.0 / (t18 * t18);
  st.site = &y_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  st.site = &ab_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t52 = in1[33] * in1[33];
  t195_tmp = t52 * (t9 * t9);
  st.site = &bb_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  st.site = &cb_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  st.site = &db_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  st.site = &eb_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  st.site = &fb_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  st.site = &gb_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t208 = 1.0 / t52 * (t186 * t186 - t187 * t187) + t190 * t190 * (1.0 /
    muDoubleScalarPower(t18, 4.0)) * ((t195_tmp - 1.0) * (t195_tmp - 1.0)) * 6.0;
  t209 = t208 * 3.1415926535897931 / 4.0;
  st.site = &hb_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t9 = t54 * t19 * 6.0;
  t212 = t23 + t9;
  t213 = t31 - t32;
  t18 = t562 * t19 * 8.0;
  t215 = t25 + t18;
  t216 = t35 - t36;
  t217_tmp = t2 * t17;
  b_t217_tmp = t217_tmp * 3.0;
  t218_tmp = t25_tmp * t17;
  b_t218_tmp = t218_tmp * 4.0;
  t222_tmp = t2 * t59;
  t225 = ((((t19 * t168 + t222_tmp) + t550) + t33_tmp * t42 * t47) - t5 * t167)
    - t168_tmp * t89;
  t227_tmp = t25_tmp * t59;
  t230 = ((((t19 * t92 + t227_tmp) + t506) + t547 * t42 * t47) - t5 * t176) -
    t177_tmp * t89;
  t233_tmp = s * t59;
  t236 = ((((t19 * t158 + t233_tmp) + t509) + t474 * t42 * t47) - t5 * t156) -
    t158_tmp * t89;
  t52 = t156_tmp * t19 * 4.0;
  t238 = t21 + t52;
  t239_tmp = s * t17;
  b_t239_tmp = t239_tmp * 2.0;
  t242_tmp = t21_tmp * t47;
  t242 = ((t116 + t4 * t56) + t5 * t53) - t242_tmp * t89;
  t245_tmp = t23_tmp * t47;
  t245 = ((t128 + t4 * t94) + t5 * t91) - t245_tmp * t89;
  t248_tmp = b_t25_tmp * t47;
  t248 = ((t142 + t4 * t106) + t5 * t103) - t248_tmp * t89;
  t249_tmp = s * t20 * 2.0;
  t250_tmp = -t22 + t30;
  t250 = (t250_tmp + b_t239_tmp) + t249_tmp;
  t255_tmp = t2 * t20 * 3.0;
  t256_tmp = -t24 + t34;
  t256 = (t256_tmp + b_t217_tmp) + t255_tmp;
  t257_tmp = t25_tmp * t20 * 4.0;
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
  d_t268_tmp = t547 * t46 * t47;
  t268 = ((((t141 - t103_tmp) + b_t268_tmp) + t268_tmp) + c_t268_tmp) +
    d_t268_tmp;
  t279_tmp = t4 * t113;
  b_t279_tmp = t19 * t115;
  c_t279_tmp = t115_tmp * t89;
  d_t279_tmp = t474 * t46 * t47;
  t279 = ((((t111 - t53_tmp) + b_t279_tmp) + t279_tmp) + c_t279_tmp) +
    d_t279_tmp;
  t284 = t27 - t28;
  st.site = &ib_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t294 = muDoubleScalarPower(muDoubleScalarAbs(((((((((((((((((t212 * in2[22] +
    t213 * in2[25]) + t215 * in2[23]) + t216 * in2[26]) + t225 * in2[34]) + t230
    * in2[35]) + t236 * in2[33]) + t238 * in2[21]) + t242 * in2[27]) + t245 *
    in2[28]) + t248 * in2[29]) - t256 * in2[19]) - t258 * in2[20]) - t263 * in2
    [31]) - t268 * in2[32]) - t279 * in2[30]) - t284 * in2[24]) - t250 * in2[18]),
    in1[11] - 1.0);
  t302 = t23_tmp * t19 * 6.0;
  t303 = t33 + t302;
  t102 = b_t25_tmp * t19 * 8.0;
  t305 = t37 + t102;
  t309 = ((((t127 + t19 * t91) + t32_tmp * t51) + t524 * t47 * t51) - t3 * t94)
    - t245_tmp * t59;
  t313 = ((((t141 + t19 * t103) + t36_tmp * t51) + t533 * t47 * t51) - t3 * t106)
    - t248_tmp * t59;
  t319 = ((((t111 + t19 * t53) + t27_tmp * t51) + t520 * t47 * t51) - t3 * t56)
    - t242_tmp * t59;
  t104 = t21_tmp * t19 * 4.0;
  t322 = t29 + t104;
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
  d_t351_tmp = t524 * t42 * t47;
  t351 = ((((t169 - t130_tmp) + b_t351_tmp) + t351_tmp) + c_t351_tmp) +
    d_t351_tmp;
  t356_tmp = t5 * t92;
  b_t356_tmp = t19 * t176;
  c_t356_tmp = t177_tmp * t59;
  d_t356_tmp = t533 * t42 * t47;
  t356 = ((((t178 - t144_tmp) + b_t356_tmp) + t356_tmp) + c_t356_tmp) +
    d_t356_tmp;
  t364_tmp = t5 * t158;
  b_t364_tmp = t19 * t156;
  c_t364_tmp = t158_tmp * t59;
  d_t364_tmp = t520 * t42 * t47;
  t364 = ((((t157 - t113_tmp) + b_t364_tmp) + t364_tmp) + c_t364_tmp) +
    d_t364_tmp;
  t382 = t21 - t52;
  st.site = &jb_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t375 = muDoubleScalarPower(muDoubleScalarAbs(((((((((((((((((t333 * in2[19] +
    t303 * in2[25]) + t336 * in2[20]) + t305 * in2[26]) + t309 * in2[28]) + t313
    * in2[29]) + t319 * in2[27]) + t382 * in2[18]) + t322 * in2[24]) + t325 *
    in2[30]) + t328 * in2[31]) + t331 * in2[32]) - t339 * in2[22]) - t340 * in2
    [23]) - t351 * in2[34]) - t356 * in2[35]) - t364 * in2[33]) - t332 * in2[21]),
    in1[11] - 1.0);
  t383 = t31 + t32;
  t384 = t35 + t36;
  t385 = t54 * t51;
  t386 = t562 * t51;
  t390 = ((((t169 + t19 * t130) + t554) + t467 * t46 * t47) - t4 * t132) -
    t132_tmp * t63;
  t394 = ((((t178 + t19 * t144) + t548) + t469 * t46 * t47) - t4 * t146) -
    t146_tmp * t63;
  t395 = t156_tmp * t51;
  t399 = ((((t157 + t19 * t113) + b_t156_tmp) + t460 * t46 * t47) - t4 * t115) -
    t115_tmp * t63;
  t400 = t27 + t28;
  t403 = ((t116 + t3 * t156) + t4 * t158) - t158_tmp * t63;
  t406 = ((t128 + t3 * t167) + t4 * t168) - t168_tmp * t63;
  t409 = ((t142 + t3 * t176) + t4 * t92) - t177_tmp * t63;
  t410 = ((t22 + t30) - b_t239_tmp) + t249_tmp;
  t412 = t33 - t302;
  t415 = t37 - t102;
  t417 = ((t24 + t34) - b_t217_tmp) + t255_tmp;
  t418 = ((t26 + t38) - b_t218_tmp) + t257_tmp;
  t128 = t3 * t91;
  t156 = t19 * t94;
  t31 = t245_tmp * t63;
  b_t156_tmp = t467 * t47 * t51;
  t423 = ((((t222_tmp - t385) + t156) + t128) + t31) + b_t156_tmp;
  t156_tmp = t3 * t103;
  t130 = t19 * t106;
  t144 = t248_tmp * t63;
  t132 = t469 * t47 * t51;
  t428 = ((((t227_tmp - t386) + t130) + t156_tmp) + t144) + t132;
  t302 = t3 * t53;
  t32_tmp = t19 * t56;
  t36_tmp = t242_tmp * t63;
  t23_tmp = t460 * t47 * t51;
  t439 = ((((t233_tmp - t395) + t32_tmp) + t302) + t36_tmp) + t23_tmp;
  t460 = t29 - t104;
  st.site = &kb_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t453 = muDoubleScalarPower(muDoubleScalarAbs(((((((((((((((((t383 * in2[19] +
    t412 * in2[22]) + t384 * in2[20]) + t415 * in2[23]) + t390 * in2[31]) + t394
    * in2[32]) + t399 * in2[30]) + t400 * in2[18]) + t460 * in2[21]) + t403 *
    in2[33]) + t406 * in2[34]) + t409 * in2[35]) - t417 * in2[25]) - t418 * in2
    [26]) - t423 * in2[28]) - t428 * in2[29]) - t439 * in2[27]) - t410 * in2[24]),
    in1[11] - 1.0);
  t463_tmp = t3 * t47;
  t52 = s * t19 * 4.0 + t2 * t47 * t76;
  t103 = ((t52 + t463_tmp * t100) + t24_tmp * t76 * t82) - t245_tmp * t66 * 2.0;
  t106 = (((-t148 + t150) + t180_tmp) + t463_tmp * t154) - t146_tmp * t66 * 2.0;
  t467 = (((-t149 + t153_tmp) + t181) + t463_tmp * t182) - t177_tmp * t66 * 2.0;
  t469 = (((-t134 + t136) + t171_tmp) + t463_tmp * t139) - t132_tmp * t66 * 2.0;
  t53 = (((-t135 + t138_tmp) + t172) + t463_tmp * t173) - t168_tmp * t66 * 2.0;
  t56 = (((((-t118 + t122) + t160_tmp) + t161_tmp) + t162_tmp) + t463_tmp * t125)
    - t115_tmp * t66 * 2.0;
  t474 = t463_tmp * t164;
  t54 = t2 * t19 * 6.0 + t25_tmp * t47 * t76;
  t94 = ((t54 + t463_tmp * t110) + t26_tmp * t76 * t82) - t248_tmp * t66 * 2.0;
  t20 = t19 * 2.0 + s * t47 * t76;
  t142 = ((t20 + t463_tmp * t81) + t22_tmp * t76 * t82) - t242_tmp * t66 * 2.0;
  t33_tmp = t158_tmp * t66 * 2.0;
  t27_tmp = t125_tmp - t124_tmp;
  t113 = ((t27_tmp - t163) - t474) + t33_tmp;
  st.site = &lb_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t116 = muDoubleScalarPower(muDoubleScalarAbs((((((((t103 * in2[28] + t106 *
    in2[32]) + t467 * in2[35]) + t469 * in2[31]) + t53 * in2[34]) + t56 * in2[30])
    + t94 * in2[29]) + t142 * in2[27]) - t113 * in2[33]), in1[11] - 1.0);
  t91 = t4 * t47;
  t32 = ((t52 + t91 * t139) + t34_tmp * t76 * t82) - t132_tmp * t70 * 2.0;
  t506 = t91 * t110;
  t35 = (((t108 - t109) + t183) + t91 * t182) - t177_tmp * t70 * 2.0;
  t509 = t91 * t100;
  t36 = (((t98 - t99) + t174) + t91 * t173) - t168_tmp * t70 * 2.0;
  t17 = t91 * t81;
  t21_tmp = ((t77 - t78) + t79) + t80;
  t115 = ((t21_tmp + t165) + t91 * t164) - t158_tmp * t70 * 2.0;
  t158 = ((t54 + t91 * t154) + t38_tmp * t76 * t82) - t146_tmp * t70 * 2.0;
  t520 = ((t20 + t91 * t125) + t30_tmp * t76 * t82) - t115_tmp * t70 * 2.0;
  t92 = t134 + t136;
  t104 = t245_tmp * t70 * 2.0;
  t146 = ((t92 - t171_tmp) + t509) - t104;
  t9 = t148 + t150;
  t18 = t248_tmp * t70 * 2.0;
  t524 = ((t9 - t180_tmp) + t506) - t18;
  t562 = t242_tmp * t70 * 2.0;
  t533 = (((((-t118 - t122) + t160_tmp) + t161_tmp) + t162_tmp) - t17) + t562;
  st.site = &mb_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t167 = muDoubleScalarPower(muDoubleScalarAbs((((((((t32 * in2[31] + t524 *
    in2[29]) + t35 * in2[35]) + t146 * in2[28]) + t36 * in2[34]) + t115 * in2[33])
    + t158 * in2[32]) + t520 * in2[30]) - t533 * in2[27]), in1[11] - 1.0);
  b_t25_tmp = t5 * t47;
  t547 = ((t52 + b_t25_tmp * t173) + t217_tmp * t76 * t82) - t168_tmp * t74 *
    2.0;
  t548 = b_t25_tmp * t110;
  t550 = (((-t108 + t109) + t183) + b_t25_tmp * t154) - t146_tmp * t74 * 2.0;
  t52 = b_t25_tmp * t100;
  t176 = (((-t98 + t99) + t174) + b_t25_tmp * t139) - t132_tmp * t74 * 2.0;
  t554 = b_t25_tmp * t81;
  t102 = b_t25_tmp * t125;
  t168 = ((t54 + b_t25_tmp * t182) + t218_tmp * t76 * t82) - t177_tmp * t74 *
    2.0;
  t54 = ((t20 + b_t25_tmp * t164) + t239_tmp * t76 * t82) - t158_tmp * t74 * 2.0;
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
  out1[45] = ((((t395 - t233_tmp) - t302) - t32_tmp) - t36_tmp) - t23_tmp;
  out1[46] = ((((t385 - t222_tmp) - t128) - t156) - t31) - b_t156_tmp;
  out1[47] = ((((t386 - t156_tmp) - t130) - t227_tmp) - t144) - t132;
  out1[48] = t399;
  out1[49] = t390;
  out1[50] = t394;
  out1[51] = t403;
  out1[52] = t406;
  out1[53] = t409;
  memset(&out1[54], 0, 9U * sizeof(real_T));
  out1[63] = t142;
  out1[64] = t103;
  out1[65] = t94;
  out1[66] = t56;
  out1[67] = t469;
  out1[68] = t106;
  out1[69] = (((((-t119 - t120) - t121) + t124_tmp) + t163) + t474) - t33_tmp;
  out1[70] = t53;
  out1[71] = t467;
  memset(&out1[72], 0, 9U * sizeof(real_T));
  out1[81] = (((((t118 + t122) + t17) - t160_tmp) - t161_tmp) - t162_tmp) - t562;
  out1[82] = ((t92 + t509) - t171_tmp) - t104;
  out1[83] = ((t9 + t506) - t180_tmp) - t18;
  out1[84] = t520;
  out1[85] = t32;
  out1[86] = t158;
  out1[87] = t115;
  out1[88] = t36;
  out1[89] = t35;
  memset(&out1[90], 0, 9U * sizeof(real_T));
  t92 = t242_tmp * t74 * 2.0;
  out1[99] = (((t125_tmp + t163) + t554) - t124_tmp) - t92;
  t9 = t245_tmp * t74 * 2.0;
  out1[100] = (((t135 + t172) + t52) - t138_tmp) - t9;
  t18 = t248_tmp * t74 * 2.0;
  out1[101] = (((t149 + t181) + t548) - t153_tmp) - t18;
  t302 = t115_tmp * t74 * 2.0;
  out1[102] = (((((-t77 + t78) - t79) - t80) + t165) + t102) - t302;
  out1[103] = t176;
  out1[104] = t550;
  out1[105] = t54;
  out1[106] = t547;
  out1[107] = t168;
  t562 = (((t135 - t138_tmp) + t172) + t52) - t9;
  t52 = (((t149 - t153_tmp) + t181) + t548) - t18;
  t18 = ((t27_tmp + t163) + t554) - t92;
  t92 = ((t21_tmp - t165) - t102) + t302;
  st.site = &nb_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  t104 = muDoubleScalarPower(muDoubleScalarAbs((((((((t547 * in2[34] + t52 *
    in2[29]) + t550 * in2[32]) + t562 * in2[28]) + t176 * in2[31]) + t18 * in2
    [27]) + t168 * in2[35]) + t54 * in2[33]) - t92 * in2[30]), in1[11] - 1.0);
  t9 = in1[33];
  st.site = &ob_emlrtRSI;
  b_sqrt(&st, &t9);
  t554 = 1.0 / t9;
  t102 = in1[1] * t184;
  t9 = t102 * (t184 * (t186 - t187) - t190 * t192 * (t195_tmp - 1.0) * 6.0) *
    3.1415926535897931;
  out2[0] = t9 * (((t5 * t59 - t4 * t63) + t3 * t86) + t19 * t89) / 3.0;
  out2[1] = t9 * (((t3 * t63 + t19 * t59) + t4 * t86) - t5 * t89) / 3.0;
  out2[2] = t9 * ((((-t3 * t59 + t19 * t63) + t5 * t86) + t4 * t89) - 1.0);
  t9 = t184 * t190 * t192 * (t195_tmp - 1.0) * (in1[19] * in1[19]) *
    3.1415926535897931;
  out2[3] = t102 * (t209 - t9 * 3.0) * (((t5 * t70 * 2.0 - t4 * t74 * 2.0) + t19
    * t66 * 2.0) + t463_tmp * t76);
  out2[4] = t102 * (t209 - t9 * 2.9999999999999991) * (((t5 * t66 * -2.0 + t3 *
    t74 * 2.0) + t19 * t70 * 2.0) + t91 * t76);
  out2[5] = t102 * t208 * 3.1415926535897931 * (((t4 * t66 * 2.0 - t3 * t70 *
    2.0) + t19 * t74 * 2.0) + b_t25_tmp * t76) / 6.0;
  out3[0] = ((((((((((((((((-in1[5] * t212 * t294 * in2[22] - in1[5] * t213 *
    t294 * in2[25]) - in1[5] * t215 * t294 * in2[23]) - in1[5] * t216 * t294 *
    in2[26]) - in1[5] * t225 * t294 * in2[34]) - in1[5] * t238 * t294 * in2[21])
                       - in1[5] * t230 * t294 * in2[35]) + in1[5] * t250 * t294 *
                      in2[18]) - in1[5] * t236 * t294 * in2[33]) - in1[5] * t242
                    * t294 * in2[27]) - in1[5] * t245 * t294 * in2[28]) + in1[5]
                  * t256 * t294 * in2[19]) - in1[5] * t248 * t294 * in2[29]) +
                in1[5] * t258 * t294 * in2[20]) + in1[5] * t263 * t294 * in2[31])
              + in1[5] * t268 * t294 * in2[32]) + in1[5] * t284 * t294 * in2[24])
    + in1[5] * t279 * t294 * in2[30];
  out3[1] = ((((((((((((((((-in1[6] * t303 * t375 * in2[25] - in1[6] * t305 *
    t375 * in2[26]) - in1[6] * t309 * t375 * in2[28]) - in1[6] * t313 * t375 *
    in2[29]) - in1[6] * t319 * t375 * in2[27]) - in1[6] * t322 * t375 * in2[24])
                       - in1[6] * t333 * t375 * in2[19]) + in1[6] * t332 * t375 *
                      in2[21]) - in1[6] * t325 * t375 * in2[30]) - in1[6] * t336
                    * t375 * in2[20]) - in1[6] * t328 * t375 * in2[31]) + in1[6]
                  * t339 * t375 * in2[22]) - in1[6] * t331 * t375 * in2[32]) +
                in1[6] * t340 * t375 * in2[23]) + in1[6] * t351 * t375 * in2[34])
              + in1[6] * t356 * t375 * in2[35]) + in1[6] * t364 * t375 * in2[33])
    - in1[6] * t375 * t382 * in2[18];
  out3[2] = ((((((((((((((((-in1[7] * t383 * t453 * in2[19] - in1[7] * t384 *
    t453 * in2[20]) - in1[7] * t400 * t453 * in2[18]) - in1[7] * t390 * t453 *
    in2[31]) - in1[7] * t394 * t453 * in2[32]) - in1[7] * t399 * t453 * in2[30])
                       + in1[7] * t410 * t453 * in2[24]) - in1[7] * t412 * t453 *
                      in2[22]) - in1[7] * t403 * t453 * in2[33]) - in1[7] * t415
                    * t453 * in2[23]) - in1[7] * t406 * t453 * in2[34]) + in1[7]
                  * t417 * t453 * in2[25]) - in1[7] * t409 * t453 * in2[35]) +
                in1[7] * t418 * t453 * in2[26]) + in1[7] * t423 * t453 * in2[28])
              + in1[7] * t428 * t453 * in2[29]) + in1[7] * t439 * t453 * in2[27])
    - in1[7] * t453 * t460 * in2[21];
  out3[3] = (((((((-in1[8] * t103 * t116 * in2[28] - in1[8] * t106 * t116 * in2
                   [32]) - in1[8] * t469 * t116 * in2[31]) - in1[8] * t467 *
                 t116 * in2[35]) - in1[8] * t56 * t116 * in2[30]) - in1[8] * t53
               * t116 * in2[34]) - in1[8] * t94 * t116 * in2[29]) - in1[8] *
             t142 * t116 * in2[27]) + in1[8] * t113 * t116 * in2[33];
  out3[4] = (((((((-in1[9] * t32 * t167 * in2[31] - in1[9] * t35 * t167 * in2[35])
                  - in1[9] * t36 * t167 * in2[34]) - in1[9] * t115 * t167 * in2
                 [33]) - in1[9] * t158 * t167 * in2[32]) - in1[9] * t146 * t167 *
               in2[28]) - in1[9] * t520 * t167 * in2[30]) - in1[9] * t524 * t167
             * in2[29]) + in1[9] * t533 * t167 * in2[27];
  out3[5] = (((((((-in1[10] * t547 * t104 * in2[34] - in1[10] * t550 * t104 *
                   in2[32]) - in1[10] * t176 * t104 * in2[31]) - in1[10] * t562 *
                 t104 * in2[28]) - in1[10] * t168 * t104 * in2[35]) - in1[10] *
               t54 * t104 * in2[33]) - in1[10] * t52 * t104 * in2[29]) - in1[10]
             * t18 * t104 * in2[27]) + in1[10] * t92 * t104 * in2[30];
  out4[0] = 0.0;
  out4[1] = 0.0;
  out4[2] = -t190 * t192 * (t195_tmp - 1.0) * 3.1415926535897931 * (((((in1[21]
    + in1[22]) + in1[23]) + in1[24]) + in1[25]) + in1[26]);
  t102 = in1[21] * in1[19] * t190 * t192 * (t195_tmp - 1.0) * t554 *
    3.1415926535897931;
  t92 = in1[22] * in1[19] * t190 * t192 * (t195_tmp - 1.0) * t554 *
    3.1415926535897931;
  t104 = in1[23] * in1[19] * t190 * t192 * (t195_tmp - 1.0) * t554 *
    3.1415926535897931;
  t18 = in1[24] * in1[19] * t190 * t192 * (t195_tmp - 1.0) * t554 *
    3.1415926535897931;
  t52 = in1[25] * in1[19] * t190 * t192 * (t195_tmp - 1.0) * t554 *
    3.1415926535897931;
  t9 = in1[26] * in1[19] * t190 * t192 * (t195_tmp - 1.0) * t554 *
    3.1415926535897931;
  out4[3] = ((((t102 * -0.91522491349480972 - t92 * 0.91522491349480972) + t104 *
               0.1086532638769295) + t18 * 0.80657164961788008) + t52 *
             0.80657164961787986) + t9 * 0.1086532638769295;
  out4[4] = ((((t102 * -0.40294336787992679 + t92 * 0.40294336787992691) + t104 *
               0.99407970920288391) + t18 * 0.59113634132295712) - t52 *
             0.59113634132295745) - t9 * 0.99407970920288391;
  out4[5] = 0.0;
  out5[0] = t51;
  out5[1] = t46;
  out5[2] = t42;
}

/* End of code generation (sprdmpF19.c) */
