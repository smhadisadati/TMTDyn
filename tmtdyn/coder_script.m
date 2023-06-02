% LIB_EOM_SCRIPT   Generate static library EOM from EOM, EOM_input.
% 
% Script generated from project 'lib_EOM.prj' on 30-Jun-2021.
% 
% See also CODER, CODER.CONFIG, CODER.TYPEOF, CODEGEN.

function coder_script( par_dyn )

%% Create configuration object of class 'coder.CodeConfig'.
cfg = coder.config('lib','ecoder',false);
cfg.GenerateReport = true;
cfg.ReportPotentialDifferences = false;
cfg.GenCodeOnly = true;

%% Define argument types for entry-point 'EOM'.
[~, ~, z0, par_mex] = EOM_input(); EOM( 0 , z0 , par_mex );

ARGS = cell(2,1);
ARGS{1}{1} = coder.typeof(0);
ARGS{1}{2} = coder.typeof(z0);
ARGS{1}{3} = coder.typeof(par_mex);


%% Invoke MATLAB Coder.
if par_dyn == 6 % 6-'update_parameters_only'
    fprintf('Generating C code for input parameters ... \n')
    codegen -config cfg EOM_input    
else % full system
    % codegen -config cfg EOM -args ARGS{1} EOM_input
    fprintf('Generating C code for input parameters ... \n')
    codegen -config cfg EOM_input
    fprintf('Generating C code for system EOM ... \n')
    codegen -config cfg EOM -args ARGS{1}
end

