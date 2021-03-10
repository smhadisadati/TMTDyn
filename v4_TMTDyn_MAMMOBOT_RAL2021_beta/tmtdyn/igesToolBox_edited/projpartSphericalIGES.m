function [model,UV,srfind,srfDerivind,srfDer,numpoints,distR]=projpartSphericalIGES(ParameterData,projEye,normal,pdir,sdir,dtheta,nppos,npneg,nspos,nsneg)
% projpartSphericalIGES returns points of projections on surfaces given in an IGES-file.
%
% Usage:
%
% [model,UV,srfind,srfDerivind,srfDer,numpoints]=projpartSphericalIGES(ParameterData,...
%            projEye,normal,pdir,sdir,dtheta,nppos,npneg,nspos,nsneg)
%
% Input:
%
% ParameterData - Parameter data from IGES file. ParameterData
%                 is one of the output from IGES2MATLAB.
% projEye - The origin of the spherical projection
% normal - The projection normal. The direction of normal is toward the surface
% pdir - The first (primary) direction in which projection points lies
% sdir - The second (secondary) direction in which projection points lies
% dtheta - the angle difference between the projected points
% nppos - number of projections in positive primary direction
% npneg - number of projections in negative primary direction
% nspos - number of projections in positive secondary direction
% nsneg - number of projections in negative secondary direction
%
% Output:
%
% model - points of projetions.
% UV - the parameter values for corresponding model point from original surface
% srfind - The index of surface in ParameterData for corresponding model point. srfind(i)==0 means no projection
% srfDerivind - The index of surface derivatives in srfDer for corresponding model point
% srfDer - Cell array with surface first and second derivative for all model points
% distR - distances between model points and R
%
% m-file can be downloaded at
% http://www.mathworks.com/matlabcentral/fileexchange/13253-iges-toolbox
%
% written by Per Bergström 2013-10-22
%

if nargin<10
    error('projIGES must have 10 input arguments!');
end

if not(iscell(ParameterData))
    error('ParameterData must be a cell array!');
end

numpoints=[(nppos+npneg+1),(nspos+nsneg+1)];

[model,UV,srfind,srfDerivind,srfDer,nmodel,distR]=projSphericalIGESsub(ParameterData,normal,pdir,sdir,dtheta,nppos+npneg+1,nspos+nsneg+1,projEye,nppos,npneg,nspos,nsneg);


function [model,UV,srfind,srfDerivind,srfDer,nmodel,distR]=projSphericalIGESsub(ParameterData,normal,pdir,sdir,dtheta,np1,np2,R,nppos,npneg,nspos,nsneg)

nmodel=np1*np2;

model=zeros(3,nmodel);

UV=zeros(2,nmodel);

srfind=zeros(1,nmodel);
srfindsup=zeros(1,nmodel);

normalz=Inf*ones(1,nmodel);

distR=-ones(1,nmodel);

% For triangulation comparison

for i=1:length(ParameterData)   % Triangulate each surface and find projection on triangulation
    
    [PTRI,isSCP,isSup,TRI,UV0,srfind0]=retSrfCrvPnt(1,ParameterData,1,i,200,2);

    if and(isSCP,not(isSup))
        
        PTRIspherical=xyz2sph(PTRI,normal,pdir,sdir,R);
                
        PTRIspherical(2,:)=PTRIspherical(2,:)/dtheta;
        PTRIspherical(3,:)=PTRIspherical(3,:)/dtheta;
        
        if nspos>(min(PTRIspherical(2,:))-0.5*pi/dtheta)
            if -nsneg<(max(PTRIspherical(2,:))-0.5*pi/dtheta)
                if nppos>min(PTRIspherical(3,:))
                    if -npneg<max(PTRIspherical(3,:))
                        for j=1:size(TRI,1)
                            ind1s=floor(min(PTRIspherical(3,TRI(j,:))));
                            if ind1s<nppos
                                ind1e=ceil(max(PTRIspherical(3,TRI(j,:))));
                                if ind1e>-npneg
                                    ind2s=floor(min(PTRIspherical(2,TRI(j,:)))-0.5*pi/dtheta);
                                    if ind2s<nspos
                                        ind2e=ceil(max(PTRIspherical(2,TRI(j,:)))-0.5*pi/dtheta);
                                        if ind2e>-nsneg
                                            for ii=max(-npneg,ind1s):min(nppos,ind1e)
                                                for jj=max(-nsneg,ind2s):min(nspos,ind2e)
                                                    
                                                    dirtmp=cos(ii*dtheta)*sin(pi/2+jj*dtheta)*normal+sin(ii*dtheta)*sin(pi/2+jj*dtheta)*pdir+cos(pi/2+jj*dtheta)*sdir;
                                                    vrbls=[dirtmp PTRI(:,TRI(j,1))-PTRI(:,TRI(j,2)) PTRI(:,TRI(j,1))-PTRI(:,TRI(j,3))]\(PTRI(:,TRI(j,1))-R);
                                                    
                                                    if vrbls(1)>0.0 && vrbls(2)>-1e-4 && vrbls(3)>-1e-4 && (vrbls(2)+vrbls(3))<1.0001

                                                        indtmp=(ii+npneg)*np2+jj+nsneg+1;
                                                        
                                                        if vrbls(1)<normalz(indtmp)
                                                            normalz(indtmp)=vrbls(1);
                                                            UV(:,indtmp)=UV0(:,TRI(j,1))+vrbls(2)*(UV0(:,TRI(j,2))-UV0(:,TRI(j,1)))+vrbls(3)*(UV0(:,TRI(j,3))-UV0(:,TRI(j,1)));
                                                            srfind(indtmp)=srfind0;
                                                            srfindsup(indtmp)=i;
                                                            model(:,indtmp)=R+vrbls(1)*dirtmp;
                                                        end
                                                        
                                                    end
                                                end
                                            end
                                        end
                                    end
                                end
                            end
                        end
                    end
                end
            end
        end
    end
    clear PTRI PTRIspherical isSCP isSup TRI UV0 srfind0 vrbls
