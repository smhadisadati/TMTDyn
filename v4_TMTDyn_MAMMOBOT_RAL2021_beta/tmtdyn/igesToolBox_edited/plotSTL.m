function handlePlot=plotSTL(VertexData,FVCD,fignr,holdoff_flag)
% PLOTSTL plots surface patches from STL-file
%
% Usage:
%
% handlePlot=plotSTL(VertexData,FVCD)
%
% Input:
%
% VertexData - Matrices with vertices (output from stl2matlab)
% FVCD - FaceVertexColorData or color specification, [r g b] (optional)
% fignr - Figure number of the plot. 1 default
% holdoff_flag - Bolean value (1/0). If 1 then hold off the plot
%                when the plot is done. 1 default
%
% Output:
%
% handlePlot - plothandle
%
% m-file can be downloaded at
% http://www.mathworks.com/matlabcentral/fileexchange/13253-iges-toolbox
%
% written by Per Bergström 2012-01-09
%


if nargin<4
    holdoff_flag=1;
    if nargin<3
        fignr=1;
        if nargin<2
            FVCD=[];
            if nargin<1
                error('plotSTL must have an input with VertexData');
            end
        end
    end
end

if isempty(fignr)
    fignr=1;
else
    fignr=round(fignr);
end

if isempty(holdoff_flag)
    holdoff_flag=1;
elseif not(holdoff_flag==0 | holdoff_flag==1)
    holdoff_flag=1;
end

if fignr>0
    figure(fignr),hold on
end

if isempty(FVCD)

    hPlot = patch(VertexData{1},VertexData{2},VertexData{3},zeros(size(VertexData{1})));
    set(hPlot,'facec','flat','EdgeColor','none');
    set(hPlot,'facec',[0.8 0.4 0.4]);
    
elseif length(FVCD(:))==3
    
    hPlot = patch(VertexData{1},VertexData{2},VertexData{3},zeros(size(VertexData{1})));
    set(hPlot,'facec','flat','EdgeColor','none');
    set(hPlot,'facec',FVCD);    
    
else
    
    hPlot = patch(VertexData{1},VertexData{2},VertexData{3},FVCD);
    set(hPlot,'facec','flat','EdgeColor','none');
    
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

if nargout>0
    handlePlot=hPlot;
end
