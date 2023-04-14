/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: dyn_mid_step.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 14-Oct-2020 16:42:47
 */

/* Include Files */
#include <string.h>
#include "EOM.h"
#include "EOM_input.h"
#include "dyn_mid_step.h"

/* Function Definitions */

/*
 * inputs
 *  % accelaration
 *  ddq = 1 * interp1(par_mex.user_pars.motor_in.acc(:,1), par_mex.user_pars.motor_in.acc(:,2:end), t, 'nearest');
 *  % [t ddq]
 *
 *  % % PID
 *  % C = [1 1 0.1]; % P-I-D coeff
 *  % pos = interp1(par_mex.user_pars.motor_in.pos(:,1), par_mex.user_pars.motor_in.pos(:,2:end), t);
 *  % vel = interp1(par_mex.user_pars.motor_in.vel(:,1), par_mex.user_pars.motor_in.vel(:,2:end), t);
 *  % ddq = C(1) * ( pos - z([1, 2, i2, i2+1])' ) ... % P
 *  %     + C(3) * ( vel - z(end/2+[1, 2, i2, i2+1])' ); % D
 *
 *  ftau_u = ddq ; % motor_acc
 * Arguments    : double t
 *                struct0_T *par_mex
 * Return Type  : void
 */
void dyn_mid_step(double t, struct0_T *par_mex)
{
  double varargin_1[37];
  int offset;
  double varargin_2[222];
  int j;
  double xtmp;
  double q_u[6];
  int low_i;
  int high_i;
  int mid_i;
  double b_y1;
  double b_par_mex;
  double ftau_ex[6];
  static const signed char b[6] = { 1, 0, -1, 0, 0, 0 };

  /*  positions */
  memcpy(&varargin_1[0], &par_mex->user_pars.motor_in.pos[0], 37U * sizeof
         (double));
  for (offset = 0; offset < 6; offset++) {
    memcpy(&varargin_2[offset * 37], &par_mex->user_pars.motor_in.pos[offset *
           37 + 37], 37U * sizeof(double));
  }

  if (par_mex->user_pars.motor_in.pos[1] < par_mex->user_pars.motor_in.pos[0]) {
    for (offset = 0; offset < 18; offset++) {
      xtmp = varargin_1[offset];
      varargin_1[offset] = varargin_1[36 - offset];
      varargin_1[36 - offset] = xtmp;
    }

    for (j = 0; j < 6; j++) {
      offset = j * 37 + 37;
      for (high_i = 0; high_i < 18; high_i++) {
        mid_i = (offset + high_i) - 37;
        xtmp = varargin_2[mid_i];
        low_i = (offset - high_i) - 1;
        varargin_2[mid_i] = varargin_2[low_i];
        varargin_2[low_i] = xtmp;
      }
    }
  }

  for (offset = 0; offset < 6; offset++) {
    q_u[offset] = 0.0;
  }

  if ((t <= varargin_1[36]) && (t >= varargin_1[0])) {
    low_i = 1;
    offset = 2;
    high_i = 37;
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
        q_u[j] = varargin_2[(low_i + j * 37) - 1];
      }
    } else if (xtmp == 1.0) {
      for (j = 0; j < 6; j++) {
        q_u[j] = varargin_2[low_i + j * 37];
      }
    } else {
      for (j = 0; j < 6; j++) {
        offset = low_i + j * 37;
        b_y1 = varargin_2[offset - 1];
        if (b_y1 == varargin_2[offset]) {
          q_u[j] = b_y1;
        } else {
          q_u[j] = (1.0 - xtmp) * b_y1 + xtmp * varargin_2[offset];
        }
      }
    }
  }

  /*  ftau_u = q_u ; % motor_in */
  /*  catheter kappa_y (I used dl2 as kappa) */
  q_u[5] *= par_mex->var[43];

  /*  spline segmentation */
  /*  physical bent length */
  xtmp = (par_mex->var[39] + q_u[0]) - par_mex->var[41];
  if (xtmp < 0.0) {
    xtmp = 5.0E-3;
  }

  /*  preventing IC from being cancelled out! */
  /*  external forces (I used dl3 as f) */
  b_y1 = par_mex->var[39] + q_u[4];
  if (q_u[4] > 0.0) {
    b_par_mex = par_mex->var[44];
    for (offset = 0; offset < 6; offset++) {
      ftau_ex[offset] = b_par_mex * (double)b[offset];
    }

    /*  load */
  } else {
    for (offset = 0; offset < 6; offset++) {
      ftau_ex[offset] = 0.0;
    }

    /*  load */
  }

  q_u[4] = 0.0;

  /*  update par */
  par_mex->var[42] = xtmp;
  par_mex->var[43] = 0.0;
  par_mex->var[44] = 0.0;
  for (offset = 0; offset < 6; offset++) {
    par_mex->var[offset + 45] = q_u[offset];
    par_mex->var[offset + 51] = ftau_ex[offset];
  }

  par_mex->var[57] = b_y1;
}

/*
 * File trailer for dyn_mid_step.c
 *
 * [EOF]
 */
