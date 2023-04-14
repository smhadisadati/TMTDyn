classdef body_builder

    properties (GetAccess = public, SetAccess=private)
      the_robot;
      mass_val;
      inertia_vec;
      length_val;
      l_com_val;
    end
    
    methods
        function self = body_builder(the_robot)
          self.the_robot = the_robot;
        end
        
        function self = mass(self, mass)
            self.mass_val = mass;
        end
        
        function self = inertia(self, inertia)
            self.inertia_vec = inertia;
        end
        
        function self = length(self, length)
            self.length_val = length;
        end
        
        function self = center_of_mass(self, l_com)
            self.l_com_val = l_com;
        end
        

		% reference to other elements of robot_builder
		fucntion the_body = body(self)
            the_body = self.the_robot.body();
		end		

		fucntion the_joint = joint(self)
            the_joint = self.the_robot.joint();
		end	

		fucntion the_mesh = mesh(self)
            the_mesh = self.the_robot.mesh();
		end	

		fucntion the_exload = exload(self)
            the_exload = self.the_robot.exload();
		end		

    end
end
