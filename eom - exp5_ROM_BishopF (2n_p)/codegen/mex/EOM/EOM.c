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
#include "pinv.h"
#include "rt_nonfinite.h"
#include "sprdmpF10.h"
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

static emlrtRSInfo c_emlrtRSI = { 27,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 34,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 39,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 50,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 55,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 65,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 71,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 81,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo de_emlrtRSI = { 50, /* lineNo */
  "loadsF1",                           /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\v5_Latest_Version_Examples\\eom\\loadsF1.m"/* pathName */
};

static emlrtRSInfo fe_emlrtRSI = { 59, /* lineNo */
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
void EOM(const emlrtStack *sp, real_T t, const real_T z[18], const struct0_T
         *par_mex, real_T dz[18], real_T *flag)
{
  static const int8_T iv[6] = { 0, 0, 1, 1, 2, 2 };

  emlrtStack b_st;
  emlrtStack st;
  real_T TMT[81];
  real_T b_TMT_tmp[81];
  real_T Dd[54];
  real_T T[54];
  real_T TMT_tmp[54];
  real_T Tt[54];
  real_T b_Dd[54];
  real_T b_T[54];
  real_T b_Tt[54];
  real_T c_TMT_tmp[54];
  real_T M[36];
  real_T par_mex_var[34];
  real_T TMfd[9];
  real_T b_TMfd[9];
  real_T w_in[9];
  real_T w_sd[9];
  real_T w_vd_j[9];
  real_T b_fg[6];
  real_T b_in[6];
  real_T b_kx[6];
  real_T b_vd[6];
  real_T c_Dd[6];
  real_T fg[6];
  real_T in[6];
  real_T kx[6];
  real_T vd[6];
  real_T b_t115_tmp;
  real_T b_t116_tmp;
  real_T b_t162_tmp;
  real_T b_t164_tmp;
  real_T sn;
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
  int32_T TMT_tmp_tmp;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
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
  /*     15-Jun-2021 02:02:11 */
  t17 = par_mex_var[4];
  st.site = &b_emlrtRSI;
  massF1(&st, par_mex_var, z, 1.0E-6 * par_mex_var[4], M, T, Dd, fg);
  for (i = 0; i < 9; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      t164_tmp = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        t164_tmp += T[i2 + 6 * i] * M[i2 + 6 * i1];
      }

      TMT_tmp[i + 9 * i1] = t164_tmp;
    }
  }

  st.site = &c_emlrtRSI;
  sprdmpF10(&st, par_mex_var, z, 1.0E-6 * par_mex_var[4], Tt, kx, vd, in, &step);
  st.site = &d_emlrtRSI;
  massF1(&st, par_mex_var, z, 0.999999 * par_mex_var[4], M, b_T, b_Dd, b_fg);
  for (i = 0; i < 9; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      t164_tmp = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        t164_tmp += b_T[i2 + 6 * i] * M[i2 + 6 * i1];
      }

      c_TMT_tmp[i + 9 * i1] = t164_tmp;
    }
  }

  st.site = &e_emlrtRSI;
  sprdmpF10(&st, par_mex_var, z, 0.999999 * par_mex_var[4], b_Tt, b_kx, b_vd,
            b_in, &step);
  for (i = 0; i < 9; i++) {
    for (i1 = 0; i1 < 9; i1++) {
      t164_tmp = 0.0;
      step = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        TMT_tmp_tmp = i + 9 * i2;
        i3 = i2 + 6 * i1;
        t164_tmp += TMT_tmp[TMT_tmp_tmp] * T[i3];
        step += c_TMT_tmp[TMT_tmp_tmp] * b_T[i3];
      }

      TMT_tmp_tmp = i + 9 * i1;
      b_TMT_tmp[TMT_tmp_tmp] = step;
      TMT[TMT_tmp_tmp] = t164_tmp;
    }
  }

  for (i = 0; i < 81; i++) {
    TMT[i] = (TMT[i] * t17 + b_TMT_tmp[i] * t17) / 2.0;
  }

  for (i = 0; i < 54; i++) {
    Dd[i] = -Dd[i];
  }

  for (i = 0; i < 6; i++) {
    t164_tmp = 0.0;
    for (i1 = 0; i1 < 9; i1++) {
      t164_tmp += Dd[i + 6 * i1] * z[i1 + 9];
    }

    c_Dd[i] = t164_tmp + fg[i];
  }

  for (i = 0; i < 9; i++) {
    t164_tmp = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      t164_tmp += TMT_tmp[i + 9 * i1] * c_Dd[i1];
    }

    TMfd[i] = t164_tmp;
  }

  for (i = 0; i < 54; i++) {
    b_Dd[i] = -b_Dd[i];
  }

  for (i = 0; i < 6; i++) {
    t164_tmp = 0.0;
    for (i1 = 0; i1 < 9; i1++) {
      t164_tmp += b_Dd[i + 6 * i1] * z[i1 + 9];
    }

    c_Dd[i] = t164_tmp + b_fg[i];
  }

  for (i = 0; i < 9; i++) {
    t164_tmp = 0.0;
    step = 0.0;
    sn = 0.0;
    t94_tmp = 0.0;
    t56 = 0.0;
    t53 = 0.0;
    t115_tmp = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      i2 = i + 9 * i1;
      t164_tmp += c_TMT_tmp[i2] * c_Dd[i1];
      t162_tmp = Tt[i2];
      step += t162_tmp * vd[i1];
      b_t162_tmp = b_Tt[i2];
      sn += b_t162_tmp * b_vd[i1];
      t94_tmp += t162_tmp * kx[i1];
      t56 += b_t162_tmp * b_kx[i1];
      t53 += t162_tmp * in[i1];
      t115_tmp += b_t162_tmp * b_in[i1];
    }

    TMfd[i] = (TMfd[i] * t17 + t164_tmp * t17) / 2.0;
    w_vd_j[i] = (step * par_mex_var[4] + sn * par_mex_var[4]) / 2.0;
    w_sd[i] = (t94_tmp * par_mex_var[4] + t56 * par_mex_var[4]) / 2.0;
    w_in[i] = (t53 * par_mex_var[4] + t115_tmp * par_mex_var[4]) / 2.0;
  }

  for (TMT_tmp_tmp = 0; TMT_tmp_tmp < 9; TMT_tmp_tmp++) {
    sn = (real_T)TMT_tmp_tmp * 0.1 + 0.100001;
    st.site = &f_emlrtRSI;
    massF1(&st, par_mex_var, z, sn * t17, M, T, Dd, fg);
    for (i = 0; i < 9; i++) {
      for (i1 = 0; i1 < 6; i1++) {
        t164_tmp = 0.0;
        for (i2 = 0; i2 < 6; i2++) {
          t164_tmp += T[i2 + 6 * i] * M[i2 + 6 * i1];
        }

        TMT_tmp[i + 9 * i1] = t164_tmp;
      }

      for (i1 = 0; i1 < 9; i1++) {
        t164_tmp = 0.0;
        for (i2 = 0; i2 < 6; i2++) {
          t164_tmp += TMT_tmp[i + 9 * i2] * T[i2 + 6 * i1];
        }

        b_TMT_tmp[i + 9 * i1] = t164_tmp;
      }
    }

    for (i = 0; i < 81; i++) {
      TMT[i] += b_TMT_tmp[i] * t17;
    }

    for (i = 0; i < 54; i++) {
      Dd[i] = -Dd[i];
    }

    for (i = 0; i < 6; i++) {
      t164_tmp = 0.0;
      for (i1 = 0; i1 < 9; i1++) {
        t164_tmp += Dd[i + 6 * i1] * z[i1 + 9];
      }

      c_Dd[i] = t164_tmp + fg[i];
    }

    for (i = 0; i < 9; i++) {
      t164_tmp = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        t164_tmp += TMT_tmp[i + 9 * i1] * c_Dd[i1];
      }

      TMfd[i] += t164_tmp * t17;
    }

    st.site = &g_emlrtRSI;
    sprdmpF10(&st, par_mex_var, z, sn * par_mex_var[4], Tt, kx, vd, in, &step);
    for (i = 0; i < 9; i++) {
      t164_tmp = 0.0;
      step = 0.0;
      sn = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        t94_tmp = Tt[i + 9 * i1];
        t164_tmp += t94_tmp * vd[i1];
        step += t94_tmp * kx[i1];
        sn += t94_tmp * in[i1];
      }

      w_vd_j[i] += t164_tmp * par_mex_var[4];
      w_sd[i] += step * par_mex_var[4];
      w_in[i] += sn * par_mex_var[4];
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  for (i = 0; i < 81; i++) {
    TMT[i] /= 10.0;
  }

  for (i = 0; i < 9; i++) {
    TMfd[i] /= 10.0;
    w_vd_j[i] /= 10.0;
    w_sd[i] /= 10.0;
    w_in[i] /= 10.0;
  }

  st.site = &h_emlrtRSI;
  massF2(&st, par_mex_var, z, M, T, Dd, fg);
  for (i = 0; i < 9; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      t164_tmp = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        t164_tmp += T[i2 + 6 * i] * M[i2 + 6 * i1];
      }

      TMT_tmp[i + 9 * i1] = t164_tmp;
    }
  }

  for (i = 0; i < 54; i++) {
    Dd[i] = -Dd[i];
  }

  for (i = 0; i < 6; i++) {
    t164_tmp = 0.0;
    for (i1 = 0; i1 < 9; i1++) {
      t164_tmp += Dd[i + 6 * i1] * z[i1 + 9];
    }

    c_Dd[i] = t164_tmp + fg[i];
  }

  for (i = 0; i < 9; i++) {
    t164_tmp = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      t164_tmp += TMT_tmp[i + 9 * i1] * c_Dd[i1];
    }

    TMfd[i] += t164_tmp;
  }

  st.site = &i_emlrtRSI;

  /* LOADSF1 */
  /*     [OUT1,OUT2,OUT3] = LOADSF1(IN1,IN2,S,DS,T_SYM) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
  /*     15-Jun-2021 02:09:41 */
  t2 = par_mex_var[4] * par_mex_var[4];
  t3 = muDoubleScalarPower(par_mex_var[4], 3.0);
  t14 = par_mex_var[4] * z[0] * 2.0 + z[1] * t2 * 3.0;
  t15 = par_mex_var[4] * z[2] * 2.0 + z[3] * t2 * 3.0;
  t16 = (par_mex_var[4] * z[4] * 2.0 + z[5] * t2 * 3.0) + 1.0;
  step = (par_mex_var[4] * z[6] / 2.0 + z[7] * t2 / 2.0) + z[8] * t3 / 2.0;
  t17 = t14 * t14;
  t18 = t15 * t15;
  sn = t16 * t16;
  t21 = muDoubleScalarCos(step);
  t22 = muDoubleScalarSin(step);
  t23 = t21 * t21;
  t24 = t22 * t22;
  step = (t17 + t18) + sn;
  t26 = 1.0 / (step * step);
  b_st.site = &de_emlrtRSI;
  if (step < 0.0) {
    emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  step = 1.0 / muDoubleScalarSqrt(step);
  t28 = muDoubleScalarPower(step, 3.0);
  t32_tmp = t16 * step + 1.0;
  b_st.site = &fe_emlrtRSI;
  if (t32_tmp < 0.0) {
    emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  t36 = muDoubleScalarSqrt(t32_tmp);
  t38 = 1.0 / t36;
  t41_tmp = 1.4142135623730951 * t21 * t36;
  t43_tmp = 1.4142135623730951 * t22 * t36;
  t47 = par_mex_var[4] * step * 2.0 + -(par_mex_var[4] * sn * t28 * 2.0);
  t48 = t2 * step * 3.0 + -(t2 * sn * t28 * 3.0);
  t39 = muDoubleScalarPower(t38, 3.0);
  t49_tmp = par_mex_var[4] * 1.4142135623730951 * t21;
  t49 = t49_tmp * step * t38;
  t50_tmp = par_mex_var[4] * 1.4142135623730951 * t22;
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
  step = par_mex_var[4] * 1.4142135623730951 * t14;
  t94_tmp = step * t15;
  t94 = t94_tmp * t21 * t28 * t38;
  t95 = t94_tmp * t22 * t28 * t38;
  step *= t16;
  t96 = step * t21 * t28 * t38;
  sn = par_mex_var[4] * 1.4142135623730951 * t15 * t16;
  t97 = sn * t21 * t28 * t38;
  t98 = step * t22 * t28 * t38;
  t99 = sn * t22 * t28 * t38;
  step = t2 * 1.4142135623730951 * t14;
  sn = step * t15;
  t107 = sn * t21 * t28 * t38 * 1.5;
  t108 = sn * t22 * t28 * t38 * 1.5;
  t115_tmp = step * t16;
  b_t115_tmp = t115_tmp * t22 * t28 * t38;
  t115 = b_t115_tmp * 1.5;
  t116_tmp = t2 * 1.4142135623730951 * t15 * t16;
  b_t116_tmp = t116_tmp * t22 * t28 * t38;
  t116 = b_t116_tmp * 1.5;
  step = t94_tmp * t16;
  t120 = step * t21 * t26 * t39 / 2.0;
  t121 = step * t22 * t26 * t39 / 2.0;
  step = sn * t16;
  t124 = step * t21 * t26 * t39 * 0.75;
  t125 = step * t22 * t26 * t39 * 0.75;
  t138 = t53 + t56;
  t139 = t54 + -t55;
  t140 = t53 / 2.0 + t56 / 2.0;
  t145 = t15 * t50 / 4.0 + t14 * t49 / 4.0;
  t152 = t2 * t53 / 4.0 + t2 * t56 / 4.0;
  t153 = t3 * t53 / 4.0 + t3 * t56 / 4.0;
  step = par_mex_var[4] * 1.4142135623730951 * t16;
  t162_tmp = par_mex_var[4] * 1.4142135623730951 * t17;
  b_t162_tmp = step * t17;
  t162 = (((t49 + -(t162_tmp * t21 * t28 * t38)) + -t95) + b_t162_tmp * t21 *
          t26 * t39 / 2.0) + t121;
  t56 = par_mex_var[4] * 1.4142135623730951 * t18;
  t94_tmp = step * t18;
  t163 = (((t50 + -(t56 * t22 * t28 * t38)) + -t94) + t94_tmp * t22 * t26 * t39 /
          2.0) + t120;
  step = t2 * 1.4142135623730951 * t16;
  b_t164_tmp = t2 * 1.4142135623730951 * t17;
  t164_tmp = step * t17;
  t164 = (((t51 + -(b_t164_tmp * t21 * t28 * t38 * 1.5)) + -t108) + t164_tmp *
          t21 * t26 * t39 * 0.75) + t125;
  t53 = t2 * 1.4142135623730951 * t18;
  t17 = step * t18;
  t167 = (((t52 + -(t53 * t22 * t28 * t38 * 1.5)) + t17 * t22 * t26 * t39 * 0.75)
          + -t107) + t124;
  sn = t53_tmp * t39;
  step = t56_tmp * t39;
  t168 = ((t96 + t99) + sn * t47 / 4.0) + step * t47 / 4.0;
  t170_tmp = t115_tmp * t21 * t28 * t38;
  t170 = ((t170_tmp * 1.5 + t116) + sn * t48 / 4.0) + step * t48 / 4.0;
  t141 = t54 / 2.0 + -(t55 / 2.0);
  t149 = t14 * t50 / 4.0 + -(t15 * t49 / 4.0);
  t154 = t2 * t54 / 4.0 + -(t2 * t55 / 4.0);
  t155 = t3 * t54 / 4.0 + -(t3 * t55 / 4.0);
  t160 = (((t49 + -(t56 * t21 * t28 * t38)) + t95) + t94_tmp * t21 * t26 * t39 /
          2.0) + -t121;
  t161 = (((t50 + -(t162_tmp * t22 * t28 * t38)) + t94) + b_t162_tmp * t22 * t26
          * t39 / 2.0) + -t120;
  t165 = (((t51 + -(t53 * t21 * t28 * t38 * 1.5)) + t108) + t17 * t21 * t26 *
          t39 * 0.75) + -t125;
  t51 = (((t52 + -(b_t164_tmp * t22 * t28 * t38 * 1.5)) + t107) + t164_tmp * t22
         * t26 * t39 * 0.75) + -t124;
  sn = t54_tmp * t39;
  step = t55_tmp * t39;
  t50 = ((t97 + -t98) + sn * t47 / 4.0) + -(step * t47 / 4.0);
  t94 = t116_tmp * t21 * t28 * t38;
  t55 = ((t94 * 1.5 + -t115) + sn * t48 / 4.0) + -(step * t48 / 4.0);
  t95 = (t41_tmp * par_mex_var[30] / 2.0 + t43_tmp * par_mex_var[31] / 2.0) +
    -(t140 * par_mex_var[32]);
  t107 = (t41_tmp * par_mex_var[32] / 2.0 + t140 * par_mex_var[30]) + t141 *
    par_mex_var[31];
  t49 = (t43_tmp * par_mex_var[32] / 2.0 + t140 * par_mex_var[31]) + -(t141 *
    par_mex_var[30]);

  /*  EOM */
  for (i = 0; i < 9; i++) {
    for (i1 = 0; i1 < 9; i1++) {
      t164_tmp = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        t164_tmp += TMT_tmp[i + 9 * i2] * T[i2 + 6 * i1];
      }

      TMT_tmp_tmp = i + 9 * i1;
      b_TMT_tmp[TMT_tmp_tmp] = TMT[TMT_tmp_tmp] + t164_tmp;
    }
  }

  st.site = &j_emlrtRSI;
  pinv(&st, b_TMT_tmp, TMT);
  t18 = par_mex_var[16] * 1.4142135623730951 * t21;
  t121 = t18 * t36;
  step = par_mex_var[16] * 1.4142135623730951 * t22;
  t125 = step * t36;
  TMT_tmp[0] = (((t2 - par_mex_var[16] * t96 * t140) + par_mex_var[16] * t98 *
                 t141) + t121 * t162) + t125 * t161;
  t120 = par_mex_var[16] * t2;
  t124 = t120 * 1.4142135623730951;
  t108 = t124 * t14 * t16;
  t54 = t108 * t21 * t28 * t38;
  TMT_tmp[1] = (((t3 + par_mex_var[16] * t115 * t141) + t121 * t164) + t125 *
                t51) - t54 * t140 * 1.5;
  t53_tmp = par_mex_var[16] * t99;
  TMT_tmp[2] = ((-par_mex_var[16] * t97 * t140 + t53_tmp * t141) - t125 * t160)
    + t121 * t163;
  t56_tmp = t124 * t15 * t16;
  b_t164_tmp = t56_tmp * t21 * t28 * t38;
  TMT_tmp[3] = ((par_mex_var[16] * t116 * t141 - t125 * t165) + t121 * t167) -
    b_t164_tmp * t140 * 1.5;
  t56 = -par_mex_var[16] * 1.4142135623730951 * t21 * t36;
  t53 = t18 * t38;
  step *= t38;
  sn = t53 * t47;
  t115_tmp = step * t47;
  TMT_tmp[4] = ((t56 * t168 + t125 * t50) + sn * t140 / 2.0) - t115_tmp * t141 /
    2.0;
  t53 *= t48;
  step *= t48;
  TMT_tmp[5] = ((t56 * t170 + t125 * t55) + t53 * t140 / 2.0) - step * t141 /
    2.0;
  t18 = par_mex_var[16] * par_mex_var[4];
  t162_tmp = t18 * 1.4142135623730951;
  b_t162_tmp = t162_tmp * t21 * t36;
  t162_tmp = t162_tmp * t22 * t36;
  TMT_tmp[6] = ((t125 * t145 - t121 * t149) - b_t162_tmp * t141 / 2.0) -
    t162_tmp * t140 / 2.0;
  t17 = t124 * t21 * t36;
  t124 = t124 * t22 * t36;
  TMT_tmp[7] = ((t125 * t152 + t121 * t154) - t17 * t141 / 2.0) - t124 * t140 /
    2.0;
  t94_tmp = par_mex_var[16] * t3 * 1.4142135623730951;
  t164_tmp = t94_tmp * t21 * t36;
  t94_tmp = t94_tmp * t22 * t36;
  TMT_tmp[8] = ((t125 * t153 + t121 * t155) - t164_tmp * t141 / 2.0) - t94_tmp *
    t140 / 2.0;
  TMT_tmp[9] = ((-par_mex_var[16] * t96 * t141 + par_mex_var[16] * -t98 * t140)
                - t121 * t161) + t125 * t162;
  TMT_tmp[10] = ((t125 * t164 - t121 * t51) - t54 * t141 * 1.5) - t108 * t22 *
    t28 * t38 * t140 * 1.5;
  TMT_tmp[11] = (((t2 - par_mex_var[16] * t97 * t141) - t53_tmp * t140) + t121 *
                 t160) + t125 * t163;
  TMT_tmp[12] = (((t3 + t121 * t165) + t125 * t167) - b_t164_tmp * t141 * 1.5) -
    t56_tmp * t22 * t28 * t38 * t140 * 1.5;
  TMT_tmp[13] = ((t56 * t50 - t125 * t168) + sn * t141 / 2.0) + t115_tmp * t140 /
    2.0;
  TMT_tmp[14] = ((t56 * t55 - t125 * t170) + t53 * t141 / 2.0) + step * t140 /
    2.0;
  TMT_tmp[15] = ((t56 * t145 - t125 * t149) + b_t162_tmp * t140 / 2.0) -
    t162_tmp * t141 / 2.0;
  TMT_tmp[16] = ((t56 * t152 + t125 * t154) + t17 * t140 / 2.0) - t124 * t141 /
    2.0;
  TMT_tmp[17] = ((t56 * t153 + t125 * t155) + t164_tmp * t140 / 2.0) - t94_tmp *
    t141 / 2.0;
  t121 = t18 * t14 * t16;
  t125 = par_mex_var[16] * t140;
  t124 = par_mex_var[16] * t141;
  TMT_tmp[18] = ((t125 * t162 * -2.0 + t124 * t161 * 2.0) - t121 * t23 * t28) -
    t121 * t24 * t28;
  t121 = t120 * t14 * t16;
  TMT_tmp[19] = ((t125 * t164 * -2.0 + t124 * t51 * 2.0) - t121 * t23 * t28 *
                 1.5) - t121 * t24 * t28 * 1.5;
  t121 = t18 * t15 * t16;
  TMT_tmp[20] = ((t124 * t160 * -2.0 - t125 * t163 * 2.0) - t121 * t23 * t28) -
    t121 * t24 * t28;
  t121 = t120 * t15 * t16;
  TMT_tmp[21] = ((t124 * t165 * -2.0 - t125 * t167 * 2.0) - t121 * t23 * t28 *
                 1.5) - t121 * t24 * t28 * 1.5;
  t121 = par_mex_var[16] * t23;
  t54 = par_mex_var[16] * t24;
  TMT_tmp[22] = (((t2 + t121 * t47 / 2.0) + t54 * t47 / 2.0) + t125 * t168 * 2.0)
    + t124 * t50 * 2.0;
  TMT_tmp[23] = (((t3 + t121 * t48 / 2.0) + t54 * t48 / 2.0) + t125 * t170 * 2.0)
    + t124 * t55 * 2.0;
  TMT_tmp[24] = t124 * t145 * 2.0 + t125 * t149 * 2.0;
  TMT_tmp[25] = t124 * t152 * 2.0 - t125 * t154 * 2.0;
  TMT_tmp[26] = t124 * t153 * 2.0 - t125 * t155 * 2.0;
  TMT_tmp[27] = ((t96 * t139 * -0.5 + t98 * t138 / 2.0) + t41_tmp * t161) +
    t43_tmp * t162;
  TMT_tmp[28] = ((t43_tmp * t164 + t41_tmp * t51) - t170_tmp * t139 * 0.75) +
    b_t115_tmp * t138 * 0.75;
  TMT_tmp[29] = ((t97 * t139 * -0.5 + t99 * t138 / 2.0) - t41_tmp * t160) +
    t43_tmp * t163;
  t121 = -1.4142135623730951 * t21 * t36;
  TMT_tmp[30] = ((t121 * t165 + t43_tmp * t167) - t94 * t139 * 0.75) +
    b_t116_tmp * t138 * 0.75;
  t125 = 1.4142135623730951 * t21 * t38;
  t124 = 1.4142135623730951 * t22 * t38;
  t54 = t125 * t47;
  t53_tmp = t124 * t47;
  TMT_tmp[31] = ((t41_tmp * t50 - t43_tmp * t168) + t54 * t139 / 4.0) - t53_tmp *
    t138 / 4.0;
  t125 *= t48;
  t124 *= t48;
  TMT_tmp[32] = ((t41_tmp * t55 - t43_tmp * t170) + t125 * t139 / 4.0) - t124 *
    t138 / 4.0;
  b_t164_tmp = t49_tmp * t36;
  t56 = t50_tmp * t36;
  TMT_tmp[33] = ((t41_tmp * t145 - t43_tmp * t149) - b_t164_tmp * t138 / 4.0) -
    t56 * t139 / 4.0;
  t53 = t51_tmp * t36;
  step = t52_tmp * t36;
  TMT_tmp[34] = ((t41_tmp * t152 + t43_tmp * t154) - t53 * t138 / 4.0) - step *
    t139 / 4.0;
  sn = t3 * 1.4142135623730951 * t21 * t36;
  t115_tmp = t3 * 1.4142135623730951 * t22 * t36;
  TMT_tmp[35] = ((t41_tmp * t153 + t43_tmp * t155) - sn * t138 / 4.0) - t115_tmp
    * t139 / 4.0;
  TMT_tmp[36] = ((t96 * t138 / 2.0 + t98 * t139 / 2.0) + t41_tmp * t162) -
    t43_tmp * t161;
  TMT_tmp[37] = ((t41_tmp * t164 - t43_tmp * t51) + t170_tmp * t138 * 0.75) +
    b_t115_tmp * t139 * 0.75;
  TMT_tmp[38] = ((t97 * t138 / 2.0 + t99 * t139 / 2.0) + t43_tmp * t160) +
    t41_tmp * t163;
  TMT_tmp[39] = ((t43_tmp * t165 + t41_tmp * t167) + t94 * t138 * 0.75) +
    b_t116_tmp * t139 * 0.75;
  TMT_tmp[40] = ((t121 * t168 - t43_tmp * t50) - t54 * t138 / 4.0) - t53_tmp *
    t139 / 4.0;
  TMT_tmp[41] = ((t121 * t170 - t43_tmp * t55) - t125 * t138 / 4.0) - t124 *
    t139 / 4.0;
  t121 = -1.4142135623730951 * t22 * t36;
  TMT_tmp[42] = ((t121 * t145 - t41_tmp * t149) - b_t164_tmp * t139 / 4.0) + t56
    * t138 / 4.0;
  TMT_tmp[43] = ((t121 * t152 + t41_tmp * t154) - t53 * t139 / 4.0) + step *
    t138 / 4.0;
  TMT_tmp[44] = ((t121 * t153 + t41_tmp * t155) - sn * t139 / 4.0) + t115_tmp *
    t138 / 4.0;
  TMT_tmp[45] = t138 * t161 + t139 * t162;
  TMT_tmp[46] = t139 * t164 + t138 * t51;
  TMT_tmp[47] = -t138 * t160 + t139 * t163;
  TMT_tmp[48] = -t138 * t165 + t139 * t167;
  TMT_tmp[49] = t138 * t50 - t139 * t168;
  TMT_tmp[50] = t138 * t55 - t139 * t170;
  TMT_tmp[51] = ((t138 * t145 - t139 * t149) + par_mex_var[4] * t23 * t32_tmp /
                 2.0) + par_mex_var[4] * t24 * t32_tmp / 2.0;
  TMT_tmp[52] = ((t138 * t152 + t139 * t154) + t2 * t23 * t32_tmp / 2.0) + t2 *
    t24 * t32_tmp / 2.0;
  TMT_tmp[53] = ((t138 * t153 + t139 * t155) + t3 * t23 * t32_tmp / 2.0) + t3 *
    t24 * t32_tmp / 2.0;
  fg[0] = par_mex_var[27];
  fg[1] = par_mex_var[28];
  fg[2] = par_mex_var[29];
  step = (-(t41_tmp * par_mex_var[31] / 2.0) + t43_tmp * par_mex_var[30] / 2.0)
    + t141 * par_mex_var[32];
  fg[3] = ((-t140 * t107 - t141 * t49) + t41_tmp * t95 / 2.0) - t43_tmp * step /
    2.0;
  fg[4] = ((t140 * t49 - t141 * t107) - t43_tmp * t95 / 2.0) - t41_tmp * step /
    2.0;
  fg[5] = ((t140 * t95 - t141 * step) + t41_tmp * t107 / 2.0) + t43_tmp * t49 /
    2.0;
  for (i = 0; i < 9; i++) {
    t164_tmp = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      t164_tmp += TMT_tmp[i + 9 * i1] * fg[i1];
    }

    b_TMfd[i] = (((TMfd[i] + w_sd[i]) + w_in[i]) + w_vd_j[i]) + t164_tmp;
  }

  for (i = 0; i < 9; i++) {
    t164_tmp = 0.0;
    for (i1 = 0; i1 < 9; i1++) {
      t164_tmp += TMT[i + 9 * i1] * b_TMfd[i1];
    }

    dz[i] = z[i + 9];
    dz[i + 9] = t164_tmp;
  }

  *flag = 0.0;
}

/* End of code generation (EOM.c) */
