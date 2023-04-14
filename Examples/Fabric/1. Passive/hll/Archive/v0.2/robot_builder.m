classdef robot_builder < handle
    
    properties (GetAccess = public, SetAccess = private)
        name;
        the_source;
        pipe;
        
        bodies;
		joints;
		meshes;
		exloads;

		i_m = 0; % body counter
		i_j = 0; % joint counter
		i_mesh = 0; % mesh counter
		i_l = 0; % external load counter
    end
    
    methods
        function self = robot_builder(source, name)
            self.name = name;
            self.the_source = source;
        end
        
        function body = body(self, name)
			self.i_m = self.i_m + 1;
            body = body_builder(self, name);
            self.bodies(self.i_m) = body ;
        end

        function joint = joint(self, name)
			self.i_j = self.i_j + 1;
            joint = joint_builder(self, name);
            self.joints(self.i_j) = joint ;
        end

        function joint = constraint(self, name)
			self.i_j = self.i_j + 1;
            joint = joint_builder(self, name);
            self.joints(self.i_j) = joint ;
        end

        function joint = jacobian_inverse_controller(self, name)
			self.i_j = self.i_j + 1;
            joint = joint_builder(self, name);
            self.joints(self.i_j) = joint ;
        end

        function mesh = mesh(self, name)
			self.i_mesh = self.i_mesh + 1;
            mesh = mesh_builder(self, name);
            self.meshes(self.i_mesh) = mesh ;
        end

        function exload = exload(self, name)
			self.i_l = self.i_l + 1;
            exload = exload_builder(self, name);
            self.exloads(self.i_l) = exload ;
        end        
		
        function source = end(self)
            source = self.the_source;
            source.pipe.robot = self.pipe;
		end
     end
end
