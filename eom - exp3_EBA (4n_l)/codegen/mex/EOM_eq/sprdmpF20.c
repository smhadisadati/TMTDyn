/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sprdmpF20.c
 *
 * Code generation for function 'sprdmpF20'
 *
 */

/* Include files */
#include "sprdmpF20.h"
#include "EOM_eq_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo qd_emlrtRSI = { 86, /* lineNo */
  "sprdmpF20",                         /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\sprdmpF20.m"/* pathName */
};

static emlrtRSInfo yd_emlrtRSI = { 155,/* lineNo */
  "sprdmpF20",                         /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\sprdmpF20.m"/* pathName */
};

static emlrtRSInfo ae_emlrtRSI = { 156,/* lineNo */
  "sprdmpF20",                         /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\sprdmpF20.m"/* pathName */
};

/* Function Definitions */
void sprdmpF20(const emlrtStack *sp, const real_T in1[34], const real_T in2[36],
               real_T out1[108], real_T out2[6], real_T out3[6], real_T out4[6],
               real_T *out6)
{
  emlrtStack st;
  real_T t10;
  real_T t100;
  real_T t101;
  real_T t102;
  real_T t11;
  real_T t110;
  real_T t112;
  real_T t113;
  real_T t114;
  real_T t115;
  real_T t116;
  real_T t117;
  real_T t118;
  real_T t12;
  real_T t122;
  real_T t123;
  real_T t124;
  real_T t13;
  real_T t140;
  real_T t141;
  real_T t142;
  real_T t143;
  real_T t144;
  real_T t145;
  real_T t146;
  real_T t147;
  real_T t148;
  real_T t155;
  real_T t158;
  real_T t159;
  real_T t160;
  real_T t161;
  real_T t162;
  real_T t163;
  real_T t17;
  real_T t18;
  real_T t182;
  real_T t183;
  real_T t184;
  real_T t186;
  real_T t190;
  real_T t191;
  real_T t192;
  real_T t199;
  real_T t20;
  real_T t200;
  real_T t201;
  real_T t206;
  real_T t207;
  real_T t208;
  real_T t209;
  real_T t21;
  real_T t212;
  real_T t219;
  real_T t219_tmp;
  real_T t220;
  real_T t220_tmp;
  real_T t221;
  real_T t225;
  real_T t226;
  real_T t227;
  real_T t234;
  real_T t235;
  real_T t236;
  real_T t25;
  real_T t26;
  real_T t27;
  real_T t28;
  real_T t29;
  real_T t4;
  real_T t40;
  real_T t41;
  real_T t42;
  real_T t43;
  real_T t45;
  real_T t46;
  real_T t47;
  real_T t5;
  real_T t50;
  real_T t52;
  real_T t54;
  real_T t6;
  real_T t60;
  real_T t61;
  real_T t62;
  real_T t63;
  real_T t64;
  real_T t65;
  real_T t66;
  real_T t68;
  real_T t69;
  real_T t7;
  real_T t70;
  real_T t71;
  real_T t72;
  real_T t73;
  real_T t74;
  real_T t75;
  real_T t76;
  real_T t77;
  real_T t8;
  real_T t9;
  st.prev = sp;
  st.tls = sp->tls;

  /* SPRDMPF20 */
  /*     [OUT1,OUT2,OUT3,OUT4,OUT5,OUT6,OUT7] = SPRDMPF20(IN1,IN2,S,DS,T_SYM) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
  /*     15-Jun-2021 01:39:27 */
  t118 = muDoubleScalarCos(in1[20]);
  t117 = muDoubleScalarSin(in1[20]);
  t4 = in1[33] * in1[33];
  t5 = in2[3] * 2.0;
  t6 = in2[4] * 2.0;
  t7 = in2[5] * 2.0;
  t8 = in2[9] * 2.0;
  t9 = in2[10] * 2.0;
  t10 = in2[11] * 2.0;
  t11 = in2[3] * in2[3];
  t12 = in2[4] * in2[4];
  t13 = in2[5] * in2[5];
  t17 = in1[19] * in1[19];
  t18 = in1[18] * in1[18];
  t20 = in1[2] * in1[2];
  t21 = in1[3] * in1[3];
  t28 = 1.0 / in1[4];
  t29 = 1.0 / in1[33];
  t45 = in2[3] * in2[4] * -2.0;
  t46 = in2[3] * in2[5] * -2.0;
  t47 = in2[4] * in2[5] * -2.0;
  st.site = &qd_emlrtRSI;
  if (in1[33] < 0.0) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  t66 = 1.0 / muDoubleScalarSqrt(in1[33]);
  t25 = in2[4] * t5;
  t26 = in2[5] * t5;
  t27 = in2[5] * t6;
  t40 = in2[3] * t5;
  t41 = in2[4] * t6;
  t42 = in2[5] * t7;
  t43 = 1.0 / (t117 * t117);
  t50 = t11 * -2.0;
  t52 = t12 * -2.0;
  t54 = t13 * -2.0;
  t60 = in2[0] + -in2[6];
  t61 = in2[1] + -in2[7];
  t62 = in2[2] + -in2[8];
  t63 = in2[3] + -in2[9];
  t64 = in2[4] + -in2[10];
  t65 = in2[5] + -in2[11];
  t68 = t4 * (t118 * t118);
  t69 = in2[3] * t60;
  t70 = in2[4] * t60;
  t71 = in2[3] * t61;
  t72 = in2[5] * t60;
  t73 = in2[4] * t61;
  t74 = in2[3] * t62;
  t75 = in2[5] * t61;
  t76 = in2[4] * t62;
  t77 = in2[5] * t62;
  t100 = (t40 + t41) - 1.0;
  t101 = (t40 + t42) - 1.0;
  t102 = (t41 + t42) - 1.0;
  t110 = ((-t11 + -t12) + -t13) + 1.0;
  st.site = &yd_emlrtRSI;
  if (t110 < 0.0) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  t110 = muDoubleScalarSqrt(t110);
  t12 = ((-(in2[9] * in2[9]) + -(in2[10] * in2[10])) + -(in2[11] * in2[11])) +
    1.0;
  st.site = &ae_emlrtRSI;
  if (t12 < 0.0) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  t12 = muDoubleScalarSqrt(t12);
  t114 = (t69 + t73) + t77;
  t112 = 1.0 / t110;
  t113 = 1.0 / t12;
  t115 = t110 * 2.0;
  t116 = t12 * 2.0;
  t117 = t5 * t110;
  t118 = t6 * t110;
  t11 = t7 * t110;
  t122 = in2[3] * t110 * -2.0;
  t123 = in2[4] * t110 * -2.0;
  t124 = in2[5] * t110 * -2.0;
  t143 = t60 * t110;
  t144 = t61 * t110;
  t145 = t62 * t110;
  t140 = t45 * t112;
  t141 = t46 * t112;
  t142 = t47 * t112;
  t146 = t27 + t117;
  t147 = t26 + t118;
  t148 = t25 + t11;
  t155 = t74 * t112;
  t158 = t47 + t117;
  t159 = t46 + t118;
  t160 = t45 + t11;
  t206 = (t70 + -t71) + t145;
  t207 = (t74 + -t72) + t144;
  t208 = (t75 + -t76) + t143;
  t209 = t110 + -t12;
  t161 = t5 + in2[11] * t6 * t113;
  t162 = t6 + in2[9] * t7 * t113;
  t163 = t7 + in2[10] * t5 * t113;
  t182 = t29 * (t20 + -t21) + -(t18 * t43 * (t68 - 1.0) * 6.0);
  t183 = t60 + t75 * t112;
  t184 = (in2[7] + -in2[1]) + t72 * t112;
  t60 = t62 + t70 * t112;
  t186 = (in2[6] + -in2[0]) + t76 * t112;
  t117 = t61 + t155;
  t118 = (in2[8] + -in2[2]) + t71 * t112;
  t4 = 1.0 / t4 * (t20 * t20 + -(t21 * t21)) + t18 * t18 * (t43 * t43) * ((t68 -
    1.0) * (t68 - 1.0)) * 6.0;
  t20 = t115 + in2[9] * t5 * t113;
  t21 = t115 + in2[10] * t6 * t113;
  t212 = t115 + in2[11] * t7 * t113;
  t219_tmp = t7 * t63;
  t219 = (t9 + t141) + t219_tmp * t112;
  t220_tmp = t5 * t64;
  t220 = (t10 + t140) + t220_tmp * t112;
  t61 = t6 * t65;
  t221 = (t8 + t142) + t61 * t112;
  t11 = in2[3] * t112;
  t225 = t11 * t208;
  t12 = in2[4] * t112;
  t226 = t12 * t207;
  t13 = in2[5] * t112;
  t227 = t13 * t206;
  t190 = in2[3] * t183;
  t191 = in2[3] * t186;
  t192 = in2[4] * t184;
  t199 = in2[4] * t117;
  t200 = in2[5] * t60;
  t201 = in2[5] * t118;
  t234 = (((((t71 + t70 * -2.0) + -t145) + in2[5] * -t69 * t112) + in2[3] * t117)
          + t110 * t118) + t11 * t207;
  t235 = (((((t76 + t75 * -2.0) + -t143) + in2[4] * -t71 * t112) + in2[4] * t60)
          + t110 * t186) + t12 * t206;
  t236 = (((((t72 + t74 * -2.0) + -t144) + in2[5] * -t76 * t112) + in2[5] * t183)
          + t110 * t184) + t13 * t208;
  t62 = (((((t74 + t72 * -2.0) + t144) + in2[4] * t69 * t112) + -(in2[3] * t118))
         + t110 * t117) + t11 * t206;
  t118 = (((((t70 + t71 * -2.0) + t145) + in2[5] * t73 * t112) + -(in2[4] * t186))
          + t110 * t60) + t12 * t208;
  t13 = (((((t75 + t76 * -2.0) + t143) + in2[5] * t155) + -(in2[5] * t184)) +
         t110 * t183) + t13 * t207;
  out1[0] = t102;
  out1[1] = t45 + t124;
  out1[2] = t159;
  t11 = (-t69 + -t73) + -t77;
  out1[3] = ((t11 - t199) + t201) + t225;
  out1[4] = t118;
  out1[5] = t236;
  out1[6] = (t52 + t54) + 1.0;
  out1[7] = t148;
  out1[8] = t26 + t123;
  memset(&out1[9], 0, 9U * sizeof(real_T));
  out1[18] = t160;
  out1[19] = t101;
  out1[20] = t47 + t122;
  out1[21] = t234;
  out1[22] = ((t11 + t191) - t200) + t226;
  out1[23] = t13;
  out1[24] = t25 + t124;
  out1[25] = (t50 + t54) + 1.0;
  out1[26] = t146;
  memset(&out1[27], 0, 9U * sizeof(real_T));
  out1[36] = t46 + t123;
  out1[37] = t158;
  out1[38] = t100;
  out1[39] = t62;
  out1[40] = t235;
  out1[41] = ((t11 - t190) + t192) + t227;
  out1[42] = t147;
  out1[43] = t27 + t122;
  out1[44] = (t50 + t52) + 1.0;
  memset(&out1[45], 0, 12U * sizeof(real_T));
  out1[57] = (-t116 + t5 * t63 * t112) + t50 * t112;
  out1[58] = (-t10 + t140) + t6 * t63 * t112;
  out1[59] = t219;
  out1[60] = 0.0;
  out1[61] = 0.0;
  out1[62] = 0.0;
  out1[63] = t20;
  out1[64] = t163;
  out1[65] = -t6 + in2[11] * t5 * t113;
  memset(&out1[66], 0, 9U * sizeof(real_T));
  out1[75] = t220;
  out1[76] = (-t116 + t6 * t64 * t112) + t52 * t112;
  out1[77] = (-t8 + t142) + t7 * t64 * t112;
  out1[78] = 0.0;
  out1[79] = 0.0;
  out1[80] = 0.0;
  out1[81] = -t7 + in2[9] * t6 * t113;
  out1[82] = t21;
  out1[83] = t161;
  memset(&out1[84], 0, 9U * sizeof(real_T));
  out1[93] = (-t9 + t141) + t5 * t65 * t112;
  out1[94] = t221;
  out1[95] = (-t116 + t7 * t65 * t112) + t54 * t112;
  out1[96] = 0.0;
  out1[97] = 0.0;
  out1[98] = 0.0;
  out1[99] = t162;
  out1[100] = -t5 + in2[10] * t7 * t113;
  out1[101] = t212;
  out1[102] = 0.0;
  out1[103] = 0.0;
  out1[104] = 0.0;
  out1[105] = 0.0;
  out1[106] = 0.0;
  out1[107] = 0.0;
  t11 = -in1[1] * t28 * t29;
  t12 = t11 * t182 * 3.1415926535897931;
  out2[0] = t12 * (((in2[3] * t114 - in2[4] * t206) + in2[5] * t207) + t110 *
                   t208);
  out2[1] = t12 * (((in2[4] * t114 + in2[3] * t206) - in2[5] * t208) + t110 *
                   t207);
  t12 = in1[1] * t28 * t29;
  out2[2] = t12 * t182 * 3.1415926535897931 * ((((in1[4] / 3.0 + in2[5] * t114)
    - in2[3] * t207) + in2[4] * t208) + t110 * t206) * -3.0;
  t12 *= t4 * 3.1415926535897931 / 4.0 - t17 * t18 * t29 * t43 * (t68 - 1.0) *
    3.1415926535897931 * 3.0;
  t117 = in2[5] * t64;
  out2[3] = t12 * (((t117 * 2.0 - t61) + t63 * t115) - t5 * t209) * -3.0;
  t60 = in2[3] * t65;
  out2[4] = t12 * (((t60 * 2.0 - t219_tmp) + t64 * t115) - t6 * t209) * -3.0;
  t12 = in2[4] * t63;
  out2[5] = t11 * (t4 * 3.1415926535897931 / 2.0 - in1[33] * t17 * t18 * t43 *
                   (t68 - 1.0) * 3.1415926535897931) * (((t12 * 2.0 - t220_tmp)
    + t65 * t115) - t7 * t209);
  out3[0] = -in1[5] * ((((((((t102 * in2[18] - t102 * in2[24]) - t148 * in2[19])
    + t148 * in2[25]) + t159 * in2[20]) - t159 * in2[26]) + t118 * in2[22]) +
                        t236 * in2[23]) - in2[21] * (((t114 + t199) - t201) -
    t225));
  out3[1] = -in1[6] * ((((((((t101 * in2[19] - t101 * in2[25]) - t146 * in2[20])
    + t146 * in2[26]) + t160 * in2[18]) - t160 * in2[24]) + t234 * in2[21]) +
                        t13 * in2[23]) - in2[22] * (((t114 - t191) + t200) -
    t226));
  out3[2] = -in1[7] * ((((((((t100 * in2[20] - t100 * in2[26]) - t147 * in2[18])
    + t147 * in2[24]) + t158 * in2[19]) - t158 * in2[25]) + t62 * in2[21]) +
                        t235 * in2[22]) - in2[23] * (((t114 + t190) - t192) -
    t227));
  out3[3] = -in1[8] * (((((t163 * in2[28] + t20 * in2[27]) + t219 * in2[23]) -
    in2[29] * (t6 - in2[3] * in2[11] * t113 * 2.0)) - in2[22] * ((t10 + t25 *
    t112) - t12 * t112 * 2.0)) - in2[21] * ((t116 + t40 * t112) - in2[3] * t63 *
    t112 * 2.0));
  out3[4] = -in1[9] * (((((t161 * in2[29] + t21 * in2[28]) + t220 * in2[21]) -
    in2[27] * (t7 - in2[4] * in2[9] * t113 * 2.0)) - in2[23] * ((t8 + t27 * t112)
    - t117 * t112 * 2.0)) - in2[22] * ((t116 + t41 * t112) - in2[4] * t64 * t112
    * 2.0));
  out3[5] = -in1[10] * (((((t162 * in2[27] + t212 * in2[29]) + t221 * in2[22]) -
    in2[28] * (t5 - in2[5] * in2[10] * t113 * 2.0)) - in2[21] * ((t9 + t26 *
    t112) - t60 * t112 * 2.0)) - in2[23] * ((t116 + t42 * t112) - in2[5] * t65 *
    t112 * 2.0));
  out4[0] = 0.0;
  out4[1] = 0.0;
  out4[2] = -t18 * t43 * (t68 - 1.0) * 3.1415926535897931 * (((((in1[21] + in1
    [22]) + in1[23]) + in1[24]) + in1[25]) + in1[26]);
  t118 = in1[23] * in1[19] * t18 * t43 * t66 * (t68 - 1.0) * 3.1415926535897931;
  t11 = in1[24] * in1[19] * t18 * t43 * t66 * (t68 - 1.0) * 3.1415926535897931;
  t12 = in1[25] * in1[19] * t18 * t43 * t66 * (t68 - 1.0) * 3.1415926535897931;
  t13 = in1[26] * in1[19] * t18 * t43 * t66 * (t68 - 1.0) * 3.1415926535897931;
  t60 = in1[21] * in1[19] * t18 * t43 * t66;
  t117 = in1[22] * in1[19] * t18 * t43 * t66;
  out4[3] = ((((t60 * (t68 - 1.0) * 3.1415926535897931 * -0.93771626297577859 -
                t117 * (t68 - 1.0) * 3.1415926535897931 * 0.93771626297577859) +
               t118 * 0.167999098695029) + t11 * 0.76971716428074954) + t12 *
             0.76971716428074932) + t13 * 0.16799909869502891;
  out4[4] = ((((t118 * 0.9857871488499218 + t11 * 0.63838506170774523) - t12 *
               0.63838506170774545) - t13 * 0.9857871488499218) - t60 *
             8.3666002653407556 * (t68 - 1.0) * 3.1415926535897931 *
             0.041522491349480967) + t117 * 8.3666002653407556 * (t68 - 1.0) *
    3.1415926535897931 * 0.041522491349480967;
  out4[5] = 0.0;
  *out6 = 1.0;
}

/* End of code generation (sprdmpF20.c) */
