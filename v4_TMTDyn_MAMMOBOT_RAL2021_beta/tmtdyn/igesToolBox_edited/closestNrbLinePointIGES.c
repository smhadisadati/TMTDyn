/**************************************************************************
 *
 * function [P,UV]=closestNrbLinePointIGES(nurbs,dnurbs,d2nurbs,UV0,r0,v)
 *
 * Closest points of NURBS patch and line/point using Newton's method.
 *
 * Line (3D):  r=r0+t*v
 * Point (3D): r0
 *
 * Usage in Matlab:
 *
 * § Closest NURBS-point to line
 * [P,UV]=closestNrbLinePointIGES(nurbs,dnurbs,d2nurbs,UV0,r0,v)
 *
 * § Closest NURBS-point to point
 * [P,UV]=closestNrbLinePointIGES(nurbs,dnurbs,d2nurbs,UV0,r0)
 *
 * Input:
 * nurbs - NURBS structure
 * dnurbs,d2nurbs - NURBS derivatives (output from nrbDerivativesIGES).
 * UV0 - Initial start Parameter values
 * r0,(v) - See Line/Point (3D) above. r0 (and v) must have the dimension (3x{1 or N})
 *          If size (3x1) - same point/line is used, if size (3xN) - different point/lines are used.
 *
 * Curve
 * UV0 - 1xN matrix, N number of u-parameters
 *
 * Surface
 * UV0 - 2xN matrix, N number of (u,v)-parameters
 *
 * Output:
 * P - Closest points on NURBS patch.
 * UV - NURBS Parameter values at closest point. (same dimension as UV0)
 *
 * c-file can be downloaded at
 *
 * http://www.mathworks.com/matlabcentral/fileexchange/13253-iges-toolbox
 *
 * compile in Matlab by using the command  "mex -v closestNrbLinePointIGES.c"
 *
 * See "help mex" for more information
 *
 * written by Per Bergström 2015-10-01
 *
 **************************************************************************/

#include <math.h>
#include "mex.h"

/* Input Arguments */

#define	nurbsstructure	prhs[0]
#define	dnrbsstructure	prhs[1]
#define d2nrbsstructure	prhs[2]
#define initparamvalues	prhs[3]
#define point0	prhs[4]
#define linedirection	prhs[5]

/* Output Arguments */

#define	evaluated_points	plhs[0]
#define	parametervalues	plhs[1]

/* Misc */

#define MAXITER 30

#if !defined(MAX)
#define	MAX(A, B)	((A) > (B) ? (A) : (B))
#endif

#if !defined(MIN)
#define	MIN(A, B)	((A) < (B) ? (A) : (B))
#endif

/* Sub functions (in folder "mexSourceFiles") */

#include "mexSourceFiles/FindSpan.c"
#include "mexSourceFiles/BasisFuns.c"
#include "mexSourceFiles/BspEval.c"
#include "mexSourceFiles/BspEval2.c"
#include "mexSourceFiles/NURBSsurfaceEval.c"
#include "mexSourceFiles/NURBScurveEval.c"
#include "mexSourceFiles/nrbD1D2eval.c"
#include "mexSourceFiles/nrbD1D2eval2.c"

void crossProduct(double *p, double *q, double *v){
    /* v = p x q */
    v[0] =  p[1]*q[2] - p[2]*q[1];
    v[1] =  p[2]*q[0] - p[0]*q[2];
    v[2] =  p[0]*q[1] - p[1]*q[0];
}

