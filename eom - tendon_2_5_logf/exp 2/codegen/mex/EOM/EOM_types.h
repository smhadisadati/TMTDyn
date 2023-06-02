/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EOM_types.h
 *
 * Code generation for function 'EOM'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef typedef_struct2_T
#define typedef_struct2_T

typedef struct {
  real_T pos[10242];
  real_T vel[10242];
  real_T acc[10242];
} struct2_T;

#endif                                 /*typedef_struct2_T*/

#ifndef typedef_struct3_T
#define typedef_struct3_T

typedef struct {
  real_T tube1[6828];
  real_T tube1_vel[6828];
  real_T tube1_acc[6828];
} struct3_T;

#endif                                 /*typedef_struct3_T*/

#ifndef typedef_struct1_T
#define typedef_struct1_T

typedef struct {
  real_T n_t;
  struct2_T motor_in;
  struct3_T tip_pos;
  real_T tip_load[6840];
} struct1_T;

#endif                                 /*typedef_struct1_T*/

#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
  real_T var[27];
  struct1_T user_pars;
  real_T t_equil_i;
} struct0_T;

#endif                                 /*typedef_struct0_T*/

#ifndef typedef_EOMStackData
#define typedef_EOMStackData

typedef struct {
  struct {
    struct0_T par_mex;
  } f0;
} EOMStackData;

#endif                                 /*typedef_EOMStackData*/

/* End of code generation (EOM_types.h) */
