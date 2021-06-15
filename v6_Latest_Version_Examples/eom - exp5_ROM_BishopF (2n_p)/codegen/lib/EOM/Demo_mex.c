/* -----------------------------------------------------------------
 * Programmer(s): Scott D. Cohen, Alan C. Hindmarsh and
 *                Radu Serban @ LLNL
 * -----------------------------------------------------------------
 * SUNDIALS Copyright Start
 * Copyright (c) 2002-2019, Lawrence Livermore National Security
 * and Southern Methodist University.
 * All rights reserved.
 *
 * See the top-level LICENSE and NOTICE files for details.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * SUNDIALS Copyright End
 * -----------------------------------------------------------------
 * Original CVode Example problem:
 * 
 * The following is a simple example problem, with the coding
 * needed for its solution by CVODE. The problem is from
 * chemical kinetics, and consists of the following three rate
 * equations:         
 *    dy1/dt = -.04*y1 + 1.e4*y2*y3
 *    dy2/dt = .04*y1 - 1.e4*y2*y3 - 3.e7*(y2)^2
 *    dy3/dt = 3.e7*(y2)^2
 * on the interval from t = 0.0 to t = 4.e10, with initial
 * conditions: y1 = 1.0, y2 = y3 = 0. The problem is stiff.
 * While integrating the system, we also use the rootfinding
 * feature to find the points at which y1 = 1e-4 or at which
 * y3 = 0.01. This program solves the problem with the BDF method,
 * Newton iteration with the SUNDENSE dense linear solver, and a
 * user-supplied Jacobian routine.
 * It uses a scalar relative tolerance and a vector absolute
 * tolerance. Output is printed in decades from t = .4 to t = 4.e10.
 * Run statistics (optional outputs) are printed at the end.
 * -----------------------------------------------------------------*/
// general
#include <stdio.h>
#include <time.h>

// mex
#include "mex.h"

// sundials
#include <cvode/cvode.h>               /* prototypes for CVODE fcts., consts.  */
#include <nvector/nvector_serial.h>    /* access to serial N_Vector            */
#include <sunmatrix/sunmatrix_dense.h> /* access to dense SUNMatrix            */
#include <sunlinsol/sunlinsol_dense.h> /* access to dense SUNLinearSolver      */
#include <sundials/sundials_types.h>   /* defs. of realtype, sunindextype      */

/* Include EOM Files */
#include <string.h>
#include "EOM.h"
#include "EOM_input.h"
#include "Demo.h"

#if defined(SUNDIALS_EXTENDED_PRECISION)
#define GSYM "Lg"
#define ESYM "Le"
#define FSYM "Lf"
#else
#define GSYM "g"
#define ESYM "e"
#define FSYM "f"
#endif

/* User-defined vector and matrix accessor macros: Ith, IJth */

/* These macros are defined in order to write code which exactly matches
   the mathematical problem description given above.

   Ith(v,i) references the (i+1)th component of the vector v
   
   IJth(A,i,j) references the (i+1,j+1)th element of the dense matrix A */

#define Ith(v,i)    NV_Ith_S(v,i)         /* Ith numbers components 1..NEQ */
#define IJth(A,i,j) SM_ELEMENT_D(A,i,j) /* IJth numbers rows,cols 1..NEQ */


////////////////////////////////////////////////////////////////////////////////////
/* to compile & run:
mex windows:
mex -IC:\sundials-5.6.1\instdir\include -LC:\sundials-5.6.1\instdir -lsundials_cvode *.c
Demo_mex
///////////////////////////////////////////////////////////////////////////////////*
/* Problem Constants */
#define STATES_NO RCONST(32) /* CHANGE THIS ACCORDING TO YOUR PROBLEM */

#define RTOL RCONST(1.0e-1)  /* scalar relative tolerance            */
#define ATOL RCONST(1.0e-2)  /* vector absolute tolerance components */
#define RTOLF RCONST(1.0e-5)  /* fine tol.s */
#define ATOLF RCONST(1.0e-6)  
#define MXSTEP_DEFAULT RCONST(1.0e9)
#define INITIAL_STEP RCONST(1.0e-23)

