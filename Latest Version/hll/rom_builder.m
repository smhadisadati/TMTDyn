classdef rom_builder < handle
    
    properties (GetAccess = public, SetAccess = private)
        source;
        
        order_val;
        length_val;
    end

    properties (GetAccess = public, SetAccess = public)
        pipe;
        i_S = 1;
    end
    
    methods
        function self = rom_builder(source)
            self.source = source;
			self.pipe = source.template.joint.rom;
        end
        
        function self = order(self,order)
            self.order_val = order;
            self.pipe.order = order;
            self.i_S = self.i_S + 1;
        end

        function self = length(self, length)
            self.length_val = length;
            self.pipe.length = length;
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
            	self.source.pipe.rom = self.pipe;
				self.source.i_S = 1 ; % reset i_S of the source object
                [varargout{1:nargout}] = builtin('subsref', self.source, S(2*self.i_S-1:end));
            end
        end
        
    end
end
