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
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
void massF2(const real_T in1[34], const real_T in2[36], real_T out1[36], real_T
            out2[108], real_T out3[108], real_T out4[6])
{
  real_T a;
  real_T b_a;
  real_T t10;
  real_T t100;
  real_T t100_tmp;
  real_T t101;
  real_T t102;
  real_T t102_tmp;
  real_T t103;
  real_T t103_tmp;
  real_T t11;
  real_T t119;
  real_T t120;
  real_T t121;
  real_T t122;
  real_T t13;
  real_T t130;
  real_T t131;
  real_T t132;
  real_T t133;
  real_T t14;
  real_T t145;
  real_T t146;
  real_T t147;
  real_T t148;
  real_T t149;
  real_T t150;
  real_T t151;
  real_T t152;
  real_T t153;
  real_T t156;
  real_T t157;
  real_T t158;
  real_T t16;
  real_T t17;
  real_T t179;
  real_T t180;
  real_T t181;
  real_T t183;
  real_T t184;
  real_T t185;
  real_T t187;
  real_T t188;
  real_T t189;
  real_T t191;
  real_T t194;
  real_T t195;
  real_T t196;
  real_T t198;
  real_T t199;
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
  real_T t215;
  real_T t216;
  real_T t217;
  real_T t221;
  real_T t222;
  real_T t223;
  real_T t225;
  real_T t228;
  real_T t23;
  real_T t233;
  real_T t234;
  real_T t235;
  real_T t237;
  real_T t238;
  real_T t239;
  real_T t24;
  real_T t241;
  real_T t242;
  real_T t243;
  real_T t244;
  real_T t245;
  real_T t246;
  real_T t247;
  real_T t248;
  real_T t249;
  real_T t25;
  real_T t250;
  real_T t255;
  real_T t257;
  real_T t258;
  real_T t259;
  real_T t26;
  real_T t260;
  real_T t261;
  real_T t262;
  real_T t264;
  real_T t265;
  real_T t266;
  real_T t267;
  real_T t268;
  real_T t269;
  real_T t270;
  real_T t271;
  real_T t272;
  real_T t274;
  real_T t275;
  real_T t281;
  real_T t282;
  real_T t283;
  real_T t285;
  real_T t286;
  real_T t287;
  real_T t288;
  real_T t289;
  real_T t29;
  real_T t290;
  real_T t291;
  real_T t292;
  real_T t293;
  real_T t294;
  real_T t295;
  real_T t297;
  real_T t298;
  real_T t30;
  real_T t303;
  real_T t31;
  real_T t315;
  real_T t316;
  real_T t317;
  real_T t32;
  real_T t320;
  real_T t321;
  real_T t322;
  real_T t323;
  real_T t324;
  real_T t325;
  real_T t327;
  real_T t328;
  real_T t348;
  real_T t349;
  real_T t35;
  real_T t350;
  real_T t36;
  real_T t38;
  real_T t47;
  real_T t47_tmp;
  real_T t5;
  real_T t51;
  real_T t51_tmp;
  real_T t52;
  real_T t52_tmp;
  real_T t55;
  real_T t55_tmp;
  real_T t56;
  real_T t56_tmp;
  real_T t57;
  real_T t57_tmp;
  real_T t59;
  real_T t59_tmp;
  real_T t6;
  real_T t60;
  real_T t60_tmp;
  real_T t61;
  real_T t61_tmp;
  real_T t62;
  real_T t63;
  real_T t64;
  real_T t7;
  real_T t8;
  real_T t83;
  real_T t9;
  real_T t90;
  real_T t91;
  real_T t92;
  real_T t93;
  real_T t94;
  real_T t95;
  real_T t96;
  real_T t97;
  real_T t98;
  real_T t98_tmp;
  real_T t99;
  real_T t99_tmp;

  /* MASSF2 */
  /*     [OUT1,OUT2,OUT3,OUT4] = MASSF2(IN1,IN2,S,DS,T_SYM) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
  /*     14-Jun-2021 23:13:51 */
  a = muDoubleScalarCos(in1[20]);
  b_a = muDoubleScalarSin(in1[20]);
  t5 = in1[33] * in1[33];
  t6 = in2[3] * in2[3];
  t7 = in2[4] * in2[4];
  t8 = in2[5] * in2[5];
  t9 = in2[9] * in2[9];
  t10 = in2[10] * in2[10];
  t11 = in2[11] * in2[11];
  t13 = in1[2] * in1[2];
  t14 = in1[3] * in1[3];
  t16 = 1.0 / in1[33];
  t21 = in1[4] / 3.0;
  t23 = in1[4] / 6.0;
  t24 = in2[3] / 2.0;
  t25 = in2[4] / 2.0;
  t26 = in2[5] / 2.0;
  t29 = in2[8] / 2.0;
  t30 = in2[9] / 2.0;
  t31 = in2[10] / 2.0;
  t32 = in2[11] / 2.0;
  t47_tmp = in2[3] * in2[9];
  t47 = t47_tmp / 4.0;
  t51_tmp = in2[3] * in2[10];
  t51 = t51_tmp / 4.0;
  t52_tmp = in2[4] * in2[9];
  t52 = t52_tmp / 4.0;
  t55_tmp = in2[3] * in2[11];
  t55 = t55_tmp / 4.0;
  t56_tmp = in2[4] * in2[10];
  t56 = t56_tmp / 4.0;
  t57_tmp = in2[5] * in2[9];
  t57 = t57_tmp / 4.0;
  t59_tmp = in2[4] * in2[11];
  t59 = t59_tmp / 4.0;
  t60_tmp = in2[5] * in2[10];
  t60 = t60_tmp / 4.0;
  t61_tmp = in2[5] * in2[11];
  t61 = t61_tmp / 4.0;
  t62 = in2[9] * in2[10] / 4.0;
  t63 = in2[9] * in2[11] / 4.0;
  t64 = in2[10] * in2[11] / 4.0;
  t83 = in1[4] / 12.0;
  t98_tmp = in1[4] * in2[3];
  t98 = t98_tmp / 24.0;
  t99_tmp = in1[4] * in2[4];
  t99 = t99_tmp / 24.0;
  t100_tmp = in1[4] * in2[5];
  t100 = t100_tmp / 24.0;
  t191 = in1[4] * in2[9];
  t101 = t191 / 24.0;
  t102_tmp = in1[4] * in2[10];
  t102 = t102_tmp / 24.0;
  t103_tmp = in1[4] * in2[11];
  t103 = t103_tmp / 24.0;
  t119 = in2[3] * in2[21] * -0.5;
  t120 = in2[4] * in2[22] * -0.5;
  t121 = in2[5] * in2[23] * -0.5;
  t133 = t191 * -0.083333333333333329;
  t145 = t98_tmp * in2[9] / 48.0;
  t146 = t98_tmp * in2[10] / 48.0;
  t147 = t99_tmp * in2[9] / 48.0;
  t148 = t98_tmp * in2[11] / 48.0;
  t149 = t99_tmp * in2[10] / 48.0;
  t150 = t100_tmp * in2[9] / 48.0;
  t151 = t99_tmp * in2[11] / 48.0;
  t152 = t100_tmp * in2[10] / 48.0;
  t153 = t100_tmp * in2[11] / 48.0;
  t17 = in1[18] * in1[18] * 6.0;
  t35 = in2[4] * t24;
  t36 = in2[5] * t24;
  t38 = in2[5] * t25;
  t90 = t6 / 4.0;
  t91 = t7 / 4.0;
  t92 = t8 / 4.0;
  t93 = in2[3] * t83;
  t94 = in2[4] * t83;
  t95 = in2[5] * t83;
  t96 = in2[9] * t83;
  t97 = in2[10] * t83;
  t122 = in2[8] + t21;
  t130 = t9 / 8.0;
  t131 = t10 / 8.0;
  t132 = t11 / 8.0;
  t156 = in1[4] * t6 / 48.0;
  t157 = in1[4] * t7 / 48.0;
  t158 = in1[4] * t8 / 48.0;
  t179 = t23 + t29;
  t183 = t30 + t64;
  t184 = t31 + t63;
  t185 = t32 + t62;
  t191 = (t47 + t56) - 1.0;
  t348 = t24 + t30;
  t203 = t348 + t59;
  t350 = t25 + t31;
  t204 = t350 + t57;
  t349 = t26 + t32;
  t205 = t349 + t51;
  t180 = in2[3] * t122 / 4.0;
  t181 = in2[4] * t122 / 4.0;
  t187 = t30 + -t64;
  t188 = t31 + -t63;
  t189 = t32 + -t62;
  t194 = t93 + in2[5] * t99;
  t195 = t94 + in2[5] * t98;
  t196 = t95 + in2[4] * t98;
  t62 = ((in2[3] + in2[9]) + in2[11] * t25) + t60_tmp * -0.5;
  t198 = ((in2[4] + in2[10]) + in2[9] * t26) + t55_tmp * -0.5;
  t199 = ((in2[5] + in2[11]) + in2[10] * t24) + t52_tmp * -0.5;
  t206 = t93 + t99_tmp * in2[5] * -0.041666666666666664;
  t207 = t94 + t98_tmp * in2[5] * -0.041666666666666664;
  t208 = t95 + t98_tmp * in2[4] * -0.041666666666666664;
  t209 = t191 * in2[23];
  t210 = ((t47 + t61) - 1.0) * in2[22];
  t211 = ((t56 + t61) - 1.0) * in2[21];
  t215 = t204 * in2[21];
  t216 = t203 * in2[23];
  t217 = t205 * in2[22];
  t225 = (in2[6] / 2.0 + t97) + in2[11] * t101;
  t64 = ((in2[9] * t24 + in2[10] * t25) + in2[11] * t26) - 2.0;
  t228 = t61 + t191;
  t250 = (in2[7] / 2.0 + t133) + in2[11] * t102;
  t259 = -t60 + t203;
  t260 = -t55 + t204;
  t261 = -t52 + t205;
  t63 = ((t6 / 8.0 + t7 / 8.0) + t8 / 8.0) + 0.5;
  t221 = (t348 + -t60) * in2[22];
  t222 = (t349 + -t52) * in2[21];
  t223 = (t350 + -t55) * in2[23];
  t233 = in2[3] * t198 / 4.0;
  t234 = in2[3] * t199 / 4.0;
  t235 = in2[4] * t62 / 4.0;
  t237 = in2[4] * t199 / 4.0;
  t238 = in2[5] * t62 / 4.0;
  t239 = in2[5] * t198 / 4.0;
  t241 = in2[9] * t62 / 4.0;
  t242 = in2[9] * t198 / 4.0;
  t243 = in2[9] * t199 / 4.0;
  t244 = in2[10] * t62 / 4.0;
  t245 = in2[10] * t198 / 4.0;
  t246 = in2[10] * t199 / 4.0;
  t247 = in2[11] * t62 / 4.0;
  t248 = in2[11] * t198 / 4.0;
  t249 = in2[11] * t199 / 4.0;
  t255 = in1[4] * in1[0] * ((t13 + t17) + -t14) * 3.1415926535897931 *
    -0.33333333333333331;
  t257 = t225 * in2[22];
  t258 = t225 * in2[23];
  t262 = t250 * in2[21];
  t264 = t250 * in2[23];
  t265 = t23 * t228;
  t266 = in2[3] * t64 / 4.0;
  t267 = in2[4] * t64 / 4.0;
  t268 = in2[5] * t64 / 4.0;
  t269 = in2[9] * t64 / 4.0;
  t270 = in2[10] * t64 / 4.0;
  t271 = in2[11] * t64 / 4.0;
  t272 = in1[4] * t228 * -0.16666666666666666;
  t191 = t83 * t228;
  t274 = t93 * t228;
  t275 = t94 * t228;
  t281 = t23 * t259;
  t282 = t23 * t260;
  t283 = t23 * t261;
  t285 = in1[4] * t259 * -0.16666666666666666;
  t286 = in1[4] * t260 * -0.16666666666666666;
  t287 = t83 * t259;
  t288 = t83 * t260;
  t289 = t83 * t261;
  t290 = t63 * in2[27];
  t291 = t63 * in2[28];
  t292 = t63 * in2[29];
  t293 = ((t130 + -t131) + -t132) + 0.5;
  t294 = ((t130 + t132) + -t131) - 0.5;
  t295 = ((t130 + t131) + -t132) - 0.5;
  t297 = t93 * t259;
  t298 = t93 * t260;
  t303 = t95 * t259;
  t315 = t99_tmp * t259 * -0.083333333333333329;
  t316 = t99_tmp * t260 * -0.083333333333333329;
  t317 = t100_tmp * t260 * -0.083333333333333329;
  t320 = ((t83 + t158) + -t156) + -t157;
  t321 = ((t83 + t157) + -t156) + -t158;
  t322 = ((t83 + t156) + -t157) + -t158;
  t323 = (((in1[4] / 4.0 + t29) + in1[4] * t11 / 48.0) + -(in1[4] * t9 / 48.0))
    + -(in1[4] * t10 / 48.0);
  t324 = t323 * in2[21];
  t325 = t323 * in2[22];
  t327 = (((t83 + t145) + t149) + t153) + t191;
  t328 = (((-t83 + t149) + t153) + -t145) + t191;
  t29 = (((-t83 + t145) + t153) + -t149) + t191;
  t145 = (((t98 + t101) + t151) + t152) + t287;
  t64 = t100 + t103;
  t149 = ((t64 + t146) + t147) + t289;
  t153 = (((t101 + -t98) + t151) + -t152) + t287;
  t9 = (((t98 + -t101) + t151) + -t152) + t287;
  t10 = (((t102 + -t99) + t150) + -t148) + t288;
  t11 = (((t99 + -t102) + t150) + -t148) + t288;
  t158 = (((t99 + t102) + -t148) + -t150) + t288;
  t157 = (((t103 + -t100) + t146) + -t147) + t289;
  t132 = ((t64 + -t146) + -t147) + t289;
  t156 = (((t30 + t59) + -t60) * in2[21] + ((t31 + t57) + -t55) * in2[22]) +
    ((t32 + t51) + -t52) * in2[23];
  t131 = (-t47 + -t56) + -t61;
  t130 = (((t131 + in2[3] * t62 / 4.0) + in2[4] * t198 / 4.0) + in2[5] * t199 /
          4.0) + 1.0;
  t63 = (t14 + -t13) + t17 * (1.0 / (b_a * b_a)) * (t5 * (a * a) - 1.0);
  t204 = t29 * in2[27];
  t205 = t328 * in2[28];
  t6 = t145 * in2[27];
  t7 = t149 * in2[28];
  t8 = t132 * in2[27];
  t348 = t158 * in2[28];
  t349 = t153 * in2[29];
  t350 = t10 * in2[29];
  t23 = t157 * in2[29];
  t203 = ((((((in2[6] * t24 + in2[7] * t25) + in2[5] * t122 / 4.0) + t26 * t179)
            + in2[11] * t191) + t283) + t97 * t259) + t133 * t260;
  t64 = in1[0] * t21 * t63 * (in1[4] * in1[4] * t5 / 108.0 + t16 * (t13 * 3.0 +
    t14 * 3.0) / 12.0) * 3.1415926535897931;
  out1[0] = t255;
  out1[1] = 0.0;
  out1[2] = 0.0;
  out1[3] = 0.0;
  out1[4] = 0.0;
  out1[5] = 0.0;
  out1[6] = 0.0;
  out1[7] = t255;
  out1[8] = 0.0;
  out1[9] = 0.0;
  out1[10] = 0.0;
  out1[11] = 0.0;
  out1[12] = 0.0;
  out1[13] = 0.0;
  out1[14] = t255;
  out1[15] = 0.0;
  out1[16] = 0.0;
  out1[17] = 0.0;
  out1[18] = 0.0;
  out1[19] = 0.0;
  out1[20] = 0.0;
  out1[21] = t64;
  out1[22] = 0.0;
  out1[23] = 0.0;
  out1[24] = 0.0;
  out1[25] = 0.0;
  out1[26] = 0.0;
  out1[27] = 0.0;
  out1[28] = t64;
  out1[29] = 0.0;
  out1[30] = 0.0;
  out1[31] = 0.0;
  out1[32] = 0.0;
  out1[33] = 0.0;
  out1[34] = 0.0;
  out1[35] = in1[0] * t16 * t21 * t63 * 3.1415926535897931 * (t13 / 2.0 + t14 /
    2.0);
  out2[0] = 1.0;
  out2[1] = 0.0;
  out2[2] = 0.0;
  out2[3] = 0.0;
  out2[4] = 0.0;
  out2[5] = 0.0;
  out2[6] = 0.0;
  out2[7] = 1.0;
  out2[8] = 0.0;
  out2[9] = 0.0;
  out2[10] = 0.0;
  out2[11] = 0.0;
  out2[12] = 0.0;
  out2[13] = 0.0;
  out2[14] = 1.0;
  out2[15] = 0.0;
  out2[16] = 0.0;
  out2[17] = 0.0;
  out2[18] = t203;
  out2[19] = (((((in2[6] * t25 - t122) + t265) + t96 * t259) + t97 * t260) -
              in2[3] * in2[7] / 2.0) - t103_tmp * t261 / 12.0;
  out2[20] = ((((((in2[7] + in2[6] * t26) - t180) + t96 * t228) + t285) + t97 *
               t261) + in2[11] * t288) - in2[3] * t179 / 2.0;
  out2[21] = (((t131 + t241) + -t245) + -t249) + 1.0;
  t191 = ((t52 + -t26) + -t32) + -t51;
  out2[22] = ((t191 + t242) + t244) + t271;
  out2[23] = ((t243 + t247) + t260) - t270;
  out2[24] = (((((in2[7] * t24 + t122) + t272) + in2[11] * t289) - in2[4] * in2
               [6] / 2.0) + t133 * t259) - t102_tmp * t260 / 12.0;
  out2[25] = t203;
  out2[26] = ((((((-in2[6] + in2[7] * t26) - t181) + t97 * t228) + t286) - in2[4]
               * t179 / 2.0) + t133 * t261) - t103_tmp * t259 / 12.0;
  out2[27] = ((t242 + t244) + t261) - t271;
  out2[28] = (((t131 + t245) + -t241) + -t249) + 1.0;
  t62 = ((t60 + -t24) + -t30) + -t59;
  out2[29] = ((t62 + t246) + t248) + t269;
  out2[30] = ((((((-in2[7] + t180) + t24 * t179) + t281) - in2[5] * in2[6] / 2.0)
               + t133 * t228) - t102_tmp * t261 / 12.0) - t103_tmp * t260 / 12.0;
  out2[31] = ((((((in2[6] + t181) + t25 * t179) + t282) + t96 * t261) + in2[11] *
               t287) - in2[5] * in2[7] / 2.0) - t102_tmp * t228 / 12.0;
  out2[32] = t203;
  t63 = ((t55 + -t25) + -t31) + -t57;
  out2[33] = ((t63 + t243) + t247) + t270;
  out2[34] = ((t246 + t248) + t259) - t269;
  out2[35] = (((t131 + t249) + -t241) + -t245) + 1.0;
  out2[36] = ((t90 + -t91) + -t92) + 1.0;
  out2[37] = in2[5] + t35;
  out2[38] = -in2[4] + t36;
  out2[39] = 0.0;
  out2[40] = 0.0;
  out2[41] = 0.0;
  out2[42] = -in2[5] + t35;
  out2[43] = ((t91 + -t90) + -t92) + 1.0;
  out2[44] = in2[3] + t38;
  out2[45] = 0.0;
  out2[46] = 0.0;
  out2[47] = 0.0;
  out2[48] = in2[4] + t36;
  out2[49] = -in2[3] + t38;
  out2[50] = ((t92 + -t90) + -t91) + 1.0;
  out2[51] = 0.0;
  out2[52] = 0.0;
  out2[53] = 0.0;
  t64 = t283 + t100_tmp * t228 * -0.083333333333333329;
  out2[54] = (t64 + t315) - t98_tmp * t260 / 12.0;
  out2[55] = ((t265 + t297) + t95 * t261) + t316;
  out2[56] = ((t274 + t285) + t317) - t99_tmp * t261 / 12.0;
  out2[57] = t130;
  out2[58] = ((t191 + t233) - t235) - t268;
  out2[59] = ((t234 - t238) + t260) + t267;
  out2[60] = ((t272 + t297) + t316) - t100_tmp * t261 / 12.0;
  out2[61] = (t64 + t298) + t94 * t259;
  out2[62] = ((t275 + t286) + t93 * t261) + t303;
  out2[63] = ((-t233 + t235) + t261) + t268;
  out2[64] = t130;
  out2[65] = ((t62 + t237) - t239) - t266;
  out2[66] = ((t274 + t281) + t94 * t261) + t317;
  out2[67] = ((t275 + t282) + t303) - t98_tmp * t261 / 12.0;
  out2[68] = ((t95 * t228 + t283) + t298) + t315;
  out2[69] = ((t63 - t234) + t238) - t267;
  out2[70] = ((-t237 + t239) + t259) + t266;
  out2[71] = t130;
  memset(&out2[72], 0, 36U * sizeof(real_T));
  t64 = (((((((t24 * in2[24] + t25 * in2[25]) + t26 * in2[26]) + t225 * in2[21])
            + t250 * in2[22]) + t323 * in2[23]) + t327 * in2[29]) + t9 * in2[28])
    + -(t11 * in2[27]);
  memset(&out3[0], 0, 18U * sizeof(real_T));
  out3[18] = t64;
  out3[19] = ((((((t25 * in2[24] + t257) - t262) + t6) + t348) - t23) - in2[26])
    - in2[3] * in2[25] / 2.0;
  out3[20] = ((((((t26 * in2[24] + t258) - t324) + t204) + t7) + t350) + in2[25])
    - in2[3] * in2[26] / 2.0;
  out3[21] = (((t24 * in2[27] + t55 * in2[28]) + t185 * in2[23]) + t188 * in2[22])
    - t51_tmp * in2[29] / 4.0;
  out3[22] = (((t24 * in2[28] + t47 * in2[29]) - t183 * in2[22]) - t294 * in2[23])
    - t55_tmp * in2[27] / 4.0;
  out3[23] = (((t24 * in2[29] + t51 * in2[27]) - t187 * in2[23]) + t295 * in2[22])
    - t47_tmp * in2[28] / 4.0;
  out3[24] = ((((((t24 * in2[25] - t257) + t262) - t6) - t348) + t23) + in2[26])
    - in2[4] * in2[24] / 2.0;
  out3[25] = t64;
  out3[26] = ((((((t26 * in2[25] + t264) - t325) + t205) - t8) - t349) - in2[24])
    - in2[4] * in2[26] / 2.0;
  out3[27] = (((t25 * in2[27] + t59 * in2[28]) - t188 * in2[21]) - t293 * in2[23])
    - t56_tmp * in2[29] / 4.0;
  out3[28] = (((t25 * in2[28] + t52 * in2[29]) + t183 * in2[21]) + t189 * in2[23])
    - t59_tmp * in2[27] / 4.0;
  out3[29] = (((t25 * in2[29] + t56 * in2[27]) - t184 * in2[23]) - t295 * in2[21])
    - t52_tmp * in2[28] / 4.0;
  out3[30] = ((((((t24 * in2[26] - t258) + t324) - t204) - t7) - t350) - in2[25])
    - in2[5] * in2[24] / 2.0;
  out3[31] = ((((((t25 * in2[26] - t264) + t325) - t205) + t8) + t349) + in2[24])
    - in2[5] * in2[25] / 2.0;
  out3[32] = t64;
  out3[33] = (((t26 * in2[27] + t61 * in2[28]) - t185 * in2[21]) + t293 * in2[22])
    - t60_tmp * in2[29] / 4.0;
  out3[34] = (((t26 * in2[28] + t57 * in2[29]) - t189 * in2[22]) + t294 * in2[21])
    - t61_tmp * in2[27] / 4.0;
  out3[35] = (((t26 * in2[29] + t60 * in2[27]) + t184 * in2[22]) + t187 * in2[21])
    - t57_tmp * in2[28] / 4.0;
  out3[36] = (t24 * in2[21] + t120) + t121;
  t64 = t24 * in2[22] + t25 * in2[21];
  out3[37] = t64 + in2[23];
  t191 = t24 * in2[23] + t26 * in2[21];
  out3[38] = t191 - in2[22];
  out3[39] = 0.0;
  out3[40] = 0.0;
  out3[41] = 0.0;
  out3[42] = t64 - in2[23];
  out3[43] = (t25 * in2[22] + t119) + t121;
  t64 = t25 * in2[23] + t26 * in2[22];
  out3[44] = t64 + in2[21];
  out3[45] = 0.0;
  out3[46] = 0.0;
  out3[47] = 0.0;
  out3[48] = t191 + in2[22];
  out3[49] = t64 - in2[21];
  out3[50] = (t26 * in2[23] + t119) + t120;
  out3[51] = 0.0;
  out3[52] = 0.0;
  out3[53] = 0.0;
  out3[54] = (((-t195 * in2[27] + t322 * in2[29]) - t29 * in2[23]) - t145 * in2
              [22]) - t11 * in2[21];
  out3[55] = (((t196 * in2[29] + t206 * in2[27]) + t145 * in2[21]) - t11 * in2
              [22]) + t132 * in2[23];
  out3[56] = (((-t207 * in2[29] - t320 * in2[27]) + t29 * in2[21]) - t11 * in2
              [23]) - t132 * in2[22];
  out3[57] = t156;
  out3[58] = ((-t209 + t215) - t221) + t292;
  out3[59] = ((t210 - t216) + t222) - t291;
  out3[60] = (((-t195 * in2[28] - t208 * in2[29]) - t149 * in2[23]) + t9 * in2
              [21]) - t158 * in2[22];
  out3[61] = (((t206 * in2[28] + t321 * in2[29]) - t328 * in2[23]) + t9 * in2[22])
    + t158 * in2[21];
  out3[62] = (((t194 * in2[29] - t320 * in2[28]) + t328 * in2[22]) + t149 * in2
              [21]) + t9 * in2[23];
  out3[63] = ((t209 - t215) + t221) - t292;
  out3[64] = t156;
  out3[65] = ((-t211 + t217) - t223) + t290;
  out3[66] = ((((t195 * in2[29] - t208 * in2[28]) + t327 * in2[21]) + t322 *
               in2[27]) - t10 * in2[23]) + t157 * in2[22];
  out3[67] = ((((t196 * in2[27] - t206 * in2[29]) + t321 * in2[28]) + t327 *
               in2[22]) + t153 * in2[23]) - t157 * in2[21];
  out3[68] = ((((t194 * in2[28] - t207 * in2[27]) + t320 * in2[29]) + t327 *
               in2[23]) - t153 * in2[22]) + t10 * in2[21];
  out3[69] = ((-t210 + t216) - t222) + t291;
  out3[70] = ((t211 - t217) + t223) - t290;
  out3[71] = t156;
  memset(&out3[72], 0, 36U * sizeof(real_T));
  out4[0] = in1[12];
  out4[1] = in1[13];
  out4[2] = in1[14];
  out4[3] = 0.0;
  out4[4] = 0.0;
  out4[5] = 0.0;
}

/* End of code generation (massF2.c) */
