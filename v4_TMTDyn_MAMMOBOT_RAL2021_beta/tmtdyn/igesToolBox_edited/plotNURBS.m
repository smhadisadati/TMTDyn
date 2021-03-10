function plotNURBS(nurbs,clr,nu,nv,plotCP)
% plotNURBS plots a NURBS entity
%
% Usage:
%
% plotNURBS(nurbs,clr,nu,nv)
%
% Input:
%
% nurbs - NURBS structure
% clr -  color of plot (optional). Default is [0.7,0.7,0.97]
%        If color is a scalar, the plot is in black and white (for surfaces, clr==0 tranparent, clr==1 opaque, clr==2 opaque)
% nu - number of evaluation points for the parameter u (optional). Default is 20 for surfaces and 200 for curves
% nv - number of evaluation points for the parameter v (optional). Default is 20
% plotCP - Boolean value (0 or 1), 1 default. If plotCP=1 the control points and
%          control net is plotted, otherwise not
%
% m-file can be downloaded at
% http://www.mathworks.com/matlabcentral/fileexchange/13253-iges-toolbox
%
% written by Per Bergström 2012-02-22
%

if nargin<1
    error('plotNURBS must have an input!');
end

if nargin<5
    plotCP=1;
end
if isempty(plotCP)
    plotCP=1;
end
if not(or(plotCP==0,plotCP==1))
    plotCP=1;
end

