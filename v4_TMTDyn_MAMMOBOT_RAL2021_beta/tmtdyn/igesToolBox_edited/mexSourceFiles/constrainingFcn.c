
/* Written by Per Bergström */

static void constrainingFcnZero(double *constrFcnMatrxs, double *quasum, double *datam, double *modelm, double *Spx, double *doubleVars){
    /* Required length of constrFcnMatrxs 1 */
    /* Required length of doubleVars 0 */
    
    /* Compute function value */
    constrFcnMatrxs[0]=quasum[0]*(pwr2(datam[0]-modelm[0])+pwr2(datam[1]-modelm[1])+pwr2(datam[2]-modelm[2]))-2.0*(Spx[0]+Spx[4]+Spx[8]);
    
}

static void constrainingFcn(double *constrFcnMatrxs, double *zParameters, double *quasum, double *datam, double *modelm, double *Spx, double *doubleVars){
    /* Required length of constrFcnMatrxs 1 */
    /* Required length of doubleVars 16 */
    
    /* Compute rotation matrix */
    getRotMat(zParameters,doubleVars,&doubleVars[9]);
    
    /* Compute function value */
    constrFcnMatrxs[0]=quasum[0]*(pwr2(doubleVars[0]*datam[0]+doubleVars[3]*datam[1]+doubleVars[6]*datam[2]+zParameters[3]-modelm[0])+pwr2(doubleVars[1]*datam[0]+doubleVars[4]*datam[1]+doubleVars[7]*datam[2]+zParameters[4]-modelm[1])+pwr2(doubleVars[2]*datam[0]+doubleVars[5]*datam[1]+doubleVars[8]*datam[2]+zParameters[5]-modelm[2]))-2.0*(doubleVars[0]*Spx[0]+doubleVars[1]*Spx[1]+doubleVars[2]*Spx[2]+doubleVars[3]*Spx[3]+doubleVars[4]*Spx[4]+doubleVars[5]*Spx[5]+doubleVars[6]*Spx[6]+doubleVars[7]*Spx[7]+doubleVars[8]*Spx[8]);
    
}

static void constrainingFcnGrad(double *constrFcnMatrxs, double *zParameters, double *quasum, double *datam, double *modelm, double *Spx, double *doubleVars){
    /* Required length of constrFcnMatrxs 7 */
    /* Required length of doubleVars 37 */
    
    /* Compute rotation matrix and derivative */
    getRotMatD2(zParameters,doubleVars,&doubleVars[18]);
    
    /* Compute more things */
    doubleVars[18]=2.0*quasum[0];
    doubleVars[19]=zParameters[3]-modelm[0];
    doubleVars[20]=zParameters[4]-modelm[1];
    doubleVars[21]=zParameters[5]-modelm[2];
    doubleVars[22]=doubleVars[0]*datam[0]+doubleVars[3]*datam[1]+doubleVars[6]*datam[2]+doubleVars[19];
    doubleVars[23]=doubleVars[1]*datam[0]+doubleVars[4]*datam[1]+doubleVars[7]*datam[2]+doubleVars[20];
    doubleVars[24]=doubleVars[2]*datam[0]+doubleVars[5]*datam[1]+doubleVars[8]*datam[2]+doubleVars[21];
    doubleVars[25]=quasum[0]*datam[0];
    doubleVars[26]=quasum[0]*datam[1];
    doubleVars[27]=quasum[0]*datam[2];
    doubleVars[28]=doubleVars[25]*doubleVars[19]-Spx[0];
    doubleVars[29]=doubleVars[25]*doubleVars[20]-Spx[1];
    doubleVars[30]=doubleVars[25]*doubleVars[21]-Spx[2];
    doubleVars[31]=doubleVars[26]*doubleVars[19]-Spx[3];
    doubleVars[32]=doubleVars[26]*doubleVars[20]-Spx[4];
    doubleVars[33]=doubleVars[26]*doubleVars[21]-Spx[5];
    doubleVars[34]=doubleVars[27]*doubleVars[19]-Spx[6];
    doubleVars[35]=doubleVars[27]*doubleVars[20]-Spx[7];
    doubleVars[36]=doubleVars[27]*doubleVars[21]-Spx[8];
    
    /* Compute function value */
    constrFcnMatrxs[0]=quasum[0]*(pwr2(doubleVars[22])+pwr2(doubleVars[23])+pwr2(doubleVars[24]))-2.0*(doubleVars[0]*Spx[0]+doubleVars[1]*Spx[1]+doubleVars[2]*Spx[2]+doubleVars[3]*Spx[3]+doubleVars[4]*Spx[4]+doubleVars[5]*Spx[5]+doubleVars[6]*Spx[6]+doubleVars[7]*Spx[7]+doubleVars[8]*Spx[8]);
    
    /* Compute gradient */
    constrFcnMatrxs[1]=2.0*(doubleVars[6]*doubleVars[31]+doubleVars[7]*doubleVars[32]+doubleVars[8]*doubleVars[33]-(doubleVars[3]*doubleVars[34]+doubleVars[4]*doubleVars[35]+doubleVars[5]*doubleVars[36]));
    constrFcnMatrxs[2]=2.0*(doubleVars[9]*doubleVars[28]+doubleVars[10]*doubleVars[29]+doubleVars[11]*doubleVars[30]+doubleVars[12]*doubleVars[31]+doubleVars[13]*doubleVars[32]+doubleVars[14]*doubleVars[33]+doubleVars[15]*doubleVars[34]+doubleVars[16]*doubleVars[35]+doubleVars[17]*doubleVars[36]);
    constrFcnMatrxs[3]=2.0*(doubleVars[0]*doubleVars[29]+doubleVars[3]*doubleVars[32]+doubleVars[6]*doubleVars[35]-(doubleVars[1]*doubleVars[28]+doubleVars[4]*doubleVars[31]+doubleVars[7]*doubleVars[34]));
    
    constrFcnMatrxs[4]=doubleVars[18]*doubleVars[22];
    constrFcnMatrxs[5]=doubleVars[18]*doubleVars[23];
    constrFcnMatrxs[6]=doubleVars[18]*doubleVars[24];
    
}

