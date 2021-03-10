
/* Written by Per Bergström */

/* Required length of doubleVars 24 */

static void genzCGM(double *HessianMatrix, double *gradientVector, double *parameterStep, double *doubleVars){
    
    /* Generalization of the conjugate gradient method */
    
    unsigned char i;
    
    /* Initiate the parameter step to zero */
    parameterStep[0]=0.0;
    parameterStep[1]=0.0;
    parameterStep[2]=0.0;
    parameterStep[3]=0.0;
    parameterStep[4]=0.0;
    parameterStep[5]=0.0;
    
    /* residual=-gradientVector */
    doubleVars[6]=-gradientVector[0];
    doubleVars[7]=-gradientVector[1];
    doubleVars[8]=-gradientVector[2];
    doubleVars[9]=-gradientVector[3];
    doubleVars[10]=-gradientVector[4];
    doubleVars[11]=-gradientVector[5];
    
    /* p=residual */
    doubleVars[12]=doubleVars[6];
    doubleVars[13]=doubleVars[7];
    doubleVars[14]=doubleVars[8];
    doubleVars[15]=doubleVars[9];
    doubleVars[16]=doubleVars[10];
    doubleVars[17]=doubleVars[11];
    
    /* Squared 2-norm of initial residual */
    doubleVars[18]=doubleVars[6]*doubleVars[6]+doubleVars[7]*doubleVars[7]+doubleVars[8]*doubleVars[8]+doubleVars[9]*doubleVars[9]+doubleVars[10]*doubleVars[10]+doubleVars[11]*doubleVars[11];
    doubleVars[19]=doubleVars[18];
    
    for (i=0;i<6;i++){
        
        /* Compute matrix-vector product */
        sym6x6MatVecMult(HessianMatrix,&doubleVars[12],doubleVars);
        
        /* alpha */
        doubleVars[21]=doubleVars[19]/(doubleVars[0]*doubleVars[12]+doubleVars[1]*doubleVars[13]+doubleVars[2]*doubleVars[14]+doubleVars[3]*doubleVars[15]+doubleVars[4]*doubleVars[16]+doubleVars[5]*doubleVars[17]);
        
        if (doubleVars[21]>0.0){
            
            /* alpha>0 */
            
            /* Some security */
            if (i==0){
                doubleVars[22]=(doubleVars[21]*doubleVars[21])*(doubleVars[12]*doubleVars[12]+doubleVars[13]*doubleVars[13]+doubleVars[14]*doubleVars[14]+doubleVars[15]*doubleVars[15]+doubleVars[16]*doubleVars[16]+doubleVars[17]*doubleVars[17]);
            }
            else if (i==1){
                doubleVars[22]=1.0e6*MAX(doubleVars[22],(doubleVars[21]*doubleVars[21])*(doubleVars[12]*doubleVars[12]+doubleVars[13]*doubleVars[13]+doubleVars[14]*doubleVars[14]+doubleVars[15]*doubleVars[15]+doubleVars[16]*doubleVars[16]+doubleVars[17]*doubleVars[17]));
            }
            else {
                
                doubleVars[23]=(doubleVars[21]*doubleVars[21])*(doubleVars[12]*doubleVars[12]+doubleVars[13]*doubleVars[13]+doubleVars[14]*doubleVars[14]+doubleVars[15]*doubleVars[15]+doubleVars[16]*doubleVars[16]+doubleVars[17]*doubleVars[17]);
                
                if (doubleVars[23]>doubleVars[22]){
                    
                    /* Update the parameter step and terminate */
                    doubleVars[21]=doubleVars[21]*sqrt(doubleVars[22]/doubleVars[23]);
                    parameterStep[0]+=doubleVars[21]*doubleVars[12];
                    parameterStep[1]+=doubleVars[21]*doubleVars[13];
                    parameterStep[2]+=doubleVars[21]*doubleVars[14];
                    parameterStep[3]+=doubleVars[21]*doubleVars[15];
                    parameterStep[4]+=doubleVars[21]*doubleVars[16];
                    parameterStep[5]+=doubleVars[21]*doubleVars[17];
                    
                    return;
                    
                }
                
            }
            
            /* Update the parameter step */
            parameterStep[0]+=doubleVars[21]*doubleVars[12];
            parameterStep[1]+=doubleVars[21]*doubleVars[13];
            parameterStep[2]+=doubleVars[21]*doubleVars[14];
            parameterStep[3]+=doubleVars[21]*doubleVars[15];
            parameterStep[4]+=doubleVars[21]*doubleVars[16];
            parameterStep[5]+=doubleVars[21]*doubleVars[17];
            
            /* Update residual */
            doubleVars[6]-=doubleVars[21]*doubleVars[0];
            doubleVars[7]-=doubleVars[21]*doubleVars[1];
            doubleVars[8]-=doubleVars[21]*doubleVars[2];
            doubleVars[9]-=doubleVars[21]*doubleVars[3];
            doubleVars[10]-=doubleVars[21]*doubleVars[4];
            doubleVars[11]-=doubleVars[21]*doubleVars[5];
            
            /* Squared 2-norm of residual */
            doubleVars[20]=doubleVars[6]*doubleVars[6]+doubleVars[7]*doubleVars[7]+doubleVars[8]*doubleVars[8]+doubleVars[9]*doubleVars[9]+doubleVars[10]*doubleVars[10]+doubleVars[11]*doubleVars[11];
            
            /* Terminate if the solution is sufficiently good */
            if (i>2){
                if (doubleVars[20]<doubleVars[18]*1e-8){
                    return;
                }
            }
            
            /* Update p */
            doubleVars[21]=doubleVars[20]/doubleVars[19];
            doubleVars[12]=doubleVars[6]+doubleVars[21]*doubleVars[12];
            doubleVars[13]=doubleVars[7]+doubleVars[21]*doubleVars[13];
            doubleVars[14]=doubleVars[8]+doubleVars[21]*doubleVars[14];
            doubleVars[15]=doubleVars[9]+doubleVars[21]*doubleVars[15];
            doubleVars[16]=doubleVars[10]+doubleVars[21]*doubleVars[16];
            doubleVars[17]=doubleVars[11]+doubleVars[21]*doubleVars[17];
            
            /* Update old residual */
            doubleVars[19]=doubleVars[20];
            
        }
        else {
            
            /* alpha<=0 */
            
            doubleVars[0]=doubleVars[12]*doubleVars[12]+doubleVars[13]*doubleVars[13]+doubleVars[14]*doubleVars[14]+doubleVars[15]*doubleVars[15]+doubleVars[16]*doubleVars[16]+doubleVars[17]*doubleVars[17];
            doubleVars[1]=parameterStep[0]*parameterStep[0]+parameterStep[1]*parameterStep[1]+parameterStep[2]*parameterStep[2]+parameterStep[3]*parameterStep[3]+parameterStep[4]*parameterStep[4]+parameterStep[5]*parameterStep[5];
            
            if (doubleVars[0]>1.0e-36 && doubleVars[1]>1.0e-36){
                
                doubleVars[21]=0.5*sqrt(doubleVars[1]/doubleVars[0]);
                
            }
            else {
                
                /* Some security */
                if (i>1){
                    
                    doubleVars[23]=(doubleVars[21]*doubleVars[21])*doubleVars[0];
                    
                    if (doubleVars[23]>doubleVars[22]){
                        doubleVars[21]=-0.5*doubleVars[21]*sqrt(doubleVars[22]/doubleVars[23]);
                    }
                    else {
                        doubleVars[21]=-0.5*doubleVars[21];
                    }
                    
                }
                else {
                    
                    doubleVars[21]=-0.5*doubleVars[21];
                    
                }
                
                
            }
            
            /* Update the parameter step and terminate */
            
            parameterStep[0]+=doubleVars[21]*doubleVars[12];
            parameterStep[1]+=doubleVars[21]*doubleVars[13];
            parameterStep[2]+=doubleVars[21]*doubleVars[14];
            parameterStep[3]+=doubleVars[21]*doubleVars[15];
            parameterStep[4]+=doubleVars[21]*doubleVars[16];
            parameterStep[5]+=doubleVars[21]*doubleVars[17];
            
            parameterStep[0]=0.75*parameterStep[0];
            parameterStep[1]=0.75*parameterStep[1];
            parameterStep[2]=0.75*parameterStep[2];
            parameterStep[3]=0.75*parameterStep[3];
            parameterStep[4]=0.75*parameterStep[4];
            parameterStep[5]=0.75*parameterStep[5];
            
            return;
            
        }
        
    }
    
}

