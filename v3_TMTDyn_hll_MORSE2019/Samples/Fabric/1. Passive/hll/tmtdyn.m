classdef tmtdyn < handle
    
    properties (GetAccess = public, SetAccess = private)        
        the_world;
        the_robot;
        the_simulation;
		template;
    end

    properties (GetAccess = public, SetAccess = public)
        pipe; % struct: transfer data to TMTDyn package old interface
		i_S = 1;
    end
    
    methods
        function self = tmtdyn()
			[self.template.world, self.template.body, self.template.joint, self.template.exload, self.template.mesh, self.template.par] = template_builder();
        end
        
        function world = world(self)
            self.the_world = world_builder(self);
            world = self.the_world;
			self.i_S = self.i_S + 1;
        end
        
        function robot = robot(self, name)
            self.the_robot = robot_builder(self, name);
            robot = self.the_robot;
			self.i_S = self.i_S + 1;
        end
        
        function simulation = simulation(self)
            self.the_simulation = simulation_builder(self);
            simulation = self.the_simulation;
			self.i_S = self.i_S + 1;
        end
        
        function results = run(self)
            if isfield (self.pipe, 'simulation')
                par_struct = self.pipe.simulation;
            else
                par_struct = self.template.par;
            end
            if isfield (self.pipe, 'world')
                world_struct = self.pipe.world;
            else
                world_struct = self.template.world;
            end
            if isfield (self.pipe.robot, 'body')
                body_struct = self.pipe.robot.body;
            else
                body_struct = self.template.body;
            end
            if isfield (self.pipe.robot, 'joint')
                joint_struct = self.pipe.robot.joint;
            else
                joint_struct = self.template.joint;
            end
            if isfield (self.pipe.robot, 'exload')
                exload_struct = self.pipe.robot.exload;
            else
                exload_struct = self.template.exload;
            end
            if isfield (self.pipe.robot, 'mesh')
                mesh_struct = self.pipe.robot.mesh;
            else
                mesh_struct = self.template.mesh;
            end
                        
            results = pipeline (par_struct, world_struct, body_struct, joint_struct, exload_struct, mesh_struct);
			self.i_S = self.i_S + 1;
        end
    end
    
end
