/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * rjtipF.c
 *
 * Code generation for function 'rjtipF'
 *
 */

/* Include files */
#include "rjtipF.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo h_emlrtRSI = { 70,  /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\rjtipF.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 71,  /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\rjtipF.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 13,  /* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pName */
};

/* Function Definitions */
void rjtipF(const emlrtStack *sp, const real_T in1[34], const real_T in2[30],
            real_T s, real_T ds, real_T t_sym, real_T out1[30])
{
  emlrtStack st;
  real_T t13;
  real_T t14;
  real_T t15;
  real_T t16;
  real_T t17;
  real_T t18;
  real_T t19;
  real_T t20;
  real_T t21;
  real_T t22;
  real_T t23;
  real_T t3;
  real_T t31;
  real_T t32;
  real_T t33;
  real_T t34;
  real_T t35;
  real_T t36;
  real_T t4;
  real_T t40;
  real_T t41;
  real_T t5;
  real_T t6;
  real_T t7;
  real_T t8;
  real_T t9;
  (void)ds;
  (void)t_sym;
  st.prev = sp;
  st.tls = sp->tls;

  /* RJTIPF */
  /*     OUT1 = RJTIPF(IN1,IN2,S,DS,T_SYM) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
  /*     15-Jun-2021 01:48:24 */
  t3 = in1[4] * in2[6];
  t4 = in1[4] * in2[9];
  t5 = in1[4] * in2[12];
  t6 = in1[4] * in1[4];
  t7 = muDoubleScalarPower(in1[4], 3.0);
  t8 = s * s;
  t9 = muDoubleScalarPower(s, 3.0);
  t13 = in2[0] * t6;
  t14 = in2[2] * t6;
  t15 = in2[1] * t7;
  t16 = in2[4] * t6;
  t17 = in2[3] * t7;
  t18 = in2[5] * t7;
  t19 = in2[7] * t6;
  t20 = in2[8] * t7;
  t21 = in2[10] * t6;
  t22 = in2[11] * t7;
  t23 = in2[13] * t6;
  t6 = in2[14] * t7;
  t31 = (t3 + t19) + t20;
  t32 = (t4 + t21) + t22;
  t33 = (t5 + t23) + t6;
  t34 = t31 * t31;
  t35 = t32 * t32;
  t36 = t33 * t33;
  t40 = (s * t3 + t8 * t19) + t9 * t20;
  t41 = (s * t4 + t8 * t21) + t9 * t22;
  t4 = (s * t5 + t8 * t23) + t9 * t6;
  st.site = &h_emlrtRSI;
  t21 = ((-t34 + -t35) + -t36) + 1.0;
  if (t21 < 0.0) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  t22 = muDoubleScalarSqrt(t21);
  st.site = &i_emlrtRSI;
  t21 = ((-(t40 * t40) - t41 * t41) - t4 * t4) + 1.0;
  if (t21 < 0.0) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  st.site = &i_emlrtRSI;
  if (in1[33] < 0.0) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  out1[0] = t8 * t13 + t9 * t15;
  t20 = t13 + t15;
  out1[1] = t20;
  out1[2] = t8 * t14 + t9 * t17;
  t19 = t14 + t17;
  out1[3] = t19;
  out1[4] = (in1[4] * s + t8 * t16) + t9 * t18;
  t6 = (in1[4] + t16) + t18;
  out1[5] = t6;
  out1[6] = rtNaN;
  t7 = in1[16] * t32;
  t3 = in1[16] * t31;
  out1[7] = (t20 + t3 * t33 * 2.0) + t7 * t22 * 2.0;
  out1[8] = rtNaN;
  out1[9] = (t19 + t7 * t33 * 2.0) - t3 * t22 * 2.0;
  out1[10] = rtNaN;
  out1[11] = (((t6 + in1[16] * t36) + in1[16] * -t34) + in1[16] * -t35) - in1[16]
    * (((t34 + t35) + t36) - 1.0);
  out1[12] = muDoubleScalarSqrt(t21);
  out1[13] = t22;
  out1[14] = t40;
  out1[15] = t31;
  out1[16] = t41;
  out1[17] = t32;
  out1[18] = t4;
  out1[19] = t33;
  out1[20] = rtNaN;
  out1[21] = t22;
  out1[22] = rtNaN;
  out1[23] = t31;
  out1[24] = rtNaN;
  out1[25] = t32;
  out1[26] = rtNaN;
  out1[27] = t33;
  out1[28] = 1.0 / muDoubleScalarSqrt(in1[33]) * in1[3];
  out1[29] = in1[17];
}

/* End of code generation (rjtipF.c) */
