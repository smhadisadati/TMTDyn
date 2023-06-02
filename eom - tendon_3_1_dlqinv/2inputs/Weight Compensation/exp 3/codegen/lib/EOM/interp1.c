/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: interp1.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 08-May-2021 02:08:04
 */

/* Include Files */
#include "interp1.h"
#include "spline.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double varargin_1[3618]
 *                const double varargin_2[10854]
 *                double varargin_3
 *                double Vq[3]
 * Return Type  : void
 */
void interp1(const double varargin_1[3618], const double varargin_2[10854],
             double varargin_3, double Vq[3])
{
  static double pp_coefs[43404];
  static double b_y[10854];
  static double y[10854];
  double pp_breaks[3618];
  double x[3618];
  double c0;
  double c1;
  double d2max;
  double h;
  double s3m4;
  double xtmp;
  int exponent;
  int icp;
  int low_i;
  int low_ip1;
  int offset;
  int y_tmp;
  memcpy(&y[0], &varargin_2[0], 10854U * sizeof(double));
  memcpy(&x[0], &varargin_1[0], 3618U * sizeof(double));
  if (varargin_1[1] < varargin_1[0]) {
    for (low_ip1 = 0; low_ip1 < 1809; low_ip1++) {
      xtmp = x[low_ip1];
      x[low_ip1] = x[3617 - low_ip1];
      x[3617 - low_ip1] = xtmp;
    }

    for (low_ip1 = 0; low_ip1 < 3; low_ip1++) {
      offset = low_ip1 * 3618 + 3618;
      for (icp = 0; icp < 1809; icp++) {
        low_i = (offset + icp) - 3618;
        xtmp = y[low_i];
        y_tmp = (offset - icp) - 1;
        y[low_i] = y[y_tmp];
        y[y_tmp] = xtmp;
      }
    }
  }

  h = 0.0;
  d2max = 0.0;
  for (icp = 0; icp < 3616; icp++) {
    xtmp = x[icp + 1];
    xtmp = fabs((x[icp + 2] - xtmp) - (xtmp - x[icp]));
    if (xtmp > d2max) {
      d2max = xtmp;
    }
  }

  xtmp = fmax(fabs(x[0]), fabs(x[3617]));
  if (xtmp <= 2.2250738585072014E-308) {
    xtmp = 4.94065645841247E-324;
  } else {
    frexp(xtmp, &exponent);
    xtmp = ldexp(1.0, exponent - 53);
  }

  if (d2max <= 2.0 * xtmp) {
    h = (x[3617] - x[0]) / 3617.0;
  }

  if (h > 0.0) {
    Vq[0] = 0.0;
    Vq[1] = 0.0;
    Vq[2] = 0.0;
    if ((varargin_3 >= x[0]) && (varargin_3 <= x[3617])) {
      if (varargin_3 < x[1]) {
        low_ip1 = 1;
        d2max = (varargin_3 - x[0]) / h;
      } else if (varargin_3 >= x[3616]) {
        low_ip1 = 3617;
        d2max = (varargin_3 - x[3616]) / h;
      } else {
        xtmp = floor((varargin_3 - x[0]) / h);
        low_ip1 = (int)(xtmp + 1.0);
        d2max = (varargin_3 - x[(int)(xtmp + 1.0) - 1]) / h;
      }

      xtmp = d2max / 2.0;
      h = d2max * xtmp;
      s3m4 = 3.0 * d2max - 4.0;
      c0 = -d2max * (d2max * (xtmp - 1.0) + 0.5);
      c1 = h * (s3m4 - 1.0) + 1.0;
      s3m4 = -xtmp * (d2max * s3m4 - 1.0);
      xtmp = h * (d2max - 1.0);
      if (low_ip1 < 2) {
        h = y[low_ip1 - 1];
        d2max = y[low_ip1 + 1];
        Vq[0] = ((c0 * ((3.0 * h - 3.0 * y[low_ip1]) + d2max) + c1 * h) + s3m4 *
                 y[low_ip1]) + xtmp * d2max;
        h = y[low_ip1 + 3617];
        d2max = y[low_ip1 + 3619];
        Vq[1] = ((c0 * ((3.0 * h - 3.0 * y[low_ip1 + 3618]) + d2max) + c1 * h) +
                 s3m4 * y[low_ip1 + 3618]) + xtmp * d2max;
        h = y[low_ip1 + 7235];
        d2max = y[low_ip1 + 7237];
        Vq[2] = ((c0 * ((3.0 * h - 3.0 * y[low_ip1 + 7236]) + d2max) + c1 * h) +
                 s3m4 * y[low_ip1 + 7236]) + xtmp * d2max;
      } else if (low_ip1 < 3617) {
        Vq[0] = ((c0 * y[low_ip1 - 2] + c1 * y[low_ip1 - 1]) + s3m4 * y[low_ip1])
          + xtmp * y[low_ip1 + 1];
        Vq[1] = ((c0 * y[low_ip1 + 3616] + c1 * y[low_ip1 + 3617]) + s3m4 *
                 y[low_ip1 + 3618]) + xtmp * y[low_ip1 + 3619];
        Vq[2] = ((c0 * y[low_ip1 + 7234] + c1 * y[low_ip1 + 7235]) + s3m4 *
                 y[low_ip1 + 7236]) + xtmp * y[low_ip1 + 7237];
      } else {
        h = y[low_ip1 - 1];
        d2max = y[low_ip1 - 2];
        Vq[0] = ((c0 * d2max + c1 * h) + s3m4 * y[low_ip1]) + xtmp * ((3.0 *
          y[low_ip1] - 3.0 * h) + d2max);
        h = y[low_ip1 + 3617];
        d2max = y[low_ip1 + 3616];
        Vq[1] = ((c0 * d2max + c1 * h) + s3m4 * y[low_ip1 + 3618]) + xtmp *
          ((3.0 * y[low_ip1 + 3618] - 3.0 * h) + d2max);
        h = y[low_ip1 + 7235];
        d2max = y[low_ip1 + 7234];
        Vq[2] = ((c0 * d2max + c1 * h) + s3m4 * y[low_ip1 + 7236]) + xtmp *
          ((3.0 * y[low_ip1 + 7236] - 3.0 * h) + d2max);
      }
    }
  } else {
    for (low_ip1 = 0; low_ip1 < 3618; low_ip1++) {
      b_y[3 * low_ip1] = y[low_ip1];
      b_y[3 * low_ip1 + 1] = y[low_ip1 + 3618];
      b_y[3 * low_ip1 + 2] = y[low_ip1 + 7236];
    }

    spline(x, b_y, pp_breaks, pp_coefs);
    low_i = 1;
    low_ip1 = 2;
    offset = 3618;
    while (offset > low_ip1) {
      icp = (low_i + offset) >> 1;
      if (varargin_3 >= pp_breaks[icp - 1]) {
        low_i = icp;
        low_ip1 = icp + 1;
      } else {
        offset = icp;
      }
    }

    icp = (low_i - 1) * 3;
    xtmp = varargin_3 - pp_breaks[low_i - 1];
    d2max = pp_coefs[icp];
    s3m4 = pp_coefs[icp + 1];
    h = pp_coefs[icp + 2];
    for (low_ip1 = 0; low_ip1 < 3; low_ip1++) {
      offset = icp + (low_ip1 + 1) * 10851;
      d2max = xtmp * d2max + pp_coefs[offset];
      s3m4 = xtmp * s3m4 + pp_coefs[offset + 1];
      h = xtmp * h + pp_coefs[offset + 2];
    }

    Vq[0] = d2max;
    Vq[1] = s3m4;
    Vq[2] = h;
  }
}

/*
 * File trailer for interp1.c
 *
 * [EOF]
 */
