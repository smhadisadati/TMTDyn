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
#include "rt_nonfinite.h"
#include "sprdmpF10.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 9,     /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 24,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 29,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 36,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 41,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 52,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 57,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 67,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 73,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM_eq.m"/* pathName */
};

static emlrtDCInfo emlrtDCI = { 10,    /* lineNo */
  34,                                  /* colNo */
  "static_mid_step",                   /* fName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\static_mid_step.m",/* pName */
  1                                    /* checkKind */
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

/* Function Definitions */
void EOM_eq(const emlrtStack *sp, const real_T z[9], real_T res[9])
{
  static const int8_T iv[6] = { 0, 0, 1, 1, 2, 2 };

  emlrtStack st;
  real_T Dd[54];
  real_T T[54];
  real_T Tt[54];
  real_T b_Dd[54];
  real_T b_T[54];
  real_T b_Tt[54];
  real_T c_T[54];
  real_T M[36];
  real_T b_M[36];
  real_T b_z[18];
  real_T TMfd[9];
  real_T w_in[9];
  real_T w_sd[9];
  real_T b_fg[6];
  real_T b_in[6];
  real_T b_kx[6];
  real_T fg[6];
  real_T in[6];
  real_T kx[6];
  real_T vd[6];
  real_T b_sn;
  real_T d;
  real_T d1;
  real_T d2;
  real_T d3;
  real_T d4;
  real_T step;
  real_T unnamed_idx_19;
  real_T unnamed_idx_2;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T sn;
  st.prev = sp;
  st.tls = sp->tls;
  for (i = 0; i < 9; i++) {
    d = z[i];
    b_z[i] = d;
    b_z[i + 9] = 0.0 * d;
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
  /*     27-Feb-2021 16:40:36 */
  unnamed_idx_2 = par_mex.var[4];
  unnamed_idx_19 = par_mex.var[4];
  st.site = &b_emlrtRSI;
  massF1(&st, par_mex.var, b_z, 1.0E-6 * unnamed_idx_2, M, T, Dd, fg);
  st.site = &c_emlrtRSI;
  sprdmpF10(&st, par_mex.var, b_z, 1.0E-6 * unnamed_idx_19, Tt, kx, vd, in,
            &step);
  for (i = 0; i < 54; i++) {
    Tt[i] *= step;
  }

  st.site = &d_emlrtRSI;
  massF1(&st, par_mex.var, b_z, 0.999999 * unnamed_idx_2, b_M, b_T, b_Dd, b_fg);
  st.site = &e_emlrtRSI;
  sprdmpF10(&st, par_mex.var, b_z, 0.999999 * unnamed_idx_19, b_Tt, b_kx, vd,
            b_in, &step);
  for (i = 0; i < 54; i++) {
    b_Tt[i] *= step;
    Dd[i] = -Dd[i];
  }

  for (i = 0; i < 9; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      d = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        d += T[i2 + 6 * i] * M[i2 + 6 * i1];
      }

      c_T[i + 9 * i1] = d;
    }
  }

  for (i = 0; i < 6; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 9; i1++) {
      d += Dd[i + 6 * i1] * b_z[i1 + 9];
    }

    vd[i] = d + fg[i];
  }

  for (i = 0; i < 9; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      d += c_T[i + 9 * i1] * vd[i1];
    }

    TMfd[i] = d;
  }

  for (i = 0; i < 54; i++) {
    b_Dd[i] = -b_Dd[i];
  }

  for (i = 0; i < 9; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      d = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        d += b_T[i2 + 6 * i] * b_M[i2 + 6 * i1];
      }

      c_T[i + 9 * i1] = d;
    }
  }

  for (i = 0; i < 6; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 9; i1++) {
      d += b_Dd[i + 6 * i1] * b_z[i1 + 9];
    }

    vd[i] = d + b_fg[i];
  }

  for (i = 0; i < 9; i++) {
    d = 0.0;
    step = 0.0;
    b_sn = 0.0;
    d1 = 0.0;
    d2 = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      i2 = i + 9 * i1;
      d += c_T[i2] * vd[i1];
      d3 = Tt[i2];
      step += d3 * kx[i1];
      d4 = b_Tt[i2];
      b_sn += d4 * b_kx[i1];
      d1 += d3 * in[i1];
      d2 += d4 * b_in[i1];
    }

    TMfd[i] = (TMfd[i] * unnamed_idx_2 + d * unnamed_idx_2) / 2.0;
    w_sd[i] = (step * par_mex.var[4] + b_sn * par_mex.var[4]) / 2.0;
    w_in[i] = (d1 * par_mex.var[4] + d2 * par_mex.var[4]) / 2.0;
  }

  for (sn = 0; sn < 9; sn++) {
    b_sn = (real_T)sn * 0.1 + 0.100001;
    st.site = &f_emlrtRSI;
    massF1(&st, par_mex.var, b_z, b_sn * unnamed_idx_2, M, T, Dd, fg);
    for (i = 0; i < 54; i++) {
      Dd[i] = -Dd[i];
    }

    for (i = 0; i < 9; i++) {
      for (i1 = 0; i1 < 6; i1++) {
        d = 0.0;
        for (i2 = 0; i2 < 6; i2++) {
          d += T[i2 + 6 * i] * M[i2 + 6 * i1];
        }

        c_T[i + 9 * i1] = d;
      }
    }

    for (i = 0; i < 6; i++) {
      d = 0.0;
      for (i1 = 0; i1 < 9; i1++) {
        d += Dd[i + 6 * i1] * b_z[i1 + 9];
      }

      vd[i] = d + fg[i];
    }

    for (i = 0; i < 9; i++) {
      d = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        d += c_T[i + 9 * i1] * vd[i1];
      }

      TMfd[i] += d * unnamed_idx_2;
    }

    st.site = &g_emlrtRSI;
    sprdmpF10(&st, par_mex.var, b_z, b_sn * unnamed_idx_19, Tt, kx, vd, in,
              &step);
    for (i = 0; i < 54; i++) {
      Tt[i] *= step;
    }

    for (i = 0; i < 9; i++) {
      d = 0.0;
      step = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        b_sn = Tt[i + 9 * i1];
        d += b_sn * kx[i1];
        step += b_sn * in[i1];
      }

      w_sd[i] += d * par_mex.var[4];
      w_in[i] += step * par_mex.var[4];
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  for (i = 0; i < 9; i++) {
    TMfd[i] /= 10.0;
    w_sd[i] /= 10.0;
    w_in[i] /= 10.0;
  }

  st.site = &h_emlrtRSI;
  massF2(&st, par_mex.var, b_z, M, T, Dd, fg);
  for (i = 0; i < 54; i++) {
    Dd[i] = -Dd[i];
  }

  for (i = 0; i < 9; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      d = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        d += T[i2 + 6 * i] * M[i2 + 6 * i1];
      }

      c_T[i + 9 * i1] = d;
    }
  }

  for (i = 0; i < 6; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 9; i1++) {
      d += Dd[i + 6 * i1] * b_z[i1 + 9];
    }

    vd[i] = d + fg[i];
  }

  for (i = 0; i < 9; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      d += c_T[i + 9 * i1] * vd[i1];
    }

    TMfd[i] += d;
  }

  st.site = &i_emlrtRSI;
  loadsF1(&st, par_mex.var, b_z, T, fg);

  /*  EOM */
  for (i = 0; i < 9; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      d += T[i + 9 * i1] * fg[i1];
    }

    res[i] = ((TMfd[i] + w_sd[i]) + w_in[i]) + d;
  }
}

/* End of code generation (EOM_eq.c) */
