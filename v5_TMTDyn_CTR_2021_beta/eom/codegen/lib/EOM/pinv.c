/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: pinv.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 10-Mar-2021 22:46:32
 */

/* Include Files */
#include "pinv.h"
#include "svd.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double A[576]
 *                double X[576]
 * Return Type  : void
 */
void pinv(const double A[576], double X[576])
{
  double U[576];
  double V[576];
  double s[24];
  double absx;
  int ar;
  int br;
  int exponent;
  int i;
  int i1;
  int ia;
  int ib;
  int ic;
  int r;
  int vcol;
  memset(&X[0], 0, 576U * sizeof(double));
  svd(A, U, s, V);
  absx = fabs(s[0]);
  if (absx <= 2.2250738585072014E-308) {
    absx = 4.94065645841247E-324;
  } else {
    frexp(absx, &exponent);
    absx = ldexp(1.0, exponent - 53);
  }

  absx *= 24.0;
  r = -1;
  exponent = 0;
  while ((exponent < 24) && (s[exponent] > absx)) {
    r++;
    exponent++;
  }

  if (r + 1 > 0) {
    vcol = 1;
    for (br = 0; br <= r; br++) {
      absx = 1.0 / s[br];
      i = vcol + 23;
      for (exponent = vcol; exponent <= i; exponent++) {
        V[exponent - 1] *= absx;
      }

      vcol += 24;
    }

    for (exponent = 0; exponent <= 552; exponent += 24) {
      i = exponent + 1;
      vcol = exponent + 24;
      if (i <= vcol) {
        memset(&X[i + -1], 0, ((vcol - i) + 1) * sizeof(double));
      }
    }

    br = 0;
    for (exponent = 0; exponent <= 552; exponent += 24) {
      ar = -1;
      br++;
      i = br + 24 * r;
      for (ib = br; ib <= i; ib += 24) {
        ia = ar;
        vcol = exponent + 1;
        i1 = exponent + 24;
        for (ic = vcol; ic <= i1; ic++) {
          ia++;
          X[ic - 1] += U[ib - 1] * V[ia];
        }

        ar += 24;
      }
    }
  }
}

/*
 * File trailer for pinv.c
 *
 * [EOF]
 */