#define ZERO  RCONST(0.0)
////////////////////////////////////////////////////////////////////////////////////


// global variables
double NEQ; /* number of equations  */
struct0_T par_mex; /* user inputs */

/* Functions Called by the Solver */

static int f(realtype t, N_Vector y, N_Vector ydot, void *user_data);

/* Private function to print final statistics */

static void PrintFinalStats(void *cvode_mem);

/* Private function to check function return values */

static int check_retval(void *returnvalue, const char *funcname, int opt);


/*
 *-------------------------------
 * Main Program
 *-------------------------------
 */

// void main()
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  realtype reltol, reltolf, t, tout;
  N_Vector y, yt, abstol, abstolf;
  SUNMatrix A;
  SUNLinearSolver LS;
  void *cvode_mem;
  int retval, retvalr, iout;
  int rootsfound[2];
  bool isTolRefined;
    
  y = abstol = NULL;
  A = NULL;
  LS = NULL;
  cvode_mem = NULL;
  isTolRefined = false;
  
  // EOM arguments
  double tspan[3];
  double z0[STATES_NO]; /* initial y components */
    
  /* Call the entry-point 'EOM_input'. */
  EOM_input(tspan, &NEQ, z0, &par_mex);
  
  const int imax = RCONST( ( tspan[2] - tspan[0] ) / tspan[1] );
  const int jmax = RCONST( NEQ );
  // realtype yout[imax][jmax];

  /* Create serial vector of length NEQ for I.C. and abstol */
  y = N_VNew_Serial(NEQ);
  if (check_retval((void *)y, "N_VNew_Serial", 0)) return;
  abstol = N_VNew_Serial(NEQ); 
  abstolf = N_VNew_Serial(NEQ); 
  if (check_retval((void *)abstol, "N_VNew_Serial", 0)) return;

  /* Initialize y */
  for (int i = 0; i < NEQ; i++) {
    Ith(y,i) = z0[i];
    /* Set the vector absolute tolerance */
    Ith(abstol,i) = ATOL;
    Ith(abstolf,i) = ATOLF;
	}
  yt = y;

  /* Set the scalar relative tolerance */
  reltol = RTOL;
  reltolf = RTOLF;
  
  double T0 = tspan[0]; /* initial time           */

  /* Call CVodeCreate to create the solver memory and specify the 
   * Backward Differentiation Formula */
  cvode_mem = CVodeCreate(CV_BDF);
  if (check_retval((void *)cvode_mem, "CVodeCreate", 0)) return;
  
  /* Call CVodeInit to initialize the integrator memory and specify the
   * user's right hand side function in y'=f(t,y), the inital time T0, and
   * the initial dependent variable vector y. */
  retval = CVodeInit(cvode_mem, f, T0, y);
  if (check_retval(&retval, "CVodeInit", 1)) return;

  /* Call CVodeSVtolerances to specify the scalar relative tolerance
   * and vector absolute tolerances */
  retval = CVodeSVtolerances(cvode_mem, reltol, abstol);
  if (check_retval(&retval, "CVodeSVtolerances", 1)) return;
  
  // CVodeSetMaxNumSteps 
  retval = CVodeSetMaxNumSteps(cvode_mem, MXSTEP_DEFAULT);
  if (check_retval(&retval, "CVodeSetMaxNumSteps", 1)) return;
  
  // CVodeSetInitStep
  retval = CVodeSetInitStep(cvode_mem, INITIAL_STEP);
  if (check_retval(&retval, "CVodeSetInitStep", 1)) return;

  /* Create dense SUNMatrix for use in linear solves */
  A = SUNDenseMatrix(NEQ, NEQ);
  if(check_retval((void *)A, "SUNDenseMatrix", 0)) return;

  /* Create dense SUNLinearSolver object for use by CVode */
  LS = SUNLinSol_Dense(y, A);
  if(check_retval((void *)LS, "SUNLinSol_Dense", 0)) return;

  /* Call CVodeSetLinearSolver to attach the matrix and linear solver to CVode */
  retval = CVodeSetLinearSolver(cvode_mem, LS, A);
  if(check_retval(&retval, "CVodeSetLinearSolver", 1)) return;
  
  // prepare .txt file
  FILE *yout_file = fopen("results.txt", "w");
  if (yout_file == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }

  /* In loop, call CVode, print results, and test for error.
     Break out of loop when NOUT preset output times have been reached.  */
  printf(" \nODE run...\n\n");

  iout = 0;  tout = tspan[0] + tspan[1];
  clock_t tsim0 = clock();
  while(1) {
    retval = CVode(cvode_mem, tout, y, &t, CV_NORMAL);

    // if (check_retval(&retval, "CVode", 1)) break;
    if (check_retval(&retval, "CVode", 1)) { // switch to fine par.s
      isTolRefined = true;
      CVodeInit(cvode_mem, f, tout-tspan[1], yt);
      // CVodeSVtolerances(cvode_mem, reltolf, abstolf); // fine tol.s
      CVodeSVtolerances(cvode_mem, reltol, abstol);
      CVodeSetMaxNumSteps(cvode_mem, MXSTEP_DEFAULT);
      CVodeSetInitStep(cvode_mem, INITIAL_STEP);
      A = SUNDenseMatrix(NEQ, NEQ);
      LS = SUNLinSol_Dense(yt, A);
      CVodeSetLinearSolver(cvode_mem, LS, A);
      continue; // repeat previous step
    }
    // if (isTolRefined) { // reset to normal par.s
    //   isTolRefined = false;
    //   CVodeInit(cvode_mem, f, tout, y);
    //   CVodeSVtolerances(cvode_mem, reltol, abstol); // normal tol.s
    //   CVodeSetMaxNumSteps(cvode_mem, MXSTEP_DEFAULT);
    //   CVodeSetInitStep(cvode_mem, INITIAL_STEP);
    //   A = SUNDenseMatrix(NEQ, NEQ);
    //   LS = SUNLinSol_Dense(y, A);
    //   CVodeSetLinearSolver(cvode_mem, LS, A);
    // }
    yt = y;
        
    if (retval == CV_SUCCESS) {
      printf("t = %f [s]\n",t);
      fprintf(yout_file, "%f", t); // file print data
      for (int i = 0; i < NEQ; i++) {
        // yout[iout][i] = Ith(y,i); // store data
        // printf("%f ", yout[iout][i]); // terminal print data
        // fprintf(yout_file, "\t%f", yout[iout][i]); // file print data
        fprintf(yout_file, "\t%f", Ith(y,i)); // file print data
      }
      //printf("\n");
      fprintf(yout_file, "\n");
      // iout++;
      tout += tspan[1];
    }
    if (tout > tspan[2]) break;
  }
  // simulation time in sec
  float tsim = ( clock() - tsim0 ) / CLOCKS_PER_SEC ;
  float tsim_exp = tsim / ( tspan[2]-tspan[0] );
  printf("\nexp time = %f [s]\nsim time = %f [s]\nsim_to_exp time = %f [s]\n", tspan[2]-tspan[0], tsim, tsim_exp);

  // close result file  
  fclose(yout_file);
  

  /* Print some final statistics */
  PrintFinalStats(cvode_mem);

  /* Free y and abstol vectors */
  N_VDestroy(y);
  N_VDestroy(abstol);

  /* Free integrator memory */
  CVodeFree(&cvode_mem);

  /* Free the linear solver memory */
  SUNLinSolFree(LS);

  /* Free the matrix memory */
  SUNMatDestroy(A);

  return;
}


