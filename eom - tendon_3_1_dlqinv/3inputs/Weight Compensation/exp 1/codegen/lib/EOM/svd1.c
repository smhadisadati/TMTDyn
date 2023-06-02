/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: svd1.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 08-May-2021 03:51:05
 */

/* Include Files */
#include "svd1.h"
#include "xnrm2.h"
#include "xrotg.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double A[324]
 *                double U[18]
 * Return Type  : void
 */
void c_svd(const double A[324], double U[18])
{
  double b_A[324];
  double e[18];
  double work[18];
  double nrm;
  double rt;
  double scale;
  double sm;
  double snorm;
  double sqds;
  double ztest;
  int exitg1;
  int i;
  int ix;
  int iy;
  int jj;
  int k;
  int q;
  int qjj;
  int qp1;
  int qq;
  int qq_tmp;
  boolean_T apply_transform;
  boolean_T exitg2;
  memcpy(&b_A[0], &A[0], 324U * sizeof(double));
  memset(&U[0], 0, 18U * sizeof(double));
  memset(&e[0], 0, 18U * sizeof(double));
  memset(&work[0], 0, 18U * sizeof(double));
  for (q = 0; q < 17; q++) {
    qp1 = q + 2;
    qq_tmp = q + 18 * q;
    qq = qq_tmp + 1;
    apply_transform = false;
    nrm = c_xnrm2(18 - q, b_A, qq_tmp + 1);
    if (nrm > 0.0) {
      apply_transform = true;
      if (b_A[qq_tmp] < 0.0) {
        ztest = -nrm;
        U[q] = -nrm;
      } else {
        ztest = nrm;
        U[q] = nrm;
      }

      if (fabs(ztest) >= 1.0020841800044864E-292) {
        nrm = 1.0 / ztest;
        i = (qq_tmp - q) + 18;
        for (k = qq; k <= i; k++) {
          b_A[k - 1] *= nrm;
        }
      } else {
        i = (qq_tmp - q) + 18;
        for (k = qq; k <= i; k++) {
          b_A[k - 1] /= U[q];
        }
      }

      b_A[qq_tmp]++;
      U[q] = -U[q];
    } else {
      U[q] = 0.0;
    }

    for (jj = qp1; jj < 19; jj++) {
      qjj = q + 18 * (jj - 1);
      if (apply_transform) {
        qq = 17 - q;
        nrm = 0.0;
        ix = qq_tmp + 1;
        iy = qjj;
        for (k = 0; k <= qq; k++) {
          nrm += b_A[ix - 1] * b_A[iy];
          ix++;
          iy++;
        }

        nrm = -(nrm / b_A[qq_tmp]);
        if (nrm != 0.0) {
          ix = qq_tmp;
          iy = qjj;
          i = 17 - q;
          for (k = 0; k <= i; k++) {
            b_A[iy] += nrm * b_A[ix];
            ix++;
            iy++;
          }
        }
      }

      e[jj - 1] = b_A[qjj];
    }

    if (q + 1 <= 16) {
      nrm = d_xnrm2(17 - q, e, q + 2);
      if (nrm == 0.0) {
        e[q] = 0.0;
      } else {
        if (e[q + 1] < 0.0) {
          e[q] = -nrm;
        } else {
          e[q] = nrm;
        }

        nrm = e[q];
        if (fabs(e[q]) >= 1.0020841800044864E-292) {
          nrm = 1.0 / e[q];
          for (k = qp1; k < 19; k++) {
            e[k - 1] *= nrm;
          }
        } else {
          for (k = qp1; k < 19; k++) {
            e[k - 1] /= nrm;
          }
        }

        e[q + 1]++;
        e[q] = -e[q];
        for (jj = qp1; jj < 19; jj++) {
          work[jj - 1] = 0.0;
        }

        for (jj = qp1; jj < 19; jj++) {
          ztest = e[jj - 1];
          if (ztest != 0.0) {
            ix = q + 18 * (jj - 1);
            iy = q + 1;
            i = 16 - q;
            for (k = 0; k <= i; k++) {
              work[iy] += ztest * b_A[ix + 1];
              ix++;
              iy++;
            }
          }
        }

        for (jj = qp1; jj < 19; jj++) {
          nrm = -e[jj - 1] / e[q + 1];
          if (nrm != 0.0) {
            ix = q;
            iy = (q + 18 * (jj - 1)) + 1;
            i = 16 - q;
            for (k = 0; k <= i; k++) {
              b_A[iy] += nrm * work[ix + 1];
              ix++;
              iy++;
            }
          }
        }
      }
    }
  }

  iy = 16;
  U[17] = b_A[323];
  e[16] = b_A[322];
  e[17] = 0.0;
  ix = 0;
  snorm = 0.0;
  for (q = 0; q < 18; q++) {
    ztest = U[q];
    sm = ztest;
    if (ztest != 0.0) {
      rt = fabs(ztest);
      sm = rt;
      U[q] = rt;
      if (q + 1 < 18) {
        e[q] /= ztest / rt;
      }
    }

    if ((q + 1 < 18) && (e[q] != 0.0)) {
      rt = fabs(e[q]);
      nrm = rt / e[q];
      e[q] = rt;
      U[q + 1] *= nrm;
    }

    snorm = fmax(snorm, fmax(fabs(sm), fabs(e[q])));
  }

  while ((iy + 2 > 0) && (ix < 75)) {
    jj = iy;
    do {
      exitg1 = 0;
      q = jj + 1;
      if (jj + 1 == 0) {
        exitg1 = 1;
      } else {
        nrm = fabs(e[jj]);
        if ((nrm <= 2.2204460492503131E-16 * (fabs(U[jj]) + fabs(U[jj + 1]))) ||
            (nrm <= 1.0020841800044864E-292) || ((ix > 20) && (nrm <=
              2.2204460492503131E-16 * snorm))) {
          e[jj] = 0.0;
          exitg1 = 1;
        } else {
          jj--;
        }
      }
    } while (exitg1 == 0);

    if (jj + 1 == iy + 1) {
      qq = 4;
    } else {
      qjj = iy + 2;
      qq = iy + 2;
      exitg2 = false;
      while ((!exitg2) && (qq >= jj + 1)) {
        qjj = qq;
        if (qq == jj + 1) {
          exitg2 = true;
        } else {
          nrm = 0.0;
          if (qq < iy + 2) {
            nrm = fabs(e[qq - 1]);
          }

          if (qq > jj + 2) {
            nrm += fabs(e[qq - 2]);
          }

          ztest = fabs(U[qq - 1]);
          if ((ztest <= 2.2204460492503131E-16 * nrm) || (ztest <=
               1.0020841800044864E-292)) {
            U[qq - 1] = 0.0;
            exitg2 = true;
          } else {
            qq--;
          }
        }
      }

      if (qjj == jj + 1) {
        qq = 3;
      } else if (qjj == iy + 2) {
        qq = 1;
      } else {
        qq = 2;
        q = qjj;
      }
    }

    switch (qq) {
     case 1:
      ztest = e[iy];
      e[iy] = 0.0;
      i = iy + 1;
      for (k = i; k >= q + 1; k--) {
        xrotg(&U[k - 1], &ztest, &rt, &sqds);
        if (k > q + 1) {
          sm = e[k - 2];
          ztest = -sqds * sm;
          e[k - 2] = sm * rt;
        }
      }
      break;

     case 2:
      ztest = e[q - 1];
      e[q - 1] = 0.0;
      for (k = q + 1; k <= iy + 2; k++) {
        xrotg(&U[k - 1], &ztest, &rt, &sqds);
        sm = e[k - 1];
        ztest = -sqds * sm;
        e[k - 1] = sm * rt;
      }
      break;

     case 3:
      qq = iy + 1;
      nrm = U[iy + 1];
      scale = fmax(fmax(fmax(fmax(fabs(nrm), fabs(U[iy])), fabs(e[iy])), fabs
                        (U[q])), fabs(e[q]));
      sm = nrm / scale;
      nrm = U[iy] / scale;
      ztest = e[iy] / scale;
      sqds = U[q] / scale;
      rt = ((nrm + sm) * (nrm - sm) + ztest * ztest) / 2.0;
      nrm = sm * ztest;
      nrm *= nrm;
      if ((rt != 0.0) || (nrm != 0.0)) {
        ztest = sqrt(rt * rt + nrm);
        if (rt < 0.0) {
          ztest = -ztest;
        }

        ztest = nrm / (rt + ztest);
      } else {
        ztest = 0.0;
      }

      ztest += (sqds + sm) * (sqds - sm);
      nrm = sqds * (e[q] / scale);
      for (k = q + 1; k <= qq; k++) {
        xrotg(&ztest, &nrm, &rt, &sqds);
        if (k > q + 1) {
          e[k - 2] = ztest;
        }

        nrm = e[k - 1];
        sm = U[k - 1];
        e[k - 1] = rt * nrm - sqds * sm;
        ztest = sqds * U[k];
        U[k] *= rt;
        U[k - 1] = rt * sm + sqds * nrm;
        xrotg(&U[k - 1], &ztest, &rt, &sqds);
        ztest = rt * e[k - 1] + sqds * U[k];
        U[k] = -sqds * e[k - 1] + rt * U[k];
        nrm = sqds * e[k];
        e[k] *= rt;
      }

      e[iy] = ztest;
      ix++;
      break;

     default:
      if (U[q] < 0.0) {
        U[q] = -U[q];
      }

      qp1 = q + 1;
      while ((q + 1 < 18) && (U[q] < U[qp1])) {
        rt = U[q];
        U[q] = U[qp1];
        U[qp1] = rt;
        q = qp1;
        qp1++;
      }

      ix = 0;
      iy--;
      break;
    }
  }
}

/*
 * File trailer for svd1.c
 *
 * [EOF]
 */
