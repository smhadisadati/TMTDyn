function [ s , world , body , joint , exload , mesh , par , symbols ] = ...
    check( par , world , body , joint , exload , mesh )
%% check inputs to set default values and pass errors
fprintf( 'check inputs... \n' )
par.elapsed_time = [ par.elapsed_time toc( par.timer ) ] ;
toc( par.timer )

%% init.
syms s t_sym dummy1 real
symbols = dummy1 ;
[ world_temp , body_temp , joint_temp , exload_temp , mesh_temp , par_temp ] = template_builder() ;

%% pars
if isempty( par )
    par = par_temp ;
else
    if ~isfield( par , 'sym' ) || isempty( par.sym )
        par.sym = par_temp.sym ;
    end
    if ~isfield( par , 'var' ) || isempty( par.var )
        par.var = par_temp.var ;
    end
    if ~isfield( par , 'user_pars' ) || isempty( par.user_pars )
        par.user_pars = par_temp.user_pars ;
    end
    if ~isfield( par , 'derive' ) || isempty( par.derive )
        par.derive = par_temp.derive ;
    end
    if ~isfield( par , 'cores' ) || isempty( par.cores )
        par.cores = par_temp.cores ;
    end
    if ~isfield( par , 'opv' ) || isempty( par.opv )
        par.opv = par_temp.opv ;
    end
    if ~isfield( par , 'simplify' ) || isempty( par.simplify )
        par.simplify = par_temp.simplify ;
    end
    if numel( par.simplify ) == 1
        par.simplify = [par.simplify, inf] ; % add simplification duration
    end
    if ~isfield( par , 'sparse' ) || isempty( par.sparse )
        par.sparse = par_temp.sparse ;
    end
    if ~isfield( par , 'derive_collect' ) || isempty( par.derive_collect )
        par.derive_collect = par_temp.derive_collect ;
    end
    if ismember( par.derive_collect , [ 3 4 ] )
        par.sparse = 0 ;
    end
    if ~isfield( par , 'derive_mex' ) || isempty( par.derive_mex )
        par.derive_mex = par_temp.derive_mex ;
        par.derive_collect = par_temp.derive_collect ;
    end
    if ~isfield( par , 'post_process' ) || isempty( par.post_process )
        par.post_process = par_temp.post_process ;
    end
    if ~isfield( par , 'anim' ) || isempty( par.anim )
        par.anim = par_temp.anim ;
    end
    if ~isfield( par , 'anim_frame' ) || isempty( par.anim_frame )
        par.anim_frame = par_temp.anim_frame ;
    end
    if ~isfield( par , 'movie' ) || isempty( par.movie )
        par.movie = par_temp.movie ;
    end
    if ~isfield( par , 'equil' ) || isempty( par.equil )
        par.equil = par_temp.equil ;
    end
    if ~isfield( par , 'dyn' ) || isempty( par.dyn )
        par.dyn = par_temp.dyn ;
    end
    if ~isfield( par , 'solver' ) || isempty( par.solver )
        par.solver = par_temp.solver ;
    end
    if ~isfield( par , 'modal' ) || isempty( par.modal )
        par.modal = par_temp.modal ;
    end
    if ~isfield( par , 't_rep' ) || isempty( par.t_rep )
        par.t_rep = par_temp.t_rep-1 ;
    end
    if ~isfield( par , 'n_int' ) || isempty( par.n_int )
        par.n_int = par_temp.n_int ;
    end
    if ~isfield( par , 'n_animpoints' ) || isempty( par.n_animpoints )
        par.n_animpoints = par_temp.n_animpoints ;
    end
    if ~isfield( par , 'n_datasample' ) || isempty( par.n_datasample )
        par.n_datasample = par_temp.n_datasample ;
    end
    if ~isfield( par , 'dt_anim_rep' ) || isempty( par.dt_anim_rep ) || numel( par.dt_anim_rep ) ~= 2
        par.dt_anim_rep = par_temp.dt_anim_rep ;
    end
    if ~isfield( par , 't_init' ) || isempty( par.t_init )
        par.t_init = par_temp.t_init ;
    end
    if ~isfield( par , 't_final' ) || isempty( par.t_final )
        par.t_final = par_temp.t_final ;
    end
    if ~isfield( par , 't_equil' ) || isempty( par.t_equil )
        par.t_equil = par_temp.t_init ;
    end
    if ~isfield( par , 'pw2lg' ) || isempty( par.pw2lg )
        par.pw2lg = par_temp.pw2lg ;
    end
    if ~isfield( par , 'fps' ) || isempty( par.fps )
        par.fps = par_temp.fps ;
    end
    if ~isfield( par , 'anim_edge' ) || isempty( par.anim_edge )
        par.anim_edge = par_temp.anim_edge ;
    end
    if ~isfield( par , 'anim_line' ) || isempty( par.anim_line )
        par.anim_line = par_temp.anim_line ;
    end
end


%% world
if isempty( world ) ||  ~isfield( world , 'g' ) || isempty( world.g )
    world.g = [ 0 0 0 ] ;
end


