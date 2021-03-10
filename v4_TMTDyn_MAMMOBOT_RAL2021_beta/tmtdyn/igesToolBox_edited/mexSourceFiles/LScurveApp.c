
/* Written by Per Bergström */

double pwr2(double a){
    return a*a;
}

static void LScurveApp(int deg, int ncp, double *knot, double *us, int dim, int nus, double *qmat, double *startq, double *endq, double *nmat, double *rmat, double *left, double *right, double *N){
    
    /* Originates from section 9.4.1, The NURBS Book, L.Piegl and W. Tiller */
    /* Least Squares Curve Approximation */
    
    int i, j, jj, span, sd, ncpm2;
    double Rk[4];
    
    ncpm2=ncp-2;
    
    for (jj = 0; jj < nus; jj++){
        
        for (j = 0; j < dim; j++){
            Rk[j]=qmat[dim*jj+j];
        }
        
        if(us[jj]<=knot[deg] || deg==0){
            /*
             *  Have no sense
             */
        }
        else if(us[jj]>=knot[ncp]){
            /*
             *  Have no sense
             */
        }
        else{
            span = FindSpan(ncp, deg, us[jj], knot);
            BasisFuns(span, us[jj], deg, knot, N, left, right);
            
            sd=span-deg-1;
            
            if(span==deg){
                for (j = 0; j < dim; j++){
                    Rk[j]-=N[0]*startq[j];
                }
            }
            if(span==(ncp-1)){
                for (j = 0; j < dim; j++){
                    Rk[j]-=N[deg]*endq[j];
                }
            }
            
            if(span==deg && span<(ncp-1)){
                for (i = 1; i <= deg; i++){
                    for (j = 1; j <= deg; j++){
                        nmat[j-1+(i-1)*ncpm2] += N[i]*N[j];
                    }
                    for (j = 0; j < dim; j++){
                        rmat[i-1+j*ncpm2]+=N[i]*Rk[j];
                    }
                }
            }
            else if(span==(ncp-1) && span>deg){
                for (i = 0; i < deg; i++){
                    for (j = 0; j < deg; j++){
                        nmat[j+sd+(i+sd)*ncpm2] += N[i]*N[j];
                    }
                    for (j = 0; j < dim; j++){
                        rmat[i+sd+j*ncpm2]+=N[i]*Rk[j];
                    }
                }
            }
            else if(span==(ncp-1) && span==deg){
                for (i = 1; i < deg; i++){
                    for (j = 1; j < deg; j++){
                        nmat[j-1+(i-1)*ncpm2] += N[i]*N[j];
                    }
                    for (j = 0; j < dim; j++){
                        rmat[i-1+j*ncpm2]+=N[i]*Rk[j];
                    }
                }
            }
            else{
                for (i = 0; i <= deg; i++){
                    for (j = 0; j <= deg; j++){
                        nmat[j+sd+(i+sd)*ncpm2] += N[i]*N[j];
                    }
                    for (j = 0; j < dim; j++){
                        rmat[i+sd+j*ncpm2]+=N[i]*Rk[j];
                    }
                }
            }
            
        }
        
    }
    
}

