/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sprdmpF110.c
 *
 * Code generation for function 'sprdmpF110'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "sprdmpF110.h"
#include "sqrt.h"
#include "error.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 41,    /* lineNo */
  "sprdmpF110",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF110.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 42,  /* lineNo */
  "sprdmpF110",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF110.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 43,  /* lineNo */
  "sprdmpF110",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF110.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 44,  /* lineNo */
  "sprdmpF110",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF110.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 54,  /* lineNo */
  "sprdmpF110",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF110.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 55,  /* lineNo */
  "sprdmpF110",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF110.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 56,  /* lineNo */
  "sprdmpF110",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF110.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 57,  /* lineNo */
  "sprdmpF110",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF110.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 59,  /* lineNo */
  "sprdmpF110",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF110.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 60,  /* lineNo */
  "sprdmpF110",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF110.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 61,  /* lineNo */
  "sprdmpF110",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF110.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 79,  /* lineNo */
  "sprdmpF110",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF110.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 124, /* lineNo */
  "sprdmpF110",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF110.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 196, /* lineNo */
  "sprdmpF110",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF110.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 197, /* lineNo */
  "sprdmpF110",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF110.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 247, /* lineNo */
  "sprdmpF110",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF110.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 293, /* lineNo */
  "sprdmpF110",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF110.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 337, /* lineNo */
  "sprdmpF110",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF110.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 389, /* lineNo */
  "sprdmpF110",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF110.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 436, /* lineNo */
  "sprdmpF110",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF110.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 481, /* lineNo */
  "sprdmpF110",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF110.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 494, /* lineNo */
  "sprdmpF110",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF110.m"/* pathName */
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
void sprdmpF110(const emlrtStack *sp, const real_T in1[6], const real_T in2[224],
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

  /* SPRDMPF110 */
  /*     [OUT1,OUT2,OUT3,OUT4,OUT5,OUT6,OUT7,OUT8] = SPRDMPF110(IN1,IN2,S) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.2. */
  /*     06-Jul-2019 07:27:44 */
  st.site = &emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t2 = in2[73] * in2[73];
  st.site = &b_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t3 = in2[74] * in2[74];
  st.site = &c_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t4 = in2[75] * in2[75];
  st.site = &d_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t5 = in2[76] * in2[76];
  t6 = ((t2 + t3) + t4) + t5;
  t7 = 1.0 / t6;
  t120 = in2[74] * in2[75];
  t8 = t120 * t7 * 2.0;
  t9 = t2 * t7;
  t10 = t3 * t7;
  t58 = in2[73] * in2[75];
  t11 = t58 * t7 * 2.0;
  t102 = in2[74] * in2[76];
  t12 = t102 * t7 * 2.0;
  t13_tmp = in2[75] * in2[76];
  t13 = t13_tmp * t7 * 2.0;
  t14 = t4 * t7;
  st.site = &e_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t15 = in2[10] * in2[10];
  st.site = &f_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t16 = in2[11] * in2[11];
  st.site = &g_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t17 = in2[12] * in2[12];
  st.site = &h_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t18 = in2[13] * in2[13];
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
  t27_tmp = in2[10] * in2[11];
  t27 = t27_tmp * in2[76] * t20 * t21 * 2.0;
  t399 = in2[10] * in2[12];
  t28 = t399 * in2[74] * t20 * t21 * 2.0;
  t29 = t22 - t17 * t20;
  t31 = t22 - t18 * t20;
  t32_tmp = in2[10] * in2[13];
  t32 = t32_tmp * in2[75] * t20 * t21 * 2.0;
  t400 = in2[11] * in2[13];
  t34 = t400 * in2[75] * t20 * t21 * 2.0;
  t35 = t5 * t7;
  t15 = in2[73] * in2[76];
  t36_tmp = t15 * t7 * 2.0;
  t19 = in2[73] * in2[74];
  t37_tmp = t19 * t7 * 2.0;
  t38 = in2[7] - in2[70];
  t39 = in2[8] - in2[71];
  st.site = &l_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  if (t6 < 0.0) {
    c_st.site = &x_emlrtRSI;
    error(&c_st);
  }

  t40 = 1.0 / muDoubleScalarPower(t6, 1.5);
  t41 = in2[9] - in2[72];
  t44_tmp = in2[73] * t21;
  b_t44_tmp = in2[76] * t21;
  c_t44_tmp = in2[75] * t21;
  t44 = (t44_tmp * t38 + b_t44_tmp * t39) - c_t44_tmp * t41;
  t47_tmp = in2[74] * t21;
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
  t78 = in2[11] * t22 - t47_tmp;
  t80 = in2[12] * t22 - c_t44_tmp;
  t82 = t21 - t53_tmp;
  st.site = &m_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t83 = 1.0 / (t6 * t6);
  t85 = in2[10] * t22 - t44_tmp;
  t88 = in2[13] * t22 - b_t44_tmp;
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
  t153 = t149 * 0.162 + t150 * 0.036;
  t156 = t149 * 0.036 - t150 * 0.162;
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
  t205 = muDoubleScalarPower(muDoubleScalarAbs(((((((((t176 * in2[185] + t182 *
    in2[186]) + t191 * in2[187]) + t197 * in2[188]) + t169 * in2[121]) + t168 *
    in2[183]) + t170 * in2[182]) - t168 * in2[120]) - t169 * in2[184]) - t170 *
    in2[119]), in1[1] - 1.0);
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
  t251 = muDoubleScalarPower(muDoubleScalarAbs(((((((((t225 * in2[185] + t230 *
    in2[186]) + t236 * in2[187]) + t244 * in2[188]) + t217 * in2[119]) + t218 *
    in2[184]) + t219 * in2[183]) - t218 * in2[121]) - t217 * in2[182]) - t219 *
    in2[120]), in1[1] - 1.0);
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
  t295 = muDoubleScalarPower(muDoubleScalarAbs(((((((((t270 * in2[185] + t277 *
    in2[186]) + t282 * in2[187]) + t288 * in2[188]) + t264 * in2[120]) + t263 *
    in2[182]) + t265 * in2[184]) - t263 * in2[119]) - t264 * in2[183]) - t265 *
    in2[121]), in1[1] - 1.0);
  t13_tmp = t59_tmp * t80 * 2.0;
  t302 = (((((t130 + t132) + t47_tmp * t82 * 2.0) + in2[74] * t2 * t83 * 2.0) +
           t74_tmp * t85 * 2.0) - t53_tmp * t78 * 2.0) - t13_tmp;
  t99 = t100_tmp * t85 * 2.0;
  t304_tmp = t407 * t80 * 2.0;
  t54 = t119_tmp * t88 * 2.0;
  t309 = (((((t111 + t142) - t6) + c_t44_tmp * t144 * 2.0) + in2[75] * t5 * t83 *
           2.0) + t116_tmp * t88 * 2.0) - t406 * t80 * 2.0;
  t310_tmp = t399 * in2[76] * t20 * t21 * 2.0;
  t76 = t44_tmp * t25 * 2.0;
  t48 = t27_tmp * in2[74] * t20 * t21 * 2.0;
  t117 = in2[11] * in2[12];
  t49 = t117 * in2[76] * t20 * t21 * 2.0;
  t59 = t117 * in2[73] * t20 * t21 * 2.0;
  t19 = in2[12] * in2[13];
  t316 = ((t28 + b_t44_tmp * t29 * 2.0) + t19 * in2[75] * t20 * t21 * 2.0) - t59;
  t40 = t32_tmp * in2[74] * t20 * t21 * 2.0;
  t321_tmp = t21 * t85 * 2.0;
  t51 = in2[73] * t3 * t83 * 2.0;
  t432 = t44_tmp * t109 * 2.0;
  t436 = t74_tmp * t78 * 2.0;
  t325 = (((((-t129 - t99) + t304_tmp) + t321_tmp) + t432) + t51) + t436;
  t328_tmp = t408 * t78 * 2.0;
  t428 = in2[76] * t4 * t83 * 2.0;
  t427 = b_t44_tmp * t128 * 2.0;
  t330_tmp = t116_tmp * t80 * 2.0;
  t330 = (((((t108 - t127) - t54) + t427) + t428) + t328_tmp) + t330_tmp;
  t335_tmp = t47_tmp * t23 * 2.0;
  b_t335_tmp = t27_tmp * in2[73] * t20 * t21 * 2.0;
  t335 = ((-t32 + t310_tmp) + t335_tmp) + b_t335_tmp;
  t336 = ((t34 + t76) + t48) - t49;
  t341_tmp = t400 * in2[73] * t20 * t21 * 2.0;
  t343_tmp = c_t44_tmp * t31 * 2.0;
  b_t343_tmp = t19 * in2[76] * t20 * t21 * 2.0;
  t343 = ((-t40 + t343_tmp) + t341_tmp) + b_t343_tmp;
  st.site = &s_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t346 = muDoubleScalarPower(muDoubleScalarAbs(((((((t302 * in2[185] + t309 *
    in2[188]) + t336 * in2[123]) + t316 * in2[124]) - t325 * in2[186]) - t330 *
    in2[187]) - t335 * in2[122]) - t343 * in2[125]), in1[1] - 1.0);
  t98 = t74_tmp * t88 * 2.0;
  t354 = (((((t111 + t6) + c_t44_tmp * t82 * 2.0) + in2[75] * t2 * t83 * 2.0) +
           t408 * t85 * 2.0) - t53_tmp * t80 * 2.0) - t98;
  t355 = t119_tmp * t85 * 2.0;
  t359 = (((((t108 - t110) + t127) + b_t44_tmp * t109 * 2.0) + in2[76] * t3 *
           t83 * 2.0) + t407 * t78 * 2.0) - t100_tmp * t88 * 2.0;
  t360 = t406 * t78 * 2.0;
  t116_tmp = t27_tmp * in2[75] * t20 * t21 * 2.0;
  t362 = t44_tmp * t29 * 2.0;
  t363 = t399 * in2[75] * t20 * t21 * 2.0;
  t6 = t19 * in2[74] * t20 * t21 * 2.0;
  t389_tmp = t19 * in2[73] * t20 * t21 * 2.0;
  t367 = ((t32 + t47_tmp * t31 * 2.0) + t400 * in2[76] * t20 * t21 * 2.0) -
    t389_tmp;
  t74_tmp = in2[73] * t4 * t83 * 2.0;
  t27_tmp = t44_tmp * t128 * 2.0;
  t22 = t408 * t80 * 2.0;
  t374 = (((((t129 - t147) + t321_tmp) - t355) + t27_tmp) + t74_tmp) + t22;
  t55 = in2[74] * t5 * t83 * 2.0;
  t72 = t47_tmp * t144 * 2.0;
  t17 = t407 * t88 * 2.0;
  t380 = (((((t130 - t145) + t13_tmp) - t360) + t72) + t55) + t17;
  t18 = c_t44_tmp * t23 * 2.0;
  t15 = t399 * in2[73] * t20 * t21 * 2.0;
  t383 = ((-t27 + t40) + t18) + t15;
  t16 = b_t44_tmp * t25 * 2.0;
  t19 = t400 * in2[74] * t20 * t21 * 2.0;
  t386 = ((t59 - t116_tmp) + t16) + t19;
  t387 = ((t49 + t362) + t363) - t6;
  st.site = &t_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t393 = muDoubleScalarPower(muDoubleScalarAbs(((((((t354 * in2[185] + t359 *
    in2[186]) + t387 * in2[124]) + t367 * in2[125]) - t374 * in2[187]) - t380 *
    in2[188]) - t383 * in2[122]) - t386 * in2[123]), in1[1] - 1.0);
  t56 = b_t44_tmp * t82 * 2.0;
  t399 = in2[76] * t2 * t83 * 2.0;
  t400 = t59_tmp * t85 * 2.0;
  t53 = t100_tmp * t80 * 2.0;
  t132 = (((((t130 - t132) + t145) + t47_tmp * t128 * 2.0) + in2[74] * t4 * t83 *
           2.0) + t107_tmp * t80 * 2.0) - t119_tmp * t78 * 2.0;
  t406 = t406 * t85 * 2.0;
  t407 = c_t44_tmp * t25 * 2.0;
  t408 = t117 * in2[74] * t20 * t21 * 2.0;
  t128 = ((-t34 + t6) + t44_tmp * t31 * 2.0) + t32_tmp * in2[76] * t20 * t21 *
    2.0;
  out1[0] = 0.0;
  out1[1] = 0.0;
  out1[2] = 0.0;
  out1[3] = 0.0;
  out1[4] = 0.0;
  out1[5] = 0.0;
  out1[6] = 0.0;
  out1[7] = ((t9 + t10) - t4 * t7) - t5 * t7;
  out1[8] = t168;
  out1[9] = -t11 + t12;
  memset(&out1[10], 0, 60U * sizeof(real_T));
  out1[70] = ((-t9 - t10) + t14) + t35;
  out1[71] = -t8 - t36_tmp;
  out1[72] = t169;
  out1[73] = (((((((t122 + t126) + t58) + t160) - t176_tmp) - b_t176_tmp) -
               c_t176_tmp) - t175_tmp) - d_t176_tmp;
  out1[74] = (((((((t113 + t121) + t161) + t162) - t182_tmp) - b_t182_tmp) -
               c_t182_tmp) - d_t182_tmp) - t163_tmp;
  out1[75] = (((((((-t92 + t164) - t191_tmp) - b_t191_tmp) - c_t191_tmp) -
                d_t191_tmp) - t188_tmp) - e_t191_tmp) - t189_tmp;
  out1[76] = (((((((t104 - t133) + t165) + t166) + t167) - t197_tmp) -
               b_t197_tmp) - c_t197_tmp) - t196_tmp;
  memset(&out1[77], 0, 36U * sizeof(real_T));
  out1[113] = t8 - t36_tmp;
  out1[114] = ((t9 - t10) + t14) - t5 * t7;
  out1[115] = t218;
  memset(&out1[116], 0, 60U * sizeof(real_T));
  out1[176] = t217;
  t58 = -t9 + t10;
  out1[177] = (t58 - t14) + t35;
  out1[178] = -t13 - t37_tmp;
  out1[179] = (((((((t104 + t133) + t209) + t210) - t225_tmp) - b_t225_tmp) -
                c_t225_tmp) - t223_tmp) - d_t225_tmp;
  out1[180] = (((((((t92 - t103) + t211) + t212) + t213) - t230_tmp) -
                b_t230_tmp) - c_t230_tmp) - t189_tmp;
  out1[181] = (((((((t113 - t121) + t141) + t214) + t215) - t236_tmp) -
                b_t236_tmp) - c_t236_tmp) - d_t236_tmp;
  out1[182] = (((((((-t122 + t216) - t244_tmp) - b_t244_tmp) - c_t244_tmp) -
                 d_t244_tmp) - t175_tmp) - e_t244_tmp) - t243_tmp;
  memset(&out1[183], 0, 36U * sizeof(real_T));
  out1[219] = t263;
  out1[220] = t13 - t37_tmp;
  out1[221] = t265;
  memset(&out1[222], 0, 60U * sizeof(real_T));
  out1[282] = -t11 - t12;
  out1[283] = t264;
  out1[284] = (t58 + t14) - t35;
  out1[285] = (((((((t92 + t103) + t255) + t256) - t270_tmp) - b_t270_tmp) -
                c_t270_tmp) - t188_tmp) - d_t270_tmp;
  out1[286] = (((((((-t104 + t257) - t277_tmp) - b_t277_tmp) - t50) - t94) -
                t100) - t223_tmp) - t196_tmp;
  out1[287] = (((((((t122 - t126) + t258) + t259) + t260) - t102) - t120) - t60)
    - t243_tmp;
  out1[288] = (((((((t113 - t141) + t163_tmp) + t261) + t262) - t412) - t288_tmp)
               - b_t288_tmp) - c_t288_tmp;
  memset(&out1[289], 0, 39U * sizeof(real_T));
  out1[328] = ((t32 - t335_tmp) - b_t335_tmp) - t310_tmp;
  out1[329] = ((t34 + t76) + t48) - in2[11] * in2[12] * in2[76] * t20 * t21 *
    2.0;
  out1[330] = t316;
  out1[331] = ((t40 - t343_tmp) - t341_tmp) - b_t343_tmp;
  memset(&out1[332], 0, 59U * sizeof(real_T));
  out1[391] = t302;
  out1[392] = (((((t129 + t99) - t321_tmp) - t51) - t432) - t436) - t304_tmp;
  out1[393] = (((((-t108 + t127) + t54) - t428) - t427) - t328_tmp) - t330_tmp;
  out1[394] = t309;
  memset(&out1[395], 0, 39U * sizeof(real_T));
  out1[434] = ((t27 - t18) - t15) - t40;
  out1[435] = ((t116_tmp - t16) - t59) - t19;
  out1[436] = ((t49 + t362) + t363) - in2[12] * in2[13] * in2[74] * t20 * t21 *
    2.0;
  out1[437] = t367;
  memset(&out1[438], 0, 59U * sizeof(real_T));
  out1[497] = t354;
  out1[498] = t359;
  out1[499] = (((((-t129 + t147) + t355) - t321_tmp) - t74_tmp) - t27_tmp) - t22;
  out1[500] = (((((-t130 + t145) + t360) - t55) - t72) - t13_tmp) - t17;
  memset(&out1[501], 0, 39U * sizeof(real_T));
  t58 = b_t44_tmp * t23 * 2.0;
  t102 = t32_tmp * in2[73] * t20 * t21 * 2.0;
  out1[540] = ((t28 - t58) - t116_tmp) - t102;
  out1[541] = ((t27 + t407) + t408) - t341_tmp;
  t72 = t47_tmp * t29 * 2.0;
  t55 = t117 * in2[75] * t20 * t21 * 2.0;
  out1[542] = ((t310_tmp - t72) - t55) - t389_tmp;
  out1[543] = t128;
  memset(&out1[544], 0, 59U * sizeof(real_T));
  t120 = t108 + t110;
  t6 = t53_tmp * t88 * 2.0;
  out1[603] = ((((t120 + t56) + t399) + t400) - t6) - t328_tmp;
  t22 = c_t44_tmp * t109 * 2.0;
  t18 = in2[75] * t3 * t83 * 2.0;
  t16 = t107_tmp * t78 * 2.0;
  out1[604] = (((((-t111 + t142) + t53) - t18) - t22) - t16) - t98;
  out1[605] = t132;
  t17 = t44_tmp * t144 * 2.0;
  t15 = in2[73] * t5 * t83 * 2.0;
  t19 = t59_tmp * t88 * 2.0;
  out1[606] = (((((-t147 + t304_tmp) + t406) - t321_tmp) - t15) - t17) - t19;
  memset(&out1[607], 0, 29U * sizeof(real_T));
  t412 = ((((t120 - t328_tmp) + t56) + t399) + t400) - t6;
  t400 = (((((t111 - t142) + t98) - t53) + t22) + t18) + t16;
  t399 = (((((t147 - t304_tmp) + t321_tmp) - t406) + t17) + t15) + t19;
  t427 = ((-t28 + t116_tmp) + t58) + t102;
  t428 = ((t27 - t341_tmp) + t407) + t408;
  t432 = ((-t310_tmp + t389_tmp) + t72) + t55;
  st.site = &u_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t436 = muDoubleScalarPower(muDoubleScalarAbs(((((((t412 * in2[185] + t132 *
    in2[187]) + t428 * in2[123]) + t128 * in2[125]) - t400 * in2[186]) - t399 *
    in2[188]) - t427 * in2[122]) - t432 * in2[124]), in1[1] - 1.0);
  out2[0] = in1[0] * ((((((t149 * t150 * 0.324 - t150 * t153) + t149 * t156) +
    t44_tmp * t44) + b_t44_tmp * t47) - c_t44_tmp * t64) + t47_tmp * t68) *
    -0.00026666666666666668;
  out2[1] = in1[0] * (((((t157 * 0.02259459459505023 + t158 *
    0.02259459459505023) - t44_tmp * t47) + b_t44_tmp * t44) - t47_tmp * t64) -
                      c_t44_tmp * t68) * 0.00026666666666666668;
  t19 = ((t157 * -0.162 + t149 * t153) + t150 * t156) + t158 * 0.162;
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
  out3[0] = ((((((((t72 * in2[120] - t120 * in2[119]) + t55 * in2[121]) +
                  t13_tmp * in2[183]) + t120 * in2[182]) - t55 * in2[184]) + t99
               * in2[185]) + t54 * in2[186]) + t76 * in2[187]) + t48 * in2[188];
  t49 = in1[2] * t217 * t251;
  t59 = in1[2] * t218 * t251;
  t40 = in1[2] * t219 * t251;
  t51 = in1[2] * t225 * t251;
  t53 = in1[2] * t230 * t251;
  t56 = in1[2] * t236 * t251;
  t60 = in1[2] * t244 * t251;
  out3[1] = ((((((((t49 * in2[119] - t59 * in2[121]) - t40 * in2[120]) - t49 *
                  in2[182]) + t59 * in2[184]) + t40 * in2[183]) + t51 * in2[185])
              + t53 * in2[186]) + t56 * in2[187]) + t60 * in2[188];
  t117 = in1[2] * t264 * t295;
  t94 = in1[2] * t265 * t295;
  t100 = -in1[2] * t263 * t295;
  t50 = in1[2] * t263 * t295;
  t98 = in1[2] * t270 * t295;
  t116_tmp = in1[2] * t277 * t295;
  t74_tmp = in1[2] * t282 * t295;
  t27_tmp = in1[2] * t288 * t295;
  out3[2] = ((((((((t100 * in2[119] + t117 * in2[120]) - t94 * in2[121]) + t50 *
                  in2[182]) - t117 * in2[183]) + t94 * in2[184]) + t98 * in2[185])
              + t116_tmp * in2[186]) + t74_tmp * in2[187]) + t27_tmp * in2[188];
  t362 = in1[3] * t335 * t346;
  t363 = -in1[3] * t316 * t346;
  t355 = in1[3] * t343 * t346;
  t360 = in1[3] * t325 * t346;
  t406 = in1[3] * t330 * t346;
  out3[3] = ((((((t363 * in2[124] + t362 * in2[122]) - in1[3] * t336 * t346 *
                 in2[123]) + t355 * in2[125]) - in1[3] * t302 * t346 * in2[185])
              - in1[3] * t309 * t346 * in2[188]) + t360 * in2[186]) + t406 *
    in2[187];
  t407 = in1[3] * t383 * t393;
  t408 = in1[3] * t386 * t393;
  t330_tmp = -in1[3] * t367 * t393;
  t335_tmp = in1[3] * t374 * t393;
  b_t335_tmp = in1[3] * t380 * t393;
  out3[4] = ((((((t330_tmp * in2[125] + t407 * in2[122]) + t408 * in2[123]) -
                in1[3] * t387 * t393 * in2[124]) - in1[3] * t354 * t393 * in2
               [185]) - in1[3] * t359 * t393 * in2[186]) + t335_tmp * in2[187])
    + b_t335_tmp * in2[188];
  t343_tmp = in1[3] * t427 * t436;
  b_t343_tmp = in1[3] * t432 * t436;
  t288_tmp = -in1[3] * t128 * t436;
  b_t288_tmp = in1[3] * t400 * t436;
  c_t288_tmp = in1[3] * t399 * t436;
  out3[5] = ((((((t288_tmp * in2[125] + t343_tmp * in2[122]) - in1[3] * t428 *
                 t436 * in2[123]) + b_t343_tmp * in2[124]) - in1[3] * t132 *
               t436 * in2[187]) - in1[3] * t412 * t436 * in2[185]) + b_t288_tmp *
             in2[186]) + c_t288_tmp * in2[188];
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
  memset(&out6[0], 0, 42U * sizeof(real_T));
  out6[42] = t102;
  t16 = in1[0] * t217;
  out6[43] = t16 * -0.00026666666666666668;
  out6[44] = t17;
  out6[45] = 0.0;
  out6[46] = 0.0;
  out6[47] = 0.0;
  out6[48] = t58;
  out6[49] = t6;
  t15 = in1[0] * t264;
  out6[50] = t15 * -0.0008;
  out6[51] = 0.0;
  out6[52] = 0.0;
  out6[53] = 0.0;
  t19 = in1[0] * t169;
  out6[54] = t19 * -0.00026666666666666668;
  out6[55] = t22;
  out6[56] = t18;
  out6[57] = 0.0;
  out6[58] = 0.0;
  out6[59] = 0.0;
  out6[60] = 0.0;
  out6[61] = 0.0;
  out6[62] = 0.0;
  out6[63] = in1[0] * t335 * -4.2666666666666668E-11;
  out6[64] = in1[0] * t383 * -1.421066666666666E-8;
  out6[65] = in1[0] * t427 * -4.75111111111111E-9;
  out6[66] = 0.0;
  out6[67] = 0.0;
  out6[68] = 0.0;
  out6[69] = in1[0] * t336 * 4.2666666666666668E-11;
  out6[70] = in1[0] * t386 * -1.421066666666666E-8;
  out6[71] = in1[0] * t428 * 4.75111111111111E-9;
  out6[72] = 0.0;
  out6[73] = 0.0;
  out6[74] = 0.0;
  out6[75] = in1[0] * t316 * 4.2666666666666668E-11;
  out6[76] = in1[0] * t387 * 1.421066666666666E-8;
  out6[77] = in1[0] * t432 * -4.75111111111111E-9;
  out6[78] = 0.0;
  out6[79] = 0.0;
  out6[80] = 0.0;
  out6[81] = in1[0] * t343 * -4.2666666666666668E-11;
  out6[82] = in1[0] * t367 * 1.421066666666666E-8;
  out6[83] = in1[0] * t128 * 4.75111111111111E-9;
  memset(&out6[84], 0, 336U * sizeof(real_T));
  out6[420] = -t102;
  out6[421] = t16 * 0.00026666666666666668;
  out6[422] = -t17;
  out6[423] = 0.0;
  out6[424] = 0.0;
  out6[425] = 0.0;
  out6[426] = -t58;
  out6[427] = -t6;
  out6[428] = t15 * 0.0008;
  out6[429] = 0.0;
  out6[430] = 0.0;
  out6[431] = 0.0;
  out6[432] = t19 * 0.00026666666666666668;
  out6[433] = -t22;
  out6[434] = -t18;
  out6[435] = 0.0;
  out6[436] = 0.0;
  out6[437] = 0.0;
  out6[438] = in1[0] * t176 * -0.00026666666666666668;
  out6[439] = in1[0] * t225 * -0.00026666666666666668;
  out6[440] = in1[0] * t270 * -0.0008;
  out6[441] = in1[0] * t302 * 4.2666666666666668E-11;
  out6[442] = in1[0] * t354 * 1.421066666666666E-8;
  out6[443] = in1[0] * t412 * 4.75111111111111E-9;
  out6[444] = in1[0] * t182 * -0.00026666666666666668;
  out6[445] = in1[0] * t230 * -0.00026666666666666668;
  out6[446] = in1[0] * t277 * -0.0008;
  out6[447] = in1[0] * t325 * -4.2666666666666668E-11;
  out6[448] = in1[0] * t359 * 1.421066666666666E-8;
  out6[449] = in1[0] * t400 * -4.75111111111111E-9;
  out6[450] = in1[0] * t191 * -0.00026666666666666668;
  out6[451] = in1[0] * t236 * -0.00026666666666666668;
  out6[452] = in1[0] * t282 * -0.0008;
  out6[453] = in1[0] * t330 * -4.2666666666666668E-11;
  out6[454] = in1[0] * t374 * -1.421066666666666E-8;
  out6[455] = in1[0] * t132 * 4.75111111111111E-9;
  out6[456] = in1[0] * t197 * -0.00026666666666666668;
  out6[457] = in1[0] * t244 * -0.00026666666666666668;
  out6[458] = in1[0] * t288 * -0.0008;
  out6[459] = in1[0] * t309 * 4.2666666666666668E-11;
  out6[460] = in1[0] * t380 * -1.421066666666666E-8;
  out6[461] = in1[0] * t399 * -4.75111111111111E-9;
  memset(&out6[462], 0, 174U * sizeof(real_T));
  memset(&out7[0], 0, 42U * sizeof(real_T));
  out7[42] = -in1[2] * t170 * t205;
  out7[43] = t49;
  out7[44] = t100;
  out7[45] = 0.0;
  out7[46] = 0.0;
  out7[47] = 0.0;
  out7[48] = t72;
  out7[49] = -in1[2] * t219 * t251;
  out7[50] = t117;
  out7[51] = 0.0;
  out7[52] = 0.0;
  out7[53] = 0.0;
  out7[54] = t55;
  out7[55] = -in1[2] * t218 * t251;
  out7[56] = -in1[2] * t265 * t295;
  out7[57] = 0.0;
  out7[58] = 0.0;
  out7[59] = 0.0;
  out7[60] = 0.0;
  out7[61] = 0.0;
  out7[62] = 0.0;
  out7[63] = t362;
  out7[64] = t407;
  out7[65] = t343_tmp;
  out7[66] = 0.0;
  out7[67] = 0.0;
  out7[68] = 0.0;
  out7[69] = -in1[3] * t336 * t346;
  out7[70] = t408;
  out7[71] = -in1[3] * t428 * t436;
  out7[72] = 0.0;
  out7[73] = 0.0;
  out7[74] = 0.0;
  out7[75] = t363;
  out7[76] = -in1[3] * t387 * t393;
  out7[77] = b_t343_tmp;
  out7[78] = 0.0;
  out7[79] = 0.0;
  out7[80] = 0.0;
  out7[81] = t355;
  out7[82] = t330_tmp;
  out7[83] = t288_tmp;
  memset(&out7[84], 0, 336U * sizeof(real_T));
  out7[420] = t120;
  out7[421] = -t49;
  out7[422] = t50;
  out7[423] = 0.0;
  out7[424] = 0.0;
  out7[425] = 0.0;
  out7[426] = t13_tmp;
  out7[427] = t40;
  out7[428] = -t117;
  out7[429] = 0.0;
  out7[430] = 0.0;
  out7[431] = 0.0;
  out7[432] = -t55;
  out7[433] = t59;
  out7[434] = t94;
  out7[435] = 0.0;
  out7[436] = 0.0;
  out7[437] = 0.0;
  out7[438] = t99;
  out7[439] = t51;
  out7[440] = t98;
  out7[441] = -in1[3] * t302 * t346;
  out7[442] = -in1[3] * t354 * t393;
  out7[443] = -in1[3] * t412 * t436;
  out7[444] = t54;
  out7[445] = t53;
  out7[446] = t116_tmp;
  out7[447] = t360;
  out7[448] = -in1[3] * t359 * t393;
  out7[449] = b_t288_tmp;
  out7[450] = t76;
  out7[451] = t56;
  out7[452] = t74_tmp;
  out7[453] = t406;
  out7[454] = t335_tmp;
  out7[455] = -in1[3] * t132 * t436;
  out7[456] = t48;
  out7[457] = t60;
  out7[458] = t27_tmp;
  out7[459] = -in1[3] * t309 * t346;
  out7[460] = b_t335_tmp;
  out7[461] = c_t288_tmp;
  memset(&out7[462], 0, 174U * sizeof(real_T));
  *out8 = 1.0;
}

/* End of code generation (sprdmpF110.c) */
