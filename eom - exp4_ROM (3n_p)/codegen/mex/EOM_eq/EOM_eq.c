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
#include "mtimes.h"
#include "rt_nonfinite.h"
#include "sprdmpF16.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 9,     /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 24,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 26,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 27,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 29,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 36,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 38,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 39,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 41,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 52,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 54,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 55,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 57,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 67,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 69,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 70,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 73,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo cd_emlrtRSI = { 83, /* lineNo */
  "loadsF1",                           /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\loadsF1.m"/* pathName */
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

/* Function Definitions */
void EOM_eq(const emlrtStack *sp, const real_T z[15], real_T res[15])
{
  static const int8_T iv[6] = { 0, 0, 1, 1, 2, 2 };

  emlrtStack b_st;
  emlrtStack st;
  real_T unusedExpr[225];
  real_T Dd[90];
  real_T T[90];
  real_T Tt[90];
  real_T b_Dd[90];
  real_T b_Tt[90];
  real_T b_y[90];
  real_T y[90];
  real_T M[36];
  real_T b_z[30];
  real_T TMfd[15];
  real_T w_in[15];
  real_T w_sd[15];
  real_T b_fg[6];
  real_T b_in[6];
  real_T b_kx[6];
  real_T fg[6];
  real_T in[6];
  real_T kx[6];
  real_T vd[6];
  real_T b_sn;
  real_T step;
  real_T t11;
  real_T t12;
  real_T t13;
  real_T t14;
  real_T t15;
  real_T t22;
  real_T t23;
  real_T t24;
  real_T t25;
  real_T t26;
  real_T t3;
  real_T t4;
  real_T t40;
  real_T t40_tmp;
  real_T t47;
  real_T t48;
  real_T t49;
  real_T t5;
  real_T t50;
  real_T t50_tmp;
  real_T t51;
  real_T t51_tmp;
  real_T t52;
  real_T t53;
  real_T t54;
  real_T t55;
  real_T t56;
  real_T t6;
  real_T t68;
  real_T t71;
  real_T t71_tmp;
  real_T t72;
  real_T t72_tmp;
  real_T t73;
  real_T t73_tmp;
  real_T t74;
  real_T t75;
  real_T t76;
  int32_T i;
  int32_T i1;
  int32_T sn;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  for (i = 0; i < 15; i++) {
    t4 = z[i];
    b_z[i] = t4;
    b_z[i + 15] = 0.0 * t4;
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
  /*  s0 = 1e-6 ; l = 0 ; */
  /*  ds = par_mex.var(5) / 1e1 ; */
  /*  for s = s0 : ds : par_mex.var(5) - s0 */
  /*      [ ~ , ~ , ~ , ~ , ~ , ~ , dl ] = sprdmpF19( par_mex.var , z , s , 0 , 0 ) ; */
  /*      l = l + dl(3) * ds ; */
  /*  end */
  /*  lambda = l / par_mex.var(5) ; */
  /*  update simulation parameters */
  for (i = 0; i < 6; i++) {
    par_mex.var[i + 21] = par_mex.user_pars.p[((int32_T)step + 1094 * (iv[i] + 1))
      - 1];
    par_mex.var[i + 27] = par_mex.user_pars.f_ex[((int32_T)step + 1094 * (i + 1))
      - 1];
  }

  par_mex.var[33] = 1.0;
  par_mex_dirty |= 1U;

  /* ROMF */
  /*     [OUT1,OUT2] = ROMF(IN1,IN2,S,DS,T_SYM) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
  /*     15-Jun-2021 01:47:56 */
  t14 = par_mex.var[4];
  t15 = par_mex.var[4];
  st.site = &b_emlrtRSI;
  massF1(&st, par_mex.var, b_z, 1.0E-6 * t14, M, T, Dd, fg);
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 15; i1++) {
      Tt[i1 + 15 * i] = T[i + 6 * i1];
    }
  }

  st.site = &c_emlrtRSI;
  mtimes(Tt, M, y);
  st.site = &c_emlrtRSI;
  b_mtimes(y, T, unusedExpr);
  st.site = &d_emlrtRSI;
  mtimes(Tt, M, y);
  st.site = &e_emlrtRSI;
  sprdmpF16(&st, par_mex.var, b_z, 1.0E-6 * t15, b_Tt, kx, vd, in, &step);
  for (i = 0; i < 90; i++) {
    b_Tt[i] *= step;
  }

  st.site = &f_emlrtRSI;
  massF1(&st, par_mex.var, b_z, 0.999999 * t14, M, T, b_Dd, b_fg);
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 15; i1++) {
      Tt[i1 + 15 * i] = T[i + 6 * i1];
    }
  }

  st.site = &g_emlrtRSI;
  mtimes(Tt, M, b_y);
  st.site = &g_emlrtRSI;
  b_mtimes(b_y, T, unusedExpr);
  st.site = &h_emlrtRSI;
  mtimes(Tt, M, b_y);
  st.site = &i_emlrtRSI;
  sprdmpF16(&st, par_mex.var, b_z, 0.999999 * t15, Tt, b_kx, vd, b_in, &step);
  for (i = 0; i < 90; i++) {
    Tt[i] *= step;
    Dd[i] = -Dd[i];
  }

  for (i = 0; i < 6; i++) {
    t4 = 0.0;
    for (i1 = 0; i1 < 15; i1++) {
      t4 += Dd[i + 6 * i1] * b_z[i1 + 15];
    }

    vd[i] = t4 + fg[i];
  }

  for (i = 0; i < 15; i++) {
    t4 = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      t4 += y[i + 15 * i1] * vd[i1];
    }

    TMfd[i] = t4;
  }

  for (i = 0; i < 90; i++) {
    b_Dd[i] = -b_Dd[i];
  }

  for (i = 0; i < 6; i++) {
    t4 = 0.0;
    for (i1 = 0; i1 < 15; i1++) {
      t4 += b_Dd[i + 6 * i1] * b_z[i1 + 15];
    }

    vd[i] = t4 + b_fg[i];
  }

  for (i = 0; i < 15; i++) {
    t4 = 0.0;
    step = 0.0;
    b_sn = 0.0;
    t11 = 0.0;
    t3 = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      sn = i + 15 * i1;
      t4 += b_y[sn] * vd[i1];
      t12 = b_Tt[sn];
      step += t12 * kx[i1];
      t13 = Tt[sn];
      b_sn += t13 * b_kx[i1];
      t11 += t12 * in[i1];
      t3 += t13 * b_in[i1];
    }

    TMfd[i] = (TMfd[i] * t14 + t4 * t14) / 2.0;
    w_sd[i] = (step * par_mex.var[4] + b_sn * par_mex.var[4]) / 2.0;
    w_in[i] = (t11 * par_mex.var[4] + t3 * par_mex.var[4]) / 2.0;
  }

  for (sn = 0; sn < 9; sn++) {
    b_sn = (real_T)sn * 0.1 + 0.100001;
    st.site = &j_emlrtRSI;
    massF1(&st, par_mex.var, b_z, b_sn * t14, M, T, Dd, fg);
    for (i = 0; i < 6; i++) {
      for (i1 = 0; i1 < 15; i1++) {
        Tt[i1 + 15 * i] = T[i + 6 * i1];
      }
    }

    st.site = &k_emlrtRSI;
    mtimes(Tt, M, y);
    st.site = &k_emlrtRSI;
    b_mtimes(y, T, unusedExpr);
    st.site = &l_emlrtRSI;
    mtimes(Tt, M, y);
    for (i = 0; i < 90; i++) {
      Dd[i] = -Dd[i];
    }

    for (i = 0; i < 6; i++) {
      t4 = 0.0;
      for (i1 = 0; i1 < 15; i1++) {
        t4 += Dd[i + 6 * i1] * b_z[i1 + 15];
      }

      vd[i] = t4 + fg[i];
    }

    for (i = 0; i < 15; i++) {
      t4 = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        t4 += y[i + 15 * i1] * vd[i1];
      }

      TMfd[i] += t4 * t14;
    }

    st.site = &m_emlrtRSI;
    sprdmpF16(&st, par_mex.var, b_z, b_sn * t15, Tt, kx, vd, in, &step);
    for (i = 0; i < 90; i++) {
      Tt[i] *= step;
    }

    for (i = 0; i < 15; i++) {
      t4 = 0.0;
      step = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        b_sn = Tt[i + 15 * i1];
        t4 += b_sn * kx[i1];
        step += b_sn * in[i1];
      }

      w_sd[i] += t4 * par_mex.var[4];
      w_in[i] += step * par_mex.var[4];
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  for (i = 0; i < 15; i++) {
    TMfd[i] /= 10.0;
    w_sd[i] /= 10.0;
    w_in[i] /= 10.0;
  }

  st.site = &n_emlrtRSI;
  massF2(&st, par_mex.var, b_z, M, T, Dd, fg);
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 15; i1++) {
      Tt[i1 + 15 * i] = T[i + 6 * i1];
    }
  }

  st.site = &o_emlrtRSI;
  mtimes(Tt, M, y);
  st.site = &o_emlrtRSI;
  b_mtimes(y, T, unusedExpr);
  st.site = &p_emlrtRSI;
  mtimes(Tt, M, y);
  for (i = 0; i < 90; i++) {
    Dd[i] = -Dd[i];
  }

  for (i = 0; i < 6; i++) {
    t4 = 0.0;
    for (i1 = 0; i1 < 15; i1++) {
      t4 += Dd[i + 6 * i1] * b_z[i1 + 15];
    }

    vd[i] = t4 + fg[i];
  }

  for (i = 0; i < 15; i++) {
    t4 = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      t4 += y[i + 15 * i1] * vd[i1];
    }

    TMfd[i] += t4;
  }

  st.site = &q_emlrtRSI;

  /* LOADSF1 */
  /*     [OUT1,OUT2,OUT3] = LOADSF1(IN1,IN2,S,DS,T_SYM) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
  /*     15-Jun-2021 01:48:23 */
  step = par_mex.var[4] * b_z[6];
  t3 = par_mex.var[4] * b_z[9];
  t4 = par_mex.var[4] * b_z[12];
  t5 = par_mex.var[4] * par_mex.var[4];
  t6 = muDoubleScalarPower(par_mex.var[4], 3.0);
  b_sn = b_z[7] * t5;
  t11 = b_z[8] * t6;
  t12 = b_z[10] * t5;
  t13 = b_z[11] * t6;
  t14 = b_z[13] * t5;
  t15 = b_z[14] * t6;
  t22 = (step + b_sn) + t11;
  t23 = (t3 + t12) + t13;
  t24 = (t4 + t14) + t15;
  t25 = t22 * t22;
  t26 = t23 * t23;
  t11 = (step * 2.0 + b_sn * 2.0) + t11 * 2.0;
  b_sn = (t3 * 2.0 + t12 * 2.0) + t13 * 2.0;
  step = (t4 * 2.0 + t14 * 2.0) + t15 * 2.0;
  t40_tmp = par_mex.var[16] * par_mex.var[4];
  t40 = t40_tmp * t24 * 2.0;
  t50_tmp = par_mex.var[16] * t5;
  t50 = t50_tmp * t24 * 2.0;
  t51_tmp = par_mex.var[16] * t6;
  t51 = t51_tmp * t24 * 2.0;
  t47 = par_mex.var[4] * t11;
  t48 = par_mex.var[4] * b_sn;
  t49 = par_mex.var[4] * step;
  t52 = t5 * t11;
  t53 = t6 * t11;
  t54 = t5 * b_sn;
  t55 = t6 * b_sn;
  t56 = t5 * step;
  t3 = t6 * step;
  t12 = (t22 * par_mex.var[30] + t23 * par_mex.var[31]) + t24 * par_mex.var[32];
  t13 = ((-t25 + -t26) + -(t24 * t24)) + 1.0;
  b_st.site = &cd_emlrtRSI;
  if (t13 < 0.0) {
    emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  t13 = muDoubleScalarSqrt(t13);
  t4 = 1.0 / t13;
  t14 = par_mex.var[4] * t13 * 2.0;
  t15 = t5 * t13 * 2.0;
  t68 = t6 * t13 * 2.0;
  t71_tmp = t40_tmp * t22;
  t71 = t71_tmp * t23 * t4 * 2.0;
  t72_tmp = t50_tmp * t22;
  t72 = t72_tmp * t23 * t4 * 2.0;
  t73_tmp = t51_tmp * t22;
  t73 = t73_tmp * t23 * t4 * 2.0;
  t74 = (t23 * par_mex.var[30] + -(t22 * par_mex.var[31])) + t13 * par_mex.var
    [32];
  t75 = (t22 * par_mex.var[32] + -(t24 * par_mex.var[30])) + t13 * par_mex.var
    [31];
  t76 = (t24 * par_mex.var[31] + -(t23 * par_mex.var[32])) + t13 * par_mex.var
    [30];

  /*  EOM */
  Tt[0] = t5;
  Tt[1] = t6;
  Tt[2] = 0.0;
  Tt[3] = 0.0;
  Tt[4] = 0.0;
  Tt[5] = 0.0;
  Tt[6] = t40 - t71;
  Tt[7] = t50 - t72;
  Tt[8] = t51 - t73;
  Tt[9] = par_mex.var[16] * t14 - t40_tmp * t26 * t4 * 2.0;
  Tt[10] = par_mex.var[16] * t15 - t50_tmp * t26 * t4 * 2.0;
  Tt[11] = par_mex.var[16] * t68 - t51_tmp * t26 * t4 * 2.0;
  step = t40_tmp * t23;
  Tt[12] = t71_tmp * 2.0 - step * t24 * t4 * 2.0;
  b_sn = t50_tmp * t23;
  Tt[13] = t72_tmp * 2.0 - b_sn * t24 * t4 * 2.0;
  t11 = t51_tmp * t23;
  Tt[14] = t73_tmp * 2.0 - t11 * t24 * t4 * 2.0;
  Tt[15] = 0.0;
  Tt[16] = 0.0;
  Tt[17] = t5;
  Tt[18] = t6;
  Tt[19] = 0.0;
  Tt[20] = 0.0;
  Tt[21] = t40_tmp * t13 * -2.0 + t40_tmp * t25 * t4 * 2.0;
  Tt[22] = t50_tmp * t13 * -2.0 + t50_tmp * t25 * t4 * 2.0;
  Tt[23] = t51_tmp * t13 * -2.0 + t51_tmp * t25 * t4 * 2.0;
  Tt[24] = t40 + t71;
  Tt[25] = t50 + t72;
  Tt[26] = t51 + t73;
  Tt[27] = step * 2.0 + t22 * t40 * t4;
  Tt[28] = b_sn * 2.0 + t22 * t50 * t4;
  Tt[29] = t11 * 2.0 + t22 * t51 * t4;
  Tt[30] = 0.0;
  Tt[31] = 0.0;
  Tt[32] = 0.0;
  Tt[33] = 0.0;
  Tt[34] = t5;
  Tt[35] = t6;
  Tt[36] = t71_tmp * -4.0;
  Tt[37] = t72_tmp * -4.0;
  Tt[38] = t73_tmp * -4.0;
  Tt[39] = step * -4.0;
  Tt[40] = b_sn * -4.0;
  Tt[41] = t11 * -4.0;
  memset(&Tt[42], 0, 9U * sizeof(real_T));
  Tt[51] = t14 + t22 * t47 * t4;
  Tt[52] = t15 + t22 * t52 * t4;
  Tt[53] = t68 + t22 * t53 * t4;
  Tt[54] = t49 + t23 * t47 * t4;
  Tt[55] = t56 + t23 * t52 * t4;
  Tt[56] = t3 + t23 * t53 * t4;
  Tt[57] = -t48 + t24 * t47 * t4;
  Tt[58] = -t54 + t24 * t52 * t4;
  Tt[59] = -t55 + t24 * t53 * t4;
  Tt[60] = 0.0;
  Tt[61] = 0.0;
  Tt[62] = 0.0;
  Tt[63] = 0.0;
  Tt[64] = 0.0;
  Tt[65] = 0.0;
  Tt[66] = -t49 + t22 * t48 * t4;
  Tt[67] = -t56 + t22 * t54 * t4;
  Tt[68] = -t3 + t22 * t55 * t4;
  Tt[69] = t14 + t23 * t48 * t4;
  Tt[70] = t15 + t23 * t54 * t4;
  Tt[71] = t68 + t23 * t55 * t4;
  Tt[72] = t47 + t24 * t48 * t4;
  Tt[73] = t52 + t24 * t54 * t4;
  Tt[74] = t53 + t24 * t55 * t4;
  Tt[75] = 0.0;
  Tt[76] = 0.0;
  Tt[77] = 0.0;
  Tt[78] = 0.0;
  Tt[79] = 0.0;
  Tt[80] = 0.0;
  Tt[81] = t48 + t22 * t49 * t4;
  Tt[82] = t54 + t22 * t56 * t4;
  Tt[83] = t55 + t22 * t3 * t4;
  Tt[84] = -t47 + t23 * t49 * t4;
  Tt[85] = -t52 + t23 * t56 * t4;
  Tt[86] = -t53 + t23 * t3 * t4;
  Tt[87] = t14 + t24 * t49 * t4;
  Tt[88] = t15 + t24 * t56 * t4;
  Tt[89] = t68 + t24 * t3 * t4;
  vd[0] = par_mex.var[27];
  vd[1] = par_mex.var[28];
  vd[2] = par_mex.var[29];
  vd[3] = ((t22 * t12 - t23 * t74) + t24 * t75) + t13 * t76;
  vd[4] = ((t23 * t12 + t22 * t74) - t24 * t76) + t13 * t75;
  vd[5] = ((t24 * t12 - t22 * t75) + t23 * t76) + t13 * t74;
  for (i = 0; i < 15; i++) {
    t4 = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      t4 += Tt[i + 15 * i1] * vd[i1];
    }

    res[i] = ((TMfd[i] + w_sd[i]) + w_in[i]) + t4;
  }
}

/* End of code generation (EOM_eq.c) */
