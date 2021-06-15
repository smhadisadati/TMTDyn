
/* Written by Per Bergström */

unsigned char findBoundary(double *paramBoundary, double *paramInside, double *paramTarget, double *quasum, double *datam, double *modelm, double *Spx, double *constTermCnsFcn, double *doubleVars){
    /* Required length of doubleVars 55 */
    
    unsigned char i;
    
    constrainingFcn(doubleVars, paramTarget, quasum, datam, modelm, Spx, &doubleVars[18]);
    
    if ((doubleVars[0]+constTermCnsFcn[0])>0.0){
        
        /* Target point is outside the region */
        
        doubleVars[7]=paramTarget[0]-paramInside[0];
        doubleVars[8]=paramTarget[1]-paramInside[1];
        doubleVars[9]=paramTarget[2]-paramInside[2];
        doubleVars[10]=paramTarget[3]-paramInside[3];
        doubleVars[11]=paramTarget[4]-paramInside[4];
        doubleVars[12]=paramTarget[5]-paramInside[5];
        
        /* Binary search */
        
        doubleVars[13]=0.0;
        doubleVars[14]=1.0;
        
        for (i=0;i<6;i++){
            
            doubleVars[15]=0.5*(doubleVars[13]+doubleVars[14]);
            
            paramBoundary[0]=paramInside[0]+doubleVars[15]*doubleVars[7];
            paramBoundary[1]=paramInside[1]+doubleVars[15]*doubleVars[8];
            paramBoundary[2]=paramInside[2]+doubleVars[15]*doubleVars[9];
            paramBoundary[3]=paramInside[3]+doubleVars[15]*doubleVars[10];
            paramBoundary[4]=paramInside[4]+doubleVars[15]*doubleVars[11];
            paramBoundary[5]=paramInside[5]+doubleVars[15]*doubleVars[12];
            
            constrainingFcn(doubleVars, paramBoundary, quasum, datam, modelm, Spx, &doubleVars[18]);
            
            if ((doubleVars[0]+constTermCnsFcn[0])>0.0){
                doubleVars[14]=doubleVars[15];
            }
            else {
                doubleVars[13]=doubleVars[15];
            }
            
        }
        
        if (doubleVars[14]<0.02){
            
            /* Possible additional binary search */
            
            for (i=0;i<10;i++){
                
                doubleVars[15]=0.5*(doubleVars[13]+doubleVars[14]);
                
                paramBoundary[0]=paramInside[0]+doubleVars[15]*doubleVars[7];
                paramBoundary[1]=paramInside[1]+doubleVars[15]*doubleVars[8];
                paramBoundary[2]=paramInside[2]+doubleVars[15]*doubleVars[9];
                paramBoundary[3]=paramInside[3]+doubleVars[15]*doubleVars[10];
                paramBoundary[4]=paramInside[4]+doubleVars[15]*doubleVars[11];
                paramBoundary[5]=paramInside[5]+doubleVars[15]*doubleVars[12];
                
                constrainingFcn(doubleVars, paramBoundary, quasum, datam, modelm, Spx, &doubleVars[18]);
                
                if ((doubleVars[0]+constTermCnsFcn[0])>0.0){
                    doubleVars[14]=doubleVars[15];
                }
                else {
                    doubleVars[13]=doubleVars[15];
                }
                
            }
            
            if (doubleVars[14]<2.0e-5){
                
                /* Possible additional binary search */
                
                for (i=0;i<20;i++){
                    
                    doubleVars[15]=0.5*(doubleVars[13]+doubleVars[14]);
                    
                    paramBoundary[0]=paramInside[0]+doubleVars[15]*doubleVars[7];
                    paramBoundary[1]=paramInside[1]+doubleVars[15]*doubleVars[8];
                    paramBoundary[2]=paramInside[2]+doubleVars[15]*doubleVars[9];
                    paramBoundary[3]=paramInside[3]+doubleVars[15]*doubleVars[10];
                    paramBoundary[4]=paramInside[4]+doubleVars[15]*doubleVars[11];
                    paramBoundary[5]=paramInside[5]+doubleVars[15]*doubleVars[12];
                    
                    constrainingFcn(doubleVars, paramBoundary, quasum, datam, modelm, Spx, &doubleVars[18]);
                    
                    if ((doubleVars[0]+constTermCnsFcn[0])>0.0){
                        doubleVars[14]=doubleVars[15];
                    }
                    else {
                        doubleVars[13]=doubleVars[15];
                    }
                    
                }
                
                if (doubleVars[14]<2.0e-11){
                    
                    /* Possible additional binary search */
                    
                    for (i=0;i<20;i++){
                        
                        doubleVars[15]=0.5*(doubleVars[13]+doubleVars[14]);
                        
                        paramBoundary[0]=paramInside[0]+doubleVars[15]*doubleVars[7];
                        paramBoundary[1]=paramInside[1]+doubleVars[15]*doubleVars[8];
                        paramBoundary[2]=paramInside[2]+doubleVars[15]*doubleVars[9];
                        paramBoundary[3]=paramInside[3]+doubleVars[15]*doubleVars[10];
                        paramBoundary[4]=paramInside[4]+doubleVars[15]*doubleVars[11];
                        paramBoundary[5]=paramInside[5]+doubleVars[15]*doubleVars[12];
                        
                        constrainingFcn(doubleVars, paramBoundary, quasum, datam, modelm, Spx, &doubleVars[18]);
                        
                        if ((doubleVars[0]+constTermCnsFcn[0])>0.0){
                            doubleVars[14]=doubleVars[15];
                        }
                        else {
                            doubleVars[13]=doubleVars[15];
                        }
                        
                    }
                    
                    if (doubleVars[14]<2.0e-17){
                        
                        /* Possible additional binary search */
                        
                        for (i=0;i<20;i++){
                            
                            doubleVars[15]=0.5*(doubleVars[13]+doubleVars[14]);
                            
                            paramBoundary[0]=paramInside[0]+doubleVars[15]*doubleVars[7];
                            paramBoundary[1]=paramInside[1]+doubleVars[15]*doubleVars[8];
                            paramBoundary[2]=paramInside[2]+doubleVars[15]*doubleVars[9];
                            paramBoundary[3]=paramInside[3]+doubleVars[15]*doubleVars[10];
                            paramBoundary[4]=paramInside[4]+doubleVars[15]*doubleVars[11];
                            paramBoundary[5]=paramInside[5]+doubleVars[15]*doubleVars[12];
                            
                            constrainingFcn(doubleVars, paramBoundary, quasum, datam, modelm, Spx, &doubleVars[18]);
                            
                            if ((doubleVars[0]+constTermCnsFcn[0])>0.0){
                                doubleVars[14]=doubleVars[15];
                            }
                            else {
                                doubleVars[13]=doubleVars[15];
                            }
                            
                        }
                        
                        if (doubleVars[14]<2.0e-23){
                            
                            /* Possible additional binary search */
                            
                            for (i=0;i<50;i++){
                                
                                doubleVars[15]=0.5*(doubleVars[13]+doubleVars[14]);
                                
                                paramBoundary[0]=paramInside[0]+doubleVars[15]*doubleVars[7];
                                paramBoundary[1]=paramInside[1]+doubleVars[15]*doubleVars[8];
                                paramBoundary[2]=paramInside[2]+doubleVars[15]*doubleVars[9];
                                paramBoundary[3]=paramInside[3]+doubleVars[15]*doubleVars[10];
                                paramBoundary[4]=paramInside[4]+doubleVars[15]*doubleVars[11];
                                paramBoundary[5]=paramInside[5]+doubleVars[15]*doubleVars[12];
                                
                                constrainingFcn(doubleVars, paramBoundary, quasum, datam, modelm, Spx, &doubleVars[18]);
                                
                                if ((doubleVars[0]+constTermCnsFcn[0])>0.0){
                                    doubleVars[14]=doubleVars[15];
                                }
                                else {
                                    doubleVars[13]=doubleVars[15];
                                }
                                
                            }
                            
                            if (doubleVars[14]<2.0e-38){
                                
                                /* Possible additional binary search */
                                
                                for (i=0;i<50;i++){
                                    
                                    doubleVars[15]=0.5*(doubleVars[13]+doubleVars[14]);
                                    
                                    paramBoundary[0]=paramInside[0]+doubleVars[15]*doubleVars[7];
                                    paramBoundary[1]=paramInside[1]+doubleVars[15]*doubleVars[8];
                                    paramBoundary[2]=paramInside[2]+doubleVars[15]*doubleVars[9];
                                    paramBoundary[3]=paramInside[3]+doubleVars[15]*doubleVars[10];
                                    paramBoundary[4]=paramInside[4]+doubleVars[15]*doubleVars[11];
                                    paramBoundary[5]=paramInside[5]+doubleVars[15]*doubleVars[12];
                                    
                                    constrainingFcn(doubleVars, paramBoundary, quasum, datam, modelm, Spx, &doubleVars[18]);
                                    
                                    if ((doubleVars[0]+constTermCnsFcn[0])>0.0){
                                        doubleVars[14]=doubleVars[15];
                                    }
                                    else {
                                        doubleVars[13]=doubleVars[15];
                                    }
                                    
                                }
                                
                            }
                            
                        }
                        
                    }
                    
                }
                
            }
            
        }
        
        /* Newton's method */
        
        if (doubleVars[14]<2.0e-53){
            doubleVars[15]=0.95*doubleVars[13]+0.05*doubleVars[14];
            doubleVars[17]=0.5*(doubleVars[14]-doubleVars[13]);
        }
        else if (doubleVars[14]>0.99){
            doubleVars[15]=0.05*doubleVars[13]+0.95*doubleVars[14];
            doubleVars[17]=0.5*(doubleVars[14]-doubleVars[13]);
        }
        else {
            doubleVars[15]=0.5*(doubleVars[13]+doubleVars[14]);
            doubleVars[17]=0.25*(doubleVars[14]-doubleVars[13]);
        }
        
        for (i=0;i<3;i++){
            
            paramBoundary[0]=paramInside[0]+doubleVars[15]*doubleVars[7];
            paramBoundary[1]=paramInside[1]+doubleVars[15]*doubleVars[8];
            paramBoundary[2]=paramInside[2]+doubleVars[15]*doubleVars[9];
            paramBoundary[3]=paramInside[3]+doubleVars[15]*doubleVars[10];
            paramBoundary[4]=paramInside[4]+doubleVars[15]*doubleVars[11];
            paramBoundary[5]=paramInside[5]+doubleVars[15]*doubleVars[12];
            
            constrainingFcnGrad(doubleVars, paramBoundary, quasum, datam, modelm, Spx, &doubleVars[18]);
            
            doubleVars[16]=-(doubleVars[0]+constTermCnsFcn[0])/(doubleVars[1]*doubleVars[7]+doubleVars[2]*doubleVars[8]+doubleVars[3]*doubleVars[9]+doubleVars[4]*doubleVars[10]+doubleVars[5]*doubleVars[11]+doubleVars[6]*doubleVars[12]);
            
            if (doubleVars[16]>doubleVars[17]){
                doubleVars[15]+=doubleVars[17];
            }
            else if (doubleVars[16]<-doubleVars[17]){
                doubleVars[15]-=doubleVars[17];
            }
            else {
                doubleVars[15]+=doubleVars[16];
            }
            
        }
        
        if (doubleVars[15]<doubleVars[13]){
            doubleVars[15]=0.95*doubleVars[13]+0.05*doubleVars[14];
        }
        else if (doubleVars[15]>doubleVars[14]){
            doubleVars[15]=0.05*doubleVars[13]+0.95*doubleVars[14];
        }
        
        /* Update parmeters */
        
        paramBoundary[0]=paramInside[0]+doubleVars[15]*doubleVars[7];
        paramBoundary[1]=paramInside[1]+doubleVars[15]*doubleVars[8];
        paramBoundary[2]=paramInside[2]+doubleVars[15]*doubleVars[9];
        paramBoundary[3]=paramInside[3]+doubleVars[15]*doubleVars[10];
        paramBoundary[4]=paramInside[4]+doubleVars[15]*doubleVars[11];
        paramBoundary[5]=paramInside[5]+doubleVars[15]*doubleVars[12];
        
        return 1;
        
    }
    else {
        
        /* Target point is inside the region */
        
        paramBoundary[0]=paramTarget[0];
        paramBoundary[1]=paramTarget[1];
        paramBoundary[2]=paramTarget[2];
        paramBoundary[3]=paramTarget[3];
        paramBoundary[4]=paramTarget[4];
        paramBoundary[5]=paramTarget[5];
        
        return 0;
        
    }
    
}

