classdef joint_builder < handle
    
    properties (GetAccess = public, SetAccess = private)
        source;
        name;
		template;
        
        n_mesh;
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
        i_t = 0; % number of transformations
        i_t2nd = 0; % nuimber of transformations w.r.t. 2nd body
        i_q = 0; % number of dof definitions
        i_S = 1;
    end
    
    methods
        function self = joint_builder(source, name, to_body, mesh_no, axial_loc)
            self.source = source;
            self.name = name;
			self.template = source.template;
			self.pipe = source.template.joint;
            if nargin < 4
                mesh_no = 1;
            end
            if nargin < 5
                axial_loc = zeros(1, numel(mesh_no));
            end
            if nargin > 2
                self.second_body = [to_body, mesh_no; 0, axial_loc];
                self.pipe.second = [to_body, mesh_no; 0, axial_loc];
            else
                self.second_body = [0, 1];
                self.pipe.second = [0, 1];
            end
            self.pipe.n_mesh = numel(mesh_no);
            self.n_mesh = numel(mesh_no);
        end
        
        function rom = rom(self)
            rom = rom_builder(self) ;
            self.rom_val = rom ;
            self.i_S = self.i_S + 1;
        end
        
        function self = from_body(self, first, mesh_no, axial_loc)
            if nargin < 3
                mesh_no = [];
            end
            if nargin < 4
                axial_loc = zeros(1, numel(mesh_no));
            end
            self.first_body = [first, mesh_no; 0, axial_loc] ;
            self.pipe.first = [first, mesh_no; 0, axial_loc] ;
            self.i_S = self.i_S + 1;
        end
        
        function self = from_body_tip(self, first, mesh_no)
            if nargin < 3
                mesh_no = [];
            end
            self.first_body = [first, mesh_no; 0, nan] ;
            self.pipe.first = [first, mesh_no; 0, nan] ;
            self.i_S = self.i_S + 1;
        end
        
        function self = to_body(self, second, mesh_no, axial_loc)
            if nargin < 3
                mesh_no = [];
            end
            if nargin < 4
                axial_loc = zeros(1, numel(mesh_no));
            end
            self.second_body = [second, mesh_no; 0, axial_loc] ;
            self.pipe.second = [second, mesh_no; 0, axial_loc] ;
            self.i_S = self.i_S + 1;
        end
        
        function self = to_body_tip(self, second, mesh_no)
            if nargin < 3
                mesh_no = [];
            end
            self.second_body = [second, mesh_no; 0, nan] ;
            self.pipe.second = [second, mesh_no; 0, nan] ;
            self.i_S = self.i_S + 1;
        end
        
        function transformation = with_transformation_from_body(self, from_body, mesh_no, axial_loc)
			if nargin > 1
                if nargin < 3
                    mesh_no = 1;
                end
                if nargin < 4
                    axial_loc = zeros(1, numel(mesh_no));
                end
                self.first_body = [from_body, mesh_no; 0, axial_loc] ;
                self.pipe.first = [from_body, mesh_no; 0, axial_loc] ;
			end
            self.i_t = self.i_t + 1;
            transformation = transformation_builder(self, 1); % tr
            self.transformations{self.i_t} = transformation;
            self.i_S = self.i_S + 1;
        end
        
        function transformation2nd = with_transformation_to_body(self, to_body, mesh_no, axial_loc)
            self.first_body = self.second_body; % connect this body to another
            self.pipe.first = self.second_body;
			if nargin > 1
                if nargin < 3
                    mesh_no = 1;
                end
                if nargin < 4
                    axial_loc = zeros(1, numel(mesh_no));
                end
                self.second_body = [to_body, mesh_no; 0, axial_loc] ;
                self.pipe.second = [to_body, mesh_no; 0, axial_loc] ;
			end
            self.i_t2nd = self.i_t2nd + 1;
            transformation2nd = transformation_builder(self, 2); % tr2nd
            self.transformation2nd{self.i_t2nd} = transformation2nd;
            self.i_S = self.i_S + 1;
        end
        
        function transformation2nd = with_transformation_to_body_tip(self, to_body, mesh_no)
            self.first_body = self.second_body; % connect this body to another
            self.pipe.first = self.second_body;
			if nargin > 1
                if nargin < 3
                    mesh_no = 1;
                end
                self.second_body = [to_body, mesh_no; 0, nan] ;
                self.pipe.second = [to_body, mesh_no; 0, nan] ;
			end
            self.i_t2nd = self.i_t2nd + 1;
            transformation2nd = transformation_builder(self, 2); % tr2nd
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
        
        function self = wrt_body(self, refbody, mesh_no, axial_loc)
            if nargin < 3
                mesh_no = [];
            end
            if nargin < 4
                axial_loc = [];
            end
            self.refbody_val = [refbody, mesh_no, axial_loc] ;
            self.pipe.refbody = [refbody, mesh_no, axial_loc];
            self.i_S = self.i_S + 1;
        end
        
        function self = wrt_body_tip(self, refbody, mesh_no)
            if nargin < 3
                mesh_no = [];
            end
            self.refbody_val = [refbody, mesh_no, nan] ;
            self.pipe.refbody = [refbody, mesh_no, nan];
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
		
        function self = control_directions(self,fixed_directions)
			if nargin == 1
				fixed_directions = ones(1,6);
			end
			index = find( fixed_directions );
			fixed_directions(index) = inf;
			self.fixed_directions(fixed_directions);
        end
        
        function self = known_trajectory(self,control)
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
                % e.message
            	self.source.pipe.joint(self.source.i_j) = self.pipe;
				self.source.i_S = 1 ; % reset i_S of the source object
                [varargout{1:nargout}] = builtin('subsref', self.source, S(2*self.i_S-1:end));
            end
        end
        
    end
end
