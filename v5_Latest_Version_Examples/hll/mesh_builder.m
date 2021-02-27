classdef mesh_builder < handle
    
    properties (GetAccess = public, SetAccess = private)
        source;
        name;
		template;
        
        file_name_val;
        the_body;
		tol_val;
		transformations;

        i_m = 0;
    end

    properties (GetAccess = public, SetAccess = public)
        pipe;
        joints;
        i_j = 0;
		i_t = 0;
        i_S = 1; % counter for executed functions of the full DDL input in the current (this) object
    end
    
    methods
        function self = mesh_builder(source, name)
            self.source = source;
            self.name = name;
			self.template = source.template;
			self.pipe = source.template.mesh;
        end
        
        function self = from_file( self, file_name_val, tol_val )
            self.file_name_val = file_name_val;
            self.pipe.file_name = file_name_val;
            self.tol_val = tol_val;
            self.pipe.tol = tol_val;
            self.i_S = self.i_S + 1;
        end

        function self = with_tolerance( self, tol_val )
            self.tol_val = tol_val;
            self.pipe.tol = tol_val;
            self.i_S = self.i_S + 1;
        end

        function transformation = with_base_transformation( self )
            self.i_t = self.i_t + 1;
            transformation = transformation_builder(self, 1);
            self.transformations{self.i_t} = transformation;
            self.i_S = self.i_S + 1;
        end
        
        function body = with_node_body(self,name)
            self.i_m = self.i_m + 1;
            body = body_builder(self,name);
            self.the_body{self.i_m} = body ;
            self.i_S = self.i_S + 1;
        end
        
        function joint = joint(self,name)
            self.i_j = self.i_j + 1;
            joint = joint_builder(self,name);
            self.joints{self.i_j} = joint ;
            self.i_S = self.i_S + 1;
        end

        function joint = with_node_dof(self,name)
            self.i_j = 1;
            joint = joint_builder(self,name);
            self.joints{self.i_j} = joint ;
            self.i_S = self.i_S + 1;
        end

        function joint = with_edge(self,name)
            self.i_j = 2;
            joint = joint_builder(self,name);
            self.joints{self.i_j} = joint ;
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
            	self.source.pipe.mesh(self.source.i_mesh) = self.pipe;
				self.source.i_S = 1 ; % reset i_S of the source object to start executing from 1st line of DSL input % reset i_S of the source object
                [varargout{1:nargout}] = builtin('subsref', self.source, S(2*self.i_S-1:end)); % pass the unexecuted lines to the source object
            end
        end
        
    end
end
