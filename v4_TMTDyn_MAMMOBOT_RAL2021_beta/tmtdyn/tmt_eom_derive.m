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


% mesh
if ~isempty( mesh.file_name )
    [ ~ , ~ , body , joint , ~ , mesh ] = check( par , [] , body , joint , [] , mesh ) ; % not mesh body/joint check
    [ body_mesh , joint_mesh ] = mesh_import( body , joint , mesh , par ) ; % mesh import
    body = [ body body_mesh ] ; % first indvidual bodies
    joint = [ joint_mesh joint ] ; % first mesh joints
end

% all check
[ s , world , body , joint , exload , mesh , par , symbols ] = check( par , world , body , joint , exload , mesh ) ;

if par.clean % clean up memory
    clearvars mesh
end

% >> Initialization:
syms sw % unit length for logistic function switch to simplify diff.s w.r.t. s
global unit_quat par_simplify par_sparse
unit_quat = 1 ; % is unit quaternion?
par_simplify = par.simplify ;
par_sparse = par.sparse ;

[ ~ , n_b ] = size( body ) ; % number of bodies
[ ~ , n_ex ] = size( exload ) ; % number of ext. forces/torques
[ ~ , n_j ] = size( joint ) ; % number of joints

emps = sym( [] ) ; zerosym = sym( 0 ) ;
M = emps ; fgv = emps ; T = emps ; Dd = emps ;
Dcn = emps ; Tcn = emps ; Ccn = emps ; Tcu = emps ;
q = emps ; u = emps ; q0 = emps ; % all dofs
lambda = emps ; dlambda = emps ; gamma = emps ; dgamma = emps ;
r_c = emps ; ref = emps ; rcn = emps ;
r_jtips = emps ; r_ks = emps ;

mass.M = emps ; mass.T = emps ; mass.Dd = emps ; mass.fg = emps ;
sprdmp.Tt = emps ; sprdmp.kx = emps ; sprdmp.vd = emps ; sprdmp.dl = emps ;
sprdmp.in = emps ; sprdmp.k_mat = emps ; sprdmp.vd_mat = emps ; sprdmp.dir = emps ;
sprdmp.Tt_u = emps ;
cnst.r = emps ; cnst.T = emps ; cnst.Tt = emps ; cnst.D = emps ; cnst.in = emps ;
loads.Tt = emps ; loads.ftau = emps ; loads.Tt_o = emps ;

% >> Derivation:
n_sd = 0 ; % spring/damper counter
nq = 0 ; nq_mat = [ 0 0 0 ] ; % total dof counter
n_cn = 0; % constraint position counter
n_co = 0 ; % control input/observer counter
fj_k = sym( 0 ) ; % for joint spring
fj_vd = sym( 0 ) ; % for joint viscous damping
fj_in = sym( 0 ) ; %for joint Coulomb damping
fj_k_mat = sym( 0 ) ;
fj_sdi = sym( 0 ) ;
fj_vd_mat = sym( 0 ) ;
Tj_u = emps ;


