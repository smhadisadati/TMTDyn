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
        
        function self = static_sim(select)
			switch select
				case 'm-file'
					select = 1;
				case 'mex-regenerate'
					select = 2;
				case 'mex'
					select = 3;
			end
			% select: 1: static analysis with Matlab func.s, 2: with C-mex func.s, 3: to used latest genarated C-Mex file
            self.static_sim_val = select ;
            self.the_source.pipe.equil = select;
        end
        
        function self = dynamic_sim(self,select)
			switch select
				case 'm-file'
					select = 1;
				case 'mex-regenerate'
					select = 2;
				case 'mex'
					select = 3;
			end
			% select: 1: dyn. sim. with Matlab func.s, 2: with C-mex func.s, 3: to used latest genarated C-Mex file
            self.dynamic_sim_val = select ;
            self.the_source.pipe.dyn = select;
        end
        
        function self = modal(self,select)
			switch select
				case 'm-file'
					select = 1;
				case 'mex-regenerate'
					select = 2;
				case 'mex'
					select = 3;
			end
			% select: 1: linear modal analysis with Matlab func.s, 2: with C-mex func.s, 3: to used latest genarated C-Mex file
            self.modal_analysis = select ;
            self.the_source.pipe.modal = select;
        end
        
        function self = report_time_step(self,report_time)
            self.report_time_val = report_time ;
            self.the_source.pipe.t_rep = report_time;
        end
        
        function self = s_integration_step(self,integration_steps)
            self.integration_steps = integration_steps ;
            self.the_source.pipe.n_int = integration_steps;
        end
        
        function self = sample_rate(self,sampling_rate)
            self.sampling_rate = sampling_rate ;
            self.the_source.pipe.n_datasample = sampling_rate;
        end
        
        function varargout = subsref (self, S)
            try
                [varargout{1:nargout}] = builtin('subsref', self, S);
            catch
                [varargout{1:nargout}] = builtin('subsref', self.source, S);
            end
        end
    end
end