static void constrainingFcnGradHess(double *constrFcnMatrxs, double *zParameters, double *quasum, double *datam, double *modelm, double *Spx, double *doubleVars){
    /* Required length of constrFcnMatrxs 28 */
    /* Required length of doubleVars 46 */
    
    /* Compute rotation matrix and derivatives */
    getRotMatD2D22(zParameters,doubleVars,&doubleVars[27]);
    
    /* Compute more things */
    doubleVars[27]=2.0*quasum[0];
    doubleVars[28]=zParameters[3]-modelm[0];
    doubleVars[29]=zParameters[4]-modelm[1];
    doubleVars[30]=zParameters[5]-modelm[2];
    doubleVars[31]=doubleVars[0]*datam[0]+doubleVars[3]*datam[1]+doubleVars[6]*datam[2]+doubleVars[28];
    doubleVars[32]=doubleVars[1]*datam[0]+doubleVars[4]*datam[1]+doubleVars[7]*datam[2]+doubleVars[29];
    doubleVars[33]=doubleVars[2]*datam[0]+doubleVars[5]*datam[1]+doubleVars[8]*datam[2]+doubleVars[30];
    doubleVars[34]=quasum[0]*datam[0];
    doubleVars[35]=quasum[0]*datam[1];
    doubleVars[36]=quasum[0]*datam[2];
    doubleVars[37]=doubleVars[34]*doubleVars[28]-Spx[0];
    doubleVars[38]=doubleVars[34]*doubleVars[29]-Spx[1];
    doubleVars[39]=doubleVars[34]*doubleVars[30]-Spx[2];
    doubleVars[40]=doubleVars[35]*doubleVars[28]-Spx[3];
    doubleVars[41]=doubleVars[35]*doubleVars[29]-Spx[4];
    doubleVars[42]=doubleVars[35]*doubleVars[30]-Spx[5];
    doubleVars[43]=doubleVars[36]*doubleVars[28]-Spx[6];
    doubleVars[44]=doubleVars[36]*doubleVars[29]-Spx[7];
    doubleVars[45]=doubleVars[36]*doubleVars[30]-Spx[8];
    
    /* Compute function value */
    constrFcnMatrxs[0]=quasum[0]*(pwr2(doubleVars[31])+pwr2(doubleVars[32])+pwr2(doubleVars[33]))-2.0*(doubleVars[0]*Spx[0]+doubleVars[1]*Spx[1]+doubleVars[2]*Spx[2]+doubleVars[3]*Spx[3]+doubleVars[4]*Spx[4]+doubleVars[5]*Spx[5]+doubleVars[6]*Spx[6]+doubleVars[7]*Spx[7]+doubleVars[8]*Spx[8]);
    
    /* Compute gradient */
    constrFcnMatrxs[1]=2.0*(doubleVars[6]*doubleVars[40]+doubleVars[7]*doubleVars[41]+doubleVars[8]*doubleVars[42]-(doubleVars[3]*doubleVars[43]+doubleVars[4]*doubleVars[44]+doubleVars[5]*doubleVars[45]));
    constrFcnMatrxs[2]=2.0*(doubleVars[9]*doubleVars[37]+doubleVars[10]*doubleVars[38]+doubleVars[11]*doubleVars[39]+doubleVars[12]*doubleVars[40]+doubleVars[13]*doubleVars[41]+doubleVars[14]*doubleVars[42]+doubleVars[15]*doubleVars[43]+doubleVars[16]*doubleVars[44]+doubleVars[17]*doubleVars[45]);
    constrFcnMatrxs[3]=2.0*(doubleVars[0]*doubleVars[38]+doubleVars[3]*doubleVars[41]+doubleVars[6]*doubleVars[44]-(doubleVars[1]*doubleVars[37]+doubleVars[4]*doubleVars[40]+doubleVars[7]*doubleVars[43]));
    
    constrFcnMatrxs[4]=doubleVars[27]*doubleVars[31];
    constrFcnMatrxs[5]=doubleVars[27]*doubleVars[32];
    constrFcnMatrxs[6]=doubleVars[27]*doubleVars[33];
    
    /* Compute Hessian */
    constrFcnMatrxs[7]=-2.0*(doubleVars[3]*doubleVars[40]+doubleVars[4]*doubleVars[41]+doubleVars[5]*doubleVars[42]+doubleVars[6]*doubleVars[43]+doubleVars[7]*doubleVars[44]+doubleVars[8]*doubleVars[45]);
    constrFcnMatrxs[8]=2.0*(doubleVars[15]*doubleVars[40]+doubleVars[16]*doubleVars[41]+doubleVars[17]*doubleVars[42]-(doubleVars[12]*doubleVars[43]+doubleVars[13]*doubleVars[44]+doubleVars[14]*doubleVars[45]));
    constrFcnMatrxs[9]=2.0*(doubleVars[6]*doubleVars[41]+doubleVars[4]*doubleVars[43]-(doubleVars[7]*doubleVars[40]+doubleVars[3]*doubleVars[44]));
    constrFcnMatrxs[10]=doubleVars[27]*(doubleVars[6]*datam[1]-doubleVars[3]*datam[2]);
    constrFcnMatrxs[11]=doubleVars[27]*(doubleVars[7]*datam[1]-doubleVars[4]*datam[2]);
    constrFcnMatrxs[12]=doubleVars[27]*(doubleVars[8]*datam[1]-doubleVars[5]*datam[2]);
    constrFcnMatrxs[13]=2.0*(doubleVars[18]*doubleVars[37]+doubleVars[19]*doubleVars[38]+doubleVars[20]*doubleVars[39]+doubleVars[21]*doubleVars[40]+doubleVars[22]*doubleVars[41]+doubleVars[23]*doubleVars[42]+doubleVars[24]*doubleVars[43]+doubleVars[25]*doubleVars[44]+doubleVars[26]*doubleVars[45]);
    constrFcnMatrxs[14]=2.0*(doubleVars[9]*doubleVars[38]+doubleVars[12]*doubleVars[41]+doubleVars[15]*doubleVars[44]-(doubleVars[10]*doubleVars[37]+doubleVars[13]*doubleVars[40]+doubleVars[16]*doubleVars[43]));
    constrFcnMatrxs[15]=doubleVars[27]*(doubleVars[9]*datam[0]+doubleVars[12]*datam[1]+doubleVars[15]*datam[2]);
    constrFcnMatrxs[16]=doubleVars[27]*(doubleVars[10]*datam[0]+doubleVars[13]*datam[1]+doubleVars[16]*datam[2]);
    constrFcnMatrxs[17]=doubleVars[27]*(doubleVars[11]*datam[0]+doubleVars[14]*datam[1]+doubleVars[17]*datam[2]);
    constrFcnMatrxs[18]=-2.0*(doubleVars[0]*doubleVars[37]+doubleVars[1]*doubleVars[38]+doubleVars[3]*doubleVars[40]+doubleVars[4]*doubleVars[41]+doubleVars[6]*doubleVars[43]+doubleVars[7]*doubleVars[44]);
    constrFcnMatrxs[19]=-doubleVars[27]*(doubleVars[1]*datam[0]+doubleVars[4]*datam[1]+doubleVars[7]*datam[2]);
    constrFcnMatrxs[20]=doubleVars[27]*(doubleVars[0]*datam[0]+doubleVars[3]*datam[1]+doubleVars[6]*datam[2]);
    constrFcnMatrxs[21]=0.0;
    constrFcnMatrxs[22]=doubleVars[27];
    constrFcnMatrxs[23]=0.0;
    constrFcnMatrxs[24]=0.0;
    constrFcnMatrxs[25]=doubleVars[27];
    constrFcnMatrxs[26]=0.0;
    constrFcnMatrxs[27]=doubleVars[27];
    
}

