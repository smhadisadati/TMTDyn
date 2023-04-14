/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sprdmpF19.c
 *
 * Code generation for function 'sprdmpF19'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "EOM.h"
#include "sprdmpF19.h"
#include "error.h"
#include "EOM_data.h"

/* Variable Definitions */
static emlrtRSInfo rc_emlrtRSI = { 46, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo sc_emlrtRSI = { 47, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo tc_emlrtRSI = { 50, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo uc_emlrtRSI = { 52, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo vc_emlrtRSI = { 53, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo wc_emlrtRSI = { 54, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo xc_emlrtRSI = { 59, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo yc_emlrtRSI = { 60, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo ad_emlrtRSI = { 61, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo bd_emlrtRSI = { 64, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo cd_emlrtRSI = { 65, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo dd_emlrtRSI = { 66, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo ed_emlrtRSI = { 70, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo fd_emlrtRSI = { 72, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo gd_emlrtRSI = { 73, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo hd_emlrtRSI = { 74, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo id_emlrtRSI = { 76, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo jd_emlrtRSI = { 83, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo kd_emlrtRSI = { 85, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo ld_emlrtRSI = { 87, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo md_emlrtRSI = { 90, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo nd_emlrtRSI = { 93, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

static emlrtRSInfo od_emlrtRSI = { 96, /* lineNo */
  "sprdmpF19",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF19.m"/* pathName */
};

/* Function Definitions */
void sprdmpF19(const emlrtStack *sp, const real_T in1[34], const real_T in2[36],
               real_T out2[6], real_T out3[6], real_T out4[6])
{
  real_T t2;
  real_T t35;
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

  /* SPRDMPF19 */
  /*     [OUT1,OUT2,OUT3,OUT4,OUT5,OUT6,OUT7,OUT8] = SPRDMPF19(IN1,IN2,S) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.2. */
  /*     06-Jan-2019 18:52:18 */
  t2 = 1.0 / in1[33];
  t35 = muDoubleScalarCos(in1[20]);
  t4 = 1.0 / in1[4];
  st.site = &rc_emlrtRSI;
  t5 = in1[2] * in1[2];
  st.site = &sc_emlrtRSI;
  t6 = in1[3] * in1[3];
  st.site = &tc_emlrtRSI;
  t9 = in1[18] * in1[18];
  t10 = muDoubleScalarSin(in1[20]);
  st.site = &uc_emlrtRSI;
  t11 = 1.0 / (t10 * t10);
  st.site = &vc_emlrtRSI;
  st.site = &wc_emlrtRSI;
  t14_tmp_tmp = in1[33] * in1[33];
  t14_tmp = t14_tmp_tmp * (t35 * t35);
  t16 = t2 * (t5 - t6) - t9 * t11 * (t14_tmp - 1.0) * 6.0;
  st.site = &xc_emlrtRSI;
  st.site = &yc_emlrtRSI;
  st.site = &ad_emlrtRSI;
  st.site = &bd_emlrtRSI;
  st.site = &cd_emlrtRSI;
  st.site = &dd_emlrtRSI;
  t5 = 1.0 / t14_tmp_tmp * (t5 * t5 - t6 * t6) + t9 * t9 * (1.0 /
    muDoubleScalarPower(t10, 4.0)) * ((t14_tmp - 1.0) * (t14_tmp - 1.0)) * 6.0;
  st.site = &ed_emlrtRSI;
  st.site = &fd_emlrtRSI;
  if (in1[33] < 0.0) {
    b_st.site = &hb_emlrtRSI;
    error(&b_st);
  }

  t31 = 1.0 / muDoubleScalarSqrt(in1[33]);
  st.site = &gd_emlrtRSI;
  st.site = &hd_emlrtRSI;
  t35 = in1[4] * in1[4] / 9.0;
  st.site = &id_emlrtRSI;
  if (t35 < 0.0) {
    b_st.site = &hb_emlrtRSI;
    error(&b_st);
  }

  t35 = muDoubleScalarSqrt(t35);
  out2[0] = in1[1] * in2[0] * t2 * t4 * t16 * 3.1415926535897931;
  out2[1] = in1[1] * in2[1] * t2 * t4 * t16 * 3.1415926535897931;
  out2[2] = in1[1] * t2 * t4 * t16 * 3.1415926535897931 * (in2[2] - t35) * 3.0;
  t35 = t5 * 3.1415926535897931 / 4.0 - t2 * t9 * t11 * (t14_tmp - 1.0) * (in1
    [19] * in1[19]) * 3.1415926535897931 * 3.0;
  out2[3] = in1[1] * in2[3] * t2 * t4 * t35 * 6.0;
  out2[4] = in1[1] * in2[4] * t2 * t4 * t35 * 6.0;
  out2[5] = in1[1] * in2[5] * t2 * t4 * t5 * 3.1415926535897931;
  st.site = &jd_emlrtRSI;
  st.site = &kd_emlrtRSI;
  st.site = &ld_emlrtRSI;
  st.site = &md_emlrtRSI;
  st.site = &nd_emlrtRSI;
  st.site = &od_emlrtRSI;
  out3[0] = -in1[5] * muDoubleScalarPower(muDoubleScalarAbs(in2[18]), in1[11] -
    1.0) * in2[18];
  out3[1] = -in1[6] * muDoubleScalarPower(muDoubleScalarAbs(in2[19]), in1[11] -
    1.0) * in2[19];
  out3[2] = -in1[7] * muDoubleScalarPower(muDoubleScalarAbs(in2[20]), in1[11] -
    1.0) * in2[20];
  out3[3] = in1[8] * muDoubleScalarPower(muDoubleScalarAbs(in2[21]) * 2.0, in1
    [11] - 1.0) * in2[21] * -2.0;
  out3[4] = in1[9] * muDoubleScalarPower(muDoubleScalarAbs(in2[22]) * 2.0, in1
    [11] - 1.0) * in2[22] * -2.0;
  out3[5] = in1[10] * muDoubleScalarPower(muDoubleScalarAbs(in2[23]) * 2.0, in1
    [11] - 1.0) * in2[23] * -2.0;
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
  t35 = in1[22] * in1[19] * t9 * t11 * (t14_tmp - 1.0) * t31;
  out4[3] = ((((t16 * 3.1415926535897931 * -0.93771626297577859 - t35 *
                3.1415926535897931 * 0.93771626297577859) + t5 *
               0.167999098695029) + t6 * 0.76971716428074954) + t10 *
             0.76971716428074932) + t14_tmp_tmp * 0.16799909869502891;
  out4[4] = ((((t5 * 0.9857871488499218 + t6 * 0.63838506170774523) - t10 *
               0.63838506170774545) - t14_tmp_tmp * 0.9857871488499218) - t16 *
             8.3666002653407556 * 3.1415926535897931 * 0.041522491349480967) +
    t35 * 8.3666002653407556 * 3.1415926535897931 * 0.041522491349480967;
  out4[5] = 0.0;
}

/* End of code generation (sprdmpF19.c) */
