classdef simulation_builder < handle
    
    properties (GetAccess = public, SetAccess = private)
        the_source ;
        pipe;
        
        variables ;
        variable_values ;
        derive_par ;
        analysis_par ;
        postprocesses ;
    end
    
    methods
        function self = simulation_builder(source)
            self.the_source = source;
        end
        
        function self = vars(self,variables)
            self.variables = variables ;
            self.pipe.sym = variables;
        end
        
        function self = var_vals(self,variable_values)
            self.variable_values = variable_values ;
            self.pipe.var = variable_values;
        end
        
        function derive = eom_derive(self)
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
        
        function source = end(self)
            source = self.the_source;
            source.pipe.simulation = self.pipe;
        end
    end
end
