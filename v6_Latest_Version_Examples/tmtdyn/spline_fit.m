%% dof_spline_fit
% to fit a spline with time variable (state) coefficients to an axis, i.e. ROM methor
function joint = spline_fit( s, sw, q, q0, par, joint, i_joint, i_dofAxsAngl, i_copies, figure_states )

sym_empty = sym( [] );
sym_zero = sym( 0 ) ;

lgnds{1} = []; % plot legends
if par.plotIC > 1 ; figure(figure_states); hold off ; end

qC = q; % mix of q and qC to accomodate qC states for the current dofAxsAngl too, needed for continuity and relaxed state (spring) constraints
qC0 = q0 ;

spline.init_s_index_all{1} = sym_empty ; % index of initial axial locations for all spline segments
spline.coeff_all{1} = sym_empty ; % all spline coeffs
spline.init_coeff_all{1} = sym_empty ; % constant coeff.s and initial value of dof coeff.s; each row for a spline segment, last row for summation of all
spline.series{1} = sym_empty ; % spline series for current dof axis/angle; each element for a spline segment, 2nd row for terms without base growing effect
spline.init_series{1} = sym_empty ; % spline series initial value (based on q0) for current dof axis/angle; each element for a spline segment
spline.condition{1} = sym_empty ; % spline segments' conditionitions (switches)

%% dof
% initializations
joint(i_joint).dof(i_dofAxsAngl).qCs{i_copies} = sym_empty ; % dof coeff of all segments as symbolic variables qC_i
joint(i_joint).dof(i_dofAxsAngl).init_qs{i_copies} = sym_empty ; % initial value for dof coeff of all segments
joint(i_joint).dof(i_dofAxsAngl).index_qCs{i_copies} = sym_empty ;  % coeff index for dof coeff of all segments; 1st row is i_segm; 2nd row is i_coeff
joint(i_joint).dof(i_dofAxsAngl).series{i_copies} = sym_zero ; % final spline series for a variabl axis/angle absed
joint(i_joint).dof(i_dofAxsAngl).init_series{i_copies} = sym_zero ; % final spline init_series for a variabl axis/angle absed
joint(i_joint).dof(i_dofAxsAngl).spline{i_copies} = spline;

% fit spline
source = joint(i_joint).dof(i_dofAxsAngl);
[ joint(i_joint).dof(i_dofAxsAngl) , qC , qC0 , lgnds ] = spline_fitting( source, s, sw, qC, qC0, par, joint, i_joint, i_dofAxsAngl, i_copies , false , figure_states , lgnds ) ;

%% relaxed state, i.e. spring
% initializations
joint(i_joint).dof(i_dofAxsAngl).spring.qCs{i_copies} = sym_empty ; % dof coeff of all segments as symbolic variables qC_i
joint(i_joint).dof(i_dofAxsAngl).spring.init_qs{i_copies} = sym_empty ; % initial value for dof coeff of all segments
joint(i_joint).dof(i_dofAxsAngl).spring.index_qCs{i_copies} = sym_empty ;  % coeff index for dof coeff of all segments; 1st row is i_segm; 2nd row is i_coeff
joint(i_joint).dof(i_dofAxsAngl).spring.series{i_copies} = sym_zero ; % final spline series for a variabl axis/angle absed
joint(i_joint).dof(i_dofAxsAngl).spring.init_series{i_copies} = sym_zero ; % final spline init_series for a variabl axis/angle absed
joint(i_joint).dof(i_dofAxsAngl).spring.spline{i_copies} = spline;

% fit spline
source = joint(i_joint).dof(i_dofAxsAngl).spring;
[ joint(i_joint).dof(i_dofAxsAngl).spring , qC , qC0 , lgnds ] = spline_fitting( source, s, sw, qC, qC0, par, joint, i_joint, i_dofAxsAngl, i_copies , true , figure_states , lgnds ) ;

