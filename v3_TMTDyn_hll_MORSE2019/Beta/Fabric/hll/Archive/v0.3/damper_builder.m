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
        
        function self = visc(viscosity)
            self.viscosity_val = viscosity ;
            self.pipe.visc = viscosity;
        end
        
        function self = power(self,power)
            self.power_law_val = power ;
            self.pipe.pow = power;
        end
        
        function varargout = subsref (self, S)
            try
                [varargout{1:nargout}] = builtin('subsref', self, S);
            catch
            	source.self.damp = self.pipe;
                [varargout{1:nargout}] = builtin('subsref', self.source, S);
            end
        end
        
    end
end
