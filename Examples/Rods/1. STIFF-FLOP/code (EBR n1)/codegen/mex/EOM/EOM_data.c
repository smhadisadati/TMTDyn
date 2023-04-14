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

emlrtRSInfo k_emlrtRSI = { 25,         /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo l_emlrtRSI = { 26,         /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo m_emlrtRSI = { 29,         /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo n_emlrtRSI = { 31,         /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo o_emlrtRSI = { 32,         /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo p_emlrtRSI = { 33,         /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo q_emlrtRSI = { 38,         /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo r_emlrtRSI = { 39,         /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo s_emlrtRSI = { 40,         /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo t_emlrtRSI = { 43,         /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo u_emlrtRSI = { 44,         /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo v_emlrtRSI = { 45,         /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo w_emlrtRSI = { 49,         /* lineNo */
  "fj_kF",                             /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"/* pathName */
};

emlrtRSInfo x_emlrtRSI = { 49,         /* lineNo */
  "power",                             /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

emlrtRSInfo gb_emlrtRSI = { 23,        /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

emlrtRSInfo hb_emlrtRSI = { 25,        /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

emlrtRSInfo ib_emlrtRSI = { 26,        /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

emlrtRSInfo jb_emlrtRSI = { 33,        /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

emlrtRSInfo kb_emlrtRSI = { 34,        /* lineNo */
  "massF1",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"/* pathName */
};

emlrtRSInfo mb_emlrtRSI = { 20,        /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

emlrtRSInfo nb_emlrtRSI = { 21,        /* lineNo */
  "massF2",                            /* fcnName */
  "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"/* pathName */
};

/* End of code generation (EOM_data.c) */
