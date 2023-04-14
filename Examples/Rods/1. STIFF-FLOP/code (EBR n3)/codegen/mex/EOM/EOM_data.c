/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EOM_data.c
 *
 * Code generation for function 'EOM_data'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "EOM.h"
#include "EOM_data.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
real_T t_report;
uint32_T t_report_dirty;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131467U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "EOM",                               /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

emlrtRSInfo t_emlrtRSI = { 37,         /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo u_emlrtRSI = { 38,         /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo v_emlrtRSI = { 41,         /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo w_emlrtRSI = { 43,         /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo x_emlrtRSI = { 44,         /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo y_emlrtRSI = { 45,         /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo ab_emlrtRSI = { 50,        /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo bb_emlrtRSI = { 51,        /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo cb_emlrtRSI = { 52,        /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo db_emlrtRSI = { 55,        /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo eb_emlrtRSI = { 56,        /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo fb_emlrtRSI = { 57,        /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo gb_emlrtRSI = { 61,        /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo hb_emlrtRSI = { 49,        /* lineNo */
  "power",                             /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

emlrtRSInfo pb_emlrtRSI = { 23,        /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

emlrtRSInfo qb_emlrtRSI = { 25,        /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

emlrtRSInfo rb_emlrtRSI = { 26,        /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

emlrtRSInfo sb_emlrtRSI = { 33,        /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

emlrtRSInfo tb_emlrtRSI = { 34,        /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

emlrtRSInfo ub_emlrtRSI = { 52,        /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pathName */
};

emlrtRSInfo vb_emlrtRSI = { 114,       /* lineNo */
  "mtimes",                            /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+blas/mtimes.m"/* pathName */
};

emlrtRSInfo wb_emlrtRSI = { 118,       /* lineNo */
  "mtimes",                            /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+blas/mtimes.m"/* pathName */
};

emlrtRSInfo yb_emlrtRSI = { 35,        /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

emlrtRSInfo ac_emlrtRSI = { 37,        /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

emlrtRSInfo bc_emlrtRSI = { 38,        /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

emlrtRSInfo cc_emlrtRSI = { 45,        /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

emlrtRSInfo dc_emlrtRSI = { 46,        /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

emlrtRSInfo ec_emlrtRSI = { 64,        /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

emlrtRSInfo fc_emlrtRSI = { 66,        /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

emlrtRSInfo gc_emlrtRSI = { 67,        /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

emlrtRSInfo hc_emlrtRSI = { 140,       /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

emlrtRSInfo ic_emlrtRSI = { 142,       /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

emlrtRSInfo jc_emlrtRSI = { 143,       /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

emlrtRSInfo kc_emlrtRSI = { 47,        /* lineNo */
  "massF3",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF3.m"/* pathName */
};

emlrtRSInfo lc_emlrtRSI = { 49,        /* lineNo */
  "massF3",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF3.m"/* pathName */
};

emlrtRSInfo mc_emlrtRSI = { 50,        /* lineNo */
  "massF3",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF3.m"/* pathName */
};

emlrtRSInfo nc_emlrtRSI = { 57,        /* lineNo */
  "massF3",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF3.m"/* pathName */
};

emlrtRSInfo oc_emlrtRSI = { 58,        /* lineNo */
  "massF3",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF3.m"/* pathName */
};

emlrtRSInfo pc_emlrtRSI = { 154,       /* lineNo */
  "massF3",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF3.m"/* pathName */
};

emlrtRSInfo qc_emlrtRSI = { 156,       /* lineNo */
  "massF3",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF3.m"/* pathName */
};

emlrtRSInfo rc_emlrtRSI = { 157,       /* lineNo */
  "massF3",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF3.m"/* pathName */
};

emlrtRSInfo sc_emlrtRSI = { 176,       /* lineNo */
  "massF3",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF3.m"/* pathName */
};

emlrtRSInfo tc_emlrtRSI = { 177,       /* lineNo */
  "massF3",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF3.m"/* pathName */
};

emlrtRSInfo uc_emlrtRSI = { 178,       /* lineNo */
  "massF3",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF3.m"/* pathName */
};

emlrtRSInfo vc_emlrtRSI = { 179,       /* lineNo */
  "massF3",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF3.m"/* pathName */
};

emlrtRSInfo wc_emlrtRSI = { 572,       /* lineNo */
  "massF3",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF3.m"/* pathName */
};

emlrtRSInfo xc_emlrtRSI = { 574,       /* lineNo */
  "massF3",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF3.m"/* pathName */
};

emlrtRSInfo yc_emlrtRSI = { 576,       /* lineNo */
  "massF3",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF3.m"/* pathName */
};

emlrtRSInfo ad_emlrtRSI = { 577,       /* lineNo */
  "massF3",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF3.m"/* pathName */
};

emlrtRSInfo bd_emlrtRSI = { 648,       /* lineNo */
  "massF3",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF3.m"/* pathName */
};

emlrtRSInfo cd_emlrtRSI = { 650,       /* lineNo */
  "massF3",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF3.m"/* pathName */
};

emlrtRSInfo dd_emlrtRSI = { 652,       /* lineNo */
  "massF3",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF3.m"/* pathName */
};

emlrtRSInfo ed_emlrtRSI = { 654,       /* lineNo */
  "massF3",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF3.m"/* pathName */
};

emlrtRSInfo fd_emlrtRSI = { 45,        /* lineNo */
  "massF4",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF4.m"/* pathName */
};

emlrtRSInfo gd_emlrtRSI = { 46,        /* lineNo */
  "massF4",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF4.m"/* pathName */
};

emlrtRSInfo hd_emlrtRSI = { 210,       /* lineNo */
  "massF4",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF4.m"/* pathName */
};

emlrtRSInfo id_emlrtRSI = { 212,       /* lineNo */
  "massF4",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF4.m"/* pathName */
};

emlrtRSInfo jd_emlrtRSI = { 213,       /* lineNo */
  "massF4",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF4.m"/* pathName */
};

emlrtRSInfo kd_emlrtRSI = { 241,       /* lineNo */
  "massF4",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF4.m"/* pathName */
};

emlrtRSInfo ld_emlrtRSI = { 242,       /* lineNo */
  "massF4",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF4.m"/* pathName */
};

emlrtRSInfo md_emlrtRSI = { 243,       /* lineNo */
  "massF4",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF4.m"/* pathName */
};

emlrtRSInfo nd_emlrtRSI = { 244,       /* lineNo */
  "massF4",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF4.m"/* pathName */
};

emlrtRSInfo od_emlrtRSI = { 397,       /* lineNo */
  "massF4",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF4.m"/* pathName */
};

emlrtRSInfo pd_emlrtRSI = { 399,       /* lineNo */
  "massF4",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF4.m"/* pathName */
};

emlrtRSInfo qd_emlrtRSI = { 400,       /* lineNo */
  "massF4",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF4.m"/* pathName */
};

emlrtRSInfo rd_emlrtRSI = { 401,       /* lineNo */
  "massF4",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF4.m"/* pathName */
};

emlrtRSInfo sd_emlrtRSI = { 581,       /* lineNo */
  "massF4",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF4.m"/* pathName */
};

emlrtRSInfo td_emlrtRSI = { 583,       /* lineNo */
  "massF4",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF4.m"/* pathName */
};

emlrtRSInfo ud_emlrtRSI = { 585,       /* lineNo */
  "massF4",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF4.m"/* pathName */
};

emlrtRSInfo vd_emlrtRSI = { 586,       /* lineNo */
  "massF4",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF4.m"/* pathName */
};

emlrtRSInfo wd_emlrtRSI = { 1043,      /* lineNo */
  "massF4",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF4.m"/* pathName */
};

emlrtRSInfo xd_emlrtRSI = { 182,       /* lineNo */
  "loadsF1",                           /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/loadsF1.m"/* pathName */
};

emlrtRSInfo yd_emlrtRSI = { 184,       /* lineNo */
  "loadsF1",                           /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/loadsF1.m"/* pathName */
};

emlrtRSInfo ae_emlrtRSI = { 185,       /* lineNo */
  "loadsF1",                           /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/loadsF1.m"/* pathName */
};

emlrtRSInfo be_emlrtRSI = { 249,       /* lineNo */
  "loadsF1",                           /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/loadsF1.m"/* pathName */
};

emlrtRSInfo ce_emlrtRSI = { 250,       /* lineNo */
  "loadsF1",                           /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/loadsF1.m"/* pathName */
};

emlrtRSInfo de_emlrtRSI = { 251,       /* lineNo */
  "loadsF1",                           /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/loadsF1.m"/* pathName */
};

emlrtRSInfo ee_emlrtRSI = { 252,       /* lineNo */
  "loadsF1",                           /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/loadsF1.m"/* pathName */
};

emlrtRSInfo je_emlrtRSI = { 7,         /* lineNo */
  "int",                               /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+lapack/int.m"/* pathName */
};

emlrtRSInfo re_emlrtRSI = { 8,         /* lineNo */
  "majority",                          /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+lapack/majority.m"/* pathName */
};

emlrtRSInfo se_emlrtRSI = { 31,        /* lineNo */
  "infocheck",                         /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+lapack/infocheck.m"/* pathName */
};

/* End of code generation (EOM_data.c) */
