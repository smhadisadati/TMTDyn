/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sprdmpF25.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 10-Mar-2021 22:46:32
 */

/* Include Files */
#include "sprdmpF25.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * SPRDMPF25
 *     [OUT1,OUT2,OUT3,OUT4,OUT5,OUT6,OUT7] = SPRDMPF25(IN1,IN2,S,DS,T_SYM)
 * Arguments    : const double in1[60]
 *                const double in2[48]
 *                double s
 *                double out1[144]
 *                double out2[6]
 *                double out3[6]
 *                double out4[6]
 *                double *out6
 * Return Type  : void
 */
void sprdmpF25(const double in1[60], const double in2[48], double s, double
               out1[144], double out2[6], double out3[6], double out4[6], double
               *out6)
{
  double t14;
  double t15;
  double t19;
  double t2;
  double t25;
  double t26;
  double t5;
  double t7;
  int i;

  /*     This function was generated by the Symbolic Math Toolbox version 8.6. */
  /*     10-Mar-2021 20:38:33 */
  t2 = in2[1] * s;
  t5 = s * s;
  t7 = in2[0] / 2.0;
  t14 = pow(in1[9], 4.0) + -pow(in1[10], 4.0);
  t15 = (t2 + t7) + in2[2] * t5 * 1.5;
  t2 = ((in1[51] / 2.0 + s * t7) + s * t2 / 2.0) + in2[2] * pow(s, 3.0) / 2.0;
  t7 = cos(t2);
  t2 = sin(t2);
  t19 = t7 * t7;
  t7 = t2 * t2;
  t25 = t19 + t7;
  t26 = s * t19 * 2.0 + s * t7 * 2.0;
  t2 = t5 * t19 * 3.0 + t5 * t7 * 3.0;
  memset(&out1[0], 0, 120U * sizeof(double));
  out1[120] = t25;
  out1[121] = t26;
  out1[122] = t2;
  memset(&out1[123], 0, 21U * sizeof(double));
  out2[0] = 0.0;
  out2[1] = 0.0;
  out2[2] = in1[2] * 3.1415926535897931 * (in1[9] * in1[9] - in1[10] * in1[10]) *
    (t25 - 1.0);
  out2[3] = 0.0;
  out2[4] = 0.0;
  out2[5] = in1[5] * t14 * 3.1415926535897931 * (t15 * t19 * 2.0 + t15 * t7 *
    2.0) / 2.0;
  out3[0] = 0.0;
  out3[1] = 0.0;
  out3[2] = 0.0;
  out3[3] = 0.0;
  out3[4] = 0.0;
  out3[5] = in1[24] * t14 * 3.1415926535897931 * ((t25 * in2[24] + t26 * in2[25])
    + t2 * in2[26]) / 2.0;
  for (i = 0; i < 6; i++) {
    out4[i] = 0.0;
  }

  *out6 = 1.0;
}

/*
 * File trailer for sprdmpF25.c
 *
 * [EOF]
 */