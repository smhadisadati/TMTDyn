/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mtimes.h
 *
 * Code generation for function 'mtimes'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void b_mtimes(const real_T A[144], const real_T B[144], real_T C[576]);
void c_mtimes(const real_T A[576], const real_T B[24], real_T C[24]);
void mtimes(const real_T A[144], const real_T B[36], real_T C[144]);

/* End of code generation (mtimes.h) */
