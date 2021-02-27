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
#include "eml_int_forloop_overflow_check.h"
#include "loadsF1.h"
#include "massF1.h"
#include "massF2.h"
#include "rt_nonfinite.h"
#include "sprdmpF6.h"
#include "xscal.h"
#include "xzsvdc.h"
#include "mwmathutil.h"
#include <math.h>
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

static emlrtRSInfo ae_emlrtRSI = { 21, /* lineNo */
  "pinv",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m"/* pathName */
};

static emlrtRSInfo be_emlrtRSI = { 42, /* lineNo */
  "eml_pinv",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m"/* pathName */
};

static emlrtRSInfo ce_emlrtRSI = { 46, /* lineNo */
  "eml_pinv",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m"/* pathName */
};

static emlrtRSInfo de_emlrtRSI = { 53, /* lineNo */
  "eml_pinv",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m"/* pathName */
};

static emlrtRSInfo ee_emlrtRSI = { 68, /* lineNo */
  "eml_pinv",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m"/* pathName */
};

static emlrtRSInfo fe_emlrtRSI = { 69, /* lineNo */
  "eml_pinv",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m"/* pathName */
};

static emlrtRSInfo ge_emlrtRSI = { 72, /* lineNo */
  "eml_pinv",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m"/* pathName */
};

static emlrtRSInfo he_emlrtRSI = { 29, /* lineNo */
  "anyNonFinite",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\anyNonFinite.m"/* pathName */
};

static emlrtRSInfo ie_emlrtRSI = { 44, /* lineNo */
  "vAllOrAny",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\vAllOrAny.m"/* pathName */
};

static emlrtRSInfo le_emlrtRSI = { 53, /* lineNo */
  "svd",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m"/* pathName */
};

static emlrtRSInfo me_emlrtRSI = { 108,/* lineNo */
  "callLAPACK",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m"/* pathName */
};

static emlrtRSInfo ne_emlrtRSI = { 34, /* lineNo */
  "xgesvd",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgesvd.m"/* pathName */
};

static emlrtRSInfo tf_emlrtRSI = { 46, /* lineNo */
  "eps",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\elmat\\eps.m"/* pathName */
};

static emlrtRSInfo uf_emlrtRSI = { 63, /* lineNo */
  "xgemm",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgemm.m"/* pathName */
};

static emlrtRSInfo vf_emlrtRSI = { 65, /* lineNo */
  "xgemm",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgemm.m"/* pathName */
};

static emlrtRSInfo wf_emlrtRSI = { 128,/* lineNo */
  "xgemm",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgemm.m"/* pathName */
};

