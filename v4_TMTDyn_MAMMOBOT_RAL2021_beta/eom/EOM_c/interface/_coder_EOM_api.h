/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_EOM_api.h
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 14-Oct-2020 16:42:47
 */

#ifndef _CODER_EOM_API_H
#define _CODER_EOM_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_EOM_api.h"

/* Type Definitions */
#ifndef typedef_struct2_T
#define typedef_struct2_T

typedef struct {
  real_T pos[259];
} struct2_T;

#endif                                 /*typedef_struct2_T*/

#ifndef typedef_struct3_T
#define typedef_struct3_T

typedef struct {
  real_T tube2[148];
} struct3_T;

#endif                                 /*typedef_struct3_T*/

#ifndef typedef_struct1_T
#define typedef_struct1_T

typedef struct {
  real_T n_t;
  struct2_T motor_in;
  struct3_T tip_pos;
} struct1_T;

#endif                                 /*typedef_struct1_T*/

#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
  struct1_T user_pars;
  real_T var[58];
  real_T t_equil_i;
} struct0_T;

#endif                                 /*typedef_struct0_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void EOM(real_T t, real_T z[64], struct0_T *par_mex, real_T dz[64],
                real_T *flag);
extern void EOM_api(const mxArray * const prhs[3], int32_T nlhs, const mxArray
                    *plhs[3]);
extern void EOM_atexit(void);
extern void EOM_initialize(void);
extern void EOM_input(real_T tspan[3], real_T *nz, real_T z0[64], struct0_T
                      *par_mex);
extern void EOM_input_api(int32_T nlhs, const mxArray *plhs[4]);
extern void EOM_terminate(void);
extern void EOM_xil_shutdown(void);
extern void EOM_xil_terminate(void);

#endif

/*
 * File trailer for _coder_EOM_api.h
 *
 * [EOF]
 */
