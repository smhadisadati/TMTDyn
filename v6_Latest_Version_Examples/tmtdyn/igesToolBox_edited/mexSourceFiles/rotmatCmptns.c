
/* Written by Per Bergström */

static void getRotMat(double *anglVec, double *rotMatrxs, double *doubleVars){
    /* Required length of rotMatrxs 9 */
    /* Required length of doubleVars 7 */
    
    /* Sine and cosine of the angles */
    doubleVars[0]=sin(anglVec[0]);
    doubleVars[1]=sin(anglVec[1]);
    doubleVars[2]=sin(anglVec[2]);
    doubleVars[3]=cos(anglVec[0]);
    doubleVars[4]=cos(anglVec[1]);
    doubleVars[5]=cos(anglVec[2]);
    
    
    /* Rotation matrix */
    rotMatrxs[0]=doubleVars[4]*doubleVars[5];
    rotMatrxs[1]=doubleVars[4]*doubleVars[2];
    rotMatrxs[2]=-doubleVars[1];
    
    doubleVars[6]=doubleVars[0]*doubleVars[1];
    rotMatrxs[3]=doubleVars[6]*doubleVars[5]-doubleVars[3]*doubleVars[2];
    rotMatrxs[4]=doubleVars[6]*doubleVars[2]+doubleVars[3]*doubleVars[5];
    rotMatrxs[5]=doubleVars[0]*doubleVars[4];
    
    doubleVars[6]=doubleVars[3]*doubleVars[1];
    rotMatrxs[6]=doubleVars[6]*doubleVars[5]+doubleVars[0]*doubleVars[2];
    rotMatrxs[7]=doubleVars[6]*doubleVars[2]-doubleVars[0]*doubleVars[5];
    rotMatrxs[8]=doubleVars[3]*doubleVars[4];
    
}

static void getRotMatD2(double *anglVec, double *rotMatrxs, double *doubleVars){
    /* Required length of rotMatrxs 18 */
    /* Required length of doubleVars 8 */
    
    /* Sine and cosine of the angles */
    doubleVars[0]=sin(anglVec[0]);
    doubleVars[1]=sin(anglVec[1]);
    doubleVars[2]=sin(anglVec[2]);
    doubleVars[3]=cos(anglVec[0]);
    doubleVars[4]=cos(anglVec[1]);
    doubleVars[5]=cos(anglVec[2]);
    
    
    /* Rotation matrix */
    rotMatrxs[0]=doubleVars[4]*doubleVars[5];
    rotMatrxs[1]=doubleVars[4]*doubleVars[2];
    rotMatrxs[2]=-doubleVars[1];
    
    doubleVars[6]=doubleVars[0]*doubleVars[1];
    rotMatrxs[3]=doubleVars[6]*doubleVars[5]-doubleVars[3]*doubleVars[2];
    rotMatrxs[4]=doubleVars[6]*doubleVars[2]+doubleVars[3]*doubleVars[5];
    rotMatrxs[5]=doubleVars[0]*doubleVars[4];
    
    doubleVars[7]=doubleVars[3]*doubleVars[1];
    rotMatrxs[6]=doubleVars[7]*doubleVars[5]+doubleVars[0]*doubleVars[2];
    rotMatrxs[7]=doubleVars[7]*doubleVars[2]-doubleVars[0]*doubleVars[5];
    rotMatrxs[8]=doubleVars[3]*doubleVars[4];
    
    
    /* Derivative 2 of rotation matrix */
    rotMatrxs[9]=-doubleVars[1]*doubleVars[5];
    rotMatrxs[10]=-doubleVars[1]*doubleVars[2];
    rotMatrxs[11]=-doubleVars[4];
    
    rotMatrxs[14]=-doubleVars[6];
    doubleVars[6]=rotMatrxs[5];
    rotMatrxs[12]=doubleVars[6]*doubleVars[5];
    rotMatrxs[13]=doubleVars[6]*doubleVars[2];
    
    rotMatrxs[15]=rotMatrxs[8]*doubleVars[5];
    rotMatrxs[16]=rotMatrxs[8]*doubleVars[2];
    rotMatrxs[17]=-doubleVars[7];
    
}

