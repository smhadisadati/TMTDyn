function [nrmlmodel,srfbounds,UVb,nrmlb,dirb,srfindb,srfs,UVs,nrmls,srfinds]=srfRepInProjection(varargin)
% srfRepInProjection returns normals and points on a surfaces of an IGES-object.
% It uses the output from projpartIGES
%
% Usage I:
%
% [nrmlmodel,srfbounds,UVb,nrmlb,dirb,srfindb,srfs,UVs,nrmls,srfinds]=...
%      srfRepInProjection(ParameterData,R,normal,pdir,sdir,dp,nppos,npneg,nspos,nsneg,model,UV,srfind,dpfactor,dpsfactor)
%
% Usage II:
%
% [nrmlmodel,srfbounds,UVb,nrmlb,dirb,srfindb,srfs,UVs,nrmls,srfinds]=...
%      srfRepInProjection(ParameterData,normal,pdir,sdir,dp,numpoints,model,UV,srfind,dpfactor,dpsfactor)
%
% Input:
%
% See help of projIGES and projpartIGES for more information about the input variables
% dpfactor - A positive scalar telling how dense the boundary poins will be compared to dp
% dpsfactor - A positive scalar telling how dense the surface poins will be compared to dp
%
% m-file can be downloaded at
% http://www.mathworks.com/matlabcentral/fileexchange/13253-iges-toolbox
%
% written by Per Bergström 2015-12-06
%

if nargin==15
    ParameterData=varargin{1};
    R=varargin{2};
    normal=varargin{3};
    pdir=varargin{4};
    sdir=varargin{5};
    dp=varargin{6};
    nppos=varargin{7};
    npneg=varargin{8};
    nspos=varargin{9};
    nsneg=varargin{10};
    model=varargin{11};
    UV=varargin{12};
    srfind=varargin{13};
    dpfactor=varargin{14};
    dpsfactor=varargin{15};
    
    np=npneg+1+nppos;
    ns=nsneg+1+nspos;
elseif nargin==11
    ParameterData=varargin{1};
    normal=varargin{2};
    pdir=varargin{3};
    sdir=varargin{4};
    dp=varargin{5};
    numpoints=varargin{6};
    model=varargin{7};
    UV=varargin{8};
    srfind=varargin{9};
    dpfactor=varargin{10};
    dpsfactor=varargin{11};
    
    np=numpoints(1);
    ns=numpoints(2);
else
    error('Wrong number of input arguments');
end

npm1=np-1;
nsm1=ns-1;

nrmlmodel=zeros(3,np*ns);

nrml=zeros(3,1);

bool=true;

for j=1:np
    for i=1:ns
        mind=i+(j-1)*ns;
        sind=srfind(mind);
        if sind>0
            
            if bool
                if nargin==11
                    refP=model(:,mind)-((j-1)*dp)*pdir-((i-1)*dp)*sdir;
                end
                bool=false;
            end
            
            if ParameterData{sind}.type==108
                nrml(:)=ParameterData{sind}.normal;
                nonrml=norm(nrml);
                if nonrml>1e-10
                    nrmlmodel(:,mind)=nrml/norm(nrml);
                end
            elseif ParameterData{sind}.type==128
                [~,Ptmpu,Ptmpv]=nrbevalIGES(ParameterData{sind}.nurbs,UV(:,mind),ParameterData{sind}.dnurbs);
                nrml(:)=cross(Ptmpu,Ptmpv);
                nonrml=norm(nrml);
                if nonrml>1e-10
                    nrmlmodel(:,mind)=nrml/norm(nrml);
                end
            end
        end
    end
end

