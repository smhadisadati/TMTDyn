function [ s , world , body , joint , exload , mesh , par , symbols ] = ...
    check( par , world , body , joint , exload , mesh )
%% check inputs to set default values and pass errors
fprintf( 'check inputs... \n' )
par.elapsed_time = [ par.elapsed_time toc( par.timer ) ] ;
toc( par.timer )

%% init.
syms s dummy1
symbols = [ dummy1 ] ;
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
    if ~isfield( par , 'user' ) || isempty( par.user )
        par.user = par_temp.user ;
    end
    if ~isfield( par , 'derive' ) || isempty( par.derive )
        par.derive = par_temp.derive ;
    end
    if ~isfield( par , 'opv' ) || isempty( par.opv )
        par.opv = par_temp.opv ;
    end
    if ~isfield( par , 'simplify' ) || isempty( par.simplify )
        par.opv = par_temp.simplify ;
    end
    if ~isfield( par , 'derive_collect' ) || isempty( par.derive_collect )
        par.derive_collect = par_temp.derive_collect ;
    end
    if ~isfield( par , 'derive_mex' ) || isempty( par.derive_mex )
        par.derive_mex = par_temp.derive_mex ;
        par.derive_collect = par_temp.derive_collect ;
    end
    if ~isfield( par , 'anim' ) || isempty( par.anim )
        par.anim = par_temp.anim ;
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
    if ~isfield( par , 'dt_anim_rep' ) || isempty( par.dt_anim_rep ) || numel( par.dt_anim_rep ) ~= 1
        par.dt_anim_rep = par_temp.dt_anim_rep ;
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
        joint(i_j).first = 0 ;
    end
    
    if ~isfield( joint(i_j) , 'second' ) || isempty( joint(i_j).second )
        joint(i_j).second = 0 ;
    end
    
    if ~isfield( joint(i_j) , 'rom' ) || isempty( joint(i_j).rom )
        joint(i_j).rom = joint_temp.rom ;
    else
        if ~isempty( joint(i_j).rom.order )
            if ~isfield( joint(i_j).rom , 'order' ) || isempty( joint(i_j).rom.order )
                error( 'joint(i_j).rom.order error' ) ;
            end
            if ~isfield( joint(i_j).rom , 'length' ) || isempty( joint(i_j).rom.length )
                error( 'joint(i_j).rom.length error' ) ;
            end
        end
    end
    
    if ~isfield( joint(i_j) , 'mainkin' ) || isempty( joint(i_j).mainkin )
        joint(i_j).mainkin = 0 ;
        for i_b = 1 : numel( body )
            if joint(i_j).second(1) == i_b && j_b( i_b ) == 0 % first connected to i_b is in main kin. chain
                j_b( i_b ) = i_j ;
                joint(i_j).mainkin = 1 ;
            end
        end
    end
    
    [ n_mesh , ind ] = max( [ numel( joint(i_j).second ) , numel( joint(i_j).first ) ] ) ;
    if ind == 2 && joint(i_j).mainkin == 1 && numel( joint(i_j).first ) > 2 % only acceptable for sprdmp
        i_j
        error( 'main kin. chain joint(i_j).second size error' ) ;
    end
    if n_mesh > 1
        n_mesh = n_mesh - 1 ;
    else
        joint(i_j).first(2) = 1 ;
        joint(i_j).second(2) = 1 ;
    end
    if numel( joint(i_j).first ) ~= numel( joint(i_j).second )
        if ind == 2
            if numel( joint(i_j).second ) == 1
                joint(i_j).second(2:n_mesh+1) = 1 ;
            else if numel( joint(i_j).second ) == 2
                    joint(i_j).second(2:n_mesh+1) = joint(i_j).second(2) ;
                else
                    error( 'numel( joint(i_j).first ) ~= numel( joint(i_j).second )' ) ;
                end
            end
        else
            if numel( joint(i_j).first ) == 1
                joint(i_j).first(2:n_mesh+1) = 1 ;
            else if numel( joint(i_j).first ) == 2
                    joint(i_j).first(2:n_mesh+1) = joint(i_j).first(2) ;
                else
                    error( 'numel( joint(i_j).first ) ~= numel( joint(i_j).second )' ) ;
                end
            end
        end
    end
    
    if ~isfield( joint(i_j) ,'tr' ) || isempty( joint(i_j).tr )
        joint(i_j).tr.trans = [ 0 0 0 ] ;
        joint(i_j).tr.rot = [ 0 0 0 1 ] ;
        joint(i_j).tr.rot_type = 'none' ;
    end
    
    if ~isfield( joint(i_j) , 'dof' ) || isempty( joint(i_j).dof )
        joint(i_j).dof = joint_temp.dof ;
    end
    
    for i = 1 : numel( joint(i_j).tr )
        if ~isfield( joint(i_j).tr(i) ,'trans' ) || isempty( joint(i_j).tr(i).trans )
            joint(i_j).tr(i).trans = [ 0 0 0 ] ;
        end
        if ~isfield( joint(i_j).tr(i) ,'rot' ) || isempty( joint(i_j).tr(i).rot )
            joint(i_j).tr(i).rot = [ 0 0 0 1 ] ;
            joint(i_j).tr(i).rot_type = 'none' ;
        end
        if ~isfield( joint(i_j).tr(i) ,'rot_type' ) || isempty( joint(i_j).tr(i).rot_type )
            joint(i_j).tr(i).rot_type = 'none' ;
        end
        rotrans = [ joint(i_j).tr(i).trans joint(i_j).tr(i).rot ] ;
        for i2 = 1 : numel( rotrans )
            if isinf( rotrans(i2) )
                nq = nq + 1 ;
                if ~isfield( joint(i_j) , 'dof' ) || isempty( joint(i_j).dof ) || numel( joint(i_j).dof ) < nq
                    joint(i_j).dof(nq).equal2 = [] ;
                    joint(i_j).dof(nq).init = zeros(n_mesh,1) ;
                    joint(i_j).dof(nq).init_s = [] ;
                    joint(i_j).dof(nq).spring.coeff = zeros(n_mesh,1) ;
                    joint(i_j).dof(nq).spring.init = zeros(n_mesh,1) ;
                    joint(i_j).dof(nq).spring.compr = ones(n_mesh,1) ;
                    joint(i_j).dof(nq).dir = zeros(n_mesh,1) ;
                    joint(i_j).dof(nq).damp.visc = zeros(n_mesh,1) ;
                    joint(i_j).dof(nq).damp.pow = ones(n_mesh,1) ;
                    joint(i_j).dof(nq).input = zeros(n_mesh,1) ;
                else
                    if ~isfield( joint(i_j).dof(nq) ,'equal2' ) || isempty( joint(i_j).dof(nq).equal2 )
                        joint(i_j).dof(nq).equal2 = [] ;
                    else if numel( joint(i_j).dof(nq).equal2 ) == 1
                            error( 'joint(i_j).dof(nq).equal2 size!' ) ;
                        end
                        if numel( joint(i_j).dof(nq).equal2 ) == 2
                            joint(i_j).dof(nq).equal2 = ones(n_mesh,1) * [ joint(i_j).dof(nq).equal2(1) 1 joint(i_j).dof(nq).equal2(2) ] ; % [ body mesh dof ]
                            joint(i_j).dof(nq).equal2 = ones(n_mesh,1) * joint(i_j).dof(nq).equal2 ;
                        end
                        if numel( joint(i_j).dof(nq).equal2(1,:) ) == 2
                            joint(i_j).dof(nq).equal2 = [ joint(i_j).dof(nq).equal2(:,1) ones(n_mesh,1) joint(i_j).dof(nq).equal2(:,2) ] ; % [ body mesh dof ]
                            
                        end
                        if numel( joint(i_j).dof(nq).equal2 ) == 3
                            joint(i_j).dof(nq).equal2 = ones(n_mesh,1) * joint(i_j).dof(nq).equal2 ;
                        end
                    end
                    if ~isfield( joint(i_j).dof(nq) ,'init' ) || isempty( joint(i_j).dof(nq).init )
                        joint(i_j).dof(nq).init = zeros(n_mesh,1) ;
                    else if numel( joint(i_j).dof(nq).init ) == 1
                            joint(i_j).dof(nq).init = joint(i_j).dof(nq).init * ones(n_mesh,1) ;
                        end
                    end
                    if ~isfield( joint(i_j).dof(nq) ,'spring' ) || isempty( joint(i_j).dof(nq).spring )
                        joint(i_j).dof(nq).spring.coeff = zeros(n_mesh,1) ;
                        joint(i_j).dof(nq).spring.init = zeros(n_mesh,1) ;
                        joint(i_j).dof(nq).spring.compr = ones(n_mesh,1) ;
                    else
                        if ~isfield( joint(i_j).dof(nq).spring ,'coeff' ) || isempty( joint(i_j).dof(nq).spring.coeff )
                            joint(i_j).dof(nq).spring.coeff = zeros(n_mesh,1) ;
                        else if numel( joint(i_j).dof(nq).spring.coeff ) == 1
                                joint(i_j).dof(nq).spring.coeff = joint(i_j).dof(nq).spring.coeff * ones(n_mesh,1) ;
                            end
                        end
                        if ~isfield( joint(i_j).dof(nq).spring ,'init' ) || isempty( joint(i_j).dof(nq).spring.init )
                            joint(i_j).dof(nq).spring.init = zeros(n_mesh,1) ;
                        else if numel( joint(i_j).dof(nq).spring.init ) == 1
                                joint(i_j).dof(nq).spring.init = joint(i_j).dof(nq).spring.init * ones(n_mesh,1) ;
                            end
                        end
                        if ~isfield( joint(i_j).dof(nq).spring ,'compr' ) || isempty( joint(i_j).dof(nq).spring.compr )
                            joint(i_j).dof(nq).spring.compr = ones(n_mesh,1) ;
                        else if numel( joint(i_j).dof(nq).spring.compr ) == 1
                                joint(i_j).dof(nq).spring.compr = joint(i_j).dof(nq).spring.compr * ones(n_mesh,1) ;
                            end
                        end
                    end
                    if ~isfield( joint(i_j).dof(nq) ,'dir' ) || isempty( joint(i_j).dof(nq).dir )
                        joint(i_j).dof(nq).dir = zeros(n_mesh,1) ;
                    else if numel( joint(i_j).dof(nq).dir ) == 1
                            joint(i_j).dof(nq).dir = joint(i_j).dof(nq).dir * ones(n_mesh,1) ;
                        end
                    end
                    if ~isfield( joint(i_j).dof(nq) ,'damp' ) || isempty( joint(i_j).dof(nq).damp )
                        joint(i_j).dof(nq).damp.visc = zeros(n_mesh,1) ;
                        joint(i_j).dof(nq).damp.pow = ones(n_mesh,1) ;
                    else
                        if ~isfield( joint(i_j).dof(nq).damp ,'visc' ) || isempty( joint(i_j).dof(nq).damp.visc )
                            joint(i_j).dof(nq).damp.visc = zeros(n_mesh,1) ;
                        else if numel( joint(i_j).dof(nq).damp.visc ) == 1
                                joint(i_j).dof(nq).damp.visc = joint(i_j).dof(nq).damp.visc * ones(n_mesh,1) ;
                            end
                        end
                        if ~isfield( joint(i_j).dof(nq).damp ,'pow' ) || isempty( joint(i_j).dof(nq).damp.pow )
                            joint(i_j).dof(nq).damp.pow = ones(n_mesh,1) ;
                        else if numel( joint(i_j).dof(nq).damp.pow ) == 1
                                joint(i_j).dof(nq).damp.pow = joint(i_j).dof(nq).damp.pow * ones(n_mesh,1) ;
                            end
                        end
                    end
                    if ~isfield( joint(i_j).dof(nq) ,'input' ) || isempty( joint(i_j).dof(nq).input )
                        joint(i_j).dof(nq).input = zeros(n_mesh,1) ;
                    else if numel( joint(i_j).dof(nq).input ) == 1
                            joint(i_j).dof(nq).input = joint(i_j).dof(nq).input * ones(n_mesh,1) ;
                        end
                    end
                end
                
                if ~isempty( joint(i_j).rom.order )
                    S = [] ;
                    for i_s = 1 : joint(i_j).rom.order
                        i_sbc = i_s ;
                        if i2 < 4  % x,y,z Boundary Condition at s = 0
                            i_sbc = i_s + 1 ;
                        end
                        S = [ S s^i_sbc ] ;
                    end
                    if ~isfield( joint(i_j).dof(nq) , 'init_s' ) || isempty( joint(i_j).dof(nq).init_s )
                        joint(i_j).dof(nq).init_s = ( 1 : numel( joint(i_j).dof(nq).init(1,:) ) ) * joint(i_j).rom.length / numel( joint(i_j).dof(nq).init(1,:) ) ;
                    end
                    if numel( joint(i_j).dof(nq).init ) ~= numel( joint(i_j).dof(nq).init_s )
                        error( 'numel( joint(i_j).dof(nq).init ) ~= numel( joint(i_j).dof(nq).init_s ) error' ) ;
                    end
                    S0= [] ; b0 =[] ;
                    for i_s = 1 : numel( joint(i_j).dof(nq).init(1,:) )
                        s0 = joint(i_j).dof(nq).init_s(i_s) ;
                        S0 = [ S0 ; subs( S , s , s0 ) ] ;
                        if i2 == 3 % z Boundary Condition
                            b0 = [ b0 s0 ] ;
                        else
                            b0 = [ b0 0 ] ;
                        end
                    end
                    joint(i_j).dof(nq).init = ( S0 \ ( joint(i_j).dof(nq).init - b0 ).' ).' ;
                    joint(i_j).dof(nq).s = S ;
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
            joint(i_j).tr2nd.rot_type = 'none' ;
        end
        if ~isfield( joint(i_j).tr2nd ,'rot_type' )
            joint(i_j).tr2nd.rot_type = 'none' ;
        end
    end
    
    if joint(i_j).mainkin == 0 % joint not in main kin. chain
        for i = 1 : numel( joint(i_j).tr2nd )
            if ~isfield( joint(i_j).tr2nd(i) ,'trans' ) || isempty( joint(i_j).tr2nd(i).trans )
                joint(i_j).tr2nd(i).trans = [ 0 0 0 ] ;
            end
            if ~isfield( joint(i_j).tr2nd(i) ,'rot' ) || isempty( joint(i_j).tr2nd(i).rot )
                joint(i_j).tr2nd(i).rot = [ 0 0 0 1 ] ;
                joint(i_j).tr2nd(i).rot_type = 'none' ;
            end
            if ~isfield( joint(i_j).tr2nd(i) ,'rot_type' ) || isempty( joint(i_j).tr2nd(i).rot_type )
                joint(i_j).tr2nd(i).rot_type = 'none' ;
            end
        end
    end
    if ~isfield( joint(i_j) , 'dir' ) || isempty( joint(i_j).dir )
        joint(i_j).dir = zeros(n_mesh,1) ;
    else
        if numel( joint(i_j).dir(:,1) ) == 1
            joint(i_j).dir = ones(n_mesh,1) * joint(i_j).dir(1,:) ;
        end
    end
    if ~isfield( joint(i_j) , 'xaxis' ) || isempty( joint(i_j).xaxis )
        joint(i_j).xaxis = [] ; % default in local frame defined by joint.tr
    else
        if numel( joint(i_j).xaxis(:,1) ) == 1
            joint(i_j).xaxis = ones(n_mesh,1) * joint(i_j).xaxis(1,:) ;
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
            joint(i_j).spring.coeff = zeros(n_mesh,1) ;
        else
            if numel( joint(i_j).spring.coeff(:,1) ) == 1
                joint(i_j).spring.coeff = ones(n_mesh,1) * joint(i_j).spring.coeff(1,:) ;
            end
        end
        if ~isfield( joint(i_j).spring , 'init' ) || isempty( joint(i_j).spring.init )
            joint(i_j).spring.init = zeros(n_mesh,numel(joint(i_j).spring.coeff(1,:))) ;
        end
        if numel( joint(i_j).spring.init(1,:) ) == 1
            joint(i_j).spring.init = joint(i_j).spring.init(1,:) * ones(1,numel(joint(i_j).spring.coeff(1,:))) ;
        end
        if numel( joint(i_j).spring.init(:,1) ) == 1
            joint(i_j).spring.init = ones(n_mesh,1) * joint(i_j).spring.init(1,:) ;
        end
        if ~isfield( joint(i_j).spring , 'compr' ) || isempty( joint(i_j).spring.compr )
            joint(i_j).spring.compr = ones(n_mesh,numel(joint(i_j).spring.coeff(1,:))) ;
        end
        if numel( joint(i_j).spring.compr(1,:) ) == 1
            joint(i_j).spring.compr = joint(i_j).spring.compr(1,:) * ones(1,numel(joint(i_j).spring.coeff(1,:))) ;
        end
        if numel( joint(i_j).spring.compr(:,1) ) == 1
            joint(i_j).spring.compr = ones(n_mesh,1) * joint(i_j).spring.compr(1,:) ;
        end
        if ~isfield( joint(i_j) , 'damp' ) || isempty( joint(i_j).damp )
            joint(i_j).damp.visc = zeros(n_mesh,numel(joint(i_j).spring.coeff(1,:))) ;
            joint(i_j).damp.pow = ones(n_mesh,numel(joint(i_j).spring.coeff(1,:))) ;
        end
        if ~isfield( joint(i_j) , 'input' ) || isempty( joint(i_j).input )
            joint(i_j).input = zeros(n_mesh,numel(joint(i_j).spring.coeff(1,:))) ;
        end
    end
    if ~isfield( joint(i_j) , 'damp' ) % constraint
        joint(i_j).damp = joint_temp.damp ;
    else
        if ~isfield( joint(i_j).damp , 'visc' ) % constraint
            joint(i_j).damp.visc = [] ;
        end
        if ~isfield( joint(i_j).damp , 'pow' ) % constraint
            joint(i_j).damp.pow = [] ;
        end
    end
    if ~isempty( joint(i_j).damp.visc )
        if numel( joint(i_j).damp.visc(:,1) ) == 1
            joint(i_j).damp.visc = ones(n_mesh,1) * joint(i_j).damp.visc(1,:) ;
        end
        if ~isfield( joint(i_j).damp , 'pow' ) || isempty( joint(i_j).damp.pow )
            joint(i_j).damp.pow = ones(n_mesh,numel(joint(i_j).damp.visc(1,:))) ;
        end
        if numel( joint(i_j).damp.pow(1,:) ) == 1
            joint(i_j).damp.pow = joint(i_j).damp.pow(1,:) * ones(1,numel(joint(i_j).damp.visc(1,:))) ;
        end
        if numel( joint(i_j).damp.pow(:,1) ) == 1
            joint(i_j).damp.pow = ones(n_mesh,1) * joint(i_j).damp.pow(1,:) ;
        end
        if ~isfield( joint(i_j) , 'spring' ) || isempty( joint(i_j).spring )
            joint(i_j).spring.coeff = zeros(n_mesh,numel(joint(i_j).damp.visc(1,:))) ;
            joint(i_j).spring.init = zeros(n_mesh,numel(joint(i_j).damp.visc(1,:))) ;
            joint(i_j).spring.compr = ones(n_mesh,numel(joint(i_j).damp.visc(1,:))) ;
        end
        if ~isfield( joint(i_j) , 'input' ) || isempty( joint(i_j).input )
            joint(i_j).input = zeros(n_mesh,numel(joint(i_j).damp.visc(1,:))) ;
        end
    end
    if ~isfield( joint(i_j) , 'input' )
        joint(i_j).input = [] ;
    end
    if ~isempty( joint(i_j).input )
        if numel( joint(i_j).input(:,1) ) == 1
            joint(i_j).input = ones(n_mesh,1) * joint(i_j).input(1,:) ;
        end
        if ~isfield( joint(i_j) , 'spring' ) || isempty( joint(i_j).spring )
            joint(i_j).spring.coeff = zeros(n_mesh,numel(joint(i_j).input(1,:))) ;
            joint(i_j).spring.init = zeros(n_mesh,numel(joint(i_j).input(1,:))) ;
            joint(i_j).spring.compr = ones(n_mesh,numel(joint(i_j).input(1,:))) ;
        end
        if ~isfield( joint(i_j) , 'damp' ) || isempty( joint(i_j).damp )
            joint(i_j).damp.visc = zeros(n_mesh,numel(joint(i_j).input(1,:))) ;
            joint(i_j).damp.pow = ones(n_mesh,numel(joint(i_j).input(1,:))) ;
        end
    end
    if ~isfield( joint(i_j) , 'fixed' )
        joint(i_j).fixed = [] ;
    end
    if ~isempty( joint(i_j).fixed )
        if numel( joint(i_j).fixed(1,:) ) > 6
            error( 'numel( joint(i_j).fixed(1,:) ) error!' ) ;
        end
        if numel( joint(i_j).fixed(1,:) ) < 6
            joint(i_j).fixed = [ joint(i_j).fixed, zeros( numel( joint(i_j).fixed(:,1) ) , 6 - numel( joint(i_j).fixed(1,:) ) ) ] ;
        end
        if numel( joint(i_j).fixed(:,1) ) == 1
            joint(i_j).fixed = ones(n_mesh,1) * joint(i_j).fixed(1,:) ;
        end
        if ~isfield( joint(i_j) , 'control' ) || isempty( joint(i_j).control )
            joint(i_j).control = zeros(n_mesh,6) ;
        else
            if numel( joint(i_j).control(1,:) ) == 1
                joint(i_j).control = joint(i_j).control(1,:) * ones(1,6) ;
            end
            if numel( joint(i_j).control(:,1) ) == 1
                joint(i_j).control = ones(n_mesh,1) * joint(i_j).control(1,:) ;
            end
            if numel(joint(i_j).control(1,:)) ~= 6
                error( 'numel(joint(i_j).control(1,:)) ~= 6 error!' ) ;
            end
        end
        if ~isfield( joint(i_j) ,'refbody' ) || isempty( joint(i_j).refbody )
            joint(i_j).refbody = ones(n_mesh,1) * [ 0 1 ] ;
        else if numel( joint(i_j).refbody(1,:) ) == 1
                joint(i_j).refbody(:,2) = 1 ;
            end
            if numel( joint(i_j).refbody(:,1) ) == 1
                joint(i_j).refbody = ones(n_mesh,1) * joint(i_j).refbody(1,:) ;
            end
        end
        if isempty( joint(i_j).spring.coeff )
            joint(i_j).spring.coeff = zeros(n_mesh,6) ;
        else
            if numel( joint(i_j).spring.coeff(1,:) ) == 1
                joint(i_j).spring.coeff = joint(i_j).spring.coeff * ones(1,6) ;
            end
            if numel( joint(i_j).spring.coeff(:,1) ) == 1
                joint(i_j).spring.coeff = ones(n_mesh,1) * joint(i_j).spring.coeff ;
            end
            if numel( joint(i_j).spring.coeff(1,:) ) ~= 6
                error( 'numel( joint(i_j).spring.coeff(1,:) ) ~= 6 error!' ) ;
            end
        end
        if isempty( joint(i_j).spring.init )
            joint(i_j).spring.init = zeros(n_mesh,6) ;
        else
            if numel( joint(i_j).spring.init(1,:) ) == 1
                joint(i_j).spring.init = joint(i_j).spring.init * ones(1,6) ;
            end
            if numel( joint(i_j).spring.init(:,1) ) == 1
                joint(i_j).spring.init = ones(n_mesh,1) * joint(i_j).spring.init ;
            end
            if numel( joint(i_j).spring.init(1,:) ) ~= 6
                error( 'numel( joint(i_j).spring.init(1,:) ) ~= 6 error!' ) ;
            end
        end
        if isempty( joint(i_j).spring.compr )
            joint(i_j).spring.compr = ones(n_mesh,6) ;
        else
            if numel( joint(i_j).spring.compr(1,:) ) == 1
                joint(i_j).spring.compr = joint(i_j).spring.compr * ones(1,6) ;
            end
            if numel( joint(i_j).spring.compr(:,1) ) == 1
                joint(i_j).spring.compr = ones(n_mesh,1) * joint(i_j).spring.compr ;
            end
            if numel( joint(i_j).spring.compr(1,:) ) ~= 6
                error( 'numel( joint(i_j).spring.compr(1,:) ) ~= 6 error!' ) ;
            end
        end
        if isempty( joint(i_j).damp.visc )
            joint(i_j).damp.visc = zeros(n_mesh,6) ;
        else
            if numel( joint(i_j).damp.visc(1,:) ) == 1
                joint(i_j).damp.visc = joint(i_j).damp.visc * ones(1,6) ;
            end
            if numel( joint(i_j).damp.visc(:,1) ) == 1
                joint(i_j).damp.visc = ones(n_mesh,1) * joint(i_j).damp.visc  ;
            end
            if numel( joint(i_j).damp.visc(1,:) ) ~= 6
                error( 'numel( joint(i_j).damp.visc(1,:) ) ~= 6 error!' ) ;
            end
        end
        if isempty( joint(i_j).damp.pow )
            joint(i_j).damp.pow = ones(n_mesh,6) ;
        else
            if numel( joint(i_j).damp.pow(1,:) ) == 1
                joint(i_j).damp.pow = joint(i_j).damp.pow * ones(1,6) ;
            end
            if numel( joint(i_j).damp.pow(:,1) ) == 1
                joint(i_j).damp.pow = ones(n_mesh,1) * joint(i_j).damp.pow  ;
            end
            if numel( joint(i_j).damp.pow(1,:) ) ~= 6
                error( 'numel( joint(i_j).damp.pow(1,:) ) ~= 6 error!' ) ;
            end
        end
        if isempty( joint(i_j).input )
            joint(i_j).input = zeros(n_mesh,6) ;
        else
            if numel( joint(i_j).input(1,:) ) == 1
                joint(i_j).input = joint(i_j).input * ones(1,6) ;
            end
            if numel( joint(i_j).input(:,1) ) == 1
                joint(i_j).input = ones(n_mesh,1) * joint(i_j).input ;
            end
            if numel( joint(i_j).input(1,:) ) ~= 6
                error( 'numel( joint(i_j).input(1,:) ) ~= 6 error!' ) ;
            end
        end
    end
    if ~isempty( joint(i_j).rom.order )
        if isempty( joint(i_j).spring.coeff )
            joint(i_j).spring.coeff = zeros(n_mesh,6) ;
        else
            if numel( joint(i_j).spring.coeff(1,:) ) == 1
                joint(i_j).spring.coeff = joint(i_j).spring.coeff * ones(1,6) ;
            end
            if numel( joint(i_j).spring.coeff(:,1) ) == 1
                joint(i_j).spring.coeff = ones(n_mesh,1) * joint(i_j).spring.coeff ;
            end
            if numel( joint(i_j).spring.coeff(1,:) ) ~= 6
                error( 'numel( joint(i_j).spring.coeff(1,:) ) ~= 6 error!' ) ;
            end
        end
        if isempty( joint(i_j).spring.init )
            joint(i_j).spring.init = zeros(n_mesh,6) ;
        else
            if numel( joint(i_j).spring.init(1,:) ) == 1
                joint(i_j).spring.init = joint(i_j).spring.init * ones(1,6) ;
            end
            if numel( joint(i_j).spring.init(:,1) ) == 1
                joint(i_j).spring.init = ones(n_mesh,1) * joint(i_j).spring.init ;
            end
            if numel( joint(i_j).spring.init(1,:) ) ~= 6
                error( 'numel( joint(i_j).spring.init(1,:) ) ~= 6 error!' ) ;
            end
        end
        if isempty( joint(i_j).spring.compr )
            joint(i_j).spring.compr = ones(n_mesh,6) ;
        else
            if numel( joint(i_j).spring.compr(1,:) ) == 1
                joint(i_j).spring.compr = joint(i_j).spring.compr * ones(1,6) ;
            end
            if numel( joint(i_j).spring.compr(:,1) ) == 1
                joint(i_j).spring.compr = ones(n_mesh,1) * joint(i_j).spring.compr ;
            end
            if numel( joint(i_j).spring.compr(1,:) ) ~= 6
                error( 'numel( joint(i_j).spring.compr(1,:) ) ~= 6 error!' ) ;
            end
        end
        if isempty( joint(i_j).damp.visc )
            joint(i_j).damp.visc = zeros(n_mesh,6) ;
        else
            if numel( joint(i_j).damp.visc(1,:) ) == 1
                joint(i_j).damp.visc = joint(i_j).damp.visc * ones(1,6) ;
            end
            if numel( joint(i_j).damp.visc(:,1) ) == 1
                joint(i_j).damp.visc = ones(n_mesh,1) * joint(i_j).damp.visc  ;
            end
            if numel( joint(i_j).damp.visc(1,:) ) ~= 6
                error( 'numel( joint(i_j).damp.visc(1,:) ) ~= 6 error!' ) ;
            end
        end
        if isempty( joint(i_j).damp.pow )
            joint(i_j).damp.pow = ones(n_mesh,6) ;
        else
            if numel( joint(i_j).damp.pow(1,:) ) == 1
                joint(i_j).damp.pow = joint(i_j).damp.pow * ones(1,6) ;
            end
            if numel( joint(i_j).damp.pow(:,1) ) == 1
                joint(i_j).damp.pow = ones(n_mesh,1) * joint(i_j).damp.pow  ;
            end
            if numel( joint(i_j).damp.pow(1,:) ) ~= 6
                error( 'numel( joint(i_j).damp.pow(1,:) ) ~= 6 error!' ) ;
            end
        end
        if isempty( joint(i_j).input )
            joint(i_j).input = zeros(n_mesh,6) ;
        else
            if numel( joint(i_j).input(1,:) ) == 1
                joint(i_j).input = joint(i_j).input * ones(1,6) ;
            end
            if numel( joint(i_j).input(:,1) ) == 1
                joint(i_j).input = ones(n_mesh,1) * joint(i_j).input ;
            end
            if numel( joint(i_j).input(1,:) ) ~= 6
                error( 'numel( joint(i_j).input(1,:) ) ~= 6 error!' ) ;
            end
        end
    end
    if numel( joint(i_j).spring.init ) == 1 && isnan( joint(i_j).spring.init )
        joint(i_j).spring.init = [ nan nan nan nan nan nan ] ;
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
        joint(i_j).input = [] ;
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
        
        if joint(j_count).second(1) == i_b
            n_mesh = numel( joint(j_count).first ) - 1 ;
            
            if ~isfield( body(i_b) ,'m' ) || isempty( body(i_b).m )
                body(i_b).m = 1e-9 ;
            end
            if numel( body(i_b).m ) == 1
                body(i_b).m = ones(n_mesh,1) * body(i_b).m ;
            else
                if numel( body(i_b).m(:,1) ) ~= n_mesh
                    error( 'body(i_b).m size error!' ) ;
                end
            end
            
            if ~isfield( body(i_b) ,'I' ) || isempty( body(i_b).I )
                body(i_b).I = 1e-9 * eye(3) ;
            end
            if numel( body(i_b).I(1,1,:) ) == 1
                tmp = body(i_b).I(:,:) ;
                for i_mesh = 1 : n_mesh
                    body(i_b).I(:,:,i_mesh) = tmp ;
                end
            else
                if numel( body(i_b).I(1,1,:) ) ~= n_mesh
                    error( 'body(i_b).I size error!' ) ;
                end
            end
            
            if ~isfield( body(i_b) ,'l_com' ) || isempty( body(i_b).l_com )
                body(i_b).l_com = [ 0 0 0 ] ;
            end
            if numel( body(i_b).l_com(:,1) ) == 1
                body(i_b).l_com = ones(n_mesh,1) * body(i_b).l_com  ;
            else
                if numel( body(i_b).l_com(:,1) ) ~= n_mesh
                    error( 'body(i_b).l_com size error!' ) ;
                end
            end
            
            if ~isfield( body(i_b) ,'tip' ) || isempty( body(i_b).tip )
                body(i_b).tip = 2 * body(i_b).l_com ;
            end
            if numel( body(i_b).tip(:,1) ) == 1
                body(i_b).tip = ones(n_mesh,1) * body(i_b).tip  ;
            else
                if numel( body(i_b).tip(:,1) ) ~= n_mesh
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
        body(i_b).m = [] ;
    end
    if ~isfield( body(i_b) ,'I' )
        body(i_b).I = [] ;
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
        n_mesh = numel( exload(i_l).exbody ) ;
        if n_mesh > 1
            n_mesh = n_mesh - 1 ;
        else
            exload(i_l).exbody(1,2) = 1 ;
        end
        if ~isfield( exload(i_l) ,'refbody' ) || isempty( exload(i_l).refbody )
            exload(i_l).refbody = ones(n_mesh,1) * [ 0 1 ] ;
        else if numel( exload(i_l).refbody(1,:) ) == 1
                exload(i_l).refbody(:,2) = 1 ;
            end
            if numel( exload(i_l).refbody(:,1) ) == 1
                exload(i_l).refbody = ones(n_mesh,1) * exload(i_l).refbody(1,:) ;
            end
        end
        
        if ~isfield( exload(i_l) ,'tr' ) || isempty( exload(i_l).tr )
            exload(i_l).tr.trans = [ 0 0 0 ] ;
            exload(i_l).tr.rot = [ 0 0 ] ;
            exload(i_l).tr.rot_type = 'none' ;
        end
        for i = 1 : numel( exload(i_l).tr )
            if ~isfield( exload(i_l).tr(i) ,'trans' ) || isempty( exload(i_l).tr(i).trans )
                exload(i_l).tr(i).trans = [ 0 0 0 ] ;
            end
            if ~isfield( exload(i_l).tr(i) ,'rot' ) || isempty( exload(i_l).tr(i).rot )
                exload(i_l).tr(i).rot = [ 0 0 0 1 ] ;
                exload(i_l).tr(i).rot_type = 'none' ;
            end
            if ~isfield( exload(i_l).tr(i) ,'rot_type' ) || isempty( exload(i_l).tr(i).rot_type )
                exload(i_l).tr(i).rot_type = 'none' ;
            end
        end
        if ~isfield( exload(i_l) ,'ftau' ) || isempty( exload(i_l).ftau )
            exload(i_l).ftau = zeros(n_mesh,6) ;
        else if numel( exload(i_l).ftau(:,1) ) == 1
                exload(i_l).ftau = ones(n_mesh,1) * exload(i_l).ftau(1,:) ;
            end
        end
        if numel( exload(i_l).ftau(1,:) ) ~= 6
            exload(i_l).ftau = [ exload(i_l).ftau zeros( n_mesh , 6 - numel( exload(i_l).ftau ) ) ] ;
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
            mesh(i_d).tr.rot = [ 0 0 0 1 ] ;
            mesh(i_d).tr.rot_type = 'none' ;
        end
        for i = 1 : numel( mesh(i_d).tr )
            if ~isfield( mesh(i_d).tr(i) ,'trans' ) || isempty( mesh(i_d).tr(i).trans )
                mesh(i_d).tr(i).trans = [ 0 0 0 ] ;
            end
            if ~isfield( mesh(i_d).tr(i) ,'rot' ) || isempty( mesh(i_d).tr(i).rot )
                mesh(i_d).tr(i).rot = [ 0 0 0 1 ] ;
                mesh(i_d).tr(i).rot_type = 'none' ;
            end
            if ~isfield( mesh(i_d).tr(i) ,'rot_type' ) || isempty( mesh(i_d).tr(i).rot_type )
                mesh(i_d).tr(i).rot_type = 'none' ;
            end
        end
        
    end
    
end


