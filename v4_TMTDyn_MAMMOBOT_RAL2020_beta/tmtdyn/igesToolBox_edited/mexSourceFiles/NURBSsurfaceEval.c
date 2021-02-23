
/* Written by Per Bergström */

static void NURBSsurfaceEval(int degU, int degV, double *cp, int ncp, int kcp, double *knotU, double *knotV, double *us, unsigned int nus, double *ep, double *leftU, double *rightU, double *NU, double *leftV, double *rightV, double *NV){
    /* Modification of  ALGORITHM A4.3, The NURBS Book, L.Piegl and W. Tiller */
    
    /* Evaluates a NURBS surface at given parameter values */
    
    /* NURBSsurfaceEval( degU - degree of NURBS in u, degV - degree of NURBS in v, cp - pointer to control points, ncp - number of control points in u, kcp - number of control points in v, knotU - pointer to knot sequence in u, knotV - pointer to knot sequence in v, us - pointer to parameter values,  nus - number of parameter values, ep - pointer to evaluated points, leftU - pointer to array for function BasisFuns, rightU - pointer to array for function BasisFuns, NU - pointer to array for function BasisFuns, leftV - pointer to array for function BasisFuns, rightV - pointer to array for function BasisFuns, NV - pointer to array for function BasisFuns) */
    
    unsigned short int i, j, spanU, spanV, ind, ind2, fourncp, myint;
    unsigned int jj, threejj;
    double wgh, NN;
    
    fourncp = 4*ncp;
    
    for (jj = 0; jj < nus; jj++){
        
        threejj = 3*jj;
        
        if (us[2*jj] <= knotU[degU]){
            
            if (us[2*jj+1] <= knotV[degV]){
                
                ep[threejj] = cp[0]/cp[3];
                ep[threejj+1] = cp[1]/cp[3];
                ep[threejj+2] = cp[2]/cp[3];
                
            }
            else if (us[2*jj+1] >= knotV[kcp]){
                
                myint = fourncp*(kcp-1);
                ep[threejj] = cp[myint]/cp[myint+3];
                ep[threejj+1] = cp[myint+1]/cp[myint+3];
                ep[threejj+2] = cp[myint+2]/cp[myint+3];
                
            }
            else {
                
                ep[threejj] = 0.0;
                ep[threejj+1] = 0.0;
                ep[threejj+2] = 0.0;
                wgh = 0.0;
                
                spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                
                ind = spanV - degV;
                
                for (i = 0; i <= degV; i++){
                    myint = (ind+i)*fourncp;
                    ep[threejj] += NV[i] * cp[myint];
                    ep[threejj+1] += NV[i] * cp[myint+1];
                    ep[threejj+2] += NV[i] * cp[myint+2];
                    wgh += NV[i] * cp[myint+3];
                }
                ep[threejj] = ep[threejj]/wgh;
                ep[threejj+1] = ep[threejj+1]/wgh;
                ep[threejj+2] = ep[threejj+2]/wgh;
                
            }
            
        }
        else if (us[2*jj] >= knotU[ncp]){
            
            if (us[2*jj+1] <= knotV[degV]){
                
                ep[threejj] = cp[fourncp-4]/cp[fourncp-1];
                ep[threejj+1] = cp[fourncp-3]/cp[fourncp-1];
                ep[threejj+2] = cp[fourncp-2]/cp[fourncp-1];
                
            }
            else if (us[2*jj+1] >= knotV[kcp]){
                
                myint = fourncp*kcp;
                ep[threejj] = cp[myint-4]/cp[myint-1];
                ep[threejj+1] = cp[myint-3]/cp[myint-1];
                ep[threejj+2] = cp[myint-2]/cp[myint-1];
                
            }
            else {
                
                ep[threejj] = 0.0;
                ep[threejj+1] = 0.0;
                ep[threejj+2] = 0.0;
                wgh = 0.0;
                
                spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                
                ind = spanV - degV;
                myint = (ind+1)*fourncp;
                
                for (i = 0; i <= degV; i++){
                    ep[threejj] += NV[i] * cp[i*fourncp+myint-4];
                    ep[threejj+1] += NV[i] * cp[i*fourncp+myint-3];
                    ep[threejj+2] += NV[i] * cp[i*fourncp+myint-2];
                    wgh += NV[i] * cp[i*fourncp+myint-1];
                }
                ep[threejj] = ep[threejj]/wgh;
                ep[threejj+1] = ep[threejj+1]/wgh;
                ep[threejj+2] = ep[threejj+2]/wgh;
                
            }
            
        }
        else {
            
            ep[threejj] = 0.0;
            ep[threejj+1] = 0.0;
            ep[threejj+2] = 0.0;
            wgh = 0.0;
            
            if (us[2*jj+1] <= knotV[degV]){
                
                spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                
                ind = spanU - degU;
                
                for (i = 0; i <= degU; i++){
                    ep[threejj] += NU[i] * cp[(ind+i)*4];
                    ep[threejj+1] += NU[i] * cp[(ind+i)*4+1];
                    ep[threejj+2] += NU[i] * cp[(ind+i)*4+2];
                    wgh += NU[i] * cp[(ind+i)*4+3];
                }
                ep[threejj] = ep[threejj]/wgh;
                ep[threejj+1] = ep[threejj+1]/wgh;
                ep[threejj+2] = ep[threejj+2]/wgh;
                
            }
            else if (us[2*jj+1] >= knotV[kcp]){
                
                spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                
                ind = spanU - degU;
                myint = ind*4+(kcp-1)*fourncp;
                
                for (i = 0; i <= degU; i++){
                    ep[threejj] += NU[i] * cp[i*4+myint];
                    ep[threejj+1] += NU[i] * cp[i*4+myint+1];
                    ep[threejj+2] += NU[i] * cp[i*4+myint+2];
                    wgh += NU[i] * cp[i*4+myint+3];
                }
                ep[threejj] = ep[threejj]/wgh;
                ep[threejj+1] = ep[threejj+1]/wgh;
                ep[threejj+2] = ep[threejj+2]/wgh;
                
            }
            else {
                
                spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                
                spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                
                ind = spanU - degU;
                ind2 = spanV - degV;
                myint = ind2*fourncp+ind*4;
                
                for (i = 0; i <= degV; i++){
                    for (j = 0; j <= degU; j++){
                        NN = NV[i] * NU[j];
                        ep[threejj] += NN * cp[i*fourncp+j*4+myint];
                        ep[threejj+1] += NN * cp[i*fourncp+j*4+myint+1];
                        ep[threejj+2] += NN * cp[i*fourncp+j*4+myint+2];
                        wgh += NN * cp[i*fourncp+j*4+myint+3];
                    }
                }
                ep[threejj] = ep[threejj]/wgh;
                ep[threejj+1] = ep[threejj+1]/wgh;
                ep[threejj+2] = ep[threejj+2]/wgh;
                
            }
            
        }
        
    }
    
}


