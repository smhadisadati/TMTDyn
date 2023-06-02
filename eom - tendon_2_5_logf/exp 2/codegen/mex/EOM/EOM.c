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
#include "interp1.h"
#include "loadsTt1.h"
#include "massM1.h"
#include "massT1.h"
#include "mtimes.h"
#include "pinv.h"
#include "rt_nonfinite.h"
#include "sprdmpKx18.h"
#include "sprdmpTt18.h"
#include "sprdmpVd18.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 6,     /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Friends\\Research\\Tendon Robot - Izad\\Model\\Izad TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 22,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Friends\\Research\\Tendon Robot - Izad\\Model\\Izad TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 23,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Friends\\Research\\Tendon Robot - Izad\\Model\\Izad TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 27,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Friends\\Research\\Tendon Robot - Izad\\Model\\Izad TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 28,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Friends\\Research\\Tendon Robot - Izad\\Model\\Izad TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 30,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Friends\\Research\\Tendon Robot - Izad\\Model\\Izad TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 31,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Friends\\Research\\Tendon Robot - Izad\\Model\\Izad TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 32,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Friends\\Research\\Tendon Robot - Izad\\Model\\Izad TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 41,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Friends\\Research\\Tendon Robot - Izad\\Model\\Izad TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 42,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Friends\\Research\\Tendon Robot - Izad\\Model\\Izad TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 46,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Friends\\Research\\Tendon Robot - Izad\\Model\\Izad TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 47,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Friends\\Research\\Tendon Robot - Izad\\Model\\Izad TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 49,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Friends\\Research\\Tendon Robot - Izad\\Model\\Izad TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 50,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Friends\\Research\\Tendon Robot - Izad\\Model\\Izad TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 51,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Friends\\Research\\Tendon Robot - Izad\\Model\\Izad TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 64,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Friends\\Research\\Tendon Robot - Izad\\Model\\Izad TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 65,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Friends\\Research\\Tendon Robot - Izad\\Model\\Izad TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 69,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Friends\\Research\\Tendon Robot - Izad\\Model\\Izad TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 70,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Friends\\Research\\Tendon Robot - Izad\\Model\\Izad TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 72,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Friends\\Research\\Tendon Robot - Izad\\Model\\Izad TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 73,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Friends\\Research\\Tendon Robot - Izad\\Model\\Izad TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 74,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Friends\\Research\\Tendon Robot - Izad\\Model\\Izad TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 87,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Friends\\Research\\Tendon Robot - Izad\\Model\\Izad TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 88,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Friends\\Research\\Tendon Robot - Izad\\Model\\Izad TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 99,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Friends\\Research\\Tendon Robot - Izad\\Model\\Izad TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 4,  /* lineNo */
  "dyn_mid_step",                      /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Friends\\Research\\Tendon Robot - Izad\\Model\\Izad TMTDyn\\eom\\user_codes\\dyn_mid_step.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 28, /* lineNo */
  "dyn_mid_step",                      /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Friends\\Research\\Tendon Robot - Izad\\Model\\Izad TMTDyn\\eom\\user_codes\\dyn_mid_step.m"/* pathName */
};

static emlrtRSInfo ub_emlrtRSI = { 79, /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pathName */
};

static emlrtRSInfo qe_emlrtRSI = { 47, /* lineNo */
  "loadsFtau1",                        /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Friends\\Research\\Tendon Robot - Izad\\Model\\Izad TMTDyn\\eom\\loadsFtau1.m"/* pathName */
};

static emlrtRSInfo re_emlrtRSI = { 48, /* lineNo */
  "loadsFtau1",                        /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Friends\\Research\\Tendon Robot - Izad\\Model\\Izad TMTDyn\\eom\\loadsFtau1.m"/* pathName */
};

static emlrtRSInfo se_emlrtRSI = { 83, /* lineNo */
  "loadsFtau1",                        /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Friends\\Research\\Tendon Robot - Izad\\Model\\Izad TMTDyn\\eom\\loadsFtau1.m"/* pathName */
};

static emlrtRSInfo te_emlrtRSI = { 112,/* lineNo */
  "loadsFtau1",                        /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Friends\\Research\\Tendon Robot - Izad\\Model\\Izad TMTDyn\\eom\\loadsFtau1.m"/* pathName */
};