int updateClosestSrfPnt2Line(int degU, int degV, double *cp, int ncp, int kcp, double *knotU, double *knotV, double du, double dv, double *P0, double *Ldir, double *us, double *ep, double *epu, double *epv, double *epuu, double *epuv, double *epvv, double *leftU, double *rightU, double *NU, double *leftV, double *rightV, double *NV, double *InvHess, double *grad, double *vec1, double *vec2, double *vec3){
    
    unsigned char i;
    
    ep[0]-=P0[0];
    ep[1]-=P0[1];
    ep[2]-=P0[2];
    
    crossProduct(Ldir, ep, vec1);
    crossProduct(Ldir, epu, vec2);
    crossProduct(Ldir, epv, vec3);
    
    grad[0]=vec1[0]*vec2[0]+vec1[1]*vec2[1]+vec1[2]*vec2[2];
    grad[1]=vec1[0]*vec3[0]+vec1[1]*vec3[1]+vec1[2]*vec3[2];
    
    InvHess[0]=vec3[0]*vec3[0]+vec3[1]*vec3[1]+vec3[2]*vec3[2];
    InvHess[1]=-(vec2[0]*vec3[0]+vec2[1]*vec3[1]+vec2[2]*vec3[2]);
    InvHess[2]=vec2[0]*vec2[0]+vec2[1]*vec2[1]+vec2[2]*vec2[2];
    
    crossProduct(Ldir, epvv, vec3);
    InvHess[0]+=vec1[0]*vec3[0]+vec1[1]*vec3[1]+vec1[2]*vec3[2];
    crossProduct(Ldir, epuv, vec3);
    InvHess[1]-=vec1[0]*vec3[0]+vec1[1]*vec3[1]+vec1[2]*vec3[2];
    crossProduct(Ldir, epuu, vec3);
    InvHess[2]+=vec1[0]*vec3[0]+vec1[1]*vec3[1]+vec1[2]*vec3[2];
    
    vec2[2]=0.5*(vec1[0]*vec1[0]+vec1[1]*vec1[1]+vec1[2]*vec1[2]);
    
    vec3[0]=InvHess[0]*grad[0]+InvHess[1]*grad[1];
    vec3[1]=InvHess[1]*grad[0]+InvHess[2]*grad[1];
    
    vec3[2]=InvHess[0]*InvHess[2]-InvHess[1]*InvHess[1];
    
    if (fabs(vec3[2])<MAX(fabs(vec3[0]/du),fabs(vec3[1]/dv))){
        return 1;
    }
    else {
        vec3[0]=-vec3[0]/vec3[2];
        vec3[1]=-vec3[1]/vec3[2];
    }
    
    du=0.05*du;
    dv=0.05*dv;
    
    if (vec3[0]>du){
        vec3[1]=vec3[1]*du/vec3[0];
        vec3[0]=du;
    }
    else if (vec3[0]<-du){
        vec3[1]=-vec3[1]*du/vec3[0];
        vec3[0]=-du;
    }
    if (vec3[1]>dv){
        vec3[0]=vec3[0]*dv/vec3[1];
        vec3[1]=dv;
    }
    else if (vec3[1]<-dv){
        vec3[0]=-vec3[0]*dv/vec3[1];
        vec3[1]=-dv;
    }
    
    vec3[2]=0.3*(vec3[0]*grad[0]+vec3[1]*grad[1]);
    
    if (vec3[2]>0){
        vec3[0]=-vec3[0];
        vec3[1]=-vec3[1];
        vec3[2]=-vec3[2];
    }
    
    InvHess[0]=1.0;
    vec2[0]=us[0]+vec3[0];
    vec2[1]=us[1]+vec3[1];
    
    for (i = 0; i < 100; i++){
        
        NURBSsurfaceEval(degU, degV, cp, ncp, kcp, knotU, knotV, vec2, 1, ep, leftU, rightU, NU, leftV, rightV, NV);
        
        ep[0]-=P0[0];
        ep[1]-=P0[1];
        ep[2]-=P0[2];
        
        crossProduct(Ldir, ep, vec1);
        
        if ( 0.5*(vec1[0]*vec1[0]+vec1[1]*vec1[1]+vec1[2]*vec1[2])<(vec2[2]+InvHess[0]*vec3[2]) ){
            us[0]=vec2[0];
            us[1]=vec2[1];
            return 0;
        }
        else {
            InvHess[0]=0.7*InvHess[0];
            vec2[0]=us[0]+InvHess[0]*vec3[0];
            vec2[1]=us[1]+InvHess[0]*vec3[1];
        }
        
    }
    
    return 1;
    
}

int updateClosestCrvPnt2Line(int degU, double *cp, int ncp, double *knotU, double du, double *P0, double *Ldir, double *us, double *ep, double *epu, double *epuu, double *leftU, double *rightU, double *NU, double *InvHess, double *grad, double *vec1, double *vec2, double *vec3){
    
    unsigned char i;
    
    ep[0]-=P0[0];
    ep[1]-=P0[1];
    ep[2]-=P0[2];
    
    crossProduct(Ldir, ep, vec1);
    crossProduct(Ldir, epu, vec2);
    crossProduct(Ldir, epuu, vec3);
    
    grad[0]=vec1[0]*vec2[0]+vec1[1]*vec2[1]+vec1[2]*vec2[2];
    
    InvHess[0]=vec2[0]*vec2[0]+vec2[1]*vec2[1]+vec2[2]*vec2[2]+vec1[0]*vec3[0]+vec1[1]*vec3[1]+vec1[2]*vec3[2];
    
    if (fabs(InvHess[0]*du)<fabs(grad[0])){
        return 1;
    }
    else if (InvHess[0]<0){
        vec3[0]=grad[0]/InvHess[0];
    }
    else {
        vec3[0]=-grad[0]/InvHess[0];
    }
    
    du=0.05*du;
    
    if (vec3[0]>du){
        vec3[0]=du;
    }
    else if (vec3[0]<-du){
        vec3[0]=-du;
    }
    
    vec2[2]=0.5*(vec1[0]*vec1[0]+vec1[1]*vec1[1]+vec1[2]*vec1[2]);
    vec3[2]=0.3*vec3[0]*grad[0];
    
    
    InvHess[0]=1.0;
    vec2[0]=us[0]+vec3[0];
    
    for (i = 0; i < 100; i++){
        
        NURBScurveEval(degU, cp, ncp, knotU, vec2, 1, ep, leftU, rightU, NU);
        
        ep[0]-=P0[0];
        ep[1]-=P0[1];
        ep[2]-=P0[2];
        
        crossProduct(Ldir, ep, vec1);
        
        if ( 0.5*(vec1[0]*vec1[0]+vec1[1]*vec1[1]+vec1[2]*vec1[2])<(vec2[2]+InvHess[0]*vec3[2]) ){
            us[0]=vec2[0];
            return 0;
        }
        else {
            InvHess[0]=0.7*InvHess[0];
            vec2[0]=us[0]+InvHess[0]*vec3[0];
        }
        
    }
    
    return 1;
    
}

