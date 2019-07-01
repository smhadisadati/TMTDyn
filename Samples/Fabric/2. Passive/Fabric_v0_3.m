%% initialize

clc
clear all
% close all
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
% study specific parameters
par.exp_case = 2 ; % [ exp_case start_exp_sequence end_exp_sequence ]

% derivation
par.derive = 0 ; % set 1 to rederive in TMT
par.derive_collect = 1 ; % collect in 1: single struct., 2: seperte struct.s, 3: seperate func.s, 4: C func.s
par.derive_mex = 0 ; % use Matlab codegen, automatically sets par.derive_collect = 1
par.opv = true ; % optimize results

% controls
par.anim = 1 ; % animation on (1) or off (0)
par.movie = 0 ; % save movie[ ~ , rks , par ] = AnimEOM_mex( t , z , par );
par.equil = 0 ; % 1: static analysis with Matlab func.s, 2: with C-mex func.s, 3: to used latest genarated C-Mex file
par.modal = 0 ; % 1: linear modal analysis with Matlab func.s, 2: with C-mex func.s
par.simdyn = 3 ; % 1: dyn. sim. with Matlab func.s, 2: with C-mex func.s, 3: to used latest genarated C-Mex file

% other parameters
par.t_rep = 5e-1 ; % sim report time
par.n_int = 100 ; % number of integration steps
par.n_animpoints = 50 ; % number of anim points
par.n_datasample = 50 ; % number of saved data samples
dt_anim_rep = [ inf 1 ] ; % anim report time, if 'inf' then (tf-t0)/dt_animStep(2)

% variables
if par.derive == 1
    syms E_sym mu_pow_sym mu_v_sym mu_u_sym phi_sym mu_link_sym
    par.sym = [ E_sym mu_pow_sym mu_v_sym mu_u_sym phi_sym mu_link_sym ] ;
assume( par.var , 'real' ) ;
else
    E_sym = 0 ; mu_pow_sym = 0 ; mu_v_sym = 0 ; mu_u_sym = 0 ; phi_sym = 0 ; mu_link_sym = 0 ;
end


%% parameters
l_xz2 = 73e-3 / 5 ;
l_y2 = 0.8e-3 ;
m_2 = 36e-3 / 15 ;

l_x1 = 76e-3 / 2 ;
l_z1 = 30e-3 ;
l_com1 = 135e-3 ;

g = 9.81 ; % gravity

% EBA
E = 1.5e3 ;
mu_pow = 1 ; % < 1: rate thining, > 1: rate thikening
mu_v = 5e1 ;
mu_u = 5e1;
mu_link = 7e-4 ;

phi = - 85 * pi/ 180 ;
 
par.var = [ E mu_pow mu_v mu_u phi mu_link ] ;
par.var2 = [ l_xz2 l_y2 l_x1 l_z1 l_com1 ] ;


%% derivation simplification
% ...


%% preprocess
G = E_sym / 3 ;
I_2 = 1 / 12 * m_2 * ...
    diag( [ l_y2^2+l_xz2^2 l_xz2^2+l_xz2^2 l_xz2^2+l_y2^2 ] ) ;
J_2 = 1 / 12 * [ l_xz2*l_y2^3 l_xz2^3*l_y2 l_xz2*l_y2^3+l_xz2^3*l_y2 ] ;
a_xy2 = l_xz2 * l_y2 ;
K_v = diag( [ G G E_sym ] ) * a_xy2 / l_xz2 ;
K_u = diag( [ E_sym E_sym G ] ) * diag( J_2 ) / l_xz2 ;


%% system geomety
% EB
world.g = [ 0 0 -g ] ; % gravity vector

% arm
body(1).m = m_2 ;
body(1).l_com = [ 0 0 -l_com1 ] ;
joint(1).second = 1 ;
joint(1).tr.rot = [ 2 inf ] ;
joint(1).dof.init = phi_sym ;
joint(1).dof.damp.visc = mu_link_sym ;

% mesh import
mesh.file_name = 'exp/exp2.iges' ;
mesh.tol = 1e-3 ; % import tolerance
mesh.tr(1).trans = [ 0 0 0 ] ;
mesh.tr(1).rot = [ 2 phi_sym ] ;
mesh.tr(2).trans = [ 0 0 -l_z1 ] ;
mesh.tr(2).rot = [ 0 0 ] ;

% fabric mass
mesh.body.m = m_2 ;
mesh.body.I = I_2 ;
mesh.joint(1).tr.trans = [ inf inf inf ] ;
mesh.joint(1).tr.rot = [ 0 inf inf inf ] ;

% fabric EBA
mesh.joint(2).spring.coeff = [ diag( K_v ).' diag( K_u ).' ] ;
% mesh.joint(2).spring.init = [ 0 0 nan 0 0 0 ] ;
mesh.joint(2).spring.init = [ nan nan nan nan nan nan ] ;
mesh.joint(2).damp.visc = [ mu_v_sym*ones(1,3) mu_u_sym*ones(1,3) ] ;
mesh.joint(2).damp.pow = mu_pow_sym ; % power law index

% fabric clips constraints
joint(2).first = 1 ;
joint(2).second = 16 ; % you have to know the mass number in mesh
joint(2).tr.trans = [ l_x1 0 -l_z1 ] ;
joint(2).fixed = ones(1,6) ;

joint(3).first = 1 ;
joint(3).second = 14 ;
joint(3).tr.trans = [ -l_x1 0 -l_z1 ] ;
joint(3).fixed = ones(1,6) ;

% tip external load
exload = [] ;
        

%% EOM:
if par.derive == 1
    [ qf , uf , lambdaf , par ] = tmt_eom_derive ( par , world , body , joint , exload , mesh );
end


%% axp. inputs
par = exp_v0_1( par ) ;


%% numerical simulation & animation
% sim pars:
par.t_init = par.t_exp(1) ;
par.t_final = par.t_exp(end) ;

par.t_equil = par.t_init ;
if isinf( dt_anim_rep(1) )
    dt_anim_rep(1) = ( par.t_final - par.t_init ) / dt_anim_rep(2) ;
end
par.dt = dt_anim_rep(1) ;
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

