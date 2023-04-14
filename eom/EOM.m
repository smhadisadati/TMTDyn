function [ dz , flag , new_data ] = EOM ( t , z , par_mex )

u = z( 32 + 0 + 0 + 1 : end ) ;
uq = u( 1 : 32 ) ;

[ z , par_mex ] = dyn_mid_step( t , z , par_mex ) ;

fj_k = fj_kF( par_mex.var , z ) ; 
fj_vd = fj_vdF( par_mex.var , z ) ;
fj_in = fj_inF( par_mex.var , z ) ;
Tj_u = Tj_uF( par_mex.var , z ) ;

TMT = zeros(32,32) ; TMfd = zeros(32,1) ;
w_vd_j = zeros(32,1) ; w_sd = zeros(32,1) ; w_in = zeros(32,1) ;
w_f = zeros(32,1) ;
Tc = [] ; Tct = Tj_u ; dc = [] ;
[rom_mass, rom_sprdmp] = romF(par_mex.var , z , 0) ;


sn = 0 ; 

    [ M , T , Dd , fg ] = massF1( par_mex.var , z , sn * ( rom_mass(1,2) - rom_mass(1,1) ) + rom_mass(1,1) ) ;
    Tt = T' ;
    TMT = TMT + Tt * M * T * ( rom_mass(1,2) - rom_mass(1,1) ) ;
    TMfd = TMfd + Tt * M * ( - Dd * uq + fg ) * ( rom_mass(1,2) - rom_mass(1,1) ) ;

    [ M , T , Dd , fg ] = massF2( par_mex.var , z , sn * ( rom_mass(2,2) - rom_mass(2,1) ) + rom_mass(2,1) ) ;
    Tt = T' ;
    TMT = TMT + Tt * M * T * ( rom_mass(2,2) - rom_mass(2,1) ) ;
    TMfd = TMfd + Tt * M * ( - Dd * uq + fg ) * ( rom_mass(2,2) - rom_mass(2,1) ) ;

    [ Tt , kx , vd , in , ~ , dir ] = sprdmpF33( par_mex.var , z , sn * ( rom_sprdmp(33,2) - rom_sprdmp(33,1) ) + rom_sprdmp(33,1) ) ;
    w_vd_j = w_vd_j + dir * Tt * vd * ( rom_sprdmp(33,2) - rom_sprdmp(33,1) ) ;
    w_sd = w_sd + dir * Tt * kx * ( rom_sprdmp(33,2) - rom_sprdmp(33,1) ) ;
    w_in = w_in + dir * Tt * in * ( rom_sprdmp(33,2) - rom_sprdmp(33,1) ) ;

    [ Tt , kx , vd , in , ~ , dir ] = sprdmpF34( par_mex.var , z , sn * ( rom_sprdmp(34,2) - rom_sprdmp(34,1) ) + rom_sprdmp(34,1) ) ;
    w_vd_j = w_vd_j + dir * Tt * vd * ( rom_sprdmp(34,2) - rom_sprdmp(34,1) ) ;
    w_sd = w_sd + dir * Tt * kx * ( rom_sprdmp(34,2) - rom_sprdmp(34,1) ) ;
    w_in = w_in + dir * Tt * in * ( rom_sprdmp(34,2) - rom_sprdmp(34,1) ) ;

sn = 1 ; 

    [ M , T , Dd , fg ] = massF1( par_mex.var , z , sn * ( rom_mass(1,2) - rom_mass(1,1) ) + rom_mass(1,1) ) ;
    Tt = T' ;
    TMT = TMT + Tt * M * T * ( rom_mass(1,2) - rom_mass(1,1) ) ;
    TMfd = TMfd + Tt * M * ( - Dd * uq + fg ) * ( rom_mass(1,2) - rom_mass(1,1) ) ;

    [ M , T , Dd , fg ] = massF2( par_mex.var , z , sn * ( rom_mass(2,2) - rom_mass(2,1) ) + rom_mass(2,1) ) ;
    Tt = T' ;
    TMT = TMT + Tt * M * T * ( rom_mass(2,2) - rom_mass(2,1) ) ;
    TMfd = TMfd + Tt * M * ( - Dd * uq + fg ) * ( rom_mass(2,2) - rom_mass(2,1) ) ;

    [ Tt , kx , vd , in , ~ , dir ] = sprdmpF33( par_mex.var , z , sn * ( rom_sprdmp(33,2) - rom_sprdmp(33,1) ) + rom_sprdmp(33,1) ) ;
    w_vd_j = w_vd_j + dir * Tt * vd * ( rom_sprdmp(33,2) - rom_sprdmp(33,1) ) ;
    w_sd = w_sd + dir * Tt * kx * ( rom_sprdmp(33,2) - rom_sprdmp(33,1) ) ;
    w_in = w_in + dir * Tt * in * ( rom_sprdmp(33,2) - rom_sprdmp(33,1) ) ;

    [ Tt , kx , vd , in , ~ , dir ] = sprdmpF34( par_mex.var , z , sn * ( rom_sprdmp(34,2) - rom_sprdmp(34,1) ) + rom_sprdmp(34,1) ) ;
    w_vd_j = w_vd_j + dir * Tt * vd * ( rom_sprdmp(34,2) - rom_sprdmp(34,1) ) ;
    w_sd = w_sd + dir * Tt * kx * ( rom_sprdmp(34,2) - rom_sprdmp(34,1) ) ;
    w_in = w_in + dir * Tt * in * ( rom_sprdmp(34,2) - rom_sprdmp(34,1) ) ;