% all joints
fprintf( 'Deriving joint transformations for joint... \n' )
dof_m = [] ; % 3x3 cube
rom.sprdmp = [] ; % reduced order model indicator
if par.plotIC > 0; fig_rom = figure; else; fig_rom = []; end
for j_count = 1 : n_j % look into all joints
    j_count
    
    joint(j_count).n_mesh = max( [ numel( joint(j_count).first(1,:) ) , numel( joint(j_count).second(1,:) ) ] ) - 1;
    for n_mesh = 1 : joint(j_count).n_mesh
        nj_dof = 0 ; % dof counter in each joint
        joint(j_count).Q(n_mesh).loc = sym( [ 1 0 0 0 ].' );
        joint(j_count).TQ(n_mesh).loc = sym( [ 1 0 0 0 ; 0 0 0 0 ].' );
        joint(j_count).spring.Q(n_mesh).loc = sym( [ 1 0 0 0 ].' ); % for rom body initial configuration
        joint(j_count).spring.TQ(n_mesh).loc = sym( [ 1 0 0 0 ; 0 0 0 0 ].' );
        
        joint(j_count).i_q{n_mesh} = emps ; % current joint elements number in q
        joint(j_count).spring.q0{n_mesh} = emps ; % current joint initial configuration
        [ ~ , nj_tr ] = size( joint(j_count).tr ) ; % number of transforamtions in a joint
        rotrans = []; rotrans_spring = []; rotrans_cond = []; rotrans_spring_cond = [];
        rotrans{1} = emps; rotrans_spring{1} = emps; rotrans_cond{1} = 1; rotrans_spring_cond{1} = 1; rotrans_itr = [];
        i3_merg = 0; % rotrans merged indexes
        for i3 = 1 : nj_tr
            rotrans_itr(i3-i3_merg) = i3; % the original transfomration number:
            rotrans_i = sym( [ joint(j_count).tr(i3).trans , joint(j_count).tr(i3).rot ] ).' ; % initial rotrans
            rotrans_spring_i = sym( [ joint(j_count).tr(i3).trans , joint(j_count).tr(i3).rot ] ).' ;
            rotrans{i3-i3_merg} = rotrans_i ; rotrans_spring{i3-i3_merg} = rotrans_spring_i ; % updated rotrans with qs
            rotrans_cond{i3-i3_merg} = 1; rotrans_spring_cond{i3-i3_merg} = 1; % spline logistic functions
            
            isq = 0 ; % if quat. rot. contains states
            for i2 = 1 : numel( rotrans{i3-i3_merg}(:,1) )
                if rotrans{i3-i3_merg}(i2,1) == inf
                    if i2 > 3 % rot with dof
                        isq = 1 ;
                    end
                    nj_dof = nj_dof + 1;
                    dof_mult{1} = 1 ; % single dof
                    dof_mult_index{1}(:,:,1) = 1 : dof_mult{1} ;
                    
                    for i_kn = 1 : numel( joint(j_count).dof(nj_dof).fit_type(n_mesh,:) ) % spline segments
                        if i_kn > 1 && isnan( joint(j_count).dof(nj_dof).equal2{1}(n_mesh,4) ); continue; end % dof similar to another dof, so skip
                        % dofs kin. const.s & rom IC
                        [joint, dof_mult, dof_mult_index] = dof_fit(s, sw, q, q0, par, joint, j_count, nj_dof, n_mesh, i_kn, fig_rom);
                        
                        % extract dofs
                        for i_dof_mult = 1 : dof_mult{i_kn}
                            i_rom = dof_mult_index{i_kn}(i_dof_mult) ;
                            if joint(j_count).dof(nj_dof).equal2{dof_mult_index{i_kn}(1,i_dof_mult)}(n_mesh,1) == 0 % [j_count, n_mesh, nj_dof, i_dof_mult, l_rom, diff_order, coeff] x i_dof_mult
                                n_sd = n_sd + 1 ;
                                nq = nq + 1;
                                nq_mat = [ j_count nj_dof nq n_sd ] ;
                                dof_m(:,:,i_dof_mult,nj_dof,n_mesh,j_count) = [ nq n_sd ] ; % dof number
                                q = [ q , sym( [ 'q' num2str( nq ) ] , 'real' ) ];
                                q0 = [ q0 , joint(j_count).dof(nj_dof).init_fit{n_mesh,i_kn}(i_dof_mult) ] ; % only all element ICs in an array
                                u = [ u , sym( [ 'u' num2str( nq ) ] , 'real' ) ];
                                fj_k(nq,1) = 0 ;
                                fj_vd(nq,1) = 0 ;
                                fj_in(nq,1) = 0 ;
                                fj_k_mat(nq,nq) = 0 ;
                                fj_vd_mat(nq,nq) = 0 ;
                            else % geometrical constraint between dof.s, for rigid body dof.s only
                                n_sd = n_sd + 1 ; % can have its own stiffness/damping/input elements
                                temp = joint(j_count).dof(nj_dof).equal2{dof_mult_index{i_kn}(1,i_dof_mult)}(n_mesh,:) ; % [j_count, n_mesh, nj_dof, i_dof_mult, val_or_l_rom, diff_order, coeff] x i_dof_mult
                                if isnan( temp(4) ) %  coeff. no. in the refrence dof similar to the current (this) coeff.
                                    temp(4) = dof_mult_index{i_kn}(1,i_dof_mult) ;
                                end
                                nq_mat([1 2 4]) = [ j_count nj_dof n_sd ] ;
                                nq_mat(3) = dof_m( 1 , 1 , temp(4) , temp(3) , temp(2) , temp(1) ) ; % only similar q
                                if isnan( joint(j_count).dof(nj_dof).init_fit{n_mesh,i_kn}(i_dof_mult) ) % q0 is similar to the ref. dof's q0
                                    joint(j_count).dof(nj_dof).init_fit{n_mesh,i_kn}(i_dof_mult) = joint(temp(1)).dof(temp(3)).init_all{temp(2)}(end,dof_mult_index{i_kn}(1,i_dof_mult)) ;
                                end
                            end
                            
                            % for each spring
                            rom.sprdmp = [ rom.sprdmp; 0, 0 ] ;
                            sprdmp(nq_mat(4)).Tt(nq_mat(3),1) = 1 ;
                            if joint(nq_mat(1)).dof(nq_mat(2)).spring.coeff(n_mesh,i_rom) ~= 0
                                sprdmp(nq_mat(4)).kx = smplfy( - joint(nq_mat(1)).dof(nq_mat(2)).spring.coeff(n_mesh,i_rom) * ...
                                    ( q(nq_mat(3)) - joint(nq_mat(1)).dof(nq_mat(2)).spring.compr(n_mesh,i_rom) * joint(nq_mat(1)).dof(nq_mat(2)).spring.init_all{n_mesh}(end,i_rom) ) ) ; % spring
                                sprdmp(nq_mat(4)).dl = smplfy( q(nq_mat(3)) - joint(nq_mat(1)).dof(nq_mat(2)).spring.init_all{n_mesh}(end,i_rom) ) ; % spring delta-l
                            else
                                sprdmp(nq_mat(4)).kx = 0;
                                sprdmp(nq_mat(4)).dl = 0;
                            end
                            sprdmp(nq_mat(4)).vd = smplfy( - joint(nq_mat(1)).dof(nq_mat(2)).damp.visc(n_mesh,i_rom) ...
                                * u(nq_mat(3)) ) ; % viscous
                            if joint(nq_mat(1)).dof(nq_mat(2)).damp.pow(n_mesh,i_rom) ~= 1 % speedup trick
                                sprdmp(nq_mat(4)).vd = sprdmp(nq_mat(4)).vd * abs( u(nq_mat(3)) ).^( joint(nq_mat(1)).dof(nq_mat(2)).damp.pow(n_mesh,i_rom) - 1 ) ;
                            end
                            sprdmp(nq_mat(4)).in = smplfy( joint(nq_mat(1)).dof(nq_mat(2)).input(n_mesh,i_rom) ) ; % external input
                            sprdmp(nq_mat(4)).k_mat(1,nq_mat(3)) = smplfy( joint(nq_mat(1)).dof(nq_mat(2)).spring.coeff(n_mesh,i_rom) ) ; % spring
                            sprdmp(nq_mat(4)).vd_mat(1,nq_mat(3)) = smplfy( - joint(nq_mat(1)).dof(nq_mat(2)).damp.visc(n_mesh,i_rom) ) ; % viscous
                            if joint(nq_mat(1)).dof(nq_mat(2)).damp.pow(n_mesh,i_rom) ~= 1
                                sprdmp(nq_mat(4)).vd_mat(1,nq_mat(3)) = sprdmp(nq_mat(4)).vd_mat(1,nq_mat(3)) * abs( u(nq_mat(3)) ).^( joint(nq_mat(1)).dof(nq_mat(2)).damp.pow(n_mesh,i_rom) - 1 ) ;
                            end
                                                        
                            % if input is considered part of the inverse controller
                            if isinf( joint(nq_mat(1)).dof(nq_mat(2)).input(n_mesh,i_rom) )
                                sprdmp(nq_mat(4)).in = 0 ;
                                
                                n_co = n_co + 1 ;
                                gamma = [ gamma, sym( [ 'gamma' num2str( n_co ) ] , 'real' ) ] ;
                                dgamma = [ dgamma, sym( [ 'dgamma' num2str( n_co ) ] , 'real' ) ] ;
                                
                                sprdmp(nq_mat(4)).Tt_u = sprdmp(nq_mat(4)).Tt ;
                                Tj_u(nq_mat(3),n_co) = 1 ; % for unknown input to be found from inverse Jacobian controller
                            end
                            
                            switch joint(nq_mat(1)).dof(nq_mat(2)).dir(n_mesh,i_rom)
                                case 1 % compression-only elements, e.g. soft contact
                                    sprdmp(nq_mat(4)).dir = smplfy( sign( sprdmp(nq_mat(4)).dl ) + 1 ) / 2 ;
                                case 0 % both dir.ss, e.g. regular spring/damper
                                    sprdmp(nq_mat(4)).dir = 1 ;
                                case -1 % tension-only elements, e.g. wire
                                    sprdmp(nq_mat(4)).dir = smplfy( - sign( sprdmp(nq_mat(4)).dl ) + 1 ) / 2 ;
                            end
                            
                            % better to keep this form rather than sprdmp
                            fj_k(nq_mat(3),1) = fj_k(nq_mat(3),1) ... % spring on DOFs
                                + sprdmp(nq_mat(4)).dir * sprdmp(nq_mat(4)).kx ;
                            fj_vd(nq_mat(3),1) = fj_vd(nq_mat(3),1) ... % damper on DOFs
                                + sprdmp(nq_mat(4)).dir * sprdmp(nq_mat(4)).vd ;
                            fj_in(nq_mat(3),1) = fj_in(nq_mat(3),1) ... % inputs on DOFs
                                + sprdmp(nq_mat(4)).dir * sprdmp(nq_mat(4)).in ;
                            fj_sdi(nq_mat(3),1) = sprdmp(nq_mat(4)).dir * ( sprdmp(nq_mat(4)).kx + sprdmp(nq_mat(4)).vd + sprdmp(nq_mat(4)).in ) ; % all spring/damper/input force virtual work
                            fj_k_mat(nq_mat(3),nq_mat(3)) = fj_k_mat(nq_mat(3),nq_mat(3)) ... % spring on DOFs
                                + sprdmp(nq_mat(4)).k_mat(1,nq_mat(3)) ;
                            fj_vd_mat(nq_mat(3),nq_mat(3)) = fj_vd_mat(nq_mat(3),nq_mat(3)) ... % damper on DOFs
                                + sprdmp(nq_mat(4)).vd_mat(1,nq_mat(3)) ;
                            
                            % if direct geometrical control available
                            if joint(nq_mat(1)).dof(nq_mat(2)).control(n_mesh,i_rom) ~= 0
                                sprdmp(nq_mat(4)).in = 0 ;
                                fj_in(nq_mat(3),1) = 0;
                                
                                n_cn = n_cn + 1 ;
                                lambda = [ lambda, sym( [ 'lambda' num2str( n_cn ) ] , 'real' ) ] ;
                                dlambda = [ dlambda, sym( [ 'dlambda' num2str( n_cn ) ] , 'real' ) ] ;
                                
                                cnst(n_cn).r = q(nq_mat(3)) ; % constraint relation
                                cnst(n_cn).T = sprdmp(nq_mat(4)).Tt.' ; % use T.' in dynamics EOM and T in algebraic part
                                vcn = cnst(n_cn).T * u.' ;
                                cnst(n_cn).D = myJacobian( vcn , q ) ;
                                cnst(n_cn).in = joint(nq_mat(1)).dof(nq_mat(2)).control(n_mesh,i_rom) ;
                                
                                if par.derive_collect == 5 % collect most terms
                                    cnst(n_cn).dc = - cnst(n_cn).Dc * u.' + cnst(n_cn).in;
                                end
                                
                                % sparse matrix
                                cnst(n_cn).r = sprse( cnst(n_cn).r ) ;
                                cnst(n_cn).T = sprse( cnst(n_cn).T ) ;
                                cnst(n_cn).D = sprse( cnst(n_cn).D ) ;
                            end
                            
                            if par.derive_collect == 5% collect most terms
                                sprdmp(nq_mat(4)).w_vd_j = sprdmp(nq_mat(4)).dir * sprdmp(nq_mat(4)).Tt * sprdmp(nq_mat(4)).vd * ( rom.sprdmp(end,2) - rom.sprdmp(end,1) ) ;
                                sprdmp(nq_mat(4)).w_sd = sprdmp(nq_mat(4)).dir * sprdmp(nq_mat(4)).Tt * sprdmp(nq_mat(4)).kx * ( rom.sprdmp(end,2) - rom.sprdmp(end,1) ) ;
                                sprdmp(nq_mat(4)).w_in = sprdmp(nq_mat(4)).dir * sprdmp(nq_mat(4)).Tt * sprdmp(nq_mat(4)).in * ( rom.sprdmp(end,2) - rom.sprdmp(end,1) ) ;
                                sprdmp(nq_mat(4)).Tt_u = sprdmp(nq_mat(4)).Tt_u * ( rom.sprdmp(end,2) - rom.sprdmp(end,1) ) ;
                            end
                            
                            % sparse matrices
                            sprdmp(nq_mat(4)).Tt = sprse( sprdmp(nq_mat(4)).Tt ) ;
                            sprdmp(nq_mat(4)).kx = sprse( sprdmp(nq_mat(4)).kx ) ;
                            sprdmp(nq_mat(4)).dl = sprse( sprdmp(nq_mat(4)).dl ) ;
                            sprdmp(nq_mat(4)).vd = sprse( sprdmp(nq_mat(4)).vd ) ;
                            sprdmp(nq_mat(4)).in = sprse( sprdmp(nq_mat(4)).in ) ;
                            sprdmp(nq_mat(4)).k_mat = sprse( sprdmp(nq_mat(4)).k_mat ) ;
                            sprdmp(nq_mat(4)).vd_mat = sprse( sprdmp(nq_mat(4)).vd_mat ) ;
                        end
                        
                        joint(j_count).dof(nj_dof).qs{n_mesh,i_kn} = emps ;
                        joint(j_count).dof(nj_dof).qs0{n_mesh,i_kn} = emps ;
                        joint(j_count).dof(nj_dof).i_q{n_mesh,i_kn} = emps ;
                        if dof_mult{i_kn} > 0
                            joint(j_count).dof(nj_dof).qs{n_mesh,i_kn} = q(nq-dof_mult{i_kn}+1:nq) ;
                            joint(j_count).dof(nj_dof).qs0{n_mesh,i_kn} = q0(nq-dof_mult{i_kn}+1:nq) ;
                            joint(j_count).dof(nj_dof).i_q{n_mesh,i_kn} = nq-dof_mult{i_kn}+1:nq ;
                            joint(j_count).i_q{n_mesh} = [ joint(j_count).i_q{n_mesh} , nq-dof_mult{i_kn}+1:nq ] ;
                        end
                        
                        if ~isempty( joint(j_count).rom.order ) && ... % reduced order model
                                ~isnan( joint(j_count).dof(nj_dof).equal2{1}(n_mesh,4) ) % dof similar to another dof, so skip
                            if ~isempty( joint(j_count).dof(nj_dof).qs{n_mesh,i_kn} )
                                joint(j_count).dof(nj_dof).rom_coeff{n_mesh,i_kn}(1,dof_mult_index{i_kn}) = joint(j_count).dof(nj_dof).qs{n_mesh,i_kn} ;
                                joint(j_count).dof(nj_dof).rom_series{n_mesh}(1,i_kn) = ...
                                    joint(j_count).dof(nj_dof).qs{n_mesh,i_kn} * joint(j_count).dof(nj_dof).s{n_mesh,i_kn}.' + ...
                                    joint(j_count).dof(nj_dof).q_equal{n_mesh,i_kn} * joint(j_count).dof(nj_dof).b{n_mesh,i_kn}.' ;
                            else
                                joint(j_count).dof(nj_dof).rom_series{n_mesh}(1,i_kn) = ...
                                    joint(j_count).dof(nj_dof).q_equal{n_mesh,i_kn} * joint(j_count).dof(nj_dof).b{n_mesh,i_kn}.' ;
                            end
                        end
                    end
                    
                    if ~isempty( joint(j_count).rom.order ) % reduced order model
                        % logistic function coefficients
                        if numel( joint(j_count).dof(nj_dof).cond ) > 1
                            joint(j_count).dof(nj_dof).rom_series{n_mesh}(1,end+1) = joint(j_count).dof(nj_dof).rom_series{n_mesh}(1,1);
                            for i_kn = 2 : numel( joint(j_count).dof(nj_dof).cond ) % joint(j_count).dof(nj_dof).cond(1) is always = 1
                                joint(j_count).dof(nj_dof).rom_series{n_mesh}(1,end)= joint(j_count).dof(nj_dof).rom_series{n_mesh}(1,end) - ...
                                    joint(j_count).dof(nj_dof).cond(i_kn) * joint(j_count).dof(nj_dof).rom_series{n_mesh}(1,i_kn-1) + ... % to cancel previous term
                                    joint(j_count).dof(nj_dof).cond(i_kn) * joint(j_count).dof(nj_dof).rom_series{n_mesh}(1,i_kn) ; % new term
                            end
                        end
                        % s offset:
                        if isempty( joint(j_count).dof(nj_dof).spring.rom_offset(n_mesh) )
                            joint(j_count).dof(nj_dof).spring.rom_offset(n_mesh) = joint(j_count).dof(nj_dof).rom_offset(n_mesh) ;
                        end
                        joint(j_count).dof(nj_dof).rom_series{n_mesh}(2,:) = joint(j_count).dof(nj_dof).rom_series{n_mesh}(1,:) ; % to preserve original terms for full dof (not single coeff) equality constraint
                        joint(j_count).dof(nj_dof).cond(2,:) = joint(j_count).dof(nj_dof).cond(1,:);
                        joint(j_count).dof(nj_dof).rom_series{n_mesh}(1,:) = subs( joint(j_count).dof(nj_dof).rom_series{n_mesh}(1,:) , [s, sw] , [s, sw] + joint(j_count).dof(nj_dof).rom_offset(n_mesh) );
                        joint(j_count).dof(nj_dof).cond(1,:) = subs( joint(j_count).dof(nj_dof).cond(1,:) , [s, sw] , [s, sw] + joint(j_count).dof(nj_dof).rom_offset(n_mesh) );
                        joint(j_count).dof(nj_dof).spring.init_rom_series{n_mesh} = subs( joint(j_count).dof(nj_dof).spring.init_rom_series{n_mesh} , [s, sw] , [s, sw] + joint(j_count).dof(nj_dof).spring.rom_offset(n_mesh) );
                        joint(j_count).dof(nj_dof).spring.cond = subs( joint(j_count).dof(nj_dof).spring.cond , [s, sw] , [s, sw] + joint(j_count).dof(nj_dof).spring.rom_offset(n_mesh) );
                        % rotrans for Q & TQ
                        n_rotrans = numel( joint(j_count).dof(nj_dof).rom_series{n_mesh}(1,:) ); % kin
                        rotrans{i3-i3_merg}(i2,1:n_rotrans) = smplfy( joint(j_count).dof(nj_dof).rom_series{n_mesh}(1,:) ) ;
                        rotrans{i3-i3_merg}(i2+1:end,1:n_rotrans) =  rotrans_i(i2+1:end) .* ones(1,n_rotrans); % copy the rest of elements
                        n_rotrans_spring = numel( joint(j_count).dof(nj_dof).spring.init_rom_series{n_mesh}(1,:) ); % IC
                        rotrans_spring{i3-i3_merg}(i2,1:n_rotrans_spring) = smplfy( joint(j_count).dof(nj_dof).spring.init_rom_series{n_mesh}(1,:) ) ;
                        rotrans_spring{i3-i3_merg}(i2+1:end,1:n_rotrans_spring) =  rotrans_spring_i(i2+1:end) .* ones(1,n_rotrans_spring); % copy the rest of elements
                    else
                        rotrans{i3-i3_merg}(i2,1) = q(nq);
                        rotrans_spring{i3-i3_merg}(i2,1) = q(nq);
                    end
                end
            end
                        
            if i3 > 1 && ... % combine similar single-axis rotations for derivation efficiency (no need for transfomrations)
                    strcmp( joint(j_count).tr(i3-1).rot_type , 'angle_axis' ) && ... % both angle-axis
                    strcmp( joint(j_count).tr(i3).rot_type , 'angle_axis' ) && ...
                    min( double( rotrans{i3-i3_merg}(1:3,end) == 0 ) ) && ... % pure rotation (no translation)
                    min( double( rotrans{i3-i3_merg}(5:7,end) == rotrans{i3-i3_merg-1}(5:7,end) ) ) % similar axis
                rotrans{i3-i3_merg-1}(4,:) = rotrans{i3-i3_merg-1}(4,:) + rotrans{i3-i3_merg}(4,:) ; % add-up angles
                rotrans_spring{i3-i3_merg-1}(4,:) = rotrans_spring{i3-i3_merg-1}(4,:) + rotrans_spring{i3-i3_merg}(4,:) ;
                i3_merg = i3_merg + 1;
                % no need to update rotrans_itr
            end
            
            % spline simplification with implementing logistic functions only once
            if ( max( double( joint(j_count).rom.fit_type(n_mesh,:) == joint(j_count).dof(nj_dof).fit_type(n_mesh,:) ) ) && ... % logistic function has default knots for all dofs
                    max( double( joint(j_count).rom.spring_fit_type(n_mesh,:) == joint(j_count).dof(nj_dof).spring.fit_type(n_mesh,:) ) ) ) || ... % logistic function has default knots for all springs
                    joint(j_count).rom.fit_type.simpKnot % explicitly asked for this simplification
                rotrans_cond{i3-i3_merg} = joint(j_count).dof(nj_dof).cond(1,:);
                rotrans_spring_cond{i3-i3_merg} = joint(j_count).dof(nj_dof).spring.cond;
            end
        end
        
        % derive local transformations for each joint
        for i3 = 1 : nj_tr - i3_merg
            % for main transfomrations
            Q_temp = []; TQ_temp = []; Q_temp{1} = emps; TQ_temp{1} = emps;
            if numel( rotrans_cond{i3} ) == 1
                [ Q_temp{1} , TQ_temp{1} ] = TQ_mat( rotrans{i3}(:,end).' , [ q s ] , joint(j_count).tr(rotrans_itr(i3)).rot_type , joint(j_count).tr(rotrans_itr(i3)).init_quat );
            else
                for i_kn = 1 : numel( rotrans_cond{i3} )
                    [ Q_temp{i_kn} , TQ_temp{i_kn} ] = TQ_mat( rotrans{i3}(:,i_kn).' , [ q s ] , joint(j_count).tr(rotrans_itr(i3)).rot_type , joint(j_count).tr(rotrans_itr(i3)).init_quat );
                end
                % logistic function coefficients
                Q_temp{end+1} = Q_temp{1}; TQ_temp{end+1} = TQ_temp{1};
                for i_kn = 2 : numel( rotrans_cond{i3} ) % rotrans_cond{1} is always = 1
                    Q_temp{end} = Q_temp{end} - rotrans_cond{i3}(i_kn) * Q_temp{i_kn-1} + rotrans_cond{i3}(i_kn) * Q_temp{i_kn} ;
                    TQ_temp{end} = TQ_temp{end} - rotrans_cond{i3}(i_kn) * TQ_temp{i_kn-1} + rotrans_cond{i3}(i_kn) * TQ_temp{i_kn} ;
                end
            end
            joint(j_count).Q(n_mesh).loc = Q_mult( joint(j_count).Q(n_mesh).loc , Q_temp{end} ) ;
            joint(j_count).TQ(n_mesh).loc = TQ_mult( joint(j_count).TQ(n_mesh).loc , TQ_temp{end} ) ;
            
            % for parallel spring
            if ~isempty( joint(j_count).rom.order ) % reduced order model
                Q_temp = []; TQ_temp = []; Q_temp{1} = emps; TQ_temp{1} = emps;
                if numel( rotrans_spring_cond{i3} ) == 1
                    [ Q_temp{1} , TQ_temp{1} ] = TQ_mat( rotrans_spring{i3}(:,end).' , [ q s ] , joint(j_count).tr(rotrans_itr(i3)).rot_type , joint(j_count).tr(rotrans_itr(i3)).init_quat );
                else
                    for i_kn = 1 : numel( rotrans_spring_cond{i3} )
                        [ Q_temp{i_kn} , TQ_temp{i_kn} ] = TQ_mat( rotrans_spring{i3}(:,i_kn).' , [ q s ] , joint(j_count).tr(rotrans_itr(i3)).rot_type , joint(j_count).tr(rotrans_itr(i3)).init_quat );
                    end
                    % logistic function coefficients
                    Q_temp{end+1} = Q_temp{1}; TQ_temp{end+1} = TQ_temp{1};
                    for i_kn = 2 : numel( rotrans_spring_cond{i3} ) % rotrans_cond{1} is always = 1
                        Q_temp{end} = Q_temp{end} - rotrans_spring_cond{i3}(i_kn) * Q_temp{i_kn-1} + rotrans_spring_cond{i3}(i_kn) * Q_temp{i_kn} ;
                        TQ_temp{end} = TQ_temp{end} - rotrans_spring_cond{i3}(i_kn) * TQ_temp{i_kn-1} + rotrans_spring_cond{i3}(i_kn) * TQ_temp{i_kn} ;
                    end
                end
                joint(j_count).spring.Q(n_mesh).loc = Q_mult( joint(j_count).spring.Q(n_mesh).loc , Q_temp{end} ) ;
                joint(j_count).spring.TQ(n_mesh).loc = TQ_mult( joint(j_count).spring.TQ(n_mesh).loc , TQ_temp{end} ) ;
            end
        end
        
        % rom variable length:
        % placed here for cases where dl is a function of same joint dof
        if ~isempty( joint(j_count).rom.order ) % reduced order model
            % length: [init_length_start, init_length_end, type, coeff, j_count, n_mesh, nj_dof, i_dof_mult, l_rom]
            if joint(j_count).rom.length(n_mesh,4) ~= 0 % coeff
                temp = joint(j_count).rom.length(n_mesh,5:end) ; % [j_count, n_mesh, nj_dof, i_dof_mult, l_rom]
                if temp(4) > 0
                    joint(j_count).rom.dl(n_mesh,1) = joint(j_count).rom.length(n_mesh,4) * joint(temp(1)).dof(temp(3)).rom_coeff{temp(2),1}(temp(4)) ;
                else
                    joint(j_count).rom.dl(n_mesh,1) = joint(j_count).rom.length(n_mesh,4) * subs( joint(temp(1)).dof(temp(3)).rom_series{temp(2)}(1,end) , [s, sw] , temp(5) * [1, 1] ) ;
                end
                joint(j_count).rom.length(n_mesh,2) = joint(j_count).rom.length(n_mesh,2) + joint(j_count).rom.dl(n_mesh,1);
            else
                joint(j_count).rom.dl(n_mesh,1) = 0;
            end
            if joint(j_count).rom.length(n_mesh,3) < 0 % base_growing or sliding
                joint(j_count).Q(n_mesh).loc = subs( joint(j_count).Q(n_mesh).loc , [s, sw] , [s, sw] + joint(j_count).rom.dl(n_mesh,1) ) ; % should update sw too to maintain knot loc.s
                joint(j_count).TQ(n_mesh).loc = subs( joint(j_count).TQ(n_mesh).loc , [s, sw] , [s, sw] + joint(j_count).rom.dl(n_mesh,1) ) ;
                if joint(j_count).rom.length(n_mesh,3) == -1 % base_growing only
                    joint(j_count).rom.length(n_mesh,1) = joint(j_count).rom.length(n_mesh,1) - joint(j_count).rom.dl(n_mesh,1) ; % base_growing shuold be integrated for -q_s:original_length
                    joint(j_count).rom.length(n_mesh,2) = joint(j_count).rom.length(n_mesh,2) - joint(j_count).rom.dl(n_mesh,1) ;
                end
            end
            for ij_dof = 1 : nj_dof % update rom_series too for kin. const.s at tip
                joint(j_count).dof(ij_dof).rom_series{n_mesh}(2,:) = joint(j_count).dof(ij_dof).rom_series{n_mesh}(1,:) ; % to preserve original terms for full dof (not single coeff) equality constraint
                joint(j_count).dof(ij_dof).rom_series{n_mesh}(1,:) = subs( joint(j_count).dof(ij_dof).rom_series{n_mesh}(1,:) , s , s + joint(j_count).rom.dl(n_mesh,1) ) ; % no need to update sw
            end
        end
        
        % for spring/damper and constraints
        if ~isempty( joint(j_count).tr2nd.trans )
            joint(j_count).Q2nd(n_mesh).loc = sym( [ 1 0 0 0 ].' );
            joint(j_count).TQ2nd(n_mesh).loc = sym( [ 1 0 0 0 ; 0 0 0 0 ].' );
            [ ~ , nj_tr ] = size( joint(j_count).tr2nd ) ; % number of transforamtions in a joint
            for i3 = 1 : nj_tr
                [ Q_temp , TQ_temp ] = TQ_mat( [ joint(j_count).tr2nd(i3).trans joint(j_count).tr2nd(i3).rot ] , [ q s ] , joint(j_count).tr2nd(i3).rot_type );
                joint(j_count).Q2nd(n_mesh).loc = Q_mult( joint(j_count).Q2nd(n_mesh).loc , Q_temp ) ;
                joint(j_count).TQ2nd(n_mesh).loc = TQ_mult( joint(j_count).TQ2nd(n_mesh).loc , TQ_temp ) ;
            end
        end
    end
end

fj_k = sprse( fj_k ) ;
fj_vd = sprse( fj_vd ) ;
fj_in = sprse( fj_in ) ;
fj_sdi = sprse( fj_sdi ) ;
fj_k_mat = sprse( fj_k_mat ) ;
fj_vd_mat = sprse( fj_vd_mat ) ;
if ~isempty( Tj_u )
    [ temp , ~ ] = size( Tj_u ) ;
    if temp ~= nq
        Tj_u(nq,1) = 0;
    end
    Tj_u = sprse( Tj_u ) ;
end

% Adjustments
for i = 1 : numel( sprdmp )
    if ~par.sparse && numel( sprdmp(i).Tt ) ~= nq % fill all elements
        sprdmp(i).Tt(nq,1) = 0 ;
        sprdmp(i).vd_mat(1,nq) = 0 ;
        sprdmp(i).k_mat(1,nq) = 0 ;
        if ~isempty( sprdmp(i).Tt_u )
            sprdmp(i).Tt_u(nq,1) = 0 ;
        end
    end
end
for i = 1 : numel( cnst )
    if ~par.sparse && numel( cnst(i).T ) ~= nq % fill all elements
        cnst(i).T(1,nq) = 0 ;
        cnst(i).D(1,nq) = 0;
    end
    cnst(i).Tt = cnst(i).T.' ;
end

if ismember( par.derive_collect , [ 3 4 ] ) % for all constraints
    for i = 1 : n_cn
        Tcn = [ Tcn ; cnst(i).T ] ;
        Dcn = [ Dcn ; cnst(i).D ] ;
        Ccn = [ Ccn ; cnst(i).in ] ;
    end
    Tcu = Tcn.' ;
end

if par.plotIC > 0 % compare overall fit curves with init data
    figure
    for j_count = 1 : n_j
        for n_mesh = 1 : joint(j_count).n_mesh
            s_test = subs( subs( joint(j_count).rom.length(n_mesh,1), q, q0 ), par.sym,par.var ) : 1e-3 : ...
                subs( subs( joint(j_count).rom.length(n_mesh,2), q, q0 ), par.sym, par.var );
            pos_test = subs( subs( subs( subs( joint(j_count).TQ(n_mesh).loc(:,2), q, q0 ), par.sym, par.var ), sw, s), s, s_test );
            pos_spring_test = subs( subs( subs( subs( joint(j_count).spring.TQ(n_mesh).loc(:,2), q, q0 ), par.sym, par.var ), sw, s), s, s_test );
            Q_test = subs( subs( subs( subs( joint(j_count).TQ(n_mesh).loc(:,1), q, q0 ), par.sym, par.var ), sw, s), s, s_test );
            Q_spring_test = subs( subs( subs( subs( joint(j_count).spring.TQ(n_mesh).loc(:,1), q, q0 ), par.sym, par.var ), sw, s), s, s_test );
            subplot(1,2,1); plot3( pos_test(2,:), pos_test(3,:), pos_test(4,:) );
            hold on; axis equal
            subplot(1,2,1); plot3( pos_spring_test(2,:), pos_spring_test(3,:), pos_spring_test(4,:), '--' );
            hold on; axis equal; xlabel('x'); ylabel('y'); zlabel('z');
            subplot(1,2,2); plot(s_test, Q_test(1,:), '-', s_test, Q_spring_test(1,:), '--' );
            hold on; xlabel('x'); ylabel('Q_0');
        end
    end
    fprintf( 'Interpolation overall check! Press any key to continue... \n' )
    pause
end

if par.clean % clean up memory
    close all
    clearvars dof_m nq_mat dof_mult dof_mult_index
    joint = rmfield( joint , { 'tr' ; 'dof' ; 'n_mesh' ; 'mainkin' ; 'i_q' } ) ;
end

% Start with bodies and creat R|TR. To do so, check R|TR for the
% previous body and if not available creat R|TR for that till reaching
% ground. If the user provides a proper sequence of bodies the sequence of
% generalized coordinates numbers will rational starting frorm 1 for the
% nearest one to the ground
% SHOULD GIVE THE NEARED BODY TO GROUND FIRST
fprintf( 'Deriving inertial terms for body... \n' )
n_m = 0 ; % body type counter [ rigid , other ]
rom.mass = [] ; % reduced order model indicator
c_D = 1; if par.derive == 2; c_D = 0; end % linearize dynamics for small velocity assumption 
for b_count = 1 : n_b % number of bodies
    b_count
    
    for j_count = 1 : n_j % look into all joints
        
        if joint(j_count).second(1,1) == b_count % if the joint connects this body to another one,
            % 1st connecting joint is in the main kin. chain,
            % the rest are spring,damper, input, or constraints
            
            body(b_count).rom = [] ;
            body(b_count).n_mesh = numel( joint(j_count).first(1,:) ) - 1; % multiple body based on instances of main kin joint (not other joints)
            for n_mesh = 1 : body(b_count).n_mesh
                
                if isempty( joint(j_count).rom.order )
                    rom.mass = [ rom.mass; 0, 0 ] ;
                else % DON'T include int limits into system EOM so their q don't appear in diff
                    body(b_count).rom.l(n_mesh,:) = [ joint(j_count).rom.length(n_mesh,1) , joint(j_count).rom.length(n_mesh,2) ] ;
                    rom.mass = [ rom.mass ; body(b_count).rom.l(n_mesh,:) ] ;
                end
                
                if joint(j_count).first(1,1) == 0 || ... % the joint number where the new frame is connected to the firstbody
                        ( joint(j_count).first(1,n_mesh+1) == 0 && isempty( body(joint(j_count).first(1,1)).rom ) )
                    joint(j_count).Q(n_mesh).abs = joint(j_count).Q(n_mesh).loc ;
                    joint(j_count).TQ(n_mesh).abs = joint(j_count).TQ(n_mesh).loc ;
                else
                    if isempty( body(joint(j_count).first(1,1)).rom ) % not rom
                        Q = body(joint(j_count).first(1,1)).Q(joint(j_count).first(1,n_mesh+1)).abs ;
                        TQ = body(joint(j_count).first(1,1)).TQ(joint(j_count).first(1,n_mesh+1)).abs ;
                    else
                        Q = body(joint(j_count).first(1,1)).Q(joint(j_count).first(1,n_mesh+1)).abs ;
                        TQ = body(joint(j_count).first(1,1)).TQ(joint(j_count).first(1,n_mesh+1)).abs ;
                        if isnan( joint(j_count).first(2,n_mesh+1) ) % at tip
                            joint(j_count).first(2,n_mesh+1) = body(joint(j_count).first(1,1)).rom.l(joint(j_count).first(1,n_mesh+1),2);
                        end
                        Q = subs( Q , [s, sw] , joint(j_count).first(2,n_mesh+1) * [1, 1] ) ;
                        TQ = subs( TQ , [s, sw] , joint(j_count).first(2,n_mesh+1) * [1, 1] ) ;
                    end
                    if ~isempty( joint(j_count).rom.order ) && ~joint(j_count).rom.rel_base(n_mesh) % not rel: absolute base
                        joint(j_count).Q(n_mesh).abs = Q + joint(j_count).Q(n_mesh).loc ;
                        joint(j_count).TQ(n_mesh).abs = TQ + joint(j_count).TQ(n_mesh).loc ;
                        joint(j_count).Q(n_mesh).loc = joint(j_count).Q(n_mesh).abs ;
                        joint(j_count).TQ(n_mesh).loc = joint(j_count).TQ(n_mesh).abs ;
                    else
                        joint(j_count).Q(n_mesh).abs = Q_mult( Q , joint(j_count).Q(n_mesh).loc ) ;
                        joint(j_count).TQ(n_mesh).abs = TQ_mult( TQ , joint(j_count).TQ(n_mesh).loc ) ;
                    end
                end
                
                body(b_count).Q(n_mesh).loc = joint(j_count).Q(n_mesh).loc ;
                body(b_count).TQ(n_mesh).loc = joint(j_count).TQ(n_mesh).loc ;
                body(b_count).Q(n_mesh).abs = joint(j_count).Q(n_mesh).abs ;
                body(b_count).TQ(n_mesh).abs = joint(j_count).TQ(n_mesh).abs ;
                
                joint(j_count).r(n_mesh,:) = joint(j_count).TQ(n_mesh).abs(2:4,2).' ;
                if isempty( joint(j_count).rom.order ) % not a reduced order model
                    TQ_temp = TQ_mult( body(b_count).TQ(n_mesh).abs , [ 1 0 0 0 ; 0 body(b_count).tip(n_mesh,:) ].' ) ;
                    r_jtips = [ r_jtips ; joint(j_count).r(n_mesh,:) , TQ_temp(2:4,2).' , ...
                        joint(j_count).TQ(n_mesh).abs(1:4,1).' , TQ_temp(1:4,1).'] ; % each body joint and tip
                else
                    s1 = s * ( body(b_count).rom.l(n_mesh,2) - body(b_count).rom.l(n_mesh,1) ) + body(b_count).rom.l(n_mesh,1) ; % normalized curve length
                    r_jtips = [ r_jtips ; subs( joint(j_count).r(n_mesh,:) , [s, sw] , s1 * [1, 1] ) nan nan nan , ...
                        subs( joint(j_count).TQ(n_mesh).abs(1:4,1).' , [s, sw] , s1 * [1, 1] ) nan nan nan nan ] ;
                end
                
                n_m = n_m + 1 ;
                im = 6 * n_m ; % 6 elements for mass and inertia matrix
                mass(n_m).M(1:3,1:3) = smplfy( sym( body(b_count).m(n_mesh) * eye( 3 ) ) ) ;
                mass(n_m).M(4:6,4:6) = smplfy( sym( body(b_count).I(:,:,n_mesh) ) ) ;
                
                temp = myJacobian( body(b_count).Q(n_mesh).abs , q ) ;
                % temp4 = 2 * Q_mult( Q_conj( body(b_count).Q(n_mesh).abs ) , temp ) ; % omega_loc = 2 * Q^{-1} * Q_{,t}
                temp4 = Q_omega( body(b_count).Q(n_mesh).abs , temp ) ;
                body(b_count).omega(n_mesh).abs_loc = ( temp4(2:4,:) * u.' ).' ; % abs omega in local frame
                
                mass(n_m).T(4:6,:) = smplfy( temp4(2:4,:) ) ;
                mass(n_m).Dd(4:6,:) = c_D * smplfy( myJacobian( body(b_count).omega(n_mesh).abs_loc.' , q ) ) ;
                
                temp7 = TQ_mult( body(b_count).TQ(n_mesh).abs , [ 1 0 0 0 ; 0 body(b_count).l_com(n_mesh,:) ].' ) ;
                body(b_count).r_com(n_mesh,:) = temp7(2:4,2).';
                r_c = [ r_c ; body(b_count).r_com(n_mesh,:) ] ; % COM position for output
                temp8 = myJacobian ( temp7(2:4,2) , q );
                body(b_count).v_com(n_mesh,:) = ( temp8 * u.' ).';
                
                mass(n_m).T(1:3,:) = smplfy( temp8 ) ;
                mass(n_m).Dd(1:3,:) = c_D * smplfy( myJacobian ( body(b_count).v_com(n_mesh,:).' , q ) ) ;
                
                % gravity generalized work
                mass(n_m).fg = ( [ world.g 0 0 0 ].' ) ;
                
                if par.derive_collect == 5 % collect most terms
                    mass(n_m).TMT = mass(n_m).T.' * mass(n_m).M * mass(n_m).T * ( rom.mass(b_count,2) - rom.mass(b_count,1) ) ;
                    mass(n_m).TMfd = mass(n_m).T.' * mass(n_m).M * ( - mass(n_m).Dd * u.' + mass(n_m).fg ) * ( rom.mass(b_count,2) - rom.mass(b_count,1) ) ;
                end
                
                % sparse matrix
                mass(n_m).M = sprse( mass(n_m).M ) ;
                mass(n_m).T = sprse( mass(n_m).T ) ;
                mass(n_m).Dd = sprse( mass(n_m).Dd ) ;
                mass(n_m).fg = sprse( mass(n_m).fg ) ;                
                
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

if par.clean % clean up memory
    clearvars world
    body = rmfield( body , { 'm' , 'I' , 'l_com' , 'tip' , 'n_mesh' , 'omega' , 'r_com' , 'v_com' } ) ;
end


% spring/dampers/constraint
% look for the secondary joints that should be constraint or spring/dampers
fprintf( 'Deriving spring/damper/input dynamics for joints (according to which body they are connected to)... \n' )
w_sdi = sym( 0 ) ; % total virt. work
w_k = sym( 0 ) ; % spring virt. work
w_vd = sym( 0 ) ; % viscous dampers virt. work
w_vd_mat = sym( 0 ) ; % viscous dampers virt. work
w_in = sym( 0 ) ; % Coulomb dampers virt. work
w_k_mat = sym( 0 ) ; % spring stiffnes matrix for modal analysis
for b_count = 0 : n_b % number of bodies
    b_count
    
    for j_count = 1 : n_j % look into all joints, first one is the main kinematic path and rest are froce and spring and constraints
        
        if joint(j_count).second(1,1) == b_count && isempty( joint(j_count).rom.order ) && ~isempty( joint(j_count).tr2nd.trans ) % if the joint connects this body to another one
            j_count
            
            for n_mesh = 1 : max( [ numel( joint(j_count).first(1,:) ) , numel( joint(j_count).second(1,:) ) ] ) - 1
                
                if joint(j_count).first(1,1) == 0 || ... % the joint number where the new frame is connected to
                        ( joint(j_count).first(1,n_mesh+1) == 0 && isempty( body(joint(j_count).first(1,1)).rom ) )
                    joint(j_count).Q(n_mesh).abs = joint(j_count).Q(n_mesh).loc ;
                    joint(j_count).TQ(n_mesh).abs = joint(j_count).TQ(n_mesh).loc ;
                else
                    if isempty( body(joint(j_count).first(1,1)).rom )
                        Q = body(joint(j_count).first(1,1)).Q(joint(j_count).first(1,n_mesh+1)).abs ;
                        TQ = body(joint(j_count).first(1,1)).TQ(joint(j_count).first(1,n_mesh+1)).abs ;
                    else
                        % Q = body(joint(j_count).first(1,1)).Q(n_mesh+1).abs ;
                        % TQ = body(joint(j_count).first(1,1)).TQ(n_mesh+1).abs ;
                        Q = body(joint(j_count).first(1,1)).Q(joint(j_count).second(1,n_mesh+1)).abs ;
                        TQ = body(joint(j_count).first(1,1)).TQ(joint(j_count).second(1,n_mesh+1)).abs ;
                        if isnan( joint(j_count).first(2,n_mesh+1) ) % at tip
                            joint(j_count).first(2,n_mesh+1) = body(joint(j_count).first(1,1)).rom.l(joint(j_count).first(1,n_mesh+1),2);
                        end
                        Q = subs( Q , [s, sw] , joint(j_count).first(2,n_mesh+1) * [1, 1] ) ;
                        TQ = subs( TQ , [s, sw] , joint(j_count).first(2,n_mesh+1) * [1, 1] ) ;
                    end
                    if ~isempty( joint(j_count).rom.order ) && ~joint(j_count).rom.rel_base(n_mesh) % absolute base
                        joint(j_count).Q(n_mesh).abs = Q + joint(j_count).Q(n_mesh).loc ;
                        joint(j_count).TQ(n_mesh).abs = TQ + joint(j_count).TQ(n_mesh).loc ;
                        joint(j_count).Q(n_mesh).loc = joint(j_count).Q(n_mesh).abs ;
                        joint(j_count).TQ(n_mesh).loc = joint(j_count).TQ(n_mesh).abs ;
                    else
                        joint(j_count).Q(n_mesh).abs = Q_mult( Q , joint(j_count).Q(n_mesh).loc ) ;
                        joint(j_count).TQ(n_mesh).abs = TQ_mult( TQ , joint(j_count).TQ(n_mesh).loc ) ;
                    end
                end
                joint(j_count).r(n_mesh,:) = joint(j_count).TQ(n_mesh).abs(2:4,2).';
                
                if joint(j_count).second(1,1) == 0 || ... % the joint number where the new frame is connected to the second body
                        ( joint(j_count).second(1,n_mesh+1) == 0 && isempty( body(joint(j_count).second(1,1)).rom ) )
                    joint(j_count).Q2nd(n_mesh).abs = joint(j_count).Q2nd(n_mesh).loc ;
                    joint(j_count).TQ2nd(n_mesh).abs = joint(j_count).TQ2nd(n_mesh).loc ;
                else
                    if isempty( body(joint(j_count).second(1,1)).rom )
                        Q = body(joint(j_count).second(1,1)).Q(joint(j_count).second(1,n_mesh+1)).abs ;
                        TQ = body(joint(j_count).second(1,1)).TQ(joint(j_count).second(1,n_mesh+1)).abs ;
                    else
                        Q = body(joint(j_count).second(1,1)).Q(1,joint(j_count).second(1,n_mesh+1)).abs ;
                        TQ = body(joint(j_count).second(1,1)).TQ(1,joint(j_count).second(1,n_mesh+1)).abs ;
                        if isnan( joint(j_count).second(2,n_mesh+1) ) % at tip
                            joint(j_count).second(2,n_mesh+1) = body(joint(j_count).second(1,1)).rom.l(joint(j_count).second(1,n_mesh+1),2);
                        end
                        Q = subs( Q , [s, sw] , joint(j_count).second(2,n_mesh+1) * [1, 1] ) ;
                        TQ = subs( TQ , [s, sw] , joint(j_count).second(2,n_mesh+1) * [1, 1] ) ;
                    end
                    joint(j_count).Q2nd(n_mesh).abs = Q_mult( Q , joint(j_count).Q2nd(n_mesh).loc ) ;
                    joint(j_count).TQ2nd(n_mesh).abs = TQ_mult( TQ , joint(j_count).TQ2nd(n_mesh).loc ) ;
                end                
                
                % spring/damper/input:                
                n_sd = n_sd + 1 ;
                r_ks = [ r_ks ; joint(j_count).TQ(n_mesh).abs(2:4,2).' , joint(j_count).TQ2nd(n_mesh).abs(2:4,2).' , ...
                    joint(j_count).TQ(n_mesh).abs(1:4,1).' , joint(j_count).TQ2nd(n_mesh).abs(1:4,1).' ] ; % each body joint and tip
                r_sd = joint(j_count).TQ2nd(n_mesh).abs(2:4,2) - joint(j_count).TQ(n_mesh).abs(2:4,2) ; % TQ2nd - TQ: subtracting order should match direction of q0, otherwise does not matter
                % if q0 = 0 -> any order results in two actions: f2nd(r2nd-r) & f(r-r2nd)
                % dr_sd = myJacobian( r_sd , qf ) * uf.' ;
                
                % constraints
                i_free = [] ; % free directions in (to be removed from) sprdmp
                if ~isempty( joint(j_count).fixed )
                    
                    % constrain vector
                    if joint(j_count).refbody(n_mesh,1) ~= 0 % contraint wrt refbody frame
                        if isempty( body(joint(j_count).refbody(n_mesh,1)).rom ) % rigid link
                            Q_ref = body(joint(j_count).refbody(n_mesh,1)).Q(joint(j_count).refbody(n_mesh,2)).abs ;
                        else % rom
                            Q_ref = body(joint(j_count).refbody(n_mesh,1)).Q(joint(j_count).refbody(n_mesh,2)).abs ;
                            if isnan( joint(j_count).refbody(n_mesh,3) ) % at tip
                                joint(j_count).refbody(n_mesh,3) = body(joint(j_count).refbody(n_mesh,1)).rom.l(joint(j_count).refbody(n_mesh,2),2);
                            end
                            Q_ref = subs( Q_ref , [s, sw] , joint(j_count).refbody(n_mesh,3) * [1, 1] ) ;
                        end
                        temp = Q_rot( Q_conj( Q_ref ) , [ 0 ; r_sd ] ) ; % transforming to refbody frame
                        r_sd_r = temp(2:4) ;
                    else
                        r_sd_r = r_sd ;
                    end
                    
                    if numel( joint(j_count).fixed(n_mesh,:) ) < 7 % 6 trans. & rot. spring/dampers
                        % Q_sd = 2 * Q_mult( Q_conj( joint(j_count).TQ(n_mesh).abs(:,1) ) , joint(j_count).TQ2nd(n_mesh).abs(:,1) - joint(j_count).TQ(n_mesh).abs(:,1) ) ;
                        Q_sd = Q_omega( joint(j_count).TQ(n_mesh).abs(:,1) , joint(j_count).TQ2nd(n_mesh).abs(:,1) - joint(j_count).TQ(n_mesh).abs(:,1) ) ;
                        rQ_sd = [ r_sd_r ; Q_sd(2:4,1) ] ;
                    else % 7 trans. & quat rot.
                        Q_sd = joint(j_count).TQ2nd(n_mesh).abs(:,1) - joint(j_count).TQ(n_mesh).abs(:,1) ;
                        rQ_sd = [ r_sd_r ; Q_sd(:,1) ] ;
                    end
                    
                    temp = myJacobian( rQ_sd , q ).' ;
                    rcn = [ rcn ; r_sd_r.' ] ;
                    
                    for i_c = 1 : numel( joint(j_count).fixed(n_mesh,:) )
                        if joint(j_count).fixed(n_mesh,i_c) == 1 ... % constraint
                                || isinf( joint(j_count).fixed(n_mesh,i_c) ) % desired or known
                            n_cn = n_cn + 1 ;
                            
                            cnst(n_cn).r = smplfy( rQ_sd(i_c) ) ; % constraint relation
                            cnst(n_cn).T = smplfy( temp(:,i_c).' ) ; % use T.' in dynamics EOM and T in algebraic part
                            vcn = smplfy( cnst(n_cn).T * u.' ) ;
                            cnst(n_cn).D = smplfy( myJacobian( vcn , q ) ) ;
                            cnst(n_cn).in = smplfy( joint(j_count).control(n_mesh,i_c) ) ;
                            
                            if isinf( joint(j_count).fixed(n_mesh,i_c) ) % desired or known
                                cnst(n_cn).Tt = [] ;
                            else
                                cnst(n_cn).Tt = cnst(n_cn).T.';
                                % lambdaf = [ lambdaf, lambda_vpa(n_cn) ] ;
                                lambda = [ lambda, sym( [ 'lambda' num2str( n_cn ) ] , 'real' ) ] ;
                                dlambda = [ dlambda, sym( [ 'dlambda' num2str( n_cn ) ] , 'real' ) ] ;
                            end
                            
                            if par.derive_collect == 5 % collect most terms
                                cnst(n_cn).dc = - cnst(n_cn).Dc * u.' + cnst(n_cn).in;
                            end
                            
                            % sparse
                            cnst(n_cn).r = sprse( cnst(n_cn).r ) ;
                            cnst(n_cn).T = sprse( cnst(n_cn).T ) ;
                            cnst(n_cn).D = sprse( cnst(n_cn).D ) ;
                            % cnst(n_cn).in = smplfy( cnst(n_cn).in ) ;
                            
                            if ismember( par.derive_collect , [ 3 4 ] ) % for all constraints
                                Tcn = [ Tcn ; cnst(n_cn).T ] ;
                                Tcu = [ Tcu , cnst(n_cn).T.' ] ;
                                Dcn = [ Dcn ; cnst(n_cn).D ] ;
                                Ccn = [ Ccn ; cnst(n_cn).in ] ;
                            end
                        else
                            i_free = [ i_free , i_c ] ; % to be removed from sprdmp
                        end
                    end
                end
                
                % simple spring
                if numel( joint(j_count).spring.coeff(n_mesh,:) ) == 1 % simple spring
                    
                    l_sd0 = joint(j_count).spring.init(n_mesh,1) ;
                    if isnan( joint(j_count).spring.init(n_mesh,1) ) % init. l based on q0 and compression ratio
                        r_sd0 = subs( r_sd , q , q0 ).' ; % 1x3
                        l_sd0_q0 = sqrt( r_sd0 * r_sd0.' ) ; % based on int. config.
                        l_sd0 = [] ;
                        l_sd0 = l_sd0_q0 ;
                    end
                    l_sd0 = joint(j_count).spring.compr(n_mesh,1) * l_sd0 ;
                    
                    temp = smplfy( myJacobian( r_sd , q ) ) ;
                    temp_u = temp * u.' ;
                    sprdmp(n_sd).Tt = smplfy( temp.' ) ; % virtual displacement
                    sprdmp(n_sd).kx = smplfy( ... % all spring/damper force virtual work
                        ( - joint(j_count).spring.coeff(n_mesh,1) * ...
                        r_sd * ( 1 - l_sd0 / sqrt( r_sd.' * r_sd ) ) ) ) ; % instantanious spring force vector
                    sprdmp(n_sd).dl = smplfy( sqrt( r_sd.' * r_sd ) - l_sd0 ) ; % spring delta_l
                    sprdmp(n_sd).vd = smplfy( ... % viscous damping force virtual work
                        - joint(j_count).damp.visc(n_mesh).' ...
                        .* temp_u ) ; % instantanious viscous force matrix
                    if joint(j_count).damp.pow(n_mesh,1) ~= 1 % speedup trick
                        sprdmp(n_sd).vd = sprdmp(n_sd).vd .* ( abs( temp_u ).^( joint(j_count).damp.pow(n_mesh,1) - 1 ) ) ;
                    end
                    sprdmp(n_sd).in = smplfy( ... % input force virtual work
                        joint(j_count).input(n_mesh) * ones(3,1) ) ; % instantanious input value
                    sprdmp(n_sd).k_mat = 0 ;
                    % smplfy( joint(j_count).spring.coeff(n_mesh,1) * ... % for modal analysis if k is linear w.r.t. states
                    %     temp ) ;
                    sprdmp(n_sd).vd_mat = 0 ;
                    % smplfy( ... % viscous damping force virtual work
                    %     - joint(j_count).damp.visc(n_mesh).' ...
                    %     .* temp ) ; % instantanious viscous force matrix
                    % if joint(j_count).damp.pow(n_mesh,1) ~= 1 % speedup trick
                    %     sprdmp(n_sd).vd_mat = sprdmp(n_sd).vd_mat .* ( abs( temp_u ).^( joint(j_count).damp.pow(n_mesh,1) - 1 ) ) ;
                    % end
                    
                    % if input is considered part of the inverse controller
                    if isinf( joint(j_count).input(n_mesh) )
                        sprdmp(n_sd).in = sprse( zeros(3,1) ) ;
                        n_co = n_co + 1 ;
                        gamma = [ gamma, sym( [ 'gamma' num2str( n_co ) ] , 'real' ) ] ;
                        dgamma = [ dgamma, sym( [ 'dgamma' num2str( n_co ) ] , 'real' ) ] ;
                        sprdmp(n_sd).Tt_u = sprdmp(n_sd).Tt * ones(3,1) ;
                    end
                    
                % beam trans. & rot. or constraint
                else % 6 elements for beam trans. & rot. or constraint
                    
                    r_sd0 = subs( r_sd , q , q0 ).' ; % 1x3
                    l_sd0_q0 = sqrt( r_sd0 * r_sd0.' ) ; % based on int. config.
                    temp = Q_rot( Q_conj( joint(j_count).TQ(n_mesh).abs(:,1) ) , [ 0 ; r_sd0.' ] ) ; % r_{loc} = Q^{-1} * r_{abs} * Q
                    r_sd_r = Q_rot( Q_conj( joint(j_count).TQ(n_mesh).abs(:,1) ) , [ 0 ; r_sd ] ) ; % r_{loc} = Q^{-1} * r_{abs} * Q
                    
                    if ~isempty( joint(j_count).xaxis ) % rotate to beam frame
                        r_sd0_r = temp(2:4,1).' ; % 1x3 in local frame
                        yaxis =  cross( r_sd0_r , joint(j_count).xaxis(n_mesh,:) ) ; % 1x3 beam frame axis w.r.t. local frame
                        xaxis = cross( yaxis , r_sd0_r ) ;
                        R_b = [ xaxis/sqrt( xaxis * xaxis.' ) ;
                            yaxis/sqrt( yaxis * yaxis.' ) ;
                            r_sd0_r/l_sd0_q0 ] ;
                        r_sd_rb = R_b.' * r_sd_r(2:4,1) ; % 3x1 transformed to beam frame
                        Q_rb = R2Q( R_b ) ; % beam frame relative to local frame
                        Q_b = Q_mult( Q_conj( Q_rb ) , joint(j_count).TQ(n_mesh).abs(:,1) ) ;
                    else
                        r_sd_rb = r_sd_r(2:4,1) ; % 3x1 already in beam frame
                        Q_b = joint(j_count).TQ(n_mesh).abs(:,1) ;
                    end
                    % Q_sd_r = 2 * Q_mult( Q_conj( Q_b ) , joint(j_count).TQ2nd(n_mesh).abs(:,1) - Q_b ) ;
                    Q_sd_r = Q_omega( Q_b , joint(j_count).TQ2nd(n_mesh).abs(:,1) - Q_b ) ;
                    rQ_sd = [ r_sd_rb ; Q_sd_r(2:4,1) ] ; % 6 trans. & rot. spring/dampers
                    
                    rQ_sd0 = joint(j_count).spring.init(n_mesh,1:6) ;
                    for i_s = 1 : numel( rQ_sd0 )
                        if isnan( rQ_sd0(i_s) )
                            rQ_sd0 = sym( rQ_sd0 ) ;
                            rQ_sd0(i_s) = subs( rQ_sd(i_s) , q , q0 ) ;
                            % if i_s == 3 % init. l based on q0 and compression ratio
                            %     rQ_sd0(i_s) = l_sd0_q0 ;
                            % end
                        end
                    end
                    rQ_sd0 = rQ_sd0 .* joint(j_count).spring.compr(n_mesh,:) ;
                    
                    temp = smplfy( myJacobian( rQ_sd , q ) ) ;
                    temp_u = temp * u.' ;
                    sprdmp(n_sd).Tt = smplfy( temp.' ) ; % virtual displacement
                    sprdmp(n_sd).kx = smplfy( ... % all spring/damper force virtual work
                        - ( joint(j_count).spring.coeff(n_mesh,:).' ) ...
                        .* ( rQ_sd - rQ_sd0.' ) ) ; % instantanious spring force vector
                    sprdmp(n_sd).dl = smplfy( sqrt( r_sd.' * r_sd ) - rQ_sd0(3) ) ; % spring delta-l
                    sprdmp(n_sd).vd = smplfy( ... % viscous damping force virtual work
                        - ( joint(j_count).damp.visc(n_mesh,:).' ) ...
                        .* temp_u ) ; % instantanious viscous force matrix
                    if joint(j_count).damp.pow(n_mesh,1) ~= 1 % speedup trick
                        sprdmp(n_sd).vd = sprdmp(n_sd).vd .* ( abs( temp_u ).^( joint(j_count).damp.pow(n_mesh,1) - 1 ) ) ;
                    end
                    sprdmp(n_sd).in = smplfy( ... % input force virtual work
                        joint(j_count).input(n_mesh,:).' ) ; % instantanious input value
                    sprdmp(n_sd).k_mat = 0 ;
                    % smplfy( ( joint(j_count).spring.coeff(n_mesh,:).' ) ... % for modal analysis if k is linear w.r.t. states
                    %     .* temp ) ;
                    sprdmp(n_sd).vd_mat = 0 ;
                    % smplfy( ... % viscous damping force virtual work
                    %     - ( joint(j_count).damp.visc(n_mesh,:).' ) ...
                    %     .* temp ) ; % instantanious viscous force matrix
                    % if joint(j_count).damp.pow(n_mesh,1) ~= 1 % speedup trick
                    %     sprdmp(n_sd).vd_mat = sprdmp(n_sd).vd_mat .* ( abs( temp_u ).^( joint(j_count).damp.pow(n_mesh,1) - 1 ) ) ;
                    % end
                    
                    % if input is considered part of the inverse controller
                    for i_in = 1 : numel( joint(j_count).input(n_mesh,:) )
                        if isinf( joint(j_count).input(n_mesh,i_in) )
                            sprdmp(n_sd).in(i_in,1) = 0 ;
                            n_co = n_co + 1 ;
                            gamma = [ gamma, sym( [ 'gamma' num2str( n_co ) ] , 'real' ) ] ;
                            dgamma = [ dgamma, sym( [ 'dgamma' num2str( n_co ) ] , 'real' ) ] ;
                            sprdmp(n_sd).Tt_u = [ sprdmp(n_sd).Tt_u, sprdmp(n_sd).Tt(:,i_in) ] ;
                        end
                    end
                    
                    % % remove free directions (not needed as we can set k & nu = 0)
                    % sprdmp(n_sd).Tt(:,i_free) = [] ;
                    % sprdmp(n_sd).kx(i_free,:) = [] ;
                    % sprdmp(n_sd).vd(i_free,:) = [] ;
                    % sprdmp(n_sd).in(i_free,:) = [] ;
                    % sprdmp(n_sd).k_mat(i_free,:) = [] ;
                    % sprdmp(n_sd).vd_mat(i_free,:) = [] ;
                end
                
                rom.sprdmp = [ rom.sprdmp; 0, 0 ] ;
                switch joint(j_count).dir(n_mesh)
                    case 1 % compression-only elements, e.g. soft contact
                        sprdmp(n_sd).dir = smplfy( sign( sprdmp(n_sd).dl ) + 1 ) / 2 ;
                    case 0 % both dir.ss, e.g. regular spring/damper
                        sprdmp(n_sd).dir = 1 ;
                    case -1 % tension-only elements, e.g. wire
                        sprdmp(n_sd).dir = smplfy( - sign( sprdmp(n_sd).dl ) + 1 ) / 2 ;
                end
                
                if par.derive_collect == 5 % collect most terms                
                    sprdmp(n_sd).w_vd_j = sprdmp(n_sd).dir * sprdmp(n_sd).Tt * sprdmp(n_sd).vd * ( rom.sprdmp(end,2) - rom.sprdmp(end,1) ) ;
                    sprdmp(n_sd).w_sd = sprdmp(n_sd).dir * sprdmp(n_sd).Tt * sprdmp(n_sd).kx * ( rom.sprdmp(end,2) - rom.sprdmp(end,1) ) ;
                    sprdmp(n_sd).w_in = sprdmp(n_sd).dir * sprdmp(n_sd).Tt * sprdmp(n_sd).in * ( rom.sprdmp(end,2) - rom.sprdmp(end,1) ) ;
                    sprdmp(n_sd).Tt_u = sprdmp(n_sd).Tt_u * ( rom.sprdmp(end,2) - rom.sprdmp(end,1) ) ;
                end
                
                % sparse matrix
                sprdmp(n_sd).Tt = sprse( sprdmp(n_sd).Tt ) ;
                sprdmp(n_sd).kx = sprse( sprdmp(n_sd).kx ) ;
                sprdmp(n_sd).dl = sprse( sprdmp(n_sd).dl ) ;
                sprdmp(n_sd).vd = sprse( sprdmp(n_sd).vd ) ;
                sprdmp(n_sd).in = sprse( sprdmp(n_sd).in ) ;
                sprdmp(n_sd).k_mat = sprse( sprdmp(n_sd).k_mat ) ;
                sprdmp(n_sd).vd_mat = sprse( sprdmp(n_sd).vd_mat ) ;
                if ~isempty( sprdmp(n_sd).Tt_u )
                    sprdmp(n_sd).Tt_u = sprse( sprdmp(n_sd).Tt_u ) ;
                end
                
                if ismember( par.derive_collect , [ 3 4 ] ) % for all spring/dampers
                    w_k = w_k + sprdmp(n_sd).dir * sprdmp(n_sd).Tt * sprdmp(n_sd).kx ;
                    w_vd = w_vd + sprdmp(n_sd).dir * sprdmp(n_sd).Tt * sprdmp(n_sd).vd ;
                    w_in = w_in + sprdmp(n_sd).dir * sprdmp(n_sd).Tt * sprdmp(n_sd).in ;
                    w_sdi = w_sdi + sprdmp(n_sd).dir * sprdmp(n_sd).Tt * ( ...
                        sprdmp(n_sd).kx + sprdmp(n_sd).vd + sprdmp(n_sd).in ) ; % all spring/damper/input force virtual work
                    w_k_mat = w_k_mat + sprdmp(n_sd).Tt * sprdmp(n_sd).k_mat ;
                    w_vd_mat = w_vd_mat + sprdmp(n_sd).Tt * sprdmp(n_sd).vd_mat ;
                    Tcu = [ Tcu , sprdmp(n_sd).Tt_u ] ;
                end
            end
        end
        
        % rom
        if joint(j_count).second(1,1) == b_count && ~isempty( joint(j_count).rom.order ) % if the joint is reduced order model
            j_count            
            
            for n_mesh = 1 : max( [ numel( joint(j_count).first(1,:) ) , numel( joint(j_count).second(1,:) ) ] ) - 1
                
                r_sd = joint(j_count).TQ(n_mesh).loc(:,2) ;
                n_sd = n_sd + 1 ;
                dr_sd = diff( r_sd , s ) ;
                dQ_sd = diff( joint(j_count).TQ(n_mesh).loc(:,1) , s ) ;
                % uQ_sd = 2 * Q_mult( Q_conj( joint(j_count).TQ(n_mesh).loc(:,1) ) , dQ_sd ) ;
                uQ_sd = Q_omega( joint(j_count).TQ(n_mesh).loc(:,1) , dQ_sd ) ; % same as 2*Q_conj*dQ but less computation
                vr_sd = Q_rot( Q_conj( joint(j_count).TQ(n_mesh).loc(:,1) ) , dr_sd ) ; % transfer to local frame in which K is defined
                rQ_sd = [ vr_sd(2:4,1) ; uQ_sd(2:4,1) ] ; % [ v u ]: 6 trans. & rot. spring/dampers
                
                % for spring IC
                if max( isnan( joint(j_count).spring.init(n_mesh,1:6) ) )
                    r_sd_spr = joint(j_count).spring.TQ(n_mesh).loc(:,2) ;
                    dr_sd_spr = diff( r_sd_spr , s ) ;
                    dQ_sd_spr = diff( joint(j_count).spring.TQ(n_mesh).loc(:,1) , s ) ;
                    % uQ_sd_spr = 2 * Q_mult( Q_conj( joint(j_count).spring.TQ(n_mesh).loc(:,1) ) , dQ_sd_spr ) ;
                    uQ_sd_spr = Q_omega( joint(j_count).spring.TQ(n_mesh).loc(:,1) , dQ_sd_spr ) ;
                    vr_sd_spr = Q_rot( Q_conj( joint(j_count).spring.TQ(n_mesh).loc(:,1) ) , dr_sd_spr ) ;
                    rQ_sd_spr = [ vr_sd_spr(2:4,1) ; uQ_sd_spr(2:4,1) ] ; % [ v u ]: 6 trans. & rot. spring/dampers
                end
                
                % no n_mesh for spring.init & spring.init_s at the moment
                rQ_sd0 = joint(j_count).spring.init(n_mesh,1:6) ;
                for i_s = 1 : numel( rQ_sd0 )
                    if isnan( rQ_sd0(i_s) )
                        rQ_sd0 = sym( rQ_sd0 ) ;
                        rQ_sd0(i_s) = rQ_sd_spr(i_s) ;
                    end
                end
                rQ_sd0 = rQ_sd0 .* joint(j_count).spring.compr(n_mesh,:) ;
                
                rom.sprdmp = [ rom.sprdmp ; joint(j_count).rom.length(n_mesh,1) , joint(j_count).rom.length(n_mesh,2) ] ;
                
                temp = smplfy( myJacobian( rQ_sd , q ) ) ;
                temp_u = smplfy( temp * u.' ) ;
                sprdmp(n_sd).Tt = smplfy( temp.' ) ; % virtual displacement
                sprdmp(n_sd).kx = smplfy( ... % all spring/damper force virtual work
                    - ( joint(j_count).spring.coeff(n_mesh,:).' ) ...
                    .* ( rQ_sd - rQ_sd0.' ) ) ; % instantanious spring force vector
                sprdmp(n_sd).dl = smplfy( dr_sd(2:4).' ) ; % spring delta-l
                sprdmp(n_sd).vd = smplfy( ... % viscous damping force virtual work
                    - ( joint(j_count).damp.visc(n_mesh,:).' ) ...
                    .* temp_u ) ; % instantanious viscous force matrix
                if joint(j_count).damp.pow(n_mesh,1) ~= 1 % speedup trick
                    sprdmp(n_sd).vd = sprdmp(n_sd).vd .* ( abs( temp_u ).^( joint(j_count).damp.pow(n_mesh,1) - 1 ) ) ;
                end
                sprdmp(n_sd).in = smplfy( ... % input force virtual work
                    joint(j_count).input(n_mesh,:).' ) ; % instantanious input value
                sprdmp(n_sd).k_mat = 0 ;
                sprdmp(n_sd).vd_mat = 0 ;
                
                % if input is considered part of the inverse controller
                for i_in = 1 : numel( joint(j_count).input(n_mesh,:) )
                    if isinf( joint(j_count).input(n_mesh,i_in) )
                        sprdmp(n_sd).in(i_in,1) = 0 ;
                        n_co = n_co + 1 ;
                        gamma = [ gamma, sym( [ 'gamma' num2str( n_co ) ] , 'real' ) ] ;
                        dgamma = [ dgamma, sym( [ 'dgamma' num2str( n_co ) ] , 'real' ) ] ;
                        sprdmp(n_sd).Tt_u = [ sprdmp(n_sd).Tt_u, sprdmp(n_sd).Tt(:,i_in) ] ;
                    end
                end
                    
                switch joint(j_count).dir(n_mesh)
                    case 1 % compression-only elements, e.g. soft contact
                        sprdmp(n_sd).dir = smplfy( sign( sprdmp(n_sd).dl ) + 1 ) / 2 ;
                    case 0 % both dir.ss, e.g. regular spring/damper
                        sprdmp(n_sd).dir = 1 ;
                    case -1 % tension-only elements, e.g. wire
                        sprdmp(n_sd).dir = smplfy( - sign( sprdmp(n_sd).dl ) + 1 ) / 2 ;
                end                
                
                if par.derive_collect == 5 % collect most terms
                    sprdmp(n_sd).w_vd_j = sprdmp(n_sd).dir * sprdmp(n_sd).Tt * sprdmp(n_sd).vd * ( rom.sprdmp(end,2) - rom.sprdmp(end,1) ) ;
                    sprdmp(n_sd).w_sd = sprdmp(n_sd).dir * sprdmp(n_sd).Tt * sprdmp(n_sd).kx * ( rom.sprdmp(end,2) - rom.sprdmp(end,1) ) ;
                    sprdmp(n_sd).w_in = sprdmp(n_sd).dir * sprdmp(n_sd).Tt * sprdmp(n_sd).in * ( rom.sprdmp(end,2) - rom.sprdmp(end,1) ) ;
                    sprdmp(n_sd).Tt_u = sprdmp(n_sd).Tt_u * ( rom.sprdmp(end,2) - rom.sprdmp(end,1) ) ;
                end
                
                % sparse matrix
                sprdmp(n_sd).Tt = sprse( sprdmp(n_sd).Tt ) ;
                sprdmp(n_sd).kx = sprse( sprdmp(n_sd).kx ) ;
                sprdmp(n_sd).dl = sprse( sprdmp(n_sd).dl ) ;
                sprdmp(n_sd).vd = sprse( sprdmp(n_sd).vd ) ;
                sprdmp(n_sd).in = sprse( sprdmp(n_sd).in ) ;
                sprdmp(n_sd).k_mat = sprse( sprdmp(n_sd).k_mat ) ;
                sprdmp(n_sd).vd_mat = sprse( sprdmp(n_sd).vd_mat ) ;
                if ~isempty( sprdmp(n_sd).Tt_u )
                    sprdmp(n_sd).Tt_u = sprse( sprdmp(n_sd).Tt_u ) ;
                end
                
                if ismember( par.derive_collect , [ 3 4 ] ) % for all spring/dampers
                    w_k = w_k + sprdmp(n_sd).dir * sprdmp(n_sd).Tt * sprdmp(n_sd).kx ;
                    w_vd = w_vd + sprdmp(n_sd).dir * sprdmp(n_sd).Tt * sprdmp(n_sd).vd ;
                    w_in = w_in + sprdmp(n_sd).dir * sprdmp(n_sd).Tt * sprdmp(n_sd).in ;
                    w_sdi = w_sdi + sprdmp(n_sd).dir * sprdmp(n_sd).Tt * ( ...
                        sprdmp(n_sd).kx + sprdmp(n_sd).vd + sprdmp(n_sd).in ) ; % all spring/damper/input force virtual work
                    w_k_mat = w_k_mat + sprdmp(n_sd).Tt * sprdmp(n_sd).k_mat ;
                    w_vd_mat = w_vd_mat + sprdmp(n_sd).Tt * sprdmp(n_sd).vd_mat ;
                    Tcu = [ Tcu , sprdmp(n_sd).Tt_u ] ;
                end                
                
            end
        end
    end
end
nlambda = numel( lambda ) ;
ngamma = numel( gamma ) ;

if par.clean % clean up memory
    clearvars joint ;
end


% handle external forces
% linear force for now
fprintf( 'Deriving external load dynamics... \n' )
Ttef = sym( [] ) ;
ftau_ef = sym( [] ) ;
for i_exload = 1 : n_ex
    if isempty( exload(i_exload).exbody )
        n_ex = n_ex - 1 ;
        continue ;
    end
    i_exload
    
    for n_mesh = 1 : numel( exload(i_exload).exbody(1,:) ) - 1
        
        exload(i_exload).Q(n_mesh).loc = sym( [ 1 0 0 0 ].' );
        exload(i_exload).TQ(n_mesh).loc = sym( [ 1 0 0 0 ; 0 0 0 0 ].' );
        
        [ ~ , nj_tr ] = size( exload(i_exload).tr ) ; % number of transforamtions in a joint
        for i3 = 1 : nj_tr
            [ Q_temp , TQ_temp ] = TQ_mat( [ exload(i_exload).tr(i3).trans , exload(i_exload).tr(i3).rot ] , [ q s ] , exload(i_exload).tr(i3).rot_type );
            exload(i_exload).Q(n_mesh).loc = Q_mult( exload(i_exload).Q(n_mesh).loc , Q_temp ) ;
            exload(i_exload).TQ(n_mesh).loc = TQ_mult( exload(i_exload).TQ(n_mesh).loc , TQ_temp ) ;
        end
        
        if isempty( body(exload(i_exload).exbody(1,1)).rom ) % not rom
            Q = body(exload(i_exload).exbody(1,1)).Q(exload(i_exload).exbody(1,n_mesh+1)).abs ;
            TQ = body(exload(i_exload).exbody(1,1)).TQ(exload(i_exload).exbody(1,n_mesh+1)).abs ;
        else
            Q = body(exload(i_exload).exbody(1,1)).Q(exload(i_exload).exbody(1,n_mesh+1)).abs ;
            TQ = body(exload(i_exload).exbody(1,1)).TQ(exload(i_exload).exbody(1,n_mesh+1)).abs ;
            if isnan( exload(i_exload).exbody(2,n_mesh+1) ) % at tip
                exload(i_exload).exbody(2,n_mesh+1) = body(exload(i_exload).exbody(1,1)).rom.l(exload(i_exload).exbody(1,n_mesh+1),2);
            end
            Q = subs( Q , [s, sw] , exload(i_exload).exbody(2,n_mesh+1) * [1, 1] ) ;
            TQ = subs( TQ , [s, sw] , exload(i_exload).exbody(2,n_mesh+1) * [1, 1] ) ;
        end
        exload(i_exload).Q(n_mesh).abs = Q_mult( Q , exload(i_exload).Q(n_mesh).loc ) ;
        exload(i_exload).TQ(n_mesh).abs = TQ_mult( TQ , exload(i_exload).TQ(n_mesh).loc ) ;
        
        % both load and action vector should be in same frame
        ref(i_exload,:) = exload(i_exload).TQ(n_mesh).abs(2:4,2).';
        r_ex = exload(i_exload).TQ(n_mesh).abs(2:4,2) ; % exerting point vector in ref. frame
        loads(i_exload).Tt(:,1:3) = smplfy( myJacobian( exload(i_exload).TQ(n_mesh).abs(2:4,2) , q ).' ) ; % in ref. frame
        temp = myJacobian( exload(i_exload).Q(n_mesh).abs , q ) ;
        % temp = 2 * Q_mult( Q_conj( exload(i_exload).Q(n_mesh).abs ) , temp ) ; % in exbody. frame: omega_abs = 2 * Q^{-1} * Q_{,t}
        temp = Q_omega( exload(i_exload).Q(n_mesh).abs , temp ) ;
        loads(i_exload).Tt(:,4:6) = smplfy( temp(2:4,:).' ) ; % in exbody frame
        
        % transfer f to ref. frame and tau to exbody. frame
        % default: in ref. frame
        f_reff = [ 0 exload(i_exload).ftau(n_mesh,1:3) ].' ; % f in ref. frame
        tau_reff = [ 0 exload(i_exload).ftau(n_mesh,4:6) ].' ; % tau in ref. frame
        if exload(i_exload).refbody(n_mesh,1) ~= 0 % ftau in refbody frame
            if isempty( body(exload(i_exload).refbody(n_mesh,1)).rom ) % rigid link
                Q_ref = body(exload(i_exload).refbody(n_mesh,1)).Q(exload(i_exload).refbody(n_mesh,2)).abs ;
            else % rom
                Q_ref = body(exload(i_exload).refbody(n_mesh,1)).Q(exload(i_exload).refbody(n_mesh,2)).abs ;
                if isnan( exload(i_exload).refbody(n_mesh,3) ) % at tip
                    exload(i_exload).refbody(n_mesh,3) = body(exload(i_exload).refbody(n_mesh,1)).rom.l(exload(i_exload).refbody(n_mesh,2),2);
                end
                Q_ref = subs( Q_ref , [s, sw] , exload(i_exload).refbody(n_mesh,3) * [1, 1] ) ;
            end
            f_reff = Q_rot( Q_conj( Q_ref ) , f_reff ) ; % f in ref. frame
            tau_reff = Q_rot( Q_conj( Q_ref ) , tau_reff ) ; % tau in ref. frame
        end
        tau_exbf = Q_rot( Q_conj( exload(i_exload).Q(n_mesh).abs ) , tau_reff ) ; % tau in exbody. frame
        loads(i_exload).ftau = smplfy( [ f_reff(2:4,1) ; tau_exbf(2:4,1) ] ) ;
        
        % if ftau is considered part of the observer
        for i_ftau = 1 : numel( loads(i_exload).ftau )
            if isinf( loads(i_exload).ftau(i_ftau,1) )
                loads(i_exload).ftau(i_ftau,1) = 0 ;
                n_co = n_co + 1 ;
                gamma = [ gamma, sym( [ 'gamma' num2str( n_co ) ] , 'real' ) ] ;
                dgamma = [ dgamma, sym( [ 'dgamma' num2str( n_co ) ] , 'real' ) ] ;
                loads(i_exload).Tt_o = [ loads(i_exload).Tt_o, loads(i_exload).Tt(:,i_ftau) ] ;
            end
        end
        
        if par.derive_collect == 5 % collect most terms
            loads(i_exload).w_f = loads(i_exload).Tt * loads(i_exload).ftau ;
        end
        
        % sparse matrix
        loads(i_exload).Tt = sprse( loads(i_exload).Tt ) ;
        loads(i_exload).ftau = sprse( loads(i_exload).ftau ) ;
        loads(i_exload).Tt_o = sprse( loads(i_exload).Tt_o ) ;
        
        if ismember( par.derive_collect , [ 3 4 ] )  % for all ex. forces
            Ttef = [ Ttef loads(i_exload).Tt ] ;
            ftau_ef = [ ftau_ef ; loads(i_exload).ftau ] ;
            Tcu = [ Tcu , loads(i_exload).Tt_o ] ;
        end
    end
end


% k_mat for modal analysis:
k_mat = w_k_mat + fj_k_mat ; % total stiffnes matrix for modal analysis
vd_mat = w_vd_mat + fj_vd_mat ;

if par.clean % clean up memory
    clearvars -except q u lambda dlambda gamma dgamma s sw par ...
        mass sprdmp cnst loads ...
        nq nlambda ngamma q0 n_m n_sd n_cn n_co n_ex ...
        M T fj_k fj_vd fj_in fj_sdi fj_k_mat fj_vd_mat Tj_u ...
        fgv Dd ref rcn Ttef ftau_ef Tcn Tcu Dcn r_jtips w_sdi ...
        w_k w_vd w_k_mat w_vd_mat w_in r_ks k_mat vd_mat rom
end


%% report:
% % replace sw (log. func. var) with s:
% q = sym( q ) ; u = sym( u ) ; lambda = sym( lambda ) ; dlambda = sym( dlambda ) ; gamma = sym( gamma ) ; dgamma = sym( dgamma ) ; s = sym( s ) ;
% mass = subs( sym( mass ), sw , s ) ; sprdmp = subs( sym( sprdmp ), sw , s ) ; cnst = subs( sym( cnst ), sw , s ) ; loads = subs( sym( load ), sw , s ) ;
% nq = subs( sym( nq ), sw , s ) ; nlambda = subs( sym( nlambda ), sw , s ) ; ngamma = subs( sym( ngamma ), sw , s ) ; q0 = subs( sym( q0 ), sw , s ) ; n_m = subs( sym( n_m ), sw , s ) ; n_sd = subs( sym( n_sd ), sw , s ) ; n_cn = subs( sym( n_cn ), sw , s ) ; n_co = subs( sym( n_co ), sw , s ) ; n_ex = subs( sym( n_ex ), sw , s ) ;
% M = subs( sym( M ), sw , s ) ; T = subs( sym( T ), sw , s ) ; fj_k = subs( sym( fj_k ), sw , s ) ; fj_vd = subs( sym( fj_vd ), sw , s ) ; fj_in = subs( sym( fj_in ), sw , s ) ; fj_sdi = subs( sym( fj_sdi ), sw , s ) ; fj_k_mat = subs( sym( fj_k_mat ), sw , s ) ; fj_vd_mat = subs( sym( fj_vd_mat ), sw , s ) ; Tj_u = subs( sym( Tj_u ), sw , s ) ;
% fgv = subs( sym( fgv ), sw , s ) ; Dd = subs( sym( Dd ), sw , s ) ; ref = subs( sym( ref ), sw , s ) ; rcn = subs( sym( rcn ), sw , s ) ; Ttef = subs( sym( Ttef ), sw , s ) ; ftau_ef = subs( sym( ftau_ef ), sw , s ) ; Tcn = subs( sym( Tcn ), sw , s ) ; Tcu = subs( sym( Tcu ), sw , s ) ; Dcn = subs( sym( Dcn ), sw , s ) ; r_jtips = subs( sym( r_jtips ), sw , s ) ; w_sdi = subs( sym( w_sdi ), sw , s ) ;
% w_k = subs( sym( w_k ), sw , s ) ; w_vd = subs( sym( w_vd ), sw , s ) ; w_k_mat = subs( sym( w_k_mat ), sw , s ) ; w_vd_mat = subs( sym( w_vd_mat ), sw , s ) ; w_in = subs( sym( w_in ), sw , s ) ; r_ks = subs( sym( r_ks ), sw , s ) ; k_mat = subs( sym( k_mat ), sw , s ) ; vd_mat = subs( sym( vd_mat ), sw , s ) ; rom = subs( sym( rom ), sw , s ) ;
% % simplify:
% q = smplfy( q ) ; u = smplfy( u ) ; lambda = smplfy( lambda ) ; dlambda = smplfy( dlambda ) ; gamma = smplfy( gamma ) ; dgamma = smplfy( dgamma ) ; s = smplfy( s ) ;
% mass = smplfy( mass ) ; sprdmp = smplfy( sprdmp ) ; cnst = smplfy( cnst ) ; loads = smplfy( load ) ;
% nq = smplfy( nq ) ; nlambda = smplfy( nlambda ) ; ngamma = smplfy( ngamma ) ; q0 = smplfy( q0 ) ; n_m = smplfy( n_m ) ; n_sd = smplfy( n_sd ) ; n_cn = smplfy( n_cn ) ; n_co = smplfy( n_co ) ; n_ex = smplfy( n_ex ) ;
% M = smplfy( M ) ; T = smplfy( T ) ; fj_k = smplfy( fj_k ) ; fj_vd = smplfy( fj_vd ) ; fj_in = smplfy( fj_in ) ; fj_sdi = smplfy( fj_sdi ) ; fj_k_mat = smplfy( fj_k_mat ) ; fj_vd_mat = smplfy( fj_vd_mat ) ; Tj_u = smplfy( Tj_u ) ;
% fgv = smplfy( fgv ) ; Dd = smplfy( Dd ) ; ref = smplfy( ref ) ; rcn = smplfy( rcn ) ; Ttef = smplfy( Ttef ) ; ftau_ef = smplfy( ftau_ef ) ; Tcn = smplfy( Tcn ) ; Tcu = smplfy( Tcu ) ; Dcn = smplfy( Dcn ) ; r_jtips = smplfy( r_jtips ) ; w_sdi = smplfy( w_sdi ) ;
% w_k = smplfy( w_k ) ; w_vd = smplfy( w_vd ) ; w_k_mat = smplfy( w_k_mat ) ; w_vd_mat = smplfy( w_vd_mat ) ; w_in = smplfy( w_in ) ; r_ks = smplfy(r_ks  ) ; k_mat = smplfy( k_mat ) ; vd_mat = smplfy( vd_mat ) ; rom = smplfy( rom ) ;

save( 'eom/derivations.mat' ) ; % save all

save_func( q , u , lambda , dlambda , gamma , dgamma , s , sw , par , ...
    mass , sprdmp , cnst , loads , ...
    nq , nlambda , ngamma , q0 , n_m , n_sd , n_cn , n_co , n_ex , ...
    M , T , fj_k , fj_vd , fj_in , fj_sdi , fj_k_mat , fj_vd_mat , Tj_u , ...
    fgv , Dd , ref , rcn , Ttef , ftau_ef , Tcn , Tcu , Dcn , r_jtips , w_sdi , ...
    w_k , w_vd , w_k_mat , w_vd_mat , w_in , r_ks , k_mat , vd_mat , rom ) ;


%% Complementary Functions:
function [ Q , TQ ] = TQ_mat( r , qs , rot_type , init_Q_axis )
global unit_quat
% Q = [ q0 r1 r2 r3 ] ; % quaternion format
% Q1 & Q2 are cloumn vectors

switch rot_type
    
    case 'angle_axis' % angle-axis: 4 elements
        Q = ( [ cos( r(4) / 2 ), sin( r(4) / 2 )*r(5:7)/sqrt( r(5:7) * r(5:7).' ) ].' ) ;
        
    case 'rot_strain' % variable curvature with piecewise constant strain assumption in each elements: 3 elements
        Q = [ 1, r(4:6)/2 ].';
        
    case 'unit_quat' % unit quaternion: 3 elements
        Q = [ sqrt( 1 - r(4:6) * r(4:6).' ), r(4:6) ].' ; % % only 0:pi, avoid singularity
        
    case 'non_unit_quat' % non-uit quaternion: 4 elements
        unit_quat = 0 ; % there is non-unit quaternion in the code
        Q = r(4:7).' ; % avoid singularity
        Q = Q / sqrt( Q.' * Q ) ;
        
    case 'frenet_serret'
        s = qs(end);
        rho = r(1:3).' ;
        drho = diff( rho , s );
        t = drho / sqrt( drho.' * drho ) ;
        
        ddrho = diff( drho , s );
        temp = cross( drho , ddrho ) ;
        b = temp / sqrt( temp.' * temp ) ;
        n = cross( b, t );
        
        % dt = diff( t , s );
        % n = dt / sqrt( dt.' * dt ) ;
        % b = cross( t, n );
        
        R = [ t, n, b ];
        Q(1,1) = sqrt( 1 + R(1,1) + R(2,2) + R(3,3) ) / 2 ; % only if trace(R)+1<0
        Q(2,1) = ( R(3,2) - R(2,3) ) / ( 4 * Q(1,1) ) ;
        Q(3,1) = ( R(1,3) - R(3,1) ) / ( 4 * Q(1,1) ) ;
        Q(4,1) = ( R(2,1) - R(1,2) ) / ( 4 * Q(1,1) ) ;
        
    case 'simple_curvilinear'
        s = qs(end) ;
        rho = r(1:3).' ;
        drho = diff( rho , s ) ;
        t = drho / sqrt( drho.' * drho ) ;
        init_Q_axis(2:4) = init_Q_axis(2:4) / sqrt( init_Q_axis(2:4) * init_Q_axis(2:4).' ) ;
        
        % according to definition
        % % Q(1,1) = sqrt( ( init_Q_axis(2:4) * init_Q_axis(2:4).' ) * ( t.' * t ) ) + init_Q_axis(2:4) * t ;
        % Q(1,1) = 1 + init_Q_axis(2:4) * t ; % vectors already normalized
        % Q(1,2:4) = cross( init_Q_axis(2:4) , t.' ) ;
        % Q = ( Q / sqrt( Q * Q.' ) ).' ;
        
        % simpleset derivation: singular at pi
        temp = sqrt( 2 + 2 * init_Q_axis(2:4) * t ) ;
        Q(1,1) = temp / 2 ;
        Q(1,2:4) = 1 / temp * cross( init_Q_axis(2:4) , t.' ) ; % vectors already normalized
        Q = Q.' ;
        
    case 'bishop_frame' % same as 'simple_curvilinear' for now
        s = qs(end) ;
        rho = r(1:3).' ;
        drho = diff( rho , s ) ;
        t = drho / sqrt( drho.' * drho ) ;
        init_Q_axis(2:4) = init_Q_axis(2:4) / sqrt( init_Q_axis(2:4) * init_Q_axis(2:4).' ) ;
        
        % % Q(1,1) = sqrt( ( init_Q_axis(2:4) * init_Q_axis(2:4).' ) * ( t.' * t ) ) + init_Q_axis(2:4) * t ;
        % Q(1,1) = 1 + init_Q_axis(2:4) * t ; % vectors already normalized
        % Q(1,2:4) = cross( init_Q_axis(2:4) , t.' ) ;
        % Q = ( Q / sqrt( Q * Q.' ) ).' ;
        
        temp = sqrt( 2 + 2 * init_Q_axis(2:4) * t ) ;
        Q(1,1) = temp / 2 ;
        Q(1,2:4) = 1 / temp * cross( init_Q_axis(2:4) , t.' ) ; % vectors already normalized
        Q = Q.' ;
        
    otherwise
        Q = [ 1, 0, 0, 0 ].';
end

TQ = sym ( [ Q , [ 0, r(1:3) ].' ] ) ; % 4x4: Each QR contains a translation and then a rotation
Q = smplfy( sym( Q ) ) ;
TQ = smplfy( sym( TQ ) ) ;


function [joint, dof_mult, dof_mult_index] = dof_fit(s, sw, q, q0, par, joint, j_count, nj_dof, n_mesh, n_kn, fig_rom)
% initialization
emps = sym( [] ) ;
n_r = joint(j_count).rom.order(n_mesh,nj_dof) ;
if n_kn == 1 % needed only once for each mesh element
    joint(j_count).dof(nj_dof).init_fit{n_mesh,1} = sym( joint(j_count).dof(nj_dof).init(n_mesh,:) ) ;
    joint(j_count).dof(nj_dof).init_equal{n_mesh,1} = emps ;
    joint(j_count).dof(nj_dof).init_all{n_mesh} = emps ; % each row for a spline segment, last row for summation of all
    joint(j_count).dof(nj_dof).s{n_mesh,1} = emps ;
    joint(j_count).dof(nj_dof).b{n_mesh,1} = emps ;
    joint(j_count).dof(nj_dof).q_equal{n_mesh,1} = emps ;
    joint(j_count).dof(nj_dof).rom_coeff{n_mesh,1} = emps ; % 1st element:
    joint(j_count).dof(nj_dof).rom_series{n_mesh} = emps ; % each element for a spline segment, last element for summation of all, 2nd row for terms without base growing effect
    joint(j_count).dof(nj_dof).init_rom_series{n_mesh} = emps ; % each element for a spline segment, last element for summation of all
    joint(j_count).dof(nj_dof).cond = sym( 1 ); % spline arguments conditions, 1st element is always 1
    joint(j_count).dof(nj_dof).fit_type = sym( joint(j_count).dof(nj_dof).fit_type ) ;
    
    joint(j_count).dof(nj_dof).spring.init_fit{n_mesh,1} = sym( joint(j_count).dof(nj_dof).spring.init(n_mesh,:) ) ;
    joint(j_count).dof(nj_dof).spring.init_equal{n_mesh,1} = emps ;
    joint(j_count).dof(nj_dof).spring.init_all{n_mesh} = sym( joint(j_count).dof(nj_dof).spring.init(n_mesh,:) ) ; % each row for a spline segment, last row for summation of all
    joint(j_count).dof(nj_dof).spring.s{n_mesh,1} = emps ;
    joint(j_count).dof(nj_dof).spring.b{n_mesh,1} = emps ;
    joint(j_count).dof(nj_dof).spring.q_equal{n_mesh,1} = emps ;
    joint(j_count).dof(nj_dof).spring.init_rom_series{n_mesh} = emps ; % each element for a spline segment, last element for summation of all
    joint(j_count).dof(nj_dof).spring.cond = sym( 1 ); % spline arguments conditions, 1st element is always 1
    joint(j_count).dof(nj_dof).spring.fit_type = sym( joint(j_count).dof(nj_dof).spring.fit_type ) ;
    
    if ~joint(j_count).rom.var_init % improve performance by setting init. to double
        joint(j_count).dof(nj_dof).init(n_mesh,:) = subs( joint(j_count).dof(nj_dof).init(n_mesh,:), par.sym, par.var );
        joint(j_count).dof(nj_dof).init_fit{n_mesh,1} = subs( joint(j_count).dof(nj_dof).init_fit{n_mesh,1}, par.sym, par.var );
        joint(j_count).dof(nj_dof).init_s(n_mesh,:) = subs( joint(j_count).dof(nj_dof).init_s(n_mesh,:), par.sym, par.var );
        joint(j_count).dof(nj_dof).spring.init(n_mesh,:) = subs( joint(j_count).dof(nj_dof).spring.init(n_mesh,:), par.sym, par.var );
        joint(j_count).dof(nj_dof).spring.init_s(n_mesh,:) = subs( joint(j_count).dof(nj_dof).spring.init_s(n_mesh,:), par.sym, par.var );
    else
        joint(j_count).dof(nj_dof).init(n_mesh,:) = subs( joint(j_count).dof(nj_dof).init(n_mesh,:), par.control_sym, par.control_var );
        joint(j_count).dof(nj_dof).init_fit{n_mesh,1} = subs( joint(j_count).dof(nj_dof).init_fit{n_mesh,1}, par.sym, par.var );
        joint(j_count).dof(nj_dof).init_s(n_mesh,:) = subs( joint(j_count).dof(nj_dof).init_s(n_mesh,:), par.control_sym, par.control_var );
        joint(j_count).dof(nj_dof).spring.init(n_mesh,:) = subs( joint(j_count).dof(nj_dof).spring.init(n_mesh,:), par.control_sym, par.control_var );
        joint(j_count).dof(nj_dof).spring.init_s(n_mesh,:) = subs( joint(j_count).dof(nj_dof).spring.init_s(n_mesh,:), par.control_sym, par.control_var );
    end
end
% init values
dof_mult{n_kn} = 0 ; dof_mult_index{n_kn} = emps ; dof_equal_index{n_kn} = emps ;
init_s_index = 1 : numel( joint(j_count).dof(nj_dof).init_s(n_mesh,:) );
joint(j_count).dof(nj_dof).cond(n_kn) = 1; % default condition
init_offset = 0;
init_offset_spring = 0;

if isnan( joint(j_count).dof(nj_dof).equal2{1}(n_mesh,4) ) % init from other dof
    temp = joint(j_count).dof(nj_dof).equal2{1}(n_mesh,:) ; % [j_count, n_mesh, nj_dof, i_dof_mult, l_rom, diff_order, coeff] x i_dof_mult
    % joint(j_count).dof(nj_dof).init_s(n_mesh,:) = joint(temp(1)).dof(temp(3)).init_s(temp(2),:) ; Not orking if not cell
    % joint(j_count).dof(nj_dof).init(n_mesh,:) = joint(temp(1)).dof(temp(3)).init(temp(2),:) ;
    joint(j_count).dof(nj_dof).init_fit{n_mesh,:} = joint(temp(1)).dof(temp(3)).init_fit{temp(2),:} ;
    joint(j_count).dof(nj_dof).init_equal{n_mesh,:} = joint(temp(1)).dof(temp(3)).init_equal{temp(2),:} ;
    joint(j_count).dof(nj_dof).init_all{n_mesh} = joint(temp(1)).dof(temp(3)).init_all{temp(2)} ;
    joint(j_count).dof(nj_dof).s{n_mesh,:} = joint(temp(1)).dof(temp(3)).s{temp(2),:} ;
    joint(j_count).dof(nj_dof).b{n_mesh,:} = joint(temp(1)).dof(temp(3)).b{temp(2),:} ;
    joint(j_count).dof(nj_dof).q_equal{n_mesh,:} = joint(temp(1)).dof(temp(3)).q_equal{temp(2),:} ;
    joint(j_count).dof(nj_dof).rom_coeff{n_mesh,:} = joint(temp(1)).dof(temp(3)).rom_coeff{temp(2),:} ;
    joint(j_count).dof(nj_dof).rom_series{n_mesh} = joint(temp(1)).dof(temp(3)).rom_series{temp(2)}(2,:) ; % original terms without base growing effect
    joint(j_count).dof(nj_dof).init_rom_series{n_mesh} = joint(temp(1)).dof(temp(3)).init_rom_series{temp(2)} ;
    joint(j_count).dof(nj_dof).cond = joint(temp(1)).dof(temp(3)).cond(2,:) ;
    joint(j_count).dof(nj_dof).fit_type(n_mesh,1:numel(joint(temp(1)).dof(temp(3)).fit_type(temp(2),:))) = joint(temp(1)).dof(temp(3)).fit_type(temp(2),:) ;
else
    S = emps ; b = emps ; q_equal = emps ;
    i_kn2 = 1;
    if numel( joint(j_count).dof(nj_dof).fit_type(n_mesh,:) ) > 1 && joint(j_count).dof(nj_dof).fit_type(n_mesh,1) >= 2 % spline init & arg cond.s
        if n_kn < numel( joint(j_count).dof(nj_dof).fit_type(n_mesh,:) ) % init.s
            init_s_index = find( subs(joint(j_count).dof(nj_dof).init_s(n_mesh,:), par.sym, par.var) <= ...
                subs(joint(j_count).dof(nj_dof).fit_type(n_mesh,n_kn+1), par.sym, par.var) ) ;
            joint(j_count).dof(nj_dof).init_fit{n_mesh,n_kn} = joint(j_count).dof(nj_dof).init(n_mesh,init_s_index);
        end
        if n_kn > 1
            init_s_index = find( subs(joint(j_count).dof(nj_dof).init_s(n_mesh,init_s_index), par.sym, par.var) >= ...
                subs(joint(j_count).dof(nj_dof).fit_type(n_mesh,n_kn), par.sym, par.var) ) ;
            joint(j_count).dof(nj_dof).init_fit{n_mesh,n_kn} = joint(j_count).dof(nj_dof).init(n_mesh,init_s_index); % offset
            % continuity condition at segment locations
            init_offset = - joint(j_count).dof(nj_dof).fit_type(n_mesh,n_kn) ; % vars in spline_knots will not be substituted by par.var or par.control_var
            for i_p = 1 : n_r + 1 % revise kin. const.s for new spline seg.s
                if ~isnan( joint(j_count).dof(nj_dof).equal2{i_p}(n_mesh,4) ) % not for kin. const.s on entire dof
                    if i_p <= 2 % continuity order
                        i_kn2 = n_kn - 1 ;
                        joint(j_count).dof(nj_dof).equal2{i_p} = sym( joint(j_count).dof(nj_dof).equal2{1} );
                        joint(j_count).dof(nj_dof).equal2{i_p}(n_mesh,:) =  [j_count, n_mesh, nj_dof, 0, joint(j_count).dof(nj_dof).fit_type(n_mesh,n_kn), i_p-1, 1] ; % coefficient_similar_to_dof_at_tip
                    else % cancel individual coeff. kin. const.s
                        joint(j_count).dof(nj_dof).equal2{i_p}(n_mesh,:) = sym( zeros(1,7) );
                    end
                end
            end
        end
        if  joint(j_count).dof(nj_dof).fit_type(n_mesh,1) == 3 % spline_logistic_function
            lfk = joint(j_count).rom.growth; % logistic growth rate (curve steepness)
            if n_kn > 1
                joint(j_count).dof(nj_dof).cond(n_kn) = 1 / ( 1 + exp( -lfk * ( sw - joint(j_count).dof(nj_dof).fit_type(n_mesh,n_kn) ) ) ) ;
            end
        end
    end
    
    % if no init data is provided for this segment
    if isempty( init_s_index )
        init_s_index = 0;
        if n_kn > 1
            for i_kn = 1 : n_kn-1
                init_s_index = init_s_index + numel( joint(j_count).dof(nj_dof).init_fit{n_mesh,i_kn} ) ;
            end
        end
        if init_s_index == 0
            init_s_index = 1;
        end
        joint(j_count).dof(nj_dof).init_fit{n_mesh,n_kn} = joint(j_count).dof(nj_dof).init(n_mesh,init_s_index) ; % copy last value
    end
    
    for i_s = 1 : n_r + 1 % n_r = 0 for not-rom dof
        if joint(j_count).dof(nj_dof).equal2{i_s}(n_mesh,1) ~= 0 % it is constraint
            b = [ b (s+init_offset)^(i_s-1) ] ;
            temp = joint(j_count).dof(nj_dof).equal2{i_s}(n_mesh,:) ; % [j_count, n_mesh, nj_dof, i_dof_mult, l_rom, diff_order, coeff] x i_dof_mult
            if temp(7) == 0; temp(7) = 1; end % set default coeff if not specified
            if isnan( temp(1) ) % ground fixed or set_rom_coefficient
                q_equal = [ q_equal ; temp(5) ] ;
            else
                if temp(4) > 0 % i_dof_mult provided
                    q_equal = [ q_equal ; temp(7)*diff( joint(temp(1)).dof(temp(3)).rom_coeff{temp(2),i_kn2}(temp(4)) , s , temp(6) ) ] ;
                else
                    if isnan( temp(4) ) % same i_dof_mult of the target dof as i_dof_mult of current dof
                        q_equal = [ q_equal ; temp(7)*diff( joint(temp(1)).dof(temp(3)).rom_coeff{temp(2),i_kn2}(i_s) , s , temp(6) ) ] ;
                    else % l_rom case
                        if isnan( temp(5) ) % consider tip
                            q_equal = [ q_equal ; temp(7)*subs( diff( joint(temp(1)).dof(temp(3)).rom_series{temp(2)}(1,i_kn2) , s , temp(6) ) , [s, sw] , joint(temp(1)).rom.length(temp(2),2) * [1, 1] ) ] ;
                        else % l_rom available
                            q_equal = [ q_equal ; temp(7)*subs( diff( joint(temp(1)).dof(temp(3)).rom_series{temp(2)}(1,i_kn2) , s , temp(6) ) , [s, sw] , temp(5) * [1, 1] ) ] ;
                        end
                    end
                end
            end
            dof_equal_index{n_kn} = [ dof_equal_index{n_kn} , i_s ] ;
        else
            if i_s == 1 && ~joint(j_count).rom.free_base(n_mesh) % base condition from .rom object: acts only if no other kin. const. is specified
                b = [ b (s+init_offset)^(i_s-1) ] ;
                q_equal = [ q_equal ; 0 ] ; % q_equal = [ q_equal ; temp(5) ] ;
                dof_equal_index{n_kn} = [ dof_equal_index{n_kn} , i_s ] ;
            else
                S = [ S (s+init_offset)^(i_s-1) ] ;
                dof_mult{n_kn} = dof_mult{n_kn} + 1 ;
                dof_mult_index{n_kn} = [ dof_mult_index{n_kn} , i_s ] ;
            end
        end
    end
    q_equal_0 = subs( q_equal , q , q0 ) ;
    % initial dof val
    S0 = emps ; b0 = emps ;
    for i_s = init_s_index
        s0 = joint(j_count).dof(nj_dof).init_s(n_mesh,i_s) ;
        S0 = [ S0 ; subs( S , s , s0 ) ] ; % no need for segment_offset
        b0 = [ b0 ; subs( b , s , s0 ) ] ;
    end
    if isempty( q_equal )
        q_equal = 0 ; b = 0 ;
        q_equal_0 = 0 ; b0 = 0 ;
    end
    if ~joint(j_count).rom.var_init % improve performance by setting init. to double
        q_equal_0 = subs( q_equal_0 , par.sym , par.var ) ;
        S0 = subs( S0 , par.sym , par.var ) ;
        b0 = subs( b0 , par.sym , par.var ) ;
    else
        q_equal_0 = subs( q_equal_0 , par.control_sym , par.control_var ) ;
        S0 = subs( S0 , par.control_sym , par.control_var ) ;
        b0 = subs( b0 , par.control_sym , par.control_var ) ;
    end
    if isempty( S0 )
        joint(j_count).dof(nj_dof).init_fit{n_mesh,n_kn} = [] ; % dof init after fitting
        joint(j_count).dof(nj_dof).init_rom_series{n_mesh}(n_kn) = ( b * q_equal_0 ).' ; % init contains init. val. for all coeff.s
    else
        joint(j_count).dof(nj_dof).init_fit{n_mesh,n_kn} = ( pinv( S0 ) * ( joint(j_count).dof(nj_dof).init(n_mesh,init_s_index).' - b0 * q_equal_0 ) ).' ; % dof
        joint(j_count).dof(nj_dof).init_rom_series{n_mesh}(n_kn) = joint(j_count).dof(nj_dof).init_fit{n_mesh,n_kn} * S.' + ( b * q_equal_0 ).' ; % init contains init. val. for all coeff.s
    end
    joint(j_count).dof(nj_dof).init_equal{n_mesh,n_kn} = q_equal_0.' ; % from kinematic constraints (equal2)
    if ~isempty( joint(j_count).dof(nj_dof).init_fit{n_mesh,n_kn} )
        joint(j_count).dof(nj_dof).init_all{n_mesh}(n_kn,dof_mult_index{n_kn}) = joint(j_count).dof(nj_dof).init_fit{n_mesh,n_kn} ; % for all rom coefficients, only init. val.s
    end
    if ~isempty( joint(j_count).dof(nj_dof).init_equal{n_mesh,n_kn} )
        joint(j_count).dof(nj_dof).init_all{n_mesh}(n_kn,dof_equal_index{n_kn}) = joint(j_count).dof(nj_dof).init_equal{n_mesh,n_kn} ;
    end
    joint(j_count).dof(nj_dof).s{n_mesh,n_kn} = S ;
    joint(j_count).dof(nj_dof).b{n_mesh,n_kn} = b ;
    joint(j_count).dof(nj_dof).q_equal{n_mesh,n_kn} = q_equal.' ;
    joint(j_count).dof(nj_dof).rom_coeff{n_mesh,n_kn}(1,dof_equal_index{n_kn}) = joint(j_count).dof(nj_dof).q_equal{n_mesh,n_kn} ; % may contain states
    
    % logistic function coefficients
    if n_kn == numel( joint(j_count).dof(nj_dof).fit_type(n_mesh,:) ) % needed only once for each mesh element
        if numel( joint(j_count).dof(nj_dof).cond ) > 1
            joint(j_count).dof(nj_dof).rom_series{n_mesh}(1,end+1) = joint(j_count).dof(nj_dof).rom_series{n_mesh}(1,1);
            joint(j_count).dof(nj_dof).init_rom_series{n_mesh}(end+1) = joint(j_count).dof(nj_dof).init_rom_series{n_mesh}(1);
            joint(j_count).dof(nj_dof).init_all{n_mesh}(end+1,:) = joint(j_count).dof(nj_dof).init_all{n_mesh}(1,:) ;
            for i_kn = 2 : numel( joint(j_count).dof(nj_dof).cond ) % joint(j_count).dof(nj_dof).cond(1) is always = 1
                joint(j_count).dof(nj_dof).rom_series{n_mesh}(1,end) = joint(j_count).dof(nj_dof).rom_series{n_mesh}(1,end) - ...
                    joint(j_count).dof(nj_dof).cond(i_kn) * joint(j_count).dof(nj_dof).rom_series{n_mesh}(1,i_kn-1) + ...
                    joint(j_count).dof(nj_dof).cond(i_kn) * joint(j_count).dof(nj_dof).rom_series{n_mesh}(1,i_kn) ;
                joint(j_count).dof(nj_dof).init_rom_series{n_mesh}(end) = joint(j_count).dof(nj_dof).init_rom_series{n_mesh}(end) - ...
                    joint(j_count).dof(nj_dof).cond(i_kn) * joint(j_count).dof(nj_dof).init_rom_series{n_mesh}(i_kn-1) + ...
                    joint(j_count).dof(nj_dof).cond(i_kn) * joint(j_count).dof(nj_dof).init_rom_series{n_mesh}(i_kn) ;
                joint(j_count).dof(nj_dof).init_all{n_mesh}(end,:) = joint(j_count).dof(nj_dof).init_all{n_mesh}(end,:) - ...
                    joint(j_count).dof(nj_dof).cond(i_kn) * joint(j_count).dof(nj_dof).init_all{n_mesh}(i_kn-1,:) + ...
                    joint(j_count).dof(nj_dof).cond(i_kn) * joint(j_count).dof(nj_dof).init_all{n_mesh}(i_kn,:) ;
            end
        end
    end
end

% spring initial configuration
if n_kn == numel( joint(j_count).dof(nj_dof).fit_type(n_mesh,:) ) || ... % needed only once for each mesh element, last spline segment
        isnan( joint(j_count).dof(nj_dof).equal2{1}(n_mesh,4) ) % dof similar to another dof
    if isnan( joint(j_count).dof(nj_dof).spring.init(n_mesh,1) ) % spring.init from dof.init: uses S, b, q_equal from dof.init
        % joint(j_count).dof(nj_dof).spring.init_s(n_mesh,:) = joint(j_count).dof(nj_dof).init_s(n_mesh,:) ; Not orking if not cell
        % joint(j_count).dof(nj_dof).spring.init(n_mesh,:) = joint(j_count).dof(nj_dof).init(n_mesh,:) ;
        joint(j_count).dof(nj_dof).spring.init_fit{n_mesh,1} = joint(j_count).dof(nj_dof).init_all{n_mesh}(end,:) ;
        joint(j_count).dof(nj_dof).spring.init_all{n_mesh} = joint(j_count).dof(nj_dof).init_all{n_mesh} ;
        joint(j_count).dof(nj_dof).spring.init_equal{n_mesh,:} = joint(j_count).dof(nj_dof).init_equal{n_mesh,:} ;
        joint(j_count).dof(nj_dof).spring.s{n_mesh,:} = joint(j_count).dof(nj_dof).s{n_mesh,:} ;
        joint(j_count).dof(nj_dof).spring.b{n_mesh,:} = joint(j_count).dof(nj_dof).b{n_mesh,:} ;
        joint(j_count).dof(nj_dof).spring.q_equal{n_mesh,:} = joint(j_count).dof(nj_dof).q_equal{n_mesh,:} ;
        joint(j_count).dof(nj_dof).spring.fit_type(n_mesh,:) = joint(j_count).dof(nj_dof).fit_type(n_mesh,:) ;
        joint(j_count).dof(nj_dof).spring.init_rom_series{n_mesh} = joint(j_count).dof(nj_dof).init_rom_series{n_mesh} ;
        joint(j_count).dof(nj_dof).spring.cond = joint(j_count).dof(nj_dof).cond ; % no need for joint(j_count).dof(nj_dof).cond(2,:), it refers to current dof
        if ~joint(j_count).rom.var_init % improve performance by setting init. to double
            joint(j_count).dof(nj_dof).spring.init_rom_series{n_mesh} = subs( joint(j_count).dof(nj_dof).spring.init_rom_series{n_mesh} , par.sym , par.var ) ;
            joint(j_count).dof(nj_dof).spring.cond = subs( joint(j_count).dof(nj_dof).spring.cond , par.sym , par.var ) ;
        else
            joint(j_count).dof(nj_dof).spring.init_rom_series{n_mesh} = subs( joint(j_count).dof(nj_dof).spring.init_rom_series{n_mesh} , par.control_sym , par.control_var ) ;
            joint(j_count).dof(nj_dof).spring.cond = subs( joint(j_count).dof(nj_dof).spring.cond , par.control_sym , par.control_var ) ;
        end
    else
        args = []; % spline arguments
        for i_kn = 1 : numel( joint(j_count).dof(nj_dof).spring.fit_type(n_mesh,:) )
            S = emps ; b = emps ; q_equal = emps ;
            dof_mult_index_spring = emps ; dof_equal_index_spring = emps ;
            args.cond(i_kn) = sym( 1 ) ;
            init_s_index_spring = 1 : numel( joint(j_count).dof(nj_dof).spring.init_s(n_mesh,:) );
            if numel( joint(j_count).dof(nj_dof).spring.fit_type(n_mesh,:) ) > 1 && joint(j_count).dof(nj_dof).spring.fit_type(n_mesh,1) >= 2 % spline init & arg cond.s
                if i_kn < numel( joint(j_count).dof(nj_dof).spring.fit_type(n_mesh,:) ) % init.s
                    init_s_index_spring = find( subs(joint(j_count).dof(nj_dof).spring.init_s(n_mesh,:), par.sym, par.var) <= ...
                        subs(joint(j_count).dof(nj_dof).spring.fit_type(n_mesh,i_kn+1), par.sym, par.var) ) ;
                    joint(j_count).dof(nj_dof).spring.init_fit{n_mesh,i_kn} = joint(j_count).dof(nj_dof).spring.init(n_mesh,init_s_index_spring);
                end
                if i_kn > 1
                    init_s_index_spring = find( subs(joint(j_count).dof(nj_dof).spring.init_s(n_mesh,init_s_index_spring), par.sym, par.var) >= ...
                        subs(joint(j_count).dof(nj_dof).spring.fit_type(n_mesh,i_kn), par.sym, par.var) ) ;
                    joint(j_count).dof(nj_dof).spring.init_fit{n_mesh,i_kn} = joint(j_count).dof(nj_dof).spring.init(n_mesh,init_s_index_spring); % offset
                    % continuity condition at 0
                    init_offset_spring = - joint(j_count).dof(nj_dof).spring.fit_type(n_mesh,i_kn) ; % I.C. so subs all vars. use control vars in spring_offset instead if needed
                    for i_p = 1 : n_r+1  % revise kin. const.s for new spline seg.s
                        if ~isnan( joint(j_count).dof(nj_dof).spring.equal2{i_p}(n_mesh,4) )
                            if i_p <= 2 % continuity order, NO NEED: KIN. CONST. ARE W.R.T. DOFS ONLY NOT PREV. SPRINGS
                                % joint(j_count).dof(nj_dof).spring.equal2{i_p} = sym( joint(j_count).dof(nj_dof).spring.equal2{i_p} ) ;
                                % joint(j_count).dof(nj_dof).spring.equal2{i_p}(n_mesh,:) = [j_count, n_mesh, nj_dof, 0, joint(j_count).dof(nj_dof).spring.fit_type(n_mesh,i_kn), i_p-1, 1] ; % coefficient_similar_to_dof_at_tip
                            else % cancel individual coeff. kin. const.s
                                joint(j_count).dof(nj_dof).spring.equal2{i_p} = sym( zeros(1,7) );
                            end
                        end
                    end
                end
                if  joint(j_count).dof(nj_dof).spring.fit_type(n_mesh,1) == 2 % spline_piecewise
                    if i_kn == 1 % srg cond.s
                        args.cond(i_kn) = ( s <= joint(j_count).dof(nj_dof).spring.fit_type(n_mesh,i_kn+1) ) ;
                    elseif i_kn ==  numel( joint(j_count).dof(nj_dof).spring.fit_type(n_mesh,:) )
                        args.cond(i_kn) = ( s > joint(j_count).dof(nj_dof).spring.fit_type(n_mesh,end) ) ;
                    else
                        args.cond(i_kn) = ( s > joint(j_count).dof(nj_dof).spring.fit_type(n_mesh,i_kn) && s < joint(j_count).dof(nj_dof).spring.fit_type(n_mesh,i_kn+1) );
                    end
                end
                if  joint(j_count).dof(nj_dof).spring.fit_type(n_mesh,1) == 3 % spline_logistic_function
                    lfk = joint(j_count).rom.growth; % logistic growth rate (curve steepness)
                    if i_kn > 1 % srg cond.s
                        args.cond(i_kn) = 1 / ( 1 + exp( -lfk * ( sw - joint(j_count).dof(nj_dof).spring.fit_type(n_mesh,i_kn) ) ) ) ;
                    end
                end
            end
            
            % if no init data is provided for this segment
            if isempty( init_s_index_spring )
                init_s_index_spring = 0;
                if i_kn > 1
                    for j_kn = 1 : i_kn-1
                        init_s_index_spring = init_s_index_spring + numel( joint(j_count).dof(nj_dof).spring.init_fit{n_mesh,j_kn} ) ;
                    end
                end
                if init_s_index_spring == 0
                    init_s_index_spring = 1;
                end
                joint(j_count).dof(nj_dof).spring.init_fit{n_mesh,i_kn} = joint(j_count).dof(nj_dof).spring.init(n_mesh,init_s_index_spring); % copy last value
            end
            
            for i_s = 1 : n_r + 1 % n_r = 0 for not-rom dof
                if joint(j_count).dof(nj_dof).spring.equal2{i_s}(n_mesh,1) ~= 0
                    b = [ b (s+init_offset_spring)^(i_s-1) ] ;
                    temp = joint(j_count).dof(nj_dof).spring.equal2{i_s}(n_mesh,:) ; % [j_count, n_mesh, nj_dof, i_dof_mult, l_rom, diff_order, coeff] x i_dof_mult
                    if temp(7) == 0; temp(7) = 1; end
                    if isnan( temp(1) ) % ground fixed - set_rom_coefficient
                        q_equal = [ q_equal ; temp(5) ] ;
                    else
                        if temp(4) > 0  % i_dof_mult provided
                            q_equal = [ q_equal ; temp(7)*diff( joint(temp(1)).dof(temp(3)).init_all{temp(2)}(end,temp(4)) , s , temp(6) ) ] ;
                        else
                            if isnan( temp(4) )  % same i_dof_mult as current dof
                                q_equal = [ q_equal ; temp(7)*diff( joint(temp(1)).dof(temp(3)).init_all{temp(2)}(end,i_s) , s , temp(6) ) ] ;
                            else % l_rom case
                                if isnan( temp(5) ) % consider tip
                                    q_equal = [ q_equal ; temp(7)*subs( diff( joint(temp(1)).dof(temp(3)).init_rom_series{temp(2)}(end) , s , temp(6) ) , [s, sw] , joint(temp(1)).rom.length(temp(2),2) * [1, 1] ) ] ;
                                else % l_rom available
                                    q_equal = [ q_equal ; temp(7)*subs( diff( joint(temp(1)).dof(temp(3)).init_rom_series{temp(2)}(end) , s , temp(6) ) , [s, sw] , temp(5) * [1, 1] ) ] ;
                                end
                            end
                        end
                    end
                    dof_equal_index_spring = [ dof_equal_index_spring , i_s ] ;
                else
                    % if i_s == 1 && ~joint(j_count).rom.free_base % base condition from .rom object: acts only if no other kin. const. is specified
                    %     b = [ b (s+init_offset_spring)^(i_s-1) ] ;
                    %     q_equal = [ q_equal ; 0 ] ; % q_equal = [ q_equal ; temp(5) ] ;
                    %     dof_equal_index = [ dof_equal_index , i_s ] ;
                    % else
                    S = [ S (s+init_offset_spring)^(i_s-1) ] ;
                    dof_mult_index_spring = [ dof_mult_index_spring , i_s ] ;
                    % end
                end
            end
            
            q_equal_0 = subs( q_equal , q , q0 ) ;
            S0 = emps ; b0 = emps ;
            for i_s = init_s_index_spring
                s0 = joint(j_count).dof(nj_dof).spring.init_s(n_mesh,i_s) ; % offset for continuity cond.
                S0 = [ S0 ; subs( S , s , s0 ) ] ; % no need for segment_offset_spring
                b0 = [ b0 ; subs( b , s , s0 ) ] ;
            end
            if isempty( q_equal )
                q_equal = 0 ; b = 0 ;
                q_equal_0 = 0 ; b0 = 0 ;
            end
            if ~joint(j_count).rom.var_init % improve performance by setting init. to double
                q_equal_0 = subs( q_equal_0 , par.sym , par.var ) ;
                S0 = subs( S0 , par.sym , par.var ) ;
                b0 = subs( b0 , par.sym , par.var ) ;
                args.cond = subs( args.cond , par.sym , par.var ) ;
            else
                q_equal_0 = subs( q_equal_0 , par.control_sym , par.control_var ) ;
                S0 = subs( S0 , par.control_sym , par.control_var ) ;
                b0 = subs( b0 , par.control_sym , par.control_var ) ;
                args.cond = subs( args.cond , par.control_sym , par.control_var ) ;
            end
            
            if isempty( S0 )
                args.init{2*i_kn} = [] ; % dof
                args.init_rom_series{2*i_kn} = ( b * q_equal_0 ).' ; % init contains init. val. for all coeff.s
            else
                if isinf( joint(j_count).dof(nj_dof).spring.init(n_mesh,1) ) % initi from rom constant (c0)
                    args.init{2*i_kn}(1,:) = q_equal_0(1) * ones( 1 , numel( joint(j_count).dof(nj_dof).spring.init_fit{n_mesh,i_kn} ) ) ;
                end
                args.init{2*i_kn} = ( pinv( S0 ) * ( joint(j_count).dof(nj_dof).spring.init_fit{n_mesh,i_kn}.' - b0 * q_equal_0 ) ).' ; % dof
                args.init_rom_series{2*i_kn} = args.init{2*i_kn} * S.' + ( b * q_equal_0 ).' ; % init contains init. val. for all coeff.s
            end
            args.init_equal{2*i_kn} = q_equal_0.' ; % from kinematic constraints (equal2)
            args.s{2*i_kn} = S ;
            args.b{2*i_kn} = b ;
            args.q_equal{2*i_kn} = q_equal.' ;
            i_ctemp = 0;
            for i_c = dof_mult_index_spring
                i_ctemp = i_ctemp + 1;
                args.init_all(i_c).vec{2*i_kn} = args.init{2*i_kn}(i_ctemp) ; % for all rom coefficients, only init. val.s
            end
            i_ctemp = 0;
            for i_c = dof_equal_index_spring
                i_ctemp = i_ctemp + 1;
                args.init_all(i_c).vec{2*i_kn} = args.q_equal{2*i_kn}(i_ctemp) ;
            end
            
            args.init{2*i_kn-1} = args.cond(i_kn);
            args.init_rom_series{2*i_kn-1} = args.cond(i_kn);
            args.init_equal{2*i_kn-1} = args.cond(i_kn);
            args.s{2*i_kn-1} = args.cond(i_kn);
            args.b{2*i_kn-1} = args.cond(i_kn);
            args.q_equal{2*i_kn-1} = args.cond(i_kn);
            for i_c = 1 : numel( args.init_all )
                args.init_all(i_c).vec{2*i_kn-1} = args.cond(i_kn);
            end
            if numel( joint(j_count).dof(nj_dof).spring.fit_type(n_mesh,:) ) == 1 || ... % general case
                    joint(j_count).dof(nj_dof).spring.fit_type(n_mesh,1) == 3 % spline logistic function
                joint(j_count).dof(nj_dof).spring.init_fit{n_mesh,i_kn} =  args.init{2*i_kn} ; % dof
                joint(j_count).dof(nj_dof).spring.init_rom_series{n_mesh}(i_kn) = args.init_rom_series{2*i_kn} ; % init contains init. val. for all coeff.s
                joint(j_count).dof(nj_dof).spring.init_equal{n_mesh} = args.init_equal{2*i_kn} ; % from kinematic constraints (equal2)
                joint(j_count).dof(nj_dof).spring.s{n_mesh,i_kn} = args.s{2*i_kn} ;
                joint(j_count).dof(nj_dof).spring.b{n_mesh,i_kn} = args.b{2*i_kn} ;
                joint(j_count).dof(nj_dof).spring.q_equal{n_mesh,i_kn} = args.q_equal{2*i_kn} ;
                for i_c = 1 : numel( args.init_all )
                    joint(j_count).dof(nj_dof).spring.init_all{n_mesh}(i_kn,i_c) = args.init_all(i_c).vec{2*i_kn} ;
                end
            end
        end
        
        % logistic function coefficients
        if numel( args.cond ) > 1
            joint(j_count).dof(nj_dof).spring.cond = args.cond;
            joint(j_count).dof(nj_dof).spring.init_rom_series{n_mesh}(end+1) = joint(j_count).dof(nj_dof).spring.init_rom_series{n_mesh}(1);
            joint(j_count).dof(nj_dof).spring.init_all{n_mesh}(end+1,:) = joint(j_count).dof(nj_dof).spring.init_all{n_mesh}(1,:);
            for i_kn = 2 : numel( args.cond ) % args.cond(1) is always = 1
                joint(j_count).dof(nj_dof).spring.init_rom_series{n_mesh}(end) = joint(j_count).dof(nj_dof).spring.init_rom_series{n_mesh}(end) - ...
                    args.cond(i_kn) * joint(j_count).dof(nj_dof).spring.init_rom_series{n_mesh}(i_kn-1) + ...
                    args.cond(i_kn) * joint(j_count).dof(nj_dof).spring.init_rom_series{n_mesh}(i_kn) ;
                joint(j_count).dof(nj_dof).spring.init_all{n_mesh}(end,:) = joint(j_count).dof(nj_dof).spring.init_all{n_mesh}(end,:) - ...
                    args.cond(i_kn) * joint(j_count).dof(nj_dof).spring.init_all{n_mesh}(i_kn-1,:) + ...
                    args.cond(i_kn) * joint(j_count).dof(nj_dof).spring.init_all{n_mesh}(i_kn,:) ;
            end
        end
        
        if numel( joint(j_count).dof(nj_dof).spring.fit_type(n_mesh,:) ) > 1 && joint(j_count).dof(nj_dof).spring.fit_type(n_mesh,1) == 2 % spline piecewise
            joint(j_count).dof(nj_dof).spring.init_fit{n_mesh,i_kn} = piecewise( args.init{:} ) ; % dof
            joint(j_count).dof(nj_dof).spring.init_rom_series{n_mesh}(end) = piecewise( args.init_rom_series{:} ) ; % init contains init. val. for all coeff.s
            joint(j_count).dof(nj_dof).spring.init_equal{n_mesh} = piecewise( args.init_equal{:} ) ; % from kinematic constraints (equal2)
            joint(j_count).dof(nj_dof).spring.s{n_mesh} = piecewise( args.s{:} ) ;
            joint(j_count).dof(nj_dof).spring.b{n_mesh} = piecewise( args.b{:} ) ;
            joint(j_count).dof(nj_dof).spring.q_equal{n_mesh} = piecewise( args.q_equal{:} ) ;
            for i_c = 1 : numel( args.init_all )
                joint(j_count).dof(nj_dof).spring.init_all{n_mesh}(end,i_c) = piecewise( args.init_all(i_c).vec{:} ) ;
            end
        end
    end
end

if par.plotIC > 1 % compare fit curve with init data
    figure(fig_rom)
    if n_kn == 1 ; hold off; end
    % segment init
    temp_init_s = subs(joint(j_count).dof(nj_dof).init_s(n_mesh,init_s_index), par.sym, par.var);
    temp_init = subs(joint(j_count).dof(nj_dof).init(n_mesh,init_s_index), par.sym, par.var);
    plot(temp_init_s(1,:), temp_init(1,:), 'o'); hold on
    % segment fit
    temp_init_s = subs(joint(j_count).dof(nj_dof).init_s(n_mesh,init_s_index([1,end])), par.sym, par.var);
    temp_init_s_all = subs(joint(j_count).dof(nj_dof).init_s(n_mesh,[1,end]), par.sym, par.var);
    if numel( joint(j_count).dof(nj_dof).init_s(n_mesh,:) ) > numel( init_s_index ) % if not dof_similar_to_other_dof
        if n_kn < numel( joint(j_count).dof(nj_dof).fit_type(n_mesh,:) ) % init.s
            temp_init_s(2) = subs(joint(j_count).dof(nj_dof).fit_type(n_mesh,n_kn+1), par.sym, par.var) ;
            temp_init_s_all(2) = temp_init_s(2) ;
        end
        if n_kn > 1
            temp_init_s(1) = subs(joint(j_count).dof(nj_dof).fit_type(n_mesh,n_kn), par.sym, par.var) ;
        end
    end
    s_check = linspace(temp_init_s(1,1), temp_init_s(1,end), par.n_int);
    rom_check = subs(subs(subs(joint(j_count).dof(nj_dof).init_rom_series{n_mesh}(end), par.sym, par.var), sw, s), s, s_check);
    plot(s_check, rom_check, 'linewidth', 2); hold on
    % labeling
    title(['joint: ' num2str(j_count) ', mesh instance: ' num2str(n_mesh) ', dof: ' num2str(nj_dof) ', spline segment: ' num2str(n_kn)])
    xlabel('s [m]'); ylabel('state');
    legend( 'segment init' , 'segment fit' ) ;
    % final plots
    if n_kn == numel( joint(j_count).dof(nj_dof).fit_type(n_mesh,:) ) || ... % last spline segment
            isnan( joint(j_count).dof(nj_dof).equal2{1}(n_mesh,4) ) % dof similar to another dof
        % body fit
        s_check_all = linspace(temp_init_s_all(1,1), temp_init_s_all(1,2), par.n_int);
        rom_check_all = subs(subs(subs(joint(j_count).dof(nj_dof).init_rom_series{n_mesh}(end), par.sym, par.var), sw, s), s, s_check_all);
        plot(s_check_all, rom_check_all, 'y'); hold on
        % spring init
        temp_init_s = subs(subs(joint(j_count).dof(nj_dof).spring.init_s(n_mesh,:), q, q0), par.sym, par.var);
        temp_init = subs(subs(joint(j_count).dof(nj_dof).spring.init(n_mesh,:), q, q0), par.sym, par.var);
        plot(temp_init_s(1,:), temp_init(1,:), 'xr'); hold on
        % spring fit
        s_check = linspace(temp_init_s(1,1), temp_init_s(1,end), par.n_int);
        rom_check = subs(subs(subs(subs(joint(j_count).dof(nj_dof).spring.init_rom_series{n_mesh}(end), q, q0), par.sym, par.var), sw, s), s, s_check);
        plot(s_check, rom_check, '--r');
        legend( 'segment init' , 'segment fit' , 'body fit' , 'spring init' , 'spring fit' ) ;
    end
    % report
    fprintf( 'Interpolation check! Press any key to continue... \n' )
    pause
end


