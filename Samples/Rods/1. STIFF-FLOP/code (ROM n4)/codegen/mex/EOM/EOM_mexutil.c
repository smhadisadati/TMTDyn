/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EOM_mexutil.c
 *
 * Code generation for function 'EOM_mexutil'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "EOM.h"
#include "EOM_mexutil.h"
#include "EOM_data.h"

/* Function Declarations */
static real_T u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);

/* Function Definitions */
static real_T u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void MEXGlobalSyncInFunction(const emlrtStack *sp)
{
  const mxArray *tmp;

  /* Marshall in global variables */
  tmp = emlrtGetGlobalVariable("t_report");
  if (tmp != NULL) {
    t_report = emlrt_marshallIn(sp, tmp, "t_report");
    t_report_dirty = 0U;
  }
}

void MEXGlobalSyncOutFunction(boolean_T skipDirtyCheck)
{
  /* Marshall out global variables */
  if (skipDirtyCheck || (t_report_dirty != 0U)) {
    emlrtPutGlobalVariable("t_report", emlrt_marshallOut(t_report));
  }
}

real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = u_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

void emlrt_checkEscapedGlobals(void)
{
  t_report_dirty |= t_report_dirty >> 1U;
}

real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *c_t_report, const
  char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(c_t_report), &thisId);
  emlrtDestroyArray(&c_t_report);
  return y;
}

const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *y;
  const mxArray *m7;
  y = NULL;
  m7 = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m7);
  return y;
}

void emlrt_synchGlobalsFromML(const emlrtStack *sp)
{
  MEXGlobalSyncInFunction(sp);
  t_report_dirty = 0U;
}

void emlrt_synchGlobalsToML(const emlrtStack *sp)
{
  (void)sp;
  MEXGlobalSyncOutFunction(false);
}

/* End of code generation (EOM_mexutil.c) */
