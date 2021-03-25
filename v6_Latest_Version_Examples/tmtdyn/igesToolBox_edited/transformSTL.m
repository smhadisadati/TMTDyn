function VertexData=transformSTL(VertexData,R,T)
% TRANSFORMSTL transform vertices in VertexData from a STL file
% using a rotation or a reflection and a translation.
%
% Usage:
%
% VertexData=transformSTL(VertexData,R,T)
%
% Input:
%
% VertexData - Vertex data from STL file. VertexData
%                 is the output from STL2MATLAB.
% R - Rotation/reflection matrix. eye(3) default.
% T - Translation vector. zeros(3,1) default.
%
% Output:
%
% VertexData - Transformed vertex data.
%
% vertex=R*vertex+T
%
% m-file can be downloaded at
% http://www.mathworks.com/matlabcentral/fileexchange/13253-iges-toolbox
%
% written by Per Bergström 2012-02-16
%

if nargin<3
    T=zeros(3,1);
    if nargin<2
        R=eye(3);
        if nargin <1
            error('transformSTL must have inputs!');
        end
    end
end

if not(iscell(VertexData))
    error('VertexData must be a cell array!');
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


for i=1:3
    
    P=R*[VertexData{1}(i,:);VertexData{2}(i,:);VertexData{3}(i,:)];
    
    VertexData{1}(i,:)=P(1,:)+T(1);
    VertexData{2}(i,:)=P(2,:)+T(2);
    VertexData{3}(i,:)=P(3,:)+T(3);
    
end