%% joints
j_b = zeros( 1 , numel( body ) ) ; % joints in main kin. chain for all each body
for i_joint = 1 : numel( joint )
    nq = 0 ; % number of dof.s
    
    if ~isfield( joint(i_joint) , 'first' ) || isempty( joint(i_joint).first )
        joint(i_joint).first = [ 0 1 ; 0 0 ] ; % [body_no, mesh_no; 0, location_lengh]
    end
    
    if ~isfield( joint(i_joint) , 'second' ) || isempty( joint(i_joint).second )
        joint(i_joint).second = [ 0 1 ; 0 0 ] ; % [body_no, mesh_no; 0, location_lengh]
    end
        
    if ~isfield( joint(i_joint) , 'mainkin' ) || isempty( joint(i_joint).mainkin )
        joint(i_joint).mainkin = 0 ;
        for i_b = 1 : numel( body )
            if joint(i_joint).second(1,1) == i_b && j_b( i_b ) == 0 % first connected to i_b is in main kin. chain
                j_b( i_b ) = i_joint ;
                joint(i_joint).mainkin = 1 ;
            end
        end
    end
    
    [ n_copy , ind ] = max( [ numel( joint(i_joint).second(1,:) ) , numel( joint(i_joint).first(1,:) ) ] ) ;
    if ind == 2 && joint(i_joint).mainkin == 1 && numel( joint(i_joint).first(1,:) ) > 2 % only acceptable for sprdmp
        i_joint
        error( 'main kin. chain joint(i_joint).second size error' ) ;
    end
    if n_copy > 1
        n_copy = n_copy - 1 ;
    else
        joint(i_joint).first(1,2) = 1 ;
        joint(i_joint).second(1,2) = 1 ;
    end
    if numel( joint(i_joint).first(1,:) ) ~= numel( joint(i_joint).second(1,:) )
        if ind == 2
            if numel( joint(i_joint).second(1,:) ) == 1
                joint(i_joint).second(1,2:n_copy+1) = 1 ;
            else
                if numel( joint(i_joint).second(1,:) ) == 2
                    joint(i_joint).second(1,2:n_copy+1) = joint(i_joint).second(1,2) ;
                else
                    error( 'numel( joint(i_joint).first ) ~= numel( joint(i_joint).second )' ) ;
                end
            end
        else
            if numel( joint(i_joint).first(1,:) ) == 1
                joint(i_joint).first(1,2:n_copy+1) = 1 ;
            else
                if numel( joint(i_joint).first(1,:) ) == 2
                    joint(i_joint).first(1,2:n_copy+1) = joint(i_joint).first(1,2) ;
                else
                    error( 'numel( joint(i_joint).first ) ~= numel( joint(i_joint).second )' ) ;
                end
            end
        end
    end
    
    if numel( joint(i_joint).first(:,1) ) == 1 % fill the curve_length row
        joint(i_joint).first(2,1) = 0 ;
    end
    if numel( joint(i_joint).second(:,1) ) == 1
        joint(i_joint).second(2,1) = 0 ;
    end
    
    if ~isfield( joint(i_joint) , 'rom' ) || isempty( joint(i_joint).rom )
        joint(i_joint).rom = par_temp.rom ;
    end
    if max( max( joint(i_joint).rom.order ) ) > 0
        joint(i_joint).rom.isROM = 1; % it is a continuum ROM joint
        if ~isfield( joint(i_joint).rom , 'order' ) || isempty( joint(i_joint).rom.order )
            error( 'joint(i_joint).rom.order error' ) ;
        else
            joint(i_joint).rom.order =  ones(n_copy,1) .* joint(i_joint).rom.order;
        end
        if ~isfield( joint(i_joint).rom , 'default_order' ) || isempty( joint(i_joint).rom.default_order )
            joint(i_joint).rom.default_order = zeros(n_copy,1)  ;
        else
            joint(i_joint).rom.default_order =  ones(n_copy,1) .* joint(i_joint).rom.default_order;
        end
        if ~isfield( joint(i_joint).rom , 'length' ) || isempty( joint(i_joint).rom.length )
            error( 'joint(i_joint).rom.length error' ) ;
        else
            joint(i_joint).rom.length =  ones(n_copy,1) .* joint(i_joint).rom.length;
        end
        if ~isfield( joint(i_joint).rom , 'rel_base' ) || isempty( joint(i_joint).rom.rel_base )
            joint(i_joint).rom.rel_base = par_temp.rom.rel_base ;
        else
            joint(i_joint).rom.rel_base =  ones(n_copy,1) .* joint(i_joint).rom.rel_base;
        end
        if ~isfield( joint(i_joint).rom , 'free_base' ) || isempty( joint(i_joint).rom.free_base )
            joint(i_joint).rom.free_base = par_temp.rom.free_base ;
        else
            joint(i_joint).rom.free_base =  ones(n_copy,1) .* joint(i_joint).rom.free_base;
        end
        if ~isfield( joint(i_joint).rom , 'init_s' )
            joint(i_joint).rom.init_s = par_temp.rom.init_s ;
        end
        if ~isfield( joint(i_joint).rom , 'fit_type' )
            joint(i_joint).rom.fit_type = par_temp.rom.fit_type ;
        end
        if ~isfield( joint(i_joint).rom , 'spring_fit_type' )
            joint(i_joint).rom.spring_fit_type = par_temp.rom.spring_fit_type ;
        end
        if ~isfield( joint(i_joint).rom , 'growth' )
            joint(i_joint).rom.growth = par_temp.rom.growth ;
        end
        if ~isfield( joint(i_joint).rom , 'simpKnot' )
            joint(i_joint).rom.simpKnot = par_temp.rom.simpKnot ;
        end
        if ~isfield( joint(i_joint).rom , 'spc_order' )
            joint(i_joint).rom.spc_order = par_temp.rom.spc_order ;
        end
        if ~isfield( joint(i_joint).rom , 'var_init' )
            joint(i_joint).rom.var_init = par_temp.rom.var_init ;
        end
        if ~isfield( joint(i_joint).rom , 'stiffmodel' )
            joint(i_joint).rom.stiffmodel = par_temp.rom.stiffmodel ;
        end
        if ~isfield( joint(i_joint).rom , 'rom_offset' )
            joint(i_joint).rom.rom_offset = par_temp.rom.rom_offset ;
        end
        if ~isfield( joint(i_joint).rom , 'spring_rom_offset' )
            joint(i_joint).rom.spring_rom_offset = par_temp.rom.spring_rom_offset ;
        end
        if ~isfield( joint(i_joint).rom , 'singleBody' )
            joint(i_joint).rom.singleBody = par_temp.rom.singleBody ;
        end
    else
        joint(i_joint).rom.isROM = 0; % it is not a continuum ROM joint
        joint(i_joint).rom.order =  ones(n_copy,1) .* joint(i_joint).rom.order;
    end
    
    if ~isfield( joint(i_joint) ,'tr' ) || isempty( joint(i_joint).tr )
        joint(i_joint).tr.trans = [ 0 0 0 ] ;
        joint(i_joint).tr.rot = [ 1 0 0 0 ] ;
        joint(i_joint).tr.init_quat = [ 1 0 0 0 ] ;
        joint(i_joint).tr.type = 'none' ;
    end
    
    if ~isfield( joint(i_joint) , 'dof' ) || isempty( joint(i_joint).dof )
        joint(i_joint).dof = joint_temp.dof ;
    end
    
    if ~isfield( joint(i_joint) , 'pid' ) || isempty( joint(i_joint).pid )
        joint(i_joint).pid = joint_temp.pid ;
    end
    if ~isfield( joint(i_joint).pid , 'p' ) || isempty( joint(i_joint).pid.p )
        joint(i_joint).pid.p = ones(n_copy,1) .* ones(1,6) .* joint_temp.pid.p ;
    else
        if numel( joint(i_joint).pid.p(1,:) ) < 6
            joint(i_joint).pid.p = ones(1,6) .* joint(i_joint).pid.p(1,:) ;
        end
        joint(i_joint).pid.p = ones(n_copy,1) .* joint(i_joint).pid.p ;
    end
    if ~isfield( joint(i_joint).pid , 'i' ) || isempty( joint(i_joint).pid.i )
        joint(i_joint).pid.i = ones(n_copy,1) .* ones(1,6) .* joint_temp.pid.i ;
    else
        if numel( joint(i_joint).pid.i(1,:) ) < 6
            joint(i_joint).pid.i = ones(1,6) .* joint(i_joint).pid.i(1,:) ;
        end
        joint(i_joint).pid.i = ones(n_copy,1) .* joint(i_joint).pid.i ;
    end
    if ~isfield( joint(i_joint).pid , 'd' ) || isempty( joint(i_joint).pid.d )
        joint(i_joint).pid.d = ones(n_copy,1) .* ones(1,6) .* joint_temp.pid.d ;
    else
        if numel( joint(i_joint).pid.d(1,:) ) < 6
            joint(i_joint).pid.d = ones(1,6) .* joint(i_joint).pid.d(1,:) ;
        end
        joint(i_joint).pid.d = ones(n_copy,1) .* joint(i_joint).pid.d ;
    end
    for i = 1 : numel( joint(i_joint).tr )
        if ~isfield( joint(i_joint).tr(i) ,'trans' ) || isempty( joint(i_joint).tr(i).trans )
            joint(i_joint).tr(i).trans = [ 0 0 0 ] ;
        end
        if ~isfield( joint(i_joint).tr(i) ,'rot' ) || isempty( joint(i_joint).tr(i).rot )
            joint(i_joint).tr(i).rot = [ 1 0 0 0 ] ;
            joint(i_joint).tr(i).init_quat = [ 1 0 0 0 ] ;
            joint(i_joint).tr(i).type = 'none' ;
        end
        if ~isfield( joint(i_joint).tr(i) ,'init_quat' ) || isempty( joint(i_joint).tr(i).init_quat )
            joint(i_joint).tr(i).init_quat = [ 1 0 0 0 ] ;
        end
        if ~isfield( joint(i_joint).tr(i) ,'type' ) || isempty( joint(i_joint).tr(i).type )
            joint(i_joint).tr(i).type = 'none' ;
        end
        rotrans = [ joint(i_joint).tr(i).trans joint(i_joint).tr(i).rot ] ;
        for i2 = 1 : numel( rotrans )
            if isinf( rotrans(i2) )
                nq = nq + 1 ;
                if nq > numel( joint(i_joint).rom.order(1,:) ) || isnan( joint(i_joint).rom.order(1,nq) )
                    joint(i_joint).rom.order(:,nq) = ones(n_copy,1) .* joint(i_joint).rom.default_order ;
                end
                n_coeff = joint(i_joint).rom.order(n_copy,nq) ;
                if ~isfield( joint(i_joint) , 'dof' ) || isempty( joint(i_joint).dof ) || numel( joint(i_joint).dof ) < nq
                    [joint(i_joint).dof(nq).equal2{1:n_coeff+1>0}] = deal( sym( zeros(n_copy,7) ) ) ;
                    joint(i_joint).dof(nq).init = zeros(n_copy,n_coeff+1) ; % n_coeff+1 to cover all q_coeff.s for parallel springs
                    joint(i_joint).dof(nq).init_s = sym( zeros(n_copy,n_coeff+1) ) ; % to get equal number of elements as in init (above)
                    joint(i_joint).dof(nq).rom_offset = ones(n_copy,1) .* joint(i_joint).rom.rom_offset ;
                    joint(i_joint).dof(nq).dir = zeros(n_copy,n_coeff+1) ;
                    joint(i_joint).dof(nq).damp.visc = zeros(n_copy,n_coeff+1) ;
                    joint(i_joint).dof(nq).damp.pow = ones(n_copy,n_coeff+1) ;
                    joint(i_joint).dof(nq).input = zeros(n_copy,n_coeff+1) ;
                    joint(i_joint).dof(nq).control = zeros(n_copy,n_coeff+1) ;
                    joint(i_joint).dof(nq).pid.p = zeros(n_copy,n_coeff+1) ;
                    joint(i_joint).dof(nq).pid.i = zeros(n_copy,n_coeff+1) ;
                    joint(i_joint).dof(nq).pid.d = zeros(n_copy,n_coeff+1) ;
                    joint(i_joint).dof(nq).fixed = zeros(n_copy,n_coeff+1) ;
                    joint(i_joint).dof(nq).fit_type = ones(n_copy,1) .* joint(i_joint).rom.fit_type ;
                    joint(i_joint).dof(nq).spc_order = ones(n_copy,1) .* joint(i_joint).rom.spc_order ;
                    
                    joint(i_joint).dof(nq).spring.coeff = zeros(n_copy,n_coeff+1) ;
                    joint(i_joint).dof(nq).spring.init = zeros(n_copy,n_coeff+1) ; % n_coeff+1 to cover all q_coeff.s for parallel springs
                    joint(i_joint).dof(nq).spring.init_s = sym( zeros(n_copy,n_coeff+1) ) ; % to get equal number of elements as in init (above)
                    joint(i_joint).dof(nq).spring.compr = ones(n_copy,n_coeff+1) ;
                    [joint(i_joint).dof(nq).spring.equal2{1:n_coeff+1>0}] = deal( sym( zeros(n_copy,7) ) ) ;
                    joint(i_joint).dof(nq).spring.rom_offset = ones(n_copy,1) .* joint(i_joint).rom.spring_rom_offset ;
                    joint(i_joint).dof(nq).spring.fit_type = ones(n_copy,1) .* joint(i_joint).rom.spring_fit_type  ;
                    joint(i_joint).dof(nq).spring.spc_order = ones(n_copy,1) .* joint(i_joint).rom.spc_order ;
                else
                    if ~isfield( joint(i_joint).dof(nq) ,'equal2' ) || isempty( joint(i_joint).dof(nq).equal2 )
                        [joint(i_joint).dof(nq).equal2{1:n_coeff+1>0}] = deal( sym( zeros(n_copy,7) ) ) ; % [j_count, n_copy, nj_dof, i_dof_mult, val_or_l_rom] x i_dof_mult -or- [n_j, n_copy, n_h, i_coeff, curve_length] x n_coeff
                    else
                        for i_coeff = 1 : n_coeff + 1
                            [ ~ , temp_3 ] = size( joint(i_joint).dof(nq).equal2 ) ;
                            for i_copy = 1 : n_copy
                                if temp_3 < i_coeff || joint(i_joint).dof(nq).equal2{i_coeff}(i_copy,1) == 0
                                    if isnan( joint(i_joint).dof(nq).equal2{1}(i_copy,4) ) % all coeffs will be equal to the same coeff in the other joint/dof
                                        joint(i_joint).dof(nq).equal2{i_coeff}(i_copy,:) = joint(i_joint).dof(nq).equal2{1}(i_copy,:) ;
                                    else
                                        joint(i_joint).dof(nq).equal2{i_coeff}(i_copy,:) = vpa( zeros(1,7) ) ;
                                    end
                                    % continue ;
                                end
                                %if i_copy == 1 && numel(joint(i_joint).dof(nq).equal2{i_coeff}(:,1) ) == 1
                                    % joint(i_joint).dof(nq).equal2{i_coeff} = ones(n_copy,1) * joint(i_joint).dof(nq).equal2{i_coeff} ;
                                if i_copy == 1 && numel( joint(i_joint).dof(nq).equal2{i_coeff}(:,1) ) < n_copy
                                    joint(i_joint).dof(nq).equal2{i_coeff}(n_copy,end) = 0 ;
                                end
                            end
                            if joint(i_joint).dof(nq).equal2{i_coeff}(n_copy,1) == i_joint && joint(i_joint).dof(nq).equal2{i_coeff}(n_copy,2) == n_copy
                                error( 'joint(i_joint).dof(nq).equal2{i_coeff}(n_copy,1) = same joint is not allowed!' ) ;
                            end
                            if numel( joint(i_joint).dof(nq).equal2{i_coeff}(1,:) ) == 2 % [n_j, n_h]
                                joint(i_joint).dof(nq).equal2{i_coeff} = [ joint(i_joint).dof(nq).equal2{i_coeff}(:,1) ones(n_copy,1) joint(i_joint).dof(nq).equal2{i_coeff}(:,2) nan*ones(n_copy,1) zeros(n_copy,3) ] ;
                            end
                            if numel( joint(i_joint).dof(nq).equal2{i_coeff}(1,:) ) == 3 % [n_j, n_h, i_coeff]
                                joint(i_joint).dof(nq).equal2{i_coeff} = [ joint(i_joint).dof(nq).equal2{i_coeff}(:,1) ones(n_copy,1) joint(i_joint).dof(nq).equal2{i_coeff}(:,2:3) zeros(n_copy,3) ] ;
                            end
                        end
                    end
                    if ~isfield( joint(i_joint).dof(nq) ,'rom_offset' ) || isempty( joint(i_joint).dof(nq).rom_offset )
                        joint(i_joint).dof(nq).rom_offset = ones(n_copy,1) .* joint(i_joint).rom.rom_offset ;
                    else
                        joint(i_joint).dof(nq).rom_offset = ones(n_copy,1) .* joint(i_joint).dof(nq).rom_offset ;
                    end
                    if ~isfield( joint(i_joint).dof(nq) ,'fit_type' ) || isempty( joint(i_joint).dof(nq).fit_type )
                        joint(i_joint).dof(nq).fit_type = ones(n_copy,1) .* joint(i_joint).rom.fit_type ;
                    else
                        joint(i_joint).dof(nq).fit_type = ones(n_copy,1) .* joint(i_joint).dof(nq).fit_type ;
                    end
                    if ~isfield( joint(i_joint).dof(nq) ,'spc_order' ) || isempty( joint(i_joint).dof(nq).spc_order )
                        joint(i_joint).dof(nq).spc_order = ones(n_copy,1) .* joint(i_joint).rom.spc_order ;
                    else
                        joint(i_joint).dof(nq).spc_order = ones(n_copy,1) .* joint(i_joint).dof(nq).spc_order ;
                    end
                    if ~isfield( joint(i_joint).dof(nq) ,'init' ) || isempty( joint(i_joint).dof(nq).init )
                        joint(i_joint).dof(nq).init = zeros(n_copy,n_coeff+1) ; % n_coeff+1 to cover all q_coeff.s for parallel springs
                    else
                        joint(i_joint).dof(nq).init = ones(n_copy,1) .* joint(i_joint).dof(nq).init ;
                    end
                    if ~isfield( joint(i_joint).dof(nq) ,'init_s' ) || isempty( joint(i_joint).dof(nq).init_s )
                        joint(i_joint).dof(nq).init_s = sym( zeros(n_copy, numel( joint(i_joint).dof(nq).init(1,:) ) ) ) ; % to get equal number of elements as in init (above)
                    else
                        joint(i_joint).dof(nq).init_s = ones(n_copy,1) .* joint(i_joint).dof(nq).init_s ;
                    end
                    if ~isfield( joint(i_joint).dof(nq) ,'spring' ) || isempty( joint(i_joint).dof(nq).spring )
                        joint(i_joint).dof(nq).spring.coeff = zeros(n_copy,n_coeff+1) ;
                        joint(i_joint).dof(nq).spring.init = zeros(n_copy,n_coeff+1) ; % n_coeff+1 to cover all q_coeff.s for parallel springs
                        joint(i_joint).dof(nq).spring.init_s = sym( zeros(n_copy,n_coeff+1) ) ; % to get equal number of elements as in init (above)
                        joint(i_joint).dof(nq).spring.compr = ones(n_copy,n_coeff+1) ;
                        [joint(i_joint).dof(nq).spring.equal2{1:n_coeff+1>0}] = deal( sym( zeros(n_copy,7) ) ) ;
                        joint(i_joint).dof(nq).spring.rom_offset = ones(n_copy,1) .* joint(i_joint).rom.spring_rom_offset ;
                        joint(i_joint).dof(nq).spring.fit_type = ones(n_copy,1) .* joint(i_joint).rom.spring_fit_type  ;
                        joint(i_joint).dof(nq).spring.spc_order = ones(n_copy,1) .* joint(i_joint).rom.spc_order ;
                    else
                        if ~isfield( joint(i_joint).dof(nq).spring ,'coeff' ) || isempty( joint(i_joint).dof(nq).spring.coeff )
                            joint(i_joint).dof(nq).spring.coeff = zeros(n_copy,n_coeff+1) ;
                        else
                            joint(i_joint).dof(nq).spring.coeff = ones(1,n_coeff+1) .* ones(n_copy,1) .* joint(i_joint).dof(nq).spring.coeff ;
                        end
                        if ~isfield( joint(i_joint).dof(nq).spring ,'init' ) || isempty( joint(i_joint).dof(nq).spring.init )
                            joint(i_joint).dof(nq).spring.init = zeros(n_copy,n_coeff+1) ; % n_coeff+1 to cover all q_coeff.s for parallel springs
                        else
                            joint(i_joint).dof(nq).spring.init = ones(n_copy,1) .* joint(i_joint).dof(nq).spring.init ;
                        end
                        if ~isfield( joint(i_joint).dof(nq).spring ,'init_s' ) || isempty( joint(i_joint).dof(nq).spring.init_s )
                            joint(i_joint).dof(nq).spring.init_s = sym( zeros(n_copy, numel( joint(i_joint).dof(nq).spring.init(1,:) ) ) ) ; % to get equal number of elements as in init (above)
                        else
                            joint(i_joint).dof(nq).spring.init_s = ones(n_copy,1) .* joint(i_joint).dof(nq).spring.init_s ;
                        end
                        if ~isfield( joint(i_joint).dof(nq).spring ,'compr' ) || isempty( joint(i_joint).dof(nq).spring.compr )
                            joint(i_joint).dof(nq).spring.compr = ones(n_copy,n_coeff+1) ;
                        else
                            joint(i_joint).dof(nq).spring.compr = ones(1,n_coeff+1) .* ones(n_copy,1) .* joint(i_joint).dof(nq).spring.compr ;
                        end                        
                        if ~isfield( joint(i_joint).dof(nq).spring ,'rom_offset' ) || isempty( joint(i_joint).dof(nq).spring.rom_offset )
                            joint(i_joint).dof(nq).spring.rom_offset = ones(n_copy,1) .* joint(i_joint).rom.spring_rom_offset ;
                        else
                            joint(i_joint).dof(nq).spring.rom_offset = ones(n_copy,1) .* joint(i_joint).dof(nq).spring.rom_offset ;
                        end              
                        if ~isfield( joint(i_joint).dof(nq).spring ,'fit_type' ) || isempty( joint(i_joint).dof(nq).spring.fit_type )
                            joint(i_joint).dof(nq).spring.fit_type = ones(n_copy,1) .* joint(i_joint).rom.spring_fit_type ;
                        else
                            joint(i_joint).dof(nq).spring.fit_type = ones(n_copy,1) .* joint(i_joint).dof(nq).spring.fit_type ;
                        end
                        if ~isfield( joint(i_joint).dof(nq).spring ,'spc_order' ) || isempty( joint(i_joint).dof(nq).spring.spc_order )
                            joint(i_joint).dof(nq).spring.spc_order = ones(n_copy,1) .* joint(i_joint).rom.spc_order ;
                        else
                            joint(i_joint).dof(nq).spring.spc_order = ones(n_copy,1) .* joint(i_joint).dof(nq).spring.spc_order ;
                        end
                        if ~isfield( joint(i_joint).dof(nq).spring ,'equal2' )
                            [ joint(i_joint).dof(nq).spring.equal2{1:n_coeff+1>0} ] = deal( sym( zeros(n_copy,7) ) ) ;
						else
							for i_coeff = 1 : n_coeff + 1
								[ ~ , temp_3 ] = size( joint(i_joint).dof(nq).spring.equal2 ) ;
                                for i_copy = 1 : n_copy
                                    if temp_3 < i_coeff || joint(i_joint).dof(nq).spring.equal2{i_coeff}(i_copy,1) == 0
                                        if isnan( joint(i_joint).dof(nq).spring.equal2{1}(i_copy,4) )
                                            joint(i_joint).dof(nq).spring.equal2{i_coeff}(i_copy,:) = joint(i_joint).dof(nq).spring.equal2{1}(i_copy,:) ;
                                        else
                                            joint(i_joint).dof(nq).spring.equal2{i_coeff}(i_copy,:) = vpa( zeros(1,7) ) ;
                                        end
                                        % continue ;
                                    end
                                    % if i_copy == 1 && numel( joint(i_joint).dof(nq).spring.equal2{i_coeff}(:,1) ) == 1
                                        % joint(i_joint).dof(nq).spring.equal2{i_coeff} = ones(n_copy,1) * joint(i_joint).dof(nq).spring.equal2{i_coeff} ;
                                    if i_copy == 1 && numel( joint(i_joint).dof(nq).spring.equal2{i_coeff}(:,1) ) < n_copy
                                        joint(i_joint).dof(nq).spring.equal2{i_coeff}(n_copy,end) = 0 ;
                                    end
                                end
								% Here, same joint is not allowed: joint(i_joint).dof(nq).spring.equal2{i_coeff}(n_copy,1) = i_joint
								if numel( joint(i_joint).dof(nq).spring.equal2{i_coeff}(1,:) ) == 2 % [n_j, n_h]
									joint(i_joint).dof(nq).spring.equal2{i_coeff} = [ joint(i_joint).dof(nq).spring.equal2{i_coeff}(:,1) ones(n_copy,1) joint(i_joint).dof(nq).spring.equal2{i_coeff}(:,2) zeros(n_copy,4) ] ;                           
								end
								if numel( joint(i_joint).dof(nq).spring.equal2{i_coeff}(1,:) ) == 3 % [n_j, n_h, i_coeff]
									joint(i_joint).dof(nq).spring.equal2{i_coeff} = [ joint(i_joint).dof(nq).spring.equal2{i_coeff}(:,1) ones(n_copy,1) joint(i_joint).dof(nq).spring.equal2{i_coeff}(:,2:3) zeros(n_copy,3) ] ;                   
								end
							end							
                        end
                    end
                    if ~isfield( joint(i_joint).dof(nq) ,'dir' ) || isempty( joint(i_joint).dof(nq).dir )
                        joint(i_joint).dof(nq).dir = zeros(n_copy,n_coeff+1) ;
                    else
                        joint(i_joint).dof(nq).dir = ones(1,n_coeff+1) .* ones(n_copy,1) .* joint(i_joint).dof(nq).dir ;
                    end
                    if ~isfield( joint(i_joint).dof(nq) ,'damp' ) || isempty( joint(i_joint).dof(nq).damp )
                        joint(i_joint).dof(nq).damp.visc = zeros(n_copy,n_coeff+1) ;
                        joint(i_joint).dof(nq).damp.pow = ones(n_copy,n_coeff+1) ;
                    else
                        if ~isfield( joint(i_joint).dof(nq).damp ,'visc' ) || isempty( joint(i_joint).dof(nq).damp.visc )
                            joint(i_joint).dof(nq).damp.visc = zeros(n_copy,n_coeff+1) ;
                        else
                            joint(i_joint).dof(nq).damp.visc = ones(1,n_coeff+1) .* ones(n_copy,1) .* joint(i_joint).dof(nq).damp.visc ;
                        end
                        if ~isfield( joint(i_joint).dof(nq).damp ,'pow' ) || isempty( joint(i_joint).dof(nq).damp.pow )
                            joint(i_joint).dof(nq).damp.pow = ones(n_copy,n_coeff+1) ;
                        else
                            joint(i_joint).dof(nq).damp.pow = ones(1,n_coeff+1) .* ones(n_copy,1) .* joint(i_joint).dof(nq).damp.pow ;
                        end
                    end
                    if ~isfield( joint(i_joint).dof(nq) ,'input' ) || isempty( joint(i_joint).dof(nq).input )
                        joint(i_joint).dof(nq).input = zeros(n_copy,n_coeff+1) ;
                    else
						if numel( joint(i_joint).dof(nq).input(1,:) ) < n_coeff + 1
							joint(i_joint).dof(nq).input(:,n_coeff+1) = 0 ;
						end
                        joint(i_joint).dof(nq).input = ones(1,n_coeff+1) .* ones(n_copy,1) .* joint(i_joint).dof(nq).input ;
                    end
                    if ~isfield( joint(i_joint).dof(nq) , 'fixed' ) || isempty( joint(i_joint).dof(nq).fixed )
                        joint(i_joint).dof(nq).fixed = zeros(n_copy,n_coeff+1) ;
                    else
						if numel( joint(i_joint).dof(nq).fixed(1,:) ) < n_coeff + 1
							joint(i_joint).dof(nq).fixed(:,n_coeff+1) = 0 ;
						end
                        joint(i_joint).dof(nq).fixed = ones(1,n_coeff+1) .* ones(n_copy,1) .* joint(i_joint).dof(nq).fixed ;
                    end
                    if ~isfield( joint(i_joint).dof(nq) , 'control' ) || isempty( joint(i_joint).dof(nq).control )
                        joint(i_joint).dof(nq).control = zeros(n_copy,n_coeff+1) ;
                    else
						if numel( joint(i_joint).dof(nq).control(1,:) ) < n_coeff + 1
							joint(i_joint).dof(nq).control(:,n_coeff+1) = 0 ;
						end
                        joint(i_joint).dof(nq).control = ones(1,n_coeff+1) .* ones(n_copy,1) .* joint(i_joint).dof(nq).control ;
                    end
                    if ~isfield( joint(i_joint).dof(nq) , 'pid' ) || isempty( joint(i_joint).dof(nq).pid )
                        joint(i_joint).dof(nq).pid = joint_temp.dof.pid ;
                    end
                    if ~isfield( joint(i_joint).dof(nq).pid , 'p' ) || isempty( joint(i_joint).dof(nq).pid.p )
                        joint(i_joint).dof(nq).pid.p = ones(n_copy,1) .* ones(1,n_coeff+1) .* joint_temp.dof.pid.p ;
                    else
                        if numel( joint(i_joint).dof(nq).pid.p(1,:) ) < n_coeff+1
                            joint(i_joint).dof(nq).pid.p = ones(1,n_coeff+1) .* joint(i_joint).dof(nq).pid.p ;
                        end
                        joint(i_joint).dof(nq).pid.p = ones(n_copy,1) .* joint(i_joint).dof(nq).pid.p ;
                    end
                    if ~isfield( joint(i_joint).dof(nq).pid , 'i' ) || isempty( joint(i_joint).dof(nq).pid.i )
                        joint(i_joint).dof(nq).pid.i = ones(n_copy,1) .* ones(1,n_coeff+1) .* joint_temp.dof.pid.i ;
                    else
                        if numel( joint(i_joint).dof(nq).pid.i(1,:) ) < n_coeff+1
                            joint(i_joint).dof(nq).pid.i = ones(1,n_coeff+1) .* joint(i_joint).dof(nq).pid.i ;
                        end
                        joint(i_joint).dof(nq).pid.i = ones(n_copy,1) .* joint(i_joint).dof(nq).pid.i ;
                    end
                    if ~isfield( joint(i_joint).dof(nq).pid , 'd' ) || isempty( joint(i_joint).dof(nq).pid.d )
                        joint(i_joint).dof(nq).pid.d = ones(n_copy,1) .* ones(1,n_coeff+1) .* joint_temp.dof.pid.d ;
                    else
                        if numel( joint(i_joint).dof(nq).pid.d(1,:) ) < n_coeff+1
                            joint(i_joint).dof(nq).pid.d = ones(1,n_coeff+1) .* joint(i_joint).dof(nq).pid.d ;
                        end
                        joint(i_joint).dof(nq).pid.d = ones(n_copy,1) .* joint(i_joint).dof(nq).pid.d ;
                    end
                    if ~isfield( joint(i_joint).dof(nq) ,'s' ) || isempty( joint(i_joint).dof(nq).s )
                        joint(i_joint).dof(nq).s = [] ;
                    end
                end
                
                if joint(i_joint).rom.isROM
                    if ~isfield( joint(i_joint).dof(nq) , 'init_s' ) || isempty( joint(i_joint).dof(nq).init_s ) || max( double( abs( subs( joint(i_joint).dof(nq).init_s(1,:), par.sym, par.var ) ) ) ) == 0
                        if ~isempty( joint(i_joint).rom.init_s )
                            joint(i_joint).dof(nq).init_s(i_copy,:) = ones(n_copy,1) .* joint(i_joint).rom.init_s ;
                        else
                            for i_copy = 1 : n_copy
                                joint(i_joint).dof(nq).init_s(i_copy,:) = linspace( joint(i_joint).rom.length(i_copy,1) , joint(i_joint).rom.length(i_copy,2) , numel( joint(i_joint).dof(nq).init(i_copy,:) ) ) ;
                            end
                        end
                    end                    
                    if numel( joint(i_joint).dof(nq).init_s(1,:) ) == numel( joint(i_joint).dof(nq).init(1,:) )
                        joint(i_joint).dof(nq).init_s = ones(n_copy,1) .* joint(i_joint).dof(nq).init_s ;
                    else
                        error( 'numel( joint(i_joint).dof(nq).init_s ) ~= numel( joint(i_joint).dof(nq).init ) error' ) ;
                    end
                    % spring initial shape
                    if ~isfield( joint(i_joint).dof(nq).spring , 'init_s' ) || isempty( joint(i_joint).dof(nq).spring.init_s )|| max( double( abs( subs( joint(i_joint).dof(nq).spring.init_s(1,:), par.sym, par.var ) ) ) ) == 0
                        if ~isempty( joint(i_joint).rom.init_s )
                            joint(i_joint).dof(nq).spring.init_s(i_copy,:) = ones(n_copy,1) .* joint(i_joint).rom.init_s ;
                        else
                            for i_copy = 1 : n_copy
                                joint(i_joint).dof(nq).spring.init_s(i_copy,:) = linspace( joint(i_joint).rom.length(i_copy,1) , joint(i_joint).rom.length(i_copy,2) , numel( joint(i_joint).dof(nq).spring.init(i_copy,:) ) ) ;
                            end
                        end
                    end
                    if isnan( joint(i_joint).dof(nq).spring.init(1,1) ) || numel( joint(i_joint).dof(nq).spring.init_s(1,:) ) == numel( joint(i_joint).dof(nq).spring.init(1,:) )
                        joint(i_joint).dof(nq).spring.init_s = ones(n_copy,1) .* joint(i_joint).dof(nq).spring.init_s ;
                    else
                        error( 'numel( joint(i_joint).dof(nq).spring.init_s ) ~= numel( joint(i_joint).dof(nq).spring.init ) error' ) ;
                    end
                end
                                
            end
            
        end
        
    end
    
    if ~isfield( joint(i_joint) ,'tr2nd' ) || isempty( joint(i_joint).tr2nd )
        joint(i_joint).tr2nd = joint_temp.tr ;
    else
        if ~isfield( joint(i_joint).tr2nd ,'trans' )
            joint(i_joint).tr2nd.trans = [] ;
        end
        if ~isfield( joint(i_joint).tr2nd ,'rot' )
            joint(i_joint).tr2nd.rot = [] ;
            joint(i_joint).tr2nd.type = 'none' ;
        end
        if ~isfield( joint(i_joint).tr2nd ,'type' )
            joint(i_joint).tr2nd.type = 'none' ;
        end
    end
    
    if joint(i_joint).mainkin == 0 % joint not in main kin. chain
        for i = 1 : numel( joint(i_joint).tr2nd )
            if ~isfield( joint(i_joint).tr2nd(i) ,'trans' ) || isempty( joint(i_joint).tr2nd(i).trans )
                joint(i_joint).tr2nd(i).trans = [ 0 0 0 ] ;
            end
            if ~isfield( joint(i_joint).tr2nd(i) ,'rot' ) || isempty( joint(i_joint).tr2nd(i).rot )
                joint(i_joint).tr2nd(i).rot = [ 1 0 0 0 ] ;
                joint(i_joint).tr2nd(i).type = 'none' ;
            end
            if ~isfield( joint(i_joint).tr2nd(i) ,'type' ) || isempty( joint(i_joint).tr2nd(i).type )
                joint(i_joint).tr2nd(i).type = 'none' ;
            end
        end
    end
    if ~isfield( joint(i_joint) , 'dir' ) || isempty( joint(i_joint).dir )
        joint(i_joint).dir = zeros(n_copy,1) ;
    else
        if numel( joint(i_joint).dir(:,1) ) == 1
            joint(i_joint).dir = ones(n_copy,1) * joint(i_joint).dir(1,:) ;
        end
    end
    if ~isfield( joint(i_joint) , 'xaxis' ) || isempty( joint(i_joint).xaxis )
        joint(i_joint).xaxis = [] ; % default in local frame defined by joint.tr
    else
        if numel( joint(i_joint).xaxis(:,1) ) == 1
            joint(i_joint).xaxis = ones(n_copy,1) * joint(i_joint).xaxis(1,:) ;
        end
    end
    if ~isfield( joint(i_joint) , 'spring' ) % constraint
        joint(i_joint).spring = joint_temp.spring ;
    else
        if ~isfield( joint(i_joint).spring , 'coeff' ) % constraint
            joint(i_joint).spring.coeff = [] ;
        end
        if ~isfield( joint(i_joint).spring , 'init' ) % constraint
            joint(i_joint).spring.init = [] ;
        end
        if ~isfield( joint(i_joint).spring , 'compr' ) % constraint
            joint(i_joint).spring.compr = [] ;
        end
    end
    if ~isempty( joint(i_joint).spring.coeff )
        if ~isfield( joint(i_joint).spring , 'coeff' ) || isempty( joint(i_joint).spring.coeff )
            joint(i_joint).spring.coeff = zeros(n_copy,1) ;
        else
            if numel( joint(i_joint).spring.coeff(:,1) ) == 1
                joint(i_joint).spring.coeff = ones(n_copy,1) * joint(i_joint).spring.coeff(1,:) ;
            end
        end
        if ~isfield( joint(i_joint).spring , 'init' ) || isempty( joint(i_joint).spring.init )
            joint(i_joint).spring.init = zeros(n_copy,numel(joint(i_joint).spring.coeff(1,:))) ;
        end
        if numel( joint(i_joint).spring.init(1,:) ) == 1
            joint(i_joint).spring.init = joint(i_joint).spring.init(1,:) * ones(1,numel(joint(i_joint).spring.coeff(1,:))) ;
        end
        if numel( joint(i_joint).spring.init(:,1) ) == 1
            joint(i_joint).spring.init = ones(n_copy,1) * joint(i_joint).spring.init(1,:) ;
        end
        if ~isfield( joint(i_joint).spring , 'compr' ) || isempty( joint(i_joint).spring.compr )
            joint(i_joint).spring.compr = ones(n_copy,numel(joint(i_joint).spring.coeff(1,:))) ;
        end
        if numel( joint(i_joint).spring.compr(1,:) ) == 1
            joint(i_joint).spring.compr = joint(i_joint).spring.compr(1,:) * ones(1,numel(joint(i_joint).spring.coeff(1,:))) ;
        end
        if numel( joint(i_joint).spring.compr(:,1) ) == 1
            joint(i_joint).spring.compr = ones(n_copy,1) * joint(i_joint).spring.compr(1,:) ;
        end
        if ~isfield( joint(i_joint) , 'damp' ) || isempty( joint(i_joint).damp )
            joint(i_joint).damp.visc = zeros(n_copy,numel(joint(i_joint).spring.coeff(1,:))) ;
            joint(i_joint).damp.pow = ones(n_copy,numel(joint(i_joint).spring.coeff(1,:))) ;
        end
        if ~isfield( joint(i_joint) , 'input' ) || isempty( joint(i_joint).input )
            joint(i_joint).input = zeros(n_copy,numel(joint(i_joint).spring.coeff(1,:))) ;
        end
    end
    if ~isfield( joint(i_joint) , 'damp' ) % constraint
        joint(i_joint).damp = joint_temp.damp ;
    else
        if ~isfield( joint(i_joint).damp , 'visc' ) % constraint
            joint(i_joint).damp.visc = [] ;
        end
        if ~isfield( joint(i_joint).damp , 'pow' ) % constraint
            joint(i_joint).damp.pow = 1 ;
        end
    end
    if ~isempty( joint(i_joint).damp.visc )
        if numel( joint(i_joint).damp.visc(:,1) ) == 1
            joint(i_joint).damp.visc = ones(n_copy,1) * joint(i_joint).damp.visc(1,:) ;
        end
        if ~isfield( joint(i_joint).damp , 'pow' ) || isempty( joint(i_joint).damp.pow )
            joint(i_joint).damp.pow = ones(n_copy,numel(joint(i_joint).damp.visc(1,:))) ;
        end
        if numel( joint(i_joint).damp.pow(1,:) ) == 1
            joint(i_joint).damp.pow = joint(i_joint).damp.pow(1,:) * ones(1,numel(joint(i_joint).damp.visc(1,:))) ;
        end
        if numel( joint(i_joint).damp.pow(:,1) ) == 1
            joint(i_joint).damp.pow = ones(n_copy,1) * joint(i_joint).damp.pow(1,:) ;
        end
        if ~isfield( joint(i_joint) , 'spring' ) || isempty( joint(i_joint).spring )
            joint(i_joint).spring.coeff = zeros(n_copy,numel(joint(i_joint).damp.visc(1,:))) ;
            joint(i_joint).spring.init = zeros(n_copy,numel(joint(i_joint).damp.visc(1,:))) ;
            joint(i_joint).spring.compr = ones(n_copy,numel(joint(i_joint).damp.visc(1,:))) ;
        end
        if ~isfield( joint(i_joint) , 'input' ) || isempty( joint(i_joint).input )
            joint(i_joint).input = zeros(n_copy,numel(joint(i_joint).damp.visc(1,:))) ;
        end
    end
    if ~isfield( joint(i_joint) , 'input' )
        joint(i_joint).input = 0 ;
    end
    if ~isempty( joint(i_joint).input )
        if numel( joint(i_joint).input(:,1) ) == 1
            joint(i_joint).input = ones(n_copy,1) * joint(i_joint).input(1,:) ;
        end
        if ~isfield( joint(i_joint) , 'spring' ) || isempty( joint(i_joint).spring )
            joint(i_joint).spring.coeff = zeros(n_copy,numel(joint(i_joint).input(1,:))) ;
            joint(i_joint).spring.init = zeros(n_copy,numel(joint(i_joint).input(1,:))) ;
            joint(i_joint).spring.compr = ones(n_copy,numel(joint(i_joint).input(1,:))) ;
        end
        if ~isfield( joint(i_joint) , 'damp' ) || isempty( joint(i_joint).damp )
            joint(i_joint).damp.visc = zeros(n_copy,numel(joint(i_joint).input(1,:))) ;
            joint(i_joint).damp.pow = ones(n_copy,numel(joint(i_joint).input(1,:))) ;
        end
    end
    if ~isfield( joint(i_joint) , 'fixed' )
        joint(i_joint).fixed = [] ;
    end
    if ~isempty( joint(i_joint).fixed )
        if numel( joint(i_joint).fixed(1,:) ) > 7
            error( 'numel( joint(i_joint).fixed(1,:) ) error!' ) ;
        end
        if numel( joint(i_joint).fixed(1,:) ) < 6
            joint(i_joint).fixed = [ joint(i_joint).fixed, zeros( numel( joint(i_joint).fixed(:,1) ) , 7 - numel( joint(i_joint).fixed(1,:) ) ) ] ;
        end
        if numel( joint(i_joint).fixed(:,1) ) == 1
            joint(i_joint).fixed = ones(n_copy,1) * joint(i_joint).fixed(1,:) ;
        end
        if ~isfield( joint(i_joint) , 'control' ) || isempty( joint(i_joint).control )
            joint(i_joint).control = zeros(n_copy, numel( joint(i_joint).fixed(1,:) )) ;
        else
            if numel( joint(i_joint).control(1,:) ) == 1
                joint(i_joint).control = joint(i_joint).control(1,:) * ones(1, numel( joint(i_joint).fixed(1,:) )) ;
            end
            if numel( joint(i_joint).control(1,:) ) < numel( joint(i_joint).fixed(1,:) )
                joint(i_joint).control = [ joint(i_joint).control, zeros( numel( joint(i_joint).control(:,1) ) , 7 - numel( joint(i_joint).control(1,:) ) ) ] ;
            end
            if numel( joint(i_joint).control(:,1) ) == 1
                joint(i_joint).control = ones(n_copy,1) * joint(i_joint).control(1,:) ;
            end
            if numel(joint(i_joint).control(1,:)) ~= numel( joint(i_joint).fixed(1,:) )
                error( 'numel(joint(i_joint).control(1,:)) ~= numel( joint(i_joint).fixed(1,:) ) error!' ) ;
            end
        end
        if ~isfield( joint(i_joint) ,'refbody' ) || isempty( joint(i_joint).refbody )
            joint(i_joint).refbody = ones(n_copy,1) * [ 0 1 0 ] ; % [body_no mesh_no location_lengh]
        else
            if numel( joint(i_joint).refbody(1,:) ) == 1
                joint(i_joint).refbody(:,2:3) = [ 1 0 ] ;
            end
            if numel( joint(i_joint).refbody(:,1) ) == 1
                joint(i_joint).refbody = ones(n_copy,1) * joint(i_joint).refbody(1,:) ;
            end
        end
        if isempty( joint(i_joint).spring.coeff )
            joint(i_joint).spring.coeff = zeros(n_copy,6) ;
        else
            if numel( joint(i_joint).spring.coeff(1,:) ) == 1
                joint(i_joint).spring.coeff = joint(i_joint).spring.coeff * ones(1,6) ;
            end
            if numel( joint(i_joint).spring.coeff(:,1) ) == 1
                joint(i_joint).spring.coeff = ones(n_copy,1) * joint(i_joint).spring.coeff ;
            end
            if numel( joint(i_joint).spring.coeff(1,:) ) ~= 6
                error( 'numel( joint(i_joint).spring.coeff(1,:) ) ~= 6 error!' ) ;
            end
        end
        if isempty( joint(i_joint).spring.init )
            joint(i_joint).spring.init = zeros(n_copy,6) ;
        else
            if numel( joint(i_joint).spring.init(1,:) ) == 1
                joint(i_joint).spring.init = joint(i_joint).spring.init * ones(1,6) ;
            end
            if numel( joint(i_joint).spring.init(:,1) ) == 1
                joint(i_joint).spring.init = ones(n_copy,1) * joint(i_joint).spring.init ;
            end
            if numel( joint(i_joint).spring.init(1,:) ) ~= 6
                error( 'numel( joint(i_joint).spring.init(1,:) ) ~= 6 error!' ) ;
            end
        end
        if isempty( joint(i_joint).spring.compr )
            joint(i_joint).spring.compr = ones(n_copy,6) ;
        else
            if numel( joint(i_joint).spring.compr(1,:) ) == 1
                joint(i_joint).spring.compr = joint(i_joint).spring.compr * ones(1,6) ;
            end
            if numel( joint(i_joint).spring.compr(:,1) ) == 1
                joint(i_joint).spring.compr = ones(n_copy,1) * joint(i_joint).spring.compr ;
            end
            if numel( joint(i_joint).spring.compr(1,:) ) ~= 6
                error( 'numel( joint(i_joint).spring.compr(1,:) ) ~= 6 error!' ) ;
            end
        end
        if isempty( joint(i_joint).damp.visc )
            joint(i_joint).damp.visc = zeros(n_copy,6) ;
        else
            if numel( joint(i_joint).damp.visc(1,:) ) == 1
                joint(i_joint).damp.visc = joint(i_joint).damp.visc * ones(1,6) ;
            end
            if numel( joint(i_joint).damp.visc(:,1) ) == 1
                joint(i_joint).damp.visc = ones(n_copy,1) * joint(i_joint).damp.visc  ;
            end
            if numel( joint(i_joint).damp.visc(1,:) ) ~= 6
                error( 'numel( joint(i_joint).damp.visc(1,:) ) ~= 6 error!' ) ;
            end
        end
        if isempty( joint(i_joint).damp.pow )
            joint(i_joint).damp.pow = ones(n_copy,6) ;
        else
            if numel( joint(i_joint).damp.pow(1,:) ) == 1
                joint(i_joint).damp.pow = joint(i_joint).damp.pow * ones(1,6) ;
            end
            if numel( joint(i_joint).damp.pow(:,1) ) == 1
                joint(i_joint).damp.pow = ones(n_copy,1) * joint(i_joint).damp.pow  ;
            end
            if numel( joint(i_joint).damp.pow(1,:) ) ~= 6
                error( 'numel( joint(i_joint).damp.pow(1,:) ) ~= 6 error!' ) ;
            end
        end
        if isempty( joint(i_joint).input )
            joint(i_joint).input = zeros(n_copy,6) ;
        else
            if numel( joint(i_joint).input(1,:) ) == 1
                joint(i_joint).input = joint(i_joint).input * ones(1,6) ;
            end
            if numel( joint(i_joint).input(:,1) ) == 1
                joint(i_joint).input = ones(n_copy,1) * joint(i_joint).input ;
            end
            if numel( joint(i_joint).input(1,:) ) ~= 6
                error( 'numel( joint(i_joint).input(1,:) ) ~= 6 error!' ) ;
            end
        end
    end
    if joint(i_joint).rom.isROM
        if isempty( joint(i_joint).spring.coeff )
            joint(i_joint).spring.coeff = zeros(n_copy,6) ;
        else
            if numel( joint(i_joint).spring.coeff(1,:) ) == 1
                joint(i_joint).spring.coeff = joint(i_joint).spring.coeff * ones(1,6) ;
            end
            if numel( joint(i_joint).spring.coeff(:,1) ) == 1
                joint(i_joint).spring.coeff = ones(n_copy,1) * joint(i_joint).spring.coeff ;
            end
            if numel( joint(i_joint).spring.coeff(1,:) ) ~= 6
                error( 'numel( joint(i_joint).spring.coeff(1,:) ) ~= 6 error!' ) ;
            end
        end
        if isempty( joint(i_joint).spring.init ) % [ number of points along backbone x 6 ]
            joint(i_joint).spring.init = zeros(n_copy,6) ;
        else
            if numel( joint(i_joint).spring.init(1,:) ) == 1
                joint(i_joint).spring.init = joint(i_joint).spring.init * ones(1,6) ;
            end
            if numel( joint(i_joint).spring.init(:,1) ) == 1
                joint(i_joint).spring.init = ones(n_copy,1) * joint(i_joint).spring.init ;
            end
            if numel( joint(i_joint).spring.init(1,:) ) ~= 6
                error( 'numel( joint(i_joint).spring.init(1,:) ) ~= 6 error!' ) ;
            end
        end
        if isempty( joint(i_joint).spring.compr )
            joint(i_joint).spring.compr = ones(n_copy,6) ;
        else
            if numel( joint(i_joint).spring.compr(1,:) ) == 1
                joint(i_joint).spring.compr = joint(i_joint).spring.compr * ones(1,6) ;
            end
            if numel( joint(i_joint).spring.compr(:,1) ) == 1
                joint(i_joint).spring.compr = ones(n_copy,1) * joint(i_joint).spring.compr ;
            end
            if numel( joint(i_joint).spring.compr(1,:) ) ~= 6
                error( 'numel( joint(i_joint).spring.compr(1,:) ) ~= 6 error!' ) ;
            end
        end
        if isempty( joint(i_joint).damp.visc )
            joint(i_joint).damp.visc = zeros(n_copy,6) ;
        else
            if numel( joint(i_joint).damp.visc(1,:) ) == 1
                joint(i_joint).damp.visc = joint(i_joint).damp.visc * ones(1,6) ;
            end
            if numel( joint(i_joint).damp.visc(:,1) ) == 1
                joint(i_joint).damp.visc = ones(n_copy,1) * joint(i_joint).damp.visc ;
            end
            if numel( joint(i_joint).damp.visc(1,:) ) ~= 6
                error( 'numel( joint(i_joint).damp.visc(1,:) ) ~= 6 error!' ) ;
            end
        end
        if isempty( joint(i_joint).damp.pow )
            joint(i_joint).damp.pow = ones(n_copy,6) ;
        else
            if numel( joint(i_joint).damp.pow(1,:) ) == 1
                joint(i_joint).damp.pow = joint(i_joint).damp.pow * ones(1,6) ;
            end
            if numel( joint(i_joint).damp.pow(:,1) ) == 1
                joint(i_joint).damp.pow = ones(n_copy,1) * joint(i_joint).damp.pow ;
            end
            if numel( joint(i_joint).damp.pow(1,:) ) ~= 6
                error( 'numel( joint(i_joint).damp.pow(1,:) ) ~= 6 error!' ) ;
            end
        end
        if isempty( joint(i_joint).input )
            joint(i_joint).input = zeros(n_copy,6) ;
        else
            if numel( joint(i_joint).input(1,:) ) == 1
                joint(i_joint).input = joint(i_joint).input * ones(1,6) ;
            end
            if numel( joint(i_joint).input(:,1) ) == 1
                joint(i_joint).input = ones(n_copy,1) * joint(i_joint).input ;
            end
            if numel( joint(i_joint).input(1,:) ) ~= 6
                error( 'numel( joint(i_joint).input(1,:) ) ~= 6 error!' ) ;
            end
        end
    end
    if numel( joint(i_joint).spring.init ) == 1 && isnan( joint(i_joint).spring.init )
        joint(i_joint).spring.init = [ nan nan nan nan nan nan ] ;
    end
    if ~isfield( joint(i_joint) , 'radi' ) || isempty( joint(i_joint).radi ) % cross-section radius for plotting
        joint(i_joint).radi = ones(n_copy,1) * joint_temp.radi ;
    else
        joint(i_joint).radi = ones(n_copy,1) * joint(i_joint).radi ;
    end
    
