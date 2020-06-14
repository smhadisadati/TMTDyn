%% initialize
clc
clear all
close all
format shorte
pause( 1e-2 )

syms lambda

g = - 0 * 9.81 ;
l = 20e-3 ; % seg l
l_m = 1e-2; % for animation only
m = 1e-4 ; I = 1e-12 * eye(3) ; % m of water droplets
k_s = 1e-2 ; % k of silk thread
mu = 0 ; % mu from air resistance

n_c = 2 ; % number of circles
n_r = 3 ; % number of radii, n_r * n_c < 7

%% system
world.g = [ 0 , 0 , g ] ; % gravity vector

% Central node:
body(1).type = 'rigid' ; % 'rigid', 'CC_EB', 'VC', default: rigid
                         % VC discrete is CC_EB with many segments
                         % curvilinear frame: [d_y d_x d_z] ~ [ y x z ]
body(1).rigid.m = m ; % mass or mass/length
body(1).rigid.I = I ; % inertia around COM expressed in local frame
body(1).rigid.l_com = [ 0 0 0 ] ; % COM position vector w.r.t & expressed in local frame
body(1).rigid.tip = [ 0 0 l_m ] ; % tip position vector w.r.t & expressed in local curvilinear frame
    
joint(1).first = 0 ; % first body number, 0 for inertial frame
joint(1).second = 1 ; % second body number, 0 for inertial frame
	                  % define second body local frame
joint(1).tr(1).trans = [ inf inf inf ] ; % position vector w.r.t. & exp. in prev. joint local Cartesian frame
joint(1).tr(1).rot = [ 0 0 ] ; % position vector w.r.t. & exp. in prev. joint local frame
	                           % both can be left empty
joint(1).tr2nd = [] ; % definitions
joint(1).dof(1).equal2 = [] ; % equal to another CC_EB parameter [ bodyNumber dofNumberInBody ]
joint(1).dof(1).init = 0 ; % flexible body states' initial condition
joint(1).dof(1).spring = [ 0 0 ] ;
joint(1).dof(1).damp = [ mu 0 ] ;
joint(1).dof(2).init =  0 ;
joint(1).dof(2).spring = [ 0 0 ] ;
joint(1).dof(2).damp = [ mu 0 ] ;
joint(1).dof(3).init = 0 ;
joint(1).dof(3).spring = [ 0 0 ] ;
joint(1).dof(3).damp = [ mu 0 ] ;