/*
 *-------------------------------
 * Functions called by the solver
 *-------------------------------
 */

/*
 * f routine. Compute function f(t,y). 
 */

static int f(realtype t, N_Vector y, N_Vector ydot, void *user_data)
{		  
  double z[STATES_NO];
  double dz[STATES_NO];
  double flag;
    
  for (int i = 0; i < NEQ; i++)
    z[i] = Ith(y,i);

  /* Initialize function 'EOM' input arguments. */
  /* Initialize function input argument 'z'. */
  /* Initialize function input argument 'par_mex'. */
  /* Call the entry-point 'EOM'. */
  // EOM(t, y, &par_mex, ydot, &flag);
  EOM(t, z, &par_mex, dz, &flag);
  
  for (int i = 0; i < NEQ; i++)
    Ith(ydot,i) = dz[i];

  return(0);
}

/* 
 * Get and print some final statistics
 */

static void PrintFinalStats(void *cvode_mem)
{
  long int nst, nfe, nsetups, nje, nfeLS, nni, ncfn, netf, nge;
  int retval;

  retval = CVodeGetNumSteps(cvode_mem, &nst);
  check_retval(&retval, "CVodeGetNumSteps", 1);
  retval = CVodeGetNumRhsEvals(cvode_mem, &nfe);
  check_retval(&retval, "CVodeGetNumRhsEvals", 1);
  retval = CVodeGetNumLinSolvSetups(cvode_mem, &nsetups);
  check_retval(&retval, "CVodeGetNumLinSolvSetups", 1);
  retval = CVodeGetNumErrTestFails(cvode_mem, &netf);
  check_retval(&retval, "CVodeGetNumErrTestFails", 1);
  retval = CVodeGetNumNonlinSolvIters(cvode_mem, &nni);
  check_retval(&retval, "CVodeGetNumNonlinSolvIters", 1);
  retval = CVodeGetNumNonlinSolvConvFails(cvode_mem, &ncfn);
  check_retval(&retval, "CVodeGetNumNonlinSolvConvFails", 1);

  retval = CVodeGetNumJacEvals(cvode_mem, &nje);
  check_retval(&retval, "CVodeGetNumJacEvals", 1);
  retval = CVodeGetNumLinRhsEvals(cvode_mem, &nfeLS);
  check_retval(&retval, "CVodeGetNumLinRhsEvals", 1);

  retval = CVodeGetNumGEvals(cvode_mem, &nge);
  check_retval(&retval, "CVodeGetNumGEvals", 1);

  printf("\nFinal Statistics:\n");
  printf("nst = %-6ld nfe  = %-6ld nsetups = %-6ld nfeLS = %-6ld nje = %ld\n",
	 nst, nfe, nsetups, nfeLS, nje);
  printf("nni = %-6ld ncfn = %-6ld netf = %-6ld nge = %ld\n \n",
	 nni, ncfn, netf, nge);
}

/*
 * Check function return value...
 *   opt == 0 means SUNDIALS function allocates memory so check if
 *            returned NULL pointer
 *   opt == 1 means SUNDIALS function returns an integer value so check if
 *            retval < 0
 *   opt == 2 means function allocates memory so check if returned
 *            NULL pointer 
 */

static int check_retval(void *returnvalue, const char *funcname, int opt)
{
  int *retval;

  /* Check if SUNDIALS function returned NULL pointer - no memory allocated */
  if (opt == 0 && returnvalue == NULL) {
    fprintf(stderr, "\nSUNDIALS_ERROR: %s() failed - returned NULL pointer\n\n",
	    funcname);
    return(1); }

  /* Check if retval < 0 */
  else if (opt == 1) {
    retval = (int *) returnvalue;
    if (*retval < 0) {
      fprintf(stderr, "\nSUNDIALS_ERROR: %s() failed with retval = %d\n\n",
	      funcname, *retval);
      return(1); }}

  /* Check if function returned NULL pointer - no memory allocated */
  else if (opt == 2 && returnvalue == NULL) {
    fprintf(stderr, "\nMEMORY_ERROR: %s() failed - returned NULL pointer\n\n",
	    funcname);
    return(1); }

  return(0);
}

