%% EOM Numerical Integrator:
% ====================================================
% change this for different scenarios

function [ z0 , par ] = EquilEoM_Cat_v0_5( par )
global par_i

[ par.nq , par.nu , par.nlambda , par.qf0 , par.n_m , par.n_sd , par.n_cn , par.nlambda , par.n_ex ] = nqF( par.var ) ; % states' number and init. value

eps = 1e-3 ; % for singularity prevention
par.nlambda = 2 ; % added 2 constrains
z0 = [ eps+double( par.qf0 ) 0*ones( 1 , par.nlambda ) 0*ones( 1 , par.nq ) 0*ones( 1 , par.nlambda ) ] ; % initial condition
par_i = par ;
if par.equil == 0 ; return ; end

% fsolve equlibrium solver:
[ z0_eq , fval , exitflag ] = fsolve( @EOM_eq , z0(1:end/2) )
z0 = [ z0_eq 0*z0_eq ] ;

function fval = EOM_eq ( z )
global par_i
par = par_i ;
z = [ z 0*z ]' ;

% real strain and stress
lambda = 1 ;
% for i = 3 : 6 : par.nq % mean 
%     lambda = lambda + z(i) / par.var(5) ;
% end

% input p & ext. forces
r_p = par.var(18) ; r_o = par.var(19) ;
a_p = pi * r_p ^ 2 ;
temp = interp1( par.f_ex(:,1) , [ par.f_ex(:,2:7) par.p(:,2:4) ] , par.t_init , 'nearest' ) ;
f_ex = temp(1:3) ;
p = temp(7:9) ;
f_p = 2 * ( p(1) + p(2) + p(3) ) * a_p ;
tau = 2 * p * a_p * r_o / lambda * ... % constrained by caps and dense braids
      [ sin( 3*pi/6 )  -cos( 3*pi/6 )  0 ; % according to Ali's inputs
        sin( 11*pi/6 ) -cos( 11*pi/6 ) 0 ;
        sin( 7*pi/6 )  -cos( 7*pi/6 )  0 ] + ... % tau_p
        temp(4:6) ; % external tau
par.var(end-4:end) = [ f_p tau lambda ] ;

% Matlab
TMfd = 0 ;
for i = 1 : par.n_m
    M = feval( sprintf('massM%i', i) , par.var , z.' ) ;
    T = feval( sprintf('massT%i', i) , par.var , z.' ) ;
    fg = feval( sprintf('massFg%i', i) , par.var , z.' ) ;
    TMfd = TMfd + T.' * M * fg ; % for
end
w_sd = 0 ; w_in = 0 ;
for i = 1 : par.n_sd
    Tt = feval( sprintf('sprdmpTt%i', i) , par.var , z.' ) ;
    kx = feval( sprintf('sprdmpKx%i', i) , par.var , z.' ) ;
    in = feval( sprintf('sprdmpIn%i', i) , par.var , z.' ) ;
    w_sd = w_sd + Tt * kx ;
    w_in = w_in + Tt * in ;
end
w_f = 0 ;
for i = 1 : par.n_ex
    Ttf = feval( sprintf('loadTt%i', i) , par.var , z.' ) ;
    w_f = w_f + Ttf * f_ex(i,:).' ;
end

% EOM static equl.
fval = TMfd + w_sd + w_in + w_f ;

% % C++
% fval = EOM_Ccnt( q , uq , par.var , par.TMTi(:,:,i_cnt) , par.TMfd , par.w_vd_j , par.nq , par.nlambda , cnt ) ;

 
