classdef mesh_builder < handle
    
    properties (GetAccess = public, SetAccess=private)
        the_source;
        name;
        pipe;
        
        file_name_val;
        the_body;
        the_joint;
        i_m = 0;
        i_j = 0;
    end
    
    methods
        function self = mesh_builder(source, name)
            self.the_source = source;
            self.name = name;
        end
        
        function self = file_name( self, file_name_val )
            self.file_name_val = file_name_val;
            self.pipe.file_name = file_name_val;
        end
        
        function body = body(self)
            self.i_m = self.i_m + 1;
            body = body_builder(self);
            self.the_body = body ;
        end
        
        function joint = joint(self)
            self.i_j = self.i_j + 1;
            joint = joint_builder(self);
            self.the_joint = joint ;
        end
        
        function source = end(self)
            source = self.the_source;
            source.pipe.mesh(source.i_mesh) = self.pipe;
        end
        
    end
end
