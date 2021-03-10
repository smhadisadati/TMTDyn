 function [ z , par_mex ] = static_mid_step( t , z , par_mex )

%% inputs
% equil
q_u = 1 * interp1(par_mex.user_pars.motor_in.pos(:,1), par_mex.user_pars.motor_in.pos(:,2:end), t, 'linear', 0);
% ftau_u = q_u ; % motor_in


%% external forces
% ftau_ex = [ 0 0 0 0 0 0 ] ; % tip load


%% update par
% par_mex.var(end-11:end) = [ ftau_u ftau_ex ] ;
par_mex.var(end-11:end-6) = q_u ;
