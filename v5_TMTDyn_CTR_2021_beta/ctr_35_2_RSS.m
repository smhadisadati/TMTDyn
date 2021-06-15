%% initialize
close all
clear all
format shorte
clc
pause( 1 )

addpath('./tmtdyn','./tmtdyn/sundials_matlab','./tmtdyn/radau','./tmtdyn/funcs','./hll','./eom');


%% parameters
n_diffOrder = 3 ; % polynomial order
n_tube = 2 ;
spline_growth = 200 ;
l_bs = [ 42, 136, 0 ] * 1e-3; % steel part of the base (no twist assumption)
l_0 = [ 275, 311, 0 ] * 1e-3 ; % overal nitinol length
l_b = [ 194, 168, 0 ] * 1e-3 ; % experiment base length: [most outer (1), ..., most inner (n)], has no effect on IC
l_s = l_0 - l_b  % experiment curved length
l_b0 = [ 166, 200, 0 ] * 1e-3 ; % relaxed state base (straight section) length
l_s0 = l_0 - l_b0  % relaxed state curve length
% kappa = [ 1/130.7, 1/88.1, 0 ] * 1e3 ;
kappa = [ 1, 1, 0 ] ; % kappa curve coeff
r_s = 0.5 * ... % tube 1 outer [ inner outer ] radius
        [ 1.37, 1.78 ;
           0.7,  1.1 ;
             0,    0 ] * 1e-3 ; % tube 3 inner

g_x = -9.81 ; g_y = 0 ; g_z = 0 ; % gravity
sigma_s = 6450 ; % nitinol tube density

E_s = 1*[ 80, 90, 60 ] * 1e9 ; % Mohsen: 30 or [10,69,17] GPa, Zisis: 60 MPa, web: 28(cold)-75(hot) GPa 
G_s = 1*[ 72, 81, 20 ] * 1e9 ;
% G_s = E_s / 3;

mu_pow = 1 ; % < 1: rate thining, > 1: rate thikening
mu_E = 1*[ 90, 4.5, 60 ] * 1e9 ;
mu_G = 1*[ 80, 4, 60 ] * 1e9 ;
% mu_E = 1e-2 * E_s ; % proportional damping
% mu_G = 1e-2 * G_s;
mu_x = mu_G ; mu_y = mu_G ; mu_z = mu_E ;
mu_xx = mu_E ; mu_yy = mu_E ; mu_zz = mu_G ;


%% exp. readings
exp_case = 1;
[motor_in, tip_pos] = exp_v0(exp_case);


%% variables
syms s sigma_s_ E_s1_ E_s2_ E_s3_ G_s1_ G_s2_ G_s3_ ...
    r_s11_ r_s12_ r_s21_ r_s22_ r_s31_ r_s32_ ...
    mu_x1_ mu_y1_ mu_z1_ mu_xx1_ mu_yy1_ mu_zz1_ ...
    mu_x2_ mu_y2_ mu_z2_ mu_xx2_ mu_yy2_ mu_zz2_ ...
    mu_x3_ mu_y3_ mu_z3_ mu_xx3_ mu_yy3_ mu_zz3_ ...
    mu_pow_ g_xsym g_ysym g_zsym...
    l_b1_ l_b2_ l_b3_ l_s1_ l_s2_ l_s3_ ...
    kappa1_ kappa2_ kappa3_ growth_ ...
    dl1_ dl2_ dl3_ ...
    f_u1_ tau_u2_ f_u3_ tau_u4_ f_u5_ tau_u6_ ...
    f_tx_ f_ty_ f_tz_ tau_tx_ tau_ty_ tau_tz_ real
vars = [ sigma_s_ E_s1_ E_s2_ E_s3_ G_s1_ G_s2_ G_s3_ ...
    r_s11_ r_s12_ r_s21_ r_s22_ r_s31_ r_s32_ ...
    mu_x1_ mu_y1_ mu_z1_ mu_xx1_ mu_yy1_ mu_zz1_ ...
    mu_x2_ mu_y2_ mu_z2_ mu_xx2_ mu_yy2_ mu_zz2_ ...
    mu_x3_ mu_y3_ mu_z3_ mu_xx3_ mu_yy3_ mu_zz3_ ...
    mu_pow_ g_xsym g_ysym g_zsym ...
    l_b1_ l_b2_ l_b3_ l_s1_ l_s2_ l_s3_ ...
    kappa1_ kappa2_ kappa3_ growth_ ] ;
