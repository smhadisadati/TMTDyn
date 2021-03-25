classdef body_builder < handle
    
    properties (GetAccess = public, SetAccess=private)
        source;
        name;
		template;
        
        mass_val;
        inertia_vec;
        radius_val ;
        length_val;
        l_com_val;
    end

    properties (GetAccess = public, SetAccess=public)
        pipe;
        i_S = 1; % counter for executed functions of the full DDL input in the current (this) object
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
        
        function self = with_cross_section_radius(self, radius)
            self.radius_val = radius;
            self.pipe.radi = radius;
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

        function joint = connected_to_joint(self, name)
            if nargin < 2
                name = [self.name '_joint'];
            end
			self.source.i_j = self.source.i_j + 1;
            joint = joint_builder(self.source, name, self.source.i_m, 1);
            self.source.joints{self.source.i_j} = joint;
            self.source.pipe.body(self.source.i_m) = self.pipe;
            self.i_S = self.i_S + 1;
        end
        
        function joint = connected_to_repeated_joint(self, mesh_no)
			self.source.i_j = self.source.i_j + 1;
            joint = joint_builder(self.source, [self.name '_joint'], self.source.i_m, mesh_no);
            self.source.joints{self.source.i_j} = joint;
            self.source.pipe.body(self.source.i_m) = self.pipe;
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
            	self.source.pipe.body(self.source.i_m) = self.pipe;
				self.source.i_S = 1 ; % reset i_S of the source object to start executing from 1st line of DSL input % reset i_S of the source object
                [varargout{1:nargout}] = builtin('subsref', self.source, S(2*self.i_S-1:end)); % pass the unexecuted lines to the source object
            end
        end
        
    end
end
