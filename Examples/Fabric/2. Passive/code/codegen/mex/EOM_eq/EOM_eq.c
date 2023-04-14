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
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "EOM_eq.h"
#include "cnstF8.h"
#include "cnstF7.h"
#include "cnstF6.h"
#include "cnstF5.h"
#include "cnstF4.h"
#include "cnstF3.h"
#include "cnstF2.h"
#include "cnstF1.h"
#include "sprdmpF116.h"
#include "sprdmpF115.h"
#include "sprdmpF114.h"
#include "sprdmpF113.h"
#include "sprdmpF112.h"
#include "sprdmpF111.h"
#include "sprdmpF110.h"
#include "sprdmpF109.h"
#include "sprdmpF108.h"
#include "sprdmpF107.h"
#include "sprdmpF106.h"
#include "sprdmpF105.h"
#include "sprdmpF104.h"
#include "sprdmpF103.h"
#include "sprdmpF102.h"
#include "sprdmpF101.h"
#include "sprdmpF100.h"
#include "sprdmpF99.h"
#include "sprdmpF98.h"
#include "sprdmpF97.h"
#include "sprdmpF96.h"
#include "sprdmpF95.h"
#include "sprdmpF94.h"
#include "sprdmpF93.h"
#include "sprdmpF92.h"
#include "massF15.h"
#include "massF14.h"
#include "massF13.h"
#include "massF12.h"
#include "massF11.h"
#include "massF10.h"
#include "massF9.h"
#include "massF8.h"
#include "massF7.h"
#include "massF6.h"
#include "massF5.h"
#include "massF4.h"
#include "massF3.h"
#include "massF2.h"
#include "massF1.h"
#include "int_mid_step.h"
#include "indexShapeCheck.h"
#include "EOM_eq_data.h"
#include "blas.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 7,     /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 9,   /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 24,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 25,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 26,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 33,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 34,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 35,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 42,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 43,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 44,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 51,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 52,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 53,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 60,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 61,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 62,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 69,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 70,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 71,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 78,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 79,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 80,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 87,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 88,  /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 89, /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 96, /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo cb_emlrtRSI = { 97, /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo db_emlrtRSI = { 98, /* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo eb_emlrtRSI = { 105,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo fb_emlrtRSI = { 106,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 107,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo hb_emlrtRSI = { 114,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo ib_emlrtRSI = { 115,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo jb_emlrtRSI = { 116,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo kb_emlrtRSI = { 123,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo lb_emlrtRSI = { 124,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo mb_emlrtRSI = { 125,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo nb_emlrtRSI = { 132,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo ob_emlrtRSI = { 133,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo pb_emlrtRSI = { 134,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo qb_emlrtRSI = { 141,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo rb_emlrtRSI = { 142,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo sb_emlrtRSI = { 143,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo tb_emlrtRSI = { 150,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo ub_emlrtRSI = { 151,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo vb_emlrtRSI = { 152,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo wb_emlrtRSI = { 159,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo xb_emlrtRSI = { 160,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo yb_emlrtRSI = { 161,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo ac_emlrtRSI = { 162,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo bc_emlrtRSI = { 169,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo cc_emlrtRSI = { 170,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo dc_emlrtRSI = { 171,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo ec_emlrtRSI = { 172,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo fc_emlrtRSI = { 179,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo gc_emlrtRSI = { 180,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo hc_emlrtRSI = { 181,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo ic_emlrtRSI = { 182,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo jc_emlrtRSI = { 189,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo kc_emlrtRSI = { 190,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo lc_emlrtRSI = { 191,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo mc_emlrtRSI = { 192,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo nc_emlrtRSI = { 199,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo oc_emlrtRSI = { 200,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo pc_emlrtRSI = { 201,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo qc_emlrtRSI = { 202,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo rc_emlrtRSI = { 209,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo sc_emlrtRSI = { 210,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo tc_emlrtRSI = { 211,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo uc_emlrtRSI = { 212,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo vc_emlrtRSI = { 219,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo wc_emlrtRSI = { 220,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo xc_emlrtRSI = { 221,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo yc_emlrtRSI = { 222,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo ad_emlrtRSI = { 229,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo bd_emlrtRSI = { 230,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo cd_emlrtRSI = { 231,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo dd_emlrtRSI = { 232,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo ed_emlrtRSI = { 239,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo fd_emlrtRSI = { 240,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo gd_emlrtRSI = { 241,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo hd_emlrtRSI = { 242,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo id_emlrtRSI = { 249,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo jd_emlrtRSI = { 250,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo kd_emlrtRSI = { 251,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo ld_emlrtRSI = { 252,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo md_emlrtRSI = { 259,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo nd_emlrtRSI = { 260,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo od_emlrtRSI = { 261,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo pd_emlrtRSI = { 262,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo qd_emlrtRSI = { 269,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo rd_emlrtRSI = { 270,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo sd_emlrtRSI = { 271,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo td_emlrtRSI = { 272,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo ud_emlrtRSI = { 279,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo vd_emlrtRSI = { 280,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo wd_emlrtRSI = { 281,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo xd_emlrtRSI = { 282,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo yd_emlrtRSI = { 289,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo ae_emlrtRSI = { 290,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo be_emlrtRSI = { 291,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo ce_emlrtRSI = { 292,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo de_emlrtRSI = { 299,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo ee_emlrtRSI = { 300,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo fe_emlrtRSI = { 301,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo ge_emlrtRSI = { 302,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo he_emlrtRSI = { 309,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo ie_emlrtRSI = { 310,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo je_emlrtRSI = { 311,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo ke_emlrtRSI = { 312,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo le_emlrtRSI = { 319,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo me_emlrtRSI = { 320,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo ne_emlrtRSI = { 321,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo oe_emlrtRSI = { 322,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo pe_emlrtRSI = { 329,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo qe_emlrtRSI = { 330,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo re_emlrtRSI = { 331,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo se_emlrtRSI = { 332,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo te_emlrtRSI = { 339,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo ue_emlrtRSI = { 340,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo ve_emlrtRSI = { 341,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo we_emlrtRSI = { 342,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo xe_emlrtRSI = { 349,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo ye_emlrtRSI = { 350,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo af_emlrtRSI = { 351,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo bf_emlrtRSI = { 352,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo cf_emlrtRSI = { 359,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo df_emlrtRSI = { 360,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo ef_emlrtRSI = { 361,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo ff_emlrtRSI = { 362,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo gf_emlrtRSI = { 369,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo hf_emlrtRSI = { 370,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo if_emlrtRSI = { 371,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo jf_emlrtRSI = { 372,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo kf_emlrtRSI = { 379,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo lf_emlrtRSI = { 380,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo mf_emlrtRSI = { 381,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo nf_emlrtRSI = { 382,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo of_emlrtRSI = { 389,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo pf_emlrtRSI = { 390,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo qf_emlrtRSI = { 391,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo rf_emlrtRSI = { 392,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo sf_emlrtRSI = { 399,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo tf_emlrtRSI = { 400,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo uf_emlrtRSI = { 401,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo vf_emlrtRSI = { 402,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo wf_emlrtRSI = { 405,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo xf_emlrtRSI = { 407,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo yf_emlrtRSI = { 411,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo ag_emlrtRSI = { 413,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo bg_emlrtRSI = { 415,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo cg_emlrtRSI = { 417,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo dg_emlrtRSI = { 419,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo eg_emlrtRSI = { 421,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo fg_emlrtRSI = { 423,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo gg_emlrtRSI = { 425,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo hg_emlrtRSI = { 427,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo ig_emlrtRSI = { 429,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo jg_emlrtRSI = { 431,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo kg_emlrtRSI = { 433,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo lg_emlrtRSI = { 435,/* lineNo */
  "EOM_eq",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pathName */
};

