/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * massF3.h
 *
 * Code generation for function 'massF3'
 *
 */

#ifndef MASSF3_H
#define MASSF3_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "EOM_types.h"

/* Function Declarations */
extern void massF3(const real_T in1[34], const real_T in2[24], real_T out1[36],
                   real_T out2[72], real_T out3[72], real_T out4[6]);

#endif

/* End of code generation (massF3.h) */
