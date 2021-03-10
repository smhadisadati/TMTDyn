
/* Written by Per Bergström */

unsigned short int FindSpanIncSeq(unsigned short int n, double u, double *U, unsigned short int PrevSpan) {
    /* ALGORITHM A2.1 (with some modification), The NURBS Book, L.Piegl and W. Tiller */
    /* Determine the knot span index */
    /* Input: n,u,U */
    /* Return: the knot span index */
    
    unsigned short int low, high, mid;
    
    if (u < U[PrevSpan+1]){
        return(PrevSpan);
    }
    else if (u < U[PrevSpan+2]){
        return(PrevSpan+1);
    }
    else if (u >= U[n-1]){
        return(n-1);
    }
    else {
        low = PrevSpan+2;
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
