classdef analysis_builder < handle
    
    properties (GetAccess = public, SetAccess = private)
        the_source ;
        
        static_sim_val;
        dynamic_sim_val;
        modal_analysis;
        report_time_val;
        integration_steps;
        sampling_rate;
    end
    
    methods
        function self = analysis_builder(source)
            self.the_source = source;
        end
        
        function self = static_sim(self)
            self.static_sim_val = 1 ;
            self.the_source.pipe.equil = 1;
        end
        
        function self = dynamic_sim(self)
            self.dynamic_sim_val = 1 ;
            self.the_source.pipe.dyn = 1;
        end
        
        function self = modal(self)
            self.modal_analysis = 1 ;
            self.the_source.pipe.modal = 1;
        end
        
        function self = report_time_step(self,report_time)
            self.report_time_val = report_time ;
            self.the_source.pipe.t_rep = report_time;
        end
        
        function self = s_integration_step(self,integration_steps)
            self.integration_steps = integration_steps ;
            self.the_source.pipe.n_int = 1;
        end
        
        function self = sample_rate(self,sampling_rate)
            self.sampling_rate = sampling_rate ;
            self.the_source.pipe.n_datasample = 1;
        end
        
        function source = end(self)
            source = self.the_source;
        end
    end
end
