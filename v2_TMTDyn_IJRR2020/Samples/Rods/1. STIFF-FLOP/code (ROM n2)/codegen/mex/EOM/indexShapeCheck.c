/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * indexShapeCheck.c
 *
 * Code generation for function 'indexShapeCheck'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "EOM.h"
#include "indexShapeCheck.h"

/* Variable Definitions */
static emlrtRSInfo l_emlrtRSI = { 18,  /* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"/* pathName */
};

static emlrtRTEInfo g_emlrtRTEI = { 88,/* lineNo */
  9,                                   /* colNo */
  "indexShapeCheck",                   /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"/* pName */
};

/* Function Definitions */
void indexShapeCheck(const emlrtStack *sp, int32_T matrixSize, const int32_T
                     indexSize[2])
{
  boolean_T b;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if (matrixSize == 1) {
    b = false;
    if (indexSize[1] != 1) {
      b = true;
    }

    if (b) {
      b = true;
    } else {
      b = false;
    }
  } else {
    b = false;
  }

  st.site = &l_emlrtRSI;
  if (b) {
    emlrtErrorWithMessageIdR2018a(&st, &g_emlrtRTEI,
      "Coder:FE:PotentialVectorVector", "Coder:FE:PotentialVectorVector", 0);
  }
}

/* End of code generation (indexShapeCheck.c) */
