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

emlrtRSInfo q_emlrtRSI = { 31,         /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo r_emlrtRSI = { 32,         /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo s_emlrtRSI = { 35,         /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo t_emlrtRSI = { 37,         /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo u_emlrtRSI = { 38,         /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo v_emlrtRSI = { 39,         /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo w_emlrtRSI = { 44,         /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo x_emlrtRSI = { 45,         /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo y_emlrtRSI = { 46,         /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo ab_emlrtRSI = { 49,        /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo bb_emlrtRSI = { 50,        /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo cb_emlrtRSI = { 51,        /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo db_emlrtRSI = { 55,        /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo eb_emlrtRSI = { 49,        /* lineNo */
  "power",                             /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

emlrtRSInfo mb_emlrtRSI = { 23,        /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

emlrtRSInfo nb_emlrtRSI = { 25,        /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

emlrtRSInfo ob_emlrtRSI = { 26,        /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

emlrtRSInfo pb_emlrtRSI = { 33,        /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

emlrtRSInfo qb_emlrtRSI = { 34,        /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

emlrtRSInfo rb_emlrtRSI = { 52,        /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pathName */
};

emlrtRSInfo sb_emlrtRSI = { 114,       /* lineNo */
  "mtimes",                            /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+blas/mtimes.m"/* pathName */
};

emlrtRSInfo tb_emlrtRSI = { 118,       /* lineNo */
  "mtimes",                            /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+blas/mtimes.m"/* pathName */
};

emlrtRSInfo vb_emlrtRSI = { 35,        /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

emlrtRSInfo wb_emlrtRSI = { 37,        /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

emlrtRSInfo xb_emlrtRSI = { 38,        /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

emlrtRSInfo yb_emlrtRSI = { 45,        /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

emlrtRSInfo ac_emlrtRSI = { 46,        /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

emlrtRSInfo bc_emlrtRSI = { 64,        /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

emlrtRSInfo cc_emlrtRSI = { 66,        /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

emlrtRSInfo dc_emlrtRSI = { 67,        /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

emlrtRSInfo ec_emlrtRSI = { 140,       /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

emlrtRSInfo fc_emlrtRSI = { 142,       /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

emlrtRSInfo gc_emlrtRSI = { 143,       /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

emlrtRSInfo hc_emlrtRSI = { 33,        /* lineNo */
  "massF3",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF3.m"/* pathName */
};

emlrtRSInfo ic_emlrtRSI = { 34,        /* lineNo */
  "massF3",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF3.m"/* pathName */
};

emlrtRSInfo jc_emlrtRSI = { 79,        /* lineNo */
  "massF3",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF3.m"/* pathName */
};

emlrtRSInfo kc_emlrtRSI = { 81,        /* lineNo */
  "massF3",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF3.m"/* pathName */
};

emlrtRSInfo lc_emlrtRSI = { 82,        /* lineNo */
  "massF3",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF3.m"/* pathName */
};

emlrtRSInfo mc_emlrtRSI = { 141,       /* lineNo */
  "massF3",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF3.m"/* pathName */
};

emlrtRSInfo nc_emlrtRSI = { 142,       /* lineNo */
  "massF3",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF3.m"/* pathName */
};

emlrtRSInfo oc_emlrtRSI = { 143,       /* lineNo */
  "massF3",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF3.m"/* pathName */
};

emlrtRSInfo pc_emlrtRSI = { 79,        /* lineNo */
  "loadsF1",                           /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/loadsF1.m"/* pathName */
};

emlrtRSInfo qc_emlrtRSI = { 81,        /* lineNo */
  "loadsF1",                           /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/loadsF1.m"/* pathName */
};

emlrtRSInfo rc_emlrtRSI = { 82,        /* lineNo */
  "loadsF1",                           /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/loadsF1.m"/* pathName */
};

emlrtRSInfo wc_emlrtRSI = { 7,         /* lineNo */
  "int",                               /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+lapack/int.m"/* pathName */
};

emlrtRSInfo fd_emlrtRSI = { 8,         /* lineNo */
  "majority",                          /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+lapack/majority.m"/* pathName */
};

emlrtRSInfo gd_emlrtRSI = { 31,        /* lineNo */
  "infocheck",                         /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+lapack/infocheck.m"/* pathName */
};

/* End of code generation (EOM_data.c) */
