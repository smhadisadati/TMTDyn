function [UVout,Pout,Puout,Pvout]=getSurfaceDistributedPoints(P,UV,TRI,srfsdensity,nurbs,dnurbs,d2nurbs,numTimes)
% getSurfaceDistributedPoints returns points distibuted on a surfaces in a
% given triangular mesh
%
% Usage:
%
% [UVout,Pout,Puout,Pvout]=getSurfaceDistributedPoints(P,UV,TRI,srfsdensity,nurbs,dnurbs,d2nurbs,numTimes)
%
% Input:
%
% P - Vertices in 3D of triagular mesh
% UV - Parameter values of P
% TRI - Triangular mesh
% srfsdensity - If positive, number of new points per square units,
%               if negative, number of new points
% nurbs - (optional) NURBS surface
% dnurbs - (optional) NURBS surface derivative (output from nrbDerivativesIGES)
% d2nurbs - (optional) NURBS surface second derivative (output from nrbDerivativesIGES)
% numTimes - (optional) A number greater than 1 which describes the share
%             of extra/discarded points. A larger value of numTimes gives surface points
%             distributed where the curvature is high
%
% Output:
%
% UVout - Parameter values of output points
% Pout - Points
% Puout - first parameter derivatives
% Pvout - second parameter derivatives
%
% m-file can be downloaded at
% http://www.mathworks.com/matlabcentral/fileexchange/13253-iges-toolbox
%
% written by Per Bergström 2012-04-24
%

if srfsdensity==0
    srfsdensity=-1;
end

if nargin<7
    
    mTRI=size(TRI,1);
    areavec=zeros(mTRI,1);
    
    vec1=zeros(3,1);
    vec2=zeros(3,1);
    
    vec1(:)=P(:,TRI(1,2))-P(:,TRI(1,1));
    vec2(:)=P(:,TRI(1,3))-P(:,TRI(1,1));
    areavec(1)=0.5*norm(cross(vec1,vec2));
    
    [basPuPv,tmp]=qr([vec1 vec2],0);
    
    clear tmp
    
    for i=2:mTRI
        vec1(:)=P(:,TRI(i,2))-P(:,TRI(i,1));
        vec2(:)=P(:,TRI(i,3))-P(:,TRI(i,1));
        areavec(i)=0.5*norm(cross(vec1,vec2));
    end
    
    if srfsdensity>0
        numUV=areavec*srfsdensity;
    else
        numUV=areavec*(-srfsdensity/sum(areavec));
    end
    
    numUVtot=ceil(sum(numUV));
    
    numUVrem=cumsum(numUV-floor(numUV));
    numUVrem=numUVrem/numUVrem(mTRI);
    
    numUV=floor(numUV);
    
    numUVremtot=numUVtot-sum(numUV);
    
    rndvec=sort(rand(1,numUVremtot));
    
    stind=1;
    for i=1:numUVremtot
        for j=stind:mTRI
            if numUVrem(j)>=rndvec(i)
                numUV(j)=numUV(j)+1;
                stind=j;
                break
            end
        end
    end
    
    UVout=zeros(2,numUVtot);
    Pout=zeros(3,numUVtot);
    
    if nargout>2
        Puout=zeros(3,numUVtot);
        Pvout=zeros(3,numUVtot);
        
        Puout(1,:)=basPuPv(1,1);
        Puout(2,:)=basPuPv(2,1);
        Puout(3,:)=basPuPv(3,1);
        
        Pvout(1,:)=basPuPv(1,2);
        Pvout(2,:)=basPuPv(2,2);
        Pvout(3,:)=basPuPv(3,2);
    end
    
    vec1uv=zeros(2,1);
    vec2uv=zeros(2,1);
    
    stind=0;
    
    for i=1:mTRI
        if numUV(i)>0
            vec1uv(:)=UV(:,TRI(i,2))-UV(:,TRI(i,1));
            vec2uv(:)=UV(:,TRI(i,3))-UV(:,TRI(i,1));
            
            vec1(:)=P(:,TRI(i,2))-P(:,TRI(i,1));
            vec2(:)=P(:,TRI(i,3))-P(:,TRI(i,1));
            for j=1:numUV(i)
                rnd1=rand;
                rnd2=rand;
                if rnd1+rnd2>1
                    UVout(:,stind+j)=UV(:,TRI(i,1))+(1-rnd1)*vec1uv+(1-rnd2)*vec2uv;
                    Pout(:,stind+j)=P(:,TRI(i,1))+(1-rnd1)*vec1+(1-rnd2)*vec2;
                else
                    UVout(:,stind+j)=UV(:,TRI(i,1))+rnd1*vec1uv+rnd2*vec2uv;
                    Pout(:,stind+j)=P(:,TRI(i,1))+rnd1*vec1+rnd2*vec2;
                end
            end
            stind=stind+numUV(i);
        end
    end
    
