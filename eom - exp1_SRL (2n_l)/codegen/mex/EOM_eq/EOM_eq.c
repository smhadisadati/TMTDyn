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
#include "loadsF1.h"
#include "massF1.h"
#include "massF2.h"
#include "massF3.h"
#include "mtimes.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 9,     /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 11,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 12,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 21,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 23,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 26,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 28,  /* lineNo */
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

static emlrtRSInfo j_emlrtRSI = { 37,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 22, /* lineNo */
  "fj_inF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\fj_inF.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 13,  /* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pName */
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
void EOM_eq(const emlrtStack *sp, const real_T z[12], real_T res[12])
{
  static const int8_T iv[6] = { 0, 0, 1, 1, 2, 2 };

  emlrtStack b_st;
  emlrtStack st;
  real_T unusedExpr[144];
  real_T Dd[72];
  real_T T[72];
  real_T b_Dd[72];
  real_T b_y_tmp[72];
  real_T c_Dd[72];
  real_T c_y_tmp[72];
  real_T y_tmp[72];
  real_T M[36];
  real_T b_z[24];
  real_T d_y_tmp[12];
  real_T dv[12];
  real_T dv1[12];
  real_T b_fg[6];
  real_T c_fg[6];
  real_T d_Dd[6];
  real_T fg[6];
  real_T ftau_ex[6];
  real_T b_t13;
  real_T b_t32_tmp;
  real_T step;
  real_T t13;
  real_T t14;
  real_T t20_tmp;
  real_T t30;
  real_T t31;
  real_T t32;
  real_T t32_tmp;
  real_T t33;
  real_T t37_tmp;
  real_T t4_tmp;
  real_T t8;
  real_T t9;
  int32_T i;
  int32_T i1;
  int32_T i2;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  for (i = 0; i < 12; i++) {
    step = z[i];
    b_z[i] = step;
    b_z[i + 12] = 0.0 * step;
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

  /* FJ_KF */
  /*     OUT1 = FJ_KF(IN1,IN2,S,DS,T_SYM) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
  /*     26-Feb-2021 18:56:22 */
  t33 = muDoubleScalarCos(par_mex.var[20]);
  step = muDoubleScalarSin(par_mex.var[20]);
  t4_tmp = par_mex.var[33] * par_mex.var[33];
  t32 = par_mex.var[18] * par_mex.var[18];
  t8 = par_mex.var[2] * par_mex.var[2];
  t9 = par_mex.var[3] * par_mex.var[3];
  t13 = 1.0 / par_mex.var[4];
  t14 = 1.0 / par_mex.var[33];
  step = 1.0 / (step * step);
  t20_tmp = t4_tmp * (t33 * t33);
  t30 = t14 * (t8 + -t9) + -(t32 * step * (t20_tmp - 1.0) * 6.0);
  t31 = 1.0 / t4_tmp * (t8 * t8 + -(t9 * t9)) + t32 * t32 * (step * step) *
    ((t20_tmp - 1.0) * (t20_tmp - 1.0)) * 6.0;
  t37_tmp = t31 * 3.1415926535897931 / 4.0 + -(par_mex.var[19] * par_mex.var[19]
    * t32 * t14 * step * (t20_tmp - 1.0) * 3.1415926535897931 * 3.0);
  st.site = &c_emlrtRSI;

  /* FJ_INF */
  /*     OUT1 = FJ_INF(IN1,IN2,S,DS,T_SYM) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
  /*     26-Feb-2021 18:56:22 */
  b_st.site = &ab_emlrtRSI;
  if (par_mex.var[33] < 0.0) {
    emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  t8 = 1.0 / muDoubleScalarSqrt(par_mex.var[33]);
  b_t13 = t32 * step * (((((par_mex.var[21] + par_mex.var[22]) + par_mex.var[23])
    + par_mex.var[24]) + par_mex.var[25]) + par_mex.var[26]) * (t20_tmp - 1.0) *
    3.1415926535897931;
  t33 = par_mex.var[22] * par_mex.var[19] * t32 * step * t8;
  t4_tmp = par_mex.var[21] * par_mex.var[19] * t32 * step * t8;
  t9 = par_mex.var[23] * par_mex.var[19] * t32 * step * t8 * (t20_tmp - 1.0) *
    3.1415926535897931;
  t32_tmp = par_mex.var[24] * par_mex.var[19] * t32 * step * t8 * (t20_tmp - 1.0)
    * 3.1415926535897931;
  b_t32_tmp = par_mex.var[26] * par_mex.var[19] * t32 * step * t8 * (t20_tmp -
    1.0) * 3.1415926535897931;
  step = par_mex.var[25] * par_mex.var[19] * t32 * step * t8 * (t20_tmp - 1.0) *
    3.1415926535897931;
  t32 = ((((-(t4_tmp * (t20_tmp - 1.0) * 3.1415926535897931 *
              0.93771626297577859) + -(t33 * (t20_tmp - 1.0) *
             3.1415926535897931 * 0.93771626297577859)) + step *
           0.76971716428074932) + t32_tmp * 0.76971716428074954) + b_t32_tmp *
         0.16799909869502891) + t9 * 0.167999098695029;
  t33 = ((((t33 * 8.3666002653407556 * (t20_tmp - 1.0) * 3.1415926535897931 *
            0.041522491349480967 + -(t4_tmp * 8.3666002653407556 * (t20_tmp -
              1.0) * 3.1415926535897931 * 0.041522491349480967)) + t9 *
           0.9857871488499218) + t32_tmp * 0.63838506170774523) + -(b_t32_tmp *
          0.9857871488499218)) + -(step * 0.63838506170774545);
  st.site = &d_emlrtRSI;
  massF1(par_mex.var, b_z, M, T, Dd, fg);
  for (i = 0; i < 12; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      step = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        step += T[i2 + 6 * i] * M[i2 + 6 * i1];
      }

      y_tmp[i + 12 * i1] = step;
    }
  }

  st.site = &e_emlrtRSI;
  mtimes(y_tmp, T, unusedExpr);
  st.site = &f_emlrtRSI;
  massF2(par_mex.var, b_z, M, T, b_Dd, b_fg);
  for (i = 0; i < 12; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      step = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        step += T[i2 + 6 * i] * M[i2 + 6 * i1];
      }

      b_y_tmp[i + 12 * i1] = step;
    }
  }

  st.site = &g_emlrtRSI;
  mtimes(b_y_tmp, T, unusedExpr);
  st.site = &h_emlrtRSI;
  massF3(par_mex.var, b_z, M, T, c_Dd, c_fg);
  for (i = 0; i < 12; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      step = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        step += T[i2 + 6 * i] * M[i2 + 6 * i1];
      }

      c_y_tmp[i + 12 * i1] = step;
    }
  }

  st.site = &i_emlrtRSI;
  mtimes(c_y_tmp, T, unusedExpr);
  st.site = &j_emlrtRSI;
  loadsF1(par_mex.var, b_z, T, ftau_ex);

  /*  EOM */
  for (i = 0; i < 72; i++) {
    Dd[i] = -Dd[i];
  }

  for (i = 0; i < 6; i++) {
    step = 0.0;
    for (i1 = 0; i1 < 12; i1++) {
      step += Dd[i + 6 * i1] * b_z[i1 + 12];
    }

    d_Dd[i] = step + fg[i];
  }

  for (i = 0; i < 72; i++) {
    b_Dd[i] = -b_Dd[i];
  }

  for (i = 0; i < 6; i++) {
    step = 0.0;
    for (i1 = 0; i1 < 12; i1++) {
      step += b_Dd[i + 6 * i1] * b_z[i1 + 12];
    }

    fg[i] = step + b_fg[i];
  }

  for (i = 0; i < 12; i++) {
    step = 0.0;
    t4_tmp = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      i2 = i + 12 * i1;
      step += y_tmp[i2] * d_Dd[i1];
      t4_tmp += b_y_tmp[i2] * fg[i1];
    }

    d_y_tmp[i] = t4_tmp;
    dv[i] = step;
  }

  for (i = 0; i < 72; i++) {
    c_Dd[i] = -c_Dd[i];
  }

  for (i = 0; i < 6; i++) {
    step = 0.0;
    for (i1 = 0; i1 < 12; i1++) {
      step += c_Dd[i + 6 * i1] * b_z[i1 + 12];
    }

    d_Dd[i] = step + c_fg[i];
  }

  for (i = 0; i < 12; i++) {
    step = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      step += c_y_tmp[i + 12 * i1] * d_Dd[i1];
    }

    dv1[i] = (dv[i] + d_y_tmp[i]) + step;
  }

  dv[0] = par_mex.var[1] * b_z[0] * t13 * t14 * t30 * 3.1415926535897931 *
    0.66666666666666663;
  dv[1] = par_mex.var[1] * b_z[1] * t13 * t14 * t30 * 3.1415926535897931 *
    0.66666666666666663;
  dv[2] = par_mex.var[1] * b_z[2] * t13 * t14 * t30 * 3.1415926535897931 * 2.0;
  dv[3] = par_mex.var[1] * b_z[3] * t13 * t14 * t31 * 3.1415926535897931 / 3.0;
  dv[4] = par_mex.var[1] * b_z[4] * t13 * t14 * t37_tmp * 2.0;
  dv[5] = par_mex.var[1] * b_z[5] * t13 * t14 * t37_tmp * 2.0;
  dv[6] = par_mex.var[1] * b_z[6] * t13 * t14 * t30 * 3.1415926535897931 *
    0.66666666666666663;
  dv[7] = par_mex.var[1] * b_z[7] * t13 * t14 * t30 * 3.1415926535897931 *
    0.66666666666666663;
  dv[8] = par_mex.var[1] * b_z[8] * t13 * t14 * t30 * 3.1415926535897931 * 2.0;
  dv[9] = par_mex.var[1] * b_z[9] * t13 * t14 * t31 * 3.1415926535897931 / 3.0;
  dv[10] = par_mex.var[1] * b_z[10] * t13 * t14 * t37_tmp * 2.0;
  dv[11] = par_mex.var[1] * b_z[11] * t13 * t14 * t37_tmp * 2.0;
  d_y_tmp[0] = 0.0;
  d_y_tmp[1] = 0.0;
  d_y_tmp[2] = -b_t13;
  d_y_tmp[3] = 0.0;
  d_y_tmp[4] = t32;
  d_y_tmp[5] = t33;
  d_y_tmp[6] = 0.0;
  d_y_tmp[7] = 0.0;
  d_y_tmp[8] = -b_t13;
  d_y_tmp[9] = 0.0;
  d_y_tmp[10] = t32;
  d_y_tmp[11] = t33;
  for (i = 0; i < 12; i++) {
    step = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      step += T[i + 12 * i1] * ftau_ex[i1];
    }

    res[i] = ((dv1[i] + dv[i]) + d_y_tmp[i]) + step;
  }
}

/* End of code generation (EOM_eq.c) */
