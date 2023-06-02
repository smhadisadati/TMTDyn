/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: spline.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 08-May-2021 02:08:04
 */

/* Include Files */
#include "spline.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double x[3618]
 *                const double y[10854]
 *                double output_breaks[3618]
 *                double output_coefs[43404]
 * Return Type  : void
 */
void spline(const double x[3618], const double y[10854], double output_breaks
            [3618], double output_coefs[43404])
{
  static double s[10854];
  static double dvdf[10851];
  double md[3618];
  double dx[3617];
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
  for (k = 0; k < 3617; k++) {
    d = x[k + 1] - x[k];
    dx[k] = d;
    dpg = k * 3 - 1;
    pgp1 = (k + 1) * 3;
    dvdf[dpg + 1] = (y[pgp1] - y[dpg + 1]) / d;
    dvdf[dpg + 2] = (y[pgp1 + 1] - y[dpg + 2]) / d;
    dvdf[dpg + 3] = (y[pgp1 + 2] - y[dpg + 3]) / d;
  }

  d31 = x[2] - x[0];
  dnnm2 = x[3617] - x[3615];
  r = (dx[0] + 2.0 * d31) * dx[1];
  dxj = dx[0] * dx[0];
  dzzdx = (dx[3616] + 2.0 * dnnm2) * dx[3615];
  s_tmp = dx[3616] * dx[3616];
  md[0] = dx[1];
  md[3617] = dx[3615];
  for (k = 0; k < 3616; k++) {
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
  s[10851] = (dzzdx * dvdf[10848] + s_tmp * dvdf[10845]) / dnnm2;
  s[10852] = (dzzdx * dvdf[10849] + s_tmp * dvdf[10846]) / dnnm2;
  s[10853] = (dzzdx * dvdf[10850] + s_tmp * dvdf[10847]) / dnnm2;
  r = dx[1] / md[0];
  md[1] -= r * d31;
  s[3] -= r * s[0];
  s[4] -= r * s[1];
  s[5] -= r * s[2];
  for (k = 0; k < 3615; k++) {
    r = dx[k + 2] / md[k + 1];
    md[k + 2] -= r * dx[k];
    dpg = (k + 2) * 3 - 1;
    pgp1 = (k + 1) * 3;
    s[dpg + 1] -= r * s[pgp1];
    s[dpg + 2] -= r * s[pgp1 + 1];
    s[dpg + 3] -= r * s[pgp1 + 2];
  }

  r = dnnm2 / md[3616];
  md[3617] -= r * dx[3615];
  s[10851] -= r * s[10848];
  s[10852] -= r * s[10849];
  s[10853] -= r * s[10850];
  s[10851] /= md[3617];
  s[10852] /= md[3617];
  s[10853] /= md[3617];
  for (k = 3615; k >= 0; k--) {
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
  memcpy(&output_breaks[0], &x[0], 3618U * sizeof(double));
  for (dpg = 0; dpg < 3617; dpg++) {
    dxj = dx[dpg];
    pgp1 = dpg * 3 - 1;
    r = dvdf[pgp1 + 1];
    d = s[pgp1 + 1];
    dzzdx = (r - d) / dxj;
    r = (s[pgp1 + 4] - r) / dxj;
    output_coefs[pgp1 + 1] = (r - dzzdx) / dxj;
    output_coefs[pgp1 + 10852] = 2.0 * dzzdx - r;
    output_coefs[pgp1 + 21703] = d;
    output_coefs[pgp1 + 32554] = y[pgp1 + 1];
    r = dvdf[pgp1 + 2];
    d = s[pgp1 + 2];
    dzzdx = (r - d) / dxj;
    r = (s[pgp1 + 5] - r) / dxj;
    output_coefs[pgp1 + 2] = (r - dzzdx) / dxj;
    output_coefs[pgp1 + 10853] = 2.0 * dzzdx - r;
    output_coefs[pgp1 + 21704] = d;
    output_coefs[pgp1 + 32555] = y[pgp1 + 2];
    r = dvdf[pgp1 + 3];
    d = s[pgp1 + 3];
    dzzdx = (r - d) / dxj;
    r = (s[pgp1 + 6] - r) / dxj;
    output_coefs[pgp1 + 3] = (r - dzzdx) / dxj;
    output_coefs[pgp1 + 10854] = 2.0 * dzzdx - r;
    output_coefs[pgp1 + 21705] = d;
    output_coefs[pgp1 + 32556] = y[pgp1 + 3];
  }
}

/*
 * File trailer for spline.c
 *
 * [EOF]
 */