end


% final check
for i_joint = 1 : numel( joint )
    if ~isfield( joint(i_joint) , 'first' )
        joint(i_joint).first = [] ;
    end
    if ~isfield( joint(i_joint) , 'second' )
        joint(i_joint).second = [] ;
    end
    if ~isfield( joint(i_joint) , 'rom' )
        joint(i_joint).rom = joint_temp.rom;
    end
    if ~isfield( joint(i_joint) ,'tr' )
        joint(i_joint).tr = joint_temp.tr ;
    end
    if ~isfield( joint(i_joint) , 'dof' )
        joint(i_joint).dof = joint_temp.dof ;
    end
    if ~isfield( joint(i_joint) ,'tr2nd' )
        joint(i_joint).tr2nd = joint_temp.tr ;
    end
    if ~isfield( joint(i_joint) , 'dir' )
        joint(i_joint).dir = 0 ;
    end
    if ~isfield( joint(i_joint) , 'xaxis' )
        joint(i_joint).xaxis = [] ;
    end
    if ~isfield( joint(i_joint) , 'spring' )
        joint(i_joint).spring = joint_temp.spring ;
    end
    if ~isfield( joint(i_joint) , 'damp' )
        joint(i_joint).damp = joint_temp.damp ;
    end
    if ~isfield( joint(i_joint) , 'input' )
        joint(i_joint).input = 0 ;
    end
    if ~isfield( joint(i_joint) , 'fixed' )
        joint(i_joint).fixed = [] ;
    end
    if ~isfield( joint(i_joint) , 'control' )
        joint(i_joint).control = [] ;
    end
    if ~isfield( joint(i_joint) , 'refbody' )
        joint(i_joint).refbody = [] ;
    end
