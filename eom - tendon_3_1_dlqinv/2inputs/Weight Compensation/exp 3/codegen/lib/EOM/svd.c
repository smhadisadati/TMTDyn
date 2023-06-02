/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: svd.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 08-May-2021 02:08:04
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
 * Arguments    : const double A[289]
 *                double U[289]
 *                double s[17]
 *                double V[289]
 * Return Type  : void
 */
void b_svd(const double A[289], double U[289], double s[17], double V[289])
{
  double Vf[289];
  double b_A[289];
  double b_s[17];
  double e[17];
  double work[17];
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
  memcpy(&b_A[0], &A[0], 289U * sizeof(double));
  memset(&b_s[0], 0, 17U * sizeof(double));
  memset(&e[0], 0, 17U * sizeof(double));
  memset(&work[0], 0, 17U * sizeof(double));
  memset(&U[0], 0, 289U * sizeof(double));
  memset(&Vf[0], 0, 289U * sizeof(double));
  for (q = 0; q < 16; q++) {
    qp1 = q + 2;
    qq = (q + 17 * q) + 1;
    apply_transform = false;
    nrm = b_xnrm2(17 - q, b_A, qq);
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
        qp1jj = (qq - q) + 16;
        for (k = qq; k <= qp1jj; k++) {
          b_A[k - 1] *= nrm;
        }
      } else {
        qp1jj = (qq - q) + 16;
        for (k = qq; k <= qp1jj; k++) {
          b_A[k - 1] /= b_s[q];
        }
      }

      b_A[qq - 1]++;
      b_s[q] = -b_s[q];
    } else {
      b_s[q] = 0.0;
    }

    for (k = qp1; k < 18; k++) {
      qjj = q + 17 * (k - 1);
      if (apply_transform) {
        b_xaxpy(17 - q, -(b_xdotc(17 - q, b_A, qq, b_A, qjj + 1) / b_A[q + 17 *
                          q]), qq, b_A, qjj + 1);
      }

      e[k - 1] = b_A[qjj];
    }

    for (k = q + 1; k < 18; k++) {
      qjj = (k + 17 * q) - 1;
      U[qjj] = b_A[qjj];
    }

    if (q + 1 <= 15) {
      nrm = c_xnrm2(16 - q, e, q + 2);
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
          for (k = qp1; k < 18; k++) {
            e[k - 1] *= nrm;
          }
        } else {
          for (k = qp1; k < 18; k++) {
            e[k - 1] /= nrm;
          }
        }

        e[q + 1]++;
        e[q] = -e[q];
        for (k = qp1; k < 18; k++) {
          work[k - 1] = 0.0;
        }

        for (k = qp1; k < 18; k++) {
          c_xaxpy(16 - q, e[k - 1], b_A, (q + 17 * (k - 1)) + 2, work, q + 2);
        }

        for (k = qp1; k < 18; k++) {
          d_xaxpy(16 - q, -e[k - 1] / e[q + 1], work, q + 2, b_A, (q + 17 * (k -
                    1)) + 2);
        }
      }

      for (k = qp1; k < 18; k++) {
        Vf[(k + 17 * q) - 1] = e[k - 1];
      }
    }
  }

  m = 15;
  b_s[16] = b_A[288];
  e[15] = b_A[287];
  e[16] = 0.0;
  memset(&U[272], 0, 17U * sizeof(double));
  U[288] = 1.0;
  for (q = 15; q >= 0; q--) {
    qp1 = q + 2;
    qq = q + 17 * q;
    if (b_s[q] != 0.0) {
      for (k = qp1; k < 18; k++) {
        qjj = (q + 17 * (k - 1)) + 1;
        b_xaxpy(17 - q, -(b_xdotc(17 - q, U, qq + 1, U, qjj) / U[qq]), qq + 1, U,
                qjj);
      }

      for (k = q + 1; k < 18; k++) {
        qjj = (k + 17 * q) - 1;
        U[qjj] = -U[qjj];
      }

      U[qq]++;
      for (k = 0; k < q; k++) {
        U[k + 17 * q] = 0.0;
      }
    } else {
      memset(&U[q * 17], 0, 17U * sizeof(double));
      U[qq] = 1.0;
    }
  }

  for (q = 16; q >= 0; q--) {
    if ((q + 1 <= 15) && (e[q] != 0.0)) {
      qp1 = q + 2;
      qjj = (q + 17 * q) + 2;
      for (k = qp1; k < 18; k++) {
        qp1jj = (q + 17 * (k - 1)) + 2;
        b_xaxpy(16 - q, -(b_xdotc(16 - q, Vf, qjj, Vf, qp1jj) / Vf[qjj - 1]),
                qjj, Vf, qp1jj);
      }
    }

    memset(&Vf[q * 17], 0, 17U * sizeof(double));
    Vf[q + 17 * q] = 1.0;
  }

  qq = 0;
  snorm = 0.0;
  for (q = 0; q < 17; q++) {
    ztest = b_s[q];
    if (ztest != 0.0) {
      rt = fabs(ztest);
      nrm = ztest / rt;
      b_s[q] = rt;
      if (q + 1 < 17) {
        e[q] /= nrm;
      }

      qjj = 17 * q;
      qp1jj = qjj + 17;
      for (k = qjj + 1; k <= qp1jj; k++) {
        U[k - 1] *= nrm;
      }
    }

    if (q + 1 < 17) {
      ztest = e[q];
      if (ztest != 0.0) {
        rt = fabs(ztest);
        nrm = rt / ztest;
        e[q] = rt;
        b_s[q + 1] *= nrm;
        qjj = 17 * (q + 1);
        qp1jj = qjj + 17;
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

        c_xrot(Vf, 17 * (k - 1) + 1, 17 * (m + 1) + 1, sm, sqds);
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
        c_xrot(U, 17 * (k - 1) + 1, 17 * (q - 1) + 1, sm, sqds);
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
        c_xrot(Vf, 17 * (k - 1) + 1, 17 * k + 1, sm, sqds);
        b_s[k - 1] = sm * rt + sqds * nrm;
        xrotg(&b_s[k - 1], &ztest, &sm, &sqds);
        ztest = sm * e[k - 1] + sqds * b_s[k];
        b_s[k] = -sqds * e[k - 1] + sm * b_s[k];
        nrm = sqds * e[k];
        e[k] *= sm;
        c_xrot(U, 17 * (k - 1) + 1, 17 * k + 1, sm, sqds);
      }

      e[m] = ztest;
      qq++;
      break;

     default:
      if (b_s[q] < 0.0) {
        b_s[q] = -b_s[q];
        qjj = 17 * q;
        qp1jj = qjj + 17;
        for (k = qjj + 1; k <= qp1jj; k++) {
          Vf[k - 1] = -Vf[k - 1];
        }
      }

      qp1 = q + 1;
      while ((q + 1 < 17) && (b_s[q] < b_s[qp1])) {
        rt = b_s[q];
        b_s[q] = b_s[qp1];
        b_s[qp1] = rt;
        c_xswap(Vf, 17 * q + 1, 17 * (q + 1) + 1);
        c_xswap(U, 17 * q + 1, 17 * (q + 1) + 1);
        q = qp1;
        qp1++;
      }

      qq = 0;
      m--;
      break;
    }
  }

  for (k = 0; k < 17; k++) {
    s[k] = b_s[k];
    memcpy(&V[k * 17], &Vf[k * 17], 17U * sizeof(double));
  }
}

