/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: dyn_mid_step.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 10-Mar-2021 22:46:32
 */

/* Include Files */
#include "dyn_mid_step.h"
#include "EOM_types.h"
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
  double varargin_2[2244];
  double varargin_1[374];
  double q_u[6];
  double b_y1;
  double xtmp;
  double y2;
  int high_i;
  int j;
  int low_i;
  int mid_i;
  int offset;
  memcpy(&varargin_1[0], &par_mex->user_pars.motor_in.pos[0], 374U * sizeof
         (double));
  for (offset = 0; offset < 6; offset++) {
    memcpy(&varargin_2[offset * 374], &par_mex->user_pars.motor_in.pos[offset *
           374 + 374], 374U * sizeof(double));
  }

  if (par_mex->user_pars.motor_in.pos[1] < par_mex->user_pars.motor_in.pos[0]) {
    for (offset = 0; offset < 187; offset++) {
      xtmp = varargin_1[offset];
      varargin_1[offset] = varargin_1[373 - offset];
      varargin_1[373 - offset] = xtmp;
    }

    for (j = 0; j < 6; j++) {
      offset = j * 374 + 374;
      for (low_i = 0; low_i < 187; low_i++) {
        high_i = (offset + low_i) - 374;
        xtmp = varargin_2[high_i];
        mid_i = (offset - low_i) - 1;
        varargin_2[high_i] = varargin_2[mid_i];
        varargin_2[mid_i] = xtmp;
      }
    }
  }

  for (offset = 0; offset < 6; offset++) {
    q_u[offset] = 0.0;
  }

  if ((t <= varargin_1[373]) && (t >= varargin_1[0])) {
    low_i = 1;
    offset = 2;
    high_i = 374;
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
        q_u[j] = varargin_2[(low_i + j * 374) - 1];
      }
    } else if (xtmp == 1.0) {
      for (j = 0; j < 6; j++) {
        q_u[j] = varargin_2[low_i + j * 374];
      }
    } else {
      for (j = 0; j < 6; j++) {
        offset = low_i + j * 374;
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

  /*  straight part overlapping */
  /*  relaxed state base (straight section) length */
  xtmp = (0.20800000000000002 - par_mex->var[36]) + q_u[2];

  /*  external forces */
  /*  ftau_ex = [ 0 0 0 0 0 0 ] ; % tip load */
  /*  update par */
  /*  par_mex.var(end-11:end) = [ ftau_u ftau_ex ] ; */
  par_mex->var[45] = 0.0;
  if (xtmp < 0.001) {
    par_mex->var[46] = 0.001;
  } else {
    par_mex->var[46] = xtmp;
  }

  par_mex->var[47] = 0.0;
  for (offset = 0; offset < 6; offset++) {
    par_mex->var[offset + 48] = q_u[offset];
  }
}

/*
 * File trailer for dyn_mid_step.c
 *
 * [EOF]
 */
