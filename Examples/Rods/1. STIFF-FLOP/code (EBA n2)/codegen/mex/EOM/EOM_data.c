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

emlrtRSInfo cb_emlrtRSI = { 49,        /* lineNo */
  "power",                             /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

emlrtRSInfo db_emlrtRSI = { 12,        /* lineNo */
  "sqrt",                              /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/elfun/sqrt.m"/* pathName */
};

emlrtRSInfo eb_emlrtRSI = { 52,        /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pathName */
};

emlrtRSInfo fb_emlrtRSI = { 114,       /* lineNo */
  "mtimes",                            /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+blas/mtimes.m"/* pathName */
};

emlrtRSInfo gb_emlrtRSI = { 118,       /* lineNo */
  "mtimes",                            /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+blas/mtimes.m"/* pathName */
};

emlrtRSInfo ad_emlrtRSI = { 53,        /* lineNo */
  "sprdmpF14",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF14.m"/* pathName */
};

emlrtRSInfo bd_emlrtRSI = { 54,        /* lineNo */
  "sprdmpF14",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF14.m"/* pathName */
};

emlrtRSInfo cd_emlrtRSI = { 55,        /* lineNo */
  "sprdmpF14",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF14.m"/* pathName */
};

emlrtRSInfo fd_emlrtRSI = { 89,        /* lineNo */
  "sprdmpF14",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF14.m"/* pathName */
};

emlrtRSInfo gd_emlrtRSI = { 90,        /* lineNo */
  "sprdmpF14",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF14.m"/* pathName */
};

emlrtRSInfo hd_emlrtRSI = { 91,        /* lineNo */
  "sprdmpF14",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF14.m"/* pathName */
};

emlrtRSInfo kd_emlrtRSI = { 111,       /* lineNo */
  "sprdmpF14",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF14.m"/* pathName */
};

emlrtRSInfo ld_emlrtRSI = { 112,       /* lineNo */
  "sprdmpF14",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF14.m"/* pathName */
};

emlrtRSInfo md_emlrtRSI = { 115,       /* lineNo */
  "sprdmpF14",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF14.m"/* pathName */
};

emlrtRSInfo nd_emlrtRSI = { 117,       /* lineNo */
  "sprdmpF14",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF14.m"/* pathName */
};

emlrtRSInfo od_emlrtRSI = { 118,       /* lineNo */
  "sprdmpF14",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF14.m"/* pathName */
};

emlrtRSInfo pd_emlrtRSI = { 119,       /* lineNo */
  "sprdmpF14",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF14.m"/* pathName */
};

emlrtRSInfo qd_emlrtRSI = { 128,       /* lineNo */
  "sprdmpF14",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF14.m"/* pathName */
};

emlrtRSInfo rd_emlrtRSI = { 129,       /* lineNo */
  "sprdmpF14",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF14.m"/* pathName */
};

emlrtRSInfo sd_emlrtRSI = { 130,       /* lineNo */
  "sprdmpF14",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF14.m"/* pathName */
};

emlrtRSInfo td_emlrtRSI = { 133,       /* lineNo */
  "sprdmpF14",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF14.m"/* pathName */
};

emlrtRSInfo ud_emlrtRSI = { 134,       /* lineNo */
  "sprdmpF14",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF14.m"/* pathName */
};

emlrtRSInfo vd_emlrtRSI = { 135,       /* lineNo */
  "sprdmpF14",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF14.m"/* pathName */
};

emlrtRSInfo wd_emlrtRSI = { 139,       /* lineNo */
  "sprdmpF14",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF14.m"/* pathName */
};

emlrtRSInfo xd_emlrtRSI = { 172,       /* lineNo */
  "sprdmpF14",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF14.m"/* pathName */
};

emlrtRSInfo yd_emlrtRSI = { 203,       /* lineNo */
  "sprdmpF14",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF14.m"/* pathName */
};

emlrtRSInfo ae_emlrtRSI = { 234,       /* lineNo */
  "sprdmpF14",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF14.m"/* pathName */
};

emlrtRSInfo be_emlrtRSI = { 261,       /* lineNo */
  "sprdmpF14",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF14.m"/* pathName */
};

emlrtRSInfo ce_emlrtRSI = { 285,       /* lineNo */
  "sprdmpF14",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF14.m"/* pathName */
};

emlrtRSInfo de_emlrtRSI = { 309,       /* lineNo */
  "sprdmpF14",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF14.m"/* pathName */
};

emlrtRSInfo ge_emlrtRSI = { 312,       /* lineNo */
  "sprdmpF14",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF14.m"/* pathName */
};

emlrtRSInfo re_emlrtRSI = { 7,         /* lineNo */
  "int",                               /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+lapack/int.m"/* pathName */
};

emlrtRSInfo af_emlrtRSI = { 8,         /* lineNo */
  "majority",                          /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+lapack/majority.m"/* pathName */
};

emlrtRSInfo bf_emlrtRSI = { 31,        /* lineNo */
  "infocheck",                         /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+lapack/infocheck.m"/* pathName */
};

/* End of code generation (EOM_data.c) */
