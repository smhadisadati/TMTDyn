function [P,numPnt] = xyz2matlab(varargin)
% Reads an XYZ ASCII file
%
% [P,numPnt] = xyz2matlab(xyzfile,P)
% [P,numPnt] = xyz2matlab(xyzfile,numPnt)
% 
% Input arguments:
% xyzfile - the XYZ ASCII file
% P - 3xN matrix for storing xyz-data
% numPnt - expected number of xyz-points
% 
% Output arguments:
% P - 3xN matrix of xyz-data
% numPnt - number of xyz-points
%

maxNumPnt=9999999;

if nargin==1
    xyzfile=varargin{1};
    P=zeros(3,2000000,'single');
elseif nargin==2
    xyzfile=varargin{1};
    if size(varargin{2},1)==1
        numPnt=varargin{2};
        P=zeros(3,numPnt,'single');
    else
        P=single(varargin{2});
    end
else
    error('Wrong number of inputs in xyz2matlab');
end

fid=fopen(xyzfile,'r');

numPnt=0;
while and(feof(fid)==0,numPnt<maxNumPnt)
    numPnt=numPnt+1;
    P(:,numPnt)=single(sscanf(fgetl(fid),'%f',3));
end

fclose(fid);

% if numPnt<size(P,2)
%     P=P(:,1:numPnt);
% end
