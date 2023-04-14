classdef tmtdyn < handle
    
    properties (GetAccess = public, SetAccess = private)
        pipe; % struct: transfer data to TMTDyn package old interface
        
        the_world;
        the_robot;
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
            self.the_simulation = simulation_builder(self);
            simulation = self.the_simulation;
        end
        
        function self = run(self)
            par = self.pipe.simulation;
            world = self.pipe.world;
            body = self.pipe.robot.body;
            joint = self.pipe.robot.joint;
            exload = self.pipe.robot.exload;
            mesh = self.pipe.robot.mesh;
            pipe_to_old_interface (par, world, body, joint, exload, mesh);
        end
    end
    
end
