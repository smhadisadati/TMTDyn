
/* Written by Per Bergström */

static void nrbD1eval(int order, int ncp, mxArray *nrbStruct, mxArray *nrbDerStruct, double *paramValuePtr, double *evalPnt, double *evalDer, double *bspPnts, double *left, double *right, double *N) {
    /* nrbD1eval evaluates a curve point and derivative for one parameter value */
    
    /* nrbD1eval( nrbStruct - nurbs pointer, nrbDerStruct - nurbs derivative pointer, paramValuePtr - pointer parameter values, evalPnt - pointer point on curve, evalDer - pointer derivative, bspPnts - pointer bspline point, left - pointer to array for function BasisFuns, right - pointer to array for function BasisFuns, N - pointer to array for function BasisFuns) */
    
    unsigned short int i, span, ind, deg, fourncp;
    double weightsPnts;
    double *cp;
    
    deg=order-1;
    cp=mxGetPr(mxGetField(nrbStruct, 0, "coefs"));
    
    fourncp=4*ncp;
    
    if (paramValuePtr[0]<=mxGetPr(mxGetField(nrbStruct, 0, "knots"))[deg]){
        
        weightsPnts=cp[3];
        evalPnt[0]=cp[0]/weightsPnts;
        evalPnt[1]=cp[1]/weightsPnts;
        evalPnt[2]=cp[2]/weightsPnts;
        
        if (order>1){
            cp=mxGetPr(mxGetField(nrbDerStruct, 0, "coefs"));
            
            evalDer[0]=(cp[0]-cp[3]*evalPnt[0])/weightsPnts;
            evalDer[1]=(cp[1]-cp[3]*evalPnt[1])/weightsPnts;
            evalDer[2]=(cp[2]-cp[3]*evalPnt[2])/weightsPnts;
        }
        else {
            evalDer[0]=0.0;
            evalDer[1]=0.0;
            evalDer[2]=0.0;
        }
        
    }
    else if(paramValuePtr[0]>=mxGetPr(mxGetField(nrbStruct, 0, "knots"))[ncp]){
        
        weightsPnts = cp[fourncp-1];
        evalPnt[0]=cp[fourncp-4]/weightsPnts;
        evalPnt[1]=cp[fourncp-3]/weightsPnts;
        evalPnt[2]=cp[fourncp-2]/weightsPnts;
        
        if (order>1){
            cp=mxGetPr(mxGetField(nrbDerStruct, 0, "coefs"));
            fourncp-=4;
            
            evalDer[0]=(cp[fourncp-4]-cp[fourncp-1]*evalPnt[0])/weightsPnts;
            evalDer[1]=(cp[fourncp-3]-cp[fourncp-1]*evalPnt[1])/weightsPnts;
            evalDer[2]=(cp[fourncp-2]-cp[fourncp-1]*evalPnt[2])/weightsPnts;
        }
        else {
            evalDer[0]=0.0;
            evalDer[1]=0.0;
            evalDer[2]=0.0;
        }
        
    }
    else {
        
        span = FindSpan(ncp, deg, paramValuePtr[0], mxGetPr(mxGetField(nrbStruct, 0, "knots")));
        
        bspPnts[0] = 0.0;
        bspPnts[1] = 0.0;
        bspPnts[2] = 0.0;
        bspPnts[3] = 0.0;
        
        BasisFuns(span, paramValuePtr[0], deg, mxGetPr(mxGetField(nrbStruct, 0, "knots")), N, left, right);
        
        ind = span - deg;
        
        for (i = 0; i <= deg; i++){
            bspPnts[0] += N[i] * cp[(i+ind)*4];
            bspPnts[1] += N[i] * cp[(i+ind)*4+1];
            bspPnts[2] += N[i] * cp[(i+ind)*4+2];
            bspPnts[3] += N[i] * cp[(i+ind)*4+3];
        }
        
        weightsPnts=bspPnts[3];
        evalPnt[0]=bspPnts[0]/weightsPnts;
        evalPnt[1]=bspPnts[1]/weightsPnts;
        evalPnt[2]=bspPnts[2]/weightsPnts;
        
        if (order>1){
            cp=mxGetPr(mxGetField(nrbDerStruct, 0, "coefs"));
            deg--;
            
            bspPnts[0] = 0.0;
            bspPnts[1] = 0.0;
            bspPnts[2] = 0.0;
            bspPnts[3] = 0.0;
            
            BasisFuns(span-1, paramValuePtr[0], deg, mxGetPr(mxGetField(nrbDerStruct, 0, "knots")), N, left, right);
            
            for (i = 0; i <= deg; i++){
                bspPnts[0] += N[i] * cp[(i+ind)*4];
                bspPnts[1] += N[i] * cp[(i+ind)*4+1];
                bspPnts[2] += N[i] * cp[(i+ind)*4+2];
                bspPnts[3] += N[i] * cp[(i+ind)*4+3];
            }
            
            evalDer[0]=(bspPnts[0]-bspPnts[3]*evalPnt[0])/weightsPnts;
            evalDer[1]=(bspPnts[1]-bspPnts[3]*evalPnt[1])/weightsPnts;
            evalDer[2]=(bspPnts[2]-bspPnts[3]*evalPnt[2])/weightsPnts;
        }
        else {
            evalDer[0]=0.0;
            evalDer[1]=0.0;
            evalDer[2]=0.0;
        }
        
    }
    
}


