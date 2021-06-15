/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EOM_eq_types.h
 *
 * Code generation for function 'EOM_eq'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef typedef_struct_T
#define typedef_struct_T

typedef struct {
  real_T p[4376];
  real_T tip_pos[4376];
  real_T tip_RQ[5470];
  real_T f_ex[7658];
  real_T n_l;
} struct_T;

#endif                                 /*typedef_struct_T*/

#ifndef typedef_b_struct_T
#define typedef_b_struct_T

typedef struct {
  real_T var[34];
  struct_T user_pars;
  real_T t_equil_i;
} b_struct_T;

#endif                                 /*typedef_b_struct_T*/

/* End of code generation (EOM_eq_types.h) */
