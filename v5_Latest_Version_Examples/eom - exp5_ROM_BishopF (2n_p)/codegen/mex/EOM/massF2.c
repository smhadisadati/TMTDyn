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
#include "massF2.h"
#include "EOM_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo ed_emlrtRSI = { 59, /* lineNo */
  "massF2",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\massF2.m"/* pathName */
};

static emlrtRSInfo id_emlrtRSI = { 78, /* lineNo */
  "massF2",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\massF2.m"/* pathName */
};

/* Function Definitions */
void massF2(const emlrtStack *sp, const real_T in1[34], const real_T in2[10],
            real_T out1[36], real_T out2[30], real_T out3[30], real_T out4[6])
{
  emlrtStack st;
  real_T b_t266_tmp;
  real_T b_t331_tmp;
  real_T b_t332_tmp;
  real_T b_t433_tmp;
  real_T b_t577_tmp_tmp;
  real_T b_t633_tmp;
  real_T b_t761_tmp;
  real_T b_t81_tmp;
  real_T b_t82_tmp;
  real_T b_t852_tmp;
  real_T b_t853_tmp;
  real_T b_t99_tmp;
  real_T c_t99_tmp;
  real_T t101;
  real_T t101_tmp;
  real_T t102;
  real_T t102_tmp;
  real_T t104;
  real_T t105;
  real_T t105_tmp;
  real_T t106;
  real_T t107;
  real_T t107_tmp;
  real_T t108;
  real_T t11;
  real_T t12_tmp;
  real_T t19;
  real_T t194;
  real_T t195;
  real_T t198;
  real_T t199;
  real_T t2;
  real_T t202;
  real_T t202_tmp_tmp;
  real_T t203;
  real_T t204;
  real_T t205;
  real_T t206;
  real_T t207;
  real_T t208;
  real_T t209;
  real_T t210;
  real_T t211;
  real_T t212;
  real_T t212_tmp_tmp;
  real_T t212_tmp_tmp_tmp;
  real_T t214;
  real_T t214_tmp_tmp;
  real_T t214_tmp_tmp_tmp;
  real_T t216;
  real_T t216_tmp;
  real_T t217;
  real_T t217_tmp;
  real_T t218;
  real_T t220;
  real_T t233;
  real_T t235;
  real_T t236;
  real_T t237;
  real_T t238;
  real_T t239;
  real_T t242;
  real_T t243;
  real_T t25;
  real_T t26;
  real_T t264;
  real_T t264_tmp;
  real_T t265;
  real_T t265_tmp;
  real_T t266;
  real_T t266_tmp;
  real_T t27;
  real_T t279;
  real_T t28;
  real_T t280;
  real_T t281;
  real_T t283;
  real_T t284;
  real_T t285;
  real_T t29;
  real_T t290;
  real_T t290_tmp;
  real_T t291;
  real_T t291_tmp;
  real_T t3;
  real_T t304;
  real_T t305;
  real_T t305_tmp_tmp;
  real_T t308;
  real_T t309;
  real_T t31;
  real_T t32;
  real_T t323;
  real_T t324;
  real_T t325;
  real_T t326;
  real_T t33;
  real_T t330;
  real_T t330_tmp;
  real_T t331;
  real_T t331_tmp;
  real_T t332;
  real_T t332_tmp;
  real_T t333;
  real_T t333_tmp;
  real_T t334;
  real_T t335;
  real_T t34;
  real_T t343;
  real_T t344;
  real_T t35;
  real_T t358;
  real_T t359;
  real_T t36;
  real_T t360;
  real_T t361;
  real_T t37;
  real_T t371;
  real_T t372;
  real_T t373;
  real_T t374;
  real_T t375;
  real_T t376;
  real_T t39;
  real_T t39_tmp;
  real_T t4;
  real_T t405;
  real_T t406;
  real_T t407;
  real_T t409;
  real_T t410;
  real_T t411;
  real_T t412;
  real_T t413;
  real_T t414;
  real_T t415;
  real_T t416;
  real_T t417;
  real_T t418;
  real_T t419;
  real_T t420;
  real_T t421;
  real_T t422;
  real_T t425_tmp;
  real_T t429;
  real_T t429_tmp;
  real_T t42_tmp;
  real_T t432;
  real_T t432_tmp;
  real_T t433_tmp;
  real_T t435;
  real_T t437;
  real_T t459;
  real_T t46;
  real_T t460;
  real_T t461;
  real_T t462;
  real_T t463;
  real_T t464;
  real_T t466;
  real_T t467_tmp;
  real_T t467_tmp_tmp;
  real_T t469;
  real_T t47;
  real_T t470_tmp;
  real_T t48;
  real_T t483;
  real_T t49;
  real_T t495;
  real_T t5;
  real_T t520;
  real_T t557_tmp;
  real_T t56;
  real_T t563_tmp;
  real_T t565_tmp;
  real_T t567_tmp;
  real_T t57;
  real_T t571_tmp;
  real_T t573_tmp;
  real_T t577_tmp;
  real_T t577_tmp_tmp;
  real_T t591_tmp;
  real_T t592_tmp;
  real_T t592_tmp_tmp;
  real_T t593_tmp;
  real_T t594_tmp;
  real_T t597;
  real_T t6;
  real_T t60;
  real_T t603;
  real_T t603_tmp;
  real_T t604_tmp;
  real_T t605_tmp;
  real_T t606_tmp;
  real_T t608_tmp;
  real_T t61;
  real_T t615_tmp;
  real_T t617;
  real_T t618;
  real_T t619;
  real_T t62;
  real_T t620;
  real_T t621;
  real_T t622;
  real_T t623;
  real_T t624;
  real_T t625;
  real_T t626;
  real_T t627;
  real_T t628;
  real_T t629;
  real_T t63;
  real_T t630;
  real_T t631;
  real_T t632;
  real_T t633;
  real_T t633_tmp;
  real_T t634;
  real_T t634_tmp_tmp;
  real_T t635;
  real_T t636;
  real_T t637;
  real_T t639;
  real_T t63_tmp;
  real_T t64;
  real_T t640;
  real_T t641;
  real_T t642;
  real_T t643;
  real_T t644;
  real_T t645;
  real_T t646;
  real_T t647;
  real_T t648;
  real_T t65;
  real_T t655;
  real_T t656;
  real_T t65_tmp_tmp;
  real_T t66;
  real_T t66_tmp_tmp;
  real_T t68;
  real_T t7;
  real_T t71;
  real_T t714_tmp;
  real_T t715_tmp;
  real_T t72;
  real_T t721;
  real_T t722;
  real_T t723;
  real_T t724;
  real_T t761_tmp;
  real_T t761_tmp_tmp;
  real_T t769_tmp_tmp;
  real_T t77;
  real_T t78;
  real_T t780;
  real_T t781;
  real_T t81;
  real_T t81_tmp;
  real_T t82;
  real_T t827;
  real_T t828;
  real_T t829;
  real_T t82_tmp;
  real_T t83;
  real_T t830;
  real_T t831;
  real_T t838;
  real_T t839;
  real_T t83_tmp;
  real_T t84;
  real_T t840;
  real_T t841;
  real_T t84_tmp;
  real_T t85;
  real_T t852;
  real_T t852_tmp;
  real_T t853_tmp;
  real_T t855;
  real_T t85_tmp;
  real_T t86;
  real_T t865;
  real_T t86_tmp;
  real_T t87;
  real_T t870;
  real_T t873;
  real_T t876;
  real_T t877;
  real_T t87_tmp;
  real_T t88;
  real_T t88_tmp;
  real_T t9;
  real_T t93;
  real_T t93_tmp;
  real_T t94;
  real_T t94_tmp;
  real_T t95;
  real_T t95_tmp;
  real_T t96;
  real_T t96_tmp;
  real_T t99;
  real_T t99_tmp;
  st.prev = sp;
  st.tls = sp->tls;

  /* MASSF2 */
  /*     [OUT1,OUT2,OUT3,OUT4] = MASSF2(IN1,IN2,S,DS,T_SYM) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
  /*     27-Feb-2021 16:28:01 */
  t2 = in1[16] * in1[16];
  t3 = in1[4] * in1[4];
  t4 = muDoubleScalarPower(in1[4], 3.0);
  t6 = muDoubleScalarPower(in1[4], 5.0);
  t7 = in2[0] * in2[0];
  t9 = in2[1] * in2[1];
  t11 = in1[17] * in1[17];
  t12_tmp = in1[4] * in2[2] * 2.0;
  t5 = t3 * t3;
  t19 = (t12_tmp + 1.0) * (t12_tmp + 1.0);
  t25 = in1[4] * in2[3] / 2.0 + in2[4] * t3 / 2.0;
  t26 = muDoubleScalarCos(t25);
  t27 = muDoubleScalarSin(t25);
  t31 = (t19 + t3 * t7 * 4.0) + t3 * t9 * 4.0;
  t28 = t27 * t27;
  t29 = t26 * t26;
  t25 = in1[15] * t2 / 4.0 + in1[15] * (t2 + t11 * 3.0) / 12.0;
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
  out1[21] = t25;
  out1[22] = 0.0;
  out1[23] = 0.0;
  out1[24] = 0.0;
  out1[25] = 0.0;
  out1[26] = 0.0;
  out1[27] = 0.0;
  out1[28] = t25;
  out1[29] = 0.0;
  out1[30] = 0.0;
  out1[31] = 0.0;
  out1[32] = 0.0;
  out1[33] = 0.0;
  out1[34] = 0.0;
  out1[35] = in1[15] * t11 / 2.0;
  t32 = 1.0 / (t31 * t31);
  t33 = 1.0 / muDoubleScalarPower(t31, 3.0);
  st.site = &ed_emlrtRSI;
  if (t31 < 0.0) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  t34 = 1.0 / muDoubleScalarSqrt(t31);
  t35 = muDoubleScalarPower(t34, 3.0);
  t36 = muDoubleScalarPower(t34, 5.0);
  t37 = muDoubleScalarPower(t34, 7.0);
  t2 = in1[4] * t34 * 2.0;
  t39_tmp = in2[0] * t4;
  t39 = t39_tmp * t35 * 8.0;
  t42_tmp = (t12_tmp + 1.0) * t34 + 1.0;
  t870 = in1[16] * t3;
  t25 = t870 * (t12_tmp + 1.0);
  t56 = t25 * t29 * t35;
  t57 = t25 * t28 * t35;
  st.site = &id_emlrtRSI;
  if (t42_tmp < 0.0) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  t46 = muDoubleScalarSqrt(t42_tmp);
  t47 = 1.0 / t46;
  t60 = t2 + -(in1[4] * t19 * t35 * 2.0);
  t62 = t39 + -(t39_tmp * t19 * t36 * 24.0);
  t63_tmp = in2[1] * t4;
  t63 = t63_tmp * t35 * 8.0 + -(t63_tmp * t19 * t36 * 24.0);
  t64 = t3 * (t12_tmp + 1.0) * t35 * 12.0 + -(t3 * muDoubleScalarPower(t12_tmp +
    1.0, 3.0) * t36 * 12.0);
  t48 = muDoubleScalarPower(t47, 3.0);
  t49 = muDoubleScalarPower(t47, 5.0);
  t61 = t60 * t60;
  t65_tmp_tmp = in1[4] * 1.4142135623730951 * t26;
  t655 = t65_tmp_tmp * t34;
  t65 = t655 * t47;
  t66_tmp_tmp = in1[4] * 1.4142135623730951 * t27;
  t656 = t66_tmp_tmp * t34;
  t66 = t656 * t47;
  t71 = 1.4142135623730951 * t26 * t2 * t47;
  t72 = 1.4142135623730951 * t27 * t2 * t47;
  t81_tmp = in2[0] * t3 * 1.4142135623730951;
  b_t81_tmp = t81_tmp * t26 * t34;
  t81 = b_t81_tmp * t47;
  t82_tmp = in2[1] * t3 * 1.4142135623730951;
  b_t82_tmp = t82_tmp * t26 * t34;
  t82 = b_t82_tmp * t47;
  t877 = t39_tmp * 1.4142135623730951;
  t25 = t877 * t26;
  t83_tmp = t25 * t34;
  t83 = t83_tmp * t47;
  t876 = t63_tmp * 1.4142135623730951;
  t2 = t876 * t26;
  t84_tmp = t2 * t34;
  t84 = t84_tmp * t47;
  t85_tmp = t81_tmp * t27 * t34;
  t85 = t85_tmp * t47;
  t86_tmp = t82_tmp * t27 * t34;
  t86 = t86_tmp * t47;
  t11 = t877 * t27;
  t87_tmp = t11 * t34;
  t87 = t87_tmp * t47;
  t31 = t876 * t27;
  t88_tmp = t31 * t34;
  t88 = t88_tmp * t47;
  t93_tmp = t25 * t35 * t47;
  t93 = t93_tmp * 4.0;
  t94_tmp = t2 * t35 * t47;
  t94 = t94_tmp * 4.0;
  t95_tmp = t11 * t35 * t47;
  t95 = t95_tmp * 4.0;
  t96_tmp = t31 * t35 * t47;
  t96 = t96_tmp * 4.0;
  t99_tmp = in2[0] * in2[1];
  b_t99_tmp = t99_tmp * t5 * 1.4142135623730951;
  c_t99_tmp = b_t99_tmp * t26;
  t99 = c_t99_tmp * t35 * t47 * 2.0;
  t101_tmp = t99_tmp * t6 * 1.4142135623730951;
  t101 = t101_tmp * t26 * t35 * t47 * 2.0;
  t102_tmp = b_t99_tmp * t27;
  t102 = t102_tmp * t35 * t47 * 2.0;
  t104 = t101_tmp * t27 * t35 * t47 * 2.0;
  t105_tmp = t3 * 1.4142135623730951 * t26;
  t105 = t105_tmp * t34 * t47 / 2.0;
  t873 = t4 * 1.4142135623730951 * t26;
  t106 = t873 * t34 * t47 / 2.0;
  t107_tmp = t3 * 1.4142135623730951 * t27;
  t107 = t107_tmp * t34 * t47 / 2.0;
  t625 = t4 * 1.4142135623730951 * t27;
  t108 = t625 * t34 * t47 / 2.0;
  t202_tmp_tmp = in2[0] * t6;
  t839 = t202_tmp_tmp * t9 * 1.4142135623730951;
  t202 = t839 * t26 * t36 * t47 * 48.0;
  t464 = in2[1] * t6;
  t840 = t464 * t7 * 1.4142135623730951;
  t203 = t840 * t26 * t36 * t47 * 48.0;
  t204 = t839 * t27 * t36 * t47 * 48.0;
  t205 = t840 * t27 * t36 * t47 * 48.0;
  t25 = t877 * (t12_tmp + 1.0);
  t632 = t25 * t26;
  t210 = t632 * t35 * t47;
  t2 = t876 * (t12_tmp + 1.0);
  t631 = t2 * t26;
  t211 = t631 * t35 * t47;
  t212_tmp_tmp_tmp = in2[0] * t5;
  t212_tmp_tmp = t212_tmp_tmp_tmp * 1.4142135623730951;
  t11 = t212_tmp_tmp * (t12_tmp + 1.0);
  t212 = t11 * t26 * t35 * t47;
  t214_tmp_tmp_tmp = in2[1] * t5;
  t214_tmp_tmp = t214_tmp_tmp_tmp * 1.4142135623730951;
  t31 = t214_tmp_tmp * (t12_tmp + 1.0);
  t214 = t31 * t26 * t35 * t47;
  t216_tmp = t25 * t27;
  t216 = t216_tmp * t35 * t47;
  t217_tmp = t2 * t27;
  t217 = t217_tmp * t35 * t47;
  t218 = t11 * t27 * t35 * t47;
  t220 = t31 * t27 * t35 * t47;
  t25 = t3 * 1.4142135623730951 * (t12_tmp + 1.0);
  t841 = t25 * t26 * t35 * t47;
  t236 = t841 * 2.0;
  t838 = t25 * t27 * t35 * t47;
  t237 = t838 * 2.0;
  t266_tmp = t81_tmp * (t12_tmp + 1.0);
  b_t266_tmp = t266_tmp * t27 * t35;
  t865 = b_t266_tmp * t47;
  t266 = t865 * -2.0;
  t25 = b_t99_tmp * (t12_tmp + 1.0);
  t11 = t25 * t26;
  t290_tmp = t11 * t36 * t47;
  t290 = t290_tmp * 24.0;
  t31 = t25 * t27;
  t291_tmp = t31 * t36 * t47;
  t291 = t291_tmp * 24.0;
  t855 = t5 * t7 * 1.4142135623730951;
  t25 = t855 * (t12_tmp + 1.0);
  t304 = t25 * t26 * t36 * t47 * 24.0;
  t305_tmp_tmp = t5 * t9 * 1.4142135623730951;
  t2 = t305_tmp_tmp * (t12_tmp + 1.0);
  t305 = t2 * t26 * t36 * t47 * 24.0;
  t308 = t25 * t27 * t36 * t47 * 24.0;
  t309 = t2 * t27 * t36 * t47 * 24.0;
  t68 = in2[1] * t65;
  t77 = c_t99_tmp * t32 * t48 * 4.0;
  t78 = t102_tmp * t32 * t48 * 4.0;
  t194 = t632 * t32 * t48 * 2.0;
  t195 = t631 * t32 * t48 * 2.0;
  t198 = t216_tmp * t32 * t48 * 2.0;
  t199 = t217_tmp * t32 * t48 * 2.0;
  t206 = t11 * t32 * t48;
  t25 = t101_tmp * (t12_tmp + 1.0);
  t207 = t25 * t26 * t32 * t48;
  t208 = t31 * t32 * t48;
  t209 = t25 * t27 * t32 * t48;
  t11 = t99_tmp * t4 * 1.4142135623730951;
  t25 = t11 * (t12_tmp + 1.0);
  t31 = t25 * t26 * t32;
  t233 = t31 * t48 * 4.0;
  t81_tmp = t25 * t27 * t32;
  t235 = t81_tmp * t48 * 4.0;
  t238 = in2[0] * t236;
  t239 = in2[1] * t236;
  t242 = in2[0] * t237;
  t243 = in2[1] * t237;
  t25 = b_t99_tmp * t19;
  t264_tmp = t25 * t26 * t33 * t48;
  t264 = t264_tmp * 4.0;
  t265_tmp = t25 * t27 * t33 * t48;
  t265 = t265_tmp * 4.0;
  t279 = t264_tmp * 16.0;
  t25 = t839 * (t12_tmp + 1.0);
  t280 = t25 * t26 * t33 * t48 * 40.0;
  t2 = t840 * (t12_tmp + 1.0);
  t281 = t2 * t26 * t33 * t48 * 40.0;
  t283 = t265_tmp * 16.0;
  t284 = t25 * t27 * t33 * t48 * 40.0;
  t285 = t2 * t27 * t33 * t48 * 40.0;
  t25 = t839 * t19;
  t323 = t25 * t26 * t37 * t49 * 12.0;
  t2 = t840 * t19;
  t324 = t2 * t26 * t37 * t49 * 12.0;
  t325 = t25 * t27 * t37 * t49 * 12.0;
  t326 = t2 * t27 * t37 * t49 * 12.0;
  t25 = in1[4] * in2[0] * 1.4142135623730951;
  t101_tmp = t25 * t26 * t34;
  t330_tmp = t101_tmp * t48;
  t330 = t330_tmp * t60;
  t2 = in1[4] * in2[1] * 1.4142135623730951;
  t331_tmp = t2 * t26 * t34;
  b_t331_tmp = t331_tmp * t48;
  t331 = b_t331_tmp * t60;
  t332_tmp = t25 * t27 * t34;
  b_t332_tmp = t332_tmp * t48;
  t332 = b_t332_tmp * t60;
  t217_tmp = t2 * t27 * t34;
  t333_tmp = t217_tmp * t48;
  t333 = t333_tmp * t60;
  t334 = t655 * t48 * t60 / 2.0;
  t335 = t656 * t48 * t60 / 2.0;
  t631 = t11 * t26 * t35;
  t343 = t631 * t48 * t60 * 2.0;
  t102_tmp = t11 * t27 * t35;
  t344 = t102_tmp * t48 * t60 * 2.0;
  t25 = t4 * t7 * 1.4142135623730951;
  t632 = t25 * t26 * t35;
  t358 = t632 * t48 * t60 * 2.0;
  t2 = t4 * t9 * 1.4142135623730951;
  t11 = t2 * t26 * t35;
  t359 = t11 * t48 * t60 * 2.0;
  c_t99_tmp = t25 * t27 * t35;
  t360 = c_t99_tmp * t48 * t60 * 2.0;
  t216_tmp = t2 * t27 * t35;
  t361 = t216_tmp * t48 * t60 * 2.0;
  t371 = t31 * t49 * t60 * 3.0;
  t372 = t81_tmp * t49 * t60 * 3.0;
  t25 *= t12_tmp + 1.0;
  t373 = t25 * t26 * t32 * t49 * t60 * 3.0;
  t2 *= t12_tmp + 1.0;
  t374 = t2 * t26 * t32 * t49 * t60 * 3.0;
  t375 = t25 * t27 * t32 * t49 * t60 * 3.0;
  t376 = t2 * t27 * t32 * t49 * t60 * 3.0;
  t409 = t81 + t86;
  t410 = t83 + t88;
  t416 = t212_tmp_tmp * t26 * t34 * t47 / 4.0 + t214_tmp_tmp * t27 * t34 * t47 /
    4.0;
  t2 = t464 * 1.4142135623730951;
  t25 = t202_tmp_tmp * 1.4142135623730951;
  t417 = t25 * t26 * t34 * t47 / 4.0 + t2 * t27 * t34 * t47 / 4.0;
  t405 = in2[0] * t65 + in2[1] * t66;
  t407 = in2[0] * t71 + in2[1] * t72;
  t411 = t82 + -t85;
  t412 = t84 + -t87;
  t413 = t81 / 2.0 + t86 / 2.0;
  t414 = t83 / 2.0 + t88 / 2.0;
  t415 = t83 / 4.0 + t88 / 4.0;
  t421 = t214_tmp_tmp * t26 * t34 * t47 / 4.0 + -(t212_tmp_tmp * t27 * t34 * t47
    / 4.0);
  t422 = t2 * t26 * t34 * t47 / 4.0 + -(t25 * t27 * t34 * t47 / 4.0);
  t429_tmp = 1.4142135623730951 * t26 * t46;
  t429 = t429_tmp * t416;
  t432_tmp = 1.4142135623730951 * t27 * t46;
  t432 = t432_tmp * t416;
  t433_tmp = t68 * 2.0 - in2[0] * t72;
  b_t433_tmp = t625 * t46;
  t463 = t838 * t433_tmp;
  t466 = t841 * t433_tmp;
  t483 = t265_tmp * t433_tmp * 2.0;
  t520 = t291_tmp * t433_tmp * 12.0;
  t565_tmp = t65_tmp_tmp * t47 * t60;
  t567_tmp = t66_tmp_tmp * t47 * t60;
  t571_tmp = t105_tmp * t47 * t60;
  t573_tmp = t107_tmp * t47 * t60;
  t603_tmp = t266_tmp * t26 * t35 * t48 * t60;
  t603 = t603_tmp * t433_tmp / 2.0;
  t25 = t82_tmp * (t12_tmp + 1.0);
  t604_tmp = t25 * t26 * t35 * t48 * t60;
  t605_tmp = b_t266_tmp * t48 * t60;
  t606_tmp = t25 * t27 * t35 * t48 * t60;
  b_t99_tmp = t11 * t47;
  t839 = t4 * t9 * 1.4142135623730951 * (t12_tmp + 1.0) * t26 * t32 * t48;
  t618 = (((t65 + in2[1] * t95) + -(b_t99_tmp * 4.0)) + t839 * 2.0) + in2[0] *
    in2[1] * t4 * 1.4142135623730951 * (t12_tmp + 1.0) * t27 * t32 * t48 * -2.0;
  t840 = c_t99_tmp * t47;
  t655 = t4 * t7 * 1.4142135623730951 * (t12_tmp + 1.0) * t27 * t32 * t48;
  t619 = (((t66 + in2[1] * t93) + -(t840 * 4.0)) + t655 * 2.0) + in2[0] * in2[1]
    * t4 * 1.4142135623730951 * (t12_tmp + 1.0) * t26 * t32 * t48 * -2.0;
  t99_tmp = t102_tmp * t47;
  t81_tmp = t632 * t47;
  c_t99_tmp = t4 * t7 * 1.4142135623730951 * (t12_tmp + 1.0) * t26 * t32 * t48;
  t621 = (((t71 + t99_tmp * -8.0) + -(t81_tmp * 8.0)) + t235) + c_t99_tmp * 4.0;
  t102_tmp = t631 * t47;
  t11 = t216_tmp * t47;
  t31 = t4 * t9 * 1.4142135623730951 * (t12_tmp + 1.0) * t27 * t32 * t48;
  t624 = (((t72 + t102_tmp * -8.0) + -(t11 * 8.0)) + t233) + t31 * 4.0;
  t81 = t855 * t26;
  t625 = (((t105 + -t102) + -(t81 * t35 * t47 * 2.0)) + t208) + t5 * t7 *
    1.4142135623730951 * (t12_tmp + 1.0) * t26 * t32 * t48;
  t216_tmp = t6 * t7 * 1.4142135623730951;
  t656 = t216_tmp * (t12_tmp + 1.0);
  t626 = (((t106 + -t104) + -(t216_tmp * t26 * t35 * t47 * 2.0)) + t209) + t656 *
    t26 * t32 * t48;
  t88 = t305_tmp_tmp * t27;
  t627 = (((t107 + -t99) + -(t88 * t35 * t47 * 2.0)) + t206) + t5 * t9 *
    1.4142135623730951 * (t12_tmp + 1.0) * t27 * t32 * t48;
  t632 = t6 * t9 * 1.4142135623730951;
  t631 = t632 * (t12_tmp + 1.0);
  t628 = (((t108 + -t101) + -(t632 * t27 * t35 * t47 * 2.0)) + t207) + t631 *
    t27 * t32 * t48;
  t633_tmp = in2[0] * t3 * 1.4142135623730951 * (t12_tmp + 1.0) * t26 * t35 *
    t47;
  b_t633_tmp = in2[1] * t3 * 1.4142135623730951 * (t12_tmp + 1.0) * t27 * t35 *
    t47;
  t633 = ((t633_tmp * 4.0 + b_t633_tmp * 4.0) + t330) + t333;
  t636 = ((t210 + t217) + b_t81_tmp * t48 * t60 / 4.0) + t86_tmp * t48 * t60 /
    4.0;
  t637 = ((t212 + t220) + t83_tmp * t48 * t60 / 4.0) + t88_tmp * t48 * t60 / 4.0;
  t202_tmp_tmp = t877 * t19;
  t212_tmp_tmp = t876 * t19;
  t852_tmp = t202_tmp_tmp * t26 * t36 * t47;
  b_t852_tmp = t212_tmp_tmp * t27 * t36 * t47;
  t852 = ((((((((-t93 + -t96) + t852_tmp * 12.0) + b_t852_tmp * 12.0) + t101_tmp
              * t49 * t61 * 0.75) + t217_tmp * t49 * t61 * 0.75) + in2[0] * t3 *
            1.4142135623730951 * (t12_tmp + 1.0) * t26 * t35 * t48 * t60 * 2.0)
           + in2[1] * t3 * 1.4142135623730951 * (t12_tmp + 1.0) * t27 * t35 *
           t48 * t60 * 2.0) + t330_tmp * t64 / 2.0) + t333_tmp * t64 / 2.0;
  t406 = t68 + -(in2[0] * t66);
  t418 = t82 / 2.0 + -(t85 / 2.0);
  t419 = t84 / 2.0 + -(t87 / 2.0);
  t420 = t84 / 4.0 + -(t87 / 4.0);
  t425_tmp = t873 * t46;
  t435 = t429_tmp * t421;
  t437 = t432_tmp * t421;
  t34 = t870 * 1.4142135623730951;
  t25 = t34 * (t12_tmp + 1.0);
  t101_tmp = t25 * t26 * t35 * t47;
  t459 = t101_tmp * t405;
  t214_tmp_tmp = t25 * t27 * t35 * t47;
  t460 = t214_tmp_tmp * t405;
  t461 = t838 * t407;
  t462 = t841 * t407;
  t467_tmp_tmp = in1[16] * in2[0];
  b_t81_tmp = t467_tmp_tmp * in2[1] * t5;
  t25 = b_t81_tmp * 1.4142135623730951;
  t266_tmp = t25 * t19;
  t467_tmp = t266_tmp * t26 * t33 * t48;
  t469 = t264_tmp * t407 * 2.0;
  b_t266_tmp = t25 * (t12_tmp + 1.0);
  t470_tmp = b_t266_tmp * t26 * t36 * t47;
  t495 = t290_tmp * t407 * 12.0;
  t83 = in1[16] * in1[4] * 1.4142135623730951;
  t86 = t83 * t26;
  t557_tmp = t86 * t47 * t60;
  t291_tmp = t34 * t26;
  t563_tmp = t291_tmp * t47 * t60;
  t577_tmp_tmp = in1[16] * 1.4142135623730951 * t26;
  b_t577_tmp_tmp = t577_tmp_tmp * t47;
  t577_tmp = b_t577_tmp_tmp * t60;
  t25 = t467_tmp_tmp * t3 * 1.4142135623730951 * (t12_tmp + 1.0);
  t68 = t25 * t26 * t35;
  t591_tmp = t68 * t48 * t60;
  t592_tmp_tmp = in1[16] * in2[1];
  t2 = t592_tmp_tmp * t3 * 1.4142135623730951 * (t12_tmp + 1.0);
  t82_tmp = t2 * t26 * t35;
  t592_tmp = t82_tmp * t48 * t60;
  t25 = t25 * t27 * t35;
  t593_tmp = t25 * t48 * t60;
  t594_tmp = t2 * t27 * t35;
  t597 = t605_tmp * t407 / 2.0;
  t608_tmp = in1[16] * t405;
  t615_tmp = in1[16] * t413;
  t617 = (((t65 + t99_tmp * -4.0) + -(t81_tmp * 4.0)) + in2[1] * t198) +
    c_t99_tmp * 2.0;
  t620 = (((t66 + t102_tmp * -4.0) + -(t11 * 4.0)) + in2[1] * t194) + t31 * 2.0;
  t622 = (((t71 + in2[1] * 1.4142135623730951 * t27 * t39 * t47) + -(b_t99_tmp *
            8.0)) + t839 * 4.0) + -t235;
  t623 = (((t72 + in2[1] * 1.4142135623730951 * t26 * t39 * t47) + -(t840 * 8.0))
          + t655 * 4.0) + -t233;
  t217_tmp = t305_tmp_tmp * t26;
  t629 = (((t102 + t105) + -(t217_tmp * t35 * t47 * 2.0)) + t5 * t9 *
          1.4142135623730951 * (t12_tmp + 1.0) * t26 * t32 * t48) + -t208;
  t630 = (((t104 + t106) + -(t632 * t26 * t35 * t47 * 2.0)) + t631 * t26 * t32 *
          t48) + -t209;
  t102_tmp = t855 * t27;
  t631 = (((t99 + t107) + -(t102_tmp * t35 * t47 * 2.0)) + t5 * t7 *
          1.4142135623730951 * (t12_tmp + 1.0) * t27 * t32 * t48) + -t206;
  t632 = (((t101 + t108) + -(t216_tmp * t27 * t35 * t47 * 2.0)) + t656 * t27 *
          t32 * t48) + -t207;
  t634_tmp_tmp = in2[1] * t3 * 1.4142135623730951 * (t12_tmp + 1.0) * t26 * t35 *
    t47;
  t634 = ((t634_tmp_tmp * 4.0 + -(t865 * 4.0)) + t331) + -t332;
  t635 = ((t238 + t243) + t330 / 2.0) + t333 / 2.0;
  t639 = ((t211 + -t216) + b_t82_tmp * t48 * t60 / 4.0) + -(t85_tmp * t48 * t60 /
    4.0);
  t640 = ((t214 + -t218) + t84_tmp * t48 * t60 / 4.0) + -(t87_tmp * t48 * t60 /
    4.0);
  t641 = t429_tmp * t625;
  t642 = t429_tmp * t626;
  t643 = t432_tmp * t625;
  t644 = t429_tmp * t627;
  t645 = t432_tmp * t626;
  t646 = t429_tmp * t628;
  t647 = t432_tmp * t627;
  t648 = t432_tmp * t628;
  t714_tmp = t25 * t47;
  t715_tmp = t594_tmp * t47;
  t721 = t429_tmp * t636;
  t722 = t429_tmp * t637;
  t723 = t432_tmp * t636;
  t724 = t432_tmp * t637;
  t761_tmp = in1[16] * 1.4142135623730951 * t27;
  t761_tmp_tmp = t761_tmp * t47;
  b_t761_tmp = t761_tmp_tmp * t60;
  t769_tmp_tmp = ((t242 - t331 / 2.0) + t332 / 2.0) - t634_tmp_tmp * 2.0;
  t780 = t407 * t625;
  t781 = t407 * t626;
  t25 = t6 * muDoubleScalarPower(in2[0], 3.0) * 1.4142135623730951;
  t2 = t25 * (t12_tmp + 1.0);
  t11 = t25 * t19;
  t827 = ((((((((-t96 + -(t93_tmp * 12.0)) + t25 * t26 * t36 * t47 * 48.0) +
               in2[0] * t4 * 1.4142135623730951 * (t12_tmp + 1.0) * t26 * t32 *
               t48 * 6.0) + t199) + t205) + -(t2 * t26 * t33 * t48 * 40.0)) +
           -t285) + t11 * t26 * t37 * t49 * 12.0) + t326;
  t31 = t6 * muDoubleScalarPower(in2[1], 3.0) * 1.4142135623730951;
  t81_tmp = t31 * (t12_tmp + 1.0);
  c_t99_tmp = t31 * t19;
  t828 = ((((((((-t93 + -(t96_tmp * 12.0)) + t31 * t27 * t36 * t47 * 48.0) +
               t194) + in2[1] * t4 * 1.4142135623730951 * (t12_tmp + 1.0) * t27 *
              t32 * t48 * 6.0) + t202) + -(t81_tmp * t27 * t33 * t48 * 40.0)) +
           -t280) + c_t99_tmp * t27 * t37 * t49 * 12.0) + t323;
  t829 = ((((((((t94 + -(t95_tmp * 12.0)) + t25 * t27 * t36 * t47 * 48.0) + in2
               [0] * t4 * 1.4142135623730951 * (t12_tmp + 1.0) * t27 * t32 * t48
               * 6.0) + -t195) + -t203) + t281) + -(t2 * t27 * t33 * t48 * 40.0))
          + t11 * t27 * t37 * t49 * 12.0) + -t324;
  t830 = ((((((((t95 + -(t94_tmp * 12.0)) + t31 * t26 * t36 * t47 * 48.0) + in2
               [1] * t4 * 1.4142135623730951 * (t12_tmp + 1.0) * t26 * t32 * t48
               * 6.0) + -t198) + -t204) + t284) + -(t81_tmp * t26 * t33 * t48 *
            40.0)) + c_t99_tmp * t26 * t37 * t49 * 12.0) + -t325;
  t831 = ((((((((-t94 + -t95) + t195) + t198) + t203) + t204) + -t281) + -t284)
          + t324) + t325;
  t93 = ((((((((t93 + -t96) + t199) + t205) + -t194) + -t202) + t280) + -t285) +
         t326) + -t323;
  t853_tmp = t202_tmp_tmp * t27 * t36 * t47;
  b_t853_tmp = t212_tmp_tmp * t26 * t36 * t47;
  t37 = ((((((((t94 + -t95) + t853_tmp * 12.0) + -(b_t853_tmp * 12.0)) +
             t332_tmp * t49 * t61 * 0.75) + -(t331_tmp * t49 * t61 * 0.75)) +
           in2[0] * t3 * 1.4142135623730951 * (t12_tmp + 1.0) * t27 * t35 * t48 *
           t60 * 2.0) + -(t604_tmp * 2.0)) + b_t332_tmp * t64 / 2.0) +
    -(b_t331_tmp * t64 / 2.0);
  t2 = t305_tmp_tmp * t19;
  t202 = t2 * t26 * t33 * t48;
  t6 = ((((((((((t78 + -(t217_tmp * t32 * t48 * 4.0)) + t236) + t291) + t202 *
              16.0) + -t283) + -t305) + t334) + t344) + -t359) + t374) + -t372;
  t25 = t855 * t19;
  t204 = t25 * t27 * t33 * t48;
  t855 = ((((((((((t77 + -(t102_tmp * t32 * t48 * 4.0)) + t237) + t290) + t204 *
                16.0) + -t279) + -t308) + t335) + t343) + -t360) + t375) + -t371;
  t305_tmp_tmp = t25 * t26 * t33 * t48;
  t205 = ((((((((((t78 + t81 * t32 * t48 * 4.0) + -t236) + t291) + -t283) + t304)
              + -(t305_tmp_tmp * 16.0)) + -t334) + t344) + t358) + -t372) +
    -t373;
  t203 = t2 * t27 * t33 * t48;
  t96 = ((((((((((t77 + t88 * t32 * t48 * 4.0) + -t237) + t290) + -t279) + t309)
             + -(t203 * 16.0)) + -t335) + t343) + t361) + -t371) + -t376;
  t279 = ((((((((((t236 + t202 * 4.0) + -t265) + t291) + -t305) + t334) + t344)
             + -t359) + t374) + -t372) + b_t332_tmp * t63 / 2.0) + -(b_t331_tmp *
    t63 / 2.0);
  t283 = ((((((((((t237 + t204 * 4.0) + -t264) + t290) + -t308) + t335) + t343)
             + -t360) + t375) + -t371) + b_t331_tmp * t62 / 2.0) + -(b_t332_tmp *
    t62 / 2.0);
  t334 = ((((((((((t236 + t265) + t305_tmp_tmp * 4.0) + -t291) + -t304) + t334)
              + -t344) + -t358) + t372) + t373) + -(t330_tmp * t62 / 2.0)) +
    -(t333_tmp * t62 / 2.0);
  t284 = ((((((((((t237 + t264) + t203 * 4.0) + -t290) + -t309) + t335) + -t343)
             + -t361) + t371) + t376) + -(t330_tmp * t63 / 2.0)) + -(t333_tmp *
    t63 / 2.0);
  t464 = t101_tmp * t406;
  t326 = t214_tmp_tmp * t406;
  t361 = t761_tmp * t46;
  t335 = t577_tmp_tmp * t46;
  out2[0] = (((t3 - in2[0] * t459) + in2[0] * t326) + t335 * t617 / 2.0) + t361 *
    t619 / 2.0;
  out2[1] = ((-in2[0] * t460 - in2[0] * t464) + t361 * t617 / 2.0) - t335 * t619
    / 2.0;
  t343 = in1[16] * t406;
  out2[2] = ((-in2[0] * t56 - in2[0] * t57) - t608_tmp * t617) + t343 * t619;
  out2[3] = ((in2[0] * t461 - in2[0] * t466) + t432_tmp * t617) + t429_tmp *
    t619;
  out2[4] = ((in2[0] * t462 + in2[0] * t463) + t429_tmp * t617) - t432_tmp *
    t619;
  out2[5] = t407 * t619 + t617 * t433_tmp;
  out2[6] = ((-in2[1] * t459 + in2[1] * t326) - t361 * t618 / 2.0) + t335 * t620
    / 2.0;
  out2[7] = (((t3 - in2[1] * t460) - in2[1] * t464) + t335 * t618 / 2.0) + t361 *
    t620 / 2.0;
  out2[8] = ((-in2[1] * t56 - in2[1] * t57) - t343 * t618) - t608_tmp * t620;
  out2[9] = ((in2[1] * t461 - in2[1] * t466) - t429_tmp * t618) + t432_tmp *
    t620;
  out2[10] = ((in2[1] * t462 + in2[1] * t463) + t432_tmp * t618) + t429_tmp *
    t620;
  out2[11] = -t407 * t618 + t620 * t433_tmp;
  out2[12] = ((t335 * t635 * -0.5 - t361 * t769_tmp_tmp / 2.0) + t577_tmp * t405
              / 4.0) - b_t761_tmp * t406 / 4.0;
  out2[13] = ((t361 * t635 * -0.5 + t335 * t769_tmp_tmp / 2.0) + t577_tmp * t406
              / 4.0) + b_t761_tmp * t405 / 4.0;
  t198 = in1[16] * t28;
  t199 = in1[16] * t29;
  out2[14] = (((t3 + t198 * t60 / 4.0) + t199 * t60 / 4.0) + t608_tmp * t635) -
    t343 * t769_tmp_tmp;
  b_t332_tmp = 1.4142135623730951 * t27 * t47;
  t195 = b_t332_tmp * t60;
  b_t331_tmp = 1.4142135623730951 * t26 * t47;
  t333_tmp = b_t331_tmp * t60;
  t194 = -1.4142135623730951 * t27 * t46;
  out2[15] = ((t194 * t635 - t429_tmp * t769_tmp_tmp) + t333_tmp * t433_tmp /
              4.0) - t195 * t407 / 4.0;
  out2[16] = ((-1.4142135623730951 * t26 * t46 * t635 + t432_tmp * t769_tmp_tmp)
              - t195 * t433_tmp / 4.0) - t333_tmp * t407 / 4.0;
  out2[17] = -t407 * t769_tmp_tmp - t635 * t433_tmp;
  t371 = t86 * t46;
  t2 = t83 * t27;
  t358 = t2 * t46;
  out2[18] = ((t361 * t413 / 2.0 + t335 * t418 / 2.0) - t371 * t406 / 4.0) -
    t358 * t405 / 4.0;
  out2[19] = ((t335 * t413 * -0.5 + t361 * t418 / 2.0) + t371 * t405 / 4.0) -
    t358 * t406 / 4.0;
  out2[20] = t343 * t413 - t608_tmp * t418;
  t344 = t65_tmp_tmp * t46;
  t359 = t66_tmp_tmp * t46;
  out2[21] = ((t429_tmp * t413 + t432_tmp * t418) - t359 * t433_tmp / 4.0) -
    t344 * t407 / 4.0;
  out2[22] = ((t194 * t413 + t429_tmp * t418) - t344 * t433_tmp / 4.0) + t359 *
    t407 / 4.0;
  t372 = in1[4] * t28;
  t360 = in1[4] * t29;
  out2[23] = ((t407 * t413 + t418 * t433_tmp) + t372 * t42_tmp / 2.0) + t360 *
    t42_tmp / 2.0;
  t373 = t291_tmp * t46;
  t25 = t34 * t27;
  t281 = t25 * t46;
  t374 = t373 * t406;
  t375 = t281 * t405;
  out2[24] = ((t361 * t414 / 2.0 + t335 * t419 / 2.0) - t374 / 4.0) - t375 / 4.0;
  t280 = t373 * t405;
  t376 = t281 * t406;
  out2[25] = ((t335 * t414 * -0.5 + t361 * t419 / 2.0) + t280 / 4.0) - t376 /
    4.0;
  out2[26] = t343 * t414 - t608_tmp * t419;
  t285 = t105_tmp * t46;
  t84_tmp = t107_tmp * t46;
  t87_tmp = t84_tmp * t433_tmp;
  t324 = t285 * t407;
  out2[27] = ((t429_tmp * t414 + t432_tmp * t419) - t87_tmp / 4.0) - t324 / 4.0;
  t332_tmp = t285 * t433_tmp;
  t323 = t84_tmp * t407;
  out2[28] = ((t194 * t414 + t429_tmp * t419) - t332_tmp / 4.0) + t323 / 4.0;
  t194 = t3 * t28;
  t331_tmp = t3 * t29;
  out2[29] = ((t407 * t414 + t419 * t433_tmp) + t194 * t42_tmp / 2.0) + t331_tmp
    * t42_tmp / 2.0;
  b_t99_tmp = t266_tmp * t27 * t33 * t48;
  t99_tmp = b_t266_tmp * t27 * t36 * t47;
  t325 = t2 * t47 * t60;
  b_t82_tmp = t25 * t47 * t60;
  t85_tmp = in1[16] * t418;
  t206 = t429_tmp * t629;
  t207 = t429_tmp * t630;
  t82 = t429_tmp * t631;
  t332 = t432_tmp * t629;
  t85 = t429_tmp * t632;
  t331 = t432_tmp * t630;
  t655 = t432_tmp * t631;
  t656 = t432_tmp * t632;
  t87 = t82_tmp * t47;
  t101_tmp = t68 * t47;
  t106 = t429_tmp * t639;
  t71 = t429_tmp * t640;
  t72 = t432_tmp * t639;
  t99 = t432_tmp * t640;
  t107 = t631 * t433_tmp;
  t39 = t632 * t433_tmp;
  t216_tmp = in1[16] * t617;
  t101 = t216_tmp * t635;
  t838 = t429_tmp * t831;
  t839 = t432_tmp * t831;
  t840 = t429_tmp * t93;
  t841 = t432_tmp * t93;
  t25 = in1[16] * t4 * 1.4142135623730951;
  t2 = t25 * t27 * t46;
  t25 = t25 * t26 * t46;
  t108 = ((((((t25 * t405 / 8.0 + -(t2 * t406 / 8.0)) + in1[16] * t429 / 2.0) +
             -(in1[16] * t437 / 2.0)) + -(t371 * t414 / 4.0)) + t358 * t419 /
           4.0) + -(t373 * t413 / 4.0)) + t281 * t418 / 4.0;
  t104 = ((((((t2 * t405 / 8.0 + t25 * t406 / 8.0) + in1[16] * t432 / 2.0) +
             in1[16] * t435 / 2.0) + -(t358 * t414 / 4.0)) + -(t371 * t419 / 4.0))
          + -(t281 * t413 / 4.0)) + -(t373 * t418 / 4.0);
  t865 = ((t608_tmp * t631 + t343 * t625) + -(t615_tmp * t619)) + -(t85_tmp *
    t617);
  t66 = ((t608_tmp * t629 + -(t343 * t627)) + t85_tmp * t620) + -(t615_tmp *
    t618);
  t25 = in1[16] * t419;
  t2 = in1[16] * t414;
  t65 = ((t608_tmp * t632 + t343 * t626) + -(t2 * t619)) + -(t25 * t617);
  t102 = ((t608_tmp * t630 + -(t343 * t628)) + t25 * t620) + -(t2 * t618);
  t105 = ((t608_tmp * t639 + -(t343 * t636)) + t85_tmp * t635) + t615_tmp *
    t769_tmp_tmp;
  t870 = ((t608_tmp * t640 + -(t343 * t637)) + t25 * t635) + t2 * t769_tmp_tmp;
  t217_tmp = in1[16] * in2[0] * t3 * 1.4142135623730951 * (t12_tmp + 1.0) * t27 *
    t35 * t47;
  t31 = in1[16] * t216;
  t81_tmp = in1[16] * t210;
  t235 = ((((((t81_tmp * t405 / 2.0 + -(t31 * t406 / 2.0)) + t217_tmp * t418) +
             -(t101_tmp * t413)) + -(t371 * t617 / 4.0)) + -(t358 * t619 / 4.0))
          + in1[16] * t641 / 2.0) + in1[16] * t655 / 2.0;
  t2 = in1[16] * t211;
  t11 = in1[16] * t217;
  t333 = ((((((t11 * t405 / 2.0 + t2 * t406 / 2.0) + -(t715_tmp * t413)) + -(t87
              * t418)) + -(t371 * t618 / 4.0)) + -(t358 * t620 / 4.0)) + in1[16]
          * t647 / 2.0) + in1[16] * t206 / 2.0;
  t632 = in1[16] * t218;
  t631 = in1[16] * t212;
  t233 = ((((((t631 * t405 / 2.0 + -(t632 * t406 / 2.0)) + t217_tmp * t419) +
             -(t101_tmp * t414)) + in1[16] * t642 / 2.0) + -(t373 * t617 / 4.0))
          + -(t281 * t619 / 4.0)) + in1[16] * t656 / 2.0;
  c_t99_tmp = in1[16] * t214;
  t102_tmp = in1[16] * t220;
  t330 = ((((((t102_tmp * t405 / 2.0 + c_t99_tmp * t406 / 2.0) + -(t715_tmp *
    t414)) + -(t87 * t419)) + in1[16] * t648 / 2.0) + -(t373 * t618 / 4.0)) +
          -(t281 * t620 / 4.0)) + in1[16] * t207 / 2.0;
  t208 = ((((((t325 * t405 / 8.0 + t557_tmp * t406 / 8.0) + -(b_t761_tmp * t413 /
    4.0)) + -(t577_tmp * t418 / 4.0)) + -(t358 * t635 / 4.0)) + in1[16] * t723 /
           2.0) + t371 * t769_tmp_tmp / 4.0) + in1[16] * t106 / 2.0;
  t209 = ((((((b_t82_tmp * t405 / 8.0 + t563_tmp * t406 / 8.0) + -(b_t761_tmp *
    t414 / 4.0)) + -(t577_tmp * t419 / 4.0)) + in1[16] * t724 / 2.0) + -(t281 *
            t635 / 4.0)) + in1[16] * t71 / 2.0) + t373 * t769_tmp_tmp / 4.0;
  t25 = b_t81_tmp * (t12_tmp + 1.0);
  t625 = ((((t25 * t29 * t36 * 12.0 + t25 * t28 * t36 * 12.0) + in1[16] * t618 *
            t619) + -(t216_tmp * t620)) + -(t608_tmp * t831)) + t343 * t93;
  t25 = in1[16] * in2[1] * t3 * 1.4142135623730951 * (t12_tmp + 1.0) * t27 * t35
    * t47;
  t84 = ((((((t2 * t405 / 2.0 + -(t11 * t406 / 2.0)) + t25 * t418) + -(t87 *
             t413)) + t358 * t618 / 4.0) + -(t371 * t620 / 4.0)) + in1[16] *
         t644 / 2.0) + -(in1[16] * t332 / 2.0);
  t873 = ((((((t31 * t405 / 2.0 + t81_tmp * t406 / 2.0) + -(t714_tmp * t413)) +
             -(t101_tmp * t418)) + t371 * t619 / 4.0) + -(t358 * t617 / 4.0)) +
          in1[16] * t643 / 2.0) + -(in1[16] * t82 / 2.0);
  t876 = ((((((c_t99_tmp * t405 / 2.0 + -(t102_tmp * t406 / 2.0)) + t25 * t419)
             + -(t87 * t414)) + t281 * t618 / 4.0) + in1[16] * t646 / 2.0) +
          -(t373 * t620 / 4.0)) + -(in1[16] * t331 / 2.0);
  t877 = ((((((t632 * t405 / 2.0 + t631 * t406 / 2.0) + -(t714_tmp * t414)) +
             -(t101_tmp * t419)) + t373 * t619 / 4.0) + in1[16] * t645 / 2.0) +
          -(t281 * t617 / 4.0)) + -(in1[16] * t85 / 2.0);
  t2 = in1[16] * in2[0] * t3 * 1.4142135623730951 * (t12_tmp + 1.0) * t26 * t35 *
    t47;
  t25 = ((((((((b_t99_tmp * t405 * 2.0 + -(t99_tmp * t405 * 12.0)) + t467_tmp *
               t406 * 2.0) + -(t470_tmp * t406 * 12.0)) + t2 * t618) + t25 *
            t617) + t217_tmp * t620) + -(t87 * t619)) + in1[16] * t840 / 2.0) +
    -(in1[16] * t839 / 2.0);
  t266_tmp = in1[16] * t5;
  b_t266_tmp = t266_tmp * t7;
  t82_tmp = b_t266_tmp * 1.4142135623730951;
  t68 = t82_tmp * (t12_tmp + 1.0);
  t82_tmp *= t19;
  b_t81_tmp = t68 * t26 * t36 * t47;
  t68 = t68 * t27 * t36 * t47;
  t86_tmp = t82_tmp * t26 * t33 * t48;
  t82_tmp = t82_tmp * t27 * t33 * t48;
  t83_tmp = b_t577_tmp_tmp * t62;
  t88_tmp = t761_tmp_tmp * t62;
  t34 = ((((((((t467_tmp * t405 * 2.0 - t470_tmp * t405 * 12.0) - b_t99_tmp *
               t406 * 2.0) + t99_tmp * t406 * 12.0) + t87 * t617) + t101_tmp *
            t620) - t714_tmp * t618) + t715_tmp * t619) - in1[16] * t838 / 2.0)
    - in1[16] * t841 / 2.0;
  t291_tmp = (((t591_tmp * t405 / 2.0 - t593_tmp * t406 / 2.0) + t577_tmp * t617
               / 4.0) + b_t761_tmp * t619 / 4.0) + t101_tmp * t635;
  t88 = t217_tmp * t769_tmp_tmp;
  out3[0] = (((t873 * in2[8] + t877 * in2[9]) + in2[5] * (((((((((-t459 + t326)
    + in1[16] * t266 * t619) + t335 * t827 / 2.0) + t361 * t829 / 2.0) - t2 *
    t617 * 2.0) + b_t81_tmp * t405 * 12.0) - t86_tmp * t405 * 2.0) - t68 * t406 *
    12.0) + t82_tmp * t406 * 2.0)) - in2[6] * t34) + in2[7] * (((((t291_tmp -
    t335 * t334 / 2.0) - t361 * t283 / 2.0) - t83_tmp * t405 / 4.0) + t88_tmp *
    t406 / 4.0) + t88);
  t83 = t460 + t464;
  t86 = ((((t593_tmp * t405 / 2.0 + t591_tmp * t406 / 2.0) + b_t761_tmp * t617 /
           4.0) + -(t577_tmp * t619 / 4.0)) + t714_tmp * t635) + -in1[16] * in2
    [0] * t3 * 1.4142135623730951 * (t12_tmp + 1.0) * t26 * t35 * t47 *
    t769_tmp_tmp;
  out3[1] = (((-in2[5] * ((((((((t83 + in1[16] * t242 * t617) - t361 * t827 /
    2.0) + t335 * t829 / 2.0) - t2 * t619 * 2.0) - b_t81_tmp * t406 * 12.0) -
    t68 * t405 * 12.0) + t86_tmp * t406 * 2.0) + t82_tmp * t405 * 2.0) + in2[7] *
               ((((t86 + t335 * t283 / 2.0) - t361 * t334 / 2.0) - t83_tmp *
                 t406 / 4.0) - t88_tmp * t405 / 4.0)) - t235 * in2[8]) - t233 *
             in2[9]) - t25 * in2[6];
  t82_tmp = b_t266_tmp * (t12_tmp + 1.0);
  t68 = t56 + t57;
  b_t81_tmp = in1[16] * t619 * t769_tmp_tmp;
  out3[2] = (((t865 * in2[8] + t65 * in2[9]) + t625 * in2[6]) + in2[7] *
             (((((t101 - t198 * t62 / 4.0) - t199 * t62 / 4.0) + t608_tmp * t334)
               - t343 * t283) + b_t81_tmp)) - in2[5] * ((((((t68 + in1[16] *
    (t617 * t617)) + in1[16] * (t619 * t619)) + t608_tmp * t827) - t343 * t829)
    - t82_tmp * t28 * t36 * 12.0) - t82_tmp * t29 * t36 * 12.0);
  t82_tmp = b_t332_tmp * t62;
  t86_tmp = b_t331_tmp * t62;
  t83_tmp = in2[0] * t3 * 1.4142135623730951 * (t12_tmp + 1.0) * t27 * t35 * t47;
  t88_tmp = t5 * t7 * 1.4142135623730951 * (t12_tmp + 1.0) * t27 * t36 * t47;
  t81 = t5 * t7 * 1.4142135623730951 * (t12_tmp + 1.0) * t26 * t36 * t47;
  t214_tmp_tmp = t461 - t466;
  t212_tmp_tmp = ((((t265_tmp * t407 * 2.0 + -(t264_tmp * t433_tmp * 2.0)) +
                    t290_tmp * t433_tmp * 12.0) + -(in2[0] * in2[1] * t5 *
    1.4142135623730951 * (t12_tmp + 1.0) * t27 * t36 * t47 * t407 * 12.0)) +
                  t839) + t840;
  t202_tmp_tmp = ((t210 * t407 / 2.0 + t216 * t433_tmp / 2.0) + t641) + -t655;
  t464 = ((t212 * t407 / 2.0 + t218 * t433_tmp / 2.0) + t642) + -t656;
  out3[3] = (((in2[5] * ((((((((((t214_tmp_tmp + t266 * t617) + t432_tmp * t827)
    + t429_tmp * t829) + t81 * t433_tmp * 12.0) - t305_tmp_tmp * t433_tmp * 2.0)
    - t633_tmp * t619 * 2.0) + t83_tmp * t621) + t633_tmp * t623) - t88_tmp *
    t407 * 12.0) + t204 * t407 * 2.0) - in2[7] * (((((((((t597 - t603) + t266 *
    t635) + t429_tmp * t283) + t432_tmp * t334) + t86_tmp * t433_tmp / 4.0) -
    t82_tmp * t407 / 4.0) + t195 * t621 / 4.0) + t333_tmp * t623 / 4.0) -
    t633_tmp * t769_tmp_tmp * 2.0)) + in2[6] * ((((t212_tmp_tmp + t238 * t618) +
    t266 * t620) + b_t633_tmp * t621) + t634_tmp_tmp * t623)) + in2[8] *
             ((((t202_tmp_tmp + t266 * t418) - t344 * t621 / 4.0) + t359 * t623 /
               4.0) - t633_tmp * t413 * 2.0)) + in2[9] * ((((t464 + t266 * t419)
    - t285 * t621 / 4.0) + t84_tmp * t623 / 4.0) - t633_tmp * t414 * 2.0);
  t656 = t462 + t463;
  t655 = t603_tmp * t407 / 2.0 + t605_tmp * t433_tmp / 2.0;
  t840 = ((t216 * t407 / 2.0 + -(t210 * t433_tmp / 2.0)) + t643) + t82;
  t839 = ((t218 * t407 / 2.0 + -(t212 * t433_tmp / 2.0)) + t645) + t85;
  out3[4] = (((-in2[6] * (((((((((-t469 - t483) + t495) + t520) - t838) + t841)
    + t238 * t620) + t242 * t618) - t634_tmp_tmp * t621) + b_t633_tmp * t623) -
               in2[7] * ((((((((t655 + t429_tmp * t334) - t432_tmp * t283) -
    t82_tmp * t433_tmp / 4.0) - t86_tmp * t407 / 4.0) + t333_tmp * t621 / 4.0) -
    t195 * t623 / 4.0) + t83_tmp * t769_tmp_tmp * 2.0) - t633_tmp * t635 * 2.0))
              - in2[8] * ((((t840 + t238 * t418) + t266 * t413) - t359 * t621 /
    4.0) - t344 * t623 / 4.0)) - in2[9] * ((((t839 + t238 * t419) + t266 * t414)
    - t84_tmp * t621 / 4.0) - t285 * t623 / 4.0)) + in2[5] * ((((((((((t656 +
    t242 * t619) + t429_tmp * t827) - t432_tmp * t829) - t88_tmp * t433_tmp *
    12.0) + t204 * t433_tmp * 2.0) - t633_tmp * t617 * 2.0) + t633_tmp * t621) -
    t83_tmp * t623) - t81 * t407 * 12.0) + t305_tmp_tmp * t407 * 2.0);
  t82_tmp = t39_tmp * (t12_tmp + 1.0);
  t86_tmp = t212_tmp_tmp_tmp * (t12_tmp + 1.0);
  t88_tmp = t407 * t93 + t831 * t433_tmp;
  out3[5] = (((-in2[7] * (((-t623 * t635 + t407 * t283) + t621 * t769_tmp_tmp) +
    t334 * t433_tmp) + in2[6] * ((t88_tmp - t618 * t621) - t620 * t623)) + in2[5]
              * (((t407 * t829 - t617 * t623) + t619 * t621) + t827 * t433_tmp))
             - in2[8] * (((((t107 + -t780) - t413 * t621) + t418 * t623) +
    t82_tmp * t28 * t35 * 2.0) + t82_tmp * t29 * t35 * 2.0)) - in2[9] * (((((t39
    + -t781) - t414 * t621) + t419 * t623) + t86_tmp * t28 * t35 * 2.0) +
    t86_tmp * t29 * t35 * 2.0);
  b_t266_tmp = t266_tmp * t9;
  t82_tmp = b_t266_tmp * 1.4142135623730951;
  t86_tmp = t82_tmp * (t12_tmp + 1.0);
  t82_tmp *= t19;
  t81 = b_t577_tmp_tmp * t63;
  t217_tmp = t761_tmp_tmp * t63;
  t101_tmp = in1[16] * t243;
  t99_tmp = t86_tmp * t26 * t36 * t47;
  t86_tmp = t86_tmp * t27 * t36 * t47;
  b_t99_tmp = t82_tmp * t26 * t33 * t48;
  t82_tmp = t82_tmp * t27 * t33 * t48;
  t216_tmp = ((((t592_tmp * t405 / 2.0 + -(in1[16] * in2[1] * t3 *
    1.4142135623730951 * (t12_tmp + 1.0) * t27 * t35 * t48 * t60 * t406 / 2.0))
                + t577_tmp * t620 / 4.0) + -(b_t761_tmp * t618 / 4.0)) + t87 *
              t635) + t715_tmp * t769_tmp_tmp;
  out3[6] = (((in2[7] * ((((t216_tmp + t361 * t279 / 2.0) - t335 * t284 / 2.0) -
    t81 * t405 / 4.0) + t217_tmp * t406 / 4.0) + t333 * in2[8]) + t330 * in2[9])
             - in2[6] * (((((((((t459 - t326) - t101_tmp * t618) - t335 * t828 /
    2.0) + t361 * t830 / 2.0) + in1[16] * in2[1] * t3 * 1.4142135623730951 *
    (t12_tmp + 1.0) * t26 * t35 * t47 * t620 * 2.0) - t99_tmp * t405 * 12.0) +
    b_t99_tmp * t405 * 2.0) + t86_tmp * t406 * 12.0) - t82_tmp * t406 * 2.0)) -
    in2[5] * t34;
  t34 = ((((t594_tmp * t48 * t60 * t405 / 2.0 + t592_tmp * t406 / 2.0) +
           t577_tmp * t618 / 4.0) + b_t761_tmp * t620 / 4.0) + t715_tmp * t635)
    + -in1[16] * in2[1] * t3 * 1.4142135623730951 * (t12_tmp + 1.0) * t26 * t35 *
    t47 * t769_tmp_tmp;
  out3[7] = (((in2[7] * ((((t34 - t335 * t279 / 2.0) - t361 * t284 / 2.0) - t81 *
    t406 / 4.0) - t217_tmp * t405 / 4.0) - t84 * in2[8]) - t876 * in2[9]) - t25 *
             in2[5]) - in2[6] * ((((((((t83 + in1[16] * t239 * t618) + t101_tmp *
    t620) - t361 * t828 / 2.0) - t335 * t830 / 2.0) - t99_tmp * t406 * 12.0) -
    t86_tmp * t405 * 12.0) + b_t99_tmp * t406 * 2.0) + t82_tmp * t405 * 2.0);
  t82_tmp = b_t266_tmp * (t12_tmp + 1.0);
  t86_tmp = in1[16] * t620 * t635 + -in1[16] * t618 * t769_tmp_tmp;
  out3[8] = (((-t66 * in2[8] - t102 * in2[9]) + t625 * in2[5]) - in2[6] *
             ((((((t68 + in1[16] * (t618 * t618)) + in1[16] * (t620 * t620)) +
                 t608_tmp * t828) + t343 * t830) - t82_tmp * t28 * t36 * 12.0) -
              t82_tmp * t29 * t36 * 12.0)) + in2[7] * ((((t86_tmp - t198 * t63 /
    4.0) - t199 * t63 / 4.0) + t343 * t279) + t608_tmp * t284);
  t82_tmp = b_t332_tmp * t63;
  t68 = b_t331_tmp * t63;
  t83 = t5 * t9 * 1.4142135623730951 * (t12_tmp + 1.0) * t27 * t36 * t47;
  t81 = t5 * t9 * 1.4142135623730951 * (t12_tmp + 1.0) * t26 * t36 * t47;
  t217_tmp = -(t606_tmp * t407 / 2.0) + t604_tmp * t433_tmp / 2.0;
  t101_tmp = ((t211 * t407 / 2.0 + t217 * t433_tmp / 2.0) + t644) + t332;
  t99_tmp = ((t214 * t407 / 2.0 + t220 * t433_tmp / 2.0) + t646) + t331;
  out3[9] = (((in2[8] * ((((t101_tmp - t359 * t622 / 4.0) - t344 * t624 / 4.0) -
    t634_tmp_tmp * t413 * 2.0) - b_t633_tmp * t418 * 2.0) + in2[6] *
               ((((((((((t214_tmp_tmp + t239 * t618) + t432_tmp * t828) -
                       t429_tmp * t830) + t81 * t433_tmp * 12.0) - t202 *
                     t433_tmp * 2.0) - b_t633_tmp * t620 * 2.0) - t634_tmp_tmp *
                   t622) + b_t633_tmp * t624) - t83 * t407 * 12.0) + t203 * t407
                * 2.0)) + in2[9] * ((((t99_tmp - t84_tmp * t622 / 4.0) - t285 *
    t624 / 4.0) - t634_tmp_tmp * t414 * 2.0) - b_t633_tmp * t419 * 2.0)) + in2[7]
             * ((((((((t217_tmp + t243 * t635) + t239 * t769_tmp_tmp) + t429_tmp
                     * t279) - t432_tmp * t284) - t68 * t433_tmp / 4.0) +
                  t82_tmp * t407 / 4.0) + t333_tmp * t622 / 4.0) - t195 * t624 /
                4.0)) + in2[5] * ((((t212_tmp_tmp - b_t633_tmp * t617 * 2.0) -
    t634_tmp_tmp * t619 * 2.0) - t633_tmp * t622) + t83_tmp * t624);
  t214_tmp_tmp = t604_tmp * t407 / 2.0 + t606_tmp * t433_tmp / 2.0;
  t212_tmp_tmp = ((t217 * t407 / 2.0 - t211 * t433_tmp / 2.0) + t647) - t206;
  b_t99_tmp = ((t220 * t407 / 2.0 - t214 * t433_tmp / 2.0) + t648) - t207;
  out3[10] = (((-in2[7] * ((((((((t214_tmp_tmp + t243 * t769_tmp_tmp) + t432_tmp
    * t279) + t429_tmp * t284) - t82_tmp * t433_tmp / 4.0) - t68 * t407 / 4.0) +
    t195 * t622 / 4.0) + t333_tmp * t624 / 4.0) - t634_tmp_tmp * t635 * 2.0) -
                in2[8] * ((((t212_tmp_tmp + t239 * t418) + t344 * t622 / 4.0) -
    t359 * t624 / 4.0) - b_t633_tmp * t413 * 2.0)) + in2[5] * (((((((((t469 +
    t483) - t495) - t520) + t838) - t841) + t243 * t619) - t634_tmp_tmp * t617 *
    2.0) + t83_tmp * t622) + t633_tmp * t624)) - in2[9] * ((((b_t99_tmp + t239 *
    t419) + t285 * t622 / 4.0) - t84_tmp * t624 / 4.0) - b_t633_tmp * t414 * 2.0))
    + in2[6] * ((((((((((t656 + t429_tmp * t828) + t432_tmp * t830) - t83 *
                       t433_tmp * 12.0) + t203 * t433_tmp * 2.0) - b_t633_tmp *
                     t618 * 2.0) - t634_tmp_tmp * t620 * 2.0) + b_t633_tmp *
                   t622) + t634_tmp_tmp * t624) - t81 * t407 * 12.0) + t202 *
                t407 * 2.0);
  t82_tmp = t63_tmp * (t12_tmp + 1.0);
  t68 = t214_tmp_tmp_tmp * (t12_tmp + 1.0);
  t83 = t407 * t627 + t629 * t433_tmp;
  t81 = t407 * t628 + t630 * t433_tmp;
  out3[11] = (((-in2[7] * (((t622 * t635 - t407 * t279) + t624 * t769_tmp_tmp) +
    t284 * t433_tmp) + in2[5] * ((t88_tmp + t617 * t622) + t619 * t624)) - in2[6]
               * (((t407 * t830 + t618 * t624) - t620 * t622) - t828 * t433_tmp))
              + in2[8] * ((((t83 + t413 * t624) + t418 * t622) - t82_tmp * t28 *
    t35 * 2.0) - t82_tmp * t29 * t35 * 2.0)) + in2[9] * ((((t81 + t414 * t624) +
    t419 * t622) - t68 * t28 * t35 * 2.0) - t68 * t29 * t35 * 2.0);
  b_t266_tmp = t467_tmp_tmp * t4;
  t82_tmp = b_t266_tmp * 1.4142135623730951;
  t68 = t82_tmp * t19;
  t81_tmp = t592_tmp_tmp * t4;
  t88_tmp = t81_tmp * 1.4142135623730951;
  t656 = t88_tmp * t19;
  c_t99_tmp = t82_tmp * t26 * t35 * t47;
  t82_tmp = t82_tmp * t27 * t35 * t47;
  t102_tmp = t68 * t26 * t36 * t47;
  t68 = t68 * t27 * t36 * t47;
  t632 = t88_tmp * t26 * t35 * t47;
  t88_tmp = t88_tmp * t27 * t35 * t47;
  t631 = t656 * t26 * t36 * t47;
  t656 = t656 * t27 * t36 * t47;
  t31 = t577_tmp_tmp * t48 * t61;
  t11 = t761_tmp * t48 * t61;
  t2 = b_t577_tmp_tmp * t64;
  t25 = t761_tmp_tmp * t64;
  out3[12] = (((-t208 * in2[8] - t209 * in2[9]) + in2[5] * (((((((t291_tmp +
    t335 * t205 / 2.0) - t361 * t855 / 2.0) - c_t99_tmp * t405 * 2.0) + t82_tmp *
    t406 * 2.0) + t102_tmp * t405 * 6.0) - t68 * t406 * 6.0) + t88)) + in2[6] *
              ((((((t216_tmp + t361 * t6 / 2.0) + t335 * t96 / 2.0) - t632 *
                  t405 * 2.0) + t88_tmp * t406 * 2.0) + t631 * t405 * 6.0) -
               t656 * t406 * 6.0)) + in2[7] * (((((((t335 * t852 / 2.0 + t361 *
    t37 / 2.0) - t31 * t405 / 8.0) - t2 * t405 / 4.0) + t11 * t406 / 8.0) + t25 *
    t406 / 4.0) - t577_tmp * t635 / 2.0) - b_t761_tmp * t769_tmp_tmp / 2.0);
  t291_tmp = ((((((-(t557_tmp * t405 / 8.0) + t325 * t406 / 8.0) + t577_tmp *
                  t413 / 4.0) - b_t761_tmp * t418 / 4.0) + t371 * t635 / 4.0) -
               in1[16] * t721 / 2.0) + in1[16] * t72 / 2.0) + t358 *
    t769_tmp_tmp / 4.0;
  t88 = ((((((-(t563_tmp * t405 / 8.0) + b_t82_tmp * t406 / 8.0) + t577_tmp *
             t414 / 4.0) - b_t761_tmp * t419 / 4.0) - in1[16] * t722 / 2.0) +
          t373 * t635 / 4.0) + in1[16] * t99 / 2.0) + t281 * t769_tmp_tmp / 4.0;
  out3[13] = (((-in2[8] * t291_tmp - in2[9] * t88) + in2[5] * ((((((t86 + t335 *
    t855 / 2.0) + t361 * t205 / 2.0) - c_t99_tmp * t406 * 2.0) - t82_tmp * t405 *
    2.0) + t102_tmp * t406 * 6.0) + t68 * t405 * 6.0)) + in2[6] * ((((((t34 -
    t335 * t6 / 2.0) + t361 * t96 / 2.0) - t632 * t406 * 2.0) - t88_tmp * t405 *
    2.0) + t631 * t406 * 6.0) + t656 * t405 * 6.0)) - in2[7] * (((((((t335 * t37
    / 2.0 - t361 * t852 / 2.0) + t31 * t406 / 8.0) + t11 * t405 / 8.0) + t2 *
    t406 / 4.0) + t25 * t405 / 4.0) + b_t761_tmp * t635 / 2.0) - t577_tmp *
    t769_tmp_tmp / 2.0);
  t82_tmp = b_t266_tmp * t19;
  t68 = t81_tmp * t19;
  out3[14] = (((in2[5] * (((((((t101 - t608_tmp * t205) - t343 * t855) +
    b_t81_tmp) - b_t266_tmp * t28 * t35 * 2.0) - b_t266_tmp * t29 * t35 * 2.0) +
    t82_tmp * t28 * t36 * 6.0) + t82_tmp * t29 * t36 * 6.0) + t105 * in2[8]) +
               t870 * in2[9]) - in2[7] * (((((in1[16] * (t635 * t635) + in1[16] *
    (t769_tmp_tmp * t769_tmp_tmp)) + t198 * t64 / 4.0) + t199 * t64 / 4.0) +
    t608_tmp * t852) - t343 * t37)) + in2[6] * ((((((t86_tmp + t343 * t6) -
    t608_tmp * t96) - t81_tmp * t28 * t35 * 2.0) - t81_tmp * t29 * t35 * 2.0) +
    t68 * t28 * t36 * 6.0) + t68 * t29 * t36 * 6.0);
  t82_tmp = 1.4142135623730951 * t27 * t48 * t61;
  t68 = b_t332_tmp * t64;
  b_t81_tmp = 1.4142135623730951 * t26 * t48 * t61;
  t86_tmp = b_t331_tmp * t64;
  t88_tmp = ((t565_tmp * t407 / 8.0 + t567_tmp * t433_tmp / 8.0) + t721) + t72;
  t34 = ((t571_tmp * t407 / 8.0 + t573_tmp * t433_tmp / 8.0) + t722) + t99;
  out3[15] = (((in2[7] * (((((((((t429_tmp * t37 + t432_tmp * t852) - b_t81_tmp *
    t433_tmp / 8.0) - t86_tmp * t433_tmp / 4.0) + t82_tmp * t407 / 8.0) + t68 *
    t407 / 4.0) - t333_tmp * t634 / 4.0) + t195 * t633 / 4.0) - t195 * t635 /
    2.0) - t333_tmp * t769_tmp_tmp / 2.0) + in2[5] * (((((((((((-t597 + t603) -
    t429_tmp * t855) + t432_tmp * t205) + t195 * t617 / 2.0) + t333_tmp * t619 /
    2.0) - t93_tmp * t433_tmp * 2.0) + t95_tmp * t407 * 2.0) + t852_tmp *
    t433_tmp * 6.0) - t853_tmp * t407 * 6.0) + t633_tmp * t634) - t83_tmp * t633))
               + in2[6] * ((((((((((t217_tmp + t429_tmp * t6) + t432_tmp * t96)
    - t333_tmp * t618 / 2.0) + t195 * t620 / 2.0) - t94_tmp * t433_tmp * 2.0) +
    t96_tmp * t407 * 2.0) + b_t853_tmp * t433_tmp * 6.0) - b_t852_tmp * t407 *
    6.0) + t634_tmp_tmp * t634) - b_t633_tmp * t633)) - in2[8] * ((((t88_tmp -
    t344 * t633 / 4.0) - t359 * t634 / 4.0) - t333_tmp * t413 / 2.0) - t195 *
    t418 / 2.0)) - in2[9] * ((((t34 - t333_tmp * t414 / 2.0) - t195 * t419 / 2.0)
    - t285 * t633 / 4.0) - t84_tmp * t634 / 4.0);
  t86 = ((t567_tmp * t407 / 8.0 - t565_tmp * t433_tmp / 8.0) + t723) - t106;
  t656 = ((t573_tmp * t407 / 8.0 - t571_tmp * t433_tmp / 8.0) + t724) - t71;
  out3[16] = (((in2[7] * (((((((((t429_tmp * t852 - t432_tmp * t37) + t82_tmp *
    t433_tmp / 8.0) + t68 * t433_tmp / 4.0) + b_t81_tmp * t407 / 8.0) + t86_tmp *
    t407 / 4.0) + t333_tmp * t633 / 4.0) - t333_tmp * t635 / 2.0) + t195 * t634 /
    4.0) + t195 * t769_tmp_tmp / 2.0) + in2[8] * ((((t86 + t344 * t634 / 4.0) -
    t359 * t633 / 4.0) - t195 * t413 / 2.0) + t333_tmp * t418 / 2.0)) + in2[9] *
               ((((t656 - t195 * t414 / 2.0) + t333_tmp * t419 / 2.0) + t285 *
                 t634 / 4.0) - t84_tmp * t633 / 4.0)) - in2[5] * ((((((((((t655
    - t429_tmp * t205) - t432_tmp * t855) - t333_tmp * t617 / 2.0) + t195 * t619
    / 2.0) - t95_tmp * t433_tmp * 2.0) - t93_tmp * t407 * 2.0) + t853_tmp *
    t433_tmp * 6.0) + t852_tmp * t407 * 6.0) + t633_tmp * t633) + t83_tmp * t634))
    - in2[6] * ((((((((((t214_tmp_tmp + t432_tmp * t6) - t429_tmp * t96) - t195 *
                       t618 / 2.0) - t333_tmp * t620 / 2.0) - t96_tmp * t433_tmp
                     * 2.0) - t94_tmp * t407 * 2.0) + b_t852_tmp * t433_tmp *
                   6.0) + b_t853_tmp * t407 * 6.0) + t634_tmp_tmp * t633) +
                b_t633_tmp * t634);
  t82_tmp = t407 * t636 + t639 * t433_tmp;
  t68 = t407 * t637 + t640 * t433_tmp;
  out3[17] = (((-in2[8] * ((((t82_tmp + t413 * t633) + t418 * t634) - t372 * t60
    / 2.0) - t360 * t60 / 2.0) + in2[7] * (((t407 * t37 + t634 * t635) + t633 *
    t769_tmp_tmp) + t852 * t433_tmp)) - in2[9] * ((((t68 + t414 * t633) + t419 *
    t634) - t194 * t60 / 2.0) - t331_tmp * t60 / 2.0)) - in2[5] * (((t617 * t634
    + t619 * t633) + t407 * t855) - t205 * t433_tmp)) + in2[6] * (((t618 * t633
    - t620 * t634) + t407 * t6) + t96 * t433_tmp);
  out3[18] = (((-t108 * in2[9] + t873 * in2[5]) + t333 * in2[6]) - t208 * in2[7])
    - in2[8] * (((((t335 * t415 / 2.0 - t361 * t420 / 2.0) - t371 * t413 / 2.0)
                  + t358 * t418 / 2.0) + t280 / 8.0) - t376 / 8.0);
  out3[19] = (((-t104 * in2[9] - t235 * in2[5]) - t84 * in2[6]) - in2[8] *
              (((((t361 * t415 / 2.0 + t335 * t420 / 2.0) - t358 * t413 / 2.0) -
                 t371 * t418 / 2.0) + t374 / 8.0) + t375 / 8.0)) - in2[7] *
    t291_tmp;
  b_t81_tmp = ((t608_tmp * t416 + t343 * t421) - t615_tmp * t414) - t85_tmp *
    t419;
  out3[20] = (((t865 * in2[5] - t66 * in2[6]) + t105 * in2[7]) + in2[9] *
              b_t81_tmp) - in2[8] * (((in1[16] * (t413 * t413) + in1[16] * (t418
    * t418)) - t608_tmp * t415) - t343 * t420);
  t86_tmp = ((b_t433_tmp * t407 / 8.0 + t435) + -(t425_tmp * t433_tmp / 8.0)) +
    -t432;
  out3[21] = (((in2[6] * ((((t101_tmp + t359 * t618 / 2.0) + t344 * t620 / 2.0)
    + t634_tmp_tmp * t409) + b_t633_tmp * t411) + in2[5] * ((((t202_tmp_tmp +
    t344 * t617 / 2.0) - t359 * t619 / 2.0) + t633_tmp * t409) + t83_tmp * t411))
               + in2[9] * ((((t86_tmp - t359 * t414 / 2.0) + t344 * t419 / 2.0)
    + t84_tmp * t409 / 4.0) - t285 * t411 / 4.0)) - in2[7] * ((((t88_tmp + t344 *
    t635 / 2.0) + t333_tmp * t409 / 4.0) + t195 * t411 / 4.0) - t359 *
    t769_tmp_tmp / 2.0)) - in2[8] * (((((((t432_tmp * t415 - t429_tmp * t420) +
    t332_tmp / 8.0) - t359 * t409 / 4.0) + t344 * t411 / 4.0) + t359 * t413 /
    2.0) - t344 * t418 / 2.0) - t323 / 8.0);
  t88_tmp = ((t425_tmp * t407 / 8.0 - t429) + b_t433_tmp * t433_tmp / 8.0) -
    t437;
  out3[22] = (((-in2[5] * ((((t840 + t359 * t617 / 2.0) + t344 * t619 / 2.0) +
    t83_tmp * t409) - t633_tmp * t411) + in2[9] * ((((t88_tmp - t344 * t414 /
    2.0) - t359 * t419 / 2.0) + t285 * t409 / 4.0) + t84_tmp * t411 / 4.0)) +
               in2[7] * ((((t86 + t359 * t635 / 2.0) + t195 * t409 / 4.0) -
    t333_tmp * t411 / 4.0) + t344 * t769_tmp_tmp / 2.0)) - in2[8] *
              (((((((t429_tmp * t415 + t432_tmp * t420) - t87_tmp / 8.0) - t344 *
                   t409 / 4.0) - t359 * t411 / 4.0) + t344 * t413 / 2.0) + t359 *
                t418 / 2.0) - t324 / 8.0)) - in2[6] * ((((t212_tmp_tmp - t344 *
    t618 / 2.0) + t359 * t620 / 2.0) + b_t633_tmp * t409) - t634_tmp_tmp * t411);
  t291_tmp = t407 * t421 - t416 * t433_tmp;
  out3[23] = (((in2[9] * ((t291_tmp + t411 * t414) - t409 * t419) + in2[5] *
                (((t780 - t107) - t409 * t617) + t411 * t619)) + in2[6] * ((t83
    - t409 * t620) - t411 * t618)) - in2[7] * ((t82_tmp - t409 * t635) + t411 *
    t769_tmp_tmp)) + in2[8] * (((t411 * t413 + t407 * t420) - t409 * t418) -
    t415 * t433_tmp);
  t82_tmp = t266_tmp * 1.4142135623730951;
  t83 = t82_tmp * t26 * t46;
  t82_tmp = t82_tmp * t27 * t46;
  out3[24] = (((-t108 * in2[8] + t877 * in2[5]) + t330 * in2[6]) - t209 * in2[7])
    - in2[9] * (((((t335 * t417 / 2.0 - t361 * t422 / 2.0) + t83 * t405 / 8.0) -
                  t82_tmp * t406 / 8.0) - t373 * t414 / 2.0) + t281 * t419 / 2.0);
  out3[25] = (((-t104 * in2[8] - t233 * in2[5]) - t876 * in2[6]) - in2[9] *
              (((((t361 * t417 / 2.0 + t335 * t422 / 2.0) + t83 * t406 / 8.0) +
                 t82_tmp * t405 / 8.0) - t281 * t414 / 2.0) - t373 * t419 / 2.0))
    - in2[7] * t88;
  out3[26] = (((t65 * in2[5] - t102 * in2[6]) + t870 * in2[7]) + in2[8] *
              b_t81_tmp) - in2[9] * (((in1[16] * (t414 * t414) + in1[16] * (t419
    * t419)) - t608_tmp * t417) - t343 * t422);
  t82_tmp = t5 * 1.4142135623730951 * t27 * t46;
  b_t81_tmp = t5 * 1.4142135623730951 * t26 * t46;
  out3[27] = (((in2[6] * ((((t99_tmp + t84_tmp * t618 / 2.0) + t285 * t620 / 2.0)
    + t634_tmp_tmp * t410) + b_t633_tmp * t412) + in2[5] * ((((t464 + t285 *
    t617 / 2.0) - t84_tmp * t619 / 2.0) + t633_tmp * t410) + t83_tmp * t412)) +
               in2[8] * ((((t86_tmp + t359 * t410 / 4.0) - t344 * t412 / 4.0) -
    t84_tmp * t413 / 2.0) + t285 * t418 / 2.0)) - in2[7] * ((((t34 + t333_tmp *
    t410 / 4.0) + t195 * t412 / 4.0) + t285 * t635 / 2.0) - t84_tmp *
    t769_tmp_tmp / 2.0)) - in2[9] * (((((((t432_tmp * t417 - t429_tmp * t422) +
    b_t81_tmp * t433_tmp / 8.0) - t82_tmp * t407 / 8.0) - t84_tmp * t410 / 4.0)
    + t285 * t412 / 4.0) + t84_tmp * t414 / 2.0) - t285 * t419 / 2.0);
  out3[28] = (((-in2[6] * ((((b_t99_tmp - t285 * t618 / 2.0) + t84_tmp * t620 /
    2.0) + b_t633_tmp * t410) - t634_tmp_tmp * t412) + in2[8] * ((((t88_tmp +
    t344 * t410 / 4.0) + t359 * t412 / 4.0) - t285 * t413 / 2.0) - t84_tmp *
    t418 / 2.0)) - in2[5] * ((((t839 + t84_tmp * t617 / 2.0) + t285 * t619 / 2.0)
    + t83_tmp * t410) - t633_tmp * t412)) + in2[7] * ((((t656 + t195 * t410 /
    4.0) - t333_tmp * t412 / 4.0) + t84_tmp * t635 / 2.0) + t285 * t769_tmp_tmp /
    2.0)) - in2[9] * (((((((t429_tmp * t417 + t432_tmp * t422) - t82_tmp *
    t433_tmp / 8.0) - b_t81_tmp * t407 / 8.0) - t285 * t410 / 4.0) - t84_tmp *
                        t412 / 4.0) + t285 * t414 / 2.0) + t84_tmp * t419 / 2.0);
  out3[29] = (((in2[8] * ((t291_tmp + t412 * t413) - t410 * t418) + in2[5] *
                (((t781 - t39) - t410 * t617) + t412 * t619)) + in2[6] * ((t81 -
    t410 * t620) - t412 * t618)) - in2[7] * ((t68 - t410 * t635) + t412 *
    t769_tmp_tmp)) + in2[9] * (((t412 * t414 + t407 * t422) - t410 * t419) -
    t417 * t433_tmp);
  out4[0] = in1[12];
  out4[1] = in1[13];
  out4[2] = in1[14];
  out4[3] = 0.0;
  out4[4] = 0.0;
  out4[5] = 0.0;
}

/* End of code generation (massF2.c) */
