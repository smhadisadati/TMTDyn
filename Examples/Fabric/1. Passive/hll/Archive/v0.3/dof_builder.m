classdef dof_builder < handle

    properties (GetAccess = public, SetAccess=private)
        source;
        pipe;
        
		equal2_val ;
		init_val ;
		init_s_val ;
		the_spring ;
		active_direction ;
		the_damping ;
		input_val ;
    end
    
    methods
        function self = dof_builder(source)
          self.source = source;
        end

		function self = equal2(self,equal2)
			self.equal2_val = equal2;
            self.pipe.equal2 = equal2;
		end

		function self = init(self,init)
			self.init_val = init;
            self.pipe.init = init;
		end

		function self = init_s(self,init_s)
			self.init_s_val = init_s;
            self.pipe.init_s = init_s;
		end

		function spring = spring( self )
            self.the_spring = spring_builder(self);
            spring = self.the_spring;
		end

		function self = dir(self,dir)
			self.active_direction = dir;
            self.pipe.dir = dir;
		end

		function damper = damper( self )
            self.the_damping = damper_builder(self);
            damper = self.the_damping;
		end

		function self = input(self,input)
			self.input_val = input;
            self.pipe.input = input;
		end
        
        function varargout = subsref (self, S)
            try
                [varargout{1:nargout}] = builtin('subsref', self, S);
            catch
            	source.pipe.dof(source.i_q) = self.pipe;
                [varargout{1:nargout}] = builtin('subsref', self.source, S);
            end
        end

    end
end
