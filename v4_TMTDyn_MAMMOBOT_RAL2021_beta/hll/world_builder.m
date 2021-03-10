classdef world_builder < handle
    properties (GetAccess = public, SetAccess = private)
        source;
        
        g_vector;
    end

    properties (GetAccess = public, SetAccess = public)
        pipe;
        i_S = 1;
    end
    
    methods
        function self = world_builder (source)
            self.source = source;
            self.pipe.g = [ 0 0 0 ];
        end
        
        function self = g(self, g_vector)
            self.g_vector = g_vector;
            self.pipe.g = g_vector;
            self.i_S = self.i_S + 1;
        end
        
        function varargout = subsref (self, S)
            try
                [varargout{1:nargout}] = builtin('subsref', self, S);
            catch e
                if ~ strcmp (e.identifier, 'MATLAB:noSuchMethodOrField')
                    rethrow(e)
                end
                % e.message
            	self.source.pipe.world = self.pipe;
				self.source.i_S = 1 ; % reset i_S of the source object
                [varargout{1:nargout}] = builtin('subsref', self.source, S(2*self.i_S-1:end));
            end
        end

    end
end
