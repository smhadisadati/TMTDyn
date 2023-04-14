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
#include "EOM_eq_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo uc_emlrtRSI = { 102,/* lineNo */
  "massF2",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\massF2.m"/* pathName */
};

/* Function Definitions */
void massF2(const emlrtStack *sp, const real_T in1[34], const real_T in2[30],
            real_T out1[36], real_T out2[90], real_T out3[90], real_T out4[6])
{
  emlrtStack st;
  real_T t10;
  real_T t100;
  real_T t101;
  real_T t102;
  real_T t102_tmp;
  real_T t103;
  real_T t104;
  real_T t105;
  real_T t106;
  real_T t107;
  real_T t11;
  real_T t120;
  real_T t121;
  real_T t122;
  real_T t123;
  real_T t124;
  real_T t125;
  real_T t126;
  real_T t127;
  real_T t128;
  real_T t129;
  real_T t130;
  real_T t131;
  real_T t132;
  real_T t133;
  real_T t134;
  real_T t137;
  real_T t15;
  real_T t16;
  real_T t17;
  real_T t18;
  real_T t19;
  real_T t195;
  real_T t196;
  real_T t197;
  real_T t198;
  real_T t199;
  real_T t2;
  real_T t200;
  real_T t201;
  real_T t202;
  real_T t203;
  real_T t204;
  real_T t205;
  real_T t206;
  real_T t207;
  real_T t208;
  real_T t209;
  real_T t21;
  real_T t210;
  real_T t211;
  real_T t212;
  real_T t213;
  real_T t219;
  real_T t22;
  real_T t220;
  real_T t221;
  real_T t222;
  real_T t223;
  real_T t224;
  real_T t225;
  real_T t226;
  real_T t227;
  real_T t229;
  real_T t23;
  real_T t231;
  real_T t232;
  real_T t233;
  real_T t234;
  real_T t235;
  real_T t236;
  real_T t237;
  real_T t238;
  real_T t239;
  real_T t24;
  real_T t240;
  real_T t25;
  real_T t273;
  real_T t274;
  real_T t275;
  real_T t276;
  real_T t277;
  real_T t283;
  real_T t284;
  real_T t285;
  real_T t286;
  real_T t287;
  real_T t288;
  real_T t289;
  real_T t290;
  real_T t291;
  real_T t296;
  real_T t299;
  real_T t3;
  real_T t301;
  real_T t302;
  real_T t303;
  real_T t304;
  real_T t305;
  real_T t306;
  real_T t307;
  real_T t308;
  real_T t309;
  real_T t310;
  real_T t311;
  real_T t312;
  real_T t313;
  real_T t314;
  real_T t315;
  real_T t316;
  real_T t317;
  real_T t318;
  real_T t319;
  real_T t320;
  real_T t321;
  real_T t322;
  real_T t323;
  real_T t324;
  real_T t325;
  real_T t326;
  real_T t327;
  real_T t328;
  real_T t329;
  real_T t330;
  real_T t331;
  real_T t332;
  real_T t335;
  real_T t337;
  real_T t339;
  real_T t341;
  real_T t343;
  real_T t345;
  real_T t349;
  real_T t351;
  real_T t352;
  real_T t353;
  real_T t354;
  real_T t355;
  real_T t356;
  real_T t357;
  real_T t358;
  real_T t359;
  real_T t360;
  real_T t361;
  real_T t362;
  real_T t363;
  real_T t364;
  real_T t365;
  real_T t366;
  real_T t367;
  real_T t368;
  real_T t369;
  real_T t370;
  real_T t371;
  real_T t372;
  real_T t373;
  real_T t374;
  real_T t375;
  real_T t376;
  real_T t383;
  real_T t384;
  real_T t386;
  real_T t387;
  real_T t388;
  real_T t389;
  real_T t390;
  real_T t391;
  real_T t392;
  real_T t393;
  real_T t394;
  real_T t395;
  real_T t4;
  real_T t40;
  real_T t41;
  real_T t42;
  real_T t44;
  real_T t45;
  real_T t46;
  real_T t47;
  real_T t48;
  real_T t49;
  real_T t5;
  real_T t50;
  real_T t51;
  real_T t52;
  real_T t53;
  real_T t54;
  real_T t58;
  real_T t59;
  real_T t6;
  real_T t60;
  real_T t61;
  real_T t62;
  real_T t63;
  real_T t64;
  real_T t65;
  real_T t66;
  real_T t7;
  real_T t70;
  real_T t71;
  real_T t72;
  real_T t74;
  real_T t75;
  real_T t76;
  real_T t78;
  real_T t79;
  real_T t8;
  real_T t80;
  real_T t81;
  real_T t82;
  real_T t83;
  real_T t84;
  real_T t85;
  real_T t86;
  real_T t87;
  real_T t88;
  real_T t89;
  real_T t9;
  real_T t90;
  real_T t91;
  real_T t92;
  real_T t93;
  real_T t93_tmp;
  real_T t94;
  real_T t95;
  real_T t96;
  real_T t97;
  real_T t97_tmp;
  real_T t98;
  real_T t98_tmp;
  real_T t99;
  st.prev = sp;
  st.tls = sp->tls;

  /* MASSF2 */
  /*     [OUT1,OUT2,OUT3,OUT4] = MASSF2(IN1,IN2,S,DS,T_SYM) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
  /*     15-Jun-2021 01:48:12 */
  t2 = in1[4] * in2[6];
  t3 = in1[4] * in2[9];
  t4 = in1[4] * in2[12];
  t5 = in1[16] * in1[16];
  t6 = in1[4] * in1[4];
  t7 = muDoubleScalarPower(in1[4], 3.0);
  t9 = muDoubleScalarPower(in1[4], 5.0);
  t11 = in1[17] * in1[17];
  t8 = t6 * t6;
  t10 = muDoubleScalarPower(t6, 3.0);
  t15 = t6 * 2.0;
  t16 = t7 * 2.0;
  t18 = t9 * 2.0;
  t21 = in1[16] * t6;
  t22 = in1[16] * t7;
  t24 = in1[16] * t9;
  t17 = t8 * 2.0;
  t19 = t10 * 2.0;
  t23 = in1[16] * t8;
  t25 = in1[16] * t10;
  t40 = (t2 + in2[7] * t6) + in2[8] * t7;
  t41 = (t3 + in2[10] * t6) + in2[11] * t7;
  t42 = (t4 + in2[13] * t6) + in2[14] * t7;
  t44 = t40 * t40;
  t45 = muDoubleScalarPower(t40, 3.0);
  t46 = t41 * t41;
  t47 = muDoubleScalarPower(t41, 3.0);
  t48 = t42 * t42;
  t195 = in1[16] * in1[4];
  t49 = t195 * t42;
  t50 = (t2 * 2.0 + in2[7] * t15) + in2[8] * t16;
  t51 = (t3 * 2.0 + in2[10] * t15) + in2[11] * t16;
  t52 = (t4 * 2.0 + in2[13] * t15) + in2[14] * t16;
  t53 = t21 * t42;
  t54 = t22 * t42;
  t58 = in1[4] * t50;
  t59 = in1[4] * t51;
  t60 = in1[4] * t52;
  t61 = t6 * t50;
  t62 = t7 * t50;
  t63 = t6 * t51;
  t64 = t7 * t51;
  t65 = t6 * t52;
  t66 = t7 * t52;
  t2 = in1[15] * t5 / 4.0 + in1[15] * (t5 + t11 * 3.0) / 12.0;
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
  out1[35] = in1[15] * t11 / 2.0;
  t2 = ((-t44 + -t46) + -t48) + 1.0;
  st.site = &uc_emlrtRSI;
  if (t2 < 0.0) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  t2 = muDoubleScalarSqrt(t2);
  t70 = 1.0 / t2;
  t72 = in1[4] * t2 * 2.0;
  t3 = t195 * t2;
  t74 = t21 * t2;
  t75 = t22 * t2;
  t76 = t15 * t2;
  t4 = t16 * t2;
  t71 = muDoubleScalarPower(t70, 3.0);
  t78 = t15 * t40 * t70;
  t79 = t16 * t40 * t70;
  t80 = t17 * t40 * t70;
  t81 = t18 * t40 * t70;
  t82 = t19 * t40 * t70;
  t83 = t15 * t41 * t70;
  t84 = t16 * t41 * t70;
  t85 = t17 * t41 * t70;
  t86 = t18 * t41 * t70;
  t87 = t19 * t41 * t70;
  t88 = t15 * t42 * t70;
  t89 = t16 * t42 * t70;
  t90 = t17 * t42 * t70;
  t91 = t18 * t42 * t70;
  t92 = t19 * t42 * t70;
  t93_tmp = t21 * t40;
  t93 = t93_tmp * t70;
  t335 = t22 * t40;
  t94 = t335 * t70;
  t337 = t23 * t40;
  t95 = t337 * t70;
  t339 = t24 * t40;
  t96 = t339 * t70;
  t97_tmp = t25 * t40;
  t97 = t97_tmp * t70;
  t98_tmp = t21 * t41;
  t98 = t98_tmp * t70;
  t341 = t22 * t41;
  t99 = t341 * t70;
  t343 = t23 * t41;
  t100 = t343 * t70;
  t345 = t24 * t41;
  t101 = t345 * t70;
  t102_tmp = t25 * t41;
  t102 = t102_tmp * t70;
  t103 = t53 * t70;
  t104 = t54 * t70;
  t349 = t23 * t42;
  t105 = t349 * t70;
  t299 = t24 * t42;
  t106 = t299 * t70;
  t296 = t25 * t42;
  t107 = t296 * t70;
  t120 = t61 * t70;
  t121 = t62 * t70;
  t122 = t8 * t50 * t70;
  t123 = t9 * t50 * t70;
  t124 = t10 * t50 * t70;
  t125 = t63 * t70;
  t126 = t64 * t70;
  t127 = t8 * t51 * t70;
  t128 = t9 * t51 * t70;
  t129 = t10 * t51 * t70;
  t130 = t65 * t70;
  t131 = t66 * t70;
  t132 = t8 * t52 * t70;
  t133 = t9 * t52 * t70;
  t134 = t10 * t52 * t70;
  t5 = t195 * t40;
  t2 = t5 * t41 * t70;
  t11 = t41 * t93;
  t137 = t41 * t94;
  out2[0] = t6;
  out2[1] = 0.0;
  out2[2] = 0.0;
  out2[3] = 0.0;
  out2[4] = 0.0;
  out2[5] = 0.0;
  out2[6] = t7;
  out2[7] = 0.0;
  out2[8] = 0.0;
  out2[9] = 0.0;
  out2[10] = 0.0;
  out2[11] = 0.0;
  out2[12] = 0.0;
  out2[13] = t6;
  out2[14] = 0.0;
  out2[15] = 0.0;
  out2[16] = 0.0;
  out2[17] = 0.0;
  out2[18] = 0.0;
  out2[19] = t7;
  out2[20] = 0.0;
  out2[21] = 0.0;
  out2[22] = 0.0;
  out2[23] = 0.0;
  out2[24] = 0.0;
  out2[25] = 0.0;
  out2[26] = t6;
  out2[27] = 0.0;
  out2[28] = 0.0;
  out2[29] = 0.0;
  out2[30] = 0.0;
  out2[31] = 0.0;
  out2[32] = t7;
  out2[33] = 0.0;
  out2[34] = 0.0;
  out2[35] = 0.0;
  out2[36] = t49 - t2;
  out2[37] = -t3 + t195 * t44 * t70;
  out2[38] = t5 * -2.0;
  out2[39] = t72 + t40 * t58 * t70;
  out2[40] = -t60 + t40 * t59 * t70;
  out2[41] = t59 + t40 * t60 * t70;
  out2[42] = t53 - t11;
  out2[43] = -t74 + t21 * t44 * t70;
  out2[44] = t93_tmp * -2.0;
  out2[45] = t76 + t40 * t120;
  out2[46] = -t65 + t40 * t125;
  out2[47] = t63 + t40 * t130;
  out2[48] = t54 - t137;
  out2[49] = -t75 + t22 * t44 * t70;
  out2[50] = t335 * -2.0;
  out2[51] = t4 + t40 * t121;
  out2[52] = -t66 + t40 * t126;
  out2[53] = t64 + t40 * t131;
  out2[54] = t3 + t195 * -t46 * t70;
  out2[55] = t49 + t2;
  t2 = t195 * t41;
  out2[56] = t2 * -2.0;
  out2[57] = t60 + t41 * t58 * t70;
  out2[58] = t72 + t41 * t59 * t70;
  out2[59] = -t58 + t41 * t60 * t70;
  out2[60] = t74 + t21 * -t46 * t70;
  out2[61] = t53 + t11;
  out2[62] = t98_tmp * -2.0;
  out2[63] = t65 + t41 * t120;
  out2[64] = t76 + t41 * t125;
  out2[65] = -t61 + t41 * t130;
  out2[66] = t75 + t22 * -t46 * t70;
  out2[67] = t54 + t137;
  out2[68] = t341 * -2.0;
  out2[69] = t66 + t41 * t121;
  out2[70] = t4 + t41 * t126;
  out2[71] = -t62 + t41 * t131;
  out2[72] = t5 - t41 * t49 * t70;
  out2[73] = t2 + t40 * t49 * t70;
  out2[74] = 0.0;
  out2[75] = -t59 + t42 * t58 * t70;
  out2[76] = t58 + t42 * t59 * t70;
  out2[77] = t72 + t42 * t60 * t70;
  out2[78] = t93_tmp - t41 * t103;
  out2[79] = t98_tmp + t40 * t103;
  out2[80] = 0.0;
  out2[81] = -t63 + t42 * t120;
  out2[82] = t61 + t42 * t125;
  out2[83] = t76 + t42 * t130;
  out2[84] = t335 - t41 * t104;
  out2[85] = t341 + t40 * t104;
  out2[86] = 0.0;
  out2[87] = -t64 + t42 * t121;
  out2[88] = t62 + t42 * t126;
  out2[89] = t4 + t42 * t131;
  t5 = t40 * t41;
  t75 = t5 * t53 * t71;
  t58 = t5 * t54 * t71;
  t60 = t337 * t41 * t42 * t71;
  t49 = t339 * t41 * t42 * t71;
  t195 = t97_tmp * t41 * t42 * t71;
  t196 = t5 * t61 * t71;
  t197 = t5 * t62 * t71;
  t2 = t8 * t40;
  t11 = t2 * t41;
  t198 = t11 * t50 * t71;
  t3 = t9 * t40;
  t137 = t3 * t41;
  t199 = t137 * t50 * t71;
  t4 = t10 * t40;
  t70 = t4 * t41;
  t200 = t70 * t50 * t71;
  t72 = t40 * t42;
  t201 = t72 * t61 * t71;
  t202 = t5 * t63 * t71;
  t203 = t72 * t62 * t71;
  t204 = t5 * t64 * t71;
  t2 *= t42;
  t205 = t2 * t50 * t71;
  t206 = t11 * t51 * t71;
  t3 *= t42;
  t207 = t3 * t50 * t71;
  t208 = t137 * t51 * t71;
  t4 *= t42;
  t209 = t4 * t50 * t71;
  t210 = t70 * t51 * t71;
  t211 = t5 * t65 * t71;
  t212 = t72 * t63 * t71;
  t74 = t41 * t42;
  t213 = t74 * t61 * t71;
  t76 = t5 * t66 * t71;
  t59 = t72 * t64 * t71;
  t6 = t74 * t62 * t71;
  t7 = t11 * t52 * t71;
  t40 = t2 * t51 * t71;
  t11 = t8 * t41 * t42;
  t219 = t11 * t50 * t71;
  t220 = t137 * t52 * t71;
  t221 = t3 * t51 * t71;
  t137 = t9 * t41 * t42;
  t222 = t137 * t50 * t71;
  t223 = t70 * t52 * t71;
  t224 = t4 * t51 * t71;
  t5 = t10 * t41 * t42;
  t225 = t5 * t50 * t71;
  t226 = t72 * t65 * t71;
  t227 = t74 * t63 * t71;
  t70 = t72 * t66 * t71;
  t229 = t74 * t64 * t71;
  t72 = t2 * t52 * t71;
  t231 = t11 * t51 * t71;
  t232 = t3 * t52 * t71;
  t233 = t137 * t51 * t71;
  t234 = t4 * t52 * t71;
  t235 = t5 * t51 * t71;
  t236 = t74 * t65 * t71;
  t237 = t74 * t66 * t71;
  t238 = t11 * t52 * t71;
  t239 = t137 * t52 * t71;
  t240 = t5 * t52 * t71;
  t273 = t21 + t75;
  t274 = t22 + t58;
  t275 = t23 + t60;
  t276 = t24 + t49;
  t277 = t25 + t195;
  t283 = t16 + t76;
  t284 = t16 + t59;
  t285 = t16 + t6;
  t286 = t17 + t7;
  t287 = t17 + t40;
  t288 = t17 + t219;
  t289 = t18 + t220;
  t290 = t18 + t221;
  t291 = t18 + t222;
  t301 = t94 * 3.0 + t22 * t45 * t71;
  t302 = t95 * 3.0 + t23 * t45 * t71;
  t303 = t96 * 3.0 + t24 * t45 * t71;
  t304 = t99 * 3.0 + t22 * t47 * t71;
  t305 = t100 * 3.0 + t23 * t47 * t71;
  t306 = t101 * 3.0 + t24 * t47 * t71;
  t307 = t93 + t93_tmp * t46 * t71;
  t308 = t94 + t335 * t46 * t71;
  t309 = t95 + t337 * t46 * t71;
  t310 = t96 + t339 * t46 * t71;
  t311 = t97 + t97_tmp * t46 * t71;
  t312 = t98 + t98_tmp * t44 * t71;
  t313 = t94 + t335 * t48 * t71;
  t314 = t99 + t341 * t44 * t71;
  t315 = t95 + t337 * t48 * t71;
  t316 = t100 + t343 * t44 * t71;
  t317 = t96 + t339 * t48 * t71;
  t318 = t101 + t345 * t44 * t71;
  t319 = t102 + t102_tmp * t44 * t71;
  t320 = t103 + t44 * t53 * t71;
  t321 = t99 + t341 * t48 * t71;
  t322 = t104 + t44 * t54 * t71;
  t323 = t100 + t343 * t48 * t71;
  t324 = t105 + t349 * t44 * t71;
  t325 = t101 + t345 * t48 * t71;
  t326 = t106 + t299 * t44 * t71;
  t327 = t107 + t296 * t44 * t71;
  t328 = t103 + t46 * t53 * t71;
  t329 = t104 + t46 * t54 * t71;
  t330 = t105 + t349 * t46 * t71;
  t331 = t106 + t299 * t46 * t71;
  t332 = t107 + t296 * t46 * t71;
  t351 = t121 + t44 * t62 * t71;
  t2 = t8 * t44;
  t352 = t122 + t2 * t50 * t71;
  t3 = t9 * t44;
  t353 = t123 + t3 * t50 * t71;
  t354 = t121 + t46 * t62 * t71;
  t5 = t8 * t46;
  t355 = t122 + t5 * t50 * t71;
  t137 = t9 * t46;
  t356 = t123 + t137 * t50 * t71;
  t357 = t121 + t48 * t62 * t71;
  t358 = t126 + t44 * t64 * t71;
  t11 = t8 * t48;
  t359 = t122 + t11 * t50 * t71;
  t360 = t127 + t2 * t51 * t71;
  t4 = t9 * t48;
  t361 = t123 + t4 * t50 * t71;
  t362 = t128 + t3 * t51 * t71;
  t363 = t126 + t46 * t64 * t71;
  t364 = t127 + t5 * t51 * t71;
  t365 = t128 + t137 * t51 * t71;
  t366 = t126 + t48 * t64 * t71;
  t367 = t131 + t44 * t66 * t71;
  t368 = t127 + t11 * t51 * t71;
  t369 = t132 + t2 * t52 * t71;
  t370 = t128 + t4 * t51 * t71;
  t371 = t133 + t3 * t52 * t71;
  t372 = t131 + t46 * t66 * t71;
  t373 = t132 + t5 * t52 * t71;
  t374 = t133 + t137 * t52 * t71;
  t375 = t131 + t48 * t66 * t71;
  t376 = t132 + t11 * t52 * t71;
  t128 = t133 + t4 * t52 * t71;
  t131 = t79 + t204;
  t9 = t84 + t197;
  t132 = t80 + t206;
  t133 = t85 + t198;
  t66 = t81 + t208;
  t383 = t86 + t199;
  t384 = t79 + t70;
  t127 = t89 + t203;
  t386 = t80 + t72;
  t387 = t90 + t205;
  t388 = t81 + t232;
  t389 = t91 + t207;
  t390 = t84 + t237;
  t391 = t89 + t229;
  t392 = t85 + t238;
  t393 = t90 + t231;
  t394 = t86 + t239;
  t395 = t91 + t233;
  t64 = t21 + -t75;
  t126 = t22 + -t58;
  t8 = t23 + -t60;
  t123 = t24 + -t49;
  t62 = t25 + -t195;
  t121 = t16 + -t76;
  t122 = t16 + -t59;
  t54 = t16 + -t6;
  t107 = t17 + -t7;
  t296 = t17 + -t40;
  t53 = t17 + -t219;
  t106 = t18 + -t220;
  t299 = t18 + -t221;
  t40 = t18 + -t222;
  t41 = t307 * in2[24];
  t42 = t308 * in2[24];
  t335 = t308 * in2[25];
  t94 = t309 * in2[24];
  t337 = t309 * in2[25];
  t95 = t312 * in2[21];
  t339 = t309 * in2[26];
  t96 = t310 * in2[25];
  t341 = t314 * in2[21];
  t99 = t310 * in2[26];
  t343 = t314 * in2[22];
  t100 = t316 * in2[21];
  t345 = t311 * in2[26];
  t101 = t316 * in2[22];
  t103 = t316 * in2[23];
  t104 = t318 * in2[22];
  t349 = t318 * in2[23];
  t105 = t319 * in2[23];
  t195 = t79 + -t204;
  t49 = t84 + -t197;
  t7 = t80 + -t206;
  t6 = t85 + -t198;
  t60 = t81 + -t208;
  t59 = t86 + -t199;
  t2 = t79 + -t70;
  t58 = t89 + -t203;
  t76 = t80 + -t72;
  t75 = t90 + -t205;
  t74 = t81 + -t232;
  t72 = t91 + -t207;
  t70 = t84 + -t237;
  t137 = t89 + -t229;
  t11 = t85 + -t238;
  t5 = t90 + -t231;
  t4 = t86 + -t239;
  t3 = t91 + -t233;
  memset(&out3[0], 0, 36U * sizeof(real_T));
  out3[36] = (((((((-t41 - t335) - t95) - t339) - t343) - t103) + t64 * in2[27])
              + t126 * in2[28]) + t8 * in2[29];
  out3[37] = (((((((t301 * in2[22] + t302 * in2[23]) + t312 * in2[24]) + t314 *
                  in2[25]) + t316 * in2[26]) + t320 * in2[27]) + t322 * in2[28])
              + t324 * in2[29]) + in2[21] * (t93 * 3.0 + t21 * t45 * t71);
  out3[38] = (t21 * in2[21] * -2.0 - t22 * in2[22] * 2.0) - t23 * in2[23] * 2.0;
  out3[39] = (((((((in2[24] * (t83 + t196) + in2[27] * (t88 + t201)) + t351 *
                   in2[22]) + t352 * in2[23]) + t9 * in2[25]) + t133 * in2[26])
               + t127 * in2[28]) + t387 * in2[29]) + in2[21] * (t120 + t44 * t61
    * t71);
  out3[40] = (((((((in2[27] * (t15 + t212) + t284 * in2[28]) + t287 * in2[29]) +
                  t358 * in2[22]) + t360 * in2[23]) - t195 * in2[25]) - t7 *
               in2[26]) + in2[21] * (t125 + t44 * t63 * t71)) - in2[24] * (t78 -
    t202);
  out3[41] = (((((((-t121 * in2[25] - t107 * in2[26]) + t367 * in2[22]) + t369 *
                  in2[23]) - t2 * in2[28]) - t76 * in2[29]) + in2[21] * (t130 +
    t44 * t65 * t71)) - in2[24] * (t15 - t211)) - in2[27] * (t78 - t226);
  out3[42] = (((((((-t42 - t337) - t341) - t99) - t101) - t349) + t126 * in2[27])
              + t8 * in2[28]) + t123 * in2[29];
  out3[43] = (((((((t301 * in2[21] + t302 * in2[22]) + t303 * in2[23]) + t314 *
                  in2[24]) + t316 * in2[25]) + t318 * in2[26]) + t322 * in2[27])
              + t324 * in2[28]) + t326 * in2[29];
  out3[44] = (t22 * in2[21] * -2.0 - t23 * in2[22] * 2.0) - t24 * in2[23] * 2.0;
  out3[45] = (((((((t351 * in2[21] + t352 * in2[22]) + t353 * in2[23]) + t9 *
                  in2[24]) + t133 * in2[25]) + t383 * in2[26]) + t127 * in2[27])
              + t387 * in2[28]) + t389 * in2[29];
  out3[46] = (((((((t284 * in2[27] + t287 * in2[28]) + t290 * in2[29]) + t358 *
                  in2[21]) + t360 * in2[22]) + t362 * in2[23]) - t195 * in2[24])
              - t7 * in2[25]) - t60 * in2[26];
  out3[47] = (((((((-t121 * in2[24] - t107 * in2[25]) - t106 * in2[26]) + t367 *
                  in2[21]) + t369 * in2[22]) + t371 * in2[23]) - t2 * in2[27]) -
              t76 * in2[28]) - t74 * in2[29];
  out3[48] = (((((((-t94 - t96) - t100) - t345) - t104) - t105) + t8 * in2[27])
              + t123 * in2[28]) + t62 * in2[29];
  out3[49] = (((((((t302 * in2[21] + t303 * in2[22]) + t316 * in2[24]) + t318 *
                  in2[25]) + t319 * in2[26]) + t324 * in2[27]) + t326 * in2[28])
              + t327 * in2[29]) + in2[23] * (t97 * 3.0 + t25 * t45 * t71);
  out3[50] = (t23 * in2[21] * -2.0 - t24 * in2[22] * 2.0) - t25 * in2[23] * 2.0;
  t2 = t10 * t44;
  out3[51] = (((((((in2[26] * (t87 + t200) + in2[29] * (t92 + t209)) + t352 *
                   in2[21]) + t353 * in2[22]) + t133 * in2[24]) + t383 * in2[25])
               + t387 * in2[27]) + t389 * in2[28]) + in2[23] * (t124 + t2 * t50 *
    t71);
  out3[52] = (((((((in2[29] * (t19 + t224) + t287 * in2[27]) + t290 * in2[28]) +
                  t360 * in2[21]) + t362 * in2[22]) - t7 * in2[24]) - t60 * in2
               [25]) - in2[26] * (t82 - t210)) + in2[23] * (t129 + t2 * t51 *
    t71);
  out3[53] = (((((((-t107 * in2[24] - t106 * in2[25]) + t369 * in2[21]) + t371 *
                  in2[22]) - t76 * in2[27]) - t74 * in2[28]) - in2[26] * (t19 -
    t223)) - in2[29] * (t82 - t234)) + in2[23] * (t134 + t2 * t52 * t71);
  out3[54] = (((((((-t307 * in2[21] - t304 * in2[25]) - t308 * in2[22]) - t305 *
                  in2[26]) - t309 * in2[23]) - t328 * in2[27]) - t329 * in2[28])
              - t330 * in2[29]) - in2[24] * (t98 * 3.0 + t21 * t47 * t71);
  out3[55] = (((((((t41 + t335) + t95) + t339) + t343) + t103) + t273 * in2[27])
              + t274 * in2[28]) + t275 * in2[29];
  out3[56] = (t21 * in2[24] * -2.0 - t22 * in2[25] * 2.0) - t23 * in2[26] * 2.0;
  out3[57] = (((((((-t54 * in2[28] - t53 * in2[29]) + t354 * in2[25]) + t355 *
                  in2[26]) - t49 * in2[22]) - t6 * in2[23]) + in2[24] * (t120 +
    t46 * t61 * t71)) - in2[27] * (t15 - t213)) - in2[21] * (t83 - t196);
  out3[58] = (((((((in2[21] * (t78 + t202) + in2[27] * (t88 + t227)) + t363 *
                   in2[25]) + t364 * in2[26]) + t131 * in2[22]) + t132 * in2[23])
               + t391 * in2[28]) + t393 * in2[29]) + in2[24] * (t125 + t46 * t63
    * t71);
  out3[59] = (((((((in2[21] * (t15 + t211) + t283 * in2[22]) + t286 * in2[23]) +
                  t372 * in2[25]) + t373 * in2[26]) - t70 * in2[28]) - t11 *
               in2[29]) + in2[24] * (t130 + t46 * t65 * t71)) - in2[27] * (t83 -
    t236);
  out3[60] = (((((((-t304 * in2[24] - t308 * in2[21]) - t305 * in2[25]) - t309 *
                  in2[22]) - t306 * in2[26]) - t310 * in2[23]) - t329 * in2[27])
              - t330 * in2[28]) - t331 * in2[29];
  out3[61] = (((((((t42 + t337) + t341) + t99) + t101) + t349) + t274 * in2[27])
              + t275 * in2[28]) + t276 * in2[29];
  out3[62] = (t22 * in2[24] * -2.0 - t23 * in2[25] * 2.0) - t24 * in2[26] * 2.0;
  out3[63] = (((((((-t54 * in2[27] - t53 * in2[28]) - t40 * in2[29]) + t354 *
                  in2[24]) + t355 * in2[25]) + t356 * in2[26]) - t49 * in2[21])
              - t6 * in2[22]) - t59 * in2[23];
  out3[64] = (((((((t363 * in2[24] + t364 * in2[25]) + t365 * in2[26]) + t131 *
                  in2[21]) + t132 * in2[22]) + t66 * in2[23]) + t391 * in2[27])
              + t393 * in2[28]) + t395 * in2[29];
  out3[65] = (((((((t283 * in2[21] + t286 * in2[22]) + t289 * in2[23]) + t372 *
                  in2[24]) + t373 * in2[25]) + t374 * in2[26]) - t70 * in2[27])
              - t11 * in2[28]) - t4 * in2[29];
  out3[66] = (((((((-t305 * in2[24] - t309 * in2[21]) - t306 * in2[25]) - t310 *
                  in2[22]) - t311 * in2[23]) - t330 * in2[27]) - t331 * in2[28])
              - t332 * in2[29]) - in2[26] * (t102 * 3.0 + t25 * t47 * t71);
  out3[67] = (((((((t94 + t96) + t100) + t345) + t104) + t105) + t275 * in2[27])
              + t276 * in2[28]) + t277 * in2[29];
  out3[68] = (t23 * in2[24] * -2.0 - t24 * in2[25] * 2.0) - t25 * in2[26] * 2.0;
  t2 = t10 * t46;
  out3[69] = (((((((-t53 * in2[27] - t40 * in2[28]) + t355 * in2[24]) + t356 *
                  in2[25]) - t6 * in2[21]) - t59 * in2[22]) - in2[29] * (t19 -
    t225)) - in2[23] * (t87 - t200)) + in2[26] * (t124 + t2 * t50 * t71);
  out3[70] = (((((((in2[23] * (t82 + t210) + in2[29] * (t92 + t235)) + t364 *
                   in2[24]) + t365 * in2[25]) + t132 * in2[21]) + t66 * in2[22])
               + t393 * in2[27]) + t395 * in2[28]) + in2[26] * (t129 + t2 * t51 *
    t71);
  out3[71] = (((((((in2[23] * (t19 + t223) + t286 * in2[21]) + t289 * in2[22]) +
                  t373 * in2[24]) + t374 * in2[25]) - t11 * in2[27]) - t4 * in2
               [28]) - in2[29] * (t87 - t240)) + in2[26] * (t134 + t2 * t52 *
    t71);
  out3[72] = (((((((t64 * in2[21] + t126 * in2[22]) + t8 * in2[23]) - t321 *
                  in2[28]) - t323 * in2[29]) - t328 * in2[24]) - t329 * in2[25])
              - t330 * in2[26]) - in2[27] * (t98 + t98_tmp * t48 * t71);
  out3[73] = (((((((t273 * in2[24] + t274 * in2[25]) + t275 * in2[26]) + t313 *
                  in2[28]) + t320 * in2[21]) + t315 * in2[29]) + t322 * in2[22])
              + t324 * in2[23]) + in2[27] * (t93 + t93_tmp * t48 * t71);
  out3[74] = 0.0;
  out3[75] = (((((((in2[24] * (t15 + t213) + t285 * in2[25]) + t288 * in2[26]) +
                  t357 * in2[28]) + t359 * in2[29]) - t58 * in2[22]) - t75 *
               in2[23]) + in2[27] * (t120 + t48 * t61 * t71)) - in2[21] * (t88 -
    t201);
  out3[76] = (((((((-t122 * in2[22] - t296 * in2[23]) + t366 * in2[28]) + t368 *
                  in2[29]) - t137 * in2[25]) - t5 * in2[26]) + in2[27] * (t125 +
    t48 * t63 * t71)) - in2[21] * (t15 - t212)) - in2[24] * (t88 - t227);
  out3[77] = (((((((in2[21] * (t78 + t226) + in2[24] * (t83 + t236)) + t375 *
                   in2[28]) + t376 * in2[29]) + t384 * in2[22]) + t386 * in2[23])
               + t390 * in2[25]) + t392 * in2[26]) + in2[27] * (t130 + t48 * t65
    * t71);
  out3[78] = (((((((t126 * in2[21] + t8 * in2[22]) + t123 * in2[23]) - t321 *
                  in2[27]) - t323 * in2[28]) - t329 * in2[24]) - t325 * in2[29])
              - t330 * in2[25]) - t331 * in2[26];
  out3[79] = (((((((t274 * in2[24] + t275 * in2[25]) + t276 * in2[26]) + t313 *
                  in2[27]) + t315 * in2[28]) + t322 * in2[21]) + t317 * in2[29])
              + t324 * in2[22]) + t326 * in2[23];
  out3[80] = 0.0;
  out3[81] = (((((((t285 * in2[24] + t288 * in2[25]) + t291 * in2[26]) + t357 *
                  in2[27]) + t359 * in2[28]) + t361 * in2[29]) - t58 * in2[21])
              - t75 * in2[22]) - t72 * in2[23];
  out3[82] = (((((((-t122 * in2[21] - t296 * in2[22]) - t299 * in2[23]) + t366 *
                  in2[27]) + t368 * in2[28]) + t370 * in2[29]) - t137 * in2[24])
              - t5 * in2[25]) - t3 * in2[26];
  out3[83] = (((((((t375 * in2[27] + t376 * in2[28]) + t384 * in2[21]) + t128 *
                  in2[29]) + t386 * in2[22]) + t388 * in2[23]) + t390 * in2[24])
              + t392 * in2[25]) + t394 * in2[26];
  out3[84] = (((((((t8 * in2[21] + t123 * in2[22]) + t62 * in2[23]) - t323 *
                  in2[27]) - t325 * in2[28]) - t330 * in2[24]) - t331 * in2[25])
              - t332 * in2[26]) - in2[29] * (t102 + t102_tmp * t48 * t71);
  out3[85] = (((((((t275 * in2[24] + t276 * in2[25]) + t277 * in2[26]) + t315 *
                  in2[27]) + t317 * in2[28]) + t324 * in2[21]) + t326 * in2[22])
              + t327 * in2[23]) + in2[29] * (t97 + t97_tmp * t48 * t71);
  out3[86] = 0.0;
  t2 = t10 * t48;
  out3[87] = (((((((in2[26] * (t19 + t225) + t288 * in2[24]) + t291 * in2[25]) +
                  t359 * in2[27]) + t361 * in2[28]) - t75 * in2[21]) - t72 *
               in2[22]) - in2[23] * (t92 - t209)) + in2[29] * (t124 + t2 * t50 *
    t71);
  out3[88] = (((((((-t296 * in2[21] - t299 * in2[22]) + t368 * in2[27]) + t370 *
                  in2[28]) - t5 * in2[24]) - t3 * in2[25]) - in2[23] * (t19 -
    t224)) - in2[26] * (t92 - t235)) + in2[29] * (t129 + t2 * t51 * t71);
  out3[89] = (((((((in2[23] * (t82 + t234) + in2[26] * (t87 + t240)) + t376 *
                   in2[27]) + t128 * in2[28]) + t386 * in2[21]) + t388 * in2[22])
               + t392 * in2[24]) + t394 * in2[25]) + in2[29] * (t134 + t2 * t52 *
    t71);
  out4[0] = in1[12];
  out4[1] = in1[13];
  out4[2] = in1[14];
  out4[3] = 0.0;
  out4[4] = 0.0;
  out4[5] = 0.0;
}

/* End of code generation (massF2.c) */
