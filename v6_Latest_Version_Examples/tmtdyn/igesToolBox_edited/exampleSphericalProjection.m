% exampleSphericalProjection.m plots an IGES CAD-object and project points on its surface

% Compile the c-files (if necessary)
% makeIGESmex;

% Load parameter data from IGES-file.
[ParameterData,EntityType,numEntityType,unknownEntityType,numunknownEntityType]=iges2matlab('IGESfiles/example.igs');

% Project a set of points in a regular grid on the surface

% Projection data

R=[2000;-1300;0];   % Spherical projection origin
normal=[2;8;-3.2];  % Direction of projection
normal=normal/norm(normal);
pdir=randn(3,1);    % First (primary) direction
pdir=pdir-dot(pdir,normal)*normal;
pdir=pdir/norm(pdir);
sdir=cross(pdir,normal); % Second (secondary) direction
sdir=sdir/norm(sdir);

dtheta=1.4*pi/180; % Angle difference
nppos=10; % Number of positive grids in primary direction
npneg=11; % Number of negative grids in primary direction
nspos=13; % Number of positive grids in secondary direction
nsneg=14; % Number of negative grids in secondary direction

% Do the projection
[model,UV,srfind,srfDerivind,srfDer,numpoints,distR]=projpartSphericalIGES(ParameterData,R,normal,pdir,sdir,dtheta,nppos,npneg,nspos,nsneg);

% Plots

% Plot the IGES object
figno=1;
plotIGES(ParameterData,1,figno,[],0);

Pnts=zeros(3,(npneg+1+nppos)*(nsneg+1+nspos));

ind=0;
for i=-npneg:nppos
    for j=-nsneg:nspos
        ind=ind+1;
        Pnts(:,ind)=R+370*(cos(i*dtheta)*sin(pi/2+j*dtheta)*normal+sin(i*dtheta)*sin(pi/2+j*dtheta)*pdir+cos(pi/2+j*dtheta)*sdir);
    end
end

plot3(Pnts(1,:),Pnts(2,:),Pnts(3,:),'.','Color',[0.1 0.5 0.4]);

% Plot normal, starting at grid origin
lines=[R R+370*normal];
plot3(lines(1,:),lines(2,:),lines(3,:),'r-');

% Plot pdir, starting at grid origin
lines=[R R+370*pdir];
plot3(lines(1,:),lines(2,:),lines(3,:),'g-');

% Plot sdir, starting at grid origin
lines=[R R+370*sdir];
plot3(lines(1,:),lines(2,:),lines(3,:),'b-');

% Plot projected points
plot3(model(1,srfind>0),model(2,srfind>0),model(3,srfind>0),'.','Color',[0.0 0.8 0.8]);

axis auto

hold off;
