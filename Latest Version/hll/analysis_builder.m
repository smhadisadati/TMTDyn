classdef analysis_builder < handle
    
    properties (GetAccess = public, SetAccess = private)
        source ;
        
        static_sim_val;
        dynamic_sim_val;
        modal_analysis;
        report_time_val;
        integration_steps;
        sampling_rate;
    end
    
    properties (GetAccess = public, SetAccess = public)
        i_S = 1;
    end
    
    methods
        function self = analysis_builder(source)
            self.source = source;
        end
        
        function self = static_sim(self, select, time_points)
			switch select
				case 'm_file'
					select = 1;
				case 'regenerate_mex_file'
					select = 2;
				case 'old_mex_file'
					select = 3;
				otherwise
					select = 2;
			end
			% select: 1: static analysis with Matlab func.s, 2: with C-mex func.s, 3: to used latest genarated C-Mex file
            self.static_sim_val = select ;
            self.source.pipe.equil = select;
            self.source.pipe.t_equil = time_points;
            self.i_S = self.i_S + 1;
        end
        
        function self = dynamic_sim(self, select, start_time, end_time)
			switch select
				case 'm_file'
					select = 1;
				case 'regenerate_mex_file'
					select = 2;
				case 'old_mex_file'
					select = 3;
				otherwise
					select = 2;
			end
			% select: 1: dyn. sim. with Matlab func.s, 2: with C-mex func.s, 3: to used latest genarated C-Mex file
            self.dynamic_sim_val = select ;
            self.source.pipe.dyn = select;
            self.source.pipe.t_init = start_time;
            self.source.pipe.t_final = end_time;
            self.i_S = self.i_S + 1;
        end
        
        function self = modal(self, select, time_points)
			switch select
				case 'm_file'
					select = 1;
				case 'regenerate_mex_file'
					select = 2;
				case 'old_mex_file'
					select = 3;
				otherwise
					select = 2;
			end
			% select: 1: linear modal analysis with Matlab func.s, 2: with C-mex func.s, 3: to used latest genarated C-Mex file
            self.modal_analysis = select ;
            self.source.pipe.modal = select;
            self.source.pipe.t_equil = time_points;
            self.i_S = self.i_S + 1;
        end
        
        function self = report_time_step(self,report_time)
			% sim report time
            self.report_time_val = report_time ;
            self.source.pipe.t_rep = report_time;
            self.i_S = self.i_S + 1;
        end
        
        function self = s_integration_step(self,integration_steps)
			% number of integration steps
            self.integration_steps = integration_steps ;
            self.source.pipe.n_int = integration_steps;
            self.i_S = self.i_S + 1;
        end
        
        function self = sample_rate(self,sampling_rate)
			% number of saved data samples
            self.sampling_rate = sampling_rate ;
            self.source.pipe.n_datasample = sampling_rate;
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
