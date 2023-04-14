/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * massF3.c
 *
 * Code generation for function 'massF3'
 *
 */

/* Include files */
#include "massF3.h"
#include "EOM_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo gc_emlrtRSI = { 56, /* lineNo */
  "massF3",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\massF3.m"/* pathName */
};

/* Function Definitions */
void massF3(const emlrtStack *sp, const real_T in1[34], const real_T in2[36],
            real_T out1[36], real_T out2[108], real_T out3[108], real_T out4[6])
{
  emlrtStack st;
  real_T t10;
  real_T t11;
  real_T t13;
  real_T t14;
  real_T t16;
  real_T t17;
  real_T t35;
  real_T t35_tmp;
  real_T t36;
  real_T t37;
  real_T t38;
  real_T t39;
  real_T t40;
  real_T t41;
  real_T t42;
  real_T t43;
  real_T t44;
  real_T t46;
  real_T t46_tmp;
  real_T t47;
  real_T t5;
  real_T t6;
  real_T t7;
  real_T t8;
  real_T t9;
  st.prev = sp;
  st.tls = sp->tls;

  /* MASSF3 */
  /*     [OUT1,OUT2,OUT3,OUT4] = MASSF3(IN1,IN2,S,DS,T_SYM) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
  /*     15-Jun-2021 01:39:21 */
  t47 = muDoubleScalarCos(in1[20]);
  t43 = muDoubleScalarSin(in1[20]);
  t5 = in1[33] * in1[33];
  t6 = in2[15] * 2.0;
  t7 = in2[16] * 2.0;
  t8 = in2[17] * 2.0;
  t9 = in2[15] * in2[15];
  t10 = in2[16] * in2[16];
  t11 = in2[17] * in2[17];
  t13 = in1[2] * in1[2];
  t14 = in1[3] * in1[3];
  t16 = 1.0 / in1[33];
  t17 = in1[18] * in1[18] * 6.0;
  st.site = &gc_emlrtRSI;
  t36 = ((-t9 + -t10) + -t11) + 1.0;
  if (t36 < 0.0) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  t36 = muDoubleScalarSqrt(t36);
  t35_tmp = in1[4] * in1[0];
  t35 = -(t35_tmp * ((t13 + t17) + -t14) * 3.1415926535897931 / 3.0);
  t37 = 1.0 / t36;
  t39 = t36 * 2.0;
  t38 = muDoubleScalarPower(t37, 3.0);
  t40 = t6 * t37;
  t41 = t7 * t37;
  t42 = t8 * t37;
  t47 = (t14 + -t13) + t17 * (1.0 / (t43 * t43)) * (t5 * (t47 * t47) - 1.0);
  t43 = in2[16] * t40;
  t44 = in2[17] * t40;
  t37 = in2[17] * t41;
  t46_tmp = in2[16] * in2[17];
  t46 = t46_tmp * t6 * t38;
  t36 = t35_tmp * t47 * (in1[4] * in1[4] * t5 / 108.0 + t16 * (t13 * 3.0 + t14 *
    3.0) / 12.0) * 3.1415926535897931 / 3.0;
  out1[0] = t35;
  out1[1] = 0.0;
  out1[2] = 0.0;
  out1[3] = 0.0;
  out1[4] = 0.0;
  out1[5] = 0.0;
  out1[6] = 0.0;
  out1[7] = t35;
  out1[8] = 0.0;
  out1[9] = 0.0;
  out1[10] = 0.0;
  out1[11] = 0.0;
  out1[12] = 0.0;
  out1[13] = 0.0;
  out1[14] = t35;
  out1[15] = 0.0;
  out1[16] = 0.0;
  out1[17] = 0.0;
  out1[18] = 0.0;
  out1[19] = 0.0;
  out1[20] = 0.0;
  out1[21] = t36;
  out1[22] = 0.0;
  out1[23] = 0.0;
  out1[24] = 0.0;
  out1[25] = 0.0;
  out1[26] = 0.0;
  out1[27] = 0.0;
  out1[28] = t36;
  out1[29] = 0.0;
  out1[30] = 0.0;
  out1[31] = 0.0;
  out1[32] = 0.0;
  out1[33] = 0.0;
  out1[34] = 0.0;
  out1[35] = t35_tmp * t16 * t47 * 3.1415926535897931 * (t13 / 2.0 + t14 / 2.0) /
    3.0;
  memset(&out2[0], 0, 72U * sizeof(real_T));
  out2[72] = 1.0;
  out2[73] = 0.0;
  out2[74] = 0.0;
  out2[75] = 0.0;
  out2[76] = 0.0;
  out2[77] = 0.0;
  out2[78] = 0.0;
  out2[79] = 1.0;
  out2[80] = 0.0;
  out2[81] = 0.0;
  out2[82] = 0.0;
  out2[83] = 0.0;
  out2[84] = 0.0;
  out2[85] = 0.0;
  out2[86] = 1.0;
  out2[87] = 0.0;
  out2[88] = 0.0;
  out2[89] = 0.0;
  out2[90] = 0.0;
  out2[91] = 0.0;
  out2[92] = 0.0;
  out2[93] = t39 + in2[15] * t40;
  out2[94] = -t8 + t43;
  out2[95] = t7 + t44;
  out2[96] = 0.0;
  out2[97] = 0.0;
  out2[98] = 0.0;
  out2[99] = t8 + t43;
  out2[100] = t39 + in2[16] * t41;
  out2[101] = -t6 + t37;
  out2[102] = 0.0;
  out2[103] = 0.0;
  out2[104] = 0.0;
  out2[105] = -t7 + t44;
  out2[106] = t6 + t37;
  out2[107] = t39 + in2[17] * t42;
  t37 = t40 + t6 * t10 * t38;
  t47 = t40 + t6 * t11 * t38;
  t43 = t41 + in2[15] * in2[16] * t6 * t38;
  t17 = t41 + t7 * t11 * t38;
  t44 = t42 + in2[15] * in2[17] * t6 * t38;
  t36 = t42 + t46_tmp * t7 * t38;
  memset(&out3[0], 0, 93U * sizeof(real_T));
  out3[93] = (t43 * in2[34] + t44 * in2[35]) + in2[33] * (t40 + t6 * t9 * t38);
  out3[94] = ((t46 + 2.0) * in2[35] + t43 * in2[33]) - in2[34] * (t40 - in2[15] *
    t10 * t38 * 2.0);
  out3[95] = ((t46 - 2.0) * in2[34] + t44 * in2[33]) - in2[35] * (t40 - in2[15] *
    t11 * t38 * 2.0);
  out3[96] = 0.0;
  out3[97] = 0.0;
  out3[98] = 0.0;
  out3[99] = ((t46 - 2.0) * in2[35] + t37 * in2[34]) - in2[33] * (t41 - in2[16] *
    t9 * t38 * 2.0);
  out3[100] = (t37 * in2[33] + t36 * in2[35]) + in2[34] * (t41 + t7 * t10 * t38);
  out3[101] = ((t46 + 2.0) * in2[33] + t36 * in2[34]) - in2[35] * (t41 - in2[16]
    * t11 * t38 * 2.0);
  out3[102] = 0.0;
  out3[103] = 0.0;
  out3[104] = 0.0;
  out3[105] = ((t46 + 2.0) * in2[34] + t47 * in2[35]) - in2[33] * (t42 - in2[17]
    * t9 * t38 * 2.0);
  out3[106] = ((t46 - 2.0) * in2[33] + t17 * in2[35]) - in2[34] * (t42 - in2[17]
    * t10 * t38 * 2.0);
  out3[107] = (t47 * in2[33] + t17 * in2[34]) + in2[35] * (t42 + t8 * t11 * t38);
  out4[0] = in1[12];
  out4[1] = in1[13];
  out4[2] = in1[14];
  out4[3] = 0.0;
  out4[4] = 0.0;
  out4[5] = 0.0;
}

/* End of code generation (massF3.c) */
