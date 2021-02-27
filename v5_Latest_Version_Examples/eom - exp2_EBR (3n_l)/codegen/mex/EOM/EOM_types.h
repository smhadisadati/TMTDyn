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
#ifndef typedef_struct1_T
#define typedef_struct1_T

typedef struct {
  real_T p[4376];
  real_T tip_pos[4376];
  real_T tip_RQ[5470];
  real_T f_ex[7658];
  real_T n_l;
} struct1_T;

#endif                                 /*typedef_struct1_T*/

#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
  real_T var[34];
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
