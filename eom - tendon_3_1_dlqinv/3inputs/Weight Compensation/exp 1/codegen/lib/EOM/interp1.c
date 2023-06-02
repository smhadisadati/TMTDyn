/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: interp1.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 08-May-2021 03:51:05
 */

/* Include Files */
#include "interp1.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double varargin_1[1707]
 *                const double varargin_2[5121]
 *                double varargin_3
 *                double Vq[3]
 * Return Type  : void
 */
void interp1(const double varargin_1[1707], const double varargin_2[5121],
             double varargin_3, double Vq[3])
{
  double y[5121];
  double x[1707];
  double b_y1;
  double xtmp;
  double y2;
  int high_i;
  int low_i;
  int mid_i;
  int offset;
  int y_tmp;
  memcpy(&y[0], &varargin_2[0], 5121U * sizeof(double));
  memcpy(&x[0], &varargin_1[0], 1707U * sizeof(double));
  if (varargin_1[1] < varargin_1[0]) {
    for (low_i = 0; low_i < 853; low_i++) {
      xtmp = x[low_i];
      x[low_i] = x[1706 - low_i];
      x[1706 - low_i] = xtmp;
    }

    for (low_i = 0; low_i < 3; low_i++) {
      offset = low_i * 1707 + 1707;
      for (high_i = 0; high_i < 853; high_i++) {
        mid_i = (offset + high_i) - 1707;
        xtmp = y[mid_i];
        y_tmp = (offset - high_i) - 1;
        y[mid_i] = y[y_tmp];
        y[y_tmp] = xtmp;
      }
    }
  }

  Vq[0] = 0.0;
  Vq[1] = 0.0;
  Vq[2] = 0.0;
  if ((varargin_3 <= x[1706]) && (varargin_3 >= x[0])) {
    low_i = 1;
    offset = 2;
    high_i = 1707;
    while (high_i > offset) {
      mid_i = (low_i + high_i) >> 1;
      if (varargin_3 >= x[mid_i - 1]) {
        low_i = mid_i;
        offset = mid_i + 1;
      } else {
        high_i = mid_i;
      }
    }

    xtmp = x[low_i - 1];
    xtmp = (varargin_3 - xtmp) / (x[low_i] - xtmp);
    if (xtmp == 0.0) {
      Vq[0] = y[low_i - 1];
      Vq[1] = y[low_i + 1706];
      Vq[2] = y[low_i + 3413];
    } else if (xtmp == 1.0) {
      Vq[0] = y[low_i];
      Vq[1] = y[low_i + 1707];
      Vq[2] = y[low_i + 3414];
    } else {
      b_y1 = y[low_i - 1];
      y2 = y[low_i];
      if (b_y1 == y2) {
        Vq[0] = b_y1;
      } else {
        Vq[0] = (1.0 - xtmp) * b_y1 + xtmp * y2;
      }

      b_y1 = y[low_i + 1706];
      y2 = y[low_i + 1707];
      if (b_y1 == y2) {
        Vq[1] = b_y1;
      } else {
        Vq[1] = (1.0 - xtmp) * b_y1 + xtmp * y2;
      }

      b_y1 = y[low_i + 3413];
      y2 = y[low_i + 3414];
      if (b_y1 == y2) {
        Vq[2] = b_y1;
      } else {
        Vq[2] = (1.0 - xtmp) * b_y1 + xtmp * y2;
      }
    }
  }
}

/*
 * File trailer for interp1.c
 *
 * [EOF]
 */
