classdef body_builder < handle
    
    properties (GetAccess = public, SetAccess=private)
        the_source;
        pipe;
        name;
        
        mass_val;
        inertia_vec;
        length_val;
        l_com_val;
    end
    
    methods
        function self = body_builder(source, name)
            self.the_source = source;
            self.name = name;
            self.pipe = [];
        end
        
        function self = mass(self, mass)
            self.mass_val = mass;
            self.pipe.m = mass;
        end
        
        function self = inertia(self, inertia)
            self.inertia_vec = inertia;
            self.pipe.inertia = inertia;
        end
        
        function self = length(self, length)
            self.length_val = length;
            self.pipe.length = length;
        end
        
        function self = center_of_mass(self, l_com)
            self.l_com_val = l_com;
            self.the_pipe.l_com = l_com;
        end
        
        function source = end(self)
            source = self.the_source;
            source.pipe.body(source.i_m) = self.pipe;
        end
        
    end
end
