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

TMT = zeros(24,24) ; TMfd = zeros(24,1) ;
w_vd_j = zeros(24,1) ; w_sd = zeros(24,1) ; w_in = zeros(24,1) ;
w_f = zeros(24,1) ;
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
ds = par.rom.sprdmp(25) / par.n_int ;
if par.rom.sprdmp(25) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.sprdmp(25) - s0
    [ Tt , kx , vd , in ] = sprdmpF25( par.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par.rom.sprdmp(26) / par.n_int ;
if par.rom.sprdmp(26) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.sprdmp(26) - s0
    [ Tt , kx , vd , in ] = sprdmpF26( par.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par.rom.sprdmp(27) / par.n_int ;
if par.rom.sprdmp(27) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.sprdmp(27) - s0
    [ Tt , kx , vd , in ] = sprdmpF27( par.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par.rom.sprdmp(28) / par.n_int ;
if par.rom.sprdmp(28) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.sprdmp(28) - s0
    [ Tt , kx , vd , in ] = sprdmpF28( par.var , z.' , s ) ;
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