function [ z , par_mex ] = dyn_mid_step( t , z , par_mex )

%% parameters
...

%% inputs: internal pressure & external forces/torques
% temp = interp1( par.f_ex(:,1) , [ par.f_ex(:,2:7) par.p(:,2:4) ] , t , 'nearest' ) ;
step = floor( t / 0.05 ) ;
if step == 0 ; step = 1 ; end
ftau_ex = par_mex.user_pars.f_ex(step,2:7) ;
temp = par_mex.user_pars.p(step,2:4) ;
p = temp([ 1 1 2 2 3 3 ]) ;


%% sample desired trajectory and it's derivatives
l_s = par_mex(5) ;
l_f = par_mex(17) ;
xyz_d = [ 0, 0, l_s+l_f ] + 5e-3 * sin( 2*pi * t ) ;
dxyz_d = 5e-3 * 2*pi/5 * cos( 2*pi/5 * t ) ;
ddxyz_d = - 5e-3 * ( 2*pi/5 )^2 * sin( 2*pi/5 * t ) ;

%% cross-section deformation
% In this case it causes numerical instability, so commented
lambda = 1 ; % axial stretch
% l = 0 ;
% for i = 0 : par_mex.user_pars.n_l - 2
%     l = l + z(i*6+3) ;
% end
% lambda = 1 + l / par_mex.var(5) ;


%% update simulation parameters
par_mex.var(end-9:end) = [ lambda xyz_d dxyz_d ddxyz_d ] ;