 function [ z , par_mex ] = static_mid_step( t , z , par_mex )

%% inputs
% equil
q_u = 1 * interp1(par_mex.user_pars.motor_in.pos(:,1), par_mex.user_pars.motor_in.pos(:,2:end), t);
% ftau_u = q_u ; % motor_in

% catheter kappa_y
q_u(6) = 1e-2;

%% external forces
% ftau_ex = [ 0 0 0 0 0 0 ] ; % tip load


%% update par
par_mex.var(end-11:end-6) = q_u ;
