classdef analysis_builder < handle
    
    properties (GetAccess = public, SetAccess = private)
        source ;
        
        static_sim_val;
        dynamic_sim_val;
        solver_val;
        modal_analysis;
        report_time_val;
        integration_steps;
        sampling_rate;
    end
    
    properties (GetAccess = public, SetAccess = public)
        i_S = 1; % counter for executed functions of the full DDL input in the current (this) object
    end
    
    methods
        function self = analysis_builder(source)
            self.source = source;
        end
        
        function self = static_sim(self, select, time_points)
			switch select
				case 'edited_m_file'
					select = 5;
				case 'generate_m_file'
					select = 1;
				case 'generate_mex_file'
					select = 2;
				case 'old_mex_file'
					select = 3;
				case 'generate_mex_from_edited_m_file'
					select = 4;
                case 'generate_mex_from_c_files'
                    select = 6;
				otherwise
					select = 2;
			end
			if nargin == 2
				time_points = 0;
			end
			% select: 1: static analysis with Matlab func.s, 2: with C-mex func.s, 3: to used latest genarated C-Mex file
            self.static_sim_val = select ;
            self.source.pipe.equil = select;
            self.source.pipe.t_equil = time_points;
            self.i_S = self.i_S + 1;
        end
        
        function self = dynamic_sim(self, select_file, select_solver, start_time, end_time)
			switch select_file
				case 'edited_m_file'
					select_file = 5;
				case 'generate_m_file'
					select_file = 1;
				case 'generate_mex_file'
					select_file = 2;
				case 'old_mex_file'
					select_file = 3;
				case 'generate_mex_from_edited_m_file'
					select_file = 4;
                case 'generate_mex_from_c_files'
                    select_file = 6;
				otherwise
					select_file = 2;
			end
			% select_file: 1: dyn. sim. with Matlab func.s, 2: with C-mex func.s, 3: to used latest genarated C-Mex file
            self.dynamic_sim_val = select_file;
            self.source.pipe.dyn = select_file;
			switch select_solver
				case 'matlab'
					select_solver = 1;
				case 'sundials_ode'
					select_solver = 2;
				case 'sundials_dae'
					select_solver = 3;
				case 'radau'
					select_solver = 4;
				case 'radau_mex'
					select_solver = 5;
				case 'external'
					select_solver = 6;
				otherwise
					select_solver = 1;
			end
            self.solver_val = select_solver;
            self.source.pipe.solver = select_solver;
			self.source.pipe.t_init = start_time;
            self.source.pipe.t_final = end_time;
            self.i_S = self.i_S + 1;
        end
        
        function self = modal(self, select, time_points)
			switch select
				case 'old_m_file'
					select = 5;
				case 'generate_m_file'
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
        
        function self = report_time_intervals(self,report_time)
			% sim report time
            self.report_time_val = report_time ;
            self.source.pipe.t_rep = report_time;
            self.i_S = self.i_S + 1;
        end
        
        function self = spatial_integration_step(self,integration_steps)
			% number of integration steps
            self.integration_steps = integration_steps ;
            self.source.pipe.n_int = integration_steps;
            self.i_S = self.i_S + 1;
        end
        
        function self = results_sample_rate(self,sampling_rate)
			% number of saved data samples
            self.sampling_rate = sampling_rate ;
            self.source.pipe.n_datasample = sampling_rate;
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
				self.source.i_S = 1 ; % reset i_S of the source object to start executing from 1st line of DSL input % reset i_S of the source object
                [varargout{1:nargout}] = builtin('subsref', self.source, S(2*self.i_S-1:end)); % pass the unexecuted lines to the source object
            end
        end
    end
end