static void findBoundaryFromApprx(double *paramBoundary, double *paramConstrMin, double *linzGrad, double *linzHess, double *quasum, double *datam, double *modelm, double *Spx, double *constTermCnsFcn, double *doubleVars){
    /* Required length of doubleVars 58 */
    
    unsigned char i;
    
    /* Function value and gradient */
    constrainingFcnGrad(doubleVars, paramBoundary, quasum, datam, modelm, Spx, &doubleVars[21]);
    doubleVars[0]+=constTermCnsFcn[0];
    
    doubleVars[20]=doubleVars[0];
    
    if (doubleVars[20]>0.0){
        
        /* Initial function value is positive, paramBoundary is outside the region */
        
        doubleVars[14]=paramConstrMin[0]-paramBoundary[0];
        doubleVars[15]=paramConstrMin[1]-paramBoundary[1];
        doubleVars[16]=paramConstrMin[2]-paramBoundary[2];
        doubleVars[17]=paramConstrMin[3]-paramBoundary[3];
        doubleVars[18]=paramConstrMin[4]-paramBoundary[4];
        doubleVars[19]=paramConstrMin[5]-paramBoundary[5];
        
        /* Find the initial Newton step towards the boundary */
        doubleVars[13]=-doubleVars[20]/(doubleVars[1]*doubleVars[14]+doubleVars[2]*doubleVars[15]+doubleVars[3]*doubleVars[16]+doubleVars[4]*doubleVars[17]+doubleVars[5]*doubleVars[18]+doubleVars[6]*doubleVars[19]);
        
        if (doubleVars[13]<0.0){
            return;
        }
        doubleVars[13]=MIN(1.0,doubleVars[13]);
        
        doubleVars[7]=paramBoundary[0]+doubleVars[13]*doubleVars[14];
        doubleVars[8]=paramBoundary[1]+doubleVars[13]*doubleVars[15];
        doubleVars[9]=paramBoundary[2]+doubleVars[13]*doubleVars[16];
        doubleVars[10]=paramBoundary[3]+doubleVars[13]*doubleVars[17];
        doubleVars[11]=paramBoundary[4]+doubleVars[13]*doubleVars[18];
        doubleVars[12]=paramBoundary[5]+doubleVars[13]*doubleVars[19];
        
        constrainingFcn(doubleVars, &doubleVars[7], quasum, datam, modelm, Spx, &doubleVars[21]);
        doubleVars[0]+=constTermCnsFcn[0];
        
        if (1.0e5*fabs(doubleVars[0])<doubleVars[20] || fabs(doubleVars[0])<1.0e-10){
            
            paramBoundary[0]=doubleVars[7];
            paramBoundary[1]=doubleVars[8];
            paramBoundary[2]=doubleVars[9];
            paramBoundary[3]=doubleVars[10];
            paramBoundary[4]=doubleVars[11];
            paramBoundary[5]=doubleVars[12];
            
            return;
            
        }
        
        /* Try to find a point closer to the boundary */
        
        doubleVars[1]=(doubleVars[20]-doubleVars[0])/doubleVars[20];
        
        if (doubleVars[1]<1.0e-3){
            return;
        }
        
        if (doubleVars[0]<0.0){
            doubleVars[13]=0.5*(1.0+1.0/doubleVars[1])*doubleVars[13];
        }
        else {
            doubleVars[13]=doubleVars[13]/doubleVars[1];
        }
        
        /* Newton iterations */
        for (i=0;i<20;i++){
            
            doubleVars[7]=paramBoundary[0]+doubleVars[13]*doubleVars[14];
            doubleVars[8]=paramBoundary[1]+doubleVars[13]*doubleVars[15];
            doubleVars[9]=paramBoundary[2]+doubleVars[13]*doubleVars[16];
            doubleVars[10]=paramBoundary[3]+doubleVars[13]*doubleVars[17];
            doubleVars[11]=paramBoundary[4]+doubleVars[13]*doubleVars[18];
            doubleVars[12]=paramBoundary[5]+doubleVars[13]*doubleVars[19];
            
            constrainingFcnGrad(doubleVars, &doubleVars[7], quasum, datam, modelm, Spx, &doubleVars[21]);
            doubleVars[0]+=constTermCnsFcn[0];
            
            doubleVars[13]-=doubleVars[0]/(doubleVars[1]*doubleVars[14]+doubleVars[2]*doubleVars[15]+doubleVars[3]*doubleVars[16]+doubleVars[4]*doubleVars[17]+doubleVars[5]*doubleVars[18]+doubleVars[6]*doubleVars[19]);
            
            if (1.0e5*fabs(doubleVars[0])<doubleVars[20] || fabs(doubleVars[0])<1.0e-10){
                break;
            }
            
        }
        
    }
    else {
        
        /* Initial function value is negative, paramBoundary is inside the region */
        
        /* Find the Newton step of the quadratic function approximation */
        genzCGMinitiate(linzHess, linzGrad, paramBoundary, &doubleVars[14], &doubleVars[21]);
        
        doubleVars[14]-=paramBoundary[0];
        doubleVars[15]-=paramBoundary[1];
        doubleVars[16]-=paramBoundary[2];
        doubleVars[17]-=paramBoundary[3];
        doubleVars[18]-=paramBoundary[4];
        doubleVars[19]-=paramBoundary[5];
        
        /* Find the initial Newton step towards the boundary */
        doubleVars[13]=-doubleVars[20]/(doubleVars[1]*doubleVars[14]+doubleVars[2]*doubleVars[15]+doubleVars[3]*doubleVars[16]+doubleVars[4]*doubleVars[17]+doubleVars[5]*doubleVars[18]+doubleVars[6]*doubleVars[19]);
        
        if (doubleVars[13]<0.0){
            return;
        }
        doubleVars[13]=MIN(1.0,doubleVars[13]);
        
        doubleVars[7]=paramBoundary[0]+doubleVars[13]*doubleVars[14];
        doubleVars[8]=paramBoundary[1]+doubleVars[13]*doubleVars[15];
        doubleVars[9]=paramBoundary[2]+doubleVars[13]*doubleVars[16];
        doubleVars[10]=paramBoundary[3]+doubleVars[13]*doubleVars[17];
        doubleVars[11]=paramBoundary[4]+doubleVars[13]*doubleVars[18];
        doubleVars[12]=paramBoundary[5]+doubleVars[13]*doubleVars[19];
        
        constrainingFcn(doubleVars, &doubleVars[7], quasum, datam, modelm, Spx, &doubleVars[21]);
        doubleVars[0]+=constTermCnsFcn[0];
        
        if (1.0e5*fabs(doubleVars[0])<-doubleVars[20] || fabs(doubleVars[0])<1.0e-10){
            
            paramBoundary[0]=doubleVars[7];
            paramBoundary[1]=doubleVars[8];
            paramBoundary[2]=doubleVars[9];
            paramBoundary[3]=doubleVars[10];
            paramBoundary[4]=doubleVars[11];
            paramBoundary[5]=doubleVars[12];
            
            return;
            
        }
        
        /* Try to find a point closer to the boundary */
        
        doubleVars[1]=(doubleVars[20]-doubleVars[0])/doubleVars[20];
        
        if (doubleVars[1]<1.0e-3){
            return;
        }
        
        if (doubleVars[0]<0.0){
            doubleVars[13]=doubleVars[13]/doubleVars[1];
        }
        else {
            doubleVars[13]=0.5*(1.0+1.0/doubleVars[1])*doubleVars[13];
        }
        
        /* Newton iterations */
        for (i=0;i<20;i++){
            
            doubleVars[7]=paramBoundary[0]+doubleVars[13]*doubleVars[14];
            doubleVars[8]=paramBoundary[1]+doubleVars[13]*doubleVars[15];
            doubleVars[9]=paramBoundary[2]+doubleVars[13]*doubleVars[16];
            doubleVars[10]=paramBoundary[3]+doubleVars[13]*doubleVars[17];
            doubleVars[11]=paramBoundary[4]+doubleVars[13]*doubleVars[18];
            doubleVars[12]=paramBoundary[5]+doubleVars[13]*doubleVars[19];
            
            constrainingFcnGrad(doubleVars, &doubleVars[7], quasum, datam, modelm, Spx, &doubleVars[21]);
            doubleVars[0]+=constTermCnsFcn[0];
            
            doubleVars[13]-=doubleVars[0]/(doubleVars[1]*doubleVars[14]+doubleVars[2]*doubleVars[15]+doubleVars[3]*doubleVars[16]+doubleVars[4]*doubleVars[17]+doubleVars[5]*doubleVars[18]+doubleVars[6]*doubleVars[19]);
            
            if (1.0e5*fabs(doubleVars[0])<-doubleVars[20] || fabs(doubleVars[0])<1.0e-10){
                break;
            }
            
        }
        
    }
    
    doubleVars[13]=MIN(1.0,doubleVars[13]);
    doubleVars[13]=MAX(0.0,doubleVars[13]);
    
    /* Check if the new point is better */
    doubleVars[7]=paramBoundary[0]+doubleVars[13]*doubleVars[14];
    doubleVars[8]=paramBoundary[1]+doubleVars[13]*doubleVars[15];
    doubleVars[9]=paramBoundary[2]+doubleVars[13]*doubleVars[16];
    doubleVars[10]=paramBoundary[3]+doubleVars[13]*doubleVars[17];
    doubleVars[11]=paramBoundary[4]+doubleVars[13]*doubleVars[18];
    doubleVars[12]=paramBoundary[5]+doubleVars[13]*doubleVars[19];
    
    constrainingFcn(doubleVars, &doubleVars[7], quasum, datam, modelm, Spx, &doubleVars[21]);
    doubleVars[0]+=constTermCnsFcn[0];
    
    if (fabs(doubleVars[0])<fabs(doubleVars[20])){
        
        paramBoundary[0]=doubleVars[7];
        paramBoundary[1]=doubleVars[8];
        paramBoundary[2]=doubleVars[9];
        paramBoundary[3]=doubleVars[10];
        paramBoundary[4]=doubleVars[11];
        paramBoundary[5]=doubleVars[12];
        
    }
    
}
