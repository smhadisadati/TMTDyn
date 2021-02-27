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
[ par.nq , par.nlambda , par.ngamma , par.qf0 , par.n_m , par.n_sd , par.n_cn , par.n_co , par.n_ex ] = nqF( par.var ) ; % states' number and init. value

eps = [ 1*1e-6 0*1e-9 ] ; % for singularity prevention
if isempty( z0 ) % check if z0 is provided
    z0 = [ eps(1)+double( par.qf0 ) eps(1)*ones( 1 , par.nlambda ) eps(1)*ones( 1 , par.ngamma ) eps(2)*ones( 1 , par.nq ) eps(2)*ones( 1 , par.nlambda ) eps(2)*ones( 1 , par.ngamma ) ] ; % initial condition
else
    if par.t0 == par.t_init
        z0 = [ eps(1)+z0(1:end/2) eps(2)+z0(1+end/2:end) ] ;
    end
end

par.z0 = z0;
if par.t0 == par.t_init  % drive EOM_mex
    par = save_eom_mex( z0 , par , 'dyn' ) ;
    % save_eom_mex( z0 , par , 'J' ) ; % WRONG! needs denseJ not J
    if par.solver == 3 % sundials DAE
        save_eom_mex( z0 , par , 'dz0' ) ;
    end
end
par_mex = par.par_mex ;
% par_mex.t0 = par.t0 ;


%% ODE Solver
t_start_end = [ t0 t0+dt ] 
tspan = t0 : stepT : t0 + dt ;

odefun = @EOM ;
Jfun = @EOM_J ;
if ismember( par.dyn , [2, 3, 4] ) % 2-'generate_mex_file', 3-'old_mex_file', 4-'generate_mex_file_from_edited_m_file'
	odefun = @EOM_mex ;
	Jfun = @EOM_J_mex ;
end