static void nrbD1D2eval(int order, int ncp, mxArray *nrbStruct, mxArray *nrbDerStruct, mxArray *nrbDer2Struct, double *paramValuePtr, double *evalPnt, double *evalDer, double *evalDer2, double *bspPnts, double *left, double *right, double *N) {
    /* nrbD1D2eval evaluates a curve point and derivatives for one parameter value */
    
    /* nrbD1D2eval( nrbStruct - nurbs pointer, nrbDerStruct - nurbs derivative pointer, nrbDer2Struct - nurbs second derivative pointer, paramValuePtr - pointer parameter values, evalPnt - pointer point on curve, evalDer - pointer derivative, evalDer2 - pointer second derivative, bspPnts - pointer bspline point, left - pointer to array for function BasisFuns, right - pointer to array for function BasisFuns, N - pointer to array for function BasisFuns) */
    
    unsigned short int i, span, ind, deg, fourncp;
    double weightsPnts, weights;
    double *cp;
    
    deg=order-1;
    cp=mxGetPr(mxGetField(nrbStruct, 0, "coefs"));
    
    fourncp=4*ncp;
    
    if (paramValuePtr[0]<=mxGetPr(mxGetField(nrbStruct, 0, "knots"))[deg]){
        
        weightsPnts=cp[3];
        evalPnt[0]=cp[0]/weightsPnts;
        evalPnt[1]=cp[1]/weightsPnts;
        evalPnt[2]=cp[2]/weightsPnts;
        
        if (order>1){
            cp=mxGetPr(mxGetField(nrbDerStruct, 0, "coefs"));
            
            weights=cp[3];
            evalDer[0]=(cp[0]-weights*evalPnt[0])/weightsPnts;
            evalDer[1]=(cp[1]-weights*evalPnt[1])/weightsPnts;
            evalDer[2]=(cp[2]-weights*evalPnt[2])/weightsPnts;
            
            if (order>2){
                cp=mxGetPr(mxGetField(nrbDer2Struct, 0, "coefs"));
                
                weights*=2.0;
                evalDer2[0]=(cp[0]-weights*evalDer[0]-cp[3]*evalPnt[0])/weightsPnts;
                evalDer2[1]=(cp[1]-weights*evalDer[1]-cp[3]*evalPnt[1])/weightsPnts;
                evalDer2[2]=(cp[2]-weights*evalDer[2]-cp[3]*evalPnt[2])/weightsPnts;
            }
            else {
                evalDer2[0]=0.0;
                evalDer2[1]=0.0;
                evalDer2[2]=0.0;
            }
        }
        else {
            evalDer[0]=0.0;
            evalDer[1]=0.0;
            evalDer[2]=0.0;
            
            evalDer2[0]=0.0;
            evalDer2[1]=0.0;
            evalDer2[2]=0.0;
        }
        
    }
    else if(paramValuePtr[0]>=mxGetPr(mxGetField(nrbStruct, 0, "knots"))[ncp]){
        
        weightsPnts = cp[fourncp-1];
        evalPnt[0]=cp[fourncp-4]/weightsPnts;
        evalPnt[1]=cp[fourncp-3]/weightsPnts;
        evalPnt[2]=cp[fourncp-2]/weightsPnts;
        
        if (order>1){
            cp=mxGetPr(mxGetField(nrbDerStruct, 0, "coefs"));
            fourncp-=4;
            
            weights=cp[fourncp-1];
            evalDer[0]=(cp[fourncp-4]-weights*evalPnt[0])/weightsPnts;
            evalDer[1]=(cp[fourncp-3]-weights*evalPnt[1])/weightsPnts;
            evalDer[2]=(cp[fourncp-2]-weights*evalPnt[2])/weightsPnts;
            
            if (order>2){
                cp=mxGetPr(mxGetField(nrbDer2Struct, 0, "coefs"));
                fourncp-=4;
                
                weights*=2.0;
                evalDer2[0]=(cp[fourncp-4]-weights*evalDer[0]-cp[fourncp-1]*evalPnt[0])/weightsPnts;
                evalDer2[1]=(cp[fourncp-3]-weights*evalDer[1]-cp[fourncp-1]*evalPnt[1])/weightsPnts;
                evalDer2[2]=(cp[fourncp-2]-weights*evalDer[2]-cp[fourncp-1]*evalPnt[2])/weightsPnts;
            }
            else {
                evalDer2[0]=0.0;
                evalDer2[1]=0.0;
                evalDer2[2]=0.0;
            }
        }
        else {
            evalDer[0]=0.0;
            evalDer[1]=0.0;
            evalDer[2]=0.0;
            
            evalDer2[0]=0.0;
            evalDer2[1]=0.0;
            evalDer2[2]=0.0;
        }
        
    }
    else {
        
        span = FindSpan(ncp, deg, paramValuePtr[0], mxGetPr(mxGetField(nrbStruct, 0, "knots")));
        
        bspPnts[0] = 0.0;
        bspPnts[1] = 0.0;
        bspPnts[2] = 0.0;
        bspPnts[3] = 0.0;
        
        BasisFuns(span, paramValuePtr[0], deg, mxGetPr(mxGetField(nrbStruct, 0, "knots")), N, left, right);
        
        ind = span - deg;
        
        for (i = 0; i <= deg; i++){
            bspPnts[0] += N[i] * cp[(i+ind)*4];
            bspPnts[1] += N[i] * cp[(i+ind)*4+1];
            bspPnts[2] += N[i] * cp[(i+ind)*4+2];
            bspPnts[3] += N[i] * cp[(i+ind)*4+3];
        }
        
        weightsPnts=bspPnts[3];
        evalPnt[0]=bspPnts[0]/weightsPnts;
        evalPnt[1]=bspPnts[1]/weightsPnts;
        evalPnt[2]=bspPnts[2]/weightsPnts;
        
        if (order>1){
            cp=mxGetPr(mxGetField(nrbDerStruct, 0, "coefs"));
            deg--;
            
            bspPnts[0] = 0.0;
            bspPnts[1] = 0.0;
            bspPnts[2] = 0.0;
            bspPnts[3] = 0.0;
            
            BasisFuns(span-1, paramValuePtr[0], deg, mxGetPr(mxGetField(nrbDerStruct, 0, "knots")), N, left, right);
            
            for (i = 0; i <= deg; i++){
                bspPnts[0] += N[i] * cp[(i+ind)*4];
                bspPnts[1] += N[i] * cp[(i+ind)*4+1];
                bspPnts[2] += N[i] * cp[(i+ind)*4+2];
                bspPnts[3] += N[i] * cp[(i+ind)*4+3];
            }
            
            weights=bspPnts[3];
            evalDer[0]=(bspPnts[0]-weights*evalPnt[0])/weightsPnts;
            evalDer[1]=(bspPnts[1]-weights*evalPnt[1])/weightsPnts;
            evalDer[2]=(bspPnts[2]-weights*evalPnt[2])/weightsPnts;
            
            if (order>2){
                cp=mxGetPr(mxGetField(nrbDer2Struct, 0, "coefs"));
                deg--;
                
                bspPnts[0] = 0.0;
                bspPnts[1] = 0.0;
                bspPnts[2] = 0.0;
                bspPnts[3] = 0.0;
                
                BasisFuns(span-2, paramValuePtr[0], deg, mxGetPr(mxGetField(nrbDer2Struct, 0, "knots")), N, left, right);
                
                for (i = 0; i <= deg; i++){
                    bspPnts[0] += N[i] * cp[(i+ind)*4];
                    bspPnts[1] += N[i] * cp[(i+ind)*4+1];
                    bspPnts[2] += N[i] * cp[(i+ind)*4+2];
                    bspPnts[3] += N[i] * cp[(i+ind)*4+3];
                }
                
                weights*=2.0;
                evalDer2[0]=(bspPnts[0]-weights*evalDer[0]-bspPnts[3]*evalPnt[0])/weightsPnts;
                evalDer2[1]=(bspPnts[1]-weights*evalDer[1]-bspPnts[3]*evalPnt[1])/weightsPnts;
                evalDer2[2]=(bspPnts[2]-weights*evalDer[2]-bspPnts[3]*evalPnt[2])/weightsPnts;
            }
            else {
                evalDer2[0]=0.0;
                evalDer2[1]=0.0;
                evalDer2[2]=0.0;
            }
        }
        else {
            evalDer[0]=0.0;
            evalDer[1]=0.0;
            evalDer[2]=0.0;
            
            evalDer2[0]=0.0;
            evalDer2[1]=0.0;
            evalDer2[2]=0.0;
        }
        
    }
    
}
