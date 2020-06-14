/**************************************************************************
 *
 * function [UV,P]=crvPntsSrfNURBS(numPnts,nurbsCrv,us,ut,evalFlag)
 * function [lengthCrv,lengthScCrv,evalFlag]=crvPntsSrfNURBS(numPnts,nurbsCrv,us,ut)
 *
 * function [UV,P]=crvPntsSrfNURBS(numPnts,nurbsSrf,nurbsCrv,us,ut,evalFlag)
 * function [lengthCrv,lengthScCrv,evalFlag]=crvPntsSrfNURBS(numPnts,nurbsSrf,nurbsCrv,us,ut)
 *
 * function [UV,P]=crvPntsSrfNURBS(numPnts,nurbsSrf,Ps,Pt,evalFlag)
 * function [lengthCrv,lengthScCrv,evalFlag]=crvPntsSrfNURBS(numPnts,nurbsSrf,Ps,Pt)
 *
 * function [UV,P]=crvPntsSrfNURBS(numPnts,Ps,Pt)
 * function [lengthCrv,lengthScCrv,evalFlag]=crvPntsSrfNURBS(numPnts,Ps,Pt)
 *
 * Evaluates a trimmed NURBS curve in the parameter space of a NURBS surface
 *
 * c-file can be downloaded at
 *
 * http://www.mathworks.com/matlabcentral/fileexchange/13253-iges-toolbox
 *
 * compile in Matlab by using the command "mex -v crvPntsSrfNURBS.c"
 *
 * See "help mex" for more information
 *
 * written by Per Bergström 2015-11-06
 *
 **************************************************************************/

#include <math.h>
#include "mex.h"

/* Input Arguments */

#define numPnts	prhs[0]

#define	nurbs3DCRV	prhs[1]
#define	uStart	prhs[2]
#define	uTermi	prhs[3]

#define	evaliFlag	prhs[4]

#define	nurbsSRF	prhs[1]

#define	nurbsCRV	prhs[2]
#define	usStart	prhs[3]
#define	usTermi	prhs[4]

#define	evaliiFlag	prhs[5]

#define	pntStart	prhs[2]
#define	pntTermi	prhs[3]

#define	pnt3Start	prhs[1]
#define	pnt3Termi	prhs[2]

/* Output Arguments */

#define	parametervalues	plhs[0]
#define	evaluated_points	plhs[1]

#define	crvLength	plhs[0]
#define	crvScLength	plhs[1]
#define	evalFlag	plhs[2]

/* Misc */

#if !defined(MAX)
#define	MAX(A, B)	((A) > (B) ? (A) : (B))
#endif

#if !defined(MIN)
#define	MIN(A, B)	((A) < (B) ? (A) : (B))
#endif

/* Sub functions (in folder "mexSourceFiles") */

#include "mexSourceFiles/FindSpan.c"
#include "mexSourceFiles/BasisFuns.c"
#include "mexSourceFiles/NURBSsurfaceEval.c"


double pwr2(double a){
    return(a*a);
}

double getPoint2lineDist(double *P,double *pl,double *vl){
    return pwr2(vl[2]*(P[1]-pl[1])-vl[1]*(P[2]-pl[2]))+pwr2(vl[0]*(P[2]-pl[2])-vl[2]*(P[0]-pl[0]))+pwr2(vl[0]*(P[1]-pl[1])-vl[1]*(P[0]-pl[0]));
}


