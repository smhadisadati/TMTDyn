/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * rjtipF.c
 *
 * Code generation for function 'rjtipF'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "rjtipF.h"
#include "sqrt.h"

/* Variable Definitions */
static emlrtRSInfo e_emlrtRSI = { 57,  /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

static emlrtRSInfo cb_emlrtRSI = { 326,/* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

static emlrtRSInfo db_emlrtRSI = { 327,/* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

static emlrtRSInfo qb_emlrtRSI = { 380,/* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

static emlrtRSInfo rb_emlrtRSI = { 381,/* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

static emlrtRSInfo sb_emlrtRSI = { 386,/* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

static emlrtRSInfo tb_emlrtRSI = { 387,/* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

static emlrtRSInfo ub_emlrtRSI = { 388,/* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

static emlrtRSInfo vb_emlrtRSI = { 389,/* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

static emlrtRSInfo wb_emlrtRSI = { 418,/* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

static emlrtRSInfo xb_emlrtRSI = { 419,/* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

static emlrtRSInfo yb_emlrtRSI = { 424,/* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

static emlrtRSInfo ac_emlrtRSI = { 425,/* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

/* Function Definitions */
void rjtipF(const emlrtStack *sp, const real_T in1[58], const real_T in2[64],
            real_T s, real_T out1[28])
{
  real_T t3;
  real_T t4;
  real_T t5;
  real_T t6;
  real_T t7;
  real_T t10;
  real_T t11;
  real_T t21;
  real_T t32;
  real_T t35;
  real_T t19;
  real_T t20;
  real_T t22;
  real_T t23;
  real_T t24;
  real_T t25;
  real_T a_tmp;
  real_T t64;
  real_T y_tmp;
  real_T t36;
  real_T t37;
  real_T t56;
  real_T t57;
  real_T t70_tmp;
  real_T t72_tmp;
  real_T t74_tmp;
  real_T t76_tmp;
  real_T t78_tmp;
  real_T t80_tmp;
  real_T t96;
  real_T t97;
  real_T t104;
  real_T t110;
  real_T t115;
  real_T t116;
  real_T t68;
  real_T t69;
  real_T t82;
  real_T t83;
  real_T t247;
  real_T t90;
  real_T t92;
  real_T t93;
  real_T t94;
  real_T t95;
  real_T t111;
  real_T t112;
  real_T t113;
  real_T t114;
  real_T t148;
  real_T t149;
  real_T t204;
  real_T t205;
  real_T t206;
  real_T t207;
  real_T t210;
  real_T t211;
  real_T t248;
  real_T t249;
  real_T t252;
  real_T t253;
  real_T t254;
  real_T t262;
  real_T t267;
  real_T t215;
  real_T t216;
  real_T t243;
  real_T t244;
  real_T t255;
  real_T t256;
  real_T t257;
  real_T t258;
  real_T t278_tmp;
  real_T t278;
  real_T t279;
  real_T t280_tmp;
  real_T t280;
  real_T t281;
  real_T t283_tmp;
  real_T t283;
  real_T t284;
  real_T t290;
  real_T t291;
  real_T t292;
  real_T t293;
  real_T t296;
  real_T t297;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;

  /* RJTIPF */
  /*     OUT1 = RJTIPF(IN1,IN2,S) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.3. */
  /*     14-Oct-2020 04:58:59 */
  t3 = in1[45] + in1[39];
  t4 = in1[47] + in1[40];
  t5 = in1[42] * 2.0;
  t6 = in1[42] * in1[42];
  t7 = muDoubleScalarPower(in1[42], 3.0);
  t10 = s * s;
  t11 = muDoubleScalarPower(s, 3.0);
  t21 = 2.0;
  st.site = &e_emlrtRSI;
  b_sqrt(&st, &t21);
  t32 = in1[42] * 200.0;
  t35 = in1[46] / 2.0;
  t19 = s * t3;
  t20 = s * t4;
  t22 = t3 * t3;
  t23 = muDoubleScalarPower(t3, 3.0);
  t24 = t4 * t4;
  t25 = muDoubleScalarPower(t4, 3.0);
  a_tmp = in1[42] - t3;
  t64 = a_tmp * a_tmp;
  y_tmp = muDoubleScalarPower(a_tmp, 3.0);
  t36 = t19 * 2.0;
  t37 = t20 * 2.0;
  t56 = t19 * 200.0;
  t57 = t20 * 200.0;
  t70_tmp = in2[0] * t10;
  t72_tmp = in2[1] * t11;
  t74_tmp = in2[6] * t10;
  t76_tmp = in2[7] * t11;
  t78_tmp = in2[12] * t10;
  t80_tmp = in2[13] * t11;
  t96 = in2[0] * t5 + in2[1] * t6 * 3.0;
  t97 = in2[6] * t5 + in2[7] * t6 * 3.0;
  t104 = t3 * 2.0 + -t5;
  t110 = (in2[12] * t5 + in2[13] * t6 * 3.0) + 1.0;
  t115 = (in2[18] + in2[19] * t5) + in2[20] * t6 * 3.0;
  t116 = (in2[25] + in2[26] * t5) + in2[27] * t6 * 3.0;
  t68 = in1[42] + -t19;
  t69 = in1[42] + -t20;
  t82 = t3 + -t19;
  t83 = t3 + -t20;
  t247 = (in2[18] * t20 / 2.0 + in2[19] * t10 * t24 / 2.0) + in2[20] * t11 * t25
    / 2.0;
  t11 = ((t35 + in2[25] * t19 / 2.0) + in2[26] * t10 * t22 / 2.0) + in2[27] *
    t11 * t23 / 2.0;
  t90 = t5 + -t36;
  t5 += -t37;
  t92 = t68 * t68;
  t93 = muDoubleScalarPower(t68, 3.0);
  t94 = t69 * t69;
  t95 = muDoubleScalarPower(t69, 3.0);
  t111 = t82 * t82;
  t112 = muDoubleScalarPower(t82, 3.0);
  t113 = t83 * t83;
  t114 = muDoubleScalarPower(t83, 3.0);
  t148 = t3 * 2.0 + -t36;
  t149 = t3 * 2.0 + -t37;
  t4 = in2[1] * t10;
  t204 = in2[0] * t36 + t4 * t22 * 3.0;
  t205 = in2[0] * t37 + t4 * t24 * 3.0;
  t4 = in2[7] * t10;
  t206 = in2[6] * t36 + t4 * t22 * 3.0;
  t207 = in2[6] * t37 + t4 * t24 * 3.0;
  t4 = in2[13] * t10;
  t210 = (in2[12] * t36 + t4 * t22 * 3.0) + 1.0;
  t211 = (in2[12] * t37 + t4 * t24 * 3.0) + 1.0;
  t248 = (t96 + in2[3] * t64 * 3.0) + in2[2] * t104;
  t249 = (t97 + in2[9] * t64 * 3.0) + in2[8] * t104;
  t252 = muDoubleScalarCos(t247);
  t253 = muDoubleScalarSin(t247);
  t254 = (in2[15] * t64 * 3.0 + t110) + in2[14] * t104;
  t262 = muDoubleScalarCos(t11);
  t267 = muDoubleScalarSin(t11);
  t215 = 1.0 / (muDoubleScalarExp(t32 + -t56) + 1.0);
  t216 = 1.0 / (muDoubleScalarExp(t32 + -t57) + 1.0);
  t243 = 1.0 / (muDoubleScalarExp(t3 * 200.0 + -t56) + 1.0);
  t244 = 1.0 / (muDoubleScalarExp(t3 * 200.0 + -t57) + 1.0);
  t255 = (t96 + in2[3] * t92 * 3.0) + -(in2[2] * t90);
  t256 = (t96 + in2[3] * t94 * 3.0) + -(in2[2] * t5);
  t257 = (t97 + in2[9] * t92 * 3.0) + -(in2[8] * t90);
  t258 = (t97 + in2[9] * t94 * 3.0) + -(in2[8] * t5);
  t32 = (t110 + in2[15] * t92 * 3.0) + -(in2[14] * t90);
  t56 = (t110 + in2[15] * t94 * 3.0) + -(in2[14] * t5);
  t278_tmp = in2[0] * t6 + in2[1] * t7;
  t278 = ((t278_tmp + in2[2] * t92) + -(in2[3] * t93)) + -(t68 * t96);
  t279 = ((t278_tmp + in2[2] * t94) + -(in2[3] * t95)) + -(t69 * t96);
  t280_tmp = in2[6] * t6 + in2[7] * t7;
  t280 = ((t280_tmp + in2[8] * t92) + -(in2[9] * t93)) + -(t68 * t97);
  t281 = ((t280_tmp + in2[8] * t94) + -(in2[9] * t95)) + -(t69 * t97);
  t283_tmp = (in1[42] + in2[12] * t6) + in2[13] * t7;
  t283 = ((t283_tmp + in2[14] * t92) + -(in2[15] * t93)) + -(t68 * t110);
  t284 = ((t283_tmp + in2[14] * t94) + -(in2[15] * t95)) + -(t69 * t110);
  t290 = (in2[5] * t111 * 3.0 + -(in2[4] * t148)) + t248;
  t291 = (in2[5] * t113 * 3.0 + -(in2[4] * t149)) + t248;
  t292 = (in2[11] * t111 * 3.0 + -(in2[10] * t148)) + t249;
  t293 = (in2[11] * t113 * 3.0 + -(in2[10] * t149)) + t249;
  t90 = (in2[17] * t111 * 3.0 + -(in2[16] * t148)) + t254;
  t148 = (in2[17] * t113 * 3.0 + -(in2[16] * t149)) + t254;
  t247 = (t204 * t204 + t206 * t206) + t210 * t210;
  st.site = &cb_emlrtRSI;
  b_sqrt(&st, &t247);
  t296 = 1.0 / t247;
  t247 = (t205 * t205 + t207 * t207) + t211 * t211;
  st.site = &db_emlrtRSI;
  b_sqrt(&st, &t247);
  t297 = 1.0 / t247;
  t5 = (in1[42] * in2[18] / 2.0 + in2[19] * t6 / 2.0) + in2[20] * t7 / 2.0;
  t10 = ((t5 + in2[21] * t94 / 2.0) + -(in2[22] * t95 / 2.0)) + -(t69 * t115 /
    2.0);
  t4 = ((t35 + in1[42] * in2[25] / 2.0) + in2[26] * t6 / 2.0) + in2[27] * t7 /
    2.0;
  t11 = ((t4 + in2[28] * t92 / 2.0) + -(in2[29] * t93 / 2.0)) + -(t68 * t116 /
    2.0);
  t37 = (((((t5 + in2[21] * t64 / 2.0) + in2[22] * y_tmp * -0.5) + in2[23] *
           t113 / 2.0) + -(in2[24] * t114 / 2.0)) + t115 * a_tmp * -0.5) + -(t83
    * ((in2[22] * t64 * 3.0 + t115) + in2[21] * t104) / 2.0);
  t36 = (((((t4 + in2[28] * t64 / 2.0) + in2[29] * y_tmp * -0.5) + in2[30] *
           t111 / 2.0) + -(in2[31] * t112 / 2.0)) + t116 * a_tmp * -0.5) + -(t82
    * ((in2[29] * t64 * 3.0 + t116) + in2[28] * t104) / 2.0);
  t4 = muDoubleScalarCos(t10);
  t5 = muDoubleScalarSin(t10);
  t10 = muDoubleScalarCos(t11);
  t11 = muDoubleScalarSin(t11);
  t57 = t210 * t296 + 1.0;
  st.site = &qb_emlrtRSI;
  b_sqrt(&st, &t57);
  t3 = t211 * t297 + 1.0;
  st.site = &rb_emlrtRSI;
  b_sqrt(&st, &t3);
  t247 = (t255 * t255 + t257 * t257) + t32 * t32;
  st.site = &sb_emlrtRSI;
  b_sqrt(&st, &t247);
  t92 = 1.0 / t247;
  t247 = (t256 * t256 + t258 * t258) + t56 * t56;
  st.site = &tb_emlrtRSI;
  b_sqrt(&st, &t247);
  t68 = 1.0 / t247;
  t247 = (t290 * t290 + t292 * t292) + t90 * t90;
  st.site = &ub_emlrtRSI;
  b_sqrt(&st, &t247);
  t93 = 1.0 / t247;
  t247 = (t291 * t291 + t293 * t293) + t148 * t148;
  st.site = &vb_emlrtRSI;
  b_sqrt(&st, &t247);
  t7 = 1.0 / t247;
  t95 = 1.0 / t57;
  t35 = 1.0 / t3;
  t211 = (((t252 + -(t216 * t252)) + t216 * t4) + -(t244 * t4)) + t244 *
    muDoubleScalarCos(t37);
  t6 = (((t253 + -(t216 * t253)) + t216 * t5) + -(t244 * t5)) + t244 *
    muDoubleScalarSin(t37);
  t69 = (((t267 + -(t215 * t267)) + t215 * t11) + -(t243 * t11)) + t243 *
    muDoubleScalarSin(t36);
  t94 = (((t262 + -(t215 * t262)) + t215 * t10) + -(t243 * t10)) + t243 *
    muDoubleScalarCos(t36);
  t11 = t32 * t92 + 1.0;
  st.site = &wb_emlrtRSI;
  b_sqrt(&st, &t11);
  t10 = t56 * t68 + 1.0;
  st.site = &xb_emlrtRSI;
  b_sqrt(&st, &t10);
  t4 = t90 * t93 + 1.0;
  st.site = &yb_emlrtRSI;
  b_sqrt(&st, &t4);
  t5 = t148 * t7 + 1.0;
  st.site = &ac_emlrtRSI;
  b_sqrt(&st, &t5);
  t36 = 1.0 / t11;
  t90 = 1.0 / t10;
  t247 = 1.0 / t4;
  t148 = 1.0 / t5;
  t32 = t21 * t215;
  t56 = t21 * t243;
  t149 = (((t21 * t57 / 2.0 + t32 * t57 * -0.5) + t32 * t11 / 2.0) + -(t56 * t11
           / 2.0)) + t56 * t4 / 2.0;
  t11 = t21 * t216;
  t57 = t21 * t244;
  t3 = (((t21 * t3 / 2.0 + t11 * t3 * -0.5) + t11 * t10 / 2.0) + -(t57 * t10 /
         2.0)) + t57 * t5 / 2.0;
  t4 = t21 * t204;
  t37 = (((t4 * t296 * t95 / 2.0 + t4 * t215 * t296 * t95 * -0.5) + t32 * t255 *
          t92 * t36 / 2.0) + -(t56 * t255 * t92 * t36 / 2.0)) + t56 * t290 * t93
    * t247 / 2.0;
  t4 = t21 * t206;
  t36 = (((t4 * t296 * t95 / 2.0 + t4 * t215 * t296 * t95 * -0.5) + t32 * t257 *
          t92 * t36 / 2.0) + -(t56 * t257 * t92 * t36 / 2.0)) + t56 * t292 * t93
    * t247 / 2.0;
  t4 = t21 * t205;
  t10 = (((t4 * t297 * t35 / 2.0 + t4 * t216 * t297 * t35 * -0.5) + t11 * t256 *
          t68 * t90 / 2.0) + -(t57 * t256 * t68 * t90 / 2.0)) + t57 * t291 * t7 *
    t148 / 2.0;
  t4 = t21 * t207;
  t11 = (((t4 * t297 * t35 / 2.0 + t4 * t216 * t297 * t35 * -0.5) + t11 * t258 *
          t68 * t90 / 2.0) + -(t57 * t258 * t68 * t90 / 2.0)) + t57 * t293 * t7 *
    t148 / 2.0;
  t5 = t70_tmp * t24 + t72_tmp * t25;
  t4 = ((t278_tmp + in2[2] * t64) + in2[3] * -y_tmp) + -t96 * a_tmp;
  out1[0] = (((t5 - t216 * t5) + t244 * (((t4 + in2[4] * t113) - in2[5] * t114)
    - t83 * t248)) + t216 * t279) - t244 * t279;
  t5 = t70_tmp * t22 + t72_tmp * t23;
  out1[1] = (((t5 - t215 * t5) + t243 * (((t4 + in2[4] * t111) - in2[5] * t112)
    - t82 * t248)) + t215 * t278) - t243 * t278;
  t5 = t74_tmp * t24 + t76_tmp * t25;
  t4 = ((t280_tmp + in2[8] * t64) + in2[9] * -y_tmp) + -t97 * a_tmp;
  out1[2] = (((t5 - t216 * t5) + t244 * (((t4 + in2[10] * t113) - in2[11] * t114)
    - t83 * t249)) + t216 * t281) - t244 * t281;
  t5 = t74_tmp * t22 + t76_tmp * t23;
  out1[3] = (((t5 - t215 * t5) + t243 * (((t4 + in2[10] * t111) - in2[11] * t112)
    - t82 * t249)) + t215 * t280) - t243 * t280;
  t5 = (t20 + t78_tmp * t24) + t80_tmp * t25;
  t4 = ((t283_tmp + in2[14] * t64) + in2[15] * -y_tmp) + -t110 * a_tmp;
  out1[4] = (((t5 + t216 * t284) - t244 * t284) - t216 * t5) + t244 * (((t4 +
    in2[16] * t113) - in2[17] * t114) - t83 * t254);
  t5 = (t19 + t78_tmp * t22) + t80_tmp * t23;
  out1[5] = (((t5 + t215 * t283) - t243 * t283) - t215 * t5) + t243 * (((t4 +
    in2[16] * t111) - in2[17] * t112) - t82 * t254);
  out1[6] = rtNaN;
  out1[7] = rtNaN;
  out1[8] = rtNaN;
  out1[9] = rtNaN;
  out1[10] = rtNaN;
  out1[11] = rtNaN;
  out1[12] = t211 * t3;
  out1[13] = t94 * t149;
  out1[14] = -t211 * t11 + t6 * t10;
  out1[15] = t69 * t37 - t94 * t36;
  out1[16] = t211 * t10 + t6 * t11;
  out1[17] = t69 * t36 + t94 * t37;
  out1[18] = t6 * t3;
  out1[19] = t69 * t149;
  out1[20] = rtNaN;
  out1[21] = rtNaN;
  out1[22] = rtNaN;
  out1[23] = rtNaN;
  out1[24] = rtNaN;
  out1[25] = rtNaN;
  out1[26] = rtNaN;
  out1[27] = rtNaN;
}

/* End of code generation (rjtipF.c) */
