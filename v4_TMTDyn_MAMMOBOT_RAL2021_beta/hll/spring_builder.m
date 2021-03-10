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
        i_S = 1;
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
        
        function self = relaxed_state(self, init, init_type)
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
		
		function self = boundary_condition(self,equal2) % [j_count, n_mesh, nj_dof, i_dof_mult, val_or_l_rom, diff_order, coeff] x i_dof_mult -or- [n_j, n_d, n_h, i_r, l, i_p, c] x n_r
			self.equal2_val = equal2;
            self.pipe.equal2 = equal2;
            self.i_S = self.i_S + 1;
        end
        
		function self = set_relaxed_state_rom_coefficient(self, n_r, value)
            n_d = 1 : numel(value);
            self = element_set_relaxed_state_rom_coefficient(self, n_d, n_r, value);
        end
        
		function self = element_set_relaxed_state_rom_coefficient(self, n_d, n_r, value)
			self.equal2_val{n_r}(n_d,:) = [nan*ones(numel(n_d),1), zeros(numel(n_d),3), value, zeros(numel(n_d),1), 1*ones(numel(n_d),1)]; % ground fixed: similar to dof.set_rom_coefficient
            self.pipe.equal2{n_r}(n_d,:) = [nan*ones(numel(n_d),1), zeros(numel(n_d),3), value, zeros(numel(n_d),1), 1*ones(numel(n_d),1)];
            self.i_S = self.i_S + 1;
		end
		
		function self = relaxed_state_coefficient_similar_to_dof_order(self, n_r, coeff, i_j, i_h, i_r, i_d) % note the order change
			if nargin == 5
				i_r = nan * ones(numel(coeff),1); % equal to the same coeff in the other joint/dof
			end
			if nargin == 6
				i_d = ones(numel(coeff),1); % results in all mesh nodes having the same equal2 property
			end
            n_d = 1 : numel(coeff);
            element_relaxed_state_coefficient_similar_to_dof_order(self, n_d, n_r, coeff, i_j, i_h, i_r, i_d);
        end
        
		function self = element_relaxed_state_coefficient_similar_to_dof_order(self, n_d, n_r, coeff, i_j, i_h, i_r, i_d) % note the order change
			if nargin == 6
				i_r = nan * ones(numel(n_d),1); % equal to the same coeff in the other joint/dof
			end
			if nargin == 7
				i_d = ones(numel(n_d),1); % results in all mesh nodes having the same equal2 property
			end
			self.equal2_val{n_r}(n_d,:) = [i_j, i_d, i_h, i_r, zeros(numel(n_d),2), coeff];
            self.pipe.equal2{n_r}(n_d,:) = [i_j, i_d, i_h, i_r, zeros(numel(n_d),2), coeff];
            self.i_S = self.i_S + 1;
        end
        
		function self = relaxed_state_coefficient_similar_to_dof_at_axial_location(self, n_r, coeff, i_j, i_h, l, i_d) % note the order change
			if nargin == 5
				l = zeros(numel(coeff),1); % equal to the other joint/dof at base
			end
			if nargin == 6
				i_d = ones(numel(coeff),1); % results in all mesh nodes having the same equal2 property
			end
            n_d = 1 : numel(coeff);
            self = element_relaxed_state_coeff_similar_to_dof_at_axial_location(self, n_d, n_r, coeff, i_j, i_h, l, i_d);
        end
        
		function self = element_relaxed_state_coeff_similar_to_dof_at_axial_location(self, n_d, n_r, coeff, i_j, i_h, l, i_d) % note the order change
			if nargin == 6
				l = zeros(numel(n_d),1); % equal to the other joint/dof at base
			end
			if nargin == 7
				i_d = ones(numel(n_d),1); % results in all mesh nodes having the same equal2 property
			end
			self.equal2_val{n_r}(n_d,:) = [i_j, i_d, i_h, zeros(numel(n_d),1), l, zeros(numel(n_d),1), coeff];
            self.pipe.equal2{n_r}(n_d,:) = [i_j, i_d, i_h, zeros(numel(n_d),1), l, zeros(numel(n_d),1), coeff];
            self.i_S = self.i_S + 1;
		end
        
		function self = relaxed_state_coefficient_similar_to_dof_at_tip(self, n_r, coeff, i_j, i_h, i_d) % note the order change
			if nargin == 5
				i_d = ones(numel(coeff),1); % results in all mesh nodes having the same equal2 property
			end
            n_d = 1 : numel(coeff);
            self = element_relaxed_state_coefficient_similar_to_dof_at_tip(self, n_d, n_r, coeff, i_j, i_h, i_d);
        end
        
		function self = element_relaxed_state_coefficient_similar_to_dof_at_tip(self, n_d, n_r, coeff, i_j, i_h, i_d) % note the order change
            l = nan * ones(numel(n_d),1); % equal to the other joint/dof at tip
			if nargin == 6
				i_d = ones(numel(n_d),1); % results in all mesh nodes having the same equal2 property
			end
			self.equal2_val{n_r}(n_d,:) = [i_j, i_d, i_h, zeros(numel(n_d),1), l, zeros(numel(n_d),1), coeff];
            self.pipe.equal2{n_r}(n_d,:) = [i_j, i_d, i_h, zeros(numel(n_d),1), l, zeros(numel(n_d),1), coeff];
            self.i_S = self.i_S + 1;
		end
            
		function self = relaxed_state_base_value(self, value)
            n_d = 1 : numel(value);
            self = element_relaxed_state_base_value(self, n_d, value);
        end
        
		function self = element_relaxed_state_base_value(self, n_d, value)
			self.equal2_val{1}(n_d,:) = [nan*ones(numel(n_d),1), zeros(numel(n_d),3), value, zeros(numel(n_d),1), ones(numel(n_d),1)];
            self.pipe.equal2{1}(n_d,:) = [nan*ones(numel(n_d),1), zeros(numel(n_d),3), value, zeros(numel(n_d),1), ones(numel(n_d),1)];
            self.i_S = self.i_S + 1;
		end
		
		function self = relaxed_state_base_director(self, director)
            n_d = 1 : numel(director);
            self = element_relaxed_state_base_director(self, n_d, director);
        end
        
		function self = element_relaxed_state_base_director(self, n_d, director)
			self.equal2_val{2}(n_d,:) = [nan*ones(numel(n_d),1), zeros(numel(n_d),3), director, zeros(numel(n_d),1), ones(numel(n_d),1)];
            self.pipe.equal2{2}(n_d,:) = [nan*ones(numel(n_d),1), zeros(numel(n_d),3), director, zeros(numel(n_d),1), ones(numel(n_d),1)];
            self.i_S = self.i_S + 1;
        end
        
		function self = relaxed_state_axial_offset(self, offset) % changes spring too
			self.rom_offset_val = offset;
            self.pipe.rom_offset = offset;
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
                n_mesh = 1;
            else
                n_mesh = numel(knots(:,1));
            end
            switch type
                case 'polynomial'
                    type = 1 * ones(n_mesh,1);
                case 'spline_piecewise'
                    type = 2 * ones(n_mesh,1);
                case 'spline_logistic_func'
                    type = 3 * ones(n_mesh,1);
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
            	self.source.pipe.spring = self.pipe;
				self.source.i_S = 1 ; % reset i_S of the source object
                [varargout{1:nargout}] = builtin('subsref', self.source, S(2*self.i_S-1:end));
            end
        end
        
    end
end
