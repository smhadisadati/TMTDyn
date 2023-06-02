/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: EOM_types.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 08-May-2021 03:51:05
 */

#ifndef EOM_TYPES_H
#define EOM_TYPES_H

/* Include Files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_struct2_T
#define typedef_struct2_T

typedef struct {
  double pos[10242];
  double vel[10242];
  double acc[10242];
} struct2_T;

#endif                                 /*typedef_struct2_T*/

#ifndef typedef_struct3_T
#define typedef_struct3_T

typedef struct {
  double tube1[6828];
  double tube1_vel[6828];
  double tube1_acc[6828];
} struct3_T;

#endif                                 /*typedef_struct3_T*/

#ifndef typedef_struct1_T
#define typedef_struct1_T

typedef struct {
  double n_t;
  struct2_T motor_in;
  struct3_T tip_pos;
  double tip_load[8550];
} struct1_T;

#endif                                 /*typedef_struct1_T*/

#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
  struct1_T user_pars;
  double var[33];
  double t_equil_i;
} struct0_T;

#endif                                 /*typedef_struct0_T*/
#endif

/*
 * File trailer for EOM_types.h
 *
 * [EOF]
 */
