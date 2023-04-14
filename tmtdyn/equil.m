%% EOM Numerical Integrator:
% ====================================================
% change this for different scenarios

function [ z0 , par ] = equil( par )
global par_mex
fprintf( 'equlibrium point... \n' )
par.elapsed_time = [ par.elapsed_time toc( par.timer ) ] ;
toc( par.timer )

[ par.nq , par.nlambda , par.ngamma , par.qf0 , par.n_m , par.n_sd , par.n_cn , par.n_co , par.n_ex ] = nqF( par.var ) ; % states' number and init. value

eps = [ 1*1e-6 0*1e-9 ] ; % for singularity prevention
z0 = [ eps(1)+double( par.qf0 ) eps(1)*ones( 1 , par.nlambda ) eps(1)*ones( 1 , par.ngamma ) eps(2)*ones( 1 , par.nq ) eps(2)*ones( 1 , par.nlambda ) eps(2)*ones( 1 , par.ngamma ) ] ; % initial condition
if par.equil == 0 ; return ; end

par.z0 = z0;
if par.t_equil_i == par.t_equil(1) % && par.derive  % drive EOM_mex
    par = save_eom_mex( z0 , par , 'equil' ) ;
end
par_mex = par.par_mex ;
par_mex.t_equil_i = par.t_equil_i ;

equilfun = @EOM_eq ;
if ismember( par.equil , [2, 3, 4] )
	equilfun = @EOM_eq_mex ;
end

% fsolve equlibrium solver
% options = optimset( 'Algorithm' , 'levenberg-marquardt' ) ; % 'trust-region-dogleg', 'trust-region', 'levenberg-marquardt'
options = optimoptions( 'fsolve', 'Algorithm', ...
                        'levenberg-marquardt', ...
                        'FiniteDifferenceType', 'central', ...                        
                        'MaxIterations', 1e3, ...
                        ...'StepTolerance', 1e-6 , ...
                        ...'FunctionTolerance', 1e-6 , ...
                        'MaxFunctionEvaluations', 1e4) ;
[ z0_eq , fval , exitflag ] = fsolve(equilfun , z0(1:end/2) , options )
z0 = [ z0_eq 0*z0_eq ] ;

par.par_mex = par_mex ;


