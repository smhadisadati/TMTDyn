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
#include "massF5.h"
#include "mtimes.h"
#include "pinv.h"
#include "rt_nonfinite.h"
#include "sprdmpF25.h"
#include "sprdmpF26.h"
#include "sprdmpF27.h"
#include "sprdmpF28.h"
#include "blas.h"
#include "mwmathutil.h"
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 6,     /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 19,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 21,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 22,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 24,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 26,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 27,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 29,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 31,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 32,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 34,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 36,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 37,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 39,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 41,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 42,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 44,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 49,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 54,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 59,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 65,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 75,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo ig_emlrtRSI = { 42, /* lineNo */
  "loadsF1",                           /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\loadsF1.m"/* pathName */
};

static emlrtBCInfo emlrtBCI = { 1,     /* iFirst */
  1094,                                /* iLast */
  10,                                  /* lineNo */
  34,                                  /* colNo */
  "par_mex.user_pars.f_ex",            /* aName */
  "dyn_mid_step",                      /* fName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\dyn_mid_step.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo emlrtDCI = { 10,    /* lineNo */
  34,                                  /* colNo */
  "dyn_mid_step",                      /* fName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\dyn_mid_step.m",/* pName */
  1                                    /* checkKind */
};

/* Function Definitions */
void EOM(const emlrtStack *sp, real_T t, const real_T z[48], const struct0_T
         *par_mex, real_T dz[48], real_T *flag)
{
  static const int8_T w_vd_j_tmp[144] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0 };

  static const int8_T iv[6] = { 0, 0, 1, 1, 2, 2 };

  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack st;
  real_T b_y[576];
  real_T d_y[576];
  real_T f_y[576];
  real_T h_y[576];
  real_T j_y[576];
  real_T Dd[144];
  real_T T[144];
  real_T Tt[144];
  real_T b_Dd[144];
  real_T b_Tt[144];
  real_T c_Dd[144];
  real_T c_y[144];
  real_T d_Dd[144];
  real_T e_Dd[144];
  real_T e_y[144];
  real_T g_y[144];
  real_T i_y[144];
  real_T y[144];
  real_T M[36];
  real_T par_mex_var[34];
  real_T ddY[24];
  real_T dv[24];
  real_T k_y[24];
  real_T reshapes_f1[24];
  real_T b_fg[6];
  real_T b_in[6];
  real_T b_kx[6];
  real_T b_vd[6];
  real_T c_fg[6];
  real_T c_in[6];
  real_T c_kx[6];
  real_T c_vd[6];
  real_T d_fg[6];
  real_T d_in[6];
  real_T d_kx[6];
  real_T d_vd[6];
  real_T e_fg[6];
  real_T f_Dd[6];
  real_T fg[6];
  real_T in[6];
  real_T kx[6];
  real_T vd[6];
  real_T d;
  real_T d1;
  real_T d10;
  real_T d11;
  real_T d2;
  real_T d3;
  real_T d4;
  real_T d5;
  real_T d6;
  real_T d7;
  real_T d8;
  real_T d9;
  real_T step;
  real_T t11;
  real_T t12;
  real_T t13;
  real_T t15;
  real_T t17;
  real_T t26;
  real_T t27;
  real_T t31;
  real_T t33;
  real_T t34;
  real_T t35;
  real_T t37;
  real_T t38;
  real_T t39;
  int32_T b_i;
  int32_T i;
  int32_T i1;
  char_T TRANSA1;
  char_T TRANSB1;
  int8_T i2;
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
    for (i1 = 0; i1 < 24; i1++) {
      Tt[i1 + 24 * i] = T[i + 6 * i1];
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
    for (i1 = 0; i1 < 24; i1++) {
      Tt[i1 + 24 * i] = T[i + 6 * i1];
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
    for (i1 = 0; i1 < 24; i1++) {
      Tt[i1 + 24 * i] = T[i + 6 * i1];
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
    for (i1 = 0; i1 < 24; i1++) {
      Tt[i1 + 24 * i] = T[i + 6 * i1];
    }
  }

  st.site = &l_emlrtRSI;
  mtimes(Tt, M, g_y);
  st.site = &l_emlrtRSI;
  b_mtimes(g_y, T, h_y);
  st.site = &m_emlrtRSI;
  mtimes(Tt, M, g_y);
  st.site = &n_emlrtRSI;
  massF5(&st, par_mex_var, z, M, T, e_Dd, e_fg);
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 24; i1++) {
      Tt[i1 + 24 * i] = T[i + 6 * i1];
    }
  }

  st.site = &o_emlrtRSI;
  mtimes(Tt, M, i_y);
  st.site = &o_emlrtRSI;
  b_mtimes(i_y, T, j_y);
  st.site = &p_emlrtRSI;
  mtimes(Tt, M, i_y);
  st.site = &q_emlrtRSI;
  sprdmpF25(&st, par_mex_var, z, kx, vd, in, &step);
  st.site = &r_emlrtRSI;
  sprdmpF26(&st, par_mex_var, z, Tt, b_kx, b_vd, b_in, &step);
  st.site = &s_emlrtRSI;
  sprdmpF27(&st, par_mex_var, z, T, c_kx, c_vd, c_in, &step);
  st.site = &t_emlrtRSI;
  sprdmpF28(&st, par_mex_var, z, b_Tt, d_kx, d_vd, d_in, &step);
  st.site = &u_emlrtRSI;

  /* LOADSF1 */
  /*     [OUT1,OUT2,OUT3] = LOADSF1(IN1,IN2,S,DS,T_SYM) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
  /*     26-Feb-2021 21:07:24 */
  t11 = z[21] * 2.0;
  t12 = z[22] * 2.0;
  t13 = z[23] * 2.0;
  t15 = z[22] * z[22];
  t17 = par_mex_var[16] * t13;
  step = (z[21] * par_mex_var[30] + z[22] * par_mex_var[31]) + z[23] *
    par_mex_var[32];
  t26 = ((-(z[21] * z[21]) + -t15) + -(z[23] * z[23])) + 1.0;
  b_st.site = &ig_emlrtRSI;
  if (t26 < 0.0) {
    emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  t26 = muDoubleScalarSqrt(t26);
  t27 = 1.0 / t26;
  t31 = t26 * 2.0;
  t33 = z[22] * t11 * t27;
  t34 = z[23] * t11 * t27;
  t35 = z[23] * t12 * t27;
  t37 = (z[22] * par_mex_var[30] + -(z[21] * par_mex_var[31])) + t26 *
    par_mex_var[32];
  t38 = (z[21] * par_mex_var[32] + -(z[23] * par_mex_var[30])) + t26 *
    par_mex_var[31];
  t39 = (z[23] * par_mex_var[31] + -(z[22] * par_mex_var[32])) + t26 *
    par_mex_var[30];

  /*  EOM */
  for (i = 0; i < 144; i++) {
    Dd[i] = -Dd[i];
  }

  for (i = 0; i < 6; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 24; i1++) {
      d += Dd[i + 6 * i1] * z[i1 + 24];
    }

    f_Dd[i] = d + fg[i];
  }

  for (i = 0; i < 144; i++) {
    b_Dd[i] = -b_Dd[i];
  }

  for (i = 0; i < 6; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 24; i1++) {
      d += b_Dd[i + 6 * i1] * z[i1 + 24];
    }

    fg[i] = d + b_fg[i];
  }

  for (i = 0; i < 24; i++) {
    d = 0.0;
    d1 = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      b_i = i + 24 * i1;
      d += y[b_i] * f_Dd[i1];
      d1 += c_y[b_i] * fg[i1];
    }

    k_y[i] = d1;
    ddY[i] = d;
  }

  for (i = 0; i < 144; i++) {
    c_Dd[i] = -c_Dd[i];
  }

  for (i = 0; i < 6; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 24; i1++) {
      d += c_Dd[i + 6 * i1] * z[i1 + 24];
    }

    f_Dd[i] = d + c_fg[i];
  }

  for (i = 0; i < 144; i++) {
    d_Dd[i] = -d_Dd[i];
  }

  for (i = 0; i < 6; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 24; i1++) {
      d += d_Dd[i + 6 * i1] * z[i1 + 24];
    }

    fg[i] = d + d_fg[i];
  }

  for (i = 0; i < 24; i++) {
    d = 0.0;
    d1 = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      b_i = i + 24 * i1;
      d += e_y[b_i] * f_Dd[i1];
      d1 += g_y[b_i] * fg[i1];
    }

    dv[i] = (ddY[i] + k_y[i]) + d;
    k_y[i] = d1;
  }

  for (i = 0; i < 144; i++) {
    e_Dd[i] = -e_Dd[i];
  }

  for (i = 0; i < 6; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 24; i1++) {
      d += e_Dd[i + 6 * i1] * z[i1 + 24];
    }

    f_Dd[i] = d + e_fg[i];
  }

  fg[0] = par_mex_var[27];
  fg[1] = par_mex_var[28];
  fg[2] = par_mex_var[29];
  fg[3] = ((z[21] * step - z[22] * t37) + z[23] * t38) + t26 * t39;
  fg[4] = ((z[22] * step + z[21] * t37) - z[23] * t39) + t26 * t38;
  fg[5] = ((z[23] * step - z[21] * t38) + z[22] * t39) + t26 * t37;
  for (i = 0; i < 24; i++) {
    d = 0.0;
    d1 = 0.0;
    step = 0.0;
    t37 = 0.0;
    t38 = 0.0;
    t39 = 0.0;
    d2 = 0.0;
    d3 = 0.0;
    d4 = 0.0;
    d5 = 0.0;
    d6 = 0.0;
    d7 = 0.0;
    d8 = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      b_i = i + 24 * i1;
      i2 = w_vd_j_tmp[b_i];
      d += (real_T)i2 * kx[i1];
      d9 = Tt[b_i];
      step += d9 * b_kx[i1];
      d10 = T[b_i];
      d1 += d10 * c_kx[i1];
      d11 = b_Tt[b_i];
      t39 += d11 * d_kx[i1];
      t37 += (real_T)i2 * in[i1];
      d2 += d9 * b_in[i1];
      t38 += d10 * c_in[i1];
      d5 += d11 * d_in[i1];
      d3 += (real_T)i2 * vd[i1];
      d6 += d9 * b_vd[i1];
      d4 += d10 * c_vd[i1];
      d8 += d11 * d_vd[i1];
      d7 += i_y[b_i] * f_Dd[i1];
    }

    reshapes_f1[i] = ((((dv[i] + k_y[i]) + d7) + (((d + step) + d1) + t39)) +
                      (((t37 + d2) + t38) + d5)) + (((d3 + d6) + d4) + d8);
  }

  memset(&Tt[0], 0, 18U * sizeof(real_T));
  Tt[18] = 1.0;
  Tt[19] = 0.0;
  Tt[20] = 0.0;
  t37 = par_mex_var[16] * z[21];
  Tt[21] = t17 - t37 * z[22] * t27 * 2.0;
  Tt[22] = par_mex_var[16] * t31 - par_mex_var[16] * t15 * t27 * 2.0;
  step = par_mex_var[16] * z[22];
  Tt[23] = par_mex_var[16] * t11 - step * z[23] * t27 * 2.0;
  memset(&Tt[24], 0, 19U * sizeof(real_T));
  Tt[43] = 1.0;
  Tt[44] = 0.0;
  Tt[45] = par_mex_var[16] * t26 * -2.0 + t37 * t11 * t27;
  Tt[46] = t17 + par_mex_var[16] * t33;
  Tt[47] = par_mex_var[16] * t12 + par_mex_var[16] * t34;
  memset(&Tt[48], 0, 20U * sizeof(real_T));
  Tt[68] = 1.0;
  Tt[69] = t37 * -4.0;
  Tt[70] = step * -4.0;
  memset(&Tt[71], 0, 22U * sizeof(real_T));
  Tt[93] = t31 + z[21] * t11 * t27;
  Tt[94] = t13 + t33;
  Tt[95] = -t12 + t34;
  memset(&Tt[96], 0, 21U * sizeof(real_T));
  Tt[117] = -t13 + t33;
  Tt[118] = t31 + z[22] * t12 * t27;
  Tt[119] = t11 + t35;
  memset(&Tt[120], 0, 21U * sizeof(real_T));
  Tt[141] = t12 + t34;
  Tt[142] = -t11 + t35;
  Tt[143] = t31 + z[23] * t13 * t27;
  for (i = 0; i < 24; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      d += Tt[i + 24 * i1] * fg[i1];
    }

    reshapes_f1[i] += d;
  }

  st.site = &v_emlrtRSI;
  for (i = 0; i < 576; i++) {
    d_y[i] = (((b_y[i] + d_y[i]) + f_y[i]) + h_y[i]) + j_y[i];
  }

  b_st.site = &v_emlrtRSI;
  pinv(&b_st, d_y, b_y);
  TRANSB1 = 'N';
  TRANSA1 = 'N';
  step = 1.0;
  t37 = 0.0;
  m_t = (ptrdiff_t)24;
  n_t = (ptrdiff_t)1;
  k_t = (ptrdiff_t)24;
  lda_t = (ptrdiff_t)24;
  ldb_t = (ptrdiff_t)24;
  ldc_t = (ptrdiff_t)24;
  dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &step, &b_y[0], &lda_t,
        &reshapes_f1[0], &ldb_t, &t37, &ddY[0], &ldc_t);
  for (b_i = 0; b_i < 24; b_i++) {
    dz[b_i] = z[b_i + 24];
    dz[b_i + 24] = ddY[b_i];
  }

  *flag = 0.0;
}

/* End of code generation (EOM.c) */
