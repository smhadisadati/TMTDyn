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

emlrtRSInfo gb_emlrtRSI = { 49,        /* lineNo */
  "power",                             /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

emlrtRSInfo hb_emlrtRSI = { 12,        /* lineNo */
  "sqrt",                              /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/elfun/sqrt.m"/* pathName */
};

emlrtRSInfo ib_emlrtRSI = { 52,        /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pathName */
};

emlrtRSInfo jb_emlrtRSI = { 114,       /* lineNo */
  "mtimes",                            /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+blas/mtimes.m"/* pathName */
};

emlrtRSInfo kb_emlrtRSI = { 118,       /* lineNo */
  "mtimes",                            /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+blas/mtimes.m"/* pathName */
};

emlrtRSInfo pd_emlrtRSI = { 53,        /* lineNo */
  "sprdmpF20",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF20.m"/* pathName */
};

emlrtRSInfo qd_emlrtRSI = { 54,        /* lineNo */
  "sprdmpF20",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF20.m"/* pathName */
};

emlrtRSInfo rd_emlrtRSI = { 55,        /* lineNo */
  "sprdmpF20",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF20.m"/* pathName */
};

emlrtRSInfo ud_emlrtRSI = { 89,        /* lineNo */
  "sprdmpF20",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF20.m"/* pathName */
};

emlrtRSInfo vd_emlrtRSI = { 90,        /* lineNo */
  "sprdmpF20",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF20.m"/* pathName */
};

emlrtRSInfo wd_emlrtRSI = { 91,        /* lineNo */
  "sprdmpF20",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF20.m"/* pathName */
};

emlrtRSInfo ae_emlrtRSI = { 111,       /* lineNo */
  "sprdmpF20",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF20.m"/* pathName */
};

emlrtRSInfo be_emlrtRSI = { 112,       /* lineNo */
  "sprdmpF20",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF20.m"/* pathName */
};

emlrtRSInfo ce_emlrtRSI = { 115,       /* lineNo */
  "sprdmpF20",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF20.m"/* pathName */
};

emlrtRSInfo de_emlrtRSI = { 117,       /* lineNo */
  "sprdmpF20",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF20.m"/* pathName */
};

emlrtRSInfo ee_emlrtRSI = { 118,       /* lineNo */
  "sprdmpF20",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF20.m"/* pathName */
};

emlrtRSInfo fe_emlrtRSI = { 119,       /* lineNo */
  "sprdmpF20",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF20.m"/* pathName */
};

emlrtRSInfo ge_emlrtRSI = { 128,       /* lineNo */
  "sprdmpF20",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF20.m"/* pathName */
};

emlrtRSInfo he_emlrtRSI = { 129,       /* lineNo */
  "sprdmpF20",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF20.m"/* pathName */
};

emlrtRSInfo ie_emlrtRSI = { 130,       /* lineNo */
  "sprdmpF20",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF20.m"/* pathName */
};

emlrtRSInfo je_emlrtRSI = { 133,       /* lineNo */
  "sprdmpF20",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF20.m"/* pathName */
};

emlrtRSInfo ke_emlrtRSI = { 134,       /* lineNo */
  "sprdmpF20",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF20.m"/* pathName */
};

emlrtRSInfo le_emlrtRSI = { 135,       /* lineNo */
  "sprdmpF20",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF20.m"/* pathName */
};

emlrtRSInfo me_emlrtRSI = { 139,       /* lineNo */
  "sprdmpF20",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF20.m"/* pathName */
};

emlrtRSInfo ne_emlrtRSI = { 172,       /* lineNo */
  "sprdmpF20",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF20.m"/* pathName */
};

emlrtRSInfo oe_emlrtRSI = { 203,       /* lineNo */
  "sprdmpF20",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF20.m"/* pathName */
};

emlrtRSInfo pe_emlrtRSI = { 234,       /* lineNo */
  "sprdmpF20",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF20.m"/* pathName */
};

emlrtRSInfo qe_emlrtRSI = { 261,       /* lineNo */
  "sprdmpF20",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF20.m"/* pathName */
};

emlrtRSInfo re_emlrtRSI = { 285,       /* lineNo */
  "sprdmpF20",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF20.m"/* pathName */
};

emlrtRSInfo se_emlrtRSI = { 309,       /* lineNo */
  "sprdmpF20",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF20.m"/* pathName */
};

emlrtRSInfo ve_emlrtRSI = { 312,       /* lineNo */
  "sprdmpF20",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF20.m"/* pathName */
};

emlrtRSInfo xe_emlrtRSI = { 53,        /* lineNo */
  "sprdmpF21",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF21.m"/* pathName */
};

emlrtRSInfo ye_emlrtRSI = { 54,        /* lineNo */
  "sprdmpF21",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF21.m"/* pathName */
};

emlrtRSInfo af_emlrtRSI = { 55,        /* lineNo */
  "sprdmpF21",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF21.m"/* pathName */
};

emlrtRSInfo df_emlrtRSI = { 89,        /* lineNo */
  "sprdmpF21",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF21.m"/* pathName */
};

emlrtRSInfo ef_emlrtRSI = { 90,        /* lineNo */
  "sprdmpF21",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF21.m"/* pathName */
};

emlrtRSInfo ff_emlrtRSI = { 91,        /* lineNo */
  "sprdmpF21",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF21.m"/* pathName */
};

emlrtRSInfo if_emlrtRSI = { 111,       /* lineNo */
  "sprdmpF21",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF21.m"/* pathName */
};

emlrtRSInfo jf_emlrtRSI = { 112,       /* lineNo */
  "sprdmpF21",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF21.m"/* pathName */
};

emlrtRSInfo kf_emlrtRSI = { 115,       /* lineNo */
  "sprdmpF21",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF21.m"/* pathName */
};

emlrtRSInfo lf_emlrtRSI = { 117,       /* lineNo */
  "sprdmpF21",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF21.m"/* pathName */
};

emlrtRSInfo mf_emlrtRSI = { 118,       /* lineNo */
  "sprdmpF21",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF21.m"/* pathName */
};

emlrtRSInfo nf_emlrtRSI = { 119,       /* lineNo */
  "sprdmpF21",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF21.m"/* pathName */
};

emlrtRSInfo of_emlrtRSI = { 128,       /* lineNo */
  "sprdmpF21",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF21.m"/* pathName */
};

emlrtRSInfo pf_emlrtRSI = { 129,       /* lineNo */
  "sprdmpF21",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF21.m"/* pathName */
};

emlrtRSInfo qf_emlrtRSI = { 130,       /* lineNo */
  "sprdmpF21",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF21.m"/* pathName */
};

emlrtRSInfo rf_emlrtRSI = { 133,       /* lineNo */
  "sprdmpF21",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF21.m"/* pathName */
};

emlrtRSInfo sf_emlrtRSI = { 134,       /* lineNo */
  "sprdmpF21",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF21.m"/* pathName */
};

emlrtRSInfo tf_emlrtRSI = { 135,       /* lineNo */
  "sprdmpF21",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF21.m"/* pathName */
};

emlrtRSInfo uf_emlrtRSI = { 139,       /* lineNo */
  "sprdmpF21",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF21.m"/* pathName */
};

emlrtRSInfo vf_emlrtRSI = { 172,       /* lineNo */
  "sprdmpF21",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF21.m"/* pathName */
};

emlrtRSInfo wf_emlrtRSI = { 203,       /* lineNo */
  "sprdmpF21",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF21.m"/* pathName */
};

emlrtRSInfo xf_emlrtRSI = { 234,       /* lineNo */
  "sprdmpF21",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF21.m"/* pathName */
};

emlrtRSInfo yf_emlrtRSI = { 261,       /* lineNo */
  "sprdmpF21",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF21.m"/* pathName */
};

emlrtRSInfo ag_emlrtRSI = { 285,       /* lineNo */
  "sprdmpF21",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF21.m"/* pathName */
};

emlrtRSInfo bg_emlrtRSI = { 309,       /* lineNo */
  "sprdmpF21",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF21.m"/* pathName */
};

emlrtRSInfo eg_emlrtRSI = { 312,       /* lineNo */
  "sprdmpF21",                         /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF21.m"/* pathName */
};

emlrtRSInfo pg_emlrtRSI = { 7,         /* lineNo */
  "int",                               /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+lapack/int.m"/* pathName */
};

emlrtRSInfo xg_emlrtRSI = { 8,         /* lineNo */
  "majority",                          /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+lapack/majority.m"/* pathName */
};

emlrtRSInfo yg_emlrtRSI = { 31,        /* lineNo */
  "infocheck",                         /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/+lapack/infocheck.m"/* pathName */
};

/* End of code generation (EOM_data.c) */
