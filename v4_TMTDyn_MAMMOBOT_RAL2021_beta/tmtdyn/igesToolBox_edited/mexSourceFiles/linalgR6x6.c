/**************************************************************************
 *
 * A simple linear algebra package used for finding a transformation in
 * the ICP algorithm
 *
 * Written by Per Bergström
 *
 **************************************************************************/

static void sym6x6MatVecMult(double *Mat, double *Vec, double *Prod){
    
    /* Symmetric 6x6 matrix-vector product */
    
    Prod[0]=Mat[0]*Vec[0]+Mat[1]*Vec[1]+Mat[2]*Vec[2]+Mat[3]*Vec[3]+Mat[4]*Vec[4]+Mat[5]*Vec[5];
    Prod[1]=Mat[1]*Vec[0]+Mat[6]*Vec[1]+Mat[7]*Vec[2]+Mat[8]*Vec[3]+Mat[9]*Vec[4]+Mat[10]*Vec[5];
    Prod[2]=Mat[2]*Vec[0]+Mat[7]*Vec[1]+Mat[11]*Vec[2]+Mat[12]*Vec[3]+Mat[13]*Vec[4]+Mat[14]*Vec[5];
    Prod[3]=Mat[3]*Vec[0]+Mat[8]*Vec[1]+Mat[12]*Vec[2]+Mat[15]*Vec[3]+Mat[16]*Vec[4]+Mat[17]*Vec[5];
    Prod[4]=Mat[4]*Vec[0]+Mat[9]*Vec[1]+Mat[13]*Vec[2]+Mat[16]*Vec[3]+Mat[18]*Vec[4]+Mat[19]*Vec[5];
    Prod[5]=Mat[5]*Vec[0]+Mat[10]*Vec[1]+Mat[14]*Vec[2]+Mat[17]*Vec[3]+Mat[19]*Vec[4]+Mat[20]*Vec[5];
    
}

static void sym6x6MatVecMultVecAdd(double *Mat, double *VecMlt, double *VecAdd, double *ProdSum){
    
    /* Symmetric 6x6 matrix-vector product and vector addition */
    
    ProdSum[0]=Mat[0]*VecMlt[0]+Mat[1]*VecMlt[1]+Mat[2]*VecMlt[2]+Mat[3]*VecMlt[3]+Mat[4]*VecMlt[4]+Mat[5]*VecMlt[5]+VecAdd[0];
    ProdSum[1]=Mat[1]*VecMlt[0]+Mat[6]*VecMlt[1]+Mat[7]*VecMlt[2]+Mat[8]*VecMlt[3]+Mat[9]*VecMlt[4]+Mat[10]*VecMlt[5]+VecAdd[1];
    ProdSum[2]=Mat[2]*VecMlt[0]+Mat[7]*VecMlt[1]+Mat[11]*VecMlt[2]+Mat[12]*VecMlt[3]+Mat[13]*VecMlt[4]+Mat[14]*VecMlt[5]+VecAdd[2];
    ProdSum[3]=Mat[3]*VecMlt[0]+Mat[8]*VecMlt[1]+Mat[12]*VecMlt[2]+Mat[15]*VecMlt[3]+Mat[16]*VecMlt[4]+Mat[17]*VecMlt[5]+VecAdd[3];
    ProdSum[4]=Mat[4]*VecMlt[0]+Mat[9]*VecMlt[1]+Mat[13]*VecMlt[2]+Mat[16]*VecMlt[3]+Mat[18]*VecMlt[4]+Mat[19]*VecMlt[5]+VecAdd[4];
    ProdSum[5]=Mat[5]*VecMlt[0]+Mat[10]*VecMlt[1]+Mat[14]*VecMlt[2]+Mat[17]*VecMlt[3]+Mat[19]*VecMlt[4]+Mat[20]*VecMlt[5]+VecAdd[5];
    
}

