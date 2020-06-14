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

if par.t0 == par.t_init  % drive EOM_mex
    par = save_eom_mex( par , 1 ) ;
    if par.solver == 3 % sundials DAE
        par_temp = par;
        par_temp.solver = 1 ;
        save_eom_mex( par_temp , 3 ) ;
        par_temp = [];
    end
end
par_mex = par.par_mex ;
% par_mex.t0 = par.t0 ;


%% ODE Solver
t_start_end = [ t0 t0+dt ] 
tspan = t0 : stepT : t0 + dt ;

odefun = @EOM ;
if par.dyn >= 2
	odefun = @EOM_mex ;
end
    
switch par.solver 
    case 1 % Matlab ODE:
        options = odeset (); % 'MassSingular', 'yes');%, 'AbsTol' , 1e-10 , 'RelTol' , 1e-10 ) ;
        % [ t , z , tfinal ] = ode113( odefun , tspan , z0 , options , par_mex ) ;
        [ t , z , tfinal ] = ode15s ( odefun , tspan , z0 , options , par_mex ) ;
        
    case 2 % Sundials ODE solver
        startup_STB;
        options = CVodeSetOptions ('UserData', par_mex,...
                                   'RelTol', 1.0e-6,...
                                   'AbsTol', 1.0e-6,...
                                   'InitialStep', 1.0e-23,...
                                   'MaxNumSteps', 1.0e6);
        % CVodeInit (odefun, 'Adams', 'Functional', t0, z0', options); % non-stiff probrem
        CVodeInit (odefun, 'BDF', 'Newton', t0, z0', options); % stiff problems
        [status, t, z] = CVode (tspan, 'Normal');
        tfinal = t (end);
        t = t'; z = z';
        Sundial_ODE_Return_Status = status
        CVodeFree; % free memory
        
    case 3 % Sundials DAE
        startup_STB;
        id = ones (numel (z0), 1);
        id ((par.nq + 1): end / 2) = 0 ; % associated w gamma: Lagrange multiplier for velocity constraints
        id ((end - par.nlambda + 1): end) = 0 ; % associated w lambda: Lagrange multiplier for acceleration constraints
        if par.dyn >= 2
            dz0 = EOM_0_mex (0, z0', par_mex);
        else
            dz0 = EOM_0 (0, z0', par_mex);
        end
        options = IDASetOptions ('UserData', par_mex,...
                                 'RelTol', 1.0e-6,...
                                 'AbsTol', 1.0e-6,...
                                 'VariableTypes', id,...
                                 'suppressAlgVars', 'on',...
                                 'InitialStep', 1.0e-23,...
                                 'MaxNumSteps', 1.0e6,...
                                 'LinearSolver', 'Dense');
        IDAInit (odefun, t0, z0', dz0, options); % stiff problems
        % [status, t, z] = IDASolve (tspan, 'Normal');
        t = 0; z = z0'; 
        i_end = numel (tspan);
        for i = 2: i_end
            [status, t(i), z(:,i)] = IDASolve(tspan(i), 'OneStep');
        end
        tfinal = t (end);
        t = t'; z = z';
        Sundial_DAE_Return_Status = status
        IDAFree; % free memory
        
end


