classdef dof_builder < handle
    
    properties (GetAccess = public, SetAccess=private)
        source;
        template;
        q_index ; % tr dof numerator
        
        equal2_val; % [i_j(joint), i_d(mesh), i_h(DOF in joint), i_r(rom coeff), l(length along rom), i_p(derivative order), c(coeff)]
        init_val = sym([]);
        init_s_val = sym([]);
        the_spring = sym([]);
        active_direction = sym([]);
        the_damping = sym([]);
        input_val = sym([]);
        control_val = sym([]);
        pid_val = [];
        fixed_val = sym([]);
        rom_order_val = sym([]);
        init_type_val = sym([]);
        rom_offset_val = sym([]);
        fit_type_val;
        spc_order;
    end
    
    properties (GetAccess = public, SetAccess=public)
        pipe;
        i_S = 1; % counter for executed functions of the full DDL input in the current (this) object
    end
    
    methods
        function self = dof_builder(source, q_index)
            self.source = source;
            self.template = source.template;
            self.pipe = source.template.joint.dof;
            self.q_index = q_index;
        end
        
        function self = equal2(self, equal2, n_r) % [j_count, n_copies, nj_dof, i_dof_mult, val_or_l_rom diff_order coeff] x i_dof_mult -or- [i_j, i_d, i_h, i_r, l, i_p, c] x n_r
            if nargin == 2
                n_r = 1 ;
            end
            self.equal2_val{n_r} = equal2;
            self.pipe.equal2{n_r} = equal2;
            self.i_S = self.i_S + 1;
        end
        
        function self = similar_to_dof(self, coeff, i_j, i_h, i_d) % note order change
            if nargin == 4
                i_d = 1; % results in all mesh nodes having the same equal2 property
            end
            n_d = 1 : numel(coeff);
            self = element_similar_to_dof(self, n_d, coeff, ones(numel(n_d),1).*i_j, ones(numel(n_d),1).*i_h, ones(numel(n_d),1).*i_d);
        end
        
        function self = element_similar_to_dof(self, n_d, coeff, i_j, i_h, i_d) % note order change
            if nargin == 5
                i_d = 1; % results in all mesh nodes having the same equal2 property
            end
            % [i_j, i_d, i_h, i_r, 0, 0, coeff]
            self.equal2_val{1}(n_d,:) = [ones(numel(n_d),1).*i_j, ones(numel(n_d),1).*i_d, ones(numel(n_d),1).*i_h, ones(numel(n_d),1).*nan, ones(numel(n_d),1).*0, ones(numel(n_d),1).*0, ones(numel(n_d),1).*coeff];
            self.pipe.equal2{1}(n_d,:) = [ones(numel(n_d),1).*i_j, ones(numel(n_d),1).*i_d, ones(numel(n_d),1).*i_h, ones(numel(n_d),1).*nan, ones(numel(n_d),1).*0, ones(numel(n_d),1).*0, ones(numel(n_d),1).*coeff];
            self.i_S = self.i_S + 1;
        end
        
        function self = coefficient_similar_to_dof_order(self, n_r, coeff, i_j, i_h, i_r, i_d) % note the order change
            if nargin == 5
                i_r = nan; % equal to the same coeff in the other joint/dof
            end
            if nargin == 6
                i_d =  1; % results in all mesh nodes having the same equal2 property
            end
            n_d = 1 : numel(coeff);
            self = element_coefficient_similar_to_dof_order(self, n_d, n_r, coeff, i_j, i_h, i_r, i_d);
        end
        
        function self = element_coefficient_similar_to_dof_order(self, n_d, n_r, coeff, i_j, i_h, i_r, i_d) % note the order change
            if nargin == 6
                i_r = nan; % equal to the same coeff in the other joint/dof
            end
            if nargin == 7
                i_d =  1; % results in all mesh nodes having the same equal2 property
            end
            % [i_j, i_d, i_h, i_r, 0, 0, coeff]
            self.equal2_val{n_r}(n_d,:) = [ones(numel(n_d),1).*i_j, ones(numel(n_d),1).*i_d, ones(numel(n_d),1).*i_h, ones(numel(n_d),1).*i_r, ones(numel(n_d),1).*0, ones(numel(n_d),1).*0, ones(numel(n_d),1).*coeff];
            self.pipe.equal2{n_r}(n_d,:) = [ones(numel(n_d),1).*i_j, ones(numel(n_d),1).*i_d, ones(numel(n_d),1).*i_h, ones(numel(n_d),1).*i_r, ones(numel(n_d),1).*0, ones(numel(n_d),1).*0, ones(numel(n_d),1).*coeff];
            self.i_S = self.i_S + 1;
        end
        
        function self = coefficient_similar_to_dof_at_axial_location(self, n_r, coeff, i_j, i_h, l, i_d) % note the order change
            if nargin == 5
                l =  0; % equal to the other joint/dof at base
            end
            if nargin == 6
                i_d = 1; % results in all mesh nodes having the same equal2 property
            end
            n_d = 1 : numel(coeff);
             self = element_coefficient_similar_to_dof_at_axial_location(self, n_d, n_r, coeff, i_j, i_h, l, i_d);
        end
                
        function self = element_coefficient_similar_to_dof_at_axial_location(self, n_d, n_r, coeff, i_j, i_h, l, i_d) % note the order change
            if nargin == 6
                l =  0; % equal to the other joint/dof at base
            end
            if nargin == 7
                i_d = 1; % results in all mesh nodes having the same equal2 property
            end
            % [i_j, i_d, i_h, 0, l, 0, coeff]
            self.equal2_val{n_r}(n_d,:) = [ones(numel(n_d),1).*i_j, ones(numel(n_d),1).*i_d, ones(numel(n_d),1).*i_h, ones(numel(n_d),1).*0, ones(numel(n_d),1).*l, ones(numel(n_d),1).*0, ones(numel(n_d),1).*coeff];
            self.pipe.equal2{n_r}(n_d,:) = [ones(numel(n_d),1).*i_j, ones(numel(n_d),1).*i_d, ones(numel(n_d),1).*i_h, ones(numel(n_d),1).*0, ones(numel(n_d),1).*l, ones(numel(n_d),1).*0, ones(numel(n_d),1).*coeff];
            self.i_S = self.i_S + 1;
        end
        
        function self = coefficient_similar_to_dof_at_tip(self, n_r, coeff, i_j, i_h, i_d) % note the order change
            if nargin == 5
                i_d = 1; % results in all mesh nodes having the same equal2 property
            end
            n_d = 1 : numel(coeff);
            self = element_coefficient_similar_to_dof_at_tip(self, n_d, n_r, coeff, i_j, i_h, i_d);
        end
        
        function self = element_coefficient_similar_to_dof_at_tip(self, n_d, n_r, coeff, i_j, i_h, i_d) % note the order change
            l = nan; % equal to the other joint/dof at tip
            if nargin == 6
                i_d = 1; % results in all mesh nodes having the same equal2 property
            end
            % [i_j, i_d, i_h, 0, l, 0, coeff]
            self.equal2_val{n_r}(n_d,:) = [ones(numel(n_d),1).*i_j, ones(numel(n_d),1).*i_d, ones(numel(n_d),1).*i_h, ones(numel(n_d),1).*0, ones(numel(n_d),1).*l, ones(numel(n_d),1).*0, ones(numel(n_d),1).*coeff];
            self.pipe.equal2{n_r}(n_d,:) = [ones(numel(n_d),1).*i_j, ones(numel(n_d),1).*i_d, ones(numel(n_d),1).*i_h, ones(numel(n_d),1).*0, ones(numel(n_d),1).*l, ones(numel(n_d),1).*0, ones(numel(n_d),1).*coeff];
            self.i_S = self.i_S + 1;
        end
        
        function self = coefficient_similar_to_dof_derivative_at_axial_location(self, n_r, n_p, coeff, i_j, i_h, l, i_d) % note the order change
            if nargin == 6
                l =  0; % equal to the other joint/dof at base
            end
            if nargin == 7
                i_d = 1; % results in all mesh nodes having the same equal2 property
            end
            n_d = 1 : numel(coeff);
            self = element_coefficient_similar_to_dof_derivative_at_axial_location(self, n_d, n_r, n_p, coeff, i_j, i_h, l, i_d);
        end
        
        function self = element_coefficient_similar_to_dof_derivative_at_axial_location(self, n_d, n_r, n_p, coeff, i_j, i_h, l, i_d) % note the order change
            if nargin == 7
                l =  0; % equal to the other joint/dof at base
            end
            if nargin == 8
                i_d = 1; % results in all mesh nodes having the same equal2 property
            end
            % [i_j, i_d, i_h, 0, l, n_p, coeff]
            self.equal2_val{n_r}(n_d,:) = [ones(numel(n_d),1).*i_j, ones(numel(n_d),1).*i_d, ones(numel(n_d),1).*i_h, ones(numel(n_d),1).*0, ones(numel(n_d),1).*l, ones(numel(n_d),1).*n_p, ones(numel(n_d),1).*coeff];
            self.pipe.equal2{n_r}(n_d,:) = [ones(numel(n_d),1).*i_j, ones(numel(n_d),1).*i_d, ones(numel(n_d),1).*i_h, ones(numel(n_d),1).*0, ones(numel(n_d),1).*l, ones(numel(n_d),1).*n_p, ones(numel(n_d),1).*coeff];
            self.i_S = self.i_S + 1;
        end
        
        function self = coefficient_similar_to_dof_derivative_at_tip(self, n_r, n_p, coeff, i_j, i_h, i_d) % note the order change
            if nargin == 6
                i_d = 1; % results in all mesh nodes having the same equal2 property
            end
            n_d = 1 : numel(coeff);
            self = element_coefficient_similar_to_dof_derivative_at_tip(self, n_d, n_r, n_p, coeff, i_j, i_h, i_d);
        end
        
        function self = element_coefficient_similar_to_dof_derivative_at_tip(self, n_d, n_r, n_p, coeff, i_j, i_h, i_d) % note the order change
            l = nan ; % equal to the other joint/dof at tip
            if nargin == 7
                i_d = 1; % results in all mesh nodes having the same equal2 property
            end
            % [i_j, i_d, i_h, 0, l, n_p, coeff]
            self.equal2_val{n_r}(n_d,:) = [ones(numel(n_d),1).*i_j, ones(numel(n_d),1).*i_d, ones(numel(n_d),1).*i_h, ones(numel(n_d),1).*0, ones(numel(n_d),1).*l, ones(numel(n_d),1).*n_p, ones(numel(n_d),1).*coeff];
            self.pipe.equal2{n_r}(n_d,:) = [ones(numel(n_d),1).*i_j, ones(numel(n_d),1).*i_d, ones(numel(n_d),1).*i_h, ones(numel(n_d),1).*0, ones(numel(n_d),1).*l, ones(numel(n_d),1).*n_p, ones(numel(n_d),1).*coeff];
            self.i_S = self.i_S + 1;
        end
        
        function self = set_rom_coefficient(self, n_r, value)
            n_d = 1 : numel(value);
            self = element_set_rom_coefficient(self, n_d, n_r, value);
        end
        
        function self = element_set_rom_coefficient(self, n_d, n_r, value)
            % [nan, 0, 0, 0, value, 0, 1]
            self.equal2_val{n_r}(n_d,:) = [ones(numel(n_d),1).*nan, ones(numel(n_d),1).*0, ones(numel(n_d),1).*0, ones(numel(n_d),1).*0, ones(numel(n_d),1).*value, ones(numel(n_d),1).*0, ones(numel(n_d),1).*1]; % ground fixed
            self.pipe.equal2{n_r}(n_d,:) = [ones(numel(n_d),1).*nan, ones(numel(n_d),1).*0, ones(numel(n_d),1).*0, ones(numel(n_d),1).*0, ones(numel(n_d),1).*value, ones(numel(n_d),1).*0, ones(numel(n_d),1).*1];
            self.i_S = self.i_S + 1;
        end
        
        function self = base_value(self, value) % changes spring too
            n_d = 1 : numel(value);
            self = element_base_value(self, n_d, value);
        end
        
        function self = element_base_value(self, n_d, value) % changes spring too
            % [nan, 0, 0, 0, value, 0, 1]
            self.equal2_val{1}(n_d,:) = [ones(numel(n_d),1).*nan, ones(numel(n_d),1).*0, ones(numel(n_d),1).*0, ones(numel(n_d),1).*0, ones(numel(n_d),1).*value, ones(numel(n_d),1).*0, ones(numel(n_d),1).*1]; % ground fixed
            self.pipe.equal2{1}(n_d,:) = [ones(numel(n_d),1).*nan, ones(numel(n_d),1).*0, ones(numel(n_d),1).*0, ones(numel(n_d),1).*0, ones(numel(n_d),1).*value, ones(numel(n_d),1).*0, ones(numel(n_d),1).*1];
            % self.pipe.spring.equal2(:,:,1) = [nan, 0, 0, 0, value, 0, 1];
            self.i_S = self.i_S + 1;
        end        
        
        function self = base_value_at_axial_location(self, value, length) % changes spring too
            n_d = 1 : numel(value);
            self = element_base_value_at_axial_location(self, n_d, value, length);
        end
        
        function self = element_base_value_at_axial_location(self, n_d, value, length) % changes spring too
            % [nan, 0, 0, 0, value, 0, 1]
            self.equal2_val{1}(n_d,:) = [ones(numel(n_d),1).*nan, ones(numel(n_d),1).*0, ones(numel(n_d),1).*0, ones(numel(n_d),1).*0, ones(numel(n_d),1).*value, ones(numel(n_d),1).*0, ones(numel(n_d),1).*1]; % ground fixed
            self.pipe.equal2{1}(n_d,:) = [ones(numel(n_d),1).*nan, ones(numel(n_d),1).*0, ones(numel(n_d),1).*0, ones(numel(n_d),1).*0, ones(numel(n_d),1).*value, ones(numel(n_d),1).*0, ones(numel(n_d),1).*1];
            % self.pipe.spring.equal2(:,:,1) = [nan, 0, 0, 0, value, 0, 1];
            self.rom_offset_val(2,:) = -length;
            self.pipe.rom_offset(2,:) = -length;
            self.i_S = self.i_S + 1;
        end      
        
        function self = base_director(self, director) % changes spring too
            n_d = 1 : numel(director);
            self = element_base_director(self, n_d, director);
        end
        
        function self = element_base_director(self, n_d, director) % changes spring too
            % [nan, 0, 0, 0, director, 0, 1]
            self.equal2_val{2}(n_d,:) = [ones(numel(n_d),1).*nan, ones(numel(n_d),1).*0, ones(numel(n_d),1).*0, ones(numel(n_d),1).*0, ones(numel(n_d),1).*director, ones(numel(n_d),1).*0, ones(numel(n_d),1).*1];
            self.pipe.equal2{2}(n_d,:) = [ones(numel(n_d),1).*nan, ones(numel(n_d),1).*0, ones(numel(n_d),1).*0, ones(numel(n_d),1).*0, ones(numel(n_d),1).*director, ones(numel(n_d),1).*0, ones(numel(n_d),1).*1];
            % self.pipe.spring.equal2(:,:,2) = [nan, 0, 0, 0, director, 0, 1];
            self.i_S = self.i_S + 1;
        end
        
        function self = base_director_at_axial_location(self, director, length) % changes spring too
            n_d = 1 : numel(director);
            self = element_base_director_at_axial_location(self, n_d, director, length);
        end
        
        function self = element_base_director_at_axial_location(self, n_d, director, length) % changes spring too
            % [nan, 0, 0, 0, director, 0, 1]
            self.equal2_val{2}(n_d,:) = [ones(numel(n_d),1).*nan, ones(numel(n_d),1).*0, ones(numel(n_d),1).*0, ones(numel(n_d),1).*0, ones(numel(n_d),1).*director, ones(numel(n_d),1).*0, ones(numel(n_d),1).*1];
            self.pipe.equal2{2}(n_d,:) = [ones(numel(n_d),1).*nan, ones(numel(n_d),1).*0, ones(numel(n_d),1).*0, ones(numel(n_d),1).*0, ones(numel(n_d),1).*director, ones(numel(n_d),1).*0, ones(numel(n_d),1).*1];
            % self.pipe.spring.equal2(:,:,2) = [nan, 0, 0, 0, director, 0, 1];
            self.rom_offset_val(2,:) = -length;
            self.pipe.rom_offset(2,:) = -length;
            self.i_S = self.i_S + 1;
        end
        
        function self = axial_offset(self, offset) % doesn't changes spring_offset
            self.rom_offset_val(1,:) = offset;
            self.pipe.rom_offset(1,:) = offset;
            % self.pipe.spring.rom_offset(1,:) = offset;
            self.i_S = self.i_S + 1;
        end
        
        function self = initial_value(self, init)
            self.init_val = init;
            self.pipe.init = init;
            self.i_S = self.i_S + 1;
        end
        
        function self = initial_value_from_kinematic_constraint(self)
            self.init_val = nan;
            self.pipe.init = nan;
            self.i_S = self.i_S + 1;
        end
        
        function self = initial_value_axial_locations(self,init_s)
            self.init_s_val = init_s;
            self.pipe.init_s = init_s;
            self.i_S = self.i_S + 1;
        end
        
        function spring = parallel_spring(self)
            self.the_spring = spring_builder(self);
            spring = self.the_spring;
            self.i_S = self.i_S + 1;
        end
        
        function self = parallel_elements_active_direction(self,dir)
            self.active_direction = dir;
            self.pipe.dir = dir;
            self.i_S = self.i_S + 1;
        end
        
        function damper = parallel_damper(self)
            self.the_damping = damper_builder(self);
            damper = self.the_damping;
            self.i_S = self.i_S + 1;
        end
        
        function self = direct_input(self, input_type, input)
            switch input_type
                case 'force'
                    self.input_val = input;
                    self.pipe.input = input;
                case 'trajectory'
                    self.control_val = input;
                    self.pipe.control = input;
                    self.fixed_val = 1; % constraint: with Lagrange multiplier
                    self.pipe.fixed = 1;
                otherwise
                    self.input_val = input;
                    self.pipe.input = input;
            end
            self.i_S = self.i_S + 1;
        end
        
        function self = unknown_direct_input(self)
            self = self.direct_input('force', inf);
        end
        
        function self = direct_input_at_coefficient(self, n_r, input_type, input)
            switch input_type
                case 'force'
                    self.input_val(:,n_r) = input;
                    self.pipe.input(:,n_r) = input;
                case 'trajectory'
                    self.control_val(:,n_r) = input;
                    self.pipe.control(:,n_r) = input;
                    self.fixed_val(:,n_r) = 1; % constraint: with Lagrange multiplier
                    self.pipe.fixed(:,n_r) = 1;
                otherwise
                    self.input_val(:,n_r) = input;
                    self.pipe.input(:,n_r) = input;
            end
            self.i_S = self.i_S + 1;
        end
        
        function self = unknown_direct_input_at_coefficient(self, n_r)
            self = self.direct_input_at_coefficient(n_r, 'force', inf);
        end
        
        function self = desired_state_trajectory(self, input)
            self.control_val = input;
            self.pipe.control = input;
            self.fixed_val = inf; % desired/known: no Lagrange multiplier
            self.pipe.fixed = inf;
            self.i_S = self.i_S + 1;
        end
        
        function self = desired_state_trajectory_at_coefficient(self, n_r, input)
            self.control_val(:,n_r) = input;
            self.pipe.control(:,n_r) = input;
            self.fixed_val(:,n_r) = inf; % desired/known: no Lagrange multiplier
            self.pipe.fixed(:,n_r) = inf;
            self.i_S = self.i_S + 1;
        end
        
        function self = state_pid_controller_gains(self, p_vec, i_vec, d_vec) % pid_vec=[P,I,D]
            self.pipe.pid.p = p_vec;
            self.pipe.pid.i = i_vec;
            self.pipe.pid.d = d_vec;
            self.pid_val = self.pipe.pid;
            self.i_S = self.i_S + 1;
        end
        
        function self = state_pid_controller_gains_at_coefficient(self, n_r, p_vec, i_vec, d_vec) % pid_vec=[P,I,D]
            self.pipe.pid.p(:,n_r) = p_vec;
            self.pipe.pid.i(:,n_r) = i_vec;
            self.pipe.pid.d(:,n_r) = d_vec;
            self.pid_val = self.pipe.pid;
            self.i_S = self.i_S + 1;
        end
                
        function self = rom_order(self, order)
            self.rom_order_val = order;
            i = numel(self.source.source.pipe.rom.order);
            if i < self.q_index
                self.source.source.pipe.rom.order(:, i+1 : self.q_index) = nan;
            end
            self.source.source.pipe.rom.order(self.q_index) = order;
            self.i_S = self.i_S + 1;
        end
        
        function self = not_rom(self)
            self.rom_order_val = 0;
            self.source.source.pipe.rom.order(self.q_index) = 0;
            self.i_S = self.i_S + 1;
        end
        
        function self = initial_value_fit_type(self, type, knots) % 'polynomial', 'spline_piecewise', 'spline_logistic_func'
            if nargin < 3
                knots = [];
            end
            switch type
                case 'polynomial'
                    type = 1 * ones(numel(knots(:,1)),1);
                case 'spline_piecewise'
                    type = 2 * ones(numel(knots(:,1)),1);
                case 'spline_logistic_func'
                    type = 3 * ones(numel(knots(:,1)),1);
            end
            self.fit_type_val = [type, knots];
            self.pipe.fit_type = [type, knots];
            self.i_S = self.i_S + 1;
        end
        
        function self = spline_continuity_order(self, value)
            self.spc_order = value;
            self.pipe.spc_order = value;
            self.i_S = self.i_S + 1;
        end
        
        function varargout = subsref (self, S)
            try
                [varargout{1:nargout}] = builtin('subsref', self, S); % call set of inputs, i.e. the full DSL text
                if numel( S ) == 2 * ( self.i_S - 1 ) ; self.i_S = 1 ; end % if the last input argument is reched, reset i_S counter in case we add more elements later!
            catch e
                if ~ strcmp (e.identifier, 'MATLAB:noSuchMethodOrField')
                    rethrow(e)
                end
                % e.message
                self.source.source.pipe.dof(self.q_index) = self.pipe; % to be copied in joint struct, not tr
                self.source.i_S = 1 ; % reset i_S of the source object to start executing from 1st line of DSL input % reset i_S of the source object
                [varargout{1:nargout}] = builtin('subsref', self.source, S(2*self.i_S-1:end)); % pass the unexecuted lines to the source object
            end
        end
        
    end
end
