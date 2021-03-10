/*=================================================================
 *
 * This is an implementation of the ICP method using a DVG-tree, [1], and point to plane minimization [2].
 * Tukey's biweight-estimator is used to make it more robust and
 * reduce the influence of bad data (Beaton/Tukey) [3].
 *
 * Commpile in Matlab by running: mex -v icpDVGpnt2plnTu.c
 *
 * Usage:
 *
 * icpDVGpnt2plnTu(DATA,quality,quasirand,sizerand,randincreasing,maxiter,kTu,SURFDATA,DVGdata,R,t)
 *
 * Input:
 *
 * DATA - the data points
 * quality - a vector with quality values corresponding to DATA
 * quasirand - a vector with a pseudo random permumation of the indices of DATA
 * sizerand - size of the random subset of DATA which is used in the iterations
 * randincreasing - the increasing of sizerand in each iteration
 * maxiter - the number of ICP-iterations
 * kTu - the value of the parameter in Tukey's biweight-estimator, see [2]
 * SURFDATA - surface data (output from icpSrfLinRep)
 * DVGdata - the data structure (output from getDVGtree)
 *
 * Input/Output:
 *
 * R - rotation matrix
 * t - translation vector
 *
 * Written by Per Bergström 2015-10-04
 *
 * References
 *
 * [1]
 * Authors: Per Bergström, Ove Edlund, and Inge Söderkvist
 * Title: Repeated surface registration for on-line use
 * Journal: The International Journal of Advanced Manufacturing Technology
 * Cover Date: 2011-05-01
 * Publisher: Springer London
 * Issn: 0268-3768
 * Pages: 677-689
 * Volume: 54
 * Issue: 5
 * Url: http://dx.doi.org/10.1007/s00170-010-2950-6
 * Doi: 10.1007/s00170-010-2950-6
 *
 * [2]
 * Author: Per Bergström
 * Title: Reliable updates of the transformation in the iterative closest point algorithm
 * Journal: Computational Optimization and Applications
 * Cover Date: March 2016
 * Publisher: Springer Nature
 * Issn: 0926-6003
 * Pages: 543-557
 * Volume: 63
 * Issue: 2
 * Url: http://dx.doi.org/10.1007/s10589-015-9771-3
 * Doi: 10.1007/s10589-015-9771-3
 *
 * [3]
 * Author: Per Bergström and Ove Edlund
 * Title: Robust registration of point sets using iteratively reweighted least squares
 * Journal: Computational Optimization and Applications
 * Cover Date: 2014-07
 * Publisher: Springer Nature
 * Issn: 0926-6003
 * Pages: 543-561
 * Volume: 58
 * Issue: 3
 * Url: http://dx.doi.org/10.1007/s10589-014-9643-2
 * Doi: 10.1007/s10589-014-9643-2
 *
 * [4]
 * Author: Per Bergström and Ove Edlund
 * Title: Robust registration of surfaces using a refined iterative closest point algorithm with a trust region approach
 * Journal: Numerical Algorithms
 * Cover Date: (2016) 2017
 * Publisher: Springer Nature
 * Issn:
 * Pages:
 * Volume:
 * Issue:
 * Url: http://dx.doi.org/10.1007/s11075-016-0170-3
 * Doi: 10.1007/s11075-016-0170-3
 *
 *
 * See also:  https://se.mathworks.com/matlabcentral/fileexchange/12627-iterative-closest-point-method
 *
 *=================================================================*/


#include <math.h>
#include "mex.h"


/* Input Arguments */

#define	data	prhs[0]
#define	quality	prhs[1]
#define	randvec	prhs[2]
#define	sizerand	prhs[3]
#define	randincrease	prhs[4]
#define	maxiter	prhs[5]
#define	kTukey	prhs[6]
#define	surfdata	prhs[7]
#define	DVGdata	prhs[8]


/* Output Arguments */

#define	rotationMatrixIO	prhs[9]
#define	transVecIO     prhs[10]


#if !defined(MAX)
#define	MAX(A, B)	((A) > (B) ? (A) : (B))
#endif

#if !defined(MIN)
#define	MIN(A, B)	((A) < (B) ? (A) : (B))
#endif

#define	caxis	0

/* Power 2 function */

double pwr2(double a){
    return a*a;
}

/* Sub functions (in folder "mexSourceFiles") */

#include "mexSourceFiles/linalgR6x6.c"
#include "mexSourceFiles/rotmatCmptns.c"
#include "mexSourceFiles/genzCGM.c"
#include "mexSourceFiles/constrainingFcn.c"
#include "mexSourceFiles/findBoundary.c"
#include "mexSourceFiles/linesearchRcprBarrier.c"
#include "mexSourceFiles/trustRegionFuncRcprclBarrier.c"
#include "mexSourceFiles/rotMatrixCCOV.c"

/* Main function */

