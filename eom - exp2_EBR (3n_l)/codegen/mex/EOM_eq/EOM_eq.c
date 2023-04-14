/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EOM_eq.c
 *
 * Code generation for function 'EOM_eq'
 *
 */

/* Include files */
#include "EOM_eq.h"
#include "EOM_eq_data.h"
#include "EOM_eq_types.h"
#include "fj_kF.h"
#include "loadsF1.h"
#include "massF2.h"
#include "massF3.h"
#include "massF4.h"
#include "mtimes.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 9,     /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 11,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 12,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 21,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 23,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 24,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 26,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 28,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 29,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 31,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 33,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 34,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 36,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 38,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 39,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 42,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 22, /* lineNo */
  "fj_inF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\fj_inF.m"/* pathName */
};

static emlrtDCInfo emlrtDCI = { 10,    /* lineNo */
  34,                                  /* colNo */
  "static_mid_step",                   /* fName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\static_mid_step.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo emlrtBCI = { 1,     /* iFirst */
  1094,                                /* iLast */
  10,                                  /* lineNo */
  34,                                  /* colNo */
  "par_mex.user_pars.f_ex",            /* aName */
  "static_mid_step",                   /* fName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\static_mid_step.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = { 13,  /* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pName */
};

/* Function Definitions */
void EOM_eq(const emlrtStack *sp, const real_T z[18], real_T res[18])
{
  static const int8_T iv[6] = { 0, 0, 1, 1, 2, 2 };

  emlrtStack b_st;
  emlrtStack st;
  real_T unusedExpr[324];
  real_T Dd[108];
  real_T T[108];
  real_T Tt[108];
  real_T b_Dd[108];
  real_T b_y[108];
  real_T c_Dd[108];
  real_T c_y[108];
  real_T d_y[108];
  real_T y[108];
  real_T M[36];
  real_T b_z[36];
  real_T dv1[18];
  real_T dv2[18];
  real_T e_y[18];
  real_T fj_k[18];
  real_T b_fg[6];
  real_T c_fg[6];
  real_T d_Dd[6];
  real_T dv[6];
  real_T e_Dd[6];
  real_T fg[6];
  real_T ftau_ex[6];
  real_T b_t13;
  real_T step;
  real_T t11;
  real_T t11_tmp_tmp;
  real_T t12;
  real_T t13;
  real_T t14;
  real_T t15;
  real_T t16;
  real_T t17;
  real_T t19;
  real_T t20;
  real_T t21;
  real_T t22;
  real_T t23;
  real_T t24;
  real_T t25;
  real_T t30;
  real_T t30_tmp;
  real_T t32;
  real_T t33;
  real_T t5_tmp;
  real_T t6;
  real_T t7;
  real_T t8;
  int32_T i;
  int32_T i1;
  int32_T i2;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  for (i = 0; i < 18; i++) {
    step = z[i];
    b_z[i] = step;
    b_z[i + 18] = 0.0 * step;
  }

  st.site = &emlrtRSI;

  /*  parameters */
  /*  inputs: internal pressure & external forces/torques */
  /*  temp = interp1( par.f_ex(:,1) , [ par.f_ex(:,2:7) par.p(:,2:4) ] , t , 'nearest' ) ; */
  step = muDoubleScalarFloor(par_mex.t_equil_i / 0.05);
  if (step == 0.0) {
    step = 1.0;
  }

  if (step != (int32_T)step) {
    emlrtIntegerCheckR2012b(step, &emlrtDCI, &st);
  }

  if (((int32_T)step < 1) || ((int32_T)step > 1094)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)step, 1, 1094, &emlrtBCI, &st);
  }

  /*  cross-section deformation */
  /*  In this case it causes numerical instability, so commented */
  /*  axial stretch */
  /*  l = 0 ; */
  /*  for i = 0 : par_mex.user_pars.n_l - 2 */
  /*      l = l + z(i*6+3) ; */
  /*  end */
  /*  lambda = 1 + l / par_mex.var(5) ; */
  /*  update simulation parameters */
  for (i = 0; i < 6; i++) {
    par_mex.var[i + 21] = par_mex.user_pars.p[((int32_T)step + 1094 * (iv[i] + 1))
      - 1];
    par_mex.var[i + 27] = par_mex.user_pars.f_ex[((int32_T)step + 1094 * (i + 1))
      - 1];
  }

  par_mex.var[33] = 1.0;
  par_mex_dirty |= 1U;
  st.site = &b_emlrtRSI;
  fj_kF(par_mex.var, b_z, fj_k);
  st.site = &c_emlrtRSI;

  /* FJ_INF */
  /*     OUT1 = FJ_INF(IN1,IN2,S,DS,T_SYM) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
  /*     14-Jun-2021 16:41:55 */
  t30 = muDoubleScalarCos(par_mex.var[20]);
  step = muDoubleScalarSin(par_mex.var[20]);
  t5_tmp = par_mex.var[18] * par_mex.var[18];
  b_st.site = &gb_emlrtRSI;
  if (par_mex.var[33] < 0.0) {
    emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  t8 = 1.0 / muDoubleScalarSqrt(par_mex.var[33]);
  t7 = 1.0 / (step * step);
  t11_tmp_tmp = par_mex.var[33] * par_mex.var[33];
  t30 = t11_tmp_tmp * (t30 * t30);
  t13 = t5_tmp * t7 * (((((par_mex.var[21] + par_mex.var[22]) + par_mex.var[23])
    + par_mex.var[24]) + par_mex.var[25]) + par_mex.var[26]) * (t30 - 1.0) *
    3.1415926535897931;
  t6 = par_mex.var[22] * par_mex.var[19] * t5_tmp * t7 * t8;
  t11 = par_mex.var[21] * par_mex.var[19] * t5_tmp * t7 * t8;
  t12 = par_mex.var[23] * par_mex.var[19] * t5_tmp * t7 * t8 * (t30 - 1.0) *
    3.1415926535897931;
  b_t13 = par_mex.var[24] * par_mex.var[19] * t5_tmp * t7 * t8 * (t30 - 1.0) *
    3.1415926535897931;
  t14 = par_mex.var[26] * par_mex.var[19] * t5_tmp * t7 * t8 * (t30 - 1.0) *
    3.1415926535897931;
  step = par_mex.var[25] * par_mex.var[19] * t5_tmp * t7 * t8 * (t30 - 1.0) *
    3.1415926535897931;
  t32 = ((((-(t11 * (t30 - 1.0) * 3.1415926535897931 * 0.93771626297577859) +
            -(t6 * (t30 - 1.0) * 3.1415926535897931 * 0.93771626297577859)) +
           step * 0.76971716428074932) + b_t13 * 0.76971716428074954) + t14 *
         0.16799909869502891) + t12 * 0.167999098695029;
  t33 = ((((t6 * 8.3666002653407556 * (t30 - 1.0) * 3.1415926535897931 *
            0.041522491349480967 + -(t11 * 8.3666002653407556 * (t30 - 1.0) *
             3.1415926535897931 * 0.041522491349480967)) + t12 *
           0.9857871488499218) + b_t13 * 0.63838506170774523) + -(t14 *
          0.9857871488499218)) + -(step * 0.63838506170774545);
  st.site = &d_emlrtRSI;

  /* MASSF1 */
  /*     [OUT1,OUT2,OUT3,OUT4] = MASSF1(IN1,IN2,S,DS,T_SYM) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
  /*     14-Jun-2021 16:39:44 */
  t8 = par_mex.var[2] * par_mex.var[2];
  t6 = par_mex.var[3] * par_mex.var[3];
  t7 = 1.0 / par_mex.var[33];
  t11 = par_mex.var[4] / 6.0;
  t12 = b_z[3] / 2.0;
  b_t13 = b_z[4] / 2.0;
  t14 = b_z[5] / 2.0;
  t15 = b_z[21] / 2.0;
  t16 = b_z[22] / 2.0;
  t17 = b_z[23] / 2.0;
  t19 = par_mex.var[4] * b_z[3] / 12.0;
  t20 = par_mex.var[4] * b_z[4] / 12.0;
  t21 = par_mex.var[4] * b_z[5] / 12.0;
  t22 = par_mex.var[4] * b_z[21] / 12.0;
  t23 = par_mex.var[4] * b_z[22] / 12.0;
  t24 = par_mex.var[4] * b_z[23] / 12.0;
  t25 = t8 + -t6;
  t30_tmp = par_mex.var[4] * par_mex.var[0];
  t30 = t30_tmp * (t5_tmp * 6.0 + t25) * 3.1415926535897931 / 3.0;
  step = t30_tmp * t25 * (par_mex.var[4] * par_mex.var[4] * t11_tmp_tmp / 108.0
    + t7 * (t8 * 3.0 + t6 * 3.0) / 12.0) * 3.1415926535897931 / 3.0;
  M[0] = -t30;
  M[1] = 0.0;
  M[2] = 0.0;
  M[3] = 0.0;
  M[4] = 0.0;
  M[5] = 0.0;
  M[6] = 0.0;
  M[7] = -t30;
  M[8] = 0.0;
  M[9] = 0.0;
  M[10] = 0.0;
  M[11] = 0.0;
  M[12] = 0.0;
  M[13] = 0.0;
  M[14] = -t30;
  M[15] = 0.0;
  M[16] = 0.0;
  M[17] = 0.0;
  M[18] = 0.0;
  M[19] = 0.0;
  M[20] = 0.0;
  M[21] = -step;
  M[22] = 0.0;
  M[23] = 0.0;
  M[24] = 0.0;
  M[25] = 0.0;
  M[26] = 0.0;
  M[27] = 0.0;
  M[28] = -step;
  M[29] = 0.0;
  M[30] = 0.0;
  M[31] = 0.0;
  M[32] = 0.0;
  M[33] = 0.0;
  M[34] = 0.0;
  M[35] = t30_tmp * t7 * t25 * 3.1415926535897931 * (t8 / 2.0 + t6 / 2.0) *
    -0.33333333333333331;
  T[0] = 1.0;
  T[1] = 0.0;
  T[2] = 0.0;
  T[3] = 0.0;
  T[4] = 0.0;
  T[5] = 0.0;
  T[6] = 0.0;
  T[7] = 1.0;
  T[8] = 0.0;
  T[9] = 0.0;
  T[10] = 0.0;
  T[11] = 0.0;
  T[12] = 0.0;
  T[13] = 0.0;
  T[14] = 1.0;
  T[15] = 0.0;
  T[16] = 0.0;
  T[17] = 0.0;
  T[18] = t21;
  T[19] = -t11;
  T[20] = -t19;
  T[21] = 1.0;
  T[22] = -t14;
  T[23] = b_t13;
  T[24] = t11;
  T[25] = t21;
  T[26] = -t20;
  T[27] = t14;
  T[28] = 1.0;
  T[29] = -t12;
  T[30] = t19;
  T[31] = t20;
  T[32] = t21;
  T[33] = -b_t13;
  T[34] = t12;
  T[35] = 1.0;
  memset(&T[36], 0, 72U * sizeof(real_T));
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 18; i1++) {
      Tt[i1 + 18 * i] = T[i + 6 * i1];
    }
  }

  st.site = &e_emlrtRSI;
  mtimes(Tt, M, y);
  st.site = &e_emlrtRSI;
  b_mtimes(y, T, unusedExpr);
  st.site = &f_emlrtRSI;
  mtimes(Tt, M, y);
  st.site = &g_emlrtRSI;
  massF2(par_mex.var, b_z, M, T, Dd, fg);
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 18; i1++) {
      Tt[i1 + 18 * i] = T[i + 6 * i1];
    }
  }

  st.site = &h_emlrtRSI;
  mtimes(Tt, M, b_y);
  st.site = &h_emlrtRSI;
  b_mtimes(b_y, T, unusedExpr);
  st.site = &i_emlrtRSI;
  mtimes(Tt, M, b_y);
  st.site = &j_emlrtRSI;
  massF3(par_mex.var, b_z, M, T, b_Dd, b_fg);
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 18; i1++) {
      Tt[i1 + 18 * i] = T[i + 6 * i1];
    }
  }

  st.site = &k_emlrtRSI;
  mtimes(Tt, M, c_y);
  st.site = &k_emlrtRSI;
  b_mtimes(c_y, T, unusedExpr);
  st.site = &l_emlrtRSI;
  mtimes(Tt, M, c_y);
  st.site = &m_emlrtRSI;
  massF4(par_mex.var, b_z, M, T, c_Dd, c_fg);
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 18; i1++) {
      Tt[i1 + 18 * i] = T[i + 6 * i1];
    }
  }

  st.site = &n_emlrtRSI;
  mtimes(Tt, M, d_y);
  st.site = &n_emlrtRSI;
  b_mtimes(d_y, T, unusedExpr);
  st.site = &o_emlrtRSI;
  mtimes(Tt, M, d_y);
  st.site = &p_emlrtRSI;
  loadsF1(par_mex.var, b_z, T, ftau_ex);

  /*  EOM */
  memset(&Tt[0], 0, 18U * sizeof(real_T));
  Tt[18] = -t24;
  Tt[19] = -0.0;
  Tt[20] = t22;
  Tt[21] = -0.0;
  Tt[22] = -t17;
  Tt[23] = t16;
  Tt[24] = -0.0;
  Tt[25] = -t24;
  Tt[26] = t23;
  Tt[27] = t17;
  Tt[28] = -0.0;
  Tt[29] = -t15;
  Tt[30] = -t22;
  Tt[31] = -t23;
  Tt[32] = -t24;
  Tt[33] = -t16;
  Tt[34] = t15;
  memset(&Tt[35], 0, 73U * sizeof(real_T));
  d_Dd[0] = par_mex.var[12];
  d_Dd[1] = par_mex.var[13];
  d_Dd[2] = par_mex.var[14];
  d_Dd[3] = 0.0;
  d_Dd[4] = 0.0;
  d_Dd[5] = 0.0;
  for (i = 0; i < 6; i++) {
    step = 0.0;
    for (i1 = 0; i1 < 18; i1++) {
      step += Tt[i + 6 * i1] * b_z[i1 + 18];
    }

    dv[i] = step + d_Dd[i];
  }

  for (i = 0; i < 108; i++) {
    Dd[i] = -Dd[i];
  }

  for (i = 0; i < 6; i++) {
    step = 0.0;
    for (i1 = 0; i1 < 18; i1++) {
      step += Dd[i + 6 * i1] * b_z[i1 + 18];
    }

    e_Dd[i] = step + fg[i];
  }

  for (i = 0; i < 18; i++) {
    step = 0.0;
    t30 = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      i2 = i + 18 * i1;
      step += y[i2] * dv[i1];
      t30 += b_y[i2] * e_Dd[i1];
    }

    e_y[i] = t30;
    dv1[i] = step;
  }

  for (i = 0; i < 108; i++) {
    b_Dd[i] = -b_Dd[i];
  }

  for (i = 0; i < 6; i++) {
    step = 0.0;
    for (i1 = 0; i1 < 18; i1++) {
      step += b_Dd[i + 6 * i1] * b_z[i1 + 18];
    }

    e_Dd[i] = step + b_fg[i];
  }

  for (i = 0; i < 108; i++) {
    c_Dd[i] = -c_Dd[i];
  }

  for (i = 0; i < 6; i++) {
    step = 0.0;
    for (i1 = 0; i1 < 18; i1++) {
      step += c_Dd[i + 6 * i1] * b_z[i1 + 18];
    }

    d_Dd[i] = step + c_fg[i];
  }

  for (i = 0; i < 18; i++) {
    step = 0.0;
    t30 = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      i2 = i + 18 * i1;
      step += c_y[i2] * e_Dd[i1];
      t30 += d_y[i2] * d_Dd[i1];
    }

    dv2[i] = (dv1[i] + e_y[i]) + step;
    e_y[i] = t30;
  }

  dv1[0] = 0.0;
  dv1[1] = 0.0;
  dv1[2] = -t13;
  dv1[3] = t32;
  dv1[4] = t33;
  dv1[5] = 0.0;
  dv1[6] = 0.0;
  dv1[7] = 0.0;
  dv1[8] = -t13;
  dv1[9] = t32;
  dv1[10] = t33;
  dv1[11] = 0.0;
  dv1[12] = 0.0;
  dv1[13] = 0.0;
  dv1[14] = -t13;
  dv1[15] = t32;
  dv1[16] = t33;
  dv1[17] = 0.0;
  for (i = 0; i < 18; i++) {
    step = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      step += T[i + 18 * i1] * ftau_ex[i1];
    }

    res[i] = (((dv2[i] + e_y[i]) + fj_k[i]) + dv1[i]) + step;
  }
}

/* End of code generation (EOM_eq.c) */
