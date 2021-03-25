/*=================================================================
 *
 * This code is developed for registration problems using
 * the ICP method. The compiled program creates a DVG tree [1].
 *
 * Commpile in Matlab by running: mex -v createDVGtree.c
 *
 * Written by Per Bergström 2012-03-02
 *
 * Reference
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
 *=================================================================*/


#include <math.h>
#include "mex.h"

/* Input Arguments */

#define	normal	prhs[0]
#define	pdir	prhs[1]
#define	sdir	prhs[2]
#define	P0	prhs[3]
#define	N0	prhs[4]
#define	gridSpacingL0	prhs[5]
#define	Nvertex	prhs[6]
#define	newGridsMaxDist	prhs[7]
#define	MODEL	prhs[8]
#define	DIRVEC	prhs[9]
#define	MINDIRsq	prhs[10]
#define	MNORMAL	prhs[11]
#define	Tes	prhs[12]

/* Output Arguments */

#define	DVGdata     plhs[0]


#if !defined(MAX)
#define	MAX(A, B)	((A) > (B) ? (A) : (B))
#endif

#if !defined(MIN)
#define	MIN(A, B)	((A) < (B) ? (A) : (B))
#endif


double pwr2(double a){
    return(a*a);
}


static void createDelaunaystruct(
        unsigned int *tesz,
        unsigned int mtesz,
        unsigned int *irz,
        unsigned int *jcz,
        unsigned int nmodelz
        ) {
    unsigned int *num, i;
    
    num=(unsigned int *)malloc(nmodelz*sizeof(unsigned int));
    
    for (i=0; i<nmodelz; i++) {
        num[i]=0;
    }
    
    for (i=0; i<(4*mtesz); i++) {
        num[tesz[i]]++;
    }
    
    /* cumsum */
    for (i=1; i<nmodelz; i++) {
        num[i]+=num[i-1];
    }
    
    jcz[0]=0;
    for (i=1; i<=nmodelz; i++) {
        jcz[i]=num[i-1];
        num[i-1]=jcz[i-1];
    }
    
    /* calculate ir */
    
    for (i=0; i<mtesz; i++) {
        irz[num[tesz[i]]]=i;
        num[tesz[i]]++;
        
        irz[num[tesz[i+mtesz]]]=i;
        num[tesz[i+mtesz]]++;
        
        irz[num[tesz[i+2*mtesz]]]=i;
        num[tesz[i+2*mtesz]]++;
        
        irz[num[tesz[i+3*mtesz]]]=i;
        num[tesz[i+3*mtesz]]++;
    }
    
    free(num);
    
}

