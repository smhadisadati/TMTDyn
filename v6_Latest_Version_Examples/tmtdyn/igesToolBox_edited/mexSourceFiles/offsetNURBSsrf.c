
/* Written by Per Bergström */

static void nrbSrfDerivative(int degU, int degV, int ncp, int kcp, double *cp, double *knotU, double *knotV, double *ducp, double *duknotU, double *duknotV, double *dvcp, double *dvknotV, double *duucp, double *duvcp, double *dvvcp){
    
    unsigned short int i, j, fourncp, fourncpD;
    double doubleVal;
    
    fourncp=4*ncp;
    fourncpD=fourncp-4;
    
    /* first derivatives */
    
    if (degU>0){
        
        /* u-derivative */
        
        for (j = 0; j < (ncp-1); j++){
            if ((knotU[j+degU+1]-knotU[j+1])>1e-12){
                doubleVal=((double)(degU))/(knotU[j+degU+1]-knotU[j+1]);
                for (i = 0; i < kcp; i++){
                    ducp[i*fourncpD+4*j]=doubleVal*(cp[i*fourncp+4*(j+1)]-cp[i*fourncp+4*j]);
                    ducp[i*fourncpD+4*j+1]=doubleVal*(cp[i*fourncp+4*(j+1)+1]-cp[i*fourncp+4*j+1]);
                    ducp[i*fourncpD+4*j+2]=doubleVal*(cp[i*fourncp+4*(j+1)+2]-cp[i*fourncp+4*j+2]);
                    ducp[i*fourncpD+4*j+3]=doubleVal*(cp[i*fourncp+4*(j+1)+3]-cp[i*fourncp+4*j+3]);
                }
            }
            else {
                for (i = 0; i < kcp; i++){
                    ducp[i*fourncpD+4*j]=0.0;
                    ducp[i*fourncpD+4*j+1]=0.0;
                    ducp[i*fourncpD+4*j+2]=0.0;
                    ducp[i*fourncpD+4*j+3]=0.0;
                }
            }
        }
        
    }
    
    if (degV>0){
        
        /* v-derivative */
        
        for (i = 0; i < (kcp-1); i++){
            if ((knotV[i+degV+1]-knotV[i+1])>1e-12){
                doubleVal=((double)(degV))/(knotV[i+degV+1]-knotV[i+1]);
                for (j = 0; j < ncp; j++){
                    dvcp[i*fourncp+4*j]=doubleVal*(cp[i*fourncp+fourncp+4*j]-cp[i*fourncp+4*j]);
                    dvcp[i*fourncp+4*j+1]=doubleVal*(cp[i*fourncp+fourncp+4*j+1]-cp[i*fourncp+4*j+1]);
                    dvcp[i*fourncp+4*j+2]=doubleVal*(cp[i*fourncp+fourncp+4*j+2]-cp[i*fourncp+4*j+2]);
                    dvcp[i*fourncp+4*j+3]=doubleVal*(cp[i*fourncp+fourncp+4*j+3]-cp[i*fourncp+4*j+3]);
                }
            }
            else {
                for (j = 0; j < ncp; j++){
                    dvcp[i*fourncp+4*j]=0.0;
                    dvcp[i*fourncp+4*j+1]=0.0;
                    dvcp[i*fourncp+4*j+2]=0.0;
                    dvcp[i*fourncp+4*j+3]=0.0;
                }
            }
        }
        
    }
    
    fourncp-=4;
    fourncpD-=4;
    
    /* second derivatives */
    
    if (degU>1){
        
        /* uu-derivative */
        
        for (j = 0; j < (ncp-2); j++){
            if ((duknotU[j+degU]-duknotU[j+1])>1e-12){
                doubleVal=((double)(degU-1))/(duknotU[j+degU]-duknotU[j+1]);
                for (i = 0; i < kcp; i++){
                    duucp[i*fourncpD+4*j]=doubleVal*(ducp[i*fourncp+4*(j+1)]-ducp[i*fourncp+4*j]);
                    duucp[i*fourncpD+4*j+1]=doubleVal*(ducp[i*fourncp+4*(j+1)+1]-ducp[i*fourncp+4*j+1]);
                    duucp[i*fourncpD+4*j+2]=doubleVal*(ducp[i*fourncp+4*(j+1)+2]-ducp[i*fourncp+4*j+2]);
                    duucp[i*fourncpD+4*j+3]=doubleVal*(ducp[i*fourncp+4*(j+1)+3]-ducp[i*fourncp+4*j+3]);
                }
            }
            else {
                for (i = 0; i < kcp; i++){
                    duucp[i*fourncpD+4*j]=0.0;
                    duucp[i*fourncpD+4*j+1]=0.0;
                    duucp[i*fourncpD+4*j+2]=0.0;
                    duucp[i*fourncpD+4*j+3]=0.0;
                }
            }
        }
        
    }
    
    if (degU>0 && degV>0){
        
        /* uv-derivative */
        
        for (i = 0; i < (kcp-1); i++){
            if ((duknotV[i+degV+1]-duknotV[i+1])>1e-12){
                doubleVal=((double)(degV))/(duknotV[i+degV+1]-duknotV[i+1]);
                for (j = 0; j < (ncp-1); j++){
                    duvcp[i*fourncp+4*j]=doubleVal*(ducp[i*fourncp+fourncp+4*j]-ducp[i*fourncp+4*j]);
                    duvcp[i*fourncp+4*j+1]=doubleVal*(ducp[i*fourncp+fourncp+4*j+1]-ducp[i*fourncp+4*j+1]);
                    duvcp[i*fourncp+4*j+2]=doubleVal*(ducp[i*fourncp+fourncp+4*j+2]-ducp[i*fourncp+4*j+2]);
                    duvcp[i*fourncp+4*j+3]=doubleVal*(ducp[i*fourncp+fourncp+4*j+3]-ducp[i*fourncp+4*j+3]);
                }
            }
            else {
                for (j = 0; j < (ncp-1); j++){
                    duvcp[i*fourncp+4*j]=0.0;
                    duvcp[i*fourncp+4*j+1]=0.0;
                    duvcp[i*fourncp+4*j+2]=0.0;
                    duvcp[i*fourncp+4*j+3]=0.0;
                }
            }
        }
        
    }
    
    fourncp+=4;
    
    if (degV>1){
        
        /* vv-derivative */
        
        for (i = 0; i < (kcp-2); i++){
            if ((dvknotV[i+degV]-dvknotV[i+1])>1e-12){
                doubleVal=((double)(degV-1))/(dvknotV[i+degV]-dvknotV[i+1]);
                for (j = 0; j < ncp; j++){
                    dvvcp[i*fourncp+4*j]=doubleVal*(dvcp[i*fourncp+fourncp+4*j]-dvcp[i*fourncp+4*j]);
                    dvvcp[i*fourncp+4*j+1]=doubleVal*(dvcp[i*fourncp+fourncp+4*j+1]-dvcp[i*fourncp+4*j+1]);
                    dvvcp[i*fourncp+4*j+2]=doubleVal*(dvcp[i*fourncp+fourncp+4*j+2]-dvcp[i*fourncp+4*j+2]);
                    dvvcp[i*fourncp+4*j+3]=doubleVal*(dvcp[i*fourncp+fourncp+4*j+3]-dvcp[i*fourncp+4*j+3]);
                }
            }
            else {
                for (j = 0; j < ncp; j++){
                    dvvcp[i*fourncp+4*j]=0.0;
                    dvvcp[i*fourncp+4*j+1]=0.0;
                    dvvcp[i*fourncp+4*j+2]=0.0;
                    dvvcp[i*fourncp+4*j+3]=0.0;
                }
            }
        }
        
    }
    
}

static void findNURBSbasisFunU(int jj, int iters, double *us, double oldFunVal, double stepU, int degU, double *cp, int ncp, double *knotU, double *leftU, double *rightU, double *NU, int ind2){
    
    unsigned short int itr, j, spanU, ind, fourncp, myint, cpInd;
    double wgh, u, funVal;
    
    fourncp=4*ncp;
    
    cpInd=4*jj+ind2;
    
    for (itr = 0; itr < iters; itr++){
        
        u=us[0]-stepU;
        
        spanU = FindSpan(ncp, degU, u, knotU);
        BasisFuns(spanU, u, degU, knotU, NU, leftU, rightU);
        
        ind = spanU - degU;
        
        myint=ind*4+ind2;
        
        wgh=0.0;
        for (j = 0; j <= degU; j++){
            wgh += NU[j] * cp[j*4+myint];
        }
        
        funVal=NU[jj-ind] * cp[cpInd]/wgh;
        
        if (funVal>oldFunVal){
            us[0]=u;
            oldFunVal=funVal;
        }
        else {
            
            u+=2*stepU;
            
            spanU = FindSpan(ncp, degU, u, knotU);
            BasisFuns(spanU, u, degU, knotU, NU, leftU, rightU);
            
            ind = spanU - degU;
            
            myint=ind*4+ind2;
            
            wgh=0.0;
            for (j = 0; j <= degU; j++){
                wgh += NU[j] * cp[j*4+myint];
            }
            
            funVal=NU[jj-ind] * cp[cpInd]/wgh;
            
            if (funVal>oldFunVal){
                us[0]=u;
                oldFunVal=funVal;
            }
            
        }
        
        stepU=0.5*stepU;
        
    }
    
    if (us[0]<knotU[0]){
        us[0]=knotU[0];
    }
    else if (us[0]>knotU[ncp]){
        us[0]=knotU[ncp];
    }
    
    return;
    
}

static void findNURBSbasisFunV(int ii, int iters, double *us, double oldFunVal, double stepV, int degV, double *cp, int fourncp, int kcp, double *knotV, double *leftV, double *rightV, double *NV, int ind){
    
    unsigned short int itr, i, spanV, ind2, myint, cpInd;
    double wgh, v, funVal;
    
    cpInd=ii*fourncp+ind;
    
    for (itr = 0; itr < iters; itr++){
        
        v=us[1]-stepV;
        
        spanV = FindSpan(kcp, degV, v, knotV);
        BasisFuns(spanV, v, degV, knotV, NV, leftV, rightV);
        
        ind2 = spanV - degV;
        
        myint=ind2*fourncp+ind;
        
        wgh=0.0;
        for (i = 0; i <= degV; i++){
            wgh += NV[i] * cp[i*fourncp+myint];
        }
        
        funVal=NV[ii-ind2] * cp[cpInd]/wgh;
        
        if (funVal>oldFunVal){
            us[1]=v;
            oldFunVal=funVal;
        }
        else {
            
            v+=2*stepV;
            
            spanV = FindSpan(kcp, degV, v, knotV);
            BasisFuns(spanV, v, degV, knotV, NV, leftV, rightV);
            
            ind2 = spanV - degV;
            
            myint=ind2*fourncp+ind;
            
            wgh=0.0;
            for (i = 0; i <= degV; i++){
                wgh += NV[i] * cp[i*fourncp+myint];
            }
            
            funVal=NV[ii-ind2] * cp[cpInd]/wgh;
            
            if (funVal>oldFunVal){
                us[1]=v;
                oldFunVal=funVal;
            }
            
        }
        
        stepV=0.5*stepV;
        
    }
    
    if (us[1]<knotV[0]){
        us[1]=knotV[0];
    }
    else if (us[1]>knotV[kcp]){
        us[1]=knotV[kcp];
    }
    
    return;
    
}

static void findNURBSbasisFunIso(int ii, int jj, int iters, double *us, double oldFunVal, double stepU, double stepV, int degU, int degV, double *cp, int ncp, int kcp, double *knotU, double *knotV, double *leftU, double *rightU, double *NU, double *leftV, double *rightV, double *NV){
    
    unsigned short int itr, i, j, spanU, spanV, ind, ind2, fourncp, myint, cpInd;
    double wgh, u, v, funVal;
    
    fourncp=4*ncp;
    
    cpInd=ii*fourncp+4*jj+3;
    
    v=us[1];
    spanV = FindSpan(kcp, degV, v, knotV);
    BasisFuns(spanV, v, degV, knotV, NV, leftV, rightV);
    ind2 = spanV - degV;
    
    for (itr = 0; itr < iters; itr++){
        
        u=us[0]-stepU;
        
        spanU = FindSpan(ncp, degU, u, knotU);
        BasisFuns(spanU, u, degU, knotU, NU, leftU, rightU);
        
        ind = spanU - degU;
        
        myint=ind2*fourncp+ind*4+3;
        
        wgh=0.0;
        for (i = 0; i <= degV; i++){
            for (j = 0; j <= degU; j++){
                wgh += NV[i] * NU[j] * cp[i*fourncp+j*4+myint];
            }
        }
        
        funVal=NV[ii-ind2] * NU[jj-ind] * cp[cpInd]/wgh;
        
        if (funVal>oldFunVal){
            
            us[0]=u;
            
            oldFunVal=funVal;
            
            v=us[1]-stepV;
            
            spanV = FindSpan(kcp, degV, v, knotV);
            BasisFuns(spanV, v, degV, knotV, NV, leftV, rightV);
            
            ind2 = spanV - degV;
            
            myint=ind2*fourncp+ind*4+3;
            
            wgh=0.0;
            for (i = 0; i <= degV; i++){
                for (j = 0; j <= degU; j++){
                    wgh += NV[i] * NU[j] * cp[i*fourncp+j*4+myint];
                }
            }
            
            funVal=NV[ii-ind2] * NU[jj-ind] * cp[cpInd]/wgh;
            
            if (funVal>oldFunVal){
                
                us[1]=v;
                oldFunVal=funVal;
                
            }
            else {
                
                v+=2*stepV;
                
                spanV = FindSpan(kcp, degV, v, knotV);
                BasisFuns(spanV, v, degV, knotV, NV, leftV, rightV);
                
                ind2 = spanV - degV;
                
                myint=ind2*fourncp+ind*4+3;
                
                wgh=0.0;
                for (i = 0; i <= degV; i++){
                    for (j = 0; j <= degU; j++){
                        wgh += NV[i] * NU[j] * cp[i*fourncp+j*4+myint];
                    }
                }
                
                funVal=NV[ii-ind2] * NU[jj-ind] * cp[cpInd]/wgh;
                
                if (funVal>oldFunVal){
                    us[1]=v;
                    oldFunVal=funVal;
                }
                else {
                    v=us[1];
                    
                    spanV = FindSpan(kcp, degV, v, knotV);
                    BasisFuns(spanV, v, degV, knotV, NV, leftV, rightV);
                    
                    ind2 = spanV - degV;
                }
                
            }
            
        }
        else {
            u+=2*stepU;
            
            spanU = FindSpan(ncp, degU, u, knotU);
            BasisFuns(spanU, u, degU, knotU, NU, leftU, rightU);
            
            ind = spanU - degU;
            
            myint=ind2*fourncp+ind*4+3;
            
            wgh=0.0;
            for (i = 0; i <= degV; i++){
                for (j = 0; j <= degU; j++){
                    wgh += NV[i] * NU[j] * cp[i*fourncp+j*4+myint];
                }
            }
            
            funVal=NV[ii-ind2] * NU[jj-ind] * cp[cpInd]/wgh;
            
            if (funVal>oldFunVal){
                
                us[0]=u;
                oldFunVal=funVal;
                
            }
            else {
                
                u=us[0];
                
                spanU = FindSpan(ncp, degU, u, knotU);
                BasisFuns(spanU, u, degU, knotU, NU, leftU, rightU);
                
                ind = spanU - degU;
                
            }
            
            v=us[1]-stepV;
            
            spanV = FindSpan(kcp, degV, v, knotV);
            BasisFuns(spanV, v, degV, knotV, NV, leftV, rightV);
            
            ind2 = spanV - degV;
            
            myint=ind2*fourncp+ind*4+3;
            
            wgh=0.0;
            for (i = 0; i <= degV; i++){
                for (j = 0; j <= degU; j++){
                    wgh += NV[i] * NU[j] * cp[i*fourncp+j*4+myint];
                }
            }
            
            funVal=NV[ii-ind2] * NU[jj-ind] * cp[cpInd]/wgh;
            
            if (funVal>oldFunVal){
                
                us[1]=v;
                oldFunVal=funVal;
                
            }
            else {
                
                v+=2*stepV;
                
                spanV = FindSpan(kcp, degV, v, knotV);
                BasisFuns(spanV, v, degV, knotV, NV, leftV, rightV);
                
                ind2 = spanV - degV;
                
                myint=ind2*fourncp+ind*4+3;
                
                wgh=0.0;
                for (i = 0; i <= degV; i++){
                    for (j = 0; j <= degU; j++){
                        wgh += NV[i] * NU[j] * cp[i*fourncp+j*4+myint];
                    }
                }
                
                funVal=NV[ii-ind2] * NU[jj-ind] * cp[cpInd]/wgh;
                
                if (funVal>oldFunVal){
                    us[1]=v;
                    oldFunVal=funVal;
                }
                else {
                    v=us[1];
                    
                    spanV = FindSpan(kcp, degV, v, knotV);
                    BasisFuns(spanV, v, degV, knotV, NV, leftV, rightV);
                    
                    ind2 = spanV - degV;
                }
                
            }
            
        }
        
        stepU=0.5*stepU;
        stepV=0.5*stepV;
        
    }
    
    if (us[0]<knotU[0]){
        us[0]=knotU[0];
    }
    else if (us[0]>knotU[ncp]){
        us[0]=knotU[ncp];
    }
    
    if (us[1]<knotV[0]){
        us[1]=knotV[0];
    }
    else if (us[1]>knotV[kcp]){
        us[1]=knotV[kcp];
    }
    
    return;
    
}

static void findNURBSbasisFunIso4xCP(int ii, int jj, int iters, double *us, double stepU, double stepV, int degU, int degV, double *cp, int ncp, int kcp, double *knotU, double *knotV, double *usX1max, double *basisVals, double *leftU, double *rightU, double *NU, double *leftV, double *rightV, double *NV){
    
    int itr, itr2, i, j, spanU, spanV, ind, ind2, fourncp, myint, numCP, cpInd1, cpInd2, cpInd3, cpInd4, uvInd1, uvInd2, uvInd3, uvInd4, bvind1, bvind2, bvind3, bvind4;
    double wgh, u, v, funVal, oldFunVal, p1, p2, f1, f2;
    
    bvind1=ii*ncp+jj;
    bvind2=bvind1+1;
    bvind3=bvind1+ncp;
    bvind4=bvind3+1;
    
    uvInd1=ii*2*ncp+2*jj;
    uvInd2=uvInd1+2;
    uvInd3=uvInd1+2*ncp;
    uvInd4=uvInd3+2;
    
    fourncp=4*ncp;
    
    numCP=ncp*kcp;
    
    cpInd1=ii*fourncp+4*jj+3;
    cpInd2=cpInd1+4;
    cpInd3=cpInd1+fourncp;
    cpInd4=cpInd3+4;
    
    for (itr2 = 0; itr2 < 2; itr2++){
        
        v=us[1];
        spanV = FindSpan(kcp, degV, v, knotV);
        BasisFuns(spanV, v, degV, knotV, NV, leftV, rightV);
        ind2 = spanV - degV;
        
        u=us[0];
        spanU = FindSpan(ncp, degU, u, knotU);
        BasisFuns(spanU, u, degU, knotU, NU, leftU, rightU);
        ind = spanU - degU;
        
        myint=ind2*fourncp+ind*4+3;
        
        p1= ((v-usX1max[uvInd1+1])*usX1max[uvInd3]+(usX1max[uvInd3+1]-v)*usX1max[uvInd1])/(usX1max[uvInd3+1]-usX1max[uvInd1+1]);
        p2= ((v-usX1max[uvInd2+1])*usX1max[uvInd4]+(usX1max[uvInd4+1]-v)*usX1max[uvInd2])/(usX1max[uvInd4+1]-usX1max[uvInd2+1]);
        
        f1=basisVals[numCP*bvind1+bvind2]+basisVals[numCP*bvind3+bvind4];
        f2=basisVals[numCP*bvind2+bvind1]+basisVals[numCP*bvind4+bvind3];
        
        wgh=0.0;
        for (i = 0; i <= degV; i++){
            for (j = 0; j <= degU; j++){
                wgh += NV[i] * NU[j] * cp[i*fourncp+j*4+myint];
            }
        }
        
        oldFunVal=((NV[ii-ind2] * NU[jj-ind] * cp[cpInd1]+NV[ii+1-ind2] * NU[jj-ind] * cp[cpInd3])-(NV[ii-ind2] * NU[jj+1-ind] * cp[cpInd2]+NV[ii+1-ind2] * NU[jj+1-ind] * cp[cpInd4]))/wgh-((u-p1)*f1-(p2-u)*f2)/(p2-p1);
        
        for (itr = 0; itr < iters; itr++){
            
            if (fabs(oldFunVal)<1e-6){
                break;
            }
            
            if (oldFunVal>0){
                u+=stepU;
            }
            else {
                u-=stepU;
            }
            stepU=0.5*stepU;
            
            spanU = FindSpan(ncp, degU, u, knotU);
            BasisFuns(spanU, u, degU, knotU, NU, leftU, rightU);
            ind = spanU - degU;
            
            myint=ind2*fourncp+ind*4+3;
            
            wgh=0.0;
            for (i = 0; i <= degV; i++){
                for (j = 0; j <= degU; j++){
                    wgh += NV[i] * NU[j] * cp[i*fourncp+j*4+myint];
                }
            }
            
            funVal=((NV[ii-ind2] * NU[jj-ind] * cp[cpInd1]+NV[ii+1-ind2] * NU[jj-ind] * cp[cpInd3])-(NV[ii-ind2] * NU[jj+1-ind] * cp[cpInd2]+NV[ii+1-ind2] * NU[jj+1-ind] * cp[cpInd4]))/wgh-((u-p1)*f1-(p2-u)*f2)/(p2-p1);
            
            if (fabs(funVal)<fabs(oldFunVal)){
                oldFunVal=funVal;
                us[0]=u;
            }
            else {
                u=us[0];
            }
            
        }
        
        spanU = FindSpan(ncp, degU, u, knotU);
        BasisFuns(spanU, u, degU, knotU, NU, leftU, rightU);
        ind = spanU - degU;
        
        myint=ind2*fourncp+ind*4+3;
        
        p1= ((u-usX1max[uvInd1])*usX1max[uvInd2+1]+(usX1max[uvInd2]-u)*usX1max[uvInd1+1])/(usX1max[uvInd2]-usX1max[uvInd1]);
        p2= ((u-usX1max[uvInd3])*usX1max[uvInd4+1]+(usX1max[uvInd4]-u)*usX1max[uvInd3+1])/(usX1max[uvInd4]-usX1max[uvInd3]);
        
        f1=basisVals[numCP*bvind1+bvind3]+basisVals[numCP*bvind2+bvind4];
        f2=basisVals[numCP*bvind3+bvind1]+basisVals[numCP*bvind4+bvind2];
        
        wgh=0.0;
        for (i = 0; i <= degV; i++){
            for (j = 0; j <= degU; j++){
                wgh += NV[i] * NU[j] * cp[i*fourncp+j*4+myint];
            }
        }
        
        oldFunVal=((NV[ii-ind2] * NU[jj-ind] * cp[cpInd1]+NV[ii-ind2] * NU[jj+1-ind] * cp[cpInd2])-(NV[ii+1-ind2] * NU[jj-ind] * cp[cpInd3]+NV[ii+1-ind2] * NU[jj+1-ind] * cp[cpInd4]))/wgh-((v-p1)*f1-(p2-v)*f2)/(p2-p1);
        
        for (itr = 0; itr < iters; itr++){
            
            if (fabs(oldFunVal)<1e-6){
                break;
            }
            
            if (oldFunVal>0){
                v+=stepV;
            }
            else {
                v-=stepV;
            }
            stepV=0.5*stepV;
            
            spanV = FindSpan(kcp, degV, v, knotV);
            BasisFuns(spanV, v, degV, knotV, NV, leftV, rightV);
            ind2 = spanV - degV;
            
            myint=ind2*fourncp+ind*4+3;
            
            wgh=0.0;
            for (i = 0; i <= degV; i++){
                for (j = 0; j <= degU; j++){
                    wgh += NV[i] * NU[j] * cp[i*fourncp+j*4+myint];
                }
            }
            
            funVal=((NV[ii-ind2] * NU[jj-ind] * cp[cpInd1]+NV[ii-ind2] * NU[jj+1-ind] * cp[cpInd2])-(NV[ii+1-ind2] * NU[jj-ind] * cp[cpInd3]+NV[ii+1-ind2] * NU[jj+1-ind] * cp[cpInd4]))/wgh-((v-p1)*f1-(p2-v)*f2)/(p2-p1);
            
            if (fabs(funVal)<fabs(oldFunVal)){
                oldFunVal=funVal;
                us[1]=v;
            }
            else {
                v=us[1];
            }
            
        }
        
    }
    
    return;
    
}

static void findNURBSbasisFunIso2xCP(int ii1, int jj1, int ii2, int jj2, double alpha, double beta, int iters, double *us, double stepU, double stepV, int degU, int degV, double *cp, int ncp, int kcp, double *knotU, double *knotV, double *usX1max, double *basisVals, double *leftU, double *rightU, double *NU, double *leftV, double *rightV, double *NV){
    
    int itr, i, j, spanU, spanV, ind, ind2, fourncp, myint, bvind1, bvind2, uvInd1, uvInd2, cpInd1, cpInd2, numCP;
    double wgh, u, v, funVal, oldFunVal, p1, p2, f1, f2;
    
    fourncp=4*ncp;
    numCP=ncp*kcp;
    
    if (ii1==ii2){
        
        bvind1=ii1*ncp+jj1;
        bvind2=bvind1+1;
        
        uvInd1=ii1*2*ncp+2*jj1;
        uvInd2=uvInd1+2;
        
        cpInd1=ii1*fourncp+4*jj1+3;
        cpInd2=cpInd1+4;
        
        p1=usX1max[uvInd1];
        p2=usX1max[uvInd2];
        
        f1=beta*basisVals[numCP*bvind1+bvind2];
        f2=alpha*basisVals[numCP*bvind2+bvind1];
        
        v=us[1];
        spanV = FindSpan(kcp, degV, v, knotV);
        BasisFuns(spanV, v, degV, knotV, NV, leftV, rightV);
        ind2 = spanV - degV;
        
        u=us[0];
        spanU = FindSpan(ncp, degU, u, knotU);
        BasisFuns(spanU, u, degU, knotU, NU, leftU, rightU);
        ind = spanU - degU;
        
        myint=ind2*fourncp+ind*4+3;
        
        wgh=0.0;
        for (i = 0; i <= degV; i++){
            for (j = 0; j <= degU; j++){
                wgh += NV[i] * NU[j] * cp[i*fourncp+j*4+myint];
            }
        }
        
        oldFunVal=(beta*NV[ii1-ind2] * NU[jj1-ind] * cp[cpInd1]-alpha*NV[ii2-ind2] * NU[jj2-ind] * cp[cpInd2])/wgh-((u-p1)*f1-(p2-u)*f2)/(p2-p1);
        
        for (itr = 0; itr < iters; itr++){
            
            if (fabs(oldFunVal)<1e-6){
                break;
            }
            
            if (oldFunVal>0){
                u+=stepU;
            }
            else {
                u-=stepU;
            }
            stepU=0.5*stepU;
            
            spanU = FindSpan(ncp, degU, u, knotU);
            BasisFuns(spanU, u, degU, knotU, NU, leftU, rightU);
            ind = spanU - degU;
            
            myint=ind2*fourncp+ind*4+3;
            
            wgh=0.0;
            for (i = 0; i <= degV; i++){
                for (j = 0; j <= degU; j++){
                    wgh += NV[i] * NU[j] * cp[i*fourncp+j*4+myint];
                }
            }
            
            funVal=(beta*NV[ii1-ind2] * NU[jj1-ind] * cp[cpInd1]-alpha*NV[ii2-ind2] * NU[jj2-ind] * cp[cpInd2])/wgh-((u-p1)*f1-(p2-u)*f2)/(p2-p1);
            
            if (fabs(funVal)<fabs(oldFunVal)){
                oldFunVal=funVal;
                us[0]=u;
            }
            else {
                u=us[0];
            }
            
        }
        
    }
    else {
        
        bvind1=ii1*ncp+jj1;
        bvind2=bvind1+ncp;
        
        uvInd1=ii1*2*ncp+2*jj1;
        uvInd2=uvInd1+2*ncp;
        
        cpInd1=ii1*fourncp+4*jj1+3;
        cpInd2=cpInd1+fourncp;
        
        p1=usX1max[uvInd1];
        p2=usX1max[uvInd2];
        
        f1=beta*basisVals[numCP*bvind1+bvind2];
        f2=alpha*basisVals[numCP*bvind2+bvind1];
        
        u=us[0];
        spanU = FindSpan(ncp, degU, u, knotU);
        BasisFuns(spanU, u, degU, knotU, NU, leftU, rightU);
        ind = spanU - degU;
        
        v=us[1];
        spanV = FindSpan(kcp, degV, v, knotV);
        BasisFuns(spanV, v, degV, knotV, NV, leftV, rightV);
        ind2 = spanV - degV;
        
        myint=ind2*fourncp+ind*4+3;
        
        wgh=0.0;
        for (i = 0; i <= degV; i++){
            for (j = 0; j <= degU; j++){
                wgh += NV[i] * NU[j] * cp[i*fourncp+j*4+myint];
            }
        }
        
        oldFunVal=(beta*NV[ii1-ind2] * NU[jj1-ind] * cp[cpInd1]-alpha*NV[ii2-ind2] * NU[jj2-ind] * cp[cpInd2])/wgh-((v-p1)*f1-(p2-v)*f2)/(p2-p1);
        
        for (itr = 0; itr < iters; itr++){
            
            if (fabs(oldFunVal)<1e-6){
                break;
            }
            
            if (oldFunVal>0){
                v+=stepV;
            }
            else {
                v-=stepV;
            }
            stepV=0.5*stepV;
            
            spanV = FindSpan(kcp, degV, v, knotV);
            BasisFuns(spanV, v, degV, knotV, NV, leftV, rightV);
            ind2 = spanV - degV;
            
            myint=ind2*fourncp+ind*4+3;
            
            wgh=0.0;
            for (i = 0; i <= degV; i++){
                for (j = 0; j <= degU; j++){
                    wgh += NV[i] * NU[j] * cp[i*fourncp+j*4+myint];
                }
            }
            
            funVal=(beta*NV[ii1-ind2] * NU[jj1-ind] * cp[cpInd1]-alpha*NV[ii2-ind2] * NU[jj2-ind] * cp[cpInd2])/wgh-((v-p1)*f1-(p2-v)*f2)/(p2-p1);
            
            if (fabs(funVal)<fabs(oldFunVal)){
                oldFunVal=funVal;
                us[1]=v;
            }
            else {
                v=us[1];
            }
            
        }
        
    }
    
    return;
    
}

static void findNURBSbasisFunIso4xScCP(int ii, int jj, double a1, double b1, int iters, double *us, double stepU, double stepV, int degU, int degV, double *cp, int ncp, int kcp, double *knotU, double *knotV, double *usX1max, double *basisVals, double *leftU, double *rightU, double *NU, double *leftV, double *rightV, double *NV){
    
    int itr, itr2, i, j, spanU, spanV, ind, ind2, fourncp, myint, numCP, cpInd1, cpInd2, cpInd3, cpInd4, uvInd1, uvInd2, uvInd3, uvInd4, bvind1, bvind2, bvind3, bvind4;
    double wgh, u, v, funVal, oldFunVal, a2, b2, p1, p2, f1, f2;
    
    a2=1.0-a1;
    b2=1.0-b1;
    
    bvind1=ii*ncp+jj;
    bvind2=bvind1+1;
    bvind3=bvind1+ncp;
    bvind4=bvind3+1;
    
    uvInd1=ii*2*ncp+2*jj;
    uvInd2=uvInd1+2;
    uvInd3=uvInd1+2*ncp;
    uvInd4=uvInd3+2;
    
    fourncp=4*ncp;
    
    numCP=ncp*kcp;
    
    cpInd1=ii*fourncp+4*jj+3;
    cpInd2=cpInd1+4;
    cpInd3=cpInd1+fourncp;
    cpInd4=cpInd3+4;
    
    for (itr2 = 0; itr2 < 2; itr2++){
        
        v=us[1];
        spanV = FindSpan(kcp, degV, v, knotV);
        BasisFuns(spanV, v, degV, knotV, NV, leftV, rightV);
        ind2 = spanV - degV;
        
        u=us[0];
        spanU = FindSpan(ncp, degU, u, knotU);
        BasisFuns(spanU, u, degU, knotU, NU, leftU, rightU);
        ind = spanU - degU;
        
        myint=ind2*fourncp+ind*4+3;
        
        p1= ((v-usX1max[uvInd1+1])*usX1max[uvInd3]+(usX1max[uvInd3+1]-v)*usX1max[uvInd1])/(usX1max[uvInd3+1]-usX1max[uvInd1+1]);
        p2= ((v-usX1max[uvInd2+1])*usX1max[uvInd4]+(usX1max[uvInd4+1]-v)*usX1max[uvInd2])/(usX1max[uvInd4+1]-usX1max[uvInd2+1]);
        
        f1=b2*(a2*basisVals[numCP*bvind1+bvind2]+a1*basisVals[numCP*bvind3+bvind4]);
        f2=b1*(a2*basisVals[numCP*bvind2+bvind1]+a1*basisVals[numCP*bvind4+bvind3]);
        
        wgh=0.0;
        for (i = 0; i <= degV; i++){
            for (j = 0; j <= degU; j++){
                wgh += NV[i] * NU[j] * cp[i*fourncp+j*4+myint];
            }
        }
        
        oldFunVal=(b2*(a2*NV[ii-ind2] * NU[jj-ind] * cp[cpInd1]+a1*NV[ii+1-ind2] * NU[jj-ind] * cp[cpInd3])-b1*(a2*NV[ii-ind2] * NU[jj+1-ind] * cp[cpInd2]+a1*NV[ii+1-ind2] * NU[jj+1-ind] * cp[cpInd4]))/wgh-((u-p1)*f1-(p2-u)*f2)/(p2-p1);
        
        for (itr = 0; itr < iters; itr++){
            
            if (fabs(oldFunVal)<1e-6){
                break;
            }
            
            if (oldFunVal>0){
                u+=stepU;
            }
            else {
                u-=stepU;
            }
            stepU=0.5*stepU;
            
            spanU = FindSpan(ncp, degU, u, knotU);
            BasisFuns(spanU, u, degU, knotU, NU, leftU, rightU);
            ind = spanU - degU;
            
            myint=ind2*fourncp+ind*4+3;
            
            wgh=0.0;
            for (i = 0; i <= degV; i++){
                for (j = 0; j <= degU; j++){
                    wgh += NV[i] * NU[j] * cp[i*fourncp+j*4+myint];
                }
            }
            
            funVal=(b2*(a2*NV[ii-ind2] * NU[jj-ind] * cp[cpInd1]+a1*NV[ii+1-ind2] * NU[jj-ind] * cp[cpInd3])-b1*(a2*NV[ii-ind2] * NU[jj+1-ind] * cp[cpInd2]+a1*NV[ii+1-ind2] * NU[jj+1-ind] * cp[cpInd4]))/wgh-((u-p1)*f1-(p2-u)*f2)/(p2-p1);
            
            if (fabs(funVal)<fabs(oldFunVal)){
                oldFunVal=funVal;
                us[0]=u;
            }
            else {
                u=us[0];
            }
            
        }
        
        spanU = FindSpan(ncp, degU, u, knotU);
        BasisFuns(spanU, u, degU, knotU, NU, leftU, rightU);
        ind = spanU - degU;
        
        myint=ind2*fourncp+ind*4+3;
        
        p1= ((u-usX1max[uvInd1])*usX1max[uvInd2+1]+(usX1max[uvInd2]-u)*usX1max[uvInd1+1])/(usX1max[uvInd2]-usX1max[uvInd1]);
        p2= ((u-usX1max[uvInd3])*usX1max[uvInd4+1]+(usX1max[uvInd4]-u)*usX1max[uvInd3+1])/(usX1max[uvInd4]-usX1max[uvInd3]);
        
        f1=a2*(b2*basisVals[numCP*bvind1+bvind3]+b1*basisVals[numCP*bvind2+bvind4]);
        f2=a1*(b2*basisVals[numCP*bvind3+bvind1]+b1*basisVals[numCP*bvind4+bvind2]);
        
        wgh=0.0;
        for (i = 0; i <= degV; i++){
            for (j = 0; j <= degU; j++){
                wgh += NV[i] * NU[j] * cp[i*fourncp+j*4+myint];
            }
        }
        
        oldFunVal=(a2*(b2*NV[ii-ind2] * NU[jj-ind] * cp[cpInd1]+b1*NV[ii-ind2] * NU[jj+1-ind] * cp[cpInd2])-a1*(b2*NV[ii+1-ind2] * NU[jj-ind] * cp[cpInd3]+b1*NV[ii+1-ind2] * NU[jj+1-ind] * cp[cpInd4]))/wgh-((v-p1)*f1-(p2-v)*f2)/(p2-p1);
        
        for (itr = 0; itr < iters; itr++){
            
            if (fabs(oldFunVal)<1e-6){
                break;
            }
            
            if (oldFunVal>0){
                v+=stepV;
            }
            else {
                v-=stepV;
            }
            stepV=0.5*stepV;
            
            spanV = FindSpan(kcp, degV, v, knotV);
            BasisFuns(spanV, v, degV, knotV, NV, leftV, rightV);
            ind2 = spanV - degV;
            
            myint=ind2*fourncp+ind*4+3;
            
            wgh=0.0;
            for (i = 0; i <= degV; i++){
                for (j = 0; j <= degU; j++){
                    wgh += NV[i] * NU[j] * cp[i*fourncp+j*4+myint];
                }
            }
            
            funVal=(a2*(b2*NV[ii-ind2] * NU[jj-ind] * cp[cpInd1]+b1*NV[ii-ind2] * NU[jj+1-ind] * cp[cpInd2])-a1*(b2*NV[ii+1-ind2] * NU[jj-ind] * cp[cpInd3]+b1*NV[ii+1-ind2] * NU[jj+1-ind] * cp[cpInd4]))/wgh-((v-p1)*f1-(p2-v)*f2)/(p2-p1);
            
            if (fabs(funVal)<fabs(oldFunVal)){
                oldFunVal=funVal;
                us[1]=v;
            }
            else {
                v=us[1];
            }
            
        }
        
    }
    
    return;
    
}