control_vars = [ dl1_ dl2_ dl3_ ...
    f_u1_ tau_u2_ f_u3_ tau_u4_ f_u5_ tau_u6_ ...
    f_tx_ f_ty_ f_tz_ tau_tx_ tau_ty_ tau_tz_ ] ;

var_vals = [sigma_s, E_s(1), E_s(2), E_s(3), G_s(1), G_s(2), G_s(3), r_s(1,1), r_s(1,2), r_s(2,1), r_s(2,2), r_s(3,1), r_s(3,2), ...
    mu_x(1), mu_y(1), mu_z(1), mu_xx(1), mu_yy(1), mu_zz(1), mu_x(2), mu_y(2), mu_z(2), mu_xx(2), mu_yy(2), mu_zz(2), mu_x(3), mu_y(3), mu_z(3), mu_xx(3), mu_yy(3), mu_zz(3), ...
    mu_pow, g_x, g_y, g_z, l_b(1) , l_b(2) ,l_b(3) ,l_s(1), l_s(2), l_s(3), kappa(1), kappa(2), kappa(3), spline_growth] ;
control_var_vals = [0, 1e-3, 0, zeros(1,12)] ; % dl2 = 1e-3 to avoid vanishing states and hense singularity

user_pars.n_t= n_diffOrder ;
user_pars.motor_in = motor_in ;
user_pars.tip_pos = tip_pos ;


%% simplified variables
% syms dl1_ dl2_ dl3_ ...
%     f_u1_ tau_u2_ f_u3_ tau_u4_ f_u5_ tau_u6_ ...
%     f_tx_ f_ty_ f_tz_ tau_tx_ tau_ty_ tau_tz_ real
% control_vars = [ dl1_ dl2_ dl3_ ...
%     f_u1_ tau_u2_ f_u3_ tau_u4_ f_u5_ tau_u6_ ...
%     f_tx_ f_ty_ f_tz_ tau_tx_ tau_ty_ tau_tz_ ] ;
% 
% control_var_vals = zeros(1,15) ;
% user_pars.n_t = n_diffOrder ;
% user_pars.motor_in = motor_in ;
% 
% g_xsym = g_x; g_ysym = g_y; g_zsym = g_z; sigma_s_ = sigma_s ;
% r_s11_ = r_s(1,1); r_s12_ = r_s(1,2); r_s21_ = r_s(2,1); r_s22_ = r_s(2,2); r_s31_ = r_s(3,1); r_s32_ = r_s(3,2);
% 
% E_s1_ = E_s(1); E_s2_ = E_s(2); E_s3_ = E_s(3); 
% G_s1_ = G_s(1); G_s2_ = G_s(2); G_s3_ = G_s(3);
% mu_x1_ = mu_x(1); mu_y1_ = mu_y(1); mu_z1_ = mu_z(1);
% mu_x2_ = mu_x(2); mu_y2_ = mu_y(2); mu_z2_ = mu_z(2);
% mu_x3_ = mu_x(3); mu_y3_ = mu_y(3); mu_z3_ = mu_z(3);
% mu_xx1_ = mu_xx(1); mu_yy1_ = mu_yy(1); mu_zz1_ = mu_zz(1);
% mu_xx2_ = mu_xx(2); mu_yy2_ = mu_yy(2); mu_zz2_ = mu_zz(2);
% mu_xx3_ = mu_xx(3); mu_yy3_ = mu_yy(3); mu_zz3_ = mu_zz(3);
mu_pow_  = mu_pow;
growth_ = spline_growth ;

% l_s1_ = l_s(1) ; l_s2_ = l_s(2) ; l_s3_ = l_s(3) ;
% l_b1_ = l_b(1) ; l_b2_ = l_b(2) ; l_b3_ = l_b(3) ;


