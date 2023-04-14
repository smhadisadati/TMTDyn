% EOM Simulation (for 3-modoule system):
% 1 modules planar lumped model with 3 elements and one external load
% 2 DOF symmetric CC plannar

clc
clear all
close all
format shorte
pause( 1e-2 )


%% parameters:
syms dummy % symbolic parameters

% all points with Cosserat: mean_err = 0.0169 , mean_errprc = 0.2215 , mean_errprcN = 0.2638
l_1 = 2e-3 ;
l_2 = 5e-3 ;
l_3 = 220e-3 ;
r_1 = 2e-3 / 2 ;
r_2 = 10e-3 ;
r_3 = 0.5-3 ;
a_1 = pi * r_1 ^ 2 ;
a_3 = pi * r_3 ^ 2 ;
E1 = 10e4 ;
E3 = 1e4 ;
g = 0 ;
i_1 = pi * r_1^4 / 4 ;
i_3 = pi * r_3^4 / 4 ;
m_1 = 1e-3 ;
m_2 = 0.5e-3 ;
m_3 = 1e-3 ;

kt1 = 1 / ( l_1 / E1 / a_1 ) ; % translational
cvt1 = 1e-4 ;
cct1 = 0 ;
kbr1 = 1 / ( l_1 / E1 / i_1 ) ; % rotational
cvbr1 = 1e-4 ;
ccbr1 = 0 ;

kt3 = 1 / ( l_3 / E3 / a_3 ) ; % translational
cvt3 = 1e-4 ;
cct3 = 0 ;
kbr3 = 1 / ( l_3 / E3 / i_3 ) ; % rotational
cvbr3 = 1e-4 ;
ccbr3 = 0 ;

I_dz1 = m_1 / 2 * r_1 ^ 4 ;
I_dxy1 = m_1 / 12 * ( 3 * r_1 ^ 2 + l_1 ^ 2 );
I_1 = I_dxy1 * eye( 3 ) ; I_1(3,3) = I_dz1 ;
I_dz2 = m_2 / 2 * r_2 ^ 4 ;
I_dxy2 = m_2 / 12 * ( 3 * r_2 ^ 2 + l_2 ^ 2 );
I_2 = I_dxy2 * eye( 3 ) ; I_2(3,3) = I_dz2 ;
I_dz3 = m_3 / 2 * r_3 ^ 4 ;
I_dxy3 = m_3 / 12 * ( 3 * r_3 ^ 2 + l_3 ^ 2 );
I_3 = I_dxy3 * eye( 3 ) ; I_3(3,3) = I_dz3 ;

eps = 1e-3 ; % singularity prevention


%% inputs: Make sure everything is defined to be empty if no vaue is assigned
world.g = [ 0 , g , 0 ] ; % gravity vector

% SHOULD GIVE THE NEARED BODY TO GROUND FIRST
body(1).type = 'EB-CC' ; % 'rigid', 'EB-CC', 'VC', default: rigid
body(1).m = m_1 / l_1 ; % mass or mass/length
body(1).I = I_1 / l_1 ; % inertia around COM expressed in local frame
body(1).l_com = [ 0 0 l_1/2 ] ; % COM position vector w.r.t & expressed in local frame
body(1).tip = l_1 ; % tip position vector w.r.t & expressed in local frame
body(1).curve.stiff = [ kt1 0 0 0 0 kbr1 ] ; % curvilinear translational and rotational stiffness: [ t n b tr nr br ]
body(1).curve.viscdamp = [ cvt1 0 0 0 0 cvbr1 ] ; % curvilinear translational and rotational damping: [ t n b tr nr br ]
body(1).curve.couldamp = [ cct1 0 0 0 0 ccbr1 ] ; % curvilinear translational and rotational damping: [ t n b tr nr br ]
body(1).curve.par = [ l_1 inf 0 ] ; % put 'inf' for curve states to be dof and values for fixed directions
body(1).curve.dof(1).equal2 = [] ; % equal to another curve parameter [ bodyNumber dofNumberInBody ]
body(1).curve.dof(1).init = eps ;
body(1).curve.dof(1).spring = [ 0 0 ] ;
body(1).curve.dof(1).damp = [ 0 0 ] ;

