%% EOM Numerical Integrator:
% ====================================================
% change this for different scenarios

function [ t , z , tfinal , par ] = dyn_sim( z0 , par )
t0 = par.t0 ; dt = par.dt ; stepT = par.stepT ;
fprintf( 'dynamic sim... \n' )
par.elapsed_time = [ par.elapsed_time toc( par.timer ) ] ;
toc( par.timer )

global t_report
t_report = 0 ;
[ par.nq , par.nlambda , par.qf0 , par.n_m , par.n_sd , par.n_cn , par.n_ex , par.rom.mass , par.rom.sprdmp ] = nqF( par.var ) ; % states' number and init. value

eps = 0*[ 1e-6 1e-6 ] ; % for singularity prevention
if isempty( z0 ) % check if z0 is provided
    z0 = [ eps(1)+double( par.qf0 ) eps(1)*ones( 1 , par.nlambda ) eps(2)*ones( 1 , par.nq ) eps(2)*ones( 1 , par.nlambda ) ] ; % initial condition
else
    if par.t0 == par.t_init
        z0 = [ eps(1)+z0(1:end/2) eps(2)+z0(1+end/2:end) ] ;
    end
end

if par.t0 == par.t_init % && par.derive  % drive EOM_mex
    par = save_eom_mex( par , 1 ) ;
end
par_mex = par.par_mex ;
par_mex.t0 = par.t0 ;
        
odefun = @EOM ;
if par.dyn >= 2
	odefun = @EOM_mex ;
end

% ODE Solver
t_start_end = [ t0 t0+dt ]
tspan = t0 : stepT : t0 + dt ;

% Matlab ODE:
options = odeset ();% 'AbsTol' , 1e-10 , 'RelTol' , 1e-10 ) ;
% [ t , z , tfinal ] = ode113( odefun , tspan , z0 , options , par_mex ) ;
[ t , z , tfinal ] = ode15s( odefun , tspan , z0 , options , par_mex ) ;

% % Forwrd integration
% t = t0 ; z(1,:) = z0 ; i = 1 ;
% for t_step = tspan
%     coeff = 1 ;
%     if t_step == tspan(1) || t_step == tspan(end)
%         coeff = 0.5 ;
%     end
%     z(i+1,:) = z(i,:) + odefun( t(end) , z(end,:)' , par_mex )' * stepT * coeff ;
%     t(i+1,1) = t_step ;
%     i = i + 1 ;
% end
% tfinal = t_step ;