%% preprocess
r_s_ = [ r_s11_, r_s12_; r_s21_, r_s22_ ; r_s31_, r_s32_ ];
l_s_ = [ l_s1_, l_s2_, l_s3_ ];
l_b_ = [ l_b1_, l_b2_, l_b3_ ];
E_s_ = [ E_s1_, E_s2_, E_s3_ ] ;
G_s_ = [ G_s1_, G_s2_, G_s3_ ] ;
mu_x_ = [ mu_x1_, mu_x2_, mu_x3_ ];
mu_y_ = [ mu_y1_, mu_y2_, mu_y3_ ];
mu_z_ = [ mu_z1_, mu_z2_, mu_z3_ ];
mu_xx_ = [ mu_xx1_, mu_xx2_, mu_xx3_ ];
mu_yy_ = [ mu_yy1_, mu_yy2_, mu_yy3_ ];
mu_zz_ = [ mu_zz1_, mu_zz2_, mu_zz3_ ];

for i = 1 : n_tube % # of tubes
    % bent part
    a_aw = pi * ( r_s_(i,2).^ 2 - r_s_(i,1).^ 2 ) ; % no change
    m_ss(i) = a_aw * sigma_s_ ;  % manipulator mass
    I_aw =  [ 1 1 2 ] * 1 / 4 * pi * ( r_s_(i,2).^ 4 - r_s_(i,1).^ 4 ) ;
    K_v(i,:) = ( [ G_s_(i) G_s_(i) E_s_(i) ] ) * a_aw ; % to get deformation not strain 
    K_u(i,:) = ( [ E_s_(i) E_s_(i) G_s_(i) ] ) .* ( I_aw ) ; % to get angles not curvatures/torsion 
    mu_v(i,:) = ( [ mu_x_(i) mu_y_(i) mu_z_(i) ] ) * a_aw ; % to get deformation not strain 
    mu_u(i,:) = ( [ mu_xx_(i) mu_yy_(i) mu_zz_(i) ] ) .* ( I_aw ) ; % ( l_ss / lambda_ ) to get angles not curvatures/torsion
    I_ss(:,:,i) = diag( sigma_s_ * pi * (r_s_(i,2).^2-r_s_(i,1).^2) * ...
                        [ 1/12*3*(r_s_(i,2).^2+r_s_(i,1).^2) , ...
                          1/12*3*(r_s_(i,2).^2+r_s_(i,1).^2) , ...
                          1/2*(r_s_(i,2).^2+r_s_(i,1).^2) ] ) ; % manipulator segment inertia

    % base part
    a_bw = pi * ( r_s_(i,2).^ 2 - r_s_(i,1).^ 2 ) ; % no change
    m_bs(i) = a_bw * sigma_s_ ;  % manipulator mass
    I_bw =  [ 1 1 2 ] * 1 / 4 * pi * ( r_s_(i,2).^ 4 - r_s_(i,1).^ 4 ) ;
    K_bv(i,:) = ( [ G_s_(i) G_s_(i) E_s_(i) ] ) * a_bw ;
    K_bu(i,:) = ( [ E_s_(i) E_s_(i) G_s_(i) ] ) .* ( I_bw ) ;
    mu_bv(i,:) = ( [ mu_x_(i) mu_y_(i) mu_z_(i) ] ) * a_bw ; % to get deformation not strain 
    mu_bu(i,:) = ( [ mu_xx_(i) mu_yy_(i) mu_zz_(i) ] ) .* ( I_bw ) ; % ( l_ss / lambda_ ) to get angles not curvatures/torsion
    I_bs(:,:,i) = diag( sigma_s_ * pi * (r_s_(i,2).^2-r_s_(i,1).^2) * ( ... % COM (joint location) is mid link
                        [ 1/12*3*(r_s_(i,2).^2+r_s_(i,1).^2) , ...
                          1/12*3*(r_s_(i,2).^2+r_s_(i,1).^2) , ...
                          1/2*r_s_(i,2).^2+r_s_(i,1).^2 ] ) ) ; % manipulator segment inertia
end
ftau_u = [ f_u1_ tau_u2_ f_u3_ tau_u4_ f_u5_ tau_u6_ ] ; % input loads, p is input torsion


