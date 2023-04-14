classdef simulation_builder < handle
    
    properties (GetAccess = public, SetAccess = private)
        source;
        
        variables = [];
        variable_values = [];
        derive_par;
        analysis_par;
        postprocesses;
		user_params;
    end
    
    properties (GetAccess = public, SetAccess = public)
        pipe;
        i_S = 1;
    end
    
    methods
        function self = simulation_builder(source)
            self.source = source;
        end
        
        function self = var(self, variables, variable_values)
			assume( variables , 'real' ) ;
			self.variables = [self.variables, variables];
            self.pipe.sym = self.variables;

            self.variable_values = [self.variable_values, variable_values];
            self.pipe.var = self.variable_values;

            self.i_S = self.i_S + 1;
        end
        
        function self = user_pars(self,user_params)
            self.user_params = user_params;
            self.pipe.user = user_params;
            self.i_S = self.i_S + 1;
        end
        
        function derive = derive_eom(self)
            self.derive_par = eom_derive_builder(self);
            derive = self.derive_par;
            self.i_S = self.i_S + 1;
        end
        
        function analysis = analysis(self)
            self.analysis_par = analysis_builder(self);
            analysis = self.analysis_par;
            self.i_S = self.i_S + 1;
        end
        
        function post_process = post_process(self)
            self.postprocesses = post_process_builder(self);
            post_process = self.postprocesses;
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
            	self.source.pipe.simulation = self.pipe;
				self.source.i_S = 1 ; % reset i_S of the source object
                [varargout{1:nargout}] = builtin('subsref', self.source, S(2*self.i_S-1:end));
            end
        end
    end
end
