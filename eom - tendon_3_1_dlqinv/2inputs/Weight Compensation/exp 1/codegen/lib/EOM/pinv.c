/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: pinv.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 07-May-2021 20:42:12
 */

/* Include Files */
#include "pinv.h"
#include "svd.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double A[289]
 *                double tol
 *                double X[289]
 * Return Type  : void
 */
void b_pinv(const double A[289], double tol, double X[289])
{
  double U[289];
  double V[289];
  double s[17];
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
  memset(&X[0], 0, 289U * sizeof(double));
  b_svd(A, U, s, V);
  r = -1;
  k = 0;
  while ((k < 17) && (s[k] > tol)) {
    r++;
    k++;
  }

  if (r + 1 > 0) {
    vcol = 1;
    for (br = 0; br <= r; br++) {
      a = 1.0 / s[br];
      i = vcol + 16;
      for (k = vcol; k <= i; k++) {
        V[k - 1] *= a;
      }

      vcol += 17;
    }

    for (k = 0; k <= 272; k += 17) {
      i = k + 1;
      vcol = k + 17;
      if (i <= vcol) {
        memset(&X[i + -1], 0, ((vcol - i) + 1) * sizeof(double));
      }
    }

    br = 0;
    for (k = 0; k <= 272; k += 17) {
      ar = -1;
      br++;
      i = br + 17 * r;
      for (ib = br; ib <= i; ib += 17) {
        ia = ar;
        vcol = k + 1;
        i1 = k + 17;
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
 * Arguments    : const double A[34]
 *                double X[34]
 * Return Type  : void
 */
void pinv(const double A[34], double X[34])
{
  double U[34];
  double V[4];
  double s[2];
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
  memset(&X[0], 0, 34U * sizeof(double));
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
  while ((exponent < 2) && (s[exponent] > absx)) {
    r++;
    exponent++;
  }

  if (r + 1 > 0) {
    vcol = 1;
    for (br = 0; br <= r; br++) {
      absx = 1.0 / s[br];
      i = vcol + 1;
      for (exponent = vcol; exponent <= i; exponent++) {
        V[exponent - 1] *= absx;
      }

      vcol += 2;
    }

    for (exponent = 0; exponent <= 32; exponent += 2) {
      i = exponent + 1;
      vcol = exponent + 2;
      if (i <= vcol) {
        memset(&X[i + -1], 0, ((vcol - i) + 1) * sizeof(double));
      }
    }

    br = 0;
    for (exponent = 0; exponent <= 32; exponent += 2) {
      ar = -1;
      br++;
      i = br + 17 * r;
      for (ib = br; ib <= i; ib += 17) {
        ia = ar;
        vcol = exponent + 1;
        i1 = exponent + 2;
        for (ic = vcol; ic <= i1; ic++) {
          ia++;
          X[ic - 1] += U[ib - 1] * V[ia];
        }

        ar += 2;
      }
    }
  }
}

/*
 * File trailer for pinv.c
 *
 * [EOF]
 */