static void NURBSsurfaceBasisMax(int degU, int degV, double *cp, int ncp, int kcp, double *knotU, double *knotV, double *us, double *leftU, double *rightU, double *NU, double *leftV, double *rightV, double *NV){
    
    /* NURBSsurfaceBasisMax( degU - degree of NURBS in u, degV - degree of NURBS in v, cp - pointer to control points, ncp - number of control points in u, kcp - number of control points in v, knotU - pointer to knot sequence in u, knotV - pointer to knot sequence in v, us - pointer to parameter values, leftU - pointer to array for function BasisFuns, rightU - pointer to array for function BasisFuns, NU - pointer to array for function BasisFuns, leftV - pointer to array for function BasisFuns, rightV - pointer to array for function BasisFuns, NV - pointer to array for function BasisFuns) */
    
    int i, j, ii, jj, spanU, spanV, ind, ind2, fourncp, myint, nus, orderU, orderV;
    double wgh, uv[2], funVal, stepU, stepV;
    
    fourncp=4*ncp;
    orderU=degU+1;
    orderV=degV+1;
    
    /* ii=0  jj=0 */
    
    us[0]=knotU[0];
    us[1]=knotV[0];
    
    /* ii=0  jj=1,2,...,ncp-2 */
    nus=1;
    ind2=3;
    
    for (jj = 1; jj <= (ncp-2); jj++){
        
        uv[0]=0.5*(knotU[jj]+knotU[jj+orderU]);
        
        spanU = FindSpan(ncp, degU, uv[0], knotU);
        BasisFuns(spanU, uv[0], degU, knotU, NU, leftU, rightU);
        
        ind = spanU - degU;
        
        myint=ind*4+ind2;
        
        wgh=0.0;
        for (j = 0; j <= degU; j++){
            wgh += NU[j] * cp[j*4+myint];
        }
        
        funVal=NU[jj-ind] * cp[4*jj+3]/wgh;
        
        stepU=0.25*(knotU[jj+orderU]-knotU[jj]);
        
        findNURBSbasisFunU(jj, 15, uv, funVal, stepU, degU, cp, ncp, knotU, leftU, rightU, NU, ind2);
        
        us[2*nus]=uv[0];
        us[2*nus+1]=knotV[0];
        
        nus++;
        
    }
    
    /* ii=0  jj=ncp-1 */
    
    us[2*nus]=knotU[ncp];
    us[2*nus+1]=knotV[0];
    
    nus++;
    
    /* ii=1,2,...,kcp-2 */
    
    for (ii = 1; ii <= (kcp-2); ii++){
        
        /* jj=0 */
        
        uv[1]=0.5*(knotV[ii]+knotV[ii+orderV]);
        
        spanV = FindSpan(kcp, degV, uv[1], knotV);
        BasisFuns(spanV, uv[1], degV, knotV, NV, leftV, rightV);
        
        ind2 = spanV - degV;
        myint=ind2*fourncp+3;
        
        wgh=0.0;
        for (i = 0; i <= degV; i++){
            wgh += NV[i] * cp[i*fourncp+myint];
        }
        
        funVal=NV[ii-ind2] * cp[ii*fourncp+3]/wgh;
        
        stepV=0.25*(knotV[ii+orderV]-knotV[ii]);
        
        findNURBSbasisFunV(ii, 15, uv, funVal, stepV, degV, cp, fourncp, kcp, knotV, leftV, rightV, NV, 3);
        
        us[2*nus]=knotU[0];
        us[2*nus+1]=uv[1];
        
        nus++;
        
        /* jj=1,2,...,ncp-2 */
        
        for (jj = 1; jj <= (ncp-2); jj++){
            
            uv[0]=0.5*(knotU[jj]+knotU[jj+orderU]);
            uv[1]=0.5*(knotV[ii]+knotV[ii+orderV]);
            
            spanU = FindSpan(ncp, degU, uv[0], knotU);
            BasisFuns(spanU, uv[0], degU, knotU, NU, leftU, rightU);
            
            ind = spanU - degU;
            
            spanV = FindSpan(kcp, degV, uv[1], knotV);
            BasisFuns(spanV, uv[1], degV, knotV, NV, leftV, rightV);
            
            ind2 = spanV - degV;
            myint=ind2*fourncp+ind*4+3;
            
            wgh=0.0;
            for (i = 0; i <= degV; i++){
                for (j = 0; j <= degU; j++){
                    wgh += NV[i] * NU[j] * cp[i*fourncp+j*4+myint];
                }
            }
            
            funVal=NV[ii-ind2] * NU[jj-ind] * cp[ii*fourncp+4*jj+3]/wgh;
            
            stepU=0.25*(knotU[jj+orderU]-knotU[jj]);
            stepV=0.25*(knotV[ii+orderV]-knotV[ii]);
            
            findNURBSbasisFunIso(ii, jj, 15, uv, funVal, stepU, stepV, degU, degV, cp, ncp, kcp, knotU, knotV, leftU, rightU, NU, leftV, rightV, NV);
            
            us[2*nus]=uv[0];
            us[2*nus+1]=uv[1];
            
            nus++;
            
        }
        
        /* jj=ncp-1 */
        
        uv[1]=0.5*(knotV[ii]+knotV[ii+orderV]);
        
        spanV = FindSpan(kcp, degV, uv[1], knotV);
        BasisFuns(spanV, uv[1], degV, knotV, NV, leftV, rightV);
        
        ind2 = spanV - degV;
        myint=(ind2+1)*fourncp-1;
        
        wgh=0.0;
        for (i = 0; i <= degV; i++){
            wgh += NV[i] * cp[i*fourncp+myint];
        }
        
        funVal=NV[ii-ind2] * cp[ii*fourncp+4*(ncp-1)+3]/wgh;
        
        stepV=0.25*(knotV[ii+orderV]-knotV[ii]);
        
        findNURBSbasisFunV(ii, 15, uv, funVal, stepV, degV, cp, fourncp, kcp, knotV, leftV, rightV, NV, fourncp-1);
        
        us[2*nus]=knotU[ncp];
        us[2*nus+1]=uv[1];
        
        nus++;
        
    }
    
    /* ii=kcp-1  jj=0 */
    
    us[2*nus]=knotU[0];
    us[2*nus+1]=knotV[kcp];
    
    nus++;
    
    ind2=fourncp*(kcp-1)+3;
    
    /* ii=kcp-1  jj=1,2,...,ncp-2 */
    
    for (jj = 1; jj <= (ncp-2); jj++){
        
        uv[0]=0.5*(knotU[jj]+knotU[jj+orderU]);
        
        spanU = FindSpan(ncp, degU, uv[0], knotU);
        BasisFuns(spanU, uv[0], degU, knotU, NU, leftU, rightU);
        
        ind = spanU - degU;
        
        myint=ind*4+ind2;
        
        wgh=0.0;
        for (j = 0; j <= degU; j++){
            wgh += NU[j] * cp[j*4+myint];
        }
        
        funVal=NU[jj-ind] * cp[4*jj+ind2]/wgh;
        
        stepU=0.25*(knotU[jj+orderU]-knotU[jj]);
        
        findNURBSbasisFunU(jj, 15, uv, funVal, stepU, degU, cp, ncp, knotU, leftU, rightU, NU, ind2);
        
        us[2*nus]=uv[0];
        us[2*nus+1]=knotV[kcp];
        
        nus++;
        
    }
    
    /* ii=kcp-1  jj=ncp-1 */
    
    us[2*nus]=knotU[ncp];
    us[2*nus+1]=knotV[kcp];
    
}

static void NURBSsurfaceBasisX4Max(int degU, int degV, double *cp, int ncp, int kcp, double *knotU, double *knotV, double *us, double *usX1max, double *basisVals, double *leftU, double *rightU, double *NU, double *leftV, double *rightV, double *NV){
    
    /* NURBSsurfaceBasisX4Max( degU - degree of NURBS in u, degV - degree of NURBS in v, cp - pointer to control points, ncp - number of control points in u, kcp - number of control points in v, knotU - pointer to knot sequence in u, knotV - pointer to knot sequence in v, us - pointer to parameter values, usX1max - pointer to parameter values, basisVals - basis values at single max, leftU - pointer to array for function BasisFuns, rightU - pointer to array for function BasisFuns, NU - pointer to array for function BasisFuns, leftV - pointer to array for function BasisFuns, rightV - pointer to array for function BasisFuns, NV - pointer to array for function BasisFuns) */
    
    int ii, jj, nus, orderU, orderV;
    double uv[2], stepU, stepV;
    
    orderU=degU+1;
    orderV=degV+1;
    
    nus=0;
    
    /* ii=0,1,2,...,kcp-2 */
    
    for (ii = 0; ii <= (kcp-2); ii++){
        
        /* jj=0,1,2,...,ncp-2 */
        
        for (jj = 0; jj <= (ncp-2); jj++){
            
            uv[0]=0.25*(usX1max[2*(ii*ncp+jj)]+usX1max[2*(ii*ncp+jj+1)]+usX1max[2*((ii+1)*ncp+jj)]+usX1max[2*((ii+1)*ncp+jj+1)]);
            uv[1]=0.25*(usX1max[2*(ii*ncp+jj)+1]+usX1max[2*(ii*ncp+jj+1)+1]+usX1max[2*((ii+1)*ncp+jj)+1]+usX1max[2*((ii+1)*ncp+jj+1)+1]);
            
            stepU=0.1*(knotU[jj+1+orderU]-knotU[jj]);
            stepV=0.1*(knotV[ii+1+orderV]-knotV[ii]);
            
            findNURBSbasisFunIso4xCP(ii, jj, 6, uv, stepU, stepV, degU, degV, cp, ncp, kcp, knotU, knotV, usX1max, basisVals, leftU, rightU, NU, leftV, rightV, NV);
            
            us[2*nus]=uv[0];
            us[2*nus+1]=uv[1];
            
            nus++;
            
        }
        
    }
    
}

static void NURBSsurfaceBasisX2Max(int degU, int degV, double *cp, int ncp, int kcp, double *knotU, double *knotV, double *us, double *usX1max, double *basisVals, double *leftU, double *rightU, double *NU, double *leftV, double *rightV, double *NV){
    
    /* NURBSsurfaceBasisX2Max( degU - degree of NURBS in u, degV - degree of NURBS in v, cp - pointer to control points, ncp - number of control points in u, kcp - number of control points in v, knotU - pointer to knot sequence in u, knotV - pointer to knot sequence in v, us - pointer to parameter values, usX1max - pointer to parameter values, basisVals - basis values at single max, leftU - pointer to array for function BasisFuns, rightU - pointer to array for function BasisFuns, NU - pointer to array for function BasisFuns, leftV - pointer to array for function BasisFuns, rightV - pointer to array for function BasisFuns, NV - pointer to array for function BasisFuns) */
    
    int ii, jj, nus, orderU, orderV;
    double uv[2], stepU, stepV;
    
    orderU=degU+1;
    orderV=degV+1;
    
    nus=0;
    
    /* ii=0,1,2,...,kcp-1 */
    
    for (ii = 0; ii <= (kcp-1); ii++){
        
        stepV=0.1*(knotV[ii+orderV]-knotV[ii]);
        
        /* jj=0,1,2,...,ncp-2 */
        
        for (jj = 0; jj <= (ncp-2); jj++){
            
            stepU=0.1*(knotU[jj+1+orderU]-knotU[jj]);
            
            uv[0]=0.75*usX1max[2*(ii*ncp+jj)]+0.25*usX1max[2*(ii*ncp+jj+1)];
            uv[1]=0.75*usX1max[2*(ii*ncp+jj)+1]+0.25*usX1max[2*(ii*ncp+jj+1)+1];
            
            findNURBSbasisFunIso2xCP(ii, jj, ii, jj+1, 0.75, 0.25, 18, uv, stepU, stepV, degU, degV, cp, ncp, kcp, knotU, knotV, usX1max, basisVals, leftU, rightU, NU, leftV, rightV, NV);
            
            us[2*nus]=uv[0];
            us[2*nus+1]=uv[1];
            
            nus++;
            
            uv[0]=0.666666666667*uv[0]+0.33333333333*usX1max[2*(ii*ncp+jj+1)];
            uv[1]=0.666666666667*uv[1]+0.33333333333*usX1max[2*(ii*ncp+jj+1)+1];
            
            findNURBSbasisFunIso2xCP(ii, jj, ii, jj+1, 0.5, 0.5, 16, uv, stepU, stepV, degU, degV, cp, ncp, kcp, knotU, knotV, usX1max, basisVals, leftU, rightU, NU, leftV, rightV, NV);
            
            us[2*nus]=uv[0];
            us[2*nus+1]=uv[1];
            
            nus++;
            
            uv[0]=0.5*uv[0]+0.5*usX1max[2*(ii*ncp+jj+1)];
            uv[1]=0.5*uv[1]+0.5*usX1max[2*(ii*ncp+jj+1)+1];
            
            findNURBSbasisFunIso2xCP(ii, jj, ii, jj+1, 0.25, 0.75, 14, uv, stepU, stepV, degU, degV, cp, ncp, kcp, knotU, knotV, usX1max, basisVals, leftU, rightU, NU, leftV, rightV, NV);
            
            us[2*nus]=uv[0];
            us[2*nus+1]=uv[1];
            
            nus++;
            
        }
        
    }
    
    /* jj=0,1,2,...,ncp-1 */
    
    for (jj = 0; jj <= (ncp-1); jj++){
        
        stepU=0.1*(knotU[jj+orderU]-knotU[jj]);
        
        /* ii=0,1,2,...,kcp-2 */
        
        for (ii = 0; ii <= (kcp-2); ii++){
            
            stepV=0.1*(knotV[ii+1+orderV]-knotV[ii]);
            
            uv[0]=0.75*usX1max[2*(ii*ncp+jj)]+0.25*usX1max[2*((ii+1)*ncp+jj)];
            uv[1]=0.75*usX1max[2*(ii*ncp+jj)+1]+0.25*usX1max[2*((ii+1)*ncp+jj)+1];
            
            findNURBSbasisFunIso2xCP(ii, jj, ii+1, jj, 0.75, 0.25, 18, uv, stepU, stepV, degU, degV, cp, ncp, kcp, knotU, knotV, usX1max, basisVals, leftU, rightU, NU, leftV, rightV, NV);
            
            us[2*nus]=uv[0];
            us[2*nus+1]=uv[1];
            
            nus++;
            
            uv[0]=0.666666666667*uv[0]+0.33333333333*usX1max[2*((ii+1)*ncp+jj)];
            uv[1]=0.666666666667*uv[1]+0.33333333333*usX1max[2*((ii+1)*ncp+jj)+1];
            
            findNURBSbasisFunIso2xCP(ii, jj, ii+1, jj, 0.5, 0.5, 16, uv, stepU, stepV, degU, degV, cp, ncp, kcp, knotU, knotV, usX1max, basisVals, leftU, rightU, NU, leftV, rightV, NV);
            
            us[2*nus]=uv[0];
            us[2*nus+1]=uv[1];
            
            nus++;
            
            uv[0]=0.5*uv[0]+0.5*usX1max[2*((ii+1)*ncp+jj)];
            uv[1]=0.5*uv[1]+0.5*usX1max[2*((ii+1)*ncp+jj)+1];
            
            findNURBSbasisFunIso2xCP(ii, jj, ii+1, jj, 0.25, 0.75, 14, uv, stepU, stepV, degU, degV, cp, ncp, kcp, knotU, knotV, usX1max, basisVals, leftU, rightU, NU, leftV, rightV, NV);
            
            us[2*nus]=uv[0];
            us[2*nus+1]=uv[1];
            
            nus++;
            
        }
        
    }
    
}

static void NURBSsurfaceBasisX4ScMax(int degU, int degV, double *cp, int ncp, int kcp, double *knotU, double *knotV, double *us, double *usX1max, double *basisVals, double *leftU, double *rightU, double *NU, double *leftV, double *rightV, double *NV){
    
    /* NURBSsurfaceBasisX4ScMax( degU - degree of NURBS in u, degV - degree of NURBS in v, cp - pointer to control points, ncp - number of control points in u, kcp - number of control points in v, knotU - pointer to knot sequence in u, knotV - pointer to knot sequence in v, us - pointer to parameter values, usX1max - pointer to parameter values, basisVals - basis values at single max, leftU - pointer to array for function BasisFuns, rightU - pointer to array for function BasisFuns, NU - pointer to array for function BasisFuns, leftV - pointer to array for function BasisFuns, rightV - pointer to array for function BasisFuns, NV - pointer to array for function BasisFuns) */
    
    int ii, jj, nus, orderU, orderV;
    double uv[2], stepU, stepV;
    
    orderU=degU+1;
    orderV=degV+1;
    
    nus=0;
    
    /* ii=0,1,2,...,kcp-2 */
    
    for (ii = 0; ii <= (kcp-2); ii++){
        
        stepV=0.1*(knotV[ii+1+orderV]-knotV[ii]);
        
        /* jj=0,1,2,...,ncp-2 */
        
        for (jj = 0; jj <= (ncp-2); jj++){
            
            stepU=0.1*(knotU[jj+1+orderU]-knotU[jj]);
            
            uv[0]=0.75*(0.75*usX1max[2*(ii*ncp+jj)]+0.25*usX1max[2*(ii*ncp+jj+1)])+0.25*(0.75*usX1max[2*((ii+1)*ncp+jj)]+0.25*usX1max[2*((ii+1)*ncp+jj+1)]);
            uv[1]=0.75*(0.75*usX1max[2*(ii*ncp+jj)+1]+0.25*usX1max[2*(ii*ncp+jj+1)+1])+0.25*(0.75*usX1max[2*((ii+1)*ncp+jj)+1]+0.25*usX1max[2*((ii+1)*ncp+jj+1)+1]);
            
            findNURBSbasisFunIso4xScCP(ii, jj, 0.75, 0.75, 12, uv, stepU, stepV, degU, degV, cp, ncp, kcp, knotU, knotV, usX1max, basisVals, leftU, rightU, NU, leftV, rightV, NV);
            
            us[2*nus]=uv[0];
            us[2*nus+1]=uv[1];
            
            nus++;
            
            uv[0]=0.75*(0.5*usX1max[2*(ii*ncp+jj)]+0.5*usX1max[2*(ii*ncp+jj+1)])+0.25*(0.5*usX1max[2*((ii+1)*ncp+jj)]+0.5*usX1max[2*((ii+1)*ncp+jj+1)]);
            uv[1]=0.75*(0.5*usX1max[2*(ii*ncp+jj)+1]+0.5*usX1max[2*(ii*ncp+jj+1)+1])+0.25*(0.5*usX1max[2*((ii+1)*ncp+jj)+1]+0.5*usX1max[2*((ii+1)*ncp+jj+1)+1]);
            
            findNURBSbasisFunIso4xScCP(ii, jj, 0.75, 0.5, 12, uv, stepU, stepV, degU, degV, cp, ncp, kcp, knotU, knotV, usX1max, basisVals, leftU, rightU, NU, leftV, rightV, NV);
            
            us[2*nus]=uv[0];
            us[2*nus+1]=uv[1];
            
            nus++;
            
            uv[0]=0.75*(0.25*usX1max[2*(ii*ncp+jj)]+0.75*usX1max[2*(ii*ncp+jj+1)])+0.25*(0.25*usX1max[2*((ii+1)*ncp+jj)]+0.75*usX1max[2*((ii+1)*ncp+jj+1)]);
            uv[1]=0.75*(0.25*usX1max[2*(ii*ncp+jj)+1]+0.75*usX1max[2*(ii*ncp+jj+1)+1])+0.25*(0.25*usX1max[2*((ii+1)*ncp+jj)+1]+0.75*usX1max[2*((ii+1)*ncp+jj+1)+1]);
            
            findNURBSbasisFunIso4xScCP(ii, jj, 0.75, 0.25, 12, uv, stepU, stepV, degU, degV, cp, ncp, kcp, knotU, knotV, usX1max, basisVals, leftU, rightU, NU, leftV, rightV, NV);
            
            us[2*nus]=uv[0];
            us[2*nus+1]=uv[1];
            
            nus++;
            
            uv[0]=0.5*(0.75*usX1max[2*(ii*ncp+jj)]+0.25*usX1max[2*(ii*ncp+jj+1)])+0.5*(0.75*usX1max[2*((ii+1)*ncp+jj)]+0.25*usX1max[2*((ii+1)*ncp+jj+1)]);
            uv[1]=0.5*(0.75*usX1max[2*(ii*ncp+jj)+1]+0.25*usX1max[2*(ii*ncp+jj+1)+1])+0.5*(0.75*usX1max[2*((ii+1)*ncp+jj)+1]+0.25*usX1max[2*((ii+1)*ncp+jj+1)+1]);
            
            findNURBSbasisFunIso4xScCP(ii, jj, 0.5, 0.75, 12, uv, stepU, stepV, degU, degV, cp, ncp, kcp, knotU, knotV, usX1max, basisVals, leftU, rightU, NU, leftV, rightV, NV);
            
            us[2*nus]=uv[0];
            us[2*nus+1]=uv[1];
            
            nus++;
            
            uv[0]=0.5*(0.25*usX1max[2*(ii*ncp+jj)]+0.75*usX1max[2*(ii*ncp+jj+1)])+0.5*(0.25*usX1max[2*((ii+1)*ncp+jj)]+0.75*usX1max[2*((ii+1)*ncp+jj+1)]);
            uv[1]=0.5*(0.25*usX1max[2*(ii*ncp+jj)+1]+0.75*usX1max[2*(ii*ncp+jj+1)+1])+0.5*(0.25*usX1max[2*((ii+1)*ncp+jj)+1]+0.75*usX1max[2*((ii+1)*ncp+jj+1)+1]);
            
            findNURBSbasisFunIso4xScCP(ii, jj, 0.5, 0.25, 12, uv, stepU, stepV, degU, degV, cp, ncp, kcp, knotU, knotV, usX1max, basisVals, leftU, rightU, NU, leftV, rightV, NV);
            
            us[2*nus]=uv[0];
            us[2*nus+1]=uv[1];
            
            nus++;
            
            uv[0]=0.25*(0.75*usX1max[2*(ii*ncp+jj)]+0.25*usX1max[2*(ii*ncp+jj+1)])+0.75*(0.75*usX1max[2*((ii+1)*ncp+jj)]+0.25*usX1max[2*((ii+1)*ncp+jj+1)]);
            uv[1]=0.25*(0.75*usX1max[2*(ii*ncp+jj)+1]+0.25*usX1max[2*(ii*ncp+jj+1)+1])+0.75*(0.75*usX1max[2*((ii+1)*ncp+jj)+1]+0.25*usX1max[2*((ii+1)*ncp+jj+1)+1]);
            
            findNURBSbasisFunIso4xScCP(ii, jj, 0.25, 0.75, 12, uv, stepU, stepV, degU, degV, cp, ncp, kcp, knotU, knotV, usX1max, basisVals, leftU, rightU, NU, leftV, rightV, NV);
            
            us[2*nus]=uv[0];
            us[2*nus+1]=uv[1];
            
            nus++;
            
            uv[0]=0.25*(0.5*usX1max[2*(ii*ncp+jj)]+0.5*usX1max[2*(ii*ncp+jj+1)])+0.75*(0.5*usX1max[2*((ii+1)*ncp+jj)]+0.5*usX1max[2*((ii+1)*ncp+jj+1)]);
            uv[1]=0.25*(0.5*usX1max[2*(ii*ncp+jj)+1]+0.5*usX1max[2*(ii*ncp+jj+1)+1])+0.75*(0.5*usX1max[2*((ii+1)*ncp+jj)+1]+0.5*usX1max[2*((ii+1)*ncp+jj+1)+1]);
            
            findNURBSbasisFunIso4xScCP(ii, jj, 0.25, 0.5, 12, uv, stepU, stepV, degU, degV, cp, ncp, kcp, knotU, knotV, usX1max, basisVals, leftU, rightU, NU, leftV, rightV, NV);
            
            us[2*nus]=uv[0];
            us[2*nus+1]=uv[1];
            
            nus++;
            
            uv[0]=0.25*(0.25*usX1max[2*(ii*ncp+jj)]+0.75*usX1max[2*(ii*ncp+jj+1)])+0.75*(0.25*usX1max[2*((ii+1)*ncp+jj)]+0.75*usX1max[2*((ii+1)*ncp+jj+1)]);
            uv[1]=0.25*(0.25*usX1max[2*(ii*ncp+jj)+1]+0.75*usX1max[2*(ii*ncp+jj+1)+1])+0.75*(0.25*usX1max[2*((ii+1)*ncp+jj)+1]+0.75*usX1max[2*((ii+1)*ncp+jj+1)+1]);
            
            findNURBSbasisFunIso4xScCP(ii, jj, 0.25, 0.25, 12, uv, stepU, stepV, degU, degV, cp, ncp, kcp, knotU, knotV, usX1max, basisVals, leftU, rightU, NU, leftV, rightV, NV);
            
            us[2*nus]=uv[0];
            us[2*nus+1]=uv[1];
            
            nus++;
            
        }
        
    }
    
}

static void NURBSsurfaceBasisX16ScMax(int degU, int degV, double *cp, int ncp, int kcp, double *knotU, double *knotV, double *us, double *usX1max, double *basisVals, double *leftU, double *rightU, double *NU, double *leftV, double *rightV, double *NV){
    
    /* NURBSsurfaceBasisX16ScMax( degU - degree of NURBS in u, degV - degree of NURBS in v, cp - pointer to control points, ncp - number of control points in u, kcp - number of control points in v, knotU - pointer to knot sequence in u, knotV - pointer to knot sequence in v, us - pointer to parameter values, usX1max - pointer to parameter values, basisVals - basis values at single max, leftU - pointer to array for function BasisFuns, rightU - pointer to array for function BasisFuns, NU - pointer to array for function BasisFuns, leftV - pointer to array for function BasisFuns, rightV - pointer to array for function BasisFuns, NV - pointer to array for function BasisFuns) */
    
    int i, j, ii, jj, nus, orderU, orderV;
    double uv[2], stepU, stepV, uScale, vScale, uScale2, vScale2;
    
    orderU=degU+1;
    orderV=degV+1;
    
    nus=0;
    
    /* ii=0,1,2,...,kcp-2 */
    
    for (ii = 0; ii <= (kcp-2); ii++){
        
        stepV=0.1*(knotV[ii+1+orderV]-knotV[ii]);
        
        /* jj=0,1,2,...,ncp-2 */
        
        for (jj = 0; jj <= (ncp-2); jj++){
            
            stepU=0.1*(knotU[jj+1+orderU]-knotU[jj]);
            
            vScale=0.125;
            
            for (i = 0; i < 4 ; i++){
                
                vScale2=1.0-vScale;
                
                uScale=0.125;
                
                for (j = 0; j < 4 ; j++){
                    
                    uScale2=1.0-uScale;
                    
                    uv[0]=vScale2*(uScale2*usX1max[2*(ii*ncp+jj)]+uScale*usX1max[2*(ii*ncp+jj+1)])+vScale*(uScale2*usX1max[2*((ii+1)*ncp+jj)]+uScale*usX1max[2*((ii+1)*ncp+jj+1)]);
                    uv[1]=vScale2*(uScale2*usX1max[2*(ii*ncp+jj)+1]+uScale*usX1max[2*(ii*ncp+jj+1)+1])+vScale*(uScale2*usX1max[2*((ii+1)*ncp+jj)+1]+uScale*usX1max[2*((ii+1)*ncp+jj+1)+1]);
                    
                    findNURBSbasisFunIso4xScCP(ii, jj, vScale2, uScale2, 12, uv, stepU, stepV, degU, degV, cp, ncp, kcp, knotU, knotV, usX1max, basisVals, leftU, rightU, NU, leftV, rightV, NV);
                    
                    us[2*nus]=uv[0];
                    us[2*nus+1]=uv[1];
                    
                    nus++;
                    
                    uScale+=0.25;
                    
                }
                
                vScale+=0.25;
                
            }
            
        }
        
    }
    
}

static void NURBSsurfaceBasisValues(int degU, int degV, double *cp, int ncp, int kcp, double *knotU, double *knotV, double *us, double *nrbBasisVals, double *leftU, double *rightU, double *NU, double *leftV, double *rightV, double *NV){
    
    /* NURBSsurfaceBasisValues( degU - degree of NURBS in u, degV - degree of NURBS in v, cp - pointer to control points, ncp - number of control points in u, kcp - number of control points in v, knotU - pointer to knot sequence in u, knotV - pointer to knot sequence in v, us - pointer to parameter values, nrbBasisVals - , leftU - pointer to array for function BasisFuns, rightU - pointer to array for function BasisFuns, NU - pointer to array for function BasisFuns, leftV - pointer to array for function BasisFuns, rightV - pointer to array for function BasisFuns, NV - pointer to array for function BasisFuns) */
    
    int i, j, ii, jj, spanU, spanV, ind, ind2, fourncp, myint, nus, cpStrt, numCP, orderU, orderV;
    double wgh;
    
    fourncp=4*ncp;
    orderU=degU+1;
    orderV=degV+1;
    
    numCP=ncp*kcp;
    
    for (jj = 0; jj < numCP*numCP; jj++){
        nrbBasisVals[jj]=0.0;
    }
    
    /* ii=0  jj=0 */
    
    nrbBasisVals[0]=1.0;
    
    /* ii=0  jj=1,2,...,ncp-2 */
    
    nus=1;
    cpStrt=numCP;
    
    ind2=3;
    
    for (jj = 1; jj <= (ncp-2); jj++){
        
        spanU = FindSpan(ncp, degU, us[2*nus], knotU);
        BasisFuns(spanU, us[2*nus], degU, knotU, NU, leftU, rightU);
        
        ind = spanU - degU;
        
        myint=ind*4+ind2;
        
        wgh=0.0;
        for (j = 0; j <= degU; j++){
            wgh += NU[j] * cp[j*4+myint];
        }
        for (j = 0; j <= degU; j++){
            nrbBasisVals[cpStrt+ind+j] = NU[j] * cp[j*4+myint]/wgh;
        }
        
        nus++;
        cpStrt+=numCP;
        
    }
    
    /* ii=0  jj=ncp-1 */
    
    nrbBasisVals[cpStrt+ncp-1]=1.0;
    
    nus++;
    cpStrt+=numCP;
    
    /* ii=1,2,...,kcp-2 */
    
    for (ii = 1; ii <= (kcp-2); ii++){
        
        /* jj=0 */
        
        spanV = FindSpan(kcp, degV, us[2*nus+1], knotV);
        BasisFuns(spanV, us[2*nus+1], degV, knotV, NV, leftV, rightV);
        
        ind2 = spanV - degV;
        myint=ind2*fourncp+3;
        
        wgh=0.0;
        for (i = 0; i <= degV; i++){
            wgh += NV[i] * cp[i*fourncp+myint];
        }
        for (i = 0; i <= degV; i++){
            nrbBasisVals[cpStrt+(ind2+i)*ncp] = NV[i] * cp[i*fourncp+myint]/wgh;
        }
        
        nus++;
        cpStrt+=numCP;
        
        /* jj=1,2,...,ncp-2 */
        
        for (jj = 1; jj <= (ncp-2); jj++){
            
            spanU = FindSpan(ncp, degU, us[2*nus], knotU);
            BasisFuns(spanU, us[2*nus], degU, knotU, NU, leftU, rightU);
            
            ind = spanU - degU;
            
            spanV = FindSpan(kcp, degV, us[2*nus+1], knotV);
            BasisFuns(spanV, us[2*nus+1], degV, knotV, NV, leftV, rightV);
            
            ind2 = spanV - degV;
            myint=ind2*fourncp+ind*4+3;
            
            wgh=0.0;
            for (i = 0; i <= degV; i++){
                for (j = 0; j <= degU; j++){
                    wgh += NV[i] * NU[j] * cp[i*fourncp+j*4+myint];
                }
            }
            for (i = 0; i <= degV; i++){
                for (j = 0; j <= degU; j++){
                    nrbBasisVals[cpStrt+(ind2+i)*ncp+ind+j] = NV[i] * NU[j] * cp[i*fourncp+j*4+myint]/wgh;
                }
            }
            
            nus++;
            cpStrt+=numCP;
            
        }
        
        /* jj=ncp-1 */
        
        spanV = FindSpan(kcp, degV, us[2*nus+1], knotV);
        BasisFuns(spanV, us[2*nus+1], degV, knotV, NV, leftV, rightV);
        
        ind2 = spanV - degV;
        myint=(ind2+1)*fourncp-1;
        
        wgh=0.0;
        for (i = 0; i <= degV; i++){
            wgh += NV[i] * cp[i*fourncp+myint];
        }
        for (i = 0; i <= degV; i++){
            nrbBasisVals[cpStrt+(ind2+i+1)*ncp-1] = NV[i] * cp[i*fourncp+myint]/wgh;
        }
        
        nus++;
        cpStrt+=numCP;
        
    }
    
    /* ii=kcp-1  jj=0 */
    
    nrbBasisVals[cpStrt+ncp*(kcp-1)]=1.0;
    
    nus++;
    cpStrt+=numCP;
    
    /* ii=kcp-1  jj=1,2,...,ncp-2 */
    
    ind2=fourncp*(kcp-1)+3;
    
    for (jj = 1; jj <= (ncp-2); jj++){
        
        spanU = FindSpan(ncp, degU, us[2*nus], knotU);
        BasisFuns(spanU, us[2*nus], degU, knotU, NU, leftU, rightU);
        
        ind = spanU - degU;
        
        myint=ind*4+ind2;
        
        wgh=0.0;
        for (j = 0; j <= degU; j++){
            wgh += NU[j] * cp[j*4+myint];
        }
        for (j = 0; j <= degU; j++){
            nrbBasisVals[cpStrt+ncp*(kcp-1)+ind+j] = NU[j] * cp[j*4+myint]/wgh;
        }
        
        nus++;
        cpStrt+=numCP;
        
    }
    
    /* ii=kcp-1  jj=ncp-1 */
    
    nrbBasisVals[cpStrt+numCP-1]=1.0;
    
}

