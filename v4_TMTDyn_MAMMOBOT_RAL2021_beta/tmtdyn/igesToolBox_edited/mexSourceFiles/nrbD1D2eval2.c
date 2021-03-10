
/* Written by Per Bergström */

/* nrbD1D2eval2 evaluates a surface point and derivatives for one parameter value */

/* nrbD1D2eval2( nrbStruct - nurbs pointer, nrbDerStruct - nurbs derivative pointer, nrbDer2Struct - nurbs second derivative pointer, paramValuePtr - pointer parameter values, evalPnt - pointer point on surface, evalDeru - pointer derivative u, evalDerv - pointer derivative v, evalDeruu - pointer second derivative uu, evalDeruv - pointer second derivative uv, evalDervv - pointer second derivative vv, bspPnts - pointer bspline point, leftU - pointer to array for function BasisFuns, rightU - pointer to array for function BasisFuns, NU - pointer to array for function BasisFuns, leftV - pointer to array for function BasisFuns, rightV - pointer to array for function BasisFuns, NV - pointer to array for function BasisFuns) */

static void oneBspEval2(int degU, int degV, double *cp, int ncp, int kcp, double *knotU, double *knotV, double *us, double *ep, double *leftU, double *rightU, double *NU, double *leftV, double *rightV, double *NV){
    /* Modification of ALGORITHM A3.5, The NURBS Book, L.Piegl and W. Tiller */
    
    /* oneBspEval2( degU - degree of B-spline in u, degV - degree of B-spline in v, cp - pointer to control points, ncp - number of control points in u, kcp - number of control points in v, knotU - pointer to knot sequence in u, knotV - pointer to knot sequence in v, us - pointer to parameter values, ep - pointer to evaluated points, leftU - pointer to array for function BasisFuns, rightU - pointer to array for function BasisFuns, NU - pointer to array for function BasisFuns, leftV - pointer to array for function BasisFuns, rightV - pointer to array for function BasisFuns, NV - pointer to array for function BasisFuns) */
    
    unsigned short int i, j, spanU, spanV, ind, ind2, fourncp, myint;
    double NN;
    
    fourncp=4*ncp;
    
    if(us[0]<=knotU[degU]){
        
        if(us[1]<=knotV[degV]){
            ep[0] = cp[0];
            ep[1] = cp[1];
            ep[2] = cp[2];
            ep[3] = cp[3];
        }
        else if(us[1]>=knotV[kcp]){
            myint=fourncp*(kcp-1);
            ep[0] = cp[myint];
            ep[1] = cp[myint+1];
            ep[2] = cp[myint+2];
            ep[3] = cp[myint+3];
        }
        else {
            ep[0]=0.0;
            ep[1]=0.0;
            ep[2]=0.0;
            ep[3]=0.0;
            
            spanV = FindSpan(kcp, degV, us[1], knotV);
            BasisFuns(spanV, us[1], degV, knotV, NV, leftV, rightV);
            
            ind = spanV - degV;
            
            for (i = 0; i <= degV; i++){
                ep[0] += NV[i] * cp[(ind+i)*fourncp];
                ep[1] += NV[i] * cp[(ind+i)*fourncp+1];
                ep[2] += NV[i] * cp[(ind+i)*fourncp+2];
                ep[3] += NV[i] * cp[(ind+i)*fourncp+3];
            }
        }
        
    }
    else if(us[0]>=knotU[ncp]){
        
        if(us[1]<=knotV[degV]){
            ep[0] = cp[fourncp-4];
            ep[1] = cp[fourncp-3];
            ep[2] = cp[fourncp-2];
            ep[3] = cp[fourncp-1];
        }
        else if(us[1]>=knotV[kcp]){
            myint=fourncp*kcp;
            ep[0] = cp[myint-4];
            ep[1] = cp[myint-3];
            ep[2] = cp[myint-2];
            ep[3] = cp[myint-1];
        }
        else {
            ep[0]=0.0;
            ep[1]=0.0;
            ep[2]=0.0;
            ep[3]=0.0;
            
            spanV = FindSpan(kcp, degV, us[1], knotV);
            BasisFuns(spanV, us[1], degV, knotV, NV, leftV, rightV);
            
            ind = spanV - degV;
            myint=(ind+1)*fourncp;
            
            for (i = 0; i <= degV; i++){
                ep[0] += NV[i] * cp[i*fourncp+myint-4];
                ep[1] += NV[i] * cp[i*fourncp+myint-3];
                ep[2] += NV[i] * cp[i*fourncp+myint-2];
                ep[3] += NV[i] * cp[i*fourncp+myint-1];
            }
        }
        
    }
    else {
        
        ep[0]=0.0;
        ep[1]=0.0;
        ep[2]=0.0;
        ep[3]=0.0;
        
        if(us[1]<=knotV[degV]){
            spanU = FindSpan(ncp, degU, us[0], knotU);
            BasisFuns(spanU, us[0], degU, knotU, NU, leftU, rightU);
            
            ind = spanU - degU;
            
            for (i = 0; i <= degU; i++){
                ep[0] += NU[i] * cp[(ind+i)*4];
                ep[1] += NU[i] * cp[(ind+i)*4+1];
                ep[2] += NU[i] * cp[(ind+i)*4+2];
                ep[3] += NU[i] * cp[(ind+i)*4+3];
            }
        }
        else if(us[1]>=knotV[kcp]){
            spanU = FindSpan(ncp, degU, us[0], knotU);
            BasisFuns(spanU, us[0], degU, knotU, NU, leftU, rightU);
            
            ind = spanU - degU;
            myint=ind*4+(kcp-1)*fourncp;
            
            for (i = 0; i <= degU; i++){
                ep[0] += NU[i] * cp[i*4+myint];
                ep[1] += NU[i] * cp[i*4+myint+1];
                ep[2] += NU[i] * cp[i*4+myint+2];
                ep[3] += NU[i] * cp[i*4+myint+3];
            }
        }
        else {
            spanU = FindSpan(ncp, degU, us[0], knotU);
            BasisFuns(spanU, us[0], degU, knotU, NU, leftU, rightU);
            
            spanV = FindSpan(kcp, degV, us[1], knotV);
            BasisFuns(spanV, us[1], degV, knotV, NV, leftV, rightV);
            
            ind = spanU - degU;
            ind2 = spanV - degV;
            myint=ind2*fourncp+ind*4;
            
            for (i = 0; i <= degV; i++){
                for (j = 0; j <= degU; j++){
                    NN=NV[i] * NU[j];
                    ep[0] += NN * cp[i*fourncp+j*4+myint];
                    ep[1] += NN * cp[i*fourncp+j*4+myint+1];
                    ep[2] += NN * cp[i*fourncp+j*4+myint+2];
                    ep[3] += NN * cp[i*fourncp+j*4+myint+3];
                }
            }
        }
        
    }
    
}


