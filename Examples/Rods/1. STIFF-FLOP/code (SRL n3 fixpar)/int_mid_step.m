function [ z , par ] = int_mid_step( t , z , par )

lambda = 1 ;
% l = 0 ;
% for i = 0 : par.n_m - 2
%     l = l + z(i*6+3) ;
% end
% lambda = 1 + l / par.var(5) ;

% input p & ext. forces
% temp = interp1( par.f_ex(:,1) , [ par.f_ex(:,2:7) par.p(:,2:4) ] , t , 'nearest' ) ;
step = floor( t / 0.05 ) ;
ftau_ex = par.f_ex(step,2:7) ;
temp = par.p(step,2:4) ;
p = temp([ 1 1 2 2 3 3 ]) ;
par.var(end-12:end) = [ p ftau_ex lambda ] ;