%% initial state:
% tube 1 middle:
i_knot = [11, 11]; % knot index in tube data
tube{1}(1,:) = linspace( 0, l_0(1), 18) ; % middle
tube{1}(2,:) = [0,  0,     0,    0,   0,     0,    0,     0,     0,  0,     0,     0.64,  2.5,   6.11,   12,     20,    30.2,  42] * 1e-3 ; % x
tube{1}(4,:) = [42, 58.13, 74.3, 90.4 106.5, 122.6 138.8, 154.9, 171 187.2, 203.3, 219.4, 235.4, 251.14, 266.15, 280.1, 292.7, 303.6] * 1e-3 - l_bs(1) ; % z

% plot(tube{1}(2,:),tube{1}(4,:))
dzdx = [0, diff(tube{1}(4,:)) ./ diff(tube{1}(2,:))];
ddzdx = [0, diff(dzdx) ./ diff(tube{1}(2,:))];
kappa_v = abs(ddzdx) ./ ( 1 + dzdx.^2 ).^1.5;
kappa_m = mean( kappa_v(14:end) )
% plot(tube{1}(1,14:end)-tube{1}(1,14),kappa_v(14:end)); hold on
kappa_s{1} = - 49*s + 14;
% kappa_s{1} = 4.9e4*s^3 - 6.1e3*s^2 + 1.5e2*s + 13;
% kappa_s{1} = - 7.1e6*s^4 + 9.7e5*s^3 - 4.3e4*s^2 + 5.8e2*s + 13;
kappa_s{1} = kappa1_ * kappa_s{1} ;

% tube 2 inner-longer:
tube{2}(1,:) = linspace( 0, l_0(2), 20) ; % inner
tube{2}(2,:) = [0,   0,     0,     0,     0,     0,   0,     0,     0,     0,     0,   0.06,  1,     3,     6.61,  12.5,  21,  32.1,  45.8,  61.3] * 1e-3 ; % x
tube{2}(4,:) = [136, 152.4, 168.8, 185.2, 201.5, 218, 234.3, 250.7, 267.1, 283.5, 300, 316.3, 332.7, 348.9, 364.8, 380.1, 394, 406.1, 415.1, 419.9] * 1e-3 - l_bs(2) ; % z

% plot(tube{2}(2,:),tube{2}(4,:))
dzdx = [0, diff(tube{2}(4,:)) ./ diff(tube{2}(2,:))];
ddzdx = [0, diff(dzdx) ./ diff(tube{2}(2,:))];
kappa_v = abs(ddzdx) ./ ( 1 + dzdx.^2 ).^1.5;
kappa_m = mean( kappa_v(14:end) )
% plot(tube{2}(1,14:end)-tube{2}(1,14),kappa_v(14:end)); hold on
kappa_s{2}{1} = 1.1e2*s + 9.5;
% kappa_s{2}{1} = - 5.3e2*s^2 + 1.6e2*s + 8.8;
kappa_s{2}{1} = kappa2_ * kappa_s{2}{1} ;
kappa_s{2}{2} = subs( kappa_s{2}{1}, s, s+l_s1_+ftau_u(1) );

for i = 1 : n_tube % # of tubes
    sp_knot(i) = tube{i}(1,i_knot(i)) ;
    s_0{i} = tube{i}(1,:);
    rho_0{i} = tube{i}(2:4,:);
end

% CC init. shape
for i = 1 : n_tube % # of tubes
    s_c0{i} = [ linspace( 0, 1, 6 )*l_b0(i), l_b0(i)+linspace( 0, 1, 6 )*l_s0(i) ] ;
    theta_c0(i,:) = [ linspace( 0, 1, 6 )*0, linspace( 0, 1, 6 )*kappa(i)*l_s0(i) ];
    rho_c0{i}(:,:) = [ ( 1-cos( theta_c0(i,:) ) )/kappa(i) ;
                      0*theta_c0(i,:);
                     linspace( 0, 1, 6 )*l_b0(i), l_b0(i)+sin( linspace( 0, 1, 6 )*kappa(i)*l_s0(i) )/kappa(i) ] ; % should include s=0 if init_s is not defined
end

% sim. init. states
kappa = [ 1/131, 1/88 ] * 1e3 ;
for i = 1 : n_tube % # of tubes
    s_a0{i} = s_0{i} ;
    rho_a0{i}(3,:) = s_a0{i}; % straight IC
    % rho_a0{i} = rho_0{i} ; % conforming to a tube relaxed states
