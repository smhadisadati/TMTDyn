classdef transformation_builder < handle
    
    properties (GetAccess = public, SetAccess = private)
        source ;
		template;
        
        type_val = 'none' ;
        translation_vec = [0, 0, 0] ;
        rotation_vec = [1, 0, 0, 0] ;
        init_quat_vec = [1, 0, 0, 0] ;

		index; % tr (main kin chain) or tr2nd (2nd joint, not main kin chain)
		i_q = 0;
		i_q_latest; % no. of most recent defined dofs
		mix = [0, 0]; % [old, new]: to combine a translation with its subsequent rotation,
					  % and rotations of the same type
					  % 0- non, 1- trans, 2- rot, 3- rotx, 4- roty, 5- rotz 
    end

    properties (GetAccess = public, SetAccess = public)
        pipe;
        i_S = 1; % counter for executed functions of the full DDL input in the current (this) object
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
			self.mix(2) = 1;
			self = self.end_def();
            self.i_S = self.i_S + 1;
        end

        function output = trans_x( self, translation_value )
			if nargin == 1
            	self.translation_vec = [inf 0 0];
				self.mix(2) = 1;
				self = self.end_def();
            	self.i_S = self.i_S - 1; % i_S will be updated once more in self.dof
				output = self.dof( 1 );
			else
            	self.translation_vec = [translation_value 0 0];
				self.mix(2) = 1;
				output = self.end_def();
			end
            self.i_S = self.i_S + 1;
        end

        function output = trans_y( self, translation_value )
			if nargin == 1
            	self.translation_vec = [0 inf 0];
				self.mix(2) = 1;
				self = self.end_def();
            	self.i_S = self.i_S - 1; % i_S will be updated once more in self.dof
				output = self.dof( 1 );
			else
		        self.translation_vec = [0 translation_value 0];
				self.mix(2) = 1;
				output = self.end_def();
			end
            self.i_S = self.i_S + 1;
        end

        function output = trans_z( self, translation_value )
			if nargin == 1
            	self.translation_vec = [0 0 inf];
				self.mix(2) = 1;
				self = self.end_def();
            	self.i_S = self.i_S - 1; % i_S will be updated once more in self.dof
				output = self.dof( 1 );
			else				
		        self.translation_vec = [0 0 translation_value];
				self.mix(2) = 1;
				output = self.end_def();
			end
            self.i_S = self.i_S + 1;
        end
        
        function output = trans_curvilinear_axial(self)
            self.type_val = 'growing' ;
            self.translation_vec = [0 0 inf];
            self.mix(2) = 0;
            self = self.end_def();
            self.i_S = self.i_S - 1; % i_S will be updated once more in self.dof
            output = self.dof( 1 );
            self.i_S = self.i_S + 1;
        end
                
        function self = rot_angle_axis( self, rotation_vec )
            self.type_val = 'angle_axis' ;
            self.rotation_vec = rotation_vec;
			self.mix(2) = 2;
			self = self.end_def();
            self.i_S = self.i_S + 1;
        end

        function self = rot_strain( self, rotation_vec, init_quat )
            self.type_val = 'rot_strain' ;
            self.rotation_vec = [rotation_vec(1:3), 0];
            if nargin == 3
                self.init_quat_vec = init_quat;
            end
			self.mix(2) = 2;
			self = self.end_def();
            self.i_S = self.i_S + 1;
		end
		
        function self = rot_frenet_serret( self )
            self.type_val = 'frenet_serret' ;
			self.mix(2) = 2;
			self = self.end_def();
            self.i_S = self.i_S + 1;
        end
		
        function self = rot_simple_curvilinear_frame( self, init_tangent_axis )
            self.type_val = 'simple_curvilinear' ;
            self.init_quat_vec = [0, init_tangent_axis];
			self.mix(2) = 2;
			self = self.end_def();
            self.i_S = self.i_S + 1;
        end
        
        function self = rot_bishop_frame( self, curvature_vec )
            self.type_val = 'bishop_frame' ;
            self.rotation_vec = [curvature_vec(1:2), 0, 0];
			self.mix(2) = 2;
			self = self.end_def();
            self.i_S = self.i_S + 1;
        end

        function self = rot_unit_quat( self, rotation_vec )
            self.type_val = 'unit_quat' ;
            self.rotation_vec = [rotation_vec(1:3), 0];
			self.mix(2) = 2;
			self = self.end_def();
            self.i_S = self.i_S + 1;
        end
        
        function self = rot_non_unit_quat( self, rotation_vec )
            self.type_val = 'non_unit_quat' ;
            self.rotation_vec = rotation_vec;
			self.mix(2) = 2;
			self = self.end_def();
            self.i_S = self.i_S + 1;
        end

        function output = rot_x( self, rotation_angle )
            self.type_val = 'angle_axis' ;
			if nargin == 1
				self.rotation_vec = [inf 1 0 0];
				self.mix(2) = 3;
				self = self.end_def();
            	self.i_S = self.i_S - 1; % i_S will be updated once more in self.dof
				output = self.dof( 1 );
			else
		        self.rotation_vec = [rotation_angle 1 0 0];
				self.mix(2) = 3;
				output = self.end_def();
			end
            self.i_S = self.i_S + 1;
        end

        function output = rot_y( self, rotation_angle )
            self.type_val = 'angle_axis' ;
			if nargin == 1
				self.rotation_vec = [inf 0 1 0];
				self.mix(2) = 4;
				self = self.end_def();
            	self.i_S = self.i_S - 1; % i_S will be updated once more in self.dof
				output = self.dof( 1 );
			else
		        self.rotation_vec = [rotation_angle 0 1 0];
				self.mix(2) = 4;
				output = self.end_def();
			end
            self.i_S = self.i_S + 1;
        end

        function output = rot_z( self, rotation_angle )
            self.type_val = 'angle_axis' ;
			if nargin == 1
				self.rotation_vec = [inf 0 0 1];
				self.mix(2) = 5;
				self = self.end_def();
            	self.i_S = self.i_S - 1; % i_S will be updated once more in self.dof
				output = self.dof( 1 );
			else
		        self.rotation_vec = [rotation_angle 0 0 1];
				self.mix(2) = 5;
				output = self.end_def();
			end
            self.i_S = self.i_S + 1;
        end

        function dof = dof( self , index )
			q_index = self.source.i_q - self.i_q_latest + index; % tr dof numerator
            dof = dof_builder(self, q_index);
            self.source.dof_val{self.source.i_q} = dof;
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
				if self.index == 1
					self.source.i_t = self.source.i_t - 1;
				else
					self.source.i_t = self.source.i_t2nd - 1;
				end
				self.source.i_S = 1 ; % reset i_S of the source object to start executing from 1st line of DSL input % reset i_S of the source object
                [varargout{1:nargout}] = builtin('subsref', self.source, S(2*self.i_S-1:end)); % pass the unexecuted lines to the source object
            end
        end

    end

    methods (Access = private)

		function self = end_def(self)            
            if self.mix(1) == 1 && self.mix(2) > 1 % when a rot after trans
                if self.index == 1
                    self.pipe.trans = self.source.pipe.tr(self.source.i_t-1).trans;
                    self.source.i_t = self.source.i_t - 1; % to override previous tr
                else
                    self.pipe.trans = self.source.pipe.tr2nd(self.source.i_t2nd-1).trans;
                    self.source.i_t2nd = self.source.i_t2nd - 1; % to override previous tr2nd
                end
                self.pipe.type = self.type_val;
                self.pipe.init_quat = self.init_quat_vec;
                self.pipe.rot = self.rotation_vec;
                rotrans = self.rotation_vec; % trans dofs are already counted
            else
                self.pipe.trans = self.translation_vec;
                self.pipe.type = self.type_val;
                self.pipe.init_quat = self.init_quat_vec;
                self.pipe.rot = self.rotation_vec;
                rotrans = [self.translation_vec, self.rotation_vec];
            end
            self.mix(1) = self.mix(2); self.mix(2) = 0;
            
            % mix transforations
