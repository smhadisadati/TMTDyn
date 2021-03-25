function [MODEL,DIRVEC,MINDIRsq,MNORMAL,SURFDATA]=icpSrfLinRep(model,nrmlmodel,srfind,srfs,nrmls,srfb,nrmlb,dir1model,dir2model,ldirmodel,dir1s,dir2s,ldirs,dir1b,dir2b,ldirb)
% icpSrfLinRep returns a gathered surface representation and removes duplicate points. 
% It uses the output from projpartIGES, srfRepInProjection, and linAppSrfIGES
%
% Usage:
%
% [MODEL,DIRVEC,MINDIR,MNORMAL,SURFDATA]=...
%    icpSrfLinRep(model,nrmlmodel,srfind,srfs,nrmls,srfb,nrmlb,dir1model,dir2model,ldirmodel,dir1s,dir2s,ldirs,dir1b,dir2b,ldirb)
%
%
% m-file can be downloaded at
% http://www.mathworks.com/matlabcentral/fileexchange/13253-iges-toolbox
%
% written by Per Bergström 2012-03-13
%


modelBOOLind=srfind>0;

MODEL=[model(:,modelBOOLind),srfs,srfb];

DIRVEC=[ldirmodel(1,modelBOOLind),ldirs(1,:),ldirb(1,:);...
    dir1model(:,modelBOOLind),dir1s,dir1b;...
    ldirmodel(2,modelBOOLind),ldirs(2,:),ldirb(2,:);...
    dir2model(:,modelBOOLind),dir2s,dir2b];

MINDIRsq=[min(ldirmodel(:,modelBOOLind),[],1),min(ldirs,[],1),min(ldirb,[],1)].^2;

MNORMAL=[nrmlmodel(:,modelBOOLind),nrmls,nrmlb];

clear modelBOOLind model nrmlmodel srfind srfs nrmls srfb nrmlb dir1model dir2model ldirmodel dir1s dir2s ldirs dir1b dir2b ldirb

% Remove duplicate points

leMod=size(MODEL,2);

delvec1=false(1,leMod);
delvec2=false(1,leMod);
delvec3=false(1,leMod);

[soM1,indM1]=sort(MODEL(1,:));
[soM2,indM2]=sort(MODEL(2,:));
[soM3,indM3]=sort(MODEL(3,:));

for i=2:leMod
    
    if abs(soM1(i-1)-soM1(i))<1e-8
        delvec1(indM1(i-1))=true;
        delvec1(indM1(i))=true;
    end
    
    if abs(soM2(i-1)-soM2(i))<1e-8
        delvec2(indM2(i-1))=true;
        delvec2(indM2(i))=true;
    end
    
    if abs(soM3(i-1)-soM3(i))<1e-8
        delvec3(indM3(i-1))=true;
        delvec3(indM3(i))=true;
    end
    
end

delvec=and(and(delvec1,delvec2),delvec3);

clear delvec1 soM1 indM1 delvec2 soM2 indM2 delvec3 soM3 indM3

if any(delvec)

    distvec=(MODEL(1,delvec)-100*rand).^2+(MODEL(2,delvec)-100*rand).^2+(MODEL(3,delvec)-100*rand).^2+(MODEL(1,delvec)-100*rand).^2+(MODEL(2,delvec)-100*rand).^2+(MODEL(3,delvec)-100*rand).^2+(MODEL(1,delvec)-100*rand).^2+(MODEL(2,delvec)-100*rand).^2+(MODEL(3,delvec)-100*rand).^2+(MODEL(1,delvec)-100*rand).^2+(MODEL(2,delvec)-100*rand).^2+(MODEL(3,delvec)-100*rand).^2;
    
    [so,in]=sort(distvec);
    delind=find(delvec);
    oldval=-1;
    for i=1:length(delind)
        if so(i)-oldval>1e-8
            delvec(delind(in(i)))=false;
            oldval=so(i);
        end
    end
    
end

MODEL=MODEL(:,not(delvec));
DIRVEC=DIRVEC(:,not(delvec));
MINDIRsq=MINDIRsq(:,not(delvec));
MNORMAL=MNORMAL(:,not(delvec));

SURFDATA=[MODEL;DIRVEC;MNORMAL];

