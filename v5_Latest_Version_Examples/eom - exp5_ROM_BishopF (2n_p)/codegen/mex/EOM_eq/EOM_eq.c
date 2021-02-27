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
#include "rt_nonfinite.h"
#include "sprdmpF6.h"
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

static emlrtRSInfo ud_emlrtRSI = { 40, /* lineNo */
  "loadsF1",                           /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\loadsF1.m"/* pathName */
};

static emlrtRSInfo wd_emlrtRSI = { 47, /* lineNo */
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
void EOM_eq(const emlrtStack *sp, const real_T z[5], real_T res[5])
{
  static const int8_T iv[6] = { 0, 0, 1, 1, 2, 2 };

  emlrtStack b_st;
  emlrtStack st;
  real_T M[36];
  real_T b_M[36];
  real_T Dd[30];
  real_T T[30];
  real_T Tt[30];
  real_T b_Dd[30];
  real_T b_T[30];
  real_T b_Tt[30];
  real_T c_T[30];
  real_T b_z[10];
  real_T b_fg[6];
  real_T b_in[6];
  real_T b_kx[6];
  real_T fg[6];
  real_T in[6];
  real_T kx[6];
  real_T vd[6];
  real_T TMfd[5];
  real_T w_in[5];
  real_T w_sd[5];
  real_T b_sn;
  real_T b_t111_tmp;
  real_T step;
  real_T t103;
  real_T t104;
  real_T t105;
  real_T t106;
  real_T t110;
  real_T t111;
  real_T t111_tmp;
  real_T t112;
  real_T t113;
  real_T t114;
  real_T t115;
  real_T t115_tmp;
  real_T t116_tmp;
  real_T t15;
  real_T t16;
  real_T t17;
  real_T t18;
  real_T t2;
  real_T t20;
  real_T t21;
  real_T t22;
  real_T t23;
  real_T t25_tmp;
  real_T t28;
  real_T t29;
  real_T t3;
  real_T t30;
  real_T t32_tmp;
  real_T t34_tmp;
  real_T t38;
  real_T t39;
  real_T t39_tmp;
  real_T t4;
  real_T t40;
  real_T t40_tmp;
  real_T t42;
  real_T t5;
  real_T t51;
  real_T t52;
  real_T t6_tmp;
  real_T t73;
  real_T t74;
  real_T t77;
  real_T t77_tmp;
  real_T t78;
  real_T t78_tmp;
  real_T t91;
  real_T t92;
  real_T t93;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T sn;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  for (i = 0; i < 5; i++) {
    t111_tmp = z[i];
    b_z[i] = t111_tmp;
    b_z[i + 5] = 0.0 * t111_tmp;
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
  /*     27-Feb-2021 16:27:16 */
  t3 = par_mex.var[4];
  t5 = par_mex.var[4];
  st.site = &b_emlrtRSI;
  massF1(&st, par_mex.var, b_z, 1.0E-6 * t3, M, T, Dd, fg);
  st.site = &c_emlrtRSI;
  sprdmpF6(&st, par_mex.var, b_z, 1.0E-6 * t5, Tt, kx, vd, in, &step);
  for (i = 0; i < 30; i++) {
    Tt[i] *= step;
  }

  st.site = &d_emlrtRSI;
  massF1(&st, par_mex.var, b_z, 0.999999 * t3, b_M, b_T, b_Dd, b_fg);
  st.site = &e_emlrtRSI;
  sprdmpF6(&st, par_mex.var, b_z, 0.999999 * t5, b_Tt, b_kx, vd, b_in, &step);
  for (i = 0; i < 30; i++) {
    b_Tt[i] *= step;
    Dd[i] = -Dd[i];
  }

  for (i = 0; i < 5; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      t111_tmp = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        t111_tmp += T[i2 + 6 * i] * M[i2 + 6 * i1];
      }

      c_T[i + 5 * i1] = t111_tmp;
    }
  }

  for (i = 0; i < 6; i++) {
    t111_tmp = 0.0;
    for (i1 = 0; i1 < 5; i1++) {
      t111_tmp += Dd[i + 6 * i1] * b_z[i1 + 5];
    }

    vd[i] = t111_tmp + fg[i];
  }

  for (i = 0; i < 5; i++) {
    t111_tmp = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      t111_tmp += c_T[i + 5 * i1] * vd[i1];
    }

    TMfd[i] = t111_tmp;
  }

  for (i = 0; i < 30; i++) {
    b_Dd[i] = -b_Dd[i];
  }

  for (i = 0; i < 5; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      t111_tmp = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        t111_tmp += b_T[i2 + 6 * i] * b_M[i2 + 6 * i1];
      }

      c_T[i + 5 * i1] = t111_tmp;
    }
  }

  for (i = 0; i < 6; i++) {
    t111_tmp = 0.0;
    for (i1 = 0; i1 < 5; i1++) {
      t111_tmp += b_Dd[i + 6 * i1] * b_z[i1 + 5];
    }

    vd[i] = t111_tmp + b_fg[i];
  }

  for (i = 0; i < 5; i++) {
    t111_tmp = 0.0;
    step = 0.0;
    b_sn = 0.0;
    t77_tmp = 0.0;
    t78_tmp = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      i2 = i + 5 * i1;
      t111_tmp += c_T[i2] * vd[i1];
      t4 = Tt[i2];
      step += t4 * kx[i1];
      b_t111_tmp = b_Tt[i2];
      b_sn += b_t111_tmp * b_kx[i1];
      t77_tmp += t4 * in[i1];
      t78_tmp += b_t111_tmp * b_in[i1];
    }

    TMfd[i] = (TMfd[i] * t3 + t111_tmp * t3) / 2.0;
    w_sd[i] = (step * par_mex.var[4] + b_sn * par_mex.var[4]) / 2.0;
    w_in[i] = (t77_tmp * par_mex.var[4] + t78_tmp * par_mex.var[4]) / 2.0;
  }

  for (sn = 0; sn < 9; sn++) {
    b_sn = (real_T)sn * 0.1 + 0.100001;
    st.site = &f_emlrtRSI;
    massF1(&st, par_mex.var, b_z, b_sn * t3, M, T, Dd, fg);
    for (i = 0; i < 30; i++) {
      Dd[i] = -Dd[i];
    }

    for (i = 0; i < 5; i++) {
      for (i1 = 0; i1 < 6; i1++) {
        t111_tmp = 0.0;
        for (i2 = 0; i2 < 6; i2++) {
          t111_tmp += T[i2 + 6 * i] * M[i2 + 6 * i1];
        }

        c_T[i + 5 * i1] = t111_tmp;
      }
    }

    for (i = 0; i < 6; i++) {
      t111_tmp = 0.0;
      for (i1 = 0; i1 < 5; i1++) {
        t111_tmp += Dd[i + 6 * i1] * b_z[i1 + 5];
      }

      vd[i] = t111_tmp + fg[i];
    }

    for (i = 0; i < 5; i++) {
      t111_tmp = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        t111_tmp += c_T[i + 5 * i1] * vd[i1];
      }

      TMfd[i] += t111_tmp * t3;
    }

    st.site = &g_emlrtRSI;
    sprdmpF6(&st, par_mex.var, b_z, b_sn * t5, Tt, kx, vd, in, &step);
    for (i = 0; i < 30; i++) {
      Tt[i] *= step;
    }

    for (i = 0; i < 5; i++) {
      t111_tmp = 0.0;
      step = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        b_sn = Tt[i + 5 * i1];
        t111_tmp += b_sn * kx[i1];
        step += b_sn * in[i1];
      }

      w_sd[i] += t111_tmp * par_mex.var[4];
      w_in[i] += step * par_mex.var[4];
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  for (i = 0; i < 5; i++) {
    TMfd[i] /= 10.0;
    w_sd[i] /= 10.0;
    w_in[i] /= 10.0;
  }

  st.site = &h_emlrtRSI;
  massF2(&st, par_mex.var, b_z, M, T, Dd, fg);
  for (i = 0; i < 30; i++) {
    Dd[i] = -Dd[i];
  }

  for (i = 0; i < 5; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      t111_tmp = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        t111_tmp += T[i2 + 6 * i] * M[i2 + 6 * i1];
      }

      c_T[i + 5 * i1] = t111_tmp;
    }
  }

  for (i = 0; i < 6; i++) {
    t111_tmp = 0.0;
    for (i1 = 0; i1 < 5; i1++) {
      t111_tmp += Dd[i + 6 * i1] * b_z[i1 + 5];
    }

    vd[i] = t111_tmp + fg[i];
  }

  for (i = 0; i < 5; i++) {
    t111_tmp = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      t111_tmp += c_T[i + 5 * i1] * vd[i1];
    }

    TMfd[i] += t111_tmp;
  }

  st.site = &i_emlrtRSI;

  /* LOADSF1 */
  /*     [OUT1,OUT2,OUT3] = LOADSF1(IN1,IN2,S,DS,T_SYM) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
  /*     27-Feb-2021 16:28:43 */
  t2 = par_mex.var[4] * par_mex.var[4];
  t3 = muDoubleScalarPower(par_mex.var[4], 3.0);
  t4 = b_z[0] * b_z[0];
  t5 = b_z[1] * b_z[1];
  t6_tmp = par_mex.var[4] * b_z[2] * 2.0;
  b_sn = (t6_tmp + 1.0) * (t6_tmp + 1.0);
  step = par_mex.var[4] * b_z[3] / 2.0 + b_z[4] * t2 / 2.0;
  t15 = muDoubleScalarCos(step);
  t16 = muDoubleScalarSin(step);
  step = (b_sn + t2 * t4 * 4.0) + t2 * t5 * 4.0;
  t17 = t16 * t16;
  t18 = t15 * t15;
  t20 = 1.0 / (step * step);
  b_st.site = &ud_emlrtRSI;
  if (step < 0.0) {
    emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  t21 = 1.0 / muDoubleScalarSqrt(step);
  t22 = muDoubleScalarPower(t21, 3.0);
  t23 = par_mex.var[4] * t21 * 2.0;
  t25_tmp = (t6_tmp + 1.0) * t21 + 1.0;
  b_st.site = &wd_emlrtRSI;
  if (t25_tmp < 0.0) {
    emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  t28 = muDoubleScalarSqrt(t25_tmp);
  t29 = 1.0 / t28;
  t32_tmp = 1.4142135623730951 * t15 * t28;
  t34_tmp = 1.4142135623730951 * t16 * t28;
  t38 = t23 + -(par_mex.var[4] * b_sn * t22 * 2.0);
  t30 = muDoubleScalarPower(t29, 3.0);
  t39_tmp = par_mex.var[4] * 1.4142135623730951 * t15;
  t39 = t39_tmp * t21 * t29;
  t40_tmp = par_mex.var[4] * 1.4142135623730951 * t16;
  t40 = t40_tmp * t21 * t29;
  step = b_z[0] * b_z[1] * t3 * 1.4142135623730951;
  t51 = step * t15 * t22 * t29 * 4.0;
  t52 = step * t16 * t22 * t29 * 4.0;
  t77_tmp = b_z[0] * t2 * 1.4142135623730951;
  t77 = t77_tmp * (t6_tmp + 1.0) * t16 * t22 * t29 * 2.0;
  t78_tmp = b_z[1] * t2 * 1.4142135623730951;
  t78 = t78_tmp * (t6_tmp + 1.0) * t16 * t22 * t29 * 2.0;
  t42 = b_z[1] * t39;
  step *= t6_tmp + 1.0;
  t73 = step * t15 * t20 * t30 * 2.0;
  t74 = step * t16 * t20 * t30 * 2.0;
  t93 = b_z[0] * 1.4142135623730951 * t15 * t23 * t29 + b_z[1] *
    1.4142135623730951 * t16 * t23 * t29;
  t103 = t77_tmp * t15 * t21 * t29 / 2.0 + t78_tmp * t16 * t21 * t29 / 2.0;
  step = b_z[1] * t3 * 1.4142135623730951;
  b_sn = b_z[0] * t3 * 1.4142135623730951;
  t104 = b_sn * t15 * t21 * t29 / 2.0 + step * t16 * t21 * t29 / 2.0;
  t91 = b_z[0] * t39 + b_z[1] * t40;
  t105 = t78_tmp * t15 * t21 * t29 / 2.0 + -(t77_tmp * t16 * t21 * t29 / 2.0);
  t106 = step * t15 * t21 * t29 / 2.0 + -(b_sn * t16 * t21 * t29 / 2.0);
  b_t111_tmp = t3 * t4 * 1.4142135623730951;
  t111_tmp = b_t111_tmp * (t6_tmp + 1.0);
  t111 = (((t39 + -t52) + -(b_t111_tmp * t15 * t22 * t29 * 4.0)) + t74) +
    t111_tmp * t15 * t20 * t30 * 2.0;
  step = t3 * t5 * 1.4142135623730951;
  b_sn = step * (t6_tmp + 1.0);
  t114 = (((t40 + -t51) + -(step * t16 * t22 * t29 * 4.0)) + t73) + b_sn * t16 *
    t20 * t30 * 2.0;
  t3 = par_mex.var[4] * b_z[1] * 1.4142135623730951;
  t5 = par_mex.var[4] * b_z[0] * 1.4142135623730951;
  t115_tmp = b_z[0] * t2 * 1.4142135623730951 * (t6_tmp + 1.0) * t15 * t22 * t29;
  t115 = ((t115_tmp * 2.0 + t78) + t5 * t15 * t21 * t30 * t38 / 2.0) + t3 * t16 *
    t21 * t30 * t38 / 2.0;
  t92 = t42 + -(b_z[0] * t40);
  t112 = (((t39 + t52) + -(step * t15 * t22 * t29 * 4.0)) + b_sn * t15 * t20 *
          t30 * 2.0) + -t74;
  t113 = (((t40 + t51) + -(b_t111_tmp * t16 * t22 * t29 * 4.0)) + t111_tmp * t16
          * t20 * t30 * 2.0) + -t73;
  t116_tmp = b_z[1] * t2 * 1.4142135623730951 * (t6_tmp + 1.0) * t15 * t22 * t29;
  t39 = ((t116_tmp * 2.0 + -t77) + t3 * t15 * t21 * t30 * t38 / 2.0) + -(t5 *
    t16 * t21 * t30 * t38 / 2.0);
  t30 = (t32_tmp * par_mex.var[30] / 2.0 + t34_tmp * par_mex.var[31] / 2.0) +
    -(t91 * par_mex.var[32]);
  t21 = (t32_tmp * par_mex.var[32] / 2.0 + t91 * par_mex.var[30]) + t92 *
    par_mex.var[31];
  t110 = (t34_tmp * par_mex.var[32] / 2.0 + t91 * par_mex.var[31]) + -(t92 *
    par_mex.var[30]);

  /*  EOM */
  b_sn = par_mex.var[16] * 1.4142135623730951 * t16;
  t52 = b_sn * t28;
  step = par_mex.var[16] * 1.4142135623730951 * t15;
  t73 = step * t28;
  t40 = par_mex.var[16] * b_z[0] * t2;
  t51 = t40 * 1.4142135623730951 * (t6_tmp + 1.0);
  t20 = t51 * t15 * t22 * t29;
  Tt[0] = (((t2 + par_mex.var[16] * t77 * t92) + t73 * t111) + t52 * t113) - t20
    * t91 * 2.0;
  t3 = par_mex.var[16] * b_z[1] * t2;
  t5 = t3 * 1.4142135623730951 * (t6_tmp + 1.0);
  t74 = t5 * t15 * t22 * t29;
  Tt[1] = ((par_mex.var[16] * t78 * t92 - t52 * t112) + t73 * t114) - t74 * t91 *
    2.0;
  t111_tmp = -par_mex.var[16] * 1.4142135623730951 * t15 * t28;
  b_t111_tmp = step * t29 * t38;
  step = b_sn * t29 * t38;
  Tt[2] = ((t111_tmp * t115 + t52 * t39) + b_t111_tmp * t91 / 2.0) - step * t92 /
    2.0;
  b_sn = par_mex.var[16] * par_mex.var[4] * 1.4142135623730951;
  t77_tmp = b_sn * t15 * t28;
  b_sn = b_sn * t16 * t28;
  Tt[3] = ((t52 * t103 + t73 * t105) - t77_tmp * t92 / 2.0) - b_sn * t91 / 2.0;
  t78_tmp = par_mex.var[16] * t2 * 1.4142135623730951;
  t4 = t78_tmp * t15 * t28;
  t78_tmp = t78_tmp * t16 * t28;
  Tt[4] = ((t52 * t104 + t73 * t106) - t4 * t92 / 2.0) - t78_tmp * t91 / 2.0;
  Tt[5] = ((t52 * t111 - t73 * t113) - t20 * t92 * 2.0) - t51 * t16 * t22 * t29 *
    t91 * 2.0;
  Tt[6] = (((t2 + t73 * t112) + t52 * t114) - t74 * t92 * 2.0) - t5 * t16 * t22 *
    t29 * t91 * 2.0;
  Tt[7] = ((t111_tmp * t39 - t52 * t115) + b_t111_tmp * t92 / 2.0) + step * t91 /
    2.0;
  Tt[8] = ((t111_tmp * t103 + t52 * t105) + t77_tmp * t91 / 2.0) - b_sn * t92 /
    2.0;
  Tt[9] = ((t111_tmp * t104 + t52 * t106) + t4 * t91 / 2.0) - t78_tmp * t92 /
    2.0;
  t52 = t40 * (t6_tmp + 1.0);
  t73 = par_mex.var[16] * t92;
  t20 = par_mex.var[16] * t91;
  Tt[10] = ((t20 * t111 * -2.0 + t73 * t113 * 2.0) - t52 * t17 * t22 * 2.0) -
    t52 * t18 * t22 * 2.0;
  t52 = t3 * (t6_tmp + 1.0);
  Tt[11] = ((t73 * t112 * -2.0 - t20 * t114 * 2.0) - t52 * t17 * t22 * 2.0) -
    t52 * t18 * t22 * 2.0;
  Tt[12] = (((t2 + par_mex.var[16] * t17 * t38 / 2.0) + par_mex.var[16] * t18 *
             t38 / 2.0) + t20 * t115 * 2.0) + t73 * t39 * 2.0;
  Tt[13] = t73 * t103 * 2.0 - t20 * t105 * 2.0;
  Tt[14] = t73 * t104 * 2.0 - t20 * t106 * 2.0;
  t52 = t42 * 2.0 - b_z[0] * 1.4142135623730951 * t16 * t23 * t29;
  t73 = b_z[0] * t2 * 1.4142135623730951 * (t6_tmp + 1.0) * t16 * t22 * t29;
  Tt[15] = ((t34_tmp * t111 + t32_tmp * t113) - t115_tmp * t52) + t73 * t93;
  t20 = b_z[1] * t2 * 1.4142135623730951 * (t6_tmp + 1.0) * t16 * t22 * t29;
  t74 = -1.4142135623730951 * t15 * t28;
  Tt[16] = ((t74 * t112 + t34_tmp * t114) - t116_tmp * t52) + t20 * t93;
  t111_tmp = 1.4142135623730951 * t16 * t29 * t38;
  b_t111_tmp = 1.4142135623730951 * t15 * t29 * t38;
  Tt[17] = ((t32_tmp * t39 - t34_tmp * t115) + b_t111_tmp * t52 / 4.0) -
    t111_tmp * t93 / 4.0;
  step = t39_tmp * t28;
  b_sn = t40_tmp * t28;
  Tt[18] = ((t32_tmp * t103 + t34_tmp * t105) - b_sn * t52 / 4.0) - step * t93 /
    4.0;
  t77_tmp = t2 * 1.4142135623730951 * t15 * t28;
  t78_tmp = t2 * 1.4142135623730951 * t16 * t28;
  Tt[19] = ((t32_tmp * t104 + t34_tmp * t106) - t78_tmp * t52 / 4.0) - t77_tmp *
    t93 / 4.0;
  Tt[20] = ((t32_tmp * t111 - t34_tmp * t113) + t73 * t52) + t115_tmp * t93;
  Tt[21] = ((t34_tmp * t112 + t32_tmp * t114) + t20 * t52) + t116_tmp * t93;
  Tt[22] = ((t74 * t115 - t34_tmp * t39) - t111_tmp * t52 / 4.0) - b_t111_tmp *
    t93 / 4.0;
  t73 = -1.4142135623730951 * t16 * t28;
  Tt[23] = ((t73 * t103 + t32_tmp * t105) - step * t52 / 4.0) + b_sn * t93 / 4.0;
  Tt[24] = ((t73 * t104 + t32_tmp * t106) - t77_tmp * t52 / 4.0) + t78_tmp * t93
    / 4.0;
  Tt[25] = t93 * t113 + t111 * t52;
  Tt[26] = -t93 * t112 + t114 * t52;
  Tt[27] = t93 * t39 - t115 * t52;
  Tt[28] = ((t93 * t103 + t105 * t52) + par_mex.var[4] * t17 * t25_tmp / 2.0) +
    par_mex.var[4] * t18 * t25_tmp / 2.0;
  Tt[29] = ((t93 * t104 + t106 * t52) + t2 * t17 * t25_tmp / 2.0) + t2 * t18 *
    t25_tmp / 2.0;
  vd[0] = par_mex.var[27];
  vd[1] = par_mex.var[28];
  vd[2] = par_mex.var[29];
  step = (-(t32_tmp * par_mex.var[31] / 2.0) + t34_tmp * par_mex.var[30] / 2.0)
    + t92 * par_mex.var[32];
  vd[3] = ((-t91 * t21 - t92 * t110) + t32_tmp * t30 / 2.0) - t34_tmp * step /
    2.0;
  vd[4] = ((t91 * t110 - t92 * t21) - t34_tmp * t30 / 2.0) - t32_tmp * step /
    2.0;
  vd[5] = ((t91 * t30 - t92 * step) + t32_tmp * t21 / 2.0) + t34_tmp * t110 /
    2.0;
  for (i = 0; i < 5; i++) {
    t111_tmp = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      t111_tmp += Tt[i + 5 * i1] * vd[i1];
    }

    res[i] = ((TMfd[i] + w_sd[i]) + w_in[i]) + t111_tmp;
  }
}

/* End of code generation (EOM_eq.c) */
