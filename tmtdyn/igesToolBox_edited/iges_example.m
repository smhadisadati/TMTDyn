% example.m plots an IGES CAD-object
clear all
close all
clc

% Compile the c-files
makeIGESmex;

% Load parameter data from IGES-file.
[ParameterData,EntityType,numEntityType,unknownEntityType,numunknownEntityType]=iges2matlab('frame3fixed.IGS');

% Plot the IGES object
plotIGES(ParameterData,1);