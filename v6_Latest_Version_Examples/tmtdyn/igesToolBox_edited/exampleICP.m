% exampleICP.m plots an IGES CAD-object and project points on its surface

% Compile the c-files (if necessary)
% makeIGESmex;

getMODEL=true;
%getMODEL=false;

if getMODEL
    
    % Load parameter data from IGES-file.
    [ParameterData,EntityType,numEntityType,unknownEntityType,numunknownEntityType]=iges2matlab('IGESfiles/piece.igs');
    
    % Project a set of points in a regular grid on the surface
    
    % Projection data
    
    R=[50;0;12.5]; % Grid origin
    normal=[-1;1;-1]; % Direction of projection
    normal=normal/norm(normal);
    pdir=randn(3,1); % First (primary) direction of grid
    pdir=pdir-dot(pdir,normal)*normal;
    pdir=pdir/norm(pdir);
    sdir=cross(pdir,normal); % Second (secondary) direction of grid
    sdir=sdir/norm(sdir);
    
    dp=0.2;  % Grid spacing
    nppos=25; % Number of positive grids in primary direction
    npneg=25; % Number of negative grids in primary direction
    nspos=25; % Number of positive grids in secondary direction
    nsneg=25; % Number of negative grids in secondary direction
    
    % Do the projection
    [model,UV,srfind,srfDerivind,srfDer,numpoints]=projpartIGES(ParameterData,R,normal,pdir,sdir,dp,nppos,npneg,nspos,nsneg);
    
    dpfactor=3;
    dpsfactor=5;
    
    [nrmlmodel,srfb,UVb,nrmlb,dirb,srfindb,srfs,UVs,nrmls,srfinds]=srfRepInProjection(ParameterData,R,normal,pdir,sdir,dp,nppos,npneg,nspos,nsneg,model,UV,srfind,dpfactor,dpsfactor);
    
    % Prepare for the ICP algorithm
    tol=1e-2;
    maxl=0.5*dp;
    
    [dir1model,dir2model,ldirmodel,dir1s,dir2s,ldirs,dir1b,dir2b,ldirb]=linAppSrfIGES(ParameterData,model,UV,srfind,srfs,UVs,srfinds,srfb,UVb,srfindb,dirb,nrmlb,tol,maxl);
    
    [MODEL,DIRVEC,MINDIRsq,MNORMAL,SURFDATA]=icpSrfLinRep(model,nrmlmodel,srfind,srfs,nrmls,srfb,nrmlb,dir1model,dir2model,ldirmodel,dir1s,dir2s,ldirs,dir1b,dir2b,ldirb);
    
    % Reference
    %
    % Authors: Per Bergström, Ove Edlund, and Inge Söderkvist
    % Title: Repeated surface registration for on-line use
    % Journal: The International Journal of Advanced Manufacturing Technology
    % Cover Date: 2011-05-01
    % Publisher: Springer London
    % Issn: 0268-3768
    % Pages: 677-689
    % Volume: 54
    % Issue: 5
    % Url: http://dx.doi.org/10.1007/s00170-010-2950-6
    % Doi: 10.1007/s00170-010-2950-6
    %
    % Springer Nature’s SharedIt links (full paper online access):   http://rdcu.be/nJUW
    
    gridSpacingL0=1.0;
    newGridsMaxDist=[1.5,0.5,0.2];
    Nvertex=[3,4,3];
    
    DVGdata=getDVGtree(normal,pdir,sdir,MODEL,DIRVEC,MINDIRsq,MNORMAL,gridSpacingL0,newGridsMaxDist,Nvertex);
    
end

% Generate data points from the model points
alph1=(2*rand-1)*20*(pi/180);
alph2=(2*rand-1)*20*(pi/180);
alph3=(2*rand-1)*20*(pi/180);