static unsigned int createGridIndStruct(
        int *ispr,
        unsigned int n0,
        unsigned int n1,
        unsigned int n2,
        double *modelz,
        unsigned int nmodelz,
        unsigned int *tesz,
        unsigned int mtesz,
        unsigned int *irz,
        unsigned int *jcz,
        double *P0z,
        double *dz,
        double *normalz,
        double *pdirz,
        double *sdirz,
        int start,
        unsigned char treeLevel,
        unsigned char nT,
        double *dmin2,
        double *minRsq
        ) {
    
    unsigned int i, ii, j, jj, k, ijk, in, ind, threeind, nn, myint1, myint2, fourmtesz;
    double distc, distcc, Ptemp[3];
    unsigned short int bol=1;
    int indL, indU;
    
    
    nn=n0*n1;
    fourmtesz=4*mtesz;
    
    if (treeLevel==0){
        
        ispr[0]=0;
        distc=pwr2(P0z[0]-modelz[0])+pwr2(P0z[1]-modelz[1])+pwr2(P0z[2]-modelz[2]);
        
        myint1=(unsigned int)ceil(0.5*sqrt((double)nmodelz));
        myint2=(unsigned int)(((double)nmodelz)/((double)myint1));
        in=3*myint1;
        ind=0;
        
        for (i=1; i<myint2; i++) {
            ind+=in;
            distcc=pwr2(P0z[0]-modelz[ind])+pwr2(P0z[1]-modelz[ind+1])+pwr2(P0z[2]-modelz[ind+2]);
            if (distcc<distc){
                distc=distcc;
                ispr[0]=myint1*i;
            }
        }
        
    }
    else {
        
        ispr[0]=start;
        distc=pwr2(P0z[0]-modelz[3*ispr[0]])+pwr2(P0z[1]-modelz[3*ispr[0]+1])+pwr2(P0z[2]-modelz[3*ispr[0]+2]);
        
    }
    
    while (bol){
        bol=0;
        for (i=jcz[ispr[0]];i<jcz[ispr[0]+1];i++){
            in=irz[i];
            for (j=0;j<fourmtesz;j+=mtesz){
                ind=tesz[j+in];
                threeind=3*ind;
                distcc=pwr2(P0z[0]-modelz[threeind])+pwr2(P0z[1]-modelz[threeind+1])+pwr2(P0z[2]-modelz[threeind+2]);
                if (distcc<distc){
                    distc=distcc;
                    ispr[0]=ind;
                    bol=1;
                    break;
                }
            }
            if (bol){
                break;
            }
        }
    }
    
    for (k=1;k<n0;k++){
        
        Ptemp[0]=P0z[0]+k*dz[0]*normalz[0];
        Ptemp[1]=P0z[1]+k*dz[0]*normalz[1];
        Ptemp[2]=P0z[2]+k*dz[0]*normalz[2];
        
        ispr[k]=ispr[k-1];
        distc=pwr2(Ptemp[0]-modelz[3*ispr[k]])+pwr2(Ptemp[1]-modelz[3*ispr[k]+1])+pwr2(Ptemp[2]-modelz[3*ispr[k]+2]);
        
        bol=1;
        
        while (bol){
            bol=0;
            for (i=jcz[ispr[k]];i<jcz[ispr[k]+1];i++){
                in=irz[i];
                for (j=0;j<fourmtesz;j+=mtesz){
                    ind=tesz[j+in];
                    threeind=3*ind;
                    distcc=pwr2(Ptemp[0]-modelz[threeind])+pwr2(Ptemp[1]-modelz[threeind+1])+pwr2(Ptemp[2]-modelz[threeind+2]);
                    if (distcc<distc){
                        distc=distcc;
                        ispr[k]=ind;
                        bol=1;
                        break;
                    }
                }
                if (bol){
                    break;
                }
            }
        }
        
    }
    
    myint2=n0;
    
    for (ii=1;ii<n1;ii++){
        
        for (k=0;k<n0;k++){
            
            Ptemp[0]=P0z[0]+dz[0]*(k*normalz[0]+ii*pdirz[0]);
            Ptemp[1]=P0z[1]+dz[0]*(k*normalz[1]+ii*pdirz[1]);
            Ptemp[2]=P0z[2]+dz[0]*(k*normalz[2]+ii*pdirz[2]);
            
            ijk=k+myint2;
            ispr[ijk]=ispr[ijk-n0];
            
            distc=pwr2(Ptemp[0]-modelz[3*ispr[ijk]])+pwr2(Ptemp[1]-modelz[3*ispr[ijk]+1])+pwr2(Ptemp[2]-modelz[3*ispr[ijk]+2]);
            
            bol=1;
            
            while (bol){
                bol=0;
                for (i=jcz[ispr[ijk]];i<jcz[ispr[ijk]+1];i++){
                    in=irz[i];
                    for (j=0;j<fourmtesz;j+=mtesz){
                        ind=tesz[j+in];
                        threeind=3*ind;
                        distcc=pwr2(Ptemp[0]-modelz[threeind])+pwr2(Ptemp[1]-modelz[threeind+1])+pwr2(Ptemp[2]-modelz[threeind+2]);
                        if (distcc<distc){
                            distc=distcc;
                            ispr[ijk]=ind;
                            bol=1;
                            break;
                        }
                    }
                    if (bol){
                        break;
                    }
                }
            }
        }
        
        myint2+=n0;
        
    }
    
    myint1=nn;
    
    for (jj=1;jj<n2;jj++){
        
        myint2=myint1;
        
        for (ii=0;ii<n1;ii++){
            
            for (k=0;k<n0;k++){
                
                Ptemp[0]=P0z[0]+dz[0]*(k*normalz[0]+ii*pdirz[0]+jj*sdirz[0]);
                Ptemp[1]=P0z[1]+dz[0]*(k*normalz[1]+ii*pdirz[1]+jj*sdirz[1]);
                Ptemp[2]=P0z[2]+dz[0]*(k*normalz[2]+ii*pdirz[2]+jj*sdirz[2]);
                
                ijk=k+myint2;
                ispr[ijk]=ispr[ijk-nn];
                
                distc=pwr2(Ptemp[0]-modelz[3*ispr[ijk]])+pwr2(Ptemp[1]-modelz[3*ispr[ijk]+1])+pwr2(Ptemp[2]-modelz[3*ispr[ijk]+2]);
                
                bol=1;
                
                while (bol){
                    bol=0;
                    for (i=jcz[ispr[ijk]];i<jcz[ispr[ijk]+1];i++){
                        in=irz[i];
                        for (j=0;j<fourmtesz;j+=mtesz){
                            ind=tesz[j+in];
                            threeind=3*ind;
                            distcc=pwr2(Ptemp[0]-modelz[threeind])+pwr2(Ptemp[1]-modelz[threeind+1])+pwr2(Ptemp[2]-modelz[threeind+2]);
                            if (distcc<distc){
                                distc=distcc;
                                ispr[ijk]=ind;
                                bol=1;
                                break;
                            }
                        }
                        if (bol){
                            break;
                        }
                    }
                }
                
            }
            
            myint2+=n0;
            
        }
        
        myint1+=nn;
        
    }
    
    if (treeLevel==nT || dmin2[0]==0.0){
        return(0);
    }
    else{
        
        distc=pwr2(dz[0]);
        
        in=0;
        myint1=0;
        
        for (jj=0;jj<n2;jj++){
            
            myint2=myint1;
            
            for (ii=0;ii<n1;ii++){
                
                for (k=0;k<n0;k++){
                    
                    Ptemp[0]=P0z[0]+dz[0]*(k*normalz[0]+ii*pdirz[0]+jj*sdirz[0]);
                    Ptemp[1]=P0z[1]+dz[0]*(k*normalz[1]+ii*pdirz[1]+jj*sdirz[1]);
                    Ptemp[2]=P0z[2]+dz[0]*(k*normalz[2]+ii*pdirz[2]+jj*sdirz[2]);
                    
                    ijk=k+myint2;
                    ind=3*ispr[ijk];
                    distcc=pwr2(Ptemp[0]-modelz[ind])+pwr2(Ptemp[1]-modelz[ind+1])+pwr2(Ptemp[2]-modelz[ind+2]);
                    
                    if (distcc<dmin2[0]){
                        
                        distcc=minRsq[ispr[ijk]];
                        
                        if (distcc<distc){
                            ispr[ijk]=-ispr[ijk]-1;
                            in++;
                        }
                        
                        else{
                            
                            if ((jj>0)&&(jj<(n2-1))){
                                indL=3*ispr[ijk-nn];
                                indU=3*ispr[ijk+nn];
                                if (indL<0){
                                    indL=-indL-3;
                                }
                                if (indU<0){
                                    indU=-indU-3;
                                }
                                distcc=pwr2(modelz[indL]-modelz[indU])+pwr2(modelz[indL+1]-modelz[indU+1])+pwr2(modelz[indL+2]-modelz[indU+2]);
                            }
                            if ((ii>0)&&(ii<(n1-1))){
                                indL=3*ispr[ijk-n0];
                                indU=3*ispr[ijk+n0];
                                if (indL<0){
                                    indL=-indL-3;
                                }
                                if (indU<0){
                                    indU=-indU-3;
                                }
                                distcc=MAX(pwr2(modelz[indL]-modelz[indU])+pwr2(modelz[indL+1]-modelz[indU+1])+pwr2(modelz[indL+2]-modelz[indU+2]), distcc);
                            }
                            if ((k>0)&&(k<(n0-1))){
                                indL=3*ispr[ijk-1];
                                indU=3*ispr[ijk+1];
                                if (indL<0){
                                    indL=-indL-3;
                                }
                                if (indU<0){
                                    indU=-indU-3;
                                }
                                distcc=MAX(pwr2(modelz[indL]-modelz[indU])+pwr2(modelz[indL+1]-modelz[indU+1])+pwr2(modelz[indL+2]-modelz[indU+2]), distcc);
                            }
                            
                            if (distcc>12*distc){
                                ispr[ijk]=-ispr[ijk]-1;
                                in++;
                            }
                            
                        }
                        
                    }
                    
                }
                
                myint2+=n0;
                
            }
            
            myint1+=nn;
            
        }
        
        return(in);
        
    }
    
}