if length(nurbs.order)>1
    
    % NURBS surface
    
    if nargin<4
        nv=20;
        if nargin<3
            nu=20;
            if nargin<2
                clr=[0.7,0.7,0.97];
            end
        end
    end
    
    if isempty(clr)
        clr=[0.7,0.7,0.97];
    end
    if isempty(nu)
        nu=20;
    end
    if isempty(nv)
        nv=20;
    end
    
    xc=nurbs.coefs(1,:,:)./nurbs.coefs(4,:,:);
    yc=nurbs.coefs(2,:,:)./nurbs.coefs(4,:,:);
    zc=nurbs.coefs(3,:,:)./nurbs.coefs(4,:,:);
    
    if or(ischar(clr),not(isscalar(clr)))
        
        [P,UV,TRI]=nrbSrfRegularEvalIGES(nurbs,nurbs.knots{1}(1),nurbs.knots{1}(end),nu,nurbs.knots{2}(1),nurbs.knots{2}(end),nv);
        
        patch('faces',TRI,'vertices',P','FaceColor',clr,'EdgeColor','none'), hold on
        
        light
        
        if plotCP
            for i=1:nurbs.number(1)
                plot3(reshape(xc(:,i,:),1,[]),reshape(yc(:,i,:),1,[]),reshape(zc(:,i,:),1,[]),'k--');
            end
            for i=1:nurbs.number(2)
                plot3(xc(:,:,i),yc(:,:,i),zc(:,:,i),'k--');
            end
            plot3(xc(:),yc(:),zc(:),'r.','MarkerSize',10);
        end
        
    else
        
        if clr==1
            nfactor=6;
        else
            nfactor=1;
        end
        nu2=nfactor*(nu-1)+1;
        nv2=nfactor*(nv-1)+1;
        
        P=nrbSrfRegularEvalIGES(nurbs,nurbs.knots{1}(1),nurbs.knots{1}(end),nu2,nurbs.knots{2}(1),nurbs.knots{2}(end),nv2);
        
        lw=1.0;
        
        if clr==0
            indvec=1:nu2;
            for i=1:nv
                plot3(P(1,indvec+(i-1)*nfactor*nu2),P(2,indvec+(i-1)*nfactor*nu2),P(3,indvec+(i-1)*nfactor*nu2),'k-','LineWidth',lw), hold on
            end
            indvec=nu2*(0:(nv2-1))+1;
            for i=1:nu
                plot3(P(1,indvec+(i-1)*nfactor),P(2,indvec+(i-1)*nfactor),P(3,indvec+(i-1)*nfactor),'k-','LineWidth',lw), hold on
            end
        elseif clr==1
            QUA=zeros((nu-1)*(nv-1),4*nfactor);
            QUArow=zeros(1,4*nfactor);
            for j=1:(nv-1)
                for i=1:(nu-1)
                    QUArow(:)=[(i-1+nu2*(j-1))*nfactor+(1:nfactor),(i+nu2*(j-1))*nfactor+1+(1:nfactor)*nu2-nu2,(i+nu2*j)*nfactor+2-(1:nfactor),(i-1+nu2*j)*nfactor+1-(1:nfactor)*nu2+nu2];
                    QUA(i+(j-1)*(nu-1),:)=[QUArow(2:end),QUArow(1)];
                end
            end
            patch('faces',QUA,'vertices',P','FaceColor','w','FaceAlpha',1,'EdgeColor','k','LineWidth',lw), hold on
        else
            QUA=zeros((nu-1)*(nv-1),4*nfactor);
            QUArow=zeros(1,4*nfactor);
            for j=1:(nv-1)
                for i=1:(nu-1)
                    QUArow(:)=[(i-1+nu2*(j-1))*nfactor+(1:nfactor),(i+nu2*(j-1))*nfactor+1+(1:nfactor)*nu2-nu2,(i+nu2*j)*nfactor+2-(1:nfactor),(i-1+nu2*j)*nfactor+1-(1:nfactor)*nu2+nu2];
                    QUA(i+(j-1)*(nu-1),:)=[QUArow(2:end),QUArow(1)];
                end
            end
            patch('faces',QUA,'vertices',P','FaceColor','w','FaceAlpha',1,'EdgeColor','k','LineWidth',lw), hold on
        end
        
        lw=0.5;
        if plotCP
            for i=1:nurbs.number(1)
                plot3(reshape(xc(:,i,:),1,[]),reshape(yc(:,i,:),1,[]),reshape(zc(:,i,:),1,[]),'k--','LineWidth',lw);
            end
            for i=1:nurbs.number(2)
                plot3(xc(:,:,i),yc(:,:,i),zc(:,:,i),'k--','LineWidth',lw);
            end
            plot3(xc(:),yc(:),zc(:),'k.','MarkerSize',15);
        end
        
    end
    
else
    
    % NURBS curve
    
    if nargin<3
        nu=200;
        if nargin<2
            clr=[0.7,0.7,0.97]*0.5;
        end
    end
    
    if isempty(clr)
        clr=[0.7,0.7,0.97]*0.5;
    end
    if isempty(nu)
        nu=200;
    end
    
    U=linspace(nurbs.knots(1),nurbs.knots(end),nu);
    P=nrbevalIGES(nurbs,U);
    
    xc=nurbs.coefs(1,:)./nurbs.coefs(4,:);
    yc=nurbs.coefs(2,:)./nurbs.coefs(4,:);
    zc=nurbs.coefs(3,:)./nurbs.coefs(4,:);
    
    lw=0.5;
    if plotCP
        plot3(xc,yc,zc,'k--','LineWidth',lw), hold on
    end
    
    if or(ischar(clr),not(isscalar(clr)))
        
        if plotCP
            plot3(xc,yc,zc,'r.','MarkerSize',10);
        end
        plot3(P(1,:),P(2,:),P(3,:),'-','Color',clr,'LineWidth',2), hold on
        
    else
        
        if plotCP
            plot3(xc,yc,zc,'k.','MarkerSize',14);
        end
        plot3(P(1,:),P(2,:),P(3,:),'k-','LineWidth',2), hold on
        
    end
    
end

axis image

sc=0.15;

xl=xlim;
dx=xl(2)-xl(1);

yl=ylim;
dy=yl(2)-yl(1);

zl=zlim;
dz=zl(2)-zl(1);

ddd=0.25*max([dx,dy,dz]);

dx=max(dx,ddd);
dy=max(dy,ddd);
dz=max(dz,ddd);

xl(1)=xl(1)-sc*dx;
xl(2)=xl(2)+sc*dx;
xlim(xl);

yl(1)=yl(1)-sc*dy;
yl(2)=yl(2)+sc*dy;
ylim(yl);

zl(1)=zl(1)-sc*dz;
zl(2)=zl(2)+sc*dz;
zlim(zl);
