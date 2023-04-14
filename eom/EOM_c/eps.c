/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: eps.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 14-Oct-2020 16:42:47
 */

/* Include Files */
#include <math.h>
#include "EOM.h"
#include "EOM_input.h"
#include "eps.h"

/* Function Definitions */

/*
 * Arguments    : double x
 * Return Type  : double
 */
double eps(double x)
{
  double r;
  double absxk;
  int exponent;
  absxk = fabs(x);
  if (absxk <= 2.2250738585072014E-308) {
    r = 4.94065645841247E-324;
  } else {
    frexp(absxk, &exponent);
    r = ldexp(1.0, exponent - 53);
  }

  return r;
}

/*
 * File trailer for eps.c
 *
 * [EOF]
 */
