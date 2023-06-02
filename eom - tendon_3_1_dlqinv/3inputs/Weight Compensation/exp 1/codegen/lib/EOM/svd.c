/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: svd.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 08-May-2021 03:51:05
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
 * Arguments    : const double A[324]
 *                double U[324]
 *                double s[18]
 *                double V[324]
 * Return Type  : void
 */
void b_svd(const double A[324], double U[324], double s[18], double V[324])
{
  double Vf[324];
  double b_A[324];
  double b_s[18];
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
  int k;
  int m;
  int q;
  int qjj;
  int qp1;
  int qp1jj;
  int qq;
  boolean_T apply_transform;
  boolean_T exitg2;
  memcpy(&b_A[0], &A[0], 324U * sizeof(double));
  memset(&b_s[0], 0, 18U * sizeof(double));
  memset(&e[0], 0, 18U * sizeof(double));
  memset(&work[0], 0, 18U * sizeof(double));
  memset(&U[0], 0, 324U * sizeof(double));
  memset(&Vf[0], 0, 324U * sizeof(double));
  for (q = 0; q < 17; q++) {
    qp1 = q + 2;
    qq = (q + 18 * q) + 1;
    apply_transform = false;
    nrm = c_xnrm2(18 - q, b_A, qq);
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
        qp1jj = (qq - q) + 17;
        for (k = qq; k <= qp1jj; k++) {
          b_A[k - 1] *= nrm;
        }
      } else {
        qp1jj = (qq - q) + 17;
        for (k = qq; k <= qp1jj; k++) {
          b_A[k - 1] /= b_s[q];
        }
      }

      b_A[qq - 1]++;
      b_s[q] = -b_s[q];
    } else {
      b_s[q] = 0.0;
    }

    for (k = qp1; k < 19; k++) {
      qjj = q + 18 * (k - 1);
      if (apply_transform) {
        e_xaxpy(18 - q, -(c_xdotc(18 - q, b_A, qq, b_A, qjj + 1) / b_A[q + 18 *
                          q]), qq, b_A, qjj + 1);
      }

      e[k - 1] = b_A[qjj];
    }

    for (k = q + 1; k < 19; k++) {
      qjj = (k + 18 * q) - 1;
      U[qjj] = b_A[qjj];
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
        for (k = qp1; k < 19; k++) {
          work[k - 1] = 0.0;
        }

        for (k = qp1; k < 19; k++) {
          f_xaxpy(17 - q, e[k - 1], b_A, (q + 18 * (k - 1)) + 2, work, q + 2);
        }

        for (k = qp1; k < 19; k++) {
          g_xaxpy(17 - q, -e[k - 1] / e[q + 1], work, q + 2, b_A, (q + 18 * (k -
                    1)) + 2);
        }
      }

      for (k = qp1; k < 19; k++) {
        Vf[(k + 18 * q) - 1] = e[k - 1];
      }
    }
  }

  m = 16;
  b_s[17] = b_A[323];
  e[16] = b_A[322];
  e[17] = 0.0;
  memset(&U[306], 0, 18U * sizeof(double));
  U[323] = 1.0;
  for (q = 16; q >= 0; q--) {
    qp1 = q + 2;
    qq = q + 18 * q;
    if (b_s[q] != 0.0) {
      for (k = qp1; k < 19; k++) {
        qjj = (q + 18 * (k - 1)) + 1;
        e_xaxpy(18 - q, -(c_xdotc(18 - q, U, qq + 1, U, qjj) / U[qq]), qq + 1, U,
                qjj);
      }

      for (k = q + 1; k < 19; k++) {
        qjj = (k + 18 * q) - 1;
        U[qjj] = -U[qjj];
      }

      U[qq]++;
      for (k = 0; k < q; k++) {
        U[k + 18 * q] = 0.0;
      }
    } else {
      memset(&U[q * 18], 0, 18U * sizeof(double));
      U[qq] = 1.0;
    }
  }

  for (q = 17; q >= 0; q--) {
    if ((q + 1 <= 16) && (e[q] != 0.0)) {
      qp1 = q + 2;
      qjj = (q + 18 * q) + 2;
      for (k = qp1; k < 19; k++) {
        qp1jj = (q + 18 * (k - 1)) + 2;
        e_xaxpy(17 - q, -(c_xdotc(17 - q, Vf, qjj, Vf, qp1jj) / Vf[qjj - 1]),
                qjj, Vf, qp1jj);
      }
    }

    memset(&Vf[q * 18], 0, 18U * sizeof(double));
    Vf[q + 18 * q] = 1.0;
  }

  qq = 0;
  snorm = 0.0;
  for (q = 0; q < 18; q++) {
    ztest = b_s[q];
    if (ztest != 0.0) {
      rt = fabs(ztest);
      nrm = ztest / rt;
      b_s[q] = rt;
      if (q + 1 < 18) {
        e[q] /= nrm;
      }

      qjj = 18 * q;
      qp1jj = qjj + 18;
      for (k = qjj + 1; k <= qp1jj; k++) {
        U[k - 1] *= nrm;
      }
    }

    if (q + 1 < 18) {
      ztest = e[q];
      if (ztest != 0.0) {
        rt = fabs(ztest);
        nrm = rt / ztest;
        e[q] = rt;
        b_s[q + 1] *= nrm;
        qjj = 18 * (q + 1);
        qp1jj = qjj + 18;
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

        c_xrot(Vf, 18 * (k - 1) + 1, 18 * (m + 1) + 1, sm, sqds);
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
        c_xrot(U, 18 * (k - 1) + 1, 18 * (q - 1) + 1, sm, sqds);
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
        c_xrot(Vf, 18 * (k - 1) + 1, 18 * k + 1, sm, sqds);
        b_s[k - 1] = sm * rt + sqds * nrm;
        xrotg(&b_s[k - 1], &ztest, &sm, &sqds);
        ztest = sm * e[k - 1] + sqds * b_s[k];
        b_s[k] = -sqds * e[k - 1] + sm * b_s[k];
        nrm = sqds * e[k];
        e[k] *= sm;
        c_xrot(U, 18 * (k - 1) + 1, 18 * k + 1, sm, sqds);
      }

      e[m] = ztest;
      qq++;
      break;

     default:
      if (b_s[q] < 0.0) {
        b_s[q] = -b_s[q];
        qjj = 18 * q;
        qp1jj = qjj + 18;
        for (k = qjj + 1; k <= qp1jj; k++) {
          Vf[k - 1] = -Vf[k - 1];
        }
      }

      qp1 = q + 1;
      while ((q + 1 < 18) && (b_s[q] < b_s[qp1])) {
        rt = b_s[q];
        b_s[q] = b_s[qp1];
        b_s[qp1] = rt;
        c_xswap(Vf, 18 * q + 1, 18 * (q + 1) + 1);
        c_xswap(U, 18 * q + 1, 18 * (q + 1) + 1);
        q = qp1;
        qp1++;
      }

      qq = 0;
      m--;
      break;
    }
  }

  for (k = 0; k < 18; k++) {
    s[k] = b_s[k];
    memcpy(&V[k * 18], &Vf[k * 18], 18U * sizeof(double));
  }
}

