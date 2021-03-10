/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * rjtipF_data.c
 *
 * Code generation for function 'rjtipF_data'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "rjtipF.h"
#include "rjtipF_data.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131482U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "rjtipF",                            /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

emlrtRSInfo emlrtRSI = { 50,           /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

emlrtRSInfo b_emlrtRSI = { 51,         /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

emlrtRSInfo c_emlrtRSI = { 54,         /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

emlrtRSInfo d_emlrtRSI = { 55,         /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

emlrtRSInfo f_emlrtRSI = { 72,         /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

emlrtRSInfo g_emlrtRSI = { 73,         /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

emlrtRSInfo h_emlrtRSI = { 74,         /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

emlrtRSInfo i_emlrtRSI = { 75,         /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

emlrtRSInfo j_emlrtRSI = { 92,         /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

emlrtRSInfo k_emlrtRSI = { 93,         /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

emlrtRSInfo l_emlrtRSI = { 94,         /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

emlrtRSInfo m_emlrtRSI = { 95,         /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

emlrtRSInfo n_emlrtRSI = { 173,        /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

emlrtRSInfo o_emlrtRSI = { 174,        /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

emlrtRSInfo p_emlrtRSI = { 175,        /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

emlrtRSInfo q_emlrtRSI = { 176,        /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

emlrtRSInfo r_emlrtRSI = { 177,        /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

emlrtRSInfo s_emlrtRSI = { 178,        /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

emlrtRSInfo t_emlrtRSI = { 179,        /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

emlrtRSInfo u_emlrtRSI = { 180,        /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

emlrtRSInfo v_emlrtRSI = { 258,        /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

emlrtRSInfo w_emlrtRSI = { 259,        /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

emlrtRSInfo x_emlrtRSI = { 260,        /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

emlrtRSInfo y_emlrtRSI = { 261,        /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

emlrtRSInfo ab_emlrtRSI = { 262,       /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

emlrtRSInfo bb_emlrtRSI = { 263,       /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

emlrtRSInfo eb_emlrtRSI = { 332,       /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

emlrtRSInfo fb_emlrtRSI = { 333,       /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

emlrtRSInfo gb_emlrtRSI = { 334,       /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

emlrtRSInfo hb_emlrtRSI = { 335,       /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

emlrtRSInfo ib_emlrtRSI = { 336,       /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

emlrtRSInfo jb_emlrtRSI = { 337,       /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

emlrtRSInfo kb_emlrtRSI = { 342,       /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

emlrtRSInfo lb_emlrtRSI = { 343,       /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

emlrtRSInfo mb_emlrtRSI = { 344,       /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

emlrtRSInfo nb_emlrtRSI = { 345,       /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

emlrtRSInfo ob_emlrtRSI = { 346,       /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

emlrtRSInfo pb_emlrtRSI = { 347,       /* lineNo */
  "rjtipF",                            /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"/* pathName */
};

emlrtRSInfo bc_emlrtRSI = { 55,        /* lineNo */
  "power",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

/* End of code generation (rjtipF_data.c) */
