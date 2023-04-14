classdef transformation_builder
    
    properties (GetAccess = public, SetAccess = private)
        the_source ;
        pipe;
        i_t;
        
        rotation_type_val ;
        translation_vec ;
        rotation_vec ;
    end
    
    methods
        function self = transformation_builder(source, i)
            self.the_source = source;
            self.i_t = i;
        end
        
        function self = trans( self, translation_vec )
            self.translation_vec = translation_vec ;
            self.pipe.trans = translation_vec;
        end
        
        function self = rotation_type( self , rotation_type_val )
            % axis_angle , rot_strain , unit_quat , non_unit_quat
            self.rotation_type_val = rotation_type_val ;
            self.pipe.rot_type = rotation_type_val;
        end
        
        function self = rot( self, rotation_vec )
            self.rotation_vec = rotation_vec;
            self.pipe.rot = rotation_vec;
        end
        
        function source = end(self)
            source = self.the_source;
            source.pipe.tr(self.i_t) = self.pipe;
        end
        
    end
end
