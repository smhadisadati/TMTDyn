
/* Written by Per Bergström */

/* Required length of doubleVars 85 */

static void findMinTrfExpPenalty(double *paramFinal, unsigned char iters, double *paramConstrMin, double *linzGrad, double *linzHess, double *quasum, double *datam, double *modelm, double *Spx, double *constTermCnsFcn, double *constrFcnMatrxs, double *pnltyParamVal, double *exponConstVal, double *expTempVar, double *Vec, double *alphaLinSrch, double *pnltyParamUpdt, double *doubleVars){
    
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
    
    /* -log(3.0)=-1.0986122886681097 */
    pnltyParamVal[0]=-1.0986122886681097/constrFcnMatrxs[0];
    exponConstVal[0]=3.0*(doubleVars[0]-sym6x6MatVecInnrProdSum(linzGrad, linzHess, paramFinal));
    expTempVar[0]=exponConstVal[0]*exp(pnltyParamVal[0]*constrFcnMatrxs[0]);
    
    constrFcnMatrxs[1]=pnltyParamVal[0]*constrFcnMatrxs[1];
    constrFcnMatrxs[2]=pnltyParamVal[0]*constrFcnMatrxs[2];
    constrFcnMatrxs[3]=pnltyParamVal[0]*constrFcnMatrxs[3];
    constrFcnMatrxs[4]=pnltyParamVal[0]*constrFcnMatrxs[4];
    constrFcnMatrxs[5]=pnltyParamVal[0]*constrFcnMatrxs[5];
    constrFcnMatrxs[6]=pnltyParamVal[0]*constrFcnMatrxs[6];
    
    sym6x6MatExpPenaltyOprtrs(constrFcnMatrxs, linzHess, linzGrad, paramConstrMin, expTempVar, pnltyParamVal);
    
    /* Find the Newton step of the augmented problem */
    genzCGM(&constrFcnMatrxs[7], &constrFcnMatrxs[1], Vec, &doubleVars[2]);
    
    doubleVars[0]+=expTempVar[0];
    doubleVars[1]=0.25*(constrFcnMatrxs[1]*Vec[0]+constrFcnMatrxs[2]*Vec[1]+constrFcnMatrxs[3]*Vec[2]+constrFcnMatrxs[4]*Vec[3]+constrFcnMatrxs[5]*Vec[4]+constrFcnMatrxs[6]*Vec[5]);
    
    /* Use line search and update the parameters */
    alphaLinSrch[0]=linesearchPenalty(paramFinal, constrFcnMatrxs, paramConstrMin, Vec, exponConstVal, pnltyParamVal, linzGrad, linzHess, quasum, datam, modelm, Spx, constTermCnsFcn, doubleVars, &doubleVars[1], &doubleVars[2]);
    
    for (i=0;i<iters;i++){
        
        /* iterate... */
        
        pnltyParamUpdt[0]=1.1+0.8*alphaLinSrch[0];
        
        /* Update the penalty parameter */
        pnltyParamVal[0]=pnltyParamUpdt[0]*pnltyParamVal[0];
        expTempVar[0]=exponConstVal[0]*exp(pnltyParamVal[0]*constrFcnMatrxs[0]);
        
        constrainingFcnGradHessNotF(constrFcnMatrxs, paramFinal, quasum, datam, modelm, Spx, doubleVars);
        
        constrFcnMatrxs[1]=pnltyParamVal[0]*constrFcnMatrxs[1];
        constrFcnMatrxs[2]=pnltyParamVal[0]*constrFcnMatrxs[2];
        constrFcnMatrxs[3]=pnltyParamVal[0]*constrFcnMatrxs[3];
        constrFcnMatrxs[4]=pnltyParamVal[0]*constrFcnMatrxs[4];
        constrFcnMatrxs[5]=pnltyParamVal[0]*constrFcnMatrxs[5];
        constrFcnMatrxs[6]=pnltyParamVal[0]*constrFcnMatrxs[6];
        
        sym6x6MatExpPenaltyOprtrs(constrFcnMatrxs, linzHess, linzGrad, paramFinal, expTempVar, pnltyParamVal);
        
        /* Find the Newton step of the augmented problem */
        genzCGM(&constrFcnMatrxs[7], &constrFcnMatrxs[1], Vec, &doubleVars[2]);
        
        doubleVars[0]=sym6x6MatVecInnrProdSum(linzGrad, linzHess, paramFinal)+expTempVar[0];
        doubleVars[1]=0.25*(constrFcnMatrxs[1]*Vec[0]+constrFcnMatrxs[2]*Vec[1]+constrFcnMatrxs[3]*Vec[2]+constrFcnMatrxs[4]*Vec[3]+constrFcnMatrxs[5]*Vec[4]+constrFcnMatrxs[6]*Vec[5]);
        
        /* Use line search */
        alphaLinSrch[0]=linesearchPenalty(&constrFcnMatrxs[7], constrFcnMatrxs, paramFinal, Vec, exponConstVal, pnltyParamVal, linzGrad, linzHess, quasum, datam, modelm, Spx, constTermCnsFcn, doubleVars, &doubleVars[1], &doubleVars[2]);
        
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

static void trfExpPenalty(double *paramFinal, unsigned char iters, double *paramConstrMin, double *linzGrad, double *linzHess, double *quasum, double *datam, double *modelm, double *Spx, double *constTermCnsFcn, double *doubleVars){
    
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
        
        findMinTrfExpPenalty(paramFinal, iters, paramConstrMin, linzGrad, linzHess, quasum, datam, modelm, Spx, constTermCnsFcn, doubleVars, &doubleVars[28], &doubleVars[29], &doubleVars[30], &doubleVars[31], &doubleVars[37], &doubleVars[38], &doubleVars[39]);
        
        findBoundaryFromApprx(paramFinal, paramConstrMin, linzGrad, linzHess, quasum, datam, modelm, Spx, constTermCnsFcn, doubleVars);
        
    }
    
    return;
    
}
