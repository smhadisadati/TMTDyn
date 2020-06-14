classdef joint_builder < handle
    
    properties (GetAccess = public, SetAccess = private)
        source;
        name;
		template;
        
        rom_val;
        first_body;
        second_body;
        transformations;
        transformation2nd;
        active_dir;
        x_axis;
        the_spring;
        the_damping;
        input_val;
        refbody_val;
        fixed_dirs;
        desired_control;        
    end

    properties (GetAccess = public, SetAccess=public)
        pipe;
        dof_val;
        i_t = 0; % nuimber of transformations
        i_t2nd = 0; % nuimber of transformations w.r.t. 2nd body
        i_q = 0; % number of dof definitions
        i_S = 1;
    end
    
    methods
        function self = joint_builder(source, name, to_body)
            self.source = source;
            self.name = name;
			self.template = source.template;
			self.pipe = source.template.joint;
			if nargin == 3
            	self.second_body = to_body ;
            	self.pipe.second = to_body;
			end
        end
        
        function rom = rom(self)
            rom = rom_builder(self) ;
            self.rom_val = rom ;
            self.i_S = self.i_S + 1;
        end
        
        function self = from_body(self,first)
            self.first_body = first ;
            self.pipe.first = first;
            self.i_S = self.i_S + 1;
        end
        
        function self = to_body(self,second)
            self.second_body = second ;
            self.pipe.second = second;
            self.i_S = self.i_S + 1;
        end
        
        function transformation = with_transformation_from( self )
            self.i_t = self.i_t + 1;
            transformation = transformation_builder(self, 1);
            self.transformations{self.i_t} = transformation;
            self.i_S = self.i_S + 1;
        end
        
        function transformation2nd = with_transformation_to( self )
            self.i_t2nd = self.i_t2nd + 1;
            transformation2nd = transformation_builder(self, 2);
            self.transformation2nd{self.i_t2nd} = transformation2nd;
            self.i_S = self.i_S + 1;
        end
                
        function self = active_directions(self,direction)
            self.active_dir = direction;
            self.pipe.dir = direction;
            self.i_S = self.i_S + 1;
        end
        
        function self = beam_local_x_axis(self,axis)
            self.x_axis = axis;
            self.pipe.xaxis = axis;
            self.i_S = self.i_S + 1;
        end
        
        function spring = beam_stiffness( self )
            self.the_spring = spring_builder(self);
            spring = self.the_spring;
            self.i_S = self.i_S + 1;
        end
        
        function damping = beam_damping( self )
            self.the_damping = damper_builder(self);
            damping = self.the_damping;
            self.i_S = self.i_S + 1;
        end
        
        function self = beam_internal_actuation(self,input)
            self.input_val = input ;
            self.pipe.input = input;
            self.i_S = self.i_S + 1;
        end
        
        function self = wrt_body(self,refbody)
            self.refbody_val = refbody ;
            self.pipe.refbody = refbody;
            self.i_S = self.i_S + 1;
        end
        
        function self = fixed_directions(self,fixed_directions)
			if nargin == 1
				fixed_directions = ones(1,6);
			end
            self.fixed_dirs = fixed_directions;
            self.pipe.fixed = fixed_directions;
            self.i_S = self.i_S + 1;
        end
        
        function self = desired_trajectory(self,control)
            self.desired_control = control;
            self.pipe.control = control;
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
            	self.source.pipe.joint(self.source.i_j) = self.pipe;
				self.source.i_S = 1 ; % reset i_S of the source object
                [varargout{1:nargout}] = builtin('subsref', self.source, S(2*self.i_S-1:end));
            end
        end
        
    end
end
