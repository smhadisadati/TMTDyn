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
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
void massF1(const real_T in1[34], const real_T in2[24], real_T out1[36], real_T
            out2[72], real_T out3[72], real_T out4[6])
{
  real_T t100;
  real_T t101;
  real_T t109;
  real_T t11;
  real_T t110;
  real_T t111;
  real_T t115_tmp;
  real_T t116;
  real_T t117;
  real_T t118;
  real_T t119;
  real_T t12;
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
  real_T t13;
  real_T t130;
  real_T t131;
  real_T t133;
  real_T t134;
  real_T t135;
  real_T t136;
  real_T t137;
  real_T t138;
  real_T t139;
  real_T t140;
  real_T t141;
  real_T t142;
  real_T t143;
  real_T t15;
  real_T t150;
  real_T t152;
  real_T t154;
  real_T t156;
  real_T t158;
  real_T t159;
  real_T t16;
  real_T t160;
  real_T t161;
  real_T t164;
  real_T t165;
  real_T t166;
  real_T t167;
  real_T t168;
  real_T t169;
  real_T t17;
  real_T t170;
  real_T t171;
  real_T t172;
  real_T t173;
  real_T t175;
  real_T t176;
  real_T t177;
  real_T t178;
  real_T t179;
  real_T t18;
  real_T t180;
  real_T t190;
  real_T t192;
  real_T t194;
  real_T t196;
  real_T t198;
  real_T t198_tmp;
  real_T t199;
  real_T t201;
  real_T t202_tmp;
  real_T t203;
  real_T t204;
  real_T t205;
  real_T t21;
  real_T t217;
  real_T t249_tmp;
  real_T t25;
  real_T t255;
  real_T t258;
  real_T t26;
  real_T t261;
  real_T t265;
  real_T t27;
  real_T t279;
  real_T t279_tmp;
  real_T t28;
  real_T t280;
  real_T t281;
  real_T t281_tmp;
  real_T t282;
  real_T t282_tmp;
  real_T t29;
  real_T t294_tmp;
  real_T t303;
  real_T t303_tmp;
  real_T t309;
  real_T t309_tmp;
  real_T t310;
  real_T t5;
  real_T t50;
  real_T t51;
  real_T t52;
  real_T t53;
  real_T t54;
  real_T t57;
  real_T t58;
  real_T t59;
  real_T t6;
  real_T t61;
  real_T t62;
  real_T t63;
  real_T t64;
  real_T t7;
  real_T t75;
  real_T t76;
  real_T t77;
  real_T t78;
  real_T t79;
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
  real_T t90;
  real_T t91;
  real_T t92;
  real_T t93;
  real_T t94;
  real_T t95;
  real_T t96;
  real_T t97;
  real_T t98;
  real_T t99;

  /* MASSF1 */
  /*     [OUT1,OUT2,OUT3,OUT4] = MASSF1(IN1,IN2,S,DS,T_SYM) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
  /*     26-Feb-2021 18:54:18 */
  t5 = in1[2] * in1[2];
  t6 = in1[3] * in1[3];
  t7 = 1.0 / in1[33];
  t11 = in2[3] / 2.0;
  t12 = in2[4] / 2.0;
  t13 = in2[5] / 2.0;
  t15 = muDoubleScalarCos(t11);
  t16 = muDoubleScalarCos(t12);
  t17 = muDoubleScalarCos(t13);
  t18 = muDoubleScalarSin(t11);
  t12 = muDoubleScalarSin(t12);
  t11 = muDoubleScalarSin(t13);
  t21 = t5 + -t6;
  t13 = t15 * t16;
  t25 = t13 * t11;
  t26 = t15 * t17 * t12;
  t27 = t16 * t17 * t18;
  t28 = t15 * t12 * t11;
  t29 = t16 * t18 * t11;
  t15 = t17 * t18 * t12;
  t16 = t18 * t12 * t11;
  t11 = t13 * t17;
  t12 = t25 / 2.0;
  t18 = t26 / 2.0;
  t50 = t27 / 2.0;
  t51 = t25 / 4.0;
  t52 = t26 / 4.0;
  t53 = t27 / 4.0;
  t54 = t28 / 2.0;
  t17 = t29 / 2.0;
  t13 = t15 / 2.0;
  t57 = t28 / 4.0;
  t58 = t29 / 4.0;
  t59 = t15 / 4.0;
  t61 = t16 / 2.0;
  t62 = t16 / 4.0;
  t63 = t11 / 2.0;
  t64 = t11 / 4.0;
  t75 = t25 + t15;
  t76 = t26 + t29;
  t77 = t27 + t28;
  t78 = t16 + t11;
  t79 = t25 + -t15;
  t80 = t26 + -t29;
  t81 = t27 + -t28;
  t82 = t16 + -t11;
  t83 = t25 * 2.0 + t15 * 2.0;
  t84 = t27 * 2.0 + t28 * 2.0;
  t87 = t12 + t13;
  t88 = t18 + t17;
  t89 = t50 + t54;
  t90 = t61 + t63;
  t91 = t51 + t59;
  t92 = t52 + t58;
  t93 = t53 + t57;
  t94 = t62 + t64;
  t15 = in1[4] * in1[0];
  t25 = -(t15 * (in1[18] * in1[18] * 6.0 + t21) * 3.1415926535897931 / 2.0);
  t85 = t26 * 2.0 + -(t29 * 2.0);
  t86 = t16 * 2.0 + -(t11 * 2.0);
  t95 = t12 + -t13;
  t96 = t18 + -t17;
  t97 = t50 + -t54;
  t98 = t61 + -t63;
  t99 = t51 + -t59;
  t100 = t52 + -t58;
  t101 = t53 + -t57;
  t64 = t62 + -t64;
  t116 = t75 * t87;
  t117 = t75 * t89;
  t118 = t77 * t87;
  t119 = t77 * t89;
  t133 = t79 * t89;
  t134 = t80 * t87;
  t135 = t80 * t88;
  t136 = t80 * t89;
  t137 = t80 * t90;
  t138 = t81 * t87;
  t139 = t81 * t89;
  t140 = t82 * t87;
  t141 = t82 * t88;
  t142 = t82 * t89;
  t143 = t82 * t90;
  t29 = t83 * t87;
  t61 = t83 * t89;
  t63 = t84 * t87;
  t51 = t84 * t89;
  t150 = t83 * t91;
  t152 = t83 * t93;
  t154 = t84 * t91;
  t156 = t84 * t93;
  t198_tmp = in1[4] * t75;
  t198 = t198_tmp * t91 / 2.0;
  t199 = t198_tmp * t92 / 2.0;
  t59 = t198_tmp * t93 / 2.0;
  t201 = t198_tmp * t94 / 2.0;
  t202_tmp = in1[4] * t77;
  t57 = t202_tmp * t91 / 2.0;
  t203 = t202_tmp * t92 / 2.0;
  t204 = t202_tmp * t93 / 2.0;
  t205 = t202_tmp * t94 / 2.0;
  t249_tmp = in1[4] * t82;
  t279_tmp = in1[4] * t87;
  t279 = t279_tmp * t88 / 2.0;
  t280 = t279_tmp * t90 / 2.0;
  t281_tmp = in1[4] * t88;
  t281 = t281_tmp * t89 / 2.0;
  t282_tmp = in1[4] * t89;
  t282 = t282_tmp * t90 / 2.0;
  t11 = -(t15 * t21 * (in1[4] * in1[4] * (in1[33] * in1[33]) / 48.0 + t7 * (t5 *
            3.0 + t6 * 3.0) / 12.0) * 3.1415926535897931 / 2.0);
  out1[0] = t25;
  out1[1] = 0.0;
  out1[2] = 0.0;
  out1[3] = 0.0;
  out1[4] = 0.0;
  out1[5] = 0.0;
  out1[6] = 0.0;
  out1[7] = t25;
  out1[8] = 0.0;
  out1[9] = 0.0;
  out1[10] = 0.0;
  out1[11] = 0.0;
  out1[12] = 0.0;
  out1[13] = 0.0;
  out1[14] = t25;
  out1[15] = 0.0;
  out1[16] = 0.0;
  out1[17] = 0.0;
  out1[18] = 0.0;
  out1[19] = 0.0;
  out1[20] = 0.0;
  out1[21] = t11;
  out1[22] = 0.0;
  out1[23] = 0.0;
  out1[24] = 0.0;
  out1[25] = 0.0;
  out1[26] = 0.0;
  out1[27] = 0.0;
  out1[28] = t11;
  out1[29] = 0.0;
  out1[30] = 0.0;
  out1[31] = 0.0;
  out1[32] = 0.0;
  out1[33] = 0.0;
  out1[34] = 0.0;
  out1[35] = t15 * t7 * t21 * 3.1415926535897931 * (t5 / 2.0 + t6 / 2.0) * -0.5;
  t109 = in1[4] * (t87 * t87) / 2.0;
  t110 = in1[4] * (t89 * t89) / 2.0;
  t120 = t75 * t95;
  t121 = t75 * t96;
  t122 = t75 * t97;
  t123 = t75 * t98;
  t124 = t76 * t96;
  t125 = t76 * t98;
  t126 = t77 * t95;
  t127 = t77 * t96;
  t128 = t77 * t97;
  t129 = t77 * t98;
  t130 = t78 * t96;
  t131 = t78 * t98;
  t158 = t80 * t96;
  t159 = t80 * t98;
  t160 = t82 * t96;
  t161 = t82 * t98;
  t164 = t83 * t99;
  t165 = t83 * t100;
  t166 = t83 * t101;
  t167 = t83 * t64;
  t168 = t85 * t91;
  t169 = t85 * t92;
  t170 = t85 * t93;
  t171 = t85 * t94;
  t172 = t84 * t99;
  t173 = t84 * t100;
  t175 = t84 * t64;
  t176 = t86 * t91;
  t177 = t86 * t92;
  t178 = t86 * t93;
  t179 = t86 * t94;
  t180 = -(t79 * t87);
  t12 = t85 * t96;
  t13 = t85 * t98;
  t15 = t86 * t98;
  t190 = t85 * t100;
  t192 = t85 * t64;
  t194 = t86 * t100;
  t196 = t86 * t64;
  t16 = in1[4] * t134 / 2.0;
  t18 = in1[4] * t136 / 2.0;
  t17 = in1[4] * t140 / 2.0;
  t25 = in1[4] * t142 / 2.0;
  t62 = in1[4] * t80;
  t26 = t62 * t99 / 2.0;
  t255 = t62 * t100 / 2.0;
  t21 = t62 * t101 / 2.0;
  t258 = t62 * t64 / 2.0;
  t5 = t249_tmp * t99 / 2.0;
  t261 = t249_tmp * t100 / 2.0;
  t52 = t249_tmp * t101 / 2.0;
  t265 = t249_tmp * t64 / 2.0;
  t294_tmp = in1[4] * t95;
  t58 = t294_tmp * t96 / 2.0;
  t6 = t294_tmp * t98 / 2.0;
  t11 = in1[4] * t96;
  t7 = t11 * t97 / 2.0;
  t53 = in1[4] * t97 * t98 / 2.0;
  t111 = in1[4] * (t96 * t96) / 2.0;
  t217 = -(t84 * t101);
  t28 = in1[4] * t121 / 2.0;
  t27 = in1[4] * t123 / 2.0;
  t50 = in1[4] * t127 / 2.0;
  t54 = -(t86 * t96);
  t303_tmp = t59 + t57;
  t303 = (((t303_tmp + t279_tmp * t89) + t258) + t261) + t11 * t98;
  t309_tmp = in1[4] * t90;
  t309 = ((((((t198_tmp * t99 / 2.0 + t202_tmp * t101 / 2.0) + t62 * t92 / 2.0)
             + t249_tmp * t94 / 2.0) + t279_tmp * t95 / 2.0) + t281_tmp * t96 /
           2.0) + t282_tmp * t97 / 2.0) + t309_tmp * t98 / 2.0;
  t310 = ((((((t199 + t205) + t26) + t52) + t279) + t282) + t58) + t53;
  t115_tmp = -(in1[4] * (t98 * t98) / 2.0);
  t11 = -(in1[4] * t129 / 2.0);
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
  out2[18] = ((in1[4] * t117 * -0.5 - in1[4] * t118 / 2.0) - in1[4] * t159 / 2.0)
    - in1[4] * t160 / 2.0;
  out2[19] = ((-t27 + t50) + t18) - t17;
  out2[20] = ((-t28 + t11) + t16) + t25;
  out2[21] = ((t86 * t87 + t85 * t89) + t84 * t96) + t83 * t98;
  out2[22] = ((t61 + t63) - t13) + t54;
  out2[23] = ((-t29 + t51) - t12) + t15;
  out2[24] = ((t198_tmp * t88 * -0.5 + t202_tmp * t90 / 2.0) + t62 * t95 / 2.0)
    - t249_tmp * t97 / 2.0;
  out2[25] = ((in1[4] * t120 / 2.0 + in1[4] * t128 / 2.0) + in1[4] * t135 / 2.0)
    + in1[4] * t143 / 2.0;
  out2[26] = ((in1[4] * t122 * -0.5 + in1[4] * t126 / 2.0) - in1[4] * t137 / 2.0)
    + in1[4] * t141 / 2.0;
  out2[27] = ((t85 * t88 - t86 * t90) - t83 * t95) + t84 * t97;
  out2[28] = ((t83 * t88 - t84 * t90) + t85 * t95) - t86 * t97;
  out2[29] = ((t84 * t88 + t83 * t90) - t86 * t95) - t85 * t97;
  out2[30] = ((in1[4] * t116 * -0.5 - in1[4] * t119 / 2.0) + in1[4] * t158 / 2.0)
    + in1[4] * t161 / 2.0;
  out2[31] = ((t28 + t11) + t16) - t25;
  out2[32] = ((t27 + t50) + t18) + t17;
  out2[33] = ((t85 * t87 + t86 * t89) - t83 * t96) - t84 * t98;
  out2[34] = ((t29 + t51) + t12) + t15;
  out2[35] = ((-t61 + t63) + t13) + t54;
  memset(&out2[36], 0, 36U * sizeof(real_T));
  t51 = ((t59 + -t57) + t261) + -t258;
  t59 = ((((t198_tmp * t100 / 2.0 + -(t202_tmp * t64 / 2.0)) + t62 * t91 / 2.0)
          + -(t249_tmp * t93 / 2.0)) + t279_tmp * t96) + -(t282_tmp * t98);
  t54 = ((t198_tmp * t64 / 2.0 + -(t202_tmp * t100 / 2.0)) + t249_tmp * t91 /
         2.0) + -(t62 * t93 / 2.0);
  t29 = (t54 + t279_tmp * t98) + -(t282_tmp * t96);
  t61 = ((((((t121 + t142) + -t129) + t168) + t175) + -t134) + -t165) + -t178;
  t63 = ((((((t123 + t136) + -t127) + t173) + t176) + -t140) + -t167) + -t170;
  t50 = ((((((t199 + -t205) + t52) + -t26) + t279) + -t282) + t53) + -t58;
  t28 = ((((((t198_tmp * t101 / 2.0 + t202_tmp * t99 / 2.0) + -(t62 * t94 / 2.0))
            + -(t249_tmp * t92 / 2.0)) + t282_tmp * t95 / 2.0) + t279_tmp * t97 /
          2.0) + -(t309_tmp * t96 / 2.0)) + -(t281_tmp * t98 / 2.0);
  t27 = ((((((t201 + -t203) + t21) + -t5) + t280) + -t281) + t7) + -t6;
  t11 = ((((((t201 + t203) + -t21) + -t5) + -t280) + -t281) + t6) + t7;
  t25 = ((((((t109 + t110) + -t111) + t115_tmp) + t198) + t204) + -t255) + -t265;
  memset(&out3[0], 0, 18U * sizeof(real_T));
  out3[18] = (t29 * in2[15] - t59 * in2[17]) - t309 * in2[16];
  out3[19] = (-t303 * in2[15] - t25 * in2[17]) - t50 * in2[16];
  t18 = ((t109 + t111) + -t110) + t115_tmp;
  out3[20] = (-in2[15] * ((((t18 - t198) + t204) + t265) + -t255) + t51 * in2[17])
    - t11 * in2[16];
  t17 = ((t83 * t92 + t84 * t94) + t85 * t99) + t86 * t101;
  t16 = t116 + -t119;
  t15 = t117 + -t118;
  out3[21] = (in2[16] * ((((t17 - t75 * t88) - t77 * t90) - t80 * t95) - t82 *
    t97) - in2[17] * ((((((t16 - t150) + t156) + t158) - t190) + t196) + -t161))
    - in2[15] * ((((((t15 + t154) + t160) + t192) + -t152) + -t159) + -t194);
  out3[22] = (-in2[16] * (((((((t120 + t128) - t143) + t169) + t179) + -t135) +
    -t164) + t217) + t63 * in2[15]) - t61 * in2[17];
  t13 = ((t123 + t127) + t136) + t140;
  t12 = t121 + t129;
  out3[23] = (in2[15] * ((((((t12 + t168) - t175) + t178) + -t134) + -t142) +
    -t165) + in2[16] * (((((((t122 - t126) + t137) - t141) + t172) + t177) +
    -t166) + -t171)) - in2[17] * ((((t13 + -t167) + -t170) + -t173) + -t176);
  out3[24] = (-t309 * in2[15] - t28 * in2[17]) + in2[16] * ((t54 - t281_tmp *
    t97) + t309_tmp * t95);
  out3[25] = (-t50 * in2[15] + t27 * in2[17]) - in2[16] * ((((t303_tmp + t258) +
    t261) - t281_tmp * t90) - t294_tmp * t97);
  out3[26] = (t310 * in2[17] - t11 * in2[15]) + in2[16] * (((((((t198 + -t204) +
    t255) + -t265) + in1[4] * (t88 * t88) / 2.0) - in1[4] * (t90 * t90) / 2.0) +
    in1[4] * (t95 * t95) / 2.0) - in1[4] * (t97 * t97) / 2.0);
  t11 = ((t83 * t94 + t84 * t92) - t85 * t101) - t86 * t99;
  out3[27] = (in2[15] * ((((t17 + t76 * t87) + t78 * t89) + t79 * t96) + t81 *
    t98) + in2[16] * (((((((t152 - t154) - t192) + t194) - t76 * t90) + t78 *
                        t88) + t79 * t97) - t81 * t95)) - in2[17] * ((((t11 -
    t76 * t89) - t78 * t87) + t79 * t98) + t81 * t96);
  out3[28] = (-in2[16] * (((((((t167 + t170) + -t173) + -t176) + t79 * t90) -
    t81 * t88) + t76 * t97) - t78 * t95) - in2[15] * (((((((t124 + t131) - t139)
    + t169) + t179) + t180) + -t164) + t217)) + in2[17] * (((((((t125 + t130) +
    t133) + t138) + t166) + t171) + t172) + t177);
  out3[29] = (-in2[16] * (((((((t165 + t175) + -t168) + -t178) - t79 * t88) +
    t76 * t95) - t81 * t90) + t78 * t97) - in2[17] * (((((((t124 - t131) + t139)
    + t164) + t179) + t180) + -t169) + t217)) + in2[15] * (((((((t125 - t130) +
    t133) - t138) + t172) + t177) + -t166) + -t171);
  out3[30] = (-t59 * in2[15] + t29 * in2[17]) - t28 * in2[16];
  out3[31] = (-t303 * in2[17] - t25 * in2[15]) + t27 * in2[16];
  out3[32] = (t51 * in2[15] + t310 * in2[16]) + in2[17] * ((((t18 + t198) +
    -t204) + t255) + -t265);
  out3[33] = (in2[15] * ((((((t16 + t150) - t156) + t158) + t190) - t196) +
    -t161) + in2[17] * ((((((t15 + t152) - t154) + t160) - t192) + t194) + -t159))
    - in2[16] * ((((t11 + t75 * t90) + t77 * t88) - t80 * t97) - t82 * t95);
  out3[34] = (-t61 * in2[15] + t63 * in2[17]) - in2[16] * (((((((t122 + t126) +
    t137) + t141) - t172) - t177) + -t166) + -t171);
  out3[35] = (-in2[16] * (((((((t120 - t128) + t143) + t164) + t179) + -t135) +
    -t169) + t217) + in2[15] * ((((t13 + t167) + t170) + t173) + t176)) - in2[17]
    * ((((((t12 + t165) + t175) + -t134) + -t142) + -t168) + -t178);
  memset(&out3[36], 0, 36U * sizeof(real_T));
  out4[0] = in1[12];
  out4[1] = in1[13];
  out4[2] = in1[14];
  out4[3] = 0.0;
  out4[4] = 0.0;
  out4[5] = 0.0;
}

/* End of code generation (massF1.c) */
