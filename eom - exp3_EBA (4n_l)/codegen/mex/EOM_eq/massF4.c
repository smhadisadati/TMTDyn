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
#include "EOM_eq_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo nc_emlrtRSI = { 48, /* lineNo */
  "massF4",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\massF4.m"/* pathName */
};

/* Function Definitions */
void massF4(const emlrtStack *sp, const real_T in1[34], const real_T in2[48],
            real_T out1[36], real_T out2[144], real_T out3[144], real_T out4[6])
{
  emlrtStack st;
  real_T t11;
  real_T t12;
  real_T t13;
  real_T t21;
  real_T t28;
  real_T t29;
  real_T t30;
  real_T t31;
  real_T t32;
  real_T t33;
  real_T t34;
  real_T t35;
  real_T t38;
  real_T t39;
  real_T t39_tmp;
  real_T t4;
  real_T t5;
  real_T t50;
  real_T t55;
  real_T t6;
  real_T t7;
  real_T t8;
  real_T t9;
  st.prev = sp;
  st.tls = sp->tls;

  /* MASSF4 */
  /*     [OUT1,OUT2,OUT3,OUT4] = MASSF4(IN1,IN2,S,DS,T_SYM) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
  /*     26-Feb-2021 21:07:20 */
  t4 = in2[21] * 2.0;
  t5 = in2[22] * 2.0;
  t6 = in2[23] * 2.0;
  t7 = in2[21] * in2[21];
  t8 = in2[22] * in2[22];
  t9 = in2[23] * in2[23];
  t11 = in1[2] * in1[2];
  t12 = in1[3] * in1[3];
  t13 = 1.0 / in1[33];
  t21 = t11 + -t12;
  t29 = ((-t7 + -t8) + -t9) + 1.0;
  st.site = &nc_emlrtRSI;
  if (t29 < 0.0) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  t29 = muDoubleScalarSqrt(t29);
  t30 = 1.0 / t29;
  t32 = t29 * 2.0;
  t55 = in1[4] * in1[0];
  t28 = -(t55 * (in1[18] * in1[18] * 6.0 + t21) * 3.1415926535897931 / 4.0);
  t31 = muDoubleScalarPower(t30, 3.0);
  t33 = t4 * t30;
  t34 = t5 * t30;
  t35 = t6 * t30;
  t29 = in2[22] * t33;
  t30 = in2[23] * t33;
  t38 = in2[23] * t34;
  t39_tmp = in2[22] * in2[23];
  t39 = t39_tmp * t4 * t31;
  t50 = -(t55 * t21 * (in1[4] * in1[4] * (in1[33] * in1[33]) / 192.0 + t13 *
                       (t11 * 3.0 + t12 * 3.0) / 12.0) * 3.1415926535897931 /
          4.0);
  out1[0] = t28;
  out1[1] = 0.0;
  out1[2] = 0.0;
  out1[3] = 0.0;
  out1[4] = 0.0;
  out1[5] = 0.0;
  out1[6] = 0.0;
  out1[7] = t28;
  out1[8] = 0.0;
  out1[9] = 0.0;
  out1[10] = 0.0;
  out1[11] = 0.0;
  out1[12] = 0.0;
  out1[13] = 0.0;
  out1[14] = t28;
  out1[15] = 0.0;
  out1[16] = 0.0;
  out1[17] = 0.0;
  out1[18] = 0.0;
  out1[19] = 0.0;
  out1[20] = 0.0;
  out1[21] = t50;
  out1[22] = 0.0;
  out1[23] = 0.0;
  out1[24] = 0.0;
  out1[25] = 0.0;
  out1[26] = 0.0;
  out1[27] = 0.0;
  out1[28] = t50;
  out1[29] = 0.0;
  out1[30] = 0.0;
  out1[31] = 0.0;
  out1[32] = 0.0;
  out1[33] = 0.0;
  out1[34] = 0.0;
  out1[35] = t55 * t13 * t21 * 3.1415926535897931 * (t11 / 2.0 + t12 / 2.0) *
    -0.25;
  memset(&out2[0], 0, 108U * sizeof(real_T));
  out2[108] = 1.0;
  out2[109] = 0.0;
  out2[110] = 0.0;
  out2[111] = 0.0;
  out2[112] = 0.0;
  out2[113] = 0.0;
  out2[114] = 0.0;
  out2[115] = 1.0;
  out2[116] = 0.0;
  out2[117] = 0.0;
  out2[118] = 0.0;
  out2[119] = 0.0;
  out2[120] = 0.0;
  out2[121] = 0.0;
  out2[122] = 1.0;
  out2[123] = 0.0;
  out2[124] = 0.0;
  out2[125] = 0.0;
  out2[126] = 0.0;
  out2[127] = 0.0;
  out2[128] = 0.0;
  out2[129] = t32 + in2[21] * t33;
  out2[130] = -t6 + t29;
  out2[131] = t5 + t30;
  out2[132] = 0.0;
  out2[133] = 0.0;
  out2[134] = 0.0;
  out2[135] = t6 + t29;
  out2[136] = t32 + in2[22] * t34;
  out2[137] = -t4 + t38;
  out2[138] = 0.0;
  out2[139] = 0.0;
  out2[140] = 0.0;
  out2[141] = -t5 + t30;
  out2[142] = t4 + t38;
  out2[143] = t32 + in2[23] * t35;
  t30 = t33 + t4 * t8 * t31;
  t38 = t33 + t4 * t9 * t31;
  t50 = t34 + in2[21] * in2[22] * t4 * t31;
  t32 = t34 + t5 * t9 * t31;
  t55 = t35 + in2[21] * in2[23] * t4 * t31;
  t29 = t35 + t39_tmp * t5 * t31;
  memset(&out3[0], 0, 129U * sizeof(real_T));
  out3[129] = (t50 * in2[46] + t55 * in2[47]) + in2[45] * (t33 + t4 * t7 * t31);
  out3[130] = ((t39 + 2.0) * in2[47] + t50 * in2[45]) - in2[46] * (t33 - in2[21]
    * t8 * t31 * 2.0);
  out3[131] = ((t39 - 2.0) * in2[46] + t55 * in2[45]) - in2[47] * (t33 - in2[21]
    * t9 * t31 * 2.0);
  out3[132] = 0.0;
  out3[133] = 0.0;
  out3[134] = 0.0;
  out3[135] = ((t39 - 2.0) * in2[47] + t30 * in2[46]) - in2[45] * (t34 - in2[22]
    * t7 * t31 * 2.0);
  out3[136] = (t30 * in2[45] + t29 * in2[47]) + in2[46] * (t34 + t5 * t8 * t31);
  out3[137] = ((t39 + 2.0) * in2[45] + t29 * in2[46]) - in2[47] * (t34 - in2[22]
    * t9 * t31 * 2.0);
  out3[138] = 0.0;
  out3[139] = 0.0;
  out3[140] = 0.0;
  out3[141] = ((t39 + 2.0) * in2[46] + t38 * in2[47]) - in2[45] * (t35 - in2[23]
    * t7 * t31 * 2.0);
  out3[142] = ((t39 - 2.0) * in2[45] + t32 * in2[47]) - in2[46] * (t35 - in2[23]
    * t8 * t31 * 2.0);
  out3[143] = (t38 * in2[45] + t32 * in2[46]) + in2[47] * (t35 + t6 * t9 * t31);
  out4[0] = in1[12];
  out4[1] = in1[13];
  out4[2] = in1[14];
  out4[3] = 0.0;
  out4[4] = 0.0;
  out4[5] = 0.0;
}

/* End of code generation (massF4.c) */