%% plot final spline
source = joint(i_joint).dof(i_dofAxsAngl); % plot dof axis/angle full body
lgnds = plot_results( source, s, sw, qC, qC0, par, joint, i_joint, i_dofAxsAngl, i_copies , 0 , false , figure_states , lgnds );

source = joint(i_joint).dof(i_dofAxsAngl).spring; % plot dof axis/angle full relaxed state
lgnds = plot_results( source, s, sw, qC, qC0, par, joint, i_joint, i_dofAxsAngl, i_copies , 0 , true , figure_states , lgnds );


%% fitting function
function [ source , qC , qC0 , lgnds ] = spline_fitting( source, s, sw, qC, qC0, par, joint, i_joint, i_dofAxsAngl, i_copies , isSpring , figure_states , lgnds  )

% initialization
sym_empty = sym( [] ) ;
sym_zero = sym( 0 ) ;
n_poly_order = joint(i_joint).rom.order(i_copies,i_dofAxsAngl) ; % polynomial order

source.init(i_copies,:) = sym( source.init(i_copies,:) );
source.init_s(i_copies,:) = sym( source.init_s(i_copies,:) );
if ~joint(i_joint).rom.var_init % improve performance by setting all initial symbolic values to double
    source.init(i_copies,:) = subs( source.init(i_copies,:), par.sym, par.var );
    source.init_s(i_copies,:) = subs( source.init_s(i_copies,:), par.sym, par.var );
else % otherwise only set the control symbolic values (inputs) to double
    source.init(i_copies,:) = subs( source.init(i_copies,:), par.control_sym, par.control_var );
    source.init_s(i_copies,:) = subs( source.init_s(i_copies,:), par.control_sym, par.control_var );
end
   
source.fit_type = sym( source.fit_type ) ; % to avoid sym-double assignment error

axial_offset_user = source.rom_offset(i_copies,2); % axial offset from original integration range, no need to modify spline_knots since logistic function s and s_knot cancels each other; l_tip updates automatically
axial_offset_s_init = 0 ; % s_init offset for enforcing continuity

n_C_dof = 0 ; % number of doeff coeff.s

% spring similar to the dof
if isnan( source.init(i_copies,1) ) % only happens if source.init = NAN and has only 1 element
    source.equal2{1}(i_copies,:) = [i_joint, i_copies, i_dofAxsAngl, nan, 0, 0, 1] ; % {i_coeff}[i_joint, i_copies, i_dofAxsAngl, i_coeff, l_rom, diff_order, coeff] x i_dof_mult
end

% spline fitting    
if isnan( source.equal2{1}(i_copies,4) ) % copy whole dof axis/angle from other axis/angle
    
    temp = source.equal2{1}(i_copies,:) ; % {i_coeff}[i_joint, i_copies, i_dofAxsAngl, i_coeff, l_rom, diff_order, coeff] x i_dof_mult
    
    % NOT NEEDED! Also may cause the change of dimension of a single row which is impossible
    % source.init_s(i_copies,:) = joint(temp(1)).dof(temp(3)).init_s(temp(2),:) ; % copy over intial s locations
    % source.init(i_copies,:) = joint(temp(1)).dof(temp(3)).init(temp(2),:) ; % copy initial values
    
    source.fit_type(i_copies,1:numel(joint(temp(1)).dof(temp(3)).fit_type(temp(2),:))) = joint(temp(1)).dof(temp(3)).fit_type(temp(2),:) ; % copy segmentation info, i.e type and s_knots
    source.qCs{i_copies} = sym_empty ; % no new dof coeff.s
    source.qs{i_copies} = joint(temp(1)).dof(temp(3)).qs{temp(2)} ; % copy over all q_states
    source.init_qs{i_copies} = joint(temp(1)).dof(temp(3)).init_qs{temp(2)} ; % copy over all qs initial values
    source.index_qCs{i_copies} = joint(temp(1)).dof(temp(3)).index_qCs{temp(2)} ; % copy over all qs initial values
    source.series{i_copies} = joint(temp(1)).dof(temp(3)).series{temp(2)} ; % copy over the final spline series
    source.init_series{i_copies} = joint(temp(1)).dof(temp(3)).init_series{temp(2)} ; % copy over the final spline init_series
    
    source.spline{i_copies} = joint(temp(1)).dof(temp(3)).spline{temp(2)}; % copy over all spline elments
    
