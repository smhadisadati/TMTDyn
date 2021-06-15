/**************************************************************************
 *
 * function [P,Pu,Pv,Puu,Puv,Pvv]=nrbevalIGES(nurbs,UV,dnurbs,d2nurbs)
 *
 * Evaluates NURBS (and its derivatives) at given parameter values in Matlab.
 *
 * Usage 1 in Matlab (NURBS curve):
 *
 * P=nrbevalIGES(nurbs,UV)
 * [P,Pu]=nrbevalIGES(nurbs,UV,dnurbs)
 * [P,Pu,Puu]=nrbevalIGES(nurbs,UV,dnurbs,d2nurbs)
 *
 * UV - 1xN matrix, N number of u-parameters
 *
 * Usage 2 in Matlab (NURBS surface):
 *
 * P=nrbevalIGES(nurbs,UV)
 * [P,Pu,Pv]=nrbevalIGES(nurbs,UV,dnurbs)
 * [P,Pu,Pv,Puu,Puv,Pvv]=nrbevalIGES(nurbs,UV,dnurbs,d2nurbs)
 *
 * UV - 2xN matrix, N number of (u,v)-parameters
 *
 * Input:
 * nurbs - NURBS structure
 * UV - Parameter values
 * dnurbs,d2nurbs - NURBS derivatives (output from nrbDerivativesIGES).
 *
 * Output:
 * P - Points (evaluated NURBS).
 * Pu,Pv - First derivatives.
 * Puu,Puv,Pvv - Second derivatives.
 *
 * c-file can be downloaded at
 *
 * http://www.mathworks.com/matlabcentral/fileexchange/13253-iges-toolbox
 *
 * compile in Matlab by using the command  "mex nrbevalIGES.c"
 * Remark! The compilation will take a while
 *
 * See "help mex" for more information
 *
 * written by Per Bergström 2015-08-09
 *
 **************************************************************************/

#include <math.h>
#include "mex.h"

/* Input Arguments */

#define	nurbsstructure	prhs[0]
#define parametervalues	prhs[1]
#define	dnurbsstructure	prhs[2]
#define d2nurbsstructure	prhs[3]

/* Output Arguments */

#define	evaluated_points	plhs[0]

#define	d1evaluated_points	plhs[1]
#define	d12evaluated_points	plhs[2]

#define	d2uevaluated_points	plhs[1]
#define	d2vevaluated_points	plhs[2]
#define	d2uuevaluated_points	plhs[3]
#define	d2uvevaluated_points	plhs[4]
#define	d2vvevaluated_points	plhs[5]

/* Sub functions (in folder "mexSourceFiles") */

#include "mexSourceFiles/FindSpan.c"
#include "mexSourceFiles/BasisFuns.c"
#include "mexSourceFiles/BspEval.c"
#include "mexSourceFiles/BspEval2.c"
#include "mexSourceFiles/NURBScurveEval.c"
#include "mexSourceFiles/NURBSsurfaceEval.c"

