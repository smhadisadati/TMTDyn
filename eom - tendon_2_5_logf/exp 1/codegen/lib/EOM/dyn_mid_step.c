/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: dyn_mid_step.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 06-Apr-2021 13:11:18
 */

/* Include Files */
#include "dyn_mid_step.h"
#include "EOM_types.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * inputs positions
 * Arguments    : double t
 *                struct0_T *par_mex
 * Return Type  : void
 */
void dyn_mid_step(double t, struct0_T *par_mex)
{
  double varargin_2[8535];
  double varargin_1[1707];
  double q_u[5];
  double b_y1;
  double l_w_idx_0;
  double xtmp;
  double y2;
  int high_i;
  int j;
  int low_i;
  int mid_i;
  int offset;
  memcpy(&varargin_1[0], &par_mex->user_pars.motor_in.pos[0], 1707U * sizeof
         (double));
  for (offset = 0; offset < 5; offset++) {
    memcpy(&varargin_2[offset * 1707], &par_mex->user_pars.motor_in.pos[offset *
           1707 + 1707], 1707U * sizeof(double));
  }

  if (par_mex->user_pars.motor_in.pos[1] < par_mex->user_pars.motor_in.pos[0]) {
    for (offset = 0; offset < 853; offset++) {
      xtmp = varargin_1[offset];
      varargin_1[offset] = varargin_1[1706 - offset];
      varargin_1[1706 - offset] = xtmp;
    }

    for (j = 0; j < 5; j++) {
      offset = j * 1707 + 1707;
      for (low_i = 0; low_i < 853; low_i++) {
        high_i = (offset + low_i) - 1707;
        xtmp = varargin_2[high_i];
        mid_i = (offset - low_i) - 1;
        varargin_2[high_i] = varargin_2[mid_i];
        varargin_2[mid_i] = xtmp;
      }
    }
  }

  for (offset = 0; offset < 5; offset++) {
    q_u[offset] = 0.0;
  }

  if ((t <= varargin_1[1706]) && (t >= varargin_1[0])) {
    low_i = 1;
    offset = 2;
    high_i = 1707;
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
      for (j = 0; j < 5; j++) {
        q_u[j] = varargin_2[(low_i + j * 1707) - 1];
      }
    } else if (xtmp == 1.0) {
      for (j = 0; j < 5; j++) {
        q_u[j] = varargin_2[low_i + j * 1707];
      }
    } else {
      for (j = 0; j < 5; j++) {
        offset = low_i + j * 1707;
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

  /*  curvature inputs */
  /*  wire offsets diameter: 2*(r_s21+r_s22)/2 */
  xtmp = par_mex->var[16];
  l_w_idx_0 = q_u[0] + xtmp;
  b_y1 = q_u[1] + xtmp;

  /*  % 3 tendons */
  /*  kappa = 2*sqrt(l(1)^2+l(2)^2+l(3)^2-l(1)*l(2)-l(1)*l(3)-l(2)*l(3))/(d*(l(1)+l(2)+l(3))); */
  /*  phi = atan2(sqrt(3)*(l(2)+l(3)-2*l(1)),(3*(l(2)-l(3)))); */
  /*  4 tendons */
  xtmp = (((l_w_idx_0 + b_y1) + (q_u[2] + xtmp)) + (q_u[3] + xtmp)) / 4.0;

  /*  l_b = l_s2; */
  b_y1 = atan2(b_y1 - xtmp, l_w_idx_0 - xtmp);
  y2 = cos(b_y1);
  xtmp = (xtmp - l_w_idx_0) / (xtmp * (par_mex->var[8] + par_mex->var[9]) / 2.0 *
    y2);

  /*  model inputs */
  /*  inner (introducer) tube lengths */
  /*  update par */
  /*  vars = [ sigma_s1_sym sigma_s2_sym E_s1_sym E_s2_sym G_s1_sym G_s2_sym ... */
  /*      r_s11_sym r_s12_sym r_s21_sym r_s22_sym ... */
  /*      mu_x1_sym mu_y1_sym mu_z1_sym mu_xx1_sym mu_yy1_sym mu_zz1_sym ... */
  /*      mu_x2_sym mu_y2_sym mu_z2_sym mu_xx2_sym mu_yy2_sym mu_zz2_sym ... */
  /*      mu_pow_sym g_xsym g_ysym g_zsym ... */
  /*      l_s1_sym l_s2_sym dl_sym kappa_x_sym kappa_y_sym ... */
  /*      f_tx_sym f_ty_sym f_tz_sym tau_tx_sym tau_ty_sym tau_tz_sym ] ; */
  par_mex->var[17] = q_u[4];
  par_mex->var[18] = xtmp * sin(b_y1);
  par_mex->var[19] = xtmp * y2;
}

/*
 * File trailer for dyn_mid_step.c
 *
 * [EOF]
 */
