classdef mesh_builder < handle
    
    properties (GetAccess = public, SetAccess=private)
        the_source;
        name;
        pipe;
        
        file_name_val;
        the_body;
        the_joint;
		tol_val;
		transformations;
        i_m = 0;
        i_j = 0;
		i_t = 0;
    end
    
    methods
        function self = mesh_builder(source, name)
            self.the_source = source;
            self.name = name;
        end
        
        function self = from_file( self, file_name_val, tol_val )
            self.file_name_val = file_name_val;
            self.pipe.file_name = file_name_val;
            self.tol_val = tol_val;
            self.pipe.tol = tol_val;
        end

        function self = with_tolerance( self, tol_val )
            self.tol_val = tol_val;
            self.pipe.tol = tol_val;
        end

        function transformation = with_transformation( self )
            self.i_t = self.i_t + 1;
            transformation = transformation_builder(self, self.i_t);
            self.transformations(self.i_t) = transformation;
        end
        
        function body = with_node(self,name)
            self.i_m = self.i_m + 1;
            body = body_builder(self,name);
            self.the_body(self.i_m) = body ;
        end
        
        function joint = joint(self,name)
            self.i_j = self.i_j + 1;
            joint = joint_builder(self,name);
            self.the_joint(self.i_j) = joint ;
        end

        function joint = with_dof(self,name)
            self.i_j = 1;
            joint = joint_builder(self,name);
            self.the_joint(self.i_j) = joint ;
        end

        function joint = with_edge(self,name)
            self.i_j = 2;
            joint = joint_builder(self,name);
            self.the_joint(self.i_j) = joint ;
        end
        
        function source = end(self)
            source = self.the_source;
            source.pipe.mesh(source.i_mesh) = self.pipe;
        end
        
    end
end
