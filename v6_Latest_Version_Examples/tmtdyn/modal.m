function [ Phi_modal , M_modal , K_modal , V_modal , omega , xi , par ] = modal( z0 , par )
global par_mex
fprintf( 'linear modal analysis... \n' )
par.elapsed_time = [ par.elapsed_time toc( par.timer ) ] ;
toc( par.timer )

[ par.nq , par.nlambda , par.ngamma , par.qf0 , par.n_m , par.n_sd , par.n_cn , par.n_co , par.n_ex ] = nqF( par.var ) ; % states' number and init. value

eps = [ 1e-6 1e-6 ] ; % for singularity prevention
if isempty( z0 ) % check if z0 is provided
    z0 = [ eps(1)+double( par.qf0 ) eps(1)*ones( 1 , par.nlambda ) eps(1)*ones( 1 , par.ngamma ) eps(2)*ones( 1 , par.nq ) eps(2)*ones( 1 , par.nlambda ) eps(2)*ones( 1 , par.ngamma ) ] ; % initial condition
end

if par.t_equil_i == par.t_equil(1) % && par.derive  % drive EOM_mex
    par = save_modal_mex( z0 , par ) ;
end
par_mex = par.par_mex ;
par_mex.t_equil_i = par.t_equil_i ;

modalfun = @EOM_modal ;
if ismember( par.modal , [2, 3, 4] )
	modalfun = @EOM_modal_mex ;
end

% linear terms in state space
[ TMT , TKT , TVT ] = modalfun( z0(1:end/2) ) ;

% modal analysis
[ Phi_modal , Omega_modal ] = eig( - TMT \ TKT ) ;
i_plot = 0 ;
figure( par.figmod ) ;
omega = sqrt( diag( Omega_modal ) ) ;

% modal damping
M_modal = Phi_modal.' * TMT * Phi_modal ;
K_modal = Phi_modal.' * TKT * Phi_modal ;
V_modal = Phi_modal.' * TVT * Phi_modal ;
xi = 0.5 * ( Omega_modal * M_modal ) \ V_modal ;

% plots
number_of_natural_frequencies = numel( omega )
[ ~ , omega_index ] = sort( omega ) ; % ascending freq.
for i = omega_index'
    [ ~ , temp ] = max( abs( Phi_modal(:,i) ) ) ;
    [ i omega( i ) ]
    clf
    amp_modal = Phi_modal(:,i)' ;
    z_modal_norm = z0(1:end/2) + amp_modal / max( abs( amp_modal ) ) * 1e-1 ;
    z = [ z_modal_norm 0*z_modal_norm ] ;
    anim( 0 , z , par ) ;
    pause( 1e-1 )
end

par.par_mex = par_mex ;

