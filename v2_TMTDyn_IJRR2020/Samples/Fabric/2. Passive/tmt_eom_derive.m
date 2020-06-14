%% TMT EOM Derivator for Single Elements:
% ===========================================
% [ qf , uf , lambdaf , qf0 , par ] = ...
%     tmt( world , body , joint , exload  , par ) % discrete implementation
%
% ===========================================
% Author:
% S.M.Hadi Sadati, PhD in Robotics
% Research Associate in Morphological Computation with Spiders' Web
% University of Bristol
% s.m.hadi.sadati@bristol.ac.uk
% 2018
%
% ===========================================
% Help:
%
% Inputs:
% ...
%
% Outputs:
% M : Mass matrix
% T : Transformation matrix
% Dd : Damping/Stiffness matrix
% fg : Gravity force virtual work
% fj : Joint stiffness/damping virtual work acting directly on generalized coordinates
% rj : 3 first elements are for Joint absolute position vector in base frame
%	  and the last element the number of the previous element ( 0 for series link part )
% rc : Joint COM absolute position vector in base frame
% vc : Joint COM absolute linear velocity vector in base frame
% wc : Joint COM absolute rotational velocity vector in link frame
% ref: External force/torque position vector
% rcn: Constraint location ( Useful for parallel mechanisms )
% Tef: External force/torque position vector Jacobian w.r.t. generalized coord.s
% Tcn: Constraint location Jacobian w.r.t. generalized coord.s
% Dcn: Remain terms in Constraint 2nd time location derivation
% dwC: divergence of chamber body stored energy
% dwG: divergence of gas work
% qf : Generalized coordinates
% uf : Generalized coordinates derivatives
% pf : input pressures for the CCCM
% 
% ============================================
% Example:
% ...
%
% ============================================


%% Main:
function [ q , u , lambda , par ] = ...
    tmt_eom_derive( par , world , body , joint , exload , mesh ) % discrete implementation
fprintf( 'TMT derive... \n' )
par.elapsed_time = [ par.elapsed_time toc( par.timer ) ] ;
toc( par.timer )

global unit_quat
unit_quat = 1 ; % is unit quaternion?

% mesh
if ~isempty( mesh )
    [ ~ , ~ , body , joint ] = check( par , [] , body , joint , [] , [] ) ; % not mesh body/joint check
	[ body_mesh , joint_mesh ] = mesh_import( body , joint , mesh , par ) ; % mesh import
	body = [ body body_mesh ] ; % first indvidual bodies
	joint = [ joint_mesh joint ] ; % first mesh joints
end

% all check
[ s , world , body , joint , exload , par , symbols ] = check( par , world , body , joint , exload , mesh ) ;

% >> Initialization:
[ ~ , n_b ] = size( body ) ; % number of bodies
[ ~ , n_ex ] = size( exload ) ; % number of ext. forces/torques
[ ~ , n_j ] = size( joint ) ; % number of joints

% [ q_sym , u_sym , lambda_sym ] = variables( par.derive ) ; % symbolic variables

M = sym( [] ) ; fgv = M ; T = M ; Dd = M ;
q = sym( [] ) ; u = q ; q0 = q ; % all dofs
lambda = q ; dlambda = q ;
r_j = sym( [] ) ; r_c = r_j ; ref = r_j ; rcn = r_j ;
r_jtips = r_j ; r_ks = r_j ;
mass = [] ; sprdmp = mass ; cnst = mass ; loads = mass ;


% >> Derivation:

n_sd = 0 ; % spring/damper counter
nq = 0 ; nq_mat = [ 0 0 0 ] ; % total dof counter
n_cn = 0; % constraint position counter
fj_k = sym( 0 ) ; % for joint spring
fj_vd = sym( 0 ) ; % for joint viscous damping
fj_in = sym( 0 ) ; %for joint Coulomb damping
fj_k_mat = sym( 0 ) ;
fj_sdi = sym( 0 ) ;
fj_vd_mat = sym( 0 ) ;