TMT = TMT / 2 ; TMfd = TMfd / 2 ;
w_vd_j = w_vd_j / 2 ; w_sd = w_sd / 2 ; w_in = w_in / 2 ;


for sn = 1e-06 + 0.016667 : 0.016667 : 1 + 1e-06 - 0.016667

    [ M , T , Dd , fg ] = massF1( par_mex.var , z , sn * ( rom_mass(1,2) - rom_mass(1,1) ) + rom_mass(1,1) ) ;
    Tt = T' ;
    TMT = TMT + Tt * M * T * ( rom_mass(1,2) - rom_mass(1,1) ) ;
    TMfd = TMfd + Tt * M * ( - Dd * uq + fg ) * ( rom_mass(1,2) - rom_mass(1,1) ) ;

    [ M , T , Dd , fg ] = massF2( par_mex.var , z , sn * ( rom_mass(2,2) - rom_mass(2,1) ) + rom_mass(2,1) ) ;
    Tt = T' ;
    TMT = TMT + Tt * M * T * ( rom_mass(2,2) - rom_mass(2,1) ) ;
    TMfd = TMfd + Tt * M * ( - Dd * uq + fg ) * ( rom_mass(2,2) - rom_mass(2,1) ) ;

    [ Tt , kx , vd , in , ~ , dir ] = sprdmpF33( par_mex.var , z , sn * ( rom_sprdmp(33,2) - rom_sprdmp(33,1) ) + rom_sprdmp(33,1) ) ;
    w_vd_j = w_vd_j + dir * Tt * vd * ( rom_sprdmp(33,2) - rom_sprdmp(33,1) ) ;
    w_sd = w_sd + dir * Tt * kx * ( rom_sprdmp(33,2) - rom_sprdmp(33,1) ) ;
    w_in = w_in + dir * Tt * in * ( rom_sprdmp(33,2) - rom_sprdmp(33,1) ) ;

    [ Tt , kx , vd , in , ~ , dir ] = sprdmpF34( par_mex.var , z , sn * ( rom_sprdmp(34,2) - rom_sprdmp(34,1) ) + rom_sprdmp(34,1) ) ;
    w_vd_j = w_vd_j + dir * Tt * vd * ( rom_sprdmp(34,2) - rom_sprdmp(34,1) ) ;
    w_sd = w_sd + dir * Tt * kx * ( rom_sprdmp(34,2) - rom_sprdmp(34,1) ) ;
    w_in = w_in + dir * Tt * in * ( rom_sprdmp(34,2) - rom_sprdmp(34,1) ) ;

end
TMT = TMT / 60 ; TMfd = TMfd / 60 ;
w_vd_j = w_vd_j / 60 ; w_sd = w_sd / 60 ; w_in = w_in / 60 ;



[ Ttf , ftau_ex , Tto ] = loadsF1( par_mex.var , z , 0 ) ;
w_f = w_f + Ttf * ftau_ex ;
Tct = [ Tct , Tto ] ;

% EOM
TMTb = [ TMT , -Tct ; 
         Tc  , zeros(0,0) ] ;
d_eom = [ ( TMfd + fj_k + fj_vd + fj_in + w_sd + w_in + w_vd_j + w_f ) ; dc ] ;

dY = u ;
ddY = pinv( TMTb ) * d_eom ;

dz = [ dY ; ddY ];
flag = 0;
new_data = [];