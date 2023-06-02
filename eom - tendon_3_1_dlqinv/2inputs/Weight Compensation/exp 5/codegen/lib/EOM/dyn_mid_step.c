/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: dyn_mid_step.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 08-May-2021 01:57:20
 */

/* Include Files */
#include "dyn_mid_step.h"
#include "EOM_types.h"
#include "interp1.h"
#include <string.h>

/* Function Definitions */
/*
 * tendon dicplacements
 * Arguments    : double t
 *                struct0_T *par_mex
 * Return Type  : void
 */
void dyn_mid_step(double t, struct0_T *par_mex)
{
  static double varargin_2[72935];
  static double b_varargin_2[58348];
  static double varargin_1[14587];
  double q_u[5];
  double dq_d[3];
  double q_d[3];
  double unusedExpr[3];
  double b_y1;
  double f_t_idx_0;
  double f_t_idx_1;
  double f_t_idx_2;
  double pid_idx_0;
  double pid_idx_2;
  double xtmp;
  double y2;
  int high_i;
  int j;
  int low_i;
  int mid_i;
  int offset;
  memcpy(&varargin_1[0], &par_mex->user_pars.motor_in.pos[0], 14587U * sizeof
         (double));
  for (offset = 0; offset < 5; offset++) {
    memcpy(&varargin_2[offset * 14587], &par_mex->user_pars.motor_in.pos[offset *
           14587 + 14587], 14587U * sizeof(double));
  }

  if (par_mex->user_pars.motor_in.pos[1] < par_mex->user_pars.motor_in.pos[0]) {
    for (offset = 0; offset < 7293; offset++) {
      xtmp = varargin_1[offset];
      varargin_1[offset] = varargin_1[14586 - offset];
      varargin_1[14586 - offset] = xtmp;
    }

    for (j = 0; j < 5; j++) {
      offset = j * 14587 + 14587;
      for (low_i = 0; low_i < 7293; low_i++) {
        high_i = (offset + low_i) - 14587;
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

  if ((t <= varargin_1[14586]) && (t >= varargin_1[0])) {
    low_i = 1;
    offset = 2;
    high_i = 14587;
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
        q_u[j] = varargin_2[(low_i + j * 14587) - 1];
      }
    } else if (xtmp == 1.0) {
      for (j = 0; j < 5; j++) {
        q_u[j] = varargin_2[low_i + j * 14587];
      }
    } else {
      for (j = 0; j < 5; j++) {
        offset = low_i + j * 14587;
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
  /*  d_ow = par_mex.var(9) + par_mex.var(10) ; % wire offsets diameter: 2*(r_s21+r_s22)/2 */
  /*  l_s2 = par_mex.var(28); */
  /*  l_w = q_u(1:4) + l_s2;  */
  /*  % % 3 tendons */
  /*  % kappa = 2*sqrt(l(1)^2+l(2)^2+l(3)^2-l(1)*l(2)-l(1)*l(3)-l(2)*l(3))/(d*(l(1)+l(2)+l(3))); */
  /*  % phi = atan2(sqrt(3)*(l(2)+l(3)-2*l(1)),(3*(l(2)-l(3)))); */
  /*  % 4 tendons */
  /*  l_b = ( l_w(1) + l_w(2) + l_w(3) + l_w(4) ) / 4; */
  /*  phi = atan2(l_w(2)-l_b,l_w(1)-l_b); */
  /*  kappa = ( l_b - l_w(1) ) / ( l_b * d_ow/2 * cos(phi) ) ; */
  /*  % model inputs */
  /*  kappa_x = kappa * sin( phi ); */
  /*  kappa_y = kappa * cos( phi ); */
  /*   */
  /*  par_mex.U = [ kappa_x kappa_y ] ; */
  /*  inner (introducer) tube lengths */
  /*  tip positions */
  interp1(*(double (*)[14584])&par_mex->user_pars.tip_pos.tube1[0], *(double (*)
           [43752])&par_mex->user_pars.tip_pos.tube1[14584], t, q_d);
  interp1(*(double (*)[14584])&par_mex->user_pars.tip_pos.tube1_vel[0], *(double
           (*)[43752])&par_mex->user_pars.tip_pos.tube1_vel[14584], t, dq_d);
  interp1(*(double (*)[14584])&par_mex->user_pars.tip_pos.tube1_acc[0], *(double
           (*)[43752])&par_mex->user_pars.tip_pos.tube1_acc[14584], t,
          unusedExpr);

  /*  tip pos. desired position */
  pid_idx_0 = par_mex->var[30];
  pid_idx_2 = par_mex->var[32];

  /*  PD controller */
  /*  introducer load */
  memcpy(&varargin_1[0], &par_mex->user_pars.tip_load[0], 14587U * sizeof(double));
  for (offset = 0; offset < 4; offset++) {
    memcpy(&b_varargin_2[offset * 14587], &par_mex->user_pars.tip_load[offset *
           14587 + 14587], 14587U * sizeof(double));
  }

  if (par_mex->user_pars.tip_load[1] < par_mex->user_pars.tip_load[0]) {
    for (offset = 0; offset < 7293; offset++) {
      xtmp = varargin_1[offset];
      varargin_1[offset] = varargin_1[14586 - offset];
      varargin_1[14586 - offset] = xtmp;
    }

    for (j = 0; j < 4; j++) {
      offset = j * 14587 + 14587;
      for (low_i = 0; low_i < 7293; low_i++) {
        high_i = (offset + low_i) - 14587;
        xtmp = b_varargin_2[high_i];
        mid_i = (offset - low_i) - 1;
        b_varargin_2[high_i] = b_varargin_2[mid_i];
        b_varargin_2[mid_i] = xtmp;
      }
    }
  }

  f_t_idx_0 = 0.0;
  f_t_idx_1 = 0.0;
  f_t_idx_2 = 0.0;
  xtmp = 0.0;
  if ((t <= varargin_1[14586]) && (t >= varargin_1[0])) {
    low_i = 1;
    offset = 2;
    high_i = 14587;
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
      f_t_idx_0 = b_varargin_2[low_i - 1];
      f_t_idx_1 = b_varargin_2[low_i + 14586];
      f_t_idx_2 = b_varargin_2[low_i + 29173];
      xtmp = b_varargin_2[low_i + 43760];
    } else if (xtmp == 1.0) {
      f_t_idx_0 = b_varargin_2[low_i];
      f_t_idx_1 = b_varargin_2[low_i + 14587];
      f_t_idx_2 = b_varargin_2[low_i + 29174];
      xtmp = b_varargin_2[low_i + 43761];
    } else {
      b_y1 = b_varargin_2[low_i - 1];
      y2 = b_varargin_2[low_i];
      if (b_y1 == y2) {
        f_t_idx_0 = b_y1;
      } else {
        f_t_idx_0 = (1.0 - xtmp) * b_y1 + xtmp * y2;
      }

      b_y1 = b_varargin_2[low_i + 14586];
      y2 = b_varargin_2[low_i + 14587];
      if (b_y1 == y2) {
        f_t_idx_1 = b_y1;
      } else {
        f_t_idx_1 = (1.0 - xtmp) * b_y1 + xtmp * y2;
      }

      b_y1 = b_varargin_2[low_i + 29173];
      y2 = b_varargin_2[low_i + 29174];
      if (b_y1 == y2) {
        f_t_idx_2 = b_y1;
      } else {
        f_t_idx_2 = (1.0 - xtmp) * b_y1 + xtmp * y2;
      }

      b_y1 = b_varargin_2[low_i + 43760];
      y2 = b_varargin_2[low_i + 43761];
      if (b_y1 == y2) {
        xtmp = b_y1;
      } else {
        xtmp = (1.0 - xtmp) * b_y1 + xtmp * y2;
      }
    }
  }

  if (xtmp == 1.0) {
    /*  at introducer tip */
    par_mex->var[17] = par_mex->var[15] + q_u[4];
  } else {
    /*  f_t(4) == 2, at catheter tip */
    par_mex->var[17] = par_mex->var[16];
  }

  /*  update par */
  par_mex->var[18] = q_u[4];
  par_mex->var[21] = f_t_idx_0;
  par_mex->var[27] = pid_idx_0 * q_d[0] + pid_idx_2 * dq_d[0];
  par_mex->var[22] = f_t_idx_1;
  par_mex->var[28] = pid_idx_0 * q_d[1] + pid_idx_2 * dq_d[1];
  par_mex->var[23] = f_t_idx_2;
  par_mex->var[29] = pid_idx_0 * q_d[2] + pid_idx_2 * dq_d[2];
}

/*
 * File trailer for dyn_mid_step.c
 *
 * [EOF]
 */
