classdef tmtdyn < handle
    
    properties (GetAccess = public, SetAccess = private)
        pipe; % struct: transfer data to TMTDyn package old interface
        
        the_world;
        the_robot;
        the_simulation;
    end
    
    methods
        function self = tmtdyn()
            pipe.par_struct = [];
            pipe.world_struct = [];
            pipe.body_struct = [];
            pipe.joint_struct = [];
            pipe.exload_struct = [];
            pipe.mesh_struct = [];
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
        
        function results = run(self)
            par_struct = self.pipe.simulation;
            world_struct = self.pipe.world;
            body_struct = self.pipe.robot.body;
            joint_struct = self.pipe.robot.joint;
            exload_struct = self.pipe.robot.exload;
            mesh_struct = self.pipe.robot.mesh;
            results = pipeline (par_struct, world_struct, body_struct, joint_struct, exload_struct, mesh_struct);
        end
    end
    
end
