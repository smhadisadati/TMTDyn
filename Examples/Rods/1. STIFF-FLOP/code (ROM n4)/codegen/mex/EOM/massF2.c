/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * massF2.c
 *
 * Code generation for function 'massF2'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "EOM.h"
#include "massF2.h"
#include "error.h"
#include "sqrt.h"
#include "EOM_data.h"

/* Variable Definitions */
static emlrtRSInfo qc_emlrtRSI = { 39, /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/massF2.m"/* pathName */
};

static emlrtRSInfo rc_emlrtRSI = { 40, /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/massF2.m"/* pathName */
};

static emlrtRSInfo sc_emlrtRSI = { 48, /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/massF2.m"/* pathName */
};

static emlrtRSInfo tc_emlrtRSI = { 49, /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/massF2.m"/* pathName */
};

static emlrtRSInfo uc_emlrtRSI = { 65, /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/massF2.m"/* pathName */
};

static emlrtRSInfo vc_emlrtRSI = { 66, /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/massF2.m"/* pathName */
};

static emlrtRSInfo wc_emlrtRSI = { 67, /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/massF2.m"/* pathName */
};

static emlrtRSInfo xc_emlrtRSI = { 69, /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/massF2.m"/* pathName */
};

static emlrtRSInfo yc_emlrtRSI = { 70, /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/massF2.m"/* pathName */
};

static emlrtRSInfo ad_emlrtRSI = { 106,/* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/massF2.m"/* pathName */
};

static emlrtRSInfo bd_emlrtRSI = { 146,/* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/massF2.m"/* pathName */
};

