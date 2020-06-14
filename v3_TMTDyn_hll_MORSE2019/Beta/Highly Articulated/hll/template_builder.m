function [world, body, joint, exload, mesh, par] = template_builder()

syms dummy1
empty_sym = sym([]);
zero_sym = sym(0);

% par
par.sym = dummy1;
par.var = zero_sym;
par.derive = 0; % set 1 to rederive in TMT
par.user_pars = 0;
par.opv = 0; % optimize derivation files
par.simplify = 0; % simplify derivations
par.derive_collect = 0; % derive in single file: 1- single struct., 2- seperte struct.s, 3- separate func.s, 4- C func.s
par.derive_mex = 0; % use Matlab codegen, use with par.derive_collect = 1 for now
par.post_process = 0;
par.anim = 0; % animation on (1) or off (0)
par.anim_frame = 0; % show local frame
par.movie = 0; % save movie
par.equil = 0; % 1 to do initial static analysis
par.dyn = 0; % 1 to do dyn. sim.
par.solver = 1 ; % use Matlab ode15s
par.modal = 0; % 1 to do modal analysis
par.t_rep = 0; % sim report time, 0: no report (faster)
par.n_int = 50; % number of integration steps
par.n_animpoints = 20; % number of anim points
par.n_datasample = 100; % number of saved data samples
par.dt_anim_rep = [inf, 1]; % anim report time, if 'inf' then (tf-t0)/dt_animStep(2)
par.t_init = 0;
par.t_final = 0;
par.t_equil = 0;

% world
world.g = sym([0, 0, 0]);

% body
body.m = empty_sym;
body.I = empty_sym;
body.l_com = empty_sym;
body.tip = empty_sym;

% tr
tr.trans = empty_sym;
tr.rot_type = [];
tr.rot = empty_sym;

% spring
spring.coeff = empty_sym;
spring.init = empty_sym;
spring.init_cart = [];
spring.init_s = empty_sym;
spring.compr = empty_sym;
spring.equal2 = sym(zeros(1, 5));

%damper
damp.visc = empty_sym;
damp.pow = sym(1);

% dof
dof.equal2 = sym(zeros(1, 5));
dof.init = empty_sym;
dof.init_cart = [];
dof.init_s = empty_sym;
dof.spring = spring;
dof.dir = 0;
dof.damp = damp;
dof.input = zero_sym;
dof.control = zero_sym;
dof.xaxis = empty_sym;
dof.s = empty_sym;

% rom
rom.order = [];
rom.default_order = 0;
rom.length = empty_sym;
rom.rel_base = 1;
rom.free_base = 0;
rom.init_s = empty_sym;

% joint
joint.first = [];
joint.second = [];
joint.rom = rom;
joint.tr = tr;
joint.dof = dof;
joint.tr2nd = tr;
joint.spring = spring;
joint.dir = 0;
joint.damp = damp;
joint.input = empty_sym;
joint.xaxis = empty_sym;
joint.fixed = [];
joint.control = empty_sym;
joint.refbody = [];

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


