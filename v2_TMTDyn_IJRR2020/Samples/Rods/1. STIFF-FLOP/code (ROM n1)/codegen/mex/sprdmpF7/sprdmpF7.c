/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sprdmpF7.c
 *
 * Code generation for function 'sprdmpF7'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "sprdmpF7.h"
#include "sqrt.h"
#include "error.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 40,    /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 41,  /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 42,  /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 43,  /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 48,  /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 58,  /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 73,  /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 78,  /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 112, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 113, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 116, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 118, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 119, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 120, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 125, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 126, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 127, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 130, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 131, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 132, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 136, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 169, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 198, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 226, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 235, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 244,/* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 255,/* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo cb_emlrtRSI = { 256,/* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo db_emlrtRSI = { 49, /* lineNo */
  "power",                             /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

static emlrtRSInfo eb_emlrtRSI = { 61, /* lineNo */
  "power",                             /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

/* Function Definitions */
void sprdmpF7(const emlrtStack *sp, const real_T in1[34], const real_T in2[12],
              real_T s, real_T out1[36], real_T out2[6], real_T out3[6], real_T
              out4[6], real_T out5[3], real_T out6[36], real_T out7[36], real_T *
              out8)
{
  real_T t2;
  real_T t3;
  real_T t4;
  real_T t5;
  real_T t6_tmp;
  real_T t7_tmp;
  real_T t8_tmp;
  real_T t9;
  real_T t10;
  real_T t64;
  real_T t140;
  real_T t11;
  real_T t12_tmp;
  real_T b_t12_tmp;
  real_T t12;
  real_T t14_tmp;
  real_T t200;
  real_T t14;
  real_T t15_tmp;
  real_T t15;
  real_T t16_tmp;
  real_T t132;
  real_T t16;
  real_T t17_tmp;
  real_T b_t17_tmp;
  real_T t18_tmp;
  real_T t21;
  real_T t20;
  real_T t177;
  real_T t22_tmp;
  real_T t22;
  real_T t23;
  real_T t219;
  real_T t25_tmp;
  real_T t25;
  real_T t164;
  real_T t28_tmp;
  real_T b_t28_tmp;
  real_T t28;
  real_T t79;
  real_T t32;
  real_T t33;
  real_T t37;
  real_T t38;
  real_T t40;
  real_T t43_tmp;
  real_T b_t43_tmp;
  real_T t43;
  real_T t47_tmp;
  real_T b_t47_tmp;
  real_T c_t47_tmp;
  real_T t47;
  real_T t48;
  real_T t50;
  real_T t216;
  real_T t52;
  real_T t58;
  real_T t209;
  real_T t62;
  real_T t63;
  real_T t64_tmp;
  real_T t68;
  real_T t71;
  real_T t72;
  real_T t78;
  real_T t80;
  real_T t83_tmp;
  real_T t85;
  real_T t96;
  real_T t97;
  real_T t100_tmp;
  real_T t103;
  real_T t104_tmp;
  real_T b_t104_tmp;
  real_T t107;
  real_T t108;
  real_T t110;
  real_T t111;
  real_T t217;
  real_T t116;
  real_T t215;
  real_T t121;
  real_T t129;
  real_T t135;
  real_T t139;
  real_T t141;
  real_T t148;
  real_T t149;
  real_T t153;
  real_T t158;
  real_T t163;
  real_T t168;
  real_T t169;
  real_T t172;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;

  /* SPRDMPF7 */
  /*     [OUT1,OUT2,OUT3,OUT4,OUT5,OUT6,OUT7,OUT8] = SPRDMPF7(IN1,IN2,S) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.2. */
  /*     04-Jan-2019 13:21:30 */
  st.site = &emlrtRSI;
  b_st.site = &db_emlrtRSI;
  t2 = s * s;
  st.site = &b_emlrtRSI;
  b_st.site = &db_emlrtRSI;
  t3 = in2[3] * in2[3];
  st.site = &c_emlrtRSI;
  b_st.site = &db_emlrtRSI;
  t4 = in2[4] * in2[4];
  st.site = &d_emlrtRSI;
  b_st.site = &db_emlrtRSI;
  t5 = in2[5] * in2[5];
  t6_tmp = t2 * t3;
  t7_tmp = t2 * t4;
  t8_tmp = t2 * t5;
  t9 = ((-t6_tmp - t7_tmp) - t8_tmp) + 1.0;
  t10 = t9;
  st.site = &e_emlrtRSI;
  b_sqrt(&st, &t10);
  t64 = in2[3] * in2[4];
  t140 = t64 * s * t2;
  t11 = t140 * 4.0;
  t12_tmp = s * t2;
  b_t12_tmp = t12_tmp * t3;
  t12 = b_t12_tmp * 2.0;
  t14_tmp = in2[3] * in2[5];
  t200 = t14_tmp * s * t2;
  t14 = t200 * 4.0;
  t15_tmp = in2[4] * t2;
  t15 = t15_tmp * t10 * 4.0;
  t16_tmp = in2[4] * in2[5];
  t132 = t16_tmp * s * t2;
  t16 = t132 * 4.0;
  t17_tmp = t12_tmp * t4;
  b_t17_tmp = t17_tmp * 2.0;
  t18_tmp = in2[2] * s * 2.0;
  t21 = t9;
  st.site = &f_emlrtRSI;
  b_sqrt(&st, &t21);
  t20 = 1.0 / t21;
  t21 = s * (t18_tmp + 1.0);
  t177 = in2[1] * in2[3];
  t22_tmp = t177 * s * t2;
  t22 = t21 - t22_tmp * t20 * 2.0;
  t23 = in2[1] * t2 * 2.0;
  t219 = in2[3] * t2;
  t25_tmp = t219 * (t18_tmp + 1.0);
  t25 = t23 + t25_tmp * t20;
  t164 = in2[0] * in2[5];
  t28_tmp = in2[3] * s;
  b_t28_tmp = in2[1] * s;
  t28 = (b_t28_tmp * t10 * 2.0 + t28_tmp * (t18_tmp + 1.0)) - t164 * t2 * 2.0;
  t79 = in2[0] * in2[4];
  t32 = (t10 * (t18_tmp + 1.0) + t79 * t2 * 2.0) - t177 * t2 * 2.0;
  st.site = &g_emlrtRSI;
  b_st.site = &db_emlrtRSI;
  t33 = t2 * t2;
  t37 = (s * t3 * 2.0 + s * t4 * 2.0) + s * t5 * 2.0;
  st.site = &h_emlrtRSI;
  b_st.site = &db_emlrtRSI;
  if (t9 < 0.0) {
    c_st.site = &eb_emlrtRSI;
    error(&c_st);
  }

  t38 = 1.0 / muDoubleScalarPower(t9, 1.5);
  t40 = s * t32;
  t3 = in2[1] * in2[5];
  t43_tmp = in2[4] * s;
  b_t43_tmp = in2[0] * s;
  t43 = (b_t43_tmp * t10 * 2.0 + t3 * t2 * 2.0) - t43_tmp * (t18_tmp + 1.0);
  t47_tmp = in2[5] * s;
  b_t47_tmp = in2[1] * in2[4];
  c_t47_tmp = in2[0] * in2[3];
  t47 = (c_t47_tmp * t2 * 2.0 + b_t47_tmp * t2 * 2.0) + t47_tmp * (t18_tmp + 1.0);
  t48 = s * t47;
  t4 = in2[0] * t2 * 2.0;
  t50 = t4 - t15_tmp * (t18_tmp + 1.0) * t20;
  t216 = t79 * s * t2;
  t52 = t21 + t216 * t20 * 2.0;
  t58 = t64 * t2 * t20 * 2.0 + t140 * t37 * t38;
  t209 = t3 * s * t2;
  t62 = t4 + t209 * t20 * 2.0;
  t63 = s * t43;
  t64_tmp = t164 * s * t2;
  t64 = t23 - t64_tmp * t20 * 2.0;
  t68 = t14_tmp * t2 * t20 * 2.0 + t200 * t37 * t38;
  t71 = t16_tmp * t2 * t20 * 2.0 + t132 * t37 * t38;
  t72 = 1.0 / in1[33];
  t3 = muDoubleScalarCos(in1[20]);
  st.site = &i_emlrtRSI;
  b_st.site = &db_emlrtRSI;
  t4 = in1[2] * in1[2];
  st.site = &j_emlrtRSI;
  b_st.site = &db_emlrtRSI;
  t9 = in1[3] * in1[3];
  st.site = &k_emlrtRSI;
  b_st.site = &db_emlrtRSI;
  t78 = in1[18] * in1[18];
  t79 = muDoubleScalarSin(in1[20]);
  st.site = &l_emlrtRSI;
  b_st.site = &db_emlrtRSI;
  t80 = 1.0 / (t79 * t79);
  st.site = &m_emlrtRSI;
  b_st.site = &db_emlrtRSI;
  st.site = &n_emlrtRSI;
  b_st.site = &db_emlrtRSI;
  t21 = in1[33] * in1[33];
  t83_tmp = t21 * (t3 * t3);
  t85 = t72 * (t4 - t9) - t78 * t80 * (t83_tmp - 1.0) * 6.0;
  st.site = &o_emlrtRSI;
  b_st.site = &db_emlrtRSI;
  st.site = &p_emlrtRSI;
  b_st.site = &db_emlrtRSI;
  st.site = &q_emlrtRSI;
  b_st.site = &db_emlrtRSI;
  st.site = &r_emlrtRSI;
  b_st.site = &db_emlrtRSI;
  st.site = &s_emlrtRSI;
  b_st.site = &db_emlrtRSI;
  st.site = &t_emlrtRSI;
  b_st.site = &db_emlrtRSI;
  t96 = 1.0 / t21 * (t4 * t4 - t9 * t9) + t78 * t78 * (1.0 / muDoubleScalarPower
    (t79, 4.0)) * ((t83_tmp - 1.0) * (t83_tmp - 1.0)) * 6.0;
  t97 = t96 * 3.1415926535897931 / 4.0;
  st.site = &u_emlrtRSI;
  b_st.site = &db_emlrtRSI;
  t100_tmp = s * t28;
  t3 = in2[5] * t2;
  t9 = t3 * t20;
  t103 = ((((t10 * t64 + t100_tmp) + t25_tmp) + t132 * (t18_tmp + 1.0) * t20) -
          t47_tmp * t62) - t9 * t43;
  t104_tmp = t12_tmp * t5;
  b_t104_tmp = t104_tmp * 2.0;
  t23 = t219 * t20;
  t107 = ((t48 + t43_tmp * t25) + t47_tmp * t22) - t23 * t43;
  t108 = t22_tmp * 2.0;
  t3 = t3 * t10 * 4.0;
  t110 = t11 + t3;
  t111 = t14 - t15;
  t4 = t15_tmp * t20;
  t5 = t10 * t52;
  t12_tmp = t43_tmp * t50;
  t22_tmp = t4 * t43;
  t217 = b_t47_tmp * in2[5] * t20 * t33 * 2.0;
  t116 = ((((t40 - t108) + t5) + t12_tmp) + t22_tmp) + t217;
  t215 = s * (((t6_tmp + t7_tmp) + t8_tmp) - 1.0) * 2.0;
  t25_tmp = -t12 + b_t17_tmp;
  t121 = (t25_tmp + b_t104_tmp) + t215;
  st.site = &v_emlrtRSI;
  b_st.site = &db_emlrtRSI;
  t129 = muDoubleScalarPower(muDoubleScalarAbs(((((t103 * in2[11] + t107 * in2[9])
    + t110 * in2[7]) + t111 * in2[8]) - t121 * in2[6]) - t116 * in2[10]), in1[11]
    - 1.0);
  t132 = in2[4] * t2 * (t18_tmp + 1.0);
  t135 = ((t48 + t28_tmp * t50) + t47_tmp * t52) - t4 * t28;
  t139 = ((((t40 + t10 * t22) + t216 * 2.0) + c_t47_tmp * in2[5] * t20 * t33 *
           2.0) - t28_tmp * t25) - t23 * t28;
  t140 = t219 * t10 * 4.0;
  t141 = t16 + t140;
  t14_tmp = t10 * t62;
  t16_tmp = t47_tmp * t64;
  t216 = t9 * t28;
  t79 = t200 * (t18_tmp + 1.0) * t20;
  t148 = ((((t63 - t132) + t14_tmp) + t16_tmp) + t216) + t79;
  t149 = ((t12 - b_t17_tmp) + b_t104_tmp) + t215;
  t153 = t11 - t3;
  st.site = &w_emlrtRSI;
  b_st.site = &db_emlrtRSI;
  t158 = muDoubleScalarPower(muDoubleScalarAbs(((((t135 * in2[10] + t139 * in2[9])
    + t153 * in2[6]) + t141 * in2[8]) - t148 * in2[11]) - t149 * in2[7]), in1[11]
    - 1.0);
  t163 = ((t48 + t28_tmp * t62) + t43_tmp * t64) - t9 * t32;
  t164 = t64_tmp * 2.0;
  t168 = ((((t63 + t10 * t50) + t209 * 2.0) + t177 * in2[4] * t20 * t33 * 2.0) -
          t43_tmp * t52) - t4 * t32;
  t169 = t14 + t15;
  t172 = ((t12 + b_t17_tmp) - b_t104_tmp) + t215;
  t64 = t10 * t25;
  t21 = t28_tmp * t22;
  t9 = t23 * t32;
  t4 = c_t47_tmp * in2[4] * t20 * t33 * 2.0;
  t177 = ((((t100_tmp - t164) + t64) + t21) + t9) + t4;
  t14 = t16 - t140;
  st.site = &x_emlrtRSI;
  b_st.site = &db_emlrtRSI;
  t15 = muDoubleScalarPower(muDoubleScalarAbs(((((t163 * in2[11] + t168 * in2[10])
    + t169 * in2[6]) + t14 * in2[7]) - t172 * in2[8]) - t177 * in2[9]), in1[11]
    - 1.0);
  t3 = t10 * 2.0 + s * t20 * t37;
  t52 = (t3 + t6_tmp * t20 * 2.0) + b_t12_tmp * t37 * t38;
  st.site = &y_emlrtRSI;
  b_st.site = &db_emlrtRSI;
  t50 = muDoubleScalarPower(muDoubleScalarAbs((t52 * in2[9] + t58 * in2[10]) +
    t68 * in2[11]), in1[11] - 1.0);
  t200 = (t3 + t7_tmp * t20 * 2.0) + t17_tmp * t37 * t38;
  st.site = &ab_emlrtRSI;
  b_st.site = &db_emlrtRSI;
  t48 = muDoubleScalarPower(muDoubleScalarAbs((t200 * in2[10] + t58 * in2[9]) +
    t71 * in2[11]), in1[11] - 1.0);
  t209 = (t3 + t8_tmp * t20 * 2.0) + t104_tmp * t37 * t38;
  out1[0] = ((t12 - t215) - b_t17_tmp) - b_t104_tmp;
  out1[1] = t110;
  out1[2] = t111;
  out1[3] = t107;
  out1[4] = ((((-t40 + t108) - t5) - t12_tmp) - t22_tmp) - t217;
  out1[5] = t103;
  out1[6] = t11 - in2[5] * t2 * t10 * 4.0;
  out1[7] = (t25_tmp - t215) - b_t104_tmp;
  out1[8] = t141;
  out1[9] = t139;
  out1[10] = t135;
  out1[11] = ((((-t63 + t132) - t14_tmp) - t16_tmp) - t216) - t79;
  out1[12] = t169;
  out1[13] = t16 - in2[3] * t2 * t10 * 4.0;
  out1[14] = ((-t12 - b_t17_tmp) + b_t104_tmp) - t215;
  out1[15] = ((((t164 - t100_tmp) - t64) - t21) - t9) - t4;
  out1[16] = t168;
  out1[17] = t163;
  out1[18] = 0.0;
  out1[19] = 0.0;
  out1[20] = 0.0;
  out1[21] = t52;
  out1[22] = t58;
  out1[23] = t68;
  out1[24] = 0.0;
  out1[25] = 0.0;
  out1[26] = 0.0;
  out1[27] = t58;
  out1[28] = t200;
  out1[29] = t71;
  out1[30] = 0.0;
  out1[31] = 0.0;
  out1[32] = 0.0;
  out1[33] = t68;
  out1[34] = t71;
  out1[35] = t209;
  st.site = &bb_emlrtRSI;
  b_st.site = &db_emlrtRSI;
  t215 = muDoubleScalarPower(muDoubleScalarAbs((t209 * in2[11] + t68 * in2[9]) +
    t71 * in2[10]), in1[11] - 1.0);
  t21 = in1[33];
  st.site = &cb_emlrtRSI;
  b_sqrt(&st, &t21);
  t216 = 1.0 / t21;
  t3 = t72 * t78 * t80 * (t83_tmp - 1.0) * (in1[19] * in1[19]) *
    3.1415926535897931;
  t217 = t97 - t3 * 3.0;
  t219 = t97 - t3 * 2.9999999999999991;
  t3 = in1[1] * t72;
  t62 = t3 * t85;
  t64_tmp = t62 * 3.1415926535897931;
  out2[0] = t64_tmp * (((t10 * t43 + t47_tmp * t28) - t43_tmp * t32) + t28_tmp *
                       t47) / 3.0;
  out2[1] = t64_tmp * (((t10 * t28 + t28_tmp * t32) - t47_tmp * t43) + t43_tmp *
                       t47) / 3.0;
  out2[2] = t64_tmp * ((((t10 * t32 - t28_tmp * t28) + t43_tmp * t43) + t47_tmp *
                        t47) - 1.0);
  out2[3] = t3 * t217 * (in2[3] * t10 * 2.0 + t28_tmp * t20 * t37);
  out2[4] = t3 * t219 * (in2[4] * t10 * 2.0 + t43_tmp * t20 * t37);
  t64_tmp = t3 * t96;
  out2[5] = t64_tmp * 3.1415926535897931 * (in2[5] * t10 * 2.0 + t47_tmp * t20 *
    t37) / 6.0;
  t140 = in1[5] * t121 * t129;
  t164 = in1[5] * t116 * t129;
  t23 = -in1[5] * t103 * t129;
  out3[0] = ((((t23 * in2[11] - in1[5] * t107 * t129 * in2[9]) - in1[5] * t110 *
               t129 * in2[7]) - in1[5] * t111 * t129 * in2[8]) + t164 * in2[10])
    + t140 * in2[6];
  t14_tmp = in1[6] * t149 * t158;
  t16_tmp = -in1[6] * t135 * t158;
  t25_tmp = in1[6] * t148 * t158;
  out3[1] = ((((t16_tmp * in2[10] - in1[6] * t139 * t158 * in2[9]) - in1[6] *
               t141 * t158 * in2[8]) + t14_tmp * in2[7]) + t25_tmp * in2[11]) -
    in1[6] * t153 * t158 * in2[6];
  t132 = in1[7] * t172 * t15;
  t5 = in1[7] * t177 * t15;
  t12_tmp = -in1[7] * t163 * t15;
  out3[2] = ((((t12_tmp * in2[11] - in1[7] * t169 * t15 * in2[6]) - in1[7] *
               t168 * t15 * in2[10]) + t132 * in2[8]) + t5 * in2[9]) - in1[7] *
    t14 * t15 * in2[7];
  t22_tmp = -in1[8] * t58 * t50;
  out3[3] = (t22_tmp * in2[10] - in1[8] * t68 * t50 * in2[11]) - in1[8] * t52 *
    t50 * in2[9];
  t15_tmp = -in1[9] * t58 * t48;
  out3[4] = (t15_tmp * in2[9] - in1[9] * t71 * t48 * in2[11]) - in1[9] * t200 *
    t48 * in2[10];
  b_t47_tmp = -in1[10] * t68 * t215;
  out3[5] = (b_t47_tmp * in2[9] - in1[10] * t71 * t215 * in2[10]) - in1[10] *
    t209 * t215 * in2[11];
  out4[0] = 0.0;
  out4[1] = 0.0;
  out4[2] = -t78 * t80 * (t83_tmp - 1.0) * 3.1415926535897931 * (((((in1[21] +
    in1[22]) + in1[23]) + in1[24]) + in1[25]) + in1[26]);
  t4 = in1[21] * in1[19] * t78 * t80 * (t83_tmp - 1.0) * t216 *
    3.1415926535897931;
  t9 = in1[22] * in1[19] * t78 * t80 * (t83_tmp - 1.0) * t216 *
    3.1415926535897931;
  t79 = in1[23] * in1[19] * t78 * t80 * (t83_tmp - 1.0) * t216 *
    3.1415926535897931;
  t21 = in1[24] * in1[19] * t78 * t80 * (t83_tmp - 1.0) * t216 *
    3.1415926535897931;
  t64 = in1[25] * in1[19] * t78 * t80 * (t83_tmp - 1.0) * t216 *
    3.1415926535897931;
  t3 = in1[26] * in1[19] * t78 * t80 * (t83_tmp - 1.0) * t216 *
    3.1415926535897931;
  out4[3] = ((((t4 * -0.91522491349480972 - t9 * 0.91522491349480972) + t79 *
               0.1086532638769295) + t21 * 0.80657164961788008) + t64 *
             0.80657164961787986) + t3 * 0.1086532638769295;
  out4[4] = ((((t4 * -0.40294336787992679 + t9 * 0.40294336787992691) + t79 *
               0.99407970920288391) + t21 * 0.59113634132295712) - t64 *
             0.59113634132295745) - t3 * 0.99407970920288391;
  out4[5] = 0.0;
  out5[0] = b_t43_tmp * 2.0;
  out5[1] = b_t28_tmp * 2.0;
  out5[2] = t18_tmp + 1.0;
  out6[0] = t62 * t121 * 3.1415926535897931 / 3.0;
  out6[1] = t62 * t153 * 3.1415926535897931 * -0.33333333333333331;
  t9 = -in1[1] * t72;
  t4 = t9 * t85;
  out6[2] = t4 * t169 * 3.1415926535897931;
  out6[3] = 0.0;
  out6[4] = 0.0;
  out6[5] = 0.0;
  out6[6] = t62 * t110 * 3.1415926535897931 * -0.33333333333333331;
  out6[7] = t62 * t149 * 3.1415926535897931 / 3.0;
  out6[8] = t4 * t14 * 3.1415926535897931;
  out6[9] = 0.0;
  out6[10] = 0.0;
  out6[11] = 0.0;
  out6[12] = t62 * t111 * 3.1415926535897931 * -0.33333333333333331;
  out6[13] = t62 * t141 * 3.1415926535897931 * -0.33333333333333331;
  out6[14] = t62 * t172 * 3.1415926535897931;
  out6[15] = 0.0;
  out6[16] = 0.0;
  out6[17] = 0.0;
  out6[18] = t62 * t107 * 3.1415926535897931 * -0.33333333333333331;
  out6[19] = t62 * t139 * 3.1415926535897931 * -0.33333333333333331;
  out6[20] = t62 * t177 * 3.1415926535897931;
  out6[21] = t9 * t52 * t217;
  t3 = -in1[1] * t58 * t72;
  out6[22] = t3 * t219;
  out6[23] = in1[1] * t68 * t72 * t96 * 3.1415926535897931 *
    -0.16666666666666666;
  out6[24] = t62 * t116 * 3.1415926535897931 / 3.0;
  out6[25] = t62 * t135 * 3.1415926535897931 * -0.33333333333333331;
  out6[26] = t4 * t168 * 3.1415926535897931;
  out6[27] = t3 * t217;
  out6[28] = t9 * t200 * t219;
  out6[29] = in1[1] * t71 * t72 * t96 * 3.1415926535897931 *
    -0.16666666666666666;
  out6[30] = t62 * t103 * 3.1415926535897931 * -0.33333333333333331;
  out6[31] = t62 * t148 * 3.1415926535897931 / 3.0;
  out6[32] = t4 * t163 * 3.1415926535897931;
  out6[33] = -in1[1] * t68 * t72 * t217;
  out6[34] = -in1[1] * t71 * t72 * t219;
  out6[35] = t64_tmp * t209 * 3.1415926535897931 * -0.16666666666666666;
  out7[0] = t140;
  out7[1] = -in1[6] * t153 * t158;
  out7[2] = -in1[7] * t169 * t15;
  out7[3] = 0.0;
  out7[4] = 0.0;
  out7[5] = 0.0;
  out7[6] = -in1[5] * t110 * t129;
  out7[7] = t14_tmp;
  out7[8] = -in1[7] * t14 * t15;
  out7[9] = 0.0;
  out7[10] = 0.0;
  out7[11] = 0.0;
  out7[12] = -in1[5] * t111 * t129;
  out7[13] = -in1[6] * t141 * t158;
  out7[14] = t132;
  out7[15] = 0.0;
  out7[16] = 0.0;
  out7[17] = 0.0;
  out7[18] = -in1[5] * t107 * t129;
  out7[19] = -in1[6] * t139 * t158;
  out7[20] = t5;
  out7[21] = -in1[8] * t52 * t50;
  out7[22] = t15_tmp;
  out7[23] = b_t47_tmp;
  out7[24] = t164;
  out7[25] = t16_tmp;
  out7[26] = -in1[7] * t168 * t15;
  out7[27] = t22_tmp;
  out7[28] = -in1[9] * t200 * t48;
  out7[29] = -in1[10] * t71 * t215;
  out7[30] = t23;
  out7[31] = t25_tmp;
  out7[32] = t12_tmp;
  out7[33] = -in1[8] * t68 * t50;
  out7[34] = -in1[9] * t71 * t48;
  out7[35] = -in1[10] * t209 * t215;
  *out8 = 1.0;
}

/* End of code generation (sprdmpF7.c) */