end


%% body
for i_b = 1 : numel( body )
    
    for j_count = 1 : numel( joint )
        
        if joint(j_count).second(1,1) == i_b
            n_copy = numel( joint(j_count).first(1,:) ) - 1 ;
            
            if ~isfield( body(i_b) ,'m' ) || isempty( body(i_b).m )
                body(i_b).m = body_temp.m ;
            end
            if numel( body(i_b).m ) == 1
                body(i_b).m = ones(n_copy,1) * body(i_b).m ;
            else
                if numel( body(i_b).m(:,1) ) ~= n_copy
                    error( 'body(i_b).m size error!' ) ;
                end
            end
            
            if ~isfield( body(i_b) ,'I' ) || isempty( body(i_b).I )
                body(i_b).I = body_temp.I ;
            end
            if numel( body(i_b).I(1,1,:) ) == 1
                tmp = body(i_b).I(:,:) ;
                for i_copy = 1 : n_copy
                    body(i_b).I(:,:,i_copy) = tmp ;
                end
            else
                if numel( body(i_b).I(1,1,:) ) ~= n_copy
                    error( 'body(i_b).I size error!' ) ;
                end
            end
            
            if ~isfield( body(i_b) ,'radi' ) || isempty( body(i_b).radi )
                body(i_b).radi = ones(n_copy,1) * body_temp.radi ;
            else
                body(i_b).radi = ones(n_copy,1) * body(i_b).radi ;
            end
            
            if ~isfield( body(i_b) ,'l_com' ) || isempty( body(i_b).l_com )
                body(i_b).l_com = body_temp.l_com ;
            end
            if numel( body(i_b).l_com(:,1) ) == 1
                body(i_b).l_com = ones(n_copy,1) * body(i_b).l_com  ;
            else
                if numel( body(i_b).l_com(:,1) ) ~= n_copy
                    error( 'body(i_b).l_com size error!' ) ;
                end
            end
            
            if ~isfield( body(i_b) ,'tip' ) || isempty( body(i_b).tip )
                body(i_b).tip = 2 * body(i_b).l_com ;
            end
            if numel( body(i_b).tip(:,1) ) == 1
                body(i_b).tip = ones(n_copy,1) * body(i_b).tip  ;
            else
                if numel( body(i_b).tip(:,1) ) ~= n_copy
                    error( 'body(i_b).tip size error!' ) ;
                end
            end
            
            break ;
            
        end
        
    end
    