static emlrtRSInfo ah_emlrtRSI = { 21, /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 83,  /* lineNo */
  23,                                  /* colNo */
  "eml_mtimes_helper",                 /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 88,/* lineNo */
  23,                                  /* colNo */
  "eml_mtimes_helper",                 /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 398,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 388,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 378,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 368,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 358,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 348,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 338,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 328,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 318,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 308,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo m_emlrtRTEI = { 298,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 288,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo o_emlrtRTEI = { 278,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo p_emlrtRTEI = { 268,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo q_emlrtRTEI = { 258,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo r_emlrtRTEI = { 248,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo s_emlrtRTEI = { 238,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo t_emlrtRTEI = { 228,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo u_emlrtRTEI = { 218,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo v_emlrtRTEI = { 208,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo w_emlrtRTEI = { 198,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo x_emlrtRTEI = { 188,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo y_emlrtRTEI = { 178,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = { 168,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = { 158,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = { 149,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo db_emlrtRTEI = { 140,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = { 131,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo fb_emlrtRTEI = { 122,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo gb_emlrtRTEI = { 113,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo hb_emlrtRTEI = { 104,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo ib_emlrtRTEI = { 95,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo jb_emlrtRTEI = { 86,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo kb_emlrtRTEI = { 77,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = { 68,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo mb_emlrtRTEI = { 59,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo nb_emlrtRTEI = { 50,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo ob_emlrtRTEI = { 41,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo pb_emlrtRTEI = { 32,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pName */
};

static emlrtRTEInfo qb_emlrtRTEI = { 23,/* lineNo */
  9,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  7,                                   /* lineNo */
  13,                                  /* colNo */
  "u",                                 /* aName */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo emlrtDCI = { 7,     /* lineNo */
  13,                                  /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  7,                                   /* lineNo */
  9,                                   /* colNo */
  "u",                                 /* aName */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { 1,   /* iFirst */
  198,                                 /* iLast */
  6,                                   /* lineNo */
  8,                                   /* colNo */
  "z",                                 /* aName */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 6,   /* lineNo */
  8,                                   /* colNo */
  "EOM_eq",                            /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM_eq.m",/* pName */
  1                                    /* checkKind */
};

/* Function Definitions */
void EOM_eq(const emlrtStack *sp, const real_T z[99], real_T fval[99])
{
  b_struct_T par;
  int32_T i1;
  real_T alpha1;
  real_T b_z[198];
  int32_T i2;
  int32_T i;
  int32_T i3;
  real_T u_data[198];
  int32_T loop_ub;
  int32_T iv0[2];
  real_T uq_data[198];
  real_T TMfd[91];
  real_T w_sd[91];
  real_T w_in[91];
  real_T s0;
  real_T ds;
  real_T T[546];
  real_T Dd[546];
  real_T fg[6];
  real_T a_tmp[546];
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  char_T TRANSA;
  char_T TRANSB;
  static const real_T b[36] = { 0.0024, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0024,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0024, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    4.2759999999999987E-8, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 8.5263999999999975E-8,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 4.2759999999999987E-8 };

  real_T a[546];
  real_T y[8281];
  real_T b_y[6];
  real_T c_y[91];
  real_T in[6];
  real_T Dc[91];
  real_T d_y;
  real_T e_y;
  real_T f_y;
  real_T g_y;
  real_T h_y;
  real_T i_y;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  par = par_i;
  for (i1 = 0; i1 < 99; i1++) {
    b_z[i1] = z[i1];
    b_z[i1 + 99] = 0.0 * z[i1];
  }

  alpha1 = (par_i.nq + par_i.nlambda) + 1.0;
  if (alpha1 > 198.0) {
    i1 = 0;
    i2 = 0;
  } else {
    if (alpha1 != (int32_T)muDoubleScalarFloor(alpha1)) {
      emlrtIntegerCheckR2012b(alpha1, &b_emlrtDCI, sp);
    }

    i1 = (int32_T)alpha1;
    if ((i1 < 1) || (i1 > 198)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, 198, &c_emlrtBCI, sp);
    }

    i1--;
    i2 = 198;
  }

  i = i2 - i1;
  for (i3 = 0; i3 < i; i3++) {
    u_data[i3] = b_z[i1 + i3];
  }

  if (1.0 > par_i.nq) {
    loop_ub = 0;
  } else {
    if (1 > i) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i, &b_emlrtBCI, sp);
    }

    if (par_i.nq != (int32_T)muDoubleScalarFloor(par_i.nq)) {
      emlrtIntegerCheckR2012b(par_i.nq, &emlrtDCI, sp);
    }

    loop_ub = (int32_T)par_i.nq;
    if ((loop_ub < 1) || (loop_ub > i)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i, &emlrtBCI, sp);
    }
  }

  iv0[0] = 1;
  iv0[1] = loop_ub;
  st.site = &emlrtRSI;
  indexShapeCheck(&st, i2 - i1, iv0);
  if (0 <= loop_ub - 1) {
    memcpy(&uq_data[0], &u_data[0], (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
  }

  st.site = &b_emlrtRSI;
  int_mid_step(&st, par.t_equil_i, &par);
  memset(&TMfd[0], 0, 91U * sizeof(real_T));
  memset(&w_sd[0], 0, 91U * sizeof(real_T));
  memset(&w_in[0], 0, 91U * sizeof(real_T));
  s0 = 1.0E-6;
  ds = par.rom.mass[0] / par.n_int;
  if (par.rom.mass[0] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.mass[0] - s0;
  i1 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i1,
    &qb_emlrtRTEI, sp);
  for (i = 0; i < i1; i++) {
    st.site = &c_emlrtRSI;
    massF1(&st, b_z, T, Dd, fg);
    st.site = &d_emlrtRSI;
    for (i2 = 0; i2 < 6; i2++) {
      for (i3 = 0; i3 < 91; i3++) {
        a_tmp[i3 + 91 * i2] = T[i2 + 6 * i3];
      }
    }

    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &d_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)91;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &s0, &y[0], &ldc_t);
    st.site = &e_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &e_emlrtRSI;
    for (i2 = 0; i2 < 546; i2++) {
      Dd[i2] = -Dd[i2];
    }

    b_st.site = &ah_emlrtRSI;
    if (91 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI, "MATLAB:innerdim",
          "MATLAB:innerdim", 0);
      }
    }

    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)6;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)91;
    lda_t = (ptrdiff_t)6;
    ldb_t = (ptrdiff_t)91;
    ldc_t = (ptrdiff_t)6;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Dd[0], &lda_t, &uq_data
          [0], &ldb_t, &s0, &b_y[0], &ldc_t);
    for (i2 = 0; i2 < 6; i2++) {
      b_y[i2] += fg[i2];
    }

    st.site = &e_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      TMfd[i2] += c_y[i2] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.mass[1] / par.n_int;
  if (par.rom.mass[1] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.mass[1] - s0;
  i1 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i1,
    &pb_emlrtRTEI, sp);
  for (i = 0; i < i1; i++) {
    st.site = &f_emlrtRSI;
    massF2(&st, b_z, T, Dd, fg);
    st.site = &g_emlrtRSI;
    for (i2 = 0; i2 < 6; i2++) {
      for (i3 = 0; i3 < 91; i3++) {
        a_tmp[i3 + 91 * i2] = T[i2 + 6 * i3];
      }
    }

    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &g_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)91;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &s0, &y[0], &ldc_t);
    st.site = &h_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &h_emlrtRSI;
    for (i2 = 0; i2 < 546; i2++) {
      Dd[i2] = -Dd[i2];
    }

    b_st.site = &ah_emlrtRSI;
    if (91 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI, "MATLAB:innerdim",
          "MATLAB:innerdim", 0);
      }
    }

    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)6;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)91;
    lda_t = (ptrdiff_t)6;
    ldb_t = (ptrdiff_t)91;
    ldc_t = (ptrdiff_t)6;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Dd[0], &lda_t, &uq_data
          [0], &ldb_t, &s0, &b_y[0], &ldc_t);
    for (i2 = 0; i2 < 6; i2++) {
      b_y[i2] += fg[i2];
    }

    st.site = &h_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      TMfd[i2] += c_y[i2] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.mass[2] / par.n_int;
  if (par.rom.mass[2] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.mass[2] - s0;
  i1 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i1,
    &ob_emlrtRTEI, sp);
  for (i = 0; i < i1; i++) {
    st.site = &i_emlrtRSI;
    massF3(&st, b_z, T, Dd, fg);
    st.site = &j_emlrtRSI;
    for (i2 = 0; i2 < 6; i2++) {
      for (i3 = 0; i3 < 91; i3++) {
        a_tmp[i3 + 91 * i2] = T[i2 + 6 * i3];
      }
    }

    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &j_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)91;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &s0, &y[0], &ldc_t);
    st.site = &k_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &k_emlrtRSI;
    for (i2 = 0; i2 < 546; i2++) {
      Dd[i2] = -Dd[i2];
    }

    b_st.site = &ah_emlrtRSI;
    if (91 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI, "MATLAB:innerdim",
          "MATLAB:innerdim", 0);
      }
    }

    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)6;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)91;
    lda_t = (ptrdiff_t)6;
    ldb_t = (ptrdiff_t)91;
    ldc_t = (ptrdiff_t)6;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Dd[0], &lda_t, &uq_data
          [0], &ldb_t, &s0, &b_y[0], &ldc_t);
    for (i2 = 0; i2 < 6; i2++) {
      b_y[i2] += fg[i2];
    }

    st.site = &k_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      TMfd[i2] += c_y[i2] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.mass[3] / par.n_int;
  if (par.rom.mass[3] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.mass[3] - s0;
  i1 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i1,
    &nb_emlrtRTEI, sp);
  for (i = 0; i < i1; i++) {
    st.site = &l_emlrtRSI;
    massF4(&st, b_z, T, Dd, fg);
    st.site = &m_emlrtRSI;
    for (i2 = 0; i2 < 6; i2++) {
      for (i3 = 0; i3 < 91; i3++) {
        a_tmp[i3 + 91 * i2] = T[i2 + 6 * i3];
      }
    }

    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &m_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)91;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &s0, &y[0], &ldc_t);
    st.site = &n_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &n_emlrtRSI;
    for (i2 = 0; i2 < 546; i2++) {
      Dd[i2] = -Dd[i2];
    }

    b_st.site = &ah_emlrtRSI;
    if (91 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI, "MATLAB:innerdim",
          "MATLAB:innerdim", 0);
      }
    }

    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)6;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)91;
    lda_t = (ptrdiff_t)6;
    ldb_t = (ptrdiff_t)91;
    ldc_t = (ptrdiff_t)6;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Dd[0], &lda_t, &uq_data
          [0], &ldb_t, &s0, &b_y[0], &ldc_t);
    for (i2 = 0; i2 < 6; i2++) {
      b_y[i2] += fg[i2];
    }

    st.site = &n_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      TMfd[i2] += c_y[i2] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.mass[4] / par.n_int;
  if (par.rom.mass[4] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.mass[4] - s0;
  i1 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i1,
    &mb_emlrtRTEI, sp);
  for (i = 0; i < i1; i++) {
    st.site = &o_emlrtRSI;
    massF5(&st, b_z, T, Dd, fg);
    st.site = &p_emlrtRSI;
    for (i2 = 0; i2 < 6; i2++) {
      for (i3 = 0; i3 < 91; i3++) {
        a_tmp[i3 + 91 * i2] = T[i2 + 6 * i3];
      }
    }

    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &p_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)91;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &s0, &y[0], &ldc_t);
    st.site = &q_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &q_emlrtRSI;
    for (i2 = 0; i2 < 546; i2++) {
      Dd[i2] = -Dd[i2];
    }

    b_st.site = &ah_emlrtRSI;
    if (91 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI, "MATLAB:innerdim",
          "MATLAB:innerdim", 0);
      }
    }

    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)6;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)91;
    lda_t = (ptrdiff_t)6;
    ldb_t = (ptrdiff_t)91;
    ldc_t = (ptrdiff_t)6;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Dd[0], &lda_t, &uq_data
          [0], &ldb_t, &s0, &b_y[0], &ldc_t);
    for (i2 = 0; i2 < 6; i2++) {
      b_y[i2] += fg[i2];
    }

    st.site = &q_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      TMfd[i2] += c_y[i2] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.mass[5] / par.n_int;
  if (par.rom.mass[5] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.mass[5] - s0;
  i1 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i1,
    &lb_emlrtRTEI, sp);
  for (i = 0; i < i1; i++) {
    st.site = &r_emlrtRSI;
    massF6(&st, b_z, T, Dd, fg);
    st.site = &s_emlrtRSI;
    for (i2 = 0; i2 < 6; i2++) {
      for (i3 = 0; i3 < 91; i3++) {
        a_tmp[i3 + 91 * i2] = T[i2 + 6 * i3];
      }
    }

    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &s_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)91;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &s0, &y[0], &ldc_t);
    st.site = &t_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &t_emlrtRSI;
    for (i2 = 0; i2 < 546; i2++) {
      Dd[i2] = -Dd[i2];
    }

    b_st.site = &ah_emlrtRSI;
    if (91 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI, "MATLAB:innerdim",
          "MATLAB:innerdim", 0);
      }
    }

    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)6;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)91;
    lda_t = (ptrdiff_t)6;
    ldb_t = (ptrdiff_t)91;
    ldc_t = (ptrdiff_t)6;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Dd[0], &lda_t, &uq_data
          [0], &ldb_t, &s0, &b_y[0], &ldc_t);
    for (i2 = 0; i2 < 6; i2++) {
      b_y[i2] += fg[i2];
    }

    st.site = &t_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      TMfd[i2] += c_y[i2] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.mass[6] / par.n_int;
  if (par.rom.mass[6] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.mass[6] - s0;
  i1 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i1,
    &kb_emlrtRTEI, sp);
  for (i = 0; i < i1; i++) {
    st.site = &u_emlrtRSI;
    massF7(&st, b_z, T, Dd, fg);
    st.site = &v_emlrtRSI;
    for (i2 = 0; i2 < 6; i2++) {
      for (i3 = 0; i3 < 91; i3++) {
        a_tmp[i3 + 91 * i2] = T[i2 + 6 * i3];
      }
    }

    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &v_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)91;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &s0, &y[0], &ldc_t);
    st.site = &w_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &w_emlrtRSI;
    for (i2 = 0; i2 < 546; i2++) {
      Dd[i2] = -Dd[i2];
    }

    b_st.site = &ah_emlrtRSI;
    if (91 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI, "MATLAB:innerdim",
          "MATLAB:innerdim", 0);
      }
    }

    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)6;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)91;
    lda_t = (ptrdiff_t)6;
    ldb_t = (ptrdiff_t)91;
    ldc_t = (ptrdiff_t)6;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Dd[0], &lda_t, &uq_data
          [0], &ldb_t, &s0, &b_y[0], &ldc_t);
    for (i2 = 0; i2 < 6; i2++) {
      b_y[i2] += fg[i2];
    }

    st.site = &w_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      TMfd[i2] += c_y[i2] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.mass[7] / par.n_int;
  if (par.rom.mass[7] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.mass[7] - s0;
  i1 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i1,
    &jb_emlrtRTEI, sp);
  for (i = 0; i < i1; i++) {
    st.site = &x_emlrtRSI;
    massF8(&st, b_z, T, Dd, fg);
    st.site = &y_emlrtRSI;
    for (i2 = 0; i2 < 6; i2++) {
      for (i3 = 0; i3 < 91; i3++) {
        a_tmp[i3 + 91 * i2] = T[i2 + 6 * i3];
      }
    }

    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &y_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)91;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &s0, &y[0], &ldc_t);
    st.site = &ab_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &ab_emlrtRSI;
    for (i2 = 0; i2 < 546; i2++) {
      Dd[i2] = -Dd[i2];
    }

    b_st.site = &ah_emlrtRSI;
    if (91 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI, "MATLAB:innerdim",
          "MATLAB:innerdim", 0);
      }
    }

    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)6;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)91;
    lda_t = (ptrdiff_t)6;
    ldb_t = (ptrdiff_t)91;
    ldc_t = (ptrdiff_t)6;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Dd[0], &lda_t, &uq_data
          [0], &ldb_t, &s0, &b_y[0], &ldc_t);
    for (i2 = 0; i2 < 6; i2++) {
      b_y[i2] += fg[i2];
    }

    st.site = &ab_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      TMfd[i2] += c_y[i2] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.mass[8] / par.n_int;
  if (par.rom.mass[8] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.mass[8] - s0;
  i1 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i1,
    &ib_emlrtRTEI, sp);
  for (i = 0; i < i1; i++) {
    st.site = &bb_emlrtRSI;
    massF9(&st, b_z, T, Dd, fg);
    st.site = &cb_emlrtRSI;
    for (i2 = 0; i2 < 6; i2++) {
      for (i3 = 0; i3 < 91; i3++) {
        a_tmp[i3 + 91 * i2] = T[i2 + 6 * i3];
      }
    }

    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &cb_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)91;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &s0, &y[0], &ldc_t);
    st.site = &db_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &db_emlrtRSI;
    for (i2 = 0; i2 < 546; i2++) {
      Dd[i2] = -Dd[i2];
    }

    b_st.site = &ah_emlrtRSI;
    if (91 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI, "MATLAB:innerdim",
          "MATLAB:innerdim", 0);
      }
    }

    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)6;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)91;
    lda_t = (ptrdiff_t)6;
    ldb_t = (ptrdiff_t)91;
    ldc_t = (ptrdiff_t)6;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Dd[0], &lda_t, &uq_data
          [0], &ldb_t, &s0, &b_y[0], &ldc_t);
    for (i2 = 0; i2 < 6; i2++) {
      b_y[i2] += fg[i2];
    }

    st.site = &db_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      TMfd[i2] += c_y[i2] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.mass[9] / par.n_int;
  if (par.rom.mass[9] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.mass[9] - s0;
  i1 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i1,
    &hb_emlrtRTEI, sp);
  for (i = 0; i < i1; i++) {
    st.site = &eb_emlrtRSI;
    massF10(&st, b_z, T, Dd, fg);
    st.site = &fb_emlrtRSI;
    for (i2 = 0; i2 < 6; i2++) {
      for (i3 = 0; i3 < 91; i3++) {
        a_tmp[i3 + 91 * i2] = T[i2 + 6 * i3];
      }
    }

    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &fb_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)91;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &s0, &y[0], &ldc_t);
    st.site = &gb_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &gb_emlrtRSI;
    for (i2 = 0; i2 < 546; i2++) {
      Dd[i2] = -Dd[i2];
    }

    b_st.site = &ah_emlrtRSI;
    if (91 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI, "MATLAB:innerdim",
          "MATLAB:innerdim", 0);
      }
    }

    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)6;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)91;
    lda_t = (ptrdiff_t)6;
    ldb_t = (ptrdiff_t)91;
    ldc_t = (ptrdiff_t)6;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Dd[0], &lda_t, &uq_data
          [0], &ldb_t, &s0, &b_y[0], &ldc_t);
    for (i2 = 0; i2 < 6; i2++) {
      b_y[i2] += fg[i2];
    }

    st.site = &gb_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      TMfd[i2] += c_y[i2] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.mass[10] / par.n_int;
  if (par.rom.mass[10] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.mass[10] - s0;
  i1 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i1,
    &gb_emlrtRTEI, sp);
  for (i = 0; i < i1; i++) {
    st.site = &hb_emlrtRSI;
    massF11(&st, b_z, T, Dd, fg);
    st.site = &ib_emlrtRSI;
    for (i2 = 0; i2 < 6; i2++) {
      for (i3 = 0; i3 < 91; i3++) {
        a_tmp[i3 + 91 * i2] = T[i2 + 6 * i3];
      }
    }

    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &ib_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)91;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &s0, &y[0], &ldc_t);
    st.site = &jb_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &jb_emlrtRSI;
    for (i2 = 0; i2 < 546; i2++) {
      Dd[i2] = -Dd[i2];
    }

    b_st.site = &ah_emlrtRSI;
    if (91 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI, "MATLAB:innerdim",
          "MATLAB:innerdim", 0);
      }
    }

    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)6;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)91;
    lda_t = (ptrdiff_t)6;
    ldb_t = (ptrdiff_t)91;
    ldc_t = (ptrdiff_t)6;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Dd[0], &lda_t, &uq_data
          [0], &ldb_t, &s0, &b_y[0], &ldc_t);
    for (i2 = 0; i2 < 6; i2++) {
      b_y[i2] += fg[i2];
    }

    st.site = &jb_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      TMfd[i2] += c_y[i2] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.mass[11] / par.n_int;
  if (par.rom.mass[11] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.mass[11] - s0;
  i1 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i1,
    &fb_emlrtRTEI, sp);
  for (i = 0; i < i1; i++) {
    st.site = &kb_emlrtRSI;
    massF12(&st, b_z, T, Dd, fg);
    st.site = &lb_emlrtRSI;
    for (i2 = 0; i2 < 6; i2++) {
      for (i3 = 0; i3 < 91; i3++) {
        a_tmp[i3 + 91 * i2] = T[i2 + 6 * i3];
      }
    }

    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &lb_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)91;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &s0, &y[0], &ldc_t);
    st.site = &mb_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &mb_emlrtRSI;
    for (i2 = 0; i2 < 546; i2++) {
      Dd[i2] = -Dd[i2];
    }

    b_st.site = &ah_emlrtRSI;
    if (91 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI, "MATLAB:innerdim",
          "MATLAB:innerdim", 0);
      }
    }

    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)6;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)91;
    lda_t = (ptrdiff_t)6;
    ldb_t = (ptrdiff_t)91;
    ldc_t = (ptrdiff_t)6;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Dd[0], &lda_t, &uq_data
          [0], &ldb_t, &s0, &b_y[0], &ldc_t);
    for (i2 = 0; i2 < 6; i2++) {
      b_y[i2] += fg[i2];
    }

    st.site = &mb_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      TMfd[i2] += c_y[i2] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.mass[12] / par.n_int;
  if (par.rom.mass[12] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.mass[12] - s0;
  i1 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i1,
    &eb_emlrtRTEI, sp);
  for (i = 0; i < i1; i++) {
    st.site = &nb_emlrtRSI;
    massF13(&st, b_z, T, Dd, fg);
    st.site = &ob_emlrtRSI;
    for (i2 = 0; i2 < 6; i2++) {
      for (i3 = 0; i3 < 91; i3++) {
        a_tmp[i3 + 91 * i2] = T[i2 + 6 * i3];
      }
    }

    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &ob_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)91;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &s0, &y[0], &ldc_t);
    st.site = &pb_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &pb_emlrtRSI;
    for (i2 = 0; i2 < 546; i2++) {
      Dd[i2] = -Dd[i2];
    }

    b_st.site = &ah_emlrtRSI;
    if (91 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI, "MATLAB:innerdim",
          "MATLAB:innerdim", 0);
      }
    }

    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)6;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)91;
    lda_t = (ptrdiff_t)6;
    ldb_t = (ptrdiff_t)91;
    ldc_t = (ptrdiff_t)6;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Dd[0], &lda_t, &uq_data
          [0], &ldb_t, &s0, &b_y[0], &ldc_t);
    for (i2 = 0; i2 < 6; i2++) {
      b_y[i2] += fg[i2];
    }

    st.site = &pb_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      TMfd[i2] += c_y[i2] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.mass[13] / par.n_int;
  if (par.rom.mass[13] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.mass[13] - s0;
  i1 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i1,
    &db_emlrtRTEI, sp);
  for (i = 0; i < i1; i++) {
    st.site = &qb_emlrtRSI;
    massF14(&st, b_z, T, Dd, fg);
    st.site = &rb_emlrtRSI;
    for (i2 = 0; i2 < 6; i2++) {
      for (i3 = 0; i3 < 91; i3++) {
        a_tmp[i3 + 91 * i2] = T[i2 + 6 * i3];
      }
    }

    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &rb_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)91;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &s0, &y[0], &ldc_t);
    st.site = &sb_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &sb_emlrtRSI;
    for (i2 = 0; i2 < 546; i2++) {
      Dd[i2] = -Dd[i2];
    }

    b_st.site = &ah_emlrtRSI;
    if (91 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI, "MATLAB:innerdim",
          "MATLAB:innerdim", 0);
      }
    }

    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)6;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)91;
    lda_t = (ptrdiff_t)6;
    ldb_t = (ptrdiff_t)91;
    ldc_t = (ptrdiff_t)6;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Dd[0], &lda_t, &uq_data
          [0], &ldb_t, &s0, &b_y[0], &ldc_t);
    for (i2 = 0; i2 < 6; i2++) {
      b_y[i2] += fg[i2];
    }

    st.site = &sb_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      TMfd[i2] += c_y[i2] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.mass[14] / par.n_int;
  if (par.rom.mass[14] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.mass[14] - s0;
  i1 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i1,
    &cb_emlrtRTEI, sp);
  for (i = 0; i < i1; i++) {
    st.site = &tb_emlrtRSI;
    massF15(&st, b_z, T, Dd, fg);
    st.site = &ub_emlrtRSI;
    for (i2 = 0; i2 < 6; i2++) {
      for (i3 = 0; i3 < 91; i3++) {
        a_tmp[i3 + 91 * i2] = T[i2 + 6 * i3];
      }
    }

    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &ub_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)91;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &s0, &y[0], &ldc_t);
    st.site = &vb_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &vb_emlrtRSI;
    for (i2 = 0; i2 < 546; i2++) {
      Dd[i2] = -Dd[i2];
    }

    b_st.site = &ah_emlrtRSI;
    if (91 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI, "MATLAB:innerdim",
          "MATLAB:innerdim", 0);
      }
    }

    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)6;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)91;
    lda_t = (ptrdiff_t)6;
    ldb_t = (ptrdiff_t)91;
    ldc_t = (ptrdiff_t)6;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Dd[0], &lda_t, &uq_data
          [0], &ldb_t, &s0, &b_y[0], &ldc_t);
    for (i2 = 0; i2 < 6; i2++) {
      b_y[i2] += fg[i2];
    }

    st.site = &vb_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      TMfd[i2] += c_y[i2] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.sprdmp[91] / par.n_int;
  if (par.rom.sprdmp[91] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.sprdmp[91] - s0;
  i1 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i1,
    &bb_emlrtRTEI, sp);
  for (i = 0; i < i1; i++) {
    st.site = &wb_emlrtRSI;
    sprdmpF92(&st, par.var, b_z, T, fg, b_y, in);
    st.site = &xb_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    st.site = &yb_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_sd[i2] += c_y[i2] * ds;
    }

    st.site = &ac_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_in[i2] += c_y[i2] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.sprdmp[92] / par.n_int;
  if (par.rom.sprdmp[92] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.sprdmp[92] - s0;
  i1 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i1,
    &ab_emlrtRTEI, sp);
  for (i = 0; i < i1; i++) {
    st.site = &bc_emlrtRSI;
    sprdmpF93(&st, par.var, b_z, T, fg, b_y, in);
    st.site = &cc_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    st.site = &dc_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_sd[i2] += c_y[i2] * ds;
    }

    st.site = &ec_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_in[i2] += c_y[i2] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.sprdmp[93] / par.n_int;
  if (par.rom.sprdmp[93] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.sprdmp[93] - s0;
  i1 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i1, &y_emlrtRTEI,
    sp);
  for (i = 0; i < i1; i++) {
    st.site = &fc_emlrtRSI;
    sprdmpF94(&st, b_z, T, fg, b_y, in);
    st.site = &gc_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    st.site = &hc_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_sd[i2] += c_y[i2] * ds;
    }

    st.site = &ic_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_in[i2] += c_y[i2] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.sprdmp[94] / par.n_int;
  if (par.rom.sprdmp[94] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.sprdmp[94] - s0;
  i1 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i1, &x_emlrtRTEI,
    sp);
  for (i = 0; i < i1; i++) {
    st.site = &jc_emlrtRSI;
    sprdmpF95(&st, par.var, b_z, T, fg, b_y, in);
    st.site = &kc_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    st.site = &lc_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_sd[i2] += c_y[i2] * ds;
    }

    st.site = &mc_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_in[i2] += c_y[i2] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.sprdmp[95] / par.n_int;
  if (par.rom.sprdmp[95] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.sprdmp[95] - s0;
  i1 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i1, &w_emlrtRTEI,
    sp);
  for (i = 0; i < i1; i++) {
    st.site = &nc_emlrtRSI;
    sprdmpF96(&st, par.var, b_z, T, fg, b_y, in);
    st.site = &oc_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    st.site = &pc_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_sd[i2] += c_y[i2] * ds;
    }

    st.site = &qc_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_in[i2] += c_y[i2] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.sprdmp[96] / par.n_int;
  if (par.rom.sprdmp[96] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.sprdmp[96] - s0;
  i1 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i1, &v_emlrtRTEI,
    sp);
  for (i = 0; i < i1; i++) {
    st.site = &rc_emlrtRSI;
    sprdmpF97(&st, par.var, b_z, T, fg, b_y, in);
    st.site = &sc_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    st.site = &tc_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_sd[i2] += c_y[i2] * ds;
    }

    st.site = &uc_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_in[i2] += c_y[i2] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.sprdmp[97] / par.n_int;
  if (par.rom.sprdmp[97] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.sprdmp[97] - s0;
  i1 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i1, &u_emlrtRTEI,
    sp);
  for (i = 0; i < i1; i++) {
    st.site = &vc_emlrtRSI;
    sprdmpF98(&st, par.var, b_z, T, fg, b_y, in);
    st.site = &wc_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    st.site = &xc_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_sd[i2] += c_y[i2] * ds;
    }

    st.site = &yc_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_in[i2] += c_y[i2] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.sprdmp[98] / par.n_int;
  if (par.rom.sprdmp[98] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.sprdmp[98] - s0;
  i1 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i1, &t_emlrtRTEI,
    sp);
  for (i = 0; i < i1; i++) {
    st.site = &ad_emlrtRSI;
    sprdmpF99(&st, par.var, b_z, T, fg, b_y, in);
    st.site = &bd_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    st.site = &cd_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_sd[i2] += c_y[i2] * ds;
    }

    st.site = &dd_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_in[i2] += c_y[i2] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.sprdmp[99] / par.n_int;
  if (par.rom.sprdmp[99] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.sprdmp[99] - s0;
  i1 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i1, &s_emlrtRTEI,
    sp);
  for (i = 0; i < i1; i++) {
    st.site = &ed_emlrtRSI;
    sprdmpF100(&st, par.var, b_z, T, fg, b_y, in);
    st.site = &fd_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    st.site = &gd_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_sd[i2] += c_y[i2] * ds;
    }

    st.site = &hd_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_in[i2] += c_y[i2] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.sprdmp[100] / par.n_int;
  if (par.rom.sprdmp[100] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.sprdmp[100] - s0;
  i1 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i1, &r_emlrtRTEI,
    sp);
  for (i = 0; i < i1; i++) {
    st.site = &id_emlrtRSI;
    sprdmpF101(&st, par.var, b_z, T, fg, b_y, in);
    st.site = &jd_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    st.site = &kd_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_sd[i2] += c_y[i2] * ds;
    }

    st.site = &ld_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_in[i2] += c_y[i2] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.sprdmp[101] / par.n_int;
  if (par.rom.sprdmp[101] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.sprdmp[101] - s0;
  i1 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i1, &q_emlrtRTEI,
    sp);
  for (i = 0; i < i1; i++) {
    st.site = &md_emlrtRSI;
    sprdmpF102(&st, par.var, b_z, T, fg, b_y, in);
    st.site = &nd_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    st.site = &od_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_sd[i2] += c_y[i2] * ds;
    }

    st.site = &pd_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_in[i2] += c_y[i2] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.sprdmp[102] / par.n_int;
  if (par.rom.sprdmp[102] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.sprdmp[102] - s0;
  i1 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i1, &p_emlrtRTEI,
    sp);
  for (i = 0; i < i1; i++) {
    st.site = &qd_emlrtRSI;
    sprdmpF103(&st, par.var, b_z, T, fg, b_y, in);
    st.site = &rd_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    st.site = &sd_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_sd[i2] += c_y[i2] * ds;
    }

    st.site = &td_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_in[i2] += c_y[i2] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.sprdmp[103] / par.n_int;
  if (par.rom.sprdmp[103] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.sprdmp[103] - s0;
  i1 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i1, &o_emlrtRTEI,
    sp);
  for (i = 0; i < i1; i++) {
    st.site = &ud_emlrtRSI;
    sprdmpF104(&st, par.var, b_z, T, fg, b_y, in);
    st.site = &vd_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    st.site = &wd_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_sd[i2] += c_y[i2] * ds;
    }

    st.site = &xd_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_in[i2] += c_y[i2] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.sprdmp[104] / par.n_int;
  if (par.rom.sprdmp[104] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.sprdmp[104] - s0;
  i1 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i1, &n_emlrtRTEI,
    sp);
  for (i = 0; i < i1; i++) {
    st.site = &yd_emlrtRSI;
    sprdmpF105(&st, par.var, b_z, T, fg, b_y, in);
    st.site = &ae_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    st.site = &be_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_sd[i2] += c_y[i2] * ds;
    }

    st.site = &ce_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_in[i2] += c_y[i2] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.sprdmp[105] / par.n_int;
  if (par.rom.sprdmp[105] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.sprdmp[105] - s0;
  i1 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i1, &m_emlrtRTEI,
    sp);
  for (i = 0; i < i1; i++) {
    st.site = &de_emlrtRSI;
    sprdmpF106(&st, par.var, b_z, T, fg, b_y, in);
    st.site = &ee_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    st.site = &fe_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_sd[i2] += c_y[i2] * ds;
    }

    st.site = &ge_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_in[i2] += c_y[i2] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.sprdmp[106] / par.n_int;
  if (par.rom.sprdmp[106] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.sprdmp[106] - s0;
  i1 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i1, &l_emlrtRTEI,
    sp);
  for (i = 0; i < i1; i++) {
    st.site = &he_emlrtRSI;
    sprdmpF107(&st, par.var, b_z, T, fg, b_y, in);
    st.site = &ie_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    st.site = &je_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_sd[i2] += c_y[i2] * ds;
    }

    st.site = &ke_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_in[i2] += c_y[i2] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.sprdmp[107] / par.n_int;
  if (par.rom.sprdmp[107] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.sprdmp[107] - s0;
  i1 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i1, &k_emlrtRTEI,
    sp);
  for (i = 0; i < i1; i++) {
    st.site = &le_emlrtRSI;
    sprdmpF108(&st, par.var, b_z, T, fg, b_y, in);
    st.site = &me_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    st.site = &ne_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_sd[i2] += c_y[i2] * ds;
    }

    st.site = &oe_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_in[i2] += c_y[i2] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.sprdmp[108] / par.n_int;
  if (par.rom.sprdmp[108] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.sprdmp[108] - s0;
  i1 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i1, &j_emlrtRTEI,
    sp);
  for (i = 0; i < i1; i++) {
    st.site = &pe_emlrtRSI;
    sprdmpF109(&st, par.var, b_z, T, fg, b_y, in);
    st.site = &qe_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    st.site = &re_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_sd[i2] += c_y[i2] * ds;
    }

    st.site = &se_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_in[i2] += c_y[i2] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.sprdmp[109] / par.n_int;
  if (par.rom.sprdmp[109] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.sprdmp[109] - s0;
  i1 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i1, &i_emlrtRTEI,
    sp);
  for (i = 0; i < i1; i++) {
    st.site = &te_emlrtRSI;
    sprdmpF110(&st, par.var, b_z, T, fg, b_y, in);
    st.site = &ue_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    st.site = &ve_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_sd[i2] += c_y[i2] * ds;
    }

    st.site = &we_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_in[i2] += c_y[i2] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.sprdmp[110] / par.n_int;
  if (par.rom.sprdmp[110] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.sprdmp[110] - s0;
  i1 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i1, &h_emlrtRTEI,
    sp);
  for (i = 0; i < i1; i++) {
    st.site = &xe_emlrtRSI;
    sprdmpF111(&st, par.var, b_z, T, fg, b_y, in);
    st.site = &ye_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    st.site = &af_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_sd[i2] += c_y[i2] * ds;
    }

    st.site = &bf_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_in[i2] += c_y[i2] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.sprdmp[111] / par.n_int;
  if (par.rom.sprdmp[111] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.sprdmp[111] - s0;
  i1 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i1, &g_emlrtRTEI,
    sp);
  for (i = 0; i < i1; i++) {
    st.site = &cf_emlrtRSI;
    sprdmpF112(&st, par.var, b_z, T, fg, b_y, in);
    st.site = &df_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    st.site = &ef_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_sd[i2] += c_y[i2] * ds;
    }

    st.site = &ff_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_in[i2] += c_y[i2] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.sprdmp[112] / par.n_int;
  if (par.rom.sprdmp[112] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.sprdmp[112] - s0;
  i1 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i1, &f_emlrtRTEI,
    sp);
  for (i = 0; i < i1; i++) {
    st.site = &gf_emlrtRSI;
    sprdmpF113(&st, b_z, T, fg, b_y, in);
    st.site = &hf_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    st.site = &if_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_sd[i2] += c_y[i2] * ds;
    }

    st.site = &jf_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_in[i2] += c_y[i2] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.sprdmp[113] / par.n_int;
  if (par.rom.sprdmp[113] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.sprdmp[113] - s0;
  i1 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i1, &e_emlrtRTEI,
    sp);
  for (i = 0; i < i1; i++) {
    st.site = &kf_emlrtRSI;
    sprdmpF114(&st, par.var, b_z, T, fg, b_y, in);
    st.site = &lf_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    st.site = &mf_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_sd[i2] += c_y[i2] * ds;
    }

    st.site = &nf_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_in[i2] += c_y[i2] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.sprdmp[114] / par.n_int;
  if (par.rom.sprdmp[114] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.sprdmp[114] - s0;
  i1 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i1, &d_emlrtRTEI,
    sp);
  for (i = 0; i < i1; i++) {
    st.site = &of_emlrtRSI;
    sprdmpF115(&st, par.var, b_z, T, fg, b_y, in);
    st.site = &pf_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    st.site = &qf_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_sd[i2] += c_y[i2] * ds;
    }

    st.site = &rf_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_in[i2] += c_y[i2] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par.rom.sprdmp[115] / par.n_int;
  if (par.rom.sprdmp[115] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par.rom.sprdmp[115] - s0;
  i1 = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i1, &c_emlrtRTEI,
    sp);
  for (i = 0; i < i1; i++) {
    st.site = &sf_emlrtRSI;
    sprdmpF116(&st, b_z, T, fg, b_y, in);
    st.site = &tf_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    st.site = &uf_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_sd[i2] += c_y[i2] * ds;
    }

    st.site = &vf_emlrtRSI;
    alpha1 = 1.0;
    s0 = 0.0;
    m_t = (ptrdiff_t)91;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)91;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)91;
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i2 = 0; i2 < 91; i2++) {
      w_in[i2] += c_y[i2] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  st.site = &wf_emlrtRSI;
  cnstF1(&st, par.var, b_z, c_y, Dc, &alpha1);
  st.site = &xf_emlrtRSI;
  for (i1 = 0; i1 < 91; i1++) {
    Dc[i1] = -Dc[i1];
  }

  b_st.site = &ah_emlrtRSI;
  if (91 != loop_ub) {
    if (loop_ub == 1) {
      emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
        "Coder:toolbox:mtimes_noDynamicScalarExpansion",
        "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI, "MATLAB:innerdim",
        "MATLAB:innerdim", 0);
    }
  }

  ds = 0.0;
  for (i = 0; i < 91; i++) {
    ds += Dc[i] * u_data[i];
  }

  cnstF2(b_z, c_y, Dc, &s0);
  st.site = &yf_emlrtRSI;
  for (i1 = 0; i1 < 91; i1++) {
    Dc[i1] = -Dc[i1];
  }

  d_y = 0.0;
  for (i = 0; i < 91; i++) {
    d_y += Dc[i] * u_data[i];
  }

  st.site = &ag_emlrtRSI;
  cnstF3(&st, b_z, c_y, Dc, &s0);
  st.site = &bg_emlrtRSI;
  for (i1 = 0; i1 < 91; i1++) {
    Dc[i1] = -Dc[i1];
  }

  e_y = 0.0;
  for (i = 0; i < 91; i++) {
    e_y += Dc[i] * u_data[i];
  }

  st.site = &cg_emlrtRSI;
  cnstF4(&st, b_z, c_y, Dc, &s0);
  st.site = &dg_emlrtRSI;
  for (i1 = 0; i1 < 91; i1++) {
    Dc[i1] = -Dc[i1];
  }

  f_y = 0.0;
  for (i = 0; i < 91; i++) {
    f_y += Dc[i] * u_data[i];
  }

  st.site = &eg_emlrtRSI;
  cnstF5(&st, b_z, c_y, Dc, &s0);
  st.site = &fg_emlrtRSI;
  for (i1 = 0; i1 < 91; i1++) {
    Dc[i1] = -Dc[i1];
  }

  g_y = 0.0;
  for (i = 0; i < 91; i++) {
    g_y += Dc[i] * u_data[i];
  }

  st.site = &gg_emlrtRSI;
  cnstF6(&st, b_z, c_y, Dc, &s0);
  st.site = &hg_emlrtRSI;
  for (i1 = 0; i1 < 91; i1++) {
    Dc[i1] = -Dc[i1];
  }

  h_y = 0.0;
  for (i = 0; i < 91; i++) {
    h_y += Dc[i] * u_data[i];
  }

  st.site = &ig_emlrtRSI;
  cnstF7(&st, b_z, c_y, Dc, &s0);
  st.site = &jg_emlrtRSI;
  for (i1 = 0; i1 < 91; i1++) {
    Dc[i1] = -Dc[i1];
  }

  i_y = 0.0;
  for (i = 0; i < 91; i++) {
    i_y += Dc[i] * u_data[i];
  }

  st.site = &kg_emlrtRSI;
  cnstF8(&st, b_z, c_y, Dc, &s0);
  st.site = &lg_emlrtRSI;
  for (i1 = 0; i1 < 91; i1++) {
    Dc[i1] = -Dc[i1];
  }

  s0 = 0.0;
  for (i = 0; i < 91; i++) {
    s0 += Dc[i] * u_data[i];
  }

  /*  EOM */
  for (i = 0; i < 91; i++) {
    fval[i] = (TMfd[i] + w_sd[i]) + w_in[i];
  }

  fval[91] = ds + alpha1;
  fval[92] = d_y;
  fval[93] = e_y;
  fval[94] = f_y;
  fval[95] = g_y;
  fval[96] = h_y;
  fval[97] = i_y;
  fval[98] = s0;
}

/* End of code generation (EOM_eq.c) */
