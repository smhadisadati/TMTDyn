% EOM Simulation (for 3-modoule system):
% 1 modules planar lumped model with 3 elements and one external load
% 2 DOF symmetric CC plannar

clc
clear all
close all
format shorte
pause( 1e-2 )


%% parameters:
syms dummy 
l_b = 1e-3 ;
l_s = 0 ;
m_e = 2 ;
I_e = 1e-12 * eye(3) ;
springCoeff1 = 20 ;
springCoeff2 = 10 ;
dampViscous1 = 1 ;
dampViscous2 = 0.2 ;
g = -9.81 ;


%% inputs: Make sure everything is defined to be empty if no vaue is assigned
world.g = [ 0 , 0 , g ] ; % gravity vector

body(1).type = 'rigid' ;
body(1).tip = [ 0 0 l_b ] ;
body(1).m = m_e ;
body(1).I = I_e ;
body(1).l_com = [ 0 0 l_b/2 ] ;

body(2).type = 'rigid' ;
body(2).tip = [ 0 0 l_b ] ;
body(2).m = m_e ;
body(2).I = I_e ;
body(2).l_com = [ 0 0 l_b/2 ] ;

joint(1).first = 0 ; % first body number, 0 for inertial frame
joint(1).second = 1 ; % second body number, 0 for inertial frame
joint(1).tr(1).trans = [ 0 0 inf ] ; % position vector w.r.t. & exp. in prev. joint local frame
joint(1).tr(1).rot = [ 0 0 ] ; % position vector w.r.t. & exp. in prev. joint local frame
joint(1).tr2nd = [] ; % definitions
joint(1).dof(1).equal2 = [] ;
joint(1).dof(1).init = l_s ;
joint(1).dof(1).spring = [ springCoeff1 , l_s ] ;
joint(1).dof(1).damp = [ dampViscous1 , 0 ] ;

% a  module as external load
joint(2).first = 1 ;
joint(2).second = 2 ;
joint(2).tr(1).trans = [ 0 0 inf ] ; % this is mid-base sensor position
joint(2).tr(1).rot = [ 0 0 ] ;
joint(2).tr2nd = [] ; % definitions
joint(2).dof(1).equal2 = [] ;
joint(2).dof(1).init = l_s ;
joint(2).dof(1).spring = [ springCoeff2 , l_s ] ;
joint(2).dof(1).damp = [ dampViscous2 , 0 ] ;

exload = [] ; % definition
exload(1).body = 2 ; % point of contact body number
exload(1).tr(1).trans = [ 0 0 0 ] ; % point translation and rotation vector w.r.t & exp. in local frame
exload(1).tr(1).rot = [ 0 0 ] ;



%% EOM:
par.save = 1 ; par.sym = [ dummy ] ;  % symbolic parameters
[ qf , uf , lambdaf , sf , qf0 , par ] = TMTEoM_SC ( world , body , joint , exload  , par );


%% numerical simulation
par.t0 = 0 ; par.dt = 100 ; % final tmie: 218
par.stepT = 1e-1 ; % time step for sensor readings is 0.025
par.symV = 1 ; % value for lambdal
[ t , z , tfinal ] = Sim_EliFoot_v0_1( qf , uf , lambdaf , sf , qf0 , par ) ;
figure ; plot( t , z(:,1:2) ) ;
hold on ; plot( t , z(:,2)+z(:,1) ) ;
pause ;


%% animation
par.skip = 1 ; % step skip
par.pause = 1e-2 ; % pause time
rjtip = AnimEOM_G( qf , uf , t , z , par );
% plot
[ ~ , ~ , n_p ] = size( rjtip ) ;
figure ; plot( t' , reshape( rjtip(end,4:6,:) , [ 3 , n_p ] )' ) ;


