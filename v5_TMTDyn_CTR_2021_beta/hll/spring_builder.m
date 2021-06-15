classdef spring_builder < handle
    
    properties (GetAccess = public, SetAccess=private)
        source;
        
        coeff_val = sym([]);
        init_val = sym([]);
		init_type_val = sym([]);
		init_s_val = sym([]);
        compression_val = sym([]);
		equal2_val;
        rom_offset_val = sym([]);
        fit_type_val;
    end

    properties (GetAccess = public, SetAccess = public)
        pipe;
        i_S = 1; % counter for executed functions of the full DDL input in the current (this) object
    end
    
    methods
        function self = spring_builder(source)
            self.source = source;
			self.pipe = source.template.joint.spring;
        end
        
        function self = coefficient(self,coeff)
            self.coeff_val = coeff ;
            self.pipe.coeff = coeff;
            self.i_S = self.i_S + 1;
        end
        
        function self = relaxed_state(self, init)
			self.init_val = init;
			self.pipe.init = init;				
            self.i_S = self.i_S + 1;
        end
        
        function self = unknown_relaxed_states(self, unkown_direction_vec)
            if nargin == 1
                unkown_direction_vec = ones(1,6);
            end
            index = find( unkown_direction_vec );
			self.init_val(index) = inf;
			self.pipe.init(index) = inf;				
            self.i_S = self.i_S + 1;
        end
        
		function self = relaxed_state_axial_locations(self,init_s)
			self.init_s_val = init_s;
            self.pipe.init_s = init_s;
            self.i_S = self.i_S + 1;
		end

        function self = relaxed_state_from_initial_condition(self)
            self.init_val = nan ;
            self.pipe.init = nan;
            self.i_S = self.i_S + 1;
        end
        
        function self = relaxed_state_from_rom_constant(self)
            self.init_val = inf ;
            self.pipe.init = inf;
            self.i_S = self.i_S + 1;
        end
		
		function self = boundary_condition(self,equal2) % [j_count, n_copy, nj_dof, i_dof_mult, val_or_l_rom, diff_order, coeff] x i_dof_mult -or- [n_j, n_copy, n_h, i_coeff, curve_length, i_p, c] x n_coeff
			self.equal2_val = equal2;
            self.pipe.equal2 = equal2;
            self.i_S = self.i_S + 1;
        end
        
		function self = set_relaxed_state_rom_coefficient(self, n_coeff, value)
            n_copy = 1 : numel(value);
            self = element_set_relaxed_state_rom_coefficient(self, n_copy, n_coeff, value);
        end
        
		function self = element_set_relaxed_state_rom_coefficient(self, n_copy, n_coeff, value)
			self.equal2_val{n_coeff}(n_copy,:) = [nan*ones(numel(n_copy),1), zeros(numel(n_copy),3), value.*ones(numel(n_copy),1), zeros(numel(n_copy),1), ones(numel(n_copy),1)]; % ground fixed: similar to dof.set_rom_coefficient
            self.pipe.equal2{n_coeff}(n_copy,:) = [nan*ones(numel(n_copy),1), zeros(numel(n_copy),3), value.*ones(numel(n_copy),1), zeros(numel(n_copy),1), ones(numel(n_copy),1)];
            self.i_S = self.i_S + 1;
		end
		
		function self = relaxed_state_coefficient_similar_to_dof_order(self, n_coeff, coeff, i_joint, i_dofAxis, i_coeff, i_copy) % note the order change
			if nargin == 5
				i_coeff = nan; % equal to the same coeff in the other joint/dof
			end
			if nargin == 6
				i_copy = 1; % results in all mesh nodes having the same equal2 property
			end
            n_copy = 1 : numel(coeff);
            element_relaxed_state_coefficient_similar_to_dof_order(self, n_copy, n_coeff, coeff, i_joint, i_dofAxis, i_coeff, i_copy);
        end
        
		function self = element_relaxed_state_coefficient_similar_to_dof_order(self, n_copy, n_coeff, coeff, i_joint, i_dofAxis, i_coeff, i_copy) % note the order change
			if nargin == 6
				i_coeff = nan; % equal to the same coeff in the other joint/dof
			end
			if nargin == 7
				i_copy = 1; % results in all mesh nodes having the same equal2 property
			end
			self.equal2_val{n_coeff}(n_copy,:) = [ones(numel(n_copy),1).*i_joint, ones(numel(n_copy),1).*i_copy, ones(numel(n_copy),1).*i_dofAxis, ones(numel(n_copy),1).*i_coeff, zeros(numel(n_copy),2), ones(numel(n_copy),1).*coeff];
            self.pipe.equal2{n_coeff}(n_copy,:) = [ones(numel(n_copy),1).*i_joint, ones(numel(n_copy),1).*i_copy, ones(numel(n_copy),1).*i_dofAxis, ones(numel(n_copy),1).*i_coeff, zeros(numel(n_copy),2), ones(numel(n_copy),1).*coeff];
            self.i_S = self.i_S + 1;
        end
        
		function self = relaxed_state_coefficient_similar_to_dof_at_axial_location(self, n_coeff, coeff, i_joint, i_dofAxis, curve_length, i_copy) % note the order change
			if nargin == 5
				curve_length = 0; % equal to the other joint/dof at base
			end
			if nargin == 6
				i_copy = 1; % results in all mesh nodes having the same equal2 property
			end
            n_copy = 1 : numel(coeff);
            self = element_relaxed_state_coeff_similar_to_dof_at_axial_location(self, n_copy, n_coeff, coeff, i_joint, i_dofAxis, curve_length, i_copy);
        end
        
		function self = element_relaxed_state_coeff_similar_to_dof_at_axial_location(self, n_copy, n_coeff, coeff, i_joint, i_dofAxis, curve_length, i_copy) % note the order change
			if nargin == 6
				curve_length = 0; % equal to the other joint/dof at base
			end
			if nargin == 7
				i_copy = 1; % results in all mesh nodes having the same equal2 property
			end
			self.equal2_val{n_coeff}(n_copy,:) = [ones(numel(n_copy),1).*i_joint, ones(numel(n_copy),1).*i_copy, ones(numel(n_copy),1).*i_dofAxis, zeros(numel(n_copy),1), ones(numel(n_copy),1).*curve_length, zeros(numel(n_copy),1), ones(numel(n_copy),1).*coeff];
            self.pipe.equal2{n_coeff}(n_copy,:) = [ones(numel(n_copy),1).*i_joint, ones(numel(n_copy),1).*i_copy, ones(numel(n_copy),1).*i_dofAxis, zeros(numel(n_copy),1), ones(numel(n_copy),1).*curve_length, zeros(numel(n_copy),1), ones(numel(n_copy),1).*coeff];
            self.i_S = self.i_S + 1;
		end
        
		function self = relaxed_state_coefficient_similar_to_dof_at_tip(self, n_coeff, coeff, i_joint, i_dofAxis, i_copy) % note the order change
			if nargin == 5
				i_copy = 1; % results in all mesh nodes having the same equal2 property
			end
            n_copy = 1 : numel(coeff);
            self = element_relaxed_state_coefficient_similar_to_dof_at_tip(self, n_copy, n_coeff, coeff, i_joint, i_dofAxis, i_copy);
        end
        
		function self = element_relaxed_state_coefficient_similar_to_dof_at_tip(self, n_copy, n_coeff, coeff, i_joint, i_dofAxis, i_copy) % note the order change
            curve_length = nan; % equal to the other joint/dof at tip
			if nargin == 6
				i_copy = 1; % results in all mesh nodes having the same equal2 property
			end
			self.equal2_val{n_coeff}(n_copy,:) = [ones(numel(n_copy),1).*i_joint, ones(numel(n_copy),1).*i_copy, ones(numel(n_copy),1).*i_dofAxis, zeros(numel(n_copy),1), ones(numel(n_copy),1).*curve_length, zeros(numel(n_copy),1), ones(numel(n_copy),1).*coeff];
            self.pipe.equal2{n_coeff}(n_copy,:) = [ones(numel(n_copy),1).*i_joint, ones(numel(n_copy),1).*i_copy, ones(numel(n_copy),1).*i_dofAxis, zeros(numel(n_copy),1), ones(numel(n_copy),1).*curve_length, zeros(numel(n_copy),1), ones(numel(n_copy),1).*coeff];
            self.i_S = self.i_S + 1;
		end
            
		function self = relaxed_state_base_value(self, value)
            n_copy = 1 : numel(value);
            self = element_relaxed_state_base_value(self, n_copy, value);
        end
        
		function self = element_relaxed_state_base_value(self, n_copy, value)
			self.equal2_val{1}(n_copy,:) = [nan*ones(numel(n_copy),1), zeros(numel(n_copy),3), ones(numel(n_copy),1).*value, zeros(numel(n_copy),1), ones(numel(n_copy),1)];
            self.pipe.equal2{1}(n_copy,:) = [nan*ones(numel(n_copy),1), zeros(numel(n_copy),3), ones(numel(n_copy),1).*value, zeros(numel(n_copy),1), ones(numel(n_copy),1)];
            self.i_S = self.i_S + 1;
        end
        
		function self = relaxed_state_base_value_at_axial_location(self, value, curve_length)
            n_copy = 1 : numel(value);
            self = element_relaxed_state_base_value_at_axial_location(self, n_copy, value, curve_length);
        end
        
		function self = element_relaxed_state_base_value_at_axial_location(self, n_copy, value, curve_length)
			self.equal2_val{1}(n_copy,:) = [nan*ones(numel(n_copy),1), zeros(numel(n_copy),3), ones(numel(n_copy),1).*value, zeros(numel(n_copy),1), ones(numel(n_copy),1)];
            self.pipe.equal2{1}(n_copy,:) = [nan*ones(numel(n_copy),1), zeros(numel(n_copy),3), ones(numel(n_copy),1).*value, zeros(numel(n_copy),1), ones(numel(n_copy),1)];
            self.i_S = self.i_S + 1;
            self.rom_offset_val(2,:) = -curve_length;
            self.pipe.rom_offset(2,:) = -curve_length;
		end
		
		function self = relaxed_state_base_director(self, director)
            n_copy = 1 : numel(director);
            self = element_relaxed_state_base_director(self, n_copy, director);
        end
        
		function self = element_relaxed_state_base_director(self, n_copy, director)
			self.equal2_val{2}(n_copy,:) = [nan*ones(numel(n_copy),1), zeros(numel(n_copy),3), ones(numel(n_copy),1).*director, zeros(numel(n_copy),1), ones(numel(n_copy),1)];
            self.pipe.equal2{2}(n_copy,:) = [nan*ones(numel(n_copy),1), zeros(numel(n_copy),3), ones(numel(n_copy),1).*director, zeros(numel(n_copy),1), ones(numel(n_copy),1)];
            self.i_S = self.i_S + 1;
        end
        
		function self = relaxed_state_base_director_at_axial_location(self, director, curve_length)
            n_copy = 1 : numel(director);
            self = element_relaxed_state_base_director_at_axial_location(self, n_copy, director, curve_length);
        end
        
		function self = element_relaxed_state_base_director_at_axial_location(self, n_copy, director, curve_length)
			self.equal2_val{2}(n_copy,:) = [nan*ones(numel(n_copy),1), zeros(numel(n_copy),3), ones(numel(n_copy),1).*director, zeros(numel(n_copy),1), ones(numel(n_copy),1)];
            self.pipe.equal2{2}(n_copy,:) = [nan*ones(numel(n_copy),1), zeros(numel(n_copy),3), ones(numel(n_copy),1).*director, zeros(numel(n_copy),1), ones(numel(n_copy),1)];
            self.i_S = self.i_S + 1;
            self.rom_offset_val(2,:) = -curve_length;
            self.pipe.rom_offset(2,:) = -curve_length;
        end
        
		function self = relaxed_state_axial_offset(self, offset) % changes spring too
			self.rom_offset_val(1,:) = offset;
            self.pipe.rom_offset(1,:) = offset;
            self.i_S = self.i_S + 1;
		end
        		
        function self = compression_ratio(self,compr)
            self.compression_val = compr ;
            self.pipe.compr = compr;
            self.i_S = self.i_S + 1;
        end
        
        function self = relaxed_state_fit_type(self, type, knots) % 'polynomial', 'spline_piecewise', 'spline_logistic_func'
            if nargin < 3
                knots = [];
                n_copy = 1;
            else
                n_copy = numel(knots(:,1));
            end
            switch type
                case 'polynomial'
                    type = 1 * ones(n_copy,1);
                case 'spline_piecewise'
                    type = 2 * ones(n_copy,1);
                case 'spline_logistic_func'
                    type = 3 * ones(n_copy,1);
            end
            self.fit_type_val = [type, knots];
            self.pipe.fit_type = [type, knots];
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
            	self.source.pipe.spring = self.pipe;
				self.source.i_S = 1 ; % reset i_S of the source object to start executing from 1st line of DSL input % reset i_S of the source object
                [varargout{1:nargout}] = builtin('subsref', self.source, S(2*self.i_S-1:end)); % pass the unexecuted lines to the source object
            end
        end
        
    end
end
