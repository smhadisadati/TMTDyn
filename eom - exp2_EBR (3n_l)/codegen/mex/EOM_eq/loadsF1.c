/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * loadsF1.c
 *
 * Code generation for function 'loadsF1'
 *
 */

/* Include files */
#include "loadsF1.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void loadsF1(const real_T in1[34], const real_T in2[36], real_T out1[108],
             real_T out2[6])
{
  real_T t10;
  real_T t100;
  real_T t101;
  real_T t102;
  real_T t104;
  real_T t105;
  real_T t106;
  real_T t11;
  real_T t116;
  real_T t117;
  real_T t12;
  real_T t133;
  real_T t138;
  real_T t139;
  real_T t149;
  real_T t150;
  real_T t151;
  real_T t154;
  real_T t155;
  real_T t156;
  real_T t157;
  real_T t158;
  real_T t159;
  real_T t16;
  real_T t160;
  real_T t161;
  real_T t162;
  real_T t163;
  real_T t164;
  real_T t165;
  real_T t166;
  real_T t167;
  real_T t168;
  real_T t169;
  real_T t170;
  real_T t171;
  real_T t175;
  real_T t176;
  real_T t177;
  real_T t178;
  real_T t179;
  real_T t18;
  real_T t180;
  real_T t181;
  real_T t182;
  real_T t19;
  real_T t198;
  real_T t199;
  real_T t20;
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
  real_T t214;
  real_T t215;
  real_T t216;
  real_T t217;
  real_T t221;
  real_T t222;
  real_T t23;
  real_T t235;
  real_T t236;
  real_T t237;
  real_T t238;
  real_T t239;
  real_T t24;
  real_T t240;
  real_T t25;
  real_T t250;
  real_T t251;
  real_T t252;
  real_T t253;
  real_T t257;
  real_T t26;
  real_T t263;
  real_T t264;
  real_T t265;
  real_T t268;
  real_T t269;
  real_T t27;
  real_T t270;
  real_T t271;
  real_T t272;
  real_T t273;
  real_T t275;
  real_T t276;
  real_T t278;
  real_T t279;
  real_T t280;
  real_T t281;
  real_T t282;
  real_T t283;
  real_T t284;
  real_T t286;
  real_T t288;
  real_T t289;
  real_T t29;
  real_T t290;
  real_T t291;
  real_T t292;
  real_T t293;
  real_T t294;
  real_T t296;
  real_T t297;
  real_T t298;
  real_T t301;
  real_T t302;
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
  real_T t345;
  real_T t346;
  real_T t347;
  real_T t349;
  real_T t350;
  real_T t351;
  real_T t353;
  real_T t357;
  real_T t361;
  real_T t362;
  real_T t363;
  real_T t364;
  real_T t365;
  real_T t366;
  real_T t367;
  real_T t371;
  real_T t372;
  real_T t373;
  real_T t374;
  real_T t375;
  real_T t376;
  real_T t378;
  real_T t379;
  real_T t380;
  real_T t381;
  real_T t382;
  real_T t383;
  real_T t384;
  real_T t385;
  real_T t388;
  real_T t389;
  real_T t391;
  real_T t392;
  real_T t394;
  real_T t395;
  real_T t396;
  real_T t397;
  real_T t398;
  real_T t399;
  real_T t401;
  real_T t402;
  real_T t404;
  real_T t405;
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
  real_T t427;
  real_T t428;
  real_T t430;
  real_T t431;
  real_T t433;
  real_T t434;
  real_T t435;
  real_T t436;
  real_T t438;
  real_T t439;
  real_T t441;
  real_T t442;
  real_T t444;
  real_T t446;
  real_T t447;
  real_T t448;
  real_T t449;
  real_T t450;
  real_T t455;
  real_T t457;
  real_T t461;
  real_T t462;
  real_T t5;
  real_T t50;
  real_T t54;
  real_T t56;
  real_T t57;
  real_T t58;
  real_T t6;
  real_T t7;
  real_T t73;
  real_T t74;
  real_T t75;
  real_T t8;
  real_T t84;
  real_T t9;
  real_T t96;
  real_T t98;
  real_T t99;

  /* LOADSF1 */
  /*     [OUT1,OUT2,OUT3] = LOADSF1(IN1,IN2,S,DS,T_SYM) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
  /*     14-Jun-2021 16:41:53 */
  t5 = in1[4] / 3.0;
  t6 = in1[4] / 6.0;
  t7 = in2[3] / 2.0;
  t8 = in2[4] / 2.0;
  t9 = in2[3] / 4.0;
  t10 = in2[5] / 2.0;
  t11 = in2[4] / 4.0;
  t12 = in2[5] / 4.0;
  t16 = in2[9] / 4.0;
  t18 = in2[10] / 4.0;
  t19 = in2[12] / 2.0;
  t20 = in2[11] / 4.0;
  t21 = in2[13] / 2.0;
  t23 = in2[15] / 4.0;
  t24 = in2[16] / 4.0;
  t25 = in2[17] / 4.0;
  t84 = in2[3] * in2[13] * -0.25;
  t96 = in2[3] * in2[15] / 8.0;
  t98 = in2[3] * in2[16] / 8.0;
  t99 = in2[4] * in2[15] / 8.0;
  t100 = in2[3] * in2[17] / 8.0;
  t101 = in2[4] * in2[16] / 8.0;
  t102 = in2[5] * in2[15] / 8.0;
  t104 = in2[4] * in2[17] / 8.0;
  t105 = in2[5] * in2[16] / 8.0;
  t106 = in2[5] * in2[17] / 8.0;
  t26 = in2[4] * t7;
  t27 = in2[5] * t7;
  t29 = in2[5] * t8;
  t50 = in2[12] * t9;
  t54 = in2[12] * t11;
  t56 = in2[13] * t11;
  t57 = in2[12] * t12;
  t58 = in2[13] * t12;
  t73 = in2[3] * in2[3] / 4.0;
  t74 = in2[4] * in2[4] / 4.0;
  t75 = in2[5] * in2[5] / 4.0;
  t116 = in2[8] + t5;
  t117 = in2[14] + t5;
  t133 = t6 + in2[8] / 2.0;
  t5 = t6 + in2[14] / 2.0;
  t165 = (t5 + t84) + in2[4] * in2[12] * -0.25;
  t175 = ((in2[3] * in2[9] / 8.0 + in2[4] * in2[10] / 8.0) + in2[5] * in2[11] /
          8.0) - 0.5;
  t179 = ((in2[9] * in2[15] / 8.0 + in2[10] * in2[16] / 8.0) + in2[11] * in2[17]
          / 8.0) - 0.5;
  t6 = t9 * t117;
  t138 = t11 * t117;
  t139 = t12 * t117;
  t149 = ((in2[9] * t9 + in2[10] * t11) + in2[11] * t12) - 1.0;
  t150 = (t5 + in2[13] * t9) + t54;
  t157 = (t5 + t54) + t84;
  t158 = (t5 + in2[13] * t16) + in2[10] * in2[12] * -0.25;
  t462 = in2[5] * in2[10];
  t159 = ((t7 + in2[9] / 2.0) + in2[11] * t11) + t462 * -0.25;
  t455 = in2[3] * in2[11];
  t160 = ((t8 + in2[10] / 2.0) + in2[9] * t12) + t455 * -0.25;
  t457 = in2[4] * in2[9];
  t161 = ((t10 + in2[11] / 2.0) + in2[10] * t9) + t457 * -0.25;
  t176 = ((t101 + t106) + -t96) + 0.5;
  t177 = ((t96 + t106) + -t101) + 0.5;
  t178 = ((t96 + t101) + -t106) + 0.5;
  t198 = ((t9 + t16) + in2[4] * in2[11] / 8.0) + -(t462 / 8.0);
  t199 = ((t11 + t18) + in2[5] * in2[9] / 8.0) + -(t455 / 8.0);
  t200 = ((t12 + t20) + in2[3] * in2[10] / 8.0) + -(t457 / 8.0);
  t201 = ((t23 + -t9) + t104) + t105;
  t202 = ((t9 + -t23) + t104) + t105;
  t203 = ((t9 + t23) + t105) + -t104;
  t204 = ((t24 + -t11) + t100) + t102;
  t205 = ((t11 + -t24) + t100) + t102;
  t206 = ((t11 + t24) + t100) + -t102;
  t207 = ((t25 + -t12) + t98) + t99;
  t208 = ((t12 + -t25) + t98) + t99;
  t209 = ((t12 + t25) + t99) + -t98;
  t210 = ((t16 + t23) + in2[10] * in2[17] / 8.0) + -(in2[11] * in2[16] / 8.0);
  t211 = ((t18 + t24) + in2[11] * in2[15] / 8.0) + -(in2[9] * in2[17] / 8.0);
  t212 = ((t20 + t25) + in2[9] * in2[16] / 8.0) + -(in2[10] * in2[15] / 8.0);
  t151 = t149 * t149;
  t98 = in2[12] * t149;
  t99 = in2[13] * t149;
  t154 = in2[15] * t149;
  t155 = in2[16] * t149;
  t156 = in2[17] * t149;
  t162 = (t21 + t57) + t6;
  t5 = t19 + t58;
  t163 = t5 + t138;
  t164 = (in2[12] * t16 + in2[13] * t18) + t20 * t117;
  t166 = (t57 + -t21) + t6;
  t167 = (t21 + in2[5] * in2[12] * -0.25) + t6;
  t168 = (t58 + -t19) + t138;
  t169 = t5 + in2[4] * t117 * -0.25;
  t170 = (t21 + in2[12] * t20) + in2[9] * t117 * -0.25;
  t171 = (t19 + in2[11] * in2[13] * -0.25) + t18 * t117;
  t180 = (t56 + in2[3] * in2[12] * -0.25) + t139;
  t181 = (t50 + in2[4] * in2[13] * -0.25) + t139;
  t182 = (t50 + t56) + in2[5] * t117 * -0.25;
  t84 = in2[12] * t160;
  t104 = in2[12] * t161;
  t54 = in2[13] * t159;
  t106 = in2[13] * t161;
  t105 = in2[15] * t159;
  t138 = in2[15] * t160;
  t25 = in2[15] * t161;
  t58 = in2[16] * t159;
  t100 = in2[16] * t160;
  t23 = in2[16] * t161;
  t57 = in2[17] * t159;
  t24 = in2[17] * t160;
  t102 = in2[17] * t161;
  t213 = t159 * t159;
  t214 = t160 * t160;
  t215 = t161 * t161;
  t216 = t19 * t149;
  t217 = t21 * t149;
  t96 = t117 * t149;
  t235 = t19 * t159;
  t236 = t19 * t160;
  t237 = t19 * t161;
  t238 = t21 * t159;
  t239 = t21 * t160;
  t240 = t21 * t161;
  t101 = t117 * t159;
  t6 = t117 * t160;
  t5 = t117 * t161;
  t268 = t149 * t158;
  t269 = t149 * t159 * 2.0;
  t270 = t149 * t160 * 2.0;
  t271 = t149 * t161 * 2.0;
  t275 = t158 * t159;
  t276 = t158 * t160;
  t281 = t159 * t160 * 2.0;
  t282 = t159 * t161 * 2.0;
  t283 = t160 * t161 * 2.0;
  t221 = t98 * -0.5;
  t222 = t99 * -0.5;
  t250 = t84 * -0.5;
  t251 = t104 * -0.5;
  t252 = t54 * -0.5;
  t253 = t106 * -0.5;
  t257 = t96 / 2.0;
  t263 = t101 / 2.0;
  t264 = t6 / 2.0;
  t265 = t5 / 2.0;
  t272 = t149 * t170;
  t273 = t149 * t171;
  t278 = t159 * t164;
  t279 = t160 * t164;
  t280 = t161 * t164;
  t284 = t159 * t170;
  t286 = t161 * t170;
  t288 = t160 * t171;
  t289 = t161 * t171;
  t293 = (in2[12] * t159 + in2[13] * t160) + t5;
  t324 = (((((in2[9] * t7 + in2[10] * t8) + in2[11] * t10) + t105) + t100) +
          t102) - 2.0;
  t290 = (t84 + -t54) + t96;
  t291 = (t98 + t106) + -t6;
  t292 = (t99 + -t104) + t101;
  t321 = (((((in2[3] + in2[9]) + in2[11] * t8) + t462 * -0.5) + -t154) + t24) +
    -t23;
  t322 = (((((in2[4] + in2[10]) + in2[9] * t10) + t455 * -0.5) + -t155) + t25) +
    -t57;
  t323 = (((((in2[5] + in2[11]) + in2[10] * t7) + t457 * -0.5) + -t156) + t58) +
    -t138;
  t325 = ((t149 + t105 / 2.0) + t100 / 2.0) + t102 / 2.0;
  t371 = t198 * t324;
  t372 = t199 * t324;
  t373 = t200 * t324;
  t374 = t210 * t324;
  t375 = t211 * t324;
  t376 = t212 * t324;
  t378 = t179 * t324;
  t294 = t9 * t290;
  t296 = t9 * t292;
  t297 = t11 * t290;
  t298 = t11 * t291;
  t301 = t12 * t291;
  t302 = t12 * t292;
  t318 = in2[3] * t291 * -0.25;
  t319 = in2[4] * t292 * -0.25;
  t320 = in2[5] * t290 * -0.25;
  t326 = ((t159 + -(t154 / 2.0)) + t24 / 2.0) + -(t23 / 2.0);
  t327 = ((t160 + -(t155 / 2.0)) + t25 / 2.0) + -(t57 / 2.0);
  t328 = ((t161 + -(t156 / 2.0)) + t58 / 2.0) + -(t138 / 2.0);
  t345 = t198 * t322;
  t346 = t198 * t323;
  t347 = t199 * t321;
  t349 = t199 * t323;
  t350 = t200 * t321;
  t351 = t200 * t322;
  t353 = t210 * t321;
  t357 = t211 * t322;
  t361 = t212 * t323;
  t362 = t175 * t321;
  t363 = t175 * t322;
  t364 = t175 * t323;
  t365 = t179 * t321;
  t366 = t179 * t322;
  t367 = t179 * t323;
  t84 = in1[16] * t175;
  t379 = t84 * t325 * 2.0;
  t99 = in1[16] * t179;
  t380 = t99 * t325 * 2.0;
  t5 = in1[16] * t198;
  t381 = t5 * t325 * 2.0;
  t54 = in1[16] * t199;
  t382 = t54 * t325 * 2.0;
  t96 = in1[16] * t200;
  t383 = t96 * t325 * 2.0;
  t23 = in1[16] * t210;
  t384 = t23 * t325 * 2.0;
  t24 = in1[16] * t211;
  t385 = t24 * t325 * 2.0;
  t101 = in1[4] * t175;
  t394 = t101 * t325 * 0.66666666666666663;
  t100 = in1[4] * t179;
  t395 = t100 * t325 * 0.66666666666666663;
  t6 = in1[4] * t198;
  t414 = t6 * t325 * 0.66666666666666663;
  t106 = in1[4] * t199;
  t415 = t106 * t325 * 0.66666666666666663;
  t104 = in1[4] * t200;
  t416 = t104 * t325 * 0.66666666666666663;
  t102 = in1[4] * t210;
  t417 = t102 * t325 * 0.66666666666666663;
  t98 = in1[4] * t211;
  t418 = t98 * t325 * 0.66666666666666663;
  t388 = t84 * t326 * 2.0;
  t389 = t84 * t327 * 2.0;
  t391 = t99 * t326 * 2.0;
  t392 = t99 * t327 * 2.0;
  t396 = t5 * t326 * 2.0;
  t397 = t5 * t327 * 2.0;
  t398 = t5 * t328 * 2.0;
  t399 = t54 * t326 * 2.0;
  t401 = t54 * t328 * 2.0;
  t402 = t96 * t326 * 2.0;
  t404 = t96 * t328 * 2.0;
  t405 = t23 * t326 * 2.0;
  t407 = t23 * t328 * 2.0;
  t409 = t24 * t327 * 2.0;
  t410 = t24 * t328 * 2.0;
  t105 = in1[16] * t212;
  t411 = t105 * t326 * 2.0;
  t412 = t105 * t327 * 2.0;
  t413 = t105 * t328 * 2.0;
  t427 = t101 * t326 * 0.66666666666666663;
  t428 = t101 * t327 * 0.66666666666666663;
  t430 = t100 * t326 * 0.66666666666666663;
  t431 = t100 * t327 * 0.66666666666666663;
  t433 = t6 * t326 * 0.66666666666666663;
  t434 = t6 * t327 * 0.66666666666666663;
  t435 = t6 * t328 * 0.66666666666666663;
  t436 = t106 * t326 * 0.66666666666666663;
  t438 = t106 * t328 * 0.66666666666666663;
  t439 = t104 * t326 * 0.66666666666666663;
  t441 = t104 * t328 * 0.66666666666666663;
  t442 = t102 * t326 * 0.66666666666666663;
  t444 = t102 * t328 * 0.66666666666666663;
  t446 = t98 * t327 * 0.66666666666666663;
  t447 = t98 * t328 * 0.66666666666666663;
  t5 = in1[4] * t212;
  t448 = t5 * t326 * 0.66666666666666663;
  t449 = t5 * t327 * 0.66666666666666663;
  t450 = t5 * t328 * 0.66666666666666663;
  t461 = ((t198 * t321 + t199 * t322) + t200 * t323) + t175 * t324;
  t175 = -(t84 * t328 * 2.0);
  t200 = -(t54 * t327 * 2.0);
  t199 = -(t96 * t327 * 2.0);
  t198 = -(t101 * t328 * 0.66666666666666663);
  t179 = -(t106 * t327 * 0.66666666666666663);
  t455 = -(t104 * t327 * 0.66666666666666663);
  t457 = (t326 * in1[30] + t327 * in1[31]) + t328 * in1[32];
  t154 = (t325 * in1[31] + t328 * in1[30]) + -(t326 * in1[32]);
  t155 = (t325 * in1[30] + t327 * in1[32]) + -(t328 * in1[31]);
  t156 = (t325 * in1[32] + t326 * in1[31]) + -(t327 * in1[30]);
  t462 = ((((((((((((((((((((in2[6] * t7 + in2[7] * t8) + t12 * t116) + t10 *
    t133) + t235) + t239) + t265) + t149 * t164) + t158 * t161) + t160 * t170) +
                    t159 * t171) + t16 * t291) + t18 * t292) + t20 * t290) +
                t105 * t325 * 2.0) + t24 * t326 * 2.0) + t5 * t325 *
              0.66666666666666663) + -(t99 * t328 * 2.0)) + -(t23 * t327 * 2.0))
           + t98 * t326 * 0.66666666666666663) + -(t100 * t328 *
           0.66666666666666663)) + -(t102 * t327 * 0.66666666666666663);
  out1[0] = 1.0;
  out1[1] = 0.0;
  out1[2] = 0.0;
  out1[3] = t462;
  out1[4] = (((((((((((((((((((in2[7] * t7 + t116) + t238) + t250) + -t257) -
    t268) + t280) + t284) - t288) + t18 * t291) + t20 * t293) + t380) + t395) -
                   t405) - t409) + t413) - t442) - t446) + t450) - in2[4] * in2
             [6] / 2.0) - in2[9] * t292 / 4.0;
  out1[5] = ((((((((((((((((((((-in2[7] + t9 * t116) + t7 * t133) + t217) + t251)
    + t263) + t272) + t275) - t279) - t289) + t20 * t291) - t384) - t391) - t410)
                   - t412) - t417) - t430) - t447) - t449) - in2[5] * in2[6] /
              2.0) - in2[9] * t290 / 4.0) - in2[10] * t293 / 4.0;
  out1[6] = ((t73 + -t74) + -t75) + 1.0;
  out1[7] = -in2[5] + t26;
  out1[8] = in2[4] + t27;
  t138 = in1[16] * t176;
  t58 = in1[16] * t203;
  t139 = in1[16] * t205;
  t50 = in1[16] * t207;
  t56 = in1[4] * t176;
  t19 = in1[4] * t203;
  t21 = in1[4] * t205;
  t117 = in1[4] * t207;
  t105 = (t235 + t239) + t265;
  out1[9] = ((((((((((((((t105 + t9 * t291) + t319) + t320) + t150 * t161) -
                      t160 * t166) + t159 * t169) - t149 * t180) + t138 * t328 *
                   2.0) - t58 * t327 * 2.0) - t139 * t326 * 2.0) + t50 * t325 *
                2.0) + t56 * t328 * 0.66666666666666663) - t19 * t327 *
              0.66666666666666663) - t21 * t326 * 0.66666666666666663) + t117 *
    t325 * 0.66666666666666663;
  t100 = in1[16] * t177;
  t102 = in1[16] * t201;
  t98 = in1[16] * t206;
  t99 = in1[16] * t208;
  t23 = in1[4] * t177;
  t24 = in1[4] * t201;
  t25 = in1[4] * t206;
  t57 = in1[4] * t208;
  out1[10] = ((((((((((((((((t238 + t250) + -t257) + t296) + t298) - in2[5] *
    t293 / 4.0) - t149 * t165) - t160 * t163) + t159 * t167) - t161 * t181) -
                    t100 * t325 * 2.0) - t102 * t326 * 2.0) - t98 * t327 * 2.0)
                 - t99 * t328 * 2.0) - t23 * t325 * 0.66666666666666663) - t24 *
               t326 * 0.66666666666666663) - t25 * t327 * 0.66666666666666663) -
    t57 * t328 * 0.66666666666666663;
  t5 = in1[16] * t178;
  t6 = in1[16] * t204;
  t84 = in1[16] * t202;
  t54 = in1[16] * t209;
  t96 = in1[4] * t178;
  t101 = in1[4] * t204;
  t106 = in1[4] * t202;
  t104 = in1[4] * t209;
  out1[11] = ((((((((((((((((t217 + t251) + t263) + t294) + t301) + t11 * t293)
                        + t149 * t162) + t157 * t159) + t161 * t168) + t160 *
                     t182) + t5 * t326 * 2.0) + t84 * t325 * 2.0) - t6 * t328 *
                  2.0) - t54 * t327 * 2.0) + t96 * t326 * 0.66666666666666663) +
               t106 * t325 * 0.66666666666666663) - t101 * t328 *
              0.66666666666666663) - t104 * t327 * 0.66666666666666663;
  out1[12] = ((t151 + t213) + -t214) + -t215;
  out1[13] = t271 + t281;
  out1[14] = -t270 + t282;
  out1[15] = ((((((-t383 - t397) + t175) + -t399) + -t416) - t434) + t198) +
    -t436;
  out1[16] = ((((((t379 + t394) + t396) - t404) + t200) + t433) - t441) + t179;
  out1[17] = ((((((t381 - t388) + t401) + t414) + t199) - t427) + t438) + t455;
  out1[18] = 0.0;
  out1[19] = 1.0;
  out1[20] = 0.0;
  out1[21] = (((((((((((((((((((in2[6] * t8 - t116) + t236) + t252) + t257) +
    t268) - t280) - t284) + t288) + t16 * t292) - t380) - t395) + t405) + t409)
                   - t413) + t442) + t446) - t450) - in2[3] * in2[7] / 2.0) -
              in2[10] * t291 / 4.0) - in2[11] * t293 / 4.0;
  out1[22] = t462;
  out1[23] = ((((((((((((((((((((in2[6] + t11 * t116) + t8 * t133) + t221) +
    t253) + t264) - t273) + t276) + t278) - t286) + t20 * t292) + t16 * t293) -
                      t385) - t392) + t407) + t411) - t418) - t431) + t444) +
               t448) - in2[5] * in2[7] / 2.0) - in2[10] * t290 / 4.0;
  out1[24] = in2[5] + t26;
  out1[25] = ((t74 + -t73) + -t75) + 1.0;
  out1[26] = -in2[3] + t29;
  out1[27] = ((((((((((((((((t236 + t252) + t257) + t296) + t298) + t12 * t293)
                        + t149 * t150) + t159 * t166) + t160 * t169) + t161 *
                     t180) + t138 * t325 * 2.0) + t58 * t326 * 2.0) - t139 *
                  t327 * 2.0) - t50 * t328 * 2.0) + t56 * t325 *
                0.66666666666666663) + t19 * t326 * 0.66666666666666663) - t21 *
              t327 * 0.66666666666666663) - t117 * t328 * 0.66666666666666663;
  out1[28] = ((((((((((((((t105 + t11 * t292) + t318) + t320) + t159 * t163) +
                       t161 * t165) + t160 * t167) - t149 * t181) + t100 * t328 *
                    2.0) - t102 * t327 * 2.0) + t98 * t326 * 2.0) - t99 * t325 *
                 2.0) + t23 * t328 * 0.66666666666666663) - t24 * t327 *
               0.66666666666666663) + t25 * t326 * 0.66666666666666663) - t57 *
    t325 * 0.66666666666666663;
  out1[29] = ((((((((((((((((t221 + t253) + t264) + t297) + t302) - in2[3] *
    t293 / 4.0) + t149 * t168) + t157 * t160) - t161 * t162) - t159 * t182) + t5
                    * t327 * 2.0) - t6 * t325 * 2.0) - t84 * t328 * 2.0) + t54 *
                 t326 * 2.0) + t96 * t327 * 0.66666666666666663) - t101 * t325 *
               0.66666666666666663) - t106 * t328 * 0.66666666666666663) + t104 *
    t326 * 0.66666666666666663;
  out1[30] = -t271 + t281;
  out1[31] = ((t151 + t214) + -t213) + -t215;
  out1[32] = t269 + t283;
  out1[33] = ((((((-t379 - t394) + t396) + t404) + t200) + t433) + t441) + t179;
  out1[34] = ((((((-t383 + t397) + t399) + t175) + -t416) + t434) + t436) + t198;
  out1[35] = ((((((t382 - t389) - t398) + t402) + t415) - t428) - t435) + t439;
  out1[36] = 0.0;
  out1[37] = 0.0;
  out1[38] = 1.0;
  out1[39] = ((((((((((((((((((((in2[7] + in2[6] * t10) + t222) + t237) + -t263)
    - t272) - t275) + t279) + t289) + t16 * t290) + t18 * t293) + t384) + t391)
                     + t410) + t412) + t417) + t430) + t447) + t449) - in2[3] *
               t116 / 4.0) - in2[3] * t133 / 2.0) - in2[11] * t291 / 4.0;
  out1[40] = ((((((((((((((((((((-in2[6] + in2[7] * t10) + t216) + t240) + -t264)
    + t273) - t276) - t278) + t286) + t18 * t290) + t385) + t392) - t407) - t411)
                    + t418) + t431) - t444) - t448) - in2[4] * t116 / 4.0) -
               in2[4] * t133 / 2.0) - in2[9] * t293 / 4.0) - in2[11] * t292 /
    4.0;
  out1[41] = t462;
  out1[42] = -in2[4] + t27;
  out1[43] = in2[3] + t29;
  out1[44] = ((t75 + -t73) + -t74) + 1.0;
  out1[45] = ((((((((((((((((t222 + t237) + -t263) + t294) + t301) - in2[4] *
    t293 / 4.0) - t150 * t159) + t149 * t166) + t161 * t169) - t160 * t180) -
                    t138 * t326 * 2.0) + t58 * t325 * 2.0) - t139 * t328 * 2.0)
                 + t50 * t327 * 2.0) - t56 * t326 * 0.66666666666666663) + t19 *
               t325 * 0.66666666666666663) - t21 * t328 * 0.66666666666666663) +
    t117 * t327 * 0.66666666666666663;
  out1[46] = ((((((((((((((((t216 + t240) + -t264) + t297) + t302) + t9 * t293)
                        + t149 * t163) - t160 * t165) + t161 * t167) + t159 *
                     t181) - t100 * t327 * 2.0) - t102 * t328 * 2.0) + t98 *
                  t325 * 2.0) + t99 * t326 * 2.0) - t23 * t327 *
                0.66666666666666663) - t24 * t328 * 0.66666666666666663) + t25 *
              t325 * 0.66666666666666663) + t57 * t326 * 0.66666666666666663;
  out1[47] = ((((((((((((((t105 + t12 * t290) + t318) + t319) + t157 * t161) +
                       t160 * t162) - t159 * t168) - t149 * t182) + t5 * t328 *
                    2.0) + t84 * t327 * 2.0) + t6 * t326 * 2.0) + t54 * t325 *
                 2.0) + t96 * t328 * 0.66666666666666663) + t106 * t327 *
               0.66666666666666663) + t101 * t326 * 0.66666666666666663) + t104 *
    t325 * 0.66666666666666663;
  out1[48] = t270 + t282;
  out1[49] = -t269 + t283;
  out1[50] = ((t151 + t215) + -t213) + -t214;
  out1[51] = ((((((t381 + t388) - t401) + t414) + t199) + t427) - t438) + t455;
  out1[52] = ((((((t382 + t389) + t398) + t402) + t415) + t428) + t435) + t439;
  out1[53] = ((((((t383 + t397) + t416) + t175) + -t399) + t434) + t198) + -t436;
  out1[54] = 0.0;
  out1[55] = 0.0;
  out1[56] = 0.0;
  out1[57] = ((t353 + -t357) + -t361) + t378;
  t138 = t210 * t322 + t211 * t321;
  out1[58] = (t138 - t367) - t376;
  t58 = t210 * t323 + t212 * t321;
  out1[59] = (t58 + t366) + t375;
  out1[60] = 0.0;
  out1[61] = 0.0;
  out1[62] = 0.0;
  out1[63] = ((-t176 * t324 + t203 * t321) + t205 * t322) - t207 * t323;
  out1[64] = ((t177 * t323 + t201 * t322) + t206 * t321) + t208 * t324;
  out1[65] = ((-t178 * t322 - t202 * t323) + t204 * t324) + t209 * t321;
  out1[66] = 0.0;
  out1[67] = 0.0;
  out1[68] = 0.0;
  out1[69] = t461;
  out1[70] = ((-t345 + t347) - t364) + t373;
  out1[71] = ((-t346 + t350) + t363) - t372;
  out1[72] = 0.0;
  out1[73] = 0.0;
  out1[74] = 0.0;
  out1[75] = (t138 + t367) + t376;
  out1[76] = ((t357 + -t353) + -t361) + t378;
  t138 = t211 * t323 + t212 * t322;
  out1[77] = (t138 - t365) - t374;
  out1[78] = 0.0;
  out1[79] = 0.0;
  out1[80] = 0.0;
  out1[81] = ((-t176 * t323 + t203 * t322) - t205 * t321) + t207 * t324;
  out1[82] = ((-t177 * t324 - t201 * t321) + t206 * t322) + t208 * t323;
  out1[83] = ((t178 * t321 + t202 * t324) + t204 * t323) + t209 * t322;
  out1[84] = 0.0;
  out1[85] = 0.0;
  out1[86] = 0.0;
  out1[87] = ((t345 - t347) + t364) - t373;
  out1[88] = t461;
  out1[89] = ((-t349 + t351) - t362) + t371;
  out1[90] = 0.0;
  out1[91] = 0.0;
  out1[92] = 0.0;
  out1[93] = (t58 - t366) - t375;
  out1[94] = (t138 + t365) + t374;
  out1[95] = ((t361 + -t353) + -t357) + t378;
  out1[96] = 0.0;
  out1[97] = 0.0;
  out1[98] = 0.0;
  out1[99] = ((t176 * t322 + t203 * t323) + t207 * t321) + t205 * t324;
  out1[100] = ((-t177 * t321 + t201 * t324) + t206 * t323) - t208 * t322;
  out1[101] = ((-t178 * t324 + t202 * t321) - t204 * t322) + t209 * t323;
  out1[102] = 0.0;
  out1[103] = 0.0;
  out1[104] = 0.0;
  out1[105] = ((t346 - t350) - t363) + t372;
  out1[106] = ((t349 - t351) + t362) - t371;
  out1[107] = t461;
  out2[0] = in1[27];
  out2[1] = in1[28];
  out2[2] = in1[29];
  out2[3] = ((t326 * t457 + t325 * t155) - t328 * t154) + t327 * t156;
  out2[4] = ((t325 * t154 + t327 * t457) - t326 * t156) + t328 * t155;
  out2[5] = ((t326 * t154 + t325 * t156) + t328 * t457) - t327 * t155;
}

/* End of code generation (loadsF1.c) */
