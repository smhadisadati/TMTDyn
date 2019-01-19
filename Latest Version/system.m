%% initialize

clc
clear all
close all
format shorte

addpath('./code');
world = [] ; body = [] ; joint = [] ; % defaults
exload = [] ; pack = [] ;
par.sym = [] ; par.timer = tic ; par.elapsed_time = [] ;

fprintf( 'start... \n' )
par.elapsed_time = [ par.elapsed_time toc( par.timer ) ] ;
toc( par.timer )

pause( 1e-2 )


%% initialization
par.exp_case = 2 ; % [ case star_sequence end_sequence ]

% derivation
par.derive = 0 ; % set 1 to rederive in TMT
par.derive_collect = 1 ; % collect in 1: single struct., 2: seperte struct.s, 3: seperate func.s, 4: C func.s
par.derive_mex = 0 ; % use Matlab codegen, automatically sets par.derive_collect = 1
par.opv = false ; % optimize results

% controls
par.Anim = 1 ; % animation on (1) or off (0)
par.movie = 0 ; % save movie[ ~ , rks , par ] = AnimEOM_mex( t , z , par );
par.equil = 0 ; % 1: static analysis with Matlab func.s, 2: with C-mex func.s, 3: to used latest genarated C-Mex file
par.modal = 0 ; % 1: linear modal analysis with Matlab func.s, 2: with C-mex func.s
par.simdyn = 1 ; % 1: dyn. sim. with Matlab func.s, 2: with C-mex func.s, 3: to used latest genarated C-Mex file

% other parameters
par.t_rep = 5e-1 ; % sim report time
par.n_int = 100 ; % number of integration steps
par.n_animpoints = 50 ; % number of anim points
par.n_datasample = 50 ; % number of saved data samples
dt_anim_rep = [ inf 1 ] ; % anim report time, if 'inf' then (tf-t0)/dt_animStep(2)

% variables
if par.derive == 1
    syms sample_symbol % symbolic parameters
    par.sym = [ sample_symbol ] ;
assume( par.sym , 'real' ) ;
else
    sample_symbol = 0 ;
end


%% parameters
% ...
sample = 1 ; 
par.var = [ sample ] ;


%% derivation simplification
% ...


%% preprocess
% ...


%% system geomety
% world.g, body, joint, exload, mesh
% ...
world.g = [] ;
body = [] ;
joint = [] ;
exload = [] ;
mesh = [] ;
        

%% EOM:
if par.derive == 1
    [ qf , uf , lambdaf , par ] = tmt_eom_derive ( par , world , body , joint , exload , mesh );
end


%% import experimental data if needed
par = exp( par ) ;


%% numerical simulation & animation
% sim pars:
% par.t_init, par.t_final
% ...
par.t_init = 0 ;
par.t_final = 10 ;


%% Don't change the rest unless you understand how it works
par.t_equil = par.t_init ;
if isinf( dt_anim_rep(1) )
    dt_anim_rep(1) = ( par.t_final - par.t_init ) / dt_anim_rep(2) ;
end
par.dt = dt_anim_rep(1) ;
par.stepT = par.dt / ( ( 1 + floor( par.dt ) ) * par.n_datasample ) ; % sampling time to save data for
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
    for t0_step = par.t_init : dt_anim_rep(1) : par.t_final
        if t0_step == par.t_final ; continue ; end
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
post_proc( t_all , z_all , rjtip_all , par ) ;
pause( 1 )
save( 'code/results/results_sys.mat' ) ; % save workspace