static void negSym6x6MatVecMultVecAdd(double *Mat, double *VecMlt, double *VecAdd, double *ProdSum){
    
    /* Negative symmetric 6x6 matrix-vector product and vector addition */
    
    ProdSum[0]=-(Mat[0]*VecMlt[0]+Mat[1]*VecMlt[1]+Mat[2]*VecMlt[2]+Mat[3]*VecMlt[3]+Mat[4]*VecMlt[4]+Mat[5]*VecMlt[5]+VecAdd[0]);
    ProdSum[1]=-(Mat[1]*VecMlt[0]+Mat[6]*VecMlt[1]+Mat[7]*VecMlt[2]+Mat[8]*VecMlt[3]+Mat[9]*VecMlt[4]+Mat[10]*VecMlt[5]+VecAdd[1]);
    ProdSum[2]=-(Mat[2]*VecMlt[0]+Mat[7]*VecMlt[1]+Mat[11]*VecMlt[2]+Mat[12]*VecMlt[3]+Mat[13]*VecMlt[4]+Mat[14]*VecMlt[5]+VecAdd[2]);
    ProdSum[3]=-(Mat[3]*VecMlt[0]+Mat[8]*VecMlt[1]+Mat[12]*VecMlt[2]+Mat[15]*VecMlt[3]+Mat[16]*VecMlt[4]+Mat[17]*VecMlt[5]+VecAdd[3]);
    ProdSum[4]=-(Mat[4]*VecMlt[0]+Mat[9]*VecMlt[1]+Mat[13]*VecMlt[2]+Mat[16]*VecMlt[3]+Mat[18]*VecMlt[4]+Mat[19]*VecMlt[5]+VecAdd[4]);
    ProdSum[5]=-(Mat[5]*VecMlt[0]+Mat[10]*VecMlt[1]+Mat[14]*VecMlt[2]+Mat[17]*VecMlt[3]+Mat[19]*VecMlt[4]+Mat[20]*VecMlt[5]+VecAdd[5]);
    
}

double sym6x6MatVecInnrProd(double *Mat, double *Vec){
    
    /* Symmetric 6x6 matrix vector inner product, x'*A*x */
    
    return (Mat[0]*Vec[0]+Mat[1]*Vec[1]+Mat[2]*Vec[2]+Mat[3]*Vec[3]+Mat[4]*Vec[4]+Mat[5]*Vec[5])*Vec[0]+(Mat[1]*Vec[0]+Mat[6]*Vec[1]+Mat[7]*Vec[2]+Mat[8]*Vec[3]+Mat[9]*Vec[4]+Mat[10]*Vec[5])*Vec[1]+(Mat[2]*Vec[0]+Mat[7]*Vec[1]+Mat[11]*Vec[2]+Mat[12]*Vec[3]+Mat[13]*Vec[4]+Mat[14]*Vec[5])*Vec[2]+(Mat[3]*Vec[0]+Mat[8]*Vec[1]+Mat[12]*Vec[2]+Mat[15]*Vec[3]+Mat[16]*Vec[4]+Mat[17]*Vec[5])*Vec[3]+(Mat[4]*Vec[0]+Mat[9]*Vec[1]+Mat[13]*Vec[2]+Mat[16]*Vec[3]+Mat[18]*Vec[4]+Mat[19]*Vec[5])*Vec[4]+(Mat[5]*Vec[0]+Mat[10]*Vec[1]+Mat[14]*Vec[2]+Mat[17]*Vec[3]+Mat[19]*Vec[4]+Mat[20]*Vec[5])*Vec[5];
    
}

double sym6x6MatVecInnrProdSum(double *Vecb, double *Mat, double *Vec){
    
    /* Symmetric 6x6 matrix vector inner product, b'*x+0.5*x'*A*x */
    
    return Vecb[0]*Vec[0]+Vecb[1]*Vec[1]+Vecb[2]*Vec[2]+Vecb[3]*Vec[3]+Vecb[4]*Vec[4]+Vecb[5]*Vec[5]+0.5*((Mat[0]*Vec[0]+Mat[1]*Vec[1]+Mat[2]*Vec[2]+Mat[3]*Vec[3]+Mat[4]*Vec[4]+Mat[5]*Vec[5])*Vec[0]+(Mat[1]*Vec[0]+Mat[6]*Vec[1]+Mat[7]*Vec[2]+Mat[8]*Vec[3]+Mat[9]*Vec[4]+Mat[10]*Vec[5])*Vec[1]+(Mat[2]*Vec[0]+Mat[7]*Vec[1]+Mat[11]*Vec[2]+Mat[12]*Vec[3]+Mat[13]*Vec[4]+Mat[14]*Vec[5])*Vec[2]+(Mat[3]*Vec[0]+Mat[8]*Vec[1]+Mat[12]*Vec[2]+Mat[15]*Vec[3]+Mat[16]*Vec[4]+Mat[17]*Vec[5])*Vec[3]+(Mat[4]*Vec[0]+Mat[9]*Vec[1]+Mat[13]*Vec[2]+Mat[16]*Vec[3]+Mat[18]*Vec[4]+Mat[19]*Vec[5])*Vec[4]+(Mat[5]*Vec[0]+Mat[10]*Vec[1]+Mat[14]*Vec[2]+Mat[17]*Vec[3]+Mat[19]*Vec[4]+Mat[20]*Vec[5])*Vec[5]);
    
}