theRotation=[cos(alph1) sin(alph1) 0;-sin(alph1) cos(alph1) 0;0 0 1];
theRotation=theRotation*[cos(alph2) 0 sin(alph2);0 1 0;-sin(alph2) 0 cos(alph2)];
theRotation=theRotation*[1 0 0;0 cos(alph3) sin(alph3);0 -sin(alph3) cos(alph3)];
theTranslation=10*(rand(3,1)-0.5)+R-theRotation*R;

data=theRotation*MODEL;
data(1,:)=data(1,:)+theTranslation(1);
data(2,:)=data(2,:)+theTranslation(2);
data(3,:)=data(3,:)+theTranslation(3);

quality=ones(1,size(data,2));
quality=quality/sum(quality);

% Use all the data points
quasirand=uint32(randperm(size(data,2))-1);
sizerand=size(data,2);
randincreasing=0;

% The number of iterations
maxiter=uint32(30);

% Initiate transformation
Rotation=eye(3);
Translation=zeros(3,1);


% Run the ICP algorithm

% Point to point minimization
% icpDVGpnt2pntLS(data,quality,quasirand,sizerand,randincreasing,maxiter,SURFDATA,DVGdata,Rotation,Translation);

% Point to plane minimization
% icpDVGpnt2plnLS(data,quality,quasirand,sizerand,randincreasing,maxiter,SURFDATA,DVGdata,Rotation,Translation);

% Use Tukey's criterion function
kTu=20;

% Point to point minimization
% icpDVGpnt2pntTu(data,quality,quasirand,sizerand,randincreasing,maxiter,kTu,SURFDATA,DVGdata,Rotation,Translation);

% Point to plane minimization
icpDVGpnt2plnTu(data,quality,quasirand,sizerand,randincreasing,maxiter,kTu,SURFDATA,DVGdata,Rotation,Translation);



% References:
% 
% [Bergström & Edlund 2014]
% 
% Bergström, P. and Edlund, O. 2014, “Robust registration of point sets using iteratively reweighted least squares”,
% Computational Optimization and Applications, vol 58, no. 3, pp. 543-561, doi: 10.1007/s10589-014-9643-2
% 
% 
% [Bergström & Edlund (2016) 2017]
% 
% Bergström, P. and Edlund, O. (2016) 2017, “Robust registration of surfaces using a refined iterative closest point algorithm 
% with a trust region approach”, Numerical Algorithms, doi: 10.1007/s11075-016-0170-3
% 
% 
% [Bergström 2016]
% 
% Bergström, P. 2016, “Reliable updates of the transformation in the iterative closest point algorithm”,
% Computational Optimization and Applications, vol 63, no. 2, pp. 543-557, doi: doi:10.1007/s10589-015-9771-3
% 
% 
% Doi links:
% 
% http://dx.doi.org/10.1007/s10589-014-9643-2
% 
% http://dx.doi.org/10.1007/s11075-016-0170-3
% 
% http://dx.doi.org/10.1007/s10589-015-9771-3
% 
% 
% Springer Nature’s SharedIt links (full paper online access):
% 
% http://rdcu.be/nJRM
% 
% http://rdcu.be/noHE
% 
% http://rdcu.be/nJRV
% 
% 
% YouTube: Real time 3D shape analysis by comparing point cloud with CAD-model
% 
% Examples where an ICP-algorithm is used can be seen on YouTube,
% 
% https://youtu.be/lm7_mwpOk0E
% 
% https://youtu.be/cPS-DY9sCz4
% 
% 
% A demonstration of shape matching, shape comparison, and shape identification is presented.



% Transform the data points
data2=Rotation*data;
data2(1,:)=data2(1,:)+Translation(1);
data2(2,:)=data2(2,:)+Translation(2);
data2(3,:)=data2(3,:)+Translation(3);


% Plots

% Plot the IGES object
figno=1;
hplot=plotIGES(ParameterData,1,figno,[],0);
set(hplot{3},'FaceAlpha',0.4);

% Plot the original data points
plot3(data(1,:),data(2,:),data(3,:),'r.');

% Plot the transformed data points
plot3(data2(1,:),data2(2,:),data2(3,:),'c.');

hold off;
