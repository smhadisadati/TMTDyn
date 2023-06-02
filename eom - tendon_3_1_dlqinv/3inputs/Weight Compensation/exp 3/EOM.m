function [ dz , flag , new_data ] = EOM ( t , z , par_mex )

u = z( 18 + 0 + 3 + 1 : end ) ;
uq = u( 1 : 18 ) ;

[ z , par_mex ] = dyn_mid_step( t , z , par_mex ) ;

fj_k = fj_kF( par_mex.var , z , 0 , 0 , t ) ; 
fj_vd = fj_vdF( par_mex.var , z , 0 , 0 , t ) ;
fj_in = fj_inF( par_mex.var , z , 0 , 0 , t ) ;
Tj_u = Tj_uF( par_mex.var , z , 0 , 0 , t ) ;

TMT = zeros(18,18) ; TMfd = zeros(18,1) ;
w_vd_j = zeros(18,1) ; w_sd = zeros(18,1) ; w_in = zeros(18,1) ;
w_f = zeros(18,1) ;
Tc = [] ; Tct = Tj_u ; dc = [] ; in_c = [] ;
[rom_mass, rom_sprdmp] = romF(par_mex.var , z , 0 , 0 , t ) ;


Ttu_20 = zeros( 18 , 2 ) ;
sn = 1e-06 ; 

    M = massM1( par_mex.var , z , sn * ( rom_mass(1,2) - rom_mass(1,1) ) + rom_mass(1,1) , 0 , t ) ;
    T = massT1( par_mex.var , z , sn * ( rom_mass(1,2) - rom_mass(1,1) ) + rom_mass(1,1) , 0 , t ) ;
    Dd = massDd1( par_mex.var , z , sn * ( rom_mass(1,2) - rom_mass(1,1) ) + rom_mass(1,1) , 0 , t ) ;
    fg = massFg1( par_mex.var , z , sn * ( rom_mass(1,2) - rom_mass(1,1) ) + rom_mass(1,1) , 0 , t ) ;
    Tt = T' ;
    TMT = TMT + Tt * M * T * ( rom_mass(1,2) - rom_mass(1,1) ) ;
    TMfd = TMfd + Tt * M * ( - Dd * uq + fg ) * ( rom_mass(1,2) - rom_mass(1,1) ) ;

    Tt = sprdmpTt20( par_mex.var , z , sn * ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) + rom_sprdmp(20,1) , ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) / 10 , t ) ;
    kx = sprdmpKx20( par_mex.var , z , sn * ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) + rom_sprdmp(20,1) , ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) / 10 , t ) ;
    vd = sprdmpVd20( par_mex.var , z , sn * ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) + rom_sprdmp(20,1) , ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) / 10 , t ) ;
    in = sprdmpIn20( par_mex.var , z , sn * ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) + rom_sprdmp(20,1) , ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) / 10 , t ) ;
    ttu = sprdmpTtu20( par_mex.var , z , sn * ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) + rom_sprdmp(20,1) , ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) / 10 , t ) ;
    dir = sprdmpDir20( par_mex.var , z , sn * ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) + rom_sprdmp(20,1) , ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) / 10 , t ) ;
    w_vd_j = w_vd_j + dir * Tt * vd * ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) ;
    w_sd = w_sd + dir * Tt * kx * ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) ;
    w_in = w_in + dir * Tt * in * ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) ;
    Ttu_20 = Ttu_20 + ttu * ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) ;