switch par.solver
    case 1 % Matlab ODE:
        options = odeset ( 'AbsTol' , 1e-4 , 'RelTol' , 1e-3 ) ;
        % [ t , z , tfinal ] = ode113( odefun , tspan , z0 , options , par_mex ) ;
        [ t , z , tfinal ] = ode15s ( odefun , tspan , z0 , options , par_mex ) ;
        
    case 2 % Sundials ODE solver        
        startup_STB;
        options = CVodeSetOptions ('UserData', par_mex,...
                                   'RelTol', 1.0e-3,...
                                   'AbsTol', 1.0e-4,...
								   ...'JacobianFn', Jfun,... % WRONG! needs denseJ not J
                                   'InitialStep', 1.0e-23,...
                                   'MaxNumSteps', 1e9);
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
        if par.dyn >= 2 % 2-'generate_mex_file', 3-'old_mex_file', 4-'generate_mex_file_from_edited_m_file', 5-'edited_m_file',
            dz0 = EOM_0_mex (0, z0', par_mex);
        else
            dz0 = EOM_0 (0, z0', par_mex);
        end
        options = IDASetOptions ('UserData', par_mex,...
                                 'RelTol', 1.0e-3,...
                                 'AbsTol', 1.0e-4,...
                                 'VariableTypes', id,...
                                 'suppressAlgVars', 'on',...
                                 'InitialStep', 1.0e-23,...
                                 'MaxNumSteps', 1.0e9,...
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
        
    case { 4 , 5 } % radau ODE solver
        options.nAlgVars = par.nlambda + par.ngamma;
        options.RelTol = 1e-3;
        options.AbsTol = 1e-4;
        options.InitialStep = 1e-23;
        options.t_rep = par.t_rep;
        
        
        if ismember( par.solver , [ 4 ] )
            [t, z] = radau_edit(odefun, tspan, z0', par_mex, options) ;
%             [t, z] = radau_edit_supAlgVar(odefun, tspan, z0', par_mex, options) ;
% %             [t, z] = radau_edit_pinv(odefun, tspan, z0', par_mex, options) ;radau_edit_suppressAlgVars
% %             [t, z] = radau_edit_supAlgVar_MR(odefun, tspan, z0', par_mex, options) ;
            
        else
            if ~ismember( par.dyn , [ 3 ] ) % 3-'old_mex_file'
                fprintf( 'generate Radau mex files... \n' )
                par.elapsed_time = [ par.elapsed_time toc( par.timer ) ] ;
                toc( par.timer )
                
                cd eom
                nz = 2 * ( par.nq + par.nlambda + par.ngamma ) ;
                vars_mex = { tspan , zeros( 1 , nz )' , par_mex , options } ;
%                 codegen radau_mexedit -args vars_mex % use full mat.
                codegen radau_mexedit_sparse -args vars_mex % use sparse mat. but needs trans. to full for lu
                cd ..

                fprintf( 'mex files generated. continue... \n' )
                par.elapsed_time = [ par.elapsed_time toc( par.timer ) ] ;
                toc( par.timer )
            end
%             [t, z] = radau_mexedit_mex(tspan, z0', par_mex, options) ;
            [t, z] = radau_mexedit_sparse(tspan, z0', par_mex, options) ;
            
        end        
        tfinal = t(end);
        
    case 6 % external solver
        try
            fprintf( 'importing external results from file results.txt ... \n' )
            results_file = './eom/codegen/lib/EOM/results.txt'; % default generated code location from Demo_mex
            delimiterIn = '\t';
            results = importdata( results_file, delimiterIn );
        catch e            
            switch par.dyn 
                case { 1, 2, 4, 5 } % 1-'generate_m_file', 2-'generate_mex_file', 4-'generate_mex_from_edited_m_file', 5-'edited_m_file'       
                    load('config.mat');
                    fprintf( 'no file is found... \n' )
                    fprintf( '>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> \n' )
                    fprintf( 'create cpp code (EOM_input & EOM in eom folder) using Matlab coder app for an external solver... \n' )
                    fprintf( 'run this sample code in the coder app to determine the inputs:... \n' )
                    fprintf( '[tspan, nz, z0, par_mex] = EOM_input(); EOM( 0 , z0 , par_mex ); ... \n' )
                    fprintf( 'for optimized code conversion, load the congig.mat and import it to Matlab Coder app ... \n' )
                    fprintf( 'load(''config.mat''); ... \n' )
                    fprintf( 'c code is generated in ./eom/codegen/lib/EOM ... \n' )
                    fprintf( 'see sundials external solver help in ./tmtdyn/sundials_c ... \n' )
                    fprintf( 'set the number of states in ./eom/codegen/lib/EOM/Demo_mex.c or Demo.c file to nq: #define STATES_NO RCONST(nq) \nwhere nq is ... \n' )
                    numel(z0)
                    fprintf( '>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> \n' )
                    par.elapsed_time = [ par.elapsed_time toc( par.timer ) ] ;
                    toc( par.timer )
                    coder ;                  
                    fprintf('when code generation with coder is finished, run the model again with .dynamic_sim(''generate_mex_from_c_files'', ''external'',... \n')
                    error('no ./eom/EOM_c/results.txt file is found! see above instructions.')
                    % t = []; z = []; tfinal = [];
                    % return
                case 6 % 6-'generate_mex_from_c_files'
                    par.elapsed_time = [ par.elapsed_time toc( par.timer ) ] ;
                    toc( par.timer )
                    fprintf('compile EOM mex file...') % mex compile
                    mex -IC:\sundials-5.6.1\instdir\include -LC:\sundials-5.6.1\instdir -lsundials_cvode ./eom/codegen/lib/EOM/*.c -output ./eom/codegen/lib/EOM/Demo_mex
            end
            par.elapsed_time = [ par.elapsed_time toc( par.timer ) ] ;
            toc( par.timer )
            fprintf('run external simulation with SUNDIALS ODE...') % run simulation
            cd eom/codegen/lib/EOM % default generated code location from Demo_mex is the top folder
            Demo_mex
            cd ../../../.. % return to top folder
            fprintf( 'importing external results from file results.txt ... \n' ) % import results
            results_file = './eom/codegen/lib/EOM/results.txt'; % default generated code location where Demo_mex generate results
            delimiterIn = '\t';
            results = importdata( results_file, delimiterIn );
        end        
        t = results(:,1);
        z = results(:,2:end);
        tfinal = t(end);

        fprintf( 'results.txt file is loaded... \n' )
        par.elapsed_time = [ par.elapsed_time toc( par.timer ) ] ;
        toc( par.timer )
        
end


