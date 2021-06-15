/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xtrsm.c
 *
 * Code generation for function 'xtrsm'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "EOM.h"
#include "xtrsm.h"
#include "EOM_mexutil.h"
#include "blas.h"

/* Function Definitions */
void b_xtrsm(const real_T A[576], real_T B[24])
{
  real_T alpha1;
  char_T DIAGA1;
  char_T TRANSA1;
  char_T UPLO1;
  char_T SIDE1;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  alpha1 = 1.0;
  DIAGA1 = 'N';
  TRANSA1 = 'N';
  UPLO1 = 'U';
  SIDE1 = 'L';
  m_t = (ptrdiff_t)24;
  n_t = (ptrdiff_t)1;
  lda_t = (ptrdiff_t)24;
  ldb_t = (ptrdiff_t)24;
  emlrt_checkEscapedGlobals();
  dtrsm(&SIDE1, &UPLO1, &TRANSA1, &DIAGA1, &m_t, &n_t, &alpha1, &A[0], &lda_t,
        &B[0], &ldb_t);
}

void xtrsm(const real_T A[576], real_T B[24])
{
  real_T alpha1;
  char_T DIAGA1;
  char_T TRANSA1;
  char_T UPLO1;
  char_T SIDE1;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  alpha1 = 1.0;
  DIAGA1 = 'U';
  TRANSA1 = 'N';
  UPLO1 = 'L';
  SIDE1 = 'L';
  m_t = (ptrdiff_t)24;
  n_t = (ptrdiff_t)1;
  lda_t = (ptrdiff_t)24;
  ldb_t = (ptrdiff_t)24;
  emlrt_checkEscapedGlobals();
  dtrsm(&SIDE1, &UPLO1, &TRANSA1, &DIAGA1, &m_t, &n_t, &alpha1, &A[0], &lda_t,
        &B[0], &ldb_t);
}

/* End of code generation (xtrsm.c) */