sn = 1 - 1e-06 ; 

    M = massM1( par_mex.var , z , sn * ( rom_mass(1,2) - rom_mass(1,1) ) + rom_mass(1,1) , 0 , t ) ;
    T = massT1( par_mex.var , z , sn * ( rom_mass(1,2) - rom_mass(1,1) ) + rom_mass(1,1) , 0 , t ) ;
    Dd = massDd1( par_mex.var , z , sn * ( rom_mass(1,2) - rom_mass(1,1) ) + rom_mass(1,1) , 0 , t ) ;
    fg = massFg1( par_mex.var , z , sn * ( rom_mass(1,2) - rom_mass(1,1) ) + rom_mass(1,1) , 0 , t ) ;
    Tt = T' ;
    TMT = TMT + Tt * M * T * ( rom_mass(1,2) - rom_mass(1,1) ) ;
    TMfd = TMfd + Tt * M * ( - Dd * uq + fg ) * ( rom_mass(1,2) - rom_mass(1,1) ) ;

    Tt = sprdmpTt20( par_mex.var , z , sn * ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) + rom_sprdmp(20,1) , ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) / 10 , t ) ;
    kx = sprdmpKx20( par_mex.var , z , sn * ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) + rom_sprdmp(20,1) , ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) / 10 , t ) ;
    vd = sprdmpVd20( par_mex.var , z , sn * ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) + rom_sprdmp(20,1) , ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) / 10 , t ) ;
    in = sprdmpIn20( par_mex.var , z , sn * ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) + rom_sprdmp(20,1) , ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) / 10 , t ) ;
    ttu = sprdmpTtu20( par_mex.var , z , sn * ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) + rom_sprdmp(20,1) , ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) / 10 , t ) ;
    dir = sprdmpDir20( par_mex.var , z , sn * ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) + rom_sprdmp(20,1) , ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) / 10 , t ) ;
    w_vd_j = w_vd_j + dir * Tt * vd * ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) ;
    w_sd = w_sd + dir * Tt * kx * ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) ;
    w_in = w_in + dir * Tt * in * ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) ;
    Ttu_20 = Ttu_20 + ttu * ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) ;

TMT = TMT / 2 ; TMfd = TMfd / 2 ;
w_vd_j = w_vd_j / 2 ; w_sd = w_sd / 2 ; w_in = w_in / 2 ;

Ttu_20 = Ttu_20 / 2 ; 


for sn = 1e-06 + 0.1 : 0.1 : 1 + 1e-06 - 0.1

    M = massM1( par_mex.var , z , sn * ( rom_mass(1,2) - rom_mass(1,1) ) + rom_mass(1,1) , 0 , t ) ;
    T = massT1( par_mex.var , z , sn * ( rom_mass(1,2) - rom_mass(1,1) ) + rom_mass(1,1) , 0 , t ) ;
    Dd = massDd1( par_mex.var , z , sn * ( rom_mass(1,2) - rom_mass(1,1) ) + rom_mass(1,1) , 0 , t ) ;
    fg = massFg1( par_mex.var , z , sn * ( rom_mass(1,2) - rom_mass(1,1) ) + rom_mass(1,1) , 0 , t ) ;
    Tt = T' ;
    TMT = TMT + Tt * M * T * ( rom_mass(1,2) - rom_mass(1,1) ) ;
    TMfd = TMfd + Tt * M * ( - Dd * uq + fg ) * ( rom_mass(1,2) - rom_mass(1,1) ) ;

    Tt = sprdmpTt20( par_mex.var , z , sn * ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) + rom_sprdmp(20,1) , ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) / 10 , t ) ;
    kx = sprdmpKx20( par_mex.var , z , sn * ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) + rom_sprdmp(20,1) , ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) / 10 , t ) ;
    vd = sprdmpVd20( par_mex.var , z , sn * ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) + rom_sprdmp(20,1) , ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) / 10 , t ) ;
    in = sprdmpIn20( par_mex.var , z , sn * ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) + rom_sprdmp(20,1) , ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) / 10 , t ) ;
    ttu = sprdmpTtu20( par_mex.var , z , sn * ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) + rom_sprdmp(20,1) , ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) / 10 , t ) ;
    dir = sprdmpDir20( par_mex.var , z , sn * ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) + rom_sprdmp(20,1) , ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) / 10 , t ) ;
    w_vd_j = w_vd_j + dir * Tt * vd * ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) ;
    w_sd = w_sd + dir * Tt * kx * ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) ;
    w_in = w_in + dir * Tt * in * ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) ;
    Ttu_20 = Ttu_20 + ttu * ( rom_sprdmp(20,2) - rom_sprdmp(20,1) ) ;

