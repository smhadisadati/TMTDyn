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
#include "loadsF1.h"
#include "massF1.h"
#include "massF2.h"
#include "mtimes.h"
#include "pinv.h"
#include "rt_nonfinite.h"
#include "sprdmpF18.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 6,     /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 22,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 27,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 34,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 39,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 50,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 55,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 65,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 71,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 81,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM.m"/* pathName */
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
void EOM(const emlrtStack *sp, real_T t, const real_T z[34], const struct0_T
         *par_mex, real_T dz[34], real_T *flag)
{
  static const int8_T iv[6] = { 0, 0, 1, 1, 2, 2 };

  emlrtStack st;
  real_T TMT[289];
  real_T c_y[289];
  real_T Dd[102];
  real_T T[102];
  real_T Tt[102];
  real_T b_Dd[102];
  real_T b_Tt[102];
  real_T b_y[102];
  real_T y[102];
  real_T M[36];
  real_T par_mex_var[34];
  real_T TMfd[17];
  real_T b_TMfd[17];
  real_T w_in[17];
  real_T w_sd[17];
  real_T w_vd_j[17];
  real_T b_fg[6];
  real_T b_in[6];
  real_T b_kx[6];
  real_T b_vd[6];
  real_T c_Dd[6];
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
  real_T d5;
  real_T d6;
  real_T step;
  real_T unnamed_idx_2;
  int32_T i;
  int32_T i1;
  int32_T sn;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &emlrtRSI;
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
  /*  s0 = 1e-6 ; l = 0 ; */
  /*  ds = par_mex.var(5) / 1e1 ; */
  /*  for s = s0 : ds : par_mex.var(5) - s0 */
  /*      [ ~ , ~ , ~ , ~ , ~ , ~ , dl ] = sprdmpF19( par_mex.var , z , s , 0 , 0 ) ; */
  /*      l = l + dl(3) * ds ; */
  /*  end */
  /*  lambda = l / par_mex.var(5) ; */
  /*  update simulation parameters */
  for (i = 0; i < 6; i++) {
    par_mex_var[i + 21] = par_mex->user_pars.p[((int32_T)step + 1094 * (iv[i] +
      1)) - 1];
    par_mex_var[i + 27] = par_mex->user_pars.f_ex[((int32_T)step + 1094 * (i + 1))
      - 1];
  }

  par_mex_var[33] = 1.0;

  /* ROMF */
  /*     [OUT1,OUT2] = ROMF(IN1,IN2,S,DS,T_SYM) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
  /*     15-Jun-2021 03:31:37 */
  unnamed_idx_2 = par_mex_var[4];
  st.site = &b_emlrtRSI;
  massF1(&st, par_mex_var, z, 1.0E-6 * par_mex_var[4], M, T, Dd, fg);
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 17; i1++) {
      Tt[i1 + 17 * i] = T[i + 6 * i1];
    }
  }

  mtimes(Tt, M, y);
  b_mtimes(y, T, TMT);
  mtimes(Tt, M, y);
  st.site = &e_emlrtRSI;
  sprdmpF18(&st, par_mex_var, z, 1.0E-6 * par_mex_var[4], b_Tt, kx, vd, in,
            &step);
  st.site = &f_emlrtRSI;
  massF1(&st, par_mex_var, z, 0.999999 * par_mex_var[4], M, T, b_Dd, b_fg);
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 17; i1++) {
      Tt[i1 + 17 * i] = T[i + 6 * i1];
    }
  }

  mtimes(Tt, M, b_y);
  b_mtimes(b_y, T, c_y);
  mtimes(Tt, M, b_y);
  st.site = &i_emlrtRSI;
  sprdmpF18(&st, par_mex_var, z, 0.999999 * par_mex_var[4], Tt, b_kx, b_vd, b_in,
            &step);
  for (i = 0; i < 289; i++) {
    TMT[i] = (TMT[i] * unnamed_idx_2 + c_y[i] * unnamed_idx_2) / 2.0;
  }

  for (i = 0; i < 102; i++) {
    Dd[i] = -Dd[i];
  }

  for (i = 0; i < 6; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 17; i1++) {
      d += Dd[i + 6 * i1] * z[i1 + 17];
    }

    c_Dd[i] = d + fg[i];
  }

  for (i = 0; i < 17; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      d += y[i + 17 * i1] * c_Dd[i1];
    }

    TMfd[i] = d;
  }

  for (i = 0; i < 102; i++) {
    b_Dd[i] = -b_Dd[i];
  }

  for (i = 0; i < 6; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 17; i1++) {
      d += b_Dd[i + 6 * i1] * z[i1 + 17];
    }

    c_Dd[i] = d + b_fg[i];
  }

  for (i = 0; i < 17; i++) {
    d = 0.0;
    step = 0.0;
    b_sn = 0.0;
    d1 = 0.0;
    d2 = 0.0;
    d3 = 0.0;
    d4 = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      sn = i + 17 * i1;
      d += b_y[sn] * c_Dd[i1];
      d5 = b_Tt[sn];
      step += d5 * vd[i1];
      d6 = Tt[sn];
      b_sn += d6 * b_vd[i1];
      d1 += d5 * kx[i1];
      d2 += d6 * b_kx[i1];
      d3 += d5 * in[i1];
      d4 += d6 * b_in[i1];
    }

    TMfd[i] = (TMfd[i] * unnamed_idx_2 + d * unnamed_idx_2) / 2.0;
    w_vd_j[i] = (step * par_mex_var[4] + b_sn * par_mex_var[4]) / 2.0;
    w_sd[i] = (d1 * par_mex_var[4] + d2 * par_mex_var[4]) / 2.0;
    w_in[i] = (d3 * par_mex_var[4] + d4 * par_mex_var[4]) / 2.0;
  }

  for (sn = 0; sn < 9; sn++) {
    b_sn = (real_T)sn * 0.1 + 0.100001;
    st.site = &j_emlrtRSI;
    massF1(&st, par_mex_var, z, b_sn * unnamed_idx_2, M, T, Dd, fg);
    for (i = 0; i < 6; i++) {
      for (i1 = 0; i1 < 17; i1++) {
        Tt[i1 + 17 * i] = T[i + 6 * i1];
      }
    }

    mtimes(Tt, M, y);
    b_mtimes(y, T, c_y);
    for (i = 0; i < 289; i++) {
      TMT[i] += c_y[i] * unnamed_idx_2;
    }

    mtimes(Tt, M, y);
    for (i = 0; i < 102; i++) {
      Dd[i] = -Dd[i];
    }

    for (i = 0; i < 6; i++) {
      d = 0.0;
      for (i1 = 0; i1 < 17; i1++) {
        d += Dd[i + 6 * i1] * z[i1 + 17];
      }

      c_Dd[i] = d + fg[i];
    }

    for (i = 0; i < 17; i++) {
      d = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        d += y[i + 17 * i1] * c_Dd[i1];
      }

      TMfd[i] += d * unnamed_idx_2;
    }

    st.site = &m_emlrtRSI;
    sprdmpF18(&st, par_mex_var, z, b_sn * par_mex_var[4], Tt, kx, vd, in, &step);
    for (i = 0; i < 17; i++) {
      d = 0.0;
      step = 0.0;
      b_sn = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        d1 = Tt[i + 17 * i1];
        d += d1 * vd[i1];
        step += d1 * kx[i1];
        b_sn += d1 * in[i1];
      }

      w_vd_j[i] += d * par_mex_var[4];
      w_sd[i] += step * par_mex_var[4];
      w_in[i] += b_sn * par_mex_var[4];
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  for (i = 0; i < 289; i++) {
    TMT[i] /= 10.0;
  }

  for (i = 0; i < 17; i++) {
    TMfd[i] /= 10.0;
    w_vd_j[i] /= 10.0;
    w_sd[i] /= 10.0;
    w_in[i] /= 10.0;
  }

  st.site = &n_emlrtRSI;
  massF2(&st, par_mex_var, z, M, T, Dd, fg);
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 17; i1++) {
      Tt[i1 + 17 * i] = T[i + 6 * i1];
    }
  }

  mtimes(Tt, M, y);
  b_mtimes(y, T, c_y);
  mtimes(Tt, M, y);
  for (i = 0; i < 102; i++) {
    Dd[i] = -Dd[i];
  }

  for (i = 0; i < 6; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 17; i1++) {
      d += Dd[i + 6 * i1] * z[i1 + 17];
    }

    c_Dd[i] = d + fg[i];
  }

  for (i = 0; i < 17; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      d += y[i + 17 * i1] * c_Dd[i1];
    }

    TMfd[i] += d;
  }

  st.site = &q_emlrtRSI;
  loadsF1(&st, par_mex_var, z, T, fg);

  /*  EOM */
  for (i = 0; i < 289; i++) {
    TMT[i] += c_y[i];
  }

  st.site = &r_emlrtRSI;
  pinv(&st, TMT, c_y);
  for (i = 0; i < 17; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      d += T[i + 17 * i1] * fg[i1];
    }

    b_TMfd[i] = (((TMfd[i] + w_sd[i]) + w_in[i]) + w_vd_j[i]) + d;
  }

  for (i = 0; i < 17; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 17; i1++) {
      d += c_y[i + 17 * i1] * b_TMfd[i1];
    }

    dz[i] = z[i + 17];
    dz[i + 17] = d;
  }

  *flag = 0.0;
}

/* End of code generation (EOM.c) */
