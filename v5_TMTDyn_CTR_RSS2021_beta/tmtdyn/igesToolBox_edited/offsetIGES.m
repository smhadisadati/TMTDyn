function ParameterDataOffset=offsetIGES(ParameterData,d,dir)
% OFFSETIGES creates an offset surface
%
% Usage:
%
% ParameterDataOffset=offsetIGES(ParameterData,d,dir)
%
% Input:
%
% ParameterData - cell array with parameter data from the IGES-file
% d - offset signed distance
% dir - positive offset direction
%
% Output:
%
% ParameterDataOffset -  parameter data of offset surface
%
% m-file can be downloaded at
% http://www.mathworks.com/matlabcentral/fileexchange/13253-iges-toolbox
%
% Note: All IGES-entities are not supported
%
% written by Per Bergström 2015-08-18
%

if size(dir,1)>size(dir,2)
    dir=sign(d)*dir;
else
    dir=sign(d)*dir';
end
d=abs(d);

ParameterDataOffset=ParameterData;

numEnt=length(ParameterData);

signDistPD=zeros(1,numEnt);

nu=20;
nv=20;

for i=1:numEnt
    
    if ParameterData{i}.type==128
        
        [P,UV]=nrbSrfRegularEvalIGES(ParameterData{i}.nurbs,ParameterData{i}.nurbs.knots{1}(1),ParameterData{i}.nurbs.knots{1}(end),nu,ParameterData{i}.nurbs.knots{2}(1),ParameterData{i}.nurbs.knots{2}(end),nv);
        [~,ind]=max(dir'*P);
        
        [~,Pu,Pv]=nrbevalIGES(ParameterData{i}.nurbs,UV(:,ind),ParameterData{i}.dnurbs);
        
        Nm=cross(Pu,Pv);
        if dot(dir,Nm)>0
            signdist=d;
        else
            signdist=-d;
        end
        signDistPD(i)=signdist;
        
        NURBSorg=ParameterData{i}.nurbs;
        dNURBSorg=ParameterData{i}.dnurbs;
        d2NURBSorg=ParameterData{i}.d2nurbs;
        
        [NURBSoffset,coefsOffset,wghsOffset]=offsetNURBSsurface(signdist,NURBSorg,dNURBSorg,d2NURBSorg);
        [dNURBSoffset,d2NURBSoffset]=nrbDerivativesIGES(NURBSoffset);
        
        ParameterDataOffset{i}.w=wghsOffset;
        ParameterDataOffset{i}.p=coefsOffset;
        
        ParameterDataOffset{i}.nurbs=NURBSoffset;
        ParameterDataOffset{i}.dnurbs=dNURBSoffset;
        ParameterDataOffset{i}.d2nurbs=d2NURBSoffset;
        
    elseif ParameterData{i}.type==108
        
        if dot(dir,ParameterData{i}.normal)>0
            signdist=d;
        else
            signdist=-d;
        end
        signDistPD(i)=signdist;
        
        ParameterDataOffset{i}.d=ParameterData{i}.d+signdist*norm(ParameterData{i}.normal);
        
        ParameterDataOffset{i}.x=ParameterData{i}.x+signdist*ParameterData{i}.a/norm(ParameterData{i}.normal);
        ParameterDataOffset{i}.y=ParameterData{i}.y+signdist*ParameterData{i}.b/norm(ParameterData{i}.normal);
        ParameterDataOffset{i}.z=ParameterData{i}.z+signdist*ParameterData{i}.c/norm(ParameterData{i}.normal);
        
    elseif and(ParameterData{i}.type==144,isfield(ParameterData{i},'nurbs'))
        
        [P,UV]=nrbSrfRegularEvalIGES(ParameterData{i}.nurbs,ParameterData{i}.nurbs.knots{1}(1),ParameterData{i}.nurbs.knots{1}(end),nu,ParameterData{i}.nurbs.knots{2}(1),ParameterData{i}.nurbs.knots{2}(end),nv);
        [~,ind]=max(dir'*P);
        
        [~,Pu,Pv]=nrbevalIGES(ParameterData{i}.nurbs,UV(:,ind),ParameterData{i}.dnurbs);
        
        Nm=cross(Pu,Pv);
        if dot(dir,Nm)>0
            signdist=d;
        else
            signdist=-d;
        end
        signDistPD(i)=signdist;
        
        NURBSorg=ParameterData{i}.nurbs;
        dNURBSorg=ParameterData{i}.dnurbs;
        d2NURBSorg=ParameterData{i}.d2nurbs;
        
        [NURBSoffset,coefsOffset,wghsOffset]=offsetNURBSsurface(signdist,NURBSorg,dNURBSorg,d2NURBSorg);
        [dNURBSoffset,d2NURBSoffset]=nrbDerivativesIGES(NURBSoffset);
        
        ParameterDataOffset{i}.nurbs=NURBSoffset;
        ParameterDataOffset{i}.dnurbs=dNURBSoffset;
        ParameterDataOffset{i}.d2nurbs=d2NURBSoffset;
        
    end
    
end

for i=1:numEnt
    
    if ParameterData{i}.type==144
        
        ParameterData{i}.original=0;
        
        srfInd=ParameterData{i}.pts;
        
        if ParameterData{srfInd}.type==128
            
            if ParameterData{i}.n1
                
                [ParameterDataOffset,uInterval,vInterval,domainIsRectangle]=findBoundaryInOffsetNURBSParameterSpace(ParameterData,ParameterDataOffset,i,ParameterData{i}.pto,signDistPD(i));
                
                if and(domainIsRectangle,ParameterData{i}.n2==0)
                    ParameterDataOffset{i}.trimmed=0;
                    
                    ParameterDataOffset{i}.u=uInterval;
                    ParameterDataOffset{i}.v=vInterval;
                    
                    ParameterDataOffset{i}.ulinear=ParameterDataOffset{srfInd}.isplane;
                    ParameterDataOffset{i}.vlinear=ParameterDataOffset{srfInd}.isplane;
                    
                    ParameterDataOffset{i}.isplane=ParameterDataOffset{srfInd}.isplane;
                    
                    ParameterDataOffset{i}.ratio=ParameterDataOffset{srfInd}.ratio;
                    
                else
                    ParameterDataOffset{i}.trimmed=1;
                end
                
            end
            
            for j=1:ParameterData{i}.n2
                ParameterDataOffset=findBoundaryInOffsetNURBSParameterSpace(ParameterData,ParameterDataOffset,i,ParameterData{i}.pti(j),signDistPD(i));
            end
            
        end
        
    end
    
end

for i=1:numEnt
    
    if ParameterData{i}.type==142
        
        ParameterData{i}.original=0;
        
        ParameterDataOffset=findCrvInOffsetNURBSParameterSpace(ParameterData,ParameterDataOffset,i,signDistPD(ParameterData{i}.sptr));
        
    end
    
end


function [ParameterDataOffset,uInterval,vInterval,domainIsRectangle]=findBoundaryInOffsetNURBSParameterSpace(ParameterData,ParameterDataOffset,ind,crvInd,signdist)

srfInd=ParameterData{ind}.pts;
bCptr=ParameterData{crvInd}.bptr;

uInterval=[ParameterData{srfInd}.u(2),ParameterData{srfInd}.u(1)];
vInterval=[ParameterData{srfInd}.v(2),ParameterData{srfInd}.v(1)];

dU=abs(uInterval(2)-uInterval(1));
dV=abs(vInterval(2)-vInterval(1));
pspaceD=dU^2+dV^2;

numSplineVal=20;
splinePnts=zeros(2,numSplineVal);

if ParameterData{bCptr}.type==102
    
    numCrv=ParameterData{bCptr}.n;
    
    lengthTrimCRVS=0;
    lengthcnt=zeros(1,numCrv);
    
    numPnt=501;
    
    UVbpr=zeros(2,numPnt);
    UV=zeros(2,numPnt);
    pntCrvPrms=zeros(1,numPnt);
    Pbpr=zeros(3,numPnt);
    SuBpr=zeros(3,numPnt);
    SvBpr=zeros(3,numPnt);
    nrmlBpr=zeros(3,numPnt);
    noNrmlBpr=zeros(1,numPnt);
    
    allLines=true;
    
    for jj=1:numCrv
        
        crvInd=ParameterData{bCptr}.de(jj);
        
        if ParameterData{crvInd}.type==126
            nrbDeg=ParameterData{crvInd}.m;
            numCtrlPnts=ParameterData{crvInd}.k+1;
            knots=ParameterData{crvInd}.t;
            
            pntCrvPrms(:)=pchip(0:(numCtrlPnts-nrbDeg),knots((nrbDeg+1):(numCtrlPnts+1)),linspace(0,numCtrlPnts-nrbDeg,numPnt));
            
            Pbpr(:,:)=nrbevalIGES(ParameterData{crvInd}.nurbs,pntCrvPrms);
            UVbpr(:,:)=Pbpr(1:2,:);
        else
            UVbpr(:,:)=retSrfCrvPnt(2,ParameterData,0,crvInd,numPnt,22);
        end
        
        [Pbpr(:,:),SuBpr(:,:),SvBpr(:,:)]=nrbevalIGES(ParameterData{srfInd}.nurbs,UVbpr,ParameterData{srfInd}.dnurbs);
        
        nrmlBpr(1,:)=SuBpr(2,:).*SvBpr(3,:)-SuBpr(3,:).*SvBpr(2,:);
        nrmlBpr(2,:)=SuBpr(3,:).*SvBpr(1,:)-SuBpr(1,:).*SvBpr(3,:);
        nrmlBpr(3,:)=SuBpr(1,:).*SvBpr(2,:)-SuBpr(2,:).*SvBpr(1,:);
        
        noNrmlBpr(:)=sqrt(sum(nrmlBpr.^2,1));
        
        nrmlBpr(1,:)=nrmlBpr(1,:)./noNrmlBpr;
        nrmlBpr(2,:)=nrmlBpr(2,:)./noNrmlBpr;
        nrmlBpr(3,:)=nrmlBpr(3,:)./noNrmlBpr;
        
        Pbpr(:,:)=Pbpr+signdist*nrmlBpr;
        
        [~,UV(:,:)]=closestNrbLinePointIGES(ParameterDataOffset{srfInd}.nurbs,ParameterDataOffset{srfInd}.dnurbs,ParameterDataOffset{srfInd}.d2nurbs,UVbpr,Pbpr);
        
        uInterval(1)=min(uInterval(1),min(UV(1,:)));
        uInterval(2)=max(uInterval(2),max(UV(1,:)));
        
        vInterval(1)=min(vInterval(1),min(UV(2,:)));
        vInterval(2)=max(vInterval(2),max(UV(2,:)));
        
        meaUV=mean(UV,2);
        
        singVals=svd(UV*UV'-(numPnt*meaUV)*meaUV');
        
        if or(1e6*singVals(2)<singVals(1),1e6*singVals(1)<pspaceD)
            
            ParameterDataOffset{crvInd}.type=110;
            
            ParameterDataOffset{crvInd}.name='LINE';
            ParameterDataOffset{crvInd}.original=0;
            ParameterDataOffset{crvInd}.previous_type=ParameterData{crvInd}.type;
            ParameterDataOffset{crvInd}.previous_name=ParameterData{crvInd}.name;
            
            ParameterDataOffset{crvInd}.superior=1;
            
            ParameterDataOffset{crvInd}.form=0;
            
            ParameterDataOffset{crvInd}.p1=[UV(:,1);0];
            ParameterDataOffset{crvInd}.x1=UV(1,1);
            ParameterDataOffset{crvInd}.y1=UV(2,1);
            ParameterDataOffset{crvInd}.z1=0;
            
            ParameterDataOffset{crvInd}.p2=[UV(:,numPnt);0];
            ParameterDataOffset{crvInd}.x2=UV(1,numPnt);
            ParameterDataOffset{crvInd}.y2=UV(2,numPnt);
            ParameterDataOffset{crvInd}.z2=0;
            
            ParameterDataOffset{crvInd}.length=norm(UV(:,numPnt)-UV(:,1));
            
            ParameterDataOffset{crvInd}.well=true;
            
            lengthTrimCRVS=lengthTrimCRVS+ParameterDataOffset{crvInd}.length;
            lengthcnt(jj)=ParameterDataOffset{crvInd}.length;
            
        else
            
            allLines=false;
            
            if ParameterData{crvInd}.type==126
                
                coefs=ParameterData{crvInd}.nurbs.coefs;
                
                [NTN,R]=LScrvApp(UV,nrbDeg,numCtrlPnts,pntCrvPrms,knots,coefs);
                
                coefs(1:2,1)=coefs(4,1)*UV(:,1);
                coefs(1:2,numCtrlPnts)=coefs(4,end)*UV(:,numPnt);
                coefs(1:2,2:(numCtrlPnts-1))=(NTN\R)';
                
            else
                
                nrbDeg=2;
                numCtrlPnts=30;
                
                knots=zeros(1,nrbDeg+numCtrlPnts+1);
                knots((numCtrlPnts+1):end)=1;
                
                pntCrvPrms=zeros(1,numPnt);
                
                coefs=zeros(4,numCtrlPnts);
                coefs(4,:)=1;
                
                pp = spline(1:numPnt,UV);
                
                for j=2:numPnt
                    splinePnts(:,:)=ppval(pp,linspace(j-1,j,numSplineVal));
                    pntCrvPrms(j)=sum(sqrt((splinePnts(1,2:numSplineVal)-splinePnts(1,1:(numSplineVal-1))).^2+(splinePnts(2,2:numSplineVal)-splinePnts(2,1:(numSplineVal-1))).^2));
                end
                pntCrvPrms=cumsum(pntCrvPrms);
                pntCrvPrms=pntCrvPrms/pntCrvPrms(numPnt);
                
                ppParams = pchip(linspace(0,1,numPnt),pntCrvPrms);
                
                knots((nrbDeg+2):numCtrlPnts)=ppval(ppParams,(1:(numCtrlPnts-nrbDeg-1))/(numCtrlPnts-nrbDeg));
                
                [NTN,R]=LScrvApp(UV,nrbDeg,numCtrlPnts,pntCrvPrms,knots);
                
                coefs(1:2,1)=UV(:,1);
                coefs(1:2,numCtrlPnts)=UV(:,numPnt);
                coefs(1:2,2:(numCtrlPnts-1))=(NTN\R)';
                
            end
            
            
            ParameterDataOffset{crvInd}.type=126;
            ParameterDataOffset{crvInd}.name='B-NURBS CRV';
            ParameterDataOffset{crvInd}.original=0;
            ParameterDataOffset{crvInd}.previous_type=ParameterData{crvInd}.type;
            ParameterDataOffset{crvInd}.previous_name=ParameterData{crvInd}.name;
            ParameterDataOffset{crvInd}.superior=1;
            ParameterDataOffset{crvInd}.k=numCtrlPnts-1;
            ParameterDataOffset{crvInd}.m=nrbDeg;
            
            ParameterDataOffset{crvInd}.prop1=1;
            ParameterDataOffset{crvInd}.prop2=1;
            ParameterDataOffset{crvInd}.prop3=1;
            ParameterDataOffset{crvInd}.prop4=1;
            
            ParameterDataOffset{crvInd}.t=knots;
            ParameterDataOffset{crvInd}.w=coefs(4,:);
            ParameterDataOffset{crvInd}.p=coefs(1:3,:);
            ParameterDataOffset{crvInd}.p(1,:)=coefs(1,:)./coefs(4,:);
            ParameterDataOffset{crvInd}.p(2,:)=coefs(2,:)./coefs(4,:);
            ParameterDataOffset{crvInd}.p(3,:)=coefs(3,:)./coefs(4,:);
            
            ParameterDataOffset{crvInd}.v=[knots(1),knots(end)];
            
            ParameterDataOffset{crvInd}.xnorm=0;
            ParameterDataOffset{crvInd}.ynorm=0;
            ParameterDataOffset{crvInd}.znorm=1;
            
            ParameterDataOffset{crvInd}.nurbs.form='B-NURBS';
            ParameterDataOffset{crvInd}.nurbs.dim=4;
            ParameterDataOffset{crvInd}.nurbs.number=numCtrlPnts;
            ParameterDataOffset{crvInd}.nurbs.coefs=coefs;
            ParameterDataOffset{crvInd}.nurbs.order=nrbDeg+1;
            ParameterDataOffset{crvInd}.nurbs.knots=knots;
            
            [ParameterDataOffset{crvInd}.dnurbs,ParameterDataOffset{crvInd}.d2nurbs]=nrbDerivativesIGES(ParameterDataOffset{crvInd}.nurbs);
            
            nup=500;
            p = nrbevalIGES(ParameterDataOffset{crvInd}.nurbs,linspace(ParameterDataOffset{crvInd}.v(1),ParameterDataOffset{crvInd}.v(2),nup));
            len=sum(sqrt(sum((p(:,1:(nup-1))-p(:,2:nup)).^2,1)));
            if norm(p(:,1)-p(:,nup))<1e-3
                ParameterDataOffset{crvInd}.length=3*len;
            else
                ParameterDataOffset{crvInd}.length=min((len/norm(p(:,1)-p(:,nup))-1)*10+1,3)*len;
            end
            
            ParameterDataOffset{crvInd}.well=true;
            
            lengthTrimCRVS=lengthTrimCRVS+ParameterDataOffset{crvInd}.length;
            lengthcnt(jj)=ParameterDataOffset{crvInd}.length;
            
        end
        
    end
    
    ParameterDataOffset{bCptr}.length=lengthTrimCRVS;
    ParameterDataOffset{bCptr}.lengthcnt=lengthcnt;
    ParameterDataOffset{bCptr}.allLines=allLines;
    
else
    
    crvInd=ParameterData{bCptr};
    
    numCrv=1;
    
    numPnt=1001;
    
    UVbpr=zeros(2,numPnt);
    UV=zeros(2,numPnt);
    pntCrvPrms=zeros(1,numPnt);
    Pbpr=zeros(3,numPnt);
    SuBpr=zeros(3,numPnt);
    SvBpr=zeros(3,numPnt);
    nrmlBpr=zeros(3,numPnt);
    noNrmlBpr=zeros(1,numPnt);
    
    allLines=false;
    
    if ParameterData{crvInd}.type==126
        nrbDeg=ParameterData{crvInd}.m;
        numCtrlPnts=ParameterData{crvInd}.k+1;
        knots=ParameterData{crvInd}.t;
        
        pntCrvPrms(:)=pchip(0:(numCtrlPnts-nrbDeg),knots((nrbDeg+1):(numCtrlPnts+1)),linspace(0,numCtrlPnts-nrbDeg,numPnt));
        
        Pbpr(:,:)=nrbevalIGES(ParameterData{crvInd}.nurbs,pntCrvPrms);
        UVbpr(:,:)=Pbpr(1:2,:);
    else
        UVbpr(:,:)=retSrfCrvPnt(2,ParameterData,0,crvInd,numPnt,22);
    end
    
    [Pbpr(:,:),SuBpr(:,:),SvBpr(:,:)]=nrbevalIGES(ParameterData{srfInd}.nurbs,UVbpr,ParameterData{srfInd}.dnurbs);
    
    nrmlBpr(1,:)=SuBpr(2,:).*SvBpr(3,:)-SuBpr(3,:).*SvBpr(2,:);
    nrmlBpr(2,:)=SuBpr(3,:).*SvBpr(1,:)-SuBpr(1,:).*SvBpr(3,:);
    nrmlBpr(3,:)=SuBpr(1,:).*SvBpr(2,:)-SuBpr(2,:).*SvBpr(1,:);
    
    noNrmlBpr(:)=sqrt(sum(nrmlBpr.^2,1));
    
    nrmlBpr(1,:)=nrmlBpr(1,:)./noNrmlBpr;
    nrmlBpr(2,:)=nrmlBpr(2,:)./noNrmlBpr;
    nrmlBpr(3,:)=nrmlBpr(3,:)./noNrmlBpr;
    
    Pbpr(:,:)=Pbpr+signdist*nrmlBpr;
    
    [~,UV(:,:)]=closestNrbLinePointIGES(ParameterDataOffset{srfInd}.nurbs,ParameterDataOffset{srfInd}.dnurbs,ParameterDataOffset{srfInd}.d2nurbs,UVbpr,Pbpr);
    
    uInterval(1)=min(uInterval(1),min(UV(1,:)));
    uInterval(2)=max(uInterval(2),max(UV(1,:)));
    
    vInterval(1)=min(vInterval(1),min(UV(2,:)));
    vInterval(2)=max(vInterval(2),max(UV(2,:)));
    
    if ParameterData{crvInd}.type==126
        
        coefs=ParameterData{crvInd}.nurbs.coefs;
        
        [NTN,R]=LScrvApp(UV,nrbDeg,numCtrlPnts,pntCrvPrms,knots,coefs);
        
        coefs(1:2,1)=coefs(4,1)*UV(:,1);
        coefs(1:2,numCtrlPnts)=coefs(4,end)*UV(:,numPnt);
        coefs(1:2,2:(numCtrlPnts-1))=(NTN\R)';
        
    else
        
        nrbDeg=2;
        numCtrlPnts=30;
        
        knots=zeros(1,nrbDeg+numCtrlPnts+1);
        knots((numCtrlPnts+1):end)=1;
        
        pntCrvPrms=zeros(1,numPnt);
        
        coefs=zeros(4,numCtrlPnts);
        coefs(4,:)=1;
        
        pp = spline(1:numPnt,UV);
        
        for j=2:numPnt
            splinePnts(:,:)=ppval(pp,linspace(j-1,j,numSplineVal));
            pntCrvPrms(j)=sum(sqrt((splinePnts(1,2:numSplineVal)-splinePnts(1,1:(numSplineVal-1))).^2+(splinePnts(2,2:numSplineVal)-splinePnts(2,1:(numSplineVal-1))).^2));
        end
        pntCrvPrms=cumsum(pntCrvPrms);
        pntCrvPrms=pntCrvPrms/pntCrvPrms(numPnt);
        
        ppParams = pchip(linspace(0,1,numPnt),pntCrvPrms);
        
        knots((nrbDeg+2):numCtrlPnts)=ppval(ppParams,(1:(numCtrlPnts-nrbDeg-1))/(numCtrlPnts-nrbDeg));
        
        [NTN,R]=LScrvApp(UV,nrbDeg,numCtrlPnts,pntCrvPrms,knots);
        
        coefs(1:2,1)=UV(:,1);
        coefs(1:2,numCtrlPnts)=UV(:,numPnt);
        coefs(1:2,2:(numCtrlPnts-1))=(NTN\R)';
        
    end
    
    ParameterDataOffset{crvInd}.type=126;
    ParameterDataOffset{crvInd}.name='B-NURBS CRV';
    ParameterDataOffset{crvInd}.original=0;
    ParameterDataOffset{crvInd}.previous_type=ParameterData{crvInd}.type;
    ParameterDataOffset{crvInd}.previous_name=ParameterData{crvInd}.name;
    ParameterDataOffset{crvInd}.superior=1;
    ParameterDataOffset{crvInd}.k=numCtrlPnts-1;
    ParameterDataOffset{crvInd}.m=nrbDeg;
    
    ParameterDataOffset{crvInd}.prop1=1;
    ParameterDataOffset{crvInd}.prop2=1;
    ParameterDataOffset{crvInd}.prop3=1;
    ParameterDataOffset{crvInd}.prop4=1;
    
    ParameterDataOffset{crvInd}.t=knots;
    ParameterDataOffset{crvInd}.w=coefs(4,:);
    ParameterDataOffset{crvInd}.p=coefs(1:3,:);
    ParameterDataOffset{crvInd}.p(1,:)=coefs(1,:)./coefs(4,:);
    ParameterDataOffset{crvInd}.p(2,:)=coefs(2,:)./coefs(4,:);
    ParameterDataOffset{crvInd}.p(3,:)=coefs(3,:)./coefs(4,:);
    
    ParameterDataOffset{crvInd}.v=[knots(1),knots(end)];
    
    ParameterDataOffset{crvInd}.xnorm=0;
    ParameterDataOffset{crvInd}.ynorm=0;
    ParameterDataOffset{crvInd}.znorm=1;
    
    ParameterDataOffset{crvInd}.nurbs.form='B-NURBS';
    ParameterDataOffset{crvInd}.nurbs.dim=4;
    ParameterDataOffset{crvInd}.nurbs.number=numCtrlPnts;
    ParameterDataOffset{crvInd}.nurbs.coefs=coefs;
    ParameterDataOffset{crvInd}.nurbs.order=nrbDeg+1;
    ParameterDataOffset{crvInd}.nurbs.knots=knots;
    
    [ParameterDataOffset{crvInd}.dnurbs,ParameterDataOffset{crvInd}.d2nurbs]=nrbDerivativesIGES(ParameterDataOffset{crvInd}.nurbs);
    
    nup=500;
    p = nrbevalIGES(ParameterDataOffset{crvInd}.nurbs,linspace(ParameterDataOffset{crvInd}.v(1),ParameterDataOffset{crvInd}.v(2),nup));
    len=sum(sqrt(sum((p(:,1:(nup-1))-p(:,2:nup)).^2,1)));
    if norm(p(:,1)-p(:,nup))<1e-3
        ParameterDataOffset{crvInd}.length=3*len;
    else
        ParameterDataOffset{crvInd}.length=min((len/norm(p(:,1)-p(:,nup))-1)*10+1,3)*len;
    end
    
    ParameterDataOffset{crvInd}.well=true;
    
    lengthTrimCRVS=ParameterDataOffset{crvInd}.length;
    
    ParameterDataOffset{bCptr}.length=lengthTrimCRVS;
    
end

if allLines
    
    domainIsRectangle=true;
    
    for jj=1:numCrv
        
        if and(abs(ParameterDataOffset{crvInd}.x2-ParameterDataOffset{crvInd}.x1)>0.01*dU,abs(ParameterDataOffset{crvInd}.y2-ParameterDataOffset{crvInd}.y1)>0.01*dV)
            domainIsRectangle=false;
            break
        elseif and(and((ParameterDataOffset{crvInd}.x1-uInterval(1))>0.01*dU,(uInterval(2)-ParameterDataOffset{crvInd}.x1)>0.01*dU),and((ParameterDataOffset{crvInd}.y1-vInterval(1))>0.01*dV,(vInterval(2)-ParameterDataOffset{crvInd}.y1)>0.01*dV))
            domainIsRectangle=false;
            break
        elseif and(and((ParameterDataOffset{crvInd}.x2-uInterval(1))>0.01*dU,(uInterval(2)-ParameterDataOffset{crvInd}.x2)>0.01*dU),and((ParameterDataOffset{crvInd}.y2-vInterval(1))>0.01*dV,(vInterval(2)-ParameterDataOffset{crvInd}.y2)>0.01*dV))
            domainIsRectangle=false;
            break
        end
        
    end
    
else
    
    domainIsRectangle=false;
    
end


function ParameterDataOffset=findCrvInOffsetNURBSParameterSpace(ParameterData,ParameterDataOffset,ind,signdist)

srfInd=ParameterData{ind}.sptr;

if ParameterData{srfInd}.type==128
    
    nu=150;
    nv=150;
    [Pcomp,UVcomp]=nrbSrfRegularEvalIGES(ParameterData{srfInd}.nurbs,ParameterData{srfInd}.u(1),ParameterData{srfInd}.u(2),nu,ParameterData{srfInd}.v(1),ParameterData{srfInd}.v(2),nv);
    
    bCptr=ParameterData{ind}.cptr;
    
    if ParameterData{bCptr}.type==102
        
        numCrv=ParameterData{bCptr}.n;
        
        lengthSpaceCRVS=0;
        lengthcnt=zeros(1,numCrv);
        
        numPnt=501;
        
        UVcpr=zeros(2,numPnt);
        UV=zeros(2,numPnt);
        tcpr=zeros(1,numPnt);
        Pcpr=zeros(3,numPnt);
        SuBpr=zeros(3,numPnt);
        SvBpr=zeros(3,numPnt);
        nrmlBpr=zeros(3,numPnt);
        noNrmlBpr=zeros(1,numPnt);
        
        for jj=1:numCrv
            
            crvInd=ParameterData{bCptr}.de(jj);
            
            if ParameterData{crvInd}.type==126
                
                nrbDeg=ParameterData{crvInd}.m;
                numCtrlPnts=ParameterData{crvInd}.k+1;
                knots=ParameterData{crvInd}.t;
                
                tcpr(:)=pchip(0:(numCtrlPnts-nrbDeg),knots((nrbDeg+1):(numCtrlPnts+1)),linspace(0,numCtrlPnts-nrbDeg,numPnt));
                
                Pcpr(:,:)=nrbevalIGES(ParameterData{crvInd}.nurbs,tcpr);
                
                for kk=1:numPnt
                    [~,miind]=min((Pcomp(1,:)-Pcpr(1,kk)).^2+(Pcomp(2,:)-Pcpr(2,kk)).^2+(Pcomp(3,:)-Pcpr(3,kk)).^2);
                    UVcpr(:,kk)=UVcomp(:,miind);
                end
                
                [~,UV(:,:)]=closestNrbLinePointIGES(ParameterData{srfInd}.nurbs,ParameterData{srfInd}.dnurbs,ParameterData{srfInd}.d2nurbs,UVcpr,Pcpr);
                
                [~,SuBpr(:,:),SvBpr(:,:)]=nrbevalIGES(ParameterData{srfInd}.nurbs,UV,ParameterData{srfInd}.dnurbs);
                
                nrmlBpr(1,:)=SuBpr(2,:).*SvBpr(3,:)-SuBpr(3,:).*SvBpr(2,:);
                nrmlBpr(2,:)=SuBpr(3,:).*SvBpr(1,:)-SuBpr(1,:).*SvBpr(3,:);
                nrmlBpr(3,:)=SuBpr(1,:).*SvBpr(2,:)-SuBpr(2,:).*SvBpr(1,:);
                
                noNrmlBpr(:)=sqrt(sum(nrmlBpr.^2,1));
                
                nrmlBpr(1,:)=nrmlBpr(1,:)./noNrmlBpr;
                nrmlBpr(2,:)=nrmlBpr(2,:)./noNrmlBpr;
                nrmlBpr(3,:)=nrmlBpr(3,:)./noNrmlBpr;
                
                Pcpr(:,:)=Pcpr+signdist*nrmlBpr;
                
                coefs=ParameterData{crvInd}.nurbs.coefs;
                
                [NTN,R]=LScrvApp(Pcpr,nrbDeg,numCtrlPnts,tcpr,knots,coefs);
                
                coefs(1:3,1)=coefs(4,1)*Pcpr(:,1);
                coefs(1:3,numCtrlPnts)=coefs(4,end)*Pcpr(:,numPnt);
                coefs(1:3,2:(numCtrlPnts-1))=(NTN\R)';
                
                
                ParameterDataOffset{crvInd}.type=126;
                ParameterDataOffset{crvInd}.name='B-NURBS CRV';
                ParameterDataOffset{crvInd}.original=0;
                ParameterDataOffset{crvInd}.previous_type=ParameterData{crvInd}.type;
                ParameterDataOffset{crvInd}.previous_name=ParameterData{crvInd}.name;
                ParameterDataOffset{crvInd}.superior=0;
                ParameterDataOffset{crvInd}.k=numCtrlPnts-1;
                ParameterDataOffset{crvInd}.m=nrbDeg;
                
                ParameterDataOffset{crvInd}.prop1=1;
                ParameterDataOffset{crvInd}.prop2=1;
                ParameterDataOffset{crvInd}.prop3=1;
                ParameterDataOffset{crvInd}.prop4=1;
                
                ParameterDataOffset{crvInd}.t=knots;
                ParameterDataOffset{crvInd}.w=coefs(4,:);
                ParameterDataOffset{crvInd}.p=coefs(1:3,:);
                ParameterDataOffset{crvInd}.p(1,:)=coefs(1,:)./coefs(4,:);
                ParameterDataOffset{crvInd}.p(2,:)=coefs(2,:)./coefs(4,:);
                ParameterDataOffset{crvInd}.p(3,:)=coefs(3,:)./coefs(4,:);
                
                ParameterDataOffset{crvInd}.v=ParameterData{crvInd}.v;
                
                ParameterDataOffset{crvInd}.xnorm=0;
                ParameterDataOffset{crvInd}.ynorm=0;
                ParameterDataOffset{crvInd}.znorm=1;
                
                ParameterDataOffset{crvInd}.nurbs.form='B-NURBS';
                ParameterDataOffset{crvInd}.nurbs.dim=4;
                ParameterDataOffset{crvInd}.nurbs.number=numCtrlPnts;
                ParameterDataOffset{crvInd}.nurbs.coefs=coefs;
                ParameterDataOffset{crvInd}.nurbs.order=nrbDeg+1;
                ParameterDataOffset{crvInd}.nurbs.knots=knots;
                
                [ParameterDataOffset{crvInd}.dnurbs,ParameterDataOffset{crvInd}.d2nurbs]=nrbDerivativesIGES(ParameterDataOffset{crvInd}.nurbs);
                
                nup=500;
                p = nrbevalIGES(ParameterDataOffset{crvInd}.nurbs,linspace(ParameterDataOffset{crvInd}.v(1),ParameterDataOffset{crvInd}.v(2),nup));
                len=sum(sqrt(sum((p(:,1:(nup-1))-p(:,2:nup)).^2,1)));
                if norm(p(:,1)-p(:,nup))<1e-3
                    ParameterDataOffset{crvInd}.length=3*len;
                else
                    ParameterDataOffset{crvInd}.length=min((len/norm(p(:,1)-p(:,nup))-1)*10+1,3)*len;
                end
                
                ParameterDataOffset{crvInd}.well=true;
                
                lengthSpaceCRVS=lengthSpaceCRVS+ParameterDataOffset{crvInd}.length;
                lengthcnt(jj)=ParameterDataOffset{crvInd}.length;
                
            elseif ParameterData{crvInd}.type==110
                
                Pcpr(:,1)=ParameterData{crvInd}.p1;
                Pcpr(:,2)=ParameterData{crvInd}.p2;
                
                for kk=1:2
                    [~,miind]=min((Pcomp(1,:)-Pcpr(1,kk)).^2+(Pcomp(2,:)-Pcpr(2,kk)).^2+(Pcomp(3,:)-Pcpr(3,kk)).^2);
                    UVcpr(:,kk)=UVcomp(:,miind);
                end
                
                [~,UV(:,1:2)]=closestNrbLinePointIGES(ParameterData{srfInd}.nurbs,ParameterData{srfInd}.dnurbs,ParameterData{srfInd}.d2nurbs,UVcpr(:,1:2),Pcpr(:,1:2));
                
                [~,SuBpr(:,1:2),SvBpr(:,1:2)]=nrbevalIGES(ParameterData{srfInd}.nurbs,UV(:,1:2),ParameterData{srfInd}.dnurbs);
                
                nrmlBpr(1,1:2)=SuBpr(2,1:2).*SvBpr(3,1:2)-SuBpr(3,1:2).*SvBpr(2,1:2);
                nrmlBpr(2,1:2)=SuBpr(3,1:2).*SvBpr(1,1:2)-SuBpr(1,1:2).*SvBpr(3,1:2);
                nrmlBpr(3,1:2)=SuBpr(1,1:2).*SvBpr(2,1:2)-SuBpr(2,1:2).*SvBpr(1,1:2);
                
                noNrmlBpr(1:2)=sqrt(sum(nrmlBpr(:,1:2).^2,1));
                
                nrmlBpr(1,1:2)=nrmlBpr(1,1:2)./noNrmlBpr(1:2);
                nrmlBpr(2,1:2)=nrmlBpr(2,1:2)./noNrmlBpr(1:2);
                nrmlBpr(3,1:2)=nrmlBpr(3,1:2)./noNrmlBpr(1:2);
                
                Pcpr(:,1:2)=Pcpr(:,1:2)+signdist*nrmlBpr(:,1:2);
                
                
                ParameterDataOffset{crvInd}.type=110;
                
                ParameterDataOffset{crvInd}.name='LINE';
                ParameterDataOffset{crvInd}.original=0;
                ParameterDataOffset{crvInd}.previous_type=ParameterData{crvInd}.type;
                ParameterDataOffset{crvInd}.previous_name=ParameterData{crvInd}.name;
                
                ParameterDataOffset{crvInd}.superior=0;
                
                ParameterDataOffset{crvInd}.form=0;
                
                ParameterDataOffset{crvInd}.p1=Pcpr(:,1);
                ParameterDataOffset{crvInd}.x1=Pcpr(1,1);
                ParameterDataOffset{crvInd}.y1=Pcpr(2,1);
                ParameterDataOffset{crvInd}.z1=Pcpr(3,1);
                
                ParameterDataOffset{crvInd}.p2=Pcpr(:,2);
                ParameterDataOffset{crvInd}.x2=Pcpr(1,2);
                ParameterDataOffset{crvInd}.y2=Pcpr(2,2);
                ParameterDataOffset{crvInd}.z2=Pcpr(3,2);
                
                ParameterDataOffset{crvInd}.length=norm(Pcpr(:,2)-Pcpr(:,1));
                
                ParameterDataOffset{crvInd}.well=true;
                
                lengthSpaceCRVS=lengthSpaceCRVS+ParameterDataOffset{crvInd}.length;
                lengthcnt(jj)=ParameterDataOffset{crvInd}.length;
                
            end
            
        end
        
        ParameterDataOffset{bCptr}.length=lengthSpaceCRVS;
        ParameterDataOffset{bCptr}.lengthcnt=lengthcnt;
        
    else
        
        numPnt=1001;
        
        UVcpr=zeros(2,numPnt);
        UV=zeros(2,numPnt);
        tcpr=zeros(1,numPnt);
        Pcpr=zeros(3,numPnt);
        SuBpr=zeros(3,numPnt);
        SvBpr=zeros(3,numPnt);
        nrmlBpr=zeros(3,numPnt);
        noNrmlBpr=zeros(1,numPnt);
        
        crvInd=bCptr;
        
        if ParameterData{crvInd}.type==126
            
            nrbDeg=ParameterData{crvInd}.m;
            numCtrlPnts=ParameterData{crvInd}.k+1;
            knots=ParameterData{crvInd}.t;
            
            tcpr(:)=pchip(0:(numCtrlPnts-nrbDeg),knots((nrbDeg+1):(numCtrlPnts+1)),linspace(0,numCtrlPnts-nrbDeg,numPnt));
            
            Pcpr(:,:)=nrbevalIGES(ParameterData{crvInd}.nurbs,tcpr);
            
            for kk=1:numPnt
                [~,miind]=min((Pcomp(1,:)-Pcpr(1,kk)).^2+(Pcomp(2,:)-Pcpr(2,kk)).^2+(Pcomp(3,:)-Pcpr(3,kk)).^2);
                UVcpr(:,kk)=UVcomp(:,miind);
            end
            
            [~,UV(:,:)]=closestNrbLinePointIGES(ParameterData{srfInd}.nurbs,ParameterData{srfInd}.dnurbs,ParameterData{srfInd}.d2nurbs,UVcpr,Pcpr);
            
            [~,SuBpr(:,:),SvBpr(:,:)]=nrbevalIGES(ParameterData{srfInd}.nurbs,UV,ParameterData{srfInd}.dnurbs);
            
            nrmlBpr(1,:)=SuBpr(2,:).*SvBpr(3,:)-SuBpr(3,:).*SvBpr(2,:);
            nrmlBpr(2,:)=SuBpr(3,:).*SvBpr(1,:)-SuBpr(1,:).*SvBpr(3,:);
            nrmlBpr(3,:)=SuBpr(1,:).*SvBpr(2,:)-SuBpr(2,:).*SvBpr(1,:);
            
            noNrmlBpr(:)=sqrt(sum(nrmlBpr.^2,1));
            
            nrmlBpr(1,:)=nrmlBpr(1,:)./noNrmlBpr;
            nrmlBpr(2,:)=nrmlBpr(2,:)./noNrmlBpr;
            nrmlBpr(3,:)=nrmlBpr(3,:)./noNrmlBpr;
            
            Pcpr(:,:)=Pcpr+signdist*nrmlBpr;
            
            coefs=ParameterData{crvInd}.nurbs.coefs;
            
            [NTN,R]=LScrvApp(Pcpr,nrbDeg,numCtrlPnts,tcpr,knots,coefs);
            
            coefs(1:3,1)=coefs(4,1)*Pcpr(:,1);
            coefs(1:3,numCtrlPnts)=coefs(4,end)*Pcpr(:,numPnt);
            coefs(1:3,2:(numCtrlPnts-1))=(NTN\R)';
            
            
            ParameterDataOffset{crvInd}.type=126;
            ParameterDataOffset{crvInd}.name='B-NURBS CRV';
            ParameterDataOffset{crvInd}.original=0;
            ParameterDataOffset{crvInd}.previous_type=ParameterData{crvInd}.type;
            ParameterDataOffset{crvInd}.previous_name=ParameterData{crvInd}.name;
            ParameterDataOffset{crvInd}.superior=0;
            ParameterDataOffset{crvInd}.k=numCtrlPnts-1;
            ParameterDataOffset{crvInd}.m=nrbDeg;
            
            ParameterDataOffset{crvInd}.prop1=1;
            ParameterDataOffset{crvInd}.prop2=1;
            ParameterDataOffset{crvInd}.prop3=1;
            ParameterDataOffset{crvInd}.prop4=1;
            
            ParameterDataOffset{crvInd}.t=knots;
            ParameterDataOffset{crvInd}.w=coefs(4,:);
            ParameterDataOffset{crvInd}.p=coefs(1:3,:);
            ParameterDataOffset{crvInd}.p(1,:)=coefs(1,:)./coefs(4,:);
            ParameterDataOffset{crvInd}.p(2,:)=coefs(2,:)./coefs(4,:);
            ParameterDataOffset{crvInd}.p(3,:)=coefs(3,:)./coefs(4,:);
            
            ParameterDataOffset{crvInd}.v=ParameterData{crvInd}.v;
            
            ParameterDataOffset{crvInd}.xnorm=0;
            ParameterDataOffset{crvInd}.ynorm=0;
            ParameterDataOffset{crvInd}.znorm=1;
            
            ParameterDataOffset{crvInd}.nurbs.form='B-NURBS';
            ParameterDataOffset{crvInd}.nurbs.dim=4;
            ParameterDataOffset{crvInd}.nurbs.number=numCtrlPnts;
            ParameterDataOffset{crvInd}.nurbs.coefs=coefs;
            ParameterDataOffset{crvInd}.nurbs.order=nrbDeg+1;
            ParameterDataOffset{crvInd}.nurbs.knots=knots;
            
            [ParameterDataOffset{crvInd}.dnurbs,ParameterDataOffset{crvInd}.d2nurbs]=nrbDerivativesIGES(ParameterDataOffset{crvInd}.nurbs);
            
            nup=500;
            p = nrbevalIGES(ParameterDataOffset{crvInd}.nurbs,linspace(ParameterDataOffset{crvInd}.v(1),ParameterDataOffset{crvInd}.v(2),nup));
            len=sum(sqrt(sum((p(:,1:(nup-1))-p(:,2:nup)).^2,1)));
            if norm(p(:,1)-p(:,nup))<1e-3
                ParameterDataOffset{crvInd}.length=3*len;
            else
                ParameterDataOffset{crvInd}.length=min((len/norm(p(:,1)-p(:,nup))-1)*10+1,3)*len;
            end
            
            ParameterDataOffset{crvInd}.well=true;
            
        elseif ParameterData{crvInd}.type==110
            
            Pcpr(:,1)=ParameterData{crvInd}.p1;
            Pcpr(:,2)=ParameterData{crvInd}.p2;
            
            for kk=1:2
                [~,miind]=min((Pcomp(1,:)-Pcpr(1,kk)).^2+(Pcomp(2,:)-Pcpr(2,kk)).^2+(Pcomp(3,:)-Pcpr(3,kk)).^2);
                UVcpr(:,kk)=UVcomp(:,miind);
            end
            
            [~,UV(:,1:2)]=closestNrbLinePointIGES(ParameterData{srfInd}.nurbs,ParameterData{srfInd}.dnurbs,ParameterData{srfInd}.d2nurbs,UVcpr(:,1:2),Pcpr(:,1:2));
            
            [~,SuBpr(:,1:2),SvBpr(:,1:2)]=nrbevalIGES(ParameterData{srfInd}.nurbs,UV(:,1:2),ParameterData{srfInd}.dnurbs);
            
            nrmlBpr(1,1:2)=SuBpr(2,1:2).*SvBpr(3,1:2)-SuBpr(3,1:2).*SvBpr(2,1:2);
            nrmlBpr(2,1:2)=SuBpr(3,1:2).*SvBpr(1,1:2)-SuBpr(1,1:2).*SvBpr(3,1:2);
            nrmlBpr(3,1:2)=SuBpr(1,1:2).*SvBpr(2,1:2)-SuBpr(2,1:2).*SvBpr(1,1:2);
            
            noNrmlBpr(1:2)=sqrt(sum(nrmlBpr(:,1:2).^2,1));
            
            nrmlBpr(1,1:2)=nrmlBpr(1,1:2)./noNrmlBpr(1:2);
            nrmlBpr(2,1:2)=nrmlBpr(2,1:2)./noNrmlBpr(1:2);
            nrmlBpr(3,1:2)=nrmlBpr(3,1:2)./noNrmlBpr(1:2);
            
            Pcpr(:,1:2)=Pcpr(:,1:2)+signdist*nrmlBpr(:,1:2);
            
            
            ParameterDataOffset{crvInd}.type=110;
            
            ParameterDataOffset{crvInd}.name='LINE';
            ParameterDataOffset{crvInd}.original=0;
            ParameterDataOffset{crvInd}.previous_type=ParameterData{crvInd}.type;
            ParameterDataOffset{crvInd}.previous_name=ParameterData{crvInd}.name;
            
            ParameterDataOffset{crvInd}.superior=0;
            
            ParameterDataOffset{crvInd}.form=0;
            
            ParameterDataOffset{crvInd}.p1=Pcpr(:,1);
            ParameterDataOffset{crvInd}.x1=Pcpr(1,1);
            ParameterDataOffset{crvInd}.y1=Pcpr(2,1);
            ParameterDataOffset{crvInd}.z1=Pcpr(3,1);
            
            ParameterDataOffset{crvInd}.p2=Pcpr(:,2);
            ParameterDataOffset{crvInd}.x2=Pcpr(1,2);
            ParameterDataOffset{crvInd}.y2=Pcpr(2,2);
            ParameterDataOffset{crvInd}.z2=Pcpr(3,2);
            
            ParameterDataOffset{crvInd}.length=norm(Pcpr(:,2)-Pcpr(:,1));
            
            ParameterDataOffset{crvInd}.well=true;
            
        end
        
    end
    
elseif ParameterData{srfInd}.type==108
    
    transl=signdist*ParameterData{srfInd}.normal;
    
    bCptr=ParameterData{ind}.cptr;
    
    if ParameterData{bCptr}.type==102
        
        numCrv=ParameterData{bCptr}.n;
        
        for jj=1:numCrv
            
            crvInd=ParameterData{bCptr}.de(jj);
            
            if ParameterData{crvInd}.type==126
                
                coefs=ParameterData{crvInd}.nurbs.coefs;
                coefs(1,:)=coefs(1,:)+transl(1)*coefs(4,:);
                coefs(2,:)=coefs(2,:)+transl(2)*coefs(4,:);
                coefs(3,:)=coefs(3,:)+transl(3)*coefs(4,:);
                
                ParameterDataOffset{crvInd}.type=126;
                ParameterDataOffset{crvInd}.name='B-NURBS CRV';
                ParameterDataOffset{crvInd}.original=0;
                ParameterDataOffset{crvInd}.previous_type=ParameterData{crvInd}.type;
                ParameterDataOffset{crvInd}.previous_name=ParameterData{crvInd}.name;
                
                ParameterDataOffset{crvInd}.w=coefs(4,:);
                ParameterDataOffset{crvInd}.p=coefs(1:3,:);
                ParameterDataOffset{crvInd}.p(1,:)=coefs(1,:)./coefs(4,:);
                ParameterDataOffset{crvInd}.p(2,:)=coefs(2,:)./coefs(4,:);
                ParameterDataOffset{crvInd}.p(3,:)=coefs(3,:)./coefs(4,:);
                
                ParameterDataOffset{crvInd}.nurbs.form='B-NURBS';
                ParameterDataOffset{crvInd}.nurbs.coefs=coefs;
                
            elseif ParameterData{crvInd}.type==110
                
                ParameterDataOffset{crvInd}.type=110;
                ParameterDataOffset{crvInd}.name='LINE';
                ParameterDataOffset{crvInd}.original=0;
                ParameterDataOffset{crvInd}.previous_type=ParameterData{crvInd}.type;
                ParameterDataOffset{crvInd}.previous_name=ParameterData{crvInd}.name;
                
                ParameterDataOffset{crvInd}.superior=0;
                
                ParameterDataOffset{crvInd}.form=0;
                
                ParameterDataOffset{crvInd}.p1=ParameterData{crvInd}.p1+transl;
                ParameterDataOffset{crvInd}.x1=ParameterDataOffset{crvInd}.p1(1);
                ParameterDataOffset{crvInd}.y1=ParameterDataOffset{crvInd}.p1(2);
                ParameterDataOffset{crvInd}.z1=ParameterDataOffset{crvInd}.p1(3);
                
                ParameterDataOffset{crvInd}.p2=ParameterData{crvInd}.p2+transl;
                ParameterDataOffset{crvInd}.x2=ParameterDataOffset{crvInd}.p2(1);
                ParameterDataOffset{crvInd}.y2=ParameterDataOffset{crvInd}.p2(2);
                ParameterDataOffset{crvInd}.z2=ParameterDataOffset{crvInd}.p2(3);
                
            end
            
        end
        
    else
        
        crvInd=bCptr;
        
        if ParameterData{crvInd}.type==126
            
            coefs=ParameterData{crvInd}.nurbs.coefs;
            coefs(1,:)=coefs(1,:)+transl(1)*coefs(4,:);
            coefs(2,:)=coefs(2,:)+transl(2)*coefs(4,:);
            coefs(3,:)=coefs(3,:)+transl(3)*coefs(4,:);
            
            ParameterDataOffset{crvInd}.type=126;
            ParameterDataOffset{crvInd}.name='B-NURBS CRV';
            ParameterDataOffset{crvInd}.original=0;
            ParameterDataOffset{crvInd}.previous_type=ParameterData{crvInd}.type;
            ParameterDataOffset{crvInd}.previous_name=ParameterData{crvInd}.name;
            
            ParameterDataOffset{crvInd}.w=coefs(4,:);
            ParameterDataOffset{crvInd}.p=coefs(1:3,:);
            ParameterDataOffset{crvInd}.p(1,:)=coefs(1,:)./coefs(4,:);
            ParameterDataOffset{crvInd}.p(2,:)=coefs(2,:)./coefs(4,:);
            ParameterDataOffset{crvInd}.p(3,:)=coefs(3,:)./coefs(4,:);
            
            ParameterDataOffset{crvInd}.nurbs.form='B-NURBS';
            ParameterDataOffset{crvInd}.nurbs.coefs=coefs;
            
        elseif ParameterData{crvInd}.type==110
            
            ParameterDataOffset{crvInd}.type=110;
            ParameterDataOffset{crvInd}.name='LINE';
            ParameterDataOffset{crvInd}.original=0;
            ParameterDataOffset{crvInd}.previous_type=ParameterData{crvInd}.type;
            ParameterDataOffset{crvInd}.previous_name=ParameterData{crvInd}.name;
            
            ParameterDataOffset{crvInd}.superior=0;
            
            ParameterDataOffset{crvInd}.form=0;
            
            ParameterDataOffset{crvInd}.p1=ParameterData{crvInd}.p1+transl;
            ParameterDataOffset{crvInd}.x1=ParameterDataOffset{crvInd}.p1(1);
            ParameterDataOffset{crvInd}.y1=ParameterDataOffset{crvInd}.p1(2);
            ParameterDataOffset{crvInd}.z1=ParameterDataOffset{crvInd}.p1(3);
            
            ParameterDataOffset{crvInd}.p2=ParameterData{crvInd}.p2+transl;
            ParameterDataOffset{crvInd}.x2=ParameterDataOffset{crvInd}.p2(1);
            ParameterDataOffset{crvInd}.y2=ParameterDataOffset{crvInd}.p2(2);
            ParameterDataOffset{crvInd}.z2=ParameterDataOffset{crvInd}.p2(3);
            
        end
        
    end
    
end