static void genzCGMinitiate(double *HessianMatrix, double *gradientVector, double *parameterStart, double *parameterStep, double *doubleVars){
    
    /* Generalization of the conjugate gradient method */
    
    unsigned char i;
    
    /* Initiate the parameter step */
    parameterStep[0]=parameterStart[0];
    parameterStep[1]=parameterStart[1];
    parameterStep[2]=parameterStart[2];
    parameterStep[3]=parameterStart[3];
    parameterStep[4]=parameterStart[4];
    parameterStep[5]=parameterStart[5];
    
    /* residual=-(HessianMatrix*parameterStep+gradientVector) */
    negSym6x6MatVecMultVecAdd(HessianMatrix,parameterStep,gradientVector,&doubleVars[6]);
    
    /* p=residual */
    doubleVars[12]=doubleVars[6];
    doubleVars[13]=doubleVars[7];
    doubleVars[14]=doubleVars[8];
    doubleVars[15]=doubleVars[9];
    doubleVars[16]=doubleVars[10];
    doubleVars[17]=doubleVars[11];
    
    /* Squared 2-norm of initial residual */
    doubleVars[18]=doubleVars[6]*doubleVars[6]+doubleVars[7]*doubleVars[7]+doubleVars[8]*doubleVars[8]+doubleVars[9]*doubleVars[9]+doubleVars[10]*doubleVars[10]+doubleVars[11]*doubleVars[11];
    doubleVars[19]=doubleVars[18];
    
    for (i=0;i<6;i++){
        
        /* Compute matrix-vector product */
        sym6x6MatVecMult(HessianMatrix,&doubleVars[12],doubleVars);
        
        /* alpha */
        doubleVars[21]=doubleVars[19]/(doubleVars[0]*doubleVars[12]+doubleVars[1]*doubleVars[13]+doubleVars[2]*doubleVars[14]+doubleVars[3]*doubleVars[15]+doubleVars[4]*doubleVars[16]+doubleVars[5]*doubleVars[17]);
        
        if (doubleVars[21]>0.0){
            
            /* alpha>0 */
            
            /* Some security */
            if (i==0){
                doubleVars[22]=(doubleVars[21]*doubleVars[21])*(doubleVars[12]*doubleVars[12]+doubleVars[13]*doubleVars[13]+doubleVars[14]*doubleVars[14]+doubleVars[15]*doubleVars[15]+doubleVars[16]*doubleVars[16]+doubleVars[17]*doubleVars[17]);
            }
            else if (i==1){
                doubleVars[22]=1.0e6*MAX(doubleVars[22],(doubleVars[21]*doubleVars[21])*(doubleVars[12]*doubleVars[12]+doubleVars[13]*doubleVars[13]+doubleVars[14]*doubleVars[14]+doubleVars[15]*doubleVars[15]+doubleVars[16]*doubleVars[16]+doubleVars[17]*doubleVars[17]));
            }
            else {
                
                doubleVars[23]=(doubleVars[21]*doubleVars[21])*(doubleVars[12]*doubleVars[12]+doubleVars[13]*doubleVars[13]+doubleVars[14]*doubleVars[14]+doubleVars[15]*doubleVars[15]+doubleVars[16]*doubleVars[16]+doubleVars[17]*doubleVars[17]);
                
                if (doubleVars[23]>doubleVars[22]){
                    
                    /* Update the parameter step and terminate */
                    doubleVars[21]=doubleVars[21]*sqrt(doubleVars[22]/doubleVars[23]);
                    parameterStep[0]+=doubleVars[21]*doubleVars[12];
                    parameterStep[1]+=doubleVars[21]*doubleVars[13];
                    parameterStep[2]+=doubleVars[21]*doubleVars[14];
                    parameterStep[3]+=doubleVars[21]*doubleVars[15];
                    parameterStep[4]+=doubleVars[21]*doubleVars[16];
                    parameterStep[5]+=doubleVars[21]*doubleVars[17];
                    
                    return;
                    
                }
                
            }
            
            /* Update the parameter step */
            parameterStep[0]+=doubleVars[21]*doubleVars[12];
            parameterStep[1]+=doubleVars[21]*doubleVars[13];
            parameterStep[2]+=doubleVars[21]*doubleVars[14];
            parameterStep[3]+=doubleVars[21]*doubleVars[15];
            parameterStep[4]+=doubleVars[21]*doubleVars[16];
            parameterStep[5]+=doubleVars[21]*doubleVars[17];
            
            /* Update residual */
            doubleVars[6]-=doubleVars[21]*doubleVars[0];
            doubleVars[7]-=doubleVars[21]*doubleVars[1];
            doubleVars[8]-=doubleVars[21]*doubleVars[2];
            doubleVars[9]-=doubleVars[21]*doubleVars[3];
            doubleVars[10]-=doubleVars[21]*doubleVars[4];
            doubleVars[11]-=doubleVars[21]*doubleVars[5];
            
            /* Squared 2-norm of residual */
            doubleVars[20]=doubleVars[6]*doubleVars[6]+doubleVars[7]*doubleVars[7]+doubleVars[8]*doubleVars[8]+doubleVars[9]*doubleVars[9]+doubleVars[10]*doubleVars[10]+doubleVars[11]*doubleVars[11];
            
            /* Terminate if the solution is sufficiently good */
            if (i>2){
                if (doubleVars[20]<doubleVars[18]*1e-8){
                    return;
                }
            }
            
            /* Update p */
            doubleVars[21]=doubleVars[20]/doubleVars[19];
            doubleVars[12]=doubleVars[6]+doubleVars[21]*doubleVars[12];
            doubleVars[13]=doubleVars[7]+doubleVars[21]*doubleVars[13];
            doubleVars[14]=doubleVars[8]+doubleVars[21]*doubleVars[14];
            doubleVars[15]=doubleVars[9]+doubleVars[21]*doubleVars[15];
            doubleVars[16]=doubleVars[10]+doubleVars[21]*doubleVars[16];
            doubleVars[17]=doubleVars[11]+doubleVars[21]*doubleVars[17];
            
            /* Update old residual */
            doubleVars[19]=doubleVars[20];
            
        }
        else {
            
            /* alpha<=0 */
            
            doubleVars[0]=doubleVars[12]*doubleVars[12]+doubleVars[13]*doubleVars[13]+doubleVars[14]*doubleVars[14]+doubleVars[15]*doubleVars[15]+doubleVars[16]*doubleVars[16]+doubleVars[17]*doubleVars[17];
            doubleVars[1]=parameterStep[0]*parameterStep[0]+parameterStep[1]*parameterStep[1]+parameterStep[2]*parameterStep[2]+parameterStep[3]*parameterStep[3]+parameterStep[4]*parameterStep[4]+parameterStep[5]*parameterStep[5];
            
            if (doubleVars[0]>1.0e-36 && doubleVars[1]>1.0e-36){
                
                doubleVars[21]=0.5*sqrt(doubleVars[1]/doubleVars[0]);
                
            }
            else {
                
                /* Some security */
                if (i>1){
                    
                    doubleVars[23]=(doubleVars[21]*doubleVars[21])*doubleVars[0];
                    
                    if (doubleVars[23]>doubleVars[22]){
                        doubleVars[21]=-0.5*doubleVars[21]*sqrt(doubleVars[22]/doubleVars[23]);
                    }
                    else {
                        doubleVars[21]=-0.5*doubleVars[21];
                    }
                    
                }
                else {
                    
                    doubleVars[21]=-0.5*doubleVars[21];
                    
                }
                
                
            }
            
            /* Update the parameter step and terminate */
            
            parameterStep[0]+=doubleVars[21]*doubleVars[12];
            parameterStep[1]+=doubleVars[21]*doubleVars[13];
            parameterStep[2]+=doubleVars[21]*doubleVars[14];
            parameterStep[3]+=doubleVars[21]*doubleVars[15];
            parameterStep[4]+=doubleVars[21]*doubleVars[16];
            parameterStep[5]+=doubleVars[21]*doubleVars[17];
            
            doubleVars[12]=parameterStep[0]-parameterStart[0];
            doubleVars[13]=parameterStep[1]-parameterStart[1];
            doubleVars[14]=parameterStep[2]-parameterStart[2];
            doubleVars[15]=parameterStep[3]-parameterStart[3];
            doubleVars[16]=parameterStep[4]-parameterStart[4];
            doubleVars[17]=parameterStep[5]-parameterStart[5];
            
            parameterStep[0]=parameterStart[0]+0.75*doubleVars[12];
            parameterStep[1]=parameterStart[1]+0.75*doubleVars[13];
            parameterStep[2]=parameterStart[2]+0.75*doubleVars[14];
            parameterStep[3]=parameterStart[3]+0.75*doubleVars[15];
            parameterStep[4]=parameterStart[4]+0.75*doubleVars[16];
            parameterStep[5]=parameterStart[5]+0.75*doubleVars[17];
            
            return;
            
        }
        
    }
    
}

