/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: dyn_mid_step.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 30-Apr-2021 21:54:05
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
  static double varargin_2[18105];
  double b_varargin_2[14484];
  double varargin_1[3621];
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
  memcpy(&varargin_1[0], &par_mex->user_pars.motor_in.pos[0], 3621U * sizeof
         (double));
  for (offset = 0; offset < 5; offset++) {
    memcpy(&varargin_2[offset * 3621], &par_mex->user_pars.motor_in.pos[offset *
           3621 + 3621], 3621U * sizeof(double));
  }

  if (par_mex->user_pars.motor_in.pos[1] < par_mex->user_pars.motor_in.pos[0]) {
    for (offset = 0; offset < 1810; offset++) {
      xtmp = varargin_1[offset];
      varargin_1[offset] = varargin_1[3620 - offset];
      varargin_1[3620 - offset] = xtmp;
    }

    for (j = 0; j < 5; j++) {
      offset = j * 3621 + 3621;
      for (low_i = 0; low_i < 1810; low_i++) {
        high_i = (offset + low_i) - 3621;
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

  if ((t <= varargin_1[3620]) && (t >= varargin_1[0])) {
    low_i = 1;
    offset = 2;
    high_i = 3621;
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
        q_u[j] = varargin_2[(low_i + j * 3621) - 1];
      }
    } else if (xtmp == 1.0) {
      for (j = 0; j < 5; j++) {
        q_u[j] = varargin_2[low_i + j * 3621];
      }
    } else {
      for (j = 0; j < 5; j++) {
        offset = low_i + j * 3621;
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
  l_w_idx_0 = q_u[0] / 2.0 + xtmp;
  l_w_idx_1 = q_u[1] / 2.0 + xtmp;

  /*  /2 because of tendon pair  */
  /*  % 3 tendons */
  /*  kappa = 2*sqrt(l(1)^2+l(2)^2+l(3)^2-l(1)*l(2)-l(1)*l(3)-l(2)*l(3))/(d*(l(1)+l(2)+l(3))); */
  /*  phi = atan2(sqrt(3)*(l(2)+l(3)-2*l(1)),(3*(l(2)-l(3)))); */
  /*  4 tendons */
  xtmp = (((l_w_idx_0 + l_w_idx_1) + (q_u[2] / 2.0 + xtmp)) + (q_u[3] / 2.0 +
           xtmp)) / 4.0;

  /*  l_b = l_s2; */
  phi = atan2(l_w_idx_1 - xtmp, l_w_idx_0 - xtmp);
  kappa_tmp = cos(phi);
  kappa = (xtmp - l_w_idx_0) / (xtmp * (par_mex->var[8] + par_mex->var[9]) / 2.0
    * kappa_tmp);

  /*  model inputs */
  /*  inner (introducer) tube lengths */
  /*  introducer load */
  memcpy(&varargin_1[0], &par_mex->user_pars.tip_load[0], 3621U * sizeof(double));
  for (offset = 0; offset < 4; offset++) {
    memcpy(&b_varargin_2[offset * 3621], &par_mex->user_pars.tip_load[offset *
           3621 + 3621], 3621U * sizeof(double));
  }

  if (par_mex->user_pars.tip_load[1] < par_mex->user_pars.tip_load[0]) {
    for (offset = 0; offset < 1810; offset++) {
      xtmp = varargin_1[offset];
      varargin_1[offset] = varargin_1[3620 - offset];
      varargin_1[3620 - offset] = xtmp;
    }

    for (j = 0; j < 4; j++) {
      offset = j * 3621 + 3621;
      for (low_i = 0; low_i < 1810; low_i++) {
        high_i = (offset + low_i) - 3621;
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
  if ((t <= varargin_1[3620]) && (t >= varargin_1[0])) {
    low_i = 1;
    offset = 2;
    high_i = 3621;
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
      l_w_idx_0 = b_varargin_2[low_i - 1];
      l_w_idx_1 = b_varargin_2[low_i + 3620];
      l_w_idx_2 = b_varargin_2[low_i + 7241];
      xtmp = b_varargin_2[low_i + 10862];
    } else if (xtmp == 1.0) {
      l_w_idx_0 = b_varargin_2[low_i];
      l_w_idx_1 = b_varargin_2[low_i + 3621];
      l_w_idx_2 = b_varargin_2[low_i + 7242];
      xtmp = b_varargin_2[low_i + 10863];
    } else {
      b_y1 = b_varargin_2[low_i - 1];
      y2 = b_varargin_2[low_i];
      if (b_y1 == y2) {
        l_w_idx_0 = b_y1;
      } else {
        l_w_idx_0 = (1.0 - xtmp) * b_y1 + xtmp * y2;
      }

      b_y1 = b_varargin_2[low_i + 3620];
      y2 = b_varargin_2[low_i + 3621];
      if (b_y1 == y2) {
        l_w_idx_1 = b_y1;
      } else {
        l_w_idx_1 = (1.0 - xtmp) * b_y1 + xtmp * y2;
      }

      b_y1 = b_varargin_2[low_i + 7241];
      y2 = b_varargin_2[low_i + 7242];
      if (b_y1 == y2) {
        l_w_idx_2 = b_y1;
      } else {
        l_w_idx_2 = (1.0 - xtmp) * b_y1 + xtmp * y2;
      }

      b_y1 = b_varargin_2[low_i + 10862];
      y2 = b_varargin_2[low_i + 10863];
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
