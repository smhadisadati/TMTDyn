
/* Written by Per Bergström */

static void NURBScurveEval(int deg, double *cp, int ncp, double *knot, double *us, unsigned int nus, double *ep, double *left, double *right, double *N){
    /* Modification of  ALGORITHM A4.1, The NURBS Book, L.Piegl and W. Tiller */
    
    /* Evaluates a NURBS curve at given parameter values */
    
    /* NURBScurveEval( deg - degree of NURBS, cp - pointer to control points, ncp - number of control points, knot - pointer to knot sequence, us - pointer to parameter values, nus - number of parameter values, ep - pointer to evaluated points, left - pointer to array for function BasisFuns, right - pointer to array for function BasisFuns, N - pointer to array for function BasisFuns) */
    
    unsigned short int i, span, ind, fourncp;
    unsigned int jj, threejj;
    double wgh;
    
    fourncp=4*ncp;
    
    for (jj = 0; jj < nus; jj++){
        
        threejj = 3*jj;
        
        if (us[jj] <= knot[deg]){
            
            ep[threejj] = cp[0]/cp[3];
            ep[threejj+1] = cp[1]/cp[3];
            ep[threejj+2] = cp[2]/cp[3];
            
        }
        else if (us[jj] >= knot[ncp]){
            
            ep[threejj] = cp[fourncp-4]/cp[fourncp-1];
            ep[threejj+1] = cp[fourncp-3]/cp[fourncp-1];
            ep[threejj+2] = cp[fourncp-2]/cp[fourncp-1];
            
        }
        else {
            
            ep[threejj] = 0.0;
            ep[threejj+1] = 0.0;
            ep[threejj+2] = 0.0;
            wgh = 0.0;
            
            span = FindSpan(ncp, deg, us[jj], knot);
            BasisFuns(span, us[jj], deg, knot, N, left, right);
            
            ind = span - deg;
            
            for (i = 0; i <= deg; i++){
                ep[threejj] += N[i] * cp[(i+ind)*4];
                ep[threejj+1] += N[i] * cp[(i+ind)*4+1];
                ep[threejj+2] += N[i] * cp[(i+ind)*4+2];
                wgh += N[i] * cp[(i+ind)*4+3];
            }
            ep[threejj] = ep[threejj]/wgh;
            ep[threejj+1] = ep[threejj+1]/wgh;
            ep[threejj+2] = ep[threejj+2]/wgh;
            
        }
        
    }
    
}


