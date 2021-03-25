function [ParameterData,EntityType,numEntityType,unknownEntityType,numunknownEntityType]=iges2matlab(igsfile,showlines)
% IGES2MATLAB extracts the parameter data in an IGES-file to a cell array
%
% Usage:
%
% [ParameterData,EntityType,numEntityType,unknownEntityType,numunknownEntityType]=...
%         iges2matlab(igsfile,showlines)
%
% Input:
%
% igsfile - IGES-file
% showlines - information flag to plotIGES (optional)
%             0 (default) show only lines in plotIGES associated with surfaces
%             1 show all lines in plotIGES
%
% Output:
%
% ParameterData - cell array with Parameter Data from the IGES-file
%                 (and some additional information)
% EntityType - vector with entities in igsfile converted to matlab
% numEntityType - vector with number of entities belonging to EntityType
% unknownEntityType - vector with unknown entities for iges2matlab
% numunknownEntityType - vector with number of unknown entities
%                        belonging to unknownEntityType
%
%
%
% For information about the IGES format
% Google for "Initial Graphics Exchange Specification"
%
% This version cannot handle all IGES entities
%
% Example:
%
% [ParameterData,EntityType,numEntityType,unknownEntityType]=iges2matlab('example.igs');
%
%
% m-file can be downloaded at
% http://www.mathworks.com/matlabcentral/fileexchange/13253-iges-toolbox
%
% written by Per Bergström 2014-10-28
%


if nargin<2
    showlines=0;
end

if isempty(showlines)
    showlines=0;
end
if not(or(showlines==0,showlines==1))
    showlines=0;
end

[fid,msg]=fopen(igsfile);
if fid==-1
    error(msg);
end
c = fread(fid,'uint8=>uint8')';
fclose(fid);

nwro=sum((c((81:82))==10))+sum((c((81:82))==13));
edfi=nwro-sum(c(((end-1):end))==10)-sum(c(((end-1):end))==13);
siz=length(c);
ro=round((siz+edfi)/(80+nwro));
if rem((siz+edfi),(80+nwro))~=0
    error('Input file must be an IGES-file!');
end

roind=1:ro;
SGDPT=c(roind*(80+nwro)-7-nwro);

Sfind=SGDPT==83;
Gfind=SGDPT==71;
Dfind=SGDPT==68;
Pfind=SGDPT==80;
Tfind=SGDPT==84;

sumSfind=sum(Sfind);
sumGfind=sum(Gfind);
sumDfind=sum(Dfind);
sumPfind=sum(Pfind);
sumTfind=sum(Tfind);

%------S Line information (The initial line to get things started)---------
for i=roind(Sfind)
    disp(char(c(((i-1)*(80+nwro)+1):(i*(80+nwro)-8-nwro))));
end

%---------------G Line information  (Header infomation)--------------------

G=cell(1,25);
Gstr=zeros(1,72*sumGfind);
j=1;
for i=roind(Gfind)
    Gstr(((j-1)*72+1):(j*72))=c(((i-1)*(80+nwro)+1):(i*(80+nwro)-8-nwro));
    j=j+1;
end

if and(Gstr(1)==49,Gstr(2)==72)
    G{1}=Gstr(3);
    st=4;
else
    G{1}=44;
    st=1;
end

if and(Gstr(st+1)==49,Gstr(st+2)==72)
    G{2}=Gstr(st+3);
    st=st+4;
else
    G{2}=59;
    st=st+1;
end

le=length(Gstr);
for i=3:25
    for j=(st+1):le
        if or(Gstr(j)==G{1},Gstr(j)==G{2})
            break
        end
    end
    G{i}=Gstr((st+1):(j-1));
    st=j;
end

for i=[3 4 5 6 12 15 18 21 22 25]   %string
    stind=1;
    for j=1:length(G{i})
        if G{i}(j)~=32
            stind=j;
            break
        end
    end
    for j=stind:length(G{i})
        if G{i}(j)==72
            stind=j+1;
            break
        end
    end
    endind=length(G{i});
    for j=length(G{i}):-1:1
        if G{i}(j)~=32
            endind=j;
            break
        end
    end
    G{i}=G{i}(stind:endind);
end

for i=[7 8 9 10 11 13 14 16 17 19 20 23 24]   %num
    G{i}=str2num(char(G{i}));
end

%--D Line information (Data information) & P Line information (All data)---

noent=round(sumDfind/2);
ParameterData=cell(1,noent);
roP=sumSfind+sumGfind+sumDfind;

entty=zeros(1,520);
entunk=zeros(1,520);

% Default color
defaultColor=[0.8,0.8,0.9];

subfiguresExists=false;
transformationExists=false;
offsetsurfaceExists=false;

[spline2BezierCrvMat,spline2BezierSrfMat]=matrixSpline2Bezier();

mat3x3=zeros(3);

% Reads the parameter data