%             if self.mix(1) == 1 && self.mix(2) == 1 % when a trans after another trans
%                 if self.index == 1
%                     self.pipe.trans = self.source.pipe.tr(self.source.i_t-1).trans + self.translation_vec;
%                     self.source.i_t = self.source.i_t - 1; % to override previous tr
%                 else
%                     self.pipe.trans = self.source.pipe.tr2nd(self.source.i_t2nd-1).trans + self.translation_vec;
%                     self.source.i_t2nd = self.source.i_t2nd - 1; % to override previous tr2nd
%                 end
%                 self.pipe.type = self.type_val;
%                 self.pipe.init_quat = self.init_quat_vec;
%                 self.pipe.rot = self.rotation_vec;
%                 rotrans = self.translation_vec; % previous trans dofs are already counted
%             else
%                 if self.mix(1) == 1 && self.mix(2) > 1 % when a rot after trans
%                     if self.index == 1
%                         self.pipe.trans = self.source.pipe.tr(self.source.i_t-1).trans;
%                         self.source.i_t = self.source.i_t - 1; % to override previous tr
%                     else
%                         self.pipe.trans = self.source.pipe.tr2nd(self.source.i_t2nd-1).trans;
%                         self.source.i_t2nd = self.source.i_t2nd - 1; % to override previous tr2nd
%                     end
%                     self.pipe.type = self.type_val;
%                     self.pipe.init_quat = self.init_quat_vec;
%                     self.pipe.rot = self.rotation_vec;
%                     rotrans = self.rotation_vec; % trans dofs are already counted
%                 else
%                     if self.mix(1) == self.mix(2) && self.mix(2) > 2 % if same single-axis rotations follow
%                         if self.index == 1
%                             self.pipe.rot = self.source.pipe.tr(self.source.i_t-1).rot;
%                             self.source.i_t = self.source.i_t - 1; % to override previous tr
%                         else
%                             self.pipe.rot = self.source.pipe.tr2nd(self.source.i_t2nd-1).rot;
%                             self.source.i_t2nd = self.source.i_t2nd - 1; % to override previous tr2nd
%                         end
%                         self.pipe.rot(1) = self.pipe.rot(1) + self.rotation_vec(1);
%                         self.pipe.type = self.type_val;
%                         self.pipe.init_quat = self.init_quat_vec;
%                         self.pipe.trans = self.translation_vec;
%                         rotrans = self.rotation_vec; % previous rot dofs are already counted                     
%                     else % normal assignments
%                         self.pipe.trans = self.translation_vec;
%                         self.pipe.type = self.type_val;
%                         self.pipe.init_quat = self.init_quat_vec;
%                         self.pipe.rot = self.rotation_vec;
%                         rotrans = [self.translation_vec, self.rotation_vec];
%                     end
%                 end
%             end
%             self.mix(1) = self.mix(2); self.mix(2) = 0;

			if self.index == 1
				self.source.pipe.tr(self.source.i_t) = self.pipe;
				self.source.i_t = self.source.i_t + 1;
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

		    self.type_val = 'none' ;
		    self.translation_vec = [0, 0, 0] ;
		    self.rotation_vec = [1, 0, 0, 0] ;
		    self.init_quat_vec = [1, 0, 0, 0] ;
		end

	end
	
end
