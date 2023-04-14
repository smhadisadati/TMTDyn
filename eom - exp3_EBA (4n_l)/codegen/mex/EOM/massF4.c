/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * massF4.c
 *
 * Code generation for function 'massF4'
 *
 */

/* Include files */
#include "massF4.h"
#include "EOM_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo pc_emlrtRSI = { 39, /* lineNo */
  "massF4",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\massF4.m"/* pathName */
};

/* Function Definitions */
void massF4(const emlrtStack *sp, const real_T in1[34], const real_T in2[36],
            real_T out1[36], real_T out2[108], real_T out3[108], real_T out4[6])
{
  emlrtStack st;
  real_T t11;
  real_T t12;
  real_T t2;
  real_T t22;
  real_T t23;
  real_T t24;
  real_T t25;
  real_T t27;
  real_T t28;
  real_T t29;
  real_T t3;
  real_T t30;
  real_T t31;
  real_T t32;
  real_T t35;
  real_T t36;
  real_T t37;
  real_T t37_tmp;
  real_T t4;
  real_T t49;
  real_T t5;
  real_T t54;
  real_T t55;
  real_T t56;
  real_T t57;
  real_T t59;
  real_T t6;
  real_T t63;
  real_T t7;
  real_T t9;
  st.prev = sp;
  st.tls = sp->tls;

  /* MASSF4 */
  /*     [OUT1,OUT2,OUT3,OUT4] = MASSF4(IN1,IN2,S,DS,T_SYM) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
  /*     15-Jun-2021 01:39:21 */
  t2 = in1[16] * in2[17];
  t3 = in1[16] * in1[16];
  t4 = in2[15] * 2.0;
  t5 = in2[16] * 2.0;
  t6 = in2[17] * 2.0;
  t7 = in2[15] * in2[15];
  t9 = in2[16] * in2[16];
  t11 = in2[17] * in2[17];
  t12 = in1[17] * in1[17];
  t22 = ((-t7 + -t9) + -t11) + 1.0;
  st.site = &pc_emlrtRSI;
  if (t22 < 0.0) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  t22 = muDoubleScalarSqrt(t22);
  t3 = in1[15] * t3 / 4.0 + in1[15] * (t3 + t12 * 3.0) / 12.0;
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
  out1[21] = t3;
  out1[22] = 0.0;
  out1[23] = 0.0;
  out1[24] = 0.0;
  out1[25] = 0.0;
  out1[26] = 0.0;
  out1[27] = 0.0;
  out1[28] = t3;
  out1[29] = 0.0;
  out1[30] = 0.0;
  out1[31] = 0.0;
  out1[32] = 0.0;
  out1[33] = 0.0;
  out1[34] = 0.0;
  out1[35] = in1[15] * t12 / 2.0;
  t23 = 1.0 / t22;
  t25 = in1[16] * t22;
  t3 = t22 * 2.0;
  t24 = muDoubleScalarPower(t23, 3.0);
  t27 = t4 * t23;
  t28 = t5 * t23;
  t29 = t6 * t23;
  t63 = in1[16] * in2[15];
  t30 = t63 * t23;
  t57 = in1[16] * in2[16];
  t31 = t57 * t23;
  t32 = t2 * t23;
  t12 = in2[16] * t27;
  t22 = in2[17] * t27;
  t35 = in2[17] * t28;
  t36 = in2[16] * t30;
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
  out2[90] = t2 - t36;
  out2[91] = -t25 + in1[16] * t7 * t23;
  out2[92] = t63 * -2.0;
  out2[93] = t3 + in2[15] * t27;
  out2[94] = -t6 + t12;
  out2[95] = t5 + t22;
  out2[96] = t25 + in1[16] * -t9 * t23;
  out2[97] = t2 + t36;
  out2[98] = t57 * -2.0;
  out2[99] = t6 + t12;
  out2[100] = t3 + in2[16] * t28;
  out2[101] = -t4 + t35;
  out2[102] = t63 - in2[16] * t32;
  out2[103] = t57 + in2[15] * t32;
  out2[104] = 0.0;
  out2[105] = -t5 + t22;
  out2[106] = t4 + t35;
  out2[107] = t3 + in2[17] * t29;
  t37_tmp = in2[16] * in2[17];
  t37 = t37_tmp * t4 * t24;
  t3 = in2[15] * in2[16];
  t12 = t3 * t2 * t24;
  t49 = in1[16] + t12;
  t54 = t30 + t63 * t9 * t24;
  t55 = t31 + t57 * t7 * t24;
  t56 = t32 + t2 * t7 * t24;
  t57 = t32 + t2 * t9 * t24;
  t32 = t27 + t4 * t9 * t24;
  t59 = t27 + t4 * t11 * t24;
  t35 = t28 + t3 * t4 * t24;
  t36 = t28 + t5 * t11 * t24;
  t23 = in2[15] * in2[17];
  t25 = t29 + t23 * t4 * t24;
  t63 = t29 + t37_tmp * t5 * t24;
  t3 = in1[16] + -t12;
  t12 = t55 * in2[33];
  t22 = t54 * in2[34];
  memset(&out3[0], 0, 90U * sizeof(real_T));
  out3[90] = (-t12 - t22) + t3 * in2[35];
  out3[91] = (t55 * in2[34] + t56 * in2[35]) + in2[33] * (t30 * 3.0 + in1[16] *
    muDoubleScalarPower(in2[15], 3.0) * t24);
  out3[92] = in1[16] * in2[33] * -2.0;
  out3[93] = (t35 * in2[34] + t25 * in2[35]) + in2[33] * (t27 + t4 * t7 * t24);
  out3[94] = ((t37 + 2.0) * in2[35] + t35 * in2[33]) - in2[34] * (t27 - in2[15] *
    t9 * t24 * 2.0);
  out3[95] = ((t37 - 2.0) * in2[34] + t25 * in2[33]) - in2[35] * (t27 - in2[15] *
    t11 * t24 * 2.0);
  out3[96] = (-t54 * in2[33] - t57 * in2[35]) - in2[34] * (t31 * 3.0 + in1[16] *
    muDoubleScalarPower(in2[16], 3.0) * t24);
  out3[97] = (t12 + t22) + t49 * in2[35];
  out3[98] = in1[16] * in2[34] * -2.0;
  out3[99] = ((t37 - 2.0) * in2[35] + t32 * in2[34]) - in2[33] * (t28 - in2[16] *
    t7 * t24 * 2.0);
  out3[100] = (t32 * in2[33] + t63 * in2[35]) + in2[34] * (t28 + t5 * t9 * t24);
  out3[101] = ((t37 + 2.0) * in2[33] + t63 * in2[34]) - in2[35] * (t28 - in2[16]
    * t11 * t24 * 2.0);
  out3[102] = (t3 * in2[33] - t57 * in2[34]) - in2[35] * (t31 + t37_tmp * t2 *
    t24);
  out3[103] = (t49 * in2[34] + t56 * in2[33]) + in2[35] * (t30 + t23 * t2 * t24);
  out3[104] = 0.0;
  out3[105] = ((t37 + 2.0) * in2[34] + t59 * in2[35]) - in2[33] * (t29 - in2[17]
    * t7 * t24 * 2.0);
  out3[106] = ((t37 - 2.0) * in2[33] + t36 * in2[35]) - in2[34] * (t29 - in2[17]
    * t9 * t24 * 2.0);
  out3[107] = (t59 * in2[33] + t36 * in2[34]) + in2[35] * (t29 + t6 * t11 * t24);
  out4[0] = in1[12];
  out4[1] = in1[13];
  out4[2] = in1[14];
  out4[3] = 0.0;
  out4[4] = 0.0;
  out4[5] = 0.0;
}

/* End of code generation (massF4.c) */