static void closestNURBSsrfPnt2CP(int iters, int degU, int degV, double *cp, int ncp, int kcp, double *knotU, double *knotV, double *us, mxArray *nrbStruct, mxArray *nrbDerStruct, mxArray *nrbDer2Struct, double *explWghs, double *corrSrfNrmls, double *UVcp, double *leftU, double *rightU, double *NU, double *leftV, double *rightV, double *NV){
    
    /* closestNURBSsrfPnt2CP(iters - maximum number of iterations when searching for closest point, degU - degree of offset surface, degV - degree of offset surface, cp - offset control points, ncp - number of offset control points, kcp - number of offset control points, knotU - offset knot vector, knotV - offset knot vector, us - parameter values of original points, nrbStruct - original NURBS surface, nrbDerStruct - original derivative, nrbDer2Struct - original second derivative, corrSrfNrmls - original computed surface normals, UVcp - parameter values, leftU, rightU, NU, leftV, rightV, NV) */
    
    int ii, jj, i, j, k=0, threek=0;
    double tmpDist, minDist, controlPnt[3], wgh, uv[2], bspPnts[4], diffPnt[3], evalPnt[3], evalDeru[3], evalDerv[3], evalDeruu[3], evalDeruv[3], evalDervv[3], srfNrml[3];
    double uStart, uEnd, vStart, vEnd, stcri, udiff, vdiff, difru, difrv, newtUlim, newtVlim, newTdir[2], Hess[3], grad[2], explsign;
    int spanU, spanV, ind, ind2, myint, fourncp, bool;
    
    fourncp=4*ncp;
    
    uStart=knotU[0];
    uEnd=knotU[ncp];
    vStart=knotV[0];
    vEnd=knotV[kcp];
    
    udiff=uEnd-uStart;
    vdiff=vEnd-vStart;
    
    difru=1e-12*udiff;
    difrv=1e-12*vdiff;
    
    newtUlim=0.1*udiff;
    newtVlim=0.1*vdiff;
    
    stcri=1e-8*(udiff+vdiff);
    
    
    /* ii = 0, jj=0 */
    
    uv[0]=us[2*k];
    uv[1]=us[2*k+1];
    
    UVcp[2*k]=uv[0];
    UVcp[2*k+1]=uv[1];
    
    /* Compute surface normal at the corner point */
    
    nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
    
    evalDeruu[0]=evalDeru[0]*evalDeru[0]+evalDeru[1]*evalDeru[1]+evalDeru[2]*evalDeru[2];
    evalDervv[0]=evalDerv[0]*evalDerv[0]+evalDerv[1]*evalDerv[1]+evalDerv[2]*evalDerv[2];
    
    if (evalDeruu[0]<1e-20*evalDervv[0]){
        
        /* u-derivative to small to be accurate, estimate a new one */
        
        if (uv[1]>(vEnd-10.1*difrv)){
            explsign=-1.0;
        }
        else {
            explsign=1.0;
        }
        
        srfNrml[0]=0.0;
        srfNrml[1]=0.0;
        srfNrml[2]=0.0;
        
        for (i = 0; i < 10; i++){
            
            uv[1]+=explsign*difrv;
            
            nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
            
            evalDeruu[0]=evalDeru[1]*evalDerv[2]-evalDeru[2]*evalDerv[1];
            evalDeruu[1]=evalDeru[2]*evalDerv[0]-evalDeru[0]*evalDerv[2];
            evalDeruu[2]=evalDeru[0]*evalDerv[1]-evalDeru[1]*evalDerv[0];
            
            tmpDist=sqrt(evalDeruu[0]*evalDeruu[0]+evalDeruu[1]*evalDeruu[1]+evalDeruu[2]*evalDeruu[2]);
            
            srfNrml[0]+=explWghs[i]*evalDeruu[0]/tmpDist;
            srfNrml[1]+=explWghs[i]*evalDeruu[1]/tmpDist;
            srfNrml[2]+=explWghs[i]*evalDeruu[2]/tmpDist;
            
        }
        
        tmpDist=sqrt(srfNrml[0]*srfNrml[0]+srfNrml[1]*srfNrml[1]+srfNrml[2]*srfNrml[2]);
        
        srfNrml[0]=srfNrml[0]/tmpDist;
        srfNrml[1]=srfNrml[1]/tmpDist;
        srfNrml[2]=srfNrml[2]/tmpDist;
        
    }
    else if (evalDervv[0]<1e-20*evalDeruu[0]){
        
        /* v-derivative to small to be accurate, estimate a new one */
        
        if (uv[0]>(uEnd-10.1*difru)){
            explsign=-1.0;
        }
        else {
            explsign=1.0;
        }
        
        srfNrml[0]=0.0;
        srfNrml[1]=0.0;
        srfNrml[2]=0.0;
        
        for (i = 0; i < 10; i++){
            
            uv[0]+=explsign*difru;
            
            nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
            
            evalDeruu[0]=evalDeru[1]*evalDerv[2]-evalDeru[2]*evalDerv[1];
            evalDeruu[1]=evalDeru[2]*evalDerv[0]-evalDeru[0]*evalDerv[2];
            evalDeruu[2]=evalDeru[0]*evalDerv[1]-evalDeru[1]*evalDerv[0];
            
            tmpDist=sqrt(evalDeruu[0]*evalDeruu[0]+evalDeruu[1]*evalDeruu[1]+evalDeruu[2]*evalDeruu[2]);
            
            srfNrml[0]+=explWghs[i]*evalDeruu[0]/tmpDist;
            srfNrml[1]+=explWghs[i]*evalDeruu[1]/tmpDist;
            srfNrml[2]+=explWghs[i]*evalDeruu[2]/tmpDist;
            
        }
        
        tmpDist=sqrt(srfNrml[0]*srfNrml[0]+srfNrml[1]*srfNrml[1]+srfNrml[2]*srfNrml[2]);
        
        srfNrml[0]=srfNrml[0]/tmpDist;
        srfNrml[1]=srfNrml[1]/tmpDist;
        srfNrml[2]=srfNrml[2]/tmpDist;
        
    }
    else {
        
        /* just compute the surface normal */
        
        srfNrml[0]=evalDeru[1]*evalDerv[2]-evalDeru[2]*evalDerv[1];
        srfNrml[1]=evalDeru[2]*evalDerv[0]-evalDeru[0]*evalDerv[2];
        srfNrml[2]=evalDeru[0]*evalDerv[1]-evalDeru[1]*evalDerv[0];
        
        tmpDist=sqrt(srfNrml[0]*srfNrml[0]+srfNrml[1]*srfNrml[1]+srfNrml[2]*srfNrml[2]);
        
        if (tmpDist>1e-50){
            
            srfNrml[0]=srfNrml[0]/tmpDist;
            srfNrml[1]=srfNrml[1]/tmpDist;
            srfNrml[2]=srfNrml[2]/tmpDist;
            
        }
        else {
            
            srfNrml[0]=0.0;
            srfNrml[1]=0.0;
            srfNrml[2]=1.0;
            
        }
        
    }
    
    corrSrfNrmls[threek]=srfNrml[0];
    corrSrfNrmls[threek+1]=srfNrml[1];
    corrSrfNrmls[threek+2]=srfNrml[2];
    
    k++;
    threek+=3;
    
    /* ii = 0, jj=1,2,...,ncp-2 */
    
    for (jj = 1; jj <= (ncp-2); jj++){
        
        /* Initial parameters */
        
        uv[0]=us[2*k];
        uv[1]=us[2*k+1];
        
        nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
        
        if ((evalDeru[0]*evalDeru[0]+evalDeru[1]*evalDeru[1]+evalDeru[2]*evalDeru[2])<1e-16*(evalDerv[0]*evalDerv[0]+evalDerv[1]*evalDerv[1]+evalDerv[2]*evalDerv[2])){
            
            /* Surface normal not defined, using extrapolation */
            
            uv[1]+=10.0*difrv;
            explsign=0.0;
            
            for (ii = 9; ii >= 0; ii--){
                
                /* Compute unweighted control point */
                
                spanV = FindSpan(kcp, degV, uv[1], knotV);
                BasisFuns(spanV, uv[1], degV, knotV, NV, leftV, rightV);
                
                ind2 = spanV - degV;
                myint=ind2*fourncp+jj*4;
                
                bspPnts[0]=0.0;
                bspPnts[1]=0.0;
                bspPnts[2]=0.0;
                bspPnts[3]=0.0;
                for (i = 0; i <= degV; i++){
                    bspPnts[0] += NV[i] * cp[i*fourncp+myint];
                    bspPnts[1] += NV[i] * cp[i*fourncp+myint+1];
                    bspPnts[2] += NV[i] * cp[i*fourncp+myint+2];
                    bspPnts[3] += NV[i] * cp[i*fourncp+myint+3];
                }
                
                controlPnt[0]=bspPnts[0]/bspPnts[3];
                controlPnt[1]=bspPnts[1]/bspPnts[3];
                controlPnt[2]=bspPnts[2]/bspPnts[3];
                
                /* Iterate to find the closest NURBS surface point */
                
                bool=0;
                
                for (i = 0; i < iters; i++){
                    
                    if (bool){
                        break;
                    }
                    
                    /* Compute gradient and Hessian */
                    
                    nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                    
                    diffPnt[0]=evalPnt[0]-controlPnt[0];
                    diffPnt[1]=evalPnt[1]-controlPnt[1];
                    diffPnt[2]=evalPnt[2]-controlPnt[2];
                    
                    minDist=diffPnt[0]*diffPnt[0]+diffPnt[1]*diffPnt[1]+diffPnt[2]*diffPnt[2];
                    
                    grad[0]=evalDeru[0]*diffPnt[0]+evalDeru[1]*diffPnt[1]+evalDeru[2]*diffPnt[2];
                    
                    Hess[0]=evalDeruu[0]*diffPnt[0]+evalDeruu[1]*diffPnt[1]+evalDeruu[2]*diffPnt[2] + evalDeru[0]*evalDeru[0]+evalDeru[1]*evalDeru[1]+evalDeru[2]*evalDeru[2];
                    
                    if (1e12*Hess[0]<=fabs(grad[0])){
                        newTdir[0]=-grad[0];
                    }
                    else {
                        newTdir[0]=-grad[0]/Hess[0];
                    }
                    
                    /* Scale search direction if neccecary */
                    
                    if (newTdir[0]<-newtUlim){
                        newTdir[0]=-newtUlim;
                    }
                    else if (newTdir[0]>newtUlim){
                        newTdir[0]=newtUlim;
                    }
                    
                    /* Apply line search */
                    
                    evalDeru[0]=0.5*(newTdir[0]*grad[0]);
                    
                    wgh=1.0;
                    bool=1;
                    evalDeruv[1]=uv[1];
                    
                    for (j = 0; j < 15; j++){
                        
                        evalDeruv[0]=uv[0]+wgh*newTdir[0];
                        
                        oneBspEval2(degU, degV, mxGetPr(mxGetField(nrbStruct, 0, "coefs")), ncp, kcp, mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 1)), evalDeruv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                        
                        tmpDist=pwr2(bspPnts[0]/bspPnts[3]-controlPnt[0])+pwr2(bspPnts[1]/bspPnts[3]-controlPnt[1])+pwr2(bspPnts[2]/bspPnts[3]-controlPnt[2]);
                        
                        if (tmpDist<(minDist+wgh*evalDeru[0])){
                            uv[0]=evalDeruv[0];
                            
                            if (wgh*(fabs(newTdir[0]))>stcri){
                                bool=0;
                            }
                            break;
                        }
                        else {
                            wgh=wgh*0.75;
                        }
                        
                    }
                    
                    /* Parameter values must be inside the domain */
                    
                    if (uv[0]<uStart){
                        uv[0]=uStart;
                    }
                    else if (uv[0]>uEnd){
                        uv[0]=uEnd;
                    }
                    
                }
                
                uv[1]-=difrv;
                explsign+=explWghs[ii]*uv[0];
                
            }
            
            uv[0]=explsign;
            uv[1]=us[2*k+1];
            
        }
        else {
            
            /* Surface normal exists */
            
            /* Compute unweighted control point */
            
            controlPnt[0]=cp[4*k]/cp[4*k+3];
            controlPnt[1]=cp[4*k+1]/cp[4*k+3];
            controlPnt[2]=cp[4*k+2]/cp[4*k+3];
            
            /* Iterate to find the closest NURBS surface point to the control point */
            
            bool=0;
            
            for (i = 0; i < iters; i++){
                
                if (bool){
                    break;
                }
                
                /* Compute gradient and Hessian */
                
                nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                
                diffPnt[0]=evalPnt[0]-controlPnt[0];
                diffPnt[1]=evalPnt[1]-controlPnt[1];
                diffPnt[2]=evalPnt[2]-controlPnt[2];
                
                minDist=diffPnt[0]*diffPnt[0]+diffPnt[1]*diffPnt[1]+diffPnt[2]*diffPnt[2];
                
                grad[0]=evalDeru[0]*diffPnt[0]+evalDeru[1]*diffPnt[1]+evalDeru[2]*diffPnt[2];
                
                Hess[0]=evalDeruu[0]*diffPnt[0]+evalDeruu[1]*diffPnt[1]+evalDeruu[2]*diffPnt[2] + evalDeru[0]*evalDeru[0]+evalDeru[1]*evalDeru[1]+evalDeru[2]*evalDeru[2];
                
                if (1e12*Hess[0]<=fabs(grad[0])){
                    newTdir[0]=-grad[0];
                }
                else {
                    newTdir[0]=-grad[0]/Hess[0];
                }
                
                /* Scale search direction if neccecary */
                
                if (newTdir[0]<-newtUlim){
                    newTdir[0]=-newtUlim;
                }
                else if (newTdir[0]>newtUlim){
                    newTdir[0]=newtUlim;
                }
                
                /* Apply line search */
                
                evalDeru[0]=0.5*(newTdir[0]*grad[0]);
                
                wgh=1.0;
                bool=1;
                evalDeruv[1]=uv[1];
                
                for (j = 0; j < 15; j++){
                    
                    evalDeruv[0]=uv[0]+wgh*newTdir[0];
                    
                    oneBspEval2(degU, degV, mxGetPr(mxGetField(nrbStruct, 0, "coefs")), ncp, kcp, mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 1)), evalDeruv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                    
                    tmpDist=pwr2(bspPnts[0]/bspPnts[3]-controlPnt[0])+pwr2(bspPnts[1]/bspPnts[3]-controlPnt[1])+pwr2(bspPnts[2]/bspPnts[3]-controlPnt[2]);
                    
                    if (tmpDist<(minDist+wgh*evalDeru[0])){
                        uv[0]=evalDeruv[0];
                        
                        if (wgh*(fabs(newTdir[0]))>stcri){
                            bool=0;
                        }
                        break;
                    }
                    else {
                        wgh=wgh*0.75;
                    }
                    
                }
                
                /* Parameter values must be inside the domain */
                
                if (uv[0]<uStart){
                    uv[0]=uStart;
                }
                else if (uv[0]>uEnd){
                    uv[0]=uEnd;
                }
                
            }
            
        }
        
        UVcp[2*k]=uv[0];
        UVcp[2*k+1]=uv[1];
        
        /* Compute surface normal at the closest point */
        
        nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
        
        evalDeruu[0]=evalDeru[0]*evalDeru[0]+evalDeru[1]*evalDeru[1]+evalDeru[2]*evalDeru[2];
        evalDervv[0]=evalDerv[0]*evalDerv[0]+evalDerv[1]*evalDerv[1]+evalDerv[2]*evalDerv[2];
        
        if (evalDeruu[0]<1e-20*evalDervv[0]){
            
            /* u-derivative to small to be accurate, estimate a new one */
            
            if (uv[1]>(vEnd-10.1*difrv)){
                explsign=-1.0;
            }
            else {
                explsign=1.0;
            }
            
            srfNrml[0]=0.0;
            srfNrml[1]=0.0;
            srfNrml[2]=0.0;
            
            for (i = 0; i < 10; i++){
                
                uv[1]+=explsign*difrv;
                
                nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                
                evalDeruu[0]=evalDeru[1]*evalDerv[2]-evalDeru[2]*evalDerv[1];
                evalDeruu[1]=evalDeru[2]*evalDerv[0]-evalDeru[0]*evalDerv[2];
                evalDeruu[2]=evalDeru[0]*evalDerv[1]-evalDeru[1]*evalDerv[0];
                
                tmpDist=sqrt(evalDeruu[0]*evalDeruu[0]+evalDeruu[1]*evalDeruu[1]+evalDeruu[2]*evalDeruu[2]);
                
                srfNrml[0]+=explWghs[i]*evalDeruu[0]/tmpDist;
                srfNrml[1]+=explWghs[i]*evalDeruu[1]/tmpDist;
                srfNrml[2]+=explWghs[i]*evalDeruu[2]/tmpDist;
                
            }
            
            tmpDist=sqrt(srfNrml[0]*srfNrml[0]+srfNrml[1]*srfNrml[1]+srfNrml[2]*srfNrml[2]);
            
            srfNrml[0]=srfNrml[0]/tmpDist;
            srfNrml[1]=srfNrml[1]/tmpDist;
            srfNrml[2]=srfNrml[2]/tmpDist;
            
        }
        else if (evalDervv[0]<1e-20*evalDeruu[0]){
            
            /* v-derivative to small to be accurate, estimate a new one */
            
            if (uv[0]>(uEnd-10.1*difru)){
                explsign=-1.0;
            }
            else {
                explsign=1.0;
            }
            
            srfNrml[0]=0.0;
            srfNrml[1]=0.0;
            srfNrml[2]=0.0;
            
            for (i = 0; i < 10; i++){
                
                uv[0]+=explsign*difru;
                
                nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                
                evalDeruu[0]=evalDeru[1]*evalDerv[2]-evalDeru[2]*evalDerv[1];
                evalDeruu[1]=evalDeru[2]*evalDerv[0]-evalDeru[0]*evalDerv[2];
                evalDeruu[2]=evalDeru[0]*evalDerv[1]-evalDeru[1]*evalDerv[0];
                
                tmpDist=sqrt(evalDeruu[0]*evalDeruu[0]+evalDeruu[1]*evalDeruu[1]+evalDeruu[2]*evalDeruu[2]);
                
                srfNrml[0]+=explWghs[i]*evalDeruu[0]/tmpDist;
                srfNrml[1]+=explWghs[i]*evalDeruu[1]/tmpDist;
                srfNrml[2]+=explWghs[i]*evalDeruu[2]/tmpDist;
                
            }
            
            tmpDist=sqrt(srfNrml[0]*srfNrml[0]+srfNrml[1]*srfNrml[1]+srfNrml[2]*srfNrml[2]);
            
            srfNrml[0]=srfNrml[0]/tmpDist;
            srfNrml[1]=srfNrml[1]/tmpDist;
            srfNrml[2]=srfNrml[2]/tmpDist;
            
        }
        else {
            
            /* just compute the surface normal */
            
            srfNrml[0]=evalDeru[1]*evalDerv[2]-evalDeru[2]*evalDerv[1];
            srfNrml[1]=evalDeru[2]*evalDerv[0]-evalDeru[0]*evalDerv[2];
            srfNrml[2]=evalDeru[0]*evalDerv[1]-evalDeru[1]*evalDerv[0];
            
            tmpDist=sqrt(srfNrml[0]*srfNrml[0]+srfNrml[1]*srfNrml[1]+srfNrml[2]*srfNrml[2]);
            
            if (tmpDist>1e-50){
                
                srfNrml[0]=srfNrml[0]/tmpDist;
                srfNrml[1]=srfNrml[1]/tmpDist;
                srfNrml[2]=srfNrml[2]/tmpDist;
                
            }
            else {
                
                srfNrml[0]=0.0;
                srfNrml[1]=0.0;
                srfNrml[2]=1.0;
                
            }
            
        }
        
        corrSrfNrmls[threek]=srfNrml[0];
        corrSrfNrmls[threek+1]=srfNrml[1];
        corrSrfNrmls[threek+2]=srfNrml[2];
        
        k++;
        threek+=3;
        
    }
    
    /* ii = 0, jj=ncp-1 */
    
    uv[0]=us[2*k];
    uv[1]=us[2*k+1];
    
    UVcp[2*k]=uv[0];
    UVcp[2*k+1]=uv[1];
    
    /* Compute surface normal at the corner point */
    
    nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
    
    evalDeruu[0]=evalDeru[0]*evalDeru[0]+evalDeru[1]*evalDeru[1]+evalDeru[2]*evalDeru[2];
    evalDervv[0]=evalDerv[0]*evalDerv[0]+evalDerv[1]*evalDerv[1]+evalDerv[2]*evalDerv[2];
    
    if (evalDeruu[0]<1e-20*evalDervv[0]){
        
        /* u-derivative to small to be accurate, estimate a new one */
        
        if (uv[1]>(vEnd-10.1*difrv)){
            explsign=-1.0;
        }
        else {
            explsign=1.0;
        }
        
        srfNrml[0]=0.0;
        srfNrml[1]=0.0;
        srfNrml[2]=0.0;
        
        for (i = 0; i < 10; i++){
            
            uv[1]+=explsign*difrv;
            
            nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
            
            evalDeruu[0]=evalDeru[1]*evalDerv[2]-evalDeru[2]*evalDerv[1];
            evalDeruu[1]=evalDeru[2]*evalDerv[0]-evalDeru[0]*evalDerv[2];
            evalDeruu[2]=evalDeru[0]*evalDerv[1]-evalDeru[1]*evalDerv[0];
            
            tmpDist=sqrt(evalDeruu[0]*evalDeruu[0]+evalDeruu[1]*evalDeruu[1]+evalDeruu[2]*evalDeruu[2]);
            
            srfNrml[0]+=explWghs[i]*evalDeruu[0]/tmpDist;
            srfNrml[1]+=explWghs[i]*evalDeruu[1]/tmpDist;
            srfNrml[2]+=explWghs[i]*evalDeruu[2]/tmpDist;
            
        }
        
        tmpDist=sqrt(srfNrml[0]*srfNrml[0]+srfNrml[1]*srfNrml[1]+srfNrml[2]*srfNrml[2]);
        
        srfNrml[0]=srfNrml[0]/tmpDist;
        srfNrml[1]=srfNrml[1]/tmpDist;
        srfNrml[2]=srfNrml[2]/tmpDist;
        
    }
    else if (evalDervv[0]<1e-20*evalDeruu[0]){
        
        /* v-derivative to small to be accurate, estimate a new one */
        
        if (uv[0]>(uEnd-10.1*difru)){
            explsign=-1.0;
        }
        else {
            explsign=1.0;
        }
        
        srfNrml[0]=0.0;
        srfNrml[1]=0.0;
        srfNrml[2]=0.0;
        
        for (i = 0; i < 10; i++){
            
            uv[0]+=explsign*difru;
            
            nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
            
            evalDeruu[0]=evalDeru[1]*evalDerv[2]-evalDeru[2]*evalDerv[1];
            evalDeruu[1]=evalDeru[2]*evalDerv[0]-evalDeru[0]*evalDerv[2];
            evalDeruu[2]=evalDeru[0]*evalDerv[1]-evalDeru[1]*evalDerv[0];
            
            tmpDist=sqrt(evalDeruu[0]*evalDeruu[0]+evalDeruu[1]*evalDeruu[1]+evalDeruu[2]*evalDeruu[2]);
            
            srfNrml[0]+=explWghs[i]*evalDeruu[0]/tmpDist;
            srfNrml[1]+=explWghs[i]*evalDeruu[1]/tmpDist;
            srfNrml[2]+=explWghs[i]*evalDeruu[2]/tmpDist;
            
        }
        
        tmpDist=sqrt(srfNrml[0]*srfNrml[0]+srfNrml[1]*srfNrml[1]+srfNrml[2]*srfNrml[2]);
        
        srfNrml[0]=srfNrml[0]/tmpDist;
        srfNrml[1]=srfNrml[1]/tmpDist;
        srfNrml[2]=srfNrml[2]/tmpDist;
        
    }
    else {
        
        /* just compute the surface normal */
        
        srfNrml[0]=evalDeru[1]*evalDerv[2]-evalDeru[2]*evalDerv[1];
        srfNrml[1]=evalDeru[2]*evalDerv[0]-evalDeru[0]*evalDerv[2];
        srfNrml[2]=evalDeru[0]*evalDerv[1]-evalDeru[1]*evalDerv[0];
        
        tmpDist=sqrt(srfNrml[0]*srfNrml[0]+srfNrml[1]*srfNrml[1]+srfNrml[2]*srfNrml[2]);
        
        if (tmpDist>1e-50){
            
            srfNrml[0]=srfNrml[0]/tmpDist;
            srfNrml[1]=srfNrml[1]/tmpDist;
            srfNrml[2]=srfNrml[2]/tmpDist;
            
        }
        else {
            
            srfNrml[0]=0.0;
            srfNrml[1]=0.0;
            srfNrml[2]=1.0;
            
        }
        
    }
    
    corrSrfNrmls[threek]=srfNrml[0];
    corrSrfNrmls[threek+1]=srfNrml[1];
    corrSrfNrmls[threek+2]=srfNrml[2];
    
    k++;
    threek+=3;
    
    /* ii = 1,2,...,kcp-2, jj=0,1,2,...,ncp-2,ncp-1 */
    
    for (ii = 1; ii <= (kcp-2); ii++){
        
        /* Initial parameters */
        
        uv[0]=us[2*k];
        uv[1]=us[2*k+1];
        
        nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
        
        if ((evalDerv[0]*evalDerv[0]+evalDerv[1]*evalDerv[1]+evalDerv[2]*evalDerv[2])<1e-16*(evalDeru[0]*evalDeru[0]+evalDeru[1]*evalDeru[1]+evalDeru[2]*evalDeru[2])){
            
            /* Surface normal not defined, using extrapolation */
            
            uv[0]+=10.0*difru;
            explsign=0.0;
            
            for (jj = 9; jj >= 0; jj--){
                
                /* Compute unweighted control point */
                
                spanU = FindSpan(ncp, degU, uv[0], knotU);
                BasisFuns(spanU, uv[0], degU, knotU, NU, leftU, rightU);
                
                ind = spanU - degU;
                myint=ii*fourncp+ind*4;
                
                bspPnts[0]=0.0;
                bspPnts[1]=0.0;
                bspPnts[2]=0.0;
                bspPnts[3]=0.0;
                for (j = 0; j <= degU; j++){
                    bspPnts[0] += NU[j] * cp[j*4+myint];
                    bspPnts[1] += NU[j] * cp[j*4+myint+1];
                    bspPnts[2] += NU[j] * cp[j*4+myint+2];
                    bspPnts[3] += NU[j] * cp[j*4+myint+3];
                }
                
                controlPnt[0]=bspPnts[0]/bspPnts[3];
                controlPnt[1]=bspPnts[1]/bspPnts[3];
                controlPnt[2]=bspPnts[2]/bspPnts[3];
                
                /* Iterate to find the closest NURBS surface point */
                
                bool=0;
                
                for (i = 0; i < iters; i++){
                    
                    if (bool){
                        break;
                    }
                    
                    /* Compute gradient and Hessian */
                    
                    nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                    
                    diffPnt[0]=evalPnt[0]-controlPnt[0];
                    diffPnt[1]=evalPnt[1]-controlPnt[1];
                    diffPnt[2]=evalPnt[2]-controlPnt[2];
                    
                    minDist=diffPnt[0]*diffPnt[0]+diffPnt[1]*diffPnt[1]+diffPnt[2]*diffPnt[2];
                    
                    grad[1]=evalDerv[0]*diffPnt[0]+evalDerv[1]*diffPnt[1]+evalDerv[2]*diffPnt[2];
                    
                    Hess[2]=evalDervv[0]*diffPnt[0]+evalDervv[1]*diffPnt[1]+evalDervv[2]*diffPnt[2] + evalDerv[0]*evalDerv[0]+evalDerv[1]*evalDerv[1]+evalDerv[2]*evalDerv[2];
                    
                    if (1e12*Hess[2]<=fabs(grad[1])){
                        newTdir[1]=-grad[1];
                    }
                    else {
                        newTdir[1]=-grad[1]/Hess[2];
                    }
                    
                    /* Scale search direction if neccecary */
                    
                    if (newTdir[1]<-newtVlim){
                        newTdir[1]=-newtVlim;
                    }
                    else if (newTdir[1]>newtVlim){
                        newTdir[1]=newtVlim;
                    }
                    
                    /* Apply line search */
                    
                    evalDeru[0]=0.5*(newTdir[1]*grad[1]);
                    
                    wgh=1.0;
                    bool=1;
                    evalDeruv[0]=uv[0];
                    
                    for (j = 0; j < 15; j++){
                        
                        evalDeruv[1]=uv[1]+wgh*newTdir[1];
                        
                        oneBspEval2(degU, degV, mxGetPr(mxGetField(nrbStruct, 0, "coefs")), ncp, kcp, mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 1)), evalDeruv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                        
                        tmpDist=pwr2(bspPnts[0]/bspPnts[3]-controlPnt[0])+pwr2(bspPnts[1]/bspPnts[3]-controlPnt[1])+pwr2(bspPnts[2]/bspPnts[3]-controlPnt[2]);
                        
                        if (tmpDist<(minDist+wgh*evalDeru[0])){
                            uv[1]=evalDeruv[1];
                            
                            if (wgh*(fabs(newTdir[1]))>stcri){
                                bool=0;
                            }
                            break;
                        }
                        else {
                            wgh=wgh*0.75;
                        }
                        
                    }
                    
                    /* Parameter values must be inside the domain */
                    
                    if (uv[1]<vStart){
                        uv[1]=vStart;
                    }
                    else if (uv[1]>vEnd){
                        uv[1]=vEnd;
                    }
                    
                }
                
                uv[0]-=difru;
                explsign+=explWghs[jj]*uv[1];
                
            }
            
            uv[0]=us[2*k];
            uv[1]=explsign;
            
        }
        else {
            
            /* Surface normal exists */
            
            /* Compute unweighted control point */
            
            controlPnt[0]=cp[4*k]/cp[4*k+3];
            controlPnt[1]=cp[4*k+1]/cp[4*k+3];
            controlPnt[2]=cp[4*k+2]/cp[4*k+3];
            
            /* Iterate to find the closest NURBS surface point */
            
            bool=0;
            
            for (i = 0; i < iters; i++){
                
                if (bool){
                    break;
                }
                
                /* Compute gradient and Hessian */
                
                nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                
                diffPnt[0]=evalPnt[0]-controlPnt[0];
                diffPnt[1]=evalPnt[1]-controlPnt[1];
                diffPnt[2]=evalPnt[2]-controlPnt[2];
                
                minDist=diffPnt[0]*diffPnt[0]+diffPnt[1]*diffPnt[1]+diffPnt[2]*diffPnt[2];
                
                grad[1]=evalDerv[0]*diffPnt[0]+evalDerv[1]*diffPnt[1]+evalDerv[2]*diffPnt[2];
                
                Hess[2]=evalDervv[0]*diffPnt[0]+evalDervv[1]*diffPnt[1]+evalDervv[2]*diffPnt[2] + evalDerv[0]*evalDerv[0]+evalDerv[1]*evalDerv[1]+evalDerv[2]*evalDerv[2];
                
                if (1e12*Hess[2]<=fabs(grad[1])){
                    newTdir[1]=-grad[1];
                }
                else {
                    newTdir[1]=-grad[1]/Hess[2];
                }
                
                /* Scale search direction if neccecary */
                
                if (newTdir[1]<-newtVlim){
                    newTdir[1]=-newtVlim;
                }
                else if (newTdir[1]>newtVlim){
                    newTdir[1]=newtVlim;
                }
                
                /* Apply line search */
                
                evalDeru[0]=0.5*(newTdir[1]*grad[1]);
                
                wgh=1.0;
                bool=1;
                evalDeruv[0]=uv[0];
                
                for (j = 0; j < 15; j++){
                    
                    evalDeruv[1]=uv[1]+wgh*newTdir[1];
                    
                    oneBspEval2(degU, degV, mxGetPr(mxGetField(nrbStruct, 0, "coefs")), ncp, kcp, mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 1)), evalDeruv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                    
                    tmpDist=pwr2(bspPnts[0]/bspPnts[3]-controlPnt[0])+pwr2(bspPnts[1]/bspPnts[3]-controlPnt[1])+pwr2(bspPnts[2]/bspPnts[3]-controlPnt[2]);
                    
                    if (tmpDist<(minDist+wgh*evalDeru[0])){
                        uv[1]=evalDeruv[1];
                        
                        if (wgh*(fabs(newTdir[1]))>stcri){
                            bool=0;
                        }
                        break;
                    }
                    else {
                        wgh=wgh*0.75;
                    }
                    
                }
                
                /* Parameter values must be inside the domain */
                
                if (uv[1]<vStart){
                    uv[1]=vStart;
                }
                else if (uv[1]>vEnd){
                    uv[1]=vEnd;
                }
                
            }
            
        }
        
        UVcp[2*k]=uv[0];
        UVcp[2*k+1]=uv[1];
        
        /* Compute surface normal at the closest point */
        
        nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
        
        evalDeruu[0]=evalDeru[0]*evalDeru[0]+evalDeru[1]*evalDeru[1]+evalDeru[2]*evalDeru[2];
        evalDervv[0]=evalDerv[0]*evalDerv[0]+evalDerv[1]*evalDerv[1]+evalDerv[2]*evalDerv[2];
        
        if (evalDeruu[0]<1e-20*evalDervv[0]){
            
            /* u-derivative to small to be accurate, estimate a new one */
            
            if (uv[1]>(vEnd-10.1*difrv)){
                explsign=-1.0;
            }
            else {
                explsign=1.0;
            }
            
            srfNrml[0]=0.0;
            srfNrml[1]=0.0;
            srfNrml[2]=0.0;
            
            for (i = 0; i < 10; i++){
                
                uv[1]+=explsign*difrv;
                
                nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                
                evalDeruu[0]=evalDeru[1]*evalDerv[2]-evalDeru[2]*evalDerv[1];
                evalDeruu[1]=evalDeru[2]*evalDerv[0]-evalDeru[0]*evalDerv[2];
                evalDeruu[2]=evalDeru[0]*evalDerv[1]-evalDeru[1]*evalDerv[0];
                
                tmpDist=sqrt(evalDeruu[0]*evalDeruu[0]+evalDeruu[1]*evalDeruu[1]+evalDeruu[2]*evalDeruu[2]);
                
                srfNrml[0]+=explWghs[i]*evalDeruu[0]/tmpDist;
                srfNrml[1]+=explWghs[i]*evalDeruu[1]/tmpDist;
                srfNrml[2]+=explWghs[i]*evalDeruu[2]/tmpDist;
                
            }
            
            tmpDist=sqrt(srfNrml[0]*srfNrml[0]+srfNrml[1]*srfNrml[1]+srfNrml[2]*srfNrml[2]);
            
            srfNrml[0]=srfNrml[0]/tmpDist;
            srfNrml[1]=srfNrml[1]/tmpDist;
            srfNrml[2]=srfNrml[2]/tmpDist;
            
        }
        else if (evalDervv[0]<1e-20*evalDeruu[0]){
            
            /* v-derivative to small to be accurate, estimate a new one */
            
            if (uv[0]>(uEnd-10.1*difru)){
                explsign=-1.0;
            }
            else {
                explsign=1.0;
            }
            
            srfNrml[0]=0.0;
            srfNrml[1]=0.0;
            srfNrml[2]=0.0;
            
            for (i = 0; i < 10; i++){
                
                uv[0]+=explsign*difru;
                
                nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                
                evalDeruu[0]=evalDeru[1]*evalDerv[2]-evalDeru[2]*evalDerv[1];
                evalDeruu[1]=evalDeru[2]*evalDerv[0]-evalDeru[0]*evalDerv[2];
                evalDeruu[2]=evalDeru[0]*evalDerv[1]-evalDeru[1]*evalDerv[0];
                
                tmpDist=sqrt(evalDeruu[0]*evalDeruu[0]+evalDeruu[1]*evalDeruu[1]+evalDeruu[2]*evalDeruu[2]);
                
                srfNrml[0]+=explWghs[i]*evalDeruu[0]/tmpDist;
                srfNrml[1]+=explWghs[i]*evalDeruu[1]/tmpDist;
                srfNrml[2]+=explWghs[i]*evalDeruu[2]/tmpDist;
                
            }
            
            tmpDist=sqrt(srfNrml[0]*srfNrml[0]+srfNrml[1]*srfNrml[1]+srfNrml[2]*srfNrml[2]);
            
            srfNrml[0]=srfNrml[0]/tmpDist;
            srfNrml[1]=srfNrml[1]/tmpDist;
            srfNrml[2]=srfNrml[2]/tmpDist;
            
        }
        else {
            
            /* just compute the surface normal */
            
            srfNrml[0]=evalDeru[1]*evalDerv[2]-evalDeru[2]*evalDerv[1];
            srfNrml[1]=evalDeru[2]*evalDerv[0]-evalDeru[0]*evalDerv[2];
            srfNrml[2]=evalDeru[0]*evalDerv[1]-evalDeru[1]*evalDerv[0];
            
            tmpDist=sqrt(srfNrml[0]*srfNrml[0]+srfNrml[1]*srfNrml[1]+srfNrml[2]*srfNrml[2]);
            
            if (tmpDist>1e-50){
                
                srfNrml[0]=srfNrml[0]/tmpDist;
                srfNrml[1]=srfNrml[1]/tmpDist;
                srfNrml[2]=srfNrml[2]/tmpDist;
                
            }
            else {
                
                srfNrml[0]=0.0;
                srfNrml[1]=0.0;
                srfNrml[2]=1.0;
                
            }
            
        }
        
        corrSrfNrmls[threek]=srfNrml[0];
        corrSrfNrmls[threek+1]=srfNrml[1];
        corrSrfNrmls[threek+2]=srfNrml[2];
        
        k++;
        threek+=3;
        
        for (jj = 1; jj <= (ncp-2); jj++){
            
            /* Compute unweighted control point */
            
            controlPnt[0]=cp[4*k]/cp[4*k+3];
            controlPnt[1]=cp[4*k+1]/cp[4*k+3];
            controlPnt[2]=cp[4*k+2]/cp[4*k+3];
            
            /* Initial parameters */
            
            uv[0]=us[2*k];
            uv[1]=us[2*k+1];
            
            /* Iterate to find the closest NURBS surface point */
            
            bool=0;
            
            for (i = 0; i < iters; i++){
                
                if (bool){
                    break;
                }
                
                /* Compute gradient and Hessian */
                
                nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                
                diffPnt[0]=evalPnt[0]-controlPnt[0];
                diffPnt[1]=evalPnt[1]-controlPnt[1];
                diffPnt[2]=evalPnt[2]-controlPnt[2];
                
                minDist=diffPnt[0]*diffPnt[0]+diffPnt[1]*diffPnt[1]+diffPnt[2]*diffPnt[2];
                
                grad[0]=evalDeru[0]*diffPnt[0]+evalDeru[1]*diffPnt[1]+evalDeru[2]*diffPnt[2];
                grad[1]=evalDerv[0]*diffPnt[0]+evalDerv[1]*diffPnt[1]+evalDerv[2]*diffPnt[2];
                
                Hess[0]=evalDeruu[0]*diffPnt[0]+evalDeruu[1]*diffPnt[1]+evalDeruu[2]*diffPnt[2] + evalDeru[0]*evalDeru[0]+evalDeru[1]*evalDeru[1]+evalDeru[2]*evalDeru[2];
                Hess[1]=evalDeruv[0]*diffPnt[0]+evalDeruv[1]*diffPnt[1]+evalDeruv[2]*diffPnt[2] + evalDeru[0]*evalDerv[0]+evalDeru[1]*evalDerv[1]+evalDeru[2]*evalDerv[2];
                Hess[2]=evalDervv[0]*diffPnt[0]+evalDervv[1]*diffPnt[1]+evalDervv[2]*diffPnt[2] + evalDerv[0]*evalDerv[0]+evalDerv[1]*evalDerv[1]+evalDerv[2]*evalDerv[2];
                
                /* CGM - two iterations */
                
                evalDerv[0]=grad[0];
                evalDerv[1]=grad[1];
                
                evalDeru[0]=evalDerv[0];
                evalDeru[1]=evalDerv[1];
                
                wgh=evalDerv[0]*evalDerv[0]+evalDerv[1]*evalDerv[1];
                
                if (wgh>1e-50){
                    
                    evalDeruu[0]=Hess[0]*evalDeru[0]+Hess[1]*evalDeru[1];
                    evalDeruu[1]=Hess[1]*evalDeru[0]+Hess[2]*evalDeru[1];
                    
                    tmpDist=evalDeru[0]*evalDeruu[0]+evalDeru[1]*evalDeruu[1];
                    
                    if (wgh<1e20*fabs(tmpDist)){
                        
                        tmpDist=wgh/tmpDist;
                        
                        if (tmpDist<0){
                            
                            newTdir[0]=-grad[0];
                            newTdir[1]=-grad[1];
                            
                        }
                        else {
                            
                            newTdir[0]=-tmpDist*evalDeru[0];
                            newTdir[1]=-tmpDist*evalDeru[1];
                            
                            evalDerv[0]-=tmpDist*evalDeruu[0];
                            evalDerv[1]-=tmpDist*evalDeruu[1];
                            
                            bspPnts[0]=evalDerv[0]*evalDerv[0]+evalDerv[1]*evalDerv[1];
                            
                            if (bspPnts[0]>1e-25){
                                
                                evalDeru[0]=evalDerv[0]+(bspPnts[0]*evalDeru[0])/wgh;
                                evalDeru[1]=evalDerv[1]+(bspPnts[0]*evalDeru[1])/wgh;
                                
                                wgh=bspPnts[0];
                                
                                evalDeruu[0]=Hess[0]*evalDeru[0]+Hess[1]*evalDeru[1];
                                evalDeruu[1]=Hess[1]*evalDeru[0]+Hess[2]*evalDeru[1];
                                
                                tmpDist=evalDeru[0]*evalDeruu[0]+evalDeru[1]*evalDeruu[1];
                                
                                if (wgh<1e10*fabs(tmpDist)){
                                    
                                    tmpDist=wgh/tmpDist;
                                    
                                    if (tmpDist<0){
                                        
                                        newTdir[0]+=0.5*tmpDist*evalDeru[0];
                                        newTdir[1]+=0.5*tmpDist*evalDeru[1];
                                        
                                    }
                                    else {
                                        
                                        newTdir[0]-=tmpDist*evalDeru[0];
                                        newTdir[1]-=tmpDist*evalDeru[1];
                                        
                                    }
                                    
                                }
                                
                            }
                            
                        }
                        
                    }
                    else {
                        
                        newTdir[0]=-grad[0];
                        newTdir[1]=-grad[1];
                        
                    }
                    
                    /* Scale search direction if neccecary */
                    
                    if (newTdir[0]<-newtUlim){
                        newTdir[1]=-newtUlim*newTdir[1]/newTdir[0];
                        newTdir[0]=-newtUlim;
                    }
                    else if (newTdir[0]>newtUlim){
                        newTdir[1]=newtUlim*newTdir[1]/newTdir[0];
                        newTdir[0]=newtUlim;
                    }
                    if (newTdir[1]<-newtVlim){
                        newTdir[0]=-newtVlim*newTdir[0]/newTdir[1];
                        newTdir[1]=-newtVlim;
                    }
                    else if (newTdir[1]>newtVlim){
                        newTdir[0]=newtVlim*newTdir[0]/newTdir[1];
                        newTdir[1]=newtVlim;
                    }
                    
                    /* Apply line search */
                    
                    evalDeru[0]=0.5*(newTdir[0]*grad[0]+newTdir[1]*grad[1]);
                    
                    wgh=1.0;
                    bool=1;
                    for (j = 0; j < 15; j++){
                        
                        evalDeruv[0]=uv[0]+wgh*newTdir[0];
                        evalDeruv[1]=uv[1]+wgh*newTdir[1];
                        
                        oneBspEval2(degU, degV, mxGetPr(mxGetField(nrbStruct, 0, "coefs")), ncp, kcp, mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 1)), evalDeruv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                        
                        tmpDist=pwr2(bspPnts[0]/bspPnts[3]-controlPnt[0])+pwr2(bspPnts[1]/bspPnts[3]-controlPnt[1])+pwr2(bspPnts[2]/bspPnts[3]-controlPnt[2]);
                        
                        if (tmpDist<(minDist+wgh*evalDeru[0])){
                            uv[0]=evalDeruv[0];
                            uv[1]=evalDeruv[1];
                            
                            if (wgh*(fabs(newTdir[0])+fabs(newTdir[1]))>stcri){
                                bool=0;
                            }
                            break;
                        }
                        else {
                            wgh=wgh*0.75;
                        }
                        
                    }
                    
                }
                else {
                    bool=1;
                }
                
                /* Parameter values must be inside the domain */
                
                if (uv[0]<uStart){
                    uv[0]=uStart;
                }
                else if (uv[0]>uEnd){
                    uv[0]=uEnd;
                }
                if (uv[1]<vStart){
                    uv[1]=vStart;
                }
                else if (uv[1]>vEnd){
                    uv[1]=vEnd;
                }
                
            }
            
            UVcp[2*k]=uv[0];
            UVcp[2*k+1]=uv[1];
            
            /* Compute surface normal at the closest point */
            
            nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
            
            evalDeruu[0]=evalDeru[0]*evalDeru[0]+evalDeru[1]*evalDeru[1]+evalDeru[2]*evalDeru[2];
            evalDervv[0]=evalDerv[0]*evalDerv[0]+evalDerv[1]*evalDerv[1]+evalDerv[2]*evalDerv[2];
            
            if (evalDeruu[0]<1e-20*evalDervv[0]){
                
                /* u-derivative to small to be accurate, estimate a new one */
                
                if (uv[1]>(vEnd-10.1*difrv)){
                    explsign=-1.0;
                }
                else {
                    explsign=1.0;
                }
                
                srfNrml[0]=0.0;
                srfNrml[1]=0.0;
                srfNrml[2]=0.0;
                
                for (i = 0; i < 10; i++){
                    
                    uv[1]+=explsign*difrv;
                    
                    nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                    
                    evalDeruu[0]=evalDeru[1]*evalDerv[2]-evalDeru[2]*evalDerv[1];
                    evalDeruu[1]=evalDeru[2]*evalDerv[0]-evalDeru[0]*evalDerv[2];
                    evalDeruu[2]=evalDeru[0]*evalDerv[1]-evalDeru[1]*evalDerv[0];
                    
                    tmpDist=sqrt(evalDeruu[0]*evalDeruu[0]+evalDeruu[1]*evalDeruu[1]+evalDeruu[2]*evalDeruu[2]);
                    
                    srfNrml[0]+=explWghs[i]*evalDeruu[0]/tmpDist;
                    srfNrml[1]+=explWghs[i]*evalDeruu[1]/tmpDist;
                    srfNrml[2]+=explWghs[i]*evalDeruu[2]/tmpDist;
                    
                }
                
                tmpDist=sqrt(srfNrml[0]*srfNrml[0]+srfNrml[1]*srfNrml[1]+srfNrml[2]*srfNrml[2]);
                
                srfNrml[0]=srfNrml[0]/tmpDist;
                srfNrml[1]=srfNrml[1]/tmpDist;
                srfNrml[2]=srfNrml[2]/tmpDist;
                
            }
            else if (evalDervv[0]<1e-20*evalDeruu[0]){
                
                /* v-derivative to small to be accurate, estimate a new one */
                
                if (uv[0]>(uEnd-10.1*difru)){
                    explsign=-1.0;
                }
                else {
                    explsign=1.0;
                }
                
                srfNrml[0]=0.0;
                srfNrml[1]=0.0;
                srfNrml[2]=0.0;
                
                for (i = 0; i < 10; i++){
                    
                    uv[0]+=explsign*difru;
                    
                    nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                    
                    evalDeruu[0]=evalDeru[1]*evalDerv[2]-evalDeru[2]*evalDerv[1];
                    evalDeruu[1]=evalDeru[2]*evalDerv[0]-evalDeru[0]*evalDerv[2];
                    evalDeruu[2]=evalDeru[0]*evalDerv[1]-evalDeru[1]*evalDerv[0];
                    
                    tmpDist=sqrt(evalDeruu[0]*evalDeruu[0]+evalDeruu[1]*evalDeruu[1]+evalDeruu[2]*evalDeruu[2]);
                    
                    srfNrml[0]+=explWghs[i]*evalDeruu[0]/tmpDist;
                    srfNrml[1]+=explWghs[i]*evalDeruu[1]/tmpDist;
                    srfNrml[2]+=explWghs[i]*evalDeruu[2]/tmpDist;
                    
                }
                
                tmpDist=sqrt(srfNrml[0]*srfNrml[0]+srfNrml[1]*srfNrml[1]+srfNrml[2]*srfNrml[2]);
                
                srfNrml[0]=srfNrml[0]/tmpDist;
                srfNrml[1]=srfNrml[1]/tmpDist;
                srfNrml[2]=srfNrml[2]/tmpDist;
                
            }
            else {
                
                /* just compute the surface normal */
                
                srfNrml[0]=evalDeru[1]*evalDerv[2]-evalDeru[2]*evalDerv[1];
                srfNrml[1]=evalDeru[2]*evalDerv[0]-evalDeru[0]*evalDerv[2];
                srfNrml[2]=evalDeru[0]*evalDerv[1]-evalDeru[1]*evalDerv[0];
                
                tmpDist=sqrt(srfNrml[0]*srfNrml[0]+srfNrml[1]*srfNrml[1]+srfNrml[2]*srfNrml[2]);
                
                if (tmpDist>1e-50){
                    
                    srfNrml[0]=srfNrml[0]/tmpDist;
                    srfNrml[1]=srfNrml[1]/tmpDist;
                    srfNrml[2]=srfNrml[2]/tmpDist;
                    
                }
                else {
                    
                    srfNrml[0]=0.0;
                    srfNrml[1]=0.0;
                    srfNrml[2]=1.0;
                    
                }
                
            }
            
            corrSrfNrmls[threek]=srfNrml[0];
            corrSrfNrmls[threek+1]=srfNrml[1];
            corrSrfNrmls[threek+2]=srfNrml[2];
            
            k++;
            threek+=3;
            
        }
        
        /* Initial parameters */
        
        uv[0]=us[2*k];
        uv[1]=us[2*k+1];
        
        nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
        
        if ((evalDerv[0]*evalDerv[0]+evalDerv[1]*evalDerv[1]+evalDerv[2]*evalDerv[2])<1e-16*(evalDeru[0]*evalDeru[0]+evalDeru[1]*evalDeru[1]+evalDeru[2]*evalDeru[2])){
            
            /* Surface normal not defined, using extrapolation */
            
            uv[0]-=10.0*difru;
            explsign=0.0;
            
            for (jj = 9; jj >= 0; jj--){
                
                /* Compute unweighted control point */
                
                spanU = FindSpan(ncp, degU, uv[0], knotU);
                BasisFuns(spanU, uv[0], degU, knotU, NU, leftU, rightU);
                
                ind = spanU - degU;
                myint=ii*fourncp+ind*4;
                
                bspPnts[0]=0.0;
                bspPnts[1]=0.0;
                bspPnts[2]=0.0;
                bspPnts[3]=0.0;
                for (j = 0; j <= degU; j++){
                    bspPnts[0] += NU[j] * cp[j*4+myint];
                    bspPnts[1] += NU[j] * cp[j*4+myint+1];
                    bspPnts[2] += NU[j] * cp[j*4+myint+2];
                    bspPnts[3] += NU[j] * cp[j*4+myint+3];
                }
                
                controlPnt[0]=bspPnts[0]/bspPnts[3];
                controlPnt[1]=bspPnts[1]/bspPnts[3];
                controlPnt[2]=bspPnts[2]/bspPnts[3];
                
                /* Iterate to find the closest NURBS surface point */
                
                bool=0;
                
                for (i = 0; i < iters; i++){
                    
                    if (bool){
                        break;
                    }
                    
                    /* Compute gradient and Hessian */
                    
                    nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                    
                    diffPnt[0]=evalPnt[0]-controlPnt[0];
                    diffPnt[1]=evalPnt[1]-controlPnt[1];
                    diffPnt[2]=evalPnt[2]-controlPnt[2];
                    
                    minDist=diffPnt[0]*diffPnt[0]+diffPnt[1]*diffPnt[1]+diffPnt[2]*diffPnt[2];
                    
                    grad[1]=evalDerv[0]*diffPnt[0]+evalDerv[1]*diffPnt[1]+evalDerv[2]*diffPnt[2];
                    
                    Hess[2]=evalDervv[0]*diffPnt[0]+evalDervv[1]*diffPnt[1]+evalDervv[2]*diffPnt[2] + evalDerv[0]*evalDerv[0]+evalDerv[1]*evalDerv[1]+evalDerv[2]*evalDerv[2];
                    
                    if (1e12*Hess[2]<=fabs(grad[1])){
                        newTdir[1]=-grad[1];
                    }
                    else {
                        newTdir[1]=-grad[1]/Hess[2];
                    }
                    
                    /* Scale search direction if neccecary */
                    
                    if (newTdir[1]<-newtVlim){
                        newTdir[1]=-newtVlim;
                    }
                    else if (newTdir[1]>newtVlim){
                        newTdir[1]=newtVlim;
                    }
                    
                    /* Apply line search */
                    
                    evalDeru[0]=0.5*(newTdir[1]*grad[1]);
                    
                    wgh=1.0;
                    bool=1;
                    evalDeruv[0]=uv[0];
                    
                    for (j = 0; j < 15; j++){
                        
                        evalDeruv[1]=uv[1]+wgh*newTdir[1];
                        
                        oneBspEval2(degU, degV, mxGetPr(mxGetField(nrbStruct, 0, "coefs")), ncp, kcp, mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 1)), evalDeruv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                        
                        tmpDist=pwr2(bspPnts[0]/bspPnts[3]-controlPnt[0])+pwr2(bspPnts[1]/bspPnts[3]-controlPnt[1])+pwr2(bspPnts[2]/bspPnts[3]-controlPnt[2]);
                        
                        if (tmpDist<(minDist+wgh*evalDeru[0])){
                            uv[1]=evalDeruv[1];
                            
                            if (wgh*(fabs(newTdir[1]))>stcri){
                                bool=0;
                            }
                            break;
                        }
                        else {
                            wgh=wgh*0.75;
                        }
                        
                    }
                    
                    /* Parameter values must be inside the domain */
                    
                    if (uv[1]<vStart){
                        uv[1]=vStart;
                    }
                    else if (uv[1]>vEnd){
                        uv[1]=vEnd;
                    }
                    
                }
                
                uv[0]+=difru;
                explsign+=explWghs[jj]*uv[1];
                
            }
            
            uv[0]=us[2*k];
            uv[1]=explsign;
            
        }
        else {
            
            /* Surface normal exists */
            
            /* Compute unweighted control point */
            
            controlPnt[0]=cp[4*k]/cp[4*k+3];
            controlPnt[1]=cp[4*k+1]/cp[4*k+3];
            controlPnt[2]=cp[4*k+2]/cp[4*k+3];
            
            /* Iterate to find the closest NURBS surface point */
            
            bool=0;
            
            for (i = 0; i < iters; i++){
                
                if (bool){
                    break;
                }
                
                /* Compute gradient and Hessian */
                
                nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                
                diffPnt[0]=evalPnt[0]-controlPnt[0];
                diffPnt[1]=evalPnt[1]-controlPnt[1];
                diffPnt[2]=evalPnt[2]-controlPnt[2];
                
                minDist=diffPnt[0]*diffPnt[0]+diffPnt[1]*diffPnt[1]+diffPnt[2]*diffPnt[2];
                
                grad[1]=evalDerv[0]*diffPnt[0]+evalDerv[1]*diffPnt[1]+evalDerv[2]*diffPnt[2];
                
                Hess[2]=evalDervv[0]*diffPnt[0]+evalDervv[1]*diffPnt[1]+evalDervv[2]*diffPnt[2] + evalDerv[0]*evalDerv[0]+evalDerv[1]*evalDerv[1]+evalDerv[2]*evalDerv[2];
                
                if (1e12*Hess[2]<=fabs(grad[1])){
                    newTdir[1]=-grad[1];
                }
                else {
                    newTdir[1]=-grad[1]/Hess[2];
                }
                
                /* Scale search direction if neccecary */
                
                if (newTdir[1]<-newtVlim){
                    newTdir[1]=-newtVlim;
                }
                else if (newTdir[1]>newtVlim){
                    newTdir[1]=newtVlim;
                }
                
                /* Apply line search */
                
                evalDeru[0]=0.5*(newTdir[1]*grad[1]);
                
                wgh=1.0;
                bool=1;
                evalDeruv[0]=uv[0];
                
                for (j = 0; j < 15; j++){
                    
                    evalDeruv[1]=uv[1]+wgh*newTdir[1];
                    
                    oneBspEval2(degU, degV, mxGetPr(mxGetField(nrbStruct, 0, "coefs")), ncp, kcp, mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 1)), evalDeruv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                    
                    tmpDist=pwr2(bspPnts[0]/bspPnts[3]-controlPnt[0])+pwr2(bspPnts[1]/bspPnts[3]-controlPnt[1])+pwr2(bspPnts[2]/bspPnts[3]-controlPnt[2]);
                    
                    if (tmpDist<(minDist+wgh*evalDeru[0])){
                        uv[1]=evalDeruv[1];
                        
                        if (wgh*(fabs(newTdir[1]))>stcri){
                            bool=0;
                        }
                        break;
                    }
                    else {
                        wgh=wgh*0.75;
                    }
                    
                }
                
                /* Parameter values must be inside the domain */
                
                if (uv[1]<vStart){
                    uv[1]=vStart;
                }
                else if (uv[1]>vEnd){
                    uv[1]=vEnd;
                }
                
            }
            
        }
        
        UVcp[2*k]=uv[0];
        UVcp[2*k+1]=uv[1];
        
        /* Compute surface normal at the closest point */
        
        nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
        
        evalDeruu[0]=evalDeru[0]*evalDeru[0]+evalDeru[1]*evalDeru[1]+evalDeru[2]*evalDeru[2];
        evalDervv[0]=evalDerv[0]*evalDerv[0]+evalDerv[1]*evalDerv[1]+evalDerv[2]*evalDerv[2];
        
        if (evalDeruu[0]<1e-20*evalDervv[0]){
            
            /* u-derivative to small to be accurate, estimate a new one */
            
            if (uv[1]>(vEnd-10.1*difrv)){
                explsign=-1.0;
            }
            else {
                explsign=1.0;
            }
            
            srfNrml[0]=0.0;
            srfNrml[1]=0.0;
            srfNrml[2]=0.0;
            
            for (i = 0; i < 10; i++){
                
                uv[1]+=explsign*difrv;
                
                nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                
                evalDeruu[0]=evalDeru[1]*evalDerv[2]-evalDeru[2]*evalDerv[1];
                evalDeruu[1]=evalDeru[2]*evalDerv[0]-evalDeru[0]*evalDerv[2];
                evalDeruu[2]=evalDeru[0]*evalDerv[1]-evalDeru[1]*evalDerv[0];
                
                tmpDist=sqrt(evalDeruu[0]*evalDeruu[0]+evalDeruu[1]*evalDeruu[1]+evalDeruu[2]*evalDeruu[2]);
                
                srfNrml[0]+=explWghs[i]*evalDeruu[0]/tmpDist;
                srfNrml[1]+=explWghs[i]*evalDeruu[1]/tmpDist;
                srfNrml[2]+=explWghs[i]*evalDeruu[2]/tmpDist;
                
            }
            
            tmpDist=sqrt(srfNrml[0]*srfNrml[0]+srfNrml[1]*srfNrml[1]+srfNrml[2]*srfNrml[2]);
            
            srfNrml[0]=srfNrml[0]/tmpDist;
            srfNrml[1]=srfNrml[1]/tmpDist;
            srfNrml[2]=srfNrml[2]/tmpDist;
            
        }
        else if (evalDervv[0]<1e-20*evalDeruu[0]){
            
            /* v-derivative to small to be accurate, estimate a new one */
            
            if (uv[0]>(uEnd-10.1*difru)){
                explsign=-1.0;
            }
            else {
                explsign=1.0;
            }
            
            srfNrml[0]=0.0;
            srfNrml[1]=0.0;
            srfNrml[2]=0.0;
            
            for (i = 0; i < 10; i++){
                
                uv[0]+=explsign*difru;
                
                nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                
                evalDeruu[0]=evalDeru[1]*evalDerv[2]-evalDeru[2]*evalDerv[1];
                evalDeruu[1]=evalDeru[2]*evalDerv[0]-evalDeru[0]*evalDerv[2];
                evalDeruu[2]=evalDeru[0]*evalDerv[1]-evalDeru[1]*evalDerv[0];
                
                tmpDist=sqrt(evalDeruu[0]*evalDeruu[0]+evalDeruu[1]*evalDeruu[1]+evalDeruu[2]*evalDeruu[2]);
                
                srfNrml[0]+=explWghs[i]*evalDeruu[0]/tmpDist;
                srfNrml[1]+=explWghs[i]*evalDeruu[1]/tmpDist;
                srfNrml[2]+=explWghs[i]*evalDeruu[2]/tmpDist;
                
            }
            
            tmpDist=sqrt(srfNrml[0]*srfNrml[0]+srfNrml[1]*srfNrml[1]+srfNrml[2]*srfNrml[2]);
            
            srfNrml[0]=srfNrml[0]/tmpDist;
            srfNrml[1]=srfNrml[1]/tmpDist;
            srfNrml[2]=srfNrml[2]/tmpDist;
            
        }
        else {
            
            /* just compute the surface normal */
            
            srfNrml[0]=evalDeru[1]*evalDerv[2]-evalDeru[2]*evalDerv[1];
            srfNrml[1]=evalDeru[2]*evalDerv[0]-evalDeru[0]*evalDerv[2];
            srfNrml[2]=evalDeru[0]*evalDerv[1]-evalDeru[1]*evalDerv[0];
            
            tmpDist=sqrt(srfNrml[0]*srfNrml[0]+srfNrml[1]*srfNrml[1]+srfNrml[2]*srfNrml[2]);
            
            if (tmpDist>1e-50){
                
                srfNrml[0]=srfNrml[0]/tmpDist;
                srfNrml[1]=srfNrml[1]/tmpDist;
                srfNrml[2]=srfNrml[2]/tmpDist;
                
            }
            else {
                
                srfNrml[0]=0.0;
                srfNrml[1]=0.0;
                srfNrml[2]=1.0;
                
            }
            
        }
        
        corrSrfNrmls[threek]=srfNrml[0];
        corrSrfNrmls[threek+1]=srfNrml[1];
        corrSrfNrmls[threek+2]=srfNrml[2];
        
        k++;
        threek+=3;
        
    }
    
    /* ii = kcp-1, jj=0 */
    
    uv[0]=us[2*k];
    uv[1]=us[2*k+1];
    
    UVcp[2*k]=uv[0];
    UVcp[2*k+1]=uv[1];
    
    /* Compute surface normal at the corner point */
    
    nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
    
    evalDeruu[0]=evalDeru[0]*evalDeru[0]+evalDeru[1]*evalDeru[1]+evalDeru[2]*evalDeru[2];
    evalDervv[0]=evalDerv[0]*evalDerv[0]+evalDerv[1]*evalDerv[1]+evalDerv[2]*evalDerv[2];
    
    if (evalDeruu[0]<1e-20*evalDervv[0]){
        
        /* u-derivative to small to be accurate, estimate a new one */
        
        if (uv[1]>(vEnd-10.1*difrv)){
            explsign=-1.0;
        }
        else {
            explsign=1.0;
        }
        
        srfNrml[0]=0.0;
        srfNrml[1]=0.0;
        srfNrml[2]=0.0;
        
        for (i = 0; i < 10; i++){
            
            uv[1]+=explsign*difrv;
            
            nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
            
            evalDeruu[0]=evalDeru[1]*evalDerv[2]-evalDeru[2]*evalDerv[1];
            evalDeruu[1]=evalDeru[2]*evalDerv[0]-evalDeru[0]*evalDerv[2];
            evalDeruu[2]=evalDeru[0]*evalDerv[1]-evalDeru[1]*evalDerv[0];
            
            tmpDist=sqrt(evalDeruu[0]*evalDeruu[0]+evalDeruu[1]*evalDeruu[1]+evalDeruu[2]*evalDeruu[2]);
            
            srfNrml[0]+=explWghs[i]*evalDeruu[0]/tmpDist;
            srfNrml[1]+=explWghs[i]*evalDeruu[1]/tmpDist;
            srfNrml[2]+=explWghs[i]*evalDeruu[2]/tmpDist;
            
        }
        
        tmpDist=sqrt(srfNrml[0]*srfNrml[0]+srfNrml[1]*srfNrml[1]+srfNrml[2]*srfNrml[2]);
        
        srfNrml[0]=srfNrml[0]/tmpDist;
        srfNrml[1]=srfNrml[1]/tmpDist;
        srfNrml[2]=srfNrml[2]/tmpDist;
        
    }
    else if (evalDervv[0]<1e-20*evalDeruu[0]){
        
        /* v-derivative to small to be accurate, estimate a new one */
        
        if (uv[0]>(uEnd-10.1*difru)){
            explsign=-1.0;
        }
        else {
            explsign=1.0;
        }
        
        srfNrml[0]=0.0;
        srfNrml[1]=0.0;
        srfNrml[2]=0.0;
        
        for (i = 0; i < 10; i++){
            
            uv[0]+=explsign*difru;
            
            nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
            
            evalDeruu[0]=evalDeru[1]*evalDerv[2]-evalDeru[2]*evalDerv[1];
            evalDeruu[1]=evalDeru[2]*evalDerv[0]-evalDeru[0]*evalDerv[2];
            evalDeruu[2]=evalDeru[0]*evalDerv[1]-evalDeru[1]*evalDerv[0];
            
            tmpDist=sqrt(evalDeruu[0]*evalDeruu[0]+evalDeruu[1]*evalDeruu[1]+evalDeruu[2]*evalDeruu[2]);
            
            srfNrml[0]+=explWghs[i]*evalDeruu[0]/tmpDist;
            srfNrml[1]+=explWghs[i]*evalDeruu[1]/tmpDist;
            srfNrml[2]+=explWghs[i]*evalDeruu[2]/tmpDist;
            
        }
        
        tmpDist=sqrt(srfNrml[0]*srfNrml[0]+srfNrml[1]*srfNrml[1]+srfNrml[2]*srfNrml[2]);
        
        srfNrml[0]=srfNrml[0]/tmpDist;
        srfNrml[1]=srfNrml[1]/tmpDist;
        srfNrml[2]=srfNrml[2]/tmpDist;
        
    }
    else {
        
        /* just compute the surface normal */
        
        srfNrml[0]=evalDeru[1]*evalDerv[2]-evalDeru[2]*evalDerv[1];
        srfNrml[1]=evalDeru[2]*evalDerv[0]-evalDeru[0]*evalDerv[2];
        srfNrml[2]=evalDeru[0]*evalDerv[1]-evalDeru[1]*evalDerv[0];
        
        tmpDist=sqrt(srfNrml[0]*srfNrml[0]+srfNrml[1]*srfNrml[1]+srfNrml[2]*srfNrml[2]);
        
        if (tmpDist>1e-50){
            
            srfNrml[0]=srfNrml[0]/tmpDist;
            srfNrml[1]=srfNrml[1]/tmpDist;
            srfNrml[2]=srfNrml[2]/tmpDist;
            
        }
        else {
            
            srfNrml[0]=0.0;
            srfNrml[1]=0.0;
            srfNrml[2]=1.0;
            
        }
        
    }
    
    corrSrfNrmls[threek]=srfNrml[0];
    corrSrfNrmls[threek+1]=srfNrml[1];
    corrSrfNrmls[threek+2]=srfNrml[2];
    
    k++;
    threek+=3;
    
    /* ii = kcp-1, jj=1,2,...,ncp-2 */
    
    for (jj = 1; jj <= (ncp-2); jj++){
        
        /* Initial parameters */
        
        uv[0]=us[2*k];
        uv[1]=us[2*k+1];
        
        nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
        
        if ((evalDeru[0]*evalDeru[0]+evalDeru[1]*evalDeru[1]+evalDeru[2]*evalDeru[2])<1e-16*(evalDerv[0]*evalDerv[0]+evalDerv[1]*evalDerv[1]+evalDerv[2]*evalDerv[2])){
            
            /* Surface normal not defined, using extrapolation */
            
            uv[1]-=10.0*difrv;
            explsign=0.0;
            
            for (ii = 9; ii >= 0; ii--){
                
                /* Compute unweighted control point */
                
                spanV = FindSpan(kcp, degV, uv[1], knotV);
                BasisFuns(spanV, uv[1], degV, knotV, NV, leftV, rightV);
                
                ind2 = spanV - degV;
                myint=ind2*fourncp+jj*4;
                
                bspPnts[0]=0.0;
                bspPnts[1]=0.0;
                bspPnts[2]=0.0;
                bspPnts[3]=0.0;
                for (i = 0; i <= degV; i++){
                    bspPnts[0] += NV[i] * cp[i*fourncp+myint];
                    bspPnts[1] += NV[i] * cp[i*fourncp+myint+1];
                    bspPnts[2] += NV[i] * cp[i*fourncp+myint+2];
                    bspPnts[3] += NV[i] * cp[i*fourncp+myint+3];
                }
                
                controlPnt[0]=bspPnts[0]/bspPnts[3];
                controlPnt[1]=bspPnts[1]/bspPnts[3];
                controlPnt[2]=bspPnts[2]/bspPnts[3];
                
                /* Iterate to find the closest NURBS surface point */
                
                bool=0;
                
                for (i = 0; i < iters; i++){
                    
                    if (bool){
                        break;
                    }
                    
                    /* Compute gradient and Hessian */
                    
                    nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                    
                    diffPnt[0]=evalPnt[0]-controlPnt[0];
                    diffPnt[1]=evalPnt[1]-controlPnt[1];
                    diffPnt[2]=evalPnt[2]-controlPnt[2];
                    
                    minDist=diffPnt[0]*diffPnt[0]+diffPnt[1]*diffPnt[1]+diffPnt[2]*diffPnt[2];
                    
                    grad[0]=evalDeru[0]*diffPnt[0]+evalDeru[1]*diffPnt[1]+evalDeru[2]*diffPnt[2];
                    
                    Hess[0]=evalDeruu[0]*diffPnt[0]+evalDeruu[1]*diffPnt[1]+evalDeruu[2]*diffPnt[2] + evalDeru[0]*evalDeru[0]+evalDeru[1]*evalDeru[1]+evalDeru[2]*evalDeru[2];
                    
                    if (1e12*Hess[0]<=fabs(grad[0])){
                        newTdir[0]=-grad[0];
                    }
                    else {
                        newTdir[0]=-grad[0]/Hess[0];
                    }
                    
                    /* Scale search direction if neccecary */
                    
                    if (newTdir[0]<-newtUlim){
                        newTdir[0]=-newtUlim;
                    }
                    else if (newTdir[0]>newtUlim){
                        newTdir[0]=newtUlim;
                    }
                    
                    /* Apply line search */
                    
                    evalDeru[0]=0.5*(newTdir[0]*grad[0]);
                    
                    wgh=1.0;
                    bool=1;
                    evalDeruv[1]=uv[1];
                    
                    for (j = 0; j < 15; j++){
                        
                        evalDeruv[0]=uv[0]+wgh*newTdir[0];
                        
                        oneBspEval2(degU, degV, mxGetPr(mxGetField(nrbStruct, 0, "coefs")), ncp, kcp, mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 1)), evalDeruv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                        
                        tmpDist=pwr2(bspPnts[0]/bspPnts[3]-controlPnt[0])+pwr2(bspPnts[1]/bspPnts[3]-controlPnt[1])+pwr2(bspPnts[2]/bspPnts[3]-controlPnt[2]);
                        
                        if (tmpDist<(minDist+wgh*evalDeru[0])){
                            uv[0]=evalDeruv[0];
                            
                            if (wgh*(fabs(newTdir[0]))>stcri){
                                bool=0;
                            }
                            break;
                        }
                        else {
                            wgh=wgh*0.75;
                        }
                        
                    }
                    
                    /* Parameter values must be inside the domain */
                    
                    if (uv[0]<uStart){
                        uv[0]=uStart;
                    }
                    else if (uv[0]>uEnd){
                        uv[0]=uEnd;
                    }
                    
                }
                
                uv[1]+=difrv;
                explsign+=explWghs[ii]*uv[0];
                
            }
            
            uv[0]=explsign;
            uv[1]=us[2*k+1];
            
        }
        else {
            
            /* Surface normal exists */
            
            /* Compute unweighted control point */
            
            controlPnt[0]=cp[4*k]/cp[4*k+3];
            controlPnt[1]=cp[4*k+1]/cp[4*k+3];
            controlPnt[2]=cp[4*k+2]/cp[4*k+3];
            
            /* Iterate to find the closest NURBS surface point to the control point */
            
            bool=0;
            
            for (i = 0; i < iters; i++){
                
                if (bool){
                    break;
                }
                
                /* Compute gradient and Hessian */
                
                nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                
                diffPnt[0]=evalPnt[0]-controlPnt[0];
                diffPnt[1]=evalPnt[1]-controlPnt[1];
                diffPnt[2]=evalPnt[2]-controlPnt[2];
                
                minDist=diffPnt[0]*diffPnt[0]+diffPnt[1]*diffPnt[1]+diffPnt[2]*diffPnt[2];
                
                grad[0]=evalDeru[0]*diffPnt[0]+evalDeru[1]*diffPnt[1]+evalDeru[2]*diffPnt[2];
                
                Hess[0]=evalDeruu[0]*diffPnt[0]+evalDeruu[1]*diffPnt[1]+evalDeruu[2]*diffPnt[2] + evalDeru[0]*evalDeru[0]+evalDeru[1]*evalDeru[1]+evalDeru[2]*evalDeru[2];
                
                if (1e12*Hess[0]<=fabs(grad[0])){
                    newTdir[0]=-grad[0];
                }
                else {
                    newTdir[0]=-grad[0]/Hess[0];
                }
                
                /* Scale search direction if neccecary */
                
                if (newTdir[0]<-newtUlim){
                    newTdir[0]=-newtUlim;
                }
                else if (newTdir[0]>newtUlim){
                    newTdir[0]=newtUlim;
                }
                
                /* Apply line search */
                
                evalDeru[0]=0.5*(newTdir[0]*grad[0]);
                
                wgh=1.0;
                bool=1;
                evalDeruv[1]=uv[1];
                
                for (j = 0; j < 15; j++){
                    
                    evalDeruv[0]=uv[0]+wgh*newTdir[0];
                    
                    oneBspEval2(degU, degV, mxGetPr(mxGetField(nrbStruct, 0, "coefs")), ncp, kcp, mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 1)), evalDeruv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                    
                    tmpDist=pwr2(bspPnts[0]/bspPnts[3]-controlPnt[0])+pwr2(bspPnts[1]/bspPnts[3]-controlPnt[1])+pwr2(bspPnts[2]/bspPnts[3]-controlPnt[2]);
                    
                    if (tmpDist<(minDist+wgh*evalDeru[0])){
                        uv[0]=evalDeruv[0];
                        
                        if (wgh*(fabs(newTdir[0]))>stcri){
                            bool=0;
                        }
                        break;
                    }
                    else {
                        wgh=wgh*0.75;
                    }
                    
                }
                
                /* Parameter values must be inside the domain */
                
                if (uv[0]<uStart){
                    uv[0]=uStart;
                }
                else if (uv[0]>uEnd){
                    uv[0]=uEnd;
                }
                
            }
            
        }
        
        UVcp[2*k]=uv[0];
        UVcp[2*k+1]=uv[1];
        
        /* Compute surface normal at the closest point */
        
        nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
        
        evalDeruu[0]=evalDeru[0]*evalDeru[0]+evalDeru[1]*evalDeru[1]+evalDeru[2]*evalDeru[2];
        evalDervv[0]=evalDerv[0]*evalDerv[0]+evalDerv[1]*evalDerv[1]+evalDerv[2]*evalDerv[2];
        
        if (evalDeruu[0]<1e-20*evalDervv[0]){
            
            /* u-derivative to small to be accurate, estimate a new one */
            
            if (uv[1]>(vEnd-10.1*difrv)){
                explsign=-1.0;
            }
            else {
                explsign=1.0;
            }
            
            srfNrml[0]=0.0;
            srfNrml[1]=0.0;
            srfNrml[2]=0.0;
            
            for (i = 0; i < 10; i++){
                
                uv[1]+=explsign*difrv;
                
                nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                
                evalDeruu[0]=evalDeru[1]*evalDerv[2]-evalDeru[2]*evalDerv[1];
                evalDeruu[1]=evalDeru[2]*evalDerv[0]-evalDeru[0]*evalDerv[2];
                evalDeruu[2]=evalDeru[0]*evalDerv[1]-evalDeru[1]*evalDerv[0];
                
                tmpDist=sqrt(evalDeruu[0]*evalDeruu[0]+evalDeruu[1]*evalDeruu[1]+evalDeruu[2]*evalDeruu[2]);
                
                srfNrml[0]+=explWghs[i]*evalDeruu[0]/tmpDist;
                srfNrml[1]+=explWghs[i]*evalDeruu[1]/tmpDist;
                srfNrml[2]+=explWghs[i]*evalDeruu[2]/tmpDist;
                
            }
            
            tmpDist=sqrt(srfNrml[0]*srfNrml[0]+srfNrml[1]*srfNrml[1]+srfNrml[2]*srfNrml[2]);
            
            srfNrml[0]=srfNrml[0]/tmpDist;
            srfNrml[1]=srfNrml[1]/tmpDist;
            srfNrml[2]=srfNrml[2]/tmpDist;
            
        }
        else if (evalDervv[0]<1e-20*evalDeruu[0]){
            
            /* v-derivative to small to be accurate, estimate a new one */
            
            if (uv[0]>(uEnd-10.1*difru)){
                explsign=-1.0;
            }
            else {
                explsign=1.0;
            }
            
            srfNrml[0]=0.0;
            srfNrml[1]=0.0;
            srfNrml[2]=0.0;
            
            for (i = 0; i < 10; i++){
                
                uv[0]+=explsign*difru;
                
                nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                
                evalDeruu[0]=evalDeru[1]*evalDerv[2]-evalDeru[2]*evalDerv[1];
                evalDeruu[1]=evalDeru[2]*evalDerv[0]-evalDeru[0]*evalDerv[2];
                evalDeruu[2]=evalDeru[0]*evalDerv[1]-evalDeru[1]*evalDerv[0];
                
                tmpDist=sqrt(evalDeruu[0]*evalDeruu[0]+evalDeruu[1]*evalDeruu[1]+evalDeruu[2]*evalDeruu[2]);
                
                srfNrml[0]+=explWghs[i]*evalDeruu[0]/tmpDist;
                srfNrml[1]+=explWghs[i]*evalDeruu[1]/tmpDist;
                srfNrml[2]+=explWghs[i]*evalDeruu[2]/tmpDist;
                
            }
            
            tmpDist=sqrt(srfNrml[0]*srfNrml[0]+srfNrml[1]*srfNrml[1]+srfNrml[2]*srfNrml[2]);
            
            srfNrml[0]=srfNrml[0]/tmpDist;
            srfNrml[1]=srfNrml[1]/tmpDist;
            srfNrml[2]=srfNrml[2]/tmpDist;
            
        }
        else {
            
            /* just compute the surface normal */
            
            srfNrml[0]=evalDeru[1]*evalDerv[2]-evalDeru[2]*evalDerv[1];
            srfNrml[1]=evalDeru[2]*evalDerv[0]-evalDeru[0]*evalDerv[2];
            srfNrml[2]=evalDeru[0]*evalDerv[1]-evalDeru[1]*evalDerv[0];
            
            tmpDist=sqrt(srfNrml[0]*srfNrml[0]+srfNrml[1]*srfNrml[1]+srfNrml[2]*srfNrml[2]);
            
            if (tmpDist>1e-50){
                
                srfNrml[0]=srfNrml[0]/tmpDist;
                srfNrml[1]=srfNrml[1]/tmpDist;
                srfNrml[2]=srfNrml[2]/tmpDist;
                
            }
            else {
                
                srfNrml[0]=0.0;
                srfNrml[1]=0.0;
                srfNrml[2]=1.0;
                
            }
            
        }
        
        corrSrfNrmls[threek]=srfNrml[0];
        corrSrfNrmls[threek+1]=srfNrml[1];
        corrSrfNrmls[threek+2]=srfNrml[2];
        
        k++;
        threek+=3;
        
    }
    
    /* ii = kcp-1, jj=ncp-1 */
    
    uv[0]=us[2*k];
    uv[1]=us[2*k+1];
    
    UVcp[2*k]=uv[0];
    UVcp[2*k+1]=uv[1];
    
    /* Compute surface normal at the corner point */
    
    nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
    
    evalDeruu[0]=evalDeru[0]*evalDeru[0]+evalDeru[1]*evalDeru[1]+evalDeru[2]*evalDeru[2];
    evalDervv[0]=evalDerv[0]*evalDerv[0]+evalDerv[1]*evalDerv[1]+evalDerv[2]*evalDerv[2];
    
    if (evalDeruu[0]<1e-20*evalDervv[0]){
        
        /* u-derivative to small to be accurate, estimate a new one */
        
        if (uv[1]>(vEnd-10.1*difrv)){
            explsign=-1.0;
        }
        else {
            explsign=1.0;
        }
        
        srfNrml[0]=0.0;
        srfNrml[1]=0.0;
        srfNrml[2]=0.0;
        
        for (i = 0; i < 10; i++){
            
            uv[1]+=explsign*difrv;
            
            nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
            
            evalDeruu[0]=evalDeru[1]*evalDerv[2]-evalDeru[2]*evalDerv[1];
            evalDeruu[1]=evalDeru[2]*evalDerv[0]-evalDeru[0]*evalDerv[2];
            evalDeruu[2]=evalDeru[0]*evalDerv[1]-evalDeru[1]*evalDerv[0];
            
            tmpDist=sqrt(evalDeruu[0]*evalDeruu[0]+evalDeruu[1]*evalDeruu[1]+evalDeruu[2]*evalDeruu[2]);
            
            srfNrml[0]+=explWghs[i]*evalDeruu[0]/tmpDist;
            srfNrml[1]+=explWghs[i]*evalDeruu[1]/tmpDist;
            srfNrml[2]+=explWghs[i]*evalDeruu[2]/tmpDist;
            
        }
        
        tmpDist=sqrt(srfNrml[0]*srfNrml[0]+srfNrml[1]*srfNrml[1]+srfNrml[2]*srfNrml[2]);
        
        srfNrml[0]=srfNrml[0]/tmpDist;
        srfNrml[1]=srfNrml[1]/tmpDist;
        srfNrml[2]=srfNrml[2]/tmpDist;
        
    }
    else if (evalDervv[0]<1e-20*evalDeruu[0]){
        
        /* v-derivative to small to be accurate, estimate a new one */
        
        if (uv[0]>(uEnd-10.1*difru)){
            explsign=-1.0;
        }
        else {
            explsign=1.0;
        }
        
        srfNrml[0]=0.0;
        srfNrml[1]=0.0;
        srfNrml[2]=0.0;
        
        for (i = 0; i < 10; i++){
            
            uv[0]+=explsign*difru;
            
            nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
            
            evalDeruu[0]=evalDeru[1]*evalDerv[2]-evalDeru[2]*evalDerv[1];
            evalDeruu[1]=evalDeru[2]*evalDerv[0]-evalDeru[0]*evalDerv[2];
            evalDeruu[2]=evalDeru[0]*evalDerv[1]-evalDeru[1]*evalDerv[0];
            
            tmpDist=sqrt(evalDeruu[0]*evalDeruu[0]+evalDeruu[1]*evalDeruu[1]+evalDeruu[2]*evalDeruu[2]);
            
            srfNrml[0]+=explWghs[i]*evalDeruu[0]/tmpDist;
            srfNrml[1]+=explWghs[i]*evalDeruu[1]/tmpDist;
            srfNrml[2]+=explWghs[i]*evalDeruu[2]/tmpDist;
            
        }
        
        tmpDist=sqrt(srfNrml[0]*srfNrml[0]+srfNrml[1]*srfNrml[1]+srfNrml[2]*srfNrml[2]);
        
        srfNrml[0]=srfNrml[0]/tmpDist;
        srfNrml[1]=srfNrml[1]/tmpDist;
        srfNrml[2]=srfNrml[2]/tmpDist;
        
    }
    else {
        
        /* just compute the surface normal */
        
        srfNrml[0]=evalDeru[1]*evalDerv[2]-evalDeru[2]*evalDerv[1];
        srfNrml[1]=evalDeru[2]*evalDerv[0]-evalDeru[0]*evalDerv[2];
        srfNrml[2]=evalDeru[0]*evalDerv[1]-evalDeru[1]*evalDerv[0];
        
        tmpDist=sqrt(srfNrml[0]*srfNrml[0]+srfNrml[1]*srfNrml[1]+srfNrml[2]*srfNrml[2]);
        
        if (tmpDist>1e-50){
            
            srfNrml[0]=srfNrml[0]/tmpDist;
            srfNrml[1]=srfNrml[1]/tmpDist;
            srfNrml[2]=srfNrml[2]/tmpDist;
            
        }
        else {
            
            srfNrml[0]=0.0;
            srfNrml[1]=0.0;
            srfNrml[2]=1.0;
            
        }
        
    }
    
    corrSrfNrmls[threek]=srfNrml[0];
    corrSrfNrmls[threek+1]=srfNrml[1];
    corrSrfNrmls[threek+2]=srfNrml[2];
    
    k++;
    threek+=3;
    
    return;
    
}

