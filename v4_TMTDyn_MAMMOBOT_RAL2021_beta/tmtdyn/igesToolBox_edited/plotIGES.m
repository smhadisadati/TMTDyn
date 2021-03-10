function iges_figure = plotIGES(ParameterData,srf,fignr,subd,holdoff_flag,fine_flag,plotCrvPnts,srfClr)
% PLOTIGES plots surfaces, curves and points from IGES-file
%
% Simple usage:
%
% handlePlot=plotIGES(ParameterData)
%
% or
%
% handlePlot=plotIGES(ParameterData,1)
%
% Ordinary usage:
%
% plotIGES(ParameterData,srf,fignr,subd,holdoff_flag)
%
% Input:
%
% ParameterData - Parameter data from IGES file. ParameterData
%                 is the output from IGES2MATLAB
% srf - Flag for surface plotting. (0,1,2)
%        0 (default), no surfaces are plotted,
%        1 the surface is plotted as triangular patches,
%        2 the surface is plotted as triangular mesh
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
% plotCrvPnts - Flag for curve and point plotting (1/0)
%        0, no curves and points are plotted,
%        1  curves and points are plotted (default)
% srfClr - Color of surface
%
% Output:
%
% handlePlot - plothandle
%
% m-file can be downloaded at
% http://www.mathworks.com/matlabcentral/fileexchange/13253-iges-toolbox
%
% written by Per Bergstr�m 2013-11-14
%

if nargin<8
    usrDefClr=false;
    if nargin<7
        plotCrvPnts=1;
        if nargin<6
            fine_flag=0;
            if nargin<5
                holdoff_flag=1;
                if nargin<4
                    subd=100;
                    if nargin<3
                        fignr=1;
                        if nargin<2
                            srf=0;
                            if nargin<1
                                error('plotIGES must have an input');
                            end
                        end
                    end
                end
            end
        end
    end
else
    if isempty(srfClr)
        usrDefClr=false;
    elseif isscalar(srfClr)
        usrDefClr=false;
    else
        usrDefClr=true;
    end
end

if isempty(ParameterData)
    error('Empty ParameterData');
elseif not(iscell(ParameterData))
    error('Invalid ParameterData. Must be a cell array!');
end

if isempty(srf)
    srf=0;
elseif not(srf==0 | srf==1 | srf==2)
    srf=0;
end

srf0not=not(srf==0);
srf1=srf==1;

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

if isempty(plotCrvPnts)
    plotCrvPnts=1;
elseif not(plotCrvPnts==0 | plotCrvPnts==1)
    plotCrvPnts=1;
end

subd=subd+1;  % subd now number of points, not number of subintervals

siz=length(ParameterData);

if usrDefClr
    clr=srfClr;
else
    clr=[0.8,0.8,0.9];
end
lsclclr=0.5;
pntsclclr=0.25;

if fignr>0
    iges_figure = figure(fignr) ; hold on
end


for i=1:siz
        
    if strcmp( ParameterData{i}.name , 'LINE' )
        
        line( 'XData' , [ ParameterData{i}.p1(1) ParameterData{i}.p2(1) ] , ...
            'YData' , [ ParameterData{i}.p1(2) ParameterData{i}.p2(2) ] , ...
            'ZData' , [ ParameterData{i}.p1(3) ParameterData{i}.p2(3) ] ) ;
        hold on
        
    end
    
end


axis image

sc=0.2;

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
