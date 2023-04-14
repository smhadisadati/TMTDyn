%% EOM Numerical Integrator:
% ====================================================
% change this for different scenarios

function [ t , z , tfinal ] = SimEoM_EB_v0_3( qf , uf , lambdaf , sf , qf0 , par )
t0 = par.t0 ; dt = par.dt ; stepT = par.stepT ;

[ ~ , nq ] = size( qf ) ;
[ ~ , nlambda ] = size( lambdaf ) ;

eps = 0 ; % for singularity prevention
z0 = [ double( qf0 ) eps*ones( 1 , nlambda ) eps*ones( 1 , nq ) eps*ones( 1 , nlambda ) ] ; % initial condition

% Standard ODE solver:
par.nq = nq ; par.nlambda = nlambda ;
options = odeset () ;  %,'abstol',1*1e-6,'reltol',1*1e-6) ;
tspan = t0 : stepT: t0 + dt ;
[ t , z , tfinal ] = ode113( @EOM , tspan , z0 , options , par ) ;


function dz = EOM ( t , z , par )
if mod( t , 1 ) < 1e-6 ; t % report every second
end

% lambdal = 1 ;
lambdal = z(1) / par.l_b ;

% pressure parameters
d_p = par.d_p ; a_p = par.a_p / sqrt( lambdal ) ;

p_i = [ par.p_rho( floor( t * 1/par.stepT + 1 ) , 1 ) ...
    par.p_rho( floor( t * 1/par.stepT + 1 ) , 2 ) ...
    par.p_rho( floor( t * 1/par.stepT + 1 ) , 3 ) ] - [ 1 1 1 ] * 1e5 ;

psi = par.phi_b + atan2( ( sqrt( 3 ) * ( p_i(2) + p_i(3) - 2 * p_i(1) ) ) , ( 3 * ( p_i(2) - p_i(3) ) ) ) - pi / 2 ;
fj = [ ( p_i(1) + p_i(2) + p_i(3) )*a_p + ...
        -( p_i(1) * cos( - psi ) + p_i(2) * cos( 2 * pi / 3 - psi ) + p_i(3) * cos( - 2 * pi / 3 - psi ) )*a_p*d_p/2*z(2) ;
    -( p_i(1) * cos( - psi ) + p_i(2) * cos( 2 * pi / 3 - psi ) + p_i(3) * cos( - 2 * pi / 3 - psi ) )*a_p*d_p/2*z(1) ;
    -( p_i(1) * sin( - psi ) + p_i(2) * sin( 2 * pi / 3 - psi ) + p_i(3) * sin( - 2 * pi / 3 - psi ) )*a_p*d_p/2*z(1)*z(2) ] ;

fex = [ 0 0 0 ] ;

u = z( par.nq + par.nlambda + 1 : end ) ;

% for rigid elements
M = double( MF( lambdal , z.' ) ) ;
T = double( TF( lambdal , z.' ) ) ;
D = double( DdF( lambdal , z.' ) ) ;
fg = double( fgF( lambdal , z.' ) ) ;
fj = fj + double( fjF( lambdal , z.' ) ) ;
Tex = double( TefF( lambdal , z.' ) ) ;

TMTr = T.' * M * T ;
Tdr = T.' * ( fg - M * D * u ) + fj + Tex.' * fex.' ;

% for non-rigid elements
TMTc = 0 ; Tdc = 0 ;
if par.nC ~= 0
    [ TMTc , Tdc ] = crvint( lambdal , z , u ) ;
end

% EOM
TMT = TMTr + TMTc ; Td = Tdr + Tdc ;
dzt = TMT \ Td ;
dz = [ u ; dzt ];


function [ TMTc , Tdc ] = crvint( var , z , u )
% trapezoidal numerical integration
intlim = double( intlimF( var , z.' ) ) ;

n = 10 ; % integration step
TMTc = 0 ; Tdc = 0 ;
for i = 0 : 1/n : 1 
    
    s = i * intlim ;
    
    MC = double( MCF( var , z.' , s ) ) ;
    TC = double( TCF( var , z.' , s ) ) ;
    DC = double( DdCF( var , z.' , s ) ) ;
    fgC = double( fgCF( var , z.' , s ) ) ;
    
    if i == 0 || i == 1
        TMTc = TMTc + TC.' * MC * TC / 2 ;
        Tdc = Tdc + TC.' * ( fgC - MC * DC * u ) / 2 ;
    else
        TMTc = TMTc + TC.' * MC * TC ;
        Tdc = Tdc + TC.' * ( fgC - MC * DC * u ) ;
    end
    
end

TMTc = TMTc * intlim / n ; Tdc = Tdc * intlim / n ;


