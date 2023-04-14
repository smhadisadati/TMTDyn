%% EOM Numerical Integrator:
% ====================================================
% change this for different scenarios

function [ t , z , tfinal ] = SimEoM_Wisker_v0_1( qf , uf , lambdaf , sf , qf0 , par )
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
if mod( t , 1e-2 ) < 1e-6 ; t % report every second
end
% t

fj = 0 * 0.02*sin( pi * t ) * [ 1 ; 1 ] ;
fex = [ 0.001*sin( 2 * pi * t ) , 0 , 0 ] ;
var = 0 ;

u = z( par.nq + par.nlambda + 1 : end ) ;

% for rigid elements
M = double( MF( var , z.' ) ) ;
T = double( TF( var , z.' ) ) ;
D = double( DdF( var , z.' ) ) ;
fg = double( fgF( var , z.' ) ) ;
fj = fj + double( fjF( var , z.' ) ) ;
Tex = double( TefF( var , z.' ) ) ;

TMTr = 0 ;
Tdr = fj + Tex.' * fex.' ;
if par.nb - par.nC ~= 0 % if there is a rigid body
    TMTr = T.' * M * T ;
    Tdr = T.' * ( fg - M * D * u ) + Tdr ;
end

% for non-rigid elements
TMTc = 0 ; Tdc = 0 ;
if par.nC ~= 0 % if there is a continuum body
    [ TMTc , Tdc ] = crvint( var , z , u ) ;
end

% EOM
TMT = TMTr + TMTc ; Td = Tdr + Tdc ;
dzt = TMT \ Td ;
dz = [ u ; dzt ];

% if abs(dzt)>10; dzt
% end


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

TMTc = TMTc / n ; Tdc = Tdc/ n ;


