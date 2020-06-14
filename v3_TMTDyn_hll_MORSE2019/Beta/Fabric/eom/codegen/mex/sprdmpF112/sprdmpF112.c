/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sprdmpF112.c
 *
 * Code generation for function 'sprdmpF112'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "sprdmpF112.h"
#include "sqrt.h"
#include "error.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 41,    /* lineNo */
  "sprdmpF112",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF112.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 42,  /* lineNo */
  "sprdmpF112",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF112.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 43,  /* lineNo */
  "sprdmpF112",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF112.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 44,  /* lineNo */
  "sprdmpF112",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF112.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 54,  /* lineNo */
  "sprdmpF112",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF112.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 55,  /* lineNo */
  "sprdmpF112",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF112.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 56,  /* lineNo */
  "sprdmpF112",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF112.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 57,  /* lineNo */
  "sprdmpF112",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF112.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 59,  /* lineNo */
  "sprdmpF112",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF112.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 60,  /* lineNo */
  "sprdmpF112",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF112.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 61,  /* lineNo */
  "sprdmpF112",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF112.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 79,  /* lineNo */
  "sprdmpF112",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF112.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 124, /* lineNo */
  "sprdmpF112",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF112.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 196, /* lineNo */
  "sprdmpF112",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF112.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 197, /* lineNo */
  "sprdmpF112",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF112.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 247, /* lineNo */
  "sprdmpF112",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF112.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 293, /* lineNo */
  "sprdmpF112",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF112.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 337, /* lineNo */
  "sprdmpF112",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF112.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 389, /* lineNo */
  "sprdmpF112",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF112.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 436, /* lineNo */
  "sprdmpF112",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF112.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 481, /* lineNo */
  "sprdmpF112",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF112.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 494, /* lineNo */
  "sprdmpF112",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF112.m"/* pathName */
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
void sprdmpF112(const emlrtStack *sp, const real_T in1[6], const real_T in2[224],
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
  real_T t399;
  real_T t28;
  real_T t29;
  real_T t31;
  real_T t32_tmp;
  real_T t32;
  real_T t400;
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
  real_T t408;
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
  real_T t407;
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
  real_T t406;
  real_T t141;
  real_T t142;
  real_T t144;
  real_T t145;
  real_T t147;
  real_T t149;
  real_T t150;
  real_T t153;
  real_T t156;
  real_T t157;
  real_T t158;
  real_T t160;
  real_T t161;
  real_T t162;
  real_T t163_tmp;
  real_T t164;
  real_T t165;
  real_T t166;
  real_T t167;
  real_T t168;
  real_T t169;
  real_T t170;
  real_T t175_tmp;
  real_T t176_tmp;
  real_T b_t176_tmp;
  real_T c_t176_tmp;
  real_T d_t176_tmp;
  real_T t176;
  real_T t182_tmp;
  real_T b_t182_tmp;
  real_T c_t182_tmp;
  real_T d_t182_tmp;
  real_T t182;
  real_T t188_tmp;
  real_T t189_tmp;
  real_T t191_tmp;
  real_T b_t191_tmp;
  real_T c_t191_tmp;
  real_T d_t191_tmp;
  real_T e_t191_tmp;
  real_T t191;
  real_T t196_tmp;
  real_T t197_tmp;
  real_T b_t197_tmp;
  real_T c_t197_tmp;
  real_T t197;
  real_T t205;
  real_T t209;
  real_T t210;
  real_T t211;
  real_T t212;
  real_T t213;
  real_T t214;
  real_T t215;
  real_T t216;
  real_T t217;
  real_T t218;
  real_T t219;
  real_T t223_tmp;
  real_T t225_tmp;
  real_T b_t225_tmp;
  real_T c_t225_tmp;
  real_T d_t225_tmp;
  real_T t225;
  real_T t230_tmp;
  real_T b_t230_tmp;
  real_T c_t230_tmp;
  real_T t230;
  real_T t236_tmp;
  real_T b_t236_tmp;
  real_T c_t236_tmp;
  real_T d_t236_tmp;
  real_T t236;
  real_T t243_tmp;
  real_T t244_tmp;
  real_T b_t244_tmp;
  real_T c_t244_tmp;
  real_T d_t244_tmp;
  real_T e_t244_tmp;
  real_T t244;
  real_T t251;
  real_T t255;
  real_T t256;
  real_T t257;
  real_T t258;
  real_T t259;
  real_T t260;
  real_T t261;
  real_T t262;
  real_T t263;
  real_T t264;
  real_T t265;
  real_T t270_tmp;
  real_T b_t270_tmp;
  real_T c_t270_tmp;
  real_T d_t270_tmp;
  real_T t270;
  real_T t277_tmp;
  real_T b_t277_tmp;
  real_T t277;
  real_T t282;
  real_T t412;
  real_T t288_tmp;
  real_T b_t288_tmp;
  real_T c_t288_tmp;
  real_T t288;
  real_T t295;
  real_T t302;
  real_T t304_tmp;
  real_T t309;
  real_T t310_tmp;
  real_T t316;
  real_T t321_tmp;
  real_T t432;
  real_T t436;
  real_T t325;
  real_T t328_tmp;
  real_T t428;
  real_T t427;
  real_T t330_tmp;
  real_T t330;
  real_T t335_tmp;
  real_T b_t335_tmp;
  real_T t335;
  real_T t336;
  real_T t341_tmp;
  real_T t343_tmp;
  real_T b_t343_tmp;
  real_T t343;
  real_T t346;
  real_T t354;
  real_T t355;
  real_T t359;
  real_T t360;
  real_T t362;
  real_T t363;
  real_T t389_tmp;
  real_T t367;
  real_T t374;
  real_T t380;
  real_T t383;
  real_T t386;
  real_T t387;
  real_T t393;
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

  /* SPRDMPF112 */
  /*     [OUT1,OUT2,OUT3,OUT4,OUT5,OUT6,OUT7,OUT8] = SPRDMPF112(IN1,IN2,S) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.2. */
  /*     06-Jul-2019 06:48:21 */
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
  t15 = in2[17] * in2[17];
  st.site = &f_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t16 = in2[18] * in2[18];
  st.site = &g_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t17 = in2[19] * in2[19];
  st.site = &h_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t18 = in2[20] * in2[20];
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
  t27_tmp = in2[17] * in2[18];
  t27 = t27_tmp * in2[83] * t20 * t21 * 2.0;
  t399 = in2[17] * in2[19];
  t28 = t399 * in2[81] * t20 * t21 * 2.0;
  t29 = t22 - t17 * t20;
  t31 = t22 - t18 * t20;
  t32_tmp = in2[17] * in2[20];
  t32 = t32_tmp * in2[82] * t20 * t21 * 2.0;
  t400 = in2[18] * in2[20];
  t34 = t400 * in2[82] * t20 * t21 * 2.0;
  t35 = t5 * t7;
  t15 = in2[80] * in2[83];
  t36_tmp = t15 * t7 * 2.0;
  t19 = in2[80] * in2[81];
  t37_tmp = t19 * t7 * 2.0;
  t38 = in2[14] - in2[77];
  t39 = in2[15] - in2[78];
  st.site = &l_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  if (t6 < 0.0) {
    c_st.site = &x_emlrtRSI;
    error(&c_st);
  }

  t40 = 1.0 / muDoubleScalarPower(t6, 1.5);
  t41 = in2[16] - in2[79];
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
  t408 = t58 * t40;
  t55 = t408 * t41;
  t76 = t15 * t39 * t40;
  t56 = ((t54 + t55) - t2 * t38 * t40) - t76;
  t19 = t19 * t38 * t40;
  t58 = t58 * t39 * t40;
  t59_tmp = t15 * t40;
  t59 = t59_tmp * t41;
  t60 = (t19 + t58) + t59;
  t64 = (c_t44_tmp * t38 + t44_tmp * t41) - t47_tmp * t39;
  t68 = (t47_tmp * t38 + c_t44_tmp * t39) + b_t44_tmp * t41;
  t78 = in2[18] * t22 - t47_tmp;
  t80 = in2[19] * t22 - c_t44_tmp;
  t82 = t21 - t53_tmp;
  st.site = &m_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t83 = 1.0 / (t6 * t6);
  t85 = in2[17] * t22 - t44_tmp;
  t88 = in2[20] * t22 - b_t44_tmp;
  t92 = t21 * t64;
  t18 = t120 * t38 * t40;
  t94 = ((t48 + t16) + t18) - t3 * t39 * t40;
  t15 = t120 * t39 * t40;
  t407 = t102 * t40;
  t6 = t407 * t41;
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
  t126 = t408 * t64;
  t127 = t107_tmp * t85 * 2.0;
  t128 = t21 - t119_tmp;
  t129 = t107_tmp * t88 * 2.0;
  t130 = t21 * t78 * 2.0;
  t132 = t408 * t88 * 2.0;
  t133 = t59_tmp * t44;
  t18 = ((t54 + t76) + t6) - t5 * t38 * t40;
  t16 = ((t48 - t49) + t19) - t5 * t39 * t40;
  t406 = t5 * t40;
  t17 = ((-t51 + t99) + t17) + t406 * t41;
  t15 += t59 - t22;
  t141 = t116_tmp * t44;
  t142 = t407 * t85 * 2.0;
  t6 = t59_tmp * t78 * 2.0;
  t144 = t21 - t406;
  t145 = t116_tmp * t85 * 2.0;
  t147 = t116_tmp * t78 * 2.0;
  t19 = in1[4] / 2.0;
  t149 = muDoubleScalarCos(t19);
  t150 = muDoubleScalarSin(t19);
  t153 = t149 / 4.0 + t150 * 0.036;
  t156 = t149 * 0.036 - t150 / 4.0;
  st.site = &n_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t157 = t149 * t149;
  st.site = &o_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t158 = t150 * t150;
  t58 = t44_tmp * t56;
  t160 = b_t44_tmp * t50;
  t161 = c_t44_tmp * t94;
  t162 = b_t44_tmp * t100;
  t163_tmp = t407 * t47;
  t164 = t119_tmp * t64;
  t165 = t44_tmp * t16;
  t166 = c_t44_tmp * t15;
  t167 = t116_tmp * t64;
  t168 = t8 + t36_tmp;
  t169 = t11 - t12;
  t170 = ((t9 + t10) - t14) - t35;
  t175_tmp = t59_tmp * t47;
  t176_tmp = c_t44_tmp * t53;
  b_t176_tmp = t47_tmp * t60;
  c_t176_tmp = t53_tmp * t44;
  d_t176_tmp = t74_tmp * t68;
  t176 = (((((((-t122 - t126) - t58) - t160) + t176_tmp) + b_t176_tmp) +
           c_t176_tmp) + d_t176_tmp) + t175_tmp;
  t182_tmp = t47_tmp * t98;
  b_t182_tmp = t44_tmp * t102;
  c_t182_tmp = t100_tmp * t68;
  d_t182_tmp = t74_tmp * t44;
  t182 = (((((((-t113 - t121) - t161) - t162) + t163_tmp) + t182_tmp) +
           b_t182_tmp) + c_t182_tmp) + d_t182_tmp;
  t188_tmp = t408 * t44;
  t189_tmp = t107_tmp * t68;
  t191_tmp = c_t44_tmp * t55;
  b_t191_tmp = t47_tmp * t117;
  c_t191_tmp = t44_tmp * t72;
  d_t191_tmp = b_t44_tmp * t120;
  e_t191_tmp = t116_tmp * t47;
  t191 = (((((((t92 - t164) + t191_tmp) + c_t191_tmp) + b_t191_tmp) + d_t191_tmp)
           + t188_tmp) + t189_tmp) + e_t191_tmp;
  t196_tmp = t407 * t68;
  t197_tmp = b_t44_tmp * t18;
  b_t197_tmp = t47_tmp * t17;
  c_t197_tmp = t406 * t47;
  t197 = (((((((-t104 + t133) - t165) - t166) - t167) + t197_tmp) + b_t197_tmp)
          + c_t197_tmp) + t196_tmp;
  st.site = &p_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t205 = muDoubleScalarPower(muDoubleScalarAbs(((((((((t176 * in2[192] + t182 *
    in2[193]) + t191 * in2[194]) + t197 * in2[195]) + t169 * in2[128]) + t168 *
    in2[190]) + t170 * in2[189]) - t168 * in2[127]) - t169 * in2[191]) - t170 *
    in2[126]), in1[1] - 1.0);
  t209 = t44_tmp * t50;
  t210 = t47_tmp * t53;
  t211 = t44_tmp * t100;
  t212 = b_t44_tmp * t102;
  t213 = t407 * t44;
  t214 = t47_tmp * t55;
  t215 = b_t44_tmp * t72;
  t216 = t406 * t44;
  t217 = -t8 + t36_tmp;
  t218 = t13 + t37_tmp;
  t19 = t9 - t10;
  t219 = (t19 + t14) - t35;
  t223_tmp = t74_tmp * t64;
  t225_tmp = b_t44_tmp * t56;
  b_t225_tmp = c_t44_tmp * t60;
  c_t225_tmp = t53_tmp * t47;
  d_t225_tmp = t408 * t68;
  t225 = (((((((-t104 - t133) - t209) - t210) + t225_tmp) + b_t225_tmp) +
           c_t225_tmp) + t223_tmp) + d_t225_tmp;
  t230_tmp = t47_tmp * t94;
  b_t230_tmp = c_t44_tmp * t98;
  c_t230_tmp = t100_tmp * t64;
  t230 = (((((((-t92 + t103) + t189_tmp) - t211) - t212) - t213) + t230_tmp) +
          b_t230_tmp) + c_t230_tmp;
  t236_tmp = c_t44_tmp * t117;
  b_t236_tmp = t44_tmp * t120;
  c_t236_tmp = t119_tmp * t68;
  d_t236_tmp = t408 * t47;
  t236 = (((((((-t113 + t121) - t141) - t214) - t215) + t236_tmp) + b_t236_tmp)
          + c_t236_tmp) + d_t236_tmp;
  t243_tmp = t116_tmp * t68;
  t244_tmp = t44_tmp * t18;
  b_t244_tmp = b_t44_tmp * t16;
  c_t244_tmp = t47_tmp * t15;
  d_t244_tmp = c_t44_tmp * t17;
  e_t244_tmp = t407 * t64;
  t244 = (((((((t122 + t175_tmp) - t216) + t244_tmp) + b_t244_tmp) + d_t244_tmp)
           + c_t244_tmp) + e_t244_tmp) + t243_tmp;
  st.site = &q_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t251 = muDoubleScalarPower(muDoubleScalarAbs(((((((((t225 * in2[192] + t230 *
    in2[193]) + t236 * in2[194]) + t244 * in2[195]) + t217 * in2[126]) + t218 *
    in2[191]) + t219 * in2[190]) - t218 * in2[128]) - t217 * in2[189]) - t219 *
    in2[127]), in1[1] - 1.0);
  t255 = t44_tmp * t53;
  t256 = c_t44_tmp * t56;
  t257 = t100_tmp * t47;
  t258 = t44_tmp * t55;
  t259 = t47_tmp * t120;
  t260 = t107_tmp * t47;
  t261 = t47_tmp * t18;
  t262 = c_t44_tmp * t16;
  t263 = t11 + t12;
  t264 = -t13 + t37_tmp;
  t265 = (t19 - t14) + t35;
  t270_tmp = t47_tmp * t50;
  b_t270_tmp = b_t44_tmp * t60;
  c_t270_tmp = t53_tmp * t64;
  d_t270_tmp = t59_tmp * t68;
  t270 = (((((((-t92 - t103) + t188_tmp) - t255) - t256) + t270_tmp) +
           b_t270_tmp) + c_t270_tmp) + d_t270_tmp;
  t277_tmp = t44_tmp * t94;
  b_t277_tmp = t47_tmp * t100;
  t50 = b_t44_tmp * t98;
  t94 = c_t44_tmp * t102;
  t100 = t107_tmp * t44;
  t277 = (((((((t104 + t196_tmp) + t223_tmp) - t257) + t277_tmp) + t50) +
           b_t277_tmp) + t94) + t100;
  t102 = b_t44_tmp * t117;
  t120 = c_t44_tmp * t72;
  t60 = t119_tmp * t44;
  t282 = (((((((-t122 + t126) + t243_tmp) - t258) - t259) - t260) + t120) + t102)
    + t60;
  t412 = t44_tmp * t15;
  t288_tmp = b_t44_tmp * t17;
  b_t288_tmp = t406 * t68;
  c_t288_tmp = t59_tmp * t64;
  t288 = (((((((-t113 + t141) - t163_tmp) - t261) - t262) + t288_tmp) + t412) +
          b_t288_tmp) + c_t288_tmp;
  st.site = &r_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t295 = muDoubleScalarPower(muDoubleScalarAbs(((((((((t270 * in2[192] + t277 *
    in2[193]) + t282 * in2[194]) + t288 * in2[195]) + t264 * in2[127]) + t263 *
    in2[189]) + t265 * in2[191]) - t263 * in2[126]) - t264 * in2[190]) - t265 *
    in2[128]), in1[1] - 1.0);
  t13_tmp = t59_tmp * t80 * 2.0;
  t302 = (((((t130 + t132) + t47_tmp * t82 * 2.0) + in2[81] * t2 * t83 * 2.0) +
           t74_tmp * t85 * 2.0) - t53_tmp * t78 * 2.0) - t13_tmp;
  t99 = t100_tmp * t85 * 2.0;
  t304_tmp = t407 * t80 * 2.0;
  t54 = t119_tmp * t88 * 2.0;
  t309 = (((((t111 + t142) - t6) + c_t44_tmp * t144 * 2.0) + in2[82] * t5 * t83 *
           2.0) + t116_tmp * t88 * 2.0) - t406 * t80 * 2.0;
  t310_tmp = t399 * in2[83] * t20 * t21 * 2.0;
  t76 = t44_tmp * t25 * 2.0;
  t48 = t27_tmp * in2[81] * t20 * t21 * 2.0;
  t117 = in2[18] * in2[19];
  t49 = t117 * in2[83] * t20 * t21 * 2.0;
  t59 = t117 * in2[80] * t20 * t21 * 2.0;
  t19 = in2[19] * in2[20];
  t316 = ((t28 + b_t44_tmp * t29 * 2.0) + t19 * in2[82] * t20 * t21 * 2.0) - t59;
  t40 = t32_tmp * in2[81] * t20 * t21 * 2.0;
  t321_tmp = t21 * t85 * 2.0;
  t51 = in2[80] * t3 * t83 * 2.0;
  t432 = t44_tmp * t109 * 2.0;
  t436 = t74_tmp * t78 * 2.0;
  t325 = (((((-t129 - t99) + t304_tmp) + t321_tmp) + t432) + t51) + t436;
  t328_tmp = t408 * t78 * 2.0;
  t428 = in2[83] * t4 * t83 * 2.0;
  t427 = b_t44_tmp * t128 * 2.0;
  t330_tmp = t116_tmp * t80 * 2.0;
  t330 = (((((t108 - t127) - t54) + t427) + t428) + t328_tmp) + t330_tmp;
  t335_tmp = t47_tmp * t23 * 2.0;
  b_t335_tmp = t27_tmp * in2[80] * t20 * t21 * 2.0;
  t335 = ((-t32 + t310_tmp) + t335_tmp) + b_t335_tmp;
  t336 = ((t34 + t76) + t48) - t49;
  t341_tmp = t400 * in2[80] * t20 * t21 * 2.0;
  t343_tmp = c_t44_tmp * t31 * 2.0;
  b_t343_tmp = t19 * in2[83] * t20 * t21 * 2.0;
  t343 = ((-t40 + t343_tmp) + t341_tmp) + b_t343_tmp;
  st.site = &s_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t346 = muDoubleScalarPower(muDoubleScalarAbs(((((((t302 * in2[192] + t309 *
    in2[195]) + t336 * in2[130]) + t316 * in2[131]) - t325 * in2[193]) - t330 *
    in2[194]) - t335 * in2[129]) - t343 * in2[132]), in1[1] - 1.0);
  t98 = t74_tmp * t88 * 2.0;
  t354 = (((((t111 + t6) + c_t44_tmp * t82 * 2.0) + in2[82] * t2 * t83 * 2.0) +
           t408 * t85 * 2.0) - t53_tmp * t80 * 2.0) - t98;
  t355 = t119_tmp * t85 * 2.0;
  t359 = (((((t108 - t110) + t127) + b_t44_tmp * t109 * 2.0) + in2[83] * t3 *
           t83 * 2.0) + t407 * t78 * 2.0) - t100_tmp * t88 * 2.0;
  t360 = t406 * t78 * 2.0;
  t116_tmp = t27_tmp * in2[82] * t20 * t21 * 2.0;
  t362 = t44_tmp * t29 * 2.0;
  t363 = t399 * in2[82] * t20 * t21 * 2.0;
  t6 = t19 * in2[81] * t20 * t21 * 2.0;
  t389_tmp = t19 * in2[80] * t20 * t21 * 2.0;
  t367 = ((t32 + t47_tmp * t31 * 2.0) + t400 * in2[83] * t20 * t21 * 2.0) -
    t389_tmp;
  t74_tmp = in2[80] * t4 * t83 * 2.0;
  t27_tmp = t44_tmp * t128 * 2.0;
  t22 = t408 * t80 * 2.0;
  t374 = (((((t129 - t147) + t321_tmp) - t355) + t27_tmp) + t74_tmp) + t22;
  t55 = in2[81] * t5 * t83 * 2.0;
  t72 = t47_tmp * t144 * 2.0;
  t17 = t407 * t88 * 2.0;
  t380 = (((((t130 - t145) + t13_tmp) - t360) + t72) + t55) + t17;
  t18 = c_t44_tmp * t23 * 2.0;
  t15 = t399 * in2[80] * t20 * t21 * 2.0;
  t383 = ((-t27 + t40) + t18) + t15;
  t16 = b_t44_tmp * t25 * 2.0;
  t19 = t400 * in2[81] * t20 * t21 * 2.0;
  t386 = ((t59 - t116_tmp) + t16) + t19;
  t387 = ((t49 + t362) + t363) - t6;
  st.site = &t_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t393 = muDoubleScalarPower(muDoubleScalarAbs(((((((t354 * in2[192] + t359 *
    in2[193]) + t387 * in2[131]) + t367 * in2[132]) - t374 * in2[194]) - t380 *
    in2[195]) - t383 * in2[129]) - t386 * in2[130]), in1[1] - 1.0);
  t56 = b_t44_tmp * t82 * 2.0;
  t399 = in2[83] * t2 * t83 * 2.0;
  t400 = t59_tmp * t85 * 2.0;
  t53 = t100_tmp * t80 * 2.0;
  t132 = (((((t130 - t132) + t145) + t47_tmp * t128 * 2.0) + in2[81] * t4 * t83 *
           2.0) + t107_tmp * t80 * 2.0) - t119_tmp * t78 * 2.0;
  t406 = t406 * t85 * 2.0;
  t407 = c_t44_tmp * t25 * 2.0;
  t408 = t117 * in2[81] * t20 * t21 * 2.0;
  t128 = ((-t34 + t6) + t44_tmp * t31 * 2.0) + t32_tmp * in2[83] * t20 * t21 *
    2.0;
  memset(&out1[0], 0, 14U * sizeof(real_T));
  out1[14] = ((t9 + t10) - t4 * t7) - t5 * t7;
  out1[15] = t168;
  out1[16] = -t11 + t12;
  memset(&out1[17], 0, 60U * sizeof(real_T));
  out1[77] = ((-t9 - t10) + t14) + t35;
  out1[78] = -t8 - t36_tmp;
  out1[79] = t169;
  out1[80] = (((((((t122 + t126) + t58) + t160) - t176_tmp) - b_t176_tmp) -
               c_t176_tmp) - t175_tmp) - d_t176_tmp;
  out1[81] = (((((((t113 + t121) + t161) + t162) - t182_tmp) - b_t182_tmp) -
               c_t182_tmp) - d_t182_tmp) - t163_tmp;
  out1[82] = (((((((-t92 + t164) - t191_tmp) - b_t191_tmp) - c_t191_tmp) -
                d_t191_tmp) - t188_tmp) - e_t191_tmp) - t189_tmp;
  out1[83] = (((((((t104 - t133) + t165) + t166) + t167) - t197_tmp) -
               b_t197_tmp) - c_t197_tmp) - t196_tmp;
  memset(&out1[84], 0, 36U * sizeof(real_T));
  out1[120] = t8 - t36_tmp;
  out1[121] = ((t9 - t10) + t14) - t5 * t7;
  out1[122] = t218;
  memset(&out1[123], 0, 60U * sizeof(real_T));
  out1[183] = t217;
  t58 = -t9 + t10;
  out1[184] = (t58 - t14) + t35;
  out1[185] = -t13 - t37_tmp;
  out1[186] = (((((((t104 + t133) + t209) + t210) - t225_tmp) - b_t225_tmp) -
                c_t225_tmp) - t223_tmp) - d_t225_tmp;
  out1[187] = (((((((t92 - t103) + t211) + t212) + t213) - t230_tmp) -
                b_t230_tmp) - c_t230_tmp) - t189_tmp;
  out1[188] = (((((((t113 - t121) + t141) + t214) + t215) - t236_tmp) -
                b_t236_tmp) - c_t236_tmp) - d_t236_tmp;
  out1[189] = (((((((-t122 + t216) - t244_tmp) - b_t244_tmp) - c_t244_tmp) -
                 d_t244_tmp) - t175_tmp) - e_t244_tmp) - t243_tmp;
  memset(&out1[190], 0, 36U * sizeof(real_T));
  out1[226] = t263;
  out1[227] = t13 - t37_tmp;
  out1[228] = t265;
  memset(&out1[229], 0, 60U * sizeof(real_T));
  out1[289] = -t11 - t12;
  out1[290] = t264;
  out1[291] = (t58 + t14) - t35;
  out1[292] = (((((((t92 + t103) + t255) + t256) - t270_tmp) - b_t270_tmp) -
                c_t270_tmp) - t188_tmp) - d_t270_tmp;
  out1[293] = (((((((-t104 + t257) - t277_tmp) - b_t277_tmp) - t50) - t94) -
                t100) - t223_tmp) - t196_tmp;
  out1[294] = (((((((t122 - t126) + t258) + t259) + t260) - t102) - t120) - t60)
    - t243_tmp;
  out1[295] = (((((((t113 - t141) + t163_tmp) + t261) + t262) - t412) - t288_tmp)
               - b_t288_tmp) - c_t288_tmp;
  memset(&out1[296], 0, 39U * sizeof(real_T));
  out1[335] = ((t32 - t335_tmp) - b_t335_tmp) - t310_tmp;
  out1[336] = ((t34 + t76) + t48) - in2[18] * in2[19] * in2[83] * t20 * t21 *
    2.0;
  out1[337] = t316;
  out1[338] = ((t40 - t343_tmp) - t341_tmp) - b_t343_tmp;
  memset(&out1[339], 0, 59U * sizeof(real_T));
  out1[398] = t302;
  out1[399] = (((((t129 + t99) - t321_tmp) - t51) - t432) - t436) - t304_tmp;
  out1[400] = (((((-t108 + t127) + t54) - t428) - t427) - t328_tmp) - t330_tmp;
  out1[401] = t309;
  memset(&out1[402], 0, 39U * sizeof(real_T));
  out1[441] = ((t27 - t18) - t15) - t40;
  out1[442] = ((t116_tmp - t16) - t59) - t19;
  out1[443] = ((t49 + t362) + t363) - in2[19] * in2[20] * in2[81] * t20 * t21 *
    2.0;
  out1[444] = t367;
  memset(&out1[445], 0, 59U * sizeof(real_T));
  out1[504] = t354;
  out1[505] = t359;
  out1[506] = (((((-t129 + t147) + t355) - t321_tmp) - t74_tmp) - t27_tmp) - t22;
  out1[507] = (((((-t130 + t145) + t360) - t55) - t72) - t13_tmp) - t17;
  memset(&out1[508], 0, 39U * sizeof(real_T));
  t58 = b_t44_tmp * t23 * 2.0;
  t102 = t32_tmp * in2[80] * t20 * t21 * 2.0;
  out1[547] = ((t28 - t58) - t116_tmp) - t102;
  out1[548] = ((t27 + t407) + t408) - t341_tmp;
  t72 = t47_tmp * t29 * 2.0;
  t55 = t117 * in2[82] * t20 * t21 * 2.0;
  out1[549] = ((t310_tmp - t72) - t55) - t389_tmp;
  out1[550] = t128;
  memset(&out1[551], 0, 59U * sizeof(real_T));
  t120 = t108 + t110;
  t6 = t53_tmp * t88 * 2.0;
  out1[610] = ((((t120 + t56) + t399) + t400) - t6) - t328_tmp;
  t22 = c_t44_tmp * t109 * 2.0;
  t18 = in2[82] * t3 * t83 * 2.0;
  t16 = t107_tmp * t78 * 2.0;
  out1[611] = (((((-t111 + t142) + t53) - t18) - t22) - t16) - t98;
  out1[612] = t132;
  t17 = t44_tmp * t144 * 2.0;
  t15 = in2[80] * t5 * t83 * 2.0;
  t19 = t59_tmp * t88 * 2.0;
  out1[613] = (((((-t147 + t304_tmp) + t406) - t321_tmp) - t15) - t17) - t19;
  memset(&out1[614], 0, 22U * sizeof(real_T));
  t412 = ((((t120 - t328_tmp) + t56) + t399) + t400) - t6;
  t400 = (((((t111 - t142) + t98) - t53) + t22) + t18) + t16;
  t399 = (((((t147 - t304_tmp) + t321_tmp) - t406) + t17) + t15) + t19;
  t427 = ((-t28 + t116_tmp) + t58) + t102;
  t428 = ((t27 - t341_tmp) + t407) + t408;
  t432 = ((-t310_tmp + t389_tmp) + t72) + t55;
  st.site = &u_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t436 = muDoubleScalarPower(muDoubleScalarAbs(((((((t412 * in2[192] + t132 *
    in2[194]) + t428 * in2[130]) + t128 * in2[132]) - t400 * in2[193]) - t399 *
    in2[195]) - t427 * in2[129]) - t432 * in2[131]), in1[1] - 1.0);
  out2[0] = in1[0] * ((((((t149 * t150 / 2.0 - t150 * t153) + t149 * t156) +
    t44_tmp * t44) + b_t44_tmp * t47) - c_t44_tmp * t64) + t47_tmp * t68) *
    -0.00026666666666666668;
  out2[1] = in1[0] * (((((t157 * 0.01096696696707752 + t158 *
    0.01096696696707752) - t44_tmp * t47) + b_t44_tmp * t44) - t47_tmp * t64) -
                      c_t44_tmp * t68) * 0.00026666666666666668;
  t19 = ((t157 * -0.25 + t149 * t153) + t150 * t156) + t158 / 4.0;
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
  t120 = in1[2] * t170 * t205;
  t55 = in1[2] * t169 * t205;
  t72 = -in1[2] * t168 * t205;
  t13_tmp = in1[2] * t168 * t205;
  t99 = in1[2] * t176 * t205;
  t54 = in1[2] * t182 * t205;
  t76 = in1[2] * t191 * t205;
  t48 = in1[2] * t197 * t205;
  out3[0] = ((((((((t72 * in2[127] - t120 * in2[126]) + t55 * in2[128]) +
                  t13_tmp * in2[190]) + t120 * in2[189]) - t55 * in2[191]) + t99
               * in2[192]) + t54 * in2[193]) + t76 * in2[194]) + t48 * in2[195];
  t49 = in1[2] * t217 * t251;
  t59 = in1[2] * t218 * t251;
  t40 = in1[2] * t219 * t251;
  t51 = in1[2] * t225 * t251;
  t53 = in1[2] * t230 * t251;
  t56 = in1[2] * t236 * t251;
  t60 = in1[2] * t244 * t251;
  out3[1] = ((((((((t49 * in2[126] - t59 * in2[128]) - t40 * in2[127]) - t49 *
                  in2[189]) + t59 * in2[191]) + t40 * in2[190]) + t51 * in2[192])
              + t53 * in2[193]) + t56 * in2[194]) + t60 * in2[195];
  t117 = in1[2] * t264 * t295;
  t94 = in1[2] * t265 * t295;
  t100 = -in1[2] * t263 * t295;
  t50 = in1[2] * t263 * t295;
  t98 = in1[2] * t270 * t295;
  t116_tmp = in1[2] * t277 * t295;
  t74_tmp = in1[2] * t282 * t295;
  t27_tmp = in1[2] * t288 * t295;
  out3[2] = ((((((((t100 * in2[126] + t117 * in2[127]) - t94 * in2[128]) + t50 *
                  in2[189]) - t117 * in2[190]) + t94 * in2[191]) + t98 * in2[192])
              + t116_tmp * in2[193]) + t74_tmp * in2[194]) + t27_tmp * in2[195];
  t362 = in1[3] * t335 * t346;
  t363 = -in1[3] * t316 * t346;
  t355 = in1[3] * t343 * t346;
  t360 = in1[3] * t325 * t346;
  t406 = in1[3] * t330 * t346;
  out3[3] = ((((((t363 * in2[131] + t362 * in2[129]) - in1[3] * t336 * t346 *
                 in2[130]) + t355 * in2[132]) - in1[3] * t302 * t346 * in2[192])
              - in1[3] * t309 * t346 * in2[195]) + t360 * in2[193]) + t406 *
    in2[194];
  t407 = in1[3] * t383 * t393;
  t408 = in1[3] * t386 * t393;
  t330_tmp = -in1[3] * t367 * t393;
  t335_tmp = in1[3] * t374 * t393;
  b_t335_tmp = in1[3] * t380 * t393;
  out3[4] = ((((((t330_tmp * in2[132] + t407 * in2[129]) + t408 * in2[130]) -
                in1[3] * t387 * t393 * in2[131]) - in1[3] * t354 * t393 * in2
               [192]) - in1[3] * t359 * t393 * in2[193]) + t335_tmp * in2[194])
    + b_t335_tmp * in2[195];
  t343_tmp = in1[3] * t427 * t436;
  b_t343_tmp = in1[3] * t432 * t436;
  t288_tmp = -in1[3] * t128 * t436;
  b_t288_tmp = in1[3] * t400 * t436;
  c_t288_tmp = in1[3] * t399 * t436;
  out3[5] = ((((((t288_tmp * in2[132] + t343_tmp * in2[129]) - in1[3] * t428 *
                 t436 * in2[130]) + b_t343_tmp * in2[131]) - in1[3] * t132 *
               t436 * in2[194]) - in1[3] * t412 * t436 * in2[192]) + b_t288_tmp *
             in2[193]) + c_t288_tmp * in2[195];
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
  t102 = in1[0] * t170 * 0.00026666666666666668;
  t58 = in1[0] * t168 * 0.00026666666666666668;
  t6 = in1[0] * t219 * 0.00026666666666666668;
  t22 = in1[0] * t218 * 0.00026666666666666668;
  t17 = in1[0] * t263 * 0.0008;
  t18 = in1[0] * t265 * 0.0008;
  memset(&out6[0], 0, 84U * sizeof(real_T));
  out6[84] = t102;
  t16 = in1[0] * t217;
  out6[85] = t16 * -0.00026666666666666668;
  out6[86] = t17;
  out6[87] = 0.0;
  out6[88] = 0.0;
  out6[89] = 0.0;
  out6[90] = t58;
  out6[91] = t6;
  t15 = in1[0] * t264;
  out6[92] = t15 * -0.0008;
  out6[93] = 0.0;
  out6[94] = 0.0;
  out6[95] = 0.0;
  t19 = in1[0] * t169;
  out6[96] = t19 * -0.00026666666666666668;
  out6[97] = t22;
  out6[98] = t18;
  out6[99] = 0.0;
  out6[100] = 0.0;
  out6[101] = 0.0;
  out6[102] = 0.0;
  out6[103] = 0.0;
  out6[104] = 0.0;
  out6[105] = in1[0] * t335 * -4.2666666666666668E-11;
  out6[106] = in1[0] * t383 * -1.421066666666666E-8;
  out6[107] = in1[0] * t427 * -4.75111111111111E-9;
  out6[108] = 0.0;
  out6[109] = 0.0;
  out6[110] = 0.0;
  out6[111] = in1[0] * t336 * 4.2666666666666668E-11;
  out6[112] = in1[0] * t386 * -1.421066666666666E-8;
  out6[113] = in1[0] * t428 * 4.75111111111111E-9;
  out6[114] = 0.0;
  out6[115] = 0.0;
  out6[116] = 0.0;
  out6[117] = in1[0] * t316 * 4.2666666666666668E-11;
  out6[118] = in1[0] * t387 * 1.421066666666666E-8;
  out6[119] = in1[0] * t432 * -4.75111111111111E-9;
  out6[120] = 0.0;
  out6[121] = 0.0;
  out6[122] = 0.0;
  out6[123] = in1[0] * t343 * -4.2666666666666668E-11;
  out6[124] = in1[0] * t367 * 1.421066666666666E-8;
  out6[125] = in1[0] * t128 * 4.75111111111111E-9;
  memset(&out6[126], 0, 336U * sizeof(real_T));
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
  out6[480] = in1[0] * t176 * -0.00026666666666666668;
  out6[481] = in1[0] * t225 * -0.00026666666666666668;
  out6[482] = in1[0] * t270 * -0.0008;
  out6[483] = in1[0] * t302 * 4.2666666666666668E-11;
  out6[484] = in1[0] * t354 * 1.421066666666666E-8;
  out6[485] = in1[0] * t412 * 4.75111111111111E-9;
  out6[486] = in1[0] * t182 * -0.00026666666666666668;
  out6[487] = in1[0] * t230 * -0.00026666666666666668;
  out6[488] = in1[0] * t277 * -0.0008;
  out6[489] = in1[0] * t325 * -4.2666666666666668E-11;
  out6[490] = in1[0] * t359 * 1.421066666666666E-8;
  out6[491] = in1[0] * t400 * -4.75111111111111E-9;
  out6[492] = in1[0] * t191 * -0.00026666666666666668;
  out6[493] = in1[0] * t236 * -0.00026666666666666668;
  out6[494] = in1[0] * t282 * -0.0008;
  out6[495] = in1[0] * t330 * -4.2666666666666668E-11;
  out6[496] = in1[0] * t374 * -1.421066666666666E-8;
  out6[497] = in1[0] * t132 * 4.75111111111111E-9;
  out6[498] = in1[0] * t197 * -0.00026666666666666668;
  out6[499] = in1[0] * t244 * -0.00026666666666666668;
  out6[500] = in1[0] * t288 * -0.0008;
  out6[501] = in1[0] * t309 * 4.2666666666666668E-11;
  out6[502] = in1[0] * t380 * -1.421066666666666E-8;
  out6[503] = in1[0] * t399 * -4.75111111111111E-9;
  memset(&out6[504], 0, 132U * sizeof(real_T));
  memset(&out7[0], 0, 84U * sizeof(real_T));
  out7[84] = -in1[2] * t170 * t205;
  out7[85] = t49;
  out7[86] = t100;
  out7[87] = 0.0;
  out7[88] = 0.0;
  out7[89] = 0.0;
  out7[90] = t72;
  out7[91] = -in1[2] * t219 * t251;
  out7[92] = t117;
  out7[93] = 0.0;
  out7[94] = 0.0;
  out7[95] = 0.0;
  out7[96] = t55;
  out7[97] = -in1[2] * t218 * t251;
  out7[98] = -in1[2] * t265 * t295;
  out7[99] = 0.0;
  out7[100] = 0.0;
  out7[101] = 0.0;
  out7[102] = 0.0;
  out7[103] = 0.0;
  out7[104] = 0.0;
  out7[105] = t362;
  out7[106] = t407;
  out7[107] = t343_tmp;
  out7[108] = 0.0;
  out7[109] = 0.0;
  out7[110] = 0.0;
  out7[111] = -in1[3] * t336 * t346;
  out7[112] = t408;
  out7[113] = -in1[3] * t428 * t436;
  out7[114] = 0.0;
  out7[115] = 0.0;
  out7[116] = 0.0;
  out7[117] = t363;
  out7[118] = -in1[3] * t387 * t393;
  out7[119] = b_t343_tmp;
  out7[120] = 0.0;
  out7[121] = 0.0;
  out7[122] = 0.0;
  out7[123] = t355;
  out7[124] = t330_tmp;
  out7[125] = t288_tmp;
  memset(&out7[126], 0, 336U * sizeof(real_T));
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
  out7[483] = -in1[3] * t302 * t346;
  out7[484] = -in1[3] * t354 * t393;
  out7[485] = -in1[3] * t412 * t436;
  out7[486] = t54;
  out7[487] = t53;
  out7[488] = t116_tmp;
  out7[489] = t360;
  out7[490] = -in1[3] * t359 * t393;
  out7[491] = b_t288_tmp;
  out7[492] = t76;
  out7[493] = t56;
  out7[494] = t74_tmp;
  out7[495] = t406;
  out7[496] = t335_tmp;
  out7[497] = -in1[3] * t132 * t436;
  out7[498] = t48;
  out7[499] = t60;
  out7[500] = t27_tmp;
  out7[501] = -in1[3] * t309 * t346;
  out7[502] = b_t335_tmp;
  out7[503] = c_t288_tmp;
  memset(&out7[504], 0, 132U * sizeof(real_T));
  *out8 = 1.0;
}

/* End of code generation (sprdmpF112.c) */