static emlrtRSInfo ue_emlrtRSI = { 113,/* lineNo */
  "loadsFtau1",                        /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Friends\\Research\\Tendon Robot - Izad\\Model\\Izad TMTDyn\\eom\\loadsFtau1.m"/* pathName */
};

static emlrtRSInfo ve_emlrtRSI = { 114,/* lineNo */
  "loadsFtau1",                        /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Friends\\Research\\Tendon Robot - Izad\\Model\\Izad TMTDyn\\eom\\loadsFtau1.m"/* pathName */
};

static emlrtRSInfo we_emlrtRSI = { 116,/* lineNo */
  "loadsFtau1",                        /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Friends\\Research\\Tendon Robot - Izad\\Model\\Izad TMTDyn\\eom\\loadsFtau1.m"/* pathName */
};

static emlrtRSInfo xe_emlrtRSI = { 119,/* lineNo */
  "loadsFtau1",                        /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Friends\\Research\\Tendon Robot - Izad\\Model\\Izad TMTDyn\\eom\\loadsFtau1.m"/* pathName */
};

/* Function Definitions */
void EOM(const emlrtStack *sp, real_T t, const real_T z[34], const struct0_T
         *par_mex, real_T dz[34], real_T *flag)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T varargin_2[8535];
  real_T varargin_1[1707];
  real_T TMT[289];
  real_T d_y[289];
  real_T T[102];
  real_T Tt[102];
  real_T b_y[102];
  real_T y[102];
  real_T M[36];
  real_T par_mex_var[27];
  real_T TMfd[17];
  real_T c_y[17];
  real_T w_in[17];
  real_T w_sd[17];
  real_T w_vd_j[17];
  real_T b_tmp[6];
  real_T kx[6];
  real_T vd[6];
  real_T q_u[5];
  real_T f_t[3];
  real_T b_y1;
  real_T phi;
  real_T t14;
  real_T t15;
  real_T t2;
  real_T t52;
  real_T t56;
  real_T t6;
  real_T t78;
  real_T xtmp;
  real_T y2;
  int32_T exitg1;
  int32_T high_i;
  int32_T j;
  int32_T low_i;
  int32_T mid_i;
  int32_T offset;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  memcpy(&par_mex_var[0], &par_mex->var[0], 27U * sizeof(real_T));

  /*  inputs positions */
  b_st.site = &ab_emlrtRSI;
  memcpy(&varargin_1[0], &par_mex->user_pars.motor_in.pos[0], 1707U * sizeof
         (real_T));
  for (mid_i = 0; mid_i < 5; mid_i++) {
    memcpy(&varargin_2[mid_i * 1707], &par_mex->user_pars.motor_in.pos[mid_i *
           1707 + 1707], 1707U * sizeof(real_T));
  }

  c_st.site = &cb_emlrtRSI;
  low_i = 0;
  do {
    exitg1 = 0;
    if (low_i < 1707) {
      if (muDoubleScalarIsNaN(par_mex->user_pars.motor_in.pos[low_i])) {
        emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI, "MATLAB:interp1:NaNinX",
          "MATLAB:interp1:NaNinX", 0);
      } else {
        low_i++;
      }
    } else {
      if (par_mex->user_pars.motor_in.pos[1] < par_mex->user_pars.motor_in.pos[0])
      {
        for (high_i = 0; high_i < 853; high_i++) {
          xtmp = varargin_1[high_i];
          varargin_1[high_i] = varargin_1[1706 - high_i];
          varargin_1[1706 - high_i] = xtmp;
        }

        for (j = 0; j < 5; j++) {
          offset = j * 1707 + 1707;
          for (low_i = 0; low_i < 853; low_i++) {
            high_i = (offset + low_i) - 1707;
            xtmp = varargin_2[high_i];
            mid_i = (offset - low_i) - 1;
            varargin_2[high_i] = varargin_2[mid_i];
            varargin_2[mid_i] = xtmp;
          }
        }
      }

      for (low_i = 0; low_i < 1706; low_i++) {
        if (varargin_1[low_i + 1] <= varargin_1[low_i]) {
          emlrtErrorWithMessageIdR2018a(&c_st, &b_emlrtRTEI,
            "Coder:toolbox:interp1_nonMonotonicX",
            "Coder:toolbox:interp1_nonMonotonicX", 0);
        }
      }

      for (mid_i = 0; mid_i < 5; mid_i++) {
        q_u[mid_i] = 0.0;
      }

      if (muDoubleScalarIsNaN(t)) {
        for (j = 0; j < 5; j++) {
          q_u[j] = rtNaN;
        }
      } else {
        if ((!(t > varargin_1[1706])) && (!(t < varargin_1[0]))) {
          low_i = 1;
          offset = 2;
          high_i = 1707;
          while (high_i > offset) {
            mid_i = (low_i + high_i) >> 1;
            if (t >= varargin_1[mid_i - 1]) {
              low_i = mid_i;
              offset = mid_i + 1;
            } else {
              high_i = mid_i;
            }
          }

          xtmp = varargin_1[low_i - 1];
          xtmp = (t - xtmp) / (varargin_1[low_i] - xtmp);
          if (xtmp == 0.0) {
            for (j = 0; j < 5; j++) {
              q_u[j] = varargin_2[(low_i + j * 1707) - 1];
            }
          } else if (xtmp == 1.0) {
            for (j = 0; j < 5; j++) {
              q_u[j] = varargin_2[low_i + j * 1707];
            }
          } else {
            for (j = 0; j < 5; j++) {
              offset = low_i + j * 1707;
              b_y1 = varargin_2[offset - 1];
              y2 = varargin_2[offset];
              if (b_y1 == y2) {
                q_u[j] = b_y1;
              } else {
                q_u[j] = (1.0 - xtmp) * b_y1 + xtmp * y2;
              }
            }
          }
        }
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);

  /*  curvature inputs */
  /*  wire offsets diameter: 2*(r_s21+r_s22)/2 */
  b_y1 = q_u[0] / 2.0 + par_mex_var[16];
  xtmp = q_u[1] / 2.0 + par_mex_var[16];

  /*  /2 because of tendon pair  */
  /*  % 3 tendons */
  /*  kappa = 2*sqrt(l(1)^2+l(2)^2+l(3)^2-l(1)*l(2)-l(1)*l(3)-l(2)*l(3))/(d*(l(1)+l(2)+l(3))); */
  /*  phi = atan2(sqrt(3)*(l(2)+l(3)-2*l(1)),(3*(l(2)-l(3)))); */
  /*  4 tendons */
  y2 = (((b_y1 + xtmp) + (q_u[2] / 2.0 + par_mex_var[16])) + (q_u[3] / 2.0 +
         par_mex_var[16])) / 4.0;

  /*  l_b = l_s2; */
  phi = muDoubleScalarAtan2(xtmp - y2, b_y1 - y2);
  t52 = muDoubleScalarCos(phi);
  xtmp = (y2 - b_y1) / (y2 * (par_mex_var[8] + par_mex_var[9]) / 2.0 * t52);

  /*  model inputs */
  /*  inner (introducer) tube lengths */
  /*  introducer load */
  b_st.site = &bb_emlrtRSI;
  interp1(&b_st, *(real_T (*)[1710])&par_mex->user_pars.tip_load[0], *(real_T (*)
           [5130])&par_mex->user_pars.tip_load[1710], t, f_t);

  /*  at introducer tip */
  /*  l_ex = l_s(2) ; % at catheter tip */
  /*  update par */
  par_mex_var[17] = par_mex_var[15] + q_u[4];
  par_mex_var[18] = q_u[4];
  par_mex_var[19] = xtmp * muDoubleScalarSin(phi);
  par_mex_var[20] = xtmp * t52;
  par_mex_var[21] = f_t[0];
  par_mex_var[22] = f_t[1];
  par_mex_var[23] = f_t[2];

  /* ROMF */
  /*     [OUT1,OUT2] = ROMF(IN1,IN2,S,DS,T_SYM) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
  /*     30-Apr-2021 16:05:34 */
  t2 = q_u[4] + par_mex_var[15];
  st.site = &b_emlrtRSI;
  massM1(par_mex_var, M);
  st.site = &c_emlrtRSI;
  massT1(&st, par_mex_var, z, 1.0E-6 * t2, T);

  /* MASSFG1 */
  /*     OUT1 = MASSFG1(IN1,IN2,S,DS,T_SYM) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
  /*     30-Apr-2021 15:46:29 */
  for (mid_i = 0; mid_i < 6; mid_i++) {
    for (low_i = 0; low_i < 17; low_i++) {
      Tt[low_i + 17 * mid_i] = T[mid_i + 6 * low_i];
    }
  }

  st.site = &d_emlrtRSI;
  b_st.site = &ub_emlrtRSI;
  mtimes(Tt, M, y);
  st.site = &d_emlrtRSI;
  b_st.site = &ub_emlrtRSI;
  b_mtimes(y, T, TMT);
  st.site = &e_emlrtRSI;
  b_st.site = &ub_emlrtRSI;
  mtimes(Tt, M, y);
  kx[0] = par_mex_var[12];
  kx[1] = par_mex_var[13];
  kx[2] = par_mex_var[14];
  kx[3] = 0.0;
  kx[4] = 0.0;
  kx[5] = 0.0;
  for (mid_i = 0; mid_i < 6; mid_i++) {
    t56 = 0.0;
    for (low_i = 0; low_i < 17; low_i++) {
      t56 += -0.0 * z[low_i + 17];
    }

    b_tmp[mid_i] = t56 + kx[mid_i];
  }

  st.site = &f_emlrtRSI;
  sprdmpTt18(&st, par_mex_var, z, 1.0E-6 * t2, Tt);
  st.site = &g_emlrtRSI;
  sprdmpKx18(&st, par_mex_var, z, 1.0E-6 * t2, kx);
  st.site = &h_emlrtRSI;
  sprdmpVd18(&st, par_mex_var, z, 1.0E-6 * t2, vd);
  for (mid_i = 0; mid_i < 17; mid_i++) {
    t56 = 0.0;
    xtmp = 0.0;
    b_y1 = 0.0;
    for (low_i = 0; low_i < 6; low_i++) {
      y2 = Tt[mid_i + 17 * low_i];
      t56 += y2 * vd[low_i];
      xtmp += y2 * kx[low_i];
      b_y1 += y2 * 0.0;
    }

    c_y[mid_i] = b_y1;
    w_sd[mid_i] = xtmp;
    w_in[mid_i] = t56;
  }

  st.site = &i_emlrtRSI;
  massM1(par_mex_var, M);
  st.site = &j_emlrtRSI;
  massT1(&st, par_mex_var, z, 0.999999 * t2, T);
  for (mid_i = 0; mid_i < 6; mid_i++) {
    for (low_i = 0; low_i < 17; low_i++) {
      Tt[low_i + 17 * mid_i] = T[mid_i + 6 * low_i];
    }
  }

  st.site = &k_emlrtRSI;
  b_st.site = &ub_emlrtRSI;
  mtimes(Tt, M, b_y);
  st.site = &k_emlrtRSI;
  b_st.site = &ub_emlrtRSI;
  b_mtimes(b_y, T, d_y);
  st.site = &l_emlrtRSI;
  b_st.site = &ub_emlrtRSI;
  mtimes(Tt, M, b_y);
  st.site = &m_emlrtRSI;
  sprdmpTt18(&st, par_mex_var, z, 0.999999 * t2, Tt);
  st.site = &n_emlrtRSI;
  sprdmpKx18(&st, par_mex_var, z, 0.999999 * t2, kx);
  st.site = &o_emlrtRSI;
  sprdmpVd18(&st, par_mex_var, z, 0.999999 * t2, vd);
  for (mid_i = 0; mid_i < 289; mid_i++) {
    TMT[mid_i] = (TMT[mid_i] * t2 + d_y[mid_i] * t2) / 2.0;
  }

  for (mid_i = 0; mid_i < 17; mid_i++) {
    t56 = 0.0;
    xtmp = 0.0;
    b_y1 = 0.0;
    y2 = 0.0;
    phi = 0.0;
    for (low_i = 0; low_i < 6; low_i++) {
      offset = mid_i + 17 * low_i;
      t52 = b_tmp[low_i];
      t56 += y[offset] * t52;
      xtmp += b_y[offset] * t52;
      t52 = Tt[offset];
      b_y1 += t52 * vd[low_i];
      y2 += t52 * kx[low_i];
      phi += t52 * 0.0;
    }

    TMfd[mid_i] = (t56 * t2 + xtmp * t2) / 2.0;
    w_vd_j[mid_i] = (w_in[mid_i] * t2 + b_y1 * t2) / 2.0;
    w_sd[mid_i] = (w_sd[mid_i] * t2 + y2 * t2) / 2.0;
    w_in[mid_i] = (c_y[mid_i] * t2 + phi * t2) / 2.0;
  }

  for (high_i = 0; high_i < 9; high_i++) {
    xtmp = (real_T)high_i * 0.1 + 0.100001;
    st.site = &p_emlrtRSI;
    massM1(par_mex_var, M);
    st.site = &q_emlrtRSI;
    massT1(&st, par_mex_var, z, xtmp * t2, T);
    for (mid_i = 0; mid_i < 6; mid_i++) {
      for (low_i = 0; low_i < 17; low_i++) {
        Tt[low_i + 17 * mid_i] = T[mid_i + 6 * low_i];
      }
    }

    st.site = &r_emlrtRSI;
    b_st.site = &ub_emlrtRSI;
    mtimes(Tt, M, y);
    st.site = &r_emlrtRSI;
    b_st.site = &ub_emlrtRSI;
    b_mtimes(y, T, d_y);
    for (mid_i = 0; mid_i < 289; mid_i++) {
      TMT[mid_i] += d_y[mid_i] * t2;
    }

    st.site = &s_emlrtRSI;
    b_st.site = &ub_emlrtRSI;
    mtimes(Tt, M, y);
    for (mid_i = 0; mid_i < 17; mid_i++) {
      t56 = 0.0;
      for (low_i = 0; low_i < 6; low_i++) {
        t56 += y[mid_i + 17 * low_i] * b_tmp[low_i];
      }

      TMfd[mid_i] += t56 * t2;
    }

    st.site = &t_emlrtRSI;
    sprdmpTt18(&st, par_mex_var, z, xtmp * t2, Tt);
    st.site = &u_emlrtRSI;
    sprdmpKx18(&st, par_mex_var, z, xtmp * t2, kx);
    st.site = &v_emlrtRSI;
    sprdmpVd18(&st, par_mex_var, z, xtmp * t2, vd);
    for (mid_i = 0; mid_i < 17; mid_i++) {
      t56 = 0.0;
      xtmp = 0.0;
      b_y1 = 0.0;
      for (low_i = 0; low_i < 6; low_i++) {
        y2 = Tt[mid_i + 17 * low_i];
        t56 += y2 * vd[low_i];
        xtmp += y2 * kx[low_i];
        b_y1 += y2 * 0.0;
      }

      w_vd_j[mid_i] += t56 * t2;
      w_sd[mid_i] += xtmp * t2;
      w_in[mid_i] += b_y1 * t2;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  for (mid_i = 0; mid_i < 289; mid_i++) {
    TMT[mid_i] /= 10.0;
  }

  for (mid_i = 0; mid_i < 17; mid_i++) {
    TMfd[mid_i] /= 10.0;
    w_vd_j[mid_i] /= 10.0;
    w_sd[mid_i] /= 10.0;
    w_in[mid_i] /= 10.0;
  }

  st.site = &w_emlrtRSI;
  loadsTt1(&st, par_mex_var, z, Tt);
  memcpy(&T[0], &Tt[0], 102U * sizeof(real_T));
  st.site = &x_emlrtRSI;

  /* LOADSFTAU1 */
  /*     OUT1 = LOADSFTAU1(IN1,IN2,S,DS,T_SYM) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
  /*     30-Apr-2021 15:59:38 */
  t2 = par_mex_var[17] * z[1];
  phi = par_mex_var[17] * z[5];
  t6 = par_mex_var[17] * z[9];
  b_y1 = par_mex_var[17] * z[14];
  t14 = par_mex_var[17] * 2.0;
  t15 = par_mex_var[16] * 2.0;
  b_st.site = &qe_emlrtRSI;
  y2 = par_mex_var[17] * par_mex_var[17];
  b_st.site = &re_emlrtRSI;
  xtmp = par_mex_var[17] + -par_mex_var[16];
  b_st.site = &se_emlrtRSI;
  t52 = xtmp * xtmp;
  t56 = 1.0 / (muDoubleScalarExp(par_mex_var[16] * 200.0 + -(par_mex_var[17] *
    200.0)) + 1.0);
  b_y1 = ((par_mex_var[17] * z[12] / 2.0 + z[13] * y2 / 2.0) + b_y1 * y2 / 2.0)
    + -(t52 * t56 * (((((z[13] + b_y1) + par_mex_var[16] * z[16]) + z[14] * t15)
                      + -z[15]) + -(par_mex_var[17] * z[16])) / 2.0);
  xtmp = (t14 + -t15) * t56;
  t78 = ((z[0] * t14 + par_mex_var[17] * t2 * 3.0) + -((z[1] + -z[3]) * t52 *
          t56)) + -(xtmp * (((((z[0] + t2) + par_mex_var[16] * z[3]) + z[1] *
    t15) + -z[2]) + -(par_mex_var[17] * z[3])));
  t2 = ((z[4] * t14 + par_mex_var[17] * phi * 3.0) + -((z[5] + -z[7]) * t52 *
         t56)) + -(xtmp * (((((z[4] + phi) + par_mex_var[16] * z[7]) + z[5] *
    t15) + -z[6]) + -(par_mex_var[17] * z[7])));
  xtmp = (((z[8] * t14 + par_mex_var[17] * t6 * 3.0) + -((z[9] + -z[11]) * t52 *
            t56)) + -(xtmp * (((((z[8] + t6) + par_mex_var[16] * z[11]) + z[9] *
              t15) + -z[10]) + -(par_mex_var[17] * z[11])))) + 1.0;
  t52 = muDoubleScalarCos(b_y1);
  phi = muDoubleScalarSin(b_y1);
  b_st.site = &te_emlrtRSI;
  b_st.site = &ue_emlrtRSI;
  b_st.site = &ve_emlrtRSI;
  t56 = (t78 * t78 + t2 * t2) + xtmp * xtmp;
  b_st.site = &we_emlrtRSI;
  if (t56 < 0.0) {
    emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  t56 = muDoubleScalarSqrt(t56);
  y2 = 1.0 / t56;
  xtmp = xtmp * y2 / 2.0 + 0.5;
  b_st.site = &xe_emlrtRSI;
  if (xtmp < 0.0) {
    emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  xtmp = muDoubleScalarSqrt(xtmp);
  b_y1 = 1.0 / xtmp;
  t14 = t52 * xtmp;
  t56 = phi * xtmp;
  t6 = phi * t2 * y2 * b_y1 / 2.0 + t52 * t78 * y2 * b_y1 / 2.0;
  xtmp = phi * t78 * y2 * b_y1 / 2.0 + -(t52 * t2 * y2 * b_y1 / 2.0);
  b_y1 = (t14 * par_mex_var[24] + t56 * par_mex_var[25]) + -(t6 * par_mex_var[26]);
  y2 = (t56 * par_mex_var[26] + t6 * par_mex_var[25]) + xtmp * par_mex_var[24];
  phi = (t14 * par_mex_var[26] + t6 * par_mex_var[24]) + -(xtmp * par_mex_var[25]);

  /*  EOM via jacobian inversion */
  st.site = &y_emlrtRSI;
  pinv(&st, TMT, d_y);
  kx[0] = f_t[0];
  kx[1] = f_t[1];
  kx[2] = f_t[2];
  t52 = (t14 * par_mex_var[25] - t56 * par_mex_var[24]) + xtmp * par_mex_var[26];
  kx[3] = ((-t6 * phi + xtmp * y2) + t56 * t52) + t14 * b_y1;
  kx[4] = ((t6 * y2 + xtmp * phi) + t14 * t52) - t56 * b_y1;
  kx[5] = ((t6 * b_y1 - xtmp * t52) + t14 * phi) + t56 * y2;
  for (mid_i = 0; mid_i < 17; mid_i++) {
    t56 = 0.0;
    for (low_i = 0; low_i < 6; low_i++) {
      t56 += T[mid_i + 17 * low_i] * kx[low_i];
    }

    xtmp = 0.0;
    for (low_i = 0; low_i < 17; low_i++) {
      xtmp += 1.0E-18 * TMT[mid_i + 17 * low_i] * z[low_i + 17];
    }

    c_y[mid_i] = ((((TMfd[mid_i] + w_sd[mid_i]) + w_in[mid_i]) + w_vd_j[mid_i])
                  + t56) - xtmp;
  }

  for (mid_i = 0; mid_i < 17; mid_i++) {
    t56 = 0.0;
    for (low_i = 0; low_i < 17; low_i++) {
      t56 += d_y[mid_i + 17 * low_i] * c_y[low_i];
    }

    dz[mid_i] = z[mid_i + 17];
    dz[mid_i + 17] = t56;
  }

  *flag = 0.0;
}

/* End of code generation (EOM.c) */
