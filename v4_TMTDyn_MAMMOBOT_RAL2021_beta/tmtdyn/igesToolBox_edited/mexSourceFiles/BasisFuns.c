
/* Written by Per Bergström */

void BasisFuns(unsigned short int i, double u, unsigned short int p, double *U, double *N, double *left, double *right) {
    /* ALGORITHM A2.2, The NURBS Book, L.Piegl and W. Tiller */
    /* Compute the nonvanishing basis functions */
    /* Input: i,u,p,U */
    /* Output: N */
    
    unsigned short int j, r;
    double saved, temp;
    
    N[0] = 1.0;
    
    for (j = 1; j <= p; j++) {
        left[j]  = u - U[i+1-j];
        right[j] = U[i+j] - u;
        
        temp = N[0] / (right[1] + left[j]);
        N[0] = right[1] * temp;
        saved = left[j] * temp;
        
        for (r = 1; r < j; r++) {
            temp = N[r] / (right[r+1] + left[j-r]);
            N[r] = saved + right[r+1] * temp;
            saved = left[j-r] * temp;
        }
        N[j] = saved;
    }
    
}
