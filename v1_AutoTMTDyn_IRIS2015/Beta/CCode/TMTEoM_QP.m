%% TMT EOM Derivator:
% (with constant curvature continuum modules (CCCM))
% Here half of each module mass is assumed to be at each of the two module ends.
% ===========================================
% [ M , T , Dd , fg , fj , rj , rc , vc , wc , ref , rcn ,  Tef , Tcn , Dcn , dwC , dwG , qf , uf , pf ] = ...
%    TMTEoM_C ( lc , m , I , j , jkd , g , quatSlct , mtdSlct );
%
% ===========================================
% Author:
%   S.M.Hadi Sadati
%   PhD student - King's College London
%   2014
%
% ===========================================
% Help:
%
% Inputs:
% ( n ) Number of links (every thing that has mass and/or rotational inertia
% ( nq ) Number of generalized coordinates
% lc : nx5
%     first 3 elements are vector of link COM (4th: 0) / external force (4th: 1) / constraint (4th: 2) positions in link frame (1x3),
%     	4th element is indicator for types
%     	and 5th element is the number of previous joint ( 0 for serial mechanism ).
% 	  Deal with links first, then forces and then constraints.
%     Joint (link) frame origin attached to joint
% m : nx1 vector of link masses
% I : 3x3xn cube of link inertia matrices w.r.t. link frame
% j : rx5xn cube of each joint (translation and rotation leading to each joint)
%     translation from previous joint position:
%       ( r , 3:5 , n ) = linear transformation value along previous link frame x-y-z axes 
%     and rotation of new link frame w.r.t. previous link frame
%       ( r , 1 , n ) = 1 : 3 axis indicator number for Euler post-multiplication rotations about sequencive temporary frames' x-y-z axes ),
%		can be "inf" for a constant curvature continuum module
%     and the rotation values:
%       ( r , 2 , n ) = value.
%     PLACE "inf" FOR "VALUE" IF IT IS ONE OF THE GENERALIZED COORDINATES!!!
%	  "inf" should not be used if the transformation is for a constraint or an external force point.
% jkd : 4x2xnq cube generalized coordinates 3 pair of 
%     [ spring coeff.s ; viscous damping coeff.s ; external input ; symmetric constraint ]
%     and their initial pos.s ( Only spring coeff. needs it! )
%     symmetric constraint: number of the joint where this one is equal to
% g : 1x3 gravity acceleration vector
% config = [ quatSlct % Select quaternion (1) or matrix transformation (2)
%            mtdSlct ] ; % Select TMT method (1) or Lagrange Method (2)
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
%
% syms lc1 lc2 lc3 m1 m2 m3 I1 I2 I3 l1 l2 k1 k2 k3 gx gy gz
% lc = [ lc1 0 0 0 0 ; lc2 0 0 0 0 ; lc3 0 0 0 0 ];
% m = [ m1 , m2 , m3 ];
% I = sym ( zeros ( 3 , 3 , 3 ) );
% I(:,:,1) = I1 * eye ( 3 ); I(:,:,2) = I2 * eye ( 3 ); I(:,:,3) = I3 * eye ( 3 );
% j = sym ( zeros ( 1 , 5 , 3 ) );
% j(:,:,1) = [ 2 inf 0 0 0 ]; j(:,:,2) = [ 2 inf l1 0 0 ]; j(:,:,3) = [ 2 inf l2 0 0 ];
% jkd = sym (zeros ( 3 , 2 , 3 ) );
% jkd(1,:,1) = [ k1 0 ]; jkd(1,:,2) = [ k2 0 ]; jkd(1,:,3) = [ k3 0 ];
% g = [ gx , gy , gz ];
%
% ============================================


%% Main:
function [ qf , uf , lambdaf , qf0 , par ] = ...
    TMTEoM_QP ( world , body , joint , exload  , par ) % discrete implementation


% >> Initialization:

[ ~ , n_b ] = size( body ) ; % number of bodies
[ ~ , n_ex ] = size( exload ) ; % number of ext. forces/torques
[ ~ , n_j ] = size( joint ) ; % number of joints

[ q , u , lambda , ~ , ~ ] = variables( par.derive ) ; % symbolic variables

M = sym( [] ) ; fgv = M ; T = M ; Dd = M ;
qf = sym( [] ) ; uf = qf ; qf0 = qf ; % all dofs
lambdaf = qf ;
r_j = sym( [] ) ; r_c = r_j ; ref = r_j ; rcn = r_j ; r_jtip = r_j ; r_ks = r_j ;
mass = [] ; sprdmp = mass ; cnst = mass ; load = mass ;


% >> Derivation:

n_sd = 0 ; % spring/damper counter
nq = 0; nq_mat = [ 0 0 0 ] ; % total dof counter
n_cn = 0; % constraint position counter
fj_k = sym( 0 ) ; % for joint spring
fj_vd = sym( 0 ) ; % for joint viscous damping
fj_cd = sym( 0 ) ; %for joint Coulomb damping
fj_k_mat = sym( 0 ) ;


% all joints
dof_m = [] ; % 3x3 cube
for j_count = 1 : n_j % look into all joints
    nj_dof = 0 ; % dof counter in each joint
    joint(j_count).Q.loc = sym( [ 1 0 0 0 ].' );
    joint(j_count).TQ.loc = sym( [ 1 0 0 0 ; 0 0 0 0 ].' );
    
    [ ~ , nj_tr ] = size( joint(j_count).tr ) ; % number of transforamtions in a joint
    for i3 = 1 : nj_tr        
        rotrans = [ joint(j_count).tr(i3).trans joint(j_count).tr(i3).rot ] ;
        
        for i2 = 1 : numel( rotrans )
            if rotrans(i2) == inf
                nj_dof = nj_dof + 1;
                
                if isempty( joint(j_count).dof(nj_dof).equal2 )
                    n_sd = n_sd + 1 ;
                    nq = nq + 1;
                    nq_mat = [ j_count nj_dof nq n_sd ] ;
                    dof_m(:,:,nj_dof,1,j_count) = [ nq n_sd ] ; % dof number
                    qf = [ qf , q(nq) ];
                    qf0 = [ qf0 joint(j_count).dof(nj_dof).init ] ;
                    uf = [ uf , u(nq) ];
                    fj_k(nq,1) = 0 ;
                    fj_vd(nq,nq) = 0 ;
                    fj_cd(nq,1) = 0 ;
                    fj_k_mat(nq,nq) = 0 ;
                else % geometrical constraint between dof.s, for rigid body dof.s only
                    nq_mat(1:2) = joint(j_count).dof(nj_dof).equal2 ;
                    nq_mat(3:4) = dof_m( 1 , : , nq_mat(2) , 1 , nq_mat(1) ) ;
                end
                
                % replace inf with q(iqc(3))
                joint(j_count).tr(i3).rot = sym( joint(j_count).tr(i3).rot ) ; % change double to sym
                joint(j_count).tr(i3).trans = sym( joint(j_count).tr(i3).trans ) ;
                if i2 < 4
                    joint(j_count).tr(i3).trans(i2) = q(nq_mat(3));
                else
                    joint(j_count).tr(i3).rot(i2-3) = q(nq_mat(3));
                end
                
                % for each spring
                sprdmp(nq_mat(4)).Tt(nq_mat(3),1) = 1 ;
                sprdmp(nq_mat(4)).kx = - joint(nq_mat(1)).dof(nq_mat(2)).spring.coeff * ( q(nq_mat(3)) - joint(nq_mat(1)).dof(nq_mat(2)).spring.init ) ; % spring
                sprdmp(nq_mat(4)).dl = q(nq_mat(3)) - joint(nq_mat(1)).dof(nq_mat(2)).spring.init ; % spring delta-l
                sprdmp(nq_mat(4)).vd(1,nq_mat(3)) = - joint(nq_mat(1)).dof(nq_mat(2)).damp.visc ; % * u(iqc(3)) ; % viscous
                sprdmp(nq_mat(4)).in = joint(nq_mat(1)).dof(nq_mat(2)).input ; % external input
                sprdmp(nq_mat(4)).k_mat(1,nq_mat(3)) = joint(nq_mat(1)).dof(nq_mat(2)).spring.coeff ; % spring
                
                if joint(j_count).dof(nq_mat(2)).spring.comp == 0 % tension-only elements
                    sprdmp(nq_mat(4)).kx = ( sign( sprdmp(nq_mat(4)).dl ) + 1 ) / 2 * sprdmp(nq_mat(4)).kx ;
                    sprdmp(nq_mat(4)).vd = ( sign( sprdmp(nq_mat(4)).dl ) + 1 ) / 2 * sprdmp(nq_mat(4)).vd ;
                end
                    
                if par.derive_collect == 1 % for all joint spring/dampers
                    fj_k(nq_mat(3),1) = fj_k(nq_mat(3),1) ... % spring on DOFs
                        + sprdmp(nq_mat(4)).kx ;
                    fj_vd(nq_mat(3),nq_mat(3)) = fj_vd(nq_mat(3),nq_mat(3)) ... % damper on DOFs
                        + sprdmp(nq_mat(4)).vd(1,nq_mat(3)) ;
                    fj_cd(nq_mat(3),1) = fj_cd(nq_mat(3),1) ... % inputs on DOFs
                        + sprdmp(nq_mat(4)).in ;
                    fj_k_mat(nq_mat(3),nq_mat(3)) = fj_k_mat(nq_mat(3),nq_mat(3)) ... % spring on DOFs
                        + sprdmp(nq_mat(4)).k_mat(1,nq_mat(3)) ;
                end
                
                        
            end            
        end
        
        [ tmp1 , tmp2 , tmp3 ] = TQ_mat( [ joint(j_count).tr(i3).trans joint(j_count).tr(i3).rot ] , qf );
        joint(j_count).Q.loc = Q_mult( joint(j_count).Q.loc , tmp1 , tmp3 ) ;
        joint(j_count).TQ.loc = TQ_mult( joint(j_count).TQ.loc , tmp2 , tmp3 ) ;
        
    end
    
    % for spring/damper and constraints
    if ~isempty( joint(j_count).tr2nd )
        joint(j_count).Q2nd.loc = sym( [ 1 0 0 0 ].' );
        joint(j_count).TQ2nd.loc = sym( [ 1 0 0 0 ; 0 0 0 0 ].' );
        [ ~ , nj_tr ] = size( joint(j_count).tr2nd ) ; % number of transforamtions in a joint
        for i3 = 1 : nj_tr
            [ tmp1 , tmp2 , tmp3 ] = TQ_mat( [ joint(j_count).tr2nd(i3).trans joint(j_count).tr2nd(i3).rot ] , qf );
            joint(j_count).Q2nd.loc = Q_mult( joint(j_count).Q2nd.loc , tmp1 , tmp3 ) ;
            joint(j_count).TQ2nd.loc = TQ_mult( joint(j_count).TQ2nd.loc , tmp2 , tmp3 ) ;
        end
    end
    
end

% Adjustments
for i = 1 : numel( sprdmp )
    if numel( sprdmp(i).Tt ) ~= nq % fill all elements
        sprdmp(i).Tt(nq,1) = 0 ;
        sprdmp(i).vd(1,nq) = 0 ;
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
for ib = 1 : n_b % number of bodies
              
    for j_count = 1 : n_j % look into all joints
        
        if joint(j_count).second(1) == ib % if the joint connects this body to another one

            if joint(j_count).first(1) == 0 % the joint number where the new frame is connected to on the firstbody
                joint(j_count).Q.abs = joint(j_count).Q.loc ;
                joint(j_count).TQ.abs = joint(j_count).TQ.loc ;
            else
                joint(j_count).Q.abs = Q_mult( body(joint(j_count).first(1)).Q.abs , joint(j_count).Q.loc , 0 ) ;
                joint(j_count).TQ.abs = TQ_mult( body(joint(j_count).first(1)).TQ.abs , joint(j_count).TQ.loc , 0 ) ;
            end
            joint(j_count).r = joint(j_count).TQ.abs(2:4,2).';
                        
            body(ib).Q.loc = joint(j_count).Q.loc ;
            body(ib).TQ.loc = joint(j_count).TQ.loc ;
            body(ib).Q.abs = joint(j_count).Q.abs ;
            body(ib).TQ.abs = joint(j_count).TQ.abs ;
            body(ib).prebody = joint(j_count).first(1) ; % previous body in the main kinematic chain
            
            r_j = [ r_j ; joint(j_count).r , joint(j_count).first(1) ] ; % each body local frame origin (joint)
            tmp3 = TQ_mult( body(ib).TQ.abs , [ 1 0 0 0 ; 0 body(ib).tip ].' , 0 ) ;
            tmp4 = tmp3(2:4,2).' ;
            r_jtip = [ r_jtip ; joint(j_count).r , tmp4 ] ; % each body jint and tip
            joint(j_count).r_tip = tmp4 ;
            
            n_m = n_m + 1 ;
            im = 6 * n_m ; % 6 elements for mass and inertia matrix
            mass(n_m).M(1:3,1:3) = sym( body(ib).m * eye( 3 ) ) ;
            mass(n_m).M(4:6,4:6) = sym( body(ib).I ) ;
            
            tmp3 = jacobian( body(ib).Q.abs , qf ) ;
            tmp4 = 2 * Q_mult( Q_conj( body(ib).Q.abs ) , tmp3 , 0 ) ;
            body(ib).omega.loc = ( tmp4(2:4,:) * uf.' ).' ; % abs omega in local frame
            
            mass(n_m).T(4:6,:) = tmp4(2:4,:) ;
            mass(n_m).Dd(4:6,:) = jacobian( body(ib).omega.loc.' , qf );
                        
            tmp7 = TQ_mult( body(ib).TQ.abs , [ 1 0 0 0 ; 0 body(ib).l_com ].' , 0 ) ;
            body(ib).r_com = tmp7(2:4,2).';
            r_c = [ r_c ; body(ib).r_com ] ; % COM position for output
            tmp8 = jacobian ( tmp7(2:4,2) , qf );
            body(ib).v_com = ( tmp8 * uf.' ).';
            
            mass(n_m).T(1:3,:) = tmp8 ;
            mass(n_m).Dd(1:3,:) = jacobian ( body(ib).v_com.' , qf );
            
            % gravity generalized work
            mass(n_m).fg = [ world.g 0 0 0 ].' ;
            
            
            if par.derive_collect == 1 % for all masses
                M( im - 5 : im , im - 5 : im ) = mass(n_m).M ;
                T ( im - 5 : im , : ) = mass(n_m).T ;
                Dd ( im - 5 : im , 1 : nq ) = mass(n_m).Dd ;
                fgv = [ fgv , mass(n_m).fg.' ];
            end
        
            break ; % other joints are spring or dampers and should have .tr2nd
            
        end
        
    end
    
end


% spring/dampers/constraint
% look for the secondary joints that should be constraint or spring/dampers
w_sd = sym( 0 ) ; % total virt. work
w_k = sym( 0 ) ; % spring virt. work
w_vd = sym( 0 ) ; % viscous dampers virt. work
w_cd = sym( 0 ) ; % Coulomb dampers virt. work
w_k_mat = sym( 0 ) ; % spring stiffnes matrix for modal analysis
Dcn = sym( [] ) ; Tcn = Dcn ;
for ib = 0 : n_b % number of bodies

    for j_count = 1 : n_j % look into all joints, first one is the main kinematic path and rest are froce and spring and constraints

        %         [ ib ij joint(ij).second(1) isempty(joint(ij).tr2nd) ]
        if joint(j_count).second(1) == ib && ~isempty( joint(j_count).tr2nd ) % if the joint connects this body to another one

            if joint(j_count).first(1) == 0 % the joint number where the new frame is connected to
                joint(j_count).Q.abs = joint(j_count).Q.loc ;
                joint(j_count).TQ.abs = joint(j_count).TQ.loc ;
            else
                joint(j_count).Q.abs = Q_mult( body(joint(j_count).first(1)).Q.abs , joint(j_count).Q.loc , 0 ) ;
                joint(j_count).TQ.abs = TQ_mult( body(joint(j_count).first(1)).TQ.abs , joint(j_count).TQ.loc , 0 ) ;
            end
            joint(j_count).r = joint(j_count).TQ.abs(2:4,2).';

            if joint(j_count).second(1) == 0 % the joint number where the new frame is connected to on the second body
                joint(j_count).Q2nd.abs = joint(j_count).Q2nd.loc ;
                joint(j_count).TQ2nd.abs = joint(j_count).TQ2nd.loc ;
            else
                joint(j_count).Q2nd.abs = Q_mult( body(joint(j_count).second(1)).Q.abs , joint(j_count).Q2nd.loc , 0 ) ;
                joint(j_count).TQ2nd.abs = TQ_mult( body(joint(j_count).second(1)).TQ.abs , joint(j_count).TQ2nd.loc , 0 ) ;
            end

            if ~isempty( joint(j_count).spring ) || ~isempty( joint(j_count).damp ) % is spring/damper

                if joint(j_count).spring.coeff ~= 0 || joint(j_count).damp.visc ~= 0 || joint(j_count).input ~= 0 % if not zero (dummy spring/damper )
                    % translational spring only at the moment
                    r_ks = [ r_ks ; joint(j_count).TQ.abs(2:4,2).' , joint(j_count).TQ2nd.abs(2:4,2).' ] ; % each body joint and tip
                    r_sd = joint(j_count).TQ.abs(2:4,2) - joint(j_count).TQ2nd.abs(2:4,2) ;
                    dr_sd = jacobian( r_sd , qf ) * uf.' ;
                    
                    n_sd = n_sd + 1 ;
                    sprdmp(n_sd).Tt = jacobian( r_sd , qf ).' ; % virtual displacement
                    sprdmp(n_sd).kx = ... % all spring/damper force virtual work
                        ( - joint(j_count).spring.coeff * ...
                        r_sd * ( 1 - joint(j_count).spring.init / sqrt( r_sd.' * r_sd ) ) ) ; % instantanious spring force vector
                    sprdmp(n_sd).dl = sqrt( r_sd.' * r_sd ) - joint(j_count).spring.init ; % spring delta-l
                    sprdmp(n_sd).vd = ... % viscous damping force virtual work
                        - joint(j_count).damp.visc * jacobian( r_sd , qf ) ; % instantanious viscous force matrix
                    sprdmp(n_sd).in = ... % input force virtual work
                        joint(j_count).input ; % instantanious input value
                    sprdmp(n_sd).k_mat = joint(j_count).spring.coeff * ... % for modal analysis if k is linear w.r.t. states
                        jacobian( r_sd , qf ) ; 
                    
                    if joint(j_count).spring.comp == 0 % tension-only elements
                        sprdmp(n_sd).kx = ( sign( sprdmp(n_sd).dl ) + 1 ) / 2 * sprdmp(n_sd).kx ;
                        sprdmp(n_sd).vd = ( sign( sprdmp(n_sd).dl ) + 1 ) / 2 * sprdmp(n_sd).vd ;
                    end
                                    
                    if par.derive_collect == 1 % for all spring/dampers
                        w_k = w_k + sprdmp(n_sd).Tt * sprdmp(n_sd).kx ;
                        w_vd = w_vd + sprdmp(n_sd).Tt * sprdmp(n_sd).vd ;
                        w_cd = w_cd + sprdmp(n_sd).Tt * sprdmp(n_sd).in ;
                        w_sd = w_sd + sprdmp(n_sd).Tt * ( ...
                            sprdmp(n_sd).kx + sprdmp(n_sd).vd * uf.' + sprdmp(n_sd).in ) ; % all spring/damper/input force virtual work
                        w_k_mat = w_k_mat + sprdmp(n_sd).Tt * sprdmp(n_sd).k_mat ;
                    end
                end

            else % is constraint: only 
                n_cn = n_cn + 1 ;
                lambdaf = [ lambdaf, lambda(n_cn) ] ;

                % translational constraint only for now
                rcn(n_cn,:) = joint(j_count).TQ.abs(2:4,2).';
                ecn = joint(j_count).TQ.abs(2:4,2) - joint(j_count).TQ2nd.abs(2:4,2) ;
                tmp11 = jacobian ( ecn , qf );
                vcn = tmp11 * uf.' ;
                
                cnst(n_cn).T = tmp11 ; % use T.' in dynamics EOM and T in algebraic part
                cnst(n_cn).D = jacobian( vcn , qf ) ;

                if par.derive_collect == 1 % for all constraints
                    Tcn = [ Tcn ; cnst(n_cn).T ] ;
                    Dcn = [ Dcn ; cnst(n_cn).D ] ;
                end
                
            end

        end

    end

end
    

% handle external forces
% linear force for now
Ttef = sym( [] ) ;
for i_ex = 1 : n_ex
    
    exload(i_ex).Q.loc = sym( [ 1 0 0 0 ].' );
    exload(i_ex).TQ.loc = sym( [ 1 0 0 0 ; 0 0 0 0 ].' );
    
    [ ~ , nj_tr ] = size( exload(i_ex).tr ) ; % number of transforamtions in a joint
    for i3 = 1 : nj_tr
        [ tmp1 , tmp2 , tmp3 ] = TQ_mat( [ exload(i_ex).tr(i3).trans exload(i_ex).tr(i3).rot ] , qf );
        exload(i_ex).Q.loc = Q_mult( exload(i_ex).Q.loc , tmp1 , tmp3 ) ;
        exload(i_ex).TQ.loc = TQ_mult( exload(i_ex).TQ.loc , tmp2 , tmp3 ) ;
    end
    
    exload(i_ex).Q.abs = Q_mult( body(exload(i_ex).body(1)).Q.abs , exload(i_ex).Q.loc , 0 ) ;
    exload(i_ex).TQ.abs = TQ_mult( body(exload(i_ex).body(1)).TQ.abs , exload(i_ex).TQ.loc , 0 ) ;
    
    ref(i_ex,:) = exload(i_ex).TQ.abs(2:4,2).';
    
    load(i_ex).Tt = jacobian( exload(i_ex).TQ.abs(2:4,2) , qf ).' ;
    
    if par.derive_collect == 1 % for all ex. forces
        Ttef = [ Ttef load(i_ex).Tt ] ; % use T.' in dynamics EOM
    end
    
end

% k_mat for modal analysis:
k_mat = w_k_mat + fj_k_mat ; % total stiffnes matrix for modal analysis


% report:
% matlabpool('open', 4);
opv = par.opv ;
vars = par.sym ;


n_m
n_sd
n_cn
n_ex
[ ~ , nqf ] = size( qf ) ; % number of states
[ ~ , nuf ] = size( uf ) ;
[ ~ , nlambdaf ] = size( lambdaf ) ;
matlabFunction ( sym(nqf) , sym(nuf) , sym(nlambdaf) , sym(qf0) , sym(n_m) , sym(n_sd) , sym(n_cn) , sym(n_lambda) , sym(n_ex) , ...
      'file' , 'nqF.m' , 'vars' , { vars } , 'Optimize' , opv ); % save as matlab function

if par.derive_C == 0 % collect all
    if n_m ~= 0
        parfor i = 1 : n_m
            matlabFunction ( sym( mass(i).M ) , sym( mass(i).T ) , sym( mass(i).Dd ) , sym( mass(i).fg ) , ...
                'file' , sprintf('massF%i.m', i) , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
        end
    end
    if n_sd ~= 0
        for i = 1 : n_sd
            matlabFunction ( sym( sprdmp(i).Tt ) , sym( sprdmp(i).kx ) , sym( sprdmp(i).vd ) , sym( sprdmp(i).in ) , sym( sprdmp(i).k_mat ) , sym( sprdmp(i).dl ) , ...
                'file' , sprintf('sprdmpF%i.m', i) , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
        end
    end
    if n_cn ~= 0
        parfor i = 1 : n_cn
            matlabFunction ( sym( cnst(i).T ) , sym( cnst(i).D ) , ...
                'file' , sprintf('cnstF%i.m', i) , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
        end
    end
    if n_ex ~= 0
        parfor i = 1 : n_ex
            matlabFunction ( sym( load(i).Tt ) , ...
                'file' , sprintf('loadF%i.m', i) , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
        end
    end
    
else % C compatible
    if n_m ~= 0
        parfor i = 1 : n_m
            matlabFunction ( sym( mass(i).M ) , 'file' , sprintf('massM%i.m', i) , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
        end
        parfor i = 1 : n_m
            matlabFunction ( sym( mass(i).T ) , 'file' , sprintf('massT%i.m', i) , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
        end
        parfor i = 1 : n_m
            matlabFunction ( sym( mass(i).Dd ) , 'file' , sprintf('massDd%i.m', i) , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
        end
        parfor i = 1 : n_m
            matlabFunction ( sym( mass(i).fg ) , 'file' , sprintf('massFg%i.m', i) , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
        end
    end
    if n_sd ~= 0
        parfor i = 1 : n_sd
            matlabFunction ( sym( sprdmp(i).Tt ) , 'file' , sprintf('sprdmpTt%i.m', i) , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
        end
        parfor i = 1 : n_sd
            matlabFunction ( sym( sprdmp(i).kx ) , 'file' , sprintf('sprdmpKx%i.m', i) , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
        end
        parfor i = 1 : n_sd
            matlabFunction ( sym( sprdmp(i).vd ) , 'file' , sprintf('sprdmpVd%i.m', i) , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
        end
        parfor i = 1 : n_sd
            matlabFunction ( sym( sprdmp(i).in ) , 'file' , sprintf('sprdmpIn%i.m', i) , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
        end
        parfor i = 1 : n_sd
            matlabFunction ( sym( sprdmp(i).k_mat ) , 'file' , sprintf('sprdmpKmat%i.m', i) , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
        end
        parfor i = 1 : n_sd
            matlabFunction ( sym( sprdmp(i).dl ) , 'file' , sprintf('sprdmpDl%i.m', i) , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
        end
    end
    if n_cn ~= 0
        parfor i = 1 : n_cn
            matlabFunction ( sym( cnst(i).T ) ,'file' , sprintf('cnstT%i.m', i) , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
        end
        parfor i = 1 : n_cn
            matlabFunction ( sym( cnst(i).D ) , 'file' , sprintf('cnstD%i.m', i) , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
        end
    end
    if n_ex ~= 0
        parfor i = 1 : n_ex
            matlabFunction ( sym( load(i).Tt ) , 'file' , sprintf('loadTt%i.m', i) , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
        end
    end
    
end

if par.derive_collect == 1
%     save_select = 1 : 42 ; % all
    save_select = 1 : 21 ; % matlab func.s
    save( 'derivations_collect.mat' , 'M' , 'T' , 'fj_k' , 'fj_vd' , 'fj_cd' , 'fj_k_mat' , ...
        'fgv' , 'Dd' , 'ref' , 'rcn' , 'Ttef' , 'Tcn' , 'Dcn' , 'r_jtip' , 'w_sd' , ...
        'w_k' , 'w_vd' , 'w_cd' , 'r_ks' , 'k_mat' ) ; % save all
else
    save_select = [ 14 , 20 ] ; % Animation only
    save( 'derivations.mat' , 'mass' , 'sprdmp' , 'cnst' , 'load' , 'r_jtip' , 'r_ks' ) ; % save all
end
parfor i = 1 : numel( save_select )
    switch save_select(i)
        % matlab functions
        case 1
            matlabFunction ( M , 'file' , 'MF.m' , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
            
        case 2
            matlabFunction ( T , 'file' , 'TF.m' , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
            
        case 3
            matlabFunction ( fj_k , 'file' , 'fj_kF.m' , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
            
        case 4
            matlabFunction ( fj_vd , 'file' , 'fj_vdF.m' , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
            
        case 5
            matlabFunction ( fj_cd , 'file' , 'fj_cdF.m' , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
            
        case 6
            matlabFunction ( fj_k_mat, 'file' , 'fj_k_matF.m' , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
            
        case 7
            matlabFunction ( fgv , 'file' , 'fgvF.m' , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
            
        case 8
            matlabFunction ( Dd , 'file' , 'DdF.m' , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
              
        case 9
            matlabFunction ( ref , 'file' , 'refF.m' , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
            
        case 10
            matlabFunction ( rcn , 'file' , 'rcnF.m' , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
            
        case 11
            matlabFunction ( Ttef , 'file' , 'TtefF.m' , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
            
        case 12
            matlabFunction ( Tcn , 'file' , 'TcnF.m' , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
            
        case 13
            matlabFunction ( Dcn , 'file' , 'DcnF.m' , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
            
        case 14
            matlabFunction ( r_jtip , 'file' , 'rjtipF.m' , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
            
        case 16
            matlabFunction ( w_sd , 'file' , 'w_sdF.m' , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
            
        case 17
            matlabFunction ( w_k , 'file' , 'w_kF.m' , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
            
        case 18
            matlabFunction ( w_vd , 'file' , 'w_vdF.m' , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
            
        case 19
            matlabFunction ( w_cd , 'file' , 'w_cdF.m' , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
              
        case 20
            matlabFunction ( r_ks , 'file' , 'rksF.m' , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
               
        case 21
            matlabFunction ( k_mat , 'file' , 'k_matF.m' , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
        
        % C codes
        case 22
            if ~isempty( M )
                ccode ( M , 'file' , 'MF.cpp' );
            end
            
        case 23
            if ~isempty( T )
                ccode ( T , 'file' , 'TF.cpp' );
            end
            
        case 24
            if ~isempty( fj_k )
                ccode ( fj_k , 'file' , 'fj_kF.cpp' );
            end
            
        case 25
            if ~isempty( fj_vd )
                ccode ( fj_vd , 'file' , 'fj_vdF.cpp' );
            end
           
        case 26
            if ~isempty( fj_cd )
                ccode ( fj_cd , 'file' , 'fj_cdF.cpp' );
            end
            
        case 27
            if ~isempty( fj_k_mat )
                ccode ( fj_k_mat , 'file' , 'fj_k_matF.cpp' );
            end
            
        case 28
            if ~isempty( fgv )
                ccode ( fgv , 'file' , 'fgvF.cpp' );
            end
            
        case 29
            if ~isempty( Dd )
                ccode ( Dd , 'file' , 'DdF.cpp' );
            end
            
        case 30
            if ~isempty( ref )
                ccode ( ref , 'file' , 'refF.cpp' );
            end
            
        case 31
            if ~isempty( rcn )
                ccode ( rcn , 'file' , 'rcnF.cpp' );
            end
            
        case 32
            if ~isempty( Ttef )
                ccode ( Ttef , 'file' , 'TtefF.cpp' );
            end
            
        case 33
            if ~isempty( Tcn )
                ccode ( Tcn , 'file' , 'TcnF.cpp' );
            end
            
        case 34
            if ~isempty( Dcn )
                ccode ( Dcn , 'file' , 'DcnF.cpp' );
            end
            
        case 35
            if ~isempty( r_jtip )
                ccode ( r_jtip , 'file' , 'rjtipF.cpp' );
            end
            
        case 37
            if ~isempty( w_sd )
                ccode ( w_sd , 'file' , 'w_sdF.cpp' );
            end
            
        case 38
            if ~isempty( w_k )
                ccode ( w_k , 'file' , 'w_kF.cpp' );
            end
            
        case 39
            if ~isempty( w_vd )
                ccode ( w_vd , 'file' , 'w_vdF.cpp' );
            end
            
        case 40
            if ~isempty( w_cd )
                ccode ( w_cd , 'file' , 'w_cdF.cpp' );
            end
            
        case 41
            if ~isempty( r_ks )
                ccode ( r_ks , 'file' , 'rksF.cpp' );
            end

        case 42
            if ~isempty( k_mat )
                ccode ( k_mat , 'file' , 'k_matF.cpp' );
            end
            
    end    
end



%% Complementary Functions:

function [ R , TR ] = TR_mat( r , q ) % base rotation matices

i = r(4);
x = r(5);

if i == 1
    R = [ ...
        1       0        0 ;
        0  cos(x)  -sin(x);
        0  sin(x)   cos(x)];
    
else if i == 2
        R = [ ...
            cos(x)  0  sin(x);
            0  1       0;
            -sin(x)  0  cos(x)];
        
    else if i == 3
            R = [ ...
                cos(x)  -sin(x)  0;
                sin(x)   cos(x)  0;
                0        0  1];
        else
            R = sym ( eye ( 3 ) );
            
        end
    end
end

TR = sym ( [ [ R , r(1:3).' ] ; 0 0 0 1 ] ); % Each TR contains a translation and then a rotation


function [ R , TR ] = TRc_mat( r , q , type ) % for CC_EB, VC

if ~strcmp( type , 'rigid' )
    
    s = r(1); kappa = r(2); phi = r(3); theta = s * kappa ;
    
    % for CC
%     rho =  [ cos(phi)*(1-cos(theta))/kappa , sin(phi)*(1-cos(theta))/kappa , sin(theta)/kappa ] ; % CC
    rho =  [ cos(phi)*s*sin(theta/2) , sin(phi)*s*sin(theta/2) , s*cos(theta/2) ] ; % lim_{kappa \to 0}, hyperbolic
    [ ~ , TR1 ] = TR_mat( [ 0 0 0 3 phi ] ) ;
    [ ~ , TR2 ] = TR_mat( [ rho 2 theta ] ) ;
    [ ~ , TR3 ] = TR_mat( [ 0 0 0 3 -phi ] ) ;  

%     % for hyperbolic ( theta ~ 0 )
%     rho =  [ cos(phi)*s*theta , sin(phi)*s*theta , s ] ;
%     [ ~ , TR1 ] = TRm_lim( [ 0 0 0 3 phi ] ) ;
%     [ ~ , TR2 ] = TRm_lim( [ rho 2 theta ] ) ;
%     [ ~ , TR3 ] = TRm_lim( [ 0 0 0 3 -phi ] ) ;
    
    TR = TR1 * TR2 * TR3 ;
    R = TR(1:3,1:3) ;
    
end


function phi = atanF( y , x )
phi = atan( y / x ) ;
% phi = atan2( y , x ) ;


function [ Q , TQ , isdQ ] = TQ_mat( r , q )
% Q = [ q0 r1 r2 r3 ] ; % quaternion format
% Q1 & Q2 are cloumn vectors

switch numel( r )        
    case 6 % variable curvature with piecewise constant strain assumption in each elements
        Q = [ 0 r(4:6) ].';
        isdQ = 1 ; % is it dQ (path curvatures and torsion) or Q (rotation quaternions)?
        
    case 7 % 4-element euler angle rot. vector
        Q = [ cos( r(4) / 2 ) sin( r(4) / 2 )*r(5:7)/sqrt( r(5:7) * r(5:7).' ) ].' ;
        if ismember( r(5) , q ) || ismember( r(6) , q ) || ismember( r(7) , q )
            Q = [ sqrt( 1 - r(5:7) * r(5:7).' ) r(5:7) ].' ; % avoid singularity
%             Q = [ 0 r(5:7)/sqrt( r(5:7) * r(5:7).' ) ].' ; % no imaginary part issue but singular
        end
        isdQ = 0 ;
        
    case 5 % single rotations: Euler angles
        i = double( r(4) );
        x = r(5);
        isdQ = 0 ;
        
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
end

TQ = sym ( [ Q , [ 0 r(1:3) ].' ] ); % 4x4: Each QR contains a translation and then a rotation
Q = sym( Q ) ;
TQ = sym( TQ ) ;


function Qo = Q_mult( Q1 , Q2 , isdQ )
% Q = [ q0 r1 r2 r3 ] ; % quaternion format
% Q1 & Q2 are cloumn vectors
if isdQ == 0 % Q2 is rotation quaternions
    Qo = [ Q1(1,1) -Q1(2,1) -Q1(3,1) -Q1(4,1) ;
           Q1(2,1)  Q1(1,1) -Q1(4,1)  Q1(3,1) ;
           Q1(3,1)  Q1(4,1)  Q1(1,1) -Q1(2,1) ;
           Q1(4,1) -Q1(3,1)  Q1(2,1)  Q1(1,1) ] * Q2 ;
else % Q2 is path curvatures and torsion
    Qo = [ Q1(1,1) -Q1(2,1) -Q1(3,1) -Q1(4,1) ;
           Q1(2,1)  Q1(1,1) -Q1(4,1)  Q1(3,1) ;
           Q1(3,1)  Q1(4,1)  Q1(1,1) -Q1(2,1) ;
           Q1(4,1) -Q1(3,1)  Q1(2,1)  Q1(1,1) ] * Q2 / 2 + Q1 ; % trivedi's paper
end
   
function r_rot = Q_rot( Q , rQ )
% rQ = [ 0 r ].' ;
r_rot = Q_mult( Q_mult( Q , rQ , 0 ) , Q_conj( Q ) , 0 ) ; % 4x1 vector
   

function TQo = TQ_mult( TQ1 , TQ2 , isdQ )
TQo = [ Q_mult( TQ1(:,1) , TQ2(:,1) , isdQ ) , ...
        TQ1(:,2)+Q_rot( TQ1(:,1) , TQ2(:,2) ) ] ;
   
function Qo = Q_conj( Q )
Qo = [ Q(1,1) ; -Q(2:4,1) ] ;
    

