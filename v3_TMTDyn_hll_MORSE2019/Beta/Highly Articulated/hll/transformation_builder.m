classdef transformation_builder < handle
    
    properties (GetAccess = public, SetAccess = private)
        source ;
		template;
        
        rotation_type_val = 'none' ;
        translation_vec = [0, 0, 0] ;
        rotation_vec = [1, 0, 0, 0] ;

		index;
		i_q = 0;
		i_q_latest; % no. of most recent defined dofs
    end

    properties (GetAccess = public, SetAccess = public)
        pipe;
        i_S = 1;
	end
    
    methods (Access = public)
        function self = transformation_builder(source, index)
            self.source = source;
			self.index = index;
			self.template = source.template;
			self.pipe = source.template.joint.tr;
        end
        
        function self = translation( self, translation_vec )
            self.translation_vec = translation_vec ;
			self = self.end_def();
            self.i_S = self.i_S + 1;
        end

        function output = trans_x( self, translation_value )
			if nargin == 1
            	self.translation_vec = [inf 0 0];
				self = self.end_def();
            	self.i_S = self.i_S - 1;
				output = self.dof( 1 );
			else
            	self.translation_vec = [translation_value 0 0];
				output = self.end_def();
			end
            self.i_S = self.i_S + 1;
        end

        function output = trans_y( self, translation_value )
			if nargin == 1
            	self.translation_vec = [0 inf 0];
				self = self.end_def();
            	self.i_S = self.i_S - 1;
				output = self.dof( 1 );
			else
		        self.translation_vec = [0 translation_value 0];
				output = self.end_def();
			end
            self.i_S = self.i_S + 1;
        end

        function output = trans_z( self, translation_value )
			if nargin == 1
            	self.translation_vec = [0 0 inf];
				self = self.end_def();
            	self.i_S = self.i_S - 1;
				output = self.dof( 1 );
			else				
		        self.translation_vec = [0 0 translation_value];
				output = self.end_def();
			end
            self.i_S = self.i_S + 1;
        end
                
        function self = rot_angle_axis( self, rotation_vec )
            self.rotation_type_val = 'angle_axis' ;
            self.rotation_vec = rotation_vec;
			self = self.end_def();
            self.i_S = self.i_S + 1;
        end

        function self = rot_strain( self, rotation_vec )
            self.rotation_type_val = 'strain' ;
            self.rotation_vec = rotation_vec;
			self = self.end_def();
            self.i_S = self.i_S + 1;
        end

        function self = rot_u_quat( self, rotation_vec )
            self.rotation_type_val = 'unit_quat' ;
            self.rotation_vec = rotation_vec;
			self = self.end_def();
            self.i_S = self.i_S + 1;
        end
        
        function self = rot_non_unit_quat( self, rotation_vec )
            self.rotation_type_val = 'non_unit_quat' ;
            self.rotation_vec = rotation_vec;
			self = self.end_def();
            self.i_S = self.i_S + 1;
        end

        function output = rot_x( self, rotation_angle )
            self.rotation_type_val = 'angle_axis' ;
			if nargin == 1
				self.rotation_vec = [inf 1 0 0];
				self = self.end_def();
            	self.i_S = self.i_S - 1;
				output = self.dof( 1 );
			else
		        self.rotation_vec = [rotation_angle 1 0 0];
				output = self.end_def();
			end
            self.i_S = self.i_S + 1;
        end

        function output = rot_y( self, rotation_angle )
            self.rotation_type_val = 'angle_axis' ;
			if nargin == 1
				self.rotation_vec = [inf 0 1 0];
				self = self.end_def();
            	self.i_S = self.i_S - 1;
				output = self.dof( 1 );
			else
		        self.rotation_vec = [rotation_angle 0 1 0];
				output = self.end_def();
			end
            self.i_S = self.i_S + 1;
        end

        function output = rot_z( self, rotation_angle )
            self.rotation_type_val = 'angle_axis' ;
			if nargin == 1
				self.rotation_vec = [inf 0 0 1];
				self = self.end_def();
            	self.i_S = self.i_S - 1;
				output = self.dof( 1 );
			else
		        self.rotation_vec = [rotation_angle 0 0 1];
				output = self.end_def();
			end
            self.i_S = self.i_S + 1;
        end

        function dof = dof( self , index )
			q_index = self.source.i_q - self.i_q_latest + index;
            dof = dof_builder(self, q_index);
            self.source.dof_val{self.source.i_q} = dof;
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
				if self.index == 1
					self.source.i_t = self.source.i_t - 1;
				else
					self.source.i_t = self.source.i_t2nd - 1;
				end
				self.source.i_S = 1 ; % reset i_S of the source object
                [varargout{1:nargout}] = builtin('subsref', self.source, S(2*self.i_S-1:end));
            end
        end

    end

    methods (Access = private)

		function self = end_def(self)
			self.pipe.rot_type = self.rotation_type_val;
        	self.pipe.trans = self.translation_vec;
        	self.pipe.rot = self.rotation_vec;

			if self.index == 1
				self.source.pipe.tr(self.source.i_t) = self.pipe;
				self.source.i_t = self.source.i_t + 1;
				rotrans = [self.translation_vec, self.rotation_vec];
				self.i_q_latest = 0;
				for i = 1 : numel (rotrans)
					if isinf (rotrans (i))
						self.source.i_q = self.source.i_q + 1;
						self.i_q_latest = self.i_q_latest + 1;
					end
				end
			else
				self.source.pipe.tr2nd(self.source.i_t2nd) = self.pipe;
				self.source.i_t2nd = self.source.i_t2nd + 1;
			end

		    self.rotation_type_val = 'none' ;
		    self.translation_vec = [0, 0, 0] ;
		    self.rotation_vec = [1, 0, 0, 0] ;
		end

	end
	
end
