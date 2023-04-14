classdef spring_builder < handle
    
    properties (GetAccess = public, SetAccess=private)
        source;
        
        coeff_val ;
        init_val ;
        compression_val ;
    end

    properties (GetAccess = public, SetAccess = public)
        pipe;
        i_S = 1;
    end
    
    methods
        function self = spring_builder(source)
            self.source = source;
			self.pipe.coeff = []; self.pipe.init = []; self.pipe.compr = [];
        end
        
        function self = coefficient(self,coeff)
            self.coeff_val = coeff ;
            self.pipe.coeff = coeff;
            self.i_S = self.i_S + 1;
        end
        
        function self = initial_state(self,init)
            self.init_val = init ;
            self.pipe.init_val = init;
            self.i_S = self.i_S + 1;
        end

        function self = initial_state_from_configuration(self)
            self.init_val = nan ;
            self.pipe.init = nan;
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
