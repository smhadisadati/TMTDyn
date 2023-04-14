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
function [ qf , uf , lambdaf , sf , qf0 , par ] = ...
    TMTEoM_SC ( world , body , joint , exload  , par )


% >> Initialization:

[ ~ , nb ] = size( body ) ; % number of bodies
[ ~ , nef ] = size( exload ) ; % number of ext. forces/torques
[ ~ , nj ] = size( joint ) ; % number of joints

syms q1 q2 q3 q4 q5 q6 q7 q8 q9 q10 q11 q12 q13 q14 q15 q16 q17 q18 q19 q20 q21 q22 q23 q24 q25 q26 q27 q28 q29 q30 q31 q32 q33 q34 q35 q36 q37 q38 q39
syms u1 u2 u3 u4 u5 u6 u7 u8 u9 u10 u11 u12 u13 u14 u15 u16 u17 u18 u19 u20 u21 u22 u23 u24 u25 u26 u27 u28 u29 u30 u31 u32 u33 u34 u35 u36 u37 u38 u39
syms lambda1 lambda2 lambda3 lambda4 lambda5 lambda6 lambda7 lambda8 lambda9 lambda10 lambda11 lambda12 lambda13 lambda14 lambda15 lambda16 lambda17 lambda18 lambda19 lambda20 lambda21 lambda22 lambda23 lambda24 lambda25 lambda26 lambda27 lambda28 lambda29 lambda30 lambda31 lambda32 lambda33 lambda34 lambda35 lambda36 lambda37 lambda38 lambda39
syms s1 s2 s3 s4 s5 s6 s7 s8 s9 s10 s11 s12 s13 s14 s15 s16 s17 s18 s19 s20 s21 s22 s23 s24 s25 s26 s27 s28 s29 s30 s31 s32 s33 s34 s35 s36 s37 s38 s39
q = [ q1 q2 q3 q4 q5 q6 q7 q8 q9 q10 q11 q12 q13 q14 q15 q16 q17 q18 q19 q20 q21 q22 q23 q24 q25 q26 q27 q28 q29 q30 q31 q32 q33 q34 q35 q36 q37 q38 q39 ];
u = [ u1 u2 u3 u4 u5 u6 u7 u8 u9 u10 u11 u12 u13 u14 u15 u16 u17 u18 u19 u20 u21 u22 u23 u24 u25 u26 u27 u28 u29 u30 u31 u32 u33 u34 u35 u36 u37 u38 u39 ];
lambda = [ lambda1 lambda2 lambda3 lambda4 lambda5 lambda6 lambda7 lambda8 lambda9 lambda10 lambda11 lambda12 lambda13 lambda14 lambda15 lambda16 lambda17 lambda18 lambda19 lambda20 lambda21 lambda22 lambda23 lambda24 lambda25 lambda26 lambda27 lambda28 lambda29 lambda30 lambda31 lambda32 lambda33 lambda34 lambda35 lambda36 lambda37 lambda38 lambda39 ] ;
s = [ s1 s2 s3 s4 s5 s6 s7 s8 s9 s10 s11 s12 s13 s14 s15 s16 s17 s18 s19 s20 s21 s22 s23 s24 s25 s26 s27 s28 s29 s30 s31 s32 s33 s34 s35 s36 s37 s38 s39 ] ;

M = sym( [] ) ; fg = M ; MC = M ; fgC = M ;
T = M ; TC = M ; Dd = M ; DdC = M ; ED = M ;
qf = sym( [] ) ; uf = qf ; qf0 = qf ; lambdaf = qf ;
r_j = sym( [] ) ; r_c = sym( [] ) ; ref = r_c ; rcn = r_c ; r_jtip = r_c ;


% >> Derivation:

iq = 0; iqc = [ 0 0 0 ] ; % total dof counter
icn = 0; % constraint position counter
fj = sym( 0 ) ;


