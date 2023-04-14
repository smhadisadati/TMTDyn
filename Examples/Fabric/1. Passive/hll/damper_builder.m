classdef damper_builder < handle
    
    properties (GetAccess = public, SetAccess = private)
        source;
        
        viscosity_val ;
        power_law_val ;
    end

    properties (GetAccess = public, SetAccess=public)
        pipe;
        i_S = 1;
    end
    
    methods
        function self = damper_builder(source)
            self.source = source;
			self.pipe.visc = []; self.pipe.pow = [];
        end
        
        function self = viscosity(self, viscosity)
            self.viscosity_val = viscosity ;
            self.pipe.visc = viscosity;
            self.i_S = self.i_S + 1;
        end
        
        function self = power(self, power)
            self.power_law_val = power ;
            self.pipe.pow = power;
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
            	self.source.pipe.damp = self.pipe;
				self.source.i_S = 1 ; % reset i_S of the source object
                [varargout{1:nargout}] = builtin('subsref', self.source, S(2*self.i_S-1:end));
            end
        end
        
    end
end