static void sym6x6MatExpPenaltyOprtrs(double *constrFcnMatrxs, double *Mat, double *VecAdd, double *VecMlt, double *expTempVar, double *pnltyParamVal){
    
    /* Operator used in "findMinTrfExpPenalty" */
    
    /* Matrix update */
    constrFcnMatrxs[7]=Mat[0]+expTempVar[0]*(constrFcnMatrxs[1]*constrFcnMatrxs[1]+pnltyParamVal[0]*constrFcnMatrxs[7]);
    constrFcnMatrxs[8]=Mat[1]+expTempVar[0]*(constrFcnMatrxs[2]*constrFcnMatrxs[1]+pnltyParamVal[0]*constrFcnMatrxs[8]);
    constrFcnMatrxs[9]=Mat[2]+expTempVar[0]*(constrFcnMatrxs[3]*constrFcnMatrxs[1]+pnltyParamVal[0]*constrFcnMatrxs[9]);
    constrFcnMatrxs[10]=Mat[3]+expTempVar[0]*(constrFcnMatrxs[4]*constrFcnMatrxs[1]+pnltyParamVal[0]*constrFcnMatrxs[10]);
    constrFcnMatrxs[11]=Mat[4]+expTempVar[0]*(constrFcnMatrxs[5]*constrFcnMatrxs[1]+pnltyParamVal[0]*constrFcnMatrxs[11]);
    constrFcnMatrxs[12]=Mat[5]+expTempVar[0]*(constrFcnMatrxs[6]*constrFcnMatrxs[1]+pnltyParamVal[0]*constrFcnMatrxs[12]);
    
    constrFcnMatrxs[13]=Mat[6]+expTempVar[0]*(constrFcnMatrxs[2]*constrFcnMatrxs[2]+pnltyParamVal[0]*constrFcnMatrxs[13]);
    constrFcnMatrxs[14]=Mat[7]+expTempVar[0]*(constrFcnMatrxs[3]*constrFcnMatrxs[2]+pnltyParamVal[0]*constrFcnMatrxs[14]);
    constrFcnMatrxs[15]=Mat[8]+expTempVar[0]*(constrFcnMatrxs[4]*constrFcnMatrxs[2]+pnltyParamVal[0]*constrFcnMatrxs[15]);
    constrFcnMatrxs[16]=Mat[9]+expTempVar[0]*(constrFcnMatrxs[5]*constrFcnMatrxs[2]+pnltyParamVal[0]*constrFcnMatrxs[16]);
    constrFcnMatrxs[17]=Mat[10]+expTempVar[0]*(constrFcnMatrxs[6]*constrFcnMatrxs[2]+pnltyParamVal[0]*constrFcnMatrxs[17]);
    
    constrFcnMatrxs[18]=Mat[11]+expTempVar[0]*(constrFcnMatrxs[3]*constrFcnMatrxs[3]+pnltyParamVal[0]*constrFcnMatrxs[18]);
    constrFcnMatrxs[19]=Mat[12]+expTempVar[0]*(constrFcnMatrxs[4]*constrFcnMatrxs[3]+pnltyParamVal[0]*constrFcnMatrxs[19]);
    constrFcnMatrxs[20]=Mat[13]+expTempVar[0]*(constrFcnMatrxs[5]*constrFcnMatrxs[3]+pnltyParamVal[0]*constrFcnMatrxs[20]);
    constrFcnMatrxs[21]=Mat[14]+expTempVar[0]*(constrFcnMatrxs[6]*constrFcnMatrxs[3]);
    
    constrFcnMatrxs[22]=Mat[15]+expTempVar[0]*(constrFcnMatrxs[4]*constrFcnMatrxs[4]+pnltyParamVal[0]*constrFcnMatrxs[22]);
    constrFcnMatrxs[23]=Mat[16]+expTempVar[0]*(constrFcnMatrxs[5]*constrFcnMatrxs[4]);
    constrFcnMatrxs[24]=Mat[17]+expTempVar[0]*(constrFcnMatrxs[6]*constrFcnMatrxs[4]);
    
    constrFcnMatrxs[25]=Mat[18]+expTempVar[0]*(constrFcnMatrxs[5]*constrFcnMatrxs[5]+pnltyParamVal[0]*constrFcnMatrxs[25]);
    constrFcnMatrxs[26]=Mat[19]+expTempVar[0]*(constrFcnMatrxs[6]*constrFcnMatrxs[5]);
    
    constrFcnMatrxs[27]=Mat[20]+expTempVar[0]*(constrFcnMatrxs[6]*constrFcnMatrxs[6]+pnltyParamVal[0]*constrFcnMatrxs[27]);
    
    
    /* Vector update */
    constrFcnMatrxs[1]=Mat[0]*VecMlt[0]+Mat[1]*VecMlt[1]+Mat[2]*VecMlt[2]+Mat[3]*VecMlt[3]+Mat[4]*VecMlt[4]+Mat[5]*VecMlt[5]+VecAdd[0]+expTempVar[0]*constrFcnMatrxs[1];
    constrFcnMatrxs[2]=Mat[1]*VecMlt[0]+Mat[6]*VecMlt[1]+Mat[7]*VecMlt[2]+Mat[8]*VecMlt[3]+Mat[9]*VecMlt[4]+Mat[10]*VecMlt[5]+VecAdd[1]+expTempVar[0]*constrFcnMatrxs[2];
    constrFcnMatrxs[3]=Mat[2]*VecMlt[0]+Mat[7]*VecMlt[1]+Mat[11]*VecMlt[2]+Mat[12]*VecMlt[3]+Mat[13]*VecMlt[4]+Mat[14]*VecMlt[5]+VecAdd[2]+expTempVar[0]*constrFcnMatrxs[3];
    constrFcnMatrxs[4]=Mat[3]*VecMlt[0]+Mat[8]*VecMlt[1]+Mat[12]*VecMlt[2]+Mat[15]*VecMlt[3]+Mat[16]*VecMlt[4]+Mat[17]*VecMlt[5]+VecAdd[3]+expTempVar[0]*constrFcnMatrxs[4];
    constrFcnMatrxs[5]=Mat[4]*VecMlt[0]+Mat[9]*VecMlt[1]+Mat[13]*VecMlt[2]+Mat[16]*VecMlt[3]+Mat[18]*VecMlt[4]+Mat[19]*VecMlt[5]+VecAdd[4]+expTempVar[0]*constrFcnMatrxs[5];
    constrFcnMatrxs[6]=Mat[5]*VecMlt[0]+Mat[10]*VecMlt[1]+Mat[14]*VecMlt[2]+Mat[17]*VecMlt[3]+Mat[19]*VecMlt[4]+Mat[20]*VecMlt[5]+VecAdd[5]+expTempVar[0]*constrFcnMatrxs[6];
    
}

