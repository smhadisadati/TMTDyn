function [world, body, joint, exload, mesh, par] = template_builder()

addpath('./tmtdyn','./tmtdyn/sundials_matlab','./tmtdyn/radau','./tmtdyn/funcs','./hll','./eom','./tmtdyn/tubeplot','./tmtdyn/igesToolBox_edited');

syms dummy1 real
empty_sym = sym([]);
zero_sym = sym(0);

% par
par.sym = dummy1; % e.g. structural params, replaced for I.C. if rom.var_init
par.var = zero_sym;
par.control_sym = dummy1; % e.g. inputs and varying, always replaced for I.C. except for vars in spline_knots
par.control_var = zero_sym;
par.derive = 0; % set 1:rederive in TMT, 2: rederive neglecting TMDu (small velocity linearization)
par.user_pars = 0;
par.cores = 0; % use parallel computing for derivations, 0 (default) to use all available cores
par.opv = 0; % optimize derivation files
par.clean = 0; % free up memory
par.simplify = 0; % simplify derivations, default: vpa
par.derive_collect = 1; % derive in single file: 1-'single_structures', 2-'separate_structures', 3-'separate_functions', 4-'C_functions', 5-'collect_most_terms'
par.derive_mex = 0; % use Matlab codegen, use with par.derive_collect = 1 for now
par.sparse = 0; % assume sparse matix, not working with par.derive_collect = 3 & 4
par.post_process = 0;
par.anim = 0; % animation on (1) or off (0)
par.anim_frame = 0; % show local frame
par.movie = 0; % save movie
par.equil = 0; % 1-'generate_m_file', 2-'generate_mex_file', 3-'old_mex_file', 4-'generate_mex_from_edited_m_file', 5-'edited_m_file',
par.dyn = 0; % 1-'generate_m_file', 2-'generate_mex_file', 3-'old_mex_file', 4-'generate_mex_from_edited_m_file', 5-'edited_m_file', 6-'generate_mex_from_c_files'
par.solver = 1 ; % 1-'matlab', 2-'sundials_ode', 3-'sundials_dae', 4-'radau', 5-'radau_mex', 6-'external'
par.modal = 0; % 1 to do modal analysis
par.t_rep = 0; % sim report time, 0: no report (faster)
par.n_int = 100; % number of integration steps
par.n_animpoints = 20; % number of points along each curve for plotting
par.n_datasample = 100; % number of saved data samples
par.dt_anim_rep = [inf, 1]; % anim report time, if 'inf' then (tf-t0)/dt_animStep(2)
par.t_init = 0;
par.t_final = 0;
par.t_equil = 0;
par.plotIC = 0;
par.pw2lg = 0; % piecewise to logistic function convertsion
par.anim_line = 0; % animation line type, line: 0, tube: 1
par.fps = 30; % animation fps for video recording
par.anim_edge = 10; % tube cross-section edge

% world
world.g = sym([0, 0, 0]);

% body
body.m = 1e-9;
body.I = 1e-9 * eye(3);
body.radi = 1e-3; % body link cross-section radius for animation only
body.l_com = [ 0 0 0 ];
body.tip = empty_sym;

% tr
tr.trans = empty_sym;
tr.type = []; % type: {'angle_axis', 'rot_strain', 'non_unit_quat', 'frenet_serret', 'simple_curvilinear', 'bishop_frame', 'growing'}
tr.rot = empty_sym;
tr.init_quat = sym([1, 0, 0, 0]);

% spring
spring.coeff = empty_sym;
spring.init = empty_sym; % set 
spring.init_s = empty_sym;
spring.compr = empty_sym;
spring.equal2{1} = sym(zeros(1, 7));
spring.rom_offset = []; % 1st element: acts after fitting for each dof, affects logistic switch unit length but not the spline knots, 2nd element: act before fitting including spline knots
spring.fit_type = []; % [type, knots]; type: []- default copy from rom_default, 1-'polynomial', 2-'spline_piecewise', 3-'spline_logistic_func'; default not ROM
spring.spc_order = []; % spline transition continuity order (starting form polynomial coeff. C_0), to be filled by rom.spc_order if not specified

