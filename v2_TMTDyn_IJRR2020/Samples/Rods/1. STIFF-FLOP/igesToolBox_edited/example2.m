% example2.m plots an IGES CAD-object

% Compile the c-files (if necessary)
% makeIGESmex;

% Load parameter data from IGES-file.
[ParameterData,EntityType,numEntityType,unknownEntityType,numunknownEntityType]=iges2matlab('IGESfiles/example2.igs');


% Plot the IGES object
plotIGES(ParameterData,2,1,30);
