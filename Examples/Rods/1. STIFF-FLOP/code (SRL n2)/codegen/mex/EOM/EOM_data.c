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

emlrtRSInfo r_emlrtRSI = { 31,         /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo s_emlrtRSI = { 32,         /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo t_emlrtRSI = { 35,         /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo u_emlrtRSI = { 37,         /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo v_emlrtRSI = { 38,         /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo w_emlrtRSI = { 39,         /* lineNo */
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

emlrtRSInfo ab_emlrtRSI = { 46,        /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo bb_emlrtRSI = { 49,        /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo cb_emlrtRSI = { 50,        /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo db_emlrtRSI = { 51,        /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo eb_emlrtRSI = { 55,        /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo fb_emlrtRSI = { 49,        /* lineNo */
  "power",                             /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

emlrtRSInfo gb_emlrtRSI = { 28,        /* lineNo */
  "fj_vdF",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_vdF.m"/* pathName */
};

emlrtRSInfo ob_emlrtRSI = { 23,        /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

emlrtRSInfo pb_emlrtRSI = { 25,        /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

emlrtRSInfo qb_emlrtRSI = { 26,        /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

emlrtRSInfo rb_emlrtRSI = { 33,        /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

emlrtRSInfo sb_emlrtRSI = { 34,        /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

emlrtRSInfo tb_emlrtRSI = { 117,       /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

emlrtRSInfo ub_emlrtRSI = { 120,       /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

emlrtRSInfo vb_emlrtRSI = { 121,       /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

emlrtRSInfo wb_emlrtRSI = { 145,       /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

emlrtRSInfo xb_emlrtRSI = { 52,        /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pathName */
};

emlrtRSInfo yb_emlrtRSI = { 114,       /* lineNo */
  "mtimes",                            /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+blas/mtimes.m"/* pathName */
};

emlrtRSInfo ac_emlrtRSI = { 118,       /* lineNo */
  "mtimes",                            /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+blas/mtimes.m"/* pathName */
};

emlrtRSInfo cc_emlrtRSI = { 35,        /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

emlrtRSInfo dc_emlrtRSI = { 37,        /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

emlrtRSInfo ec_emlrtRSI = { 38,        /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

emlrtRSInfo fc_emlrtRSI = { 45,        /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

emlrtRSInfo gc_emlrtRSI = { 46,        /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

emlrtRSInfo hc_emlrtRSI = { 140,       /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

emlrtRSInfo ic_emlrtRSI = { 141,       /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

emlrtRSInfo jc_emlrtRSI = { 142,       /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

emlrtRSInfo kc_emlrtRSI = { 590,       /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

emlrtRSInfo lc_emlrtRSI = { 33,        /* lineNo */
  "massF3",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF3.m"/* pathName */
};

emlrtRSInfo mc_emlrtRSI = { 34,        /* lineNo */
  "massF3",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF3.m"/* pathName */
};

emlrtRSInfo nc_emlrtRSI = { 233,       /* lineNo */
  "massF3",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF3.m"/* pathName */
};

emlrtRSInfo oc_emlrtRSI = { 234,       /* lineNo */
  "massF3",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF3.m"/* pathName */
};

emlrtRSInfo pc_emlrtRSI = { 235,       /* lineNo */
  "massF3",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF3.m"/* pathName */
};

emlrtRSInfo qc_emlrtRSI = { 319,       /* lineNo */
  "massF3",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF3.m"/* pathName */
};

emlrtRSInfo rc_emlrtRSI = { 1225,      /* lineNo */
  "massF3",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF3.m"/* pathName */
};

emlrtRSInfo sc_emlrtRSI = { 207,       /* lineNo */
  "loadsF1",                           /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/loadsF1.m"/* pathName */
};

emlrtRSInfo tc_emlrtRSI = { 208,       /* lineNo */
  "loadsF1",                           /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/loadsF1.m"/* pathName */
};

emlrtRSInfo uc_emlrtRSI = { 209,       /* lineNo */
  "loadsF1",                           /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/loadsF1.m"/* pathName */
};

emlrtRSInfo vc_emlrtRSI = { 277,       /* lineNo */
  "loadsF1",                           /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/loadsF1.m"/* pathName */
};

emlrtRSInfo bd_emlrtRSI = { 7,         /* lineNo */
  "int",                               /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+lapack/int.m"/* pathName */
};

emlrtRSInfo jd_emlrtRSI = { 8,         /* lineNo */
  "majority",                          /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+lapack/majority.m"/* pathName */
};

emlrtRSInfo kd_emlrtRSI = { 31,        /* lineNo */
  "infocheck",                         /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+lapack/infocheck.m"/* pathName */
};

/* End of code generation (EOM_data.c) */
