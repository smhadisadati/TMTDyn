/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: pinv.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 08-May-2021 03:51:05
 */

/* Include Files */
#include "pinv.h"
#include "svd.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double A[324]
 *                double tol
 *                double X[324]
 * Return Type  : void
 */
void b_pinv(const double A[324], double tol, double X[324])
{
  double U[324];
  double V[324];
  double s[18];
  double a;
  int ar;
  int br;
  int i;
  int i1;
  int ia;
  int ib;
  int ic;
  int k;
  int r;
  int vcol;
  memset(&X[0], 0, 324U * sizeof(double));
  b_svd(A, U, s, V);
  r = -1;
  k = 0;
  while ((k < 18) && (s[k] > tol)) {
    r++;
    k++;
  }

  if (r + 1 > 0) {
    vcol = 1;
    for (br = 0; br <= r; br++) {
      a = 1.0 / s[br];
      i = vcol + 17;
      for (k = vcol; k <= i; k++) {
        V[k - 1] *= a;
      }

      vcol += 18;
    }

    for (k = 0; k <= 306; k += 18) {
      i = k + 1;
      vcol = k + 18;
      if (i <= vcol) {
        memset(&X[i + -1], 0, ((vcol - i) + 1) * sizeof(double));
      }
    }

    br = 0;
    for (k = 0; k <= 306; k += 18) {
      ar = -1;
      br++;
      i = br + 18 * r;
      for (ib = br; ib <= i; ib += 18) {
        ia = ar;
        vcol = k + 1;
        i1 = k + 18;
        for (ic = vcol; ic <= i1; ic++) {
          ia++;
          X[ic - 1] += U[ib - 1] * V[ia];
        }

        ar += 18;
      }
    }
  }
}

/*
 * Arguments    : const double A[54]
 *                double X[54]
 * Return Type  : void
 */
void pinv(const double A[54], double X[54])
{
  double U[54];
  double V[9];
  double s[3];
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
  memset(&X[0], 0, 54U * sizeof(double));
  svd(A, U, s, V);
  absx = fabs(s[0]);
  if (absx <= 2.2250738585072014E-308) {
    absx = 4.94065645841247E-324;
  } else {
    frexp(absx, &exponent);
    absx = ldexp(1.0, exponent - 53);
  }

  absx *= 18.0;
  r = -1;
  exponent = 0;
  while ((exponent < 3) && (s[exponent] > absx)) {
    r++;
    exponent++;
  }

  if (r + 1 > 0) {
    vcol = 1;
    for (br = 0; br <= r; br++) {
      absx = 1.0 / s[br];
      i = vcol + 2;
      for (exponent = vcol; exponent <= i; exponent++) {
        V[exponent - 1] *= absx;
      }

      vcol += 3;
    }

    for (exponent = 0; exponent <= 51; exponent += 3) {
      i = exponent + 1;
      vcol = exponent + 3;
      if (i <= vcol) {
        memset(&X[i + -1], 0, ((vcol - i) + 1) * sizeof(double));
      }
    }

    br = 0;
    for (exponent = 0; exponent <= 51; exponent += 3) {
      ar = -1;
      br++;
      i = br + 18 * r;
      for (ib = br; ib <= i; ib += 18) {
        ia = ar;
        vcol = exponent + 1;
        i1 = exponent + 3;
        for (ic = vcol; ic <= i1; ic++) {
          ia++;
          X[ic - 1] += U[ib - 1] * V[ia];
        }

        ar += 3;
      }
    }
  }
}

/*
 * File trailer for pinv.c
 *
 * [EOF]
 */