static void constrainingFcnGradHessNotF(double *constrFcnMatrxs, double *zParameters, double *quasum, double *datam, double *modelm, double *Spx, double *doubleVars){
    /* Required length of constrFcnMatrxs 28 */
    /* Required length of doubleVars 46 */
    
    /* Compute rotation matrix and derivatives */
    getRotMatD2D22(zParameters,doubleVars,&doubleVars[27]);
    
    /* Compute more things */
    doubleVars[27]=2.0*quasum[0];
    doubleVars[28]=zParameters[3]-modelm[0];
    doubleVars[29]=zParameters[4]-modelm[1];
    doubleVars[30]=zParameters[5]-modelm[2];
    doubleVars[31]=doubleVars[0]*datam[0]+doubleVars[3]*datam[1]+doubleVars[6]*datam[2]+doubleVars[28];
    doubleVars[32]=doubleVars[1]*datam[0]+doubleVars[4]*datam[1]+doubleVars[7]*datam[2]+doubleVars[29];
    doubleVars[33]=doubleVars[2]*datam[0]+doubleVars[5]*datam[1]+doubleVars[8]*datam[2]+doubleVars[30];
    doubleVars[34]=quasum[0]*datam[0];
    doubleVars[35]=quasum[0]*datam[1];
    doubleVars[36]=quasum[0]*datam[2];
    doubleVars[37]=doubleVars[34]*doubleVars[28]-Spx[0];
    doubleVars[38]=doubleVars[34]*doubleVars[29]-Spx[1];
    doubleVars[39]=doubleVars[34]*doubleVars[30]-Spx[2];
    doubleVars[40]=doubleVars[35]*doubleVars[28]-Spx[3];
    doubleVars[41]=doubleVars[35]*doubleVars[29]-Spx[4];
    doubleVars[42]=doubleVars[35]*doubleVars[30]-Spx[5];
    doubleVars[43]=doubleVars[36]*doubleVars[28]-Spx[6];
    doubleVars[44]=doubleVars[36]*doubleVars[29]-Spx[7];
    doubleVars[45]=doubleVars[36]*doubleVars[30]-Spx[8];
    
    /* Compute gradient */
    constrFcnMatrxs[1]=2.0*(doubleVars[6]*doubleVars[40]+doubleVars[7]*doubleVars[41]+doubleVars[8]*doubleVars[42]-(doubleVars[3]*doubleVars[43]+doubleVars[4]*doubleVars[44]+doubleVars[5]*doubleVars[45]));
    constrFcnMatrxs[2]=2.0*(doubleVars[9]*doubleVars[37]+doubleVars[10]*doubleVars[38]+doubleVars[11]*doubleVars[39]+doubleVars[12]*doubleVars[40]+doubleVars[13]*doubleVars[41]+doubleVars[14]*doubleVars[42]+doubleVars[15]*doubleVars[43]+doubleVars[16]*doubleVars[44]+doubleVars[17]*doubleVars[45]);
    constrFcnMatrxs[3]=2.0*(doubleVars[0]*doubleVars[38]+doubleVars[3]*doubleVars[41]+doubleVars[6]*doubleVars[44]-(doubleVars[1]*doubleVars[37]+doubleVars[4]*doubleVars[40]+doubleVars[7]*doubleVars[43]));
    
    constrFcnMatrxs[4]=doubleVars[27]*doubleVars[31];
    constrFcnMatrxs[5]=doubleVars[27]*doubleVars[32];
    constrFcnMatrxs[6]=doubleVars[27]*doubleVars[33];
    
    /* Compute Hessian */
    constrFcnMatrxs[7]=-2.0*(doubleVars[3]*doubleVars[40]+doubleVars[4]*doubleVars[41]+doubleVars[5]*doubleVars[42]+doubleVars[6]*doubleVars[43]+doubleVars[7]*doubleVars[44]+doubleVars[8]*doubleVars[45]);
    constrFcnMatrxs[8]=2.0*(doubleVars[15]*doubleVars[40]+doubleVars[16]*doubleVars[41]+doubleVars[17]*doubleVars[42]-(doubleVars[12]*doubleVars[43]+doubleVars[13]*doubleVars[44]+doubleVars[14]*doubleVars[45]));
    constrFcnMatrxs[9]=2.0*(doubleVars[6]*doubleVars[41]+doubleVars[4]*doubleVars[43]-(doubleVars[7]*doubleVars[40]+doubleVars[3]*doubleVars[44]));
    constrFcnMatrxs[10]=doubleVars[27]*(doubleVars[6]*datam[1]-doubleVars[3]*datam[2]);
    constrFcnMatrxs[11]=doubleVars[27]*(doubleVars[7]*datam[1]-doubleVars[4]*datam[2]);
    constrFcnMatrxs[12]=doubleVars[27]*(doubleVars[8]*datam[1]-doubleVars[5]*datam[2]);
    constrFcnMatrxs[13]=2.0*(doubleVars[18]*doubleVars[37]+doubleVars[19]*doubleVars[38]+doubleVars[20]*doubleVars[39]+doubleVars[21]*doubleVars[40]+doubleVars[22]*doubleVars[41]+doubleVars[23]*doubleVars[42]+doubleVars[24]*doubleVars[43]+doubleVars[25]*doubleVars[44]+doubleVars[26]*doubleVars[45]);
    constrFcnMatrxs[14]=2.0*(doubleVars[9]*doubleVars[38]+doubleVars[12]*doubleVars[41]+doubleVars[15]*doubleVars[44]-(doubleVars[10]*doubleVars[37]+doubleVars[13]*doubleVars[40]+doubleVars[16]*doubleVars[43]));
    constrFcnMatrxs[15]=doubleVars[27]*(doubleVars[9]*datam[0]+doubleVars[12]*datam[1]+doubleVars[15]*datam[2]);
    constrFcnMatrxs[16]=doubleVars[27]*(doubleVars[10]*datam[0]+doubleVars[13]*datam[1]+doubleVars[16]*datam[2]);
    constrFcnMatrxs[17]=doubleVars[27]*(doubleVars[11]*datam[0]+doubleVars[14]*datam[1]+doubleVars[17]*datam[2]);
    constrFcnMatrxs[18]=-2.0*(doubleVars[0]*doubleVars[37]+doubleVars[1]*doubleVars[38]+doubleVars[3]*doubleVars[40]+doubleVars[4]*doubleVars[41]+doubleVars[6]*doubleVars[43]+doubleVars[7]*doubleVars[44]);
    constrFcnMatrxs[19]=-doubleVars[27]*(doubleVars[1]*datam[0]+doubleVars[4]*datam[1]+doubleVars[7]*datam[2]);
    constrFcnMatrxs[20]=doubleVars[27]*(doubleVars[0]*datam[0]+doubleVars[3]*datam[1]+doubleVars[6]*datam[2]);
    constrFcnMatrxs[21]=0.0;
    constrFcnMatrxs[22]=doubleVars[27];
    constrFcnMatrxs[23]=0.0;
    constrFcnMatrxs[24]=0.0;
    constrFcnMatrxs[25]=doubleVars[27];
    constrFcnMatrxs[26]=0.0;
    constrFcnMatrxs[27]=doubleVars[27];
    
}