% Rest of the nodes:
for i = 1 : n_c % itterate over radius
	for j = 1 : n_r % iterate over Circumference

		k = ( i - 1 ) * n_r + j + 1 ;
		phi = ( j - 1 ) * 2 * pi / n_r ;
		
		body(k).type = 'rigid' ;
		body(k).rigid.m = m ; % mass or mass/length
		body(k).rigid.I = I ; % inertia around COM expressed in local frame
		body(k).rigid.l_com = [ 0 0 0 ] ; % COM position vector w.r.t & expressed in local frame
		body(k).rigid.tip = [ 0 0 l_m ] ; % tip position vector w.r.t & expressed in local curvilinear frame
		
		% DOF
		joint(k).first = 0 ; % first body number, 0 for inertial frame
		joint(k).second = k ; % second body number, 0 for inertial frame
				              % define second body local frame
		joint(k).tr(1).trans = [ inf inf inf ] ; % position vector w.r.t. & exp. in prev. joint local Cartesian frame
		joint(k).tr(1).rot = [ 0 0 ] ; % position vector w.r.t. & exp. in prev. joint local frame
				                       % both can be left empty
		joint(k).tr2nd = [] ; % definitions
		joint(k).dof(1).equal2 = [] ; % equal to another CC_EB parameter [ bodyNumber dofNumberInBody ]
		joint(k).dof(1).init = i * l * sin( phi ) ; % flexible body states' initial condition
		joint(k).dof(1).spring = [ 0 0 ] ;
		joint(k).dof(1).damp = [ mu 0 ] ;
		joint(k).dof(2).init =  i * l * cos( phi ) ;
		joint(k).dof(2).spring = [ 0 0 ] ;
		joint(k).dof(2).damp = [ mu 0 ] ;
		joint(k).dof(3).init = 0 ;
		joint(k).dof(3).spring = [ 0 0 ] ;
		joint(k).dof(3).damp = [ mu 0 ] ;

		% Radial Springs to previous radial m
		ks = 1 + n_c * n_r + 2 * ( ( i - 1 ) * n_r + j ) - 1 ; % after the last mass which is 1 + n_r * n_c
        k_r = ( i - 2 ) * n_r + j + 1 ; if i < 2 ; k_r = 1 ; end % previous radial m
		joint(ks).first = k_r ; % first body number, 0 for inertial frame
		joint(ks).second = k ; % second body number, 0 for inertial frame
				              % define second body local frame
		joint(ks).tr(1).trans = [ 0 0 0 ] ; % position vector w.r.t. & exp. in prev. joint local Cartesian frame
		joint(ks).tr(1).rot = [ 0 0 ] ; % position vector w.r.t. & exp. in prev. joint local frame
				                        % both can be left empty
		joint(ks).tr2nd.trans = [ 0 0 0 ] ; % definitions
		joint(ks).tr2nd.rot = [ 0 0 ] ; % definitions
		joint(ks).spring = [ k_s l ] ;
		joint(ks).damp = [ 0 0 ] ;
        
        if i == n_c % outer spring to fixed frame
            kso = 1 + 3 * ( n_c * n_r ) + j ;            
            joint(kso).first = k ; % first body number, 0 for inertial frame
            joint(kso).second = 0 ; % second body number, 0 for inertial frame
            % define second body local frame
            joint(kso).tr(1).trans = [ 0 0 0 ] ; % position vector w.r.t. & exp. in prev. joint local Cartesian frame
            joint(kso).tr(1).rot = [ 0 0 ] ; % position vector w.r.t. & exp. in prev. joint local frame
            % both can be left empty
            joint(kso).tr2nd.trans = ( i + 1 ) * l * [ sin( phi ) cos( phi ) 0 ] ; % definitions
            joint(kso).tr2nd.rot = [ 0 0 ] ; % definitions
            joint(kso).spring = [ k_s l ] ;
            joint(kso).damp = [ 0 0 ] ;
        end

		% Circumferential Springs to next Circumferential m
		ks = ks + 1 ;
		l_c = sqrt( 2 * ( i * l ) ^ 2 * ( 1 - cos( 2 * pi / n_r ) )  ) ; % Circumferential spring initial length
        k_b = k + 1 ; if k_b > i * n_r + 1 ; k_b = ( i - 1 ) * n_r + 1 + 1 ; end % end m on c attache to the first one
		joint(ks).first = k_b ; % first body number, 0 for inertial frame
		joint(ks).second = k ; % second body number, 0 for inertial frame
				              % define second body local frame
		joint(ks).tr(1).trans = [ 0 0 0 ] ; % position vector w.r.t. & exp. in prev. joint local Cartesian frame
		joint(ks).tr(1).rot = [ 0 0 ] ; % position vector w.r.t. & exp. in prev. joint local frame
				                        % both can be left empty
		joint(ks).tr2nd.trans = [ 0 0 0 ] ; % definitions
		joint(ks).tr2nd.rot = [ 0 0 ] ; % definitions
		joint(ks).spring = [ k_s l_c ] ;
		joint(ks).damp = [ 0 0 ] ;

	end
end

exload = [] ; % definition
exload(1).body = 1 ; % point of contact bosdy number
exload(1).tr(1).trans = [ 0 0 0 ] ; % point translation and rotation vector w.r.t & exp. in local Cartesian frame
exload(1).tr(1).rot = [ 0 0 ] ;


%% EOM:
par.save = 1 ; par.sym = [ lambda ] ;  % symbolic parameters
[ qf , uf , lambdaf , sf , qf0 , par ] = TMTEoM_SC ( world , body , joint , exload  , par );


%% numerical simulation
par.t0 = 0 ; par.dt = 10 ; par.stepT = 1e-3 ;
[ t , z , tfinal ] = SimEoM_Spider_v0_1( qf , uf , lambdaf , sf , qf0 , par ) ;
plot ( t , z(:,1:end/2) , 'LineWidth' , 2 ) ;


%% animation
par.skip = 20 ; % step skip
par.pause = 25e-3 ; % pause time
par.symV = 0 ;
rjtip = AnimEOM_G( qf , uf , t , z , par );



