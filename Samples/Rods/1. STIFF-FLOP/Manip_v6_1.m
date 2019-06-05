%% initialize

clc
clear all
close all
format shorte

addpath('./code');
world = [] ; body = [] ; joint = [] ; % defaults
exload = [] ; pack = [] ;
par.sym = [] ; par.timer = tic ; par.elapsed_time = [] ;

fprintf( 'start... \n' )
par.elapsed_time = [ par.elapsed_time toc( par.timer ) ] ;
toc( par.timer )

pause( 1e-2 )


%% initialization
% study specific parameters
study = 2 ; % 1: ROM, 2: Series Rigid Link (SRL), 3: Discretized Relative States (EBR), 4: Discretized Absolute States (EBA)
exp_case = [ 1 1 inf ] ; % [ case star_sequence end_sequence ]

% derivation
par.derive = 1 ; % set 1 to rederive in TMT
par.derive_collect = 1 ; % collect in 1: single struct., 2: seperte struct.s, 3: seperate func.s, 4: C func.s
par.derive_mex = 0 ; % use Matlab codegen, automatically sets par.derive_collect = 1
par.opv = true ; % optimize results

% controls
par.Anim = 0 ; % animation on (1) or off (0)
par.movie = 0 ; % save movie[ ~ , rks , par ] = AnimEOM_mex( t , z , par );
par.equil = 0 ; % 1: static analysis with Matlab func.s, 2: with C-mex func.s
par.modal = 0 ; % 1: linear modal analysis with Matlab func.s, 2: with C-mex func.s
par.simdyn = 0 ; % 1: dyn. sim. with Matlab func.s, 2: with C-mex func.s

% other parameters
par.t_rep = 5e-1 ; % sim report time
par.n_int = 100 ; % number of integration steps
par.n_animpoints = 50 ; % number of anim points
par.n_datasample = 50 ; % number of saved data samples
dt_anim_rep = [ inf 1 ] ; % anim report time, if 'inf' then (tf-t0)/dt_animStep(2)

% variables
if par.derive == 1
    syms sigma_s_sym E_s_sym r_s1_sym r_s2_sym r_p1_sym l_s_sym mu_x_sym mu_y_sym mu_z_sym mu_xx_sym mu_yy_sym mu_zz_sym mu_pow_sym g_xsym g_ysym g_zsym lambda_sym  m_f_sym l_f_sym r_f_sym r_o_sym gamma_sym p1_sym p2_sym p3_sym p4_sym p5_sym p6_sym f_tx_sym f_ty_sym f_tz_sym tau_tx_sym tau_ty_sym tau_tz_sym
    par.sym = [ sigma_s_sym E_s_sym r_s1_sym r_s2_sym l_s_sym mu_x_sym mu_y_sym mu_z_sym ...
        mu_xx_sym mu_yy_sym mu_zz_sym mu_pow_sym g_xsym g_ysym g_zsym  m_f_sym l_f_sym r_f_sym ...
        r_p1_sym r_o_sym gamma_sym p1_sym p2_sym p3_sym p4_sym p5_sym p6_sym f_tx_sym f_ty_sym ...
        f_tz_sym tau_tx_sym tau_ty_sym tau_tz_sym lambda_sym ] ;
    assume( par.sym , 'real' ) ;
else
    sigma_s_sym = 0 ; E_s_sym = 0 ; r_s1_sym = 0 ; r_s2_sym = 0 ; l_s_sym = 0 ; r_p1_sym = 0 ; r_o_sym = 0 ; gamma_sym = 0 ;
    mu_x_sym = 0 ; mu_y_sym = 0 ; mu_z_sym = 0 ; mu_xx_sym = 0 ; mu_yy_sym = 0 ; mu_zz_sym = 0 ; mu_pow_sym = 1 ;
    g_xsym = 0 ; g_ysym = 0 ; g_zsym = 0 ; lambda_sym = 1 ; m_f_sym = 0 ; l_f_sym = 0 ; r_f_sym = 0 ;
    p1_sym = 0 ; p2_sym = 0 ; p3_sym = 0 ; p4_sym = 0 ; p5_sym = 0 ; p6_sym = 0 ;
    f_tx_sym = 0 ; f_ty_sym = 0 ; f_tz_sym = 0 ; tau_tx_sym = 0 ; tau_ty_sym = 0 ; tau_tz_sym = 0 ;
