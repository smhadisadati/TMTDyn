/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * massF1.c
 *
 * Code generation for function 'massF1'
 *
 */

/* Include files */
#include "massF1.h"
#include "EOM_eq_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo bb_emlrtRSI = { 64, /* lineNo */
  "massF1",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\massF1.m"/* pathName */
};

static emlrtRSInfo fb_emlrtRSI = { 83, /* lineNo */
  "massF1",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\massF1.m"/* pathName */
};

/* Function Definitions */
void massF1(const emlrtStack *sp, const real_T in1[34], const real_T in2[10],
            real_T s, real_T out1[36], real_T out2[30], real_T out3[30], real_T
            out4[6])
{
  emlrtStack st;
  real_T b_t106_tmp;
  real_T b_t268_tmp;
  real_T b_t297_tmp;
  real_T b_t300_tmp;
  real_T b_t328_tmp;
  real_T b_t329_tmp;
  real_T b_t420_tmp;
  real_T b_t490_tmp;
  real_T b_t548_tmp;
  real_T t10;
  real_T t106;
  real_T t106_tmp;
  real_T t108;
  real_T t109;
  real_T t11;
  real_T t111;
  real_T t112;
  real_T t112_tmp;
  real_T t113;
  real_T t114;
  real_T t114_tmp;
  real_T t115;
  real_T t115_tmp;
  real_T t12;
  real_T t13_tmp;
  real_T t14;
  real_T t183_tmp;
  real_T t192;
  real_T t193;
  real_T t194;
  real_T t195;
  real_T t2;
  real_T t201;
  real_T t202;
  real_T t205;
  real_T t205_tmp;
  real_T t206;
  real_T t209;
  real_T t209_tmp;
  real_T t210;
  real_T t210_tmp;
  real_T t211;
  real_T t212;
  real_T t218;
  real_T t22;
  real_T t220;
  real_T t221;
  real_T t221_tmp;
  real_T t222;
  real_T t222_tmp;
  real_T t223;
  real_T t224;
  real_T t224_tmp_tmp;
  real_T t224_tmp_tmp_tmp;
  real_T t225;
  real_T t226;
  real_T t226_tmp_tmp;
  real_T t226_tmp_tmp_tmp;
  real_T t227;
  real_T t227_tmp;
  real_T t228;
  real_T t229;
  real_T t229_tmp;
  real_T t231;
  real_T t252;
  real_T t253;
  real_T t256;
  real_T t257;
  real_T t264_tmp;
  real_T t266;
  real_T t266_tmp;
  real_T t267;
  real_T t267_tmp;
  real_T t268;
  real_T t268_tmp;
  real_T t268_tmp_tmp;
  real_T t27;
  real_T t275;
  real_T t275_tmp;
  real_T t276;
  real_T t276_tmp;
  real_T t28;
  real_T t283;
  real_T t284;
  real_T t287;
  real_T t288;
  real_T t293;
  real_T t293_tmp_tmp;
  real_T t294;
  real_T t294_tmp_tmp;
  real_T t297_tmp;
  real_T t300_tmp;
  real_T t301_tmp;
  real_T t304_tmp;
  real_T t309;
  real_T t31;
  real_T t310;
  real_T t318_tmp;
  real_T t32;
  real_T t321;
  real_T t322;
  real_T t323;
  real_T t324;
  real_T t327;
  real_T t327_tmp;
  real_T t328;
  real_T t328_tmp;
  real_T t329;
  real_T t329_tmp;
  real_T t33;
  real_T t330;
  real_T t330_tmp;
  real_T t332;
  real_T t333;
  real_T t338;
  real_T t34;
  real_T t340;
  real_T t354;
  real_T t355;
  real_T t356;
  real_T t357;
  real_T t36;
  real_T t366;
  real_T t367;
  real_T t372;
  real_T t373;
  real_T t374;
  real_T t375;
  real_T t38;
  real_T t39;
  real_T t398;
  real_T t4;
  real_T t40;
  real_T t400;
  real_T t401;
  real_T t402;
  real_T t403;
  real_T t404;
  real_T t405;
  real_T t406;
  real_T t407;
  real_T t408;
  real_T t409;
  real_T t41;
  real_T t410;
  real_T t411;
  real_T t412;
  real_T t413;
  real_T t414_tmp;
  real_T t417_tmp;
  real_T t42;
  real_T t420_tmp;
  real_T t421_tmp;
  real_T t424;
  real_T t425;
  real_T t427;
  real_T t43;
  real_T t430;
  real_T t442;
  real_T t455_tmp;
  real_T t458_tmp;
  real_T t460_tmp;
  real_T t461_tmp;
  real_T t464_tmp;
  real_T t466;
  real_T t469_tmp;
  real_T t47;
  real_T t470_tmp;
  real_T t471_tmp;
  real_T t474;
  real_T t475;
  real_T t476;
  real_T t477;
  real_T t478;
  real_T t479;
  real_T t47_tmp;
  real_T t480;
  real_T t481;
  real_T t482;
  real_T t483;
  real_T t484;
  real_T t485;
  real_T t486;
  real_T t487;
  real_T t489;
  real_T t490;
  real_T t490_tmp;
  real_T t494;
  real_T t495;
  real_T t497;
  real_T t50_tmp;
  real_T t525;
  real_T t526;
  real_T t527;
  real_T t532;
  real_T t533;
  real_T t536;
  real_T t537;
  real_T t54;
  real_T t540;
  real_T t541;
  real_T t548;
  real_T t548_tmp;
  real_T t55;
  real_T t551;
  real_T t554;
  real_T t56;
  real_T t57;
  real_T t64;
  real_T t65;
  real_T t66;
  real_T t67;
  real_T t67_tmp;
  real_T t68;
  real_T t69;
  real_T t69_tmp;
  real_T t69_tmp_tmp;
  real_T t7;
  real_T t70;
  real_T t70_tmp;
  real_T t70_tmp_tmp;
  real_T t71;
  real_T t72;
  real_T t75;
  real_T t77;
  real_T t77_tmp;
  real_T t78;
  real_T t78_tmp;
  real_T t79;
  real_T t79_tmp;
  real_T t8;
  real_T t80;
  real_T t81;
  real_T t82;
  real_T t84;
  real_T t85;
  real_T t86;
  real_T t86_tmp;
  real_T t87;
  real_T t87_tmp;
  real_T t88;
  real_T t88_tmp;
  real_T t89;
  real_T t89_tmp;
  real_T t9;
  real_T t90_tmp;
  real_T t93_tmp;
  real_T t96;
  real_T t96_tmp;
  real_T t97;
  real_T t97_tmp;
  st.prev = sp;
  st.tls = sp->tls;

  /* MASSF1 */
  /*     [OUT1,OUT2,OUT3,OUT4] = MASSF1(IN1,IN2,S,DS,T_SYM) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
  /*     27-Feb-2021 16:27:46 */
  t2 = in2[0] * in2[0];
  t4 = in2[1] * in2[1];
  t7 = in1[2] * in1[2];
  t8 = in1[3] * in1[3];
  t9 = s * s;
  t10 = muDoubleScalarPower(s, 3.0);
  t12 = muDoubleScalarPower(s, 5.0);
  t13_tmp = in2[2] * s * 2.0;
  t14 = 1.0 / in1[33];
  t11 = t9 * t9;
  t22 = (t13_tmp + 1.0) * (t13_tmp + 1.0);
  t27 = t7 + -t8;
  t28 = in2[3] * s / 2.0 + in2[4] * t9 / 2.0;
  t31 = muDoubleScalarCos(t28);
  t32 = muDoubleScalarSin(t28);
  t28 = (t22 + t2 * t9 * 4.0) + t4 * t9 * 4.0;
  t33 = t31 * t31;
  t34 = t32 * t32;
  t38 = 1.0 / (t28 * t28);
  t39 = 1.0 / muDoubleScalarPower(t28, 3.0);
  st.site = &bb_emlrtRSI;
  if (t28 < 0.0) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  t40 = 1.0 / muDoubleScalarSqrt(t28);
  t28 = -(in1[0] * t14 * t27 * (t7 / 4.0 + t8 / 4.0) * 3.1415926535897931);
  t36 = -(in1[0] * (in1[18] * in1[18] * 6.0 + t27) * 3.1415926535897931);
  out1[0] = t36;
  out1[1] = 0.0;
  out1[2] = 0.0;
  out1[3] = 0.0;
  out1[4] = 0.0;
  out1[5] = 0.0;
  out1[6] = 0.0;
  out1[7] = t36;
  out1[8] = 0.0;
  out1[9] = 0.0;
  out1[10] = 0.0;
  out1[11] = 0.0;
  out1[12] = 0.0;
  out1[13] = 0.0;
  out1[14] = t36;
  out1[15] = 0.0;
  out1[16] = 0.0;
  out1[17] = 0.0;
  out1[18] = 0.0;
  out1[19] = 0.0;
  out1[20] = 0.0;
  out1[21] = t28;
  out1[22] = 0.0;
  out1[23] = 0.0;
  out1[24] = 0.0;
  out1[25] = 0.0;
  out1[26] = 0.0;
  out1[27] = 0.0;
  out1[28] = t28;
  out1[29] = 0.0;
  out1[30] = 0.0;
  out1[31] = 0.0;
  out1[32] = 0.0;
  out1[33] = 0.0;
  out1[34] = 0.0;
  out1[35] = -in1[0] * t14 * t27 * 3.1415926535897931 * (t7 / 2.0 + t8 / 2.0);
  t41 = muDoubleScalarPower(t40, 3.0);
  t42 = muDoubleScalarPower(t40, 5.0);
  t43 = muDoubleScalarPower(t40, 7.0);
  t28 = s * t40 * 2.0;
  t47_tmp = in2[0] * t10;
  t47 = t47_tmp * t41 * 8.0;
  t50_tmp = (t13_tmp + 1.0) * t40 + 1.0;
  st.site = &fb_emlrtRSI;
  if (t50_tmp < 0.0) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  t54 = muDoubleScalarSqrt(t50_tmp);
  t55 = 1.0 / t54;
  t64 = t28 + -(s * t22 * t41 * 2.0);
  t66 = t47 + -(t47_tmp * t22 * t42 * 24.0);
  t67_tmp = in2[1] * t10;
  t67 = t67_tmp * t41 * 8.0 + -(t67_tmp * t22 * t42 * 24.0);
  t68 = t9 * (t13_tmp + 1.0) * t41 * 12.0 + -(t9 * muDoubleScalarPower(t13_tmp +
    1.0, 3.0) * t42 * 12.0);
  t56 = muDoubleScalarPower(t55, 3.0);
  t57 = muDoubleScalarPower(t55, 5.0);
  t65 = t64 * t64;
  t69_tmp_tmp = s * 1.4142135623730951 * t31;
  t69_tmp = t69_tmp_tmp * t40;
  t69 = t69_tmp * t55;
  t70_tmp_tmp = s * 1.4142135623730951 * t32;
  t70_tmp = t70_tmp_tmp * t40;
  t70 = t70_tmp * t55;
  t71 = 1.4142135623730951 * t31 * t28 * t55;
  t72 = 1.4142135623730951 * t32 * t28 * t55;
  t14 = in2[0] * t9 * 1.4142135623730951;
  t77_tmp = t14 * t32 * t40;
  t77 = t77_tmp * t55;
  t532 = t47_tmp * 1.4142135623730951;
  t28 = t532 * t32;
  t78_tmp = t28 * t40;
  t78 = t78_tmp * t55;
  t79_tmp = in2[1] * t9 * 1.4142135623730951;
  t537 = t79_tmp * t32 * t40;
  t79 = t537 * t55;
  t527 = t67_tmp * 1.4142135623730951;
  t36 = t527 * t32;
  t525 = t36 * t40;
  t80 = t525 * t55;
  t497 = t14 * t31 * t40;
  t84 = t497 * t55;
  t7 = t532 * t31;
  t526 = t7 * t40;
  t85 = t526 * t55;
  t86_tmp = t79_tmp * t31 * t40;
  t86 = t86_tmp * t55;
  t8 = t527 * t31;
  t87_tmp = t8 * t40;
  t87 = t87_tmp * t55;
  t88_tmp = t28 * t41 * t55;
  t88 = t88_tmp * 4.0;
  t89_tmp = t36 * t41 * t55;
  t89 = t89_tmp * 4.0;
  t96_tmp = t7 * t41 * t55;
  t96 = t96_tmp * 4.0;
  t97_tmp = t8 * t41 * t55;
  t97 = t97_tmp * 4.0;
  t106_tmp = in2[0] * in2[1];
  b_t106_tmp = t106_tmp * t11 * 1.4142135623730951;
  t27 = b_t106_tmp * t31;
  t106 = t27 * t41 * t55 * 2.0;
  t540 = t106_tmp * t12 * 1.4142135623730951;
  t108 = t540 * t31 * t41 * t55 * 2.0;
  t541 = b_t106_tmp * t32;
  t109 = t541 * t41 * t55 * 2.0;
  t111 = t540 * t32 * t41 * t55 * 2.0;
  t112_tmp = t9 * 1.4142135623730951 * t31;
  t112 = t112_tmp * t40 * t55 / 2.0;
  t533 = t10 * 1.4142135623730951 * t31;
  t113 = t533 * t40 * t55 / 2.0;
  t114_tmp = t9 * 1.4142135623730951 * t32;
  t114 = t114_tmp * t40 * t55 / 2.0;
  t115_tmp = t10 * 1.4142135623730951 * t32;
  t115 = t115_tmp * t40 * t55 / 2.0;
  t183_tmp = muDoubleScalarPower(in2[0], 3.0) * t12 * 1.4142135623730951;
  t209_tmp = in2[0] * t4 * t12 * 1.4142135623730951;
  t209 = t209_tmp * t31 * t42 * t55 * 48.0;
  t210_tmp = in2[1] * t2 * t12 * 1.4142135623730951;
  t210 = t210_tmp * t31 * t42 * t55 * 48.0;
  t211 = t209_tmp * t32 * t42 * t55 * 48.0;
  t212 = t210_tmp * t32 * t42 * t55 * 48.0;
  t28 = t9 * 1.4142135623730951 * (t13_tmp + 1.0);
  t221_tmp = t28 * t31 * t41 * t55;
  t221 = t221_tmp * 2.0;
  t222_tmp = t28 * t32 * t41 * t55;
  t222 = t222_tmp * 2.0;
  t28 = t532 * (t13_tmp + 1.0);
  t536 = t28 * t31;
  t223 = t536 * t41 * t55;
  t224_tmp_tmp_tmp = in2[0] * t11;
  t224_tmp_tmp = t224_tmp_tmp_tmp * 1.4142135623730951;
  t36 = t224_tmp_tmp * (t13_tmp + 1.0);
  t224 = t36 * t31 * t41 * t55;
  t7 = t527 * (t13_tmp + 1.0);
  t489 = t7 * t31;
  t225 = t489 * t41 * t55;
  t226_tmp_tmp_tmp = in2[1] * t11;
  t226_tmp_tmp = t226_tmp_tmp_tmp * 1.4142135623730951;
  t8 = t226_tmp_tmp * (t13_tmp + 1.0);
  t226 = t8 * t31 * t41 * t55;
  t227_tmp = t28 * t32;
  t227 = t227_tmp * t41 * t55;
  t228 = t36 * t32 * t41 * t55;
  t229_tmp = t7 * t32;
  t229 = t229_tmp * t41 * t55;
  t231 = t8 * t32 * t41 * t55;
  t268_tmp_tmp = t14 * (t13_tmp + 1.0);
  t268_tmp = t268_tmp_tmp * t32 * t41;
  b_t268_tmp = t268_tmp * t55;
  t268 = b_t268_tmp * -2.0;
  t28 = b_t106_tmp * (t13_tmp + 1.0);
  t7 = t28 * t31;
  t275_tmp = t7 * t42 * t55;
  t275 = t275_tmp * 24.0;
  t8 = t28 * t32;
  t276_tmp = t8 * t42 * t55;
  t276 = t276_tmp * 24.0;
  t293_tmp_tmp = t2 * t11 * 1.4142135623730951;
  t28 = t293_tmp_tmp * (t13_tmp + 1.0);
  t293 = t28 * t32 * t42 * t55 * 24.0;
  t294_tmp_tmp = t4 * t11 * 1.4142135623730951;
  t36 = t294_tmp_tmp * (t13_tmp + 1.0);
  t294 = t36 * t32 * t42 * t55 * 24.0;
  t309 = t28 * t31 * t42 * t55 * 24.0;
  t310 = t36 * t31 * t42 * t55 * 24.0;
  t75 = in2[0] * t72;
  t81 = t27 * t38 * t56 * 4.0;
  t82 = t541 * t38 * t56 * 4.0;
  t90_tmp = t293_tmp_tmp * t31;
  t93_tmp = t294_tmp_tmp * t32;
  t192 = t7 * t38 * t56;
  t28 = t540 * (t13_tmp + 1.0);
  t193 = t28 * t31 * t38 * t56;
  t194 = t8 * t38 * t56;
  t195 = t28 * t32 * t38 * t56;
  t201 = t536 * t38 * t56 * 2.0;
  t202 = t489 * t38 * t56 * 2.0;
  t205_tmp = t227_tmp * t38 * t56;
  t205 = t205_tmp * 2.0;
  t206 = t229_tmp * t38 * t56 * 2.0;
  t7 = t106_tmp * t10 * 1.4142135623730951;
  t28 = t7 * (t13_tmp + 1.0);
  t8 = t28 * t31 * t38;
  t218 = t8 * t56 * 4.0;
  t14 = t28 * t32 * t38;
  t220 = t14 * t56 * 4.0;
  t252 = in2[0] * t221;
  t253 = in2[1] * t221;
  t256 = in2[0] * t222;
  t257 = in2[1] * t222;
  t264_tmp = t183_tmp * (t13_tmp + 1.0);
  t28 = b_t106_tmp * t22;
  t266_tmp = t28 * t31 * t39 * t56;
  t266 = t266_tmp * 4.0;
  t267_tmp = t28 * t32 * t39 * t56;
  t267 = t267_tmp * 4.0;
  t28 = t209_tmp * (t13_tmp + 1.0);
  t283 = t28 * t31 * t39 * t56 * 40.0;
  t36 = t210_tmp * (t13_tmp + 1.0);
  t284 = t36 * t31 * t39 * t56 * 40.0;
  t287 = t28 * t32 * t39 * t56 * 40.0;
  t288 = t36 * t32 * t39 * t56 * 40.0;
  t297_tmp = t293_tmp_tmp * t22;
  b_t297_tmp = t297_tmp * t31 * t39 * t56;
  t300_tmp = t294_tmp_tmp * t22;
  b_t300_tmp = t300_tmp * t32 * t39 * t56;
  t318_tmp = t183_tmp * t22;
  t28 = t209_tmp * t22;
  t321 = t28 * t31 * t43 * t57 * 12.0;
  t36 = t210_tmp * t22;
  t322 = t36 * t31 * t43 * t57 * 12.0;
  t323 = t28 * t32 * t43 * t57 * 12.0;
  t324 = t36 * t32 * t43 * t57 * 12.0;
  t28 = in2[0] * s * 1.4142135623730951;
  t551 = t28 * t31 * t40;
  t327_tmp = t551 * t56;
  t327 = t327_tmp * t64;
  t36 = in2[1] * s * 1.4142135623730951;
  t328_tmp = t36 * t31 * t40;
  b_t328_tmp = t328_tmp * t56;
  t328 = b_t328_tmp * t64;
  t329_tmp = t28 * t32 * t40;
  b_t329_tmp = t329_tmp * t56;
  t329 = b_t329_tmp * t64;
  t554 = t36 * t32 * t40;
  t330_tmp = t554 * t56;
  t330 = t330_tmp * t64;
  t332 = t69_tmp * t56 * t64 / 2.0;
  t333 = t70_tmp * t56 * t64 / 2.0;
  t541 = t7 * t32 * t41;
  t338 = t541 * t56 * t64 * 2.0;
  t536 = t7 * t31 * t41;
  t340 = t536 * t56 * t64 * 2.0;
  t28 = t2 * t10 * 1.4142135623730951;
  t540 = t28 * t31 * t41;
  t354 = t540 * t56 * t64 * 2.0;
  t36 = t4 * t10 * 1.4142135623730951;
  t7 = t36 * t31 * t41;
  t355 = t7 * t56 * t64 * 2.0;
  t27 = t28 * t32 * t41;
  t356 = t27 * t56 * t64 * 2.0;
  t489 = t36 * t32 * t41;
  t357 = t489 * t56 * t64 * 2.0;
  t366 = t8 * t57 * t64 * 3.0;
  t367 = t14 * t57 * t64 * 3.0;
  t28 *= t13_tmp + 1.0;
  t372 = t28 * t31 * t38 * t57 * t64 * 3.0;
  t36 *= t13_tmp + 1.0;
  t373 = t36 * t31 * t38 * t57 * t64 * 3.0;
  t374 = t28 * t32 * t38 * t57 * t64 * 3.0;
  t375 = t36 * t32 * t38 * t57 * t64 * 3.0;
  t400 = t79 + t84;
  t401 = t80 + t85;
  t407 = t226_tmp_tmp * t32 * t40 * t55 / 4.0 + t224_tmp_tmp * t31 * t40 * t55 /
    4.0;
  t28 = in2[0] * t12 * 1.4142135623730951;
  t36 = in2[1] * t12 * 1.4142135623730951;
  t408 = t36 * t32 * t40 * t55 / 4.0 + t28 * t31 * t40 * t55 / 4.0;
  t301_tmp = -(t266_tmp * 16.0);
  t304_tmp = -(t267_tmp * 16.0);
  t398 = in2[0] * t71 + in2[1] * t72;
  t402 = t77 + -t86;
  t403 = t78 + -t87;
  t404 = t79 / 2.0 + t84 / 2.0;
  t405 = t80 / 2.0 + t85 / 2.0;
  t406 = t80 / 4.0 + t85 / 4.0;
  t412 = t224_tmp_tmp * t32 * t40 * t55 / 4.0 + -(t226_tmp_tmp * t31 * t40 * t55
    / 4.0);
  t413 = t28 * t32 * t40 * t55 / 4.0 + -(t36 * t31 * t40 * t55 / 4.0);
  t417_tmp = 1.4142135623730951 * t32 * t54;
  t420_tmp = t75 - in2[1] * t69 * 2.0;
  b_t420_tmp = t115_tmp * t54;
  t427 = -t9 * 1.4142135623730951 * (t13_tmp + 1.0) * t32 * t41 * t55 * t420_tmp;
  t458_tmp = t70_tmp_tmp * t55 * t64;
  t461_tmp = t114_tmp * t55 * t64;
  t469_tmp = t268_tmp * t56 * t64;
  t227_tmp = t79_tmp * (t13_tmp + 1.0);
  t470_tmp = t227_tmp * t32 * t41 * t56 * t64;
  t471_tmp = t268_tmp_tmp * t31 * t41 * t56 * t64;
  t229_tmp = t7 * t55;
  t106_tmp = t4 * t10 * 1.4142135623730951 * (t13_tmp + 1.0) * t31 * t38 * t56;
  t475 = (((t69 + in2[1] * t88) + -(t229_tmp * 4.0)) + in2[0] * in2[1] * t10 *
          1.4142135623730951 * (t13_tmp + 1.0) * t32 * t38 * t56 * -2.0) +
    t106_tmp * 2.0;
  b_t106_tmp = t27 * t55;
  t209_tmp = t2 * t10 * 1.4142135623730951 * (t13_tmp + 1.0) * t32 * t38 * t56;
  t476 = (((t70 + in2[1] * t96) + -(b_t106_tmp * 4.0)) + t209_tmp * 2.0) + in2[0]
    * in2[1] * t10 * 1.4142135623730951 * (t13_tmp + 1.0) * t31 * t38 * t56 *
    -2.0;
  t27 = t541 * t55;
  t7 = t540 * t55;
  t8 = t2 * t10 * 1.4142135623730951 * (t13_tmp + 1.0) * t31 * t38 * t56;
  t478 = (((t71 + t27 * -8.0) + -(t7 * 8.0)) + t220) + t8 * 4.0;
  t14 = t536 * t55;
  t28 = t489 * t55;
  t36 = t4 * t10 * 1.4142135623730951 * (t13_tmp + 1.0) * t32 * t38 * t56;
  t481 = (((t72 + t14 * -8.0) + -(t28 * 8.0)) + t218) + t36 * 4.0;
  t482 = (((t112 + -t109) + -(t90_tmp * t41 * t55 * 2.0)) + t194) + t2 * t11 *
    1.4142135623730951 * (t13_tmp + 1.0) * t31 * t38 * t56;
  t210_tmp = t2 * t12 * 1.4142135623730951;
  t69_tmp = t210_tmp * (t13_tmp + 1.0);
  t483 = (((t113 + -t111) + -(t210_tmp * t31 * t41 * t55 * 2.0)) + t195) +
    t69_tmp * t31 * t38 * t56;
  t484 = (((t114 + -t106) + -(t93_tmp * t41 * t55 * 2.0)) + t192) + t4 * t11 *
    1.4142135623730951 * (t13_tmp + 1.0) * t32 * t38 * t56;
  t536 = t4 * t12 * 1.4142135623730951;
  t489 = t536 * (t13_tmp + 1.0);
  t485 = (((t115 + -t108) + -(t536 * t32 * t41 * t55 * 2.0)) + t193) + t489 *
    t32 * t38 * t56;
  t490_tmp = in2[0] * t9 * 1.4142135623730951 * (t13_tmp + 1.0) * t31 * t41 *
    t55;
  b_t490_tmp = in2[1] * t9 * 1.4142135623730951 * (t13_tmp + 1.0) * t32 * t41 *
    t55;
  t490 = ((t490_tmp * 4.0 + b_t490_tmp * 4.0) + t327) + t330;
  t494 = ((t223 + t229) + t497 * t56 * t64 / 4.0) + t537 * t56 * t64 / 4.0;
  t495 = ((t224 + t231) + t526 * t56 * t64 / 4.0) + t525 * t56 * t64 / 4.0;
  t70_tmp = t527 * t22;
  t224_tmp_tmp = t532 * t22;
  t548_tmp = t70_tmp * t32 * t42 * t55;
  b_t548_tmp = t224_tmp_tmp * t31 * t42 * t55;
  t548 = ((((((((-t89 + -t96) + t548_tmp * 12.0) + b_t548_tmp * 12.0) + t551 *
              t57 * t65 * 0.75) + t554 * t57 * t65 * 0.75) + in2[0] * t9 *
            1.4142135623730951 * (t13_tmp + 1.0) * t31 * t41 * t56 * t64 * 2.0)
           + in2[1] * t9 * 1.4142135623730951 * (t13_tmp + 1.0) * t32 * t41 *
           t56 * t64 * 2.0) + t327_tmp * t68 / 2.0) + t330_tmp * t68 / 2.0;
  t409 = t77 / 2.0 + -(t86 / 2.0);
  t410 = t78 / 2.0 + -(t87 / 2.0);
  t411 = t78 / 4.0 + -(t87 / 4.0);
  t414_tmp = t533 * t54;
  t421_tmp = 1.4142135623730951 * t31 * t54;
  t424 = t221_tmp * t398;
  t425 = t222_tmp * t398;
  t430 = t267_tmp * t398 * 2.0;
  t442 = t276_tmp * t398 * 12.0;
  t455_tmp = t69_tmp_tmp * t55 * t64;
  t460_tmp = t112_tmp * t55 * t64;
  t464_tmp = t227_tmp * t31 * t41 * t56 * t64;
  t466 = t470_tmp * t398 / 2.0;
  t474 = (((t69 + t27 * -4.0) + -(t7 * 4.0)) + in2[1] * t205) + t8 * 2.0;
  t477 = (((t70 + t14 * -4.0) + -(t28 * 4.0)) + in2[1] * t201) + t36 * 2.0;
  t479 = (((t71 + in2[1] * 1.4142135623730951 * t32 * t47 * t55) + -(t229_tmp *
            8.0)) + -t220) + t106_tmp * 4.0;
  t480 = (((t72 + in2[1] * 1.4142135623730951 * t31 * t47 * t55) + -(b_t106_tmp *
            8.0)) + t209_tmp * 4.0) + -t218;
  t14 = t294_tmp_tmp * t31;
  t486 = (((t109 + t112) + -(t14 * t41 * t55 * 2.0)) + t4 * t11 *
          1.4142135623730951 * (t13_tmp + 1.0) * t31 * t38 * t56) + -t194;
  t487 = (((t111 + t113) + -(t536 * t31 * t41 * t55 * 2.0)) + t489 * t31 * t38 *
          t56) + -t195;
  t8 = t293_tmp_tmp * t32;
  t70 = (((t106 + t114) + -(t8 * t41 * t55 * 2.0)) + t2 * t11 *
         1.4142135623730951 * (t13_tmp + 1.0) * t32 * t38 * t56) + -t192;
  t489 = (((t108 + t115) + -(t210_tmp * t32 * t41 * t55 * 2.0)) + t69_tmp * t32 *
          t38 * t56) + -t193;
  t114 = in2[1] * t9 * 1.4142135623730951 * (t13_tmp + 1.0) * t31 * t41 * t55;
  t106 = ((t114 * 4.0 + -(b_t268_tmp * 4.0)) + t328) + -t329;
  t47 = ((t252 + t257) + t327 / 2.0) + t330 / 2.0;
  out2[0] = t9;
  out2[1] = 0.0;
  out2[2] = 0.0;
  out2[3] = ((in2[0] * t425 + t417_tmp * t474) + t421_tmp * t476) + t490_tmp *
    t420_tmp;
  out2[4] = ((in2[0] * t424 + in2[0] * t427) + t421_tmp * t474) - t417_tmp *
    t476;
  out2[5] = t398 * t476 - t474 * t420_tmp;
  out2[6] = 0.0;
  out2[7] = t9;
  out2[8] = 0.0;
  out2[9] = ((in2[1] * t425 - t421_tmp * t475) + t417_tmp * t477) + t114 *
    t420_tmp;
  out2[10] = ((in2[1] * t424 + in2[1] * t427) + t417_tmp * t475) + t421_tmp *
    t477;
  out2[11] = -t398 * t475 - t477 * t420_tmp;
  out2[12] = 0.0;
  out2[13] = 0.0;
  out2[14] = t9;
  t111 = ((t256 - t328 / 2.0) + t329 / 2.0) - t114 * 2.0;
  t86 = 1.4142135623730951 * t32 * t55;
  t113 = t86 * t64;
  t194 = 1.4142135623730951 * t31 * t55;
  t71 = t194 * t64;
  t72 = -1.4142135623730951 * t32 * t54;
  out2[15] = ((t72 * t47 - t421_tmp * t111) - t71 * t420_tmp / 4.0) - t113 *
    t398 / 4.0;
  t193 = -1.4142135623730951 * t31 * t54;
  out2[16] = ((t193 * t47 + t417_tmp * t111) + t113 * t420_tmp / 4.0) - t71 *
    t398 / 4.0;
  out2[17] = -t398 * t111 + t47 * t420_tmp;
  out2[18] = 0.0;
  out2[19] = 0.0;
  out2[20] = 0.0;
  b_t268_tmp = t69_tmp_tmp * t54;
  t293_tmp_tmp = t70_tmp_tmp * t54;
  out2[21] = ((t421_tmp * t404 - t417_tmp * t409) + t293_tmp_tmp * t420_tmp /
              4.0) - b_t268_tmp * t398 / 4.0;
  out2[22] = ((t72 * t404 - t421_tmp * t409) + b_t268_tmp * t420_tmp / 4.0) +
    t293_tmp_tmp * t398 / 4.0;
  t109 = s * t33;
  t112 = s * t34;
  out2[23] = ((t398 * t404 + t409 * t420_tmp) + t109 * t50_tmp / 2.0) + t112 *
    t50_tmp / 2.0;
  out2[24] = 0.0;
  out2[25] = 0.0;
  out2[26] = 0.0;
  t294_tmp_tmp = t112_tmp * t54;
  t195 = t114_tmp * t54;
  t221_tmp = t195 * t420_tmp;
  t222_tmp = t294_tmp_tmp * t398;
  out2[27] = ((t421_tmp * t405 - t417_tmp * t410) + t221_tmp / 4.0) - t222_tmp /
    4.0;
  t78 = t294_tmp_tmp * t420_tmp;
  t87 = t195 * t398;
  out2[28] = ((t72 * t405 - t421_tmp * t410) + t78 / 4.0) + t87 / 4.0;
  t72 = t9 * t33;
  t192 = t9 * t34;
  out2[29] = ((t398 * t405 + t410 * t420_tmp) + t72 * t50_tmp / 2.0) + t192 *
    t50_tmp / 2.0;
  t77 = ((t225 + -t227) + t86_tmp * t56 * t64 / 4.0) + -(t77_tmp * t56 * t64 /
    4.0);
  t497 = ((t226 + -t228) + t87_tmp * t56 * t64 / 4.0) + -(t78_tmp * t56 * t64 /
    4.0);
  t328 = t398 * t482;
  t525 = t398 * t483;
  t526 = t398 * t484;
  t527 = t398 * t485;
  t532 = t398 * t494;
  t533 = t398 * t495;
  t536 = ((((((((-t89 + -(t96_tmp * 12.0)) + t183_tmp * t31 * t42 * t55 * 48.0)
               + in2[0] * t10 * 1.4142135623730951 * (t13_tmp + 1.0) * t31 * t38
               * t56 * 6.0) + t206) + t212) + -(t264_tmp * t31 * t39 * t56 *
             40.0)) + -t288) + t318_tmp * t31 * t43 * t57 * 12.0) + t324;
  t36 = muDoubleScalarPower(in2[1], 3.0) * t12 * 1.4142135623730951;
  t7 = t36 * (t13_tmp + 1.0);
  t28 = t36 * t22;
  t537 = ((((((((-t96 + -(t89_tmp * 12.0)) + t36 * t32 * t42 * t55 * 48.0) +
               t201) + in2[1] * t10 * 1.4142135623730951 * (t13_tmp + 1.0) * t32
              * t38 * t56 * 6.0) + t209) + -(t7 * t32 * t39 * t56 * 40.0)) +
           -t283) + t28 * t32 * t43 * t57 * 12.0) + t321;
  t329 = ((((((((t88 + -(t97_tmp * 12.0)) + t36 * t31 * t42 * t55 * 48.0) + in2
               [1] * t10 * 1.4142135623730951 * (t13_tmp + 1.0) * t31 * t38 *
               t56 * 6.0) + -t205) + -t211) + t287) + -(t7 * t31 * t39 * t56 *
            40.0)) + t28 * t31 * t43 * t57 * 12.0) + -t323;
  t540 = ((((((((-t88 + -t97) + t202) + t205) + t210) + t211) + -t284) + -t287)
          + t322) + t323;
  t541 = ((((((((t89 + -t96) + t201) + t209) + -t206) + -t212) + t288) + -t283)
          + t321) + -t324;
  t327 = t70_tmp * t31 * t42 * t55;
  t218 = t224_tmp_tmp * t32 * t42 * t55;
  t330 = ((((((((t88 + -t97) + t327 * 12.0) + -(t218 * 12.0)) + t328_tmp * t57 *
              t65 * 0.75) + -(t329_tmp * t57 * t65 * 0.75)) + in2[1] * t9 *
            1.4142135623730951 * (t13_tmp + 1.0) * t31 * t41 * t56 * t64 * 2.0)
           + -(t469_tmp * 2.0)) + b_t328_tmp * t68 / 2.0) + -(b_t329_tmp * t68 /
    2.0);
  t79_tmp = t300_tmp * t31 * t39 * t56;
  t220 = ((((((((((t82 + -(t14 * t38 * t56 * 4.0)) + t221) + t276) + t79_tmp *
                16.0) + t304_tmp) + -t310) + t332) + t338) + -t355) + t373) +
    -t367;
  t27 = t297_tmp * t32 * t39 * t56;
  t551 = ((((((((((t81 + -(t8 * t38 * t56 * 4.0)) + t222) + t275) + t27 * 16.0)
               + t301_tmp) + -t293) + t333) + t340) + -t356) + t374) + -t366;
  t554 = ((((((((((t221 + t276) + t79_tmp * 4.0) + -t267) + -t310) + t332) +
              t338) + -t355) + t373) + -t367) + b_t329_tmp * t67 / 2.0) +
    -(b_t328_tmp * t67 / 2.0);
  t8 = ((((((((((t222 + t275) + t27 * 4.0) + -t266) + -t293) + t333) + t340) +
           -t356) + t374) + -t366) + b_t328_tmp * t66 / 2.0) + -(b_t329_tmp *
    t66 / 2.0);
  t28 = ((((((((((t221 + t267) + b_t297_tmp * 4.0) + -t276) + -t309) + t332) +
             -t338) + -t354) + t367) + t372) + -(t327_tmp * t66 / 2.0)) +
    -(t330_tmp * t66 / 2.0);
  t14 = ((((((((((t222 + t266) + b_t300_tmp * 4.0) + -t275) + -t294) + t333) +
             -t340) + -t357) + t366) + t375) + -(t327_tmp * t67 / 2.0)) +
    -(t330_tmp * t67 / 2.0);
  t36 = t417_tmp * t540;
  t7 = t421_tmp * t541;
  t40 = t398 * t541;
  out3[0] = 0.0;
  out3[1] = 0.0;
  out3[2] = 0.0;
  t85 = ((((((((t97 - t88_tmp * 12.0) + t183_tmp * t32 * t42 * t55 * 48.0) -
              t202) + t205_tmp * 6.0) - t210) - t264_tmp * t32 * t39 * t56 *
           40.0) + t284) + t318_tmp * t32 * t43 * t57 * 12.0) - t322;
  t115_tmp = t2 * t11 * 1.4142135623730951 * (t13_tmp + 1.0) * t32 * t42 * t55;
  t268_tmp_tmp = in2[0] * t9 * 1.4142135623730951 * (t13_tmp + 1.0) * t32 * t41 *
    t55;
  t268_tmp = t2 * t11 * 1.4142135623730951 * (t13_tmp + 1.0) * t31 * t42 * t55;
  t80 = t86 * t66;
  t69_tmp = t194 * t66;
  t70_tmp = t9 * 1.4142135623730951 * (t13_tmp + 1.0) * t31 * t41 * t55 *
    t420_tmp;
  t224_tmp_tmp = t266_tmp * t420_tmp;
  t226_tmp_tmp = t469_tmp * t398 / 2.0 + t471_tmp * t420_tmp / 2.0;
  t79 = ((t223 * t398 / 2.0 + t227 * t420_tmp * -0.5) + t421_tmp * t482) +
    -(t417_tmp * t70);
  t84 = ((t224 * t398 / 2.0 + t228 * t420_tmp * -0.5) + t421_tmp * t483) +
    -(t417_tmp * t489);
  out3[3] = (((in2[5] * (((((((((((t425 + t268 * t474) + t417_tmp * t536) +
    t421_tmp * t85) + t70_tmp) - t268_tmp * t420_tmp * 12.0) + b_t297_tmp *
    t420_tmp * 2.0) - t490_tmp * t476 * 2.0) + t268_tmp_tmp * t478) + t490_tmp *
    t480) - t115_tmp * t398 * 12.0) + t27 * t398 * 2.0) - in2[7] *
               ((((((((t226_tmp_tmp + t268 * t47) + t421_tmp * t8) + t417_tmp *
                     t28) - t69_tmp * t420_tmp / 4.0) - t80 * t398 / 4.0) + t113
                  * t478 / 4.0) + t71 * t480 / 4.0) - t490_tmp * t111 * 2.0)) +
              in2[8] * ((((t79 + t256 * t409) - b_t268_tmp * t478 / 4.0) +
    t293_tmp_tmp * t480 / 4.0) - t490_tmp * t404 * 2.0)) + in2[9] * ((((t84 +
    t256 * t410) - t294_tmp_tmp * t478 / 4.0) + t195 * t480 / 4.0) - t490_tmp *
              t405 * 2.0)) + in2[6] * (((((((((t430 - t442) + t275_tmp *
    t420_tmp * -12.0) + t36) - t7) + t252 * t475) + t268 * t477) + b_t490_tmp *
    t478) + t114 * t480) + t224_tmp_tmp * 2.0);
  t210_tmp = ((((t266_tmp * t398 * 2.0 + t267_tmp * t420_tmp * -2.0) + -(in2[0] *
    in2[1] * t11 * 1.4142135623730951 * (t13_tmp + 1.0) * t31 * t42 * t55 * t398
    * 12.0)) + t276_tmp * t420_tmp * 12.0) + t421_tmp * t540) + t417_tmp * t541;
  t209_tmp = t471_tmp * t398 / 2.0 + t469_tmp * t420_tmp * -0.5;
  b_t106_tmp = (t227 * t398 / 2.0 + t417_tmp * t482) + t421_tmp * t70;
  t106_tmp = t223 * t420_tmp / 2.0;
  t229_tmp = (t228 * t398 / 2.0 + t417_tmp * t483) + t421_tmp * t489;
  t227_tmp = t224 * t420_tmp / 2.0;
  out3[4] = (((-in2[8] * (((((b_t106_tmp + t268 * t404) + t106_tmp) -
    t293_tmp_tmp * t478 / 4.0) - b_t268_tmp * t480 / 4.0) - t490_tmp * t409 *
    2.0) - in2[9] * (((((t229_tmp + t268 * t405) + t227_tmp) - t195 * t478 / 4.0)
                      - t294_tmp_tmp * t480 / 4.0) - t490_tmp * t410 * 2.0)) +
              in2[6] * ((((t210_tmp + t268 * t475) - t490_tmp * t477 * 2.0) +
    t114 * t478) - b_t490_tmp * t480)) - in2[5] * (((((((((((-t424 + t252 * t474)
    + t268 * t476) - t421_tmp * t536) + t417_tmp * t85) + t9 *
    1.4142135623730951 * (t13_tmp + 1.0) * t32 * t41 * t55 * t420_tmp) -
    t115_tmp * t420_tmp * 12.0) + t27 * t420_tmp * 2.0) - t490_tmp * t478) +
    t268_tmp_tmp * t480) + t268_tmp * t398 * 12.0) - b_t297_tmp * t398 * 2.0)) -
    in2[7] * ((((((((t209_tmp + t421_tmp * t28) - t417_tmp * t8) + t80 *
                   t420_tmp / 4.0) - t69_tmp * t398 / 4.0) + t71 * t478 / 4.0) -
                t113 * t480 / 4.0) + t268_tmp_tmp * t111 * 2.0) - t490_tmp * t47
              * 2.0);
  t115_tmp = t47_tmp * (t13_tmp + 1.0);
  t268_tmp = t224_tmp_tmp_tmp * (t13_tmp + 1.0);
  t80 = t540 * t420_tmp;
  t69_tmp = t70 * t420_tmp;
  t489 *= t420_tmp;
  out3[5] = (((-in2[6] * (((t40 + t475 * t478) + t477 * t480) + t80) - in2[7] *
               (((t398 * t8 - t480 * t47) + t478 * t111) - t28 * t420_tmp)) -
              in2[5] * (((t474 * t480 - t476 * t478) - t398 * t85) + t536 *
                        t420_tmp)) + in2[8] * (((((t328 + t404 * t478) + t409 *
    t480) + t69_tmp) - t115_tmp * t33 * t41 * 2.0) - t115_tmp * t34 * t41 * 2.0))
    + in2[9] * (((((t525 + t405 * t478) + t410 * t480) + t489) - t268_tmp * t33 *
                 t41 * 2.0) - t268_tmp * t34 * t41 * 2.0);
  out3[6] = 0.0;
  out3[7] = 0.0;
  out3[8] = 0.0;
  t85 = t86 * t67;
  t115_tmp = t194 * t67;
  t268_tmp = t4 * t11 * 1.4142135623730951 * (t13_tmp + 1.0) * t32 * t42 * t55;
  t541 = t4 * t11 * 1.4142135623730951 * (t13_tmp + 1.0) * t31 * t42 * t55;
  t540 = ((t225 * t398 / 2.0 + t229 * t420_tmp * -0.5) + t421_tmp * t484) +
    t417_tmp * t486;
  t536 = ((t226 * t398 / 2.0 + t231 * t420_tmp * -0.5) + t421_tmp * t485) +
    t417_tmp * t487;
  out3[9] = (((in2[8] * ((((t540 + t257 * t409) - t293_tmp_tmp * t479 / 4.0) -
    b_t268_tmp * t481 / 4.0) - t114 * t404 * 2.0) + in2[9] * ((((t536 + t257 *
    t410) - t195 * t479 / 4.0) - t294_tmp_tmp * t481 / 4.0) - t114 * t405 * 2.0))
              + in2[6] * (((((((((((t425 + t253 * t475) + t417_tmp * t537) -
    t421_tmp * t329) + t70_tmp) - t541 * t420_tmp * 12.0) + t79_tmp * t420_tmp *
    2.0) - b_t490_tmp * t477 * 2.0) - t114 * t479) + b_t490_tmp * t481) -
    t268_tmp * t398 * 12.0) + b_t300_tmp * t398 * 2.0)) + in2[7] *
             (((((((((-t466 + t464_tmp * t420_tmp * -0.5) + t257 * t47) + t253 *
                    t111) + t421_tmp * t554) - t417_tmp * t14) + t115_tmp *
                 t420_tmp / 4.0) + t85 * t398 / 4.0) + t71 * t479 / 4.0) - t113 *
              t481 / 4.0)) - in2[5] * (((((((((-t430 + t224_tmp_tmp * -2.0) +
    t442) - t36) + t7) + t253 * t476) + t257 * t474) + t490_tmp * t479) -
    t268_tmp_tmp * t481) + in2[0] * in2[1] * t11 * 1.4142135623730951 * (t13_tmp
    + 1.0) * t31 * t42 * t55 * (t75 - in2[1] * t69 * 2.0) * 12.0);
  t70_tmp = t464_tmp * t398 / 2.0 + t470_tmp * t420_tmp * -0.5;
  t224_tmp_tmp = ((t229 * t398 / 2.0 + t417_tmp * t484) - t421_tmp * t486) +
    t225 * t420_tmp / 2.0;
  t27 = ((t231 * t398 / 2.0 + t417_tmp * t485) - t421_tmp * t487) + t226 *
    t420_tmp / 2.0;
  out3[10] = (((-in2[8] * ((((t224_tmp_tmp + b_t268_tmp * t479 / 4.0) -
    t293_tmp_tmp * t481 / 4.0) - b_t490_tmp * t404 * 2.0) - t114 * t409 * 2.0) -
                in2[9] * ((((t27 + t294_tmp_tmp * t479 / 4.0) - t195 * t481 /
    4.0) - b_t490_tmp * t405 * 2.0) - t114 * t410 * 2.0)) - in2[7] *
               ((((((((t70_tmp + t257 * t111) + t417_tmp * t554) + t421_tmp *
                     t14) + t85 * t420_tmp / 4.0) - t115_tmp * t398 / 4.0) +
                  t113 * t479 / 4.0) + t71 * t481 / 4.0) - t114 * t47 * 2.0)) +
              in2[5] * ((((t210_tmp + t257 * t476) - t114 * t474 * 2.0) +
    t268_tmp_tmp * t479) + t490_tmp * t481)) + in2[6] * (((((((((((t424 + t427)
    + t421_tmp * t537) + t417_tmp * t329) + t268_tmp * t420_tmp * 12.0) -
    b_t300_tmp * t420_tmp * 2.0) - b_t490_tmp * t475 * 2.0) - t114 * t477 * 2.0)
    + b_t490_tmp * t479) + t114 * t481) - t541 * t398 * 12.0) + t79_tmp * t398 *
    2.0);
  t85 = t67_tmp * (t13_tmp + 1.0);
  t115_tmp = t226_tmp_tmp_tmp * (t13_tmp + 1.0);
  out3[11] = (((-in2[5] * (((t40 - t474 * t479) - t476 * t481) + t80) + in2[7] *
                (((t398 * t554 - t479 * t47) - t481 * t111) + t14 * t420_tmp)) -
               in2[8] * (((((-t526 - t404 * t481) + t409 * t479) + t486 *
    t420_tmp) + t85 * t33 * t41 * 2.0) + t85 * t34 * t41 * 2.0)) - in2[9] *
              (((((-t527 - t405 * t481) + t410 * t479) + t487 * t420_tmp) +
                t115_tmp * t33 * t41 * 2.0) + t115_tmp * t34 * t41 * 2.0)) -
    in2[6] * (((t398 * t329 + t475 * t481) - t477 * t479) + t537 * t420_tmp);
  out3[12] = 0.0;
  out3[13] = 0.0;
  out3[14] = 0.0;
  t85 = 1.4142135623730951 * t32 * t56 * t65;
  t115_tmp = t86 * t68;
  t268_tmp = 1.4142135623730951 * t31 * t56 * t65;
  t80 = t194 * t68;
  t210_tmp = ((((((((((t82 + t90_tmp * t38 * t56 * 4.0) - t221) + t276) -
                    b_t297_tmp * 16.0) + t304_tmp) + t309) - t332) + t338) +
               t354) - t372) + -t367;
  t541 = ((((((((((t81 + t93_tmp * t38 * t56 * 4.0) - t222) + t275) + t294) -
               b_t300_tmp * 16.0) + t301_tmp) - t333) + t340) + t357) - t375) +
    -t366;
  t8 = ((t455_tmp * t398 / 8.0 + t458_tmp * t420_tmp * -0.125) + t421_tmp * t494)
    + t417_tmp * t77;
  t14 = ((t460_tmp * t398 / 8.0 + t461_tmp * t420_tmp * -0.125) + t421_tmp *
         t495) + t417_tmp * t497;
  out3[15] = (((in2[7] * (((((((((t193 * t330 + t417_tmp * t548) + t268_tmp *
    t420_tmp / 8.0) + t80 * t420_tmp / 4.0) + t85 * t398 / 8.0) + t115_tmp *
    t398 / 4.0) - t71 * t106 / 4.0) + t113 * t490 / 4.0) - t113 * t47 / 2.0) -
    t71 * t111 / 2.0) - in2[6] * (((((((((((t466 - t417_tmp * t541) - t421_tmp *
    t220) + t71 * t475 / 2.0) - t113 * t477 / 2.0) - t97_tmp * t420_tmp * 2.0) -
    t89_tmp * t398 * 2.0) + t327 * t420_tmp * 6.0) + t548_tmp * t398 * 6.0) -
    t114 * t106) + b_t490_tmp * t490) + in2[1] * t9 * 1.4142135623730951 *
    (t13_tmp + 1.0) * t31 * t41 * t56 * t64 * (t75 - in2[1] * t69 * 2.0) / 2.0))
               - in2[8] * ((((t8 - b_t268_tmp * t490 / 4.0) - t293_tmp_tmp *
    t106 / 4.0) - t71 * t404 / 2.0) + t113 * t409 / 2.0)) - in2[9] * ((((t14 -
    t71 * t405 / 2.0) + t113 * t410 / 2.0) - t294_tmp_tmp * t490 / 4.0) - t195 *
    t106 / 4.0)) - in2[5] * ((((((((((t226_tmp_tmp - t417_tmp * t210_tmp) +
    t421_tmp * t551) - t113 * t474 / 2.0) - t71 * t476 / 2.0) - t96_tmp *
    t420_tmp * 2.0) - t88_tmp * t398 * 2.0) + b_t548_tmp * t420_tmp * 6.0) +
    t218 * t398 * 6.0) - t490_tmp * t106) + t268_tmp_tmp * t490);
  t226_tmp_tmp = (t458_tmp * t398 / 8.0 + t417_tmp * t494) - t421_tmp * t77;
  t7 = t455_tmp * t420_tmp / 8.0;
  t36 = (t461_tmp * t398 / 8.0 + t417_tmp * t495) - t421_tmp * t497;
  t28 = t460_tmp * t420_tmp / 8.0;
  out3[16] = (((in2[7] * (((((((((t421_tmp * t548 + t417_tmp * t330) - t85 *
    t420_tmp / 8.0) - t115_tmp * t420_tmp / 4.0) + t268_tmp * t398 / 8.0) + t80 *
    t398 / 4.0) + t71 * t490 / 4.0) - t71 * t47 / 2.0) + t113 * t106 / 4.0) +
    t113 * t111 / 2.0) + in2[8] * (((((t226_tmp_tmp + b_t268_tmp * t106 / 4.0) -
    t293_tmp_tmp * t490 / 4.0) - t113 * t404 / 2.0) - t71 * t409 / 2.0) + t7)) +
               in2[9] * (((((t36 - t113 * t405 / 2.0) - t71 * t410 / 2.0) +
    t294_tmp_tmp * t106 / 4.0) - t195 * t490 / 4.0) + t28)) - in2[5] *
              ((((((((((t209_tmp - t421_tmp * t210_tmp) - t417_tmp * t551) - t71
                      * t474 / 2.0) + t113 * t476 / 2.0) + t88_tmp * t420_tmp *
                    2.0) - t96_tmp * t398 * 2.0) - t218 * t420_tmp * 6.0) +
                 b_t548_tmp * t398 * 6.0) + t490_tmp * t490) + t268_tmp_tmp *
               t106)) - in2[6] * ((((((((((t70_tmp - t421_tmp * t541) + t417_tmp
    * t220) - t113 * t475 / 2.0) - t71 * t477 / 2.0) + t89_tmp * t420_tmp * 2.0)
    - t97_tmp * t398 * 2.0) - t548_tmp * t420_tmp * 6.0) + t327 * t398 * 6.0) +
    t114 * t490) + b_t490_tmp * t106);
  t85 = t77 * t420_tmp;
  t115_tmp = t497 * t420_tmp;
  out3[17] = (((-in2[7] * (((t398 * t330 - t106 * t47) - t490 * t111) + t548 *
    t420_tmp) + in2[6] * (((t398 * t220 + t475 * t490) - t477 * t106) - t420_tmp
    * t541)) - in2[5] * (((t398 * t551 + t474 * t106) + t476 * t490) + t420_tmp *
    t210_tmp)) + in2[8] * (((((-t532 - t404 * t490) + t409 * t106) + t85) + t109
    * t64 / 2.0) + t112 * t64 / 2.0)) + in2[9] * (((((-t533 - t405 * t490) +
    t410 * t106) + t115_tmp) + t72 * t64 / 2.0) + t192 * t64 / 2.0);
  out3[18] = 0.0;
  out3[19] = 0.0;
  out3[20] = 0.0;
  t268_tmp = ((b_t420_tmp * t398 / 8.0 - t417_tmp * t407) - t421_tmp * t412) +
    t414_tmp * t420_tmp / 8.0;
  out3[21] = (((-in2[8] * (((((((t417_tmp * t406 + t421_tmp * t411) - t78 / 8.0)
    - t293_tmp_tmp * t400 / 4.0) - b_t268_tmp * t402 / 4.0) + t293_tmp_tmp *
    t404 / 2.0) + b_t268_tmp * t409 / 2.0) - t87 / 8.0) + in2[9] * ((((t268_tmp
    - t293_tmp_tmp * t405 / 2.0) - b_t268_tmp * t410 / 2.0) + t195 * t400 / 4.0)
    + t294_tmp_tmp * t402 / 4.0)) + in2[5] * ((((t79 + b_t268_tmp * t474 / 2.0)
    - t293_tmp_tmp * t476 / 2.0) + t490_tmp * t400) - t268_tmp_tmp * t402)) +
              in2[6] * ((((t540 + t293_tmp_tmp * t475 / 2.0) + b_t268_tmp * t477
    / 2.0) + t114 * t400) - b_t490_tmp * t402)) - in2[7] * ((((t8 + b_t268_tmp *
    t47 / 2.0) + t71 * t400 / 4.0) - t113 * t402 / 4.0) - t293_tmp_tmp * t111 /
    2.0);
  t80 = ((t414_tmp * t398 / 8.0 + b_t420_tmp * t420_tmp * -0.125) + t417_tmp *
         t412) + -(t421_tmp * t407);
  out3[22] = (((-in2[8] * (((((((t421_tmp * t406 - t417_tmp * t411) + t221_tmp /
    8.0) - b_t268_tmp * t400 / 4.0) + t293_tmp_tmp * t402 / 4.0) + b_t268_tmp *
    t404 / 2.0) - t293_tmp_tmp * t409 / 2.0) - t222_tmp / 8.0) - in2[6] *
                ((((t224_tmp_tmp - b_t268_tmp * t475 / 2.0) + t293_tmp_tmp *
                   t477 / 2.0) + b_t490_tmp * t400) + t114 * t402)) + in2[7] *
               (((((t226_tmp_tmp + t293_tmp_tmp * t47 / 2.0) + t113 * t400 / 4.0)
                  + t71 * t402 / 4.0) + b_t268_tmp * t111 / 2.0) + t7)) + in2[9]
              * ((((t80 - b_t268_tmp * t405 / 2.0) + t293_tmp_tmp * t410 / 2.0)
                  + t294_tmp_tmp * t400 / 4.0) - t195 * t402 / 4.0)) - in2[5] *
    (((((b_t106_tmp + t106_tmp) + t293_tmp_tmp * t474 / 2.0) + b_t268_tmp * t476
       / 2.0) + t268_tmp_tmp * t400) + t490_tmp * t402);
  t70_tmp = t398 * t412 + -t407 * t420_tmp;
  out3[23] = (((in2[5] * (((t328 - t400 * t474) - t402 * t476) + t69_tmp) - in2
                [9] * ((t70_tmp + t402 * t405) - t400 * t410)) + in2[6] *
               (((t526 + -t486 * t420_tmp) - t400 * t477) + t402 * t475)) + in2
              [7] * (((-t532 + t400 * t47) + t402 * t111) + t85)) - in2[8] *
    (((t402 * t404 + t398 * t411) - t400 * t409) - t406 * t420_tmp);
  out3[24] = 0.0;
  out3[25] = 0.0;
  out3[26] = 0.0;
  t85 = t11 * 1.4142135623730951 * t32 * t54;
  t69_tmp = t11 * 1.4142135623730951 * t31 * t54;
  out3[27] = (((-in2[9] * (((((((t417_tmp * t408 + t421_tmp * t413) - t69_tmp *
    t420_tmp / 8.0) - t85 * t398 / 8.0) - t195 * t401 / 4.0) - t294_tmp_tmp *
    t403 / 4.0) + t195 * t405 / 2.0) + t294_tmp_tmp * t410 / 2.0) + in2[8] *
                ((((t268_tmp + t293_tmp_tmp * t401 / 4.0) + b_t268_tmp * t403 /
                   4.0) - t195 * t404 / 2.0) - t294_tmp_tmp * t409 / 2.0)) +
               in2[5] * ((((t84 + t294_tmp_tmp * t474 / 2.0) - t195 * t476 / 2.0)
    + t490_tmp * t401) - t268_tmp_tmp * t403)) + in2[6] * ((((t536 + t195 * t475
    / 2.0) + t294_tmp_tmp * t477 / 2.0) + t114 * t401) - b_t490_tmp * t403)) -
    in2[7] * ((((t14 + t71 * t401 / 4.0) - t113 * t403 / 4.0) + t294_tmp_tmp *
               t47 / 2.0) - t195 * t111 / 2.0);
  out3[28] = (((-in2[9] * (((((((t421_tmp * t408 - t417_tmp * t413) + t85 *
    t420_tmp / 8.0) - t69_tmp * t398 / 8.0) - t294_tmp_tmp * t401 / 4.0) + t195 *
    t403 / 4.0) + t294_tmp_tmp * t405 / 2.0) - t195 * t410 / 2.0) - in2[6] *
                ((((t27 - t294_tmp_tmp * t475 / 2.0) + t195 * t477 / 2.0) +
                  b_t490_tmp * t401) + t114 * t403)) + in2[7] * (((((t36 + t113 *
    t401 / 4.0) + t71 * t403 / 4.0) + t195 * t47 / 2.0) + t294_tmp_tmp * t111 /
    2.0) + t28)) + in2[8] * ((((t80 + b_t268_tmp * t401 / 4.0) - t293_tmp_tmp *
    t403 / 4.0) - t294_tmp_tmp * t404 / 2.0) + t195 * t409 / 2.0)) - in2[5] *
    (((((t229_tmp + t227_tmp) + t195 * t474 / 2.0) + t294_tmp_tmp * t476 / 2.0)
      + t268_tmp_tmp * t401) + t490_tmp * t403);
  out3[29] = (((in2[5] * (((t525 - t401 * t474) - t403 * t476) + t489) - in2[8] *
                ((t70_tmp + t403 * t404) - t401 * t409)) + in2[6] * (((t527 +
    -t487 * t420_tmp) - t401 * t477) + t403 * t475)) + in2[7] * (((-t533 + t401 *
    t47) + t403 * t111) + t115_tmp)) - in2[9] * (((t403 * t405 + t398 * t413) -
    t401 * t410) - t408 * t420_tmp);
  out4[0] = in1[12];
  out4[1] = in1[13];
  out4[2] = in1[14];
  out4[3] = 0.0;
  out4[4] = 0.0;
  out4[5] = 0.0;
}

/* End of code generation (massF1.c) */
