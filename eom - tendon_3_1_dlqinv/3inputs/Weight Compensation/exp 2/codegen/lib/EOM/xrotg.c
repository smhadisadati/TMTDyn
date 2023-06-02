/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xrotg.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 08-May-2021 03:55:48
 */

/* Include Files */
#include "xrotg.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : double *a
 *                double *b
 *                double *c
 *                double *s
 * Return Type  : void
 */
void xrotg(double *a, double *b, double *c, double *s)
{
  double absa;
  double absb;
  double ads;
  double bds;
  double roe;
  double scale;
  roe = *b;
  absa = fabs(*a);
  absb = fabs(*b);
  if (absa > absb) {
    roe = *a;
  }

  scale = absa + absb;
  if (scale == 0.0) {
    *s = 0.0;
    *c = 1.0;
    *a = 0.0;
    *b = 0.0;
  } else {
    ads = absa / scale;
    bds = absb / scale;
    scale *= sqrt(ads * ads + bds * bds);
    if (roe < 0.0) {
      scale = -scale;
    }

    *c = *a / scale;
    *s = *b / scale;
    if (absa > absb) {
      *b = *s;
    } else if (*c != 0.0) {
      *b = 1.0 / *c;
    } else {
      *b = 1.0;
    }

    *a = scale;
  }
}

/*
 * File trailer for xrotg.c
 *
 * [EOF]
 */