end


%% parameters
l_s = 50e-3 ; %44e-3 ; % manipulator length
r_s1 = 4.5e-3 ; % manipulator inner radius
r_s2 = 12.5e-3 ; % manipulator outer radius
r_p1 = 2.5e-3 ; % 2.25e-3 pressure chamber inner radius
r_p2 = 3e-3 ; % pressure chamber outer radius
r_t = 0.2e-3 ; % braid diameter
gamma = pi / 2 - acos( 1 - r_t ^ 2 / 2 / r_p2 ^ 2 ) ;
r_o = 8.5e-3 ; %8.4e-3
phi_o = acos( 1 - r_p2 ^ 2 / 2 / r_o ^ 2 ) ;
r_od = [ cos( 3*pi/6 + phi_o )  sin( 3*pi/6 + phi_o )  0 ; % according to Ali's inputs
         cos( 3*pi/6 - phi_o )  sin( 3*pi/6 - phi_o )  0 ;
         cos( -pi/6 + phi_o )   sin( -pi/6 + phi_o )   0 ;
         cos( -pi/6 - phi_o )   sin( -pi/6 - phi_o  )  0 ;
         cos( 7*pi/6 + phi_o )  sin( 7*pi/6 + phi_o )  0 ;
         cos( 7*pi/6 - phi_o )  sin( 7*pi/6 - phi_o )  0 ] ;

m_f = 13.47e-3 ; % force sensor and its mount mass
l_f = 14.5e-3 ; %17e-3 ;
r_f = 7.5e-3 ;

g_x = 0 ; g_y = 0 ; g_z = 9.81 ; % gravity
sigma_s = 1.4 * 1300 ; % silicon density

switch study    
    case 1 % ROM
        n_r = 5 ; % ROM polynomial order
        E_s =205e3 ; % 130e3, 205e3        
        mu_pow = 2 ; % < 1: rate thining, > 1: rate thikening
        mu_x = 1e-1 ; % 1e-1
        mu_y = 1e-1 ;
        mu_z = 1e-1 ;
        mu_xx = 1e-5 ; % 1e-4
        mu_yy = 1e-5 ;
        mu_zz = 1e-5 ;

    case 2 % SRL
        n_s = 3 ; % manipulator segments
        E_s =205e3 ; % 130e3, 205e3        
        mu_pow = 2 ; % < 1: rate thining, > 1: rate thikening
        mu_x = 1e-1 ; % 1e-1
        mu_y = 1e-1 ;
        mu_z = 1e-1 ;
        mu_xx = 1e-5 ; % 1e-4
        mu_yy = 1e-5 ;
        mu_zz = 1e-5 ;
        
    case 3 % EBR
        n_s = 5 ; % manipulator segments
        E_s =205e3 ; % 130e3, 205e3        
        mu_pow = 2 ; % < 1: rate thining, > 1: rate thikening
        mu_x = 1e2 ; % 1e-1
        mu_y = 1e2 ;
        mu_z = 1e2 ;
        mu_xx = 5e-1 ; % 1e-4
        mu_yy = 5e-1 ;
        mu_zz = 5e-1 ;
        
    case 4 % EBA
        n_s = 6 ; % manipulator segments
        E_s =205e3 ; % 130e3, 205e3        
        mu_pow = 2 ; % < 1: rate thining, > 1: rate thikening
        mu_x = 1e2 ; % 1e-1
        mu_y = 1e2 ;
        mu_z = 1e2 ;
        mu_xx = 1e-2 ; % 1e-4
        mu_yy = 1e-2 ;
        mu_zz = 1e-2 ;
        
end

par.var = [ sigma_s, E_s, r_s1, r_s2, l_s, mu_x, mu_y, mu_z, mu_xx, mu_yy, ...
    mu_zz, mu_pow, g_x, g_y, g_z, m_f, l_f, r_f, r_p1, r_o, gamma, zeros(1,12) , 1 ] ;


