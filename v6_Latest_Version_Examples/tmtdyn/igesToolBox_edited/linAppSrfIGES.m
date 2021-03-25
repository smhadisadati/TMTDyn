function [dir1model,dir2model,ldirmodel,dir1s,dir2s,ldirs,dir1b,dir2b,ldirb]=linAppSrfIGES(ParameterData,model,UV,srfind,srfs,UVs,srfinds,srfbounds,UVb,srfindb,dirb,nrmlb,tol,maxl)
% linAppSrfIGES returns local linear approximations (rectangles) at sampled points on a surfaces of an IGES-object.
% It uses the output from projpartIGES and srfRepInProjection
%
% Usage:
%
% [dir1model,dir2model,ldirmodel,dir1s,dir2s,ldirs,dir1b,dir2b,ldirb]=...
%       linAppSrfIGES(ParameterData,model,UV,srfind,srfs,UVs,srfinds,srfbounds,UVb,srfindb,dirb,nrmlb,tol,maxl)
%
% Input:
%
% See help of projpartIGES and srfRepInProjection for more information about the input variables
% tol - A positive number giving the tolerance of how much the local linear approximation (rectangles) can deviate
%       compared to a local quadratic approximation
% maxl - The maximal length of the approximating rectangles
%
% m-file can be downloaded at
% http://www.mathworks.com/matlabcentral/fileexchange/13253-iges-toolbox
%
% written by Per Bergström 2012-03-13
%


tol=max(tol,1e-14);

nummodel=size(model,2);

dir1model=zeros(3,nummodel);
dir2model=zeros(3,nummodel);
ldirmodel=zeros(2,nummodel);