end


% t_equil = [2.3, 8.5, 16.7, 22, 38.1, 43.1];
% t_init = [0, 6.1, 12, 33.7, 52];
%% robot
results = ...
    tmtdyn()...
        .simulation()...
            .variables(vars, var_vals)...
          .control_variables(control_vars, control_var_vals)...
            .user_parameters(user_pars)...
            .derive_eom('no')... % 'full_system', 'assume_small_velocities', 'no'
                .plot_initial_conditions('final')... % 'all', 'final'
                .free_up_memory()...
                .optimize_code()...
            .analysis()...
                ...static_sim('generate_mex_file', [2.55, 9.15, 18, 41])... % edited_m_file, generate_m_file, generate_mex_file, old_mex_file, generate_mex_from_edited_m_file, generate_mex_from_c_files
                .dynamic_sim('generate_mex_from_c_files', 'external', 0, 52.62)... % matlab, sundials_ode, sundials_dae, radau, radau_mex, external
                .results_sample_rate(1e2)...
                .spatial_integration_step(1e1)...
            .post_process()...
                .animate('line', 'show_frame', 30, 20, 20)... % ({null 'none', 'show_frame', 'side_views', 'show_frame_side_views'}, fps, axis edges, cross-section edges) 
                .record_video()...
                .number_of_reports(1)...
                .run_user_code();
results = results... % to prevent matlab error for complex argument
        .world()... % world
            .g([g_xsym, g_ysym, g_zsym])...
        .robot('CTR')... % robot
            .body('tube_2_inner')...
                .with_mass(m_ss(2))...
                .with_inertia(I_ss(:,:,2))...
                .with_cross_section_radius(r_s_(2,2))...
                .connected_to_repeated_joint(1:3)...
                    .rom()...
                        .default_order(n_diffOrder)...
                        .length([ l_b2_; l_s1_+ftau_u(1); l_s2_+ftau_u(3)] ...
                              - [ftau_u(3);                  0; l_s1_+ftau_u(1)])... % end s_t, all start from s_b=0
                        .fixed_inital_values()...
                    .with_transformation_from_body()...
                        .translation([inf, inf, inf])...
                            .dof(1)...
                                .element_base_value(1, 0)... % no lateral motion at base
                                .element_base_director(1, 0)... % prependicular at base
                                .element_set_rom_coefficient(1, 3, 0)... % no shear strain for this part
                                .element_set_rom_coefficient(1, 4, 0)... % no shear strain for this part                           
                                .element_coefficient_similar_to_dof_at_tip(2:3, 1, 1, 1, 1, [1;2])... % [n_copy, n_coeff, coeff, i_joint, i_dofAxis, i_copy]
                                .element_coefficient_similar_to_dof_derivative_at_tip(2:3, 2, 1, 1, 1, 1, [1;2])... % [n_copy, n_coeff, n_diffOrder, coeff, i_joint, i_dofAxis, i_copy]
                            .dof(2)...
                                .element_base_value(1, 0)... % no lateral motion at base
                                .element_base_director(1, 0)... % prependicular at base
                                .element_set_rom_coefficient(1, 3, 0)... % no shear strain for this part
                                .element_set_rom_coefficient(1, 4, 0)... % no shear strain for this part
                                .element_coefficient_similar_to_dof_at_tip(2:3, 1, 1, 1, 2, [1;2])... % [n_copy, n_coeff, coeff, i_joint, i_dofAxis, i_copy]
                                .element_coefficient_similar_to_dof_derivative_at_tip(2:3, 2, 1, 1, 1, 2, [1;2])... % [n_copy, n_coeff, n_diffOrder, coeff, i_joint, i_dofAxis, i_copy]
                            .dof(3)...
                                .initial_value([[ftau_u(3);                    l_b2_; l_b2_+l_s1_+ftau_u(1)],...
                                                [ l_b2_; l_b2_+l_s1_+ftau_u(1); l_b2_+l_s2_+ftau_u(3)]])... % going to be straight
                                .element_base_value(1, ftau_u(3))... % base translational input
                                .element_base_director(1, 1)... % prependicular at base
                                .element_set_rom_coefficient(1, 3, 0)... % no shear strain for this part
                                .element_set_rom_coefficient(1, 4, 0)... % no shear strain for this part                               
                                .element_coefficient_similar_to_dof_at_tip(2:3, 1, 1, 1, 3, [1;2])... % [n_copy, n_coeff, coeff, i_joint, i_dofAxis, i_copy]
                                .element_coefficient_similar_to_dof_derivative_at_tip(2:3, 2, 1, 1, 1, 3, [1;2])... % [n_copy, n_coeff, n_diffOrder, coeff, i_joint, i_dofAxis, i_copy]
                        .rot_simple_curvilinear_frame([0, 0, 1])...
                        .rot_z()...
                            .element_base_value(1, ftau_u(4))...
                            .element_coefficient_similar_to_dof_at_tip(2:3, 1, 1, 1, 4, [1;2])... % [n_copy, n_coeff, coeff, i_joint, i_dofAxis, i_copy]
                            .element_coefficient_similar_to_dof_derivative_at_tip(2:3, 2, 1, 1, 1, 4, [1;2])... % [n_copy, n_coeff, n_diffOrder, coeff, i_joint, i_dofAxis, i_copy]
                        .beam_stiffness()...
                            .coefficient([ K_v(2,:) K_u(2,:) ])...
                            .relaxed_state([0, 0, 1, 0, 0, 0; 0, 0, 1, 0, kappa_s{2}{1}, 0; 0, 0, 1, 0, kappa_s{2}{2}, 0])...
                        .beam_damping()...
                            .viscosity([ mu_v(2,:) mu_u(2,:) ])...
                            .power(mu_pow_);
