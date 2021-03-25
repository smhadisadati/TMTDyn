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
for i_j = 1 : numel( joint )
    nq = 0 ; % number of dof.s
    
    if ~isfield( joint(i_j) , 'first' ) || isempty( joint(i_j).first )
        joint(i_j).first = [ 0 1 ; 0 0 ] ; % [body_no, mesh_no; 0, location_lengh]
    end
    
    if ~isfield( joint(i_j) , 'second' ) || isempty( joint(i_j).second )
        joint(i_j).second = [ 0 1 ; 0 0 ] ; % [body_no, mesh_no; 0, location_lengh]
    end
        
    if ~isfield( joint(i_j) , 'mainkin' ) || isempty( joint(i_j).mainkin )
        joint(i_j).mainkin = 0 ;
        for i_b = 1 : numel( body )
            if joint(i_j).second(1,1) == i_b && j_b( i_b ) == 0 % first connected to i_b is in main kin. chain
                j_b( i_b ) = i_j ;
                joint(i_j).mainkin = 1 ;
            end
        end
    end
    
    [ n_copies , ind ] = max( [ numel( joint(i_j).second(1,:) ) , numel( joint(i_j).first(1,:) ) ] ) ;
    if ind == 2 && joint(i_j).mainkin == 1 && numel( joint(i_j).first(1,:) ) > 2 % only acceptable for sprdmp
        i_j
        error( 'main kin. chain joint(i_j).second size error' ) ;
    end
    if n_copies > 1
        n_copies = n_copies - 1 ;
    else
        joint(i_j).first(1,2) = 1 ;
        joint(i_j).second(1,2) = 1 ;
    end
    if numel( joint(i_j).first(1,:) ) ~= numel( joint(i_j).second(1,:) )
        if ind == 2
            if numel( joint(i_j).second(1,:) ) == 1
                joint(i_j).second(1,2:n_copies+1) = 1 ;
            else
                if numel( joint(i_j).second(1,:) ) == 2
                    joint(i_j).second(1,2:n_copies+1) = joint(i_j).second(1,2) ;
                else
                    error( 'numel( joint(i_j).first ) ~= numel( joint(i_j).second )' ) ;
                end
            end
        else
            if numel( joint(i_j).first(1,:) ) == 1
                joint(i_j).first(1,2:n_copies+1) = 1 ;
            else
                if numel( joint(i_j).first(1,:) ) == 2
                    joint(i_j).first(1,2:n_copies+1) = joint(i_j).first(1,2) ;
                else
                    error( 'numel( joint(i_j).first ) ~= numel( joint(i_j).second )' ) ;
                end
            end
        end
    end
    
    if numel( joint(i_j).first(:,1) ) == 1 % fill the length row
        joint(i_j).first(2,1) = 0 ;
    end
    if numel( joint(i_j).second(:,1) ) == 1
        joint(i_j).second(2,1) = 0 ;
    end
    
    if ~isfield( joint(i_j) , 'rom' ) || isempty( joint(i_j).rom )
        joint(i_j).rom = par_temp.rom ;
    end
    if max( max( joint(i_j).rom.order ) ) > 0
        joint(i_j).rom.isROM = 1; % it is a continuum ROM joint
        if ~isfield( joint(i_j).rom , 'order' ) || isempty( joint(i_j).rom.order )
            error( 'joint(i_j).rom.order error' ) ;
        else
            joint(i_j).rom.order =  ones(n_copies,1) .* joint(i_j).rom.order;
        end
        if ~isfield( joint(i_j).rom , 'default_order' ) || isempty( joint(i_j).rom.default_order )
            joint(i_j).rom.default_order = zeros(n_copies,1)  ;
        else
            joint(i_j).rom.default_order =  ones(n_copies,1) .* joint(i_j).rom.default_order;
        end
        if ~isfield( joint(i_j).rom , 'length' ) || isempty( joint(i_j).rom.length )
            error( 'joint(i_j).rom.length error' ) ;
        else
            joint(i_j).rom.length =  ones(n_copies,1) .* joint(i_j).rom.length;
        end
        if ~isfield( joint(i_j).rom , 'rel_base' ) || isempty( joint(i_j).rom.rel_base )
            joint(i_j).rom.rel_base = par_temp.rom.rel_base ;
        else
            joint(i_j).rom.rel_base =  ones(n_copies,1) .* joint(i_j).rom.rel_base;
        end
        if ~isfield( joint(i_j).rom , 'free_base' ) || isempty( joint(i_j).rom.free_base )
            joint(i_j).rom.free_base = par_temp.rom.free_base ;
        else
            joint(i_j).rom.free_base =  ones(n_copies,1) .* joint(i_j).rom.free_base;
        end
        if ~isfield( joint(i_j).rom , 'init_s' )
            joint(i_j).rom.init_s = par_temp.rom.init_s ;
        end
        if ~isfield( joint(i_j).rom , 'fit_type' )
            joint(i_j).rom.fit_type = par_temp.rom.fit_type ;
        end
        if ~isfield( joint(i_j).rom , 'spring_fit_type' )
            joint(i_j).rom.spring_fit_type = par_temp.rom.spring_fit_type ;
        end
        if ~isfield( joint(i_j).rom , 'growth' )
            joint(i_j).rom.growth = par_temp.rom.growth ;
        end
        if ~isfield( joint(i_j).rom , 'simpKnot' )
            joint(i_j).rom.simpKnot = par_temp.rom.simpKnot ;
        end
        if ~isfield( joint(i_j).rom , 'spc_order' )
            joint(i_j).rom.spc_order = par_temp.rom.spc_order ;
        end
        if ~isfield( joint(i_j).rom , 'var_init' )
            joint(i_j).rom.var_init = par_temp.rom.var_init ;
        end
        if ~isfield( joint(i_j).rom , 'stiffmodel' )
            joint(i_j).rom.stiffmodel = par_temp.rom.stiffmodel ;
        end
        if ~isfield( joint(i_j).rom , 'rom_offset' )
            joint(i_j).rom.rom_offset = par_temp.rom.rom_offset ;
        end
        if ~isfield( joint(i_j).rom , 'spring_rom_offset' )
            joint(i_j).rom.spring_rom_offset = par_temp.rom.spring_rom_offset ;
        end
        if ~isfield( joint(i_j).rom , 'singleBody' )
            joint(i_j).rom.singleBody = par_temp.rom.singleBody ;
        end
    else
        joint(i_j).rom.isROM = 0; % it is not a continuum ROM joint
        joint(i_j).rom.order =  ones(n_copies,1) .* joint(i_j).rom.order;
    end
    
    if ~isfield( joint(i_j) ,'tr' ) || isempty( joint(i_j).tr )
        joint(i_j).tr.trans = [ 0 0 0 ] ;
        joint(i_j).tr.rot = [ 1 0 0 0 ] ;
        joint(i_j).tr.init_quat = [ 1 0 0 0 ] ;
        joint(i_j).tr.type = 'none' ;
    end
    
    if ~isfield( joint(i_j) , 'dof' ) || isempty( joint(i_j).dof )
        joint(i_j).dof = joint_temp.dof ;
    end
    
    if ~isfield( joint(i_j) , 'pid' ) || isempty( joint(i_j).pid )
        joint(i_j).pid = joint_temp.pid ;
    end
    if ~isfield( joint(i_j).pid , 'p' ) || isempty( joint(i_j).pid.p )
        joint(i_j).pid.p = ones(n_copies,1) .* ones(1,6) .* joint_temp.pid.p ;
    else
        if numel( joint(i_j).pid.p(1,:) ) < 6
            joint(i_j).pid.p = ones(1,6) .* joint(i_j).pid.p(1,:) ;
        end
        joint(i_j).pid.p = ones(n_copies,1) .* joint(i_j).pid.p ;
    end
    if ~isfield( joint(i_j).pid , 'i' ) || isempty( joint(i_j).pid.i )
        joint(i_j).pid.i = ones(n_copies,1) .* ones(1,6) .* joint_temp.pid.i ;
    else
        if numel( joint(i_j).pid.i(1,:) ) < 6
            joint(i_j).pid.i = ones(1,6) .* joint(i_j).pid.i(1,:) ;
        end
        joint(i_j).pid.i = ones(n_copies,1) .* joint(i_j).pid.i ;
    end
    if ~isfield( joint(i_j).pid , 'd' ) || isempty( joint(i_j).pid.d )
        joint(i_j).pid.d = ones(n_copies,1) .* ones(1,6) .* joint_temp.pid.d ;
    else
        if numel( joint(i_j).pid.d(1,:) ) < 6
            joint(i_j).pid.d = ones(1,6) .* joint(i_j).pid.d(1,:) ;
        end
        joint(i_j).pid.d = ones(n_copies,1) .* joint(i_j).pid.d ;
    end
    for i = 1 : numel( joint(i_j).tr )
        if ~isfield( joint(i_j).tr(i) ,'trans' ) || isempty( joint(i_j).tr(i).trans )
            joint(i_j).tr(i).trans = [ 0 0 0 ] ;
        end
        if ~isfield( joint(i_j).tr(i) ,'rot' ) || isempty( joint(i_j).tr(i).rot )
            joint(i_j).tr(i).rot = [ 1 0 0 0 ] ;
            joint(i_j).tr(i).init_quat = [ 1 0 0 0 ] ;
            joint(i_j).tr(i).type = 'none' ;
        end
        if ~isfield( joint(i_j).tr(i) ,'init_quat' ) || isempty( joint(i_j).tr(i).init_quat )
            joint(i_j).tr(i).init_quat = [ 1 0 0 0 ] ;
        end
        if ~isfield( joint(i_j).tr(i) ,'type' ) || isempty( joint(i_j).tr(i).type )
            joint(i_j).tr(i).type = 'none' ;
        end
        rotrans = [ joint(i_j).tr(i).trans joint(i_j).tr(i).rot ] ;
        for i2 = 1 : numel( rotrans )
            if isinf( rotrans(i2) )
                nq = nq + 1 ;
                if nq > numel( joint(i_j).rom.order(1,:) ) || isnan( joint(i_j).rom.order(1,nq) )
                    joint(i_j).rom.order(:,nq) = ones(n_copies,1) .* joint(i_j).rom.default_order ;
                end
                n_r = joint(i_j).rom.order(n_copies,nq) ;
                if ~isfield( joint(i_j) , 'dof' ) || isempty( joint(i_j).dof ) || numel( joint(i_j).dof ) < nq
                    [joint(i_j).dof(nq).equal2{1:n_r+1>0}] = deal( sym( zeros(n_copies,7) ) ) ;
                    joint(i_j).dof(nq).init = zeros(n_copies,n_r+1) ; % n_r+1 to cover all q_coeff.s for parallel springs
                    joint(i_j).dof(nq).init_s = sym( zeros(n_copies,n_r+1) ) ; % to get equal number of elements as in init (above)
                    joint(i_j).dof(nq).rom_offset = ones(n_copies,1) .* joint(i_j).rom.rom_offset ;
                    joint(i_j).dof(nq).dir = zeros(n_copies,n_r+1) ;
                    joint(i_j).dof(nq).damp.visc = zeros(n_copies,n_r+1) ;
                    joint(i_j).dof(nq).damp.pow = ones(n_copies,n_r+1) ;
                    joint(i_j).dof(nq).input = zeros(n_copies,n_r+1) ;
                    joint(i_j).dof(nq).control = zeros(n_copies,n_r+1) ;
                    joint(i_j).dof(nq).pid.p = zeros(n_copies,n_r+1) ;
                    joint(i_j).dof(nq).pid.i = zeros(n_copies,n_r+1) ;
                    joint(i_j).dof(nq).pid.d = zeros(n_copies,n_r+1) ;
                    joint(i_j).dof(nq).fixed = zeros(n_copies,n_r+1) ;
                    joint(i_j).dof(nq).fit_type = ones(n_copies,1) .* joint(i_j).rom.fit_type ;
                    joint(i_j).dof(nq).spc_order = ones(n_copies,1) .* joint(i_j).rom.spc_order ;
                    
                    joint(i_j).dof(nq).spring.coeff = zeros(n_copies,n_r+1) ;
                    joint(i_j).dof(nq).spring.init = zeros(n_copies,n_r+1) ; % n_r+1 to cover all q_coeff.s for parallel springs
                    joint(i_j).dof(nq).spring.init_s = sym( zeros(n_copies,n_r+1) ) ; % to get equal number of elements as in init (above)
                    joint(i_j).dof(nq).spring.compr = ones(n_copies,n_r+1) ;
                    [joint(i_j).dof(nq).spring.equal2{1:n_r+1>0}] = deal( sym( zeros(n_copies,7) ) ) ;
                    joint(i_j).dof(nq).spring.rom_offset = ones(n_copies,1) .* joint(i_j).rom.spring_rom_offset ;
                    joint(i_j).dof(nq).spring.fit_type = ones(n_copies,1) .* joint(i_j).rom.spring_fit_type  ;
                    joint(i_j).dof(nq).spring.spc_order = ones(n_copies,1) .* joint(i_j).rom.spc_order ;
                else
                    if ~isfield( joint(i_j).dof(nq) ,'equal2' ) || isempty( joint(i_j).dof(nq).equal2 )
                        [joint(i_j).dof(nq).equal2{1:n_r+1>0}] = deal( sym( zeros(n_copies,7) ) ) ; % [j_count, n_copies, nj_dof, i_dof_mult, val_or_l_rom] x i_dof_mult -or- [n_j, n_d, n_h, i_r, l] x n_r
                    else
                        for i_r = 1 : n_r + 1
                            [ ~ , temp_3 ] = size( joint(i_j).dof(nq).equal2 ) ;
                            for i_d = 1 : n_copies
                                if temp_3 < i_r || joint(i_j).dof(nq).equal2{i_r}(i_d,1) == 0
                                    if isnan( joint(i_j).dof(nq).equal2{1}(i_d,4) ) % all coeffs will be equal to the same coeff in the other joint/dof
                                        joint(i_j).dof(nq).equal2{i_r}(i_d,:) = joint(i_j).dof(nq).equal2{1}(i_d,:) ;
                                    else
                                        joint(i_j).dof(nq).equal2{i_r}(i_d,:) = vpa( zeros(1,7) ) ;
                                    end
                                    % continue ;
                                end
                                %if i_d == 1 && numel(joint(i_j).dof(nq).equal2{i_r}(:,1) ) == 1
                                    % joint(i_j).dof(nq).equal2{i_r} = ones(n_copies,1) * joint(i_j).dof(nq).equal2{i_r} ;
                                if i_d == 1 && numel( joint(i_j).dof(nq).equal2{i_r}(:,1) ) < n_copies
                                    joint(i_j).dof(nq).equal2{i_r}(n_copies,end) = 0 ;
                                end
                            end
                            if joint(i_j).dof(nq).equal2{i_r}(n_copies,1) == i_j && joint(i_j).dof(nq).equal2{i_r}(n_copies,2) == n_copies
                                error( 'joint(i_j).dof(nq).equal2{i_r}(n_copies,1) = same joint is not allowed!' ) ;
                            end
                            if numel( joint(i_j).dof(nq).equal2{i_r}(1,:) ) == 2 % [n_j, n_h]
                                joint(i_j).dof(nq).equal2{i_r} = [ joint(i_j).dof(nq).equal2{i_r}(:,1) ones(n_copies,1) joint(i_j).dof(nq).equal2{i_r}(:,2) nan*ones(n_copies,1) zeros(n_copies,3) ] ;
                            end
                            if numel( joint(i_j).dof(nq).equal2{i_r}(1,:) ) == 3 % [n_j, n_h, i_r]
                                joint(i_j).dof(nq).equal2{i_r} = [ joint(i_j).dof(nq).equal2{i_r}(:,1) ones(n_copies,1) joint(i_j).dof(nq).equal2{i_r}(:,2:3) zeros(n_copies,3) ] ;
                            end
                        end
                    end
                    if ~isfield( joint(i_j).dof(nq) ,'rom_offset' ) || isempty( joint(i_j).dof(nq).rom_offset )
                        joint(i_j).dof(nq).rom_offset = ones(n_copies,1) .* joint(i_j).rom.rom_offset ;
                    else
                        joint(i_j).dof(nq).rom_offset = ones(n_copies,1) .* joint(i_j).dof(nq).rom_offset ;
                    end
                    if ~isfield( joint(i_j).dof(nq) ,'fit_type' ) || isempty( joint(i_j).dof(nq).fit_type )
                        joint(i_j).dof(nq).fit_type = ones(n_copies,1) .* joint(i_j).rom.fit_type ;
                    else
                        joint(i_j).dof(nq).fit_type = ones(n_copies,1) .* joint(i_j).dof(nq).fit_type ;
                    end
                    if ~isfield( joint(i_j).dof(nq) ,'spc_order' ) || isempty( joint(i_j).dof(nq).spc_order )
                        joint(i_j).dof(nq).spc_order = ones(n_copies,1) .* joint(i_j).rom.spc_order ;
                    else
                        joint(i_j).dof(nq).spc_order = ones(n_copies,1) .* joint(i_j).dof(nq).spc_order ;
                    end
                    if ~isfield( joint(i_j).dof(nq) ,'init' ) || isempty( joint(i_j).dof(nq).init )
                        joint(i_j).dof(nq).init = zeros(n_copies,n_r+1) ; % n_r+1 to cover all q_coeff.s for parallel springs
                    else
                        joint(i_j).dof(nq).init = ones(n_copies,1) .* joint(i_j).dof(nq).init ;
                    end
                    if ~isfield( joint(i_j).dof(nq) ,'init_s' ) || isempty( joint(i_j).dof(nq).init_s )
                        joint(i_j).dof(nq).init_s = sym( zeros(n_copies, numel( joint(i_j).dof(nq).init(1,:) ) ) ) ; % to get equal number of elements as in init (above)
                    else
                        joint(i_j).dof(nq).init_s = ones(n_copies,1) .* joint(i_j).dof(nq).init_s ;
                    end
                    if ~isfield( joint(i_j).dof(nq) ,'spring' ) || isempty( joint(i_j).dof(nq).spring )
                        joint(i_j).dof(nq).spring.coeff = zeros(n_copies,n_r+1) ;
                        joint(i_j).dof(nq).spring.init = zeros(n_copies,n_r+1) ; % n_r+1 to cover all q_coeff.s for parallel springs
                        joint(i_j).dof(nq).spring.init_s = sym( zeros(n_copies,n_r+1) ) ; % to get equal number of elements as in init (above)
                        joint(i_j).dof(nq).spring.compr = ones(n_copies,n_r+1) ;
                        [joint(i_j).dof(nq).spring.equal2{1:n_r+1>0}] = deal( sym( zeros(n_copies,7) ) ) ;
                        joint(i_j).dof(nq).spring.rom_offset = ones(n_copies,1) .* joint(i_j).rom.spring_rom_offset ;
                        joint(i_j).dof(nq).spring.fit_type = ones(n_copies,1) .* joint(i_j).rom.spring_fit_type  ;
                        joint(i_j).dof(nq).spring.spc_order = ones(n_copies,1) .* joint(i_j).rom.spc_order ;
                    else
                        if ~isfield( joint(i_j).dof(nq).spring ,'coeff' ) || isempty( joint(i_j).dof(nq).spring.coeff )
                            joint(i_j).dof(nq).spring.coeff = zeros(n_copies,n_r+1) ;
                        else
                            joint(i_j).dof(nq).spring.coeff = ones(1,n_r+1) .* ones(n_copies,1) .* joint(i_j).dof(nq).spring.coeff ;
                        end
                        if ~isfield( joint(i_j).dof(nq).spring ,'init' ) || isempty( joint(i_j).dof(nq).spring.init )
                            joint(i_j).dof(nq).spring.init = zeros(n_copies,n_r+1) ; % n_r+1 to cover all q_coeff.s for parallel springs
                        else
                            joint(i_j).dof(nq).spring.init = ones(n_copies,1) .* joint(i_j).dof(nq).spring.init ;
                        end
                        if ~isfield( joint(i_j).dof(nq).spring ,'init_s' ) || isempty( joint(i_j).dof(nq).spring.init_s )
                            joint(i_j).dof(nq).spring.init_s = sym( zeros(n_copies, numel( joint(i_j).dof(nq).spring.init(1,:) ) ) ) ; % to get equal number of elements as in init (above)
                        else
                            joint(i_j).dof(nq).spring.init_s = ones(n_copies,1) .* joint(i_j).dof(nq).spring.init_s ;
                        end
                        if ~isfield( joint(i_j).dof(nq).spring ,'compr' ) || isempty( joint(i_j).dof(nq).spring.compr )
                            joint(i_j).dof(nq).spring.compr = ones(n_copies,n_r+1) ;
                        else
                            joint(i_j).dof(nq).spring.compr = ones(1,n_r+1) .* ones(n_copies,1) .* joint(i_j).dof(nq).spring.compr ;
                        end                        
                        if ~isfield( joint(i_j).dof(nq).spring ,'rom_offset' ) || isempty( joint(i_j).dof(nq).spring.rom_offset )
                            joint(i_j).dof(nq).spring.rom_offset = ones(n_copies,1) .* joint(i_j).rom.spring_rom_offset ;
                        else
                            joint(i_j).dof(nq).spring.rom_offset = ones(n_copies,1) .* joint(i_j).dof(nq).spring.rom_offset ;
                        end              
                        if ~isfield( joint(i_j).dof(nq).spring ,'fit_type' ) || isempty( joint(i_j).dof(nq).spring.fit_type )
                            joint(i_j).dof(nq).spring.fit_type = ones(n_copies,1) .* joint(i_j).rom.spring_fit_type ;
                        else
                            joint(i_j).dof(nq).spring.fit_type = ones(n_copies,1) .* joint(i_j).dof(nq).spring.fit_type ;
                        end
                        if ~isfield( joint(i_j).dof(nq).spring ,'spc_order' ) || isempty( joint(i_j).dof(nq).spring.spc_order )
                            joint(i_j).dof(nq).spring.spc_order = ones(n_copies,1) .* joint(i_j).rom.spc_order ;
                        else
                            joint(i_j).dof(nq).spring.spc_order = ones(n_copies,1) .* joint(i_j).dof(nq).spring.spc_order ;
                        end
                        if ~isfield( joint(i_j).dof(nq).spring ,'equal2' )
                            [ joint(i_j).dof(nq).spring.equal2{1:n_r+1>0} ] = deal( sym( zeros(n_copies,7) ) ) ;
						else
							for i_r = 1 : n_r + 1
								[ ~ , temp_3 ] = size( joint(i_j).dof(nq).spring.equal2 ) ;
                                for i_d = 1 : n_copies
                                    if temp_3 < i_r || joint(i_j).dof(nq).spring.equal2{i_r}(i_d,1) == 0
                                        if isnan( joint(i_j).dof(nq).spring.equal2{1}(i_d,4) )
                                            joint(i_j).dof(nq).spring.equal2{i_r}(i_d,:) = joint(i_j).dof(nq).spring.equal2{1}(i_d,:) ;
                                        else
                                            joint(i_j).dof(nq).spring.equal2{i_r}(i_d,:) = vpa( zeros(1,7) ) ;
                                        end
                                        % continue ;
                                    end
                                    % if i_d == 1 && numel( joint(i_j).dof(nq).spring.equal2{i_r}(:,1) ) == 1
                                        % joint(i_j).dof(nq).spring.equal2{i_r} = ones(n_copies,1) * joint(i_j).dof(nq).spring.equal2{i_r} ;
                                    if i_d == 1 && numel( joint(i_j).dof(nq).spring.equal2{i_r}(:,1) ) < n_copies
                                        joint(i_j).dof(nq).spring.equal2{i_r}(n_copies,end) = 0 ;
                                    end
                                end
								% Here, same joint is not allowed: joint(i_j).dof(nq).spring.equal2{i_r}(n_copies,1) = i_j
								if numel( joint(i_j).dof(nq).spring.equal2{i_r}(1,:) ) == 2 % [n_j, n_h]
									joint(i_j).dof(nq).spring.equal2{i_r} = [ joint(i_j).dof(nq).spring.equal2{i_r}(:,1) ones(n_copies,1) joint(i_j).dof(nq).spring.equal2{i_r}(:,2) zeros(n_copies,4) ] ;                           
								end
								if numel( joint(i_j).dof(nq).spring.equal2{i_r}(1,:) ) == 3 % [n_j, n_h, i_r]
									joint(i_j).dof(nq).spring.equal2{i_r} = [ joint(i_j).dof(nq).spring.equal2{i_r}(:,1) ones(n_copies,1) joint(i_j).dof(nq).spring.equal2{i_r}(:,2:3) zeros(n_copies,3) ] ;                   
								end
							end							
                        end
                    end
                    if ~isfield( joint(i_j).dof(nq) ,'dir' ) || isempty( joint(i_j).dof(nq).dir )
                        joint(i_j).dof(nq).dir = zeros(n_copies,n_r+1) ;
                    else
                        joint(i_j).dof(nq).dir = ones(1,n_r+1) .* ones(n_copies,1) .* joint(i_j).dof(nq).dir ;
                    end
                    if ~isfield( joint(i_j).dof(nq) ,'damp' ) || isempty( joint(i_j).dof(nq).damp )
                        joint(i_j).dof(nq).damp.visc = zeros(n_copies,n_r+1) ;
                        joint(i_j).dof(nq).damp.pow = ones(n_copies,n_r+1) ;
                    else
                        if ~isfield( joint(i_j).dof(nq).damp ,'visc' ) || isempty( joint(i_j).dof(nq).damp.visc )
                            joint(i_j).dof(nq).damp.visc = zeros(n_copies,n_r+1) ;
                        else
                            joint(i_j).dof(nq).damp.visc = ones(1,n_r+1) .* ones(n_copies,1) .* joint(i_j).dof(nq).damp.visc ;
                        end
                        if ~isfield( joint(i_j).dof(nq).damp ,'pow' ) || isempty( joint(i_j).dof(nq).damp.pow )
                            joint(i_j).dof(nq).damp.pow = ones(n_copies,n_r+1) ;
                        else
                            joint(i_j).dof(nq).damp.pow = ones(1,n_r+1) .* ones(n_copies,1) .* joint(i_j).dof(nq).damp.pow ;
                        end
                    end
                    if ~isfield( joint(i_j).dof(nq) ,'input' ) || isempty( joint(i_j).dof(nq).input )
                        joint(i_j).dof(nq).input = zeros(n_copies,n_r+1) ;
                    else
						if numel( joint(i_j).dof(nq).input(1,:) ) < n_r + 1
							joint(i_j).dof(nq).input(:,n_r+1) = 0 ;
						end
                        joint(i_j).dof(nq).input = ones(1,n_r+1) .* ones(n_copies,1) .* joint(i_j).dof(nq).input ;
                    end
                    if ~isfield( joint(i_j).dof(nq) , 'fixed' ) || isempty( joint(i_j).dof(nq).fixed )
                        joint(i_j).dof(nq).fixed = zeros(n_copies,n_r+1) ;
                    else
						if numel( joint(i_j).dof(nq).fixed(1,:) ) < n_r + 1
							joint(i_j).dof(nq).fixed(:,n_r+1) = 0 ;
						end
                        joint(i_j).dof(nq).fixed = ones(1,n_r+1) .* ones(n_copies,1) .* joint(i_j).dof(nq).fixed ;
                    end
                    if ~isfield( joint(i_j).dof(nq) , 'control' ) || isempty( joint(i_j).dof(nq).control )
                        joint(i_j).dof(nq).control = zeros(n_copies,n_r+1) ;
                    else
						if numel( joint(i_j).dof(nq).control(1,:) ) < n_r + 1
							joint(i_j).dof(nq).control(:,n_r+1) = 0 ;
						end
                        joint(i_j).dof(nq).control = ones(1,n_r+1) .* ones(n_copies,1) .* joint(i_j).dof(nq).control ;
                    end
                    if ~isfield( joint(i_j).dof(nq) , 'pid' ) || isempty( joint(i_j).dof(nq).pid )
                        joint(i_j).dof(nq).pid = joint_temp.dof.pid ;
                    end
                    if ~isfield( joint(i_j).dof(nq).pid , 'p' ) || isempty( joint(i_j).dof(nq).pid.p )
                        joint(i_j).dof(nq).pid.p = ones(n_copies,1) .* ones(1,n_r+1) .* joint_temp.dof.pid.p ;
                    else
                        if numel( joint(i_j).dof(nq).pid.p(1,:) ) < n_r+1
                            joint(i_j).dof(nq).pid.p = ones(1,n_r+1) .* joint(i_j).dof(nq).pid.p ;
                        end
                        joint(i_j).dof(nq).pid.p = ones(n_copies,1) .* joint(i_j).dof(nq).pid.p ;
                    end
                    if ~isfield( joint(i_j).dof(nq).pid , 'i' ) || isempty( joint(i_j).dof(nq).pid.i )
                        joint(i_j).dof(nq).pid.i = ones(n_copies,1) .* ones(1,n_r+1) .* joint_temp.dof.pid.i ;
                    else
                        if numel( joint(i_j).dof(nq).pid.i(1,:) ) < n_r+1
                            joint(i_j).dof(nq).pid.i = ones(1,n_r+1) .* joint(i_j).dof(nq).pid.i ;
                        end
                        joint(i_j).dof(nq).pid.i = ones(n_copies,1) .* joint(i_j).dof(nq).pid.i ;
                    end
                    if ~isfield( joint(i_j).dof(nq).pid , 'd' ) || isempty( joint(i_j).dof(nq).pid.d )
                        joint(i_j).dof(nq).pid.d = ones(n_copies,1) .* ones(1,n_r+1) .* joint_temp.dof.pid.d ;
                    else
                        if numel( joint(i_j).dof(nq).pid.d(1,:) ) < n_r+1
                            joint(i_j).dof(nq).pid.d = ones(1,n_r+1) .* joint(i_j).dof(nq).pid.d ;
                        end
                        joint(i_j).dof(nq).pid.d = ones(n_copies,1) .* joint(i_j).dof(nq).pid.d ;
                    end
                    if ~isfield( joint(i_j).dof(nq) ,'s' ) || isempty( joint(i_j).dof(nq).s )
                        joint(i_j).dof(nq).s = [] ;
                    end
                end
                
                if joint(i_j).rom.isROM
                    if ~isfield( joint(i_j).dof(nq) , 'init_s' ) || isempty( joint(i_j).dof(nq).init_s ) || max( double( abs( subs( joint(i_j).dof(nq).init_s(1,:), par.sym, par.var ) ) ) ) == 0
                        if ~isempty( joint(i_j).rom.init_s )
                            joint(i_j).dof(nq).init_s(i_d,:) = ones(n_copies,1) .* joint(i_j).rom.init_s ;
                        else
                            for i_d = 1 : n_copies
                                joint(i_j).dof(nq).init_s(i_d,:) = linspace( joint(i_j).rom.length(i_d,1) , joint(i_j).rom.length(i_d,2) , numel( joint(i_j).dof(nq).init(i_d,:) ) ) ;
                            end
                        end
                    end                    
                    if numel( joint(i_j).dof(nq).init_s(1,:) ) == numel( joint(i_j).dof(nq).init(1,:) )
                        joint(i_j).dof(nq).init_s = ones(n_copies,1) .* joint(i_j).dof(nq).init_s ;
                    else
                        error( 'numel( joint(i_j).dof(nq).init_s ) ~= numel( joint(i_j).dof(nq).init ) error' ) ;
                    end
                    % spring initial shape
                    if ~isfield( joint(i_j).dof(nq).spring , 'init_s' ) || isempty( joint(i_j).dof(nq).spring.init_s )|| max( double( abs( subs( joint(i_j).dof(nq).spring.init_s(1,:), par.sym, par.var ) ) ) ) == 0
                        if ~isempty( joint(i_j).rom.init_s )
                            joint(i_j).dof(nq).spring.init_s(i_d,:) = ones(n_copies,1) .* joint(i_j).rom.init_s ;
                        else
                            for i_d = 1 : n_copies
                                joint(i_j).dof(nq).spring.init_s(i_d,:) = linspace( joint(i_j).rom.length(i_d,1) , joint(i_j).rom.length(i_d,2) , numel( joint(i_j).dof(nq).spring.init(i_d,:) ) ) ;
                            end
                        end
                    end
                    if isnan( joint(i_j).dof(nq).spring.init(1,1) ) || numel( joint(i_j).dof(nq).spring.init_s(1,:) ) == numel( joint(i_j).dof(nq).spring.init(1,:) )
                        joint(i_j).dof(nq).spring.init_s = ones(n_copies,1) .* joint(i_j).dof(nq).spring.init_s ;
                    else
                        error( 'numel( joint(i_j).dof(nq).spring.init_s ) ~= numel( joint(i_j).dof(nq).spring.init ) error' ) ;
                    end
                end
                                
            end
            
        end
        
    end
    
    if ~isfield( joint(i_j) ,'tr2nd' ) || isempty( joint(i_j).tr2nd )
        joint(i_j).tr2nd = joint_temp.tr ;
    else
        if ~isfield( joint(i_j).tr2nd ,'trans' )
            joint(i_j).tr2nd.trans = [] ;
        end
        if ~isfield( joint(i_j).tr2nd ,'rot' )
            joint(i_j).tr2nd.rot = [] ;
            joint(i_j).tr2nd.type = 'none' ;
        end
        if ~isfield( joint(i_j).tr2nd ,'type' )
            joint(i_j).tr2nd.type = 'none' ;
        end
    end
    
    if joint(i_j).mainkin == 0 % joint not in main kin. chain
        for i = 1 : numel( joint(i_j).tr2nd )
            if ~isfield( joint(i_j).tr2nd(i) ,'trans' ) || isempty( joint(i_j).tr2nd(i).trans )
                joint(i_j).tr2nd(i).trans = [ 0 0 0 ] ;
            end
            if ~isfield( joint(i_j).tr2nd(i) ,'rot' ) || isempty( joint(i_j).tr2nd(i).rot )
                joint(i_j).tr2nd(i).rot = [ 1 0 0 0 ] ;
                joint(i_j).tr2nd(i).type = 'none' ;
            end
            if ~isfield( joint(i_j).tr2nd(i) ,'type' ) || isempty( joint(i_j).tr2nd(i).type )
                joint(i_j).tr2nd(i).type = 'none' ;
            end
        end
    end
    if ~isfield( joint(i_j) , 'dir' ) || isempty( joint(i_j).dir )
        joint(i_j).dir = zeros(n_copies,1) ;
    else
        if numel( joint(i_j).dir(:,1) ) == 1
            joint(i_j).dir = ones(n_copies,1) * joint(i_j).dir(1,:) ;
        end
    end
    if ~isfield( joint(i_j) , 'xaxis' ) || isempty( joint(i_j).xaxis )
        joint(i_j).xaxis = [] ; % default in local frame defined by joint.tr
    else
        if numel( joint(i_j).xaxis(:,1) ) == 1
            joint(i_j).xaxis = ones(n_copies,1) * joint(i_j).xaxis(1,:) ;
        end
    end
    if ~isfield( joint(i_j) , 'spring' ) % constraint
        joint(i_j).spring = joint_temp.spring ;
    else
        if ~isfield( joint(i_j).spring , 'coeff' ) % constraint
            joint(i_j).spring.coeff = [] ;
        end
        if ~isfield( joint(i_j).spring , 'init' ) % constraint
            joint(i_j).spring.init = [] ;
        end
        if ~isfield( joint(i_j).spring , 'compr' ) % constraint
            joint(i_j).spring.compr = [] ;
        end
    end
    if ~isempty( joint(i_j).spring.coeff )
        if ~isfield( joint(i_j).spring , 'coeff' ) || isempty( joint(i_j).spring.coeff )
            joint(i_j).spring.coeff = zeros(n_copies,1) ;
        else
            if numel( joint(i_j).spring.coeff(:,1) ) == 1
                joint(i_j).spring.coeff = ones(n_copies,1) * joint(i_j).spring.coeff(1,:) ;
            end
        end
        if ~isfield( joint(i_j).spring , 'init' ) || isempty( joint(i_j).spring.init )
            joint(i_j).spring.init = zeros(n_copies,numel(joint(i_j).spring.coeff(1,:))) ;
        end
        if numel( joint(i_j).spring.init(1,:) ) == 1
            joint(i_j).spring.init = joint(i_j).spring.init(1,:) * ones(1,numel(joint(i_j).spring.coeff(1,:))) ;
        end
        if numel( joint(i_j).spring.init(:,1) ) == 1
            joint(i_j).spring.init = ones(n_copies,1) * joint(i_j).spring.init(1,:) ;
        end
        if ~isfield( joint(i_j).spring , 'compr' ) || isempty( joint(i_j).spring.compr )
            joint(i_j).spring.compr = ones(n_copies,numel(joint(i_j).spring.coeff(1,:))) ;
        end
        if numel( joint(i_j).spring.compr(1,:) ) == 1
            joint(i_j).spring.compr = joint(i_j).spring.compr(1,:) * ones(1,numel(joint(i_j).spring.coeff(1,:))) ;
        end
        if numel( joint(i_j).spring.compr(:,1) ) == 1
            joint(i_j).spring.compr = ones(n_copies,1) * joint(i_j).spring.compr(1,:) ;
        end
        if ~isfield( joint(i_j) , 'damp' ) || isempty( joint(i_j).damp )
            joint(i_j).damp.visc = zeros(n_copies,numel(joint(i_j).spring.coeff(1,:))) ;
            joint(i_j).damp.pow = ones(n_copies,numel(joint(i_j).spring.coeff(1,:))) ;
        end
        if ~isfield( joint(i_j) , 'input' ) || isempty( joint(i_j).input )
            joint(i_j).input = zeros(n_copies,numel(joint(i_j).spring.coeff(1,:))) ;
        end
    end
    if ~isfield( joint(i_j) , 'damp' ) % constraint
        joint(i_j).damp = joint_temp.damp ;
    else
        if ~isfield( joint(i_j).damp , 'visc' ) % constraint
            joint(i_j).damp.visc = [] ;
        end
        if ~isfield( joint(i_j).damp , 'pow' ) % constraint
            joint(i_j).damp.pow = 1 ;
        end
    end
    if ~isempty( joint(i_j).damp.visc )
        if numel( joint(i_j).damp.visc(:,1) ) == 1
            joint(i_j).damp.visc = ones(n_copies,1) * joint(i_j).damp.visc(1,:) ;
        end
        if ~isfield( joint(i_j).damp , 'pow' ) || isempty( joint(i_j).damp.pow )
            joint(i_j).damp.pow = ones(n_copies,numel(joint(i_j).damp.visc(1,:))) ;
        end
        if numel( joint(i_j).damp.pow(1,:) ) == 1
            joint(i_j).damp.pow = joint(i_j).damp.pow(1,:) * ones(1,numel(joint(i_j).damp.visc(1,:))) ;
        end
        if numel( joint(i_j).damp.pow(:,1) ) == 1
            joint(i_j).damp.pow = ones(n_copies,1) * joint(i_j).damp.pow(1,:) ;
        end
        if ~isfield( joint(i_j) , 'spring' ) || isempty( joint(i_j).spring )
            joint(i_j).spring.coeff = zeros(n_copies,numel(joint(i_j).damp.visc(1,:))) ;
            joint(i_j).spring.init = zeros(n_copies,numel(joint(i_j).damp.visc(1,:))) ;
            joint(i_j).spring.compr = ones(n_copies,numel(joint(i_j).damp.visc(1,:))) ;
        end
        if ~isfield( joint(i_j) , 'input' ) || isempty( joint(i_j).input )
            joint(i_j).input = zeros(n_copies,numel(joint(i_j).damp.visc(1,:))) ;
        end
    end
    if ~isfield( joint(i_j) , 'input' )
        joint(i_j).input = 0 ;
    end
    if ~isempty( joint(i_j).input )
        if numel( joint(i_j).input(:,1) ) == 1
            joint(i_j).input = ones(n_copies,1) * joint(i_j).input(1,:) ;
        end
        if ~isfield( joint(i_j) , 'spring' ) || isempty( joint(i_j).spring )
            joint(i_j).spring.coeff = zeros(n_copies,numel(joint(i_j).input(1,:))) ;
            joint(i_j).spring.init = zeros(n_copies,numel(joint(i_j).input(1,:))) ;
            joint(i_j).spring.compr = ones(n_copies,numel(joint(i_j).input(1,:))) ;
        end
        if ~isfield( joint(i_j) , 'damp' ) || isempty( joint(i_j).damp )
            joint(i_j).damp.visc = zeros(n_copies,numel(joint(i_j).input(1,:))) ;
            joint(i_j).damp.pow = ones(n_copies,numel(joint(i_j).input(1,:))) ;
        end
    end
    if ~isfield( joint(i_j) , 'fixed' )
        joint(i_j).fixed = [] ;
    end
    if ~isempty( joint(i_j).fixed )
        if numel( joint(i_j).fixed(1,:) ) > 7
            error( 'numel( joint(i_j).fixed(1,:) ) error!' ) ;
        end
        if numel( joint(i_j).fixed(1,:) ) < 6
            joint(i_j).fixed = [ joint(i_j).fixed, zeros( numel( joint(i_j).fixed(:,1) ) , 7 - numel( joint(i_j).fixed(1,:) ) ) ] ;
        end
        if numel( joint(i_j).fixed(:,1) ) == 1
            joint(i_j).fixed = ones(n_copies,1) * joint(i_j).fixed(1,:) ;
        end
        if ~isfield( joint(i_j) , 'control' ) || isempty( joint(i_j).control )
            joint(i_j).control = zeros(n_copies, numel( joint(i_j).fixed(1,:) )) ;
        else
            if numel( joint(i_j).control(1,:) ) == 1
                joint(i_j).control = joint(i_j).control(1,:) * ones(1, numel( joint(i_j).fixed(1,:) )) ;
            end
            if numel( joint(i_j).control(1,:) ) < numel( joint(i_j).fixed(1,:) )
                joint(i_j).control = [ joint(i_j).control, zeros( numel( joint(i_j).control(:,1) ) , 7 - numel( joint(i_j).control(1,:) ) ) ] ;
            end
            if numel( joint(i_j).control(:,1) ) == 1
                joint(i_j).control = ones(n_copies,1) * joint(i_j).control(1,:) ;
            end
            if numel(joint(i_j).control(1,:)) ~= numel( joint(i_j).fixed(1,:) )
                error( 'numel(joint(i_j).control(1,:)) ~= numel( joint(i_j).fixed(1,:) ) error!' ) ;
            end
        end
        if ~isfield( joint(i_j) ,'refbody' ) || isempty( joint(i_j).refbody )
            joint(i_j).refbody = ones(n_copies,1) * [ 0 1 0 ] ; % [body_no mesh_no location_lengh]
        else
            if numel( joint(i_j).refbody(1,:) ) == 1
                joint(i_j).refbody(:,2:3) = [ 1 0 ] ;
            end
            if numel( joint(i_j).refbody(:,1) ) == 1
                joint(i_j).refbody = ones(n_copies,1) * joint(i_j).refbody(1,:) ;
            end
        end
        if isempty( joint(i_j).spring.coeff )
            joint(i_j).spring.coeff = zeros(n_copies,6) ;
        else
            if numel( joint(i_j).spring.coeff(1,:) ) == 1
                joint(i_j).spring.coeff = joint(i_j).spring.coeff * ones(1,6) ;
            end
            if numel( joint(i_j).spring.coeff(:,1) ) == 1
                joint(i_j).spring.coeff = ones(n_copies,1) * joint(i_j).spring.coeff ;
            end
            if numel( joint(i_j).spring.coeff(1,:) ) ~= 6
                error( 'numel( joint(i_j).spring.coeff(1,:) ) ~= 6 error!' ) ;
            end
        end
        if isempty( joint(i_j).spring.init )
            joint(i_j).spring.init = zeros(n_copies,6) ;
        else
            if numel( joint(i_j).spring.init(1,:) ) == 1
                joint(i_j).spring.init = joint(i_j).spring.init * ones(1,6) ;
            end
            if numel( joint(i_j).spring.init(:,1) ) == 1
                joint(i_j).spring.init = ones(n_copies,1) * joint(i_j).spring.init ;
            end
            if numel( joint(i_j).spring.init(1,:) ) ~= 6
                error( 'numel( joint(i_j).spring.init(1,:) ) ~= 6 error!' ) ;
            end
        end
        if isempty( joint(i_j).spring.compr )
            joint(i_j).spring.compr = ones(n_copies,6) ;
        else
            if numel( joint(i_j).spring.compr(1,:) ) == 1
                joint(i_j).spring.compr = joint(i_j).spring.compr * ones(1,6) ;
            end
            if numel( joint(i_j).spring.compr(:,1) ) == 1
                joint(i_j).spring.compr = ones(n_copies,1) * joint(i_j).spring.compr ;
            end
            if numel( joint(i_j).spring.compr(1,:) ) ~= 6
                error( 'numel( joint(i_j).spring.compr(1,:) ) ~= 6 error!' ) ;
            end
        end
        if isempty( joint(i_j).damp.visc )
            joint(i_j).damp.visc = zeros(n_copies,6) ;
        else
            if numel( joint(i_j).damp.visc(1,:) ) == 1
                joint(i_j).damp.visc = joint(i_j).damp.visc * ones(1,6) ;
            end
            if numel( joint(i_j).damp.visc(:,1) ) == 1
                joint(i_j).damp.visc = ones(n_copies,1) * joint(i_j).damp.visc  ;
            end
            if numel( joint(i_j).damp.visc(1,:) ) ~= 6
                error( 'numel( joint(i_j).damp.visc(1,:) ) ~= 6 error!' ) ;
            end
        end
        if isempty( joint(i_j).damp.pow )
            joint(i_j).damp.pow = ones(n_copies,6) ;
        else
            if numel( joint(i_j).damp.pow(1,:) ) == 1
                joint(i_j).damp.pow = joint(i_j).damp.pow * ones(1,6) ;
            end
            if numel( joint(i_j).damp.pow(:,1) ) == 1
                joint(i_j).damp.pow = ones(n_copies,1) * joint(i_j).damp.pow  ;
            end
            if numel( joint(i_j).damp.pow(1,:) ) ~= 6
                error( 'numel( joint(i_j).damp.pow(1,:) ) ~= 6 error!' ) ;
            end
        end
        if isempty( joint(i_j).input )
            joint(i_j).input = zeros(n_copies,6) ;
        else
            if numel( joint(i_j).input(1,:) ) == 1
                joint(i_j).input = joint(i_j).input * ones(1,6) ;
            end
            if numel( joint(i_j).input(:,1) ) == 1
                joint(i_j).input = ones(n_copies,1) * joint(i_j).input ;
            end
            if numel( joint(i_j).input(1,:) ) ~= 6
                error( 'numel( joint(i_j).input(1,:) ) ~= 6 error!' ) ;
            end
        end
    end
    if joint(i_j).rom.isROM
        if isempty( joint(i_j).spring.coeff )
            joint(i_j).spring.coeff = zeros(n_copies,6) ;
        else
            if numel( joint(i_j).spring.coeff(1,:) ) == 1
                joint(i_j).spring.coeff = joint(i_j).spring.coeff * ones(1,6) ;
            end
            if numel( joint(i_j).spring.coeff(:,1) ) == 1
                joint(i_j).spring.coeff = ones(n_copies,1) * joint(i_j).spring.coeff ;
            end
            if numel( joint(i_j).spring.coeff(1,:) ) ~= 6
                error( 'numel( joint(i_j).spring.coeff(1,:) ) ~= 6 error!' ) ;
            end
        end
        if isempty( joint(i_j).spring.init ) % [ number of points along backbone x 6 ]
            joint(i_j).spring.init = zeros(n_copies,6) ;
        else
            if numel( joint(i_j).spring.init(1,:) ) == 1
                joint(i_j).spring.init = joint(i_j).spring.init * ones(1,6) ;
            end
            if numel( joint(i_j).spring.init(:,1) ) == 1
                joint(i_j).spring.init = ones(n_copies,1) * joint(i_j).spring.init ;
            end
            if numel( joint(i_j).spring.init(1,:) ) ~= 6
                error( 'numel( joint(i_j).spring.init(1,:) ) ~= 6 error!' ) ;
            end
        end
        if isempty( joint(i_j).spring.compr )
            joint(i_j).spring.compr = ones(n_copies,6) ;
        else
            if numel( joint(i_j).spring.compr(1,:) ) == 1
                joint(i_j).spring.compr = joint(i_j).spring.compr * ones(1,6) ;
            end
            if numel( joint(i_j).spring.compr(:,1) ) == 1
                joint(i_j).spring.compr = ones(n_copies,1) * joint(i_j).spring.compr ;
            end
            if numel( joint(i_j).spring.compr(1,:) ) ~= 6
                error( 'numel( joint(i_j).spring.compr(1,:) ) ~= 6 error!' ) ;
            end
        end
        if isempty( joint(i_j).damp.visc )
            joint(i_j).damp.visc = zeros(n_copies,6) ;
        else
            if numel( joint(i_j).damp.visc(1,:) ) == 1
                joint(i_j).damp.visc = joint(i_j).damp.visc * ones(1,6) ;
            end
            if numel( joint(i_j).damp.visc(:,1) ) == 1
                joint(i_j).damp.visc = ones(n_copies,1) * joint(i_j).damp.visc ;
            end
            if numel( joint(i_j).damp.visc(1,:) ) ~= 6
                error( 'numel( joint(i_j).damp.visc(1,:) ) ~= 6 error!' ) ;
            end
        end
        if isempty( joint(i_j).damp.pow )
            joint(i_j).damp.pow = ones(n_copies,6) ;
        else
            if numel( joint(i_j).damp.pow(1,:) ) == 1
                joint(i_j).damp.pow = joint(i_j).damp.pow * ones(1,6) ;
            end
            if numel( joint(i_j).damp.pow(:,1) ) == 1
                joint(i_j).damp.pow = ones(n_copies,1) * joint(i_j).damp.pow ;
            end
            if numel( joint(i_j).damp.pow(1,:) ) ~= 6
                error( 'numel( joint(i_j).damp.pow(1,:) ) ~= 6 error!' ) ;
            end
        end
        if isempty( joint(i_j).input )
            joint(i_j).input = zeros(n_copies,6) ;
        else
            if numel( joint(i_j).input(1,:) ) == 1
                joint(i_j).input = joint(i_j).input * ones(1,6) ;
            end
            if numel( joint(i_j).input(:,1) ) == 1
                joint(i_j).input = ones(n_copies,1) * joint(i_j).input ;
            end
            if numel( joint(i_j).input(1,:) ) ~= 6
                error( 'numel( joint(i_j).input(1,:) ) ~= 6 error!' ) ;
            end
        end
    end
    if numel( joint(i_j).spring.init ) == 1 && isnan( joint(i_j).spring.init )
        joint(i_j).spring.init = [ nan nan nan nan nan nan ] ;
    end
    if ~isfield( joint(i_j) , 'radi' ) || isempty( joint(i_j).radi ) % cross-section radius for plotting
        joint(i_j).radi = ones(n_copies,1) * joint_temp.radi ;
    else
        joint(i_j).radi = ones(n_copies,1) * joint(i_j).radi ;
    end
    
