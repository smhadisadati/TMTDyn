/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 08-May-2021 01:57:20
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
#include "main.h"
#include "EOM.h"
#include "EOM_input.h"
#include "EOM_terminate.h"
#include "EOM_types.h"

/* Function Declarations */
static void argInit_14584x4_real_T(double result[58336]);
static void argInit_14587x5_real_T(double result[72935]);
static void argInit_14587x6_real_T(double result[87522]);
static void argInit_1x33_real_T(double result[33]);
static void argInit_38x1_real_T(double result[38]);
static double argInit_real_T(void);
static void argInit_struct0_T(struct0_T *result);
static void argInit_struct1_T(struct1_T *result);
static void argInit_struct2_T(struct2_T *result);
static void argInit_struct3_T(struct3_T *result);
static void main_EOM(void);
static void main_EOM_input(void);

/* Function Definitions */
/*
 * Arguments    : double result[58336]
 * Return Type  : void
 */
static void argInit_14584x4_real_T(double result[58336])
{
  int idx0;
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 14584; idx0++) {
    for (idx1 = 0; idx1 < 4; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result[idx0 + 14584 * idx1] = argInit_real_T();
    }
  }
}

/*
 * Arguments    : double result[72935]
 * Return Type  : void
 */
static void argInit_14587x5_real_T(double result[72935])
{
  int idx0;
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 14587; idx0++) {
    for (idx1 = 0; idx1 < 5; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result[idx0 + 14587 * idx1] = argInit_real_T();
    }
  }
}

/*
 * Arguments    : double result[87522]
 * Return Type  : void
 */
static void argInit_14587x6_real_T(double result[87522])
{
  int idx0;
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 14587; idx0++) {
    for (idx1 = 0; idx1 < 6; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result[idx0 + 14587 * idx1] = argInit_real_T();
    }
  }
}

/*
 * Arguments    : double result[33]
 * Return Type  : void
 */
static void argInit_1x33_real_T(double result[33])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 33; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

/*
 * Arguments    : double result[38]
 * Return Type  : void
 */
static void argInit_38x1_real_T(double result[38])
{
  int idx0;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 38; idx0++) {
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
  argInit_1x33_real_T(result->var);
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
  argInit_14587x5_real_T(result->tip_load);
}

/*
 * Arguments    : struct2_T *result
 * Return Type  : void
 */
static void argInit_struct2_T(struct2_T *result)
{
  double d;
  int i;

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  argInit_14587x6_real_T(result->pos);
  for (i = 0; i < 87522; i++) {
    d = result->pos[i];
    result->vel[i] = d;
    result->acc[i] = d;
  }
}

/*
 * Arguments    : struct3_T *result
 * Return Type  : void
 */
static void argInit_struct3_T(struct3_T *result)
{
  double d;
  int i;

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  argInit_14584x4_real_T(result->tube1);
  for (i = 0; i < 58336; i++) {
    d = result->tube1[i];
    result->tube1_vel[i] = d;
    result->tube1_acc[i] = d;
  }
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_EOM(void)
{
  static struct0_T r;
  double dv[38];
  double dz[38];
  double flag;

  /* Initialize function 'EOM' input arguments. */
  /* Initialize function input argument 'z'. */
  /* Initialize function input argument 'par_mex'. */
  /* Call the entry-point 'EOM'. */
  argInit_38x1_real_T(dv);
  argInit_struct0_T(&r);
  EOM(argInit_real_T(), dv, &r, dz, &flag);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_EOM_input(void)
{
  static struct0_T par_mex;
  double z0[38];
  double tspan[3];
  double nz;

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

  /* The initialize function is being called automatically from your entry-point function. So, a call to initialize is not included here. */
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