static void ordinaryCGM(double *A, double *b, double *x, double *doubleVars){
    
    /* Solves A*x=b, A 6x6 spd matrix */
    
    /* Required length of doubleVars 22 */
    
    unsigned char i;
    
    /* Initiate x to zero */
    x[0]=0.0;
    x[1]=0.0;
    x[2]=0.0;
    x[3]=0.0;
    x[4]=0.0;
    x[5]=0.0;
    
    /* residual=b */
    doubleVars[6]=b[0];
    doubleVars[7]=b[1];
    doubleVars[8]=b[2];
    doubleVars[9]=b[3];
    doubleVars[10]=b[4];
    doubleVars[11]=b[5];
    
    /* p=residual */
    doubleVars[12]=doubleVars[6];
    doubleVars[13]=doubleVars[7];
    doubleVars[14]=doubleVars[8];
    doubleVars[15]=doubleVars[9];
    doubleVars[16]=doubleVars[10];
    doubleVars[17]=doubleVars[11];
    
    /* Squared 2-norm of initial residual */
    doubleVars[18]=doubleVars[6]*doubleVars[6]+doubleVars[7]*doubleVars[7]+doubleVars[8]*doubleVars[8]+doubleVars[9]*doubleVars[9]+doubleVars[10]*doubleVars[10]+doubleVars[11]*doubleVars[11];
    doubleVars[19]=doubleVars[18];
    
    if (doubleVars[19]<1e-50){
        return;
    }
    
    for (i=0;i<12;i++){
        
        /* Compute matrix-vector product */
        sym6x6MatVecMult(A,&doubleVars[12],doubleVars);
        
        /* alpha */
        
        doubleVars[21]=doubleVars[0]*doubleVars[12]+doubleVars[1]*doubleVars[13]+doubleVars[2]*doubleVars[14]+doubleVars[3]*doubleVars[15]+doubleVars[4]*doubleVars[16]+doubleVars[5]*doubleVars[17];
        
        if (doubleVars[19]>1e20*doubleVars[21]){
            return;
        }
        
        doubleVars[21]=doubleVars[19]/doubleVars[21];
        
        /* Update the parameter step */
        x[0]+=doubleVars[21]*doubleVars[12];
        x[1]+=doubleVars[21]*doubleVars[13];
        x[2]+=doubleVars[21]*doubleVars[14];
        x[3]+=doubleVars[21]*doubleVars[15];
        x[4]+=doubleVars[21]*doubleVars[16];
        x[5]+=doubleVars[21]*doubleVars[17];
        
        /* Update residual */
        doubleVars[6]-=doubleVars[21]*doubleVars[0];
        doubleVars[7]-=doubleVars[21]*doubleVars[1];
        doubleVars[8]-=doubleVars[21]*doubleVars[2];
        doubleVars[9]-=doubleVars[21]*doubleVars[3];
        doubleVars[10]-=doubleVars[21]*doubleVars[4];
        doubleVars[11]-=doubleVars[21]*doubleVars[5];
        
        /* Squared 2-norm of residual */
        doubleVars[20]=doubleVars[6]*doubleVars[6]+doubleVars[7]*doubleVars[7]+doubleVars[8]*doubleVars[8]+doubleVars[9]*doubleVars[9]+doubleVars[10]*doubleVars[10]+doubleVars[11]*doubleVars[11];
        
        /* Terminate if the solution is sufficiently good */
        if (doubleVars[20]<doubleVars[18]*1e-30){
            return;
        }
        
        /* Update p */
        doubleVars[21]=doubleVars[20]/doubleVars[19];
        doubleVars[12]=doubleVars[6]+doubleVars[21]*doubleVars[12];
        doubleVars[13]=doubleVars[7]+doubleVars[21]*doubleVars[13];
        doubleVars[14]=doubleVars[8]+doubleVars[21]*doubleVars[14];
        doubleVars[15]=doubleVars[9]+doubleVars[21]*doubleVars[15];
        doubleVars[16]=doubleVars[10]+doubleVars[21]*doubleVars[16];
        doubleVars[17]=doubleVars[11]+doubleVars[21]*doubleVars[17];
        
        /* Update old residual */
        doubleVars[19]=doubleVars[20];
        
    }
    
}