static void offsetPnt2OrgNURBSnrml(int iters, double *nrbPnt, double *orgPnts, double *usOrg, int norgp, int degUorg, int degVorg, int ncpOrg, int kcpOrg, mxArray *nrbOrgStruct, mxArray *nrbOrgDerStruct, mxArray *nrbOrgDer2Struct, double *explWghs, double *UVcp, double *srfNrml, double *leftU, double *rightU, double *NU, double *leftV, double *rightV, double *NV, double *newTdir, double *Hess, double *grad, double *uv, double *bspPnts, double *diffPnt, double *evalPnt, double *evalDeru, double *evalDerv, double *evalDeruu, double *evalDeruv, double *evalDervv){
    
    /* offsetPnt2OrgNURBSnrml(iters - maximum number of iterations when searching for closest point, nrbPnt - offset point, orgPnts - computed original points, usOrg - parameter values of original points, norgp - number of original points, degUorg - degree original, degVorg - degree original, ncpOrg - number of original control points, kcpOrg - number of original control points, nrbOrgStruct - original NURBS surface, nrbOrgDerStruct - original derivative, nrbOrgDer2Struct - original second derivative, explWghs - extrapolation weights, UVcp - original parameter values , srfNrml - original computed surface normals, leftU, rightU, NU, leftV, rightV, NV, newTdir, Hess, grad) */
    
    double tmpDist, minDist, wgh;
    double uStartOrg, uEndOrg, vStartOrg, vEndOrg, stcri, udiffOrg, vdiffOrg, difru, difrv, newtUlim, newtVlim, explsign;
    int i, j, threej, ind, bool;
    
    
    uStartOrg=mxGetPr(mxGetCell(mxGetField(nrbOrgStruct, 0, "knots"), 0))[0];
    uEndOrg=mxGetPr(mxGetCell(mxGetField(nrbOrgStruct, 0, "knots"), 0))[ncpOrg];
    vStartOrg=mxGetPr(mxGetCell(mxGetField(nrbOrgStruct, 0, "knots"), 1))[0];
    vEndOrg=mxGetPr(mxGetCell(mxGetField(nrbOrgStruct, 0, "knots"), 1))[kcpOrg];
    
    udiffOrg=uEndOrg-uStartOrg;
    vdiffOrg=vEndOrg-vStartOrg;
    
    difru=1e-12*udiffOrg;
    difrv=1e-12*vdiffOrg;
    
    newtUlim=0.1*udiffOrg;
    newtVlim=0.1*vdiffOrg;
    
    stcri=1e-6*(udiffOrg+vdiffOrg);
    
    
    /* Find closest original surface point */
    
    oneBspEval2(degUorg, degVorg, mxGetPr(mxGetField(nrbOrgStruct, 0, "coefs")), ncpOrg, kcpOrg, mxGetPr(mxGetCell(mxGetField(nrbOrgStruct, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nrbOrgStruct, 0, "knots"), 1)), UVcp, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
    
    minDist=(pwr2(bspPnts[0]/bspPnts[3]-nrbPnt[0])+pwr2(bspPnts[1]/bspPnts[3]-nrbPnt[1])+pwr2(bspPnts[2]/bspPnts[3]-nrbPnt[2]))*0.999999999999;
    ind=-1;
    
    threej=0;
    for (j = 0; j < norgp; j++){
        tmpDist=pwr2(nrbPnt[0]-orgPnts[threej])+pwr2(nrbPnt[1]-orgPnts[threej+1])+pwr2(nrbPnt[2]-orgPnts[threej+2]);
        if (tmpDist<minDist){
            ind=j;
            minDist=tmpDist;
        }
        threej+=3;
    }
    
    if (ind<0){
        
        minDist=minDist/0.999999999999;
        
        bool=0;
        if (UVcp[0]>(uEndOrg-10.0*difru)){
            uv[0]=UVcp[0]-1e-6*udiffOrg;
            bool=1;
        }
        else if (UVcp[0]<(uStartOrg+10.0*difru)){
            uv[0]=UVcp[0]+1e-6*udiffOrg;
            bool=1;
        }
        else {
            uv[0]=UVcp[0];
            uv[1]=UVcp[1];
        }
        
        if (bool){
            
            uv[1]=vStartOrg+0.025*vdiffOrg;
            
            for (j = 0; j < 20; j++){
                
                oneBspEval2(degUorg, degVorg, mxGetPr(mxGetField(nrbOrgStruct, 0, "coefs")), ncpOrg, kcpOrg, mxGetPr(mxGetCell(mxGetField(nrbOrgStruct, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nrbOrgStruct, 0, "knots"), 1)), uv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                tmpDist=pwr2(bspPnts[0]/bspPnts[3]-nrbPnt[0])+pwr2(bspPnts[1]/bspPnts[3]-nrbPnt[1])+pwr2(bspPnts[2]/bspPnts[3]-nrbPnt[2]);
                
                if (tmpDist<minDist){
                    ind=j;
                    minDist=tmpDist;
                }
                
                uv[1]+=0.05*vdiffOrg;
                
            }
            
            if (ind<0){
                uv[0]=UVcp[0];
                uv[1]=UVcp[1];
            }
            else {
                uv[1]=vStartOrg+(0.025+((double)ind)*0.05)*vdiffOrg;
            }
            
        }
        
        bool=0;
        if (uv[1]>(vEndOrg-10.0*difrv)){
            evalDeruv[0]=uv[0];
            evalDeruv[1]=uv[1];
            uv[1]-=1e-6*vdiffOrg;
            bool=1;
        }
        else if (uv[1]<(vStartOrg+10.0*difrv)){
            evalDeruv[0]=uv[0];
            evalDeruv[1]=uv[1];
            uv[1]+=1e-6*vdiffOrg;
            bool=1;
        }
        
        if (bool){
            
            ind=-1;
            
            uv[0]=uStartOrg+0.025*udiffOrg;
            
            for (j = 0; j < 20; j++){
                
                oneBspEval2(degUorg, degVorg, mxGetPr(mxGetField(nrbOrgStruct, 0, "coefs")), ncpOrg, kcpOrg, mxGetPr(mxGetCell(mxGetField(nrbOrgStruct, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nrbOrgStruct, 0, "knots"), 1)), uv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                tmpDist=pwr2(bspPnts[0]/bspPnts[3]-nrbPnt[0])+pwr2(bspPnts[1]/bspPnts[3]-nrbPnt[1])+pwr2(bspPnts[2]/bspPnts[3]-nrbPnt[2]);
                
                if (tmpDist<minDist){
                    ind=j;
                    minDist=tmpDist;
                }
                
                uv[0]+=0.05*udiffOrg;
                
            }
            
            if (ind<0){
                uv[0]=evalDeruv[0];
                uv[1]=evalDeruv[1];
            }
            else {
                uv[0]=uStartOrg+(0.025+((double)ind)*0.05)*udiffOrg;
            }
            
        }
        
    }
    else {
        
        uv[0]=usOrg[2*ind];
        uv[1]=usOrg[2*ind+1];
        
    }
    
    /* Iterate to find a closer original surface point */
    
    bool=0;
    
    for (i = 0; i < iters; i++){
        
        if (bool){
            break;
        }
        
        /* Compute gradient and Hessian */
        
        nrbD1D2eval2(degUorg+1, degVorg+1, ncpOrg, kcpOrg, nrbOrgStruct, nrbOrgDerStruct, nrbOrgDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
        
        diffPnt[0]=evalPnt[0]-nrbPnt[0];
        diffPnt[1]=evalPnt[1]-nrbPnt[1];
        diffPnt[2]=evalPnt[2]-nrbPnt[2];
        
        minDist=diffPnt[0]*diffPnt[0]+diffPnt[1]*diffPnt[1]+diffPnt[2]*diffPnt[2];
        
        grad[0]=evalDeru[0]*diffPnt[0]+evalDeru[1]*diffPnt[1]+evalDeru[2]*diffPnt[2];
        grad[1]=evalDerv[0]*diffPnt[0]+evalDerv[1]*diffPnt[1]+evalDerv[2]*diffPnt[2];
        
        Hess[0]=evalDeruu[0]*diffPnt[0]+evalDeruu[1]*diffPnt[1]+evalDeruu[2]*diffPnt[2] + evalDeru[0]*evalDeru[0]+evalDeru[1]*evalDeru[1]+evalDeru[2]*evalDeru[2];
        Hess[1]=evalDeruv[0]*diffPnt[0]+evalDeruv[1]*diffPnt[1]+evalDeruv[2]*diffPnt[2] + evalDeru[0]*evalDerv[0]+evalDeru[1]*evalDerv[1]+evalDeru[2]*evalDerv[2];
        Hess[2]=evalDervv[0]*diffPnt[0]+evalDervv[1]*diffPnt[1]+evalDervv[2]*diffPnt[2] + evalDerv[0]*evalDerv[0]+evalDerv[1]*evalDerv[1]+evalDerv[2]*evalDerv[2];
        
        /* CGM - two iterations */
        
        evalDerv[0]=grad[0];
        evalDerv[1]=grad[1];
        
        evalDeru[0]=evalDerv[0];
        evalDeru[1]=evalDerv[1];
        
        wgh=evalDerv[0]*evalDerv[0]+evalDerv[1]*evalDerv[1];
        
        if (wgh>1e-50){
            
            evalDeruu[0]=Hess[0]*evalDeru[0]+Hess[1]*evalDeru[1];
            evalDeruu[1]=Hess[1]*evalDeru[0]+Hess[2]*evalDeru[1];
            
            tmpDist=evalDeru[0]*evalDeruu[0]+evalDeru[1]*evalDeruu[1];
            
            if (wgh<1e20*fabs(tmpDist)){
                
                tmpDist=wgh/tmpDist;
                
                if (tmpDist<0){
                    
                    newTdir[0]=-grad[0];
                    newTdir[1]=-grad[1];
                    
                }
                else {
                    
                    newTdir[0]=-tmpDist*evalDeru[0];
                    newTdir[1]=-tmpDist*evalDeru[1];
                    
                    evalDerv[0]-=tmpDist*evalDeruu[0];
                    evalDerv[1]-=tmpDist*evalDeruu[1];
                    
                    bspPnts[0]=evalDerv[0]*evalDerv[0]+evalDerv[1]*evalDerv[1];
                    
                    if (bspPnts[0]>1e-25){
                        
                        evalDeru[0]=evalDerv[0]+(bspPnts[0]*evalDeru[0])/wgh;
                        evalDeru[1]=evalDerv[1]+(bspPnts[0]*evalDeru[1])/wgh;
                        
                        wgh=bspPnts[0];
                        
                        evalDeruu[0]=Hess[0]*evalDeru[0]+Hess[1]*evalDeru[1];
                        evalDeruu[1]=Hess[1]*evalDeru[0]+Hess[2]*evalDeru[1];
                        
                        tmpDist=evalDeru[0]*evalDeruu[0]+evalDeru[1]*evalDeruu[1];
                        
                        if (wgh<1e10*fabs(tmpDist)){
                            
                            tmpDist=wgh/tmpDist;
                            
                            if (tmpDist<0){
                                
                                newTdir[0]+=0.5*tmpDist*evalDeru[0];
                                newTdir[1]+=0.5*tmpDist*evalDeru[1];
                                
                            }
                            else {
                                
                                newTdir[0]-=tmpDist*evalDeru[0];
                                newTdir[1]-=tmpDist*evalDeru[1];
                                
                            }
                            
                        }
                        
                    }
                    
                }
                
            }
            else {
                
                newTdir[0]=-grad[0];
                newTdir[1]=-grad[1];
                
            }
            
            /* Scale search direction if neccecary */
            
            if (newTdir[0]<-newtUlim){
                newTdir[1]=-newtUlim*newTdir[1]/newTdir[0];
                newTdir[0]=-newtUlim;
            }
            else if (newTdir[0]>newtUlim){
                newTdir[1]=newtUlim*newTdir[1]/newTdir[0];
                newTdir[0]=newtUlim;
            }
            if (newTdir[1]<-newtVlim){
                newTdir[0]=-newtVlim*newTdir[0]/newTdir[1];
                newTdir[1]=-newtVlim;
            }
            else if (newTdir[1]>newtVlim){
                newTdir[0]=newtVlim*newTdir[0]/newTdir[1];
                newTdir[1]=newtVlim;
            }
            
            /* Apply line search */
            
            evalDeru[0]=0.5*(newTdir[0]*grad[0]+newTdir[1]*grad[1]);
            
            wgh=1.0;
            bool=1;
            for (j = 0; j < 15; j++){
                
                evalDeruv[0]=uv[0]+wgh*newTdir[0];
                evalDeruv[1]=uv[1]+wgh*newTdir[1];
                
                oneBspEval2(degUorg, degVorg, mxGetPr(mxGetField(nrbOrgStruct, 0, "coefs")), ncpOrg, kcpOrg, mxGetPr(mxGetCell(mxGetField(nrbOrgStruct, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nrbOrgStruct, 0, "knots"), 1)), evalDeruv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                
                tmpDist=pwr2(bspPnts[0]/bspPnts[3]-nrbPnt[0])+pwr2(bspPnts[1]/bspPnts[3]-nrbPnt[1])+pwr2(bspPnts[2]/bspPnts[3]-nrbPnt[2]);
                
                if (tmpDist<(minDist+wgh*evalDeru[0])){
                    uv[0]=evalDeruv[0];
                    uv[1]=evalDeruv[1];
                    
                    if (wgh*(fabs(newTdir[0])+fabs(newTdir[1]))>stcri){
                        bool=0;
                    }
                    break;
                }
                else {
                    wgh=wgh*0.75;
                }
                
            }
            
        }
        else {
            bool=1;
        }
        
        /* Parameter values must be inside the domain */
        
        if (uv[0]<uStartOrg){
            uv[0]=uStartOrg;
        }
        else if (uv[0]>uEndOrg){
            uv[0]=uEndOrg;
        }
        if (uv[1]<vStartOrg){
            uv[1]=vStartOrg;
        }
        else if (uv[1]>vEndOrg){
            uv[1]=vEndOrg;
        }
        
    }
    
    /* Compute surface normal at the closest point */
    
    nrbD1D2eval2(degUorg+1, degVorg+1, ncpOrg, kcpOrg, nrbOrgStruct, nrbOrgDerStruct, nrbOrgDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
    
    evalDeruu[0]=evalDeru[0]*evalDeru[0]+evalDeru[1]*evalDeru[1]+evalDeru[2]*evalDeru[2];
    evalDervv[0]=evalDerv[0]*evalDerv[0]+evalDerv[1]*evalDerv[1]+evalDerv[2]*evalDerv[2];
    
    if (evalDeruu[0]<1e-20*evalDervv[0]){
        
        /* u-derivative to small to be accurate, estimate a new one */
        
        if (uv[1]>(vEndOrg-10.1*difrv)){
            explsign=-1.0;
        }
        else {
            explsign=1.0;
        }
        
        srfNrml[0]=0.0;
        srfNrml[1]=0.0;
        srfNrml[2]=0.0;
        
        for (i = 0; i < 10; i++){
            
            uv[1]+=explsign*difrv;
            
            nrbD1D2eval2(degUorg+1, degVorg+1, ncpOrg, kcpOrg, nrbOrgStruct, nrbOrgDerStruct, nrbOrgDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
            
            evalDeruu[0]=evalDeru[1]*evalDerv[2]-evalDeru[2]*evalDerv[1];
            evalDeruu[1]=evalDeru[2]*evalDerv[0]-evalDeru[0]*evalDerv[2];
            evalDeruu[2]=evalDeru[0]*evalDerv[1]-evalDeru[1]*evalDerv[0];
            
            tmpDist=sqrt(evalDeruu[0]*evalDeruu[0]+evalDeruu[1]*evalDeruu[1]+evalDeruu[2]*evalDeruu[2]);
            
            srfNrml[0]+=explWghs[i]*evalDeruu[0]/tmpDist;
            srfNrml[1]+=explWghs[i]*evalDeruu[1]/tmpDist;
            srfNrml[2]+=explWghs[i]*evalDeruu[2]/tmpDist;
            
        }
        
        tmpDist=sqrt(srfNrml[0]*srfNrml[0]+srfNrml[1]*srfNrml[1]+srfNrml[2]*srfNrml[2]);
        
        srfNrml[0]=srfNrml[0]/tmpDist;
        srfNrml[1]=srfNrml[1]/tmpDist;
        srfNrml[2]=srfNrml[2]/tmpDist;
        
    }
    else if (evalDervv[0]<1e-20*evalDeruu[0]){
        
        /* v-derivative to small to be accurate, estimate a new one */
        
        if (uv[0]>(uEndOrg-10.1*difru)){
            explsign=-1.0;
        }
        else {
            explsign=1.0;
        }
        
        srfNrml[0]=0.0;
        srfNrml[1]=0.0;
        srfNrml[2]=0.0;
        
        for (i = 0; i < 10; i++){
            
            uv[0]+=explsign*difru;
            
            nrbD1D2eval2(degUorg+1, degVorg+1, ncpOrg, kcpOrg, nrbOrgStruct, nrbOrgDerStruct, nrbOrgDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
            
            evalDeruu[0]=evalDeru[1]*evalDerv[2]-evalDeru[2]*evalDerv[1];
            evalDeruu[1]=evalDeru[2]*evalDerv[0]-evalDeru[0]*evalDerv[2];
            evalDeruu[2]=evalDeru[0]*evalDerv[1]-evalDeru[1]*evalDerv[0];
            
            tmpDist=sqrt(evalDeruu[0]*evalDeruu[0]+evalDeruu[1]*evalDeruu[1]+evalDeruu[2]*evalDeruu[2]);
            
            srfNrml[0]+=explWghs[i]*evalDeruu[0]/tmpDist;
            srfNrml[1]+=explWghs[i]*evalDeruu[1]/tmpDist;
            srfNrml[2]+=explWghs[i]*evalDeruu[2]/tmpDist;
            
        }
        
        tmpDist=sqrt(srfNrml[0]*srfNrml[0]+srfNrml[1]*srfNrml[1]+srfNrml[2]*srfNrml[2]);
        
        srfNrml[0]=srfNrml[0]/tmpDist;
        srfNrml[1]=srfNrml[1]/tmpDist;
        srfNrml[2]=srfNrml[2]/tmpDist;
        
    }
    else {
        
        /* just compute the surface normal */
        
        srfNrml[0]=evalDeru[1]*evalDerv[2]-evalDeru[2]*evalDerv[1];
        srfNrml[1]=evalDeru[2]*evalDerv[0]-evalDeru[0]*evalDerv[2];
        srfNrml[2]=evalDeru[0]*evalDerv[1]-evalDeru[1]*evalDerv[0];
        
        tmpDist=sqrt(srfNrml[0]*srfNrml[0]+srfNrml[1]*srfNrml[1]+srfNrml[2]*srfNrml[2]);
        
        if (tmpDist>1e-50){
            
            srfNrml[0]=srfNrml[0]/tmpDist;
            srfNrml[1]=srfNrml[1]/tmpDist;
            srfNrml[2]=srfNrml[2]/tmpDist;
            
        }
        else {
            
            srfNrml[0]=0.0;
            srfNrml[1]=0.0;
            srfNrml[2]=1.0;
            
        }
        
    }
    
    return;
    
}

static void findCPdir(int iters, int degU, int degV, double *cp, int ncp, int kcp, double *knotU, double *knotV, double *us, mxArray *nrbStruct, mxArray *nrbDerStruct, mxArray *nrbDer2Struct, double *UVcp, double *orgPnts, double *usOrg, int norgp, int degUorg, int degVorg, int ncpOrg, int kcpOrg, mxArray *nrbOrgStruct, mxArray *nrbOrgDerStruct, mxArray *nrbOrgDer2Struct, double *explWghs, double *cpDir, double *leftU, double *rightU, double *NU, double *leftV, double *rightV, double *NV){
    
    /* findCPdir(iters - maximum number of iterations when searching for closest point, degU - degree of offset surface, degV - degree of offset surface, cp - offset control points, ncp - number of offset control points, kcp - number of offset control points, knotU - offset knot vector, knotV - offset knot vector, us - parameter values of original points, nrbStruct - original NURBS surface, nrbDerStruct - original derivative, nrbDer2Struct - original second derivative, UVorg - parameter values of original surface, cpDir - original computed surface normals, leftU, rightU, NU, leftV, rightV, NV) */
    
    int ii, jj, i, j, k=0;
    double tmpDist, minDist, nrbPnt[3], controlPnt[3], wgh, uv[2], bspPnts[4], diffPnt[3], evalPnt[3], evalDeru[3], evalDerv[3], evalDeruu[3], evalDeruv[3], evalDervv[3], explsign;
    double uStart, uEnd, vStart, vEnd, stcri, udiff, vdiff, difru, difrv, newtUlim, newtVlim, newTdir[2], Hess[3], grad[2];
    int spanU, spanV, ind, ind2, myint, fourncp, bool;
    
    fourncp=4*ncp;
    
    uStart=knotU[0];
    uEnd=knotU[ncp];
    vStart=knotV[0];
    vEnd=knotV[kcp];
    
    udiff=uEnd-uStart;
    vdiff=vEnd-vStart;
    
    difru=1e-12*udiff;
    difrv=1e-12*vdiff;
    
    newtUlim=0.1*udiff;
    newtVlim=0.1*vdiff;
    
    stcri=1e-8*(udiff+vdiff);
    
    
    /* ii = 0, jj=0 */
    
    nrbPnt[0]=cp[0]/cp[3];
    nrbPnt[1]=cp[1]/cp[3];
    nrbPnt[2]=cp[2]/cp[3];
    
    offsetPnt2OrgNURBSnrml(iters, nrbPnt, orgPnts, usOrg, norgp, degUorg, degVorg, ncpOrg, kcpOrg, nrbOrgStruct, nrbOrgDerStruct, nrbOrgDer2Struct, explWghs, &UVcp[2*k], &cpDir[3*k], leftU, rightU, NU, leftV, rightV, NV, newTdir, Hess, grad, uv, bspPnts, diffPnt, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv);
    
    k++;
    
    /* ii = 0, jj=1,2,...,ncp-2 */
    
    for (jj = 1; jj <= (ncp-2); jj++){
        
        /* Initial parameters */
        
        uv[0]=us[2*k];
        uv[1]=us[2*k+1];
        
        nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
        
        if ((evalDeru[0]*evalDeru[0]+evalDeru[1]*evalDeru[1]+evalDeru[2]*evalDeru[2])<1e-16*(evalDerv[0]*evalDerv[0]+evalDerv[1]*evalDerv[1]+evalDerv[2]*evalDerv[2])){
            
            /* Surface normal not defined, using extrapolation */
            
            uv[1]+=10.0*difrv;
            explsign=0.0;
            
            for (ii = 9; ii >= 0; ii--){
                
                /* Compute unweighted control point */
                
                spanV = FindSpan(kcp, degV, uv[1], knotV);
                BasisFuns(spanV, uv[1], degV, knotV, NV, leftV, rightV);
                
                ind2 = spanV - degV;
                myint=ind2*fourncp+jj*4;
                
                bspPnts[0]=0.0;
                bspPnts[1]=0.0;
                bspPnts[2]=0.0;
                bspPnts[3]=0.0;
                for (i = 0; i <= degV; i++){
                    bspPnts[0] += NV[i] * cp[i*fourncp+myint];
                    bspPnts[1] += NV[i] * cp[i*fourncp+myint+1];
                    bspPnts[2] += NV[i] * cp[i*fourncp+myint+2];
                    bspPnts[3] += NV[i] * cp[i*fourncp+myint+3];
                }
                
                controlPnt[0]=bspPnts[0]/bspPnts[3];
                controlPnt[1]=bspPnts[1]/bspPnts[3];
                controlPnt[2]=bspPnts[2]/bspPnts[3];
                
                /* Iterate to find the closest NURBS surface point */
                
                bool=0;
                
                for (i = 0; i < iters; i++){
                    
                    if (bool){
                        break;
                    }
                    
                    /* Compute gradient and Hessian */
                    
                    nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                    
                    diffPnt[0]=evalPnt[0]-controlPnt[0];
                    diffPnt[1]=evalPnt[1]-controlPnt[1];
                    diffPnt[2]=evalPnt[2]-controlPnt[2];
                    
                    minDist=diffPnt[0]*diffPnt[0]+diffPnt[1]*diffPnt[1]+diffPnt[2]*diffPnt[2];
                    
                    grad[0]=evalDeru[0]*diffPnt[0]+evalDeru[1]*diffPnt[1]+evalDeru[2]*diffPnt[2];
                    
                    Hess[0]=evalDeruu[0]*diffPnt[0]+evalDeruu[1]*diffPnt[1]+evalDeruu[2]*diffPnt[2] + evalDeru[0]*evalDeru[0]+evalDeru[1]*evalDeru[1]+evalDeru[2]*evalDeru[2];
                    
                    if (1e12*Hess[0]<=fabs(grad[0])){
                        newTdir[0]=-grad[0];
                    }
                    else {
                        newTdir[0]=-grad[0]/Hess[0];
                    }
                    
                    /* Scale search direction if neccecary */
                    
                    if (newTdir[0]<-newtUlim){
                        newTdir[0]=-newtUlim;
                    }
                    else if (newTdir[0]>newtUlim){
                        newTdir[0]=newtUlim;
                    }
                    
                    /* Apply line search */
                    
                    evalDeru[0]=0.5*(newTdir[0]*grad[0]);
                    
                    wgh=1.0;
                    bool=1;
                    evalDeruv[1]=uv[1];
                    
                    for (j = 0; j < 15; j++){
                        
                        evalDeruv[0]=uv[0]+wgh*newTdir[0];
                        
                        oneBspEval2(degU, degV, mxGetPr(mxGetField(nrbStruct, 0, "coefs")), ncp, kcp, mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 1)), evalDeruv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                        
                        tmpDist=pwr2(bspPnts[0]/bspPnts[3]-controlPnt[0])+pwr2(bspPnts[1]/bspPnts[3]-controlPnt[1])+pwr2(bspPnts[2]/bspPnts[3]-controlPnt[2]);
                        
                        if (tmpDist<(minDist+wgh*evalDeru[0])){
                            uv[0]=evalDeruv[0];
                            
                            if (wgh*(fabs(newTdir[0]))>stcri){
                                bool=0;
                            }
                            break;
                        }
                        else {
                            wgh=wgh*0.75;
                        }
                        
                    }
                    
                    /* Parameter values must be inside the domain */
                    
                    if (uv[0]<uStart){
                        uv[0]=uStart;
                    }
                    else if (uv[0]>uEnd){
                        uv[0]=uEnd;
                    }
                    
                }
                
                uv[1]-=difrv;
                explsign+=explWghs[ii]*uv[0];
                
            }
            
            uv[0]=explsign;
            uv[1]=us[2*k+1];
            
        }
        else {
            
            /* Surface normal exists */
            
            /* Compute unweighted control point */
            
            controlPnt[0]=cp[4*k]/cp[4*k+3];
            controlPnt[1]=cp[4*k+1]/cp[4*k+3];
            controlPnt[2]=cp[4*k+2]/cp[4*k+3];
            
            /* Iterate to find the closest NURBS surface point to the control point */
            
            bool=0;
            
            for (i = 0; i < iters; i++){
                
                if (bool){
                    break;
                }
                
                /* Compute gradient and Hessian */
                
                nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                
                diffPnt[0]=evalPnt[0]-controlPnt[0];
                diffPnt[1]=evalPnt[1]-controlPnt[1];
                diffPnt[2]=evalPnt[2]-controlPnt[2];
                
                minDist=diffPnt[0]*diffPnt[0]+diffPnt[1]*diffPnt[1]+diffPnt[2]*diffPnt[2];
                
                grad[0]=evalDeru[0]*diffPnt[0]+evalDeru[1]*diffPnt[1]+evalDeru[2]*diffPnt[2];
                
                Hess[0]=evalDeruu[0]*diffPnt[0]+evalDeruu[1]*diffPnt[1]+evalDeruu[2]*diffPnt[2] + evalDeru[0]*evalDeru[0]+evalDeru[1]*evalDeru[1]+evalDeru[2]*evalDeru[2];
                
                if (1e12*Hess[0]<=fabs(grad[0])){
                    newTdir[0]=-grad[0];
                }
                else {
                    newTdir[0]=-grad[0]/Hess[0];
                }
                
                /* Scale search direction if neccecary */
                
                if (newTdir[0]<-newtUlim){
                    newTdir[0]=-newtUlim;
                }
                else if (newTdir[0]>newtUlim){
                    newTdir[0]=newtUlim;
                }
                
                /* Apply line search */
                
                evalDeru[0]=0.5*(newTdir[0]*grad[0]);
                
                wgh=1.0;
                bool=1;
                evalDeruv[1]=uv[1];
                
                for (j = 0; j < 15; j++){
                    
                    evalDeruv[0]=uv[0]+wgh*newTdir[0];
                    
                    oneBspEval2(degU, degV, mxGetPr(mxGetField(nrbStruct, 0, "coefs")), ncp, kcp, mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 1)), evalDeruv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                    
                    tmpDist=pwr2(bspPnts[0]/bspPnts[3]-controlPnt[0])+pwr2(bspPnts[1]/bspPnts[3]-controlPnt[1])+pwr2(bspPnts[2]/bspPnts[3]-controlPnt[2]);
                    
                    if (tmpDist<(minDist+wgh*evalDeru[0])){
                        uv[0]=evalDeruv[0];
                        
                        if (wgh*(fabs(newTdir[0]))>stcri){
                            bool=0;
                        }
                        break;
                    }
                    else {
                        wgh=wgh*0.75;
                    }
                    
                }
                
                /* Parameter values must be inside the domain */
                
                if (uv[0]<uStart){
                    uv[0]=uStart;
                }
                else if (uv[0]>uEnd){
                    uv[0]=uEnd;
                }
                
            }
            
        }
        
        oneBspEval2(degU, degV, mxGetPr(mxGetField(nrbStruct, 0, "coefs")), ncp, kcp, mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 1)), uv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
        
        nrbPnt[0]=bspPnts[0]/bspPnts[3];
        nrbPnt[1]=bspPnts[1]/bspPnts[3];
        nrbPnt[2]=bspPnts[2]/bspPnts[3];
        
        offsetPnt2OrgNURBSnrml(iters, nrbPnt, orgPnts, usOrg, norgp, degUorg, degVorg, ncpOrg, kcpOrg, nrbOrgStruct, nrbOrgDerStruct, nrbOrgDer2Struct, explWghs, &UVcp[2*k], &cpDir[3*k], leftU, rightU, NU, leftV, rightV, NV, newTdir, Hess, grad, uv, bspPnts, diffPnt, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv);
        
        k++;
        
    }
    
    /* ii = 0, jj=ncp-1 */
    
    nrbPnt[0]=cp[4*k]/cp[4*k+3];
    nrbPnt[1]=cp[4*k+1]/cp[4*k+3];
    nrbPnt[2]=cp[4*k+2]/cp[4*k+3];
    
    offsetPnt2OrgNURBSnrml(iters, nrbPnt, orgPnts, usOrg, norgp, degUorg, degVorg, ncpOrg, kcpOrg, nrbOrgStruct, nrbOrgDerStruct, nrbOrgDer2Struct, explWghs, &UVcp[2*k], &cpDir[3*k], leftU, rightU, NU, leftV, rightV, NV, newTdir, Hess, grad, uv, bspPnts, diffPnt, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv);
    
    k++;
    
    /* ii = 1,2,...,kcp-2, jj=0,1,2,...,ncp-2,ncp-1 */
    
    for (ii = 1; ii <= (kcp-2); ii++){
        
        /* Initial parameters */
        
        uv[0]=us[2*k];
        uv[1]=us[2*k+1];
        
        nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
        
        if ((evalDerv[0]*evalDerv[0]+evalDerv[1]*evalDerv[1]+evalDerv[2]*evalDerv[2])<1e-16*(evalDeru[0]*evalDeru[0]+evalDeru[1]*evalDeru[1]+evalDeru[2]*evalDeru[2])){
            
            /* Surface normal not defined, using extrapolation */
            
            uv[0]+=10.0*difru;
            explsign=0.0;
            
            for (jj = 9; jj >= 0; jj--){
                
                /* Compute unweighted control point */
                
                spanU = FindSpan(ncp, degU, uv[0], knotU);
                BasisFuns(spanU, uv[0], degU, knotU, NU, leftU, rightU);
                
                ind = spanU - degU;
                myint=ii*fourncp+ind*4;
                
                bspPnts[0]=0.0;
                bspPnts[1]=0.0;
                bspPnts[2]=0.0;
                bspPnts[3]=0.0;
                for (j = 0; j <= degU; j++){
                    bspPnts[0] += NU[j] * cp[j*4+myint];
                    bspPnts[1] += NU[j] * cp[j*4+myint+1];
                    bspPnts[2] += NU[j] * cp[j*4+myint+2];
                    bspPnts[3] += NU[j] * cp[j*4+myint+3];
                }
                
                controlPnt[0]=bspPnts[0]/bspPnts[3];
                controlPnt[1]=bspPnts[1]/bspPnts[3];
                controlPnt[2]=bspPnts[2]/bspPnts[3];
                
                /* Iterate to find the closest NURBS surface point */
                
                bool=0;
                
                for (i = 0; i < iters; i++){
                    
                    if (bool){
                        break;
                    }
                    
                    /* Compute gradient and Hessian */
                    
                    nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                    
                    diffPnt[0]=evalPnt[0]-controlPnt[0];
                    diffPnt[1]=evalPnt[1]-controlPnt[1];
                    diffPnt[2]=evalPnt[2]-controlPnt[2];
                    
                    minDist=diffPnt[0]*diffPnt[0]+diffPnt[1]*diffPnt[1]+diffPnt[2]*diffPnt[2];
                    
                    grad[1]=evalDerv[0]*diffPnt[0]+evalDerv[1]*diffPnt[1]+evalDerv[2]*diffPnt[2];
                    
                    Hess[2]=evalDervv[0]*diffPnt[0]+evalDervv[1]*diffPnt[1]+evalDervv[2]*diffPnt[2] + evalDerv[0]*evalDerv[0]+evalDerv[1]*evalDerv[1]+evalDerv[2]*evalDerv[2];
                    
                    if (1e12*Hess[2]<=fabs(grad[1])){
                        newTdir[1]=-grad[1];
                    }
                    else {
                        newTdir[1]=-grad[1]/Hess[2];
                    }
                    
                    /* Scale search direction if neccecary */
                    
                    if (newTdir[1]<-newtVlim){
                        newTdir[1]=-newtVlim;
                    }
                    else if (newTdir[1]>newtVlim){
                        newTdir[1]=newtVlim;
                    }
                    
                    /* Apply line search */
                    
                    evalDeru[0]=0.5*(newTdir[1]*grad[1]);
                    
                    wgh=1.0;
                    bool=1;
                    evalDeruv[0]=uv[0];
                    
                    for (j = 0; j < 15; j++){
                        
                        evalDeruv[1]=uv[1]+wgh*newTdir[1];
                        
                        oneBspEval2(degU, degV, mxGetPr(mxGetField(nrbStruct, 0, "coefs")), ncp, kcp, mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 1)), evalDeruv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                        
                        tmpDist=pwr2(bspPnts[0]/bspPnts[3]-controlPnt[0])+pwr2(bspPnts[1]/bspPnts[3]-controlPnt[1])+pwr2(bspPnts[2]/bspPnts[3]-controlPnt[2]);
                        
                        if (tmpDist<(minDist+wgh*evalDeru[0])){
                            uv[1]=evalDeruv[1];
                            
                            if (wgh*(fabs(newTdir[1]))>stcri){
                                bool=0;
                            }
                            break;
                        }
                        else {
                            wgh=wgh*0.75;
                        }
                        
                    }
                    
                    /* Parameter values must be inside the domain */
                    
                    if (uv[1]<vStart){
                        uv[1]=vStart;
                    }
                    else if (uv[1]>vEnd){
                        uv[1]=vEnd;
                    }
                    
                }
                
                uv[0]-=difru;
                explsign+=explWghs[jj]*uv[1];
                
            }
            
            uv[0]=us[2*k];
            uv[1]=explsign;
            
        }
        else {
            
            /* Surface normal exists */
            
            /* Compute unweighted control point */
            
            controlPnt[0]=cp[4*k]/cp[4*k+3];
            controlPnt[1]=cp[4*k+1]/cp[4*k+3];
            controlPnt[2]=cp[4*k+2]/cp[4*k+3];
            
            /* Iterate to find the closest NURBS surface point */
            
            bool=0;
            
            for (i = 0; i < iters; i++){
                
                if (bool){
                    break;
                }
                
                /* Compute gradient and Hessian */
                
                nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                
                diffPnt[0]=evalPnt[0]-controlPnt[0];
                diffPnt[1]=evalPnt[1]-controlPnt[1];
                diffPnt[2]=evalPnt[2]-controlPnt[2];
                
                minDist=diffPnt[0]*diffPnt[0]+diffPnt[1]*diffPnt[1]+diffPnt[2]*diffPnt[2];
                
                grad[1]=evalDerv[0]*diffPnt[0]+evalDerv[1]*diffPnt[1]+evalDerv[2]*diffPnt[2];
                
                Hess[2]=evalDervv[0]*diffPnt[0]+evalDervv[1]*diffPnt[1]+evalDervv[2]*diffPnt[2] + evalDerv[0]*evalDerv[0]+evalDerv[1]*evalDerv[1]+evalDerv[2]*evalDerv[2];
                
                if (1e12*Hess[2]<=fabs(grad[1])){
                    newTdir[1]=-grad[1];
                }
                else {
                    newTdir[1]=-grad[1]/Hess[2];
                }
                
                /* Scale search direction if neccecary */
                
                if (newTdir[1]<-newtVlim){
                    newTdir[1]=-newtVlim;
                }
                else if (newTdir[1]>newtVlim){
                    newTdir[1]=newtVlim;
                }
                
                /* Apply line search */
                
                evalDeru[0]=0.5*(newTdir[1]*grad[1]);
                
                wgh=1.0;
                bool=1;
                evalDeruv[0]=uv[0];
                
                for (j = 0; j < 15; j++){
                    
                    evalDeruv[1]=uv[1]+wgh*newTdir[1];
                    
                    oneBspEval2(degU, degV, mxGetPr(mxGetField(nrbStruct, 0, "coefs")), ncp, kcp, mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 1)), evalDeruv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                    
                    tmpDist=pwr2(bspPnts[0]/bspPnts[3]-controlPnt[0])+pwr2(bspPnts[1]/bspPnts[3]-controlPnt[1])+pwr2(bspPnts[2]/bspPnts[3]-controlPnt[2]);
                    
                    if (tmpDist<(minDist+wgh*evalDeru[0])){
                        uv[1]=evalDeruv[1];
                        
                        if (wgh*(fabs(newTdir[1]))>stcri){
                            bool=0;
                        }
                        break;
                    }
                    else {
                        wgh=wgh*0.75;
                    }
                    
                }
                
                /* Parameter values must be inside the domain */
                
                if (uv[1]<vStart){
                    uv[1]=vStart;
                }
                else if (uv[1]>vEnd){
                    uv[1]=vEnd;
                }
                
            }
            
        }
        
        oneBspEval2(degU, degV, mxGetPr(mxGetField(nrbStruct, 0, "coefs")), ncp, kcp, mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 1)), uv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
        
        nrbPnt[0]=bspPnts[0]/bspPnts[3];
        nrbPnt[1]=bspPnts[1]/bspPnts[3];
        nrbPnt[2]=bspPnts[2]/bspPnts[3];
        
        offsetPnt2OrgNURBSnrml(iters, nrbPnt, orgPnts, usOrg, norgp, degUorg, degVorg, ncpOrg, kcpOrg, nrbOrgStruct, nrbOrgDerStruct, nrbOrgDer2Struct, explWghs, &UVcp[2*k], &cpDir[3*k], leftU, rightU, NU, leftV, rightV, NV, newTdir, Hess, grad, uv, bspPnts, diffPnt, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv);
        
        k++;
        
        for (jj = 1; jj <= (ncp-2); jj++){
            
            /* Compute unweighted control point */
            
            controlPnt[0]=cp[4*k]/cp[4*k+3];
            controlPnt[1]=cp[4*k+1]/cp[4*k+3];
            controlPnt[2]=cp[4*k+2]/cp[4*k+3];
            
            /* Initial parameters */
            
            uv[0]=us[2*k];
            uv[1]=us[2*k+1];
            
            /* Iterate to find the closest NURBS surface point */
            
            bool=0;
            
            for (i = 0; i < iters; i++){
                
                if (bool){
                    break;
                }
                
                /* Compute gradient and Hessian */
                
                nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                
                diffPnt[0]=evalPnt[0]-controlPnt[0];
                diffPnt[1]=evalPnt[1]-controlPnt[1];
                diffPnt[2]=evalPnt[2]-controlPnt[2];
                
                minDist=diffPnt[0]*diffPnt[0]+diffPnt[1]*diffPnt[1]+diffPnt[2]*diffPnt[2];
                
                grad[0]=evalDeru[0]*diffPnt[0]+evalDeru[1]*diffPnt[1]+evalDeru[2]*diffPnt[2];
                grad[1]=evalDerv[0]*diffPnt[0]+evalDerv[1]*diffPnt[1]+evalDerv[2]*diffPnt[2];
                
                Hess[0]=evalDeruu[0]*diffPnt[0]+evalDeruu[1]*diffPnt[1]+evalDeruu[2]*diffPnt[2] + evalDeru[0]*evalDeru[0]+evalDeru[1]*evalDeru[1]+evalDeru[2]*evalDeru[2];
                Hess[1]=evalDeruv[0]*diffPnt[0]+evalDeruv[1]*diffPnt[1]+evalDeruv[2]*diffPnt[2] + evalDeru[0]*evalDerv[0]+evalDeru[1]*evalDerv[1]+evalDeru[2]*evalDerv[2];
                Hess[2]=evalDervv[0]*diffPnt[0]+evalDervv[1]*diffPnt[1]+evalDervv[2]*diffPnt[2] + evalDerv[0]*evalDerv[0]+evalDerv[1]*evalDerv[1]+evalDerv[2]*evalDerv[2];
                
                /* CGM - two iterations */
                
                evalDerv[0]=grad[0];
                evalDerv[1]=grad[1];
                
                evalDeru[0]=evalDerv[0];
                evalDeru[1]=evalDerv[1];
                
                wgh=evalDerv[0]*evalDerv[0]+evalDerv[1]*evalDerv[1];
                
                if (wgh>1e-50){
                    
                    evalDeruu[0]=Hess[0]*evalDeru[0]+Hess[1]*evalDeru[1];
                    evalDeruu[1]=Hess[1]*evalDeru[0]+Hess[2]*evalDeru[1];
                    
                    tmpDist=evalDeru[0]*evalDeruu[0]+evalDeru[1]*evalDeruu[1];
                    
                    if (wgh<1e20*fabs(tmpDist)){
                        
                        tmpDist=wgh/tmpDist;
                        
                        if (tmpDist<0){
                            
                            newTdir[0]=-grad[0];
                            newTdir[1]=-grad[1];
                            
                        }
                        else {
                            
                            newTdir[0]=-tmpDist*evalDeru[0];
                            newTdir[1]=-tmpDist*evalDeru[1];
                            
                            evalDerv[0]-=tmpDist*evalDeruu[0];
                            evalDerv[1]-=tmpDist*evalDeruu[1];
                            
                            bspPnts[0]=evalDerv[0]*evalDerv[0]+evalDerv[1]*evalDerv[1];
                            
                            if (bspPnts[0]>1e-25){
                                
                                evalDeru[0]=evalDerv[0]+(bspPnts[0]*evalDeru[0])/wgh;
                                evalDeru[1]=evalDerv[1]+(bspPnts[0]*evalDeru[1])/wgh;
                                
                                wgh=bspPnts[0];
                                
                                evalDeruu[0]=Hess[0]*evalDeru[0]+Hess[1]*evalDeru[1];
                                evalDeruu[1]=Hess[1]*evalDeru[0]+Hess[2]*evalDeru[1];
                                
                                tmpDist=evalDeru[0]*evalDeruu[0]+evalDeru[1]*evalDeruu[1];
                                
                                if (wgh<1e10*fabs(tmpDist)){
                                    
                                    tmpDist=wgh/tmpDist;
                                    
                                    if (tmpDist<0){
                                        
                                        newTdir[0]+=0.5*tmpDist*evalDeru[0];
                                        newTdir[1]+=0.5*tmpDist*evalDeru[1];
                                        
                                    }
                                    else {
                                        
                                        newTdir[0]-=tmpDist*evalDeru[0];
                                        newTdir[1]-=tmpDist*evalDeru[1];
                                        
                                    }
                                    
                                }
                                
                            }
                            
                        }
                        
                    }
                    else {
                        
                        newTdir[0]=-grad[0];
                        newTdir[1]=-grad[1];
                        
                    }
                    
                    /* Scale search direction if neccecary */
                    
                    if (newTdir[0]<-newtUlim){
                        newTdir[1]=-newtUlim*newTdir[1]/newTdir[0];
                        newTdir[0]=-newtUlim;
                    }
                    else if (newTdir[0]>newtUlim){
                        newTdir[1]=newtUlim*newTdir[1]/newTdir[0];
                        newTdir[0]=newtUlim;
                    }
                    if (newTdir[1]<-newtVlim){
                        newTdir[0]=-newtVlim*newTdir[0]/newTdir[1];
                        newTdir[1]=-newtVlim;
                    }
                    else if (newTdir[1]>newtVlim){
                        newTdir[0]=newtVlim*newTdir[0]/newTdir[1];
                        newTdir[1]=newtVlim;
                    }
                    
                    /* Apply line search */
                    
                    evalDeru[0]=0.5*(newTdir[0]*grad[0]+newTdir[1]*grad[1]);
                    
                    wgh=1.0;
                    bool=1;
                    for (j = 0; j < 15; j++){
                        
                        evalDeruv[0]=uv[0]+wgh*newTdir[0];
                        evalDeruv[1]=uv[1]+wgh*newTdir[1];
                        
                        oneBspEval2(degU, degV, mxGetPr(mxGetField(nrbStruct, 0, "coefs")), ncp, kcp, mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 1)), evalDeruv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                        
                        tmpDist=pwr2(bspPnts[0]/bspPnts[3]-controlPnt[0])+pwr2(bspPnts[1]/bspPnts[3]-controlPnt[1])+pwr2(bspPnts[2]/bspPnts[3]-controlPnt[2]);
                        
                        if (tmpDist<(minDist+wgh*evalDeru[0])){
                            uv[0]=evalDeruv[0];
                            uv[1]=evalDeruv[1];
                            
                            if (wgh*(fabs(newTdir[0])+fabs(newTdir[1]))>stcri){
                                bool=0;
                            }
                            break;
                        }
                        else {
                            wgh=wgh*0.75;
                        }
                        
                    }
                    
                }
                else {
                    bool=1;
                }
                
                /* Parameter values must be inside the domain */
                
                if (uv[0]<uStart){
                    uv[0]=uStart;
                }
                else if (uv[0]>uEnd){
                    uv[0]=uEnd;
                }
                if (uv[1]<vStart){
                    uv[1]=vStart;
                }
                else if (uv[1]>vEnd){
                    uv[1]=vEnd;
                }
                
            }
            
            oneBspEval2(degU, degV, mxGetPr(mxGetField(nrbStruct, 0, "coefs")), ncp, kcp, mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 1)), uv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
            
            nrbPnt[0]=bspPnts[0]/bspPnts[3];
            nrbPnt[1]=bspPnts[1]/bspPnts[3];
            nrbPnt[2]=bspPnts[2]/bspPnts[3];
            
            offsetPnt2OrgNURBSnrml(iters, nrbPnt, orgPnts, usOrg, norgp, degUorg, degVorg, ncpOrg, kcpOrg, nrbOrgStruct, nrbOrgDerStruct, nrbOrgDer2Struct, explWghs, &UVcp[2*k], &cpDir[3*k], leftU, rightU, NU, leftV, rightV, NV, newTdir, Hess, grad, uv, bspPnts, diffPnt, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv);
            
            k++;
            
        }
        
        /* Initial parameters */
        
        uv[0]=us[2*k];
        uv[1]=us[2*k+1];
        
        nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
        
        if ((evalDerv[0]*evalDerv[0]+evalDerv[1]*evalDerv[1]+evalDerv[2]*evalDerv[2])<1e-16*(evalDeru[0]*evalDeru[0]+evalDeru[1]*evalDeru[1]+evalDeru[2]*evalDeru[2])){
            
            /* Surface normal not defined, using extrapolation */
            
            uv[0]-=10.0*difru;
            explsign=0.0;
            
            for (jj = 9; jj >= 0; jj--){
                
                /* Compute unweighted control point */
                
                spanU = FindSpan(ncp, degU, uv[0], knotU);
                BasisFuns(spanU, uv[0], degU, knotU, NU, leftU, rightU);
                
                ind = spanU - degU;
                myint=ii*fourncp+ind*4;
                
                bspPnts[0]=0.0;
                bspPnts[1]=0.0;
                bspPnts[2]=0.0;
                bspPnts[3]=0.0;
                for (j = 0; j <= degU; j++){
                    bspPnts[0] += NU[j] * cp[j*4+myint];
                    bspPnts[1] += NU[j] * cp[j*4+myint+1];
                    bspPnts[2] += NU[j] * cp[j*4+myint+2];
                    bspPnts[3] += NU[j] * cp[j*4+myint+3];
                }
                
                controlPnt[0]=bspPnts[0]/bspPnts[3];
                controlPnt[1]=bspPnts[1]/bspPnts[3];
                controlPnt[2]=bspPnts[2]/bspPnts[3];
                
                /* Iterate to find the closest NURBS surface point */
                
                bool=0;
                
                for (i = 0; i < iters; i++){
                    
                    if (bool){
                        break;
                    }
                    
                    /* Compute gradient and Hessian */
                    
                    nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                    
                    diffPnt[0]=evalPnt[0]-controlPnt[0];
                    diffPnt[1]=evalPnt[1]-controlPnt[1];
                    diffPnt[2]=evalPnt[2]-controlPnt[2];
                    
                    minDist=diffPnt[0]*diffPnt[0]+diffPnt[1]*diffPnt[1]+diffPnt[2]*diffPnt[2];
                    
                    grad[1]=evalDerv[0]*diffPnt[0]+evalDerv[1]*diffPnt[1]+evalDerv[2]*diffPnt[2];
                    
                    Hess[2]=evalDervv[0]*diffPnt[0]+evalDervv[1]*diffPnt[1]+evalDervv[2]*diffPnt[2] + evalDerv[0]*evalDerv[0]+evalDerv[1]*evalDerv[1]+evalDerv[2]*evalDerv[2];
                    
                    if (1e12*Hess[2]<=fabs(grad[1])){
                        newTdir[1]=-grad[1];
                    }
                    else {
                        newTdir[1]=-grad[1]/Hess[2];
                    }
                    
                    /* Scale search direction if neccecary */
                    
                    if (newTdir[1]<-newtVlim){
                        newTdir[1]=-newtVlim;
                    }
                    else if (newTdir[1]>newtVlim){
                        newTdir[1]=newtVlim;
                    }
                    
                    /* Apply line search */
                    
                    evalDeru[0]=0.5*(newTdir[1]*grad[1]);
                    
                    wgh=1.0;
                    bool=1;
                    evalDeruv[0]=uv[0];
                    
                    for (j = 0; j < 15; j++){
                        
                        evalDeruv[1]=uv[1]+wgh*newTdir[1];
                        
                        oneBspEval2(degU, degV, mxGetPr(mxGetField(nrbStruct, 0, "coefs")), ncp, kcp, mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 1)), evalDeruv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                        
                        tmpDist=pwr2(bspPnts[0]/bspPnts[3]-controlPnt[0])+pwr2(bspPnts[1]/bspPnts[3]-controlPnt[1])+pwr2(bspPnts[2]/bspPnts[3]-controlPnt[2]);
                        
                        if (tmpDist<(minDist+wgh*evalDeru[0])){
                            uv[1]=evalDeruv[1];
                            
                            if (wgh*(fabs(newTdir[1]))>stcri){
                                bool=0;
                            }
                            break;
                        }
                        else {
                            wgh=wgh*0.75;
                        }
                        
                    }
                    
                    /* Parameter values must be inside the domain */
                    
                    if (uv[1]<vStart){
                        uv[1]=vStart;
                    }
                    else if (uv[1]>vEnd){
                        uv[1]=vEnd;
                    }
                    
                }
                
                uv[0]+=difru;
                explsign+=explWghs[jj]*uv[1];
                
            }
            
            uv[0]=us[2*k];
            uv[1]=explsign;
            
        }
        else {
            
            /* Surface normal exists */
            
            /* Compute unweighted control point */
            
            controlPnt[0]=cp[4*k]/cp[4*k+3];
            controlPnt[1]=cp[4*k+1]/cp[4*k+3];
            controlPnt[2]=cp[4*k+2]/cp[4*k+3];
            
            /* Iterate to find the closest NURBS surface point */
            
            bool=0;
            
            for (i = 0; i < iters; i++){
                
                if (bool){
                    break;
                }
                
                /* Compute gradient and Hessian */
                
                nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                
                diffPnt[0]=evalPnt[0]-controlPnt[0];
                diffPnt[1]=evalPnt[1]-controlPnt[1];
                diffPnt[2]=evalPnt[2]-controlPnt[2];
                
                minDist=diffPnt[0]*diffPnt[0]+diffPnt[1]*diffPnt[1]+diffPnt[2]*diffPnt[2];
                
                grad[1]=evalDerv[0]*diffPnt[0]+evalDerv[1]*diffPnt[1]+evalDerv[2]*diffPnt[2];
                
                Hess[2]=evalDervv[0]*diffPnt[0]+evalDervv[1]*diffPnt[1]+evalDervv[2]*diffPnt[2] + evalDerv[0]*evalDerv[0]+evalDerv[1]*evalDerv[1]+evalDerv[2]*evalDerv[2];
                
                if (1e12*Hess[2]<=fabs(grad[1])){
                    newTdir[1]=-grad[1];
                }
                else {
                    newTdir[1]=-grad[1]/Hess[2];
                }
                
                /* Scale search direction if neccecary */
                
                if (newTdir[1]<-newtVlim){
                    newTdir[1]=-newtVlim;
                }
                else if (newTdir[1]>newtVlim){
                    newTdir[1]=newtVlim;
                }
                
                /* Apply line search */
                
                evalDeru[0]=0.5*(newTdir[1]*grad[1]);
                
                wgh=1.0;
                bool=1;
                evalDeruv[0]=uv[0];
                
                for (j = 0; j < 15; j++){
                    
                    evalDeruv[1]=uv[1]+wgh*newTdir[1];
                    
                    oneBspEval2(degU, degV, mxGetPr(mxGetField(nrbStruct, 0, "coefs")), ncp, kcp, mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 1)), evalDeruv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                    
                    tmpDist=pwr2(bspPnts[0]/bspPnts[3]-controlPnt[0])+pwr2(bspPnts[1]/bspPnts[3]-controlPnt[1])+pwr2(bspPnts[2]/bspPnts[3]-controlPnt[2]);
                    
                    if (tmpDist<(minDist+wgh*evalDeru[0])){
                        uv[1]=evalDeruv[1];
                        
                        if (wgh*(fabs(newTdir[1]))>stcri){
                            bool=0;
                        }
                        break;
                    }
                    else {
                        wgh=wgh*0.75;
                    }
                    
                }
                
                /* Parameter values must be inside the domain */
                
                if (uv[1]<vStart){
                    uv[1]=vStart;
                }
                else if (uv[1]>vEnd){
                    uv[1]=vEnd;
                }
                
            }
            
        }
        
        oneBspEval2(degU, degV, mxGetPr(mxGetField(nrbStruct, 0, "coefs")), ncp, kcp, mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 1)), uv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
        
        nrbPnt[0]=bspPnts[0]/bspPnts[3];
        nrbPnt[1]=bspPnts[1]/bspPnts[3];
        nrbPnt[2]=bspPnts[2]/bspPnts[3];
        
        offsetPnt2OrgNURBSnrml(iters, nrbPnt, orgPnts, usOrg, norgp, degUorg, degVorg, ncpOrg, kcpOrg, nrbOrgStruct, nrbOrgDerStruct, nrbOrgDer2Struct, explWghs, &UVcp[2*k], &cpDir[3*k], leftU, rightU, NU, leftV, rightV, NV, newTdir, Hess, grad, uv, bspPnts, diffPnt, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv);
        
        k++;
        
    }
    
    /* ii = kcp-1, jj=0 */
    
    nrbPnt[0]=cp[4*k]/cp[4*k+3];
    nrbPnt[1]=cp[4*k+1]/cp[4*k+3];
    nrbPnt[2]=cp[4*k+2]/cp[4*k+3];
    
    offsetPnt2OrgNURBSnrml(iters, nrbPnt, orgPnts, usOrg, norgp, degUorg, degVorg, ncpOrg, kcpOrg, nrbOrgStruct, nrbOrgDerStruct, nrbOrgDer2Struct, explWghs, &UVcp[2*k], &cpDir[3*k], leftU, rightU, NU, leftV, rightV, NV, newTdir, Hess, grad, uv, bspPnts, diffPnt, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv);
    
    k++;
    
    /* ii = kcp-1, jj=1,2,...,ncp-2 */
    
    for (jj = 1; jj <= (ncp-2); jj++){
        
        /* Initial parameters */
        
        uv[0]=us[2*k];
        uv[1]=us[2*k+1];
        
        nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
        
        if ((evalDeru[0]*evalDeru[0]+evalDeru[1]*evalDeru[1]+evalDeru[2]*evalDeru[2])<1e-16*(evalDerv[0]*evalDerv[0]+evalDerv[1]*evalDerv[1]+evalDerv[2]*evalDerv[2])){
            
            /* Surface normal not defined, using extrapolation */
            
            uv[1]-=10.0*difrv;
            explsign=0.0;
            
            for (ii = 9; ii >= 0; ii--){
                
                /* Compute unweighted control point */
                
                spanV = FindSpan(kcp, degV, uv[1], knotV);
                BasisFuns(spanV, uv[1], degV, knotV, NV, leftV, rightV);
                
                ind2 = spanV - degV;
                myint=ind2*fourncp+jj*4;
                
                bspPnts[0]=0.0;
                bspPnts[1]=0.0;
                bspPnts[2]=0.0;
                bspPnts[3]=0.0;
                for (i = 0; i <= degV; i++){
                    bspPnts[0] += NV[i] * cp[i*fourncp+myint];
                    bspPnts[1] += NV[i] * cp[i*fourncp+myint+1];
                    bspPnts[2] += NV[i] * cp[i*fourncp+myint+2];
                    bspPnts[3] += NV[i] * cp[i*fourncp+myint+3];
                }
                
                controlPnt[0]=bspPnts[0]/bspPnts[3];
                controlPnt[1]=bspPnts[1]/bspPnts[3];
                controlPnt[2]=bspPnts[2]/bspPnts[3];
                
                /* Iterate to find the closest NURBS surface point */
                
                bool=0;
                
                for (i = 0; i < iters; i++){
                    
                    if (bool){
                        break;
                    }
                    
                    /* Compute gradient and Hessian */
                    
                    nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                    
                    diffPnt[0]=evalPnt[0]-controlPnt[0];
                    diffPnt[1]=evalPnt[1]-controlPnt[1];
                    diffPnt[2]=evalPnt[2]-controlPnt[2];
                    
                    minDist=diffPnt[0]*diffPnt[0]+diffPnt[1]*diffPnt[1]+diffPnt[2]*diffPnt[2];
                    
                    grad[0]=evalDeru[0]*diffPnt[0]+evalDeru[1]*diffPnt[1]+evalDeru[2]*diffPnt[2];
                    
                    Hess[0]=evalDeruu[0]*diffPnt[0]+evalDeruu[1]*diffPnt[1]+evalDeruu[2]*diffPnt[2] + evalDeru[0]*evalDeru[0]+evalDeru[1]*evalDeru[1]+evalDeru[2]*evalDeru[2];
                    
                    if (1e12*Hess[0]<=fabs(grad[0])){
                        newTdir[0]=-grad[0];
                    }
                    else {
                        newTdir[0]=-grad[0]/Hess[0];
                    }
                    
                    /* Scale search direction if neccecary */
                    
                    if (newTdir[0]<-newtUlim){
                        newTdir[0]=-newtUlim;
                    }
                    else if (newTdir[0]>newtUlim){
                        newTdir[0]=newtUlim;
                    }
                    
                    /* Apply line search */
                    
                    evalDeru[0]=0.5*(newTdir[0]*grad[0]);
                    
                    wgh=1.0;
                    bool=1;
                    evalDeruv[1]=uv[1];
                    
                    for (j = 0; j < 15; j++){
                        
                        evalDeruv[0]=uv[0]+wgh*newTdir[0];
                        
                        oneBspEval2(degU, degV, mxGetPr(mxGetField(nrbStruct, 0, "coefs")), ncp, kcp, mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 1)), evalDeruv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                        
                        tmpDist=pwr2(bspPnts[0]/bspPnts[3]-controlPnt[0])+pwr2(bspPnts[1]/bspPnts[3]-controlPnt[1])+pwr2(bspPnts[2]/bspPnts[3]-controlPnt[2]);
                        
                        if (tmpDist<(minDist+wgh*evalDeru[0])){
                            uv[0]=evalDeruv[0];
                            
                            if (wgh*(fabs(newTdir[0]))>stcri){
                                bool=0;
                            }
                            break;
                        }
                        else {
                            wgh=wgh*0.75;
                        }
                        
                    }
                    
                    /* Parameter values must be inside the domain */
                    
                    if (uv[0]<uStart){
                        uv[0]=uStart;
                    }
                    else if (uv[0]>uEnd){
                        uv[0]=uEnd;
                    }
                    
                }
                
                uv[1]+=difrv;
                explsign+=explWghs[ii]*uv[0];
                
            }
            
            uv[0]=explsign;
            uv[1]=us[2*k+1];
            
        }
        else {
            
            /* Surface normal exists */
            
            /* Compute unweighted control point */
            
            controlPnt[0]=cp[4*k]/cp[4*k+3];
            controlPnt[1]=cp[4*k+1]/cp[4*k+3];
            controlPnt[2]=cp[4*k+2]/cp[4*k+3];
            
            /* Iterate to find the closest NURBS surface point to the control point */
            
            bool=0;
            
            for (i = 0; i < iters; i++){
                
                if (bool){
                    break;
                }
                
                /* Compute gradient and Hessian */
                
                nrbD1D2eval2(degU+1, degV+1, ncp, kcp, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                
                diffPnt[0]=evalPnt[0]-controlPnt[0];
                diffPnt[1]=evalPnt[1]-controlPnt[1];
                diffPnt[2]=evalPnt[2]-controlPnt[2];
                
                minDist=diffPnt[0]*diffPnt[0]+diffPnt[1]*diffPnt[1]+diffPnt[2]*diffPnt[2];
                
                grad[0]=evalDeru[0]*diffPnt[0]+evalDeru[1]*diffPnt[1]+evalDeru[2]*diffPnt[2];
                
                Hess[0]=evalDeruu[0]*diffPnt[0]+evalDeruu[1]*diffPnt[1]+evalDeruu[2]*diffPnt[2] + evalDeru[0]*evalDeru[0]+evalDeru[1]*evalDeru[1]+evalDeru[2]*evalDeru[2];
                
                if (1e12*Hess[0]<=fabs(grad[0])){
                    newTdir[0]=-grad[0];
                }
                else {
                    newTdir[0]=-grad[0]/Hess[0];
                }
                
                /* Scale search direction if neccecary */
                
                if (newTdir[0]<-newtUlim){
                    newTdir[0]=-newtUlim;
                }
                else if (newTdir[0]>newtUlim){
                    newTdir[0]=newtUlim;
                }
                
                /* Apply line search */
                
                evalDeru[0]=0.5*(newTdir[0]*grad[0]);
                
                wgh=1.0;
                bool=1;
                evalDeruv[1]=uv[1];
                
                for (j = 0; j < 15; j++){
                    
                    evalDeruv[0]=uv[0]+wgh*newTdir[0];
                    
                    oneBspEval2(degU, degV, mxGetPr(mxGetField(nrbStruct, 0, "coefs")), ncp, kcp, mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 1)), evalDeruv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                    
                    tmpDist=pwr2(bspPnts[0]/bspPnts[3]-controlPnt[0])+pwr2(bspPnts[1]/bspPnts[3]-controlPnt[1])+pwr2(bspPnts[2]/bspPnts[3]-controlPnt[2]);
                    
                    if (tmpDist<(minDist+wgh*evalDeru[0])){
                        uv[0]=evalDeruv[0];
                        
                        if (wgh*(fabs(newTdir[0]))>stcri){
                            bool=0;
                        }
                        break;
                    }
                    else {
                        wgh=wgh*0.75;
                    }
                    
                }
                
                /* Parameter values must be inside the domain */
                
                if (uv[0]<uStart){
                    uv[0]=uStart;
                }
                else if (uv[0]>uEnd){
                    uv[0]=uEnd;
                }
                
            }
            
        }
        
        oneBspEval2(degU, degV, mxGetPr(mxGetField(nrbStruct, 0, "coefs")), ncp, kcp, mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 1)), uv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
        
        nrbPnt[0]=bspPnts[0]/bspPnts[3];
        nrbPnt[1]=bspPnts[1]/bspPnts[3];
        nrbPnt[2]=bspPnts[2]/bspPnts[3];
        
        offsetPnt2OrgNURBSnrml(iters, nrbPnt, orgPnts, usOrg, norgp, degUorg, degVorg, ncpOrg, kcpOrg, nrbOrgStruct, nrbOrgDerStruct, nrbOrgDer2Struct, explWghs, &UVcp[2*k], &cpDir[3*k], leftU, rightU, NU, leftV, rightV, NV, newTdir, Hess, grad, uv, bspPnts, diffPnt, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv);
        
        k++;
        
    }
    
    /* ii = kcp-1, jj=ncp-1 */
    
    nrbPnt[0]=cp[4*k]/cp[4*k+3];
    nrbPnt[1]=cp[4*k+1]/cp[4*k+3];
    nrbPnt[2]=cp[4*k+2]/cp[4*k+3];
    
    offsetPnt2OrgNURBSnrml(iters, nrbPnt, orgPnts, usOrg, norgp, degUorg, degVorg, ncpOrg, kcpOrg, nrbOrgStruct, nrbOrgDerStruct, nrbOrgDer2Struct, explWghs, &UVcp[2*k], &cpDir[3*k], leftU, rightU, NU, leftV, rightV, NV, newTdir, Hess, grad, uv, bspPnts, diffPnt, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv);
    
    return;
    
}