/* Main function */

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]){
    
    int i, j, k, pind, cind;
    int np, n0, n1, n2, n3, nrem, orderU, orderV, degU, degV, ncp, kcp, orderC, degC, ncpC, span, myint;
    double *srfPnts, *srfCP, *srfKnotsU, *srfKnotsV, *crvCP, *crvKnots, *leftU, *rightU, *NU, *leftV, *rightV, *NV;
    char TrueFalse=1, evFlg;
    double P0[3], P1[3], P2[3], P3[3], Pend[3], dir[3], maxDis, maxDis0, maxDis1, maxDis2, maxDis3, tmpDis, cparam, cparam1, cparam2, cparam3, *crvParams, paramtmp[2], param1[2], param2[2], param3[2], lineSt[2];
    double no0, no1, no2, no3, du, duC, uminC, umaxC, bspPnts[4], pnttmp[3];
    
    
    np = (int)mxGetScalar(numPnts);
    
    if (nlhs==1 || nlhs==2){
        
        if (nrhs<3 || nrhs==4 || nrhs>6){
            mexErrMsgTxt("Number of inputs must be 3, 5, or 6");
        }
        
        if (nrhs==5 && mxGetN(mxGetField(nurbs3DCRV, 0, "order"))==1){
            
            parametervalues = mxCreateDoubleMatrix(2, 0, mxREAL);
            
            if (nlhs==1){
                return;
            }
            
            evaluated_points = mxCreateDoubleMatrix(3, np, mxREAL);
            
            if (np==0){
                return;
            }
            
            evFlg = (char)mxGetScalar(evaliFlag);
            
            orderC = (int)mxGetScalar(mxGetField(nurbs3DCRV, 0, "order"));
            ncpC = (int)mxGetScalar(mxGetField(nurbs3DCRV, 0, "number"));
            
            degC = orderC-1;
            
            leftU  = (double*) malloc(orderC*sizeof(double)+1);
            rightU = (double*) malloc(orderC*sizeof(double)+1);
            NU = (double*) malloc(orderC*sizeof(double)+1);
            
            crvCP = mxGetPr(mxGetField(nurbs3DCRV, 0, "coefs"));
            crvKnots = mxGetPr(mxGetField(nurbs3DCRV, 0, "knots"));
            
            uminC = mxGetScalar(uStart);
            umaxC = mxGetScalar(uTermi);
            
            duC = umaxC - uminC;
            
            if (np==1){
                
                if (uminC < (crvKnots[0] + 1e-6*duC)){
                    
                    mxGetPr(evaluated_points)[0]=crvCP[0]/crvCP[3];
                    mxGetPr(evaluated_points)[1]=crvCP[1]/crvCP[3];
                    mxGetPr(evaluated_points)[2]=crvCP[2]/crvCP[3];
                    
                }
                else {
                    
                    bspPnts[0]=0.0;
                    bspPnts[1]=0.0;
                    bspPnts[2]=0.0;
                    bspPnts[3]=0.0;
                    
                    span = FindSpan(ncpC, degC, uminC, crvKnots);
                    BasisFuns(span, uminC, degC, crvKnots, NU, leftU, rightU);
                    
                    myint=(span-degC)*4;
                    for (i = 0; i <= degC; i++){
                        bspPnts[0]+=NU[i]*crvCP[myint];
                        bspPnts[1]+=NU[i]*crvCP[myint+1];
                        bspPnts[2]+=NU[i]*crvCP[myint+2];
                        bspPnts[3]+=NU[i]*crvCP[myint+3];
                        myint+=4;
                    }
                    mxGetPr(evaluated_points)[0]=bspPnts[0]/bspPnts[3];
                    mxGetPr(evaluated_points)[1]=bspPnts[1]/bspPnts[3];
                    mxGetPr(evaluated_points)[2]=bspPnts[2]/bspPnts[3];
                    
                }
                
            }
            else {
                
                if (uminC < (crvKnots[0] + 1e-6*duC)){
                    
                    P0[0]=crvCP[0]/crvCP[3];
                    P0[1]=crvCP[1]/crvCP[3];
                    P0[2]=crvCP[2]/crvCP[3];
                    
                }
                else {
                    
                    bspPnts[0]=0.0;
                    bspPnts[1]=0.0;
                    bspPnts[2]=0.0;
                    bspPnts[3]=0.0;
                    
                    span = FindSpan(ncpC, degC, uminC, crvKnots);
                    BasisFuns(span, uminC, degC, crvKnots, NU, leftU, rightU);
                    
                    myint=(span-degC)*4;
                    for (i = 0; i <= degC; i++){
                        bspPnts[0]+=NU[i]*crvCP[myint];
                        bspPnts[1]+=NU[i]*crvCP[myint+1];
                        bspPnts[2]+=NU[i]*crvCP[myint+2];
                        bspPnts[3]+=NU[i]*crvCP[myint+3];
                        myint+=4;
                    }
                    P0[0]=bspPnts[0]/bspPnts[3];
                    P0[1]=bspPnts[1]/bspPnts[3];
                    P0[2]=bspPnts[2]/bspPnts[3];
                    
                }
                
                if (evFlg==1){
                    
                    if (umaxC > (crvKnots[ncpC+degC] - 1e-6*duC)){
                        
                        Pend[0]=crvCP[4*ncpC-4]/crvCP[4*ncpC-1];
                        Pend[1]=crvCP[4*ncpC-3]/crvCP[4*ncpC-1];
                        Pend[2]=crvCP[4*ncpC-2]/crvCP[4*ncpC-1];
                        
                    }
                    else {
                        
                        bspPnts[0]=0.0;
                        bspPnts[1]=0.0;
                        bspPnts[2]=0.0;
                        bspPnts[3]=0.0;
                        
                        span = FindSpan(ncpC, degC, umaxC, crvKnots);
                        BasisFuns(span, umaxC, degC, crvKnots, NU, leftU, rightU);
                        
                        myint=(span-degC)*4;
                        for (i = 0; i <= degC; i++){
                            bspPnts[0]+=NU[i]*crvCP[myint];
                            bspPnts[1]+=NU[i]*crvCP[myint+1];
                            bspPnts[2]+=NU[i]*crvCP[myint+2];
                            bspPnts[3]+=NU[i]*crvCP[myint+3];
                            myint+=4;
                        }
                        Pend[0]=bspPnts[0]/bspPnts[3];
                        Pend[1]=bspPnts[1]/bspPnts[3];
                        Pend[2]=bspPnts[2]/bspPnts[3];
                        
                    }
                    
                    dir[0]=Pend[0]-P0[0];
                    dir[1]=Pend[1]-P0[1];
                    dir[2]=Pend[2]-P0[2];
                    
                    mxGetPr(evaluated_points)[0]=P0[0];
                    mxGetPr(evaluated_points)[1]=P0[1];
                    mxGetPr(evaluated_points)[2]=P0[2];
                    
                    if (np>4){
                        
                        crvParams = (double*) malloc(np*sizeof(double)+1);
                        crvParams[0] = uminC;
                        
                        maxDis=-1.0;
                        du=duC/6.0;
                        cparam=uminC+du;
                        
                        for (j = 0; j < 5; j++){
                            
                            bspPnts[0]=0.0;
                            bspPnts[1]=0.0;
                            bspPnts[2]=0.0;
                            bspPnts[3]=0.0;
                            
                            span = FindSpan(ncpC, degC, cparam, crvKnots);
                            BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                            
                            myint=(span-degC)*4;
                            for (i = 0; i <= degC; i++){
                                bspPnts[0]+=NU[i]*crvCP[myint];
                                bspPnts[1]+=NU[i]*crvCP[myint+1];
                                bspPnts[2]+=NU[i]*crvCP[myint+2];
                                bspPnts[3]+=NU[i]*crvCP[myint+3];
                                myint+=4;
                            }
                            pnttmp[0]=bspPnts[0]/bspPnts[3];
                            pnttmp[1]=bspPnts[1]/bspPnts[3];
                            pnttmp[2]=bspPnts[2]/bspPnts[3];
                            
                            tmpDis=getPoint2lineDist(pnttmp, P0, dir);
                            
                            if (tmpDis>maxDis){
                                
                                P2[0]=pnttmp[0];
                                P2[1]=pnttmp[1];
                                P2[2]=pnttmp[2];
                                
                                maxDis=tmpDis;
                                cparam2=cparam;
                                
                            }
                            
                            cparam+=du;
                            
                        }
                        
                        maxDis=-1.0;
                        du=(cparam2-uminC)/5.0;
                        cparam=uminC+du;
                        
                        dir[0]=P2[0]-P0[0];
                        dir[1]=P2[1]-P0[1];
                        dir[2]=P2[2]-P0[2];
                        
                        for (j = 0; j < 4; j++){
                            
                            bspPnts[0]=0.0;
                            bspPnts[1]=0.0;
                            bspPnts[2]=0.0;
                            bspPnts[3]=0.0;
                            
                            span = FindSpan(ncpC, degC, cparam, crvKnots);
                            BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                            
                            myint=(span-degC)*4;
                            for (i = 0; i <= degC; i++){
                                bspPnts[0]+=NU[i]*crvCP[myint];
                                bspPnts[1]+=NU[i]*crvCP[myint+1];
                                bspPnts[2]+=NU[i]*crvCP[myint+2];
                                bspPnts[3]+=NU[i]*crvCP[myint+3];
                                myint+=4;
                            }
                            pnttmp[0]=bspPnts[0]/bspPnts[3];
                            pnttmp[1]=bspPnts[1]/bspPnts[3];
                            pnttmp[2]=bspPnts[2]/bspPnts[3];
                            
                            tmpDis=getPoint2lineDist(pnttmp, P0, dir);
                            
                            if (tmpDis>maxDis){
                                
                                P1[0]=pnttmp[0];
                                P1[1]=pnttmp[1];
                                P1[2]=pnttmp[2];
                                
                                maxDis=tmpDis;
                                cparam1=cparam;
                                
                            }
                            
                            cparam+=du;
                            
                        }
                        
                        maxDis=-1.0;
                        du=(umaxC-cparam2)/5.0;
                        cparam=cparam2+du;
                        
                        dir[0]=Pend[0]-P2[0];
                        dir[1]=Pend[1]-P2[1];
                        dir[2]=Pend[2]-P2[2];
                        
                        for (j = 0; j < 4; j++){
                            
                            bspPnts[0]=0.0;
                            bspPnts[1]=0.0;
                            bspPnts[2]=0.0;
                            bspPnts[3]=0.0;
                            
                            span = FindSpan(ncpC, degC, cparam, crvKnots);
                            BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                            
                            myint=(span-degC)*4;
                            for (i = 0; i <= degC; i++){
                                bspPnts[0]+=NU[i]*crvCP[myint];
                                bspPnts[1]+=NU[i]*crvCP[myint+1];
                                bspPnts[2]+=NU[i]*crvCP[myint+2];
                                bspPnts[3]+=NU[i]*crvCP[myint+3];
                                myint+=4;
                            }
                            pnttmp[0]=bspPnts[0]/bspPnts[3];
                            pnttmp[1]=bspPnts[1]/bspPnts[3];
                            pnttmp[2]=bspPnts[2]/bspPnts[3];
                            
                            tmpDis=getPoint2lineDist(pnttmp, P2, dir);
                            
                            if (tmpDis>maxDis){
                                
                                P3[0]=pnttmp[0];
                                P3[1]=pnttmp[1];
                                P3[2]=pnttmp[2];
                                
                                maxDis=tmpDis;
                                cparam3=cparam;
                                
                            }
                            
                            cparam+=du;
                            
                        }
                        
                        /* First curve section */
                        
                        maxDis0=-1.0;
                        du=(cparam1-uminC)/5.0;
                        cparam=uminC+du;
                        
                        dir[0]=P1[0]-P0[0];
                        dir[1]=P1[1]-P0[1];
                        dir[2]=P1[2]-P0[2];
                        
                        no0=sqrt(dir[0]*dir[0]+dir[1]*dir[1]+dir[2]*dir[2]);
                        
                        dir[0]=dir[0]/no0;
                        dir[1]=dir[1]/no0;
                        dir[2]=dir[2]/no0;
                        
                        for (j = 0; j < 4; j++){
                            
                            bspPnts[0]=0.0;
                            bspPnts[1]=0.0;
                            bspPnts[2]=0.0;
                            bspPnts[3]=0.0;
                            
                            span = FindSpan(ncpC, degC, cparam, crvKnots);
                            BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                            
                            myint=(span-degC)*4;
                            for (i = 0; i <= degC; i++){
                                bspPnts[0]+=NU[i]*crvCP[myint];
                                bspPnts[1]+=NU[i]*crvCP[myint+1];
                                bspPnts[2]+=NU[i]*crvCP[myint+2];
                                bspPnts[3]+=NU[i]*crvCP[myint+3];
                                myint+=4;
                            }
                            pnttmp[0]=bspPnts[0]/bspPnts[3];
                            pnttmp[1]=bspPnts[1]/bspPnts[3];
                            pnttmp[2]=bspPnts[2]/bspPnts[3];
                            
                            tmpDis=getPoint2lineDist(pnttmp, P0, dir);
                            
                            if (tmpDis>maxDis0){
                                maxDis0=tmpDis;
                            }
                            
                            cparam+=du;
                            
                        }
                        
                        /* Second curve section */
                        
                        maxDis1=-1.0;
                        du=(cparam2-cparam1)/5.0;
                        cparam=cparam1+du;
                        
                        dir[0]=P2[0]-P1[0];
                        dir[1]=P2[1]-P1[1];
                        dir[2]=P2[2]-P1[2];
                        
                        no1=sqrt(dir[0]*dir[0]+dir[1]*dir[1]+dir[2]*dir[2]);
                        
                        dir[0]=dir[0]/no1;
                        dir[1]=dir[1]/no1;
                        dir[2]=dir[2]/no1;
                        
                        for (j = 0; j < 4; j++){
                            
                            bspPnts[0]=0.0;
                            bspPnts[1]=0.0;
                            bspPnts[2]=0.0;
                            bspPnts[3]=0.0;
                            
                            span = FindSpan(ncpC, degC, cparam, crvKnots);
                            BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                            
                            myint=(span-degC)*4;
                            for (i = 0; i <= degC; i++){
                                bspPnts[0]+=NU[i]*crvCP[myint];
                                bspPnts[1]+=NU[i]*crvCP[myint+1];
                                bspPnts[2]+=NU[i]*crvCP[myint+2];
                                bspPnts[3]+=NU[i]*crvCP[myint+3];
                                myint+=4;
                            }
                            pnttmp[0]=bspPnts[0]/bspPnts[3];
                            pnttmp[1]=bspPnts[1]/bspPnts[3];
                            pnttmp[2]=bspPnts[2]/bspPnts[3];
                            
                            tmpDis=getPoint2lineDist(pnttmp, P1, dir);
                            
                            if (tmpDis>maxDis1){
                                maxDis1=tmpDis;
                            }
                            
                            cparam+=du;
                            
                        }
                        
                        /* Third curve section */
                        
                        maxDis2=-1.0;
                        du=(cparam3-cparam2)/5.0;
                        cparam=cparam2+du;
                        
                        dir[0]=P3[0]-P2[0];
                        dir[1]=P3[1]-P2[1];
                        dir[2]=P3[2]-P2[2];
                        
                        no2=sqrt(dir[0]*dir[0]+dir[1]*dir[1]+dir[2]*dir[2]);
                        
                        dir[0]=dir[0]/no2;
                        dir[1]=dir[1]/no2;
                        dir[2]=dir[2]/no2;
                        
                        for (j = 0; j < 4; j++){
                            
                            bspPnts[0]=0.0;
                            bspPnts[1]=0.0;
                            bspPnts[2]=0.0;
                            bspPnts[3]=0.0;
                            
                            span = FindSpan(ncpC, degC, cparam, crvKnots);
                            BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                            
                            myint=(span-degC)*4;
                            for (i = 0; i <= degC; i++){
                                bspPnts[0]+=NU[i]*crvCP[myint];
                                bspPnts[1]+=NU[i]*crvCP[myint+1];
                                bspPnts[2]+=NU[i]*crvCP[myint+2];
                                bspPnts[3]+=NU[i]*crvCP[myint+3];
                                myint+=4;
                            }
                            pnttmp[0]=bspPnts[0]/bspPnts[3];
                            pnttmp[1]=bspPnts[1]/bspPnts[3];
                            pnttmp[2]=bspPnts[2]/bspPnts[3];
                            
                            tmpDis=getPoint2lineDist(pnttmp, P2, dir);
                            
                            if (tmpDis>maxDis2){
                                maxDis2=tmpDis;
                            }
                            
                            cparam+=du;
                            
                        }
                        
                        /* Fourth curve section */
                        
                        maxDis3=-1.0;
                        du=(umaxC-cparam3)/5.0;
                        cparam=cparam3+du;
                        
                        dir[0]=Pend[0]-P3[0];
                        dir[1]=Pend[1]-P3[1];
                        dir[2]=Pend[2]-P3[2];
                        
                        no3=sqrt(dir[0]*dir[0]+dir[1]*dir[1]+dir[2]*dir[2]);
                        
                        dir[0]=dir[0]/no3;
                        dir[1]=dir[1]/no3;
                        dir[2]=dir[2]/no3;
                        
                        for (j = 0; j < 4; j++){
                            
                            bspPnts[0]=0.0;
                            bspPnts[1]=0.0;
                            bspPnts[2]=0.0;
                            bspPnts[3]=0.0;
                            
                            span = FindSpan(ncpC, degC, cparam, crvKnots);
                            BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                            
                            myint=(span-degC)*4;
                            for (i = 0; i <= degC; i++){
                                bspPnts[0]+=NU[i]*crvCP[myint];
                                bspPnts[1]+=NU[i]*crvCP[myint+1];
                                bspPnts[2]+=NU[i]*crvCP[myint+2];
                                bspPnts[3]+=NU[i]*crvCP[myint+3];
                                myint+=4;
                            }
                            pnttmp[0]=bspPnts[0]/bspPnts[3];
                            pnttmp[1]=bspPnts[1]/bspPnts[3];
                            pnttmp[2]=bspPnts[2]/bspPnts[3];
                            
                            tmpDis=getPoint2lineDist(pnttmp, P3, dir);
                            
                            if (tmpDis>maxDis3){
                                maxDis3=tmpDis;
                            }
                            
                            cparam+=du;
                            
                        }
                        
                        maxDis0=sqrt(maxDis0)+5e-3*no0;
                        maxDis1=sqrt(maxDis1)+5e-3*no1;
                        maxDis2=sqrt(maxDis2)+5e-3*no2;
                        maxDis3=sqrt(maxDis3)+5e-3*no3;
                        
                        nrem=np-4;
                        
                        tmpDis=((double)nrem)/(maxDis0+maxDis1+maxDis2+maxDis3);
                        
                        maxDis0=maxDis0*tmpDis;
                        maxDis1=maxDis1*tmpDis;
                        maxDis2=maxDis2*tmpDis;
                        maxDis3=maxDis3*tmpDis;
                        
                        n0=(int)maxDis0;
                        n1=(int)maxDis1;
                        n2=(int)maxDis2;
                        n3=(int)maxDis3;
                        
                        nrem=nrem-(n0+n1+n2+n3);
                        
                        if (nrem>0){
                            
                            maxDis0=maxDis0-(double)n0;
                            maxDis1=maxDis1-(double)n1;
                            maxDis2=maxDis2-(double)n2;
                            maxDis3=maxDis3-(double)n3;
                            
                            if (maxDis0>maxDis1){
                                if (maxDis0>maxDis2){
                                    if (maxDis0>maxDis3){
                                        n0++;
                                        maxDis0-=0.25;
                                    }
                                    else {
                                        n3++;
                                        maxDis3-=0.25;
                                    }
                                }
                                else {
                                    if (maxDis2>maxDis3){
                                        n2++;
                                        maxDis2-=0.25;
                                    }
                                    else {
                                        n3++;
                                        maxDis3-=0.25;
                                    }
                                }
                            }
                            else {
                                if (maxDis1>maxDis2){
                                    if (maxDis1>maxDis3){
                                        n1++;
                                        maxDis1-=0.25;
                                    }
                                    else {
                                        n3++;
                                        maxDis3-=0.25;
                                    }
                                }
                                else {
                                    if (maxDis2>maxDis3){
                                        n2++;
                                        maxDis2-=0.25;
                                    }
                                    else {
                                        n3++;
                                        maxDis3-=0.25;
                                    }
                                }
                            }
                            nrem--;
                            
                            if (nrem>0){
                                
                                if (maxDis0>maxDis1){
                                    if (maxDis0>maxDis2){
                                        if (maxDis0>maxDis3){
                                            n0++;
                                            maxDis0-=0.25;
                                        }
                                        else {
                                            n3++;
                                            maxDis3-=0.25;
                                        }
                                    }
                                    else {
                                        if (maxDis2>maxDis3){
                                            n2++;
                                            maxDis2-=0.25;
                                        }
                                        else {
                                            n3++;
                                            maxDis3-=0.25;
                                        }
                                    }
                                }
                                else {
                                    if (maxDis1>maxDis2){
                                        if (maxDis1>maxDis3){
                                            n1++;
                                            maxDis1-=0.25;
                                        }
                                        else {
                                            n3++;
                                            maxDis3-=0.25;
                                        }
                                    }
                                    else {
                                        if (maxDis2>maxDis3){
                                            n2++;
                                            maxDis2-=0.25;
                                        }
                                        else {
                                            n3++;
                                            maxDis3-=0.25;
                                        }
                                    }
                                }
                                nrem--;
                                
                                if (nrem>0){
                                    
                                    if (maxDis0>maxDis1){
                                        if (maxDis0>maxDis2){
                                            if (maxDis0>maxDis3){
                                                n0++;
                                                maxDis0-=0.25;
                                            }
                                            else {
                                                n3++;
                                                maxDis3-=0.25;
                                            }
                                        }
                                        else {
                                            if (maxDis2>maxDis3){
                                                n2++;
                                                maxDis2-=0.25;
                                            }
                                            else {
                                                n3++;
                                                maxDis3-=0.25;
                                            }
                                        }
                                    }
                                    else {
                                        if (maxDis1>maxDis2){
                                            if (maxDis1>maxDis3){
                                                n1++;
                                                maxDis1-=0.25;
                                            }
                                            else {
                                                n3++;
                                                maxDis3-=0.25;
                                            }
                                        }
                                        else {
                                            if (maxDis2>maxDis3){
                                                n2++;
                                                maxDis2-=0.25;
                                            }
                                            else {
                                                n3++;
                                                maxDis3-=0.25;
                                            }
                                        }
                                    }
                                    nrem--;
                                    
                                    if (nrem>0){
                                        
                                        if (maxDis0>maxDis1){
                                            if (maxDis0>maxDis2){
                                                if (maxDis0>maxDis3){
                                                    n0++;
                                                    maxDis0-=0.25;
                                                }
                                                else {
                                                    n3++;
                                                    maxDis3-=0.25;
                                                }
                                            }
                                            else {
                                                if (maxDis2>maxDis3){
                                                    n2++;
                                                    maxDis2-=0.25;
                                                }
                                                else {
                                                    n3++;
                                                    maxDis3-=0.25;
                                                }
                                            }
                                        }
                                        else {
                                            if (maxDis1>maxDis2){
                                                if (maxDis1>maxDis3){
                                                    n1++;
                                                    maxDis1-=0.25;
                                                }
                                                else {
                                                    n3++;
                                                    maxDis3-=0.25;
                                                }
                                            }
                                            else {
                                                if (maxDis2>maxDis3){
                                                    n2++;
                                                    maxDis2-=0.25;
                                                }
                                                else {
                                                    n3++;
                                                    maxDis3-=0.25;
                                                }
                                            }
                                        }
                                        
                                    }
                                    
                                }
                                
                            }
                            
                        }
                        
                        cind=1;
                        k=3;
                        
                        /* First curve section */
                        
                        du=(cparam1-uminC)/((double)(n0+1));
                        cparam=uminC+du;
                        
                        for (j = 0; j < n0; j++){
                            
                            bspPnts[0]=0.0;
                            bspPnts[1]=0.0;
                            bspPnts[2]=0.0;
                            bspPnts[3]=0.0;
                            
                            span = FindSpan(ncpC, degC, cparam, crvKnots);
                            BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                            
                            myint=(span-degC)*4;
                            for (i = 0; i <= degC; i++){
                                bspPnts[0]+=NU[i]*crvCP[myint];
                                bspPnts[1]+=NU[i]*crvCP[myint+1];
                                bspPnts[2]+=NU[i]*crvCP[myint+2];
                                bspPnts[3]+=NU[i]*crvCP[myint+3];
                                myint+=4;
                            }
                            pnttmp[0]=bspPnts[0]/bspPnts[3];
                            pnttmp[1]=bspPnts[1]/bspPnts[3];
                            pnttmp[2]=bspPnts[2]/bspPnts[3];
                            
                            mxGetPr(evaluated_points)[k]=pnttmp[0];
                            mxGetPr(evaluated_points)[k+1]=pnttmp[1];
                            mxGetPr(evaluated_points)[k+2]=pnttmp[2];
                            
                            crvParams[cind]=cparam;
                            
                            cind++;
                            k+=3;
                            
                            cparam+=du;
                            
                        }
                        
                        mxGetPr(evaluated_points)[k]=P1[0];
                        mxGetPr(evaluated_points)[k+1]=P1[1];
                        mxGetPr(evaluated_points)[k+2]=P1[2];
                        
                        crvParams[cind]=cparam1;
                        
                        cind++;
                        k+=3;
                        
                        /* Second curve section */
                        
                        du=(cparam2-cparam1)/((double)(n1+1));
                        cparam=cparam1+du;
                        
                        for (j = 0; j < n1; j++){
                            
                            bspPnts[0]=0.0;
                            bspPnts[1]=0.0;
                            bspPnts[2]=0.0;
                            bspPnts[3]=0.0;
                            
                            span = FindSpan(ncpC, degC, cparam, crvKnots);
                            BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                            
                            myint=(span-degC)*4;
                            for (i = 0; i <= degC; i++){
                                bspPnts[0]+=NU[i]*crvCP[myint];
                                bspPnts[1]+=NU[i]*crvCP[myint+1];
                                bspPnts[2]+=NU[i]*crvCP[myint+2];
                                bspPnts[3]+=NU[i]*crvCP[myint+3];
                                myint+=4;
                            }
                            pnttmp[0]=bspPnts[0]/bspPnts[3];
                            pnttmp[1]=bspPnts[1]/bspPnts[3];
                            pnttmp[2]=bspPnts[2]/bspPnts[3];
                            
                            mxGetPr(evaluated_points)[k]=pnttmp[0];
                            mxGetPr(evaluated_points)[k+1]=pnttmp[1];
                            mxGetPr(evaluated_points)[k+2]=pnttmp[2];
                            
                            crvParams[cind]=cparam;
                            
                            cind++;
                            k+=3;
                            
                            cparam+=du;
                            
                        }
                        
                        mxGetPr(evaluated_points)[k]=P2[0];
                        mxGetPr(evaluated_points)[k+1]=P2[1];
                        mxGetPr(evaluated_points)[k+2]=P2[2];
                        
                        crvParams[cind]=cparam2;
                        
                        cind++;
                        k+=3;
                        
                        /* Third curve section */
                        
                        du=(cparam3-cparam2)/((double)(n2+1));
                        cparam=cparam2+du;
                        
                        for (j = 0; j < n2; j++){
                            
                            bspPnts[0]=0.0;
                            bspPnts[1]=0.0;
                            bspPnts[2]=0.0;
                            bspPnts[3]=0.0;
                            
                            span = FindSpan(ncpC, degC, cparam, crvKnots);
                            BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                            
                            myint=(span-degC)*4;
                            for (i = 0; i <= degC; i++){
                                bspPnts[0]+=NU[i]*crvCP[myint];
                                bspPnts[1]+=NU[i]*crvCP[myint+1];
                                bspPnts[2]+=NU[i]*crvCP[myint+2];
                                bspPnts[3]+=NU[i]*crvCP[myint+3];
                                myint+=4;
                            }
                            pnttmp[0]=bspPnts[0]/bspPnts[3];
                            pnttmp[1]=bspPnts[1]/bspPnts[3];
                            pnttmp[2]=bspPnts[2]/bspPnts[3];
                            
                            mxGetPr(evaluated_points)[k]=pnttmp[0];
                            mxGetPr(evaluated_points)[k+1]=pnttmp[1];
                            mxGetPr(evaluated_points)[k+2]=pnttmp[2];
                            
                            crvParams[cind]=cparam;
                            
                            cind++;
                            k+=3;
                            
                            cparam+=du;
                            
                        }
                        
                        mxGetPr(evaluated_points)[k]=P3[0];
                        mxGetPr(evaluated_points)[k+1]=P3[1];
                        mxGetPr(evaluated_points)[k+2]=P3[2];
                        
                        crvParams[cind]=cparam3;
                        
                        cind++;
                        k+=3;
                        
                        /* Fourth curve section */
                        
                        du=(umaxC-cparam3)/((double)(n3+1));
                        cparam=cparam3+du;
                        
                        for (j = 0; j < n3; j++){
                            
                            bspPnts[0]=0.0;
                            bspPnts[1]=0.0;
                            bspPnts[2]=0.0;
                            bspPnts[3]=0.0;
                            
                            span = FindSpan(ncpC, degC, cparam, crvKnots);
                            BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                            
                            myint=(span-degC)*4;
                            for (i = 0; i <= degC; i++){
                                bspPnts[0]+=NU[i]*crvCP[myint];
                                bspPnts[1]+=NU[i]*crvCP[myint+1];
                                bspPnts[2]+=NU[i]*crvCP[myint+2];
                                bspPnts[3]+=NU[i]*crvCP[myint+3];
                                myint+=4;
                            }
                            pnttmp[0]=bspPnts[0]/bspPnts[3];
                            pnttmp[1]=bspPnts[1]/bspPnts[3];
                            pnttmp[2]=bspPnts[2]/bspPnts[3];
                            
                            mxGetPr(evaluated_points)[k]=pnttmp[0];
                            mxGetPr(evaluated_points)[k+1]=pnttmp[1];
                            mxGetPr(evaluated_points)[k+2]=pnttmp[2];
                            
                            crvParams[cind]=cparam;
                            
                            cind++;
                            k+=3;
                            
                            cparam+=du;
                            
                        }
                        
                    }
                    else if (np==2){
                        
                        maxDis=-1.0;
                        du=duC/6.0;
                        cparam=uminC+du;
                        
                        for (j = 0; j < 5; j++){
                            
                            bspPnts[0]=0.0;
                            bspPnts[1]=0.0;
                            bspPnts[2]=0.0;
                            bspPnts[3]=0.0;
                            
                            span = FindSpan(ncpC, degC, cparam, crvKnots);
                            BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                            
                            myint=(span-degC)*4;
                            for (i = 0; i <= degC; i++){
                                bspPnts[0]+=NU[i]*crvCP[myint];
                                bspPnts[1]+=NU[i]*crvCP[myint+1];
                                bspPnts[2]+=NU[i]*crvCP[myint+2];
                                bspPnts[3]+=NU[i]*crvCP[myint+3];
                                myint+=4;
                            }
                            pnttmp[0]=bspPnts[0]/bspPnts[3];
                            pnttmp[1]=bspPnts[1]/bspPnts[3];
                            pnttmp[2]=bspPnts[2]/bspPnts[3];
                            
                            tmpDis=getPoint2lineDist(pnttmp, P0, dir);
                            
                            if (tmpDis>maxDis){
                                
                                mxGetPr(evaluated_points)[3]=pnttmp[0];
                                mxGetPr(evaluated_points)[4]=pnttmp[1];
                                mxGetPr(evaluated_points)[5]=pnttmp[2];
                                
                                maxDis=tmpDis;
                                cparam2=cparam;
                                
                            }
                            
                            cparam+=du;
                            
                        }
                        
                        for (k = 0; k < 3; k++){
                            
                            du=0.5*du;
                            
                            cparam=cparam2-du;
                            
                            bspPnts[0]=0.0;
                            bspPnts[1]=0.0;
                            bspPnts[2]=0.0;
                            bspPnts[3]=0.0;
                            
                            span = FindSpan(ncpC, degC, cparam, crvKnots);
                            BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                            
                            myint=(span-degC)*4;
                            for (i = 0; i <= degC; i++){
                                bspPnts[0]+=NU[i]*crvCP[myint];
                                bspPnts[1]+=NU[i]*crvCP[myint+1];
                                bspPnts[2]+=NU[i]*crvCP[myint+2];
                                bspPnts[3]+=NU[i]*crvCP[myint+3];
                                myint+=4;
                            }
                            pnttmp[0]=bspPnts[0]/bspPnts[3];
                            pnttmp[1]=bspPnts[1]/bspPnts[3];
                            pnttmp[2]=bspPnts[2]/bspPnts[3];
                            
                            tmpDis=getPoint2lineDist(pnttmp, P0, dir);
                            
                            if (tmpDis>maxDis){
                                
                                mxGetPr(evaluated_points)[3]=pnttmp[0];
                                mxGetPr(evaluated_points)[4]=pnttmp[1];
                                mxGetPr(evaluated_points)[5]=pnttmp[2];
                                
                                maxDis=tmpDis;
                                cparam2=cparam;
                                
                            }
                            else {
                                
                                cparam=cparam2+du;
                                
                                bspPnts[0]=0.0;
                                bspPnts[1]=0.0;
                                bspPnts[2]=0.0;
                                bspPnts[3]=0.0;
                                
                                span = FindSpan(ncpC, degC, cparam, crvKnots);
                                BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                                
                                myint=(span-degC)*4;
                                for (i = 0; i <= degC; i++){
                                    bspPnts[0]+=NU[i]*crvCP[myint];
                                    bspPnts[1]+=NU[i]*crvCP[myint+1];
                                    bspPnts[2]+=NU[i]*crvCP[myint+2];
                                    bspPnts[3]+=NU[i]*crvCP[myint+3];
                                    myint+=4;
                                }
                                pnttmp[0]=bspPnts[0]/bspPnts[3];
                                pnttmp[1]=bspPnts[1]/bspPnts[3];
                                pnttmp[2]=bspPnts[2]/bspPnts[3];
                                
                                tmpDis=getPoint2lineDist(pnttmp, P0, dir);
                                
                                if (tmpDis>maxDis){
                                    
                                    mxGetPr(evaluated_points)[3]=pnttmp[0];
                                    mxGetPr(evaluated_points)[4]=pnttmp[1];
                                    mxGetPr(evaluated_points)[5]=pnttmp[2];
                                    
                                    maxDis=tmpDis;
                                    cparam2=cparam;
                                    
                                }
                                
                            }
                            
                        }
                        
                    }
                    else if (np==3){
                        
                        crvParams = (double*) malloc(np*sizeof(double)+1);
                        crvParams[0] = uminC;
                        
                        maxDis=-1.0;
                        du=duC/6.0;
                        cparam=uminC+du;
                        
                        for (j = 0; j < 5; j++){
                            
                            bspPnts[0]=0.0;
                            bspPnts[1]=0.0;
                            bspPnts[2]=0.0;
                            bspPnts[3]=0.0;
                            
                            span = FindSpan(ncpC, degC, cparam, crvKnots);
                            BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                            
                            myint=(span-degC)*4;
                            for (i = 0; i <= degC; i++){
                                bspPnts[0]+=NU[i]*crvCP[myint];
                                bspPnts[1]+=NU[i]*crvCP[myint+1];
                                bspPnts[2]+=NU[i]*crvCP[myint+2];
                                bspPnts[3]+=NU[i]*crvCP[myint+3];
                                myint+=4;
                            }
                            pnttmp[0]=bspPnts[0]/bspPnts[3];
                            pnttmp[1]=bspPnts[1]/bspPnts[3];
                            pnttmp[2]=bspPnts[2]/bspPnts[3];
                            
                            tmpDis=getPoint2lineDist(pnttmp, P0, dir);
                            
                            if (tmpDis>maxDis){
                                
                                P1[0]=pnttmp[0];
                                P1[1]=pnttmp[1];
                                P1[2]=pnttmp[2];
                                
                                maxDis=tmpDis;
                                cparam2=cparam;
                                
                            }
                            
                            cparam+=du;
                            
                        }
                        
                        maxDis=-1.0;
                        du=(cparam2-uminC)/5.0;
                        cparam=uminC+du;
                        
                        dir[0]=P1[0]-P0[0];
                        dir[1]=P1[1]-P0[1];
                        dir[2]=P1[2]-P0[2];
                        
                        tmpDis=sqrt(dir[0]*dir[0]+dir[1]*dir[1]+dir[2]*dir[2]);
                        
                        dir[0]=dir[0]/tmpDis;
                        dir[1]=dir[1]/tmpDis;
                        dir[2]=dir[2]/tmpDis;
                        
                        for (j = 0; j < 4; j++){
                            
                            bspPnts[0]=0.0;
                            bspPnts[1]=0.0;
                            bspPnts[2]=0.0;
                            bspPnts[3]=0.0;
                            
                            span = FindSpan(ncpC, degC, cparam, crvKnots);
                            BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                            
                            myint=(span-degC)*4;
                            for (i = 0; i <= degC; i++){
                                bspPnts[0]+=NU[i]*crvCP[myint];
                                bspPnts[1]+=NU[i]*crvCP[myint+1];
                                bspPnts[2]+=NU[i]*crvCP[myint+2];
                                bspPnts[3]+=NU[i]*crvCP[myint+3];
                                myint+=4;
                            }
                            pnttmp[0]=bspPnts[0]/bspPnts[3];
                            pnttmp[1]=bspPnts[1]/bspPnts[3];
                            pnttmp[2]=bspPnts[2]/bspPnts[3];
                            
                            tmpDis=getPoint2lineDist(pnttmp, P0, dir);
                            
                            if (tmpDis>maxDis){
                                
                                P2[0]=pnttmp[0];
                                P2[1]=pnttmp[1];
                                P2[2]=pnttmp[2];
                                
                                maxDis=tmpDis;
                                cparam1=cparam;
                                
                            }
                            
                            cparam+=du;
                            
                        }
                        
                        
                        du=(umaxC-cparam2)/5.0;
                        cparam=cparam2+du;
                        
                        dir[0]=Pend[0]-P1[0];
                        dir[1]=Pend[1]-P1[1];
                        dir[2]=Pend[2]-P1[2];
                        
                        tmpDis=sqrt(dir[0]*dir[0]+dir[1]*dir[1]+dir[2]*dir[2]);
                        
                        dir[0]=dir[0]/tmpDis;
                        dir[1]=dir[1]/tmpDis;
                        dir[2]=dir[2]/tmpDis;
                        
                        for (j = 0; j < 4; j++){
                            
                            bspPnts[0]=0.0;
                            bspPnts[1]=0.0;
                            bspPnts[2]=0.0;
                            bspPnts[3]=0.0;
                            
                            span = FindSpan(ncpC, degC, cparam, crvKnots);
                            BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                            
                            myint=(span-degC)*4;
                            for (i = 0; i <= degC; i++){
                                bspPnts[0]+=NU[i]*crvCP[myint];
                                bspPnts[1]+=NU[i]*crvCP[myint+1];
                                bspPnts[2]+=NU[i]*crvCP[myint+2];
                                bspPnts[3]+=NU[i]*crvCP[myint+3];
                                myint+=4;
                            }
                            pnttmp[0]=bspPnts[0]/bspPnts[3];
                            pnttmp[1]=bspPnts[1]/bspPnts[3];
                            pnttmp[2]=bspPnts[2]/bspPnts[3];
                            
                            tmpDis=getPoint2lineDist(pnttmp, P1, dir);
                            
                            if (tmpDis>maxDis){
                                
                                P2[0]=pnttmp[0];
                                P2[1]=pnttmp[1];
                                P2[2]=pnttmp[2];
                                
                                maxDis=tmpDis;
                                cparam1=cparam;
                                TrueFalse=0;
                                
                            }
                            
                            cparam+=du;
                            
                        }
                        
                        if (TrueFalse){
                            
                            mxGetPr(evaluated_points)[3]=P2[0];
                            mxGetPr(evaluated_points)[4]=P2[1];
                            mxGetPr(evaluated_points)[5]=P2[2];
                            
                            mxGetPr(evaluated_points)[6]=P1[0];
                            mxGetPr(evaluated_points)[7]=P1[1];
                            mxGetPr(evaluated_points)[8]=P1[2];
                            
                            crvParams[1]=cparam1;
                            crvParams[2]=cparam2;
                            
                        }
                        else {
                            
                            mxGetPr(evaluated_points)[3]=P1[0];
                            mxGetPr(evaluated_points)[4]=P1[1];
                            mxGetPr(evaluated_points)[5]=P1[2];
                            
                            mxGetPr(evaluated_points)[6]=P2[0];
                            mxGetPr(evaluated_points)[7]=P2[1];
                            mxGetPr(evaluated_points)[8]=P2[2];
                            
                            crvParams[1]=cparam2;
                            crvParams[2]=cparam1;
                            
                        }
                        
                    }
                    else if (np==4){
                        
                        crvParams = (double*) malloc(np*sizeof(double)+1);
                        crvParams[0] = uminC;
                        
                        maxDis=-1.0;
                        du=duC/6.0;
                        cparam=uminC+du;
                        
                        for (j = 0; j < 5; j++){
                            
                            bspPnts[0]=0.0;
                            bspPnts[1]=0.0;
                            bspPnts[2]=0.0;
                            bspPnts[3]=0.0;
                            
                            span = FindSpan(ncpC, degC, cparam, crvKnots);
                            BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                            
                            myint=(span-degC)*4;
                            for (i = 0; i <= degC; i++){
                                bspPnts[0]+=NU[i]*crvCP[myint];
                                bspPnts[1]+=NU[i]*crvCP[myint+1];
                                bspPnts[2]+=NU[i]*crvCP[myint+2];
                                bspPnts[3]+=NU[i]*crvCP[myint+3];
                                myint+=4;
                            }
                            pnttmp[0]=bspPnts[0]/bspPnts[3];
                            pnttmp[1]=bspPnts[1]/bspPnts[3];
                            pnttmp[2]=bspPnts[2]/bspPnts[3];
                            
                            tmpDis=getPoint2lineDist(pnttmp, P0, dir);
                            
                            if (tmpDis>maxDis){
                                
                                P2[0]=pnttmp[0];
                                P2[1]=pnttmp[1];
                                P2[2]=pnttmp[2];
                                
                                maxDis=tmpDis;
                                cparam2=cparam;
                                
                            }
                            
                            cparam+=du;
                            
                        }
                        
                        maxDis=-1.0;
                        du=(cparam2-uminC)/5.0;
                        cparam=uminC+du;
                        
                        dir[0]=P2[0]-P0[0];
                        dir[1]=P2[1]-P0[1];
                        dir[2]=P2[2]-P0[2];
                        
                        for (j = 0; j < 4; j++){
                            
                            bspPnts[0]=0.0;
                            bspPnts[1]=0.0;
                            bspPnts[2]=0.0;
                            bspPnts[3]=0.0;
                            
                            span = FindSpan(ncpC, degC, cparam, crvKnots);
                            BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                            
                            myint=(span-degC)*4;
                            for (i = 0; i <= degC; i++){
                                bspPnts[0]+=NU[i]*crvCP[myint];
                                bspPnts[1]+=NU[i]*crvCP[myint+1];
                                bspPnts[2]+=NU[i]*crvCP[myint+2];
                                bspPnts[3]+=NU[i]*crvCP[myint+3];
                                myint+=4;
                            }
                            pnttmp[0]=bspPnts[0]/bspPnts[3];
                            pnttmp[1]=bspPnts[1]/bspPnts[3];
                            pnttmp[2]=bspPnts[2]/bspPnts[3];
                            
                            tmpDis=getPoint2lineDist(pnttmp, P0, dir);
                            
                            if (tmpDis>maxDis){
                                
                                P1[0]=pnttmp[0];
                                P1[1]=pnttmp[1];
                                P1[2]=pnttmp[2];
                                
                                maxDis=tmpDis;
                                cparam1=cparam;
                                
                            }
                            
                            cparam+=du;
                            
                        }
                        
                        maxDis=-1.0;
                        du=(umaxC-cparam2)/5.0;
                        cparam=cparam2+du;
                        
                        dir[0]=Pend[0]-P2[0];
                        dir[1]=Pend[1]-P2[1];
                        dir[2]=Pend[2]-P2[2];
                        
                        for (j = 0; j < 4; j++){
                            
                            bspPnts[0]=0.0;
                            bspPnts[1]=0.0;
                            bspPnts[2]=0.0;
                            bspPnts[3]=0.0;
                            
                            span = FindSpan(ncpC, degC, cparam, crvKnots);
                            BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                            
                            myint=(span-degC)*4;
                            for (i = 0; i <= degC; i++){
                                bspPnts[0]+=NU[i]*crvCP[myint];
                                bspPnts[1]+=NU[i]*crvCP[myint+1];
                                bspPnts[2]+=NU[i]*crvCP[myint+2];
                                bspPnts[3]+=NU[i]*crvCP[myint+3];
                                myint+=4;
                            }
                            pnttmp[0]=bspPnts[0]/bspPnts[3];
                            pnttmp[1]=bspPnts[1]/bspPnts[3];
                            pnttmp[2]=bspPnts[2]/bspPnts[3];
                            
                            tmpDis=getPoint2lineDist(pnttmp, P2, dir);
                            
                            if (tmpDis>maxDis){
                                
                                P3[0]=pnttmp[0];
                                P3[1]=pnttmp[1];
                                P3[2]=pnttmp[2];
                                
                                maxDis=tmpDis;
                                cparam3=cparam;
                                
                            }
                            
                            cparam+=du;
                            
                        }
                        
                        mxGetPr(evaluated_points)[3]=P1[0];
                        mxGetPr(evaluated_points)[4]=P1[1];
                        mxGetPr(evaluated_points)[5]=P1[2];
                        
                        mxGetPr(evaluated_points)[6]=P2[0];
                        mxGetPr(evaluated_points)[7]=P2[1];
                        mxGetPr(evaluated_points)[8]=P2[2];
                        
                        mxGetPr(evaluated_points)[9]=P3[0];
                        mxGetPr(evaluated_points)[10]=P3[1];
                        mxGetPr(evaluated_points)[11]=P3[2];
                        
                        crvParams[1]=cparam1;
                        crvParams[2]=cparam2;
                        crvParams[3]=cparam3;
                        
                    }
                    
                    if (np>2){
                        
                        cind=3;
                        
                        for (k = 1; k < (np-1); k++){
                            
                            dir[0]=mxGetPr(evaluated_points)[cind+3]-mxGetPr(evaluated_points)[cind-3];
                            dir[1]=mxGetPr(evaluated_points)[cind+4]-mxGetPr(evaluated_points)[cind-2];
                            dir[2]=mxGetPr(evaluated_points)[cind+5]-mxGetPr(evaluated_points)[cind-1];
                            
                            maxDis=getPoint2lineDist(&mxGetPr(evaluated_points)[cind], &mxGetPr(evaluated_points)[cind-3], dir);
                            
                            cparam=0.67*crvParams[k]+0.33*crvParams[k-1];
                            
                            bspPnts[0]=0.0;
                            bspPnts[1]=0.0;
                            bspPnts[2]=0.0;
                            bspPnts[3]=0.0;
                            
                            span = FindSpan(ncpC, degC, cparam, crvKnots);
                            BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                            
                            myint=(span-degC)*4;
                            for (i = 0; i <= degC; i++){
                                bspPnts[0]+=NU[i]*crvCP[myint];
                                bspPnts[1]+=NU[i]*crvCP[myint+1];
                                bspPnts[2]+=NU[i]*crvCP[myint+2];
                                bspPnts[3]+=NU[i]*crvCP[myint+3];
                                myint+=4;
                            }
                            pnttmp[0]=bspPnts[0]/bspPnts[3];
                            pnttmp[1]=bspPnts[1]/bspPnts[3];
                            pnttmp[2]=bspPnts[2]/bspPnts[3];
                            
                            tmpDis=getPoint2lineDist(pnttmp, &mxGetPr(evaluated_points)[cind-3], dir);
                            
                            if (tmpDis>maxDis){
                                
                                crvParams[k]=cparam;
                                
                                mxGetPr(evaluated_points)[cind]=pnttmp[0];
                                mxGetPr(evaluated_points)[cind+1]=pnttmp[1];
                                mxGetPr(evaluated_points)[cind+2]=pnttmp[2];
                                
                            }
                            else {
                                
                                cparam=0.67*crvParams[k]+0.33*crvParams[k+1];
                                
                                bspPnts[0]=0.0;
                                bspPnts[1]=0.0;
                                bspPnts[2]=0.0;
                                bspPnts[3]=0.0;
                                
                                span = FindSpan(ncpC, degC, cparam, crvKnots);
                                BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                                
                                myint=(span-degC)*4;
                                for (i = 0; i <= degC; i++){
                                    bspPnts[0]+=NU[i]*crvCP[myint];
                                    bspPnts[1]+=NU[i]*crvCP[myint+1];
                                    bspPnts[2]+=NU[i]*crvCP[myint+2];
                                    bspPnts[3]+=NU[i]*crvCP[myint+3];
                                    myint+=4;
                                }
                                pnttmp[0]=bspPnts[0]/bspPnts[3];
                                pnttmp[1]=bspPnts[1]/bspPnts[3];
                                pnttmp[2]=bspPnts[2]/bspPnts[3];
                                
                                tmpDis=getPoint2lineDist(pnttmp, &mxGetPr(evaluated_points)[cind-3], dir);
                                
                                if (tmpDis>maxDis){
                                    
                                    crvParams[k]=cparam;
                                    
                                    mxGetPr(evaluated_points)[cind]=pnttmp[0];
                                    mxGetPr(evaluated_points)[cind+1]=pnttmp[1];
                                    mxGetPr(evaluated_points)[cind+2]=pnttmp[2];
                                    
                                }
                                
                            }
                            
                            cind+=3;
                            
                        }
                        
                        k = np-1;
                        
                        dir[0]=Pend[0]-mxGetPr(evaluated_points)[cind-3];
                        dir[1]=Pend[1]-mxGetPr(evaluated_points)[cind-2];
                        dir[2]=Pend[2]-mxGetPr(evaluated_points)[cind-1];
                        
                        maxDis=getPoint2lineDist(&mxGetPr(evaluated_points)[cind], &mxGetPr(evaluated_points)[cind-3], dir);
                        
                        cparam=0.67*crvParams[k]+0.33*crvParams[k-1];
                        
                        bspPnts[0]=0.0;
                        bspPnts[1]=0.0;
                        bspPnts[2]=0.0;
                        bspPnts[3]=0.0;
                        
                        span = FindSpan(ncpC, degC, cparam, crvKnots);
                        BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                        
                        myint=(span-degC)*4;
                        for (i = 0; i <= degC; i++){
                            bspPnts[0]+=NU[i]*crvCP[myint];
                            bspPnts[1]+=NU[i]*crvCP[myint+1];
                            bspPnts[2]+=NU[i]*crvCP[myint+2];
                            bspPnts[3]+=NU[i]*crvCP[myint+3];
                            myint+=4;
                        }
                        pnttmp[0]=bspPnts[0]/bspPnts[3];
                        pnttmp[1]=bspPnts[1]/bspPnts[3];
                        pnttmp[2]=bspPnts[2]/bspPnts[3];
                        
                        tmpDis=getPoint2lineDist(pnttmp, &mxGetPr(evaluated_points)[cind-3], dir);
                        
                        if (tmpDis>maxDis){
                            
                            crvParams[k]=cparam;
                            
                            mxGetPr(evaluated_points)[cind]=pnttmp[0];
                            mxGetPr(evaluated_points)[cind+1]=pnttmp[1];
                            mxGetPr(evaluated_points)[cind+2]=pnttmp[2];
                            
                        }
                        else {
                            
                            cparam=0.67*crvParams[k]+0.33*umaxC;
                            
                            bspPnts[0]=0.0;
                            bspPnts[1]=0.0;
                            bspPnts[2]=0.0;
                            bspPnts[3]=0.0;
                            
                            span = FindSpan(ncpC, degC, cparam, crvKnots);
                            BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                            
                            myint=(span-degC)*4;
                            for (i = 0; i <= degC; i++){
                                bspPnts[0]+=NU[i]*crvCP[myint];
                                bspPnts[1]+=NU[i]*crvCP[myint+1];
                                bspPnts[2]+=NU[i]*crvCP[myint+2];
                                bspPnts[3]+=NU[i]*crvCP[myint+3];
                                myint+=4;
                            }
                            pnttmp[0]=bspPnts[0]/bspPnts[3];
                            pnttmp[1]=bspPnts[1]/bspPnts[3];
                            pnttmp[2]=bspPnts[2]/bspPnts[3];
                            
                            tmpDis=getPoint2lineDist(pnttmp, &mxGetPr(evaluated_points)[cind-3], dir);
                            
                            if (tmpDis>maxDis){
                                
                                crvParams[k]=cparam;
                                
                                mxGetPr(evaluated_points)[cind]=pnttmp[0];
                                mxGetPr(evaluated_points)[cind+1]=pnttmp[1];
                                mxGetPr(evaluated_points)[cind+2]=pnttmp[2];
                                
                            }
                            
                        }
                        
                        free(crvParams);
                        
                    }
                    
                }
                else {
                    
                    du = duC/((double)np);
                    
                    cparam=uminC;
                    
                    mxGetPr(evaluated_points)[0]=P0[0];
                    mxGetPr(evaluated_points)[1]=P0[1];
                    mxGetPr(evaluated_points)[2]=P0[2];
                    
                    for (k = 3; k < 3*np-2; k+=3){
                        
                        cparam+=du;
                        
                        bspPnts[0]=0.0;
                        bspPnts[1]=0.0;
                        bspPnts[2]=0.0;
                        bspPnts[3]=0.0;
                        
                        span = FindSpan(ncpC, degC, cparam, crvKnots);
                        BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                        
                        myint=(span-degC)*4;
                        for (i = 0; i <= degC; i++){
                            bspPnts[0]+=NU[i]*crvCP[myint];
                            bspPnts[1]+=NU[i]*crvCP[myint+1];
                            bspPnts[2]+=NU[i]*crvCP[myint+2];
                            bspPnts[3]+=NU[i]*crvCP[myint+3];
                            myint+=4;
                        }
                        mxGetPr(evaluated_points)[k]=bspPnts[0]/bspPnts[3];
                        mxGetPr(evaluated_points)[k+1]=bspPnts[1]/bspPnts[3];
                        mxGetPr(evaluated_points)[k+2]=bspPnts[2]/bspPnts[3];
                        
                    }
                    
                }
                
            }
            
            free(leftU);
            free(rightU);
            free(NU);
            
        }
        else if (nrhs>3){
            
            parametervalues = mxCreateDoubleMatrix(2, np, mxREAL);
            
            orderU = (int)mxGetPr(mxGetField(nurbsSRF, 0, "order"))[0];
            orderV = (int)mxGetPr(mxGetField(nurbsSRF, 0, "order"))[1];
            
            degU = orderU-1;
            degV = orderV-1;
            
            ncp = (int)mxGetPr(mxGetField(nurbsSRF, 0, "number"))[0];
            kcp = (int)mxGetPr(mxGetField(nurbsSRF, 0, "number"))[1];
            
            if (nrhs==6){
                
                evFlg = (char)mxGetScalar(evaliiFlag);
                
                if (nlhs==2){
                    evaluated_points = mxCreateDoubleMatrix(3, np, mxREAL);
                    srfPnts = (double*)mxGetPr(evaluated_points);
                }
                else if (evFlg>0 && np>1){
                    srfPnts = (double*) malloc((3*np)*sizeof(double)+1);
                }
                
                if (np==0){
                    return;
                }
                
                orderC = (int)mxGetScalar(mxGetField(nurbsCRV, 0, "order"));
                ncpC = (int)mxGetScalar(mxGetField(nurbsCRV, 0, "number"));
                
                degC = orderC-1;
                
                leftU  = (double*) malloc(MAX(orderU,orderC)*sizeof(double)+1);
                rightU = (double*) malloc(MAX(orderU,orderC)*sizeof(double)+1);
                NU = (double*) malloc(MAX(orderU,orderC)*sizeof(double)+1);
                leftV  = (double*) malloc(orderV*sizeof(double)+1);
                rightV = (double*) malloc(orderV*sizeof(double)+1);
                NV = (double*) malloc(orderV*sizeof(double)+1);
                
                srfCP = mxGetPr(mxGetField(nurbsSRF, 0, "coefs"));
                srfKnotsU = mxGetPr(mxGetCell(mxGetField(nurbsSRF, 0, "knots"), 0));
                srfKnotsV = mxGetPr(mxGetCell(mxGetField(nurbsSRF, 0, "knots"), 1));
                
                crvCP = mxGetPr(mxGetField(nurbsCRV, 0, "coefs"));
                crvKnots = mxGetPr(mxGetField(nurbsCRV, 0, "knots"));
                
                uminC = mxGetScalar(usStart);
                umaxC = mxGetScalar(usTermi);
                
                duC = umaxC - uminC;
                
                if (np==1){
                    
                    if (uminC < (crvKnots[0] + 1e-6*duC)){
                        
                        mxGetPr(parametervalues)[0]=crvCP[0]/crvCP[3];
                        mxGetPr(parametervalues)[1]=crvCP[1]/crvCP[3];
                        
                    }
                    else {
                        
                        bspPnts[0]=0.0;
                        bspPnts[1]=0.0;
                        bspPnts[2]=0.0;
                        
                        span = FindSpan(ncpC, degC, uminC, crvKnots);
                        BasisFuns(span, uminC, degC, crvKnots, NU, leftU, rightU);
                        
                        myint=(span-degC)*4;
                        for (i = 0; i <= degC; i++){
                            bspPnts[0]+=NU[i]*crvCP[myint];
                            bspPnts[1]+=NU[i]*crvCP[myint+1];
                            bspPnts[2]+=NU[i]*crvCP[myint+3];
                            myint+=4;
                        }
                        mxGetPr(parametervalues)[0]=bspPnts[0]/bspPnts[2];
                        mxGetPr(parametervalues)[1]=bspPnts[1]/bspPnts[2];
                        
                    }
                    
                    if (nlhs==2){
                        NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, mxGetPr(parametervalues), 1, srfPnts, leftU, rightU, NU, leftV, rightV, NV);
                    }
                    
                }
                else {
                    
                    if (uminC < (crvKnots[0] + 1e-6*duC)){
                        
                        paramtmp[0]=crvCP[0]/crvCP[3];
                        paramtmp[1]=crvCP[1]/crvCP[3];
                        
                    }
                    else {
                        
                        bspPnts[0]=0.0;
                        bspPnts[1]=0.0;
                        bspPnts[2]=0.0;
                        
                        span = FindSpan(ncpC, degC, uminC, crvKnots);
                        BasisFuns(span, uminC, degC, crvKnots, NU, leftU, rightU);
                        
                        myint=(span-degC)*4;
                        for (i = 0; i <= degC; i++){
                            bspPnts[0]+=NU[i]*crvCP[myint];
                            bspPnts[1]+=NU[i]*crvCP[myint+1];
                            bspPnts[2]+=NU[i]*crvCP[myint+3];
                            myint+=4;
                        }
                        paramtmp[0]=bspPnts[0]/bspPnts[2];
                        paramtmp[1]=bspPnts[1]/bspPnts[2];
                        
                    }
                    
                    mxGetPr(parametervalues)[0]=paramtmp[0];
                    mxGetPr(parametervalues)[1]=paramtmp[1];
                    
                    if (evFlg==1){
                        
                        NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, (unsigned int)1, P0, leftU, rightU, NU, leftV, rightV, NV);
                        
                        srfPnts[0]=P0[0];
                        srfPnts[1]=P0[1];
                        srfPnts[2]=P0[2];
                        
                        if (umaxC > (crvKnots[ncpC+degC] - 1e-6*duC)){
                            
                            paramtmp[0]=crvCP[4*ncpC-4]/crvCP[4*ncpC-1];
                            paramtmp[1]=crvCP[4*ncpC-3]/crvCP[4*ncpC-1];
                            
                        }
                        else {
                            
                            bspPnts[0]=0.0;
                            bspPnts[1]=0.0;
                            bspPnts[2]=0.0;
                            
                            span = FindSpan(ncpC, degC, umaxC, crvKnots);
                            BasisFuns(span, umaxC, degC, crvKnots, NU, leftU, rightU);
                            
                            myint=(span-degC)*4;
                            for (i = 0; i <= degC; i++){
                                bspPnts[0]+=NU[i]*crvCP[myint];
                                bspPnts[1]+=NU[i]*crvCP[myint+1];
                                bspPnts[2]+=NU[i]*crvCP[myint+3];
                                myint+=4;
                            }
                            paramtmp[0]=bspPnts[0]/bspPnts[2];
                            paramtmp[1]=bspPnts[1]/bspPnts[2];
                            
                        }
                        
                        NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, (unsigned int)1, Pend, leftU, rightU, NU, leftV, rightV, NV);
                        
                        dir[0]=Pend[0]-P0[0];
                        dir[1]=Pend[1]-P0[1];
                        dir[2]=Pend[2]-P0[2];
                        
                        if (np>4){
                            
                            crvParams = (double*) malloc(np*sizeof(double)+1);
                            crvParams[0] = uminC;
                            
                            maxDis=-1.0;
                            du=duC/6.0;
                            cparam=uminC+du;
                            
                            for (j = 0; j < 5; j++){
                                
                                bspPnts[0]=0.0;
                                bspPnts[1]=0.0;
                                bspPnts[2]=0.0;
                                
                                span = FindSpan(ncpC, degC, cparam, crvKnots);
                                BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                                
                                myint=(span-degC)*4;
                                for (i = 0; i <= degC; i++){
                                    bspPnts[0]+=NU[i]*crvCP[myint];
                                    bspPnts[1]+=NU[i]*crvCP[myint+1];
                                    bspPnts[2]+=NU[i]*crvCP[myint+3];
                                    myint+=4;
                                }
                                paramtmp[0]=bspPnts[0]/bspPnts[2];
                                paramtmp[1]=bspPnts[1]/bspPnts[2];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                tmpDis=getPoint2lineDist(pnttmp, P0, dir);
                                
                                if (tmpDis>maxDis){
                                    
                                    param2[0]=paramtmp[0];
                                    param2[1]=paramtmp[1];
                                    
                                    P2[0]=pnttmp[0];
                                    P2[1]=pnttmp[1];
                                    P2[2]=pnttmp[2];
                                    
                                    maxDis=tmpDis;
                                    cparam2=cparam;
                                    
                                }
                                
                                cparam+=du;
                                
                            }
                            
                            maxDis=-1.0;
                            du=(cparam2-uminC)/5.0;
                            cparam=uminC+du;
                            
                            dir[0]=P2[0]-P0[0];
                            dir[1]=P2[1]-P0[1];
                            dir[2]=P2[2]-P0[2];
                            
                            for (j = 0; j < 4; j++){
                                
                                bspPnts[0]=0.0;
                                bspPnts[1]=0.0;
                                bspPnts[2]=0.0;
                                
                                span = FindSpan(ncpC, degC, cparam, crvKnots);
                                BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                                
                                myint=(span-degC)*4;
                                for (i = 0; i <= degC; i++){
                                    bspPnts[0]+=NU[i]*crvCP[myint];
                                    bspPnts[1]+=NU[i]*crvCP[myint+1];
                                    bspPnts[2]+=NU[i]*crvCP[myint+3];
                                    myint+=4;
                                }
                                paramtmp[0]=bspPnts[0]/bspPnts[2];
                                paramtmp[1]=bspPnts[1]/bspPnts[2];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                tmpDis=getPoint2lineDist(pnttmp, P0, dir);
                                
                                if (tmpDis>maxDis){
                                    
                                    param1[0]=paramtmp[0];
                                    param1[1]=paramtmp[1];
                                    
                                    P1[0]=pnttmp[0];
                                    P1[1]=pnttmp[1];
                                    P1[2]=pnttmp[2];
                                    
                                    maxDis=tmpDis;
                                    cparam1=cparam;
                                    
                                }
                                
                                cparam+=du;
                                
                            }
                            
                            maxDis=-1.0;
                            du=(umaxC-cparam2)/5.0;
                            cparam=cparam2+du;
                            
                            dir[0]=Pend[0]-P2[0];
                            dir[1]=Pend[1]-P2[1];
                            dir[2]=Pend[2]-P2[2];
                            
                            for (j = 0; j < 4; j++){
                                
                                bspPnts[0]=0.0;
                                bspPnts[1]=0.0;
                                bspPnts[2]=0.0;
                                
                                span = FindSpan(ncpC, degC, cparam, crvKnots);
                                BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                                
                                myint=(span-degC)*4;
                                for (i = 0; i <= degC; i++){
                                    bspPnts[0]+=NU[i]*crvCP[myint];
                                    bspPnts[1]+=NU[i]*crvCP[myint+1];
                                    bspPnts[2]+=NU[i]*crvCP[myint+3];
                                    myint+=4;
                                }
                                paramtmp[0]=bspPnts[0]/bspPnts[2];
                                paramtmp[1]=bspPnts[1]/bspPnts[2];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                tmpDis=getPoint2lineDist(pnttmp, P2, dir);
                                
                                if (tmpDis>maxDis){
                                    
                                    param3[0]=paramtmp[0];
                                    param3[1]=paramtmp[1];
                                    
                                    P3[0]=pnttmp[0];
                                    P3[1]=pnttmp[1];
                                    P3[2]=pnttmp[2];
                                    
                                    maxDis=tmpDis;
                                    cparam3=cparam;
                                    
                                }
                                
                                cparam+=du;
                                
                            }
                            
                            /* First curve section */
                            
                            maxDis0=-1.0;
                            du=(cparam1-uminC)/5.0;
                            cparam=uminC+du;
                            
                            dir[0]=P1[0]-P0[0];
                            dir[1]=P1[1]-P0[1];
                            dir[2]=P1[2]-P0[2];
                            
                            no0=sqrt(dir[0]*dir[0]+dir[1]*dir[1]+dir[2]*dir[2]);
                            
                            dir[0]=dir[0]/no0;
                            dir[1]=dir[1]/no0;
                            dir[2]=dir[2]/no0;
                            
                            for (j = 0; j < 4; j++){
                                
                                bspPnts[0]=0.0;
                                bspPnts[1]=0.0;
                                bspPnts[2]=0.0;
                                
                                span = FindSpan(ncpC, degC, cparam, crvKnots);
                                BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                                
                                myint=(span-degC)*4;
                                for (i = 0; i <= degC; i++){
                                    bspPnts[0]+=NU[i]*crvCP[myint];
                                    bspPnts[1]+=NU[i]*crvCP[myint+1];
                                    bspPnts[2]+=NU[i]*crvCP[myint+3];
                                    myint+=4;
                                }
                                paramtmp[0]=bspPnts[0]/bspPnts[2];
                                paramtmp[1]=bspPnts[1]/bspPnts[2];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                tmpDis=getPoint2lineDist(pnttmp, P0, dir);
                                
                                if (tmpDis>maxDis0){
                                    maxDis0=tmpDis;
                                }
                                
                                cparam+=du;
                                
                            }
                            
                            /* Second curve section */
                            
                            maxDis1=-1.0;
                            du=(cparam2-cparam1)/5.0;
                            cparam=cparam1+du;
                            
                            dir[0]=P2[0]-P1[0];
                            dir[1]=P2[1]-P1[1];
                            dir[2]=P2[2]-P1[2];
                            
                            no1=sqrt(dir[0]*dir[0]+dir[1]*dir[1]+dir[2]*dir[2]);
                            
                            dir[0]=dir[0]/no1;
                            dir[1]=dir[1]/no1;
                            dir[2]=dir[2]/no1;
                            
                            for (j = 0; j < 4; j++){
                                
                                bspPnts[0]=0.0;
                                bspPnts[1]=0.0;
                                bspPnts[2]=0.0;
                                
                                span = FindSpan(ncpC, degC, cparam, crvKnots);
                                BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                                
                                myint=(span-degC)*4;
                                for (i = 0; i <= degC; i++){
                                    bspPnts[0]+=NU[i]*crvCP[myint];
                                    bspPnts[1]+=NU[i]*crvCP[myint+1];
                                    bspPnts[2]+=NU[i]*crvCP[myint+3];
                                    myint+=4;
                                }
                                paramtmp[0]=bspPnts[0]/bspPnts[2];
                                paramtmp[1]=bspPnts[1]/bspPnts[2];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                tmpDis=getPoint2lineDist(pnttmp, P1, dir);
                                
                                if (tmpDis>maxDis1){
                                    maxDis1=tmpDis;
                                }
                                
                                cparam+=du;
                                
                            }
                            
                            /* Third curve section */
                            
                            maxDis2=-1.0;
                            du=(cparam3-cparam2)/5.0;
                            cparam=cparam2+du;
                            
                            dir[0]=P3[0]-P2[0];
                            dir[1]=P3[1]-P2[1];
                            dir[2]=P3[2]-P2[2];
                            
                            no2=sqrt(dir[0]*dir[0]+dir[1]*dir[1]+dir[2]*dir[2]);
                            
                            dir[0]=dir[0]/no2;
                            dir[1]=dir[1]/no2;
                            dir[2]=dir[2]/no2;
                            
                            for (j = 0; j < 4; j++){
                                
                                bspPnts[0]=0.0;
                                bspPnts[1]=0.0;
                                bspPnts[2]=0.0;
                                
                                span = FindSpan(ncpC, degC, cparam, crvKnots);
                                BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                                
                                myint=(span-degC)*4;
                                for (i = 0; i <= degC; i++){
                                    bspPnts[0]+=NU[i]*crvCP[myint];
                                    bspPnts[1]+=NU[i]*crvCP[myint+1];
                                    bspPnts[2]+=NU[i]*crvCP[myint+3];
                                    myint+=4;
                                }
                                paramtmp[0]=bspPnts[0]/bspPnts[2];
                                paramtmp[1]=bspPnts[1]/bspPnts[2];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                tmpDis=getPoint2lineDist(pnttmp, P2, dir);
                                
                                if (tmpDis>maxDis2){
                                    maxDis2=tmpDis;
                                }
                                
                                cparam+=du;
                                
                            }
                            
                            /* Fourth curve section */
                            
                            maxDis3=-1.0;
                            du=(umaxC-cparam3)/5.0;
                            cparam=cparam3+du;
                            
                            dir[0]=Pend[0]-P3[0];
                            dir[1]=Pend[1]-P3[1];
                            dir[2]=Pend[2]-P3[2];
                            
                            no3=sqrt(dir[0]*dir[0]+dir[1]*dir[1]+dir[2]*dir[2]);
                            
                            dir[0]=dir[0]/no3;
                            dir[1]=dir[1]/no3;
                            dir[2]=dir[2]/no3;
                            
                            for (j = 0; j < 4; j++){
                                
                                bspPnts[0]=0.0;
                                bspPnts[1]=0.0;
                                bspPnts[2]=0.0;
                                
                                span = FindSpan(ncpC, degC, cparam, crvKnots);
                                BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                                
                                myint=(span-degC)*4;
                                for (i = 0; i <= degC; i++){
                                    bspPnts[0]+=NU[i]*crvCP[myint];
                                    bspPnts[1]+=NU[i]*crvCP[myint+1];
                                    bspPnts[2]+=NU[i]*crvCP[myint+3];
                                    myint+=4;
                                }
                                paramtmp[0]=bspPnts[0]/bspPnts[2];
                                paramtmp[1]=bspPnts[1]/bspPnts[2];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                tmpDis=getPoint2lineDist(pnttmp, P3, dir);
                                
                                if (tmpDis>maxDis3){
                                    maxDis3=tmpDis;
                                }
                                
                                cparam+=du;
                                
                            }
                            
                            maxDis0=sqrt(maxDis0)+5e-3*no0;
                            maxDis1=sqrt(maxDis1)+5e-3*no1;
                            maxDis2=sqrt(maxDis2)+5e-3*no2;
                            maxDis3=sqrt(maxDis3)+5e-3*no3;
                            
                            nrem=np-4;
                            
                            tmpDis=((double)nrem)/(maxDis0+maxDis1+maxDis2+maxDis3);
                            
                            maxDis0=maxDis0*tmpDis;
                            maxDis1=maxDis1*tmpDis;
                            maxDis2=maxDis2*tmpDis;
                            maxDis3=maxDis3*tmpDis;
                            
                            n0=(int)maxDis0;
                            n1=(int)maxDis1;
                            n2=(int)maxDis2;
                            n3=(int)maxDis3;
                            
                            nrem=nrem-(n0+n1+n2+n3);
                            
                            if (nrem>0){
                                
                                maxDis0=maxDis0-(double)n0;
                                maxDis1=maxDis1-(double)n1;
                                maxDis2=maxDis2-(double)n2;
                                maxDis3=maxDis3-(double)n3;
                                
                                if (maxDis0>maxDis1){
                                    if (maxDis0>maxDis2){
                                        if (maxDis0>maxDis3){
                                            n0++;
                                            maxDis0-=0.25;
                                        }
                                        else {
                                            n3++;
                                            maxDis3-=0.25;
                                        }
                                    }
                                    else {
                                        if (maxDis2>maxDis3){
                                            n2++;
                                            maxDis2-=0.25;
                                        }
                                        else {
                                            n3++;
                                            maxDis3-=0.25;
                                        }
                                    }
                                }
                                else {
                                    if (maxDis1>maxDis2){
                                        if (maxDis1>maxDis3){
                                            n1++;
                                            maxDis1-=0.25;
                                        }
                                        else {
                                            n3++;
                                            maxDis3-=0.25;
                                        }
                                    }
                                    else {
                                        if (maxDis2>maxDis3){
                                            n2++;
                                            maxDis2-=0.25;
                                        }
                                        else {
                                            n3++;
                                            maxDis3-=0.25;
                                        }
                                    }
                                }
                                nrem--;
                                
                                if (nrem>0){
                                    
                                    if (maxDis0>maxDis1){
                                        if (maxDis0>maxDis2){
                                            if (maxDis0>maxDis3){
                                                n0++;
                                                maxDis0-=0.25;
                                            }
                                            else {
                                                n3++;
                                                maxDis3-=0.25;
                                            }
                                        }
                                        else {
                                            if (maxDis2>maxDis3){
                                                n2++;
                                                maxDis2-=0.25;
                                            }
                                            else {
                                                n3++;
                                                maxDis3-=0.25;
                                            }
                                        }
                                    }
                                    else {
                                        if (maxDis1>maxDis2){
                                            if (maxDis1>maxDis3){
                                                n1++;
                                                maxDis1-=0.25;
                                            }
                                            else {
                                                n3++;
                                                maxDis3-=0.25;
                                            }
                                        }
                                        else {
                                            if (maxDis2>maxDis3){
                                                n2++;
                                                maxDis2-=0.25;
                                            }
                                            else {
                                                n3++;
                                                maxDis3-=0.25;
                                            }
                                        }
                                    }
                                    nrem--;
                                    
                                    if (nrem>0){
                                        
                                        if (maxDis0>maxDis1){
                                            if (maxDis0>maxDis2){
                                                if (maxDis0>maxDis3){
                                                    n0++;
                                                    maxDis0-=0.25;
                                                }
                                                else {
                                                    n3++;
                                                    maxDis3-=0.25;
                                                }
                                            }
                                            else {
                                                if (maxDis2>maxDis3){
                                                    n2++;
                                                    maxDis2-=0.25;
                                                }
                                                else {
                                                    n3++;
                                                    maxDis3-=0.25;
                                                }
                                            }
                                        }
                                        else {
                                            if (maxDis1>maxDis2){
                                                if (maxDis1>maxDis3){
                                                    n1++;
                                                    maxDis1-=0.25;
                                                }
                                                else {
                                                    n3++;
                                                    maxDis3-=0.25;
                                                }
                                            }
                                            else {
                                                if (maxDis2>maxDis3){
                                                    n2++;
                                                    maxDis2-=0.25;
                                                }
                                                else {
                                                    n3++;
                                                    maxDis3-=0.25;
                                                }
                                            }
                                        }
                                        nrem--;
                                        
                                        if (nrem>0){
                                            
                                            if (maxDis0>maxDis1){
                                                if (maxDis0>maxDis2){
                                                    if (maxDis0>maxDis3){
                                                        n0++;
                                                        maxDis0-=0.25;
                                                    }
                                                    else {
                                                        n3++;
                                                        maxDis3-=0.25;
                                                    }
                                                }
                                                else {
                                                    if (maxDis2>maxDis3){
                                                        n2++;
                                                        maxDis2-=0.25;
                                                    }
                                                    else {
                                                        n3++;
                                                        maxDis3-=0.25;
                                                    }
                                                }
                                            }
                                            else {
                                                if (maxDis1>maxDis2){
                                                    if (maxDis1>maxDis3){
                                                        n1++;
                                                        maxDis1-=0.25;
                                                    }
                                                    else {
                                                        n3++;
                                                        maxDis3-=0.25;
                                                    }
                                                }
                                                else {
                                                    if (maxDis2>maxDis3){
                                                        n2++;
                                                        maxDis2-=0.25;
                                                    }
                                                    else {
                                                        n3++;
                                                        maxDis3-=0.25;
                                                    }
                                                }
                                            }
                                            
                                        }
                                        
                                    }
                                    
                                }
                                
                            }
                            
                            pind=2;
                            cind=1;
                            k=3;
                            
                            /* First curve section */
                            
                            du=(cparam1-uminC)/((double)(n0+1));
                            cparam=uminC+du;
                            
                            for (j = 0; j < n0; j++){
                                
                                bspPnts[0]=0.0;
                                bspPnts[1]=0.0;
                                bspPnts[2]=0.0;
                                
                                span = FindSpan(ncpC, degC, cparam, crvKnots);
                                BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                                
                                myint=(span-degC)*4;
                                for (i = 0; i <= degC; i++){
                                    bspPnts[0]+=NU[i]*crvCP[myint];
                                    bspPnts[1]+=NU[i]*crvCP[myint+1];
                                    bspPnts[2]+=NU[i]*crvCP[myint+3];
                                    myint+=4;
                                }
                                paramtmp[0]=bspPnts[0]/bspPnts[2];
                                paramtmp[1]=bspPnts[1]/bspPnts[2];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                mxGetPr(parametervalues)[pind]=paramtmp[0];
                                mxGetPr(parametervalues)[pind+1]=paramtmp[1];
                                
                                srfPnts[k]=pnttmp[0];
                                srfPnts[k+1]=pnttmp[1];
                                srfPnts[k+2]=pnttmp[2];
                                
                                crvParams[cind]=cparam;
                                
                                pind+=2;
                                cind++;
                                k+=3;
                                
                                cparam+=du;
                                
                            }
                            
                            mxGetPr(parametervalues)[pind]=param1[0];
                            mxGetPr(parametervalues)[pind+1]=param1[1];
                            
                            srfPnts[k]=P1[0];
                            srfPnts[k+1]=P1[1];
                            srfPnts[k+2]=P1[2];
                            
                            crvParams[cind]=cparam1;
                            
                            pind+=2;
                            cind++;
                            k+=3;
                            
                            /* Second curve section */
                            
                            du=(cparam2-cparam1)/((double)(n1+1));
                            cparam=cparam1+du;
                            
                            for (j = 0; j < n1; j++){
                                
                                bspPnts[0]=0.0;
                                bspPnts[1]=0.0;
                                bspPnts[2]=0.0;
                                
                                span = FindSpan(ncpC, degC, cparam, crvKnots);
                                BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                                
                                myint=(span-degC)*4;
                                for (i = 0; i <= degC; i++){
                                    bspPnts[0]+=NU[i]*crvCP[myint];
                                    bspPnts[1]+=NU[i]*crvCP[myint+1];
                                    bspPnts[2]+=NU[i]*crvCP[myint+3];
                                    myint+=4;
                                }
                                paramtmp[0]=bspPnts[0]/bspPnts[2];
                                paramtmp[1]=bspPnts[1]/bspPnts[2];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                mxGetPr(parametervalues)[pind]=paramtmp[0];
                                mxGetPr(parametervalues)[pind+1]=paramtmp[1];
                                
                                srfPnts[k]=pnttmp[0];
                                srfPnts[k+1]=pnttmp[1];
                                srfPnts[k+2]=pnttmp[2];
                                
                                crvParams[cind]=cparam;
                                
                                pind+=2;
                                cind++;
                                k+=3;
                                
                                cparam+=du;
                                
                            }
                            
                            mxGetPr(parametervalues)[pind]=param2[0];
                            mxGetPr(parametervalues)[pind+1]=param2[1];
                            
                            srfPnts[k]=P2[0];
                            srfPnts[k+1]=P2[1];
                            srfPnts[k+2]=P2[2];
                            
                            crvParams[cind]=cparam2;
                            
                            pind+=2;
                            cind++;
                            k+=3;
                            
                            /* Third curve section */
                            
                            du=(cparam3-cparam2)/((double)(n2+1));
                            cparam=cparam2+du;
                            
                            for (j = 0; j < n2; j++){
                                
                                bspPnts[0]=0.0;
                                bspPnts[1]=0.0;
                                bspPnts[2]=0.0;
                                
                                span = FindSpan(ncpC, degC, cparam, crvKnots);
                                BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                                
                                myint=(span-degC)*4;
                                for (i = 0; i <= degC; i++){
                                    bspPnts[0]+=NU[i]*crvCP[myint];
                                    bspPnts[1]+=NU[i]*crvCP[myint+1];
                                    bspPnts[2]+=NU[i]*crvCP[myint+3];
                                    myint+=4;
                                }
                                paramtmp[0]=bspPnts[0]/bspPnts[2];
                                paramtmp[1]=bspPnts[1]/bspPnts[2];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                mxGetPr(parametervalues)[pind]=paramtmp[0];
                                mxGetPr(parametervalues)[pind+1]=paramtmp[1];
                                
                                srfPnts[k]=pnttmp[0];
                                srfPnts[k+1]=pnttmp[1];
                                srfPnts[k+2]=pnttmp[2];
                                
                                crvParams[cind]=cparam;
                                
                                pind+=2;
                                cind++;
                                k+=3;
                                
                                cparam+=du;
                                
                            }
                            
                            mxGetPr(parametervalues)[pind]=param3[0];
                            mxGetPr(parametervalues)[pind+1]=param3[1];
                            
                            srfPnts[k]=P3[0];
                            srfPnts[k+1]=P3[1];
                            srfPnts[k+2]=P3[2];
                            
                            crvParams[cind]=cparam3;
                            
                            pind+=2;
                            cind++;
                            k+=3;
                            
                            /* Fourth curve section */
                            
                            du=(umaxC-cparam3)/((double)(n3+1));
                            cparam=cparam3+du;
                            
                            for (j = 0; j < n3; j++){
                                
                                bspPnts[0]=0.0;
                                bspPnts[1]=0.0;
                                bspPnts[2]=0.0;
                                
                                span = FindSpan(ncpC, degC, cparam, crvKnots);
                                BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                                
                                myint=(span-degC)*4;
                                for (i = 0; i <= degC; i++){
                                    bspPnts[0]+=NU[i]*crvCP[myint];
                                    bspPnts[1]+=NU[i]*crvCP[myint+1];
                                    bspPnts[2]+=NU[i]*crvCP[myint+3];
                                    myint+=4;
                                }
                                paramtmp[0]=bspPnts[0]/bspPnts[2];
                                paramtmp[1]=bspPnts[1]/bspPnts[2];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                mxGetPr(parametervalues)[pind]=paramtmp[0];
                                mxGetPr(parametervalues)[pind+1]=paramtmp[1];
                                
                                srfPnts[k]=pnttmp[0];
                                srfPnts[k+1]=pnttmp[1];
                                srfPnts[k+2]=pnttmp[2];
                                
                                crvParams[cind]=cparam;
                                
                                pind+=2;
                                cind++;
                                k+=3;
                                
                                cparam+=du;
                                
                            }
                            
                        }
                        else if (np==2){
                            
                            maxDis=-1.0;
                            du=duC/6.0;
                            cparam=uminC+du;
                            
                            for (j = 0; j < 5; j++){
                                
                                bspPnts[0]=0.0;
                                bspPnts[1]=0.0;
                                bspPnts[2]=0.0;
                                
                                span = FindSpan(ncpC, degC, cparam, crvKnots);
                                BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                                
                                myint=(span-degC)*4;
                                for (i = 0; i <= degC; i++){
                                    bspPnts[0]+=NU[i]*crvCP[myint];
                                    bspPnts[1]+=NU[i]*crvCP[myint+1];
                                    bspPnts[2]+=NU[i]*crvCP[myint+3];
                                    myint+=4;
                                }
                                paramtmp[0]=bspPnts[0]/bspPnts[2];
                                paramtmp[1]=bspPnts[1]/bspPnts[2];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                tmpDis=getPoint2lineDist(pnttmp, P0, dir);
                                
                                if (tmpDis>maxDis){
                                    
                                    mxGetPr(parametervalues)[2]=paramtmp[0];
                                    mxGetPr(parametervalues)[3]=paramtmp[1];
                                    
                                    srfPnts[3]=pnttmp[0];
                                    srfPnts[4]=pnttmp[1];
                                    srfPnts[5]=pnttmp[2];
                                    
                                    maxDis=tmpDis;
                                    cparam2=cparam;
                                    
                                }
                                
                                cparam+=du;
                                
                            }
                            
                            for (k = 0; k < 3; k++){
                                
                                du=0.5*du;
                                
                                cparam=cparam2-du;
                                
                                bspPnts[0]=0.0;
                                bspPnts[1]=0.0;
                                bspPnts[2]=0.0;
                                
                                span = FindSpan(ncpC, degC, cparam, crvKnots);
                                BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                                
                                myint=(span-degC)*4;
                                for (i = 0; i <= degC; i++){
                                    bspPnts[0]+=NU[i]*crvCP[myint];
                                    bspPnts[1]+=NU[i]*crvCP[myint+1];
                                    bspPnts[2]+=NU[i]*crvCP[myint+3];
                                    myint+=4;
                                }
                                paramtmp[0]=bspPnts[0]/bspPnts[2];
                                paramtmp[1]=bspPnts[1]/bspPnts[2];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                tmpDis=getPoint2lineDist(pnttmp, P0, dir);
                                
                                if (tmpDis>maxDis){
                                    
                                    mxGetPr(parametervalues)[2]=paramtmp[0];
                                    mxGetPr(parametervalues)[3]=paramtmp[1];
                                    
                                    srfPnts[3]=pnttmp[0];
                                    srfPnts[4]=pnttmp[1];
                                    srfPnts[5]=pnttmp[2];
                                    
                                    maxDis=tmpDis;
                                    cparam2=cparam;
                                    
                                }
                                else {
                                    
                                    cparam=cparam2+du;
                                    
                                    bspPnts[0]=0.0;
                                    bspPnts[1]=0.0;
                                    bspPnts[2]=0.0;
                                    
                                    span = FindSpan(ncpC, degC, cparam, crvKnots);
                                    BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                                    
                                    myint=(span-degC)*4;
                                    for (i = 0; i <= degC; i++){
                                        bspPnts[0]+=NU[i]*crvCP[myint];
                                        bspPnts[1]+=NU[i]*crvCP[myint+1];
                                        bspPnts[2]+=NU[i]*crvCP[myint+3];
                                        myint+=4;
                                    }
                                    paramtmp[0]=bspPnts[0]/bspPnts[2];
                                    paramtmp[1]=bspPnts[1]/bspPnts[2];
                                    
                                    NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                    
                                    tmpDis=getPoint2lineDist(pnttmp, P0, dir);
                                    
                                    if (tmpDis>maxDis){
                                        
                                        mxGetPr(parametervalues)[2]=paramtmp[0];
                                        mxGetPr(parametervalues)[3]=paramtmp[1];
                                        
                                        srfPnts[3]=pnttmp[0];
                                        srfPnts[4]=pnttmp[1];
                                        srfPnts[5]=pnttmp[2];
                                        
                                        maxDis=tmpDis;
                                        cparam2=cparam;
                                        
                                    }
                                    
                                }
                                
                            }
                            
                        }
                        else if (np==3){
                            
                            crvParams = (double*) malloc(np*sizeof(double)+1);
                            crvParams[0] = uminC;
                            
                            maxDis=-1.0;
                            du=duC/6.0;
                            cparam=uminC+du;
                            
                            for (j = 0; j < 5; j++){
                                
                                bspPnts[0]=0.0;
                                bspPnts[1]=0.0;
                                bspPnts[2]=0.0;
                                
                                span = FindSpan(ncpC, degC, cparam, crvKnots);
                                BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                                
                                myint=(span-degC)*4;
                                for (i = 0; i <= degC; i++){
                                    bspPnts[0]+=NU[i]*crvCP[myint];
                                    bspPnts[1]+=NU[i]*crvCP[myint+1];
                                    bspPnts[2]+=NU[i]*crvCP[myint+3];
                                    myint+=4;
                                }
                                paramtmp[0]=bspPnts[0]/bspPnts[2];
                                paramtmp[1]=bspPnts[1]/bspPnts[2];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                tmpDis=getPoint2lineDist(pnttmp, P0, dir);
                                
                                if (tmpDis>maxDis){
                                    
                                    param1[0]=paramtmp[0];
                                    param1[1]=paramtmp[1];
                                    
                                    P1[0]=pnttmp[0];
                                    P1[1]=pnttmp[1];
                                    P1[2]=pnttmp[2];
                                    
                                    maxDis=tmpDis;
                                    cparam2=cparam;
                                    
                                }
                                
                                cparam+=du;
                                
                            }
                            
                            maxDis=-1.0;
                            du=(cparam2-uminC)/5.0;
                            cparam=uminC+du;
                            
                            dir[0]=P1[0]-P0[0];
                            dir[1]=P1[1]-P0[1];
                            dir[2]=P1[2]-P0[2];
                            
                            tmpDis=sqrt(dir[0]*dir[0]+dir[1]*dir[1]+dir[2]*dir[2]);
                            
                            dir[0]=dir[0]/tmpDis;
                            dir[1]=dir[1]/tmpDis;
                            dir[2]=dir[2]/tmpDis;
                            
                            for (j = 0; j < 4; j++){
                                
                                bspPnts[0]=0.0;
                                bspPnts[1]=0.0;
                                bspPnts[2]=0.0;
                                
                                span = FindSpan(ncpC, degC, cparam, crvKnots);
                                BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                                
                                myint=(span-degC)*4;
                                for (i = 0; i <= degC; i++){
                                    bspPnts[0]+=NU[i]*crvCP[myint];
                                    bspPnts[1]+=NU[i]*crvCP[myint+1];
                                    bspPnts[2]+=NU[i]*crvCP[myint+3];
                                    myint+=4;
                                }
                                paramtmp[0]=bspPnts[0]/bspPnts[2];
                                paramtmp[1]=bspPnts[1]/bspPnts[2];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                tmpDis=getPoint2lineDist(pnttmp, P0, dir);
                                
                                if (tmpDis>maxDis){
                                    
                                    param2[0]=paramtmp[0];
                                    param2[1]=paramtmp[1];
                                    
                                    P2[0]=pnttmp[0];
                                    P2[1]=pnttmp[1];
                                    P2[2]=pnttmp[2];
                                    
                                    maxDis=tmpDis;
                                    cparam1=cparam;
                                    
                                }
                                
                                cparam+=du;
                                
                            }
                            
                            
                            du=(umaxC-cparam2)/5.0;
                            cparam=cparam2+du;
                            
                            dir[0]=Pend[0]-P1[0];
                            dir[1]=Pend[1]-P1[1];
                            dir[2]=Pend[2]-P1[2];
                            
                            tmpDis=sqrt(dir[0]*dir[0]+dir[1]*dir[1]+dir[2]*dir[2]);
                            
                            dir[0]=dir[0]/tmpDis;
                            dir[1]=dir[1]/tmpDis;
                            dir[2]=dir[2]/tmpDis;
                            
                            for (j = 0; j < 4; j++){
                                
                                bspPnts[0]=0.0;
                                bspPnts[1]=0.0;
                                bspPnts[2]=0.0;
                                
                                span = FindSpan(ncpC, degC, cparam, crvKnots);
                                BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                                
                                myint=(span-degC)*4;
                                for (i = 0; i <= degC; i++){
                                    bspPnts[0]+=NU[i]*crvCP[myint];
                                    bspPnts[1]+=NU[i]*crvCP[myint+1];
                                    bspPnts[2]+=NU[i]*crvCP[myint+3];
                                    myint+=4;
                                }
                                paramtmp[0]=bspPnts[0]/bspPnts[2];
                                paramtmp[1]=bspPnts[1]/bspPnts[2];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                tmpDis=getPoint2lineDist(pnttmp, P1, dir);
                                
                                if (tmpDis>maxDis){
                                    
                                    param2[0]=paramtmp[0];
                                    param2[1]=paramtmp[1];
                                    
                                    P2[0]=pnttmp[0];
                                    P2[1]=pnttmp[1];
                                    P2[2]=pnttmp[2];
                                    
                                    maxDis=tmpDis;
                                    cparam1=cparam;
                                    TrueFalse=0;
                                    
                                }
                                
                                cparam+=du;
                                
                            }
                            
                            if (TrueFalse){
                                
                                mxGetPr(parametervalues)[2]=param2[0];
                                mxGetPr(parametervalues)[3]=param2[1];
                                
                                mxGetPr(parametervalues)[4]=param1[0];
                                mxGetPr(parametervalues)[5]=param1[1];
                                
                                srfPnts[3]=P2[0];
                                srfPnts[4]=P2[1];
                                srfPnts[5]=P2[2];
                                
                                srfPnts[6]=P1[0];
                                srfPnts[7]=P1[1];
                                srfPnts[8]=P1[2];
                                
                                crvParams[1]=cparam1;
                                crvParams[2]=cparam2;
                                
                            }
                            else {
                                
                                mxGetPr(parametervalues)[2]=param1[0];
                                mxGetPr(parametervalues)[3]=param1[1];
                                
                                mxGetPr(parametervalues)[4]=param2[0];
                                mxGetPr(parametervalues)[5]=param2[1];
                                
                                srfPnts[3]=P1[0];
                                srfPnts[4]=P1[1];
                                srfPnts[5]=P1[2];
                                
                                srfPnts[6]=P2[0];
                                srfPnts[7]=P2[1];
                                srfPnts[8]=P2[2];
                                
                                crvParams[1]=cparam2;
                                crvParams[2]=cparam1;
                                
                            }
                            
                        }
                        else if (np==4){
                            
                            crvParams = (double*) malloc(np*sizeof(double)+1);
                            crvParams[0] = uminC;
                            
                            maxDis=-1.0;
                            du=duC/6.0;
                            cparam=uminC+du;
                            
                            for (j = 0; j < 5; j++){
                                
                                bspPnts[0]=0.0;
                                bspPnts[1]=0.0;
                                bspPnts[2]=0.0;
                                
                                span = FindSpan(ncpC, degC, cparam, crvKnots);
                                BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                                
                                myint=(span-degC)*4;
                                for (i = 0; i <= degC; i++){
                                    bspPnts[0]+=NU[i]*crvCP[myint];
                                    bspPnts[1]+=NU[i]*crvCP[myint+1];
                                    bspPnts[2]+=NU[i]*crvCP[myint+3];
                                    myint+=4;
                                }
                                paramtmp[0]=bspPnts[0]/bspPnts[2];
                                paramtmp[1]=bspPnts[1]/bspPnts[2];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                tmpDis=getPoint2lineDist(pnttmp, P0, dir);
                                
                                if (tmpDis>maxDis){
                                    
                                    param2[0]=paramtmp[0];
                                    param2[1]=paramtmp[1];
                                    
                                    P2[0]=pnttmp[0];
                                    P2[1]=pnttmp[1];
                                    P2[2]=pnttmp[2];
                                    
                                    maxDis=tmpDis;
                                    cparam2=cparam;
                                    
                                }
                                
                                cparam+=du;
                                
                            }
                            
                            maxDis=-1.0;
                            du=(cparam2-uminC)/5.0;
                            cparam=uminC+du;
                            
                            dir[0]=P2[0]-P0[0];
                            dir[1]=P2[1]-P0[1];
                            dir[2]=P2[2]-P0[2];
                            
                            for (j = 0; j < 4; j++){
                                
                                bspPnts[0]=0.0;
                                bspPnts[1]=0.0;
                                bspPnts[2]=0.0;
                                
                                span = FindSpan(ncpC, degC, cparam, crvKnots);
                                BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                                
                                myint=(span-degC)*4;
                                for (i = 0; i <= degC; i++){
                                    bspPnts[0]+=NU[i]*crvCP[myint];
                                    bspPnts[1]+=NU[i]*crvCP[myint+1];
                                    bspPnts[2]+=NU[i]*crvCP[myint+3];
                                    myint+=4;
                                }
                                paramtmp[0]=bspPnts[0]/bspPnts[2];
                                paramtmp[1]=bspPnts[1]/bspPnts[2];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                tmpDis=getPoint2lineDist(pnttmp, P0, dir);
                                
                                if (tmpDis>maxDis){
                                    
                                    param1[0]=paramtmp[0];
                                    param1[1]=paramtmp[1];
                                    
                                    P1[0]=pnttmp[0];
                                    P1[1]=pnttmp[1];
                                    P1[2]=pnttmp[2];
                                    
                                    maxDis=tmpDis;
                                    cparam1=cparam;
                                    
                                }
                                
                                cparam+=du;
                                
                            }
                            
                            maxDis=-1.0;
                            du=(umaxC-cparam2)/5.0;
                            cparam=cparam2+du;
                            
                            dir[0]=Pend[0]-P2[0];
                            dir[1]=Pend[1]-P2[1];
                            dir[2]=Pend[2]-P2[2];
                            
                            for (j = 0; j < 4; j++){
                                
                                bspPnts[0]=0.0;
                                bspPnts[1]=0.0;
                                bspPnts[2]=0.0;
                                
                                span = FindSpan(ncpC, degC, cparam, crvKnots);
                                BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                                
                                myint=(span-degC)*4;
                                for (i = 0; i <= degC; i++){
                                    bspPnts[0]+=NU[i]*crvCP[myint];
                                    bspPnts[1]+=NU[i]*crvCP[myint+1];
                                    bspPnts[2]+=NU[i]*crvCP[myint+3];
                                    myint+=4;
                                }
                                paramtmp[0]=bspPnts[0]/bspPnts[2];
                                paramtmp[1]=bspPnts[1]/bspPnts[2];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                tmpDis=getPoint2lineDist(pnttmp, P2, dir);
                                
                                if (tmpDis>maxDis){
                                    
                                    param3[0]=paramtmp[0];
                                    param3[1]=paramtmp[1];
                                    
                                    P3[0]=pnttmp[0];
                                    P3[1]=pnttmp[1];
                                    P3[2]=pnttmp[2];
                                    
                                    maxDis=tmpDis;
                                    cparam3=cparam;
                                    
                                }
                                
                                cparam+=du;
                                
                            }
                            
                            mxGetPr(parametervalues)[2]=param1[0];
                            mxGetPr(parametervalues)[3]=param1[1];
                            
                            mxGetPr(parametervalues)[4]=param2[0];
                            mxGetPr(parametervalues)[5]=param2[1];
                            
                            mxGetPr(parametervalues)[6]=param3[0];
                            mxGetPr(parametervalues)[7]=param3[1];
                            
                            srfPnts[3]=P1[0];
                            srfPnts[4]=P1[1];
                            srfPnts[5]=P1[2];
                            
                            srfPnts[6]=P2[0];
                            srfPnts[7]=P2[1];
                            srfPnts[8]=P2[2];
                            
                            srfPnts[9]=P3[0];
                            srfPnts[10]=P3[1];
                            srfPnts[11]=P3[2];
                            
                            crvParams[1]=cparam1;
                            crvParams[2]=cparam2;
                            crvParams[3]=cparam3;
                            
                        }
                        
                        if (np>2){
                            
                            pind=2;
                            cind=3;
                            
                            for (k = 1; k < (np-1); k++){
                                
                                dir[0]=srfPnts[cind+3]-srfPnts[cind-3];
                                dir[1]=srfPnts[cind+4]-srfPnts[cind-2];
                                dir[2]=srfPnts[cind+5]-srfPnts[cind-1];
                                
                                maxDis=getPoint2lineDist(&srfPnts[cind], &srfPnts[cind-3], dir);
                                
                                cparam=0.67*crvParams[k]+0.33*crvParams[k-1];
                                
                                bspPnts[0]=0.0;
                                bspPnts[1]=0.0;
                                bspPnts[2]=0.0;
                                
                                span = FindSpan(ncpC, degC, cparam, crvKnots);
                                BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                                
                                myint=(span-degC)*4;
                                for (i = 0; i <= degC; i++){
                                    bspPnts[0]+=NU[i]*crvCP[myint];
                                    bspPnts[1]+=NU[i]*crvCP[myint+1];
                                    bspPnts[2]+=NU[i]*crvCP[myint+3];
                                    myint+=4;
                                }
                                paramtmp[0]=bspPnts[0]/bspPnts[2];
                                paramtmp[1]=bspPnts[1]/bspPnts[2];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                tmpDis=getPoint2lineDist(pnttmp, &srfPnts[cind-3], dir);
                                
                                if (tmpDis>maxDis){
                                    
                                    crvParams[k]=cparam;
                                    
                                    mxGetPr(parametervalues)[pind]=paramtmp[0];
                                    mxGetPr(parametervalues)[pind+1]=paramtmp[1];
                                    
                                    srfPnts[cind]=pnttmp[0];
                                    srfPnts[cind+1]=pnttmp[1];
                                    srfPnts[cind+2]=pnttmp[2];
                                    
                                }
                                else {
                                    
                                    cparam=0.67*crvParams[k]+0.33*crvParams[k+1];
                                    
                                    bspPnts[0]=0.0;
                                    bspPnts[1]=0.0;
                                    bspPnts[2]=0.0;
                                    
                                    span = FindSpan(ncpC, degC, cparam, crvKnots);
                                    BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                                    
                                    myint=(span-degC)*4;
                                    for (i = 0; i <= degC; i++){
                                        bspPnts[0]+=NU[i]*crvCP[myint];
                                        bspPnts[1]+=NU[i]*crvCP[myint+1];
                                        bspPnts[2]+=NU[i]*crvCP[myint+3];
                                        myint+=4;
                                    }
                                    paramtmp[0]=bspPnts[0]/bspPnts[2];
                                    paramtmp[1]=bspPnts[1]/bspPnts[2];
                                    
                                    NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                    
                                    tmpDis=getPoint2lineDist(pnttmp, &srfPnts[cind-3], dir);
                                    
                                    if (tmpDis>maxDis){
                                        
                                        crvParams[k]=cparam;
                                        
                                        mxGetPr(parametervalues)[pind]=paramtmp[0];
                                        mxGetPr(parametervalues)[pind+1]=paramtmp[1];
                                        
                                        srfPnts[cind]=pnttmp[0];
                                        srfPnts[cind+1]=pnttmp[1];
                                        srfPnts[cind+2]=pnttmp[2];
                                        
                                    }
                                    
                                }
                                
                                pind+=2;
                                cind+=3;
                                
                            }
                            
                            k = np-1;
                            
                            dir[0]=Pend[0]-srfPnts[cind-3];
                            dir[1]=Pend[1]-srfPnts[cind-2];
                            dir[2]=Pend[2]-srfPnts[cind-1];
                            
                            maxDis=getPoint2lineDist(&srfPnts[cind], &srfPnts[cind-3], dir);
                            
                            cparam=0.67*crvParams[k]+0.33*crvParams[k-1];
                            
                            bspPnts[0]=0.0;
                            bspPnts[1]=0.0;
                            bspPnts[2]=0.0;
                            
                            span = FindSpan(ncpC, degC, cparam, crvKnots);
                            BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                            
                            myint=(span-degC)*4;
                            for (i = 0; i <= degC; i++){
                                bspPnts[0]+=NU[i]*crvCP[myint];
                                bspPnts[1]+=NU[i]*crvCP[myint+1];
                                bspPnts[2]+=NU[i]*crvCP[myint+3];
                                myint+=4;
                            }
                            paramtmp[0]=bspPnts[0]/bspPnts[2];
                            paramtmp[1]=bspPnts[1]/bspPnts[2];
                            
                            NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                            
                            tmpDis=getPoint2lineDist(pnttmp, &srfPnts[cind-3], dir);
                            
                            if (tmpDis>maxDis){
                                
                                crvParams[k]=cparam;
                                
                                mxGetPr(parametervalues)[pind]=paramtmp[0];
                                mxGetPr(parametervalues)[pind+1]=paramtmp[1];
                                
                                srfPnts[cind]=pnttmp[0];
                                srfPnts[cind+1]=pnttmp[1];
                                srfPnts[cind+2]=pnttmp[2];
                                
                            }
                            else {
                                
                                cparam=0.67*crvParams[k]+0.33*umaxC;
                                
                                bspPnts[0]=0.0;
                                bspPnts[1]=0.0;
                                bspPnts[2]=0.0;
                                
                                span = FindSpan(ncpC, degC, cparam, crvKnots);
                                BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                                
                                myint=(span-degC)*4;
                                for (i = 0; i <= degC; i++){
                                    bspPnts[0]+=NU[i]*crvCP[myint];
                                    bspPnts[1]+=NU[i]*crvCP[myint+1];
                                    bspPnts[2]+=NU[i]*crvCP[myint+3];
                                    myint+=4;
                                }
                                paramtmp[0]=bspPnts[0]/bspPnts[2];
                                paramtmp[1]=bspPnts[1]/bspPnts[2];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                tmpDis=getPoint2lineDist(pnttmp, &srfPnts[cind-3], dir);
                                
                                if (tmpDis>maxDis){
                                    
                                    crvParams[k]=cparam;
                                    
                                    mxGetPr(parametervalues)[pind]=paramtmp[0];
                                    mxGetPr(parametervalues)[pind+1]=paramtmp[1];
                                    
                                    srfPnts[cind]=pnttmp[0];
                                    srfPnts[cind+1]=pnttmp[1];
                                    srfPnts[cind+2]=pnttmp[2];
                                    
                                }
                                
                            }
                            
                            free(crvParams);
                            
                        }
                        
                    }
                    else {
                        
                        du = duC/((double)np);
                        cparam=uminC;
                        pind=1;
                        
                        if (nlhs>1){
                            
                            NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, (unsigned int)1, srfPnts, leftU, rightU, NU, leftV, rightV, NV);
                            
                            for (k = 3; k < 3*np-2; k+=3){
                                
                                cparam+=du;
                                
                                bspPnts[0]=0.0;
                                bspPnts[1]=0.0;
                                bspPnts[2]=0.0;
                                
                                span = FindSpan(ncpC, degC, cparam, crvKnots);
                                BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                                
                                myint=(span-degC)*4;
                                for (i = 0; i <= degC; i++){
                                    bspPnts[0]+=NU[i]*crvCP[myint];
                                    bspPnts[1]+=NU[i]*crvCP[myint+1];
                                    bspPnts[2]+=NU[i]*crvCP[myint+3];
                                    myint+=4;
                                }
                                paramtmp[0]=bspPnts[0]/bspPnts[2];
                                paramtmp[1]=bspPnts[1]/bspPnts[2];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, (unsigned int)1, &srfPnts[k], leftU, rightU, NU, leftV, rightV, NV);
                                
                                pind++;
                                mxGetPr(parametervalues)[pind]=paramtmp[0];
                                pind++;
                                mxGetPr(parametervalues)[pind]=paramtmp[1];
                                
                            }
                            
                        }
                        else {
                            
                            for (k = 3; k < 3*np-2; k+=3){
                                
                                cparam+=du;
                                
                                bspPnts[0]=0.0;
                                bspPnts[1]=0.0;
                                bspPnts[2]=0.0;
                                
                                span = FindSpan(ncpC, degC, cparam, crvKnots);
                                BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                                
                                myint=(span-degC)*4;
                                for (i = 0; i <= degC; i++){
                                    bspPnts[0]+=NU[i]*crvCP[myint];
                                    bspPnts[1]+=NU[i]*crvCP[myint+1];
                                    bspPnts[2]+=NU[i]*crvCP[myint+3];
                                    myint+=4;
                                }
                                paramtmp[0]=bspPnts[0]/bspPnts[2];
                                paramtmp[1]=bspPnts[1]/bspPnts[2];
                                
                                pind++;
                                mxGetPr(parametervalues)[pind]=paramtmp[0];
                                pind++;
                                mxGetPr(parametervalues)[pind]=paramtmp[1];
                                
                            }
                            
                        }
                        
                    }
                    
                }
                
            }
            else if (nrhs==5){
                
                evFlg = (char)mxGetScalar(evaliFlag);
                
                if (nlhs==2){
                    evaluated_points = mxCreateDoubleMatrix(3, np, mxREAL);
                    srfPnts = (double*)mxGetPr(evaluated_points);
                }
                else if (evFlg>0 && np>1){
                    srfPnts = (double*) malloc((3*np)*sizeof(double)+1);
                }
                
                if (np==0){
                    return;
                }
                
                leftU  = (double*) malloc(orderU*sizeof(double)+1);
                rightU = (double*) malloc(orderU*sizeof(double)+1);
                NU = (double*) malloc(orderU*sizeof(double)+1);
                leftV  = (double*) malloc(orderV*sizeof(double)+1);
                rightV = (double*) malloc(orderV*sizeof(double)+1);
                NV = (double*) malloc(orderV*sizeof(double)+1);
                
                srfCP = mxGetPr(mxGetField(nurbsSRF, 0, "coefs"));
                srfKnotsU = mxGetPr(mxGetCell(mxGetField(nurbsSRF, 0, "knots"), 0));
                srfKnotsV = mxGetPr(mxGetCell(mxGetField(nurbsSRF, 0, "knots"), 1));
                
                if (np==1){
                    
                    mxGetPr(parametervalues)[0]=mxGetPr(pntStart)[0];
                    mxGetPr(parametervalues)[1]=mxGetPr(pntStart)[1];
                    
                    if (nlhs==2){
                        NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, mxGetPr(parametervalues), 1, srfPnts, leftU, rightU, NU, leftV, rightV, NV);
                    }
                    
                }
                else {
                    
                    bspPnts[0]=mxGetPr(pntTermi)[0]-mxGetPr(pntStart)[0];
                    bspPnts[1]=mxGetPr(pntTermi)[1]-mxGetPr(pntStart)[1];
                    
                    paramtmp[0]=mxGetPr(pntStart)[0];
                    paramtmp[1]=mxGetPr(pntStart)[1];
                    
                    lineSt[0]=paramtmp[0];
                    lineSt[1]=paramtmp[1];
                    
                    mxGetPr(parametervalues)[0]=paramtmp[0];
                    mxGetPr(parametervalues)[1]=paramtmp[1];
                    
                    if (evFlg==1){
                        
                        NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, (unsigned int)1, P0, leftU, rightU, NU, leftV, rightV, NV);
                        
                        srfPnts[0]=P0[0];
                        srfPnts[1]=P0[1];
                        srfPnts[2]=P0[2];
                        
                        paramtmp[0]=mxGetPr(pntTermi)[0];
                        paramtmp[1]=mxGetPr(pntTermi)[1];
                        
                        NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, (unsigned int)1, Pend, leftU, rightU, NU, leftV, rightV, NV);
                        
                        dir[0]=Pend[0]-P0[0];
                        dir[1]=Pend[1]-P0[1];
                        dir[2]=Pend[2]-P0[2];
                        
                        if (np>4){
                            
                            crvParams = (double*) malloc(np*sizeof(double)+1);
                            crvParams[0] = 0.0;
                            
                            maxDis=-1.0;
                            du=1.0/6.0;
                            cparam=du;
                            
                            for (j = 0; j < 5; j++){
                                
                                paramtmp[0]=lineSt[0]+cparam*bspPnts[0];
                                paramtmp[1]=lineSt[1]+cparam*bspPnts[1];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                tmpDis=getPoint2lineDist(pnttmp, P0, dir);
                                
                                if (tmpDis>maxDis){
                                    
                                    param2[0]=paramtmp[0];
                                    param2[1]=paramtmp[1];
                                    
                                    P2[0]=pnttmp[0];
                                    P2[1]=pnttmp[1];
                                    P2[2]=pnttmp[2];
                                    
                                    maxDis=tmpDis;
                                    cparam2=cparam;
                                    
                                }
                                
                                cparam+=du;
                                
                            }
                            
                            maxDis=-1.0;
                            du=(cparam2)/5.0;
                            cparam=du;
                            
                            dir[0]=P2[0]-P0[0];
                            dir[1]=P2[1]-P0[1];
                            dir[2]=P2[2]-P0[2];
                            
                            for (j = 0; j < 4; j++){
                                
                                paramtmp[0]=lineSt[0]+cparam*bspPnts[0];
                                paramtmp[1]=lineSt[1]+cparam*bspPnts[1];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                tmpDis=getPoint2lineDist(pnttmp, P0, dir);
                                
                                if (tmpDis>maxDis){
                                    
                                    param1[0]=paramtmp[0];
                                    param1[1]=paramtmp[1];
                                    
                                    P1[0]=pnttmp[0];
                                    P1[1]=pnttmp[1];
                                    P1[2]=pnttmp[2];
                                    
                                    maxDis=tmpDis;
                                    cparam1=cparam;
                                    
                                }
                                
                                cparam+=du;
                                
                            }
                            
                            maxDis=-1.0;
                            du=(1.0-cparam2)/5.0;
                            cparam=cparam2+du;
                            
                            dir[0]=Pend[0]-P2[0];
                            dir[1]=Pend[1]-P2[1];
                            dir[2]=Pend[2]-P2[2];
                            
                            for (j = 0; j < 4; j++){
                                
                                paramtmp[0]=lineSt[0]+cparam*bspPnts[0];
                                paramtmp[1]=lineSt[1]+cparam*bspPnts[1];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                tmpDis=getPoint2lineDist(pnttmp, P2, dir);
                                
                                if (tmpDis>maxDis){
                                    
                                    param3[0]=paramtmp[0];
                                    param3[1]=paramtmp[1];
                                    
                                    P3[0]=pnttmp[0];
                                    P3[1]=pnttmp[1];
                                    P3[2]=pnttmp[2];
                                    
                                    maxDis=tmpDis;
                                    cparam3=cparam;
                                    
                                }
                                
                                cparam+=du;
                                
                            }
                            
                            /* First curve section */
                            
                            maxDis0=-1.0;
                            du=(cparam1)/5.0;
                            cparam=du;
                            
                            dir[0]=P1[0]-P0[0];
                            dir[1]=P1[1]-P0[1];
                            dir[2]=P1[2]-P0[2];
                            
                            no0=sqrt(dir[0]*dir[0]+dir[1]*dir[1]+dir[2]*dir[2]);
                            
                            dir[0]=dir[0]/no0;
                            dir[1]=dir[1]/no0;
                            dir[2]=dir[2]/no0;
                            
                            for (j = 0; j < 4; j++){
                                
                                paramtmp[0]=lineSt[0]+cparam*bspPnts[0];
                                paramtmp[1]=lineSt[1]+cparam*bspPnts[1];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                tmpDis=getPoint2lineDist(pnttmp, P0, dir);
                                
                                if (tmpDis>maxDis0){
                                    maxDis0=tmpDis;
                                }
                                
                                cparam+=du;
                                
                            }
                            
                            /* Second curve section */
                            
                            maxDis1=-1.0;
                            du=(cparam2-cparam1)/5.0;
                            cparam=cparam1+du;
                            
                            dir[0]=P2[0]-P1[0];
                            dir[1]=P2[1]-P1[1];
                            dir[2]=P2[2]-P1[2];
                            
                            no1=sqrt(dir[0]*dir[0]+dir[1]*dir[1]+dir[2]*dir[2]);
                            
                            dir[0]=dir[0]/no1;
                            dir[1]=dir[1]/no1;
                            dir[2]=dir[2]/no1;
                            
                            for (j = 0; j < 4; j++){
                                
                                paramtmp[0]=lineSt[0]+cparam*bspPnts[0];
                                paramtmp[1]=lineSt[1]+cparam*bspPnts[1];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                tmpDis=getPoint2lineDist(pnttmp, P1, dir);
                                
                                if (tmpDis>maxDis1){
                                    maxDis1=tmpDis;
                                }
                                
                                cparam+=du;
                                
                            }
                            
                            /* Third curve section */
                            
                            maxDis2=-1.0;
                            du=(cparam3-cparam2)/5.0;
                            cparam=cparam2+du;
                            
                            dir[0]=P3[0]-P2[0];
                            dir[1]=P3[1]-P2[1];
                            dir[2]=P3[2]-P2[2];
                            
                            no2=sqrt(dir[0]*dir[0]+dir[1]*dir[1]+dir[2]*dir[2]);
                            
                            dir[0]=dir[0]/no2;
                            dir[1]=dir[1]/no2;
                            dir[2]=dir[2]/no2;
                            
                            for (j = 0; j < 4; j++){
                                
                                paramtmp[0]=lineSt[0]+cparam*bspPnts[0];
                                paramtmp[1]=lineSt[1]+cparam*bspPnts[1];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                tmpDis=getPoint2lineDist(pnttmp, P2, dir);
                                
                                if (tmpDis>maxDis2){
                                    maxDis2=tmpDis;
                                }
                                
                                cparam+=du;
                                
                            }
                            
                            /* Fourth curve section */
                            
                            maxDis3=-1.0;
                            du=(1.0-cparam3)/5.0;
                            cparam=cparam3+du;
                            
                            dir[0]=Pend[0]-P3[0];
                            dir[1]=Pend[1]-P3[1];
                            dir[2]=Pend[2]-P3[2];
                            
                            no3=sqrt(dir[0]*dir[0]+dir[1]*dir[1]+dir[2]*dir[2]);
                            
                            dir[0]=dir[0]/no3;
                            dir[1]=dir[1]/no3;
                            dir[2]=dir[2]/no3;
                            
                            for (j = 0; j < 4; j++){
                                
                                paramtmp[0]=lineSt[0]+cparam*bspPnts[0];
                                paramtmp[1]=lineSt[1]+cparam*bspPnts[1];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                tmpDis=getPoint2lineDist(pnttmp, P3, dir);
                                
                                if (tmpDis>maxDis3){
                                    maxDis3=tmpDis;
                                }
                                
                                cparam+=du;
                                
                            }
                            
                            maxDis0=sqrt(maxDis0)+5e-3*no0;
                            maxDis1=sqrt(maxDis1)+5e-3*no1;
                            maxDis2=sqrt(maxDis2)+5e-3*no2;
                            maxDis3=sqrt(maxDis3)+5e-3*no3;
                            
                            nrem=np-4;
                            
                            tmpDis=((double)nrem)/(maxDis0+maxDis1+maxDis2+maxDis3);
                            
                            maxDis0=maxDis0*tmpDis;
                            maxDis1=maxDis1*tmpDis;
                            maxDis2=maxDis2*tmpDis;
                            maxDis3=maxDis3*tmpDis;
                            
                            n0=(int)maxDis0;
                            n1=(int)maxDis1;
                            n2=(int)maxDis2;
                            n3=(int)maxDis3;
                            
                            nrem=nrem-(n0+n1+n2+n3);
                            
                            if (nrem>0){
                                
                                maxDis0=maxDis0-(double)n0;
                                maxDis1=maxDis1-(double)n1;
                                maxDis2=maxDis2-(double)n2;
                                maxDis3=maxDis3-(double)n3;
                                
                                if (maxDis0>maxDis1){
                                    if (maxDis0>maxDis2){
                                        if (maxDis0>maxDis3){
                                            n0++;
                                            maxDis0-=0.25;
                                        }
                                        else {
                                            n3++;
                                            maxDis3-=0.25;
                                        }
                                    }
                                    else {
                                        if (maxDis2>maxDis3){
                                            n2++;
                                            maxDis2-=0.25;
                                        }
                                        else {
                                            n3++;
                                            maxDis3-=0.25;
                                        }
                                    }
                                }
                                else {
                                    if (maxDis1>maxDis2){
                                        if (maxDis1>maxDis3){
                                            n1++;
                                            maxDis1-=0.25;
                                        }
                                        else {
                                            n3++;
                                            maxDis3-=0.25;
                                        }
                                    }
                                    else {
                                        if (maxDis2>maxDis3){
                                            n2++;
                                            maxDis2-=0.25;
                                        }
                                        else {
                                            n3++;
                                            maxDis3-=0.25;
                                        }
                                    }
                                }
                                nrem--;
                                
                                if (nrem>0){
                                    
                                    if (maxDis0>maxDis1){
                                        if (maxDis0>maxDis2){
                                            if (maxDis0>maxDis3){
                                                n0++;
                                                maxDis0-=0.25;
                                            }
                                            else {
                                                n3++;
                                                maxDis3-=0.25;
                                            }
                                        }
                                        else {
                                            if (maxDis2>maxDis3){
                                                n2++;
                                                maxDis2-=0.25;
                                            }
                                            else {
                                                n3++;
                                                maxDis3-=0.25;
                                            }
                                        }
                                    }
                                    else {
                                        if (maxDis1>maxDis2){
                                            if (maxDis1>maxDis3){
                                                n1++;
                                                maxDis1-=0.25;
                                            }
                                            else {
                                                n3++;
                                                maxDis3-=0.25;
                                            }
                                        }
                                        else {
                                            if (maxDis2>maxDis3){
                                                n2++;
                                                maxDis2-=0.25;
                                            }
                                            else {
                                                n3++;
                                                maxDis3-=0.25;
                                            }
                                        }
                                    }
                                    nrem--;
                                    
                                    if (nrem>0){
                                        
                                        if (maxDis0>maxDis1){
                                            if (maxDis0>maxDis2){
                                                if (maxDis0>maxDis3){
                                                    n0++;
                                                    maxDis0-=0.25;
                                                }
                                                else {
                                                    n3++;
                                                    maxDis3-=0.25;
                                                }
                                            }
                                            else {
                                                if (maxDis2>maxDis3){
                                                    n2++;
                                                    maxDis2-=0.25;
                                                }
                                                else {
                                                    n3++;
                                                    maxDis3-=0.25;
                                                }
                                            }
                                        }
                                        else {
                                            if (maxDis1>maxDis2){
                                                if (maxDis1>maxDis3){
                                                    n1++;
                                                    maxDis1-=0.25;
                                                }
                                                else {
                                                    n3++;
                                                    maxDis3-=0.25;
                                                }
                                            }
                                            else {
                                                if (maxDis2>maxDis3){
                                                    n2++;
                                                    maxDis2-=0.25;
                                                }
                                                else {
                                                    n3++;
                                                    maxDis3-=0.25;
                                                }
                                            }
                                        }
                                        nrem--;
                                        
                                        if (nrem>0){
                                            
                                            if (maxDis0>maxDis1){
                                                if (maxDis0>maxDis2){
                                                    if (maxDis0>maxDis3){
                                                        n0++;
                                                        maxDis0-=0.25;
                                                    }
                                                    else {
                                                        n3++;
                                                        maxDis3-=0.25;
                                                    }
                                                }
                                                else {
                                                    if (maxDis2>maxDis3){
                                                        n2++;
                                                        maxDis2-=0.25;
                                                    }
                                                    else {
                                                        n3++;
                                                        maxDis3-=0.25;
                                                    }
                                                }
                                            }
                                            else {
                                                if (maxDis1>maxDis2){
                                                    if (maxDis1>maxDis3){
                                                        n1++;
                                                        maxDis1-=0.25;
                                                    }
                                                    else {
                                                        n3++;
                                                        maxDis3-=0.25;
                                                    }
                                                }
                                                else {
                                                    if (maxDis2>maxDis3){
                                                        n2++;
                                                        maxDis2-=0.25;
                                                    }
                                                    else {
                                                        n3++;
                                                        maxDis3-=0.25;
                                                    }
                                                }
                                            }
                                            
                                        }
                                        
                                    }
                                    
                                }
                                
                            }
                            
                            pind=2;
                            cind=1;
                            k=3;
                            
                            /* First curve section */
                            
                            du=(cparam1)/((double)(n0+1));
                            cparam=du;
                            
                            for (j = 0; j < n0; j++){
                                
                                paramtmp[0]=lineSt[0]+cparam*bspPnts[0];
                                paramtmp[1]=lineSt[1]+cparam*bspPnts[1];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                mxGetPr(parametervalues)[pind]=paramtmp[0];
                                mxGetPr(parametervalues)[pind+1]=paramtmp[1];
                                
                                srfPnts[k]=pnttmp[0];
                                srfPnts[k+1]=pnttmp[1];
                                srfPnts[k+2]=pnttmp[2];
                                
                                crvParams[cind]=cparam;
                                
                                pind+=2;
                                cind++;
                                k+=3;
                                
                                cparam+=du;
                                
                            }
                            
                            mxGetPr(parametervalues)[pind]=param1[0];
                            mxGetPr(parametervalues)[pind+1]=param1[1];
                            
                            srfPnts[k]=P1[0];
                            srfPnts[k+1]=P1[1];
                            srfPnts[k+2]=P1[2];
                            
                            crvParams[cind]=cparam1;
                            
                            pind+=2;
                            cind++;
                            k+=3;
                            
                            /* Second curve section */
                            
                            du=(cparam2-cparam1)/((double)(n1+1));
                            cparam=cparam1+du;
                            
                            for (j = 0; j < n1; j++){
                                
                                paramtmp[0]=lineSt[0]+cparam*bspPnts[0];
                                paramtmp[1]=lineSt[1]+cparam*bspPnts[1];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                mxGetPr(parametervalues)[pind]=paramtmp[0];
                                mxGetPr(parametervalues)[pind+1]=paramtmp[1];
                                
                                srfPnts[k]=pnttmp[0];
                                srfPnts[k+1]=pnttmp[1];
                                srfPnts[k+2]=pnttmp[2];
                                
                                crvParams[cind]=cparam;
                                
                                pind+=2;
                                cind++;
                                k+=3;
                                
                                cparam+=du;
                                
                            }
                            
                            mxGetPr(parametervalues)[pind]=param2[0];
                            mxGetPr(parametervalues)[pind+1]=param2[1];
                            
                            srfPnts[k]=P2[0];
                            srfPnts[k+1]=P2[1];
                            srfPnts[k+2]=P2[2];
                            
                            crvParams[cind]=cparam2;
                            
                            pind+=2;
                            cind++;
                            k+=3;
                            
                            /* Third curve section */
                            
                            du=(cparam3-cparam2)/((double)(n2+1));
                            cparam=cparam2+du;
                            
                            for (j = 0; j < n2; j++){
                                
                                paramtmp[0]=lineSt[0]+cparam*bspPnts[0];
                                paramtmp[1]=lineSt[1]+cparam*bspPnts[1];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                mxGetPr(parametervalues)[pind]=paramtmp[0];
                                mxGetPr(parametervalues)[pind+1]=paramtmp[1];
                                
                                srfPnts[k]=pnttmp[0];
                                srfPnts[k+1]=pnttmp[1];
                                srfPnts[k+2]=pnttmp[2];
                                
                                crvParams[cind]=cparam;
                                
                                pind+=2;
                                cind++;
                                k+=3;
                                
                                cparam+=du;
                                
                            }
                            
                            mxGetPr(parametervalues)[pind]=param3[0];
                            mxGetPr(parametervalues)[pind+1]=param3[1];
                            
                            srfPnts[k]=P3[0];
                            srfPnts[k+1]=P3[1];
                            srfPnts[k+2]=P3[2];
                            
                            crvParams[cind]=cparam3;
                            
                            pind+=2;
                            cind++;
                            k+=3;
                            
                            /* Fourth curve section */
                            
                            du=(1.0-cparam3)/((double)(n3+1));
                            cparam=cparam3+du;
                            
                            for (j = 0; j < n3; j++){
                                
                                paramtmp[0]=lineSt[0]+cparam*bspPnts[0];
                                paramtmp[1]=lineSt[1]+cparam*bspPnts[1];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                mxGetPr(parametervalues)[pind]=paramtmp[0];
                                mxGetPr(parametervalues)[pind+1]=paramtmp[1];
                                
                                srfPnts[k]=pnttmp[0];
                                srfPnts[k+1]=pnttmp[1];
                                srfPnts[k+2]=pnttmp[2];
                                
                                crvParams[cind]=cparam;
                                
                                pind+=2;
                                cind++;
                                k+=3;
                                
                                cparam+=du;
                                
                            }
                            
                        }
                        else if (np==2){
                            
                            maxDis=-1.0;
                            du=1.0/6.0;
                            cparam=du;
                            
                            for (j = 0; j < 5; j++){
                                
                                paramtmp[0]=lineSt[0]+cparam*bspPnts[0];
                                paramtmp[1]=lineSt[1]+cparam*bspPnts[1];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                tmpDis=getPoint2lineDist(pnttmp, P0, dir);
                                
                                if (tmpDis>maxDis){
                                    
                                    mxGetPr(parametervalues)[2]=paramtmp[0];
                                    mxGetPr(parametervalues)[3]=paramtmp[1];
                                    
                                    srfPnts[3]=pnttmp[0];
                                    srfPnts[4]=pnttmp[1];
                                    srfPnts[5]=pnttmp[2];
                                    
                                    maxDis=tmpDis;
                                    cparam2=cparam;
                                    
                                }
                                
                                cparam+=du;
                                
                            }
                            
                            for (k = 0; k < 3; k++){
                                
                                du=0.5*du;
                                
                                cparam=cparam2-du;
                                
                                paramtmp[0]=lineSt[0]+cparam*bspPnts[0];
                                paramtmp[1]=lineSt[1]+cparam*bspPnts[1];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                tmpDis=getPoint2lineDist(pnttmp, P0, dir);
                                
                                if (tmpDis>maxDis){
                                    
                                    mxGetPr(parametervalues)[2]=paramtmp[0];
                                    mxGetPr(parametervalues)[3]=paramtmp[1];
                                    
                                    srfPnts[3]=pnttmp[0];
                                    srfPnts[4]=pnttmp[1];
                                    srfPnts[5]=pnttmp[2];
                                    
                                    maxDis=tmpDis;
                                    cparam2=cparam;
                                    
                                }
                                else {
                                    
                                    cparam=cparam2+du;
                                    
                                    paramtmp[0]=lineSt[0]+cparam*bspPnts[0];
                                    paramtmp[1]=lineSt[1]+cparam*bspPnts[1];
                                    
                                    NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                    
                                    tmpDis=getPoint2lineDist(pnttmp, P0, dir);
                                    
                                    if (tmpDis>maxDis){
                                        
                                        mxGetPr(parametervalues)[2]=paramtmp[0];
                                        mxGetPr(parametervalues)[3]=paramtmp[1];
                                        
                                        srfPnts[3]=pnttmp[0];
                                        srfPnts[4]=pnttmp[1];
                                        srfPnts[5]=pnttmp[2];
                                        
                                        maxDis=tmpDis;
                                        cparam2=cparam;
                                        
                                    }
                                    
                                }
                                
                            }
                            
                        }
                        else if (np==3){
                            
                            crvParams = (double*) malloc(np*sizeof(double)+1);
                            crvParams[0] = 0.0;
                            
                            maxDis=-1.0;
                            du=1.0/6.0;
                            cparam=du;
                            
                            for (j = 0; j < 5; j++){
                                
                                paramtmp[0]=lineSt[0]+cparam*bspPnts[0];
                                paramtmp[1]=lineSt[1]+cparam*bspPnts[1];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                tmpDis=getPoint2lineDist(pnttmp, P0, dir);
                                
                                if (tmpDis>maxDis){
                                    
                                    param1[0]=paramtmp[0];
                                    param1[1]=paramtmp[1];
                                    
                                    P1[0]=pnttmp[0];
                                    P1[1]=pnttmp[1];
                                    P1[2]=pnttmp[2];
                                    
                                    maxDis=tmpDis;
                                    cparam2=cparam;
                                    
                                }
                                
                                cparam+=du;
                                
                            }
                            
                            maxDis=-1.0;
                            du=(cparam2)/5.0;
                            cparam=du;
                            
                            dir[0]=P1[0]-P0[0];
                            dir[1]=P1[1]-P0[1];
                            dir[2]=P1[2]-P0[2];
                            
                            tmpDis=sqrt(dir[0]*dir[0]+dir[1]*dir[1]+dir[2]*dir[2]);
                            
                            dir[0]=dir[0]/tmpDis;
                            dir[1]=dir[1]/tmpDis;
                            dir[2]=dir[2]/tmpDis;
                            
                            for (j = 0; j < 4; j++){
                                
                                paramtmp[0]=lineSt[0]+cparam*bspPnts[0];
                                paramtmp[1]=lineSt[1]+cparam*bspPnts[1];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                tmpDis=getPoint2lineDist(pnttmp, P0, dir);
                                
                                if (tmpDis>maxDis){
                                    
                                    param2[0]=paramtmp[0];
                                    param2[1]=paramtmp[1];
                                    
                                    P2[0]=pnttmp[0];
                                    P2[1]=pnttmp[1];
                                    P2[2]=pnttmp[2];
                                    
                                    maxDis=tmpDis;
                                    cparam1=cparam;
                                    
                                }
                                
                                cparam+=du;
                                
                            }
                            
                            
                            du=(1.0-cparam2)/5.0;
                            cparam=cparam2+du;
                            
                            dir[0]=Pend[0]-P1[0];
                            dir[1]=Pend[1]-P1[1];
                            dir[2]=Pend[2]-P1[2];
                            
                            tmpDis=sqrt(dir[0]*dir[0]+dir[1]*dir[1]+dir[2]*dir[2]);
                            
                            dir[0]=dir[0]/tmpDis;
                            dir[1]=dir[1]/tmpDis;
                            dir[2]=dir[2]/tmpDis;
                            
                            for (j = 0; j < 4; j++){
                                
                                paramtmp[0]=lineSt[0]+cparam*bspPnts[0];
                                paramtmp[1]=lineSt[1]+cparam*bspPnts[1];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                tmpDis=getPoint2lineDist(pnttmp, P1, dir);
                                
                                if (tmpDis>maxDis){
                                    
                                    param2[0]=paramtmp[0];
                                    param2[1]=paramtmp[1];
                                    
                                    P2[0]=pnttmp[0];
                                    P2[1]=pnttmp[1];
                                    P2[2]=pnttmp[2];
                                    
                                    maxDis=tmpDis;
                                    cparam1=cparam;
                                    TrueFalse=0;
                                    
                                }
                                
                                cparam+=du;
                                
                            }
                            
                            if (TrueFalse){
                                
                                mxGetPr(parametervalues)[2]=param2[0];
                                mxGetPr(parametervalues)[3]=param2[1];
                                
                                mxGetPr(parametervalues)[4]=param1[0];
                                mxGetPr(parametervalues)[5]=param1[1];
                                
                                srfPnts[3]=P2[0];
                                srfPnts[4]=P2[1];
                                srfPnts[5]=P2[2];
                                
                                srfPnts[6]=P1[0];
                                srfPnts[7]=P1[1];
                                srfPnts[8]=P1[2];
                                
                                crvParams[1]=cparam1;
                                crvParams[2]=cparam2;
                                
                            }
                            else {
                                
                                mxGetPr(parametervalues)[2]=param1[0];
                                mxGetPr(parametervalues)[3]=param1[1];
                                
                                mxGetPr(parametervalues)[4]=param2[0];
                                mxGetPr(parametervalues)[5]=param2[1];
                                
                                srfPnts[3]=P1[0];
                                srfPnts[4]=P1[1];
                                srfPnts[5]=P1[2];
                                
                                srfPnts[6]=P2[0];
                                srfPnts[7]=P2[1];
                                srfPnts[8]=P2[2];
                                
                                crvParams[1]=cparam2;
                                crvParams[2]=cparam1;
                                
                            }
                            
                        }
                        else if (np==4){
                            
                            crvParams = (double*) malloc(np*sizeof(double)+1);
                            crvParams[0] = 0.0;
                            
                            maxDis=-1.0;
                            du=1.0/6.0;
                            cparam=du;
                            
                            for (j = 0; j < 5; j++){
                                
                                paramtmp[0]=lineSt[0]+cparam*bspPnts[0];
                                paramtmp[1]=lineSt[1]+cparam*bspPnts[1];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                tmpDis=getPoint2lineDist(pnttmp, P0, dir);
                                
                                if (tmpDis>maxDis){
                                    
                                    param2[0]=paramtmp[0];
                                    param2[1]=paramtmp[1];
                                    
                                    P2[0]=pnttmp[0];
                                    P2[1]=pnttmp[1];
                                    P2[2]=pnttmp[2];
                                    
                                    maxDis=tmpDis;
                                    cparam2=cparam;
                                    
                                }
                                
                                cparam+=du;
                                
                            }
                            
                            maxDis=-1.0;
                            du=(cparam2)/5.0;
                            cparam=du;
                            
                            dir[0]=P2[0]-P0[0];
                            dir[1]=P2[1]-P0[1];
                            dir[2]=P2[2]-P0[2];
                            
                            for (j = 0; j < 4; j++){
                                
                                paramtmp[0]=lineSt[0]+cparam*bspPnts[0];
                                paramtmp[1]=lineSt[1]+cparam*bspPnts[1];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                tmpDis=getPoint2lineDist(pnttmp, P0, dir);
                                
                                if (tmpDis>maxDis){
                                    
                                    param1[0]=paramtmp[0];
                                    param1[1]=paramtmp[1];
                                    
                                    P1[0]=pnttmp[0];
                                    P1[1]=pnttmp[1];
                                    P1[2]=pnttmp[2];
                                    
                                    maxDis=tmpDis;
                                    cparam1=cparam;
                                    
                                }
                                
                                cparam+=du;
                                
                            }
                            
                            maxDis=-1.0;
                            du=(1.0-cparam2)/5.0;
                            cparam=cparam2+du;
                            
                            dir[0]=Pend[0]-P2[0];
                            dir[1]=Pend[1]-P2[1];
                            dir[2]=Pend[2]-P2[2];
                            
                            for (j = 0; j < 4; j++){
                                
                                paramtmp[0]=lineSt[0]+cparam*bspPnts[0];
                                paramtmp[1]=lineSt[1]+cparam*bspPnts[1];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                tmpDis=getPoint2lineDist(pnttmp, P2, dir);
                                
                                if (tmpDis>maxDis){
                                    
                                    param3[0]=paramtmp[0];
                                    param3[1]=paramtmp[1];
                                    
                                    P3[0]=pnttmp[0];
                                    P3[1]=pnttmp[1];
                                    P3[2]=pnttmp[2];
                                    
                                    maxDis=tmpDis;
                                    cparam3=cparam;
                                    
                                }
                                
                                cparam+=du;
                                
                            }
                            
                            mxGetPr(parametervalues)[2]=param1[0];
                            mxGetPr(parametervalues)[3]=param1[1];
                            
                            mxGetPr(parametervalues)[4]=param2[0];
                            mxGetPr(parametervalues)[5]=param2[1];
                            
                            mxGetPr(parametervalues)[6]=param3[0];
                            mxGetPr(parametervalues)[7]=param3[1];
                            
                            srfPnts[3]=P1[0];
                            srfPnts[4]=P1[1];
                            srfPnts[5]=P1[2];
                            
                            srfPnts[6]=P2[0];
                            srfPnts[7]=P2[1];
                            srfPnts[8]=P2[2];
                            
                            srfPnts[9]=P3[0];
                            srfPnts[10]=P3[1];
                            srfPnts[11]=P3[2];
                            
                            crvParams[1]=cparam1;
                            crvParams[2]=cparam2;
                            crvParams[3]=cparam3;
                            
                        }
                        
                        if (np>2){
                            
                            pind=2;
                            cind=3;
                            
                            for (k = 1; k < (np-1); k++){
                                
                                dir[0]=srfPnts[cind+3]-srfPnts[cind-3];
                                dir[1]=srfPnts[cind+4]-srfPnts[cind-2];
                                dir[2]=srfPnts[cind+5]-srfPnts[cind-1];
                                
                                maxDis=getPoint2lineDist(&srfPnts[cind], &srfPnts[cind-3], dir);
                                
                                cparam=0.67*crvParams[k]+0.33*crvParams[k-1];
                                
                                paramtmp[0]=lineSt[0]+cparam*bspPnts[0];
                                paramtmp[1]=lineSt[1]+cparam*bspPnts[1];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                tmpDis=getPoint2lineDist(pnttmp, &srfPnts[cind-3], dir);
                                
                                if (tmpDis>maxDis){
                                    
                                    crvParams[k]=cparam;
                                    
                                    mxGetPr(parametervalues)[pind]=paramtmp[0];
                                    mxGetPr(parametervalues)[pind+1]=paramtmp[1];
                                    
                                    srfPnts[cind]=pnttmp[0];
                                    srfPnts[cind+1]=pnttmp[1];
                                    srfPnts[cind+2]=pnttmp[2];
                                    
                                }
                                else {
                                    
                                    cparam=0.67*crvParams[k]+0.33*crvParams[k+1];
                                    
                                    paramtmp[0]=lineSt[0]+cparam*bspPnts[0];
                                    paramtmp[1]=lineSt[1]+cparam*bspPnts[1];
                                    
                                    NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                    
                                    tmpDis=getPoint2lineDist(pnttmp, &srfPnts[cind-3], dir);
                                    
                                    if (tmpDis>maxDis){
                                        
                                        crvParams[k]=cparam;
                                        
                                        mxGetPr(parametervalues)[pind]=paramtmp[0];
                                        mxGetPr(parametervalues)[pind+1]=paramtmp[1];
                                        
                                        srfPnts[cind]=pnttmp[0];
                                        srfPnts[cind+1]=pnttmp[1];
                                        srfPnts[cind+2]=pnttmp[2];
                                        
                                    }
                                    
                                }
                                
                                pind+=2;
                                cind+=3;
                                
                            }
                            
                            k = np-1;
                            
                            dir[0]=Pend[0]-srfPnts[cind-3];
                            dir[1]=Pend[1]-srfPnts[cind-2];
                            dir[2]=Pend[2]-srfPnts[cind-1];
                            
                            maxDis=getPoint2lineDist(&srfPnts[cind], &srfPnts[cind-3], dir);
                            
                            cparam=0.67*crvParams[k]+0.33*crvParams[k-1];
                            
                            paramtmp[0]=lineSt[0]+cparam*bspPnts[0];
                            paramtmp[1]=lineSt[1]+cparam*bspPnts[1];
                            
                            NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                            
                            tmpDis=getPoint2lineDist(pnttmp, &srfPnts[cind-3], dir);
                            
                            if (tmpDis>maxDis){
                                
                                crvParams[k]=cparam;
                                
                                mxGetPr(parametervalues)[pind]=paramtmp[0];
                                mxGetPr(parametervalues)[pind+1]=paramtmp[1];
                                
                                srfPnts[cind]=pnttmp[0];
                                srfPnts[cind+1]=pnttmp[1];
                                srfPnts[cind+2]=pnttmp[2];
                                
                            }
                            else {
                                
                                cparam=0.67*crvParams[k]+0.33;
                                
                                paramtmp[0]=lineSt[0]+cparam*bspPnts[0];
                                paramtmp[1]=lineSt[1]+cparam*bspPnts[1];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, 1, pnttmp, leftU, rightU, NU, leftV, rightV, NV);
                                
                                tmpDis=getPoint2lineDist(pnttmp, &srfPnts[cind-3], dir);
                                
                                if (tmpDis>maxDis){
                                    
                                    crvParams[k]=cparam;
                                    
                                    mxGetPr(parametervalues)[pind]=paramtmp[0];
                                    mxGetPr(parametervalues)[pind+1]=paramtmp[1];
                                    
                                    srfPnts[cind]=pnttmp[0];
                                    srfPnts[cind+1]=pnttmp[1];
                                    srfPnts[cind+2]=pnttmp[2];
                                    
                                }
                                
                            }
                            
                            free(crvParams);
                            
                        }
                        
                    }
                    else {
                        
                        bspPnts[0]=bspPnts[0]/((double)np);
                        bspPnts[1]=bspPnts[1]/((double)np);
                        
                        pind=1;
                        
                        if (nlhs>1){
                            
                            NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, (unsigned int)1, srfPnts, leftU, rightU, NU, leftV, rightV, NV);
                            
                            for (k = 3; k < 3*np-2; k+=3){
                                
                                paramtmp[0]+=bspPnts[0];
                                paramtmp[1]+=bspPnts[1];
                                
                                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, (unsigned int)1, &srfPnts[k], leftU, rightU, NU, leftV, rightV, NV);
                                
                                pind++;
                                mxGetPr(parametervalues)[pind]=paramtmp[0];
                                pind++;
                                mxGetPr(parametervalues)[pind]=paramtmp[1];
                                
                            }
                            
                        }
                        else {
                            
                            for (k = 3; k < 3*np-2; k+=3){
                                
                                paramtmp[0]+=bspPnts[0];
                                paramtmp[1]+=bspPnts[1];
                                
                                pind++;
                                mxGetPr(parametervalues)[pind]=paramtmp[0];
                                pind++;
                                mxGetPr(parametervalues)[pind]=paramtmp[1];
                                
                            }
                            
                        }
                        
                    }
                    
                }
                
            }
            
            if (nlhs==1 && evFlg>0 && np>1){
                free(srfPnts);
            }
            
            free(leftU);
            free(rightU);
            free(NU);
            free(leftV);
            free(rightV);
            free(NV);
            
        }
        else if (nrhs==3){
            
            parametervalues = mxCreateDoubleMatrix(2, 0, mxREAL);
            
            if (nlhs==1){
                return;
            }
            
            evaluated_points = mxCreateDoubleMatrix(3, np, mxREAL);
            
            if (np==0){
                return;
            }
            
            mxGetPr(evaluated_points)[0]=mxGetPr(pnt3Start)[0];
            mxGetPr(evaluated_points)[1]=mxGetPr(pnt3Start)[1];
            mxGetPr(evaluated_points)[2]=mxGetPr(pnt3Start)[2];
            
            bspPnts[0]=(mxGetPr(pnt3Termi)[0]-mxGetPr(pnt3Start)[0])/((double)np);
            bspPnts[1]=(mxGetPr(pnt3Termi)[1]-mxGetPr(pnt3Start)[1])/((double)np);
            bspPnts[2]=(mxGetPr(pnt3Termi)[2]-mxGetPr(pnt3Start)[2])/((double)np);
            
            for (k = 3; k < 3*np-2; k+=3){
                mxGetPr(evaluated_points)[k]=mxGetPr(evaluated_points)[k-3]+bspPnts[0];
                mxGetPr(evaluated_points)[k+1]=mxGetPr(evaluated_points)[k-2]+bspPnts[1];
                mxGetPr(evaluated_points)[k+2]=mxGetPr(evaluated_points)[k-1]+bspPnts[2];
            }
            
        }
        
    }
    else if (nlhs==3){
        
        if (nrhs<3 || nrhs>5){
            mexErrMsgTxt("Number of inputs must be 3, 4, or 5");
        }
        
        crvLength=mxCreateDoubleMatrix(1, 1, mxREAL);
        crvScLength=mxCreateDoubleMatrix(1, 1, mxREAL);
        evalFlag=mxCreateDoubleMatrix(1, 1, mxREAL);
        
        np=MAX(np,20);
        
        maxDis3=(double)(np*np*np);
        maxDis3=maxDis3*maxDis3;
        
        if (nrhs==4 && mxGetN(mxGetField(nurbs3DCRV, 0, "order"))==1){
            
            orderC = (int)mxGetScalar(mxGetField(nurbs3DCRV, 0, "order"));
            ncpC = (int)mxGetScalar(mxGetField(nurbs3DCRV, 0, "number"));
            
            degC = orderC-1;
            
            leftU  = (double*) malloc(orderC*sizeof(double)+1);
            rightU = (double*) malloc(orderC*sizeof(double)+1);
            NU = (double*) malloc(orderC*sizeof(double)+1);
            
            crvCP = mxGetPr(mxGetField(nurbs3DCRV, 0, "coefs"));
            crvKnots = mxGetPr(mxGetField(nurbs3DCRV, 0, "knots"));
            
            uminC = mxGetScalar(uStart);
            umaxC = mxGetScalar(uTermi);
            
            duC = umaxC - uminC;
            
            du = duC/((double)np);
            
            if (uminC < (crvKnots[0] + 1e-6*duC)){
                
                P0[0]=crvCP[0]/crvCP[3];
                P0[1]=crvCP[1]/crvCP[3];
                P0[2]=crvCP[2]/crvCP[3];
                
            }
            else {
                
                bspPnts[0]=0.0;
                bspPnts[1]=0.0;
                bspPnts[2]=0.0;
                bspPnts[3]=0.0;
                
                span = FindSpan(ncpC, degC, uminC, crvKnots);
                BasisFuns(span, uminC, degC, crvKnots, NU, leftU, rightU);
                
                myint=(span-degC)*4;
                for (i = 0; i <= degC; i++){
                    bspPnts[0]+=NU[i]*crvCP[myint];
                    bspPnts[1]+=NU[i]*crvCP[myint+1];
                    bspPnts[2]+=NU[i]*crvCP[myint+2];
                    bspPnts[3]+=NU[i]*crvCP[myint+3];
                    myint+=4;
                }
                P0[0]=bspPnts[0]/bspPnts[3];
                P0[1]=bspPnts[1]/bspPnts[3];
                P0[2]=bspPnts[2]/bspPnts[3];
                
            }
            
            pnttmp[0]=P0[0];
            pnttmp[1]=P0[1];
            pnttmp[2]=P0[2];
            
            cparam=uminC+du;
            
            bspPnts[0]=0.0;
            bspPnts[1]=0.0;
            bspPnts[2]=0.0;
            bspPnts[3]=0.0;
            
            span = FindSpan(ncpC, degC, cparam, crvKnots);
            BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
            
            myint=(span-degC)*4;
            for (i = 0; i <= degC; i++){
                bspPnts[0]+=NU[i]*crvCP[myint];
                bspPnts[1]+=NU[i]*crvCP[myint+1];
                bspPnts[2]+=NU[i]*crvCP[myint+2];
                bspPnts[3]+=NU[i]*crvCP[myint+3];
                myint+=4;
            }
            P1[0]=bspPnts[0]/bspPnts[3];
            P1[1]=bspPnts[1]/bspPnts[3];
            P1[2]=bspPnts[2]/bspPnts[3];
            
            maxDis=sqrt(pwr2(P1[0]-P0[0])+pwr2(P1[1]-P0[1])+pwr2(P1[2]-P0[2]));
            
            tmpDis=sqrt(pwr2(P1[0]-pnttmp[0])+pwr2(P1[1]-pnttmp[1])+pwr2(P1[2]-pnttmp[2]));
            
            cparam+=du;
            
            bspPnts[0]=0.0;
            bspPnts[1]=0.0;
            bspPnts[2]=0.0;
            bspPnts[3]=0.0;
            
            span = FindSpan(ncpC, degC, cparam, crvKnots);
            BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
            
            myint=(span-degC)*4;
            for (i = 0; i <= degC; i++){
                bspPnts[0]+=NU[i]*crvCP[myint];
                bspPnts[1]+=NU[i]*crvCP[myint+1];
                bspPnts[2]+=NU[i]*crvCP[myint+2];
                bspPnts[3]+=NU[i]*crvCP[myint+3];
                myint+=4;
            }
            P2[0]=bspPnts[0]/bspPnts[3];
            P2[1]=bspPnts[1]/bspPnts[3];
            P2[2]=bspPnts[2]/bspPnts[3];
            
            maxDis+=sqrt(pwr2(P2[0]-P1[0])+pwr2(P2[1]-P1[1])+pwr2(P2[2]-P1[2]));
            
            tmpDis=MAX(tmpDis,sqrt(pwr2(P2[0]-pnttmp[0])+pwr2(P2[1]-pnttmp[1])+pwr2(P2[2]-pnttmp[2])));
            
            P3[0]=0.5*(P2[0]-P0[0]);
            P3[1]=0.5*(P2[1]-P0[1]);
            P3[2]=0.5*(P2[2]-P0[2]);
            
            Pend[0]=P2[0]-2.0*P1[0]+P0[0];
            Pend[1]=P2[1]-2.0*P1[1]+P0[1];
            Pend[2]=P2[2]-2.0*P1[2]+P0[2];
            
            no0=pwr2(P3[0])+pwr2(P3[1])+pwr2(P3[2]);
            no0=no0*no0*no0;
            no1=pwr2(P3[0]*Pend[1]-P3[1]*Pend[0])+pwr2(P3[0]*Pend[2]-P3[2]*Pend[0])+pwr2(P3[2]*Pend[1]-P3[1]*Pend[2]);
            if (no0*maxDis3 < 1e-30){
                no2=0.0;
            }
            else if (tmpDis*tmpDis*no1 >= no0*1e6){
                no2=1e3;
            }
            else {
                no2=sqrt(no1/no0);
            }
            
            maxDis0=no2;
            maxDis1=no2;
            maxDis2=no2;
            
            for (k = 2; k < np; k++){
                
                P0[0]=P1[0];
                P0[1]=P1[1];
                P0[2]=P1[2];
                
                P1[0]=P2[0];
                P1[1]=P2[1];
                P1[2]=P2[2];
                
                cparam+=du;
                
                bspPnts[0]=0.0;
                bspPnts[1]=0.0;
                bspPnts[2]=0.0;
                bspPnts[3]=0.0;
                
                span = FindSpan(ncpC, degC, cparam, crvKnots);
                BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                
                myint=(span-degC)*4;
                for (i = 0; i <= degC; i++){
                    bspPnts[0]+=NU[i]*crvCP[myint];
                    bspPnts[1]+=NU[i]*crvCP[myint+1];
                    bspPnts[2]+=NU[i]*crvCP[myint+2];
                    bspPnts[3]+=NU[i]*crvCP[myint+3];
                    myint+=4;
                }
                P2[0]=bspPnts[0]/bspPnts[3];
                P2[1]=bspPnts[1]/bspPnts[3];
                P2[2]=bspPnts[2]/bspPnts[3];
                
                maxDis+=sqrt(pwr2(P2[0]-P1[0])+pwr2(P2[1]-P1[1])+pwr2(P2[2]-P1[2]));
                
                tmpDis=MAX(tmpDis,sqrt(pwr2(P2[0]-pnttmp[0])+pwr2(P2[1]-pnttmp[1])+pwr2(P2[2]-pnttmp[2])));
                
                P3[0]=0.5*(P2[0]-P0[0]);
                P3[1]=0.5*(P2[1]-P0[1]);
                P3[2]=0.5*(P2[2]-P0[2]);
                
                Pend[0]=P2[0]-2.0*P1[0]+P0[0];
                Pend[1]=P2[1]-2.0*P1[1]+P0[1];
                Pend[2]=P2[2]-2.0*P1[2]+P0[2];
                
                no0=pwr2(P3[0])+pwr2(P3[1])+pwr2(P3[2]);
                no0=no0*no0*no0;
                no1=pwr2(P3[0]*Pend[1]-P3[1]*Pend[0])+pwr2(P3[0]*Pend[2]-P3[2]*Pend[0])+pwr2(P3[2]*Pend[1]-P3[1]*Pend[2]);
                if (no0*maxDis3 < 1e-30){
                    no2=0.0;
                }
                else if (tmpDis*tmpDis*no1 >= no0*1e6){
                    no2=1e3;
                }
                else {
                    no2=sqrt(no1/no0);
                }
                
                maxDis0=MIN(no2,maxDis0);
                maxDis1+=no2;
                maxDis2=MAX(no2,maxDis2);
                
            }
            
            maxDis1=maxDis1/((double)(np-1));
            tmpDis=tmpDis*maxDis1;
            
            mxGetPr(crvLength)[0]=maxDis;
            mxGetPr(crvScLength)[0]=maxDis*(5.0*tmpDis/(2.0+tmpDis)+0.075);
            if ( maxDis*maxDis2 < 1.0 ){
                mxGetPr(evalFlag)[0]=0.0;
            }
            else if ( maxDis2 > 2.5*maxDis1 ){
                mxGetPr(evalFlag)[0]=1.0;
            }
            else {
                mxGetPr(evalFlag)[0]=0.0;
            }
            
        }
        else if (nrhs>3){
            
            orderU = (int)mxGetPr(mxGetField(nurbsSRF, 0, "order"))[0];
            orderV = (int)mxGetPr(mxGetField(nurbsSRF, 0, "order"))[1];
            
            degU = orderU-1;
            degV = orderV-1;
            
            ncp = (int)mxGetPr(mxGetField(nurbsSRF, 0, "number"))[0];
            kcp = (int)mxGetPr(mxGetField(nurbsSRF, 0, "number"))[1];
            
            if (nrhs==5){
                
                orderC = (int)mxGetScalar(mxGetField(nurbsCRV, 0, "order"));
                ncpC = (int)mxGetScalar(mxGetField(nurbsCRV, 0, "number"));
                
                degC = orderC-1;
                
                leftU  = (double*) malloc(MAX(orderU,orderC)*sizeof(double)+1);
                rightU = (double*) malloc(MAX(orderU,orderC)*sizeof(double)+1);
                NU = (double*) malloc(MAX(orderU,orderC)*sizeof(double)+1);
                leftV  = (double*) malloc(orderV*sizeof(double)+1);
                rightV = (double*) malloc(orderV*sizeof(double)+1);
                NV = (double*) malloc(orderV*sizeof(double)+1);
                
                srfCP = mxGetPr(mxGetField(nurbsSRF, 0, "coefs"));
                srfKnotsU = mxGetPr(mxGetCell(mxGetField(nurbsSRF, 0, "knots"), 0));
                srfKnotsV = mxGetPr(mxGetCell(mxGetField(nurbsSRF, 0, "knots"), 1));
                
                crvCP = mxGetPr(mxGetField(nurbsCRV, 0, "coefs"));
                crvKnots = mxGetPr(mxGetField(nurbsCRV, 0, "knots"));
                
                uminC = mxGetScalar(usStart);
                umaxC = mxGetScalar(usTermi);
                
                duC = umaxC - uminC;
                
                du = duC/((double)np);
                
                if (uminC < (crvKnots[0] + 1e-6*duC)){
                    
                    paramtmp[0]=crvCP[0]/crvCP[3];
                    paramtmp[1]=crvCP[1]/crvCP[3];
                    
                }
                else {
                    
                    bspPnts[0]=0.0;
                    bspPnts[1]=0.0;
                    bspPnts[2]=0.0;
                    
                    span = FindSpan(ncpC, degC, uminC, crvKnots);
                    BasisFuns(span, uminC, degC, crvKnots, NU, leftU, rightU);
                    
                    myint=(span-degC)*4;
                    for (i = 0; i <= degC; i++){
                        bspPnts[0]+=NU[i]*crvCP[myint];
                        bspPnts[1]+=NU[i]*crvCP[myint+1];
                        bspPnts[2]+=NU[i]*crvCP[myint+3];
                        myint+=4;
                    }
                    paramtmp[0]=bspPnts[0]/bspPnts[2];
                    paramtmp[1]=bspPnts[1]/bspPnts[2];
                    
                }
                
                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, (unsigned int)1, P0, leftU, rightU, NU, leftV, rightV, NV);
                
                pnttmp[0]=P0[0];
                pnttmp[1]=P0[1];
                pnttmp[2]=P0[2];
                
                cparam=uminC+du;
                
                bspPnts[0]=0.0;
                bspPnts[1]=0.0;
                bspPnts[2]=0.0;
                
                span = FindSpan(ncpC, degC, cparam, crvKnots);
                BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                
                myint=(span-degC)*4;
                for (i = 0; i <= degC; i++){
                    bspPnts[0]+=NU[i]*crvCP[myint];
                    bspPnts[1]+=NU[i]*crvCP[myint+1];
                    bspPnts[2]+=NU[i]*crvCP[myint+3];
                    myint+=4;
                }
                paramtmp[0]=bspPnts[0]/bspPnts[2];
                paramtmp[1]=bspPnts[1]/bspPnts[2];
                
                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, (unsigned int)1, P1, leftU, rightU, NU, leftV, rightV, NV);
                
                maxDis=sqrt(pwr2(P1[0]-P0[0])+pwr2(P1[1]-P0[1])+pwr2(P1[2]-P0[2]));
                
                tmpDis=sqrt(pwr2(P1[0]-pnttmp[0])+pwr2(P1[1]-pnttmp[1])+pwr2(P1[2]-pnttmp[2]));
                
                cparam+=du;
                
                bspPnts[0]=0.0;
                bspPnts[1]=0.0;
                bspPnts[2]=0.0;
                
                span = FindSpan(ncpC, degC, cparam, crvKnots);
                BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                
                myint=(span-degC)*4;
                for (i = 0; i <= degC; i++){
                    bspPnts[0]+=NU[i]*crvCP[myint];
                    bspPnts[1]+=NU[i]*crvCP[myint+1];
                    bspPnts[2]+=NU[i]*crvCP[myint+3];
                    myint+=4;
                }
                paramtmp[0]=bspPnts[0]/bspPnts[2];
                paramtmp[1]=bspPnts[1]/bspPnts[2];
                
                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, (unsigned int)1, P2, leftU, rightU, NU, leftV, rightV, NV);
                
                maxDis+=sqrt(pwr2(P2[0]-P1[0])+pwr2(P2[1]-P1[1])+pwr2(P2[2]-P1[2]));
                
                tmpDis=MAX(tmpDis,sqrt(pwr2(P2[0]-pnttmp[0])+pwr2(P2[1]-pnttmp[1])+pwr2(P2[2]-pnttmp[2])));
                
                P3[0]=0.5*(P2[0]-P0[0]);
                P3[1]=0.5*(P2[1]-P0[1]);
                P3[2]=0.5*(P2[2]-P0[2]);
                
                Pend[0]=P2[0]-2.0*P1[0]+P0[0];
                Pend[1]=P2[1]-2.0*P1[1]+P0[1];
                Pend[2]=P2[2]-2.0*P1[2]+P0[2];
                
                no0=pwr2(P3[0])+pwr2(P3[1])+pwr2(P3[2]);
                no0=no0*no0*no0;
                no1=pwr2(P3[0]*Pend[1]-P3[1]*Pend[0])+pwr2(P3[0]*Pend[2]-P3[2]*Pend[0])+pwr2(P3[2]*Pend[1]-P3[1]*Pend[2]);
                if (no0*maxDis3 < 1e-30){
                    no2=0.0;
                }
                else if (tmpDis*tmpDis*no1 >= no0*1e6){
                    no2=1e3;
                }
                else {
                    no2=sqrt(no1/no0);
                }
                
                maxDis0=no2;
                maxDis1=no2;
                maxDis2=no2;
                
                for (k = 2; k < np; k++){
                    
                    P0[0]=P1[0];
                    P0[1]=P1[1];
                    P0[2]=P1[2];
                    
                    P1[0]=P2[0];
                    P1[1]=P2[1];
                    P1[2]=P2[2];
                    
                    cparam+=du;
                    
                    bspPnts[0]=0.0;
                    bspPnts[1]=0.0;
                    bspPnts[2]=0.0;
                    
                    span = FindSpan(ncpC, degC, cparam, crvKnots);
                    BasisFuns(span, cparam, degC, crvKnots, NU, leftU, rightU);
                    
                    myint=(span-degC)*4;
                    for (i = 0; i <= degC; i++){
                        bspPnts[0]+=NU[i]*crvCP[myint];
                        bspPnts[1]+=NU[i]*crvCP[myint+1];
                        bspPnts[2]+=NU[i]*crvCP[myint+3];
                        myint+=4;
                    }
                    paramtmp[0]=bspPnts[0]/bspPnts[2];
                    paramtmp[1]=bspPnts[1]/bspPnts[2];
                    
                    NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, (unsigned int)1, P2, leftU, rightU, NU, leftV, rightV, NV);
                    
                    maxDis+=sqrt(pwr2(P2[0]-P1[0])+pwr2(P2[1]-P1[1])+pwr2(P2[2]-P1[2]));
                    
                    tmpDis=MAX(tmpDis,sqrt(pwr2(P2[0]-pnttmp[0])+pwr2(P2[1]-pnttmp[1])+pwr2(P2[2]-pnttmp[2])));
                    
                    P3[0]=0.5*(P2[0]-P0[0]);
                    P3[1]=0.5*(P2[1]-P0[1]);
                    P3[2]=0.5*(P2[2]-P0[2]);
                    
                    Pend[0]=P2[0]-2.0*P1[0]+P0[0];
                    Pend[1]=P2[1]-2.0*P1[1]+P0[1];
                    Pend[2]=P2[2]-2.0*P1[2]+P0[2];
                    
                    no0=pwr2(P3[0])+pwr2(P3[1])+pwr2(P3[2]);
                    no0=no0*no0*no0;
                    no1=pwr2(P3[0]*Pend[1]-P3[1]*Pend[0])+pwr2(P3[0]*Pend[2]-P3[2]*Pend[0])+pwr2(P3[2]*Pend[1]-P3[1]*Pend[2]);
                    if (no0*maxDis3 < 1e-30){
                        no2=0.0;
                    }
                    else if (tmpDis*tmpDis*no1 >= no0*1e6){
                        no2=1e3;
                    }
                    else {
                        no2=sqrt(no1/no0);
                    }
                    
                    maxDis0=MIN(no2,maxDis0);
                    maxDis1+=no2;
                    maxDis2=MAX(no2,maxDis2);
                    
                }
                
            }
            else if (nrhs==4){
                
                leftU  = (double*) malloc(orderU*sizeof(double)+1);
                rightU = (double*) malloc(orderU*sizeof(double)+1);
                NU = (double*) malloc(orderU*sizeof(double)+1);
                leftV  = (double*) malloc(orderV*sizeof(double)+1);
                rightV = (double*) malloc(orderV*sizeof(double)+1);
                NV = (double*) malloc(orderV*sizeof(double)+1);
                
                srfCP = mxGetPr(mxGetField(nurbsSRF, 0, "coefs"));
                srfKnotsU = mxGetPr(mxGetCell(mxGetField(nurbsSRF, 0, "knots"), 0));
                srfKnotsV = mxGetPr(mxGetCell(mxGetField(nurbsSRF, 0, "knots"), 1));
                
                bspPnts[0]=(mxGetPr(pntTermi)[0]-mxGetPr(pntStart)[0])/((double)np);
                bspPnts[1]=(mxGetPr(pntTermi)[1]-mxGetPr(pntStart)[1])/((double)np);
                
                paramtmp[0]=mxGetPr(pntStart)[0];
                paramtmp[1]=mxGetPr(pntStart)[1];
                
                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, (unsigned int)1, P0, leftU, rightU, NU, leftV, rightV, NV);
                
                pnttmp[0]=P0[0];
                pnttmp[1]=P0[1];
                pnttmp[2]=P0[2];
                
                paramtmp[0]+=bspPnts[0];
                paramtmp[1]+=bspPnts[1];
                
                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, (unsigned int)1, P1, leftU, rightU, NU, leftV, rightV, NV);
                
                maxDis=sqrt(pwr2(P1[0]-P0[0])+pwr2(P1[1]-P0[1])+pwr2(P1[2]-P0[2]));
                
                tmpDis=sqrt(pwr2(P1[0]-pnttmp[0])+pwr2(P1[1]-pnttmp[1])+pwr2(P1[2]-pnttmp[2]));
                
                paramtmp[0]+=bspPnts[0];
                paramtmp[1]+=bspPnts[1];
                
                NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, (unsigned int)1, P2, leftU, rightU, NU, leftV, rightV, NV);
                
                maxDis+=sqrt(pwr2(P2[0]-P1[0])+pwr2(P2[1]-P1[1])+pwr2(P2[2]-P1[2]));
                
                tmpDis=MAX(tmpDis,sqrt(pwr2(P2[0]-pnttmp[0])+pwr2(P2[1]-pnttmp[1])+pwr2(P2[2]-pnttmp[2])));
                
                P3[0]=0.5*(P2[0]-P0[0]);
                P3[1]=0.5*(P2[1]-P0[1]);
                P3[2]=0.5*(P2[2]-P0[2]);
                
                Pend[0]=P2[0]-2.0*P1[0]+P0[0];
                Pend[1]=P2[1]-2.0*P1[1]+P0[1];
                Pend[2]=P2[2]-2.0*P1[2]+P0[2];
                
                no0=pwr2(P3[0])+pwr2(P3[1])+pwr2(P3[2]);
                no0=no0*no0*no0;
                no1=pwr2(P3[0]*Pend[1]-P3[1]*Pend[0])+pwr2(P3[0]*Pend[2]-P3[2]*Pend[0])+pwr2(P3[2]*Pend[1]-P3[1]*Pend[2]);
                if (no0*maxDis3 < 1e-30){
                    no2=0.0;
                }
                else if (tmpDis*tmpDis*no1 >= no0*1e6){
                    no2=1e3;
                }
                else {
                    no2=sqrt(no1/no0);
                }
                
                maxDis0=no2;
                maxDis1=no2;
                maxDis2=no2;
                
                for (k = 2; k < np; k++){
                    
                    P0[0]=P1[0];
                    P0[1]=P1[1];
                    P0[2]=P1[2];
                    
                    P1[0]=P2[0];
                    P1[1]=P2[1];
                    P1[2]=P2[2];
                    
                    paramtmp[0]+=bspPnts[0];
                    paramtmp[1]+=bspPnts[1];
                    
                    NURBSsurfaceEval(degU, degV, srfCP, ncp, kcp, srfKnotsU, srfKnotsV, paramtmp, (unsigned int)1, P2, leftU, rightU, NU, leftV, rightV, NV);
                    
                    maxDis+=sqrt(pwr2(P2[0]-P1[0])+pwr2(P2[1]-P1[1])+pwr2(P2[2]-P1[2]));
                    
                    tmpDis=MAX(tmpDis,sqrt(pwr2(P2[0]-pnttmp[0])+pwr2(P2[1]-pnttmp[1])+pwr2(P2[2]-pnttmp[2])));
                    
                    P3[0]=0.5*(P2[0]-P0[0]);
                    P3[1]=0.5*(P2[1]-P0[1]);
                    P3[2]=0.5*(P2[2]-P0[2]);
                    
                    Pend[0]=P2[0]-2.0*P1[0]+P0[0];
                    Pend[1]=P2[1]-2.0*P1[1]+P0[1];
                    Pend[2]=P2[2]-2.0*P1[2]+P0[2];
                    
                    no0=pwr2(P3[0])+pwr2(P3[1])+pwr2(P3[2]);
                    no0=no0*no0*no0;
                    no1=pwr2(P3[0]*Pend[1]-P3[1]*Pend[0])+pwr2(P3[0]*Pend[2]-P3[2]*Pend[0])+pwr2(P3[2]*Pend[1]-P3[1]*Pend[2]);
                    if (no0*maxDis3 < 1e-30){
                        no2=0.0;
                    }
                    else if (tmpDis*tmpDis*no1 >= no0*1e6){
                        no2=1e3;
                    }
                    else {
                        no2=sqrt(no1/no0);
                    }
                    
                    maxDis0=MIN(no2,maxDis0);
                    maxDis1+=no2;
                    maxDis2=MAX(no2,maxDis2);
                    
                }
                
            }
            
            maxDis1=maxDis1/((double)(np-1));
            tmpDis=tmpDis*maxDis1;
            
            mxGetPr(crvLength)[0]=maxDis;
            mxGetPr(crvScLength)[0]=maxDis*(5.0*tmpDis/(2.0+tmpDis)+0.075);
            if ( maxDis*maxDis2 < 1.0 ){
                mxGetPr(evalFlag)[0]=0.0;
            }
            else if ( maxDis2 > 2.5*maxDis1 ){
                mxGetPr(evalFlag)[0]=1.0;
            }
            else {
                mxGetPr(evalFlag)[0]=0.0;
            }
            
        }
        else if (nrhs==3){
            
            maxDis=sqrt(pwr2(mxGetPr(pnt3Termi)[0]-mxGetPr(pnt3Start)[0])+pwr2(mxGetPr(pnt3Termi)[1]-mxGetPr(pnt3Start)[1])+pwr2(mxGetPr(pnt3Termi)[2]-mxGetPr(pnt3Start)[2]));
            
            mxGetPr(crvLength)[0]=maxDis;
            mxGetPr(crvScLength)[0]=0.075*maxDis;
            mxGetPr(evalFlag)[0]=0.0;
            
        }
        
    }
    else {
        mexErrMsgTxt("Illegal number of outputs");
    }
    
}