static unsigned int  createGridIndSystem(
        unsigned int treeLevel,
        unsigned int recursiveInd,
        int start,
        unsigned int *couGrds,
        mxArray *DVGtree,
        unsigned int *N0vertex,
        unsigned int *Nlvertex,
        unsigned char nT,
        double *P0z,
        double *dz,
        double *childGridsMaxDist,
        double *normalz,
        double *pdirz,
        double *sdirz,
        double *modelz,
        unsigned int nmodelz,
        double *minRsq,
        unsigned int *tesz,
        unsigned int mtesz,
        unsigned int *irz,
        unsigned int *jcz
        ) {
    unsigned int i, j, k, cou, n, nn, myuint, myuint2;
    double Ptemp[3], ddiff, ddz[1];
    double mydouble1, mydouble2, mydouble3;
    int *ispr, *isprChld, isprInd, ind, nnn;
    
    
    if (treeLevel==0){
        
        cou=createGridIndStruct((int *)mxGetPr(mxGetCell(DVGtree,5)), N0vertex[0], N0vertex[1], N0vertex[2], modelz, nmodelz, tesz, mtesz, irz, jcz, P0z, dz, normalz, pdirz, sdirz, 0, 0, nT, childGridsMaxDist, minRsq);
        
    }
    else if (treeLevel==1){
        
        ispr=(int *)mxGetPr(mxGetCell(DVGtree,5));
        isprChld=(int *)mxGetPr(mxGetCell(DVGtree,6));
        
        nn=N0vertex[0]*N0vertex[1];
        nnn=(int)Nlvertex[0]*Nlvertex[0]*Nlvertex[0];
        
        cou=0;
        ind=0;
        
        ddz[0]=dz[0]/((double)Nlvertex[0]);
        ddiff=0.5*(dz[0]-ddz[0]);
        
        myuint=0;
        mydouble3=-ddiff;
        
        for (i=0;i<N0vertex[2];i++){
            
            myuint2=myuint;
            mydouble2=-ddiff;
            
            for (j=0;j<N0vertex[1];j++){
                
                for (k=0;k<N0vertex[0];k++){
                    
                    isprInd=ispr[myuint2+k];
                    
                    if (isprInd<0){
                        
                        mydouble1=k*dz[0]-ddiff;
                        
                        Ptemp[0]=P0z[0]+mydouble1*normalz[0]+mydouble2*pdirz[0]+mydouble3*sdirz[0];
                        Ptemp[1]=P0z[1]+mydouble1*normalz[1]+mydouble2*pdirz[1]+mydouble3*sdirz[1];
                        Ptemp[2]=P0z[2]+mydouble1*normalz[2]+mydouble2*pdirz[2]+mydouble3*sdirz[2];
                        
                        cou+=createGridIndStruct(&isprChld[ind], Nlvertex[0], Nlvertex[0], Nlvertex[0], modelz, nmodelz, tesz, mtesz, irz, jcz, &Ptemp[0], &ddz[0], normalz, pdirz, sdirz, -isprInd-1, 1, nT, childGridsMaxDist, minRsq);
                        ispr[myuint2+k]=-ind-1;
                        ind+=nnn;
                        
                    }
                    
                }
                
                myuint2+=N0vertex[0];
                mydouble2+=dz[0];
                
            }
            
            myuint+=nn;
            mydouble3+=dz[0];
            
        }
        
    }
    else if (treeLevel==(recursiveInd+1)){

        ispr=(int *)mxGetPr(mxGetCell(DVGtree,4+treeLevel));
        isprChld=(int *)mxGetPr(mxGetCell(DVGtree,5+treeLevel));
        
        n=Nlvertex[recursiveInd-1];
        nn=n*n;
        nnn=(int)Nlvertex[recursiveInd]*Nlvertex[recursiveInd]*Nlvertex[recursiveInd];
        
        cou=0;
        ind=couGrds[0];
        
        ddz[0]=dz[0]/((double)Nlvertex[recursiveInd]);
        ddiff=0.5*(dz[0]-ddz[0]);
        
        myuint=(unsigned int)start;
        mydouble3=-ddiff;

        for (i=0;i<n;i++){
            
            myuint2=myuint;
            mydouble2=-ddiff;
            
            for (j=0;j<n;j++){
                
                for (k=0;k<n;k++){
                    
                    isprInd=ispr[myuint2+k];
                    
                    if (isprInd<0){
                        
                        mydouble1=k*dz[0]-ddiff;
                        
                        Ptemp[0]=P0z[0]+mydouble1*normalz[0]+mydouble2*pdirz[0]+mydouble3*sdirz[0];
                        Ptemp[1]=P0z[1]+mydouble1*normalz[1]+mydouble2*pdirz[1]+mydouble3*sdirz[1];
                        Ptemp[2]=P0z[2]+mydouble1*normalz[2]+mydouble2*pdirz[2]+mydouble3*sdirz[2];

                        cou+=createGridIndStruct(&isprChld[ind], Nlvertex[recursiveInd], Nlvertex[recursiveInd], Nlvertex[recursiveInd], modelz, nmodelz, tesz, mtesz, irz, jcz, &Ptemp[0], &ddz[0], normalz, pdirz, sdirz, -isprInd-1, treeLevel, nT, childGridsMaxDist, minRsq);
                        ispr[myuint2+k]=-ind-1;
                        ind+=nnn;
                        
                    }
                    
                }
                
                myuint2+=n;
                mydouble2+=dz[0];
                
            }
            
            myuint+=nn;
            mydouble3+=dz[0];
            
        }
        
        couGrds[0]=ind;
        
    }
    else if (recursiveInd==0){
       
        ispr=(int *)mxGetPr(mxGetCell(DVGtree,5));
        
        nn=N0vertex[0]*N0vertex[1];
        
        cou=0;
        couGrds[0]=0;
        
        ddz[0]=dz[0]/((double)Nlvertex[0]);
        ddiff=0.5*(dz[0]-ddz[0]);
        
        myuint=0;
        mydouble3=-ddiff;
        
        for (i=0;i<N0vertex[2];i++){
            
            myuint2=myuint;
            mydouble2=-ddiff;
            
            for (j=0;j<N0vertex[1];j++){
                
                for (k=0;k<N0vertex[0];k++){
                    
                    isprInd=ispr[myuint2+k];
                    
                    if (isprInd<0){
                        
                        mydouble1=k*dz[0]-ddiff;
                        
                        Ptemp[0]=P0z[0]+mydouble1*normalz[0]+mydouble2*pdirz[0]+mydouble3*sdirz[0];
                        Ptemp[1]=P0z[1]+mydouble1*normalz[1]+mydouble2*pdirz[1]+mydouble3*sdirz[1];
                        Ptemp[2]=P0z[2]+mydouble1*normalz[2]+mydouble2*pdirz[2]+mydouble3*sdirz[2];
                        
                        cou+=createGridIndSystem(treeLevel, recursiveInd+1, -isprInd-1, couGrds, DVGtree, N0vertex, Nlvertex, nT, &Ptemp[0], &ddz[0], childGridsMaxDist, normalz, pdirz, sdirz, modelz, nmodelz, minRsq, tesz, mtesz, irz, jcz);
                        
                    }
                    
                }
                
                myuint2+=N0vertex[0];
                mydouble2+=dz[0];
                
            }
            
            myuint+=nn;
            mydouble3+=dz[0];
            
        }
        
    }
    else {
        
        ispr=(int *)mxGetPr(mxGetCell(DVGtree,5+recursiveInd));
        
        n=Nlvertex[recursiveInd-1];
        nn=n*n;
        
        cou=0;
        
        ddz[0]=dz[0]/((double)Nlvertex[recursiveInd]);
        ddiff=0.5*(dz[0]-ddz[0]);
        
        myuint=(unsigned int)start;
        mydouble3=-ddiff;
        
        for (i=0;i<n;i++){
            
            myuint2=myuint;
            mydouble2=-ddiff;
            
            for (j=0;j<n;j++){
                
                for (k=0;k<n;k++){
                    
                    isprInd=ispr[myuint2+k];
                    
                    if (isprInd<0){
                        
                        mydouble1=k*dz[0]-ddiff;
                        
                        Ptemp[0]=P0z[0]+mydouble1*normalz[0]+mydouble2*pdirz[0]+mydouble3*sdirz[0];
                        Ptemp[1]=P0z[1]+mydouble1*normalz[1]+mydouble2*pdirz[1]+mydouble3*sdirz[1];
                        Ptemp[2]=P0z[2]+mydouble1*normalz[2]+mydouble2*pdirz[2]+mydouble3*sdirz[2];
                        
                        cou+=createGridIndSystem(treeLevel, recursiveInd+1, -isprInd-1, couGrds, DVGtree, N0vertex, Nlvertex, nT, &Ptemp[0], &ddz[0], childGridsMaxDist, normalz, pdirz, sdirz, modelz, nmodelz, minRsq, tesz, mtesz, irz, jcz);
                        
                    }
                    
                }
                
                myuint2+=n;
                mydouble2+=dz[0];
                
            }
            
            myuint+=nn;
            mydouble3+=dz[0];
            
        }
        
    }
    
    return(cou);
    
}


