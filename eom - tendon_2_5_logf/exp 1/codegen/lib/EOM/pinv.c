/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: pinv.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 06-Apr-2021 13:11:18
 */

/* Include Files */
#include "pinv.h"
#include "svd.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double A[289]
 *                double X[289]
 * Return Type  : void
 */
void pinv(const double A[289], double X[289])
{
  double U[289];
  double V[289];
  double s[17];
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
  memset(&X[0], 0, 289U * sizeof(double));
  svd(A, U, s, V);
  absx = fabs(s[0]);
  if (absx <= 2.2250738585072014E-308) {
    absx = 4.94065645841247E-324;
  } else {
    frexp(absx, &exponent);
    absx = ldexp(1.0, exponent - 53);
  }

  absx *= 17.0;
  r = -1;
  exponent = 0;
  while ((exponent < 17) && (s[exponent] > absx)) {
    r++;
    exponent++;
  }

  if (r + 1 > 0) {
    vcol = 1;
    for (br = 0; br <= r; br++) {
      absx = 1.0 / s[br];
      i = vcol + 16;
      for (exponent = vcol; exponent <= i; exponent++) {
        V[exponent - 1] *= absx;
      }

      vcol += 17;
    }

    for (exponent = 0; exponent <= 272; exponent += 17) {
      i = exponent + 1;
      vcol = exponent + 17;
      if (i <= vcol) {
        memset(&X[i + -1], 0, ((vcol - i) + 1) * sizeof(double));
      }
    }

    br = 0;
    for (exponent = 0; exponent <= 272; exponent += 17) {
      ar = -1;
      br++;
      i = br + 17 * r;
      for (ib = br; ib <= i; ib += 17) {
        ia = ar;
        vcol = exponent + 1;
        i1 = exponent + 17;
        for (ic = vcol; ic <= i1; ic++) {
          ia++;
          X[ic - 1] += U[ib - 1] * V[ia];
        }

        ar += 17;
      }
    }
  }
}

/*
 * File trailer for pinv.c
 *
 * [EOF]
 */
