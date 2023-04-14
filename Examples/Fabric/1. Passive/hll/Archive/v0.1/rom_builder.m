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
        
        function source = end(self)
            source = self.the_source;
            source.pipe.rom = self.pipe;
        end
        
    end
end
