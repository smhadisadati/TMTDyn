/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xgemm.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 14-Oct-2020 22:53:18
 */

/* Include Files */
#include <string.h>
#include "EOM.h"
#include "EOM_input.h"
#include "xgemm.h"

/* Function Definitions */

/*
 * Arguments    : int k
 *                const double A[1024]
 *                const double B[1024]
 *                double C[1024]
 * Return Type  : void
 */
void xgemm(int k, const double A[1024], const double B[1024], double C[1024])
{
  int cr;
  int br;
  int i8;
  int i9;
  int ar;
  int ib;
  int ia;
  int i10;
  int ic;
  for (cr = 0; cr <= 992; cr += 32) {
    i8 = cr + 1;
    i9 = cr + 32;
    if (i8 <= i9) {
      memset(&C[i8 + -1], 0, (unsigned int)(((i9 - i8) + 1) * (int)sizeof(double)));
    }
  }

  br = 0;
  for (cr = 0; cr <= 992; cr += 32) {
    ar = -1;
    br++;
    i8 = br + ((k - 1) << 5);
    for (ib = br; ib <= i8; ib += 32) {
      ia = ar;
      i9 = cr + 1;
      i10 = cr + 32;
      for (ic = i9; ic <= i10; ic++) {
        ia++;
        C[ic - 1] += B[ib - 1] * A[ia];
      }

      ar += 32;
    }
  }
}

/*
 * File trailer for xgemm.c
 *
 * [EOF]
 */