static void NURBSsurfaceDeval(int degU, int degV, double *cp, double *ducp, double *dvcp, int ncp, int kcp, double *knotU, double *knotV, double *us, unsigned int nus, double *ep, double *duep, double *dvep, double *leftU, double *rightU, double *NU, double *leftV, double *rightV, double *NV){
    /* Modification of  ALGORITHM A4.3, The NURBS Book, L.Piegl and W. Tiller */
    
    /* Evaluates a NURBS surface at given parameter values */
    
    /* NURBSsurfaceDeval( degU - degree of NURBS in u, degV - degree of NURBS in v, cp - pointer to control points, ducp - pointer to du control points, dvcp - pointer to dv control points, ncp - number of control points in u, kcp - number of control points in v, knotU - pointer to knot sequence in u, knotV - pointer to knot sequence in v, us - pointer to parameter values,  nus - number of parameter values, ep - pointer to evaluated points, duep - pointer to evaluated points, dvep - pointer to evaluated points, leftU - pointer to array for function BasisFuns, rightU - pointer to array for function BasisFuns, NU - pointer to array for function BasisFuns, leftV - pointer to array for function BasisFuns, rightV - pointer to array for function BasisFuns, NV - pointer to array for function BasisFuns) */
    
    unsigned short int i, j, spanU, spanV, ind, ind2, fourncp, fourncpm4, myint;
    unsigned int jj, threejj;
    double wgh, dwgh, NN;
    
    fourncp = 4*ncp;
    fourncpm4 = fourncp - 4;
    
    if (degU>0){
        
        if (degV>0){
            
            for (jj = 0; jj < nus; jj++){
                
                threejj = 3*jj;
                
                if (us[2*jj] <= knotU[degU]){
                    
                    if (us[2*jj+1] <= knotV[degV]){
                        
                        wgh = cp[3];
                        ep[threejj] = cp[0]/wgh;
                        ep[threejj+1] = cp[1]/wgh;
                        ep[threejj+2] = cp[2]/wgh;
                        
                        duep[threejj] = (ducp[0] - ducp[3]*ep[threejj])/wgh;
                        duep[threejj+1] = (ducp[1] - ducp[3]*ep[threejj+1])/wgh;
                        duep[threejj+2] = (ducp[2] - ducp[3]*ep[threejj+2])/wgh;
                        
                        dvep[threejj] = (dvcp[0] - dvcp[3]*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvcp[1] - dvcp[3]*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvcp[2] - dvcp[3]*ep[threejj+2])/wgh;
                        
                    }
                    else if (us[2*jj+1] >= knotV[kcp]){
                        
                        myint = fourncp*(kcp-1);
                        wgh = cp[myint+3];
                        ep[threejj] = cp[myint]/wgh;
                        ep[threejj+1] = cp[myint+1]/wgh;
                        ep[threejj+2] = cp[myint+2]/wgh;
                        
                        myint = fourncpm4*(kcp-1);
                        duep[threejj] = (ducp[myint] - ducp[myint+3]*ep[threejj])/wgh;
                        duep[threejj+1] = (ducp[myint+1] - ducp[myint+3]*ep[threejj+1])/wgh;
                        duep[threejj+2] = (ducp[myint+2] - ducp[myint+3]*ep[threejj+2])/wgh;
                        
                        myint = fourncp*(kcp-2);
                        dvep[threejj] = (dvcp[myint] - dvcp[myint+3]*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvcp[myint+1] - dvcp[myint+3]*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvcp[myint+2] - dvcp[myint+3]*ep[threejj+2])/wgh;
                        
                    }
                    else {
                        
                        ep[threejj] = 0.0;
                        ep[threejj+1] = 0.0;
                        ep[threejj+2] = 0.0;
                        wgh = 0.0;
                        
                        spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        ind = spanV - degV;
                        
                        for (i = 0; i <= degV; i++){
                            myint = (ind+i)*fourncp;
                            ep[threejj] += NV[i] * cp[myint];
                            ep[threejj+1] += NV[i] * cp[myint+1];
                            ep[threejj+2] += NV[i] * cp[myint+2];
                            wgh += NV[i] * cp[myint+3];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        dwgh = 0.0;
                        
                        for (i = 0; i <= degV; i++){
                            myint = (ind+i)*fourncpm4;
                            duep[threejj] += NV[i] * ducp[myint];
                            duep[threejj+1] += NV[i] * ducp[myint+1];
                            duep[threejj+2] += NV[i] * ducp[myint+2];
                            dwgh += NV[i] * ducp[myint+3];
                        }
                        duep[threejj] = (duep[threejj] - dwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (duep[threejj+1] - dwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (duep[threejj+2] - dwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanV-1, us[2*jj+1], degV-1, &knotV[1], NV, leftV, rightV);
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        dwgh = 0.0;
                        
                        for (i = 0; i < degV; i++){
                            myint = (ind+i)*fourncp;
                            dvep[threejj] += NV[i] * dvcp[myint];
                            dvep[threejj+1] += NV[i] * dvcp[myint+1];
                            dvep[threejj+2] += NV[i] * dvcp[myint+2];
                            dwgh += NV[i] * dvcp[myint+3];
                        }
                        dvep[threejj] = (dvep[threejj] - dwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvep[threejj+1] - dwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvep[threejj+2] - dwgh*ep[threejj+2])/wgh;
                        
                    }
                    
                }
                else if (us[2*jj] >= knotU[ncp]){
                    
                    if (us[2*jj+1] <= knotV[degV]){
                        
                        wgh = cp[fourncp-1];
                        ep[threejj] = cp[fourncpm4]/wgh;
                        ep[threejj+1] = cp[fourncpm4+1]/wgh;
                        ep[threejj+2] = cp[fourncpm4+2]/wgh;
                        
                        duep[threejj] = (ducp[fourncpm4-4] - ducp[fourncpm4-1]*ep[threejj])/wgh;
                        duep[threejj+1] = (ducp[fourncpm4-3] - ducp[fourncpm4-1]*ep[threejj+1])/wgh;
                        duep[threejj+2] = (ducp[fourncpm4-2] - ducp[fourncpm4-1]*ep[threejj+2])/wgh;
                        
                        dvep[threejj] = (dvcp[fourncpm4] - dvcp[fourncpm4+3]*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvcp[fourncpm4+1] - dvcp[fourncpm4+3]*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvcp[fourncpm4+2] - dvcp[fourncpm4+3]*ep[threejj+2])/wgh;
                        
                    }
                    else if (us[2*jj+1] >= knotV[kcp]){
                        
                        myint = fourncp*kcp;
                        wgh = cp[myint-1];
                        ep[threejj] = cp[myint-4]/wgh;
                        ep[threejj+1] = cp[myint-3]/wgh;
                        ep[threejj+2] = cp[myint-2]/wgh;
                        
                        myint = fourncpm4*kcp-4;
                        duep[threejj] = (ducp[myint] - ducp[myint+3]*ep[threejj])/wgh;
                        duep[threejj+1] = (ducp[myint+1] - ducp[myint+3]*ep[threejj+1])/wgh;
                        duep[threejj+2] = (ducp[myint+2] - ducp[myint+3]*ep[threejj+2])/wgh;
                        
                        myint = fourncp*(kcp-1)-4;
                        dvep[threejj] = (dvcp[myint] - dvcp[myint+3]*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvcp[myint+1] - dvcp[myint+3]*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvcp[myint+2] - dvcp[myint+3]*ep[threejj+2])/wgh;
                        
                    }
                    else {
                        
                        ep[threejj] = 0.0;
                        ep[threejj+1] = 0.0;
                        ep[threejj+2] = 0.0;
                        wgh = 0.0;
                        
                        spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        ind = spanV - degV;
                        myint = (ind+1)*fourncp;
                        
                        for (i = 0; i <= degV; i++){
                            ep[threejj] += NV[i] * cp[i*fourncp+myint-4];
                            ep[threejj+1] += NV[i] * cp[i*fourncp+myint-3];
                            ep[threejj+2] += NV[i] * cp[i*fourncp+myint-2];
                            wgh += NV[i] * cp[i*fourncp+myint-1];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        dwgh = 0.0;
                        
                        ind++;
                        
                        for (i = 0; i <= degV; i++){
                            myint = (ind+i)*fourncpm4 - 4;
                            duep[threejj] += NV[i] * ducp[myint];
                            duep[threejj+1] += NV[i] * ducp[myint+1];
                            duep[threejj+2] += NV[i] * ducp[myint+2];
                            dwgh += NV[i] * ducp[myint+3];
                        }
                        duep[threejj] = (duep[threejj] - dwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (duep[threejj+1] - dwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (duep[threejj+2] - dwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanV-1, us[2*jj+1], degV-1, &knotV[1], NV, leftV, rightV);
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        dwgh = 0.0;
                        
                        for (i = 0; i < degV; i++){
                            myint = (ind+i)*fourncp - 4;
                            dvep[threejj] += NV[i] * dvcp[myint];
                            dvep[threejj+1] += NV[i] * dvcp[myint+1];
                            dvep[threejj+2] += NV[i] * dvcp[myint+2];
                            dwgh += NV[i] * dvcp[myint+3];
                        }
                        dvep[threejj] = (dvep[threejj] - dwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvep[threejj+1] - dwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvep[threejj+2] - dwgh*ep[threejj+2])/wgh;
                        
                    }
                    
                }
                else {
                    
                    ep[threejj] = 0.0;
                    ep[threejj+1] = 0.0;
                    ep[threejj+2] = 0.0;
                    wgh = 0.0;
                    
                    duep[threejj] = 0.0;
                    duep[threejj+1] = 0.0;
                    duep[threejj+2] = 0.0;
                    
                    dvep[threejj] = 0.0;
                    dvep[threejj+1] = 0.0;
                    dvep[threejj+2] = 0.0;
                    dwgh = 0.0;
                    
                    if (us[2*jj+1] <= knotV[degV]){
                        
                        spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                        BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                        
                        ind = spanU - degU;
                        
                        for (i = 0; i <= degU; i++){
                            ep[threejj] += NU[i] * cp[(ind+i)*4];
                            ep[threejj+1] += NU[i] * cp[(ind+i)*4+1];
                            ep[threejj+2] += NU[i] * cp[(ind+i)*4+2];
                            wgh += NU[i] * cp[(ind+i)*4+3];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        for (i = 0; i <= degU; i++){
                            dvep[threejj] += NU[i] * dvcp[(ind+i)*4];
                            dvep[threejj+1] += NU[i] * dvcp[(ind+i)*4+1];
                            dvep[threejj+2] += NU[i] * dvcp[(ind+i)*4+2];
                            dwgh += NU[i] * dvcp[(ind+i)*4+3];
                        }
                        dvep[threejj] = (dvep[threejj] - dwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvep[threejj+1] - dwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvep[threejj+2] - dwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanU-1, us[2*jj], degU-1, &knotU[1], NU, leftU, rightU);
                        
                        dwgh = 0.0;
                        
                        for (i = 0; i < degU; i++){
                            duep[threejj] += NU[i] * ducp[(ind+i)*4];
                            duep[threejj+1] += NU[i] * ducp[(ind+i)*4+1];
                            duep[threejj+2] += NU[i] * ducp[(ind+i)*4+2];
                            dwgh += NU[i] * ducp[(ind+i)*4+3];
                        }
                        duep[threejj] = (duep[threejj] - dwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (duep[threejj+1] - dwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (duep[threejj+2] - dwgh*ep[threejj+2])/wgh;
                        
                    }
                    else if (us[2*jj+1] >= knotV[kcp]){
                        
                        spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                        BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                        
                        ind = spanU - degU;
                        myint = ind*4+(kcp-1)*fourncp;
                        
                        for (i = 0; i <= degU; i++){
                            ep[threejj] += NU[i] * cp[i*4+myint];
                            ep[threejj+1] += NU[i] * cp[i*4+myint+1];
                            ep[threejj+2] += NU[i] * cp[i*4+myint+2];
                            wgh += NU[i] * cp[i*4+myint+3];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        ind += ncp*(kcp-2);
                        
                        for (i = 0; i <= degU; i++){
                            dvep[threejj] += NU[i] * dvcp[(ind+i)*4];
                            dvep[threejj+1] += NU[i] * dvcp[(ind+i)*4+1];
                            dvep[threejj+2] += NU[i] * dvcp[(ind+i)*4+2];
                            dwgh += NU[i] * dvcp[(ind+i)*4+3];
                        }
                        dvep[threejj] = (dvep[threejj] - dwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvep[threejj+1] - dwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvep[threejj+2] - dwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanU-1, us[2*jj], degU-1, &knotU[1], NU, leftU, rightU);
                        
                        dwgh = 0.0;
                        
                        ind = spanU - degU + (ncp-1)*(kcp-1);
                        
                        for (i = 0; i < degU; i++){
                            duep[threejj] += NU[i] * ducp[(ind+i)*4];
                            duep[threejj+1] += NU[i] * ducp[(ind+i)*4+1];
                            duep[threejj+2] += NU[i] * ducp[(ind+i)*4+2];
                            dwgh += NU[i] * ducp[(ind+i)*4+3];
                        }
                        duep[threejj] = (duep[threejj] - dwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (duep[threejj+1] - dwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (duep[threejj+2] - dwgh*ep[threejj+2])/wgh;
                        
                    }
                    else {
                        
                        spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                        BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                        
                        spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        ind = spanU - degU;
                        ind2 = spanV - degV;
                        myint = ind2*fourncp+ind*4;
                        
                        for (i = 0; i <= degV; i++){
                            for (j = 0; j <= degU; j++){
                                NN = NV[i] * NU[j];
                                ep[threejj] += NN * cp[i*fourncp+j*4+myint];
                                ep[threejj+1] += NN * cp[i*fourncp+j*4+myint+1];
                                ep[threejj+2] += NN * cp[i*fourncp+j*4+myint+2];
                                wgh += NN * cp[i*fourncp+j*4+myint+3];
                            }
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        BasisFuns(spanV-1, us[2*jj+1], degV-1, &knotV[1], NV, leftV, rightV);
                        
                        for (i = 0; i < degV; i++){
                            for (j = 0; j <= degU; j++){
                                NN = NV[i] * NU[j];
                                dvep[threejj] += NN * dvcp[i*fourncp+j*4+myint];
                                dvep[threejj+1] += NN * dvcp[i*fourncp+j*4+myint+1];
                                dvep[threejj+2] += NN * dvcp[i*fourncp+j*4+myint+2];
                                dwgh += NN * dvcp[i*fourncp+j*4+myint+3];
                            }
                        }
                        dvep[threejj] = (dvep[threejj] - dwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvep[threejj+1] - dwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvep[threejj+2] - dwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanU-1, us[2*jj], degU-1, &knotU[1], NU, leftU, rightU);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        myint = ind2*fourncpm4+ind*4;
                        
                        dwgh = 0.0;
                        
                        for (i = 0; i <= degV; i++){
                            for (j = 0; j < degU; j++){
                                NN = NV[i] * NU[j];
                                duep[threejj] += NN * ducp[i*fourncpm4+j*4+myint];
                                duep[threejj+1] += NN * ducp[i*fourncpm4+j*4+myint+1];
                                duep[threejj+2] += NN * ducp[i*fourncpm4+j*4+myint+2];
                                dwgh += NN * ducp[i*fourncpm4+j*4+myint+3];
                            }
                        }
                        duep[threejj] = (duep[threejj] - dwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (duep[threejj+1] - dwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (duep[threejj+2] - dwgh*ep[threejj+2])/wgh;
                        
                    }
                    
                }
                
            }
            
        }
        else {
            
            for (jj = 0; jj < nus; jj++){
                
                threejj = 3*jj;
                
                if (us[2*jj] <= knotU[degU]){
                    
                    if (us[2*jj+1] <= knotV[degV]){
                        
                        wgh = cp[3];
                        ep[threejj] = cp[0]/wgh;
                        ep[threejj+1] = cp[1]/wgh;
                        ep[threejj+2] = cp[2]/wgh;
                        
                        duep[threejj] = (ducp[0] - ducp[3]*ep[threejj])/wgh;
                        duep[threejj+1] = (ducp[1] - ducp[3]*ep[threejj+1])/wgh;
                        duep[threejj+2] = (ducp[2] - ducp[3]*ep[threejj+2])/wgh;
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        
                    }
                    else if (us[2*jj+1] >= knotV[kcp]){
                        
                        myint = fourncp*(kcp-1);
                        wgh = cp[myint+3];
                        ep[threejj] = cp[myint]/wgh;
                        ep[threejj+1] = cp[myint+1]/wgh;
                        ep[threejj+2] = cp[myint+2]/wgh;
                        
                        myint = fourncpm4*(kcp-1);
                        duep[threejj] = (ducp[myint] - ducp[myint+3]*ep[threejj])/wgh;
                        duep[threejj+1] = (ducp[myint+1] - ducp[myint+3]*ep[threejj+1])/wgh;
                        duep[threejj+2] = (ducp[myint+2] - ducp[myint+3]*ep[threejj+2])/wgh;
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        
                    }
                    else {
                        
                        ep[threejj] = 0.0;
                        ep[threejj+1] = 0.0;
                        ep[threejj+2] = 0.0;
                        wgh = 0.0;
                        
                        spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        ind = spanV - degV;
                        
                        for (i = 0; i <= degV; i++){
                            myint = (ind+i)*fourncp;
                            ep[threejj] += NV[i] * cp[myint];
                            ep[threejj+1] += NV[i] * cp[myint+1];
                            ep[threejj+2] += NV[i] * cp[myint+2];
                            wgh += NV[i] * cp[myint+3];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        dwgh = 0.0;
                        
                        for (i = 0; i <= degV; i++){
                            myint = (ind+i)*fourncpm4;
                            duep[threejj] += NV[i] * ducp[myint];
                            duep[threejj+1] += NV[i] * ducp[myint+1];
                            duep[threejj+2] += NV[i] * ducp[myint+2];
                            dwgh += NV[i] * ducp[myint+3];
                        }
                        duep[threejj] = (duep[threejj] - dwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (duep[threejj+1] - dwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (duep[threejj+2] - dwgh*ep[threejj+2])/wgh;
                        
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        
                    }
                    
                }
                else if (us[2*jj] >= knotU[ncp]){
                    
                    if (us[2*jj+1] <= knotV[degV]){
                        
                        wgh = cp[fourncp-1];
                        ep[threejj] = cp[fourncpm4]/wgh;
                        ep[threejj+1] = cp[fourncpm4+1]/wgh;
                        ep[threejj+2] = cp[fourncpm4+2]/wgh;
                        
                        duep[threejj] = (ducp[fourncpm4-4] - ducp[fourncpm4-1]*ep[threejj])/wgh;
                        duep[threejj+1] = (ducp[fourncpm4-3] - ducp[fourncpm4-1]*ep[threejj+1])/wgh;
                        duep[threejj+2] = (ducp[fourncpm4-2] - ducp[fourncpm4-1]*ep[threejj+2])/wgh;
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        
                    }
                    else if (us[2*jj+1] >= knotV[kcp]){
                        
                        myint = fourncp*kcp;
                        wgh = cp[myint-1];
                        ep[threejj] = cp[myint-4]/wgh;
                        ep[threejj+1] = cp[myint-3]/wgh;
                        ep[threejj+2] = cp[myint-2]/wgh;
                        
                        myint = fourncpm4*kcp-4;
                        duep[threejj] = (ducp[myint] - ducp[myint+3]*ep[threejj])/wgh;
                        duep[threejj+1] = (ducp[myint+1] - ducp[myint+3]*ep[threejj+1])/wgh;
                        duep[threejj+2] = (ducp[myint+2] - ducp[myint+3]*ep[threejj+2])/wgh;
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        
                    }
                    else {
                        
                        ep[threejj] = 0.0;
                        ep[threejj+1] = 0.0;
                        ep[threejj+2] = 0.0;
                        wgh = 0.0;
                        
                        spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        ind = spanV - degV;
                        myint = (ind+1)*fourncp-4;
                        
                        for (i = 0; i <= degV; i++){
                            ep[threejj] += NV[i] * cp[i*fourncp+myint];
                            ep[threejj+1] += NV[i] * cp[i*fourncp+myint+1];
                            ep[threejj+2] += NV[i] * cp[i*fourncp+myint+2];
                            wgh += NV[i] * cp[i*fourncp+myint+3];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        dwgh = 0.0;
                        
                        ind++;
                        
                        for (i = 0; i <= degV; i++){
                            myint = (ind+i)*fourncpm4 - 4;
                            duep[threejj] += NV[i] * ducp[myint];
                            duep[threejj+1] += NV[i] * ducp[myint+1];
                            duep[threejj+2] += NV[i] * ducp[myint+2];
                            dwgh += NV[i] * ducp[myint+3];
                        }
                        duep[threejj] = (duep[threejj] - dwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (duep[threejj+1] - dwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (duep[threejj+2] - dwgh*ep[threejj+2])/wgh;
                        
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        
                    }
                    
                }
                else {
                    
                    ep[threejj] = 0.0;
                    ep[threejj+1] = 0.0;
                    ep[threejj+2] = 0.0;
                    wgh = 0.0;
                    
                    duep[threejj] = 0.0;
                    duep[threejj+1] = 0.0;
                    duep[threejj+2] = 0.0;
                    
                    dvep[threejj] = 0.0;
                    dvep[threejj+1] = 0.0;
                    dvep[threejj+2] = 0.0;
                    dwgh = 0.0;
                    
                    if (us[2*jj+1] <= knotV[degV]){
                        
                        spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                        BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                        
                        ind = spanU - degU;
                        
                        for (i = 0; i <= degU; i++){
                            ep[threejj] += NU[i] * cp[(ind+i)*4];
                            ep[threejj+1] += NU[i] * cp[(ind+i)*4+1];
                            ep[threejj+2] += NU[i] * cp[(ind+i)*4+2];
                            wgh += NU[i] * cp[(ind+i)*4+3];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        BasisFuns(spanU-1, us[2*jj], degU-1, &knotU[1], NU, leftU, rightU);
                        
                        for (i = 0; i < degU; i++){
                            duep[threejj] += NU[i] * ducp[(ind+i)*4];
                            duep[threejj+1] += NU[i] * ducp[(ind+i)*4+1];
                            duep[threejj+2] += NU[i] * ducp[(ind+i)*4+2];
                            dwgh += NU[i] * ducp[(ind+i)*4+3];
                        }
                        duep[threejj] = (duep[threejj] - dwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (duep[threejj+1] - dwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (duep[threejj+2] - dwgh*ep[threejj+2])/wgh;
                        
                    }
                    else if (us[2*jj+1] >= knotV[kcp]){
                        
                        spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                        BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                        
                        ind = spanU - degU;
                        myint = ind*4+(kcp-1)*fourncp;
                        
                        for (i = 0; i <= degU; i++){
                            ep[threejj] += NU[i] * cp[i*4+myint];
                            ep[threejj+1] += NU[i] * cp[i*4+myint+1];
                            ep[threejj+2] += NU[i] * cp[i*4+myint+2];
                            wgh += NU[i] * cp[i*4+myint+3];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        BasisFuns(spanU-1, us[2*jj], degU-1, &knotU[1], NU, leftU, rightU);
                        
                        ind = spanU - degU + (ncp-1)*(kcp-1);
                        
                        for (i = 0; i < degU; i++){
                            duep[threejj] += NU[i] * ducp[(ind+i)*4];
                            duep[threejj+1] += NU[i] * ducp[(ind+i)*4+1];
                            duep[threejj+2] += NU[i] * ducp[(ind+i)*4+2];
                            dwgh += NU[i] * ducp[(ind+i)*4+3];
                        }
                        duep[threejj] = (duep[threejj] - dwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (duep[threejj+1] - dwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (duep[threejj+2] - dwgh*ep[threejj+2])/wgh;
                        
                    }
                    else {
                        
                        spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                        BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                        
                        spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        ind = spanU - degU;
                        ind2 = spanV - degV;
                        myint = ind2*fourncp+ind*4;
                        
                        for (i = 0; i <= degV; i++){
                            for (j = 0; j <= degU; j++){
                                NN = NV[i] * NU[j];
                                ep[threejj] += NN * cp[i*fourncp+j*4+myint];
                                ep[threejj+1] += NN * cp[i*fourncp+j*4+myint+1];
                                ep[threejj+2] += NN * cp[i*fourncp+j*4+myint+2];
                                wgh += NN * cp[i*fourncp+j*4+myint+3];
                            }
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        BasisFuns(spanU-1, us[2*jj], degU-1, &knotU[1], NU, leftU, rightU);
                        
                        myint = ind2*fourncpm4+ind*4;
                        
                        for (i = 0; i <= degV; i++){
                            for (j = 0; j < degU; j++){
                                NN = NV[i] * NU[j];
                                duep[threejj] += NN * ducp[i*fourncpm4+j*4+myint];
                                duep[threejj+1] += NN * ducp[i*fourncpm4+j*4+myint+1];
                                duep[threejj+2] += NN * ducp[i*fourncpm4+j*4+myint+2];
                                dwgh += NN * ducp[i*fourncpm4+j*4+myint+3];
                            }
                        }
                        duep[threejj] = (duep[threejj] - dwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (duep[threejj+1] - dwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (duep[threejj+2] - dwgh*ep[threejj+2])/wgh;
                        
                    }
                    
                }
                
            }
            
        }
        
    }
    else {
        
        if (degV>0){
            
            for (jj = 0; jj < nus; jj++){
                
                threejj = 3*jj;
                
                if (us[2*jj] <= knotU[degU]){
                    
                    if (us[2*jj+1] <= knotV[degV]){
                        
                        wgh = cp[3];
                        ep[threejj] = cp[0]/wgh;
                        ep[threejj+1] = cp[1]/wgh;
                        ep[threejj+2] = cp[2]/wgh;
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        
                        dvep[threejj] = (dvcp[0] - dvcp[3]*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvcp[1] - dvcp[3]*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvcp[2] - dvcp[3]*ep[threejj+2])/wgh;
                        
                    }
                    else if (us[2*jj+1] >= knotV[kcp]){
                        
                        myint = fourncp*(kcp-1);
                        wgh = cp[myint+3];
                        ep[threejj] = cp[myint]/wgh;
                        ep[threejj+1] = cp[myint+1]/wgh;
                        ep[threejj+2] = cp[myint+2]/wgh;
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        
                        myint = fourncp*(kcp-2);
                        dvep[threejj] = (dvcp[myint] - dvcp[myint+3]*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvcp[myint+1] - dvcp[myint+3]*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvcp[myint+2] - dvcp[myint+3]*ep[threejj+2])/wgh;
                        
                    }
                    else {
                        
                        ep[threejj] = 0.0;
                        ep[threejj+1] = 0.0;
                        ep[threejj+2] = 0.0;
                        wgh = 0.0;
                        
                        spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        ind = spanV - degV;
                        
                        for (i = 0; i <= degV; i++){
                            myint = (ind+i)*fourncp;
                            ep[threejj] += NV[i] * cp[myint];
                            ep[threejj+1] += NV[i] * cp[myint+1];
                            ep[threejj+2] += NV[i] * cp[myint+2];
                            wgh += NV[i] * cp[myint+3];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        
                        
                        BasisFuns(spanV-1, us[2*jj+1], degV-1, &knotV[1], NV, leftV, rightV);
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        dwgh = 0.0;
                        
                        for (i = 0; i < degV; i++){
                            myint = (ind+i)*fourncp;
                            dvep[threejj] += NV[i] * dvcp[myint];
                            dvep[threejj+1] += NV[i] * dvcp[myint+1];
                            dvep[threejj+2] += NV[i] * dvcp[myint+2];
                            dwgh += NV[i] * dvcp[myint+3];
                        }
                        dvep[threejj] = (dvep[threejj] - dwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvep[threejj+1] - dwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvep[threejj+2] - dwgh*ep[threejj+2])/wgh;
                        
                    }
                    
                }
                else if (us[2*jj] >= knotU[ncp]){
                    
                    if (us[2*jj+1] <= knotV[degV]){
                        
                        wgh = cp[fourncp-1];
                        ep[threejj] = cp[fourncpm4]/wgh;
                        ep[threejj+1] = cp[fourncpm4+1]/wgh;
                        ep[threejj+2] = cp[fourncpm4+2]/wgh;
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        
                        dvep[threejj] = (dvcp[fourncpm4] - dvcp[fourncpm4+3]*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvcp[fourncpm4+1] - dvcp[fourncpm4+3]*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvcp[fourncpm4+2] - dvcp[fourncpm4+3]*ep[threejj+2])/wgh;
                        
                    }
                    else if (us[2*jj+1] >= knotV[kcp]){
                        
                        myint = fourncp*kcp;
                        wgh = cp[myint-1];
                        ep[threejj] = cp[myint-4]/wgh;
                        ep[threejj+1] = cp[myint-3]/wgh;
                        ep[threejj+2] = cp[myint-2]/wgh;
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        
                        myint = fourncp*(kcp-1)-4;
                        dvep[threejj] = (dvcp[myint] - dvcp[myint+3]*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvcp[myint+1] - dvcp[myint+3]*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvcp[myint+2] - dvcp[myint+3]*ep[threejj+2])/wgh;
                        
                    }
                    else {
                        
                        ep[threejj] = 0.0;
                        ep[threejj+1] = 0.0;
                        ep[threejj+2] = 0.0;
                        wgh = 0.0;
                        
                        spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        ind = spanV - degV;
                        myint = (ind+1)*fourncp;
                        
                        for (i = 0; i <= degV; i++){
                            ep[threejj] += NV[i] * cp[i*fourncp+myint-4];
                            ep[threejj+1] += NV[i] * cp[i*fourncp+myint-3];
                            ep[threejj+2] += NV[i] * cp[i*fourncp+myint-2];
                            wgh += NV[i] * cp[i*fourncp+myint-1];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        
                        ind++;
                        
                        BasisFuns(spanV-1, us[2*jj+1], degV-1, &knotV[1], NV, leftV, rightV);
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        dwgh = 0.0;
                        
                        for (i = 0; i < degV; i++){
                            myint = (ind+i)*fourncp - 4;
                            dvep[threejj] += NV[i] * dvcp[myint];
                            dvep[threejj+1] += NV[i] * dvcp[myint+1];
                            dvep[threejj+2] += NV[i] * dvcp[myint+2];
                            dwgh += NV[i] * dvcp[myint+3];
                        }
                        dvep[threejj] = (dvep[threejj] - dwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvep[threejj+1] - dwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvep[threejj+2] - dwgh*ep[threejj+2])/wgh;
                        
                    }
                    
                }
                else {
                    
                    ep[threejj] = 0.0;
                    ep[threejj+1] = 0.0;
                    ep[threejj+2] = 0.0;
                    wgh = 0.0;
                    
                    duep[threejj] = 0.0;
                    duep[threejj+1] = 0.0;
                    duep[threejj+2] = 0.0;
                    
                    dvep[threejj] = 0.0;
                    dvep[threejj+1] = 0.0;
                    dvep[threejj+2] = 0.0;
                    dwgh = 0.0;
                    
                    if (us[2*jj+1] <= knotV[degV]){
                        
                        spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                        BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                        
                        ind = spanU - degU;
                        
                        for (i = 0; i <= degU; i++){
                            ep[threejj] += NU[i] * cp[(ind+i)*4];
                            ep[threejj+1] += NU[i] * cp[(ind+i)*4+1];
                            ep[threejj+2] += NU[i] * cp[(ind+i)*4+2];
                            wgh += NU[i] * cp[(ind+i)*4+3];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        for (i = 0; i <= degU; i++){
                            dvep[threejj] += NU[i] * dvcp[(ind+i)*4];
                            dvep[threejj+1] += NU[i] * dvcp[(ind+i)*4+1];
                            dvep[threejj+2] += NU[i] * dvcp[(ind+i)*4+2];
                            dwgh += NU[i] * dvcp[(ind+i)*4+3];
                        }
                        dvep[threejj] = (dvep[threejj] - dwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvep[threejj+1] - dwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvep[threejj+2] - dwgh*ep[threejj+2])/wgh;
                        
                    }
                    else if (us[2*jj+1] >= knotV[kcp]){
                        
                        spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                        BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                        
                        ind = spanU - degU;
                        myint = ind*4+(kcp-1)*fourncp;
                        
                        for (i = 0; i <= degU; i++){
                            ep[threejj] += NU[i] * cp[i*4+myint];
                            ep[threejj+1] += NU[i] * cp[i*4+myint+1];
                            ep[threejj+2] += NU[i] * cp[i*4+myint+2];
                            wgh += NU[i] * cp[i*4+myint+3];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        ind += ncp*(kcp-2);
                        
                        for (i = 0; i <= degU; i++){
                            dvep[threejj] += NU[i] * dvcp[(ind+i)*4];
                            dvep[threejj+1] += NU[i] * dvcp[(ind+i)*4+1];
                            dvep[threejj+2] += NU[i] * dvcp[(ind+i)*4+2];
                            dwgh += NU[i] * dvcp[(ind+i)*4+3];
                        }
                        dvep[threejj] = (dvep[threejj] - dwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvep[threejj+1] - dwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvep[threejj+2] - dwgh*ep[threejj+2])/wgh;
                        
                    }
                    else {
                        
                        spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                        BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                        
                        spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        ind = spanU - degU;
                        ind2 = spanV - degV;
                        myint = ind2*fourncp+ind*4;
                        
                        for (i = 0; i <= degV; i++){
                            for (j = 0; j <= degU; j++){
                                NN = NV[i] * NU[j];
                                ep[threejj] += NN * cp[i*fourncp+j*4+myint];
                                ep[threejj+1] += NN * cp[i*fourncp+j*4+myint+1];
                                ep[threejj+2] += NN * cp[i*fourncp+j*4+myint+2];
                                wgh += NN * cp[i*fourncp+j*4+myint+3];
                            }
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        BasisFuns(spanV-1, us[2*jj+1], degV-1, &knotV[1], NV, leftV, rightV);
                        
                        for (i = 0; i < degV; i++){
                            for (j = 0; j <= degU; j++){
                                NN = NV[i] * NU[j];
                                dvep[threejj] += NN * dvcp[i*fourncp+j*4+myint];
                                dvep[threejj+1] += NN * dvcp[i*fourncp+j*4+myint+1];
                                dvep[threejj+2] += NN * dvcp[i*fourncp+j*4+myint+2];
                                dwgh += NN * dvcp[i*fourncp+j*4+myint+3];
                            }
                        }
                        dvep[threejj] = (dvep[threejj] - dwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvep[threejj+1] - dwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvep[threejj+2] - dwgh*ep[threejj+2])/wgh;
                        
                    }
                    
                }
                
            }
            
        }
        else {
            
            for (jj = 0; jj < nus; jj++){
                
                threejj = 3*jj;
                
                if (us[2*jj] <= knotU[degU]){
                    
                    if (us[2*jj+1] <= knotV[degV]){
                        
                        wgh = cp[3];
                        ep[threejj] = cp[0]/wgh;
                        ep[threejj+1] = cp[1]/wgh;
                        ep[threejj+2] = cp[2]/wgh;
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        
                    }
                    else if (us[2*jj+1] >= knotV[kcp]){
                        
                        myint = fourncp*(kcp-1);
                        wgh = cp[myint+3];
                        ep[threejj] = cp[myint]/wgh;
                        ep[threejj+1] = cp[myint+1]/wgh;
                        ep[threejj+2] = cp[myint+2]/wgh;
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        
                    }
                    else {
                        
                        ep[threejj] = 0.0;
                        ep[threejj+1] = 0.0;
                        ep[threejj+2] = 0.0;
                        wgh = 0.0;
                        
                        spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        ind = spanV - degV;
                        
                        for (i = 0; i <= degV; i++){
                            myint = (ind+i)*fourncp;
                            ep[threejj] += NV[i] * cp[myint];
                            ep[threejj+1] += NV[i] * cp[myint+1];
                            ep[threejj+2] += NV[i] * cp[myint+2];
                            wgh += NV[i] * cp[myint+3];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        
                    }
                    
                }
                else if (us[2*jj] >= knotU[ncp]){
                    
                    if (us[2*jj+1] <= knotV[degV]){
                        
                        wgh = cp[fourncp-1];
                        ep[threejj] = cp[fourncpm4]/wgh;
                        ep[threejj+1] = cp[fourncpm4+1]/wgh;
                        ep[threejj+2] = cp[fourncpm4+2]/wgh;
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        
                    }
                    else if (us[2*jj+1] >= knotV[kcp]){
                        
                        myint = fourncp*kcp;
                        wgh = cp[myint-1];
                        ep[threejj] = cp[myint-4]/wgh;
                        ep[threejj+1] = cp[myint-3]/wgh;
                        ep[threejj+2] = cp[myint-2]/wgh;
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        
                    }
                    else {
                        
                        ep[threejj] = 0.0;
                        ep[threejj+1] = 0.0;
                        ep[threejj+2] = 0.0;
                        wgh = 0.0;
                        
                        spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        ind = spanV - degV;
                        myint = (ind+1)*fourncp;
                        
                        for (i = 0; i <= degV; i++){
                            ep[threejj] += NV[i] * cp[i*fourncp+myint-4];
                            ep[threejj+1] += NV[i] * cp[i*fourncp+myint-3];
                            ep[threejj+2] += NV[i] * cp[i*fourncp+myint-2];
                            wgh += NV[i] * cp[i*fourncp+myint-1];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        
                    }
                    
                }
                else {
                    
                    ep[threejj] = 0.0;
                    ep[threejj+1] = 0.0;
                    ep[threejj+2] = 0.0;
                    wgh = 0.0;
                    
                    duep[threejj] = 0.0;
                    duep[threejj+1] = 0.0;
                    duep[threejj+2] = 0.0;
                    
                    dvep[threejj] = 0.0;
                    dvep[threejj+1] = 0.0;
                    dvep[threejj+2] = 0.0;
                    
                    if (us[2*jj+1] <= knotV[degV]){
                        
                        spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                        BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                        
                        ind = spanU - degU;
                        
                        for (i = 0; i <= degU; i++){
                            ep[threejj] += NU[i] * cp[(ind+i)*4];
                            ep[threejj+1] += NU[i] * cp[(ind+i)*4+1];
                            ep[threejj+2] += NU[i] * cp[(ind+i)*4+2];
                            wgh += NU[i] * cp[(ind+i)*4+3];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                    }
                    else if (us[2*jj+1] >= knotV[kcp]){
                        
                        spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                        BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                        
                        ind = spanU - degU;
                        myint = ind*4+(kcp-1)*fourncp;
                        
                        for (i = 0; i <= degU; i++){
                            ep[threejj] += NU[i] * cp[i*4+myint];
                            ep[threejj+1] += NU[i] * cp[i*4+myint+1];
                            ep[threejj+2] += NU[i] * cp[i*4+myint+2];
                            wgh += NU[i] * cp[i*4+myint+3];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                    }
                    else {
                        
                        spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                        BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                        
                        spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        ind = spanU - degU;
                        ind2 = spanV - degV;
                        myint = ind2*fourncp+ind*4;
                        
                        for (i = 0; i <= degV; i++){
                            for (j = 0; j <= degU; j++){
                                NN = NV[i] * NU[j];
                                ep[threejj] += NN * cp[i*fourncp+j*4+myint];
                                ep[threejj+1] += NN * cp[i*fourncp+j*4+myint+1];
                                ep[threejj+2] += NN * cp[i*fourncp+j*4+myint+2];
                                wgh += NN * cp[i*fourncp+j*4+myint+3];
                            }
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                    }
                    
                }
                
            }
            
        }
        
    }
    
}


static void NURBSsurfaceD2eval(int degU, int degV, double *cp, double *ducp, double *dvcp, double *duucp, double *duvcp, double *dvvcp, int ncp, int kcp, double *knotU, double *knotV, double *us, unsigned int nus, double *ep, double *duep, double *dvep, double *duuep, double *duvep, double *dvvep, double *leftU, double *rightU, double *NU, double *leftV, double *rightV, double *NV){
    /* Modification of  ALGORITHM A4.3, The NURBS Book, L.Piegl and W. Tiller */
    
    /* Evaluates a NURBS surface at given parameter values */
    
    /* NURBSsurfaceD2eval( degU - degree of NURBS in u, degV - degree of NURBS in v, cp - pointer to control points, ducp - pointer to du control points, dvcp - pointer to dv control points, duucp - pointer to duu control points, duvcp - pointer to duv control points, dvvcp - pointer to dvv control points, ncp - number of control points in u, kcp - number of control points in v, knotU - pointer to knot sequence in u, knotV - pointer to knot sequence in v, us - pointer to parameter values,  nus - number of parameter values, ep - pointer to evaluated points, duep - pointer to evaluated points, dvep - pointer to evaluated points, leftU - pointer to array for function BasisFuns, rightU - pointer to array for function BasisFuns, NU - pointer to array for function BasisFuns, leftV - pointer to array for function BasisFuns, rightV - pointer to array for function BasisFuns, NV - pointer to array for function BasisFuns) */
    
    unsigned short int i, j, spanU, spanV, ind, ind2, fourncp, fourncpm4, fourncpm8, myint;
    unsigned int jj, threejj;
    double wgh, duwgh, dvwgh, duuwgh, duvwgh, dvvwgh, NN;
    
    fourncp = 4*ncp;
    fourncpm4 = fourncp - 4;
    fourncpm8 = fourncp - 8;
    
    if (degU>1){
        
        if (degV>1){
            
            for (jj = 0; jj < nus; jj++){
                
                threejj = 3*jj;
                
                if (us[2*jj] <= knotU[degU]){
                    
                    if (us[2*jj+1] <= knotV[degV]){
                        
                        wgh = cp[3];
                        ep[threejj] = cp[0]/wgh;
                        ep[threejj+1] = cp[1]/wgh;
                        ep[threejj+2] = cp[2]/wgh;
                        
                        duep[threejj] = (ducp[0] - ducp[3]*ep[threejj])/wgh;
                        duep[threejj+1] = (ducp[1] - ducp[3]*ep[threejj+1])/wgh;
                        duep[threejj+2] = (ducp[2] - ducp[3]*ep[threejj+2])/wgh;
                        
                        dvep[threejj] = (dvcp[0] - dvcp[3]*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvcp[1] - dvcp[3]*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvcp[2] - dvcp[3]*ep[threejj+2])/wgh;
                        
                        duuep[threejj] = (duucp[0] - 2.0*ducp[3]*duep[threejj] - duucp[3]*ep[threejj])/wgh;
                        duuep[threejj+1] = (duucp[1] - 2.0*ducp[3]*duep[threejj+1] - duucp[3]*ep[threejj+1])/wgh;
                        duuep[threejj+2] = (duucp[2] - 2.0*ducp[3]*duep[threejj+2] - duucp[3]*ep[threejj+2])/wgh;
                        
                        duvep[threejj] = (duvcp[0] - ducp[3]*dvep[threejj] - dvcp[3]*duep[threejj] - duvcp[3]*ep[threejj])/wgh;
                        duvep[threejj+1] = (duvcp[1] - ducp[3]*dvep[threejj+1] - dvcp[3]*duep[threejj+1] - duvcp[3]*ep[threejj+1])/wgh;
                        duvep[threejj+2] = (duvcp[2] - ducp[3]*dvep[threejj+2] - dvcp[3]*duep[threejj+2] - duvcp[3]*ep[threejj+2])/wgh;
                        
                        dvvep[threejj] = (dvvcp[0] - 2.0*dvcp[3]*dvep[threejj] - dvvcp[3]*ep[threejj])/wgh;
                        dvvep[threejj+1] = (dvvcp[1] - 2.0*dvcp[3]*dvep[threejj+1] - dvvcp[3]*ep[threejj+1])/wgh;
                        dvvep[threejj+2] = (dvvcp[2] - 2.0*dvcp[3]*dvep[threejj+2] - dvvcp[3]*ep[threejj+2])/wgh;
                        
                    }
                    else if (us[2*jj+1] >= knotV[kcp]){
                        
                        myint = fourncp*(kcp-1);
                        wgh = cp[myint+3];
                        ep[threejj] = cp[myint]/wgh;
                        ep[threejj+1] = cp[myint+1]/wgh;
                        ep[threejj+2] = cp[myint+2]/wgh;
                        
                        myint = fourncpm4*(kcp-1);
                        duwgh = ducp[myint+3];
                        duep[threejj] = (ducp[myint] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (ducp[myint+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (ducp[myint+2] - duwgh*ep[threejj+2])/wgh;
                        
                        myint = fourncp*(kcp-2);
                        dvwgh = dvcp[myint+3];
                        dvep[threejj] = (dvcp[myint] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvcp[myint+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvcp[myint+2] - dvwgh*ep[threejj+2])/wgh;
                        
                        myint = fourncpm8*(kcp-1);
                        duuep[threejj] = (duucp[myint] - 2.0*duwgh*duep[threejj] - duucp[myint+3]*ep[threejj])/wgh;
                        duuep[threejj+1] = (duucp[myint+1] - 2.0*duwgh*duep[threejj+1] - duucp[myint+3]*ep[threejj+1])/wgh;
                        duuep[threejj+2] = (duucp[myint+2] - 2.0*duwgh*duep[threejj+2] - duucp[myint+3]*ep[threejj+2])/wgh;
                        
                        myint = fourncpm4*(kcp-2);
                        duvep[threejj] = (duvcp[myint] - duwgh*dvep[threejj] - dvwgh*duep[threejj] - duvcp[myint+3]*ep[threejj])/wgh;
                        duvep[threejj+1] = (duvcp[myint+1] - duwgh*dvep[threejj+1] - dvwgh*duep[threejj+1] - duvcp[myint+3]*ep[threejj+1])/wgh;
                        duvep[threejj+2] = (duvcp[myint+2] - duwgh*dvep[threejj+2] - dvwgh*duep[threejj+2] - duvcp[myint+3]*ep[threejj+2])/wgh;
                        
                        myint = fourncp*(kcp-3);
                        dvwgh *= 2.0;
                        dvvep[threejj] = (dvvcp[myint] - dvwgh*dvep[threejj] - dvvcp[myint+3]*ep[threejj])/wgh;
                        dvvep[threejj+1] = (dvvcp[myint+1] - dvwgh*dvep[threejj+1] - dvvcp[myint+3]*ep[threejj+1])/wgh;
                        dvvep[threejj+2] = (dvvcp[myint+2] - dvwgh*dvep[threejj+2] - dvvcp[myint+3]*ep[threejj+2])/wgh;
                        
                    }
                    else {
                        
                        ep[threejj] = 0.0;
                        ep[threejj+1] = 0.0;
                        ep[threejj+2] = 0.0;
                        wgh = 0.0;
                        
                        spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        ind = spanV - degV;
                        
                        for (i = 0; i <= degV; i++){
                            myint = (ind+i)*fourncp;
                            ep[threejj] += NV[i] * cp[myint];
                            ep[threejj+1] += NV[i] * cp[myint+1];
                            ep[threejj+2] += NV[i] * cp[myint+2];
                            wgh += NV[i] * cp[myint+3];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        duwgh = 0.0;
                        
                        for (i = 0; i <= degV; i++){
                            myint = (ind+i)*fourncpm4;
                            duep[threejj] += NV[i] * ducp[myint];
                            duep[threejj+1] += NV[i] * ducp[myint+1];
                            duep[threejj+2] += NV[i] * ducp[myint+2];
                            duwgh += NV[i] * ducp[myint+3];
                        }
                        duep[threejj] = (duep[threejj] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (duep[threejj+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (duep[threejj+2] - duwgh*ep[threejj+2])/wgh;
                        
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        duuwgh = 0.0;
                        
                        for (i = 0; i <= degV; i++){
                            myint = (ind+i)*fourncpm8;
                            duuep[threejj] += NV[i] * duucp[myint];
                            duuep[threejj+1] += NV[i] * duucp[myint+1];
                            duuep[threejj+2] += NV[i] * duucp[myint+2];
                            duuwgh += NV[i] * duucp[myint+3];
                        }
                        duuep[threejj] = (duuep[threejj] - 2.0*duwgh*duep[threejj] - duuwgh*ep[threejj])/wgh;
                        duuep[threejj+1] = (duuep[threejj+1] - 2.0*duwgh*duep[threejj+1] - duuwgh*ep[threejj+1])/wgh;
                        duuep[threejj+2] = (duuep[threejj+2] - 2.0*duwgh*duep[threejj+2] - duuwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanV-1, us[2*jj+1], degV-1, &knotV[1], NV, leftV, rightV);
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        dvwgh = 0.0;
                        
                        for (i = 0; i < degV; i++){
                            myint = (ind+i)*fourncp;
                            dvep[threejj] += NV[i] * dvcp[myint];
                            dvep[threejj+1] += NV[i] * dvcp[myint+1];
                            dvep[threejj+2] += NV[i] * dvcp[myint+2];
                            dvwgh += NV[i] * dvcp[myint+3];
                        }
                        dvep[threejj] = (dvep[threejj] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvep[threejj+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvep[threejj+2] - dvwgh*ep[threejj+2])/wgh;
                        
                        
                        duvep[threejj] = 0.0;
                        duvep[threejj+1] = 0.0;
                        duvep[threejj+2] = 0.0;
                        duvwgh = 0.0;
                        
                        for (i = 0; i < degV; i++){
                            myint = (ind+i)*fourncpm4;
                            duvep[threejj] += NV[i] * duvcp[myint];
                            duvep[threejj+1] += NV[i] * duvcp[myint+1];
                            duvep[threejj+2] += NV[i] * duvcp[myint+2];
                            duvwgh += NV[i] * duvcp[myint+3];
                        }
                        duvep[threejj] = (duvep[threejj] - duwgh*dvep[threejj] - dvwgh*duep[threejj] - duvwgh*ep[threejj])/wgh;
                        duvep[threejj+1] = (duvep[threejj+1] - duwgh*dvep[threejj+1] - dvwgh*duep[threejj+1] - duvwgh*ep[threejj+1])/wgh;
                        duvep[threejj+2] = (duvep[threejj+2] - duwgh*dvep[threejj+2] - dvwgh*duep[threejj+2] - duvwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanV-2, us[2*jj+1], degV-2, &knotV[2], NV, leftV, rightV);
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        dvvwgh = 0.0;
                        
                        for (i = 0; i <= (degV-2); i++){
                            myint = (ind+i)*fourncp;
                            dvvep[threejj] += NV[i] * dvvcp[myint];
                            dvvep[threejj+1] += NV[i] * dvvcp[myint+1];
                            dvvep[threejj+2] += NV[i] * dvvcp[myint+2];
                            dvvwgh += NV[i] * dvvcp[myint+3];
                        }
                        dvwgh *= 2.0;
                        dvvep[threejj] = (dvvep[threejj] - dvwgh*dvep[threejj] - dvvwgh*ep[threejj])/wgh;
                        dvvep[threejj+1] = (dvvep[threejj+1] - dvwgh*dvep[threejj+1] - dvvwgh*ep[threejj+1])/wgh;
                        dvvep[threejj+2] = (dvvep[threejj+2] - dvwgh*dvep[threejj+2] - dvvwgh*ep[threejj+2])/wgh;
                        
                    }
                    
                }
                else if (us[2*jj] >= knotU[ncp]){
                    
                    if (us[2*jj+1] <= knotV[degV]){
                        
                        wgh = cp[fourncp-1];
                        ep[threejj] = cp[fourncpm4]/wgh;
                        ep[threejj+1] = cp[fourncpm4+1]/wgh;
                        ep[threejj+2] = cp[fourncpm4+2]/wgh;
                        
                        duep[threejj] = (ducp[fourncpm4-4] - ducp[fourncpm4-1]*ep[threejj])/wgh;
                        duep[threejj+1] = (ducp[fourncpm4-3] - ducp[fourncpm4-1]*ep[threejj+1])/wgh;
                        duep[threejj+2] = (ducp[fourncpm4-2] - ducp[fourncpm4-1]*ep[threejj+2])/wgh;
                        
                        dvep[threejj] = (dvcp[fourncpm4] - dvcp[fourncpm4+3]*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvcp[fourncpm4+1] - dvcp[fourncpm4+3]*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvcp[fourncpm4+2] - dvcp[fourncpm4+3]*ep[threejj+2])/wgh;
                        
                        duuep[threejj] = (duucp[fourncpm8-4] - 2.0*ducp[fourncpm4-1]*duep[threejj] - duucp[fourncpm8-1]*ep[threejj])/wgh;
                        duuep[threejj+1] = (duucp[fourncpm8-3] - 2.0*ducp[fourncpm4-1]*duep[threejj+1] - duucp[fourncpm8-1]*ep[threejj+1])/wgh;
                        duuep[threejj+2] = (duucp[fourncpm8-2] - 2.0*ducp[fourncpm4-1]*duep[threejj+2] - duucp[fourncpm8-1]*ep[threejj+2])/wgh;
                        
                        duvep[threejj] = (duvcp[fourncpm4-4] - ducp[fourncpm4-1]*dvep[threejj] - dvcp[fourncpm4+3]*duep[threejj] - duvcp[fourncpm4-1]*ep[threejj])/wgh;
                        duvep[threejj+1] = (duvcp[fourncpm4-3] - ducp[fourncpm4-1]*dvep[threejj+1] - dvcp[fourncpm4+3]*duep[threejj+1] - duvcp[fourncpm4-1]*ep[threejj+1])/wgh;
                        duvep[threejj+2] = (duvcp[fourncpm4-2] - ducp[fourncpm4-1]*dvep[threejj+2] - dvcp[fourncpm4+3]*duep[threejj+2] - duvcp[fourncpm4-1]*ep[threejj+2])/wgh;
                        
                        dvvep[threejj] = (dvvcp[fourncpm4] - 2.0*dvcp[fourncpm4+3]*dvep[threejj] - dvvcp[fourncpm4+3]*ep[threejj])/wgh;
                        dvvep[threejj+1] = (dvvcp[fourncpm4+1] - 2.0*dvcp[fourncpm4+3]*dvep[threejj+1] - dvvcp[fourncpm4+3]*ep[threejj+1])/wgh;
                        dvvep[threejj+2] = (dvvcp[fourncpm4+2] - 2.0*dvcp[fourncpm4+3]*dvep[threejj+2] - dvvcp[fourncpm4+3]*ep[threejj+2])/wgh;
                        
                    }
                    else if (us[2*jj+1] >= knotV[kcp]){
                        
                        myint = fourncp*kcp;
                        wgh = cp[myint-1];
                        ep[threejj] = cp[myint-4]/wgh;
                        ep[threejj+1] = cp[myint-3]/wgh;
                        ep[threejj+2] = cp[myint-2]/wgh;
                        
                        myint = fourncpm4*kcp-4;
                        duwgh = ducp[myint+3];
                        duep[threejj] = (ducp[myint] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (ducp[myint+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (ducp[myint+2] - duwgh*ep[threejj+2])/wgh;
                        
                        myint = fourncp*(kcp-1)-4;
                        dvwgh = dvcp[myint+3];
                        dvep[threejj] = (dvcp[myint] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvcp[myint+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvcp[myint+2] - dvwgh*ep[threejj+2])/wgh;
                        
                        myint = fourncpm8*kcp-4;
                        duuep[threejj] = (duucp[myint] - 2.0*duwgh*duep[threejj] - duucp[myint+3]*ep[threejj])/wgh;
                        duuep[threejj+1] = (duucp[myint+1] - 2.0*duwgh*duep[threejj+1] - duucp[myint+3]*ep[threejj+1])/wgh;
                        duuep[threejj+2] = (duucp[myint+2] - 2.0*duwgh*duep[threejj+2] - duucp[myint+3]*ep[threejj+2])/wgh;
                        
                        myint = fourncpm4*(kcp-1)-4;
                        duvep[threejj] = (duvcp[myint] - duwgh*dvep[threejj] - dvwgh*duep[threejj] - duvcp[myint+3]*ep[threejj])/wgh;
                        duvep[threejj+1] = (duvcp[myint+1] - duwgh*dvep[threejj+1] - dvwgh*duep[threejj+1] - duvcp[myint+3]*ep[threejj+1])/wgh;
                        duvep[threejj+2] = (duvcp[myint+2] - duwgh*dvep[threejj+2] - dvwgh*duep[threejj+2] - duvcp[myint+3]*ep[threejj+2])/wgh;
                        
                        myint = fourncp*(kcp-2)-4;
                        dvwgh *= 2.0;
                        dvvep[threejj] = (dvvcp[myint] - dvwgh*dvep[threejj] - dvvcp[myint+3]*ep[threejj])/wgh;
                        dvvep[threejj+1] = (dvvcp[myint+1] - dvwgh*dvep[threejj+1] - dvvcp[myint+3]*ep[threejj+1])/wgh;
                        dvvep[threejj+2] = (dvvcp[myint+2] - dvwgh*dvep[threejj+2] - dvvcp[myint+3]*ep[threejj+2])/wgh;
                        
                    }
                    else {
                        
                        ep[threejj] = 0.0;
                        ep[threejj+1] = 0.0;
                        ep[threejj+2] = 0.0;
                        wgh = 0.0;
                        
                        spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        ind = spanV - degV;
                        myint = (ind+1)*fourncp;
                        
                        for (i = 0; i <= degV; i++){
                            ep[threejj] += NV[i] * cp[i*fourncp+myint-4];
                            ep[threejj+1] += NV[i] * cp[i*fourncp+myint-3];
                            ep[threejj+2] += NV[i] * cp[i*fourncp+myint-2];
                            wgh += NV[i] * cp[i*fourncp+myint-1];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        duwgh = 0.0;
                        
                        for (i = 0; i <= degV; i++){
                            myint = (ind+i)*fourncpm4 + fourncpm8;
                            duep[threejj] += NV[i] * ducp[myint];
                            duep[threejj+1] += NV[i] * ducp[myint+1];
                            duep[threejj+2] += NV[i] * ducp[myint+2];
                            duwgh += NV[i] * ducp[myint+3];
                        }
                        duep[threejj] = (duep[threejj] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (duep[threejj+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (duep[threejj+2] - duwgh*ep[threejj+2])/wgh;
                        
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        duuwgh = 0.0;
                        
                        for (i = 0; i <= degV; i++){
                            myint = (ind+i)*fourncpm8 + fourncpm8 - 4;
                            duuep[threejj] += NV[i] * duucp[myint];
                            duuep[threejj+1] += NV[i] * duucp[myint+1];
                            duuep[threejj+2] += NV[i] * duucp[myint+2];
                            duuwgh += NV[i] * duucp[myint+3];
                        }
                        duuep[threejj] = (duuep[threejj] - 2.0*duwgh*duep[threejj] - duuwgh*ep[threejj])/wgh;
                        duuep[threejj+1] = (duuep[threejj+1] - 2.0*duwgh*duep[threejj+1] - duuwgh*ep[threejj+1])/wgh;
                        duuep[threejj+2] = (duuep[threejj+2] - 2.0*duwgh*duep[threejj+2] - duuwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanV-1, us[2*jj+1], degV-1, &knotV[1], NV, leftV, rightV);
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        dvwgh = 0.0;
                        
                        for (i = 0; i < degV; i++){
                            myint = (ind+i)*fourncp + fourncpm4;
                            dvep[threejj] += NV[i] * dvcp[myint];
                            dvep[threejj+1] += NV[i] * dvcp[myint+1];
                            dvep[threejj+2] += NV[i] * dvcp[myint+2];
                            dvwgh += NV[i] * dvcp[myint+3];
                        }
                        dvep[threejj] = (dvep[threejj] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvep[threejj+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvep[threejj+2] - dvwgh*ep[threejj+2])/wgh;
                        
                        
                        duvep[threejj] = 0.0;
                        duvep[threejj+1] = 0.0;
                        duvep[threejj+2] = 0.0;
                        duvwgh = 0.0;
                        
                        for (i = 0; i < degV; i++){
                            myint = (ind+i)*fourncpm4 + fourncpm8;
                            duvep[threejj] += NV[i] * duvcp[myint];
                            duvep[threejj+1] += NV[i] * duvcp[myint+1];
                            duvep[threejj+2] += NV[i] * duvcp[myint+2];
                            duvwgh += NV[i] * duvcp[myint+3];
                        }
                        duvep[threejj] = (duvep[threejj] - duwgh*dvep[threejj] - dvwgh*duep[threejj] - duvwgh*ep[threejj])/wgh;
                        duvep[threejj+1] = (duvep[threejj+1] - duwgh*dvep[threejj+1] - dvwgh*duep[threejj+1] - duvwgh*ep[threejj+1])/wgh;
                        duvep[threejj+2] = (duvep[threejj+2] - duwgh*dvep[threejj+2] - dvwgh*duep[threejj+2] - duvwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanV-2, us[2*jj+1], degV-2, &knotV[2], NV, leftV, rightV);
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        dvvwgh = 0.0;
                        
                        for (i = 0; i <= (degV-2); i++){
                            myint = (ind+i)*fourncp + fourncpm4;
                            dvvep[threejj] += NV[i] * dvvcp[myint];
                            dvvep[threejj+1] += NV[i] * dvvcp[myint+1];
                            dvvep[threejj+2] += NV[i] * dvvcp[myint+2];
                            dvvwgh += NV[i] * dvvcp[myint+3];
                        }
                        dvwgh *= 2.0;
                        dvvep[threejj] = (dvvep[threejj] - dvwgh*dvep[threejj] - dvvwgh*ep[threejj])/wgh;
                        dvvep[threejj+1] = (dvvep[threejj+1] - dvwgh*dvep[threejj+1] - dvvwgh*ep[threejj+1])/wgh;
                        dvvep[threejj+2] = (dvvep[threejj+2] - dvwgh*dvep[threejj+2] - dvvwgh*ep[threejj+2])/wgh;
                        
                    }
                    
                }
                else {
                    
                    ep[threejj] = 0.0;
                    ep[threejj+1] = 0.0;
                    ep[threejj+2] = 0.0;
                    wgh = 0.0;
                    
                    duep[threejj] = 0.0;
                    duep[threejj+1] = 0.0;
                    duep[threejj+2] = 0.0;
                    duwgh = 0.0;
                    
                    dvep[threejj] = 0.0;
                    dvep[threejj+1] = 0.0;
                    dvep[threejj+2] = 0.0;
                    dvwgh = 0.0;
                    
                    duuep[threejj] = 0.0;
                    duuep[threejj+1] = 0.0;
                    duuep[threejj+2] = 0.0;
                    duuwgh = 0.0;
                    
                    duvep[threejj] = 0.0;
                    duvep[threejj+1] = 0.0;
                    duvep[threejj+2] = 0.0;
                    duvwgh = 0.0;
                    
                    dvvep[threejj] = 0.0;
                    dvvep[threejj+1] = 0.0;
                    dvvep[threejj+2] = 0.0;
                    dvvwgh = 0.0;
                    
                    if (us[2*jj+1] <= knotV[degV]){
                        
                        spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                        BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                        
                        ind = spanU - degU;
                        
                        for (i = 0; i <= degU; i++){
                            ep[threejj] += NU[i] * cp[(ind+i)*4];
                            ep[threejj+1] += NU[i] * cp[(ind+i)*4+1];
                            ep[threejj+2] += NU[i] * cp[(ind+i)*4+2];
                            wgh += NU[i] * cp[(ind+i)*4+3];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        for (i = 0; i <= degU; i++){
                            dvep[threejj] += NU[i] * dvcp[(ind+i)*4];
                            dvep[threejj+1] += NU[i] * dvcp[(ind+i)*4+1];
                            dvep[threejj+2] += NU[i] * dvcp[(ind+i)*4+2];
                            dvwgh += NU[i] * dvcp[(ind+i)*4+3];
                        }
                        dvep[threejj] = (dvep[threejj] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvep[threejj+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvep[threejj+2] - dvwgh*ep[threejj+2])/wgh;
                        
                        
                        for (i = 0; i <= degU; i++){
                            dvvep[threejj] += NU[i] * dvvcp[(ind+i)*4];
                            dvvep[threejj+1] += NU[i] * dvvcp[(ind+i)*4+1];
                            dvvep[threejj+2] += NU[i] * dvvcp[(ind+i)*4+2];
                            dvvwgh += NU[i] * dvvcp[(ind+i)*4+3];
                        }
                        dvvep[threejj] = (dvvep[threejj] - 2.0*dvwgh*dvep[threejj] - dvvwgh*ep[threejj])/wgh;
                        dvvep[threejj+1] = (dvvep[threejj+1] - 2.0*dvwgh*dvep[threejj+1] - dvvwgh*ep[threejj+1])/wgh;
                        dvvep[threejj+2] = (dvvep[threejj+2] - 2.0*dvwgh*dvep[threejj+2] - dvvwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanU-1, us[2*jj], degU-1, &knotU[1], NU, leftU, rightU);
                        
                        for (i = 0; i < degU; i++){
                            duep[threejj] += NU[i] * ducp[(ind+i)*4];
                            duep[threejj+1] += NU[i] * ducp[(ind+i)*4+1];
                            duep[threejj+2] += NU[i] * ducp[(ind+i)*4+2];
                            duwgh += NU[i] * ducp[(ind+i)*4+3];
                        }
                        duep[threejj] = (duep[threejj] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (duep[threejj+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (duep[threejj+2] - duwgh*ep[threejj+2])/wgh;
                        
                        
                        for (i = 0; i < degU; i++){
                            duvep[threejj] += NU[i] * duvcp[(ind+i)*4];
                            duvep[threejj+1] += NU[i] * duvcp[(ind+i)*4+1];
                            duvep[threejj+2] += NU[i] * duvcp[(ind+i)*4+2];
                            duvwgh += NU[i] * duvcp[(ind+i)*4+3];
                        }
                        duvep[threejj] = (duvep[threejj] - duwgh*dvep[threejj] - dvwgh*duep[threejj] - duvwgh*ep[threejj])/wgh;
                        duvep[threejj+1] = (duvep[threejj+1] - duwgh*dvep[threejj+1] - dvwgh*duep[threejj+1] - duvwgh*ep[threejj+1])/wgh;
                        duvep[threejj+2] = (duvep[threejj+2] - duwgh*dvep[threejj+2] - dvwgh*duep[threejj+2] - duvwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanU-2, us[2*jj], degU-2, &knotU[2], NU, leftU, rightU);
                        
                        for (i = 0; i <= (degU-2); i++){
                            duuep[threejj] += NU[i] * duucp[(ind+i)*4];
                            duuep[threejj+1] += NU[i] * duucp[(ind+i)*4+1];
                            duuep[threejj+2] += NU[i] * duucp[(ind+i)*4+2];
                            duuwgh += NU[i] * duucp[(ind+i)*4+3];
                        }
                        duwgh *= 2.0;
                        duuep[threejj] = (duuep[threejj] - duwgh*duep[threejj] - duuwgh*ep[threejj])/wgh;
                        duuep[threejj+1] = (duuep[threejj+1] - duwgh*duep[threejj+1] - duuwgh*ep[threejj+1])/wgh;
                        duuep[threejj+2] = (duuep[threejj+2] - duwgh*duep[threejj+2] - duuwgh*ep[threejj+2])/wgh;
                        
                    }
                    else if (us[2*jj+1] >= knotV[kcp]){
                        
                        spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                        BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                        
                        ind = spanU - degU;
                        myint = ind*4+(kcp-1)*fourncp;
                        
                        for (i = 0; i <= degU; i++){
                            ep[threejj] += NU[i] * cp[i*4+myint];
                            ep[threejj+1] += NU[i] * cp[i*4+myint+1];
                            ep[threejj+2] += NU[i] * cp[i*4+myint+2];
                            wgh += NU[i] * cp[i*4+myint+3];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        ind = spanU - degU + ncp*(kcp-2);
                        
                        for (i = 0; i <= degU; i++){
                            dvep[threejj] += NU[i] * dvcp[(ind+i)*4];
                            dvep[threejj+1] += NU[i] * dvcp[(ind+i)*4+1];
                            dvep[threejj+2] += NU[i] * dvcp[(ind+i)*4+2];
                            dvwgh += NU[i] * dvcp[(ind+i)*4+3];
                        }
                        dvep[threejj] = (dvep[threejj] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvep[threejj+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvep[threejj+2] - dvwgh*ep[threejj+2])/wgh;
                        
                        
                        ind = spanU - degU + ncp*(kcp-3);
                        
                        for (i = 0; i <= degU; i++){
                            dvvep[threejj] += NU[i] * dvvcp[(ind+i)*4];
                            dvvep[threejj+1] += NU[i] * dvvcp[(ind+i)*4+1];
                            dvvep[threejj+2] += NU[i] * dvvcp[(ind+i)*4+2];
                            dvvwgh += NU[i] * dvvcp[(ind+i)*4+3];
                        }
                        dvvep[threejj] = (dvvep[threejj] - 2.0*dvwgh*dvep[threejj] - dvvwgh*ep[threejj])/wgh;
                        dvvep[threejj+1] = (dvvep[threejj+1] - 2.0*dvwgh*dvep[threejj+1] - dvvwgh*ep[threejj+1])/wgh;
                        dvvep[threejj+2] = (dvvep[threejj+2] - 2.0*dvwgh*dvep[threejj+2] - dvvwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanU-1, us[2*jj], degU-1, &knotU[1], NU, leftU, rightU);
                        
                        ind = spanU - degU + (ncp-1)*(kcp-1);
                        
                        for (i = 0; i < degU; i++){
                            duep[threejj] += NU[i] * ducp[(ind+i)*4];
                            duep[threejj+1] += NU[i] * ducp[(ind+i)*4+1];
                            duep[threejj+2] += NU[i] * ducp[(ind+i)*4+2];
                            duwgh += NU[i] * ducp[(ind+i)*4+3];
                        }
                        duep[threejj] = (duep[threejj] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (duep[threejj+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (duep[threejj+2] - duwgh*ep[threejj+2])/wgh;
                        
                        
                        ind = spanU - degU + (ncp-1)*(kcp-2);
                        
                        for (i = 0; i < degU; i++){
                            duvep[threejj] += NU[i] * duvcp[(ind+i)*4];
                            duvep[threejj+1] += NU[i] * duvcp[(ind+i)*4+1];
                            duvep[threejj+2] += NU[i] * duvcp[(ind+i)*4+2];
                            duvwgh += NU[i] * duvcp[(ind+i)*4+3];
                        }
                        duvep[threejj] = (duvep[threejj] - duwgh*dvep[threejj] - dvwgh*duep[threejj] - duvwgh*ep[threejj])/wgh;
                        duvep[threejj+1] = (duvep[threejj+1] - duwgh*dvep[threejj+1] - dvwgh*duep[threejj+1] - duvwgh*ep[threejj+1])/wgh;
                        duvep[threejj+2] = (duvep[threejj+2] - duwgh*dvep[threejj+2] - dvwgh*duep[threejj+2] - duvwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanU-2, us[2*jj], degU-2, &knotU[2], NU, leftU, rightU);
                        
                        ind = spanU - degU + (ncp-2)*(kcp-1);
                        
                        for (i = 0; i <= (degU-2); i++){
                            duuep[threejj] += NU[i] * duucp[(ind+i)*4];
                            duuep[threejj+1] += NU[i] * duucp[(ind+i)*4+1];
                            duuep[threejj+2] += NU[i] * duucp[(ind+i)*4+2];
                            duuwgh += NU[i] * duucp[(ind+i)*4+3];
                        }
                        duwgh *= 2.0;
                        duuep[threejj] = (duuep[threejj] - duwgh*duep[threejj] - duuwgh*ep[threejj])/wgh;
                        duuep[threejj+1] = (duuep[threejj+1] - duwgh*duep[threejj+1] - duuwgh*ep[threejj+1])/wgh;
                        duuep[threejj+2] = (duuep[threejj+2] - duwgh*duep[threejj+2] - duuwgh*ep[threejj+2])/wgh;
                        
                    }
                    else {
                        
                        spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                        BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                        
                        spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        ind = spanU - degU;
                        ind2 = spanV - degV;
                        myint = ind2*fourncp+ind*4;
                        
                        for (i = 0; i <= degV; i++){
                            for (j = 0; j <= degU; j++){
                                NN = NV[i] * NU[j];
                                ep[threejj] += NN * cp[i*fourncp+j*4+myint];
                                ep[threejj+1] += NN * cp[i*fourncp+j*4+myint+1];
                                ep[threejj+2] += NN * cp[i*fourncp+j*4+myint+2];
                                wgh += NN * cp[i*fourncp+j*4+myint+3];
                            }
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        BasisFuns(spanV-1, us[2*jj+1], degV-1, &knotV[1], NV, leftV, rightV);
                        
                        for (i = 0; i < degV; i++){
                            for (j = 0; j <= degU; j++){
                                NN = NV[i] * NU[j];
                                dvep[threejj] += NN * dvcp[i*fourncp+j*4+myint];
                                dvep[threejj+1] += NN * dvcp[i*fourncp+j*4+myint+1];
                                dvep[threejj+2] += NN * dvcp[i*fourncp+j*4+myint+2];
                                dvwgh += NN * dvcp[i*fourncp+j*4+myint+3];
                            }
                        }
                        dvep[threejj] = (dvep[threejj] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvep[threejj+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvep[threejj+2] - dvwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanV-2, us[2*jj+1], degV-2, &knotV[2], NV, leftV, rightV);
                        
                        for (i = 0; i <= (degV-2); i++){
                            for (j = 0; j <= degU; j++){
                                NN = NV[i] * NU[j];
                                dvvep[threejj] += NN * dvvcp[i*fourncp+j*4+myint];
                                dvvep[threejj+1] += NN * dvvcp[i*fourncp+j*4+myint+1];
                                dvvep[threejj+2] += NN * dvvcp[i*fourncp+j*4+myint+2];
                                dvvwgh += NN * dvvcp[i*fourncp+j*4+myint+3];
                            }
                        }
                        dvvep[threejj] = (dvvep[threejj] - 2.0*dvwgh*dvep[threejj] - dvvwgh*ep[threejj])/wgh;
                        dvvep[threejj+1] = (dvvep[threejj+1] - 2.0*dvwgh*dvep[threejj+1] - dvvwgh*ep[threejj+1])/wgh;
                        dvvep[threejj+2] = (dvvep[threejj+2] - 2.0*dvwgh*dvep[threejj+2] - dvvwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanU-1, us[2*jj], degU-1, &knotU[1], NU, leftU, rightU);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        myint = ind2*fourncpm4+ind*4;
                        
                        for (i = 0; i <= degV; i++){
                            for (j = 0; j < degU; j++){
                                NN = NV[i] * NU[j];
                                duep[threejj] += NN * ducp[i*fourncpm4+j*4+myint];
                                duep[threejj+1] += NN * ducp[i*fourncpm4+j*4+myint+1];
                                duep[threejj+2] += NN * ducp[i*fourncpm4+j*4+myint+2];
                                duwgh += NN * ducp[i*fourncpm4+j*4+myint+3];
                            }
                        }
                        duep[threejj] = (duep[threejj] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (duep[threejj+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (duep[threejj+2] - duwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanU-2, us[2*jj], degU-2, &knotU[2], NU, leftU, rightU);
                        
                        myint = ind2*fourncpm8+ind*4;
                        
                        for (i = 0; i <= degV; i++){
                            for (j = 0; j <= (degU-2); j++){
                                NN = NV[i] * NU[j];
                                duuep[threejj] += NN * duucp[i*fourncpm8+j*4+myint];
                                duuep[threejj+1] += NN * duucp[i*fourncpm8+j*4+myint+1];
                                duuep[threejj+2] += NN * duucp[i*fourncpm8+j*4+myint+2];
                                duuwgh += NN * duucp[i*fourncpm8+j*4+myint+3];
                            }
                        }
                        duuep[threejj] = (duuep[threejj] - 2.0*duwgh*duep[threejj] - duuwgh*ep[threejj])/wgh;
                        duuep[threejj+1] = (duuep[threejj+1] - 2.0*duwgh*duep[threejj+1] - duuwgh*ep[threejj+1])/wgh;
                        duuep[threejj+2] = (duuep[threejj+2] - 2.0*duwgh*duep[threejj+2] - duuwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanU-1, us[2*jj], degU-1, &knotU[1], NU, leftU, rightU);
                        BasisFuns(spanV-1, us[2*jj+1], degV-1, &knotV[1], NV, leftV, rightV);
                        
                        myint = ind2*fourncpm4+ind*4;
                        
                        for (i = 0; i < degV; i++){
                            for (j = 0; j < degU; j++){
                                NN = NV[i] * NU[j];
                                duvep[threejj] += NN * duvcp[i*fourncpm4+j*4+myint];
                                duvep[threejj+1] += NN * duvcp[i*fourncpm4+j*4+myint+1];
                                duvep[threejj+2] += NN * duvcp[i*fourncpm4+j*4+myint+2];
                                duvwgh += NN * duvcp[i*fourncpm4+j*4+myint+3];
                            }
                        }
                        duvep[threejj] = (duvep[threejj] - duwgh*dvep[threejj] - dvwgh*duep[threejj] - duvwgh*ep[threejj])/wgh;
                        duvep[threejj+1] = (duvep[threejj+1] - duwgh*dvep[threejj+1] - dvwgh*duep[threejj+1] - duvwgh*ep[threejj+1])/wgh;
                        duvep[threejj+2] = (duvep[threejj+2] - duwgh*dvep[threejj+2] - dvwgh*duep[threejj+2] - duvwgh*ep[threejj+2])/wgh;
                        
                    }
                    
                }
                
            }
            
        }
        else if (degV==1){
            
            for (jj = 0; jj < nus; jj++){
                
                threejj = 3*jj;
                
                if (us[2*jj] <= knotU[degU]){
                    
                    if (us[2*jj+1] <= knotV[degV]){
                        
                        wgh = cp[3];
                        ep[threejj] = cp[0]/wgh;
                        ep[threejj+1] = cp[1]/wgh;
                        ep[threejj+2] = cp[2]/wgh;
                        
                        duep[threejj] = (ducp[0] - ducp[3]*ep[threejj])/wgh;
                        duep[threejj+1] = (ducp[1] - ducp[3]*ep[threejj+1])/wgh;
                        duep[threejj+2] = (ducp[2] - ducp[3]*ep[threejj+2])/wgh;
                        
                        dvep[threejj] = (dvcp[0] - dvcp[3]*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvcp[1] - dvcp[3]*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvcp[2] - dvcp[3]*ep[threejj+2])/wgh;
                        
                        duuep[threejj] = (duucp[0] - 2.0*ducp[3]*duep[threejj] - duucp[3]*ep[threejj])/wgh;
                        duuep[threejj+1] = (duucp[1] - 2.0*ducp[3]*duep[threejj+1] - duucp[3]*ep[threejj+1])/wgh;
                        duuep[threejj+2] = (duucp[2] - 2.0*ducp[3]*duep[threejj+2] - duucp[3]*ep[threejj+2])/wgh;
                        
                        duvep[threejj] = (duvcp[0] - ducp[3]*dvep[threejj] - dvcp[3]*duep[threejj] - duvcp[3]*ep[threejj])/wgh;
                        duvep[threejj+1] = (duvcp[1] - ducp[3]*dvep[threejj+1] - dvcp[3]*duep[threejj+1] - duvcp[3]*ep[threejj+1])/wgh;
                        duvep[threejj+2] = (duvcp[2] - ducp[3]*dvep[threejj+2] - dvcp[3]*duep[threejj+2] - duvcp[3]*ep[threejj+2])/wgh;
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        
                    }
                    else if (us[2*jj+1] >= knotV[kcp]){
                        
                        myint = fourncp*(kcp-1);
                        wgh = cp[myint+3];
                        ep[threejj] = cp[myint]/wgh;
                        ep[threejj+1] = cp[myint+1]/wgh;
                        ep[threejj+2] = cp[myint+2]/wgh;
                        
                        myint = fourncpm4*(kcp-1);
                        duwgh = ducp[myint+3];
                        duep[threejj] = (ducp[myint] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (ducp[myint+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (ducp[myint+2] - duwgh*ep[threejj+2])/wgh;
                        
                        myint = fourncp*(kcp-2);
                        dvwgh = dvcp[myint+3];
                        dvep[threejj] = (dvcp[myint] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvcp[myint+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvcp[myint+2] - dvwgh*ep[threejj+2])/wgh;
                        
                        myint = fourncpm8*(kcp-1);
                        duuep[threejj] = (duucp[myint] - 2.0*duwgh*duep[threejj] - duucp[myint+3]*ep[threejj])/wgh;
                        duuep[threejj+1] = (duucp[myint+1] - 2.0*duwgh*duep[threejj+1] - duucp[myint+3]*ep[threejj+1])/wgh;
                        duuep[threejj+2] = (duucp[myint+2] - 2.0*duwgh*duep[threejj+2] - duucp[myint+3]*ep[threejj+2])/wgh;
                        
                        myint = fourncpm4*(kcp-2);
                        duvep[threejj] = (duvcp[myint] - duwgh*dvep[threejj] - dvwgh*duep[threejj] - duvcp[myint+3]*ep[threejj])/wgh;
                        duvep[threejj+1] = (duvcp[myint+1] - duwgh*dvep[threejj+1] - dvwgh*duep[threejj+1] - duvcp[myint+3]*ep[threejj+1])/wgh;
                        duvep[threejj+2] = (duvcp[myint+2] - duwgh*dvep[threejj+2] - dvwgh*duep[threejj+2] - duvcp[myint+3]*ep[threejj+2])/wgh;
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        
                    }
                    else {
                        
                        ep[threejj] = 0.0;
                        ep[threejj+1] = 0.0;
                        ep[threejj+2] = 0.0;
                        wgh = 0.0;
                        
                        spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        ind = spanV - degV;
                        
                        for (i = 0; i <= degV; i++){
                            myint = (ind+i)*fourncp;
                            ep[threejj] += NV[i] * cp[myint];
                            ep[threejj+1] += NV[i] * cp[myint+1];
                            ep[threejj+2] += NV[i] * cp[myint+2];
                            wgh += NV[i] * cp[myint+3];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        duwgh = 0.0;
                        
                        for (i = 0; i <= degV; i++){
                            myint = (ind+i)*fourncpm4;
                            duep[threejj] += NV[i] * ducp[myint];
                            duep[threejj+1] += NV[i] * ducp[myint+1];
                            duep[threejj+2] += NV[i] * ducp[myint+2];
                            duwgh += NV[i] * ducp[myint+3];
                        }
                        duep[threejj] = (duep[threejj] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (duep[threejj+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (duep[threejj+2] - duwgh*ep[threejj+2])/wgh;
                        
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        duuwgh = 0.0;
                        
                        for (i = 0; i <= degV; i++){
                            myint = (ind+i)*fourncpm8;
                            duuep[threejj] += NV[i] * duucp[myint];
                            duuep[threejj+1] += NV[i] * duucp[myint+1];
                            duuep[threejj+2] += NV[i] * duucp[myint+2];
                            duuwgh += NV[i] * duucp[myint+3];
                        }
                        duuep[threejj] = (duuep[threejj] - 2.0*duwgh*duep[threejj] - duuwgh*ep[threejj])/wgh;
                        duuep[threejj+1] = (duuep[threejj+1] - 2.0*duwgh*duep[threejj+1] - duuwgh*ep[threejj+1])/wgh;
                        duuep[threejj+2] = (duuep[threejj+2] - 2.0*duwgh*duep[threejj+2] - duuwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanV-1, us[2*jj+1], degV-1, &knotV[1], NV, leftV, rightV);
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        dvwgh = 0.0;
                        
                        for (i = 0; i < degV; i++){
                            myint = (ind+i)*fourncp;
                            dvep[threejj] += NV[i] * dvcp[myint];
                            dvep[threejj+1] += NV[i] * dvcp[myint+1];
                            dvep[threejj+2] += NV[i] * dvcp[myint+2];
                            dvwgh += NV[i] * dvcp[myint+3];
                        }
                        dvep[threejj] = (dvep[threejj] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvep[threejj+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvep[threejj+2] - dvwgh*ep[threejj+2])/wgh;
                        
                        
                        duvep[threejj] = 0.0;
                        duvep[threejj+1] = 0.0;
                        duvep[threejj+2] = 0.0;
                        duvwgh = 0.0;
                        
                        for (i = 0; i < degV; i++){
                            myint = (ind+i)*fourncpm4;
                            duvep[threejj] += NV[i] * duvcp[myint];
                            duvep[threejj+1] += NV[i] * duvcp[myint+1];
                            duvep[threejj+2] += NV[i] * duvcp[myint+2];
                            duvwgh += NV[i] * duvcp[myint+3];
                        }
                        duvep[threejj] = (duvep[threejj] - duwgh*dvep[threejj] - dvwgh*duep[threejj] - duvwgh*ep[threejj])/wgh;
                        duvep[threejj+1] = (duvep[threejj+1] - duwgh*dvep[threejj+1] - dvwgh*duep[threejj+1] - duvwgh*ep[threejj+1])/wgh;
                        duvep[threejj+2] = (duvep[threejj+2] - duwgh*dvep[threejj+2] - dvwgh*duep[threejj+2] - duvwgh*ep[threejj+2])/wgh;
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        
                    }
                    
                }
                else if (us[2*jj] >= knotU[ncp]){
                    
                    if (us[2*jj+1] <= knotV[degV]){
                        
                        wgh = cp[fourncp-1];
                        ep[threejj] = cp[fourncpm4]/wgh;
                        ep[threejj+1] = cp[fourncpm4+1]/wgh;
                        ep[threejj+2] = cp[fourncpm4+2]/wgh;
                        
                        duep[threejj] = (ducp[fourncpm4-4] - ducp[fourncpm4-1]*ep[threejj])/wgh;
                        duep[threejj+1] = (ducp[fourncpm4-3] - ducp[fourncpm4-1]*ep[threejj+1])/wgh;
                        duep[threejj+2] = (ducp[fourncpm4-2] - ducp[fourncpm4-1]*ep[threejj+2])/wgh;
                        
                        dvep[threejj] = (dvcp[fourncpm4] - dvcp[fourncpm4+3]*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvcp[fourncpm4+1] - dvcp[fourncpm4+3]*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvcp[fourncpm4+2] - dvcp[fourncpm4+3]*ep[threejj+2])/wgh;
                        
                        duuep[threejj] = (duucp[fourncpm8-4] - 2.0*ducp[fourncpm4-1]*duep[threejj] - duucp[fourncpm8-1]*ep[threejj])/wgh;
                        duuep[threejj+1] = (duucp[fourncpm8-3] - 2.0*ducp[fourncpm4-1]*duep[threejj+1] - duucp[fourncpm8-1]*ep[threejj+1])/wgh;
                        duuep[threejj+2] = (duucp[fourncpm8-2] - 2.0*ducp[fourncpm4-1]*duep[threejj+2] - duucp[fourncpm8-1]*ep[threejj+2])/wgh;
                        
                        duvep[threejj] = (duvcp[fourncpm4-4] - ducp[fourncpm4-1]*dvep[threejj] - dvcp[fourncpm4+3]*duep[threejj] - duvcp[fourncpm4-1]*ep[threejj])/wgh;
                        duvep[threejj+1] = (duvcp[fourncpm4-3] - ducp[fourncpm4-1]*dvep[threejj+1] - dvcp[fourncpm4+3]*duep[threejj+1] - duvcp[fourncpm4-1]*ep[threejj+1])/wgh;
                        duvep[threejj+2] = (duvcp[fourncpm4-2] - ducp[fourncpm4-1]*dvep[threejj+2] - dvcp[fourncpm4+3]*duep[threejj+2] - duvcp[fourncpm4-1]*ep[threejj+2])/wgh;
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        
                    }
                    else if (us[2*jj+1] >= knotV[kcp]){
                        
                        myint = fourncp*kcp;
                        wgh = cp[myint-1];
                        ep[threejj] = cp[myint-4]/wgh;
                        ep[threejj+1] = cp[myint-3]/wgh;
                        ep[threejj+2] = cp[myint-2]/wgh;
                        
                        myint = fourncpm4*kcp-4;
                        duwgh = ducp[myint+3];
                        duep[threejj] = (ducp[myint] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (ducp[myint+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (ducp[myint+2] - duwgh*ep[threejj+2])/wgh;
                        
                        myint = fourncp*(kcp-1)-4;
                        dvwgh = dvcp[myint+3];
                        dvep[threejj] = (dvcp[myint] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvcp[myint+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvcp[myint+2] - dvwgh*ep[threejj+2])/wgh;
                        
                        myint = fourncpm8*kcp-4;
                        duuep[threejj] = (duucp[myint] - 2.0*duwgh*duep[threejj] - duucp[myint+3]*ep[threejj])/wgh;
                        duuep[threejj+1] = (duucp[myint+1] - 2.0*duwgh*duep[threejj+1] - duucp[myint+3]*ep[threejj+1])/wgh;
                        duuep[threejj+2] = (duucp[myint+2] - 2.0*duwgh*duep[threejj+2] - duucp[myint+3]*ep[threejj+2])/wgh;
                        
                        myint = fourncpm4*(kcp-1)-4;
                        duvep[threejj] = (duvcp[myint] - duwgh*dvep[threejj] - dvwgh*duep[threejj] - duvcp[myint+3]*ep[threejj])/wgh;
                        duvep[threejj+1] = (duvcp[myint+1] - duwgh*dvep[threejj+1] - dvwgh*duep[threejj+1] - duvcp[myint+3]*ep[threejj+1])/wgh;
                        duvep[threejj+2] = (duvcp[myint+2] - duwgh*dvep[threejj+2] - dvwgh*duep[threejj+2] - duvcp[myint+3]*ep[threejj+2])/wgh;
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        
                    }
                    else {
                        
                        ep[threejj] = 0.0;
                        ep[threejj+1] = 0.0;
                        ep[threejj+2] = 0.0;
                        wgh = 0.0;
                        
                        spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        ind = spanV - degV;
                        myint = (ind+1)*fourncp;
                        
                        for (i = 0; i <= degV; i++){
                            ep[threejj] += NV[i] * cp[i*fourncp+myint-4];
                            ep[threejj+1] += NV[i] * cp[i*fourncp+myint-3];
                            ep[threejj+2] += NV[i] * cp[i*fourncp+myint-2];
                            wgh += NV[i] * cp[i*fourncp+myint-1];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        duwgh = 0.0;
                        
                        for (i = 0; i <= degV; i++){
                            myint = (ind+i)*fourncpm4 + fourncpm8;
                            duep[threejj] += NV[i] * ducp[myint];
                            duep[threejj+1] += NV[i] * ducp[myint+1];
                            duep[threejj+2] += NV[i] * ducp[myint+2];
                            duwgh += NV[i] * ducp[myint+3];
                        }
                        duep[threejj] = (duep[threejj] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (duep[threejj+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (duep[threejj+2] - duwgh*ep[threejj+2])/wgh;
                        
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        duuwgh = 0.0;
                        
                        for (i = 0; i <= degV; i++){
                            myint = (ind+i)*fourncpm8 + fourncpm8 - 4;
                            duuep[threejj] += NV[i] * duucp[myint];
                            duuep[threejj+1] += NV[i] * duucp[myint+1];
                            duuep[threejj+2] += NV[i] * duucp[myint+2];
                            duuwgh += NV[i] * duucp[myint+3];
                        }
                        duuep[threejj] = (duuep[threejj] - 2.0*duwgh*duep[threejj] - duuwgh*ep[threejj])/wgh;
                        duuep[threejj+1] = (duuep[threejj+1] - 2.0*duwgh*duep[threejj+1] - duuwgh*ep[threejj+1])/wgh;
                        duuep[threejj+2] = (duuep[threejj+2] - 2.0*duwgh*duep[threejj+2] - duuwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanV-1, us[2*jj+1], degV-1, &knotV[1], NV, leftV, rightV);
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        dvwgh = 0.0;
                        
                        for (i = 0; i < degV; i++){
                            myint = (ind+i)*fourncp + fourncpm4;
                            dvep[threejj] += NV[i] * dvcp[myint];
                            dvep[threejj+1] += NV[i] * dvcp[myint+1];
                            dvep[threejj+2] += NV[i] * dvcp[myint+2];
                            dvwgh += NV[i] * dvcp[myint+3];
                        }
                        dvep[threejj] = (dvep[threejj] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvep[threejj+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvep[threejj+2] - dvwgh*ep[threejj+2])/wgh;
                        
                        
                        duvep[threejj] = 0.0;
                        duvep[threejj+1] = 0.0;
                        duvep[threejj+2] = 0.0;
                        duvwgh = 0.0;
                        
                        for (i = 0; i < degV; i++){
                            myint = (ind+i)*fourncpm4 + fourncpm8;
                            duvep[threejj] += NV[i] * duvcp[myint];
                            duvep[threejj+1] += NV[i] * duvcp[myint+1];
                            duvep[threejj+2] += NV[i] * duvcp[myint+2];
                            duvwgh += NV[i] * duvcp[myint+3];
                        }
                        duvep[threejj] = (duvep[threejj] - duwgh*dvep[threejj] - dvwgh*duep[threejj] - duvwgh*ep[threejj])/wgh;
                        duvep[threejj+1] = (duvep[threejj+1] - duwgh*dvep[threejj+1] - dvwgh*duep[threejj+1] - duvwgh*ep[threejj+1])/wgh;
                        duvep[threejj+2] = (duvep[threejj+2] - duwgh*dvep[threejj+2] - dvwgh*duep[threejj+2] - duvwgh*ep[threejj+2])/wgh;
                        
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        
                    }
                    
                }
                else {
                    
                    ep[threejj] = 0.0;
                    ep[threejj+1] = 0.0;
                    ep[threejj+2] = 0.0;
                    wgh = 0.0;
                    
                    duep[threejj] = 0.0;
                    duep[threejj+1] = 0.0;
                    duep[threejj+2] = 0.0;
                    duwgh = 0.0;
                    
                    dvep[threejj] = 0.0;
                    dvep[threejj+1] = 0.0;
                    dvep[threejj+2] = 0.0;
                    dvwgh = 0.0;
                    
                    duuep[threejj] = 0.0;
                    duuep[threejj+1] = 0.0;
                    duuep[threejj+2] = 0.0;
                    duuwgh = 0.0;
                    
                    duvep[threejj] = 0.0;
                    duvep[threejj+1] = 0.0;
                    duvep[threejj+2] = 0.0;
                    duvwgh = 0.0;
                    
                    dvvep[threejj] = 0.0;
                    dvvep[threejj+1] = 0.0;
                    dvvep[threejj+2] = 0.0;
                    
                    if (us[2*jj+1] <= knotV[degV]){
                        
                        spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                        BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                        
                        ind = spanU - degU;
                        
                        for (i = 0; i <= degU; i++){
                            ep[threejj] += NU[i] * cp[(ind+i)*4];
                            ep[threejj+1] += NU[i] * cp[(ind+i)*4+1];
                            ep[threejj+2] += NU[i] * cp[(ind+i)*4+2];
                            wgh += NU[i] * cp[(ind+i)*4+3];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        for (i = 0; i <= degU; i++){
                            dvep[threejj] += NU[i] * dvcp[(ind+i)*4];
                            dvep[threejj+1] += NU[i] * dvcp[(ind+i)*4+1];
                            dvep[threejj+2] += NU[i] * dvcp[(ind+i)*4+2];
                            dvwgh += NU[i] * dvcp[(ind+i)*4+3];
                        }
                        dvep[threejj] = (dvep[threejj] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvep[threejj+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvep[threejj+2] - dvwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanU-1, us[2*jj], degU-1, &knotU[1], NU, leftU, rightU);
                        
                        for (i = 0; i < degU; i++){
                            duep[threejj] += NU[i] * ducp[(ind+i)*4];
                            duep[threejj+1] += NU[i] * ducp[(ind+i)*4+1];
                            duep[threejj+2] += NU[i] * ducp[(ind+i)*4+2];
                            duwgh += NU[i] * ducp[(ind+i)*4+3];
                        }
                        duep[threejj] = (duep[threejj] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (duep[threejj+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (duep[threejj+2] - duwgh*ep[threejj+2])/wgh;
                        
                        
                        for (i = 0; i < degU; i++){
                            duvep[threejj] += NU[i] * duvcp[(ind+i)*4];
                            duvep[threejj+1] += NU[i] * duvcp[(ind+i)*4+1];
                            duvep[threejj+2] += NU[i] * duvcp[(ind+i)*4+2];
                            duvwgh += NU[i] * duvcp[(ind+i)*4+3];
                        }
                        duvep[threejj] = (duvep[threejj] - duwgh*dvep[threejj] - dvwgh*duep[threejj] - duvwgh*ep[threejj])/wgh;
                        duvep[threejj+1] = (duvep[threejj+1] - duwgh*dvep[threejj+1] - dvwgh*duep[threejj+1] - duvwgh*ep[threejj+1])/wgh;
                        duvep[threejj+2] = (duvep[threejj+2] - duwgh*dvep[threejj+2] - dvwgh*duep[threejj+2] - duvwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanU-2, us[2*jj], degU-2, &knotU[2], NU, leftU, rightU);
                        
                        for (i = 0; i <= (degU-2); i++){
                            duuep[threejj] += NU[i] * duucp[(ind+i)*4];
                            duuep[threejj+1] += NU[i] * duucp[(ind+i)*4+1];
                            duuep[threejj+2] += NU[i] * duucp[(ind+i)*4+2];
                            duuwgh += NU[i] * duucp[(ind+i)*4+3];
                        }
                        duwgh *= 2.0;
                        duuep[threejj] = (duuep[threejj] - duwgh*duep[threejj] - duuwgh*ep[threejj])/wgh;
                        duuep[threejj+1] = (duuep[threejj+1] - duwgh*duep[threejj+1] - duuwgh*ep[threejj+1])/wgh;
                        duuep[threejj+2] = (duuep[threejj+2] - duwgh*duep[threejj+2] - duuwgh*ep[threejj+2])/wgh;
                        
                    }
                    else if (us[2*jj+1] >= knotV[kcp]){
                        
                        spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                        BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                        
                        ind = spanU - degU;
                        myint = ind*4+(kcp-1)*fourncp;
                        
                        for (i = 0; i <= degU; i++){
                            ep[threejj] += NU[i] * cp[i*4+myint];
                            ep[threejj+1] += NU[i] * cp[i*4+myint+1];
                            ep[threejj+2] += NU[i] * cp[i*4+myint+2];
                            wgh += NU[i] * cp[i*4+myint+3];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        ind = spanU - degU + ncp*(kcp-2);
                        
                        for (i = 0; i <= degU; i++){
                            dvep[threejj] += NU[i] * dvcp[(ind+i)*4];
                            dvep[threejj+1] += NU[i] * dvcp[(ind+i)*4+1];
                            dvep[threejj+2] += NU[i] * dvcp[(ind+i)*4+2];
                            dvwgh += NU[i] * dvcp[(ind+i)*4+3];
                        }
                        dvep[threejj] = (dvep[threejj] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvep[threejj+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvep[threejj+2] - dvwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanU-1, us[2*jj], degU-1, &knotU[1], NU, leftU, rightU);
                        
                        ind = spanU - degU + (ncp-1)*(kcp-1);
                        
                        for (i = 0; i < degU; i++){
                            duep[threejj] += NU[i] * ducp[(ind+i)*4];
                            duep[threejj+1] += NU[i] * ducp[(ind+i)*4+1];
                            duep[threejj+2] += NU[i] * ducp[(ind+i)*4+2];
                            duwgh += NU[i] * ducp[(ind+i)*4+3];
                        }
                        duep[threejj] = (duep[threejj] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (duep[threejj+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (duep[threejj+2] - duwgh*ep[threejj+2])/wgh;
                        
                        
                        ind = spanU - degU + (ncp-1)*(kcp-2);
                        
                        for (i = 0; i < degU; i++){
                            duvep[threejj] += NU[i] * duvcp[(ind+i)*4];
                            duvep[threejj+1] += NU[i] * duvcp[(ind+i)*4+1];
                            duvep[threejj+2] += NU[i] * duvcp[(ind+i)*4+2];
                            duvwgh += NU[i] * duvcp[(ind+i)*4+3];
                        }
                        duvep[threejj] = (duvep[threejj] - duwgh*dvep[threejj] - dvwgh*duep[threejj] - duvwgh*ep[threejj])/wgh;
                        duvep[threejj+1] = (duvep[threejj+1] - duwgh*dvep[threejj+1] - dvwgh*duep[threejj+1] - duvwgh*ep[threejj+1])/wgh;
                        duvep[threejj+2] = (duvep[threejj+2] - duwgh*dvep[threejj+2] - dvwgh*duep[threejj+2] - duvwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanU-2, us[2*jj], degU-2, &knotU[2], NU, leftU, rightU);
                        
                        ind = spanU - degU + (ncp-2)*(kcp-1);
                        
                        for (i = 0; i <= (degU-2); i++){
                            duuep[threejj] += NU[i] * duucp[(ind+i)*4];
                            duuep[threejj+1] += NU[i] * duucp[(ind+i)*4+1];
                            duuep[threejj+2] += NU[i] * duucp[(ind+i)*4+2];
                            duuwgh += NU[i] * duucp[(ind+i)*4+3];
                        }
                        duwgh *= 2.0;
                        duuep[threejj] = (duuep[threejj] - duwgh*duep[threejj] - duuwgh*ep[threejj])/wgh;
                        duuep[threejj+1] = (duuep[threejj+1] - duwgh*duep[threejj+1] - duuwgh*ep[threejj+1])/wgh;
                        duuep[threejj+2] = (duuep[threejj+2] - duwgh*duep[threejj+2] - duuwgh*ep[threejj+2])/wgh;
                        
                    }
                    else {
                        
                        spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                        BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                        
                        spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        ind = spanU - degU;
                        ind2 = spanV - degV;
                        myint = ind2*fourncp+ind*4;
                        
                        for (i = 0; i <= degV; i++){
                            for (j = 0; j <= degU; j++){
                                NN = NV[i] * NU[j];
                                ep[threejj] += NN * cp[i*fourncp+j*4+myint];
                                ep[threejj+1] += NN * cp[i*fourncp+j*4+myint+1];
                                ep[threejj+2] += NN * cp[i*fourncp+j*4+myint+2];
                                wgh += NN * cp[i*fourncp+j*4+myint+3];
                            }
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        BasisFuns(spanV-1, us[2*jj+1], degV-1, &knotV[1], NV, leftV, rightV);
                        
                        for (i = 0; i < degV; i++){
                            for (j = 0; j <= degU; j++){
                                NN = NV[i] * NU[j];
                                dvep[threejj] += NN * dvcp[i*fourncp+j*4+myint];
                                dvep[threejj+1] += NN * dvcp[i*fourncp+j*4+myint+1];
                                dvep[threejj+2] += NN * dvcp[i*fourncp+j*4+myint+2];
                                dvwgh += NN * dvcp[i*fourncp+j*4+myint+3];
                            }
                        }
                        dvep[threejj] = (dvep[threejj] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvep[threejj+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvep[threejj+2] - dvwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanU-1, us[2*jj], degU-1, &knotU[1], NU, leftU, rightU);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        myint = ind2*fourncpm4+ind*4;
                        
                        for (i = 0; i <= degV; i++){
                            for (j = 0; j < degU; j++){
                                NN = NV[i] * NU[j];
                                duep[threejj] += NN * ducp[i*fourncpm4+j*4+myint];
                                duep[threejj+1] += NN * ducp[i*fourncpm4+j*4+myint+1];
                                duep[threejj+2] += NN * ducp[i*fourncpm4+j*4+myint+2];
                                duwgh += NN * ducp[i*fourncpm4+j*4+myint+3];
                            }
                        }
                        duep[threejj] = (duep[threejj] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (duep[threejj+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (duep[threejj+2] - duwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanU-2, us[2*jj], degU-2, &knotU[2], NU, leftU, rightU);
                        
                        myint = ind2*fourncpm8+ind*4;
                        
                        for (i = 0; i <= degV; i++){
                            for (j = 0; j <= (degU-2); j++){
                                NN = NV[i] * NU[j];
                                duuep[threejj] += NN * duucp[i*fourncpm8+j*4+myint];
                                duuep[threejj+1] += NN * duucp[i*fourncpm8+j*4+myint+1];
                                duuep[threejj+2] += NN * duucp[i*fourncpm8+j*4+myint+2];
                                duuwgh += NN * duucp[i*fourncpm8+j*4+myint+3];
                            }
                        }
                        duuep[threejj] = (duuep[threejj] - 2.0*duwgh*duep[threejj] - duuwgh*ep[threejj])/wgh;
                        duuep[threejj+1] = (duuep[threejj+1] - 2.0*duwgh*duep[threejj+1] - duuwgh*ep[threejj+1])/wgh;
                        duuep[threejj+2] = (duuep[threejj+2] - 2.0*duwgh*duep[threejj+2] - duuwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanU-1, us[2*jj], degU-1, &knotU[1], NU, leftU, rightU);
                        BasisFuns(spanV-1, us[2*jj+1], degV-1, &knotV[1], NV, leftV, rightV);
                        
                        myint = ind2*fourncpm4+ind*4;
                        
                        for (i = 0; i < degV; i++){
                            for (j = 0; j < degU; j++){
                                NN = NV[i] * NU[j];
                                duvep[threejj] += NN * duvcp[i*fourncpm4+j*4+myint];
                                duvep[threejj+1] += NN * duvcp[i*fourncpm4+j*4+myint+1];
                                duvep[threejj+2] += NN * duvcp[i*fourncpm4+j*4+myint+2];
                                duvwgh += NN * duvcp[i*fourncpm4+j*4+myint+3];
                            }
                        }
                        duvep[threejj] = (duvep[threejj] - duwgh*dvep[threejj] - dvwgh*duep[threejj] - duvwgh*ep[threejj])/wgh;
                        duvep[threejj+1] = (duvep[threejj+1] - duwgh*dvep[threejj+1] - dvwgh*duep[threejj+1] - duvwgh*ep[threejj+1])/wgh;
                        duvep[threejj+2] = (duvep[threejj+2] - duwgh*dvep[threejj+2] - dvwgh*duep[threejj+2] - duvwgh*ep[threejj+2])/wgh;
                        
                    }
                    
                }
                
            }
            
        }
        else {
            
            for (jj = 0; jj < nus; jj++){
                
                threejj = 3*jj;
                
                if (us[2*jj] <= knotU[degU]){
                    
                    if (us[2*jj+1] <= knotV[degV]){
                        
                        wgh = cp[3];
                        ep[threejj] = cp[0]/wgh;
                        ep[threejj+1] = cp[1]/wgh;
                        ep[threejj+2] = cp[2]/wgh;
                        
                        duep[threejj] = (ducp[0] - ducp[3]*ep[threejj])/wgh;
                        duep[threejj+1] = (ducp[1] - ducp[3]*ep[threejj+1])/wgh;
                        duep[threejj+2] = (ducp[2] - ducp[3]*ep[threejj+2])/wgh;
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        
                        duuep[threejj] = (duucp[0] - 2.0*ducp[3]*duep[threejj] - duucp[3]*ep[threejj])/wgh;
                        duuep[threejj+1] = (duucp[1] - 2.0*ducp[3]*duep[threejj+1] - duucp[3]*ep[threejj+1])/wgh;
                        duuep[threejj+2] = (duucp[2] - 2.0*ducp[3]*duep[threejj+2] - duucp[3]*ep[threejj+2])/wgh;
                        
                        duvep[threejj] = 0.0;
                        duvep[threejj+1] = 0.0;
                        duvep[threejj+2] = 0.0;
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        
                    }
                    else if (us[2*jj+1] >= knotV[kcp]){
                        
                        myint = fourncp*(kcp-1);
                        wgh = cp[myint+3];
                        ep[threejj] = cp[myint]/wgh;
                        ep[threejj+1] = cp[myint+1]/wgh;
                        ep[threejj+2] = cp[myint+2]/wgh;
                        
                        myint = fourncpm4*(kcp-1);
                        duwgh = ducp[myint+3];
                        duep[threejj] = (ducp[myint] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (ducp[myint+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (ducp[myint+2] - duwgh*ep[threejj+2])/wgh;
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        
                        myint = fourncpm8*(kcp-1);
                        duwgh *= 2.0;
                        duuep[threejj] = (duucp[myint] - duwgh*duep[threejj] - duucp[myint+3]*ep[threejj])/wgh;
                        duuep[threejj+1] = (duucp[myint+1] - duwgh*duep[threejj+1] - duucp[myint+3]*ep[threejj+1])/wgh;
                        duuep[threejj+2] = (duucp[myint+2] - duwgh*duep[threejj+2] - duucp[myint+3]*ep[threejj+2])/wgh;
                        
                        duvep[threejj] = 0.0;
                        duvep[threejj+1] = 0.0;
                        duvep[threejj+2] = 0.0;
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        
                    }
                    else {
                        
                        ep[threejj] = 0.0;
                        ep[threejj+1] = 0.0;
                        ep[threejj+2] = 0.0;
                        wgh = 0.0;
                        
                        spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        ind = spanV - degV;
                        
                        for (i = 0; i <= degV; i++){
                            myint = (ind+i)*fourncp;
                            ep[threejj] += NV[i] * cp[myint];
                            ep[threejj+1] += NV[i] * cp[myint+1];
                            ep[threejj+2] += NV[i] * cp[myint+2];
                            wgh += NV[i] * cp[myint+3];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        duwgh = 0.0;
                        
                        for (i = 0; i <= degV; i++){
                            myint = (ind+i)*fourncpm4;
                            duep[threejj] += NV[i] * ducp[myint];
                            duep[threejj+1] += NV[i] * ducp[myint+1];
                            duep[threejj+2] += NV[i] * ducp[myint+2];
                            duwgh += NV[i] * ducp[myint+3];
                        }
                        duep[threejj] = (duep[threejj] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (duep[threejj+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (duep[threejj+2] - duwgh*ep[threejj+2])/wgh;
                        
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        duuwgh = 0.0;
                        
                        for (i = 0; i <= degV; i++){
                            myint = (ind+i)*fourncpm8;
                            duuep[threejj] += NV[i] * duucp[myint];
                            duuep[threejj+1] += NV[i] * duucp[myint+1];
                            duuep[threejj+2] += NV[i] * duucp[myint+2];
                            duuwgh += NV[i] * duucp[myint+3];
                        }
                        duwgh *= 2.0;
                        duuep[threejj] = (duuep[threejj] - duwgh*duep[threejj] - duuwgh*ep[threejj])/wgh;
                        duuep[threejj+1] = (duuep[threejj+1] - duwgh*duep[threejj+1] - duuwgh*ep[threejj+1])/wgh;
                        duuep[threejj+2] = (duuep[threejj+2] - duwgh*duep[threejj+2] - duuwgh*ep[threejj+2])/wgh;
                        
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        
                        
                        duvep[threejj] = 0.0;
                        duvep[threejj+1] = 0.0;
                        duvep[threejj+2] = 0.0;
                        
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        
                    }
                    
                }
                else if (us[2*jj] >= knotU[ncp]){
                    
                    if (us[2*jj+1] <= knotV[degV]){
                        
                        wgh = cp[fourncp-1];
                        ep[threejj] = cp[fourncpm4]/wgh;
                        ep[threejj+1] = cp[fourncpm4+1]/wgh;
                        ep[threejj+2] = cp[fourncpm4+2]/wgh;
                        
                        duep[threejj] = (ducp[fourncpm4-4] - ducp[fourncpm4-1]*ep[threejj])/wgh;
                        duep[threejj+1] = (ducp[fourncpm4-3] - ducp[fourncpm4-1]*ep[threejj+1])/wgh;
                        duep[threejj+2] = (ducp[fourncpm4-2] - ducp[fourncpm4-1]*ep[threejj+2])/wgh;
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        
                        duuep[threejj] = (duucp[fourncpm8-4] - 2.0*ducp[fourncpm4-1]*duep[threejj] - duucp[fourncpm8-1]*ep[threejj])/wgh;
                        duuep[threejj+1] = (duucp[fourncpm8-3] - 2.0*ducp[fourncpm4-1]*duep[threejj+1] - duucp[fourncpm8-1]*ep[threejj+1])/wgh;
                        duuep[threejj+2] = (duucp[fourncpm8-2] - 2.0*ducp[fourncpm4-1]*duep[threejj+2] - duucp[fourncpm8-1]*ep[threejj+2])/wgh;
                        
                        duvep[threejj] = 0.0;
                        duvep[threejj+1] = 0.0;
                        duvep[threejj+2] = 0.0;
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        
                    }
                    else if (us[2*jj+1] >= knotV[kcp]){
                        
                        myint = fourncp*kcp;
                        wgh = cp[myint-1];
                        ep[threejj] = cp[myint-4]/wgh;
                        ep[threejj+1] = cp[myint-3]/wgh;
                        ep[threejj+2] = cp[myint-2]/wgh;
                        
                        myint = fourncpm4*kcp-4;
                        duwgh = ducp[myint+3];
                        duep[threejj] = (ducp[myint] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (ducp[myint+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (ducp[myint+2] - duwgh*ep[threejj+2])/wgh;
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        
                        myint = fourncpm8*kcp-4;
                        duwgh *= 2.0;
                        duuep[threejj] = (duucp[myint] - duwgh*duep[threejj] - duucp[myint+3]*ep[threejj])/wgh;
                        duuep[threejj+1] = (duucp[myint+1] - duwgh*duep[threejj+1] - duucp[myint+3]*ep[threejj+1])/wgh;
                        duuep[threejj+2] = (duucp[myint+2] - duwgh*duep[threejj+2] - duucp[myint+3]*ep[threejj+2])/wgh;
                        
                        duvep[threejj] = 0.0;
                        duvep[threejj+1] = 0.0;
                        duvep[threejj+2] = 0.0;
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        
                    }
                    else {
                        
                        ep[threejj] = 0.0;
                        ep[threejj+1] = 0.0;
                        ep[threejj+2] = 0.0;
                        wgh = 0.0;
                        
                        spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        ind = spanV - degV;
                        myint = (ind+1)*fourncp;
                        
                        for (i = 0; i <= degV; i++){
                            ep[threejj] += NV[i] * cp[i*fourncp+myint-4];
                            ep[threejj+1] += NV[i] * cp[i*fourncp+myint-3];
                            ep[threejj+2] += NV[i] * cp[i*fourncp+myint-2];
                            wgh += NV[i] * cp[i*fourncp+myint-1];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        duwgh = 0.0;
                        
                        for (i = 0; i <= degV; i++){
                            myint = (ind+i)*fourncpm4 + fourncpm8;
                            duep[threejj] += NV[i] * ducp[myint];
                            duep[threejj+1] += NV[i] * ducp[myint+1];
                            duep[threejj+2] += NV[i] * ducp[myint+2];
                            duwgh += NV[i] * ducp[myint+3];
                        }
                        duep[threejj] = (duep[threejj] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (duep[threejj+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (duep[threejj+2] - duwgh*ep[threejj+2])/wgh;
                        
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        duuwgh = 0.0;
                        
                        for (i = 0; i <= degV; i++){
                            myint = (ind+i)*fourncpm8 + fourncpm8 - 4;
                            duuep[threejj] += NV[i] * duucp[myint];
                            duuep[threejj+1] += NV[i] * duucp[myint+1];
                            duuep[threejj+2] += NV[i] * duucp[myint+2];
                            duuwgh += NV[i] * duucp[myint+3];
                        }
                        duwgh *= 2.0;
                        duuep[threejj] = (duuep[threejj] - duwgh*duep[threejj] - duuwgh*ep[threejj])/wgh;
                        duuep[threejj+1] = (duuep[threejj+1] - duwgh*duep[threejj+1] - duuwgh*ep[threejj+1])/wgh;
                        duuep[threejj+2] = (duuep[threejj+2] - duwgh*duep[threejj+2] - duuwgh*ep[threejj+2])/wgh;
                        
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        
                        
                        duvep[threejj] = 0.0;
                        duvep[threejj+1] = 0.0;
                        duvep[threejj+2] = 0.0;
                        
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        
                    }
                    
                }
                else {
                    
                    ep[threejj] = 0.0;
                    ep[threejj+1] = 0.0;
                    ep[threejj+2] = 0.0;
                    wgh = 0.0;
                    
                    duep[threejj] = 0.0;
                    duep[threejj+1] = 0.0;
                    duep[threejj+2] = 0.0;
                    duwgh = 0.0;
                    
                    dvep[threejj] = 0.0;
                    dvep[threejj+1] = 0.0;
                    dvep[threejj+2] = 0.0;
                    
                    duuep[threejj] = 0.0;
                    duuep[threejj+1] = 0.0;
                    duuep[threejj+2] = 0.0;
                    duuwgh = 0.0;
                    
                    duvep[threejj] = 0.0;
                    duvep[threejj+1] = 0.0;
                    duvep[threejj+2] = 0.0;
                    
                    dvvep[threejj] = 0.0;
                    dvvep[threejj+1] = 0.0;
                    dvvep[threejj+2] = 0.0;
                    
                    if (us[2*jj+1] <= knotV[degV]){
                        
                        spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                        BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                        
                        ind = spanU - degU;
                        
                        for (i = 0; i <= degU; i++){
                            ep[threejj] += NU[i] * cp[(ind+i)*4];
                            ep[threejj+1] += NU[i] * cp[(ind+i)*4+1];
                            ep[threejj+2] += NU[i] * cp[(ind+i)*4+2];
                            wgh += NU[i] * cp[(ind+i)*4+3];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        BasisFuns(spanU-1, us[2*jj], degU-1, &knotU[1], NU, leftU, rightU);
                        
                        for (i = 0; i < degU; i++){
                            duep[threejj] += NU[i] * ducp[(ind+i)*4];
                            duep[threejj+1] += NU[i] * ducp[(ind+i)*4+1];
                            duep[threejj+2] += NU[i] * ducp[(ind+i)*4+2];
                            duwgh += NU[i] * ducp[(ind+i)*4+3];
                        }
                        duep[threejj] = (duep[threejj] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (duep[threejj+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (duep[threejj+2] - duwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanU-2, us[2*jj], degU-2, &knotU[2], NU, leftU, rightU);
                        
                        for (i = 0; i <= (degU-2); i++){
                            duuep[threejj] += NU[i] * duucp[(ind+i)*4];
                            duuep[threejj+1] += NU[i] * duucp[(ind+i)*4+1];
                            duuep[threejj+2] += NU[i] * duucp[(ind+i)*4+2];
                            duuwgh += NU[i] * duucp[(ind+i)*4+3];
                        }
                        duwgh *= 2.0;
                        duuep[threejj] = (duuep[threejj] - duwgh*duep[threejj] - duuwgh*ep[threejj])/wgh;
                        duuep[threejj+1] = (duuep[threejj+1] - duwgh*duep[threejj+1] - duuwgh*ep[threejj+1])/wgh;
                        duuep[threejj+2] = (duuep[threejj+2] - duwgh*duep[threejj+2] - duuwgh*ep[threejj+2])/wgh;
                        
                    }
                    else if (us[2*jj+1] >= knotV[kcp]){
                        
                        spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                        BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                        
                        ind = spanU - degU;
                        myint = ind*4+(kcp-1)*fourncp;
                        
                        for (i = 0; i <= degU; i++){
                            ep[threejj] += NU[i] * cp[i*4+myint];
                            ep[threejj+1] += NU[i] * cp[i*4+myint+1];
                            ep[threejj+2] += NU[i] * cp[i*4+myint+2];
                            wgh += NU[i] * cp[i*4+myint+3];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        BasisFuns(spanU-1, us[2*jj], degU-1, &knotU[1], NU, leftU, rightU);
                        
                        ind = spanU - degU + (ncp-1)*(kcp-1);
                        
                        for (i = 0; i < degU; i++){
                            duep[threejj] += NU[i] * ducp[(ind+i)*4];
                            duep[threejj+1] += NU[i] * ducp[(ind+i)*4+1];
                            duep[threejj+2] += NU[i] * ducp[(ind+i)*4+2];
                            duwgh += NU[i] * ducp[(ind+i)*4+3];
                        }
                        duep[threejj] = (duep[threejj] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (duep[threejj+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (duep[threejj+2] - duwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanU-2, us[2*jj], degU-2, &knotU[2], NU, leftU, rightU);
                        
                        ind = spanU - degU + (ncp-2)*(kcp-1);
                        
                        for (i = 0; i <= (degU-2); i++){
                            duuep[threejj] += NU[i] * duucp[(ind+i)*4];
                            duuep[threejj+1] += NU[i] * duucp[(ind+i)*4+1];
                            duuep[threejj+2] += NU[i] * duucp[(ind+i)*4+2];
                            duuwgh += NU[i] * duucp[(ind+i)*4+3];
                        }
                        duwgh *= 2.0;
                        duuep[threejj] = (duuep[threejj] - duwgh*duep[threejj] - duuwgh*ep[threejj])/wgh;
                        duuep[threejj+1] = (duuep[threejj+1] - duwgh*duep[threejj+1] - duuwgh*ep[threejj+1])/wgh;
                        duuep[threejj+2] = (duuep[threejj+2] - duwgh*duep[threejj+2] - duuwgh*ep[threejj+2])/wgh;
                        
                    }
                    else {
                        
                        spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                        BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                        
                        spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        ind = spanU - degU;
                        ind2 = spanV - degV;
                        myint = ind2*fourncp+ind*4;
                        
                        for (i = 0; i <= degV; i++){
                            for (j = 0; j <= degU; j++){
                                NN = NV[i] * NU[j];
                                ep[threejj] += NN * cp[i*fourncp+j*4+myint];
                                ep[threejj+1] += NN * cp[i*fourncp+j*4+myint+1];
                                ep[threejj+2] += NN * cp[i*fourncp+j*4+myint+2];
                                wgh += NN * cp[i*fourncp+j*4+myint+3];
                            }
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        BasisFuns(spanU-1, us[2*jj], degU-1, &knotU[1], NU, leftU, rightU);
                        
                        myint = ind2*fourncpm4+ind*4;
                        
                        for (i = 0; i <= degV; i++){
                            for (j = 0; j < degU; j++){
                                NN = NV[i] * NU[j];
                                duep[threejj] += NN * ducp[i*fourncpm4+j*4+myint];
                                duep[threejj+1] += NN * ducp[i*fourncpm4+j*4+myint+1];
                                duep[threejj+2] += NN * ducp[i*fourncpm4+j*4+myint+2];
                                duwgh += NN * ducp[i*fourncpm4+j*4+myint+3];
                            }
                        }
                        duep[threejj] = (duep[threejj] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (duep[threejj+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (duep[threejj+2] - duwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanU-2, us[2*jj], degU-2, &knotU[2], NU, leftU, rightU);
                        
                        myint = ind2*fourncpm8+ind*4;
                        
                        for (i = 0; i <= degV; i++){
                            for (j = 0; j <= (degU-2); j++){
                                NN = NV[i] * NU[j];
                                duuep[threejj] += NN * duucp[i*fourncpm8+j*4+myint];
                                duuep[threejj+1] += NN * duucp[i*fourncpm8+j*4+myint+1];
                                duuep[threejj+2] += NN * duucp[i*fourncpm8+j*4+myint+2];
                                duuwgh += NN * duucp[i*fourncpm8+j*4+myint+3];
                            }
                        }
                        duwgh *= 2.0;
                        duuep[threejj] = (duuep[threejj] - duwgh*duep[threejj] - duuwgh*ep[threejj])/wgh;
                        duuep[threejj+1] = (duuep[threejj+1] - duwgh*duep[threejj+1] - duuwgh*ep[threejj+1])/wgh;
                        duuep[threejj+2] = (duuep[threejj+2] - duwgh*duep[threejj+2] - duuwgh*ep[threejj+2])/wgh;
                        
                    }
                    
                }
                
            }
            
        }
        
    }
    else if (degU==1){
        
        if (degV>1){
            
            for (jj = 0; jj < nus; jj++){
                
                threejj = 3*jj;
                
                if (us[2*jj] <= knotU[degU]){
                    
                    if (us[2*jj+1] <= knotV[degV]){
                        
                        wgh = cp[3];
                        ep[threejj] = cp[0]/wgh;
                        ep[threejj+1] = cp[1]/wgh;
                        ep[threejj+2] = cp[2]/wgh;
                        
                        duep[threejj] = (ducp[0] - ducp[3]*ep[threejj])/wgh;
                        duep[threejj+1] = (ducp[1] - ducp[3]*ep[threejj+1])/wgh;
                        duep[threejj+2] = (ducp[2] - ducp[3]*ep[threejj+2])/wgh;
                        
                        dvep[threejj] = (dvcp[0] - dvcp[3]*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvcp[1] - dvcp[3]*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvcp[2] - dvcp[3]*ep[threejj+2])/wgh;
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        
                        duvep[threejj] = (duvcp[0] - ducp[3]*dvep[threejj] - dvcp[3]*duep[threejj] - duvcp[3]*ep[threejj])/wgh;
                        duvep[threejj+1] = (duvcp[1] - ducp[3]*dvep[threejj+1] - dvcp[3]*duep[threejj+1] - duvcp[3]*ep[threejj+1])/wgh;
                        duvep[threejj+2] = (duvcp[2] - ducp[3]*dvep[threejj+2] - dvcp[3]*duep[threejj+2] - duvcp[3]*ep[threejj+2])/wgh;
                        
                        dvvep[threejj] = (dvvcp[0] - 2.0*dvcp[3]*dvep[threejj] - dvvcp[3]*ep[threejj])/wgh;
                        dvvep[threejj+1] = (dvvcp[1] - 2.0*dvcp[3]*dvep[threejj+1] - dvvcp[3]*ep[threejj+1])/wgh;
                        dvvep[threejj+2] = (dvvcp[2] - 2.0*dvcp[3]*dvep[threejj+2] - dvvcp[3]*ep[threejj+2])/wgh;
                        
                    }
                    else if (us[2*jj+1] >= knotV[kcp]){
                        
                        myint = fourncp*(kcp-1);
                        wgh = cp[myint+3];
                        ep[threejj] = cp[myint]/wgh;
                        ep[threejj+1] = cp[myint+1]/wgh;
                        ep[threejj+2] = cp[myint+2]/wgh;
                        
                        myint = fourncpm4*(kcp-1);
                        duwgh = ducp[myint+3];
                        duep[threejj] = (ducp[myint] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (ducp[myint+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (ducp[myint+2] - duwgh*ep[threejj+2])/wgh;
                        
                        myint = fourncp*(kcp-2);
                        dvwgh = dvcp[myint+3];
                        dvep[threejj] = (dvcp[myint] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvcp[myint+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvcp[myint+2] - dvwgh*ep[threejj+2])/wgh;
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        
                        myint = fourncpm4*(kcp-2);
                        duvep[threejj] = (duvcp[myint] - duwgh*dvep[threejj] - dvwgh*duep[threejj] - duvcp[myint+3]*ep[threejj])/wgh;
                        duvep[threejj+1] = (duvcp[myint+1] - duwgh*dvep[threejj+1] - dvwgh*duep[threejj+1] - duvcp[myint+3]*ep[threejj+1])/wgh;
                        duvep[threejj+2] = (duvcp[myint+2] - duwgh*dvep[threejj+2] - dvwgh*duep[threejj+2] - duvcp[myint+3]*ep[threejj+2])/wgh;
                        
                        myint = fourncp*(kcp-3);
                        dvwgh *= 2.0;
                        dvvep[threejj] = (dvvcp[myint] - dvwgh*dvep[threejj] - dvvcp[myint+3]*ep[threejj])/wgh;
                        dvvep[threejj+1] = (dvvcp[myint+1] - dvwgh*dvep[threejj+1] - dvvcp[myint+3]*ep[threejj+1])/wgh;
                        dvvep[threejj+2] = (dvvcp[myint+2] - dvwgh*dvep[threejj+2] - dvvcp[myint+3]*ep[threejj+2])/wgh;
                        
                    }
                    else {
                        
                        ep[threejj] = 0.0;
                        ep[threejj+1] = 0.0;
                        ep[threejj+2] = 0.0;
                        wgh = 0.0;
                        
                        spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        ind = spanV - degV;
                        
                        for (i = 0; i <= degV; i++){
                            myint = (ind+i)*fourncp;
                            ep[threejj] += NV[i] * cp[myint];
                            ep[threejj+1] += NV[i] * cp[myint+1];
                            ep[threejj+2] += NV[i] * cp[myint+2];
                            wgh += NV[i] * cp[myint+3];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        duwgh = 0.0;
                        
                        for (i = 0; i <= degV; i++){
                            myint = (ind+i)*fourncpm4;
                            duep[threejj] += NV[i] * ducp[myint];
                            duep[threejj+1] += NV[i] * ducp[myint+1];
                            duep[threejj+2] += NV[i] * ducp[myint+2];
                            duwgh += NV[i] * ducp[myint+3];
                        }
                        duep[threejj] = (duep[threejj] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (duep[threejj+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (duep[threejj+2] - duwgh*ep[threejj+2])/wgh;
                        
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        
                        
                        BasisFuns(spanV-1, us[2*jj+1], degV-1, &knotV[1], NV, leftV, rightV);
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        dvwgh = 0.0;
                        
                        for (i = 0; i < degV; i++){
                            myint = (ind+i)*fourncp;
                            dvep[threejj] += NV[i] * dvcp[myint];
                            dvep[threejj+1] += NV[i] * dvcp[myint+1];
                            dvep[threejj+2] += NV[i] * dvcp[myint+2];
                            dvwgh += NV[i] * dvcp[myint+3];
                        }
                        dvep[threejj] = (dvep[threejj] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvep[threejj+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvep[threejj+2] - dvwgh*ep[threejj+2])/wgh;
                        
                        
                        duvep[threejj] = 0.0;
                        duvep[threejj+1] = 0.0;
                        duvep[threejj+2] = 0.0;
                        duvwgh = 0.0;
                        
                        for (i = 0; i < degV; i++){
                            myint = (ind+i)*fourncpm4;
                            duvep[threejj] += NV[i] * duvcp[myint];
                            duvep[threejj+1] += NV[i] * duvcp[myint+1];
                            duvep[threejj+2] += NV[i] * duvcp[myint+2];
                            duvwgh += NV[i] * duvcp[myint+3];
                        }
                        duvep[threejj] = (duvep[threejj] - duwgh*dvep[threejj] - dvwgh*duep[threejj] - duvwgh*ep[threejj])/wgh;
                        duvep[threejj+1] = (duvep[threejj+1] - duwgh*dvep[threejj+1] - dvwgh*duep[threejj+1] - duvwgh*ep[threejj+1])/wgh;
                        duvep[threejj+2] = (duvep[threejj+2] - duwgh*dvep[threejj+2] - dvwgh*duep[threejj+2] - duvwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanV-2, us[2*jj+1], degV-2, &knotV[2], NV, leftV, rightV);
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        dvvwgh = 0.0;
                        
                        for (i = 0; i <= (degV-2); i++){
                            myint = (ind+i)*fourncp;
                            dvvep[threejj] += NV[i] * dvvcp[myint];
                            dvvep[threejj+1] += NV[i] * dvvcp[myint+1];
                            dvvep[threejj+2] += NV[i] * dvvcp[myint+2];
                            dvvwgh += NV[i] * dvvcp[myint+3];
                        }
                        dvwgh *= 2.0;
                        dvvep[threejj] = (dvvep[threejj] - dvwgh*dvep[threejj] - dvvwgh*ep[threejj])/wgh;
                        dvvep[threejj+1] = (dvvep[threejj+1] - dvwgh*dvep[threejj+1] - dvvwgh*ep[threejj+1])/wgh;
                        dvvep[threejj+2] = (dvvep[threejj+2] - dvwgh*dvep[threejj+2] - dvvwgh*ep[threejj+2])/wgh;
                        
                    }
                    
                }
                else if (us[2*jj] >= knotU[ncp]){
                    
                    if (us[2*jj+1] <= knotV[degV]){
                        
                        wgh = cp[fourncp-1];
                        ep[threejj] = cp[fourncpm4]/wgh;
                        ep[threejj+1] = cp[fourncpm4+1]/wgh;
                        ep[threejj+2] = cp[fourncpm4+2]/wgh;
                        
                        duep[threejj] = (ducp[fourncpm4-4] - ducp[fourncpm4-1]*ep[threejj])/wgh;
                        duep[threejj+1] = (ducp[fourncpm4-3] - ducp[fourncpm4-1]*ep[threejj+1])/wgh;
                        duep[threejj+2] = (ducp[fourncpm4-2] - ducp[fourncpm4-1]*ep[threejj+2])/wgh;
                        
                        dvep[threejj] = (dvcp[fourncpm4] - dvcp[fourncpm4+3]*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvcp[fourncpm4+1] - dvcp[fourncpm4+3]*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvcp[fourncpm4+2] - dvcp[fourncpm4+3]*ep[threejj+2])/wgh;
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        
                        duvep[threejj] = (duvcp[fourncpm4-4] - ducp[fourncpm4-1]*dvep[threejj] - dvcp[fourncpm4+3]*duep[threejj] - duvcp[fourncpm4-1]*ep[threejj])/wgh;
                        duvep[threejj+1] = (duvcp[fourncpm4-3] - ducp[fourncpm4-1]*dvep[threejj+1] - dvcp[fourncpm4+3]*duep[threejj+1] - duvcp[fourncpm4-1]*ep[threejj+1])/wgh;
                        duvep[threejj+2] = (duvcp[fourncpm4-2] - ducp[fourncpm4-1]*dvep[threejj+2] - dvcp[fourncpm4+3]*duep[threejj+2] - duvcp[fourncpm4-1]*ep[threejj+2])/wgh;
                        
                        dvvep[threejj] = (dvvcp[fourncpm4] - 2.0*dvcp[fourncpm4+3]*dvep[threejj] - dvvcp[fourncpm4+3]*ep[threejj])/wgh;
                        dvvep[threejj+1] = (dvvcp[fourncpm4+1] - 2.0*dvcp[fourncpm4+3]*dvep[threejj+1] - dvvcp[fourncpm4+3]*ep[threejj+1])/wgh;
                        dvvep[threejj+2] = (dvvcp[fourncpm4+2] - 2.0*dvcp[fourncpm4+3]*dvep[threejj+2] - dvvcp[fourncpm4+3]*ep[threejj+2])/wgh;
                        
                    }
                    else if (us[2*jj+1] >= knotV[kcp]){
                        
                        myint = fourncp*kcp;
                        wgh = cp[myint-1];
                        ep[threejj] = cp[myint-4]/wgh;
                        ep[threejj+1] = cp[myint-3]/wgh;
                        ep[threejj+2] = cp[myint-2]/wgh;
                        
                        myint = fourncpm4*kcp-4;
                        duwgh = ducp[myint+3];
                        duep[threejj] = (ducp[myint] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (ducp[myint+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (ducp[myint+2] - duwgh*ep[threejj+2])/wgh;
                        
                        myint = fourncp*(kcp-1)-4;
                        dvwgh = dvcp[myint+3];
                        dvep[threejj] = (dvcp[myint] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvcp[myint+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvcp[myint+2] - dvwgh*ep[threejj+2])/wgh;
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        
                        myint = fourncpm4*(kcp-1)-4;
                        duvep[threejj] = (duvcp[myint] - duwgh*dvep[threejj] - dvwgh*duep[threejj] - duvcp[myint+3]*ep[threejj])/wgh;
                        duvep[threejj+1] = (duvcp[myint+1] - duwgh*dvep[threejj+1] - dvwgh*duep[threejj+1] - duvcp[myint+3]*ep[threejj+1])/wgh;
                        duvep[threejj+2] = (duvcp[myint+2] - duwgh*dvep[threejj+2] - dvwgh*duep[threejj+2] - duvcp[myint+3]*ep[threejj+2])/wgh;
                        
                        myint = fourncp*(kcp-2)-4;
                        dvwgh *= 2.0;
                        dvvep[threejj] = (dvvcp[myint] - dvwgh*dvep[threejj] - dvvcp[myint+3]*ep[threejj])/wgh;
                        dvvep[threejj+1] = (dvvcp[myint+1] - dvwgh*dvep[threejj+1] - dvvcp[myint+3]*ep[threejj+1])/wgh;
                        dvvep[threejj+2] = (dvvcp[myint+2] - dvwgh*dvep[threejj+2] - dvvcp[myint+3]*ep[threejj+2])/wgh;
                        
                    }
                    else {
                        
                        ep[threejj] = 0.0;
                        ep[threejj+1] = 0.0;
                        ep[threejj+2] = 0.0;
                        wgh = 0.0;
                        
                        spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        ind = spanV - degV;
                        myint = (ind+1)*fourncp;
                        
                        for (i = 0; i <= degV; i++){
                            ep[threejj] += NV[i] * cp[i*fourncp+myint-4];
                            ep[threejj+1] += NV[i] * cp[i*fourncp+myint-3];
                            ep[threejj+2] += NV[i] * cp[i*fourncp+myint-2];
                            wgh += NV[i] * cp[i*fourncp+myint-1];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        duwgh = 0.0;
                        
                        for (i = 0; i <= degV; i++){
                            myint = (ind+i)*fourncpm4 + fourncpm8;
                            duep[threejj] += NV[i] * ducp[myint];
                            duep[threejj+1] += NV[i] * ducp[myint+1];
                            duep[threejj+2] += NV[i] * ducp[myint+2];
                            duwgh += NV[i] * ducp[myint+3];
                        }
                        duep[threejj] = (duep[threejj] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (duep[threejj+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (duep[threejj+2] - duwgh*ep[threejj+2])/wgh;
                        
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        
                        
                        BasisFuns(spanV-1, us[2*jj+1], degV-1, &knotV[1], NV, leftV, rightV);
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        dvwgh = 0.0;
                        
                        for (i = 0; i < degV; i++){
                            myint = (ind+i)*fourncp + fourncpm4;
                            dvep[threejj] += NV[i] * dvcp[myint];
                            dvep[threejj+1] += NV[i] * dvcp[myint+1];
                            dvep[threejj+2] += NV[i] * dvcp[myint+2];
                            dvwgh += NV[i] * dvcp[myint+3];
                        }
                        dvep[threejj] = (dvep[threejj] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvep[threejj+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvep[threejj+2] - dvwgh*ep[threejj+2])/wgh;
                        
                        
                        duvep[threejj] = 0.0;
                        duvep[threejj+1] = 0.0;
                        duvep[threejj+2] = 0.0;
                        duvwgh = 0.0;
                        
                        for (i = 0; i < degV; i++){
                            myint = (ind+i)*fourncpm4 + fourncpm8;
                            duvep[threejj] += NV[i] * duvcp[myint];
                            duvep[threejj+1] += NV[i] * duvcp[myint+1];
                            duvep[threejj+2] += NV[i] * duvcp[myint+2];
                            duvwgh += NV[i] * duvcp[myint+3];
                        }
                        duvep[threejj] = (duvep[threejj] - duwgh*dvep[threejj] - dvwgh*duep[threejj] - duvwgh*ep[threejj])/wgh;
                        duvep[threejj+1] = (duvep[threejj+1] - duwgh*dvep[threejj+1] - dvwgh*duep[threejj+1] - duvwgh*ep[threejj+1])/wgh;
                        duvep[threejj+2] = (duvep[threejj+2] - duwgh*dvep[threejj+2] - dvwgh*duep[threejj+2] - duvwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanV-2, us[2*jj+1], degV-2, &knotV[2], NV, leftV, rightV);
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        dvvwgh = 0.0;
                        
                        for (i = 0; i <= (degV-2); i++){
                            myint = (ind+i)*fourncp + fourncpm4;
                            dvvep[threejj] += NV[i] * dvvcp[myint];
                            dvvep[threejj+1] += NV[i] * dvvcp[myint+1];
                            dvvep[threejj+2] += NV[i] * dvvcp[myint+2];
                            dvvwgh += NV[i] * dvvcp[myint+3];
                        }
                        dvwgh *= 2.0;
                        dvvep[threejj] = (dvvep[threejj] - dvwgh*dvep[threejj] - dvvwgh*ep[threejj])/wgh;
                        dvvep[threejj+1] = (dvvep[threejj+1] - dvwgh*dvep[threejj+1] - dvvwgh*ep[threejj+1])/wgh;
                        dvvep[threejj+2] = (dvvep[threejj+2] - dvwgh*dvep[threejj+2] - dvvwgh*ep[threejj+2])/wgh;
                        
                    }
                    
                }
                else {
                    
                    ep[threejj] = 0.0;
                    ep[threejj+1] = 0.0;
                    ep[threejj+2] = 0.0;
                    wgh = 0.0;
                    
                    duep[threejj] = 0.0;
                    duep[threejj+1] = 0.0;
                    duep[threejj+2] = 0.0;
                    duwgh = 0.0;
                    
                    dvep[threejj] = 0.0;
                    dvep[threejj+1] = 0.0;
                    dvep[threejj+2] = 0.0;
                    dvwgh = 0.0;
                    
                    duuep[threejj] = 0.0;
                    duuep[threejj+1] = 0.0;
                    duuep[threejj+2] = 0.0;
                    
                    duvep[threejj] = 0.0;
                    duvep[threejj+1] = 0.0;
                    duvep[threejj+2] = 0.0;
                    duvwgh = 0.0;
                    
                    dvvep[threejj] = 0.0;
                    dvvep[threejj+1] = 0.0;
                    dvvep[threejj+2] = 0.0;
                    dvvwgh = 0.0;
                    
                    if (us[2*jj+1] <= knotV[degV]){
                        
                        spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                        BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                        
                        ind = spanU - degU;
                        
                        for (i = 0; i <= degU; i++){
                            ep[threejj] += NU[i] * cp[(ind+i)*4];
                            ep[threejj+1] += NU[i] * cp[(ind+i)*4+1];
                            ep[threejj+2] += NU[i] * cp[(ind+i)*4+2];
                            wgh += NU[i] * cp[(ind+i)*4+3];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        for (i = 0; i <= degU; i++){
                            dvep[threejj] += NU[i] * dvcp[(ind+i)*4];
                            dvep[threejj+1] += NU[i] * dvcp[(ind+i)*4+1];
                            dvep[threejj+2] += NU[i] * dvcp[(ind+i)*4+2];
                            dvwgh += NU[i] * dvcp[(ind+i)*4+3];
                        }
                        dvep[threejj] = (dvep[threejj] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvep[threejj+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvep[threejj+2] - dvwgh*ep[threejj+2])/wgh;
                        
                        
                        for (i = 0; i <= degU; i++){
                            dvvep[threejj] += NU[i] * dvvcp[(ind+i)*4];
                            dvvep[threejj+1] += NU[i] * dvvcp[(ind+i)*4+1];
                            dvvep[threejj+2] += NU[i] * dvvcp[(ind+i)*4+2];
                            dvvwgh += NU[i] * dvvcp[(ind+i)*4+3];
                        }
                        dvvep[threejj] = (dvvep[threejj] - 2.0*dvwgh*dvep[threejj] - dvvwgh*ep[threejj])/wgh;
                        dvvep[threejj+1] = (dvvep[threejj+1] - 2.0*dvwgh*dvep[threejj+1] - dvvwgh*ep[threejj+1])/wgh;
                        dvvep[threejj+2] = (dvvep[threejj+2] - 2.0*dvwgh*dvep[threejj+2] - dvvwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanU-1, us[2*jj], degU-1, &knotU[1], NU, leftU, rightU);
                        
                        for (i = 0; i < degU; i++){
                            duep[threejj] += NU[i] * ducp[(ind+i)*4];
                            duep[threejj+1] += NU[i] * ducp[(ind+i)*4+1];
                            duep[threejj+2] += NU[i] * ducp[(ind+i)*4+2];
                            duwgh += NU[i] * ducp[(ind+i)*4+3];
                        }
                        duep[threejj] = (duep[threejj] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (duep[threejj+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (duep[threejj+2] - duwgh*ep[threejj+2])/wgh;
                        
                        
                        for (i = 0; i < degU; i++){
                            duvep[threejj] += NU[i] * duvcp[(ind+i)*4];
                            duvep[threejj+1] += NU[i] * duvcp[(ind+i)*4+1];
                            duvep[threejj+2] += NU[i] * duvcp[(ind+i)*4+2];
                            duvwgh += NU[i] * duvcp[(ind+i)*4+3];
                        }
                        duvep[threejj] = (duvep[threejj] - duwgh*dvep[threejj] - dvwgh*duep[threejj] - duvwgh*ep[threejj])/wgh;
                        duvep[threejj+1] = (duvep[threejj+1] - duwgh*dvep[threejj+1] - dvwgh*duep[threejj+1] - duvwgh*ep[threejj+1])/wgh;
                        duvep[threejj+2] = (duvep[threejj+2] - duwgh*dvep[threejj+2] - dvwgh*duep[threejj+2] - duvwgh*ep[threejj+2])/wgh;
                        
                    }
                    else if (us[2*jj+1] >= knotV[kcp]){
                        
                        spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                        BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                        
                        ind = spanU - degU;
                        myint = ind*4+(kcp-1)*fourncp;
                        
                        for (i = 0; i <= degU; i++){
                            ep[threejj] += NU[i] * cp[i*4+myint];
                            ep[threejj+1] += NU[i] * cp[i*4+myint+1];
                            ep[threejj+2] += NU[i] * cp[i*4+myint+2];
                            wgh += NU[i] * cp[i*4+myint+3];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        ind = spanU - degU + ncp*(kcp-2);
                        
                        for (i = 0; i <= degU; i++){
                            dvep[threejj] += NU[i] * dvcp[(ind+i)*4];
                            dvep[threejj+1] += NU[i] * dvcp[(ind+i)*4+1];
                            dvep[threejj+2] += NU[i] * dvcp[(ind+i)*4+2];
                            dvwgh += NU[i] * dvcp[(ind+i)*4+3];
                        }
                        dvep[threejj] = (dvep[threejj] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvep[threejj+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvep[threejj+2] - dvwgh*ep[threejj+2])/wgh;
                        
                        
                        ind = spanU - degU + ncp*(kcp-3);
                        
                        for (i = 0; i <= degU; i++){
                            dvvep[threejj] += NU[i] * dvvcp[(ind+i)*4];
                            dvvep[threejj+1] += NU[i] * dvvcp[(ind+i)*4+1];
                            dvvep[threejj+2] += NU[i] * dvvcp[(ind+i)*4+2];
                            dvvwgh += NU[i] * dvvcp[(ind+i)*4+3];
                        }
                        dvvep[threejj] = (dvvep[threejj] - 2.0*dvwgh*dvep[threejj] - dvvwgh*ep[threejj])/wgh;
                        dvvep[threejj+1] = (dvvep[threejj+1] - 2.0*dvwgh*dvep[threejj+1] - dvvwgh*ep[threejj+1])/wgh;
                        dvvep[threejj+2] = (dvvep[threejj+2] - 2.0*dvwgh*dvep[threejj+2] - dvvwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanU-1, us[2*jj], degU-1, &knotU[1], NU, leftU, rightU);
                        
                        ind = spanU - degU + (ncp-1)*(kcp-1);
                        
                        for (i = 0; i < degU; i++){
                            duep[threejj] += NU[i] * ducp[(ind+i)*4];
                            duep[threejj+1] += NU[i] * ducp[(ind+i)*4+1];
                            duep[threejj+2] += NU[i] * ducp[(ind+i)*4+2];
                            duwgh += NU[i] * ducp[(ind+i)*4+3];
                        }
                        duep[threejj] = (duep[threejj] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (duep[threejj+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (duep[threejj+2] - duwgh*ep[threejj+2])/wgh;
                        
                        
                        ind = spanU - degU + (ncp-1)*(kcp-2);
                        
                        for (i = 0; i < degU; i++){
                            duvep[threejj] += NU[i] * duvcp[(ind+i)*4];
                            duvep[threejj+1] += NU[i] * duvcp[(ind+i)*4+1];
                            duvep[threejj+2] += NU[i] * duvcp[(ind+i)*4+2];
                            duvwgh += NU[i] * duvcp[(ind+i)*4+3];
                        }
                        duvep[threejj] = (duvep[threejj] - duwgh*dvep[threejj] - dvwgh*duep[threejj] - duvwgh*ep[threejj])/wgh;
                        duvep[threejj+1] = (duvep[threejj+1] - duwgh*dvep[threejj+1] - dvwgh*duep[threejj+1] - duvwgh*ep[threejj+1])/wgh;
                        duvep[threejj+2] = (duvep[threejj+2] - duwgh*dvep[threejj+2] - dvwgh*duep[threejj+2] - duvwgh*ep[threejj+2])/wgh;
                        
                    }
                    else {
                        
                        spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                        BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                        
                        spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        ind = spanU - degU;
                        ind2 = spanV - degV;
                        myint = ind2*fourncp+ind*4;
                        
                        for (i = 0; i <= degV; i++){
                            for (j = 0; j <= degU; j++){
                                NN = NV[i] * NU[j];
                                ep[threejj] += NN * cp[i*fourncp+j*4+myint];
                                ep[threejj+1] += NN * cp[i*fourncp+j*4+myint+1];
                                ep[threejj+2] += NN * cp[i*fourncp+j*4+myint+2];
                                wgh += NN * cp[i*fourncp+j*4+myint+3];
                            }
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        BasisFuns(spanV-1, us[2*jj+1], degV-1, &knotV[1], NV, leftV, rightV);
                        
                        for (i = 0; i < degV; i++){
                            for (j = 0; j <= degU; j++){
                                NN = NV[i] * NU[j];
                                dvep[threejj] += NN * dvcp[i*fourncp+j*4+myint];
                                dvep[threejj+1] += NN * dvcp[i*fourncp+j*4+myint+1];
                                dvep[threejj+2] += NN * dvcp[i*fourncp+j*4+myint+2];
                                dvwgh += NN * dvcp[i*fourncp+j*4+myint+3];
                            }
                        }
                        dvep[threejj] = (dvep[threejj] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvep[threejj+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvep[threejj+2] - dvwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanV-2, us[2*jj+1], degV-2, &knotV[2], NV, leftV, rightV);
                        
                        for (i = 0; i <= (degV-2); i++){
                            for (j = 0; j <= degU; j++){
                                NN = NV[i] * NU[j];
                                dvvep[threejj] += NN * dvvcp[i*fourncp+j*4+myint];
                                dvvep[threejj+1] += NN * dvvcp[i*fourncp+j*4+myint+1];
                                dvvep[threejj+2] += NN * dvvcp[i*fourncp+j*4+myint+2];
                                dvvwgh += NN * dvvcp[i*fourncp+j*4+myint+3];
                            }
                        }
                        dvvep[threejj] = (dvvep[threejj] - 2.0*dvwgh*dvep[threejj] - dvvwgh*ep[threejj])/wgh;
                        dvvep[threejj+1] = (dvvep[threejj+1] - 2.0*dvwgh*dvep[threejj+1] - dvvwgh*ep[threejj+1])/wgh;
                        dvvep[threejj+2] = (dvvep[threejj+2] - 2.0*dvwgh*dvep[threejj+2] - dvvwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanU-1, us[2*jj], degU-1, &knotU[1], NU, leftU, rightU);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        myint = ind2*fourncpm4+ind*4;
                        
                        for (i = 0; i <= degV; i++){
                            for (j = 0; j < degU; j++){
                                NN = NV[i] * NU[j];
                                duep[threejj] += NN * ducp[i*fourncpm4+j*4+myint];
                                duep[threejj+1] += NN * ducp[i*fourncpm4+j*4+myint+1];
                                duep[threejj+2] += NN * ducp[i*fourncpm4+j*4+myint+2];
                                duwgh += NN * ducp[i*fourncpm4+j*4+myint+3];
                            }
                        }
                        duep[threejj] = (duep[threejj] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (duep[threejj+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (duep[threejj+2] - duwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanU-1, us[2*jj], degU-1, &knotU[1], NU, leftU, rightU);
                        BasisFuns(spanV-1, us[2*jj+1], degV-1, &knotV[1], NV, leftV, rightV);
                        
                        myint = ind2*fourncpm4+ind*4;
                        
                        for (i = 0; i < degV; i++){
                            for (j = 0; j < degU; j++){
                                NN = NV[i] * NU[j];
                                duvep[threejj] += NN * duvcp[i*fourncpm4+j*4+myint];
                                duvep[threejj+1] += NN * duvcp[i*fourncpm4+j*4+myint+1];
                                duvep[threejj+2] += NN * duvcp[i*fourncpm4+j*4+myint+2];
                                duvwgh += NN * duvcp[i*fourncpm4+j*4+myint+3];
                            }
                        }
                        duvep[threejj] = (duvep[threejj] - duwgh*dvep[threejj] - dvwgh*duep[threejj] - duvwgh*ep[threejj])/wgh;
                        duvep[threejj+1] = (duvep[threejj+1] - duwgh*dvep[threejj+1] - dvwgh*duep[threejj+1] - duvwgh*ep[threejj+1])/wgh;
                        duvep[threejj+2] = (duvep[threejj+2] - duwgh*dvep[threejj+2] - dvwgh*duep[threejj+2] - duvwgh*ep[threejj+2])/wgh;
                        
                    }
                    
                }
                
            }
            
        }
        else if (degV==1){
            
            for (jj = 0; jj < nus; jj++){
                
                threejj = 3*jj;
                
                if (us[2*jj] <= knotU[degU]){
                    
                    if (us[2*jj+1] <= knotV[degV]){
                        
                        wgh = cp[3];
                        ep[threejj] = cp[0]/wgh;
                        ep[threejj+1] = cp[1]/wgh;
                        ep[threejj+2] = cp[2]/wgh;
                        
                        duep[threejj] = (ducp[0] - ducp[3]*ep[threejj])/wgh;
                        duep[threejj+1] = (ducp[1] - ducp[3]*ep[threejj+1])/wgh;
                        duep[threejj+2] = (ducp[2] - ducp[3]*ep[threejj+2])/wgh;
                        
                        dvep[threejj] = (dvcp[0] - dvcp[3]*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvcp[1] - dvcp[3]*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvcp[2] - dvcp[3]*ep[threejj+2])/wgh;
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        
                        duvep[threejj] = (duvcp[0] - ducp[3]*dvep[threejj] - dvcp[3]*duep[threejj] - duvcp[3]*ep[threejj])/wgh;
                        duvep[threejj+1] = (duvcp[1] - ducp[3]*dvep[threejj+1] - dvcp[3]*duep[threejj+1] - duvcp[3]*ep[threejj+1])/wgh;
                        duvep[threejj+2] = (duvcp[2] - ducp[3]*dvep[threejj+2] - dvcp[3]*duep[threejj+2] - duvcp[3]*ep[threejj+2])/wgh;
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        
                    }
                    else if (us[2*jj+1] >= knotV[kcp]){
                        
                        myint = fourncp*(kcp-1);
                        wgh = cp[myint+3];
                        ep[threejj] = cp[myint]/wgh;
                        ep[threejj+1] = cp[myint+1]/wgh;
                        ep[threejj+2] = cp[myint+2]/wgh;
                        
                        myint = fourncpm4*(kcp-1);
                        duwgh = ducp[myint+3];
                        duep[threejj] = (ducp[myint] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (ducp[myint+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (ducp[myint+2] - duwgh*ep[threejj+2])/wgh;
                        
                        myint = fourncp*(kcp-2);
                        dvwgh = dvcp[myint+3];
                        dvep[threejj] = (dvcp[myint] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvcp[myint+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvcp[myint+2] - dvwgh*ep[threejj+2])/wgh;
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        
                        myint = fourncpm4*(kcp-2);
                        duvep[threejj] = (duvcp[myint] - duwgh*dvep[threejj] - dvwgh*duep[threejj] - duvcp[myint+3]*ep[threejj])/wgh;
                        duvep[threejj+1] = (duvcp[myint+1] - duwgh*dvep[threejj+1] - dvwgh*duep[threejj+1] - duvcp[myint+3]*ep[threejj+1])/wgh;
                        duvep[threejj+2] = (duvcp[myint+2] - duwgh*dvep[threejj+2] - dvwgh*duep[threejj+2] - duvcp[myint+3]*ep[threejj+2])/wgh;
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        
                    }
                    else {
                        
                        ep[threejj] = 0.0;
                        ep[threejj+1] = 0.0;
                        ep[threejj+2] = 0.0;
                        wgh = 0.0;
                        
                        spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        ind = spanV - degV;
                        
                        for (i = 0; i <= degV; i++){
                            myint = (ind+i)*fourncp;
                            ep[threejj] += NV[i] * cp[myint];
                            ep[threejj+1] += NV[i] * cp[myint+1];
                            ep[threejj+2] += NV[i] * cp[myint+2];
                            wgh += NV[i] * cp[myint+3];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        duwgh = 0.0;
                        
                        for (i = 0; i <= degV; i++){
                            myint = (ind+i)*fourncpm4;
                            duep[threejj] += NV[i] * ducp[myint];
                            duep[threejj+1] += NV[i] * ducp[myint+1];
                            duep[threejj+2] += NV[i] * ducp[myint+2];
                            duwgh += NV[i] * ducp[myint+3];
                        }
                        duep[threejj] = (duep[threejj] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (duep[threejj+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (duep[threejj+2] - duwgh*ep[threejj+2])/wgh;
                        
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        
                        
                        BasisFuns(spanV-1, us[2*jj+1], degV-1, &knotV[1], NV, leftV, rightV);
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        dvwgh = 0.0;
                        
                        for (i = 0; i < degV; i++){
                            myint = (ind+i)*fourncp;
                            dvep[threejj] += NV[i] * dvcp[myint];
                            dvep[threejj+1] += NV[i] * dvcp[myint+1];
                            dvep[threejj+2] += NV[i] * dvcp[myint+2];
                            dvwgh += NV[i] * dvcp[myint+3];
                        }
                        dvep[threejj] = (dvep[threejj] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvep[threejj+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvep[threejj+2] - dvwgh*ep[threejj+2])/wgh;
                        
                        
                        duvep[threejj] = 0.0;
                        duvep[threejj+1] = 0.0;
                        duvep[threejj+2] = 0.0;
                        duvwgh = 0.0;
                        
                        for (i = 0; i < degV; i++){
                            myint = (ind+i)*fourncpm4;
                            duvep[threejj] += NV[i] * duvcp[myint];
                            duvep[threejj+1] += NV[i] * duvcp[myint+1];
                            duvep[threejj+2] += NV[i] * duvcp[myint+2];
                            duvwgh += NV[i] * duvcp[myint+3];
                        }
                        duvep[threejj] = (duvep[threejj] - duwgh*dvep[threejj] - dvwgh*duep[threejj] - duvwgh*ep[threejj])/wgh;
                        duvep[threejj+1] = (duvep[threejj+1] - duwgh*dvep[threejj+1] - dvwgh*duep[threejj+1] - duvwgh*ep[threejj+1])/wgh;
                        duvep[threejj+2] = (duvep[threejj+2] - duwgh*dvep[threejj+2] - dvwgh*duep[threejj+2] - duvwgh*ep[threejj+2])/wgh;
                        
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        
                    }
                    
                }
                else if (us[2*jj] >= knotU[ncp]){
                    
                    if (us[2*jj+1] <= knotV[degV]){
                        
                        wgh = cp[fourncp-1];
                        ep[threejj] = cp[fourncpm4]/wgh;
                        ep[threejj+1] = cp[fourncpm4+1]/wgh;
                        ep[threejj+2] = cp[fourncpm4+2]/wgh;
                        
                        duep[threejj] = (ducp[fourncpm4-4] - ducp[fourncpm4-1]*ep[threejj])/wgh;
                        duep[threejj+1] = (ducp[fourncpm4-3] - ducp[fourncpm4-1]*ep[threejj+1])/wgh;
                        duep[threejj+2] = (ducp[fourncpm4-2] - ducp[fourncpm4-1]*ep[threejj+2])/wgh;
                        
                        dvep[threejj] = (dvcp[fourncpm4] - dvcp[fourncpm4+3]*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvcp[fourncpm4+1] - dvcp[fourncpm4+3]*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvcp[fourncpm4+2] - dvcp[fourncpm4+3]*ep[threejj+2])/wgh;
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        
                        duvep[threejj] = (duvcp[fourncpm4-4] - ducp[fourncpm4-1]*dvep[threejj] - dvcp[fourncpm4+3]*duep[threejj] - duvcp[fourncpm4-1]*ep[threejj])/wgh;
                        duvep[threejj+1] = (duvcp[fourncpm4-3] - ducp[fourncpm4-1]*dvep[threejj+1] - dvcp[fourncpm4+3]*duep[threejj+1] - duvcp[fourncpm4-1]*ep[threejj+1])/wgh;
                        duvep[threejj+2] = (duvcp[fourncpm4-2] - ducp[fourncpm4-1]*dvep[threejj+2] - dvcp[fourncpm4+3]*duep[threejj+2] - duvcp[fourncpm4-1]*ep[threejj+2])/wgh;
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        
                    }
                    else if (us[2*jj+1] >= knotV[kcp]){
                        
                        myint = fourncp*kcp;
                        wgh = cp[myint-1];
                        ep[threejj] = cp[myint-4]/wgh;
                        ep[threejj+1] = cp[myint-3]/wgh;
                        ep[threejj+2] = cp[myint-2]/wgh;
                        
                        myint = fourncpm4*kcp-4;
                        duwgh = ducp[myint+3];
                        duep[threejj] = (ducp[myint] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (ducp[myint+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (ducp[myint+2] - duwgh*ep[threejj+2])/wgh;
                        
                        myint = fourncp*(kcp-1)-4;
                        dvwgh = dvcp[myint+3];
                        dvep[threejj] = (dvcp[myint] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvcp[myint+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvcp[myint+2] - dvwgh*ep[threejj+2])/wgh;
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        
                        myint = fourncpm4*(kcp-1)-4;
                        duvep[threejj] = (duvcp[myint] - duwgh*dvep[threejj] - dvwgh*duep[threejj] - duvcp[myint+3]*ep[threejj])/wgh;
                        duvep[threejj+1] = (duvcp[myint+1] - duwgh*dvep[threejj+1] - dvwgh*duep[threejj+1] - duvcp[myint+3]*ep[threejj+1])/wgh;
                        duvep[threejj+2] = (duvcp[myint+2] - duwgh*dvep[threejj+2] - dvwgh*duep[threejj+2] - duvcp[myint+3]*ep[threejj+2])/wgh;
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        
                    }
                    else {
                        
                        ep[threejj] = 0.0;
                        ep[threejj+1] = 0.0;
                        ep[threejj+2] = 0.0;
                        wgh = 0.0;
                        
                        spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        ind = spanV - degV;
                        myint = (ind+1)*fourncp;
                        
                        for (i = 0; i <= degV; i++){
                            ep[threejj] += NV[i] * cp[i*fourncp+myint-4];
                            ep[threejj+1] += NV[i] * cp[i*fourncp+myint-3];
                            ep[threejj+2] += NV[i] * cp[i*fourncp+myint-2];
                            wgh += NV[i] * cp[i*fourncp+myint-1];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        duwgh = 0.0;
                        
                        for (i = 0; i <= degV; i++){
                            myint = (ind+i)*fourncpm4 + fourncpm8;
                            duep[threejj] += NV[i] * ducp[myint];
                            duep[threejj+1] += NV[i] * ducp[myint+1];
                            duep[threejj+2] += NV[i] * ducp[myint+2];
                            duwgh += NV[i] * ducp[myint+3];
                        }
                        duep[threejj] = (duep[threejj] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (duep[threejj+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (duep[threejj+2] - duwgh*ep[threejj+2])/wgh;
                        
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        
                        
                        BasisFuns(spanV-1, us[2*jj+1], degV-1, &knotV[1], NV, leftV, rightV);
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        dvwgh = 0.0;
                        
                        for (i = 0; i < degV; i++){
                            myint = (ind+i)*fourncp + fourncpm4;
                            dvep[threejj] += NV[i] * dvcp[myint];
                            dvep[threejj+1] += NV[i] * dvcp[myint+1];
                            dvep[threejj+2] += NV[i] * dvcp[myint+2];
                            dvwgh += NV[i] * dvcp[myint+3];
                        }
                        dvep[threejj] = (dvep[threejj] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvep[threejj+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvep[threejj+2] - dvwgh*ep[threejj+2])/wgh;
                        
                        
                        duvep[threejj] = 0.0;
                        duvep[threejj+1] = 0.0;
                        duvep[threejj+2] = 0.0;
                        duvwgh = 0.0;
                        
                        for (i = 0; i < degV; i++){
                            myint = (ind+i)*fourncpm4 + fourncpm8;
                            duvep[threejj] += NV[i] * duvcp[myint];
                            duvep[threejj+1] += NV[i] * duvcp[myint+1];
                            duvep[threejj+2] += NV[i] * duvcp[myint+2];
                            duvwgh += NV[i] * duvcp[myint+3];
                        }
                        duvep[threejj] = (duvep[threejj] - duwgh*dvep[threejj] - dvwgh*duep[threejj] - duvwgh*ep[threejj])/wgh;
                        duvep[threejj+1] = (duvep[threejj+1] - duwgh*dvep[threejj+1] - dvwgh*duep[threejj+1] - duvwgh*ep[threejj+1])/wgh;
                        duvep[threejj+2] = (duvep[threejj+2] - duwgh*dvep[threejj+2] - dvwgh*duep[threejj+2] - duvwgh*ep[threejj+2])/wgh;
                        
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        
                    }
                    
                }
                else {
                    
                    ep[threejj] = 0.0;
                    ep[threejj+1] = 0.0;
                    ep[threejj+2] = 0.0;
                    wgh = 0.0;
                    
                    duep[threejj] = 0.0;
                    duep[threejj+1] = 0.0;
                    duep[threejj+2] = 0.0;
                    duwgh = 0.0;
                    
                    dvep[threejj] = 0.0;
                    dvep[threejj+1] = 0.0;
                    dvep[threejj+2] = 0.0;
                    dvwgh = 0.0;
                    
                    duuep[threejj] = 0.0;
                    duuep[threejj+1] = 0.0;
                    duuep[threejj+2] = 0.0;
                    
                    duvep[threejj] = 0.0;
                    duvep[threejj+1] = 0.0;
                    duvep[threejj+2] = 0.0;
                    duvwgh = 0.0;
                    
                    dvvep[threejj] = 0.0;
                    dvvep[threejj+1] = 0.0;
                    dvvep[threejj+2] = 0.0;
                    
                    if (us[2*jj+1] <= knotV[degV]){
                        
                        spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                        BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                        
                        ind = spanU - degU;
                        
                        for (i = 0; i <= degU; i++){
                            ep[threejj] += NU[i] * cp[(ind+i)*4];
                            ep[threejj+1] += NU[i] * cp[(ind+i)*4+1];
                            ep[threejj+2] += NU[i] * cp[(ind+i)*4+2];
                            wgh += NU[i] * cp[(ind+i)*4+3];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        for (i = 0; i <= degU; i++){
                            dvep[threejj] += NU[i] * dvcp[(ind+i)*4];
                            dvep[threejj+1] += NU[i] * dvcp[(ind+i)*4+1];
                            dvep[threejj+2] += NU[i] * dvcp[(ind+i)*4+2];
                            dvwgh += NU[i] * dvcp[(ind+i)*4+3];
                        }
                        dvep[threejj] = (dvep[threejj] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvep[threejj+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvep[threejj+2] - dvwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanU-1, us[2*jj], degU-1, &knotU[1], NU, leftU, rightU);
                        
                        for (i = 0; i < degU; i++){
                            duep[threejj] += NU[i] * ducp[(ind+i)*4];
                            duep[threejj+1] += NU[i] * ducp[(ind+i)*4+1];
                            duep[threejj+2] += NU[i] * ducp[(ind+i)*4+2];
                            duwgh += NU[i] * ducp[(ind+i)*4+3];
                        }
                        duep[threejj] = (duep[threejj] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (duep[threejj+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (duep[threejj+2] - duwgh*ep[threejj+2])/wgh;
                        
                        
                        for (i = 0; i < degU; i++){
                            duvep[threejj] += NU[i] * duvcp[(ind+i)*4];
                            duvep[threejj+1] += NU[i] * duvcp[(ind+i)*4+1];
                            duvep[threejj+2] += NU[i] * duvcp[(ind+i)*4+2];
                            duvwgh += NU[i] * duvcp[(ind+i)*4+3];
                        }
                        duvep[threejj] = (duvep[threejj] - duwgh*dvep[threejj] - dvwgh*duep[threejj] - duvwgh*ep[threejj])/wgh;
                        duvep[threejj+1] = (duvep[threejj+1] - duwgh*dvep[threejj+1] - dvwgh*duep[threejj+1] - duvwgh*ep[threejj+1])/wgh;
                        duvep[threejj+2] = (duvep[threejj+2] - duwgh*dvep[threejj+2] - dvwgh*duep[threejj+2] - duvwgh*ep[threejj+2])/wgh;
                        
                    }
                    else if (us[2*jj+1] >= knotV[kcp]){
                        
                        spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                        BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                        
                        ind = spanU - degU;
                        myint = ind*4+(kcp-1)*fourncp;
                        
                        for (i = 0; i <= degU; i++){
                            ep[threejj] += NU[i] * cp[i*4+myint];
                            ep[threejj+1] += NU[i] * cp[i*4+myint+1];
                            ep[threejj+2] += NU[i] * cp[i*4+myint+2];
                            wgh += NU[i] * cp[i*4+myint+3];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        ind = spanU - degU + ncp*(kcp-2);
                        
                        for (i = 0; i <= degU; i++){
                            dvep[threejj] += NU[i] * dvcp[(ind+i)*4];
                            dvep[threejj+1] += NU[i] * dvcp[(ind+i)*4+1];
                            dvep[threejj+2] += NU[i] * dvcp[(ind+i)*4+2];
                            dvwgh += NU[i] * dvcp[(ind+i)*4+3];
                        }
                        dvep[threejj] = (dvep[threejj] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvep[threejj+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvep[threejj+2] - dvwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanU-1, us[2*jj], degU-1, &knotU[1], NU, leftU, rightU);
                        
                        ind = spanU - degU + (ncp-1)*(kcp-1);
                        
                        for (i = 0; i < degU; i++){
                            duep[threejj] += NU[i] * ducp[(ind+i)*4];
                            duep[threejj+1] += NU[i] * ducp[(ind+i)*4+1];
                            duep[threejj+2] += NU[i] * ducp[(ind+i)*4+2];
                            duwgh += NU[i] * ducp[(ind+i)*4+3];
                        }
                        duep[threejj] = (duep[threejj] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (duep[threejj+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (duep[threejj+2] - duwgh*ep[threejj+2])/wgh;
                        
                        
                        ind = spanU - degU + (ncp-1)*(kcp-2);
                        
                        for (i = 0; i < degU; i++){
                            duvep[threejj] += NU[i] * duvcp[(ind+i)*4];
                            duvep[threejj+1] += NU[i] * duvcp[(ind+i)*4+1];
                            duvep[threejj+2] += NU[i] * duvcp[(ind+i)*4+2];
                            duvwgh += NU[i] * duvcp[(ind+i)*4+3];
                        }
                        duvep[threejj] = (duvep[threejj] - duwgh*dvep[threejj] - dvwgh*duep[threejj] - duvwgh*ep[threejj])/wgh;
                        duvep[threejj+1] = (duvep[threejj+1] - duwgh*dvep[threejj+1] - dvwgh*duep[threejj+1] - duvwgh*ep[threejj+1])/wgh;
                        duvep[threejj+2] = (duvep[threejj+2] - duwgh*dvep[threejj+2] - dvwgh*duep[threejj+2] - duvwgh*ep[threejj+2])/wgh;
                        
                    }
                    else {
                        
                        spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                        BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                        
                        spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        ind = spanU - degU;
                        ind2 = spanV - degV;
                        myint = ind2*fourncp+ind*4;
                        
                        for (i = 0; i <= degV; i++){
                            for (j = 0; j <= degU; j++){
                                NN = NV[i] * NU[j];
                                ep[threejj] += NN * cp[i*fourncp+j*4+myint];
                                ep[threejj+1] += NN * cp[i*fourncp+j*4+myint+1];
                                ep[threejj+2] += NN * cp[i*fourncp+j*4+myint+2];
                                wgh += NN * cp[i*fourncp+j*4+myint+3];
                            }
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        BasisFuns(spanV-1, us[2*jj+1], degV-1, &knotV[1], NV, leftV, rightV);
                        
                        for (i = 0; i < degV; i++){
                            for (j = 0; j <= degU; j++){
                                NN = NV[i] * NU[j];
                                dvep[threejj] += NN * dvcp[i*fourncp+j*4+myint];
                                dvep[threejj+1] += NN * dvcp[i*fourncp+j*4+myint+1];
                                dvep[threejj+2] += NN * dvcp[i*fourncp+j*4+myint+2];
                                dvwgh += NN * dvcp[i*fourncp+j*4+myint+3];
                            }
                        }
                        dvep[threejj] = (dvep[threejj] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvep[threejj+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvep[threejj+2] - dvwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanU-1, us[2*jj], degU-1, &knotU[1], NU, leftU, rightU);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        myint = ind2*fourncpm4+ind*4;
                        
                        for (i = 0; i <= degV; i++){
                            for (j = 0; j < degU; j++){
                                NN = NV[i] * NU[j];
                                duep[threejj] += NN * ducp[i*fourncpm4+j*4+myint];
                                duep[threejj+1] += NN * ducp[i*fourncpm4+j*4+myint+1];
                                duep[threejj+2] += NN * ducp[i*fourncpm4+j*4+myint+2];
                                duwgh += NN * ducp[i*fourncpm4+j*4+myint+3];
                            }
                        }
                        duep[threejj] = (duep[threejj] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (duep[threejj+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (duep[threejj+2] - duwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanV-1, us[2*jj+1], degV-1, &knotV[1], NV, leftV, rightV);
                        
                        myint = ind2*fourncpm4+ind*4;
                        
                        for (i = 0; i < degV; i++){
                            for (j = 0; j < degU; j++){
                                NN = NV[i] * NU[j];
                                duvep[threejj] += NN * duvcp[i*fourncpm4+j*4+myint];
                                duvep[threejj+1] += NN * duvcp[i*fourncpm4+j*4+myint+1];
                                duvep[threejj+2] += NN * duvcp[i*fourncpm4+j*4+myint+2];
                                duvwgh += NN * duvcp[i*fourncpm4+j*4+myint+3];
                            }
                        }
                        duvep[threejj] = (duvep[threejj] - duwgh*dvep[threejj] - dvwgh*duep[threejj] - duvwgh*ep[threejj])/wgh;
                        duvep[threejj+1] = (duvep[threejj+1] - duwgh*dvep[threejj+1] - dvwgh*duep[threejj+1] - duvwgh*ep[threejj+1])/wgh;
                        duvep[threejj+2] = (duvep[threejj+2] - duwgh*dvep[threejj+2] - dvwgh*duep[threejj+2] - duvwgh*ep[threejj+2])/wgh;
                        
                    }
                    
                }
                
            }
            
        }
        else {
            
            for (jj = 0; jj < nus; jj++){
                
                threejj = 3*jj;
                
                if (us[2*jj] <= knotU[degU]){
                    
                    if (us[2*jj+1] <= knotV[degV]){
                        
                        wgh = cp[3];
                        ep[threejj] = cp[0]/wgh;
                        ep[threejj+1] = cp[1]/wgh;
                        ep[threejj+2] = cp[2]/wgh;
                        
                        duep[threejj] = (ducp[0] - ducp[3]*ep[threejj])/wgh;
                        duep[threejj+1] = (ducp[1] - ducp[3]*ep[threejj+1])/wgh;
                        duep[threejj+2] = (ducp[2] - ducp[3]*ep[threejj+2])/wgh;
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        
                        duvep[threejj] = 0.0;
                        duvep[threejj+1] = 0.0;
                        duvep[threejj+2] = 0.0;
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        
                    }
                    else if (us[2*jj+1] >= knotV[kcp]){
                        
                        myint = fourncp*(kcp-1);
                        wgh = cp[myint+3];
                        ep[threejj] = cp[myint]/wgh;
                        ep[threejj+1] = cp[myint+1]/wgh;
                        ep[threejj+2] = cp[myint+2]/wgh;
                        
                        myint = fourncpm4*(kcp-1);
                        duwgh = ducp[myint+3];
                        duep[threejj] = (ducp[myint] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (ducp[myint+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (ducp[myint+2] - duwgh*ep[threejj+2])/wgh;
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        
                        duvep[threejj] = 0.0;
                        duvep[threejj+1] = 0.0;
                        duvep[threejj+2] = 0.0;
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        
                    }
                    else {
                        
                        ep[threejj] = 0.0;
                        ep[threejj+1] = 0.0;
                        ep[threejj+2] = 0.0;
                        wgh = 0.0;
                        
                        spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        ind = spanV - degV;
                        
                        for (i = 0; i <= degV; i++){
                            myint = (ind+i)*fourncp;
                            ep[threejj] += NV[i] * cp[myint];
                            ep[threejj+1] += NV[i] * cp[myint+1];
                            ep[threejj+2] += NV[i] * cp[myint+2];
                            wgh += NV[i] * cp[myint+3];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        duwgh = 0.0;
                        
                        for (i = 0; i <= degV; i++){
                            myint = (ind+i)*fourncpm4;
                            duep[threejj] += NV[i] * ducp[myint];
                            duep[threejj+1] += NV[i] * ducp[myint+1];
                            duep[threejj+2] += NV[i] * ducp[myint+2];
                            duwgh += NV[i] * ducp[myint+3];
                        }
                        duep[threejj] = (duep[threejj] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (duep[threejj+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (duep[threejj+2] - duwgh*ep[threejj+2])/wgh;
                        
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        
                        
                        duvep[threejj] = 0.0;
                        duvep[threejj+1] = 0.0;
                        duvep[threejj+2] = 0.0;
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        
                    }
                    
                }
                else if (us[2*jj] >= knotU[ncp]){
                    
                    if (us[2*jj+1] <= knotV[degV]){
                        
                        wgh = cp[fourncp-1];
                        ep[threejj] = cp[fourncpm4]/wgh;
                        ep[threejj+1] = cp[fourncpm4+1]/wgh;
                        ep[threejj+2] = cp[fourncpm4+2]/wgh;
                        
                        duep[threejj] = (ducp[fourncpm4-4] - ducp[fourncpm4-1]*ep[threejj])/wgh;
                        duep[threejj+1] = (ducp[fourncpm4-3] - ducp[fourncpm4-1]*ep[threejj+1])/wgh;
                        duep[threejj+2] = (ducp[fourncpm4-2] - ducp[fourncpm4-1]*ep[threejj+2])/wgh;
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        
                        duvep[threejj] = 0.0;
                        duvep[threejj+1] = 0.0;
                        duvep[threejj+2] = 0.0;
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        
                    }
                    else if (us[2*jj+1] >= knotV[kcp]){
                        
                        myint = fourncp*kcp;
                        wgh = cp[myint-1];
                        ep[threejj] = cp[myint-4]/wgh;
                        ep[threejj+1] = cp[myint-3]/wgh;
                        ep[threejj+2] = cp[myint-2]/wgh;
                        
                        myint = fourncpm4*kcp-4;
                        duwgh = ducp[myint+3];
                        duep[threejj] = (ducp[myint] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (ducp[myint+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (ducp[myint+2] - duwgh*ep[threejj+2])/wgh;
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        
                        duvep[threejj] = 0.0;
                        duvep[threejj+1] = 0.0;
                        duvep[threejj+2] = 0.0;
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        
                    }
                    else {
                        
                        ep[threejj] = 0.0;
                        ep[threejj+1] = 0.0;
                        ep[threejj+2] = 0.0;
                        wgh = 0.0;
                        
                        spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        ind = spanV - degV;
                        myint = (ind+1)*fourncp;
                        
                        for (i = 0; i <= degV; i++){
                            ep[threejj] += NV[i] * cp[i*fourncp+myint-4];
                            ep[threejj+1] += NV[i] * cp[i*fourncp+myint-3];
                            ep[threejj+2] += NV[i] * cp[i*fourncp+myint-2];
                            wgh += NV[i] * cp[i*fourncp+myint-1];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        duwgh = 0.0;
                        
                        for (i = 0; i <= degV; i++){
                            myint = (ind+i)*fourncpm4 + fourncpm8;
                            duep[threejj] += NV[i] * ducp[myint];
                            duep[threejj+1] += NV[i] * ducp[myint+1];
                            duep[threejj+2] += NV[i] * ducp[myint+2];
                            duwgh += NV[i] * ducp[myint+3];
                        }
                        duep[threejj] = (duep[threejj] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (duep[threejj+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (duep[threejj+2] - duwgh*ep[threejj+2])/wgh;
                        
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        
                        
                        duvep[threejj] = 0.0;
                        duvep[threejj+1] = 0.0;
                        duvep[threejj+2] = 0.0;
                        duvwgh = 0.0;
                        
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        
                    }
                    
                }
                else {
                    
                    ep[threejj] = 0.0;
                    ep[threejj+1] = 0.0;
                    ep[threejj+2] = 0.0;
                    wgh = 0.0;
                    
                    duep[threejj] = 0.0;
                    duep[threejj+1] = 0.0;
                    duep[threejj+2] = 0.0;
                    duwgh = 0.0;
                    
                    dvep[threejj] = 0.0;
                    dvep[threejj+1] = 0.0;
                    dvep[threejj+2] = 0.0;
                    
                    duuep[threejj] = 0.0;
                    duuep[threejj+1] = 0.0;
                    duuep[threejj+2] = 0.0;
                    
                    duvep[threejj] = 0.0;
                    duvep[threejj+1] = 0.0;
                    duvep[threejj+2] = 0.0;
                    
                    dvvep[threejj] = 0.0;
                    dvvep[threejj+1] = 0.0;
                    dvvep[threejj+2] = 0.0;
                    
                    if (us[2*jj+1] <= knotV[degV]){
                        
                        spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                        BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                        
                        ind = spanU - degU;
                        
                        for (i = 0; i <= degU; i++){
                            ep[threejj] += NU[i] * cp[(ind+i)*4];
                            ep[threejj+1] += NU[i] * cp[(ind+i)*4+1];
                            ep[threejj+2] += NU[i] * cp[(ind+i)*4+2];
                            wgh += NU[i] * cp[(ind+i)*4+3];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        BasisFuns(spanU-1, us[2*jj], degU-1, &knotU[1], NU, leftU, rightU);
                        
                        for (i = 0; i < degU; i++){
                            duep[threejj] += NU[i] * ducp[(ind+i)*4];
                            duep[threejj+1] += NU[i] * ducp[(ind+i)*4+1];
                            duep[threejj+2] += NU[i] * ducp[(ind+i)*4+2];
                            duwgh += NU[i] * ducp[(ind+i)*4+3];
                        }
                        duep[threejj] = (duep[threejj] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (duep[threejj+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (duep[threejj+2] - duwgh*ep[threejj+2])/wgh;
                        
                    }
                    else if (us[2*jj+1] >= knotV[kcp]){
                        
                        spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                        BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                        
                        ind = spanU - degU;
                        myint = ind*4+(kcp-1)*fourncp;
                        
                        for (i = 0; i <= degU; i++){
                            ep[threejj] += NU[i] * cp[i*4+myint];
                            ep[threejj+1] += NU[i] * cp[i*4+myint+1];
                            ep[threejj+2] += NU[i] * cp[i*4+myint+2];
                            wgh += NU[i] * cp[i*4+myint+3];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        BasisFuns(spanU-1, us[2*jj], degU-1, &knotU[1], NU, leftU, rightU);
                        
                        ind = spanU - degU + (ncp-1)*(kcp-1);
                        
                        for (i = 0; i < degU; i++){
                            duep[threejj] += NU[i] * ducp[(ind+i)*4];
                            duep[threejj+1] += NU[i] * ducp[(ind+i)*4+1];
                            duep[threejj+2] += NU[i] * ducp[(ind+i)*4+2];
                            duwgh += NU[i] * ducp[(ind+i)*4+3];
                        }
                        duep[threejj] = (duep[threejj] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (duep[threejj+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (duep[threejj+2] - duwgh*ep[threejj+2])/wgh;
                        
                    }
                    else {
                        
                        spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                        BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                        
                        spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        ind = spanU - degU;
                        ind2 = spanV - degV;
                        myint = ind2*fourncp+ind*4;
                        
                        for (i = 0; i <= degV; i++){
                            for (j = 0; j <= degU; j++){
                                NN = NV[i] * NU[j];
                                ep[threejj] += NN * cp[i*fourncp+j*4+myint];
                                ep[threejj+1] += NN * cp[i*fourncp+j*4+myint+1];
                                ep[threejj+2] += NN * cp[i*fourncp+j*4+myint+2];
                                wgh += NN * cp[i*fourncp+j*4+myint+3];
                            }
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        BasisFuns(spanU-1, us[2*jj], degU-1, &knotU[1], NU, leftU, rightU);
                        
                        myint = ind2*fourncpm4+ind*4;
                        
                        for (i = 0; i <= degV; i++){
                            for (j = 0; j < degU; j++){
                                NN = NV[i] * NU[j];
                                duep[threejj] += NN * ducp[i*fourncpm4+j*4+myint];
                                duep[threejj+1] += NN * ducp[i*fourncpm4+j*4+myint+1];
                                duep[threejj+2] += NN * ducp[i*fourncpm4+j*4+myint+2];
                                duwgh += NN * ducp[i*fourncpm4+j*4+myint+3];
                            }
                        }
                        duep[threejj] = (duep[threejj] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (duep[threejj+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (duep[threejj+2] - duwgh*ep[threejj+2])/wgh;
                        
                    }
                    
                }
                
            }
            
        }
        
    }
    else {
        
        if (degV>1){
            
            for (jj = 0; jj < nus; jj++){
                
                threejj = 3*jj;
                
                if (us[2*jj] <= knotU[degU]){
                    
                    if (us[2*jj+1] <= knotV[degV]){
                        
                        wgh = cp[3];
                        ep[threejj] = cp[0]/wgh;
                        ep[threejj+1] = cp[1]/wgh;
                        ep[threejj+2] = cp[2]/wgh;
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        
                        dvep[threejj] = (dvcp[0] - dvcp[3]*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvcp[1] - dvcp[3]*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvcp[2] - dvcp[3]*ep[threejj+2])/wgh;
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        
                        duvep[threejj] = 0.0;
                        duvep[threejj+1] = 0.0;
                        duvep[threejj+2] = 0.0;
                        
                        dvvep[threejj] = (dvvcp[0] - 2.0*dvcp[3]*dvep[threejj] - dvvcp[3]*ep[threejj])/wgh;
                        dvvep[threejj+1] = (dvvcp[1] - 2.0*dvcp[3]*dvep[threejj+1] - dvvcp[3]*ep[threejj+1])/wgh;
                        dvvep[threejj+2] = (dvvcp[2] - 2.0*dvcp[3]*dvep[threejj+2] - dvvcp[3]*ep[threejj+2])/wgh;
                        
                    }
                    else if (us[2*jj+1] >= knotV[kcp]){
                        
                        myint = fourncp*(kcp-1);
                        wgh = cp[myint+3];
                        ep[threejj] = cp[myint]/wgh;
                        ep[threejj+1] = cp[myint+1]/wgh;
                        ep[threejj+2] = cp[myint+2]/wgh;
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        
                        myint = fourncp*(kcp-2);
                        dvwgh = dvcp[myint+3];
                        dvep[threejj] = (dvcp[myint] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvcp[myint+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvcp[myint+2] - dvwgh*ep[threejj+2])/wgh;
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        
                        duvep[threejj] = 0.0;
                        duvep[threejj+1] = 0.0;
                        duvep[threejj+2] = 0.0;
                        
                        myint = fourncp*(kcp-3);
                        dvwgh *= 2.0;
                        dvvep[threejj] = (dvvcp[myint] - dvwgh*dvep[threejj] - dvvcp[myint+3]*ep[threejj])/wgh;
                        dvvep[threejj+1] = (dvvcp[myint+1] - dvwgh*dvep[threejj+1] - dvvcp[myint+3]*ep[threejj+1])/wgh;
                        dvvep[threejj+2] = (dvvcp[myint+2] - dvwgh*dvep[threejj+2] - dvvcp[myint+3]*ep[threejj+2])/wgh;
                        
                    }
                    else {
                        
                        ep[threejj] = 0.0;
                        ep[threejj+1] = 0.0;
                        ep[threejj+2] = 0.0;
                        wgh = 0.0;
                        
                        spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        ind = spanV - degV;
                        
                        for (i = 0; i <= degV; i++){
                            myint = (ind+i)*fourncp;
                            ep[threejj] += NV[i] * cp[myint];
                            ep[threejj+1] += NV[i] * cp[myint+1];
                            ep[threejj+2] += NV[i] * cp[myint+2];
                            wgh += NV[i] * cp[myint+3];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        
                        
                        BasisFuns(spanV-1, us[2*jj+1], degV-1, &knotV[1], NV, leftV, rightV);
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        dvwgh = 0.0;
                        
                        for (i = 0; i < degV; i++){
                            myint = (ind+i)*fourncp;
                            dvep[threejj] += NV[i] * dvcp[myint];
                            dvep[threejj+1] += NV[i] * dvcp[myint+1];
                            dvep[threejj+2] += NV[i] * dvcp[myint+2];
                            dvwgh += NV[i] * dvcp[myint+3];
                        }
                        dvep[threejj] = (dvep[threejj] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvep[threejj+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvep[threejj+2] - dvwgh*ep[threejj+2])/wgh;
                        
                        
                        duvep[threejj] = 0.0;
                        duvep[threejj+1] = 0.0;
                        duvep[threejj+2] = 0.0;
                        
                        
                        BasisFuns(spanV-2, us[2*jj+1], degV-2, &knotV[2], NV, leftV, rightV);
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        dvvwgh = 0.0;
                        
                        for (i = 0; i <= (degV-2); i++){
                            myint = (ind+i)*fourncp;
                            dvvep[threejj] += NV[i] * dvvcp[myint];
                            dvvep[threejj+1] += NV[i] * dvvcp[myint+1];
                            dvvep[threejj+2] += NV[i] * dvvcp[myint+2];
                            dvvwgh += NV[i] * dvvcp[myint+3];
                        }
                        dvwgh *= 2.0;
                        dvvep[threejj] = (dvvep[threejj] - dvwgh*dvep[threejj] - dvvwgh*ep[threejj])/wgh;
                        dvvep[threejj+1] = (dvvep[threejj+1] - dvwgh*dvep[threejj+1] - dvvwgh*ep[threejj+1])/wgh;
                        dvvep[threejj+2] = (dvvep[threejj+2] - dvwgh*dvep[threejj+2] - dvvwgh*ep[threejj+2])/wgh;
                        
                    }
                    
                }
                else if (us[2*jj] >= knotU[ncp]){
                    
                    if (us[2*jj+1] <= knotV[degV]){
                        
                        wgh = cp[fourncp-1];
                        ep[threejj] = cp[fourncpm4]/wgh;
                        ep[threejj+1] = cp[fourncpm4+1]/wgh;
                        ep[threejj+2] = cp[fourncpm4+2]/wgh;
                        
                        duep[threejj] = (ducp[fourncpm4-4] - ducp[fourncpm4-1]*ep[threejj])/wgh;
                        duep[threejj+1] = (ducp[fourncpm4-3] - ducp[fourncpm4-1]*ep[threejj+1])/wgh;
                        duep[threejj+2] = (ducp[fourncpm4-2] - ducp[fourncpm4-1]*ep[threejj+2])/wgh;
                        
                        dvep[threejj] = (dvcp[fourncpm4] - dvcp[fourncpm4+3]*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvcp[fourncpm4+1] - dvcp[fourncpm4+3]*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvcp[fourncpm4+2] - dvcp[fourncpm4+3]*ep[threejj+2])/wgh;
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        
                        duvep[threejj] = 0.0;
                        duvep[threejj+1] = 0.0;
                        duvep[threejj+2] = 0.0;
                        
                        dvvep[threejj] = (dvvcp[fourncpm4] - 2.0*dvcp[fourncpm4+3]*dvep[threejj] - dvvcp[fourncpm4+3]*ep[threejj])/wgh;
                        dvvep[threejj+1] = (dvvcp[fourncpm4+1] - 2.0*dvcp[fourncpm4+3]*dvep[threejj+1] - dvvcp[fourncpm4+3]*ep[threejj+1])/wgh;
                        dvvep[threejj+2] = (dvvcp[fourncpm4+2] - 2.0*dvcp[fourncpm4+3]*dvep[threejj+2] - dvvcp[fourncpm4+3]*ep[threejj+2])/wgh;
                        
                    }
                    else if (us[2*jj+1] >= knotV[kcp]){
                        
                        myint = fourncp*kcp;
                        wgh = cp[myint-1];
                        ep[threejj] = cp[myint-4]/wgh;
                        ep[threejj+1] = cp[myint-3]/wgh;
                        ep[threejj+2] = cp[myint-2]/wgh;
                        
                        myint = fourncpm4*kcp-4;
                        duwgh = ducp[myint+3];
                        duep[threejj] = (ducp[myint] - duwgh*ep[threejj])/wgh;
                        duep[threejj+1] = (ducp[myint+1] - duwgh*ep[threejj+1])/wgh;
                        duep[threejj+2] = (ducp[myint+2] - duwgh*ep[threejj+2])/wgh;
                        
                        myint = fourncp*(kcp-1)-4;
                        dvwgh = dvcp[myint+3];
                        dvep[threejj] = (dvcp[myint] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvcp[myint+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvcp[myint+2] - dvwgh*ep[threejj+2])/wgh;
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        
                        duvep[threejj] = 0.0;
                        duvep[threejj+1] = 0.0;
                        duvep[threejj+2] = 0.0;
                        
                        myint = fourncp*(kcp-2)-4;
                        dvwgh *= 2.0;
                        dvvep[threejj] = (dvvcp[myint] - dvwgh*dvep[threejj] - dvvcp[myint+3]*ep[threejj])/wgh;
                        dvvep[threejj+1] = (dvvcp[myint+1] - dvwgh*dvep[threejj+1] - dvvcp[myint+3]*ep[threejj+1])/wgh;
                        dvvep[threejj+2] = (dvvcp[myint+2] - dvwgh*dvep[threejj+2] - dvvcp[myint+3]*ep[threejj+2])/wgh;
                        
                    }
                    else {
                        
                        ep[threejj] = 0.0;
                        ep[threejj+1] = 0.0;
                        ep[threejj+2] = 0.0;
                        wgh = 0.0;
                        
                        spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        ind = spanV - degV;
                        myint = (ind+1)*fourncp;
                        
                        for (i = 0; i <= degV; i++){
                            ep[threejj] += NV[i] * cp[i*fourncp+myint-4];
                            ep[threejj+1] += NV[i] * cp[i*fourncp+myint-3];
                            ep[threejj+2] += NV[i] * cp[i*fourncp+myint-2];
                            wgh += NV[i] * cp[i*fourncp+myint-1];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        
                        
                        BasisFuns(spanV-1, us[2*jj+1], degV-1, &knotV[1], NV, leftV, rightV);
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        dvwgh = 0.0;
                        
                        for (i = 0; i < degV; i++){
                            myint = (ind+i)*fourncp + fourncpm4;
                            dvep[threejj] += NV[i] * dvcp[myint];
                            dvep[threejj+1] += NV[i] * dvcp[myint+1];
                            dvep[threejj+2] += NV[i] * dvcp[myint+2];
                            dvwgh += NV[i] * dvcp[myint+3];
                        }
                        dvep[threejj] = (dvep[threejj] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvep[threejj+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvep[threejj+2] - dvwgh*ep[threejj+2])/wgh;
                        
                        
                        duvep[threejj] = 0.0;
                        duvep[threejj+1] = 0.0;
                        duvep[threejj+2] = 0.0;
                        
                        
                        BasisFuns(spanV-2, us[2*jj+1], degV-2, &knotV[2], NV, leftV, rightV);
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        dvvwgh = 0.0;
                        
                        for (i = 0; i <= (degV-2); i++){
                            myint = (ind+i)*fourncp + fourncpm4;
                            dvvep[threejj] += NV[i] * dvvcp[myint];
                            dvvep[threejj+1] += NV[i] * dvvcp[myint+1];
                            dvvep[threejj+2] += NV[i] * dvvcp[myint+2];
                            dvvwgh += NV[i] * dvvcp[myint+3];
                        }
                        dvwgh *= 2.0;
                        dvvep[threejj] = (dvvep[threejj] - dvwgh*dvep[threejj] - dvvwgh*ep[threejj])/wgh;
                        dvvep[threejj+1] = (dvvep[threejj+1] - dvwgh*dvep[threejj+1] - dvvwgh*ep[threejj+1])/wgh;
                        dvvep[threejj+2] = (dvvep[threejj+2] - dvwgh*dvep[threejj+2] - dvvwgh*ep[threejj+2])/wgh;
                        
                    }
                    
                }
                else {
                    
                    ep[threejj] = 0.0;
                    ep[threejj+1] = 0.0;
                    ep[threejj+2] = 0.0;
                    wgh = 0.0;
                    
                    duep[threejj] = 0.0;
                    duep[threejj+1] = 0.0;
                    duep[threejj+2] = 0.0;
                    duwgh = 0.0;
                    
                    dvep[threejj] = 0.0;
                    dvep[threejj+1] = 0.0;
                    dvep[threejj+2] = 0.0;
                    dvwgh = 0.0;
                    
                    duuep[threejj] = 0.0;
                    duuep[threejj+1] = 0.0;
                    duuep[threejj+2] = 0.0;
                    
                    duvep[threejj] = 0.0;
                    duvep[threejj+1] = 0.0;
                    duvep[threejj+2] = 0.0;
                    
                    dvvep[threejj] = 0.0;
                    dvvep[threejj+1] = 0.0;
                    dvvep[threejj+2] = 0.0;
                    dvvwgh = 0.0;
                    
                    if (us[2*jj+1] <= knotV[degV]){
                        
                        spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                        BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                        
                        ind = spanU - degU;
                        
                        for (i = 0; i <= degU; i++){
                            ep[threejj] += NU[i] * cp[(ind+i)*4];
                            ep[threejj+1] += NU[i] * cp[(ind+i)*4+1];
                            ep[threejj+2] += NU[i] * cp[(ind+i)*4+2];
                            wgh += NU[i] * cp[(ind+i)*4+3];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        for (i = 0; i <= degU; i++){
                            dvep[threejj] += NU[i] * dvcp[(ind+i)*4];
                            dvep[threejj+1] += NU[i] * dvcp[(ind+i)*4+1];
                            dvep[threejj+2] += NU[i] * dvcp[(ind+i)*4+2];
                            dvwgh += NU[i] * dvcp[(ind+i)*4+3];
                        }
                        dvep[threejj] = (dvep[threejj] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvep[threejj+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvep[threejj+2] - dvwgh*ep[threejj+2])/wgh;
                        
                        
                        for (i = 0; i <= degU; i++){
                            dvvep[threejj] += NU[i] * dvvcp[(ind+i)*4];
                            dvvep[threejj+1] += NU[i] * dvvcp[(ind+i)*4+1];
                            dvvep[threejj+2] += NU[i] * dvvcp[(ind+i)*4+2];
                            dvvwgh += NU[i] * dvvcp[(ind+i)*4+3];
                        }
                        dvwgh *= 2.0;
                        dvvep[threejj] = (dvvep[threejj] - dvwgh*dvep[threejj] - dvvwgh*ep[threejj])/wgh;
                        dvvep[threejj+1] = (dvvep[threejj+1] - dvwgh*dvep[threejj+1] - dvvwgh*ep[threejj+1])/wgh;
                        dvvep[threejj+2] = (dvvep[threejj+2] - dvwgh*dvep[threejj+2] - dvvwgh*ep[threejj+2])/wgh;
                        
                    }
                    else if (us[2*jj+1] >= knotV[kcp]){
                        
                        spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                        BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                        
                        ind = spanU - degU;
                        myint = ind*4+(kcp-1)*fourncp;
                        
                        for (i = 0; i <= degU; i++){
                            ep[threejj] += NU[i] * cp[i*4+myint];
                            ep[threejj+1] += NU[i] * cp[i*4+myint+1];
                            ep[threejj+2] += NU[i] * cp[i*4+myint+2];
                            wgh += NU[i] * cp[i*4+myint+3];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        ind = spanU - degU + ncp*(kcp-2);
                        
                        for (i = 0; i <= degU; i++){
                            dvep[threejj] += NU[i] * dvcp[(ind+i)*4];
                            dvep[threejj+1] += NU[i] * dvcp[(ind+i)*4+1];
                            dvep[threejj+2] += NU[i] * dvcp[(ind+i)*4+2];
                            dvwgh += NU[i] * dvcp[(ind+i)*4+3];
                        }
                        dvep[threejj] = (dvep[threejj] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvep[threejj+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvep[threejj+2] - dvwgh*ep[threejj+2])/wgh;
                        
                        
                        ind = spanU - degU + ncp*(kcp-3);
                        
                        for (i = 0; i <= degU; i++){
                            dvvep[threejj] += NU[i] * dvvcp[(ind+i)*4];
                            dvvep[threejj+1] += NU[i] * dvvcp[(ind+i)*4+1];
                            dvvep[threejj+2] += NU[i] * dvvcp[(ind+i)*4+2];
                            dvvwgh += NU[i] * dvvcp[(ind+i)*4+3];
                        }
                        dvwgh *= 2.0;
                        dvvep[threejj] = (dvvep[threejj] - dvwgh*dvep[threejj] - dvvwgh*ep[threejj])/wgh;
                        dvvep[threejj+1] = (dvvep[threejj+1] - dvwgh*dvep[threejj+1] - dvvwgh*ep[threejj+1])/wgh;
                        dvvep[threejj+2] = (dvvep[threejj+2] - dvwgh*dvep[threejj+2] - dvvwgh*ep[threejj+2])/wgh;
                        
                    }
                    else {
                        
                        spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                        BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                        
                        spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        ind = spanU - degU;
                        ind2 = spanV - degV;
                        myint = ind2*fourncp+ind*4;
                        
                        for (i = 0; i <= degV; i++){
                            for (j = 0; j <= degU; j++){
                                NN = NV[i] * NU[j];
                                ep[threejj] += NN * cp[i*fourncp+j*4+myint];
                                ep[threejj+1] += NN * cp[i*fourncp+j*4+myint+1];
                                ep[threejj+2] += NN * cp[i*fourncp+j*4+myint+2];
                                wgh += NN * cp[i*fourncp+j*4+myint+3];
                            }
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        BasisFuns(spanV-1, us[2*jj+1], degV-1, &knotV[1], NV, leftV, rightV);
                        
                        for (i = 0; i < degV; i++){
                            for (j = 0; j <= degU; j++){
                                NN = NV[i] * NU[j];
                                dvep[threejj] += NN * dvcp[i*fourncp+j*4+myint];
                                dvep[threejj+1] += NN * dvcp[i*fourncp+j*4+myint+1];
                                dvep[threejj+2] += NN * dvcp[i*fourncp+j*4+myint+2];
                                dvwgh += NN * dvcp[i*fourncp+j*4+myint+3];
                            }
                        }
                        dvep[threejj] = (dvep[threejj] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvep[threejj+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvep[threejj+2] - dvwgh*ep[threejj+2])/wgh;
                        
                        
                        BasisFuns(spanV-2, us[2*jj+1], degV-2, &knotV[2], NV, leftV, rightV);
                        
                        for (i = 0; i <= (degV-2); i++){
                            for (j = 0; j <= degU; j++){
                                NN = NV[i] * NU[j];
                                dvvep[threejj] += NN * dvvcp[i*fourncp+j*4+myint];
                                dvvep[threejj+1] += NN * dvvcp[i*fourncp+j*4+myint+1];
                                dvvep[threejj+2] += NN * dvvcp[i*fourncp+j*4+myint+2];
                                dvvwgh += NN * dvvcp[i*fourncp+j*4+myint+3];
                            }
                        }
                        dvwgh *= 2.0;
                        dvvep[threejj] = (dvvep[threejj] - dvwgh*dvep[threejj] - dvvwgh*ep[threejj])/wgh;
                        dvvep[threejj+1] = (dvvep[threejj+1] - dvwgh*dvep[threejj+1] - dvvwgh*ep[threejj+1])/wgh;
                        dvvep[threejj+2] = (dvvep[threejj+2] - dvwgh*dvep[threejj+2] - dvvwgh*ep[threejj+2])/wgh;
                        
                    }
                    
                }
                
            }
            
        }
        else if (degV==1){
            
            for (jj = 0; jj < nus; jj++){
                
                threejj = 3*jj;
                
                if (us[2*jj] <= knotU[degU]){
                    
                    if (us[2*jj+1] <= knotV[degV]){
                        
                        wgh = cp[3];
                        ep[threejj] = cp[0]/wgh;
                        ep[threejj+1] = cp[1]/wgh;
                        ep[threejj+2] = cp[2]/wgh;
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        
                        dvep[threejj] = (dvcp[0] - dvcp[3]*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvcp[1] - dvcp[3]*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvcp[2] - dvcp[3]*ep[threejj+2])/wgh;
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        
                        duvep[threejj] = 0.0;
                        duvep[threejj+1] = 0.0;
                        duvep[threejj+2] = 0.0;
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        
                    }
                    else if (us[2*jj+1] >= knotV[kcp]){
                        
                        myint = fourncp*(kcp-1);
                        wgh = cp[myint+3];
                        ep[threejj] = cp[myint]/wgh;
                        ep[threejj+1] = cp[myint+1]/wgh;
                        ep[threejj+2] = cp[myint+2]/wgh;
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        
                        myint = fourncp*(kcp-2);
                        dvwgh = dvcp[myint+3];
                        dvep[threejj] = (dvcp[myint] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvcp[myint+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvcp[myint+2] - dvwgh*ep[threejj+2])/wgh;
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        
                        duvep[threejj] = 0.0;
                        duvep[threejj+1] = 0.0;
                        duvep[threejj+2] = 0.0;
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        
                    }
                    else {
                        
                        ep[threejj] = 0.0;
                        ep[threejj+1] = 0.0;
                        ep[threejj+2] = 0.0;
                        wgh = 0.0;
                        
                        spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        ind = spanV - degV;
                        
                        for (i = 0; i <= degV; i++){
                            myint = (ind+i)*fourncp;
                            ep[threejj] += NV[i] * cp[myint];
                            ep[threejj+1] += NV[i] * cp[myint+1];
                            ep[threejj+2] += NV[i] * cp[myint+2];
                            wgh += NV[i] * cp[myint+3];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        
                        
                        BasisFuns(spanV-1, us[2*jj+1], degV-1, &knotV[1], NV, leftV, rightV);
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        dvwgh = 0.0;
                        
                        for (i = 0; i < degV; i++){
                            myint = (ind+i)*fourncp;
                            dvep[threejj] += NV[i] * dvcp[myint];
                            dvep[threejj+1] += NV[i] * dvcp[myint+1];
                            dvep[threejj+2] += NV[i] * dvcp[myint+2];
                            dvwgh += NV[i] * dvcp[myint+3];
                        }
                        dvep[threejj] = (dvep[threejj] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvep[threejj+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvep[threejj+2] - dvwgh*ep[threejj+2])/wgh;
                        
                        
                        duvep[threejj] = 0.0;
                        duvep[threejj+1] = 0.0;
                        duvep[threejj+2] = 0.0;
                        
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        
                    }
                    
                }
                else if (us[2*jj] >= knotU[ncp]){
                    
                    if (us[2*jj+1] <= knotV[degV]){
                        
                        wgh = cp[fourncp-1];
                        ep[threejj] = cp[fourncpm4]/wgh;
                        ep[threejj+1] = cp[fourncpm4+1]/wgh;
                        ep[threejj+2] = cp[fourncpm4+2]/wgh;
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        
                        dvep[threejj] = (dvcp[fourncpm4] - dvcp[fourncpm4+3]*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvcp[fourncpm4+1] - dvcp[fourncpm4+3]*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvcp[fourncpm4+2] - dvcp[fourncpm4+3]*ep[threejj+2])/wgh;
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        
                        duvep[threejj] = 0.0;
                        duvep[threejj+1] = 0.0;
                        duvep[threejj+2] = 0.0;
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        
                    }
                    else if (us[2*jj+1] >= knotV[kcp]){
                        
                        myint = fourncp*kcp;
                        wgh = cp[myint-1];
                        ep[threejj] = cp[myint-4]/wgh;
                        ep[threejj+1] = cp[myint-3]/wgh;
                        ep[threejj+2] = cp[myint-2]/wgh;
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        
                        myint = fourncp*(kcp-1)-4;
                        dvwgh = dvcp[myint+3];
                        dvep[threejj] = (dvcp[myint] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvcp[myint+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvcp[myint+2] - dvwgh*ep[threejj+2])/wgh;
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        
                        duvep[threejj] = 0.0;
                        duvep[threejj+1] = 0.0;
                        duvep[threejj+2] = 0.0;
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        
                    }
                    else {
                        
                        ep[threejj] = 0.0;
                        ep[threejj+1] = 0.0;
                        ep[threejj+2] = 0.0;
                        wgh = 0.0;
                        
                        spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        ind = spanV - degV;
                        myint = (ind+1)*fourncp;
                        
                        for (i = 0; i <= degV; i++){
                            ep[threejj] += NV[i] * cp[i*fourncp+myint-4];
                            ep[threejj+1] += NV[i] * cp[i*fourncp+myint-3];
                            ep[threejj+2] += NV[i] * cp[i*fourncp+myint-2];
                            wgh += NV[i] * cp[i*fourncp+myint-1];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        
                        
                        BasisFuns(spanV-1, us[2*jj+1], degV-1, &knotV[1], NV, leftV, rightV);
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        dvwgh = 0.0;
                        
                        for (i = 0; i < degV; i++){
                            myint = (ind+i)*fourncp + fourncpm4;
                            dvep[threejj] += NV[i] * dvcp[myint];
                            dvep[threejj+1] += NV[i] * dvcp[myint+1];
                            dvep[threejj+2] += NV[i] * dvcp[myint+2];
                            dvwgh += NV[i] * dvcp[myint+3];
                        }
                        dvep[threejj] = (dvep[threejj] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvep[threejj+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvep[threejj+2] - dvwgh*ep[threejj+2])/wgh;
                        
                        
                        duvep[threejj] = 0.0;
                        duvep[threejj+1] = 0.0;
                        duvep[threejj+2] = 0.0;
                        
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        
                    }
                    
                }
                else {
                    
                    ep[threejj] = 0.0;
                    ep[threejj+1] = 0.0;
                    ep[threejj+2] = 0.0;
                    wgh = 0.0;
                    
                    duep[threejj] = 0.0;
                    duep[threejj+1] = 0.0;
                    duep[threejj+2] = 0.0;
                    
                    dvep[threejj] = 0.0;
                    dvep[threejj+1] = 0.0;
                    dvep[threejj+2] = 0.0;
                    dvwgh = 0.0;
                    
                    duuep[threejj] = 0.0;
                    duuep[threejj+1] = 0.0;
                    duuep[threejj+2] = 0.0;
                    
                    duvep[threejj] = 0.0;
                    duvep[threejj+1] = 0.0;
                    duvep[threejj+2] = 0.0;
                    
                    dvvep[threejj] = 0.0;
                    dvvep[threejj+1] = 0.0;
                    dvvep[threejj+2] = 0.0;
                    
                    if (us[2*jj+1] <= knotV[degV]){
                        
                        spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                        BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                        
                        ind = spanU - degU;
                        
                        for (i = 0; i <= degU; i++){
                            ep[threejj] += NU[i] * cp[(ind+i)*4];
                            ep[threejj+1] += NU[i] * cp[(ind+i)*4+1];
                            ep[threejj+2] += NU[i] * cp[(ind+i)*4+2];
                            wgh += NU[i] * cp[(ind+i)*4+3];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        for (i = 0; i <= degU; i++){
                            dvep[threejj] += NU[i] * dvcp[(ind+i)*4];
                            dvep[threejj+1] += NU[i] * dvcp[(ind+i)*4+1];
                            dvep[threejj+2] += NU[i] * dvcp[(ind+i)*4+2];
                            dvwgh += NU[i] * dvcp[(ind+i)*4+3];
                        }
                        dvep[threejj] = (dvep[threejj] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvep[threejj+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvep[threejj+2] - dvwgh*ep[threejj+2])/wgh;
                        
                    }
                    else if (us[2*jj+1] >= knotV[kcp]){
                        
                        spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                        BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                        
                        ind = spanU - degU;
                        myint = ind*4+(kcp-1)*fourncp;
                        
                        for (i = 0; i <= degU; i++){
                            ep[threejj] += NU[i] * cp[i*4+myint];
                            ep[threejj+1] += NU[i] * cp[i*4+myint+1];
                            ep[threejj+2] += NU[i] * cp[i*4+myint+2];
                            wgh += NU[i] * cp[i*4+myint+3];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        ind = spanU - degU + ncp*(kcp-2);
                        
                        for (i = 0; i <= degU; i++){
                            dvep[threejj] += NU[i] * dvcp[(ind+i)*4];
                            dvep[threejj+1] += NU[i] * dvcp[(ind+i)*4+1];
                            dvep[threejj+2] += NU[i] * dvcp[(ind+i)*4+2];
                            dvwgh += NU[i] * dvcp[(ind+i)*4+3];
                        }
                        dvep[threejj] = (dvep[threejj] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvep[threejj+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvep[threejj+2] - dvwgh*ep[threejj+2])/wgh;
                        
                    }
                    else {
                        
                        spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                        BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                        
                        spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        ind = spanU - degU;
                        ind2 = spanV - degV;
                        myint = ind2*fourncp+ind*4;
                        
                        for (i = 0; i <= degV; i++){
                            for (j = 0; j <= degU; j++){
                                NN = NV[i] * NU[j];
                                ep[threejj] += NN * cp[i*fourncp+j*4+myint];
                                ep[threejj+1] += NN * cp[i*fourncp+j*4+myint+1];
                                ep[threejj+2] += NN * cp[i*fourncp+j*4+myint+2];
                                wgh += NN * cp[i*fourncp+j*4+myint+3];
                            }
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        
                        BasisFuns(spanV-1, us[2*jj+1], degV-1, &knotV[1], NV, leftV, rightV);
                        
                        for (i = 0; i < degV; i++){
                            for (j = 0; j <= degU; j++){
                                NN = NV[i] * NU[j];
                                dvep[threejj] += NN * dvcp[i*fourncp+j*4+myint];
                                dvep[threejj+1] += NN * dvcp[i*fourncp+j*4+myint+1];
                                dvep[threejj+2] += NN * dvcp[i*fourncp+j*4+myint+2];
                                dvwgh += NN * dvcp[i*fourncp+j*4+myint+3];
                            }
                        }
                        dvep[threejj] = (dvep[threejj] - dvwgh*ep[threejj])/wgh;
                        dvep[threejj+1] = (dvep[threejj+1] - dvwgh*ep[threejj+1])/wgh;
                        dvep[threejj+2] = (dvep[threejj+2] - dvwgh*ep[threejj+2])/wgh;
                        
                    }
                    
                }
                
            }
            
        }
        else {
            
            for (jj = 0; jj < nus; jj++){
                
                threejj = 3*jj;
                
                if (us[2*jj] <= knotU[degU]){
                    
                    if (us[2*jj+1] <= knotV[degV]){
                        
                        wgh = cp[3];
                        ep[threejj] = cp[0]/wgh;
                        ep[threejj+1] = cp[1]/wgh;
                        ep[threejj+2] = cp[2]/wgh;
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        
                        duvep[threejj] = 0.0;
                        duvep[threejj+1] = 0.0;
                        duvep[threejj+2] = 0.0;
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        
                    }
                    else if (us[2*jj+1] >= knotV[kcp]){
                        
                        myint = fourncp*(kcp-1);
                        wgh = cp[myint+3];
                        ep[threejj] = cp[myint]/wgh;
                        ep[threejj+1] = cp[myint+1]/wgh;
                        ep[threejj+2] = cp[myint+2]/wgh;
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        
                        duvep[threejj] = 0.0;
                        duvep[threejj+1] = 0.0;
                        duvep[threejj+2] = 0.0;
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        
                    }
                    else {
                        
                        ep[threejj] = 0.0;
                        ep[threejj+1] = 0.0;
                        ep[threejj+2] = 0.0;
                        wgh = 0.0;
                        
                        spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        ind = spanV - degV;
                        
                        for (i = 0; i <= degV; i++){
                            myint = (ind+i)*fourncp;
                            ep[threejj] += NV[i] * cp[myint];
                            ep[threejj+1] += NV[i] * cp[myint+1];
                            ep[threejj+2] += NV[i] * cp[myint+2];
                            wgh += NV[i] * cp[myint+3];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        
                        duvep[threejj] = 0.0;
                        duvep[threejj+1] = 0.0;
                        duvep[threejj+2] = 0.0;
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        
                    }
                    
                }
                else if (us[2*jj] >= knotU[ncp]){
                    
                    if (us[2*jj+1] <= knotV[degV]){
                        
                        wgh = cp[fourncp-1];
                        ep[threejj] = cp[fourncpm4]/wgh;
                        ep[threejj+1] = cp[fourncpm4+1]/wgh;
                        ep[threejj+2] = cp[fourncpm4+2]/wgh;
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        
                        duvep[threejj] = 0.0;
                        duvep[threejj+1] = 0.0;
                        duvep[threejj+2] = 0.0;
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        
                    }
                    else if (us[2*jj+1] >= knotV[kcp]){
                        
                        myint = fourncp*kcp;
                        wgh = cp[myint-1];
                        ep[threejj] = cp[myint-4]/wgh;
                        ep[threejj+1] = cp[myint-3]/wgh;
                        ep[threejj+2] = cp[myint-2]/wgh;
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        
                        duvep[threejj] = 0.0;
                        duvep[threejj+1] = 0.0;
                        duvep[threejj+2] = 0.0;
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        
                    }
                    else {
                        
                        ep[threejj] = 0.0;
                        ep[threejj+1] = 0.0;
                        ep[threejj+2] = 0.0;
                        wgh = 0.0;
                        
                        spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        ind = spanV - degV;
                        myint = (ind+1)*fourncp;
                        
                        for (i = 0; i <= degV; i++){
                            ep[threejj] += NV[i] * cp[i*fourncp+myint-4];
                            ep[threejj+1] += NV[i] * cp[i*fourncp+myint-3];
                            ep[threejj+2] += NV[i] * cp[i*fourncp+myint-2];
                            wgh += NV[i] * cp[i*fourncp+myint-1];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                        duep[threejj] = 0.0;
                        duep[threejj+1] = 0.0;
                        duep[threejj+2] = 0.0;
                        
                        dvep[threejj] = 0.0;
                        dvep[threejj+1] = 0.0;
                        dvep[threejj+2] = 0.0;
                        
                        duuep[threejj] = 0.0;
                        duuep[threejj+1] = 0.0;
                        duuep[threejj+2] = 0.0;
                        
                        duvep[threejj] = 0.0;
                        duvep[threejj+1] = 0.0;
                        duvep[threejj+2] = 0.0;
                        
                        dvvep[threejj] = 0.0;
                        dvvep[threejj+1] = 0.0;
                        dvvep[threejj+2] = 0.0;
                        
                    }
                    
                }
                else {
                    
                    ep[threejj] = 0.0;
                    ep[threejj+1] = 0.0;
                    ep[threejj+2] = 0.0;
                    wgh = 0.0;
                    
                    duep[threejj] = 0.0;
                    duep[threejj+1] = 0.0;
                    duep[threejj+2] = 0.0;
                    
                    dvep[threejj] = 0.0;
                    dvep[threejj+1] = 0.0;
                    dvep[threejj+2] = 0.0;
                    
                    duuep[threejj] = 0.0;
                    duuep[threejj+1] = 0.0;
                    duuep[threejj+2] = 0.0;
                    
                    duvep[threejj] = 0.0;
                    duvep[threejj+1] = 0.0;
                    duvep[threejj+2] = 0.0;
                    
                    dvvep[threejj] = 0.0;
                    dvvep[threejj+1] = 0.0;
                    dvvep[threejj+2] = 0.0;
                    
                    if (us[2*jj+1] <= knotV[degV]){
                        
                        spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                        BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                        
                        ind = spanU - degU;
                        
                        for (i = 0; i <= degU; i++){
                            ep[threejj] += NU[i] * cp[(ind+i)*4];
                            ep[threejj+1] += NU[i] * cp[(ind+i)*4+1];
                            ep[threejj+2] += NU[i] * cp[(ind+i)*4+2];
                            wgh += NU[i] * cp[(ind+i)*4+3];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                    }
                    else if (us[2*jj+1] >= knotV[kcp]){
                        
                        spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                        BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                        
                        ind = spanU - degU;
                        myint = ind*4+(kcp-1)*fourncp;
                        
                        for (i = 0; i <= degU; i++){
                            ep[threejj] += NU[i] * cp[i*4+myint];
                            ep[threejj+1] += NU[i] * cp[i*4+myint+1];
                            ep[threejj+2] += NU[i] * cp[i*4+myint+2];
                            wgh += NU[i] * cp[i*4+myint+3];
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                    }
                    else {
                        
                        spanU = FindSpan(ncp, degU, us[2*jj], knotU);
                        BasisFuns(spanU, us[2*jj], degU, knotU, NU, leftU, rightU);
                        
                        spanV = FindSpan(kcp, degV, us[2*jj+1], knotV);
                        BasisFuns(spanV, us[2*jj+1], degV, knotV, NV, leftV, rightV);
                        
                        ind = spanU - degU;
                        ind2 = spanV - degV;
                        myint = ind2*fourncp+ind*4;
                        
                        for (i = 0; i <= degV; i++){
                            for (j = 0; j <= degU; j++){
                                NN = NV[i] * NU[j];
                                ep[threejj] += NN * cp[i*fourncp+j*4+myint];
                                ep[threejj+1] += NN * cp[i*fourncp+j*4+myint+1];
                                ep[threejj+2] += NN * cp[i*fourncp+j*4+myint+2];
                                wgh += NN * cp[i*fourncp+j*4+myint+3];
                            }
                        }
                        ep[threejj] = ep[threejj]/wgh;
                        ep[threejj+1] = ep[threejj+1]/wgh;
                        ep[threejj+2] = ep[threejj+2]/wgh;
                        
                    }
                    
                }
                
            }
            
        }
        
    }
    
}