% all joints
dof_m = [] ; % 3x3 cube
rom.sprdmp = [] ; % reduced order model indicator
for j_count = 1 : n_j % look into all joints
    j_count
    
    for n_mesh = 1 : max( [ numel( joint(j_count).first ) , numel( joint(j_count).second ) ] ) - 1
        nj_dof = 0 ; % dof counter in each joint
        joint(j_count).Q(n_mesh).loc = sym( [ 1 0 0 0 ].' );
        joint(j_count).TQ(n_mesh).loc = sym( [ 1 0 0 0 ; 0 0 0 0 ].' );
        
        [ ~ , nj_tr ] = size( joint(j_count).tr ) ; % number of transforamtions in a joint
        for i3 = 1 : nj_tr
            rotrans = sym( [ joint(j_count).tr(i3).trans joint(j_count).tr(i3).rot ] ) ;
            
            isq = 0 ; % if quat. rot. contains states
            for i2 = 1 : numel( rotrans )
                if rotrans(i2) == inf  
                    
                    if i2 > 3 % rot with dof
                        isq = 1 ;
                    end
                    
                    dof_mult = 1 ; % single dof
                    if ~isempty( joint(j_count).rom ) % reduced order model
                        dof_mult = joint(j_count).rom.order ;
                    end
                    
                    nj_dof = nj_dof + 1;
                    
                    for i_dof = 1 : dof_mult
                        
                        if isempty( joint(j_count).dof(nj_dof).equal2 )
                            n_sd = n_sd + 1 ;
                            nq = nq + 1;
                            nq_mat = [ j_count nj_dof nq n_sd ] ;
                            dof_m(:,:,nj_dof,n_mesh,j_count) = [ nq n_sd ] ; % dof number
                            % q = [ q , q_sym(nq) ];
                            q = [ q , sym( [ 'q' num2str( nq ) ] ) ];
                            q0 = [ q0 , joint(j_count).dof(nj_dof).init(n_mesh,dof_mult) ] ; % only all element ICs in an array
                            % u = [ u , u_sym(nq) ];
                            u = [ u , sym( [ 'u' num2str( nq ) ] ) ];
                            assume( q , 'real' ) ;
                            assume( u , 'real' ) ;
                            fj_k(nq,1) = 0 ;
                            fj_vd(nq,1) = 0 ;
                            fj_in(nq,1) = 0 ;
                            fj_k_mat(nq,nq) = 0 ;
                            fj_vd_mat(nq,nq) = 0 ;
							if isnan( joint(j_count).dof(nj_dof).spring.init(n_mesh) )
								joint(j_count).dof(nj_dof).spring.init(n_mesh,dof_mult) = joint(j_count).dof(nj_dof).init(n_mesh) ;
							end
                        else % geometrical constraint between dof.s, for rigid body dof.s only
                        	temp = joint(j_count).dof(nj_dof).equal2(n_mesh,:) ;
                            nq_mat(1:2) = temp([1,3]) ;
                            nq_mat(3:4) = dof_m( 1 , : , temp(3) , temp(2) , temp(1) ) ;
                        end
                        
                        % for each spring
                        rom.sprdmp = [ rom.sprdmp 0 ] ;
                        sprdmp(nq_mat(4)).Tt(nq_mat(3),1) = 1 ;
                        sprdmp(nq_mat(4)).kx = - joint(nq_mat(1)).dof(nq_mat(2)).spring.coeff(n_mesh) * ...
                        	( q(nq_mat(3)) - joint(nq_mat(1)).dof(nq_mat(2)).spring.compr(n_mesh) * joint(nq_mat(1)).dof(nq_mat(2)).spring.init(n_mesh) ) ; % spring
                        sprdmp(nq_mat(4)).dl = q(nq_mat(3)) - joint(nq_mat(1)).dof(nq_mat(2)).spring.init(n_mesh) ; % spring delta-l
                        sprdmp(nq_mat(4)).vd = - joint(nq_mat(1)).dof(nq_mat(2)).damp.visc(n_mesh) ...
                            * abs( u(nq_mat(3)) ).^( joint(nq_mat(1)).dof(nq_mat(2)).damp.pow(n_mesh,1) - 1 ) * u(nq_mat(3)) ; % viscous
                        sprdmp(nq_mat(4)).in = joint(nq_mat(1)).dof(nq_mat(2)).input(n_mesh) ; % external input
                        sprdmp(nq_mat(4)).k_mat(1,nq_mat(3)) = joint(nq_mat(1)).dof(nq_mat(2)).spring.coeff(n_mesh) ; % spring
                        sprdmp(nq_mat(4)).vd_mat(1,nq_mat(3)) = - joint(nq_mat(1)).dof(nq_mat(2)).damp.visc(n_mesh) ...
                            * u(nq_mat(3)).^( joint(nq_mat(1)).dof(nq_mat(2)).damp.pow(n_mesh) - 1 ) ; % viscous
                        sprdmp(nq_mat(4)).dir = 1 ;
                        
                        % if ismember( par.derive_collect , [ 3 4 ] )  % for all joint spring/dampers
                            fj_k(nq_mat(3),1) = fj_k(nq_mat(3),1) ... % spring on DOFs
                                + sprdmp(nq_mat(4)).kx ;
                            fj_vd(nq_mat(3),1) = fj_vd(nq_mat(3),1) ... % damper on DOFs
                                + sprdmp(nq_mat(4)).vd ;
                            fj_in(nq_mat(3),1) = fj_in(nq_mat(3),1) ... % inputs on DOFs
                                + sprdmp(nq_mat(4)).in ;
                            fj_sdi(nq_mat(3),1) = sprdmp(nq_mat(4)).kx + sprdmp(nq_mat(4)).vd + sprdmp(nq_mat(4)).in ; % all spring/damper/input force virtual work
                            fj_k_mat(nq_mat(3),nq_mat(3)) = fj_k_mat(nq_mat(3),nq_mat(3)) ... % spring on DOFs
                                + sprdmp(nq_mat(4)).k_mat(1,nq_mat(3)) ;
                            fj_vd_mat(nq_mat(3),nq_mat(3)) = fj_vd_mat(nq_mat(3),nq_mat(3)) ... % damper on DOFs
                                + sprdmp(nq_mat(4)).vd_mat(1,nq_mat(3)) ;
                        % end
                        
                    end
                    
                    if ~isempty( joint(j_count).rom ) % reduced order model
                        rotrans(i2) = q(end-dof_mult+1:end) * joint(j_count).dof(nj_dof).s.' ;
                        if i2 == 3 % z Boundary Condition
                            rotrans(i2) = rotrans(i2) + s ;
                        end
                    else
                        % replace inf with q(iqc(3))
                        rotrans(i2) = q(nq_mat(3));
                    end
                        
                end
                
            end
            
            [ Q_temo , TQ_temo ] = TQ_mat( rotrans , [ q s ] , isq );
            joint(j_count).Q(n_mesh).loc = Q_mult( joint(j_count).Q(n_mesh).loc , Q_temo ) ;
            joint(j_count).TQ(n_mesh).loc = TQ_mult( joint(j_count).TQ(n_mesh).loc , TQ_temo ) ;
            
        end
        
        % for spring/damper and constraints
        if ~isempty( joint(j_count).tr2nd )
            joint(j_count).Q2nd(n_mesh).loc = sym( [ 1 0 0 0 ].' );
            joint(j_count).TQ2nd(n_mesh).loc = sym( [ 1 0 0 0 ; 0 0 0 0 ].' );
            [ ~ , nj_tr ] = size( joint(j_count).tr2nd ) ; % number of transforamtions in a joint
            for i3 = 1 : nj_tr
                [ Q_temo , TQ_temo ] = TQ_mat( [ joint(j_count).tr2nd(i3).trans joint(j_count).tr2nd(i3).rot ] , [ q s ] , 0 );
                joint(j_count).Q2nd(n_mesh).loc = Q_mult( joint(j_count).Q2nd(n_mesh).loc , Q_temo ) ;
                joint(j_count).TQ2nd(n_mesh).loc = TQ_mult( joint(j_count).TQ2nd(n_mesh).loc , TQ_temo ) ;
            end
        end
        
    end
    
end


% Adjustments
for i = 1 : numel( sprdmp )
    if numel( sprdmp(i).Tt ) ~= nq % fill all elements
        sprdmp(i).Tt(nq,1) = 0 ;
        sprdmp(i).vd_mat(1,nq) = 0 ;
        sprdmp(i).k_mat(1,nq) = 0 ;
    end
end


% Start with bodies and creat R|TR. To do so, check R|TR for the
% previous body and if not available creat R|TR for that till reaching
% ground. If the user provides a proper sequence of bodies the sequence of
% generalized coordinates numbers will rational starting frorm 1 for the
% nearest one to the ground
% SHOULD GIVE THE NEARED BODY TO GROUND FIRST
n_m = 0 ; % body type counter [ rigid , other ]
rom.mass = [] ; % reduced order model indicator
for b_count = 1 : n_b % number of bodies
    b_count
              
    for j_count = 1 : n_j % look into all joints
        
        if joint(j_count).second(1) == b_count % if the joint connects this body to another one
            
            for n_mesh = 1 : numel( joint(j_count).first ) - 1
                
                body(b_count).rom = [] ;
                if isempty( joint(j_count).rom )
                    rom.mass = [ rom.mass 0 ] ;
                else
                    body(b_count).rom.l = joint(j_count).second(2) ;
                    rom.mass = [ rom.mass joint(j_count).second(2) ] ;
                end
                
                if joint(j_count).first(1) == 0 || joint(j_count).first(n_mesh+1) == 0 % the joint number where the new frame is connected to on the firstbody
                    joint(j_count).Q(n_mesh).abs = joint(j_count).Q(n_mesh).loc ;
                    joint(j_count).TQ(n_mesh).abs = joint(j_count).TQ(n_mesh).loc ;
                else
                    if isempty( body(joint(j_count).first(1)).rom )
                        Q = body(joint(j_count).first(1)).Q(joint(j_count).first(n_mesh+1)).abs ;
                        TQ = body(joint(j_count).first(1)).TQ(joint(j_count).first(n_mesh+1)).abs ;
                    else
                        Q = body(joint(j_count).first(1)).Q(1).abs ;
                        TQ = body(joint(j_count).first(1)).TQ(1).abs ;
                        Q = subs( Q , s , joint(j_count).first(2) ) ;
                        TQ = subs( TQ , s , joint(j_count).first(2) ) ;
                    end
                    joint(j_count).Q(n_mesh).abs = Q_mult( Q , joint(j_count).Q(n_mesh).loc ) ;
                    joint(j_count).TQ(n_mesh).abs = TQ_mult( TQ , joint(j_count).TQ(n_mesh).loc ) ;
                end
                
                body(b_count).Q(n_mesh).loc = joint(j_count).Q(n_mesh).loc ;
                body(b_count).TQ(n_mesh).loc = joint(j_count).TQ(n_mesh).loc ;
                body(b_count).Q(n_mesh).abs = joint(j_count).Q(n_mesh).abs ;
                body(b_count).TQ(n_mesh).abs = joint(j_count).TQ(n_mesh).abs ;
                
                joint(j_count).r(n_mesh,:) = joint(j_count).TQ(n_mesh).abs(2:4,2).' ;
                if isempty( joint(j_count).rom ) % reduced order model
                    TQ_temp = TQ_mult( body(b_count).TQ(n_mesh).abs , [ 1 0 0 0 ; 0 body(b_count).tip(n_mesh,:) ].' ) ;
                    r_jtips = [ r_jtips ; joint(j_count).r(n_mesh,:) , TQ_temp(2:4,2).' ] ; % each body joint and tip
                else
                    s1 = s * joint(j_count).second(2) ; % normalized curve length
                    r_jtips = [ r_jtips ; subs( joint(j_count).r(n_mesh,:) , s , s1 ) nan nan nan ] ;
                end
                
                n_m = n_m + 1 ;
                im = 6 * n_m ; % 6 elements for mass and inertia matrix
                mass(n_m).M(1:3,1:3) = sym( body(b_count).m(n_mesh) * eye( 3 ) ) ;
                mass(n_m).M(4:6,4:6) = sym( body(b_count).I(:,:,n_mesh) ) ;
                
                temp = jacobian( body(b_count).Q(n_mesh).abs , q ) ;
                temp4 = 2 * Q_mult( Q_conj( body(b_count).Q(n_mesh).abs ) , temp ) ; % omega_loc = 2 * Q^{-1} * Q_{,t}
                body(b_count).omega(n_mesh).abs_loc = ( temp4(2:4,:) * u.' ).' ; % abs omega in local frame
                % body(b_count).T_omega(n_mesh).abs_loc = temp4(2:4,:) ;
                
                mass(n_m).T(4:6,:) = temp4(2:4,:) ;
                mass(n_m).Dd(4:6,:) = jacobian( body(b_count).omega(n_mesh).abs_loc.' , q );
                
                temp7 = TQ_mult( body(b_count).TQ(n_mesh).abs , [ 1 0 0 0 ; 0 body(b_count).l_com(n_mesh,:) ].' ) ;
                body(b_count).r_com(n_mesh,:) = temp7(2:4,2).';
                r_c = [ r_c ; body(b_count).r_com(n_mesh,:) ] ; % COM position for output
                temp8 = jacobian ( temp7(2:4,2) , q );
                body(b_count).v_com(n_mesh,:) = ( temp8 * u.' ).';
                
                mass(n_m).T(1:3,:) = temp8 ;
                mass(n_m).Dd(1:3,:) = jacobian ( body(b_count).v_com(n_mesh,:).' , q );
                
                % gravity generalized work
                mass(n_m).fg = [ world.g 0 0 0 ].' ;
                
                
                if ismember( par.derive_collect , [ 3 4 ] ) % for all masses
                    M( im - 5 : im , im - 5 : im ) = mass(n_m).M ;
                    T ( im - 5 : im , : ) = mass(n_m).T ;
                    Dd ( im - 5 : im , 1 : nq ) = mass(n_m).Dd ;
                    fgv = [ fgv , mass(n_m).fg.' ];
                end
                                
            end
            
            break ; % other joints are spring or dampers and should have .tr2nd
            
        end
        
    end
    
end


% spring/dampers/constraint
% look for the secondary joints that should be constraint or spring/dampers
w_sdi = sym( 0 ) ; % total virt. work
w_k = sym( 0 ) ; % spring virt. work
w_vd = sym( 0 ) ; % viscous dampers virt. work
w_vd_mat = sym( 0 ) ; % viscous dampers virt. work
w_in = sym( 0 ) ; % Coulomb dampers virt. work
w_k_mat = sym( 0 ) ; % spring stiffnes matrix for modal analysis
Dcn = sym( [] ) ; Tcn = Dcn ; Ccn = Dcn ;
for b_count = 0 : n_b % number of bodies
    b_count

    for j_count = 1 : n_j % look into all joints, first one is the main kinematic path and rest are froce and spring and constraints
        
        if joint(j_count).second(1) == b_count && ~isempty( joint(j_count).tr2nd ) % if the joint connects this body to another one
            j_count
            
            for n_mesh = 1 : max( [ numel( joint(j_count).first ) , numel( joint(j_count).second ) ] ) - 1
                
                if joint(j_count).first(1) == 0 || joint(j_count).first(n_mesh+1) == 0 % the joint number where the new frame is connected to
                    joint(j_count).Q(n_mesh).abs = joint(j_count).Q(n_mesh).loc ;
                    joint(j_count).TQ(n_mesh).abs = joint(j_count).TQ(n_mesh).loc ;
                else
                    if isempty( body(joint(j_count).first(1)).rom )
                        Q = body(joint(j_count).first(1)).Q(joint(j_count).first(n_mesh+1)).abs ;
                        TQ = body(joint(j_count).first(1)).TQ(joint(j_count).first(n_mesh+1)).abs ;
                    else
                        Q = body(joint(j_count).first(1)).Q(1).abs ;
                        TQ = body(joint(j_count).first(1)).TQ(1).abs ;
                        Q = subs( Q , s , joint(j_count).first(2) ) ;
                        TQ = subs( TQ , s , joint(j_count).first(2) ) ;
                    end
                    joint(j_count).Q(n_mesh).abs = Q_mult( Q , joint(j_count).Q(n_mesh).loc ) ;
                    joint(j_count).TQ(n_mesh).abs = TQ_mult( TQ , joint(j_count).TQ(n_mesh).loc ) ;
                end
                joint(j_count).r(n_mesh,:) = joint(j_count).TQ(n_mesh).abs(2:4,2).';
                
                if joint(j_count).second(1) == 0 || joint(j_count).second(n_mesh+1) == 0  % the joint number where the new frame is connected to the second body
                    joint(j_count).Q2nd(n_mesh).abs = joint(j_count).Q2nd(n_mesh).loc ;
                    joint(j_count).TQ2nd(n_mesh).abs = joint(j_count).TQ2nd(n_mesh).loc ;
                else
                    if isempty( body(joint(j_count).second(1)).rom )
                        Q = body(joint(j_count).second(1)).Q(joint(j_count).second(n_mesh+1)).abs ;
                        TQ = body(joint(j_count).second(1)).TQ(joint(j_count).second(n_mesh+1)).abs ;
                    else
                        Q = body(joint(j_count).second(1)).Q(1).abs ;
                        TQ = body(joint(j_count).second(1)).TQ(1).abs ;
                        Q = subs( Q , s , joint(j_count).second(2) ) ;
                        TQ = subs( TQ , s , joint(j_count).second(2) ) ;
                    end
                    joint(j_count).Q2nd(n_mesh).abs = Q_mult( Q , joint(j_count).Q2nd(n_mesh).loc ) ;
                    joint(j_count).TQ2nd(n_mesh).abs = TQ_mult( TQ , joint(j_count).TQ2nd(n_mesh).loc ) ;
                end
                

                % spring/damper/input:
                
                n_sd = n_sd + 1 ;
                r_ks = [ r_ks ; joint(j_count).TQ(n_mesh).abs(2:4,2).' , joint(j_count).TQ2nd(n_mesh).abs(2:4,2).' ] ; % each body joint and tip
                r_sd = joint(j_count).TQ2nd(n_mesh).abs(2:4,2) - joint(j_count).TQ(n_mesh).abs(2:4,2) ; % TQ2nd - TQ: order should match direction of q0, otherwise does not matter
                                                                                                        % if q0 = 0 -> any order results in two actions: f2nd(r2nd-r) & f(r-r2nd)
                % dr_sd = jacobian( r_sd , qf ) * uf.' ;

                if numel( joint(j_count).spring.coeff(n_mesh,:) ) == 1 % simple spring     
                    
                    l_sd0 = joint(j_count).spring.init(n_mesh,1) ;
                    if isnan( joint(j_count).spring.init(n_mesh,1) ) % init. l based on q0 and compression ratio
                        r_sd0 = subs( r_sd , q , q0 ).' ; % 1x3
                        l_sd0_q0 = sqrt( r_sd0 * r_sd0.' ) ; % based on int. config.
                        l_sd0 = sym( l_sd0 ) ;
                        l_sd0 = l_sd0_q0 ;
                    end
                    l_sd0 = joint(j_count).spring.compr(n_mesh,1) * l_sd0 ;
                    
                    sprdmp(n_sd).Tt = jacobian( r_sd , q ).' ; % virtual displacement
                    sprdmp(n_sd).kx = ... % all spring/damper force virtual work
                        ( - joint(j_count).spring.coeff(n_mesh,1) * ...
                        r_sd * ( 1 - l_sd0 / sqrt( r_sd.' * r_sd ) ) ) ; % instantanious spring force vector
                    sprdmp(n_sd).dl = sqrt( r_sd.' * r_sd ) - l_sd0 ; % spring delta-l
                    sprdmp(n_sd).vd = ... % viscous damping force virtual work
                        - joint(j_count).damp.visc(n_mesh) ...
                        * diag( abs( jacobian( r_sd , q ) * u.' ).^( joint(j_count).damp.pow(n_mesh,1) - 1 ) ) ...
                        * jacobian( r_sd , q ) * u.' ; % instantanious viscous force matrix
                    sprdmp(n_sd).in = ... % input force virtual work
                        joint(j_count).input(n_mesh) ; % instantanious input value
                    sprdmp(n_sd).k_mat = joint(j_count).spring.coeff(n_mesh,1) * ... % for modal analysis if k is linear w.r.t. states
                        jacobian( r_sd , q ) ;
                    sprdmp(n_sd).vd_mat = ... % viscous damping force virtual work
                        - joint(j_count).damp.visc(n_mesh) ...
                        * diag( abs( jacobian( r_sd , q ) * u.' ).^( joint(j_count).damp.pow(n_mesh,1) - 1 ) ) ...
                        * jacobian( r_sd , q ) ; % instantanious viscous force matrix
                    
                else % 6 elements for beam trans. & rot.
                                                               
                    r_sd0 = subs( r_sd , q , q0 ).' ; % 1x3
                    l_sd0_q0 = sqrt( r_sd0 * r_sd0.' ) ; % based on int. config.
                    temp = Q_rot( Q_conj( joint(j_count).TQ(n_mesh).abs(:,1) ) , [ 0 ; r_sd0.' ] ) ; % r_{loc} = Q^{-1} * r_{abs} * Q
                    r_sd_r = Q_rot( Q_conj( joint(j_count).TQ(n_mesh).abs(:,1) ) , [ 0 ; r_sd ] ) ; % r_{loc} = Q^{-1} * r_{abs} * Q
                    if ~isempty( joint(j_count).xaxis )
                        r_sd0_r = temp(2:4,1).' ; % 1x3 in local frame
                        yaxis =  cross( r_sd0_r , joint(j_count).xaxis(n_mesh,:) ) ; % 1x3 beam frame axis w.r.t. local frame
                        xaxis = cross( yaxis , r_sd0_r ) ;
                        r_sd_rb = [ xaxis/sqrt( xaxis * xaxis.' ) ;
                                    yaxis/sqrt( yaxis * yaxis.' ) ;
                                    r_sd0_r/l_sd0_q0 ].' * r_sd_r(2:4,1) ; % 3x1 transformed to beam frame
                    else
                        r_sd_rb = r_sd_r(2:4,1) ; % 3x1 already in beam frame
                    end
            		Q_sd = 2 * Q_mult( Q_conj( joint(j_count).TQ(n_mesh).abs(:,1) ) , joint(j_count).TQ2nd(n_mesh).abs(:,1) - joint(j_count).TQ(n_mesh).abs(:,1) ) ;
                    rQ_sd = [ r_sd_rb ; Q_sd(2:4,1) ] ; % 6 trans. & rot. spring/dampers
                    
                    rQ_sd0 = joint(j_count).spring.init(n_mesh,1:6) ;
                    for i_s = 1 : numel( rQ_sd0 )
                        if isnan( rQ_sd0(i_s) )
                            rQ_sd0 = sym( rQ_sd0 ) ;
                            if i_s == 3 % init. l based on q0 and compression ratio
                                rQ_sd0(i_s) = l_sd0_q0 ;
                            else
                                rQ_sd0(i_s) = subs( rQ_sd(i_s) , q , q0 ) ;
                            end
                        end
                    end
                    rQ_sd0 = rQ_sd0 * diag( joint(j_count).spring.compr(n_mesh,:) ) ;
                    
                    sprdmp(n_sd).Tt = jacobian( rQ_sd , q ).' ; % virtual displacement
                    sprdmp(n_sd).kx = ... % all spring/damper force virtual work
                        ( - diag( joint(j_count).spring.coeff(n_mesh,:) ) * ...
                        ( rQ_sd - rQ_sd0.' ) ) ; % instantanious spring force vector
                    sprdmp(n_sd).dl = sqrt( r_sd.' * r_sd ) - rQ_sd0(3) ; % spring delta-l
                    sprdmp(n_sd).vd = ... % viscous damping force virtual work
                        - diag( joint(j_count).damp.visc(n_mesh,:) ) ...
                        * diag( abs( jacobian( rQ_sd , q ) * u.' ).^( joint(j_count).damp.pow(n_mesh,1) - 1 ) ) ...
                        * jacobian( rQ_sd , q ) * u.' ; % instantanious viscous force matrix
                    sprdmp(n_sd).in = ... % input force virtual work
                        joint(j_count).input(n_mesh,:).' ; % instantanious input value
                    sprdmp(n_sd).k_mat = diag( joint(j_count).spring.coeff(n_mesh,:) ) * ... % for modal analysis if k is linear w.r.t. states
                        jacobian( rQ_sd , q ) ;
                    sprdmp(n_sd).vd_mat = ... % viscous damping force virtual work
                        - diag( joint(j_count).damp.visc(n_mesh,:) ) ...
                        * diag( abs( jacobian( rQ_sd , q ) * u.' ).^( joint(j_count).damp.pow(n_mesh,1) - 1 ) ) ...
                        * jacobian( rQ_sd , q ) ; % instantanious viscous force matrix
                    
                end
                    
                rom.sprdmp = [ rom.sprdmp 0 ] ;
                switch joint(j_count).dir(n_mesh)
                    case 1 % compression-only elements, e.g. soft contact
                        sprdmp(n_sd).dir = ( sign( sprdmp(n_sd).dl ) + 1 ) / 2 ;
                    case 0 % both dir.ss, e.g. regular spring/damper
                        sprdmp(n_sd).dir = 1 ;
                    case -1 % tension-only elements, e.g. wire
                        sprdmp(n_sd).dir = ( - sign( sprdmp(n_sd).dl ) + 1 ) / 2 ;
                end
                
                if ismember( par.derive_collect , [ 3 4 ] ) % for all spring/dampers
                    w_k = w_k + sprdmp(n_sd).dir * sprdmp(n_sd).Tt * sprdmp(n_sd).kx ;
                    w_vd = w_vd + sprdmp(n_sd).dir * sprdmp(n_sd).Tt * sprdmp(n_sd).vd ;
                    w_in = w_in + sprdmp(n_sd).dir * sprdmp(n_sd).Tt * sprdmp(n_sd).in ;
                    w_sdi = w_sdi + sprdmp(n_sd).dir * sprdmp(n_sd).Tt * ( ...
                        sprdmp(n_sd).kx + sprdmp(n_sd).vd + sprdmp(n_sd).in ) ; % all spring/damper/input force virtual work
                    w_k_mat = w_k_mat + sprdmp(n_sd).Tt * sprdmp(n_sd).k_mat ;
                    w_vd_mat = w_vd_mat + sprdmp(n_sd).Tt * sprdmp(n_sd).vd_mat ;
                end
                

                % constraints
				if ~isempty( joint(j_count).fixed )
					for i_c = 1 : numel( joint(j_count).fixed(n_mesh,:) )
						if joint(j_count).fixed(n_mesh,i_c)

						    n_cn = n_cn + 1 ;
						    % lambdaf = [ lambdaf, lambda_sym(n_cn) ] ;
						    lambda = [ lambda, sym( [ 'lambda' num2str( i_c ) ] ) ] ;
						    dlambda = [ dlambda, sym( [ 'dlambda' num2str( i_c ) ] ) ] ;
                            assume( lambda , 'real' ) ;
                            assume( dlambda , 'real' ) ;
						    
						    % translational constraint only for now
						    rcn(n_cn,:) = r_ks(end,4:6) - r_ks(end,1:3) ;
						    cnst(n_cn).T = sprdmp(n_sd).Tt(:,i_c).' ; % use T.' in dynamics EOM and T in algebraic part
						    vcn = cnst(n_cn).T * u.' ;
						    cnst(n_cn).D = jacobian( vcn , q ) ;
						    cnst(n_cn).in = joint(j_count).control(n_mesh,i_c) ;
						    
						    if ismember( par.derive_collect , [ 3 4 ] ) % for all constraints
						        Tcn = [ Tcn ; cnst(n_cn).T ] ;
						        Dcn = [ Dcn ; cnst(n_cn).D ] ;
						        Ccn = [ Ccn ; cnst(n_cn).in ] ;
						    end

						end		                
		            end
				end
                
            end
            
        end
        
        if joint(j_count).second(1) == b_count && ~isempty( joint(j_count).rom ) % if the joint is reduced order model
            j_count
            
            for n_mesh = 1 : max( [ numel( joint(j_count).first ) , numel( joint(j_count).second ) ] ) - 1
                
                n_sd = n_sd + 1 ;
                r_sd = joint(j_count).TQ(n_mesh).loc(:,2) ;
                dr_sd = diff( r_sd , s ) ;
                dQ_sd = diff( joint(j_count).TQ(n_mesh).loc(:,1) , s ) ;
                uQ_sd = 2 * Q_mult( Q_conj( joint(j_count).TQ(n_mesh).loc(:,1) ) , dQ_sd ) ;
                vr_sd = Q_rot( Q_conj( joint(j_count).TQ(n_mesh).loc(:,1) ) , dr_sd ) - [ 0 ; 0 ; 0 ; 1 ] ;
                rQ_sd = [ vr_sd(2:4,1) ; uQ_sd(2:4,1) ] ; % [ v u ]: 6 trans. & rot. spring/dampers 
                rQj_sd = [ vr_sd(2:4,1) ; uQ_sd(2:4,1)/1 ] ; % [ rho_,s Q_,s ]            
                rQ_sd0 = joint(j_count).spring.init(n_mesh,1:6) * diag( joint(j_count).spring.compr(n_mesh,1:6) ) ;
                    
                rom.sprdmp = [ rom.sprdmp joint(j_count).second(2) ] ;
                sprdmp(n_sd).Tt = jacobian( rQj_sd , q ).' ; % virtual displacement
                sprdmp(n_sd).kx = ... % all spring/damper force virtual work
                    ( - diag( joint(j_count).spring.coeff(n_mesh,:) ) * ...
                    ( rQ_sd - rQ_sd0.' ) ) ; % instantanious spring force vector
                sprdmp(n_sd).dl = dr_sd(2:4).' ; % spring delta-l
                sprdmp(n_sd).vd = ... % viscous damping force virtual work
                    - diag( joint(j_count).damp.visc(n_mesh,:) ) ...
                    * diag( abs( jacobian( rQ_sd , q ) * u.' ).^( joint(j_count).damp.pow(n_mesh,1) - 1 ) ) ...
                    * jacobian( rQ_sd , q ) * u.' ; % instantanious viscous force matrix
                sprdmp(n_sd).in = ... % input force virtual work
                    joint(j_count).input(n_mesh,:).' ; % instantanious input value
                sprdmp(n_sd).k_mat = diag( joint(j_count).spring.coeff(n_mesh,:) ) * ... % for modal analysis if k is linear w.r.t. states
                    jacobian( rQj_sd , q ) ;
                sprdmp(n_sd).vd_mat = ... % viscous damping force virtual work
                    - diag( joint(j_count).damp.visc(n_mesh,:) ) ...
                    * diag( abs( jacobian( rQ_sd , q ) * u.' ).^( joint(j_count).damp.pow(n_mesh,1) - 1 ) ) ...
                    * jacobian( rQ_sd , q ) ; % instantanious viscous force matrix
                
                switch joint(j_count).dir(n_mesh)
                    case 1 % compression-only elements, e.g. soft contact
                        sprdmp(n_sd).dir = ( sign( sprdmp(n_sd).dl ) + 1 ) / 2 ;
                    case 0 % both dir.ss, e.g. regular spring/damper
                        sprdmp(n_sd).dir = 1 ;
                    case -1 % tension-only elements, e.g. wire
                        sprdmp(n_sd).dir = ( - sign( sprdmp(n_sd).dl ) + 1 ) / 2 ;
                end
                
                if ismember( par.derive_collect , [ 3 4 ] ) % for all spring/dampers
                    w_k = w_k + sprdmp(n_sd).dir * sprdmp(n_sd).Tt * sprdmp(n_sd).kx ;
                    w_vd = w_vd + sprdmp(n_sd).dir * sprdmp(n_sd).Tt * sprdmp(n_sd).vd ;
                    w_in = w_in + sprdmp(n_sd).dir * sprdmp(n_sd).Tt * sprdmp(n_sd).in ;
                    w_sdi = w_sdi + sprdmp(n_sd).dir * sprdmp(n_sd).Tt * ( ...
                        sprdmp(n_sd).kx + sprdmp(n_sd).vd + sprdmp(n_sd).in ) ; % all spring/damper/input force virtual work
                    w_k_mat = w_k_mat + sprdmp(n_sd).Tt * sprdmp(n_sd).k_mat ;
                    w_vd_mat = w_vd_mat + sprdmp(n_sd).Tt * sprdmp(n_sd).vd_mat ;
                end
                
            end
            
        end
        
    end

end
nlambda = numel( lambda ) ;
    

% handle external forces
% linear force for now
Ttef = sym( [] ) ;
ftau_ef = sym( [] ) ;
for i_exload = 1 : n_ex
    i_exload
    
    for n_mesh = 1 : numel( exload(i_exload).exbody ) - 1
        
        exload(i_exload).Q(n_mesh).loc = sym( [ 1 0 0 0 ].' );
        exload(i_exload).TQ(n_mesh).loc = sym( [ 1 0 0 0 ; 0 0 0 0 ].' );
        
        [ ~ , nj_tr ] = size( exload(i_exload).tr ) ; % number of transforamtions in a joint
        for i3 = 1 : nj_tr
            [ Q_temo , TQ_temo ] = TQ_mat( [ exload(i_exload).tr(i3).trans , exload(i_exload).tr(i3).rot ] , [ q s ] , 0 );
            exload(i_exload).Q(n_mesh).loc = Q_mult( exload(i_exload).Q(n_mesh).loc , Q_temo ) ;
            exload(i_exload).TQ(n_mesh).loc = TQ_mult( exload(i_exload).TQ(n_mesh).loc , TQ_temo ) ;
        end
        
        if isempty( body(exload(i_exload).exbody(1)).rom )
            Q = body(exload(i_exload).exbody(1)).Q(exload(i_exload).exbody(n_mesh+1)).abs ;
            TQ = body(exload(i_exload).exbody(1)).TQ(exload(i_exload).exbody(n_mesh+1)).abs ;
        else
            Q = body(exload(i_exload).exbody(1)).Q(1).abs ;
            TQ = body(exload(i_exload).exbody(1)).TQ(1).abs ;
            Q = subs( Q , s , exload(i_exload).exbody(2) ) ;
            TQ = subs( TQ , s , exload(i_exload).exbody(2) ) ;
        end
        exload(i_exload).Q(n_mesh).abs = Q_mult( Q , exload(i_exload).Q(n_mesh).loc ) ;
        exload(i_exload).TQ(n_mesh).abs = TQ_mult( TQ , exload(i_exload).TQ(n_mesh).loc ) ;
        
		% both load and action vector should be in same frame
        ref(i_exload,:) = exload(i_exload).TQ(n_mesh).abs(2:4,2).';
        r_ex = exload(i_exload).TQ(n_mesh).abs(2:4,2) ; % exerting point vector in ref. frame
        loads(i_exload).Tt(:,1:3) = jacobian( exload(i_exload).TQ(n_mesh).abs(2:4,2) , q ).' ; % in ref. frame
        temp = jacobian( exload(i_exload).Q(n_mesh).abs , q ) ;
        temp = 2 * Q_mult( Q_conj( exload(i_exload).Q(n_mesh).abs ) , temp ) ; % in exbody. frame: omega_abs = 2 * Q^{-1} * Q_{,t} 
        loads(i_exload).Tt(:,4:6) = temp(2:4,:).' ; % in exbody frame
        
		% transfer f to ref. frame and tau to exbody. frame
        % default: in ref. frame
        f_reff = [ 0 exload(i_exload).ftau(n_mesh,1:3) ].' ; % f in ref. frame
        tau_reff = [ 0 exload(i_exload).ftau(n_mesh,4:6) ].' ; % tau in ref. frame
        if exload(i_exload).refbody(1) ~= 0 % ftau in refbody frame
        	f_reff = Q_rot( body(exload(i_exload).refbody(1)).Q(exload(i_exload).refbody(n_mesh+1)).abs , f_reff ) ; % f in ref. frame
        	tau_reff = Q_rot( body(exload(i_exload).refbody(1)).Q(exload(i_exload).refbody(n_mesh+1)).abs , tau_reff ) ; % tau in ref. frame
        end
        tau_exbf = Q_rot( Q_conj( exload(i_exload).Q(n_mesh).abs ) , tau_reff ) ; % tau in exbody. frame
        loads(i_exload).ftau = [ f_reff(2:4,1) ; tau_exbf(2:4,1) ] ;
        
        if ismember( par.derive_collect , [ 3 4 ] )  % for all ex. forces
            Ttef = [ Ttef loads(i_exload).Tt ] ;
            ftau_ef = [ ftau_ef ; loads(i_exload).ftau ] ;
        end
        
    end
    
end

% k_mat for modal analysis:
k_mat = w_k_mat + fj_k_mat ; % total stiffnes matrix for modal analysis
vd_mat = w_vd_mat + fj_vd_mat ;


%% report:
save( 'code/derivations.mat' ) ; % save all

save_func( q , u , lambda , dlambda , s , par , ...
    mass , sprdmp , cnst , loads , ...
    nq , nlambda , q0 , n_m , n_sd , n_cn , n_ex , ...
    M , T , fj_k , fj_vd , fj_in , fj_sdi , fj_k_mat , fj_vd_mat , ...
    fgv , Dd , ref , rcn , Ttef , ftau_ef , Tcn , Dcn , r_jtips , w_sdi , ...
    w_k , w_vd , w_k_mat , w_vd_mat , w_in , r_ks , k_mat , vd_mat , rom ) ;



%% Complementary Functions:
function [ Q , TQ ] = TQ_mat( r , qs , isq )
global unit_quat
% Q = [ q0 r1 r2 r3 ] ; % quaternion format
% Q1 & Q2 are cloumn vectors

switch numel( r )                
        
    case 5 % single rotations: Euler angles
        i = double( r(4) );
        x = r(5);
        
        switch i
            case 1
                Q = [ cos( x / 2 ) sin( x / 2 )*[ 1 0 0 ] ].';
            case 2
                Q = [ cos( x / 2 ) sin( x / 2 )*[ 0 1 0 ] ].';
            case 3
                Q = [ cos( x / 2 ) sin( x / 2 )*[ 0 0 1 ] ].';
            otherwise
                Q = [ 1 0 0 0 ].';
        end
        
    case 6 % variable curvature with piecewise constant strain assumption in each elements
        Q = [ 1 r(4:6)/2 ].';
        
    case 7 % 4-element euler angle rot. vector
        Q = [ cos( r(4) / 2 ) sin( r(4) / 2 )*r(5:7)/sqrt( r(5:7) * r(5:7).' ) ].' ;
        if isq == 1 % quat. rot.s contains states
			if r(4) == 0 % unit quaternion
		        Q = [ sqrt( 1 - r(5:7) * r(5:7).' ) r(5:7) ].' ; % avoid singularity
		        % Q = [ 0 r(5:7)/sqrt( r(5:7) * r(5:7).' ) ].' ; % no imaginary part but singular
			else
				unit_quat = 0 ; % there is non-unit quaternion in the code
		        Q = r(4:7).' ; % avoid singularity
            end
        end
end

TQ = sym ( [ Q , [ 0 r(1:3) ].' ] ); % 4x4: Each QR contains a translation and then a rotation
Q = sym( Q ) ;
TQ = sym( TQ ) ;


function Qo = Q_mult( Q1 , Q2 )
% Q = [ q0 r1 r2 r3 ] ; % quaternion format
% Q1 & Q2 are cloumn vectors
Qo = [ Q1(1,1) -Q1(2,1) -Q1(3,1) -Q1(4,1) ;
       Q1(2,1)  Q1(1,1) -Q1(4,1)  Q1(3,1) ;
       Q1(3,1)  Q1(4,1)  Q1(1,1) -Q1(2,1) ;
       Q1(4,1) -Q1(3,1)  Q1(2,1)  Q1(1,1) ] * Q2 ;


function r_rot = Q_rot( Q , rQ )
% rQ = [ 0 r ].' ;
r_rot = Q_mult( Q_mult( Q , rQ ) , Q_conj( Q ) ) ; % 4x1 vector


function TQo = TQ_mult( TQ1 , TQ2 )
TQo = [ Q_mult( TQ1(:,1) , TQ2(:,1) ) , ...
        TQ1(:,2)+Q_rot( TQ1(:,1) , TQ2(:,2) ) ] ;
   
function Qo = Q_conj( Q )
global unit_quat
Qo = [ Q(1,1) ; -Q(2:4,1) ] ;
if ~unit_quat
	Qo = Qo / sqrt( Q.' * Q ) ;
end