end


% final check
for i_j = 1 : numel( joint )
    if ~isfield( joint(i_j) , 'first' )
        joint(i_j).first = [] ;
    end
    if ~isfield( joint(i_j) , 'second' )
        joint(i_j).second = [] ;
    end
    if ~isfield( joint(i_j) , 'rom' )
        joint(i_j).rom = joint_temp.rom;
    end
    if ~isfield( joint(i_j) ,'tr' )
        joint(i_j).tr = joint_temp.tr ;
    end
    if ~isfield( joint(i_j) , 'dof' )
        joint(i_j).dof = joint_temp.dof ;
    end
    if ~isfield( joint(i_j) ,'tr2nd' )
        joint(i_j).tr2nd = joint_temp.tr ;
    end
    if ~isfield( joint(i_j) , 'dir' )
        joint(i_j).dir = 0 ;
    end
    if ~isfield( joint(i_j) , 'xaxis' )
        joint(i_j).xaxis = [] ;
    end
    if ~isfield( joint(i_j) , 'spring' )
        joint(i_j).spring = joint_temp.spring ;
    end
    if ~isfield( joint(i_j) , 'damp' )
        joint(i_j).damp = joint_temp.damp ;
    end
    if ~isfield( joint(i_j) , 'input' )
        joint(i_j).input = 0 ;
    end
    if ~isfield( joint(i_j) , 'fixed' )
        joint(i_j).fixed = [] ;
    end
    if ~isfield( joint(i_j) , 'control' )
        joint(i_j).control = [] ;
    end
    if ~isfield( joint(i_j) , 'refbody' )
        joint(i_j).refbody = [] ;
    end
