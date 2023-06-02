/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: spline.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 08-May-2021 01:57:20
 */

/* Include Files */
#include "spline.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double x[14584]
 *                const double y[43752]
 *                double output_breaks[14584]
 *                double output_coefs[174996]
 * Return Type  : void
 */
void spline(const double x[14584], const double y[43752], double output_breaks
            [14584], double output_coefs[174996])
{
  static double s[43752];
  static double dvdf[43749];
  static double md[14584];
  double dx[14583];
  double b_s_tmp;
  double d;
  double d31;
  double dnnm2;
  double dxj;
  double dzzdx;
  double r;
  double s_tmp;
  int dpg;
  int k;
  int pgp1;
  for (k = 0; k < 14583; k++) {
    d = x[k + 1] - x[k];
    dx[k] = d;
    dpg = k * 3 - 1;
    pgp1 = (k + 1) * 3;
    dvdf[dpg + 1] = (y[pgp1] - y[dpg + 1]) / d;
    dvdf[dpg + 2] = (y[pgp1 + 1] - y[dpg + 2]) / d;
    dvdf[dpg + 3] = (y[pgp1 + 2] - y[dpg + 3]) / d;
  }

  d31 = x[2] - x[0];
  dnnm2 = x[14583] - x[14581];
  r = (dx[0] + 2.0 * d31) * dx[1];
  dxj = dx[0] * dx[0];
  dzzdx = (dx[14582] + 2.0 * dnnm2) * dx[14581];
  s_tmp = dx[14582] * dx[14582];
  md[0] = dx[1];
  md[14583] = dx[14581];
  for (k = 0; k < 14582; k++) {
    dpg = (k + 1) * 3 - 1;
    pgp1 = k * 3;
    b_s_tmp = dx[k + 1];
    d = dx[k];
    s[dpg + 1] = 3.0 * (b_s_tmp * dvdf[pgp1] + d * dvdf[dpg + 1]);
    s[dpg + 2] = 3.0 * (b_s_tmp * dvdf[pgp1 + 1] + d * dvdf[dpg + 2]);
    s[dpg + 3] = 3.0 * (b_s_tmp * dvdf[pgp1 + 2] + d * dvdf[dpg + 3]);
    md[k + 1] = 2.0 * (b_s_tmp + d);
  }

  s[0] = (r * dvdf[0] + dxj * dvdf[3]) / d31;
  s[1] = (r * dvdf[1] + dxj * dvdf[4]) / d31;
  s[2] = (r * dvdf[2] + dxj * dvdf[5]) / d31;
  s[43749] = (dzzdx * dvdf[43746] + s_tmp * dvdf[43743]) / dnnm2;
  s[43750] = (dzzdx * dvdf[43747] + s_tmp * dvdf[43744]) / dnnm2;
  s[43751] = (dzzdx * dvdf[43748] + s_tmp * dvdf[43745]) / dnnm2;
  r = dx[1] / md[0];
  md[1] -= r * d31;
  s[3] -= r * s[0];
  s[4] -= r * s[1];
  s[5] -= r * s[2];
  for (k = 0; k < 14581; k++) {
    r = dx[k + 2] / md[k + 1];
    md[k + 2] -= r * dx[k];
    dpg = (k + 2) * 3 - 1;
    pgp1 = (k + 1) * 3;
    s[dpg + 1] -= r * s[pgp1];
    s[dpg + 2] -= r * s[pgp1 + 1];
    s[dpg + 3] -= r * s[pgp1 + 2];
  }

  r = dnnm2 / md[14582];
  md[14583] -= r * dx[14581];
  s[43749] -= r * s[43746];
  s[43750] -= r * s[43747];
  s[43751] -= r * s[43748];
  s[43749] /= md[14583];
  s[43750] /= md[14583];
  s[43751] /= md[14583];
  for (k = 14581; k >= 0; k--) {
    dpg = (k + 1) * 3 - 1;
    pgp1 = (k + 2) * 3;
    r = md[k + 1];
    d = dx[k];
    s[dpg + 1] = (s[dpg + 1] - d * s[pgp1]) / r;
    s[dpg + 2] = (s[dpg + 2] - d * s[pgp1 + 1]) / r;
    s[dpg + 3] = (s[dpg + 3] - d * s[pgp1 + 2]) / r;
  }

  s[0] = (s[0] - d31 * s[3]) / md[0];
  s[1] = (s[1] - d31 * s[4]) / md[0];
  s[2] = (s[2] - d31 * s[5]) / md[0];
  memcpy(&output_breaks[0], &x[0], 14584U * sizeof(double));
  for (dpg = 0; dpg < 14583; dpg++) {
    dxj = dx[dpg];
    pgp1 = dpg * 3 - 1;
    r = dvdf[pgp1 + 1];
    d = s[pgp1 + 1];
    dzzdx = (r - d) / dxj;
    r = (s[pgp1 + 4] - r) / dxj;
    output_coefs[pgp1 + 1] = (r - dzzdx) / dxj;
    output_coefs[pgp1 + 43750] = 2.0 * dzzdx - r;
    output_coefs[pgp1 + 87499] = d;
    output_coefs[pgp1 + 131248] = y[pgp1 + 1];
    r = dvdf[pgp1 + 2];
    d = s[pgp1 + 2];
    dzzdx = (r - d) / dxj;
    r = (s[pgp1 + 5] - r) / dxj;
    output_coefs[pgp1 + 2] = (r - dzzdx) / dxj;
    output_coefs[pgp1 + 43751] = 2.0 * dzzdx - r;
    output_coefs[pgp1 + 87500] = d;
    output_coefs[pgp1 + 131249] = y[pgp1 + 2];
    r = dvdf[pgp1 + 3];
    d = s[pgp1 + 3];
    dzzdx = (r - d) / dxj;
    r = (s[pgp1 + 6] - r) / dxj;
    output_coefs[pgp1 + 3] = (r - dzzdx) / dxj;
    output_coefs[pgp1 + 43752] = 2.0 * dzzdx - r;
    output_coefs[pgp1 + 87501] = d;
    output_coefs[pgp1 + 131250] = y[pgp1 + 3];
  }
}

/*
 * File trailer for spline.c
 *
 * [EOF]
 */
