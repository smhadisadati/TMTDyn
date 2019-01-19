
/* Written by Per Bergström */

/* Required length of doubleVars 83 */

static void findMinTrfRcprBarrier(double *paramFinal, unsigned char iters, double *paramConstrMin, double *linzGrad, double *linzHess, double *quasum, double *datam, double *modelm, double *Spx, double *constTermCnsFcn, double *constrFcnMatrxs, double *barrirParamVal, double *Vec, double *alphaLinSrch, double *barrirParamUpdt, double *doubleVars){
    
    unsigned char i;
    
    /* Compute function value, gradient, and Hessian */
    constrainingFcnGradHess(constrFcnMatrxs, paramConstrMin, quasum, datam, modelm, Spx, doubleVars);
    constrFcnMatrxs[0]+=constTermCnsFcn[0];
    
    /* If the region is too small, use point to point minimization */
    if (constrFcnMatrxs[0]>-1e-6){
        
        paramFinal[0]=paramConstrMin[0];
        paramFinal[1]=paramConstrMin[1];
        paramFinal[2]=paramConstrMin[2];
        paramFinal[3]=paramConstrMin[3];
        paramFinal[4]=paramConstrMin[4];
        paramFinal[5]=paramConstrMin[5];
        
        return;
        
    }
    
    doubleVars[0]=sym6x6MatVecInnrProdSum(linzGrad, linzHess, paramConstrMin);
    
    /* Initiate some parameters */
    
    barrirParamVal[0]=0.6*constrFcnMatrxs[0]*(sym6x6MatVecInnrProdSum(linzGrad, linzHess, paramFinal)-doubleVars[0]);
    
    doubleVars[1]=barrirParamVal[0]/(constrFcnMatrxs[0]*constrFcnMatrxs[0]);
    doubleVars[2]=-2.0*doubleVars[1]/constrFcnMatrxs[0];
    
    sym6x6MatRcprBarrierOprtrs(constrFcnMatrxs, linzHess, linzGrad, paramConstrMin, &doubleVars[1], &doubleVars[2]);
    
    /* Find the Newton step of the augmented problem */
    genzCGM(&constrFcnMatrxs[7], &constrFcnMatrxs[1], Vec, &doubleVars[1]);
    
    doubleVars[0]-=barrirParamVal[0]/constrFcnMatrxs[0];
    doubleVars[1]=0.25*(constrFcnMatrxs[1]*Vec[0]+constrFcnMatrxs[2]*Vec[1]+constrFcnMatrxs[3]*Vec[2]+constrFcnMatrxs[4]*Vec[3]+constrFcnMatrxs[5]*Vec[4]+constrFcnMatrxs[6]*Vec[5]);
    
    /* Use line search and update the parameters */
    alphaLinSrch[0]=linesearchRcprBarrier(paramFinal, constrFcnMatrxs, paramConstrMin, Vec, barrirParamVal, linzGrad, linzHess, quasum, datam, modelm, Spx, constTermCnsFcn, doubleVars, &doubleVars[1], &doubleVars[2]);
    
    for (i=0;i<iters;i++){
        
        /* iterate... */
        
        barrirParamUpdt[0]=1.2+0.9*alphaLinSrch[0];
        
        /* Update the barrier parameter */
        barrirParamVal[0]=barrirParamVal[0]/barrirParamUpdt[0];
        
        constrainingFcnGradHessNotF(constrFcnMatrxs, paramFinal, quasum, datam, modelm, Spx, doubleVars);
        
        doubleVars[0]=barrirParamVal[0]/(constrFcnMatrxs[0]*constrFcnMatrxs[0]);
        doubleVars[1]=-2.0*doubleVars[0]/constrFcnMatrxs[0];
        
        sym6x6MatRcprBarrierOprtrs(constrFcnMatrxs, linzHess, linzGrad, paramFinal, doubleVars, &doubleVars[1]);
        
        /* Find the Newton step of the augmented problem */
        genzCGM(&constrFcnMatrxs[7], &constrFcnMatrxs[1], Vec, doubleVars);
        
        doubleVars[0]=sym6x6MatVecInnrProdSum(linzGrad, linzHess, paramFinal)-barrirParamVal[0]/constrFcnMatrxs[0];
        doubleVars[1]=0.25*(constrFcnMatrxs[1]*Vec[0]+constrFcnMatrxs[2]*Vec[1]+constrFcnMatrxs[3]*Vec[2]+constrFcnMatrxs[4]*Vec[3]+constrFcnMatrxs[5]*Vec[4]+constrFcnMatrxs[6]*Vec[5]);
        
        /* Use line search */
        alphaLinSrch[0]=linesearchRcprBarrier(&constrFcnMatrxs[7], constrFcnMatrxs, paramFinal, Vec, barrirParamVal, linzGrad, linzHess, quasum, datam, modelm, Spx, constTermCnsFcn, doubleVars, &doubleVars[1], &doubleVars[2]);
        
        /* Update the paramters */
        paramFinal[0]=constrFcnMatrxs[7];
        paramFinal[1]=constrFcnMatrxs[8];
        paramFinal[2]=constrFcnMatrxs[9];
        paramFinal[3]=constrFcnMatrxs[10];
        paramFinal[4]=constrFcnMatrxs[11];
        paramFinal[5]=constrFcnMatrxs[12];
        
    }
    
    return;
    
}

