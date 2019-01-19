function [ TMT , TKT , TVT ] = EOM_modal ( z , par )
z = [ z 0*z ]' ;

par = int_mid_step( par.t_equil_i , z , par ) ;

s0 = 1e-6 ;
TKT = fj_k_matF( par.var , z.' ) ; 
TVT = fj_vd_matF( par.var , z.' ) ;

TMT = zeros(6,6) ;

ds = par.rom.mass(1) / par.n_int ;
if par.rom.mass(1) == 0 ; ds = 1 ; end
for s = s0 : ds : par.rom.mass(1) - s0
    [ M , T ] = massF1( par.var , z.' , s ) ;
    TMT = TMT + T.' * M * T * ds ;
end

ds = par.rom.mass(2) / par.n_int ;
if par.rom.mass(2) == 0 ; ds = 1 ; end
for s = s0 : ds : par.rom.mass(2) - s0
    [ M , T ] = massF2( par.var , z.' , s ) ;
    TMT = TMT + T.' * M * T * ds ;
end

ds = par.rom.sprdmp(7) / par.n_int ;
if par.rom.sprdmp(7) == 0 ; ds = 1 ; end
for s = s0 : ds : par.rom.sprdmp(7) - s0
    [ Tt , ~ , ~ , ~ , ~ , k_mat , v_mat ] = sprdmpF7( par.var , z.' , s ) ;
    TKT = TKT + Tt * k_mat * ds ;
    TVT = TVT + Tt * v_mat * ds ;
end
