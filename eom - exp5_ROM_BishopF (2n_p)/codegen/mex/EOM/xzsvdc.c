/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xzsvdc.c
 *
 * Code generation for function 'xzsvdc'
 *
 */

/* Include files */
#include "xzsvdc.h"
#include "EOM_data.h"
#include "rt_nonfinite.h"
#include "xaxpy.h"
#include "xdotc.h"
#include "xnrm2.h"
#include "xrot.h"
#include "xscal.h"
#include "xswap.h"
#include "blas.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo oe_emlrtRSI = { 428,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo pe_emlrtRSI = { 407,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo qe_emlrtRSI = { 394,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo re_emlrtRSI = { 391,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo se_emlrtRSI = { 380,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo te_emlrtRSI = { 353,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo ue_emlrtRSI = { 351,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo ve_emlrtRSI = { 334,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo we_emlrtRSI = { 251,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo xe_emlrtRSI = { 240,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo ye_emlrtRSI = { 215,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo af_emlrtRSI = { 194,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo bf_emlrtRSI = { 184,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo cf_emlrtRSI = { 120,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo df_emlrtRSI = { 114,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo ef_emlrtRSI = { 94, /* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo ff_emlrtRSI = { 82, /* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo gf_emlrtRSI = { 77, /* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo jf_emlrtRSI = { 21, /* lineNo */
  "scaleVectorByRecip",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\scaleVectorByRecip.m"/* pathName */
};

static emlrtRTEInfo c_emlrtRTEI = { 269,/* lineNo */
  13,                                  /* colNo */
  "xzsvdc",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pName */
};

