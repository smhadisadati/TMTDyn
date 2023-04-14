classdef dof_builder < handle
    
    properties (GetAccess = public, SetAccess=private)
        source;
        template;
        q_index ;
        
        equal2_val; % [i_j(joint), i_d(mesh), i_h(DOF in joint), i_r(rom coeff), l(length along rom), i_p(derivative order), c(coeff)]
        init_val = sym([]);
        init_s_val = sym([]);
        the_spring = sym([]);
        active_direction = sym([]);
        the_damping = sym([]);
        input_val = sym([]);
        control_val = sym([]);
        rom_order_val = sym([]);
        init_type_val = sym([]);
        rom_offset_val = sym([]);
        fit_type_val;
    end
    
    properties (GetAccess = public, SetAccess=public)
        pipe;
        i_S = 1;
    end
    
    methods
        function self = dof_builder(source, q_index)
            self.source = source;
            self.template = source.template;
            self.pipe = source.template.joint.dof;
            self.q_index = q_index;
        end
        
        function self = equal2(self, equal2, n_r) % [j_count, n_mesh, nj_dof, i_dof_mult, val_or_l_rom diff_order coeff] x i_dof_mult -or- [i_j, i_d, i_h, i_r, l, i_p, c] x n_r
            if nargin == 2
                n_r = 1 ;
            end
            self.equal2_val{n_r} = equal2;
            self.pipe.equal2{n_r} = equal2;
            self.i_S = self.i_S + 1;
        end
        
        function self = similar_to_dof(self, coeff, i_j, i_h, i_d) % note order change
            if nargin == 4
                i_d = ones(numel(coeff),1); % results in all mesh nodes having the same equal2 property
            end
            n_d = 1 : numel(coeff);
            self = element_similar_to_dof(self, n_d, coeff, i_j, i_h, i_d);
        end
        
        function self = element_similar_to_dof(self, n_d, coeff, i_j, i_h, i_d) % note order change
            i_r = nan * ones(numel(n_d),1); % all coeffs will be equal to the same coeff in the other joint/dof
            if nargin == 5
                i_d = ones(numel(n_d),1); % results in all mesh nodes having the same equal2 property
            end
            % [i_j, i_d, i_h, i_r, 0, 0, coeff]
            self.equal2_val{1}(n_d,:) = [i_j, i_d, i_h, i_r, zeros(numel(n_d),2), coeff];
            self.pipe.equal2{1}(n_d,:) = [i_j, i_d, i_h, i_r, zeros(numel(n_d),2), coeff];
            self.i_S = self.i_S + 1;
        end
        
        function self = coefficient_similar_to_dof_order(self, n_r, coeff, i_j, i_h, i_r, i_d) % note the order change
            if nargin == 5
                i_r = nan * ones(numel(coeff),1); % equal to the same coeff in the other joint/dof
            end
            if nargin == 6
                i_d =  ones(numel(coeff),1); % results in all mesh nodes having the same equal2 property
            end
            n_d = 1 : numel(coeff);
            self = element_coefficient_similar_to_dof_order(self, n_d, n_r, coeff, i_j, i_h, i_r, i_d);
        end
        
        function self = element_coefficient_similar_to_dof_order(self, n_d, n_r, coeff, i_j, i_h, i_r, i_d) % note the order change
            if nargin == 6
                i_r = nan * ones(numel(coeff),1); % equal to the same coeff in the other joint/dof
            end
            if nargin == 7
                i_d =  ones(numel(coeff),1); % results in all mesh nodes having the same equal2 property
            end
            % [i_j, i_d, i_h, i_r, 0, 0, coeff]
            self.equal2_val{n_r}(n_d,:) = [i_j, i_d, i_h, i_r, zeros(numel(coeff),2), coeff];
            self.pipe.equal2{n_r}(n_d,:) = [i_j, i_d, i_h, i_r, zeros(numel(coeff),2), coeff];
            self.i_S = self.i_S + 1;
        end
        
        function self = coefficient_similar_to_dof_at_axial_location(self, n_r, coeff, i_j, i_h, l, i_d) % note the order change
            if nargin == 5
                l =  zeros(numel(coeff),1); % equal to the other joint/dof at base
            end
            if nargin == 6
                i_d = ones(numel(coeff),1); % results in all mesh nodes having the same equal2 property
            end
            n_d = 1 : numel(coeff);
             self = element_coefficient_similar_to_dof_at_axial_location(self, n_d, n_r, coeff, i_j, i_h, l, i_d);
        end
                
        function self = element_coefficient_similar_to_dof_at_axial_location(self, n_d, n_r, coeff, i_j, i_h, l, i_d) % note the order change
            if nargin == 6
                l =  zeros(numel(coeff),1); % equal to the other joint/dof at base
            end
            if nargin == 7
                i_d = ones(numel(coeff),1); % results in all mesh nodes having the same equal2 property
            end
            % [i_j, i_d, i_h, 0, l, 0, coeff]
            self.equal2_val{n_r}(n_d,:) = [i_j, i_d, i_h, zeros(numel(coeff),1), l, zeros(numel(coeff),1), coeff];
            self.pipe.equal2{n_r}(n_d,:) = [i_j, i_d, i_h, zeros(numel(coeff),1), l, zeros(numel(coeff),1), coeff];
            self.i_S = self.i_S + 1;
        end
        
        function self = coefficient_similar_to_dof_at_tip(self, n_r, coeff, i_j, i_h, i_d) % note the order change
            if nargin == 5
                i_d = ones(numel(coeff),1); % results in all mesh nodes having the same equal2 property
            end
            n_d = 1 : numel(coeff);
            self = element_coefficient_similar_to_dof_at_tip(self, n_d, n_r, coeff, i_j, i_h, i_d);
        end
        
        function self = element_coefficient_similar_to_dof_at_tip(self, n_d, n_r, coeff, i_j, i_h, i_d) % note the order change
            l = nan * ones(numel(coeff),1); % equal to the other joint/dof at tip
            if nargin == 6
                i_d = ones(numel(coeff),1); % results in all mesh nodes having the same equal2 property
            end
            % [i_j, i_d, i_h, 0, l, 0, coeff]
            self.equal2_val{n_r}(n_d,:) = [i_j, i_d, i_h, zeros(numel(coeff),1), l, zeros(numel(coeff),1), coeff];
            self.pipe.equal2{n_r}(n_d,:) = [i_j, i_d, i_h, zeros(numel(coeff),1), l, zeros(numel(coeff),1), coeff];
            self.i_S = self.i_S + 1;
        end
        
        function self = coefficient_similar_to_dof_derivative_at_axial_location(self, n_r, n_p, coeff, i_j, i_h, l, i_d) % note the order change
            if nargin == 6
                l =  zeros(numel(coeff),1); % equal to the other joint/dof at base
            end
            if nargin == 7
                i_d = ones(numel(coeff),1); % results in all mesh nodes having the same equal2 property
            end
            n_d = 1 : numel(coeff);
            self = element_coefficient_similar_to_dof_derivative_at_axial_location(self, n_d, n_r, n_p, coeff, i_j, i_h, l, i_d);
        end
        
        function self = element_coefficient_similar_to_dof_derivative_at_axial_location(self, n_d, n_r, n_p, coeff, i_j, i_h, l, i_d) % note the order change
            if nargin == 7
                l =  zeros(numel(coeff),1); % equal to the other joint/dof at base
            end
            if nargin == 8
                i_d = ones(numel(coeff),1); % results in all mesh nodes having the same equal2 property
            end
            % [i_j, i_d, i_h, 0, l, n_p, coeff]
            self.equal2_val{n_r}(n_d,:) = [i_j, i_d, i_h, zeros(numel(coeff),1), l, n_p, coeff];
            self.pipe.equal2{n_r}(n_d,:) = [i_j, i_d, i_h, zeros(numel(coeff),1), l, n_p, coeff];
            self.i_S = self.i_S + 1;
        end
        
        function self = coefficient_similar_to_dof_derivative_at_tip(self, n_r, n_p, coeff, i_j, i_h, i_d) % note the order change
            if nargin == 6
                i_d = ones(numel(coeff),1); % results in all mesh nodes having the same equal2 property
            end
            n_d = 1 : numel(coeff);
            self = element_coefficient_similar_to_dof_derivative_at_tip(self, n_d, n_r, n_p, coeff, i_j, i_h, i_d);
        end
        
        function self = element_coefficient_similar_to_dof_derivative_at_tip(self, n_d, n_r, n_p, coeff, i_j, i_h, i_d) % note the order change
            l = nan * ones(numel(coeff),1); % equal to the other joint/dof at tip
            if nargin == 7
                i_d = ones(numel(coeff),1); % results in all mesh nodes having the same equal2 property
            end
            % [i_j, i_d, i_h, 0, l, n_p, coeff]
            self.equal2_val{n_r}(n_d,:) = [i_j, i_d, i_h, zeros(numel(coeff),1), l, n_p, coeff];
            self.pipe.equal2{n_r}(n_d,:) = [i_j, i_d, i_h, zeros(numel(coeff),1), l, n_p, coeff];
            self.i_S = self.i_S + 1;
        end
        
        function self = set_rom_coefficient(self, n_r, value)
            n_d = 1 : numel(value);
            self = element_set_rom_coefficient(self, n_d, n_r, value);
        end
        
        function self = element_set_rom_coefficient(self, n_d, n_r, value)
            % [nan, 0, 0, 0, value, 0, 1]
            self.equal2_val{n_r}(n_d,:) = [nan*ones(numel(value),1), zeros(numel(value),3), value, zeros(numel(value),1), ones(numel(value),1)]; % ground fixed
            self.pipe.equal2{n_r}(n_d,:) = [nan*ones(numel(value),1), zeros(numel(value),3), value, zeros(numel(value),1), ones(numel(value),1)];
            self.i_S = self.i_S + 1;
        end
        
        function self = base_value(self, value) % changes spring too
            n_d = 1 : numel(value);
            self = element_base_value(self, n_d, value);
        end
        
        function self = element_base_value(self, n_d, value) % changes spring too
            % [nan, 0, 0, 0, value, 0, 1]
            self.equal2_val{1}(n_d,:) = [nan*ones(numel(value),1), zeros(numel(value),3), value, zeros(numel(value),1), ones(numel(value),1)]; % ground fixed
            self.pipe.equal2{1}(n_d,:) = [nan*ones(numel(value),1), zeros(numel(value),3), value, zeros(numel(value),1), ones(numel(value),1)];
            % self.pipe.spring.equal2(:,:,1) = [nan, 0, 0, 0, value, 0, 1];
            self.i_S = self.i_S + 1;
        end
        
        function self = base_director(self, director) % changes spring too
            n_d = 1 : numel(director);
            self = element_base_director(self, n_d, director);
        end
        
        function self = element_base_director(self, n_d, director) % changes spring too
            % [nan, 0, 0, 0, director, 0, 1]
            self.equal2_val{2}(n_d,:) = [nan*ones(numel(director),1), zeros(numel(director),3), director, zeros(numel(director),1), ones(numel(director),1)];
            self.pipe.equal2{2}(n_d,:) = [nan*ones(numel(director),1), zeros(numel(director),3), director, zeros(numel(director),1), ones(numel(director),1)];
            % self.pipe.spring.equal2(:,:,2) = [nan, 0, 0, 0, director, 0, 1];
            self.i_S = self.i_S + 1;
        end
        
        function self = axial_offset(self, offset) % changes spring too
            self.rom_offset_val = offset;
            self.pipe.rom_offset = offset;
            % self.pipe.spring.rom_offset = offset;
            self.i_S = self.i_S + 1;
        end
        
        function self = initial_value(self, init, init_type)
            if nargin < 3
                init_type = 'cartesian_configuration' ;
            end
            self.init_type_val = init_type ;
            self.init_val = init;
            self.pipe.init = init;
            switch init_type
                case 'state'
                    self.pipe.init_cart = 0;
                case 'cartesian_configuration'
                    self.pipe.init_cart = 1;
            end
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
                case 'position'
                    self.control_val = input;
                    self.pipe.control = input;
                otherwise
                    self.input_val = input;
                    self.pipe.input = input;
            end
            self.i_S = self.i_S + 1;
        end
        
        function self = unknown_direct_input(self)
            self.direct_input('force', inf);
        end
        
        function self = direct_input_at_coefficient(self, n_r, input_type, input)
            switch input_type
                case 'force'
                    self.input_val(:,n_r) = input;
                    self.pipe.input(:,n_r) = input;
                case 'position'
                    self.control_val(:,n_r) = input;
                    self.pipe.control(:,n_r) = input;
                otherwise
                    self.input_val(:,n_r) = input;
                    self.pipe.input(:,n_r) = input;
            end
            self.i_S = self.i_S + 1;
        end
        
        function self = unknown_direct_input_at_coefficient(self, n_r)
            self.direct_input_at_coefficient(n_r, 'force', inf);
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
        
        function varargout = subsref (self, S)
            try
                [varargout{1:nargout}] = builtin('subsref', self, S);
            catch e
                if ~ strcmp (e.identifier, 'MATLAB:noSuchMethodOrField')
                    rethrow(e)
                end
                % e.message
                self.source.source.pipe.dof(self.q_index) = self.pipe; % to be copied in joint struct, not tr
                self.source.i_S = 1 ; % reset i_S of the source object
                [varargout{1:nargout}] = builtin('subsref', self.source, S(2*self.i_S-1:end));
            end
        end
        
    end
end
