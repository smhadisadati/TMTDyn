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

TMT = zeros(1,1) ; TMfd = zeros(1,1) ;
w_vd_j = zeros(1,1) ; w_sd = zeros(1,1) ; w_in = zeros(1,1) ;
w_f = zeros(1,1) ;
Tc = [] ; dc = [] ;

s0 = 1e-6 ;
ds = par_mex.rom.mass(1) / par_mex.n_int ;
if par_mex.rom.mass(1) == 0 ; ds = 1 ; s0 = 0 ; end
for s = s0 : ds : par_mex.rom.mass(1) - s0
    [ M , T , Dd , fg ] = massF1( par_mex.var , z.' , s ) ;
    TMT = TMT + T.' * M * T * ds ;
    TMfd = TMfd + T.' * M * ( - Dd * uq + fg ) * ds ;
end

% EOM
TMT = [ TMT , Tc.' ; Tc , zeros(0,0) ] ;
d_eom = [ ( TMfd + fj_k + fj_vd + fj_in + w_sd + w_in + w_vd_j + w_f ) ; dc ] ;
dzt = TMT \ d_eom ;

dz = [ u ; dzt ];