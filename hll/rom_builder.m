classdef rom_builder < handle
    
    properties (GetAccess = public, SetAccess = private)
        source;
        
        default_order_val;
        length_val; % [l_start_rom, l_end_rom, type, coeff(-+1), i_joint(joint), i_copy(mesh), i_dofAxis(DOF), i_coeff(coeff order in rom), curve_length(along rom)]
		base_condition_val;
		free_base_val;
		init_s_val;
		fit_type_val;
		spring_fit_type_val;
        var_init_val;
        spline_growth;
        simpKnot;
        spc_order;
        stiffmodel;
        rom_offset;
        spring_rom_offset;
        singleBody;
    end

    properties (GetAccess = public, SetAccess = public)
        pipe;
        i_S = 1; % counter for executed functions of the full DDL input in the current (this) object
    end
    
    methods
        function self = rom_builder(source)
            self.source = source;
			self.pipe = source.template.joint.rom;
            self.fit_type_val = 1; % default is polynomial
            self.pipe.fit_type = 1; % polynomial fit
            self.spring_fit_type_val = 1; % default is polynomial
            self.pipe.spring_fit_type = 1; % polynomial fit
        end
        
        function self = default_order(self, order)
            self.default_order_val = order;
            self.pipe.order = order;
            self.pipe.default_order = order;
            self.i_S = self.i_S + 1;
        end
        
        function self = length(self, length_ie, length_e) % integration range along curve_length
            if nargin == 2
                curve_length = [zeros(numel(length_ie),1), length_ie];
            else
                curve_length = [length_ie, length_e];
            end
            curve_length = ones(self.source.n_copy,1) .* curve_length;
            for i = 1 : numel(length_ie) % for mesh
                self.pipe.length(i,1:2) = curve_length(i,:);
            end
            self.length_val = self.pipe.length;
            self.i_S = self.i_S + 1;
        end
        
        function self = from_body_frame(self, condition)
            self.base_condition_val = condition;
			switch condition
				case 'relative' % IC @s=0..length should be in from_body local frame: Q_0 = Q_0_loc for both dof and spring
					self.pipe.rel_base = 1;
				case 'absolute' % IC @s=0..length should be in absolute frame minus the ansolute IC of from_body frame: Q_0 = Q_0_abs - Q_from_body_abs for dof but Q_0 = Q_0_loc for spring
					self.pipe.rel_base = 0;
			end
            self.i_S = self.i_S + 1;
        end
		
        function self = free_base(self)
            self.free_base_val = 1;
            self.pipe.free_base = 1;
            self.i_S = self.i_S + 1;
        end
		
        function self = reference_axial_locations(self, value)
            self.init_s_val = value;
            self.pipe.init_s = value;
            self.i_S = self.i_S + 1;
        end
        
        function self = fixed_inital_values(self)
            self.var_init_val = 0;
            self.pipe.var_init = 0;
            self.i_S = self.i_S + 1;
        end
        
        function self = default_fit_type(self, type, knots) % 'polynomial', 'spline_piecewise', 'spline_logistic_func', 'spline_mesh'
            if nargin < 3
                knots = [];
            end
            switch type
                case 'polynomial'
                    type = 1 ;
                case 'spline_piecewise'
                    type = 2 * ones(numel(knots(:,1)),1);
                case 'spline_logistic_func'
                    type = 3 * ones(numel(knots(:,1)),1);
                case 'spline_mesh'
                    type = 4 * ones(numel(knots(:,1)),1);
            end
            self.fit_type_val = [type, knots];
            self.pipe.fit_type = [type, knots];
            % self.spring_fit_type_val = self.fit_type_val;
            % self.pipe.spring_fit_type = self.pipe.fit_type;
            self.i_S = self.i_S + 1;
        end
        
        function self = default_relaxed_state_fit_type(self, type, knots) % 'polynomial', 'spline_piecewise', 'spline_logistic_func', 'spline_mesh'
            if nargin < 3
                knots = [];
            end
            switch type
                case 'polynomial'
                    type = 1 * ones(numel(knots(:,1)),1);
                case 'spline_piecewise'
                    type = 2 * ones(numel(knots(:,1)),1);
                case 'spline_logistic_func'
                    type = 3 * ones(numel(knots(:,1)),1);
                case 'spline_mesh'
                    type = 4 * ones(numel(knots(:,1)),1);
            end
            self.spring_fit_type_val = [type, knots];
            self.pipe.spring_fit_type = [type, knots];
            self.i_S = self.i_S + 1;
        end
        
        function self = use_default_spline_knots(self)
            self.simpKnot = 1;
            self.pipe.simpKnot = 1;
            self.i_S = self.i_S + 1;
        end
        
        function self = default_spline_continuity_order(self, value)
            self.spc_order = value;
            self.pipe.spc_order = value;
            self.i_S = self.i_S + 1;
        end
                
        function self = default_spline_growth_rate(self, growth_rate)
            self.spline_growth = growth_rate;
            self.pipe.growth = growth_rate;
            self.i_S = self.i_S + 1;
        end
             
        function self = default_axial_offset(self, offset)
            self.rom_offset = offset;
            self.pipe.rom_offset = offset;
            self.i_S = self.i_S + 1;
        end
        
        function self = default_relaxed_state_axial_offset(self, offset)
            self.spring_rom_offset = offset;
            self.pipe.spring_rom_offset = offset;
            self.i_S = self.i_S + 1;
        end
        
        function self = spline_as_separate_bodies(self)
            self.singleBody = 0;
            self.pipe.singleBody = 0;
            self.i_S = self.i_S + 1;
        end

        function self = numerical_spatial_differentiation(self)
            self.stiffmodel = 2;
            self.pipe.stiffmodel = 2; % numerical differentiation
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
            	self.source.pipe.rom = self.pipe;
				self.source.i_S = 1 ; % reset i_S of the source object to start executing from 1st line of DSL input % reset i_S of the source object
                [varargout{1:nargout}] = builtin('subsref', self.source, S(2*self.i_S-1:end)); % pass the unexecuted lines to the source object
            end
        end
        
    end
end
