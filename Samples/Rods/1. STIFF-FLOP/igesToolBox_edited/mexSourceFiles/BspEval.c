
/* Written by Per Bergström */

static void BspEval(int deg, double *cp, int mcp, int ncp, double *knot, double *us, unsigned int nus, double *ep, double *left, double *right, double *N){
    /* Modification of  ALGORITHM A3.1, The NURBS Book, L.Piegl and W. Tiller */
    
    /* BspEval evaluates a B-spline at given parameter values */
    
    /* BspEval( deg - degree of B-spline, cp - pointer to control points, mcp - number of elements in a control point, ncp - number of control points, knot - pointer to knot sequence, us - pointer to parameter values, nus - number of parameter values, ep - pointer to evaluated points, left - pointer to array for function BasisFuns, right - pointer to array for function BasisFuns, N - pointer to array for function BasisFuns) */
    
    unsigned short int i, ii, span, myint;
    unsigned int jj, jjmcp=0;
    
    for (jj = 0; jj < nus; jj++){
        
        if(us[jj]<=knot[deg]){
            for (ii = 0; ii < mcp; ii++){
                ep[jjmcp+ii] = cp[ii];
            }
        }
        else if(us[jj]>=knot[ncp]){
            myint=mcp*ncp-mcp;
            for (ii = 0; ii < mcp; ii++){
                ep[jjmcp+ii] = cp[myint+ii];
            }
        }
        else{
            for (ii = 0; ii < mcp; ii++){
                ep[jjmcp+ii]=0.0;
            }
            span = FindSpan(ncp, deg, us[jj], knot);
            BasisFuns(span, us[jj], deg, knot, N, left, right);
            
            myint=(span-deg)*mcp;
            for (i = 0; i <= deg; i++){
                for (ii = 0; ii < mcp; ii++){
                    ep[jjmcp+ii] += N[i] * cp[myint+ii];
                }
                myint+=mcp;
            }
        }
        
        jjmcp+=mcp;
        
    }
    
}