static unsigned int  allocGridngDVGtree(
        mxArray *DVGtree,
        unsigned int *N0vertex,
        unsigned int *Nlvertex,
        unsigned char nT,
        double *P0z,
        double *dz,
        double *newGrdsMaxDist,
        double *normalz,
        double *pdirz,
        double *sdirz,
        double *modelz,
        unsigned int nmodelz,
        double *minRsq,
        unsigned int *tesz,
        unsigned int mtesz,
        unsigned int *irz,
        unsigned int *jcz
        ) {
    unsigned int treeLevel, nTret, cou=1, couGrds[1];
    
    
    nTret=(unsigned int)nT;
    
    mxSetCell(DVGtree,5,mxCreateNumericMatrix(1, N0vertex[0]*N0vertex[1]*N0vertex[2], mxINT32_CLASS, mxREAL));
    
    for (treeLevel=0;treeLevel<nT;treeLevel++){
        
        if (cou>0){
            cou=createGridIndSystem(treeLevel, 0, 0, &couGrds[0], DVGtree, N0vertex, Nlvertex, nT, P0z, dz, &newGrdsMaxDist[treeLevel], normalz, pdirz, sdirz, modelz, nmodelz, minRsq, tesz, mtesz, irz, jcz);
            if (cou==0){
                nTret=treeLevel;
                mxSetCell(DVGtree,6+treeLevel,mxCreateNumericMatrix(1, 0, mxINT32_CLASS, mxREAL));
            }
            else{
                mxSetCell(DVGtree,6+treeLevel,mxCreateNumericMatrix(1, cou*Nlvertex[treeLevel]*Nlvertex[treeLevel]*Nlvertex[treeLevel], mxINT32_CLASS, mxREAL));
            }
        }
        else {
            mxSetCell(DVGtree,6+treeLevel,mxCreateNumericMatrix(1, 0, mxINT32_CLASS, mxREAL));
        }
        
    }
    if (nTret==nT){
        createGridIndSystem(nT, 0, 0, &couGrds[0], DVGtree, N0vertex, Nlvertex, nT, P0z, dz, &newGrdsMaxDist[0], normalz, pdirz, sdirz, modelz, nmodelz, minRsq, tesz, mtesz, irz, jcz);
    }
    
    return(nTret);
    
}