static void LScurveAppNUwghs(int deg, int ncp, double *knot, double *us, int dim, int nus, double *qmat, double *startq, double *endq, double *ctrlpnts, double *nmat, double *rmat, double *left, double *right, double *N){
    
    /* Originates from section 9.4.1, The NURBS Book, L.Piegl and W. Tiller */
    /* Least Squares Curve Approximation */
    
    int i, j, jj, span, sd, ncpm2;
    double Rk[4], wgh;
    
    ncpm2=ncp-2;
    
    for (jj = 0; jj < nus; jj++){
        
        for (j = 0; j < dim; j++){
            Rk[j]=qmat[dim*jj+j];
        }
        
        if(us[jj]<=knot[deg] || deg==0){
            /*
             *  Have no sense
             */
        }
        else if(us[jj]>=knot[ncp]){
            /*
             *  Have no sense
             */
        }
        else{
            span = FindSpan(ncp, deg, us[jj], knot);
            BasisFuns(span, us[jj], deg, knot, N, left, right);
            
            sd=span-deg;
            
            wgh = 0.0;
            for (i = 0; i <= deg; i++){
                wgh += N[i] * ctrlpnts[(i+sd)*4+3];
            }
            for (i = 0; i <= deg; i++){
                N[i] = N[i]/wgh;
            }
            
            sd-=1;
            
            if(span==deg){
                for (j = 0; j < dim; j++){
                    Rk[j]-=N[0]*startq[j];
                }
            }
            if(span==(ncp-1)){
                for (j = 0; j < dim; j++){
                    Rk[j]-=N[deg]*endq[j];
                }
            }
            
            if(span==deg && span<(ncp-1)){
                for (i = 1; i <= deg; i++){
                    for (j = 1; j <= deg; j++){
                        nmat[j-1+(i-1)*ncpm2] += N[i]*N[j];
                    }
                    for (j = 0; j < dim; j++){
                        rmat[i-1+j*ncpm2]+=N[i]*Rk[j];
                    }
                }
            }
            else if(span==(ncp-1) && span>deg){
                for (i = 0; i < deg; i++){
                    for (j = 0; j < deg; j++){
                        nmat[j+sd+(i+sd)*ncpm2] += N[i]*N[j];
                    }
                    for (j = 0; j < dim; j++){
                        rmat[i+sd+j*ncpm2]+=N[i]*Rk[j];
                    }
                }
            }
            else if(span==(ncp-1) && span==deg){
                for (i = 1; i < deg; i++){
                    for (j = 1; j < deg; j++){
                        nmat[j-1+(i-1)*ncpm2] += N[i]*N[j];
                    }
                    for (j = 0; j < dim; j++){
                        rmat[i-1+j*ncpm2]+=N[i]*Rk[j];
                    }
                }
            }
            else{
                for (i = 0; i <= deg; i++){
                    for (j = 0; j <= deg; j++){
                        nmat[j+sd+(i+sd)*ncpm2] += N[i]*N[j];
                    }
                    for (j = 0; j < dim; j++){
                        rmat[i+sd+j*ncpm2]+=N[i]*Rk[j];
                    }
                }
            }
            
        }
        
    }
    
}