/* Function Definitions */
void xzsvdc(const emlrtStack *sp, real_T A[25], real_T U[25], real_T S[5],
            real_T V[25])
{
  emlrtStack b_st;
  emlrtStack st;
  real_T Vf[25];
  real_T e[5];
  real_T s[5];
  real_T work[5];
  real_T b;
  real_T nrm;
  real_T rt;
  real_T scale;
  real_T sm;
  real_T sn;
  real_T snorm;
  real_T sqds;
  int32_T exitg2;
  int32_T i;
  int32_T k;
  int32_T m;
  int32_T q;
  int32_T qjj;
  int32_T qp1;
  boolean_T apply_transform;
  boolean_T exitg1;
  boolean_T exitg3;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  for (i = 0; i < 5; i++) {
    e[i] = 0.0;
    work[i] = 0.0;
  }

  memset(&U[0], 0, 25U * sizeof(real_T));
  memset(&Vf[0], 0, 25U * sizeof(real_T));
  apply_transform = false;
  st.site = &gf_emlrtRSI;
  nrm = xnrm2(&st, 5, A, 1);
  if (nrm > 0.0) {
    apply_transform = true;
    if (A[0] < 0.0) {
      sqds = -nrm;
      s[0] = -nrm;
    } else {
      sqds = nrm;
      s[0] = nrm;
    }

    st.site = &ff_emlrtRSI;
    if (muDoubleScalarAbs(sqds) >= 1.0020841800044864E-292) {
      b_st.site = &jf_emlrtRSI;
      xscal(&b_st, 5, 1.0 / sqds, A, 1);
    } else {
      for (k = 1; k < 6; k++) {
        A[k - 1] /= s[0];
      }
    }

    A[0]++;
    s[0] = -s[0];
  } else {
    s[0] = 0.0;
  }

  for (k = 2; k < 6; k++) {
    qjj = 5 * (k - 1);
    if (apply_transform) {
      st.site = &ef_emlrtRSI;
      nrm = xdotc(&st, 5, A, 1, A, qjj + 1);
      nrm = -(nrm / A[0]);
      xaxpy(5, nrm, 1, A, qjj + 1);
    }

    e[k - 1] = A[qjj];
  }

  for (k = 1; k < 6; k++) {
    U[k - 1] = A[k - 1];
  }

  st.site = &df_emlrtRSI;
  nrm = b_xnrm2(&st, 4, e, 2);
  if (nrm == 0.0) {
    e[0] = 0.0;
  } else {
    if (e[1] < 0.0) {
      e[0] = -nrm;
    } else {
      e[0] = nrm;
    }

    st.site = &cf_emlrtRSI;
    sm = e[0];
    if (muDoubleScalarAbs(e[0]) >= 1.0020841800044864E-292) {
      b_st.site = &jf_emlrtRSI;
      b_xscal(&b_st, 4, 1.0 / e[0], e, 2);
    } else {
      for (k = 2; k < 6; k++) {
        e[k - 1] /= sm;
      }
    }

    e[1]++;
    e[0] = -e[0];
    for (k = 2; k < 6; k++) {
      work[k - 1] = 0.0;
    }

    for (k = 2; k < 6; k++) {
      b_xaxpy(4, e[k - 1], A, 5 * (k - 1) + 2, work, 2);
    }

    for (k = 2; k < 6; k++) {
      c_xaxpy(4, -e[k - 1] / e[1], work, 2, A, 5 * (k - 1) + 2);
    }
  }

  for (k = 2; k < 6; k++) {
    Vf[k - 1] = e[k - 1];
  }

  apply_transform = false;
  st.site = &gf_emlrtRSI;
  nrm = xnrm2(&st, 4, A, 7);
  if (nrm > 0.0) {
    apply_transform = true;
    if (A[6] < 0.0) {
      sqds = -nrm;
      s[1] = -nrm;
    } else {
      sqds = nrm;
      s[1] = nrm;
    }

    st.site = &ff_emlrtRSI;
    if (muDoubleScalarAbs(sqds) >= 1.0020841800044864E-292) {
      b_st.site = &jf_emlrtRSI;
      xscal(&b_st, 4, 1.0 / sqds, A, 7);
    } else {
      for (k = 7; k < 11; k++) {
        A[k - 1] /= s[1];
      }
    }

    A[6]++;
    s[1] = -s[1];
  } else {
    s[1] = 0.0;
  }

  for (k = 3; k < 6; k++) {
    qjj = 5 * (k - 1) + 1;
    if (apply_transform) {
      st.site = &ef_emlrtRSI;
      nrm = xdotc(&st, 4, A, 7, A, qjj + 1);
      nrm = -(nrm / A[6]);
      xaxpy(4, nrm, 7, A, qjj + 1);
    }

    e[k - 1] = A[qjj];
  }

  for (k = 2; k < 6; k++) {
    U[k + 4] = A[k + 4];
  }

  st.site = &df_emlrtRSI;
  nrm = b_xnrm2(&st, 3, e, 3);
  if (nrm == 0.0) {
    e[1] = 0.0;
  } else {
    if (e[2] < 0.0) {
      e[1] = -nrm;
    } else {
      e[1] = nrm;
    }

    st.site = &cf_emlrtRSI;
    sm = e[1];
    if (muDoubleScalarAbs(e[1]) >= 1.0020841800044864E-292) {
      b_st.site = &jf_emlrtRSI;
      b_xscal(&b_st, 3, 1.0 / e[1], e, 3);
    } else {
      for (k = 3; k < 6; k++) {
        e[k - 1] /= sm;
      }
    }

    e[2]++;
    e[1] = -e[1];
    for (k = 3; k < 6; k++) {
      work[k - 1] = 0.0;
    }

    for (k = 3; k < 6; k++) {
      b_xaxpy(3, e[k - 1], A, 5 * (k - 1) + 3, work, 3);
    }

    for (k = 3; k < 6; k++) {
      c_xaxpy(3, -e[k - 1] / e[2], work, 3, A, 5 * (k - 1) + 3);
    }
  }

  for (k = 3; k < 6; k++) {
    Vf[k + 4] = e[k - 1];
  }

  apply_transform = false;
  st.site = &gf_emlrtRSI;
  nrm = xnrm2(&st, 3, A, 13);
  if (nrm > 0.0) {
    apply_transform = true;
    if (A[12] < 0.0) {
      sqds = -nrm;
      s[2] = -nrm;
    } else {
      sqds = nrm;
      s[2] = nrm;
    }

    st.site = &ff_emlrtRSI;
    if (muDoubleScalarAbs(sqds) >= 1.0020841800044864E-292) {
      b_st.site = &jf_emlrtRSI;
      xscal(&b_st, 3, 1.0 / sqds, A, 13);
    } else {
      for (k = 13; k < 16; k++) {
        A[k - 1] /= s[2];
      }
    }

    A[12]++;
    s[2] = -s[2];
  } else {
    s[2] = 0.0;
  }

  for (k = 4; k < 6; k++) {
    qjj = 5 * (k - 1) + 2;
    if (apply_transform) {
      st.site = &ef_emlrtRSI;
      nrm = xdotc(&st, 3, A, 13, A, qjj + 1);
      nrm = -(nrm / A[12]);
      xaxpy(3, nrm, 13, A, qjj + 1);
    }

    e[k - 1] = A[qjj];
  }

  for (k = 3; k < 6; k++) {
    U[k + 9] = A[k + 9];
  }

  st.site = &df_emlrtRSI;
  nrm = b_xnrm2(&st, 2, e, 4);
  if (nrm == 0.0) {
    e[2] = 0.0;
  } else {
    if (e[3] < 0.0) {
      e[2] = -nrm;
    } else {
      e[2] = nrm;
    }

    st.site = &cf_emlrtRSI;
    sm = e[2];
    if (muDoubleScalarAbs(e[2]) >= 1.0020841800044864E-292) {
      b_st.site = &jf_emlrtRSI;
      b_xscal(&b_st, 2, 1.0 / e[2], e, 4);
    } else {
      for (k = 4; k < 6; k++) {
        e[k - 1] /= sm;
      }
    }

    e[3]++;
    e[2] = -e[2];
    for (k = 4; k < 6; k++) {
      work[k - 1] = 0.0;
    }

    for (k = 4; k < 6; k++) {
      b_xaxpy(2, e[k - 1], A, 5 * (k - 1) + 4, work, 4);
    }

    for (k = 4; k < 6; k++) {
      c_xaxpy(2, -e[k - 1] / e[3], work, 4, A, 5 * (k - 1) + 4);
    }
  }

  for (k = 4; k < 6; k++) {
    Vf[k + 9] = e[k - 1];
  }

  apply_transform = false;
  st.site = &gf_emlrtRSI;
  nrm = xnrm2(&st, 2, A, 19);
  if (nrm > 0.0) {
    apply_transform = true;
    if (A[18] < 0.0) {
      sqds = -nrm;
      s[3] = -nrm;
    } else {
      sqds = nrm;
      s[3] = nrm;
    }

    st.site = &ff_emlrtRSI;
    if (muDoubleScalarAbs(sqds) >= 1.0020841800044864E-292) {
      b_st.site = &jf_emlrtRSI;
      xscal(&b_st, 2, 1.0 / sqds, A, 19);
    } else {
      for (k = 19; k < 21; k++) {
        A[k - 1] /= s[3];
      }
    }

    A[18]++;
    s[3] = -s[3];
  } else {
    s[3] = 0.0;
  }

  for (k = 5; k < 6; k++) {
    if (apply_transform) {
      st.site = &ef_emlrtRSI;
      nrm = xdotc(&st, 2, A, 19, A, 24);
      nrm = -(nrm / A[18]);
      xaxpy(2, nrm, 19, A, 24);
    }
  }

  for (k = 4; k < 6; k++) {
    U[k + 14] = A[k + 14];
  }

  m = 3;
  s[4] = A[24];
  e[3] = A[23];
  e[4] = 0.0;
  for (k = 0; k < 5; k++) {
    U[k + 20] = 0.0;
  }

  U[24] = 1.0;
  for (q = 3; q >= 0; q--) {
    qp1 = q + 2;
    i = q + 5 * q;
    if (s[q] != 0.0) {
      for (k = qp1; k < 6; k++) {
        qjj = (q + 5 * (k - 1)) + 1;
        st.site = &bf_emlrtRSI;
        nrm = xdotc(&st, 5 - q, U, i + 1, U, qjj);
        nrm = -(nrm / U[i]);
        xaxpy(5 - q, nrm, i + 1, U, qjj);
      }

      for (k = q + 1; k < 6; k++) {
        qjj = (k + 5 * q) - 1;
        U[qjj] = -U[qjj];
      }

      U[i]++;
      st.site = &af_emlrtRSI;
      for (k = 0; k < q; k++) {
        U[k + 5 * q] = 0.0;
      }
    } else {
      for (k = 0; k < 5; k++) {
        U[k + 5 * q] = 0.0;
      }

      U[i] = 1.0;
    }
  }

  for (q = 4; q >= 0; q--) {
    if ((q + 1 <= 3) && (e[q] != 0.0)) {
      qp1 = q + 2;
      qjj = (q + 5 * q) + 2;
      for (k = qp1; k < 6; k++) {
        i = (q + 5 * (k - 1)) + 2;
        st.site = &ye_emlrtRSI;
        nrm = xdotc(&st, 4 - q, Vf, qjj, Vf, i);
        nrm = -(nrm / Vf[qjj - 1]);
        xaxpy(4 - q, nrm, qjj, Vf, i);
      }
    }

    for (k = 0; k < 5; k++) {
      Vf[k + 5 * q] = 0.0;
    }

    Vf[q + 5 * q] = 1.0;
  }

  for (q = 0; q < 5; q++) {
    sqds = s[q];
    if (sqds != 0.0) {
      rt = muDoubleScalarAbs(sqds);
      nrm = sqds / rt;
      s[q] = rt;
      if (q + 1 < 5) {
        e[q] /= nrm;
      }

      st.site = &xe_emlrtRSI;
      c_xscal(&st, nrm, U, 5 * q + 1);
    }

    if ((q + 1 < 5) && (e[q] != 0.0)) {
      rt = muDoubleScalarAbs(e[q]);
      nrm = rt / e[q];
      e[q] = rt;
      s[q + 1] *= nrm;
      st.site = &we_emlrtRSI;
      c_xscal(&st, nrm, Vf, 5 * (q + 1) + 1);
    }
  }

  qp1 = 0;
  snorm = 0.0;
  for (k = 0; k < 5; k++) {
    snorm = muDoubleScalarMax(snorm, muDoubleScalarMax(muDoubleScalarAbs(s[k]),
      muDoubleScalarAbs(e[k])));
  }

  exitg1 = false;
  while ((!exitg1) && (m + 2 > 0)) {
    if (qp1 >= 75) {
      emlrtErrorWithMessageIdR2018a(sp, &c_emlrtRTEI,
        "Coder:MATLAB:svd_NoConvergence", "Coder:MATLAB:svd_NoConvergence", 0);
    } else {
      k = m;
      do {
        exitg2 = 0;
        q = k + 1;
        if (k + 1 == 0) {
          exitg2 = 1;
        } else {
          nrm = muDoubleScalarAbs(e[k]);
          if ((nrm <= 2.2204460492503131E-16 * (muDoubleScalarAbs(s[k]) +
                muDoubleScalarAbs(s[k + 1]))) || (nrm <= 1.0020841800044864E-292)
              || ((qp1 > 20) && (nrm <= 2.2204460492503131E-16 * snorm))) {
            e[k] = 0.0;
            exitg2 = 1;
          } else {
            k--;
          }
        }
      } while (exitg2 == 0);

      if (k + 1 == m + 1) {
        qjj = 4;
      } else {
        i = m + 2;
        qjj = m + 2;
        exitg3 = false;
        while ((!exitg3) && (qjj >= k + 1)) {
          i = qjj;
          if (qjj == k + 1) {
            exitg3 = true;
          } else {
            nrm = 0.0;
            if (qjj < m + 2) {
              nrm = muDoubleScalarAbs(e[qjj - 1]);
            }

            if (qjj > k + 2) {
              nrm += muDoubleScalarAbs(e[qjj - 2]);
            }

            rt = muDoubleScalarAbs(s[qjj - 1]);
            if ((rt <= 2.2204460492503131E-16 * nrm) || (rt <=
                 1.0020841800044864E-292)) {
              s[qjj - 1] = 0.0;
              exitg3 = true;
            } else {
              qjj--;
            }
          }
        }

        if (i == k + 1) {
          qjj = 3;
        } else if (i == m + 2) {
          qjj = 1;
        } else {
          qjj = 2;
          q = i;
        }
      }

      switch (qjj) {
       case 1:
        rt = e[m];
        e[m] = 0.0;
        qjj = m + 1;
        for (k = qjj; k >= q + 1; k--) {
          st.site = &ve_emlrtRSI;
          scale = 0.0;
          sn = 0.0;
          drotg(&s[k - 1], &rt, &scale, &sn);
          if (k > q + 1) {
            nrm = e[k - 2];
            rt = -sn * nrm;
            e[k - 2] = nrm * scale;
          }

          xrot(Vf, 5 * (k - 1) + 1, 5 * (m + 1) + 1, scale, sn);
        }
        break;

       case 2:
        rt = e[q - 1];
        e[q - 1] = 0.0;
        st.site = &ue_emlrtRSI;
        for (k = q + 1; k <= m + 2; k++) {
          st.site = &te_emlrtRSI;
          scale = 0.0;
          sn = 0.0;
          drotg(&s[k - 1], &rt, &scale, &sn);
          nrm = e[k - 1];
          rt = -sn * nrm;
          e[k - 1] = nrm * scale;
          xrot(U, 5 * (k - 1) + 1, 5 * (q - 1) + 1, scale, sn);
        }
        break;

       case 3:
        qjj = m + 1;
        nrm = s[m + 1];
        scale = muDoubleScalarMax(muDoubleScalarMax(muDoubleScalarMax
          (muDoubleScalarMax(muDoubleScalarAbs(nrm), muDoubleScalarAbs(s[m])),
           muDoubleScalarAbs(e[m])), muDoubleScalarAbs(s[q])), muDoubleScalarAbs
          (e[q]));
        sm = nrm / scale;
        nrm = s[m] / scale;
        rt = e[m] / scale;
        sqds = s[q] / scale;
        b = ((nrm + sm) * (nrm - sm) + rt * rt) / 2.0;
        nrm = sm * rt;
        nrm *= nrm;
        if ((b != 0.0) || (nrm != 0.0)) {
          rt = b * b + nrm;
          st.site = &se_emlrtRSI;
          if (rt < 0.0) {
            emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
              "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError",
              3, 4, 4, "sqrt");
          }

          rt = muDoubleScalarSqrt(rt);
          if (b < 0.0) {
            rt = -rt;
          }

          rt = nrm / (b + rt);
        } else {
          rt = 0.0;
        }

        rt += (sqds + sm) * (sqds - sm);
        nrm = sqds * (e[q] / scale);
        st.site = &re_emlrtRSI;
        for (k = q + 1; k <= qjj; k++) {
          st.site = &qe_emlrtRSI;
          scale = 0.0;
          sn = 0.0;
          drotg(&rt, &nrm, &scale, &sn);
          if (k > q + 1) {
            e[k - 2] = rt;
          }

          nrm = e[k - 1];
          rt = s[k - 1];
          sm = scale * rt + sn * nrm;
          e[k - 1] = scale * nrm - sn * rt;
          sqds = s[k];
          b = sn * sqds;
          sqds *= scale;
          xrot(Vf, 5 * (k - 1) + 1, 5 * k + 1, scale, sn);
          st.site = &pe_emlrtRSI;
          scale = 0.0;
          sn = 0.0;
          drotg(&sm, &b, &scale, &sn);
          s[k - 1] = sm;
          rt = scale * e[k - 1] + sn * sqds;
          sqds = -sn * e[k - 1] + scale * sqds;
          s[k] = sqds;
          nrm = sn * e[k];
          e[k] *= scale;
          xrot(U, 5 * (k - 1) + 1, 5 * k + 1, scale, sn);
        }

        e[m] = rt;
        qp1++;
        break;

       default:
        if (s[q] < 0.0) {
          s[q] = -s[q];
          st.site = &oe_emlrtRSI;
          c_xscal(&st, -1.0, Vf, 5 * q + 1);
        }

        qp1 = q + 1;
        while ((q + 1 < 5) && (s[q] < s[qp1])) {
          rt = s[q];
          s[q] = s[qp1];
          s[qp1] = rt;
          xswap(Vf, 5 * q + 1, 5 * (q + 1) + 1);
          xswap(U, 5 * q + 1, 5 * (q + 1) + 1);
          q = qp1;
          qp1++;
        }

        qp1 = 0;
        m--;
        break;
      }
    }
  }

  for (k = 0; k < 5; k++) {
    S[k] = s[k];
    for (i = 0; i < 5; i++) {
      qjj = i + 5 * k;
      V[qjj] = Vf[qjj];
    }
  }
}

/* End of code generation (xzsvdc.c) */