static void getRotMatD2D22(double *anglVec, double *rotMatrxs, double *doubleVars){
    /* Required length of rotMatrxs 27 */
    /* Required length of doubleVars 8 */
    
    /* Sine and cosine of the angles */
    doubleVars[0]=sin(anglVec[0]);
    doubleVars[1]=sin(anglVec[1]);
    doubleVars[2]=sin(anglVec[2]);
    doubleVars[3]=cos(anglVec[0]);
    doubleVars[4]=cos(anglVec[1]);
    doubleVars[5]=cos(anglVec[2]);
    
    
    /* Rotation matrix */
    rotMatrxs[0]=doubleVars[4]*doubleVars[5];
    rotMatrxs[1]=doubleVars[4]*doubleVars[2];
    rotMatrxs[2]=-doubleVars[1];
    
    doubleVars[6]=doubleVars[0]*doubleVars[1];
    rotMatrxs[3]=doubleVars[6]*doubleVars[5]-doubleVars[3]*doubleVars[2];
    rotMatrxs[4]=doubleVars[6]*doubleVars[2]+doubleVars[3]*doubleVars[5];
    rotMatrxs[5]=doubleVars[0]*doubleVars[4];
    
    doubleVars[7]=doubleVars[3]*doubleVars[1];
    rotMatrxs[6]=doubleVars[7]*doubleVars[5];
    rotMatrxs[7]=doubleVars[7]*doubleVars[2];
    rotMatrxs[8]=doubleVars[3]*doubleVars[4];
    
    
    /* Derivative 2 of rotation matrix */
    rotMatrxs[9]=-doubleVars[1]*doubleVars[5];
    rotMatrxs[10]=-doubleVars[1]*doubleVars[2];
    rotMatrxs[11]=-doubleVars[4];
    
    rotMatrxs[14]=-doubleVars[6];
    doubleVars[6]=rotMatrxs[5];
    rotMatrxs[12]=doubleVars[6]*doubleVars[5];
    rotMatrxs[13]=doubleVars[6]*doubleVars[2];
    
    rotMatrxs[15]=rotMatrxs[8]*doubleVars[5];
    rotMatrxs[16]=rotMatrxs[8]*doubleVars[2];
    rotMatrxs[17]=-doubleVars[7];
    
    
    /* Second derivative 22 of rotation matrix */
    rotMatrxs[18]=-rotMatrxs[0];
    rotMatrxs[19]=-rotMatrxs[1];
    rotMatrxs[20]=doubleVars[1];
    
    rotMatrxs[21]=doubleVars[0]*rotMatrxs[9];
    rotMatrxs[22]=doubleVars[0]*rotMatrxs[10];
    rotMatrxs[23]=-rotMatrxs[5];
    
    rotMatrxs[24]=-rotMatrxs[6];
    rotMatrxs[25]=-rotMatrxs[7];
    rotMatrxs[26]=-rotMatrxs[8];
    
    /* Rotation matrix again */
    rotMatrxs[6]+=doubleVars[0]*doubleVars[2];
    rotMatrxs[7]-=doubleVars[0]*doubleVars[5];
    
}

static void getAngles(double *anglVec, double *rotMatrxs, double *doubleVars){
    /* Required length of doubleVars 0 */
    
    /* Ref: Gregory G. Slabaugh, Computing Euler angles from a rotation matrix */
    
    anglVec[1]=-asin(rotMatrxs[2]);
    
    if ((1.0-rotMatrxs[2]*rotMatrxs[2])>1e-15){
        
        anglVec[0]=atan2(rotMatrxs[5],rotMatrxs[8]);
        anglVec[2]=atan2(rotMatrxs[1],rotMatrxs[0]);
        
    }
    else {
        
        if (anglVec[1]>0.0){
            anglVec[0]=atan2(rotMatrxs[3],rotMatrxs[6]);
        }
        else {
            anglVec[0]=atan2(-rotMatrxs[3],-rotMatrxs[6]);
        }
        
        anglVec[2]=0.0;
        
    }
    
}
