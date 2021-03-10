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
#include "dyn_mid_step.h"
#include "massF1.h"
#include "massF2.h"
#include "massF3.h"
#include "massF4.h"
#include "massF5.h"
#include "mtimes.h"
#include "pinv.h"
#include "romF.h"
#include "rt_nonfinite.h"
#include "sprdmpF25.h"
#include "sprdmpF26.h"
#include "sprdmpF27.h"
#include "sprdmpF28.h"
#include "sprdmpF29.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 6,     /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 22,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 24,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 25,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 27,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 29,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 30,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 32,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 34,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 35,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 37,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 39,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 40,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 42,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 44,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 45,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 47,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 52,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 57,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 62,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 67,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 74,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 76,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 77,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 79,  /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 81, /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 82, /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo cb_emlrtRSI = { 84, /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo db_emlrtRSI = { 86, /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo eb_emlrtRSI = { 87, /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo fb_emlrtRSI = { 89, /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 91, /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo hb_emlrtRSI = { 92, /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo ib_emlrtRSI = { 94, /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo jb_emlrtRSI = { 96, /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo kb_emlrtRSI = { 97, /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo lb_emlrtRSI = { 99, /* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo mb_emlrtRSI = { 104,/* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo nb_emlrtRSI = { 109,/* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo ob_emlrtRSI = { 114,/* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo pb_emlrtRSI = { 119,/* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo qb_emlrtRSI = { 130,/* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo rb_emlrtRSI = { 132,/* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo sb_emlrtRSI = { 133,/* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo tb_emlrtRSI = { 135,/* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo ub_emlrtRSI = { 137,/* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo vb_emlrtRSI = { 138,/* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo wb_emlrtRSI = { 140,/* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo xb_emlrtRSI = { 142,/* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo yb_emlrtRSI = { 143,/* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo ac_emlrtRSI = { 145,/* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo bc_emlrtRSI = { 147,/* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo cc_emlrtRSI = { 148,/* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo dc_emlrtRSI = { 150,/* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo ec_emlrtRSI = { 152,/* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo fc_emlrtRSI = { 153,/* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo gc_emlrtRSI = { 155,/* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo hc_emlrtRSI = { 160,/* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo ic_emlrtRSI = { 165,/* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo jc_emlrtRSI = { 170,/* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo kc_emlrtRSI = { 175,/* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

static emlrtRSInfo lc_emlrtRSI = { 192,/* lineNo */
  "EOM",                               /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\EOM.m"/* pathName */
};

