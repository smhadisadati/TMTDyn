classdef damper_builder < handle
    
    properties (GetAccess = public, SetAccess = private)
        the_source;
        pipe;
        
        viscosity_val ;
        power_law_val ;
    end
    
    methods
        function self = damper_builder(source)
            self.the_source = source;
        end
        
        function self = visc(self,viscosity)
            self.viscosity_val = viscosity ;
            self.pipe.visc = viscosity;
        end
        
        function self = pow(self,power)
            self.power_law_val = power ;
            self.pipe.pow = power;
        end
        
        function source = end(self)
            source = self.the_source;
            source.self.damp = self.pipe;
        end
        
    end
end
