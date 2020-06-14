classdef spring_builder < handle
    
    properties (GetAccess = public, SetAccess=private)
        source;
        
        coeff_val ;
        init_val ;
		init_type_val;
		init_s_val;
        compression_val ;
		equal2_val;
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
		
		function self = boundary_condition(self,equal2) % [j_count, n_mesh, nj_dof, i_dof_mult, val_or_l_rom] x i_dof_mult -or- [n_j, n_d, n_h, i_r, l] x n_r
			self.equal2_val = equal2;
            self.pipe.equal2 = equal2;
            self.i_S = self.i_S + 1;
		end
		function self = set_boundary_condition_for_coefficient(self, n_r, value)
			self.equal2_val(:,:,n_r) = [nan, 0, 0, 0, value]; % ground fixed
            self.pipe.equal2(:,:,n_r) = [nan, 0, 0, 0, value];
            self.i_S = self.i_S + 1;
		end
		
		function self = base_boundary_condition_value(self, value)
			self.equal2_val(:,:,1) = [nan, 0, 0, 0, value]; % ground fixed
            self.pipe.equal2(:,:,1) = [nan, 0, 0, 0, value];
            self.i_S = self.i_S + 1;
		end
		
		function self = base_boundary_condition_director(self, director)
			self.equal2_val(:,:,2) = [nan, 0, 0, 0, director];
            self.pipe.equal2(:,:,2) = [nan, 0, 0, 0, director];
            self.i_S = self.i_S + 1;
		end
        		
        function self = compression_ratio(self,compr)
            self.compression_val = compr ;
            self.pipe.compr = compr;
            self.i_S = self.i_S + 1;
        end
		        
        function varargout = subsref (self, S)
            try
                [varargout{1:nargout}] = builtin('subsref', self, S);
            catch e
                if ~ strcmp (e.identifier, 'MATLAB:noSuchMethodOrField')
                    rethrow(e)
                end
                e.message
            	self.source.pipe.spring = self.pipe;
				self.source.i_S = 1 ; % reset i_S of the source object
                [varargout{1:nargout}] = builtin('subsref', self.source, S(2*self.i_S-1:end));
            end
        end
        
    end
end
