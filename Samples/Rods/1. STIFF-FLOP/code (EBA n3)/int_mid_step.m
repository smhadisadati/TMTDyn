function par = int_mid_step( t , z , par )

lambda = 1 ;
% l = 0 ;
% [ ~ , ~ , ~ , ~ , dl ] = sprdmpF19( par.var , z.' , 0 ) ; l = l + dl ; % 6 * n_s + 1 : n_sd = 6 * n_s + n_s
% [ ~ , ~ , ~ , ~ , dl ] = sprdmpF20( par.var , z.' , 0 ) ; l = l + dl ; % 6 * n_s + 1 : n_sd = 6 * n_s + n_s
% [ ~ , ~ , ~ , ~ , dl ] = sprdmpF21( par.var , z.' , 0 ) ; l = l + dl ; % 6 * n_s + 1 : n_sd = 6 * n_s + n_s
% lambda = 1 + l / par.var(5) ; 

% input p & ext. forces
% temp = interp1( par.f_ex(:,1) , [ par.f_ex(:,2:7) par.p(:,2:4) ] , t , 'nearest' ) ;
step = floor( t / 0.05 ) ;
ftau_ex = par.f_ex(step,2:7) ;
temp = par.p(step,2:4) ;
p = temp([ 1 1 2 2 3 3 ]) ;
par.var(end-12:end) = [ p ftau_ex lambda ] ;
