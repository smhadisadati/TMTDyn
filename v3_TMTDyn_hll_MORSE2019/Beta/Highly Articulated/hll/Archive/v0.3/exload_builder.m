classdef exload_builder < handle
    
    properties (GetAccess = public, SetAccess=private)
        the_source;
        name;
        pipe;
        
        exbody_val ;
        refbody_val ;
        transformations ;
        force_val ;
        moment_val ;
        ftau_val ;
        
        i_t = 0 ; % transformation counter
    end
    
    methods
        function self = exload_builder(source, name)
            self.the_source = source;
            self.name = name;
        end
        
        function self = exbody( self, exbody_val )
            self.exbody_val = exbody_val ;
            self.pipe.exbody = exbody_val;
        end
        
        function self = refbody( self, refbody_val )
            self.refbody_val = refbody_val ;
            self.pipe.refbody = refbody_val;
        end
        
        function transformation = with_transformation( self )
            self.i_t = self.i_t + 1 ;
            transformation = transformation_builder(self);
            self.transformations(self.i_t) = transformation ;
        end
        
        function self = force( self, force_val )
            self.force_val = force_val ;
            self.pipe.ftau(:,1:3) = force_val;
        end
        
        function self = moment( self, moment_val )
            self.moment_val = moment_val ;
            self.pipe.ftau(:,4:6) = moment_val;
        end
        
        function varargout = subsref (self, S)
            try
                [varargout{1:nargout}] = builtin('subsref', self, S);
            catch
            	source.pipe.exload(source.i_l) = self.pipe;
                [varargout{1:nargout}] = builtin('subsref', self.source, S);
            end
        end
        
    end
end