static void NURBScurveDeval(int deg, double *cp, double *dcp, int ncp, double *knot, double *us, unsigned int nus, double *ep, double *dep, double *left, double *right, double *N){
    /* Modification of  ALGORITHM A4.1, The NURBS Book, L.Piegl and W. Tiller */
    
    /* Evaluates a NURBS curve and derivatives at given parameter values */
    
    /* NURBScurveDeval( deg - degree of NURBS, cp - pointer to control points, dcp - pointer to derivative control points, ncp - number of control points, knot - pointer to knot sequence, us - pointer to parameter values, nus - number of parameter values, ep - pointer to evaluated points, dep - pointer to evaluated derivatives, left - pointer to array for function BasisFuns, right - pointer to array for function BasisFuns, N - pointer to array for function BasisFuns) */
    
    unsigned short int i, span, ind, fourncp;
    unsigned int jj, threejj;
    double wgh, dwgh;
    
    fourncp=4*ncp;
    
    if (deg>0){
        
        for (jj = 0; jj < nus; jj++){
            
            threejj = 3*jj;
            
            if (us[jj] <= knot[deg]){
                
                ep[threejj] = cp[0]/cp[3];
                ep[threejj+1] = cp[1]/cp[3];
                ep[threejj+2] = cp[2]/cp[3];
                
                dep[threejj] = (dcp[0] - dcp[3]*ep[threejj])/cp[3];
                dep[threejj+1] = (dcp[1] - dcp[3]*ep[threejj+1])/cp[3];
                dep[threejj+2] = (dcp[2] - dcp[3]*ep[threejj+2])/cp[3];
                
            }
            else if (us[jj] >= knot[ncp]){
                
                ep[threejj] = cp[fourncp-4]/cp[fourncp-1];
                ep[threejj+1] = cp[fourncp-3]/cp[fourncp-1];
                ep[threejj+2] = cp[fourncp-2]/cp[fourncp-1];
                
                dep[threejj] = (dcp[fourncp-8] - dcp[fourncp-5]*ep[threejj])/cp[fourncp-1];
                dep[threejj+1] = (dcp[fourncp-7] - dcp[fourncp-5]*ep[threejj+1])/cp[fourncp-1];
                dep[threejj+2] = (dcp[fourncp-6] - dcp[fourncp-5]*ep[threejj+2])/cp[fourncp-1];
                
            }
            else {
                
                ep[threejj] = 0.0;
                ep[threejj+1] = 0.0;
                ep[threejj+2] = 0.0;
                wgh = 0.0;
                
                span = FindSpan(ncp, deg, us[jj], knot);
                BasisFuns(span, us[jj], deg, knot, N, left, right);
                
                ind = span - deg;
                
                for (i = 0; i <= deg; i++){
                    ep[threejj] += N[i] * cp[(i+ind)*4];
                    ep[threejj+1] += N[i] * cp[(i+ind)*4+1];
                    ep[threejj+2] += N[i] * cp[(i+ind)*4+2];
                    wgh += N[i] * cp[(i+ind)*4+3];
                }
                ep[threejj] = ep[threejj]/wgh;
                ep[threejj+1] = ep[threejj+1]/wgh;
                ep[threejj+2] = ep[threejj+2]/wgh;
                
                
                dep[threejj] = 0.0;
                dep[threejj+1] = 0.0;
                dep[threejj+2] = 0.0;
                dwgh = 0.0;
                
                BasisFuns(span-1, us[jj], deg-1, &knot[1], N, left, right);
                
                for (i = 0; i < deg; i++){
                    dep[threejj] += N[i] * dcp[(i+ind)*4];
                    dep[threejj+1] += N[i] * dcp[(i+ind)*4+1];
                    dep[threejj+2] += N[i] * dcp[(i+ind)*4+2];
                    dwgh += N[i] * dcp[(i+ind)*4+3];
                }
                dep[threejj] = (dep[threejj] - dwgh*ep[threejj])/wgh;
                dep[threejj+1] = (dep[threejj+1] - dwgh*ep[threejj+1])/wgh;
                dep[threejj+2] = (dep[threejj+2] - dwgh*ep[threejj+2])/wgh;
                
            }
            
        }
        
    }
    else {
        
        for (jj = 0; jj < nus; jj++){
            
            threejj = 3*jj;
            
            if (us[jj] <= knot[deg]){
                
                ep[threejj] = cp[0]/cp[3];
                ep[threejj+1] = cp[1]/cp[3];
                ep[threejj+2] = cp[2]/cp[3];
                
                dep[threejj] = 0.0;
                dep[threejj+1] = 0.0;
                dep[threejj+2] = 0.0;
                
            }
            else if (us[jj] >= knot[ncp]){
                
                ep[threejj] = cp[fourncp-4]/cp[fourncp-1];
                ep[threejj+1] = cp[fourncp-3]/cp[fourncp-1];
                ep[threejj+2] = cp[fourncp-2]/cp[fourncp-1];
                
                dep[threejj] = 0.0;
                dep[threejj+1] = 0.0;
                dep[threejj+2] = 0.0;
                
            }
            else {
                
                ep[threejj] = 0.0;
                ep[threejj+1] = 0.0;
                ep[threejj+2] = 0.0;
                wgh = 0.0;
                
                span = FindSpan(ncp, deg, us[jj], knot);
                BasisFuns(span, us[jj], deg, knot, N, left, right);
                
                ind = span - deg;
                
                for (i = 0; i <= deg; i++){
                    ep[threejj] += N[i] * cp[(i+ind)*4];
                    ep[threejj+1] += N[i] * cp[(i+ind)*4+1];
                    ep[threejj+2] += N[i] * cp[(i+ind)*4+2];
                    wgh += N[i] * cp[(i+ind)*4+3];
                }
                ep[threejj] = ep[threejj]/wgh;
                ep[threejj+1] = ep[threejj+1]/wgh;
                ep[threejj+2] = ep[threejj+2]/wgh;
                
                dep[threejj] = 0.0;
                dep[threejj+1] = 0.0;
                dep[threejj+2] = 0.0;
                
            }
            
        }
        
    }
    
}


