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

TMT = zeros(106,106) ; TMfd = zeros(106,1) ;
w_vd_j = zeros(106,1) ; w_sd = zeros(106,1) ; w_in = zeros(106,1) ;
w_f = zeros(106,1) ;
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
ds = par.rom.mass(7) / par.n_int ;
if par.rom.mass(7) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.mass(7) - s0
    [ M , T , Dd , fg ] = massF7( par.var , z.' , s ) ;
    TMT = TMT + T.' * M * T * ds ;
    TMfd = TMfd + T.' * M * ( - Dd * uq + fg ) * ds ;
end

s0 = 1e-6 ;
ds = par.rom.mass(8) / par.n_int ;
if par.rom.mass(8) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.mass(8) - s0
    [ M , T , Dd , fg ] = massF8( par.var , z.' , s ) ;
    TMT = TMT + T.' * M * T * ds ;
    TMfd = TMfd + T.' * M * ( - Dd * uq + fg ) * ds ;
end

s0 = 1e-6 ;
ds = par.rom.mass(9) / par.n_int ;
if par.rom.mass(9) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.mass(9) - s0
    [ M , T , Dd , fg ] = massF9( par.var , z.' , s ) ;
    TMT = TMT + T.' * M * T * ds ;
    TMfd = TMfd + T.' * M * ( - Dd * uq + fg ) * ds ;
end

s0 = 1e-6 ;
ds = par.rom.mass(10) / par.n_int ;
if par.rom.mass(10) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.mass(10) - s0
    [ M , T , Dd , fg ] = massF10( par.var , z.' , s ) ;
    TMT = TMT + T.' * M * T * ds ;
    TMfd = TMfd + T.' * M * ( - Dd * uq + fg ) * ds ;
end

s0 = 1e-6 ;
ds = par.rom.mass(11) / par.n_int ;
if par.rom.mass(11) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.mass(11) - s0
    [ M , T , Dd , fg ] = massF11( par.var , z.' , s ) ;
    TMT = TMT + T.' * M * T * ds ;
    TMfd = TMfd + T.' * M * ( - Dd * uq + fg ) * ds ;
end

s0 = 1e-6 ;
ds = par.rom.mass(12) / par.n_int ;
if par.rom.mass(12) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.mass(12) - s0
    [ M , T , Dd , fg ] = massF12( par.var , z.' , s ) ;
    TMT = TMT + T.' * M * T * ds ;
    TMfd = TMfd + T.' * M * ( - Dd * uq + fg ) * ds ;
end

s0 = 1e-6 ;
ds = par.rom.mass(13) / par.n_int ;
if par.rom.mass(13) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.mass(13) - s0
    [ M , T , Dd , fg ] = massF13( par.var , z.' , s ) ;
    TMT = TMT + T.' * M * T * ds ;
    TMfd = TMfd + T.' * M * ( - Dd * uq + fg ) * ds ;
end

s0 = 1e-6 ;
ds = par.rom.mass(14) / par.n_int ;
if par.rom.mass(14) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.mass(14) - s0
    [ M , T , Dd , fg ] = massF14( par.var , z.' , s ) ;
    TMT = TMT + T.' * M * T * ds ;
    TMfd = TMfd + T.' * M * ( - Dd * uq + fg ) * ds ;
end

s0 = 1e-6 ;
ds = par.rom.mass(15) / par.n_int ;
if par.rom.mass(15) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.mass(15) - s0
    [ M , T , Dd , fg ] = massF15( par.var , z.' , s ) ;
    TMT = TMT + T.' * M * T * ds ;
    TMfd = TMfd + T.' * M * ( - Dd * uq + fg ) * ds ;
end

s0 = 1e-6 ;
ds = par.rom.mass(16) / par.n_int ;
if par.rom.mass(16) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.mass(16) - s0
    [ M , T , Dd , fg ] = massF16( par.var , z.' , s ) ;
    TMT = TMT + T.' * M * T * ds ;
    TMfd = TMfd + T.' * M * ( - Dd * uq + fg ) * ds ;
end

s0 = 1e-6 ;
ds = par.rom.sprdmp(107) / par.n_int ;
if par.rom.sprdmp(107) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.sprdmp(107) - s0
    [ Tt , kx , vd , in ] = sprdmpF107( par.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par.rom.sprdmp(108) / par.n_int ;
if par.rom.sprdmp(108) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.sprdmp(108) - s0
    [ Tt , kx , vd , in ] = sprdmpF108( par.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par.rom.sprdmp(109) / par.n_int ;
if par.rom.sprdmp(109) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.sprdmp(109) - s0
    [ Tt , kx , vd , in ] = sprdmpF109( par.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par.rom.sprdmp(110) / par.n_int ;
if par.rom.sprdmp(110) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.sprdmp(110) - s0
    [ Tt , kx , vd , in ] = sprdmpF110( par.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par.rom.sprdmp(111) / par.n_int ;
if par.rom.sprdmp(111) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.sprdmp(111) - s0
    [ Tt , kx , vd , in ] = sprdmpF111( par.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par.rom.sprdmp(112) / par.n_int ;
if par.rom.sprdmp(112) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.sprdmp(112) - s0
    [ Tt , kx , vd , in ] = sprdmpF112( par.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par.rom.sprdmp(113) / par.n_int ;
if par.rom.sprdmp(113) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.sprdmp(113) - s0
    [ Tt , kx , vd , in ] = sprdmpF113( par.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par.rom.sprdmp(114) / par.n_int ;
if par.rom.sprdmp(114) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.sprdmp(114) - s0
    [ Tt , kx , vd , in ] = sprdmpF114( par.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par.rom.sprdmp(115) / par.n_int ;
if par.rom.sprdmp(115) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.sprdmp(115) - s0
    [ Tt , kx , vd , in ] = sprdmpF115( par.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par.rom.sprdmp(116) / par.n_int ;
if par.rom.sprdmp(116) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.sprdmp(116) - s0
    [ Tt , kx , vd , in ] = sprdmpF116( par.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par.rom.sprdmp(117) / par.n_int ;
if par.rom.sprdmp(117) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.sprdmp(117) - s0
    [ Tt , kx , vd , in ] = sprdmpF117( par.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par.rom.sprdmp(118) / par.n_int ;
if par.rom.sprdmp(118) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.sprdmp(118) - s0
    [ Tt , kx , vd , in ] = sprdmpF118( par.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par.rom.sprdmp(119) / par.n_int ;
if par.rom.sprdmp(119) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.sprdmp(119) - s0
    [ Tt , kx , vd , in ] = sprdmpF119( par.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par.rom.sprdmp(120) / par.n_int ;
if par.rom.sprdmp(120) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.sprdmp(120) - s0
    [ Tt , kx , vd , in ] = sprdmpF120( par.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par.rom.sprdmp(121) / par.n_int ;
if par.rom.sprdmp(121) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.sprdmp(121) - s0
    [ Tt , kx , vd , in ] = sprdmpF121( par.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par.rom.sprdmp(122) / par.n_int ;
if par.rom.sprdmp(122) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.sprdmp(122) - s0
    [ Tt , kx , vd , in ] = sprdmpF122( par.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par.rom.sprdmp(123) / par.n_int ;
if par.rom.sprdmp(123) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.sprdmp(123) - s0
    [ Tt , kx , vd , in ] = sprdmpF123( par.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par.rom.sprdmp(124) / par.n_int ;
if par.rom.sprdmp(124) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.sprdmp(124) - s0
    [ Tt , kx , vd , in ] = sprdmpF124( par.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par.rom.sprdmp(125) / par.n_int ;
if par.rom.sprdmp(125) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.sprdmp(125) - s0
    [ Tt , kx , vd , in ] = sprdmpF125( par.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par.rom.sprdmp(126) / par.n_int ;
if par.rom.sprdmp(126) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.sprdmp(126) - s0
    [ Tt , kx , vd , in ] = sprdmpF126( par.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par.rom.sprdmp(127) / par.n_int ;
if par.rom.sprdmp(127) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.sprdmp(127) - s0
    [ Tt , kx , vd , in ] = sprdmpF127( par.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par.rom.sprdmp(128) / par.n_int ;
if par.rom.sprdmp(128) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.sprdmp(128) - s0
    [ Tt , kx , vd , in ] = sprdmpF128( par.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par.rom.sprdmp(129) / par.n_int ;
if par.rom.sprdmp(129) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.sprdmp(129) - s0
    [ Tt , kx , vd , in ] = sprdmpF129( par.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par.rom.sprdmp(130) / par.n_int ;
if par.rom.sprdmp(130) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par.rom.sprdmp(130) - s0
    [ Tt , kx , vd , in ] = sprdmpF130( par.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

[ tc , Dc , in ] = cnstF1( par.var , z.' , 0 ) ;
Tc = [ Tc ; tc ] ;
dc = [ dc ; - Dc * uq + in ] ;

[ tc , Dc , in ] = cnstF2( par.var , z.' , 0 ) ;
Tc = [ Tc ; tc ] ;
dc = [ dc ; - Dc * uq + in ] ;

[ tc , Dc , in ] = cnstF3( par.var , z.' , 0 ) ;
Tc = [ Tc ; tc ] ;
dc = [ dc ; - Dc * uq + in ] ;

[ tc , Dc , in ] = cnstF4( par.var , z.' , 0 ) ;
Tc = [ Tc ; tc ] ;
dc = [ dc ; - Dc * uq + in ] ;

[ tc , Dc , in ] = cnstF5( par.var , z.' , 0 ) ;
Tc = [ Tc ; tc ] ;
dc = [ dc ; - Dc * uq + in ] ;

[ tc , Dc , in ] = cnstF6( par.var , z.' , 0 ) ;
Tc = [ Tc ; tc ] ;
dc = [ dc ; - Dc * uq + in ] ;

[ tc , Dc , in ] = cnstF7( par.var , z.' , 0 ) ;
Tc = [ Tc ; tc ] ;
dc = [ dc ; - Dc * uq + in ] ;

[ tc , Dc , in ] = cnstF8( par.var , z.' , 0 ) ;
Tc = [ Tc ; tc ] ;
dc = [ dc ; - Dc * uq + in ] ;

[ tc , Dc , in ] = cnstF9( par.var , z.' , 0 ) ;
Tc = [ Tc ; tc ] ;
dc = [ dc ; - Dc * uq + in ] ;

[ tc , Dc , in ] = cnstF10( par.var , z.' , 0 ) ;
Tc = [ Tc ; tc ] ;
dc = [ dc ; - Dc * uq + in ] ;

[ tc , Dc , in ] = cnstF11( par.var , z.' , 0 ) ;
Tc = [ Tc ; tc ] ;
dc = [ dc ; - Dc * uq + in ] ;

[ tc , Dc , in ] = cnstF12( par.var , z.' , 0 ) ;
Tc = [ Tc ; tc ] ;
dc = [ dc ; - Dc * uq + in ] ;

% EOM
TMT = [ TMT , Tc.' ; Tc , zeros(12,12) ] ;
d_eom = [ ( TMfd + fj_k + fj_vd + fj_in + w_sd + w_in + w_vd_j + w_f ) ; dc ] ;
dzt = TMT \ d_eom ;

dz = [ u ; dzt ];