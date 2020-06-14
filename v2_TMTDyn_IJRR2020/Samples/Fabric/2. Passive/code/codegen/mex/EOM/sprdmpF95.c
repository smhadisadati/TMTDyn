/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sprdmpF95.c
 *
 * Code generation for function 'sprdmpF95'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "EOM.h"
#include "sprdmpF95.h"
#include "sqrt.h"

/* Variable Definitions */
static emlrtRSInfo kn_emlrtRSI = { 41, /* lineNo */
  "sprdmpF95",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/sprdmpF95.m"/* pathName */
};

static emlrtRSInfo on_emlrtRSI = { 50, /* lineNo */
  "sprdmpF95",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/sprdmpF95.m"/* pathName */
};

static emlrtRSInfo pn_emlrtRSI = { 58, /* lineNo */
  "sprdmpF95",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/sprdmpF95.m"/* pathName */
};

static emlrtRSInfo qn_emlrtRSI = { 87, /* lineNo */
  "sprdmpF95",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/sprdmpF95.m"/* pathName */
};

static emlrtRSInfo do_emlrtRSI = { 293,/* lineNo */
  "sprdmpF95",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/sprdmpF95.m"/* pathName */
};

/* Function Definitions */
void sprdmpF95(const emlrtStack *sp, const real_T in1[6], const real_T in2[206],
               real_T out1[546], real_T out2[6], real_T out3[6], real_T out4[6])
{
  real_T t2;
  real_T t3;
  real_T t4;
  real_T t5;
  real_T t6;
  real_T t7_tmp;
  real_T t7;
  real_T t8;
  real_T t9_tmp;
  real_T t9;
  real_T t233;
  real_T t10;
  real_T t14;
  real_T t71;
  real_T t15;
  real_T t16;
  real_T t17;
  real_T t18_tmp;
  real_T t19;
  real_T t20_tmp;
  real_T t21;
  real_T t22;
  real_T t23;
  real_T t179;
  real_T t25_tmp;
  real_T t173;
  real_T t28_tmp;
  real_T t28;
  real_T t30;
  real_T t31;
  real_T t32_tmp;
  real_T t33;
  real_T t34_tmp;
  real_T t35;
  real_T t36_tmp;
  real_T t46_tmp;
  real_T t37_tmp;
  real_T t37;
  real_T t39_tmp;
  real_T t39;
  real_T t41;
  real_T t53_tmp;
  real_T t183;
  real_T t45;
  real_T t58_tmp;
  real_T t230;
  real_T t47;
  real_T t48;
  real_T t49;
  real_T t51;
  real_T t52;
  real_T t55_tmp;
  real_T t55;
  real_T t57;
  real_T t59;
  real_T t61;
  real_T t62;
  real_T t63_tmp;
  real_T t66;
  real_T t69;
  real_T a;
  real_T a_tmp;
  real_T t76;
  real_T b_a_tmp;
  real_T c_a_tmp;
  real_T b_a;
  real_T t78;
  real_T t79;
  real_T t80;
  real_T t81;
  real_T t227;
  real_T t82;
  real_T t83;
  real_T t84;
  real_T t85;
  real_T t87;
  real_T t91_tmp;
  real_T b_t91_tmp;
  real_T c_t91_tmp;
  real_T t91;
  real_T t96_tmp;
  real_T b_t96_tmp;
  real_T c_t96_tmp;
  real_T t96;
  real_T t106;
  real_T t111;
  real_T t112;
  real_T t113;
  real_T t114;
  real_T t115;
  real_T t116;
  real_T t117;
  real_T t119;
  real_T t123_tmp;
  real_T b_t123_tmp;
  real_T c_t123_tmp;
  real_T t123;
  real_T t128_tmp;
  real_T b_t128_tmp;
  real_T c_t128_tmp;
  real_T t128;
  real_T t137;
  real_T t142;
  real_T t143;
  real_T t144;
  real_T t145;
  real_T t146;
  real_T t147;
  real_T t148;
  real_T t150;
  real_T t154_tmp;
  real_T t154;
  real_T t159;
  real_T t168;
  real_T t175;
  real_T t178;
  real_T t182;
  real_T t186;
  real_T t191;
  real_T t193;
  real_T t197;
  real_T t201;
  real_T t205;
  real_T t207;
  real_T t210;
  real_T t215;
  real_T t217;
  real_T t221;
  int32_T i;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;

  /* SPRDMPF95 */
  /*     [OUT1,OUT2,OUT3,OUT4,OUT5,OUT6,OUT7,OUT8] = SPRDMPF95(IN1,IN2,S) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.2. */
  /*     09-Jan-2019 03:23:42 */
  t2 = in2[64] * in2[64];
  t3 = in2[65] * in2[65];
  t4 = in2[63] * in2[63];
  t5 = ((-t2 - t3) - t4) + 1.0;
  t6 = t5;
  st.site = &kn_emlrtRSI;
  b_sqrt(&st, &t6);
  t7_tmp = in2[63] * in2[64];
  t7 = t7_tmp * 2.0;
  t8 = in2[64] * t6 * 2.0;
  t9_tmp = in2[63] * in2[65];
  t9 = t9_tmp * 2.0;
  t233 = in2[64] * in2[65];
  t10 = t233 * 2.0;
  t14 = ((-(in2[9] * in2[9]) - in2[10] * in2[10]) - in2[11] * in2[11]) + 1.0;
  t71 = t14;
  st.site = &on_emlrtRSI;
  b_sqrt(&st, &t71);
  t15 = 1.0 / t71;
  t16 = t6 * 2.0;
  t17 = in2[64] * 2.0;
  t18_tmp = in2[65] * t6 * 2.0;
  t19 = t3 * 2.0;
  t20_tmp = in2[63] * t6 * 2.0;
  t21 = t4 * 2.0;
  t22 = t2 * 2.0;
  st.site = &pn_emlrtRSI;
  b_sqrt(&st, &t5);
  t23 = 1.0 / t5;
  t179 = in2[7] - in2[61];
  t25_tmp = in2[8] - in2[62];
  t173 = in2[6] - in2[60];
  t28_tmp = in2[63] * t23;
  t28 = (-in2[8] + in2[62]) + t28_tmp * t179;
  t30 = t179 + t28_tmp * t25_tmp;
  t31 = t6 * t179;
  t32_tmp = in2[63] * t25_tmp;
  t33 = t6 * t25_tmp;
  t34_tmp = in2[64] * t173;
  t35 = t6 * t173;
  t36_tmp = in2[65] * t179;
  t46_tmp = in2[64] * t25_tmp;
  t37_tmp = t35 + t36_tmp;
  t37 = t37_tmp - t46_tmp;
  t39_tmp = in2[64] * t23;
  t39 = (-in2[6] + in2[60]) + t39_tmp * t25_tmp;
  t41 = t25_tmp + t39_tmp * t173;
  t53_tmp = in2[65] * t173;
  t183 = t31 + t32_tmp;
  t45 = t183 - t53_tmp;
  t58_tmp = in2[63] * t179;
  t230 = t33 + t34_tmp;
  t47 = t230 - t58_tmp;
  t48 = in2[11] * 2.0;
  t49 = in2[9] - in2[63];
  st.site = &qn_emlrtRSI;
  b_sqrt(&st, &t14);
  t51 = in2[10] - in2[64];
  t52 = in2[11] - in2[65];
  t55_tmp = in2[65] * t23;
  t55 = t173 + t55_tmp * t179;
  t57 = (-in2[7] + in2[61]) + t55_tmp * t173;
  t59 = in2[9] * 2.0;
  t5 = in1[4] / 2.0;
  t61 = muDoubleScalarCos(t5);
  t62 = muDoubleScalarSin(t5);
  t63_tmp = (in2[63] * t173 + in2[64] * t179) + in2[65] * t25_tmp;
  t66 = t61 * 0.162 + t62 * 0.036;
  t69 = t61 * 0.036 - t62 * 0.162;
  t5 = t61 * t61;
  t71 = t62 * t62;
  a = ((t61 * t66 + t62 * t69) - t5 * 0.162) + t71 * 0.162;
  a_tmp = t5 * 0.02259459459505023 + t71 * 0.02259459459505023;
  t76 = t62 * t66;
  b_a_tmp = t61 * t62 * 0.324;
  c_a_tmp = t61 * t69;
  b_a = (-t76 + c_a_tmp) + b_a_tmp;
  t78 = t6 - t14;
  t79 = in2[64] * t39;
  t80 = t58_tmp * 2.0;
  t81 = t32_tmp * 2.0;
  t227 = t233 * t23;
  t82 = t227 * t25_tmp;
  t83 = (t19 + t22) - 1.0;
  t84 = t7 + t18_tmp;
  t85 = t8 - t9;
  t87 = ((t63_tmp + in2[64] * t30) - in2[65] * t28) - t28_tmp * t37;
  t91_tmp = t6 * t41;
  b_t91_tmp = t39_tmp * t37;
  c_t91_tmp = t227 * t179;
  t91 = ((((t230 - t79) - t80) + t91_tmp) + b_t91_tmp) + c_t91_tmp;
  t96_tmp = in2[65] * t55;
  b_t96_tmp = t6 * t57;
  c_t96_tmp = t55_tmp * t37;
  t96 = (((((-t31 + t53_tmp) - t81) - t82) + b_t96_tmp) + t96_tmp) + c_t96_tmp;
  t106 = muDoubleScalarPower(muDoubleScalarAbs((((((((t91 * in2[167] + t96 *
    in2[168]) + t83 * in2[109]) + t85 * in2[111]) + t84 * in2[164]) - t83 * in2
    [163]) - t84 * in2[110]) - t85 * in2[165]) - t87 * in2[166]), in1[1] - 1.0);
  t111 = t34_tmp * 2.0;
  t71 = t9_tmp * t23;
  t112 = t71 * t173;
  t113 = in2[65] * t57;
  t114 = t46_tmp * 2.0;
  t115 = (t19 + t21) - 1.0;
  t116 = -t7 + t18_tmp;
  t117 = t10 + t20_tmp;
  t119 = ((t63_tmp + in2[65] * t41) - in2[63] * t39) - t39_tmp * t45;
  t123_tmp = in2[63] * t30;
  b_t123_tmp = t6 * t28;
  c_t123_tmp = t28_tmp * t45;
  t123 = (((((-t33 + t58_tmp) - t111) - t112) + b_t123_tmp) + t123_tmp) +
    c_t123_tmp;
  t128_tmp = t6 * t55;
  b_t128_tmp = t55_tmp * t45;
  c_t128_tmp = t71 * t25_tmp;
  t128 = ((((t37_tmp - t113) - t114) + t128_tmp) + b_t128_tmp) + c_t128_tmp;
  t137 = muDoubleScalarPower(muDoubleScalarAbs((((((((t123 * in2[166] + t128 *
    in2[168]) + t115 * in2[110]) + t116 * in2[109]) + t117 * in2[165]) - t115 *
    in2[164]) - t117 * in2[111]) - t116 * in2[163]) - t119 * in2[167]), in1[1] -
    1.0);
  t142 = in2[63] * t28;
  t143 = t53_tmp * 2.0;
  t144 = t36_tmp * 2.0;
  t5 = t7_tmp * t23;
  t145 = t5 * t179;
  t146 = (t21 + t22) - 1.0;
  t147 = t8 + t9;
  t148 = -t10 + t20_tmp;
  t150 = ((t63_tmp + in2[63] * t55) - in2[64] * t57) - t55_tmp * t47;
  t30 *= t6;
  t154_tmp = t28_tmp * t47;
  t55 = t5 * t173;
  t154 = ((((t183 - t142) - t143) + t30) + t154_tmp) + t55;
  t7_tmp = in2[64] * t41;
  t37_tmp = t6 * t39;
  t28 = t39_tmp * t47;
  t159 = (((((-t35 + t46_tmp) - t144) - t145) + t37_tmp) + t7_tmp) + t28;
  t168 = muDoubleScalarPower(muDoubleScalarAbs((((((((t154 * in2[166] + t159 *
    in2[167]) + t146 * in2[111]) + t148 * in2[110]) + t147 * in2[163]) - t146 *
    in2[165]) - t147 * in2[109]) - t148 * in2[164]) - t150 * in2[168]), in1[1] -
    1.0);
  t173 = in2[10] * 2.0;
  t175 = t16 + in2[9] * in2[63] * t15 * 2.0;
  t66 = in2[65] * 2.0;
  t178 = t66 + in2[10] * in2[63] * t15 * 2.0;
  t179 = in2[11] * in2[63] * t15 * 2.0;
  t230 = t5 * 2.0;
  t9_tmp = t39_tmp * t49 * 2.0;
  t182 = (t48 + t230) + t9_tmp;
  t183 = t14 * 2.0;
  t19 = t4 * t23 * 2.0;
  t25_tmp = t28_tmp * t49 * 2.0;
  t186 = (t183 + t19) + t25_tmp;
  t22 = t71 * 2.0;
  t71 = t55_tmp * t49 * 2.0;
  t191 = (-t173 + t22) + t71;
  t193 = t17 - t179;
  t197 = muDoubleScalarPower(muDoubleScalarAbs(((((t186 * in2[166] + t182 * in2
    [167]) + t191 * in2[168]) + t193 * in2[114]) - t175 * in2[112]) - t178 *
    in2[113]), in1[1] - 1.0);
  t201 = t16 + in2[10] * in2[64] * t15 * 2.0;
  t62 = in2[9] * in2[64] * t15 * 2.0;
  t41 = in2[63] * 2.0;
  t205 = t41 + in2[11] * in2[64] * t15 * 2.0;
  t69 = t28_tmp * t51 * 2.0;
  t207 = (-t48 + t230) + t69;
  t61 = t2 * t23 * 2.0;
  t233 = t39_tmp * t51 * 2.0;
  t210 = (t183 + t61) + t233;
  t57 = t227 * 2.0;
  t5 = t55_tmp * t51 * 2.0;
  t215 = (t59 + t57) + t5;
  t217 = t66 - t62;
  t221 = muDoubleScalarPower(muDoubleScalarAbs(((((t210 * in2[167] + t207 * in2
    [166]) + t215 * in2[168]) + t217 * in2[112]) - t201 * in2[113]) - t205 *
    in2[114]), in1[1] - 1.0);
  t39 = t16 + in2[11] * in2[65] * t15 * 2.0;
  t227 = t17 + in2[9] * in2[65] * t15 * 2.0;
  t21 = in2[10] * in2[65] * t15 * 2.0;
  out1[0] = 0.0;
  out1[1] = 0.0;
  out1[2] = 0.0;
  out1[3] = 0.0;
  out1[4] = 0.0;
  out1[5] = 0.0;
  out1[6] = (t2 * -2.0 - t3 * 2.0) + 1.0;
  out1[7] = t84;
  out1[8] = -t8 + t9;
  memset(&out1[9], 0, 51U * sizeof(real_T));
  out1[60] = t83;
  out1[61] = -t7 - t18_tmp;
  out1[62] = t85;
  out1[63] = t87;
  out1[64] = (((((-t33 - t34_tmp) + t79) + t80) - t91_tmp) - b_t91_tmp) -
    c_t91_tmp;
  out1[65] = (((((t31 - t53_tmp) + t81) + t82) - t96_tmp) - b_t96_tmp) -
    c_t96_tmp;
  memset(&out1[66], 0, 31U * sizeof(real_T));
  out1[97] = t7 - t18_tmp;
  out1[98] = (t3 * -2.0 - t4 * 2.0) + 1.0;
  out1[99] = t117;
  memset(&out1[100], 0, 51U * sizeof(real_T));
  out1[151] = t116;
  out1[152] = t115;
  out1[153] = -t10 - t20_tmp;
  out1[154] = (((((t33 + t111) + t112) - t58_tmp) - t123_tmp) - b_t123_tmp) -
    c_t123_tmp;
  out1[155] = t119;
  out1[156] = (((((-t35 - t36_tmp) + t113) + t114) - t128_tmp) - b_t128_tmp) -
    c_t128_tmp;
  memset(&out1[157], 0, 31U * sizeof(real_T));
  out1[188] = t147;
  out1[189] = t10 - t20_tmp;
  out1[190] = (t2 * -2.0 - t4 * 2.0) + 1.0;
  memset(&out1[191], 0, 51U * sizeof(real_T));
  out1[242] = -t8 - t9;
  out1[243] = t148;
  out1[244] = t146;
  out1[245] = (((((-t31 - t32_tmp) + t142) + t143) - t30) - t154_tmp) - t55;
  out1[246] = (((((t35 - t46_tmp) + t144) + t145) - t7_tmp) - t37_tmp) - t28;
  out1[247] = t150;
  memset(&out1[248], 0, 34U * sizeof(real_T));
  out1[282] = t175;
  out1[283] = t178;
  out1[284] = -t17 + t179;
  memset(&out1[285], 0, 51U * sizeof(real_T));
  out1[336] = (t14 * -2.0 - t19) - t25_tmp;
  out1[337] = (-t48 - t230) - t9_tmp;
  out1[338] = (t173 - t22) - t71;
  memset(&out1[339], 0, 34U * sizeof(real_T));
  out1[373] = in2[65] * -2.0 + t62;
  out1[374] = t201;
  out1[375] = t205;
  memset(&out1[376], 0, 51U * sizeof(real_T));
  out1[427] = (t48 - t230) - t69;
  out1[428] = (t14 * -2.0 - t61) - t233;
  out1[429] = (-t59 - t57) - t5;
  memset(&out1[430], 0, 34U * sizeof(real_T));
  out1[464] = t227;
  out1[465] = in2[63] * -2.0 + t21;
  out1[466] = t39;
  memset(&out1[467], 0, 51U * sizeof(real_T));
  t66 = t28_tmp * t52 * 2.0;
  out1[518] = (in2[10] * -2.0 - t22) - t66;
  t62 = t39_tmp * t52 * 2.0;
  out1[519] = (t59 - t57) - t62;
  t71 = t3 * t23 * 2.0;
  t5 = t55_tmp * t52 * 2.0;
  out1[520] = (t14 * -2.0 - t71) - t5;
  memset(&out1[521], 0, 25U * sizeof(real_T));
  t230 = (t173 + t22) + t66;
  t233 = (t183 + t71) + t5;
  t61 = (-t59 + t57) + t62;
  t62 = t41 - t21;
  t69 = muDoubleScalarPower(muDoubleScalarAbs(((((t233 * in2[168] + t230 * in2
    [166]) + t61 * in2[167]) + t62 * in2[113]) - t39 * in2[114]) - t227 * in2
    [112]), in1[1] - 1.0);
  t5 = (a * a + a_tmp * a_tmp) + b_a * b_a;
  st.site = &do_emlrtRSI;
  b_sqrt(&st, &t5);
  out2[0] = in1[0] * ((((((t76 + in2[65] * t45) - in2[64] * t47) + in2[63] *
    t63_tmp) + t6 * t37) - b_a_tmp) - c_a_tmp) * -0.00026666666666666668;
  out2[1] = in1[0] * ((((a_tmp - in2[65] * t37) + in2[63] * t47) + in2[64] *
                       t63_tmp) + t6 * t45) * -0.00026666666666666668;
  out2[2] = in1[0] * ((((-t5 + in2[64] * t37) - in2[63] * t45) + in2[65] *
                       t63_tmp) + t6 * t47) * -0.0008;
  out2[3] = in1[0] * (((in2[64] * t52 * -2.0 + in2[65] * t51 * 2.0) + in2[63] *
                       t78 * 2.0) + t6 * t49 * 2.0) * -4.2666666666666668E-11;
  out2[4] = in1[0] * (((in2[65] * t49 * -2.0 + in2[63] * t52 * 2.0) + in2[64] *
                       t78 * 2.0) + t6 * t51 * 2.0) * -1.421066666666666E-8;
  out2[5] = in1[0] * (((in2[64] * t49 * 2.0 - in2[63] * t51 * 2.0) + in2[65] *
                       t78 * 2.0) + t6 * t52 * 2.0) * -4.75111111111111E-9;
  t66 = in1[2] * t83 * t106;
  t5 = in1[2] * t84 * t106;
  t71 = in1[2] * t85 * t106;
  out3[0] = (((((((t66 * in2[109] - t5 * in2[110]) + t71 * in2[111]) - t66 *
                 in2[163]) + t5 * in2[164]) - t71 * in2[165]) - in1[2] * t87 *
              t106 * in2[166]) + in1[2] * t91 * t106 * in2[167]) + in1[2] * t96 *
    t106 * in2[168];
  t66 = in1[2] * t115 * t137;
  t5 = in1[2] * t116 * t137;
  t71 = in1[2] * t117 * t137;
  out3[1] = (((((((t66 * in2[110] + t5 * in2[109]) - t71 * in2[111]) - t66 *
                 in2[164]) - t5 * in2[163]) + t71 * in2[165]) - in1[2] * t119 *
              t137 * in2[167]) + in1[2] * t123 * t137 * in2[166]) + in1[2] *
    t128 * t137 * in2[168];
  t66 = in1[2] * t146 * t168;
  t5 = in1[2] * t148 * t168;
  out3[2] = (((((((-in1[2] * t147 * t168 * in2[109] + t66 * in2[111]) + t5 *
                  in2[110]) + in1[2] * t147 * t168 * in2[163]) - t66 * in2[165])
               - t5 * in2[164]) - in1[2] * t150 * t168 * in2[168]) + in1[2] *
             t154 * t168 * in2[166]) + in1[2] * t159 * t168 * in2[167];
  out3[3] = ((((-in1[3] * t175 * t197 * in2[112] - in1[3] * t178 * t197 * in2
                [113]) + in1[3] * t193 * t197 * in2[114]) + in1[3] * t182 * t197
              * in2[167]) + in1[3] * t186 * t197 * in2[166]) + in1[3] * t191 *
    t197 * in2[168];
  out3[4] = ((((-in1[3] * t201 * t221 * in2[113] - in1[3] * t205 * t221 * in2
                [114]) + in1[3] * t217 * t221 * in2[112]) + in1[3] * t207 * t221
              * in2[166]) + in1[3] * t210 * t221 * in2[167]) + in1[3] * t215 *
    t221 * in2[168];
  out3[5] = ((((-in1[3] * t39 * t69 * in2[114] - in1[3] * t227 * t69 * in2[112])
               + in1[3] * t62 * t69 * in2[113]) + in1[3] * t230 * t69 * in2[166])
             + in1[3] * t233 * t69 * in2[168]) + in1[3] * t61 * t69 * in2[167];
  for (i = 0; i < 6; i++) {
    out4[i] = 0.0;
  }
}

/* End of code generation (sprdmpF95.c) */