classdef simulation_builder < handle
    
    properties (GetAccess = public, SetAccess = private)
        source;
        
        vars = [];
        control_vars = [];
        variable_values = [];
        control_variable_values = [];
        derive_par;
        analysis_par;
        postprocesses;
		user_params;
    end
    
    properties (GetAccess = public, SetAccess = public)
        pipe;
        i_S = 1; % counter for executed functions of the full DDL input in the current (this) object
    end
    
    methods
        function self = simulation_builder(source)
            self.source = source;
			self.pipe = source.template.par ;
        end
        
        function self = var(self, vars, variable_values)
			assume( vars , 'real' ) ;
			self.vars = [self.vars, vars];
            self.pipe.sym = self.vars;

            self.variable_values = [self.variable_values, variable_values];
            self.pipe.var = self.variable_values;

            self.i_S = self.i_S + 1;
        end
        
        function self = variables(self, vars, variable_values) % same as var
			assume( vars , 'real' ) ;
			self.vars = [self.vars, vars];
            self.pipe.sym = self.vars;

            self.variable_values = [self.variable_values, variable_values];
            self.pipe.var = self.variable_values;

            self.i_S = self.i_S + 1;
        end
        
        function self = control_variables(self, vars, variable_values) % complementary to var
			assume( vars , 'real' ) ;
			self.control_vars = [self.control_vars, vars];
			self.vars = [self.vars, vars];
            self.pipe.sym = self.vars;
            self.pipe.control_sym = self.control_vars;

            self.variable_values = [self.variable_values, variable_values];
            self.control_variable_values = [self.control_variable_values, variable_values];
            self.pipe.var = self.variable_values;
            self.pipe.control_var = self.control_variable_values;

            self.i_S = self.i_S + 1;
        end
        
        function self = user_pars(self,user_params)
            self.user_params = user_params;
            self.pipe.user_pars = user_params;
            self.i_S = self.i_S + 1;
        end
        
        function self = user_parameters(self,user_params) % same as user_pars
            self.user_params = user_params;
            self.pipe.user_pars = user_params;
            self.i_S = self.i_S + 1;
        end
        
        function derive = derive_eom(self, select) % 'full_system', 'assume_small_velocities', 'no'
            if nargin < 2
                select = 'full';
            end
            switch select
                case 'full_system'
                    select = 1;
                case 'assume_small_velocities'
                    select = 2;
                case 'no'
                    select = 0;
            end
            self.derive_par = eom_derive_builder(self, select);
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
                [varargout{1:nargout}] = builtin('subsref', self, S); % call set of inputs, i.e. the full DSL text
                if numel( S ) == 2 * ( self.i_S - 1 ) ; self.i_S = 1 ; end % if the last input argument is reched, reset i_S counter in case we add more elements later!
            catch e
                if ~ strcmp (e.identifier, 'MATLAB:noSuchMethodOrField')
                    rethrow(e)
                end
                % e.message
            	self.source.pipe.simulation = self.pipe;
				self.source.i_S = 1 ; % reset i_S of the source object to start executing from 1st line of DSL input % reset i_S of the source object
                [varargout{1:nargout}] = builtin('subsref', self.source, S(2*self.i_S-1:end)); % pass the unexecuted lines to the source object
            end
        end
    end
end