static void safeCPdir(int numCP, double *cpDir, double *corrSrfNrmls){
    
    int i;
    
    for (i = 3; i <= 3*(numCP-2); i+=3){
        
        if ((cpDir[i]*corrSrfNrmls[i]+cpDir[i+1]*corrSrfNrmls[i+1]+cpDir[i+2]*corrSrfNrmls[i+2])<0.96){
            cpDir[i]=corrSrfNrmls[i];
            cpDir[i+1]=corrSrfNrmls[i+1];
            cpDir[i+2]=corrSrfNrmls[i+2];
        }
        
    }
    
    return;
    
}

static void getNURBSpntNrml(double *usOrg, int norgp, int degUorg, int degVorg, int ncpOrg, int kcpOrg, mxArray *nrbStruct, mxArray *nrbDerStruct, mxArray *nrbDer2Struct, double *corrSrfPnts, double *explWghs, double *corrSrfNrmls, double *leftU, double *rightU, double *NU, double *leftV, double *rightV, double *NV){
    
    /* getNURBSpntNrml(usOrg - parameter values of original points, norgp - number of original points, degUorg - degree original, degVorg - degree original, ncpOrg - number of original control points, kcpOrg - number of original control points, nrbStruct - original NURBS surface, nrbDerStruct - original derivative, nrbDer2Struct - original second derivative, corrSrfPnts - surface points, corrSrfNrmls - original computed surface normals, leftU, rightU, NU, leftV, rightV, NV) */
    
    int jj, i, threejj=0;
    double tmpDist, uv[2], bspPnts[4], evalPnt[3], evalDeru[3], evalDerv[3], evalDeruu[3], evalDeruv[3], evalDervv[3], srfNrml[3];
    double uStartOrg, uEndOrg, vStartOrg, vEndOrg, udiffOrg, vdiffOrg, difru, difrv, explsign;
    
    uStartOrg=mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 0))[0];
    uEndOrg=mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 0))[ncpOrg];
    vStartOrg=mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 1))[0];
    vEndOrg=mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 1))[kcpOrg];
    
    udiffOrg=uEndOrg-uStartOrg;
    vdiffOrg=vEndOrg-vStartOrg;
    
    difru=1e-12*udiffOrg;
    difrv=1e-12*vdiffOrg;
    
    for (jj = 0; jj < norgp; jj++){
        
        uv[0]=usOrg[2*jj];
        uv[1]=usOrg[2*jj+1];
        
        /* Compute surface normal at the closest point */
        
        nrbD1D2eval2(degUorg+1, degVorg+1, ncpOrg, kcpOrg, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
        
        corrSrfPnts[threejj]=evalPnt[0];
        corrSrfPnts[threejj+1]=evalPnt[1];
        corrSrfPnts[threejj+2]=evalPnt[2];
        
        evalDeruu[0]=evalDeru[0]*evalDeru[0]+evalDeru[1]*evalDeru[1]+evalDeru[2]*evalDeru[2];
        evalDervv[0]=evalDerv[0]*evalDerv[0]+evalDerv[1]*evalDerv[1]+evalDerv[2]*evalDerv[2];
        
        if (evalDeruu[0]<1e-20*evalDervv[0]){
            
            /* u-derivative to small to be accurate, estimate a new one */
            
            if (uv[1]>(vEndOrg-10.1*difrv)){
                explsign=-1.0;
            }
            else {
                explsign=1.0;
            }
            
            srfNrml[0]=0.0;
            srfNrml[1]=0.0;
            srfNrml[2]=0.0;
            
            for (i = 0; i < 10; i++){
                
                uv[1]+=explsign*difrv;
                
                nrbD1D2eval2(degUorg+1, degVorg+1, ncpOrg, kcpOrg, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                
                evalDeruu[0]=evalDeru[1]*evalDerv[2]-evalDeru[2]*evalDerv[1];
                evalDeruu[1]=evalDeru[2]*evalDerv[0]-evalDeru[0]*evalDerv[2];
                evalDeruu[2]=evalDeru[0]*evalDerv[1]-evalDeru[1]*evalDerv[0];
                
                tmpDist=sqrt(evalDeruu[0]*evalDeruu[0]+evalDeruu[1]*evalDeruu[1]+evalDeruu[2]*evalDeruu[2]);
                
                srfNrml[0]+=explWghs[i]*evalDeruu[0]/tmpDist;
                srfNrml[1]+=explWghs[i]*evalDeruu[1]/tmpDist;
                srfNrml[2]+=explWghs[i]*evalDeruu[2]/tmpDist;
                
            }
            
            tmpDist=sqrt(srfNrml[0]*srfNrml[0]+srfNrml[1]*srfNrml[1]+srfNrml[2]*srfNrml[2]);
            
            srfNrml[0]=srfNrml[0]/tmpDist;
            srfNrml[1]=srfNrml[1]/tmpDist;
            srfNrml[2]=srfNrml[2]/tmpDist;
            
        }
        else if (evalDervv[0]<1e-20*evalDeruu[0]){
            
            /* v-derivative to small to be accurate, estimate a new one */
            
            if (uv[0]>(uEndOrg-10.1*difru)){
                explsign=-1.0;
            }
            else {
                explsign=1.0;
            }
            
            srfNrml[0]=0.0;
            srfNrml[1]=0.0;
            srfNrml[2]=0.0;
            
            for (i = 0; i < 10; i++){
                
                uv[0]+=explsign*difru;
                
                nrbD1D2eval2(degUorg+1, degVorg+1, ncpOrg, kcpOrg, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                
                evalDeruu[0]=evalDeru[1]*evalDerv[2]-evalDeru[2]*evalDerv[1];
                evalDeruu[1]=evalDeru[2]*evalDerv[0]-evalDeru[0]*evalDerv[2];
                evalDeruu[2]=evalDeru[0]*evalDerv[1]-evalDeru[1]*evalDerv[0];
                
                tmpDist=sqrt(evalDeruu[0]*evalDeruu[0]+evalDeruu[1]*evalDeruu[1]+evalDeruu[2]*evalDeruu[2]);
                
                srfNrml[0]+=explWghs[i]*evalDeruu[0]/tmpDist;
                srfNrml[1]+=explWghs[i]*evalDeruu[1]/tmpDist;
                srfNrml[2]+=explWghs[i]*evalDeruu[2]/tmpDist;
                
            }
            
            tmpDist=sqrt(srfNrml[0]*srfNrml[0]+srfNrml[1]*srfNrml[1]+srfNrml[2]*srfNrml[2]);
            
            srfNrml[0]=srfNrml[0]/tmpDist;
            srfNrml[1]=srfNrml[1]/tmpDist;
            srfNrml[2]=srfNrml[2]/tmpDist;
            
        }
        else {
            
            /* just compute the surface normal */
            
            srfNrml[0]=evalDeru[1]*evalDerv[2]-evalDeru[2]*evalDerv[1];
            srfNrml[1]=evalDeru[2]*evalDerv[0]-evalDeru[0]*evalDerv[2];
            srfNrml[2]=evalDeru[0]*evalDerv[1]-evalDeru[1]*evalDerv[0];
            
            tmpDist=sqrt(srfNrml[0]*srfNrml[0]+srfNrml[1]*srfNrml[1]+srfNrml[2]*srfNrml[2]);
            
            if (tmpDist>1e-50){
                
                srfNrml[0]=srfNrml[0]/tmpDist;
                srfNrml[1]=srfNrml[1]/tmpDist;
                srfNrml[2]=srfNrml[2]/tmpDist;
                
            }
            else {
                
                srfNrml[0]=0.0;
                srfNrml[1]=0.0;
                srfNrml[2]=1.0;
                
            }
            
        }
        
        corrSrfNrmls[threejj]=srfNrml[0];
        corrSrfNrmls[threejj+1]=srfNrml[1];
        corrSrfNrmls[threejj+2]=srfNrml[2];
        
        threejj+=3;
        
    }
    
}

static void offsetPnt2PlnDeltaDistNURBS(int iters, int degU, int degV, double *cp, int ncp, int kcp, double *knotU, double *knotV, double *us, int noffp, double *orgPnts, double *usOrg, int norgp, int degUorg, int degVorg, int ncpOrg, int kcpOrg, mxArray *nrbStruct, mxArray *nrbDerStruct, mxArray *nrbDer2Struct, double sgndist, double *signDistDiff, double *explWghs, double *corrSrfNrmls, double *leftU, double *rightU, double *NU, double *leftV, double *rightV, double *NV){
    
    /* offsetPnt2PlnDeltaDistNURBS(iters - maximum number of iterations when searching for closest point, degU - degree of offset surface, degV - degree of offset surface, cp - offset control points, ncp - number of offset control points, kcp - number of offset control points, knotU - offset knot vector, knotV - offset knot vector, us - offset parameter values, noff - number of offset parameter values, orgPnts - computed original points, usOrg - parameter values of original points, norgp - number of original points, degUorg - degree original, degVorg - degree original, ncpOrg - number of original control points, kcpOrg - number of original control points, nrbStruct - original NURBS surface, nrbDerStruct - original derivative, nrbDer2Struct - original second derivative, sgndist - signed distance, signDistDiff - output signed distance differences, corrSrfNrmls - original computed surface normals, leftU, rightU, NU, leftV, rightV, NV) */
    
    int jj, j, threejj=0, threej;
    double tmpDist, minDist, nrbPnt[3], wgh, uv[2], bspPnts[4], diffPnt[3], evalPnt[3], evalDeru[3], evalDerv[3], evalDeruu[3], evalDeruv[3], evalDervv[3], srfNrml[3];
    double uStartOrg, uEndOrg, vStartOrg, vEndOrg, stcri, udiffOrg, vdiffOrg, difru, difrv, newtUlim, newtVlim, newTdir[2], Hess[3], grad[2], explsign;
    int i, spanU, spanV, ind, ind2, fourncp, myint, orderU, orderV, bool;
    
    fourncp=4*ncp;
    orderU=degU+1;
    orderV=degV+1;
    
    uStartOrg=mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 0))[0];
    uEndOrg=mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 0))[ncpOrg];
    vStartOrg=mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 1))[0];
    vEndOrg=mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 1))[kcpOrg];
    
    udiffOrg=uEndOrg-uStartOrg;
    vdiffOrg=vEndOrg-vStartOrg;
    
    difru=1e-12*udiffOrg;
    difrv=1e-12*vdiffOrg;
    
    newtUlim=0.1*udiffOrg;
    newtVlim=0.1*vdiffOrg;
    
    stcri=1e-6*(udiffOrg+vdiffOrg);
    
    for (jj = 0; jj < noffp; jj++){
        
        /* Compute offset point */
        
        spanU = FindSpan(ncp, degU, us[2*jj], knotU);
        BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
        
        ind = spanU - degU;
        
        spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
        
        ind2 = spanV - degV;
        myint=ind2*fourncp+ind*4;
        
        nrbPnt[0]=0.0;
        nrbPnt[1]=0.0;
        nrbPnt[2]=0.0;
        wgh=0.0;
        for (i = 0; i <= degV; i++){
            for (j = 0; j <= degU; j++){
                nrbPnt[0] += NV[i] * NU[j] * cp[i*fourncp+j*4+myint];
                nrbPnt[1] += NV[i] * NU[j] * cp[i*fourncp+j*4+myint+1];
                nrbPnt[2] += NV[i] * NU[j] * cp[i*fourncp+j*4+myint+2];
                wgh += NV[i] * NU[j] * cp[i*fourncp+j*4+myint+3];
            }
        }
        nrbPnt[0]=nrbPnt[0]/wgh;
        nrbPnt[1]=nrbPnt[1]/wgh;
        nrbPnt[2]=nrbPnt[2]/wgh;
        
        /* Find closest original surface point */
        
        oneBspEval2(degUorg, degVorg, mxGetPr(mxGetField(nrbStruct, 0, "coefs")), ncpOrg, kcpOrg, mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 1)), &us[2*jj], bspPnts, leftU, rightU, NU, leftV, rightV, NV);
        
        minDist=(pwr2(bspPnts[0]/bspPnts[3]-nrbPnt[0])+pwr2(bspPnts[1]/bspPnts[3]-nrbPnt[1])+pwr2(bspPnts[2]/bspPnts[3]-nrbPnt[2]))*0.999999999999;
        ind=-1;
        
        threej=0;
        for (j = 0; j < norgp; j++){
            tmpDist=pwr2(nrbPnt[0]-orgPnts[threej])+pwr2(nrbPnt[1]-orgPnts[threej+1])+pwr2(nrbPnt[2]-orgPnts[threej+2]);
            if (tmpDist<minDist){
                ind=j;
                minDist=tmpDist;
            }
            threej+=3;
        }
        
        if (ind<0){
            
            minDist=minDist/0.999999999999;
            
            bool=0;
            if (us[2*jj]>(uEndOrg-10.0*difru)){
                uv[0]=us[2*jj]-1e-6*udiffOrg;
                bool=1;
            }
            else if (us[2*jj]<(uStartOrg+10.0*difru)){
                uv[0]=us[2*jj]+1e-6*udiffOrg;
                bool=1;
            }
            else {
                uv[0]=us[2*jj];
                uv[1]=us[2*jj+1];
            }
            
            if (bool){
                
                uv[1]=vStartOrg+0.025*vdiffOrg;
                
                for (j = 0; j < 20; j++){
                    
                    oneBspEval2(degUorg, degVorg, mxGetPr(mxGetField(nrbStruct, 0, "coefs")), ncpOrg, kcpOrg, mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 1)), uv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                    tmpDist=pwr2(bspPnts[0]/bspPnts[3]-nrbPnt[0])+pwr2(bspPnts[1]/bspPnts[3]-nrbPnt[1])+pwr2(bspPnts[2]/bspPnts[3]-nrbPnt[2]);
                    
                    if (tmpDist<minDist){
                        ind=j;
                        minDist=tmpDist;
                    }
                    
                    uv[1]+=0.05*vdiffOrg;
                    
                }
                
                if (ind<0){
                    uv[0]=us[2*jj];
                    uv[1]=us[2*jj+1];
                }
                else {
                    uv[1]=vStartOrg+(0.025+((double)ind)*0.05)*vdiffOrg;
                }
                
            }
            
            bool=0;
            if (uv[1]>(vEndOrg-10.0*difrv)){
                evalDeruv[0]=uv[0];
                evalDeruv[1]=uv[1];
                uv[1]-=1e-6*vdiffOrg;
                bool=1;
            }
            else if (uv[1]<(vStartOrg+10.0*difrv)){
                evalDeruv[0]=uv[0];
                evalDeruv[1]=uv[1];
                uv[1]+=1e-6*vdiffOrg;
                bool=1;
            }
            
            if (bool){
                
                ind=-1;
                
                uv[0]=uStartOrg+0.025*udiffOrg;
                
                for (j = 0; j < 20; j++){
                    
                    oneBspEval2(degUorg, degVorg, mxGetPr(mxGetField(nrbStruct, 0, "coefs")), ncpOrg, kcpOrg, mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 1)), uv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                    tmpDist=pwr2(bspPnts[0]/bspPnts[3]-nrbPnt[0])+pwr2(bspPnts[1]/bspPnts[3]-nrbPnt[1])+pwr2(bspPnts[2]/bspPnts[3]-nrbPnt[2]);
                    
                    if (tmpDist<minDist){
                        ind=j;
                        minDist=tmpDist;
                    }
                    
                    uv[0]+=0.05*udiffOrg;
                    
                }
                
                if (ind<0){
                    uv[0]=evalDeruv[0];
                    uv[1]=evalDeruv[1];
                }
                else {
                    uv[0]=uStartOrg+(0.025+((double)ind)*0.05)*udiffOrg;
                }
                
            }
            
        }
        else {
            
            uv[0]=usOrg[2*ind];
            uv[1]=usOrg[2*ind+1];
            
        }
        
        /* Iterate to find a closer original surface point */
        
        bool=0;
        
        for (i = 0; i < iters; i++){
            
            if (bool){
                break;
            }
            
            /* Compute gradient and Hessian */
            
            nrbD1D2eval2(degUorg+1, degVorg+1, ncpOrg, kcpOrg, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
            
            diffPnt[0]=evalPnt[0]-nrbPnt[0];
            diffPnt[1]=evalPnt[1]-nrbPnt[1];
            diffPnt[2]=evalPnt[2]-nrbPnt[2];
            
            minDist=diffPnt[0]*diffPnt[0]+diffPnt[1]*diffPnt[1]+diffPnt[2]*diffPnt[2];
            
            grad[0]=evalDeru[0]*diffPnt[0]+evalDeru[1]*diffPnt[1]+evalDeru[2]*diffPnt[2];
            grad[1]=evalDerv[0]*diffPnt[0]+evalDerv[1]*diffPnt[1]+evalDerv[2]*diffPnt[2];
            
            Hess[0]=evalDeruu[0]*diffPnt[0]+evalDeruu[1]*diffPnt[1]+evalDeruu[2]*diffPnt[2] + evalDeru[0]*evalDeru[0]+evalDeru[1]*evalDeru[1]+evalDeru[2]*evalDeru[2];
            Hess[1]=evalDeruv[0]*diffPnt[0]+evalDeruv[1]*diffPnt[1]+evalDeruv[2]*diffPnt[2] + evalDeru[0]*evalDerv[0]+evalDeru[1]*evalDerv[1]+evalDeru[2]*evalDerv[2];
            Hess[2]=evalDervv[0]*diffPnt[0]+evalDervv[1]*diffPnt[1]+evalDervv[2]*diffPnt[2] + evalDerv[0]*evalDerv[0]+evalDerv[1]*evalDerv[1]+evalDerv[2]*evalDerv[2];
            
            /* CGM - two iterations */
            
            evalDerv[0]=grad[0];
            evalDerv[1]=grad[1];
            
            evalDeru[0]=evalDerv[0];
            evalDeru[1]=evalDerv[1];
            
            wgh=evalDerv[0]*evalDerv[0]+evalDerv[1]*evalDerv[1];
            
            if (wgh>1e-50){
                
                evalDeruu[0]=Hess[0]*evalDeru[0]+Hess[1]*evalDeru[1];
                evalDeruu[1]=Hess[1]*evalDeru[0]+Hess[2]*evalDeru[1];
                
                tmpDist=evalDeru[0]*evalDeruu[0]+evalDeru[1]*evalDeruu[1];
                
                if (wgh<1e20*fabs(tmpDist)){
                    
                    tmpDist=wgh/tmpDist;
                    
                    if (tmpDist<0){
                        
                        newTdir[0]=-grad[0];
                        newTdir[1]=-grad[1];
                        
                    }
                    else {
                        
                        newTdir[0]=-tmpDist*evalDeru[0];
                        newTdir[1]=-tmpDist*evalDeru[1];
                        
                        evalDerv[0]-=tmpDist*evalDeruu[0];
                        evalDerv[1]-=tmpDist*evalDeruu[1];
                        
                        bspPnts[0]=evalDerv[0]*evalDerv[0]+evalDerv[1]*evalDerv[1];
                        
                        if (bspPnts[0]>1e-25){
                            
                            evalDeru[0]=evalDerv[0]+(bspPnts[0]*evalDeru[0])/wgh;
                            evalDeru[1]=evalDerv[1]+(bspPnts[0]*evalDeru[1])/wgh;
                            
                            wgh=bspPnts[0];
                            
                            evalDeruu[0]=Hess[0]*evalDeru[0]+Hess[1]*evalDeru[1];
                            evalDeruu[1]=Hess[1]*evalDeru[0]+Hess[2]*evalDeru[1];
                            
                            tmpDist=evalDeru[0]*evalDeruu[0]+evalDeru[1]*evalDeruu[1];
                            
                            if (wgh<1e10*fabs(tmpDist)){
                                
                                tmpDist=wgh/tmpDist;
                                
                                if (tmpDist<0){
                                    
                                    newTdir[0]+=0.5*tmpDist*evalDeru[0];
                                    newTdir[1]+=0.5*tmpDist*evalDeru[1];
                                    
                                }
                                else {
                                    
                                    newTdir[0]-=tmpDist*evalDeru[0];
                                    newTdir[1]-=tmpDist*evalDeru[1];
                                    
                                }
                                
                            }
                            
                        }
                        
                    }
                    
                }
                else {
                    
                    newTdir[0]=-grad[0];
                    newTdir[1]=-grad[1];
                    
                }
                
                /* Scale search direction if neccecary */
                
                if (newTdir[0]<-newtUlim){
                    newTdir[1]=-newtUlim*newTdir[1]/newTdir[0];
                    newTdir[0]=-newtUlim;
                }
                else if (newTdir[0]>newtUlim){
                    newTdir[1]=newtUlim*newTdir[1]/newTdir[0];
                    newTdir[0]=newtUlim;
                }
                if (newTdir[1]<-newtVlim){
                    newTdir[0]=-newtVlim*newTdir[0]/newTdir[1];
                    newTdir[1]=-newtVlim;
                }
                else if (newTdir[1]>newtVlim){
                    newTdir[0]=newtVlim*newTdir[0]/newTdir[1];
                    newTdir[1]=newtVlim;
                }
                
                /* Apply line search */
                
                evalDeru[0]=0.5*(newTdir[0]*grad[0]+newTdir[1]*grad[1]);
                
                wgh=1.0;
                bool=1;
                for (j = 0; j < 15; j++){
                    
                    evalDeruv[0]=uv[0]+wgh*newTdir[0];
                    evalDeruv[1]=uv[1]+wgh*newTdir[1];
                    
                    oneBspEval2(degUorg, degVorg, mxGetPr(mxGetField(nrbStruct, 0, "coefs")), ncpOrg, kcpOrg, mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 1)), evalDeruv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                    
                    tmpDist=pwr2(bspPnts[0]/bspPnts[3]-nrbPnt[0])+pwr2(bspPnts[1]/bspPnts[3]-nrbPnt[1])+pwr2(bspPnts[2]/bspPnts[3]-nrbPnt[2]);
                    
                    if (tmpDist<(minDist+wgh*evalDeru[0])){
                        uv[0]=evalDeruv[0];
                        uv[1]=evalDeruv[1];
                        
                        if (wgh*(fabs(newTdir[0])+fabs(newTdir[1]))>stcri){
                            bool=0;
                        }
                        break;
                    }
                    else {
                        wgh=wgh*0.75;
                    }
                    
                }
                
            }
            else {
                bool=1;
            }
            
            /* Parameter values must be inside the domain */
            
            if (uv[0]<uStartOrg){
                uv[0]=uStartOrg;
            }
            else if (uv[0]>uEndOrg){
                uv[0]=uEndOrg;
            }
            if (uv[1]<vStartOrg){
                uv[1]=vStartOrg;
            }
            else if (uv[1]>vEndOrg){
                uv[1]=vEndOrg;
            }
            
        }
        
        /* Compute surface normal at the closest point */
        
        nrbD1D2eval2(degUorg+1, degVorg+1, ncpOrg, kcpOrg, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, evalPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
        
        evalDeruu[0]=evalDeru[0]*evalDeru[0]+evalDeru[1]*evalDeru[1]+evalDeru[2]*evalDeru[2];
        evalDervv[0]=evalDerv[0]*evalDerv[0]+evalDerv[1]*evalDerv[1]+evalDerv[2]*evalDerv[2];
        
        if (evalDeruu[0]<1e-20*evalDervv[0]){
            
            /* u-derivative to small to be accurate, estimate a new one */
            
            if (uv[1]>(vEndOrg-10.1*difrv)){
                explsign=-1.0;
            }
            else {
                explsign=1.0;
            }
            
            srfNrml[0]=0.0;
            srfNrml[1]=0.0;
            srfNrml[2]=0.0;
            
            for (i = 0; i < 10; i++){
                
                uv[1]+=explsign*difrv;
                
                nrbD1D2eval2(degUorg+1, degVorg+1, ncpOrg, kcpOrg, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, diffPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                
                evalDeruu[0]=evalDeru[1]*evalDerv[2]-evalDeru[2]*evalDerv[1];
                evalDeruu[1]=evalDeru[2]*evalDerv[0]-evalDeru[0]*evalDerv[2];
                evalDeruu[2]=evalDeru[0]*evalDerv[1]-evalDeru[1]*evalDerv[0];
                
                tmpDist=sqrt(evalDeruu[0]*evalDeruu[0]+evalDeruu[1]*evalDeruu[1]+evalDeruu[2]*evalDeruu[2]);
                
                srfNrml[0]+=explWghs[i]*evalDeruu[0]/tmpDist;
                srfNrml[1]+=explWghs[i]*evalDeruu[1]/tmpDist;
                srfNrml[2]+=explWghs[i]*evalDeruu[2]/tmpDist;
                
            }
            
            tmpDist=sqrt(srfNrml[0]*srfNrml[0]+srfNrml[1]*srfNrml[1]+srfNrml[2]*srfNrml[2]);
            
            srfNrml[0]=srfNrml[0]/tmpDist;
            srfNrml[1]=srfNrml[1]/tmpDist;
            srfNrml[2]=srfNrml[2]/tmpDist;
            
        }
        else if (evalDervv[0]<1e-20*evalDeruu[0]){
            
            /* v-derivative to small to be accurate, estimate a new one */
            
            if (uv[0]>(uEndOrg-10.1*difru)){
                explsign=-1.0;
            }
            else {
                explsign=1.0;
            }
            
            srfNrml[0]=0.0;
            srfNrml[1]=0.0;
            srfNrml[2]=0.0;
            
            for (i = 0; i < 10; i++){
                
                uv[0]+=explsign*difru;
                
                nrbD1D2eval2(degUorg+1, degVorg+1, ncpOrg, kcpOrg, nrbStruct, nrbDerStruct, nrbDer2Struct, uv, diffPnt, evalDeru, evalDerv, evalDeruu, evalDeruv, evalDervv, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
                
                evalDeruu[0]=evalDeru[1]*evalDerv[2]-evalDeru[2]*evalDerv[1];
                evalDeruu[1]=evalDeru[2]*evalDerv[0]-evalDeru[0]*evalDerv[2];
                evalDeruu[2]=evalDeru[0]*evalDerv[1]-evalDeru[1]*evalDerv[0];
                
                tmpDist=sqrt(evalDeruu[0]*evalDeruu[0]+evalDeruu[1]*evalDeruu[1]+evalDeruu[2]*evalDeruu[2]);
                
                srfNrml[0]+=explWghs[i]*evalDeruu[0]/tmpDist;
                srfNrml[1]+=explWghs[i]*evalDeruu[1]/tmpDist;
                srfNrml[2]+=explWghs[i]*evalDeruu[2]/tmpDist;
                
            }
            
            tmpDist=sqrt(srfNrml[0]*srfNrml[0]+srfNrml[1]*srfNrml[1]+srfNrml[2]*srfNrml[2]);
            
            srfNrml[0]=srfNrml[0]/tmpDist;
            srfNrml[1]=srfNrml[1]/tmpDist;
            srfNrml[2]=srfNrml[2]/tmpDist;
            
        }
        else {
            
            /* just compute the surface normal */
            
            srfNrml[0]=evalDeru[1]*evalDerv[2]-evalDeru[2]*evalDerv[1];
            srfNrml[1]=evalDeru[2]*evalDerv[0]-evalDeru[0]*evalDerv[2];
            srfNrml[2]=evalDeru[0]*evalDerv[1]-evalDeru[1]*evalDerv[0];
            
            tmpDist=sqrt(srfNrml[0]*srfNrml[0]+srfNrml[1]*srfNrml[1]+srfNrml[2]*srfNrml[2]);
            
            if (tmpDist>1e-50){
                
                srfNrml[0]=srfNrml[0]/tmpDist;
                srfNrml[1]=srfNrml[1]/tmpDist;
                srfNrml[2]=srfNrml[2]/tmpDist;
                
            }
            else {
                
                srfNrml[0]=0.0;
                srfNrml[1]=0.0;
                srfNrml[2]=1.0;
                
            }
            
        }
        
        /* finally, compute the signed distance */
        
        signDistDiff[jj]=(nrbPnt[0]-evalPnt[0])*srfNrml[0]+(nrbPnt[1]-evalPnt[1])*srfNrml[1]+(nrbPnt[2]-evalPnt[2])*srfNrml[2]-sgndist;
        signDistDiff[jj+noffp]=-(evalPnt[0]*srfNrml[0]+evalPnt[1]*srfNrml[1]+evalPnt[2]*srfNrml[2])-sgndist;
        
        corrSrfNrmls[threejj]=srfNrml[0];
        corrSrfNrmls[threejj+1]=srfNrml[1];
        corrSrfNrmls[threejj+2]=srfNrml[2];
        
        threejj+=3;
        
    }
    
}

static void getMatInd(int ncp, int kcp, int *matInds){
    
    /* getMatInd(ncp - number of control points in u, kcp - number of control points in v, matInds - array of indices to the GN matrix) */
    
    int ii, jj, matInd=0, arrInd=0, infInd;
    
    infInd=ncp*kcp+1;
    
    /* ii=0  jj=0 */
    
    matInds[arrInd]=infInd;
    arrInd++;
    
    /* ii=0  jj=1,2,...,ncp-2 */
    
    for (jj = 1; jj <= (ncp-2); jj++){
        
        matInds[arrInd]=matInd;
        matInd++;
        arrInd++;
        
    }
    
    /* ii=0  jj=ncp-1 */
    
    matInds[arrInd]=infInd;
    arrInd++;
    
    /* ii=1,2,...,kcp-2 */
    
    for (ii = 1; ii <= (kcp-2); ii++){
        
        /* jj=0,1,2,...,ncp-1 */
        
        for (jj = 0; jj <= (ncp-1); jj++){
            
            matInds[arrInd]=matInd;
            matInd++;
            arrInd++;
            
        }
        
    }
    
    /* ii=kcp-1  jj=0 */
    
    matInds[arrInd]=infInd;
    arrInd++;
    
    /* ii=kcp-1  jj=1,2,...,ncp-2 */
    
    for (jj = 1; jj <= (ncp-2); jj++){
        
        matInds[arrInd]=matInd;
        matInd++;
        arrInd++;
        
    }
    
    /* ii=kcp-1  jj=ncp-1 */
    
    matInds[arrInd]=infInd;
    
}

static void initiateArray2zero(double *A, int n){
    
    /* Set A(:)=0.0 */
    
    int i;
    
    for (i = 0; i < n ; i++){
        A[i]=0.0;
    }
    
}

static void initiateArray2val(double *A, int n, double val){
    
    /* Set A(:)=val */
    
    int i;
    
    for (i = 0; i < n ; i++){
        A[i]=val;
    }
    
}

static void rescaleArray(double *A, int n, double sc){
    
    /* Set A(:)=sc*A(:) */
    
    int i;
    
    for (i = 0; i < n ; i++){
        A[i]=sc*A[i];
    }
    
}

static void setArray2array(double *A, double *B, int n){
    
    /* Set A(:)=B(:) */
    
    int i;
    
    for (i = 0; i < n ; i++){
        A[i]=B[i];
    }
    
}

static void linSysSolver(double *A, double *b, double *x, int n){
    
    /* Solves A*x=b, A nxn matrix. Overwrites A and b */
    
    int i, j, k;
    double alpha, beta, gamma;
    
    for (i = 0; i < n ; i++){
        
        alpha=0.0;
        for (j = i; j < n ; j++){
            alpha+=A[i*n+j]*A[i*n+j];
        }
        alpha=sqrt(alpha);
        
        if (A[(n+1)*i]>=0.0){
            
            beta=1.0+A[(n+1)*i]/alpha;
            
            gamma=A[(n+1)*i]+alpha;
            
            A[(n+1)*i]=-alpha;
            for (j = i+1; j < n ; j++){
                A[i*n+j]=A[i*n+j]/gamma;
            }
            
            alpha=b[i];
            for (j = i+1; j < n ; j++){
                alpha+=A[i*n+j]*b[j];
            }
            alpha=beta*alpha;
            
            b[i]-=alpha;
            for (j = i+1; j < n ; j++){
                b[j]-=alpha*A[i*n+j];
            }
            
            for (k = i+1; k < n ; k++){
                
                alpha=A[k*n+i];
                for (j = i+1; j < n ; j++){
                    alpha+=A[i*n+j]*A[k*n+j];
                }
                alpha=beta*alpha;
                
                A[k*n+i]-=alpha;
                for (j = i+1; j < n ; j++){
                    A[k*n+j]-=alpha*A[i*n+j];
                }
                
            }
            
        }
        else {
            
            beta=1.0-A[(n+1)*i]/alpha;
            
            gamma=A[(n+1)*i]-alpha;
            
            A[(n+1)*i]=alpha;
            for (j = i+1; j < n ; j++){
                A[i*n+j]=A[i*n+j]/gamma;
            }
            
            alpha=b[i];
            for (j = i+1; j < n ; j++){
                alpha+=A[i*n+j]*b[j];
            }
            alpha=beta*alpha;
            
            b[i]-=alpha;
            for (j = i+1; j < n ; j++){
                b[j]-=alpha*A[i*n+j];
            }
            
            for (k = i+1; k < n ; k++){
                
                alpha=A[k*n+i];
                for (j = i+1; j < n ; j++){
                    alpha+=A[i*n+j]*A[k*n+j];
                }
                alpha=beta*alpha;
                
                A[k*n+i]-=alpha;
                for (j = i+1; j < n ; j++){
                    A[k*n+j]-=alpha*A[i*n+j];
                }
                
            }
            
        }
        
    }
    
    for (j = n-1; j >=0 ; j--){
        
        if (1e8*fabs(A[(n+1)*j])>fabs(b[j])){
            x[j]=b[j]/A[(n+1)*j];
            for (k = j-1; k >=0 ; k--){
                b[k]-=A[j*n+k]*x[j];
            }
        }
        else {
            x[j]=0.0;
        }
        
    }
    
    return;
    
}

static void conjugateGradientMethod(double *A, double *b, double *x, int n, int maxIter, double *doubleVals){
    
    /* Solves A*x=b, A s.p.d. */
    
    /* required size of doubleVals is 3*n */
    
    int i, j, itr;
    double rsstart, rsold, rsnew, alpha;
    
    /* p and r */
    rsstart=0.0;
    for (i = 0; i < n ; i++){
        doubleVals[i]=b[i];
        doubleVals[i+2*n]=b[i];
        rsstart+=b[i]*b[i];
    }
    
    rsold=rsstart;
    
    /* Ap and alpha */
    alpha=0.0;
    for (i = 0; i < n ; i++){
        doubleVals[i+n]=0.0;
        for (j = 0; j < n ; j++){
            doubleVals[i+n]+=A[i*n+j]*doubleVals[j];
        }
        alpha+=doubleVals[i+n]*doubleVals[i];
    }
    
    if (1e10*alpha<rsold || rsstart < 1e-30){
        for (i = 0; i < n ; i++){
            x[i]=0.0;
        }
        return;
    }
    
    alpha=rsold/alpha;
    
    for (i = 0; i < n ; i++){
        x[i]=alpha*doubleVals[i];
    }
    
    /* r */
    rsnew=0.0;
    for (i = 0; i < n ; i++){
        doubleVals[i+2*n]-=alpha*doubleVals[i+n];
        rsnew+=doubleVals[i+2*n]*doubleVals[i+2*n];
    }
    
    if (1e12*rsnew<rsstart){
        return;
    }
    
    /* p */
    alpha=rsnew/rsold;
    for (i = 0; i < n ; i++){
        doubleVals[i]=doubleVals[i+2*n]+alpha*doubleVals[i];
    }
    
    rsold=rsnew;
    
    for (itr = 0; itr < maxIter ; itr++){
        
        /* Ap and alpha */
        alpha=0.0;
        for (i = 0; i < n ; i++){
            doubleVals[i+n]=0.0;
            for (j = 0; j < n ; j++){
                doubleVals[i+n]+=A[i*n+j]*doubleVals[j];
            }
            alpha+=doubleVals[i+n]*doubleVals[i];
        }
        
        if (1e4*alpha<rsold){
            break;
        }
        
        alpha=rsold/alpha;
        
        /* r */
        rsnew=0.0;
        for (i = 0; i < n ; i++){
            doubleVals[i+2*n]-=alpha*doubleVals[i+n];
            rsnew+=doubleVals[i+2*n]*doubleVals[i+2*n];
        }
        
        if (rsnew<1.3*rsold){
            for (i = 0; i < n ; i++){
                x[i]+=alpha*doubleVals[i];
            }
        }
        else {
            break;
        }
        
        if (1e4*rsnew<rsstart){
            break;
        }
        
        /* p */
        alpha=rsnew/rsold;
        for (i = 0; i < n ; i++){
            doubleVals[i]=doubleVals[i+2*n]+alpha*doubleVals[i];
        }
        
        rsold=rsnew;
        
    }
    
    return;
    
}

static void computeLinGNmatPnt2Pnt(int degU, int degV, double *cp, int ncp, int kcp, double *knotU, double *knotV, double *us, int nus, double *dirOffset, double *cpDir, double *sgnDistDiff, double *HessApprx, double *gradIent, int *derivInds, double *derivVals, double *leftU, double *rightU, double *NU, double *leftV, double *rightV, double *NV){
    
    /* computeLinGNmatPnt2Pnt( degU - degree of NURBS in u, degV - degree of NURBS in v, cp - pointer to control points, ncp - number of control points in u, kcp - number of control points in v, knotU - pointer to knot sequence in u, knotV - pointer to knot sequence in v, us - pointer to parameter values, nus - number of evaluations, dirOffset - direction of offset, cpDir - direction of CP-update, sgnDistDiff - difference of sign dist, HessApprx - Gauss-Newton Hessian, gradIent - gradient, derivInds - , leftU - pointer to array for function BasisFuns, rightU - pointer to array for function BasisFuns, NU - pointer to array for function BasisFuns, leftV - pointer to array for function BasisFuns, rightV - pointer to array for function BasisFuns, NV - pointer to array for function BasisFuns) */
    
    int i, j, ii, twoii, threeii, spanU, spanV, ind, ind2, dind, fourncp, myint, numCP, orderU, orderV, nnz, cpInd;
    double bspnt[4], doubleVals[3];
    
    fourncp=4*ncp;
    orderU=degU+1;
    orderV=degV+1;
    
    nnz=orderU*orderV;
    
    numCP=ncp*kcp;
    
    /* ii=0,1,2,...,nus-1 */
    
    for (ii = 0; ii < nus; ii++){
        
        twoii=2*ii;
        threeii=3*ii;
        
        spanU = FindSpan(ncp, degU, us[twoii], knotU);
        BasisFuns(spanU, us[twoii], degU, knotU, NU, leftU, rightU);
        
        ind = spanU - degU;
        
        spanV = FindSpan(kcp, degV, us[twoii+1], knotV);
        BasisFuns(spanV, us[twoii+1], degV, knotV, NV, leftV, rightV);
        
        ind2 = spanV - degV;
        myint=ind2*fourncp+ind*4;
        
        bspnt[0]=0.0;
        bspnt[1]=0.0;
        bspnt[2]=0.0;
        bspnt[3]=0.0;
        for (i = 0; i <= degV; i++){
            for (j = 0; j <= degU; j++){
                bspnt[0] += NV[i] * NU[j] * cp[i*fourncp+j*4+myint];
                bspnt[1] += NV[i] * NU[j] * cp[i*fourncp+j*4+myint+1];
                bspnt[2] += NV[i] * NU[j] * cp[i*fourncp+j*4+myint+2];
                bspnt[3] += NV[i] * NU[j] * cp[i*fourncp+j*4+myint+3];
            }
        }
        
        dind=0;
        for (i = 0; i <= degV; i++){
            for (j = 0; j <= degU; j++){
                cpInd=(ind2+i)*ncp+ind+j;
                derivInds[dind]=cpInd;
                cpInd=3*cpInd;
                doubleVals[0]=NV[i]*NU[j]/bspnt[3];
                derivVals[3*dind]=doubleVals[0]*cpDir[cpInd];
                derivVals[3*dind+1]=doubleVals[0]*cpDir[cpInd+1];
                derivVals[3*dind+2]=doubleVals[0]*cpDir[cpInd+2];
                dind++;
            }
        }
        
        doubleVals[0]=sgnDistDiff[ii]*dirOffset[threeii];
        doubleVals[1]=sgnDistDiff[ii]*dirOffset[threeii+1];
        doubleVals[2]=sgnDistDiff[ii]*dirOffset[threeii+2];
        
        for (i = 0; i < nnz; i++){
            gradIent[derivInds[i]]+=doubleVals[0]*derivVals[3*i]+doubleVals[1]*derivVals[3*i+1]+doubleVals[2]*derivVals[3*i+2];
            for (j = 0; j < nnz; j++){
                if (derivInds[j]>=derivInds[i]){
                    HessApprx[derivInds[i]*numCP+derivInds[j]]+=derivVals[3*i]*derivVals[3*j]+derivVals[3*i+1]*derivVals[3*j+1]+derivVals[3*i+2]*derivVals[3*j+2];
                }
            }
        }
        
    }
    
    for (i = 1; i < numCP; i++){
        for (j = 0; j < i; j++){
            HessApprx[i*numCP+j]=HessApprx[j*numCP+i];
        }
    }
    
    return;
    
}

static void computeLinGNmatPnt2Pln(int degU, int degV, double *cp, int ncp, int kcp, double *knotU, double *knotV, double *us, int nus, double *dirOffset, double *cpDir, double *sgnDistDiff, double *HessApprx, double *gradIent, int *derivInds, double *derivVals, double *leftU, double *rightU, double *NU, double *leftV, double *rightV, double *NV){
    
    /* computeLinGNmatPnt2Pln( degU - degree of NURBS in u, degV - degree of NURBS in v, cp - pointer to control points, ncp - number of control points in u, kcp - number of control points in v, knotU - pointer to knot sequence in u, knotV - pointer to knot sequence in v, us - pointer to parameter values, nus - number of evaluations, dirOffset - direction of offset, cpDir - direction of CP-update, sgnDistDiff - difference of sign dist, HessApprx - Gauss-Newton Hessian, gradIent - gradient, derivInds - , leftU - pointer to array for function BasisFuns, rightU - pointer to array for function BasisFuns, NU - pointer to array for function BasisFuns, leftV - pointer to array for function BasisFuns, rightV - pointer to array for function BasisFuns, NV - pointer to array for function BasisFuns) */
    
    int i, j, ii, twoii, threeii, spanU, spanV, ind, ind2, dind, fourncp, myint, numCP, orderU, orderV, nnz, cpInd;
    double bspnt[4];
    
    fourncp=4*ncp;
    orderU=degU+1;
    orderV=degV+1;
    
    nnz=orderU*orderV;
    
    numCP=ncp*kcp;
    
    /* ii=0,1,2,...,nus-1 */
    
    for (ii = 0; ii < nus; ii++){
        
        twoii=2*ii;
        threeii=3*ii;
        
        spanU = FindSpan(ncp, degU, us[twoii], knotU);
        BasisFuns(spanU, us[twoii], degU, knotU, NU, leftU, rightU);
        
        ind = spanU - degU;
        
        spanV = FindSpan(kcp, degV, us[twoii+1], knotV);
        BasisFuns(spanV, us[twoii+1], degV, knotV, NV, leftV, rightV);
        
        ind2 = spanV - degV;
        myint=ind2*fourncp+ind*4;
        
        bspnt[0]=0.0;
        bspnt[1]=0.0;
        bspnt[2]=0.0;
        bspnt[3]=0.0;
        for (i = 0; i <= degV; i++){
            for (j = 0; j <= degU; j++){
                bspnt[0] += NV[i] * NU[j] * cp[i*fourncp+j*4+myint];
                bspnt[1] += NV[i] * NU[j] * cp[i*fourncp+j*4+myint+1];
                bspnt[2] += NV[i] * NU[j] * cp[i*fourncp+j*4+myint+2];
                bspnt[3] += NV[i] * NU[j] * cp[i*fourncp+j*4+myint+3];
            }
        }
        
        dind=0;
        for (i = 0; i <= degV; i++){
            for (j = 0; j <= degU; j++){
                cpInd=(ind2+i)*ncp+ind+j;
                derivInds[dind]=cpInd;
                cpInd=3*cpInd;
                derivVals[dind]=NV[i]*NU[j]*(dirOffset[threeii]*cpDir[cpInd]+dirOffset[threeii+1]*cpDir[cpInd+1]+dirOffset[threeii+2]*cpDir[cpInd+2])/bspnt[3];
                dind++;
            }
        }
        
        for (i = 0; i < nnz; i++){
            gradIent[derivInds[i]]+=sgnDistDiff[ii]*derivVals[i];
            for (j = 0; j < nnz; j++){
                if (derivInds[j]>=derivInds[i]){
                    HessApprx[derivInds[i]*numCP+derivInds[j]]+=derivVals[i]*derivVals[j];
                }
            }
        }
        
    }
    
    for (i = 1; i < numCP; i++){
        for (j = 0; j < i; j++){
            HessApprx[i*numCP+j]=HessApprx[j*numCP+i];
        }
    }
    
}

static void computeGNmatPnt2Pnt(int degU, int degV, double *cpw, double *cp, int ncp, int kcp, double *knotU, double *knotV, double *us, int nus, double *dirOffset, double *cpDir, double *sgnDistDiff, double *HessApprx, double *gradIent, int *matInds, int *derivInds, double *derivVals, double *leftU, double *rightU, double *NU, double *leftV, double *rightV, double *NV){
    
    /* computeGNmatPnt2Pnt( degU - degree of NURBS in u, degV - degree of NURBS in v, cpw - pointer to weighted control points, cp - pointer to control points, ncp - number of control points in u, kcp - number of control points in v, knotU - pointer to knot sequence in u, knotV - pointer to knot sequence in v, us - pointer to parameter values, nus - number of evaluations, dirOffset - direction of offset, cpDir - direction of CP-update, sgnDistDiff - difference of sign dist, HessApprx - Gauss-Newton Hessian, gradIent - gradient , matInds - matrix indices, derivInds - , leftU - pointer to array for function BasisFuns, rightU - pointer to array for function BasisFuns, NU - pointer to array for function BasisFuns, leftV - pointer to array for function BasisFuns, rightV - pointer to array for function BasisFuns, NV - pointer to array for function BasisFuns) */
    
    int i, j, ii, twoii, threeii, spanU, spanV, ind, ind2, dind, fourncp, myint, numCP, numRows, orderU, orderV, nnz, rowInd, colInd, cpInd;
    double bspnt[4], doubleval;
    
    fourncp=4*ncp;
    orderU=degU+1;
    orderV=degV+1;
    
    nnz=orderU*orderV;
    
    numCP=ncp*kcp;
    
    numRows=2*(numCP-4);
    
    /* ii=0,1,2,...,nus-1 */
    
    for (ii = 0; ii < nus; ii++){
        
        twoii=2*ii;
        threeii=3*ii;
        
        spanU = FindSpan(ncp, degU, us[twoii], knotU);
        BasisFuns(spanU, us[twoii], degU, knotU, NU, leftU, rightU);
        
        ind = spanU - degU;
        
        spanV = FindSpan(kcp, degV, us[twoii+1], knotV);
        BasisFuns(spanV, us[twoii+1], degV, knotV, NV, leftV, rightV);
        
        ind2 = spanV - degV;
        myint=ind2*fourncp+ind*4;
        
        bspnt[0]=0.0;
        bspnt[1]=0.0;
        bspnt[2]=0.0;
        bspnt[3]=0.0;
        for (i = 0; i <= degV; i++){
            for (j = 0; j <= degU; j++){
                bspnt[0] += NV[i] * NU[j] * cpw[i*fourncp+j*4+myint];
                bspnt[1] += NV[i] * NU[j] * cpw[i*fourncp+j*4+myint+1];
                bspnt[2] += NV[i] * NU[j] * cpw[i*fourncp+j*4+myint+2];
                bspnt[3] += NV[i] * NU[j] * cpw[i*fourncp+j*4+myint+3];
            }
        }
        
        dind=0;
        for (i = 0; i <= degV; i++){
            for (j = 0; j <= degU; j++){
                cpInd=(ind2+i)*ncp+ind+j;
                derivInds[dind]=cpInd;
                
                doubleval=NV[i]*NU[j]*cpw[4*cpInd+3]/bspnt[3];
                
                derivVals[6*dind]=doubleval*cpDir[3*cpInd];
                derivVals[6*dind+1]=doubleval*cpDir[3*cpInd+1];
                derivVals[6*dind+2]=doubleval*cpDir[3*cpInd+2];
                
                doubleval=NV[i]*NU[j]/(bspnt[3]*bspnt[3]);
                
                derivVals[6*dind+3]=doubleval*(bspnt[3]*cp[3*cpInd]-bspnt[0]);
                derivVals[6*dind+4]=doubleval*(bspnt[3]*cp[3*cpInd+1]-bspnt[1]);
                derivVals[6*dind+5]=doubleval*(bspnt[3]*cp[3*cpInd+2]-bspnt[2]);
                
                dind++;
            }
        }
        
        for (i = 0; i < nnz; i++){
            
            colInd=matInds[derivInds[i]];
            
            if (colInd<numCP){
                
                gradIent[2*colInd]+=sgnDistDiff[ii]*(dirOffset[threeii]*derivVals[6*i]+dirOffset[threeii+1]*derivVals[6*i+1]+dirOffset[threeii+2]*derivVals[6*i+2]);
                gradIent[2*colInd+1]+=sgnDistDiff[ii]*(dirOffset[threeii]*derivVals[6*i+3]+dirOffset[threeii+1]*derivVals[6*i+4]+dirOffset[threeii+2]*derivVals[6*i+5]);
                
                for (j = 0; j < nnz; j++){
                    
                    rowInd=matInds[derivInds[j]];
                    
                    if (rowInd<numCP){
                        
                        if (rowInd>colInd){
                            
                            HessApprx[(2*colInd)*numRows+2*rowInd]+=derivVals[6*i]*derivVals[6*j]+derivVals[6*i+1]*derivVals[6*j+1]+derivVals[6*i+2]*derivVals[6*j+2];
                            HessApprx[(2*colInd)*numRows+2*rowInd+1]+=derivVals[6*i]*derivVals[6*j+3]+derivVals[6*i+1]*derivVals[6*j+4]+derivVals[6*i+2]*derivVals[6*j+5];
                            HessApprx[(2*colInd+1)*numRows+2*rowInd]+=derivVals[6*i+3]*derivVals[6*j]+derivVals[6*i+4]*derivVals[6*j+1]+derivVals[6*i+5]*derivVals[6*j+2];
                            HessApprx[(2*colInd+1)*numRows+2*rowInd+1]+=derivVals[6*i+3]*derivVals[6*j+3]+derivVals[6*i+4]*derivVals[6*j+4]+derivVals[6*i+5]*derivVals[6*j+5];
                            
                        }
                        else if (rowInd==colInd){
                            
                            HessApprx[(2*colInd)*numRows+2*rowInd]+=derivVals[6*i]*derivVals[6*j]+derivVals[6*i+1]*derivVals[6*j+1]+derivVals[6*i+2]*derivVals[6*j+2];
                            HessApprx[(2*colInd)*numRows+2*rowInd+1]+=derivVals[6*i]*derivVals[6*j+3]+derivVals[6*i+1]*derivVals[6*j+4]+derivVals[6*i+2]*derivVals[6*j+5];
                            HessApprx[(2*colInd+1)*numRows+2*rowInd+1]+=derivVals[6*i+3]*derivVals[6*j+3]+derivVals[6*i+4]*derivVals[6*j+4]+derivVals[6*i+5]*derivVals[6*j+5];
                            
                        }
                        
                    }
                    
                }
                
            }
            
        }
        
    }
    
    for (i = 1; i < numRows; i++){
        for (j = 0; j < i; j++){
            HessApprx[i*numRows+j]=HessApprx[j*numRows+i];
        }
    }
    
}

static void computeGNmatPnt2Pln(int degU, int degV, double *cpw, double *cp, int ncp, int kcp, double *knotU, double *knotV, double *us, int nus, double *dirOffset, double *cpDir, double *sgnDistDiff, double *HessApprx, double *gradIent, int *matInds, int *derivInds, double *derivVals, double *leftU, double *rightU, double *NU, double *leftV, double *rightV, double *NV){
    
    /* computeGNmatPnt2Pln( degU - degree of NURBS in u, degV - degree of NURBS in v, cpw - pointer to weighted control points, cp - pointer to control points, ncp - number of control points in u, kcp - number of control points in v, knotU - pointer to knot sequence in u, knotV - pointer to knot sequence in v, us - pointer to parameter values, nus - number of evaluations, dirOffset - direction of offset, cpDir - direction of CP-update, sgnDistDiff - difference of sign dist, HessApprx - Gauss-Newton Hessian, gradIent - gradient , matInds - matrix indices, derivInds - , leftU - pointer to array for function BasisFuns, rightU - pointer to array for function BasisFuns, NU - pointer to array for function BasisFuns, leftV - pointer to array for function BasisFuns, rightV - pointer to array for function BasisFuns, NV - pointer to array for function BasisFuns) */
    
    int i, j, ii, twoii, threeii, spanU, spanV, ind, ind2, dind, fourncp, myint, numCP, numRows, orderU, orderV, nnz, rowInd, colInd, cpInd;
    double bspnt[4];
    
    fourncp=4*ncp;
    orderU=degU+1;
    orderV=degV+1;
    
    nnz=orderU*orderV;
    
    numCP=ncp*kcp;
    
    numRows=2*(numCP-4);
    
    /* ii=0,1,2,...,nus-1 */
    
    for (ii = 0; ii < nus; ii++){
        
        twoii=2*ii;
        threeii=3*ii;
        
        spanU = FindSpan(ncp, degU, us[twoii], knotU);
        BasisFuns(spanU, us[twoii], degU, knotU, NU, leftU, rightU);
        
        ind = spanU - degU;
        
        spanV = FindSpan(kcp, degV, us[twoii+1], knotV);
        BasisFuns(spanV, us[twoii+1], degV, knotV, NV, leftV, rightV);
        
        ind2 = spanV - degV;
        myint=ind2*fourncp+ind*4;
        
        bspnt[0]=0.0;
        bspnt[1]=0.0;
        bspnt[2]=0.0;
        bspnt[3]=0.0;
        for (i = 0; i <= degV; i++){
            for (j = 0; j <= degU; j++){
                bspnt[0] += NV[i] * NU[j] * cpw[i*fourncp+j*4+myint];
                bspnt[1] += NV[i] * NU[j] * cpw[i*fourncp+j*4+myint+1];
                bspnt[2] += NV[i] * NU[j] * cpw[i*fourncp+j*4+myint+2];
                bspnt[3] += NV[i] * NU[j] * cpw[i*fourncp+j*4+myint+3];
            }
        }
        
        dind=0;
        for (i = 0; i <= degV; i++){
            for (j = 0; j <= degU; j++){
                cpInd=(ind2+i)*ncp+ind+j;
                derivInds[dind]=cpInd;
                derivVals[2*dind]=NV[i]*NU[j]*cpw[4*cpInd+3]*(dirOffset[threeii]*cpDir[3*cpInd]+dirOffset[threeii+1]*cpDir[3*cpInd+1]+dirOffset[threeii+2]*cpDir[3*cpInd+2])/bspnt[3];
                derivVals[2*dind+1]=NV[i]*NU[j]*(dirOffset[threeii]*(bspnt[3]*cp[3*cpInd]-bspnt[0])+dirOffset[threeii+1]*(bspnt[3]*cp[3*cpInd+1]-bspnt[1])+dirOffset[threeii+2]*(bspnt[3]*cp[3*cpInd+2]-bspnt[2]))/(bspnt[3]*bspnt[3]);
                dind++;
            }
        }
        
        for (i = 0; i < nnz; i++){
            
            colInd=matInds[derivInds[i]];
            
            if (colInd<numCP){
                
                gradIent[2*colInd]+=sgnDistDiff[ii]*derivVals[2*i];
                gradIent[2*colInd+1]+=sgnDistDiff[ii]*derivVals[2*i+1];
                
                for (j = 0; j < nnz; j++){
                    
                    rowInd=matInds[derivInds[j]];
                    
                    if (rowInd<numCP){
                        
                        if (rowInd>colInd){
                            
                            HessApprx[(2*colInd)*numRows+2*rowInd]+=derivVals[2*i]*derivVals[2*j];
                            HessApprx[(2*colInd)*numRows+2*rowInd+1]+=derivVals[2*i]*derivVals[2*j+1];
                            HessApprx[(2*colInd+1)*numRows+2*rowInd]+=derivVals[2*i+1]*derivVals[2*j];
                            HessApprx[(2*colInd+1)*numRows+2*rowInd+1]+=derivVals[2*i+1]*derivVals[2*j+1];
                            
                        }
                        else if (rowInd==colInd){
                            
                            HessApprx[(2*colInd)*numRows+2*rowInd]+=derivVals[2*i]*derivVals[2*j];
                            HessApprx[(2*colInd)*numRows+2*rowInd+1]+=derivVals[2*i]*derivVals[2*j+1];
                            HessApprx[(2*colInd+1)*numRows+2*rowInd+1]+=derivVals[2*i+1]*derivVals[2*j+1];
                            
                        }
                        
                    }
                    
                }
                
            }
            
        }
        
    }
    
    for (i = 1; i < numRows; i++){
        for (j = 0; j < i; j++){
            HessApprx[i*numRows+j]=HessApprx[j*numRows+i];
        }
    }
    
}

static void scaleGNdirCare(int ncp, int kcp, int *matInds, double *cp, double *gnDir){
    
    /* scaleGNdirCare(ncp - number of control points in u, kcp - number of control points in v, matInds - array of indices to the GN matrix, cp - control points, gnDir - search direction) */
    
    int ii, numCP;
    double alpha=1.0;
    
    numCP=ncp*kcp;
    
    for (ii = 1; ii <= (numCP-2); ii++){
        if (matInds[ii]<numCP){
            if (gnDir[2*matInds[ii]+1]<-0.5*cp[4*ii+3]){
                alpha=MIN(alpha,-0.5*cp[4*ii+3]/gnDir[2*matInds[ii]+1]);
            }
            else if (gnDir[2*matInds[ii]+1]>cp[4*ii+3]){
                alpha=MIN(alpha,cp[4*ii+3]/gnDir[2*matInds[ii]+1]);
            }
        }
    }
    
    /* Scale search direction */
    alpha=-alpha;
    for (ii = 0; ii <  2*(numCP-4); ii++){
        gnDir[ii]=alpha*gnDir[ii];
    }
    
    return;
    
}

static void scaleGNdir(int ncp, int kcp, int *matInds, double *cp, double *gnDir){
    
    /* scaleGNdir(ncp - number of control points in u, kcp - number of control points in v, matInds - array of indices to the GN matrix, cp - control points, gnDir - search direction) */
    
    int ii, numCP;
    double alpha=1.0;
    
    numCP=ncp*kcp;
    
    for (ii = 1; ii <= (numCP-2); ii++){
        if (matInds[ii]<numCP){
            if (gnDir[2*matInds[ii]+1]<-0.9*cp[4*ii+3]){
                alpha=MIN(alpha,-0.9*cp[4*ii+3]/gnDir[2*matInds[ii]+1]);
            }
            else if (gnDir[2*matInds[ii]+1]>9.0*cp[4*ii+3]){
                alpha=MIN(alpha,9.0*cp[4*ii+3]/gnDir[2*matInds[ii]+1]);
            }
        }
    }
    
    /* Scale search direction */
    alpha=-alpha;
    for (ii = 0; ii <  2*(numCP-4); ii++){
        gnDir[ii]=alpha*gnDir[ii];
    }
    
    return;
    
}

static void updateCP(int ncp, int kcp, double *cp, double *gnDir, double *dirOffset){
    
    int i;
    
    for (i=0 ; i < kcp*ncp ; i++){
        cp[4*i]+=gnDir[i]*dirOffset[3*i];
        cp[4*i+1]+=gnDir[i]*dirOffset[3*i+1];
        cp[4*i+2]+=gnDir[i]*dirOffset[3*i+2];
    }
    
}

static void updateCPneg(int ncp, int kcp, double *cp, double *gnDir, double *dirOffset){
    
    int i;
    
    for (i=0 ; i < kcp*ncp ; i++){
        cp[4*i]-=gnDir[i]*dirOffset[3*i];
        cp[4*i+1]-=gnDir[i]*dirOffset[3*i+1];
        cp[4*i+2]-=gnDir[i]*dirOffset[3*i+2];
    }
    
}

double lineSearchUpdateOffsetNURBS(int degU, int degV, double *cpw, double *cp, int ncp, int kcp, double *knotU, double *knotV, double *us, int nus, double *dirOffset, double *cpDir, double *sgnDistDiff, int *matInds, double *gnDir, double *gradIent, double *leftU, double *rightU, double *NU, double *leftV, double *rightV, double *NV){
    
    /* lineSearchUpdateOffsetNURBS( degU - degree of NURBS in u, degV - degree of NURBS in v, cpw - pointer to weighted control points, ncp - number of control points in u, kcp - number of control points in v, knotU - pointer to knot sequence in u, knotV - pointer to knot sequence in v, us - pointer to parameter values, nus - number of evaluations, dirOffset - direction of offset, cpDir - direction of CP-update, sgnDistDiff - difference of sign dist, matInds - matrix indices, gnDir - search direction, gradIent - gradient, leftU - pointer to array for function BasisFuns, rightU - pointer to array for function BasisFuns, NU - pointer to array for function BasisFuns, leftV - pointer to array for function BasisFuns, rightV - pointer to array for function BasisFuns, NV - pointer to array for function BasisFuns) */
    
    int i, j, ii, itr, twoii, threeii, spanU, spanV, ind, ind2, fourncp, myint, numCP, numRows, orderU, orderV, cpInd;
    double bspnt[4], f0, scfp0, falpha, fdiff=0.0, alpha=1.0;
    
    fourncp=4*ncp;
    orderU=degU+1;
    orderV=degV+1;
    
    numCP=ncp*kcp;
    
    numRows=2*(numCP-4);
    
    f0=0.0;
    for (ii = 0; ii < nus; ii++){
        f0+=sgnDistDiff[ii]*sgnDistDiff[ii];
    }
    
    scfp0=0.0;
    for (ii = 0; ii < numRows; ii++){
        scfp0+=gnDir[ii]*gradIent[ii];
    }
    scfp0=0.5*scfp0;
    
    for (itr = 0; itr < 50; itr++){
        
        falpha=0.0;
        for (ii = 0; ii < nus; ii++){
            
            twoii=2*ii;
            threeii=3*ii;
            
            spanU = FindSpan(ncp, degU, us[twoii], knotU);
            BasisFuns(spanU, us[twoii], degU, knotU, NU, leftU, rightU);
            
            ind = spanU - degU;
            
            spanV = FindSpan(kcp, degV, us[twoii+1], knotV);
            BasisFuns(spanV, us[twoii+1], degV, knotV, NV, leftV, rightV);
            
            ind2 = spanV - degV;
            myint=ind2*fourncp+ind*4;
            
            bspnt[0]=0.0;
            bspnt[1]=0.0;
            bspnt[2]=0.0;
            bspnt[3]=0.0;
            for (i = 0; i <= degV; i++){
                for (j = 0; j <= degU; j++){
                    cpInd=(ind2+i)*ncp+ind+j;
                    if (matInds[cpInd]<numCP){
                        bspnt[0] += NV[i] * NU[j] * (cpw[4*cpInd+3]+alpha*gnDir[2*matInds[cpInd]+1])*(cp[3*cpInd]+alpha*gnDir[2*matInds[cpInd]]*cpDir[3*cpInd]);
                        bspnt[1] += NV[i] * NU[j] * (cpw[4*cpInd+3]+alpha*gnDir[2*matInds[cpInd]+1])*(cp[3*cpInd+1]+alpha*gnDir[2*matInds[cpInd]]*cpDir[3*cpInd+1]);
                        bspnt[2] += NV[i] * NU[j] * (cpw[4*cpInd+3]+alpha*gnDir[2*matInds[cpInd]+1])*(cp[3*cpInd+2]+alpha*gnDir[2*matInds[cpInd]]*cpDir[3*cpInd+2]);
                        bspnt[3] += NV[i] * NU[j] * (cpw[4*cpInd+3]+alpha*gnDir[2*matInds[cpInd]+1]);
                    }
                    else {
                        bspnt[0] += NV[i] * NU[j] * cpw[4*cpInd];
                        bspnt[1] += NV[i] * NU[j] * cpw[4*cpInd+1];
                        bspnt[2] += NV[i] * NU[j] * cpw[4*cpInd+2];
                        bspnt[3] += NV[i] * NU[j] * cpw[4*cpInd+3];
                    }
                }
            }
            
            falpha+=pwr2((dirOffset[threeii]*bspnt[0]+dirOffset[threeii+1]*bspnt[1]+dirOffset[threeii+2]*bspnt[2])/bspnt[3]+sgnDistDiff[ii+nus]);
            
        }
        
        if (falpha<(f0+alpha*scfp0)){
            fdiff=f0-falpha;
            for (cpInd = 0; cpInd < numCP; cpInd++){
                if (matInds[cpInd]<numCP){
                    cp[3*cpInd]+=alpha*gnDir[2*matInds[cpInd]]*cpDir[3*cpInd];
                    cp[3*cpInd+1]+=alpha*gnDir[2*matInds[cpInd]]*cpDir[3*cpInd+1];
                    cp[3*cpInd+2]+=alpha*gnDir[2*matInds[cpInd]]*cpDir[3*cpInd+2];
                    cpw[4*cpInd+3]+=alpha*gnDir[2*matInds[cpInd]+1];
                    cpw[4*cpInd]=cpw[4*cpInd+3]*cp[3*cpInd];
                    cpw[4*cpInd+1]=cpw[4*cpInd+3]*cp[3*cpInd+1];
                    cpw[4*cpInd+2]=cpw[4*cpInd+3]*cp[3*cpInd+2];
                }
            }
            break;
        }
        else {
            alpha=0.5*alpha;
        }
        
    }
    
    return(fdiff);
    
}

static void setCornerCP(double *cpw, int ncp, int kcp, double *dirOffset, double *sgnDistDiff){
    
    int ind;
    
    ind=0;
    cpw[4*ind]-=cpw[4*ind+3]*sgnDistDiff[ind]*dirOffset[3*ind];
    cpw[4*ind+1]-=cpw[4*ind+3]*sgnDistDiff[ind]*dirOffset[3*ind+1];
    cpw[4*ind+2]-=cpw[4*ind+3]*sgnDistDiff[ind]*dirOffset[3*ind+2];
    
    ind=ncp-1;
    cpw[4*ind]-=cpw[4*ind+3]*sgnDistDiff[ind]*dirOffset[3*ind];
    cpw[4*ind+1]-=cpw[4*ind+3]*sgnDistDiff[ind]*dirOffset[3*ind+1];
    cpw[4*ind+2]-=cpw[4*ind+3]*sgnDistDiff[ind]*dirOffset[3*ind+2];
    
    ind=(kcp-1)*ncp;
    cpw[4*ind]-=cpw[4*ind+3]*sgnDistDiff[ind]*dirOffset[3*ind];
    cpw[4*ind+1]-=cpw[4*ind+3]*sgnDistDiff[ind]*dirOffset[3*ind+1];
    cpw[4*ind+2]-=cpw[4*ind+3]*sgnDistDiff[ind]*dirOffset[3*ind+2];
    
    ind=ncp*kcp-1;
    cpw[4*ind]-=cpw[4*ind+3]*sgnDistDiff[ind]*dirOffset[3*ind];
    cpw[4*ind+1]-=cpw[4*ind+3]*sgnDistDiff[ind]*dirOffset[3*ind+1];
    cpw[4*ind+2]-=cpw[4*ind+3]*sgnDistDiff[ind]*dirOffset[3*ind+2];
    
}

static void getUnweightedCP(int ncp, int kcp, double *cpw, double *cp){
    
    int i;
    
    for (i=0 ; i < kcp*ncp ; i++){
        cp[3*i]=cpw[4*i]/cpw[4*i+3];
        cp[3*i+1]=cpw[4*i+1]/cpw[4*i+3];
        cp[3*i+2]=cpw[4*i+2]/cpw[4*i+3];
    }
    
}

static void getWeights(int ncp, int kcp, double *cpw, double *wghs){
    
    int i;
    
    for (i=0 ; i < kcp*ncp ; i++){
        wghs[i]=cpw[4*i+3];
    }
    
}
