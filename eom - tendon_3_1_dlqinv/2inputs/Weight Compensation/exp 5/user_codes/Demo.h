/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.h
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 18-Aug-2019 19:27:35
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
#ifndef MAIN_H
#define MAIN_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "EOM_types.h"

/* Function Declarations */
extern int main();

#endif

/*
 * File trailer for main.h
 *
 * [EOF]
 */

////////////////////////////////////////////////////////////////////////////////////
/* Problem Constants */
#define STATES_NO RCONST(38) /* CHANGE THIS ACCORDING TO YOUR PROBLEM */

#define RTOL RCONST(1.0e-2)  /* scalar relative tolerance            */
#define ATOL RCONST(1.0e-2)  /* vector absolute tolerance components */
#define RTOLF RCONST(1.0e-5)  /* fine tol.s */
#define ATOLF RCONST(1.0e-6)  
#define MXSTEP_DEFAULT RCONST(1.0e9)
#define INITIAL_STEP RCONST(1.0e-23)

#define ZERO  RCONST(0.0)
////////////////////////////////////////////////////////////////////////////////////
