% EOM Simulation (for 3-modoule system):
% 1 modules planar lumped model with 3 elements and one external load
% 2 modules but only one active, only for 2D symmetric CC
% no dynamic for phi

clc
clear all
close all
format shorte
pause( 1e-2 )


%% parameters:
syms lambdal % symbolic parameters

% all points with Cosserat: mean_err = 0.0169 , mean_errprc = 0.2215 , mean_errprcN = 0.2638
l_b = 44e-3 ; l_fs = 10e-3 ;
l_e = l_b + l_fs ;
r_p1 = 5e-3 / 2 ; r_p2 = 6e-3 / 2 ; d_p = 17e-3 ;
r_C1 = 9e-3 / 2 ; r_C2 = 25e-3 / 2 ;
a_p = 2 * pi * r_p1 ^ 2 ;
a_S0 = pi * ( r_C2 ^ 2 - r_C1 ^ 2 ) ;
a_S0 = a_S0 - 3 * a_p ; % hole correction
E = 20e4 ; 
G = E / 3 ;
sigma = 1300 ; % density kg/m^3
g = 9.81 ;
I_1 = pi * ( r_C2^4 - r_C1^4 ) / 4 ;
I_1 = I_1 - ... % corrected cross section
    2 * ( pi * r_p1^4 / 4 + d_p^2 / 4 * a_p ) - ...
    4 * ( pi * r_p1^4 / 4 + ( d_p * sin( pi / 6 ) )^2 / 4 * a_p ) ;
m_b = 24.5e-3 ; m_e = 1e-3 + m_b ;
gamma = 89 * pi / 180 ;
phi_b = 0 ;

I_dz = m_b / 2 * ( r_C2 ^ 4 + r_C1 ^ 4 ) ;
I_dxy = m_b / 12 * ( 3 * ( r_C2 ^ 2 + r_C1 ^2 ) + l_b ^ 2 );
I_ez = m_e / 2 * ( r_C2 ^ 4 + r_C1 ^ 4 ) ;
I_exy = m_e / 12 * ( 3 * ( r_C2 ^ 2 + r_C1 ^2 ) + l_e ^ 2 );

% hole corrections for inertia: DOESN'T REALLY MATTER
m_p = m_b * 3 * a_p / a_S0 ; % imaginary mass of all 6 actuator tubes
I_dz = I_dz - m_p / 2 * ( r_p1 ^ 4 ) - ( d_p / 2 ) ^ 2 * m_p ^ 2 ;
I_dxy = I_dxy - m_p / 12 * ( 3 * ( r_p1 ^ 2 ) + l_b ^ 2 ) - ...
    ( d_p / 2 * ( 1 + 2 * cos( 2 * pi / 3 ) ) ) ^ 2 * 2 * m_p / 6 ; % psi should be considered too
I_ez = I_ez - m_p / 2 * ( r_p1 ^ 4 ) - ( d_p / 2 ) ^ 2 * m_p ^ 2 ;
I_exy = I_exy - m_p / 12 * ( 3 * ( r_p1 ^2 ) + l_e ^ 2 ) - ...
    ( d_p / 2 * ( 1 + 2 * cos( 2 * pi / 3 ) ) ) ^ 2 * 2 * m_p / 6 ;

I_b = I_dxy * eye( 3 ) ; I_b(3,3) = I_dz ;
I_e = I_exy * eye( 3 ) ; I_e(3,3) = I_ez ;

tspringCoeff = 1 / ( lambdal ^ 2 * l_b / E / a_S0 ) ; % translational
tspringCoeff = 1 * tspringCoeff ; % corrected
tspringInit = 0;
tdampViscous = 1e-3;
tdampCoulomb = 0;
rspringCoeff = 1 / ( lambdal ^ 3 / E / I_1 ) ; % rotational
rspringCoeff = 1 * rspringCoeff ; % corrected
rspringInit = 0;
rdampViscous = 4e-5; % 4e-5 for Cosserat
rdampCoulomb = 0;

eps = 1e-3 ; % singularity prevention


%% inputs: Make sure everything is defined to be empty if no vaue is assigned
world.g = [ 0 , 0 , g ] ; % gravity vector

