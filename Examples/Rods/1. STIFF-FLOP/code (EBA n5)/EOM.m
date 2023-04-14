function dz = EOM ( t , z , par )
global t_report
if t > t_report
    t 
    t_report = t + par.t_rep ; 
end
t ;

u = z( par.nq + par.nlambda + 1 : end ) ;
uq = u( 1 : par.nq ) ;

[ z , par ] = int_mid_step( t , z , par ) ;

fj_k = fj_kF( par.var , z.' ) ; 
fj_vd = fj_vdF( par.var , z.' ) ;
fj_in = fj_inF( par.var , z.' ) ;

TMT = zeros(30,30) ; TMfd = zeros(30,1) ;
w_vd_j = zeros(30,1) ; w_sd = zeros(30,1) ; w_in = zeros(30,1) ;
w_f = zeros(30,1) ;
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
ds = par.rom.mass(5) / par.n_int ;
if par.rom.mass(5) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.mass(5) - s0
    [ M , T , Dd , fg ] = massF5( par.var , z.' , s ) ;
    TMT = TMT + T.' * M * T * ds ;
    TMfd = TMfd + T.' * M * ( - Dd * uq + fg ) * ds ;
end

s0 = 1e-6 ;
ds = par.rom.mass(6) / par.n_int ;
if par.rom.mass(6) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.mass(6) - s0
    [ M , T , Dd , fg ] = massF6( par.var , z.' , s ) ;
    TMT = TMT + T.' * M * T * ds ;
    TMfd = TMfd + T.' * M * ( - Dd * uq + fg ) * ds ;
end

s0 = 1e-6 ;
ds = par.rom.sprdmp(31) / par.n_int ;
if par.rom.sprdmp(31) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.sprdmp(31) - s0
    [ Tt , kx , vd , in ] = sprdmpF31( par.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par.rom.sprdmp(32) / par.n_int ;
if par.rom.sprdmp(32) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.sprdmp(32) - s0
    [ Tt , kx , vd , in ] = sprdmpF32( par.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par.rom.sprdmp(33) / par.n_int ;
if par.rom.sprdmp(33) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.sprdmp(33) - s0
    [ Tt , kx , vd , in ] = sprdmpF33( par.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par.rom.sprdmp(34) / par.n_int ;
if par.rom.sprdmp(34) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.sprdmp(34) - s0
    [ Tt , kx , vd , in ] = sprdmpF34( par.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par.rom.sprdmp(35) / par.n_int ;
if par.rom.sprdmp(35) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.sprdmp(35) - s0
    [ Tt , kx , vd , in ] = sprdmpF35( par.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

[ Ttf , ftau_ex ] = loadsF1( par.var , z.' , 0 ) ;
w_f = w_f + Ttf * ftau_ex ;

% EOM
TMT = [ TMT , Tc.' ; Tc , zeros(0,0) ] ;
d_eom = [ ( TMfd + fj_k + fj_vd + fj_in + w_sd + w_in + w_vd_j + w_f ) ; dc ] ;
dzt = TMT \ d_eom ;

dz = [ u ; dzt ];