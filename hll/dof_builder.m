classdef dof_builder < handle
    
    properties (GetAccess = public, SetAccess=private)
        source;
        template;
        q_index ; % tr dof numerator
        
        equal2_val; % [i_joint(joint), i_copy(mesh), i_dofAxis(DOF in joint), i_coeff(rom coeff), curve_length(along rom), i_p(derivative order), c(coeff)]
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
        
        function self = equal2(self, equal2, n_coeff) % [j_count, n_copy, nj_dof, i_dof_mult, val_or_l_rom diff_order coeff] x i_dof_mult -or- [i_joint, i_copy, i_dofAxis, i_coeff, curve_length, i_p, c] x n_coeff
            if nargin == 2
                n_coeff = 1 ;
            end
            self.equal2_val{n_coeff} = equal2;
            self.pipe.equal2{n_coeff} = equal2;
            self.i_S = self.i_S + 1;
        end
        
        function self = similar_to_dof(self, coeff, i_joint, i_dofAxis, i_copy) % note order change
            if nargin == 4
                i_copy = 1; % results in all mesh nodes having the same equal2 property
            end
            n_copy = 1 : numel(coeff);
            self = element_similar_to_dof(self, n_copy, coeff, ones(numel(n_copy),1).*i_joint, ones(numel(n_copy),1).*i_dofAxis, ones(numel(n_copy),1).*i_copy);
        end
        
        function self = element_similar_to_dof(self, n_copy, coeff, i_joint, i_dofAxis, i_copy) % note order change
            if nargin == 5
                i_copy = 1; % results in all mesh nodes having the same equal2 property
            end
            % [i_joint, i_copy, i_dofAxis, i_coeff, 0, 0, coeff]
            self.equal2_val{1}(n_copy,:) = [ones(numel(n_copy),1).*i_joint, ones(numel(n_copy),1).*i_copy, ones(numel(n_copy),1).*i_dofAxis, ones(numel(n_copy),1).*nan, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*coeff];
            self.pipe.equal2{1}(n_copy,:) = [ones(numel(n_copy),1).*i_joint, ones(numel(n_copy),1).*i_copy, ones(numel(n_copy),1).*i_dofAxis, ones(numel(n_copy),1).*nan, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*coeff];
            self.i_S = self.i_S + 1;
        end
        
        function self = coefficient_similar_to_dof_order(self, n_coeff, coeff, i_joint, i_dofAxis, i_coeff, i_copy) % note the order change
            if nargin == 5
                i_coeff = nan; % equal to the same coeff in the other joint/dof
            end
            if nargin == 6
                i_copy =  1; % results in all mesh nodes having the same equal2 property
            end
            n_copy = 1 : numel(coeff);
            self = element_coefficient_similar_to_dof_order(self, n_copy, n_coeff, coeff, i_joint, i_dofAxis, i_coeff, i_copy);
        end
        
        function self = element_coefficient_similar_to_dof_order(self, n_copy, n_coeff, coeff, i_joint, i_dofAxis, i_coeff, i_copy) % note the order change
            if nargin == 6
                i_coeff = nan; % equal to the same coeff in the other joint/dof
            end
            if nargin == 7
                i_copy =  1; % results in all mesh nodes having the same equal2 property
            end
            % [i_joint, i_copy, i_dofAxis, i_coeff, 0, 0, coeff]
            self.equal2_val{n_coeff}(n_copy,:) = [ones(numel(n_copy),1).*i_joint, ones(numel(n_copy),1).*i_copy, ones(numel(n_copy),1).*i_dofAxis, ones(numel(n_copy),1).*i_coeff, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*coeff];
            self.pipe.equal2{n_coeff}(n_copy,:) = [ones(numel(n_copy),1).*i_joint, ones(numel(n_copy),1).*i_copy, ones(numel(n_copy),1).*i_dofAxis, ones(numel(n_copy),1).*i_coeff, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*coeff];
            self.i_S = self.i_S + 1;
        end
        
        function self = coefficient_similar_to_dof_at_axial_location(self, n_coeff, coeff, i_joint, i_dofAxis, curve_length, i_copy) % note the order change
            if nargin == 5
                curve_length =  0; % equal to the other joint/dof at base
            end
            if nargin == 6
                i_copy = 1; % results in all mesh nodes having the same equal2 property
            end
            n_copy = 1 : numel(coeff);
             self = element_coefficient_similar_to_dof_at_axial_location(self, n_copy, n_coeff, coeff, i_joint, i_dofAxis, curve_length, i_copy);
        end
                
        function self = element_coefficient_similar_to_dof_at_axial_location(self, n_copy, n_coeff, coeff, i_joint, i_dofAxis, curve_length, i_copy) % note the order change
            if nargin == 6
                curve_length =  0; % equal to the other joint/dof at base
            end
            if nargin == 7
                i_copy = 1; % results in all mesh nodes having the same equal2 property
            end
            % [i_joint, i_copy, i_dofAxis, 0, curve_length, 0, coeff]
            self.equal2_val{n_coeff}(n_copy,:) = [ones(numel(n_copy),1).*i_joint, ones(numel(n_copy),1).*i_copy, ones(numel(n_copy),1).*i_dofAxis, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*curve_length, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*coeff];
            self.pipe.equal2{n_coeff}(n_copy,:) = [ones(numel(n_copy),1).*i_joint, ones(numel(n_copy),1).*i_copy, ones(numel(n_copy),1).*i_dofAxis, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*curve_length, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*coeff];
            self.i_S = self.i_S + 1;
        end
        
        function self = coefficient_similar_to_dof_at_tip(self, n_coeff, coeff, i_joint, i_dofAxis, i_copy) % note the order change
            if nargin == 5
                i_copy = 1; % results in all mesh nodes having the same equal2 property
            end
            n_copy = 1 : numel(coeff);
            self = element_coefficient_similar_to_dof_at_tip(self, n_copy, n_coeff, coeff, i_joint, i_dofAxis, i_copy);
        end
        
        function self = element_coefficient_similar_to_dof_at_tip(self, n_copy, n_coeff, coeff, i_joint, i_dofAxis, i_copy) % note the order change
            curve_length = nan; % equal to the other joint/dof at tip
            if nargin == 6
                i_copy = 1; % results in all mesh nodes having the same equal2 property
            end
            % [i_joint, i_copy, i_dofAxis, 0, curve_length, 0, coeff]
            self.equal2_val{n_coeff}(n_copy,:) = [ones(numel(n_copy),1).*i_joint, ones(numel(n_copy),1).*i_copy, ones(numel(n_copy),1).*i_dofAxis, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*curve_length, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*coeff];
            self.pipe.equal2{n_coeff}(n_copy,:) = [ones(numel(n_copy),1).*i_joint, ones(numel(n_copy),1).*i_copy, ones(numel(n_copy),1).*i_dofAxis, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*curve_length, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*coeff];
            self.i_S = self.i_S + 1;
        end
        
        function self = coefficient_similar_to_dof_derivative_at_axial_location(self, n_coeff, n_diffOrder, coeff, i_joint, i_dofAxis, curve_length, i_copy) % note the order change
            if nargin == 6
                curve_length =  0; % equal to the other joint/dof at base
            end
            if nargin == 7
                i_copy = 1; % results in all mesh nodes having the same equal2 property
            end
            n_copy = 1 : numel(coeff);
            self = element_coefficient_similar_to_dof_derivative_at_axial_location(self, n_copy, n_coeff, n_diffOrder, coeff, i_joint, i_dofAxis, curve_length, i_copy);
        end
        
        function self = element_coefficient_similar_to_dof_derivative_at_axial_location(self, n_copy, n_coeff, n_diffOrder, coeff, i_joint, i_dofAxis, curve_length, i_copy) % note the order change
            if nargin == 7
                curve_length =  0; % equal to the other joint/dof at base
            end
            if nargin == 8
                i_copy = 1; % results in all mesh nodes having the same equal2 property
            end
            % [i_joint, i_copy, i_dofAxis, 0, curve_length, n_diffOrder, coeff]
            self.equal2_val{n_coeff}(n_copy,:) = [ones(numel(n_copy),1).*i_joint, ones(numel(n_copy),1).*i_copy, ones(numel(n_copy),1).*i_dofAxis, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*curve_length, ones(numel(n_copy),1).*n_diffOrder, ones(numel(n_copy),1).*coeff];
            self.pipe.equal2{n_coeff}(n_copy,:) = [ones(numel(n_copy),1).*i_joint, ones(numel(n_copy),1).*i_copy, ones(numel(n_copy),1).*i_dofAxis, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*curve_length, ones(numel(n_copy),1).*n_diffOrder, ones(numel(n_copy),1).*coeff];
            self.i_S = self.i_S + 1;
        end
        
        function self = coefficient_similar_to_dof_derivative_at_tip(self, n_coeff, n_diffOrder, coeff, i_joint, i_dofAxis, i_copy) % note the order change
            if nargin == 6
                i_copy = 1; % results in all mesh nodes having the same equal2 property
            end
            n_copy = 1 : numel(coeff);
            self = element_coefficient_similar_to_dof_derivative_at_tip(self, n_copy, n_coeff, n_diffOrder, coeff, i_joint, i_dofAxis, i_copy);
        end
        
        function self = element_coefficient_similar_to_dof_derivative_at_tip(self, n_copy, n_coeff, n_diffOrder, coeff, i_joint, i_dofAxis, i_copy) % note the order change
            curve_length = nan ; % equal to the other joint/dof at tip
            if nargin == 7
                i_copy = 1; % results in all mesh nodes having the same equal2 property
            end
            % [i_joint, i_copy, i_dofAxis, 0, curve_length, n_diffOrder, coeff]
            self.equal2_val{n_coeff}(n_copy,:) = [ones(numel(n_copy),1).*i_joint, ones(numel(n_copy),1).*i_copy, ones(numel(n_copy),1).*i_dofAxis, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*curve_length, ones(numel(n_copy),1).*n_diffOrder, ones(numel(n_copy),1).*coeff];
            self.pipe.equal2{n_coeff}(n_copy,:) = [ones(numel(n_copy),1).*i_joint, ones(numel(n_copy),1).*i_copy, ones(numel(n_copy),1).*i_dofAxis, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*curve_length, ones(numel(n_copy),1).*n_diffOrder, ones(numel(n_copy),1).*coeff];
            self.i_S = self.i_S + 1;
        end
        
        function self = set_rom_coefficient(self, n_coeff, value)
            n_copy = 1 : numel(value);
            self = element_set_rom_coefficient(self, n_copy, n_coeff, value);
        end
        
        function self = element_set_rom_coefficient(self, n_copy, n_coeff, value)
            % [nan, 0, 0, 0, value, 0, 1]
            self.equal2_val{n_coeff}(n_copy,:) = [ones(numel(n_copy),1).*nan, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*value, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*1]; % ground fixed
            self.pipe.equal2{n_coeff}(n_copy,:) = [ones(numel(n_copy),1).*nan, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*value, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*1];
            self.i_S = self.i_S + 1;
        end
        
        function self = base_value(self, value) % changes spring too
            n_copy = 1 : numel(value);
            self = element_base_value(self, n_copy, value);
        end
        
        function self = element_base_value(self, n_copy, value) % changes spring too
            % [nan, 0, 0, 0, value, 0, 1]
            self.equal2_val{1}(n_copy,:) = [ones(numel(n_copy),1).*nan, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*value, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*1]; % ground fixed
            self.pipe.equal2{1}(n_copy,:) = [ones(numel(n_copy),1).*nan, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*value, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*1];
            % self.pipe.spring.equal2(:,:,1) = [nan, 0, 0, 0, value, 0, 1];
            self.i_S = self.i_S + 1;
        end        
        
        function self = base_value_at_axial_location(self, value, curve_length) % changes spring too
            n_copy = 1 : numel(value);
            self = element_base_value_at_axial_location(self, n_copy, value, curve_length);
        end
        
        function self = element_base_value_at_axial_location(self, n_copy, value, curve_length) % changes spring too
            % [nan, 0, 0, 0, value, 0, 1]
            self.equal2_val{1}(n_copy,:) = [ones(numel(n_copy),1).*nan, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*value, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*1]; % ground fixed
            self.pipe.equal2{1}(n_copy,:) = [ones(numel(n_copy),1).*nan, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*value, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*1];
            % self.pipe.spring.equal2(:,:,1) = [nan, 0, 0, 0, value, 0, 1];
            self.rom_offset_val(2,:) = -curve_length;
            self.pipe.rom_offset(2,:) = -curve_length;
            self.i_S = self.i_S + 1;
        end      
        
        function self = base_director(self, director) % changes spring too
            n_copy = 1 : numel(director);
            self = element_base_director(self, n_copy, director);
        end
        
        function self = element_base_director(self, n_copy, director) % changes spring too
            % [nan, 0, 0, 0, director, 0, 1]
            self.equal2_val{2}(n_copy,:) = [ones(numel(n_copy),1).*nan, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*director, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*1];
            self.pipe.equal2{2}(n_copy,:) = [ones(numel(n_copy),1).*nan, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*director, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*1];
            % self.pipe.spring.equal2(:,:,2) = [nan, 0, 0, 0, director, 0, 1];
            self.i_S = self.i_S + 1;
        end
        
        function self = base_director_at_axial_location(self, director, curve_length) % changes spring too
            n_copy = 1 : numel(director);
            self = element_base_director_at_axial_location(self, n_copy, director, curve_length);
        end
        
        function self = element_base_director_at_axial_location(self, n_copy, director, curve_length) % changes spring too
            % [nan, 0, 0, 0, director, 0, 1]
            self.equal2_val{2}(n_copy,:) = [ones(numel(n_copy),1).*nan, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*director, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*1];
            self.pipe.equal2{2}(n_copy,:) = [ones(numel(n_copy),1).*nan, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*director, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*1];
            % self.pipe.spring.equal2(:,:,2) = [nan, 0, 0, 0, director, 0, 1];
            self.rom_offset_val(2,:) = -curve_length;
            self.pipe.rom_offset(2,:) = -curve_length;
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
        
        function self = direct_input_at_coefficient(self, n_coeff, input_type, input)
            switch input_type
                case 'force'
                    self.input_val(:,n_coeff) = input;
                    self.pipe.input(:,n_coeff) = input;
                case 'trajectory'
                    self.control_val(:,n_coeff) = input;
                    self.pipe.control(:,n_coeff) = input;
                    self.fixed_val(:,n_coeff) = 1; % constraint: with Lagrange multiplier
                    self.pipe.fixed(:,n_coeff) = 1;
                otherwise
                    self.input_val(:,n_coeff) = input;
                    self.pipe.input(:,n_coeff) = input;
            end
            self.i_S = self.i_S + 1;
        end
        
        function self = unknown_direct_input_at_coefficient(self, n_coeff)
            self = self.direct_input_at_coefficient(n_coeff, 'force', inf);
        end
        
        function self = desired_state_trajectory(self, input)
            self.control_val = input;
            self.pipe.control = input;
            self.fixed_val = inf; % desired/known: no Lagrange multiplier
            self.pipe.fixed = inf;
            self.i_S = self.i_S + 1;
        end
        
        function self = desired_state_trajectory_at_coefficient(self, n_coeff, input)
            self.control_val(:,n_coeff) = input;
            self.pipe.control(:,n_coeff) = input;
            self.fixed_val(:,n_coeff) = inf; % desired/known: no Lagrange multiplier
            self.pipe.fixed(:,n_coeff) = inf;
            self.i_S = self.i_S + 1;
        end
        
        function self = state_pid_controller_gains(self, p_vec, i_vec, d_vec) % pid_vec=[P,I,D]
            self.pipe.pid.p = p_vec;
            self.pipe.pid.i = i_vec;
            self.pipe.pid.d = d_vec;
            self.pid_val = self.pipe.pid;
            self.i_S = self.i_S + 1;
        end
        
        function self = state_pid_controller_gains_at_coefficient(self, n_coeff, p_vec, i_vec, d_vec) % pid_vec=[P,I,D]
            self.pipe.pid.p(:,n_coeff) = p_vec;
            self.pipe.pid.i(:,n_coeff) = i_vec;
            self.pipe.pid.d(:,n_coeff) = d_vec;
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
