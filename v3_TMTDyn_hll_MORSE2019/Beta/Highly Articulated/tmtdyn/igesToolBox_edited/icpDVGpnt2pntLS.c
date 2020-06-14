/*=================================================================
 *
 * This is an implementation of the ICP method using a DVG-tree, [1], and point to point minimization.
 * Least squares minimization is used.
 *
 * Commpile in Matlab by running: mex -v icpDVGpnt2pntLS.c
 *
 * Usage:
 *
 * icpDVGpnt2pntLS(DATA,quality,quasirand,sizerand,randincreasing,maxiter,SURFDATA,DVGdata,R,t)
 *
 * Input:
 *
 * DATA - the data points
 * quality - a vector with quality values corresponding to DATA
 * quasirand - a vector with a pseudo random permumation of the indices of DATA
 * sizerand - size of the random subset of DATA which is used in the iterations
 * randincreasing - the increasing of sizerand in each iteration
 * maxiter - the number of ICP-iterations
 * SURFDATA - surface data (output from icpSrfLinRep)
 * DVGdata - the data structure (output from getDVGtree)
 *
 * Input/Output:
 *
 * R - rotation matrix
 * t - translation vector
 *
 * Written by Per Bergström 2013-08-19
 *
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
#define	surfdata	prhs[6]
#define	DVGdata	prhs[7]


/* Output Arguments */

#define	rotationMatrixIO	prhs[8]
#define	transVecIO     prhs[9]


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

/* Sub function (in folder "mexSourceFiles") */

#include "mexSourceFiles/rotMatrixCCOV.c"

/* Main function */

void icpDVGpnt2pntLS(
        double *dataPoints,
        double *qltyDataPoints,
        unsigned int numDataPoints,
        unsigned int *quasiRndNumbers,
        unsigned int numRndInIters,
        unsigned int rndIncrease,
        unsigned int ICP_iters,
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
    double dataTemp[3], dataOriginalTemp[3], tmpWgh;
    double datam[3], modelm[3], MM[3], Spx[9], quasum;
    double SIGMA[3], doubleVar, doubleVars[39];
    
    
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
        
        Spx[0]=0.0;
        Spx[1]=0.0;
        Spx[2]=0.0;
        Spx[3]=0.0;
        Spx[4]=0.0;
        Spx[5]=0.0;
        Spx[6]=0.0;
        Spx[7]=0.0;
        Spx[8]=0.0;
        
        modelm[0]=0.0;
        modelm[1]=0.0;
        modelm[2]=0.0;
        
        datam[0]=0.0;
        datam[1]=0.0;
        datam[2]=0.0;
        
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
                
                /* Mean values and cross covariance matrix, point to point correspondence */
                
                MM[0]=tmpWgh*MM[0];
                MM[1]=tmpWgh*MM[1];
                MM[2]=tmpWgh*MM[2];
                
                modelm[0]+=MM[0];
                modelm[1]+=MM[1];
                modelm[2]+=MM[2];
                
                datam[0]+=tmpWgh*dataOriginalTemp[0];
                datam[1]+=tmpWgh*dataOriginalTemp[1];
                datam[2]+=tmpWgh*dataOriginalTemp[2];
                
                /* Compute the outer product */
                Spx[0]+= MM[0]*dataOriginalTemp[0];
                Spx[1]+= MM[1]*dataOriginalTemp[0];
                Spx[2]+= MM[2]*dataOriginalTemp[0];
                Spx[3]+= MM[0]*dataOriginalTemp[1];
                Spx[4]+= MM[1]*dataOriginalTemp[1];
                Spx[5]+= MM[2]*dataOriginalTemp[1];
                Spx[6]+= MM[0]*dataOriginalTemp[2];
                Spx[7]+= MM[1]*dataOriginalTemp[2];
                Spx[8]+= MM[2]*dataOriginalTemp[2];
                
                quasum+=tmpWgh;
                
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
                translationVector[0]=modelm[0]-rotationMatrix[0]*datam[0]-rotationMatrix[3]*datam[1]-rotationMatrix[6]*datam[2];
                translationVector[1]=modelm[1]-rotationMatrix[1]*datam[0]-rotationMatrix[4]*datam[1]-rotationMatrix[7]*datam[2];
                translationVector[2]=modelm[2]-rotationMatrix[2]*datam[0]-rotationMatrix[5]*datam[1]-rotationMatrix[8]*datam[2];
            }
            
        }
        
        if (k){
            
            /* calculate R using [U,Sigma,V]=svd(Spx) */
            
            rotMatrixCCOV(rotationMatrix,Spx,SIGMA,MM,doubleVars);
            
            /* Get T=modelm-R*datam */
            
            translationVector[0]=modelm[0]-rotationMatrix[0]*datam[0]-rotationMatrix[3]*datam[1]-rotationMatrix[6]*datam[2];
            translationVector[1]=modelm[1]-rotationMatrix[1]*datam[0]-rotationMatrix[4]*datam[1]-rotationMatrix[7]*datam[2];
            translationVector[2]=modelm[2]-rotationMatrix[2]*datam[0]-rotationMatrix[5]*datam[1]-rotationMatrix[8]*datam[2];
            
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
    
    if (nrhs != 10){
        mexErrMsgTxt("10 input arguments are required");
    } else if (nlhs != 0) {
        mexErrMsgTxt("No output argument is allowed");
    }
    
    icpDVGpnt2pntLS(mxGetPr(data), mxGetPr(quality), (unsigned int)mxGetN(data), (unsigned int*)mxGetPr(randvec), (unsigned int)mxGetScalar(sizerand), (unsigned int)mxGetScalar(randincrease), (unsigned int)mxGetScalar(maxiter), mxGetPr(surfdata), DVGdata, mxGetPr(rotationMatrixIO), mxGetPr(transVecIO));
    
    return;
    
}
