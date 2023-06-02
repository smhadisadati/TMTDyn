/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_EOM_mex.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 30-Apr-2021 22:01:01
 */

#ifndef _CODER_EOM_MEX_H
#define _CODER_EOM_MEX_H

/* Include Files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  void EOM_input_mexFunction(int32_T nlhs, mxArray *plhs[4], int32_T nrhs);
  void EOM_mexFunction(int32_T nlhs, mxArray *plhs[3], int32_T nrhs, const
                       mxArray *prhs[3]);
  MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T
    nrhs, const mxArray *prhs[]);
  emlrtCTX mexFunctionCreateRootTLS(void);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for _coder_EOM_mex.h
 *
 * [EOF]
 */
