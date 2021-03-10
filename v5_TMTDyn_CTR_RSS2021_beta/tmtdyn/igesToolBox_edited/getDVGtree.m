function DVGdata=getDVGtree(normal,pdir,sdir,MODEL,DIRVEC,MINDIRsq,MNORMAL,gridSpacingL0,newGridsMaxDist,Nvertex)
% getDVGtree returns a DVG tree
%
% Usage:
%
% DVGdata=getDVGtree(normal,pdir,sdir,MODEL,DIRVEC,MINDIRsq,MNORMAL,gridSpacingL0,newGridsMaxDist,Nvertex)
%
% Input:
%
% normal - the normal vector
% pdir - primary direction
% sdir - secondary direction
% MODEL - The model points
% DIRVEC - (output from icpSrfLinRep)
% MINDIRsq - (output from icpSrfLinRep)
% MNORMAL - (output from icpSrfLinRep)
% gridSpacingL0 - the grid spacing in tree level 0
% newGridsMaxDist - the maximal distance to the model points for new grid systems
% Nvertex - size of new grids. Nvertex=[N1,N2,...,Nk], size of new grids
%           will be [N1^3,N2^3,...,Nk^3]
%
% Output:
%
% DVGdata - A data structure
%
% m-file can be downloaded at
% http://www.mathworks.com/matlabcentral/fileexchange/13253-iges-toolbox
%
% written by Per Bergström 2012-03-15
%
% Reference
%
% Authors: Per Bergström, Ove Edlund, and Inge Söderkvist
% Title: Repeated surface registration for on-line use
% Journal: The International Journal of Advanced Manufacturing Technology
% Cover Date: 2011-05-01
% Publisher: Springer London
% Issn: 0268-3768
% Pages: 677-689
% Volume: 54
% Issue: 5
% Url: http://dx.doi.org/10.1007/s00170-010-2950-6
% Doi: 10.1007/s00170-010-2950-6
%


ON=[normal,pdir,sdir];

T=ON'*MODEL;

P0=min(T,[],2);
Pb=max(T,[],2);

clear T;

nf=(Pb-P0)/gridSpacingL0;
N0=floor(nf);
P0=P0+0.5*(nf-N0)*gridSpacingL0;
N0=N0+1;

P0=ON*P0;

clear ON Pb nf
clear functions

DT=delaunayTriangulation(MODEL');
Tes=uint32(DT.ConnectivityList)-1;
clear DT

DVGdata=createDVGtree(normal,pdir,sdir,P0,N0,gridSpacingL0,Nvertex,newGridsMaxDist,MODEL,DIRVEC,MINDIRsq,MNORMAL,Tes);
