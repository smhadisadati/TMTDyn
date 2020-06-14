/**************************************************************************
 *
 * [NURBSoffset,coefsOffset,wghsOffset]=offsetNURBSsurface(signdist,NURBSorg,dNURBSorg,d2NURBSorg)
 *
 * Input:
 * signdist - Signed distance
 * NURBSorg - Original NURBS surface
 * dNURBSorg - Derivative of original NURBS surface
 * d2NURBSorg - 2:nd derivative of original NURBS surface
 *
 * Output:
 * NURBSoffset - Offset NURBS surface
 * coefsOffset - Control points of offset surface
 * wghsOffset - Weights of offset surface
 *
 * c-file can be downloaded at
 *
 * http://www.mathworks.com/matlabcentral/fileexchange/13253-iges-toolbox
 *
 * compile in Matlab by using the command  "mex -v offsetNURBSsurface.c"
 *
 * See "help mex" for more information
 *
 * written by Per Bergström 2014-09-30
 *
 **************************************************************************/

#include <math.h>
#include "mex.h"

/* Input Arguments */

#define	signdist	prhs[0]
#define	NURBSorg	prhs[1]
#define	dNURBSorg	prhs[2]
#define	d2NURBSorg	prhs[3]

/* Output Arguments */

#define	NURBSoffset	plhs[0]
#define	coefsOffset	plhs[1]
#define	wghsOffset	plhs[2]


#if !defined(MAX)
#define	MAX(A, B)	((A) > (B) ? (A) : (B))
#endif

#if !defined(MIN)
#define	MIN(A, B)	((A) < (B) ? (A) : (B))
#endif


/* Power 2 function */

double pwr2(double a){
    return(a*a);
}

/* Sub functions (in folder "mexSourceFiles") */

#include "mexSourceFiles/FindSpan.c"
#include "mexSourceFiles/BasisFuns.c"
#include "mexSourceFiles/nrbD1D2eval2.c"
#include "mexSourceFiles/NURBSsurfaceEval.c"
#include "mexSourceFiles/offsetNURBSsrf.c"


