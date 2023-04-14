tmtdyn()...
	.simulation()...
		.var(symbolic_vars_vec, var_values_vec)...
		.variables(symbolic_vars_vec, var_values_vec)... % same as var
		.user_pars(value_vac)...
		.user_parameters(value_vac)... % same as user_pars
		.derive_eom(select)... % 'full_system', 'assume_small_velocities', 'no'
			.use_cpu_cores(core_no)...
			.use_single_cpu_core()...
			.collect_terms(collection_type)... % 'single_structures', 'separate_structures', 'separate_functions', 'C_functions', 'collect_most_terms'
			.simplify_derivations(select, duration_or_precision)... % select: 'symbolic' , 'decimal' , 'symbolic_decimal'
            .optimize_code()...
            .free_up_memory()...
			.assume_sparse_matrix()...
            .convert_piecewise_to_logistic_function()...
			.use_mex()... % use mex functions except for the final EOM function
            .plot_initial_conditions(select)... % 'all', 'final'; 'final' only plots the ROM elements & skips others!
		.analysis()...
			.static_sim(method, times_vec)... % method in {'generate_m_file', 'edited_m_file', 'generate_mex_file', 'old_mex_file', 'generate_mex_file_from_edited_m_file', 'generate_mex_from_c_files'}
			.dynamic_sim(method, solver, start_time, end_time)... % method in {'generate_m_file', 'edited_m_file', 'generate_mex_file', 'old_mex_file', 'generate_mex_file_from_edited_m_file', 'generate_mex_from_c_files'}
			...													  % solver in {'matlab', 'sundials_ode', 'sundials_dae', 'radau', 'radau_mex', 'external'}
			.modal(method, time_vec)... % method in {'generate_m_file', 'edited_m_file', 'generate_mex_file', 'old_mex_file', 'generate_mex_file_from_edited_m_file'}
			.report_time_intervals(time)...
			.spatial_integration_step(steps_int)...
			.results_sample_rate(rate_int)...
		.post_process()...
			.animate(body_type, anim_frame, fps, axis_edges, circle_edges)... % type = {'line', 'tube'}, anim_frame = {null 'none', 'show_frame', 'side_views', 'show_frame_side_views'}
			.axis_edges(axis_edges)... % number of edges to plot a tube back bone
            .cross_section_edges(circle_edges)... % number of edges to plot tube cross-section
			.record_video()...
			.run_user_code()...
			.report_time_step(report_time)...
			.number_of_reports(report_no)...		
	.world()...
		.g(gravity_vec)...
	.robot(name)...
		.body(name)...
			.with_mass(mass)...
			.with_inertia(inertia_matrix)...
            .with_cross_section_radius(radius)...
			.with_tip_at(tip_vec)... % position vector in local frame
			.with_center_of_mass_at(com_vec)... % position vector in local frame
			.connected_to_joint()... % >> joint()
			.connected_to_repeated_joint(1:mesh_no)... % >> joint()
		.joint(name)...
		.joint_with_repeated_elements(name, mesh_no)... % >> joint()
			.rom()...
                .default_fit_type(type, knots)... % sets both dof & spring, can be overriden later, type: {'polynomial', 'spline_piecewise', 'spline_logistic_func', 'spline_mesh'}
                .default_relaxed_state_fit_type(type, knots)... % sets only spring, type: {'polynomial', 'spline_piecewise', 'spline_logistic_func', 'spline_mesh'}
                .default_spline_growth_rate(growth_rate)...
                .use_default_spline_knots()... % override spline knots and conditioning logistic functions
                .default_axial_offset(offset)... % offset the integration range not the spline knots, doesn't changes spring_offset
                .default_relaxed_state_axial_offset(offset)... % offset the integration range not the spline knots, 
                .default_spline_continuity_order(value)...
                .default_order(order_int)...
                .growing_from(type)... % type in {'none', 'tip', 'base', 'sliding'}
				.length(length_i, length_e)... % start and end integration range
				.varies_with_dof(coeff,i_j, i_h, i_d)... % alternativly use trans_rom_axial() and then dof geom. const. routines
				.varies_with_dof_order(coeff, i_j, i_h, i_r, i_d)... % alternativly use trans_rom_axial() and then dof geom. const. routines
				.varies_with_dof_at_axial_location(coeff, i_j, i_h, l, i_d)... % alternativly use trans_rom_axial() and then dof geom. const. routines
				.varies_with_dof_at_tip(coeff, i_j, i_h, i_d)... % alternativly use trans_rom_axial() and then dof geom. const. routines
				.from_body_frame(condition)... % condition in {'relative', 'absolute'}
				.free_base()...
				.reference_axial_locations(val_vec)...
				.fixed_inital_values()...
				.stiffness_model(select)... % 'continuous', 'discretized'
				.spline_as_separate_bodies()... % model as one body or separate bodies
			.from_body(body_no, mesh_no, axial_loc)...
			.from_body_tip(body_no, mesh_no)...
			.to_body(body_no, mesh_no, axial_loc)...
			.to_body_tip(body_no, mesh_no)...
			.with_transformation_from_body(body_no, mesh_no, axial_loc)... % >> aka transformation(), pass no arguments for transformation from ground
				.translation(trans_vec)...
				.trans_x(val_or_inf)...
				.trans_y(val_or_inf)...
				.trans_z(val_or_inf)...
                .trans_curvilinear_axial()... % don't use with 'tip growing' if its is not fixed (results in zero column in TMT, i.e. singularity), doesn't support spline simplifications, e.g. multiple body
				.rotation_angle_axis(angle_axis_vec)...
				.rot_x(val)... % leave val empty to set a dof: return a dof object >> aka dof
				.rot_y(val)... % leave val empty to set a dof: return a dof object >> aka dof
				.rot_z(val)... % leave val empty to set a dof: return a dof object >> aka dof
				.rot_strain(strain_vec, init_quat)...
				.rot_frenet_serret(init_tangent_axis)...
                .rot_simple_curvilinear_frame(init_tangent_axis)...
				.rot_bishop_frame(curvature_vec)...
				.rot_unit_quat(unit_quat_vec)...
				.rot_non_unit_quat(non_unit_quat_vec)...
				.dof(i_q)... % i_q = dof numerator in each transformation tr
					.rom_order(order_int)...
					.not_rom()...
					.equal2(vec, n_r)...
					.similar_to_dof(coeff, i_j, i_h, i_d)...
					.coefficient_similar_to_dof_order(n_r, coeff, i_j, i_h, i_r, i_d)...
					.coefficient_similar_to_dof_at_axial_location(n_r, coeff, i_j, i_h, l, i_d)...
                    .coefficient_similar_to_dof_at_tip(n_r, coeff, i_j, i_h, i_d)...
                    .coefficient_similar_to_dof_derivative_at_axial_location(n_r, coeff, n_p, i_j, i_h, l, i_d)...
                    .coefficient_similar_to_dof_derivative_at_tip(n_r, coeff, n_p, i_j, i_h, i_d)...
					.set_rom_coefficient(n_r, value)...
					.base_value(value)... % make sure s starts from 0 for it to work properly!
					.base_director(director_double)... % make sure s starts from 0 for it to work properly!
					.base_value_at_axial_location(value, length)... % make sure s starts from 0 for it to work properly!
					.base_director_at_axial_location(director_double, length)... % make sure s starts from 0 for it to work properly!
                    .element_similar_to_dof(n_d, coeff, i_j, i_h, i_d)...
					.element_coefficient_similar_to_dof_order(n_d, n_r, coeff, i_j, i_h, i_r, i_d)...
					.element_coefficient_similar_to_dof_at_axial_location(n_d, n_r, coeff, i_j, i_h, l, i_d)...
                    .element_coefficient_similar_to_dof_at_tip(n_d, n_r, coeff, i_j, i_h, i_d)...
                    .element_coefficient_similar_to_dof_derivative_at_axial_location(n_d, n_r, coeff, n_p, i_j, i_h, l, i_d)...
                    .element_coefficient_similar_to_dof_derivative_at_tip(n_d, n_r, coeff, n_p, i_j, i_h, i_d)...
					.element_set_rom_coefficient(n_d, n_r, value)...
					.element_base_value(n_d, value)... % make sure s starts from 0 for it to work properly!
					.element_base_director(n_d, director_double)... % make sure s starts from 0 for it to work properly!
					.element_base_value_at_axial_location(n_d, value, length)... % make sure s starts from 0 for it to work properly!
					.element_base_director_at_axial_location(n_d, director_double, length)... % make sure s starts from 0 for it to work properly!
                    .axial_offset(offset)... % offset the integration range not the spline knots, doesn't changes spring_offset
					.initial_value(init)...
					.initial_value_from_kinematic_constraint()...
					.initial_value_axial_locations(init_s_vec)... % init_s will be asigned automatically based on initial values, if nto specified
                    .initial_value_fit_type(type, knots)... % type: {'polynomial', 'spline_piecewise', 'spline_logistic_func'}
					.spline_continuity_order(value)...
                    .parallel_spring()... % >> spring
					.parallel_elements_active_direction(dir_bool_vec)...
					.parallel_damper()... % >> damper
					.direct_input(input_type, input_val)... % input_type in {'force', 'trajectory'}, set 'trajectory' for constraint w Lagrang multiplier then input_val is acc. or PID
					.direct_input_at_coefficient(n_r, input_type, input_val)... % input_type in {'force', 'trajectory'}, set 'trajectory' for constraint w Lagrang multiplier then input_val is acc. or PID
                    .desired_state_trajectory(input_vec)... % inverse dynamic controller, with no Lagrange multiplier, input_val is acc. or PID
                    .desired_state_trajectory_at_coefficient(n_r, input_vec)... % inverse dynamic controller, with no Lagrange multiplier, input_val is acc. or PID
					.unknown_direct_input()...
					.unknown_direct_input_at_coefficient(n_r)...
                    .state_pid_controller_gains(P_gains_vec, I_gains_vec, D_gains_vec)... % pid gains (w.r.t. velocity) for both constraint and controller, pid_gains_vec: n_copies x 1
                    .state_pid_controller_gains_at_coefficient(n_r, P_gains_vec, I_gains_vec, D_gains_vec)... % pid gains (w.r.t. velocity) for both constraint and controller, pid_gains_vec: n_copies x 1
			.with_transformation_to_body(body_no, mesh_no, axial_loc)... % >> aka transformation()
			.with_transformation_to_body_tip(body_no, mesh_no)... % >> aka transformation()
			.active_directions(dir_bool)...
			.fixed_directions(dir_vec)... % constraint with Lagrange Multiplier
			.known_trajectory(input_vec)... % constraint with Lagrange Multiplier, set input_vec element NAN to disregard that direction, input_val is acc. or PID
			.desired_trajectory(input_vec)... % inverse dynamic controller with no Lagrange multiplier, set input_vec element NAN to disregard that direction, input_val is acc. or PID
            .pid_controller_gains(P_gains_vec, I_gains_vec, D_gains_vec)... % pid gains (w.r.t. velocity) for both constraint and controller, pid_gains_vec: n_copies x 6
            .pid_controller_gains_at_strain(n_r, P_gains_vec, I_gains_vec, D_gains_vec)... % pid gains (w.r.t. velocity) for both constraint and controller, pid_gains_vec: n_copies x 6
			.wrt_body(body_no, mesh_no, axial_loc)...
			.wrt_body_tip(body_no, mesh_no)...
			.beam_local_x_axis(x_axis_vec)...
			.beam_stiffness()... % aka spring
				.coefficient(coeff)...
				.compression_ratio(ratio)...
				.relaxed_state(init_vals)... % relaxed state: spring initial length or beam initial strains/curvatures/torsion, set inf to assume unknown for controller design
                .unknown_relaxed_states(direction_vec)... % set 1 for directions with unknown relaxed state, doesn't support rom sep. body (results in a new set of lambda for each body)
				.relaxed_state_axial_locations(vec)...
				.relaxed_state_from_initial_condition()...
				.relaxed_state_from_rom_constant()...
				.boundary_condition(equal2_vec)...
				.set_relaxed_state_rom_coefficient(n_r, value)...
				.relaxed_state_coefficient_similar_to_dof_order(n_r, coeff, i_j, i_h, i_r, i_d)...
				.relaxed_state_coefficient_similar_to_dof_at_axial_location(n_r, coeff, i_j, i_h, l, i_d)...
				.relaxed_state_coefficient_similar_to_dof_at_tip(n_r, coeff, i_j, i_h, i_d)...
				.relaxed_state_base_value(value)... % make sure s starts from 0 for it to work properly!
				.relaxed_state_base_director(director_double)... % make sure s starts from 0 for it to work properly! 
				.relaxed_state_base_value_at_axial_location(value, length)... % make sure s starts from 0 for it to work properly!
				.relaxed_state_base_director_at_axial_location(director_double, length)... % make sure s starts from 0 for it to work properly!              
				.element_set_relaxed_state_rom_coefficient(n_d, n_r, value)...
				.element_relaxed_state_coefficient_similar_to_dof_order(n_d, n_r, coeff, i_j, i_h, i_r, i_d)...
				.element_relaxed_state_coeff_similar_to_dof_at_axial_location(n_d, n_r, coeff, i_j, i_h, l, i_d)...
				.element_relaxed_state_coefficient_similar_to_dof_at_tip(n_d, n_r, coeff, i_j, i_h, i_d)...
				.element_relaxed_state_base_value(n_d, value)... % make sure s starts from 0 for it to work properly!
				.element_relaxed_state_base_director(n_d, director_double)... % make sure s starts from 0 for it to work properly!
				.element_relaxed_state_base_value_at_axial_location(n_d, value, length)... % make sure s starts from 0 for it to work properly!
				.element_relaxed_state_base_director_at_axial_location(n_d, director_double, length)... % make sure s starts from 0 for it to work properly!
				.relaxed_state_axial_offset(offset)... % offset the integration range not the spline knots, 
                .relaxed_state_fit_type(type, knots)... % type: {'polynomial', 'spline_piecewise', 'spline_logistic_func'}
			.beam_damping()... % >> aka damper
				.viscosity(val)...
				.power(val)...
			.beam_internal_actuation(input_vec)...
            .beam_cross_section_radius(radius)... % for animation only
		.compliance_beam(name)... % >> joint()
		.compliance_beam_with_repeated_elements(name, mesh_no)... % >> joint()
		.constraint(name)... % >> joint()
		.constraint_with_repeated_elements(name, mesh_no)... % >> joint()
		.dynamic_inverse_controller(name)... % >> joint()
		.dynamic_inverse_controller_with_repeated_elements(name, mesh_no)... % >> joint()
		.mesh(name)...
			.from_file(file_name, tolerance_val)...
			.with_tolerance(tolerance_val)...
			.with_base_transformation()... % >> transformation()
			.with_node_body(name)... >> body()
			.joint(name)... >> joint()...
			.with_node_dof(name)... >> joint()
			.with_edge(name)... >> joint
		.exload(name)...
			.exerted_on_body(body_no, mesh_no, axial_loc)...
			.exerted_on_body_tip(body_no, mesh_no)...
			.wrt_reference_body(body_no, mesh_no, axial_loc)... % default ground
			.wrt_reference_body_tip(body_no, mesh_no)... % default ground
			.with_transformation()... % >> transformation
			.exerted_on_body_with_transformation(body_no, mesh_no, axial_loc)... % >> transformation
			.exerted_on_body_tip_with_transformation(body_no, mesh_no)... % >> transformation
			.force(force_vec)...
			.moment(monet_vec)...
			.unknown_directions(dirs)...
	.run()
	
	