static emlrtRSInfo xf_emlrtRSI = { 135,/* lineNo */
  "xgemm",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgemm.m"/* pathName */
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
void EOM(const emlrtStack *sp, real_T t, const real_T z[10], const struct0_T
         *par_mex, real_T dz[10], real_T *flag)
{
  static const int8_T iv[6] = { 0, 0, 1, 1, 2, 2 };

  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  real_T M[36];
  real_T par_mex_var[34];
  real_T Dd[30];
  real_T T[30];
  real_T TMT_tmp[30];
  real_T Tt[30];
  real_T b_Dd[30];
  real_T b_T[30];
  real_T b_Tt[30];
  real_T c_TMT_tmp[30];
  real_T C[25];
  real_T TMT[25];
  real_T b_TMT[25];
  real_T b_TMT_tmp[25];
  real_T b_fg[6];
  real_T b_in[6];
  real_T b_kx[6];
  real_T b_vd[6];
  real_T c_Dd[6];
  real_T fg[6];
  real_T in[6];
  real_T kx[6];
  real_T vd[6];
  real_T TMfd[5];
  real_T d_TMT_tmp[5];
  real_T w_in[5];
  real_T w_sd[5];
  real_T w_vd_j[5];
  real_T d;
  real_T d1;
  real_T d2;
  real_T d3;
  real_T d4;
  real_T d5;
  real_T d6;
  real_T sn;
  real_T step;
  real_T unnamed_idx_2;
  int32_T ar;
  int32_T b;
  int32_T br;
  int32_T cr;
  int32_T ia;
  int32_T ib;
  int32_T ic;
  int32_T j;
  int32_T r;
  int32_T vcol;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
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
  for (ia = 0; ia < 6; ia++) {
    par_mex_var[ia + 21] = par_mex->user_pars.p[((int32_T)step + 1094 * (iv[ia]
      + 1)) - 1];
    par_mex_var[ia + 27] = par_mex->user_pars.f_ex[((int32_T)step + 1094 * (ia +
      1)) - 1];
  }

  par_mex_var[33] = 1.0;

  /* ROMF */
  /*     [OUT1,OUT2] = ROMF(IN1,IN2,S,DS,T_SYM) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
  /*     27-Feb-2021 16:27:16 */
  unnamed_idx_2 = par_mex_var[4];
  st.site = &b_emlrtRSI;
  massF1(&st, par_mex_var, z, 1.0E-6 * par_mex_var[4], M, T, Dd, fg);
  for (ia = 0; ia < 5; ia++) {
    for (b = 0; b < 6; b++) {
      d = 0.0;
      for (ar = 0; ar < 6; ar++) {
        d += T[ar + 6 * ia] * M[ar + 6 * b];
      }

      TMT_tmp[ia + 5 * b] = d;
    }
  }

  st.site = &c_emlrtRSI;
  sprdmpF6(&st, par_mex_var, z, 1.0E-6 * par_mex_var[4], Tt, kx, vd, in, &step);
  st.site = &d_emlrtRSI;
  massF1(&st, par_mex_var, z, 0.999999 * par_mex_var[4], M, b_T, b_Dd, b_fg);
  for (ia = 0; ia < 5; ia++) {
    for (b = 0; b < 6; b++) {
      d = 0.0;
      for (ar = 0; ar < 6; ar++) {
        d += b_T[ar + 6 * ia] * M[ar + 6 * b];
      }

      c_TMT_tmp[ia + 5 * b] = d;
    }
  }

  st.site = &e_emlrtRSI;
  sprdmpF6(&st, par_mex_var, z, 0.999999 * par_mex_var[4], b_Tt, b_kx, b_vd,
           b_in, &step);
  for (ia = 0; ia < 5; ia++) {
    for (b = 0; b < 5; b++) {
      d = 0.0;
      step = 0.0;
      for (ar = 0; ar < 6; ar++) {
        vcol = ia + 5 * ar;
        j = ar + 6 * b;
        d += TMT_tmp[vcol] * T[j];
        step += c_TMT_tmp[vcol] * b_T[j];
      }

      vcol = ia + 5 * b;
      b_TMT_tmp[vcol] = step;
      TMT[vcol] = d;
    }
  }

  for (ia = 0; ia < 25; ia++) {
    TMT[ia] = (TMT[ia] * unnamed_idx_2 + b_TMT_tmp[ia] * unnamed_idx_2) / 2.0;
  }

  for (ia = 0; ia < 30; ia++) {
    Dd[ia] = -Dd[ia];
  }

  for (ia = 0; ia < 6; ia++) {
    d = 0.0;
    for (b = 0; b < 5; b++) {
      d += Dd[ia + 6 * b] * z[b + 5];
    }

    c_Dd[ia] = d + fg[ia];
  }

  for (ia = 0; ia < 5; ia++) {
    d = 0.0;
    for (b = 0; b < 6; b++) {
      d += TMT_tmp[ia + 5 * b] * c_Dd[b];
    }

    TMfd[ia] = d;
  }

  for (ia = 0; ia < 30; ia++) {
    b_Dd[ia] = -b_Dd[ia];
  }

  for (ia = 0; ia < 6; ia++) {
    d = 0.0;
    for (b = 0; b < 5; b++) {
      d += b_Dd[ia + 6 * b] * z[b + 5];
    }

    c_Dd[ia] = d + b_fg[ia];
  }

  for (ia = 0; ia < 5; ia++) {
    d = 0.0;
    step = 0.0;
    sn = 0.0;
    d1 = 0.0;
    d2 = 0.0;
    d3 = 0.0;
    d4 = 0.0;
    for (b = 0; b < 6; b++) {
      ar = ia + 5 * b;
      d += c_TMT_tmp[ar] * c_Dd[b];
      d5 = Tt[ar];
      step += d5 * vd[b];
      d6 = b_Tt[ar];
      sn += d6 * b_vd[b];
      d1 += d5 * kx[b];
      d2 += d6 * b_kx[b];
      d3 += d5 * in[b];
      d4 += d6 * b_in[b];
    }

    TMfd[ia] = (TMfd[ia] * unnamed_idx_2 + d * unnamed_idx_2) / 2.0;
    w_vd_j[ia] = (step * par_mex_var[4] + sn * par_mex_var[4]) / 2.0;
    w_sd[ia] = (d1 * par_mex_var[4] + d2 * par_mex_var[4]) / 2.0;
    w_in[ia] = (d3 * par_mex_var[4] + d4 * par_mex_var[4]) / 2.0;
  }

  for (vcol = 0; vcol < 9; vcol++) {
    sn = (real_T)vcol * 0.1 + 0.100001;
    st.site = &f_emlrtRSI;
    massF1(&st, par_mex_var, z, sn * unnamed_idx_2, M, T, Dd, fg);
    for (ia = 0; ia < 5; ia++) {
      for (b = 0; b < 6; b++) {
        d = 0.0;
        for (ar = 0; ar < 6; ar++) {
          d += T[ar + 6 * ia] * M[ar + 6 * b];
        }

        TMT_tmp[ia + 5 * b] = d;
      }

      for (b = 0; b < 5; b++) {
        d = 0.0;
        for (ar = 0; ar < 6; ar++) {
          d += TMT_tmp[ia + 5 * ar] * T[ar + 6 * b];
        }

        b_TMT_tmp[ia + 5 * b] = d;
      }
    }

    for (ia = 0; ia < 25; ia++) {
      TMT[ia] += b_TMT_tmp[ia] * unnamed_idx_2;
    }

    for (ia = 0; ia < 30; ia++) {
      Dd[ia] = -Dd[ia];
    }

    for (ia = 0; ia < 6; ia++) {
      d = 0.0;
      for (b = 0; b < 5; b++) {
        d += Dd[ia + 6 * b] * z[b + 5];
      }

      c_Dd[ia] = d + fg[ia];
    }

    for (ia = 0; ia < 5; ia++) {
      d = 0.0;
      for (b = 0; b < 6; b++) {
        d += TMT_tmp[ia + 5 * b] * c_Dd[b];
      }

      TMfd[ia] += d * unnamed_idx_2;
    }

    st.site = &g_emlrtRSI;
    sprdmpF6(&st, par_mex_var, z, sn * par_mex_var[4], Tt, kx, vd, in, &step);
    for (ia = 0; ia < 5; ia++) {
      d = 0.0;
      step = 0.0;
      sn = 0.0;
      for (b = 0; b < 6; b++) {
        d1 = Tt[ia + 5 * b];
        d += d1 * vd[b];
        step += d1 * kx[b];
        sn += d1 * in[b];
      }

      w_vd_j[ia] += d * par_mex_var[4];
      w_sd[ia] += step * par_mex_var[4];
      w_in[ia] += sn * par_mex_var[4];
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  for (ia = 0; ia < 25; ia++) {
    TMT[ia] /= 10.0;
  }

  for (ia = 0; ia < 5; ia++) {
    TMfd[ia] /= 10.0;
    w_vd_j[ia] /= 10.0;
    w_sd[ia] /= 10.0;
    w_in[ia] /= 10.0;
  }

  st.site = &h_emlrtRSI;
  massF2(&st, par_mex_var, z, M, T, Dd, fg);
  for (ia = 0; ia < 5; ia++) {
    for (b = 0; b < 6; b++) {
      d = 0.0;
      for (ar = 0; ar < 6; ar++) {
        d += T[ar + 6 * ia] * M[ar + 6 * b];
      }

      TMT_tmp[ia + 5 * b] = d;
    }

    for (b = 0; b < 5; b++) {
      d = 0.0;
      for (ar = 0; ar < 6; ar++) {
        d += TMT_tmp[ia + 5 * ar] * T[ar + 6 * b];
      }

      vcol = ia + 5 * b;
      b_TMT_tmp[vcol] = TMT[vcol] + d;
    }
  }

  for (ia = 0; ia < 30; ia++) {
    Dd[ia] = -Dd[ia];
  }

  for (ia = 0; ia < 6; ia++) {
    d = 0.0;
    for (b = 0; b < 5; b++) {
      d += Dd[ia + 6 * b] * z[b + 5];
    }

    c_Dd[ia] = d + fg[ia];
  }

  for (ia = 0; ia < 5; ia++) {
    d = 0.0;
    for (b = 0; b < 6; b++) {
      d += TMT_tmp[ia + 5 * b] * c_Dd[b];
    }

    TMfd[ia] += d;
  }

  st.site = &i_emlrtRSI;
  loadsF1(&st, par_mex_var, z, Dd, fg);

  /*  EOM */
  st.site = &j_emlrtRSI;
  b_st.site = &ae_emlrtRSI;
  memset(&C[0], 0, 25U * sizeof(real_T));
  c_st.site = &be_emlrtRSI;
  d_st.site = &he_emlrtRSI;
  e_st.site = &ie_emlrtRSI;
  p = true;
  for (vcol = 0; vcol < 25; vcol++) {
    if ((!p) || (muDoubleScalarIsInf(b_TMT_tmp[vcol]) || muDoubleScalarIsNaN
                 (b_TMT_tmp[vcol]))) {
      p = false;
    }
  }

  if (!p) {
    for (ia = 0; ia < 25; ia++) {
      C[ia] = rtNaN;
    }
  } else {
    c_st.site = &ce_emlrtRSI;
    d_st.site = &le_emlrtRSI;
    e_st.site = &me_emlrtRSI;
    for (ia = 0; ia < 5; ia++) {
      for (b = 0; b < 5; b++) {
        d = 0.0;
        for (ar = 0; ar < 6; ar++) {
          d += TMT_tmp[ia + 5 * ar] * T[ar + 6 * b];
        }

        vcol = ia + 5 * b;
        b_TMT[vcol] = TMT[vcol] + d;
      }
    }

    f_st.site = &ne_emlrtRSI;
    xzsvdc(&f_st, b_TMT, b_TMT_tmp, d_TMT_tmp, TMT);
    c_st.site = &de_emlrtRSI;
    d_st.site = &tf_emlrtRSI;
    step = muDoubleScalarAbs(d_TMT_tmp[0]);
    if ((!muDoubleScalarIsInf(step)) && (!muDoubleScalarIsNaN(step))) {
      if (step <= 2.2250738585072014E-308) {
        step = 4.94065645841247E-324;
      } else {
        frexp(step, &br);
        step = ldexp(1.0, br - 53);
      }
    } else {
      step = rtNaN;
    }

    step *= 5.0;
    r = 0;
    vcol = 0;
    while ((vcol < 5) && (d_TMT_tmp[vcol] > step)) {
      r++;
      vcol++;
    }

    if (r > 0) {
      vcol = 1;
      c_st.site = &ee_emlrtRSI;
      if (r > 2147483646) {
        d_st.site = &ke_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }

      for (j = 0; j < r; j++) {
        c_st.site = &fe_emlrtRSI;
        c_xscal(&c_st, 1.0 / d_TMT_tmp[j], TMT, vcol);
        vcol += 5;
      }

      c_st.site = &ge_emlrtRSI;
      d_st.site = &uf_emlrtRSI;
      for (cr = 0; cr <= 20; cr += 5) {
        vcol = cr + 1;
        j = cr + 5;
        e_st.site = &vf_emlrtRSI;
        if (vcol <= j) {
          memset(&C[vcol + -1], 0, ((j - vcol) + 1) * sizeof(real_T));
        }
      }

      br = 0;
      for (cr = 0; cr <= 20; cr += 5) {
        ar = -1;
        br++;
        j = br + 5 * (r - 1);
        e_st.site = &wf_emlrtRSI;
        if ((br <= j) && (j > 2147483642)) {
          f_st.site = &ke_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        for (ib = br; ib <= j; ib += 5) {
          ia = ar;
          vcol = cr + 1;
          b = cr + 5;
          e_st.site = &xf_emlrtRSI;
          for (ic = vcol; ic <= b; ic++) {
            ia++;
            C[ic - 1] += b_TMT_tmp[ib - 1] * TMT[ia];
          }

          ar += 5;
        }
      }
    }
  }

  for (ia = 0; ia < 5; ia++) {
    d = 0.0;
    for (b = 0; b < 6; b++) {
      d += Dd[ia + 5 * b] * fg[b];
    }

    d_TMT_tmp[ia] = (((TMfd[ia] + w_sd[ia]) + w_in[ia]) + w_vd_j[ia]) + d;
  }

  for (ia = 0; ia < 5; ia++) {
    d = 0.0;
    for (b = 0; b < 5; b++) {
      d += C[ia + 5 * b] * d_TMT_tmp[b];
    }

    dz[ia] = z[ia + 5];
    dz[ia + 5] = d;
  }

  *flag = 0.0;
}

/* End of code generation (EOM.c) */