static void nrbD1D2eval2(int orderU, int orderV, int ncp, int kcp, mxArray *nrbStruct, mxArray *nrbDerStruct, mxArray *nrbDer2Struct, double *paramValuePtr, double *evalPnt, double *evalDeru, double *evalDerv, double *evalDeruu, double *evalDeruv, double *evalDervv, double *bspPnts, double *leftU, double *rightU, double *NU, double *leftV, double *rightV, double *NV) {
    /* nrbD1D2eval2 evaluates a surface point and derivatives for one parameter value */
    
    /* nrbD1D2eval2( nrbStruct - nurbs pointer, nrbDerStruct - nurbs derivative pointer, nrbDer2Struct - nurbs second derivative pointer, paramValuePtr - pointer parameter values, evalPnt - pointer point on surface, evalDeru - pointer derivative u, evalDerv - pointer derivative v, evalDeruu - pointer second derivative uu, evalDeruv - pointer second derivative uv, evalDervv - pointer second derivative vv, bspPnts - pointer bspline point, leftU - pointer to array for function BasisFuns, rightU - pointer to array for function BasisFuns, NU - pointer to array for function BasisFuns, leftV - pointer to array for function BasisFuns, rightV - pointer to array for function BasisFuns, NV - pointer to array for function BasisFuns) */
    
    double weightsPnts, weights, weights2;
    
    oneBspEval2(orderU-1, orderV-1, mxGetPr(mxGetField(nrbStruct, 0, "coefs")), ncp, kcp, mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(nrbStruct, 0, "knots"), 1)), paramValuePtr, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
    
    evalPnt[0]=(bspPnts[0])/(bspPnts[3]);
    evalPnt[1]=(bspPnts[1])/(bspPnts[3]);
    evalPnt[2]=(bspPnts[2])/(bspPnts[3]);
    
    if (orderU>2){
        
        if (orderV>2){
            
            weightsPnts=bspPnts[3];
            
            oneBspEval2(orderU-2, orderV-1, mxGetPr(mxGetField(mxGetCell(nrbDerStruct, 0), 0, "coefs")), ncp-1, kcp, mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDerStruct, 0), 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDerStruct, 0), 0, "knots"), 1)), paramValuePtr, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
            
            weights=bspPnts[3];
            
            evalDeru[0]=(bspPnts[0]-weights*evalPnt[0])/weightsPnts;
            evalDeru[1]=(bspPnts[1]-weights*evalPnt[1])/weightsPnts;
            evalDeru[2]=(bspPnts[2]-weights*evalPnt[2])/weightsPnts;
            
            
            oneBspEval2(orderU-1, orderV-2, mxGetPr(mxGetField(mxGetCell(nrbDerStruct, 1), 0, "coefs")), ncp, kcp-1, mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDerStruct, 1), 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDerStruct, 1), 0, "knots"), 1)), paramValuePtr, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
            
            weights2=bspPnts[3];
            
            evalDerv[0]=(bspPnts[0]-weights2*evalPnt[0])/weightsPnts;
            evalDerv[1]=(bspPnts[1]-weights2*evalPnt[1])/weightsPnts;
            evalDerv[2]=(bspPnts[2]-weights2*evalPnt[2])/weightsPnts;
            
            
            oneBspEval2(orderU-2, orderV-2, mxGetPr(mxGetField(mxGetCell(nrbDer2Struct, 1), 0, "coefs")), ncp-1, kcp-1, mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDer2Struct, 1), 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDer2Struct, 1), 0, "knots"), 1)), paramValuePtr, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
            
            evalDeruv[0]=(bspPnts[0]-weights2*evalDeru[0]-weights*evalDerv[0]-bspPnts[3]*evalPnt[0])/weightsPnts;
            evalDeruv[1]=(bspPnts[1]-weights2*evalDeru[1]-weights*evalDerv[1]-bspPnts[3]*evalPnt[1])/weightsPnts;
            evalDeruv[2]=(bspPnts[2]-weights2*evalDeru[2]-weights*evalDerv[2]-bspPnts[3]*evalPnt[2])/weightsPnts;
            
            
            oneBspEval2(orderU-3, orderV-1, mxGetPr(mxGetField(mxGetCell(nrbDer2Struct, 0), 0, "coefs")), ncp-2, kcp, mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDer2Struct, 0), 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDer2Struct, 0), 0, "knots"), 1)), paramValuePtr, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
            
            weights*=2.0;
            evalDeruu[0]=(bspPnts[0]-weights*evalDeru[0]-bspPnts[3]*evalPnt[0])/weightsPnts;
            evalDeruu[1]=(bspPnts[1]-weights*evalDeru[1]-bspPnts[3]*evalPnt[1])/weightsPnts;
            evalDeruu[2]=(bspPnts[2]-weights*evalDeru[2]-bspPnts[3]*evalPnt[2])/weightsPnts;
            
            
            oneBspEval2(orderU-1, orderV-3, mxGetPr(mxGetField(mxGetCell(nrbDer2Struct, 2), 0, "coefs")), ncp, kcp-2, mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDer2Struct, 2), 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDer2Struct, 2), 0, "knots"), 1)), paramValuePtr, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
            
            weights2*=2.0;
            evalDervv[0]=(bspPnts[0]-weights2*evalDerv[0]-bspPnts[3]*evalPnt[0])/weightsPnts;
            evalDervv[1]=(bspPnts[1]-weights2*evalDerv[1]-bspPnts[3]*evalPnt[1])/weightsPnts;
            evalDervv[2]=(bspPnts[2]-weights2*evalDerv[2]-bspPnts[3]*evalPnt[2])/weightsPnts;
            
        }
        else if (orderV==2){
            
            weightsPnts=bspPnts[3];
            
            oneBspEval2(orderU-2, orderV-1, mxGetPr(mxGetField(mxGetCell(nrbDerStruct, 0), 0, "coefs")), ncp-1, kcp, mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDerStruct, 0), 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDerStruct, 0), 0, "knots"), 1)), paramValuePtr, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
            
            weights=bspPnts[3];
            
            evalDeru[0]=(bspPnts[0]-weights*evalPnt[0])/weightsPnts;
            evalDeru[1]=(bspPnts[1]-weights*evalPnt[1])/weightsPnts;
            evalDeru[2]=(bspPnts[2]-weights*evalPnt[2])/weightsPnts;
            
            
            oneBspEval2(orderU-1, orderV-2, mxGetPr(mxGetField(mxGetCell(nrbDerStruct, 1), 0, "coefs")), ncp, kcp-1, mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDerStruct, 1), 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDerStruct, 1), 0, "knots"), 1)), paramValuePtr, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
            
            weights2=bspPnts[3];
            
            evalDerv[0]=(bspPnts[0]-weights2*evalPnt[0])/weightsPnts;
            evalDerv[1]=(bspPnts[1]-weights2*evalPnt[1])/weightsPnts;
            evalDerv[2]=(bspPnts[2]-weights2*evalPnt[2])/weightsPnts;
            
            
            oneBspEval2(orderU-2, orderV-2, mxGetPr(mxGetField(mxGetCell(nrbDer2Struct, 1), 0, "coefs")), ncp-1, kcp-1, mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDer2Struct, 1), 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDer2Struct, 1), 0, "knots"), 1)), paramValuePtr, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
            
            evalDeruv[0]=(bspPnts[0]-weights2*evalDeru[0]-weights*evalDerv[0]-bspPnts[3]*evalPnt[0])/weightsPnts;
            evalDeruv[1]=(bspPnts[1]-weights2*evalDeru[1]-weights*evalDerv[1]-bspPnts[3]*evalPnt[1])/weightsPnts;
            evalDeruv[2]=(bspPnts[2]-weights2*evalDeru[2]-weights*evalDerv[2]-bspPnts[3]*evalPnt[2])/weightsPnts;
            
            
            oneBspEval2(orderU-3, orderV-1, mxGetPr(mxGetField(mxGetCell(nrbDer2Struct, 0), 0, "coefs")), ncp-2, kcp, mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDer2Struct, 0), 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDer2Struct, 0), 0, "knots"), 1)), paramValuePtr, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
            
            weights*=2.0;
            evalDeruu[0]=(bspPnts[0]-weights*evalDeru[0]-bspPnts[3]*evalPnt[0])/weightsPnts;
            evalDeruu[1]=(bspPnts[1]-weights*evalDeru[1]-bspPnts[3]*evalPnt[1])/weightsPnts;
            evalDeruu[2]=(bspPnts[2]-weights*evalDeru[2]-bspPnts[3]*evalPnt[2])/weightsPnts;
            
            
            evalDervv[0]=0.0;
            evalDervv[1]=0.0;
            evalDervv[2]=0.0;
            
        }
        else {
            
            weightsPnts=bspPnts[3];
            
            oneBspEval2(orderU-2, orderV-1, mxGetPr(mxGetField(mxGetCell(nrbDerStruct, 0), 0, "coefs")), ncp-1, kcp, mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDerStruct, 0), 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDerStruct, 0), 0, "knots"), 1)), paramValuePtr, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
            
            weights=bspPnts[3];
            
            evalDeru[0]=(bspPnts[0]-weights*evalPnt[0])/weightsPnts;
            evalDeru[1]=(bspPnts[1]-weights*evalPnt[1])/weightsPnts;
            evalDeru[2]=(bspPnts[2]-weights*evalPnt[2])/weightsPnts;
            
            
            evalDerv[0]=0.0;
            evalDerv[1]=0.0;
            evalDerv[2]=0.0;
            
            
            evalDeruv[0]=0.0;
            evalDeruv[1]=0.0;
            evalDeruv[2]=0.0;
            
            
            oneBspEval2(orderU-3, orderV-1, mxGetPr(mxGetField(mxGetCell(nrbDer2Struct, 0), 0, "coefs")), ncp-2, kcp, mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDer2Struct, 0), 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDer2Struct, 0), 0, "knots"), 1)), paramValuePtr, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
            
            weights*=2.0;
            evalDeruu[0]=(bspPnts[0]-weights*evalDeru[0]-bspPnts[3]*evalPnt[0])/weightsPnts;
            evalDeruu[1]=(bspPnts[1]-weights*evalDeru[1]-bspPnts[3]*evalPnt[1])/weightsPnts;
            evalDeruu[2]=(bspPnts[2]-weights*evalDeru[2]-bspPnts[3]*evalPnt[2])/weightsPnts;
            
            
            evalDervv[0]=0.0;
            evalDervv[1]=0.0;
            evalDervv[2]=0.0;
            
        }
        
    }
    else if (orderU==2){
        
        if (orderV>2){
            
            weightsPnts=bspPnts[3];
            
            oneBspEval2(orderU-2, orderV-1, mxGetPr(mxGetField(mxGetCell(nrbDerStruct, 0), 0, "coefs")), ncp-1, kcp, mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDerStruct, 0), 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDerStruct, 0), 0, "knots"), 1)), paramValuePtr, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
            
            weights=bspPnts[3];
            
            evalDeru[0]=(bspPnts[0]-weights*evalPnt[0])/weightsPnts;
            evalDeru[1]=(bspPnts[1]-weights*evalPnt[1])/weightsPnts;
            evalDeru[2]=(bspPnts[2]-weights*evalPnt[2])/weightsPnts;
            
            
            oneBspEval2(orderU-1, orderV-2, mxGetPr(mxGetField(mxGetCell(nrbDerStruct, 1), 0, "coefs")), ncp, kcp-1, mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDerStruct, 1), 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDerStruct, 1), 0, "knots"), 1)), paramValuePtr, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
            
            weights2=bspPnts[3];
            
            evalDerv[0]=(bspPnts[0]-weights2*evalPnt[0])/weightsPnts;
            evalDerv[1]=(bspPnts[1]-weights2*evalPnt[1])/weightsPnts;
            evalDerv[2]=(bspPnts[2]-weights2*evalPnt[2])/weightsPnts;
            
            
            oneBspEval2(orderU-2, orderV-2, mxGetPr(mxGetField(mxGetCell(nrbDer2Struct, 1), 0, "coefs")), ncp-1, kcp-1, mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDer2Struct, 1), 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDer2Struct, 1), 0, "knots"), 1)), paramValuePtr, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
            
            evalDeruv[0]=(bspPnts[0]-weights2*evalDeru[0]-weights*evalDerv[0]-bspPnts[3]*evalPnt[0])/weightsPnts;
            evalDeruv[1]=(bspPnts[1]-weights2*evalDeru[1]-weights*evalDerv[1]-bspPnts[3]*evalPnt[1])/weightsPnts;
            evalDeruv[2]=(bspPnts[2]-weights2*evalDeru[2]-weights*evalDerv[2]-bspPnts[3]*evalPnt[2])/weightsPnts;
            
            
            evalDeruu[0]=0.0;
            evalDeruu[1]=0.0;
            evalDeruu[2]=0.0;
            
            
            oneBspEval2(orderU-1, orderV-3, mxGetPr(mxGetField(mxGetCell(nrbDer2Struct, 2), 0, "coefs")), ncp, kcp-2, mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDer2Struct, 2), 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDer2Struct, 2), 0, "knots"), 1)), paramValuePtr, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
            
            weights2*=2.0;
            evalDervv[0]=(bspPnts[0]-weights2*evalDerv[0]-bspPnts[3]*evalPnt[0])/weightsPnts;
            evalDervv[1]=(bspPnts[1]-weights2*evalDerv[1]-bspPnts[3]*evalPnt[1])/weightsPnts;
            evalDervv[2]=(bspPnts[2]-weights2*evalDerv[2]-bspPnts[3]*evalPnt[2])/weightsPnts;
            
        }
        else if (orderV==2){
            
            weightsPnts=bspPnts[3];
            
            oneBspEval2(orderU-2, orderV-1, mxGetPr(mxGetField(mxGetCell(nrbDerStruct, 0), 0, "coefs")), ncp-1, kcp, mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDerStruct, 0), 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDerStruct, 0), 0, "knots"), 1)), paramValuePtr, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
            
            weights=bspPnts[3];
            
            evalDeru[0]=(bspPnts[0]-weights*evalPnt[0])/weightsPnts;
            evalDeru[1]=(bspPnts[1]-weights*evalPnt[1])/weightsPnts;
            evalDeru[2]=(bspPnts[2]-weights*evalPnt[2])/weightsPnts;
            
            
            oneBspEval2(orderU-1, orderV-2, mxGetPr(mxGetField(mxGetCell(nrbDerStruct, 1), 0, "coefs")), ncp, kcp-1, mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDerStruct, 1), 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDerStruct, 1), 0, "knots"), 1)), paramValuePtr, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
            
            weights2=bspPnts[3];
            
            evalDerv[0]=(bspPnts[0]-weights2*evalPnt[0])/weightsPnts;
            evalDerv[1]=(bspPnts[1]-weights2*evalPnt[1])/weightsPnts;
            evalDerv[2]=(bspPnts[2]-weights2*evalPnt[2])/weightsPnts;
            
            
            oneBspEval2(orderU-2, orderV-2, mxGetPr(mxGetField(mxGetCell(nrbDer2Struct, 1), 0, "coefs")), ncp-1, kcp-1, mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDer2Struct, 1), 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDer2Struct, 1), 0, "knots"), 1)), paramValuePtr, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
            
            evalDeruv[0]=(bspPnts[0]-weights2*evalDeru[0]-weights*evalDerv[0]-bspPnts[3]*evalPnt[0])/weightsPnts;
            evalDeruv[1]=(bspPnts[1]-weights2*evalDeru[1]-weights*evalDerv[1]-bspPnts[3]*evalPnt[1])/weightsPnts;
            evalDeruv[2]=(bspPnts[2]-weights2*evalDeru[2]-weights*evalDerv[2]-bspPnts[3]*evalPnt[2])/weightsPnts;
            
            
            evalDeruu[0]=0.0;
            evalDeruu[1]=0.0;
            evalDeruu[2]=0.0;
            
            
            evalDervv[0]=0.0;
            evalDervv[1]=0.0;
            evalDervv[2]=0.0;
            
        }
        else {
            
            weightsPnts=bspPnts[3];
            
            oneBspEval2(orderU-2, orderV-1, mxGetPr(mxGetField(mxGetCell(nrbDerStruct, 0), 0, "coefs")), ncp-1, kcp, mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDerStruct, 0), 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDerStruct, 0), 0, "knots"), 1)), paramValuePtr, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
            
            weights=bspPnts[3];
            
            evalDeru[0]=(bspPnts[0]-weights*evalPnt[0])/weightsPnts;
            evalDeru[1]=(bspPnts[1]-weights*evalPnt[1])/weightsPnts;
            evalDeru[2]=(bspPnts[2]-weights*evalPnt[2])/weightsPnts;
            
            
            evalDerv[0]=0.0;
            evalDerv[1]=0.0;
            evalDerv[2]=0.0;
            
            
            evalDeruv[0]=0.0;
            evalDeruv[1]=0.0;
            evalDeruv[2]=0.0;
            
            
            evalDeruu[0]=0.0;
            evalDeruu[1]=0.0;
            evalDeruu[2]=0.0;
            
            
            evalDervv[0]=0.0;
            evalDervv[1]=0.0;
            evalDervv[2]=0.0;
            
        }
        
    }
    else {
        
        if (orderV>2){
            
            weightsPnts=bspPnts[3];
            
            evalDeru[0]=0.0;
            evalDeru[1]=0.0;
            evalDeru[2]=0.0;
            
            
            oneBspEval2(orderU-1, orderV-2, mxGetPr(mxGetField(mxGetCell(nrbDerStruct, 1), 0, "coefs")), ncp, kcp-1, mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDerStruct, 1), 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDerStruct, 1), 0, "knots"), 1)), paramValuePtr, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
            
            weights2=bspPnts[3];
            
            evalDerv[0]=(bspPnts[0]-weights2*evalPnt[0])/weightsPnts;
            evalDerv[1]=(bspPnts[1]-weights2*evalPnt[1])/weightsPnts;
            evalDerv[2]=(bspPnts[2]-weights2*evalPnt[2])/weightsPnts;
            
            
            evalDeruv[0]=0.0;
            evalDeruv[1]=0.0;
            evalDeruv[2]=0.0;
            
            
            evalDeruu[0]=0.0;
            evalDeruu[1]=0.0;
            evalDeruu[2]=0.0;
            
            
            oneBspEval2(orderU-1, orderV-3, mxGetPr(mxGetField(mxGetCell(nrbDer2Struct, 2), 0, "coefs")), ncp, kcp-2, mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDer2Struct, 2), 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDer2Struct, 2), 0, "knots"), 1)), paramValuePtr, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
            
            weights2*=2.0;
            evalDervv[0]=(bspPnts[0]-weights2*evalDerv[0]-bspPnts[3]*evalPnt[0])/weightsPnts;
            evalDervv[1]=(bspPnts[1]-weights2*evalDerv[1]-bspPnts[3]*evalPnt[1])/weightsPnts;
            evalDervv[2]=(bspPnts[2]-weights2*evalDerv[2]-bspPnts[3]*evalPnt[2])/weightsPnts;
            
        }
        else if (orderV==2){
            
            weightsPnts=bspPnts[3];
            
            evalDeru[0]=0.0;
            evalDeru[1]=0.0;
            evalDeru[2]=0.0;
            
            
            oneBspEval2(orderU-1, orderV-2, mxGetPr(mxGetField(mxGetCell(nrbDerStruct, 1), 0, "coefs")), ncp, kcp-1, mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDerStruct, 1), 0, "knots"), 0)), mxGetPr(mxGetCell(mxGetField(mxGetCell(nrbDerStruct, 1), 0, "knots"), 1)), paramValuePtr, bspPnts, leftU, rightU, NU, leftV, rightV, NV);
            
            weights2=bspPnts[3];
            
            evalDerv[0]=(bspPnts[0]-weights2*evalPnt[0])/weightsPnts;
            evalDerv[1]=(bspPnts[1]-weights2*evalPnt[1])/weightsPnts;
            evalDerv[2]=(bspPnts[2]-weights2*evalPnt[2])/weightsPnts;
            
            
            evalDeruv[0]=0.0;
            evalDeruv[1]=0.0;
            evalDeruv[2]=0.0;
            
            
            evalDeruu[0]=0.0;
            evalDeruu[1]=0.0;
            evalDeruu[2]=0.0;
            
            
            evalDervv[0]=0.0;
            evalDervv[1]=0.0;
            evalDervv[2]=0.0;
            
        }
        else {
            
            evalDeru[0]=0.0;
            evalDeru[1]=0.0;
            evalDeru[2]=0.0;
            
            
            evalDerv[0]=0.0;
            evalDerv[1]=0.0;
            evalDerv[2]=0.0;
            
            
            evalDeruv[0]=0.0;
            evalDeruv[1]=0.0;
            evalDeruv[2]=0.0;
            
            
            evalDeruu[0]=0.0;
            evalDeruu[1]=0.0;
            evalDeruu[2]=0.0;
            
            
            evalDervv[0]=0.0;
            evalDervv[1]=0.0;
            evalDervv[2]=0.0;
            
        }
        
    }
    
}