end

% final check
for i_b = 1 : numel( body )
    if ~isfield( body(i_b) ,'m' )
        body(i_b).m = ones(n_copy,1) * body_temp.m ;
    end
    if ~isfield( body(i_b) ,'I' )
        body(i_b).I = ones(n_copy,1) * body_temp.I ;
    end
    if ~isfield( body(i_b) ,'radi' )
        body(i_b).radi = ones(n_copy,1) * body_temp.radi ;
    end
    if ~isfield( body(i_b) ,'l_com' )
        body(i_b).l_com = [] ;
    end
    if ~isfield( body(i_b) ,'tip' )
        body(i_b).tip = [] ;
    end
end


%% exload
for i_l = 1 : numel( exload )
    
    if ~isempty( exload(i_l).exbody )
        
        if ~isfield( exload(i_l) ,'exbody' ) || isempty( exload(i_l).exbody )
            error( 'exload.exbody' ) ;
        end
        if numel( exload(i_l).exbody(:,1) ) == 1 % [body_no, mesh_no; 0, location_lengh]
            exload(i_l).exbody(2,1) = 0;
        end
        n_copy = numel( exload(i_l).exbody(1,:) ) ;
        if n_copy > 1
            n_copy = n_copy - 1 ;
        else
            exload(i_l).exbody(1,2) = 1 ;
        end
        if ~isfield( exload(i_l) ,'refbody' ) || isempty( exload(i_l).refbody )
            exload(i_l).refbody = ones(n_copy,1) * [ 0 1 0 ] ; % wrt ref frame by default: [body_no mesh_no location_lengh]
        else
            if numel( exload(i_l).refbody(1,:) ) == 1
                exload(i_l).refbody(:,2:3) = [ 1 0 ] ;
            end
            if numel( exload(i_l).refbody(:,1) ) == 1
                exload(i_l).refbody = ones(n_copy,1) * exload(i_l).refbody(1,:) ;
            end
        end
        
        if ~isfield( exload(i_l) ,'tr' ) || isempty( exload(i_l).tr )
            exload(i_l).tr.trans = [ 0 0 0 ] ;
            exload(i_l).tr.rot = [ 1 0 0 0 ] ;
            exload(i_l).tr.type = 'none' ;
        end
        for i = 1 : numel( exload(i_l).tr )
            if ~isfield( exload(i_l).tr(i) ,'trans' ) || isempty( exload(i_l).tr(i).trans )
                exload(i_l).tr(i).trans = [ 0 0 0 ] ;
            end
            if ~isfield( exload(i_l).tr(i) ,'rot' ) || isempty( exload(i_l).tr(i).rot )
                exload(i_l).tr(i).rot = [ 1 0 0 0 ] ;
                exload(i_l).tr(i).type = 'none' ;
            end
            if ~isfield( exload(i_l).tr(i) ,'type' ) || isempty( exload(i_l).tr(i).type )
                exload(i_l).tr(i).type = 'none' ;
            end
        end
        if ~isfield( exload(i_l) ,'ftau' ) || isempty( exload(i_l).ftau )
            exload(i_l).ftau = zeros(n_copy,6) ;
        else
            if numel( exload(i_l).ftau(:,1) ) == 1
                exload(i_l).ftau = ones(n_copy,1) * exload(i_l).ftau(1,:) ;
            end
        end
        if numel( exload(i_l).ftau(1,:) ) ~= 6
            exload(i_l).ftau = [ exload(i_l).ftau zeros( n_copy , 6 - numel( exload(i_l).ftau ) ) ] ;
        end
        
    end
    