/* Main function */

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    
    int i, j;
    double *bspPnts, *weightsPnts, *weights, *weights2, mydouble;
    
    if (mxGetM(mxGetField(nurbsstructure, 0, "coefs"))!=4){
        mexPrintf("Number of rows in nurbs.coefs is %d,\n", mxGetM(mxGetField(nurbsstructure, 0, "coefs")));
        mexErrMsgTxt("nurbs.coefs must have 4 rows.");
    }
    if (nlhs==0 || nrhs<2){
        mexErrMsgTxt("Wrong number of inputs or outputs.");
    }
    
    if (mxGetM(parametervalues)==2){
        
        int orderU = (int)mxGetPr(mxGetField(nurbsstructure, 0, "order"))[0];
        int orderV = (int)mxGetPr(mxGetField(nurbsstructure, 0, "order"))[1];
        
        int ncp = (int)mxGetPr(mxGetField(nurbsstructure, 0, "number"))[0];
        int kcp = (int)mxGetPr(mxGetField(nurbsstructure, 0, "number"))[1];
        
        double *leftU  = (double*) malloc(orderU*sizeof(double)+1);
        double *rightU = (double*) malloc(orderU*sizeof(double)+1);
        double *NU = (double*) malloc(orderU*sizeof(double)+1);
        double *leftV  = (double*) malloc(orderV*sizeof(double)+1);
        double *rightV = (double*) malloc(orderV*sizeof(double)+1);
        double *NV = (double*) malloc(orderV*sizeof(double)+1);
        
        if (nlhs==1 && nrhs==2){
            
            evaluated_points = mxCreateDoubleMatrix(3, (unsigned int)mxGetN(parametervalues), mxREAL);
            NURBSsurfaceEval(orderU-1, orderV-1, mxGetPr(mxGetField(nurbsstructure, 0, "coefs")), ncp, kcp, mxGetPr(mxGetCell(mxGetField(nurbsstructure, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nurbsstructure, 0, "knots"), 1)), mxGetPr(parametervalues), (unsigned int)mxGetN(parametervalues), mxGetPr(evaluated_points), leftU, rightU, NU, leftV, rightV, NV);
            
        }
        else if (nlhs==3 && nrhs==3){
            
            evaluated_points = mxCreateDoubleMatrix(3, (unsigned int)mxGetN(parametervalues), mxREAL);
            d2uevaluated_points = mxCreateDoubleMatrix(3, (unsigned int)mxGetN(parametervalues), mxREAL);
            d2vevaluated_points = mxCreateDoubleMatrix(3, (unsigned int)mxGetN(parametervalues), mxREAL);
            NURBSsurfaceDeval(orderU-1, orderV-1, mxGetPr(mxGetField(nurbsstructure, 0, "coefs")), mxGetPr(mxGetField(mxGetCell(dnurbsstructure, 0), 0, "coefs")), mxGetPr(mxGetField(mxGetCell(dnurbsstructure, 1), 0, "coefs")), ncp, kcp, mxGetPr(mxGetCell(mxGetField(nurbsstructure, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nurbsstructure, 0, "knots"), 1)), mxGetPr(parametervalues), (unsigned int)mxGetN(parametervalues), mxGetPr(evaluated_points), mxGetPr(d2uevaluated_points), mxGetPr(d2vevaluated_points), leftU, rightU, NU, leftV, rightV, NV);
            
        }
        else if (nlhs==6 && nrhs==4){
            
            evaluated_points = mxCreateDoubleMatrix(3, (unsigned int)mxGetN(parametervalues), mxREAL);
            d2uevaluated_points = mxCreateDoubleMatrix(3, (unsigned int)mxGetN(parametervalues), mxREAL);
            d2vevaluated_points = mxCreateDoubleMatrix(3, (unsigned int)mxGetN(parametervalues), mxREAL);
            d2uuevaluated_points = mxCreateDoubleMatrix(3, (unsigned int)mxGetN(parametervalues), mxREAL);
            d2uvevaluated_points = mxCreateDoubleMatrix(3, (unsigned int)mxGetN(parametervalues), mxREAL);
            d2vvevaluated_points = mxCreateDoubleMatrix(3, (unsigned int)mxGetN(parametervalues), mxREAL);
            NURBSsurfaceD2eval(orderU-1, orderV-1, mxGetPr(mxGetField(nurbsstructure, 0, "coefs")), mxGetPr(mxGetField(mxGetCell(dnurbsstructure, 0), 0, "coefs")), mxGetPr(mxGetField(mxGetCell(dnurbsstructure, 1), 0, "coefs")), mxGetPr(mxGetField(mxGetCell(d2nurbsstructure, 0), 0, "coefs")), mxGetPr(mxGetField(mxGetCell(d2nurbsstructure, 1), 0, "coefs")), mxGetPr(mxGetField(mxGetCell(d2nurbsstructure, 2), 0, "coefs")), ncp, kcp, mxGetPr(mxGetCell(mxGetField(nurbsstructure, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nurbsstructure, 0, "knots"), 1)), mxGetPr(parametervalues), (unsigned int)mxGetN(parametervalues), mxGetPr(evaluated_points), mxGetPr(d2uevaluated_points), mxGetPr(d2vevaluated_points), mxGetPr(d2uuevaluated_points), mxGetPr(d2uvevaluated_points), mxGetPr(d2vvevaluated_points), leftU, rightU, NU, leftV, rightV, NV);
            
        }
        else{
            
            bspPnts  = (double*) malloc(4*(mxGetN(parametervalues))*sizeof(double)+1);
            
            BspEval2(orderU-1, orderV-1, mxGetPr(mxGetField(nurbsstructure, 0, "coefs")), 4, ncp, kcp, mxGetPr(mxGetCell(mxGetField(nurbsstructure, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nurbsstructure, 0, "knots"), 1)), mxGetPr(parametervalues), (unsigned int)mxGetN(parametervalues), bspPnts, leftU, rightU, NU, leftV, rightV, NV);
            evaluated_points = mxCreateDoubleMatrix(3, (unsigned int)mxGetN(parametervalues), mxREAL);
            for (j = 0; j < mxGetN(parametervalues); j++){
                for (i = 0; i < 3; i++){
                    mxGetPr(evaluated_points)[3*j+i]=(bspPnts[4*j+i])/(bspPnts[4*j+3]);
                }
            }
            
            if (nlhs>1 && nrhs>2){
                
                weightsPnts = (double*) malloc(mxGetN(parametervalues)*sizeof(double)+1);
                for (j = 0; j < mxGetN(parametervalues); j++){
                    weightsPnts[j]=bspPnts[4*j+3];
                }
                
                BspEval2(orderU-2, orderV-1, mxGetPr(mxGetField(mxGetCell(dnurbsstructure, 0), 0, "coefs")), 4, ncp-1, kcp, mxGetPr(mxGetCell(mxGetField(mxGetCell(dnurbsstructure, 0), 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(mxGetCell(dnurbsstructure, 0), 0, "knots"), 1)), mxGetPr(parametervalues), (unsigned int)mxGetN(parametervalues), bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                weights = (double*) malloc((mxGetN(parametervalues))*sizeof(double)+1);
                for (j = 0; j < mxGetN(parametervalues); j++){
                    weights[j]=bspPnts[4*j+3];
                }
                d2uevaluated_points = mxCreateDoubleMatrix(3, (unsigned int)mxGetN(parametervalues), mxREAL);
                for (j = 0; j < mxGetN(parametervalues); j++){
                    for (i = 0; i < 3; i++){
                        mxGetPr(d2uevaluated_points)[3*j+i]=(bspPnts[4*j+i]-(weights[j])*(mxGetPr(evaluated_points)[3*j+i]))/(weightsPnts[j]);
                    }
                }
                
                if (nlhs>2 && nrhs>2){
                    
                    BspEval2(orderU-1, orderV-2, mxGetPr(mxGetField(mxGetCell(dnurbsstructure, 1), 0, "coefs")), 4, ncp, kcp-1, mxGetPr(mxGetCell(mxGetField(mxGetCell(dnurbsstructure, 1), 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(mxGetCell(dnurbsstructure, 1), 0, "knots"), 1)), mxGetPr(parametervalues), (unsigned int)mxGetN(parametervalues), bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                    weights2 = (double*) malloc((mxGetN(parametervalues))*sizeof(double)+1);
                    for (j = 0; j < mxGetN(parametervalues); j++){
                        weights2[j]=(bspPnts[4*j+3]);
                    }
                    d2vevaluated_points = mxCreateDoubleMatrix(3, (unsigned int)mxGetN(parametervalues), mxREAL);
                    for (j = 0; j < mxGetN(parametervalues); j++){
                        for (i = 0; i < 3; i++){
                            mxGetPr(d2vevaluated_points)[3*j+i]=(bspPnts[4*j+i]-(weights2[j])*(mxGetPr(evaluated_points)[3*j+i]))/(weightsPnts[j]);
                        }
                    }
                    
                    if (nlhs>3 && nrhs==4){
                        
                        d2uuevaluated_points = mxCreateDoubleMatrix(3, (unsigned int)mxGetN(parametervalues), mxREAL);
                        if (orderU>2 && orderV>0){
                            BspEval2(orderU-3, orderV-1, mxGetPr(mxGetField(mxGetCell(d2nurbsstructure, 0), 0, "coefs")), 4, ncp-2, kcp, mxGetPr(mxGetCell(mxGetField(mxGetCell(d2nurbsstructure, 0), 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(mxGetCell(d2nurbsstructure, 0), 0, "knots"), 1)), mxGetPr(parametervalues), (unsigned int)mxGetN(parametervalues), bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                            for (j = 0; j < mxGetN(parametervalues); j++){
                                mydouble=2*weights[j];
                                for (i = 0; i < 3; i++){
                                    mxGetPr(d2uuevaluated_points)[3*j+i]=(bspPnts[4*j+i]-mydouble*(mxGetPr(d2uevaluated_points)[3*j+i])-(bspPnts[4*j+3])*(mxGetPr(evaluated_points)[3*j+i]))/(weightsPnts[j]);
                                }
                            }
                        }
                        
                        if (nlhs>4 && nrhs==4){
                            
                            d2uvevaluated_points = mxCreateDoubleMatrix(3, (unsigned int)mxGetN(parametervalues), mxREAL);
                            if (orderU>1 && orderV>1){
                                BspEval2(orderU-2, orderV-2, mxGetPr(mxGetField(mxGetCell(d2nurbsstructure, 1), 0, "coefs")), 4, ncp-1, kcp-1, mxGetPr(mxGetCell(mxGetField(mxGetCell(d2nurbsstructure, 1), 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(mxGetCell(d2nurbsstructure, 1), 0, "knots"), 1)), mxGetPr(parametervalues), (unsigned int)mxGetN(parametervalues), bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                                for (j = 0; j < mxGetN(parametervalues); j++){
                                    for (i = 0; i < 3; i++){
                                        mxGetPr(d2uvevaluated_points)[3*j+i]=(bspPnts[4*j+i]-(weights2[j])*(mxGetPr(d2uevaluated_points)[3*j+i])-(weights[j])*(mxGetPr(d2vevaluated_points)[3*j+i])-(bspPnts[4*j+3])*(mxGetPr(evaluated_points)[3*j+i]))/(weightsPnts[j]);
                                    }
                                }
                            }
                            
                            if (nlhs>5 && nrhs==4){
                                
                                d2vvevaluated_points = mxCreateDoubleMatrix(3, (unsigned int)mxGetN(parametervalues), mxREAL);
                                if (orderU>0 && orderV>2){
                                    BspEval2(orderU-1, orderV-3, mxGetPr(mxGetField(mxGetCell(d2nurbsstructure, 2), 0, "coefs")), 4, ncp, kcp-2, mxGetPr(mxGetCell(mxGetField(mxGetCell(d2nurbsstructure, 2), 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(mxGetCell(d2nurbsstructure, 2), 0, "knots"), 1)), mxGetPr(parametervalues), (unsigned int)mxGetN(parametervalues), bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                                    for (j = 0; j < mxGetN(parametervalues); j++){
                                        mydouble=2*weights2[j];
                                        for (i = 0; i < 3; i++){
                                            mxGetPr(d2vvevaluated_points)[3*j+i]=(bspPnts[4*j+i]-mydouble*(mxGetPr(d2vevaluated_points)[3*j+i])-(bspPnts[4*j+3])*(mxGetPr(evaluated_points)[3*j+i]))/(weightsPnts[j]);
                                        }
                                    }
                                }
                                
                            }
                            
                        }
                        
                    }
                    
                    free(weights2);
                    
                }
                
                free(weights);
                free(weightsPnts);
                
            }
            
            free(bspPnts);
            
        }
        
        free(leftU);
        free(rightU);
        free(NU);
        free(leftV);
        free(rightV);
        free(NV);
        
    }
    
    else if (mxGetM(parametervalues)==1){
        
        int orderU = (int)mxGetScalar(mxGetField(nurbsstructure, 0, "order"));
        
        double *left  = (double*) malloc(orderU*sizeof(double)+1);
        double *right = (double*) malloc(orderU*sizeof(double)+1);
        double *N = (double*) malloc(orderU*sizeof(double)+1);
        
        if (nlhs==1 && nrhs==2){
            
            evaluated_points = mxCreateDoubleMatrix(3, (unsigned int)mxGetN(parametervalues), mxREAL);
            NURBScurveEval(orderU-1, mxGetPr(mxGetField(nurbsstructure, 0, "coefs")), (int)mxGetN(mxGetField(nurbsstructure, 0, "coefs")), mxGetPr(mxGetField(nurbsstructure, 0, "knots")), mxGetPr(parametervalues), (unsigned int)mxGetN(parametervalues), mxGetPr(evaluated_points), left, right, N);
            
        }
        else if (nlhs==2 && nrhs==3){
            
            evaluated_points = mxCreateDoubleMatrix(3, (unsigned int)mxGetN(parametervalues), mxREAL);
            d1evaluated_points = mxCreateDoubleMatrix(3, (unsigned int)mxGetN(parametervalues), mxREAL);
            NURBScurveDeval(orderU-1, mxGetPr(mxGetField(nurbsstructure, 0, "coefs")), mxGetPr(mxGetField(dnurbsstructure, 0, "coefs")), (int)mxGetN(mxGetField(nurbsstructure, 0, "coefs")), mxGetPr(mxGetField(nurbsstructure, 0, "knots")), mxGetPr(parametervalues), (unsigned int)mxGetN(parametervalues), mxGetPr(evaluated_points), mxGetPr(d1evaluated_points), left, right, N);
            
        }
        else if (nlhs==3 && nrhs==4){
            
            evaluated_points = mxCreateDoubleMatrix(3, (unsigned int)mxGetN(parametervalues), mxREAL);
            d1evaluated_points = mxCreateDoubleMatrix(3, (unsigned int)mxGetN(parametervalues), mxREAL);
            d12evaluated_points = mxCreateDoubleMatrix(3, (unsigned int)mxGetN(parametervalues), mxREAL);
            NURBScurveD2eval(orderU-1, mxGetPr(mxGetField(nurbsstructure, 0, "coefs")), mxGetPr(mxGetField(dnurbsstructure, 0, "coefs")), mxGetPr(mxGetField(d2nurbsstructure, 0, "coefs")), (int)mxGetN(mxGetField(nurbsstructure, 0, "coefs")), mxGetPr(mxGetField(nurbsstructure, 0, "knots")), mxGetPr(parametervalues), (unsigned int)mxGetN(parametervalues), mxGetPr(evaluated_points), mxGetPr(d1evaluated_points), mxGetPr(d12evaluated_points), left, right, N);
            
        }
        else{
            
            bspPnts  = (double*) malloc(4*(mxGetN(parametervalues))*sizeof(double)+1);
            
            BspEval(orderU-1, mxGetPr(mxGetField(nurbsstructure, 0, "coefs")), 4, (int)mxGetN(mxGetField(nurbsstructure, 0, "coefs")), mxGetPr(mxGetField(nurbsstructure, 0, "knots")), mxGetPr(parametervalues), (unsigned int)mxGetN(parametervalues), bspPnts, left, right, N);
            evaluated_points = mxCreateDoubleMatrix(3, (unsigned int)mxGetN(parametervalues), mxREAL);
            for (j = 0; j < mxGetN(parametervalues); j++){
                for (i = 0; i < 3; i++){
                    mxGetPr(evaluated_points)[3*j+i]=(bspPnts[4*j+i])/(bspPnts[4*j+3]);
                }
            }
            
            if (nlhs>1 && nrhs>2){
                
                weightsPnts = (double*) malloc(mxGetN(parametervalues)*sizeof(double)+1);
                for (j = 0; j < mxGetN(parametervalues); j++){
                    weightsPnts[j]=bspPnts[4*j+3];
                }
                
                BspEval(orderU-2, mxGetPr(mxGetField(dnurbsstructure, 0, "coefs")), 4, (int)mxGetN(mxGetField(dnurbsstructure, 0, "coefs")), mxGetPr(mxGetField(dnurbsstructure, 0, "knots")), mxGetPr(parametervalues), (unsigned int)mxGetN(parametervalues), bspPnts, left, right, N);
                weights = (double*) malloc((mxGetN(parametervalues))*sizeof(double)+1);
                for (j = 0; j < mxGetN(parametervalues); j++){
                    weights[j]=bspPnts[4*j+3];
                }
                d1evaluated_points = mxCreateDoubleMatrix(3, (unsigned int)mxGetN(parametervalues), mxREAL);
                for (j = 0; j < mxGetN(parametervalues); j++){
                    for (i = 0; i < 3; i++){
                        mxGetPr(d1evaluated_points)[3*j+i]=(bspPnts[4*j+i]-(weights[j])*(mxGetPr(evaluated_points)[3*j+i]))/(weightsPnts[j]);
                    }
                }
                
                if (nlhs>2 && nrhs==4){
                    
                    d12evaluated_points = mxCreateDoubleMatrix(3, (unsigned int)mxGetN(parametervalues), mxREAL);
                    if (orderU>2){
                        BspEval(orderU-3, mxGetPr(mxGetField(d2nurbsstructure, 0, "coefs")), 4, (int)mxGetN(mxGetField(d2nurbsstructure, 0, "coefs")), mxGetPr(mxGetField(d2nurbsstructure, 0, "knots")), mxGetPr(parametervalues), (unsigned int)mxGetN(parametervalues), bspPnts, left, right, N);
                        for (j = 0; j < mxGetN(parametervalues); j++){
                            for (i = 0; i < 3; i++){
                                mxGetPr(d12evaluated_points)[3*j+i]=(bspPnts[4*j+i]-2*(weights[j])*(mxGetPr(d1evaluated_points)[3*j+i])-(bspPnts[4*j+3])*(mxGetPr(evaluated_points)[3*j+i]))/(weightsPnts[j]);
                            }
                        }
                    }
                    
                }
                
                free(weights);
                free(weightsPnts);
                
            }
            
            free(bspPnts);
            
        }
        
        free(left);
        free(right);
        free(N);
        
    }
    
    else{
        mexErrMsgTxt("Wrong dimension of UV");
    }
    
}
