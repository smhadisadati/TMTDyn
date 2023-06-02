/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: dyn_mid_step.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 07-May-2021 19:09:09
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
  double b_varargin_2[6840];
  double b_varargin_1[1710];
  double varargin_1[1707];
  double q_u[5];
  double b_y1;
  double kappa;
  double kappa_tmp;
  double l_w_idx_0;
  double l_w_idx_1;
  double l_w_idx_2;
  double phi;
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
  l_w_idx_1 = q_u[1] + xtmp;

  /*  % 3 tendons */
  /*  kappa = 2*sqrt(l(1)^2+l(2)^2+l(3)^2-l(1)*l(2)-l(1)*l(3)-l(2)*l(3))/(d*(l(1)+l(2)+l(3))); */
  /*  phi = atan2(sqrt(3)*(l(2)+l(3)-2*l(1)),(3*(l(2)-l(3)))); */
  /*  4 tendons */
  xtmp = (((l_w_idx_0 + l_w_idx_1) + (q_u[2] + xtmp)) + (q_u[3] + xtmp)) / 4.0;

  /*  l_b = l_s2; */
  phi = atan2(l_w_idx_1 - xtmp, l_w_idx_0 - xtmp);
  kappa_tmp = cos(phi);
  kappa = (xtmp - l_w_idx_0) / (xtmp * (par_mex->var[8] + par_mex->var[9]) / 2.0
    * kappa_tmp);

  /*  model inputs */
  /*  inner (introducer) tube lengths */
  /*  introducer load */
  memcpy(&b_varargin_1[0], &par_mex->user_pars.tip_load[0], 1710U * sizeof
         (double));
  for (offset = 0; offset < 4; offset++) {
    memcpy(&b_varargin_2[offset * 1710], &par_mex->user_pars.tip_load[offset *
           1710 + 1710], 1710U * sizeof(double));
  }

  if (par_mex->user_pars.tip_load[1] < par_mex->user_pars.tip_load[0]) {
    for (offset = 0; offset < 855; offset++) {
      xtmp = b_varargin_1[offset];
      b_varargin_1[offset] = b_varargin_1[1709 - offset];
      b_varargin_1[1709 - offset] = xtmp;
    }

    for (j = 0; j < 4; j++) {
      offset = j * 1710 + 1710;
      for (low_i = 0; low_i < 855; low_i++) {
        high_i = (offset + low_i) - 1710;
        xtmp = b_varargin_2[high_i];
        mid_i = (offset - low_i) - 1;
        b_varargin_2[high_i] = b_varargin_2[mid_i];
        b_varargin_2[mid_i] = xtmp;
      }
    }
  }

  l_w_idx_0 = 0.0;
  l_w_idx_1 = 0.0;
  l_w_idx_2 = 0.0;
  xtmp = 0.0;
  if ((t <= b_varargin_1[1709]) && (t >= b_varargin_1[0])) {
    low_i = 1;
    offset = 2;
    high_i = 1710;
    while (high_i > offset) {
      mid_i = (low_i + high_i) >> 1;
      if (t >= b_varargin_1[mid_i - 1]) {
        low_i = mid_i;
        offset = mid_i + 1;
      } else {
        high_i = mid_i;
      }
    }

    xtmp = b_varargin_1[low_i - 1];
    xtmp = (t - xtmp) / (b_varargin_1[low_i] - xtmp);
    if (xtmp == 0.0) {
      l_w_idx_0 = b_varargin_2[low_i - 1];
      l_w_idx_1 = b_varargin_2[low_i + 1709];
      l_w_idx_2 = b_varargin_2[low_i + 3419];
      xtmp = b_varargin_2[low_i + 5129];
    } else if (xtmp == 1.0) {
      l_w_idx_0 = b_varargin_2[low_i];
      l_w_idx_1 = b_varargin_2[low_i + 1710];
      l_w_idx_2 = b_varargin_2[low_i + 3420];
      xtmp = b_varargin_2[low_i + 5130];
    } else {
      b_y1 = b_varargin_2[low_i - 1];
      y2 = b_varargin_2[low_i];
      if (b_y1 == y2) {
        l_w_idx_0 = b_y1;
      } else {
        l_w_idx_0 = (1.0 - xtmp) * b_y1 + xtmp * y2;
      }

      b_y1 = b_varargin_2[low_i + 1709];
      y2 = b_varargin_2[low_i + 1710];
      if (b_y1 == y2) {
        l_w_idx_1 = b_y1;
      } else {
        l_w_idx_1 = (1.0 - xtmp) * b_y1 + xtmp * y2;
      }

      b_y1 = b_varargin_2[low_i + 3419];
      y2 = b_varargin_2[low_i + 3420];
      if (b_y1 == y2) {
        l_w_idx_2 = b_y1;
      } else {
        l_w_idx_2 = (1.0 - xtmp) * b_y1 + xtmp * y2;
      }

      b_y1 = b_varargin_2[low_i + 5129];
      y2 = b_varargin_2[low_i + 5130];
      if (b_y1 == y2) {
        xtmp = b_y1;
      } else {
        xtmp = (1.0 - xtmp) * b_y1 + xtmp * y2;
      }
    }
  }

  if (xtmp == 1.0) {
    /*  at introducer tip */
    xtmp = par_mex->var[15] + q_u[4];
  } else {
    /*  f_t(4) == 2, at catheter tip */
    xtmp = par_mex->var[16];
  }

  /*  update par */
  par_mex->var[17] = xtmp;
  par_mex->var[18] = q_u[4];
  par_mex->var[19] = kappa * sin(phi);
  par_mex->var[20] = kappa * kappa_tmp;
  par_mex->var[21] = l_w_idx_0;
  par_mex->var[22] = l_w_idx_1;
  par_mex->var[23] = l_w_idx_2;
}

/*
 * File trailer for dyn_mid_step.c
 *
 * [EOF]
 */
