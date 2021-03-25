% examplePerspectiveProjection.m plots an IGES CAD-object and project points on its surface

% Compile the c-files (if necessary)
% makeIGESmex;

% Load parameter data from IGES-file.
[ParameterData,EntityType,numEntityType,unknownEntityType,numunknownEntityType]=iges2matlab('IGESfiles/example.igs');

% Project a set of points in a perspective plane onto the surface

% Projection data

R=[2000;-1300;0];  % The perspective projection origin, eye position
normal=[2;8;-2.5]; % Direction of projection
normal=normal/norm(normal);
pdir=randn(3,1);   % First (primary) direction of grid
pdir=pdir-dot(pdir,normal)*normal;
pdir=pdir/norm(pdir);
sdir=cross(pdir,normal); % Second (secondary) direction of grid
sdir=sdir/norm(sdir);

pointO=[2002;-1292;-3.5];
dPerspParam=8e-3;
np=35;
ns=25;

% Do the projection
[model,UV,srfind,srfDerivind,srfDer,distR,pointOref]=projpartPerspectiveIGES(ParameterData,R,normal,pdir,sdir,pointO,dPerspParam,np,ns);


% Plots of everything

% Plot the IGES object
figno=1;
plotIGES(ParameterData,1,figno,[],0);

Pnts=zeros(3,np*ns);

ind=0;
for i=1:np
    for j=1:ns
        ind=ind+1;
        Pnts(:,ind)=pointOref+(i-1)*dPerspParam*pdir+(j-1)*dPerspParam*sdir;
    end
end

plot3(Pnts(1,:),Pnts(2,:),Pnts(3,:),'.','Color',[0.1 0.5 0.4]);

% Plot normal, starting at grid origin
lines=[R R+5e4*dPerspParam*normal];
plot3(lines(1,:),lines(2,:),lines(3,:),'r-');

% Plot pdir, starting at grid origin
lines=[R R+5e4*dPerspParam*pdir];
plot3(lines(1,:),lines(2,:),lines(3,:),'g-');

% Plot sdir, starting at grid origin
lines=[R R+5e4*dPerspParam*sdir];
plot3(lines(1,:),lines(2,:),lines(3,:),'b-');

% Plot projected points
plot3(model(1,srfind>0),model(2,srfind>0),model(3,srfind>0),'.','Color',[0.0 0.8 0.8]);

axis auto

hold off;
