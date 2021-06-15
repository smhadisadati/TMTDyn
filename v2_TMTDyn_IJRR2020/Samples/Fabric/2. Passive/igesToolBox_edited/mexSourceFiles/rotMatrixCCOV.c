
/* Written by Per Bergström */

/* Required length of doubleVars 38 */

static void safeEucldNorm(double *a, double *b, double *d){
    
    /* A safe computation of                *
     * d = sqrt(a^2 + b^2)                  *
     * Many numerical problems are avoided  */
    
    if (a[0]>0.0){
        if (b[0]>0.0){
            
            if (a[0]>b[0]){
                
                if (350.0*b[0]<a[0]){
                    /* 4th order Taylor expansion */
                    d[0]=b[0]/a[0];
                    d[0]=a[0]+0.5*b[0]*d[0]*(1.0-0.25*d[0]*d[0]);
                }
                else if (110.0*b[0]<a[0]){
                    /* 6th order Taylor expansion */
                    d[0]=b[0]/a[0];
                    d[0]=a[0]+0.5*b[0]*d[0]*(1.0+(0.5*d[0]*d[0]-1.0)*0.25*d[0]*d[0]);
                }
                else {
                    /* Avoid over/under flow      */
                    d[0]=b[0]/a[0];
                    d[0]=a[0]*sqrt(1.0+d[0]*d[0]);
                }
                
            }
            else {
                
                if (350.0*a[0]<b[0]){
                    /* 4th order Taylor expansion */
                    d[0]=a[0]/b[0];
                    d[0]=b[0]+0.5*a[0]*d[0]*(1.0-0.25*d[0]*d[0]);
                }
                else if (110.0*a[0]<b[0]){
                    /* 6th order Taylor expansion */
                    d[0]=a[0]/b[0];
                    d[0]=b[0]+0.5*a[0]*d[0]*(1.0+(0.5*d[0]*d[0]-1.0)*0.25*d[0]*d[0]);
                }
                else {
                    /* Avoid over/under flow      */
                    d[0]=a[0]/b[0];
                    d[0]=b[0]*sqrt(1.0+d[0]*d[0]);
                }
                
            }
            
        }
        else {
            
            if (a[0]>-b[0]){
                
                if (a[0]>-350.0*b[0]){
                    /* 4th order Taylor expansion */
                    d[0]=b[0]/a[0];
                    d[0]=a[0]+0.5*b[0]*d[0]*(1.0-0.25*d[0]*d[0]);
                }
                else if (a[0]>-110.0*b[0]){
                    /* 6th order Taylor expansion */
                    d[0]=b[0]/a[0];
                    d[0]=a[0]+0.5*b[0]*d[0]*(1.0+(0.5*d[0]*d[0]-1.0)*0.25*d[0]*d[0]);
                }
                else {
                    /* Avoid over/under flow      */
                    d[0]=b[0]/a[0];
                    d[0]=a[0]*sqrt(1.0+d[0]*d[0]);
                }
                
            }
            else {
                
                if (b[0]<-350.0*a[0]){
                    /* 4th order Taylor expansion */
                    d[0]=a[0]/b[0];
                    d[0]=-b[0]-0.5*a[0]*d[0]*(1.0-0.25*d[0]*d[0]);
                }
                else if (b[0]<-110.0*a[0]){
                    /* 6th order Taylor expansion */
                    d[0]=a[0]/b[0];
                    d[0]=-b[0]-0.5*a[0]*d[0]*(1.0+(0.5*d[0]*d[0]-1.0)*0.25*d[0]*d[0]);
                }
                else {
                    /* Avoid over/under flow      */
                    d[0]=a[0]/b[0];
                    d[0]=-b[0]*sqrt(1.0+d[0]*d[0]);
                }
                
            }
            
        }
    }
    else {
        if (b[0]>0.0){
            
            if (a[0]<-b[0]){
                
                if (a[0]<-350.0*b[0]){
                    /* 4th order Taylor expansion */
                    d[0]=b[0]/a[0];
                    d[0]=-a[0]-0.5*b[0]*d[0]*(1.0-0.25*d[0]*d[0]);
                }
                else if (a[0]<-110.0*b[0]){
                    /* 6th order Taylor expansion */
                    d[0]=b[0]/a[0];
                    d[0]=-a[0]-0.5*b[0]*d[0]*(1.0+(0.5*d[0]*d[0]-1.0)*0.25*d[0]*d[0]);
                }
                else {
                    /* Avoid over/under flow      */
                    d[0]=b[0]/a[0];
                    d[0]=-a[0]*sqrt(1.0+d[0]*d[0]);
                }
                
            }
            else {
                
                if (b[0]>-350.0*a[0]){
                    /* 4th order Taylor expansion */
                    d[0]=a[0]/b[0];
                    d[0]=b[0]+0.5*a[0]*d[0]*(1.0-0.25*d[0]*d[0]);
                }
                else if (b[0]>-110.0*a[0]){
                    /* 6th order Taylor expansion */
                    d[0]=a[0]/b[0];
                    d[0]=b[0]+0.5*a[0]*d[0]*(1.0+(0.5*d[0]*d[0]-1.0)*0.25*d[0]*d[0]);
                }
                else {
                    /* Avoid over/under flow      */
                    d[0]=a[0]/b[0];
                    d[0]=b[0]*sqrt(1.0+d[0]*d[0]);
                }
                
            }
            
        }
        else {
            
            if (a[0]<b[0]){
                
                if (350.0*b[0]>a[0]){
                    /* 4th order Taylor expansion */
                    d[0]=b[0]/a[0];
                    d[0]=-a[0]-0.5*b[0]*d[0]*(1.0-0.25*d[0]*d[0]);
                }
                else if (110.0*b[0]>a[0]){
                    /* 6th order Taylor expansion */
                    d[0]=b[0]/a[0];
                    d[0]=-a[0]-0.5*b[0]*d[0]*(1.0+(0.5*d[0]*d[0]-1.0)*0.25*d[0]*d[0]);
                }
                else {
                    /* Avoid over/under flow      */
                    d[0]=b[0]/a[0];
                    d[0]=-a[0]*sqrt(1.0+d[0]*d[0]);
                }
                
            }
            else {
                
                if (b[0]>-1.0e-300){
                    d[0]=1.0e-300;
                }
                else if (350.0*a[0]>b[0]){
                    /* 4th order Taylor expansion */
                    d[0]=a[0]/b[0];
                    d[0]=-b[0]-0.5*a[0]*d[0]*(1.0-0.25*d[0]*d[0]);
                }
                else if (110.0*a[0]>b[0]){
                    /* 6th order Taylor expansion */
                    d[0]=a[0]/b[0];
                    d[0]=-b[0]-0.5*a[0]*d[0]*(1.0+(0.5*d[0]*d[0]-1.0)*0.25*d[0]*d[0]);
                }
                else {
                    /* Avoid over/under flow      */
                    d[0]=a[0]/b[0];
                    d[0]=-b[0]*sqrt(1.0+d[0]*d[0]);
                }
                
            }
            
        }
    }
    
    return;
    
}

static void safeEucldNormOne(double *a, double *d){
    
    /* A safe computation of                *
     * d = sqrt(1.0 + a^2)                  *
     * Some numerical problems are avoided  */
    
    if (a[0]>0.0){
        
        if (a[0]<1.0){
            
            if (a[0]<2.5e-3){
                /* 4th order Taylor expansion */
                d[0]=1.0+0.5*a[0]*a[0]*(1.0-0.25*a[0]*a[0]);
            }
            else if (a[0]<9.0e-3){
                /* 6th order Taylor expansion */
                d[0]=1.0+0.5*a[0]*a[0]*(1.0+(0.5*a[0]*a[0]-1.0)*0.25*a[0]*a[0]);
            }
            else {
                /* Compute the norm           */
                d[0]=sqrt(1.0+a[0]*a[0]);
            }
            
        }
        else {
            
            if (a[0]>350.0){
                /* 4th order Taylor expansion */
                d[0]=1.0/a[0];
                d[0]=a[0]+0.5*d[0]*(1.0-0.25*d[0]*d[0]);
            }
            else if (a[0]>110.0){
                /* 6th order Taylor expansion */
                d[0]=1.0/a[0];
                d[0]=a[0]+0.5*d[0]*(1.0+(0.5*d[0]*d[0]-1.0)*0.25*d[0]*d[0]);
            }
            else {
                /* Compute the norm           */
                d[0]=sqrt(1.0+a[0]*a[0]);
            }
            
        }
        
    }
    else {
        
        if (a[0]>-1.0){
            
            if (a[0]>-2.5e-3){
                /* 4th order Taylor expansion */
                d[0]=1.0+0.5*a[0]*a[0]*(1.0-0.25*a[0]*a[0]);
            }
            else if (a[0]>-9.0e-3){
                /* 6th order Taylor expansion */
                d[0]=1.0+0.5*a[0]*a[0]*(1.0+(0.5*a[0]*a[0]-1.0)*0.25*a[0]*a[0]);
            }
            else {
                /* Compute the norm           */
                d[0]=sqrt(1.0+a[0]*a[0]);
            }
            
        }
        else {
            
            if (a[0]<-350.0){
                /* 4th order Taylor expansion */
                d[0]=1.0/a[0];
                d[0]=-a[0]-0.5*d[0]*(1.0-0.25*d[0]*d[0]);
            }
            else if (a[0]<-110.0){
                /* 6th order Taylor expansion */
                d[0]=1.0/a[0];
                d[0]=-a[0]-0.5*d[0]*(1.0+(0.5*d[0]*d[0]-1.0)*0.25*d[0]*d[0]);
            }
            else {
                /* Compute the norm           */
                d[0]=sqrt(1.0+a[0]*a[0]);
            }
            
        }
        
    }
    
    return;
    
}

