function [ z , par_mex ] = dyn_mid_step( t , z , par_mex )

%% inputs positions
q_u = interp1(par_mex.user_pars.motor_in.pos(:,1), par_mex.user_pars.motor_in.pos(:,2:end), t, 'linear', 0) ;

%% curvature inputs
d_ow = par_mex.var(9) + par_mex.var(10) ; % wire offsets diameter: 2*(r_s21+r_s22)/2
l_s2 = par_mex.var(17);
l_w = q_u(1:4) + l_s2; 

% % 3 tendons
% kappa = 2*sqrt(l(1)^2+l(2)^2+l(3)^2-l(1)*l(2)-l(1)*l(3)-l(2)*l(3))/(d*(l(1)+l(2)+l(3)));
% phi = atan2(sqrt(3)*(l(2)+l(3)-2*l(1)),(3*(l(2)-l(3))));

% 4 tendons
l_b = ( l_w(1) + l_w(2) + l_w(3) + l_w(4) ) / 4;
% l_b = l_s2;
phi = atan2(l_w(2)-l_b,l_w(1)-l_b);
kappa = ( l_b - l_w(1) ) / ( l_b * d_ow/2 * cos(phi) ) ;
% model inputs
kappa_x = kappa * sin( phi );
kappa_y = kappa * cos( phi );

%% inner (introducer) tube lengths
dl = q_u(5);

%% update par
% vars = [ sigma_s1_sym sigma_s2_sym E_s1_sym E_s2_sym G_s1_sym G_s2_sym ...
%     r_s11_sym r_s12_sym r_s21_sym r_s22_sym ...
%     mu_x1_sym mu_y1_sym mu_z1_sym mu_xx1_sym mu_yy1_sym mu_zz1_sym ...
%     mu_x2_sym mu_y2_sym mu_z2_sym mu_xx2_sym mu_yy2_sym mu_zz2_sym ...
%     mu_pow_sym g_xsym g_ysym g_zsym ...
%     l_s1_sym l_s2_sym dl_sym kappa_x_sym kappa_y_sym ...
%     f_tx_sym f_ty_sym f_tz_sym tau_tx_sym tau_ty_sym tau_tz_sym ] ;
par_mex.var(end-8:end-6) = [ dl kappa_x kappa_y ] ;

