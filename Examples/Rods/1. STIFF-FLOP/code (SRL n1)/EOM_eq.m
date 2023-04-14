function fval = EOM_eq ( z )
global par_i
par = par_i ;
z = [ z 0*z ]' ;

u = z( par.nq + par.nlambda + 1 : end ) ;
uq = u( 1 : par.nq ) ;

par = int_mid_step( par.t_equil_i , z , par ) ;

fj_k = fj_kF( par.var , z.' ) ; 
fj_vd = fj_vdF( par.var , z.' ) ;
fj_in = fj_inF( par.var , z.' ) ;

TMT = zeros(6,6) ; TMfd = zeros(6,1) ;
w_vd_j = zeros(6,1) ; w_sd = zeros(6,1) ; w_in = zeros(6,1) ;
w_f = zeros(6,1) ;
Tc = [] ; dc = [] ;

s0 = 1e-6 ;
ds = par.rom.mass(1) / par.n_int ;
if par.rom.mass(1) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.mass(1) - s0
    [ M , T , Dd , fg ] = massF1( par.var , z.' , s ) ;
    TMT = TMT + T.' * M * T * ds ;
    TMfd = TMfd + T.' * M * ( - Dd * uq + fg ) * ds ;
end

s0 = 1e-6 ;
ds = par.rom.mass(2) / par.n_int ;
if par.rom.mass(2) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.mass(2) - s0
    [ M , T , Dd , fg ] = massF2( par.var , z.' , s ) ;
    TMT = TMT + T.' * M * T * ds ;
    TMfd = TMfd + T.' * M * ( - Dd * uq + fg ) * ds ;
end

[ Ttf , ftau_ex ] = loadsF1( par.var , z.' , 0 ) ;
w_f = w_f + Ttf * ftau_ex ;

% EOM
fval = [ (TMfd + fj_k + fj_in + w_sd + w_in + w_f ) ; dc ] ;
