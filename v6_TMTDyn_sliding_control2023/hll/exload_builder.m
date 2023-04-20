classdef exload_builder < handle
    
    properties (GetAccess = public, SetAccess=private)
        source;
        name;
		template;
        
        exbody_val ;
        refbody_val ;
        transformations ;
        force_val ;
        moment_val ;
        ftau_val ;        
    end

    properties (GetAccess = public, SetAccess=public)
        pipe;
        i_t = 0 ; % transformation counter
        i_S = 1; % counter for executed functions of the full DDL input in the current (this) object
    end
    
    methods
        function self = exload_builder(source, name)
            self.source = source;
            self.name = name;
			self.template = source.template;
			self.pipe = source.template.exload;
        end
        
        function self = exerted_on_body( self, exbody_val, mesh_no, axial_loc )
            if nargin < 3
                mesh_no = 1;
            end
            if nargin < 4
                axial_loc = zeros( numel(mesh_no) );
            end
            self.exbody_val = [exbody_val, mesh_no; 0, axial_loc] ;
            self.pipe.exbody = [exbody_val, mesh_no; 0, axial_loc];
            self.i_S = self.i_S + 1;
        end
        
        function self = exerted_on_body_tip( self, exbody_val, mesh_no )
            if nargin < 3
                mesh_no = 1;
            end
            self.exbody_val = [exbody_val, mesh_no; 0, nan] ;
            self.pipe.exbody = [exbody_val, mesh_no; 0, nan];
            self.i_S = self.i_S + 1;
        end
        
        function self = wrt_reference_body( self, refbody_val, mesh_no, axial_loc )
            if nargin < 3
                mesh_no = [];
            end
            if nargin < 4
                axial_loc = [];
            end
            self.refbody_val = [refbody_val, mesh_no, axial_loc] ;
            self.pipe.refbody = [refbody_val, mesh_no, axial_loc] ;
            self.i_S = self.i_S + 1;
        end
        
        function self = wrt_reference_body_tip( self, refbody_val, mesh_no )
            if nargin < 3
                mesh_no = [];
            end
            self.refbody_val = [refbody_val, mesh_no, nan] ;
            self.pipe.refbody = [refbody_val, mesh_no, nan] ;
            self.i_S = self.i_S + 1;
        end
        
        function transformation = exerted_on_body_with_transformation( self, exbody_val , mesh_no, axial_loc )
			if nargin > 1
                if nargin < 3
                    mesh_no = 1;
                end
                if nargin < 4
                    axial_loc = zeros( numel(mesh_no) );
                end
				self.exbody_val = [exbody_val, mesh_no; 0, axial_loc] ;
				self.pipe.exbody = [exbody_val, mesh_no; 0, axial_loc] ;
			end
            self.i_t = self.i_t + 1 ;
            transformation = transformation_builder(self, 1);
            self.transformations{self.i_t} = transformation ;
            self.i_S = self.i_S + 1;
        end
        
        function transformation = exerted_on_body_tip_with_transformation( self, exbody_val , mesh_no )
			if nargin > 1
                if nargin < 3
                    mesh_no = 1;
                end
				self.exbody_val = [exbody_val, mesh_no; 0, nan] ;
				self.pipe.exbody = [exbody_val, mesh_no; 0, nan] ;
			end
            self.i_t = self.i_t + 1 ;
            transformation = transformation_builder(self, 1);
            self.transformations{self.i_t} = transformation ;
            self.i_S = self.i_S + 1;
        end
        
        function self = force( self, force_val )
            self.force_val = force_val ;
            self.pipe.ftau(:,1:3) = force_val;
            self.i_S = self.i_S + 1;
        end
        
        function self = moment( self, moment_val )
            self.moment_val = moment_val ;
            self.pipe.ftau(:,4:6) = moment_val;
            self.i_S = self.i_S + 1;
        end
		
		function self = unknown_directions(self, dirs)
			for i = 1 : numel(dirs)
				if dirs(i) == 1
				    self.pipe.ftau(:,i) = inf;
				end
			end
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
            	self.source.pipe.exload(self.source.i_l) = self.pipe;
				self.source.i_S = 1 ; % reset i_S of the source object to start executing from 1st line of DSL input % reset i_S of the source object
                [varargout{1:nargout}] = builtin('subsref', self.source, S(2*self.i_S-1:end)); % pass the unexecuted lines to the source object
            end
        end
        
    end
end