end


%% mesh
for i_copy = 1 : numel( mesh )
    
    if ~isempty( mesh(i_copy).file_name )
        
        if ~isfield( mesh(i_copy) ,'file_name' ) || isempty( mesh(i_copy).file_name )
            error( 'mesh(i_copy).file_name' ) ;
        end
        if ~isfield( mesh(i_copy) ,'tol' ) || isempty( mesh(i_copy).tol )
            mesh(i_copy).tol = 1e-4 ;
        end
        if ~isfield( mesh(i_copy) ,'body' ) || isempty( mesh(i_copy).body )
            error( 'mesh(i_copy).body' ) ;
        end
        if ~isfield( mesh(i_copy) ,'joint' ) || isempty( mesh(i_copy).joint ) || numel( mesh(i_copy).joint ) ~= 2
            error( 'mesh(i_copy).joint' ) ;
        end
        if ~isfield( mesh(i_copy) ,'tr' ) || isempty( mesh(i_copy).tr )
            mesh(i_copy).tr.trans = [ 0 0 0 ] ;
            mesh(i_copy).tr.rot = [ 1 0 0 0 ] ;
            mesh(i_copy).tr.init_quat = [ 1 0 0 0 ] ;
            mesh(i_copy).tr.type = 'none' ;
        end
        for i = 1 : numel( mesh(i_copy).tr )
            if ~isfield( mesh(i_copy).tr(i) ,'trans' ) || isempty( mesh(i_copy).tr(i).trans )
                mesh(i_copy).tr(i).trans = [ 0 0 0 ] ;
            end
            if ~isfield( mesh(i_copy).tr(i) ,'rot' ) || isempty( mesh(i_copy).tr(i).rot )
                mesh(i_copy).tr(i).rot = [ 1 0 0 0 ] ;
                mesh(i_copy).tr(i).init_quat = [ 1 0 0 0 ] ;
                mesh(i_copy).tr(i).type = 'none' ;
            end
            if ~isfield( mesh(i_copy).tr(i) ,'init_quat' ) || isempty( mesh(i_copy).tr(i).init_quat )
                mesh(i_copy).tr(i).init_quat = [ 1 0 0 0 ] ;
            end
            if ~isfield( mesh(i_copy).tr(i) ,'type' ) || isempty( mesh(i_copy).tr(i).type )
                mesh(i_copy).tr(i).type = 'none' ;
            end
        end
        
    end
    
end


