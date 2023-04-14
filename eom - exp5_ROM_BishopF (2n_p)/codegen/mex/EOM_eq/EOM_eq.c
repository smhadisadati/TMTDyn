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
#include "sprdmpF10.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 9,     /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 24,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 29,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 36,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 41,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 52,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 57,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 67,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 73,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM_eq.m"/* pathName */
};

static emlrtRSInfo ce_emlrtRSI = { 50, /* lineNo */
  "loadsF1",                           /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\loadsF1.m"/* pathName */
};

static emlrtRSInfo ee_emlrtRSI = { 59, /* lineNo */
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
void EOM_eq(const emlrtStack *sp, const real_T z[9], real_T res[9])
{
  static const int8_T iv[6] = { 0, 0, 1, 1, 2, 2 };

  emlrtStack b_st;
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
  real_T b_t115_tmp;
  real_T b_t116_tmp;
  real_T b_t164_tmp;
  real_T step;
  real_T t107;
  real_T t108;
  real_T t115;
  real_T t115_tmp;
  real_T t116;
  real_T t116_tmp;
  real_T t120;
  real_T t121;
  real_T t124;
  real_T t125;
  real_T t138;
  real_T t139;
  real_T t14;
  real_T t140;
  real_T t141;
  real_T t145;
  real_T t149;
  real_T t15;
  real_T t152;
  real_T t153;
  real_T t154;
  real_T t155;
  real_T t16;
  real_T t160;
  real_T t161;
  real_T t162;
  real_T t162_tmp;
  real_T t163;
  real_T t164;
  real_T t164_tmp;
  real_T t165;
  real_T t167;
  real_T t168;
  real_T t17;
  real_T t170;
  real_T t170_tmp;
  real_T t18;
  real_T t2;
  real_T t21;
  real_T t22;
  real_T t23;
  real_T t24;
  real_T t26;
  real_T t28;
  real_T t3;
  real_T t32_tmp;
  real_T t36;
  real_T t38;
  real_T t39;
  real_T t41_tmp;
  real_T t43_tmp;
  real_T t47;
  real_T t48;
  real_T t49;
  real_T t49_tmp;
  real_T t50;
  real_T t50_tmp;
  real_T t51;
  real_T t51_tmp;
  real_T t52;
  real_T t52_tmp;
  real_T t53;
  real_T t53_tmp;
  real_T t54;
  real_T t54_tmp;
  real_T t55;
  real_T t55_tmp;
  real_T t56;
  real_T t56_tmp;
  real_T t94;
  real_T t94_tmp;
  real_T t95;
  real_T t96;
  real_T t97;
  real_T t98;
  real_T t99;
  real_T unnamed_idx_19;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T sn;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  for (i = 0; i < 9; i++) {
    t162_tmp = z[i];
    b_z[i] = t162_tmp;
    b_z[i + 9] = 0.0 * t162_tmp;
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
  /*     15-Jun-2021 02:02:11 */
  t17 = par_mex.var[4];
  unnamed_idx_19 = par_mex.var[4];
  st.site = &b_emlrtRSI;
  massF1(&st, par_mex.var, b_z, 1.0E-6 * t17, M, T, Dd, fg);
  st.site = &c_emlrtRSI;
  sprdmpF10(&st, par_mex.var, b_z, 1.0E-6 * unnamed_idx_19, Tt, kx, vd, in,
            &step);
  for (i = 0; i < 54; i++) {
    Tt[i] *= step;
  }

  st.site = &d_emlrtRSI;
  massF1(&st, par_mex.var, b_z, 0.999999 * t17, b_M, b_T, b_Dd, b_fg);
  st.site = &e_emlrtRSI;
  sprdmpF10(&st, par_mex.var, b_z, 0.999999 * unnamed_idx_19, b_Tt, b_kx, vd,
            b_in, &step);
  for (i = 0; i < 54; i++) {
    b_Tt[i] *= step;
    Dd[i] = -Dd[i];
  }

  for (i = 0; i < 9; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      t162_tmp = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        t162_tmp += T[i2 + 6 * i] * M[i2 + 6 * i1];
      }

      c_T[i + 9 * i1] = t162_tmp;
    }
  }

  for (i = 0; i < 6; i++) {
    t162_tmp = 0.0;
    for (i1 = 0; i1 < 9; i1++) {
      t162_tmp += Dd[i + 6 * i1] * b_z[i1 + 9];
    }

    vd[i] = t162_tmp + fg[i];
  }

  for (i = 0; i < 9; i++) {
    t162_tmp = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      t162_tmp += c_T[i + 9 * i1] * vd[i1];
    }

    TMfd[i] = t162_tmp;
  }

  for (i = 0; i < 54; i++) {
    b_Dd[i] = -b_Dd[i];
  }

  for (i = 0; i < 9; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      t162_tmp = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        t162_tmp += b_T[i2 + 6 * i] * b_M[i2 + 6 * i1];
      }

      c_T[i + 9 * i1] = t162_tmp;
    }
  }

  for (i = 0; i < 6; i++) {
    t162_tmp = 0.0;
    for (i1 = 0; i1 < 9; i1++) {
      t162_tmp += b_Dd[i + 6 * i1] * b_z[i1 + 9];
    }

    vd[i] = t162_tmp + b_fg[i];
  }

  for (i = 0; i < 9; i++) {
    t162_tmp = 0.0;
    step = 0.0;
    b_sn = 0.0;
    t94_tmp = 0.0;
    t56 = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      i2 = i + 9 * i1;
      t162_tmp += c_T[i2] * vd[i1];
      t53 = Tt[i2];
      step += t53 * kx[i1];
      t115_tmp = b_Tt[i2];
      b_sn += t115_tmp * b_kx[i1];
      t94_tmp += t53 * in[i1];
      t56 += t115_tmp * b_in[i1];
    }

    TMfd[i] = (TMfd[i] * t17 + t162_tmp * t17) / 2.0;
    w_sd[i] = (step * par_mex.var[4] + b_sn * par_mex.var[4]) / 2.0;
    w_in[i] = (t94_tmp * par_mex.var[4] + t56 * par_mex.var[4]) / 2.0;
  }

  for (sn = 0; sn < 9; sn++) {
    b_sn = (real_T)sn * 0.1 + 0.100001;
    st.site = &f_emlrtRSI;
    massF1(&st, par_mex.var, b_z, b_sn * t17, M, T, Dd, fg);
    for (i = 0; i < 54; i++) {
      Dd[i] = -Dd[i];
    }

    for (i = 0; i < 9; i++) {
      for (i1 = 0; i1 < 6; i1++) {
        t162_tmp = 0.0;
        for (i2 = 0; i2 < 6; i2++) {
          t162_tmp += T[i2 + 6 * i] * M[i2 + 6 * i1];
        }

        c_T[i + 9 * i1] = t162_tmp;
      }
    }

    for (i = 0; i < 6; i++) {
      t162_tmp = 0.0;
      for (i1 = 0; i1 < 9; i1++) {
        t162_tmp += Dd[i + 6 * i1] * b_z[i1 + 9];
      }

      vd[i] = t162_tmp + fg[i];
    }

    for (i = 0; i < 9; i++) {
      t162_tmp = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        t162_tmp += c_T[i + 9 * i1] * vd[i1];
      }

      TMfd[i] += t162_tmp * t17;
    }

    st.site = &g_emlrtRSI;
    sprdmpF10(&st, par_mex.var, b_z, b_sn * unnamed_idx_19, Tt, kx, vd, in,
              &step);
    for (i = 0; i < 54; i++) {
      Tt[i] *= step;
    }

    for (i = 0; i < 9; i++) {
      t162_tmp = 0.0;
      step = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        b_sn = Tt[i + 9 * i1];
        t162_tmp += b_sn * kx[i1];
        step += b_sn * in[i1];
      }

      w_sd[i] += t162_tmp * par_mex.var[4];
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
      t162_tmp = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        t162_tmp += T[i2 + 6 * i] * M[i2 + 6 * i1];
      }

      c_T[i + 9 * i1] = t162_tmp;
    }
  }

  for (i = 0; i < 6; i++) {
    t162_tmp = 0.0;
    for (i1 = 0; i1 < 9; i1++) {
      t162_tmp += Dd[i + 6 * i1] * b_z[i1 + 9];
    }

    vd[i] = t162_tmp + fg[i];
  }

  for (i = 0; i < 9; i++) {
    t162_tmp = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      t162_tmp += c_T[i + 9 * i1] * vd[i1];
    }

    TMfd[i] += t162_tmp;
  }

  st.site = &i_emlrtRSI;

  /* LOADSF1 */
  /*     [OUT1,OUT2,OUT3] = LOADSF1(IN1,IN2,S,DS,T_SYM) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
  /*     15-Jun-2021 02:09:41 */
  t2 = par_mex.var[4] * par_mex.var[4];
  t3 = muDoubleScalarPower(par_mex.var[4], 3.0);
  t14 = par_mex.var[4] * b_z[0] * 2.0 + b_z[1] * t2 * 3.0;
  t15 = par_mex.var[4] * b_z[2] * 2.0 + b_z[3] * t2 * 3.0;
  t16 = (par_mex.var[4] * b_z[4] * 2.0 + b_z[5] * t2 * 3.0) + 1.0;
  step = (par_mex.var[4] * b_z[6] / 2.0 + b_z[7] * t2 / 2.0) + b_z[8] * t3 / 2.0;
  t17 = t14 * t14;
  t18 = t15 * t15;
  b_sn = t16 * t16;
  t21 = muDoubleScalarCos(step);
  t22 = muDoubleScalarSin(step);
  t23 = t21 * t21;
  t24 = t22 * t22;
  step = (t17 + t18) + b_sn;
  t26 = 1.0 / (step * step);
  b_st.site = &ce_emlrtRSI;
  if (step < 0.0) {
    emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  step = 1.0 / muDoubleScalarSqrt(step);
  t28 = muDoubleScalarPower(step, 3.0);
  t32_tmp = t16 * step + 1.0;
  b_st.site = &ee_emlrtRSI;
  if (t32_tmp < 0.0) {
    emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  t36 = muDoubleScalarSqrt(t32_tmp);
  t38 = 1.0 / t36;
  t41_tmp = 1.4142135623730951 * t21 * t36;
  t43_tmp = 1.4142135623730951 * t22 * t36;
  t47 = par_mex.var[4] * step * 2.0 + -(par_mex.var[4] * b_sn * t28 * 2.0);
  t48 = t2 * step * 3.0 + -(t2 * b_sn * t28 * 3.0);
  t39 = muDoubleScalarPower(t38, 3.0);
  t49_tmp = par_mex.var[4] * 1.4142135623730951 * t21;
  t49 = t49_tmp * step * t38;
  t50_tmp = par_mex.var[4] * 1.4142135623730951 * t22;
  t50 = t50_tmp * step * t38;
  t51_tmp = t2 * 1.4142135623730951 * t21;
  t51 = t51_tmp * step * t38 * 1.5;
  t52_tmp = t2 * 1.4142135623730951 * t22;
  t52 = t52_tmp * step * t38 * 1.5;
  t53_tmp = 1.4142135623730951 * t14 * t21 * step;
  t53 = t53_tmp * t38;
  t54_tmp = 1.4142135623730951 * t15 * t21 * step;
  t54 = t54_tmp * t38;
  t55_tmp = 1.4142135623730951 * t14 * t22 * step;
  t55 = t55_tmp * t38;
  t56_tmp = 1.4142135623730951 * t15 * t22 * step;
  t56 = t56_tmp * t38;
  step = par_mex.var[4] * 1.4142135623730951 * t14;
  t94_tmp = step * t15;
  t94 = t94_tmp * t21 * t28 * t38;
  t95 = t94_tmp * t22 * t28 * t38;
  step *= t16;
  t96 = step * t21 * t28 * t38;
  b_sn = par_mex.var[4] * 1.4142135623730951 * t15 * t16;
  t97 = b_sn * t21 * t28 * t38;
  t98 = step * t22 * t28 * t38;
  t99 = b_sn * t22 * t28 * t38;
  step = t2 * 1.4142135623730951 * t14;
  b_sn = step * t15;
  t107 = b_sn * t21 * t28 * t38 * 1.5;
  t108 = b_sn * t22 * t28 * t38 * 1.5;
  t115_tmp = step * t16;
  b_t115_tmp = t115_tmp * t22 * t28 * t38;
  t115 = b_t115_tmp * 1.5;
  t116_tmp = t2 * 1.4142135623730951 * t15 * t16;
  b_t116_tmp = t116_tmp * t22 * t28 * t38;
  t116 = b_t116_tmp * 1.5;
  step = t94_tmp * t16;
  t120 = step * t21 * t26 * t39 / 2.0;
  t121 = step * t22 * t26 * t39 / 2.0;
  step = b_sn * t16;
  t124 = step * t21 * t26 * t39 * 0.75;
  t125 = step * t22 * t26 * t39 * 0.75;
  t138 = t53 + t56;
  t139 = t54 + -t55;
  t140 = t53 / 2.0 + t56 / 2.0;
  t145 = t15 * t50 / 4.0 + t14 * t49 / 4.0;
  t152 = t2 * t53 / 4.0 + t2 * t56 / 4.0;
  t153 = t3 * t53 / 4.0 + t3 * t56 / 4.0;
  step = par_mex.var[4] * 1.4142135623730951 * t16;
  t53 = par_mex.var[4] * 1.4142135623730951 * t17;
  t162_tmp = step * t17;
  t162 = (((t49 + -(t53 * t21 * t28 * t38)) + -t95) + t162_tmp * t21 * t26 * t39
          / 2.0) + t121;
  t94_tmp = par_mex.var[4] * 1.4142135623730951 * t18;
  unnamed_idx_19 = step * t18;
  t163 = (((t50 + -(t94_tmp * t22 * t28 * t38)) + -t94) + unnamed_idx_19 * t22 *
          t26 * t39 / 2.0) + t120;
  step = t2 * 1.4142135623730951 * t16;
  t164_tmp = t2 * 1.4142135623730951 * t17;
  b_t164_tmp = step * t17;
  t164 = (((t51 + -(t164_tmp * t21 * t28 * t38 * 1.5)) + -t108) + b_t164_tmp *
          t21 * t26 * t39 * 0.75) + t125;
  t56 = t2 * 1.4142135623730951 * t18;
  t17 = step * t18;
  t167 = (((t52 + -(t56 * t22 * t28 * t38 * 1.5)) + t17 * t22 * t26 * t39 * 0.75)
          + -t107) + t124;
  b_sn = t53_tmp * t39;
  step = t56_tmp * t39;
  t168 = ((t96 + t99) + b_sn * t47 / 4.0) + step * t47 / 4.0;
  t170_tmp = t115_tmp * t21 * t28 * t38;
  t170 = ((t170_tmp * 1.5 + t116) + b_sn * t48 / 4.0) + step * t48 / 4.0;
  t141 = t54 / 2.0 + -(t55 / 2.0);
  t149 = t14 * t50 / 4.0 + -(t15 * t49 / 4.0);
  t154 = t2 * t54 / 4.0 + -(t2 * t55 / 4.0);
  t155 = t3 * t54 / 4.0 + -(t3 * t55 / 4.0);
  t160 = (((t49 + -(t94_tmp * t21 * t28 * t38)) + t95) + unnamed_idx_19 * t21 *
          t26 * t39 / 2.0) + -t121;
  t161 = (((t50 + -(t53 * t22 * t28 * t38)) + t94) + t162_tmp * t22 * t26 * t39 /
          2.0) + -t120;
  t165 = (((t51 + -(t56 * t21 * t28 * t38 * 1.5)) + t108) + t17 * t21 * t26 *
          t39 * 0.75) + -t125;
  t51 = (((t52 + -(t164_tmp * t22 * t28 * t38 * 1.5)) + t107) + b_t164_tmp * t22
         * t26 * t39 * 0.75) + -t124;
  b_sn = t54_tmp * t39;
  step = t55_tmp * t39;
  t50 = ((t97 + -t98) + b_sn * t47 / 4.0) + -(step * t47 / 4.0);
  t94 = t116_tmp * t21 * t28 * t38;
  t18 = ((t94 * 1.5 + -t115) + b_sn * t48 / 4.0) + -(step * t48 / 4.0);
  t95 = (t41_tmp * par_mex.var[30] / 2.0 + t43_tmp * par_mex.var[31] / 2.0) +
    -(t140 * par_mex.var[32]);
  t107 = (t41_tmp * par_mex.var[32] / 2.0 + t140 * par_mex.var[30]) + t141 *
    par_mex.var[31];
  t49 = (t43_tmp * par_mex.var[32] / 2.0 + t140 * par_mex.var[31]) + -(t141 *
    par_mex.var[30]);

  /*  EOM */
  t121 = par_mex.var[16] * 1.4142135623730951 * t21;
  t125 = t121 * t36;
  step = par_mex.var[16] * 1.4142135623730951 * t22;
  t120 = step * t36;
  Tt[0] = (((t2 - par_mex.var[16] * t96 * t140) + par_mex.var[16] * t98 * t141)
           + t125 * t162) + t120 * t161;
  t124 = par_mex.var[16] * t2;
  t108 = t124 * 1.4142135623730951;
  t54 = t108 * t14 * t16;
  t55 = t54 * t21 * t28 * t38;
  Tt[1] = (((t3 + par_mex.var[16] * t115 * t141) + t125 * t164) + t120 * t51) -
    t55 * t140 * 1.5;
  t53_tmp = par_mex.var[16] * t99;
  Tt[2] = ((-par_mex.var[16] * t97 * t140 + t53_tmp * t141) - t120 * t160) +
    t125 * t163;
  t56_tmp = t108 * t15 * t16;
  t164_tmp = t56_tmp * t21 * t28 * t38;
  Tt[3] = ((par_mex.var[16] * t116 * t141 - t120 * t165) + t125 * t167) -
    t164_tmp * t140 * 1.5;
  t53 = -par_mex.var[16] * 1.4142135623730951 * t21 * t36;
  b_t164_tmp = t121 * t38;
  step *= t38;
  b_sn = b_t164_tmp * t47;
  t115_tmp = step * t47;
  Tt[4] = ((t53 * t168 + t120 * t50) + b_sn * t140 / 2.0) - t115_tmp * t141 /
    2.0;
  b_t164_tmp *= t48;
  step *= t48;
  Tt[5] = ((t53 * t170 + t120 * t18) + b_t164_tmp * t140 / 2.0) - step * t141 /
    2.0;
  t121 = par_mex.var[16] * par_mex.var[4];
  t162_tmp = t121 * 1.4142135623730951;
  t17 = t162_tmp * t21 * t36;
  t162_tmp = t162_tmp * t22 * t36;
  Tt[6] = ((t120 * t145 - t125 * t149) - t17 * t141 / 2.0) - t162_tmp * t140 /
    2.0;
  unnamed_idx_19 = t108 * t21 * t36;
  t108 = t108 * t22 * t36;
  Tt[7] = ((t120 * t152 + t125 * t154) - unnamed_idx_19 * t141 / 2.0) - t108 *
    t140 / 2.0;
  t94_tmp = par_mex.var[16] * t3 * 1.4142135623730951;
  t56 = t94_tmp * t21 * t36;
  t94_tmp = t94_tmp * t22 * t36;
  Tt[8] = ((t120 * t153 + t125 * t155) - t56 * t141 / 2.0) - t94_tmp * t140 /
    2.0;
  Tt[9] = ((-par_mex.var[16] * t96 * t141 + par_mex.var[16] * -t98 * t140) -
           t125 * t161) + t120 * t162;
  Tt[10] = ((t120 * t164 - t125 * t51) - t55 * t141 * 1.5) - t54 * t22 * t28 *
    t38 * t140 * 1.5;
  Tt[11] = (((t2 - par_mex.var[16] * t97 * t141) - t53_tmp * t140) + t125 * t160)
    + t120 * t163;
  Tt[12] = (((t3 + t125 * t165) + t120 * t167) - t164_tmp * t141 * 1.5) -
    t56_tmp * t22 * t28 * t38 * t140 * 1.5;
  Tt[13] = ((t53 * t50 - t120 * t168) + b_sn * t141 / 2.0) + t115_tmp * t140 /
    2.0;
  Tt[14] = ((t53 * t18 - t120 * t170) + b_t164_tmp * t141 / 2.0) + step * t140 /
    2.0;
  Tt[15] = ((t53 * t145 - t120 * t149) + t17 * t140 / 2.0) - t162_tmp * t141 /
    2.0;
  Tt[16] = ((t53 * t152 + t120 * t154) + unnamed_idx_19 * t140 / 2.0) - t108 *
    t141 / 2.0;
  Tt[17] = ((t53 * t153 + t120 * t155) + t56 * t140 / 2.0) - t94_tmp * t141 /
    2.0;
  t125 = t121 * t14 * t16;
  t120 = par_mex.var[16] * t140;
  t108 = par_mex.var[16] * t141;
  Tt[18] = ((t120 * t162 * -2.0 + t108 * t161 * 2.0) - t125 * t23 * t28) - t125 *
    t24 * t28;
  t125 = t124 * t14 * t16;
  Tt[19] = ((t120 * t164 * -2.0 + t108 * t51 * 2.0) - t125 * t23 * t28 * 1.5) -
    t125 * t24 * t28 * 1.5;
  t125 = t121 * t15 * t16;
  Tt[20] = ((t108 * t160 * -2.0 - t120 * t163 * 2.0) - t125 * t23 * t28) - t125 *
    t24 * t28;
  t125 = t124 * t15 * t16;
  Tt[21] = ((t108 * t165 * -2.0 - t120 * t167 * 2.0) - t125 * t23 * t28 * 1.5) -
    t125 * t24 * t28 * 1.5;
  t125 = par_mex.var[16] * t23;
  t55 = par_mex.var[16] * t24;
  Tt[22] = (((t2 + t125 * t47 / 2.0) + t55 * t47 / 2.0) + t120 * t168 * 2.0) +
    t108 * t50 * 2.0;
  Tt[23] = (((t3 + t125 * t48 / 2.0) + t55 * t48 / 2.0) + t120 * t170 * 2.0) +
    t108 * t18 * 2.0;
  Tt[24] = t108 * t145 * 2.0 + t120 * t149 * 2.0;
  Tt[25] = t108 * t152 * 2.0 - t120 * t154 * 2.0;
  Tt[26] = t108 * t153 * 2.0 - t120 * t155 * 2.0;
  Tt[27] = ((t96 * t139 * -0.5 + t98 * t138 / 2.0) + t41_tmp * t161) + t43_tmp *
    t162;
  Tt[28] = ((t43_tmp * t164 + t41_tmp * t51) - t170_tmp * t139 * 0.75) +
    b_t115_tmp * t138 * 0.75;
  Tt[29] = ((t97 * t139 * -0.5 + t99 * t138 / 2.0) - t41_tmp * t160) + t43_tmp *
    t163;
  t125 = -1.4142135623730951 * t21 * t36;
  Tt[30] = ((t125 * t165 + t43_tmp * t167) - t94 * t139 * 0.75) + b_t116_tmp *
    t138 * 0.75;
  t120 = 1.4142135623730951 * t21 * t38;
  t108 = 1.4142135623730951 * t22 * t38;
  t55 = t120 * t47;
  t53_tmp = t108 * t47;
  Tt[31] = ((t41_tmp * t50 - t43_tmp * t168) + t55 * t139 / 4.0) - t53_tmp *
    t138 / 4.0;
  t120 *= t48;
  t108 *= t48;
  Tt[32] = ((t41_tmp * t18 - t43_tmp * t170) + t120 * t139 / 4.0) - t108 * t138 /
    4.0;
  t164_tmp = t49_tmp * t36;
  t53 = t50_tmp * t36;
  Tt[33] = ((t41_tmp * t145 - t43_tmp * t149) - t164_tmp * t138 / 4.0) - t53 *
    t139 / 4.0;
  b_t164_tmp = t51_tmp * t36;
  step = t52_tmp * t36;
  Tt[34] = ((t41_tmp * t152 + t43_tmp * t154) - b_t164_tmp * t138 / 4.0) - step *
    t139 / 4.0;
  b_sn = t3 * 1.4142135623730951 * t21 * t36;
  t115_tmp = t3 * 1.4142135623730951 * t22 * t36;
  Tt[35] = ((t41_tmp * t153 + t43_tmp * t155) - b_sn * t138 / 4.0) - t115_tmp *
    t139 / 4.0;
  Tt[36] = ((t96 * t138 / 2.0 + t98 * t139 / 2.0) + t41_tmp * t162) - t43_tmp *
    t161;
  Tt[37] = ((t41_tmp * t164 - t43_tmp * t51) + t170_tmp * t138 * 0.75) +
    b_t115_tmp * t139 * 0.75;
  Tt[38] = ((t97 * t138 / 2.0 + t99 * t139 / 2.0) + t43_tmp * t160) + t41_tmp *
    t163;
  Tt[39] = ((t43_tmp * t165 + t41_tmp * t167) + t94 * t138 * 0.75) + b_t116_tmp *
    t139 * 0.75;
  Tt[40] = ((t125 * t168 - t43_tmp * t50) - t55 * t138 / 4.0) - t53_tmp * t139 /
    4.0;
  Tt[41] = ((t125 * t170 - t43_tmp * t18) - t120 * t138 / 4.0) - t108 * t139 /
    4.0;
  t125 = -1.4142135623730951 * t22 * t36;
  Tt[42] = ((t125 * t145 - t41_tmp * t149) - t164_tmp * t139 / 4.0) + t53 * t138
    / 4.0;
  Tt[43] = ((t125 * t152 + t41_tmp * t154) - b_t164_tmp * t139 / 4.0) + step *
    t138 / 4.0;
  Tt[44] = ((t125 * t153 + t41_tmp * t155) - b_sn * t139 / 4.0) + t115_tmp *
    t138 / 4.0;
  Tt[45] = t138 * t161 + t139 * t162;
  Tt[46] = t139 * t164 + t138 * t51;
  Tt[47] = -t138 * t160 + t139 * t163;
  Tt[48] = -t138 * t165 + t139 * t167;
  Tt[49] = t138 * t50 - t139 * t168;
  Tt[50] = t138 * t18 - t139 * t170;
  Tt[51] = ((t138 * t145 - t139 * t149) + par_mex.var[4] * t23 * t32_tmp / 2.0)
    + par_mex.var[4] * t24 * t32_tmp / 2.0;
  Tt[52] = ((t138 * t152 + t139 * t154) + t2 * t23 * t32_tmp / 2.0) + t2 * t24 *
    t32_tmp / 2.0;
  Tt[53] = ((t138 * t153 + t139 * t155) + t3 * t23 * t32_tmp / 2.0) + t3 * t24 *
    t32_tmp / 2.0;
  vd[0] = par_mex.var[27];
  vd[1] = par_mex.var[28];
  vd[2] = par_mex.var[29];
  step = (-(t41_tmp * par_mex.var[31] / 2.0) + t43_tmp * par_mex.var[30] / 2.0)
    + t141 * par_mex.var[32];
  vd[3] = ((-t140 * t107 - t141 * t49) + t41_tmp * t95 / 2.0) - t43_tmp * step /
    2.0;
  vd[4] = ((t140 * t49 - t141 * t107) - t43_tmp * t95 / 2.0) - t41_tmp * step /
    2.0;
  vd[5] = ((t140 * t95 - t141 * step) + t41_tmp * t107 / 2.0) + t43_tmp * t49 /
    2.0;
  for (i = 0; i < 9; i++) {
    t162_tmp = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      t162_tmp += Tt[i + 9 * i1] * vd[i1];
    }

    res[i] = ((TMfd[i] + w_sd[i]) + w_in[i]) + t162_tmp;
  }
}

/* End of code generation (EOM_eq.c) */