for i=1:nummodel
    
    sind=srfind(i);
    if sind>0
        
        if ParameterData{sind}.type==128
            
            [Ptmp,ntmp,dir1,dir2,ldir]=quadAppNrb(ParameterData{sind}.nurbs,UV(:,i),ParameterData{sind}.dnurbs,ParameterData{sind}.d2nurbs,tol);
            
            if ldir(1)>ldir(2)
                dir1model(:,i)=dir1;
                dir2model(:,i)=dir2;
                ldirmodel(:,i)=min(ldir,maxl);
            else
                dir1model(:,i)=dir2;
                dir2model(:,i)=dir1;
                ldirmodel(1,i)=min(ldir(2),maxl);
                ldirmodel(2,i)=min(ldir(1),maxl);
            end
            
        elseif ParameterData{sind}.type==108
            
            nrml=ParameterData{sind}.normal;
            nulsp=null(nrml');
            dir1model(:,i)=nulsp(:,1);
            dir2model(:,i)=nulsp(:,2);
            ldirmodel(:,i)=maxl;
            
        end
        
    end
    
end

nums=size(srfs,2);

dir1s=zeros(3,nums);
dir2s=zeros(3,nums);
ldirs=zeros(2,nums);

for i=1:nums
    
    sind=srfinds(i);
    
    if ParameterData{sind}.type==128
        
        [Ptmp,ntmp,dir1,dir2,ldir]=quadAppNrb(ParameterData{sind}.nurbs,UVs(:,i),ParameterData{sind}.dnurbs,ParameterData{sind}.d2nurbs,tol);
        
        if ldir(1)>ldir(2)
            dir1s(:,i)=dir1;
            dir2s(:,i)=dir2;
            ldirs(:,i)=min(ldir,maxl);
        else
            dir1s(:,i)=dir2;
            dir2s(:,i)=dir1;
            ldirs(1,i)=min(ldir(2),maxl);
            ldirs(2,i)=min(ldir(1),maxl);
        end
        
    elseif ParameterData{sind}.type==108
        
        nrml=ParameterData{sind}.normal;
        nulsp=null(nrml');
        dir1s(:,i)=nulsp(:,1);
        dir2s(:,i)=nulsp(:,2);
        ldirs(:,i)=maxl;
        
    end
    
end

numb=size(srfbounds,2);

dir1b=zeros(3,numb);
dir2b=zeros(3,numb);
ldirb=zeros(2,numb);

for i=1:numb
    
    sind=srfindb(i);
    
    dir1b(:,i)=dirb(:,i);
    dir2b(:,i)=cross(dirb(:,i),nrmlb(:,i));
    
    if ParameterData{sind}.type==128
        
        [Ptmp,ntmp,dir1,dir2,ldir]=quadAppNrb(ParameterData{sind}.nurbs,UVb(:,i),ParameterData{sind}.dnurbs,ParameterData{sind}.d2nurbs,tol);
        
        ldir=min(ldir,maxl);
        
        ldirb(1,i)=0.5*min(ldir);
        
    elseif ParameterData{sind}.type==108
        
        ldirb(1,i)=0.1*maxl;
        
    end
    
    ldirb(2,i)=0.05*ldirb(1,i);
    
end


function [P,normal,dir1,dir2,R,quadcoef1,quadcoef2]=quadAppNrb(nurbs,UV,dnurbs,d2nurbs,tol)

R=[0;0];

% NURBS evaluation
[P,Su,Sv,Suu,Suv,Svv]=nrbevalIGES(nurbs,UV,dnurbs,d2nurbs);

Eu=norm(Su);
Ev=norm(Sv);

if and(Eu<1e-12,Eu<1e-12)
    
    normal=[0;0;1];
    dir1=[1;0;0];
    dir2=[0;1;0];
    
    quadcoef1=0;
    quadcoef2=0;
    
elseif 1e8*Eu<Ev
    
    dir1=Sv/Ev;
    
    nusp=null(dir1');
    
    if norm(nusp(:,1)-Su)<norm(nusp(:,2)-Su)
        dir2=nusp(:,1);
        normal=nusp(:,2);
    else
        dir2=nusp(:,2);
        normal=nusp(:,1);
    end
    
    quadcoef1=0;
    quadcoef2=0;
    
elseif 1e8*Ev<Eu
    
    dir1=Su/Eu;
    
    nusp=null(dir1');
    
    if norm(nusp(:,1)-Sv)<norm(nusp(:,2)-Sv)
        dir2=nusp(:,1);
        normal=nusp(:,2);
    else
        dir2=nusp(:,2);
        normal=nusp(:,1);
    end
    
    quadcoef1=0;
    quadcoef2=0;
    
else
    
    [Usvd,Sig,Vsvd]=svd([Su Sv]);
    
    if dot(Usvd(:,3),cross(Su,Sv))>0
        normal=Usvd(:,3);
    else
        normal=-Usvd(:,3);
    end
    
    a=dot(Suu,normal);
    b=dot(Svv,normal);
    c=dot(Suv,normal);
    
    V=Vsvd;
    V(:,1)=V(:,1)/Sig(1);
    V(:,2)=V(:,2)/Sig(5);

    [V,D]=eig(V'*[a c;c b]*V);
    
    D(1)=0.5*D(1);
    D(4)=0.5*D(4);
    
    dir1=Usvd(:,1)*V(1)+Usvd(:,2)*V(3);
    dir2=Usvd(:,1)*V(2)+Usvd(:,2)*V(4);  

    dir1=dir1/norm(dir1);
    dir2=dir2/norm(dir2);
    
    quadcoef1=D(1,1);
    quadcoef2=D(2,2);
        
    for j=1:2
        T=tol;
        acoef=abs(D(j,j));
        for NRiter=1:10
            T=(8*acoef*T^3+T^2+tol^2)/(12*acoef*T^2+2*T);
        end
        if abs(4*acoef*T^3+T^2-tol^2)>1e-12
            for NRiter=1:10
                T=(8*acoef*T^3+T^2+tol^2)/(12*acoef*T^2+2*T);
            end
        end
        if acoef>1e-15
            T=min(sqrt(T/acoef),1/tol);
        else
            T=1/tol;
        end
        R(j)=T+2*acoef^2*T^3;
    end   
    
end
