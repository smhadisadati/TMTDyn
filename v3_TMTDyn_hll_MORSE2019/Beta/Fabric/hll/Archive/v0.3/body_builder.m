classdef body_builder < handle
    
    properties (GetAccess = public, SetAccess=private)
        the_source;
        pipe;
        name;
        
        mass_val;
        inertia_vec;
        length_val;
        l_com_val;
		i_j;
    end
    
    methods
        function self = body_builder(source, name)
            self.the_source = source;
            self.name = name;
        end
        
        function self = with_mass(mass)
            self.mass_val = mass;
            self.pipe.m = mass;
        end
        
        function self = with_inertia(self, inertia)
            self.inertia_vec = inertia;
            self.pipe.inertia = inertia;
        end
        
        function self = with_tip_at(self, tip)
            self.length_val = tip;
            self.pipe.tip = tip;
        end
        
        function self = with_center_of_mass_at(self, l_com)
            self.l_com_val = l_com;
            self.the_pipe.l_com = l_com;
        end

        function joint = connected_from(self)
			self.source.i_j = self.source.i_j + 1;
			self.i_j = self.source.i_j;
            joint = joint_builder(self, [self.name '_joint'], self.source.i_m);
            self.source.joints(self.source.i_j) = joint;
        end
        
        function varargout = subsref (self, S)
            try
                [varargout{1:nargout}] = builtin('subsref', self, S);
            catch
            	source.pipe.body(source.i_m) = self.pipe;
                [varargout{1:nargout}] = builtin('subsref', self.source, S);
            end
        end
        
    end
end