results = results... % to prevent matlab error for complex argument
            .body('tube_1_outer')...
                .with_mass(m_ss(1))...
                .with_inertia(I_ss(:,:,1))...
                .with_cross_section_radius(r_s_(1,2))...
                .connected_to_repeated_joint(1:2)...
                    .rom()...
                        .default_order(n_diffOrder)...
                        .length([-ftau_u(3)+l_b2_-l_b1_+ftau_u(1); 0] , ... % start s_b
                                [ l_b2_; l_s1_+ftau_u(1)] ... % end s_t
                              - [ftau_u(3);                  0])...
                        .fixed_inital_values()...
                    .with_transformation_from_body()...
                        .translation([inf, inf, inf])...
                            .dof(1)...
                                .element_similar_to_dof(1:2, 1, 1, 1, [1;2])... % (n_copy, coeff, i_joint, i_dofAxis, i_copy)
                            .dof(2)...
                                .element_similar_to_dof(1:2, 1, 1, 2, [1;2])... % (n_copy, coeff, i_joint, i_dofAxis, i_copy)
                            .dof(3)...
                                .element_similar_to_dof(1:2, 1, 1, 3, [1;2])... % (n_copy, coeff, i_joint, i_dofAxis, i_copy)
                        .rot_simple_curvilinear_frame([0, 0, 1])...
                        .rot_z()...
                            .axial_offset(-(-ftau_u(3)+l_b2_-l_b1_+ftau_u(1))*[1; 0])... % only for 1st element that s_b~=0
                            .element_base_value(1, ftau_u(2))... % SO INT. RANGE SHOULD START FROM 0!!!
                            .element_coefficient_similar_to_dof_at_tip(2, 1, 1, 2, 4, 1)... % [n_copy, n_coeff, coeff, i_joint, i_dofAxis, i_copy]
                            .element_coefficient_similar_to_dof_derivative_at_tip(2, 2, 1, 1, 2, 4, 1)... % [n_copy, n_coeff, n_diffOrder, coeff, i_joint, i_dofAxis, i_copy]
                        .beam_stiffness()...
                            .coefficient([ K_v(1,:) K_u(1,:) ])...
                            .relaxed_state([0, 0, 1, 0, 0, 0; 0, 0, 1, 0, kappa_s{1}, 0])...
                        .beam_damping()...
                            .viscosity([ mu_v(1,:) mu_u(1,:) ])...
                            .power(mu_pow_)...
        .run();
    
    