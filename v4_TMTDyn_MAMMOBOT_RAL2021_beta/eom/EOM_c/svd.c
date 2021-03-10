/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: svd.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 14-Oct-2020 16:42:47
 */

/* Include Files */
#include <math.h>
#include <string.h>
#include "EOM.h"
#include "EOM_input.h"
#include "svd.h"
#include "xrot.h"
#include "xrotg.h"
#include "sqrt.h"
#include "xswap.h"
#include "xaxpy.h"
#include "xdotc.h"
#include "xnrm2.h"

/* Function Definitions */

/*
 * Arguments    : const double A[1024]
 *                double U[1024]
 *                double s[32]
 *                double V[1024]
 * Return Type  : void
 */
void svd(const double A[1024], double U[1024], double s[32], double V[1024])
{
  double b_A[1024];
  double b_s[32];
  double e[32];
  double work[32];
  double Vf[1024];
  int q;
  int m;
  int qp1;
  int iter;
  int qq;
  boolean_T apply_transform;
  double nrm;
  int k;
  int qjj;
  double snorm;
  int qp1jj;
  double r;
  int exitg1;
  boolean_T exitg2;
  double scale;
  double sm;
  double sqds;
  double b;
  memcpy(&b_A[0], &A[0], sizeof(double) << 10);
  memset(&b_s[0], 0, sizeof(double) << 5);
  memset(&e[0], 0, sizeof(double) << 5);
  memset(&work[0], 0, sizeof(double) << 5);
  memset(&U[0], 0, sizeof(double) << 10);
  memset(&Vf[0], 0, sizeof(double) << 10);
  for (q = 0; q < 31; q++) {
    qp1 = q + 2;
    iter = q << 5;
    qq = (q + iter) + 1;
    apply_transform = false;
    nrm = xnrm2(32 - q, b_A, qq);
    if (nrm > 0.0) {
      apply_transform = true;
      if (b_A[qq - 1] < 0.0) {
        nrm = -nrm;
      }

      b_s[q] = nrm;
      if (fabs(nrm) >= 1.0020841800044864E-292) {
        nrm = 1.0 / nrm;
        qp1jj = (qq - q) + 31;
        for (k = qq; k <= qp1jj; k++) {
          b_A[k - 1] *= nrm;
        }
      } else {
        qp1jj = (qq - q) + 31;
        for (k = qq; k <= qp1jj; k++) {
          b_A[k - 1] /= b_s[q];
        }
      }

      b_A[qq - 1]++;
      b_s[q] = -b_s[q];
    } else {
      b_s[q] = 0.0;
    }

    for (k = qp1; k < 33; k++) {
      qjj = q + ((k - 1) << 5);
      if (apply_transform) {
        xaxpy(32 - q, -(xdotc(32 - q, b_A, qq, b_A, qjj + 1) / b_A[q + (q << 5)]),
              qq, b_A, qjj + 1);
      }

      e[k - 1] = b_A[qjj];
    }

    for (k = q + 1; k < 33; k++) {
      qp1jj = (k + iter) - 1;
      U[qp1jj] = b_A[qp1jj];
    }

    if (q + 1 <= 30) {
      nrm = b_xnrm2(31 - q, e, q + 2);
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
          for (k = qp1; k < 33; k++) {
            e[k - 1] *= nrm;
          }
        } else {
          for (k = qp1; k < 33; k++) {
            e[k - 1] /= nrm;
          }
        }

        e[q + 1]++;
        e[q] = -e[q];
        for (k = qp1; k < 33; k++) {
          work[k - 1] = 0.0;
        }

        for (k = qp1; k < 33; k++) {
          b_xaxpy(31 - q, e[k - 1], b_A, (q + ((k - 1) << 5)) + 2, work, q + 2);
        }

        for (k = qp1; k < 33; k++) {
          c_xaxpy(31 - q, -e[k - 1] / e[q + 1], work, q + 2, b_A, (q + ((k - 1) <<
                    5)) + 2);
        }
      }

      for (k = qp1; k < 33; k++) {
        Vf[(k + iter) - 1] = e[k - 1];
      }
    }
  }

  m = 30;
  b_s[31] = b_A[1023];
  e[30] = b_A[1022];
  e[31] = 0.0;
  memset(&U[992], 0, sizeof(double) << 5);
  U[1023] = 1.0;
  for (q = 30; q >= 0; q--) {
    qp1 = q + 2;
    iter = q << 5;
    qq = q + iter;
    if (b_s[q] != 0.0) {
      for (k = qp1; k < 33; k++) {
        qjj = (q + ((k - 1) << 5)) + 1;
        xaxpy(32 - q, -(xdotc(32 - q, U, qq + 1, U, qjj) / U[qq]), qq + 1, U,
              qjj);
      }

      for (k = q + 1; k < 33; k++) {
        qp1jj = (k + iter) - 1;
        U[qp1jj] = -U[qp1jj];
      }

      U[qq]++;
      for (k = 0; k < q; k++) {
        U[k + iter] = 0.0;
      }
    } else {
      memset(&U[q << 5], 0, sizeof(double) << 5);
      U[qq] = 1.0;
    }
  }

  for (q = 31; q >= 0; q--) {
    if ((q + 1 <= 30) && (e[q] != 0.0)) {
      qp1 = q + 2;
      qjj = (q + (q << 5)) + 2;
      for (k = qp1; k < 33; k++) {
        qp1jj = (q + ((k - 1) << 5)) + 2;
        xaxpy(31 - q, -(xdotc(31 - q, Vf, qjj, Vf, qp1jj) / Vf[qjj - 1]), qjj,
              Vf, qp1jj);
      }
    }

    memset(&Vf[q << 5], 0, sizeof(double) << 5);
    Vf[q + (q << 5)] = 1.0;
  }

  iter = 0;
  snorm = 0.0;
  for (q = 0; q < 32; q++) {
    if (b_s[q] != 0.0) {
      nrm = fabs(b_s[q]);
      r = b_s[q] / nrm;
      b_s[q] = nrm;
      if (q + 1 < 32) {
        e[q] /= r;
      }

      qjj = q << 5;
      qp1jj = qjj + 32;
      for (k = qjj + 1; k <= qp1jj; k++) {
        U[k - 1] *= r;
      }
    }

    if ((q + 1 < 32) && (e[q] != 0.0)) {
      nrm = fabs(e[q]);
      r = nrm / e[q];
      e[q] = nrm;
      b_s[q + 1] *= r;
      qjj = (q + 1) << 5;
      qp1jj = qjj + 32;
      for (k = qjj + 1; k <= qp1jj; k++) {
        Vf[k - 1] *= r;
      }
    }

    snorm = fmax(snorm, fmax(fabs(b_s[q]), fabs(e[q])));
  }

  while ((m + 2 > 0) && (iter < 75)) {
    k = m;
    do {
      exitg1 = 0;
      q = k + 1;
      if (k + 1 == 0) {
        exitg1 = 1;
      } else {
        nrm = fabs(e[k]);
        if ((nrm <= 2.2204460492503131E-16 * (fabs(b_s[k]) + fabs(b_s[k + 1]))) ||
            (nrm <= 1.0020841800044864E-292) || ((iter > 20) && (nrm <=
              2.2204460492503131E-16 * snorm))) {
          e[k] = 0.0;
          exitg1 = 1;
        } else {
          k--;
        }
      }
    } while (exitg1 == 0);

    if (k + 1 == m + 1) {
      qjj = 4;
    } else {
      qp1jj = m + 2;
      qjj = m + 2;
      exitg2 = false;
      while ((!exitg2) && (qjj >= k + 1)) {
        qp1jj = qjj;
        if (qjj == k + 1) {
          exitg2 = true;
        } else {
          nrm = 0.0;
          if (qjj < m + 2) {
            nrm = fabs(e[qjj - 1]);
          }

          if (qjj > k + 2) {
            nrm += fabs(e[qjj - 2]);
          }

          r = fabs(b_s[qjj - 1]);
          if ((r <= 2.2204460492503131E-16 * nrm) || (r <=
               1.0020841800044864E-292)) {
            b_s[qjj - 1] = 0.0;
            exitg2 = true;
          } else {
            qjj--;
          }
        }
      }

      if (qp1jj == k + 1) {
        qjj = 3;
      } else if (qp1jj == m + 2) {
        qjj = 1;
      } else {
        qjj = 2;
        q = qp1jj;
      }
    }

    switch (qjj) {
     case 1:
      r = e[m];
      e[m] = 0.0;
      qp1jj = m + 1;
      for (k = qp1jj; k >= q + 1; k--) {
        xrotg(&b_s[k - 1], &r, &sm, &sqds);
        if (k > q + 1) {
          r = -sqds * e[k - 2];
          e[k - 2] *= sm;
        }

        xrot(Vf, 1 + ((k - 1) << 5), 1 + ((m + 1) << 5), sm, sqds);
      }
      break;

     case 2:
      r = e[q - 1];
      e[q - 1] = 0.0;
      for (k = q + 1; k <= m + 2; k++) {
        xrotg(&b_s[k - 1], &r, &sm, &sqds);
        b = e[k - 1];
        r = -sqds * b;
        e[k - 1] = b * sm;
        xrot(U, 1 + ((k - 1) << 5), 1 + ((q - 1) << 5), sm, sqds);
      }
      break;

     case 3:
      qjj = m + 1;
      nrm = b_s[m + 1];
      scale = fmax(fmax(fmax(fmax(fabs(nrm), fabs(b_s[m])), fabs(e[m])), fabs
                        (b_s[q])), fabs(e[q]));
      sm = nrm / scale;
      nrm = b_s[m] / scale;
      r = e[m] / scale;
      sqds = b_s[q] / scale;
      b = ((nrm + sm) * (nrm - sm) + r * r) / 2.0;
      nrm = sm * r;
      nrm *= nrm;
      if ((b != 0.0) || (nrm != 0.0)) {
        r = b * b + nrm;
        b_sqrt(&r);
        if (b < 0.0) {
          r = -r;
        }

        r = nrm / (b + r);
      } else {
        r = 0.0;
      }

      r += (sqds + sm) * (sqds - sm);
      nrm = sqds * (e[q] / scale);
      for (k = q + 1; k <= qjj; k++) {
        xrotg(&r, &nrm, &sm, &sqds);
        if (k > q + 1) {
          e[k - 2] = r;
        }

        b = e[k - 1];
        nrm = b_s[k - 1];
        e[k - 1] = sm * b - sqds * nrm;
        r = sqds * b_s[k];
        b_s[k] *= sm;
        xrot(Vf, 1 + ((k - 1) << 5), 1 + (k << 5), sm, sqds);
        b_s[k - 1] = sm * nrm + sqds * b;
        xrotg(&b_s[k - 1], &r, &sm, &sqds);
        b = e[k - 1];
        r = sm * b + sqds * b_s[k];
        b_s[k] = -sqds * b + sm * b_s[k];
        nrm = sqds * e[k];
        e[k] *= sm;
        xrot(U, 1 + ((k - 1) << 5), 1 + (k << 5), sm, sqds);
      }

      e[m] = r;
      iter++;
      break;

     default:
      if (b_s[q] < 0.0) {
        b_s[q] = -b_s[q];
        qjj = q << 5;
        qp1jj = qjj + 32;
        for (k = qjj + 1; k <= qp1jj; k++) {
          Vf[k - 1] = -Vf[k - 1];
        }
      }

      qp1 = q + 1;
      while ((q + 1 < 32) && (b_s[q] < b_s[qp1])) {
        nrm = b_s[q];
        b_s[q] = b_s[qp1];
        b_s[qp1] = nrm;
        xswap(Vf, 1 + (q << 5), 1 + ((q + 1) << 5));
        xswap(U, 1 + (q << 5), 1 + ((q + 1) << 5));
        q = qp1;
        qp1++;
      }

      iter = 0;
      m--;
      break;
    }
  }

  for (k = 0; k < 32; k++) {
    s[k] = b_s[k];
    memcpy(&V[k << 5], &Vf[k << 5], sizeof(double) << 5);
  }
}

/*
 * File trailer for svd.c
 *
 * [EOF]
 */
