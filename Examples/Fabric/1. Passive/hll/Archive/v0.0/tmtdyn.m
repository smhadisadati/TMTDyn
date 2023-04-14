classdef tmtdyn
    
    properties(GetAccess=public, SetAccess=private)
        the_world;
		the_robot ;
        the_simulation;
    end
    
    methods
        function self = tmtdyn()
        end
        
        function world = world(self)
            self.the_world = world_builder(self);
            world = self.the_world;
        end
        
        function robot = robot(self, name)
            self.the_robot = robot_builder(self, name);
            robot = self.the_robot;
        end
        
        function simulation = simulation(self)
            self.the_simulation = simulation_builder(self, name);
            simulation = self.the_simulation;
        end
    end
    
end
