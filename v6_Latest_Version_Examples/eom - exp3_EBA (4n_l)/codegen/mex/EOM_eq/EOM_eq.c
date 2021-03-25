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
#include "massF2.h"
#include "massF3.h"
#include "massF4.h"
#include "massF5.h"
#include "mtimes.h"
#include "rt_nonfinite.h"
#include "sprdmpF25.h"
#include "sprdmpF26.h"
#include "sprdmpF27.h"
#include "sprdmpF28.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 9,     /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 21,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 23,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 24,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 26,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 28,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 29,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 31,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 33,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 34,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 36,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 38,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 39,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 41,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 43,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 44,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 46,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 51,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 56,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 61,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 67,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo eb_emlrtRSI = { 48, /* lineNo */
  "massF1",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\massF1.m"/* pathName */
};

static emlrtRSInfo hg_emlrtRSI = { 42, /* lineNo */
  "loadsF1",                           /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\loadsF1.m"/* pathName */
};

static emlrtBCInfo emlrtBCI = { 1,     /* iFirst */
  1094,                                /* iLast */
  10,                                  /* lineNo */
  34,                                  /* colNo */
  "par_mex.user_pars.f_ex",            /* aName */
  "static_mid_step",                   /* fName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\static_mid_step.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo emlrtDCI = { 10,    /* lineNo */
  34,                                  /* colNo */
  "static_mid_step",                   /* fName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\static_mid_step.m",/* pName */
  1                                    /* checkKind */
};

