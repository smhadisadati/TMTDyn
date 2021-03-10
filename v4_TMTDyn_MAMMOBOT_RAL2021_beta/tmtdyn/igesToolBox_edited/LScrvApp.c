
/* mex -v LScrvApp.c */

#include <math.h>
#include "mex.h"

/* Input Arguments Qmatrix,nrbDeg,numCtrlPnts,ubar,knots */

#define	Qmatrix	prhs[0]
#define nrbDeg	prhs[1]
#define	numCtrlPnts	prhs[2]
#define ubar	prhs[3]
#define knots	prhs[4]

#define coefs	prhs[5]

#define CtrlPntsEqInd	prhs[6]
#define CtrlPntsEqWgh	prhs[7]

#define startQ	prhs[6]
#define endQ	prhs[7]

#define startEqQ	prhs[8]
#define endEqQ	prhs[9]

/* Output Arguments */

#define	NTN	plhs[0]
#define	Rmatrix	plhs[1]


/* Sub functions (in folder "mexSourceFiles") */

#include "mexSourceFiles/FindSpan.c"
#include "mexSourceFiles/BasisFuns.c"
#include "mexSourceFiles/LScurveApp.c"


/* Main function */

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    
    /* Originates from section 9.4.1, The NURBS Book, L.Piegl and W. Tiller */
    /* Least Squares Curve Approximation */
    
    double *left, *right, *N;
    
    if (nlhs<2){
        mexErrMsgTxt("Wrong number of output arguments.");
    }
    else if (!(nrhs==5 || nrhs==6 || nrhs==8 || nrhs==10)){
        mexErrMsgTxt("Wrong number of input arguments.");
    }    
    
    left  = (double*)malloc(((int)mxGetScalar(nrbDeg)+1)*sizeof(double)+1);
    right = (double*)malloc(((int)mxGetScalar(nrbDeg)+1)*sizeof(double)+1);
    N = (double*)malloc(((int)mxGetScalar(nrbDeg)+1)*sizeof(double)+1);

    if (nrhs == 5){
        NTN = mxCreateDoubleMatrix((int)mxGetScalar(numCtrlPnts)-2, (int)mxGetScalar(numCtrlPnts)-2, mxREAL);
        Rmatrix = mxCreateDoubleMatrix(((int)mxGetScalar(numCtrlPnts)-2), (int)mxGetM(Qmatrix), mxREAL);
        
        LScurveApp((int)mxGetScalar(nrbDeg), (int)mxGetScalar(numCtrlPnts), mxGetPr(knots), mxGetPr(ubar), (int)mxGetM(Qmatrix), (int)mxGetN(Qmatrix), mxGetPr(Qmatrix), &mxGetPr(Qmatrix)[0], &mxGetPr(Qmatrix)[((int)mxGetM(Qmatrix))*((int)mxGetN(Qmatrix)-1)], mxGetPr(NTN), mxGetPr(Rmatrix), left, right, N);
    }
    
    else if (nrhs == 6){
        NTN = mxCreateDoubleMatrix((int)mxGetScalar(numCtrlPnts)-2, (int)mxGetScalar(numCtrlPnts)-2, mxREAL);
        Rmatrix = mxCreateDoubleMatrix(((int)mxGetScalar(numCtrlPnts)-2), (int)mxGetM(Qmatrix), mxREAL);
        
        LScurveAppNUwghs((int)mxGetScalar(nrbDeg), (int)mxGetScalar(numCtrlPnts), mxGetPr(knots), mxGetPr(ubar), (int)mxGetM(Qmatrix), (int)mxGetN(Qmatrix), mxGetPr(Qmatrix), &mxGetPr(Qmatrix)[0], &mxGetPr(Qmatrix)[((int)mxGetM(Qmatrix))*((int)mxGetN(Qmatrix)-1)], mxGetPr(coefs), mxGetPr(NTN), mxGetPr(Rmatrix), left, right, N);
    }    
    
    else if (nrhs == 10){ 
        NTN = mxCreateDoubleMatrix((int)mxGetScalar(numCtrlPnts)-2, (int)mxGetScalar(numCtrlPnts)-2, mxREAL);
        Rmatrix = mxCreateDoubleMatrix(((int)mxGetScalar(numCtrlPnts)-2), 2, mxREAL);
        
        LScurveAppEqPntStartEnd((int)mxGetScalar(nrbDeg), (int)mxGetScalar(numCtrlPnts), mxGetPr(knots), mxGetPr(ubar), (int)mxGetN(Qmatrix), mxGetPr(Qmatrix), (unsigned int*)mxGetPr(CtrlPntsEqInd), (int)mxGetN(CtrlPntsEqInd), mxGetScalar(CtrlPntsEqWgh), mxGetPr(coefs), mxGetPr(startEqQ), mxGetPr(endEqQ), mxGetPr(NTN), mxGetPr(Rmatrix), left, right, N);
    }    

    else if (mxGetM(CtrlPntsEqWgh)==1){
        NTN = mxCreateDoubleMatrix((int)mxGetScalar(numCtrlPnts), (int)mxGetScalar(numCtrlPnts), mxREAL);
        Rmatrix = mxCreateDoubleMatrix((int)mxGetScalar(numCtrlPnts), 2, mxREAL);
        
        LScurveAppEqPnt((int)mxGetScalar(nrbDeg), (int)mxGetScalar(numCtrlPnts), mxGetPr(knots), mxGetPr(ubar), (int)mxGetN(Qmatrix), mxGetPr(Qmatrix), (unsigned int*)mxGetPr(CtrlPntsEqInd), (int)mxGetN(CtrlPntsEqInd), mxGetScalar(CtrlPntsEqWgh), mxGetPr(coefs), mxGetPr(NTN), mxGetPr(Rmatrix), left, right, N);
    }
    
    else if (mxGetM(endQ)>1){
        NTN = mxCreateDoubleMatrix((int)mxGetScalar(numCtrlPnts)-2, (int)mxGetScalar(numCtrlPnts)-2, mxREAL);
        Rmatrix = mxCreateDoubleMatrix(((int)mxGetScalar(numCtrlPnts)-2), 2, mxREAL);
        
        LScurveApp((int)mxGetScalar(nrbDeg), (int)mxGetScalar(numCtrlPnts), mxGetPr(knots), mxGetPr(ubar), 2, (int)mxGetN(Qmatrix), mxGetPr(Qmatrix), mxGetPr(startQ), mxGetPr(endQ), mxGetPr(NTN), mxGetPr(Rmatrix), left, right, N);
    }
    
    free(left);
    free(right);
    free(N);
    
}
