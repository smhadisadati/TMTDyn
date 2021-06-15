function res = EOM_eq ( z )
global par_mex
t = par_mex.t_equil_i;
z = [ z 0*z ]' ;

u = z( 10 : end ) ;
uq = u( 1 : 9 ) ;

[ z , par_mex ] = static_mid_step( t , z , par_mex ) ;

fj_k = fj_kF( par_mex.var , z , 0 , 0 , t ) ; 
fj_in = fj_inF( par_mex.var , z , 0 , 0 , t ) ;
Tj_u = Tj_uF( par_mex.var , z , 0 , 0 , t ) ;

TMT = zeros(9,9) ; TMfd = zeros(9,1) ;
w_vd_j = zeros(9,1) ; w_sd = zeros(9,1) ; w_in = zeros(9,1) ;
w_f = zeros(9,1) ;
Tc = [] ; Tct = Tj_u ; dc = [] ;
[rom_mass, rom_sprdmp] = romF(par_mex.var , z , 0 , 0 , t ) ;


sn = 1e-06 ; 

    [ M , T , Dd , fg ] = massF1( par_mex.var , z , sn * ( rom_mass(1,2) - rom_mass(1,1) ) + rom_mass(1,1) , 0 , t ) ;
    Tt = T' ;
    TMT = TMT + Tt * M * T * ( rom_mass(1,2) - rom_mass(1,1) ) ;
    TMfd = TMfd + Tt * M * ( - Dd * uq + fg ) * ( rom_mass(1,2) - rom_mass(1,1) ) ;

    [ Tt , kx , vd , in , ~ , dir ] = sprdmpF10( par_mex.var , z , sn * ( rom_sprdmp(10,2) - rom_sprdmp(10,1) ) + rom_sprdmp(10,1) , ( rom_sprdmp(10,2) - rom_sprdmp(10,1) ) / 10 , t ) ;
    w_vd_j = w_vd_j + dir * Tt * vd * ( rom_sprdmp(10,2) - rom_sprdmp(10,1) ) ;
    w_sd = w_sd + dir * Tt * kx * ( rom_sprdmp(10,2) - rom_sprdmp(10,1) ) ;
    w_in = w_in + dir * Tt * in * ( rom_sprdmp(10,2) - rom_sprdmp(10,1) ) ;

sn = 1 - 1e-06 ; 

    [ M , T , Dd , fg ] = massF1( par_mex.var , z , sn * ( rom_mass(1,2) - rom_mass(1,1) ) + rom_mass(1,1) , 0 , t ) ;
    Tt = T' ;
    TMT = TMT + Tt * M * T * ( rom_mass(1,2) - rom_mass(1,1) ) ;
    TMfd = TMfd + Tt * M * ( - Dd * uq + fg ) * ( rom_mass(1,2) - rom_mass(1,1) ) ;

    [ Tt , kx , vd , in , ~ , dir ] = sprdmpF10( par_mex.var , z , sn * ( rom_sprdmp(10,2) - rom_sprdmp(10,1) ) + rom_sprdmp(10,1) , ( rom_sprdmp(10,2) - rom_sprdmp(10,1) ) / 10 , t ) ;
    w_vd_j = w_vd_j + dir * Tt * vd * ( rom_sprdmp(10,2) - rom_sprdmp(10,1) ) ;
    w_sd = w_sd + dir * Tt * kx * ( rom_sprdmp(10,2) - rom_sprdmp(10,1) ) ;
    w_in = w_in + dir * Tt * in * ( rom_sprdmp(10,2) - rom_sprdmp(10,1) ) ;

TMT = TMT / 2 ; TMfd = TMfd / 2 ;
w_vd_j = w_vd_j / 2 ; w_sd = w_sd / 2 ; w_in = w_in / 2 ;


for sn = 1e-06 + 0.1 : 0.1 : 1 + 1e-06 - 0.1

    [ M , T , Dd , fg ] = massF1( par_mex.var , z , sn * ( rom_mass(1,2) - rom_mass(1,1) ) + rom_mass(1,1) , 0 , t ) ;
    Tt = T' ;
    TMT = TMT + Tt * M * T * ( rom_mass(1,2) - rom_mass(1,1) ) ;
    TMfd = TMfd + Tt * M * ( - Dd * uq + fg ) * ( rom_mass(1,2) - rom_mass(1,1) ) ;

    [ Tt , kx , vd , in , ~ , dir ] = sprdmpF10( par_mex.var , z , sn * ( rom_sprdmp(10,2) - rom_sprdmp(10,1) ) + rom_sprdmp(10,1) , ( rom_sprdmp(10,2) - rom_sprdmp(10,1) ) / 10 , t ) ;
    w_vd_j = w_vd_j + dir * Tt * vd * ( rom_sprdmp(10,2) - rom_sprdmp(10,1) ) ;
    w_sd = w_sd + dir * Tt * kx * ( rom_sprdmp(10,2) - rom_sprdmp(10,1) ) ;
    w_in = w_in + dir * Tt * in * ( rom_sprdmp(10,2) - rom_sprdmp(10,1) ) ;

end
TMT = TMT / 10 ; TMfd = TMfd / 10 ;
w_vd_j = w_vd_j / 10 ; w_sd = w_sd / 10 ; w_in = w_in / 10 ;


[ M , T , Dd , fg ] = massF2( par_mex.var , z , 0 , 0 , t ) ;
Tt = T' ;
TMT = TMT + Tt * M * T ;
TMfd = TMfd + Tt * M * ( - Dd * uq + fg ) ;


[ Ttf , ftau_ex , Tto ] = loadsF1( par_mex.var , z , 0 , t ) ;
w_f = w_f + Ttf * ftau_ex ;
Tct = [ Tct , Tto ] ;

% EOM
res = [ ( TMfd + fj_k + fj_in + w_sd + w_in + w_f ) ; dc ] ;

flag = 0;
new_data = [];