% states for CC_EB and VC bodies
% curvature states are befor the common joint states
dof_m = [] ; nC = 0 ; intlim = sym( [] ) ; sf = sym( [] ) ;
for ib = 1 : nb % number of bodies
    
    iqb = 0 ; % number of dof in body
    if ~strcmp( body(ib).type , 'rigid' )
        
        nC = nC + 1 ; % number of non-rigid elements
        sf = [ sf , s(nC) ];
        
        ib
        [ ~ , n_dofb ] = size( body(ib).CC_EB.par ) ; % number of dof expressing the body CC_EB
        for i2 = 1 : n_dofb
            
            if i2 == 1 % l par
                intlim = [ intlim body(ib).CC_EB.par(i2) ] ; % integration limit
            end
                    
            if body(ib).CC_EB.par(i2) == inf
                iqb = iqb + 1;
                
                if isempty( body(ib).CC_EB.dof(iqb).equal2 )
                    iq = iq + 1;
                    iqc = [ ib iqb iq ] ;
                    dof_m(ib,iqb) = iq ; % dof number
                    qf = [ qf , q(iq) ];
                    qf0 = [ qf0 body(ib).CC_EB.dof(iqb).init ] ;
                    uf = [ uf , u(iq) ];
                    fjC(iqc(3),1) = sym( 0 ) ;
                else
                    iqc(1:2) = body(ib).CC_EB.dof(iqb).equal2 ;
                    iqc(3) = dof_m( iqc(1), iqc(2) ) ;
                end
                
                % replace inf with q(iqc(3))
                body(ib).CC_EB.par = sym( body(ib).CC_EB.par ) ; % change double to sym
                if i2 == 1 % l par
                    intlim(end) = q(iqc(3)); % integration limit
                end
                body(ib).CC_EB.par(i2) = q(iqc(3));
                
                fj(iqc(3),1) = fjC(iqc(3),1) + ... % spring/damper and inputs on DOFs
                    - body(iqc(1)).CC_EB.dof(iqc(2)).spring(1) * ( q(iqc(3)) - body(iqc(1)).CC_EB.dof(iqc(2)).spring(2) ) ... % spring
                    - body(iqc(1)).CC_EB.dof(iqc(2)).damp(1) * u(iqc(3)) ... % viscous
                    + body(iqc(1)).CC_EB.dof(iqc(2)).damp(2); % external input
                
                % stiffness/damping energy
                % for CC_EB: no need for integration
                fj(iqc(3),1) = fjC(iqc(3),1) + ...
                    - body(iqc(1)).CC_EB.stiff(i2) * ( q(iqc(3)) - body(iqc(1)).CC_EB.dof(iqc(2)).init ) ... % spring
                    - body(iqc(1)).CC_EB.viscdamp(i2) * u(iqc(3)) ... % viscous
                    + body(iqc(1)).CC_EB.couldamp(i2) ;
                
                
            end
            
        end
        
    end
    
end


% do for all joints
dof_m = [] ;
for ij = 1 : nj % look into all joints
    iqj = 0 ; % dof counter in each joint
    joint(ij).R.loc = sym( eye ( 3 ) );
    joint(ij).TR.loc = sym( eye ( 4 ) );
    
    [ ~ , njt ] = size( joint(ij).tr ) ; % number of transforamtions in a joint
    ijd = 0 ; % number of dof in joint
    for i3 = 1 : njt
        
        n_rotrans = 5 ; % connect to CC_EB type body as the 1st body