end


%% body
for i_b = 1 : numel( body )
    
    for j_count = 1 : numel( joint )
        
        if joint(j_count).second(1,1) == i_b
            n_copies = numel( joint(j_count).first(1,:) ) - 1 ;
            
            if ~isfield( body(i_b) ,'m' ) || isempty( body(i_b).m )
                body(i_b).m = body_temp.m ;
            end
            if numel( body(i_b).m ) == 1
                body(i_b).m = ones(n_copies,1) * body(i_b).m ;
            else
                if numel( body(i_b).m(:,1) ) ~= n_copies
                    error( 'body(i_b).m size error!' ) ;
                end
            end
            
            if ~isfield( body(i_b) ,'I' ) || isempty( body(i_b).I )
                body(i_b).I = body_temp.I ;
            end
            if numel( body(i_b).I(1,1,:) ) == 1
                tmp = body(i_b).I(:,:) ;
                for i_d = 1 : n_copies
                    body(i_b).I(:,:,i_d) = tmp ;
                end
            else
                if numel( body(i_b).I(1,1,:) ) ~= n_copies
                    error( 'body(i_b).I size error!' ) ;
                end
            end
            
            if ~isfield( body(i_b) ,'radi' ) || isempty( body(i_b).radi )
                body(i_b).radi = ones(n_copies,1) * body_temp.radi ;
            else
                body(i_b).radi = ones(n_copies,1) * body(i_b).radi ;
            end
            
            if ~isfield( body(i_b) ,'l_com' ) || isempty( body(i_b).l_com )
                body(i_b).l_com = body_temp.l_com ;
            end
            if numel( body(i_b).l_com(:,1) ) == 1
                body(i_b).l_com = ones(n_copies,1) * body(i_b).l_com  ;
            else
                if numel( body(i_b).l_com(:,1) ) ~= n_copies
                    error( 'body(i_b).l_com size error!' ) ;
                end
            end
            
            if ~isfield( body(i_b) ,'tip' ) || isempty( body(i_b).tip )
                body(i_b).tip = 2 * body(i_b).l_com ;
            end
            if numel( body(i_b).tip(:,1) ) == 1
                body(i_b).tip = ones(n_copies,1) * body(i_b).tip  ;
            else
                if numel( body(i_b).tip(:,1) ) ~= n_copies
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
        body(i_b).m = ones(n_copies,1) * body_temp.m ;
    end
    if ~isfield( body(i_b) ,'I' )
        body(i_b).I = ones(n_copies,1) * body_temp.I ;
    end
    if ~isfield( body(i_b) ,'radi' )
        body(i_b).radi = ones(n_copies,1) * body_temp.radi ;
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
        n_copies = numel( exload(i_l).exbody(1,:) ) ;
        if n_copies > 1
            n_copies = n_copies - 1 ;
        else
            exload(i_l).exbody(1,2) = 1 ;
        end
        if ~isfield( exload(i_l) ,'refbody' ) || isempty( exload(i_l).refbody )
            exload(i_l).refbody = ones(n_copies,1) * [ 0 1 0 ] ; % wrt ref frame by default: [body_no mesh_no location_lengh]
        else
            if numel( exload(i_l).refbody(1,:) ) == 1
                exload(i_l).refbody(:,2:3) = [ 1 0 ] ;
            end
            if numel( exload(i_l).refbody(:,1) ) == 1
                exload(i_l).refbody = ones(n_copies,1) * exload(i_l).refbody(1,:) ;
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
            exload(i_l).ftau = zeros(n_copies,6) ;
        else
            if numel( exload(i_l).ftau(:,1) ) == 1
                exload(i_l).ftau = ones(n_copies,1) * exload(i_l).ftau(1,:) ;
            end
        end
        if numel( exload(i_l).ftau(1,:) ) ~= 6
            exload(i_l).ftau = [ exload(i_l).ftau zeros( n_copies , 6 - numel( exload(i_l).ftau ) ) ] ;
        end
        
    end
    
