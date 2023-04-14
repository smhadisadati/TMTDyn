classdef body_builder < handle
    
    properties (GetAccess = public, SetAccess=private)
        source;
        name;
		template;
        
        mass_val;
        inertia_vec;
        length_val;
        l_com_val;
    end

    properties (GetAccess = public, SetAccess=public)
        pipe;
        i_S = 1;
    end
    
    methods
        function self = body_builder(source, name)
            self.source = source;
            self.name = name;
			self.template = source.template;
			self.pipe = source.template.body;
        end
        
        function self = with_mass(self, mass)
            self.mass_val = mass;
            self.pipe.m = mass;
            self.i_S = self.i_S + 1;
        end
        
        function self = with_inertia(self, inertia)
            self.inertia_vec = inertia;
            self.pipe.I = inertia;
            self.i_S = self.i_S + 1;
        end
        
        function self = with_tip_at(self, tip)
            self.length_val = tip;
            self.pipe.tip = tip;
            self.i_S = self.i_S + 1;
        end
        
        function self = with_center_of_mass_at(self, l_com)
            self.l_com_val = l_com;
            self.pipe.l_com = l_com;
            self.i_S = self.i_S + 1;
        end

        function joint = connected(self)
			self.source.i_j = self.source.i_j + 1;
            joint = joint_builder(self.source, [self.name '_joint'], self.source.i_m);
            self.source.joints{self.source.i_j} = joint;
            self.source.pipe.body(self.source.i_m) = self.pipe;
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
            	self.source.pipe.body(self.source.i_m) = self.pipe;
				self.source.i_S = 1 ; % reset i_S of the source object
                [varargout{1:nargout}] = builtin('subsref', self.source, S(2*self.i_S-1:end));
            end
        end
        
    end
end
