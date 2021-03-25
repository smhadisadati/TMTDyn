classdef damper_builder < handle
    
    properties (GetAccess = public, SetAccess = private)
        source;
        
        viscosity_val ;
        power_law_val ;
    end

    properties (GetAccess = public, SetAccess=public)
        pipe;
        i_S = 1; % counter for executed functions of the full DDL input in the current (this) object
    end
    
    methods
        function self = damper_builder(source)
            self.source = source;
			self.pipe = source.template.joint.damp;
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
                [varargout{1:nargout}] = builtin('subsref', self, S); % call set of inputs, i.e. the full DSL text
                if numel( S ) == 2 * ( self.i_S - 1 ) ; self.i_S = 1 ; end % if the last input argument is reched, reset i_S counter in case we add more elements later!
            catch e
                if ~ strcmp (e.identifier, 'MATLAB:noSuchMethodOrField')
                    rethrow(e)
                end
                % e.message
            	self.source.pipe.damp = self.pipe;
				self.source.i_S = 1 ; % reset i_S of the source object to start executing from 1st line of DSL input % reset i_S of the source object
                [varargout{1:nargout}] = builtin('subsref', self.source, S(2*self.i_S-1:end)); % pass the unexecuted lines to the source object
            end
        end
        
    end
end