/*
 * Arguments    : const double A[54]
 *                double U[54]
 *                double s[3]
 *                double V[9]
 * Return Type  : void
 */
void svd(const double A[54], double U[54], double s[3], double V[9])
{
  double b_A[54];
  double work[18];
  double Vf[9];
  double b_s[3];
  double e[3];
  double nrm;
  double rt;
  double scale;
  double sm;
  double snorm;
  double sqds;
  double ztest;
  int exitg1;
  int k;
  int kase;
  int m;
  int q;
  int qjj;
  int qp1;
  int qq;
  boolean_T apply_transform;
  boolean_T exitg2;
  memcpy(&b_A[0], &A[0], 54U * sizeof(double));
  b_s[0] = 0.0;
  e[0] = 0.0;
  b_s[1] = 0.0;
  e[1] = 0.0;
  b_s[2] = 0.0;
  e[2] = 0.0;
  memset(&work[0], 0, 18U * sizeof(double));
  memset(&U[0], 0, 54U * sizeof(double));
  memset(&Vf[0], 0, 9U * sizeof(double));
  for (q = 0; q < 3; q++) {
    qp1 = q + 2;
    qq = (q + 18 * q) + 1;
    apply_transform = false;
    nrm = xnrm2(18 - q, b_A, qq);
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
        qjj = (qq - q) + 17;
        for (k = qq; k <= qjj; k++) {
          b_A[k - 1] *= nrm;
        }
      } else {
        qjj = (qq - q) + 17;
        for (k = qq; k <= qjj; k++) {
          b_A[k - 1] /= b_s[q];
        }
      }

      b_A[qq - 1]++;
      b_s[q] = -b_s[q];
    } else {
      b_s[q] = 0.0;
    }

    for (kase = qp1; kase < 4; kase++) {
      qjj = q + 18 * (kase - 1);
      if (apply_transform) {
        xaxpy(18 - q, -(xdotc(18 - q, b_A, qq, b_A, qjj + 1) / b_A[q + 18 * q]),
              qq, b_A, qjj + 1);
      }

      e[kase - 1] = b_A[qjj];
    }

    for (k = q + 1; k < 19; k++) {
      kase = (k + 18 * q) - 1;
      U[kase] = b_A[kase];
    }

    if (q + 1 <= 1) {
      nrm = b_xnrm2(2, e, 2);
      if (nrm == 0.0) {
        e[0] = 0.0;
      } else {
        if (e[1] < 0.0) {
          e[0] = -nrm;
        } else {
          e[0] = nrm;
        }

        nrm = e[0];
        if (fabs(e[0]) >= 1.0020841800044864E-292) {
          nrm = 1.0 / e[0];
          for (k = qp1; k < 4; k++) {
            e[k - 1] *= nrm;
          }
        } else {
          for (k = qp1; k < 4; k++) {
            e[k - 1] /= nrm;
          }
        }

        e[1]++;
        e[0] = -e[0];
        for (k = qp1; k < 19; k++) {
          work[k - 1] = 0.0;
        }

        for (kase = qp1; kase < 4; kase++) {
          b_xaxpy(17, e[kase - 1], b_A, 18 * (kase - 1) + 2, work, 2);
        }

        for (kase = qp1; kase < 4; kase++) {
          c_xaxpy(17, -e[kase - 1] / e[1], work, 2, b_A, 18 * (kase - 1) + 2);
        }
      }

      for (k = qp1; k < 4; k++) {
        Vf[k - 1] = e[k - 1];
      }
    }
  }

  m = 1;
  e[1] = b_A[37];
  e[2] = 0.0;
  for (q = 2; q >= 0; q--) {
    qp1 = q + 2;
    qq = q + 18 * q;
    if (b_s[q] != 0.0) {
      for (kase = qp1; kase < 4; kase++) {
        qjj = (q + 18 * (kase - 1)) + 1;
        xaxpy(18 - q, -(xdotc(18 - q, U, qq + 1, U, qjj) / U[qq]), qq + 1, U,
              qjj);
      }

      for (k = q + 1; k < 19; k++) {
        kase = (k + 18 * q) - 1;
        U[kase] = -U[kase];
      }

      U[qq]++;
      for (k = 0; k < q; k++) {
        U[k + 18 * q] = 0.0;
      }
    } else {
      memset(&U[q * 18], 0, 18U * sizeof(double));
      U[qq] = 1.0;
    }
  }

  for (q = 2; q >= 0; q--) {
    if ((q + 1 <= 1) && (e[0] != 0.0)) {
      d_xaxpy(2, -(b_xdotc(2, Vf, 2, Vf, 5) / Vf[1]), 2, Vf, 5);
      d_xaxpy(2, -(b_xdotc(2, Vf, 2, Vf, 8) / Vf[1]), 2, Vf, 8);
    }

    Vf[3 * q] = 0.0;
    Vf[3 * q + 1] = 0.0;
    Vf[3 * q + 2] = 0.0;
    Vf[q + 3 * q] = 1.0;
  }

  qp1 = 0;
  snorm = 0.0;
  for (q = 0; q < 3; q++) {
    ztest = b_s[q];
    if (ztest != 0.0) {
      rt = fabs(ztest);
      nrm = ztest / rt;
      b_s[q] = rt;
      if (q + 1 < 3) {
        e[q] /= nrm;
      }

      kase = 18 * q;
      qjj = kase + 18;
      for (k = kase + 1; k <= qjj; k++) {
        U[k - 1] *= nrm;
      }
    }

    if (q + 1 < 3) {
      ztest = e[q];
      if (ztest != 0.0) {
        rt = fabs(ztest);
        nrm = rt / ztest;
        e[q] = rt;
        b_s[q + 1] *= nrm;
        kase = 3 * (q + 1);
        qjj = kase + 3;
        for (k = kase + 1; k <= qjj; k++) {
          Vf[k - 1] *= nrm;
        }
      }
    }

    snorm = fmax(snorm, fmax(fabs(b_s[q]), fabs(e[q])));
  }

  while ((m + 2 > 0) && (qp1 < 75)) {
    k = m;
    do {
      exitg1 = 0;
      q = k + 1;
      if (k + 1 == 0) {
        exitg1 = 1;
      } else {
        nrm = fabs(e[k]);
        if ((nrm <= 2.2204460492503131E-16 * (fabs(b_s[k]) + fabs(b_s[k + 1]))) ||
            (nrm <= 1.0020841800044864E-292) || ((qp1 > 20) && (nrm <=
              2.2204460492503131E-16 * snorm))) {
          e[k] = 0.0;
          exitg1 = 1;
        } else {
          k--;
        }
      }
    } while (exitg1 == 0);

    if (k + 1 == m + 1) {
      kase = 4;
    } else {
      qjj = m + 2;
      kase = m + 2;
      exitg2 = false;
      while ((!exitg2) && (kase >= k + 1)) {
        qjj = kase;
        if (kase == k + 1) {
          exitg2 = true;
        } else {
          nrm = 0.0;
          if (kase < m + 2) {
            nrm = fabs(e[kase - 1]);
          }

          if (kase > k + 2) {
            nrm += fabs(e[kase - 2]);
          }

          ztest = fabs(b_s[kase - 1]);
          if ((ztest <= 2.2204460492503131E-16 * nrm) || (ztest <=
               1.0020841800044864E-292)) {
            b_s[kase - 1] = 0.0;
            exitg2 = true;
          } else {
            kase--;
          }
        }
      }

      if (qjj == k + 1) {
        kase = 3;
      } else if (qjj == m + 2) {
        kase = 1;
      } else {
        kase = 2;
        q = qjj;
      }
    }

    switch (kase) {
     case 1:
      ztest = e[m];
      e[m] = 0.0;
      qjj = m + 1;
      for (k = qjj; k >= q + 1; k--) {
        xrotg(&b_s[k - 1], &ztest, &sm, &sqds);
        if (k > q + 1) {
          ztest = -sqds * e[0];
          e[0] *= sm;
        }

        xrot(Vf, 3 * (k - 1) + 1, 3 * (m + 1) + 1, sm, sqds);
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
        b_xrot(U, 18 * (k - 1) + 1, 18 * (q - 1) + 1, sm, sqds);
      }
      break;

     case 3:
      kase = m + 1;
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
      for (k = q + 1; k <= kase; k++) {
        xrotg(&ztest, &nrm, &sm, &sqds);
        if (k > q + 1) {
          e[0] = ztest;
        }

        nrm = e[k - 1];
        rt = b_s[k - 1];
        e[k - 1] = sm * nrm - sqds * rt;
        ztest = sqds * b_s[k];
        b_s[k] *= sm;
        xrot(Vf, 3 * (k - 1) + 1, 3 * k + 1, sm, sqds);
        b_s[k - 1] = sm * rt + sqds * nrm;
        xrotg(&b_s[k - 1], &ztest, &sm, &sqds);
        ztest = sm * e[k - 1] + sqds * b_s[k];
        b_s[k] = -sqds * e[k - 1] + sm * b_s[k];
        nrm = sqds * e[k];
        e[k] *= sm;
        b_xrot(U, 18 * (k - 1) + 1, 18 * k + 1, sm, sqds);
      }

      e[m] = ztest;
      qp1++;
      break;

     default:
      if (b_s[q] < 0.0) {
        b_s[q] = -b_s[q];
        kase = 3 * q;
        qjj = kase + 3;
        for (k = kase + 1; k <= qjj; k++) {
          Vf[k - 1] = -Vf[k - 1];
        }
      }

      qp1 = q + 1;
      while ((q + 1 < 3) && (b_s[q] < b_s[qp1])) {
        rt = b_s[q];
        b_s[q] = b_s[qp1];
        b_s[qp1] = rt;
        xswap(Vf, 3 * q + 1, 3 * (q + 1) + 1);
        b_xswap(U, 18 * q + 1, 18 * (q + 1) + 1);
        q = qp1;
        qp1++;
      }

      qp1 = 0;
      m--;
      break;
    }
  }

  for (k = 0; k < 3; k++) {
    s[k] = b_s[k];
    V[3 * k] = Vf[3 * k];
    kase = 3 * k + 1;
    V[kase] = Vf[kase];
    kase = 3 * k + 2;
    V[kase] = Vf[kase];
  }
}

/*
 * File trailer for svd.c
 *
 * [EOF]
 */
