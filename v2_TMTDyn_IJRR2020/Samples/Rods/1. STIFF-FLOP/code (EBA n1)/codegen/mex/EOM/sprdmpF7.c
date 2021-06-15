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
#include "EOM.h"
#include "sprdmpF7.h"
#include "error.h"
#include "EOM_data.h"

/* Variable Definitions */
static emlrtRSInfo hb_emlrtRSI = { 46, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo ib_emlrtRSI = { 47, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo jb_emlrtRSI = { 50, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo kb_emlrtRSI = { 52, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo lb_emlrtRSI = { 53, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo mb_emlrtRSI = { 54, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo nb_emlrtRSI = { 59, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo ob_emlrtRSI = { 60, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo pb_emlrtRSI = { 61, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo qb_emlrtRSI = { 64, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo rb_emlrtRSI = { 65, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo sb_emlrtRSI = { 66, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo tb_emlrtRSI = { 70, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo ub_emlrtRSI = { 72, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo vb_emlrtRSI = { 73, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo wb_emlrtRSI = { 74, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo xb_emlrtRSI = { 75, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo yb_emlrtRSI = { 82, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo ac_emlrtRSI = { 84, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo bc_emlrtRSI = { 86, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo cc_emlrtRSI = { 89, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo dc_emlrtRSI = { 92, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

static emlrtRSInfo ec_emlrtRSI = { 95, /* lineNo */
  "sprdmpF7",                          /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF7.m"/* pathName */
};

/* Function Definitions */
void sprdmpF7(const emlrtStack *sp, const real_T in1[34], const real_T in2[12],
              real_T out2[6], real_T out3[6], real_T out4[6])
{
  real_T t2;
  real_T t34;
  real_T t4;
  real_T t5;
  real_T t6;
  real_T t9;
  real_T t10;
  real_T t11;
  real_T t14_tmp_tmp;
  real_T t14_tmp;
  real_T t16;
  real_T t31;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;

  /* SPRDMPF7 */
  /*     [OUT1,OUT2,OUT3,OUT4,OUT5,OUT6,OUT7,OUT8] = SPRDMPF7(IN1,IN2,S) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.2. */
  /*     06-Jan-2019 18:10:18 */
  t2 = 1.0 / in1[33];
  t34 = muDoubleScalarCos(in1[20]);
  t4 = 1.0 / in1[4];
  st.site = &hb_emlrtRSI;
  t5 = in1[2] * in1[2];
  st.site = &ib_emlrtRSI;
  t6 = in1[3] * in1[3];
  st.site = &jb_emlrtRSI;
  t9 = in1[18] * in1[18];
  t10 = muDoubleScalarSin(in1[20]);
  st.site = &kb_emlrtRSI;
  t11 = 1.0 / (t10 * t10);
  st.site = &lb_emlrtRSI;
  st.site = &mb_emlrtRSI;
  t14_tmp_tmp = in1[33] * in1[33];
  t14_tmp = t14_tmp_tmp * (t34 * t34);
  t16 = t2 * (t5 - t6) - t9 * t11 * (t14_tmp - 1.0) * 6.0;
  st.site = &nb_emlrtRSI;
  st.site = &ob_emlrtRSI;
  st.site = &pb_emlrtRSI;
  st.site = &qb_emlrtRSI;
  st.site = &rb_emlrtRSI;
  st.site = &sb_emlrtRSI;
  t5 = 1.0 / t14_tmp_tmp * (t5 * t5 - t6 * t6) + t9 * t9 * (1.0 /
    muDoubleScalarPower(t10, 4.0)) * ((t14_tmp - 1.0) * (t14_tmp - 1.0)) * 6.0;
  st.site = &tb_emlrtRSI;
  st.site = &ub_emlrtRSI;
  if (in1[33] < 0.0) {
    b_st.site = &w_emlrtRSI;
    error(&b_st);
  }

  t31 = 1.0 / muDoubleScalarSqrt(in1[33]);
  st.site = &vb_emlrtRSI;
  st.site = &wb_emlrtRSI;
  t34 = in1[4] * in1[4];
  st.site = &xb_emlrtRSI;
  if (t34 < 0.0) {
    b_st.site = &w_emlrtRSI;
    error(&b_st);
  }

  t34 = muDoubleScalarSqrt(t34);
  out2[0] = in1[1] * in2[0] * t2 * t4 * t16 * 3.1415926535897931 / 3.0;
  out2[1] = in1[1] * in2[1] * t2 * t4 * t16 * 3.1415926535897931 / 3.0;
  out2[2] = in1[1] * t2 * t4 * t16 * 3.1415926535897931 * (in2[2] - t34);
  t34 = t5 * 3.1415926535897931 / 4.0 - t2 * t9 * t11 * (t14_tmp - 1.0) * (in1
    [19] * in1[19]) * 3.1415926535897931 * 3.0;
  out2[3] = in1[1] * in2[3] * t2 * t4 * t34 * 2.0;
  out2[4] = in1[1] * in2[4] * t2 * t4 * t34 * 2.0;
  out2[5] = in1[1] * in2[5] * t2 * t4 * t5 * 3.1415926535897931 / 3.0;
  st.site = &yb_emlrtRSI;
  st.site = &ac_emlrtRSI;
  st.site = &bc_emlrtRSI;
  st.site = &cc_emlrtRSI;
  st.site = &dc_emlrtRSI;
  st.site = &ec_emlrtRSI;
  out3[0] = -in1[5] * muDoubleScalarPower(muDoubleScalarAbs(in2[6]), in1[11] -
    1.0) * in2[6];
  out3[1] = -in1[6] * muDoubleScalarPower(muDoubleScalarAbs(in2[7]), in1[11] -
    1.0) * in2[7];
  out3[2] = -in1[7] * muDoubleScalarPower(muDoubleScalarAbs(in2[8]), in1[11] -
    1.0) * in2[8];
  out3[3] = in1[8] * muDoubleScalarPower(muDoubleScalarAbs(in2[9]) * 2.0, in1[11]
    - 1.0) * in2[9] * -2.0;
  out3[4] = in1[9] * muDoubleScalarPower(muDoubleScalarAbs(in2[10]) * 2.0, in1
    [11] - 1.0) * in2[10] * -2.0;
  out3[5] = in1[10] * muDoubleScalarPower(muDoubleScalarAbs(in2[11]) * 2.0, in1
    [11] - 1.0) * in2[11] * -2.0;
  out4[0] = 0.0;
  out4[1] = 0.0;
  out4[2] = -t9 * t11 * (t14_tmp - 1.0) * 3.1415926535897931 * (((((in1[21] +
    in1[22]) + in1[23]) + in1[24]) + in1[25]) + in1[26]);
  t5 = in1[23] * in1[19] * t9 * t11 * (t14_tmp - 1.0) * t31 * 3.1415926535897931;
  t6 = in1[24] * in1[19] * t9 * t11 * (t14_tmp - 1.0) * t31 * 3.1415926535897931;
  t10 = in1[25] * in1[19] * t9 * t11 * (t14_tmp - 1.0) * t31 *
    3.1415926535897931;
  t14_tmp_tmp = in1[26] * in1[19] * t9 * t11 * (t14_tmp - 1.0) * t31 *
    3.1415926535897931;
  t16 = in1[21] * in1[19] * t9 * t11 * (t14_tmp - 1.0) * t31;
  t34 = in1[22] * in1[19] * t9 * t11 * (t14_tmp - 1.0) * t31;
  out4[3] = ((((t16 * 3.1415926535897931 * -0.93771626297577859 - t34 *
                3.1415926535897931 * 0.93771626297577859) + t5 *
               0.167999098695029) + t6 * 0.76971716428074954) + t10 *
             0.76971716428074932) + t14_tmp_tmp * 0.16799909869502891;
  out4[4] = ((((t5 * 0.9857871488499218 + t6 * 0.63838506170774523) - t10 *
               0.63838506170774545) - t14_tmp_tmp * 0.9857871488499218) - t16 *
             8.3666002653407556 * 3.1415926535897931 * 0.041522491349480967) +
    t34 * 8.3666002653407556 * 3.1415926535897931 * 0.041522491349480967;
  out4[5] = 0.0;
}

/* End of code generation (sprdmpF7.c) */
