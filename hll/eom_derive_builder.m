classdef eom_derive_builder < handle
    
    properties (GetAccess = public, SetAccess = private)
        source;
               
        derive;
        collection_type;
        eom_simplify;
        derive_mex;
        eom_optimize;
        eom_clean;
		sparsity;
		cores_val;
        plotIC;
        pw2lg ; % piecewise to logistic function convertsion
    end
    
    properties (GetAccess = public, SetAccess = public)
        i_S = 1; % counter for executed functions of the full DDL input in the current (this) object
    end
    
    methods
        function self = eom_derive_builder(source, select)
            self.source = source;
            self.derive = select;
            source.pipe.derive = select; % set 1 to rederive in TMT
        end
        
        function self = collect_terms(self, collection_type)
            switch collection_type % collect in 1: single_structures, 2: separate_structures, 3: separate_functions, 4: C_functions, 5: collect_most_terms
                case 'single_structures'
                    type = 1;
                case 'separate_structures'
                    type = 2;
                case 'separate_functions'
                    type = 3;
                case 'C_functions'
                    type = 4;
                case 'collect_most_terms'
                    type = 5;
            end
            self.collection_type = type;
            self.source.pipe.derive_collect = type;
            self.i_S = self.i_S + 1;
        end
        
        function self = simplify_derivations(self, select, duration_or_precision)
			% simplify results
            if nargin < 2
                select = 12; % max duration of simplification in sec
            end
            switch select
                case 'symbolic'
                    select = 1;
                case 'decimal' 
                    select = 2;
                case 'symbolic_decimal'
                    select = 12;
            end
            if nargin < 3
                switch select 
                    case 1
                        duration_or_precision = inf; % max duration for simplify function in sec
                    case 2
                        duration_or_precision = nan; % default vpa precision
                    case 12
                        duration_or_precision = [inf, nan];
                    otherwise
                        duration_or_precision = inf ;
                end
            end
            self.eom_simplify = [select, duration_or_precision];
            self.source.pipe.simplify = [select, duration_or_precision];
            self.i_S = self.i_S + 1;
        end
		
        function self = use_cpu_cores(self, cores)
			% simplify results
            self.cores_val = cores;
            self.source.pipe.cores = cores;
            self.i_S = self.i_S + 1;
        end
		
        function self = use_single_cpu_core(self)
			% simplify results
            self.cores_val = 1;
            self.source.pipe.cores = 1;
            self.i_S = self.i_S + 1;
        end
		
        function self = assume_sparse_matrix(self)
			% simplify results
            self.sparsity = 1;
            self.source.pipe.sparse = 1;
            self.i_S = self.i_S + 1;
        end
        
        function self = use_mex(self)
			% use Matlab codegen, automatically sets par.derive_collect = 1
            % self.collection_type = 1 ;
            % self.collection_type = 1 ;
            % self.source.pipe.derive_collect = 1;
            self.derive_mex = 1 ;
            self.source.pipe.derive_mex = 1;
            self.i_S = self.i_S + 1;
        end
        
        function self = optimize_code(self)
			% optimize results
            self.eom_optimize = 1;
            self.source.pipe.opv = 1;
            self.i_S = self.i_S + 1;
        end
        
        function self = free_up_memory(self)
			% optimize results
            self.eom_clean = 1;
            self.source.pipe.clean = 1;
            self.i_S = self.i_S + 1;
        end
        
        function self = convert_piecewise_to_logistic_function(self)
			% simplify results
            self.pw2lg = 1;
            self.source.pipe.pw2lg = 1;
            self.i_S = self.i_S + 1;
        end
        
        function self = plot_initial_conditions(self, select)
            if nargin < 2
                select = 'all';
            end
            switch select
                case 'final'
                    select_id = 1;
                case 'all'
                    select_id = 2;
            end
			% optimize results
            self.plotIC = select_id;
            self.source.pipe.plotIC = select_id;
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