% SHOULD GIVE THE NEARED BODY TO GROUND FIRST
body(1).type = 'CC_EB' ; % 'rigid', 'CC_EB', 'VC', default: rigid
body(1).CC_EB.m = m_b / l_b ; % mass or mass/length
body(1).CC_EB.I = I_b / l_b ; % inertia around COM expressed in local frame
body(1).CC_EB.l_com = [ 0 0 l_b/2 ] ; % COM position vector w.r.t & expressed in local frame
body(1).CC_EB.tip = [ l_b 0 0 ] ; % tip position vector w.r.t & expressed in local curvilinear frame
body(1).CC_EB.stiff = [ tspringCoeff 0 0 0 0 rspringCoeff ] ; % curvilinear translational and rotational stiffness: [ t n b tr nr br ]
                                                              % set to Ea/l, EI/l or GJ/l from EB relation
body(1).CC_EB.viscdamp = [ tdampViscous 0 0 0 0 rdampViscous ] ; % curvilinear translational and rotational damping: [ t n b tr nr br ]
body(1).CC_EB.couldamp = [ tdampCoulomb 0 0 0 0 rdampCoulomb ] ; % curvilinear translational and rotational damping: [ t n b tr nr br ]
body(1).CC_EB.par = [ inf inf inf ] ; % put 'inf' for CC_EB states to be dof and values for fixed directions
                                    % [ l kappa phi ] for CC_EB, 3*body(i).CC_EB.slice for VC
body(1).CC_EB.dof(1).equal2 = [] ; % equal to another CC_EB parameter [ bodyNumber dofNumberInBody ]
body(1).CC_EB.dof(1).init = l_b ; % flexible body states' initial condition
                                  % [ l kappa phi ] for CC_EB, 3*body(i).CC_EB.slice for VC
body(1).CC_EB.dof(1).spring = [ 0 0 ] ;
body(1).CC_EB.dof(1).damp = [ 0 0 ] ;
body(1).CC_EB.dof(2).init = eps ;
body(1).CC_EB.dof(2).spring = [ 0 0 ] ;
body(1).CC_EB.dof(2).damp = [ 0 0 ] ;
body(1).CC_EB.dof(3).init = eps ;
body(1).CC_EB.dof(3).spring = [ 0 0 ] ;
body(1).CC_EB.dof(3).damp = [ 0 0 ] ;

body(2).type = 'rigid' ;
body(2).rigid.m = m_e ;
body(2).rigid.I = I_e ;
body(2).rigid.l_com = [ 0 0 l_b/2 ] ;
body(2).rigid.tip = [ 0 0 l_b ] ;

% first joint ending any body is the main kinematic path and rest are froce and spring and constraints
% express spring/dampers and constraints at the end of the kinematic path joint
joint(1).first = 0 ; % first body number, 0 for inertial frame
joint(1).second = 1 ; % second body number, 0 for inertial frame
                      % define second body local frame
joint(1).tr(1).trans = [ 0 0 l_fs ] ; % position vector w.r.t. & exp. in prev. joint local Cartesian frame
joint(1).tr(1).rot = [ 0 0 ] ; % position vector w.r.t. & exp. in prev. joint local frame
                               % both can be left empty
joint(1).tr2nd = [] ; % definitions

% a  module as external load
joint(2).first = 1 ;
joint(2).second = 2 ;
joint(2).tr(1).trans = [ l_b+l_fs 0 0 ] ; % this is mid-base sensor position in local curvinlinear frame
joint(2).tr(1).rot = [ 0 0 ] ;

exload = [] ; % definition
exload(1).body = 1 ; % point of contact body number
exload(1).tr(1).trans = [ l_b+l_fs 0 0 ] ; % point translation and rotation vector w.r.t & exp. in local curvilinear frame
                                   % on CC_EB.
exload(1).tr(1).rot = [ 0 0 ] ;


%% EOM:
par.save = 1 ; par.sym = [ lambdal ] ;  % symbolic parameters
[ qf , uf , lambdaf , sf , qf0 , par ] = TMTEoM_SC ( world , body , joint , exload  , par );


