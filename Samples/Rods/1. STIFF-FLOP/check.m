function [ s , world , body , joint , exload , par , symbols ] = check( par , world , body , joint , exload , mesh )
%% check inputs to set default values and pass errors
fprintf( 'check inputs... \n' )
par.elapsed_time = [ par.elapsed_time toc( par.timer ) ] ;
toc( par.timer )

%% init.
syms s dummy1
symbols = [ dummy1 ] ;


%% mesh
if ~isempty( mesh )
	[ body_mesh , joint_mesh ] = mesh_import( mesh , par ) ;
	body = [ body body_mesh ] ;
	joint = [ joint joint_mesh ] ;
end


%% pars
if isempty( par )
	par.sym = dummy1 ;
	par.var = 0 ;
	par.derive = 1 ; % set 1 to rederive in TMT
	par.opv = true ; % optimize results
	par.derive_collect = 1 ; % derive in single file: 1- single struct., 2- seperte struct.s, 3- separate func.s, 4- C func.s
	par.derive_mex = 1 ; % use Matlab codegen, use with par.derive_collect = 1 for now
	par.Anim = 1 ; % animation on (1) or off (0)
	par.movie = 0 ; % save movie
	par.equil = 1 ; % 1 to do initial static analysis
	par.simdyn = 1 ; % 1 to do dyn. sim.
	par.intn = 100 ; % num. int. steps
else
	if ~isfield( par , 'sym' ) || isempty( par.sym )
		par.sym = dummy1 ;
	end
	if ~isfield( par , 'var' ) || isempty( par.var )
		par.var = 0 ;
	end
	if ~isfield( par , 'derive' ) || isempty( par.derive )
		par.derive = 1 ;
	end
	if ~isfield( par , 'opv' ) || isempty( par.opv )
		par.opv = true ;
	end
	if ~isfield( par , 'derive_collect' ) || isempty( par.derive_collect )
		par.derive_collect = 1 ;
	end
	if ~isfield( par , 'derive_mex' ) || isempty( par.derive_mex )
		par.derive_mex = 1 ;
		par.derive = 1 ;
	end
	if ~isfield( par , 'Anim' ) || isempty( par.Anim )
		par.Anim = 1 ;
	end
	if ~isfield( par , 'movie' ) || isempty( par.movie )
		par.movie = 0 ;
	end
	if ~isfield( par , 'equil' ) || isempty( par.equil )
		par.equil = 1 ;
	end
	if ~isfield( par , 'simdyn' ) || isempty( par.simdyn )
		par.simdyn = 1 ;
	end
	if ~isfield( par , 'intn' ) || isempty( par.intn )
		par.intn = 50 ;
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
    
    if ~isfield( joint(i_j) , 'rom' )
        joint(i_j).rom = [] ;
    else
        if ~isempty( joint(i_j).rom )
			if ~isfield( joint(i_j).rom , 'order' ) || isempty( joint(i_j).rom.order )
            	error( 'joint(i_j).rom.order error' ) ;
			end
			if joint(i_j).second(2) == 0
				error( 'joint(i_j).second(2): ROM length error' ) ;
			end
        end
    end
    
    mainkin = 0 ;
    for i_b = 1 : numel( body )
        if joint(i_j).second(1) == i_b && j_b( i_b ) == 0 % first connected to i_b is in main kin. chain
            j_b( i_b ) = i_j ;
            mainkin = 1 ;
        end
    end
    
