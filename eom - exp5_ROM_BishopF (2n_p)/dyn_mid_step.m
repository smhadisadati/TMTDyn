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


%% cross-section deformation
% In this case it causes numerical instability, so commented
lambda = 1 ;
% s0 = 1e-6 ; l = 0 ;
% ds = par_mex.var(5) / 1e1 ;
% for s = s0 : ds : par_mex.var(5) - s0
%     [ ~ , ~ , ~ , ~ , ~ , ~ , dl ] = sprdmpF19( par_mex.var , z , s , 0 , 0 ) ;
%     l = l + dl(3) * ds ;
% end
% lambda = l / par_mex.var(5) ;


%% update simulation parameters
par_mex.var(end-12:end) = [ p ftau_ex lambda ] ;