%% numerical simulation
% clear all
p_rho = csvread( 'p_rho_DataPoints_Dynamic.csv' , 0 , 0 ); % 25 msec intervals
par.p_rho = p_rho ;
par.t0 = 0 ; par.dt = 30 ; % final tmie: 218
par.stepT = 25e-3 ; % time step for sensor readings is 0.025
par.symV = 1 ; % value for lambdal
par.l_b = l_b ; par.phi_b = phi_b ;
par.d_p = d_p ; par.a_p = a_p ;
[ t , z , tfinal ] = SimEoM_EB_v0_4_3D( qf , uf , lambdaf , sf , qf0 , par ) ;
% plot
t_e = par.t0 : par.stepT : par.dt ;
[ ~ , mt ] = size(t_e);
subplot(4,5,1:3) ; plot(t_e,p_rho(1:mt,4),t_e,p_rho(1:mt,5)+1e-2,t_e,p_rho(1:mt,6),'LineWidth' , 2 );
title('position vector for middle tracker');  legend( 'x' , 'y' , 'z' ) ; ylabel( '[m]' ) ;
subplot(4,5,6:8) ; plot(t_e,p_rho(1:mt,1)-1e5,t_e,p_rho(1:mt,2)-1e5,t_e,p_rho(1:mt,3)-1e5,'LineWidth' , 2 );
title('experimentx pressure inputs');  legend( 'p_1' , 'p_2' , 'p_3' ) ; ylabel( 'P [KPa]' ) ; xlabel( 't [s]' ) ;
% subplot(4,5,11:13) ; plot ( t , z(:,1:end/2) , 'LineWidth' , 2 ) ;
% title('states') ; legend( 'l_1' , '\theta') ;
subplot(4,5,11) ; plot ( t , z(:,1) , 'LineWidth' , 2 ) ;
title('linear elongation states') ; legend( 'l_1' ) ; ylabel( 'l [m]' ) ; xlabel( 't [s]' ) ;
subplot(4,5,13) ; plot ( t , z(:,2) , 'LineWidth' , 2 ) ;
title('curvature states') ; legend( '\kappa_1' ) ; ylabel( '\kappa [1/m]' ) ; xlabel( 't [s]' ) ;
pause;


%% animation
par.skip = 20 ; % step skip
par.pause = 25e-3 ; % pause time
rjtip = AnimEOM_G( qf , uf , t , z , par );
% plot
[ ~ , ~ , n_p ] = size( rjtip ) ;
rjt3d = zeros( 1 , 3 , n_p ) ;
for i = 1 : n_p
    p_i = [ p_rho( i , 1 ) p_rho( i , 2 ) p_rho( i , 3 ) ] - [ 1 1 1 ] * 1e5 ;
    tmp = rjtip(1,4:6,i) ; % tip for 1st body
    rjt3d(:,:,i) = tmp ;
    err(i) = sqrt( ( p_rho(i,4:6) - tmp ) * ( p_rho(i,4:6) - tmp )' ) ;
    errprc(i) = err(i) / sqrt( p_rho(i,4:6) * p_rho(i,4:6)' ) ;
    errprcN(i) = err(i) / ( l_b + 2 * l_fs ) ;
end
% rjt3d(end,1:3,:) : base of the second module (mid-base pose)
subplot(4,5,16:18) ; plot( t' , reshape( rjt3d(1,1:3,:) , [ 3 , n_p ] )' , 'LineWidth' , 2 ); % tip position
legend( 'x' , 'y' , 'z' , 'x_{sim}' , 'y_{sim}' , 'z_{sim}' ) ; ylabel( '[m]' ) ;
subplot(4,5,1:3) ; hold on ; plot( t' , reshape( rjt3d(1,1:3,:) , [ 3 , n_p ] )' , '--' , 'LineWidth' , 2 ); % tip position
legend( 'x' , 'y' , 'z' , 'x_{sim}' , 'y_{sim}' , 'z_{sim}' ) ;
% figure; plot( psi ) ; title( '\psi' ) ;

%report:
mean_err = mean( err )
mean_errprc = mean( errprc )
mean_errprcN = mean( errprcN )


