function dz = EOM ( t , z )
global t_report par_mex
if t > t_report
    t 
    t_report = t + par_mex.t_rep ; 
end
t ;

u = z( par_mex.nq + par_mex.nlambda + 1 : end ) ;
uq = u( 1 : par_mex.nq ) ;

[ z , par_mex ] = int_mid_step( t , z , par_mex ) ;

fj_k = fj_kF( par_mex.var , z.' ) ; 
fj_vd = fj_vdF( par_mex.var , z.' ) ;
fj_in = fj_inF( par_mex.var , z.' ) ;

TMT = zeros(106,106) ; TMfd = zeros(106,1) ;
w_vd_j = zeros(106,1) ; w_sd = zeros(106,1) ; w_in = zeros(106,1) ;
w_f = zeros(106,1) ;
Tc = [] ; dc = [] ;

s0 = 1e-6 ;
ds = par_mex.rom.mass(1) / par_mex.n_int ;
if par_mex.rom.mass(1) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.mass(1) - s0
    [ M , T , Dd , fg ] = massF1( par_mex.var , z.' , s ) ;
    TMT = TMT + T.' * M * T * ds ;
    TMfd = TMfd + T.' * M * ( - Dd * uq + fg ) * ds ;
end

s0 = 1e-6 ;
ds = par_mex.rom.mass(2) / par_mex.n_int ;
if par_mex.rom.mass(2) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.mass(2) - s0
    [ M , T , Dd , fg ] = massF2( par_mex.var , z.' , s ) ;
    TMT = TMT + T.' * M * T * ds ;
    TMfd = TMfd + T.' * M * ( - Dd * uq + fg ) * ds ;
end

s0 = 1e-6 ;
ds = par_mex.rom.mass(3) / par_mex.n_int ;
if par_mex.rom.mass(3) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.mass(3) - s0
    [ M , T , Dd , fg ] = massF3( par_mex.var , z.' , s ) ;
    TMT = TMT + T.' * M * T * ds ;
    TMfd = TMfd + T.' * M * ( - Dd * uq + fg ) * ds ;
end

s0 = 1e-6 ;
ds = par_mex.rom.mass(4) / par_mex.n_int ;
if par_mex.rom.mass(4) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.mass(4) - s0
    [ M , T , Dd , fg ] = massF4( par_mex.var , z.' , s ) ;
    TMT = TMT + T.' * M * T * ds ;
    TMfd = TMfd + T.' * M * ( - Dd * uq + fg ) * ds ;
end

s0 = 1e-6 ;
ds = par_mex.rom.mass(5) / par_mex.n_int ;
if par_mex.rom.mass(5) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.mass(5) - s0
    [ M , T , Dd , fg ] = massF5( par_mex.var , z.' , s ) ;
    TMT = TMT + T.' * M * T * ds ;
    TMfd = TMfd + T.' * M * ( - Dd * uq + fg ) * ds ;
end

s0 = 1e-6 ;
ds = par_mex.rom.mass(6) / par_mex.n_int ;
if par_mex.rom.mass(6) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.mass(6) - s0
    [ M , T , Dd , fg ] = massF6( par_mex.var , z.' , s ) ;
    TMT = TMT + T.' * M * T * ds ;
    TMfd = TMfd + T.' * M * ( - Dd * uq + fg ) * ds ;
end

s0 = 1e-6 ;
ds = par_mex.rom.mass(7) / par_mex.n_int ;
if par_mex.rom.mass(7) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.mass(7) - s0
    [ M , T , Dd , fg ] = massF7( par_mex.var , z.' , s ) ;
    TMT = TMT + T.' * M * T * ds ;
    TMfd = TMfd + T.' * M * ( - Dd * uq + fg ) * ds ;
end

s0 = 1e-6 ;
ds = par_mex.rom.mass(8) / par_mex.n_int ;
if par_mex.rom.mass(8) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.mass(8) - s0
    [ M , T , Dd , fg ] = massF8( par_mex.var , z.' , s ) ;
    TMT = TMT + T.' * M * T * ds ;
    TMfd = TMfd + T.' * M * ( - Dd * uq + fg ) * ds ;
end

s0 = 1e-6 ;
ds = par_mex.rom.mass(9) / par_mex.n_int ;
if par_mex.rom.mass(9) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.mass(9) - s0
    [ M , T , Dd , fg ] = massF9( par_mex.var , z.' , s ) ;
    TMT = TMT + T.' * M * T * ds ;
    TMfd = TMfd + T.' * M * ( - Dd * uq + fg ) * ds ;
end

s0 = 1e-6 ;
ds = par_mex.rom.mass(10) / par_mex.n_int ;
if par_mex.rom.mass(10) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.mass(10) - s0
    [ M , T , Dd , fg ] = massF10( par_mex.var , z.' , s ) ;
    TMT = TMT + T.' * M * T * ds ;
    TMfd = TMfd + T.' * M * ( - Dd * uq + fg ) * ds ;
end

s0 = 1e-6 ;
ds = par_mex.rom.mass(11) / par_mex.n_int ;
if par_mex.rom.mass(11) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.mass(11) - s0
    [ M , T , Dd , fg ] = massF11( par_mex.var , z.' , s ) ;
    TMT = TMT + T.' * M * T * ds ;
    TMfd = TMfd + T.' * M * ( - Dd * uq + fg ) * ds ;
end

s0 = 1e-6 ;
ds = par_mex.rom.mass(12) / par_mex.n_int ;
if par_mex.rom.mass(12) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.mass(12) - s0
    [ M , T , Dd , fg ] = massF12( par_mex.var , z.' , s ) ;
    TMT = TMT + T.' * M * T * ds ;
    TMfd = TMfd + T.' * M * ( - Dd * uq + fg ) * ds ;
end

s0 = 1e-6 ;
ds = par_mex.rom.mass(13) / par_mex.n_int ;
if par_mex.rom.mass(13) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.mass(13) - s0
    [ M , T , Dd , fg ] = massF13( par_mex.var , z.' , s ) ;
    TMT = TMT + T.' * M * T * ds ;
    TMfd = TMfd + T.' * M * ( - Dd * uq + fg ) * ds ;
end

s0 = 1e-6 ;
ds = par_mex.rom.mass(14) / par_mex.n_int ;
if par_mex.rom.mass(14) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.mass(14) - s0
    [ M , T , Dd , fg ] = massF14( par_mex.var , z.' , s ) ;
    TMT = TMT + T.' * M * T * ds ;
    TMfd = TMfd + T.' * M * ( - Dd * uq + fg ) * ds ;
end

s0 = 1e-6 ;
ds = par_mex.rom.mass(15) / par_mex.n_int ;
if par_mex.rom.mass(15) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.mass(15) - s0
    [ M , T , Dd , fg ] = massF15( par_mex.var , z.' , s ) ;
    TMT = TMT + T.' * M * T * ds ;
    TMfd = TMfd + T.' * M * ( - Dd * uq + fg ) * ds ;
end

s0 = 1e-6 ;
ds = par_mex.rom.mass(16) / par_mex.n_int ;
if par_mex.rom.mass(16) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.mass(16) - s0
    [ M , T , Dd , fg ] = massF16( par_mex.var , z.' , s ) ;
    TMT = TMT + T.' * M * T * ds ;
    TMfd = TMfd + T.' * M * ( - Dd * uq + fg ) * ds ;
end

s0 = 1e-6 ;
ds = par_mex.rom.sprdmp(107) / par_mex.n_int ;
if par_mex.rom.sprdmp(107) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.sprdmp(107) - s0
    [ Tt , kx , vd , in ] = sprdmpF107( par_mex.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par_mex.rom.sprdmp(108) / par_mex.n_int ;
if par_mex.rom.sprdmp(108) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.sprdmp(108) - s0
    [ Tt , kx , vd , in ] = sprdmpF108( par_mex.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par_mex.rom.sprdmp(109) / par_mex.n_int ;
if par_mex.rom.sprdmp(109) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.sprdmp(109) - s0
    [ Tt , kx , vd , in ] = sprdmpF109( par_mex.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par_mex.rom.sprdmp(110) / par_mex.n_int ;
if par_mex.rom.sprdmp(110) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.sprdmp(110) - s0
    [ Tt , kx , vd , in ] = sprdmpF110( par_mex.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par_mex.rom.sprdmp(111) / par_mex.n_int ;
if par_mex.rom.sprdmp(111) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.sprdmp(111) - s0
    [ Tt , kx , vd , in ] = sprdmpF111( par_mex.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par_mex.rom.sprdmp(112) / par_mex.n_int ;
if par_mex.rom.sprdmp(112) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.sprdmp(112) - s0
    [ Tt , kx , vd , in ] = sprdmpF112( par_mex.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par_mex.rom.sprdmp(113) / par_mex.n_int ;
if par_mex.rom.sprdmp(113) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.sprdmp(113) - s0
    [ Tt , kx , vd , in ] = sprdmpF113( par_mex.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par_mex.rom.sprdmp(114) / par_mex.n_int ;
if par_mex.rom.sprdmp(114) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.sprdmp(114) - s0
    [ Tt , kx , vd , in ] = sprdmpF114( par_mex.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par_mex.rom.sprdmp(115) / par_mex.n_int ;
if par_mex.rom.sprdmp(115) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.sprdmp(115) - s0
    [ Tt , kx , vd , in ] = sprdmpF115( par_mex.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par_mex.rom.sprdmp(116) / par_mex.n_int ;
if par_mex.rom.sprdmp(116) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.sprdmp(116) - s0
    [ Tt , kx , vd , in ] = sprdmpF116( par_mex.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par_mex.rom.sprdmp(117) / par_mex.n_int ;
if par_mex.rom.sprdmp(117) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.sprdmp(117) - s0
    [ Tt , kx , vd , in ] = sprdmpF117( par_mex.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par_mex.rom.sprdmp(118) / par_mex.n_int ;
if par_mex.rom.sprdmp(118) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.sprdmp(118) - s0
    [ Tt , kx , vd , in ] = sprdmpF118( par_mex.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par_mex.rom.sprdmp(119) / par_mex.n_int ;
if par_mex.rom.sprdmp(119) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.sprdmp(119) - s0
    [ Tt , kx , vd , in ] = sprdmpF119( par_mex.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par_mex.rom.sprdmp(120) / par_mex.n_int ;
if par_mex.rom.sprdmp(120) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.sprdmp(120) - s0
    [ Tt , kx , vd , in ] = sprdmpF120( par_mex.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par_mex.rom.sprdmp(121) / par_mex.n_int ;
if par_mex.rom.sprdmp(121) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.sprdmp(121) - s0
    [ Tt , kx , vd , in ] = sprdmpF121( par_mex.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par_mex.rom.sprdmp(122) / par_mex.n_int ;
if par_mex.rom.sprdmp(122) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.sprdmp(122) - s0
    [ Tt , kx , vd , in ] = sprdmpF122( par_mex.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par_mex.rom.sprdmp(123) / par_mex.n_int ;
if par_mex.rom.sprdmp(123) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.sprdmp(123) - s0
    [ Tt , kx , vd , in ] = sprdmpF123( par_mex.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par_mex.rom.sprdmp(124) / par_mex.n_int ;
if par_mex.rom.sprdmp(124) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.sprdmp(124) - s0
    [ Tt , kx , vd , in ] = sprdmpF124( par_mex.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par_mex.rom.sprdmp(125) / par_mex.n_int ;
if par_mex.rom.sprdmp(125) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.sprdmp(125) - s0
    [ Tt , kx , vd , in ] = sprdmpF125( par_mex.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par_mex.rom.sprdmp(126) / par_mex.n_int ;
if par_mex.rom.sprdmp(126) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.sprdmp(126) - s0
    [ Tt , kx , vd , in ] = sprdmpF126( par_mex.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par_mex.rom.sprdmp(127) / par_mex.n_int ;
if par_mex.rom.sprdmp(127) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.sprdmp(127) - s0
    [ Tt , kx , vd , in ] = sprdmpF127( par_mex.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par_mex.rom.sprdmp(128) / par_mex.n_int ;
if par_mex.rom.sprdmp(128) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.sprdmp(128) - s0
    [ Tt , kx , vd , in ] = sprdmpF128( par_mex.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par_mex.rom.sprdmp(129) / par_mex.n_int ;
if par_mex.rom.sprdmp(129) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.sprdmp(129) - s0
    [ Tt , kx , vd , in ] = sprdmpF129( par_mex.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

s0 = 1e-6 ;
ds = par_mex.rom.sprdmp(130) / par_mex.n_int ;
if par_mex.rom.sprdmp(130) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.sprdmp(130) - s0
    [ Tt , kx , vd , in ] = sprdmpF130( par_mex.var , z.' , s ) ;
    w_vd_j = w_vd_j + Tt * vd * ds ;
    w_sd = w_sd + Tt * kx * ds ;
    w_in = w_in + Tt * in * ds ;
end

[ tc , Dc , in ] = cnstF1( par_mex.var , z.' , 0 ) ;
Tc = [ Tc ; tc ] ;
dc = [ dc ; - Dc * uq + in ] ;

[ tc , Dc , in ] = cnstF2( par_mex.var , z.' , 0 ) ;
Tc = [ Tc ; tc ] ;
dc = [ dc ; - Dc * uq + in ] ;

[ tc , Dc , in ] = cnstF3( par_mex.var , z.' , 0 ) ;
Tc = [ Tc ; tc ] ;
dc = [ dc ; - Dc * uq + in ] ;

[ tc , Dc , in ] = cnstF4( par_mex.var , z.' , 0 ) ;
Tc = [ Tc ; tc ] ;
dc = [ dc ; - Dc * uq + in ] ;

[ tc , Dc , in ] = cnstF5( par_mex.var , z.' , 0 ) ;
Tc = [ Tc ; tc ] ;
dc = [ dc ; - Dc * uq + in ] ;

[ tc , Dc , in ] = cnstF6( par_mex.var , z.' , 0 ) ;
Tc = [ Tc ; tc ] ;
dc = [ dc ; - Dc * uq + in ] ;

% EOM
TMT = [ TMT , Tc.' ; Tc , zeros(6,6) ] ;
d_eom = [ ( TMfd + fj_k + fj_vd + fj_in + w_sd + w_in + w_vd_j + w_f ) ; dc ] ;
dzt = TMT \ d_eom ;

dz = [ u ; dzt ];