%damper
damp.visc = empty_sym;
damp.pow = sym(1);

%pid [P,I,D]: result in P*u+I*q+D*a
pid.p = zero_sym;
pid.i = zero_sym;
pid.d = zero_sym;

% dof
dof.equal2{1} = sym(zeros(1, 7)); % doesn't copy one line for all mesh, should be specified individually for all elements!
dof.init = empty_sym;
dof.rom_offset = zero_sym * ones(1,2); % 1st element: acts after fitting for each dof, affects logistic switch unit length but not the spline knots, affects rom_series, not when it is used for dof equality constraint or init_rom_series used for spring equality constraint; 2nd element: act before fitting including spline knots
dof.init_s = empty_sym;
dof.spring = spring;
dof.dir = 0;
dof.damp = damp;
dof.input = zero_sym;
dof.fixed = zero_sym; % 1: constraint with Lagrange Multiplier, or inf: controller/known wo. LM
dof.control = zero_sym; % known trajectory
dof.pid = pid; % [P,I,D]: result in P*u+I*q+D*a
dof.xaxis = empty_sym;
dof.s = empty_sym;
dof.fit_type = []; % [type, knots], type: []- default copy from rom_default, 1-'polynomial', 2-'spline_piecewise', 3-'spline_logistic_func'
dof.spc_order = []; % spline transition continuity order (starting form polynomial coeff. C_0), to be filled by rom.spc_order if not specified

% rom
rom.order = 0; % dof polynomial order, default (0) means rigid-link DOFs
rom.isROM = 0; % is a continuum ROM joint?
rom.default_order = 0;
rom.spc_order = 2; % spline transition continuity order (starting form polynomial coeff. C_0)
rom.length = sym(zeros(1,9)); % [l_start_rom, l_end_rom, type, coeff(e.g. -+1), i_j(joint), i_d(mesh), i_h(DOF), i_r(coeff order in rom), l_rom(length along rom)], type:{'none', 'tip_growing', 'base_growing', 'sliding'}, coeff: inf for new dof
rom.rel_base = 1;
rom.free_base = 0;
rom.init_s = empty_sym;
rom.fit_type = 0; % [type, knots]; type: 0- default rigid-link, 1-'polynomial', 2-'spline_piecewise', 3-'spline_logistic_func'; default not ROM
rom.spring_fit_type = 0; % [type, knots]; type: 0- default rigid-link, 1-'polynomial', 2-'spline_piecewise', 3-'spline_logistic_func'; default not ROM
rom.rom_offset = zero_sym * ones(1,2); % overrides dof.rom_offset
rom.spring_rom_offset = zero_sym * ones(1,2); % overrides spring.rom_offset
rom.growth = sym( 200 ); % dof spline growth rate
rom.simpKnot = 0; % assume similar knot for all DOFs
rom.stiffmodel = 1; % rom stiffness model: 1- continuous, 2- discretized
rom.var_init = 1; % variable init. val.s
rom.singleBody = 1;

% joint
joint.first = []; % [body_no, mesh_no.s; 0, location_lenghes]
joint.second = []; % [body_no, mesh_no.s; 0, location_lenghes]
joint.rom = rom;
joint.tr = tr;
joint.dof = dof;
joint.tr2nd = tr;
joint.spring = spring;
joint.dir = 0;
joint.damp = damp;
joint.input = empty_sym;
joint.xaxis = empty_sym;
joint.fixed = []; % 1: constraint with Lagrange Multiplier, or inf: controller/known wo. LM
joint.control = empty_sym; % ve_elems = value: desired trajectory, or NAN: no controller on the direction
joint.pid = pid; % [P,I,D]: result in P*u+I*q+D*a
joint.refbody = [];
joint.n_copies = 1;
joint.radi = 1e-3; % joint cross-section radius for animation only

% exload
exload.exbody = [];
exload.refbody = [];
exload.tr = tr;
exload.ftau = empty_sym;

% mesh
mesh.file_name = [];
mesh.tol = [];
mesh.body = body;
mesh.joint(1) = joint;
mesh.joint(2) = joint;
mesh.tr = tr;