static void LScurveAppEqPnt(int deg, int ncp, double *knot, double *us, int nus, double *qmat, unsigned int *ctrlPeq, int numCtrlPeq, double ctrlPeqWgh, double *ctrlpnts, double *nmat, double *rmat, double *left, double *right, double *N){
    
    /* Originates from section 9.4.1, The NURBS Book, L.Piegl and W. Tiller */
    /* Least Squares Curve Approximation */
    
    int i, j, jj, span, ind;
    double Rk[2], wghtmp;
    
    if (numCtrlPeq>0){
        
        bool isClosed;
        
        if (ctrlPeq[numCtrlPeq-1]==(ncp-1)){
            isClosed=1;
        }
        else{
            isClosed=0;
        }
        
        for (jj = 0; jj < nus; jj++){
            
            Rk[0]=qmat[2*jj];
            Rk[1]=qmat[2*jj+1];
            
            if(us[jj]<=knot[deg] || deg==0){
                nmat[0] += 1.0;
                rmat[0] += Rk[0];
                rmat[ncp] += Rk[1];
            }
            else if(us[jj]>=knot[ncp]){
                if (isClosed){
                    nmat[0] += ctrlPeqWgh;
                    rmat[0] += ctrlPeqWgh*Rk[0];
                    rmat[ncp] += ctrlPeqWgh*Rk[1];
                }
                else {
                    nmat[ncp*ncp-1] += 1.0;
                    rmat[ncp-1] += Rk[0];
                    rmat[2*ncp-1] += Rk[1];
                }
            }
            else{
                span = FindSpan(ncp, deg, us[jj], knot);
                BasisFuns(span, us[jj], deg, knot, N, left, right);
                
                ind=span-deg;
                
                if (isClosed){
                    if (fabs(knot[span+2]-knot[span+1])<1e-12){
                        if (fabs(knot[span]-knot[span-1])>1e-12){
                            wghtmp=(ctrlPeqWgh-1.0)*pwr2((us[jj]-knot[span])/(knot[span+1]-knot[span]))+1.0;
                        }
                        else {
                            wghtmp=1.0;
                        }
                    }
                    else if (fabs(knot[span]-knot[span-1])<1e-12){
                        wghtmp=(1.0-ctrlPeqWgh)*pwr2((us[jj]-knot[span])/(knot[span+1])-knot[span])+ctrlPeqWgh;
                    }
                    else {
                        wghtmp=1.0;
                    }
                }
                else {
                    if (span<(ncp-1) || span>deg){
                        if (fabs(knot[span+2]-knot[span+1])<1e-12){
                            if (fabs(knot[span]-knot[span-1])>1e-12){
                                wghtmp=(ctrlPeqWgh-1.0)*pwr2((us[jj]-knot[span])/(knot[span+1]-knot[span]))+1.0;
                            }
                            else {
                                wghtmp=1.0;
                            }
                        }
                        else if (fabs(knot[span]-knot[span-1])<1e-12){
                            wghtmp=(1.0-ctrlPeqWgh)*pwr2((us[jj]-knot[span])/(knot[span+1]-knot[span]))+ctrlPeqWgh;
                        }
                        else {
                            wghtmp=1.0;
                        }
                    }
                    else {
                        wghtmp=1.0;
                    }
                }
                
                if (span==(ncp-1) && isClosed){
                    
                    for (i = 0; i < deg; i++){
                        for (j = 0; j < (numCtrlPeq-1); j++){
                            if ((i+ind)==ctrlPeq[j]){
                                N[i+1]+=N[i];
                                N[i]=0.0;
                                break;
                            }
                        }
                    }
                    nmat[0] += wghtmp*N[deg]*N[deg];
                    rmat[0] += wghtmp*N[deg]*Rk[0];
                    rmat[ncp] += wghtmp*N[deg]*Rk[1];
                    for (j = 0; j < deg; j++){
                        nmat[j+ind] += wghtmp*N[deg]*N[j];
                        nmat[(j+ind)*ncp] += wghtmp*N[j]*N[deg];
                    }
                    for (i = 0; i < deg; i++){
                        for (j = 0; j < deg; j++){
                            nmat[j+ind+(i+ind)*ncp] += wghtmp*N[i]*N[j];
                        }
                        rmat[i+ind]+=wghtmp*N[i]*Rk[0];
                        rmat[i+ind+ncp]+=wghtmp*N[i]*Rk[1];
                    }
                }
                else if((unsigned int)ind>ctrlPeq[numCtrlPeq-1] || (unsigned int)span<ctrlPeq[0]){
                    
                    for (i = 0; i <= deg; i++){
                        for (j = 0; j <= deg; j++){
                            nmat[j+ind+(i+ind)*ncp] += wghtmp*N[i]*N[j];
                        }
                        rmat[i+ind]+=wghtmp*N[i]*Rk[0];
                        rmat[i+ind+ncp]+=wghtmp*N[i]*Rk[1];
                    }
                }
                else {
                    for (i = 0; i < deg; i++){
                        for (j = 0; j < numCtrlPeq; j++){
                            if ((i+ind)==ctrlPeq[j]){
                                N[i+1]+=N[i];
                                N[i]=0.0;
                                break;
                            }
                        }
                    }
                    for (j = 0; j < numCtrlPeq; j++){
                        if (span==ctrlPeq[j]){
                            nmat[span+1+(span+1)*ncp] += wghtmp*N[deg]*N[deg];
                            rmat[span+1] += wghtmp*N[deg]*Rk[0];
                            rmat[span+1+ncp] += wghtmp*N[deg]*Rk[1];
                            for (i = 0; i < deg; i++){
                                nmat[ind+i+(span+1)*ncp] += wghtmp*N[deg]*N[i];
                                nmat[span+1+(ind+i)*ncp] += wghtmp*N[i]*N[deg];
                            }
                            N[deg]=0.0;
                            break;
                        }
                    }
                    
                    for (i = 0; i <= deg; i++){
                        for (j = 0; j <= deg; j++){
                            nmat[j+ind+(i+ind)*ncp] += wghtmp*N[i]*N[j];
                        }
                        rmat[i+ind]+=wghtmp*N[i]*Rk[0];
                        rmat[i+ind+ncp]+=wghtmp*N[i]*Rk[1];
                    }
                }
            }
            
        }
        
    }
    
    else{
        
        for (jj = 0; jj < nus; jj++){
            
            Rk[0]=qmat[2*jj];
            Rk[1]=qmat[2*jj+1];
            
            if(us[jj]<=knot[deg] || deg==0){
                nmat[0] += 1.0;
                rmat[0] += Rk[0];
                rmat[ncp] += Rk[1];
            }
            else if(us[jj]>=knot[ncp]){
                nmat[ncp*ncp-1] += 1.0;
                rmat[ncp-1] += Rk[0];
                rmat[2*ncp-1] += Rk[1];
            }
            else{
                span = FindSpan(ncp, deg, us[jj], knot);
                BasisFuns(span, us[jj], deg, knot, N, left, right);
                
                ind=span-deg;
                
                for (i = 0; i <= deg; i++){
                    for (j = 0; j <= deg; j++){
                        nmat[j+ind+(i+ind)*ncp] += N[i]*N[j];
                    }
                    rmat[i+ind]+=N[i]*Rk[0];
                    rmat[i+ind+ncp]+=N[i]*Rk[1];
                }
                
            }
            
        }
        
    }
    
    for (i = 0; i < ncp; i++){
        if (nmat[i+i*ncp]<1.0){
            nmat[i+i*ncp] += 1.0;
            rmat[i] += ctrlpnts[4*i];
            rmat[i+ncp] += ctrlpnts[4*i+1];
        }
    }
    
}


