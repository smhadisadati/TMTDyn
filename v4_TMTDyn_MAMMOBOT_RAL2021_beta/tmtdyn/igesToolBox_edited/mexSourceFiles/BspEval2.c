
/* Written by Per Bergström */

static void BspEval2(int degU, int degV, double *cp, int mcp, int ncp, int kcp, double *knotU, double *knotV, double *us, unsigned int nus, double *ep, double *leftU, double *rightU, double *NU, double *leftV, double *rightV, double *NV){
    /* Modification of ALGORITHM A3.5, The NURBS Book, L.Piegl and W. Tiller */
    
    /* BspEval2 evaluates a B-spline at given parameter values (u,v) */
    
    /* BspEval2( degU - degree of B-spline in u, degV - degree of B-spline in v, cp - pointer to control points, mcp - number of elements in a control point, ncp - number of control points in u, kcp - number of control points in v, knotU - pointer to knot sequence in u, knotV - pointer to knot sequence in v, us - pointer to parameter values,  nus - number of parameter values, ep - pointer to evaluated points, leftU - pointer to array for function BasisFuns, rightU - pointer to array for function BasisFuns, NU - pointer to array for function BasisFuns, leftV - pointer to array for function BasisFuns, rightV - pointer to array for function BasisFuns, NV - pointer to array for function BasisFuns) */
    
    unsigned short int i, j, ii, spanU, spanV, ind, myint1, myint2, myint3, mcpncp;
    unsigned int jj, jjmcp=0, twojj=0;
    double NN;
    
    mcpncp=mcp*ncp;
    myint3=mcpncp*(kcp-1);
    
    for (jj = 0; jj < nus; jj++){
        
        if(us[twojj]<=knotU[degU]){
            if(us[twojj+1]<=knotV[degV]){
                for (ii = 0; ii < mcp; ii++){
                    ep[jjmcp+ii] = cp[ii];
                }
            }
            else if(us[twojj+1]>=knotV[kcp]){
                for (ii = 0; ii < mcp; ii++){
                    ep[jjmcp+ii] = cp[myint3+ii];
                }
            }
            else{
                for (ii = 0; ii < mcp; ii++){
                    ep[jjmcp+ii]=0.0;
                }
                spanV = FindSpan(kcp, degV, us[twojj+1], knotV);
                BasisFuns(spanV, us[twojj+1], degV, knotV, NV, leftV, rightV);
                
                myint2=(spanV-degV)*mcpncp;
                
                for (i = 0; i <= degV; i++){
                    for (ii = 0; ii < mcp; ii++){
                        ep[jjmcp+ii] += NV[i] * cp[myint2+ii];
                    }
                    myint2+=mcpncp;
                }
            }
        }
        else if(us[twojj]>=knotU[ncp]){
            if(us[twojj+1]<=knotV[degV]){
                myint2=mcpncp-mcp;
                for (ii = 0; ii < mcp; ii++){
                    ep[jjmcp+ii] = cp[myint2+ii];
                }
            }
            else if(us[twojj+1]>=knotV[kcp]){
                myint2=mcpncp*kcp-mcp;
                for (ii = 0; ii < mcp; ii++){
                    ep[jjmcp+ii] = cp[myint2+ii];
                }
            }
            else{
                for (ii = 0; ii < mcp; ii++){
                    ep[jjmcp+ii]=0.0;
                }
                spanV = FindSpan(kcp, degV, us[twojj+1], knotV);
                BasisFuns(spanV, us[twojj+1], degV, knotV, NV, leftV, rightV);
                
                myint2=(spanV-degV+1)*mcpncp-mcp;
                
                for (i = 0; i <= degV; i++){
                    for (ii = 0; ii < mcp; ii++){
                        ep[jjmcp+ii] += NV[i] * cp[myint2+ii];
                    }
                    myint2+=mcpncp;
                }
            }
        }
        else{
            for (ii = 0; ii < mcp; ii++){
                ep[jjmcp+ii]=0.0;
            }
            if(us[twojj+1]<=knotV[degV]){
                spanU = FindSpan(ncp, degU, us[twojj], knotU);
                BasisFuns(spanU, us[twojj], degU, knotU, NU, leftU, rightU);
                
                myint2=(spanU-degU)*mcp;
                
                for (i = 0; i <= degU; i++){
                    for (ii = 0; ii < mcp; ii++){
                        ep[jjmcp+ii] += NU[i] * cp[myint2+ii];
                    }
                    myint2+=mcp;
                }
            }
            else if(us[twojj+1]>=knotV[kcp]){
                spanU = FindSpan(ncp, degU, us[twojj], knotU);
                BasisFuns(spanU, us[twojj], degU, knotU, NU, leftU, rightU);
                
                myint2=myint3+(spanU-degU)*mcp;
                
                for (i = 0; i <= degU; i++){
                    for (ii = 0; ii < mcp; ii++){
                        ep[jjmcp+ii] += NU[i] * cp[myint2+ii];
                    }
                    myint2+=mcp;
                }
            }
            else{
                spanU = FindSpan(ncp, degU, us[twojj], knotU);
                BasisFuns(spanU, us[twojj], degU, knotU, NU, leftU, rightU);
                
                spanV = FindSpan(kcp, degV, us[twojj+1], knotV);
                BasisFuns(spanV, us[twojj+1], degV, knotV, NV, leftV, rightV);
                
                ind = (spanU-degU)*mcp;
                
                myint1=(spanV-degV)*mcpncp;
                
                for (i = 0; i <= degV; i++){
                    myint2=ind+myint1;
                    for (j = 0; j <= degU; j++){
                        NN=NV[i] * NU[j];
                        for (ii = 0; ii < mcp; ii++){
                            ep[jjmcp+ii] += NN * cp[myint2+ii];
                        }
                        myint2+=mcp;
                    }
                    myint1+=mcpncp;
                }
            }
        }
        
        jjmcp+=mcp;
        twojj+=2;
        
    }
    
}