/*
 * Arguments    : const double A[34]
 *                double U[34]
 *                double s[2]
 *                double V[4]
 * Return Type  : void
 */
void svd(const double A[34], double U[34], double s[2], double V[4])
{
  double b_A[34];
  double Vf[4];
  double b_s[2];
  double e[2];
  double b;
  double f;
  double nrm;
  double rt;
  double scale;
  double sm;
  double snorm;
  double sqds;
  int ii;
  int k;
  int kase;
  int m;
  int qp1;
  int qq;
  boolean_T apply_transform;
  boolean_T exitg1;
  for (qp1 = 0; qp1 < 34; qp1++) {
    b_A[qp1] = A[qp1];
    U[qp1] = 0.0;
  }

  apply_transform = false;
  nrm = xnrm2(17, b_A, 1);
  if (nrm > 0.0) {
    apply_transform = true;
    if (b_A[0] < 0.0) {
      rt = -nrm;
      b_s[0] = -nrm;
    } else {
      rt = nrm;
      b_s[0] = nrm;
    }

    if (fabs(rt) >= 1.0020841800044864E-292) {
      nrm = 1.0 / rt;
      for (k = 1; k < 18; k++) {
        b_A[k - 1] *= nrm;
      }
    } else {
      for (k = 1; k < 18; k++) {
        b_A[k - 1] /= b_s[0];
      }
    }

    b_A[0]++;
    b_s[0] = -b_s[0];
  } else {
    b_s[0] = 0.0;
  }

  for (kase = 2; kase < 3; kase++) {
    if (apply_transform) {
      xaxpy(17, -(xdotc(17, b_A, 1, b_A, 18) / b_A[0]), 1, b_A, 18);
    }
  }

  memcpy(&U[0], &b_A[0], 17U * sizeof(double));
  nrm = xnrm2(16, b_A, 19);
  if (nrm > 0.0) {
    if (b_A[18] < 0.0) {
      rt = -nrm;
      b_s[1] = -nrm;
    } else {
      rt = nrm;
      b_s[1] = nrm;
    }

    if (fabs(rt) >= 1.0020841800044864E-292) {
      nrm = 1.0 / rt;
      for (k = 19; k < 35; k++) {
        b_A[k - 1] *= nrm;
      }
    } else {
      for (k = 19; k < 35; k++) {
        b_A[k - 1] /= b_s[1];
      }
    }

    b_A[18]++;
    b_s[1] = -b_s[1];
  } else {
    b_s[1] = 0.0;
  }

  memcpy(&U[18], &b_A[18], 16U * sizeof(double));
  m = 0;
  e[0] = b_A[17];
  e[1] = 0.0;
  for (k = 1; k >= 0; k--) {
    qp1 = k + 2;
    qq = k + 17 * k;
    if (b_s[k] != 0.0) {
      for (kase = qp1; kase < 3; kase++) {
        xaxpy(17 - k, -(xdotc(17 - k, U, qq + 1, U, k + 18) / U[qq]), qq + 1, U,
              k + 18);
      }

      for (ii = k + 1; ii < 18; ii++) {
        kase = (ii + 17 * k) - 1;
        U[kase] = -U[kase];
      }

      U[qq]++;
      if (0 <= k - 1) {
        U[17 * k] = 0.0;
      }
    } else {
      memset(&U[k * 17], 0, 17U * sizeof(double));
      U[qq] = 1.0;
    }
  }

  Vf[2] = 0.0;
  Vf[3] = 1.0;
  Vf[1] = 0.0;
  Vf[0] = 1.0;
  if (b_s[0] != 0.0) {
    rt = fabs(b_s[0]);
    nrm = b_s[0] / rt;
    b_s[0] = rt;
    e[0] = b_A[17] / nrm;
    for (k = 1; k < 18; k++) {
      U[k - 1] *= nrm;
    }
  }

  if (e[0] != 0.0) {
    rt = fabs(e[0]);
    nrm = rt / e[0];
    e[0] = rt;
    b_s[1] *= nrm;
    Vf[2] = 0.0;
    Vf[3] = nrm;
  }

  if (b_s[1] != 0.0) {
    rt = fabs(b_s[1]);
    nrm = b_s[1] / rt;
    b_s[1] = rt;
    for (k = 18; k < 35; k++) {
      U[k - 1] *= nrm;
    }
  }

  qq = 0;
  snorm = fmax(fmax(b_s[0], e[0]), fmax(b_s[1], 0.0));
  while ((m + 2 > 0) && (qq < 75)) {
    ii = m + 1;
    exitg1 = false;
    while (!(exitg1 || (ii == 0))) {
      nrm = fabs(e[0]);
      if ((nrm <= 2.2204460492503131E-16 * (fabs(b_s[0]) + fabs(b_s[1]))) ||
          (nrm <= 1.0020841800044864E-292) || ((qq > 20) && (nrm <=
            2.2204460492503131E-16 * snorm))) {
        e[0] = 0.0;
        exitg1 = true;
      } else {
        ii = 0;
      }
    }

    if (ii == m + 1) {
      kase = 4;
    } else {
      qp1 = m + 2;
      kase = m + 2;
      exitg1 = false;
      while ((!exitg1) && (kase >= ii)) {
        qp1 = kase;
        if (kase == ii) {
          exitg1 = true;
        } else {
          nrm = 0.0;
          if (kase < m + 2) {
            nrm = fabs(e[kase - 1]);
          }

          if (kase > ii + 1) {
            nrm += fabs(e[0]);
          }

          rt = fabs(b_s[kase - 1]);
          if ((rt <= 2.2204460492503131E-16 * nrm) || (rt <=
               1.0020841800044864E-292)) {
            b_s[kase - 1] = 0.0;
            exitg1 = true;
          } else {
            kase--;
          }
        }
      }

      if (qp1 == ii) {
        kase = 3;
      } else if (qp1 == m + 2) {
        kase = 1;
      } else {
        kase = 2;
        ii = qp1;
      }
    }

    switch (kase) {
     case 1:
      f = e[m];
      e[m] = 0.0;
      qp1 = m + 1;
      for (k = qp1; k >= ii + 1; k--) {
        xrotg(&b_s[0], &f, &b, &sm);
        xrot(Vf, 1, ((m + 1) << 1) + 1, b, sm);
      }
      break;

     case 2:
      f = e[ii - 1];
      e[ii - 1] = 0.0;
      for (k = ii + 1; k <= m + 2; k++) {
        xrotg(&b_s[k - 1], &f, &b, &sm);
        nrm = e[k - 1];
        f = -sm * nrm;
        e[k - 1] = nrm * b;
        b_xrot(U, 17 * (k - 1) + 1, 17 * (ii - 1) + 1, b, sm);
      }
      break;

     case 3:
      kase = m + 1;
      nrm = b_s[m + 1];
      scale = fmax(fmax(fmax(fmax(fabs(nrm), fabs(b_s[m])), fabs(e[m])), fabs
                        (b_s[ii])), fabs(e[ii]));
      sm = nrm / scale;
      nrm = b_s[m] / scale;
      rt = e[m] / scale;
      sqds = b_s[ii] / scale;
      b = ((nrm + sm) * (nrm - sm) + rt * rt) / 2.0;
      nrm = sm * rt;
      nrm *= nrm;
      if ((b != 0.0) || (nrm != 0.0)) {
        rt = sqrt(b * b + nrm);
        if (b < 0.0) {
          rt = -rt;
        }

        rt = nrm / (b + rt);
      } else {
        rt = 0.0;
      }

      f = (sqds + sm) * (sqds - sm) + rt;
      nrm = sqds * (e[ii] / scale);
      for (k = ii + 1; k <= kase; k++) {
        xrotg(&f, &nrm, &b, &sm);
        f = b * b_s[0] + sm * e[0];
        rt = b * e[0] - sm * b_s[0];
        e[0] = rt;
        nrm = sm * b_s[1];
        b_s[1] *= b;
        xrot(Vf, 1, 3, b, sm);
        b_s[0] = f;
        xrotg(&b_s[0], &nrm, &b, &sm);
        f = b * rt + sm * b_s[1];
        b_s[1] = -sm * rt + b * b_s[1];
        nrm = sm * e[1];
        e[1] *= b;
        b_xrot(U, 1, 18, b, sm);
      }

      e[m] = f;
      qq++;
      break;

     default:
      if (b_s[ii] < 0.0) {
        b_s[ii] = -b_s[ii];
        kase = ii << 1;
        qp1 = kase + 2;
        for (k = kase + 1; k <= qp1; k++) {
          Vf[k - 1] = -Vf[k - 1];
        }
      }

      qp1 = ii + 1;
      while ((ii + 1 < 2) && (b_s[ii] < b_s[qp1])) {
        rt = b_s[ii];
        b_s[ii] = b_s[qp1];
        b_s[qp1] = rt;
        xswap(Vf, (ii << 1) + 1, ((ii + 1) << 1) + 1);
        b_xswap(U, 17 * ii + 1, 17 * (ii + 1) + 1);
        ii = qp1;
        qp1++;
      }

      qq = 0;
      m--;
      break;
    }
  }

  s[0] = b_s[0];
  V[0] = Vf[0];
  V[1] = Vf[1];
  s[1] = b_s[1];
  V[2] = Vf[2];
  V[3] = Vf[3];
}

/*
 * File trailer for svd.c
 *
 * [EOF]
 */
