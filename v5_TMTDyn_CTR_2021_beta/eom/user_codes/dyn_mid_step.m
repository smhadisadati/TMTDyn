function [ z , par_mex ] = dyn_mid_step( t , z , par_mex )

%% inputs positions
q_u = 1 * interp1(par_mex.user_pars.motor_in.pos(:,1), par_mex.user_pars.motor_in.pos(:,2:end), t, 'linear', 0) ;


%% straight part overlapping
l_b0 = [ 166, 208, 0 ] * 1e-3 ; % relaxed state base (straight section) length
l_b2 = par_mex.var(37);
dl2 = max([l_b0(2) - l_b2 + q_u(3), 1e-3]);


%% external forces
% ftau_ex = [ 0 0 0 0 0 0 ] ; % tip load


%% update par
% par_mex.var(end-11:end) = [ ftau_u ftau_ex ] ;
par_mex.var(end-14:end-6) = [ 0 dl2 0 q_u ] ;


