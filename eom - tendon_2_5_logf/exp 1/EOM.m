function [ dz , flag , new_data ] = EOM ( t , z , par_mex )

u = z( 17 + 0 + 0 + 1 : end ) ;
uq = u( 1 : 17 ) ;

[ z , par_mex ] = dyn_mid_step( t , z , par_mex ) ;

fj_k = fj_kF( par_mex.var , z , 0 , 0 , t ) ; 
fj_vd = fj_vdF( par_mex.var , z , 0 , 0 , t ) ;
fj_in = fj_inF( par_mex.var , z , 0 , 0 , t ) ;
Tj_u = Tj_uF( par_mex.var , z , 0 , 0 , t ) ;

TMT = zeros(17,17) ; TMfd = zeros(17,1) ;
w_vd_j = zeros(17,1) ; w_sd = zeros(17,1) ; w_in = zeros(17,1) ;
w_f = zeros(17,1) ;
Tc = [] ; Tct = Tj_u ; dc = [] ;
[rom_mass, rom_sprdmp] = romF(par_mex.var , z , 0 , 0 , t ) ;


sn = 1e-06 ; 

    M = massM1( par_mex.var , z , sn * ( rom_mass(1,2) - rom_mass(1,1) ) + rom_mass(1,1) , 0 , t ) ;
    T = massT1( par_mex.var , z , sn * ( rom_mass(1,2) - rom_mass(1,1) ) + rom_mass(1,1) , 0 , t ) ;
    Dd = massDd1( par_mex.var , z , sn * ( rom_mass(1,2) - rom_mass(1,1) ) + rom_mass(1,1) , 0 , t ) ;
    fg = massFg1( par_mex.var , z , sn * ( rom_mass(1,2) - rom_mass(1,1) ) + rom_mass(1,1) , 0 , t ) ;
    Tt = T' ;
    TMT = TMT + Tt * M * T * ( rom_mass(1,2) - rom_mass(1,1) ) ;
    TMfd = TMfd + Tt * M * ( - Dd * uq + fg ) * ( rom_mass(1,2) - rom_mass(1,1) ) ;

    Tt = sprdmpTt18( par_mex.var , z , sn * ( rom_sprdmp(18,2) - rom_sprdmp(18,1) ) + rom_sprdmp(18,1) , ( rom_sprdmp(18,2) - rom_sprdmp(18,1) ) / 10 , t ) ;
    kx = sprdmpKx18( par_mex.var , z , sn * ( rom_sprdmp(18,2) - rom_sprdmp(18,1) ) + rom_sprdmp(18,1) , ( rom_sprdmp(18,2) - rom_sprdmp(18,1) ) / 10 , t ) ;
    vd = sprdmpVd18( par_mex.var , z , sn * ( rom_sprdmp(18,2) - rom_sprdmp(18,1) ) + rom_sprdmp(18,1) , ( rom_sprdmp(18,2) - rom_sprdmp(18,1) ) / 10 , t ) ;
    in = sprdmpIn18( par_mex.var , z , sn * ( rom_sprdmp(18,2) - rom_sprdmp(18,1) ) + rom_sprdmp(18,1) , ( rom_sprdmp(18,2) - rom_sprdmp(18,1) ) / 10 , t ) ;
    dir = sprdmpDir18( par_mex.var , z , sn * ( rom_sprdmp(18,2) - rom_sprdmp(18,1) ) + rom_sprdmp(18,1) , ( rom_sprdmp(18,2) - rom_sprdmp(18,1) ) / 10 , t ) ;
    w_vd_j = w_vd_j + dir * Tt * vd * ( rom_sprdmp(18,2) - rom_sprdmp(18,1) ) ;
    w_sd = w_sd + dir * Tt * kx * ( rom_sprdmp(18,2) - rom_sprdmp(18,1) ) ;
    w_in = w_in + dir * Tt * in * ( rom_sprdmp(18,2) - rom_sprdmp(18,1) ) ;

sn = 1 - 1e-06 ; 

    M = massM1( par_mex.var , z , sn * ( rom_mass(1,2) - rom_mass(1,1) ) + rom_mass(1,1) , 0 , t ) ;
    T = massT1( par_mex.var , z , sn * ( rom_mass(1,2) - rom_mass(1,1) ) + rom_mass(1,1) , 0 , t ) ;
    Dd = massDd1( par_mex.var , z , sn * ( rom_mass(1,2) - rom_mass(1,1) ) + rom_mass(1,1) , 0 , t ) ;
    fg = massFg1( par_mex.var , z , sn * ( rom_mass(1,2) - rom_mass(1,1) ) + rom_mass(1,1) , 0 , t ) ;
    Tt = T' ;
    TMT = TMT + Tt * M * T * ( rom_mass(1,2) - rom_mass(1,1) ) ;
    TMfd = TMfd + Tt * M * ( - Dd * uq + fg ) * ( rom_mass(1,2) - rom_mass(1,1) ) ;

    Tt = sprdmpTt18( par_mex.var , z , sn * ( rom_sprdmp(18,2) - rom_sprdmp(18,1) ) + rom_sprdmp(18,1) , ( rom_sprdmp(18,2) - rom_sprdmp(18,1) ) / 10 , t ) ;
    kx = sprdmpKx18( par_mex.var , z , sn * ( rom_sprdmp(18,2) - rom_sprdmp(18,1) ) + rom_sprdmp(18,1) , ( rom_sprdmp(18,2) - rom_sprdmp(18,1) ) / 10 , t ) ;
    vd = sprdmpVd18( par_mex.var , z , sn * ( rom_sprdmp(18,2) - rom_sprdmp(18,1) ) + rom_sprdmp(18,1) , ( rom_sprdmp(18,2) - rom_sprdmp(18,1) ) / 10 , t ) ;
    in = sprdmpIn18( par_mex.var , z , sn * ( rom_sprdmp(18,2) - rom_sprdmp(18,1) ) + rom_sprdmp(18,1) , ( rom_sprdmp(18,2) - rom_sprdmp(18,1) ) / 10 , t ) ;
    dir = sprdmpDir18( par_mex.var , z , sn * ( rom_sprdmp(18,2) - rom_sprdmp(18,1) ) + rom_sprdmp(18,1) , ( rom_sprdmp(18,2) - rom_sprdmp(18,1) ) / 10 , t ) ;
    w_vd_j = w_vd_j + dir * Tt * vd * ( rom_sprdmp(18,2) - rom_sprdmp(18,1) ) ;
    w_sd = w_sd + dir * Tt * kx * ( rom_sprdmp(18,2) - rom_sprdmp(18,1) ) ;
    w_in = w_in + dir * Tt * in * ( rom_sprdmp(18,2) - rom_sprdmp(18,1) ) ;