body(2).type = 'EB-CC' ; % 'rigid', 'EB-CC', 'VC', default: rigid
body(2).m = m_3 / l_3 ; % mass or mass/length
body(2).I = I_3 / l_3 ; % inertia around COM expressed in local frame
body(2).l_com = [ 0 0 l_3/2 ] ; % COM position vector w.r.t & expressed in local frame
body(2).tip = l_3 ; % tip position vector w.r.t & expressed in local frame
body(2).curve.stiff = [ kt3 0 0 0 0 kbr3 ] ; % curvilinear translational and rotational stiffness: [ t n b tr nr br ]                      % set to Ea/l, EI/l or GJ/l from EB relation
body(2).curve.viscdamp = [ cvt3 0 0 0 0 cvbr3 ] ; % curvilinear translational and rotational damping: [ t n b tr nr br ]
body(2).curve.couldamp = [ cct3 0 0 0 0 ccbr3 ] ; % curvilinear translational and rotational damping: [ t n b tr nr br ]
body(2).curve.par = [ l_3 inf 0 ] ; % put 'inf' for curve states to be dof and values for fixed directions
body(2).curve.dof(1).equal2 = [] ; % equal to another curve parameter [ bodyNumber dofNumberInBody ]
body(2).curve.dof(1).init = eps ; % flexible body states' initial condition
body(2).curve.dof(1).spring = [ 0 0 ] ;
body(2).curve.dof(1).damp = [ 0 0 ] ;

% first joint ending any body is the main kinematic path and rest are froce and spring and constraints
% express spring/dampers and constraints at the end of the kinematic path joint
joint(1).first = 0 ; % first body number, 0 for inertial frame
joint(1).second = 1 ; % second body number, 0 for inertial frame
joint(1).tr(1).trans = [ 0 0 0 ] ; % position vector w.r.t. & exp. in prev. joint local frame
joint(1).tr(1).rot = [ 0 0 ] ; % position vector w.r.t. & exp. in prev. joint local frame
joint(1).tr2nd = [] ; % definitions

% a  module as external load
joint(2).first = 1 ;
joint(2).second = 2 ;
joint(2).tr(1).trans = l_1 ; % this is mid-base sensor position
joint(2).tr(1).rot = [ 0 0 ] ;

exload = [] ; % definition
exload(1).body = 2 ; % point of contact body number
exload(1).tr(1).trans = l_3 ; % point translation and rotation vector w.r.t & exp. in local frame
                                           % can have rotation matrix as well.
exload(1).tr(1).rot = [ 0 0 ] ;


%% EOM:
par.save = 1 ; par.sym = [ dummy ] ;  % symbolic parameters
[ qf , uf , lambdaf , sf , qf0 , par ] = TMTEoM_SC ( world , body , joint , exload  , par );


%% numerical simulation
par.t0 = 0 ; par.dt = 1 ; % final tmie: 218
par.stepT = 1e-1 ; % time step for sensor readings is 0.025
par.symV = 1 ; % value for lambdal
[ t , z , tfinal ] = SimEoM_Wisker_v0_1( qf , uf , lambdaf , sf , qf0 , par ) ;
figure ; plot( t , z(:,1:2) ) ;
pause ;


%% animation
par.skip = 20 ; % step skip
par.pause = 1e-2 ; % pause time
rjtip = AnimEOM_G( qf , uf , t , z , par );
% plot
[ ~ , ~ , n_p ] = size( rjtip ) ;
figure ; plot( t' , reshape( rjtip(end,4:6,:) , [ 3 , n_p ] )' ) ;