static void LScurveAppEqPntStartEnd(int deg, int ncp, double *knot, double *us, int nus, double *qmat, unsigned int *ctrlPeq, int numCtrlPeq, double ctrlPeqWgh, double *ctrlpnts, double *startq, double *endq, double *nmat, double *rmat, double *left, double *right, double *N){
    
    /* Originates from section 9.4.1, The NURBS Book, L.Piegl and W. Tiller */
    /* Least Squares Curve Approximation */
    
    int i, j, jj, span, ind;
    double Rk[2], wghtmp;
    
    if (ctrlPeq[numCtrlPeq-1]==(ncp-1)){
        numCtrlPeq--;
    }
    
    for (jj = 0; jj < nus; jj++){
        
        Rk[0]=qmat[2*jj];
        Rk[1]=qmat[2*jj+1];
        
        if(us[jj]<=knot[deg] || deg==0){
            /*
             *          Have no sense
             * Rk[0]-=startq[0];
             * Rk[1]-=startq[1];
             */
        }
        else if(us[jj]>=knot[ncp]){
            /*
             *          Have no sense
             * Rk[0]-=endq[0];
             * Rk[1]-=endq[1];
             */
        }
        else{
            span = FindSpan(ncp, deg, us[jj], knot);
            BasisFuns(span, us[jj], deg, knot, N, left, right);
            
            ind=span-deg-1;
            
            if (span<(ncp-1) || span>deg){
                if (fabs(knot[span+2]-knot[span+1])<1e-12){
                    if (fabs(knot[span]-knot[span-1])>1e-12){
                        wghtmp=(ctrlPeqWgh-1.0)*pwr2((us[jj]-knot[span])/(knot[span+1]-knot[span]))+1.0;
                    }
                    else {
                        wghtmp=1.0;
                    }
                }
                else if (fabs(knot[span]-knot[span-1])<1e-12){
                    wghtmp=(1.0-ctrlPeqWgh)*pwr2((us[jj]-knot[span])/(knot[span+1]-knot[span]))+ctrlPeqWgh;
                }
                else {
                    wghtmp=1.0;
                }
            }
            else {
                wghtmp=1.0;
            }
            
            if(span==deg){
                Rk[0]-=N[0]*startq[0];
                Rk[1]-=N[0]*startq[1];
            }
            if(span==(ncp-1)){
                Rk[0]-=N[deg]*endq[0];
                Rk[1]-=N[deg]*endq[1];
            }
            
            if(span==deg && span<(ncp-1)){
                for (i = 1; i < deg; i++){
                    for (j = 0; j < numCtrlPeq; j++){
                        if ((i+ind+1)==ctrlPeq[j]){
                            N[i+1]+=N[i];
                            N[i]=0.0;
                            break;
                        }
                    }
                }
                for (j = 0; j < numCtrlPeq; j++){
                    if (span==ctrlPeq[j]){
                        nmat[span+span*(ncp-2)] += wghtmp*N[deg]*N[deg];
                        rmat[span] += wghtmp*N[deg]*Rk[0];
                        rmat[span+ncp-2] += wghtmp*N[deg]*Rk[1];
                        for (i = 0; i < deg; i++){
                            nmat[ind+i+span*(ncp-2)] += wghtmp*N[deg]*N[i];
                            nmat[span+(ind+i)*(ncp-2)] += wghtmp*N[i]*N[deg];
                        }
                        N[deg]=0.0;
                        break;
                    }
                }
                for (i = 1; i <= deg; i++){
                    for (j = 1; j <= deg; j++){
                        nmat[j-1+(i-1)*(ncp-2)] += wghtmp*N[i]*N[j];
                    }
                    rmat[i-1] += wghtmp*N[i]*Rk[0];
                    rmat[i-1+ncp-2] += wghtmp*N[i]*Rk[1];
                }
            }
            else if(span==(ncp-1) && span>deg){
                for (i = 0; i < deg; i++){
                    for (j = 0; j < numCtrlPeq; j++){
                        if ((i+ind+1)==ctrlPeq[j]){
                            N[i+1]+=N[i];
                            N[i]=0.0;
                            break;
                        }
                    }
                }
                for (i = 0; i < deg; i++){
                    for (j = 0; j < deg; j++){
                        nmat[j+ind+(i+ind)*(ncp-2)] += wghtmp*N[i]*N[j];
                    }
                    rmat[i+ind]+=wghtmp*N[i]*Rk[0];
                    rmat[i+ind+ncp-2]+=wghtmp*N[i]*Rk[1];
                }
            }
            else if(span==(ncp-1) && span==deg){
                for (i = 1; i < deg; i++){
                    for (j = 0; j < numCtrlPeq; j++){
                        if ((i+ind+1)==ctrlPeq[j]){
                            N[i+1]+=N[i];
                            N[i]=0.0;
                            break;
                        }
                    }
                }
                for (i = 1; i < deg; i++){
                    for (j = 1; j < deg; j++){
                        nmat[j-1+(i-1)*(ncp-2)] += wghtmp*N[i]*N[j];
                    }
                    rmat[i-1]+=wghtmp*N[i]*Rk[0];
                    rmat[i-1+ncp-2]+=wghtmp*N[i]*Rk[1];
                }
            }
            else{
                for (i = 0; i < deg; i++){
                    for (j = 0; j < numCtrlPeq; j++){
                        if ((i+ind+1)==ctrlPeq[j]){
                            N[i+1]+=N[i];
                            N[i]=0.0;
                            break;
                        }
                    }
                }
                for (j = 0; j < numCtrlPeq; j++){
                    if (span==ctrlPeq[j]){
                        nmat[span+span*(ncp-2)] += wghtmp*N[deg]*N[deg];
                        rmat[span] += wghtmp*N[deg]*Rk[0];
                        rmat[span+ncp-2] += wghtmp*N[deg]*Rk[1];
                        for (i = 0; i < deg; i++){
                            nmat[ind+i+span*(ncp-2)] += wghtmp*N[deg]*N[i];
                            nmat[span+(ind+i)*(ncp-2)] += wghtmp*N[i]*N[deg];
                        }
                        N[deg]=0.0;
                        break;
                    }
                }
                for (i = 0; i <= deg; i++){
                    for (j = 0; j <= deg; j++){
                        nmat[j+ind+(i+ind)*(ncp-2)] += wghtmp*N[i]*N[j];
                    }
                    rmat[i+ind]+=wghtmp*N[i]*Rk[0];
                    rmat[i+ind+ncp-2]+=wghtmp*N[i]*Rk[1];
                }
            }
            
        }
        
    }
    
    for (i = 0; i < (ncp-2); i++){
        if (nmat[i+i*(ncp-2)]<1.0){
            nmat[i+i*(ncp-2)] += 1.0;
            rmat[i] += ctrlpnts[4*(i+1)];
            rmat[i+ncp-2] += ctrlpnts[4*(i+1)+1];
        }
    }
    
}
