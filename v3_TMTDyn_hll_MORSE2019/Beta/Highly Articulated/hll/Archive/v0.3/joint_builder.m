classdef joint_builder < handle
    
    properties (GetAccess = public, SetAccess = private)
        the_source;
        name;
        pipe;
        
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
        fixed_directions;
        desired_control;
        dof_val;
        
        i_t = 0; % nuimber of transformations
        i_t2nd = 0; % nuimber of transformations w.r.t. 2nd body
        i_q = 0; % number of dof definitions
    end
    
    methods
        function self = joint_builder(source, name, to_body)
            self.the_source = source;
            self.name = name;
			if nargin == 3
            	self.second_body = to_body ;
            	self.pipe.second = to_body;
			end
        end
        
        function rom = rom(self)
            rom = rom_builder(self) ;
            self.rom_val = rom ;
        end
        
        function self = from_body(self,first)
            self.first_body = first ;
            self.pipe.first = first;
        end
        
        function self = to_body(self,second)
            self.second_body = second ;
            self.pipe.second = second;
        end
        
        function transformation = with_transformation_from( self )
            self.i_t = self.i_t + 1;
            transformation = transformation_builder(self, self.i_t);
            self.transformations(self.i_t) = transformation;
        end
        
        function transformation2nd = with_transformation_to( self )
            self.i_t2nd = self.i_t2nd + 1;
            transformation2nd = transformation_builder(self, self.i_t2nd);
            self.transformation2nd(self.i_t2nd) = transformation2nd;
        end
        
        function dof = dof( self , index )
			if nargin == 1
            	self.i_q = self.i_q + 1;
			else
				self.i_q = index;
			end
            dof = dof_builder(self);
            self.dof_val(self.i_q) = dof;
        end
        
        function self = active_direction(self,direction)
            self.active_dir = direction;
            self.pipe.dir = direction;
        end
        
        function self = xaxis(self,axis)
            self.x_axis = axis;
            self.pipe.xaxis = axis;
        end
        
        function spring = spring( self )
            self.the_spring = spring_builder(self);
            spring = self.the_spring;
        end
        
        function damper = damp( self )
            self.the_damping = damper_builder(self);
            damper = self.the_damping;
        end
        
        function self = input(self,input)
            self.input_val = input ;
            self.pipe.input = input;
        end
        
        function self = refbody(self,refbody)
            self.refbody_val = refbody ;
            self.pipe.refbody = refbody;
        end
        
        function self = fixed_directions(self,fixed_directions)
			if nargin == 1
				fixed_directions = ones(1,6);
			end
            self.fixed_directions = fixed_directions;
            self.pipe.fixed = fixed_directions;
        end
        
        function self = control(self,control)
            self.desired_control = control;
            self.pipe.control = control;
        end
        
        function varargout = subsref (self, S)
            try
                [varargout{1:nargout}] = builtin('subsref', self, S);
            catch
            	source.pipe.joint(source.i_j) = self.pipe;
                [varargout{1:nargout}] = builtin('subsref', self.source, S);
            end
        end
        
    end
end
