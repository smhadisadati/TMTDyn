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
#include "EOM_types.h"
#include "fj_kF.h"
#include "loadsF1.h"
#include "massF1.h"
#include "massF2.h"
#include "massF3.h"
#include "mtimes.h"
#include "pinv.h"
#include "power.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 6,     /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 8,   /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 9,   /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 10,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 19,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 21,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 24,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 26,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 29,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 31,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 35,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 45,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 70,  /* lineNo */
  "power",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 28, /* lineNo */
  "fj_vdF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\fj_vdF.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 20, /* lineNo */
  "fj_inF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\fj_inF.m"/* pathName */
};

static emlrtRSInfo cb_emlrtRSI = { 21, /* lineNo */
  "fj_inF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\fj_inF.m"/* pathName */
};

static emlrtRSInfo db_emlrtRSI = { 22, /* lineNo */
  "fj_inF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\fj_inF.m"/* pathName */
};

static emlrtRSInfo eb_emlrtRSI = { 23, /* lineNo */
  "fj_inF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\fj_inF.m"/* pathName */
};

static emlrtRSInfo fb_emlrtRSI = { 25, /* lineNo */
  "fj_inF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\fj_inF.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 26, /* lineNo */
  "fj_inF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\fj_inF.m"/* pathName */
};

static emlrtRSInfo rb_emlrtRSI = { 79, /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 82,  /* lineNo */
  5,                                   /* colNo */
  "fltpower",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pName */
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
void EOM(const emlrtStack *sp, real_T t, const real_T z[24], const struct0_T
         *par_mex, real_T dz[24], real_T *flag)
{
  static const int8_T iv[6] = { 0, 0, 1, 1, 2, 2 };

  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T b_y[144];
  real_T c_y[144];
  real_T y[144];
  real_T Dd[72];
  real_T T[72];
  real_T b_Dd[72];
  real_T b_y_tmp[72];
  real_T c_Dd[72];
  real_T c_y_tmp[72];
  real_T y_tmp[72];
  real_T M[36];
  real_T par_mex_var[34];
  real_T d_y_tmp[12];
  real_T dv[12];
  real_T dv1[12];
  real_T fj_k[12];
  real_T b_fg[6];
  real_T c_fg[6];
  real_T d_Dd[6];
  real_T fg[6];
  real_T ftau_ex[6];
  real_T a;
  real_T b_a;
  real_T b_t32_tmp;
  real_T c_a;
  real_T c_t32_tmp;
  real_T d_a;
  real_T d_t32_tmp;
  real_T e_a;
  real_T e_t32_tmp;
  real_T f_a;
  real_T g_a;
  real_T h_a;
  real_T i_a;
  real_T j_a;
  real_T k_a;
  real_T l_a;
  real_T m_a;
  real_T step;
  real_T t13;
  real_T t32;
  real_T t32_tmp;
  real_T t5;
  int32_T i;
  int32_T i1;
  int32_T i2;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
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
  /*  axial stretch */
  /*  l = 0 ; */
  /*  for i = 0 : par_mex.user_pars.n_l - 2 */
  /*      l = l + z(i*6+3) ; */
  /*  end */
  /*  lambda = 1 + l / par_mex.var(5) ; */
  /*  update simulation parameters */
  for (i = 0; i < 6; i++) {
    par_mex_var[i + 21] = par_mex->user_pars.p[((int32_T)step + 1094 * (iv[i] +
      1)) - 1];
    par_mex_var[i + 27] = par_mex->user_pars.f_ex[((int32_T)step + 1094 * (i + 1))
      - 1];
  }

  par_mex_var[33] = 1.0;
  st.site = &b_emlrtRSI;
  fj_kF(par_mex_var, z, fj_k);
  st.site = &c_emlrtRSI;

  /* FJ_VDF */
  /*     OUT1 = FJ_VDF(IN1,IN2,S,DS,T_SYM) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
  /*     26-Feb-2021 18:56:22 */
  b_st.site = &ab_emlrtRSI;
  a = muDoubleScalarAbs(z[12]);
  c_st.site = &y_emlrtRSI;
  if (fltpower_domain_error(a, par_mex_var[11] - 1.0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }

  b_st.site = &ab_emlrtRSI;
  b_a = muDoubleScalarAbs(z[13]);
  c_st.site = &y_emlrtRSI;
  if (fltpower_domain_error(b_a, par_mex_var[11] - 1.0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }

  b_st.site = &ab_emlrtRSI;
  c_a = muDoubleScalarAbs(z[14]);
  c_st.site = &y_emlrtRSI;
  if (fltpower_domain_error(c_a, par_mex_var[11] - 1.0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }

  b_st.site = &ab_emlrtRSI;
  d_a = muDoubleScalarAbs(z[15]);
  c_st.site = &y_emlrtRSI;
  if (fltpower_domain_error(d_a, par_mex_var[11] - 1.0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }

  b_st.site = &ab_emlrtRSI;
  e_a = muDoubleScalarAbs(z[16]);
  c_st.site = &y_emlrtRSI;
  if (fltpower_domain_error(e_a, par_mex_var[11] - 1.0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }

  b_st.site = &ab_emlrtRSI;
  f_a = muDoubleScalarAbs(z[17]);
  c_st.site = &y_emlrtRSI;
  if (fltpower_domain_error(f_a, par_mex_var[11] - 1.0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }

  b_st.site = &ab_emlrtRSI;
  g_a = muDoubleScalarAbs(z[18]);
  c_st.site = &y_emlrtRSI;
  if (fltpower_domain_error(g_a, par_mex_var[11] - 1.0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }

  b_st.site = &ab_emlrtRSI;
  h_a = muDoubleScalarAbs(z[19]);
  c_st.site = &y_emlrtRSI;
  if (fltpower_domain_error(h_a, par_mex_var[11] - 1.0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }

  b_st.site = &ab_emlrtRSI;
  i_a = muDoubleScalarAbs(z[20]);
  c_st.site = &y_emlrtRSI;
  if (fltpower_domain_error(i_a, par_mex_var[11] - 1.0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }

  b_st.site = &ab_emlrtRSI;
  j_a = muDoubleScalarAbs(z[21]);
  c_st.site = &y_emlrtRSI;
  if (fltpower_domain_error(j_a, par_mex_var[11] - 1.0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }

  b_st.site = &ab_emlrtRSI;
  k_a = muDoubleScalarAbs(z[22]);
  c_st.site = &y_emlrtRSI;
  if (fltpower_domain_error(k_a, par_mex_var[11] - 1.0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }

  b_st.site = &ab_emlrtRSI;
  l_a = muDoubleScalarAbs(z[23]);
  c_st.site = &y_emlrtRSI;
  if (fltpower_domain_error(l_a, par_mex_var[11] - 1.0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }

  st.site = &d_emlrtRSI;

  /* FJ_INF */
  /*     OUT1 = FJ_INF(IN1,IN2,S,DS,T_SYM) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
  /*     26-Feb-2021 18:56:22 */
  m_a = muDoubleScalarCos(par_mex_var[20]);
  step = muDoubleScalarSin(par_mex_var[20]);
  b_st.site = &bb_emlrtRSI;
  b_st.site = &cb_emlrtRSI;
  t5 = par_mex_var[18] * par_mex_var[18];
  b_st.site = &db_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  b_st.site = &fb_emlrtRSI;
  b_st.site = &gb_emlrtRSI;
  step = 1.0 / (step * step);
  m_a *= m_a;
  t13 = t5 * step * (((((par_mex_var[21] + par_mex_var[22]) + par_mex_var[23]) +
                       par_mex_var[24]) + par_mex_var[25]) + par_mex_var[26]) *
    (m_a - 1.0) * 3.1415926535897931;
  t32_tmp = par_mex_var[22] * par_mex_var[19] * t5 * step;
  b_t32_tmp = par_mex_var[21] * par_mex_var[19] * t5 * step;
  c_t32_tmp = par_mex_var[23] * par_mex_var[19] * t5 * step * (m_a - 1.0) *
    3.1415926535897931;
  d_t32_tmp = par_mex_var[24] * par_mex_var[19] * t5 * step * (m_a - 1.0) *
    3.1415926535897931;
  e_t32_tmp = par_mex_var[26] * par_mex_var[19] * t5 * step * (m_a - 1.0) *
    3.1415926535897931;
  step = par_mex_var[25] * par_mex_var[19] * t5 * step * (m_a - 1.0) *
    3.1415926535897931;
  t32 = ((((-(b_t32_tmp * (m_a - 1.0) * 3.1415926535897931 * 0.93771626297577859)
            + -(t32_tmp * (m_a - 1.0) * 3.1415926535897931 * 0.93771626297577859))
           + step * 0.76971716428074932) + d_t32_tmp * 0.76971716428074954) +
         e_t32_tmp * 0.16799909869502891) + c_t32_tmp * 0.167999098695029;
  step = ((((t32_tmp * 8.3666002653407556 * (m_a - 1.0) * 3.1415926535897931 *
             0.041522491349480967 + -(b_t32_tmp * 8.3666002653407556 * (m_a -
    1.0) * 3.1415926535897931 * 0.041522491349480967)) + c_t32_tmp *
            0.9857871488499218) + d_t32_tmp * 0.63838506170774523) + -(e_t32_tmp
           * 0.9857871488499218)) + -(step * 0.63838506170774545);
  st.site = &e_emlrtRSI;
  massF1(par_mex_var, z, M, T, Dd, fg);
  for (i = 0; i < 12; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      m_a = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        m_a += T[i2 + 6 * i] * M[i2 + 6 * i1];
      }

      y_tmp[i + 12 * i1] = m_a;
    }
  }

  st.site = &f_emlrtRSI;
  b_st.site = &rb_emlrtRSI;
  mtimes(y_tmp, T, y);
  st.site = &g_emlrtRSI;
  massF2(par_mex_var, z, M, T, b_Dd, b_fg);
  for (i = 0; i < 12; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      m_a = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        m_a += T[i2 + 6 * i] * M[i2 + 6 * i1];
      }

      b_y_tmp[i + 12 * i1] = m_a;
    }
  }

  st.site = &h_emlrtRSI;
  b_st.site = &rb_emlrtRSI;
  mtimes(b_y_tmp, T, b_y);
  st.site = &i_emlrtRSI;
  massF3(par_mex_var, z, M, T, c_Dd, c_fg);
  for (i = 0; i < 12; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      m_a = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        m_a += T[i2 + 6 * i] * M[i2 + 6 * i1];
      }

      c_y_tmp[i + 12 * i1] = m_a;
    }
  }

  st.site = &j_emlrtRSI;
  b_st.site = &rb_emlrtRSI;
  mtimes(c_y_tmp, T, c_y);
  st.site = &k_emlrtRSI;
  loadsF1(par_mex_var, z, T, ftau_ex);

  /*  EOM */
  for (i = 0; i < 144; i++) {
    b_y[i] = (y[i] + b_y[i]) + c_y[i];
  }

  st.site = &l_emlrtRSI;
  pinv(&st, b_y, y);
  for (i = 0; i < 72; i++) {
    Dd[i] = -Dd[i];
  }

  for (i = 0; i < 6; i++) {
    m_a = 0.0;
    for (i1 = 0; i1 < 12; i1++) {
      m_a += Dd[i + 6 * i1] * z[i1 + 12];
    }

    d_Dd[i] = m_a + fg[i];
  }

  for (i = 0; i < 72; i++) {
    b_Dd[i] = -b_Dd[i];
  }

  for (i = 0; i < 6; i++) {
    m_a = 0.0;
    for (i1 = 0; i1 < 12; i1++) {
      m_a += b_Dd[i + 6 * i1] * z[i1 + 12];
    }

    fg[i] = m_a + b_fg[i];
  }

  for (i = 0; i < 12; i++) {
    m_a = 0.0;
    t5 = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      i2 = i + 12 * i1;
      m_a += y_tmp[i2] * d_Dd[i1];
      t5 += b_y_tmp[i2] * fg[i1];
    }

    d_y_tmp[i] = t5;
    dv[i] = m_a;
  }

  for (i = 0; i < 72; i++) {
    c_Dd[i] = -c_Dd[i];
  }

  for (i = 0; i < 6; i++) {
    m_a = 0.0;
    for (i1 = 0; i1 < 12; i1++) {
      m_a += c_Dd[i + 6 * i1] * z[i1 + 12];
    }

    d_Dd[i] = m_a + c_fg[i];
  }

  for (i = 0; i < 12; i++) {
    m_a = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      m_a += c_y_tmp[i + 12 * i1] * d_Dd[i1];
    }

    dv1[i] = ((dv[i] + d_y_tmp[i]) + m_a) + fj_k[i];
  }

  fj_k[0] = -par_mex_var[5] * z[12] * muDoubleScalarPower(a, par_mex_var[11] -
    1.0);
  fj_k[1] = -par_mex_var[6] * z[13] * muDoubleScalarPower(b_a, par_mex_var[11] -
    1.0);
  fj_k[2] = -par_mex_var[7] * z[14] * muDoubleScalarPower(c_a, par_mex_var[11] -
    1.0);
  fj_k[3] = -par_mex_var[10] * z[15] * muDoubleScalarPower(d_a, par_mex_var[11]
    - 1.0);
  fj_k[4] = -par_mex_var[8] * z[16] * muDoubleScalarPower(e_a, par_mex_var[11] -
    1.0);
  fj_k[5] = -par_mex_var[9] * z[17] * muDoubleScalarPower(f_a, par_mex_var[11] -
    1.0);
  fj_k[6] = -par_mex_var[5] * z[18] * muDoubleScalarPower(g_a, par_mex_var[11] -
    1.0);
  fj_k[7] = -par_mex_var[6] * z[19] * muDoubleScalarPower(h_a, par_mex_var[11] -
    1.0);
  fj_k[8] = -par_mex_var[7] * z[20] * muDoubleScalarPower(i_a, par_mex_var[11] -
    1.0);
  fj_k[9] = -par_mex_var[10] * z[21] * muDoubleScalarPower(j_a, par_mex_var[11]
    - 1.0);
  fj_k[10] = -par_mex_var[8] * z[22] * muDoubleScalarPower(k_a, par_mex_var[11]
    - 1.0);
  fj_k[11] = -par_mex_var[9] * z[23] * muDoubleScalarPower(l_a, par_mex_var[11]
    - 1.0);
  dv[0] = 0.0;
  dv[1] = 0.0;
  dv[2] = -t13;
  dv[3] = 0.0;
  dv[4] = t32;
  dv[5] = step;
  dv[6] = 0.0;
  dv[7] = 0.0;
  dv[8] = -t13;
  dv[9] = 0.0;
  dv[10] = t32;
  dv[11] = step;
  for (i = 0; i < 12; i++) {
    m_a = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      m_a += T[i + 12 * i1] * ftau_ex[i1];
    }

    d_y_tmp[i] = ((dv1[i] + fj_k[i]) + dv[i]) + m_a;
  }

  for (i = 0; i < 12; i++) {
    m_a = 0.0;
    for (i1 = 0; i1 < 12; i1++) {
      m_a += y[i + 12 * i1] * d_y_tmp[i1];
    }

    dz[i] = z[i + 12];
    dz[i + 12] = m_a;
  }

  *flag = 0.0;
}

/* End of code generation (EOM.c) */
