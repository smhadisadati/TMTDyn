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
#include "massF1.h"
#include "massF2.h"
#include "massF3.h"
#include "mtimes.h"
#include "rt_nonfinite.h"
#include "sprdmpF19.h"
#include "sprdmpF20.h"
#include "sprdmpF21.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 9,     /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 21,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 23,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 24,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 26,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 28,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 29,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 31,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 33,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 34,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 36,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 38,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 39,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 41,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 46,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 51,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 57,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo oc_emlrtRSI = { 39, /* lineNo */
  "massF4",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\massF4.m"/* pathName */
};

static emlrtRSInfo cf_emlrtRSI = { 42, /* lineNo */
  "loadsF1",                           /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\loadsF1.m"/* pathName */
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

static emlrtDCInfo emlrtDCI = { 10,    /* lineNo */
  34,                                  /* colNo */
  "static_mid_step",                   /* fName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\static_mid_step.m",/* pName */
  1                                    /* checkKind */
};

/* Function Definitions */
void EOM_eq(const emlrtStack *sp, const real_T z[18], real_T res[18])
{
  static const int8_T b[108] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T iv[6] = { 0, 0, 1, 1, 2, 2 };

  emlrtStack b_st;
  emlrtStack st;
  real_T unusedExpr[324];
  real_T Dd[108];
  real_T T[108];
  real_T Tt[108];
  real_T b_Dd[108];
  real_T b_Tt[108];
  real_T b_y[108];
  real_T c_Dd[108];
  real_T c_y[108];
  real_T d_y[108];
  real_T y[108];
  real_T M[36];
  real_T b_z[36];
  real_T dv[18];
  real_T dv1[18];
  real_T e_y[18];
  real_T b_fg[6];
  real_T b_in[6];
  real_T b_kx[6];
  real_T c_fg[6];
  real_T c_in[6];
  real_T c_kx[6];
  real_T d_Dd[6];
  real_T fg[6];
  real_T in[6];
  real_T kx[6];
  real_T vd[6];
  real_T b_t24;
  real_T b_t27;
  real_T b_t31;
  real_T b_t37;
  real_T d;
  real_T d1;
  real_T step;
  real_T t11;
  real_T t12;
  real_T t17;
  real_T t2;
  real_T t22;
  real_T t24;
  real_T t25;
  real_T t26;
  real_T t27;
  real_T t28;
  real_T t29;
  real_T t30;
  real_T t30_tmp;
  real_T t31;
  real_T t31_tmp;
  real_T t33;
  real_T t34;
  real_T t35;
  real_T t37;
  real_T t37_tmp;
  real_T t38;
  real_T t39;
  real_T t49;
  real_T t4_tmp;
  real_T t53;
  real_T t54;
  real_T t55;
  real_T t56;
  real_T t57;
  real_T t58;
  real_T t59;
  real_T t5_tmp;
  real_T t62;
  real_T t63;
  real_T t64;
  real_T t65;
  real_T t6_tmp;
  real_T t7;
  real_T t9_tmp;
  int32_T i;
  int32_T i1;
  int32_T i2;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  for (i = 0; i < 18; i++) {
    d = z[i];
    b_z[i] = d;
    b_z[i + 18] = 0.0 * d;
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
  massF1(&st, par_mex.var, b_z, M, T, Dd, fg);
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 18; i1++) {
      Tt[i1 + 18 * i] = T[i + 6 * i1];
    }
  }

  st.site = &c_emlrtRSI;
  mtimes(Tt, M, y);
  st.site = &c_emlrtRSI;
  b_mtimes(y, T, unusedExpr);
  st.site = &d_emlrtRSI;
  mtimes(Tt, M, y);
  st.site = &e_emlrtRSI;
  massF2(&st, par_mex.var, b_z, M, T, b_Dd, b_fg);
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 18; i1++) {
      Tt[i1 + 18 * i] = T[i + 6 * i1];
    }
  }

  st.site = &f_emlrtRSI;
  mtimes(Tt, M, b_y);
  st.site = &f_emlrtRSI;
  b_mtimes(b_y, T, unusedExpr);
  st.site = &g_emlrtRSI;
  mtimes(Tt, M, b_y);
  st.site = &h_emlrtRSI;
  massF3(&st, par_mex.var, b_z, M, T, c_Dd, c_fg);
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 18; i1++) {
      Tt[i1 + 18 * i] = T[i + 6 * i1];
    }
  }

  st.site = &i_emlrtRSI;
  mtimes(Tt, M, c_y);
  st.site = &i_emlrtRSI;
  b_mtimes(c_y, T, unusedExpr);
  st.site = &j_emlrtRSI;
  mtimes(Tt, M, c_y);
  st.site = &k_emlrtRSI;

  /* MASSF4 */
  /*     [OUT1,OUT2,OUT3,OUT4] = MASSF4(IN1,IN2,S,DS,T_SYM) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
  /*     15-Jun-2021 01:39:21 */
  t2 = par_mex.var[16] * b_z[17];
  step = par_mex.var[16] * par_mex.var[16];
  t4_tmp = b_z[15] * 2.0;
  t5_tmp = b_z[16] * 2.0;
  t6_tmp = b_z[17] * 2.0;
  t7 = b_z[15] * b_z[15];
  t9_tmp = b_z[16] * b_z[16];
  t11 = b_z[17] * b_z[17];
  t12 = par_mex.var[17] * par_mex.var[17];
  t22 = ((-t7 + -t9_tmp) + -t11) + 1.0;
  b_st.site = &oc_emlrtRSI;
  if (t22 < 0.0) {
    emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  t22 = muDoubleScalarSqrt(t22);
  step = par_mex.var[15] * step / 4.0 + par_mex.var[15] * (step + t12 * 3.0) /
    12.0;
  M[0] = par_mex.var[15];
  M[1] = 0.0;
  M[2] = 0.0;
  M[3] = 0.0;
  M[4] = 0.0;
  M[5] = 0.0;
  M[6] = 0.0;
  M[7] = par_mex.var[15];
  M[8] = 0.0;
  M[9] = 0.0;
  M[10] = 0.0;
  M[11] = 0.0;
  M[12] = 0.0;
  M[13] = 0.0;
  M[14] = par_mex.var[15];
  M[15] = 0.0;
  M[16] = 0.0;
  M[17] = 0.0;
  M[18] = 0.0;
  M[19] = 0.0;
  M[20] = 0.0;
  M[21] = step;
  M[22] = 0.0;
  M[23] = 0.0;
  M[24] = 0.0;
  M[25] = 0.0;
  M[26] = 0.0;
  M[27] = 0.0;
  M[28] = step;
  M[29] = 0.0;
  M[30] = 0.0;
  M[31] = 0.0;
  M[32] = 0.0;
  M[33] = 0.0;
  M[34] = 0.0;
  M[35] = par_mex.var[15] * t12 / 2.0;
  t12 = 1.0 / t22;
  t25 = par_mex.var[16] * t22;
  t26 = t22 * 2.0;
  t24 = muDoubleScalarPower(t12, 3.0);
  t27 = t4_tmp * t12;
  t28 = t5_tmp * t12;
  t29 = t6_tmp * t12;
  t30_tmp = par_mex.var[16] * b_z[15];
  t30 = t30_tmp * t12;
  t31_tmp = par_mex.var[16] * b_z[16];
  t31 = t31_tmp * t12;
  t22 = t2 * t12;
  t33 = b_z[16] * t27;
  t34 = b_z[17] * t27;
  t35 = b_z[17] * t28;
  step = b_z[16] * t30;
  memset(&T[0], 0, 72U * sizeof(real_T));
  T[72] = 1.0;
  T[73] = 0.0;
  T[74] = 0.0;
  T[75] = 0.0;
  T[76] = 0.0;
  T[77] = 0.0;
  T[78] = 0.0;
  T[79] = 1.0;
  T[80] = 0.0;
  T[81] = 0.0;
  T[82] = 0.0;
  T[83] = 0.0;
  T[84] = 0.0;
  T[85] = 0.0;
  T[86] = 1.0;
  T[87] = 0.0;
  T[88] = 0.0;
  T[89] = 0.0;
  T[90] = t2 - step;
  T[91] = -t25 + par_mex.var[16] * t7 * t12;
  T[92] = t30_tmp * -2.0;
  T[93] = t26 + b_z[15] * t27;
  T[94] = -t6_tmp + t33;
  T[95] = t5_tmp + t34;
  T[96] = t25 + par_mex.var[16] * -t9_tmp * t12;
  T[97] = t2 + step;
  T[98] = t31_tmp * -2.0;
  T[99] = t6_tmp + t33;
  T[100] = t26 + b_z[16] * t28;
  T[101] = -t4_tmp + t35;
  T[102] = t30_tmp - b_z[16] * t22;
  T[103] = t31_tmp + b_z[15] * t22;
  T[104] = 0.0;
  T[105] = -t5_tmp + t34;
  T[106] = t4_tmp + t35;
  T[107] = t26 + b_z[17] * t29;
  t37_tmp = b_z[16] * b_z[17];
  t37 = t37_tmp * t4_tmp * t24;
  step = b_z[15] * b_z[16];
  t38 = step * t2 * t24;
  t49 = par_mex.var[16] + t38;
  t54 = t30 + t30_tmp * t9_tmp * t24;
  t55 = t31 + t31_tmp * t7 * t24;
  t56 = t22 + t2 * t7 * t24;
  t57 = t22 + t2 * t9_tmp * t24;
  t58 = t27 + t4_tmp * t9_tmp * t24;
  t59 = t27 + t4_tmp * t11 * t24;
  t12 = t28 + step * t4_tmp * t24;
  t22 = t28 + t5_tmp * t11 * t24;
  t25 = b_z[15] * b_z[17];
  t62 = t29 + t25 * t4_tmp * t24;
  t63 = t29 + t37_tmp * t5_tmp * t24;
  t53 = par_mex.var[16] + -t38;
  t64 = t55 * b_z[33];
  t65 = t54 * b_z[34];
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 18; i1++) {
      Tt[i1 + 18 * i] = T[i + 6 * i1];
    }
  }

  st.site = &l_emlrtRSI;
  mtimes(Tt, M, d_y);
  st.site = &l_emlrtRSI;
  b_mtimes(d_y, T, unusedExpr);
  st.site = &m_emlrtRSI;
  mtimes(Tt, M, d_y);
  st.site = &n_emlrtRSI;
  sprdmpF19(&st, par_mex.var, b_z, kx, vd, in, &step);
  for (i = 0; i < 108; i++) {
    T[i] = step * (real_T)b[i];
  }

  st.site = &o_emlrtRSI;
  sprdmpF20(&st, par_mex.var, b_z, Tt, b_kx, vd, b_in, &step);
  for (i = 0; i < 108; i++) {
    Tt[i] *= step;
  }

  st.site = &p_emlrtRSI;
  sprdmpF21(&st, par_mex.var, b_z, b_Tt, c_kx, vd, c_in, &step);
  for (i = 0; i < 108; i++) {
    b_Tt[i] *= step;
  }

  st.site = &q_emlrtRSI;

  /* LOADSF1 */
  /*     [OUT1,OUT2,OUT3] = LOADSF1(IN1,IN2,S,DS,T_SYM) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
  /*     15-Jun-2021 01:39:28 */
  t17 = par_mex.var[16] * t6_tmp;
  b_t24 = (b_z[15] * par_mex.var[30] + b_z[16] * par_mex.var[31]) + b_z[17] *
    par_mex.var[32];
  t26 = ((-(b_z[15] * b_z[15]) + -t9_tmp) + -(b_z[17] * b_z[17])) + 1.0;
  b_st.site = &cf_emlrtRSI;
  if (t26 < 0.0) {
    emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  t26 = muDoubleScalarSqrt(t26);
  b_t27 = 1.0 / t26;
  b_t31 = t26 * 2.0;
  t33 = b_z[16] * t4_tmp * b_t27;
  t34 = b_z[17] * t4_tmp * b_t27;
  t35 = b_z[17] * t5_tmp * b_t27;
  b_t37 = (b_z[16] * par_mex.var[30] + -(b_z[15] * par_mex.var[31])) + t26 *
    par_mex.var[32];
  t38 = (b_z[15] * par_mex.var[32] + -(b_z[17] * par_mex.var[30])) + t26 *
    par_mex.var[31];
  t39 = (b_z[17] * par_mex.var[31] + -(b_z[16] * par_mex.var[32])) + t26 *
    par_mex.var[30];

  /*  EOM */
  for (i = 0; i < 108; i++) {
    Dd[i] = -Dd[i];
  }

  for (i = 0; i < 6; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 18; i1++) {
      d += Dd[i + 6 * i1] * b_z[i1 + 18];
    }

    d_Dd[i] = d + fg[i];
  }

  for (i = 0; i < 108; i++) {
    b_Dd[i] = -b_Dd[i];
  }

  for (i = 0; i < 6; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 18; i1++) {
      d += b_Dd[i + 6 * i1] * b_z[i1 + 18];
    }

    fg[i] = d + b_fg[i];
  }

  for (i = 0; i < 18; i++) {
    d = 0.0;
    d1 = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      i2 = i + 18 * i1;
      d += y[i2] * d_Dd[i1];
      d1 += b_y[i2] * fg[i1];
    }

    e_y[i] = d1;
    dv[i] = d;
  }

  for (i = 0; i < 108; i++) {
    c_Dd[i] = -c_Dd[i];
  }

  memset(&Dd[0], 0, 90U * sizeof(real_T));
  Dd[90] = -((-t64 - t65) + t53 * b_z[35]);
  Dd[91] = -((t55 * b_z[34] + t56 * b_z[35]) + b_z[33] * (t30 * 3.0 +
              par_mex.var[16] * muDoubleScalarPower(b_z[15], 3.0) * t24));
  Dd[92] = -(par_mex.var[16] * b_z[33] * -2.0);
  Dd[93] = -((t12 * b_z[34] + t62 * b_z[35]) + b_z[33] * (t27 + t4_tmp * t7 *
              t24));
  Dd[94] = -(((t37 + 2.0) * b_z[35] + t12 * b_z[33]) - b_z[34] * (t27 - b_z[15] *
              t9_tmp * t24 * 2.0));
  Dd[95] = -(((t37 - 2.0) * b_z[34] + t62 * b_z[33]) - b_z[35] * (t27 - b_z[15] *
              t11 * t24 * 2.0));
  Dd[96] = -((-t54 * b_z[33] - t57 * b_z[35]) - b_z[34] * (t31 * 3.0 +
              par_mex.var[16] * muDoubleScalarPower(b_z[16], 3.0) * t24));
  Dd[97] = -((t64 + t65) + t49 * b_z[35]);
  Dd[98] = -(par_mex.var[16] * b_z[34] * -2.0);
  Dd[99] = -(((t37 - 2.0) * b_z[35] + t58 * b_z[34]) - b_z[33] * (t28 - b_z[16] *
              t7 * t24 * 2.0));
  Dd[100] = -((t58 * b_z[33] + t63 * b_z[35]) + b_z[34] * (t28 + t5_tmp * t9_tmp
    * t24));
  Dd[101] = -(((t37 + 2.0) * b_z[33] + t63 * b_z[34]) - b_z[35] * (t28 - b_z[16]
    * t11 * t24 * 2.0));
  Dd[102] = -((t53 * b_z[33] - t57 * b_z[34]) - b_z[35] * (t31 + t37_tmp * t2 *
    t24));
  Dd[103] = -((t49 * b_z[34] + t56 * b_z[33]) + b_z[35] * (t30 + t25 * t2 * t24));
  Dd[104] = -0.0;
  Dd[105] = -(((t37 + 2.0) * b_z[34] + t59 * b_z[35]) - b_z[33] * (t29 - b_z[17]
    * t7 * t24 * 2.0));
  Dd[106] = -(((t37 - 2.0) * b_z[33] + t22 * b_z[35]) - b_z[34] * (t29 - b_z[17]
    * t9_tmp * t24 * 2.0));
  Dd[107] = -((t59 * b_z[33] + t22 * b_z[34]) + b_z[35] * (t29 + t6_tmp * t11 *
    t24));
  fg[0] = par_mex.var[12];
  fg[1] = par_mex.var[13];
  fg[2] = par_mex.var[14];
  fg[3] = 0.0;
  fg[4] = 0.0;
  fg[5] = 0.0;
  for (i = 0; i < 6; i++) {
    d = 0.0;
    d1 = 0.0;
    for (i1 = 0; i1 < 18; i1++) {
      i2 = i + 6 * i1;
      step = b_z[i1 + 18];
      d += c_Dd[i2] * step;
      d1 += Dd[i2] * step;
    }

    d_Dd[i] = d + c_fg[i];
    vd[i] = d1 + fg[i];
  }

  for (i = 0; i < 18; i++) {
    d = 0.0;
    d1 = 0.0;
    step = 0.0;
    t12 = 0.0;
    t22 = 0.0;
    t25 = 0.0;
    t62 = 0.0;
    t63 = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      i2 = i + 18 * i1;
      d += c_y[i2] * d_Dd[i1];
      t25 += d_y[i2] * vd[i1];
      t53 = T[i2];
      d1 += t53 * kx[i1];
      t64 = Tt[i2];
      t62 += t64 * b_kx[i1];
      step += t53 * in[i1];
      t63 += t64 * b_in[i1];
      t53 = b_Tt[i2];
      t12 += t53 * c_kx[i1];
      t22 += t53 * c_in[i1];
    }

    d += dv[i] + e_y[i];
    e_y[i] = t25;
    dv1[i] = (d + t25) + ((d1 + t62) + t12);
    dv[i] = (step + t63) + t22;
  }

  memset(&Tt[0], 0, 12U * sizeof(real_T));
  Tt[12] = 1.0;
  Tt[13] = 0.0;
  Tt[14] = 0.0;
  Tt[15] = t17 - t30_tmp * b_z[16] * b_t27 * 2.0;
  Tt[16] = par_mex.var[16] * b_t31 - par_mex.var[16] * t9_tmp * b_t27 * 2.0;
  Tt[17] = par_mex.var[16] * t4_tmp - t31_tmp * b_z[17] * b_t27 * 2.0;
  memset(&Tt[18], 0, 13U * sizeof(real_T));
  Tt[31] = 1.0;
  Tt[32] = 0.0;
  Tt[33] = par_mex.var[16] * t26 * -2.0 + t30_tmp * t4_tmp * b_t27;
  Tt[34] = t17 + par_mex.var[16] * t33;
  Tt[35] = par_mex.var[16] * t5_tmp + par_mex.var[16] * t34;
  memset(&Tt[36], 0, 14U * sizeof(real_T));
  Tt[50] = 1.0;
  Tt[51] = t30_tmp * -4.0;
  Tt[52] = t31_tmp * -4.0;
  memset(&Tt[53], 0, 16U * sizeof(real_T));
  Tt[69] = b_t31 + b_z[15] * t4_tmp * b_t27;
  Tt[70] = t6_tmp + t33;
  Tt[71] = -t5_tmp + t34;
  memset(&Tt[72], 0, 15U * sizeof(real_T));
  Tt[87] = -t6_tmp + t33;
  Tt[88] = b_t31 + b_z[16] * t5_tmp * b_t27;
  Tt[89] = t4_tmp + t35;
  memset(&Tt[90], 0, 15U * sizeof(real_T));
  Tt[105] = t5_tmp + t34;
  Tt[106] = -t4_tmp + t35;
  Tt[107] = b_t31 + b_z[17] * t6_tmp * b_t27;
  vd[0] = par_mex.var[27];
  vd[1] = par_mex.var[28];
  vd[2] = par_mex.var[29];
  vd[3] = ((b_z[15] * b_t24 - b_z[16] * b_t37) + b_z[17] * t38) + t26 * t39;
  vd[4] = ((b_z[16] * b_t24 + b_z[15] * b_t37) - b_z[17] * t39) + t26 * t38;
  vd[5] = ((b_z[17] * b_t24 - b_z[15] * t38) + b_z[16] * t39) + t26 * b_t37;
  for (i = 0; i < 18; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      d += Tt[i + 18 * i1] * vd[i1];
    }

    res[i] = (dv1[i] + dv[i]) + d;
  }
}

/* End of code generation (EOM_eq.c) */
