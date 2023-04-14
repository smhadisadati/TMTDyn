/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: svd.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 10-Mar-2021 22:46:32
 */

/* Include Files */
#include "svd.h"
#include "xaxpy.h"
#include "xdotc.h"
#include "xnrm2.h"
#include "xrot.h"
#include "xrotg.h"
#include "xswap.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double A[576]
 *                double U[576]
 *                double s[24]
 *                double V[576]
 * Return Type  : void
 */
void svd(const double A[576], double U[576], double s[24], double V[576])
{
  double Vf[576];
  double b_A[576];
  double b_s[24];
  double e[24];
  double work[24];
  double nrm;
  double rt;
  double scale;
  double sm;
  double snorm;
  double sqds;
  double ztest;
  int exitg1;
  int k;
  int m;
  int q;
  int qjj;
  int qp1;
  int qp1jj;
  int qq;
  boolean_T apply_transform;
  boolean_T exitg2;
  memcpy(&b_A[0], &A[0], 576U * sizeof(double));
  memset(&b_s[0], 0, 24U * sizeof(double));
  memset(&e[0], 0, 24U * sizeof(double));
  memset(&work[0], 0, 24U * sizeof(double));
  memset(&U[0], 0, 576U * sizeof(double));
  memset(&Vf[0], 0, 576U * sizeof(double));
  for (q = 0; q < 23; q++) {
    qp1 = q + 2;
    qq = (q + 24 * q) + 1;
    apply_transform = false;
    nrm = xnrm2(24 - q, b_A, qq);
    if (nrm > 0.0) {
      apply_transform = true;
      if (b_A[qq - 1] < 0.0) {
        ztest = -nrm;
        b_s[q] = -nrm;
      } else {
        ztest = nrm;
        b_s[q] = nrm;
      }

      if (fabs(ztest) >= 1.0020841800044864E-292) {
        nrm = 1.0 / ztest;
        qp1jj = (qq - q) + 23;
        for (k = qq; k <= qp1jj; k++) {
          b_A[k - 1] *= nrm;
        }
      } else {
        qp1jj = (qq - q) + 23;
        for (k = qq; k <= qp1jj; k++) {
          b_A[k - 1] /= b_s[q];
        }
      }

      b_A[qq - 1]++;
      b_s[q] = -b_s[q];
    } else {
      b_s[q] = 0.0;
    }

    for (k = qp1; k < 25; k++) {
      qjj = q + 24 * (k - 1);
      if (apply_transform) {
        xaxpy(24 - q, -(xdotc(24 - q, b_A, qq, b_A, qjj + 1) / b_A[q + 24 * q]),
              qq, b_A, qjj + 1);
      }

      e[k - 1] = b_A[qjj];
    }

    for (k = q + 1; k < 25; k++) {
      qjj = (k + 24 * q) - 1;
      U[qjj] = b_A[qjj];
    }

    if (q + 1 <= 22) {
      nrm = b_xnrm2(23 - q, e, q + 2);
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
          for (k = qp1; k < 25; k++) {
            e[k - 1] *= nrm;
          }
        } else {
          for (k = qp1; k < 25; k++) {
            e[k - 1] /= nrm;
          }
        }

        e[q + 1]++;
        e[q] = -e[q];
        for (k = qp1; k < 25; k++) {
          work[k - 1] = 0.0;
        }

        for (k = qp1; k < 25; k++) {
          b_xaxpy(23 - q, e[k - 1], b_A, (q + 24 * (k - 1)) + 2, work, q + 2);
        }

        for (k = qp1; k < 25; k++) {
          c_xaxpy(23 - q, -e[k - 1] / e[q + 1], work, q + 2, b_A, (q + 24 * (k -
                    1)) + 2);
        }
      }

      for (k = qp1; k < 25; k++) {
        Vf[(k + 24 * q) - 1] = e[k - 1];
      }
    }
  }

  m = 22;
  b_s[23] = b_A[575];
  e[22] = b_A[574];
  e[23] = 0.0;
  memset(&U[552], 0, 24U * sizeof(double));
  U[575] = 1.0;
  for (q = 22; q >= 0; q--) {
    qp1 = q + 2;
    qq = q + 24 * q;
    if (b_s[q] != 0.0) {
      for (k = qp1; k < 25; k++) {
        qjj = (q + 24 * (k - 1)) + 1;
        xaxpy(24 - q, -(xdotc(24 - q, U, qq + 1, U, qjj) / U[qq]), qq + 1, U,
              qjj);
      }

      for (k = q + 1; k < 25; k++) {
        qjj = (k + 24 * q) - 1;
        U[qjj] = -U[qjj];
      }

      U[qq]++;
      for (k = 0; k < q; k++) {
        U[k + 24 * q] = 0.0;
      }
    } else {
      memset(&U[q * 24], 0, 24U * sizeof(double));
      U[qq] = 1.0;
    }
  }

  for (q = 23; q >= 0; q--) {
    if ((q + 1 <= 22) && (e[q] != 0.0)) {
      qp1 = q + 2;
      qjj = (q + 24 * q) + 2;
      for (k = qp1; k < 25; k++) {
        qp1jj = (q + 24 * (k - 1)) + 2;
        xaxpy(23 - q, -(xdotc(23 - q, Vf, qjj, Vf, qp1jj) / Vf[qjj - 1]), qjj,
              Vf, qp1jj);
      }
    }

    memset(&Vf[q * 24], 0, 24U * sizeof(double));
    Vf[q + 24 * q] = 1.0;
  }

  qq = 0;
  snorm = 0.0;
  for (q = 0; q < 24; q++) {
    ztest = b_s[q];
    if (ztest != 0.0) {
      rt = fabs(ztest);
      nrm = ztest / rt;
      b_s[q] = rt;
      if (q + 1 < 24) {
        e[q] /= nrm;
      }

      qjj = 24 * q;
      qp1jj = qjj + 24;
      for (k = qjj + 1; k <= qp1jj; k++) {
        U[k - 1] *= nrm;
      }
    }

    if (q + 1 < 24) {
      ztest = e[q];
      if (ztest != 0.0) {
        rt = fabs(ztest);
        nrm = rt / ztest;
        e[q] = rt;
        b_s[q + 1] *= nrm;
        qjj = 24 * (q + 1);
        qp1jj = qjj + 24;
        for (k = qjj + 1; k <= qp1jj; k++) {
          Vf[k - 1] *= nrm;
        }
      }
    }

    snorm = fmax(snorm, fmax(fabs(b_s[q]), fabs(e[q])));
  }

  while ((m + 2 > 0) && (qq < 75)) {
    k = m;
    do {
      exitg1 = 0;
      q = k + 1;
      if (k + 1 == 0) {
        exitg1 = 1;
      } else {
        nrm = fabs(e[k]);
        if ((nrm <= 2.2204460492503131E-16 * (fabs(b_s[k]) + fabs(b_s[k + 1]))) ||
            (nrm <= 1.0020841800044864E-292) || ((qq > 20) && (nrm <=
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

          ztest = fabs(b_s[qjj - 1]);
          if ((ztest <= 2.2204460492503131E-16 * nrm) || (ztest <=
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
      ztest = e[m];
      e[m] = 0.0;
      qp1jj = m + 1;
      for (k = qp1jj; k >= q + 1; k--) {
        xrotg(&b_s[k - 1], &ztest, &sm, &sqds);
        if (k > q + 1) {
          rt = e[k - 2];
          ztest = -sqds * rt;
          e[k - 2] = rt * sm;
        }

        xrot(Vf, 24 * (k - 1) + 1, 24 * (m + 1) + 1, sm, sqds);
      }
      break;

     case 2:
      ztest = e[q - 1];
      e[q - 1] = 0.0;
      for (k = q + 1; k <= m + 2; k++) {
        xrotg(&b_s[k - 1], &ztest, &sm, &sqds);
        rt = e[k - 1];
        ztest = -sqds * rt;
        e[k - 1] = rt * sm;
        xrot(U, 24 * (k - 1) + 1, 24 * (q - 1) + 1, sm, sqds);
      }
      break;

     case 3:
      qjj = m + 1;
      nrm = b_s[m + 1];
      scale = fmax(fmax(fmax(fmax(fabs(nrm), fabs(b_s[m])), fabs(e[m])), fabs
                        (b_s[q])), fabs(e[q]));
      sm = nrm / scale;
      nrm = b_s[m] / scale;
      ztest = e[m] / scale;
      sqds = b_s[q] / scale;
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
      for (k = q + 1; k <= qjj; k++) {
        xrotg(&ztest, &nrm, &sm, &sqds);
        if (k > q + 1) {
          e[k - 2] = ztest;
        }

        nrm = e[k - 1];
        rt = b_s[k - 1];
        e[k - 1] = sm * nrm - sqds * rt;
        ztest = sqds * b_s[k];
        b_s[k] *= sm;
        xrot(Vf, 24 * (k - 1) + 1, 24 * k + 1, sm, sqds);
        b_s[k - 1] = sm * rt + sqds * nrm;
        xrotg(&b_s[k - 1], &ztest, &sm, &sqds);
        ztest = sm * e[k - 1] + sqds * b_s[k];
        b_s[k] = -sqds * e[k - 1] + sm * b_s[k];
        nrm = sqds * e[k];
        e[k] *= sm;
        xrot(U, 24 * (k - 1) + 1, 24 * k + 1, sm, sqds);
      }

      e[m] = ztest;
      qq++;
      break;

     default:
      if (b_s[q] < 0.0) {
        b_s[q] = -b_s[q];
        qjj = 24 * q;
        qp1jj = qjj + 24;
        for (k = qjj + 1; k <= qp1jj; k++) {
          Vf[k - 1] = -Vf[k - 1];
        }
      }

      qp1 = q + 1;
      while ((q + 1 < 24) && (b_s[q] < b_s[qp1])) {
        rt = b_s[q];
        b_s[q] = b_s[qp1];
        b_s[qp1] = rt;
        xswap(Vf, 24 * q + 1, 24 * (q + 1) + 1);
        xswap(U, 24 * q + 1, 24 * (q + 1) + 1);
        q = qp1;
        qp1++;
      }

      qq = 0;
      m--;
      break;
    }
  }

  for (k = 0; k < 24; k++) {
    s[k] = b_s[k];
    memcpy(&V[k * 24], &Vf[k * 24], 24U * sizeof(double));
  }
}

/*
 * File trailer for svd.c
 *
 * [EOF]
 */