entiall=0;
for i=(sumSfind+sumGfind+1):2:(sumSfind+sumGfind+sumDfind-1)
    
    entiall=entiall+1;
    Dstr1=c(((i-1)*(80+nwro)+1):(i*(80+nwro)-8-nwro));
    Dstr2=c((i*(80+nwro)+1):((i+1)*(80+nwro)-8-nwro));
    
    type=str2num(char(Dstr1(1:8)));
    transformationMatrixPtr=str2num(char(Dstr1(49:56)));
    if isempty(transformationMatrixPtr)
        transformationMatrixPtr=0;
    end
    colorNo=str2num(char(Dstr2(17:24)));
    if isempty(colorNo)
        colorNo=0;
    end
    formNo=str2num(char(Dstr2(33:40)));
    if isempty(formNo)
        formNo=0;
    end
    
    if transformationMatrixPtr>0
        transformationMatrixPtr=round((transformationMatrixPtr+1)/2);
    end
    if colorNo<0
        colorNo=-round((-colorNo+1)/2);
    end
    
    Pstart=str2num(char(Dstr1(9:16)))+roP;
    
    if i==roP-1
        Pend=ro-sumTfind;
    else
        Pend=str2num(char(c(((i+1)*(80+nwro)+9):((i+1)*(80+nwro)+16))))+roP-1;
    end
    
    Pstr=zeros(1,64*(Pend-Pstart+1));
    j=1;
    for k=Pstart:Pend
        Pstr(((j-1)*64+1):(j*64))=c(((k-1)*(80+nwro)+1):(k*(80+nwro)-16-nwro));
        j=j+1;
    end
    
    Pstr(Pstr==G{1})=44;
    Pstr(Pstr==G{2})=59;
    
    Pvec=str2num(char(Pstr));
    
    % Store the entities
    
    ParameterData{entiall}.type=type;
    
    entty(type)=entty(type)+1;
    
    % SURFACES
    
    if type==128
        
        A=1+Pvec(2)+Pvec(4);
        B=1+Pvec(3)+Pvec(5);
        C=(Pvec(2)+1)*(Pvec(3)+1);
        
        ParameterData{entiall}.name='B-NURBS SRF';
        ParameterData{entiall}.original=1;
        
        ParameterData{entiall}.superior=0;
        
        ParameterData{entiall}.k1=Pvec(2);
        ParameterData{entiall}.k2=Pvec(3);
        ParameterData{entiall}.m1=Pvec(4);
        ParameterData{entiall}.m2=Pvec(5);
        
        ParameterData{entiall}.prop1=Pvec(6);
        ParameterData{entiall}.prop2=Pvec(7);
        ParameterData{entiall}.prop3=Pvec(8);
        ParameterData{entiall}.prop4=Pvec(10);
        ParameterData{entiall}.prop5=Pvec(11);
        
        ParameterData{entiall}.s=Pvec(11:(11+A));
        ParameterData{entiall}.t=Pvec((12+A):(12+A+B));
        
        ParameterData{entiall}.w=reshape(Pvec((13+A+B):(12+A+B+C)),Pvec(2)+1,Pvec(3)+1);
        ParameterData{entiall}.p=reshape(Pvec((13+A+B+C):(12+A+B+4*C)),3,Pvec(2)+1,Pvec(3)+1);
        
        ParameterData{entiall}.u=zeros(1,2);
        ParameterData{entiall}.u(1)=Pvec(13+A+B+4*C);
        ParameterData{entiall}.u(2)=Pvec(14+A+B+4*C);
        
        ParameterData{entiall}.v=zeros(1,2);
        ParameterData{entiall}.v(1)=Pvec(15+A+B+4*C);
        ParameterData{entiall}.v(2)=Pvec(16+A+B+4*C);
        
        ulinear=1;
        for k=1:(ParameterData{entiall}.k2+1)
            meaP=mean(ParameterData{entiall}.p(:,:,k),2);
            Si=svd(ParameterData{entiall}.p(:,:,k)*ParameterData{entiall}.p(:,:,k)'-((ParameterData{entiall}.k1+1)*meaP)*meaP');
            if Si(2)*1e6>Si(1)
                ulinear=0;
                break
            end
        end
        if ulinear
            vlinear=0;
        else
            vlinear=1;
            for j=1:(ParameterData{entiall}.k1+1)
                meaP(:)=0;
                mat3x3(:)=0;
                for k=1:(ParameterData{entiall}.k2+1)
                    meaP=meaP+ParameterData{entiall}.p(:,j,k);
                    mat3x3=mat3x3+ParameterData{entiall}.p(:,j,k)*ParameterData{entiall}.p(:,j,k)';
                end
                Si=svd((ParameterData{entiall}.k2+1)*mat3x3-meaP*meaP');
                if Si(2)*1e6>Si(1)
                    vlinear=0;
                    break
                end
            end
        end
        ParameterData{entiall}.isplane=false;
        ParameterData{entiall}.ulinear=ulinear;
        ParameterData{entiall}.vlinear=vlinear;
        
        % NURBS surface
        
        ParameterData{entiall}.nurbs.form='B-NURBS';
        
        ParameterData{entiall}.nurbs.dim=4;
        
        ParameterData{entiall}.nurbs.number=zeros(1,2);
        ParameterData{entiall}.nurbs.number(1)=Pvec(2)+1;
        ParameterData{entiall}.nurbs.number(2)=Pvec(3)+1;
        
        ParameterData{entiall}.nurbs.coefs=zeros(4,Pvec(2)+1,Pvec(3)+1);
        ParameterData{entiall}.nurbs.coefs(4,:,:)=reshape(Pvec((13+A+B):(12+A+B+C)),Pvec(2)+1,Pvec(3)+1);
        ParameterData{entiall}.nurbs.coefs(1:3,:,:)=ParameterData{entiall}.p;
        
        ParameterData{entiall}.nurbs.coefs(1:3,:,:)=repmat(ParameterData{entiall}.nurbs.coefs(4,:,:),3,1).*ParameterData{entiall}.nurbs.coefs(1:3,:,:);
        
        ParameterData{entiall}.nurbs.knots=cell(1,2);
        ParameterData{entiall}.nurbs.knots{1}=Pvec(11:(11+A));
        ParameterData{entiall}.nurbs.knots{2}=Pvec((12+A):(12+A+B));
        
        ParameterData{entiall}.nurbs.order=zeros(1,2);
        ParameterData{entiall}.nurbs.order(1)=Pvec(4)+1;
        ParameterData{entiall}.nurbs.order(2)=Pvec(5)+1;
        
        [ParameterData{entiall}.dnurbs,ParameterData{entiall}.d2nurbs]=nrbDerivativesIGES(ParameterData{entiall}.nurbs);
        
        ParameterData{entiall}.ratio=[0,0];
        
        ParameterData{entiall}.trnsfrmtnmtrx=transformationMatrixPtr;
        
        ParameterData{entiall}.clrnmbr=colorNo;
        ParameterData{entiall}.color=[0,0,0];
        
        ParameterData{entiall}.well=true;
        
    elseif type==114
        
        ParameterData{entiall}.name='PARAMETRIC SPLINE SURFACE';
        
        ParameterData{entiall}.original=1;
        
        ParameterData{entiall}.ctype=Pvec(2);
        ParameterData{entiall}.ptype=Pvec(3);
        
        ParameterData{entiall}.m=Pvec(4);
        ParameterData{entiall}.n=Pvec(5);
        
        ParameterData{entiall}.tu=Pvec(6:(6+ParameterData{entiall}.m));
        ParameterData{entiall}.tv=Pvec((7+ParameterData{entiall}.m):(7+ParameterData{entiall}.m+ParameterData{entiall}.n));
        
        ParameterData{entiall}.a2s=zeros(3,16,ParameterData{entiall}.m,ParameterData{entiall}.n);
        
        ind=8+ParameterData{entiall}.m+ParameterData{entiall}.n;
        
        for ii=1:ParameterData{entiall}.m
            for jj=1:ParameterData{entiall}.n
                ParameterData{entiall}.a2s(1,:,ii,jj)=Pvec(ind:(ind+15));
                ParameterData{entiall}.a2s(2,:,ii,jj)=Pvec((ind+16):(ind+31));
                ParameterData{entiall}.a2s(3,:,ii,jj)=Pvec((ind+32):(ind+47));
                ind=ind+48;
            end
            ind=ind+48;
        end
        
        ParameterData{entiall}.type=128;
        ParameterData{entiall}.name='B-NURBS SRF';
        ParameterData{entiall}.original=1;
        
        ParameterData{entiall}.previous_type=114;
        ParameterData{entiall}.previous_name='PARAMETRIC SPLINE SURFACE';
        
        ParameterData{entiall}.k1=2*ParameterData{entiall}.m+1;
        ParameterData{entiall}.k2=2*ParameterData{entiall}.n+1;
        ParameterData{entiall}.m1=3;
        ParameterData{entiall}.m2=3;
        
        ParameterData{entiall}.prop1=0;
        ParameterData{entiall}.prop2=0;
        ParameterData{entiall}.prop3=1;
        ParameterData{entiall}.prop4=0;
        ParameterData{entiall}.prop5=0;
        
        ParameterData{entiall}.superior=0;
        
        ParameterData{entiall}.s=zeros(1,8+2*(ParameterData{entiall}.m-1));
        ParameterData{entiall}.s(1:4)=ParameterData{entiall}.tu(1);
        ParameterData{entiall}.s((5+2*(ParameterData{entiall}.m-1)):(8+2*(ParameterData{entiall}.m-1)))=ParameterData{entiall}.tu(ParameterData{entiall}.m+1);
        
        ParameterData{entiall}.t=zeros(1,8+2*(ParameterData{entiall}.n-1));
        ParameterData{entiall}.t(1:4)=ParameterData{entiall}.tv(1);
        ParameterData{entiall}.t((5+2*(ParameterData{entiall}.n-1)):(8+2*(ParameterData{entiall}.n-1)))=ParameterData{entiall}.tv(ParameterData{entiall}.n+1);
        
        for ii=2:ParameterData{entiall}.m
            ParameterData{entiall}.s(2*ii+1)=ParameterData{entiall}.tu(ii);
            ParameterData{entiall}.s(2*ii+2)=ParameterData{entiall}.tu(ii);
        end
        for ii=2:ParameterData{entiall}.n
            ParameterData{entiall}.t(2*ii+1)=ParameterData{entiall}.tv(ii);
            ParameterData{entiall}.t(2*ii+2)=ParameterData{entiall}.tv(ii);
        end
        
        CP=zeros(3,2*ParameterData{entiall}.m+2,2*ParameterData{entiall}.n+2);
        splinePoints=zeros(3,16);
        
        if ParameterData{entiall}.m==1
            
            len=ParameterData{entiall}.tu(2)-ParameterData{entiall}.tu(1);
            
            if ParameterData{entiall}.n==1
                
                [scaleV,scaleU]=meshgrid((ParameterData{entiall}.tv(2)-ParameterData{entiall}.tv(1)).^(0:3),len.^(0:3));
                scaling=(scaleV(:).*scaleU(:))';
                
                splinePoints(:,:)=ParameterData{entiall}.a2s(:,:,1,1);
                splinePoints(1,:)=splinePoints(1,:).*scaling;
                splinePoints(2,:)=splinePoints(2,:).*scaling;
                splinePoints(3,:)=splinePoints(3,:).*scaling;
                
                splinePoints(:,:)=splinePoints*spline2BezierSrfMat;
                
                CP(:,:)=splinePoints;
                
            else
                
                [scaleV,scaleU]=meshgrid((ParameterData{entiall}.tv(2)-ParameterData{entiall}.tv(1)).^(0:3),len.^(0:3));
                scaling=(scaleV(:).*scaleU(:))';
                
                splinePoints(:,:)=ParameterData{entiall}.a2s(:,:,1,1);
                splinePoints(1,:)=splinePoints(1,:).*scaling;
                splinePoints(2,:)=splinePoints(2,:).*scaling;
                splinePoints(3,:)=splinePoints(3,:).*scaling;
                
                splinePoints(:,:)=splinePoints*spline2BezierSrfMat;
                
                CP(:,1:12)=splinePoints(:,1:12);
                
                for jj=2:(ParameterData{entiall}.n-1)
                    
                    [scaleV,scaleU]=meshgrid((ParameterData{entiall}.tv(jj+1)-ParameterData{entiall}.tv(jj)).^(0:3),len.^(0:3));
                    scaling=(scaleV(:).*scaleU(:))';
                    
                    splinePoints(:,:)=ParameterData{entiall}.a2s(:,:,1,jj);
                    splinePoints(1,:)=splinePoints(1,:).*scaling;
                    splinePoints(2,:)=splinePoints(2,:).*scaling;
                    splinePoints(3,:)=splinePoints(3,:).*scaling;
                    
                    splinePoints(:,:)=splinePoints*spline2BezierSrfMat;
                    
                    CP(:,(8*jj-3):(8*jj+4))=splinePoints(:,5:12);
                    
                end
                
                [scaleV,scaleU]=meshgrid((ParameterData{entiall}.tv(ParameterData{entiall}.n+1)-ParameterData{entiall}.tv(ParameterData{entiall}.n)).^(0:3),len.^(0:3));
                scaling=(scaleV(:).*scaleU(:))';
                
                splinePoints(:,:)=ParameterData{entiall}.a2s(:,:,1,ParameterData{entiall}.n);
                splinePoints(1,:)=splinePoints(1,:).*scaling;
                splinePoints(2,:)=splinePoints(2,:).*scaling;
                splinePoints(3,:)=splinePoints(3,:).*scaling;
                
                splinePoints(:,:)=splinePoints*spline2BezierSrfMat;
                
                CP(:,(8*ParameterData{entiall}.n-3):(8*ParameterData{entiall}.n+8))=splinePoints(:,5:16);
                
            end
            
        elseif ParameterData{entiall}.n==1
            
            len=ParameterData{entiall}.tv(2)-ParameterData{entiall}.tv(1);
            
            [scaleV,scaleU]=meshgrid(len.^(0:3),(ParameterData{entiall}.tu(2)-ParameterData{entiall}.tu(1)).^(0:3));
            scaling=(scaleV(:).*scaleU(:))';
            
            splinePoints(:,:)=ParameterData{entiall}.a2s(:,:,1,1);
            splinePoints(1,:)=splinePoints(1,:).*scaling;
            splinePoints(2,:)=splinePoints(2,:).*scaling;
            splinePoints(3,:)=splinePoints(3,:).*scaling;
            
            splinePoints(:,:)=splinePoints*spline2BezierSrfMat;
            
            CP(:,1:3,1)=splinePoints(:,1:3);
            CP(:,1:3,2)=splinePoints(:,5:7);
            CP(:,1:3,3)=splinePoints(:,9:11);
            CP(:,1:3,4)=splinePoints(:,13:15);
            
            for ii=2:(ParameterData{entiall}.m-1)
                
                [scaleV,scaleU]=meshgrid(len.^(0:3),(ParameterData{entiall}.tu(ii+1)-ParameterData{entiall}.tu(ii)).^(0:3));
                scaling=(scaleV(:).*scaleU(:))';
                
                splinePoints(:,:)=ParameterData{entiall}.a2s(:,:,ii,1);
                splinePoints(1,:)=splinePoints(1,:).*scaling;
                splinePoints(2,:)=splinePoints(2,:).*scaling;
                splinePoints(3,:)=splinePoints(3,:).*scaling;
                
                splinePoints(:,:)=splinePoints*spline2BezierSrfMat;
                
                CP(:,(2*ii):(2*ii+1),1)=splinePoints(:,2:3);
                CP(:,(2*ii):(2*ii+1),2)=splinePoints(:,6:7);
                CP(:,(2*ii):(2*ii+1),3)=splinePoints(:,10:11);
                CP(:,(2*ii):(2*ii+1),4)=splinePoints(:,14:15);
                
            end
            
            [scaleV,scaleU]=meshgrid(len.^(0:3),(ParameterData{entiall}.tu(ParameterData{entiall}.m+1)-ParameterData{entiall}.tu(ParameterData{entiall}.m)).^(0:3));
            scaling=(scaleV(:).*scaleU(:))';
            
            splinePoints(:,:)=ParameterData{entiall}.a2s(:,:,ParameterData{entiall}.m,1);
            splinePoints(1,:)=splinePoints(1,:).*scaling;
            splinePoints(2,:)=splinePoints(2,:).*scaling;
            splinePoints(3,:)=splinePoints(3,:).*scaling;
            
            splinePoints(:,:)=splinePoints*spline2BezierSrfMat;
            
            CP(:,(2*ParameterData{entiall}.m):(2*ParameterData{entiall}.m+2),1)=splinePoints(:,2:4);
            CP(:,(2*ParameterData{entiall}.m):(2*ParameterData{entiall}.m+2),2)=splinePoints(:,6:8);
            CP(:,(2*ParameterData{entiall}.m):(2*ParameterData{entiall}.m+2),3)=splinePoints(:,10:12);
            CP(:,(2*ParameterData{entiall}.m):(2*ParameterData{entiall}.m+2),4)=splinePoints(:,14:16);
            
        else
            
            disp(['Warning: Could not handle entity type 114 correctly in ',igsfile,'.']);
            
        end
        
        ParameterData{entiall}.w=ones(2*ParameterData{entiall}.m+2,2*ParameterData{entiall}.n+2);
        ParameterData{entiall}.p=CP;
        
        ParameterData{entiall}.u=[ParameterData{entiall}.tu(1),ParameterData{entiall}.tu(ParameterData{entiall}.m+1)];
        ParameterData{entiall}.v=[ParameterData{entiall}.tv(1),ParameterData{entiall}.tv(ParameterData{entiall}.n+1)];
        
        ulinear=1;
        for k=1:(ParameterData{entiall}.k2+1)
            meaP=mean(ParameterData{entiall}.p(:,:,k),2);
            Si=svd(ParameterData{entiall}.p(:,:,k)*ParameterData{entiall}.p(:,:,k)'-((ParameterData{entiall}.k1+1)*meaP)*meaP');
            if Si(2)*1e6>Si(1)
                ulinear=0;
                break
            end
        end
        if ulinear
            vlinear=0;
        else
            vlinear=1;
            for j=1:(ParameterData{entiall}.k1+1)
                meaP(:)=0;
                mat3x3(:)=0;
                for k=1:(ParameterData{entiall}.k2+1)
                    meaP=meaP+ParameterData{entiall}.p(:,j,k);
                    mat3x3=mat3x3+ParameterData{entiall}.p(:,j,k)*ParameterData{entiall}.p(:,j,k)';
                end
                Si=svd((ParameterData{entiall}.k2+1)*mat3x3-meaP*meaP');
                if Si(2)*1e6>Si(1)
                    vlinear=0;
                    break
                end
            end
        end
        ParameterData{entiall}.isplane=false;
        ParameterData{entiall}.ulinear=ulinear;
        ParameterData{entiall}.vlinear=vlinear;
        
        % NURBS surface
        
        ParameterData{entiall}.nurbs.form='B-NURBS';
        
        ParameterData{entiall}.nurbs.dim=4;
        
        ParameterData{entiall}.nurbs.number=[2*ParameterData{entiall}.m+2,2*ParameterData{entiall}.n+2];
        
        ParameterData{entiall}.nurbs.coefs=zeros(4,2*ParameterData{entiall}.m+2,2*ParameterData{entiall}.n+2);
        ParameterData{entiall}.nurbs.coefs(4,:,:)=1;
        ParameterData{entiall}.nurbs.coefs(1:3,:,:)=CP;
        
        ParameterData{entiall}.nurbs.knots=cell(1,2);
        ParameterData{entiall}.nurbs.knots{1}=ParameterData{entiall}.s;
        ParameterData{entiall}.nurbs.knots{2}=ParameterData{entiall}.t;
        
        ParameterData{entiall}.nurbs.order=[4,4];
        
        [ParameterData{entiall}.dnurbs,ParameterData{entiall}.d2nurbs]=nrbDerivativesIGES(ParameterData{entiall}.nurbs);
        
        ParameterData{entiall}.ratio=[0,0];
        
        ParameterData{entiall}.trnsfrmtnmtrx=transformationMatrixPtr;
        
        ParameterData{entiall}.clrnmbr=colorNo;
        ParameterData{entiall}.color=[0,0,0];
        
        ParameterData{entiall}.well=true;
        
    elseif type==118
        
        ParameterData{entiall}.name='RULED SURFACE';
        
        ParameterData{entiall}.original=1;
        
        ParameterData{entiall}.de1=round((Pvec(2)+1)/2);
        ParameterData{entiall}.de2=round((Pvec(3)+1)/2);
        ParameterData{entiall}.dirflg=Pvec(4);
        ParameterData{entiall}.devflg=Pvec(5);
        
        ParameterData{entiall}.superior=0;
        
        ParameterData{entiall}.trnsfrmtnmtrx=transformationMatrixPtr;
        
        ParameterData{entiall}.clrnmbr=colorNo;
        ParameterData{entiall}.color=[0,0,0];
        
        ParameterData{entiall}.form=formNo;
        
        ParameterData{entiall}.ratio=[0,0];
        
        ParameterData{entiall}.well=true;
        
        ParameterData{entiall}.isplane=false;
        ParameterData{entiall}.ulinear=0;
        ParameterData{entiall}.vlinear=1;
        
    elseif type==120
        
        ParameterData{entiall}.name='SURFACE OF REVOLUTION';
        
        ParameterData{entiall}.original=1;
        
        ParameterData{entiall}.l=round((Pvec(2)+1)/2);
        ParameterData{entiall}.c=round((Pvec(3)+1)/2);
        ParameterData{entiall}.sa=Pvec(4);
        ParameterData{entiall}.ta=Pvec(5);
        
        ParameterData{entiall}.superior=0;
        
        ParameterData{entiall}.trnsfrmtnmtrx=transformationMatrixPtr;
        
        ParameterData{entiall}.clrnmbr=colorNo;
        ParameterData{entiall}.color=[0,0,0];
        
        ParameterData{entiall}.ratio=[0,0];
        
        ParameterData{entiall}.well=true;
        
        ParameterData{entiall}.isplane=false;
        ParameterData{entiall}.ulinear=0;
        ParameterData{entiall}.vlinear=0;
        
    elseif type==122
        
        ParameterData{entiall}.name='TABULATED CYLINDER';
        
        ParameterData{entiall}.original=1;
        
        ParameterData{entiall}.de=round((Pvec(2)+1)/2);
        ParameterData{entiall}.lx=Pvec(3);
        ParameterData{entiall}.ly=Pvec(4);
        ParameterData{entiall}.lz=Pvec(5);
        
        ParameterData{entiall}.superior=0;
        
        ParameterData{entiall}.trnsfrmtnmtrx=transformationMatrixPtr;
        
        ParameterData{entiall}.clrnmbr=colorNo;
        ParameterData{entiall}.color=[0,0,0];
        
        ParameterData{entiall}.ratio=[0,0];
        
        ParameterData{entiall}.well=true;
        
        ParameterData{entiall}.isplane=false;
        ParameterData{entiall}.ulinear=0;
        ParameterData{entiall}.vlinear=1;
        
    elseif type==140
        
        offsetsurfaceExists=true;
        
        ParameterData{entiall}.name='OFFSET SURFACE';
        
        ParameterData{entiall}.original=1;
        
        ParameterData{entiall}.nx=Pvec(2);
        ParameterData{entiall}.ny=Pvec(3);
        ParameterData{entiall}.nz=Pvec(4);
        ParameterData{entiall}.d=Pvec(5);
        ParameterData{entiall}.de=round((Pvec(6)+1)/2);
        
        ParameterData{entiall}.superior=0;
        
        ParameterData{entiall}.trnsfrmtnmtrx=transformationMatrixPtr;
        
        ParameterData{entiall}.clrnmbr=colorNo;
        ParameterData{entiall}.color=[0,0,0];
        
        ParameterData{entiall}.ratio=[0,0];
        
        ParameterData{entiall}.well=true;
        
        ParameterData{entiall}.isplane=false;
        ParameterData{entiall}.ulinear=0;
        ParameterData{entiall}.vlinear=0;
        
    elseif type==143
        
        ParameterData{entiall}.name='BOUNDED SURFACE';
        
        ParameterData{entiall}.original=1;
        
        ParameterData{entiall}.trimmed=1;
        
        ParameterData{entiall}.ratio=[0,0];
        
        ParameterData{entiall}.boundarytype=Pvec(2);
        
        ParameterData{entiall}.sptr=round((Pvec(3)+1)/2);
        
        ParameterData{entiall}.n=Pvec(4);
        
        ParameterData{entiall}.bdpt=round((Pvec(5:(4+Pvec(4)))+1)/2);
        
        ParameterData{entiall}.mlcrv=0;
        
        ParameterData{entiall}.nument=0;
        
        ParameterData{entiall}.clrnmbr=colorNo;
        ParameterData{entiall}.color=[0,0,0];
        
        if Pvec(2)==1
            ParameterData{entiall}.well=true;
        else
            entunk(type)=entunk(type)+1;
            entty(type)=entty(type)-1;
            ParameterData{entiall}.well=false;
        end
        
    elseif type==144
        
        ParameterData{entiall}.name='TRIMMED SURFACE';
        
        ParameterData{entiall}.original=1;
        
        ParameterData{entiall}.trimmed=1;
        
        ParameterData{entiall}.ratio=[0,0];
        
        ParameterData{entiall}.pts=round((Pvec(2)+1)/2);
        
        ParameterData{entiall}.n1=Pvec(3);
        ParameterData{entiall}.n2=Pvec(4);
        
        if Pvec(5)~=0
            ParameterData{entiall}.pto=round((Pvec(5)+1)/2);
        else
            ParameterData{entiall}.pto=0;
        end
        
        ParameterData{entiall}.pti=round((Pvec(6:(5+Pvec(4)))+1)/2);
        
        ParameterData{entiall}.mlcrv=0;
        
        ParameterData{entiall}.nument=0;
        
        ParameterData{entiall}.clrnmbr=colorNo;
        ParameterData{entiall}.color=[0,0,0];
        
        ParameterData{entiall}.well=true;
        
    elseif type==108
        
        ParameterData{entiall}.name='PLANE';
        ParameterData{entiall}.original=1;
        
        ParameterData{entiall}.superior=1;
        
        ParameterData{entiall}.a=Pvec(2);
        ParameterData{entiall}.b=Pvec(3);
        ParameterData{entiall}.c=Pvec(4);
        ParameterData{entiall}.d=Pvec(5);
        
        if Pvec(6)==0
            ParameterData{entiall}.ptr=0;
        else
            ParameterData{entiall}.ptr=round((Pvec(6)+1)/2);
        end
        
        ParameterData{entiall}.x=Pvec(7);
        ParameterData{entiall}.y=Pvec(8);
        ParameterData{entiall}.z=Pvec(9);
        ParameterData{entiall}.size=Pvec(10);
        
        ParameterData{entiall}.normal=[Pvec(2);Pvec(3);Pvec(4)];
        
        ParameterData{entiall}.trnsfrmtnmtrx=transformationMatrixPtr;
        
        ParameterData{entiall}.clrnmbr=colorNo;
        ParameterData{entiall}.color=[0,0,0];
        
        ParameterData{entiall}.ratio=[1,1];
        
        ParameterData{entiall}.well=true;
        
        ParameterData{entiall}.isplane=true;
        ParameterData{entiall}.ulinear=1;
        ParameterData{entiall}.vlinear=1;
        
        % CURVES
        
    elseif type==126
        
        A=1+Pvec(2)+Pvec(3);
        
        ParameterData{entiall}.name='B-NURBS CRV';
        ParameterData{entiall}.original=1;
        
        if showlines
            ParameterData{entiall}.superior=0;
        else
            ParameterData{entiall}.superior=1;
        end
        
        ParameterData{entiall}.k=Pvec(2);
        ParameterData{entiall}.m=Pvec(3);
        
        ParameterData{entiall}.prop1=Pvec(4);
        ParameterData{entiall}.prop2=Pvec(5);
        ParameterData{entiall}.prop3=Pvec(6);
        ParameterData{entiall}.prop4=Pvec(7);
        
        ParameterData{entiall}.t=Pvec(8:(8+A));
        ParameterData{entiall}.w=Pvec((9+A):(9+A+Pvec(2)));
        ParameterData{entiall}.p=reshape(Pvec((10+A+Pvec(2)):(12+A+4*Pvec(2))),3,Pvec(2)+1);
        
        ParameterData{entiall}.v=zeros(1,2);
        ParameterData{entiall}.v(1)=Pvec(13+A+4*Pvec(2));
        ParameterData{entiall}.v(2)=Pvec(14+A+4*Pvec(2));
        
        if Pvec(4)
            ParameterData{entiall}.xnorm=Pvec(15+A+4*Pvec(2));
            ParameterData{entiall}.ynorm=Pvec(16+A+4*Pvec(2));
            ParameterData{entiall}.znorm=Pvec(17+A+4*Pvec(2));
        else
            ParameterData{entiall}.xnorm=0;
            ParameterData{entiall}.ynorm=0;
            ParameterData{entiall}.znorm=0;
        end
        
        % NURBS curve
        
        ParameterData{entiall}.nurbs.form='B-NURBS';
        
        ParameterData{entiall}.nurbs.dim=4;
        
        ParameterData{entiall}.nurbs.number=Pvec(2)+1;
        
        ParameterData{entiall}.nurbs.coefs=zeros(4,Pvec(2)+1);
        ParameterData{entiall}.nurbs.coefs(4,:)=Pvec((9+A):(9+A+Pvec(2)));
        
        ParameterData{entiall}.nurbs.coefs(1:3,:)=ParameterData{entiall}.p;
        
        ParameterData{entiall}.nurbs.coefs(1:3,:)=repmat(ParameterData{entiall}.nurbs.coefs(4,:),3,1).*ParameterData{entiall}.nurbs.coefs(1:3,:);
        
        ParameterData{entiall}.nurbs.order=Pvec(3)+1;
        
        ParameterData{entiall}.nurbs.knots=Pvec(8:(8+A));
        
        [ParameterData{entiall}.dnurbs,ParameterData{entiall}.d2nurbs]=nrbDerivativesIGES(ParameterData{entiall}.nurbs);
        
        ParameterData{entiall}.length=0;
        
        ParameterData{entiall}.trnsfrmtnmtrx=transformationMatrixPtr;
        
        ParameterData{entiall}.clrnmbr=colorNo;
        ParameterData{entiall}.color=[0,0,0];
        
        ParameterData{entiall}.numcrv=1;
        
        ParameterData{entiall}.evalmthd=0;
        
        ParameterData{entiall}.well=true;
        
        clear nup p len N A
        
    elseif type==100
        
        ParameterData{entiall}.type=126;
        
        zt=Pvec(2);
        x1=Pvec(3);
        y1=Pvec(4);
        x2=Pvec(5);
        y2=Pvec(6);
        x3=Pvec(7);
        y3=Pvec(8);
        
        R=0.5*(sqrt((x2-x1)^2+(y2-y1)^2)+sqrt((x3-x1)^2+(y3-y1)^2));
        
        vmin=atan2(y2-y1,x2-x1);
        vmax=atan2(y3-y1,x3-x1);
        
        if vmin<0
            vmin=vmin+2*pi;
        end
        if vmax<0
            vmax=vmax+2*pi;
        end
        if vmax<vmin
            vmax=vmax+2*pi;
        end
        if (vmax-vmin)<1e-12
            vmax=vmax+2*pi;
        end
        
        PP=zeros(3,7);
        
        wodd=cos((vmax-vmin)/6);
        
        betavec=linspace(vmin,vmax,7);
        
        eve=true;
        
        for ii=1:7
            
            if eve
                cob=cos(betavec(ii));
                sib=sin(betavec(ii));
                eve=false;
            else
                cob=cos(betavec(ii))/wodd;
                sib=sin(betavec(ii))/wodd;
                eve=true;
            end
            
            PP(1,ii)=R*cob+x1;
            PP(2,ii)=R*sib+y1;
            PP(3,ii)=zt;
            
        end
        
        ParameterData{entiall}.name='B-NURBS CRV';
        ParameterData{entiall}.original=0;
        ParameterData{entiall}.previous_type=100;
        ParameterData{entiall}.previous_name='CIRCULAR ARC';
        
        ParameterData{entiall}.zt=zt;
        ParameterData{entiall}.x1=x1;
        ParameterData{entiall}.y1=y1;
        ParameterData{entiall}.x2=x2;
        ParameterData{entiall}.y2=y2;
        ParameterData{entiall}.x3=x3;
        ParameterData{entiall}.y3=y3;
        
        if showlines
            ParameterData{entiall}.superior=0;
        else
            ParameterData{entiall}.superior=1;
        end
        
        ParameterData{entiall}.k=6;
        ParameterData{entiall}.m=2;
        
        ParameterData{entiall}.prop1=1;
        ParameterData{entiall}.prop2=0;
        ParameterData{entiall}.prop3=0;
        ParameterData{entiall}.prop4=0;
        
        ParameterData{entiall}.t=[0 0 0 1/3 1/3 2/3 2/3 1 1 1]*(vmax-vmin)+vmin;
        
        ParameterData{entiall}.w=[1 wodd 1 wodd 1 wodd 1];
        
        ParameterData{entiall}.p=PP;
        
        ParameterData{entiall}.v=[vmin vmax];
        
        ParameterData{entiall}.xnorm=0;
        ParameterData{entiall}.ynorm=0;
        ParameterData{entiall}.znorm=1;
        
        % NURBS curve
        
        ParameterData{entiall}.nurbs.form='B-NURBS';
        
        ParameterData{entiall}.nurbs.dim=4;
        
        ParameterData{entiall}.nurbs.number=7;
        
        ParameterData{entiall}.nurbs.coefs=zeros(4,7);
        ParameterData{entiall}.nurbs.coefs(4,:)=[1 wodd 1 wodd 1 wodd 1];
        
        ParameterData{entiall}.nurbs.coefs(1:3,:)=PP;
        
        ParameterData{entiall}.nurbs.coefs(1:3,:)=repmat(ParameterData{entiall}.nurbs.coefs(4,:),3,1).*ParameterData{entiall}.nurbs.coefs(1:3,:);
        
        ParameterData{entiall}.nurbs.order=3;
        
        ParameterData{entiall}.nurbs.knots=[0 0 0 1/3 1/3 2/3 2/3 1 1 1]*(vmax-vmin)+vmin;
        
        [ParameterData{entiall}.dnurbs,ParameterData{entiall}.d2nurbs]=nrbDerivativesIGES(ParameterData{entiall}.nurbs);
        
        ParameterData{entiall}.length=0;
        
        ParameterData{entiall}.trnsfrmtnmtrx=transformationMatrixPtr;
        
        ParameterData{entiall}.clrnmbr=colorNo;
        ParameterData{entiall}.color=[0,0,0];
        
        ParameterData{entiall}.numcrv=1;
        
        ParameterData{entiall}.evalmthd=0;
        
        ParameterData{entiall}.well=true;
        
        clear PP nup p len
        
    elseif type==104
        
        A=Pvec(2);
        B=Pvec(3);
        C=Pvec(4);
        D=Pvec(5);
        E=Pvec(6);
        F=Pvec(7);
        ZT=Pvec(8);
        X1=Pvec(9);
        Y1=Pvec(10);
        X2=Pvec(11);
        Y2=Pvec(12);
        
        Q=[A 0.5*B;0.5*B C];
        
        [P,Dig] = eig(Q);
        
        if and(Dig(1,1)>1e-6,Dig(2,2)>1e-6)
            
            iDig=[1/Dig(1,1) 0;0 1/Dig(2,2)];
            
            R2=0.25*[D E]*P*iDig*P'*[D;E]-F;
            
            sqD11=sqrt(Dig(1,1));
            sqD22=sqrt(Dig(2,2));
            
            t=0.5*iDig*P'*[D;E];
            
            if det(P)>0
                pst=P'*[X1;Y1]+t;
                pen=P'*[X2;Y2]+t;
            else
                pen=P'*[X1;Y1]+t;
                pst=P'*[X2;Y2]+t;
            end
            
            pst(1)=pst(1)*sqD11;
            pst(2)=pst(2)*sqD22;
            
            pen(1)=pen(1)*sqD11;
            pen(2)=pen(2)*sqD22;
            
            if det([pst pen])<=0
                beta=2*pi-acos(dot(pst,pen)/R2);
            else
                beta=acos(dot(pst,pen)/R2);
            end
            
            if beta<1e-12
                beta=2*pi;
            end
            
            wodd=cos(beta/6);
            
            P0=pst;
            
            P1=[cos(beta/6) -sin(beta/6);sin(beta/6) cos(beta/6)]*pst/wodd;
            
            P2=[cos(beta/3) -sin(beta/3);sin(beta/3) cos(beta/3)]*pst;
            
            P3=[cos(beta/2) -sin(beta/2);sin(beta/2) cos(beta/2)]*pst/wodd;
            
            P4=[cos(2*beta/3) -sin(2*beta/3);sin(2*beta/3) cos(2*beta/3)]*pst;
            
            P5=[cos(5*beta/6) -sin(5*beta/6);sin(5*beta/6) cos(5*beta/6)]*pst/wodd;
            
            P6=pen;
            
            PP=[P0 P1 P2 P3 P4 P5 P6;ZT*ones(1,7)];
            
            PP(1,:)=PP(1,:)/sqD11-t(1);
            PP(2,:)=PP(2,:)/sqD22-t(2);
            PP(1:2,:)=P*PP(1:2,:);
            
            ParameterData{entiall}.type=126;
            
            ParameterData{entiall}.name='B-NURBS CRV';
            ParameterData{entiall}.original=0;
            ParameterData{entiall}.previous_type=104;
            ParameterData{entiall}.previous_name='CONIC ARC';
            
            ParameterData{entiall}.k=6;
            ParameterData{entiall}.m=2;
            
            ParameterData{entiall}.prop1=1;
            ParameterData{entiall}.prop2=0;
            ParameterData{entiall}.prop3=0;
            ParameterData{entiall}.prop4=0;
            
            ParameterData{entiall}.t=[0 0 0 1 1 2 2 3 3 3];
            
            ParameterData{entiall}.w=[1 wodd 1 wodd 1 wodd 1];
            
            ParameterData{entiall}.p=PP;
            
            ParameterData{entiall}.v=[0 3];
            
            ParameterData{entiall}.xnorm=0;
            ParameterData{entiall}.ynorm=0;
            ParameterData{entiall}.znorm=1;
            
            % NURBS curve
            
            ParameterData{entiall}.nurbs.form='B-NURBS';
            
            ParameterData{entiall}.nurbs.dim=4;
            
            ParameterData{entiall}.nurbs.number=7;
            
            ParameterData{entiall}.nurbs.coefs=zeros(4,7);
            ParameterData{entiall}.nurbs.coefs(4,:)=[1 wodd 1 wodd 1 wodd 1];
            
            ParameterData{entiall}.nurbs.coefs(1:3,:)=PP;
            
            ParameterData{entiall}.nurbs.coefs(1:3,:)=repmat(ParameterData{entiall}.nurbs.coefs(4,:),3,1).*ParameterData{entiall}.nurbs.coefs(1:3,:);
            
            ParameterData{entiall}.nurbs.order=3;
            
            ParameterData{entiall}.nurbs.knots=[0 0 0 1 1 2 2 3 3 3];
            
            [ParameterData{entiall}.dnurbs,ParameterData{entiall}.d2nurbs]=nrbDerivativesIGES(ParameterData{entiall}.nurbs);
            
            ParameterData{entiall}.length=0;
            
            ParameterData{entiall}.trnsfrmtnmtrx=transformationMatrixPtr;
            
            ParameterData{entiall}.clrnmbr=colorNo;
            ParameterData{entiall}.color=[0,0,0];
            
            ParameterData{entiall}.numcrv=1;
            
            ParameterData{entiall}.evalmthd=0;
            
            ParameterData{entiall}.well=true;
            
            clear PP nup p len iDig
            
        else
            
            p1=[X1;Y1;ZT];
            p2=[X2;Y2;ZT];
            
            ParameterData{entiall}.type=110;
            
            ParameterData{entiall}.name='LINE';
            ParameterData{entiall}.original=0;
            ParameterData{entiall}.previous_type=104;
            ParameterData{entiall}.previous_name='CONIC ARC';
            
            ParameterData{entiall}.p1=p1;
            ParameterData{entiall}.x1=p1(1);
            ParameterData{entiall}.y1=p1(2);
            ParameterData{entiall}.z1=p1(3);
            
            ParameterData{entiall}.p2=p2;
            ParameterData{entiall}.x2=p2(1);
            ParameterData{entiall}.y2=p2(2);
            ParameterData{entiall}.z2=p2(3);
            
            ParameterData{entiall}.length=0;
            
            ParameterData{entiall}.trnsfrmtnmtrx=transformationMatrixPtr;
            
            ParameterData{entiall}.clrnmbr=colorNo;
            ParameterData{entiall}.color=[0,0,0];
            
            ParameterData{entiall}.numcrv=1;
            
            ParameterData{entiall}.evalmthd=0;
            
            ParameterData{entiall}.well=false;
            
        end
        
        ParameterData{entiall}.a=A;
        ParameterData{entiall}.b=B;
        ParameterData{entiall}.c=C;
        ParameterData{entiall}.d=D;
        ParameterData{entiall}.e=E;
        ParameterData{entiall}.f=F;
        ParameterData{entiall}.zt=ZT;
        ParameterData{entiall}.x1=X1;
        ParameterData{entiall}.y1=Y1;
        ParameterData{entiall}.x2=X2;
        ParameterData{entiall}.y2=Y2;
        
        if showlines
            ParameterData{entiall}.superior=0;
        else
            ParameterData{entiall}.superior=1;
        end
        
        clear A B C D E F ZT X1 X2 Y1 Y2 P Dig Q
        
    elseif type==110
        
        ParameterData{entiall}.name='LINE';
        ParameterData{entiall}.original=1;
        
        if showlines
            ParameterData{entiall}.superior=0;
        else
            ParameterData{entiall}.superior=1;
        end
        
        ParameterData{entiall}.form=formNo;
        
        p1=Pvec(2:4)';
        p2=Pvec(5:7)';
        
        ParameterData{entiall}.p1=p1;
        ParameterData{entiall}.x1=p1(1);
        ParameterData{entiall}.y1=p1(2);
        ParameterData{entiall}.z1=p1(3);
        
        ParameterData{entiall}.p2=p2;
        ParameterData{entiall}.x2=p2(1);
        ParameterData{entiall}.y2=p2(2);
        ParameterData{entiall}.z2=p2(3);
        
        ParameterData{entiall}.length=0;
        
        ParameterData{entiall}.trnsfrmtnmtrx=transformationMatrixPtr;
        
        ParameterData{entiall}.clrnmbr=colorNo;
        ParameterData{entiall}.color=[0,0,0];
        
        ParameterData{entiall}.numcrv=1;
        
        ParameterData{entiall}.evalmthd=0;
        
        ParameterData{entiall}.well=true;
        
        clear p1 p2
        
    elseif type==112
        
        ParameterData{entiall}.name='PARAMETRIC SPLINE CURVE';
        ParameterData{entiall}.original=1;
        
        if showlines
            ParameterData{entiall}.superior=0;
        else
            ParameterData{entiall}.superior=1;
        end
        
        ParameterData{entiall}.ctype=Pvec(2);
        ParameterData{entiall}.h=Pvec(3);
        ParameterData{entiall}.ndim=Pvec(4);
        ParameterData{entiall}.n=Pvec(5);
        ParameterData{entiall}.t=Pvec(6:(6+ParameterData{entiall}.n));
        
        ParameterData{entiall}.a2d=zeros(3,4,ParameterData{entiall}.n);
        
        ind=7+ParameterData{entiall}.n;
        for jj=1:ParameterData{entiall}.n
            ParameterData{entiall}.a2d(1,:,jj)=Pvec(ind:(ind+3));
            ParameterData{entiall}.a2d(2,:,jj)=Pvec((ind+4):(ind+7));
            ParameterData{entiall}.a2d(3,:,jj)=Pvec((ind+8):(ind+11));
            ind=ind+12;
        end
        ParameterData{entiall}.tp=Pvec(ind:(ind+11));
        
        breakPointsPP=ParameterData{entiall}.t;
        
        
        ParameterData{entiall}.type=126;
        
        ParameterData{entiall}.name='B-NURBS CRV';
        ParameterData{entiall}.original=0;
        ParameterData{entiall}.previous_type=112;
        ParameterData{entiall}.previous_name='PARAMETRIC SPLINE CURVE';
        
        ParameterData{entiall}.k=2*ParameterData{entiall}.n+1;
        ParameterData{entiall}.m=3;
        
        ParameterData{entiall}.prop1=0;
        ParameterData{entiall}.prop2=0;
        ParameterData{entiall}.prop3=1;
        ParameterData{entiall}.prop4=0;
        
        ParameterData{entiall}.t=zeros(1,8+2*(ParameterData{entiall}.n-1));
        ParameterData{entiall}.t(1:4)=breakPointsPP(1);
        ParameterData{entiall}.t((5+2*(ParameterData{entiall}.n-1)):(8+2*(ParameterData{entiall}.n-1)))=breakPointsPP(ParameterData{entiall}.n+1);
        
        for ii=2:ParameterData{entiall}.n
            ParameterData{entiall}.t(2*ii+1)=breakPointsPP(ii);
            ParameterData{entiall}.t(2*ii+2)=breakPointsPP(ii);
        end
        
        ParameterData{entiall}.w=ones(1,2*ParameterData{entiall}.n+2);
        
        CP=zeros(3,2*ParameterData{entiall}.n+2);
        splinePoints=zeros(3,4);
        
        if ParameterData{entiall}.n==1
            
            scaling=(breakPointsPP(2)-breakPointsPP(1)).^(0:3);
            
            splinePoints(:,:)=ParameterData{entiall}.a2d(:,:,1);
            splinePoints(1,:)=splinePoints(1,:).*scaling;
            splinePoints(2,:)=splinePoints(2,:).*scaling;
            splinePoints(3,:)=splinePoints(3,:).*scaling;
            
            splinePoints(:,:)=splinePoints*spline2BezierCrvMat;
            
            CP(:,:)=splinePoints;
            
        else
            
            scaling=(breakPointsPP(2)-breakPointsPP(1)).^(0:3);
            
            splinePoints(:,:)=ParameterData{entiall}.a2d(:,:,1);
            splinePoints(1,:)=splinePoints(1,:).*scaling;
            splinePoints(2,:)=splinePoints(2,:).*scaling;
            splinePoints(3,:)=splinePoints(3,:).*scaling;
            
            splinePoints(:,:)=splinePoints*spline2BezierCrvMat;
            
            CP(:,1:3)=splinePoints(:,1:3);
            
            for ii=2:(ParameterData{entiall}.n-1)
                
                scaling=(breakPointsPP(ii+1)-breakPointsPP(ii)).^(0:3);
                
                splinePoints(:,:)=ParameterData{entiall}.a2d(:,:,ii);
                splinePoints(1,:)=splinePoints(1,:).*scaling;
                splinePoints(2,:)=splinePoints(2,:).*scaling;
                splinePoints(3,:)=splinePoints(3,:).*scaling;
                
                splinePoints(:,:)=splinePoints*spline2BezierCrvMat;
                
                CP(:,(2*ii):(2*ii+1))=splinePoints(:,2:3);
                
            end
            
            scaling=(breakPointsPP(ParameterData{entiall}.n+1)-breakPointsPP(ParameterData{entiall}.n)).^(0:3);
            
            splinePoints(:,:)=ParameterData{entiall}.a2d(:,:,ParameterData{entiall}.n);
            splinePoints(1,:)=splinePoints(1,:).*scaling;
            splinePoints(2,:)=splinePoints(2,:).*scaling;
            splinePoints(3,:)=splinePoints(3,:).*scaling;
            
            splinePoints(:,:)=splinePoints*spline2BezierCrvMat;
            
            CP(:,(2*ParameterData{entiall}.n):(2*ParameterData{entiall}.n+2))=splinePoints(:,2:4);
            
        end
        
        ParameterData{entiall}.p=CP;
        
        ParameterData{entiall}.v=[breakPointsPP(1), breakPointsPP(ParameterData{entiall}.n+1)];
        
        ParameterData{entiall}.xnorm=0;
        ParameterData{entiall}.ynorm=0;
        ParameterData{entiall}.znorm=1;
        
        
        % NURBS curve
        
        ParameterData{entiall}.nurbs.form='B-NURBS';
        
        ParameterData{entiall}.nurbs.dim=4;
        
        ParameterData{entiall}.nurbs.number=2*ParameterData{entiall}.n+2;
        
        ParameterData{entiall}.nurbs.coefs=zeros(4,2*ParameterData{entiall}.n+2);
        ParameterData{entiall}.nurbs.coefs(4,:)=1;
        
        ParameterData{entiall}.nurbs.coefs(1:3,:)=CP;
        
        ParameterData{entiall}.nurbs.order=4;
        
        ParameterData{entiall}.nurbs.knots=ParameterData{entiall}.t;
        
        [ParameterData{entiall}.dnurbs,ParameterData{entiall}.d2nurbs]=nrbDerivativesIGES(ParameterData{entiall}.nurbs);
        
        ParameterData{entiall}.length=0;
        
        ParameterData{entiall}.trnsfrmtnmtrx=transformationMatrixPtr;
        
        ParameterData{entiall}.clrnmbr=colorNo;
        ParameterData{entiall}.color=[0,0,0];
        
        ParameterData{entiall}.numcrv=1;
        
        ParameterData{entiall}.evalmthd=0;
        
        ParameterData{entiall}.well=true;
        
    elseif type==102
        
        ParameterData{entiall}.name='COMPOSITE CRV';
        
        ParameterData{entiall}.n=Pvec(2);
        ParameterData{entiall}.de=round((Pvec(3:(2+Pvec(2)))+1)/2);
        
        ParameterData{entiall}.lengthcnt=zeros(1,Pvec(2));
        ParameterData{entiall}.length=0;
        
        ParameterData{entiall}.clrnmbr=colorNo;
        ParameterData{entiall}.color=[0,0,0];
        
        ParameterData{entiall}.numcrvcnt=zeros(1,Pvec(2));
        ParameterData{entiall}.numcrv=0;
        
        ParameterData{entiall}.well=true;
        
    elseif type==141
        
        ParameterData{entiall}.name='BOUNDARY';
        
        ParameterData{entiall}.boundarytype=Pvec(2);
        
        ParameterData{entiall}.pref=Pvec(3);
        
        ParameterData{entiall}.sptr=round((Pvec(4)+1)/2);
        
        ParameterData{entiall}.n=Pvec(5);
        
        ParameterData{entiall}.crvpt=zeros(1,ParameterData{entiall}.n);
        ParameterData{entiall}.sense=zeros(1,ParameterData{entiall}.n);
        ParameterData{entiall}.k=zeros(1,ParameterData{entiall}.n);
        ParameterData{entiall}.pscpt=cell(1,ParameterData{entiall}.n);
        
        ParameterData{entiall}.msclength=zeros(1,ParameterData{entiall}.n);
        ParameterData{entiall}.pscclctnlength=cell(1,ParameterData{entiall}.n);
        ParameterData{entiall}.psclength=zeros(1,ParameterData{entiall}.n);
        
        ParameterData{entiall}.numcrv=0;
        ParameterData{entiall}.numpscrv=zeros(1,ParameterData{entiall}.n);
        ParameterData{entiall}.numpscrvc=cell(1,ParameterData{entiall}.n);
        
        stind=5;
        
        for ii=1:ParameterData{entiall}.n
            
            ParameterData{entiall}.crvpt(ii)=round((Pvec(stind+1)+1)/2);
            ParameterData{entiall}.sense(ii)=Pvec(stind+2);
            ParameterData{entiall}.k(ii)=Pvec(stind+3);
            
            ParameterData{entiall}.pscpt{ii}=round((Pvec((stind+4):(stind+3+ParameterData{entiall}.k(ii)))+1)/2);
            ParameterData{entiall}.pscclctnlength{ii}=zeros(1,ParameterData{entiall}.k(ii));
            ParameterData{entiall}.numpscrvc{ii}=zeros(1,ParameterData{entiall}.k(ii));
            
            stind=stind+3+ParameterData{entiall}.k(ii);
            
        end
        
        ParameterData{entiall}.length=0;
        
        ParameterData{entiall}.mlcrv=0;
        
        ParameterData{entiall}.clrnmbr=colorNo;
        ParameterData{entiall}.color=[0,0,0];
        
        ParameterData{entiall}.well=true;
        
    elseif type==142
        
        ParameterData{entiall}.name='CRV ON A PARAMETRIC SURFACE';
        
        ParameterData{entiall}.crtn=Pvec(2);
        ParameterData{entiall}.sptr=round((Pvec(3)+1)/2);
        ParameterData{entiall}.bptr=round((Pvec(4)+1)/2);
        ParameterData{entiall}.cptr=round((Pvec(5)+1)/2);
        ParameterData{entiall}.pref=Pvec(6);
        ParameterData{entiall}.length=0;
        
        ParameterData{entiall}.mlcrv=0;
        
        ParameterData{entiall}.clrnmbr=colorNo;
        ParameterData{entiall}.color=[0,0,0];
        
        ParameterData{entiall}.numcrv=0;
        
        ParameterData{entiall}.well=true;
        
        % POINT
        
    elseif type==116
        
        ParameterData{entiall}.name='POINT';
        
        ParameterData{entiall}.p=Pvec(2:4)';
        
        ParameterData{entiall}.x=ParameterData{entiall}.p(1);
        ParameterData{entiall}.y=ParameterData{entiall}.p(2);
        ParameterData{entiall}.z=ParameterData{entiall}.p(3);
        
        try
            ParameterData{entiall}.ptr=round((Pvec(5)+1)/2);
        catch
            ParameterData{entiall}.ptr=0;
        end
        
        ParameterData{entiall}.original=1;
        
        ParameterData{entiall}.trnsfrmtnmtrx=transformationMatrixPtr;
        
        ParameterData{entiall}.clrnmbr=colorNo;
        ParameterData{entiall}.color=[0,0,0];
        
        ParameterData{entiall}.well=true;
        
        % OTHER
        
    elseif type==123
        
        ParameterData{entiall}.name='DIRECTION';
        
        ParameterData{entiall}.x=Pvec(2);
        ParameterData{entiall}.y=Pvec(3);
        ParameterData{entiall}.z=Pvec(4);
        
    elseif type==124
        
        transformationExists=true;
        
        ParameterData{entiall}.name='TRANSFORMATION MATRIX';
        
        ParameterData{entiall}.r=zeros(3);
        ParameterData{entiall}.t=zeros(3,1);
        
        ParameterData{entiall}.r(1,1)=Pvec(2);
        ParameterData{entiall}.r(1,2)=Pvec(3);
        ParameterData{entiall}.r(1,3)=Pvec(4);
        
        ParameterData{entiall}.t(1)=Pvec(5);
        
        ParameterData{entiall}.r(2,1)=Pvec(6);
        ParameterData{entiall}.r(2,2)=Pvec(7);
        ParameterData{entiall}.r(2,3)=Pvec(8);
        
        ParameterData{entiall}.t(2)=Pvec(9);
        
        ParameterData{entiall}.r(3,1)=Pvec(10);
        ParameterData{entiall}.r(3,2)=Pvec(11);
        ParameterData{entiall}.r(3,3)=Pvec(12);
        
        ParameterData{entiall}.t(3)=Pvec(13);
        
        ParameterData{entiall}.original=1;
        
        ParameterData{entiall}.trnsfrmtnmtrx=transformationMatrixPtr;
        
        myEye=ParameterData{entiall}.r*eye(3);
        myEye(1,:)=myEye(1,:)+ParameterData{entiall}.t(1);
        myEye(2,:)=myEye(2,:)+ParameterData{entiall}.t(2);
        myEye(3,:)=myEye(3,:)+ParameterData{entiall}.t(3);
        myEye=myEye-eye(3);
        
        if norm(myEye,'fro')<1e-8
            ParameterData{entiall}.isidentity=true;
        else
            ParameterData{entiall}.isidentity=false;
        end
        
        ParameterData{entiall}.well=true;
        
    elseif type==314
        
        ParameterData{entiall}.name='COLOR';
        
        inn=find(or(Pstr==44,Pstr==59));
        
        ParameterData{entiall}.cc1=str2num(char(Pstr((inn(1)+1):(inn(2)-1))));
        ParameterData{entiall}.cc2=str2num(char(Pstr((inn(2)+1):(inn(3)-1))));
        ParameterData{entiall}.cc3=str2num(char(Pstr((inn(3)+1):(inn(4)-1))));
        
        ParameterData{entiall}.color=[ParameterData{entiall}.cc1 ParameterData{entiall}.cc2 ParameterData{entiall}.cc3]/100;
        
        defaultColor=ParameterData{entiall}.color;
        
        if length(inn)>4
            inn2=find(Pstr(1:(inn(5)-1))==72);
            if isempty(inn2)
                ParameterData{entiall}.cname='';
            else
                ParameterData{entiall}.cname=char(Pstr((inn2(1)+1):(inn(5)-1)));
            end
        else
            ParameterData{entiall}.cname='';
        end
        
        ParameterData{entiall}.original=1;
        
        ParameterData{entiall}.well=true;
        
    elseif type==308
        
        subfiguresExists=true;
        
        ParameterData{entiall}.name='SUBFIGURE DEFINITION';
        
        for ii=1:length(Pstr)
            if Pstr(ii)==72
                hind=ii;
                break
            end
        end
        for ii=(hind-2):-1:1
            if Pstr(ii)==44
                cind=ii;
                break
            end
        end
        numStr=str2num(char(Pstr((cind+1):(hind-1))));
        Pvec=str2num(char(Pstr((hind+numStr+2):end)));
        strname=char(Pstr((hind+1):(hind+numStr)));
        for ii=(cind-2):-1:1
            if Pstr(ii)==44
                hind=ii;
                break
            end
        end
        
        ParameterData{entiall}.depth=str2num(char(Pstr((hind+1):(cind-1))));
        ParameterData{entiall}.subfigurename=strname;
        ParameterData{entiall}.n=Pvec(1);
        ParameterData{entiall}.de=round((Pvec(2:(Pvec(1)+1))+1)/2);
        
        ParameterData{entiall}.numinstances=0;
        ParameterData{entiall}.iptrs=zeros(1,0);
        
        ParameterData{entiall}.original=1;
        
        ParameterData{entiall}.well=true;
        
    elseif type==402
        
        ParameterData{entiall}.name='TYPE 402';
        ParameterData{entiall}.unknown=char(Pstr);
        
        ParameterData{entiall}.original=1;
        
        ParameterData{entiall}.well=false;
        
    elseif type==404
        
        ParameterData{entiall}.name='TYPE 404';
        ParameterData{entiall}.unknown=char(Pstr);
        
        ParameterData{entiall}.original=1;
        
        ParameterData{entiall}.well=false;
        
    elseif type==406
        
        ParameterData{entiall}.name='TYPE 406';
        ParameterData{entiall}.unknown=char(Pstr);
        
        ParameterData{entiall}.original=1;
        
        ParameterData{entiall}.well=false;
        
    elseif type==408
        
        subfiguresExists=true;
        
        ParameterData{entiall}.name='SINGULAR SUBFIGURE INSTANCE';
        
        ParameterData{entiall}.de=round((Pvec(2)+1)/2);
        
        ParameterData{entiall}.t=Pvec(3:5)';
        
        ParameterData{entiall}.x=ParameterData{entiall}.t(1);
        ParameterData{entiall}.y=ParameterData{entiall}.t(2);
        ParameterData{entiall}.z=ParameterData{entiall}.t(3);
        
        ParameterData{entiall}.s=Pvec(6);
        
        ParameterData{entiall}.trnsfrmtnmtrx=transformationMatrixPtr;
        
        ParameterData{entiall}.original=1;
        
        ParameterData{entiall}.well=true;
        
    elseif type==410
        
        ParameterData{entiall}.name='TYPE 410';
        ParameterData{entiall}.unknown=char(Pstr);
        
        ParameterData{entiall}.original=1;
        
        ParameterData{entiall}.well=false;
        
    else
        
        ParameterData{entiall}.name='UNKNOWN';
        entunk(type)=entunk(type)+1;
        entty(type)=entty(type)-1;
        
        ParameterData{entiall}.original=1;
        
        ParameterData{entiall}.length=0;
        
        ParameterData{entiall}.well=false;
        
    end
    
end


% Transform curves and points if necessary

if transformationExists
    
    % Use transformation entities on curves and points
    for i=1:noent
        
        if ParameterData{i}.type==126
            if ParameterData{i}.well
                if ParameterData{i}.trnsfrmtnmtrx>0
                    if not(ParameterData{ParameterData{i}.trnsfrmtnmtrx}.isidentity)
                        
                        R=ParameterData{ParameterData{i}.trnsfrmtnmtrx}.r;
                        T=ParameterData{ParameterData{i}.trnsfrmtnmtrx}.t;
                        
                        for j=1:(ParameterData{i}.k+1)
                            ParameterData{i}.p(:,j)=R*(ParameterData{i}.p(:,j))+T;
                        end
                        
                        ParameterData{i}.nurbs.coefs(1:3,:)=repmat(ParameterData{i}.nurbs.coefs(4,:),3,1).*ParameterData{i}.p;
                        [ParameterData{i}.dnurbs,ParameterData{i}.d2nurbs]=nrbDerivativesIGES(ParameterData{i}.nurbs);
                        
                    end
                end
            end
        elseif ParameterData{i}.type==110
            if ParameterData{i}.well
                if ParameterData{i}.trnsfrmtnmtrx>0
                    if not(ParameterData{ParameterData{i}.trnsfrmtnmtrx}.isidentity)
                        
                        R=ParameterData{ParameterData{i}.trnsfrmtnmtrx}.r;
                        T=ParameterData{ParameterData{i}.trnsfrmtnmtrx}.t;
                        
                        ParameterData{i}.p1=R*ParameterData{i}.p1+T;
                        ParameterData{i}.x1=ParameterData{i}.p1(1);
                        ParameterData{i}.y1=ParameterData{i}.p1(2);
                        ParameterData{i}.z1=ParameterData{i}.p1(3);
                        
                        ParameterData{i}.p2=R*ParameterData{i}.p2+T;
                        ParameterData{i}.x2=ParameterData{i}.p2(1);
                        ParameterData{i}.y2=ParameterData{i}.p2(2);
                        ParameterData{i}.z2=ParameterData{i}.p2(3);
                        
                    end
                end
            end
        elseif ParameterData{i}.type==116
            if ParameterData{i}.well
                if ParameterData{i}.trnsfrmtnmtrx>0
                    if not(ParameterData{ParameterData{i}.trnsfrmtnmtrx}.isidentity)
                        
                        R=ParameterData{ParameterData{i}.trnsfrmtnmtrx}.r;
                        T=ParameterData{ParameterData{i}.trnsfrmtnmtrx}.t;
                        
                        ParameterData{i}.p=R*ParameterData{i}.p+T;
                        ParameterData{i}.x=ParameterData{i}.p(1);
                        ParameterData{i}.y=ParameterData{i}.p(2);
                        ParameterData{i}.z=ParameterData{i}.p(3);
                        
                    end
                end
            end
        end
        
    end
    
end


% Create NUSBS surfaces from other representations

numPnt=301;
PouterCrv=zeros(3,numPnt);
pntCrvPrms=zeros(1,numPnt);

numSplineVal=25;
splinePnts=zeros(3,numSplineVal);

nrbDeg=2;
numCtrlPnts=40;

knots=zeros(1,nrbDeg+numCtrlPnts+1);
knots((numCtrlPnts+1):end)=1;

CP1=zeros(3,numCtrlPnts);
CP2=zeros(3,numCtrlPnts);

for i=1:noent
    
    if ParameterData{i}.type==118
        
        % First curve
        ind=ParameterData{i}.de1;
        hasLength=true;
        
        if ParameterData{ind}.type==110
            pntCrvPrms(:)=linspace(0,1,numPnt);
            PouterCrv(1,:)=linspace(ParameterData{ind}.x1,ParameterData{ind}.x2,numPnt);
            PouterCrv(2,:)=linspace(ParameterData{ind}.y1,ParameterData{ind}.y2,numPnt);
            PouterCrv(3,:)=linspace(ParameterData{ind}.z1,ParameterData{ind}.z2,numPnt);
        elseif ParameterData{ind}.type==126
            pntCrvPrms(:)=linspace(ParameterData{ind}.v(1),ParameterData{ind}.v(2),numPnt);
            PouterCrv=nrbevalIGES(ParameterData{ind}.nurbs,pntCrvPrms);
            pntCrvPrms=pntCrvPrms-pntCrvPrms(1);
            pntCrvPrms=pntCrvPrms/pntCrvPrms(end);
        elseif ParameterData{ind}.type==116
            pntCrvPrms(:)=linspace(0,1,numPnt);
            PouterCrv(1,:)=ParameterData{ind}.x;
            PouterCrv(2,:)=ParameterData{ind}.y;
            PouterCrv(3,:)=ParameterData{ind}.z;
            hasLength=false;
        else
            pntCrvPrms(:)=linspace(0,1,numPnt);
            PouterCrv(:)=0;
            hasLength=false;
            ParameterData{i}.well=false;
        end
        
        if and(ParameterData{i}.form==0,hasLength)
            pp = spline(1:numPnt,PouterCrv);
            for j=2:numPnt
                splinePnts(:,:)=ppval(pp,linspace(j-1,j,numSplineVal));
                pntCrvPrms(j)=sum(sqrt((splinePnts(1,2:numSplineVal)-splinePnts(1,1:(numSplineVal-1))).^2+(splinePnts(2,2:numSplineVal)-splinePnts(2,1:(numSplineVal-1))).^2));
            end
            pntCrvPrms=cumsum(pntCrvPrms);
            pntCrvPrms=pntCrvPrms/pntCrvPrms(numPnt);
        end
        
        ppParams = pchip(linspace(0,1,numPnt),pntCrvPrms);
        knots((nrbDeg+2):numCtrlPnts)=ppval(ppParams,(1:(numCtrlPnts-nrbDeg-1))/(numCtrlPnts-nrbDeg));
        
        [NTN,R]=LScrvApp(PouterCrv,nrbDeg,numCtrlPnts,pntCrvPrms,knots);
        
        CP1(:,1)=PouterCrv(:,1);
        CP1(:,numCtrlPnts)=PouterCrv(:,numPnt);
        CP1(:,2:(numCtrlPnts-1))=(NTN\R)';
        
        % Second curve
        ind=ParameterData{i}.de2;
        hasLength=true;
        
        if ParameterData{i}.dirflg==1
            if ParameterData{ind}.type==110
                pntCrvPrms(:)=linspace(0,1,numPnt);
                PouterCrv(1,:)=linspace(ParameterData{ind}.x2,ParameterData{ind}.x1,numPnt);
                PouterCrv(2,:)=linspace(ParameterData{ind}.y2,ParameterData{ind}.y1,numPnt);
                PouterCrv(3,:)=linspace(ParameterData{ind}.z2,ParameterData{ind}.z1,numPnt);
            elseif ParameterData{ind}.type==126
                pntCrvPrms(:)=linspace(ParameterData{ind}.v(2),ParameterData{ind}.v(1),numPnt);
                PouterCrv=nrbevalIGES(ParameterData{ind}.nurbs,pntCrvPrms);
                pntCrvPrms(:)=linspace(ParameterData{ind}.v(1),ParameterData{ind}.v(2),numPnt);
                pntCrvPrms=pntCrvPrms-pntCrvPrms(1);
                pntCrvPrms=pntCrvPrms/pntCrvPrms(end);
            elseif ParameterData{ind}.type==116
                pntCrvPrms(:)=linspace(0,1,numPnt);
                PouterCrv(1,:)=ParameterData{ind}.x;
                PouterCrv(2,:)=ParameterData{ind}.y;
                PouterCrv(3,:)=ParameterData{ind}.z;
                hasLength=false;
            else
                pntCrvPrms(:)=linspace(0,1,numPnt);
                PouterCrv(:)=0;
                hasLength=false;
                ParameterData{i}.well=false;
            end
        else
            if ParameterData{ind}.type==110
                pntCrvPrms(:)=linspace(0,1,numPnt);
                PouterCrv(1,:)=linspace(ParameterData{ind}.x1,ParameterData{ind}.x2,numPnt);
                PouterCrv(2,:)=linspace(ParameterData{ind}.y1,ParameterData{ind}.y2,numPnt);
                PouterCrv(3,:)=linspace(ParameterData{ind}.z1,ParameterData{ind}.z2,numPnt);
            elseif ParameterData{ind}.type==126
                pntCrvPrms(:)=linspace(ParameterData{ind}.v(1),ParameterData{ind}.v(2),numPnt);
                PouterCrv=nrbevalIGES(ParameterData{ind}.nurbs,pntCrvPrms);
                pntCrvPrms=pntCrvPrms-pntCrvPrms(1);
                pntCrvPrms=pntCrvPrms/pntCrvPrms(end);
            elseif ParameterData{ind}.type==116
                pntCrvPrms(:)=linspace(0,1,numPnt);
                PouterCrv(1,:)=ParameterData{ind}.x;
                PouterCrv(2,:)=ParameterData{ind}.y;
                PouterCrv(3,:)=ParameterData{ind}.z;
                hasLength=false;
            else
                pntCrvPrms(:)=linspace(0,1,numPnt);
                PouterCrv(:)=0;
                hasLength=false;
                ParameterData{i}.well=false;
            end
        end
        
        if and(ParameterData{i}.form==0,hasLength)
            pp = spline(1:numPnt,PouterCrv);
            for j=2:numPnt
                splinePnts(:,:)=ppval(pp,linspace(j-1,j,numSplineVal));
                pntCrvPrms(j)=sum(sqrt((splinePnts(1,2:numSplineVal)-splinePnts(1,1:(numSplineVal-1))).^2+(splinePnts(2,2:numSplineVal)-splinePnts(2,1:(numSplineVal-1))).^2));
            end
            pntCrvPrms=cumsum(pntCrvPrms);
            pntCrvPrms=pntCrvPrms/pntCrvPrms(numPnt);
        end
        
        [NTN,R]=LScrvApp(PouterCrv,nrbDeg,numCtrlPnts,pntCrvPrms,knots);
        
        CP2(:,1)=PouterCrv(:,1);
        CP2(:,numCtrlPnts)=PouterCrv(:,numPnt);
        CP2(:,2:(numCtrlPnts-1))=(NTN\R)';
        
        
        ParameterData{i}.type=128;
        
        ParameterData{i}.name='B-NURBS SRF';
        ParameterData{i}.original=0;
        ParameterData{i}.previous_type=118;
        ParameterData{i}.previous_name='RULED SURFACE';
        
        ParameterData{i}.superior=0;
        
        ParameterData{i}.k1=numCtrlPnts-1;
        ParameterData{i}.k2=1;
        
        ParameterData{i}.m1=nrbDeg;
        ParameterData{i}.m2=1;
        
        ParameterData{i}.prop1=0;
        ParameterData{i}.prop2=0;
        ParameterData{i}.prop3=0;
        ParameterData{i}.prop4=0;
        ParameterData{i}.prop5=0;
        
        ParameterData{i}.s=knots;
        ParameterData{i}.t=[0 0 1 1];
        
        ParameterData{i}.w=ones(numCtrlPnts,2);
        ParameterData{i}.p=zeros(3,numCtrlPnts,2);
        ParameterData{i}.p(:,:,1)=CP1;
        ParameterData{i}.p(:,:,2)=CP2;
        
        ParameterData{i}.u=[0,1];
        ParameterData{i}.v=[0,1];
        
        ParameterData{i}.isplane=false;
        
        
        % NURBS surface
        
        ParameterData{i}.nurbs.form='B-NURBS';
        ParameterData{i}.nurbs.dim=4;
        ParameterData{i}.nurbs.number=[numCtrlPnts 2];
        ParameterData{i}.nurbs.coefs=zeros(4,numCtrlPnts,2);
        
        ParameterData{i}.nurbs.coefs(1:3,:,1)=CP1;
        ParameterData{i}.nurbs.coefs(1:3,:,2)=CP2;
        ParameterData{i}.nurbs.coefs(4,:,:)=1;
        
        ParameterData{i}.nurbs.knots=cell(1,2);
        ParameterData{i}.nurbs.knots{1}=knots;
        ParameterData{i}.nurbs.knots{2}=[0 0 1 1];
        
        ParameterData{i}.nurbs.order=[nrbDeg+1 2];
        
        [ParameterData{i}.dnurbs,ParameterData{i}.d2nurbs]=nrbDerivativesIGES(ParameterData{i}.nurbs);
        
    elseif ParameterData{i}.type==120
        
        CRVclosed=false;
        
        if ParameterData{ParameterData{i}.c}.type==110
            
            CRVk=1;
            CRVm=1;
            CRVt=[0 0 1 1];
            CRVw=[1 1];
            CRVp=[ParameterData{ParameterData{i}.c}.p1 ParameterData{ParameterData{i}.c}.p2];
            CRVv=[0 1];
            
            cl=norm(CRVp(:,1)-CRVp(:,2))*1e-8;
            ulinear=1;
            
            boool=true;
            
        elseif ParameterData{ParameterData{i}.c}.type==126
            
            CRVk=ParameterData{ParameterData{i}.c}.k;
            CRVm=ParameterData{ParameterData{i}.c}.m;
            CRVt=ParameterData{ParameterData{i}.c}.t;
            CRVw=ParameterData{ParameterData{i}.c}.w;
            CRVp=ParameterData{ParameterData{i}.c}.p;
            CRVv=ParameterData{ParameterData{i}.c}.v;
            
            cl=norm(CRVp(:,1)-CRVp(:,2))*1e-8;
            
            if norm(CRVp(:,1)-CRVp(:,end))<cl
                CRVclosed=true;
            end
            
            meaP=mean(CRVp,2);
            Si=svd(CRVp*CRVp'-((CRVk+1)*meaP)*meaP');
            if Si(2)*1e6>Si(1)
                ulinear=0;
            else
                ulinear=1;
            end
            
            boool=true;
            
        else
            
            disp(['Warning: Could not handle entity type 120 correctly in ',igsfile,'.']);
            ulinear=0;
            boool=false;
            
        end
        
        if boool
            
            p1=ParameterData{ParameterData{i}.l}.p1;
            rotDir=ParameterData{ParameterData{i}.l}.p2-p1;
            rotDir=rotDir/norm(rotDir);
            
            CRVp(1,:)=CRVp(1,:)-p1(1);
            CRVp(2,:)=CRVp(2,:)-p1(2);
            CRVp(3,:)=CRVp(3,:)-p1(3);
            
            Psonaxis=norm(cross(rotDir,CRVp(:,1)))<cl;
            Ptonaxis=norm(cross(rotDir,CRVp(:,end)))<cl;
            
            ind=1;
            maval=-1;
            
            for j=1:size(CRVp,2)
                tmp=norm(cross(rotDir,CRVp(:,j)));
                if tmp>maval
                    maval=tmp;
                    ind=j;
                end
            end
            
            cDir=CRVp(:,ind);
            cDir=cDir-dot(cDir,rotDir)*rotDir;
            cDir=cDir/norm(cDir);
            
            iRot=[cDir cross(rotDir,cDir) rotDir];
            
            CRVp=iRot'*CRVp;
            
            R=iRot';
            T=-iRot'*p1;
            
            vmin=ParameterData{i}.sa;
            vmax=ParameterData{i}.ta;
            
            ParameterData{i}.type=128;
            
            ParameterData{i}.name='B-NURBS SRF';
            ParameterData{i}.original=0;
            ParameterData{i}.previous_type=120;
            ParameterData{i}.previous_name='SURFACE OF REVOLUTION';
            
            ParameterData{i}.superior=0;
            
            ParameterData{i}.k1=CRVk;
            ParameterData{i}.k2=6;
            
            ParameterData{i}.m1=CRVm;
            ParameterData{i}.m2=2;
            
            ParameterData{i}.prop1=0;
            ParameterData{i}.prop2=0;
            ParameterData{i}.prop3=0;
            ParameterData{i}.prop4=0;
            ParameterData{i}.prop5=0;
            
            ParameterData{i}.s=CRVt;
            ParameterData{i}.t=[0 0 0 1/3 1/3 2/3 2/3 1 1 1]*(vmax-vmin)+vmin;
            
            ParameterData{i}.ulinear=ulinear;
            
            wodd=cos((vmax-vmin)/6);
            
            ParameterData{i}.w=[CRVw;wodd*(CRVw);CRVw;wodd*(CRVw);CRVw;wodd*(CRVw);CRVw]';
            ParameterData{i}.p=zeros(3,CRVk+1,7);
            
            betavec=linspace(vmin,vmax,7);
            
            eve=true;
            
            for ii=1:7
                
                if eve
                    cob=cos(betavec(ii));
                    sib=sin(betavec(ii));
                    eve=false;
                else
                    cob=cos(betavec(ii))/wodd;
                    sib=sin(betavec(ii))/wodd;
                    eve=true;
                end
                
                ParameterData{i}.p(1,:,ii)=cob*CRVp(1,:)-sib*CRVp(2,:)-T(1);
                ParameterData{i}.p(2,:,ii)=sib*CRVp(1,:)+cob*CRVp(2,:)-T(2);
                ParameterData{i}.p(3,:,ii)=CRVp(3,:)-T(3);
                ParameterData{i}.p(:,:,ii)=R'*ParameterData{i}.p(:,:,ii);
                
            end
            
            ParameterData{i}.u=CRVv;
            ParameterData{i}.v=[vmin vmax];
            
            ParameterData{i}.isplane=false;
            
            
            % NURBS surface
            
            ParameterData{i}.nurbs.form='B-NURBS';
            ParameterData{i}.nurbs.dim=4;
            ParameterData{i}.nurbs.number=[ParameterData{i}.k1+1 ParameterData{i}.k2+1];
            ParameterData{i}.nurbs.coefs=zeros(4,CRVk+1,7);
            
            for ii=1:7
                ParameterData{i}.nurbs.coefs(4,:,ii)=ParameterData{i}.w(:,ii)';
                
                ParameterData{i}.nurbs.coefs(1,:,ii)=ParameterData{i}.nurbs.coefs(4,:,ii).*ParameterData{i}.p(1,:,ii);
                ParameterData{i}.nurbs.coefs(2,:,ii)=ParameterData{i}.nurbs.coefs(4,:,ii).*ParameterData{i}.p(2,:,ii);
                ParameterData{i}.nurbs.coefs(3,:,ii)=ParameterData{i}.nurbs.coefs(4,:,ii).*ParameterData{i}.p(3,:,ii);
            end
            
            ParameterData{i}.nurbs.knots=cell(1,2);
            ParameterData{i}.nurbs.knots{1}=CRVt;
            ParameterData{i}.nurbs.knots{2}=ParameterData{i}.t;
            
            ParameterData{i}.nurbs.order=[ParameterData{i}.m1+1 ParameterData{i}.m2+1];
            
            [ParameterData{i}.dnurbs,ParameterData{i}.d2nurbs]=nrbDerivativesIGES(ParameterData{i}.nurbs);
            
            
            % Revolution data
            
            ParameterData{i}.revolution.cclosed=CRVclosed;
            ParameterData{i}.revolution.psonaxis=Psonaxis;
            ParameterData{i}.revolution.ptonaxis=Ptonaxis;
            
            % NURBS curve
            
            ParameterData{i}.revolution.rnurbs.form='B-NURBS';
            ParameterData{i}.revolution.rnurbs.dim=4;
            ParameterData{i}.revolution.rnurbs.number=7;
            ParameterData{i}.revolution.rnurbs.coefs=[cos(betavec);sin(betavec);zeros(1,7);[1,wodd,1,wodd,1,wodd,1]];
            ParameterData{i}.revolution.rnurbs.order=3;
            ParameterData{i}.revolution.rnurbs.knots=ParameterData{i}.t;
            
            [ParameterData{i}.revolution.drnurbs,ParameterData{i}.revolution.d2rnurbs]=nrbDerivativesIGES(ParameterData{i}.revolution.rnurbs);
            
            if ParameterData{i}.trnsfrmtnmtrx>0
                
                if not(ParameterData{ParameterData{i}.trnsfrmtnmtrx}.isidentity)
                    
                    Rt=ParameterData{ParameterData{i}.trnsfrmtnmtrx}.r;
                    Tt=ParameterData{ParameterData{i}.trnsfrmtnmtrx}.t;
                    
                    ParameterData{i}.revolution.p=Rt*p1+Tt;
                    ParameterData{i}.revolution.v=Rt*rotDir;
                    ParameterData{i}.revolution.R=R*Rt';
                    ParameterData{i}.revolution.T=T-R*Rt'*Tt;
                    
                    % NURBS curve
                    
                    if ParameterData{ParameterData{i}.c}.type==110
                        
                        ParameterData{i}.revolution.cnurbs.form='B-NURBS';
                        ParameterData{i}.revolution.cnurbs.dim=4;
                        ParameterData{i}.revolution.cnurbs.number=2;
                        ParameterData{i}.revolution.cnurbs.coefs=ones(4,2);
                        ParameterData{i}.revolution.cnurbs.coefs(1:3,1)=Rt*ParameterData{ParameterData{i}.c}.p1+Tt;
                        ParameterData{i}.revolution.cnurbs.coefs(1:3,2)=Rt*ParameterData{ParameterData{i}.c}.p2+Tt;
                        ParameterData{i}.revolution.cnurbs.order=2;
                        ParameterData{i}.revolution.cnurbs.knots=CRVt;
                        
                    elseif ParameterData{ParameterData{i}.c}.type==126
                        
                        ParameterData{i}.revolution.cnurbs=ParameterData{ParameterData{i}.c}.nurbs;
                        ParameterData{i}.revolution.cnurbs.coefs(1,:)=(Rt(1,:)*ParameterData{ParameterData{i}.c}.p+Tt(1)).*ParameterData{ParameterData{i}.c}.w;
                        ParameterData{i}.revolution.cnurbs.coefs(2,:)=(Rt(2,:)*ParameterData{ParameterData{i}.c}.p+Tt(2)).*ParameterData{ParameterData{i}.c}.w;
                        ParameterData{i}.revolution.cnurbs.coefs(3,:)=(Rt(3,:)*ParameterData{ParameterData{i}.c}.p+Tt(3)).*ParameterData{ParameterData{i}.c}.w;
                        
                    end
                    
                else
                    
                    ParameterData{i}.revolution.p=p1;
                    ParameterData{i}.revolution.v=rotDir;
                    ParameterData{i}.revolution.R=R;
                    ParameterData{i}.revolution.T=T;
                    
                    % NURBS curve
                    
                    if ParameterData{ParameterData{i}.c}.type==110
                        
                        ParameterData{i}.revolution.cnurbs.form='B-NURBS';
                        ParameterData{i}.revolution.cnurbs.dim=4;
                        ParameterData{i}.revolution.cnurbs.number=2;
                        ParameterData{i}.revolution.cnurbs.coefs=ones(4,2);
                        ParameterData{i}.revolution.cnurbs.coefs(1:3,1)=ParameterData{ParameterData{i}.c}.p1;
                        ParameterData{i}.revolution.cnurbs.coefs(1:3,2)=ParameterData{ParameterData{i}.c}.p2;
                        ParameterData{i}.revolution.cnurbs.order=2;
                        ParameterData{i}.revolution.cnurbs.knots=CRVt;
                        
                    elseif ParameterData{ParameterData{i}.c}.type==126
                        
                        ParameterData{i}.revolution.cnurbs=ParameterData{ParameterData{i}.c}.nurbs;
                        
                    end
                    
                end
                
            else
                
                ParameterData{i}.revolution.p=p1;
                ParameterData{i}.revolution.v=rotDir;
                ParameterData{i}.revolution.R=R;
                ParameterData{i}.revolution.T=T;
                
                % NURBS curve
                
                if ParameterData{ParameterData{i}.c}.type==110
                    
                    ParameterData{i}.revolution.cnurbs.form='B-NURBS';
                    ParameterData{i}.revolution.cnurbs.dim=4;
                    ParameterData{i}.revolution.cnurbs.number=2;
                    ParameterData{i}.revolution.cnurbs.coefs=ones(4,2);
                    ParameterData{i}.revolution.cnurbs.coefs(1:3,1)=ParameterData{ParameterData{i}.c}.p1;
                    ParameterData{i}.revolution.cnurbs.coefs(1:3,2)=ParameterData{ParameterData{i}.c}.p2;
                    ParameterData{i}.revolution.cnurbs.order=2;
                    ParameterData{i}.revolution.cnurbs.knots=CRVt;
                    
                elseif ParameterData{ParameterData{i}.c}.type==126
                    
                    ParameterData{i}.revolution.cnurbs=ParameterData{ParameterData{i}.c}.nurbs;
                    
                end
                
            end
            
            [ParameterData{i}.revolution.dcnurbs,ParameterData{i}.revolution.d2cnurbs]=nrbDerivativesIGES(ParameterData{i}.revolution.cnurbs);
            
        else
            
            entunk(ParameterData{i}.type)=entunk(ParameterData{i}.type)+1;
            entty(ParameterData{i}.type)=entty(ParameterData{i}.type)-1;
            
            ParameterData{i}.well=false;
            
        end
        
    elseif ParameterData{i}.type==122
        
        if ParameterData{ParameterData{i}.de}.type==110
            
            CRVk=1;
            CRVm=1;
            CRVt=[0 0 1 1];
            CRVw=[1 1];
            CRVp=[ParameterData{ParameterData{i}.de}.p1 ParameterData{ParameterData{i}.de}.p2];
            
            isplane=true;
            boool=true;
            
        elseif ParameterData{ParameterData{i}.de}.type==126
            
            CRVk=ParameterData{ParameterData{i}.de}.k;
            CRVm=ParameterData{ParameterData{i}.de}.m;
            CRVt=ParameterData{ParameterData{i}.de}.t;
            CRVt=CRVt-CRVt(1);
            CRVt=CRVt/CRVt(end);
            CRVw=ParameterData{ParameterData{i}.de}.w;
            CRVp=ParameterData{ParameterData{i}.de}.p;
            
            meaP=mean(CRVp,2);
            Si=svd(CRVp*CRVp'-((CRVk+1)*meaP)*meaP');
            if Si(2)*1e6<Si(1)
                isplane=true;
            else
                isplane=false;
            end
            
            boool=true;
            
        else
            
            disp(['Warning: Could not handle entity type 122 correctly in ',igsfile,'.']);
            boool=false;
            
        end
        
        if boool
            
            ParameterData{i}.type=128;
            
            ParameterData{i}.name='B-NURBS SRF';
            ParameterData{i}.original=0;
            ParameterData{i}.previous_type=122;
            ParameterData{i}.previous_name='TABULATED CYLINDER';
            
            ParameterData{i}.superior=0;
            
            ParameterData{i}.k1=CRVk;
            ParameterData{i}.k2=1;
            
            ParameterData{i}.m1=CRVm;
            ParameterData{i}.m2=1;
            
            ParameterData{i}.prop1=0;
            ParameterData{i}.prop2=0;
            ParameterData{i}.prop3=0;
            ParameterData{i}.prop4=0;
            ParameterData{i}.prop5=0;
            
            ParameterData{i}.s=CRVt;
            ParameterData{i}.t=[0 0 1 1];
            
            ParameterData{i}.w=[CRVw;CRVw]';
            ParameterData{i}.p=zeros(3,CRVk+1,2);
            ParameterData{i}.p(:,:,1)=CRVp;
            ParameterData{i}.p(:,:,2)=CRVp;
            ParameterData{i}.p(1,:,2)=ParameterData{i}.p(1,:,2)+(ParameterData{i}.lx-CRVp(1,1));
            ParameterData{i}.p(2,:,2)=ParameterData{i}.p(2,:,2)+(ParameterData{i}.ly-CRVp(2,1));
            ParameterData{i}.p(3,:,2)=ParameterData{i}.p(3,:,2)+(ParameterData{i}.lz-CRVp(3,1));
            
            ParameterData{i}.u=[0 1];
            ParameterData{i}.v=[0 1];
            
            ParameterData{i}.isplane=isplane;
            
            
            % NURBS surface
            
            ParameterData{i}.nurbs.form='B-NURBS';
            ParameterData{i}.nurbs.dim=4;
            ParameterData{i}.nurbs.number=[CRVk+1 2];
            ParameterData{i}.nurbs.coefs=zeros(4,CRVk+1,2);
            
            for ii=1:2
                ParameterData{i}.nurbs.coefs(4,:,ii)=ParameterData{i}.w(:,ii)';
                
                ParameterData{i}.nurbs.coefs(1,:,ii)=ParameterData{i}.nurbs.coefs(4,:,ii).*ParameterData{i}.p(1,:,ii);
                ParameterData{i}.nurbs.coefs(2,:,ii)=ParameterData{i}.nurbs.coefs(4,:,ii).*ParameterData{i}.p(2,:,ii);
                ParameterData{i}.nurbs.coefs(3,:,ii)=ParameterData{i}.nurbs.coefs(4,:,ii).*ParameterData{i}.p(3,:,ii);
            end
            
            ParameterData{i}.nurbs.knots=cell(1,2);
            ParameterData{i}.nurbs.knots{1}=CRVt;
            ParameterData{i}.nurbs.knots{2}=[0 0 1 1];
            
            ParameterData{i}.nurbs.order=[CRVm+1 2];
            
            [ParameterData{i}.dnurbs,ParameterData{i}.d2nurbs]=nrbDerivativesIGES(ParameterData{i}.nurbs);
            
        else
            
            entunk(ParameterData{i}.type)=entunk(ParameterData{i}.type)+1;
            entty(ParameterData{i}.type)=entty(ParameterData{i}.type)-1;
            
            ParameterData{i}.well=false;
            
        end
        
    elseif ParameterData{i}.type==408
        
        ParameterData{ParameterData{i}.de}.numinstances=ParameterData{ParameterData{i}.de}.numinstances+1;
        ParameterData{ParameterData{i}.de}.iptrs(ParameterData{ParameterData{i}.de}.numinstances)=i;
        
    end
    
end

num143=entty(143);
num144=entty(144);

ent_ind=1:520;
EntityType=ent_ind(entty>0);
numEntityType=entty(entty>0);
unknownEntityType=ent_ind(entunk>0);
numunknownEntityType=entunk(entunk>0);

if not(isempty(unknownEntityType))
    disp(' ');
    disp(['Warning: There are unknown entity types for iges2matlab in ',igsfile,'.']);
    disp(' ');
    disp('Use e.g. "I-DEAS 3D IGES Translator" with NURBS as surface representation instead.');
    disp('If you dont have that posibility you can add missing IGES entities into iges2matlab().');
    disp('IGES documentation is found on the internet');
    disp(' ');
end


% Transform surfaces if necessary

if transformationExists
    
    % Use transformation entities on surfaces
    for i=1:noent
        
        if ParameterData{i}.type==128
            if ParameterData{i}.well
                if ParameterData{i}.trnsfrmtnmtrx>0
                    if not(ParameterData{ParameterData{i}.trnsfrmtnmtrx}.isidentity)
                        
                        R=ParameterData{ParameterData{i}.trnsfrmtnmtrx}.r;
                        T=ParameterData{ParameterData{i}.trnsfrmtnmtrx}.t;
                        
                        for j=1:(ParameterData{i}.k1+1)
                            for k=1:(ParameterData{i}.k2+1)
                                ParameterData{i}.p(:,j,k)=R*ParameterData{i}.p(:,j,k)+T;
                            end
                        end
                        
                        ParameterData{i}.nurbs.coefs(1:3,:,:)=repmat(ParameterData{i}.nurbs.coefs(4,:,:),3,1).*ParameterData{i}.p;
                        [ParameterData{i}.dnurbs,ParameterData{i}.d2nurbs]=nrbDerivativesIGES(ParameterData{i}.nurbs);
                        
                    end
                end
            end
        elseif ParameterData{i}.type==108
            if ParameterData{i}.well
                if ParameterData{i}.trnsfrmtnmtrx>0
                    if not(ParameterData{ParameterData{i}.trnsfrmtnmtrx}.isidentity)
                        
                        R=ParameterData{ParameterData{i}.trnsfrmtnmtrx}.r;
                        T=ParameterData{ParameterData{i}.trnsfrmtnmtrx}.t;
                        
                        ParameterData{i}.d=ParameterData{i}.d+dot(ParameterData{i}.normal,R'*T);
                        
                        ParameterData{i}.normal=R*ParameterData{i}.normal;
                        
                        ParameterData{i}.a=ParameterData{i}.normal(1);
                        ParameterData{i}.b=ParameterData{i}.normal(2);
                        ParameterData{i}.c=ParameterData{i}.normal(3);
                        
                        X=R*[ParameterData{i}.x;ParameterData{i}.y;ParameterData{i}.z]+T;
                        
                        ParameterData{i}.x=X(1);
                        ParameterData{i}.y=X(2);
                        ParameterData{i}.z=X(3);
                        
                    end
                end
            end
        end
        
    end
    
end

% Create offset surfaces

if offsetsurfaceExists
    for i=1:noent
        if ParameterData{i}.type==140
            
            entiall=ParameterData{i}.de;
            ParameterData{entiall}.superior=1;
            
            if ParameterData{entiall}.type==108
                
                if ParameterData{entiall}.a*ParameterData{i}.nx+ParameterData{entiall}.b*ParameterData{i}.ny+ParameterData{entiall}.c*ParameterData{i}.nz>0
                    signdist=ParameterData{i}.d;
                else
                    signdist=-ParameterData{i}.d;
                end
                
                ParameterData{i}.type=108;
                
                ParameterData{i}.name='PLANE';
                ParameterData{i}.original=0;
                ParameterData{i}.previous_type=140;
                ParameterData{i}.previous_name='OFFSET SURFACE';
                
                ParameterData{i}.a=ParameterData{entiall}.a;
                ParameterData{i}.b=ParameterData{entiall}.b;
                ParameterData{i}.c=ParameterData{entiall}.c;
                ParameterData{i}.d=ParameterData{entiall}.d+signdist*norm(ParameterData{entiall}.normal);
                
                ParameterData{i}.ptr=ParameterData{entiall}.ptr;
                
                ParameterData{i}.x=ParameterData{entiall}.x+signdist*ParameterData{entiall}.a/norm(ParameterData{entiall}.normal);
                ParameterData{i}.y=ParameterData{entiall}.y+signdist*ParameterData{entiall}.b/norm(ParameterData{entiall}.normal);
                ParameterData{i}.z=ParameterData{entiall}.z+signdist*ParameterData{entiall}.c/norm(ParameterData{entiall}.normal);
                ParameterData{i}.size=ParameterData{entiall}.size;
                
                ParameterData{i}.normal=ParameterData{entiall}.normal;
                
                ParameterData{i}.isplane=true;
                ParameterData{i}.ulinear=1;
                ParameterData{i}.vlinear=1;
                
            elseif ParameterData{entiall}.type==128
                
                ParameterData{i}.type=128;
                
                ParameterData{i}.name='B-NURBS SRF';
                ParameterData{i}.original=0;
                ParameterData{i}.previous_type=140;
                ParameterData{i}.previous_name='OFFSET SURFACE';
                
                ParameterData{i}.k1=ParameterData{entiall}.k1;
                ParameterData{i}.k2=ParameterData{entiall}.k2;
                ParameterData{i}.m1=ParameterData{entiall}.m1;
                ParameterData{i}.m2=ParameterData{entiall}.m2;
                
                ParameterData{i}.prop1=ParameterData{entiall}.prop1;
                ParameterData{i}.prop2=ParameterData{entiall}.prop2;
                ParameterData{i}.prop3=ParameterData{entiall}.prop3;
                ParameterData{i}.prop4=ParameterData{entiall}.prop4;
                ParameterData{i}.prop5=ParameterData{entiall}.prop5;
                
                ParameterData{i}.s=ParameterData{entiall}.s;
                ParameterData{i}.v=ParameterData{entiall}.t;
                
                ParameterData{i}.w=ParameterData{entiall}.w;
                ParameterData{i}.p=ParameterData{entiall}.p;
                
                ParameterData{i}.u=ParameterData{entiall}.u;
                ParameterData{i}.v=ParameterData{entiall}.v;
                
                ParameterData{i}.isplane=ParameterData{entiall}.isplane;
                ParameterData{i}.ulinear=ParameterData{entiall}.ulinear;
                ParameterData{i}.vlinear=ParameterData{entiall}.vlinear;
                
                % NURBS surface
                
                NURBSorg=ParameterData{entiall}.nurbs;
                dNURBSorg=ParameterData{entiall}.dnurbs;
                d2NURBSorg=ParameterData{entiall}.d2nurbs;
                
                UVm=[mean(ParameterData{entiall}.u);mean(ParameterData{entiall}.v)];
                [~,Pmu,Pmv]=nrbevalIGES(ParameterData{entiall}.nurbs,UVm,ParameterData{entiall}.dnurbs,ParameterData{entiall}.d2nurbs);
                
                Nm=cross(Pmu,Pmv);
                if Nm(1)*ParameterData{i}.nx+Nm(2)*ParameterData{i}.ny+Nm(3)*ParameterData{i}.nz>0
                    signdist=ParameterData{i}.d;
                else
                    signdist=-ParameterData{i}.d;
                end
                
                [NURBSoffset,coefsOffset,wghsOffset]=offsetNURBSsurface(signdist,NURBSorg,dNURBSorg,d2NURBSorg);
                [dNURBSoffset,d2NURBSoffset]=nrbDerivativesIGES(NURBSoffset);
                
                ParameterData{i}.w=wghsOffset;
                ParameterData{i}.p=coefsOffset;
                
                ParameterData{i}.nurbs=NURBSoffset;
                ParameterData{i}.dnurbs=dNURBSoffset;
                ParameterData{i}.d2nurbs=d2NURBSoffset;
                
            else
                
                disp(['Warning: Could not handle entity type 140 correctly in ',igsfile,'.']);
                
            end
            
        end
    end
end

% Use color entities
entities2color=[102 108 110 116 126 128 141 142 143 144];

meanLengthCrv=0;

for i=1:noent
    
    if ParameterData{i}.type==141
        
        if ParameterData{ParameterData{i}.sptr}.type==128
            ParameterData=retPsCrvLength(ParameterData{i}.sptr,ParameterData,i,75);
        end
        [ParameterData,le]=retMsCrvLength(ParameterData,i,75);
        meanLengthCrv=meanLengthCrv+le;
        
    end
    
    if any(ParameterData{i}.type==entities2color)
        if ParameterData{i}.well
            
            if ParameterData{i}.clrnmbr>0
                
                % Color numbers
                if ParameterData{i}.clrnmbr==2
                    ParameterData{i}.color(1)=1;
                elseif ParameterData{i}.clrnmbr==3
                    ParameterData{i}.color(2)=1;
                elseif ParameterData{i}.clrnmbr==4
                    ParameterData{i}.color(3)=1;
                elseif ParameterData{i}.clrnmbr==5
                    ParameterData{i}.color(1)=1;
                    ParameterData{i}.color(2)=1;
                elseif ParameterData{i}.clrnmbr==6
                    ParameterData{i}.color(1)=1;
                    ParameterData{i}.color(3)=1;
                elseif ParameterData{i}.clrnmbr==7
                    ParameterData{i}.color(2)=1;
                    ParameterData{i}.color(3)=1;
                elseif ParameterData{i}.clrnmbr==8
                    ParameterData{i}.color(:)=1;
                end
                
            elseif ParameterData{i}.clrnmbr==0
                
                % Default color
                ParameterData{i}.color(:)=defaultColor;
                
            else
                
                % Color from entity 314
                ParameterData{i}.color(:)=ParameterData{-ParameterData{i}.clrnmbr}.color;
                
            end
            
        end
    end
end

noentII=noent;

for i=1:noent
    
    if ParameterData{i}.type==143
        
        entiall=ParameterData{i}.sptr;
        
        ParameterData{entiall}.superior=1;
        
        for j=1:ParameterData{i}.n
            ParameterData=unDoSupMkC(ParameterData,ParameterData{i}.bdpt(j));
        end
        
        ParameterData{i}.nument=num143;
        
    elseif ParameterData{i}.type==144
        
        entiall=ParameterData{i}.pts;
        
        ParameterData{entiall}.superior=1;
        
        if ParameterData{i}.n1
            ParameterData=unDoSupMkC(ParameterData,ParameterData{i}.pto);
        end
        
        for j=1:ParameterData{i}.n2
            ParameterData=unDoSupMkC(ParameterData,ParameterData{i}.pti(j));
        end
        
        ParameterData{i}.nument=num144;
        
        if ParameterData{entiall}.original
            
            if and(and(ParameterData{entiall}.type==128,not(ParameterData{i}.n1)),ParameterData{i}.n2==0)
                
                ParameterData{i}.original=ParameterData{entiall}.original;
                ParameterData{i}.trimmed=0;
                
                ParameterData{i}.u=ParameterData{entiall}.u;
                ParameterData{i}.v=ParameterData{entiall}.v;
                
                ParameterData{i}.isplane=ParameterData{entiall}.isplane;
                ParameterData{i}.ulinear=ParameterData{entiall}.ulinear;
                ParameterData{i}.vlinear=ParameterData{entiall}.vlinear;
            
            elseif ParameterData{entiall}.type==128
                
                oCptr=ParameterData{ParameterData{i}.pto}.bptr;
                
                if and(ParameterData{i}.n2==0,ParameterData{oCptr}.type==102)
                    
                    allLines=true;
                    
                    uintrvl=[ParameterData{entiall}.u(2),ParameterData{entiall}.u(1)];
                    vintrvl=[ParameterData{entiall}.v(2),ParameterData{entiall}.v(1)];
                    
                    for j=1:ParameterData{oCptr}.n
                        
                        ind=ParameterData{oCptr}.de(j);
                        
                        if ParameterData{ind}.type==126
                            
                            meaUV=mean(ParameterData{ind}.p(1:2,:),2);
                            
                            singVals=svd(ParameterData{ind}.p(1:2,:)*ParameterData{ind}.p(1:2,:)'-((ParameterData{ind}.k+1)*meaUV)*meaUV');
                            
                            if 1e6*singVals(2)>singVals(1)
                                allLines=false;
                                break
                            end
                            
                            uintrvl(1)=min(ParameterData{ind}.p(1,1),uintrvl(1));
                            uintrvl(2)=max(ParameterData{ind}.p(1,1),uintrvl(2));
                            
                            uintrvl(1)=min(ParameterData{ind}.p(1,end),uintrvl(1));
                            uintrvl(2)=max(ParameterData{ind}.p(1,end),uintrvl(2));
                            
                            vintrvl(1)=min(ParameterData{ind}.p(2,1),vintrvl(1));
                            vintrvl(2)=max(ParameterData{ind}.p(2,1),vintrvl(2));
                            
                            vintrvl(1)=min(ParameterData{ind}.p(2,end),vintrvl(1));
                            vintrvl(2)=max(ParameterData{ind}.p(2,end),vintrvl(2));
                            
                        elseif ParameterData{ind}.type==110
                            
                            uintrvl(1)=min(ParameterData{ind}.x1,uintrvl(1));
                            uintrvl(2)=max(ParameterData{ind}.x1,uintrvl(2));
                            
                            uintrvl(1)=min(ParameterData{ind}.x2,uintrvl(1));
                            uintrvl(2)=max(ParameterData{ind}.x2,uintrvl(2));
                            
                            vintrvl(1)=min(ParameterData{ind}.y1,vintrvl(1));
                            vintrvl(2)=max(ParameterData{ind}.y1,vintrvl(2));
                            
                            vintrvl(1)=min(ParameterData{ind}.y2,vintrvl(1));
                            vintrvl(2)=max(ParameterData{ind}.y2,vintrvl(2));
                            
                        else
                            allLines=false;
                            break
                        end
                        
                    end
                    
                    dU=abs(uintrvl(2)-uintrvl(1));
                    dV=abs(vintrvl(2)-vintrvl(1));
                    
                    if allLines
                        for j=1:ParameterData{oCptr}.n
                            
                            [stP,endP,~,allLines]=endPoints(ParameterData,ParameterData{oCptr}.de(j));
                            
                            if allLines
                                
                                if and(abs(endP(1)-stP(1))>1e-4*dU,abs(endP(2)-stP(2))>1e-4*dV)
                                    allLines=false;
                                    break
                                elseif and(and((stP(1)-uintrvl(1))>1e-4*dU,(uintrvl(2)-stP(1))>1e-4*dU),and((stP(2)-vintrvl(1))>1e-4*dV,(vintrvl(2)-stP(2))>1e-4*dV))
                                    allLines=false;
                                    break
                                elseif and(and((endP(1)-uintrvl(1))>1e-4*dU,(uintrvl(2)-endP(1))>1e-4*dU),and((endP(2)-vintrvl(1))>1e-4*dV,(vintrvl(2)-endP(2))>1e-4*dV))
                                    allLines=false;
                                    break
                                end
                                
                            else
                                break
                            end
                            
                        end
                    end
                    
                    if allLines
                        
                        ParameterData{i}.trimmed=0;
                        
                        ParameterData{i}.u=uintrvl;
                        ParameterData{i}.v=vintrvl;
                        
                        ParameterData{i}.isplane=ParameterData{entiall}.isplane;
                        ParameterData{i}.ulinear=ParameterData{entiall}.ulinear;
                        ParameterData{i}.vlinear=ParameterData{entiall}.vlinear;
                        
                        clear P
                        
                    end
                    
                end
                
            end
            
        else
            
            if and(and(and(ParameterData{entiall}.previous_type==120,ParameterData{entiall}.well),not(ParameterData{i}.n1)),ParameterData{i}.n2==0)
                
                ParameterData{i}.original=0;
                ParameterData{i}.trimmed=0;
                
                ParameterData{i}.u=ParameterData{entiall}.u;
                ParameterData{i}.v=ParameterData{entiall}.v;
                
                ParameterData{i}.isplane=false;
                ParameterData{i}.ulinear=ParameterData{entiall}.ulinear;
                ParameterData{i}.vlinear=0;
                
            elseif and(and(ParameterData{entiall}.previous_type==120,ParameterData{entiall}.well),ParameterData{i}.n1)
                
                oCptr=ParameterData{ParameterData{i}.pto}.cptr;
                
                [trimCRVS,numCrv,cInterval,aInterval,anglIntrvl,allLines,domainIsRectangle]=findBoundaryInParameterSpace120(ParameterData,i,oCptr);
                
                ParameterData{i}.original=0;
                
                if and(ParameterData{i}.n2==0,domainIsRectangle)
                    
                    ParameterData{i}.trimmed=0;
                    
                    ParameterData{i}.u=cInterval;
                    ParameterData{i}.v=aInterval;
                    
                    ParameterData{i}.isplane=false;
                    ParameterData{i}.ulinear=ParameterData{entiall}.ulinear;
                    ParameterData{i}.vlinear=0;
                    
                end
                
                if numCrv>1
                    
                    noentII=noentII+1;
                    
                    ParameterData{noentII+numCrv}=[];
                    
                    ParameterData{ParameterData{i}.pto}.bptr=noentII;
                    
                    ParameterData{noentII}=ParameterData{oCptr};
                    
                    ParameterData{noentII}.de(:)=(noentII+1):(noentII+numCrv);
                    
                    ParameterData{noentII}.allLines=allLines;
                    
                    for jj=1:numCrv
                        ParameterData{noentII+jj}=trimCRVS{jj};
                    end
                    
                    noentII=noentII+numCrv;
                    
                else
                    
                    noentII=noentII+1;
                    
                    ParameterData{noentII}=trimCRVS;
                    
                    ParameterData{ParameterData{i}.pto}.bptr=noentII;
                    
                end
                
                for j=1:ParameterData{i}.n2
                    
                    iCptr=ParameterData{ParameterData{i}.pti(j)}.cptr;
                    
                    [trimCRVS,numCrv]=findBoundaryInParameterSpace120(ParameterData,i,iCptr);
                    
                    if numCrv>1
                        
                        noentII=noentII+1;
                        
                        ParameterData{noentII+numCrv}=[];
                        
                        ParameterData{ParameterData{i}.pti(j)}.bptr=noentII;
                        
                        ParameterData{noentII}=ParameterData{iCptr};
                        
                        ParameterData{noentII}.de(:)=(noentII+1):(noentII+numCrv);
                        
                        ParameterData{noentII}.allLines=allLines;
                        
                        for jj=1:numCrv
                            ParameterData{noentII+jj}=trimCRVS{jj};
                        end
                        
                        noentII=noentII+numCrv;
                        
                    else
                        
                        noentII=noentII+1;
                        
                        ParameterData{noentII}=trimCRVS;
                        
                        ParameterData{ParameterData{i}.pti(j)}.bptr=noentII;
                        
                    end
                    
                end
                
            elseif and(and(or(or(ParameterData{entiall}.previous_type==118,ParameterData{entiall}.previous_type==122),ParameterData{entiall}.previous_type==140),ParameterData{entiall}.well),ParameterData{i}.n1)
                
                oCptr=ParameterData{ParameterData{i}.pto}.cptr;
                [trimCRVS,uInterval,vInterval,numCrv,allLines,domainIsRectangle]=findBoundaryInNURBSParameterSpace(ParameterData,i,oCptr);
                
                if and(ParameterData{i}.n2==0,domainIsRectangle)
                    ParameterData{i}.trimmed=0;
                    ParameterData{i}.u=uInterval;
                    ParameterData{i}.v=vInterval;
                    
                    ParameterData{i}.isplane=ParameterData{entiall}.isplane;
                    ParameterData{i}.ulinear=ParameterData{entiall}.ulinear;
                    ParameterData{i}.vlinear=ParameterData{entiall}.vlinear;
                else
                    
                    if numCrv>1
                        
                        noentII=noentII+1;
                        
                        ParameterData{noentII+numCrv}=[];
                        
                        ParameterData{ParameterData{i}.pto}.bptr=noentII;
                        
                        ParameterData{noentII}=ParameterData{oCptr};
                        
                        ParameterData{noentII}.de(:)=(noentII+1):(noentII+numCrv);
                        
                        ParameterData{noentII}.allLines=allLines;
                        
                        for jj=1:numCrv
                            ParameterData{noentII+jj}=trimCRVS{jj};
                        end
                        
                        noentII=noentII+numCrv;
                        
                    else
                        
                        noentII=noentII+1;
                        
                        ParameterData{noentII}=trimCRVS;
                        
                        ParameterData{ParameterData{i}.pto}.bptr=noentII;
                        
                    end
                    
                    for j=1:ParameterData{i}.n2
                        
                        iCptr=ParameterData{ParameterData{i}.pti(j)}.cptr;
                        
                        [trimCRVS,~,~,numCrv,allLines]=findBoundaryInNURBSParameterSpace(ParameterData,i,iCptr);
                        
                        if numCrv>1
                            
                            noentII=noentII+1;
                            
                            ParameterData{noentII+numCrv}=[];
                            
                            ParameterData{ParameterData{i}.pti(j)}.bptr=noentII;
                            
                            ParameterData{noentII}=ParameterData{iCptr};
                            
                            ParameterData{noentII}.de(:)=(noentII+1):(noentII+numCrv);
                            
                            ParameterData{noentII}.allLines=allLines;
                            
                            for jj=1:numCrv
                                ParameterData{noentII+jj}=trimCRVS{jj};
                            end
                            
                            noentII=noentII+numCrv;
                            
                        else
                            
                            noentII=noentII+1;
                            
                            ParameterData{noentII}=trimCRVS;
                            
                            ParameterData{ParameterData{i}.pti(j)}.bptr=noentII;
                            
                        end
                        
                    end
                    
                end
                
                ParameterData{i}.original=0;
                
            elseif ParameterData{entiall}.well
                
                ParameterData{i}.u=ParameterData{entiall}.u;
                ParameterData{i}.v=ParameterData{entiall}.v;
                
                ParameterData{i}.isplane=ParameterData{entiall}.isplane;
                ParameterData{i}.ulinear=ParameterData{entiall}.ulinear;
                ParameterData{i}.vlinear=ParameterData{entiall}.vlinear;
                
                ParameterData{i}.trimmed=0;
                
                ParameterData{i}.original=0;
                
            else
                
                ParameterData{i}.well=false;
                
            end
            
        end
        
    end
    
end

for i=1:noentII
    
    if ParameterData{i}.type==142
        
        if ParameterData{ParameterData{i}.sptr}.type==128
            ParameterData=retPsCrvLength(ParameterData{i}.sptr,ParameterData,i,75);
        end
        [ParameterData,le]=retMsCrvLength(ParameterData,i,75);
        meanLengthCrv=meanLengthCrv+le;
        
    end
    
end

meanLengthCrv=max(meanLengthCrv/max(num143+num144,1),1);

if num143+num144<20
    if num143+num144<5
        meanLengthCrv=meanLengthCrv/4;
    elseif num143+num144<13
        meanLengthCrv=meanLengthCrv/3;
    else
        meanLengthCrv=meanLengthCrv/2;
    end
end

numPnt=101;

nu=numPnt;
nv=numPnt;

for i=1:noentII
    
    if ParameterData{i}.type==126
        if ParameterData{i}.length==0
            [~,le,evmtd]=crvPntsSrfNURBS(90,ParameterData{i}.nurbs,ParameterData{i}.v(1),ParameterData{i}.v(2));
            ParameterData{i}.length=le;
            ParameterData{i}.evalmthd=evmtd;
        end
    elseif ParameterData{i}.type==110
        if ParameterData{i}.length==0
            [~,le,~]=crvPntsSrfNURBS(1,ParameterData{i}.p1,ParameterData{i}.p2);
            ParameterData{i}.length=le;
        end
    end
    
    if ParameterData{i}.type==128
        
        P=nrbSrfRegularEvalIGES(ParameterData{i}.nurbs,ParameterData{i}.u(1),ParameterData{i}.u(2),nu,ParameterData{i}.v(1),ParameterData{i}.v(2),nv);
        
        for j=1:numPnt
            ParameterData{i}.ratio(1)=max(sum(sqrt(sum((P(:,(2+(j-1)*numPnt):(j*numPnt))-P(:,(1+(j-1)*numPnt):(j*numPnt-1))).^2,1))),ParameterData{i}.ratio(1));
        end
        
        for j=1:numPnt
            ParameterData{i}.ratio(2)=max(sum(sqrt(sum((P(:,(numPnt+j):numPnt:((numPnt-1)*numPnt+j))-P(:,j:numPnt:((numPnt-2)*numPnt+j))).^2,1))),ParameterData{i}.ratio(2));
        end
        
        ParameterData{i}.ratio=ParameterData{i}.ratio*(4/meanLengthCrv);
        
        ctrlPnts=ParameterData{i}.p(:,:);
        meaP=mean(ctrlPnts,2);
        
        singVals=svd(ctrlPnts*ctrlPnts'-(size(ctrlPnts,2)*meaP)*meaP');
        
        if 1e6*singVals(3)<singVals(2)
            ParameterData{i}.isplane=true;
        end
        
    elseif ParameterData{i}.type==141
        ParameterData{i}.mlcrv=meanLengthCrv;
    elseif ParameterData{i}.type==142
        ParameterData{i}.mlcrv=meanLengthCrv;
    elseif ParameterData{i}.type==143
        ParameterData{i}.mlcrv=meanLengthCrv;
    elseif ParameterData{i}.type==144
        ParameterData{i}.mlcrv=meanLengthCrv;
        
        if not(ParameterData{i}.trimmed)
            P=nrbSrfRegularEvalIGES(ParameterData{ParameterData{i}.pts}.nurbs,ParameterData{i}.u(1),ParameterData{i}.u(2),nu,ParameterData{i}.v(1),ParameterData{i}.v(2),nv);
            
            for j=1:numPnt
                ParameterData{i}.ratio(1)=max(sum(sqrt(sum((P(:,(2+(j-1)*numPnt):(j*numPnt))-P(:,(1+(j-1)*numPnt):(j*numPnt-1))).^2,1))),ParameterData{i}.ratio(1));
            end
            
            for j=1:numPnt
                ParameterData{i}.ratio(2)=max(sum(sqrt(sum((P(:,(numPnt+j):numPnt:((numPnt-1)*numPnt+j))-P(:,j:numPnt:((numPnt-2)*numPnt+j))).^2,1))),ParameterData{i}.ratio(2));
            end
            
            ParameterData{i}.ratio=ParameterData{i}.ratio*(4/meanLengthCrv);
        end
    end
    
end

for i=1:noentII
    
    if ParameterData{i}.type==143
        ParameterData{i}.ratio=ParameterData{ParameterData{i}.sptr}.ratio;
    end
    if ParameterData{i}.type==144
        if ParameterData{i}.trimmed
            ParameterData{i}.ratio=ParameterData{ParameterData{i}.pts}.ratio;
        end
    end
    
end

if subfiguresExists
    
    numNewEntities=0;
    
    for i=1:noent
        
        if ParameterData{i}.type==308
            if ParameterData{i}.numinstances>1
                
                numNewEntitiesTmp=0;
                for jj=1:ParameterData{i}.n
                    numNewEntitiesTmp=countEntitiesSubfigure(ParameterData,ParameterData{i}.de(jj),numNewEntitiesTmp);
                end
                numNewEntities=numNewEntities+(ParameterData{i}.numinstances-1)*numNewEntitiesTmp;
                
            end
        end
        
    end
    
    if numNewEntities>0
        ParameterData{noentII+numNewEntities}=[];
    end
    
    for i=1:noent
        
        if ParameterData{i}.type==308
            
            for j=1:(ParameterData{i}.numinstances-1)
                
                instPtr=ParameterData{i}.iptrs(j);
                
                if ParameterData{instPtr}.trnsfrmtnmtrx==0
                    R=ParameterData{instPtr}.s*eye(3);
                    T=ParameterData{instPtr}.t;
                else
                    R=ParameterData{instPtr}.s*ParameterData{ParameterData{instPtr}.trnsfrmtnmtrx}.r;
                    T=ParameterData{ParameterData{instPtr}.trnsfrmtnmtrx}.t+ParameterData{instPtr}.t;
                end
                
                for jj=1:ParameterData{i}.n
                    [noentII,ParameterData]=createTransfEntitiesSubfigure(ParameterData,ParameterData{i}.de(jj),noentII,R,T);
                end
                
            end
            
            instPtr=ParameterData{i}.iptrs(ParameterData{i}.numinstances);
            
            if ParameterData{instPtr}.trnsfrmtnmtrx==0
                R=ParameterData{instPtr}.s*eye(3);
                T=ParameterData{instPtr}.t;
            else
                R=ParameterData{instPtr}.s*ParameterData{ParameterData{instPtr}.trnsfrmtnmtrx}.r;
                T=ParameterData{ParameterData{instPtr}.trnsfrmtnmtrx}.t+ParameterData{instPtr}.t;
            end
            
            for jj=1:ParameterData{i}.n
                ParameterData=transformSubfigure(ParameterData,ParameterData{i}.de(jj),R,T);
            end
            
        end
        
    end
end


function [numEntities,ParameterData]=createTransfEntitiesSubfigure(ParameterData,i,numEntities,R,T)

if ParameterData{i}.type==128
    
    numEntities=numEntities+1;
    
    ParameterData{numEntities}=ParameterData{i};
    
    for j=1:(ParameterData{numEntities}.k1+1)
        for k=1:(ParameterData{numEntities}.k2+1)
            ParameterData{numEntities}.p(:,j,k)=R*ParameterData{numEntities}.p(:,j,k)+T;
        end
    end
    
    ParameterData{numEntities}.nurbs.coefs(1:3,:,:)=repmat(ParameterData{numEntities}.nurbs.coefs(4,:,:),3,1).*ParameterData{numEntities}.p;
    [ParameterData{numEntities}.dnurbs,ParameterData{numEntities}.d2nurbs]=nrbDerivativesIGES(ParameterData{numEntities}.nurbs);
    
elseif ParameterData{i}.type==108
    
    numEntities=numEntities+1;
    
    ParameterData{numEntities}=ParameterData{i};
    
    ParameterData{numEntities}.d=ParameterData{numEntities}.d+dot(ParameterData{numEntities}.normal,R'*T);
    
    ParameterData{numEntities}.normal=R*ParameterData{numEntities}.normal;
    
    ParameterData{numEntities}.a=ParameterData{numEntities}.normal(1);
    ParameterData{numEntities}.b=ParameterData{numEntities}.normal(2);
    ParameterData{numEntities}.c=ParameterData{numEntities}.normal(3);
    
    X=R*[ParameterData{numEntities}.x;ParameterData{numEntities}.y;ParameterData{numEntities}.z]+T;
    
    ParameterData{numEntities}.x=X(1);
    ParameterData{numEntities}.y=X(2);
    ParameterData{numEntities}.z=X(3);
    
elseif ParameterData{i}.type==144
    
    numEntities=numEntities+1;
    
    thisEntity=numEntities;
    
    ParameterData{thisEntity}=ParameterData{i};
    
    entiall=ParameterData{i}.pts;
    
    ParameterData{thisEntity}.pts=numEntities+1;
    [numEntities,ParameterData]=createTransfEntitiesSubfigure(ParameterData,entiall,numEntities,R,T);
    
    if ParameterData{thisEntity}.n1
        ParameterData{thisEntity}.pto=numEntities+1;
        [numEntities,ParameterData]=createTransfEntitiesSubfigure(ParameterData,ParameterData{i}.pto,numEntities,R,T);
    end
    for j=1:ParameterData{thisEntity}.n2
        ParameterData{thisEntity}.pti(j)=numEntities+1;
        [numEntities,ParameterData]=createTransfEntitiesSubfigure(ParameterData,ParameterData{i}.pti(j),numEntities,R,T);
    end
    
elseif ParameterData{i}.type==126
    
    if not(ParameterData{i}.superior)
        
        numEntities=numEntities+1;
        
        ParameterData{numEntities}=ParameterData{i};
        
        for j=1:(ParameterData{numEntities}.k+1)
            ParameterData{numEntities}.p(:,j)=R*(ParameterData{numEntities}.p(:,j))+T;
        end
        
        ParameterData{numEntities}.nurbs.coefs(1:3,:)=repmat(ParameterData{numEntities}.nurbs.coefs(4,:),3,1).*ParameterData{numEntities}.p;
        [ParameterData{numEntities}.dnurbs,ParameterData{numEntities}.d2nurbs]=nrbDerivativesIGES(ParameterData{numEntities}.nurbs);
        
    end
    
elseif ParameterData{i}.type==102
    
    numEntities=numEntities+1;
    
    thisEntity=numEntities;
    
    ParameterData{thisEntity}=ParameterData{i};
    
    for j=1:ParameterData{thisEntity}.n
        ParameterData{thisEntity}.de(j)=numEntities+1;
        [numEntities,ParameterData]=createTransfEntitiesSubfigure(ParameterData,ParameterData{i}.de(j),numEntities,R,T);
    end
    
elseif ParameterData{i}.type==141
    
    numEntities=numEntities+1;
    
    thisEntity=numEntities;
    
    ParameterData{thisEntity}=ParameterData{i};
    
    for j=1:ParameterData{i}.n
        for jj=1:ParameterData{i}.k(j)
            ParameterData{thisEntity}.pscpt{j}(jj)=numEntities+1;
            [numEntities,ParameterData]=createTransfEntitiesSubfigure(ParameterData,ParameterData{i}.pscpt{j}(jj),numEntities,R,T);
        end
    end
    
elseif ParameterData{i}.type==142
    
    numEntities=numEntities+1;
    
    thisEntity=numEntities;
    
    ParameterData{thisEntity}=ParameterData{i};
    
    ParameterData{thisEntity}.cptr=numEntities+1;
    [numEntities,ParameterData]=createTransfEntitiesSubfigure(ParameterData,ParameterData{i}.cptr,numEntities,R,T);
    
elseif ParameterData{i}.type==143
    
    numEntities=numEntities+1;
    
    thisEntity=numEntities;
    
    ParameterData{thisEntity}=ParameterData{i};
    
    ParameterData{thisEntity}.sptr=numEntities+1;
    [numEntities,ParameterData]=createTransfEntitiesSubfigure(ParameterData,ParameterData{i}.sptr,numEntities,R,T);
    
    for j=1:ParameterData{thisEntity}.n
        ParameterData{thisEntity}.bdpt(j)=numEntities+1;
        [numEntities,ParameterData]=createTransfEntitiesSubfigure(ParameterData,ParameterData{i}.bdpt(j),numEntities,R,T);
    end
    
elseif ParameterData{i}.type==110
    
    if not(ParameterData{i}.superior)
        
        numEntities=numEntities+1;
        
        ParameterData{numEntities}=ParameterData{i};
        
        ParameterData{numEntities}.p1=R*ParameterData{numEntities}.p1+T;
        ParameterData{numEntities}.x1=ParameterData{numEntities}.p1(1);
        ParameterData{numEntities}.y1=ParameterData{numEntities}.p1(2);
        ParameterData{numEntities}.z1=ParameterData{numEntities}.p1(3);
        
        ParameterData{numEntities}.p2=R*ParameterData{numEntities}.p2+T;
        ParameterData{numEntities}.x2=ParameterData{numEntities}.p2(1);
        ParameterData{numEntities}.y2=ParameterData{numEntities}.p2(2);
        ParameterData{numEntities}.z2=ParameterData{numEntities}.p2(3);
        
    end
    
elseif ParameterData{i}.type==116
    
    numEntities=numEntities+1;
    
    ParameterData{numEntities}=ParameterData{i};
    
    ParameterData{numEntities}.p=R*ParameterData{numEntities}.p+T;
    ParameterData{numEntities}.x=ParameterData{numEntities}.p(1);
    ParameterData{numEntities}.y=ParameterData{numEntities}.p(2);
    ParameterData{numEntities}.z=ParameterData{numEntities}.p(3);
    
end


function numEntities=countEntitiesSubfigure(ParameterData,i,numEntities)

if ParameterData{i}.type==128
    
    numEntities=numEntities+1;
    
elseif ParameterData{i}.type==108
    
    numEntities=numEntities+1;
    
elseif ParameterData{i}.type==144
    
    numEntities=numEntities+1;
    
    numEntities=countEntitiesSubfigure(ParameterData,ParameterData{i}.pts,numEntities);
    
    if ParameterData{i}.n1
        numEntities=countEntitiesSubfigure(ParameterData,ParameterData{i}.pto,numEntities);
    end
    for j=1:ParameterData{i}.n2
        numEntities=countEntitiesSubfigure(ParameterData,ParameterData{i}.pti(j),numEntities);
    end
    
elseif ParameterData{i}.type==126
    
    if not(ParameterData{i}.superior)
        numEntities=numEntities+1;
    end
    
elseif ParameterData{i}.type==102
    
    numEntities=numEntities+1;
    
    for j=1:ParameterData{i}.n
        numEntities=countEntitiesSubfigure(ParameterData,ParameterData{i}.de(j),numEntities);
    end
    
elseif ParameterData{i}.type==141
    
    numEntities=numEntities+1;
    
    for j=1:ParameterData{i}.n
        for jj=1:ParameterData{i}.k(j)
            numEntities=countEntitiesSubfigure(ParameterData,ParameterData{i}.pscpt{j}(jj),numEntities);
        end
    end
    
elseif ParameterData{i}.type==142
    
    numEntities=numEntities+1;
    
    numEntities=countEntitiesSubfigure(ParameterData,ParameterData{i}.cptr,numEntities);
    
elseif ParameterData{i}.type==143
    
    numEntities=numEntities+1;
    
    numEntities=countEntitiesSubfigure(ParameterData,ParameterData{i}.sptr,numEntities);
    for j=1:ParameterData{i}.n
        numEntities=countEntitiesSubfigure(ParameterData,ParameterData{i}.bdpt(j),numEntities);
    end
    
elseif ParameterData{i}.type==110
    
    if not(ParameterData{i}.superior)
        numEntities=numEntities+1;
    end
    
elseif ParameterData{i}.type==116
    
    numEntities=numEntities+1;
    
end


function ParameterData=transformSubfigure(ParameterData,i,R,T)

if ParameterData{i}.type==128
    
    for j=1:(ParameterData{i}.k1+1)
        for k=1:(ParameterData{i}.k2+1)
            ParameterData{i}.p(:,j,k)=R*ParameterData{i}.p(:,j,k)+T;
        end
    end
    
    ParameterData{i}.nurbs.coefs(1:3,:,:)=repmat(ParameterData{i}.nurbs.coefs(4,:,:),3,1).*ParameterData{i}.p;
    [ParameterData{i}.dnurbs,ParameterData{i}.d2nurbs]=nrbDerivativesIGES(ParameterData{i}.nurbs);
    
elseif ParameterData{i}.type==108
    
    ParameterData{i}.d=ParameterData{i}.d+dot(ParameterData{i}.normal,R'*T);
    
    ParameterData{i}.normal=R*ParameterData{i}.normal;
    
    ParameterData{i}.a=ParameterData{i}.normal(1);
    ParameterData{i}.b=ParameterData{i}.normal(2);
    ParameterData{i}.c=ParameterData{i}.normal(3);
    
    X=R*[ParameterData{i}.x;ParameterData{i}.y;ParameterData{i}.z]+T;
    
    ParameterData{i}.x=X(1);
    ParameterData{i}.y=X(2);
    ParameterData{i}.z=X(3);
    
elseif ParameterData{i}.type==144
    
    entiall=ParameterData{i}.pts;
    
    ParameterData=transformSubfigure(ParameterData,entiall,R,T);
    
    if ParameterData{i}.n1
        ParameterData=transformSubfigure(ParameterData,ParameterData{i}.pto,R,T);
    end
    for j=1:ParameterData{i}.n2
        ParameterData=transformSubfigure(ParameterData,ParameterData{i}.pti(j),R,T);
    end
    
elseif ParameterData{i}.type==126
    
    if not(ParameterData{i}.superior)
        
        for j=1:(ParameterData{i}.k+1)
            ParameterData{i}.p(:,j)=R*(ParameterData{i}.p(:,j))+T;
        end
        
        ParameterData{i}.nurbs.coefs(1:3,:)=repmat(ParameterData{i}.nurbs.coefs(4,:),3,1).*ParameterData{i}.p;
        [ParameterData{i}.dnurbs,ParameterData{i}.d2nurbs]=nrbDerivativesIGES(ParameterData{i}.nurbs);
        
    end
    
elseif ParameterData{i}.type==102
    
    for j=1:ParameterData{i}.n
        ParameterData=transformSubfigure(ParameterData,ParameterData{i}.de(j),R,T);
    end
    
elseif ParameterData{i}.type==141
    
    for j=1:ParameterData{i}.n
        for jj=1:ParameterData{i}.k(j)
            ParameterData=transformSubfigure(ParameterData,ParameterData{i}.pscpt{j}(jj),R,T);
        end
    end
    
elseif ParameterData{i}.type==142
    
    ParameterData=transformSubfigure(ParameterData,ParameterData{i}.cptr,R,T);
    
elseif ParameterData{i}.type==143
    
    ParameterData=transformSubfigure(ParameterData,ParameterData{i}.sptr,R,T);
    for j=1:ParameterData{i}.n
        ParameterData=transformSubfigure(ParameterData,ParameterData{i}.bdpt(j),R,T);
    end
    
elseif ParameterData{i}.type==110
    
    if not(ParameterData{i}.superior)
        
        ParameterData{i}.p1=R*ParameterData{i}.p1+T;
        ParameterData{i}.x1=ParameterData{i}.p1(1);
        ParameterData{i}.y1=ParameterData{i}.p1(2);
        ParameterData{i}.z1=ParameterData{i}.p1(3);
        
        ParameterData{i}.p2=R*ParameterData{i}.p2+T;
        ParameterData{i}.x2=ParameterData{i}.p2(1);
        ParameterData{i}.y2=ParameterData{i}.p2(2);
        ParameterData{i}.z2=ParameterData{i}.p2(3);
        
    end
    
elseif ParameterData{i}.type==116
    
    ParameterData{i}.p=R*ParameterData{i}.p+T;
    ParameterData{i}.x=ParameterData{i}.p(1);
    ParameterData{i}.y=ParameterData{i}.p(2);
    ParameterData{i}.z=ParameterData{i}.p(3);
    
end


function [trimCRVS,numCrv,cInterval,aInterval,anglInterval,allLines,domainIsRectangle]=findBoundaryInParameterSpace120(ParameterData,ind,bCptr)

srfind=ParameterData{ind}.pts;

miA=ParameterData{srfind}.ta;
maA=ParameterData{srfind}.sa;

miR=ParameterData{srfind}.revolution.rnurbs.knots(end);
maR=ParameterData{srfind}.revolution.rnurbs.knots(1);

miC=ParameterData{srfind}.revolution.cnurbs.knots(end);
maC=ParameterData{srfind}.revolution.cnurbs.knots(1);

numPntComp=401;

ccpar=linspace(maC,miC,numPntComp);
compPnts=nrbevalIGES(ParameterData{srfind}.revolution.cnurbs,ccpar);
planeConstComp=ParameterData{srfind}.revolution.v'*compPnts;
compDist=zeros(1,numPntComp);

for i=1:numPntComp
    compDist(i)=norm(cross(ParameterData{srfind}.revolution.v,compPnts(:,i)-ParameterData{srfind}.revolution.p));
end

numSplineVal=50;
splinePnts=zeros(2,numSplineVal);

nrbDeg=2;

vmin=ParameterData{srfind}.sa;
vmax=ParameterData{srfind}.ta;
vdiff=vmax-vmin;
vdiffCh=max((2*pi-vdiff)/2,1e-6);


if ParameterData{bCptr}.type==102
    
    numPnt=251;
    
    numCrv=ParameterData{bCptr}.n;
    angl=zeros(1,numPnt);
    cparams0=zeros(1,numPnt);
    UV=zeros(2,numPnt);
    rPoints=zeros(3,numPnt);
    
    planeConst=zeros(1,numPnt);
    pntLdist=zeros(1,numPnt);
    
    numCtrlPnts=15;
    
    knots=zeros(1,nrbDeg+numCtrlPnts+1);
    knots((numCtrlPnts+1):end)=1;
    
    pntCrvPrms=zeros(1,numPnt);
    
    CP=zeros(4,numCtrlPnts);
    CP(4,:)=1;
    
    trimCRVS=cell(1,numCrv);
    
    allLines=true;
    
    if vdiff>6.28
        
        cnotclosed=false;
        
        relAnglDiff=0;
        anglMin=zeros(1,numCrv);
        anglMax=zeros(1,numCrv);
        
        for jj=1:numCrv
            
            PouterCrv=retSrfCrvPnt(2,ParameterData,1,ParameterData{bCptr}.de(jj),numPnt,3);
            
            for i=1:numPnt
                pntLdist(i)=norm(cross(ParameterData{srfind}.revolution.v,PouterCrv(:,i)-ParameterData{srfind}.revolution.p));
            end
            
            [maDist,iind]=max(pntLdist);
            
            P1=ParameterData{srfind}.revolution.R*PouterCrv(:,iind)+ParameterData{srfind}.revolution.T;
            angl(iind)=atan2(P1(2),P1(1));
            
            for i=(iind+1):numPnt
                if pntLdist(i)>maDist*1e-6
                    P1=ParameterData{srfind}.revolution.R*PouterCrv(:,i)+ParameterData{srfind}.revolution.T;
                    a1=atan2(P1(2),P1(1));
                    if a1-angl(i-1)>pi
                        angl(i)=a1-2*pi;
                    elseif a1-angl(i-1)<-pi
                        angl(i)=a1+2*pi;
                    else
                        angl(i)=a1;
                    end
                else
                    angl(i)=angl(i-1);
                end
            end
            
            for i=(iind-1):-1:1
                if pntLdist(i)>maDist*1e-6
                    P1=ParameterData{srfind}.revolution.R*PouterCrv(:,i)+ParameterData{srfind}.revolution.T;
                    a1=atan2(P1(2),P1(1));
                    if a1-angl(i+1)>pi
                        angl(i)=a1-2*pi;
                    elseif a1-angl(i+1)<-pi
                        angl(i)=a1+2*pi;
                    else
                        angl(i)=a1;
                    end
                else
                    angl(i)=angl(i+1);
                end
            end
            
            if jj>1
                [~,iind]=min(abs([angl(1)-2*pi-anglEnd,angl(1)-anglEnd,angl(1)+2*pi-anglEnd]));
                relAnglDiff=relAnglDiff+angl(1)+(iind-2)*2*pi-anglEnd;
            end
            
            adiff=angl(numPnt)-angl(1);
            anglMin(jj)=relAnglDiff+min(angl)-angl(1);
            anglMax(jj)=relAnglDiff+max(angl)-angl(1);
            relAnglDiff=relAnglDiff+adiff;
            anglEnd=angl(numPnt);
            
        end
        
        a1=max(anglMax);
        a2=min(anglMin);
        adiff=(a1-a2)*1e-3;
        isAmax=anglMax>(a1-adiff);
        isAmin=anglMin<(a2+adiff);
        
    else
        cnotclosed=true;
    end
    
    for jj=1:numCrv
        
        PouterCrv=retSrfCrvPnt(2,ParameterData,1,ParameterData{bCptr}.de(jj),numPnt,3);
        planeConst(:)=ParameterData{srfind}.revolution.v'*PouterCrv;
        
        for i=1:numPnt
            pntLdist(i)=norm(cross(ParameterData{srfind}.revolution.v,PouterCrv(:,i)-ParameterData{srfind}.revolution.p));
            [~,iind]=min(abs(compDist-pntLdist(i))+2*abs(planeConstComp-planeConst(i)));
            cparams0(i)=ccpar(iind);
        end
        
        [maDist,iind]=max(pntLdist);
        
        [cPoints,UV(1,:)]=closestNrbLinePointIGES(ParameterData{srfind}.revolution.cnurbs,ParameterData{srfind}.revolution.dcnurbs,ParameterData{srfind}.revolution.d2cnurbs,cparams0,planeConst,ParameterData{srfind}.revolution.v);
        
        miC=min(miC,min(UV(1,:)));
        maC=max(maC,max(UV(1,:)));
        
        if cnotclosed
            
            P1=ParameterData{srfind}.revolution.R*PouterCrv(:,iind)+ParameterData{srfind}.revolution.T;
            PC=ParameterData{srfind}.revolution.R*cPoints(:,iind)+ParameterData{srfind}.revolution.T;
            
            a1=atan2(P1(2),P1(1));
            a2=atan2(PC(2),PC(1));
            adiff=a1-a2;
            
            while adiff<vmin-vdiffCh
                adiff=adiff+2*pi;
            end
            while adiff>vmax+vdiffCh
                adiff=adiff-2*pi;
            end
            
            angl(iind)=adiff;
            
            for i=(iind+1):numPnt
                if pntLdist(i)>maDist*1e-6
                    
                    P1=ParameterData{srfind}.revolution.R*PouterCrv(:,i)+ParameterData{srfind}.revolution.T;
                    PC=ParameterData{srfind}.revolution.R*cPoints(:,i)+ParameterData{srfind}.revolution.T;
                    
                    a1=atan2(P1(2),P1(1));
                    a2=atan2(PC(2),PC(1));
                    adiff=a1-a2;
                    
                    while adiff<vmin-vdiffCh
                        adiff=adiff+2*pi;
                    end
                    while adiff>vmax+vdiffCh
                        adiff=adiff-2*pi;
                    end
                    
                    if adiff-angl(i-1)>pi
                        angl(i)=adiff-2*pi;
                    elseif adiff-angl(i-1)<-pi
                        angl(i)=adiff+2*pi;
                    else
                        angl(i)=adiff;
                    end
                    
                else
                    angl(i)=angl(i-1);
                end
            end
            
            for i=(iind-1):-1:1
                if pntLdist(i)>maDist*1e-6
                    
                    P1=ParameterData{srfind}.revolution.R*PouterCrv(:,i)+ParameterData{srfind}.revolution.T;
                    PC=ParameterData{srfind}.revolution.R*cPoints(:,i)+ParameterData{srfind}.revolution.T;
                    
                    a1=atan2(P1(2),P1(1));
                    a2=atan2(PC(2),PC(1));
                    adiff=a1-a2;
                    
                    while adiff<vmin-vdiffCh
                        adiff=adiff+2*pi;
                    end
                    while adiff>vmax+vdiffCh
                        adiff=adiff-2*pi;
                    end
                    
                    if adiff-angl(i+1)>pi
                        angl(i)=adiff-2*pi;
                    elseif adiff-angl(i+1)<-pi
                        angl(i)=adiff+2*pi;
                    else
                        angl(i)=adiff;
                    end
                    
                else
                    angl(i)=angl(i+1);
                end
            end
            
        else
            
            P1=ParameterData{srfind}.revolution.R*PouterCrv(:,iind)+ParameterData{srfind}.revolution.T;
            PC=ParameterData{srfind}.revolution.R*cPoints(:,iind)+ParameterData{srfind}.revolution.T;
            
            a1=atan2(P1(2),P1(1));
            a2=atan2(PC(2),PC(1));
            adiff=a1-a2;
            
            while adiff<vmin-vdiffCh
                adiff=adiff+2*pi;
            end
            while adiff>vmax+vdiffCh
                adiff=adiff-2*pi;
            end
            
            if abs(adiff-vmin)<1e-5
                if isAmax(jj)
                    angl(iind)=adiff+2*pi;
                else
                    angl(iind)=adiff;
                end
            elseif abs(adiff-vmax)<1e-5
                if isAmin(jj)
                    angl(iind)=adiff-2*pi;
                else
                    angl(iind)=adiff;
                end
            else
                angl(iind)=adiff;
            end
            
            for i=(iind+1):numPnt
                if pntLdist(i)>maDist*1e-6
                    P1=ParameterData{srfind}.revolution.R*PouterCrv(:,i)+ParameterData{srfind}.revolution.T;
                    PC=ParameterData{srfind}.revolution.R*cPoints(:,i)+ParameterData{srfind}.revolution.T;
                    
                    a1=atan2(P1(2),P1(1));
                    a2=atan2(PC(2),PC(1));
                    adiff=a1-a2;
                    
                    while adiff<vmin-vdiffCh
                        adiff=adiff+2*pi;
                    end
                    while adiff>vmax+vdiffCh
                        adiff=adiff-2*pi;
                    end
                    
                    if adiff-angl(i-1)<-pi
                        angl(i)=adiff+2*pi;
                    elseif adiff-angl(i-1)>pi
                        angl(i)=adiff-2*pi;
                    else
                        angl(i)=adiff;
                    end
                else
                    angl(i)=angl(i-1);
                end
            end
            
            for i=(iind-1):-1:1
                if pntLdist(i)>maDist*1e-6
                    P1=ParameterData{srfind}.revolution.R*PouterCrv(:,i)+ParameterData{srfind}.revolution.T;
                    PC=ParameterData{srfind}.revolution.R*cPoints(:,i)+ParameterData{srfind}.revolution.T;
                    
                    a1=atan2(P1(2),P1(1));
                    a2=atan2(PC(2),PC(1));
                    adiff=a1-a2;
                    
                    while adiff<vmin-vdiffCh
                        adiff=adiff+2*pi;
                    end
                    while adiff>vmax+vdiffCh
                        adiff=adiff-2*pi;
                    end
                    
                    if adiff-angl(i+1)<-pi
                        angl(i)=adiff+2*pi;
                    elseif adiff-angl(i+1)>pi
                        angl(i)=adiff-2*pi;
                    else
                        angl(i)=adiff;
                    end
                else
                    angl(i)=angl(i+1);
                end
            end
            
            if isAmax(jj)
                if anglMax(jj)-anglMin(jj)>1e-3
                    a2=max(angl);
                    if a2>vmax+vdiffCh
                        a1=min(angl);
                        if a1>vmax-vdiffCh
                            a1=a1-2*pi;
                            if a1>vmin-vdiffCh
                                if a2-vmax>vmin-a1
                                    angl=angl-2*pi;
                                end
                            end
                        end
                    end
                elseif isAmin(jj)
                    a1=min(angl)-2*pi;
                    if a1>vmin-vdiffCh
                        a2=max(angl);
                        if a2-vmax>vmin-a1
                            angl=angl-2*pi;
                        end
                    end
                end
            end
            if isAmin(jj)
                if anglMax(jj)-anglMin(jj)>1e-3
                    a1=min(angl);
                    if a1<vmin-vdiffCh
                        a2=max(angl);
                        if a2<vmin+vdiffCh
                            a2=a2+2*pi;
                            if a2<vmax+vdiffCh
                                if vmin-a1>a2-vmax
                                    angl=angl+2*pi;
                                end
                            end
                        end
                    end
                elseif isAmax(jj)
                    a2=max(angl)+2*pi;
                    if a2<vmax+vdiffCh
                        a1=min(angl);
                        if vmin-a1>a2-vmax
                            angl=angl+2*pi;
                        end
                    end
                end
            end
            
        end
        
        miA=min(miA,min(angl));
        maA=max(maA,max(angl));
        
        rPoints(1,:)=cos(angl);
        rPoints(2,:)=sin(angl);
        
        [~,UV(2,:)]=closestNrbLinePointIGES(ParameterData{srfind}.revolution.rnurbs,ParameterData{srfind}.revolution.drnurbs,ParameterData{srfind}.revolution.d2rnurbs,angl,rPoints);
        
        miR=min(miR,min(UV(2,:)));
        maR=max(maR,max(UV(2,:)));
        
        meaUV=mean(UV,2);
        
        singVals=svd(UV*UV'-(numPnt*meaUV)*meaUV');
        
        if 1e6*singVals(2)<singVals(1)
            
            trimCRVS{jj}.type=110;
            
            trimCRVS{jj}.name='LINE';
            trimCRVS{jj}.original=0;
            
            trimCRVS{jj}.superior=1;
            
            trimCRVS{jj}.form=0;
            
            trimCRVS{jj}.p1=[UV(:,1);0];
            trimCRVS{jj}.x1=UV(1,1);
            trimCRVS{jj}.y1=UV(2,1);
            trimCRVS{jj}.z1=0;
            
            trimCRVS{jj}.p2=[UV(:,numPnt);0];
            trimCRVS{jj}.x2=UV(1,numPnt);
            trimCRVS{jj}.y2=UV(2,numPnt);
            trimCRVS{jj}.z2=0;
            
            trimCRVS{jj}.length=0;
            
            trimCRVS{jj}.evalmthd=0;
            
            trimCRVS{jj}.well=true;
            
        else
            
            allLines=false;
            
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
            
            CP(1:2,1)=UV(:,1);
            CP(1:2,numCtrlPnts)=UV(:,numPnt);
            CP(1:2,2:(numCtrlPnts-1))=(NTN\R)';
            
            trimCRVS{jj}.type=126;
            trimCRVS{jj}.name='B-NURBS CRV';
            trimCRVS{jj}.original=0;
            trimCRVS{jj}.superior=1;
            trimCRVS{jj}.k=numCtrlPnts-1;
            trimCRVS{jj}.m=nrbDeg;
            
            trimCRVS{jj}.prop1=1;
            trimCRVS{jj}.prop2=1;
            trimCRVS{jj}.prop3=1;
            trimCRVS{jj}.prop4=1;
            
            trimCRVS{jj}.t=knots;
            trimCRVS{jj}.w=CP(4,:);
            trimCRVS{jj}.p=CP(1:3,:);
            
            trimCRVS{jj}.v=[0,1];
            
            trimCRVS{jj}.xnorm=0;
            trimCRVS{jj}.ynorm=0;
            trimCRVS{jj}.znorm=1;
            
            trimCRVS{jj}.nurbs.form='B-NURBS';
            trimCRVS{jj}.nurbs.dim=4;
            trimCRVS{jj}.nurbs.number=numCtrlPnts;
            trimCRVS{jj}.nurbs.coefs=CP;
            trimCRVS{jj}.nurbs.order=nrbDeg+1;
            trimCRVS{jj}.nurbs.knots=knots;
            
            [trimCRVS{jj}.dnurbs,trimCRVS{jj}.d2nurbs]=nrbDerivativesIGES(trimCRVS{jj}.nurbs);
            
            trimCRVS{jj}.length=0;
            
            trimCRVS{jj}.evalmthd=0;
            
            trimCRVS{jj}.well=true;
            
        end
        
    end
    
else
    
    numPnt=451;
    numCrv=1;
    
    angl=zeros(1,numPnt);
    cparams0=zeros(1,numPnt);
    UV=zeros(2,numPnt);
    rPoints=zeros(3,numPnt);
    
    pntLdist=zeros(1,numPnt);
    
    numCtrlPnts=30;
    
    knots=zeros(1,nrbDeg+numCtrlPnts+1);
    knots((numCtrlPnts+1):end)=1;
    
    pntCrvPrms=zeros(1,numPnt);
    
    CP=zeros(4,numCtrlPnts);
    CP(4,:)=1;
    
    trimCRVS=cell(1,numCrv);
    
    PouterCrv=retSrfCrvPnt(2,ParameterData,1,bCptr,numPnt,3);
    planeConst=ParameterData{srfind}.revolution.v'*PouterCrv;
    
    for i=1:numPnt
        pntLdist(i)=norm(cross(ParameterData{srfind}.revolution.v,PouterCrv(:,i)-ParameterData{srfind}.revolution.p));
        [~,iind]=min(abs(compDist-pntLdist(i))+2*abs(planeConstComp-planeConst(i)));
        cparams0(i)=ccpar(iind);
    end
    
    [maDist,iind]=max(pntLdist);
    
    [cPoints,UV(1,:)]=closestNrbLinePointIGES(ParameterData{srfind}.revolution.cnurbs,ParameterData{srfind}.revolution.dcnurbs,ParameterData{srfind}.revolution.d2cnurbs,cparams0,planeConst,ParameterData{srfind}.revolution.v);
    
    miC=min(miC,min(UV(1,:)));
    maC=max(maC,max(UV(1,:)));
    
    
    P1=ParameterData{srfind}.revolution.R*PouterCrv(:,iind)+ParameterData{srfind}.revolution.T;
    PC=ParameterData{srfind}.revolution.R*cPoints(:,iind)+ParameterData{srfind}.revolution.T;
    
    a1=atan2(P1(2),P1(1));
    a2=atan2(PC(2),PC(1));
    adiff=a1-a2;
    
    while adiff<vmin-vdiffCh
        adiff=adiff+2*pi;
    end
    while adiff>vmax+vdiffCh
        adiff=adiff-2*pi;
    end
    
    angl(iind)=adiff;
    
    for i=(iind+1):numPnt
        if pntLdist(i)>maDist*1e-6
            
            P1=ParameterData{srfind}.revolution.R*PouterCrv(:,i)+ParameterData{srfind}.revolution.T;
            PC=ParameterData{srfind}.revolution.R*cPoints(:,i)+ParameterData{srfind}.revolution.T;
            
            a1=atan2(P1(2),P1(1));
            a2=atan2(PC(2),PC(1));
            adiff=a1-a2;
            
            while adiff<vmin-vdiffCh
                adiff=adiff+2*pi;
            end
            while adiff>vmax+vdiffCh
                adiff=adiff-2*pi;
            end
            
            if adiff-angl(i-1)>pi
                angl(i)=adiff-2*pi;
            elseif adiff-angl(i-1)<-pi
                angl(i)=adiff+2*pi;
            else
                angl(i)=adiff;
            end
            
        else
            angl(i)=angl(i-1);
        end
    end
    
    for i=(iind-1):-1:1
        if pntLdist(i)>maDist*1e-6
            
            P1=ParameterData{srfind}.revolution.R*PouterCrv(:,i)+ParameterData{srfind}.revolution.T;
            PC=ParameterData{srfind}.revolution.R*cPoints(:,i)+ParameterData{srfind}.revolution.T;
            
            a1=atan2(P1(2),P1(1));
            a2=atan2(PC(2),PC(1));
            adiff=a1-a2;
            
            while adiff<vmin-vdiffCh
                adiff=adiff+2*pi;
            end
            while adiff>vmax+vdiffCh
                adiff=adiff-2*pi;
            end
            
            if adiff-angl(i+1)>pi
                angl(i)=adiff-2*pi;
            elseif adiff-angl(i+1)<-pi
                angl(i)=adiff+2*pi;
            else
                angl(i)=adiff;
            end
            
        else
            angl(i)=angl(i+1);
        end
    end
    
    miA=min(miA,min(angl));
    maA=max(maA,max(angl));
    
    rPoints(1,:)=cos(angl);
    rPoints(2,:)=sin(angl);
    
    [~,UV(2,:)]=closestNrbLinePointIGES(ParameterData{srfind}.revolution.rnurbs,ParameterData{srfind}.revolution.drnurbs,ParameterData{srfind}.revolution.d2rnurbs,angl,rPoints);
    
    miR=min(miR,min(UV(2,:)));
    maR=max(maR,max(UV(2,:)));
    
    allLines=false;
    
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
    
    CP(1:2,1)=UV(:,1);
    CP(1:2,numCtrlPnts)=UV(:,numPnt);
    CP(1:2,2:(numCtrlPnts-1))=(NTN\R)';
    
    trimCRVS{1}.type=126;
    trimCRVS{1}.name='B-NURBS CRV';
    trimCRVS{1}.original=0;
    trimCRVS{1}.superior=1;
    trimCRVS{1}.k=numCtrlPnts-1;
    trimCRVS{1}.m=nrbDeg;
    
    trimCRVS{1}.prop1=1;
    trimCRVS{1}.prop2=1;
    trimCRVS{1}.prop3=1;
    trimCRVS{1}.prop4=1;
    
    trimCRVS{1}.t=knots;
    trimCRVS{1}.w=CP(4,:);
    trimCRVS{1}.p=CP(1:3,:);
    
    trimCRVS{1}.v=[0,1];
    
    trimCRVS{1}.xnorm=0;
    trimCRVS{1}.ynorm=0;
    trimCRVS{1}.znorm=1;
    
    trimCRVS{1}.nurbs.form='B-NURBS';
    trimCRVS{1}.nurbs.dim=4;
    trimCRVS{1}.nurbs.number=numCtrlPnts;
    trimCRVS{1}.nurbs.coefs=CP;
    trimCRVS{1}.nurbs.order=nrbDeg+1;
    trimCRVS{1}.nurbs.knots=knots;
    
    [trimCRVS{1}.dnurbs,trimCRVS{1}.d2nurbs]=nrbDerivativesIGES(trimCRVS{1}.nurbs);
    
    trimCRVS{1}.length=0;
    
    trimCRVS{1}.evalmthd=0;
    
    trimCRVS{1}.well=true;
    
end

anglInterval=[miA,maA];
cInterval=[miC,maC];
aInterval=[miR,maR];

dC=maC-miC;
dA=maR-miR;

if allLines
    
    domainIsRectangle=true;
    
    for jj=1:numCrv
        
        if and(abs(trimCRVS{jj}.x2-trimCRVS{jj}.x1)>dC*1e-4,abs(trimCRVS{jj}.y2-trimCRVS{jj}.y1)>dA*1e-4)
            domainIsRectangle=false;
            break
        elseif and(and((trimCRVS{jj}.x1-cInterval(1))>dC*1e-4,(cInterval(2)-trimCRVS{jj}.x1)>dC*1e-4),and((trimCRVS{jj}.y1-aInterval(1))>dA*1e-4,(aInterval(2)-trimCRVS{jj}.y1)>dA*1e-4))
            domainIsRectangle=false;
            break
        elseif and(and((trimCRVS{jj}.x2-cInterval(1))>dC*1e-4,(cInterval(2)-trimCRVS{jj}.x2)>dC*1e-4),and((trimCRVS{jj}.y2-aInterval(1))>dA*1e-4,(aInterval(2)-trimCRVS{jj}.y2)>dA*1e-4))
            domainIsRectangle=false;
            break
        end
        
    end
    
else
    
    domainIsRectangle=false;
    
end


function [trimCRVS,uInterval,vInterval,numCrv,allLines,domainIsRectangle]=findBoundaryInNURBSParameterSpace(ParameterData,ind,bCptr)

entiall=ParameterData{ind}.pts;

nu=150;
nv=150;
[Pcomp,UVcomp]=nrbSrfRegularEvalIGES(ParameterData{entiall}.nurbs,ParameterData{entiall}.u(1),ParameterData{entiall}.u(2),nu,ParameterData{entiall}.v(1),ParameterData{entiall}.v(2),nv);

uInterval=[ParameterData{entiall}.u(2),ParameterData{entiall}.u(1)];
vInterval=[ParameterData{entiall}.v(2),ParameterData{entiall}.v(1)];

dU=abs(uInterval(2)-uInterval(1));
dV=abs(vInterval(2)-vInterval(1));
pspaceD=dU^2+dV^2;

numSplineVal=20;
splinePnts=zeros(2,numSplineVal);

nrbDeg=2;

if ParameterData{bCptr}.type==102
    
    numCrv=ParameterData{bCptr}.n;
    
    trimCRVS=cell(1,numCrv);
    
    numPnt=501;
    
    UV0=zeros(2,numPnt);
    PouterCrv=zeros(3,numPnt);
    
    numCtrlPnts=30;
    
    knots=zeros(1,nrbDeg+numCtrlPnts+1);
    knots((numCtrlPnts+1):end)=1;
    
    pntCrvPrms=zeros(1,numPnt);
    
    CP=zeros(4,numCtrlPnts);
    CP(4,:)=1;
    
    allLines=true;
    
    for jj=1:numCrv
        
        PouterCrv(:,:)=retSrfCrvPnt(2,ParameterData,1,ParameterData{bCptr}.de(jj),numPnt,3);
        
        for j=1:numPnt
            [~,miind]=min((Pcomp(1,:)-PouterCrv(1,j)).^2+(Pcomp(2,:)-PouterCrv(2,j)).^2+(Pcomp(3,:)-PouterCrv(3,j)).^2);
            UV0(:,j)=UVcomp(:,miind);
        end
        
        [~,UV]=closestNrbLinePointIGES(ParameterData{entiall}.nurbs,ParameterData{entiall}.dnurbs,ParameterData{entiall}.d2nurbs,UV0,PouterCrv);
        
        uInterval(1)=min(uInterval(1),min(UV(1,:)));
        uInterval(2)=max(uInterval(2),max(UV(1,:)));
        
        vInterval(1)=min(vInterval(1),min(UV(2,:)));
        vInterval(2)=max(vInterval(2),max(UV(2,:)));
        
        meaUV=mean(UV,2);
        
        singVals=svd(UV*UV'-(numPnt*meaUV)*meaUV');
        
        if or(1e6*singVals(2)<singVals(1),1e6*singVals(1)<pspaceD)
            
            trimCRVS{jj}.type=110;
            
            trimCRVS{jj}.name='LINE';
            trimCRVS{jj}.original=0;
            
            trimCRVS{jj}.superior=1;
            
            trimCRVS{jj}.form=0;
            
            trimCRVS{jj}.p1=[UV(:,1);0];
            trimCRVS{jj}.x1=UV(1,1);
            trimCRVS{jj}.y1=UV(2,1);
            trimCRVS{jj}.z1=0;
            
            trimCRVS{jj}.p2=[UV(:,numPnt);0];
            trimCRVS{jj}.x2=UV(1,numPnt);
            trimCRVS{jj}.y2=UV(2,numPnt);
            trimCRVS{jj}.z2=0;
            
            trimCRVS{jj}.length=0;
            
            trimCRVS{jj}.evalmthd=0;
            
            trimCRVS{jj}.well=true;
            
        else
            
            allLines=false;
            
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
            
            CP(1:2,1)=UV(:,1);
            CP(1:2,numCtrlPnts)=UV(:,numPnt);
            CP(1:2,2:(numCtrlPnts-1))=(NTN\R)';
            
            trimCRVS{jj}.type=126;
            trimCRVS{jj}.name='B-NURBS CRV';
            trimCRVS{jj}.original=0;
            trimCRVS{jj}.superior=1;
            trimCRVS{jj}.k=numCtrlPnts-1;
            trimCRVS{jj}.m=nrbDeg;
            
            trimCRVS{jj}.prop1=1;
            trimCRVS{jj}.prop2=1;
            trimCRVS{jj}.prop3=1;
            trimCRVS{jj}.prop4=1;
            
            trimCRVS{jj}.t=knots;
            trimCRVS{jj}.w=CP(4,:);
            trimCRVS{jj}.p=CP(1:3,:);
            
            trimCRVS{jj}.v=[0,1];
            
            trimCRVS{jj}.xnorm=0;
            trimCRVS{jj}.ynorm=0;
            trimCRVS{jj}.znorm=1;
            
            trimCRVS{jj}.nurbs.form='B-NURBS';
            trimCRVS{jj}.nurbs.dim=4;
            trimCRVS{jj}.nurbs.number=numCtrlPnts;
            trimCRVS{jj}.nurbs.coefs=CP;
            trimCRVS{jj}.nurbs.order=nrbDeg+1;
            trimCRVS{jj}.nurbs.knots=knots;
            
            [trimCRVS{jj}.dnurbs,trimCRVS{jj}.d2nurbs]=nrbDerivativesIGES(trimCRVS{jj}.nurbs);
            
            trimCRVS{jj}.length=0;
            
            trimCRVS{jj}.evalmthd=0;
            
            trimCRVS{jj}.well=true;
            
        end
        
    end
    
else
    
    numCrv=1;
    trimCRVS=cell(1,numCrv);
    
    numPnt=1001;
    
    UV0=zeros(2,numPnt);
    PouterCrv=zeros(3,numPnt);
    
    numCtrlPnts=75;
    
    knots=zeros(1,nrbDeg+numCtrlPnts+1);
    knots((numCtrlPnts+1):end)=1;
    
    pntCrvPrms=zeros(1,numPnt);
    
    CP=zeros(4,numCtrlPnts);
    CP(4,:)=1;
    
    allLines=false;
    
    PouterCrv(:,:)=retSrfCrvPnt(2,ParameterData,1,bCptr,numPnt,3);
    
    for j=1:numPnt
        [~,miind]=min((Pcomp(1,:)-PouterCrv(1,j)).^2+(Pcomp(2,:)-PouterCrv(2,j)).^2+(Pcomp(3,:)-PouterCrv(3,j)).^2);
        UV0(:,j)=UVcomp(:,miind);
    end
    
    [~,UV]=closestNrbLinePointIGES(ParameterData{entiall}.nurbs,ParameterData{entiall}.dnurbs,ParameterData{entiall}.d2nurbs,UV0,PouterCrv);
    
    uInterval(1)=min(uInterval(1),min(UV(1,:)));
    uInterval(2)=max(uInterval(2),max(UV(1,:)));
    
    vInterval(1)=min(vInterval(1),min(UV(2,:)));
    vInterval(2)=max(vInterval(2),max(UV(2,:)));
    
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
    
    CP(1:2,1)=UV(:,1);
    CP(1:2,numCtrlPnts)=UV(:,numPnt);
    CP(1:2,2:(numCtrlPnts-1))=(NTN\R)';
    
    trimCRVS{1}.type=126;
    trimCRVS{1}.name='B-NURBS CRV';
    trimCRVS{1}.original=0;
    trimCRVS{1}.superior=1;
    trimCRVS{1}.k=numCtrlPnts-1;
    trimCRVS{1}.m=nrbDeg;
    
    trimCRVS{1}.prop1=1;
    trimCRVS{1}.prop2=1;
    trimCRVS{1}.prop3=1;
    trimCRVS{1}.prop4=1;
    
    trimCRVS{1}.t=knots;
    trimCRVS{1}.w=CP(4,:);
    trimCRVS{1}.p=CP(1:3,:);
    
    trimCRVS{1}.v=[0,1];
    
    trimCRVS{1}.xnorm=0;
    trimCRVS{1}.ynorm=0;
    trimCRVS{1}.znorm=1;
    
    trimCRVS{1}.nurbs.form='B-NURBS';
    trimCRVS{1}.nurbs.dim=4;
    trimCRVS{1}.nurbs.number=numCtrlPnts;
    trimCRVS{1}.nurbs.coefs=CP;
    trimCRVS{1}.nurbs.order=nrbDeg+1;
    trimCRVS{1}.nurbs.knots=knots;
    
    [trimCRVS{1}.dnurbs,trimCRVS{1}.d2nurbs]=nrbDerivativesIGES(trimCRVS{1}.nurbs);
    
    trimCRVS{1}.length=0;
    
    trimCRVS{1}.evalmthd=0;
    
    trimCRVS{1}.well=true;
    
end

if allLines
    
    domainIsRectangle=true;
    
    for jj=1:numCrv
        
        if and(abs(trimCRVS{jj}.x2-trimCRVS{jj}.x1)>1e-4*dU,abs(trimCRVS{jj}.y2-trimCRVS{jj}.y1)>1e-4*dV)
            domainIsRectangle=false;
            break
        elseif and(and((trimCRVS{jj}.x1-uInterval(1))>1e-4*dU,(uInterval(2)-trimCRVS{jj}.x1)>1e-4*dU),and((trimCRVS{jj}.y1-vInterval(1))>1e-4*dV,(vInterval(2)-trimCRVS{jj}.y1)>1e-4*dV))
            domainIsRectangle=false;
            break
        elseif and(and((trimCRVS{jj}.x2-uInterval(1))>1e-4*dU,(uInterval(2)-trimCRVS{jj}.x2)>1e-4*dU),and((trimCRVS{jj}.y2-vInterval(1))>1e-4*dV,(vInterval(2)-trimCRVS{jj}.y2)>1e-4*dV))
            domainIsRectangle=false;
            break
        end
        
    end
    
else
    
    domainIsRectangle=false;
    
end

% Recursive define function

function ParameterData=unDoSupMkC(ParameterData,ii)

if ParameterData{ii}.type==126
    ParameterData{ii}.superior=0;
elseif ParameterData{ii}.type==110
    ParameterData{ii}.superior=0;
elseif ParameterData{ii}.type==102
    for k=1:ParameterData{ii}.n
        ParameterData=unDoSupMkC(ParameterData,ParameterData{ii}.de(k));
    end
elseif ParameterData{ii}.type==141
    for k=1:ParameterData{ii}.n
        ParameterData=unDoSupMkC(ParameterData,ParameterData{ii}.crvpt(k));
        %ParameterData=makeContinous(ParameterData,ParameterData{ii}.crvpt(k));
    end
    %ParameterData=makeContinous(ParameterData,ii);
elseif ParameterData{ii}.type==142
    % only cptr, not bptr
    ParameterData=unDoSupMkC(ParameterData,ParameterData{ii}.cptr);
    
    ParameterData=makeContinous(ParameterData,ParameterData{ii}.bptr);
    ParameterData=makeContinous(ParameterData,ParameterData{ii}.cptr);
end


function ParameterData=makeContinous(ParameterData,ii)

if ii>0
    
    if ParameterData{ii}.type==102
        
        allLines=false;
        
        if ParameterData{ii}.n>1
            
            [stPp,endPp,isLine,isKnown]=endPoints(ParameterData,ParameterData{ii}.de(1));
            if isKnown
                allLines=isLine;
                [stP,endP,isLine,isKnown]=endPoints(ParameterData,ParameterData{ii}.de(2));
                if isKnown
                    if allLines
                        allLines=isLine;
                    end
                    
                    [~,miind]=min([norm(stP-endPp),norm(endP-endPp),norm(stP-stPp),norm(endP-stPp)]);
                    
                    switch miind
                        case 1
                            endPp=endP;
                        case 2
                            ParameterData=mkreverse(ParameterData,ParameterData{ii}.de(2));
                            endPp=stP;
                        case 3
                            ParameterData=mkreverse(ParameterData,ParameterData{ii}.de(1));
                            endPp=endP;
                        case 4
                            ParameterData=mkreverse(ParameterData,ParameterData{ii}.de(1));
                            ParameterData=mkreverse(ParameterData,ParameterData{ii}.de(2));
                            endPp=stP;
                    end
                    
                    for k=3:ParameterData{ii}.n
                        [stP,endP,isLine,isKnown]=endPoints(ParameterData,ParameterData{ii}.de(k));
                        if allLines
                            allLines=isLine;
                        end
                        if isKnown
                            if norm(endP-endPp)<norm(stP-endPp)
                                ParameterData=mkreverse(ParameterData,ParameterData{ii}.de(k));
                                endPp=stP;
                            else
                                endPp=endP;
                            end
                        else
                            allLines=false;
                            break
                        end
                    end
                    
                else
                    allLines=false;
                end
                
            end
            
        end
        
        ParameterData{ii}.allLines=allLines;
        
    end
    
end

function [stP,endP,isLine,isKnown]=endPoints(ParameterData,ii)

if ParameterData{ii}.type==126
    stP=nrbevalIGES(ParameterData{ii}.nurbs,ParameterData{ii}.v(1));
    endP=nrbevalIGES(ParameterData{ii}.nurbs,ParameterData{ii}.v(2));
    isLine=false;
    isKnown=true;
elseif ParameterData{ii}.type==110
    stP=ParameterData{ii}.p1;
    endP=ParameterData{ii}.p2;
    isLine=true;
    isKnown=true;
else
    stP=[0;0;0];
    endP=[0;0;0];
    isLine=false;
    isKnown=false;
end


function ParameterData=mkreverse(ParameterData,ii)

if ParameterData{ii}.type==110
    
    p1=[ParameterData{ii}.x1;ParameterData{ii}.y1;ParameterData{ii}.z1];
    p2=[ParameterData{ii}.x2;ParameterData{ii}.y2;ParameterData{ii}.z2];
    
    ParameterData{ii}.p1=p2;
    ParameterData{ii}.p2=p1;
    
    ParameterData{ii}.x1=p2(1);
    ParameterData{ii}.y1=p2(2);
    ParameterData{ii}.z1=p2(3);
    
    ParameterData{ii}.x2=p1(1);
    ParameterData{ii}.y2=p1(2);
    ParameterData{ii}.z2=p1(3);
    
elseif ParameterData{ii}.type==126
    
    tsum=ParameterData{ii}.t(1)+ParameterData{ii}.t(end);
    
    t=tsum-ParameterData{ii}.t;
    
    ParameterData{ii}.t=t(end:(-1):1);
    ParameterData{ii}.w=ParameterData{ii}.w(end:(-1):1);
    ParameterData{ii}.p=ParameterData{ii}.p(:,end:(-1):1);
    
    ParameterData{ii}.v=[tsum-ParameterData{ii}.v(2) tsum-ParameterData{ii}.v(1)];
    
    ParameterData{ii}.nurbs.coefs=ParameterData{ii}.nurbs.coefs(:,end:(-1):1);
    
    ParameterData{ii}.nurbs.knots=ParameterData{ii}.t;
    
elseif ParameterData{ii}.type==102
    
    de=ParameterData{ii}.de;
    for k=1:ParameterData{ii}.n
        ParameterData{ii}.de(k)=de(ParameterData{ii}.n+1-k);
        ParameterData=mkreverse(ParameterData,ParameterData{ii}.de(k));
    end
    
elseif ParameterData{ii}.type==142
    
    ParameterData=mkreverse(ParameterData,ParameterData{ii}.bptr);
    ParameterData=mkreverse(ParameterData,ParameterData{ii}.cptr);
    
end


function [spline2BezierCrvMat,spline2BezierSrfMat]=matrixSpline2Bezier()

basisMat=zeros(4);

basisMat(1,1)=1;
basisMat(2,1)=-3;
basisMat(3,1)=3;
basisMat(4,1)=-1;
basisMat(1,2)=0;
basisMat(2,2)=3;
basisMat(3,2)=-6;
basisMat(4,2)=3;
basisMat(1,3)=0;
basisMat(2,3)=0;
basisMat(3,3)=3;
basisMat(4,3)=-3;
basisMat(1,4)=0;
basisMat(2,4)=0;
basisMat(3,4)=0;
basisMat(4,4)=1;

spline2BezierCrvMat=inv(basisMat');

A=zeros(16);

row=0;
for j=1:4
    for i=1:4
        row=row+1;
        col=0;
        for jj=1:4
            for ii=1:4
                col=col+1;
                if row<=col
                    A(row,col)=basisMat(ii,i)*basisMat(jj,j);
                end
            end
        end
    end
end

spline2BezierSrfMat=inv(A);


function [ParameterData,le,numcrv]=retPsCrvLength(srfind,ParameterData,ind,n)

if ParameterData{ind}.type==142
    
    ind0=ind;
    
    ind=ParameterData{ind}.bptr;
    
    if ParameterData{ind}.type==102
        le=0;
        numcrv=0;
        for i=1:(ParameterData{ind}.n)
            if ParameterData{ParameterData{ind}.de(i)}.type==126
                [~,le2,evmethd]=crvPntsSrfNURBS(n,ParameterData{srfind}.nurbs,ParameterData{ParameterData{ind}.de(i)}.nurbs,ParameterData{ParameterData{ind}.de(i)}.v(1),ParameterData{ParameterData{ind}.de(i)}.v(2));
                ParameterData{ParameterData{ind}.de(i)}.length=le2;
                ParameterData{ParameterData{ind}.de(i)}.evalmthd=evmethd;
                numcrv2=1;
            elseif ParameterData{ParameterData{ind}.de(i)}.type==110
                [~,le2,evmethd]=crvPntsSrfNURBS(n,ParameterData{srfind}.nurbs,ParameterData{ParameterData{ind}.de(i)}.p1,ParameterData{ParameterData{ind}.de(i)}.p2);
                ParameterData{ParameterData{ind}.de(i)}.length=le2;
                ParameterData{ParameterData{ind}.de(i)}.evalmthd=evmethd;
                numcrv2=1;
            else
                [ParameterData,le2,numcrv2]=retPsCrvLength(srfind,ParameterData,ParameterData{ind}.de(i),n);
            end
            ParameterData{ind}.lengthcnt(i)=le2;
            ParameterData{ind}.numcrvcnt(i)=numcrv2;
            le=le+le2;
            numcrv=numcrv+numcrv2;
        end
    elseif ParameterData{ind}.type==126
        [~,le,evmethd]=crvPntsSrfNURBS(n,ParameterData{srfind}.nurbs,ParameterData{ind}.nurbs,ParameterData{ind}.v(1),ParameterData{ind}.v(2));
        ParameterData{ind}.evalmthd=evmethd;
        numcrv=1;
    else
        [ParameterData,le,numcrv]=retPsCrvLength(srfind,ParameterData,ind,n);
    end
    
    ParameterData{ind}.length=le;
    ParameterData{ind}.numcrv=numcrv;
    ParameterData{ind0}.length=le;
    ParameterData{ind0}.numcrv=numcrv;
    
elseif ParameterData{ind}.type==141
    
    le=0;
    numcrv=0;
    for i=1:ParameterData{ind}.n
        le2=0;
        numcrv2=0;
        for j=1:ParameterData{ind}.k(i)
            if ParameterData{ParameterData{ind}.pscpt{i}(j)}.type==126
                [~,le3,evmethd]=crvPntsSrfNURBS(n,ParameterData{srfind}.nurbs,ParameterData{ParameterData{ind}.pscpt{i}(j)}.nurbs,ParameterData{ParameterData{ind}.pscpt{i}(j)}.v(1),ParameterData{ParameterData{ind}.pscpt{i}(j)}.v(2));
                ParameterData{ParameterData{ind}.pscpt{i}(j)}.length=le3;
                ParameterData{ParameterData{ind}.pscpt{i}(j)}.evalmthd=evmethd;
                numcrv3=1;
            elseif ParameterData{ParameterData{ind}.pscpt{i}(j)}.type==110
                [~,le3,evmethd]=crvPntsSrfNURBS(n,ParameterData{srfind}.nurbs,ParameterData{ParameterData{ind}.pscpt{i}(j)}.p1,ParameterData{ParameterData{ind}.pscpt{i}(j)}.p2);
                ParameterData{ParameterData{ind}.pscpt{i}(j)}.length=le3;
                ParameterData{ParameterData{ind}.pscpt{i}(j)}.evalmthd=evmethd;
                numcrv3=1;
            else
                [ParameterData,le3,numcrv3]=retPsCrvLength(srfind,ParameterData,ParameterData{ind}.pscpt{i}(j),n);
            end
            ParameterData{ind}.pscclctnlength{i}(j)=le3;
            ParameterData{ind}.numpscrvc{i}(j)=numcrv3;
            le2=le2+le3;
            numcrv2=numcrv2+numcrv3;
        end
        ParameterData{ind}.psclength(i)=le2;
        ParameterData{ind}.numpscrv(i)=numcrv2;
        le=le+le2;
        numcrv=numcrv+numcrv2;
    end
    ParameterData{ind}.length=le;
    ParameterData{ind}.numcrv=numcrv;
    
elseif ParameterData{ind}.type==102
    
    le=0;
    numcrv=0;
    for i=1:(ParameterData{ind}.n)
        if ParameterData{ParameterData{ind}.de(i)}.type==126
            [~,le2,evmethd]=crvPntsSrfNURBS(n,ParameterData{srfind}.nurbs,ParameterData{ParameterData{ind}.de(i)}.nurbs,ParameterData{ParameterData{ind}.de(i)}.v(1),ParameterData{ParameterData{ind}.de(i)}.v(2));
            ParameterData{ParameterData{ind}.de(i)}.length=le2;
            ParameterData{ParameterData{ind}.de(i)}.evalmthd=evmethd;
            numcrv2=1;
        elseif ParameterData{ParameterData{ind}.de(i)}.type==110
            [~,le2,evmethd]=crvPntsSrfNURBS(n,ParameterData{srfind}.nurbs,ParameterData{ParameterData{ind}.de(i)}.p1,ParameterData{ParameterData{ind}.de(i)}.p2);
            ParameterData{ParameterData{ind}.de(i)}.length=le2;
            ParameterData{ParameterData{ind}.de(i)}.evalmthd=evmethd;
            numcrv2=1;
        else
            [ParameterData,le2,numcrv2]=retPsCrvLength(srfind,ParameterData,ParameterData{ind}.de(i),n);
        end
        ParameterData{ind}.lengthcnt(i)=le2;
        ParameterData{ind}.numcrvcnt(i)=numcrv2;
        le=le+le2;
        numcrv=numcrv+numcrv2;
    end
    ParameterData{ind}.length=le;
    ParameterData{ind}.numcrv=numcrv;
    
elseif ParameterData{ind}.type==126
    
    [~,le,evmethd]=crvPntsSrfNURBS(n,ParameterData{srfind}.nurbs,ParameterData{ind}.nurbs,ParameterData{ind}.v(1),ParameterData{ind}.v(2));
    ParameterData{ind}.length=le;
    ParameterData{ind}.evalmthd=evmethd;
    numcrv=1;
    
elseif ParameterData{ind}.type==110
    
    [~,le,evmethd]=crvPntsSrfNURBS(n,ParameterData{srfind}.nurbs,ParameterData{ind}.p1,ParameterData{ind}.p2);
    ParameterData{ind}.length=le;
    ParameterData{ind}.evalmthd=evmethd;
    numcrv=1;
    
else
    
    le=0;
    numcrv=0;
    
end


function [ParameterData,le,numcrv]=retMsCrvLength(ParameterData,ind,n)

if ParameterData{ind}.type==142
    
    ind=ParameterData{ind}.cptr;
    
    if ParameterData{ind}.type==102
        le=0;
        numcrv=0;
        for i=1:(ParameterData{ind}.n)
            if ParameterData{ParameterData{ind}.de(i)}.type==126
                [~,le2,evmethd]=crvPntsSrfNURBS(n,ParameterData{ParameterData{ind}.de(i)}.nurbs,ParameterData{ParameterData{ind}.de(i)}.v(1),ParameterData{ParameterData{ind}.de(i)}.v(2));
                ParameterData{ParameterData{ind}.de(i)}.length=le2;
                ParameterData{ParameterData{ind}.de(i)}.evalmthd=evmethd;
                numcrv2=1;
            elseif ParameterData{ParameterData{ind}.de(i)}.type==110
                [~,le2,~]=crvPntsSrfNURBS(1,ParameterData{ParameterData{ind}.de(i)}.p1,ParameterData{ParameterData{ind}.de(i)}.p2);
                ParameterData{ParameterData{ind}.de(i)}.length=le2;
                numcrv2=1;
            else
                [ParameterData,le2,numcrv2]=retMsCrvLength(ParameterData,ParameterData{ind}.de(i),n);
            end
            ParameterData{ind}.lengthcnt(i)=le2;
            ParameterData{ind}.numcrvcnt(i)=numcrv2;
            le=le+le2;
            numcrv=numcrv+numcrv2;
        end
    elseif ParameterData{ind}.type==126
        [~,le,evmethd]=crvPntsSrfNURBS(n,ParameterData{ind}.nurbs,ParameterData{ind}.v(1),ParameterData{ind}.v(2));
        ParameterData{ind}.evalmthd=evmethd;
        numcrv=1;
    else
        [ParameterData,le,numcrv]=retMsCrvLength(ParameterData,ind,n);
    end
    
    ParameterData{ind}.length=le;
    ParameterData{ind}.numcrv=numcrv;
    
elseif ParameterData{ind}.type==141
    
    le=0;
    numcrv=0;
    for i=1:ParameterData{ind}.n
        if ParameterData{ParameterData{ind}.crvpt(i)}.type==126
            [~,le2,evmethd]=crvPntsSrfNURBS(n,ParameterData{ParameterData{ind}.crvpt(i)}.nurbs,ParameterData{ParameterData{ind}.crvpt(i)}.v(1),ParameterData{ParameterData{ind}.crvpt(i)}.v(2));
            ParameterData{ParameterData{ind}.crvpt(i)}.length=le2;
            ParameterData{ParameterData{ind}.crvpt(i)}.evalmthd=evmethd;
            numcrv2=1;
        elseif ParameterData{ParameterData{ind}.crvpt(i)}.type==110
            [~,le2,~]=crvPntsSrfNURBS(1,ParameterData{ParameterData{ind}.crvpt(i)}.p1,ParameterData{ParameterData{ind}.crvpt(i)}.p2);
            ParameterData{ParameterData{ind}.crvpt(i)}.length=le2;
            numcrv2=1;
        else
            [ParameterData,le2,numcrv2]=retMsCrvLength(ParameterData,ParameterData{ind}.crvpt(i),n);
        end
        ParameterData{ind}.msclength(i)=le2;
        le=le+le2;
        numcrv=numcrv+numcrv2;
    end
    
elseif ParameterData{ind}.type==102
    
    le=0;
    numcrv=0;
    for i=1:(ParameterData{ind}.n)
        if ParameterData{ParameterData{ind}.de(i)}.type==126
            [~,le2,evmethd]=crvPntsSrfNURBS(n,ParameterData{ParameterData{ind}.de(i)}.nurbs,ParameterData{ParameterData{ind}.de(i)}.v(1),ParameterData{ParameterData{ind}.de(i)}.v(2));
            ParameterData{ParameterData{ind}.de(i)}.length=le2;
            ParameterData{ParameterData{ind}.de(i)}.evalmthd=evmethd;
            numcrv2=1;
        elseif ParameterData{ParameterData{ind}.de(i)}.type==110
            [~,le2,~]=crvPntsSrfNURBS(n,ParameterData{ParameterData{ind}.de(i)}.p1,ParameterData{ParameterData{ind}.de(i)}.p2);
            ParameterData{ParameterData{ind}.de(i)}.length=le2;
            numcrv2=1;
        else
            [ParameterData,le2,numcrv2]=retMsCrvLength(ParameterData,ParameterData{ind}.de(i),n);
        end
        ParameterData{ind}.lengthcnt(i)=le2;
        ParameterData{ind}.numcrvcnt(i)=numcrv2;
        le=le+le2;
        numcrv=numcrv+numcrv2;
    end
    ParameterData{ind}.length=le;
    ParameterData{ind}.numcrv=numcrv;
    
elseif ParameterData{ind}.type==126
    
    [~,le,evmethd]=crvPntsSrfNURBS(n,ParameterData{ind}.nurbs,ParameterData{ind}.v(1),ParameterData{ind}.v(2));
    ParameterData{ind}.length=le;
    ParameterData{ind}.evalmthd=evmethd;
    numcrv=1;
    
elseif ParameterData{ind}.type==110
    
    [~,le,~]=crvPntsSrfNURBS(n,ParameterData{ind}.p1,ParameterData{ind}.p2);
    ParameterData{ind}.length=le;
    numcrv=1;
    
else
    
    le=0;
    numcrv=0;
    
end
