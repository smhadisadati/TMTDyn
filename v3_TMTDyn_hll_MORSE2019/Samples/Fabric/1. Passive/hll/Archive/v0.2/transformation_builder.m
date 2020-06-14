classdef transformation_builder
    
    properties (GetAccess = public, SetAccess = private)
        the_source ;
        pipe;
        
        rotation_type_val ;
        translation_vec ;
        rotation_vec ;

		i_q;
    end
    
    methods (Access = public)
        function self = transformation_builder(source)
            self.the_source = source;
        end
        
        function self = trans( self, translation_vec )
            self.translation_vec = translation_vec ;
            self.pipe.trans = translation_vec;
			self = self.end_loop(self);
        end

        function self = trans_x( self, translation_value )
			if nargin == 1
				translation_value = inf;
				self = self.dof( self );
			end
            self.translation_vec = [translation_value 0 0];
            self.pipe.trans = [translation_value 0 0];
			self = self.end_loop(self);
        end

        function self = trans_y( self, translation_value )
			if nargin == 1
				translation_value = inf;
				self = self.dof( self );
			end
            self.translation_vec = [0 translation_value 0];
            self.pipe.trans = [0 translation_value 0];
			self = self.end_loop(self);
        end

        function self = trans_z( self, translation_value )
			if nargin == 1
				translation_value = inf;
				self = self.dof( self );
			end
            self.translation_vec = [0 0 translation_value];
            self.pipe.trans = [0 0 translation_value];
			self = self.end_loop(self);
        end
        
        function self = rotation_type( self , rotation_type_val )
            % angle_axis , rot_strain , unit_quat , non_unit_quat
            self.rotation_type_val = rotation_type_val ;
            self.pipe.rot_type = rotation_type_val;
			self = self.end_loop(self);
        end
        
        function self = rot( self, rotation_vec )
            self.rotation_vec = rotation_vec;
            self.pipe.rot = rotation_vec;
			self = self.end_loop(self);
        end

        function self = rot_angle_axis( self, rotation_vec )
            self.rotation_type_val = 'angle_axis' ;
            self.pipe.rot_type = 'angle_axis';
            self.rotation_vec = rotation_vec;
            self.pipe.rot = rotation_vec;
			self = self.end_loop(self);
        end

        function self = rot_strain( self, rotation_vec )
            self.rotation_type_val = 'strain' ;
            self.pipe.rot_type = 'strain';
            self.rotation_vec = rotation_vec;
            self.pipe.rot = rotation_vec;
			self = self.end_loop(self);
        end

        function self = rot_u_quat( self, rotation_vec )
            self.rotation_type_val = 'unit_quat' ;
            self.pipe.rot_type = 'unit_quat';
            self.rotation_vec = rotation_vec;
            self.pipe.rot = rotation_vec;
			self = self.end_loop(self);
        end
        
        function self = rot_nu_quat( self, rotation_vec )
            self.rotation_type_val = 'non_unit_quat' ;
            self.pipe.rot_type = 'non_unit_quat';
            self.rotation_vec = rotation_vec;
            self.pipe.rot = rotation_vec;
			self = self.end_loop(self);
        end

        function self = rot_x( self, rotation_angle )
            self.rotation_type_val = 'angle_axis' ;
            self.pipe.rot_type = 'angle_axis';
			if nargin == 1
				rotation_angle = inf;
				self = self.dof( self );
			end
            self.rotation_vec = [rotation_angle 1 0 0];
            self.pipe.rot = [rotation_angle 1 0 0];
			self = self.end_loop(self);
        end

        function self = rot_y( self, rotation_angle )
            self.rotation_type_val = 'angle_axis' ;
            self.pipe.rot_type = 'angle_axis';
			if nargin == 1
				rotation_angle = inf;
				self = self.dof( self );
			end
            self.rotation_vec = [rotation_angle 0 1 0];
            self.pipe.rot = [rotation_angle 0 1 0];
			self = self.end_loop(self);
        end

        function self = rot_z( self, rotation_angle )
            self.rotation_type_val = 'angle_axis' ;
            self.pipe.rot_type = 'angle_axis';
			if nargin == 1
				rotation_angle = inf;
				self = self.dof( self );
			end
            self.rotation_vec = [rotation_angle 0 0 1];
            self.pipe.rot = [rotation_angle 0 0 1];
			self = self.end_loop(self);
        end

        function dof = dof( self )
            self.source.i_q = self.source.i_q + 1;
			self.i_q = self.source.i_q;
            dof = dof_builder(self);
            self.source.dof_val(self.source.i_q) = dof;
        end

        function source = end(self)
			source.i_t = source.i_t - 1;
            source = self.the_source;
        end

    end

    methods (Access = private)

		function self = end_loop(self)
			source.pipe.tr(source.i_t) = self.pipe;
			source.i_t = source.i_t + 1;
		end

	end
	
end
