function plotIGESentity(ParameterData,entity,fignr,subd,holdoff_flag,fine_flag,dim)
% PLOTIGESENTITY plots surfaces, curves and points from IGES-file
%
% Usage:
%
% plotIGES(ParameterData,entity)
%
% Ordinary usage:
%
% plotIGES(ParameterData,entity,fignr,subd,holdoff_flag)
%
% Input:
%
% ParameterData - Parameter data from IGES file. ParameterData
%                 is the output from IGES2MATLAB
% entity - index in ParameterData
% fignr - Figure number of the plot. 1 default
% subd - Nuber of subdivisions when plotting curves
%        subd is nubmer of subdivisions for each parameter when
%        plotting surfaces. 100 default
% holdoff_flag - Bolean value (1/0). If 1 then hold off the plot
%                when the plot is done. 1 default
% fine_flag - 0 the surface will be rough (default)
%             1 the surface will be finer
%             2 the surface will be even finer
%             3 the surface will be even finer
% dim - Dimension (3/2). If 2 curve entities 141 and 142 will
%             be plotted in parameter space (2D space). 3 default
%
%
% m-file can be downloaded at
% http://www.mathworks.com/matlabcentral/fileexchange/13253-iges-toolbox
%
% written by Per Bergström 2012-01-09
%

if nargin<7
    dim=3;
    if nargin<6
        fine_flag=0;
        if nargin<5
            holdoff_flag=1;
            if nargin<4
                subd=100;
                if nargin<3
                    fignr=1;
                    if nargin<2
                        error('plotIGES must have 2 inputs');
                    end
                end
            end
        end
    end
end

if isempty(ParameterData)
    error('Empty ParameterData');
elseif not(iscell(ParameterData))
    error('Invalid ParameterData. Must be a cell array!');
end

if isempty(entity)
    error('Empty entity');
end

if isempty(fignr)
    fignr=1;
else
    fignr=round(fignr);
end

if isempty(subd)
    subd=100;
else
    subd=round(subd);
end

if subd<10
    subd=10;
end

if isempty(holdoff_flag)
    holdoff_flag=1;
elseif not(holdoff_flag==0 | holdoff_flag==1)
    holdoff_flag=1;
end

if isempty(fine_flag)
    fine_flag=0;
end

if isempty(dim)
    dim=3;
elseif dim>2
    dim=3;
end

subd=subd+1;  % subd is now number of points, not number of subintervals

try
    clr=ParameterData{entity}.color;
catch
    clr=[0.8,0.8,0.9];
end

lclrf=0.6;

if fignr>0
    figure(fignr),hold on
end

i=entity;

if dim>2
    [P,isSCP]=retSrfCrvPnt(2,ParameterData,0,i,subd,0);
else
    [P,isSCP]=retSrfCrvPnt(2,ParameterData,0,i,subd);
end

if isSCP

    plot3(P(1,:),P(2,:),P(3,:),'Color',lclrf*clr,'LineWidth',1);
    
else

    [P,isSCP]=retSrfCrvPnt(3,ParameterData,0,i);
    
    if isSCP

        plot3(ParameterData{i}.x,ParameterData{i}.y,ParameterData{i}.z,'r.');
        
    else

        if fine_flag
            [P,isSCP,isSup,TRI]=retSrfCrvPnt(1,ParameterData,0,i,subd,fine_flag);
        else
            [P,isSCP,isSup,TRI]=retSrfCrvPnt(1,ParameterData,0,i,subd);
        end
        
        if isSCP
            patch('faces',TRI,'vertices',P','FaceColor',clr,'EdgeColor',lclrf*clr);
        end

    end
end

axis image

sc=0.05;

xl=xlim;
dx=xl(2)-xl(1);
xl(1)=xl(1)-sc*dx;
xl(2)=xl(2)+sc*dx;
xlim(xl);

yl=ylim;
dy=yl(2)-yl(1);
yl(1)=yl(1)-sc*dy;
yl(2)=yl(2)+sc*dy;
ylim(yl);

zl=zlim;
dz=zl(2)-zl(1);
zl(1)=zl(1)-sc*dz;
zl(2)=zl(2)+sc*dz;
zlim(zl);

if holdoff_flag
    hold off;
end
