


			             IGES TOOLBOX FOR MATLAB
			             =======================

                                          Per Bergström



This is a version of the IGES toolbox for MATLAB. It can be downloaded at Mathworks file exchange community site,

http://www.mathworks.com/matlabcentral/fileexchange/13253-iges-toolbox

The toolbox cannot handle all IGES entity types but hopefully it will be a help for you to develop your CAD applications. 
A recommendation is to use I-DEAS IGES translator to generate the IGES-files.

Run some of the example files; "example", "example2", "exampleProjection", ...
in MATLAB's Command window for examples.

Some mex source files are also included. Compile them in MATLAB by running

"makeIGESmex"

in the Command window. All users must first compile the source-code before they can use it. Make sure you have a C-compiler installed.
See "help mex" in MATLAB for more information.





				          MAIN FUNCTIONS
				          ==============


iges2matlab
-----------

This is the main function which extracts IGES parameter data from a CAD-file into Matlab. 



plotIGES
--------

Plots the IGES CAD-model.



plotIGESentity
--------------

Plots a given entity of an IGES CAD-model.



plotNURBS
---------

Plots a NURBS entity (surface or curve).



transformIGES
-------------

Transform the parameter data of an IGES CAD-model with a rotation/reflection and a translation.



findEntityIGES
--------------

Returns a vector with indices having a given entity type number.



projIGES
--------

Returns points of projections on a surface of an IGES CAD-model.



projpartIGES
------------

Returns points of projections on part of a surface of an IGES CAD-model.



projpartPerspectiveIGES
-----------------------

Returns points of a perspective projections on part of a surface of an IGES CAD-model.



projpartSphericalIGES
---------------------

Returns points of a spherical projections on part of a surface of an IGES CAD-model.
 


srfRepInProjection
------------------

Returns a surface representation using input/output from projpartIGES. See "exampleProjection2", and "exampleProjection2b".



linAppSrfIGES
-------------

Returns a surface approximation.
 


icpSrfLinRep
------------

Returns a surface representation.



getDVGtree
----------

Returns a DVG tree.

See:
P. Bergström, O. Edlund, and I. Söderkvist 2011
"Repeated surface registration for on-line use",
The International Journal of Advanced Manufacturing Technology,
Volume 54, Issue 5-8, pp 677-689




icpDVGpnt2pntLS (mex functions)
icpDVGpnt2pntTu
icpDVGpnt2plnLS
icpDVGpnt2plnTu
---------------------

ICP algorithms.

See references at:  https://se.mathworks.com/matlabcentral/fileexchange/12627-iterative-closest-point-method



offsetIGES
----------

Creates an offset surface from given parameter data.



stl2matlab
----------

Extracts data in STL-files to Matlab.



plotSTL
-------

Plots data from STL-files.



transformSTL
------------

Transform vertices of a STL-object with a rotation/reflection and a translation.



igesToolBoxGUI
--------------

Matlab GUI. (igesToolBoxGUI.m and igesToolBoxGUI.fig)



				          SUBFUNCTIONS
				          ============


retSrfCrvPnt
------------

Returns values from surfaces, curves and points. No complete documentation is given.



nrbDerivativesIGES
------------------

Returns first and second derivative representation of NURBS.



getSurfaceDistributedPoints
---------------------------

Returns points distribusted on a surface.




nrbevalIGES (mex function)
--------------------------

Evaluates NURBS and derivatives of NURBS.



nrbSrfRegularEvalIGES (mex function)
------------------------------------

Evaluates a NURBS surface at parameter values in a regular grid.



crvPntsSrfNURBS (mex function)
------------------------------

Trimmed curve evaluation.



closestNrbLinePointIGES (mex function)
--------------------------------------

Returns the closest point to a NURBS patch and a line/point.



LScrvApp (mex function)
-----------------------

Creates matrices for NURBS curve fit in 2D.



offsetNURBSsurface (mex function)
---------------------------------

Creates an offset NURBS surface.



createDVGtree (mex function)
----------------------------

Creates a DVG-tree.



makeIGESmex
-----------

m-file for compiling the mex files.



For more documentation about the listed functions above, see the help for each function in Matlab.
The folder mexSourceFiles contains source code for subfunctions of the mex-files.

