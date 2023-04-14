classdef world_builder < handle
    properties (GetAccess = public, SetAccess = private)
        the_source;
        pipe;
        
        g_vector;
    end
    
    methods
        function self = world_builder (source)
            self.the_source = source;
            self.pipe.g = [ 0 0 0 ];
        end
        
        function self = g(self, g_vector)
            self.g_vector = g_vector;
            self.pipe.g = g_vector;
        end
        
        function varargout = subsref (self, S)
            try
                [varargout{1:nargout}] = builtin('subsref', self, S);
            catch
            	source.pipe.world = world.pipe;
                [varargout{1:nargout}] = builtin('subsref', self.source, S);
            end
        end

    end
end
