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
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 22,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 27,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 34,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 39,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 50,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 55,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 65,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 71,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 81,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo ad_emlrtRSI = { 95, /* lineNo */
  "loadsF1",                           /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\loadsF1.m"/* pathName */
};

static emlrtRSInfo cd_emlrtRSI = { 104,/* lineNo */
  "loadsF1",                           /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\loadsF1.m"/* pathName */
};

static emlrtDCInfo emlrtDCI = { 10,    /* lineNo */
  34,                                  /* colNo */
  "dyn_mid_step",                      /* fName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\TMTDyn\\Code\\TMTDyn_beta\\Tutorial\\eom\\dyn_mid_step.m",/* pName */
  1                                    /* checkKind */
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
  real_T b_t145_tmp;
  real_T b_t162_tmp;
  real_T b_t163_tmp;
  real_T b_t209_tmp;
  real_T sn;
  real_T step;
  real_T t100;
  real_T t100_tmp;
  real_T t101;
  real_T t103;
  real_T t104;
  real_T t106;
  real_T t139;
  real_T t140;
  real_T t145;
  real_T t145_tmp;
  real_T t146;
  real_T t146_tmp;
  real_T t152;
  real_T t152_tmp;
  real_T t153;
  real_T t162;
  real_T t162_tmp;
  real_T t163;
  real_T t163_tmp;
  real_T t165;
  real_T t166;
  real_T t169;
  real_T t170;
  real_T t183;
  real_T t184;
  real_T t185;
  real_T t186;
  real_T t190;
  real_T t194;
  real_T t197;
  real_T t198;
  real_T t205;
  real_T t205_tmp;
  real_T t206;
  real_T t207;
  real_T t208;
  real_T t209;
  real_T t209_tmp;
  real_T t210;
  real_T t212;
  real_T t213;
  real_T t213_tmp;
  real_T t214;
  real_T t215;
  real_T t215_tmp;
  real_T t3;
  real_T t33;
  real_T t4;
  real_T t40;
  real_T t46;
  real_T t47;
  real_T t49;
  real_T t50;
  real_T t56;
  real_T t57;
  real_T t59;
  real_T t61;
  real_T t66;
  real_T t67;
  real_T t68;
  real_T t69;
  real_T t71;
  real_T t72;
  real_T t73;
  real_T t75;
  real_T t77_tmp;
  real_T t78;
  real_T t79;
  real_T t80;
  real_T t86_tmp;
  real_T t88_tmp;
  real_T t92;
  real_T t93;
  real_T t94;
  real_T t95;
  real_T t96;
  real_T t97;
  real_T t99;
  real_T t99_tmp;
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
  /*     27-Feb-2021 16:40:36 */
  t101 = par_mex_var[4];
  st.site = &b_emlrtRSI;
  massF1(&st, par_mex_var, z, 1.0E-6 * par_mex_var[4], M, T, Dd, fg);
  for (i = 0; i < 9; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      t145_tmp = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        t145_tmp += T[i2 + 6 * i] * M[i2 + 6 * i1];
      }

      TMT_tmp[i + 9 * i1] = t145_tmp;
    }
  }

  st.site = &c_emlrtRSI;
  sprdmpF10(&st, par_mex_var, z, 1.0E-6 * par_mex_var[4], Tt, kx, vd, in, &step);
  st.site = &d_emlrtRSI;
  massF1(&st, par_mex_var, z, 0.999999 * par_mex_var[4], M, b_T, b_Dd, b_fg);
  for (i = 0; i < 9; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      t145_tmp = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        t145_tmp += b_T[i2 + 6 * i] * M[i2 + 6 * i1];
      }

      c_TMT_tmp[i + 9 * i1] = t145_tmp;
    }
  }

  st.site = &e_emlrtRSI;
  sprdmpF10(&st, par_mex_var, z, 0.999999 * par_mex_var[4], b_Tt, b_kx, b_vd,
            b_in, &step);
  for (i = 0; i < 9; i++) {
    for (i1 = 0; i1 < 9; i1++) {
      t145_tmp = 0.0;
      step = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        TMT_tmp_tmp = i + 9 * i2;
        i3 = i2 + 6 * i1;
        t145_tmp += TMT_tmp[TMT_tmp_tmp] * T[i3];
        step += c_TMT_tmp[TMT_tmp_tmp] * b_T[i3];
      }

      TMT_tmp_tmp = i + 9 * i1;
      b_TMT_tmp[TMT_tmp_tmp] = step;
      TMT[TMT_tmp_tmp] = t145_tmp;
    }
  }

  for (i = 0; i < 81; i++) {
    TMT[i] = (TMT[i] * t101 + b_TMT_tmp[i] * t101) / 2.0;
  }

  for (i = 0; i < 54; i++) {
    Dd[i] = -Dd[i];
  }

  for (i = 0; i < 6; i++) {
    t145_tmp = 0.0;
    for (i1 = 0; i1 < 9; i1++) {
      t145_tmp += Dd[i + 6 * i1] * z[i1 + 9];
    }

    c_Dd[i] = t145_tmp + fg[i];
  }

  for (i = 0; i < 9; i++) {
    t145_tmp = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      t145_tmp += TMT_tmp[i + 9 * i1] * c_Dd[i1];
    }

    TMfd[i] = t145_tmp;
  }

  for (i = 0; i < 54; i++) {
    b_Dd[i] = -b_Dd[i];
  }

  for (i = 0; i < 6; i++) {
    t145_tmp = 0.0;
    for (i1 = 0; i1 < 9; i1++) {
      t145_tmp += b_Dd[i + 6 * i1] * z[i1 + 9];
    }

    c_Dd[i] = t145_tmp + b_fg[i];
  }

  for (i = 0; i < 9; i++) {
    t145_tmp = 0.0;
    step = 0.0;
    sn = 0.0;
    t33 = 0.0;
    t40 = 0.0;
    t3 = 0.0;
    t75 = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      i2 = i + 9 * i1;
      t145_tmp += c_TMT_tmp[i2] * c_Dd[i1];
      t72 = Tt[i2];
      step += t72 * vd[i1];
      t152_tmp = b_Tt[i2];
      sn += t152_tmp * b_vd[i1];
      t33 += t72 * kx[i1];
      t40 += t152_tmp * b_kx[i1];
      t3 += t72 * in[i1];
      t75 += t152_tmp * b_in[i1];
    }

    TMfd[i] = (TMfd[i] * t101 + t145_tmp * t101) / 2.0;
    w_vd_j[i] = (step * par_mex_var[4] + sn * par_mex_var[4]) / 2.0;
    w_sd[i] = (t33 * par_mex_var[4] + t40 * par_mex_var[4]) / 2.0;
    w_in[i] = (t3 * par_mex_var[4] + t75 * par_mex_var[4]) / 2.0;
  }

  for (TMT_tmp_tmp = 0; TMT_tmp_tmp < 9; TMT_tmp_tmp++) {
    sn = (real_T)TMT_tmp_tmp * 0.1 + 0.100001;
    st.site = &f_emlrtRSI;
    massF1(&st, par_mex_var, z, sn * t101, M, T, Dd, fg);
    for (i = 0; i < 9; i++) {
      for (i1 = 0; i1 < 6; i1++) {
        t145_tmp = 0.0;
        for (i2 = 0; i2 < 6; i2++) {
          t145_tmp += T[i2 + 6 * i] * M[i2 + 6 * i1];
        }

        TMT_tmp[i + 9 * i1] = t145_tmp;
      }

      for (i1 = 0; i1 < 9; i1++) {
        t145_tmp = 0.0;
        for (i2 = 0; i2 < 6; i2++) {
          t145_tmp += TMT_tmp[i + 9 * i2] * T[i2 + 6 * i1];
        }

        b_TMT_tmp[i + 9 * i1] = t145_tmp;
      }
    }

    for (i = 0; i < 81; i++) {
      TMT[i] += b_TMT_tmp[i] * t101;
    }

    for (i = 0; i < 54; i++) {
      Dd[i] = -Dd[i];
    }

    for (i = 0; i < 6; i++) {
      t145_tmp = 0.0;
      for (i1 = 0; i1 < 9; i1++) {
        t145_tmp += Dd[i + 6 * i1] * z[i1 + 9];
      }

      c_Dd[i] = t145_tmp + fg[i];
    }

    for (i = 0; i < 9; i++) {
      t145_tmp = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        t145_tmp += TMT_tmp[i + 9 * i1] * c_Dd[i1];
      }

      TMfd[i] += t145_tmp * t101;
    }

    st.site = &g_emlrtRSI;
    sprdmpF10(&st, par_mex_var, z, sn * par_mex_var[4], Tt, kx, vd, in, &step);
    for (i = 0; i < 9; i++) {
      t145_tmp = 0.0;
      step = 0.0;
      sn = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        t33 = Tt[i + 9 * i1];
        t145_tmp += t33 * vd[i1];
        step += t33 * kx[i1];
        sn += t33 * in[i1];
      }

      w_vd_j[i] += t145_tmp * par_mex_var[4];
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
      t145_tmp = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        t145_tmp += T[i2 + 6 * i] * M[i2 + 6 * i1];
      }

      TMT_tmp[i + 9 * i1] = t145_tmp;
    }
  }

  for (i = 0; i < 54; i++) {
    Dd[i] = -Dd[i];
  }

  for (i = 0; i < 6; i++) {
    t145_tmp = 0.0;
    for (i1 = 0; i1 < 9; i1++) {
      t145_tmp += Dd[i + 6 * i1] * z[i1 + 9];
    }

    c_Dd[i] = t145_tmp + fg[i];
  }

  for (i = 0; i < 9; i++) {
    t145_tmp = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      t145_tmp += TMT_tmp[i + 9 * i1] * c_Dd[i1];
    }

    TMfd[i] += t145_tmp;
  }

  st.site = &i_emlrtRSI;

  /* LOADSF1 */
  /*     [OUT1,OUT2,OUT3] = LOADSF1(IN1,IN2,S,DS,T_SYM) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
  /*     27-Feb-2021 16:49:38 */
  step = par_mex_var[4] * z[6];
  t3 = par_mex_var[4] * 2.0;
  t4 = par_mex_var[4] * par_mex_var[4];
  sn = z[7] * t4;
  t33 = (par_mex_var[4] - 0.025) * (par_mex_var[4] - 0.025);
  t40 = 1.0 / (muDoubleScalarExp(-(par_mex_var[4] * 200.0) + 5.0) + 1.0);
  t46 = (t3 - 0.05) * t40;
  t47 = t33 * t40;
  t50 = t40 * ((t4 + -(par_mex_var[4] / 20.0)) + 0.000625);
  t56 = z[0] * t3 + t40 * ((par_mex_var[4] * z[0] * -2.0 + z[0] / 20.0) + z[1] *
    (t3 - 0.05));
  t57 = z[2] * t3 + t40 * ((par_mex_var[4] * z[2] * -2.0 + z[2] / 20.0) + z[3] *
    (t3 - 0.05));
  t59 = (z[4] * t3 + t40 * ((par_mex_var[4] * z[4] * -2.0 + z[4] / 20.0) + z[5] *
          (t3 - 0.05))) + 1.0;
  step = (step / 2.0 + sn / 2.0) + t40 * (((((-step + z[6] / 40.0) + -sn) + z[7]
    / 1600.0) + z[8] * t33) + (par_mex_var[4] - 0.025) * (z[6] + z[7] / 20.0)) /
    2.0;
  t49 = t3 + -t46;
  t3 = t56 * t56;
  t61 = t57 * t57;
  sn = t59 * t59;
  t66 = muDoubleScalarCos(step);
  t67 = muDoubleScalarSin(step);
  t68 = t66 * t66;
  t69 = t67 * t67;
  step = (t3 + t61) + sn;
  t71 = 1.0 / (step * step);
  b_st.site = &ad_emlrtRSI;
  if (step < 0.0) {
    emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  t72 = 1.0 / muDoubleScalarSqrt(step);
  t73 = muDoubleScalarPower(t72, 3.0);
  step = t46 * t72;
  t75 = t49 * t72;
  t77_tmp = t59 * t72 + 1.0;
  b_st.site = &cd_emlrtRSI;
  if (t77_tmp < 0.0) {
    emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  t78 = muDoubleScalarSqrt(t77_tmp);
  t92 = step + -t46 * sn * t73;
  t79 = 1.0 / t78;
  t86_tmp = 1.4142135623730951 * t66 * t78;
  t88_tmp = 1.4142135623730951 * t67 * t78;
  t93 = t75 + -(t49 * sn * t73);
  t80 = muDoubleScalarPower(t79, 3.0);
  t94 = 1.4142135623730951 * t66 * step * t79 / 2.0;
  t95 = 1.4142135623730951 * t67 * step * t79 / 2.0;
  t96 = 1.4142135623730951 * t66 * t75 * t79 / 2.0;
  t97 = 1.4142135623730951 * t67 * t75 * t79 / 2.0;
  t75 = 1.4142135623730951 * t56 * t66 * t72;
  t33 = t75 * t79;
  t99_tmp = 1.4142135623730951 * t57 * t66 * t72;
  t99 = t99_tmp * t79;
  t100_tmp = 1.4142135623730951 * t56 * t67 * t72;
  t100 = t100_tmp * t79;
  t72 *= 1.4142135623730951 * t57 * t67;
  t101 = t72 * t79;
  step = 1.4142135623730951 * t46 * t56;
  sn = step * t57;
  t139 = sn * t66 * t73 * t79 / 2.0;
  t140 = sn * t67 * t73 * t79 / 2.0;
  t145_tmp = step * t59;
  b_t145_tmp = t145_tmp * t67 * t73 * t79;
  t145 = b_t145_tmp / 2.0;
  t214 = 1.4142135623730951 * t46 * t57 * t59;
  t146_tmp = t214 * t67 * t73 * t79;
  t146 = t146_tmp / 2.0;
  step = 1.4142135623730951 * t49 * t56;
  t152_tmp = step * t57;
  t152 = t152_tmp * t66 * t73 * t79 / 2.0;
  t153 = t152_tmp * t67 * t73 * t79 / 2.0;
  t162_tmp = step * t59;
  b_t162_tmp = t162_tmp * t67 * t73 * t79;
  t162 = b_t162_tmp / 2.0;
  t163_tmp = 1.4142135623730951 * t49 * t57 * t59;
  b_t163_tmp = t163_tmp * t67 * t73 * t79;
  t163 = b_t163_tmp / 2.0;
  t103 = t33 / 2.0;
  t104 = t99 / 2.0;
  t106 = t101 / 2.0;
  step = sn * t59;
  t165 = step * t66 * t71 * t80 / 4.0;
  t166 = step * t67 * t71 * t80 / 4.0;
  step = t152_tmp * t59;
  t169 = step * t66 * t71 * t80 / 4.0;
  t170 = step * t67 * t71 * t80 / 4.0;
  t183 = t33 + t101;
  t184 = t99 + -t100;
  t185 = t103 + t106;
  t190 = par_mex_var[4] * t33 / 4.0 + par_mex_var[4] * t101 / 4.0;
  t197 = t47 * t33 / 4.0 + t47 * t101 / 4.0;
  step = 1.4142135623730951 * t46 * t59;
  t101 = 1.4142135623730951 * t46 * t3;
  t205_tmp = step * t3;
  t205 = (((t94 + -(t101 * t66 * t73 * t79 / 2.0)) + -t140) + t205_tmp * t66 *
          t71 * t80 / 4.0) + t166;
  t152_tmp = 1.4142135623730951 * t46 * t61;
  t40 = step * t61;
  t208 = (((t95 + -(t152_tmp * t67 * t73 * t79 / 2.0)) + -t139) + t40 * t67 *
          t71 * t80 / 4.0) + t165;
  step = 1.4142135623730951 * t49 * t59;
  t209_tmp = 1.4142135623730951 * t49 * t3;
  b_t209_tmp = step * t3;
  t209 = (((t96 + -(t209_tmp * t66 * t73 * t79 / 2.0)) + b_t209_tmp * t66 * t71 *
           t80 / 4.0) + -t153) + t170;
  t3 = 1.4142135623730951 * t49 * t61;
  t33 = step * t61;
  t212 = (((t97 + -(t3 * t67 * t73 * t79 / 2.0)) + t33 * t67 * t71 * t80 / 4.0)
          + -t152) + t169;
  sn = t75 * t80;
  step = t72 * t80;
  t213_tmp = t145_tmp * t66 * t73 * t79;
  t213 = ((t213_tmp / 2.0 + t146) + sn * t92 / 4.0) + step * t92 / 4.0;
  t215_tmp = t162_tmp * t66 * t73 * t79;
  t215 = ((t215_tmp / 2.0 + t163) + sn * t93 / 4.0) + step * t93 / 4.0;
  t186 = t104 + -(t100 / 2.0);
  t194 = par_mex_var[4] * t99 / 4.0 + -(par_mex_var[4] * t100 / 4.0);
  t198 = t47 * t99 / 4.0 + -(t47 * t100 / 4.0);
  t206 = (((t94 + -(t152_tmp * t66 * t73 * t79 / 2.0)) + t140) + t40 * t66 * t71
          * t80 / 4.0) + -t166;
  t207 = (((t95 + -(t101 * t67 * t73 * t79 / 2.0)) + t139) + t205_tmp * t67 *
          t71 * t80 / 4.0) + -t165;
  t210 = (((t96 + -(t3 * t66 * t73 * t79 / 2.0)) + t153) + t33 * t66 * t71 * t80
          / 4.0) + -t170;
  t71 = (((t97 + -(t209_tmp * t67 * t73 * t79 / 2.0)) + t152) + b_t209_tmp * t67
         * t71 * t80 / 4.0) + -t169;
  sn = t99_tmp * t80;
  step = t100_tmp * t80;
  t99_tmp = t214 * t66 * t73 * t79;
  t214 = ((t99_tmp / 2.0 + -t145) + sn * t92 / 4.0) + -(step * t92 / 4.0);
  t97 = t163_tmp * t66 * t73 * t79;
  t152 = ((t97 / 2.0 + -t162) + sn * t93 / 4.0) + -(step * t93 / 4.0);
  t94 = (t86_tmp * par_mex_var[30] / 2.0 + t88_tmp * par_mex_var[31] / 2.0) +
    -(t185 * par_mex_var[32]);
  t95 = (t86_tmp * par_mex_var[32] / 2.0 + t185 * par_mex_var[30]) + t186 *
    par_mex_var[31];
  t96 = (t88_tmp * par_mex_var[32] / 2.0 + t185 * par_mex_var[31]) + -(t186 *
    par_mex_var[30]);

  /*  EOM */
  for (i = 0; i < 9; i++) {
    for (i1 = 0; i1 < 9; i1++) {
      t145_tmp = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        t145_tmp += TMT_tmp[i + 9 * i2] * T[i2 + 6 * i1];
      }

      TMT_tmp_tmp = i + 9 * i1;
      b_TMT_tmp[TMT_tmp_tmp] = TMT[TMT_tmp_tmp] + t145_tmp;
    }
  }

  st.site = &j_emlrtRSI;
  pinv(&st, b_TMT_tmp, TMT);
  step = par_mex_var[16] * 1.4142135623730951 * t66;
  t165 = step * t78;
  sn = par_mex_var[16] * 1.4142135623730951 * t67;
  t169 = sn * t78;
  t99 = par_mex_var[16] * 1.4142135623730951 * t49;
  t140 = t99 * t56 * t59;
  t139 = t140 * t66 * t73 * t79;
  t153 = t4 + -t50;
  TMT_tmp[0] = (((t153 + par_mex_var[16] * t162 * t186) + t165 * t209) + t169 *
                t71) - t139 * t185 / 2.0;
  t61 = par_mex_var[16] * 1.4142135623730951 * t46;
  t166 = t61 * t56 * t59;
  t170 = t166 * t66 * t73 * t79;
  TMT_tmp[1] = (((t47 + par_mex_var[16] * t145 * t186) + t165 * t205) + t169 *
                t207) - t170 * t185 / 2.0;
  t209_tmp = t99 * t57 * t59;
  t99 = t209_tmp * t66 * t73 * t79;
  TMT_tmp[2] = ((par_mex_var[16] * t163 * t186 - t169 * t210) + t165 * t212) -
    t99 * t185 / 2.0;
  b_t209_tmp = t61 * t57 * t59;
  t61 = b_t209_tmp * t66 * t73 * t79;
  TMT_tmp[3] = ((par_mex_var[16] * t146 * t186 - t169 * t206) + t165 * t208) -
    t61 * t185 / 2.0;
  t205_tmp = -par_mex_var[16] * 1.4142135623730951 * t66 * t78;
  t162_tmp = step * t79;
  t3 = sn * t79;
  t75 = t162_tmp * t93;
  t72 = t3 * t93;
  TMT_tmp[4] = ((t205_tmp * t215 + t169 * t152) + t75 * t185 / 2.0) - t72 * t186
    / 2.0;
  t162_tmp *= t92;
  t3 *= t92;
  TMT_tmp[5] = ((t205_tmp * t213 + t169 * t214) + t162_tmp * t185 / 2.0) - t3 *
    t186 / 2.0;
  t152_tmp = par_mex_var[16] * par_mex_var[4] * 1.4142135623730951;
  t101 = t152_tmp * t66 * t78;
  t152_tmp = t152_tmp * t67 * t78;
  TMT_tmp[6] = ((t169 * t190 + t165 * t194) - t101 * t186 / 2.0) - t152_tmp *
    t185 / 2.0;
  t145_tmp = t4 / 2.0 - t50 / 2.0;
  t40 = t103 * t145_tmp + t106 * t145_tmp;
  t33 = t104 * t145_tmp + -(t100 / 2.0) * t145_tmp;
  TMT_tmp[7] = ((t169 * t40 + t165 * t33) - t165 * t186 * t145_tmp) - t169 *
    t185 * t145_tmp;
  step = par_mex_var[16] * 1.4142135623730951 * t47;
  sn = step * t66 * t78;
  step = step * t67 * t78;
  TMT_tmp[8] = ((t165 * t198 + t169 * t197) - sn * t186 / 2.0) - step * t185 /
    2.0;
  TMT_tmp[9] = ((t169 * t209 - t165 * t71) - t139 * t186 / 2.0) - t140 * t67 *
    t73 * t79 * t185 / 2.0;
  TMT_tmp[10] = ((t169 * t205 - t165 * t207) - t170 * t186 / 2.0) - t166 * t67 *
    t73 * t79 * t185 / 2.0;
  TMT_tmp[11] = (((t153 + t165 * t210) + t169 * t212) - t99 * t186 / 2.0) -
    t209_tmp * t67 * t73 * t79 * t185 / 2.0;
  TMT_tmp[12] = (((t47 + t165 * t206) + t169 * t208) - t61 * t186 / 2.0) -
    b_t209_tmp * t67 * t73 * t79 * t185 / 2.0;
  TMT_tmp[13] = ((t205_tmp * t152 - t169 * t215) + t75 * t186 / 2.0) + t72 *
    t185 / 2.0;
  TMT_tmp[14] = ((t205_tmp * t214 - t169 * t213) + t162_tmp * t186 / 2.0) + t3 *
    t185 / 2.0;
  TMT_tmp[15] = ((t205_tmp * t190 + t169 * t194) + t101 * t185 / 2.0) - t152_tmp
    * t186 / 2.0;
  TMT_tmp[16] = ((t205_tmp * t40 + t169 * t33) + t165 * t185 * t145_tmp) - t169 *
    t186 * t145_tmp;
  TMT_tmp[17] = ((t205_tmp * t197 + t169 * t198) + sn * t185 / 2.0) - step *
    t186 / 2.0;
  step = par_mex_var[16] * t49;
  t165 = step * t56 * t59;
  t169 = par_mex_var[16] * t185;
  t99 = par_mex_var[16] * t186;
  TMT_tmp[18] = ((t169 * t209 * -2.0 + t99 * t71 * 2.0) - t165 * t68 * t73 / 2.0)
    - t165 * t69 * t73 / 2.0;
  sn = par_mex_var[16] * t46;
  t165 = sn * t56 * t59;
  TMT_tmp[19] = ((t169 * t205 * -2.0 + t99 * t207 * 2.0) - t165 * t68 * t73 /
                 2.0) - t165 * t69 * t73 / 2.0;
  t165 = step * t57 * t59;
  TMT_tmp[20] = ((t99 * t210 * -2.0 - t169 * t212 * 2.0) - t165 * t68 * t73 /
                 2.0) - t165 * t69 * t73 / 2.0;
  t165 = sn * t57 * t59;
  TMT_tmp[21] = ((t99 * t206 * -2.0 - t169 * t208 * 2.0) - t165 * t68 * t73 /
                 2.0) - t165 * t69 * t73 / 2.0;
  t165 = par_mex_var[16] * t68;
  t139 = par_mex_var[16] * t69;
  TMT_tmp[22] = (((t153 + t165 * t93 / 2.0) + t139 * t93 / 2.0) + t169 * t215 *
                 2.0) + t99 * t152 * 2.0;
  TMT_tmp[23] = (((t47 + t165 * t92 / 2.0) + t139 * t92 / 2.0) + t169 * t213 *
                 2.0) + t99 * t214 * 2.0;
  TMT_tmp[24] = t99 * t190 * 2.0 - t169 * t194 * 2.0;
  TMT_tmp[25] = t99 * t40 * 2.0 - t169 * t33 * 2.0;
  TMT_tmp[26] = t169 * t198 * -2.0 + t99 * t197 * 2.0;
  TMT_tmp[27] = ((t88_tmp * t209 + t86_tmp * t71) - t215_tmp * t184 / 4.0) +
    b_t162_tmp * t183 / 4.0;
  TMT_tmp[28] = ((t88_tmp * t205 + t86_tmp * t207) - t213_tmp * t184 / 4.0) +
    b_t145_tmp * t183 / 4.0;
  t165 = -1.4142135623730951 * t66 * t78;
  TMT_tmp[29] = ((t165 * t210 + t88_tmp * t212) - t97 * t184 / 4.0) + b_t163_tmp
    * t183 / 4.0;
  TMT_tmp[30] = ((t165 * t206 + t88_tmp * t208) - t99_tmp * t184 / 4.0) +
    t146_tmp * t183 / 4.0;
  t169 = 1.4142135623730951 * t66 * t79;
  t99 = 1.4142135623730951 * t67 * t79;
  t139 = t169 * t93;
  t153 = t99 * t93;
  TMT_tmp[31] = ((t86_tmp * t152 - t88_tmp * t215) + t139 * t184 / 4.0) - t153 *
    t183 / 4.0;
  t169 *= t92;
  t99 *= t92;
  TMT_tmp[32] = ((t86_tmp * t214 - t88_tmp * t213) + t169 * t184 / 4.0) - t99 *
    t183 / 4.0;
  t61 = par_mex_var[4] * 1.4142135623730951 * t66 * t78;
  t170 = par_mex_var[4] * 1.4142135623730951 * t67 * t78;
  TMT_tmp[33] = ((t86_tmp * t190 + t88_tmp * t194) - t61 * t183 / 4.0) - t170 *
    t184 / 4.0;
  TMT_tmp[34] = ((t86_tmp * t40 + t88_tmp * t33) - t86_tmp * t183 * t145_tmp /
                 2.0) - t88_tmp * t184 * t145_tmp / 2.0;
  t205_tmp = 1.4142135623730951 * t47 * t66 * t78;
  t162_tmp = 1.4142135623730951 * t47 * t67 * t78;
  TMT_tmp[35] = ((t86_tmp * t197 + t88_tmp * t198) - t205_tmp * t183 / 4.0) -
    t162_tmp * t184 / 4.0;
  TMT_tmp[36] = ((t86_tmp * t209 - t88_tmp * t71) + t215_tmp * t183 / 4.0) +
    b_t162_tmp * t184 / 4.0;
  TMT_tmp[37] = ((t86_tmp * t205 - t88_tmp * t207) + t213_tmp * t183 / 4.0) +
    b_t145_tmp * t184 / 4.0;
  TMT_tmp[38] = ((t88_tmp * t210 + t86_tmp * t212) + t97 * t183 / 4.0) +
    b_t163_tmp * t184 / 4.0;
  TMT_tmp[39] = ((t88_tmp * t206 + t86_tmp * t208) + t99_tmp * t183 / 4.0) +
    t146_tmp * t184 / 4.0;
  TMT_tmp[40] = ((t165 * t215 - t88_tmp * t152) - t139 * t183 / 4.0) - t153 *
    t184 / 4.0;
  TMT_tmp[41] = ((t165 * t213 - t88_tmp * t214) - t169 * t183 / 4.0) - t99 *
    t184 / 4.0;
  t165 = -1.4142135623730951 * t67 * t78;
  TMT_tmp[42] = ((t165 * t190 + t86_tmp * t194) - t61 * t184 / 4.0) + t170 *
    t183 / 4.0;
  TMT_tmp[43] = ((t165 * t40 + t86_tmp * t33) - t86_tmp * t184 * t145_tmp / 2.0)
    + t88_tmp * t183 * t145_tmp / 2.0;
  TMT_tmp[44] = ((t86_tmp * t198 - t88_tmp * t197) - t205_tmp * t184 / 4.0) +
    t162_tmp * t183 / 4.0;
  TMT_tmp[45] = t184 * t209 + t183 * t71;
  TMT_tmp[46] = t184 * t205 + t183 * t207;
  TMT_tmp[47] = -t183 * t210 + t184 * t212;
  TMT_tmp[48] = -t183 * t206 + t184 * t208;
  TMT_tmp[49] = t183 * t152 - t184 * t215;
  TMT_tmp[50] = t183 * t214 - t184 * t213;
  TMT_tmp[51] = ((t183 * t190 + t184 * t194) + par_mex_var[4] * t68 * t77_tmp /
                 2.0) + par_mex_var[4] * t69 * t77_tmp / 2.0;
  TMT_tmp[52] = ((t183 * t40 + t184 * t33) + t68 * t77_tmp * t145_tmp) + t69 *
    t77_tmp * t145_tmp;
  TMT_tmp[53] = ((t183 * t197 + t184 * t198) + t47 * t68 * t77_tmp / 2.0) + t47 *
    t69 * t77_tmp / 2.0;
  fg[0] = par_mex_var[27];
  fg[1] = par_mex_var[28];
  fg[2] = par_mex_var[29];
  step = (-(t86_tmp * par_mex_var[31] / 2.0) + t88_tmp * par_mex_var[30] / 2.0)
    + t186 * par_mex_var[32];
  fg[3] = ((-t185 * t95 - t186 * t96) + t86_tmp * t94 / 2.0) - t88_tmp * step /
    2.0;
  fg[4] = ((t185 * t96 - t186 * t95) - t88_tmp * t94 / 2.0) - t86_tmp * step /
    2.0;
  fg[5] = ((t185 * t94 - t186 * step) + t86_tmp * t95 / 2.0) + t88_tmp * t96 /
    2.0;
  for (i = 0; i < 9; i++) {
    t145_tmp = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      t145_tmp += TMT_tmp[i + 9 * i1] * fg[i1];
    }

    b_TMfd[i] = (((TMfd[i] + w_sd[i]) + w_in[i]) + w_vd_j[i]) + t145_tmp;
  }

  for (i = 0; i < 9; i++) {
    t145_tmp = 0.0;
    for (i1 = 0; i1 < 9; i1++) {
      t145_tmp += TMT[i + 9 * i1] * b_TMfd[i1];
    }

    dz[i] = z[i + 9];
    dz[i + 9] = t145_tmp;
  }

  *flag = 0.0;
}

/* End of code generation (EOM.c) */
