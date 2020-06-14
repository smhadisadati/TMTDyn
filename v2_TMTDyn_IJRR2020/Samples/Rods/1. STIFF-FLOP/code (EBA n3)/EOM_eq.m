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

TMT = zeros(18,18) ; TMfd = zeros(18,1) ;
w_vd_j = zeros(18,1) ; w_sd = zeros(18,1) ; w_in = zeros(18,1) ;
w_f = zeros(18,1) ;
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

s0 = 1e-6 ;
ds = par.rom.mass(3) / par.n_int ;
if par.rom.mass(3) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.mass(3) - s0
    [ M , T , Dd , fg ] = massF3( par.var , z.' , s ) ;
    TMT = TMT + T.' * M * T * ds ;
    TMfd = TMfd + T.' * M * ( - Dd * uq + fg ) * ds ;
end

s0 = 1e-6 ;
ds = par.rom.mass(4) / par.n_int ;
if par.rom.mass(4) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.mass(4) - s0
    [ M , T , Dd , fg ] = massF4( par.var , z.' , s ) ;
    TMT = TMT + T.' * M * T * ds ;
    TMfd = TMfd + T.' * M * ( - Dd * uq + fg ) * ds ;
end

s0 = 1e-6 ;
ds = par.rom.sprdmp(19) / par.n_int ;
if par.rom.sprdmp(19) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.sprdmp(19) - s0
    [ Tt , kx , vd , in ] = sprdmpF19( par.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par.rom.sprdmp(20) / par.n_int ;
if par.rom.sprdmp(20) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.sprdmp(20) - s0
    [ Tt , kx , vd , in ] = sprdmpF20( par.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par.rom.sprdmp(21) / par.n_int ;
if par.rom.sprdmp(21) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.sprdmp(21) - s0
    [ Tt , kx , vd , in ] = sprdmpF21( par.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

[ Ttf , ftau_ex ] = loadsF1( par.var , z.' , 0 ) ;
w_f = w_f + Ttf * ftau_ex ;

% EOM
fval = [ (TMfd + fj_k + fj_in + w_sd + w_in + w_f ) ; dc ] ;