static void NURBScurveD2eval(int deg, double *cp, double *dcp, double *d2cp, int ncp, double *knot, double *us, unsigned int nus, double *ep, double *dep, double *d2ep, double *left, double *right, double *N){
    /* Modification of  ALGORITHM A4.1, The NURBS Book, L.Piegl and W. Tiller */
    
    /* Evaluates a NURBS curve and derivatives at given parameter values */
    
    /* NURBScurveD2eval( deg - degree of NURBS, cp - pointer to control points, dcp - pointer to derivative control points, d2cp - pointer to second derivative control points, ncp - number of control points, knot - pointer to knot sequence, us - pointer to parameter values, nus - number of parameter values, ep - pointer to evaluated points, dep - pointer to evaluated derivatives, d2ep - pointer to evaluated second derivatives, left - pointer to array for function BasisFuns, right - pointer to array for function BasisFuns, N - pointer to array for function BasisFuns) */
    
    unsigned short int i, span, ind, fourncp;
    unsigned int jj, threejj;
    double wgh, dwgh, d2wgh;
    
    fourncp=4*ncp;
    
    if (deg>1){
        
        for (jj = 0; jj < nus; jj++){
            
            threejj = 3*jj;
            
            if (us[jj] <= knot[deg]){
                
                ep[threejj] = cp[0]/cp[3];
                ep[threejj+1] = cp[1]/cp[3];
                ep[threejj+2] = cp[2]/cp[3];
                
                dep[threejj] = (dcp[0] - dcp[3]*ep[threejj])/cp[3];
                dep[threejj+1] = (dcp[1] - dcp[3]*ep[threejj+1])/cp[3];
                dep[threejj+2] = (dcp[2] - dcp[3]*ep[threejj+2])/cp[3];
                
                d2ep[threejj] = (d2cp[0] - 2.0*dcp[3]*dep[threejj] - d2cp[3]*ep[threejj])/cp[3];
                d2ep[threejj+1] = (d2cp[1] - 2.0*dcp[3]*dep[threejj+1] - d2cp[3]*ep[threejj+1])/cp[3];
                d2ep[threejj+2] = (d2cp[2] - 2.0*dcp[3]*dep[threejj+2] - d2cp[3]*ep[threejj+2])/cp[3];
                
            }
            else if (us[jj] >= knot[ncp]){
                
                ep[threejj] = cp[fourncp-4]/cp[fourncp-1];
                ep[threejj+1] = cp[fourncp-3]/cp[fourncp-1];
                ep[threejj+2] = cp[fourncp-2]/cp[fourncp-1];
                
                dep[threejj] = (dcp[fourncp-8] - dcp[fourncp-5]*ep[threejj])/cp[fourncp-1];
                dep[threejj+1] = (dcp[fourncp-7] - dcp[fourncp-5]*ep[threejj+1])/cp[fourncp-1];
                dep[threejj+2] = (dcp[fourncp-6] - dcp[fourncp-5]*ep[threejj+2])/cp[fourncp-1];
                
                d2ep[threejj] = (d2cp[fourncp-12] - 2.0*dcp[fourncp-5]*dep[threejj] - d2cp[fourncp-9]*ep[threejj])/cp[fourncp-1];
                d2ep[threejj+1] = (d2cp[fourncp-11] - 2.0*dcp[fourncp-5]*dep[threejj+1] - d2cp[fourncp-9]*ep[threejj+1])/cp[fourncp-1];
                d2ep[threejj+2] = (d2cp[fourncp-10] - 2.0*dcp[fourncp-5]*dep[threejj+2] - d2cp[fourncp-9]*ep[threejj+2])/cp[fourncp-1];
                
            }
            else {
                
                ep[threejj] = 0.0;
                ep[threejj+1] = 0.0;
                ep[threejj+2] = 0.0;
                wgh = 0.0;
                
                span = FindSpan(ncp, deg, us[jj], knot);
                BasisFuns(span, us[jj], deg, knot, N, left, right);
                
                ind = span - deg;
                
                for (i = 0; i <= deg; i++){
                    ep[threejj] += N[i] * cp[(i+ind)*4];
                    ep[threejj+1] += N[i] * cp[(i+ind)*4+1];
                    ep[threejj+2] += N[i] * cp[(i+ind)*4+2];
                    wgh += N[i] * cp[(i+ind)*4+3];
                }
                ep[threejj] = ep[threejj]/wgh;
                ep[threejj+1] = ep[threejj+1]/wgh;
                ep[threejj+2] = ep[threejj+2]/wgh;
                
                
                dep[threejj] = 0.0;
                dep[threejj+1] = 0.0;
                dep[threejj+2] = 0.0;
                dwgh = 0.0;
                
                BasisFuns(span-1, us[jj], deg-1, &knot[1], N, left, right);
                
                for (i = 0; i < deg; i++){
                    dep[threejj] += N[i] * dcp[(i+ind)*4];
                    dep[threejj+1] += N[i] * dcp[(i+ind)*4+1];
                    dep[threejj+2] += N[i] * dcp[(i+ind)*4+2];
                    dwgh += N[i] * dcp[(i+ind)*4+3];
                }
                dep[threejj] = (dep[threejj] - dwgh*ep[threejj])/wgh;
                dep[threejj+1] = (dep[threejj+1] - dwgh*ep[threejj+1])/wgh;
                dep[threejj+2] = (dep[threejj+2] - dwgh*ep[threejj+2])/wgh;
                
                
                d2ep[threejj] = 0.0;
                d2ep[threejj+1] = 0.0;
                d2ep[threejj+2] = 0.0;
                d2wgh = 0.0;
                
                BasisFuns(span-2, us[jj], deg-2, &knot[2], N, left, right);
                
                for (i = 0; i <= (deg-2); i++){
                    d2ep[threejj] += N[i] * d2cp[(i+ind)*4];
                    d2ep[threejj+1] += N[i] * d2cp[(i+ind)*4+1];
                    d2ep[threejj+2] += N[i] * d2cp[(i+ind)*4+2];
                    d2wgh += N[i] * d2cp[(i+ind)*4+3];
                }
                dwgh *= 2.0;
                d2ep[threejj] = (d2ep[threejj] - dwgh*dep[threejj] - d2wgh*ep[threejj])/wgh;
                d2ep[threejj+1] = (d2ep[threejj+1] - dwgh*dep[threejj+1] - d2wgh*ep[threejj+1])/wgh;
                d2ep[threejj+2] = (d2ep[threejj+2] - dwgh*dep[threejj+2] - d2wgh*ep[threejj+2])/wgh;
                
            }
            
        }
        
    }
    else if (deg>0){
        
        for (jj = 0; jj < nus; jj++){
            
            threejj = 3*jj;
            
            if (us[jj] <= knot[deg]){
                
                ep[threejj] = cp[0]/cp[3];
                ep[threejj+1] = cp[1]/cp[3];
                ep[threejj+2] = cp[2]/cp[3];
                
                dep[threejj] = (dcp[0] - dcp[3]*ep[threejj])/cp[3];
                dep[threejj+1] = (dcp[1] - dcp[3]*ep[threejj+1])/cp[3];
                dep[threejj+2] = (dcp[2] - dcp[3]*ep[threejj+2])/cp[3];
                
                d2ep[threejj] = 0.0;
                d2ep[threejj+1] = 0.0;
                d2ep[threejj+2] = 0.0;
                
            }
            else if (us[jj] >= knot[ncp]){
                
                ep[threejj] = cp[fourncp-4]/cp[fourncp-1];
                ep[threejj+1] = cp[fourncp-3]/cp[fourncp-1];
                ep[threejj+2] = cp[fourncp-2]/cp[fourncp-1];
                
                dep[threejj] = (dcp[fourncp-8] - dcp[fourncp-5]*ep[threejj])/cp[fourncp-1];
                dep[threejj+1] = (dcp[fourncp-7] - dcp[fourncp-5]*ep[threejj+1])/cp[fourncp-1];
                dep[threejj+2] = (dcp[fourncp-6] - dcp[fourncp-5]*ep[threejj+2])/cp[fourncp-1];
                
                d2ep[threejj] = 0.0;
                d2ep[threejj+1] = 0.0;
                d2ep[threejj+2] = 0.0;
                
            }
            else {
                
                ep[threejj] = 0.0;
                ep[threejj+1] = 0.0;
                ep[threejj+2] = 0.0;
                wgh = 0.0;
                
                span = FindSpan(ncp, deg, us[jj], knot);
                BasisFuns(span, us[jj], deg, knot, N, left, right);
                
                ind = span - deg;
                
                for (i = 0; i <= deg; i++){
                    ep[threejj] += N[i] * cp[(i+ind)*4];
                    ep[threejj+1] += N[i] * cp[(i+ind)*4+1];
                    ep[threejj+2] += N[i] * cp[(i+ind)*4+2];
                    wgh += N[i] * cp[(i+ind)*4+3];
                }
                ep[threejj] = ep[threejj]/wgh;
                ep[threejj+1] = ep[threejj+1]/wgh;
                ep[threejj+2] = ep[threejj+2]/wgh;
                
                
                dep[threejj] = 0.0;
                dep[threejj+1] = 0.0;
                dep[threejj+2] = 0.0;
                dwgh = 0.0;
                
                BasisFuns(span-1, us[jj], deg-1, &knot[1], N, left, right);
                
                for (i = 0; i < deg; i++){
                    dep[threejj] += N[i] * dcp[(i+ind)*4];
                    dep[threejj+1] += N[i] * dcp[(i+ind)*4+1];
                    dep[threejj+2] += N[i] * dcp[(i+ind)*4+2];
                    dwgh += N[i] * dcp[(i+ind)*4+3];
                }
                dep[threejj] = (dep[threejj] - dwgh*ep[threejj])/wgh;
                dep[threejj+1] = (dep[threejj+1] - dwgh*ep[threejj+1])/wgh;
                dep[threejj+2] = (dep[threejj+2] - dwgh*ep[threejj+2])/wgh;
                
                
                d2ep[threejj] = 0.0;
                d2ep[threejj+1] = 0.0;
                d2ep[threejj+2] = 0.0;
                
            }
            
        }
        
    }
    else {
        
        for (jj = 0; jj < nus; jj++){
            
            threejj = 3*jj;
            
            if (us[jj] <= knot[deg]){
                
                ep[threejj] = cp[0]/cp[3];
                ep[threejj+1] = cp[1]/cp[3];
                ep[threejj+2] = cp[2]/cp[3];
                
                dep[threejj] = 0.0;
                dep[threejj+1] = 0.0;
                dep[threejj+2] = 0.0;
                
                d2ep[threejj] = 0.0;
                d2ep[threejj+1] = 0.0;
                d2ep[threejj+2] = 0.0;
                
            }
            else if (us[jj] >= knot[ncp]){
                
                ep[threejj] = cp[fourncp-4]/cp[fourncp-1];
                ep[threejj+1] = cp[fourncp-3]/cp[fourncp-1];
                ep[threejj+2] = cp[fourncp-2]/cp[fourncp-1];
                
                dep[threejj] = 0.0;
                dep[threejj+1] = 0.0;
                dep[threejj+2] = 0.0;
                
                d2ep[threejj] = 0.0;
                d2ep[threejj+1] = 0.0;
                d2ep[threejj+2] = 0.0;
                
            }
            else {
                
                ep[threejj] = 0.0;
                ep[threejj+1] = 0.0;
                ep[threejj+2] = 0.0;
                wgh = 0.0;
                
                span = FindSpan(ncp, deg, us[jj], knot);
                BasisFuns(span, us[jj], deg, knot, N, left, right);
                
                ind = span - deg;
                
                for (i = 0; i <= deg; i++){
                    ep[threejj] += N[i] * cp[(i+ind)*4];
                    ep[threejj+1] += N[i] * cp[(i+ind)*4+1];
                    ep[threejj+2] += N[i] * cp[(i+ind)*4+2];
                    wgh += N[i] * cp[(i+ind)*4+3];
                }
                ep[threejj] = ep[threejj]/wgh;
                ep[threejj+1] = ep[threejj+1]/wgh;
                ep[threejj+2] = ep[threejj+2]/wgh;
                
                
                dep[threejj] = 0.0;
                dep[threejj+1] = 0.0;
                dep[threejj+2] = 0.0;
                
                
                d2ep[threejj] = 0.0;
                d2ep[threejj+1] = 0.0;
                d2ep[threejj+2] = 0.0;
                
            }
            
        }
        
    }
    
}
