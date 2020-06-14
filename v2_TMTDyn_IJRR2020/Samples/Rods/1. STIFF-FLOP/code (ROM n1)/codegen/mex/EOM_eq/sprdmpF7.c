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
#include "EOM_eq.h"
#include "sprdmpF7.h"
#include "sqrt.h"
#include "error.h"

/* Variable Definitions */
static emlrtRSInfo l_emlrtRSI = { 40,  /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 41,  /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 42,  /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 43,  /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 48,  /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 58,  /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 73,  /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 78,  /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 112, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 113, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 116, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 118, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 119, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 120, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 125,/* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 126,/* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo cb_emlrtRSI = { 127,/* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo db_emlrtRSI = { 130,/* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo eb_emlrtRSI = { 131,/* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo fb_emlrtRSI = { 132,/* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 136,/* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo hb_emlrtRSI = { 169,/* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo ib_emlrtRSI = { 198,/* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo jb_emlrtRSI = { 226,/* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo kb_emlrtRSI = { 235,/* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo lb_emlrtRSI = { 244,/* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo mb_emlrtRSI = { 255,/* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo nb_emlrtRSI = { 256,/* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo ob_emlrtRSI = { 49, /* lineNo */
  "power",                             /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

static emlrtRSInfo pb_emlrtRSI = { 61, /* lineNo */
  "power",                             /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

/* Function Definitions */
void b_sprdmpF7(const emlrtStack *sp, const real_T in1[34], const real_T in2[12],
                real_T s, real_T out1[36], real_T out2[6], real_T out3[6],
                real_T out4[6])
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
  real_T t215;
  real_T t62;
  real_T t11;
  real_T t172;
  real_T t12_tmp;
  real_T t12;
  real_T t197;
  real_T t153;
  real_T t14;
  real_T t168;
  real_T t15;
  real_T t182;
  real_T t177;
  real_T t16;
  real_T t17_tmp;
  real_T b_t17_tmp;
  real_T t158;
  real_T t32_tmp;
  real_T t20;
  real_T t21;
  real_T t22_tmp;
  real_T t164;
  real_T t22;
  real_T t23;
  real_T t163;
  real_T t186;
  real_T t25;
  real_T t206;
  real_T t28_tmp;
  real_T t28;
  real_T t32;
  real_T t33;
  real_T t37;
  real_T t38;
  real_T t40;
  real_T t43_tmp;
  real_T t43;
  real_T t47_tmp;
  real_T b_t47_tmp;
  real_T c_t47_tmp;
  real_T t47;
  real_T t48;
  real_T t50;
  real_T t52;
  real_T t58;
  real_T t62_tmp;
  real_T t63;
  real_T t68;
  real_T t71;
  real_T t72;
  real_T t74;
  real_T t75;
  real_T t78;
  real_T t80;
  real_T t83_tmp;
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
  real_T t116_tmp;
  real_T b_t116_tmp;
  real_T c_t116_tmp;
  real_T d_t116_tmp;
  real_T t116;
  real_T t120_tmp;
  real_T t121_tmp;
  real_T t121;
  real_T t129;
  real_T t132;
  real_T t135;
  real_T t139;
  real_T t141;
  real_T t148_tmp;
  real_T b_t148_tmp;
  real_T c_t148_tmp;
  real_T t148;
  real_T t149;
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
  st.site = &l_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  t2 = s * s;
  st.site = &m_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  t3 = in2[3] * in2[3];
  st.site = &n_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  t4 = in2[4] * in2[4];
  st.site = &o_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  t5 = in2[5] * in2[5];
  t6_tmp = t2 * t3;
  t7_tmp = t2 * t4;
  t8_tmp = t2 * t5;
  t9 = ((-t6_tmp - t7_tmp) - t8_tmp) + 1.0;
  t10 = t9;
  st.site = &p_emlrtRSI;
  b_sqrt(&st, &t10);
  t215 = in2[3] * in2[4];
  t62 = t215 * s * t2;
  t11 = t62 * 4.0;
  t172 = s * t2;
  t12_tmp = t172 * t3;
  t12 = t12_tmp * 2.0;
  t197 = in2[3] * in2[5];
  t153 = t197 * s * t2;
  t14 = t153 * 4.0;
  t168 = in2[4] * t2;
  t15 = t168 * t10 * 4.0;
  t182 = in2[4] * in2[5];
  t177 = t182 * s * t2;
  t16 = t177 * 4.0;
  t17_tmp = t172 * t4;
  b_t17_tmp = t17_tmp * 2.0;
  t158 = in2[2] * s * 2.0;
  t32_tmp = t9;
  st.site = &q_emlrtRSI;
  b_sqrt(&st, &t32_tmp);
  t20 = 1.0 / t32_tmp;
  t21 = s * (t158 + 1.0);
  t22_tmp = in2[1] * in2[3];
  t164 = t22_tmp * s * t2;
  t22 = t21 - t164 * t20 * 2.0;
  t23 = in2[1] * t2 * 2.0;
  t163 = in2[3] * t2;
  t186 = t163 * (t158 + 1.0);
  t25 = t23 + t186 * t20;
  t206 = in2[0] * in2[5];
  t28_tmp = in2[3] * s;
  t28 = (in2[1] * s * t10 * 2.0 + t28_tmp * (t158 + 1.0)) - t206 * t2 * 2.0;
  t32_tmp = in2[0] * in2[4];
  t32 = (t10 * (t158 + 1.0) + t32_tmp * t2 * 2.0) - t22_tmp * t2 * 2.0;
  st.site = &r_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  t33 = t2 * t2;
  t37 = (s * t3 * 2.0 + s * t4 * 2.0) + s * t5 * 2.0;
  st.site = &s_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  if (t9 < 0.0) {
    c_st.site = &pb_emlrtRSI;
    error(&c_st);
  }

  t38 = 1.0 / muDoubleScalarPower(t9, 1.5);
  t40 = s * t32;
  t3 = in2[1] * in2[5];
  t43_tmp = in2[4] * s;
  t43 = (in2[0] * s * t10 * 2.0 + t3 * t2 * 2.0) - t43_tmp * (t158 + 1.0);
  t47_tmp = in2[5] * s;
  b_t47_tmp = in2[1] * in2[4];
  c_t47_tmp = in2[0] * in2[3];
  t47 = (c_t47_tmp * t2 * 2.0 + b_t47_tmp * t2 * 2.0) + t47_tmp * (t158 + 1.0);
  t48 = s * t47;
  t4 = in2[0] * t2 * 2.0;
  t50 = t4 - t168 * (t158 + 1.0) * t20;
  t32_tmp = t32_tmp * s * t2;
  t52 = t21 + t32_tmp * t20 * 2.0;
  t58 = t215 * t2 * t20 * 2.0 + t62 * t37 * t38;
  t62_tmp = t3 * s * t2;
  t62 = t4 + t62_tmp * t20 * 2.0;
  t63 = s * t43;
  t206 = t206 * s * t2;
  t21 = t23 - t206 * t20 * 2.0;
  t68 = t197 * t2 * t20 * 2.0 + t153 * t37 * t38;
  t71 = t182 * t2 * t20 * 2.0 + t177 * t37 * t38;
  t72 = 1.0 / in1[33];
  t3 = muDoubleScalarCos(in1[20]);
  st.site = &t_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  t74 = in1[2] * in1[2];
  st.site = &u_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  t75 = in1[3] * in1[3];
  st.site = &v_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  t78 = in1[18] * in1[18];
  t4 = muDoubleScalarSin(in1[20]);
  st.site = &w_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  t80 = 1.0 / (t4 * t4);
  st.site = &x_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  st.site = &y_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  t9 = in1[33] * in1[33];
  t83_tmp = t9 * (t3 * t3);
  st.site = &ab_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  st.site = &bb_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  st.site = &cb_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  st.site = &db_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  st.site = &eb_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  st.site = &fb_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  t96 = 1.0 / t9 * (t74 * t74 - t75 * t75) + t78 * t78 * (1.0 /
    muDoubleScalarPower(t4, 4.0)) * ((t83_tmp - 1.0) * (t83_tmp - 1.0)) * 6.0;
  t97 = t96 * 3.1415926535897931 / 4.0;
  st.site = &gb_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  t100_tmp = s * t28;
  t3 = in2[5] * t2;
  t9 = t3 * t20;
  t103 = ((((t10 * t21 + t100_tmp) + t186) + t177 * (t158 + 1.0) * t20) -
          t47_tmp * t62) - t9 * t43;
  t104_tmp = t172 * t5;
  b_t104_tmp = t104_tmp * 2.0;
  t215 = t163 * t20;
  t107 = ((t48 + t43_tmp * t25) + t47_tmp * t22) - t215 * t43;
  t108 = t164 * 2.0;
  t3 = t3 * t10 * 4.0;
  t110 = t11 + t3;
  t111 = t14 - t15;
  t4 = t168 * t20;
  t116_tmp = t10 * t52;
  b_t116_tmp = t43_tmp * t50;
  c_t116_tmp = t4 * t43;
  d_t116_tmp = b_t47_tmp * in2[5] * t20 * t33 * 2.0;
  t116 = ((((t40 - t108) + t116_tmp) + b_t116_tmp) + c_t116_tmp) + d_t116_tmp;
  t120_tmp = s * (((t6_tmp + t7_tmp) + t8_tmp) - 1.0) * 2.0;
  t121_tmp = -t12 + b_t17_tmp;
  t121 = (t121_tmp + b_t104_tmp) + t120_tmp;
  st.site = &hb_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  t129 = muDoubleScalarPower(muDoubleScalarAbs(((((t103 * in2[11] + t107 * in2[9])
    + t110 * in2[7]) + t111 * in2[8]) - t121 * in2[6]) - t116 * in2[10]), in1[11]
    - 1.0);
  t132 = in2[4] * t2 * (t158 + 1.0);
  t135 = ((t48 + t28_tmp * t50) + t47_tmp * t52) - t4 * t28;
  t139 = ((((t40 + t10 * t22) + t32_tmp * 2.0) + c_t47_tmp * in2[5] * t20 * t33 *
           2.0) - t28_tmp * t25) - t215 * t28;
  t23 = t163 * t10 * 4.0;
  t141 = t16 + t23;
  t148_tmp = t10 * t62;
  b_t148_tmp = t47_tmp * t21;
  c_t148_tmp = t9 * t28;
  b_t47_tmp = t153 * (t158 + 1.0) * t20;
  t148 = ((((t63 - t132) + t148_tmp) + b_t148_tmp) + c_t148_tmp) + b_t47_tmp;
  t149 = ((t12 - b_t17_tmp) + b_t104_tmp) + t120_tmp;
  t153 = t11 - t3;
  st.site = &ib_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  t158 = muDoubleScalarPower(muDoubleScalarAbs(((((t135 * in2[10] + t139 * in2[9])
    + t153 * in2[6]) + t141 * in2[8]) - t148 * in2[11]) - t149 * in2[7]), in1[11]
    - 1.0);
  t163 = ((t48 + t28_tmp * t62) + t43_tmp * t21) - t9 * t32;
  t164 = t206 * 2.0;
  t168 = ((((t63 + t10 * t50) + t62_tmp * 2.0) + t22_tmp * in2[4] * t20 * t33 *
           2.0) - t43_tmp * t52) - t4 * t32;
  t5 = t14 + t15;
  t172 = ((t12 + b_t17_tmp) - b_t104_tmp) + t120_tmp;
  t21 = t10 * t25;
  t32_tmp = t28_tmp * t22;
  t215 *= t32;
  t9 = c_t47_tmp * in2[4] * t20 * t33 * 2.0;
  t177 = ((((t100_tmp - t164) + t21) + t32_tmp) + t215) + t9;
  t182 = t16 - t23;
  st.site = &jb_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  t186 = muDoubleScalarPower(muDoubleScalarAbs(((((t163 * in2[11] + t168 * in2
    [10]) + t5 * in2[6]) + t182 * in2[7]) - t172 * in2[8]) - t177 * in2[9]),
    in1[11] - 1.0);
  t3 = t10 * 2.0 + s * t20 * t37;
  t23 = (t3 + t6_tmp * t20 * 2.0) + t12_tmp * t37 * t38;
  st.site = &kb_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  t197 = muDoubleScalarPower(muDoubleScalarAbs((t23 * in2[9] + t58 * in2[10]) +
    t68 * in2[11]), in1[11] - 1.0);
  t62 = (t3 + t7_tmp * t20 * 2.0) + t17_tmp * t37 * t38;
  st.site = &lb_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  t206 = muDoubleScalarPower(muDoubleScalarAbs((t62 * in2[10] + t58 * in2[9]) +
    t71 * in2[11]), in1[11] - 1.0);
  t4 = (t3 + t8_tmp * t20 * 2.0) + t104_tmp * t37 * t38;
  out1[0] = ((t12 - t120_tmp) - b_t17_tmp) - b_t104_tmp;
  out1[1] = t110;
  out1[2] = t111;
  out1[3] = t107;
  out1[4] = ((((-t40 + t108) - t116_tmp) - b_t116_tmp) - c_t116_tmp) -
    d_t116_tmp;
  out1[5] = t103;
  out1[6] = t11 - in2[5] * t2 * t10 * 4.0;
  out1[7] = (t121_tmp - t120_tmp) - b_t104_tmp;
  out1[8] = t141;
  out1[9] = t139;
  out1[10] = t135;
  out1[11] = ((((-t63 + t132) - t148_tmp) - b_t148_tmp) - c_t148_tmp) -
    b_t47_tmp;
  out1[12] = t5;
  out1[13] = t16 - in2[3] * t2 * t10 * 4.0;
  out1[14] = ((-t12 - b_t17_tmp) + b_t104_tmp) - t120_tmp;
  out1[15] = ((((t164 - t100_tmp) - t21) - t32_tmp) - t215) - t9;
  out1[16] = t168;
  out1[17] = t163;
  out1[18] = 0.0;
  out1[19] = 0.0;
  out1[20] = 0.0;
  out1[21] = t23;
  out1[22] = t58;
  out1[23] = t68;
  out1[24] = 0.0;
  out1[25] = 0.0;
  out1[26] = 0.0;
  out1[27] = t58;
  out1[28] = t62;
  out1[29] = t71;
  out1[30] = 0.0;
  out1[31] = 0.0;
  out1[32] = 0.0;
  out1[33] = t68;
  out1[34] = t71;
  out1[35] = t4;
  st.site = &mb_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  t215 = muDoubleScalarPower(muDoubleScalarAbs((t4 * in2[11] + t68 * in2[9]) +
    t71 * in2[10]), in1[11] - 1.0);
  t32_tmp = in1[33];
  st.site = &nb_emlrtRSI;
  b_sqrt(&st, &t32_tmp);
  t3 = 1.0 / t32_tmp;
  t21 = in1[1] * t72;
  t32_tmp = t21 * (t72 * (t74 - t75) - t78 * t80 * (t83_tmp - 1.0) * 6.0) *
    3.1415926535897931;
  out2[0] = t32_tmp * (((t10 * t43 + t47_tmp * t28) - t43_tmp * t32) + t28_tmp *
                       t47) / 3.0;
  out2[1] = t32_tmp * (((t10 * t28 + t28_tmp * t32) - t47_tmp * t43) + t43_tmp *
                       t47) / 3.0;
  out2[2] = t32_tmp * ((((t10 * t32 - t28_tmp * t28) + t43_tmp * t43) + t47_tmp *
                        t47) - 1.0);
  t32_tmp = t72 * t78 * t80 * (t83_tmp - 1.0) * (in1[19] * in1[19]) *
    3.1415926535897931;
  out2[3] = t21 * (t97 - t32_tmp * 3.0) * (in2[3] * t10 * 2.0 + t28_tmp * t20 *
    t37);
  out2[4] = t21 * (t97 - t32_tmp * 2.9999999999999991) * (in2[4] * t10 * 2.0 +
    t43_tmp * t20 * t37);
  out2[5] = t21 * t96 * 3.1415926535897931 * (in2[5] * t10 * 2.0 + t47_tmp * t20
    * t37) / 6.0;
  out3[0] = ((((-in1[5] * t103 * t129 * in2[11] - in1[5] * t107 * t129 * in2[9])
               - in1[5] * t110 * t129 * in2[7]) - in1[5] * t111 * t129 * in2[8])
             + in1[5] * t116 * t129 * in2[10]) + in1[5] * t121 * t129 * in2[6];
  out3[1] = ((((-in1[6] * t135 * t158 * in2[10] - in1[6] * t139 * t158 * in2[9])
               - in1[6] * t141 * t158 * in2[8]) + in1[6] * t149 * t158 * in2[7])
             + in1[6] * t148 * t158 * in2[11]) - in1[6] * t153 * t158 * in2[6];
  out3[2] = ((((-in1[7] * t163 * t186 * in2[11] - in1[7] * t5 * t186 * in2[6]) -
               in1[7] * t168 * t186 * in2[10]) + in1[7] * t172 * t186 * in2[8])
             + in1[7] * t177 * t186 * in2[9]) - in1[7] * t182 * t186 * in2[7];
  out3[3] = (-in1[8] * t58 * t197 * in2[10] - in1[8] * t68 * t197 * in2[11]) -
    in1[8] * t23 * t197 * in2[9];
  out3[4] = (-in1[9] * t58 * t206 * in2[9] - in1[9] * t71 * t206 * in2[11]) -
    in1[9] * t62 * t206 * in2[10];
  out3[5] = (-in1[10] * t68 * t215 * in2[9] - in1[10] * t71 * t215 * in2[10]) -
    in1[10] * t4 * t215 * in2[11];
  out4[0] = 0.0;
  out4[1] = 0.0;
  out4[2] = -t78 * t80 * (t83_tmp - 1.0) * 3.1415926535897931 * (((((in1[21] +
    in1[22]) + in1[23]) + in1[24]) + in1[25]) + in1[26]);
  t4 = in1[21] * in1[19] * t78 * t80 * (t83_tmp - 1.0) * t3 * 3.1415926535897931;
  t9 = in1[22] * in1[19] * t78 * t80 * (t83_tmp - 1.0) * t3 * 3.1415926535897931;
  t32_tmp = in1[23] * in1[19] * t78 * t80 * (t83_tmp - 1.0) * t3 *
    3.1415926535897931;
  t21 = in1[24] * in1[19] * t78 * t80 * (t83_tmp - 1.0) * t3 *
    3.1415926535897931;
  t215 = in1[25] * in1[19] * t78 * t80 * (t83_tmp - 1.0) * t3 *
    3.1415926535897931;
  t3 = in1[26] * in1[19] * t78 * t80 * (t83_tmp - 1.0) * t3 * 3.1415926535897931;
  out4[3] = ((((t4 * -0.91522491349480972 - t9 * 0.91522491349480972) + t32_tmp *
               0.1086532638769295) + t21 * 0.80657164961788008) + t215 *
             0.80657164961787986) + t3 * 0.1086532638769295;
  out4[4] = ((((t4 * -0.40294336787992679 + t9 * 0.40294336787992691) + t32_tmp *
               0.99407970920288391) + t21 * 0.59113634132295712) - t215 *
             0.59113634132295745) - t3 * 0.99407970920288391;
  out4[5] = 0.0;
}

void sprdmpF7(const emlrtStack *sp, const real_T in1[34], const real_T in2[12],
              real_T s, real_T out1[36], real_T out2[6], real_T out3[6], real_T
              out4[6], real_T out5[3])
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
  real_T t215;
  real_T t62;
  real_T t11;
  real_T t172;
  real_T t12_tmp;
  real_T t12;
  real_T t197;
  real_T t153;
  real_T t14;
  real_T t168;
  real_T t15;
  real_T t182;
  real_T t177;
  real_T t16;
  real_T t17_tmp;
  real_T b_t17_tmp;
  real_T t18_tmp;
  real_T t32_tmp;
  real_T t20;
  real_T t21;
  real_T t22_tmp;
  real_T t164;
  real_T t22;
  real_T t23;
  real_T t163;
  real_T t186;
  real_T t25;
  real_T t206;
  real_T t28_tmp;
  real_T b_t28_tmp;
  real_T t28;
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
  real_T t52;
  real_T t58;
  real_T t62_tmp;
  real_T t63;
  real_T t68;
  real_T t71;
  real_T t72;
  real_T t74;
  real_T t75;
  real_T t78;
  real_T t80;
  real_T t83_tmp;
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
  real_T t116_tmp;
  real_T b_t116_tmp;
  real_T c_t116_tmp;
  real_T d_t116_tmp;
  real_T t116;
  real_T t120_tmp;
  real_T t121_tmp;
  real_T t121;
  real_T t129;
  real_T t132;
  real_T t135;
  real_T t139;
  real_T t141;
  real_T t148_tmp;
  real_T b_t148_tmp;
  real_T c_t148_tmp;
  real_T t148;
  real_T t149;
  real_T t158;
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
  st.site = &l_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  t2 = s * s;
  st.site = &m_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  t3 = in2[3] * in2[3];
  st.site = &n_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  t4 = in2[4] * in2[4];
  st.site = &o_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  t5 = in2[5] * in2[5];
  t6_tmp = t2 * t3;
  t7_tmp = t2 * t4;
  t8_tmp = t2 * t5;
  t9 = ((-t6_tmp - t7_tmp) - t8_tmp) + 1.0;
  t10 = t9;
  st.site = &p_emlrtRSI;
  b_sqrt(&st, &t10);
  t215 = in2[3] * in2[4];
  t62 = t215 * s * t2;
  t11 = t62 * 4.0;
  t172 = s * t2;
  t12_tmp = t172 * t3;
  t12 = t12_tmp * 2.0;
  t197 = in2[3] * in2[5];
  t153 = t197 * s * t2;
  t14 = t153 * 4.0;
  t168 = in2[4] * t2;
  t15 = t168 * t10 * 4.0;
  t182 = in2[4] * in2[5];
  t177 = t182 * s * t2;
  t16 = t177 * 4.0;
  t17_tmp = t172 * t4;
  b_t17_tmp = t17_tmp * 2.0;
  t18_tmp = in2[2] * s * 2.0;
  t32_tmp = t9;
  st.site = &q_emlrtRSI;
  b_sqrt(&st, &t32_tmp);
  t20 = 1.0 / t32_tmp;
  t21 = s * (t18_tmp + 1.0);
  t22_tmp = in2[1] * in2[3];
  t164 = t22_tmp * s * t2;
  t22 = t21 - t164 * t20 * 2.0;
  t23 = in2[1] * t2 * 2.0;
  t163 = in2[3] * t2;
  t186 = t163 * (t18_tmp + 1.0);
  t25 = t23 + t186 * t20;
  t206 = in2[0] * in2[5];
  t28_tmp = in2[3] * s;
  b_t28_tmp = in2[1] * s;
  t28 = (b_t28_tmp * t10 * 2.0 + t28_tmp * (t18_tmp + 1.0)) - t206 * t2 * 2.0;
  t32_tmp = in2[0] * in2[4];
  t32 = (t10 * (t18_tmp + 1.0) + t32_tmp * t2 * 2.0) - t22_tmp * t2 * 2.0;
  st.site = &r_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  t33 = t2 * t2;
  t37 = (s * t3 * 2.0 + s * t4 * 2.0) + s * t5 * 2.0;
  st.site = &s_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  if (t9 < 0.0) {
    c_st.site = &pb_emlrtRSI;
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
  t50 = t4 - t168 * (t18_tmp + 1.0) * t20;
  t32_tmp = t32_tmp * s * t2;
  t52 = t21 + t32_tmp * t20 * 2.0;
  t58 = t215 * t2 * t20 * 2.0 + t62 * t37 * t38;
  t62_tmp = t3 * s * t2;
  t62 = t4 + t62_tmp * t20 * 2.0;
  t63 = s * t43;
  t206 = t206 * s * t2;
  t21 = t23 - t206 * t20 * 2.0;
  t68 = t197 * t2 * t20 * 2.0 + t153 * t37 * t38;
  t71 = t182 * t2 * t20 * 2.0 + t177 * t37 * t38;
  t72 = 1.0 / in1[33];
  t3 = muDoubleScalarCos(in1[20]);
  st.site = &t_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  t74 = in1[2] * in1[2];
  st.site = &u_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  t75 = in1[3] * in1[3];
  st.site = &v_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  t78 = in1[18] * in1[18];
  t4 = muDoubleScalarSin(in1[20]);
  st.site = &w_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  t80 = 1.0 / (t4 * t4);
  st.site = &x_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  st.site = &y_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  t9 = in1[33] * in1[33];
  t83_tmp = t9 * (t3 * t3);
  st.site = &ab_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  st.site = &bb_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  st.site = &cb_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  st.site = &db_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  st.site = &eb_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  st.site = &fb_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  t96 = 1.0 / t9 * (t74 * t74 - t75 * t75) + t78 * t78 * (1.0 /
    muDoubleScalarPower(t4, 4.0)) * ((t83_tmp - 1.0) * (t83_tmp - 1.0)) * 6.0;
  t97 = t96 * 3.1415926535897931 / 4.0;
  st.site = &gb_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  t100_tmp = s * t28;
  t3 = in2[5] * t2;
  t9 = t3 * t20;
  t103 = ((((t10 * t21 + t100_tmp) + t186) + t177 * (t18_tmp + 1.0) * t20) -
          t47_tmp * t62) - t9 * t43;
  t104_tmp = t172 * t5;
  b_t104_tmp = t104_tmp * 2.0;
  t215 = t163 * t20;
  t107 = ((t48 + t43_tmp * t25) + t47_tmp * t22) - t215 * t43;
  t108 = t164 * 2.0;
  t3 = t3 * t10 * 4.0;
  t110 = t11 + t3;
  t111 = t14 - t15;
  t4 = t168 * t20;
  t116_tmp = t10 * t52;
  b_t116_tmp = t43_tmp * t50;
  c_t116_tmp = t4 * t43;
  d_t116_tmp = b_t47_tmp * in2[5] * t20 * t33 * 2.0;
  t116 = ((((t40 - t108) + t116_tmp) + b_t116_tmp) + c_t116_tmp) + d_t116_tmp;
  t120_tmp = s * (((t6_tmp + t7_tmp) + t8_tmp) - 1.0) * 2.0;
  t121_tmp = -t12 + b_t17_tmp;
  t121 = (t121_tmp + b_t104_tmp) + t120_tmp;
  st.site = &hb_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  t129 = muDoubleScalarPower(muDoubleScalarAbs(((((t103 * in2[11] + t107 * in2[9])
    + t110 * in2[7]) + t111 * in2[8]) - t121 * in2[6]) - t116 * in2[10]), in1[11]
    - 1.0);
  t132 = in2[4] * t2 * (t18_tmp + 1.0);
  t135 = ((t48 + t28_tmp * t50) + t47_tmp * t52) - t4 * t28;
  t139 = ((((t40 + t10 * t22) + t32_tmp * 2.0) + c_t47_tmp * in2[5] * t20 * t33 *
           2.0) - t28_tmp * t25) - t215 * t28;
  t23 = t163 * t10 * 4.0;
  t141 = t16 + t23;
  t148_tmp = t10 * t62;
  b_t148_tmp = t47_tmp * t21;
  c_t148_tmp = t9 * t28;
  b_t47_tmp = t153 * (t18_tmp + 1.0) * t20;
  t148 = ((((t63 - t132) + t148_tmp) + b_t148_tmp) + c_t148_tmp) + b_t47_tmp;
  t149 = ((t12 - b_t17_tmp) + b_t104_tmp) + t120_tmp;
  t153 = t11 - t3;
  st.site = &ib_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  t158 = muDoubleScalarPower(muDoubleScalarAbs(((((t135 * in2[10] + t139 * in2[9])
    + t153 * in2[6]) + t141 * in2[8]) - t148 * in2[11]) - t149 * in2[7]), in1[11]
    - 1.0);
  t163 = ((t48 + t28_tmp * t62) + t43_tmp * t21) - t9 * t32;
  t164 = t206 * 2.0;
  t168 = ((((t63 + t10 * t50) + t62_tmp * 2.0) + t22_tmp * in2[4] * t20 * t33 *
           2.0) - t43_tmp * t52) - t4 * t32;
  t5 = t14 + t15;
  t172 = ((t12 + b_t17_tmp) - b_t104_tmp) + t120_tmp;
  t21 = t10 * t25;
  t32_tmp = t28_tmp * t22;
  t215 *= t32;
  t9 = c_t47_tmp * in2[4] * t20 * t33 * 2.0;
  t177 = ((((t100_tmp - t164) + t21) + t32_tmp) + t215) + t9;
  t182 = t16 - t23;
  st.site = &jb_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  t186 = muDoubleScalarPower(muDoubleScalarAbs(((((t163 * in2[11] + t168 * in2
    [10]) + t5 * in2[6]) + t182 * in2[7]) - t172 * in2[8]) - t177 * in2[9]),
    in1[11] - 1.0);
  t3 = t10 * 2.0 + s * t20 * t37;
  t23 = (t3 + t6_tmp * t20 * 2.0) + t12_tmp * t37 * t38;
  st.site = &kb_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  t197 = muDoubleScalarPower(muDoubleScalarAbs((t23 * in2[9] + t58 * in2[10]) +
    t68 * in2[11]), in1[11] - 1.0);
  t62 = (t3 + t7_tmp * t20 * 2.0) + t17_tmp * t37 * t38;
  st.site = &lb_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  t206 = muDoubleScalarPower(muDoubleScalarAbs((t62 * in2[10] + t58 * in2[9]) +
    t71 * in2[11]), in1[11] - 1.0);
  t4 = (t3 + t8_tmp * t20 * 2.0) + t104_tmp * t37 * t38;
  out1[0] = ((t12 - t120_tmp) - b_t17_tmp) - b_t104_tmp;
  out1[1] = t110;
  out1[2] = t111;
  out1[3] = t107;
  out1[4] = ((((-t40 + t108) - t116_tmp) - b_t116_tmp) - c_t116_tmp) -
    d_t116_tmp;
  out1[5] = t103;
  out1[6] = t11 - in2[5] * t2 * t10 * 4.0;
  out1[7] = (t121_tmp - t120_tmp) - b_t104_tmp;
  out1[8] = t141;
  out1[9] = t139;
  out1[10] = t135;
  out1[11] = ((((-t63 + t132) - t148_tmp) - b_t148_tmp) - c_t148_tmp) -
    b_t47_tmp;
  out1[12] = t5;
  out1[13] = t16 - in2[3] * t2 * t10 * 4.0;
  out1[14] = ((-t12 - b_t17_tmp) + b_t104_tmp) - t120_tmp;
  out1[15] = ((((t164 - t100_tmp) - t21) - t32_tmp) - t215) - t9;
  out1[16] = t168;
  out1[17] = t163;
  out1[18] = 0.0;
  out1[19] = 0.0;
  out1[20] = 0.0;
  out1[21] = t23;
  out1[22] = t58;
  out1[23] = t68;
  out1[24] = 0.0;
  out1[25] = 0.0;
  out1[26] = 0.0;
  out1[27] = t58;
  out1[28] = t62;
  out1[29] = t71;
  out1[30] = 0.0;
  out1[31] = 0.0;
  out1[32] = 0.0;
  out1[33] = t68;
  out1[34] = t71;
  out1[35] = t4;
  st.site = &mb_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  t215 = muDoubleScalarPower(muDoubleScalarAbs((t4 * in2[11] + t68 * in2[9]) +
    t71 * in2[10]), in1[11] - 1.0);
  t32_tmp = in1[33];
  st.site = &nb_emlrtRSI;
  b_sqrt(&st, &t32_tmp);
  t3 = 1.0 / t32_tmp;
  t21 = in1[1] * t72;
  t32_tmp = t21 * (t72 * (t74 - t75) - t78 * t80 * (t83_tmp - 1.0) * 6.0) *
    3.1415926535897931;
  out2[0] = t32_tmp * (((t10 * t43 + t47_tmp * t28) - t43_tmp * t32) + t28_tmp *
                       t47) / 3.0;
  out2[1] = t32_tmp * (((t10 * t28 + t28_tmp * t32) - t47_tmp * t43) + t43_tmp *
                       t47) / 3.0;
  out2[2] = t32_tmp * ((((t10 * t32 - t28_tmp * t28) + t43_tmp * t43) + t47_tmp *
                        t47) - 1.0);
  t32_tmp = t72 * t78 * t80 * (t83_tmp - 1.0) * (in1[19] * in1[19]) *
    3.1415926535897931;
  out2[3] = t21 * (t97 - t32_tmp * 3.0) * (in2[3] * t10 * 2.0 + t28_tmp * t20 *
    t37);
  out2[4] = t21 * (t97 - t32_tmp * 2.9999999999999991) * (in2[4] * t10 * 2.0 +
    t43_tmp * t20 * t37);
  out2[5] = t21 * t96 * 3.1415926535897931 * (in2[5] * t10 * 2.0 + t47_tmp * t20
    * t37) / 6.0;
  out3[0] = ((((-in1[5] * t103 * t129 * in2[11] - in1[5] * t107 * t129 * in2[9])
               - in1[5] * t110 * t129 * in2[7]) - in1[5] * t111 * t129 * in2[8])
             + in1[5] * t116 * t129 * in2[10]) + in1[5] * t121 * t129 * in2[6];
  out3[1] = ((((-in1[6] * t135 * t158 * in2[10] - in1[6] * t139 * t158 * in2[9])
               - in1[6] * t141 * t158 * in2[8]) + in1[6] * t149 * t158 * in2[7])
             + in1[6] * t148 * t158 * in2[11]) - in1[6] * t153 * t158 * in2[6];
  out3[2] = ((((-in1[7] * t163 * t186 * in2[11] - in1[7] * t5 * t186 * in2[6]) -
               in1[7] * t168 * t186 * in2[10]) + in1[7] * t172 * t186 * in2[8])
             + in1[7] * t177 * t186 * in2[9]) - in1[7] * t182 * t186 * in2[7];
  out3[3] = (-in1[8] * t58 * t197 * in2[10] - in1[8] * t68 * t197 * in2[11]) -
    in1[8] * t23 * t197 * in2[9];
  out3[4] = (-in1[9] * t58 * t206 * in2[9] - in1[9] * t71 * t206 * in2[11]) -
    in1[9] * t62 * t206 * in2[10];
  out3[5] = (-in1[10] * t68 * t215 * in2[9] - in1[10] * t71 * t215 * in2[10]) -
    in1[10] * t4 * t215 * in2[11];
  out4[0] = 0.0;
  out4[1] = 0.0;
  out4[2] = -t78 * t80 * (t83_tmp - 1.0) * 3.1415926535897931 * (((((in1[21] +
    in1[22]) + in1[23]) + in1[24]) + in1[25]) + in1[26]);
  t4 = in1[21] * in1[19] * t78 * t80 * (t83_tmp - 1.0) * t3 * 3.1415926535897931;
  t9 = in1[22] * in1[19] * t78 * t80 * (t83_tmp - 1.0) * t3 * 3.1415926535897931;
  t32_tmp = in1[23] * in1[19] * t78 * t80 * (t83_tmp - 1.0) * t3 *
    3.1415926535897931;
  t21 = in1[24] * in1[19] * t78 * t80 * (t83_tmp - 1.0) * t3 *
    3.1415926535897931;
  t215 = in1[25] * in1[19] * t78 * t80 * (t83_tmp - 1.0) * t3 *
    3.1415926535897931;
  t3 = in1[26] * in1[19] * t78 * t80 * (t83_tmp - 1.0) * t3 * 3.1415926535897931;
  out4[3] = ((((t4 * -0.91522491349480972 - t9 * 0.91522491349480972) + t32_tmp *
               0.1086532638769295) + t21 * 0.80657164961788008) + t215 *
             0.80657164961787986) + t3 * 0.1086532638769295;
  out4[4] = ((((t4 * -0.40294336787992679 + t9 * 0.40294336787992691) + t32_tmp *
               0.99407970920288391) + t21 * 0.59113634132295712) - t215 *
             0.59113634132295745) - t3 * 0.99407970920288391;
  out4[5] = 0.0;
  out5[0] = b_t43_tmp * 2.0;
  out5[1] = b_t28_tmp * 2.0;
  out5[2] = t18_tmp + 1.0;
}

/* End of code generation (sprdmpF7.c) */
