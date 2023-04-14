classdef rom_builder < handle
    
    properties (GetAccess = public, SetAccess = private)
        the_source;
        pipe;
        
        order_val;
    end
    
    methods
        function self = rom_builder(source)
            self.the_source = source;
        end
        
        function self = order(self,order)
            self.order_val = order;
            self.pipe = order;
        end
        
        function varargout = subsref (self, S)
            try
                [varargout{1:nargout}] = builtin('subsref', self, S);
            catch
            	source.pipe.rom = self.pipe;
                [varargout{1:nargout}] = builtin('subsref', self.source, S);
            end
        end
        
    end
end
