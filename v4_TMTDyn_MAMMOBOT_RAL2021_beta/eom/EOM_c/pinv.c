/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: pinv.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 14-Oct-2020 16:42:47
 */

/* Include Files */
#include <string.h>
#include "EOM.h"
#include "EOM_input.h"
#include "pinv.h"
#include "xgemm.h"
#include "eps.h"
#include "svd.h"

/* Function Definitions */

/*
 * Arguments    : const double A[1024]
 *                double X[1024]
 * Return Type  : void
 */
void pinv(const double A[1024], double X[1024])
{
  double U[1024];
  double s[32];
  double V[1024];
  double tol;
  int r;
  int k;
  int vcol;
  int j;
  int i4;
  memset(&X[0], 0, sizeof(double) << 10);
  svd(A, U, s, V);
  tol = 32.0 * eps(s[0]);
  r = 0;
  k = 0;
  while ((k < 32) && (s[k] > tol)) {
    r++;
    k++;
  }

  if (r > 0) {
    vcol = 1;
    for (j = 0; j < r; j++) {
      tol = 1.0 / s[j];
      i4 = vcol + 31;
      for (k = vcol; k <= i4; k++) {
        V[k - 1] *= tol;
      }

      vcol += 32;
    }

    xgemm(r, V, U, X);
  }
}

/*
 * File trailer for pinv.c
 *
 * [EOF]
 */