void icpDVGpnt2plnTu(
        double *dataPoints,
        double *qltyDataPoints,
        unsigned int numDataPoints,
        unsigned int *quasiRndNumbers,
        unsigned int numRndInIters,
        unsigned int rndIncrease,
        unsigned int ICP_iters,
        double TukeysParam,
        double *modelSurfaceData,
        mxArray *DVGtree,
        double *rotationMatrix,
        double *translationVector
        ){
    
    unsigned short int bol;
    unsigned int i, j, k, ii, threei, dataIndRndIndex, gridInd, treeind, numQuasiRndNumbers_1, indQuasiRndNumbers=0;
    int cloIndTmp, fourteencloIndTmp;
    double gridSpace0, gridIndFloat, *refSys;
    double *dNvertex, *dNvertex_1;
    unsigned int n00, n01, n02, nT;
    unsigned int *uintpntr, *Nvertex, *Nvertex_1, *NvertexSq, *Nvertex_1xn, *Nvertex_1xnxn;
    int *dataStruct0, *dataStruct;
    unsigned int n00_1, n01_1, n02_1, n01_1xn00, n02_1xn00xn01, n00xn01;
    double dn00_1, dn01_1, dn02_1;
    double dataTemp[3], dataOriginalTemp[3], tmpWgh, TukeysParamSq;
    double datam[3], modelm[3], MM[3], Spx[9], quasum;
    double SIGMA[3], doubleVar, doubleVars[83];
    double HessianLinApprx[21], gradientLinApprx[6], NewtonStep[6], NewtonStepOLD[6], tmpRotMat[9], tmpTranslVec[3], paramsOut[6], paramsOutOLD[6], paramsAst[6], regionValArray[2];
    
    
    TukeysParamSq=TukeysParam*TukeysParam;
    
    uintpntr=(unsigned int*)mxGetPr(mxGetCell(DVGtree,0));
    nT=uintpntr[0];
    
    refSys=mxGetPr(mxGetCell(DVGtree,1));
    
    uintpntr=(unsigned int*)mxGetPr(mxGetCell(DVGtree,2));
    n00=uintpntr[0];
    n01=uintpntr[1];
    n02=uintpntr[2];
    
    gridSpace0=mxGetPr(mxGetCell(DVGtree,3))[0];
    
    Nvertex=(unsigned int*)mxGetPr(mxGetCell(DVGtree,4));
    
    dataStruct0=(int*)mxGetPr(mxGetCell(DVGtree,5));
    
    numQuasiRndNumbers_1=numDataPoints-1;
    
    n00_1=n00-1;
    n01_1=n01-1;
    n02_1=n02-1;
    n01_1xn00=n01_1*n00;
    n02_1xn00xn01=n02_1*n00*n01;
    n00xn01=n00*n01;
    dn00_1=(double)n00_1;
    dn01_1=(double)n01_1;
    dn02_1=(double)n02_1;
    
    Nvertex_1=(unsigned int *)malloc(nT*sizeof(unsigned int));
    NvertexSq=(unsigned int *)malloc(nT*sizeof(unsigned int));
    Nvertex_1xn=(unsigned int *)malloc(nT*sizeof(unsigned int));
    Nvertex_1xnxn=(unsigned int *)malloc(nT*sizeof(unsigned int));
    dNvertex=(double *)malloc(nT*sizeof(double));
    dNvertex_1=(double *)malloc(nT*sizeof(double));
    
    for (i=0;i<nT;i++){
        Nvertex_1[i]=Nvertex[i]-1;
        NvertexSq[i]=Nvertex[i]*Nvertex[i];
        Nvertex_1xn[i]=NvertexSq[i]-Nvertex[i];
        Nvertex_1xnxn[i]=NvertexSq[i]*Nvertex_1[i];
        dNvertex[i]=(double)Nvertex[i];
        dNvertex_1[i]=(double)Nvertex_1[i];
    }
    
    numRndInIters=MIN(numRndInIters,numDataPoints);
    
    if (numRndInIters==numDataPoints){
        bol=0;
    }
    else {
        bol=1;
        if (numRndInIters<25){
            numRndInIters=MIN(25,numDataPoints);
        }
    }
    
    for (ii=0;ii<ICP_iters;ii++){
        
        for (i=0;i<9;i++){
            Spx[i]=0.0;
        }
        for (i=0;i<3;i++){
            modelm[i]=0.0;
            datam[i]=0.0;
        }
        for (i=0;i<21;i++){
            HessianLinApprx[i]=0.0;
        }
        for (i=0;i<6;i++){
            gradientLinApprx[i]=0.0;
        }
        
        quasum=0.0;
        
        for (dataIndRndIndex=0;dataIndRndIndex<numRndInIters;dataIndRndIndex++){
            
            if (bol){
                i=quasiRndNumbers[indQuasiRndNumbers];
                if (indQuasiRndNumbers<numQuasiRndNumbers_1){
                    indQuasiRndNumbers++;
                }
                else{
                    indQuasiRndNumbers=0;
                }
            }
            else{
                i=dataIndRndIndex;
            }
            
            tmpWgh=qltyDataPoints[i];
            threei=3*i;
            
            if (tmpWgh>0.0){
                
                dataOriginalTemp[0]=dataPoints[threei];
                dataOriginalTemp[1]=dataPoints[threei+1];
                dataOriginalTemp[2]=dataPoints[threei+2];
                
                dataTemp[0]=rotationMatrix[0]*dataOriginalTemp[0]+rotationMatrix[3]*dataOriginalTemp[1]+rotationMatrix[6]*dataOriginalTemp[2]+translationVector[0];
                dataTemp[1]=rotationMatrix[1]*dataOriginalTemp[0]+rotationMatrix[4]*dataOriginalTemp[1]+rotationMatrix[7]*dataOriginalTemp[2]+translationVector[1];
                dataTemp[2]=rotationMatrix[2]*dataOriginalTemp[0]+rotationMatrix[5]*dataOriginalTemp[1]+rotationMatrix[8]*dataOriginalTemp[2]+translationVector[2];
                
                
                /* Finding the index of the closest model point  */
                
                
                /**** TREE LEVEL 0  ****/
                
                /* normal direction */
                if (caxis){
                    gridIndFloat=(refSys[2]-dataTemp[2])/gridSpace0;
                }
                else{
                    gridIndFloat=(refSys[3]*(dataTemp[0]-refSys[0])+refSys[4]*(dataTemp[1]-refSys[1])+refSys[5]*(dataTemp[2]-refSys[2]))/gridSpace0;
                }
                
                if (gridIndFloat<1.0){
                    gridInd=0;
                    SIGMA[0]=gridIndFloat;
                }
                else if (gridIndFloat>=n00_1){
                    gridInd=n00_1;
                    SIGMA[0]=gridIndFloat-dn00_1;
                }
                else{
                    gridInd=(unsigned int)gridIndFloat;
                    SIGMA[0]=gridIndFloat-(double)gridInd;
                }
                
                /* primary direction */
                if (caxis){
                    gridIndFloat=(dataTemp[0]-refSys[0])/gridSpace0;
                }
                else{
                    gridIndFloat=(refSys[6]*(dataTemp[0]-refSys[0])+refSys[7]*(dataTemp[1]-refSys[1])+refSys[8]*(dataTemp[2]-refSys[2]))/gridSpace0;
                }
                
                if (gridIndFloat<1.0){
                    SIGMA[1]=gridIndFloat;
                }
                else if (gridIndFloat>=n01_1){
                    gridInd+=n01_1xn00;
                    SIGMA[1]=gridIndFloat-dn01_1;
                }
                else{
                    k=(unsigned int)gridIndFloat;
                    gridInd+=k*n00;
                    SIGMA[1]=gridIndFloat-(double)k;
                }
                
                /* secondary direction */
                if (caxis){
                    gridIndFloat=(dataTemp[1]-refSys[1])/gridSpace0;
                }
                else{
                    gridIndFloat=(refSys[9]*(dataTemp[0]-refSys[0])+refSys[10]*(dataTemp[1]-refSys[1])+refSys[11]*(dataTemp[2]-refSys[2]))/gridSpace0;
                }
                
                if (gridIndFloat<1.0){
                    SIGMA[2]=gridIndFloat;
                }
                else if (gridIndFloat>=n02_1){
                    gridInd+=n02_1xn00xn01;
                    SIGMA[2]=gridIndFloat-dn02_1;
                }
                else{
                    k=(unsigned int)gridIndFloat;
                    gridInd+=k*n00xn01;
                    SIGMA[2]=gridIndFloat-(double)k;
                }
                
                treeind=0;
                cloIndTmp=dataStruct0[gridInd];
                
                /**** TREE LEVEL 1,2,...  ****/
                
                while (cloIndTmp<0){
                    
                    SIGMA[0]*=dNvertex[treeind];
                    SIGMA[1]*=dNvertex[treeind];
                    SIGMA[2]*=dNvertex[treeind];
                    
                    /* normal direction */
                    if (SIGMA[0]<1.0){
                        gridInd=0;
                    }
                    else if (SIGMA[0]>=Nvertex_1[treeind]){
                        gridInd=Nvertex_1[treeind];
                        SIGMA[0]-=-dNvertex_1[treeind];
                    }
                    else{
                        gridInd=(unsigned int)SIGMA[0];
                        SIGMA[0]-=(double)gridInd;
                    }
                    
                    /* primary direction */
                    if (SIGMA[1]<1.0){
                        
                    }
                    else if (SIGMA[1]>=Nvertex_1[treeind]){
                        gridInd+=Nvertex_1xn[treeind];
                        SIGMA[1]-=dNvertex_1[treeind];
                    }
                    else{
                        k=(unsigned int)SIGMA[1];
                        gridInd+=k*Nvertex[treeind];
                        SIGMA[1]-=(double)k;
                    }
                    
                    /* secondary direction */
                    if (SIGMA[2]<1.0){
                        
                    }
                    else if (SIGMA[2]>=Nvertex_1[treeind]){
                        gridInd+=Nvertex_1xnxn[treeind];
                        SIGMA[2]-=dNvertex_1[treeind];
                    }
                    else{
                        k=(unsigned int)SIGMA[2];
                        gridInd+=k*NvertexSq[treeind];
                        SIGMA[2]-=(double)k;
                    }
                    
                    dataStruct=(int*)mxGetPr(mxGetCell(DVGtree,6+treeind));
                    cloIndTmp=dataStruct[gridInd-cloIndTmp-1];
                    treeind++;
                    
                }
                
                fourteencloIndTmp=14*cloIndTmp;
                
                /* Closest model index is found, MM closest model point */
                
                MM[0]=modelSurfaceData[fourteencloIndTmp];
                MM[1]=modelSurfaceData[fourteencloIndTmp+1];
                MM[2]=modelSurfaceData[fourteencloIndTmp+2];
                
                
                /* Start using the DIRVEC for applying the linear surface approximation */
                
                doubleVar=(dataTemp[0]-MM[0])*modelSurfaceData[fourteencloIndTmp+4]+(dataTemp[1]-MM[1])*modelSurfaceData[fourteencloIndTmp+5]+(dataTemp[2]-MM[2])*modelSurfaceData[fourteencloIndTmp+6];
                if (doubleVar>modelSurfaceData[fourteencloIndTmp+3]){
                    MM[0]+=modelSurfaceData[fourteencloIndTmp+3]*modelSurfaceData[fourteencloIndTmp+4];
                    MM[1]+=modelSurfaceData[fourteencloIndTmp+3]*modelSurfaceData[fourteencloIndTmp+5];
                    MM[2]+=modelSurfaceData[fourteencloIndTmp+3]*modelSurfaceData[fourteencloIndTmp+6];
                }
                else if (doubleVar<(-modelSurfaceData[fourteencloIndTmp+3])){
                    MM[0]-=modelSurfaceData[fourteencloIndTmp+3]*modelSurfaceData[fourteencloIndTmp+4];
                    MM[1]-=modelSurfaceData[fourteencloIndTmp+3]*modelSurfaceData[fourteencloIndTmp+5];
                    MM[2]-=modelSurfaceData[fourteencloIndTmp+3]*modelSurfaceData[fourteencloIndTmp+6];
                }
                else{
                    MM[0]+=doubleVar*modelSurfaceData[fourteencloIndTmp+4];
                    MM[1]+=doubleVar*modelSurfaceData[fourteencloIndTmp+5];
                    MM[2]+=doubleVar*modelSurfaceData[fourteencloIndTmp+6];
                }
                doubleVar=(dataTemp[0]-MM[0])*modelSurfaceData[fourteencloIndTmp+8]+(dataTemp[1]-MM[1])*modelSurfaceData[fourteencloIndTmp+9]+(dataTemp[2]-MM[2])*modelSurfaceData[fourteencloIndTmp+10];
                if (doubleVar>modelSurfaceData[fourteencloIndTmp+7]){
                    MM[0]+=modelSurfaceData[fourteencloIndTmp+7]*modelSurfaceData[fourteencloIndTmp+8];
                    MM[1]+=modelSurfaceData[fourteencloIndTmp+7]*modelSurfaceData[fourteencloIndTmp+9];
                    MM[2]+=modelSurfaceData[fourteencloIndTmp+7]*modelSurfaceData[fourteencloIndTmp+10];
                }
                else if (doubleVar<(-modelSurfaceData[fourteencloIndTmp+7])){
                    MM[0]-=modelSurfaceData[fourteencloIndTmp+7]*modelSurfaceData[fourteencloIndTmp+8];
                    MM[1]-=modelSurfaceData[fourteencloIndTmp+7]*modelSurfaceData[fourteencloIndTmp+9];
                    MM[2]-=modelSurfaceData[fourteencloIndTmp+7]*modelSurfaceData[fourteencloIndTmp+10];
                }
                else{
                    MM[0]+=doubleVar*modelSurfaceData[fourteencloIndTmp+8];
                    MM[1]+=doubleVar*modelSurfaceData[fourteencloIndTmp+9];
                    MM[2]+=doubleVar*modelSurfaceData[fourteencloIndTmp+10];
                }
                
                doubleVars[0]=dataTemp[0]-MM[0];
                doubleVars[1]=dataTemp[1]-MM[1];
                doubleVars[2]=dataTemp[2]-MM[2];
                
                doubleVar=doubleVars[0]*modelSurfaceData[fourteencloIndTmp+11]+doubleVars[1]*modelSurfaceData[fourteencloIndTmp+12]+doubleVars[2]*modelSurfaceData[fourteencloIndTmp+13];
                doubleVars[14]=pwr2(doubleVars[0])+pwr2(doubleVars[1])+pwr2(doubleVars[2]);
                
                if (doubleVars[14]<TukeysParamSq){
                    
                    /* Point to tangent plane */
                    
                    doubleVars[3]=pwr2(doubleVar)/TukeysParamSq;
                    doubleVars[4]=1.0-doubleVars[3];
                    doubleVars[5]=tmpWgh*doubleVar*pwr2(doubleVars[4]);
                    doubleVars[6]=tmpWgh*doubleVars[4]*(1.0-5.0*doubleVars[3]);
                    
                    doubleVars[7]=dataTemp[1]*modelSurfaceData[fourteencloIndTmp+13]-dataTemp[2]*modelSurfaceData[fourteencloIndTmp+12];
                    doubleVars[8]=dataTemp[2]*modelSurfaceData[fourteencloIndTmp+11]-dataTemp[0]*modelSurfaceData[fourteencloIndTmp+13];
                    doubleVars[9]=dataTemp[0]*modelSurfaceData[fourteencloIndTmp+12]-dataTemp[1]*modelSurfaceData[fourteencloIndTmp+11];
                    
                    
                    /* Hessian matrix */
                    
                    doubleVars[10]=doubleVars[6]*doubleVars[7];
                    doubleVars[11]=doubleVars[5]*dataTemp[0]*modelSurfaceData[fourteencloIndTmp+11];
                    doubleVars[12]=doubleVars[5]*dataTemp[1]*modelSurfaceData[fourteencloIndTmp+12];
                    doubleVars[13]=doubleVars[5]*dataTemp[2]*modelSurfaceData[fourteencloIndTmp+13];
                    
                    HessianLinApprx[0]+=doubleVars[10]*doubleVars[7]-(doubleVars[12]+doubleVars[13]);
                    HessianLinApprx[1]+=doubleVars[10]*doubleVars[8]+doubleVars[5]*dataTemp[1]*modelSurfaceData[fourteencloIndTmp+11];
                    HessianLinApprx[2]+=doubleVars[10]*doubleVars[9]+doubleVars[5]*dataTemp[2]*modelSurfaceData[fourteencloIndTmp+11];
                    
                    HessianLinApprx[3]+=doubleVars[10]*modelSurfaceData[fourteencloIndTmp+11];
                    HessianLinApprx[4]+=doubleVars[10]*modelSurfaceData[fourteencloIndTmp+12];
                    HessianLinApprx[5]+=doubleVars[10]*modelSurfaceData[fourteencloIndTmp+13];
                    
                    doubleVars[10]=doubleVars[6]*doubleVars[8];
                    HessianLinApprx[6]+=doubleVars[10]*doubleVars[8]-(doubleVars[11]+doubleVars[13]);
                    HessianLinApprx[7]+=doubleVars[10]*doubleVars[9]+doubleVars[5]*dataTemp[2]*modelSurfaceData[fourteencloIndTmp+12];
                    
                    HessianLinApprx[8]+=doubleVars[10]*modelSurfaceData[fourteencloIndTmp+11];
                    HessianLinApprx[9]+=doubleVars[10]*modelSurfaceData[fourteencloIndTmp+12];
                    HessianLinApprx[10]+=doubleVars[10]*modelSurfaceData[fourteencloIndTmp+13];
                    
                    doubleVars[10]=doubleVars[6]*doubleVars[9];
                    HessianLinApprx[11]+=doubleVars[10]*doubleVars[9]-(doubleVars[11]+doubleVars[12]);
                    
                    HessianLinApprx[12]+=doubleVars[10]*modelSurfaceData[fourteencloIndTmp+11];
                    HessianLinApprx[13]+=doubleVars[10]*modelSurfaceData[fourteencloIndTmp+12];
                    HessianLinApprx[14]+=doubleVars[10]*modelSurfaceData[fourteencloIndTmp+13];
                    
                    doubleVars[10]=doubleVars[6]*modelSurfaceData[fourteencloIndTmp+11];
                    HessianLinApprx[15]+=doubleVars[10]*modelSurfaceData[fourteencloIndTmp+11];
                    HessianLinApprx[16]+=doubleVars[10]*modelSurfaceData[fourteencloIndTmp+12];
                    HessianLinApprx[17]+=doubleVars[10]*modelSurfaceData[fourteencloIndTmp+13];
                    
                    doubleVars[10]=doubleVars[6]*modelSurfaceData[fourteencloIndTmp+12];
                    HessianLinApprx[18]+=doubleVars[10]*modelSurfaceData[fourteencloIndTmp+12];
                    HessianLinApprx[19]+=doubleVars[10]*modelSurfaceData[fourteencloIndTmp+13];
                    
                    HessianLinApprx[20]+=doubleVars[6]*modelSurfaceData[fourteencloIndTmp+13]*modelSurfaceData[fourteencloIndTmp+13];
                    
                    /* gradient vector */
                    gradientLinApprx[0]+=doubleVars[5]*doubleVars[7];
                    gradientLinApprx[1]+=doubleVars[5]*doubleVars[8];
                    gradientLinApprx[2]+=doubleVars[5]*doubleVars[9];
                    
                    gradientLinApprx[3]+=doubleVars[5]*modelSurfaceData[fourteencloIndTmp+11];
                    gradientLinApprx[4]+=doubleVars[5]*modelSurfaceData[fourteencloIndTmp+12];
                    gradientLinApprx[5]+=doubleVars[5]*modelSurfaceData[fourteencloIndTmp+13];
                    
                    
                    tmpWgh*=pwr2(1.0-doubleVars[14]/TukeysParamSq);
                    
                    /* Mean values and cross covariance matrix, point to point correspondence */
                    
                    MM[0]=tmpWgh*MM[0];
                    MM[1]=tmpWgh*MM[1];
                    MM[2]=tmpWgh*MM[2];
                    
                    modelm[0]+=MM[0];
                    modelm[1]+=MM[1];
                    modelm[2]+=MM[2];
                    
                    datam[0]+=tmpWgh*dataTemp[0];
                    datam[1]+=tmpWgh*dataTemp[1];
                    datam[2]+=tmpWgh*dataTemp[2];
                    
                    Spx[0]+= MM[0]*dataTemp[0];
                    Spx[1]+= MM[1]*dataTemp[0];
                    Spx[2]+= MM[2]*dataTemp[0];
                    Spx[3]+= MM[0]*dataTemp[1];
                    Spx[4]+= MM[1]*dataTemp[1];
                    Spx[5]+= MM[2]*dataTemp[1];
                    Spx[6]+= MM[0]*dataTemp[2];
                    Spx[7]+= MM[1]*dataTemp[2];
                    Spx[8]+= MM[2]*dataTemp[2];
                    
                    quasum+=tmpWgh;
                    
                }
                
            }
            
        }
        
        if (quasum<1e-12){
            break;
        }
        
        /* Obtain the cross-covariance matrix, Spx */
        
        modelm[0]=modelm[0]/quasum;
        modelm[1]=modelm[1]/quasum;
        modelm[2]=modelm[2]/quasum;
        
        Spx[0]-=modelm[0]*datam[0];
        Spx[1]-=modelm[1]*datam[0];
        Spx[2]-=modelm[2]*datam[0];
        Spx[3]-=modelm[0]*datam[1];
        Spx[4]-=modelm[1]*datam[1];
        Spx[5]-=modelm[2]*datam[1];
        Spx[6]-=modelm[0]*datam[2];
        Spx[7]-=modelm[1]*datam[2];
        Spx[8]-=modelm[2]*datam[2];
        
        datam[0]=datam[0]/quasum;
        datam[1]=datam[1]/quasum;
        datam[2]=datam[2]/quasum;
        
        k=1;
        if (ii==0){
            
            doubleVar=0.0;
            for (j=0;j<9;j++){
                doubleVar+=Spx[j]*Spx[j];
            }
            
            doubleVar=doubleVar/pwr2(quasum);
            
            /* Check if Spx is in too bad condition in the first ICP-iteration  */
            if (doubleVar<1e-4){
                k=0;
                translationVector[0]+=modelm[0]-datam[0];
                translationVector[1]+=modelm[1]-datam[1];
                translationVector[2]+=modelm[2]-datam[2];
                
                paramsOut[0]=0.0;
                paramsOut[1]=0.0;
                paramsOut[2]=0.0;
                paramsOut[3]=modelm[0]-datam[0];
                paramsOut[4]=modelm[1]-datam[1];
                paramsOut[5]=modelm[2]-datam[2];
                
                NewtonStepOLD[0]=0.0;
                NewtonStepOLD[1]=0.0;
                NewtonStepOLD[2]=0.0;
                NewtonStepOLD[3]=0.0;
                NewtonStepOLD[4]=0.0;
                NewtonStepOLD[5]=0.0;
            }
            
            paramsOutOLD[0]=0.0;
            paramsOutOLD[1]=0.0;
            paramsOutOLD[2]=0.0;
            paramsOutOLD[3]=0.0;
            paramsOutOLD[4]=0.0;
            paramsOutOLD[5]=0.0;
            
        }
        
        if (k){
            
            /* calculate R using [U,Sigma,V]=svd(Spx) */
            rotMatrixCCOV(tmpRotMat, Spx, SIGMA, MM, doubleVars);
            
            /* Get T=modelm-R*datam */
            tmpTranslVec[0]=modelm[0]-tmpRotMat[0]*datam[0]-tmpRotMat[3]*datam[1]-tmpRotMat[6]*datam[2];
            tmpTranslVec[1]=modelm[1]-tmpRotMat[1]*datam[0]-tmpRotMat[4]*datam[1]-tmpRotMat[7]*datam[2];
            tmpTranslVec[2]=modelm[2]-tmpRotMat[2]*datam[0]-tmpRotMat[5]*datam[1]-tmpRotMat[8]*datam[2];
            
            getAngles(paramsAst, tmpRotMat, doubleVars);
            
            /* If the rotation is too large (>pi/4), use point to plane minimization */
            if (fabs(paramsAst[0])>0.7854){
                k=0;
            }
            else if (fabs(paramsAst[1])>0.7854){
                k=0;
            }
            else if (fabs(paramsAst[2])>0.7854){
                k=0;
            }
            
            if (k){
                
                paramsAst[3]=tmpTranslVec[0];
                paramsAst[4]=tmpTranslVec[1];
                paramsAst[5]=tmpTranslVec[2];
                
                /* Find the Newton step */
                genzCGMinitiate(HessianLinApprx, gradientLinApprx, paramsAst, NewtonStep, doubleVars);
                
                regionValArray[1]=quasum;
                
                if (ii==0){
                    
                    constrainingFcnZero(doubleVars, &regionValArray[1], datam, modelm, Spx, &doubleVars[1]);
                    
                    regionValArray[0]=-doubleVars[0];
                    
                }
                else {
                    
                    doubleVars[0]=NewtonStepOLD[0]-paramsOut[0]-NewtonStep[0];
                    doubleVars[1]=NewtonStepOLD[1]-paramsOut[1]-NewtonStep[1];
                    doubleVars[2]=NewtonStepOLD[2]-paramsOut[2]-NewtonStep[2];
                    doubleVars[3]=NewtonStepOLD[3]-paramsOut[3]-NewtonStep[3];
                    doubleVars[4]=NewtonStepOLD[4]-paramsOut[4]-NewtonStep[4];
                    doubleVars[5]=NewtonStepOLD[5]-paramsOut[5]-NewtonStep[5];
                    
                    doubleVars[6]=sqrt(paramsOut[0]*paramsOut[0]+paramsOut[1]*paramsOut[1]+paramsOut[2]*paramsOut[2]+paramsOut[3]*paramsOut[3]+paramsOut[4]*paramsOut[4]+paramsOut[5]*paramsOut[5]);
                    
                    /* beta */
                    doubleVar=doubleVars[6]/(doubleVars[6]+sqrt(doubleVars[0]*doubleVars[0]+doubleVars[1]*doubleVars[1]+doubleVars[2]*doubleVars[2]+doubleVars[3]*doubleVars[3]+doubleVars[4]*doubleVars[4]+doubleVars[5]*doubleVars[5]));
                    
                    doubleVars[0]=paramsAst[0]+doubleVar*(NewtonStep[0]-paramsAst[0]);
                    doubleVars[1]=paramsAst[1]+doubleVar*(NewtonStep[1]-paramsAst[1]);
                    doubleVars[2]=paramsAst[2]+doubleVar*(NewtonStep[2]-paramsAst[2]);
                    doubleVars[3]=paramsAst[3]+doubleVar*(NewtonStep[3]-paramsAst[3]);
                    doubleVars[4]=paramsAst[4]+doubleVar*(NewtonStep[4]-paramsAst[4]);
                    doubleVars[5]=paramsAst[5]+doubleVar*(NewtonStep[5]-paramsAst[5]);
                    
                    constrainingFcn(&doubleVars[6], doubleVars, &regionValArray[1], datam, modelm, Spx, &doubleVars[8]);
                    
                    doubleVars[0]=paramsAst[0]-doubleVar*(paramsOutOLD[0]+paramsOut[0]+paramsAst[0]);
                    doubleVars[1]=paramsAst[1]-doubleVar*(paramsOutOLD[1]+paramsOut[1]+paramsAst[1]);
                    doubleVars[2]=paramsAst[2]-doubleVar*(paramsOutOLD[2]+paramsOut[2]+paramsAst[2]);
                    doubleVars[3]=paramsAst[3]-doubleVar*(paramsOutOLD[3]+paramsOut[3]+paramsAst[3]);
                    doubleVars[4]=paramsAst[4]-doubleVar*(paramsOutOLD[4]+paramsOut[4]+paramsAst[4]);
                    doubleVars[5]=paramsAst[5]-doubleVar*(paramsOutOLD[5]+paramsOut[5]+paramsAst[5]);
                    
                    constrainingFcn(&doubleVars[7], doubleVars, &regionValArray[1], datam, modelm, Spx, &doubleVars[8]);
                    
                    regionValArray[0]=-MAX(doubleVars[6],doubleVars[7]);
                    
                    /* Save parameters to the next iteration */
                    
                    paramsOutOLD[0]=paramsOut[0];
                    paramsOutOLD[1]=paramsOut[1];
                    paramsOutOLD[2]=paramsOut[2];
                    paramsOutOLD[3]=paramsOut[3];
                    paramsOutOLD[4]=paramsOut[4];
                    paramsOutOLD[5]=paramsOut[5];
                    
                }
                
                NewtonStepOLD[0]=NewtonStep[0];
                NewtonStepOLD[1]=NewtonStep[1];
                NewtonStepOLD[2]=NewtonStep[2];
                NewtonStepOLD[3]=NewtonStep[3];
                NewtonStepOLD[4]=NewtonStep[4];
                NewtonStepOLD[5]=NewtonStep[5];
                
                /* Find the update by solving a constrained minimization problem */
                trfRcprclBarrier(paramsOut, 10, paramsAst, gradientLinApprx, HessianLinApprx, NewtonStep, &regionValArray[1], datam, modelm, Spx, &regionValArray[0], doubleVars);
                
                /* Check to see if something is weird */
                if (fabs(paramsOut[0])>1.5){
                    k=0;
                }
                else if (paramsOut[0]!=paramsOut[0]){
                    k=0;
                }
                else if (fabs(paramsOut[1])>1.5){
                    k=0;
                }
                else if (paramsOut[1]!=paramsOut[1]){
                    k=0;
                }
                else if (fabs(paramsOut[2])>1.5){
                    k=0;
                }
                else if (paramsOut[2]!=paramsOut[2]){
                    k=0;
                }
                else if (fabs(paramsOut[3])>9.9e99){
                    k=0;
                }
                else if (paramsOut[3]!=paramsOut[3]){
                    k=0;
                }
                else if (fabs(paramsOut[4])>9.9e99){
                    k=0;
                }
                else if (paramsOut[4]!=paramsOut[4]){
                    k=0;
                }
                else if (fabs(paramsOut[5])>9.9e99){
                    k=0;
                }
                else if (paramsOut[5]!=paramsOut[5]){
                    k=0;
                }
                
                if (k){
                    
                    /* Nothing was weird */
                    
                    doubleVars[0]=paramsOut[0]-paramsAst[0];
                    doubleVars[1]=paramsOut[1]-paramsAst[1];
                    doubleVars[2]=paramsOut[2]-paramsAst[2];
                    
                    /* Scale the paramteters if some of the angles are too large (>pi/3) */
                    if (paramsOut[0]>1.0472){
                        doubleVar=(1.0472-paramsAst[0])/doubleVars[0];
                    }
                    else if (paramsOut[0]<-1.0472){
                        doubleVar=-(1.0472+paramsAst[0])/doubleVars[0];
                    }
                    else {
                        doubleVar=1.0;
                    }
                    
                    if (paramsOut[1]>1.0472){
                        doubleVar=MIN(doubleVar,(1.0472-paramsAst[1])/doubleVars[1]);
                    }
                    else if (paramsOut[1]<-1.0472){
                        doubleVar=MIN(doubleVar,-(1.0472+paramsAst[1])/doubleVars[1]);
                    }
                    
                    if (paramsOut[2]>1.0472){
                        doubleVar=MIN(doubleVar,(1.0472-paramsAst[2])/doubleVars[2]);
                    }
                    else if (paramsOut[2]<-1.0472){
                        doubleVar=MIN(doubleVar,-(1.0472+paramsAst[2])/doubleVars[2]);
                    }
                    
                    if (doubleVar<0.999){
                        paramsOut[0]=paramsAst[0]+doubleVar*doubleVars[0];
                        paramsOut[1]=paramsAst[1]+doubleVar*doubleVars[1];
                        paramsOut[2]=paramsAst[2]+doubleVar*doubleVars[2];
                        paramsOut[3]=paramsAst[3]+doubleVar*(paramsOut[3]-paramsAst[3]);
                        paramsOut[4]=paramsAst[4]+doubleVar*(paramsOut[4]-paramsAst[4]);
                        paramsOut[5]=paramsAst[5]+doubleVar*(paramsOut[5]-paramsAst[5]);
                    }
                    
                    /* Get the rotation matrix from the output parameters */
                    getRotMat(paramsOut, tmpRotMat, doubleVars);
                    
                    tmpTranslVec[0]=paramsOut[3];
                    tmpTranslVec[1]=paramsOut[4];
                    tmpTranslVec[2]=paramsOut[5];
                    
                }
                else {
                    
                    paramsOut[0]=paramsAst[0];
                    paramsOut[1]=paramsAst[1];
                    paramsOut[2]=paramsAst[2];
                    paramsOut[3]=paramsAst[3];
                    paramsOut[4]=paramsAst[4];
                    paramsOut[5]=paramsAst[5];
                    
                }
                
            }
            else {
                
                if (ii>0){
                    
                    /* Save parameters to the next iteration */
                    
                    paramsOutOLD[0]=paramsOut[0];
                    paramsOutOLD[1]=paramsOut[1];
                    paramsOutOLD[2]=paramsOut[2];
                    paramsOutOLD[3]=paramsOut[3];
                    paramsOutOLD[4]=paramsOut[4];
                    paramsOutOLD[5]=paramsOut[5];
                    
                }
                
                NewtonStepOLD[0]=0.0;
                NewtonStepOLD[1]=0.0;
                NewtonStepOLD[2]=0.0;
                NewtonStepOLD[3]=0.0;
                NewtonStepOLD[4]=0.0;
                NewtonStepOLD[5]=0.0;
                
                paramsOut[0]=paramsAst[0];
                paramsOut[1]=paramsAst[1];
                paramsOut[2]=paramsAst[2];
                paramsOut[3]=tmpTranslVec[0];
                paramsOut[4]=tmpTranslVec[1];
                paramsOut[5]=tmpTranslVec[2];
                
            }
            
            /* Update transformation */
            
            /* Translation */
            
            MM[0]=translationVector[0];
            MM[1]=translationVector[1];
            MM[2]=translationVector[2];
            
            translationVector[0]=tmpTranslVec[0]+tmpRotMat[0]*MM[0]+tmpRotMat[3]*MM[1]+tmpRotMat[6]*MM[2];
            translationVector[1]=tmpTranslVec[1]+tmpRotMat[1]*MM[0]+tmpRotMat[4]*MM[1]+tmpRotMat[7]*MM[2];
            translationVector[2]=tmpTranslVec[2]+tmpRotMat[2]*MM[0]+tmpRotMat[5]*MM[1]+tmpRotMat[8]*MM[2];
            
            /* Rotation */
            
            MM[0]=rotationMatrix[0];
            MM[1]=rotationMatrix[1];
            MM[2]=rotationMatrix[2];
            
            rotationMatrix[0]=tmpRotMat[0]*MM[0]+tmpRotMat[3]*MM[1]+tmpRotMat[6]*MM[2];
            rotationMatrix[1]=tmpRotMat[1]*MM[0]+tmpRotMat[4]*MM[1]+tmpRotMat[7]*MM[2];
            rotationMatrix[2]=tmpRotMat[2]*MM[0]+tmpRotMat[5]*MM[1]+tmpRotMat[8]*MM[2];
            
            MM[0]=rotationMatrix[3];
            MM[1]=rotationMatrix[4];
            MM[2]=rotationMatrix[5];
            
            rotationMatrix[3]=tmpRotMat[0]*MM[0]+tmpRotMat[3]*MM[1]+tmpRotMat[6]*MM[2];
            rotationMatrix[4]=tmpRotMat[1]*MM[0]+tmpRotMat[4]*MM[1]+tmpRotMat[7]*MM[2];
            rotationMatrix[5]=tmpRotMat[2]*MM[0]+tmpRotMat[5]*MM[1]+tmpRotMat[8]*MM[2];
            
            MM[0]=rotationMatrix[6];
            MM[1]=rotationMatrix[7];
            MM[2]=rotationMatrix[8];
            
            rotationMatrix[6]=tmpRotMat[0]*MM[0]+tmpRotMat[3]*MM[1]+tmpRotMat[6]*MM[2];
            rotationMatrix[7]=tmpRotMat[1]*MM[0]+tmpRotMat[4]*MM[1]+tmpRotMat[7]*MM[2];
            rotationMatrix[8]=tmpRotMat[2]*MM[0]+tmpRotMat[5]*MM[1]+tmpRotMat[8]*MM[2];
            
        }
        
        if (bol){
            numRndInIters+=rndIncrease;
            if (numRndInIters>=numDataPoints){
                bol=0;
            }
        }
        
    }
    
    free(Nvertex_1);
    free(NvertexSq);
    free(Nvertex_1xn);
    free(Nvertex_1xnxn);
    free(dNvertex);
    free(dNvertex_1);
    
    return;
    
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray*prhs[]){
    
    if (nrhs != 11){
        mexErrMsgTxt("11 input arguments are required");
    } else if (nlhs != 0) {
        mexErrMsgTxt("No output argument is allowed");
    }
    
    icpDVGpnt2plnTu(mxGetPr(data), mxGetPr(quality), (unsigned int)mxGetN(data), (unsigned int*)mxGetPr(randvec), (unsigned int)mxGetScalar(sizerand), (unsigned int)mxGetScalar(randincrease), (unsigned int)mxGetScalar(maxiter), mxGetScalar(kTukey), mxGetPr(surfdata), DVGdata, mxGetPr(rotationMatrixIO), mxGetPr(transVecIO));
    
    return;
    
}