TMT = TMT / 2 ; TMfd = TMfd / 2 ;
w_vd_j = w_vd_j / 2 ; w_sd = w_sd / 2 ; w_in = w_in / 2 ;


for sn = 1e-06 + 0.1 : 0.1 : 1 + 1e-06 - 0.1

    M = massM1( par_mex.var , z , sn * ( rom_mass(1,2) - rom_mass(1,1) ) + rom_mass(1,1) , 0 , t ) ;
    T = massT1( par_mex.var , z , sn * ( rom_mass(1,2) - rom_mass(1,1) ) + rom_mass(1,1) , 0 , t ) ;
    Dd = massDd1( par_mex.var , z , sn * ( rom_mass(1,2) - rom_mass(1,1) ) + rom_mass(1,1) , 0 , t ) ;
    fg = massFg1( par_mex.var , z , sn * ( rom_mass(1,2) - rom_mass(1,1) ) + rom_mass(1,1) , 0 , t ) ;
    Tt = T' ;
    TMT = TMT + Tt * M * T * ( rom_mass(1,2) - rom_mass(1,1) ) ;
    TMfd = TMfd + Tt * M * ( - Dd * uq + fg ) * ( rom_mass(1,2) - rom_mass(1,1) ) ;

    Tt = sprdmpTt18( par_mex.var , z , sn * ( rom_sprdmp(18,2) - rom_sprdmp(18,1) ) + rom_sprdmp(18,1) , ( rom_sprdmp(18,2) - rom_sprdmp(18,1) ) / 10 , t ) ;
    kx = sprdmpKx18( par_mex.var , z , sn * ( rom_sprdmp(18,2) - rom_sprdmp(18,1) ) + rom_sprdmp(18,1) , ( rom_sprdmp(18,2) - rom_sprdmp(18,1) ) / 10 , t ) ;
    vd = sprdmpVd18( par_mex.var , z , sn * ( rom_sprdmp(18,2) - rom_sprdmp(18,1) ) + rom_sprdmp(18,1) , ( rom_sprdmp(18,2) - rom_sprdmp(18,1) ) / 10 , t ) ;
    in = sprdmpIn18( par_mex.var , z , sn * ( rom_sprdmp(18,2) - rom_sprdmp(18,1) ) + rom_sprdmp(18,1) , ( rom_sprdmp(18,2) - rom_sprdmp(18,1) ) / 10 , t ) ;
    dir = sprdmpDir18( par_mex.var , z , sn * ( rom_sprdmp(18,2) - rom_sprdmp(18,1) ) + rom_sprdmp(18,1) , ( rom_sprdmp(18,2) - rom_sprdmp(18,1) ) / 10 , t ) ;
    w_vd_j = w_vd_j + dir * Tt * vd * ( rom_sprdmp(18,2) - rom_sprdmp(18,1) ) ;
    w_sd = w_sd + dir * Tt * kx * ( rom_sprdmp(18,2) - rom_sprdmp(18,1) ) ;
    w_in = w_in + dir * Tt * in * ( rom_sprdmp(18,2) - rom_sprdmp(18,1) ) ;

end
TMT = TMT / 10 ; TMfd = TMfd / 10 ;
w_vd_j = w_vd_j / 10 ; w_sd = w_sd / 10 ; w_in = w_in / 10 ;



Ttf = loadsTt1( par_mex.var , z , 0 , t ) ;
ftau_ex = loadsFtau1( par_mex.var , z , 0 , t ) ;
Tto = loadsTto1( par_mex.var , z , 0 , t ) ;
w_f = w_f + Ttf * ftau_ex ;
Tct = [ Tct , Tto ] ;

% EOM
TMTb = [ TMT , -Tct ; 
         Tc  , zeros(0,0) ] ;
d_eom = [ ( TMfd + fj_k + fj_vd + fj_in + w_sd + w_in + w_vd_j + w_f ) ; dc ] ;

dY = u ;
ddY = pinv( TMTb ) * ( d_eom - 500000 * TMTb * dY ) ;

dz = [ dY ; ddY ];
flag = 0;
new_data = [];