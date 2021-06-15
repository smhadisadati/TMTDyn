
/* Written by Per Bergström */

unsigned short int FindSpan(unsigned short int n, unsigned short int p, double u, double *U) {
    /* ALGORITHM A2.1 (with some modification), The NURBS Book, L.Piegl and W. Tiller */
    /* Determine the knot span index */
    /* Input: n,p,u,U */
    /* Return: the knot span index */
    
    unsigned short int low, high, mid;
    
    if (u >= U[n-1]){
        return(n-1);
    }
    else if (u < U[p+1]){
        return(p);
    }
    else if ((n-p)==3){
        return(p+1);
    }
    else {
        low = p+1;
        high = n-1;
        mid =(low+high)/2;
        while (u < U[mid] || u >= U[mid+1]) {
            if (u < U[mid]){
                high = mid;
            }
            else{
                low = mid+1;
            }
            mid =(low+high)/2;
        }
        return(mid);
    }
    
}