static void trfRcprclBarrier(double *paramFinal, unsigned char iters, double *paramConstrMin, double *linzGrad, double *linzHess, double *quasum, double *datam, double *modelm, double *Spx, double *constTermCnsFcn, double *doubleVars){
    
    /* Test to see if point to point minimum is large */
    if (fabs(paramConstrMin[0])>1.0 || fabs(paramConstrMin[1])>1.0 || fabs(paramConstrMin[2])>1.0){
        
        paramFinal[0]=paramConstrMin[0];
        paramFinal[1]=paramConstrMin[1];
        paramFinal[2]=paramConstrMin[2];
        paramFinal[3]=paramConstrMin[3];
        paramFinal[4]=paramConstrMin[4];
        paramFinal[5]=paramConstrMin[5];
        
        return;
        
    }
    
    /* Find the Newton step */
    genzCGMinitiate(linzHess, linzGrad, paramConstrMin, doubleVars, &doubleVars[6]);
    
    /* Scale the Newton step if it is too large */
    
    doubleVars[6]=doubleVars[0]-paramConstrMin[0];
    doubleVars[7]=doubleVars[1]-paramConstrMin[1];
    doubleVars[8]=doubleVars[2]-paramConstrMin[2];
    
    /* Scale the paramteters if some of the angles are too large (>pi/3) */
    if (doubleVars[0]>1.0472){
        doubleVars[9]=(1.0472-paramConstrMin[0])/doubleVars[6];
    }
    else if (doubleVars[0]<-1.0472){
        doubleVars[9]=-(1.0472+paramConstrMin[0])/doubleVars[6];
    }
    else {
        doubleVars[9]=1.0;
    }
    
    if (doubleVars[1]>1.0472){
        doubleVars[9]=MIN(doubleVars[9],(1.0472-paramConstrMin[1])/doubleVars[7]);
    }
    else if (doubleVars[1]<-1.0472){
        doubleVars[9]=MIN(doubleVars[9],-(1.0472+paramConstrMin[1])/doubleVars[7]);
    }
    
    if (doubleVars[2]>1.0472){
        doubleVars[9]=MIN(doubleVars[9],(1.0472-paramConstrMin[2])/doubleVars[8]);
    }
    else if (doubleVars[2]<-1.0472){
        doubleVars[9]=MIN(doubleVars[9],-(1.0472+paramConstrMin[2])/doubleVars[8]);
    }
    
    if (doubleVars[9]<0.999){
        doubleVars[0]=paramConstrMin[0]+doubleVars[9]*doubleVars[6];
        doubleVars[1]=paramConstrMin[1]+doubleVars[9]*doubleVars[7];
        doubleVars[2]=paramConstrMin[2]+doubleVars[9]*doubleVars[8];
        doubleVars[3]=paramConstrMin[3]+doubleVars[9]*(doubleVars[3]-paramConstrMin[3]);
        doubleVars[4]=paramConstrMin[4]+doubleVars[9]*(doubleVars[4]-paramConstrMin[4]);
        doubleVars[5]=paramConstrMin[5]+doubleVars[9]*(doubleVars[5]-paramConstrMin[5]);
    }
    
    /* Use the Newton step if it is inside the region */
    /* Otherwise, search for the minimum inside the region...  */
    /* and go to the boundary of the region in the direction of the minimum.  */
    if (findBoundary(paramFinal, paramConstrMin, doubleVars, quasum, datam, modelm, Spx, constTermCnsFcn, &doubleVars[6])){
        
        findMinTrfRcprBarrier(paramFinal, iters, paramConstrMin, linzGrad, linzHess, quasum, datam, modelm, Spx, constTermCnsFcn, doubleVars, &doubleVars[28], &doubleVars[29], &doubleVars[35], &doubleVars[36], &doubleVars[37]);
        
        findBoundaryFromApprx(paramFinal, paramConstrMin, linzGrad, linzHess, quasum, datam, modelm, Spx, constTermCnsFcn, doubleVars);
        
    }
    
    return;
    
}
