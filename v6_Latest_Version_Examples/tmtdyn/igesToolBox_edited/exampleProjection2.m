% exampleProjection2.m plots an IGES CAD-object and project points on its surface

% Compile the c-files (if necessary)
% makeIGESmex;

% Load parameter data from IGES-file.
[ParameterData,EntityType,numEntityType,unknownEntityType,numunknownEntityType]=iges2matlab('IGESfiles/srfOfRev.igs');

% Project a set of points in a regular grid on the surface

% Projection data

R=[0;6;8]; % Grid origin
normal=[-0.1;-0.1;-1]; % Direction of projection
normal=normal/norm(normal);
pdir=randn(3,1); % First (primary) direction of grid
pdir=pdir-dot(pdir,normal)*normal;
pdir=pdir/norm(pdir);
sdir=cross(pdir,normal); % Second (secondary) direction of grid
sdir=sdir/norm(sdir);

dp=0.3;  % Grid spacing
nppos=5; % Number of positive grids in primary direction
npneg=4; % Number of negative grids in primary direction
nspos=4; % Number of positive grids in secondary direction
nsneg=3; % Number of negative grids in secondary direction

% Do the projection
[model,UV,srfind,srfDerivind,srfDer,numpoints]=projpartIGES(ParameterData,R,normal,pdir,sdir,dp,nppos,npneg,nspos,nsneg);

nrmlmodel=srfRepInProjection(ParameterData,R,normal,pdir,sdir,dp,nppos,npneg,nspos,nsneg,model,UV,srfind,[],[]);


% Plots

% Plot the IGES object and points of projections
figno=1;
plotIGES(ParameterData,1,figno,[],0);

Pnts=zeros(3,(npneg+1+nppos)*(nsneg+1+nspos));

ind=0;
for i=-npneg:nppos
    for j=-nsneg:nspos
        ind=ind+1;
        Pnts(:,ind)=R+i*dp*pdir+j*dp*sdir;
    end
end

plot3(Pnts(1,:),Pnts(2,:),Pnts(3,:),'.','Color',[0.1 0.5 0.4]);

% Plot normal, starting at grid origin
lines=[R R+10*dp*normal];
plot3(lines(1,:),lines(2,:),lines(3,:),'r-');

% Plot pdir, starting at grid origin
lines=[R R+10*dp*pdir];
plot3(lines(1,:),lines(2,:),lines(3,:),'g-');

% Plot sdir, starting at grid origin
lines=[R R+10*dp*sdir];
plot3(lines(1,:),lines(2,:),lines(3,:),'b-');

% Plot projected points
plot3(model(1,srfind>0),model(2,srfind>0),model(3,srfind>0),'r.');

% Plot the surface normals
nrmlle=-0.3;
for i=1:size(model,2)
    if srfind(i)>0
        plot3([model(1,i),model(1,i)+nrmlle*nrmlmodel(1,i)],[model(2,i),model(2,i)+nrmlle*nrmlmodel(2,i)],[model(3,i),model(3,i)+nrmlle*nrmlmodel(3,i)],'-','Color',[0.8 0.0 0.8]);
    end
end

axis auto

hold off;