/* Function Definitions */
void EOM_eq(const emlrtStack *sp, const real_T z[24], real_T res[24])
{
  static const int8_T b[144] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T iv[6] = { 0, 0, 1, 1, 2, 2 };

  emlrtStack b_st;
  emlrtStack st;
  real_T unusedExpr[576];
  real_T Dd[144];
  real_T T[144];
  real_T Tt[144];
  real_T b_Dd[144];
  real_T b_Tt[144];
  real_T b_y[144];
  real_T c_Dd[144];
  real_T c_Tt[144];
  real_T c_y[144];
  real_T d_Dd[144];
  real_T d_y[144];
  real_T dv[144];
  real_T e_y[144];
  real_T y[144];
  real_T b_z[48];
  real_T M[36];
  real_T dv2[24];
  real_T dv3[24];
  real_T f_y[24];
  real_T b_fg[6];
  real_T b_in[6];
  real_T b_kx[6];
  real_T c_fg[6];
  real_T c_in[6];
  real_T c_kx[6];
  real_T d_fg[6];
  real_T d_in[6];
  real_T d_kx[6];
  real_T dv1[6];
  real_T e_Dd[6];
  real_T fg[6];
  real_T in[6];
  real_T kx[6];
  real_T vd[6];
  real_T b_t31;
  real_T b_t33;
  real_T b_t34;
  real_T b_t35;
  real_T b_t39;
  real_T step;
  real_T t11;
  real_T t12;
  real_T t13;
  real_T t15;
  real_T t17;
  real_T t21;
  real_T t26;
  real_T t27;
  real_T t28;
  real_T t30;
  real_T t31;
  real_T t32;
  real_T t33;
  real_T t34;
  real_T t35;
  real_T t37;
  real_T t38;
  real_T t39;
  real_T t39_tmp;
  real_T t4;
  real_T t5;
  real_T t52;
  real_T t54;
  real_T t55;
  real_T t6;
  real_T t7;
  real_T t8;
  real_T t9;
  int32_T i;
  int32_T i1;
  int32_T i2;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  for (i = 0; i < 24; i++) {
    t39 = z[i];
    b_z[i] = t39;
    b_z[i + 24] = 0.0 * t39;
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
  /*  l = 0 ; */
  /*  [ ~ , ~ , ~ , ~ , dl ] = sprdmpF31( par.var , z.' , 0 ) ; l = l + dl ; % 6 * n_s + 1 : n_sd = 6 * n_s + n_s */
  /*  [ ~ , ~ , ~ , ~ , dl ] = sprdmpF32( par.var , z.' , 0 ) ; l = l + dl ; % 6 * n_s + 1 : n_sd = 6 * n_s + n_s */
  /*  [ ~ , ~ , ~ , ~ , dl ] = sprdmpF33( par.var , z.' , 0 ) ; l = l + dl ; % 6 * n_s + 1 : n_sd = 6 * n_s + n_s */
  /*  [ ~ , ~ , ~ , ~ , dl ] = sprdmpF34( par.var , z.' , 0 ) ; l = l + dl ; % 6 * n_s + 1 : n_sd = 6 * n_s + n_s */
  /*  [ ~ , ~ , ~ , ~ , dl ] = sprdmpF35( par.var , z.' , 0 ) ; l = l + dl ; % 6 * n_s + 1 : n_sd = 6 * n_s + n_s */
  /*  lambda = 1 + l / par.var(5) ;  */
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

  /* MASSF1 */
  /*     [OUT1,OUT2,OUT3,OUT4] = MASSF1(IN1,IN2,S,DS,T_SYM) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
  /*     26-Feb-2021 21:07:19 */
  t4 = b_z[3] * 2.0;
  t5 = b_z[4] * 2.0;
  t6 = b_z[5] * 2.0;
  t7 = b_z[3] * b_z[3];
  t8 = b_z[4] * b_z[4];
  t9 = b_z[5] * b_z[5];
  t11 = par_mex.var[2] * par_mex.var[2];
  t12 = par_mex.var[3] * par_mex.var[3];
  t13 = 1.0 / par_mex.var[33];
  t21 = t11 + -t12;
  step = ((-t7 + -t8) + -t9) + 1.0;
  b_st.site = &eb_emlrtRSI;
  if (step < 0.0) {
    emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  step = muDoubleScalarSqrt(step);
  t30 = 1.0 / step;
  t32 = step * 2.0;
  t52 = par_mex.var[4] * par_mex.var[0];
  t28 = -(t52 * (par_mex.var[18] * par_mex.var[18] * 6.0 + t21) *
          3.1415926535897931 / 4.0);
  t31 = muDoubleScalarPower(t30, 3.0);
  t33 = t4 * t30;
  t34 = t5 * t30;
  t35 = t6 * t30;
  step = b_z[4] * t33;
  t37 = b_z[5] * t33;
  t38 = b_z[5] * t34;
  t39_tmp = b_z[4] * b_z[5];
  t39 = t39_tmp * t4 * t31;
  t30 = -(t52 * t21 * (par_mex.var[4] * par_mex.var[4] * (par_mex.var[33] *
            par_mex.var[33]) / 192.0 + t13 * (t11 * 3.0 + t12 * 3.0) / 12.0) *
          3.1415926535897931 / 4.0);
  M[0] = t28;
  M[1] = 0.0;
  M[2] = 0.0;
  M[3] = 0.0;
  M[4] = 0.0;
  M[5] = 0.0;
  M[6] = 0.0;
  M[7] = t28;
  M[8] = 0.0;
  M[9] = 0.0;
  M[10] = 0.0;
  M[11] = 0.0;
  M[12] = 0.0;
  M[13] = 0.0;
  M[14] = t28;
  M[15] = 0.0;
  M[16] = 0.0;
  M[17] = 0.0;
  M[18] = 0.0;
  M[19] = 0.0;
  M[20] = 0.0;
  M[21] = t30;
  M[22] = 0.0;
  M[23] = 0.0;
  M[24] = 0.0;
  M[25] = 0.0;
  M[26] = 0.0;
  M[27] = 0.0;
  M[28] = t30;
  M[29] = 0.0;
  M[30] = 0.0;
  M[31] = 0.0;
  M[32] = 0.0;
  M[33] = 0.0;
  M[34] = 0.0;
  M[35] = t52 * t13 * t21 * 3.1415926535897931 * (t11 / 2.0 + t12 / 2.0) * -0.25;
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
  T[18] = 0.0;
  T[19] = 0.0;
  T[20] = 0.0;
  T[21] = t32 + b_z[3] * t33;
  T[22] = -t6 + step;
  T[23] = t5 + t37;
  T[24] = 0.0;
  T[25] = 0.0;
  T[26] = 0.0;
  T[27] = t6 + step;
  T[28] = t32 + b_z[4] * t34;
  T[29] = -t4 + t38;
  T[30] = 0.0;
  T[31] = 0.0;
  T[32] = 0.0;
  T[33] = -t5 + t37;
  T[34] = t4 + t38;
  T[35] = t32 + b_z[5] * t35;
  memset(&T[36], 0, 108U * sizeof(real_T));
  t32 = t33 + t4 * t8 * t31;
  t52 = t33 + t4 * t9 * t31;
  t28 = t34 + b_z[3] * b_z[4] * t4 * t31;
  t54 = t34 + t5 * t9 * t31;
  t55 = t35 + b_z[3] * b_z[5] * t4 * t31;
  t30 = t35 + t39_tmp * t5 * t31;
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 24; i1++) {
      Tt[i1 + 24 * i] = T[i + 6 * i1];
    }
  }

  st.site = &c_emlrtRSI;
  mtimes(Tt, M, y);
  st.site = &c_emlrtRSI;
  b_mtimes(y, T, unusedExpr);
  st.site = &d_emlrtRSI;
  mtimes(Tt, M, y);
  st.site = &e_emlrtRSI;
  massF2(&st, par_mex.var, b_z, M, T, Dd, fg);
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 24; i1++) {
      Tt[i1 + 24 * i] = T[i + 6 * i1];
    }
  }

  st.site = &f_emlrtRSI;
  mtimes(Tt, M, b_y);
  st.site = &f_emlrtRSI;
  b_mtimes(b_y, T, unusedExpr);
  st.site = &g_emlrtRSI;
  mtimes(Tt, M, b_y);
  st.site = &h_emlrtRSI;
  massF3(&st, par_mex.var, b_z, M, T, b_Dd, b_fg);
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 24; i1++) {
      Tt[i1 + 24 * i] = T[i + 6 * i1];
    }
  }

  st.site = &i_emlrtRSI;
  mtimes(Tt, M, c_y);
  st.site = &i_emlrtRSI;
  b_mtimes(c_y, T, unusedExpr);
  st.site = &j_emlrtRSI;
  mtimes(Tt, M, c_y);
  st.site = &k_emlrtRSI;
  massF4(&st, par_mex.var, b_z, M, T, c_Dd, c_fg);
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 24; i1++) {
      Tt[i1 + 24 * i] = T[i + 6 * i1];
    }
  }

  st.site = &l_emlrtRSI;
  mtimes(Tt, M, d_y);
  st.site = &l_emlrtRSI;
  b_mtimes(d_y, T, unusedExpr);
  st.site = &m_emlrtRSI;
  mtimes(Tt, M, d_y);
  st.site = &n_emlrtRSI;
  massF5(&st, par_mex.var, b_z, M, T, d_Dd, d_fg);
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 24; i1++) {
      Tt[i1 + 24 * i] = T[i + 6 * i1];
    }
  }

  st.site = &o_emlrtRSI;
  mtimes(Tt, M, e_y);
  st.site = &o_emlrtRSI;
  b_mtimes(e_y, T, unusedExpr);
  st.site = &p_emlrtRSI;
  mtimes(Tt, M, e_y);
  st.site = &q_emlrtRSI;
  sprdmpF25(&st, par_mex.var, b_z, kx, vd, in, &step);
  for (i = 0; i < 144; i++) {
    T[i] = step * (real_T)b[i];
  }

  st.site = &r_emlrtRSI;
  sprdmpF26(&st, par_mex.var, b_z, Tt, b_kx, vd, b_in, &step);
  for (i = 0; i < 144; i++) {
    Tt[i] *= step;
  }

  st.site = &s_emlrtRSI;
  sprdmpF27(&st, par_mex.var, b_z, b_Tt, c_kx, vd, c_in, &step);
  for (i = 0; i < 144; i++) {
    b_Tt[i] *= step;
  }

  st.site = &t_emlrtRSI;
  sprdmpF28(&st, par_mex.var, b_z, c_Tt, d_kx, vd, d_in, &step);
  for (i = 0; i < 144; i++) {
    c_Tt[i] *= step;
  }

  st.site = &u_emlrtRSI;

  /* LOADSF1 */
  /*     [OUT1,OUT2,OUT3] = LOADSF1(IN1,IN2,S,DS,T_SYM) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
  /*     26-Feb-2021 21:07:24 */
  t11 = b_z[21] * 2.0;
  t12 = b_z[22] * 2.0;
  t13 = b_z[23] * 2.0;
  t15 = b_z[22] * b_z[22];
  t17 = par_mex.var[16] * t13;
  step = (b_z[21] * par_mex.var[30] + b_z[22] * par_mex.var[31]) + b_z[23] *
    par_mex.var[32];
  t26 = ((-(b_z[21] * b_z[21]) + -t15) + -(b_z[23] * b_z[23])) + 1.0;
  b_st.site = &hg_emlrtRSI;
  if (t26 < 0.0) {
    emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  t26 = muDoubleScalarSqrt(t26);
  t27 = 1.0 / t26;
  b_t31 = t26 * 2.0;
  b_t33 = b_z[22] * t11 * t27;
  b_t34 = b_z[23] * t11 * t27;
  b_t35 = b_z[23] * t12 * t27;
  t37 = (b_z[22] * par_mex.var[30] + -(b_z[21] * par_mex.var[31])) + t26 *
    par_mex.var[32];
  t38 = (b_z[21] * par_mex.var[32] + -(b_z[23] * par_mex.var[30])) + t26 *
    par_mex.var[31];
  b_t39 = (b_z[23] * par_mex.var[31] + -(b_z[22] * par_mex.var[32])) + t26 *
    par_mex.var[30];

  /*  EOM */
  memset(&dv[0], 0, 21U * sizeof(real_T));
  dv[21] = -((t28 * b_z[28] + t55 * b_z[29]) + b_z[27] * (t33 + t4 * t7 * t31));
  dv[22] = -(((t39 + 2.0) * b_z[29] + t28 * b_z[27]) - b_z[28] * (t33 - b_z[3] *
              t8 * t31 * 2.0));
  dv[23] = -(((t39 - 2.0) * b_z[28] + t55 * b_z[27]) - b_z[29] * (t33 - b_z[3] *
              t9 * t31 * 2.0));
  dv[24] = -0.0;
  dv[25] = -0.0;
  dv[26] = -0.0;
  dv[27] = -(((t39 - 2.0) * b_z[29] + t32 * b_z[28]) - b_z[27] * (t34 - b_z[4] *
              t7 * t31 * 2.0));
  dv[28] = -((t32 * b_z[27] + t30 * b_z[29]) + b_z[28] * (t34 + t5 * t8 * t31));
  dv[29] = -(((t39 + 2.0) * b_z[27] + t30 * b_z[28]) - b_z[29] * (t34 - b_z[4] *
              t9 * t31 * 2.0));
  dv[30] = -0.0;
  dv[31] = -0.0;
  dv[32] = -0.0;
  dv[33] = -(((t39 + 2.0) * b_z[28] + t52 * b_z[29]) - b_z[27] * (t35 - b_z[5] *
              t7 * t31 * 2.0));
  dv[34] = -(((t39 - 2.0) * b_z[27] + t54 * b_z[29]) - b_z[28] * (t35 - b_z[5] *
              t8 * t31 * 2.0));
  dv[35] = -((t52 * b_z[27] + t54 * b_z[28]) + b_z[29] * (t35 + t6 * t9 * t31));
  memset(&dv[36], 0, 108U * sizeof(real_T));
  vd[0] = par_mex.var[12];
  vd[1] = par_mex.var[13];
  vd[2] = par_mex.var[14];
  vd[3] = 0.0;
  vd[4] = 0.0;
  vd[5] = 0.0;
  for (i = 0; i < 6; i++) {
    t39 = 0.0;
    for (i1 = 0; i1 < 24; i1++) {
      t39 += dv[i + 6 * i1] * b_z[i1 + 24];
    }

    dv1[i] = t39 + vd[i];
  }

  for (i = 0; i < 144; i++) {
    Dd[i] = -Dd[i];
  }

  for (i = 0; i < 6; i++) {
    t39 = 0.0;
    for (i1 = 0; i1 < 24; i1++) {
      t39 += Dd[i + 6 * i1] * b_z[i1 + 24];
    }

    e_Dd[i] = t39 + fg[i];
  }

  for (i = 0; i < 24; i++) {
    t39 = 0.0;
    t31 = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      i2 = i + 24 * i1;
      t39 += y[i2] * dv1[i1];
      t31 += b_y[i2] * e_Dd[i1];
    }

    f_y[i] = t31;
    dv2[i] = t39;
  }

  for (i = 0; i < 144; i++) {
    b_Dd[i] = -b_Dd[i];
  }

  for (i = 0; i < 6; i++) {
    t39 = 0.0;
    for (i1 = 0; i1 < 24; i1++) {
      t39 += b_Dd[i + 6 * i1] * b_z[i1 + 24];
    }

    e_Dd[i] = t39 + b_fg[i];
  }

  for (i = 0; i < 144; i++) {
    c_Dd[i] = -c_Dd[i];
  }

  for (i = 0; i < 6; i++) {
    t39 = 0.0;
    for (i1 = 0; i1 < 24; i1++) {
      t39 += c_Dd[i + 6 * i1] * b_z[i1 + 24];
    }

    vd[i] = t39 + c_fg[i];
  }

  for (i = 0; i < 24; i++) {
    t39 = 0.0;
    t31 = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      i2 = i + 24 * i1;
      t39 += c_y[i2] * e_Dd[i1];
      t31 += d_y[i2] * vd[i1];
    }

    dv3[i] = (dv2[i] + f_y[i]) + t39;
    f_y[i] = t31;
  }

  for (i = 0; i < 144; i++) {
    d_Dd[i] = -d_Dd[i];
  }

  for (i = 0; i < 6; i++) {
    t39 = 0.0;
    for (i1 = 0; i1 < 24; i1++) {
      t39 += d_Dd[i + 6 * i1] * b_z[i1 + 24];
    }

    e_Dd[i] = t39 + d_fg[i];
  }

  dv1[0] = par_mex.var[27];
  dv1[1] = par_mex.var[28];
  dv1[2] = par_mex.var[29];
  dv1[3] = ((b_z[21] * step - b_z[22] * t37) + b_z[23] * t38) + t26 * b_t39;
  dv1[4] = ((b_z[22] * step + b_z[21] * t37) - b_z[23] * b_t39) + t26 * t38;
  dv1[5] = ((b_z[23] * step - b_z[21] * t38) + b_z[22] * b_t39) + t26 * t37;
  for (i = 0; i < 24; i++) {
    t39 = 0.0;
    t31 = 0.0;
    step = 0.0;
    t30 = 0.0;
    t32 = 0.0;
    t52 = 0.0;
    t28 = 0.0;
    t21 = 0.0;
    t39_tmp = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      i2 = i + 24 * i1;
      t54 = T[i2];
      t39 += t54 * kx[i1];
      t55 = Tt[i2];
      step += t55 * b_kx[i1];
      b_t39 = b_Tt[i2];
      t31 += b_t39 * c_kx[i1];
      t35 = c_Tt[i2];
      t52 += t35 * d_kx[i1];
      t30 += t54 * in[i1];
      t28 += t55 * b_in[i1];
      t32 += b_t39 * c_in[i1];
      t39_tmp += t35 * d_in[i1];
      t21 += e_y[i2] * e_Dd[i1];
    }

    res[i] = (((dv3[i] + f_y[i]) + t21) + (((t39 + step) + t31) + t52)) + (((t30
      + t28) + t32) + t39_tmp);
  }

  memset(&Tt[0], 0, 18U * sizeof(real_T));
  Tt[18] = 1.0;
  Tt[19] = 0.0;
  Tt[20] = 0.0;
  t30 = par_mex.var[16] * b_z[21];
  Tt[21] = t17 - t30 * b_z[22] * t27 * 2.0;
  Tt[22] = par_mex.var[16] * b_t31 - par_mex.var[16] * t15 * t27 * 2.0;
  step = par_mex.var[16] * b_z[22];
  Tt[23] = par_mex.var[16] * t11 - step * b_z[23] * t27 * 2.0;
  memset(&Tt[24], 0, 19U * sizeof(real_T));
  Tt[43] = 1.0;
  Tt[44] = 0.0;
  Tt[45] = par_mex.var[16] * t26 * -2.0 + t30 * t11 * t27;
  Tt[46] = t17 + par_mex.var[16] * b_t33;
  Tt[47] = par_mex.var[16] * t12 + par_mex.var[16] * b_t34;
  memset(&Tt[48], 0, 20U * sizeof(real_T));
  Tt[68] = 1.0;
  Tt[69] = t30 * -4.0;
  Tt[70] = step * -4.0;
  memset(&Tt[71], 0, 22U * sizeof(real_T));
  Tt[93] = b_t31 + b_z[21] * t11 * t27;
  Tt[94] = t13 + b_t33;
  Tt[95] = -t12 + b_t34;
  memset(&Tt[96], 0, 21U * sizeof(real_T));
  Tt[117] = -t13 + b_t33;
  Tt[118] = b_t31 + b_z[22] * t12 * t27;
  Tt[119] = t11 + b_t35;
  memset(&Tt[120], 0, 21U * sizeof(real_T));
  Tt[141] = t12 + b_t34;
  Tt[142] = -t11 + b_t35;
  Tt[143] = b_t31 + b_z[23] * t13 * t27;
  for (i = 0; i < 24; i++) {
    t39 = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      t39 += Tt[i + 24 * i1] * dv1[i1];
    }

    res[i] += t39;
  }
}

/* End of code generation (EOM_eq.c) */