static void sym6x6MatRcprBarrierOprtrs(double *constrFcnMatrxs, double *Mat, double *VecAdd, double *VecMlt, double *ladg2, double *mi2ladg3){
    
    /* Operator used in "findMinTrfExpPenalty" */
    
    /* Matrix update */
    constrFcnMatrxs[7]=Mat[0]+mi2ladg3[0]*constrFcnMatrxs[1]*constrFcnMatrxs[1]+ladg2[0]*constrFcnMatrxs[7];
    constrFcnMatrxs[8]=Mat[1]+mi2ladg3[0]*constrFcnMatrxs[2]*constrFcnMatrxs[1]+ladg2[0]*constrFcnMatrxs[8];
    constrFcnMatrxs[9]=Mat[2]+mi2ladg3[0]*constrFcnMatrxs[3]*constrFcnMatrxs[1]+ladg2[0]*constrFcnMatrxs[9];
    constrFcnMatrxs[10]=Mat[3]+mi2ladg3[0]*constrFcnMatrxs[4]*constrFcnMatrxs[1]+ladg2[0]*constrFcnMatrxs[10];
    constrFcnMatrxs[11]=Mat[4]+mi2ladg3[0]*constrFcnMatrxs[5]*constrFcnMatrxs[1]+ladg2[0]*constrFcnMatrxs[11];
    constrFcnMatrxs[12]=Mat[5]+mi2ladg3[0]*constrFcnMatrxs[6]*constrFcnMatrxs[1]+ladg2[0]*constrFcnMatrxs[12];
    
    constrFcnMatrxs[13]=Mat[6]+mi2ladg3[0]*constrFcnMatrxs[2]*constrFcnMatrxs[2]+ladg2[0]*constrFcnMatrxs[13];
    constrFcnMatrxs[14]=Mat[7]+mi2ladg3[0]*constrFcnMatrxs[3]*constrFcnMatrxs[2]+ladg2[0]*constrFcnMatrxs[14];
    constrFcnMatrxs[15]=Mat[8]+mi2ladg3[0]*constrFcnMatrxs[4]*constrFcnMatrxs[2]+ladg2[0]*constrFcnMatrxs[15];
    constrFcnMatrxs[16]=Mat[9]+mi2ladg3[0]*constrFcnMatrxs[5]*constrFcnMatrxs[2]+ladg2[0]*constrFcnMatrxs[16];
    constrFcnMatrxs[17]=Mat[10]+mi2ladg3[0]*constrFcnMatrxs[6]*constrFcnMatrxs[2]+ladg2[0]*constrFcnMatrxs[17];
    
    constrFcnMatrxs[18]=Mat[11]+mi2ladg3[0]*constrFcnMatrxs[3]*constrFcnMatrxs[3]+ladg2[0]*constrFcnMatrxs[18];
    constrFcnMatrxs[19]=Mat[12]+mi2ladg3[0]*constrFcnMatrxs[4]*constrFcnMatrxs[3]+ladg2[0]*constrFcnMatrxs[19];
    constrFcnMatrxs[20]=Mat[13]+mi2ladg3[0]*constrFcnMatrxs[5]*constrFcnMatrxs[3]+ladg2[0]*constrFcnMatrxs[20];
    constrFcnMatrxs[21]=Mat[14]+mi2ladg3[0]*constrFcnMatrxs[6]*constrFcnMatrxs[3];
    
    constrFcnMatrxs[22]=Mat[15]+mi2ladg3[0]*constrFcnMatrxs[4]*constrFcnMatrxs[4]+ladg2[0]*constrFcnMatrxs[22];
    constrFcnMatrxs[23]=Mat[16]+mi2ladg3[0]*constrFcnMatrxs[5]*constrFcnMatrxs[4];
    constrFcnMatrxs[24]=Mat[17]+mi2ladg3[0]*constrFcnMatrxs[6]*constrFcnMatrxs[4];
    
    constrFcnMatrxs[25]=Mat[18]+mi2ladg3[0]*constrFcnMatrxs[5]*constrFcnMatrxs[5]+ladg2[0]*constrFcnMatrxs[25];
    constrFcnMatrxs[26]=Mat[19]+mi2ladg3[0]*constrFcnMatrxs[6]*constrFcnMatrxs[5];
    
    constrFcnMatrxs[27]=Mat[20]+mi2ladg3[0]*constrFcnMatrxs[6]*constrFcnMatrxs[6]+ladg2[0]*constrFcnMatrxs[27];
    
    
    /* Vector update */
    constrFcnMatrxs[1]=Mat[0]*VecMlt[0]+Mat[1]*VecMlt[1]+Mat[2]*VecMlt[2]+Mat[3]*VecMlt[3]+Mat[4]*VecMlt[4]+Mat[5]*VecMlt[5]+VecAdd[0]+ladg2[0]*constrFcnMatrxs[1];
    constrFcnMatrxs[2]=Mat[1]*VecMlt[0]+Mat[6]*VecMlt[1]+Mat[7]*VecMlt[2]+Mat[8]*VecMlt[3]+Mat[9]*VecMlt[4]+Mat[10]*VecMlt[5]+VecAdd[1]+ladg2[0]*constrFcnMatrxs[2];
    constrFcnMatrxs[3]=Mat[2]*VecMlt[0]+Mat[7]*VecMlt[1]+Mat[11]*VecMlt[2]+Mat[12]*VecMlt[3]+Mat[13]*VecMlt[4]+Mat[14]*VecMlt[5]+VecAdd[2]+ladg2[0]*constrFcnMatrxs[3];
    constrFcnMatrxs[4]=Mat[3]*VecMlt[0]+Mat[8]*VecMlt[1]+Mat[12]*VecMlt[2]+Mat[15]*VecMlt[3]+Mat[16]*VecMlt[4]+Mat[17]*VecMlt[5]+VecAdd[3]+ladg2[0]*constrFcnMatrxs[4];
    constrFcnMatrxs[5]=Mat[4]*VecMlt[0]+Mat[9]*VecMlt[1]+Mat[13]*VecMlt[2]+Mat[16]*VecMlt[3]+Mat[18]*VecMlt[4]+Mat[19]*VecMlt[5]+VecAdd[4]+ladg2[0]*constrFcnMatrxs[5];
    constrFcnMatrxs[6]=Mat[5]*VecMlt[0]+Mat[10]*VecMlt[1]+Mat[14]*VecMlt[2]+Mat[17]*VecMlt[3]+Mat[19]*VecMlt[4]+Mat[20]*VecMlt[5]+VecAdd[5]+ladg2[0]*constrFcnMatrxs[6];
    
}
