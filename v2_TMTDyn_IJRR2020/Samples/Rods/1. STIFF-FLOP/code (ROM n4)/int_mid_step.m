function [ z , par ] = int_mid_step( t , z , par )

lambda = 1 ;
s0 = 1e-6 ; l = 0 ; i = par.n_sd ;
ds = par.rom.sprdmp(i) / par.n_int ;
if par.rom.sprdmp(i) == 0 ; ds = 1 ; end
for s = s0 : ds : par.rom.sprdmp(i) - s0
    [ ~ , ~ , ~ , ~ , dl ] = sprdmpF25( par.var , z.' , s ) ; % n_r * 6 + 1
    l = l + dl(3) * ds ;
end
lambda = l / par.var(5) ;

% input p & ext. forces
% temp = interp1( par.f_ex(:,1) , [ par.f_ex(:,2:7) par.p(:,2:4) ] , t , 'nearest' ) ;
step = floor( t / 0.05 ) ;
ftau_ex = par.f_ex(step,2:7) ;
temp = par.p(step,2:4) ;
p = temp([ 1 1 2 2 3 3 ]) ;
par.var(end-12:end) = [ p ftau_ex lambda ] ;
