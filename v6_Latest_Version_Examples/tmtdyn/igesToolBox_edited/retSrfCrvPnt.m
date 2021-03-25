function [P,isSCP,isSup,TRI,UV,srfind]=retSrfCrvPnt(SCP,ParameterData,isSup,ind,n,dim)
% RETSRFCRVPNT is a subfunction in IGES2MATLAB file collection.
% No complete documentation is given
%
% SCP - 1, surface
%     - 2, curve
%     - 3, point
%
% ParameterData - Parameter data from IGES file
%
% isSup - 1, if superior then return isSup=1
%       - 0, isSup=0 (always)
%
% ind - index
%
% n - number of points for curves, n^2 number of poinst for non trimmed surface
%
% dim - [2,3] 2, curve in domain, 3, curve in space
%
% m-file can be downloaded at
% http://www.mathworks.com/matlabcentral/fileexchange/13253-iges-toolbox
%
% written by Per Bergström 2015-09-22
%

warn=warning;
warning('off','all');

isSCP=0;

if SCP==1           % SURFACE
    
    if ParameterData{ind}.type==128
        
        isSCP=1;
        srfind=ind;
        
        if and(isSup,ParameterData{ind}.superior)
            P=zeros(3,0);
            TRI=zeros(0,3);
            UV=zeros(2,0);
        else
            
            isSup=0;
            
            if nargin==6
                if dim==3
                    nu=min(max(ceil(300*ParameterData{ind}.ratio(1)),160),1600);
                    nv=min(max(ceil(300*ParameterData{ind}.ratio(2)),160),1600);
                elseif dim==2
                    nu=min(max(ceil(200*ParameterData{ind}.ratio(1)),80),800);
                    nv=min(max(ceil(200*ParameterData{ind}.ratio(2)),80),800);
                elseif dim==1
                    nu=min(max(ceil(150*ParameterData{ind}.ratio(1)),40),400);
                    nv=min(max(ceil(150*ParameterData{ind}.ratio(2)),40),400);
                else
                    nu=min(max(ceil(80*ParameterData{ind}.ratio(1)),20),200);
                    nv=min(max(ceil(80*ParameterData{ind}.ratio(2)),20),200);
                end
            else
                nu=min(max(ceil(80*ParameterData{ind}.ratio(1)),20),200);
                nv=min(max(ceil(80*ParameterData{ind}.ratio(2)),20),200);
            end
            
            [P,UV,TRI]=nrbSrfRegularEvalIGES(ParameterData{ind}.nurbs,ParameterData{ind}.u(1),ParameterData{ind}.u(2),nu,ParameterData{ind}.v(1),ParameterData{ind}.v(2),nv);
            
        end
        
    elseif ParameterData{ind}.type==144
        
        srfind=ParameterData{ind}.pts;
        
        if ParameterData{srfind}.type==128
            
            isSCP=1;
            isSup=0;
            
            if ParameterData{ind}.trimmed
                
                n2=ParameterData{ind}.n2;
                NN=ones(1,n2+1);
                
                if nargin==6
                    if dim==3
                        scl=700;
                        minNumPscl=35;
                    elseif dim==2
                        scl=360;
                        minNumPscl=25;
                    elseif dim==1
                        scl=180;
                        minNumPscl=15;
                    else
                        scl=90;
                        minNumPscl=8;
                    end
                else
                    scl=90;
                    minNumPscl=8;
                end
                
                if ParameterData{ind}.n1
                    minNumP=minNumPscl*ParameterData{ParameterData{ind}.pto}.numcrv;
                    NO=max(ceil((ParameterData{ParameterData{ind}.pto}.length/ParameterData{ParameterData{ind}.pto}.mlcrv)*scl),minNumP);
                    NN(1)=NO;
                    for j=1:n2
                        minNumP=minNumPscl*ParameterData{ParameterData{ind}.pti(j)}.numcrv;
                        NN(j+1)=max(ceil((ParameterData{ParameterData{ind}.pti(j)}.length/ParameterData{ParameterData{ind}.pti(j)}.mlcrv)*scl),minNumP);
                    end
                else
                    nO=max(ceil(100*ParameterData{ind}.ratio(1))+ceil(100*ParameterData{ind}.ratio(2)),80);
                    NO=4*nO;
                    NN(1)=NO;
                    for j=1:n2
                        minNumP=minNumPscl*ParameterData{ParameterData{ind}.pti(j)}.numcrv;
                        NN(j+1)=max(ceil((ParameterData{ParameterData{ind}.pti(j)}.length/ParameterData{ParameterData{ind}.pti(j)}.mlcrv)*scl),minNumP);
                    end
                end
                
                NN=cumsum(NN);
                numP=NN(end);
                
                UV=zeros(2,numP);
                
                if ParameterData{ind}.n1
                    UV(:,1:NO)=retUVCrv(srfind,ParameterData,ParameterData{ind}.pto,NO,minNumPscl);
                else
                    UV(:,1:nO)=crvPntsSrfNURBS(nO,ParameterData{srfind}.nurbs,[ParameterData{srfind}.u(1);ParameterData{srfind}.v(1)],[ParameterData{srfind}.u(2);ParameterData{srfind}.v(1)],0);
                    UV(:,(nO+1):(2*nO))=crvPntsSrfNURBS(nO,ParameterData{srfind}.nurbs,[ParameterData{srfind}.u(2);ParameterData{srfind}.v(1)],[ParameterData{srfind}.u(2);ParameterData{srfind}.v(2)],0);
                    UV(:,(2*nO+1):(3*nO))=crvPntsSrfNURBS(nO,ParameterData{srfind}.nurbs,[ParameterData{srfind}.u(2);ParameterData{srfind}.v(2)],[ParameterData{srfind}.u(1);ParameterData{srfind}.v(2)],0);
                    UV(:,(3*nO+1):(4*nO))=crvPntsSrfNURBS(nO,ParameterData{srfind}.nurbs,[ParameterData{srfind}.u(1);ParameterData{srfind}.v(2)],[ParameterData{srfind}.u(1);ParameterData{srfind}.v(1)],0);
                end
                
                for j=1:n2
                    UV(:,(NN(j)+1):NN(j+1))=retUVCrv(srfind,ParameterData,ParameterData{ind}.pti(j),(NN(j+1)-NN(j)),minNumPscl);
                end
                
                uscale=ParameterData{srfind}.ratio(1)/(ParameterData{srfind}.u(2)-ParameterData{srfind}.u(1));
                vscale=ParameterData{srfind}.ratio(2)/(ParameterData{srfind}.v(2)-ParameterData{srfind}.v(1));
                
                UV(1,:)=uscale*UV(1,:);
                UV(2,:)=vscale*UV(2,:);
                
                umin=min(UV(1,:));
                umax=max(UV(1,:));
                
                vmin=min(UV(2,:));
                vmax=max(UV(2,:));
                
                udiff=umax-umin;
                vdiff=vmax-vmin;
                
                if or(udiff>75*vdiff,vdiff>75*udiff)
                    
                    Constraints=zeros(numP,2);
                    Constraints(:,1)=(1:numP)';
                    Constraints(:,2)=(2:(numP+1))';
                    
                    Constraints(NN(1),2)=1;
                    for i=2:(1+n2)
                        Constraints(NN(i),2)=NN(i-1)+1;
                    end
                    
                    DT = delaunayTriangulation(UV',Constraints);
                    
                    if size(DT.Points,1)>size(UV,2)
                        UV=DT.Points';
                    end
                    
                    TRI=DT.ConnectivityList(isInterior(DT),:);
                    
                else
                    
                    if ParameterData{srfind}.isplane
                        
                        [UV,TRI] = trimesh(UV,NN);
                        
                    else
                        
                        meshIters=1;
                        
                        nu=max(ceil(udiff*0.3*NN(1)/(udiff+vdiff)),2);
                        nv=max(ceil(vdiff*0.3*NN(1)/(udiff+vdiff)),2);
                        
                        [UV,TRI] = trimeshRegular(UV,NN,meshIters,nu,nv,umin,umax,vmin,vmax);
                        
                    end
                    
                end
                
                UV(1,:)=UV(1,:)/uscale;
                UV(2,:)=UV(2,:)/vscale;
                
                P=nrbevalIGES(ParameterData{srfind}.nurbs,UV);
                
            elseif ParameterData{ind}.well
                
                if nargin==6
                    if dim==3
                        if ParameterData{ind}.ulinear
                            nu=2;
                            nv=max(ceil(300*ParameterData{ind}.ratio(2)),120);
                        elseif ParameterData{ind}.vlinear
                            nu=max(ceil(300*ParameterData{ind}.ratio(1)),120);
                            nv=2;
                        else
                            nu=max(ceil(300*ParameterData{ind}.ratio(1)),120);
                            nv=max(ceil(300*ParameterData{ind}.ratio(2)),120);
                        end
                    elseif dim==2
                        if ParameterData{ind}.ulinear
                            nu=2;
                            nv=max(ceil(200*ParameterData{ind}.ratio(2)),80);
                        elseif ParameterData{ind}.vlinear
                            nu=max(ceil(200*ParameterData{ind}.ratio(1)),80);
                            nv=2;
                        else
                            nu=max(ceil(200*ParameterData{ind}.ratio(1)),80);
                            nv=max(ceil(200*ParameterData{ind}.ratio(2)),80);
                        end
                    elseif dim==1
                        if ParameterData{ind}.ulinear
                            nu=2;
                            nv=max(ceil(100*ParameterData{ind}.ratio(2)),40);
                        elseif ParameterData{ind}.vlinear
                            nu=max(ceil(100*ParameterData{ind}.ratio(1)),40);
                            nv=2;
                        else
                            nu=max(ceil(100*ParameterData{ind}.ratio(1)),40);
                            nv=max(ceil(100*ParameterData{ind}.ratio(2)),40);
                        end
                    else
                        if ParameterData{ind}.ulinear
                            nu=2;
                            nv=max(ceil(50*ParameterData{ind}.ratio(2)),20);
                        elseif ParameterData{ind}.vlinear
                            nu=max(ceil(50*ParameterData{ind}.ratio(1)),20);
                            nv=2;
                        else
                            nu=max(ceil(50*ParameterData{ind}.ratio(1)),20);
                            nv=max(ceil(50*ParameterData{ind}.ratio(2)),20);
                        end
                    end
                else
                    if ParameterData{ind}.ulinear
                        nu=2;
                        nv=max(ceil(50*ParameterData{ind}.ratio(2)),20);
                    elseif ParameterData{ind}.vlinear
                        nu=max(ceil(50*ParameterData{ind}.ratio(1)),20);
                        nv=2;
                    else
                        nu=max(ceil(50*ParameterData{ind}.ratio(1)),20);
                        nv=max(ceil(50*ParameterData{ind}.ratio(2)),20);
                    end
                end
                
                [P,UV,TRI]=nrbSrfRegularEvalIGES(ParameterData{srfind}.nurbs,ParameterData{ind}.u(1),ParameterData{ind}.u(2),nu,ParameterData{ind}.v(1),ParameterData{ind}.v(2),nv);
                
            else
                isSup=1;
                P=zeros(3,0);
                TRI=zeros(0,3);
                UV=zeros(2,0);
                srfind=0;
            end
            
        elseif ParameterData{srfind}.type==108
            
            nrml=[ParameterData{srfind}.a ParameterData{srfind}.b ParameterData{srfind}.c];
            
            nrmlVecAdd=(ParameterData{srfind}.d/dot(nrml,nrml))*nrml;
            
            nusp=null(nrml);
            
            isSCP=1;
            isSup=0;
            
            n2=ParameterData{ind}.n2;
            
            if nargin==6
                if dim==3
                    scl=700;
                    minNumPscl=35;
                elseif dim==2
                    scl=360;
                    minNumPscl=25;
                elseif dim==1
                    scl=180;
                    minNumPscl=15;
                else
                    scl=90;
                    minNumPscl=8;
                end
            else
                scl=90;
                minNumPscl=8;
            end
            
            if n2==0
                
                crvInd=ParameterData{ParameterData{ind}.pto}.cptr;
                
                if ParameterData{crvInd}.type==102
                    if ParameterData{crvInd}.allLines
                        NN=ParameterData{crvInd}.n;
                        P=zeros(3,NN);
                        for j=1:NN
                            P(:,j)=ParameterData{ParameterData{crvInd}.de(j)}.p1;
                        end
                    else
                        numC=ParameterData{crvInd}.n;
                        numPvec=max(ceil(scl*(ParameterData{crvInd}.lengthcnt)/(ParameterData{ParameterData{ind}.pto}.mlcrv)),minNumPscl*ParameterData{crvInd}.numcrvcnt);
                        for j=1:numC
                            if ParameterData{ParameterData{crvInd}.de(j)}.type==110
                                numPvec(j)=1;
                            end
                        end
                        numPvec=cumsum(numPvec);
                        NN=numPvec(numC);
                        P=zeros(3,NN);
                        if ParameterData{ParameterData{crvInd}.de(1)}.type==110
                            P(:,1)=ParameterData{ParameterData{crvInd}.de(1)}.p1;
                        elseif ParameterData{ParameterData{crvInd}.de(1)}.type==126
                            [~,P(:,1:numPvec(1))]=crvPntsSrfNURBS(numPvec(1),ParameterData{ParameterData{crvInd}.de(1)}.nurbs,ParameterData{ParameterData{crvInd}.de(1)}.v(1),ParameterData{ParameterData{crvInd}.de(1)}.v(2),ParameterData{ParameterData{crvInd}.de(1)}.evalmthd);
                        else
                            P(:,1:numPvec(1))=ret3Crv(ParameterData,ParameterData{crvInd}.de(1),numPvec(1));
                        end
                        for j=2:numC
                            if ParameterData{ParameterData{crvInd}.de(j)}.type==110
                                P(:,numPvec(j-1)+1)=ParameterData{ParameterData{crvInd}.de(j)}.p1;
                            elseif ParameterData{ParameterData{crvInd}.de(j)}.type==126
                                [~,P(:,(numPvec(j-1)+1):numPvec(j))]=crvPntsSrfNURBS(numPvec(j)-numPvec(j-1),ParameterData{ParameterData{crvInd}.de(j)}.nurbs,ParameterData{ParameterData{crvInd}.de(j)}.v(1),ParameterData{ParameterData{crvInd}.de(j)}.v(2),ParameterData{ParameterData{crvInd}.de(j)}.evalmthd);
                            else
                                P(:,(numPvec(j-1)+1):numPvec(j))=ret3Crv(ParameterData,ParameterData{crvInd}.de(j),numPvec(j)-numPvec(j-1));
                            end
                        end
                    end
                else
                    minNumP=minNumPscl*ParameterData{crvInd}.numcrv;
                    NN=max(ceil(scl*ParameterData{crvInd}.length/(ParameterData{ParameterData{ind}.pto}.mlcrv)),minNumP);
                    P=ret3Crv(ParameterData,crvInd,NN);
                end
                
                UV=nusp'*P;
                
                DT = delaunayTriangulation(UV',[1:NN;2:NN,1]');
                
                if size(DT.Points,1)>size(UV,2)
                    UV=DT.Points';
                    P=nusp*UV;
                    P(1,:)=P(1,:)+nrmlVecAdd(1);
                    P(2,:)=P(2,:)+nrmlVecAdd(2);
                    P(3,:)=P(3,:)+nrmlVecAdd(3);
                end
                
                TRI=DT.ConnectivityList(isInterior(DT),:);
                
            else
                
                P=zeros(3,0);
                NN=zeros(1,1+n2);
                
                for i=1:(1+n2)
                    if i==1
                        crvInd=ParameterData{ParameterData{ind}.pto}.cptr;
                    else
                        crvInd=ParameterData{ParameterData{ind}.pti(i-1)}.cptr;
                    end
                    
                    if ParameterData{crvInd}.type==102
                        if ParameterData{crvInd}.allLines
                            NN(i)=ParameterData{crvInd}.n;
                            Ptmp=zeros(3,NN(i));
                            for j=1:NN(i)
                                Ptmp(:,j)=ParameterData{ParameterData{crvInd}.de(j)}.p1;
                            end
                        else
                            numC=ParameterData{crvInd}.n;
                            numPvec=max(ceil(scl*(ParameterData{crvInd}.lengthcnt)/(ParameterData{ParameterData{ind}.pto}.mlcrv)),minNumPscl*ParameterData{crvInd}.numcrvcnt);
                            for j=1:numC
                                if ParameterData{ParameterData{crvInd}.de(j)}.type==110
                                    numPvec(j)=1;
                                end
                            end
                            numPvec=cumsum(numPvec);
                            NN(i)=numPvec(numC);
                            Ptmp=zeros(3,NN(i));
                            
                            if ParameterData{ParameterData{crvInd}.de(1)}.type==110
                                Ptmp(:,1)=ParameterData{ParameterData{crvInd}.de(1)}.p1;
                            elseif ParameterData{ParameterData{crvInd}.de(1)}.type==126
                                [~,Ptmp(:,1:numPvec(1))]=crvPntsSrfNURBS(numPvec(1),ParameterData{ParameterData{crvInd}.de(1)}.nurbs,ParameterData{ParameterData{crvInd}.de(1)}.v(1),ParameterData{ParameterData{crvInd}.de(1)}.v(2),ParameterData{ParameterData{crvInd}.de(1)}.evalmthd);
                            else
                                Ptmp(:,1:numPvec(1))=ret3Crv(ParameterData,ParameterData{crvInd}.de(1),numPvec(1));
                            end
                            for j=2:numC
                                if ParameterData{ParameterData{crvInd}.de(j)}.type==110
                                    Ptmp(:,numPvec(j-1)+1)=ParameterData{ParameterData{crvInd}.de(j)}.p1;
                                elseif ParameterData{ParameterData{crvInd}.de(j)}.type==126
                                    [~,Ptmp(:,(numPvec(j-1)+1):numPvec(j))]=crvPntsSrfNURBS(numPvec(j)-numPvec(j-1),ParameterData{ParameterData{crvInd}.de(j)}.nurbs,ParameterData{ParameterData{crvInd}.de(j)}.v(1),ParameterData{ParameterData{crvInd}.de(j)}.v(2),ParameterData{ParameterData{crvInd}.de(j)}.evalmthd);
                                else
                                    Ptmp(:,(numPvec(j-1)+1):numPvec(j))=ret3Crv(ParameterData,ParameterData{crvInd}.de(j),numPvec(j)-numPvec(j-1));
                                end
                            end
                        end
                    else
                        minNumP=minNumPscl*ParameterData{crvInd}.numcrv;
                        NN(i)=max(ceil(scl*ParameterData{crvInd}.length/(ParameterData{ParameterData{ind}.pto}.mlcrv)),minNumP);
                        Ptmp=ret3Crv(ParameterData,crvInd,NN(i));
                    end
                    P=[P,Ptmp];
                end
                
                UV=nusp'*P;
                
                NN=cumsum(NN);
                
                numP=NN(end);
                Constraints=zeros(numP,2);
                Constraints(:,1)=(1:numP)';
                Constraints(:,2)=(2:(numP+1))';
                
                Constraints(NN(1),2)=1;
                for i=2:(1+n2)
                    Constraints(NN(i),2)=NN(i-1)+1;
                end
                
                DT = delaunayTriangulation(UV',Constraints);
                
                if size(DT.Points,1)>size(UV,2)
                    UV=DT.Points';
                    P=nusp*UV;
                    P(1,:)=P(1,:)+nrmlVecAdd(1);
                    P(2,:)=P(2,:)+nrmlVecAdd(2);
                    P(3,:)=P(3,:)+nrmlVecAdd(3);
                end
                
                TRI=DT.ConnectivityList(isInterior(DT),:);
                
            end
            
        else
            P=zeros(3,0);
            isSCP=0;
            isSup=1;
            TRI=zeros(0,3);
            UV=zeros(2,0);
            srfind=0;
        end
        
    elseif ParameterData{ind}.type==143
        
        srfind=ParameterData{ind}.sptr;
        
        if and(ParameterData{srfind}.type==128,ParameterData{ind}.well)
            
            isSCP=1;
            isSup=0;
            
            n=ParameterData{ind}.n;
            NN=ones(1,n);
            
            if nargin==6
                if dim==3
                    scl=700;
                    minNumPscl=35;
                elseif dim==2
                    scl=360;
                    minNumPscl=25;
                elseif dim==1
                    scl=180;
                    minNumPscl=15;
                else
                    scl=90;
                    minNumPscl=8;
                end
            else
                scl=90;
                minNumPscl=8;
            end
            
            for j=1:n
                minNumP=minNumPscl*ParameterData{ParameterData{ind}.bdpt(j)}.numcrv;
                NN(j)=max(ceil((ParameterData{ParameterData{ind}.bdpt(j)}.length/ParameterData{ind}.mlcrv)*scl),minNumP);
            end
            
            NNp=NN;
            NN=cumsum(NN);
            numP=NN(end);
            
            UV=zeros(2,numP);
            
            UV(:,1:NN(1))=retUVCrv(srfind,ParameterData,ParameterData{ind}.bdpt(1),NNp(1),minNumPscl);
            for j=2:n
                UV(:,(NN(j-1)+1):NN(j))=retUVCrv(srfind,ParameterData,ParameterData{ind}.bdpt(j),NNp(j),minNumPscl);
            end
            
            uscale=ParameterData{srfind}.ratio(1)/(ParameterData{srfind}.u(2)-ParameterData{srfind}.u(1));
            vscale=ParameterData{srfind}.ratio(2)/(ParameterData{srfind}.v(2)-ParameterData{srfind}.v(1));
            
            UV(1,:)=uscale*UV(1,:);
            UV(2,:)=vscale*UV(2,:);
            
            umin=min(UV(1,:));
            umax=max(UV(1,:));
            
            vmin=min(UV(2,:));
            vmax=max(UV(2,:));
            
            udiff=umax-umin;
            vdiff=vmax-vmin;
            
            if or(udiff>75*vdiff,vdiff>75*udiff)
                
                Constraints=zeros(numP,2);
                Constraints(:,1)=(1:numP)';
                Constraints(:,2)=(2:(numP+1))';
                
                Constraints(NN(1),2)=1;
                for i=2:n
                    Constraints(NN(i),2)=NN(i-1)+1;
                end
                
                DT = delaunayTriangulation(UV',Constraints);
                
                if size(DT.Points,1)>size(UV,2)
                    UV=DT.Points';
                end
                
                TRI=DT.ConnectivityList(isInterior(DT),:);
                
            else
                
                if ParameterData{srfind}.isplane
                    
                    [UV,TRI] = trimesh(UV,NN);
                    
                else
                    
                    meshIters=1;
                    
                    nu=max(ceil(udiff*0.3*NN(1)/(udiff+vdiff)),2);
                    nv=max(ceil(vdiff*0.3*NN(1)/(udiff+vdiff)),2);
                    
                    [UV,TRI] = trimeshRegular(UV,NN,meshIters,nu,nv,umin,umax,vmin,vmax);
                    
                end
                
            end
            
            UV(1,:)=UV(1,:)/uscale;
            UV(2,:)=UV(2,:)/vscale;
            
            P=nrbevalIGES(ParameterData{srfind}.nurbs,UV);
            
        else
            
            P=zeros(3,0);
            isSCP=0;
            isSup=1;
            TRI=zeros(0,3);
            UV=zeros(2,0);
            srfind=0;
            
        end
        
    else
        
        P=zeros(3,0);
        isSCP=0;
        isSup=1;
        TRI=zeros(0,3);
        UV=zeros(2,0);
        srfind=0;
        
    end
    
elseif SCP==2       % CURVE
    
    if isSup
        
        if ParameterData{ind}.type==110
            
            isSCP=1;
            
            if ParameterData{ind}.superior
                P=zeros(dim,0);
                TRI=0;
            else
                P=zeros(dim,n);
                
                tvec=linspace(0,1,n);
                
                P(1,:)=ParameterData{ind}.x1+tvec*(ParameterData{ind}.x2-ParameterData{ind}.x1);
                P(2,:)=ParameterData{ind}.y1+tvec*(ParameterData{ind}.y2-ParameterData{ind}.y1);
                
                if dim>2
                    P(3,:)=ParameterData{ind}.z1+tvec*(ParameterData{ind}.z2-ParameterData{ind}.z1);
                end
                
                isSup=0;
                TRI=0;
            end
            
        elseif ParameterData{ind}.type==126
            
            isSCP=1;
            
            if ParameterData{ind}.superior
                P=zeros(dim,0);
                TRI=0;
            else
                tst=ParameterData{ind}.v(1);
                ten=ParameterData{ind}.v(2);
                
                tvec=linspace(tst,ten,n);
                
                if dim==3
                    P=nrbevalIGES(ParameterData{ind}.nurbs,tvec);
                else
                    P3=nrbevalIGES(ParameterData{ind}.nurbs,tvec);
                    P=P3(1:dim,:);
                end
                isSup=0;
                TRI=0;
            end
        else
            P=zeros(dim,0);
            isSup=1;
            TRI=0;
        end
        
        UV=0;
        
    else
        
        if any(ParameterData{ind}.type==[102 110 126 141 142])
            
            if nargout>3
                [P,TRI,UV]=retCrv(ParameterData,ind,n,dim);
            elseif nargin==6
                if dim<1
                    P=retSpaceCrv(ParameterData,ind,n);
                elseif dim==2
                    P=ret2Crv(ParameterData,ind,n);
                elseif dim==22
                    P=ret2CrvII(ParameterData,ind,n);
                else
                    P=ret3Crv(ParameterData,ind,n);
                end
                TRI=0;
                UV=0;
            else
                P=ret3Crv(ParameterData,ind,n);
                TRI=0;
                UV=0;
            end
            
            if not(isempty(P))
                isSCP=1;
            end
            
        else
            P=zeros(3,0);
            isSup=1;
            TRI=0;
        end
        
    end
    
    srfind=0;
    
elseif SCP==3       % POINT
    
    if ParameterData{ind}.type==116
        P=ParameterData{ind}.p;
        isSCP=1;
        isSup=0;
        TRI=0;
    else
        P=zeros(3,1);
        isSCP=0;
        isSup=1;
        TRI=0;
    end
    
    UV=0;
    srfind=0;
    
end

warning(warn(1).state);


function [rCrv,crvind,crvindred]=retCrv(ParameterData,ind,n,dim)

if ParameterData{ind}.type==142
    
    if nargout>1
        [rCrv,crvind,crvindred]=retCrv(ParameterData,ParameterData{ind}.bptr,n,dim);
    else
        rCrv=retCrv(ParameterData,ParameterData{ind}.bptr,n,dim);
    end
    
elseif ParameterData{ind}.type==141
    
    nvecF=(n/(ParameterData{ind}.length))*(ParameterData{ind}.psclength);
    nvecI=allocateNumCrvParams(nvecF,n);
    
    rCrv=zeros(dim,n);
    
    if nargout==1
        
        stind=0;
        for i=1:ParameterData{ind}.n
            if nvecI(i)>0
                nvecI2=allocateNumCrvParams((nvecI(i)/ParameterData{ind}.psclength(i))*ParameterData{ind}.pscclctnlength{i},nvecI(i));
                for j=1:ParameterData{ind}.k(i)
                    if nvecI2(j)>0
                        endind=stind+nvecI2(j);
                        rCrv(:,(stind+1):endind)=retCrv(ParameterData,ParameterData{ind}.pscpt{i}(j),nvecI2(j),dim);
                        stind=endind;
                    end
                end
            end
        end
        
    else
        
        crvind=zeros(1,n);
        crvindred=zeros(1,0);
        
        stind=0;
        for i=1:ParameterData{ind}.n
            if nvecI(i)>0
                nvecI2=allocateNumCrvParams((nvecI(i)/ParameterData{ind}.psclength(i))*ParameterData{ind}.pscclctnlength{i},nvecI(i));
                for j=1:ParameterData{ind}.k(i)
                    if nvecI2(j)>0
                        crvindred=[crvindred,ParameterData{ind}.pscpt{i}(j)];
                        endind=stind+nvecI2(j);
                        rCrv(:,(stind+1):endind)=retCrv(ParameterData,ParameterData{ind}.pscpt{i}(j),nvecI2(j),dim);
                        crvind((stind+1):endind)=ParameterData{ind}.pscpt{i}(j);
                        stind=endind;
                    end
                end
            end
        end
        
    end
    
elseif ParameterData{ind}.type==102
    
    nvecF=(n/(ParameterData{ind}.length))*(ParameterData{ind}.lengthcnt);
    nvecI=allocateNumCrvParams(nvecF,n);
    
    rCrv=zeros(dim,n);
    
    if nargout==1
        
        stind=1;
        for i=1:(ParameterData{ind}.n)
            if nvecI(i)>0
                endind=stind+nvecI(i)-1;
                rCrv(:,stind:endind)=retCrv(ParameterData,ParameterData{ind}.de(i),nvecI(i),dim);
                stind=endind+1;
            end
        end
        
    else
        
        crvind=zeros(1,n);
        crvindred=ParameterData{ind}.de;
        stind=1;
        for i=1:(ParameterData{ind}.n)
            if nvecI(i)>0
                endind=stind+nvecI(i)-1;
                [rCrv(:,stind:endind),crvind(stind:endind)]=retCrv(ParameterData,ParameterData{ind}.de(i),nvecI(i),dim);
                stind=endind+1;
            end
        end
        
    end
    
elseif ParameterData{ind}.type==110
    
    rCrv=zeros(dim,n);
    
    if nargout==1
        tvec=linspace(0,(1-1/n),n);
    else
        tvec=linspace(0,1,n);
    end
    
    rCrv(1,:)=ParameterData{ind}.x1+tvec*(ParameterData{ind}.x2-ParameterData{ind}.x1);
    rCrv(2,:)=ParameterData{ind}.y1+tvec*(ParameterData{ind}.y2-ParameterData{ind}.y1);
    
    if dim>2
        rCrv(3,:)=ParameterData{ind}.z1+tvec*(ParameterData{ind}.z2-ParameterData{ind}.z1);
    end
    
    if nargout>1
        crvind=ind*ones(1,n);
        crvindred=ind;
    end
    
elseif ParameterData{ind}.type==126
    
    tst=ParameterData{ind}.v(1);
    ten=ParameterData{ind}.v(2);
    
    if nargout==1
        tvec=linspace(tst,ten-(ten-tst)/n,n);
    else
        tvec=linspace(tst,ten,n);
    end
    
    if dim==3
        rCrv=nrbevalIGES(ParameterData{ind}.nurbs,tvec);
    else
        P3=nrbevalIGES(ParameterData{ind}.nurbs,tvec);
        rCrv=P3(1:dim,:);
    end
    
    if nargout>1
        crvind=ind*ones(1,n);
        crvindred=ind;
    end
    
else
    rCrv=zeros(dim,n);
    
    if nargout>1
        crvind=ind*ones(1,0);
        crvindred=ind;
    end
end


function rCrv=ret2Crv(ParameterData,ind,n)

if ParameterData{ind}.type==126
    
    if n>1
        tst=ParameterData{ind}.v(1);
        ten=ParameterData{ind}.v(2);
        
        tvec=linspace(tst,ten-(ten-tst)/n,n);
        
        p=nrbevalIGES(ParameterData{ind}.nurbs,tvec);
        
        rCrv=p(1:2,:);
    elseif n==1
        rCrv=ParameterData{ind}.p(1:2,1);
    else
        rCrv=zeros(2,0);
    end
    
elseif ParameterData{ind}.type==110
    
    if n>1
        rCrv=zeros(2,n);
        tvec=linspace(0,(1-1/n),n);
        rCrv(1,:)=ParameterData{ind}.x1+tvec*(ParameterData{ind}.x2-ParameterData{ind}.x1);
        rCrv(2,:)=ParameterData{ind}.y1+tvec*(ParameterData{ind}.y2-ParameterData{ind}.y1);
    elseif n==1
        rCrv=ParameterData{ind}.p1(1:2);
    else
        rCrv=zeros(2,0);
    end
    
elseif ParameterData{ind}.type==142
    
    rCrv=ret2Crv(ParameterData,ParameterData{ind}.bptr,n);
    
elseif ParameterData{ind}.type==141
    
    nvecF=(n/(ParameterData{ind}.length))*(ParameterData{ind}.psclength);
    nvecI=allocateNumCrvParams(nvecF,n);
    
    rCrv=zeros(2,n);
    
    stind=0;
    for i=1:ParameterData{ind}.n
        if nvecI(i)>0
            nvecI2=allocateNumCrvParams((nvecI(i)/ParameterData{ind}.psclength(i))*ParameterData{ind}.pscclctnlength{i},nvecI(i));
            for j=1:ParameterData{ind}.k(i)
                if nvecI2(j)>0
                    endind=stind+nvecI2(j);
                    rCrv(:,(stind+1):endind)=ret2Crv(ParameterData,ParameterData{ind}.pscpt{i}(j),nvecI2(j));
                    stind=endind;
                end
            end
        end
    end
    
elseif ParameterData{ind}.type==102
    
    nvecF=(n/(ParameterData{ind}.length))*(ParameterData{ind}.lengthcnt);
    nvecI=allocateNumCrvParams(nvecF,n);
    
    rCrv=zeros(2,n);
    
    stind=1;
    for i=1:(ParameterData{ind}.n)
        if nvecI(i)>0
            endind=stind+nvecI(i)-1;
            rCrv(:,stind:endind)=ret2Crv(ParameterData,ParameterData{ind}.de(i),nvecI(i));
            stind=endind+1;
        end
    end
    
else
    
    rCrv=zeros(2,n);
    
end

function UV=retUVCrv(srfind,ParameterData,ind,n,minNumPscl)

if ParameterData{ind}.type==126
    
    UV=crvPntsSrfNURBS(n,ParameterData{srfind}.nurbs,ParameterData{ind}.nurbs,ParameterData{ind}.v(1),ParameterData{ind}.v(2),ParameterData{ind}.evalmthd);
    
elseif ParameterData{ind}.type==110
    
    UV=crvPntsSrfNURBS(n,ParameterData{srfind}.nurbs,ParameterData{ind}.p1,ParameterData{ind}.p2,ParameterData{ind}.evalmthd);
    
elseif ParameterData{ind}.type==142
    
    ind=ParameterData{ind}.bptr;
    
    if ParameterData{ind}.type==102
        nvecF=(max(n-minNumPscl*ParameterData{ind}.numcrv,0)/(ParameterData{ind}.length))*(ParameterData{ind}.lengthcnt);
        nvecI=allocateNumCrvParamsC(nvecF,n,ParameterData{ind}.numcrvcnt,minNumPscl);
        UV=zeros(2,n);
        stind=1;
        for i=1:(ParameterData{ind}.n)
            if nvecI(i)>0
                endind=stind+nvecI(i)-1;
                if ParameterData{ParameterData{ind}.de(i)}.type==126
                    UV(:,stind:endind)=crvPntsSrfNURBS(nvecI(i),ParameterData{srfind}.nurbs,ParameterData{ParameterData{ind}.de(i)}.nurbs,ParameterData{ParameterData{ind}.de(i)}.v(1),ParameterData{ParameterData{ind}.de(i)}.v(2),ParameterData{ParameterData{ind}.de(i)}.evalmthd);
                elseif ParameterData{ParameterData{ind}.de(i)}.type==110
                    UV(:,stind:endind)=crvPntsSrfNURBS(nvecI(i),ParameterData{srfind}.nurbs,ParameterData{ParameterData{ind}.de(i)}.p1,ParameterData{ParameterData{ind}.de(i)}.p2,ParameterData{ParameterData{ind}.de(i)}.evalmthd);
                else
                    UV(:,stind:endind)=retUVCrv(srfind,ParameterData,ParameterData{ind}.de(i),nvecI(i),minNumPscl);
                end
                UV(:,stind:endind)=retUVCrv(srfind,ParameterData,ParameterData{ind}.de(i),nvecI(i),minNumPscl);
                stind=endind+1;
            end
        end
    elseif ParameterData{ind}.type==126
        UV=crvPntsSrfNURBS(n,ParameterData{srfind}.nurbs,ParameterData{ind}.nurbs,ParameterData{ind}.v(1),ParameterData{ind}.v(2),ParameterData{ind}.evalmthd);
    else
        UV=retUVCrv(srfind,ParameterData,ind,n,minNumPscl);
    end
    
elseif ParameterData{ind}.type==141
    
    nvecF=(max(n-minNumPscl*ParameterData{ind}.numcrv,0)/(ParameterData{ind}.length))*(ParameterData{ind}.psclength);
    nvecI=allocateNumCrvParamsC(nvecF,n,ParameterData{ind}.numpscrv,minNumPscl);
    
    UV=zeros(2,n);
    
    stind=0;
    for i=1:ParameterData{ind}.n
        if nvecI(i)>0
            nvecI2=allocateNumCrvParamsC((max(nvecI(i)-minNumPscl*ParameterData{ind}.numpscrv(i),0)/ParameterData{ind}.psclength(i))*ParameterData{ind}.pscclctnlength{i},nvecI(i),ParameterData{ind}.numpscrvc{i},minNumPscl);
            for j=1:ParameterData{ind}.k(i)
                if nvecI2(j)>0
                    endind=stind+nvecI2(j);
                    if ParameterData{ParameterData{ind}.pscpt{i}(j)}.type==126
                        UV(:,(stind+1):endind)=crvPntsSrfNURBS(nvecI2(j),ParameterData{srfind}.nurbs,ParameterData{ParameterData{ind}.pscpt{i}(j)}.nurbs,ParameterData{ParameterData{ind}.pscpt{i}(j)}.v(1),ParameterData{ParameterData{ind}.pscpt{i}(j)}.v(2),ParameterData{ParameterData{ind}.pscpt{i}(j)}.evalmthd);
                    elseif ParameterData{ParameterData{ind}.pscpt{i}(j)}.type==110
                        UV(:,(stind+1):endind)=crvPntsSrfNURBS(nvecI2(j),ParameterData{srfind}.nurbs,ParameterData{ParameterData{ind}.pscpt{i}(j)}.p1,ParameterData{ParameterData{ind}.pscpt{i}(j)}.p2,ParameterData{ParameterData{ind}.pscpt{i}(j)}.evalmthd);
                    else
                        UV(:,(stind+1):endind)=retUVCrv(srfind,ParameterData,ParameterData{ind}.pscpt{i}(j),nvecI2(j),minNumPscl);
                    end
                    stind=endind;
                end
            end
        end
    end
    
elseif ParameterData{ind}.type==102
    
    nvecF=(max(n-minNumPscl*ParameterData{ind}.numcrv,0)/(ParameterData{ind}.length))*(ParameterData{ind}.lengthcnt);
    nvecI=allocateNumCrvParamsC(nvecF,n,ParameterData{ind}.numcrvcnt,minNumPscl);
    
    UV=zeros(2,n);
    
    stind=1;
    for i=1:(ParameterData{ind}.n)
        if nvecI(i)>0
            endind=stind+nvecI(i)-1;
            if ParameterData{ParameterData{ind}.de(i)}.type==126
                UV(:,stind:endind)=crvPntsSrfNURBS(nvecI(i),ParameterData{srfind}.nurbs,ParameterData{ParameterData{ind}.de(i)}.nurbs,ParameterData{ParameterData{ind}.de(i)}.v(1),ParameterData{ParameterData{ind}.de(i)}.v(2),ParameterData{ParameterData{ind}.de(i)}.evalmthd);
            elseif ParameterData{ParameterData{ind}.de(i)}.type==110
                UV(:,stind:endind)=crvPntsSrfNURBS(nvecI(i),ParameterData{srfind}.nurbs,ParameterData{ParameterData{ind}.de(i)}.p1,ParameterData{ParameterData{ind}.de(i)}.p2,ParameterData{ParameterData{ind}.de(i)}.evalmthd);
            else
                UV(:,stind:endind)=retUVCrv(srfind,ParameterData,ParameterData{ind}.de(i),nvecI(i),minNumPscl);
            end
            UV(:,stind:endind)=retUVCrv(srfind,ParameterData,ParameterData{ind}.de(i),nvecI(i),minNumPscl);
            stind=endind+1;
        end
    end
    
else
    
    UV=zeros(2,n);
    
end


function rCrv=ret2CrvII(ParameterData,ind,n)

if ParameterData{ind}.type==126
    
    if n>1
        tst=ParameterData{ind}.v(1);
        ten=ParameterData{ind}.v(2);
        
        tvec=linspace(tst,ten,n);
        
        p=nrbevalIGES(ParameterData{ind}.nurbs,tvec);
        
        rCrv=p(1:2,:);
    elseif n==1
        rCrv=ParameterData{ind}.p(1:2,1);
    else
        rCrv=zeros(2,0);
    end
    
elseif ParameterData{ind}.type==110
    
    if n>1
        rCrv=zeros(2,n);
        tvec=linspace(0,1,n);
        rCrv(1,:)=ParameterData{ind}.x1+tvec*(ParameterData{ind}.x2-ParameterData{ind}.x1);
        rCrv(2,:)=ParameterData{ind}.y1+tvec*(ParameterData{ind}.y2-ParameterData{ind}.y1);
    elseif n==1
        rCrv=ParameterData{ind}.p1(1:2);
    else
        rCrv=zeros(2,0);
    end
    
elseif ParameterData{ind}.type==142
    
    rCrv=ret2Crv(ParameterData,ParameterData{ind}.bptr,n);
    
elseif ParameterData{ind}.type==141
    
    nvecF=(n/(ParameterData{ind}.length))*(ParameterData{ind}.psclength);
    nvecI=allocateNumCrvParams(nvecF,n);
    
    rCrv=zeros(2,n);
    
    stind=0;
    for i=1:ParameterData{ind}.n
        if nvecI(i)>0
            nvecI2=allocateNumCrvParams((nvecI(i)/ParameterData{ind}.psclength(i))*ParameterData{ind}.pscclctnlength{i},nvecI(i));
            for j=1:ParameterData{ind}.k(i)
                if nvecI2(j)>0
                    endind=stind+nvecI2(j);
                    rCrv(:,(stind+1):endind)=ret2Crv(ParameterData,ParameterData{ind}.pscpt{i}(j),nvecI2(j));
                    stind=endind;
                end
            end
        end
    end
    
elseif ParameterData{ind}.type==102
    
    nvecF=(n/(ParameterData{ind}.length))*(ParameterData{ind}.lengthcnt);
    nvecI=allocateNumCrvParams(nvecF,n);
    
    rCrv=zeros(2,n);
    
    stind=1;
    for i=1:(ParameterData{ind}.n)
        if nvecI(i)>0
            endind=stind+nvecI(i)-1;
            rCrv(:,stind:endind)=ret2Crv(ParameterData,ParameterData{ind}.de(i),nvecI(i));
            stind=endind+1;
        end
    end
    
else
    
    rCrv=zeros(2,n);
    
end


function rCrv=ret3Crv(ParameterData,ind,n)

if ParameterData{ind}.type==110
    
    if n>1
        rCrv=zeros(3,n);
        
        tvec=linspace(0,(1-1/n),n);
        
        rCrv(1,:)=ParameterData{ind}.x1+tvec*(ParameterData{ind}.x2-ParameterData{ind}.x1);
        rCrv(2,:)=ParameterData{ind}.y1+tvec*(ParameterData{ind}.y2-ParameterData{ind}.y1);
        rCrv(3,:)=ParameterData{ind}.z1+tvec*(ParameterData{ind}.z2-ParameterData{ind}.z1);
    elseif n==1
        rCrv=ParameterData{ind}.p1;
    else
        rCrv=zeros(3,0);
    end
    
elseif ParameterData{ind}.type==126
    
    if n>1
        tst=ParameterData{ind}.v(1);
        ten=ParameterData{ind}.v(2);
        
        tvec=linspace(tst,ten-(ten-tst)/n,n);
        
        rCrv=nrbevalIGES(ParameterData{ind}.nurbs,tvec);
    elseif n==1
        rCrv=ParameterData{ind}.p(:,1);
    else
        rCrv=zeros(3,0);
    end
    
elseif ParameterData{ind}.type==142
    
    rCrv=ret3Crv(ParameterData,ParameterData{ind}.bptr,n);
    
elseif ParameterData{ind}.type==141
    
    nvecF=(n/(ParameterData{ind}.length))*(ParameterData{ind}.psclength);
    nvecI=allocateNumCrvParams(nvecF,n);
    
    rCrv=zeros(3,n);
    
    stind=0;
    for i=1:ParameterData{ind}.n
        if nvecI(i)>0
            nvecI2=allocateNumCrvParams((nvecI(i)/ParameterData{ind}.psclength(i))*ParameterData{ind}.pscclctnlength{i},nvecI(i));
            for j=1:ParameterData{ind}.k(i)
                if nvecI2(j)>0
                    endind=stind+nvecI2(j);
                    rCrv(:,(stind+1):endind)=ret3Crv(ParameterData,ParameterData{ind}.pscpt{i}(j),nvecI2(j));
                    stind=endind;
                end
            end
        end
    end
    
elseif ParameterData{ind}.type==102
    
    nvecF=(n/(ParameterData{ind}.length))*(ParameterData{ind}.lengthcnt);
    nvecI=allocateNumCrvParams(nvecF,n);
    
    rCrv=zeros(3,n);
    
    stind=1;
    for i=1:(ParameterData{ind}.n)
        if nvecI(i)>0
            endind=stind+nvecI(i)-1;
            rCrv(:,stind:endind)=ret3Crv(ParameterData,ParameterData{ind}.de(i),nvecI(i));
            stind=endind+1;
        end
    end
    
else
    
    rCrv=zeros(3,n);
    
end


function rCrv=retSpaceCrv(ParameterData,ind,n)

if ParameterData{ind}.type==142
    
    rCrv=ret3Crv(ParameterData,ParameterData{ind}.cptr,n);
    
elseif ParameterData{ind}.type==141
    
    nvecF=(n/sum(ParameterData{ind}.msclength))*(ParameterData{ind}.msclength);
    nvecI=allocateNumCrvParams(nvecF,n);
    
    rCrv=zeros(3,n);
    
    stind=0;
    for i=1:ParameterData{ind}.n
        if nvecI(i)>0
            endind=stind+nvecI(i);
            rCrv(:,(stind+1):endind)=ret3Crv(ParameterData,ParameterData{ind}.crvpt(i),nvecI(i));
            stind=endind;
        end
    end
    
else
    
    rCrv=ret3Crv(ParameterData,ind,n);
    
end


function nvecI=allocateNumCrvParams(nvecF,n)

nvecI=floor(nvecF);

numzero=sum(nvecI==0);
nrest=n-sum(nvecI);

if numzero>0
    [~,in]=sort(nvecF);
    if nrest<numzero
        nvecI(in((numzero-nrest+1):numzero))=1;
    else
        nvecI(in(1:numzero))=1;
        nrest=nrest-numzero;
        if nrest>0
            nvecre=nvecI-nvecF;
            [~,in]=sort(nvecre);
            nvecI(in(1:nrest))=nvecI(in(1:nrest))+1;
        end
    end
else
    if nrest>0
        nvecre=nvecI-nvecF;
        [~,in]=sort(nvecre);
        nvecI(in(1:nrest))=nvecI(in(1:nrest))+1;
    end
end


function nvecI=allocateNumCrvParamsC(nvecF,n,vecNumCrv,minNumPscl)

nvecI=floor(nvecF);
nrest=n-sum(nvecI);

for j=1:minNumPscl
    for i=1:length(nvecF)
        if nrest>0
            if minNumPscl*vecNumCrv(i)>nvecI(i)
                nvecI(i)=nvecI(i)+1;
                nrest=nrest-1;
            end
        end
    end
end

if nrest>0
    numzero=sum(nvecI==0);
    
    if numzero>0
        [~,in]=sort(nvecF);
        if nrest<numzero
            nvecI(in((numzero-nrest+1):numzero))=1;
        else
            nvecI(in(1:numzero))=1;
            nrest=nrest-numzero;
            
            while nrest>0
                if nrest>=length(nvecF)
                    nvecI=nvecI+1;
                    nrest=nrest-length(nvecF);
                else
                    nvecre=nvecI-nvecF;
                    [~,in]=sort(nvecre);
                    nvecI(in(1:nrest))=nvecI(in(1:nrest))+1;
                    nrest=0;
                end
            end
        end
    else
        while nrest>0
            if nrest>=length(nvecF)
                nvecI=nvecI+1;
                nrest=nrest-length(nvecF);
            else
                nvecre=nvecI-nvecF;
                [~,in]=sort(nvecre);
                nvecI(in(1:nrest))=nvecI(in(1:nrest))+1;
                nrest=0;
            end
        end
    end
end


function [UV,TRI] = trimesh(UV,NN)

numC=size(NN,2);
numP=NN(end);

Constraints=zeros(numP,2);
Constraints(:,1)=(1:numP)';
Constraints(:,2)=(2:(numP+1))';

Constraints(NN(1),2)=1;
for i=2:numC
    Constraints(NN(i),2)=NN(i-1)+1;
end

DT = delaunayTriangulation(UV',Constraints);

if ne(size(DT.Points,1),numP)
    UV=DT.Points';
end

TRI=DT.ConnectivityList(isInterior(DT),:);


function [UV,TRI] = trimeshRegular(UV,NN,meshIters,nu,nv,umin,umax,vmin,vmax)

numC=size(NN,2);
numP=NN(end);

Constraints=zeros(numP,2);
Constraints(:,1)=(1:numP)';
Constraints(:,2)=(2:(numP+1))';

Constraints(NN(1),2)=1;
for i=2:numC
    Constraints(NN(i),2)=NN(i-1)+1;
end

try
    
    dpu=(umax-umin)/(nu+1);
    dpv=(vmax-vmin)/(nv+1);
    
    UVreg=nrbSrfRegularEvalIGES(umin+dpu,umax-dpu,nu,vmin+dpv,vmax-dpv,nv);
    
    DT = delaunayTriangulation([UV';UVreg'],Constraints);
    inout=isInterior(DT);
    
    usePnts=false(1,size(DT.Points,1));
    newIndex=zeros(1,size(DT.Points,1));
    
    for i=1:length(inout)
        if inout(i)
            usePnts(DT.ConnectivityList(i,1))=true;
            usePnts(DT.ConnectivityList(i,2))=true;
            usePnts(DT.ConnectivityList(i,3))=true;
        end
    end
    ind=1;
    for i=1:size(DT.Points,1)
        if usePnts(i)
            newIndex(i)=ind;
            ind=ind+1;
        end
    end
    
    TRI=DT.ConnectivityList(inout,:);
    UV=DT.Points(usePnts,:)';
    
    for i=1:(3*size(TRI,1))
        TRI(i)=newIndex(TRI(i));
    end
    
catch
    
    try
        
        if nu>2
            dpu=(umax-umin)/(nu+0.9*rand);
        else
            dpu=1.5*(umax-umin)/(nu+2);
        end
        if nv>2
            dpv=(vmax-vmin)/(nv+0.9*rand);
        else
            dpv=1.5*(vmax-vmin)/(nv+2);
        end
        
        UVreg=nrbSrfRegularEvalIGES(umin+dpu,umax-dpu,nu,vmin+dpv,vmax-dpv,nv);
        
        DT = delaunayTriangulation([UV';UVreg'],Constraints);
        inout=isInterior(DT);
        
        usePnts=false(1,size(DT.Points,1));
        newIndex=zeros(1,size(DT.Points,1));
        
        for i=1:length(inout)
            if inout(i)
                usePnts(DT.ConnectivityList(i,1))=true;
                usePnts(DT.ConnectivityList(i,2))=true;
                usePnts(DT.ConnectivityList(i,3))=true;
            end
        end
        ind=1;
        for i=1:size(DT.Points,1)
            if usePnts(i)
                newIndex(i)=ind;
                ind=ind+1;
            end
        end
        
        TRI=DT.ConnectivityList(inout,:);
        UV=DT.Points(usePnts,:)';
        
        for i=1:(3*size(TRI,1))
            TRI(i)=newIndex(TRI(i));
        end
        
    catch
        
        DT = delaunayTriangulation(UV',Constraints);
        
        if ne(size(DT.Points,1),numP)
            UV=DT.Points';
        end
        
        TRI=DT.ConnectivityList(isInterior(DT),:);
        
    end
    
end
