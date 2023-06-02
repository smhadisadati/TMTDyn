/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * interp1.c
 *
 * Code generation for function 'interp1'
 *
 */

/* Include files */
#include "interp1.h"
#include "EOM_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
void interp1(const emlrtStack *sp, const real_T varargin_1[1710], const real_T
             varargin_2[5130], real_T varargin_3, real_T Vq[3])
{
  emlrtStack st;
  real_T y[5130];
  real_T x[1710];
  real_T b_y1;
  real_T xtmp;
  real_T y2;
  int32_T exitg1;
  int32_T high_i;
  int32_T j;
  int32_T low_ip1;
  int32_T mid_i;
  int32_T offset;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &cb_emlrtRSI;
  memcpy(&y[0], &varargin_2[0], 5130U * sizeof(real_T));
  memcpy(&x[0], &varargin_1[0], 1710U * sizeof(real_T));
  mid_i = 0;
  do {
    exitg1 = 0;
    if (mid_i < 1710) {
      if (muDoubleScalarIsNaN(varargin_1[mid_i])) {
        emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI, "MATLAB:interp1:NaNinX",
          "MATLAB:interp1:NaNinX", 0);
      } else {
        mid_i++;
      }
    } else {
      if (varargin_1[1] < varargin_1[0]) {
        for (offset = 0; offset < 855; offset++) {
          xtmp = x[offset];
          x[offset] = x[1709 - offset];
          x[1709 - offset] = xtmp;
        }

        for (j = 0; j < 3; j++) {
          offset = j * 1710 + 1710;
          for (mid_i = 0; mid_i < 855; mid_i++) {
            low_ip1 = (offset + mid_i) - 1710;
            xtmp = y[low_ip1];
            high_i = (offset - mid_i) - 1;
            y[low_ip1] = y[high_i];
            y[high_i] = xtmp;
          }
        }
      }

      for (mid_i = 0; mid_i < 1709; mid_i++) {
        if (x[mid_i + 1] <= x[mid_i]) {
          emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
            "Coder:toolbox:interp1_nonMonotonicX",
            "Coder:toolbox:interp1_nonMonotonicX", 0);
        }
      }

      Vq[0] = 0.0;
      Vq[1] = 0.0;
      Vq[2] = 0.0;
      if (muDoubleScalarIsNaN(varargin_3)) {
        Vq[0] = rtNaN;
        Vq[1] = rtNaN;
        Vq[2] = rtNaN;
      } else {
        if ((!(varargin_3 > x[1709])) && (!(varargin_3 < x[0]))) {
          offset = 1;
          low_ip1 = 2;
          high_i = 1710;
          while (high_i > low_ip1) {
            mid_i = (offset + high_i) >> 1;
            if (varargin_3 >= x[mid_i - 1]) {
              offset = mid_i;
              low_ip1 = mid_i + 1;
            } else {
              high_i = mid_i;
            }
          }

          xtmp = x[offset - 1];
          xtmp = (varargin_3 - xtmp) / (x[offset] - xtmp);
          if (xtmp == 0.0) {
            Vq[0] = y[offset - 1];
            Vq[1] = y[offset + 1709];
            Vq[2] = y[offset + 3419];
          } else if (xtmp == 1.0) {
            Vq[0] = y[offset];
            Vq[1] = y[offset + 1710];
            Vq[2] = y[offset + 3420];
          } else {
            b_y1 = y[offset - 1];
            y2 = y[offset];
            if (b_y1 == y2) {
              Vq[0] = b_y1;
            } else {
              Vq[0] = (1.0 - xtmp) * b_y1 + xtmp * y2;
            }

            b_y1 = y[offset + 1709];
            y2 = y[offset + 1710];
            if (b_y1 == y2) {
              Vq[1] = b_y1;
            } else {
              Vq[1] = (1.0 - xtmp) * b_y1 + xtmp * y2;
            }

            b_y1 = y[offset + 3419];
            y2 = y[offset + 3420];
            if (b_y1 == y2) {
              Vq[2] = b_y1;
            } else {
              Vq[2] = (1.0 - xtmp) * b_y1 + xtmp * y2;
            }
          }
        }
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

/* End of code generation (interp1.c) */
