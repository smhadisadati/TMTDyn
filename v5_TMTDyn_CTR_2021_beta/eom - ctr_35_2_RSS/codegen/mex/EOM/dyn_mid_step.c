/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * dyn_mid_step.c
 *
 * Code generation for function 'dyn_mid_step'
 *
 */

/* Include files */
#include "dyn_mid_step.h"
#include "EOM_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo mc_emlrtRSI = { 4,  /* lineNo */
  "dyn_mid_step",                      /* fcnName */
  "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\2. Model\\CTR TMTDyn\\eom\\user_codes\\dyn_mid_step.m"/* pathName */
};

static emlrtRSInfo nc_emlrtRSI = { 54, /* lineNo */
  "interp1",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m"/* pathName */
};

static emlrtRTEInfo f_emlrtRTEI = { 163,/* lineNo */
  13,                                  /* colNo */
  "interp1_work",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 183,/* lineNo */
  13,                                  /* colNo */
  "interp1_work",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m"/* pName */
};

/* Function Definitions */
void dyn_mid_step(const emlrtStack *sp, real_T t, struct0_T *par_mex)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T varargin_2[1014];
  real_T varargin_1[169];
  real_T q_u[6];
  real_T b_y1;
  real_T xtmp;
  real_T y2;
  int32_T exitg1;
  int32_T high_i;
  int32_T j;
  int32_T low_i;
  int32_T mid_i;
  int32_T offset;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;

  /*  inputs positions */
  st.site = &mc_emlrtRSI;
  memcpy(&varargin_1[0], &par_mex->user_pars.motor_in.pos[0], 169U * sizeof
         (real_T));
  for (offset = 0; offset < 6; offset++) {
    memcpy(&varargin_2[offset * 169], &par_mex->user_pars.motor_in.pos[offset *
           169 + 169], 169U * sizeof(real_T));
  }

  b_st.site = &nc_emlrtRSI;
  low_i = 0;
  do {
    exitg1 = 0;
    if (low_i < 169) {
      if (muDoubleScalarIsNaN(par_mex->user_pars.motor_in.pos[low_i])) {
        emlrtErrorWithMessageIdR2018a(&b_st, &f_emlrtRTEI,
          "MATLAB:interp1:NaNinX", "MATLAB:interp1:NaNinX", 0);
      } else {
        low_i++;
      }
    } else {
      if (par_mex->user_pars.motor_in.pos[1] < par_mex->user_pars.motor_in.pos[0])
      {
        for (offset = 0; offset < 84; offset++) {
          xtmp = varargin_1[offset];
          varargin_1[offset] = varargin_1[168 - offset];
          varargin_1[168 - offset] = xtmp;
        }

        for (j = 0; j < 6; j++) {
          offset = j * 169 + 169;
          for (low_i = 0; low_i < 84; low_i++) {
            high_i = (offset + low_i) - 169;
            xtmp = varargin_2[high_i];
            mid_i = (offset - low_i) - 1;
            varargin_2[high_i] = varargin_2[mid_i];
            varargin_2[mid_i] = xtmp;
          }
        }
      }

      for (low_i = 0; low_i < 168; low_i++) {
        if (varargin_1[low_i + 1] <= varargin_1[low_i]) {
          emlrtErrorWithMessageIdR2018a(&b_st, &g_emlrtRTEI,
            "Coder:toolbox:interp1_nonMonotonicX",
            "Coder:toolbox:interp1_nonMonotonicX", 0);
        }
      }

      for (offset = 0; offset < 6; offset++) {
        q_u[offset] = 0.0;
      }

      if (muDoubleScalarIsNaN(t)) {
        for (j = 0; j < 6; j++) {
          q_u[j] = rtNaN;
        }
      } else {
        if ((!(t > varargin_1[168])) && (!(t < varargin_1[0]))) {
          low_i = 1;
          offset = 2;
          high_i = 169;
          while (high_i > offset) {
            mid_i = (low_i + high_i) >> 1;
            if (t >= varargin_1[mid_i - 1]) {
              low_i = mid_i;
              offset = mid_i + 1;
            } else {
              high_i = mid_i;
            }
          }

          xtmp = varargin_1[low_i - 1];
          xtmp = (t - xtmp) / (varargin_1[low_i] - xtmp);
          if (xtmp == 0.0) {
            for (j = 0; j < 6; j++) {
              q_u[j] = varargin_2[(low_i + j * 169) - 1];
            }
          } else if (xtmp == 1.0) {
            for (j = 0; j < 6; j++) {
              q_u[j] = varargin_2[low_i + j * 169];
            }
          } else {
            for (j = 0; j < 6; j++) {
              offset = low_i + j * 169;
              b_y1 = varargin_2[offset - 1];
              y2 = varargin_2[offset];
              if (b_y1 == y2) {
                q_u[j] = b_y1;
              } else {
                q_u[j] = (1.0 - xtmp) * b_y1 + xtmp * y2;
              }
            }
          }
        }
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);

  /*  straight part overlapping */
  /*  relaxed state base (straight section) length */
  xtmp = (0.20800000000000002 - par_mex->var[36]) + q_u[2];
  if ((xtmp < 0.001) || muDoubleScalarIsNaN(xtmp)) {
    xtmp = 0.001;
  }

  /*  external forces */
  /*  ftau_ex = [ 0 0 0 0 0 0 ] ; % tip load */
  /*  update par */
  /*  par_mex.var(end-11:end) = [ ftau_u ftau_ex ] ; */
  par_mex->var[45] = 0.0;
  par_mex->var[46] = xtmp;
  par_mex->var[47] = 0.0;
  for (offset = 0; offset < 6; offset++) {
    par_mex->var[offset + 48] = q_u[offset];
  }
}

/* End of code generation (dyn_mid_step.c) */
