/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 14-Oct-2020 22:53:18
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/
/* Include Files */
#include "EOM.h"
#include "EOM_input.h"
#include "main.h"
#include "EOM_terminate.h"
#include "EOM_initialize.h"

/* Function Declarations */
static void argInit_1x58_real_T(double result[58]);
static void argInit_32x4_real_T(double result[128]);
static void argInit_32x7_real_T(double result[224]);
static void argInit_64x1_real_T(double result[64]);
static double argInit_real_T(void);
static void argInit_struct0_T(struct0_T *result);
static void argInit_struct1_T(struct1_T *result);
static void argInit_struct2_T(struct2_T *result);
static void argInit_struct3_T(struct3_T *result);
static void main_EOM(void);
static void main_EOM_input(void);

/* Function Definitions */

/*
 * Arguments    : double result[58]
 * Return Type  : void
 */
static void argInit_1x58_real_T(double result[58])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 58; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

/*
 * Arguments    : double result[128]
 * Return Type  : void
 */
static void argInit_32x4_real_T(double result[128])
{
  int idx0;
  double result_tmp;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 32; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result_tmp = argInit_real_T();
    result[idx0] = result_tmp;

    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0 + 32] = result_tmp;

    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0 + 64] = argInit_real_T();

    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0 + 96] = argInit_real_T();
  }
}

/*
 * Arguments    : double result[224]
 * Return Type  : void
 */
static void argInit_32x7_real_T(double result[224])
{
  int idx0;
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 32; idx0++) {
    for (idx1 = 0; idx1 < 7; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result[idx0 + (idx1 << 5)] = argInit_real_T();
    }
  }
}

/*
 * Arguments    : double result[64]
 * Return Type  : void
 */
static void argInit_64x1_real_T(double result[64])
{
  int idx0;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 64; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0] = argInit_real_T();
  }
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : struct0_T *result
 * Return Type  : void
 */
static void argInit_struct0_T(struct0_T *result)
{
  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  argInit_struct1_T(&result->user_pars);
  argInit_1x58_real_T(result->var);
  result->t_equil_i = argInit_real_T();
}

/*
 * Arguments    : struct1_T *result
 * Return Type  : void
 */
static void argInit_struct1_T(struct1_T *result)
{
  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  result->n_t = argInit_real_T();
  argInit_struct2_T(&result->motor_in);
  argInit_struct3_T(&result->tip_pos);
}

/*
 * Arguments    : struct2_T *result
 * Return Type  : void
 */
static void argInit_struct2_T(struct2_T *result)
{
  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  argInit_32x7_real_T(result->pos);
}

/*
 * Arguments    : struct3_T *result
 * Return Type  : void
 */
static void argInit_struct3_T(struct3_T *result)
{
  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  argInit_32x4_real_T(result->tube2);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_EOM(void)
{
  double dv2[64];
  struct0_T r0;
  double dz[64];
  double flag;

  /* Initialize function 'EOM' input arguments. */
  /* Initialize function input argument 'z'. */
  /* Initialize function input argument 'par_mex'. */
  /* Call the entry-point 'EOM'. */
  argInit_64x1_real_T(dv2);
  argInit_struct0_T(&r0);
  EOM(argInit_real_T(), dv2, &r0, dz, &flag);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_EOM_input(void)
{
  double tspan[3];
  double nz;
  double z0[64];
  struct0_T par_mex;

  /* Call the entry-point 'EOM_input'. */
  EOM_input(tspan, &nz, z0, &par_mex);
}

/*
 * Arguments    : int argc
 *                const char * const argv[]
 * Return Type  : int
 */
int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  EOM_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_EOM();
  main_EOM_input();

  /* Terminate the application.
     You do not need to do this more than one time. */
  EOM_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
