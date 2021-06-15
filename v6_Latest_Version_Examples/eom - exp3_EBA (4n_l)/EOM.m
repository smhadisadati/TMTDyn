function [ dz , flag , new_data ] = EOM ( t , z , par_mex )

u = z( 18 + 0 + 0 + 1 : end ) ;
uq = u( 1 : 18 ) ;

[ z , par_mex ] = dyn_mid_step( t , z , par_mex ) ;

fj_k = fj_kF( par_mex.var , z , 0 , 0 , t ) ; 
fj_vd = fj_vdF( par_mex.var , z , 0 , 0 , t ) ;
fj_in = fj_inF( par_mex.var , z , 0 , 0 , t ) ;
Tj_u = Tj_uF( par_mex.var , z , 0 , 0 , t ) ;

TMT = zeros(18,18) ; TMfd = zeros(18,1) ;
w_vd_j = zeros(18,1) ; w_sd = zeros(18,1) ; w_in = zeros(18,1) ;
w_f = zeros(18,1) ;
Tc = [] ; Tct = Tj_u ; dc = [] ;


[ M , T , Dd , fg ] = massF1( par_mex.var , z , 0 , 0 , t ) ;
Tt = T' ;
TMT = TMT + Tt * M * T ;
TMfd = TMfd + Tt * M * ( - Dd * uq + fg ) ;

[ M , T , Dd , fg ] = massF2( par_mex.var , z , 0 , 0 , t ) ;
Tt = T' ;
TMT = TMT + Tt * M * T ;
TMfd = TMfd + Tt * M * ( - Dd * uq + fg ) ;

[ M , T , Dd , fg ] = massF3( par_mex.var , z , 0 , 0 , t ) ;
Tt = T' ;
TMT = TMT + Tt * M * T ;
TMfd = TMfd + Tt * M * ( - Dd * uq + fg ) ;

[ M , T , Dd , fg ] = massF4( par_mex.var , z , 0 , 0 , t ) ;
Tt = T' ;
TMT = TMT + Tt * M * T ;
TMfd = TMfd + Tt * M * ( - Dd * uq + fg ) ;

[ Tt , kx , vd , in , ~ , dir ] = sprdmpF19( par_mex.var , z , 0 , 0 , t ) ;
w_vd_j = w_vd_j + dir * Tt * vd ;
w_sd = w_sd + dir * Tt * kx ;
w_in = w_in + dir * Tt * in ;

[ Tt , kx , vd , in , ~ , dir ] = sprdmpF20( par_mex.var , z , 0 , 0 , t ) ;
w_vd_j = w_vd_j + dir * Tt * vd ;
w_sd = w_sd + dir * Tt * kx ;
w_in = w_in + dir * Tt * in ;

[ Tt , kx , vd , in , ~ , dir ] = sprdmpF21( par_mex.var , z , 0 , 0 , t ) ;
w_vd_j = w_vd_j + dir * Tt * vd ;
w_sd = w_sd + dir * Tt * kx ;
w_in = w_in + dir * Tt * in ;


[ Ttf , ftau_ex , Tto ] = loadsF1( par_mex.var , z , 0 , t ) ;
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