%         if joint(ij).first ~= 0 && ~strcmp( body(joint(ij).first).type , 'rigid' ) && i3 == 1 ; n_rotrans = 3 ; end
        
        rotrans = [ joint(ij).tr(i3).trans joint(ij).tr(i3).rot ] ;
        for i2 = 1 : n_rotrans
            
            if rotrans(i2) == inf
                ijd = ijd + 1 ;
                iqj = iqj + 1;
                
                if isempty( joint(ij).dof(ijd).equal2 )
                    iq = iq + 1;
                    iqc = [ ij iqj iq ] ;
                    dof_m(ij,iqj) = iq ; % dof number
                    qf = [ qf , q(iq) ];
                    qf0 = [ qf0 joint(ij).dof(ijd).init ] ;
                    uf = [ uf , u(iq) ];
                    fj(iqc(3),1) = 0 ;
                else
                    iqc(1:2) = joint(ij).dof(ijd).equal2 ;
                    iqc(3) = dof_m( iqc(1), iqc(2) ) ;
                end
                
                % replace inf with q(iqc(3))
                joint(ij).tr(i3).rot = sym( joint(ij).tr(i3).rot ) ; % change double to sym
                joint(ij).tr(i3).trans = sym( joint(ij).tr(i3).trans ) ;
                if i2 < 4
                    joint(ij).tr(i3).trans(i2) = q(iqc(3));
                else
                    joint(ij).tr(i3).rot(i2-3) = q(iqc(3));                    
                end
                        
                fj(iqc(3),1) = fj(iqc(3),1) + ... % spring/damper and inputs on DOFs
                    - joint(iqc(1)).dof(iqc(2)).spring(1) * ( q(iqc(3)) - joint(iqc(1)).dof(iqc(2)).spring(2) ) ... % spring
                    - joint(iqc(1)).dof(iqc(2)).damp(1) * u(iqc(3)) ... % viscous
                    + joint(iqc(1)).dof(iqc(2)).spring(2); % external input
                
            end
            
        end
        
        if joint(ij).first ~= 0 && ~strcmp( body(joint(ij).first).type , 'rigid' ) && i3 == 1
            l = joint(ij).tr(i3).trans(1)/body(joint(ij).first).CC_EB.dof(1).init(1)*body(joint(ij).first).CC_EB.par(1) ;
            kappa = sqrt( body(joint(ij).first).CC_EB.par(5) ^ 2 + body(joint(ij).first).CC_EB.par(6) ^ 2 ) ;
            phi = atanF( body(joint(ij).first).CC_EB.par(5) , body(joint(ij).first).CC_EB.par(6) ) ;
            crvpar = [ l , kappa , phi ] ;
            [ tmp1 , tmp2 ] = TRc( crvpar , qf , body(joint(ij).first).type );
            [ tmp3 , tmp4 ] = TRm( [ 0 0 0 joint(ij).tr(i3).rot ] , qf );
            joint(ij).R.loc = joint(ij).R.loc * tmp1 * tmp3;
            joint(ij).TR.loc = joint(ij).TR.loc * tmp2 * tmp4;
        else
            [ tmp1 , tmp2 ] = TRm( [ joint(ij).tr(i3).trans joint(ij).tr(i3).rot ] , qf );
            joint(ij).R.loc = joint(ij).R.loc * tmp1;
            joint(ij).TR.loc = joint(ij).TR.loc * tmp2;
        end
        
    end
    
    % for spring/damper and constraints
    if ~isempty( joint(ij).tr2nd )
        joint(ij).R2nd.loc = sym( eye ( 3 ) );
        joint(ij).TR2nd.loc = sym( eye ( 4 ) );
        [ ~ , njt ] = size( joint(ij).tr2nd ) ; % number of transforamtions in a joint
        for i3 = 1 : njt
            if joint(ij).first ~= 0 && ~strcmp( body(joint(ij).first).type , 'rigid' ) && i3 == 1
                l = joint(ij).tr(i3).trans(1)/body(joint(ij).first).CC_EB.dof(1).init(1)*body(joint(ij).first).CC_EB.par(1) ;
                kappa = sqrt( body(joint(ij).first).CC_EB.par(5) ^ 2 + body(joint(ij).first).CC_EB.par(6) ^ 2 ) ;
                phi = atanF( body(joint(ij).first).CC_EB.par(5) , body(joint(ij).first).CC_EB.par(6) ) ;
                crvpar = [ l , kappa , phi ] ;
                [ tmp1 , tmp2 ] = TRc( crvpar , qf , body(joint(ij).first).type );
                [ tmp3 , tmp4 ] = TRm( [ 0 0 0 joint(ij).tr2nd(i3).rot ] , qf );
                joint(ij).R2nd.loc = joint(ij).R2nd.loc * tmp1 * tmp3;
                joint(ij).TR2nd.loc = joint(ij).TR2nd.loc * tmp2 * tmp4;
            else
                [ tmp1 , tmp2 ] = TRm( [ joint(ij).tr2nd(i3).trans joint(ij).tr2nd(i3).rot ] , qf );
                joint(ij).R2nd.loc = joint(ij).R2nd.loc * tmp1;
                joint(ij).TR2nd.loc = joint(ij).TR2nd.loc * tmp2;
            end
        end
    end
    
end


