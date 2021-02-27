function results = pipeline (par, world, body, joint, exload, mesh)
%% initialize
par.timer = tic ; par.elapsed_time = [] ;

fprintf( 'start... \n' )
par.elapsed_time = [ par.elapsed_time toc( par.timer ) ] ;
toc( par.timer )

pause( 1e-2 )

% turn off warnings
warning('off','all')


%% EOM:
[ ~ , ~ , ~ , ~ , ~ , ~ , par , ~ ] = check( par , [] , [] , [] , [] , [] ) ;
if par.derive
    [ qf , uf , lambdaf , par ] = tmt_eom_derive ( par , world , body , joint , exload , mesh );
else
    reset( symengine ) ; % clear symbolic engine
end

%% numerical simulation & animation
% sim pars:
if par.dyn ~= 0 && par.t_equil(1) ~= par.t_init % include t_0  to static analysis
    par.t_equil = [ par.t_init , par.t_equil ] ;
end
par.t0 = par.t_init ;
if isinf( par.dt_anim_rep(1) )
    par.dt_anim_rep(1) = ( par.t_final - par.t_init ) / par.dt_anim_rep(2) ;
end
par.dt = par.dt_anim_rep(1) ;
% par.stepT = par.dt / ( ( 1 + floor( par.dt ) ) * par.n_datasample ) ; % sampling time to save data for
par.stepT = 1 / par.n_datasample ;
z0 = [] ;

% par_mex
par_mex.var = par.var ;
par_mex.user_pars = par.user_pars ;
par_mex.t_equil_i = par.t_equil(1) ;

par.par_mex = par_mex ;

% animation pars
par.fig.anim = figure ;
par.skip = floor( 1 / par.stepT / par.fps ) ; % animation step skip: result in ~ par.fps fps
if par.skip <= 0; par.skip = 1; end
par.animPause = 0 ; % 1: wait for user confirmation to show anim.
par.pause = 0 ; % animation frame pause time
if par.movie == 1
    par.vid = VideoWriter( './results/video.mp4' , 'MPEG-4' ) ;
    if par.t_final > 2 % avoid videos shorter than 2 [s]
        par.vid.FrameRate = 1 / par.stepT / par.skip ;
    else
        if par.dyn == 0
            par.vid.FrameRate = 1 ;
        else
            par.vid.FrameRate = 1 / par.stepT / par.skip * par.t_final / 2 ;
        end
    end
    par.vid.Quality = 100 ;
    open( par.vid ) ;
end

% static solve for equlibrium:
t_equil_all = [] ; z_equil_all = z0 ; rjtip_equil_all = [] ; Qjtip_equil_all = [] ;
i = 0 ;
for t_equil_i = par.t_equil
    i = i + 1 ;
    t_equil_i = t_equil_i % report t_equil in terminal
    par.t_equil_i = t_equil_i ; % solve for this time step (use to extract data from exp.)
    [ z0 , par ] = equil( par ) ; % find static equlibrium
    [ ~ , rjtip_0 , ~ , Qjtip_0 , ~ , par ] = anim( t_equil_i , z0 , par ) ; % plot equil.
    z_equil_all(i,:) = z0 ;
    rjtip_equil_all(:,:,i) = rjtip_0 ; Qjtip_equil_all(:,:,i) = Qjtip_0 ; t_equil_all(i) = t_equil_i ; par.linetype = 'o' ;
    pause( 1e-2 ) ;
end
t_all = t_equil_all ; z_all = z_equil_all ; rjtip_all = rjtip_equil_all ; Qjtip_all = Qjtip_equil_all ;

% linear modal analysis at equilibrium points:
Phi_modal = [] ; M_modal = [] ; K_modal = [] ; V_modal = [] ; omega = [] ; xi = [] ;
if par.modal
    par.figmod = figure ;
    i = 0 ;
    for t_equil_i = par.t_equil
        i = i + 1 ;
        par.t_equil_i = t_equil_i ;
        [ Phi_modal , M_modal , K_modal , V_modal , omega , xi , par ] = modal( z_all(i,:) , par ) ;
        pause( 1e-2 ) ;
    end
end

% sim & anim.:
z0 = z_equil_all(1,:) ;
if par.dyn ~= 0
    clf( par.fig.anim ) ; par.linetype = '-' ;
    t_all = [] ; z_all = [] ; rjtip_all = [] ; Qjtip_all = [] ;
    for t0_step = par.t_init : par.dt_anim_rep(1) : par.t_final - par.dt_anim_rep(1)
        % step sim:
        par.t0 = t0_step ;
        [ t , z , tfinal , par ] = dyn_sim( z0 , par ) ;
        
        % animation
        [ ~ , rjtip , ~ , Qjtip , ~ , par ] = anim( t , z , par ) ;
        
        % concatanate results
        t_all = [ t_all ; t(1:end-1) ] ;
        z_all = [ z_all ; z(1:end-1,:) ] ;
        rjtip_all = cat( 3 , rjtip_all , rjtip(:,:,1:end-1) ) ;
        Qjtip_all = cat( 3 , Qjtip_all , Qjtip(:,:,1:end-1) ) ;
        z0 = z(end,:) ;
    end
    t_all = [ t_all ; t(end) ] ; % to include the last point
    z_all = [ z_all ; z(end,:) ] ;
    rjtip_all = cat( 3 , rjtip_all , rjtip(:,:,end) ) ;
    Qjtip_all = cat( 3 , Qjtip_all , Qjtip(:,:,end) ) ;
end

if par.movie == 1 ; close( par.vid ) ; end

fprintf( 'sim. end... \n' )
par.elapsed_time = [ par.elapsed_time toc( par.timer ) ] ;


%% post process
if par.post_process
    par = post_proc( t_all , t_equil_all , z_all , z_equil_all , rjtip_all , rjtip_equil_all , Qjtip_all , Qjtip_equil_all , ...
	Phi_modal , M_modal , K_modal , V_modal , omega , xi , ...
	par ) ;
    pause( 1 )
    save( './results/results_sys.mat' ) ; % save workspace
end

% results
results.t = t_all ; results.t_equil = t_equil_all ; results.z =z_all ; results.z_equil = z_equil_all ;
results.rjtip = rjtip_all ; results.rjtip_equil = rjtip_equil_all ; results.Qjtip = Qjtip_all ; results.Qjtip_equil = Qjtip_equil_all ;
results.Phi_modal = Phi_modal ; results.M_modal = M_modal ; results.K_modal = K_modal ; results.V_modal = V_modal ; results.omega = omega ; results.xi = xi ;
results.par = par ;


