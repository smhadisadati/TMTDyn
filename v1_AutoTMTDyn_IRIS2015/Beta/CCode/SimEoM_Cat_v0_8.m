%% EOM Numerical Integrator:
% ====================================================
% change this for different scenarios

function [ t , z , tfinal , par ] = SimEoM_Cat_v0_8( z0 , par )
t0 = par.t0 ; dt = par.dt ; stepT = par.stepT ;

global n_rep n_imp
[ par.nq , par.nu , par.nlambda , par.qf0 , par.n_m , par.n_sd , par.n_cn , par.nlambda , par.n_ex ] = nqF( par.var ) ; % states' number and init. value
par.nlambda = 2 ; % added 2 constrains

if isempty( z0 ) % check if z0 is provided
    n_rep = 0 ; % report counter
    n_imp = 0 ; % impulse exert flag
    eps = 0 ; % for singularity prevention
    z0 = [ eps+double( par.qf0 ) eps*ones( 1 , par.nlambda ) eps*ones( 1 , par.nq ) eps*ones( 1 , par.nlambda ) ] ; % initial condition
end

% ODE Solver
tspan = t0 : stepT : t0 + dt ;

% Matlab ODE:
options = odeset ( 'AbsTol' , 1e-24 , 'RelTol' , 1e-24 ) ;
[ t , z , tfinal ] = ode113( @EOM , tspan , z0 , options , par ) ;

% % Forwrd integration
% t = t0 ; z(1,:) = z0 ; i = 1 ;
% for t_step = tspan
%     z(i+1,:) = z(i,:) + EOM ( t(end) , z(end,:)' , par )' * stepT  ;
%     t(i+1,1) = t_step ;
%     i = i + 1 ;
% end


function dz = EOM ( t , z , par )
% global n_rep
% % t
% if floor( t / par.t_rep ) == n_rep
%     t % report time
%     n_rep = n_rep + 1 ; % report once
% end
% t
% [ t z' ]

% z = real( z ) ; % small numerical errors
q = z( 1 : par.nq + par.nlambda ) ;
u = z( par.nq + par.nlambda + 1 : end ) ;
uq = u( 1 : par.nq ) ;

% Inputs angles:
amp = [ 85 80 ] * pi / 180 ;
freq = [ 2 2 ] * 2 * pi ;
input = [ - amp(1) * freq(1) ^ 2 * cos( freq(1) * t - pi ) ;
          - amp(2) * freq(2) ^ 2 * sin( freq(2) * t ) ] ;

% Matlab
n_m = par.n_m ;
n_sd = par.n_sd ;
n_ex = par.n_ex ;
n_cnt = par.n_cnt ;
TMT = 0 ; TMfd = 0 ;
w_vd_j = 0 ; w_sd = 0 ; w_in = 0 ;
w_f = 0 ;
for i = 1 : n_m
    M = feval( sprintf('massM%i', i) , par.var , z.' ) ;
    T = feval( sprintf('massT%i', i) , par.var , z.' ) ;
    Dd = feval( sprintf('massDd%i', i) , par.var , z.' ) ;
    fg = feval( sprintf('massFg%i', i) , par.var , z.' ) ;
    TMT = TMT + T.' * M * T ;
    TMfd = TMfd + T.' * M * ( - Dd * uq + fg ) ; % for
end
% for i = 1 : n_sd
%     Tt = feval( sprintf('sprdmpTt%i', i) , par.var , z.' ) ;
%     kx = feval( sprintf('sprdmpKx%i', i) , par.var , z.' ) ;
%     vd = feval( sprintf('sprdmpVd%i', i) , par.var , z.' ) ;
%     in = feval( sprintf('sprdmpIn%i', i) , par.var , z.' ) ;
%     w_vd_j = w_vd_j + Tt * vd ;
%     w_sd = w_sd + Tt * kx ;
%     w_in = w_in + Tt * in ;
% end
% for i = 1 : n_ex
%     Ttf = feval( sprintf('loadTt%i', i) , par.var , z.' ) ;
%     w_f = w_f + Ttf * f_ex(i,:).' ;
% end

% constraints
T_cnt = [ 0 0 0 0 0 0 1 0 ; 0 0 0 0 0 0 0 1 ] ;
TMT_cnt = [ TMT , T_cnt.' ; T_cnt , zeros( par.nlambda , par.nlambda ) ] ;
d_dyn = TMfd + w_sd + w_in + w_vd_j * uq + w_f ;
d_cnt = [ d_dyn ; input ] ;

% EOM
dzt = TMT_cnt \ d_cnt ;

% % C++
% dzt = EOM_Ccnt( q , uq , par.var , par.TMTi(:,:,i_cnt) , par.TMfd , par.w_vd_j , par.nq , par.nlambda , cnt ) ;

dz = [ u ; dzt ];

 
