function hA = plotAxis(OP,le,lw,fosi)
% Plot of xyz-coordinate axis
%
% OP - point where coordinate axis starts
% le - length of coordinate axis
% lw - line width
% fosi - font size
%
% hA - cell array of handle to graphical objects created by plotAxis
%
% m-file can be downloaded at
% http://www.mathworks.com/matlabcentral/fileexchange/13253-iges-toolbox
%
% written by Per Bergström 2015-11-22
%

if nargin<4
    fosi=14;
    if nargin<3
        lw=1.75;
    end
end

rd=[0.8500, 0.3250, 0.0980];
gr=[0.4660, 0.6740, 0.1880];
bl=[0, 0.4470, 0.7410];

textSpace=1.25;

hA1=quiver3(OP(1),OP(2),OP(3),le,0,0,0,'Color',rd,'LineWidth',lw,'MaxHeadSize',0.45,'AutoScaleFactor',1.0,'AutoScale','off');
hA2=quiver3(OP(1),OP(2),OP(3),0,le,0,0,'Color',gr,'LineWidth',lw,'MaxHeadSize',0.45,'AutoScaleFactor',1.0,'AutoScale','off');
hA3=quiver3(OP(1),OP(2),OP(3),0,0,le,0,'Color',bl,'LineWidth',lw,'MaxHeadSize',0.45,'AutoScaleFactor',1.0,'AutoScale','off');

hA4=text('String','x','Position',[OP(1)+textSpace*le,OP(2),OP(3)],'HorizontalAlignment','center','VerticalAlignment','middle','FontSize',fosi,'Color',rd);
hA5=text('String','y','Position',[OP(1),OP(2)+textSpace*le,OP(3)],'HorizontalAlignment','center','VerticalAlignment','middle','FontSize',fosi,'Color',gr);
hA6=text('String','z','Position',[OP(1),OP(2),OP(3)+textSpace*le],'HorizontalAlignment','center','VerticalAlignment','middle','FontSize',fosi,'Color',bl);

if nargout>0
    
    hA=cell(6,1);
    hA{1}=hA1;
    hA{2}=hA2;
    hA{3}=hA3;
    hA{4}=hA4;
    hA{5}=hA5;
    hA{6}=hA6;
    
end