%     if mainkin == 1 && numel( joint(i_j).second ) == 2 && isempty( joint(i_j).rom ) 
%         i_j
%         error( 'mainkin == 1 && numel( joint(i_j).second ) == 2 && isempty( joint(i_j).rom )!' ) ;
%     end
%     if mainkin == 1 && numel( joint(i_j).second ) == 2 && isempty( joint(i_j).rom ) 
%         joint(i_j).second(2:joint(i_j).second(2)+1) = 1 : joint(i_j).second(2) ;
%     end
%     if mainkin == 1 && numel( joint(i_j).first ) == 2 && isempty( joint(i_j).rom )
%         joint(i_j).first(2:joint(i_j).first(2)+1) = 1 : joint(i_j).first(2) ;
%     end
            
    [ n_mesh , ind ] = max( [ numel( joint(i_j).second ) , numel( joint(i_j).first ) ] ) ;
    if ind == 2 && mainkin == 1 && numel( joint(i_j).first ) > 2 % only acceptable for sprdmp
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
        joint(i_j).tr.rot = [ 0 0 ] ;
    end
    
    for i = 1 : numel( joint(i_j).tr )
        if ~isfield( joint(i_j).tr(i) ,'trans' ) || isempty( joint(i_j).tr(i).trans )
            joint(i_j).tr(i).trans = [ 0 0 0 ] ;
        end
        if ~isfield( joint(i_j).tr(i) ,'rot' ) || isempty( joint(i_j).tr(i).rot )
            joint(i_j).tr(i).rot = [ 0 0 ] ;
        end
        rotrans = [ joint(i_j).tr(i).trans joint(i_j).tr(i).rot ] ;
        for i2 = 1 : numel( rotrans )
            if isinf( rotrans(i2) )
                nq = nq + 1 ;
                if ~isfield( joint(i_j) , 'dof' ) || numel( joint(i_j).dof ) < nq
                    joint(i_j).dof(nq).equal2 = [] ;
                    joint(i_j).dof(nq).init = zeros(n_mesh,1) ;
                    joint(i_j).dof(nq).spring.coeff = zeros(n_mesh,1) ;
                    joint(i_j).dof(nq).spring.init = zeros(n_mesh,1) ;
                    joint(i_j).dof(nq).spring.compr = ones(n_mesh,1) ;
                    joint(i_j).dof(nq).dir = zeros(n_mesh,1) ;
                    joint(i_j).dof(nq).damp.visc = zeros(n_mesh,1) ;
                    joint(i_j).dof(nq).damp.pow = zeros(n_mesh,1) ;
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
                
                if ~isempty( joint(i_j).rom )
                    S = [] ;
                    for i_s = 1 : joint(i_j).rom.order
                        i_sbc = i_s ;
                        if i2 < 4  % x,y,z Boundary Condition
                            i_sbc = i_s + 1 ;
                        end
                        S = [ S s^i_sbc ] ;
                    end
                    if ~isfield( joint(i_j).dof(nq) , 'init_s' ) || isempty( joint(i_j).dof(nq).init_s )
                        joint(i_j).dof(nq).init_s = ( 1 : numel( joint(i_j).dof(nq).init(1,:) ) ) * joint(i_j).second(2) / numel( joint(i_j).dof(nq).init(1,:) ) ;
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
    
    if ~isfield( joint(i_j) ,'tr2nd' )
        joint(i_j).tr2nd = [] ;
    end
    
    if isempty( joint(i_j).tr2nd ) &&  mainkin == 0 % joint not in main kin. chain
        joint(i_j).tr2nd.trans = [ 0 0 0 ] ;
        joint(i_j).tr2nd.rot = [ 0 0 ] ;
    end
    
    if ~isempty( joint(i_j).tr2nd )
        for i = 1 : numel( joint(i_j).tr2nd )
            if ~isfield( joint(i_j).tr2nd(i) ,'trans' ) || isempty( joint(i_j).tr2nd(i).trans )
                joint(i_j).tr2nd(i).trans = [ 0 0 0 ] ;
            end
            if ~isfield( joint(i_j).tr2nd(i) ,'rot' ) || isempty( joint(i_j).tr2nd(i).rot )
                joint(i_j).tr2nd(i).rot = [ 0 0 ] ;
            end
        end
        if ~isfield( joint(i_j) , 'dir' ) || isempty( joint(i_j).dir )
            joint(i_j).dir = zeros(n_mesh,1) ;
        else if numel( joint(i_j).dir(:,1) ) == 1
                joint(i_j).dir = ones(n_mesh,1) * joint(i_j).dir(1,:) ;
            end
        end
        if ~isfield( joint(i_j) , 'xaxis' ) || isempty( joint(i_j).xaxis )
            joint(i_j).xaxis = [] ; % default in local frame defined by joint.tr
        else if numel( joint(i_j).xaxis(:,1) ) == 1
                joint(i_j).xaxis = ones(n_mesh,1) * joint(i_j).xaxis(1,:) ;
            end
        end
        if ~isfield( joint(i_j) , 'spring' ) % constraint
            joint(i_j).spring = [] ;
        end
        if ~isempty( joint(i_j).spring )
            if ~isfield( joint(i_j).spring , 'coeff' ) || isempty( joint(i_j).spring.coeff )
                joint(i_j).spring.coeff = zeros(n_mesh,1) ;
            else if numel( joint(i_j).spring.coeff(:,1) ) == 1
                    joint(i_j).spring.coeff = ones(n_mesh,1) * joint(i_j).spring.coeff(1,:) ;
                end
            end
            if ~isfield( joint(i_j).spring , 'init' ) || isempty( joint(i_j).spring.init )
                joint(i_j).spring.init = zeros(n_mesh,numel(joint(i_j).spring.coeff(1,:))) ;
            else if numel( joint(i_j).spring.init(:,1) ) == 1
                    joint(i_j).spring.init = ones(n_mesh,1) * joint(i_j).spring.init(1,:) ;
                end
            end
            if ~isfield( joint(i_j).spring , 'compr' ) || isempty( joint(i_j).spring.compr )
                joint(i_j).spring.compr = ones(n_mesh,numel(joint(i_j).spring.coeff(1,:))) ;
            else if numel( joint(i_j).spring.compr(:,1) ) == 1
                    joint(i_j).spring.compr = ones(n_mesh,1) * joint(i_j).spring.compr(1,:) ;
                end
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
            joint(i_j).damp = [] ;  
        end
        if ~isempty( joint(i_j).damp )
            if ~isfield( joint(i_j).damp , 'visc' ) || isempty( joint(i_j).damp.visc )
                joint(i_j).damp.visc(:,1) = 0 ;
            else if numel( joint(i_j).damp.visc(:,1) ) == 1
                    joint(i_j).damp.visc = ones(n_mesh,1) * joint(i_j).damp.visc(1,:) ;
                end
            end
            if ~isfield( joint(i_j).damp , 'pow' ) || isempty( joint(i_j).damp.pow )
                joint(i_j).damp.pow =  ones(n_mesh,numel(joint(i_j).damp.visc(1,:))) ;
            else if numel( joint(i_j).damp.pow(:,1) ) == 1
                    joint(i_j).damp.pow = ones(n_mesh,1) * joint(i_j).damp.pow(1,:) ;
                end
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
            if ~isfield( joint(i_j) , 'damp' ) || isempty( joint(i_j).input )
                joint(i_j).damp.visc = zeros(n_mesh,numel(joint(i_j).input(1,:))) ;
                joint(i_j).damp.pow = ones(n_mesh,numel(joint(i_j).input(1,:))) ;
            end  
        end
        if ~isfield( joint(i_j) , 'fixed' )
            joint(i_j).fixed = [] ;
        end
        if ~isempty( joint(i_j).fixed ) 
            if numel( joint(i_j).fixed(1,:) ) == 3 || numel( joint(i_j).fixed(1,:) ) == 6
                error( 'numel( joint(i_j).fixed(:,1) ) error!' ) ;
            end
            if numel( joint(i_j).fixed(:,1) ) == 1
                joint(i_j).fixed = ones(n_mesh,1) * joint(i_j).fixed(1,:) ;
            end
            if ~isfield( joint(i_j) , 'spring' ) || isempty( joint(i_j).spring )
                joint(i_j).spring.coeff = zeros(n_mesh,numel(joint(i_j).fixed(1,:))) ;
                joint(i_j).spring.init = zeros(n_mesh,numel(joint(i_j).fixed(1,:))) ;
                joint(i_j).spring.compr = ones(n_mesh,numel(joint(i_j).fixed(1,:))) ;
            end 
            if ~isfield( joint(i_j) , 'damp' ) || isempty( joint(i_j).fixed )
                joint(i_j).damp.visc = zeros(n_mesh,numel(joint(i_j).fixed(1,:))) ;
                joint(i_j).damp.pow = ones(n_mesh,numel(joint(i_j).fixed(1,:))) ;
            end 
            if ~isfield( joint(i_j) , 'input' ) || isempty( joint(i_j).input )
                joint(i_j).input = zeros(n_mesh,numel(joint(i_j).fixed(1,:))) ;
            end  
        end
    end
    if ~isempty( joint(i_j).rom )
        if ~isfield( joint(i_j) , 'spring' )
            joint(i_j).spring = [] ;
        end
        if ~isfield( joint(i_j).spring , 'coeff' ) || isempty( joint(i_j).spring.coeff )
            joint(i_j).spring.coeff = zeros(1,6) ;
        end
        if ~isfield( joint(i_j).spring , 'init' ) || isempty( joint(i_j).spring.init )
            joint(i_j).spring.init = zeros(1,6) ;
        end
        if ~isfield( joint(i_j).spring , 'compr' ) || isempty( joint(i_j).spring.compr )
            joint(i_j).spring.compr = ones(1,6) ;
        end
        if ~isfield( joint(i_j) , 'dir' ) || isempty( joint(i_j).dir )
            joint(i_j).dir = zeros(1,6) ;
        end
        if ~isfield( joint(i_j) , 'damp' ) % constraint
            joint(i_j).damp = [] ;
        end
        if ~isfield( joint(i_j).damp , 'visc' ) || isempty( joint(i_j).damp.visc )
            joint(i_j).damp.visc = zeros(1,6) ;
        end
        if ~isfield( joint(i_j).damp , 'pow' ) || isempty( joint(i_j).damp.pow )
            joint(i_j).damp.pow = ones(1,6) ;
        end
        if ~isfield( joint(i_j) , 'input' )
            joint(i_j).input = [] ;
        end
        if isempty( joint(i_j).input )
            joint(i_j).input = zeros(1,6) ;
        end        
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


%% exload
for i_l = 1 : numel( exload )
    
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
    else if numel( exload(i_l).refbody ) == 1
		    exload(i_l).refbody(2) = 1 ;
		    exload(i_l).refbody = ones(n_mesh,1) * exload(i_l).refbody(2) ;
		 else if numel( exload(i_l).refbody(:,1) ) == 1
		    	 exload(i_l).refbody = ones(n_mesh,1) * exload(i_l).refbody(2) ;
	    	  end
         end
    end
    
    if ~isfield( exload(i_l) ,'tr' ) || isempty( exload(i_l).tr )
        exload(i_l).tr.trans = [ 0 0 0 ] ;
        exload(i_l).tr.rot = [ 0 0 ] ;
    end   
    for i = 1 : numel( exload(i_l).tr )
        if ~isfield( exload(i_l).tr(i) ,'trans' ) || isempty( exload(i_l).tr(i).trans )
            exload(i_l).tr(i).trans = [ 0 0 0 ] ;
        end
        if ~isfield( exload(i_l).tr(i) ,'rot' ) || isempty( exload(i_l).tr(i).rot )
            exload(i_l).tr(i).rot = [ 0 0 ] ;
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