end
TMT = TMT / 10 ; TMfd = TMfd / 10 ;
w_vd_j = w_vd_j / 10 ; w_sd = w_sd / 10 ; w_in = w_in / 10 ;

Tct = [ Tct , [ Ttu_20 ]/10 ] ;


Tt = sprdmpTt19( par_mex.var , z , 0 , 0 , t ) ;
kx = sprdmpKx19( par_mex.var , z , 0 , 0 , t ) ;
vd = sprdmpVd19( par_mex.var , z , 0 , 0 , t ) ;
in = sprdmpIn19( par_mex.var , z , 0 , 0 , t ) ;
dir = sprdmpDir19( par_mex.var , z , 0 , 0 , t ) ;
w_vd_j = w_vd_j + dir * Tt * vd ;
w_sd = w_sd + dir * Tt * kx ;
w_in = w_in + dir * Tt * in ;


Ttf = loadsTt1( par_mex.var , z , 0 , t ) ;
ftau_ex = loadsFtau1( par_mex.var , z , 0 , t ) ;
Tto = loadsTto1( par_mex.var , z , 0 , t ) ;
w_f = w_f + Ttf * ftau_ex ;
Tct = [ Tct , Tto ] ;

tc = cnstT1( par_mex.var , z , 0 , t ) ;
tct = cnstTt1( par_mex.var , z , 0 , t ) ;
Dc = cnstD1( par_mex.var , z , 0 , t ) ;
in = cnstIn1( par_mex.var , z , 0 , t ) ;
Tc = [ Tc ; tc ] ;
Tct = [ Tct , tct ] ;
dc = [ dc ; ( - Dc * uq + in ) ] ; % if "in" is accelerations
in_c = [ in_c ; in ] ; % if "in" is equivalent sping-damper (PD) force

tc = cnstT2( par_mex.var , z , 0 , t ) ;
tct = cnstTt2( par_mex.var , z , 0 , t ) ;
Dc = cnstD2( par_mex.var , z , 0 , t ) ;
in = cnstIn2( par_mex.var , z , 0 , t ) ;
Tc = [ Tc ; tc ] ;
Tct = [ Tct , tct ] ;
dc = [ dc ; ( - Dc * uq + in ) ] ; % if "in" is accelerations
in_c = [ in_c ; in ] ; % if "in" is equivalent sping-damper (PD) force

tc = cnstT3( par_mex.var , z , 0 , t ) ;
tct = cnstTt3( par_mex.var , z , 0 , t ) ;
Dc = cnstD3( par_mex.var , z , 0 , t ) ;
in = cnstIn3( par_mex.var , z , 0 , t ) ;
Tc = [ Tc ; tc ] ;
Tct = [ Tct , tct ] ;
dc = [ dc ; ( - Dc * uq + in ) ] ; % if "in" is accelerations
in_c = [ in_c ; in ] ; % if "in" is equivalent sping-damper (PD) force

% weight_compensation_&_attractor_field_controller
F_d = Tc' * in_c ;
d_eom_q = ( TMfd + fj_k + fj_in + w_sd + w_in + w_f ) ;

U = pinv( Tct ) * ( F_d - d_eom_q ) ;

dY = u ;
ddY = pinv( TMT , 1e-24 ) * ( d_eom_q + w_vd_j + fj_vd + Tct * U - ( 1e-12 ./ svd( TMT )  ) .* ( TMT * u( 1 : 18 + 0 ) ) ) ;

dz = [ dY ; ddY ; U ];
flag = 0;
new_data = [];