static void rotMatrixCCOVsubrtnII(double *rotationMatrix, double *Spx, double *SIGMA, double *MM, double *U, double *V, double *SpxTSpx, double *invmat, double *doubleVars){
    
    /* Computes a rotation matrix R that maximizes trace(R*Spx) *
     * using an accurate singular value decomposition of Spx.   *
     * R,Spx are 3x3 matrices.                                  */
    
    char flg;
    unsigned char i, j, jj, k, iters, myint, myint2;
    const unsigned char MAXITERS=30;
    
    /* Initialize variables */
    
    U[0]=Spx[0];
    U[1]=Spx[1];
    U[2]=Spx[2];
    U[3]=Spx[3];
    U[4]=Spx[4];
    U[5]=Spx[5];
    U[6]=Spx[6];
    U[7]=Spx[7];
    U[8]=Spx[8];
    
    SpxTSpx[0]=0.0;
    SpxTSpx[1]=0.0;
    SpxTSpx[2]=0.0;
    
    /* Householder reduction to bidiagonal form */
    
    for (i=0;i<3;i++){
        
        myint2=i+1;
        
        MM[i]=SpxTSpx[0]*SpxTSpx[2];
        SpxTSpx[2]=0.0;
        SpxTSpx[3]=0.0;
        SpxTSpx[0]=0.0;
        
        for (k=i;k<3;k++){
            SpxTSpx[0]+=fabs(U[k+3*i]);
        }
        
        if (SpxTSpx[0]>1.0e-90){
            
            for (k=i;k<3;k++){
                U[k+3*i]=U[k+3*i]/SpxTSpx[0];
                SpxTSpx[3]+=U[k+3*i]*U[k+3*i];
            }
            
            SpxTSpx[4]=U[4*i];
            
            if (SpxTSpx[4]>0.0){
                SpxTSpx[2]=-sqrt(SpxTSpx[3]);
            }
            else {
                SpxTSpx[2]=sqrt(SpxTSpx[3]);
            }
            
            SpxTSpx[5]=SpxTSpx[4]*SpxTSpx[2]-SpxTSpx[3];
            
            U[4*i]=SpxTSpx[4]-SpxTSpx[2];
            
            for (j=myint2;j<3;j++){
                SpxTSpx[3]=0.0;
                for (k=i;k<3;k++){
                    SpxTSpx[3]+=U[k+3*i]*U[k+3*j];
                }
                
                SpxTSpx[4]=SpxTSpx[3]/SpxTSpx[5];
                for (k=i;k<3;k++){
                    U[k+3*j]+=U[k+3*i]*SpxTSpx[4];
                }
            }
            for (k=i;k<3;k++){
                U[k+3*i]=U[k+3*i]*SpxTSpx[0];
            }
        }
        
        SIGMA[i]=SpxTSpx[0]*SpxTSpx[2];
        
        SpxTSpx[2]=0.0;
        SpxTSpx[3]=0.0;
        SpxTSpx[0]=0.0;
        
        for (k=myint2;k<3;k++){
            SpxTSpx[0]+=fabs(U[i+3*k]);
        }
        
        if (SpxTSpx[0]>1.0e-90){
            
            for (k=myint2;k<3;k++){
                U[i+3*k]=U[i+3*k]/SpxTSpx[0];
                SpxTSpx[3]+=U[i+3*k]*U[i+3*k];
            }
            SpxTSpx[4]=U[4*i+3];
            if (SpxTSpx[4]>0.0){
                SpxTSpx[2]=-sqrt(SpxTSpx[3]);
            }
            else {
                SpxTSpx[2]=sqrt(SpxTSpx[3]);
            }
            SpxTSpx[5]=SpxTSpx[4]*SpxTSpx[2]-SpxTSpx[3];
            U[4*i+3]=SpxTSpx[4]-SpxTSpx[2];
            
            for (k=myint2;k<3;k++){
                MM[k]=U[i+3*k]/SpxTSpx[5];
            }
            
            for (j=myint2;j<3;j++){
                SpxTSpx[3]=0.0;
                for (k=myint2;k<3;k++){
                    SpxTSpx[3]+=U[i+3*k]*U[j+3*k];
                }
                for (k=myint2;k<3;k++){
                    U[j+3*k]+=SpxTSpx[3]*MM[k];
                }
            }
            for (k=myint2;k<3;k++){
                U[i+3*k]=U[i+3*k]*SpxTSpx[0];
            }
        }
        
        doubleVars[0]=fabs(SIGMA[i])+fabs(MM[i]);
        
        if (doubleVars[0]>SpxTSpx[1]){
            SpxTSpx[1]=doubleVars[0];
        }
        
    }
    
    /* Accumulate right-hand transformations */
    
    i=2;
    {
        
        if (fabs(SpxTSpx[2])>1.0e-90){
            for (j=myint2;j<3;j++){
                V[j+3*i]=(U[i+3*j]/U[i+3*myint2])/SpxTSpx[2];
            }
            for (j=myint2;j<3;j++){
                SpxTSpx[3]=0.0;
                for (k=myint2;k<3;k++){
                    SpxTSpx[3]+=U[i+3*k]*V[k+3*j];
                }
                
                for (k=myint2;k<3;k++){
                    V[k+3*j]+=SpxTSpx[3]*V[k+3*i];
                }
            }
        }
        
        for (j=myint2;j<3;j++){
            V[i+3*j]=0.0;
            V[j+3*i]=0.0;
        }
        V[4*i]=1.0;
        SpxTSpx[2]=MM[i];
        
        myint2=i;
    }
    
    i=1;
    {
        
        if (fabs(SpxTSpx[2])>1.0e-90){
            for (j=myint2;j<3;j++){
                V[j+3*i]=(U[i+3*j]/U[i+3*myint2])/SpxTSpx[2];
            }
            for (j=myint2;j<3;j++){
                SpxTSpx[3]=0.0;
                for (k=myint2;k<3;k++){
                    SpxTSpx[3]+=U[i+3*k]*V[k+3*j];
                }
                
                for (k=myint2;k<3;k++){
                    V[k+3*j]+=SpxTSpx[3]*V[k+3*i];
                }
            }
        }
        
        for (j=myint2;j<3;j++){
            V[i+3*j]=0.0;
            V[j+3*i]=0.0;
        }
        V[4*i]=1.0;
        SpxTSpx[2]=MM[i];
        
        myint2=i;
    }
    
    i=0;
    {
        
        if (fabs(SpxTSpx[2])>1.0e-90){
            for (j=myint2;j<3;j++){
                V[j+3*i]=(U[i+3*j]/U[i+3*myint2])/SpxTSpx[2];
            }
            for (j=myint2;j<3;j++){
                SpxTSpx[3]=0.0;
                for (k=myint2;k<3;k++){
                    SpxTSpx[3]+=U[i+3*k]*V[k+3*j];
                }
                
                for (k=myint2;k<3;k++){
                    V[k+3*j]+=SpxTSpx[3]*V[k+3*i];
                }
            }
        }
        
        for (j=myint2;j<3;j++){
            V[i+3*j]=0.0;
            V[j+3*i]=0.0;
        }
        V[4*i]=1.0;
        SpxTSpx[2]=MM[i];
        
        myint2=i;
    }
    
    /* Accumulate left-hand transformations */
    
    i=2;
    {
        
        myint2=i+1;
        SpxTSpx[2]=SIGMA[i];
        
        for (j=myint2;j<3;j++){
            U[i+3*j]=0.0;
        }
        
        if (fabs(SpxTSpx[2])>1.0e-90){
            
            SpxTSpx[2]=1.0/SpxTSpx[2];
            for (j=myint2;j<3;j++){
                SpxTSpx[3]=0.0;
                for (k=myint2;k<3;k++){
                    SpxTSpx[3]+=U[k+3*i]*U[k+3*j];
                }
                SpxTSpx[4]=(SpxTSpx[3]/U[4*i])*SpxTSpx[2];
                
                for (k=i;k<3;k++){
                    U[k+3*j]+=SpxTSpx[4]*U[k+3*i];
                }
            }
            for (j=i;j<3;j++){
                U[j+3*i]=U[j+3*i]*SpxTSpx[2];
            }
        }
        else {
            for (j=i;j<3;j++){
                U[j+3*i]=0.0;
            }
        }
        U[4*i]+=1.0;
    }
    
    i=1;
    {
        
        myint2=i+1;
        SpxTSpx[2]=SIGMA[i];
        
        for (j=myint2;j<3;j++){
            U[i+3*j]=0.0;
        }
        
        if (fabs(SpxTSpx[2])>1.0e-90){
            
            SpxTSpx[2]=1.0/SpxTSpx[2];
            for (j=myint2;j<3;j++){
                SpxTSpx[3]=0.0;
                for (k=myint2;k<3;k++){
                    SpxTSpx[3]+=U[k+3*i]*U[k+3*j];
                }
                SpxTSpx[4]=(SpxTSpx[3]/U[4*i])*SpxTSpx[2];
                
                for (k=i;k<3;k++){
                    U[k+3*j]+=SpxTSpx[4]*U[k+3*i];
                }
            }
            for (j=i;j<3;j++){
                U[j+3*i]=U[j+3*i]*SpxTSpx[2];
            }
        }
        else {
            for (j=i;j<3;j++){
                U[j+3*i]=0.0;
            }
        }
        U[4*i]+=1.0;
    }
    
    i=0;
    {
        
        myint2=i+1;
        SpxTSpx[2]=SIGMA[i];
        
        for (j=myint2;j<3;j++){
            U[i+3*j]=0.0;
        }
        
        if (fabs(SpxTSpx[2])>1.0e-90){
            
            SpxTSpx[2]=1.0/SpxTSpx[2];
            for (j=myint2;j<3;j++){
                SpxTSpx[3]=0.0;
                for (k=myint2;k<3;k++){
                    SpxTSpx[3]+=U[k+3*i]*U[k+3*j];
                }
                SpxTSpx[4]=(SpxTSpx[3]/U[4*i])*SpxTSpx[2];
                
                for (k=i;k<3;k++){
                    U[k+3*j]+=SpxTSpx[4]*U[k+3*i];
                }
            }
            for (j=i;j<3;j++){
                U[j+3*i]=U[j+3*i]*SpxTSpx[2];
            }
        }
        else {
            for (j=i;j<3;j++){
                U[j+3*i]=0.0;
            }
        }
        U[4*i]+=1.0;
    }
    
    /* Diagonalize the bidiagonal form */
    
    k=2;
    {
        for (iters=0;iters<MAXITERS;iters++){
            
            flg=1;
            myint2=2;
            myint=1;
            if (1.0e15*fabs(MM[myint2])<SpxTSpx[1]){
                flg=0;
            }
            else if (1.0e15*fabs(SIGMA[myint])>SpxTSpx[1]){
                myint2=1;
                myint=0;
                if (1.0e15*fabs(MM[myint2])<SpxTSpx[1]){
                    flg=0;
                }
                else if (1.0e15*fabs(SIGMA[myint])>SpxTSpx[1]){
                    myint2=0;
                    if (1.0e15*fabs(MM[myint2])<SpxTSpx[1]){
                        flg=0;
                    }
                }
            }
            
            if (flg){
                
                invmat[0]=0.0;
                SpxTSpx[3]=1.0;
                
                for (i=myint2;i<=k;i++){
                    SpxTSpx[4]=SpxTSpx[3]*MM[i];
                    MM[i]=invmat[0]*MM[i];
                    if (1.0e15*fabs(SpxTSpx[4])<SpxTSpx[1]){
                        break;
                    }
                    SpxTSpx[2]=SIGMA[i];
                    safeEucldNorm(&SpxTSpx[2], &SpxTSpx[4], &SpxTSpx[5]);
                    SIGMA[i]=SpxTSpx[5];
                    SpxTSpx[5]=1.0/SpxTSpx[5];
                    invmat[0]=SpxTSpx[2]*SpxTSpx[5];
                    SpxTSpx[3]=-SpxTSpx[4]*SpxTSpx[5];
                    for (j=0;j<3;j++){
                        invmat[1]=U[j+3*myint];
                        invmat[2]=U[j+3*i];
                        
                        U[j+3*myint]=invmat[1]*invmat[0]+invmat[2]*SpxTSpx[3];
                        U[j+3*i]=invmat[2]*invmat[0]-invmat[1]*SpxTSpx[3];
                    }
                }
                
            }
            
            invmat[2]=SIGMA[k];
            
            if (myint2==k){
                if (invmat[2]<0.0){
                    /* Make singularvalue nonnegative */
                    SIGMA[k]=-invmat[2];
                    for (j=0;j<3;j++){
                        V[j+3*k]=-V[j+3*k];
                    }
                }
                break;
            }
            
            /* Shift from bottom 2x2 minor */
            
            invmat[3]=SIGMA[myint2];
            myint=k-1;
            invmat[1]=SIGMA[myint];
            SpxTSpx[2]=MM[myint];
            SpxTSpx[5]=MM[k];
            
            SpxTSpx[4]=((invmat[1]-invmat[2])*(invmat[1]+invmat[2])+(SpxTSpx[2]-SpxTSpx[5])*(SpxTSpx[2]+SpxTSpx[5]))/(2.0*SpxTSpx[5]*invmat[1]);
            
            safeEucldNormOne(&SpxTSpx[4], &SpxTSpx[2]);
            
            if (SpxTSpx[4]>0.0){
                if (SpxTSpx[2]>0.0){
                    SpxTSpx[4]=((invmat[3]-invmat[2])*(invmat[3]+invmat[2])+SpxTSpx[5]*((invmat[1]/(SpxTSpx[4]+SpxTSpx[2]))-SpxTSpx[5]))/invmat[3];
                }
                else {
                    SpxTSpx[4]=((invmat[3]-invmat[2])*(invmat[3]+invmat[2])+SpxTSpx[5]*((invmat[1]/(SpxTSpx[4]-SpxTSpx[2]))-SpxTSpx[5]))/invmat[3];
                }
            }
            else {
                if (SpxTSpx[2]>0.0){
                    SpxTSpx[4]=((invmat[3]-invmat[2])*(invmat[3]+invmat[2])+SpxTSpx[5]*((invmat[1]/(SpxTSpx[4]-SpxTSpx[2]))-SpxTSpx[5]))/invmat[3];
                }
                else {
                    SpxTSpx[4]=((invmat[3]-invmat[2])*(invmat[3]+invmat[2])+SpxTSpx[5]*((invmat[1]/(SpxTSpx[4]+SpxTSpx[2]))-SpxTSpx[5]))/invmat[3];
                }
            }
            
            /* Perform next QR decomposition */
            
            invmat[0]=1.0;
            SpxTSpx[3]=1.0;
            
            for (j=myint2;j<=myint;j++){
                i=j+1;
                invmat[1]=SIGMA[i];
                SpxTSpx[2]=MM[i];
                
                SpxTSpx[5]=SpxTSpx[3]*SpxTSpx[2];
                SpxTSpx[2]=invmat[0]*SpxTSpx[2];
                
                safeEucldNorm(&SpxTSpx[4], &SpxTSpx[5], &invmat[2]);
                
                MM[j]=invmat[2];
                
                if (invmat[2]>1.0e-90){
                    invmat[0]=SpxTSpx[4]/invmat[2];
                    SpxTSpx[3]=SpxTSpx[5]/invmat[2];
                }
                
                invmat[0]=SpxTSpx[4]/invmat[2];
                SpxTSpx[3]=SpxTSpx[5]/invmat[2];
                
                SpxTSpx[4]=invmat[3]*invmat[0]+SpxTSpx[2]*SpxTSpx[3];
                SpxTSpx[2]=SpxTSpx[2]*invmat[0]-invmat[3]*SpxTSpx[3];
                
                SpxTSpx[5]=invmat[1]*SpxTSpx[3];
                invmat[1]=invmat[1]*invmat[0];
                
                for (jj=0;jj<3;jj++){
                    invmat[3]=V[jj+3*j];
                    invmat[2]=V[jj+3*i];
                    
                    V[jj+3*j]=invmat[3]*invmat[0]+invmat[2]*SpxTSpx[3];
                    V[jj+3*i]=invmat[2]*invmat[0]-invmat[3]*SpxTSpx[3];
                }
                
                safeEucldNorm(&SpxTSpx[4], &SpxTSpx[5], &invmat[2]);
                
                SIGMA[j]=invmat[2];
                
                if (invmat[2]>1.0e-90){
                    invmat[0]=SpxTSpx[4]/invmat[2];
                    SpxTSpx[3]=SpxTSpx[5]/invmat[2];
                }
                
                SpxTSpx[4]=invmat[0]*SpxTSpx[2]+SpxTSpx[3]*invmat[1];
                invmat[3]=invmat[0]*invmat[1]-SpxTSpx[3]*SpxTSpx[2];
                
                for (jj=0;jj<3;jj++){
                    invmat[1]=U[jj+3*j];
                    invmat[2]=U[jj+3*i];
                    
                    U[jj+3*j]=invmat[1]*invmat[0]+invmat[2]*SpxTSpx[3];
                    U[jj+3*i]=invmat[2]*invmat[0]-invmat[1]*SpxTSpx[3];
                }
                
            }
            
            MM[myint2]=0.0;
            MM[k]=SpxTSpx[4];
            SIGMA[k]=invmat[3];
            
        }
    }
    
    k=1;
    {
        for (iters=0;iters<MAXITERS;iters++){
            
            flg=1;
            myint2=1;
            myint=0;
            if (1.0e15*fabs(MM[myint2])<SpxTSpx[1]){
                flg=0;
            }
            else if (1.0e15*fabs(SIGMA[myint])>SpxTSpx[1]){
                myint2=0;
                if (1.0e15*fabs(MM[myint2])<SpxTSpx[1]){
                    flg=0;
                }
            }
            
            if (flg){
                
                invmat[0]=0.0;
                SpxTSpx[3]=1.0;
                
                for (i=myint2;i<=k;i++){
                    SpxTSpx[4]=SpxTSpx[3]*MM[i];
                    MM[i]=invmat[0]*MM[i];
                    if (1.0e15*fabs(SpxTSpx[4])<SpxTSpx[1]){
                        break;
                    }
                    SpxTSpx[2]=SIGMA[i];
                    safeEucldNorm(&SpxTSpx[2], &SpxTSpx[4], &SpxTSpx[5]);
                    SIGMA[i]=SpxTSpx[5];
                    SpxTSpx[5]=1.0/SpxTSpx[5];
                    invmat[0]=SpxTSpx[2]*SpxTSpx[5];
                    SpxTSpx[3]=-SpxTSpx[4]*SpxTSpx[5];
                    for (j=0;j<3;j++){
                        invmat[1]=U[j+3*myint];
                        invmat[2]=U[j+3*i];
                        
                        U[j+3*myint]=invmat[1]*invmat[0]+invmat[2]*SpxTSpx[3];
                        U[j+3*i]=invmat[2]*invmat[0]-invmat[1]*SpxTSpx[3];
                    }
                }
                
            }
            
            invmat[2]=SIGMA[k];
            
            if (myint2==k){
                if (invmat[2]<0.0){
                    /* Make singularvalue nonnegative */
                    SIGMA[k]=-invmat[2];
                    for (j=0;j<3;j++){
                        V[j+3*k]=-V[j+3*k];
                    }
                }
                break;
            }
            
            /* Shift from bottom 2x2 minor */
            
            invmat[3]=SIGMA[myint2];
            myint=k-1;
            invmat[1]=SIGMA[myint];
            SpxTSpx[2]=MM[myint];
            SpxTSpx[5]=MM[k];
            
            SpxTSpx[4]=((invmat[1]-invmat[2])*(invmat[1]+invmat[2])+(SpxTSpx[2]-SpxTSpx[5])*(SpxTSpx[2]+SpxTSpx[5]))/(2.0*SpxTSpx[5]*invmat[1]);
            
            safeEucldNormOne(&SpxTSpx[4], &SpxTSpx[2]);
            
            if (SpxTSpx[4]>0.0){
                if (SpxTSpx[2]>0.0){
                    SpxTSpx[4]=((invmat[3]-invmat[2])*(invmat[3]+invmat[2])+SpxTSpx[5]*((invmat[1]/(SpxTSpx[4]+SpxTSpx[2]))-SpxTSpx[5]))/invmat[3];
                }
                else {
                    SpxTSpx[4]=((invmat[3]-invmat[2])*(invmat[3]+invmat[2])+SpxTSpx[5]*((invmat[1]/(SpxTSpx[4]-SpxTSpx[2]))-SpxTSpx[5]))/invmat[3];
                }
            }
            else {
                if (SpxTSpx[2]>0.0){
                    SpxTSpx[4]=((invmat[3]-invmat[2])*(invmat[3]+invmat[2])+SpxTSpx[5]*((invmat[1]/(SpxTSpx[4]-SpxTSpx[2]))-SpxTSpx[5]))/invmat[3];
                }
                else {
                    SpxTSpx[4]=((invmat[3]-invmat[2])*(invmat[3]+invmat[2])+SpxTSpx[5]*((invmat[1]/(SpxTSpx[4]+SpxTSpx[2]))-SpxTSpx[5]))/invmat[3];
                }
            }
            
            /* Perform next QR decomposition */
            
            invmat[0]=1.0;
            SpxTSpx[3]=1.0;
            
            for (j=myint2;j<=myint;j++){
                i=j+1;
                invmat[1]=SIGMA[i];
                SpxTSpx[2]=MM[i];
                
                SpxTSpx[5]=SpxTSpx[3]*SpxTSpx[2];
                SpxTSpx[2]=invmat[0]*SpxTSpx[2];
                
                safeEucldNorm(&SpxTSpx[4], &SpxTSpx[5], &invmat[2]);
                
                MM[j]=invmat[2];
                
                if (invmat[2]>1.0e-90){
                    invmat[0]=SpxTSpx[4]/invmat[2];
                    SpxTSpx[3]=SpxTSpx[5]/invmat[2];
                }
                
                invmat[0]=SpxTSpx[4]/invmat[2];
                SpxTSpx[3]=SpxTSpx[5]/invmat[2];
                
                SpxTSpx[4]=invmat[3]*invmat[0]+SpxTSpx[2]*SpxTSpx[3];
                SpxTSpx[2]=SpxTSpx[2]*invmat[0]-invmat[3]*SpxTSpx[3];
                
                SpxTSpx[5]=invmat[1]*SpxTSpx[3];
                invmat[1]=invmat[1]*invmat[0];
                
                for (jj=0;jj<3;jj++){
                    invmat[3]=V[jj+3*j];
                    invmat[2]=V[jj+3*i];
                    
                    V[jj+3*j]=invmat[3]*invmat[0]+invmat[2]*SpxTSpx[3];
                    V[jj+3*i]=invmat[2]*invmat[0]-invmat[3]*SpxTSpx[3];
                }
                
                safeEucldNorm(&SpxTSpx[4], &SpxTSpx[5], &invmat[2]);
                
                SIGMA[j]=invmat[2];
                
                if (invmat[2]>1.0e-90){
                    invmat[0]=SpxTSpx[4]/invmat[2];
                    SpxTSpx[3]=SpxTSpx[5]/invmat[2];
                }
                
                SpxTSpx[4]=invmat[0]*SpxTSpx[2]+SpxTSpx[3]*invmat[1];
                invmat[3]=invmat[0]*invmat[1]-SpxTSpx[3]*SpxTSpx[2];
                
                for (jj=0;jj<3;jj++){
                    invmat[1]=U[jj+3*j];
                    invmat[2]=U[jj+3*i];
                    
                    U[jj+3*j]=invmat[1]*invmat[0]+invmat[2]*SpxTSpx[3];
                    U[jj+3*i]=invmat[2]*invmat[0]-invmat[1]*SpxTSpx[3];
                }
                
            }
            
            MM[myint2]=0.0;
            MM[k]=SpxTSpx[4];
            SIGMA[k]=invmat[3];
            
        }
    }
    
    k=0;
    {
        
        flg=1;
        myint2=0;
        if (1.0e15*fabs(MM[myint2])<SpxTSpx[1]){
            flg=0;
        }
        
        if (flg){
            
            invmat[0]=0.0;
            SpxTSpx[3]=1.0;
            
            for (i=myint2;i<=k;i++){
                SpxTSpx[4]=SpxTSpx[3]*MM[i];
                MM[i]=invmat[0]*MM[i];
                if (1.0e15*fabs(SpxTSpx[4])<SpxTSpx[1]){
                    break;
                }
                SpxTSpx[2]=SIGMA[i];
                safeEucldNorm(&SpxTSpx[2], &SpxTSpx[4], &SpxTSpx[5]);
                SIGMA[i]=SpxTSpx[5];
                SpxTSpx[5]=1.0/SpxTSpx[5];
                invmat[0]=SpxTSpx[2]*SpxTSpx[5];
                SpxTSpx[3]=-SpxTSpx[4]*SpxTSpx[5];
                for (j=0;j<3;j++){
                    invmat[1]=U[j+3*myint];
                    invmat[2]=U[j+3*i];
                    
                    U[j+3*myint]=invmat[1]*invmat[0]+invmat[2]*SpxTSpx[3];
                    U[j+3*i]=invmat[2]*invmat[0]-invmat[1]*SpxTSpx[3];
                }
            }
            
        }
        
        if (SIGMA[k]<0.0){
            /* Make singularvalue nonnegative */
            SIGMA[k]=-SIGMA[k];
            for (j=0;j<3;j++){
                V[j+3*k]=-V[j+3*k];
            }
        }
        
    }
    
    /* The last value of SIGMA will be the smallest one */
    
    if (SIGMA[0]<SIGMA[2]){
        if (SIGMA[0]<SIGMA[1]){
            MM[0]=SIGMA[0];
            SIGMA[0]=SIGMA[2];
            SIGMA[2]=MM[0];
            
            MM[0]=U[0];
            MM[1]=U[1];
            MM[2]=U[2];
            
            U[0]=U[6];
            U[1]=U[7];
            U[2]=U[8];
            
            U[6]=MM[0];
            U[7]=MM[1];
            U[8]=MM[2];
            
            MM[0]=V[0];
            MM[1]=V[1];
            MM[2]=V[2];
            
            V[0]=V[6];
            V[1]=V[7];
            V[2]=V[8];
            
            V[6]=MM[0];
            V[7]=MM[1];
            V[8]=MM[2];
        }
        else {
            MM[0]=SIGMA[1];
            SIGMA[1]=SIGMA[2];
            SIGMA[2]=MM[0];
            
            MM[0]=U[3];
            MM[1]=U[4];
            MM[2]=U[5];
            
            U[3]=U[6];
            U[4]=U[7];
            U[5]=U[8];
            
            U[6]=MM[0];
            U[7]=MM[1];
            U[8]=MM[2];
            
            MM[0]=V[3];
            MM[1]=V[4];
            MM[2]=V[5];
            
            V[3]=V[6];
            V[4]=V[7];
            V[5]=V[8];
            
            V[6]=MM[0];
            V[7]=MM[1];
            V[8]=MM[2];
        }
    }
    else if (SIGMA[1]<SIGMA[2]){
        MM[0]=SIGMA[1];
        SIGMA[1]=SIGMA[2];
        SIGMA[2]=MM[0];
        
        MM[0]=U[3];
        MM[1]=U[4];
        MM[2]=U[5];
        
        U[3]=U[6];
        U[4]=U[7];
        U[5]=U[8];
        
        U[6]=MM[0];
        U[7]=MM[1];
        U[8]=MM[2];
        
        MM[0]=V[3];
        MM[1]=V[4];
        MM[2]=V[5];
        
        V[3]=V[6];
        V[4]=V[7];
        V[5]=V[8];
        
        V[6]=MM[0];
        V[7]=MM[1];
        V[8]=MM[2];
    }
    
    /* R=U*V' */
    
    rotationMatrix[0]=U[0]*V[0]+U[3]*V[3]+U[6]*V[6];
    rotationMatrix[1]=U[1]*V[0]+U[4]*V[3]+U[7]*V[6];
    rotationMatrix[2]=U[2]*V[0]+U[5]*V[3]+U[8]*V[6];
    
    rotationMatrix[3]=U[0]*V[1]+U[3]*V[4]+U[6]*V[7];
    rotationMatrix[4]=U[1]*V[1]+U[4]*V[4]+U[7]*V[7];
    rotationMatrix[5]=U[2]*V[1]+U[5]*V[4]+U[8]*V[7];
    
    rotationMatrix[6]=U[0]*V[2]+U[3]*V[5]+U[6]*V[8];
    rotationMatrix[7]=U[1]*V[2]+U[4]*V[5]+U[7]*V[8];
    rotationMatrix[8]=U[2]*V[2]+U[5]*V[5]+U[8]*V[8];
    
    /* Check if det(R)==-1 */
    
    if ((rotationMatrix[0]*(rotationMatrix[4]*rotationMatrix[8]-rotationMatrix[5]*rotationMatrix[7])+rotationMatrix[1]*(rotationMatrix[5]*rotationMatrix[6]-rotationMatrix[3]*rotationMatrix[8])+rotationMatrix[2]*(rotationMatrix[3]*rotationMatrix[7]-rotationMatrix[4]*rotationMatrix[6]))<0.0){
        rotationMatrix[0]=U[0]*V[0]+U[3]*V[3]-U[6]*V[6];
        rotationMatrix[1]=U[1]*V[0]+U[4]*V[3]-U[7]*V[6];
        rotationMatrix[2]=U[2]*V[0]+U[5]*V[3]-U[8]*V[6];
        
        rotationMatrix[3]=U[0]*V[1]+U[3]*V[4]-U[6]*V[7];
        rotationMatrix[4]=U[1]*V[1]+U[4]*V[4]-U[7]*V[7];
        rotationMatrix[5]=U[2]*V[1]+U[5]*V[4]-U[8]*V[7];
        
        rotationMatrix[6]=U[0]*V[2]+U[3]*V[5]-U[6]*V[8];
        rotationMatrix[7]=U[1]*V[2]+U[4]*V[5]-U[7]*V[8];
        rotationMatrix[8]=U[2]*V[2]+U[5]*V[5]-U[8]*V[8];
    }
    
    return;
    
}

