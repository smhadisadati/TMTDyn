%% initialize
close all
clear all
format shorte
clc
pause( 1e-2 )

addpath('./tmtdyn','./hll','./eom');


%% parameters
sample = 1;
 
% variables & values
syms sample_symbol
vars = [sample_symbol];
var_vals = [sample] ;


%% preprocess if any
...


%% robot
tmtdyn()...
    ... % system description
    .run();

