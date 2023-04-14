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

#ifndef EOM_EQ_TYPES_H
#define EOM_EQ_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_struct_T
#define typedef_struct_T

typedef struct {
  real_T mass[2];
  real_T sprdmp[19];
} struct_T;

#endif                                 /*typedef_struct_T*/

#ifndef typedef_b_struct_T
#define typedef_b_struct_T

typedef struct {
  uint64_T timer;
  real_T elapsed_time[4];
  real_T derive;
  real_T derive_collect;
  real_T derive_mex;
  boolean_T opv;
  real_T Anim;
  real_T movie;
  real_T equil;
  real_T modal;
  real_T simdyn;
  real_T t_rep;
  real_T n_int;
  real_T n_animpoints;
  real_T n_datasample;
  real_T var[34];
  real_T p[4376];
  real_T f_ex[7658];
  real_T tip_exp[4376];
  real_T tip_RQ[5470];
  real_T t_exp[9];
  real_T t_exp_equil[9];
  real_T t_init;
  real_T t_final;
  real_T t_equil[9];
  real_T dt;
  real_T stepT;
  real_T skip;
  real_T animPause;
  real_T pause;
  real_T t_equil_i;
  real_T nq;
  real_T nlambda;
  real_T qf0[18];
  real_T n_m;
  real_T n_sd;
  real_T n_cn;
  real_T n_ex;
  struct_T rom;
} b_struct_T;

#endif                                 /*typedef_b_struct_T*/
#endif

/* End of code generation (EOM_eq_types.h) */