/* Function Definitions */
void EOM(EOMStackData *SD, const emlrtStack *sp, real_T t, const real_T z[48],
         const struct0_T *par_mex, real_T dz[48], real_T *flag)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T TMT[576];
  real_T b_y[576];
  real_T d_y[576];
  real_T f_y[576];
  real_T h_y[576];
  real_T l_y[576];
  real_T n_y[576];
  real_T p_y[576];
  real_T r_y[576];
  real_T t_y[576];
  real_T Dd[144];
  real_T T[144];
  real_T Tt[144];
  real_T b_Tt[144];
  real_T c_Dd[144];
  real_T c_Tt[144];
  real_T c_y[144];
  real_T d_Dd[144];
  real_T d_Tt[144];
  real_T e_Dd[144];
  real_T e_Tt[144];
  real_T e_y[144];
  real_T f_Dd[144];
  real_T g_Dd[144];
  real_T g_y[144];
  real_T h_Dd[144];
  real_T i_Dd[144];
  real_T k_y[144];
  real_T m_y[144];
  real_T o_y[144];
  real_T q_y[144];
  real_T s_y[144];
  real_T y[144];
  real_T rom_sprdmp[87];
  real_T M[36];
  real_T TMfd[24];
  real_T ab_y[24];
  real_T i_y[24];
  real_T j_y[24];
  real_T u_y[24];
  real_T v_y[24];
  real_T w_in[24];
  real_T w_sd[24];
  real_T w_vd_j[24];
  real_T w_y[24];
  real_T x_y[24];
  real_T y_y[24];
  real_T rom_mass[10];
  real_T b_Dd[6];
  real_T b_fg[6];
  real_T b_in[6];
  real_T b_kx[6];
  real_T b_vd[6];
  real_T c_fg[6];
  real_T c_in[6];
  real_T c_kx[6];
  real_T c_vd[6];
  real_T d_fg[6];
  real_T d_in[6];
  real_T d_kx[6];
  real_T d_vd[6];
  real_T e_fg[6];
  real_T e_in[6];
  real_T e_kx[6];
  real_T e_vd[6];
  real_T f_fg[6];
  real_T f_in[6];
  real_T f_vd[6];
  real_T fg[6];
  real_T g_fg[6];
  real_T h_fg[6];
  real_T i_fg[6];
  real_T in[6];
  real_T kx[6];
  real_T vd[6];
  real_T b_b_tmp;
  real_T b_tmp;
  real_T c_b_tmp;
  real_T d;
  real_T d1;
  real_T d10;
  real_T d11;
  real_T d12;
  real_T d13;
  real_T d14;
  real_T d15;
  real_T d16;
  real_T d17;
  real_T d18;
  real_T d19;
  real_T d2;
  real_T d20;
  real_T d21;
  real_T d22;
  real_T d23;
  real_T d24;
  real_T d25;
  real_T d26;
  real_T d27;
  real_T d28;
  real_T d29;
  real_T d3;
  real_T d30;
  real_T d31;
  real_T d32;
  real_T d33;
  real_T d4;
  real_T d5;
  real_T d6;
  real_T d7;
  real_T d8;
  real_T d9;
  real_T d_b_tmp;
  real_T dir;
  real_T e_b_tmp;
  real_T f_b_tmp;
  real_T sn;
  int32_T b_i;
  int32_T i;
  int32_T i1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  SD->f0.par_mex = *par_mex;
  st.site = &emlrtRSI;
  dyn_mid_step(&st, t, &SD->f0.par_mex);
  romF(SD->f0.par_mex.var, rom_mass, rom_sprdmp);
  st.site = &b_emlrtRSI;
  massF1(SD->f0.par_mex.var, z, 1.0E-6 * rom_mass[5], M, T, Dd, fg);
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 24; i1++) {
      Tt[i1 + 24 * i] = T[i + 6 * i1];
    }
  }

  st.site = &c_emlrtRSI;
  mtimes(Tt, M, y);
  st.site = &c_emlrtRSI;
  b_mtimes(y, T, TMT);
  st.site = &d_emlrtRSI;
  mtimes(Tt, M, y);
  for (i = 0; i < 144; i++) {
    Dd[i] = -Dd[i];
  }

  for (i = 0; i < 6; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 24; i1++) {
      d += Dd[i + 6 * i1] * z[i1 + 24];
    }

    b_Dd[i] = d + fg[i];
  }

  for (i = 0; i < 24; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      d += y[i + 24 * i1] * b_Dd[i1];
    }

    w_in[i] = d;
  }

  st.site = &e_emlrtRSI;
  massF2(&st, SD->f0.par_mex.var, z, 1.0E-6 * rom_mass[6], M, T, Dd, fg);
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 24; i1++) {
      Tt[i1 + 24 * i] = T[i + 6 * i1];
    }
  }

  st.site = &f_emlrtRSI;
  mtimes(Tt, M, y);
  st.site = &f_emlrtRSI;
  b_mtimes(y, T, b_y);
  st.site = &g_emlrtRSI;
  mtimes(Tt, M, y);
  for (i = 0; i < 144; i++) {
    Dd[i] = -Dd[i];
  }

  for (i = 0; i < 6; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 24; i1++) {
      d += Dd[i + 6 * i1] * z[i1 + 24];
    }

    b_Dd[i] = d;
  }

  st.site = &h_emlrtRSI;
  massF3(&st, SD->f0.par_mex.var, z, 1.0E-6 * rom_mass[7], M, T, Dd, b_fg);
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 24; i1++) {
      Tt[i1 + 24 * i] = T[i + 6 * i1];
    }
  }

  st.site = &i_emlrtRSI;
  mtimes(Tt, M, c_y);
  st.site = &i_emlrtRSI;
  b_mtimes(c_y, T, d_y);
  st.site = &j_emlrtRSI;
  mtimes(Tt, M, c_y);
  st.site = &k_emlrtRSI;
  massF4(SD->f0.par_mex.var, z, 1.0E-6 * (rom_mass[8] - rom_mass[3]) + rom_mass
         [3], M, T, c_Dd, c_fg);
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 24; i1++) {
      Tt[i1 + 24 * i] = T[i + 6 * i1];
    }
  }

  st.site = &l_emlrtRSI;
  mtimes(Tt, M, e_y);
  st.site = &l_emlrtRSI;
  b_mtimes(e_y, T, f_y);
  b_tmp = rom_mass[8] - rom_mass[3];
  st.site = &m_emlrtRSI;
  mtimes(Tt, M, e_y);
  st.site = &n_emlrtRSI;
  massF5(&st, SD->f0.par_mex.var, z, 1.0E-6 * rom_mass[9], M, T, d_Dd, d_fg);
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 24; i1++) {
      Tt[i1 + 24 * i] = T[i + 6 * i1];
    }
  }

  st.site = &o_emlrtRSI;
  mtimes(Tt, M, g_y);
  st.site = &o_emlrtRSI;
  b_mtimes(g_y, T, h_y);
  st.site = &p_emlrtRSI;
  mtimes(Tt, M, g_y);
  st.site = &q_emlrtRSI;
  sprdmpF25(SD->f0.par_mex.var, z, 1.0E-6 * (rom_sprdmp[53] - rom_sprdmp[24]) +
            rom_sprdmp[24], Tt, kx, vd, in, &dir);
  b_b_tmp = rom_sprdmp[53] - rom_sprdmp[24];
  for (i = 0; i < 24; i++) {
    d = 0.0;
    d1 = 0.0;
    d2 = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      d3 = Tt[i + 24 * i1];
      d += d3 * vd[i1];
      d1 += d3 * kx[i1];
      d2 += d3 * in[i1];
    }

    i_y[i] = d2;
    j_y[i] = d1;
    w_sd[i] = d;
  }

  st.site = &r_emlrtRSI;
  sprdmpF26(&st, SD->f0.par_mex.var, z, 1.0E-6 * (rom_sprdmp[54] - rom_sprdmp[25])
            + rom_sprdmp[25], b_Tt, kx, vd, in, &dir);
  c_b_tmp = rom_sprdmp[54] - rom_sprdmp[25];
  st.site = &s_emlrtRSI;
  sprdmpF27(&st, SD->f0.par_mex.var, z, 1.0E-6 * (rom_sprdmp[55] - rom_sprdmp[26])
            + rom_sprdmp[26], c_Tt, b_kx, b_vd, b_in, &dir);
  d_b_tmp = rom_sprdmp[55] - rom_sprdmp[26];
  st.site = &t_emlrtRSI;
  sprdmpF28(SD->f0.par_mex.var, z, 1.0E-6 * (rom_sprdmp[56] - rom_sprdmp[27]) +
            rom_sprdmp[27], d_Tt, c_kx, c_vd, c_in, &dir);
  e_b_tmp = rom_sprdmp[56] - rom_sprdmp[27];
  st.site = &u_emlrtRSI;
  sprdmpF29(&st, SD->f0.par_mex.var, z, 1.0E-6 * (rom_sprdmp[57] - rom_sprdmp[28])
            + rom_sprdmp[28], e_Tt, d_kx, d_vd, d_in, &dir);
  f_b_tmp = rom_sprdmp[57] - rom_sprdmp[28];
  st.site = &v_emlrtRSI;
  massF1(SD->f0.par_mex.var, z, 0.999999 * rom_mass[5], M, T, e_Dd, e_fg);
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 24; i1++) {
      Tt[i1 + 24 * i] = T[i + 6 * i1];
    }
  }

  st.site = &w_emlrtRSI;
  mtimes(Tt, M, k_y);
  st.site = &w_emlrtRSI;
  b_mtimes(k_y, T, l_y);
  st.site = &x_emlrtRSI;
  mtimes(Tt, M, k_y);
  st.site = &y_emlrtRSI;
  massF2(&st, SD->f0.par_mex.var, z, 0.999999 * rom_mass[6], M, T, f_Dd, f_fg);
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 24; i1++) {
      Tt[i1 + 24 * i] = T[i + 6 * i1];
    }
  }

  st.site = &ab_emlrtRSI;
  mtimes(Tt, M, m_y);
  st.site = &ab_emlrtRSI;
  b_mtimes(m_y, T, n_y);
  st.site = &bb_emlrtRSI;
  mtimes(Tt, M, m_y);
  st.site = &cb_emlrtRSI;
  massF3(&st, SD->f0.par_mex.var, z, 0.999999 * rom_mass[7], M, T, g_Dd, g_fg);
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 24; i1++) {
      Tt[i1 + 24 * i] = T[i + 6 * i1];
    }
  }

  st.site = &db_emlrtRSI;
  mtimes(Tt, M, o_y);
  st.site = &db_emlrtRSI;
  b_mtimes(o_y, T, p_y);
  st.site = &eb_emlrtRSI;
  mtimes(Tt, M, o_y);
  st.site = &fb_emlrtRSI;
  massF4(SD->f0.par_mex.var, z, 0.999999 * (rom_mass[8] - rom_mass[3]) +
         rom_mass[3], M, T, h_Dd, h_fg);
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 24; i1++) {
      Tt[i1 + 24 * i] = T[i + 6 * i1];
    }
  }

  st.site = &gb_emlrtRSI;
  mtimes(Tt, M, q_y);
  st.site = &gb_emlrtRSI;
  b_mtimes(q_y, T, r_y);
  st.site = &hb_emlrtRSI;
  mtimes(Tt, M, q_y);
  st.site = &ib_emlrtRSI;
  massF5(&st, SD->f0.par_mex.var, z, 0.999999 * rom_mass[9], M, T, i_Dd, i_fg);
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 24; i1++) {
      Tt[i1 + 24 * i] = T[i + 6 * i1];
    }
  }

  st.site = &jb_emlrtRSI;
  mtimes(Tt, M, s_y);
  st.site = &jb_emlrtRSI;
  b_mtimes(s_y, T, t_y);
  d = rom_mass[5];
  d1 = rom_mass[6];
  d2 = rom_mass[7];
  d3 = rom_mass[9];
  for (i = 0; i < 576; i++) {
    TMT[i] = ((((((((TMT[i] * d + b_y[i] * d1) + d_y[i] * d2) + f_y[i] * b_tmp)
                  + h_y[i] * d3) + l_y[i] * d) + n_y[i] * d1) + p_y[i] * d2) +
              r_y[i] * b_tmp) + t_y[i] * d3;
  }

  st.site = &kb_emlrtRSI;
  mtimes(Tt, M, s_y);
  for (i = 0; i < 6; i++) {
    b_Dd[i] += fg[i];
  }

  for (i = 0; i < 24; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      d += y[i + 24 * i1] * b_Dd[i1];
    }

    TMfd[i] = d;
  }

  for (i = 0; i < 144; i++) {
    Dd[i] = -Dd[i];
  }

  for (i = 0; i < 6; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 24; i1++) {
      d += Dd[i + 6 * i1] * z[i1 + 24];
    }

    b_Dd[i] = d + b_fg[i];
  }

  for (i = 0; i < 24; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      d += c_y[i + 24 * i1] * b_Dd[i1];
    }

    w_vd_j[i] = d;
  }

  for (i = 0; i < 144; i++) {
    c_Dd[i] = -c_Dd[i];
  }

  for (i = 0; i < 6; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 24; i1++) {
      d += c_Dd[i + 6 * i1] * z[i1 + 24];
    }

    b_Dd[i] = d + c_fg[i];
  }

  for (i = 0; i < 24; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      d += e_y[i + 24 * i1] * b_Dd[i1];
    }

    u_y[i] = d;
  }

  for (i = 0; i < 144; i++) {
    d_Dd[i] = -d_Dd[i];
  }

  for (i = 0; i < 6; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 24; i1++) {
      d += d_Dd[i + 6 * i1] * z[i1 + 24];
    }

    b_Dd[i] = d + d_fg[i];
  }

  for (i = 0; i < 24; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      d += g_y[i + 24 * i1] * b_Dd[i1];
    }

    v_y[i] = d;
  }

  for (i = 0; i < 144; i++) {
    e_Dd[i] = -e_Dd[i];
  }

  for (i = 0; i < 6; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 24; i1++) {
      d += e_Dd[i + 6 * i1] * z[i1 + 24];
    }

    b_Dd[i] = d + e_fg[i];
  }

  for (i = 0; i < 24; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      d += k_y[i + 24 * i1] * b_Dd[i1];
    }

    w_y[i] = d;
  }

  for (i = 0; i < 144; i++) {
    f_Dd[i] = -f_Dd[i];
  }

  for (i = 0; i < 6; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 24; i1++) {
      d += f_Dd[i + 6 * i1] * z[i1 + 24];
    }

    b_Dd[i] = d + f_fg[i];
  }

  for (i = 0; i < 24; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      d += m_y[i + 24 * i1] * b_Dd[i1];
    }

    x_y[i] = d;
  }

  for (i = 0; i < 144; i++) {
    g_Dd[i] = -g_Dd[i];
  }

  for (i = 0; i < 6; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 24; i1++) {
      d += g_Dd[i + 6 * i1] * z[i1 + 24];
    }

    b_Dd[i] = d + g_fg[i];
  }

  for (i = 0; i < 24; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      d += o_y[i + 24 * i1] * b_Dd[i1];
    }

    y_y[i] = d;
  }

  for (i = 0; i < 144; i++) {
    h_Dd[i] = -h_Dd[i];
  }

  for (i = 0; i < 6; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 24; i1++) {
      d += h_Dd[i + 6 * i1] * z[i1 + 24];
    }

    b_Dd[i] = d + h_fg[i];
  }

  for (i = 0; i < 24; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      d += q_y[i + 24 * i1] * b_Dd[i1];
    }

    ab_y[i] = d;
  }

  for (i = 0; i < 144; i++) {
    i_Dd[i] = -i_Dd[i];
  }

  for (i = 0; i < 6; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 24; i1++) {
      d += i_Dd[i + 6 * i1] * z[i1 + 24];
    }

    b_Dd[i] = d + i_fg[i];
  }

  for (i = 0; i < 24; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      d += s_y[i + 24 * i1] * b_Dd[i1];
    }

    TMfd[i] = ((((((((w_in[i] * rom_mass[5] + TMfd[i] * rom_mass[6]) + w_vd_j[i]
                     * rom_mass[7]) + u_y[i] * b_tmp) + v_y[i] * rom_mass[9]) +
                  w_y[i] * rom_mass[5]) + x_y[i] * rom_mass[6]) + y_y[i] *
                rom_mass[7]) + ab_y[i] * b_tmp) + d * rom_mass[9];
  }

  st.site = &lb_emlrtRSI;
  sprdmpF25(SD->f0.par_mex.var, z, 0.999999 * (rom_sprdmp[53] - rom_sprdmp[24])
            + rom_sprdmp[24], Tt, fg, b_Dd, b_fg, &dir);
  st.site = &mb_emlrtRSI;
  sprdmpF26(&st, SD->f0.par_mex.var, z, 0.999999 * (rom_sprdmp[54] - rom_sprdmp
             [25]) + rom_sprdmp[25], T, c_fg, d_fg, e_fg, &dir);
  st.site = &nb_emlrtRSI;
  sprdmpF27(&st, SD->f0.par_mex.var, z, 0.999999 * (rom_sprdmp[55] - rom_sprdmp
             [26]) + rom_sprdmp[26], Dd, f_fg, g_fg, h_fg, &dir);
  st.site = &ob_emlrtRSI;
  sprdmpF28(SD->f0.par_mex.var, z, 0.999999 * (rom_sprdmp[56] - rom_sprdmp[27])
            + rom_sprdmp[27], y, i_fg, e_vd, e_in, &dir);
  st.site = &pb_emlrtRSI;
  sprdmpF29(&st, SD->f0.par_mex.var, z, 0.999999 * (rom_sprdmp[57] - rom_sprdmp
             [28]) + rom_sprdmp[28], c_y, e_kx, f_vd, f_in, &dir);
  for (i = 0; i < 24; i++) {
    d = 0.0;
    d1 = 0.0;
    d2 = 0.0;
    d3 = 0.0;
    dir = 0.0;
    sn = 0.0;
    d4 = 0.0;
    d5 = 0.0;
    d6 = 0.0;
    d7 = 0.0;
    d8 = 0.0;
    d9 = 0.0;
    d10 = 0.0;
    d11 = 0.0;
    d12 = 0.0;
    d13 = 0.0;
    d14 = 0.0;
    d15 = 0.0;
    d16 = 0.0;
    d17 = 0.0;
    d18 = 0.0;
    d19 = 0.0;
    d20 = 0.0;
    d21 = 0.0;
    d22 = 0.0;
    d23 = 0.0;
    d24 = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      b_i = i + 24 * i1;
      d25 = b_Tt[b_i];
      d += d25 * vd[i1];
      d26 = c_Tt[b_i];
      d1 += d26 * b_vd[i1];
      d27 = d_Tt[b_i];
      d2 += d27 * c_vd[i1];
      d28 = e_Tt[b_i];
      d3 += d28 * d_vd[i1];
      d29 = Tt[b_i];
      dir += d29 * b_Dd[i1];
      d30 = T[b_i];
      sn += d30 * d_fg[i1];
      d31 = Dd[b_i];
      d4 += d31 * g_fg[i1];
      d32 = y[b_i];
      d5 += d32 * e_vd[i1];
      d33 = c_y[b_i];
      d6 += d33 * f_vd[i1];
      d7 += d25 * kx[i1];
      d8 += d26 * b_kx[i1];
      d9 += d27 * c_kx[i1];
      d10 += d28 * d_kx[i1];
      d11 += d29 * fg[i1];
      d12 += d30 * c_fg[i1];
      d13 += d31 * f_fg[i1];
      d14 += d32 * i_fg[i1];
      d15 += d33 * e_kx[i1];
      d16 += d25 * in[i1];
      d17 += d26 * b_in[i1];
      d18 += d27 * c_in[i1];
      d19 += d28 * d_in[i1];
      d20 += d29 * b_fg[i1];
      d21 += d30 * e_fg[i1];
      d22 += d31 * h_fg[i1];
      d23 += d32 * e_in[i1];
      d24 += d33 * f_in[i1];
    }

    w_vd_j[i] = ((((((((w_sd[i] * b_b_tmp + d * c_b_tmp) + d1 * d_b_tmp) + d2 *
                      e_b_tmp) + d3 * f_b_tmp) + dir * b_b_tmp) + sn * c_b_tmp)
                  + d4 * d_b_tmp) + d5 * e_b_tmp) + d6 * f_b_tmp;
    w_sd[i] = ((((((((j_y[i] * b_b_tmp + d7 * c_b_tmp) + d8 * d_b_tmp) + d9 *
                    e_b_tmp) + d10 * f_b_tmp) + d11 * b_b_tmp) + d12 * c_b_tmp)
                + d13 * d_b_tmp) + d14 * e_b_tmp) + d15 * f_b_tmp;
    j_y[i] = d23;
    w_in[i] = ((((((((i_y[i] * b_b_tmp + d16 * c_b_tmp) + d17 * d_b_tmp) + d18 *
                    e_b_tmp) + d19 * f_b_tmp) + d20 * b_b_tmp) + d21 * c_b_tmp)
                + d22 * d_b_tmp) + d23 * e_b_tmp) + d24 * f_b_tmp;
  }

  for (i = 0; i < 576; i++) {
    TMT[i] /= 2.0;
  }

  for (i = 0; i < 24; i++) {
    TMfd[i] /= 2.0;
    w_vd_j[i] /= 2.0;
    w_sd[i] /= 2.0;
    w_in[i] /= 2.0;
  }

  for (b_i = 0; b_i < 9; b_i++) {
    sn = (real_T)b_i * 0.1 + 0.100001;
    st.site = &qb_emlrtRSI;
    massF1(SD->f0.par_mex.var, z, sn * rom_mass[5], M, T, Dd, fg);
    for (i = 0; i < 6; i++) {
      for (i1 = 0; i1 < 24; i1++) {
        Tt[i1 + 24 * i] = T[i + 6 * i1];
      }
    }

    st.site = &rb_emlrtRSI;
    mtimes(Tt, M, y);
    st.site = &rb_emlrtRSI;
    b_mtimes(y, T, b_y);
    for (i = 0; i < 576; i++) {
      TMT[i] += b_y[i] * rom_mass[5];
    }

    st.site = &sb_emlrtRSI;
    mtimes(Tt, M, y);
    for (i = 0; i < 144; i++) {
      Dd[i] = -Dd[i];
    }

    for (i = 0; i < 6; i++) {
      d = 0.0;
      for (i1 = 0; i1 < 24; i1++) {
        d += Dd[i + 6 * i1] * z[i1 + 24];
      }

      b_Dd[i] = d + fg[i];
    }

    for (i = 0; i < 24; i++) {
      d = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        d += y[i + 24 * i1] * b_Dd[i1];
      }

      TMfd[i] += d * rom_mass[5];
    }

    st.site = &tb_emlrtRSI;
    massF2(&st, SD->f0.par_mex.var, z, sn * rom_mass[6], M, T, Dd, fg);
    for (i = 0; i < 6; i++) {
      for (i1 = 0; i1 < 24; i1++) {
        Tt[i1 + 24 * i] = T[i + 6 * i1];
      }
    }

    st.site = &ub_emlrtRSI;
    mtimes(Tt, M, y);
    st.site = &ub_emlrtRSI;
    b_mtimes(y, T, b_y);
    for (i = 0; i < 576; i++) {
      TMT[i] += b_y[i] * rom_mass[6];
    }

    st.site = &vb_emlrtRSI;
    mtimes(Tt, M, y);
    for (i = 0; i < 144; i++) {
      Dd[i] = -Dd[i];
    }

    for (i = 0; i < 6; i++) {
      d = 0.0;
      for (i1 = 0; i1 < 24; i1++) {
        d += Dd[i + 6 * i1] * z[i1 + 24];
      }

      b_Dd[i] = d + fg[i];
    }

    for (i = 0; i < 24; i++) {
      d = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        d += y[i + 24 * i1] * b_Dd[i1];
      }

      TMfd[i] += d * rom_mass[6];
    }

    st.site = &wb_emlrtRSI;
    massF3(&st, SD->f0.par_mex.var, z, sn * rom_mass[7], M, T, Dd, fg);
    for (i = 0; i < 6; i++) {
      for (i1 = 0; i1 < 24; i1++) {
        Tt[i1 + 24 * i] = T[i + 6 * i1];
      }
    }

    st.site = &xb_emlrtRSI;
    mtimes(Tt, M, y);
    st.site = &xb_emlrtRSI;
    b_mtimes(y, T, b_y);
    for (i = 0; i < 576; i++) {
      TMT[i] += b_y[i] * rom_mass[7];
    }

    st.site = &yb_emlrtRSI;
    mtimes(Tt, M, y);
    for (i = 0; i < 144; i++) {
      Dd[i] = -Dd[i];
    }

    for (i = 0; i < 6; i++) {
      d = 0.0;
      for (i1 = 0; i1 < 24; i1++) {
        d += Dd[i + 6 * i1] * z[i1 + 24];
      }

      b_Dd[i] = d + fg[i];
    }

    for (i = 0; i < 24; i++) {
      d = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        d += y[i + 24 * i1] * b_Dd[i1];
      }

      TMfd[i] += d * rom_mass[7];
    }

    st.site = &ac_emlrtRSI;
    massF4(SD->f0.par_mex.var, z, sn * (rom_mass[8] - rom_mass[3]) + rom_mass[3],
           M, T, Dd, fg);
    for (i = 0; i < 6; i++) {
      for (i1 = 0; i1 < 24; i1++) {
        Tt[i1 + 24 * i] = T[i + 6 * i1];
      }
    }

    st.site = &bc_emlrtRSI;
    mtimes(Tt, M, y);
    st.site = &bc_emlrtRSI;
    b_mtimes(y, T, b_y);
    for (i = 0; i < 576; i++) {
      TMT[i] += b_y[i] * b_tmp;
    }

    st.site = &cc_emlrtRSI;
    mtimes(Tt, M, y);
    for (i = 0; i < 144; i++) {
      Dd[i] = -Dd[i];
    }

    for (i = 0; i < 6; i++) {
      d = 0.0;
      for (i1 = 0; i1 < 24; i1++) {
        d += Dd[i + 6 * i1] * z[i1 + 24];
      }

      b_Dd[i] = d + fg[i];
    }

    for (i = 0; i < 24; i++) {
      d = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        d += y[i + 24 * i1] * b_Dd[i1];
      }

      TMfd[i] += d * b_tmp;
    }

    st.site = &dc_emlrtRSI;
    massF5(&st, SD->f0.par_mex.var, z, sn * rom_mass[9], M, T, Dd, fg);
    for (i = 0; i < 6; i++) {
      for (i1 = 0; i1 < 24; i1++) {
        Tt[i1 + 24 * i] = T[i + 6 * i1];
      }
    }

    st.site = &ec_emlrtRSI;
    mtimes(Tt, M, y);
    st.site = &ec_emlrtRSI;
    b_mtimes(y, T, b_y);
    for (i = 0; i < 576; i++) {
      TMT[i] += b_y[i] * rom_mass[9];
    }

    st.site = &fc_emlrtRSI;
    mtimes(Tt, M, y);
    for (i = 0; i < 144; i++) {
      Dd[i] = -Dd[i];
    }

    for (i = 0; i < 6; i++) {
      d = 0.0;
      for (i1 = 0; i1 < 24; i1++) {
        d += Dd[i + 6 * i1] * z[i1 + 24];
      }

      b_Dd[i] = d + fg[i];
    }

    for (i = 0; i < 24; i++) {
      d = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        d += y[i + 24 * i1] * b_Dd[i1];
      }

      TMfd[i] += d * rom_mass[9];
    }

    st.site = &gc_emlrtRSI;
    sprdmpF25(SD->f0.par_mex.var, z, sn * (rom_sprdmp[53] - rom_sprdmp[24]) +
              rom_sprdmp[24], Tt, kx, vd, in, &dir);
    for (i = 0; i < 24; i++) {
      d = 0.0;
      d1 = 0.0;
      d2 = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        d3 = Tt[i + 24 * i1];
        d += d3 * vd[i1];
        d1 += d3 * kx[i1];
        d2 += d3 * in[i1];
      }

      w_vd_j[i] += d * b_b_tmp;
      w_sd[i] += d1 * b_b_tmp;
      w_in[i] += d2 * b_b_tmp;
    }

    st.site = &hc_emlrtRSI;
    sprdmpF26(&st, SD->f0.par_mex.var, z, sn * (rom_sprdmp[54] - rom_sprdmp[25])
              + rom_sprdmp[25], Tt, kx, vd, in, &dir);
    for (i = 0; i < 24; i++) {
      d = 0.0;
      d1 = 0.0;
      d2 = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        d3 = Tt[i + 24 * i1];
        d += d3 * vd[i1];
        d1 += d3 * kx[i1];
        d2 += d3 * in[i1];
      }

      w_vd_j[i] += d * c_b_tmp;
      w_sd[i] += d1 * c_b_tmp;
      w_in[i] += d2 * c_b_tmp;
    }

    st.site = &ic_emlrtRSI;
    sprdmpF27(&st, SD->f0.par_mex.var, z, sn * (rom_sprdmp[55] - rom_sprdmp[26])
              + rom_sprdmp[26], Tt, kx, vd, in, &dir);
    for (i = 0; i < 24; i++) {
      d = 0.0;
      d1 = 0.0;
      d2 = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        d3 = Tt[i + 24 * i1];
        d += d3 * vd[i1];
        d1 += d3 * kx[i1];
        d2 += d3 * in[i1];
      }

      w_vd_j[i] += d * d_b_tmp;
      w_sd[i] += d1 * d_b_tmp;
      w_in[i] += d2 * d_b_tmp;
    }

    st.site = &jc_emlrtRSI;
    sprdmpF28(SD->f0.par_mex.var, z, sn * (rom_sprdmp[56] - rom_sprdmp[27]) +
              rom_sprdmp[27], Tt, kx, vd, in, &dir);
    for (i = 0; i < 24; i++) {
      d = 0.0;
      d1 = 0.0;
      d2 = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        d3 = Tt[i + 24 * i1];
        d += d3 * vd[i1];
        d1 += d3 * kx[i1];
        d2 += d3 * in[i1];
      }

      w_vd_j[i] += d * e_b_tmp;
      w_sd[i] += d1 * e_b_tmp;
      w_in[i] += d2 * e_b_tmp;
    }

    st.site = &kc_emlrtRSI;
    sprdmpF29(&st, SD->f0.par_mex.var, z, sn * (rom_sprdmp[57] - rom_sprdmp[28])
              + rom_sprdmp[28], Tt, kx, vd, in, &dir);
    for (i = 0; i < 24; i++) {
      d = 0.0;
      d1 = 0.0;
      d2 = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        d3 = Tt[i + 24 * i1];
        d += d3 * vd[i1];
        d1 += d3 * kx[i1];
        d2 += d3 * in[i1];
      }

      w_vd_j[i] += d * f_b_tmp;
      w_sd[i] += d1 * f_b_tmp;
      w_in[i] += d2 * f_b_tmp;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  for (i = 0; i < 24; i++) {
    TMfd[i] /= 10.0;
    w_vd_j[i] /= 10.0;
    w_sd[i] /= 10.0;
    w_in[i] /= 10.0;
  }

  /*  EOM */
  st.site = &lc_emlrtRSI;
  for (i = 0; i < 576; i++) {
    TMT[i] /= 10.0;
  }

  b_st.site = &lc_emlrtRSI;
  pinv(&b_st, TMT, b_y);
  for (i = 0; i < 24; i++) {
    TMfd[i] = ((TMfd[i] + w_sd[i]) + w_in[i]) + w_vd_j[i];
  }

  c_mtimes(b_y, TMfd, w_in);
  for (b_i = 0; b_i < 24; b_i++) {
    dz[b_i] = z[b_i + 24];
    dz[b_i + 24] = w_in[b_i];
  }

  *flag = 0.0;
}

/* End of code generation (EOM.c) */