int updateClosestSrfPnt2Pnt(int degU, int degV, double *cp, int ncp, int kcp, double *knotU, double *knotV, double du, double dv, double *P0, double *us, double *ep, double *epu, double *epv, double *epuu, double *epuv, double *epvv, double *leftU, double *rightU, double *NU, double *leftV, double *rightV, double *NV, double *InvHess, double *grad, double *vec1, double *vec2, double *vec3){
    
    unsigned char i;
    
    ep[0]-=P0[0];
    ep[1]-=P0[1];
    ep[2]-=P0[2];
    
    grad[0]=ep[0]*epu[0]+ep[1]*epu[1]+ep[2]*epu[2];
    grad[1]=ep[0]*epv[0]+ep[1]*epv[1]+ep[2]*epv[2];
    
    InvHess[2]=ep[0]*epuu[0]+ep[1]*epuu[1]+ep[2]*epuu[2]+epu[0]*epu[0]+epu[1]*epu[1]+epu[2]*epu[2];
    InvHess[1]=-(ep[0]*epuv[0]+ep[1]*epuv[1]+ep[2]*epuv[2]+epu[0]*epv[0]+epu[1]*epv[1]+epu[2]*epv[2]);
    InvHess[0]=ep[0]*epvv[0]+ep[1]*epvv[1]+ep[2]*epvv[2]+epv[0]*epv[0]+epv[1]*epv[1]+epv[2]*epv[2];
    
    vec3[1]=InvHess[0]*InvHess[2]-InvHess[1]*InvHess[1];
    
    vec1[0]=InvHess[0]*grad[0]+InvHess[1]*grad[1];
    vec1[1]=InvHess[1]*grad[0]+InvHess[2]*grad[1];
    
    if (fabs(vec3[1])<MAX(fabs(vec1[0]/du),fabs(vec1[1]/dv))){
        return 1;
    }
    else {
        vec1[0]=-vec1[0]/vec3[1];
        vec1[1]=-vec1[1]/vec3[1];
    }
    
    du=0.05*du;
    dv=0.05*dv;
    
    if (vec1[0]>du){
        vec1[1]=vec1[1]*du/vec1[0];
        vec1[0]=du;
    }
    else if (vec1[0]<-du){
        vec1[1]=-vec1[1]*du/vec1[0];
        vec1[0]=-du;
    }
    if (vec1[1]>dv){
        vec1[0]=vec1[0]*dv/vec1[1];
        vec1[1]=dv;
    }
    else if (vec1[1]<-dv){
        vec1[0]=-vec1[0]*dv/vec1[1];
        vec1[1]=-dv;
    }
    
    vec3[0]=0.5*(ep[0]*ep[0]+ep[1]*ep[1]+ep[2]*ep[2]);
    vec3[1]=0.3*(vec1[0]*grad[0]+vec1[1]*grad[1]);
    
    if (vec3[1]>0){
        vec3[1]=-vec3[1];
        vec1[0]=-vec1[0];
        vec1[1]=-vec1[1];
    }
    
    InvHess[0]=1.0;
    vec2[0]=us[0]+vec1[0];
    vec2[1]=us[1]+vec1[1];
    
    for (i = 0; i < 100; i++){
        
        NURBSsurfaceEval(degU, degV, cp, ncp, kcp, knotU, knotV, vec2, 1, ep, leftU, rightU, NU, leftV, rightV, NV);
        
        ep[0]-=P0[0];
        ep[1]-=P0[1];
        ep[2]-=P0[2];
        
        if ( 0.5*(ep[0]*ep[0]+ep[1]*ep[1]+ep[2]*ep[2])<(vec3[0]+InvHess[0]*vec3[1]) ){
            us[0]=vec2[0];
            us[1]=vec2[1];
            return 0;
        }
        else {
            InvHess[0]=0.7*InvHess[0];
            vec2[0]=us[0]+InvHess[0]*vec1[0];
            vec2[1]=us[1]+InvHess[0]*vec1[1];
        }
        
    }
    
    return 1;
    
}


