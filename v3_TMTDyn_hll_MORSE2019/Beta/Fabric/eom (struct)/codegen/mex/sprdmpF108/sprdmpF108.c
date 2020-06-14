/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sprdmpF108.c
 *
 * Code generation for function 'sprdmpF108'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "sprdmpF108.h"
#include "sqrt.h"
#include "error.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 41,    /* lineNo */
  "sprdmpF108",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF108.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 42,  /* lineNo */
  "sprdmpF108",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF108.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 43,  /* lineNo */
  "sprdmpF108",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF108.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 44,  /* lineNo */
  "sprdmpF108",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF108.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 54,  /* lineNo */
  "sprdmpF108",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF108.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 55,  /* lineNo */
  "sprdmpF108",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF108.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 56,  /* lineNo */
  "sprdmpF108",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF108.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 57,  /* lineNo */
  "sprdmpF108",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF108.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 59,  /* lineNo */
  "sprdmpF108",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF108.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 60,  /* lineNo */
  "sprdmpF108",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF108.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 61,  /* lineNo */
  "sprdmpF108",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF108.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 79,  /* lineNo */
  "sprdmpF108",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF108.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 124, /* lineNo */
  "sprdmpF108",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF108.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 196, /* lineNo */
  "sprdmpF108",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF108.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 197, /* lineNo */
  "sprdmpF108",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF108.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 247, /* lineNo */
  "sprdmpF108",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF108.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 293, /* lineNo */
  "sprdmpF108",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF108.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 337, /* lineNo */
  "sprdmpF108",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF108.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 389, /* lineNo */
  "sprdmpF108",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF108.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 436, /* lineNo */
  "sprdmpF108",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF108.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 481, /* lineNo */
  "sprdmpF108",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF108.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 494, /* lineNo */
  "sprdmpF108",                        /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/sprdmpF108.m"/* pathName */
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
void sprdmpF108(const emlrtStack *sp, const real_T in1[6], const real_T in2[224],
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

  /* SPRDMPF108 */
  /*     [OUT1,OUT2,OUT3,OUT4,OUT5,OUT6,OUT7,OUT8] = SPRDMPF108(IN1,IN2,S) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.2. */
  /*     06-Jul-2019 08:06:54 */
  st.site = &emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t2 = in2[66] * in2[66];
  st.site = &b_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t3 = in2[67] * in2[67];
  st.site = &c_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t4 = in2[68] * in2[68];
  st.site = &d_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t5 = in2[69] * in2[69];
  t6 = ((t2 + t3) + t4) + t5;
  t7 = 1.0 / t6;
  t120 = in2[67] * in2[68];
  t8 = t120 * t7 * 2.0;
  t9 = t2 * t7;
  t10 = t3 * t7;
  t58 = in2[66] * in2[68];
  t11 = t58 * t7 * 2.0;
  t102 = in2[67] * in2[69];
  t12 = t102 * t7 * 2.0;
  t13_tmp = in2[68] * in2[69];
  t13 = t13_tmp * t7 * 2.0;
  t14 = t4 * t7;
  st.site = &e_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t15 = in2[3] * in2[3];
  st.site = &f_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t16 = in2[4] * in2[4];
  st.site = &g_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t17 = in2[5] * in2[5];
  st.site = &h_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t18 = in2[6] * in2[6];
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
  t27_tmp = in2[3] * in2[4];
  t27 = t27_tmp * in2[69] * t20 * t21 * 2.0;
  t399 = in2[3] * in2[5];
  t28 = t399 * in2[67] * t20 * t21 * 2.0;
  t29 = t22 - t17 * t20;
  t31 = t22 - t18 * t20;
  t32_tmp = in2[3] * in2[6];
  t32 = t32_tmp * in2[68] * t20 * t21 * 2.0;
  t400 = in2[4] * in2[6];
  t34 = t400 * in2[68] * t20 * t21 * 2.0;
  t35 = t5 * t7;
  t15 = in2[66] * in2[69];
  t36_tmp = t15 * t7 * 2.0;
  t19 = in2[66] * in2[67];
  t37_tmp = t19 * t7 * 2.0;
  t38 = in2[0] - in2[63];
  t39 = in2[1] - in2[64];
  st.site = &l_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  if (t6 < 0.0) {
    c_st.site = &x_emlrtRSI;
    error(&c_st);
  }

  t40 = 1.0 / muDoubleScalarPower(t6, 1.5);
  t41 = in2[2] - in2[65];
  t44_tmp = in2[66] * t21;
  b_t44_tmp = in2[69] * t21;
  c_t44_tmp = in2[68] * t21;
  t44 = (t44_tmp * t38 + b_t44_tmp * t39) - c_t44_tmp * t41;
  t47_tmp = in2[67] * t21;
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
  t78 = in2[4] * t22 - t47_tmp;
  t80 = in2[5] * t22 - c_t44_tmp;
  t82 = t21 - t53_tmp;
  st.site = &m_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t83 = 1.0 / (t6 * t6);
  t85 = in2[3] * t22 - t44_tmp;
  t88 = in2[6] * t22 - b_t44_tmp;
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
  t153 = t149 * 0.077 + t150 * 0.036;
  t156 = t149 * 0.036 - t150 * 0.077;
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
  t205 = muDoubleScalarPower(muDoubleScalarAbs(((((((((t176 * in2[178] + t182 *
    in2[179]) + t191 * in2[180]) + t197 * in2[181]) + t169 * in2[114]) + t168 *
    in2[176]) + t170 * in2[175]) - t168 * in2[113]) - t169 * in2[177]) - t170 *
    in2[112]), in1[1] - 1.0);
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
  t251 = muDoubleScalarPower(muDoubleScalarAbs(((((((((t225 * in2[178] + t230 *
    in2[179]) + t236 * in2[180]) + t244 * in2[181]) + t217 * in2[112]) + t218 *
    in2[177]) + t219 * in2[176]) - t218 * in2[114]) - t217 * in2[175]) - t219 *
    in2[113]), in1[1] - 1.0);
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
  t295 = muDoubleScalarPower(muDoubleScalarAbs(((((((((t270 * in2[178] + t277 *
    in2[179]) + t282 * in2[180]) + t288 * in2[181]) + t264 * in2[113]) + t263 *
    in2[175]) + t265 * in2[177]) - t263 * in2[112]) - t264 * in2[176]) - t265 *
    in2[114]), in1[1] - 1.0);
  t13_tmp = t59_tmp * t80 * 2.0;
  t302 = (((((t130 + t132) + t47_tmp * t82 * 2.0) + in2[67] * t2 * t83 * 2.0) +
           t74_tmp * t85 * 2.0) - t53_tmp * t78 * 2.0) - t13_tmp;
  t99 = t100_tmp * t85 * 2.0;
  t304_tmp = t407 * t80 * 2.0;
  t54 = t119_tmp * t88 * 2.0;
  t309 = (((((t111 + t142) - t6) + c_t44_tmp * t144 * 2.0) + in2[68] * t5 * t83 *
           2.0) + t116_tmp * t88 * 2.0) - t406 * t80 * 2.0;
  t310_tmp = t399 * in2[69] * t20 * t21 * 2.0;
  t76 = t44_tmp * t25 * 2.0;
  t48 = t27_tmp * in2[67] * t20 * t21 * 2.0;
  t117 = in2[4] * in2[5];
  t49 = t117 * in2[69] * t20 * t21 * 2.0;
  t59 = t117 * in2[66] * t20 * t21 * 2.0;
  t19 = in2[5] * in2[6];
  t316 = ((t28 + b_t44_tmp * t29 * 2.0) + t19 * in2[68] * t20 * t21 * 2.0) - t59;
  t40 = t32_tmp * in2[67] * t20 * t21 * 2.0;
  t321_tmp = t21 * t85 * 2.0;
  t51 = in2[66] * t3 * t83 * 2.0;
  t432 = t44_tmp * t109 * 2.0;
  t436 = t74_tmp * t78 * 2.0;
  t325 = (((((-t129 - t99) + t304_tmp) + t321_tmp) + t432) + t51) + t436;
  t328_tmp = t408 * t78 * 2.0;
  t428 = in2[69] * t4 * t83 * 2.0;
  t427 = b_t44_tmp * t128 * 2.0;
  t330_tmp = t116_tmp * t80 * 2.0;
  t330 = (((((t108 - t127) - t54) + t427) + t428) + t328_tmp) + t330_tmp;
  t335_tmp = t47_tmp * t23 * 2.0;
  b_t335_tmp = t27_tmp * in2[66] * t20 * t21 * 2.0;
  t335 = ((-t32 + t310_tmp) + t335_tmp) + b_t335_tmp;
  t336 = ((t34 + t76) + t48) - t49;
  t341_tmp = t400 * in2[66] * t20 * t21 * 2.0;
  t343_tmp = c_t44_tmp * t31 * 2.0;
  b_t343_tmp = t19 * in2[69] * t20 * t21 * 2.0;
  t343 = ((-t40 + t343_tmp) + t341_tmp) + b_t343_tmp;
  st.site = &s_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t346 = muDoubleScalarPower(muDoubleScalarAbs(((((((t302 * in2[178] + t309 *
    in2[181]) + t336 * in2[116]) + t316 * in2[117]) - t325 * in2[179]) - t330 *
    in2[180]) - t335 * in2[115]) - t343 * in2[118]), in1[1] - 1.0);
  t98 = t74_tmp * t88 * 2.0;
  t354 = (((((t111 + t6) + c_t44_tmp * t82 * 2.0) + in2[68] * t2 * t83 * 2.0) +
           t408 * t85 * 2.0) - t53_tmp * t80 * 2.0) - t98;
  t355 = t119_tmp * t85 * 2.0;
  t359 = (((((t108 - t110) + t127) + b_t44_tmp * t109 * 2.0) + in2[69] * t3 *
           t83 * 2.0) + t407 * t78 * 2.0) - t100_tmp * t88 * 2.0;
  t360 = t406 * t78 * 2.0;
  t116_tmp = t27_tmp * in2[68] * t20 * t21 * 2.0;
  t362 = t44_tmp * t29 * 2.0;
  t363 = t399 * in2[68] * t20 * t21 * 2.0;
  t6 = t19 * in2[67] * t20 * t21 * 2.0;
  t389_tmp = t19 * in2[66] * t20 * t21 * 2.0;
  t367 = ((t32 + t47_tmp * t31 * 2.0) + t400 * in2[69] * t20 * t21 * 2.0) -
    t389_tmp;
  t74_tmp = in2[66] * t4 * t83 * 2.0;
  t27_tmp = t44_tmp * t128 * 2.0;
  t22 = t408 * t80 * 2.0;
  t374 = (((((t129 - t147) + t321_tmp) - t355) + t27_tmp) + t74_tmp) + t22;
  t55 = in2[67] * t5 * t83 * 2.0;
  t72 = t47_tmp * t144 * 2.0;
  t17 = t407 * t88 * 2.0;
  t380 = (((((t130 - t145) + t13_tmp) - t360) + t72) + t55) + t17;
  t18 = c_t44_tmp * t23 * 2.0;
  t15 = t399 * in2[66] * t20 * t21 * 2.0;
  t383 = ((-t27 + t40) + t18) + t15;
  t16 = b_t44_tmp * t25 * 2.0;
  t19 = t400 * in2[67] * t20 * t21 * 2.0;
  t386 = ((t59 - t116_tmp) + t16) + t19;
  t387 = ((t49 + t362) + t363) - t6;
  st.site = &t_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t393 = muDoubleScalarPower(muDoubleScalarAbs(((((((t354 * in2[178] + t359 *
    in2[179]) + t387 * in2[117]) + t367 * in2[118]) - t374 * in2[180]) - t380 *
    in2[181]) - t383 * in2[115]) - t386 * in2[116]), in1[1] - 1.0);
  t56 = b_t44_tmp * t82 * 2.0;
  t399 = in2[69] * t2 * t83 * 2.0;
  t400 = t59_tmp * t85 * 2.0;
  t53 = t100_tmp * t80 * 2.0;
  t132 = (((((t130 - t132) + t145) + t47_tmp * t128 * 2.0) + in2[67] * t4 * t83 *
           2.0) + t107_tmp * t80 * 2.0) - t119_tmp * t78 * 2.0;
  t406 = t406 * t85 * 2.0;
  t407 = c_t44_tmp * t25 * 2.0;
  t408 = t117 * in2[67] * t20 * t21 * 2.0;
  t128 = ((-t34 + t6) + t44_tmp * t31 * 2.0) + t32_tmp * in2[69] * t20 * t21 *
    2.0;
  out1[0] = ((t9 + t10) - t4 * t7) - t5 * t7;
  out1[1] = t168;
  out1[2] = -t11 + t12;
  memset(&out1[3], 0, 60U * sizeof(real_T));
  out1[63] = ((-t9 - t10) + t14) + t35;
  out1[64] = -t8 - t36_tmp;
  out1[65] = t169;
  out1[66] = (((((((t122 + t126) + t58) + t160) - t176_tmp) - b_t176_tmp) -
               c_t176_tmp) - t175_tmp) - d_t176_tmp;
  out1[67] = (((((((t113 + t121) + t161) + t162) - t182_tmp) - b_t182_tmp) -
               c_t182_tmp) - d_t182_tmp) - t163_tmp;
  out1[68] = (((((((-t92 + t164) - t191_tmp) - b_t191_tmp) - c_t191_tmp) -
                d_t191_tmp) - t188_tmp) - e_t191_tmp) - t189_tmp;
  out1[69] = (((((((t104 - t133) + t165) + t166) + t167) - t197_tmp) -
               b_t197_tmp) - c_t197_tmp) - t196_tmp;
  memset(&out1[70], 0, 36U * sizeof(real_T));
  out1[106] = t8 - t36_tmp;
  out1[107] = ((t9 - t10) + t14) - t5 * t7;
  out1[108] = t218;
  memset(&out1[109], 0, 60U * sizeof(real_T));
  out1[169] = t217;
  t58 = -t9 + t10;
  out1[170] = (t58 - t14) + t35;
  out1[171] = -t13 - t37_tmp;
  out1[172] = (((((((t104 + t133) + t209) + t210) - t225_tmp) - b_t225_tmp) -
                c_t225_tmp) - t223_tmp) - d_t225_tmp;
  out1[173] = (((((((t92 - t103) + t211) + t212) + t213) - t230_tmp) -
                b_t230_tmp) - c_t230_tmp) - t189_tmp;
  out1[174] = (((((((t113 - t121) + t141) + t214) + t215) - t236_tmp) -
                b_t236_tmp) - c_t236_tmp) - d_t236_tmp;
  out1[175] = (((((((-t122 + t216) - t244_tmp) - b_t244_tmp) - c_t244_tmp) -
                 d_t244_tmp) - t175_tmp) - e_t244_tmp) - t243_tmp;
  memset(&out1[176], 0, 36U * sizeof(real_T));
  out1[212] = t263;
  out1[213] = t13 - t37_tmp;
  out1[214] = t265;
  memset(&out1[215], 0, 60U * sizeof(real_T));
  out1[275] = -t11 - t12;
  out1[276] = t264;
  out1[277] = (t58 + t14) - t35;
  out1[278] = (((((((t92 + t103) + t255) + t256) - t270_tmp) - b_t270_tmp) -
                c_t270_tmp) - t188_tmp) - d_t270_tmp;
  out1[279] = (((((((-t104 + t257) - t277_tmp) - b_t277_tmp) - t50) - t94) -
                t100) - t223_tmp) - t196_tmp;
  out1[280] = (((((((t122 - t126) + t258) + t259) + t260) - t102) - t120) - t60)
    - t243_tmp;
  out1[281] = (((((((t113 - t141) + t163_tmp) + t261) + t262) - t412) - t288_tmp)
               - b_t288_tmp) - c_t288_tmp;
  memset(&out1[282], 0, 39U * sizeof(real_T));
  out1[321] = ((t32 - t335_tmp) - b_t335_tmp) - t310_tmp;
  out1[322] = ((t34 + t76) + t48) - in2[4] * in2[5] * in2[69] * t20 * t21 * 2.0;
  out1[323] = t316;
  out1[324] = ((t40 - t343_tmp) - t341_tmp) - b_t343_tmp;
  memset(&out1[325], 0, 59U * sizeof(real_T));
  out1[384] = t302;
  out1[385] = (((((t129 + t99) - t321_tmp) - t51) - t432) - t436) - t304_tmp;
  out1[386] = (((((-t108 + t127) + t54) - t428) - t427) - t328_tmp) - t330_tmp;
  out1[387] = t309;
  memset(&out1[388], 0, 39U * sizeof(real_T));
  out1[427] = ((t27 - t18) - t15) - t40;
  out1[428] = ((t116_tmp - t16) - t59) - t19;
  out1[429] = ((t49 + t362) + t363) - in2[5] * in2[6] * in2[67] * t20 * t21 *
    2.0;
  out1[430] = t367;
  memset(&out1[431], 0, 59U * sizeof(real_T));
  out1[490] = t354;
  out1[491] = t359;
  out1[492] = (((((-t129 + t147) + t355) - t321_tmp) - t74_tmp) - t27_tmp) - t22;
  out1[493] = (((((-t130 + t145) + t360) - t55) - t72) - t13_tmp) - t17;
  memset(&out1[494], 0, 39U * sizeof(real_T));
  t58 = b_t44_tmp * t23 * 2.0;
  t102 = t32_tmp * in2[66] * t20 * t21 * 2.0;
  out1[533] = ((t28 - t58) - t116_tmp) - t102;
  out1[534] = ((t27 + t407) + t408) - t341_tmp;
  t72 = t47_tmp * t29 * 2.0;
  t55 = t117 * in2[68] * t20 * t21 * 2.0;
  out1[535] = ((t310_tmp - t72) - t55) - t389_tmp;
  out1[536] = t128;
  memset(&out1[537], 0, 59U * sizeof(real_T));
  t120 = t108 + t110;
  t6 = t53_tmp * t88 * 2.0;
  out1[596] = ((((t120 + t56) + t399) + t400) - t6) - t328_tmp;
  t22 = c_t44_tmp * t109 * 2.0;
  t18 = in2[68] * t3 * t83 * 2.0;
  t16 = t107_tmp * t78 * 2.0;
  out1[597] = (((((-t111 + t142) + t53) - t18) - t22) - t16) - t98;
  out1[598] = t132;
  t17 = t44_tmp * t144 * 2.0;
  t15 = in2[66] * t5 * t83 * 2.0;
  t19 = t59_tmp * t88 * 2.0;
  out1[599] = (((((-t147 + t304_tmp) + t406) - t321_tmp) - t15) - t17) - t19;
  memset(&out1[600], 0, 36U * sizeof(real_T));
  t412 = ((((t120 - t328_tmp) + t56) + t399) + t400) - t6;
  t400 = (((((t111 - t142) + t98) - t53) + t22) + t18) + t16;
  t399 = (((((t147 - t304_tmp) + t321_tmp) - t406) + t17) + t15) + t19;
  t427 = ((-t28 + t116_tmp) + t58) + t102;
  t428 = ((t27 - t341_tmp) + t407) + t408;
  t432 = ((-t310_tmp + t389_tmp) + t72) + t55;
  st.site = &u_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  t436 = muDoubleScalarPower(muDoubleScalarAbs(((((((t412 * in2[178] + t132 *
    in2[180]) + t428 * in2[116]) + t128 * in2[118]) - t400 * in2[179]) - t399 *
    in2[181]) - t427 * in2[115]) - t432 * in2[117]), in1[1] - 1.0);
  out2[0] = in1[0] * ((((((t149 * t150 * 0.154 - t150 * t153) + t149 * t156) +
    t44_tmp * t44) + b_t44_tmp * t47) - c_t44_tmp * t64) + t47_tmp * t68) *
    -0.00026666666666666668;
  out2[1] = in1[0] * (((((t157 * 0.033825825826023878 + t158 *
    0.033825825826023878) - t44_tmp * t47) + b_t44_tmp * t44) - t47_tmp * t64) -
                      c_t44_tmp * t68) * 0.00026666666666666668;
  t19 = ((t157 * -0.077 + t149 * t153) + t150 * t156) + t158 * 0.077;
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
  out3[0] = ((((((((t72 * in2[113] - t120 * in2[112]) + t55 * in2[114]) +
                  t13_tmp * in2[176]) + t120 * in2[175]) - t55 * in2[177]) + t99
               * in2[178]) + t54 * in2[179]) + t76 * in2[180]) + t48 * in2[181];
  t49 = in1[2] * t217 * t251;
  t59 = in1[2] * t218 * t251;
  t40 = in1[2] * t219 * t251;
  t51 = in1[2] * t225 * t251;
  t53 = in1[2] * t230 * t251;
  t56 = in1[2] * t236 * t251;
  t60 = in1[2] * t244 * t251;
  out3[1] = ((((((((t49 * in2[112] - t59 * in2[114]) - t40 * in2[113]) - t49 *
                  in2[175]) + t59 * in2[177]) + t40 * in2[176]) + t51 * in2[178])
              + t53 * in2[179]) + t56 * in2[180]) + t60 * in2[181];
  t117 = in1[2] * t264 * t295;
  t94 = in1[2] * t265 * t295;
  t100 = -in1[2] * t263 * t295;
  t50 = in1[2] * t263 * t295;
  t98 = in1[2] * t270 * t295;
  t116_tmp = in1[2] * t277 * t295;
  t74_tmp = in1[2] * t282 * t295;
  t27_tmp = in1[2] * t288 * t295;
  out3[2] = ((((((((t100 * in2[112] + t117 * in2[113]) - t94 * in2[114]) + t50 *
                  in2[175]) - t117 * in2[176]) + t94 * in2[177]) + t98 * in2[178])
              + t116_tmp * in2[179]) + t74_tmp * in2[180]) + t27_tmp * in2[181];
  t362 = in1[3] * t335 * t346;
  t363 = -in1[3] * t316 * t346;
  t355 = in1[3] * t343 * t346;
  t360 = in1[3] * t325 * t346;
  t406 = in1[3] * t330 * t346;
  out3[3] = ((((((t363 * in2[117] + t362 * in2[115]) - in1[3] * t336 * t346 *
                 in2[116]) + t355 * in2[118]) - in1[3] * t302 * t346 * in2[178])
              - in1[3] * t309 * t346 * in2[181]) + t360 * in2[179]) + t406 *
    in2[180];
  t407 = in1[3] * t383 * t393;
  t408 = in1[3] * t386 * t393;
  t330_tmp = -in1[3] * t367 * t393;
  t335_tmp = in1[3] * t374 * t393;
  b_t335_tmp = in1[3] * t380 * t393;
  out3[4] = ((((((t330_tmp * in2[118] + t407 * in2[115]) + t408 * in2[116]) -
                in1[3] * t387 * t393 * in2[117]) - in1[3] * t354 * t393 * in2
               [178]) - in1[3] * t359 * t393 * in2[179]) + t335_tmp * in2[180])
    + b_t335_tmp * in2[181];
  t343_tmp = in1[3] * t427 * t436;
  b_t343_tmp = in1[3] * t432 * t436;
  t288_tmp = -in1[3] * t128 * t436;
  b_t288_tmp = in1[3] * t400 * t436;
  c_t288_tmp = in1[3] * t399 * t436;
  out3[5] = ((((((t288_tmp * in2[118] + t343_tmp * in2[115]) - in1[3] * t428 *
                 t436 * in2[116]) + b_t343_tmp * in2[117]) - in1[3] * t132 *
               t436 * in2[180]) - in1[3] * t412 * t436 * in2[178]) + b_t288_tmp *
             in2[179]) + c_t288_tmp * in2[181];
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
  out6[0] = t102;
  t16 = in1[0] * t217;
  out6[1] = t16 * -0.00026666666666666668;
  out6[2] = t17;
  out6[3] = 0.0;
  out6[4] = 0.0;
  out6[5] = 0.0;
  out6[6] = t58;
  out6[7] = t6;
  t15 = in1[0] * t264;
  out6[8] = t15 * -0.0008;
  out6[9] = 0.0;
  out6[10] = 0.0;
  out6[11] = 0.0;
  t19 = in1[0] * t169;
  out6[12] = t19 * -0.00026666666666666668;
  out6[13] = t22;
  out6[14] = t18;
  out6[15] = 0.0;
  out6[16] = 0.0;
  out6[17] = 0.0;
  out6[18] = 0.0;
  out6[19] = 0.0;
  out6[20] = 0.0;
  out6[21] = in1[0] * t335 * -4.2666666666666668E-11;
  out6[22] = in1[0] * t383 * -1.421066666666666E-8;
  out6[23] = in1[0] * t427 * -4.75111111111111E-9;
  out6[24] = 0.0;
  out6[25] = 0.0;
  out6[26] = 0.0;
  out6[27] = in1[0] * t336 * 4.2666666666666668E-11;
  out6[28] = in1[0] * t386 * -1.421066666666666E-8;
  out6[29] = in1[0] * t428 * 4.75111111111111E-9;
  out6[30] = 0.0;
  out6[31] = 0.0;
  out6[32] = 0.0;
  out6[33] = in1[0] * t316 * 4.2666666666666668E-11;
  out6[34] = in1[0] * t387 * 1.421066666666666E-8;
  out6[35] = in1[0] * t432 * -4.75111111111111E-9;
  out6[36] = 0.0;
  out6[37] = 0.0;
  out6[38] = 0.0;
  out6[39] = in1[0] * t343 * -4.2666666666666668E-11;
  out6[40] = in1[0] * t367 * 1.421066666666666E-8;
  out6[41] = in1[0] * t128 * 4.75111111111111E-9;
  memset(&out6[42], 0, 336U * sizeof(real_T));
  out6[378] = -t102;
  out6[379] = t16 * 0.00026666666666666668;
  out6[380] = -t17;
  out6[381] = 0.0;
  out6[382] = 0.0;
  out6[383] = 0.0;
  out6[384] = -t58;
  out6[385] = -t6;
  out6[386] = t15 * 0.0008;
  out6[387] = 0.0;
  out6[388] = 0.0;
  out6[389] = 0.0;
  out6[390] = t19 * 0.00026666666666666668;
  out6[391] = -t22;
  out6[392] = -t18;
  out6[393] = 0.0;
  out6[394] = 0.0;
  out6[395] = 0.0;
  out6[396] = in1[0] * t176 * -0.00026666666666666668;
  out6[397] = in1[0] * t225 * -0.00026666666666666668;
  out6[398] = in1[0] * t270 * -0.0008;
  out6[399] = in1[0] * t302 * 4.2666666666666668E-11;
  out6[400] = in1[0] * t354 * 1.421066666666666E-8;
  out6[401] = in1[0] * t412 * 4.75111111111111E-9;
  out6[402] = in1[0] * t182 * -0.00026666666666666668;
  out6[403] = in1[0] * t230 * -0.00026666666666666668;
  out6[404] = in1[0] * t277 * -0.0008;
  out6[405] = in1[0] * t325 * -4.2666666666666668E-11;
  out6[406] = in1[0] * t359 * 1.421066666666666E-8;
  out6[407] = in1[0] * t400 * -4.75111111111111E-9;
  out6[408] = in1[0] * t191 * -0.00026666666666666668;
  out6[409] = in1[0] * t236 * -0.00026666666666666668;
  out6[410] = in1[0] * t282 * -0.0008;
  out6[411] = in1[0] * t330 * -4.2666666666666668E-11;
  out6[412] = in1[0] * t374 * -1.421066666666666E-8;
  out6[413] = in1[0] * t132 * 4.75111111111111E-9;
  out6[414] = in1[0] * t197 * -0.00026666666666666668;
  out6[415] = in1[0] * t244 * -0.00026666666666666668;
  out6[416] = in1[0] * t288 * -0.0008;
  out6[417] = in1[0] * t309 * 4.2666666666666668E-11;
  out6[418] = in1[0] * t380 * -1.421066666666666E-8;
  out6[419] = in1[0] * t399 * -4.75111111111111E-9;
  memset(&out6[420], 0, 216U * sizeof(real_T));
  out7[0] = -in1[2] * t170 * t205;
  out7[1] = t49;
  out7[2] = t100;
  out7[3] = 0.0;
  out7[4] = 0.0;
  out7[5] = 0.0;
  out7[6] = t72;
  out7[7] = -in1[2] * t219 * t251;
  out7[8] = t117;
  out7[9] = 0.0;
  out7[10] = 0.0;
  out7[11] = 0.0;
  out7[12] = t55;
  out7[13] = -in1[2] * t218 * t251;
  out7[14] = -in1[2] * t265 * t295;
  out7[15] = 0.0;
  out7[16] = 0.0;
  out7[17] = 0.0;
  out7[18] = 0.0;
  out7[19] = 0.0;
  out7[20] = 0.0;
  out7[21] = t362;
  out7[22] = t407;
  out7[23] = t343_tmp;
  out7[24] = 0.0;
  out7[25] = 0.0;
  out7[26] = 0.0;
  out7[27] = -in1[3] * t336 * t346;
  out7[28] = t408;
  out7[29] = -in1[3] * t428 * t436;
  out7[30] = 0.0;
  out7[31] = 0.0;
  out7[32] = 0.0;
  out7[33] = t363;
  out7[34] = -in1[3] * t387 * t393;
  out7[35] = b_t343_tmp;
  out7[36] = 0.0;
  out7[37] = 0.0;
  out7[38] = 0.0;
  out7[39] = t355;
  out7[40] = t330_tmp;
  out7[41] = t288_tmp;
  memset(&out7[42], 0, 336U * sizeof(real_T));
  out7[378] = t120;
  out7[379] = -t49;
  out7[380] = t50;
  out7[381] = 0.0;
  out7[382] = 0.0;
  out7[383] = 0.0;
  out7[384] = t13_tmp;
  out7[385] = t40;
  out7[386] = -t117;
  out7[387] = 0.0;
  out7[388] = 0.0;
  out7[389] = 0.0;
  out7[390] = -t55;
  out7[391] = t59;
  out7[392] = t94;
  out7[393] = 0.0;
  out7[394] = 0.0;
  out7[395] = 0.0;
  out7[396] = t99;
  out7[397] = t51;
  out7[398] = t98;
  out7[399] = -in1[3] * t302 * t346;
  out7[400] = -in1[3] * t354 * t393;
  out7[401] = -in1[3] * t412 * t436;
  out7[402] = t54;
  out7[403] = t53;
  out7[404] = t116_tmp;
  out7[405] = t360;
  out7[406] = -in1[3] * t359 * t393;
  out7[407] = b_t288_tmp;
  out7[408] = t76;
  out7[409] = t56;
  out7[410] = t74_tmp;
  out7[411] = t406;
  out7[412] = t335_tmp;
  out7[413] = -in1[3] * t132 * t436;
  out7[414] = t48;
  out7[415] = t60;
  out7[416] = t27_tmp;
  out7[417] = -in1[3] * t309 * t346;
  out7[418] = b_t335_tmp;
  out7[419] = c_t288_tmp;
  memset(&out7[420], 0, 216U * sizeof(real_T));
  *out8 = 1.0;
}

/* End of code generation (sprdmpF108.c) */