static void rotMatrixCCOVsubrtn(double *rotationMatrix, double *Spx, double *SIGMA, double *MM, double *U, double *V, double *SpxTSpx, double *invmat, double *doubleVars){
    
    /* Computes a rotation matrix R that maximizes trace(R*Spx)       *
     * using a rough singular value decomposition of Spx.             *
     * If necessary an accurate singular value decomposition is used. *
     * R,Spx are 3x3 matrices.                                        */
    
    unsigned char i, j, threei;
    
    SpxTSpx[0]=Spx[0]*Spx[0]+Spx[1]*Spx[1]+Spx[2]*Spx[2];
    SpxTSpx[1]=Spx[3]*Spx[3]+Spx[4]*Spx[4]+Spx[5]*Spx[5];
    SpxTSpx[2]=Spx[6]*Spx[6]+Spx[7]*Spx[7]+Spx[8]*Spx[8];
    SpxTSpx[3]=Spx[0]*Spx[3]+Spx[1]*Spx[4]+Spx[5]*Spx[2];
    SpxTSpx[4]=Spx[3]*Spx[6]+Spx[4]*Spx[7]+Spx[5]*Spx[8];
    SpxTSpx[5]=Spx[0]*Spx[6]+Spx[1]*Spx[7]+Spx[2]*Spx[8];
    
    
    /*   CharacteristicPolynomial  sigma^3-A*sigma^2-B*sigma+C   */
    
    /* A */
    doubleVars[0]=SpxTSpx[2]+SpxTSpx[1]+SpxTSpx[0];
    /* B */
    doubleVars[1]=SpxTSpx[5]*SpxTSpx[5]+SpxTSpx[4]*SpxTSpx[4]-SpxTSpx[2]*SpxTSpx[1]-SpxTSpx[2]*SpxTSpx[0]+SpxTSpx[3]*SpxTSpx[3]-SpxTSpx[1]*SpxTSpx[0];
    /* C */
    doubleVars[2]=-2*SpxTSpx[5]*SpxTSpx[3]*SpxTSpx[4]+SpxTSpx[5]*SpxTSpx[5]*SpxTSpx[1]+SpxTSpx[4]*SpxTSpx[4]*SpxTSpx[0]+SpxTSpx[2]*SpxTSpx[3]*SpxTSpx[3]-SpxTSpx[2]*SpxTSpx[1]*SpxTSpx[0];
    
    /* A^2+3B */
    doubleVars[3]=doubleVars[0]*doubleVars[0]+3*doubleVars[1];
    
    if (doubleVars[3]<1.0e-30){
        
        rotMatrixCCOVsubrtnII(rotationMatrix, Spx, SIGMA, MM, U, V, SpxTSpx, invmat, doubleVars);
        return;
        
    }
    else {
        
        /* sqrt(A^2+3B) */
        doubleVars[3]=sqrt(doubleVars[3]);
        
        if (1.0e4*doubleVars[3]<doubleVars[0]){
            
            rotMatrixCCOVsubrtnII(rotationMatrix, Spx, SIGMA, MM, U, V, SpxTSpx, invmat, doubleVars);
            return;
            
        }
        else {
            
            doubleVars[4]=(doubleVars[0]-doubleVars[3])/3.0;
            doubleVars[5]=(doubleVars[0]+doubleVars[3])/3.0;
            
            doubleVars[6]=doubleVars[4]*doubleVars[4]*doubleVars[4]-doubleVars[4]*doubleVars[4]*doubleVars[0]-doubleVars[4]*doubleVars[1]+doubleVars[2];
            doubleVars[7]=doubleVars[5]*doubleVars[5]*doubleVars[5]-doubleVars[5]*doubleVars[5]*doubleVars[0]-doubleVars[5]*doubleVars[1]+doubleVars[2];
            
            if ((doubleVars[6]+doubleVars[7])>0.0){
                
                /* Smallest eigenvalue */
                
                /* Newton-Raphson */
                
                SIGMA[2]=doubleVars[2]/doubleVars[1];
                
                for (i=0;i<50;i++){
                    doubleVars[6]=SIGMA[2];
                    SIGMA[2]=(doubleVars[0]*SIGMA[2]*SIGMA[2]-2.0*SIGMA[2]*SIGMA[2]*SIGMA[2]+doubleVars[2])/(2.0*doubleVars[0]*SIGMA[2]-3.0*SIGMA[2]*SIGMA[2]+doubleVars[1]);
                    if (fabs(SIGMA[2]-doubleVars[6])<SIGMA[2]*1.0e-16){
                        break;
                    }
                }
                
                /* The other eigenvalues */
                
                doubleVars[3]=2.0*doubleVars[0]*SIGMA[2]-3.0*SIGMA[2]*SIGMA[2]+doubleVars[0]*doubleVars[0]+4.0*doubleVars[1];
                
                if (doubleVars[3]>0.0){
                    doubleVars[3]=sqrt(doubleVars[3]);
                    SIGMA[1]=(doubleVars[0]-SIGMA[2]-doubleVars[3])/2.0;
                    SIGMA[0]=(doubleVars[0]-SIGMA[2]+doubleVars[3])/2.0;
                }
                else {
                    SIGMA[1]=(doubleVars[0]-SIGMA[2])/2.0;
                    SIGMA[0]=SIGMA[1];
                }
                
                /* To ensure a good numerical solution */
                
                if (1.0e3*doubleVars[3]<SIGMA[0]){
                    rotMatrixCCOVsubrtnII(rotationMatrix, Spx, SIGMA, MM, U, V, SpxTSpx, invmat, doubleVars);
                    return;
                }
                
                /* Improve the other eigenvalues using Newton-Raphson */
                
                SIGMA[0]=(doubleVars[0]*SIGMA[0]*SIGMA[0]-2.0*SIGMA[0]*SIGMA[0]*SIGMA[0]+doubleVars[2])/(2.0*doubleVars[0]*SIGMA[0]-3.0*SIGMA[0]*SIGMA[0]+doubleVars[1]);
                SIGMA[0]=(doubleVars[0]*SIGMA[0]*SIGMA[0]-2.0*SIGMA[0]*SIGMA[0]*SIGMA[0]+doubleVars[2])/(2.0*doubleVars[0]*SIGMA[0]-3.0*SIGMA[0]*SIGMA[0]+doubleVars[1]);
                
                SIGMA[1]=(doubleVars[0]*SIGMA[1]*SIGMA[1]-2.0*SIGMA[1]*SIGMA[1]*SIGMA[1]+doubleVars[2])/(2.0*doubleVars[0]*SIGMA[1]-3.0*SIGMA[1]*SIGMA[1]+doubleVars[1]);
                SIGMA[1]=(doubleVars[0]*SIGMA[1]*SIGMA[1]-2.0*SIGMA[1]*SIGMA[1]*SIGMA[1]+doubleVars[2])/(2.0*doubleVars[0]*SIGMA[1]-3.0*SIGMA[1]*SIGMA[1]+doubleVars[1]);
                
                /* eigenvalues found, corresponding eigenvectors V[i] ... */
                
                i=2;
                {
                    
                    threei=3*i;
                    
                    invmat[0]=SpxTSpx[2]*SpxTSpx[1]-SpxTSpx[1]*SIGMA[i]-SIGMA[i]*SpxTSpx[2]+SIGMA[i]*SIGMA[i]-SpxTSpx[4]*SpxTSpx[4];
                    invmat[1]=SpxTSpx[4]*SpxTSpx[5]-SpxTSpx[3]*SpxTSpx[2]+SpxTSpx[3]*SIGMA[i];
                    invmat[2]=SpxTSpx[3]*SpxTSpx[4]-SpxTSpx[5]*SpxTSpx[1]+SpxTSpx[5]*SIGMA[i];
                    invmat[3]=SpxTSpx[2]*SpxTSpx[0]-SpxTSpx[0]*SIGMA[i]-SIGMA[i]*SpxTSpx[2]+SIGMA[i]*SIGMA[i]-SpxTSpx[5]*SpxTSpx[5];
                    invmat[4]=-SpxTSpx[4]*SpxTSpx[0]+SpxTSpx[4]*SIGMA[i]+SpxTSpx[3]*SpxTSpx[5];
                    invmat[5]=SpxTSpx[1]*SpxTSpx[0]-SpxTSpx[0]*SIGMA[i]-SpxTSpx[1]*SIGMA[i]+SIGMA[i]*SIGMA[i]-SpxTSpx[3]*SpxTSpx[3];
                    
                    doubleVars[0]=invmat[0]*invmat[0]+invmat[1]*invmat[1]+invmat[2]*invmat[2];
                    doubleVars[1]=invmat[1]*invmat[1]+invmat[3]*invmat[3]+invmat[4]*invmat[4];
                    doubleVars[2]=invmat[2]*invmat[2]+invmat[4]*invmat[4]+invmat[5]*invmat[5];
                    
                    if (doubleVars[0]>doubleVars[1]){
                        if (doubleVars[0]>doubleVars[2]){
                            V[threei]=invmat[0];
                            V[threei+1]=invmat[1];
                            V[threei+2]=invmat[2];
                        }
                        else {
                            V[threei]=invmat[2];
                            V[threei+1]=invmat[4];
                            V[threei+2]=invmat[5];
                        }
                    }
                    else {
                        if (doubleVars[1]>doubleVars[2]){
                            V[threei]=invmat[1];
                            V[threei+1]=invmat[3];
                            V[threei+2]=invmat[4];
                        }
                        else {
                            V[threei]=invmat[2];
                            V[threei+1]=invmat[4];
                            V[threei+2]=invmat[5];
                        }
                    }
                    
                    MM[0]=V[threei];
                    MM[1]=V[threei+1];
                    MM[2]=V[threei+2];
                    
                    V[threei]=invmat[0]*MM[0]+invmat[1]*MM[1]+invmat[2]*MM[2];
                    V[threei+1]=invmat[1]*MM[0]+invmat[3]*MM[1]+invmat[4]*MM[2];
                    V[threei+2]=invmat[2]*MM[0]+invmat[4]*MM[1]+invmat[5]*MM[2];
                    
                    MM[0]=V[threei];
                    MM[1]=V[threei+1];
                    MM[2]=V[threei+2];
                    
                    V[threei]=invmat[0]*MM[0]+invmat[1]*MM[1]+invmat[2]*MM[2];
                    V[threei+1]=invmat[1]*MM[0]+invmat[3]*MM[1]+invmat[4]*MM[2];
                    V[threei+2]=invmat[2]*MM[0]+invmat[4]*MM[1]+invmat[5]*MM[2];
                    
                    MM[0]=V[threei];
                    MM[1]=V[threei+1];
                    MM[2]=V[threei+2];
                    
                    V[threei]=invmat[0]*MM[0]+invmat[1]*MM[1]+invmat[2]*MM[2];
                    V[threei+1]=invmat[1]*MM[0]+invmat[3]*MM[1]+invmat[4]*MM[2];
                    V[threei+2]=invmat[2]*MM[0]+invmat[4]*MM[1]+invmat[5]*MM[2];
                    
                    MM[0]=V[threei];
                    MM[1]=V[threei+1];
                    MM[2]=V[threei+2];
                    
                    V[threei]=invmat[0]*MM[0]+invmat[1]*MM[1]+invmat[2]*MM[2];
                    V[threei+1]=invmat[1]*MM[0]+invmat[3]*MM[1]+invmat[4]*MM[2];
                    V[threei+2]=invmat[2]*MM[0]+invmat[4]*MM[1]+invmat[5]*MM[2];
                    
                    for (j=0;j<3;j++){
                        
                        doubleVars[0]=fabs(V[threei])+fabs(V[threei+1])+fabs(V[threei+2]);
                        V[threei]=V[threei]/doubleVars[0];
                        V[threei+1]=V[threei+1]/doubleVars[0];
                        V[threei+2]=V[threei+2]/doubleVars[0];
                        
                        MM[0]=V[threei];
                        MM[1]=V[threei+1];
                        MM[2]=V[threei+2];
                        
                        V[threei]=invmat[0]*MM[0]+invmat[1]*MM[1]+invmat[2]*MM[2];
                        V[threei+1]=invmat[1]*MM[0]+invmat[3]*MM[1]+invmat[4]*MM[2];
                        V[threei+2]=invmat[2]*MM[0]+invmat[4]*MM[1]+invmat[5]*MM[2];
                        
                        MM[0]=V[threei];
                        MM[1]=V[threei+1];
                        MM[2]=V[threei+2];
                        
                        V[threei]=invmat[0]*MM[0]+invmat[1]*MM[1]+invmat[2]*MM[2];
                        V[threei+1]=invmat[1]*MM[0]+invmat[3]*MM[1]+invmat[4]*MM[2];
                        V[threei+2]=invmat[2]*MM[0]+invmat[4]*MM[1]+invmat[5]*MM[2];
                        
                    }
                    
                    doubleVars[0]=sqrt(V[threei]*V[threei]+V[threei+1]*V[threei+1]+V[threei+2]*V[threei+2]);
                    V[threei]=V[threei]/doubleVars[0];
                    V[threei+1]=V[threei+1]/doubleVars[0];
                    V[threei+2]=V[threei+2]/doubleVars[0];
                    
                }
                
                i=1;
                {
                    
                    threei=3*i;
                    
                    invmat[0]=SpxTSpx[2]*SpxTSpx[1]-SpxTSpx[1]*SIGMA[i]-SIGMA[i]*SpxTSpx[2]+SIGMA[i]*SIGMA[i]-SpxTSpx[4]*SpxTSpx[4];
                    invmat[1]=SpxTSpx[4]*SpxTSpx[5]-SpxTSpx[3]*SpxTSpx[2]+SpxTSpx[3]*SIGMA[i];
                    invmat[2]=SpxTSpx[3]*SpxTSpx[4]-SpxTSpx[5]*SpxTSpx[1]+SpxTSpx[5]*SIGMA[i];
                    invmat[3]=SpxTSpx[2]*SpxTSpx[0]-SpxTSpx[0]*SIGMA[i]-SIGMA[i]*SpxTSpx[2]+SIGMA[i]*SIGMA[i]-SpxTSpx[5]*SpxTSpx[5];
                    invmat[4]=-SpxTSpx[4]*SpxTSpx[0]+SpxTSpx[4]*SIGMA[i]+SpxTSpx[3]*SpxTSpx[5];
                    invmat[5]=SpxTSpx[1]*SpxTSpx[0]-SpxTSpx[0]*SIGMA[i]-SpxTSpx[1]*SIGMA[i]+SIGMA[i]*SIGMA[i]-SpxTSpx[3]*SpxTSpx[3];
                    
                    doubleVars[0]=invmat[0]*invmat[0]+invmat[1]*invmat[1]+invmat[2]*invmat[2];
                    doubleVars[1]=invmat[1]*invmat[1]+invmat[3]*invmat[3]+invmat[4]*invmat[4];
                    doubleVars[2]=invmat[2]*invmat[2]+invmat[4]*invmat[4]+invmat[5]*invmat[5];
                    
                    if (doubleVars[0]>doubleVars[1]){
                        if (doubleVars[0]>doubleVars[2]){
                            V[threei]=invmat[0];
                            V[threei+1]=invmat[1];
                            V[threei+2]=invmat[2];
                        }
                        else {
                            V[threei]=invmat[2];
                            V[threei+1]=invmat[4];
                            V[threei+2]=invmat[5];
                        }
                    }
                    else {
                        if (doubleVars[1]>doubleVars[2]){
                            V[threei]=invmat[1];
                            V[threei+1]=invmat[3];
                            V[threei+2]=invmat[4];
                        }
                        else {
                            V[threei]=invmat[2];
                            V[threei+1]=invmat[4];
                            V[threei+2]=invmat[5];
                        }
                    }
                    
                    MM[0]=V[threei];
                    MM[1]=V[threei+1];
                    MM[2]=V[threei+2];
                    
                    V[threei]=invmat[0]*MM[0]+invmat[1]*MM[1]+invmat[2]*MM[2];
                    V[threei+1]=invmat[1]*MM[0]+invmat[3]*MM[1]+invmat[4]*MM[2];
                    V[threei+2]=invmat[2]*MM[0]+invmat[4]*MM[1]+invmat[5]*MM[2];
                    
                    MM[0]=V[threei];
                    MM[1]=V[threei+1];
                    MM[2]=V[threei+2];
                    
                    V[threei]=invmat[0]*MM[0]+invmat[1]*MM[1]+invmat[2]*MM[2];
                    V[threei+1]=invmat[1]*MM[0]+invmat[3]*MM[1]+invmat[4]*MM[2];
                    V[threei+2]=invmat[2]*MM[0]+invmat[4]*MM[1]+invmat[5]*MM[2];
                    
                    MM[0]=V[threei];
                    MM[1]=V[threei+1];
                    MM[2]=V[threei+2];
                    
                    V[threei]=invmat[0]*MM[0]+invmat[1]*MM[1]+invmat[2]*MM[2];
                    V[threei+1]=invmat[1]*MM[0]+invmat[3]*MM[1]+invmat[4]*MM[2];
                    V[threei+2]=invmat[2]*MM[0]+invmat[4]*MM[1]+invmat[5]*MM[2];
                    
                    MM[0]=V[threei];
                    MM[1]=V[threei+1];
                    MM[2]=V[threei+2];
                    
                    V[threei]=invmat[0]*MM[0]+invmat[1]*MM[1]+invmat[2]*MM[2];
                    V[threei+1]=invmat[1]*MM[0]+invmat[3]*MM[1]+invmat[4]*MM[2];
                    V[threei+2]=invmat[2]*MM[0]+invmat[4]*MM[1]+invmat[5]*MM[2];
                    
                    for (j=0;j<3;j++){
                        
                        doubleVars[0]=fabs(V[threei])+fabs(V[threei+1])+fabs(V[threei+2]);
                        V[threei]=V[threei]/doubleVars[0];
                        V[threei+1]=V[threei+1]/doubleVars[0];
                        V[threei+2]=V[threei+2]/doubleVars[0];
                        
                        MM[0]=V[threei];
                        MM[1]=V[threei+1];
                        MM[2]=V[threei+2];
                        
                        V[threei]=invmat[0]*MM[0]+invmat[1]*MM[1]+invmat[2]*MM[2];
                        V[threei+1]=invmat[1]*MM[0]+invmat[3]*MM[1]+invmat[4]*MM[2];
                        V[threei+2]=invmat[2]*MM[0]+invmat[4]*MM[1]+invmat[5]*MM[2];
                        
                        MM[0]=V[threei];
                        MM[1]=V[threei+1];
                        MM[2]=V[threei+2];
                        
                        V[threei]=invmat[0]*MM[0]+invmat[1]*MM[1]+invmat[2]*MM[2];
                        V[threei+1]=invmat[1]*MM[0]+invmat[3]*MM[1]+invmat[4]*MM[2];
                        V[threei+2]=invmat[2]*MM[0]+invmat[4]*MM[1]+invmat[5]*MM[2];
                        
                    }
                    
                    doubleVars[0]=sqrt(V[threei]*V[threei]+V[threei+1]*V[threei+1]+V[threei+2]*V[threei+2]);
                    V[threei]=V[threei]/doubleVars[0];
                    V[threei+1]=V[threei+1]/doubleVars[0];
                    V[threei+2]=V[threei+2]/doubleVars[0];
                    
                }
                
                doubleVars[0]=V[3]*V[6]+V[4]*V[7]+V[5]*V[8];
                V[3]=V[3]-doubleVars[0]*V[6];
                V[4]=V[4]-doubleVars[0]*V[7];
                V[5]=V[5]-doubleVars[0]*V[8];
                
                doubleVars[0]=sqrt(V[3]*V[3]+V[4]*V[4]+V[5]*V[5]);
                V[3]=V[3]/doubleVars[0];
                V[4]=V[4]/doubleVars[0];
                V[5]=V[5]/doubleVars[0];
                
                V[0]=V[4]*V[8]-V[5]*V[7];
                V[1]=V[5]*V[6]-V[3]*V[8];
                V[2]=V[3]*V[7]-V[4]*V[6];
                
                doubleVars[0]=sqrt(V[0]*V[0]+V[1]*V[1]+V[2]*V[2]);
                V[0]=V[0]/doubleVars[0];
                V[1]=V[1]/doubleVars[0];
                V[2]=V[2]/doubleVars[0];
                
                /* singular values & V[i] of Spx found, U[i] ... */
                
                U[0]=Spx[0]*V[0]+Spx[3]*V[1]+Spx[6]*V[2];
                U[1]=Spx[1]*V[0]+Spx[4]*V[1]+Spx[7]*V[2];
                U[2]=Spx[2]*V[0]+Spx[5]*V[1]+Spx[8]*V[2];
                
                doubleVars[0]=sqrt(U[0]*U[0]+U[1]*U[1]+U[2]*U[2]);
                U[0]=U[0]/doubleVars[0];
                U[1]=U[1]/doubleVars[0];
                U[2]=U[2]/doubleVars[0];
                
                U[3]=Spx[0]*V[3]+Spx[3]*V[4]+Spx[6]*V[5];
                U[4]=Spx[1]*V[3]+Spx[4]*V[4]+Spx[7]*V[5];
                U[5]=Spx[2]*V[3]+Spx[5]*V[4]+Spx[8]*V[5];
                
                doubleVars[0]=U[0]*U[3]+U[1]*U[4]+U[2]*U[5];
                U[3]=U[3]-doubleVars[0]*U[0];
                U[4]=U[4]-doubleVars[0]*U[1];
                U[5]=U[5]-doubleVars[0]*U[2];
                
                doubleVars[0]=sqrt(U[3]*U[3]+U[4]*U[4]+U[5]*U[5]);
                U[3]=U[3]/doubleVars[0];
                U[4]=U[4]/doubleVars[0];
                U[5]=U[5]/doubleVars[0];
                
                U[6]=U[1]*U[5]-U[2]*U[4];
                U[7]=U[2]*U[3]-U[0]*U[5];
                U[8]=U[0]*U[4]-U[1]*U[3];
                
                doubleVars[0]=sqrt(U[6]*U[6]+U[7]*U[7]+U[8]*U[8]);
                U[6]=U[6]/doubleVars[0];
                U[7]=U[7]/doubleVars[0];
                U[8]=U[8]/doubleVars[0];
                
            }
            else {
                
                /* Largest eigenvalue */
                
                /* Newton-Raphson */
                
                SIGMA[0]=doubleVars[0]-(doubleVars[4]+0.6666666666666667*doubleVars[6]*doubleVars[3]/(doubleVars[6]-doubleVars[7]));
                
                for (i=0;i<50;i++){
                    doubleVars[6]=SIGMA[0];
                    SIGMA[0]=(doubleVars[0]*SIGMA[0]*SIGMA[0]-2.0*SIGMA[0]*SIGMA[0]*SIGMA[0]+doubleVars[2])/(2.0*doubleVars[0]*SIGMA[0]-3.0*SIGMA[0]*SIGMA[0]+doubleVars[1]);
                    if (fabs(SIGMA[0]-doubleVars[6])<SIGMA[0]*1.0e-16){
                        break;
                    }
                }
                
                /* The other eigenvalues */
                
                doubleVars[3]=2.0*doubleVars[0]*SIGMA[0]-3.0*SIGMA[0]*SIGMA[0]+doubleVars[0]*doubleVars[0]+4.0*doubleVars[1];
                
                if (doubleVars[3]>0.0){
                    doubleVars[3]=sqrt(doubleVars[3]);
                    SIGMA[1]=(doubleVars[0]-SIGMA[0]+doubleVars[3])/2.0;
                    SIGMA[2]=(doubleVars[0]-SIGMA[0]-doubleVars[3])/2.0;
                }
                else {
                    SIGMA[1]=(doubleVars[0]-SIGMA[0])/2.0;
                    SIGMA[2]=SIGMA[1];
                }
                
                /* To ensure a good numerical solution */
                
                if (1.0e3*doubleVars[3]<SIGMA[0]){
                    rotMatrixCCOVsubrtnII(rotationMatrix, Spx, SIGMA, MM, U, V, SpxTSpx, invmat, doubleVars);
                    return;
                }
                
                /* Improve the other eigenvalues using Newton-Raphson */
                
                SIGMA[1]=(doubleVars[0]*SIGMA[1]*SIGMA[1]-2.0*SIGMA[1]*SIGMA[1]*SIGMA[1]+doubleVars[2])/(2.0*doubleVars[0]*SIGMA[1]-3.0*SIGMA[1]*SIGMA[1]+doubleVars[1]);
                SIGMA[1]=(doubleVars[0]*SIGMA[1]*SIGMA[1]-2.0*SIGMA[1]*SIGMA[1]*SIGMA[1]+doubleVars[2])/(2.0*doubleVars[0]*SIGMA[1]-3.0*SIGMA[1]*SIGMA[1]+doubleVars[1]);
                
                SIGMA[2]=(doubleVars[0]*SIGMA[2]*SIGMA[2]-2.0*SIGMA[2]*SIGMA[2]*SIGMA[2]+doubleVars[2])/(2.0*doubleVars[0]*SIGMA[2]-3.0*SIGMA[2]*SIGMA[2]+doubleVars[1]);
                SIGMA[2]=(doubleVars[0]*SIGMA[2]*SIGMA[2]-2.0*SIGMA[2]*SIGMA[2]*SIGMA[2]+doubleVars[2])/(2.0*doubleVars[0]*SIGMA[2]-3.0*SIGMA[2]*SIGMA[2]+doubleVars[1]);
                
                /* eigenvalues found, corresponding eigenvectors V[i] ... */
                
                for (i=0;i<2;i++){
                    
                    threei=3*i;
                    
                    invmat[0]=SpxTSpx[2]*SpxTSpx[1]-SpxTSpx[1]*SIGMA[i]-SIGMA[i]*SpxTSpx[2]+SIGMA[i]*SIGMA[i]-SpxTSpx[4]*SpxTSpx[4];
                    invmat[1]=SpxTSpx[4]*SpxTSpx[5]-SpxTSpx[3]*SpxTSpx[2]+SpxTSpx[3]*SIGMA[i];
                    invmat[2]=SpxTSpx[3]*SpxTSpx[4]-SpxTSpx[5]*SpxTSpx[1]+SpxTSpx[5]*SIGMA[i];
                    invmat[3]=SpxTSpx[2]*SpxTSpx[0]-SpxTSpx[0]*SIGMA[i]-SIGMA[i]*SpxTSpx[2]+SIGMA[i]*SIGMA[i]-SpxTSpx[5]*SpxTSpx[5];
                    invmat[4]=-SpxTSpx[4]*SpxTSpx[0]+SpxTSpx[4]*SIGMA[i]+SpxTSpx[3]*SpxTSpx[5];
                    invmat[5]=SpxTSpx[1]*SpxTSpx[0]-SpxTSpx[0]*SIGMA[i]-SpxTSpx[1]*SIGMA[i]+SIGMA[i]*SIGMA[i]-SpxTSpx[3]*SpxTSpx[3];
                    
                    doubleVars[0]=invmat[0]*invmat[0]+invmat[1]*invmat[1]+invmat[2]*invmat[2];
                    doubleVars[1]=invmat[1]*invmat[1]+invmat[3]*invmat[3]+invmat[4]*invmat[4];
                    doubleVars[2]=invmat[2]*invmat[2]+invmat[4]*invmat[4]+invmat[5]*invmat[5];
                    
                    if (doubleVars[0]>doubleVars[1]){
                        if (doubleVars[0]>doubleVars[2]){
                            V[threei]=invmat[0];
                            V[threei+1]=invmat[1];
                            V[threei+2]=invmat[2];
                        }
                        else {
                            V[threei]=invmat[2];
                            V[threei+1]=invmat[4];
                            V[threei+2]=invmat[5];
                        }
                    }
                    else {
                        if (doubleVars[1]>doubleVars[2]){
                            V[threei]=invmat[1];
                            V[threei+1]=invmat[3];
                            V[threei+2]=invmat[4];
                        }
                        else {
                            V[threei]=invmat[2];
                            V[threei+1]=invmat[4];
                            V[threei+2]=invmat[5];
                        }
                    }
                    
                    MM[0]=V[threei];
                    MM[1]=V[threei+1];
                    MM[2]=V[threei+2];
                    
                    V[threei]=invmat[0]*MM[0]+invmat[1]*MM[1]+invmat[2]*MM[2];
                    V[threei+1]=invmat[1]*MM[0]+invmat[3]*MM[1]+invmat[4]*MM[2];
                    V[threei+2]=invmat[2]*MM[0]+invmat[4]*MM[1]+invmat[5]*MM[2];
                    
                    MM[0]=V[threei];
                    MM[1]=V[threei+1];
                    MM[2]=V[threei+2];
                    
                    V[threei]=invmat[0]*MM[0]+invmat[1]*MM[1]+invmat[2]*MM[2];
                    V[threei+1]=invmat[1]*MM[0]+invmat[3]*MM[1]+invmat[4]*MM[2];
                    V[threei+2]=invmat[2]*MM[0]+invmat[4]*MM[1]+invmat[5]*MM[2];
                    
                    MM[0]=V[threei];
                    MM[1]=V[threei+1];
                    MM[2]=V[threei+2];
                    
                    V[threei]=invmat[0]*MM[0]+invmat[1]*MM[1]+invmat[2]*MM[2];
                    V[threei+1]=invmat[1]*MM[0]+invmat[3]*MM[1]+invmat[4]*MM[2];
                    V[threei+2]=invmat[2]*MM[0]+invmat[4]*MM[1]+invmat[5]*MM[2];
                    
                    MM[0]=V[threei];
                    MM[1]=V[threei+1];
                    MM[2]=V[threei+2];
                    
                    V[threei]=invmat[0]*MM[0]+invmat[1]*MM[1]+invmat[2]*MM[2];
                    V[threei+1]=invmat[1]*MM[0]+invmat[3]*MM[1]+invmat[4]*MM[2];
                    V[threei+2]=invmat[2]*MM[0]+invmat[4]*MM[1]+invmat[5]*MM[2];
                    
                    for (j=0;j<3;j++){
                        
                        doubleVars[0]=fabs(V[threei])+fabs(V[threei+1])+fabs(V[threei+2]);
                        V[threei]=V[threei]/doubleVars[0];
                        V[threei+1]=V[threei+1]/doubleVars[0];
                        V[threei+2]=V[threei+2]/doubleVars[0];
                        
                        MM[0]=V[threei];
                        MM[1]=V[threei+1];
                        MM[2]=V[threei+2];
                        
                        V[threei]=invmat[0]*MM[0]+invmat[1]*MM[1]+invmat[2]*MM[2];
                        V[threei+1]=invmat[1]*MM[0]+invmat[3]*MM[1]+invmat[4]*MM[2];
                        V[threei+2]=invmat[2]*MM[0]+invmat[4]*MM[1]+invmat[5]*MM[2];
                        
                        MM[0]=V[threei];
                        MM[1]=V[threei+1];
                        MM[2]=V[threei+2];
                        
                        V[threei]=invmat[0]*MM[0]+invmat[1]*MM[1]+invmat[2]*MM[2];
                        V[threei+1]=invmat[1]*MM[0]+invmat[3]*MM[1]+invmat[4]*MM[2];
                        V[threei+2]=invmat[2]*MM[0]+invmat[4]*MM[1]+invmat[5]*MM[2];
                        
                    }
                    
                    doubleVars[0]=sqrt(V[threei]*V[threei]+V[threei+1]*V[threei+1]+V[threei+2]*V[threei+2]);
                    V[threei]=V[threei]/doubleVars[0];
                    V[threei+1]=V[threei+1]/doubleVars[0];
                    V[threei+2]=V[threei+2]/doubleVars[0];
                    
                }
                
                doubleVars[0]=V[0]*V[3]+V[1]*V[4]+V[2]*V[5];
                V[3]=V[3]-doubleVars[0]*V[0];
                V[4]=V[4]-doubleVars[0]*V[1];
                V[5]=V[5]-doubleVars[0]*V[2];
                
                doubleVars[0]=sqrt(V[3]*V[3]+V[4]*V[4]+V[5]*V[5]);
                V[3]=V[3]/doubleVars[0];
                V[4]=V[4]/doubleVars[0];
                V[5]=V[5]/doubleVars[0];
                
                V[6]=V[1]*V[5]-V[2]*V[4];
                V[7]=V[2]*V[3]-V[0]*V[5];
                V[8]=V[0]*V[4]-V[1]*V[3];
                
                doubleVars[0]=sqrt(V[6]*V[6]+V[7]*V[7]+V[8]*V[8]);
                V[6]=V[6]/doubleVars[0];
                V[7]=V[7]/doubleVars[0];
                V[8]=V[8]/doubleVars[0];
                
                /* singular values & V[i] of Spx found, U[i] ... */
                
                U[0]=Spx[0]*V[0]+Spx[3]*V[1]+Spx[6]*V[2];
                U[1]=Spx[1]*V[0]+Spx[4]*V[1]+Spx[7]*V[2];
                U[2]=Spx[2]*V[0]+Spx[5]*V[1]+Spx[8]*V[2];
                
                doubleVars[0]=sqrt(U[0]*U[0]+U[1]*U[1]+U[2]*U[2]);
                U[0]=U[0]/doubleVars[0];
                U[1]=U[1]/doubleVars[0];
                U[2]=U[2]/doubleVars[0];
                
                U[3]=Spx[0]*V[3]+Spx[3]*V[4]+Spx[6]*V[5];
                U[4]=Spx[1]*V[3]+Spx[4]*V[4]+Spx[7]*V[5];
                U[5]=Spx[2]*V[3]+Spx[5]*V[4]+Spx[8]*V[5];
                
                doubleVars[0]=U[0]*U[3]+U[1]*U[4]+U[2]*U[5];
                U[3]=U[3]-doubleVars[0]*U[0];
                U[4]=U[4]-doubleVars[0]*U[1];
                U[5]=U[5]-doubleVars[0]*U[2];
                
                doubleVars[0]=sqrt(U[3]*U[3]+U[4]*U[4]+U[5]*U[5]);
                U[3]=U[3]/doubleVars[0];
                U[4]=U[4]/doubleVars[0];
                U[5]=U[5]/doubleVars[0];
                
                U[6]=U[1]*U[5]-U[2]*U[4];
                U[7]=U[2]*U[3]-U[0]*U[5];
                U[8]=U[0]*U[4]-U[1]*U[3];
                
                doubleVars[0]=sqrt(U[6]*U[6]+U[7]*U[7]+U[8]*U[8]);
                U[6]=U[6]/doubleVars[0];
                U[7]=U[7]/doubleVars[0];
                U[8]=U[8]/doubleVars[0];
                
            }
            
            j=0;
            if ((Spx[0]*V[0]+Spx[3]*V[1]+Spx[6]*V[2])*U[0]+(Spx[1]*V[0]+Spx[4]*V[1]+Spx[7]*V[2])*U[1]+(Spx[2]*V[0]+Spx[5]*V[1]+Spx[8]*V[2])*U[2]<0.0){
                j++;
                U[0]=-U[0];
                U[1]=-U[1];
                U[2]=-U[2];
            }
            if ((Spx[0]*V[3]+Spx[3]*V[4]+Spx[6]*V[5])*U[3]+(Spx[1]*V[3]+Spx[4]*V[4]+Spx[7]*V[5])*U[4]+(Spx[2]*V[3]+Spx[5]*V[4]+Spx[8]*V[5])*U[5]<0.0){
                j++;
                U[3]=-U[3];
                U[4]=-U[4];
                U[5]=-U[5];
            }
            if ((Spx[0]*V[6]+Spx[3]*V[7]+Spx[6]*V[8])*U[6]+(Spx[1]*V[6]+Spx[4]*V[7]+Spx[7]*V[8])*U[7]+(Spx[2]*V[6]+Spx[5]*V[7]+Spx[8]*V[8])*U[8]<0.0){
                j++;
                U[6]=-U[6];
                U[7]=-U[7];
                U[8]=-U[8];
            }
            
            /* R=U*V' */
            
            if (j==0){
                rotationMatrix[0]=U[0]*V[0]+U[3]*V[3]+U[6]*V[6];
                rotationMatrix[1]=U[1]*V[0]+U[4]*V[3]+U[7]*V[6];
                rotationMatrix[2]=U[2]*V[0]+U[5]*V[3]+U[8]*V[6];
                
                rotationMatrix[3]=U[0]*V[1]+U[3]*V[4]+U[6]*V[7];
                rotationMatrix[4]=U[1]*V[1]+U[4]*V[4]+U[7]*V[7];
                rotationMatrix[5]=U[2]*V[1]+U[5]*V[4]+U[8]*V[7];
                
                rotationMatrix[6]=U[0]*V[2]+U[3]*V[5]+U[6]*V[8];
                rotationMatrix[7]=U[1]*V[2]+U[4]*V[5]+U[7]*V[8];
                rotationMatrix[8]=U[2]*V[2]+U[5]*V[5]+U[8]*V[8];
            }
            else if (j==2){
                rotationMatrix[0]=U[0]*V[0]+U[3]*V[3]+U[6]*V[6];
                rotationMatrix[1]=U[1]*V[0]+U[4]*V[3]+U[7]*V[6];
                rotationMatrix[2]=U[2]*V[0]+U[5]*V[3]+U[8]*V[6];
                
                rotationMatrix[3]=U[0]*V[1]+U[3]*V[4]+U[6]*V[7];
                rotationMatrix[4]=U[1]*V[1]+U[4]*V[4]+U[7]*V[7];
                rotationMatrix[5]=U[2]*V[1]+U[5]*V[4]+U[8]*V[7];
                
                rotationMatrix[6]=U[0]*V[2]+U[3]*V[5]+U[6]*V[8];
                rotationMatrix[7]=U[1]*V[2]+U[4]*V[5]+U[7]*V[8];
                rotationMatrix[8]=U[2]*V[2]+U[5]*V[5]+U[8]*V[8];
            }
            else {
                rotationMatrix[0]=U[0]*V[0]+U[3]*V[3]-U[6]*V[6];
                rotationMatrix[1]=U[1]*V[0]+U[4]*V[3]-U[7]*V[6];
                rotationMatrix[2]=U[2]*V[0]+U[5]*V[3]-U[8]*V[6];
                
                rotationMatrix[3]=U[0]*V[1]+U[3]*V[4]-U[6]*V[7];
                rotationMatrix[4]=U[1]*V[1]+U[4]*V[4]-U[7]*V[7];
                rotationMatrix[5]=U[2]*V[1]+U[5]*V[4]-U[8]*V[7];
                
                rotationMatrix[6]=U[0]*V[2]+U[3]*V[5]-U[6]*V[8];
                rotationMatrix[7]=U[1]*V[2]+U[4]*V[5]-U[7]*V[8];
                rotationMatrix[8]=U[2]*V[2]+U[5]*V[5]-U[8]*V[8];
            }
            
        }
        
    }
    
    return;
    
}

static void rotMatrixCCOV(double *rotationMatrix, double *Spx, double *SIGMA, double *MM, double *doubleVars){
    
    /* Computes a rotation matrix R that maximizes trace(R*Spx). *
     * R,Spx are 3x3 matrices.                                   */
    
    rotMatrixCCOVsubrtn(rotationMatrix, Spx, SIGMA, MM, doubleVars, &doubleVars[9], &doubleVars[18], &doubleVars[24], &doubleVars[30]);
    
    return;
    
}