else
    
    if nargin<8
        numTimes=1.8;
    end
    if numTimes<1
        numTimes=1;
    end
    
    mTRI=size(TRI,1);
    areavec=zeros(mTRI,1);
    
    vec1=zeros(3,1);
    vec2=zeros(3,1);
    
    for i=1:mTRI
        vec1(:)=P(:,TRI(i,2))-P(:,TRI(i,1));
        vec2(:)=P(:,TRI(i,3))-P(:,TRI(i,1));
        areavec(i)=0.5*norm(cross(vec1,vec2));
    end
    
    if srfsdensity>0
        numUV=(numTimes*srfsdensity)*areavec;
    else
        numUV=areavec*(-numTimes*srfsdensity/sum(areavec));
    end
    
    numUVtot=ceil(sum(numUV));
    
    numUVrem=cumsum(numUV-floor(numUV));
    numUVrem=numUVrem/numUVrem(mTRI);
    
    numUV=floor(numUV);
    
    numUVremtot=numUVtot-sum(numUV);
    
    rndvec=sort(rand(1,numUVremtot));
    
    stind=1;
    for i=1:numUVremtot
        for j=stind:mTRI
            if numUVrem(j)>=rndvec(i)
                numUV(j)=numUV(j)+1;
                stind=j;
                break
            end
        end
    end
    
    UVout=zeros(2,numUVtot);
    
    vec1uv=zeros(2,1);
    vec2uv=zeros(2,1);
    
    stind=0;
    
    for i=1:mTRI
        if numUV(i)>0
            vec1uv(:)=UV(:,TRI(i,2))-UV(:,TRI(i,1));
            vec2uv(:)=UV(:,TRI(i,3))-UV(:,TRI(i,1));
            
            for j=1:numUV(i)
                rnd1=rand;
                rnd2=rand;
                if rnd1+rnd2>1
                    UVout(:,stind+j)=UV(:,TRI(i,1))+(1-rnd1)*vec1uv+(1-rnd2)*vec2uv;
                else
                    UVout(:,stind+j)=UV(:,TRI(i,1))+rnd1*vec1uv+rnd2*vec2uv;
                end
            end
            stind=stind+numUV(i);
        end
    end
    
    crvValVec=zeros(1,numUVtot);

    for i=1:numUVtot
        crvValVec(i)=getCurvatureVal(UVout(:,i),nurbs,dnurbs,d2nurbs)*rand;
    end

    [vals,soind]=sort(crvValVec);
    
    UVout=UVout(:,soind(max(floor(numUVtot*(numTimes-1)/(numTimes)),1):end));
    
    if nargout>2
        [Pout,Puout,Pvout]=nrbevalIGES(nurbs,UVout,dnurbs);
    elseif nargout>1
        Pout=nrbevalIGES(nurbs,UVout);
    end
    
end


function crvVal=getCurvatureVal(UV,nurbs,dnurbs,d2nurbs)

% NURBS evaluation
[P,Su,Sv,Suu,Suv,Svv]=nrbevalIGES(nurbs,UV,dnurbs,d2nurbs);

Eu=norm(Su);
Su=Su/Eu;

Ev=norm(Sv);
Sv=Sv/Ev;

normal=cross(Su,Sv);
normal=normal/norm(normal);

% quadratic function of z*normal dependent of x*Su and y*Su
% z=a*x^2+b*y^2+c*x*y

a=dot(Suu,normal)/(2*Eu^2);
b=dot(Svv,normal)/(2*Ev^2);
c=dot(Suv,normal)/(Eu*Ev);

% Orthonormal basis

So=Sv-dot(Su,Sv)*Su;

Eo=norm(So);

transfMat=[1 -dot(Su,Sv)/Eo;0 1/Eo];

% quadratic matrix

quadMat=transfMat'*[a 0.5*c;0.5*c b]*transfMat;

crvVal=sqrt(min(max(abs(eig(quadMat))),8)+1);
