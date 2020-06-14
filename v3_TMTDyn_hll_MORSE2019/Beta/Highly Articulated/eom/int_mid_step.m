function [ z , par_mex ] = int_mid_step( t , z , par_mex )
% % lengths
% n_r = 2; % par_mex.user_pars(1);
% i_u = 1+(n_r+1)+3*(n_r-1)+4*n_r+n_r + 1;
% dl_s1 = z(1);
% % dl_s2 = z(i_u(1));
% 
% % inputs
% freq = [2, 2] * pi;
% ddq = [ -1e-3*freq(1)^2*sin( freq(1) * t ), -pi/2*freq(2)^2*sin( freq(2) * t ) ];
% ftau_u = [ ddq -ddq ddq ] ; % [z1, theta1, z2, theta2, z3, theta3] % actuator inputs
% 
% % external forces
% ftau_ex = [ 0 0 0 0 0 0 ] ; % tip load
% 
% % update par
% par_mex.var(end-13:end) = [ dl_s1 0 ftau_u ftau_ex ] ;
% % par_mex.var(end-13:end) = [ dl_s1 dl_s2 ftau_u ftau_ex ] ;