else % fit a brand new spline
    
    for i_segm = 1 : numel( source.fit_type(i_copies,:) ) % number of segments is one less than number of elements in fit_type
        
        % init values
        init_s_index{i_segm} = 1 : numel( source.init_s(i_copies,:) ); % index of elements in init_s for the current spline segment, default is all the elements
        
        S = sym_empty ; % shape function matrix for state coeff.s
        b = sym_empty ; % shape function vector for fixed coeff.s
        
        C_dof{i_segm} = sym_empty ; % time variant coeff.s, i.e. q_states; overal 1 x n_C_dof
        C_dof_init{i_segm} = sym_empty ; % initial value for C_dof; overal 1 x n_C_dof
        C_dof_index{i_segm} = sym_empty ; % index (order) for C_dof elements;  i_segm = 1 x i_C_dof; i_coeff = 2 x i_C_dof; overal 2 x n_C_dof
        C_const{i_segm} = sym_empty ; % constant/constrained coeff.s
        C_all{i_segm} = sym_empty ; % all polynomial segment coeff.s
        C_all_init{i_segm} = sym_empty ; % initial value for all polynomial segment coeff.s
        condition_piecewise(i_segm) = sym( 1 ) ; % piecewise function conditions
        condition_logistic(i_segm) = sym( 1 ) ; % logistic function conditions
        series(i_segm) = sym_zero ;
        init_series(i_segm) = sym_zero ;
        
        is_cont_const = 0; % is continuity constraint
        
        % segmentation: SEGMENTATION DISREGARDS VARIABLE INTIAL STATES!!!
        if i_segm < numel( source.fit_type(i_copies,:) ) % extract init_s lower than segment domain upper range, not needed for the last segment
            init_s_index{i_segm} = find( subs(source.init_s(i_copies,:), par.sym, par.var) <= ... % elements smaller equal to the segment length upper range
                subs(source.fit_type(i_copies,i_segm+1), par.sym, par.var) ) ;
        end
        
        if i_segm > 1 % extract init_s larger than segment domain lower range, not needed for the first segment
            
            init_s_index{i_segm} = find( subs(source.init_s(i_copies,init_s_index{i_segm}), par.sym, par.var) >= ... % elements larger equal to the segment length lower range in remaining elements from previous step
                subs(source.fit_type(i_copies,i_segm), par.sym, par.var) ) ;
            
            % continuity conditionition at segment locations
            axial_offset_s_init = source.fit_type(i_copies,i_segm) ; % new segment polynomial axial shift to match the spatial integration range; vars in spline_knots will not be substituted by par.var or par.control_var
            
            for i_p = 1 : source.spc_order % continuity kinematic constraint for new segment; implemented up to the spline continuity order spc_order
                is_cont_const = 1 ; % is contuinity constraint
                source.equal2{i_p} = sym( source.equal2{i_p} ); % [i_joint, i_copies, i_axsAngl, i_coeff, l_rom, diff_order, mult_coeff] x i_dof_mult
                source.equal2{i_p}(i_copies,:) =  [i_joint, i_copies, i_dofAxsAngl, 0, source.fit_type(i_copies,i_segm), i_p-1, 1] ; % coefficient_similar_to_dof_at_tip
            end
            
        end
        
        % segment conditionitions (switches)
        if ismember( source.fit_type(i_copies,1) , [ 2 , 3 ] ) % 2: spline_piecewise conditionitions, 3: spline_logistic_function
            
            % spline_piecewise conditionitions
            if i_segm == 1 % base segment
                condition_piecewise(i_segm) = ( sw <= source.fit_type(i_copies,i_segm+1) ) ;
            elseif i_segm ==  numel( source.fit_type(i_copies,:) ) % tip segment
                condition_piecewise(i_segm) = ( sw > source.fit_type(i_copies,end) ) ;
            else % other middle segments
                condition_piecewise(i_segm) = ( sw > source.fit_type(i_copies,i_segm) && sw < source.fit_type(i_copies,i_segm+1) );
            end
            
            % spline_logistic_function
            lfk = joint(i_joint).rom.growth; % logistic growth rate (curve steepness)
            if i_segm > 1 % other than base segment
                condition_logistic(i_segm) = 1 / ( 1 + exp( -lfk * ( sw - source.fit_type(i_copies,i_segm) ) ) ) ;
            end
            
        end
        
        % if no init data is provided for this segment
        ... TODO
        
        % coeff equality constraints
        for i_coeff = 1 : n_poly_order + 1 % check all the polynomial coeff.s
            
            if source.equal2{i_coeff}(i_copies,1) ~= 0 % it is a constraint
                
                b = [ b , (s)^(i_coeff-1) ] ; % corresponding shape function for a constant coefficient
                temp = source.equal2{i_coeff}(i_copies,:) ; % [i_joint, i_copies, i_axsAngl, i_coeff, l_rom, diff_order, mult_coeff] x i_dof_mult
                if temp(7) == 0; temp(7) = 1; end % set default multiplication coeff. if not specified, used for gearing or chnag constraint direction when needed
                
                if isnan( temp(1) ) % i_joint is nan: ground fixed or set_rom_coefficient
                    C_const{i_segm} = [ C_const{i_segm} ; temp(5) ] ; % set to l_rom (i.e. fixed position)
                else
                    if temp(4) > 0 % i_coeff of the target dof is provided
                        C_const{i_segm} = [ C_const{i_segm} ; temp(7)*diff( joint(temp(1)).dof(temp(3)).spline(temp(2)).coeff_all{i_segm}(temp(4)) , s , temp(6) ) ] ;
                    else
                        if isnan( temp(4) ) % i_coeff is nan: same i_coeff of the target dof as i_coeff of the current dof
                            C_const{i_segm} = [ C_const{i_segm} ; temp(7)*diff( joint(temp(1)).dof(temp(3)).spline(temp(2)).coeff_all{i_segm}(i_coeff) , s , temp(6) ) ] ;
                        else % otherwise it is l_rom case: equal to a location along the curve of the other dof axis/angle spline
                            if isnan( temp(5) ) % l_rom is nan: consider tip
                                C_const{i_segm} = [ C_const{i_segm} ; temp(7)*subs( diff( joint(temp(1)).dof(temp(3)).series{temp(2)} , s , temp(6) ) , [s, sw] , joint(temp(1)).rom.length(temp(2),2) * [1, 1] ) ] ; % should include s offset
                            else % l_rom is an actual value
                                if is_cont_const && i_coeff <= source.spc_order % continouity constraint w.r.t. previous segment: point to the segment series not joint series to fully support ligistic functions too
                                    C_const{i_segm} = [ C_const{i_segm} ; temp(7)*subs( diff( source.spline{i_copies}.series{i_segm-1} , s , temp(6) ) , [s, sw] , temp(5) * [1, 1] ) ] ; % should include s offset
                                else % general constraint
                                    C_const{i_segm} = [ C_const{i_segm} ; temp(7)*subs( diff( joint(temp(1)).dof(temp(3)).series{temp(2)} , s , temp(6) ) , [s, sw] , temp(5) * [1, 1] ) ] ; % should include s offset
                                end
                            end
                        end
                    end
                end
                
                C_all{i_segm} = [ C_all{i_segm} , C_const{i_segm}(end) ] ;
                
            else % time variant coeff.s
                
                if i_coeff == 1 && ... % base conditionition (C0): acts only if no other kin. const. is specified
                        n_poly_order ~= 0 && ... % not for rigid body joints
                        ~isSpring && ... % not for relaxed state (spring)
                        ~joint(i_joint).rom.free_base(i_copies) % not if explicitly asked for free spline base
                    
                    b = [ b (s)^(i_coeff-1) ] ; % update shape function vector for const. coeff.s
                    C_const{i_segm} = [ C_const{i_segm} ; 0 ] ; % set base (i.e. C0) to 0, C_const = [ C_const ; temp(5) ] ; not for relaxed state (spring)
                    C_all{i_segm} = [ C_all{i_segm} , C_const{i_segm}(end) ] ;

                else
                    
                    S = [ S (s)^(i_coeff-1) ] ; % update shape function vector for variable coeff.s
                    n_C_dof = n_C_dof + 1 ; %  number of dof coeff.s
                    C_dof_index{i_segm} = [ C_dof_index{i_segm}, [ i_segm ; i_coeff ]  ] ; % i_segm = 1 x i_C_dof; i_coeff = 2 x i_C_dof; overal 2 x n_C_dof
                    if isSpring
                        C_dof{i_segm} = [ C_dof{i_segm} , sym( [ 'qC' num2str( n_C_dof ) ] , 'real' ) ] ; % dof coeff.s are defined as symbolic variables: qC_i
                    else
                        C_dof{i_segm} = [ C_dof{i_segm} , sym( [ 'qCS' num2str( n_C_dof ) ] , 'real' ) ] ; % dof coeff.s are defined as symbolic variables: qC_i
                    end
                        C_all{i_segm} = [ C_all{i_segm} , C_dof{i_segm}(end) ] ;
                
                end
                
            end
            
        end
        
        % initial dof val
        C_const_init = subs( C_const{i_segm} , qC , qC0 ) ; % constant/constrained coeff.s initial value, it should not be a function of other q_states
        S0 = sym_empty ; % initial values for S
        b0 = sym_empty ; % initial values for b
        
        for i_coeff = init_s_index{i_segm} % check only elements found to be in the current segment axial range
            s0 = source.init(i_copies,i_coeff) - axial_offset_s_init ; % s to start from 0 for the continuity constraint to properly work
            S0 = [ S0 ; subs( S , s , s0 ) ] ;
            b0 = [ b0 ; subs( b , s , s0 ) ] ;
        end
        
        if isempty( C_const{i_segm} ) % case of no predefined coeff., i.e. all coeffs are dof
            C_const{i_segm} = 0 ; b = 0 ;
            C_const_init = 0 ; b0 = 0 ;
        end
        
        if ~joint(i_joint).rom.var_init % improve performance by setting inital values to double if not already set to
            C_const_init = subs( C_const_init , par.sym , par.var ) ;
            S0 = subs( S0 , par.sym , par.var ) ;
            b0 = subs( b0 , par.sym , par.var ) ;
        else
            C_const_init = subs( C_const_init , par.control_sym , par.control_var ) ;
            S0 = subs( S0 , par.control_sym , par.control_var ) ;
            b0 = subs( b0 , par.control_sym , par.control_var ) ;
        end
        
        % inverse problem for initial coefficients, final series with variable coeff.s and initial values:
        if isempty( S0 ) % no variable coeff.s, to avoid singular matrix inversion
            
            init_series(i_segm) = ( b * C_const_init ).' ; % initial series
            series(i_segm) = ( b * C_const{i_segm} ).' ; % time variant series: axis/angle is fully pre-defined
        
        else % some variable coeff.s
            
            C_dof_init{i_segm} = ( pinv( S0 ) * ( source.init(i_copies,init_s_index{i_segm}).' - b0 * C_const_init ) ).' ; % record coeff. init values
            init_series(i_segm) = C_dof_init{i_segm} * S.' + ( b * C_const_init ).' ; % initial full series
            series(i_segm) = C_dof{i_segm} * S.' + ( b * C_const{i_segm} ).' ; % time variant full series
            
        end
        
        % update states and initial values to include qC too which maybe needed for continuity in the next segments and relaxed state (spring) constraints
        qC = [ qC , C_dof{i_segm} ] ;
        qC0 = [ qC0 , C_dof_init{i_segm} ] ;
        
        C_all_init{i_segm} = subs( C_all{i_segm} , qC , qC0 ) ; % initial value for all the segment coeff.; qC is used to cover q & qC from constraints too
             
        % correct axial offset: segment series starts from 0 but segment integration range starts from axial_offset_s_init
        % condition does not need modification here!
        series(i_segm) = subs( series(i_segm) , s , s - axial_offset_s_init + axial_offset_user ) ;
        init_series(i_segm) = subs( init_series(i_segm) , s , s - axial_offset_s_init + axial_offset_user ) ;

        % export terms
        source.qCs{i_copies} = [ source.qCs{i_copies} , C_dof{i_segm} ] ; % add C_dof to all joint.dof.qCs
        source.init_qs{i_copies} = [ source.init_qs{i_copies} , C_dof_init{i_segm} ] ; % add C_dof_0 to all joint.dof.init_qs
        source.index_qCs{i_copies} = [ source.index_qCs{i_copies} , C_dof_index{i_segm} ] ; % record coeff and segment index for the dof coeff.s; i_segm = 1 x i_C_dof; i_coeff = 2 x i_C_dof; overal 2 x n_C_dof
        
        % forming spline series
        switch source.fit_type(i_copies,1)
            
            case 2 % spline_piecewise conditionitions
                
                if i_segm == 1 % 1st segment
                    
                    source.series{i_copies} = piecewise( condition_piecewise(i_segm) , series(i_segm) ) ;
                    source.init_series{i_copies} = piecewise( condition_piecewise(i_segm) , init_series(i_segm) ) ;
                    
                else % adding the rest of segments
                    if par.pw2lg % spline_logistic_function, piecewise deals with non-necessary multiplication of conditions one of which are zero hence the whole term is zero!
                        
                        source.series{i_copies} = piecewise( condition_piecewise(i_segm) , condition_logistic(i_segm) * ( series(i_segm) - series(i_segm-1) ) , source.series{i_copies} ) ;
                        source.init_series{i_copies} = piecewise( condition_piecewise(i_segm) , condition_logistic(i_segm) * ( init_series(i_segm) - init_series(i_segm-1) ) , source.init_series{i_copies} ) ;
                        
                    else % spline_piecewise conditionitions
                        
                        source.series{i_copies} = piecewise( condition_piecewise(i_segm) , series(i_segm) , source.series{i_copies} ) ;
                        source.init_series{i_copies} = piecewise( condition_piecewise(i_segm) , init_series(i_segm) , source.init_series{i_copies} ) ;
                        
                    end
                end
                
            case 3 % spline_logistic_function
                
                if i_segm == 1 % 1st segment
                    source.series{i_copies} = series(i_segm) ;
                    source.init_series{i_copies} = init_series(i_segm) ;
                else % adding the rest of segments
                    source.series{i_copies} = source.series{i_copies} + condition_logistic(i_segm) * ( series(i_segm) - series(i_segm-1) ) ;
                    source.init_series{i_copies} = source.init_series{i_copies} + condition_logistic(i_segm) * ( init_series(i_segm) - init_series(i_segm-1) ) ;
                end
                
            otherwise % polynomial ROM or rigid-body joints
                
                source.series{i_copies} = series(i_segm) ;
                source.init_series{i_copies} = init_series(i_segm) ;
                
        end
        
        source.spline{i_copies}.init_s_index_all{i_segm} = init_s_index{i_segm} ;
        source.spline{i_copies}.coeff_all{i_segm} = C_all{i_segm} ;
        source.spline{i_copies}.init_coeff_all{i_segm} = C_all_init{i_segm} ;
        source.spline{i_copies}.series{i_segm} = series(i_segm) ;
        source.spline{i_copies}.init_series{i_segm} = init_series(i_segm) ;
        source.spline{i_copies}.condition{i_segm} = [ condition_piecewise(i_segm) , condition_logistic(i_segm) ] ;
        
        % plot results
        lgnds = plot_results( source, s, sw, qC, qC0, par, joint, i_joint, i_dofAxsAngl, i_copies , i_segm , isSpring , figure_states , lgnds );
        
    end
end


%% plot outcomes
function lgnds = plot_results( source, s, sw, qC, qC0, par, joint, i_joint, i_dofAxsAngl, i_copies , i_segm , isSpring , figure_states , lgnds )

if par.plotIC > 1 % compare fit curve with init data

    % initialize
    lgnd = { 'initial state' , 'relaxed state' } ;
    mrkrs = { 'o' , 'x' } ; % markers
    lnstl = { '-' , '--' } ; % line style
    if ~isSpring ; isSpring = 1 ; else isSpring = 2 ; end
    
    figure(figure_states);
    i_lgnds = numel( lgnds ) ;
    
    % decide whether plot the whole axis (spline) or just a segment (polynomial)
    if i_segm == 0 % plot whole dof axis/angle

        init_s = subs( source.init_s(i_copies,:), par.sym, par.var);
        init_points = subs( source.init(i_copies,:), par.sym, par.var);   
        segmn_s_ends = subs(source.init_s(i_copies,[1,end]), par.sym, par.var) ;     

    else % plot single segment

        init_s_index = source.spline{i_copies}.init_s_index_all{i_segm}; % segment init_s indexes
    
        % initial control points, being plotted only with the segments
        init_s = subs( source.init_s(i_copies,init_s_index), par.sym, par.var);
        init_points = subs( source.init(i_copies,init_s_index), par.sym, par.var);
        plot(init_s(1,:), init_points(1,:), mrkrs{isSpring}); hold on
        lgnds{1+i_lgnds} = [ lgnd{isSpring} ' control points' ] ;
        
        % fitted spline range
        segmn_s_ends = subs(source.init_s(i_copies,[1,end]), par.sym, par.var) ;
        if i_segm > 1
            segmn_s_ends(1) = subs( source.fit_type(i_copies,i_segm), par.sym, par.var) ;
        end
        if i_segm < numel( source.fit_type(i_copies,:) )
            segmn_s_ends(2) = subs( source.fit_type(i_copies,i_segm+1) , par.sym , par.var ) ;
        end

    end

    s_segm = linspace(segmn_s_ends(1,1), segmn_s_ends(1,2), par.n_int); % fitted spline datapoints
    
    % fitted spline
    spline_sgmn = subs(subs(subs(source.init_series{i_copies}, par.sym, par.var), sw, s), s, s_segm);
    plot(s_segm, spline_sgmn, lnstl{isSpring}, 'linewidth', 2); hold on
    
    if i_segm ~= 0 % single segment
        lgnds{2+i_lgnds} = [ lgnd{isSpring} ' fitted polyn' ] ;
    else % full spline
        lgnds{1+i_lgnds} = [ lgnd{isSpring} ' fitted spline' ] ;
    end
    
    % labeling
    title(['joint: ' num2str(i_joint) ', mesh instance: ' num2str(i_copies) ', dof: ' num2str(i_dofAxsAngl) ', spline segment: ' num2str(i_segm)])
    xlabel('s [m]'); ylabel('state');
    legend( lgnds{:} ) ;
    
    % report
    fprintf( 'Interpolation check! Press any key to continue... \n' )
    pause
    
end