/* Main function */

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    
    int dims[3], orderUoff, orderVoff, ncpOff, kcpOff, orderUorg, orderVorg, ncpOrg, kcpOrg, noffp, nunkn, norgp, intTmp;
    double *leftU, *rightU, *NU, *leftV, *rightV, *NV;
    double *UVorg, *UVoff, *basisVals, *cpDir, *UVcp, *orgPnts, *orgNrmls, *sgnDistDiff, *GNHess, *GNgrad, *searchDir, *doubleVals;
    int i, numDeltaSignDist=15, numFinalIters=2, numGNIters=2, numFinalGNIters=10, numFinalGNItersII=1;
    int *derivInds, *matInds;
    double signDist, deltaSignDist, tmpSignDist, lambdaSQ=0.01, lambdaSQII=100.0, fdiffStop;
    double explWghs[10]={ 4328424.0/7581335.0 , 5597937.0/7581335.0 , 4172056.0/7581335.0 , -16125.0/3032534.0 , -528336.0/1516267.0 , -3675584.0/7581335.0 , -3127512.0/7581335.0 , -1122147.0/15162670.0 , 305388.0/1516267.0 , 400428.0/1516267.0 };
    mxArray *nrbOrg, *dnrbOrg, *d2nrbOrg, *dNURBSoff, *d2NURBSoff;
    
    if (nlhs==3 && nrhs==4){
        
        nrbOrg=NURBSorg;
        dnrbOrg=dNURBSorg;
        d2nrbOrg=d2NURBSorg;
        
        NURBSoffset=mxDuplicateArray(NURBSorg);
        dNURBSoff=mxDuplicateArray(dNURBSorg);
        d2NURBSoff=mxDuplicateArray(d2NURBSorg);
        
        orderUoff = (int)mxGetPr(mxGetField(NURBSoffset, 0, "order"))[0];
        orderVoff = (int)mxGetPr(mxGetField(NURBSoffset, 0, "order"))[1];
        
        ncpOff = (int)mxGetPr(mxGetField(NURBSoffset, 0, "number"))[0];
        kcpOff = (int)mxGetPr(mxGetField(NURBSoffset, 0, "number"))[1];
        
        dims[0]=3;
        dims[1]=ncpOff;
        dims[2]=kcpOff;
        
        coefsOffset=mxCreateNumericArray(3, dims, mxDOUBLE_CLASS, mxREAL);
        
        orderUorg = (int)mxGetPr(mxGetField(NURBSorg, 0, "order"))[0];
        orderVorg = (int)mxGetPr(mxGetField(NURBSorg, 0, "order"))[1];
        
        ncpOrg = (int)mxGetPr(mxGetField(NURBSorg, 0, "number"))[0];
        kcpOrg = (int)mxGetPr(mxGetField(NURBSorg, 0, "number"))[1];
        
        intTmp=MAX(orderUoff,orderUorg);
        leftU  = (double*) malloc(intTmp*sizeof(double)+1);
        rightU = (double*) malloc(intTmp*sizeof(double)+1);
        NU = (double*) malloc(intTmp*sizeof(double)+1);
        
        intTmp=MAX(orderVoff,orderVorg);
        leftV  = (double*) malloc(intTmp*sizeof(double)+1);
        rightV = (double*) malloc(intTmp*sizeof(double)+1);
        NV = (double*) malloc(intTmp*sizeof(double)+1);
        
        norgp = ncpOrg*kcpOrg+9*(ncpOrg-1)*(kcpOrg-1)+3*(ncpOrg-1)*kcpOrg+3*(kcpOrg-1)*ncpOrg;
        noffp = ncpOff*kcpOff+25*(ncpOff-1)*(kcpOff-1)+3*(ncpOff-1)*kcpOff+3*(kcpOff-1)*ncpOff;
        
        UVorg = (double*) malloc(2*norgp*sizeof(double)+1);
        UVoff = (double*) malloc(2*noffp*sizeof(double)+1);
        UVcp = (double*) malloc(2*ncpOrg*kcpOrg*sizeof(double)+1);
        
        basisVals = (double*) malloc((ncpOrg*kcpOrg*ncpOrg*kcpOrg)*sizeof(double)+1);
        cpDir = (double*) malloc((3*ncpOff*kcpOff)*sizeof(double)+1);
        orgPnts = (double*) malloc(3*norgp*sizeof(double)+1);
        orgNrmls = (double*) malloc(3*noffp*sizeof(double)+1);
        sgnDistDiff = (double*) malloc(2*noffp*sizeof(double)+1);
        
        derivInds = (int*) malloc(orderUoff*orderVoff*sizeof(int)+1);
        matInds = (int*) malloc(ncpOff*kcpOff*sizeof(int)+1);
        
        nunkn=MAX(ncpOff*kcpOff,2*(ncpOff*kcpOff-4));
        GNHess = (double*) malloc(nunkn*nunkn*sizeof(double)+1);
        GNgrad = (double*) malloc(nunkn*sizeof(double)+1);
        searchDir = (double*) malloc(nunkn*sizeof(double)+1);
        doubleVals = (double*) malloc(MAX(3*nunkn,6*orderUoff*orderVoff)*sizeof(double)+1);
        
        getMatInd(ncpOff, kcpOff, matInds);
        
        signDist=mxGetScalar(signdist);
        deltaSignDist=signDist/((double)(2*numDeltaSignDist+1));
        
        NURBSsurfaceBasisMax(orderUorg-1, orderVorg-1, mxGetPr(mxGetField(NURBSorg, 0, "coefs")), ncpOrg, kcpOrg, mxGetPr(mxGetCell(mxGetField(NURBSorg, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSorg, 0, "knots"), 1)), UVorg, leftU, rightU, NU, leftV, rightV, NV);
        NURBSsurfaceBasisValues(orderUorg-1, orderVorg-1, mxGetPr(mxGetField(NURBSorg, 0, "coefs")), ncpOrg, kcpOrg, mxGetPr(mxGetCell(mxGetField(NURBSorg, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSorg, 0, "knots"), 1)), UVorg, basisVals, leftU, rightU, NU, leftV, rightV, NV);
        NURBSsurfaceBasisX4Max(orderUorg-1, orderVorg-1, mxGetPr(mxGetField(NURBSorg, 0, "coefs")), ncpOrg, kcpOrg, mxGetPr(mxGetCell(mxGetField(NURBSorg, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSorg, 0, "knots"), 1)), &UVorg[2*ncpOrg*kcpOrg], UVorg, basisVals, leftU, rightU, NU, leftV, rightV, NV);
        NURBSsurfaceBasisX2Max(orderUorg-1, orderVorg-1, mxGetPr(mxGetField(NURBSorg, 0, "coefs")), ncpOrg, kcpOrg, mxGetPr(mxGetCell(mxGetField(NURBSorg, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSorg, 0, "knots"), 1)), &UVorg[2*(ncpOrg*kcpOrg+(ncpOrg-1)*(kcpOrg-1))], UVorg, basisVals, leftU, rightU, NU, leftV, rightV, NV);
        NURBSsurfaceBasisX4ScMax(orderUorg-1, orderVorg-1, mxGetPr(mxGetField(NURBSorg, 0, "coefs")), ncpOrg, kcpOrg, mxGetPr(mxGetCell(mxGetField(NURBSorg, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSorg, 0, "knots"), 1)), &UVorg[2*(ncpOrg*kcpOrg+(ncpOrg-1)*(kcpOrg-1)+3*(ncpOrg-1)*kcpOrg+3*(kcpOrg-1)*ncpOrg)], UVorg, basisVals, leftU, rightU, NU, leftV, rightV, NV);
        
        closestNURBSsrfPnt2CP(8, orderUorg-1, orderVorg-1, mxGetPr(mxGetField(NURBSorg, 0, "coefs")), ncpOrg, kcpOrg, mxGetPr(mxGetCell(mxGetField(NURBSorg, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSorg, 0, "knots"), 1)), UVorg, nrbOrg, dnrbOrg, d2nrbOrg, explWghs, cpDir, UVcp, leftU, rightU, NU, leftV, rightV, NV);
        
        noffp = ncpOrg*kcpOrg+(ncpOrg-1)*(kcpOrg-1);
        
        getNURBSpntNrml(UVorg, noffp, orderUorg-1, orderVorg-1, ncpOrg, kcpOrg, nrbOrg, dnrbOrg, d2nrbOrg, orgPnts, explWghs, orgNrmls, leftU, rightU, NU, leftV, rightV, NV);
        NURBSsurfaceEval(orderUorg-1, orderVorg-1, mxGetPr(mxGetField(NURBSorg, 0, "coefs")), ncpOrg, kcpOrg, mxGetPr(mxGetCell(mxGetField(NURBSorg, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSorg, 0, "knots"), 1)), &UVorg[2*noffp], norgp-noffp, &orgPnts[3*noffp], leftU, rightU, NU, leftV, rightV, NV);
        
        safeCPdir(ncpOff*kcpOff, cpDir, orgNrmls);
        
        tmpSignDist=deltaSignDist;
        
        nunkn=ncpOff*kcpOff;
        
        initiateArray2zero(GNHess, nunkn*nunkn);
        initiateArray2zero(GNgrad, nunkn);
        initiateArray2val(sgnDistDiff, noffp, tmpSignDist);
        
        computeLinGNmatPnt2Pnt(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVorg, noffp, orgNrmls, cpDir, sgnDistDiff, GNHess, GNgrad, derivInds, doubleVals, leftU, rightU, NU, leftV, rightV, NV);
        
        rescaleArray(GNHess, nunkn*nunkn, lambdaSQ);
        rescaleArray(GNgrad, nunkn, lambdaSQ);
        
        computeLinGNmatPnt2Pln(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVorg, noffp, orgNrmls, cpDir, sgnDistDiff, GNHess, GNgrad, derivInds, doubleVals, leftU, rightU, NU, leftV, rightV, NV);
        
        linSysSolver(GNHess, GNgrad, searchDir, nunkn);
        
        updateCP(ncpOff, kcpOff, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), searchDir, cpDir);
        
        nrbSrfDerivative(orderUoff-1, orderVoff-1, ncpOff, kcpOff,mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)),mxGetPr(mxGetField(mxGetCell(dNURBSoff, 0), 0, "coefs")),mxGetPr(mxGetCell(mxGetField(mxGetCell(dNURBSoff, 0), 0, "knots"), 0)),mxGetPr(mxGetCell(mxGetField(mxGetCell(dNURBSoff, 0), 0, "knots"), 1)),mxGetPr(mxGetField(mxGetCell(dNURBSoff, 1), 0, "coefs")),mxGetPr(mxGetCell(mxGetField(mxGetCell(dNURBSoff, 1), 0, "knots"), 1)),mxGetPr(mxGetField(mxGetCell(d2NURBSoff, 0), 0, "coefs")),mxGetPr(mxGetField(mxGetCell(d2NURBSoff, 1), 0, "coefs")),mxGetPr(mxGetField(mxGetCell(d2NURBSoff, 2), 0, "coefs")));
        
        for (i=0 ; i < numDeltaSignDist ; i++){
            
            tmpSignDist+=deltaSignDist;
            
            findCPdir(10, orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVorg, NURBSoffset, dNURBSoff, d2NURBSoff, UVcp, orgPnts, UVorg, norgp, orderUorg-1, orderVorg-1, ncpOrg, kcpOrg, nrbOrg, dnrbOrg, d2nrbOrg, explWghs, cpDir, leftU, rightU, NU, leftV, rightV, NV);
            
            offsetPnt2PlnDeltaDistNURBS(15, orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVorg, noffp, orgPnts, UVorg, norgp, orderUorg-1, orderVorg-1, ncpOrg, kcpOrg, nrbOrg, dnrbOrg, d2nrbOrg, tmpSignDist, sgnDistDiff, explWghs, orgNrmls, leftU, rightU, NU, leftV, rightV, NV);
            
            safeCPdir(ncpOff*kcpOff, cpDir, orgNrmls);
            
            initiateArray2zero(GNHess, nunkn*nunkn);
            initiateArray2zero(GNgrad, nunkn);
            
            computeLinGNmatPnt2Pnt(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVorg, noffp, orgNrmls, cpDir, sgnDistDiff, GNHess, GNgrad, derivInds, doubleVals, leftU, rightU, NU, leftV, rightV, NV);
            
            rescaleArray(GNHess, nunkn*nunkn, lambdaSQ);
            rescaleArray(GNgrad, nunkn, lambdaSQ);
            
            computeLinGNmatPnt2Pln(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVorg, noffp, orgNrmls, cpDir, sgnDistDiff, GNHess, GNgrad, derivInds, doubleVals, leftU, rightU, NU, leftV, rightV, NV);
            
            linSysSolver(GNHess, GNgrad, searchDir, nunkn);
            
            updateCPneg(ncpOff, kcpOff, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), searchDir, cpDir);
            
            nrbSrfDerivative(orderUoff-1, orderVoff-1, ncpOff, kcpOff,mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)),mxGetPr(mxGetField(mxGetCell(dNURBSoff, 0), 0, "coefs")),mxGetPr(mxGetCell(mxGetField(mxGetCell(dNURBSoff, 0), 0, "knots"), 0)),mxGetPr(mxGetCell(mxGetField(mxGetCell(dNURBSoff, 0), 0, "knots"), 1)),mxGetPr(mxGetField(mxGetCell(dNURBSoff, 1), 0, "coefs")),mxGetPr(mxGetCell(mxGetField(mxGetCell(dNURBSoff, 1), 0, "knots"), 1)),mxGetPr(mxGetField(mxGetCell(d2NURBSoff, 0), 0, "coefs")),mxGetPr(mxGetField(mxGetCell(d2NURBSoff, 1), 0, "coefs")),mxGetPr(mxGetField(mxGetCell(d2NURBSoff, 2), 0, "coefs")));
            
        }
        
        if (nunkn>4){
            
            noffp = norgp;
            nunkn=2*(ncpOff*kcpOff-4);
            
            findCPdir(10, orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVorg, NURBSoffset, dNURBSoff, d2NURBSoff, UVcp, orgPnts, UVorg, norgp, orderUorg-1, orderVorg-1, ncpOrg, kcpOrg, nrbOrg, dnrbOrg, d2nrbOrg, explWghs, cpDir, leftU, rightU, NU, leftV, rightV, NV);
            
            offsetPnt2PlnDeltaDistNURBS(15, orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVorg, noffp, orgPnts, UVorg, norgp, orderUorg-1, orderVorg-1, ncpOrg, kcpOrg, nrbOrg, dnrbOrg, d2nrbOrg, tmpSignDist, sgnDistDiff, explWghs, orgNrmls, leftU, rightU, NU, leftV, rightV, NV);
            
            safeCPdir(ncpOff*kcpOff, cpDir, orgNrmls);
            
            setCornerCP(mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, orgNrmls, sgnDistDiff);
            
            getUnweightedCP(ncpOff, kcpOff, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), mxGetPr(coefsOffset));
            
            initiateArray2zero(GNHess, nunkn*nunkn);
            initiateArray2zero(GNgrad, nunkn);
            
            computeGNmatPnt2Pnt(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), mxGetPr(coefsOffset), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVoff, noffp, orgNrmls, cpDir, sgnDistDiff, GNHess, GNgrad, matInds, derivInds, doubleVals, leftU, rightU, NU, leftV, rightV, NV);
            
            rescaleArray(GNHess, nunkn*nunkn, lambdaSQII);
            rescaleArray(GNgrad, nunkn, lambdaSQII);
            
            computeGNmatPnt2Pln(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), mxGetPr(coefsOffset), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVorg, noffp, orgNrmls, cpDir, sgnDistDiff, GNHess, GNgrad, matInds, derivInds, doubleVals, leftU, rightU, NU, leftV, rightV, NV);
            
            conjugateGradientMethod(GNHess, GNgrad, searchDir, nunkn, MIN(30,(nunkn/3)+3), doubleVals);
            
            scaleGNdirCare(ncpOff, kcpOff, matInds, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), searchDir);
            
            lineSearchUpdateOffsetNURBS(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), mxGetPr(coefsOffset), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVorg, noffp, orgNrmls, cpDir, sgnDistDiff, matInds, searchDir, GNgrad, leftU, rightU, NU, leftV, rightV, NV);
            
            nrbSrfDerivative(orderUoff-1, orderVoff-1, ncpOff, kcpOff,mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)),mxGetPr(mxGetField(mxGetCell(dNURBSoff, 0), 0, "coefs")),mxGetPr(mxGetCell(mxGetField(mxGetCell(dNURBSoff, 0), 0, "knots"), 0)),mxGetPr(mxGetCell(mxGetField(mxGetCell(dNURBSoff, 0), 0, "knots"), 1)),mxGetPr(mxGetField(mxGetCell(dNURBSoff, 1), 0, "coefs")),mxGetPr(mxGetCell(mxGetField(mxGetCell(dNURBSoff, 1), 0, "knots"), 1)),mxGetPr(mxGetField(mxGetCell(d2NURBSoff, 0), 0, "coefs")),mxGetPr(mxGetField(mxGetCell(d2NURBSoff, 1), 0, "coefs")),mxGetPr(mxGetField(mxGetCell(d2NURBSoff, 2), 0, "coefs")));
            
            NURBSsurfaceBasisMax(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVoff, leftU, rightU, NU, leftV, rightV, NV);
            NURBSsurfaceBasisValues(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVoff, basisVals, leftU, rightU, NU, leftV, rightV, NV);
            NURBSsurfaceBasisX4Max(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), &UVoff[2*ncpOff*kcpOff], UVoff, basisVals, leftU, rightU, NU, leftV, rightV, NV);
            NURBSsurfaceBasisX2Max(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), &UVoff[2*(ncpOff*kcpOff+(ncpOff-1)*(kcpOff-1))], UVoff, basisVals, leftU, rightU, NU, leftV, rightV, NV);
            NURBSsurfaceBasisX4ScMax(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), &UVoff[2*(ncpOff*kcpOff+(ncpOff-1)*(kcpOff-1)+3*(ncpOff-1)*kcpOff+3*(kcpOff-1)*ncpOff)], UVoff, basisVals, leftU, rightU, NU, leftV, rightV, NV);
            
            noffp = ncpOrg*kcpOrg+(ncpOrg-1)*(kcpOrg-1);
            nunkn=ncpOff*kcpOff;
            
        }
        else {
            
            setArray2array(UVoff, UVorg, norgp);
            
        }
        
        for (i=0 ; i < numDeltaSignDist ; i++){
            
            tmpSignDist+=deltaSignDist;
            
            findCPdir(10, orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVoff, NURBSoffset, dNURBSoff, d2NURBSoff, UVcp, orgPnts, UVorg, norgp, orderUorg-1, orderVorg-1, ncpOrg, kcpOrg, nrbOrg, dnrbOrg, d2nrbOrg, explWghs, cpDir, leftU, rightU, NU, leftV, rightV, NV);
            
            offsetPnt2PlnDeltaDistNURBS(15, orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVoff, noffp, orgPnts, UVorg, norgp, orderUorg-1, orderVorg-1, ncpOrg, kcpOrg, nrbOrg, dnrbOrg, d2nrbOrg, tmpSignDist, sgnDistDiff, explWghs, orgNrmls, leftU, rightU, NU, leftV, rightV, NV);
            
            safeCPdir(ncpOff*kcpOff, cpDir, orgNrmls);
            
            initiateArray2zero(GNHess, nunkn*nunkn);
            initiateArray2zero(GNgrad, nunkn);
            
            computeLinGNmatPnt2Pnt(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVoff, noffp, orgNrmls, cpDir, sgnDistDiff, GNHess, GNgrad, derivInds, doubleVals, leftU, rightU, NU, leftV, rightV, NV);
            
            rescaleArray(GNHess, nunkn*nunkn, lambdaSQ);
            rescaleArray(GNgrad, nunkn, lambdaSQ);
            
            computeLinGNmatPnt2Pln(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVoff, noffp, orgNrmls, cpDir, sgnDistDiff, GNHess, GNgrad, derivInds, doubleVals, leftU, rightU, NU, leftV, rightV, NV);
            
            linSysSolver(GNHess, GNgrad, searchDir, nunkn);
            
            updateCPneg(ncpOff, kcpOff, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), searchDir, cpDir);
            
            nrbSrfDerivative(orderUoff-1, orderVoff-1, ncpOff, kcpOff,mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)),mxGetPr(mxGetField(mxGetCell(dNURBSoff, 0), 0, "coefs")),mxGetPr(mxGetCell(mxGetField(mxGetCell(dNURBSoff, 0), 0, "knots"), 0)),mxGetPr(mxGetCell(mxGetField(mxGetCell(dNURBSoff, 0), 0, "knots"), 1)),mxGetPr(mxGetField(mxGetCell(dNURBSoff, 1), 0, "coefs")),mxGetPr(mxGetCell(mxGetField(mxGetCell(dNURBSoff, 1), 0, "knots"), 1)),mxGetPr(mxGetField(mxGetCell(d2NURBSoff, 0), 0, "coefs")),mxGetPr(mxGetField(mxGetCell(d2NURBSoff, 1), 0, "coefs")),mxGetPr(mxGetField(mxGetCell(d2NURBSoff, 2), 0, "coefs")));
            
        }
        
        noffp = norgp;
        
        for (i=0 ; i < numFinalIters ; i++){
            
            findCPdir(10, orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVoff, NURBSoffset, dNURBSoff, d2NURBSoff, UVcp, orgPnts, UVorg, norgp, orderUorg-1, orderVorg-1, ncpOrg, kcpOrg, nrbOrg, dnrbOrg, d2nrbOrg, explWghs, cpDir, leftU, rightU, NU, leftV, rightV, NV);
            
            offsetPnt2PlnDeltaDistNURBS(15, orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVoff, noffp, orgPnts, UVorg, norgp, orderUorg-1, orderVorg-1, ncpOrg, kcpOrg, nrbOrg, dnrbOrg, d2nrbOrg, signDist, sgnDistDiff, explWghs, orgNrmls, leftU, rightU, NU, leftV, rightV, NV);
            
            safeCPdir(ncpOff*kcpOff, cpDir, orgNrmls);
            
            initiateArray2zero(GNHess, nunkn*nunkn);
            initiateArray2zero(GNgrad, nunkn);
            
            computeLinGNmatPnt2Pnt(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVoff, noffp, orgNrmls, cpDir, sgnDistDiff, GNHess, GNgrad, derivInds, doubleVals, leftU, rightU, NU, leftV, rightV, NV);
            
            rescaleArray(GNHess, nunkn*nunkn, lambdaSQ);
            rescaleArray(GNgrad, nunkn, lambdaSQ);
            
            computeLinGNmatPnt2Pln(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVoff, noffp, orgNrmls, cpDir, sgnDistDiff, GNHess, GNgrad, derivInds, doubleVals, leftU, rightU, NU, leftV, rightV, NV);
            
            linSysSolver(GNHess, GNgrad, searchDir, nunkn);
            
            updateCPneg(ncpOff, kcpOff, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), searchDir, cpDir);
            
            nrbSrfDerivative(orderUoff-1, orderVoff-1, ncpOff, kcpOff,mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)),mxGetPr(mxGetField(mxGetCell(dNURBSoff, 0), 0, "coefs")),mxGetPr(mxGetCell(mxGetField(mxGetCell(dNURBSoff, 0), 0, "knots"), 0)),mxGetPr(mxGetCell(mxGetField(mxGetCell(dNURBSoff, 0), 0, "knots"), 1)),mxGetPr(mxGetField(mxGetCell(dNURBSoff, 1), 0, "coefs")),mxGetPr(mxGetCell(mxGetField(mxGetCell(dNURBSoff, 1), 0, "knots"), 1)),mxGetPr(mxGetField(mxGetCell(d2NURBSoff, 0), 0, "coefs")),mxGetPr(mxGetField(mxGetCell(d2NURBSoff, 1), 0, "coefs")),mxGetPr(mxGetField(mxGetCell(d2NURBSoff, 2), 0, "coefs")));
            
        }
        
        nunkn=2*(ncpOff*kcpOff-4);
        
        if (nunkn>0){
            
            findCPdir(10, orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVoff, NURBSoffset, dNURBSoff, d2NURBSoff, UVcp, orgPnts, UVorg, norgp, orderUorg-1, orderVorg-1, ncpOrg, kcpOrg, nrbOrg, dnrbOrg, d2nrbOrg, explWghs, cpDir, leftU, rightU, NU, leftV, rightV, NV);
            
            offsetPnt2PlnDeltaDistNURBS(15, orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVoff, noffp, orgPnts, UVorg, norgp, orderUorg-1, orderVorg-1, ncpOrg, kcpOrg, nrbOrg, dnrbOrg, d2nrbOrg, signDist, sgnDistDiff, explWghs, orgNrmls, leftU, rightU, NU, leftV, rightV, NV);
            
            setCornerCP(mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, orgNrmls, sgnDistDiff);
            
            safeCPdir(ncpOff*kcpOff, cpDir, orgNrmls);
            
            getUnweightedCP(ncpOff, kcpOff, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), mxGetPr(coefsOffset));
            
            initiateArray2zero(GNHess, nunkn*nunkn);
            initiateArray2zero(GNgrad, nunkn);
            
            computeGNmatPnt2Pnt(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), mxGetPr(coefsOffset), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVoff, noffp, orgNrmls, cpDir, sgnDistDiff, GNHess, GNgrad, matInds, derivInds, doubleVals, leftU, rightU, NU, leftV, rightV, NV);
            
            rescaleArray(GNHess, nunkn*nunkn, lambdaSQII);
            rescaleArray(GNgrad, nunkn, lambdaSQII);
            
            computeGNmatPnt2Pln(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), mxGetPr(coefsOffset), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVoff, noffp, orgNrmls, cpDir, sgnDistDiff, GNHess, GNgrad, matInds, derivInds, doubleVals, leftU, rightU, NU, leftV, rightV, NV);
            
            conjugateGradientMethod(GNHess, GNgrad, searchDir, nunkn, MIN(100,(nunkn/2)+10), doubleVals);
            
            scaleGNdir(ncpOff, kcpOff, matInds, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), searchDir);
            
            fdiffStop=lineSearchUpdateOffsetNURBS(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), mxGetPr(coefsOffset), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVoff, noffp, orgNrmls, cpDir, sgnDistDiff, matInds, searchDir, GNgrad, leftU, rightU, NU, leftV, rightV, NV);
            
            nrbSrfDerivative(orderUoff-1, orderVoff-1, ncpOff, kcpOff,mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)),mxGetPr(mxGetField(mxGetCell(dNURBSoff, 0), 0, "coefs")),mxGetPr(mxGetCell(mxGetField(mxGetCell(dNURBSoff, 0), 0, "knots"), 0)),mxGetPr(mxGetCell(mxGetField(mxGetCell(dNURBSoff, 0), 0, "knots"), 1)),mxGetPr(mxGetField(mxGetCell(dNURBSoff, 1), 0, "coefs")),mxGetPr(mxGetCell(mxGetField(mxGetCell(dNURBSoff, 1), 0, "knots"), 1)),mxGetPr(mxGetField(mxGetCell(d2NURBSoff, 0), 0, "coefs")),mxGetPr(mxGetField(mxGetCell(d2NURBSoff, 1), 0, "coefs")),mxGetPr(mxGetField(mxGetCell(d2NURBSoff, 2), 0, "coefs")));
            
            for (i=0 ; i < numGNIters ; i++){
                
                NURBSsurfaceBasisMax(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVoff, leftU, rightU, NU, leftV, rightV, NV);
                NURBSsurfaceBasisValues(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVoff, basisVals, leftU, rightU, NU, leftV, rightV, NV);
                NURBSsurfaceBasisX4Max(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), &UVoff[2*ncpOff*kcpOff], UVoff, basisVals, leftU, rightU, NU, leftV, rightV, NV);
                NURBSsurfaceBasisX2Max(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), &UVoff[2*(ncpOff*kcpOff+(ncpOff-1)*(kcpOff-1))], UVoff, basisVals, leftU, rightU, NU, leftV, rightV, NV);
                NURBSsurfaceBasisX4ScMax(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), &UVoff[2*(ncpOff*kcpOff+(ncpOff-1)*(kcpOff-1)+3*(ncpOff-1)*kcpOff+3*(kcpOff-1)*ncpOff)], UVoff, basisVals, leftU, rightU, NU, leftV, rightV, NV);
                
                findCPdir(10, orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVoff, NURBSoffset, dNURBSoff, d2NURBSoff, UVcp, orgPnts, UVorg, norgp, orderUorg-1, orderVorg-1, ncpOrg, kcpOrg, nrbOrg, dnrbOrg, d2nrbOrg, explWghs, cpDir, leftU, rightU, NU, leftV, rightV, NV);
                
                offsetPnt2PlnDeltaDistNURBS(15, orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVoff, noffp, orgPnts, UVorg, norgp, orderUorg-1, orderVorg-1, ncpOrg, kcpOrg, nrbOrg, dnrbOrg, d2nrbOrg, signDist, sgnDistDiff, explWghs, orgNrmls, leftU, rightU, NU, leftV, rightV, NV);
                
                safeCPdir(ncpOff*kcpOff, cpDir, orgNrmls);
                
                setCornerCP(mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, orgNrmls, sgnDistDiff);
                
                initiateArray2zero(GNHess, nunkn*nunkn);
                initiateArray2zero(GNgrad, nunkn);
                
                computeGNmatPnt2Pnt(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), mxGetPr(coefsOffset), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVoff, noffp, orgNrmls, cpDir, sgnDistDiff, GNHess, GNgrad, matInds, derivInds, doubleVals, leftU, rightU, NU, leftV, rightV, NV);
                
                rescaleArray(GNHess, nunkn*nunkn, lambdaSQII);
                rescaleArray(GNgrad, nunkn, lambdaSQII);
                
                computeGNmatPnt2Pln(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), mxGetPr(coefsOffset), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVoff, noffp, orgNrmls, cpDir, sgnDistDiff, GNHess, GNgrad, matInds, derivInds, doubleVals, leftU, rightU, NU, leftV, rightV, NV);
                
                conjugateGradientMethod(GNHess, GNgrad, searchDir, nunkn, MIN(100,(nunkn/2)+10), doubleVals);
                
                scaleGNdir(ncpOff, kcpOff, matInds, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), searchDir);
                
                fdiffStop=MAX(fdiffStop,lineSearchUpdateOffsetNURBS(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), mxGetPr(coefsOffset), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVoff, noffp, orgNrmls, cpDir, sgnDistDiff, matInds, searchDir, GNgrad, leftU, rightU, NU, leftV, rightV, NV));
                
                nrbSrfDerivative(orderUoff-1, orderVoff-1, ncpOff, kcpOff,mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)),mxGetPr(mxGetField(mxGetCell(dNURBSoff, 0), 0, "coefs")),mxGetPr(mxGetCell(mxGetField(mxGetCell(dNURBSoff, 0), 0, "knots"), 0)),mxGetPr(mxGetCell(mxGetField(mxGetCell(dNURBSoff, 0), 0, "knots"), 1)),mxGetPr(mxGetField(mxGetCell(dNURBSoff, 1), 0, "coefs")),mxGetPr(mxGetCell(mxGetField(mxGetCell(dNURBSoff, 1), 0, "knots"), 1)),mxGetPr(mxGetField(mxGetCell(d2NURBSoff, 0), 0, "coefs")),mxGetPr(mxGetField(mxGetCell(d2NURBSoff, 1), 0, "coefs")),mxGetPr(mxGetField(mxGetCell(d2NURBSoff, 2), 0, "coefs")));
                
            }
            
            if (fdiffStop>1e-10){
                
                fdiffStop=1e-4*fdiffStop;
                
                for (i=0 ; i < numFinalGNIters ; i++){
                    
                    NURBSsurfaceBasisMax(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVoff, leftU, rightU, NU, leftV, rightV, NV);
                    NURBSsurfaceBasisValues(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVoff, basisVals, leftU, rightU, NU, leftV, rightV, NV);
                    NURBSsurfaceBasisX4Max(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), &UVoff[2*ncpOff*kcpOff], UVoff, basisVals, leftU, rightU, NU, leftV, rightV, NV);
                    NURBSsurfaceBasisX2Max(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), &UVoff[2*(ncpOff*kcpOff+(ncpOff-1)*(kcpOff-1))], UVoff, basisVals, leftU, rightU, NU, leftV, rightV, NV);
                    NURBSsurfaceBasisX4ScMax(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), &UVoff[2*(ncpOff*kcpOff+(ncpOff-1)*(kcpOff-1)+3*(ncpOff-1)*kcpOff+3*(kcpOff-1)*ncpOff)], UVoff, basisVals, leftU, rightU, NU, leftV, rightV, NV);
                    
                    findCPdir(10, orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVoff, NURBSoffset, dNURBSoff, d2NURBSoff, UVcp, orgPnts, UVorg, norgp, orderUorg-1, orderVorg-1, ncpOrg, kcpOrg, nrbOrg, dnrbOrg, d2nrbOrg, explWghs, cpDir, leftU, rightU, NU, leftV, rightV, NV);
                    
                    offsetPnt2PlnDeltaDistNURBS(15, orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVoff, noffp, orgPnts, UVorg, norgp, orderUorg-1, orderVorg-1, ncpOrg, kcpOrg, nrbOrg, dnrbOrg, d2nrbOrg, signDist, sgnDistDiff, explWghs, orgNrmls, leftU, rightU, NU, leftV, rightV, NV);
                    
                    safeCPdir(ncpOff*kcpOff, cpDir, orgNrmls);
                    
                    setCornerCP(mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, orgNrmls, sgnDistDiff);
                    
                    initiateArray2zero(GNHess, nunkn*nunkn);
                    initiateArray2zero(GNgrad, nunkn);
                    
                    computeGNmatPnt2Pnt(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), mxGetPr(coefsOffset), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVoff, noffp, orgNrmls, cpDir, sgnDistDiff, GNHess, GNgrad, matInds, derivInds, doubleVals, leftU, rightU, NU, leftV, rightV, NV);
                    
                    rescaleArray(GNHess, nunkn*nunkn, lambdaSQII);
                    rescaleArray(GNgrad, nunkn, lambdaSQII);
                    
                    computeGNmatPnt2Pln(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), mxGetPr(coefsOffset), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVoff, noffp, orgNrmls, cpDir, sgnDistDiff, GNHess, GNgrad, matInds, derivInds, doubleVals, leftU, rightU, NU, leftV, rightV, NV);
                    
                    conjugateGradientMethod(GNHess, GNgrad, searchDir, nunkn, MIN(100,(nunkn/2)+10), doubleVals);
                    
                    scaleGNdir(ncpOff, kcpOff, matInds, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), searchDir);
                    
                    if (lineSearchUpdateOffsetNURBS(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), mxGetPr(coefsOffset), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVoff, noffp, orgNrmls, cpDir, sgnDistDiff, matInds, searchDir, GNgrad, leftU, rightU, NU, leftV, rightV, NV)<fdiffStop){
                        nrbSrfDerivative(orderUoff-1, orderVoff-1, ncpOff, kcpOff,mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)),mxGetPr(mxGetField(mxGetCell(dNURBSoff, 0), 0, "coefs")),mxGetPr(mxGetCell(mxGetField(mxGetCell(dNURBSoff, 0), 0, "knots"), 0)),mxGetPr(mxGetCell(mxGetField(mxGetCell(dNURBSoff, 0), 0, "knots"), 1)),mxGetPr(mxGetField(mxGetCell(dNURBSoff, 1), 0, "coefs")),mxGetPr(mxGetCell(mxGetField(mxGetCell(dNURBSoff, 1), 0, "knots"), 1)),mxGetPr(mxGetField(mxGetCell(d2NURBSoff, 0), 0, "coefs")),mxGetPr(mxGetField(mxGetCell(d2NURBSoff, 1), 0, "coefs")),mxGetPr(mxGetField(mxGetCell(d2NURBSoff, 2), 0, "coefs")));
                        break;
                    }
                    else {
                        nrbSrfDerivative(orderUoff-1, orderVoff-1, ncpOff, kcpOff,mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)),mxGetPr(mxGetField(mxGetCell(dNURBSoff, 0), 0, "coefs")),mxGetPr(mxGetCell(mxGetField(mxGetCell(dNURBSoff, 0), 0, "knots"), 0)),mxGetPr(mxGetCell(mxGetField(mxGetCell(dNURBSoff, 0), 0, "knots"), 1)),mxGetPr(mxGetField(mxGetCell(dNURBSoff, 1), 0, "coefs")),mxGetPr(mxGetCell(mxGetField(mxGetCell(dNURBSoff, 1), 0, "knots"), 1)),mxGetPr(mxGetField(mxGetCell(d2NURBSoff, 0), 0, "coefs")),mxGetPr(mxGetField(mxGetCell(d2NURBSoff, 1), 0, "coefs")),mxGetPr(mxGetField(mxGetCell(d2NURBSoff, 2), 0, "coefs")));
                    }
                    
                }
                
                noffp = ncpOff*kcpOff+25*(ncpOff-1)*(kcpOff-1)+3*(ncpOff-1)*kcpOff+3*(kcpOff-1)*ncpOff;
                
                for (i=0 ; i < numFinalGNItersII ; i++){
                    
                    NURBSsurfaceBasisMax(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVoff, leftU, rightU, NU, leftV, rightV, NV);
                    NURBSsurfaceBasisValues(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVoff, basisVals, leftU, rightU, NU, leftV, rightV, NV);
                    NURBSsurfaceBasisX4Max(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), &UVoff[2*ncpOff*kcpOff], UVoff, basisVals, leftU, rightU, NU, leftV, rightV, NV);
                    NURBSsurfaceBasisX2Max(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), &UVoff[2*(ncpOff*kcpOff+(ncpOff-1)*(kcpOff-1))], UVoff, basisVals, leftU, rightU, NU, leftV, rightV, NV);
                    NURBSsurfaceBasisX4ScMax(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), &UVoff[2*(ncpOff*kcpOff+(ncpOff-1)*(kcpOff-1)+3*(ncpOff-1)*kcpOff+3*(kcpOff-1)*ncpOff)], UVoff, basisVals, leftU, rightU, NU, leftV, rightV, NV);
                    NURBSsurfaceBasisX16ScMax(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), &UVoff[2*(ncpOff*kcpOff+9*(ncpOff-1)*(kcpOff-1)+3*(ncpOff-1)*kcpOff+3*(kcpOff-1)*ncpOff)], UVoff, basisVals, leftU, rightU, NU, leftV, rightV, NV);
                    
                    findCPdir(10, orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVoff, NURBSoffset, dNURBSoff, d2NURBSoff, UVcp, orgPnts, UVorg, norgp, orderUorg-1, orderVorg-1, ncpOrg, kcpOrg, nrbOrg, dnrbOrg, d2nrbOrg, explWghs, cpDir, leftU, rightU, NU, leftV, rightV, NV);
                    
                    offsetPnt2PlnDeltaDistNURBS(15, orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVoff, noffp, orgPnts, UVorg, norgp, orderUorg-1, orderVorg-1, ncpOrg, kcpOrg, nrbOrg, dnrbOrg, d2nrbOrg, signDist, sgnDistDiff, explWghs, orgNrmls, leftU, rightU, NU, leftV, rightV, NV);
                    
                    safeCPdir(ncpOff*kcpOff, cpDir, orgNrmls);
                    
                    setCornerCP(mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), ncpOff, kcpOff, orgNrmls, sgnDistDiff);
                    
                    initiateArray2zero(GNHess, nunkn*nunkn);
                    initiateArray2zero(GNgrad, nunkn);
                    
                    computeGNmatPnt2Pnt(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), mxGetPr(coefsOffset), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVoff, noffp, orgNrmls, cpDir, sgnDistDiff, GNHess, GNgrad, matInds, derivInds, doubleVals, leftU, rightU, NU, leftV, rightV, NV);
                    
                    rescaleArray(GNHess, nunkn*nunkn, lambdaSQII);
                    rescaleArray(GNgrad, nunkn, lambdaSQII);
                    
                    computeGNmatPnt2Pln(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), mxGetPr(coefsOffset), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVoff, noffp, orgNrmls, cpDir, sgnDistDiff, GNHess, GNgrad, matInds, derivInds, doubleVals, leftU, rightU, NU, leftV, rightV, NV);
                    
                    conjugateGradientMethod(GNHess, GNgrad, searchDir, nunkn, MIN(100,(nunkn/2)+10), doubleVals);
                    
                    scaleGNdir(ncpOff, kcpOff, matInds, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), searchDir);
                    
                    lineSearchUpdateOffsetNURBS(orderUoff-1, orderVoff-1, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), mxGetPr(coefsOffset), ncpOff, kcpOff, mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)), UVoff, noffp, orgNrmls, cpDir, sgnDistDiff, matInds, searchDir, GNgrad, leftU, rightU, NU, leftV, rightV, NV);
                    
                    nrbSrfDerivative(orderUoff-1, orderVoff-1, ncpOff, kcpOff,mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(NURBSoffset, 0, "knots"), 1)),mxGetPr(mxGetField(mxGetCell(dNURBSoff, 0), 0, "coefs")),mxGetPr(mxGetCell(mxGetField(mxGetCell(dNURBSoff, 0), 0, "knots"), 0)),mxGetPr(mxGetCell(mxGetField(mxGetCell(dNURBSoff, 0), 0, "knots"), 1)),mxGetPr(mxGetField(mxGetCell(dNURBSoff, 1), 0, "coefs")),mxGetPr(mxGetCell(mxGetField(mxGetCell(dNURBSoff, 1), 0, "knots"), 1)),mxGetPr(mxGetField(mxGetCell(d2NURBSoff, 0), 0, "coefs")),mxGetPr(mxGetField(mxGetCell(d2NURBSoff, 1), 0, "coefs")),mxGetPr(mxGetField(mxGetCell(d2NURBSoff, 2), 0, "coefs")));
                    
                }
                
            }
            
        }
        
        getUnweightedCP(ncpOff, kcpOff, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), mxGetPr(coefsOffset));
        
        mxDestroyArray(dNURBSoff);
        mxDestroyArray(d2NURBSoff);
        
        free(leftU);
        free(rightU);
        free(NU);
        free(leftV);
        free(rightV);
        free(NV);
        
        free(UVorg);
        free(UVoff);
        free(UVcp);
        
        free(basisVals);
        free(cpDir);
        free(orgPnts);
        free(orgNrmls);
        free(sgnDistDiff);
        
        free(derivInds);
        free(matInds);
        
        free(GNHess);
        free(GNgrad);
        free(searchDir);
        free(doubleVals);
        
        wghsOffset = mxCreateDoubleMatrix(ncpOff, kcpOff, mxREAL);
        
        getWeights(ncpOff, kcpOff, mxGetPr(mxGetField(NURBSoffset, 0, "coefs")), mxGetPr(wghsOffset));
        
    }
    else {
        
        mexErrMsgTxt("Wrong number of inputs or outputs.");
        
    }
    
    return;
    
}

