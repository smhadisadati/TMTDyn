function [ z , par_mex ] = dyn_mid_step( t , z , par_mex )

%% inputs positions
q_u = 1 * interp1(par_mex.user_pars.motor_in.pos(:,1), par_mex.user_pars.motor_in.pos(:,2:end), t, 'linear', 0) ;


%% spline segmentation
l_s1 = par_mex.var(40);
l_s3 = par_mex.var(42); % physical bent length
dl1 = l_s1 + q_u(1) - l_s3;
if dl1 < 0; dl1 = 5e-3; end % preventing IC from being cancelled out!


%% catheter kappa_y (I used dl2 as kappa)
kappa = par_mex.var(end-14) ;
q_u(6) = q_u(6) * kappa ;


%% external forces (I used dl3 as f)
l_ex = l_s1 + q_u(5);
f = par_mex.var(end-13) ;
if q_u(5) > 0
    ftau_ex = f * [ 1 0 -1 0 0 0 ] ; % load
else
    ftau_ex = [ 0 0 0 0 0 0 ] ; % load
end
q_u(5) = 0;


%% random
% kappa = par_mex.var(end-14) * sin(2*pi/3*t) ;
% q_u(6) = kappa ;
% l_ex = 0;
% ftau_ex = [ 0 0 0 0 0 0 ] ;


%% update par
par_mex.var(end-15:end) = [ dl1 0 0 q_u ftau_ex l_ex ] ;