int updateClosestCrvPnt2Pnt(int degU, double *cp, int ncp, double *knotU, double du, double *P0, double *us, double *ep, double *epu, double *epuu, double *leftU, double *rightU, double *NU, double *InvHess, double *grad, double *vec1, double *vec2, double *vec3){
    
    unsigned char i;
    
    ep[0]-=P0[0];
    ep[1]-=P0[1];
    ep[2]-=P0[2];
    
    grad[0]=ep[0]*epu[0]+ep[1]*epu[1]+ep[2]*epu[2];
    
    InvHess[0]=ep[0]*epuu[0]+ep[1]*epuu[1]+ep[2]*epuu[2]+epu[0]*epu[0]+epu[1]*epu[1]+epu[2]*epu[2];
    
    if (fabs(InvHess[0]*du)<fabs(grad[0])){
        return 1;
    }
    else if (InvHess[0]<0){
        vec1[0]=grad[0]/InvHess[0];
    }
    else {
        vec1[0]=-grad[0]/InvHess[0];
    }
    
    du=0.05*du;
    
    if (vec1[0]>du){
        vec1[0]=du;
    }
    else if (vec1[0]<-du){
        vec1[0]=-du;
    }
    
    vec3[0]=0.5*(ep[0]*ep[0]+ep[1]*ep[1]+ep[2]*ep[2]);
    vec3[1]=0.3*vec1[0]*grad[0];
    
    InvHess[0]=1.0;
    vec2[0]=us[0]+vec1[0];
    
    for (i = 0; i < 100; i++){
        
        NURBScurveEval(degU, cp, ncp, knotU, vec2, 1, ep, leftU, rightU, NU);
        
        ep[0]-=P0[0];
        ep[1]-=P0[1];
        ep[2]-=P0[2];
        
        if ( 0.5*(ep[0]*ep[0]+ep[1]*ep[1]+ep[2]*ep[2])<(vec3[0]+InvHess[0]*vec3[1]) ){
            us[0]=vec2[0];
            return 0;
        }
        else {
            InvHess[0]=0.7*InvHess[0];
            vec2[0]=us[0]+InvHess[0]*vec1[0];
        }
        
    }
    
    return 1;
    
}

int updateCrvPlnIntersect(int degU, double *cp, int ncp, double *knotU, double du, double *P0, double *Ldir, double *us, double *ep, double *epu, double *leftU, double *rightU, double *NU, double *InvHess, double *grad, double *vec1, double *vec2, double *vec3){
    
    unsigned char i;
    
    grad[0]=ep[0]*Ldir[0]+ep[1]*Ldir[1]+ep[2]*Ldir[2]-P0[0];
    
    vec2[2]=fabs(grad[0]);
    
    InvHess[0]=epu[0]*Ldir[0]+epu[1]*Ldir[1]+epu[2]*Ldir[2];
    
    if (fabs(InvHess[0]*du)<vec2[2]){
        return 1;
    }
    else {
        vec3[0]=-grad[0]/InvHess[0];
    }
    
    du=0.05*du;
    
    if (vec3[0]>du){
        vec3[0]=du;
    }
    else if (vec3[0]<-du){
        vec3[0]=-du;
    }
    
    InvHess[0]=1.0;
    vec2[0]=us[0]+vec3[0];
    
    for (i = 0; i < 150; i++){
        
        NURBScurveEval(degU, cp, ncp, knotU, vec2, 1, ep, leftU, rightU, NU);
        
        if ( fabs(ep[0]*Ldir[0]+ep[1]*Ldir[1]+ep[2]*Ldir[2]-P0[0])<vec2[2] ){
            us[0]=vec2[0];
            return 0;
        }
        else {
            InvHess[0]=0.7*InvHess[0];
            vec2[0]=us[0]+InvHess[0]*vec3[0];
        }
        
    }
    
    return 1;
    
}


