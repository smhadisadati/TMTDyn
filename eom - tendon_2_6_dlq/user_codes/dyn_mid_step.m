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

%% introducer load
f_t = interp1(par_mex.user_pars.tip_load(:,1), par_mex.user_pars.tip_load(:,2:end), t, 'linear', 0) ;

l_s = par_mex.var(16:17);
if f_t(4) == 1 % at introducer tip
    l_ex = l_s(1) + dl ;
else % f_t(4) == 2, at catheter tip
    l_ex = l_s(2) ;
end

%% update par
par_mex.var(end-9:end-3) = [ l_ex dl kappa_x kappa_y f_t(1:3) ] ;