% Start with bodies and creat R|TR. To do so, check R|TR for the
% previous body and if not available creat R|TR for that till reaching
% ground. If the user provides a proper sequence of bodies the sequence of
% generalized coordinates numbers will rational starting frorm 1 for the
% nearest one to the ground
% SHOULD GIVE THE NEARED BODY TO GROUND FIRST
ityp = [ 0 0 ] ; % body type counter [ rigid , other ]
for ib = 1 : nb % number of bodies
              
    for ij = 1 : nj % look into all joints, first one is the main kinematic path and rest are froce and spring and constraints
        
        if joint(ij).second == ib % if the joint connects this body to another one
            
            if joint(ij).first == 0 % the joint number where the new frame is connected to on the firstbody
                joint(ij).R.abs = joint(ij).R.loc ;
                joint(ij).TR.abs = joint(ij).TR.loc ;
            else
                joint(ij).R.abs = body(joint(ij).first).R.abs * joint(ij).R.loc ;
                joint(ij).TR.abs = body(joint(ij).first).TR.abs * joint(ij).TR.loc  ;
            end
            joint(ij).r = joint(ij).TR.abs(1:3,4).';
                        
            body(ib).R.loc = joint(ij).R.loc ;
            body(ib).TR.loc = joint(ij).TR.loc ;
            body(ib).R.abs = joint(ij).R.abs ;
            body(ib).TR.abs = joint(ij).TR.abs ;
            body(ib).prebody = joint(ij).first ; % previous body in the main kinematic chain
            
            r_j = [ r_j ; joint(ij).r , joint(ij).first ] ; % each body local frame origin (joint)
            if ~strcmp( body(ib).type , 'rigid' )
                l = body(ib).CC_EB.tip(1)/body(ib).CC_EB.dof(1).init(1)*body(ib).CC_EB.par(1) ;
                kappa = sqrt( body(ib).CC_EB.par(5) ^ 2 + body(ib).CC_EB.par(6) ^ 2 ) ;
                phi = atanF( body(ib).CC_EB.par(5) , body(ib).CC_EB.par(6) ) ;
                crvpar = [ l , kappa , phi ] ;
                [ ~ , tmp2 ] = TRc( crvpar , qf , body(ib).type );
                tmp3 = body(ib).TR.abs * tmp2 ;
                tmp3 = tmp3(1:3,4).' ;
            else
                tmp3 = body(ib).TR.abs*[ body(ib).rigid.tip 1 ].' ;
                tmp3 = tmp3(1:3).' ;
            end
            r_jtip = [ r_jtip ; joint(ij).r , tmp3 ] ; % each body jint and tip
            joint(ij).r_tip = tmp3 ;
            
            if body(ib).type == 'rigid'   
                
                ityp(1) = ityp(1) + 1 ;
                im = 3 * ityp(1) ;
                iI = 3 * ( nb - nC ) + 3 * ityp(1) ;
                M( im - 2 : im , im - 2 : im ) = body(ib).rigid.m * eye ( 3 ) ;  % first all the linear directions ( 1:3*nb ), then all the rotational directions (3*nb+1:6*nb)
                M( iI - 2 : iI , iI - 2 : iI ) = body(ib).rigid.I ;
                
                tmp3 = sym ( [] );
                for i1 = 1 : 3
                    tmp4 = jacobian( body(ib).R.abs(:,i1) , qf ) * uf.';
                    tmp3 = [ tmp3 , tmp4 ];
                end
                body(ib).omega.tensor = tmp3 * body(ib).R.abs.'; % angular velocity tensor
                body(ib).omega.abs = [ body(ib).omega.tensor(3,2) , body(ib).omega.tensor(1,3) , body(ib).omega.tensor(2,1) ]; % w in base frame
                body(ib).omega.loc = ( body(ib).R.abs.' * body(ib).omega.abs.' ).'; % w in link frame
                
                
                for i1 = 1 : 3
                    for i2 = 1 : iq
                        [ tmp5 , ~ ] = coeffs( body(ib).omega.loc(i1) , uf(i2) );
                        if isempty ( tmp5 )
                            tmp5 = sym ( 0 );
                        end
                        T ( iI - 3 + i1 , i2 ) = tmp5(1);
                    end
                end
                
                Dd ( iI - 2 : iI , 1 : iq ) = jacobian( body(ib).omega.loc.' , qf );
                
                tmp7 = body(ib).TR.abs * [ body(ib).rigid.l_com , 1 ].';
                body(ib).r_com = tmp7(1:3).';
                r_c = [ r_c ; body(ib).r_com ] ; % COM position for output
                tmp8 = jacobian ( tmp7(1:3) , qf );
                body(ib).v_com = ( tmp8 * uf.' ).';
                
                T ( im - 2 : im , 1 : iq ) = tmp8;
                Dd ( im - 2 : im , 1 : iq ) = jacobian ( body(ib).v_com.' , qf );
                
                % gravity generalized work
                fg = [ fg , world.g ];
                
                break ;
            
            end
            
            if body(ib).type == 'CC_EB'

                ityp(2) = ityp(2) + 1 ; % non-rigid body counter
                im = 3 * ityp(2) ;
                iI = 3 * nC + 3 * ityp(2) ;
                MC( im - 2 : im , im - 2 : im ) = body(ib).CC_EB.m * eye( 3 ) ; % first all the linear directions ( 1:3*nb ), then all the rotational directions (3*nb+1:6*nb)
                MC( iI - 2 : iI , iI - 2 : iI ) = body(ib).CC_EB.I ;
                
                l = sf(ityp(2)) ;
                kappa = sqrt( body(ib).CC_EB.par(5) ^ 2 + body(ib).CC_EB.par(6) ^ 2 ) ;
                phi = atanF( body(ib).CC_EB.par(5) , body(ib).CC_EB.par(6) ) ;
                crvpar = [ l , kappa , phi ] ;
                [ tmp1 , tmp2 ] = TRc( crvpar , qf , body(ib).type ); % with integration variable              
                body(ib).R.locC = joint(ij).R.loc * tmp1 ; % for CC_EB elements
                body(ib).TR.locC = joint(ij).TR.loc * tmp2 ;
                body(ib).R.absC = joint(ij).R.abs * tmp1 ;
                body(ib).TR.absC = joint(ij).TR.abs * tmp2 ;
                
                tmp3 = sym ( [] );
                for i1 = 1 : 3
                    tmp4 = jacobian( body(ib).R.absC(:,i1) , qf ) * uf.';
                    tmp3 = [ tmp3 , tmp4 ];
                end
                body(ib).omega.tensor = tmp3 * body(ib).R.absC.'; % angular velocity tensor
                body(ib).omega.abs = [ body(ib).omega.tensor(3,2) , body(ib).omega.tensor(1,3) , body(ib).omega.tensor(2,1) ]; % w in base frame
                body(ib).omega.loc = ( body(ib).R.absC.' * body(ib).omega.abs.' ).'; % w in link frame
                
                
                for i1 = 1 : 3
                    for i2 = 1 : iq
                        [ tmp5 , ~ ] = coeffs( body(ib).omega.loc(i1) , uf(i2) );
                        if isempty ( tmp5 )
                            tmp5 = sym ( 0 );
                        end
                        TC ( iI - 3 + i1 , i2 ) = tmp5(1);
                    end
                end
                
                DdC ( iI - 2 : iI , 1 : iq ) = jacobian( body(ib).omega.loc.' , qf );
                
                tmp7 = body(ib).TR.absC ;
                body(ib).r_com = tmp7(1:3,4).';
                r_c = [ r_c ; body(ib).r_com ] ; % COM position for output
                tmp8 = jacobian ( tmp7(1:3,4) , qf );
                body(ib).v_com = ( tmp8 * uf.' ).';
                
                TC ( im - 2 : im , 1 : iq ) = tmp8;
                DdC ( im - 2 : im , 1 : iq ) = jacobian ( body(ib).v_com.' , qf );
                
                % gravity generalized work
                fgC = [ fgC , world.g ];
                
                break ;
                
            end
            
        end
        
    end
    
end

% gravity generalized work
fg = [ M( 1 : 3 * ( nb - nC ) , 1 : 3 * ( nb - nC ) )*fg.' ; 0*fg.' ] ;
fgC = [ MC( 1 : 3 * nC , 1 : 3 * nC )*fgC.' ; 0*fgC.' ] ;

% spring/dampers
% look for the secondary joints that should be constraint or spring/dampers
w_sd = sym( 0 ) ; % spring/dampers virt. work
Dcn = sym( [] ) ; Tcn = Dcn ;
if par.save == 1
    
    for ib = 0 : nb % number of bodies
        
        for ij = 1 : nj % look into all joints, first one is the main kinematic path and rest are froce and spring and constraints
            
            %         [ ib ij joint(ij).second isempty(joint(ij).tr2nd) ]
            if joint(ij).second == ib && ~isempty( joint(ij).tr2nd ) % if the joint connects this body to another one
                
                if joint(ij).first == 0 % the joint number where the new frame is connected to
                    joint(ij).R.abs = joint(ij).R.loc ;
                    joint(ij).TR.abs = joint(ij).TR.loc ;
                else
                    joint(ij).R.abs = body(joint(ij).first).R.abs * joint(ij).R.loc ;
                    joint(ij).TR.abs = body(joint(ij).first).TR.abs * joint(ij).TR.loc  ;
                end
                joint(ij).r = joint(ij).TR.abs(1:3,4).';
                
                if joint(ij).second == 0 % the joint number where the new frame is connected to on the second body
                    joint(ij).R2nd.abs = joint(ij).R2nd.loc ;
                    joint(ij).TR2nd.abs = joint(ij).TR2nd.loc ;
                else
                    joint(ij).R2nd.abs = body(joint(ij).second).R.abs * joint(ij).R2nd.loc ;
                    joint(ij).TR2nd.abs = body(joint(ij).second).TR.abs * joint(ij).TR2nd.loc  ;
                end
                
                if ~isempty( joint(ij).spring ) || ~isempty( joint(ij).damp ) % is spring/damper
                    
                    % translational spring only at the moment
                    r_sd = joint(ij).TR.abs(1:3,4) - joint(ij).TR2nd.abs(1:3,4) ;
                    dr_sd = jacobian( r_sd , qf ) * uf.' ;
                    w_sd = w_sd - ( ... % spring/damper force virtual work
                        ( joint(ij).spring(1) * ...
                        ( sqrt( r_sd.' * r_sd ) - joint(ij).spring(2) ) + ... % instantanious spring force value
                        joint(ij).damp(1) * ...
                        sqrt( dr_sd.' * dr_sd ) + ... % instantanious viscous force value
                        joint(ij).damp(2) ) * ... % instantanious Coulomb force value
                        r_sd.' / sqrt( r_sd.' * r_sd ) * ... % instantanious force direction
                        jacobian( r_sd , qf ) ... % virtual displacement
                        ).' ; % transpose for TMT method
                    
                else % is constraint
                    icn = icn + 1 ;
                    lambdaf = [ lambdaf, lambda(icn) ] ;
                    
                    % translational constraint only for now
                    rcn(icn,:) = joint(ij).TR.abs(1:3,4).';
                    ecn = joint(ij).TR.abs(1:3,4) - joint(ij).TR2nd.abs(1:3,4) ;
                    tmp11 = jacobian ( ecn , qf );
                    vcn = tmp11 * uf.' ;
                    
                    Tcn = [ Tcn ; tmp11 ] ; % use T.' in dynamics EOM and T in algebraic part
                    Dcn = [ Dcn ; jacobian( vcn , qf ) ] ;
                    
                end
                
            end
            
        end
        
    end
    
end


% handle external forces
% linear force for now
Tef = sym( [] ) ;
for ief = 1 : nef
    
    exload(ief).R.loc = sym( eye ( 3 ) );
    exload(ief).TR.loc = sym( eye ( 4 ) );
    
    [ ~ , njt ] = size( exload(ief).tr ) ; % number of transforamtions in a joint
    for i3 = 1 : njt
        
        if ~strcmp( body(exload(ief).body).type , 'rigid' ) && i3 == 1
            l = exload(ief).tr(i3).trans(1)/body(exload(ief).body).CC_EB.dof(1).init(1)*body(exload(ief).body).CC_EB.par(1) ;
            kappa = sqrt( body(exload(ief).body).CC_EB.par(5) ^ 2 + body(exload(ief).body).CC_EB.par(6) ^ 2 ) ;
            phi = atanF( body(exload(ief).body).CC_EB.par(5) , body(exload(ief).body).CC_EB.par(6) ) ;
            crvpar = [ l , kappa , phi ] ;
            [ tmp1 , tmp2 ] = TRc( crvpar , qf , body(exload(ief).body).type );
            [ tmp3 , tmp4 ] = TRm( [ 0 0 0 exload(ief).tr(i3).rot ] , qf );
            exload(ief).R.loc = exload(ief).R.loc * tmp1 * tmp3;
            exload(ief).TR.loc = exload(ief).TR.loc * tmp2 * tmp4;
        else
            [ tmp1 , tmp2 ] = TRm( [ exload(ief).tr(i3).trans exload(ief).tr(i3).rot ] , qf );
            exload(ief).R.loc = exload(ief).R.loc * tmp1 ;
            exload(ief).TR.loc = exload(ief).TR.loc * tmp2 ;
        end
        
    end
    
    exload(ief).R.abs = body(exload(ief).body).R.abs * exload(ief).R.loc ;
    exload(ief).TR.abs = body(exload(ief).body).TR.abs * exload(ief).TR.loc ;
    
    ref(ief,:) = exload(ief).TR.abs(1:3,4).';
    Tef = [ Tef jacobian( exload(ief).TR.abs(1:3,4) , qf ) ] ; % use T.' in dynamics EOM
end

% Final adjustments
par.nC = nC ;
if nC == 0 ; intlim = sym( 0 ) ; end

% report:
% matlabpool('open', 4);
if par.save == 1
    opv = true ;
    vars = par.sym ;
    parfor i = 1 : 17
        
        switch i
            
            case 1
                matlabFunction ( M , 'file' , 'MF.m' , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv ); % save as matlab function
                
            case 2
                matlabFunction ( T , 'file' , 'TF.m' , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
                
            case 3
                matlabFunction ( fj , 'file' , 'fjF.m' , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
                
            case 4
                matlabFunction ( fg , 'file' , 'fgF.m' , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
                
            case 5
                matlabFunction ( Dd , 'file' , 'DdF.m' , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
                
            case 6
                matlabFunction ( ref , 'file' , 'refF.m' , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
                
            case 7
                matlabFunction ( rcn , 'file' , 'rcnF.m' , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
                
            case 8
                matlabFunction ( Tef , 'file' , 'TefF.m' , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
                
            case 9
                matlabFunction ( Tcn , 'file' , 'TcnF.m' , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
                
            case 10
                matlabFunction ( Dcn , 'file' , 'DcnF.m' , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
                
            case 11
                matlabFunction ( r_jtip , 'file' , 'rjtipF.m' , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
                
            case 12
                if nC ~= 0
                    matlabFunction ( MC , 'file' , 'MCF.m' , 'vars' , {vars , [ qf lambdaf uf] , sf} , 'Optimize' , opv ); % save as matlab function
                end
                
            case 13
                if nC ~= 0
                    matlabFunction ( TC , 'file' , 'TCF.m' , 'vars' , {vars , [ qf lambdaf uf] , sf} , 'Optimize' , opv );
                end
                
            case 14
                if nC ~= 0
                    matlabFunction ( fgC , 'file' , 'fgCF.m' , 'vars' , {vars , [ qf lambdaf uf] , sf} , 'Optimize' , opv );
                end
                
            case 15
                if nC ~= 0
                    matlabFunction ( DdC , 'file' , 'DdCF.m' , 'vars' , {vars , [ qf lambdaf uf] , sf} , 'Optimize' , opv );
                end
                
            case 16
                matlabFunction ( intlim , 'file' , 'intlimF.m' , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
            
            case 17
                matlabFunction ( w_sd , 'file' , 'w_sdF.m' , 'vars' , {vars , [ qf lambdaf uf]} , 'Optimize' , opv );
                
        end
        
    end
    
end



%% Complementary Functions:

function [ R , TR ] = TRm( r , q ) % base rotation matices

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


function [ R , TR ] = TRc( r , q , type ) % for CC_EB, VC

if ~strcmp( type , 'rigid' )
    
    s = r(1); kappa = r(2); phi = r(3); theta = s * kappa ;
    
    % for CC
%     rho =  [ cos(phi)*(1-cos(theta))/kappa , sin(phi)*(1-cos(theta))/kappa , sin(theta)/kappa ] ; % CC
    rho =  [ cos(phi)*s*sin(theta/2) , sin(phi)*s*sin(theta/2) , s*cos(theta/2) ] ; % lim_{kappa \to 0}, hyperbolic
    [ ~ , TR1 ] = TRm( [ 0 0 0 3 phi ] ) ;
    [ ~ , TR2 ] = TRm( [ rho 2 theta ] ) ;
    [ ~ , TR3 ] = TRm( [ 0 0 0 3 -phi ] ) ;  

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


function [ R , TR ] = TRm_lim( r , q ) % base rotation matices

i = r(4);
x = r(5);

if i == 1
    R = [ ...
        1  0   0 ;
        0  1  -x ;
        0  x   1 ];
    
else if i == 2
        R = [ ...
            1  0  x ;
            0  1  0 ;
           -x  0  1 ];
        
    else if i == 3
            R = [ ...
                1  -x  0 ;
                x   1  0 ;
                0   0  1 ];
        else
            R = sym ( eye ( 3 ) );
            
        end
    end
end

TR = sym ( [ [ R , r(1:3).' ] ; 0 0 0 1 ] ); % Each TR contains a translation and then a rotation

