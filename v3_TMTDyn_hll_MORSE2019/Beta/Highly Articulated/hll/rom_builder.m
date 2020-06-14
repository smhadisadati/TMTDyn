classdef rom_builder < handle
    
    properties (GetAccess = public, SetAccess = private)
        source;
        
        default_order_val;
        length_val;
		base_condition_val;
		free_base_val;
		init_s_val;
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
        
        function self = default_order(self, order)
            self.default_order_val = order;
            self.pipe.order = order;
            self.pipe.default_order = order;
            self.i_S = self.i_S + 1;
        end

        function self = length(self, length)
            self.length_val = length;
            self.pipe.length = length;
            self.i_S = self.i_S + 1;
        end
		
        function self = from_body_frame(self, condition)
            self.base_condition_val = condition;
			switch condition
				case 'relative' % IC @s=0..l should be in from_body local frame: Q_0 = Q_0_loc for both dof and spring
					self.pipe.rel_base = 1;
				case 'absolute' % IC @s=0..l should be in absolute frame minus the ansolute IC of from_body frame: Q_0 = Q_0_abs - Q_from_body_abs for dof but Q_0 = Q_0_loc for spring
					self.pipe.rel_base = 0;
			end
            self.i_S = self.i_S + 1;
        end
		
        function self = free_base(self)
            self.free_base_val = 1;
            self.pipe.free_base = 1;
            self.i_S = self.i_S + 1;
        end
		
        function self = reference_axial_locations(self, value)
            self.init_s_val = value;
            self.pipe.init_s = value;
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