%% derivation simplification
sigma_s_sym = sigma_s ; E_s_sym = E_s; r_s1_sym = r_s1; r_s2_sym = r_s2;
l_s_sym = l_s ; mu_x_sym = mu_x; mu_y_sym = mu_y; mu_z_sym = mu_z;
mu_xx_sym = mu_xx; mu_yy_sym = mu_yy; mu_zz_sym = mu_zz; mu_pow_sym  = mu_pow;
g_xsym = g_x; g_ysym = g_y; g_zsym = g_z; m_f_sym = m_f; l_f_sym = l_f;
r_f_sym = r_f; r_p1_sym = r_p1 ; r_o_sym = r_o; gamma_sym = gamma;
p2_sym = p1_sym; p4_sym = p3_sym; p6_sym = p5_sym;

%% preprocess
switch study    
    case 1 % ROM
        l_ss = l_s_sym / n_r ; % segment length
        a_aw = pi * ( r_s2_sym.^ 2 - r_s1_sym.^ 2 - 6 * r_p1_sym.^ 2 ) ; % no change
        m_s = a_aw * l_s_sym * sigma_s_sym ;  % manipulator mass
        r_ov = r_o_sym * r_od / sqrt( lambda_sym ) ;
        r_p1_sym = r_p1_sym * sqrt( 1 - lambda_sym.^ 2 * cos( gamma_sym ) ^ 2 ) / sin( gamma_sym ) ;
        a_p = pi * r_p1_sym.^ 2 ;
        a_aw = pi * ( ( r_s2_sym.^ 2 - r_s1_sym.^ 2 ) / lambda_sym - 6 * r_p1_sym.^ 2 ) ;
        m_ss = m_s / l_s_sym ; % manipulator segment mass
        G_s = E_s_sym / 3 ;
        I_aw =  [ 1 1 2 ] * 1 / 4 * pi * ( ( r_s2_sym.^ 4 - r_s1_sym.^ 4 ) / lambda_sym.^ 2 - 6 * r_p1_sym.^ 4 ) ...
                - a_p * diag( r_ov.' * r_ov ).' ;
        K_v = diag( [ G_s G_s E_s_sym ] ) * a_aw / lambda_sym ; % ( l_ss / lambda_sym ) to get deformation not strain 
        K_u = diag( [ E_s_sym E_s_sym G_s ] ) * diag( I_aw ) / lambda_sym ; % ( l_ss / lambda_sym ) to get angles not curvatures/torsion 
        I_ss = diag( ...
                     sigma_s_sym * pi * (r_s2_sym.^2-r_s1_sym.^2) * ...
                     [ 1/12*(3*(r_s2_sym.^2+r_s1_sym.^2))/lambda_sym , ...
                       1/12*(3*(r_s2_sym.^2+r_s1_sym.^2))/lambda_sym , ...
                       1/2*(r_s2_sym.^2+r_s1_sym.^2)/lambda_sym ] ) ; % manipulator segment inertia
        I_f = diag( [ 1/12*m_f_sym*(3*r_f_sym^2+l_f_sym.^2) 1/12*m_f_sym*(3*r_f_sym.^2+l_f_sym.^2) 1/2*m_f_sym*r_f_sym.^2 ]...
                    + m_f_sym * (l_f_sym/2).^2 * [ 1 1 0 ] ) ; % tip force sensor segment inertia
        p = [ p1_sym p2_sym p3_sym p4_sym p5_sym p6_sym ] ;
        f_p = [ 0 0 p*ones(6,1)*a_p ] ;
        tau_p = p * a_p * [ r_ov(:,2) -r_ov(:,1) r_ov(:,3) ] ;

    otherwise % discretized
        l_ss = l_s_sym / n_s ; % segment length
        a_aw = pi * ( r_s2_sym.^ 2 - r_s1_sym.^ 2 - 6 * r_p1_sym.^ 2 ) ; % no change
        m_s = a_aw * l_s_sym * sigma_s_sym ;  % manipulator mass
        r_ov = r_o_sym * r_od / sqrt( lambda_sym ) ;
        r_p1_sym = r_p1_sym * sqrt( 1 - lambda_sym.^ 2 * cos( gamma_sym ) ^ 2 ) / sin( gamma_sym ) ;
        a_p = pi * r_p1_sym.^ 2 ;
        a_aw = pi * ( ( r_s2_sym.^ 2 - r_s1_sym.^ 2 ) / lambda_sym - 6 * r_p1_sym.^ 2 ) ;
        m_ss = m_s / n_s ; % manipulator segment mass
        G_s = E_s_sym / 3 ;
        I_aw =  [ 1 1 2 ] * 1 / 4 * pi * ( ( r_s2_sym.^ 4 - r_s1_sym.^ 4 ) / lambda_sym.^ 2 - 6 * r_p1_sym.^ 4 ) ...
                - a_p * diag( r_ov.' * r_ov ).' ;
        K_v = diag( [ G_s G_s E_s_sym ] ) * a_aw / l_ss / lambda_sym ; % ( l_ss / lambda_sym ) to get deformation not strain 
        K_u = diag( [ E_s_sym E_s_sym G_s ] ) * diag( I_aw ) / l_ss / lambda_sym ; % ( l_ss / lambda_sym ) to get angles not curvatures/torsion 
        I_ss = diag( ... % COM (joint location) is mid link
                     sigma_s_sym * pi * (r_s2_sym.^2-r_s1_sym.^2) * l_ss * ( ...
                     [ 1/12*(3*(r_s2_sym.^2+r_s1_sym.^2)/lambda_sym+(l_ss*lambda_sym).^2) , ...
                       1/12*(3*(r_s2_sym.^2+r_s1_sym.^2)/lambda_sym+(l_ss*lambda_sym).^2) , ...
                       1/2*(r_s2_sym.^2+r_s1_sym.^2)/lambda_sym ] ) ) ; % manipulator segment inertia
        I_f = diag( [ 1/12*m_f_sym*(3*r_f_sym^2+l_f_sym.^2) 1/12*m_f_sym*(3*r_f_sym.^2+l_f_sym.^2) 1/2*m_f_sym*r_f_sym.^2 ]...
                    + m_f_sym * (l_f_sym/2).^2 * [ 1 1 0 ] ) ; % tip force sensor segment inertia
        p = [ p1_sym p2_sym p3_sym p4_sym p5_sym p6_sym ] ;
        f_p = [ 0 0 p*ones(6,1)*a_p ] ;
        tau_p = p * a_p * [ r_ov(:,2) -r_ov(:,1) r_ov(:,3) ] ;

end

%% system geomety
switch study
    
    case 1 % ROM
        world.g = [ g_xsym g_ysym g_zsym ] ; % gravity vector
        
        % manipulator segments
        i_b = 1 ;
        body(i_b).m = m_ss ; % differential mass
        body(i_b).I = I_ss ;
        
        % DOF: mesh par.s in column vec. form, other vectors in row vec. form
        i_j = i_b ;
        joint(i_j).second = [ 1 l_s_sym ].' ; % if Reduced Order Model (rom): [ a n ]: body a, n_dof is n
                                            % if connected to a mesh body: [ a vec ]: body a, mesh b, element number vec
                                            % if mesh: can be vec or column
        joint(i_j).rom.order = n_r ; % integration directions and bounds for reduces order model (rom)
        joint(i_j).tr.trans = [ inf inf inf ] ; % abs. xyz
        joint(i_j).tr.rot = [ 0 inf inf inf ] ; % quat. rot.s, rom should have quat
        % vx, vy, ux, uy, uz: default dof values
        % vz
        joint(i_j).dof(3).init = ( 1:n_r ) * l_ss ; % fit a polynomial of order n_s to these points
        % continous properties, needed if the joint is rom
        joint(i_j).spring.coeff = [ diag( K_v ).' diag( K_u ).' ] ; % 1x6 in local frame define by joint.tr
        joint(i_j).damp.visc = [ mu_x_sym mu_y_sym mu_z_sym mu_xx_sym mu_yy_sym mu_zz_sym ] ;
        joint(i_j).damp.pow = mu_pow_sym ; % power law index
        joint(i_j).input = [ f_p tau_p ] ;
        
        % tip force sensor
        i_b = i_b + 1 ;
        body(i_b).m =  m_f_sym ;
        body(i_b).I = I_f ;
        body(i_b).l_com = [ 0 0 l_f_sym/2 ] ;
        % joint
        i_j = i_j + 1 ;
        joint(i_j).first = [ 1 l_s_sym ].' ; % if connected to a single body in a mesh body: [ a b c ]: body a, mesh b, element number c
        joint(i_j).second = 2 ;
        
        % mesh import if any
        mesh = [] ;
        
        % external load if any
        % tip load
        exload(1).exbody = 2 ;
        exload(1).ftau = [ f_tx_sym f_ty_sym f_tz_sym tau_tx_sym tau_ty_sym tau_tz_sym ] ;
        exload(1).tr(1).trans = [ 0 0 l_f_sym ] ;

    case 2 % SRL
        world.g = [ g_xsym g_ysym g_zsym ] ; % gravity vector
        
        % manipulator segments
        i_b = 1 ;
        body(i_b).m = m_ss ;
        body(i_b).I = I_ss ;
        body(i_b).tip = [ 0 0 l_ss ] ;
        % COM at joint bu assumed to be mid link for calculating I
        
        % DOF
        K_uv = [ diag( K_v ).' K_u(3,3) diag( K_u(1:2,1:2) ).' ] ; % reorder for u_z u_x u_y
        mu_uv = [ mu_x_sym mu_y_sym mu_z_sym mu_zz_sym mu_xx_sym mu_yy_sym ] ;
        ftau_uv = [ f_p tau_p(3) tau_p(1:2) ] ;        
        i_j = i_b ;
        joint(i_j).first = [ 1 0:n_s-1 ]' ; % series links with rel. states
        joint(i_j).second = [ 1 1:n_s ]' ;
        joint(i_j).tr(1).trans = [ 0 0 l_ss ] ; % ( vz + 1 ) * dl
        joint(i_j).tr(2).trans = [ inf inf inf ] ; % abs. xyz
        joint(i_j).tr(2).rot = [ 3 inf ] ; % z Euler rot.s
        joint(i_j).tr(3).rot = [ 1 inf ] ; % x Euler rot.s
        joint(i_j).tr(4).rot = [ 2 inf ] ; % y Euler rot.s
        for i_d = 1 : 6
            joint(i_j).dof(i_d).spring.coeff = K_uv(i_d) ;
            joint(i_j).dof(i_d).damp.visc = mu_uv(i_d) ;
            joint(i_j).dof(i_d).damp.pow = mu_pow_sym ;
            joint(i_j).dof(i_d).input = ftau_uv(i_d) ;
        end
        
        % tip force sensor
        i_b = i_b + 1 ;
        body(i_b).m =  m_f_sym ;
        body(i_b).I = I_f ;
        body(i_b).l_com = [ 0 0 l_f_sym/2 ] ;
        % joint
        i_j = i_j + 1 ;
        joint(i_j).first = [ 1 n_s ]' ; % (not in main kin chain)- connects to a single body in a mesh body: [ a b ]: body a, element number b
        joint(i_j).second = 2 ;
        
        % mesh import if any
        mesh = [] ;
        
        % tip external load
        exload(1).exbody = 2 ;
        exload(1).ftau = [ f_tx_sym f_ty_sym f_tz_sym tau_tx_sym tau_ty_sym tau_tz_sym ] ;
        exload(1).tr(1).trans = [ 0 0 l_f_sym ] ;
        
    case 3 % EBR
        world.g = [ g_xsym g_ysym g_zsym ] ; % gravity vector
        
        % manipulator segments
        i_b = 1 ;
        body(i_b).m = m_ss ;
        body(i_b).I = I_ss ;
        body(i_b).tip = [ 0 0 l_ss ] ;
        % COM at joint bu assumed to be mid link for calculating I
        
        % DOF
        K_uv = [ diag( K_v ).' diag( K_u ).' ] ;
        mu_uv = [ mu_x_sym mu_y_sym mu_z_sym mu_xx_sym mu_yy_sym mu_zz_sym ] ;
        ftau_uv = [ f_p tau_p ] ;        
        i_j = i_b ;
        joint(i_j).first = [ 1 0:n_s-1 ]' ; % series links with rel. states
        joint(i_j).second = [ 1 1:n_s ]' ;
        joint(i_j).tr(1).trans = [ 0 0 l_ss ] ; % ( vz + 1 ) * dl
        joint(i_j).tr(2).trans = [ inf inf inf ] ; % abs. xyz
        joint(i_j).tr(2).rot = [ inf inf inf ] ; % EB beam rot.s
        % vx
        for i_d = 1 : 6
            joint(i_j).dof(i_d).spring.coeff = K_uv(i_d) ;
            joint(i_j).dof(i_d).damp.visc = mu_uv(i_d) ;
            joint(i_j).damp.pow = mu_pow_sym ;
            joint(i_j).dof(i_d).input = ftau_uv(i_d) ;
        end
        
        % tip force sensor
        i_b = i_b + 1 ;
        body(i_b).m =  m_f_sym ;
        body(i_b).I = I_f ;
        body(i_b).l_com = [ 0 0 l_f_sym/2 ] ;
        % joint
        i_j = i_j + 1 ;
        joint(i_j).first = [ 1 n_s ]' ; % (not in main kin chain)- connects to a single body in a mesh body: [ a b ]: body a, element number b
        joint(i_j).second = 2 ;
        
        % mesh import if any
        mesh = [] ;
        
        % tip external load
        exload(1).exbody = 2 ;
        exload(1).ftau = [ f_tx_sym f_ty_sym f_tz_sym tau_tx_sym tau_ty_sym tau_tz_sym ] ;
        exload(1).tr(1).trans = [ 0 0 l_f_sym ] ;
        
    case 4 % EBA
        world.g = [ g_xsym g_ysym g_zsym ] ; % gravity vector
        
        % manipulator segments
        i_b = 1 ;
        body(i_b).m = m_ss ;
        body(i_b).I = I_ss ;
        % COM at joint bu assumed to be mid link for calculating I
        
        % DOF
        i_j = i_b ;
        joint(i_j).second = [ 1 1:n_s ].' ; % (in main kin chain)- creats a mesh body: [ a b ]: body a, number of elements b
                                           % mesh par.s in column vec. form, other vectors in row vec. form
        joint(i_j).tr.trans = [ inf inf inf ] ; % abs. xyz
        joint(i_j).tr.rot = [ 0 inf inf inf ] ; % quat. rot.s
        % vx, vy, ux, uy, uz: default dof values
        % vz
        joint(i_j).dof(3).init = ( 1:n_s ).' * l_ss ;
        
        % intermediate beams
        i_j = i_j + 1 ;
        joint(i_j).first = [ 1 0:n_s-1 ].' ;
        joint(i_j).second = [ 1 1:n_s ].' ;
        joint(i_j).spring.coeff = [ diag( K_v ).' diag( K_u ).' ] ; % 1x6 in local frame define by joint.tr
        joint(i_j).spring.init = [ 0 0 nan 0 0 0 ] ; % [ init(1x6) , axial_comp_coeff(1x1) ]
        joint(i_j).damp.visc = [ mu_x_sym mu_y_sym mu_z_sym mu_xx_sym mu_yy_sym mu_zz_sym ] ;
        joint(i_j).damp.pow = mu_pow_sym ; % power law index
        joint(i_j).input = [ f_p tau_p ] ;
        
        % tip force sensor
        i_b = i_b + 1 ;
        body(i_b).m =  m_f_sym ;
        body(i_b).I = I_f ;
        body(i_b).l_com = [ 0 0 l_f_sym/2 ] ;
        % joint
        i_j = i_j + 1 ;
        joint(i_j).first = [ 1 n_s ].' ; % (not in main kin chain)- connects to a single body in a mesh body: [ a b ]: body a, element number b
        joint(i_j).second = 2 ;
        
        % mesh import if any
        mesh = [] ;
        
        % tip external load
        exload(1).exbody = 2 ;
        exload(1).ftau = [ f_tx_sym f_ty_sym f_tz_sym tau_tx_sym tau_ty_sym tau_tz_sym ] ;
        exload(1).tr(1).trans = [ 0 0 l_f_sym ] ;
        
end


%% EOM:
if par.derive == 1
    [ qf , uf , lambdaf , par ] = tmt_eom_derive ( par , world , body , joint , exload , mesh );
end


%% axp. inputs
par = exp_v0_1( par , exp_case ) ;


%% numerical simulation & animation
% sim pars:
par.t_init = par.t_exp(exp_case(2)) ;
if exp_case(3) == inf
    par.t_final = par.p(end,1) ;
    par.t_equil = par.t_exp_equil(exp_case(2):end) ;
else
    par.t_final = par.t_exp(exp_case(3)) ;
    par.t_equil = par.t_exp_equil(exp_case(2):exp_case(3)) ;
end
if par.simdyn ~= 0 % for static analysis
    par.t_equil = par.t_init ;
end
if isinf( dt_anim_rep(1) )
    dt_anim_rep(1) = ( par.t_final - par.t_init ) / dt_anim_rep(2) ;
end
par.dt = dt_anim_rep(1) ;
par.stepT = par.dt / ( ( 1 + floor( par.dt ) ) * par.n_datasample ) ; % sampling time to save data for
% par.stepT = 1e-3 ;
z0 = [] ;

% animation pars
par.fig.anim = figure ;
par.skip = floor( 1 / par.stepT / 25 ) ; % animation step skip: result in ~ 25 fps
par.animPause = 0 ; % 1: wait for user confirmation to show anim.
par.pause = 0 ; % animation frame pause time
if par.movie == 1
    par.vid = VideoWriter( 'code/results/video.avi' ) ;
    if par.t_final > 2 % avoid videos shorter than 2 [s]
        par.vid.FrameRate = 1 / par.stepT / par.skip ;
    else
        par.vid.FrameRate = 1 / par.stepT / par.skip * par.t_final / 2 ;
    end
    par.vid.Quality = 100 ;
    open( par.vid ) ;
end

% static solve for equlibrium:
z_all = z0 ;
i = 0 ;
for t_equil_i = par.t_equil
    i = i + 1 ;
    par.t_equil_i = t_equil_i ; % solve for this time step (use to extract data from exp.)
    [ z0 , par ] = equil( par ) ; % find static equlibrium
    [ ~ , rjtip_0 , ~ , par ] = anim( t_equil_i , z0 , par ) ; % plot equil.
    z_all(i,:) = z0 ;
    rjtip_all(:,:,i) = rjtip_0 ; t_all(i) = t_equil_i ; par.linetype = 'o' ;
    pause( 1e-2 ) ;
end

% linear modal analysis at equilibrium points:
if par.modal
    par.figmod = figure ;
    i = 0 ;
    for t_equil_i = par.t_equil
        i = i + 1 ;
        par.t_equil_i = t_equil_i ;
        [ Phi_modal , M_modal , K_modal , V_modal , omega , xi , par ] = modal( z_all(i,:) , par ) ;
        pause( 1e-2 ) ;
    end
end

% sim & anim.:
if par.simdyn ~= 0
    clf( par.fig.anim ) ; par.linetype = '-' ;
    t_all = [] ; z_all = [] ; rjtip_all = [] ;
    for t0_step = par.t_init : dt_anim_rep(1) : par.t_final - dt_anim_rep(1)
        % step sim:
        par.t0 = t0_step ;
        [ t , z , tfinal , par ] = sim_dyn( z0 , par ) ;
        
        % animation
        [ ~ , rjtip , ~ , par ] = anim( t , z , par ) ;
        
        % concatanate results
        t_all = [ t_all ; t(1:end-1) ] ;
        z_all = [ z_all ; z(1:end-1,:) ] ;
        rjtip_all = cat( 3 , rjtip_all , rjtip(:,:,1:end-1) ) ;
        z0 = z(end,:) ;
    end
    t_all = [ t_all ; t(end) ] ; % to include the last point
    z_all = [ z_all ; z(end,:) ] ;
    rjtip_all = cat( 3 , rjtip_all , rjtip(:,:,end) ) ;
end

if par.movie == 1 ; close( par.vid ) ; end

fprintf( 'sim. end... \n' )
par.elapsed_time = [ par.elapsed_time toc( par.timer ) ] ;


%% post process
post_proc( t_all , z_all , rjtip_all , par ) ;
pause( 1 )
save( 'code/results/results_sys.mat' ) ; % save workspace