end


%% mesh
for i_d = 1 : numel( mesh )
    
    if ~isempty( mesh(i_d).file_name )
        
        if ~isfield( mesh(i_d) ,'file_name' ) || isempty( mesh(i_d).file_name )
            error( 'mesh(i_d).file_name' ) ;
        end
        if ~isfield( mesh(i_d) ,'tol' ) || isempty( mesh(i_d).tol )
            mesh(i_d).tol = 1e-4 ;
        end
        if ~isfield( mesh(i_d) ,'body' ) || isempty( mesh(i_d).body )
            error( 'mesh(i_d).body' ) ;
        end
        if ~isfield( mesh(i_d) ,'joint' ) || isempty( mesh(i_d).joint ) || numel( mesh(i_d).joint ) ~= 2
            error( 'mesh(i_d).joint' ) ;
        end
        if ~isfield( mesh(i_d) ,'tr' ) || isempty( mesh(i_d).tr )
            mesh(i_d).tr.trans = [ 0 0 0 ] ;
            mesh(i_d).tr.rot = [ 1 0 0 0 ] ;
            mesh(i_d).tr.init_quat = [ 1 0 0 0 ] ;
            mesh(i_d).tr.type = 'none' ;
        end
        for i = 1 : numel( mesh(i_d).tr )
            if ~isfield( mesh(i_d).tr(i) ,'trans' ) || isempty( mesh(i_d).tr(i).trans )
                mesh(i_d).tr(i).trans = [ 0 0 0 ] ;
            end
            if ~isfield( mesh(i_d).tr(i) ,'rot' ) || isempty( mesh(i_d).tr(i).rot )
                mesh(i_d).tr(i).rot = [ 1 0 0 0 ] ;
                mesh(i_d).tr(i).init_quat = [ 1 0 0 0 ] ;
                mesh(i_d).tr(i).type = 'none' ;
            end
            if ~isfield( mesh(i_d).tr(i) ,'init_quat' ) || isempty( mesh(i_d).tr(i).init_quat )
                mesh(i_d).tr(i).init_quat = [ 1 0 0 0 ] ;
            end
            if ~isfield( mesh(i_d).tr(i) ,'type' ) || isempty( mesh(i_d).tr(i).type )
                mesh(i_d).tr(i).type = 'none' ;
            end
        end
        
    end
    
end


