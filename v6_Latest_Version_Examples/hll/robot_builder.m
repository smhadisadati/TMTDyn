classdef robot_builder < handle
    
    properties (GetAccess = public, SetAccess = private)
        name;
        source;
		template;
        
        bodies;
		meshes;
		exloads;

		i_m = 0; % body counter
		i_mesh = 0; % mesh counter
		i_l = 0; % external load counter
    end
    
    properties (GetAccess = public, SetAccess = public)
        pipe;
        i_S = 1; % counter for executed functions of the full DDL input in the current (this) object
		i_j = 0; % joint counter
		joints;
    end

    methods
        function self = robot_builder(source, name)
            self.name = name;
            self.source = source;
			self.template = source.template;
        end
        
        function body = body(self, name)
			self.i_m = self.i_m + 1;
            body = body_builder(self, name);
            self.bodies{self.i_m} = body ;
            self.i_S = self.i_S + 1;
        end

        function joint = joint(self, name)
			self.i_j = self.i_j + 1;
            joint = joint_builder(self, name);
            self.joints{self.i_j} = joint ;
            self.i_S = self.i_S + 1;
        end
        
        function joint = joint_with_repeated_elements(self, name, mesh_no)
			self.i_j = self.i_j + 1;
            joint = joint_builder(self, name, 0, mesh_no); % make sure override body_no later
            self.joints{self.i_j} = joint ;
            self.i_S = self.i_S + 1;
        end
        
        function joint = compliance_beam(self, name)
            joint = self. joint(name);
        end
        
        function joint = compliance_beam_with_repeated_elements(self, name, mesh_no)
            joint = self.joint_with_repeated_elements(name, mesh_no);
        end
        
        function joint = constraint(self, name)
            joint = self. joint(name);
        end
        
        function joint = constraint_with_repeated_elements(self, name, mesh_no)
            joint = self.joint_with_repeated_elements(name, mesh_no);
        end
        
        function joint = dynamic_inverse_controller(self, name)
            joint = self.joint(name);
        end
        
        function joint = dynamic_inverse_controller_with_repeated_elements(self, name, mesh_no)
            joint = self.joint_with_repeated_elements(name, mesh_no);
        end
           
        function mesh = mesh(self, name)
			self.i_mesh = self.i_mesh + 1;
            mesh = mesh_builder(self, name);
            self.meshes{self.i_mesh} = mesh ;
            self.i_S = self.i_S + 1;
        end

        function exload = exload(self, name)
			self.i_l = self.i_l + 1;
            exload = exload_builder(self, name);
            self.exloads{self.i_l} = exload ;
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
            	self.source.pipe.robot = self.pipe;
				self.source.i_S = 1 ; % reset i_S of the source object to start executing from 1st line of DSL input % reset i_S of the source object
                [varargout{1:nargout}] = builtin('subsref', self.source, S(2*self.i_S-1:end)); % pass the unexecuted lines to the source object
            end
        end
     end
end
