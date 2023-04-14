classdef eom_derive_builder < handle
    
    properties (GetAccess = public, SetAccess = private)
        source;
               
        derive;
        collection_type;
        eom_simplify;
        derive_mex;
        eom_optimize;
    end
    
    properties (GetAccess = public, SetAccess = public)
        i_S = 1;
    end
    
    methods
        function self = eom_derive_builder(source)
            self.source = source;
            self.derive = 1;
            source.pipe.derive = 1; % set 1 to rederive in TMT
        end
        
        function self = collect_terms(self,collection_type)
			% collect in 1: single struct., 2: seperte struct.s, 3: seperate func.s, 4: C func.s
            self.collection_type = collection_type;
            self.source.pipe.derive_collect = collection_type;
            self.i_S = self.i_S + 1;
        end
        
        function self = simplify_derivations(self)
			% simplify results
            self.eom_simplify = 1;
            self.source.pipe.simplify = 1;
            self.i_S = self.i_S + 1;
        end
        
        function self = use_mex(self)
			% use Matlab codegen, automatically sets par.derive_collect = 1
            self.collection_type = 1 ;
            self.derive_mex = 1 ;
            self.source.pipe.derive_collect = 1;
            self.source.pipe.derive_mex = 1;
            self.i_S = self.i_S + 1;
        end
        
        function self = optimize_code(self)
			% optimize results
            self.eom_optimize = 1;
            self.source.pipe.opv = 1;
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
				self.source.i_S = 1 ; % reset i_S of the source object
                [varargout{1:nargout}] = builtin('subsref', self.source, S(2*self.i_S-1:end));
            end
        end
    end
end