/* Function Definitions */
void massF2(const emlrtStack *sp, const real_T in1[34], const real_T in2[48],
            real_T out1[36], real_T out2[144], real_T out3[144], real_T out4[6])
{
  real_T t2;
  real_T t3;
  real_T t9;
  real_T t10;
  real_T t15;
  real_T t20;
  real_T t25;
  real_T t26;
  real_T t27;
  real_T t28;
  real_T t29;
  real_T t30;
  real_T t230;
  real_T t32;
  real_T t33_tmp;
  real_T t33;
  real_T t34_tmp;
  real_T t34;
  real_T t35_tmp;
  real_T t35;
  real_T t36;
  real_T t396;
  real_T t397;
  real_T t398;
  real_T t40;
  real_T t41;
  real_T t42_tmp;
  real_T t42;
  real_T t43_tmp;
  real_T t385;
  real_T t43;
  real_T t393;
  real_T t44_tmp;
  real_T t44;
  real_T t392;
  real_T t388;
  real_T t45;
  real_T t46_tmp;
  real_T t46;
  real_T t387;
  real_T t390;
  real_T t47;
  real_T t48;
  real_T t49;
  real_T t50;
  real_T t51;
  real_T t52;
  real_T t53;
  real_T t54;
  real_T t55;
  real_T t56;
  real_T t57;
  real_T t58;
  real_T t59_tmp;
  real_T t59;
  real_T t60;
  real_T t380;
  real_T t61;
  real_T t62;
  real_T t378;
  real_T t63;
  real_T t391;
  real_T t271;
  real_T t133;
  real_T out2_tmp;
  real_T t251;
  real_T b_out2_tmp;
  real_T t400;
  real_T t269;
  real_T t260;
  real_T t166;
  real_T t401;
  real_T t249;
  real_T t239;
  real_T t237;
  real_T t64;
  real_T t66;
  real_T t68;
  real_T t69_tmp;
  real_T t70;
  real_T t73;
  real_T t76;
  real_T t79;
  real_T t82;
  real_T t85;
  real_T t88;
  real_T t91_tmp;
  real_T t92;
  real_T t95;
  real_T t98;
  real_T t100_tmp;
  real_T t101;
  real_T t102;
  real_T t105;
  real_T t108;
  real_T t109_tmp;
  real_T t111;
  real_T t114;
  real_T t117;
  real_T t120;
  real_T t123;
  real_T t126;
  real_T t129;
  real_T t132;
  real_T t135;
  real_T t138;
  real_T t139_tmp;
  real_T b_t139_tmp;
  real_T t141;
  real_T t144;
  real_T t146;
  real_T t148_tmp;
  real_T t151;
  real_T t153;
  real_T t155;
  real_T t157;
  real_T t160;
  real_T t161_tmp;
  real_T t162;
  real_T t164;
  real_T t165_tmp;
  real_T b_t165_tmp;
  real_T t168;
  real_T t170;
  real_T t173;
  real_T t176;
  real_T t179;
  real_T t181;
  real_T t183;
  real_T t185;
  real_T t188;
  real_T t190;
  real_T t193;
  real_T t195;
  real_T t197;
  real_T t199;
  real_T t200;
  real_T t201;
  real_T t202;
  real_T t203;
  real_T t205;
  real_T t207;
  real_T t209;
  real_T t211;
  real_T t213;
  real_T t215;
  real_T t216;
  real_T t218;
  real_T t220;
  real_T t223;
  real_T t226;
  real_T t229;
  real_T t232;
  real_T t235;
  real_T t238;
  real_T t241;
  real_T t242;
  real_T t244;
  real_T t245_tmp;
  real_T t245;
  real_T t247;
  real_T t250;
  real_T t253;
  real_T t254_tmp;
  real_T t254;
  real_T t256;
  real_T t259;
  real_T t262;
  real_T t263_tmp;
  real_T t263;
  real_T t265;
  real_T t266;
  real_T t267;
  real_T t268;
  real_T t270;
  real_T t272;
  real_T t274;
  real_T t276;
  real_T t278;
  real_T t280;
  real_T t281;
  real_T t282;
  real_T t283;
  real_T t287;
  real_T t289;
  real_T t290;
  real_T t293;
  real_T t295;
  real_T t296;
  real_T t297;
  real_T t298;
  real_T t299;
  real_T t300;
  real_T t302;
  real_T t303;
  real_T t304;
  real_T t305;
  real_T t306;
  real_T t308;
  real_T t310;
  real_T t312;
  real_T t313;
  real_T t314;
  real_T t315;
  real_T t316;
  real_T t319;
  real_T t320;
  real_T t321;
  real_T t322;
  real_T t324;
  real_T t325;
  real_T t326;
  real_T t327;
  real_T t329;
  real_T t333;
  real_T t334;
  real_T t335;
  real_T t337;
  real_T t338;
  real_T t339;
  real_T t340;
  real_T t341;
  real_T t343;
  real_T t345;
  real_T t347;
  real_T t349;
  real_T t351;
  real_T t353;
  real_T t355;
  real_T t357;
  real_T t359;
  real_T t360;
  real_T t362;
  real_T t363;
  real_T t365;
  real_T t367;
  real_T t369;
  real_T t370;
  real_T t371;
  real_T t372;
  real_T t374;
  real_T t375;
  real_T t377;
  real_T t379;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;

  /* MASSF2 */
  /*     [OUT1,OUT2,OUT3,OUT4] = MASSF2(IN1,IN2,S) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.2. */
  /*     05-Jan-2019 01:28:54 */
  st.site = &qc_emlrtRSI;
  b_st.site = &rb_emlrtRSI;
  t2 = in1[16] * in1[16];
  st.site = &rc_emlrtRSI;
  b_st.site = &rb_emlrtRSI;
  t3 = in1[17] * in1[17];
  t2 = in1[15] * (t2 + t3 * 3.0) / 12.0 + in1[15] * t2 / 4.0;
  out1[0] = in1[15];
  out1[1] = 0.0;
  out1[2] = 0.0;
  out1[3] = 0.0;
  out1[4] = 0.0;
  out1[5] = 0.0;
  out1[6] = 0.0;
  out1[7] = in1[15];
  out1[8] = 0.0;
  out1[9] = 0.0;
  out1[10] = 0.0;
  out1[11] = 0.0;
  out1[12] = 0.0;
  out1[13] = 0.0;
  out1[14] = in1[15];
  out1[15] = 0.0;
  out1[16] = 0.0;
  out1[17] = 0.0;
  out1[18] = 0.0;
  out1[19] = 0.0;
  out1[20] = 0.0;
  out1[21] = t2;
  out1[22] = 0.0;
  out1[23] = 0.0;
  out1[24] = 0.0;
  out1[25] = 0.0;
  out1[26] = 0.0;
  out1[27] = 0.0;
  out1[28] = t2;
  out1[29] = 0.0;
  out1[30] = 0.0;
  out1[31] = 0.0;
  out1[32] = 0.0;
  out1[33] = 0.0;
  out1[34] = 0.0;
  out1[35] = in1[15] * t3 / 2.0;
  st.site = &sc_emlrtRSI;
  b_st.site = &rb_emlrtRSI;
  t9 = in1[4] * in1[4];
  st.site = &tc_emlrtRSI;
  b_st.site = &rb_emlrtRSI;
  t10 = t9 * t9;
  t15 = ((in1[4] * in2[12] + in2[13] * t9) + in1[4] * in2[14] * t9) + in2[15] *
    t10;
  t20 = ((in1[4] * in2[16] + in2[17] * t9) + in1[4] * in2[18] * t9) + in2[19] *
    t10;
  t25 = ((in1[4] * in2[20] + in2[21] * t9) + in1[4] * in2[22] * t9) + in2[23] *
    t10;
  st.site = &uc_emlrtRSI;
  b_st.site = &rb_emlrtRSI;
  t26 = t15 * t15;
  st.site = &vc_emlrtRSI;
  b_st.site = &rb_emlrtRSI;
  t27 = t20 * t20;
  st.site = &wc_emlrtRSI;
  b_st.site = &rb_emlrtRSI;
  t28 = t25 * t25;
  t29 = ((-t26 - t27) - t28) + 1.0;
  t2 = t29;
  st.site = &xc_emlrtRSI;
  b_sqrt(&st, &t2);
  t30 = 1.0 / t2;
  t2 = t29;
  st.site = &yc_emlrtRSI;
  b_sqrt(&st, &t2);
  t230 = in1[16] * in1[4];
  t32 = t230 * t2;
  t33_tmp = in1[16] * t9;
  t33 = t33_tmp * t2;
  t34_tmp = t230 * t9;
  t34 = t34_tmp * t2;
  t35_tmp = in1[16] * t10;
  t35 = t35_tmp * t2;
  t36 = t230 * t25;
  t396 = t33_tmp * t25;
  t397 = t34_tmp * t25;
  t398 = t35_tmp * t25;
  t40 = in1[4] * t25 * 2.0;
  t3 = in1[4] * t15;
  t41 = t3 * t20 * t30 * 2.0;
  t42_tmp = t9 * t25;
  t42 = t42_tmp * 2.0;
  t43_tmp = t9 * t15;
  t385 = t43_tmp * t20;
  t43 = t385 * t30 * 2.0;
  t393 = in1[4] * t9;
  t44_tmp = t393 * t25;
  t44 = t44_tmp * 2.0;
  t392 = t393 * t15;
  t388 = t392 * t20;
  t45 = t388 * t30 * 2.0;
  t46_tmp = t10 * t25;
  t46 = t46_tmp * 2.0;
  t387 = t10 * t15;
  t390 = t387 * t20;
  t47 = t390 * t30 * 2.0;
  t48 = in1[4] * t2 * 2.0;
  t49 = t9 * t2 * 2.0;
  t50 = t393 * t2 * 2.0;
  t51 = t10 * t2 * 2.0;
  t52 = t3 * t25 * t30 * 2.0;
  t53 = t43_tmp * t25 * t30 * 2.0;
  t54 = t392 * t25 * t30 * 2.0;
  t55 = t387 * t25 * t30 * 2.0;
  t56 = t3 * 2.0;
  t2 = in1[4] * t20;
  t57 = t2 * t25 * t30 * 2.0;
  t58 = t43_tmp * 2.0;
  t59_tmp = t9 * t20;
  t59 = t59_tmp * t25 * t30 * 2.0;
  t60 = t392 * 2.0;
  t380 = t393 * t20;
  t61 = t380 * t25 * t30 * 2.0;
  t62 = t387 * 2.0;
  t378 = t10 * t20;
  t63 = t378 * t25 * t30 * 2.0;
  out2[0] = t9;
  out2[1] = 0.0;
  out2[2] = 0.0;
  out2[3] = 0.0;
  out2[4] = 0.0;
  out2[5] = 0.0;
  out2[6] = t393;
  out2[7] = 0.0;
  out2[8] = 0.0;
  out2[9] = 0.0;
  out2[10] = 0.0;
  out2[11] = 0.0;
  out2[12] = t10;
  out2[13] = 0.0;
  out2[14] = 0.0;
  out2[15] = 0.0;
  out2[16] = 0.0;
  out2[17] = 0.0;
  t391 = in1[4] * t10;
  out2[18] = t391;
  out2[19] = 0.0;
  out2[20] = 0.0;
  out2[21] = 0.0;
  out2[22] = 0.0;
  out2[23] = 0.0;
  out2[24] = 0.0;
  out2[25] = t9;
  out2[26] = 0.0;
  out2[27] = 0.0;
  out2[28] = 0.0;
  out2[29] = 0.0;
  out2[30] = 0.0;
  out2[31] = t393;
  out2[32] = 0.0;
  out2[33] = 0.0;
  out2[34] = 0.0;
  out2[35] = 0.0;
  out2[36] = 0.0;
  out2[37] = t10;
  out2[38] = 0.0;
  out2[39] = 0.0;
  out2[40] = 0.0;
  out2[41] = 0.0;
  out2[42] = 0.0;
  out2[43] = t391;
  out2[44] = 0.0;
  out2[45] = 0.0;
  out2[46] = 0.0;
  out2[47] = 0.0;
  out2[48] = 0.0;
  out2[49] = 0.0;
  out2[50] = t9;
  out2[51] = 0.0;
  out2[52] = 0.0;
  out2[53] = 0.0;
  out2[54] = 0.0;
  out2[55] = 0.0;
  out2[56] = t393;
  out2[57] = 0.0;
  out2[58] = 0.0;
  out2[59] = 0.0;
  out2[60] = 0.0;
  out2[61] = 0.0;
  out2[62] = t10;
  out2[63] = 0.0;
  out2[64] = 0.0;
  out2[65] = 0.0;
  out2[66] = 0.0;
  out2[67] = 0.0;
  out2[68] = t391;
  out2[69] = 0.0;
  out2[70] = 0.0;
  out2[71] = 0.0;
  t271 = t230 * t15;
  t133 = t271 * t20 * t30;
  out2[72] = t36 - t133;
  out2[73] = -t32 + t230 * t26 * t30;
  out2[74] = t271 * -2.0;
  out2[75] = t48 + in1[4] * t26 * t30 * 2.0;
  out2[76] = -t40 + t41;
  t2 *= 2.0;
  out2[77] = t52 + t2;
  out2_tmp = t33_tmp * t15;
  t251 = out2_tmp * t20;
  b_out2_tmp = t251 * t30;
  out2[78] = t396 - b_out2_tmp;
  out2[79] = -t33 + t33_tmp * t26 * t30;
  out2[80] = out2_tmp * -2.0;
  out2[81] = t49 + t9 * t26 * t30 * 2.0;
  out2[82] = -t42 + t43;
  t3 = t59_tmp * 2.0;
  out2[83] = t53 + t3;
  t400 = t34_tmp * t15;
  t269 = t400 * t20;
  t260 = t269 * t30;
  out2[84] = t397 - t260;
  out2[85] = -t34 + t34_tmp * t26 * t30;
  out2[86] = t400 * -2.0;
  out2[87] = t50 + t393 * t26 * t30 * 2.0;
  out2[88] = -t44 + t45;
  t166 = t380 * 2.0;
  out2[89] = t54 + t166;
  t401 = t35_tmp * t15;
  t249 = t401 * t20;
  t239 = t249 * t30;
  out2[90] = t398 - t239;
  out2[91] = -t35 + t35_tmp * t26 * t30;
  out2[92] = t401 * -2.0;
  out2[93] = t51 + t10 * t26 * t30 * 2.0;
  out2[94] = -t46 + t47;
  t237 = t378 * 2.0;
  out2[95] = t55 + t237;
  out2[96] = t32 - t230 * t27 * t30;
  out2[97] = t36 + t133;
  t133 = t230 * t20;
  out2[98] = t133 * -2.0;
  out2[99] = t40 + t41;
  out2[100] = t48 + in1[4] * t27 * t30 * 2.0;
  out2[101] = -t56 + t57;
  out2[102] = t33 - t33_tmp * t27 * t30;
  out2[103] = t396 + b_out2_tmp;
  b_out2_tmp = t33_tmp * t20;
  out2[104] = b_out2_tmp * -2.0;
  out2[105] = t42 + t43;
  out2[106] = t49 + t9 * t27 * t30 * 2.0;
  out2[107] = -t58 + t59;
  out2[108] = t34 - t34_tmp * t27 * t30;
  out2[109] = t397 + t260;
  t260 = t34_tmp * t20;
  out2[110] = t260 * -2.0;
  out2[111] = t44 + t45;
  out2[112] = t50 + t393 * t27 * t30 * 2.0;
  out2[113] = -t60 + t61;
  out2[114] = t35 - t35_tmp * t27 * t30;
  out2[115] = t398 + t239;
  t239 = t35_tmp * t20;
  out2[116] = t239 * -2.0;
  out2[117] = t46 + t47;
  out2[118] = t51 + t10 * t27 * t30 * 2.0;
  out2[119] = -t62 + t63;
  out2[120] = t271 - t133 * t25 * t30;
  out2[121] = t133 + t271 * t25 * t30;
  out2[122] = 0.0;
  out2[123] = t52 - t2;
  out2[124] = t56 + t57;
  out2[125] = t48 + in1[4] * t28 * t30 * 2.0;
  out2[126] = out2_tmp - b_out2_tmp * t25 * t30;
  out2[127] = b_out2_tmp + out2_tmp * t25 * t30;
  out2[128] = 0.0;
  out2[129] = t53 - t3;
  out2[130] = t58 + t59;
  out2[131] = t49 + t9 * t28 * t30 * 2.0;
  out2[132] = t400 - t260 * t25 * t30;
  out2[133] = t260 + t400 * t25 * t30;
  out2[134] = 0.0;
  out2[135] = t54 - t166;
  out2[136] = t60 + t61;
  out2[137] = t50 + t393 * t28 * t30 * 2.0;
  out2[138] = t401 - t239 * t25 * t30;
  out2[139] = t239 + t401 * t25 * t30;
  out2[140] = 0.0;
  out2[141] = t55 - t237;
  out2[142] = t62 + t63;
  out2[143] = t51 + t10 * t28 * t30 * 2.0;
  st.site = &ad_emlrtRSI;
  b_st.site = &rb_emlrtRSI;
  if (t29 < 0.0) {
    c_st.site = &sb_emlrtRSI;
    error(&c_st);
  }

  t64 = 1.0 / muDoubleScalarPower(t29, 1.5);
  t52 = t269 * t25 * t64;
  t66 = t34_tmp - t52;
  t53 = t249 * t25 * t64;
  t68 = t35_tmp - t53;
  t69_tmp = t230 * t10;
  t40 = t69_tmp * t15;
  t54 = t40 * t20 * t25 * t64;
  t70 = t69_tmp - t54;
  t35 = t400 * t30;
  t73 = t35 + t400 * t27 * t64;
  t36 = t401 * t30;
  t76 = t36 + t401 * t27 * t64;
  t41 = t40 * t30;
  t79 = t41 + t40 * t27 * t64;
  t2 = t260 * t30;
  t82 = t2 + t260 * t26 * t64;
  t3 = t239 * t30;
  t85 = t3 + t239 * t26 * t64;
  t166 = t69_tmp * t20;
  t237 = t166 * t30;
  t88 = t237 + t166 * t26 * t64;
  t91_tmp = t33_tmp * t10;
  t42 = t91_tmp * t15;
  t55 = t42 * t20 * t25 * t64;
  t92 = t91_tmp - t55;
  t43 = t42 * t30;
  t95 = t43 + t42 * t27 * t64;
  t56 = t91_tmp * t20;
  t57 = t56 * t30;
  t98 = t57 + t56 * t26 * t64;
  t100_tmp = t34_tmp * t10;
  t44 = t100_tmp * t15;
  t32 = t44 * t20 * t25 * t64;
  t101 = t100_tmp - t32;
  st.site = &bd_emlrtRSI;
  b_st.site = &rb_emlrtRSI;
  t102 = t10 * t10;
  t45 = t44 * t30;
  t105 = t45 + t44 * t27 * t64;
  t58 = t100_tmp * t20;
  t59 = t58 * t30;
  t108 = t59 + t58 * t26 * t64;
  t109_tmp = out2_tmp * t30;
  t111 = t109_tmp + out2_tmp * t27 * t64;
  t114 = t2 * 3.0 + t260 * t27 * t64;
  t117 = t3 * 3.0 + t239 * t27 * t64;
  t120 = t237 * 3.0 + t166 * t27 * t64;
  t60 = t397 * t30;
  t123 = t60 + t397 * t27 * t64;
  t61 = t398 * t30;
  t126 = t61 + t398 * t27 * t64;
  t62 = t69_tmp * t25;
  t63 = t62 * t30;
  t129 = t63 + t62 * t27 * t64;
  t132 = t57 * 3.0 + t56 * t27 * t64;
  t271 = t91_tmp * t25;
  t133 = t271 * t30;
  t135 = t133 + t271 * t27 * t64;
  t138 = t59 * 3.0 + t58 * t27 * t64;
  t139_tmp = in1[16] * t15;
  b_t139_tmp = t139_tmp * t30 * t102;
  t141 = b_t139_tmp + t139_tmp * t27 * t64 * t102;
  t269 = t100_tmp * t25;
  t51 = t269 * t30;
  t144 = t51 + t269 * t27 * t64;
  t33 = t251 * t25 * t64;
  t146 = t33_tmp - t33;
  t148_tmp = b_out2_tmp * t30;
  t34 = t396 * t30;
  t151 = t34 + t396 * t27 * t64;
  t153 = t2 + t260 * t28 * t64;
  t155 = t3 + t239 * t28 * t64;
  t157 = t237 + t166 * t28 * t64;
  t160 = t57 + t56 * t28 * t64;
  t161_tmp = in1[16] * t102;
  t2 = t139_tmp * t20 * t25 * t64 * t102;
  t162 = t161_tmp - t2;
  t164 = t59 + t58 * t28 * t64;
  t165_tmp = in1[16] * t20;
  b_t165_tmp = t165_tmp * t30 * t102;
  t3 = in1[16] * t25;
  t166 = t3 * t30 * t102;
  t168 = t166 + t3 * t27 * t64 * t102;
  t170 = t148_tmp + b_out2_tmp * t26 * t64;
  t173 = t35 * 3.0 + t400 * t26 * t64;
  t176 = t36 * 3.0 + t401 * t26 * t64;
  t179 = t41 * 3.0 + t40 * t26 * t64;
  t181 = t60 + t397 * t26 * t64;
  t183 = t61 + t398 * t26 * t64;
  t185 = t63 + t62 * t26 * t64;
  t188 = t43 * 3.0 + t42 * t26 * t64;
  t190 = t133 + t271 * t26 * t64;
  t193 = t45 * 3.0 + t44 * t26 * t64;
  t195 = b_t165_tmp + t165_tmp * t26 * t64 * t102;
  t197 = t51 + t269 * t26 * t64;
  t199 = t34_tmp + t52;
  t200 = t35_tmp + t53;
  t201 = t69_tmp + t54;
  t202 = t91_tmp + t55;
  t203 = t100_tmp + t32;
  t205 = t33_tmp + t33;
  t207 = t34 + t396 * t26 * t64;
  t209 = t35 + t400 * t28 * t64;
  t211 = t36 + t401 * t28 * t64;
  t213 = t41 + t40 * t28 * t64;
  t215 = t43 + t42 * t28 * t64;
  t216 = t161_tmp + t2;
  t218 = t45 + t44 * t28 * t64;
  t220 = t166 + t3 * t26 * t64 * t102;
  t48 = t392 * t30 * 2.0;
  t223 = t392 * t26 * t64 * 2.0 + t48;
  t49 = t387 * t30 * 2.0;
  t226 = t387 * t26 * t64 * 2.0 + t49;
  t51 = t391 * t15;
  t50 = t51 * t30 * 2.0;
  t229 = t51 * t26 * t64 * 2.0 + t50;
  t230 = t380 * t30 * 2.0;
  t2 = t380 * t26 * t64 * 2.0;
  t232 = t230 + t2;
  t133 = t378 * t30 * 2.0;
  t3 = t378 * t26 * t64 * 2.0;
  t235 = t133 + t3;
  t45 = t391 * t20;
  t166 = t45 * t30 * 2.0;
  t237 = t45 * t26 * t64 * 2.0;
  t238 = t166 + t237;
  t239 = t44_tmp * t30 * 2.0;
  t52 = t44_tmp * t26 * t64 * 2.0;
  t241 = t239 + t52;
  t242 = t46_tmp * t30 * 2.0;
  t53 = t46_tmp * t26 * t64 * 2.0;
  t244 = t242 + t53;
  t245_tmp = t391 * t25;
  t245 = t245_tmp * t30 * 2.0;
  t54 = t245_tmp * t26 * t64 * 2.0;
  t247 = t245 + t54;
  t56 = t9 * t10;
  t55 = t56 * t15;
  t249 = t55 * t30 * 2.0;
  t250 = t55 * t26 * t64 * 2.0 + t249;
  t46 = t56 * t20;
  t251 = t46 * t30 * 2.0;
  t57 = t46 * t26 * t64 * 2.0;
  t253 = t251 + t57;
  t254_tmp = t56 * t25;
  t254 = t254_tmp * t30 * 2.0;
  t32 = t254_tmp * t26 * t64 * 2.0;
  t256 = t254 + t32;
  t58 = t393 * t10;
  t33 = t58 * t15;
  t29 = t33 * t30 * 2.0;
  t259 = t33 * t26 * t64 * 2.0 + t29;
  t47 = t58 * t20;
  t260 = t47 * t30 * 2.0;
  t59 = t47 * t26 * t64 * 2.0;
  t262 = t260 + t59;
  t263_tmp = t58 * t25;
  t263 = t263_tmp * t30 * 2.0;
  t34 = t263_tmp * t26 * t64 * 2.0;
  t265 = t263 + t34;
  t266 = t43_tmp * t30 * 2.0;
  t267 = t59_tmp * t30 * 2.0;
  t268 = t59_tmp * t26 * t64 * 2.0;
  t269 = t393 * 2.0;
  t63 = t388 * t25 * t64 * 2.0;
  t270 = t269 - t63;
  t271 = t10 * 2.0;
  t60 = t390 * t25 * t64 * 2.0;
  t272 = t271 - t60;
  t61 = t391 * 2.0;
  t62 = t51 * t20 * t25 * t64 * 2.0;
  t274 = t61 - t62;
  t36 = t392 * t27 * t64 * 2.0;
  t276 = t48 + t36;
  t40 = t387 * t27 * t64 * 2.0;
  t278 = t49 + t40;
  t41 = t51 * t27 * t64 * 2.0;
  t280 = t50 + t41;
  t281 = t230 - t2;
  t282 = t133 - t3;
  t283 = t166 - t237;
  t2 = t56 * 2.0;
  t3 = t55 * t20 * t25 * t64 * 2.0;
  t287 = t2 - t3;
  t35 = t55 * t27 * t64 * 2.0;
  t289 = t249 + t35;
  t290 = t251 - t57;
  t56 = t58 * 2.0;
  t57 = t33 * t20 * t25 * t64 * 2.0;
  t293 = t56 - t57;
  t58 = t33 * t27 * t64 * 2.0;
  t295 = t29 + t58;
  t296 = t15 * t30 * t102 * 2.0;
  t297 = t260 - t59;
  t298 = t20 * t30 * t102 * 2.0;
  t299 = t20 * t26 * t64 * t102 * 2.0;
  t300 = t9 * 2.0;
  t302 = t42_tmp * t30 * 2.0;
  t303 = t42_tmp * t26 * t64 * 2.0;
  t304 = t269 + t63;
  t305 = t271 + t60;
  t306 = t61 + t62;
  t42 = t392 * t28 * t64 * 2.0;
  t308 = t48 + t42;
  t43 = t387 * t28 * t64 * 2.0;
  t310 = t49 + t43;
  t44 = t51 * t28 * t64 * 2.0;
  t312 = t50 + t44;
  t313 = t239 - t52;
  t314 = t242 - t53;
  t315 = t245 - t54;
  t316 = t2 + t3;
  t52 = t55 * t28 * t64 * 2.0;
  t319 = t249 + t52;
  t320 = t254 - t32;
  t321 = t56 + t57;
  t322 = t102 * 2.0;
  t51 = t33 * t28 * t64 * 2.0;
  t324 = t29 + t51;
  t325 = t263 - t34;
  t326 = t25 * t30 * t102 * 2.0;
  t327 = t25 * t26 * t64 * t102 * 2.0;
  t59 = t385 * t25 * t64 * 2.0;
  t329 = t300 + t59;
  t53 = t43_tmp * t27 * t64 * 2.0;
  t54 = t267 + t268;
  t55 = t48 - t36;
  t333 = t49 - t40;
  t334 = t50 - t41;
  t335 = t249 - t35;
  t60 = t15 * t20 * t25 * t64 * t102 * 2.0;
  t337 = t322 + t60;
  t338 = t29 - t58;
  t339 = t15 * t27 * t64 * t102 * 2.0;
  t340 = t298 + t299;
  t341 = t266 + t53;
  t343 = t230 + t380 * t27 * t64 * 2.0;
  t345 = t133 + t378 * t27 * t64 * 2.0;
  t347 = t166 + t45 * t27 * t64 * 2.0;
  t2 = t44_tmp * t27 * t64 * 2.0;
  t349 = t239 + t2;
  t3 = t46_tmp * t27 * t64 * 2.0;
  t351 = t242 + t3;
  t56 = t245_tmp * t27 * t64 * 2.0;
  t353 = t245 + t56;
  t355 = t251 + t46 * t27 * t64 * 2.0;
  t57 = t254_tmp * t27 * t64 * 2.0;
  t357 = t254 + t57;
  t359 = t260 + t47 * t27 * t64 * 2.0;
  t360 = t296 + t339;
  t58 = t263_tmp * t27 * t64 * 2.0;
  t362 = t263 + t58;
  t363 = t42_tmp * t27 * t64 * 2.0;
  t61 = t380 * t28 * t64 * 2.0;
  t365 = t230 + t61;
  t62 = t378 * t28 * t64 * 2.0;
  t367 = t133 + t62;
  t63 = t45 * t28 * t64 * 2.0;
  t369 = t166 + t63;
  t370 = t239 - t2;
  t371 = t242 - t3;
  t372 = t245 - t56;
  t3 = t46 * t28 * t64 * 2.0;
  t374 = t251 + t3;
  t375 = t254 - t57;
  t2 = t47 * t28 * t64 * 2.0;
  t377 = t260 + t2;
  t378 = t263 - t58;
  t379 = t25 * t27 * t64 * t102 * 2.0;
  t380 = t300 - t59;
  t56 = t43_tmp * t28 * t64 * 2.0;
  t57 = t302 + t303;
  t58 = t48 - t42;
  t59 = t49 - t43;
  t385 = t50 - t44;
  t30 = t249 - t52;
  t387 = t322 - t60;
  t388 = t29 - t51;
  t10 = t15 * t28 * t64 * t102 * 2.0;
  t390 = t326 + t327;
  t391 = t59_tmp * t28 * t64 * 2.0;
  t392 = t302 + t363;
  t393 = t230 - t61;
  t269 = t133 - t62;
  t271 = t166 - t63;
  t396 = t251 - t3;
  t397 = t260 - t2;
  t398 = t20 * t28 * t64 * t102 * 2.0;
  t237 = t326 + t379;
  t400 = t266 + t56;
  t401 = t267 + t391;
  t239 += t44_tmp * t28 * t64 * 2.0;
  t260 = t242 + t46_tmp * t28 * t64 * 2.0;
  t251 = t245 + t245_tmp * t28 * t64 * 2.0;
  t166 = t254 + t254_tmp * t28 * t64 * 2.0;
  t44 = t263 + t263_tmp * t28 * t64 * 2.0;
  t45 = t296 + t10;
  t46 = t298 + t398;
  memset(&out3[0], 0, 72U * sizeof(real_T));
  t47 = t73 * in2[41];
  t48 = t76 * in2[42];
  t49 = t82 * in2[37];
  t50 = t79 * in2[43];
  t249 = t85 * in2[38];
  t29 = t88 * in2[39];
  t230 = t111 * in2[40];
  t133 = t170 * in2[36];
  out3[72] = ((((((((((t66 * in2[45] + t68 * in2[46]) - t47) + t70 * in2[47]) -
                    t48) - t49) - t50) - t249) - t29) - t230) + t146 * in2[44])
    - t133;
  out3[73] = ((((((((((t82 * in2[41] + t85 * in2[42]) + t88 * in2[43]) + t170 *
                     in2[40]) + t173 * in2[37]) + t176 * in2[38]) + t179 * in2
                  [39]) + t181 * in2[45]) + t183 * in2[46]) + t185 * in2[47]) +
              t207 * in2[44]) + in2[36] * (t109_tmp * 3.0 + out2_tmp * t26 * t64);
  out3[74] = ((t33_tmp * in2[36] * -2.0 - t35_tmp * in2[38] * 2.0) - t34_tmp *
              in2[37] * 2.0) - t69_tmp * in2[39] * 2.0;
  out3[75] = ((((((((((t223 * in2[37] + t226 * in2[38]) + t229 * in2[39]) + t232
                     * in2[41]) + t235 * in2[42]) + t238 * in2[43]) + t241 *
                  in2[45]) + t244 * in2[46]) + t247 * in2[47]) + t54 * in2[40])
              + t57 * in2[44]) + in2[36] * (t266 + t43_tmp * t26 * t64 * 2.0);
  out3[76] = ((((((((((t232 * in2[37] + t235 * in2[38]) + t238 * in2[39]) + t304
                     * in2[45]) + t305 * in2[46]) + t306 * in2[47]) + t54 * in2
                  [36]) + t329 * in2[44]) - t55 * in2[41]) - t333 * in2[42]) -
              t334 * in2[43]) - in2[40] * (t266 - t53);
  out3[77] = ((((((((((t241 * in2[37] + t244 * in2[38]) + t247 * in2[39]) - t270
                     * in2[41]) - t272 * in2[42]) - t274 * in2[43]) + t57 * in2
                  [36]) - t380 * in2[40]) - t58 * in2[45]) - t59 * in2[46]) -
              t385 * in2[47]) - in2[44] * (t266 - t56);
  t33 = t73 * in2[40];
  t34 = t76 * in2[41];
  t35 = t82 * in2[36];
  t36 = t79 * in2[42];
  t40 = t85 * in2[37];
  t41 = t88 * in2[38];
  t42 = t98 * in2[39];
  t43 = t95 * in2[43];
  out3[78] = ((((((((((t66 * in2[44] + t68 * in2[45]) - t33) + t70 * in2[46]) -
                    t34) - t35) - t36) - t40) - t41) - t42) - t43) + t92 * in2
    [47];
  out3[79] = ((((((((((t82 * in2[40] + t85 * in2[41]) + t88 * in2[42]) + t98 *
                     in2[43]) + t173 * in2[36]) + t176 * in2[37]) + t179 * in2
                  [38]) + t181 * in2[44]) + t188 * in2[39]) + t183 * in2[45]) +
              t185 * in2[46]) + t190 * in2[47];
  out3[80] = ((t35_tmp * in2[37] * -2.0 - t34_tmp * in2[36] * 2.0) - t69_tmp *
              in2[38] * 2.0) - t91_tmp * in2[39] * 2.0;
  out3[81] = ((((((((((t223 * in2[36] + t226 * in2[37]) + t229 * in2[38]) + t232
                     * in2[40]) + t235 * in2[41]) + t238 * in2[42]) + t241 *
                  in2[44]) + t244 * in2[45]) + t250 * in2[39]) + t247 * in2[46])
              + t253 * in2[43]) + t256 * in2[47];
  out3[82] = ((((((((((t232 * in2[36] + t235 * in2[37]) + t238 * in2[38]) + t253
                     * in2[39]) + t304 * in2[44]) + t305 * in2[45]) + t306 *
                  in2[46]) + t316 * in2[47]) - t55 * in2[40]) - t333 * in2[41])
              - t334 * in2[42]) - t335 * in2[43];
  out3[83] = ((((((((((t241 * in2[36] + t244 * in2[37]) + t247 * in2[38]) + t256
                     * in2[39]) - t270 * in2[40]) - t272 * in2[41]) - t274 *
                  in2[42]) - t287 * in2[43]) - t58 * in2[44]) - t59 * in2[45]) -
              t385 * in2[46]) - t30 * in2[47];
  t62 = t76 * in2[40];
  t63 = t79 * in2[41];
  t51 = t85 * in2[36];
  t52 = t88 * in2[37];
  t53 = t98 * in2[38];
  t54 = t95 * in2[42];
  t55 = t108 * in2[39];
  t32 = t105 * in2[43];
  out3[84] = ((((((((((t68 * in2[44] + t70 * in2[45]) - t62) - t63) - t51) - t52)
                  - t53) - t54) + t92 * in2[46]) - t55) + t101 * in2[47]) - t32;
  out3[85] = ((((((((((t85 * in2[40] + t88 * in2[41]) + t98 * in2[42]) + t108 *
                     in2[43]) + t176 * in2[36]) + t179 * in2[37]) + t188 * in2
                  [38]) + t183 * in2[44]) + t185 * in2[45]) + t193 * in2[39]) +
              t190 * in2[46]) + t197 * in2[47];
  out3[86] = ((t35_tmp * in2[36] * -2.0 - t69_tmp * in2[37] * 2.0) - t91_tmp *
              in2[38] * 2.0) - t100_tmp * in2[39] * 2.0;
  out3[87] = ((((((((((t226 * in2[36] + t229 * in2[37]) + t235 * in2[40]) + t238
                     * in2[41]) + t244 * in2[44]) + t250 * in2[38]) + t247 *
                  in2[45]) + t253 * in2[42]) + t259 * in2[39]) + t256 * in2[46])
              + t262 * in2[43]) + t265 * in2[47];
  out3[88] = ((((((((((t235 * in2[36] + t238 * in2[37]) + t253 * in2[38]) + t262
                     * in2[39]) + t305 * in2[44]) + t306 * in2[45]) + t316 *
                  in2[46]) + t321 * in2[47]) - t333 * in2[40]) - t334 * in2[41])
              - t335 * in2[42]) - t338 * in2[43];
  out3[89] = ((((((((((t244 * in2[36] + t247 * in2[37]) + t256 * in2[38]) + t265
                     * in2[39]) - t272 * in2[40]) - t274 * in2[41]) - t287 *
                  in2[42]) - t293 * in2[43]) - t59 * in2[44]) - t385 * in2[45])
              - t30 * in2[46]) - t388 * in2[47];
  t2 = t79 * in2[40];
  t3 = t88 * in2[36];
  t56 = t98 * in2[37];
  t57 = t95 * in2[41];
  t58 = t108 * in2[38];
  t59 = t105 * in2[42];
  t60 = t141 * in2[43];
  t61 = t195 * in2[39];
  out3[90] = ((((((((((t70 * in2[44] - t2) - t3) - t56) - t57) + t92 * in2[45])
                  - t58) + t101 * in2[46]) - t59) - t60) + t162 * in2[47]) - t61;
  out3[91] = ((((((((((t88 * in2[40] + t98 * in2[41]) + t108 * in2[42]) + t179 *
                     in2[36]) + t188 * in2[37]) + t185 * in2[44]) + t193 * in2
                  [38]) + t190 * in2[45]) + t195 * in2[43]) + t197 * in2[46]) +
              t220 * in2[47]) + in2[39] * (b_t139_tmp * 3.0 + t139_tmp * t26 *
    t64 * t102);
  out3[92] = ((t161_tmp * in2[39] * -2.0 - t69_tmp * in2[36] * 2.0) - t91_tmp *
              in2[37] * 2.0) - t100_tmp * in2[38] * 2.0;
  out3[93] = ((((((((((t229 * in2[36] + t238 * in2[40]) + t250 * in2[37]) + t247
                     * in2[44]) + t253 * in2[41]) + t259 * in2[38]) + t256 *
                  in2[45]) + t262 * in2[42]) + t265 * in2[46]) + t340 * in2[43])
              + t390 * in2[47]) + in2[39] * (t296 + t15 * t26 * t64 * t102 * 2.0);
  out3[94] = ((((((((((t238 * in2[36] + t253 * in2[37]) + t262 * in2[38]) + t306
                     * in2[44]) + t316 * in2[45]) + t321 * in2[46]) - t334 *
                  in2[40]) - t335 * in2[41]) + t340 * in2[39]) - t338 * in2[42])
              + t337 * in2[47]) - in2[43] * (t296 - t339);
  out3[95] = ((((((((((t247 * in2[36] + t256 * in2[37]) + t265 * in2[38]) - t274
                     * in2[40]) - t287 * in2[41]) - t293 * in2[42]) - t385 *
                  in2[44]) + t390 * in2[39]) - t387 * in2[43]) - t30 * in2[45])
              - t388 * in2[46]) - in2[47] * (t296 - t10);
  out3[96] = ((((((((((-t73 * in2[37] - t76 * in2[38]) - t79 * in2[39]) - t111 *
                     in2[36]) - t114 * in2[41]) - t117 * in2[42]) - t120 * in2
                  [43]) - t123 * in2[45]) - t126 * in2[46]) - t129 * in2[47]) -
              t151 * in2[44]) - in2[40] * (t148_tmp * 3.0 + b_out2_tmp * t27 *
    t64);
  out3[97] = ((((((((((t47 + t48) + t49) + t50) + t249) + t29) + t230) + t133) +
                t199 * in2[45]) + t200 * in2[46]) + t201 * in2[47]) + t205 *
    in2[44];
  out3[98] = ((t33_tmp * in2[40] * -2.0 - t35_tmp * in2[42] * 2.0) - t34_tmp *
              in2[41] * 2.0) - t69_tmp * in2[43] * 2.0;
  out3[99] = ((((((((((-t270 * in2[45] + t276 * in2[41]) - t272 * in2[46]) -
                     t281 * in2[37]) + t278 * in2[42]) - t282 * in2[38]) - t274 *
                  in2[47]) - t283 * in2[39]) + t280 * in2[43]) + t341 * in2[40])
              - in2[44] * (t300 - t9 * t15 * t20 * t25 * t64 * 2.0)) - in2[36] *
    (t267 - t268);
  out3[100] = ((((((((((t276 * in2[37] + t278 * in2[38]) + t280 * in2[39]) +
                      t341 * in2[36]) + t343 * in2[41]) + t345 * in2[42]) + t347
                   * in2[43]) + t349 * in2[45]) + t351 * in2[46]) + t353 * in2
                [47]) + t392 * in2[44]) + in2[40] * (t267 + t59_tmp * t27 * t64 *
    2.0);
  out3[101] = ((((((((((t304 * in2[37] + t305 * in2[38]) + t306 * in2[39]) +
                      t329 * in2[36]) + t349 * in2[41]) + t351 * in2[42]) + t353
                   * in2[43]) + t392 * in2[40]) - t393 * in2[45]) - t269 * in2
                [46]) - t271 * in2[47]) - in2[44] * (t267 - t391);
  out3[102] = ((((((((((-t73 * in2[36] - t76 * in2[37]) - t79 * in2[38]) - t95 *
                      in2[39]) - t114 * in2[40]) - t117 * in2[41]) - t120 * in2
                   [42]) - t123 * in2[44]) - t126 * in2[45]) - t129 * in2[46]) -
               t132 * in2[43]) - t135 * in2[47];
  out3[103] = ((((((((((t33 + t34) + t35) + t36) + t40) + t41) + t42) + t43) +
                 t199 * in2[44]) + t200 * in2[45]) + t201 * in2[46]) + t202 *
    in2[47];
  out3[104] = ((t35_tmp * in2[41] * -2.0 - t34_tmp * in2[40] * 2.0) - t69_tmp *
               in2[42] * 2.0) - t91_tmp * in2[43] * 2.0;
  out3[105] = ((((((((((-t270 * in2[44] + t276 * in2[40]) - t272 * in2[45]) -
                      t281 * in2[36]) + t278 * in2[41]) - t282 * in2[37]) - t274
                   * in2[46]) - t283 * in2[38]) + t280 * in2[42]) - t290 * in2
                [39]) + t289 * in2[43]) - t287 * in2[47];
  out3[106] = ((((((((((t276 * in2[36] + t278 * in2[37]) + t280 * in2[38]) +
                      t289 * in2[39]) + t343 * in2[40]) + t345 * in2[41]) + t347
                   * in2[42]) + t349 * in2[44]) + t351 * in2[45]) + t355 * in2
                [43]) + t353 * in2[46]) + t357 * in2[47];
  out3[107] = ((((((((((t304 * in2[36] + t305 * in2[37]) + t306 * in2[38]) +
                      t316 * in2[39]) + t349 * in2[40]) + t351 * in2[41]) + t353
                   * in2[42]) + t357 * in2[43]) - t393 * in2[44]) - t269 * in2
                [45]) - t271 * in2[46]) - t396 * in2[47];
  out3[108] = ((((((((((-t76 * in2[36] - t79 * in2[37]) - t95 * in2[38]) - t105 *
                      in2[39]) - t117 * in2[40]) - t120 * in2[41]) - t126 * in2
                   [44]) - t129 * in2[45]) - t132 * in2[42]) - t135 * in2[46]) -
               t138 * in2[43]) - t144 * in2[47];
  out3[109] = ((((((((((t62 + t63) + t51) + t52) + t53) + t54) + t55) + t32) +
                 t200 * in2[44]) + t201 * in2[45]) + t202 * in2[46]) + t203 *
    in2[47];
  out3[110] = ((t35_tmp * in2[40] * -2.0 - t69_tmp * in2[41] * 2.0) - t91_tmp *
               in2[42] * 2.0) - t100_tmp * in2[43] * 2.0;
  out3[111] = ((((((((((-t272 * in2[44] + t278 * in2[40]) - t282 * in2[36]) -
                      t274 * in2[45]) - t283 * in2[37]) + t280 * in2[41]) - t290
                   * in2[38]) + t289 * in2[42]) - t287 * in2[46]) - t297 * in2
                [39]) + t295 * in2[43]) - t293 * in2[47];
  out3[112] = ((((((((((t278 * in2[36] + t280 * in2[37]) + t289 * in2[38]) +
                      t295 * in2[39]) + t345 * in2[40]) + t347 * in2[41]) + t351
                   * in2[44]) + t355 * in2[42]) + t353 * in2[45]) + t359 * in2
                [43]) + t357 * in2[46]) + t362 * in2[47];
  out3[113] = ((((((((((t305 * in2[36] + t306 * in2[37]) + t316 * in2[38]) +
                      t321 * in2[39]) + t351 * in2[40]) + t353 * in2[41]) + t357
                   * in2[42]) + t362 * in2[43]) - t269 * in2[44]) - t271 * in2
                [45]) - t396 * in2[46]) - t397 * in2[47];
  out3[114] = ((((((((((-t79 * in2[36] - t95 * in2[37]) - t105 * in2[38]) - t120
                      * in2[40]) - t129 * in2[44]) - t132 * in2[41]) - t135 *
                   in2[45]) - t138 * in2[42]) - t141 * in2[39]) - t144 * in2[46])
               - t168 * in2[47]) - in2[43] * (b_t165_tmp * 3.0 + t165_tmp * t27 *
    t64 * t102);
  out3[115] = ((((((((((t2 + t3) + t56) + t57) + t58) + t59) + t60) + t61) +
                 t201 * in2[44]) + t202 * in2[45]) + t203 * in2[46]) + t216 *
    in2[47];
  out3[116] = ((t161_tmp * in2[43] * -2.0 - t69_tmp * in2[40] * 2.0) - t91_tmp *
               in2[41] * 2.0) - t100_tmp * in2[42] * 2.0;
  out3[117] = ((((((((((-t274 * in2[44] - t283 * in2[36]) + t280 * in2[40]) -
                      t290 * in2[37]) + t289 * in2[41]) - t287 * in2[45]) - t297
                   * in2[38]) + t295 * in2[42]) - t293 * in2[46]) + t360 * in2
                [43]) - in2[47] * (t322 - t15 * t20 * t25 * t64 * t102 * 2.0)) -
    in2[39] * (t298 - t299);
  out3[118] = ((((((((((t280 * in2[36] + t289 * in2[37]) + t295 * in2[38]) +
                      t347 * in2[40]) + t355 * in2[41]) + t353 * in2[44]) + t360
                   * in2[39]) + t359 * in2[42]) + t357 * in2[45]) + t362 * in2
                [46]) + t237 * in2[47]) + in2[43] * (t298 + t20 * t27 * t64 *
    t102 * 2.0);
  out3[119] = ((((((((((t306 * in2[36] + t316 * in2[37]) + t321 * in2[38]) +
                      t337 * in2[39]) + t353 * in2[40]) + t357 * in2[41]) + t362
                   * in2[42]) - t271 * in2[44]) - t396 * in2[45]) + t237 * in2
                [43]) - t397 * in2[46]) - in2[47] * (t298 - t398);
  out3[120] = ((((((((((-in2[44] * (t148_tmp + b_out2_tmp * t28 * t64) + t66 *
                        in2[37]) + t68 * in2[38]) + t70 * in2[39]) - t123 * in2
                     [41]) - t126 * in2[42]) - t129 * in2[43]) + t146 * in2[36])
                 - t151 * in2[40]) - t153 * in2[45]) - t155 * in2[46]) - t157 *
    in2[47];
  out3[121] = ((((((((((in2[44] * (t109_tmp + out2_tmp * t28 * t64) + t181 *
                        in2[37]) + t183 * in2[38]) + t185 * in2[39]) + t199 *
                     in2[41]) + t200 * in2[42]) + t207 * in2[36]) + t201 * in2
                  [43]) + t205 * in2[40]) + t209 * in2[45]) + t211 * in2[46]) +
    t213 * in2[47];
  out3[122] = 0.0;
  out3[123] = ((((((((((t304 * in2[41] + t305 * in2[42]) + t306 * in2[43]) -
                      t313 * in2[37]) - t314 * in2[38]) + t308 * in2[45]) - t315
                   * in2[39]) + t310 * in2[46]) + t312 * in2[47]) + t329 * in2
                [40]) + t400 * in2[44]) - in2[36] * (t302 - t303);
  out3[124] = ((((((((((-t270 * in2[37] - t272 * in2[38]) - t274 * in2[39]) +
                      t365 * in2[45]) - t370 * in2[41]) + t367 * in2[46]) - t371
                   * in2[42]) - t372 * in2[43]) + t369 * in2[47]) - t380 * in2
                [36]) + t401 * in2[44]) - in2[40] * (t302 - t363);
  out3[125] = ((((((((((t308 * in2[37] + t310 * in2[38]) + t312 * in2[39]) +
                      t365 * in2[41]) + t367 * in2[42]) + t369 * in2[43]) + t400
                   * in2[36]) + t401 * in2[40]) + t239 * in2[45]) + t260 * in2
                [46]) + t251 * in2[47]) + in2[44] * (t302 + t42_tmp * t28 * t64 *
    2.0);
  out3[126] = ((((((((((t66 * in2[36] + t68 * in2[37]) + t70 * in2[38]) + t92 *
                      in2[39]) - t123 * in2[40]) - t126 * in2[41]) - t129 * in2
                   [42]) - t135 * in2[43]) - t153 * in2[44]) - t155 * in2[45]) -
               t157 * in2[46]) - t160 * in2[47];
  out3[127] = ((((((((((t181 * in2[36] + t183 * in2[37]) + t185 * in2[38]) +
                      t190 * in2[39]) + t199 * in2[40]) + t200 * in2[41]) + t201
                   * in2[42]) + t202 * in2[43]) + t209 * in2[44]) + t211 * in2
                [45]) + t213 * in2[46]) + t215 * in2[47];
  out3[128] = 0.0;
  out3[129] = ((((((((((t304 * in2[40] + t305 * in2[41]) + t306 * in2[42]) -
                      t313 * in2[36]) - t314 * in2[37]) + t308 * in2[44]) - t315
                   * in2[38]) + t310 * in2[45]) + t312 * in2[46]) + t316 * in2
                [43]) - t320 * in2[39]) + t319 * in2[47];
  out3[130] = ((((((((((-t270 * in2[36] - t272 * in2[37]) - t274 * in2[38]) -
                      t287 * in2[39]) + t365 * in2[44]) - t370 * in2[40]) + t367
                   * in2[45]) - t371 * in2[41]) - t372 * in2[42]) + t369 * in2
                [46]) - t375 * in2[43]) + t374 * in2[47];
  out3[131] = ((((((((((t308 * in2[36] + t310 * in2[37]) + t312 * in2[38]) +
                      t319 * in2[39]) + t365 * in2[40]) + t367 * in2[41]) + t369
                   * in2[42]) + t374 * in2[43]) + t239 * in2[44]) + t260 * in2
                [45]) + t251 * in2[46]) + t166 * in2[47];
  out3[132] = ((((((((((t68 * in2[36] + t70 * in2[37]) + t92 * in2[38]) + t101 *
                      in2[39]) - t126 * in2[40]) - t129 * in2[41]) - t135 * in2
                   [42]) - t144 * in2[43]) - t155 * in2[44]) - t157 * in2[45]) -
               t160 * in2[46]) - t164 * in2[47];
  out3[133] = ((((((((((t183 * in2[36] + t185 * in2[37]) + t190 * in2[38]) +
                      t197 * in2[39]) + t200 * in2[40]) + t201 * in2[41]) + t202
                   * in2[42]) + t203 * in2[43]) + t211 * in2[44]) + t213 * in2
                [45]) + t215 * in2[46]) + t218 * in2[47];
  out3[134] = 0.0;
  out3[135] = ((((((((((t305 * in2[40] + t306 * in2[41]) - t314 * in2[36]) -
                      t315 * in2[37]) + t310 * in2[44]) + t312 * in2[45]) + t316
                   * in2[42]) - t320 * in2[38]) + t321 * in2[43]) - t325 * in2
                [39]) + t319 * in2[46]) + t324 * in2[47];
  out3[136] = ((((((((((-t272 * in2[36] - t274 * in2[37]) - t287 * in2[38]) -
                      t293 * in2[39]) + t367 * in2[44]) - t371 * in2[40]) - t372
                   * in2[41]) + t369 * in2[45]) - t375 * in2[42]) + t374 * in2
                [46]) - t378 * in2[43]) + t377 * in2[47];
  out3[137] = ((((((((((t310 * in2[36] + t312 * in2[37]) + t319 * in2[38]) +
                      t324 * in2[39]) + t367 * in2[40]) + t369 * in2[41]) + t374
                   * in2[42]) + t377 * in2[43]) + t260 * in2[44]) + t251 * in2
                [45]) + t166 * in2[46]) + t44 * in2[47];
  out3[138] = ((((((((((-in2[47] * (b_t165_tmp + t165_tmp * t28 * t64 * t102) +
                        t70 * in2[36]) + t92 * in2[37]) + t101 * in2[38]) - t129
                     * in2[40]) - t135 * in2[41]) - t144 * in2[42]) - t157 *
                  in2[44]) + t162 * in2[39]) - t160 * in2[45]) - t164 * in2[46])
    - t168 * in2[43];
  out3[139] = ((((((((((in2[47] * (b_t139_tmp + t139_tmp * t28 * t64 * t102) +
                        t185 * in2[36]) + t190 * in2[37]) + t197 * in2[38]) +
                     t201 * in2[40]) + t202 * in2[41]) + t203 * in2[42]) + t213 *
                  in2[44]) + t216 * in2[43]) + t220 * in2[39]) + t215 * in2[45])
    + t218 * in2[46];
  out3[140] = 0.0;
  out3[141] = ((((((((((t306 * in2[40] - t315 * in2[36]) + t312 * in2[44]) +
                      t316 * in2[41]) - t320 * in2[37]) + t321 * in2[42]) - t325
                   * in2[38]) + t319 * in2[45]) + t324 * in2[46]) + t337 * in2
                [43]) + t45 * in2[47]) - in2[39] * (t326 - t327);
  out3[142] = ((((((((((-t274 * in2[36] - t287 * in2[37]) - t293 * in2[38]) -
                      t372 * in2[40]) + t369 * in2[44]) - t375 * in2[41]) + t374
                   * in2[45]) - t378 * in2[42]) + t377 * in2[46]) - t387 * in2
                [39]) + t46 * in2[47]) - in2[43] * (t326 - t379);
  out3[143] = ((((((((((t312 * in2[36] + t319 * in2[37]) + t324 * in2[38]) +
                      t369 * in2[40]) + t374 * in2[41]) + t377 * in2[42]) + t251
                   * in2[44]) + t45 * in2[39]) + t166 * in2[45]) + t46 * in2[43])
               + t44 * in2[46]) + in2[47] * (t326 + t25 * t28 * t64 * t102 * 2.0);
  out4[0] = in1[12];
  out4[1] = in1[13];
  out4[2] = in1[14];
  out4[3] = 0.0;
  out4[4] = 0.0;
  out4[5] = 0.0;
}

/* End of code generation (massF2.c) */
