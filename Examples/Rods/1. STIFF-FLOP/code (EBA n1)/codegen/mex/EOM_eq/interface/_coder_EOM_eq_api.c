/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_EOM_eq_api.c
 *
 * Code generation for function '_coder_EOM_eq_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "EOM_eq.h"
#include "_coder_EOM_eq_api.h"
#include "EOM_eq_mexutil.h"
#include "EOM_eq_data.h"

/* Function Declarations */
static const mxArray *d_emlrt_marshallOut(const real_T u[6]);
static real_T (*gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[6];
static real_T (*q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *z, const
  char_T *identifier))[6];
static real_T (*r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[6];

/* Function Definitions */
static const mxArray *d_emlrt_marshallOut(const real_T u[6])
{
  const mxArray *y;
  const mxArray *m39;
  static const int32_T iv12[1] = { 0 };

  static const int32_T iv13[1] = { 6 };

  y = NULL;
  m39 = emlrtCreateNumericArray(1, iv12, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m39, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m39, iv13, 1);
  emlrtAssign(&y, m39);
  return y;
}

static real_T (*gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[6]
{
  real_T (*ret)[6];
  static const int32_T dims[2] = { 1, 6 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[6])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static real_T (*q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *z,
  const char_T *identifier))[6]
{
  real_T (*y)[6];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = r_emlrt_marshallIn(sp, emlrtAlias(z), &thisId);
  emlrtDestroyArray(&z);
  return y;
}

static real_T (*r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[6]
{
  real_T (*y)[6];
  y = gb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  void EOM_eq_api(const mxArray * const prhs[1], int32_T nlhs, const mxArray
                  *plhs[1])
{
  real_T (*fval)[6];
  real_T (*z)[6];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;
  fval = (real_T (*)[6])mxMalloc(sizeof(real_T [6]));

  /* Marshall function inputs */
  z = q_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "z");

  /* Marshall in global variables */
  MEXGlobalSyncInFunction(&st);

  /* Invoke the target function */
  EOM_eq(&st, *z, *fval);

  /* Marshall out global variables */
  MEXGlobalSyncOutFunction(true);

  /* Marshall function outputs */
  plhs[0] = d_emlrt_marshallOut(*fval);
}

/* End of code generation (_coder_EOM_eq_api.c) */
