
/* Written by Per Bergström */

/* Required length of doubleVars 25 */
/* Required length of constrFcnMatrxs 2 */

double linesearchRcprBarrier(double *paramFinal, double *constrFcnMatrxs, double *paramStart, double *searchDirct, double *barrirParamVal, double *linzGrad, double *linzHess, double *quasum, double *datam, double *modelm, double *Spx, double *constTermCnsFcn, double *fcnStart, double *slopeStart, double *doubleVars){
    
    unsigned char i;
    
    /* alpha=1 */
    paramFinal[0]=paramStart[0]+searchDirct[0];
    paramFinal[1]=paramStart[1]+searchDirct[1];
    paramFinal[2]=paramStart[2]+searchDirct[2];
    paramFinal[3]=paramStart[3]+searchDirct[3];
    paramFinal[4]=paramStart[4]+searchDirct[4];
    paramFinal[5]=paramStart[5]+searchDirct[5];
    
    constrainingFcn(constrFcnMatrxs, paramFinal, quasum, datam, modelm, Spx, &doubleVars[9]);
    constrFcnMatrxs[0]+=constTermCnsFcn[0];
    
    if (constrFcnMatrxs[0]>-1e-16){
        doubleVars[0]=2.0e300;
    }
    else {
        doubleVars[0]=sym6x6MatVecInnrProdSum(linzGrad, linzHess, paramFinal)-barrirParamVal[0]/constrFcnMatrxs[0];
    }
    
    /* alpha=0.5 */
    doubleVars[3]=paramStart[0]+0.5*searchDirct[0];
    doubleVars[4]=paramStart[1]+0.5*searchDirct[1];
    doubleVars[5]=paramStart[2]+0.5*searchDirct[2];
    doubleVars[6]=paramStart[3]+0.5*searchDirct[3];
    doubleVars[7]=paramStart[4]+0.5*searchDirct[4];
    doubleVars[8]=paramStart[5]+0.5*searchDirct[5];
    
    constrainingFcn(&constrFcnMatrxs[1], &doubleVars[3], quasum, datam, modelm, Spx, &doubleVars[9]);
    constrFcnMatrxs[1]+=constTermCnsFcn[0];
    
    if (constrFcnMatrxs[1]>-1e-16){
        doubleVars[1]=2.0e300;
    }
    else {
        doubleVars[1]=sym6x6MatVecInnrProdSum(linzGrad, linzHess, &doubleVars[3])-barrirParamVal[0]/constrFcnMatrxs[1];
    }
    
    if (doubleVars[0]<fcnStart[0] && doubleVars[0]<doubleVars[1]){
        
        /* alpha=1 seems promising */
        
        /* test alpha=0.75 */
        doubleVars[3]=paramStart[0]+0.75*searchDirct[0];
        doubleVars[4]=paramStart[1]+0.75*searchDirct[1];
        doubleVars[5]=paramStart[2]+0.75*searchDirct[2];
        doubleVars[6]=paramStart[3]+0.75*searchDirct[3];
        doubleVars[7]=paramStart[4]+0.75*searchDirct[4];
        doubleVars[8]=paramStart[5]+0.75*searchDirct[5];
        
        constrainingFcn(&constrFcnMatrxs[1], &doubleVars[3], quasum, datam, modelm, Spx, &doubleVars[9]);
        constrFcnMatrxs[1]+=constTermCnsFcn[0];
        
        if (constrFcnMatrxs[1]>-1e-16){
            doubleVars[1]=2.0e300;
        }
        else {
            doubleVars[1]=sym6x6MatVecInnrProdSum(linzGrad, linzHess, &doubleVars[3])-barrirParamVal[0]/constrFcnMatrxs[1];
        }
        
        if (doubleVars[0]<doubleVars[1]){
            
            /* Use alpha=1 */
            return 1.0;
            
        }
        else {
            
            /* Use alpha=0.75 */
            paramFinal[0]=doubleVars[3];
            paramFinal[1]=doubleVars[4];
            paramFinal[2]=doubleVars[5];
            paramFinal[3]=doubleVars[6];
            paramFinal[4]=doubleVars[7];
            paramFinal[5]=doubleVars[8];
            
            constrFcnMatrxs[0]=constrFcnMatrxs[1];
            
            return 0.75;
            
        }
        
    }
    else {
        
        if (doubleVars[1]<(fcnStart[0]+0.5*slopeStart[0])){
            
            /* alpha=0.5 seems promising */
            
            /* test alpha=0.75 */
            paramFinal[0]=paramStart[0]+0.75*searchDirct[0];
            paramFinal[1]=paramStart[1]+0.75*searchDirct[1];
            paramFinal[2]=paramStart[2]+0.75*searchDirct[2];
            paramFinal[3]=paramStart[3]+0.75*searchDirct[3];
            paramFinal[4]=paramStart[4]+0.75*searchDirct[4];
            paramFinal[5]=paramStart[5]+0.75*searchDirct[5];
            
            constrainingFcn(constrFcnMatrxs, paramFinal, quasum, datam, modelm, Spx, &doubleVars[9]);
            constrFcnMatrxs[0]+=constTermCnsFcn[0];
            
            if (constrFcnMatrxs[0]>-1e-16){
                doubleVars[0]=2.0e300;
            }
            else {
                doubleVars[0]=sym6x6MatVecInnrProdSum(linzGrad, linzHess, paramFinal)-barrirParamVal[0]/constrFcnMatrxs[0];
            }
            
            if (doubleVars[0]<doubleVars[1]){
                
                /* Use alpha=75 */
                return 0.75;
                
            }
            
            /* test alpha=0.25 */
            paramFinal[0]=paramStart[0]+0.25*searchDirct[0];
            paramFinal[1]=paramStart[1]+0.25*searchDirct[1];
            paramFinal[2]=paramStart[2]+0.25*searchDirct[2];
            paramFinal[3]=paramStart[3]+0.25*searchDirct[3];
            paramFinal[4]=paramStart[4]+0.25*searchDirct[4];
            paramFinal[5]=paramStart[5]+0.25*searchDirct[5];
            
            constrainingFcn(constrFcnMatrxs, paramFinal, quasum, datam, modelm, Spx, &doubleVars[9]);
            constrFcnMatrxs[0]+=constTermCnsFcn[0];
            
            if (constrFcnMatrxs[0]>-1e-16){
                doubleVars[0]=2.0e300;
            }
            else {
                doubleVars[0]=sym6x6MatVecInnrProdSum(linzGrad, linzHess, paramFinal)-barrirParamVal[0]/constrFcnMatrxs[0];
            }
            
            if (doubleVars[0]<doubleVars[1]){
                
                /* Use alpha=25 */
                return 0.25;
                
            }
            
            /* Use alpha=0.5 */
            paramFinal[0]=doubleVars[3];
            paramFinal[1]=doubleVars[4];
            paramFinal[2]=doubleVars[5];
            paramFinal[3]=doubleVars[6];
            paramFinal[4]=doubleVars[7];
            paramFinal[5]=doubleVars[8];
            
            constrFcnMatrxs[0]=constrFcnMatrxs[1];
            
            return 0.5;
            
        }
        else {
            
            /* Search for a smaller value of alpha */
            
            /* alpha=0.25,0.125,... */
            doubleVars[2]=0.25;
            
            for (i=0;i<200;i++){
                
                paramFinal[0]=paramStart[0]+doubleVars[2]*searchDirct[0];
                paramFinal[1]=paramStart[1]+doubleVars[2]*searchDirct[1];
                paramFinal[2]=paramStart[2]+doubleVars[2]*searchDirct[2];
                paramFinal[3]=paramStart[3]+doubleVars[2]*searchDirct[3];
                paramFinal[4]=paramStart[4]+doubleVars[2]*searchDirct[4];
                paramFinal[5]=paramStart[5]+doubleVars[2]*searchDirct[5];
                
                constrainingFcn(constrFcnMatrxs, paramFinal, quasum, datam, modelm, Spx, &doubleVars[9]);
                constrFcnMatrxs[0]+=constTermCnsFcn[0];
                
                if (constrFcnMatrxs[0]>-1e-16){
                    doubleVars[0]=2.0e300;
                }
                else {
                    doubleVars[0]=sym6x6MatVecInnrProdSum(linzGrad, linzHess, paramFinal)-barrirParamVal[0]/constrFcnMatrxs[0];
                }
                
                if (doubleVars[0]<(fcnStart[0]+doubleVars[2]*slopeStart[0])){
                    
                    /* This alpha seems promising */
                    
                    /* test 1.5*alpha */
                    doubleVars[1]=1.5*doubleVars[2];
                    doubleVars[3]=paramStart[0]+doubleVars[1]*searchDirct[0];
                    doubleVars[4]=paramStart[1]+doubleVars[1]*searchDirct[1];
                    doubleVars[5]=paramStart[2]+doubleVars[1]*searchDirct[2];
                    doubleVars[6]=paramStart[3]+doubleVars[1]*searchDirct[3];
                    doubleVars[7]=paramStart[4]+doubleVars[1]*searchDirct[4];
                    doubleVars[8]=paramStart[5]+doubleVars[1]*searchDirct[5];
                    
                    constrainingFcn(&constrFcnMatrxs[1], &doubleVars[3], quasum, datam, modelm, Spx, &doubleVars[9]);
                    constrFcnMatrxs[1]+=constTermCnsFcn[0];
                    
                    if (constrFcnMatrxs[1]>-1e-16){
                        doubleVars[1]=2.0e300;
                    }
                    else {
                        doubleVars[1]=sym6x6MatVecInnrProdSum(linzGrad, linzHess, &doubleVars[3])-barrirParamVal[0]/constrFcnMatrxs[1];
                    }
                    
                    if (doubleVars[1]<doubleVars[0]){
                        
                        /* Use 1.5*alpha */
                        paramFinal[0]=doubleVars[3];
                        paramFinal[1]=doubleVars[4];
                        paramFinal[2]=doubleVars[5];
                        paramFinal[3]=doubleVars[6];
                        paramFinal[4]=doubleVars[7];
                        paramFinal[5]=doubleVars[8];
                        
                        constrFcnMatrxs[0]=constrFcnMatrxs[1];
                        
                        return 1.5*doubleVars[2];
                        
                    }
                    
                    /* test 0.5*alpha */
                    doubleVars[1]=0.5*doubleVars[2];
                    doubleVars[3]=paramStart[0]+doubleVars[1]*searchDirct[0];
                    doubleVars[4]=paramStart[1]+doubleVars[1]*searchDirct[1];
                    doubleVars[5]=paramStart[2]+doubleVars[1]*searchDirct[2];
                    doubleVars[6]=paramStart[3]+doubleVars[1]*searchDirct[3];
                    doubleVars[7]=paramStart[4]+doubleVars[1]*searchDirct[4];
                    doubleVars[8]=paramStart[5]+doubleVars[1]*searchDirct[5];
                    
                    constrainingFcn(&constrFcnMatrxs[1], &doubleVars[3], quasum, datam, modelm, Spx, &doubleVars[9]);
                    constrFcnMatrxs[1]+=constTermCnsFcn[0];
                    
                    if (constrFcnMatrxs[1]>-1e-16){
                        doubleVars[1]=2.0e300;
                    }
                    else {
                        doubleVars[1]=sym6x6MatVecInnrProdSum(linzGrad, linzHess, &doubleVars[3])-barrirParamVal[0]/constrFcnMatrxs[1];
                    }
                    
                    if (doubleVars[1]<doubleVars[0]){
                        
                        /* Use 0.5*alpha */
                        paramFinal[0]=doubleVars[3];
                        paramFinal[1]=doubleVars[4];
                        paramFinal[2]=doubleVars[5];
                        paramFinal[3]=doubleVars[6];
                        paramFinal[4]=doubleVars[7];
                        paramFinal[5]=doubleVars[8];
                        
                        constrFcnMatrxs[0]=constrFcnMatrxs[1];
                        
                        return 0.5*doubleVars[2];
                        
                    }
                    
                    /* Use this value of alpha */
                    return (double)doubleVars[2];
                    
                }
                else {
                    
                    /* Try a smaller value of alpha */
                    doubleVars[2]=0.5*doubleVars[2];
                    
                }
                
            }
            
            /* Linesearch failed. Use a very small value of alpha */
            
            doubleVars[2]=0.000001*doubleVars[2];
            
            paramFinal[0]=paramStart[0]+doubleVars[2]*searchDirct[0];
            paramFinal[1]=paramStart[1]+doubleVars[2]*searchDirct[1];
            paramFinal[2]=paramStart[2]+doubleVars[2]*searchDirct[2];
            paramFinal[3]=paramStart[3]+doubleVars[2]*searchDirct[3];
            paramFinal[4]=paramStart[4]+doubleVars[2]*searchDirct[4];
            paramFinal[5]=paramStart[5]+doubleVars[2]*searchDirct[5];
            
            constrainingFcn(constrFcnMatrxs, paramFinal, quasum, datam, modelm, Spx, &doubleVars[9]);
            constrFcnMatrxs[0]+=constTermCnsFcn[0];
            
            return (double)doubleVars[2];
            
        }
        
    }
    
}