if nargout>1
    
    srfbounds=zeros(3,0);
    UVb=zeros(2,0);
    nrmlb=zeros(3,0);
    dirb=zeros(3,0);
    srfindb=zeros(1,0);
    
    srfs=zeros(3,0);
    UVs=zeros(2,0);
    nrmls=zeros(3,0);
    srfinds=zeros(1,0);
    
    if nargin==15
        refP=R-(npneg*dp)*pdir-(nsneg*dp)*sdir;
    end
    
    refPpdir=dot(pdir,refP);
    refPsdir=dot(sdir,refP);
    
    deltap=npm1*dp;
    deltas=nsm1*dp;
    
    modelnormal=normal'*model;
    
    modelnormalmin=zeros(nsm1,npm1);
    modelnormalmax=zeros(nsm1,npm1);
    
    srfsdensity=dpsfactor/(dp^2);
    crvdensity=dpfactor/dp;
    
    le=zeros(1,4);
    
    for j=1:npm1
        for i=1:nsm1
            if any(srfind([i+(j-1)*ns,i+1+(j-1)*ns,i+j*ns,i+1+j*ns])==0)
                modelnormalmin(i,j)=-1e99;
                modelnormalmax(i,j)=1e99;
            else
                le(:)=modelnormal([i+(j-1)*ns,i+1+(j-1)*ns,i+j*ns,i+1+j*ns]);
                modelnormalmin(i,j)=min(le)-0.5*dp;
                modelnormalmax(i,j)=max(le)+0.5*dp;
            end
        end
    end
    
    stind=1;
    stsind=1;
    
    for i=1:length(ParameterData)
        
        if ParameterData{i}.type==144
            
            entiall=ParameterData{i}.pts;
            
            if ParameterData{entiall}.well
                
                if ParameterData{entiall}.type==128
                    
                    le(1)=round(crvdensity*ParameterData{ParameterData{i}.pto}.length);
                    
                    if le(1)>0
                        
                        [UVtmp,diruvtmp]=retCrvD(ParameterData,ParameterData{ParameterData{i}.pto}.bptr,le(1),2);
                        [Ptmp,Ptmpu,Ptmpv]=nrbevalIGES(ParameterData{entiall}.nurbs,UVtmp,ParameterData{entiall}.dnurbs);
                        
                        isIn=isOnto(Ptmp,i,normal,pdir,sdir,np,ns,dp,deltap,deltas,refPpdir,refPsdir,modelnormalmin,modelnormalmax,srfind);
                        numPtmp=sum(isIn);
                        
                        if numPtmp>0
                            srfbounds(:,stind:(stind+numPtmp-1))=Ptmp(:,isIn);
                            UVb(:,stind:(stind+numPtmp-1))=UVtmp(:,isIn);
                            nrmlb(1,stind:(stind+numPtmp-1))=Ptmpu(2,isIn).*Ptmpv(3,isIn)-Ptmpu(3,isIn).*Ptmpv(2,isIn);
                            nrmlb(2,stind:(stind+numPtmp-1))=Ptmpu(3,isIn).*Ptmpv(1,isIn)-Ptmpu(1,isIn).*Ptmpv(3,isIn);
                            nrmlb(3,stind:(stind+numPtmp-1))=Ptmpu(1,isIn).*Ptmpv(2,isIn)-Ptmpu(2,isIn).*Ptmpv(1,isIn);
                            dirb(1,stind:(stind+numPtmp-1))=Ptmpu(1,isIn).*diruvtmp(1,isIn)+Ptmpv(1,isIn).*diruvtmp(2,isIn);
                            dirb(2,stind:(stind+numPtmp-1))=Ptmpu(2,isIn).*diruvtmp(1,isIn)+Ptmpv(2,isIn).*diruvtmp(2,isIn);
                            dirb(3,stind:(stind+numPtmp-1))=Ptmpu(3,isIn).*diruvtmp(1,isIn)+Ptmpv(3,isIn).*diruvtmp(2,isIn);
                            srfindb(:,stind:(stind+numPtmp-1))=entiall*ones(1,numPtmp);
                            stind=stind+numPtmp;
                        end
                        
                    end
                    
                    for j=1:ParameterData{i}.n2
                        
                        le(1)=round(crvdensity*ParameterData{ParameterData{i}.pti(j)}.length);
                        
                        if le(1)>0
                            
                            [UVtmp,diruvtmp]=retCrvD(ParameterData,ParameterData{ParameterData{i}.pti(j)}.bptr,le(1),2);
                            [Ptmp,Ptmpu,Ptmpv]=nrbevalIGES(ParameterData{entiall}.nurbs,UVtmp,ParameterData{entiall}.dnurbs);
                            
                            isIn=isOnto(Ptmp,i,normal,pdir,sdir,np,ns,dp,deltap,deltas,refPpdir,refPsdir,modelnormalmin,modelnormalmax,srfind);
                            numPtmp=sum(isIn);
                            
                            if numPtmp>0
                                srfbounds(:,stind:(stind+numPtmp-1))=Ptmp(:,isIn);
                                UVb(:,stind:(stind+numPtmp-1))=UVtmp(:,isIn);
                                nrmlb(1,stind:(stind+numPtmp-1))=Ptmpu(2,isIn).*Ptmpv(3,isIn)-Ptmpu(3,isIn).*Ptmpv(2,isIn);
                                nrmlb(2,stind:(stind+numPtmp-1))=Ptmpu(3,isIn).*Ptmpv(1,isIn)-Ptmpu(1,isIn).*Ptmpv(3,isIn);
                                nrmlb(3,stind:(stind+numPtmp-1))=Ptmpu(1,isIn).*Ptmpv(2,isIn)-Ptmpu(2,isIn).*Ptmpv(1,isIn);
                                dirb(1,stind:(stind+numPtmp-1))=Ptmpu(1,isIn).*diruvtmp(1,isIn)+Ptmpv(1,isIn).*diruvtmp(2,isIn);
                                dirb(2,stind:(stind+numPtmp-1))=Ptmpu(2,isIn).*diruvtmp(1,isIn)+Ptmpv(2,isIn).*diruvtmp(2,isIn);
                                dirb(3,stind:(stind+numPtmp-1))=Ptmpu(3,isIn).*diruvtmp(1,isIn)+Ptmpv(3,isIn).*diruvtmp(2,isIn);
                                srfindb(:,stind:(stind+numPtmp-1))=entiall*ones(1,numPtmp);
                                stind=stind+numPtmp;
                            end
                            
                        end
                        
                    end
                    
                    [P,isSCP,isSup,TRI,UVons]=retSrfCrvPnt(1,ParameterData,1,i,200,1);
                    
                    [UVtmp,Ptmp,Ptmpu,Ptmpv]=getSurfaceDistributedPoints(P,UVons,TRI,srfsdensity,ParameterData{entiall}.nurbs,ParameterData{entiall}.dnurbs,ParameterData{entiall}.d2nurbs);
                    
                    isIn=isOnto(Ptmp,i,normal,pdir,sdir,np,ns,dp,deltap,deltas,refPpdir,refPsdir,modelnormalmin,modelnormalmax,srfind);
                    numPtmp=sum(isIn);
                    
                    if numPtmp>0
                        srfs(:,stsind:(stsind+numPtmp-1))=Ptmp(:,isIn);
                        UVs(:,stsind:(stsind+numPtmp-1))=UVtmp(:,isIn);
                        nrmls(1,stsind:(stsind+numPtmp-1))=Ptmpu(2,isIn).*Ptmpv(3,isIn)-Ptmpu(3,isIn).*Ptmpv(2,isIn);
                        nrmls(2,stsind:(stsind+numPtmp-1))=Ptmpu(3,isIn).*Ptmpv(1,isIn)-Ptmpu(1,isIn).*Ptmpv(3,isIn);
                        nrmls(3,stsind:(stsind+numPtmp-1))=Ptmpu(1,isIn).*Ptmpv(2,isIn)-Ptmpu(2,isIn).*Ptmpv(1,isIn);
                        srfinds(:,stsind:(stsind+numPtmp-1))=entiall*ones(1,numPtmp);
                        stsind=stsind+numPtmp;
                    end
                    
                elseif ParameterData{entiall}.type==108
                    
                    le(1)=round(crvdensity*ParameterData{ParameterData{i}.pto}.length);
                    
                    if le(1)>0
                        
                        [Ptmp,dirstmp]=retCrvD(ParameterData,ParameterData{ParameterData{i}.pto}.cptr,le(1),3);
                        
                        isIn=isOnto(Ptmp,i,normal,pdir,sdir,np,ns,dp,deltap,deltas,refPpdir,refPsdir,modelnormalmin,modelnormalmax,srfind);
                        numPtmp=sum(isIn);
                        
                        if numPtmp>0
                            srfbounds(:,stind:(stind+numPtmp-1))=Ptmp(:,isIn);
                            UVb(:,stind:(stind+numPtmp-1))=Ptmp(1:2,isIn);
                            nrmlb(1,stind:(stind+numPtmp-1))=ParameterData{entiall}.a;
                            nrmlb(2,stind:(stind+numPtmp-1))=ParameterData{entiall}.b;
                            nrmlb(3,stind:(stind+numPtmp-1))=ParameterData{entiall}.c;
                            dirb(:,stind:(stind+numPtmp-1))=dirstmp(:,isIn);
                            srfindb(:,stind:(stind+numPtmp-1))=entiall*ones(1,numPtmp);
                            stind=stind+numPtmp;
                        end
                        
                    end
                    
                    for j=1:ParameterData{i}.n2
                        
                        le(1)=round(crvdensity*ParameterData{ParameterData{i}.pti(j)}.length);
                        
                        if le(1)>0
                            
                            [Ptmp,dirstmp]=retCrvD(ParameterData,ParameterData{ParameterData{i}.pti(j)}.cptr,le(1),3);
                            
                            isIn=isOnto(Ptmp,i,normal,pdir,sdir,np,ns,dp,deltap,deltas,refPpdir,refPsdir,modelnormalmin,modelnormalmax,srfind);
                            numPtmp=sum(isIn);
                            
                            if numPtmp>0
                                srfbounds(:,stind:(stind+numPtmp-1))=Ptmp(:,isIn);
                                UVb(:,stind:(stind+numPtmp-1))=Ptmp(1:2,isIn);
                                nrmlb(1,stind:(stind+numPtmp-1))=ParameterData{entiall}.a;
                                nrmlb(2,stind:(stind+numPtmp-1))=ParameterData{entiall}.b;
                                nrmlb(3,stind:(stind+numPtmp-1))=ParameterData{entiall}.c;
                                dirb(:,stind:(stind+numPtmp-1))=dirstmp(:,isIn);
                                srfindb(:,stind:(stind+numPtmp-1))=entiall*ones(1,numPtmp);
                                stind=stind+numPtmp;
                            end
                            
                        end
                        
                    end
                    
                    [P,isSCP,isSup,TRI,UVons]=retSrfCrvPnt(1,ParameterData,1,i,200,1);
                    
                    UVtmp=getSurfaceDistributedPoints(P,UVons,TRI,srfsdensity);
                    
                    nrmlparam=ParameterData{entiall}.d/dot(ParameterData{entiall}.normal,ParameterData{entiall}.normal);
                    
                    Ptmp=null(ParameterData{entiall}.normal')*UVtmp;
                    Ptmp(1,:)=Ptmp(1,:)+nrmlparam*ParameterData{entiall}.a;
                    Ptmp(2,:)=Ptmp(2,:)+nrmlparam*ParameterData{entiall}.b;
                    Ptmp(3,:)=Ptmp(3,:)+nrmlparam*ParameterData{entiall}.c;
                    
                    isIn=isOnto(Ptmp,i,normal,pdir,sdir,np,ns,dp,deltap,deltas,refPpdir,refPsdir,modelnormalmin,modelnormalmax,srfind);
                    numPtmp=sum(isIn);
                    
                    if numPtmp>0
                        srfs(:,stsind:(stsind+numPtmp-1))=Ptmp(:,isIn);
                        UVs(:,stsind:(stsind+numPtmp-1))=UVtmp(:,isIn);
                        nrmls(1,stsind:(stsind+numPtmp-1))=ParameterData{entiall}.a;
                        nrmls(2,stsind:(stsind+numPtmp-1))=ParameterData{entiall}.b;
                        nrmls(3,stsind:(stsind+numPtmp-1))=ParameterData{entiall}.c;
                        srfinds(:,stsind:(stsind+numPtmp-1))=entiall*ones(1,numPtmp);
                        stsind=stsind+numPtmp;
                    end
                    
                end
                
            else
                if and(ParameterData{entiall}.previous_type==120,ParameterData{entiall}.well)
                    
                    ntest=70;
                    
                    Pu=nrbSrfRegularEvalIGES(ParameterData{entiall}.nurbs,ParameterData{i}.u(1),ParameterData{i}.u(2),ntest,ParameterData{i}.v(1),ParameterData{i}.v(2),2);
                    Pv=nrbSrfRegularEvalIGES(ParameterData{entiall}.nurbs,ParameterData{i}.u(1),ParameterData{i}.u(2),2,ParameterData{i}.v(1),ParameterData{i}.v(2),ntest);
                    
                    if or(any(isInside(Pu,pdir,sdir,refPpdir,refPsdir,deltap,deltas)),any(isInside(Pv,pdir,sdir,refPpdir,refPsdir,deltap,deltas)))
                        
                        le(1)=round(crvdensity*sum(sqrt(sum((Pu(:,2:ntest)-Pu(:,1:(ntest-1))).^2,1))));
                        le(3)=round(crvdensity*sum(sqrt(sum((Pu(:,(ntest+2):(2*ntest))-Pu(:,(ntest+1):(2*ntest-1))).^2,1))));
                        
                        le(2)=round(crvdensity*sum(sqrt(sum((Pv(:,4:2:(2*ntest))-Pv(:,2:2:(2*ntest-2))).^2,1))));
                        le(4)=round(crvdensity*sum(sqrt(sum((Pv(:,3:2:(2*ntest-1))-Pv(:,1:2:(2*ntest-3))).^2,1))));
                        
                        for j=1:4
                            if le(j)>0
                                
                                if j==1
                                    UVtmp=[linspace(ParameterData{i}.u(1),ParameterData{i}.u(2)-(ParameterData{i}.u(2)-ParameterData{i}.u(1))/le(1),le(1));ParameterData{i}.v(1)*ones(1,le(1))];
                                    [Ptmp,Ptmpu,Ptmpv]=nrbevalIGES(ParameterData{entiall}.nurbs,UVtmp,ParameterData{entiall}.dnurbs);
                                    dirstmp=Ptmpu;
                                elseif j==2
                                    UVtmp=[ParameterData{i}.u(2)*ones(1,le(2));linspace(ParameterData{i}.v(1),ParameterData{i}.v(2)-(ParameterData{i}.v(2)-ParameterData{i}.v(1))/le(2),le(2))];
                                    [Ptmp,Ptmpu,Ptmpv]=nrbevalIGES(ParameterData{entiall}.nurbs,UVtmp,ParameterData{entiall}.dnurbs);
                                    dirstmp=Ptmpv;
                                elseif j==3
                                    UVtmp=[linspace(ParameterData{i}.u(2),ParameterData{i}.u(1)+(ParameterData{i}.u(2)-ParameterData{i}.u(1))/le(3),le(3));ParameterData{i}.v(2)*ones(1,le(3))];
                                    [Ptmp,Ptmpu,Ptmpv]=nrbevalIGES(ParameterData{entiall}.nurbs,UVtmp,ParameterData{entiall}.dnurbs);
                                    dirstmp=-Ptmpu;
                                else
                                    UVtmp=[ParameterData{i}.u(1)*ones(1,le(4));linspace(ParameterData{i}.v(2),ParameterData{i}.v(1)+(ParameterData{i}.v(2)-ParameterData{i}.v(1))/le(4),le(4))];
                                    [Ptmp,Ptmpu,Ptmpv]=nrbevalIGES(ParameterData{entiall}.nurbs,UVtmp,ParameterData{entiall}.dnurbs);
                                    dirstmp=-Ptmpv;
                                end
                                
                                isIn=isOnto(Ptmp,i,normal,pdir,sdir,np,ns,dp,deltap,deltas,refPpdir,refPsdir,modelnormalmin,modelnormalmax,srfind);
                                numPtmp=sum(isIn);
                                
                                if numPtmp>0
                                    srfbounds(:,stind:(stind+numPtmp-1))=Ptmp(:,isIn);
                                    UVb(:,stind:(stind+numPtmp-1))=UVtmp(:,isIn);
                                    nrmlb(1,stind:(stind+numPtmp-1))=Ptmpu(2,isIn).*Ptmpv(3,isIn)-Ptmpu(3,isIn).*Ptmpv(2,isIn);
                                    nrmlb(2,stind:(stind+numPtmp-1))=Ptmpu(3,isIn).*Ptmpv(1,isIn)-Ptmpu(1,isIn).*Ptmpv(3,isIn);
                                    nrmlb(3,stind:(stind+numPtmp-1))=Ptmpu(1,isIn).*Ptmpv(2,isIn)-Ptmpu(2,isIn).*Ptmpv(1,isIn);
                                    dirb(:,stind:(stind+numPtmp-1))=dirstmp(:,isIn);
                                    srfindb(:,stind:(stind+numPtmp-1))=i*ones(1,numPtmp);
                                    stind=stind+numPtmp;
                                end
                                
                            end
                        end
                        
                        % Srf points
                        
                        nuv=25;
                        [P,UVons,TRI]=nrbSrfRegularEvalIGES(ParameterData{entiall}.nurbs,ParameterData{i}.u(1),ParameterData{i}.u(2),nuv,ParameterData{i}.v(1),ParameterData{i}.v(2),nuv);
                        
                        [UVtmp,Ptmp,Ptmpu,Ptmpv]=getSurfaceDistributedPoints(P,UVons,TRI,srfsdensity,ParameterData{i}.nurbs,ParameterData{i}.dnurbs,ParameterData{i}.d2nurbs);
                        
                        isIn=isOnto(Ptmp,i,normal,pdir,sdir,np,ns,dp,deltap,deltas,refPpdir,refPsdir,modelnormalmin,modelnormalmax,srfind);
                        numPtmp=sum(isIn);
                        
                        if numPtmp>0
                            srfs(:,stsind:(stsind+numPtmp-1))=Ptmp(:,isIn);
                            UVs(:,stsind:(stsind+numPtmp-1))=UVtmp(:,isIn);
                            nrmls(1,stsind:(stsind+numPtmp-1))=Ptmpu(2,isIn).*Ptmpv(3,isIn)-Ptmpu(3,isIn).*Ptmpv(2,isIn);
                            nrmls(2,stsind:(stsind+numPtmp-1))=Ptmpu(3,isIn).*Ptmpv(1,isIn)-Ptmpu(1,isIn).*Ptmpv(3,isIn);
                            nrmls(3,stsind:(stsind+numPtmp-1))=Ptmpu(1,isIn).*Ptmpv(2,isIn)-Ptmpu(2,isIn).*Ptmpv(1,isIn);
                            srfinds(:,stsind:(stsind+numPtmp-1))=i*ones(1,numPtmp);
                            stsind=stsind+numPtmp;
                        end
                        
                    end
                    
                end
            end
            
        end
        
    end
    
    vecsnorm=sqrt(sum(nrmlb.^2,1));
    nrmlb(1,:)=nrmlb(1,:)./vecsnorm;
    nrmlb(2,:)=nrmlb(2,:)./vecsnorm;
    nrmlb(3,:)=nrmlb(3,:)./vecsnorm;
    
    vecsnorm=sqrt(sum(dirb.^2,1));
    dirb(1,:)=dirb(1,:)./vecsnorm;
    dirb(2,:)=dirb(2,:)./vecsnorm;
    dirb(3,:)=dirb(3,:)./vecsnorm;
    
    vecsnorm=sqrt(sum(nrmls.^2,1));
    nrmls(1,:)=nrmls(1,:)./vecsnorm;
    nrmls(2,:)=nrmls(2,:)./vecsnorm;
    nrmls(3,:)=nrmls(3,:)./vecsnorm;
    
end


function isIn=isInside(P,pdir,sdir,refPpdir,refPsdir,deltap,deltas)

vec=pdir'*P-refPpdir;

isIn=and(vec>=0,vec<=deltap);

vec=sdir'*P-refPsdir;

isIn=and(isIn,and(vec>=0,vec<=deltas));


function isOn=isOnto(P,Psrfind,normal,pdir,sdir,np,ns,dp,deltap,deltas,refPpdir,refPsdir,modelnormalmin,modelnormalmax,srfind)

vec=pdir'*P-refPpdir;

isOn=and(vec>0,vec<deltap);

intp=floor(vec/dp);

vec=sdir'*P-refPsdir;

isOn=and(isOn,and(vec>0,vec<deltas));

ints=floor(vec/dp);

for i=1:length(isOn)
    if isOn(i)
        nsip=ns*intp(i);
        
        if srfind(1+ints(i)+nsip)~=Psrfind
            if srfind(2+ints(i)+nsip)~=Psrfind
                nsip=nsip+ns;
                if srfind(1+ints(i)+nsip)~=Psrfind
                    if srfind(2+ints(i)+nsip)~=Psrfind
                        normalPi=normal'*P(:,i);
                        if normalPi<modelnormalmin(ints(i)+1,intp(i)+1)
                            isOn(i)=false;
                        elseif normalPi>modelnormalmax(ints(i)+1,intp(i)+1)
                            isOn(i)=false;
                        end
                    end
                end
            end
        end
        
    end
end


function [rCrv,rDCrv]=retCrvD(ParameterData,ind,n,dim)

if ParameterData{ind}.type==142
    
    if dim==2
        [rCrv,rDCrv]=retCrvD(ParameterData,ParameterData{ind}.bptr,n,dim);
    else
        [rCrv,rDCrv]=retCrvD(ParameterData,ParameterData{ind}.cptr,n,dim);
    end
    
elseif ParameterData{ind}.type==102
    
    nvecF=(n/(ParameterData{ind}.length))*(ParameterData{ind}.lengthcnt);
    nvecI=floor(nvecF);
    
    numzero=sum(nvecI==0);
    nrest=n-sum(nvecI);
    
    if numzero>0
        [so,in]=sort(nvecF);
        if nrest<numzero
            nvecI(in((numzero-nrest+1):numzero))=1;
        else
            nvecI(in(1:numzero))=1;
            nrest=nrest-numzero;
            if nrest>0
                nvecre=nvecI-nvecF;
                [so,in]=sort(nvecre);
                nvecI(in(1:nrest))=nvecI(in(1:nrest))+1;
            end
        end
    else
        if nrest>0
            nvecre=nvecI-nvecF;
            [so,in]=sort(nvecre);
            nvecI(in(1:nrest))=nvecI(in(1:nrest))+1;
        end
    end
    
    rCrv=zeros(dim,n);
    rDCrv=zeros(dim,n);
    
    stind=1;
    for i=1:(ParameterData{ind}.n)
        if nvecI(i)>0
            endind=stind+nvecI(i)-1;
            [rCrv(:,stind:endind),rDCrv(:,stind:endind)]=retCrvD(ParameterData,ParameterData{ind}.de(i),nvecI(i),dim);
            stind=endind+1;
        end
    end
    
elseif ParameterData{ind}.type==110
    
    if n>1
        rCrv=zeros(dim,n);
        rDCrv=zeros(dim,n);
        
        tvec=linspace(0,(1-1/n),n);
        
        dir=ParameterData{ind}.p2-ParameterData{ind}.p1;
        
        rCrv(1,:)=ParameterData{ind}.x1+tvec*dir(1);
        rCrv(2,:)=ParameterData{ind}.y1+tvec*dir(2);
        rDCrv(1,:)=dir(1);
        rDCrv(2,:)=dir(2);
        if dim>2
            rCrv(3,:)=ParameterData{ind}.z1+tvec*dir(3);
            rDCrv(3,:)=dir(3);
        end
    elseif n==1
        dir=ParameterData{ind}.p2-ParameterData{ind}.p1;
        rCrv=ParameterData{ind}.p1(1:dim);
        rDCrv=dir(1:dim);
    else
        rCrv=zeros(dim,0);
        rDCrv=zeros(dim,0);
    end
    
elseif ParameterData{ind}.type==126
    
    if n>1
        tst=ParameterData{ind}.v(1);
        ten=ParameterData{ind}.v(2);
        
        tvec=linspace(tst,ten-(ten-tst)/n,n);
        
        if dim>2
            [rCrv,rDCrv]=nrbevalIGES(ParameterData{ind}.nurbs,tvec,ParameterData{ind}.dnurbs);
        else
            [rCrv3,rDCrv3]=nrbevalIGES(ParameterData{ind}.nurbs,tvec,ParameterData{ind}.dnurbs);
            rCrv=rCrv3(1:2,:);
            rDCrv=rDCrv3(1:2,:);
        end
    elseif n==1
        tst=ParameterData{ind}.v(1);
        if dim>2
            [rCrv,rDCrv]=nrbevalIGES(ParameterData{ind}.nurbs,tst,ParameterData{ind}.dnurbs);
        else
            [rCrv3,rDCrv3]=nrbevalIGES(ParameterData{ind}.nurbs,tst,ParameterData{ind}.dnurbs);
            rCrv=rCrv3(1:2);
            rDCrv=rDCrv3(1:2);
        end
    else
        rCrv=zeros(dim,0);
        rDCrv=zeros(dim,0);
    end
    
else
    rCrv=zeros(dim,0);
    rDCrv=zeros(dim,0);
end
