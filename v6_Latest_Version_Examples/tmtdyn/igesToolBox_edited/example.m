% example.m plots an IGES CAD-object

% Compile the c-files
makeIGESmex;

% Load parameter data from IGES-file.
[ParameterData,EntityType,numEntityType,unknownEntityType,numunknownEntityType]=iges2matlab('IGESfiles/example.igs');

% Plot the IGES object
plotIGES(ParameterData,1);