void mexFunction( int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]){
    unsigned char nT;
    unsigned int cou, n00, n01, n02, *ir, *jc, nTret;
    double gridSpc0, *grdMaxDist;
    
    if (nrhs != 13) {
        mexErrMsgTxt("13 input arguments are required");
    }
    else if (nlhs != 1) {
        mexErrMsgTxt("1 output argument is required");
    }
    
    
    /* Create the DVG data structure */
    
    nT=(unsigned char)(mxGetM(Nvertex)*mxGetN(Nvertex));
    gridSpc0=mxGetScalar(gridSpacingL0);
    n00=(unsigned int)mxGetPr(N0)[0];
    n01=(unsigned int)mxGetPr(N0)[1];
    n02=(unsigned int)mxGetPr(N0)[2];
    
    if (nT != mxGetM(newGridsMaxDist)*mxGetN(newGridsMaxDist)) {
        mexErrMsgTxt("Nvertex and newGridsMaxDist must have the same size");
    }
    
    DVGdata = mxCreateCellMatrix(1,6+nT);
    
    mxSetCell(DVGdata,0,mxCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL));
    
    mxSetCell(DVGdata,1,mxCreateDoubleMatrix(3, 4, mxREAL));
    
    /* Reference point */
    mxGetPr(mxGetCell(DVGdata,1))[0]=mxGetPr(P0)[0]-0.5*gridSpc0*(mxGetPr(normal)[0]+mxGetPr(pdir)[0]+mxGetPr(sdir)[0]);
    mxGetPr(mxGetCell(DVGdata,1))[1]=mxGetPr(P0)[1]-0.5*gridSpc0*(mxGetPr(normal)[1]+mxGetPr(pdir)[1]+mxGetPr(sdir)[1]);
    mxGetPr(mxGetCell(DVGdata,1))[2]=mxGetPr(P0)[2]-0.5*gridSpc0*(mxGetPr(normal)[2]+mxGetPr(pdir)[2]+mxGetPr(sdir)[2]);
    
    /* Normal direction */
    mxGetPr(mxGetCell(DVGdata,1))[3]=mxGetPr(normal)[0];
    mxGetPr(mxGetCell(DVGdata,1))[4]=mxGetPr(normal)[1];
    mxGetPr(mxGetCell(DVGdata,1))[5]=mxGetPr(normal)[2];
    
    /* Primary direction */
    mxGetPr(mxGetCell(DVGdata,1))[6]=mxGetPr(pdir)[0];
    mxGetPr(mxGetCell(DVGdata,1))[7]=mxGetPr(pdir)[1];
    mxGetPr(mxGetCell(DVGdata,1))[8]=mxGetPr(pdir)[2];
    
    /* Secondary direction */
    mxGetPr(mxGetCell(DVGdata,1))[9]=mxGetPr(sdir)[0];
    mxGetPr(mxGetCell(DVGdata,1))[10]=mxGetPr(sdir)[1];
    mxGetPr(mxGetCell(DVGdata,1))[11]=mxGetPr(sdir)[2];    
    
    mxSetCell(DVGdata,2,mxCreateNumericMatrix(3, 1, mxUINT32_CLASS, mxREAL));
    
    ir=(unsigned int *)mxGetPr(mxGetCell(DVGdata,2));
    
    ir[0]=n00;
    ir[1]=n01;
    ir[2]=n02;
    
    mxSetCell(DVGdata,3,mxCreateDoubleMatrix(1, 1, mxREAL));
    
    mxGetPr(mxGetCell(DVGdata,3))[0]=gridSpc0;
    
    grdMaxDist=(double *)malloc(nT*sizeof(double));
    
    mxSetCell(DVGdata,4,mxCreateNumericMatrix(1, nT, mxUINT32_CLASS, mxREAL));
    
    ir=(unsigned int *)mxGetPr(mxGetCell(DVGdata,4));
    
    for (cou=0;cou<nT;cou++){
        ir[cou]=(unsigned int)mxGetPr(Nvertex)[cou];
        grdMaxDist[cou]=pwr2(mxGetPr(newGridsMaxDist)[cou]);
    }
    
    
    /* Create the Delaunay data structure */
    
    jc=(unsigned int *)malloc((mxGetN(MODEL)+1)*sizeof(unsigned int));
    ir=(unsigned int *)malloc(4*mxGetM(Tes)*sizeof(unsigned int));
    
    createDelaunaystruct((unsigned int *)mxGetPr(Tes), (unsigned int)mxGetM(Tes), ir, jc, (unsigned int)mxGetN(MODEL));
    
    /* Create the grid systems */
    
    nTret=allocGridngDVGtree(DVGdata, (unsigned int *)mxGetPr(mxGetCell(DVGdata,2)), (unsigned int *)mxGetPr(mxGetCell(DVGdata,4)), nT, mxGetPr(P0), mxGetPr(gridSpacingL0), grdMaxDist, mxGetPr(normal), mxGetPr(pdir), mxGetPr(sdir), mxGetPr(MODEL), (unsigned int)mxGetN(MODEL), mxGetPr(MINDIRsq), (unsigned int *)mxGetPr(Tes), (unsigned int)mxGetM(Tes), ir, jc);
    
    
    free(ir);
    free(jc);
    free(grdMaxDist);
    
    ir=(unsigned int *)mxGetPr(mxGetCell(DVGdata,0));
    
    ir[0]=nTret;
    
    return;
    
}
