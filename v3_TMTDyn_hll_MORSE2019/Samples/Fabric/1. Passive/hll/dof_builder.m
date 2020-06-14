classdef dof_builder < handle

    properties (GetAccess = public, SetAccess=private)
        source;
		template;
        
		equal2_val ;
		init_val ;
		init_s_val ;
		the_spring ;
		active_direction ;
		the_damping ;
		input_val ;
    end

    properties (GetAccess = public, SetAccess=public)
        pipe;
        i_S = 1;
    end
    
    methods
        function self = dof_builder(source)
            self.source = source;
			self.template = source.template;
			self.pipe = source.template.joint.dof;
        end

		function self = equal2(self,equal2)
			self.equal2_val = equal2;
            self.pipe.equal2 = equal2;
            self.i_S = self.i_S + 1;
		end

		function self = initial_value(self,init)
			self.init_val = init;
            self.pipe.init = init;
            self.i_S = self.i_S + 1;
		end

		function self = initial_value_axial_locations(self,init_s)
			self.init_s_val = init_s;
            self.pipe.init_s = init_s;
            self.i_S = self.i_S + 1;
		end

		function spring = parallel_spring( self )
            self.the_spring = spring_builder(self);
            spring = self.the_spring;
            self.i_S = self.i_S + 1;
		end

		function self = parallel_elements_active_direction(self,dir)
			self.active_direction = dir;
            self.pipe.dir = dir;
            self.i_S = self.i_S + 1;
		end

		function damper = parallel_damper( self )
            self.the_damping = damper_builder(self);
            damper = self.the_damping;
            self.i_S = self.i_S + 1;
		end

		function self = direct_input(self,input)
			self.input_val = input;
            self.pipe.input = input;
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
            	self.source.source.pipe.dof(self.source.source.i_q) = self.pipe; % to be copied in joint struct, not tr
				self.source.i_S = 1 ; % reset i_S of the source object
                [varargout{1:nargout}] = builtin('subsref', self.source, S(2*self.i_S-1:end));
            end
        end

    end
end
