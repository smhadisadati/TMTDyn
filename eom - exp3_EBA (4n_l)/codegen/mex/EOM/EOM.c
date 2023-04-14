/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EOM.c
 *
 * Code generation for function 'EOM'
 *
 */

/* Include files */
#include "EOM.h"
#include "EOM_data.h"
#include "EOM_types.h"
#include "massF1.h"
#include "massF2.h"
#include "massF3.h"
#include "massF4.h"
#include "mtimes.h"
#include "pinv.h"
#include "rt_nonfinite.h"
#include "sprdmpF20.h"
#include "sprdmpF21.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 6,     /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 19,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 21,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 22,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 24,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 26,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 27,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 29,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 31,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 32,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 34,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 36,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 37,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 39,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 44,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 49,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 55,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 65,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo df_emlrtRSI = { 42, /* lineNo */
  "loadsF1",                           /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\loadsF1.m"/* pathName */
};

static emlrtDCInfo emlrtDCI = { 10,    /* lineNo */
  34,                                  /* colNo */
  "dyn_mid_step",                      /* fName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\dyn_mid_step.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo emlrtBCI = { 1,     /* iFirst */
  1094,                                /* iLast */
  10,                                  /* lineNo */
  34,                                  /* colNo */
  "par_mex.user_pars.f_ex",            /* aName */
  "dyn_mid_step",                      /* fName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\dyn_mid_step.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void EOM(const emlrtStack *sp, real_T t, const real_T z[36], const struct0_T
         *par_mex, real_T dz[36], real_T *flag)
{
  static const int8_T w_vd_j_tmp[108] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T iv[6] = { 0, 0, 1, 1, 2, 2 };

  emlrtStack b_st;
  emlrtStack st;
  real_T b_y[324];
  real_T d_y[324];
  real_T f_y[324];
  real_T h_y[324];
  real_T Dd[108];
  real_T T[108];
  real_T Tt[108];
  real_T b_Dd[108];
  real_T c_Dd[108];
  real_T c_y[108];
  real_T d_Dd[108];
  real_T e_y[108];
  real_T g_y[108];
  real_T y[108];
  real_T M[36];
  real_T par_mex_var[34];
  real_T b_Tt[18];
  real_T dv[18];
  real_T dv1[18];
  real_T dv2[18];
  real_T i_y[18];
  real_T b_fg[6];
  real_T b_in[6];
  real_T b_kx[6];
  real_T b_vd[6];
  real_T c_fg[6];
  real_T d_fg[6];
  real_T e_Dd[6];
  real_T fg[6];
  real_T in[6];
  real_T kx[6];
  real_T vd[6];
  real_T b_fg_tmp;
  real_T b_t13;
  real_T b_t33;
  real_T fg_tmp;
  real_T step;
  real_T t11;
  real_T t12;
  real_T t13;
  real_T t15;
  real_T t16;
  real_T t17;
  real_T t23;
  real_T t24;
  real_T t26;
  real_T t27;
  real_T t31;
  real_T t33;
  real_T t34;
  real_T t35;
  real_T t37;
  real_T t38;
  real_T t39;
  real_T t6;
  real_T t8;
  real_T t9;
  int32_T i;
  int32_T i1;
  int32_T i2;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  memcpy(&par_mex_var[0], &par_mex->var[0], 34U * sizeof(real_T));

  /*  parameters */
  /*  inputs: internal pressure & external forces/torques */
  /*  temp = interp1( par.f_ex(:,1) , [ par.f_ex(:,2:7) par.p(:,2:4) ] , t , 'nearest' ) ; */
  step = muDoubleScalarFloor(t / 0.05);
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
    par_mex_var[i + 21] = par_mex->user_pars.p[((int32_T)step + 1094 * (iv[i] +
      1)) - 1];
    par_mex_var[i + 27] = par_mex->user_pars.f_ex[((int32_T)step + 1094 * (i + 1))
      - 1];
  }

  par_mex_var[33] = 1.0;
  st.site = &b_emlrtRSI;
  massF1(&st, par_mex_var, z, M, T, Dd, fg);
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 18; i1++) {
      Tt[i1 + 18 * i] = T[i + 6 * i1];
    }
  }

  st.site = &c_emlrtRSI;
  mtimes(Tt, M, y);
  st.site = &c_emlrtRSI;
  b_mtimes(y, T, b_y);
  st.site = &d_emlrtRSI;
  mtimes(Tt, M, y);
  st.site = &e_emlrtRSI;
  massF2(&st, par_mex_var, z, M, T, b_Dd, b_fg);
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 18; i1++) {
      Tt[i1 + 18 * i] = T[i + 6 * i1];
    }
  }

  st.site = &f_emlrtRSI;
  mtimes(Tt, M, c_y);
  st.site = &f_emlrtRSI;
  b_mtimes(c_y, T, d_y);
  st.site = &g_emlrtRSI;
  mtimes(Tt, M, c_y);
  st.site = &h_emlrtRSI;
  massF3(&st, par_mex_var, z, M, T, c_Dd, c_fg);
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 18; i1++) {
      Tt[i1 + 18 * i] = T[i + 6 * i1];
    }
  }

  st.site = &i_emlrtRSI;
  mtimes(Tt, M, e_y);
  st.site = &i_emlrtRSI;
  b_mtimes(e_y, T, f_y);
  st.site = &j_emlrtRSI;
  mtimes(Tt, M, e_y);
  st.site = &k_emlrtRSI;
  massF4(&st, par_mex_var, z, M, T, d_Dd, d_fg);
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 18; i1++) {
      Tt[i1 + 18 * i] = T[i + 6 * i1];
    }
  }

  st.site = &l_emlrtRSI;
  mtimes(Tt, M, g_y);
  st.site = &l_emlrtRSI;
  b_mtimes(g_y, T, h_y);
  st.site = &m_emlrtRSI;
  mtimes(Tt, M, g_y);
  st.site = &n_emlrtRSI;

  /* SPRDMPF19 */
  /*     [OUT1,OUT2,OUT3,OUT4,OUT5,OUT6,OUT7] = SPRDMPF19(IN1,IN2,S,DS,T_SYM) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
  /*     15-Jun-2021 01:39:25 */
  t33 = muDoubleScalarCos(par_mex_var[20]);
  step = muDoubleScalarSin(par_mex_var[20]);
  t6 = par_mex_var[18] * par_mex_var[18];
  t8 = par_mex_var[2] * par_mex_var[2];
  t9 = par_mex_var[3] * par_mex_var[3];
  t13 = 1.0 / par_mex_var[4];
  t16 = 1.0 / (step * step);
  t23 = t33 * t33;
  t33 = (t8 + -t9) + -(t6 * t16 * (t23 - 1.0) * 6.0);
  t8 = (t8 * t8 + -(t9 * t9)) + t6 * t6 * (t16 * t16) * ((t23 - 1.0) * (t23 -
    1.0)) * 6.0;
  st.site = &o_emlrtRSI;
  sprdmpF20(&st, par_mex_var, z, Tt, kx, vd, in, &step);
  st.site = &p_emlrtRSI;
  sprdmpF21(&st, par_mex_var, z, T, b_kx, b_vd, b_in, &step);
  st.site = &q_emlrtRSI;

  /* LOADSF1 */
  /*     [OUT1,OUT2,OUT3] = LOADSF1(IN1,IN2,S,DS,T_SYM) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
  /*     15-Jun-2021 01:39:28 */
  t11 = z[15] * 2.0;
  t12 = z[16] * 2.0;
  b_t13 = z[17] * 2.0;
  t15 = z[16] * z[16];
  t17 = par_mex_var[16] * b_t13;
  t24 = (z[15] * par_mex_var[30] + z[16] * par_mex_var[31]) + z[17] *
    par_mex_var[32];
  t26 = ((-(z[15] * z[15]) + -t15) + -(z[17] * z[17])) + 1.0;
  b_st.site = &df_emlrtRSI;
  if (t26 < 0.0) {
    emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  t26 = muDoubleScalarSqrt(t26);
  t27 = 1.0 / t26;
  t31 = t26 * 2.0;
  b_t33 = z[16] * t11 * t27;
  t34 = z[17] * t11 * t27;
  t35 = z[17] * t12 * t27;
  t37 = (z[16] * par_mex_var[30] + -(z[15] * par_mex_var[31])) + t26 *
    par_mex_var[32];
  t38 = (z[15] * par_mex_var[32] + -(z[17] * par_mex_var[30])) + t26 *
    par_mex_var[31];
  t39 = (z[17] * par_mex_var[31] + -(z[16] * par_mex_var[32])) + t26 *
    par_mex_var[30];

  /*  EOM */
  for (i = 0; i < 324; i++) {
    d_y[i] = ((b_y[i] + d_y[i]) + f_y[i]) + h_y[i];
  }

  st.site = &r_emlrtRSI;
  pinv(&st, d_y, b_y);
  for (i = 0; i < 108; i++) {
    Dd[i] = -Dd[i];
  }

  for (i = 0; i < 6; i++) {
    t9 = 0.0;
    for (i1 = 0; i1 < 18; i1++) {
      t9 += Dd[i + 6 * i1] * z[i1 + 18];
    }

    e_Dd[i] = t9 + fg[i];
  }

  for (i = 0; i < 108; i++) {
    b_Dd[i] = -b_Dd[i];
  }

  for (i = 0; i < 6; i++) {
    t9 = 0.0;
    for (i1 = 0; i1 < 18; i1++) {
      t9 += b_Dd[i + 6 * i1] * z[i1 + 18];
    }

    fg[i] = t9 + b_fg[i];
  }

  for (i = 0; i < 18; i++) {
    t9 = 0.0;
    fg_tmp = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      i2 = i + 18 * i1;
      t9 += y[i2] * e_Dd[i1];
      fg_tmp += c_y[i2] * fg[i1];
    }

    i_y[i] = fg_tmp;
    dv[i] = t9;
  }

  for (i = 0; i < 108; i++) {
    c_Dd[i] = -c_Dd[i];
  }

  for (i = 0; i < 6; i++) {
    t9 = 0.0;
    for (i1 = 0; i1 < 18; i1++) {
      t9 += c_Dd[i + 6 * i1] * z[i1 + 18];
    }

    e_Dd[i] = t9 + c_fg[i];
  }

  for (i = 0; i < 108; i++) {
    d_Dd[i] = -d_Dd[i];
  }

  for (i = 0; i < 6; i++) {
    t9 = 0.0;
    for (i1 = 0; i1 < 18; i1++) {
      t9 += d_Dd[i + 6 * i1] * z[i1 + 18];
    }

    fg[i] = t9 + d_fg[i];
  }

  for (i = 0; i < 18; i++) {
    t9 = 0.0;
    fg_tmp = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      i2 = i + 18 * i1;
      t9 += e_y[i2] * e_Dd[i1];
      fg_tmp += g_y[i2] * fg[i1];
    }

    dv1[i] = (dv[i] + i_y[i]) + t9;
    i_y[i] = fg_tmp;
  }

  fg[0] = par_mex_var[1] * z[0] * t13 * t33 * 3.1415926535897931;
  fg[1] = par_mex_var[1] * z[1] * t13 * t33 * 3.1415926535897931;
  fg[2] = par_mex_var[1] * t13 * t33 * 3.1415926535897931 * (z[2] - par_mex_var
    [4] / 3.0) * 3.0;
  step = par_mex_var[19] * par_mex_var[19] * t6 * t16 * (t23 - 1.0) *
    3.1415926535897931;
  b_fg_tmp = t8 * 3.1415926535897931 / 4.0 - step * 3.0;
  fg[3] = par_mex_var[1] * z[3] * t13 * b_fg_tmp * 6.0;
  fg[4] = par_mex_var[1] * z[4] * t13 * b_fg_tmp * 6.0;
  fg[5] = par_mex_var[1] * z[5] * t13 * (t8 * 3.1415926535897931 / 2.0 - step) *
    2.0;
  for (i = 0; i < 18; i++) {
    t9 = 0.0;
    fg_tmp = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      i2 = i + 18 * i1;
      t9 += (real_T)w_vd_j_tmp[i2] * fg[i1];
      fg_tmp += Tt[i2] * kx[i1];
    }

    b_Tt[i] = fg_tmp;
    dv[i] = t9;
  }

  fg[0] = 0.0;
  fg[1] = 0.0;
  fg[2] = -t6 * t16 * (t23 - 1.0) * 3.1415926535897931 * (((((par_mex_var[21] +
    par_mex_var[22]) + par_mex_var[23]) + par_mex_var[24]) + par_mex_var[25]) +
    par_mex_var[26]);
  b_fg_tmp = par_mex_var[23] * par_mex_var[19] * t6 * t16 * (t23 - 1.0) *
    3.1415926535897931;
  t33 = par_mex_var[24] * par_mex_var[19] * t6 * t16 * (t23 - 1.0) *
    3.1415926535897931;
  t8 = par_mex_var[25] * par_mex_var[19] * t6 * t16 * (t23 - 1.0) *
    3.1415926535897931;
  t9 = par_mex_var[26] * par_mex_var[19] * t6 * t16 * (t23 - 1.0) *
    3.1415926535897931;
  fg_tmp = par_mex_var[21] * par_mex_var[19] * t6 * t16;
  step = par_mex_var[22] * par_mex_var[19] * t6 * t16;
  fg[3] = ((((fg_tmp * (t23 - 1.0) * 3.1415926535897931 * -0.93771626297577859 -
              step * (t23 - 1.0) * 3.1415926535897931 * 0.93771626297577859) +
             b_fg_tmp * 0.167999098695029) + t33 * 0.76971716428074954) + t8 *
           0.76971716428074932) + t9 * 0.16799909869502891;
  fg[4] = ((((b_fg_tmp * 0.9857871488499218 + t33 * 0.63838506170774523) - t8 *
             0.63838506170774545) - t9 * 0.9857871488499218) - fg_tmp *
           8.3666002653407556 * (t23 - 1.0) * 3.1415926535897931 *
           0.041522491349480967) + step * 8.3666002653407556 * (t23 - 1.0) *
    3.1415926535897931 * 0.041522491349480967;
  fg[5] = 0.0;
  for (i = 0; i < 18; i++) {
    t9 = 0.0;
    fg_tmp = 0.0;
    step = 0.0;
    t33 = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      i2 = i + 18 * i1;
      t9 += (real_T)w_vd_j_tmp[i2] * fg[i1];
      t33 += Tt[i2] * in[i1];
      t8 = T[i2];
      fg_tmp += t8 * b_kx[i1];
      step += t8 * b_in[i1];
    }

    dv2[i] = (dv1[i] + i_y[i]) + ((dv[i] + b_Tt[i]) + fg_tmp);
    dv[i] = (t9 + t33) + step;
  }

  fg[0] = -par_mex_var[5] * z[18];
  fg[1] = -par_mex_var[6] * z[19];
  fg[2] = -par_mex_var[7] * z[20];
  fg[3] = par_mex_var[8] * z[21] * -2.0;
  fg[4] = par_mex_var[9] * z[22] * -2.0;
  fg[5] = par_mex_var[10] * z[23] * -2.0;
  for (i = 0; i < 18; i++) {
    t9 = 0.0;
    fg_tmp = 0.0;
    step = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      i2 = i + 18 * i1;
      t9 += (real_T)w_vd_j_tmp[i2] * fg[i1];
      step += Tt[i2] * vd[i1];
      fg_tmp += T[i2] * b_vd[i1];
    }

    dv1[i] = (dv2[i] + dv[i]) + ((t9 + step) + fg_tmp);
  }

  memset(&Tt[0], 0, 12U * sizeof(real_T));
  Tt[12] = 1.0;
  Tt[13] = 0.0;
  Tt[14] = 0.0;
  t33 = par_mex_var[16] * z[15];
  Tt[15] = t17 - t33 * z[16] * t27 * 2.0;
  Tt[16] = par_mex_var[16] * t31 - par_mex_var[16] * t15 * t27 * 2.0;
  step = par_mex_var[16] * z[16];
  Tt[17] = par_mex_var[16] * t11 - step * z[17] * t27 * 2.0;
  memset(&Tt[18], 0, 13U * sizeof(real_T));
  Tt[31] = 1.0;
  Tt[32] = 0.0;
  Tt[33] = par_mex_var[16] * t26 * -2.0 + t33 * t11 * t27;
  Tt[34] = t17 + par_mex_var[16] * b_t33;
  Tt[35] = par_mex_var[16] * t12 + par_mex_var[16] * t34;
  memset(&Tt[36], 0, 14U * sizeof(real_T));
  Tt[50] = 1.0;
  Tt[51] = t33 * -4.0;
  Tt[52] = step * -4.0;
  memset(&Tt[53], 0, 16U * sizeof(real_T));
  Tt[69] = t31 + z[15] * t11 * t27;
  Tt[70] = b_t13 + b_t33;
  Tt[71] = -t12 + t34;
  memset(&Tt[72], 0, 15U * sizeof(real_T));
  Tt[87] = -b_t13 + b_t33;
  Tt[88] = t31 + z[16] * t12 * t27;
  Tt[89] = t11 + t35;
  memset(&Tt[90], 0, 15U * sizeof(real_T));
  Tt[105] = t12 + t34;
  Tt[106] = -t11 + t35;
  Tt[107] = t31 + z[17] * b_t13 * t27;
  fg[0] = par_mex_var[27];
  fg[1] = par_mex_var[28];
  fg[2] = par_mex_var[29];
  fg[3] = ((z[15] * t24 - z[16] * t37) + z[17] * t38) + t26 * t39;
  fg[4] = ((z[16] * t24 + z[15] * t37) - z[17] * t39) + t26 * t38;
  fg[5] = ((z[17] * t24 - z[15] * t38) + z[16] * t39) + t26 * t37;
  for (i = 0; i < 18; i++) {
    t9 = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      t9 += Tt[i + 18 * i1] * fg[i1];
    }

    dv1[i] += t9;
  }

  for (i = 0; i < 18; i++) {
    t9 = 0.0;
    for (i1 = 0; i1 < 18; i1++) {
      t9 += b_y[i + 18 * i1] * dv1[i1];
    }

    dz[i] = z[i + 18];
    dz[i + 18] = t9;
  }

  *flag = 0.0;
}

/* End of code generation (EOM.c) */
