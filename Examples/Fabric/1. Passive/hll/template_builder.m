function [ world , body , joint , exload , mesh , par ] = template_builder()

syms dummy1

% par
par.sym = dummy1 ;
par.var = 0 ;
par.derive = 0 ; % set 1 to rederive in TMT
par.user = 0 ;
par.opv = 0 ; % optimize derivation files
par.simplify = 0 ; % simplify derivations
par.derive_collect = 0 ; % derive in single file: 1- single struct., 2- seperte struct.s, 3- separate func.s, 4- C func.s
par.derive_mex = 0 ; % use Matlab codegen, use with par.derive_collect = 1 for now
par.anim = 0 ; % animation on (1) or off (0)
par.movie = 0 ; % save movie
par.equil = 0 ; % 1 to do initial static analysis
par.dyn = 0 ; % 1 to do dyn. sim.
par.modal = 0 ; % 1 to do modal analysis
par.t_rep = 5e-1 ; % sim report time
par.n_int = 100 ; % number of integration steps
par.n_animpoints = 50 ; % number of anim points
par.n_datasample = 50 ; % number of saved data samples
par.dt_anim_rep = [ inf 1 ] ; % anim report time, if 'inf' then (tf-t0)/dt_animStep(2)

% world
world.g = [0, 0, 0];

% body
body.m = [];
body.I = [];
body.l_com = [];
body.tip = [];

% tr
tr.trans = [];
tr.rot_type = [];
tr.rot = [];

% spring
spring.coeff = [];
spring.init = [];
spring.compr = [];

%damper
damp.visc = [];
damp.pow = [];

% dof
dof.equal2 = [];
dof.init = [];
dof.init_s = [];
dof.spring = spring;
dof.dir = 0;
dof.damp = damp;
dof.input = [];
dof.xaxis = [];

% rom
rom.order = [];
rom.length = [];

% joint
joint.first = [];
joint.second = [];
joint.rom = rom;
joint.tr = tr;
joint.dof = dof;
joint.tr2nd = tr;
joint.spring = spring;
joint.dir = [];
joint.damp = damp;
joint.input = [];
joint.xaxis = [];
joint.fixed = [];
joint.control = [];
joint.refbody = [];

% exload
exload.exbody = [];
exload.refbody = [];
exload.tr = tr;
exload.ftau = [];

% mesh
mesh.file_name = [];
mesh.tol = [];
mesh.body = body;
mesh.joint(1) = joint;
mesh.joint(2) = joint;
mesh.tr = tr;






