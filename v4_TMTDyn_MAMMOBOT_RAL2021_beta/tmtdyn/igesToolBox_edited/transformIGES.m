function ParameterData=transformIGES(ParameterData,R,T)
% TRANSFORMIGES transform the entities from an IGES file in
% ParameterData with a rotation or a reflection and a translation.
%
% Usage:
%
% ParameterData=transformIGES(ParameterData,R,T)
%
% Input:
%
% ParameterData - Parameter data from IGES file. ParameterData
%                 is the output from IGES2MATLAB.
% R - Rotation matrix or reflection matrix. eye(3) default.
% T - Translation vector. zeros(3,1) default.
%
% Output:
%
% ParameterData - Transformed input parameter data.
%
% ENTITY=R*ENTITY+T
%
% m-file can be downloaded at
% http://www.mathworks.com/matlabcentral/fileexchange/13253-iges-toolbox
%
% written by Per Bergström 2009-12-04
%

if nargin<3
    T=zeros(3,1);
    if nargin<2
        R=eye(3);
        if nargin <1
            error('transformIGES must have inputs!');
        end
    end
end

if not(iscell(ParameterData))
    error('ParameterData must be a cell array!');
end

[mR,nR]=size(R);

if or(mR~=nR,mR~=3)
    mR=3;
    nR=3;
    R=eye(3);
elseif or(norm(R'*R-eye(3),'fro')>1e-12,not(or(abs(det(R)-1)<1e-12,abs(det(R)+1)<1e-12)))
    error('R must be a rotation matrix or a reflection matrix');
end

[mT,nT]=size(T);

if or(mT==0,nT==0)
    T=zeros(3,1);
elseif mT<nT
    T=T';
    [mT,nT]=size(T);
end

if or(mT~=3,nT~=1)
    T=zeros(3,1);
end

siz=length(ParameterData);

for i=1:siz
    
    % SURFACES
    
    if ParameterData{i}.type==128
        
        for j=1:(ParameterData{i}.k1+1)
            for k=1:(ParameterData{i}.k2+1)
                ParameterData{i}.p(:,j,k)=R*ParameterData{i}.p(:,j,k)+T;
            end
        end
        
        ParameterData{i}.nurbs.coefs(1:3,:,:)=repmat(ParameterData{i}.nurbs.coefs(4,:,:),3,1).*ParameterData{i}.p;
        [ParameterData{i}.dnurbs,ParameterData{i}.d2nurbs]=nrbDerivativesIGES(ParameterData{i}.nurbs);
        
    elseif ParameterData{i}.type==108
        
        ParameterData{i}.d=ParameterData{i}.d+dot(ParameterData{i}.normal,R'*T);
        
        ParameterData{i}.normal=R*ParameterData{i}.normal;
        
        ParameterData{i}.a=ParameterData{i}.normal(1);
        ParameterData{i}.b=ParameterData{i}.normal(2);
        ParameterData{i}.c=ParameterData{i}.normal(3);
        
        X=R*[ParameterData{i}.x;ParameterData{i}.y;ParameterData{i}.z]+T;
        
        ParameterData{i}.x=X(1);
        ParameterData{i}.y=X(2);
        ParameterData{i}.z=X(3);
        
        % CURVES
        
    elseif ParameterData{i}.type==126
        
        if not(ParameterData{i}.superior)
            
            for j=1:(ParameterData{i}.k+1)
                ParameterData{i}.p(:,j)=R*(ParameterData{i}.p(:,j))+T;
            end
            
            ParameterData{i}.nurbs.coefs(1:3,:)=repmat(ParameterData{i}.nurbs.coefs(4,:),3,1).*ParameterData{i}.p;
            [ParameterData{i}.dnurbs,ParameterData{i}.d2nurbs]=nrbDerivativesIGES(ParameterData{i}.nurbs);
            
        end
        
    elseif ParameterData{i}.type==110
        
        if not(ParameterData{i}.superior)
            
            ParameterData{i}.p1=R*ParameterData{i}.p1+T;
            ParameterData{i}.x1=ParameterData{i}.p1(1);
            ParameterData{i}.y1=ParameterData{i}.p1(2);
            ParameterData{i}.z1=ParameterData{i}.p1(3);
            
            ParameterData{i}.p2=R*ParameterData{i}.p2+T;
            ParameterData{i}.x2=ParameterData{i}.p2(1);
            ParameterData{i}.y2=ParameterData{i}.p2(2);
            ParameterData{i}.z2=ParameterData{i}.p2(3);
            
        end
        
        % POINTS
        
    elseif ParameterData{i}.type==116
        
        ParameterData{i}.p=R*ParameterData{i}.p+T;
        ParameterData{i}.x=ParameterData{i}.p(1);
        ParameterData{i}.y=ParameterData{i}.p(2);
        ParameterData{i}.z=ParameterData{i}.p(3);
        
    end
    
end
