classdef simulation_builder < handle
    
    properties (GetAccess = public, SetAccess = private)
        the_source;
        pipe;
        
        variables = [];
        variable_values = [];
        derive_par;
        analysis_par;
        postprocesses;
		user_params;
    end
    
    methods
        function self = simulation_builder(source)
            self.the_source = source;
        end
        
        function self = var_vector(self,variables)
			eval( ['syms ' variables] );
			eval( ['self.variables = [self.variables, ' variables '];'] );
			assume( self.variables , 'real' ) ;
            self.pipe.sym = self.variables;
        end
        
        function self = var_values(self,variable_values)
            self.variable_values = [self.variable_values, variable_values];
            self.pipe.var = self.variable_values;
        end

        function self = var(self,name,value)
			eval( ['syms ' name] );
			eval( ['self.variables = [self.variables, ' variables '];'] );
			assume( self.variables , 'real' ) ;
            self.pipe.sym = self.variables;
            self.variable_values = [self.variable_values, value];
            self.pipe.var = self.variable_values;
        end

        function self = user_pars(self,user_params)
            self.user_params = user_params;
            self.pipe.user = user_params;
        end
        
        function derive = derive_eom(self)
            self.derive_par = eom_derive_builder(self);
            derive = self.derive_par;
        end
        
        function analysis = analysis(self)
            self.analysis_par = analysis_builder(self);
            analysis = self.analysis_par;
        end
        
        function post_process = post_process(self)
            self.postprocesses = post_process_builder(self);
            post_process = self.postprocesses;
        end
        
        function varargout = subsref (self, S)
            try
                [varargout{1:nargout}] = builtin('subsref', self, S);
            catch
            	self.pipe.user.var = self.variable_values;
            	source.pipe.simulation = self.pipe;
                [varargout{1:nargout}] = builtin('subsref', self.source, S);
            end
        end
    end
end
