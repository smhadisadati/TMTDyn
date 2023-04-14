function pipeline (par, world, body, joint, exload, mesh)
%% initialize
par.timer = tic ; par.elapsed_time = [] ;

fprintf( 'start... \n' )
par.elapsed_time = [ par.elapsed_time toc( par.timer ) ] ;
toc( par.timer )

pause( 1e-2 )


%% EOM:
if par.derive == 1
    [ qf , uf , lambdaf , par ] = tmt_eom_derive ( par , world , body , joint , exload , mesh );
end


%% numerical simulation & animation
% sim pars:
par.t_init = par.t_exp(exp_case(2)) ;
if exp_case(3) == inf
    par.t_final = par.p(end,1) ;
    par.t_equil = par.t_exp_equil(exp_case(2):end) ;
else
    par.t_final = par.t_exp(exp_case(3)) ;
    par.t_equil = par.t_exp_equil(exp_case(2):exp_case(3)) ;
end
if par.simdyn ~= 0 % for static analysis
    par.t_equil = par.t_init ;
end
if isinf( par.dt_anim_rep(1) )
    par.dt_anim_rep(1) = ( par.t_final - par.t_init ) / par.dt_anim_rep(2) ;
end
par.dt = par.dt_anim_rep(1) ;
par.stepT = par.dt / ( ( 1 + floor( par.dt ) ) * par.n_datasample ) ; % sampling time to save data for
% par.stepT = 1e-3 ;
z0 = [] ;

% animation pars
par.fig.anim = figure ;
par.skip = floor( 1 / par.stepT / 25 ) ; % animation step skip: result in ~ 25 fps
par.animPause = 0 ; % 1: wait for user confirmation to show anim.
par.pause = 0 ; % animation frame pause time
if par.movie == 1
    par.vid = VideoWriter( 'code/results/video.avi' ) ;
    if par.t_final > 2 % avoid videos shorter than 2 [s]
        par.vid.FrameRate = 1 / par.stepT / par.skip ;
    else
        par.vid.FrameRate = 1 / par.stepT / par.skip * par.t_final / 2 ;
    end
    par.vid.Quality = 100 ;
    open( par.vid ) ;
end

% static solve for equlibrium:
z_all = z0 ;
i = 0 ;
for t_equil_i = par.t_equil
    i = i + 1 ;
    par.t_equil_i = t_equil_i ; % solve for this time step (use to extract data from exp.)
    [ z0 , par ] = equil( par ) ; % find static equlibrium
    [ ~ , rjtip_0 , ~ , par ] = anim( t_equil_i , z0 , par ) ; % plot equil.
    z_all(i,:) = z0 ;
    rjtip_all(:,:,i) = rjtip_0 ; t_all(i) = t_equil_i ; par.linetype = 'o' ;
    pause( 1e-2 ) ;
end

% linear modal analysis at equilibrium points:
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
if par.simdyn ~= 0
    clf( par.fig.anim ) ; par.linetype = '-' ;
    t_all = [] ; z_all = [] ; rjtip_all = [] ;
    for t0_step = par.t_init : par.dt_anim_rep(1) : par.t_final - par.dt_anim_rep(1)
        % step sim:
        par.t0 = t0_step ;
        [ t , z , tfinal , par ] = sim_dyn( z0 , par ) ;
        
        % animation
        [ ~ , rjtip , ~ , par ] = anim( t , z , par ) ;
        
        % concatanate results
        t_all = [ t_all ; t(1:end-1) ] ;
        z_all = [ z_all ; z(1:end-1,:) ] ;
        rjtip_all = cat( 3 , rjtip_all , rjtip(:,:,1:end-1) ) ;
        z0 = z(end,:) ;
    end
    t_all = [ t_all ; t(end) ] ; % to include the last point
    z_all = [ z_all ; z(end,:) ] ;
    rjtip_all = cat( 3 , rjtip_all , rjtip(:,:,end) ) ;
end

if par.movie == 1 ; close( par.vid ) ; end

fprintf( 'sim. end... \n' )
par.elapsed_time = [ par.elapsed_time toc( par.timer ) ] ;


%% post process
if par.post_process
    post_proc( t_all , z_all , rjtip_all , par ) ;
    pause( 1 )
    save( 'code/results/results_sys.mat' ) ; % save workspace
end