end
clear normalz
clear functions

[sosrfind,indsoP]=sort(srfind);

numbder=0;
soitmp=nmodel+1;
testFlag=true;
for i=1:nmodel
    if testFlag
        if sosrfind(i)>0
            sti=i;
            soitmp=sosrfind(i);
            soi=soitmp-1;
            numbder=1;
            testFlag=false;
        end
    elseif sosrfind(i)>soitmp
        soitmp=sosrfind(i);
        numbder=numbder+1;
    end
end
clear soitmp

srfDer=cell(1,numbder);
srfDerivind=zeros(1,nmodel);

if numbder>0
    
    srfDerind=0;
    
    for i=sti:nmodel
        
        if sosrfind(i)>soi
            soi=sosrfind(i);
            srfDerind=srfDerind+1;
            if ParameterData{soi}.type==128
                srfDer{srfDerind}.type=128;
                srfDer{srfDerind}.name='RATIONAL B-SPLINE SURFACE ENTITY';
                srfDer{srfDerind}.nurbs=ParameterData{soi}.nurbs;
                srfDer{srfDerind}.dnurbs=ParameterData{soi}.dnurbs;
                srfDer{srfDerind}.d2nurbs=ParameterData{soi}.d2nurbs;
                srfDer{srfDerind}.supind=srfindsup(indsoP(i));
            elseif ParameterData{soi}.type==108
                srfDer{srfDerind}.type=108;
                srfDer{srfDerind}.name='PLANE ENTITY';
                srfDer{srfDerind}.a=ParameterData{soi}.a;
                srfDer{srfDerind}.b=ParameterData{soi}.b;
                srfDer{srfDerind}.c=ParameterData{soi}.c;
                srfDer{srfDerind}.d=ParameterData{soi}.d;
                srfDer{srfDerind}.ptr=ParameterData{soi}.ptr;
                srfDer{srfDerind}.normal=ParameterData{soi}.normal;                
                srfDer{srfDerind}.supind=srfindsup(indsoP(i));
            else
                srfDer{srfDerind}.type=ParameterData{soi}.type;
                srfDer{srfDerind}.name='UNKNOWN ENTITY';
            end
        end
        
        srfDerivind(indsoP(i))=srfDerind;
        
    end
    
end

% For each model point. Find the projection on the corresponding surface.
for ii=-npneg:nppos
    for jj=-nsneg:nspos
        indtmp=(ii+npneg)*np2+jj+nsneg+1;
        if srfind(indtmp)>0
            if srfDer{srfDerivind(indtmp)}.type==128
                dirtmp=cos(ii*dtheta)*sin(pi/2+jj*dtheta)*normal+sin(ii*dtheta)*sin(pi/2+jj*dtheta)*pdir+cos(pi/2+jj*dtheta)*sdir;
                [model(:,indtmp),UV(:,indtmp)]=closestNrbLinePointIGES(srfDer{srfDerivind(indtmp)}.nurbs,srfDer{srfDerivind(indtmp)}.dnurbs,srfDer{srfDerivind(indtmp)}.d2nurbs,UV(:,indtmp),model(:,indtmp),dirtmp);
                distR(indtmp)=norm(model(:,indtmp)-R);
            end
        end
    end
end

function PTRIspherical=xyz2sph(PTRI,normal,pdir,sdir,R)

PTRIspherical=zeros(size(PTRI));

for i=1:size(PTRI,2)
    ptmp=PTRI(:,i)-R;
    xcoord=normal'*ptmp;
    ycoord=pdir'*ptmp;
    zcoord=sdir'*ptmp;
    rcoord=norm(ptmp);
    PTRIspherical(1,i)=rcoord;
    PTRIspherical(2,i)=acos(zcoord/rcoord);
    if xcoord>0
        PTRIspherical(3,i)=atan(ycoord/xcoord);
    elseif xcoord<0
        if ycoord>0
            PTRIspherical(3,i)=pi-atan(-ycoord/xcoord);
        else
            PTRIspherical(3,i)=atan(-ycoord/xcoord)-pi;
        end
    else
        if ycoord>0
            PTRIspherical(3,i)=pi/2;
        else
            PTRIspherical(3,i)=-pi/2;
        end
    end
end