/* Main function */

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]){
    
    int i, j;
    double stepl, matHess[3], grad[2], dblVars[9];
    char TrueFalse=0;
    double paramtmp[2], umin, umax, du, dv, vmin, vmax, bspPnts[4], pnttmp[3], pderu[3], pderv[3], pderuu[3], pderuv[3], pdervv[3];
    
    if (nlhs!=2){
        mexErrMsgTxt("Number of outputs must be 2.");
    }
    if (nrhs>6 || nrhs<5){
        mexErrMsgTxt("Number of inputs must be 5 or 6.");
    }
    if (mxGetM(mxGetField(nurbsstructure, 0, "coefs"))!=4){
        mexPrintf("Number of rows in nurbs.coefs is %d,\n", mxGetM(mxGetField(nurbsstructure, 0, "coefs")));
        mexErrMsgTxt("nurbs.coefs must have 4 rows.");
    }
    if (mxGetM(initparamvalues)>2 || mxGetM(initparamvalues)==0){
        mexErrMsgTxt("UV0 must be of dim 1xN or 2xN.");
    }
    if (nrhs==6){
        if (mxGetM(linedirection)!=3){
            mexErrMsgTxt("v must have 3 rows.");
        }
    }
    else if(nrhs==5){
        if (mxGetN(point0)==mxGetN(initparamvalues)){
            if (mxGetN(point0)>1){
                TrueFalse=1;
            }
        }
    }
    
    evaluated_points = mxCreateDoubleMatrix(3, (int)mxGetN(initparamvalues), mxREAL);
    parametervalues = mxCreateDoubleMatrix((int)mxGetM(initparamvalues), (int)mxGetN(initparamvalues), mxREAL);
    
    if (mxGetM(initparamvalues)==2){
        
        int orderU = (int)mxGetPr(mxGetField(nurbsstructure, 0, "order"))[0];
        int orderV = (int)mxGetPr(mxGetField(nurbsstructure, 0, "order"))[1];
        
        int degU = orderU-1;
        int degV = orderV-1;
        
        int ncp = (int)mxGetPr(mxGetField(nurbsstructure, 0, "number"))[0];
        int kcp = (int)mxGetPr(mxGetField(nurbsstructure, 0, "number"))[1];
        
        double *leftU  = (double*) malloc(orderU*sizeof(double)+1);
        double *rightU = (double*) malloc(orderU*sizeof(double)+1);
        double *NU = (double*) malloc(orderU*sizeof(double)+1);
        double *leftV  = (double*) malloc(orderV*sizeof(double)+1);
        double *rightV = (double*) malloc(orderV*sizeof(double)+1);
        double *NV = (double*) malloc(orderV*sizeof(double)+1);
        
        umin = (double)mxGetPr(mxGetCell(mxGetField(nurbsstructure, 0, "knots"), 0))[0];
        umax = (double)mxGetPr(mxGetCell(mxGetField(nurbsstructure, 0, "knots"), 0))[ncp];
        vmin = (double)mxGetPr(mxGetCell(mxGetField(nurbsstructure, 0, "knots"), 1))[0];
        vmax = (double)mxGetPr(mxGetCell(mxGetField(nurbsstructure, 0, "knots"), 1))[kcp];
        
        du = umax - umin;
        dv = vmax - vmin;
        
        if (nrhs==6){
            
            if (mxGetN(linedirection)!=mxGetN(point0)){
                mexErrMsgTxt("r0 and v must be of same size.");
            }
            else if(mxGetN(linedirection)==mxGetN(initparamvalues)){
                if (mxGetN(point0)>1){
                    TrueFalse=1;
                }
            }
            
            for (i = 0; i < mxGetN(initparamvalues); i++){
                
                paramtmp[0] = (double)mxGetPr(initparamvalues)[2*i];
                paramtmp[1] = (double)mxGetPr(initparamvalues)[2*i+1];
                
                for (j = 0; j < MAXITER; j++){
                    
                    if (paramtmp[0] < umin){
                        paramtmp[0] = umin;
                    }
                    else if(paramtmp[0] > umax){
                        paramtmp[0] = umax;
                    }
                    if (paramtmp[1] < vmin){
                        paramtmp[1] = vmin;
                    }
                    else if(paramtmp[1] > vmax){
                        paramtmp[1] = vmax;
                    }
                    
                    nrbD1D2eval2(orderU, orderV, ncp, kcp, nurbsstructure, dnrbsstructure, d2nrbsstructure, paramtmp, pnttmp, pderu, pderv, pderuu, pderuv, pdervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                    
                    if (TrueFalse){
                        if (updateClosestSrfPnt2Line(degU, degV, mxGetPr(mxGetField(nurbsstructure, 0, "coefs")), ncp, kcp, mxGetPr(mxGetCell(mxGetField(nurbsstructure, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nurbsstructure, 0, "knots"), 1)), du, dv, &mxGetPr(point0)[3*i], &mxGetPr(linedirection)[3*i], paramtmp, pnttmp, pderu, pderv, pderuu, pderuv, pdervv, leftU, rightU, NU, leftV, rightV, NV, matHess, grad, dblVars, &dblVars[3], &dblVars[6])){
                            break;
                        }
                    }
                    else{
                        if (updateClosestSrfPnt2Line(degU, degV, mxGetPr(mxGetField(nurbsstructure, 0, "coefs")), ncp, kcp, mxGetPr(mxGetCell(mxGetField(nurbsstructure, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nurbsstructure, 0, "knots"), 1)), du, dv, mxGetPr(point0), mxGetPr(linedirection), paramtmp, pnttmp, pderu, pderv, pderuu, pderuv, pdervv, leftU, rightU, NU, leftV, rightV, NV, matHess, grad, dblVars, &dblVars[3], &dblVars[6])){
                            break;
                        }
                    }
                    
                    if (j<4){
                        if (j==0){
                            stepl=matHess[0]*matHess[0]*(dblVars[6]*dblVars[6]+dblVars[7]*dblVars[7]);
                        }
                        else {
                            stepl=MAX(stepl,matHess[0]*matHess[0]*(dblVars[6]*dblVars[6]+dblVars[7]*dblVars[7]));
                        }
                    }
                    else {
                        if ( 1.0e24*matHess[0]*matHess[0]*(dblVars[6]*dblVars[6]+dblVars[7]*dblVars[7])<stepl ){
                            break;
                        }
                    }
                    
                }
                
                if (paramtmp[0] < umin){
                    paramtmp[0] = umin;
                }
                else if(paramtmp[0] > umax){
                    paramtmp[0] = umax;
                }
                if (paramtmp[1] < vmin){
                    paramtmp[1] = vmin;
                }
                else if(paramtmp[1] > vmax){
                    paramtmp[1] = vmax;
                }
                BspEval2(degU, degV, mxGetPr(mxGetField(nurbsstructure, 0, "coefs")), 4, ncp, kcp, mxGetPr(mxGetCell(mxGetField(nurbsstructure, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nurbsstructure, 0, "knots"), 1)), paramtmp, 1, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                
                mxGetPr(evaluated_points)[3*i]=(bspPnts[0])/(bspPnts[3]);
                mxGetPr(evaluated_points)[3*i+1]=(bspPnts[1])/(bspPnts[3]);
                mxGetPr(evaluated_points)[3*i+2]=(bspPnts[2])/(bspPnts[3]);
                
                mxGetPr(parametervalues)[2*i]=paramtmp[0];
                mxGetPr(parametervalues)[2*i+1]=paramtmp[1];
                
            }
            
        }
        else if(nrhs==5){
            
            for (i = 0; i < mxGetN(initparamvalues); i++){
                
                paramtmp[0] = (double)mxGetPr(initparamvalues)[2*i];
                paramtmp[1] = (double)mxGetPr(initparamvalues)[2*i+1];
                
                for (j = 0; j < MAXITER; j++){
                    
                    if (paramtmp[0] < umin){
                        paramtmp[0] = umin;
                    }
                    else if(paramtmp[0] > umax){
                        paramtmp[0] = umax;
                    }
                    if (paramtmp[1] < vmin){
                        paramtmp[1] = vmin;
                    }
                    else if(paramtmp[1] > vmax){
                        paramtmp[1] = vmax;
                    }
                    
                    nrbD1D2eval2(orderU, orderV, ncp, kcp, nurbsstructure, dnrbsstructure, d2nrbsstructure, paramtmp, pnttmp, pderu, pderv, pderuu, pderuv, pdervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                    
                    if (TrueFalse){
                        if (updateClosestSrfPnt2Pnt(degU, degV, mxGetPr(mxGetField(nurbsstructure, 0, "coefs")), ncp, kcp, mxGetPr(mxGetCell(mxGetField(nurbsstructure, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nurbsstructure, 0, "knots"), 1)), du, dv, &mxGetPr(point0)[3*i], paramtmp, pnttmp, pderu, pderv, pderuu, pderuv, pdervv, leftU, rightU, NU, leftV, rightV, NV, matHess, grad, dblVars, &dblVars[3], &dblVars[6])){
                            break;
                        }
                    }
                    else{
                        if (updateClosestSrfPnt2Pnt(degU, degV, mxGetPr(mxGetField(nurbsstructure, 0, "coefs")), ncp, kcp, mxGetPr(mxGetCell(mxGetField(nurbsstructure, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nurbsstructure, 0, "knots"), 1)), du, dv, mxGetPr(point0), paramtmp, pnttmp, pderu, pderv, pderuu, pderuv, pdervv, leftU, rightU, NU, leftV, rightV, NV, matHess, grad, dblVars, &dblVars[3], &dblVars[6])){
                            break;
                        }
                    }
                    
                    if (j<4){
                        if (j==0){
                            stepl=matHess[0]*matHess[0]*(dblVars[0]*dblVars[0]+dblVars[1]*dblVars[1]);
                        }
                        else {
                            stepl=MAX(stepl,matHess[0]*matHess[0]*(dblVars[0]*dblVars[0]+dblVars[1]*dblVars[1]));
                        }
                    }
                    else {
                        if ( 1.0e24*matHess[0]*matHess[0]*(dblVars[0]*dblVars[0]+dblVars[1]*dblVars[1])<stepl ){
                            break;
                        }
                    }
                    
                }
                
                if (paramtmp[0] < umin){
                    paramtmp[0] = umin;
                }
                else if(paramtmp[0] > umax){
                    paramtmp[0] = umax;
                }
                if (paramtmp[1] < vmin){
                    paramtmp[1] = vmin;
                }
                else if(paramtmp[1] > vmax){
                    paramtmp[1] = vmax;
                }
                BspEval2(degU, degV, mxGetPr(mxGetField(nurbsstructure, 0, "coefs")), 4, ncp, kcp, mxGetPr(mxGetCell(mxGetField(nurbsstructure, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nurbsstructure, 0, "knots"), 1)), paramtmp, 1, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                
                mxGetPr(evaluated_points)[3*i]=(bspPnts[0])/(bspPnts[3]);
                mxGetPr(evaluated_points)[3*i+1]=(bspPnts[1])/(bspPnts[3]);
                mxGetPr(evaluated_points)[3*i+2]=(bspPnts[2])/(bspPnts[3]);
                
                mxGetPr(parametervalues)[2*i]=paramtmp[0];
                mxGetPr(parametervalues)[2*i+1]=paramtmp[1];
                
            }
            
        }
        else{
            mexPrintf("Error! Illegeal number of inputs.\n");
        }
        
        free(leftU);
        free(rightU);
        free(NU);
        free(leftV);
        free(rightV);
        free(NV);
        
    }
    else if (mxGetM(initparamvalues)==1){
        
        int orderU = (int)mxGetScalar(mxGetField(nurbsstructure, 0, "order"));
        int deg = orderU-1;
        
        int ncp = (int)mxGetScalar(mxGetField(nurbsstructure, 0, "number"));
        
        double *left  = (double*) malloc(orderU*sizeof(double)+1);
        double *right = (double*) malloc(orderU*sizeof(double)+1);
        double *N = (double*) malloc(orderU*sizeof(double)+1);
        
        umin = (double)mxGetPr(mxGetField(nurbsstructure, 0, "knots"))[0];
        umax = (double)mxGetPr(mxGetField(nurbsstructure, 0, "knots"))[ncp];
        
        du = umax - umin;
        
        if (nrhs==6){
            
            if (mxGetM(point0)==3){
                
                if (mxGetN(linedirection)!=mxGetN(point0)){
                    mexErrMsgTxt("r0 and v must be of same size.");
                }
                else if(mxGetN(linedirection)==mxGetN(initparamvalues)){
                    if (mxGetN(point0)>1){
                        TrueFalse=1;
                    }
                }
                
                for (i = 0; i < mxGetN(initparamvalues); i++){
                    
                    paramtmp[0] = (double)mxGetPr(initparamvalues)[i];
                    
                    for (j = 0; j < MAXITER; j++){
                        
                        if (paramtmp[0] < umin){
                            paramtmp[0] = umin;
                        }
                        else if(paramtmp[0] > umax){
                            paramtmp[0] = umax;
                        }
                        
                        nrbD1D2eval(orderU, ncp, nurbsstructure, dnrbsstructure, d2nrbsstructure, paramtmp, pnttmp, pderu, pderuu, bspPnts, left, right, N);
                        
                        if (TrueFalse){
                            if (updateClosestCrvPnt2Line(deg, mxGetPr(mxGetField(nurbsstructure, 0, "coefs")), ncp, mxGetPr(mxGetField(nurbsstructure, 0, "knots")), du, &mxGetPr(point0)[3*i], &mxGetPr(linedirection)[3*i], paramtmp, pnttmp, pderu, pderuu, left, right, N, matHess, grad, dblVars, &dblVars[3], &dblVars[6])){
                                break;
                            }
                        }
                        else{
                            if (updateClosestCrvPnt2Line(deg, mxGetPr(mxGetField(nurbsstructure, 0, "coefs")), ncp, mxGetPr(mxGetField(nurbsstructure, 0, "knots")), du, mxGetPr(point0), mxGetPr(linedirection), paramtmp, pnttmp, pderu, pderuu, left, right, N, matHess, grad, dblVars, &dblVars[3], &dblVars[6])){
                                break;
                            }
                        }
                        
                        if (j<4){
                            if (j==0){
                                stepl=fabs(matHess[0]*dblVars[6]);
                            }
                            else {
                                stepl=MAX(stepl,fabs(matHess[0]*dblVars[6]));
                            }
                        }
                        else {
                            if ( 1.0e12*fabs(matHess[0]*dblVars[6])<stepl ){
                                break;
                            }
                        }
                        
                    }
                    
                    if (paramtmp[0] < umin){
                        paramtmp[0] = umin;
                    }
                    else if(paramtmp[0] > umax){
                        paramtmp[0] = umax;
                    }
                    BspEval(orderU-1, mxGetPr(mxGetField(nurbsstructure, 0, "coefs")), 4, ncp, mxGetPr(mxGetField(nurbsstructure, 0, "knots")), paramtmp, 1, bspPnts, left, right, N);
                    
                    mxGetPr(evaluated_points)[3*i]=(bspPnts[0])/(bspPnts[3]);
                    mxGetPr(evaluated_points)[3*i+1]=(bspPnts[1])/(bspPnts[3]);
                    mxGetPr(evaluated_points)[3*i+2]=(bspPnts[2])/(bspPnts[3]);
                    
                    mxGetPr(parametervalues)[i]=paramtmp[0];
                    
                }
                
            }
            else {
                
                if(mxGetN(point0)==mxGetN(initparamvalues)){
                    if (mxGetN(point0)>1){
                        TrueFalse=1;
                    }
                }
                
                for (i = 0; i < mxGetN(initparamvalues); i++){
                    
                    paramtmp[0] = (double)mxGetPr(initparamvalues)[i];
                    
                    for (j = 0; j < MAXITER; j++){
                        
                        if (paramtmp[0] < umin){
                            paramtmp[0] = umin;
                        }
                        else if(paramtmp[0] > umax){
                            paramtmp[0] = umax;
                        }
                        
                        nrbD1eval(orderU, ncp, nurbsstructure, dnrbsstructure, paramtmp, pnttmp, pderu, bspPnts, left, right, N);
                        
                        if (TrueFalse){
                            if (updateCrvPlnIntersect(deg, mxGetPr(mxGetField(nurbsstructure, 0, "coefs")), ncp, mxGetPr(mxGetField(nurbsstructure, 0, "knots")), du, &mxGetPr(point0)[i], mxGetPr(linedirection), paramtmp, pnttmp, pderu, left, right, N, matHess, grad, dblVars, &dblVars[3], &dblVars[6])){
                                break;
                            }
                        }
                        else{
                            if (updateCrvPlnIntersect(deg, mxGetPr(mxGetField(nurbsstructure, 0, "coefs")), ncp, mxGetPr(mxGetField(nurbsstructure, 0, "knots")), du, mxGetPr(point0), mxGetPr(linedirection), paramtmp, pnttmp, pderu, left, right, N, matHess, grad, dblVars, &dblVars[3], &dblVars[6])){
                                break;
                            }
                        }
                        
                        if (j<4){
                            if (j==0){
                                stepl=fabs(matHess[0]*dblVars[6]);
                            }
                            else {
                                stepl=MAX(stepl,fabs(matHess[0]*dblVars[6]));
                            }
                        }
                        else {
                            if ( 1.0e12*fabs(matHess[0]*dblVars[6])<stepl ){
                                break;
                            }
                        }
                        
                    }
                    
                    if (paramtmp[0] < umin){
                        paramtmp[0] = umin;
                    }
                    else if(paramtmp[0] > umax){
                        paramtmp[0] = umax;
                    }
                    BspEval(orderU-1, mxGetPr(mxGetField(nurbsstructure, 0, "coefs")), 4, ncp, mxGetPr(mxGetField(nurbsstructure, 0, "knots")), paramtmp, 1, bspPnts, left, right, N);
                    
                    mxGetPr(evaluated_points)[3*i]=(bspPnts[0])/(bspPnts[3]);
                    mxGetPr(evaluated_points)[3*i+1]=(bspPnts[1])/(bspPnts[3]);
                    mxGetPr(evaluated_points)[3*i+2]=(bspPnts[2])/(bspPnts[3]);
                    
                    mxGetPr(parametervalues)[i]=paramtmp[0];
                    
                }
                
            }
            
        }
        else if(nrhs==5){
            
            for (i = 0; i < mxGetN(initparamvalues); i++){
                
                paramtmp[0] = (double)mxGetPr(initparamvalues)[i];
                
                for (j = 0; j < MAXITER; j++){
                    
                    if (paramtmp[0] < umin){
                        paramtmp[0] = umin;
                    }
                    else if(paramtmp[0] > umax){
                        paramtmp[0] = umax;
                    }
                    
                    nrbD1D2eval(orderU, ncp, nurbsstructure, dnrbsstructure, d2nrbsstructure, paramtmp, pnttmp, pderu, pderuu, bspPnts, left, right, N);
                    
                    if (TrueFalse){
                        if (updateClosestCrvPnt2Pnt(deg, mxGetPr(mxGetField(nurbsstructure, 0, "coefs")), ncp, mxGetPr(mxGetField(nurbsstructure, 0, "knots")), du, &mxGetPr(point0)[3*i], paramtmp, pnttmp, pderu, pderuu, left, right, N, matHess, grad, dblVars, &dblVars[3], &dblVars[6])){
                            break;
                        }
                    }
                    else{
                        if (updateClosestCrvPnt2Pnt(deg, mxGetPr(mxGetField(nurbsstructure, 0, "coefs")), ncp, mxGetPr(mxGetField(nurbsstructure, 0, "knots")), du, mxGetPr(point0), paramtmp, pnttmp, pderu, pderuu, left, right, N, matHess, grad, dblVars, &dblVars[3], &dblVars[6])){
                            break;
                        }
                    }
                    
                    if (j<4){
                        if (j==0){
                            stepl=fabs(matHess[0]*dblVars[0]);
                        }
                        else {
                            stepl=MAX(stepl,fabs(matHess[0]*dblVars[0]));
                        }
                    }
                    else {
                        if ( 1.0e12*fabs(matHess[0]*dblVars[0])<stepl ){
                            break;
                        }
                    }
                    
                }
                
                if (paramtmp[0] < umin){
                    paramtmp[0] = umin;
                }
                else if(paramtmp[0] > umax){
                    paramtmp[0] = umax;
                }
                BspEval(orderU-1, mxGetPr(mxGetField(nurbsstructure, 0, "coefs")), 4, ncp, mxGetPr(mxGetField(nurbsstructure, 0, "knots")), paramtmp, 1, bspPnts, left, right, N);
                
                mxGetPr(evaluated_points)[3*i]=(bspPnts[0])/(bspPnts[3]);
                mxGetPr(evaluated_points)[3*i+1]=(bspPnts[1])/(bspPnts[3]);
                mxGetPr(evaluated_points)[3*i+2]=(bspPnts[2])/(bspPnts[3]);
                
                mxGetPr(parametervalues)[i]=paramtmp[0];
                
            }
            
        }
        else{
            mexPrintf("Error! Illegeal number of inputs.\n");
        }
        
        free(left);
        free(right);
        free(N);
        
    }
    
    else{
        mexErrMsgTxt("Wrong dimension of UV");
    }
    
}
