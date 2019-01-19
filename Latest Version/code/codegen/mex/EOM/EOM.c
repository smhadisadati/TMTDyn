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
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "EOM.h"
#include "massF1.h"
#include "cnstF1.h"
#include "cnstF2.h"
#include "cnstF3.h"
#include "cnstF7.h"
#include "cnstF8.h"
#include "cnstF9.h"
#include "mldivide.h"
#include "fj_vdF.h"
#include "cnstF12.h"
#include "cnstF11.h"
#include "cnstF10.h"
#include "cnstF6.h"
#include "cnstF5.h"
#include "cnstF4.h"
#include "EOM_mexutil.h"
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
#include "massF16.h"
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
#include "indexShapeCheck.h"
#include "EOM_data.h"
#include "blas.h"

/* Variable Definitions */
static emlrtRTEInfo emlrtRTEI = { 4,   /* lineNo */
  5,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtRSInfo emlrtRSI = { 10,    /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 27,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 28,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 29,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 36,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 37,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 38,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 45,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 46,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 47,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 54,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 55,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 56,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 63,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 64,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 65,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 72,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 73,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 74,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 81,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 82,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 83,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 90,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 91,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 92,  /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 99, /* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 100,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo cb_emlrtRSI = { 101,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo db_emlrtRSI = { 108,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo eb_emlrtRSI = { 109,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo fb_emlrtRSI = { 110,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 117,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo hb_emlrtRSI = { 118,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo ib_emlrtRSI = { 119,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo jb_emlrtRSI = { 126,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo kb_emlrtRSI = { 127,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo lb_emlrtRSI = { 128,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo mb_emlrtRSI = { 135,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo nb_emlrtRSI = { 136,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo ob_emlrtRSI = { 137,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo pb_emlrtRSI = { 144,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo qb_emlrtRSI = { 145,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo rb_emlrtRSI = { 146,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo sb_emlrtRSI = { 153,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo tb_emlrtRSI = { 154,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo ub_emlrtRSI = { 155,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo vb_emlrtRSI = { 162,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo wb_emlrtRSI = { 163,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo xb_emlrtRSI = { 164,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo yb_emlrtRSI = { 171,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo ac_emlrtRSI = { 172,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo bc_emlrtRSI = { 173,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo cc_emlrtRSI = { 174,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo dc_emlrtRSI = { 181,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo ec_emlrtRSI = { 182,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo fc_emlrtRSI = { 183,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo gc_emlrtRSI = { 184,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo hc_emlrtRSI = { 191,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo ic_emlrtRSI = { 192,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo jc_emlrtRSI = { 193,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo kc_emlrtRSI = { 194,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo lc_emlrtRSI = { 201,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo mc_emlrtRSI = { 202,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo nc_emlrtRSI = { 203,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo oc_emlrtRSI = { 204,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo pc_emlrtRSI = { 211,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo qc_emlrtRSI = { 212,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo rc_emlrtRSI = { 213,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo sc_emlrtRSI = { 214,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo tc_emlrtRSI = { 221,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo uc_emlrtRSI = { 222,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo vc_emlrtRSI = { 223,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo wc_emlrtRSI = { 224,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo xc_emlrtRSI = { 231,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo yc_emlrtRSI = { 232,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo ad_emlrtRSI = { 233,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo bd_emlrtRSI = { 234,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo cd_emlrtRSI = { 241,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo dd_emlrtRSI = { 242,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo ed_emlrtRSI = { 243,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo fd_emlrtRSI = { 244,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo gd_emlrtRSI = { 251,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo hd_emlrtRSI = { 252,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo id_emlrtRSI = { 253,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo jd_emlrtRSI = { 254,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo kd_emlrtRSI = { 261,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo ld_emlrtRSI = { 262,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo md_emlrtRSI = { 263,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo nd_emlrtRSI = { 264,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo od_emlrtRSI = { 271,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo pd_emlrtRSI = { 272,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo qd_emlrtRSI = { 273,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo rd_emlrtRSI = { 274,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo sd_emlrtRSI = { 281,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo td_emlrtRSI = { 282,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo ud_emlrtRSI = { 283,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo vd_emlrtRSI = { 284,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo wd_emlrtRSI = { 291,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo xd_emlrtRSI = { 292,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo yd_emlrtRSI = { 293,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo ae_emlrtRSI = { 294,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo be_emlrtRSI = { 301,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo ce_emlrtRSI = { 302,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo de_emlrtRSI = { 303,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo ee_emlrtRSI = { 304,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo fe_emlrtRSI = { 311,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo ge_emlrtRSI = { 312,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo he_emlrtRSI = { 313,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo ie_emlrtRSI = { 314,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo je_emlrtRSI = { 321,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo ke_emlrtRSI = { 322,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo le_emlrtRSI = { 323,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo me_emlrtRSI = { 324,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo ne_emlrtRSI = { 331,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo oe_emlrtRSI = { 332,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo pe_emlrtRSI = { 333,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo qe_emlrtRSI = { 334,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo re_emlrtRSI = { 341,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo se_emlrtRSI = { 342,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo te_emlrtRSI = { 343,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo ue_emlrtRSI = { 344,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo ve_emlrtRSI = { 351,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo we_emlrtRSI = { 352,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo xe_emlrtRSI = { 353,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo ye_emlrtRSI = { 354,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo af_emlrtRSI = { 361,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo bf_emlrtRSI = { 362,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo cf_emlrtRSI = { 363,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo df_emlrtRSI = { 364,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo ef_emlrtRSI = { 371,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo ff_emlrtRSI = { 372,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo gf_emlrtRSI = { 373,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo hf_emlrtRSI = { 374,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo if_emlrtRSI = { 381,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo jf_emlrtRSI = { 382,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo kf_emlrtRSI = { 383,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo lf_emlrtRSI = { 384,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo mf_emlrtRSI = { 391,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo nf_emlrtRSI = { 392,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo of_emlrtRSI = { 393,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo pf_emlrtRSI = { 394,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo qf_emlrtRSI = { 401,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo rf_emlrtRSI = { 402,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo sf_emlrtRSI = { 403,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo tf_emlrtRSI = { 404,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo uf_emlrtRSI = { 407,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo vf_emlrtRSI = { 409,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo wf_emlrtRSI = { 411,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo xf_emlrtRSI = { 413,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo yf_emlrtRSI = { 415,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo ag_emlrtRSI = { 417,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo bg_emlrtRSI = { 421,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo cg_emlrtRSI = { 423,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo dg_emlrtRSI = { 425,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo eg_emlrtRSI = { 429,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo fg_emlrtRSI = { 431,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo gg_emlrtRSI = { 433,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo hg_emlrtRSI = { 435,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo ig_emlrtRSI = { 437,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo jg_emlrtRSI = { 439,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo kg_emlrtRSI = { 441,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo lg_emlrtRSI = { 445,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo mg_emlrtRSI = { 447,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo ng_emlrtRSI = { 449,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo og_emlrtRSI = { 453,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo pg_emlrtRSI = { 458,/* lineNo */
  "EOM",                               /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pathName */
};

static emlrtRSInfo yg_emlrtRSI = { 21, /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pathName */
};

static emlrtRTEInfo b_emlrtRTEI = { 83,/* lineNo */
  23,                                  /* colNo */
  "eml_mtimes_helper",                 /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 88,/* lineNo */
  23,                                  /* colNo */
  "eml_mtimes_helper",                 /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 400,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 390,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 380,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 370,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 360,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 350,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 340,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 330,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 320,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtRTEInfo m_emlrtRTEI = { 310,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 300,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtRTEInfo o_emlrtRTEI = { 290,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtRTEInfo p_emlrtRTEI = { 280,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtRTEInfo q_emlrtRTEI = { 270,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtRTEInfo r_emlrtRTEI = { 260,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtRTEInfo s_emlrtRTEI = { 250,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtRTEInfo t_emlrtRTEI = { 240,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtRTEInfo u_emlrtRTEI = { 230,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtRTEInfo v_emlrtRTEI = { 220,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtRTEInfo w_emlrtRTEI = { 210,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtRTEInfo x_emlrtRTEI = { 200,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtRTEInfo y_emlrtRTEI = { 190,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = { 180,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = { 170,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = { 161,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtRTEInfo db_emlrtRTEI = { 152,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = { 143,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtRTEInfo fb_emlrtRTEI = { 134,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtRTEInfo gb_emlrtRTEI = { 125,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtRTEInfo hb_emlrtRTEI = { 116,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtRTEInfo ib_emlrtRTEI = { 107,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtRTEInfo jb_emlrtRTEI = { 98,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtRTEInfo kb_emlrtRTEI = { 89,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = { 80,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtRTEInfo mb_emlrtRTEI = { 71,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtRTEInfo nb_emlrtRTEI = { 62,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtRTEInfo ob_emlrtRTEI = { 53,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtRTEInfo pb_emlrtRTEI = { 44,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtRTEInfo qb_emlrtRTEI = { 35,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtRTEInfo rb_emlrtRTEI = { 26,/* lineNo */
  9,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  10,                                  /* lineNo */
  13,                                  /* colNo */
  "u",                                 /* aName */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo emlrtDCI = { 10,    /* lineNo */
  13,                                  /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  10,                                  /* lineNo */
  9,                                   /* colNo */
  "u",                                 /* aName */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { 1,   /* iFirst */
  206,                                 /* iLast */
  9,                                   /* lineNo */
  8,                                   /* colNo */
  "z",                                 /* aName */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 9,   /* lineNo */
  8,                                   /* colNo */
  "EOM",                               /* fName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/EOM.m",/* pName */
  1                                    /* checkKind */
};

/* Function Definitions */
void EOM(EOMStackData *SD, const emlrtStack *sp, real_T t, const real_T z[206],
         const struct0_T *par, real_T dz_data[], int32_T dz_size[1])
{
  real_T alpha1;
  int32_T i;
  int32_T i0;
  int32_T u_size_idx_0_tmp;
  int32_T i1;
  real_T u_data[206];
  int32_T loop_ub;
  int32_T iv0[2];
  real_T uq_data[206];
  real_T b_TMT[8281];
  real_T TMfd[91];
  real_T w_vd_j[91];
  real_T w_sd[91];
  real_T w_in[91];
  real_T s0;
  real_T ds;
  int32_T s;
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
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0024, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0E-9,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0E-9, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0E-9 };

  real_T a[546];
  static const real_T b_b[36] = { 0.0024, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0024,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0024, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    4.2759999999999987E-8, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 8.5263999999999975E-8,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 4.2759999999999987E-8 };

  real_T y[8281];
  real_T b_y[6];
  real_T c_y[91];
  real_T in[6];
  real_T reshapes_f2[91];
  real_T tc[91];
  real_T b_tc[91];
  real_T d_y;
  real_T c_tc[91];
  real_T e_y;
  real_T d_tc[91];
  real_T f_y;
  real_T e_tc[91];
  real_T g_y;
  real_T f_tc[91];
  real_T h_y;
  real_T g_tc[91];
  real_T i_y;
  real_T h_tc[91];
  real_T j_y;
  real_T i_tc[91];
  real_T k_y;
  real_T j_tc[91];
  real_T l_y;
  real_T k_tc[91];
  real_T Tc[1092];
  real_T dzt[103];
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (t > t_report) {
    emlrtDisplayR2012b(emlrt_marshallOut(t), "t", &emlrtRTEI, sp);
    t_report = t + par->t_rep;
    t_report_dirty |= 1U;
  }

  alpha1 = (par->nq + par->nlambda) + 1.0;
  if (alpha1 > 206.0) {
    i = 0;
    i0 = 0;
  } else {
    if (alpha1 != (int32_T)muDoubleScalarFloor(alpha1)) {
      emlrtIntegerCheckR2012b(alpha1, &b_emlrtDCI, sp);
    }

    i = (int32_T)alpha1;
    if ((i < 1) || (i > 206)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 206, &c_emlrtBCI, sp);
    }

    i--;
    i0 = 206;
  }

  u_size_idx_0_tmp = i0 - i;
  for (i1 = 0; i1 < u_size_idx_0_tmp; i1++) {
    u_data[i1] = z[i + i1];
  }

  if (1.0 > par->nq) {
    loop_ub = 0;
  } else {
    if (1 > u_size_idx_0_tmp) {
      emlrtDynamicBoundsCheckR2012b(1, 1, u_size_idx_0_tmp, &b_emlrtBCI, sp);
    }

    if (par->nq != (int32_T)muDoubleScalarFloor(par->nq)) {
      emlrtIntegerCheckR2012b(par->nq, &emlrtDCI, sp);
    }

    loop_ub = (int32_T)par->nq;
    if ((loop_ub < 1) || (loop_ub > u_size_idx_0_tmp)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, u_size_idx_0_tmp, &emlrtBCI, sp);
    }
  }

  iv0[0] = 1;
  iv0[1] = loop_ub;
  st.site = &emlrtRSI;
  indexShapeCheck(&st, i0 - i, iv0);
  if (0 <= loop_ub - 1) {
    memcpy(&uq_data[0], &u_data[0], (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
  }

  /*   */
  /*  step = floor( t / par.sample_t ) ; */
  /*  u_c = par.ddr_arm_x( step ) ; */
  /*  par.var(5) = u_c ; */
  /*   */
  /*  % z = real( z ) ; */
  memset(&b_TMT[0], 0, 8281U * sizeof(real_T));
  memset(&TMfd[0], 0, 91U * sizeof(real_T));
  memset(&w_vd_j[0], 0, 91U * sizeof(real_T));
  memset(&w_sd[0], 0, 91U * sizeof(real_T));
  memset(&w_in[0], 0, 91U * sizeof(real_T));
  s0 = 1.0E-6;
  ds = par->rom.mass[0] / par->n_int;
  if (par->rom.mass[0] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par->rom.mass[0] - s0;
  i = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i, &rb_emlrtRTEI,
    sp);
  for (s = 0; s < i; s++) {
    st.site = &b_emlrtRSI;
    massF1(z, T, Dd, fg);
    st.site = &c_emlrtRSI;
    for (i0 = 0; i0 < 6; i0++) {
      for (i1 = 0; i1 < 91; i1++) {
        a_tmp[i1 + 91 * i0] = T[i0 + 6 * i1];
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &c_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &s0, &y[0], &ldc_t);
    for (i0 = 0; i0 < 8281; i0++) {
      b_TMT[i0] += y[i0] * ds;
    }

    st.site = &d_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &d_emlrtRSI;
    for (i0 = 0; i0 < 546; i0++) {
      Dd[i0] = -Dd[i0];
    }

    b_st.site = &yg_emlrtRSI;
    if (91 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI, "MATLAB:innerdim",
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Dd[0], &lda_t, &uq_data
          [0], &ldb_t, &s0, &b_y[0], &ldc_t);
    for (i0 = 0; i0 < 6; i0++) {
      b_y[i0] += fg[i0];
    }

    st.site = &d_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      TMfd[i0] += c_y[i0] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par->rom.mass[1] / par->n_int;
  if (par->rom.mass[1] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par->rom.mass[1] - s0;
  i = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i, &qb_emlrtRTEI,
    sp);
  for (s = 0; s < i; s++) {
    st.site = &e_emlrtRSI;
    massF2(&st, z, T, Dd, fg);
    st.site = &f_emlrtRSI;
    for (i0 = 0; i0 < 6; i0++) {
      for (i1 = 0; i1 < 91; i1++) {
        a_tmp[i1 + 91 * i0] = T[i0 + 6 * i1];
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b_b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &f_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &s0, &y[0], &ldc_t);
    for (i0 = 0; i0 < 8281; i0++) {
      b_TMT[i0] += y[i0] * ds;
    }

    st.site = &g_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b_b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &g_emlrtRSI;
    for (i0 = 0; i0 < 546; i0++) {
      Dd[i0] = -Dd[i0];
    }

    b_st.site = &yg_emlrtRSI;
    if (91 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI, "MATLAB:innerdim",
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Dd[0], &lda_t, &uq_data
          [0], &ldb_t, &s0, &b_y[0], &ldc_t);
    for (i0 = 0; i0 < 6; i0++) {
      b_y[i0] += fg[i0];
    }

    st.site = &g_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      TMfd[i0] += c_y[i0] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par->rom.mass[2] / par->n_int;
  if (par->rom.mass[2] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par->rom.mass[2] - s0;
  i = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i, &pb_emlrtRTEI,
    sp);
  for (s = 0; s < i; s++) {
    st.site = &h_emlrtRSI;
    massF3(&st, z, T, Dd, fg);
    st.site = &i_emlrtRSI;
    for (i0 = 0; i0 < 6; i0++) {
      for (i1 = 0; i1 < 91; i1++) {
        a_tmp[i1 + 91 * i0] = T[i0 + 6 * i1];
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b_b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &i_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &s0, &y[0], &ldc_t);
    for (i0 = 0; i0 < 8281; i0++) {
      b_TMT[i0] += y[i0] * ds;
    }

    st.site = &j_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b_b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &j_emlrtRSI;
    for (i0 = 0; i0 < 546; i0++) {
      Dd[i0] = -Dd[i0];
    }

    b_st.site = &yg_emlrtRSI;
    if (91 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI, "MATLAB:innerdim",
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Dd[0], &lda_t, &uq_data
          [0], &ldb_t, &s0, &b_y[0], &ldc_t);
    for (i0 = 0; i0 < 6; i0++) {
      b_y[i0] += fg[i0];
    }

    st.site = &j_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      TMfd[i0] += c_y[i0] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par->rom.mass[3] / par->n_int;
  if (par->rom.mass[3] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par->rom.mass[3] - s0;
  i = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i, &ob_emlrtRTEI,
    sp);
  for (s = 0; s < i; s++) {
    st.site = &k_emlrtRSI;
    massF4(&st, z, T, Dd, fg);
    st.site = &l_emlrtRSI;
    for (i0 = 0; i0 < 6; i0++) {
      for (i1 = 0; i1 < 91; i1++) {
        a_tmp[i1 + 91 * i0] = T[i0 + 6 * i1];
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b_b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &l_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &s0, &y[0], &ldc_t);
    for (i0 = 0; i0 < 8281; i0++) {
      b_TMT[i0] += y[i0] * ds;
    }

    st.site = &m_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b_b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &m_emlrtRSI;
    for (i0 = 0; i0 < 546; i0++) {
      Dd[i0] = -Dd[i0];
    }

    b_st.site = &yg_emlrtRSI;
    if (91 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI, "MATLAB:innerdim",
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Dd[0], &lda_t, &uq_data
          [0], &ldb_t, &s0, &b_y[0], &ldc_t);
    for (i0 = 0; i0 < 6; i0++) {
      b_y[i0] += fg[i0];
    }

    st.site = &m_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      TMfd[i0] += c_y[i0] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par->rom.mass[4] / par->n_int;
  if (par->rom.mass[4] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par->rom.mass[4] - s0;
  i = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i, &nb_emlrtRTEI,
    sp);
  for (s = 0; s < i; s++) {
    st.site = &n_emlrtRSI;
    massF5(&st, z, T, Dd, fg);
    st.site = &o_emlrtRSI;
    for (i0 = 0; i0 < 6; i0++) {
      for (i1 = 0; i1 < 91; i1++) {
        a_tmp[i1 + 91 * i0] = T[i0 + 6 * i1];
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b_b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &o_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &s0, &y[0], &ldc_t);
    for (i0 = 0; i0 < 8281; i0++) {
      b_TMT[i0] += y[i0] * ds;
    }

    st.site = &p_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b_b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &p_emlrtRSI;
    for (i0 = 0; i0 < 546; i0++) {
      Dd[i0] = -Dd[i0];
    }

    b_st.site = &yg_emlrtRSI;
    if (91 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI, "MATLAB:innerdim",
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Dd[0], &lda_t, &uq_data
          [0], &ldb_t, &s0, &b_y[0], &ldc_t);
    for (i0 = 0; i0 < 6; i0++) {
      b_y[i0] += fg[i0];
    }

    st.site = &p_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      TMfd[i0] += c_y[i0] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par->rom.mass[5] / par->n_int;
  if (par->rom.mass[5] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par->rom.mass[5] - s0;
  i = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i, &mb_emlrtRTEI,
    sp);
  for (s = 0; s < i; s++) {
    st.site = &q_emlrtRSI;
    massF6(&st, z, T, Dd, fg);
    st.site = &r_emlrtRSI;
    for (i0 = 0; i0 < 6; i0++) {
      for (i1 = 0; i1 < 91; i1++) {
        a_tmp[i1 + 91 * i0] = T[i0 + 6 * i1];
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b_b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &r_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &s0, &y[0], &ldc_t);
    for (i0 = 0; i0 < 8281; i0++) {
      b_TMT[i0] += y[i0] * ds;
    }

    st.site = &s_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b_b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &s_emlrtRSI;
    for (i0 = 0; i0 < 546; i0++) {
      Dd[i0] = -Dd[i0];
    }

    b_st.site = &yg_emlrtRSI;
    if (91 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI, "MATLAB:innerdim",
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Dd[0], &lda_t, &uq_data
          [0], &ldb_t, &s0, &b_y[0], &ldc_t);
    for (i0 = 0; i0 < 6; i0++) {
      b_y[i0] += fg[i0];
    }

    st.site = &s_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      TMfd[i0] += c_y[i0] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par->rom.mass[6] / par->n_int;
  if (par->rom.mass[6] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par->rom.mass[6] - s0;
  i = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i, &lb_emlrtRTEI,
    sp);
  for (s = 0; s < i; s++) {
    st.site = &t_emlrtRSI;
    massF7(&st, z, T, Dd, fg);
    st.site = &u_emlrtRSI;
    for (i0 = 0; i0 < 6; i0++) {
      for (i1 = 0; i1 < 91; i1++) {
        a_tmp[i1 + 91 * i0] = T[i0 + 6 * i1];
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b_b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &u_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &s0, &y[0], &ldc_t);
    for (i0 = 0; i0 < 8281; i0++) {
      b_TMT[i0] += y[i0] * ds;
    }

    st.site = &v_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b_b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &v_emlrtRSI;
    for (i0 = 0; i0 < 546; i0++) {
      Dd[i0] = -Dd[i0];
    }

    b_st.site = &yg_emlrtRSI;
    if (91 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI, "MATLAB:innerdim",
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Dd[0], &lda_t, &uq_data
          [0], &ldb_t, &s0, &b_y[0], &ldc_t);
    for (i0 = 0; i0 < 6; i0++) {
      b_y[i0] += fg[i0];
    }

    st.site = &v_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      TMfd[i0] += c_y[i0] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par->rom.mass[7] / par->n_int;
  if (par->rom.mass[7] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par->rom.mass[7] - s0;
  i = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i, &kb_emlrtRTEI,
    sp);
  for (s = 0; s < i; s++) {
    st.site = &w_emlrtRSI;
    massF8(&st, z, T, Dd, fg);
    st.site = &x_emlrtRSI;
    for (i0 = 0; i0 < 6; i0++) {
      for (i1 = 0; i1 < 91; i1++) {
        a_tmp[i1 + 91 * i0] = T[i0 + 6 * i1];
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b_b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &x_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &s0, &y[0], &ldc_t);
    for (i0 = 0; i0 < 8281; i0++) {
      b_TMT[i0] += y[i0] * ds;
    }

    st.site = &y_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b_b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &y_emlrtRSI;
    for (i0 = 0; i0 < 546; i0++) {
      Dd[i0] = -Dd[i0];
    }

    b_st.site = &yg_emlrtRSI;
    if (91 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI, "MATLAB:innerdim",
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Dd[0], &lda_t, &uq_data
          [0], &ldb_t, &s0, &b_y[0], &ldc_t);
    for (i0 = 0; i0 < 6; i0++) {
      b_y[i0] += fg[i0];
    }

    st.site = &y_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      TMfd[i0] += c_y[i0] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par->rom.mass[8] / par->n_int;
  if (par->rom.mass[8] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par->rom.mass[8] - s0;
  i = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i, &jb_emlrtRTEI,
    sp);
  for (s = 0; s < i; s++) {
    st.site = &ab_emlrtRSI;
    massF9(&st, z, T, Dd, fg);
    st.site = &bb_emlrtRSI;
    for (i0 = 0; i0 < 6; i0++) {
      for (i1 = 0; i1 < 91; i1++) {
        a_tmp[i1 + 91 * i0] = T[i0 + 6 * i1];
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b_b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &bb_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &s0, &y[0], &ldc_t);
    for (i0 = 0; i0 < 8281; i0++) {
      b_TMT[i0] += y[i0] * ds;
    }

    st.site = &cb_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b_b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &cb_emlrtRSI;
    for (i0 = 0; i0 < 546; i0++) {
      Dd[i0] = -Dd[i0];
    }

    b_st.site = &yg_emlrtRSI;
    if (91 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI, "MATLAB:innerdim",
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Dd[0], &lda_t, &uq_data
          [0], &ldb_t, &s0, &b_y[0], &ldc_t);
    for (i0 = 0; i0 < 6; i0++) {
      b_y[i0] += fg[i0];
    }

    st.site = &cb_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      TMfd[i0] += c_y[i0] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par->rom.mass[9] / par->n_int;
  if (par->rom.mass[9] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par->rom.mass[9] - s0;
  i = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i, &ib_emlrtRTEI,
    sp);
  for (s = 0; s < i; s++) {
    st.site = &db_emlrtRSI;
    massF10(&st, z, T, Dd, fg);
    st.site = &eb_emlrtRSI;
    for (i0 = 0; i0 < 6; i0++) {
      for (i1 = 0; i1 < 91; i1++) {
        a_tmp[i1 + 91 * i0] = T[i0 + 6 * i1];
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b_b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &eb_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &s0, &y[0], &ldc_t);
    for (i0 = 0; i0 < 8281; i0++) {
      b_TMT[i0] += y[i0] * ds;
    }

    st.site = &fb_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b_b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &fb_emlrtRSI;
    for (i0 = 0; i0 < 546; i0++) {
      Dd[i0] = -Dd[i0];
    }

    b_st.site = &yg_emlrtRSI;
    if (91 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI, "MATLAB:innerdim",
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Dd[0], &lda_t, &uq_data
          [0], &ldb_t, &s0, &b_y[0], &ldc_t);
    for (i0 = 0; i0 < 6; i0++) {
      b_y[i0] += fg[i0];
    }

    st.site = &fb_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      TMfd[i0] += c_y[i0] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par->rom.mass[10] / par->n_int;
  if (par->rom.mass[10] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par->rom.mass[10] - s0;
  i = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i, &hb_emlrtRTEI,
    sp);
  for (s = 0; s < i; s++) {
    st.site = &gb_emlrtRSI;
    massF11(&st, z, T, Dd, fg);
    st.site = &hb_emlrtRSI;
    for (i0 = 0; i0 < 6; i0++) {
      for (i1 = 0; i1 < 91; i1++) {
        a_tmp[i1 + 91 * i0] = T[i0 + 6 * i1];
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b_b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &hb_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &s0, &y[0], &ldc_t);
    for (i0 = 0; i0 < 8281; i0++) {
      b_TMT[i0] += y[i0] * ds;
    }

    st.site = &ib_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b_b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &ib_emlrtRSI;
    for (i0 = 0; i0 < 546; i0++) {
      Dd[i0] = -Dd[i0];
    }

    b_st.site = &yg_emlrtRSI;
    if (91 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI, "MATLAB:innerdim",
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Dd[0], &lda_t, &uq_data
          [0], &ldb_t, &s0, &b_y[0], &ldc_t);
    for (i0 = 0; i0 < 6; i0++) {
      b_y[i0] += fg[i0];
    }

    st.site = &ib_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      TMfd[i0] += c_y[i0] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par->rom.mass[11] / par->n_int;
  if (par->rom.mass[11] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par->rom.mass[11] - s0;
  i = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i, &gb_emlrtRTEI,
    sp);
  for (s = 0; s < i; s++) {
    st.site = &jb_emlrtRSI;
    massF12(&st, z, T, Dd, fg);
    st.site = &kb_emlrtRSI;
    for (i0 = 0; i0 < 6; i0++) {
      for (i1 = 0; i1 < 91; i1++) {
        a_tmp[i1 + 91 * i0] = T[i0 + 6 * i1];
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b_b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &kb_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &s0, &y[0], &ldc_t);
    for (i0 = 0; i0 < 8281; i0++) {
      b_TMT[i0] += y[i0] * ds;
    }

    st.site = &lb_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b_b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &lb_emlrtRSI;
    for (i0 = 0; i0 < 546; i0++) {
      Dd[i0] = -Dd[i0];
    }

    b_st.site = &yg_emlrtRSI;
    if (91 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI, "MATLAB:innerdim",
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Dd[0], &lda_t, &uq_data
          [0], &ldb_t, &s0, &b_y[0], &ldc_t);
    for (i0 = 0; i0 < 6; i0++) {
      b_y[i0] += fg[i0];
    }

    st.site = &lb_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      TMfd[i0] += c_y[i0] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par->rom.mass[12] / par->n_int;
  if (par->rom.mass[12] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par->rom.mass[12] - s0;
  i = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i, &fb_emlrtRTEI,
    sp);
  for (s = 0; s < i; s++) {
    st.site = &mb_emlrtRSI;
    massF13(&st, z, T, Dd, fg);
    st.site = &nb_emlrtRSI;
    for (i0 = 0; i0 < 6; i0++) {
      for (i1 = 0; i1 < 91; i1++) {
        a_tmp[i1 + 91 * i0] = T[i0 + 6 * i1];
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b_b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &nb_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &s0, &y[0], &ldc_t);
    for (i0 = 0; i0 < 8281; i0++) {
      b_TMT[i0] += y[i0] * ds;
    }

    st.site = &ob_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b_b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &ob_emlrtRSI;
    for (i0 = 0; i0 < 546; i0++) {
      Dd[i0] = -Dd[i0];
    }

    b_st.site = &yg_emlrtRSI;
    if (91 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI, "MATLAB:innerdim",
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Dd[0], &lda_t, &uq_data
          [0], &ldb_t, &s0, &b_y[0], &ldc_t);
    for (i0 = 0; i0 < 6; i0++) {
      b_y[i0] += fg[i0];
    }

    st.site = &ob_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      TMfd[i0] += c_y[i0] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par->rom.mass[13] / par->n_int;
  if (par->rom.mass[13] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par->rom.mass[13] - s0;
  i = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i, &eb_emlrtRTEI,
    sp);
  for (s = 0; s < i; s++) {
    st.site = &pb_emlrtRSI;
    massF14(&st, z, T, Dd, fg);
    st.site = &qb_emlrtRSI;
    for (i0 = 0; i0 < 6; i0++) {
      for (i1 = 0; i1 < 91; i1++) {
        a_tmp[i1 + 91 * i0] = T[i0 + 6 * i1];
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b_b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &qb_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &s0, &y[0], &ldc_t);
    for (i0 = 0; i0 < 8281; i0++) {
      b_TMT[i0] += y[i0] * ds;
    }

    st.site = &rb_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b_b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &rb_emlrtRSI;
    for (i0 = 0; i0 < 546; i0++) {
      Dd[i0] = -Dd[i0];
    }

    b_st.site = &yg_emlrtRSI;
    if (91 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI, "MATLAB:innerdim",
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Dd[0], &lda_t, &uq_data
          [0], &ldb_t, &s0, &b_y[0], &ldc_t);
    for (i0 = 0; i0 < 6; i0++) {
      b_y[i0] += fg[i0];
    }

    st.site = &rb_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      TMfd[i0] += c_y[i0] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par->rom.mass[14] / par->n_int;
  if (par->rom.mass[14] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par->rom.mass[14] - s0;
  i = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i, &db_emlrtRTEI,
    sp);
  for (s = 0; s < i; s++) {
    st.site = &sb_emlrtRSI;
    massF15(&st, z, T, Dd, fg);
    st.site = &tb_emlrtRSI;
    for (i0 = 0; i0 < 6; i0++) {
      for (i1 = 0; i1 < 91; i1++) {
        a_tmp[i1 + 91 * i0] = T[i0 + 6 * i1];
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b_b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &tb_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &s0, &y[0], &ldc_t);
    for (i0 = 0; i0 < 8281; i0++) {
      b_TMT[i0] += y[i0] * ds;
    }

    st.site = &ub_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b_b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &ub_emlrtRSI;
    for (i0 = 0; i0 < 546; i0++) {
      Dd[i0] = -Dd[i0];
    }

    b_st.site = &yg_emlrtRSI;
    if (91 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI, "MATLAB:innerdim",
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Dd[0], &lda_t, &uq_data
          [0], &ldb_t, &s0, &b_y[0], &ldc_t);
    for (i0 = 0; i0 < 6; i0++) {
      b_y[i0] += fg[i0];
    }

    st.site = &ub_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      TMfd[i0] += c_y[i0] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par->rom.mass[15] / par->n_int;
  if (par->rom.mass[15] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par->rom.mass[15] - s0;
  i = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i, &cb_emlrtRTEI,
    sp);
  for (s = 0; s < i; s++) {
    st.site = &vb_emlrtRSI;
    massF16(&st, z, T, Dd, fg);
    st.site = &wb_emlrtRSI;
    for (i0 = 0; i0 < 6; i0++) {
      for (i1 = 0; i1 < 91; i1++) {
        a_tmp[i1 + 91 * i0] = T[i0 + 6 * i1];
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b_b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &wb_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &T[0],
          &ldb_t, &s0, &y[0], &ldc_t);
    for (i0 = 0; i0 < 8281; i0++) {
      b_TMT[i0] += y[i0] * ds;
    }

    st.site = &xb_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_tmp[0], &lda_t, &b_b[0],
          &ldb_t, &s0, &a[0], &ldc_t);
    st.site = &xb_emlrtRSI;
    for (i0 = 0; i0 < 546; i0++) {
      Dd[i0] = -Dd[i0];
    }

    b_st.site = &yg_emlrtRSI;
    if (91 != loop_ub) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI, "MATLAB:innerdim",
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Dd[0], &lda_t, &uq_data
          [0], &ldb_t, &s0, &b_y[0], &ldc_t);
    for (i0 = 0; i0 < 6; i0++) {
      b_y[i0] += fg[i0];
    }

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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      TMfd[i0] += c_y[i0] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par->rom.sprdmp[91] / par->n_int;
  if (par->rom.sprdmp[91] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par->rom.sprdmp[91] - s0;
  i = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i, &bb_emlrtRTEI,
    sp);
  for (s = 0; s < i; s++) {
    st.site = &yb_emlrtRSI;
    sprdmpF92(&st, par->var, z, T, fg, b_y, in);
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_vd_j[i0] += c_y[i0] * ds;
    }

    st.site = &bc_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_sd[i0] += c_y[i0] * ds;
    }

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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_in[i0] += c_y[i0] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par->rom.sprdmp[92] / par->n_int;
  if (par->rom.sprdmp[92] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par->rom.sprdmp[92] - s0;
  i = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i, &ab_emlrtRTEI,
    sp);
  for (s = 0; s < i; s++) {
    st.site = &dc_emlrtRSI;
    sprdmpF93(&st, par->var, z, T, fg, b_y, in);
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_vd_j[i0] += c_y[i0] * ds;
    }

    st.site = &fc_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_sd[i0] += c_y[i0] * ds;
    }

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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_in[i0] += c_y[i0] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par->rom.sprdmp[93] / par->n_int;
  if (par->rom.sprdmp[93] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par->rom.sprdmp[93] - s0;
  i = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i, &y_emlrtRTEI,
    sp);
  for (s = 0; s < i; s++) {
    st.site = &hc_emlrtRSI;
    sprdmpF94(&st, par->var, z, T, fg, b_y, in);
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_vd_j[i0] += c_y[i0] * ds;
    }

    st.site = &jc_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_sd[i0] += c_y[i0] * ds;
    }

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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_in[i0] += c_y[i0] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par->rom.sprdmp[94] / par->n_int;
  if (par->rom.sprdmp[94] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par->rom.sprdmp[94] - s0;
  i = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i, &x_emlrtRTEI,
    sp);
  for (s = 0; s < i; s++) {
    st.site = &lc_emlrtRSI;
    sprdmpF95(&st, par->var, z, T, fg, b_y, in);
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_vd_j[i0] += c_y[i0] * ds;
    }

    st.site = &nc_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_sd[i0] += c_y[i0] * ds;
    }

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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_in[i0] += c_y[i0] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par->rom.sprdmp[95] / par->n_int;
  if (par->rom.sprdmp[95] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par->rom.sprdmp[95] - s0;
  i = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i, &w_emlrtRTEI,
    sp);
  for (s = 0; s < i; s++) {
    st.site = &pc_emlrtRSI;
    sprdmpF96(&st, par->var, z, T, fg, b_y, in);
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_vd_j[i0] += c_y[i0] * ds;
    }

    st.site = &rc_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_sd[i0] += c_y[i0] * ds;
    }

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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_in[i0] += c_y[i0] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par->rom.sprdmp[96] / par->n_int;
  if (par->rom.sprdmp[96] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par->rom.sprdmp[96] - s0;
  i = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i, &v_emlrtRTEI,
    sp);
  for (s = 0; s < i; s++) {
    st.site = &tc_emlrtRSI;
    sprdmpF97(&st, par->var, z, T, fg, b_y, in);
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_vd_j[i0] += c_y[i0] * ds;
    }

    st.site = &vc_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_sd[i0] += c_y[i0] * ds;
    }

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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_in[i0] += c_y[i0] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par->rom.sprdmp[97] / par->n_int;
  if (par->rom.sprdmp[97] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par->rom.sprdmp[97] - s0;
  i = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i, &u_emlrtRTEI,
    sp);
  for (s = 0; s < i; s++) {
    st.site = &xc_emlrtRSI;
    sprdmpF98(&st, par->var, z, T, fg, b_y, in);
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_vd_j[i0] += c_y[i0] * ds;
    }

    st.site = &ad_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_sd[i0] += c_y[i0] * ds;
    }

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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_in[i0] += c_y[i0] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par->rom.sprdmp[98] / par->n_int;
  if (par->rom.sprdmp[98] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par->rom.sprdmp[98] - s0;
  i = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i, &t_emlrtRTEI,
    sp);
  for (s = 0; s < i; s++) {
    st.site = &cd_emlrtRSI;
    sprdmpF99(&st, par->var, z, T, fg, b_y, in);
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_vd_j[i0] += c_y[i0] * ds;
    }

    st.site = &ed_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_sd[i0] += c_y[i0] * ds;
    }

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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_in[i0] += c_y[i0] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par->rom.sprdmp[99] / par->n_int;
  if (par->rom.sprdmp[99] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par->rom.sprdmp[99] - s0;
  i = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i, &s_emlrtRTEI,
    sp);
  for (s = 0; s < i; s++) {
    st.site = &gd_emlrtRSI;
    sprdmpF100(&st, par->var, z, T, fg, b_y, in);
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_vd_j[i0] += c_y[i0] * ds;
    }

    st.site = &id_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_sd[i0] += c_y[i0] * ds;
    }

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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_in[i0] += c_y[i0] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par->rom.sprdmp[100] / par->n_int;
  if (par->rom.sprdmp[100] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par->rom.sprdmp[100] - s0;
  i = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i, &r_emlrtRTEI,
    sp);
  for (s = 0; s < i; s++) {
    st.site = &kd_emlrtRSI;
    sprdmpF101(&st, par->var, z, T, fg, b_y, in);
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_vd_j[i0] += c_y[i0] * ds;
    }

    st.site = &md_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_sd[i0] += c_y[i0] * ds;
    }

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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_in[i0] += c_y[i0] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par->rom.sprdmp[101] / par->n_int;
  if (par->rom.sprdmp[101] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par->rom.sprdmp[101] - s0;
  i = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i, &q_emlrtRTEI,
    sp);
  for (s = 0; s < i; s++) {
    st.site = &od_emlrtRSI;
    sprdmpF102(&st, par->var, z, T, fg, b_y, in);
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_vd_j[i0] += c_y[i0] * ds;
    }

    st.site = &qd_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_sd[i0] += c_y[i0] * ds;
    }

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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_in[i0] += c_y[i0] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par->rom.sprdmp[102] / par->n_int;
  if (par->rom.sprdmp[102] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par->rom.sprdmp[102] - s0;
  i = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i, &p_emlrtRTEI,
    sp);
  for (s = 0; s < i; s++) {
    st.site = &sd_emlrtRSI;
    sprdmpF103(&st, par->var, z, T, fg, b_y, in);
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_vd_j[i0] += c_y[i0] * ds;
    }

    st.site = &ud_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_sd[i0] += c_y[i0] * ds;
    }

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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_in[i0] += c_y[i0] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par->rom.sprdmp[103] / par->n_int;
  if (par->rom.sprdmp[103] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par->rom.sprdmp[103] - s0;
  i = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i, &o_emlrtRTEI,
    sp);
  for (s = 0; s < i; s++) {
    st.site = &wd_emlrtRSI;
    sprdmpF104(&st, par->var, z, T, fg, b_y, in);
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_vd_j[i0] += c_y[i0] * ds;
    }

    st.site = &yd_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_sd[i0] += c_y[i0] * ds;
    }

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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_in[i0] += c_y[i0] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par->rom.sprdmp[104] / par->n_int;
  if (par->rom.sprdmp[104] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par->rom.sprdmp[104] - s0;
  i = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i, &n_emlrtRTEI,
    sp);
  for (s = 0; s < i; s++) {
    st.site = &be_emlrtRSI;
    sprdmpF105(&st, par->var, z, T, fg, b_y, in);
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_vd_j[i0] += c_y[i0] * ds;
    }

    st.site = &de_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_sd[i0] += c_y[i0] * ds;
    }

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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_in[i0] += c_y[i0] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par->rom.sprdmp[105] / par->n_int;
  if (par->rom.sprdmp[105] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par->rom.sprdmp[105] - s0;
  i = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i, &m_emlrtRTEI,
    sp);
  for (s = 0; s < i; s++) {
    st.site = &fe_emlrtRSI;
    sprdmpF106(&st, par->var, z, T, fg, b_y, in);
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_vd_j[i0] += c_y[i0] * ds;
    }

    st.site = &he_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_sd[i0] += c_y[i0] * ds;
    }

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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_in[i0] += c_y[i0] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par->rom.sprdmp[106] / par->n_int;
  if (par->rom.sprdmp[106] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par->rom.sprdmp[106] - s0;
  i = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i, &l_emlrtRTEI,
    sp);
  for (s = 0; s < i; s++) {
    st.site = &je_emlrtRSI;
    sprdmpF107(&st, par->var, z, T, fg, b_y, in);
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_vd_j[i0] += c_y[i0] * ds;
    }

    st.site = &le_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_sd[i0] += c_y[i0] * ds;
    }

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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_in[i0] += c_y[i0] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par->rom.sprdmp[107] / par->n_int;
  if (par->rom.sprdmp[107] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par->rom.sprdmp[107] - s0;
  i = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i, &k_emlrtRTEI,
    sp);
  for (s = 0; s < i; s++) {
    st.site = &ne_emlrtRSI;
    sprdmpF108(&st, par->var, z, T, fg, b_y, in);
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_vd_j[i0] += c_y[i0] * ds;
    }

    st.site = &pe_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_sd[i0] += c_y[i0] * ds;
    }

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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_in[i0] += c_y[i0] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par->rom.sprdmp[108] / par->n_int;
  if (par->rom.sprdmp[108] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par->rom.sprdmp[108] - s0;
  i = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i, &j_emlrtRTEI,
    sp);
  for (s = 0; s < i; s++) {
    st.site = &re_emlrtRSI;
    sprdmpF109(&st, par->var, z, T, fg, b_y, in);
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_vd_j[i0] += c_y[i0] * ds;
    }

    st.site = &te_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_sd[i0] += c_y[i0] * ds;
    }

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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_in[i0] += c_y[i0] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par->rom.sprdmp[109] / par->n_int;
  if (par->rom.sprdmp[109] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par->rom.sprdmp[109] - s0;
  i = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i, &i_emlrtRTEI,
    sp);
  for (s = 0; s < i; s++) {
    st.site = &ve_emlrtRSI;
    sprdmpF110(&st, par->var, z, T, fg, b_y, in);
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_vd_j[i0] += c_y[i0] * ds;
    }

    st.site = &xe_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_sd[i0] += c_y[i0] * ds;
    }

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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_in[i0] += c_y[i0] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par->rom.sprdmp[110] / par->n_int;
  if (par->rom.sprdmp[110] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par->rom.sprdmp[110] - s0;
  i = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i, &h_emlrtRTEI,
    sp);
  for (s = 0; s < i; s++) {
    st.site = &af_emlrtRSI;
    sprdmpF111(&st, par->var, z, T, fg, b_y, in);
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_vd_j[i0] += c_y[i0] * ds;
    }

    st.site = &cf_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_sd[i0] += c_y[i0] * ds;
    }

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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_in[i0] += c_y[i0] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par->rom.sprdmp[111] / par->n_int;
  if (par->rom.sprdmp[111] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par->rom.sprdmp[111] - s0;
  i = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i, &g_emlrtRTEI,
    sp);
  for (s = 0; s < i; s++) {
    st.site = &ef_emlrtRSI;
    sprdmpF112(&st, z, T, fg, b_y, in);
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_vd_j[i0] += c_y[i0] * ds;
    }

    st.site = &gf_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_sd[i0] += c_y[i0] * ds;
    }

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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_in[i0] += c_y[i0] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par->rom.sprdmp[112] / par->n_int;
  if (par->rom.sprdmp[112] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par->rom.sprdmp[112] - s0;
  i = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i, &f_emlrtRTEI,
    sp);
  for (s = 0; s < i; s++) {
    st.site = &if_emlrtRSI;
    sprdmpF113(&st, par->var, z, T, fg, b_y, in);
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_vd_j[i0] += c_y[i0] * ds;
    }

    st.site = &kf_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_sd[i0] += c_y[i0] * ds;
    }

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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_in[i0] += c_y[i0] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par->rom.sprdmp[113] / par->n_int;
  if (par->rom.sprdmp[113] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par->rom.sprdmp[113] - s0;
  i = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i, &e_emlrtRTEI,
    sp);
  for (s = 0; s < i; s++) {
    st.site = &mf_emlrtRSI;
    sprdmpF114(&st, par->var, z, T, fg, b_y, in);
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_vd_j[i0] += c_y[i0] * ds;
    }

    st.site = &of_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_sd[i0] += c_y[i0] * ds;
    }

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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_in[i0] += c_y[i0] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  s0 = 1.0E-6;
  ds = par->rom.sprdmp[114] / par->n_int;
  if (par->rom.sprdmp[114] == 0.0) {
    ds = 1.0;
    s0 = 0.0;
  }

  alpha1 = par->rom.sprdmp[114] - s0;
  i = (int32_T)((alpha1 + (ds - s0)) / ds);
  emlrtForLoopVectorCheckR2012b(s0, ds, alpha1, mxDOUBLE_CLASS, i, &d_emlrtRTEI,
    sp);
  for (s = 0; s < i; s++) {
    st.site = &qf_emlrtRSI;
    sprdmpF115(&st, z, T, fg, b_y, in);
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &b_y[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_vd_j[i0] += c_y[i0] * ds;
    }

    st.site = &sf_emlrtRSI;
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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &fg[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_sd[i0] += c_y[i0] * ds;
    }

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
    emlrt_checkEscapedGlobals();
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &T[0], &lda_t, &in[0],
          &ldb_t, &s0, &c_y[0], &ldc_t);
    for (i0 = 0; i0 < 91; i0++) {
      w_in[i0] += c_y[i0] * ds;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  st.site = &uf_emlrtRSI;
  cnstF1(z, reshapes_f2, c_y, &s0);
  st.site = &vf_emlrtRSI;
  for (i = 0; i < 91; i++) {
    c_y[i] = -c_y[i];
  }

  b_st.site = &yg_emlrtRSI;
  if (91 != loop_ub) {
    if (loop_ub == 1) {
      emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
        "Coder:toolbox:mtimes_noDynamicScalarExpansion",
        "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI, "MATLAB:innerdim",
        "MATLAB:innerdim", 0);
    }
  }

  alpha1 = 0.0;
  for (i = 0; i < 91; i++) {
    alpha1 += c_y[i] * u_data[i];
  }

  st.site = &wf_emlrtRSI;
  cnstF2(z, tc, c_y, &s0);
  st.site = &xf_emlrtRSI;
  for (i = 0; i < 91; i++) {
    c_y[i] = -c_y[i];
  }

  ds = 0.0;
  for (i = 0; i < 91; i++) {
    ds += c_y[i] * u_data[i];
  }

  st.site = &yf_emlrtRSI;
  cnstF3(z, b_tc, c_y, &s0);
  st.site = &ag_emlrtRSI;
  for (i = 0; i < 91; i++) {
    c_y[i] = -c_y[i];
  }

  d_y = 0.0;
  for (i = 0; i < 91; i++) {
    d_y += c_y[i] * u_data[i];
  }

  cnstF4(z, c_tc, c_y, &s0);
  st.site = &bg_emlrtRSI;
  for (i = 0; i < 91; i++) {
    c_y[i] = -c_y[i];
  }

  e_y = 0.0;
  for (i = 0; i < 91; i++) {
    e_y += c_y[i] * u_data[i];
  }

  st.site = &cg_emlrtRSI;
  cnstF5(&st, z, d_tc, c_y, &s0);
  st.site = &dg_emlrtRSI;
  for (i = 0; i < 91; i++) {
    c_y[i] = -c_y[i];
  }

  f_y = 0.0;
  for (i = 0; i < 91; i++) {
    f_y += c_y[i] * u_data[i];
  }

  cnstF6(z, e_tc, c_y, &s0);
  st.site = &eg_emlrtRSI;
  for (i = 0; i < 91; i++) {
    c_y[i] = -c_y[i];
  }

  g_y = 0.0;
  for (i = 0; i < 91; i++) {
    g_y += c_y[i] * u_data[i];
  }

  st.site = &fg_emlrtRSI;
  cnstF7(z, f_tc, c_y, &s0);
  st.site = &gg_emlrtRSI;
  for (i = 0; i < 91; i++) {
    c_y[i] = -c_y[i];
  }

  h_y = 0.0;
  for (i = 0; i < 91; i++) {
    h_y += c_y[i] * u_data[i];
  }

  st.site = &hg_emlrtRSI;
  cnstF8(z, g_tc, c_y, &s0);
  st.site = &ig_emlrtRSI;
  for (i = 0; i < 91; i++) {
    c_y[i] = -c_y[i];
  }

  i_y = 0.0;
  for (i = 0; i < 91; i++) {
    i_y += c_y[i] * u_data[i];
  }

  st.site = &jg_emlrtRSI;
  cnstF9(z, h_tc, c_y, &s0);
  st.site = &kg_emlrtRSI;
  for (i = 0; i < 91; i++) {
    c_y[i] = -c_y[i];
  }

  j_y = 0.0;
  for (i = 0; i < 91; i++) {
    j_y += c_y[i] * u_data[i];
  }

  cnstF10(z, i_tc, c_y, &s0);
  st.site = &lg_emlrtRSI;
  for (i = 0; i < 91; i++) {
    c_y[i] = -c_y[i];
  }

  k_y = 0.0;
  for (i = 0; i < 91; i++) {
    k_y += c_y[i] * u_data[i];
  }

  st.site = &mg_emlrtRSI;
  cnstF11(&st, z, j_tc, c_y, &s0);
  st.site = &ng_emlrtRSI;
  for (i = 0; i < 91; i++) {
    c_y[i] = -c_y[i];
  }

  l_y = 0.0;
  for (i = 0; i < 91; i++) {
    l_y += c_y[i] * u_data[i];
  }

  cnstF12(z, k_tc, c_y, &s0);
  for (i = 0; i < 91; i++) {
    Tc[12 * i] = reshapes_f2[i];
    Tc[1 + 12 * i] = tc[i];
    Tc[2 + 12 * i] = b_tc[i];
    Tc[3 + 12 * i] = c_tc[i];
    Tc[4 + 12 * i] = d_tc[i];
    Tc[5 + 12 * i] = e_tc[i];
    Tc[6 + 12 * i] = f_tc[i];
    Tc[7 + 12 * i] = g_tc[i];
    Tc[8 + 12 * i] = h_tc[i];
    Tc[9 + 12 * i] = i_tc[i];
    Tc[10 + 12 * i] = j_tc[i];
    Tc[11 + 12 * i] = k_tc[i];
  }

  st.site = &og_emlrtRSI;
  for (i = 0; i < 91; i++) {
    c_y[i] = -c_y[i];
  }

  s0 = 0.0;
  for (i = 0; i < 91; i++) {
    s0 += c_y[i] * u_data[i];
  }

  /*  EOM */
  fj_vdF(par->var, z, c_y);
  dzt[91] = alpha1;
  dzt[92] = ds;
  dzt[93] = d_y;
  dzt[94] = e_y;
  dzt[95] = f_y;
  dzt[96] = g_y;
  dzt[97] = h_y;
  dzt[98] = i_y;
  dzt[99] = j_y;
  dzt[100] = k_y;
  dzt[101] = l_y;
  dzt[102] = s0;
  for (i = 0; i < 91; i++) {
    dzt[i] = (((TMfd[i] + c_y[i]) + w_sd[i]) + w_in[i]) + w_vd_j[i];
    memcpy(&SD->f1.TMT[i * 103], &b_TMT[i * 91], 91U * sizeof(real_T));
  }

  for (i = 0; i < 12; i++) {
    for (i0 = 0; i0 < 91; i0++) {
      SD->f1.TMT[i0 + 103 * (i + 91)] = Tc[i + 12 * i0];
    }
  }

  for (i = 0; i < 91; i++) {
    memcpy(&SD->f1.TMT[i * 103 + 91], &Tc[i * 12], 12U * sizeof(real_T));
  }

  for (i = 0; i < 12; i++) {
    memset(&SD->f1.TMT[i * 103 + 9464], 0, 12U * sizeof(real_T));
  }

  st.site = &pg_emlrtRSI;
  mldivide(SD, &st, SD->f1.TMT, dzt);
  dz_size[0] = u_size_idx_0_tmp + 103;
  if (0 <= u_size_idx_0_tmp - 1) {
    memcpy(&dz_data[0], &u_data[0], (uint32_T)(u_size_idx_0_tmp * (int32_T)
            sizeof(real_T)));
  }

  memcpy(&dz_data[u_size_idx_0_tmp], &dzt[0], 103U * sizeof(real_T));
}

/* End of code generation (EOM.c) */
