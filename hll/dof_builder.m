classdef dof_builder < handle
    
    properties (GetAccess = public, SetAccess=private)
        source;
        template;
        q_index ; % tr dof numerator
        
        equal2_val; % {i_segm}{i_coeff}[i_joint(joint), i_copy(mesh), i_dofAxis(DOF in joint), i_coeff(rom coeff), curve_length(along rom), i_p(derivative order), c(coeff)]
        init_val = sym([]);
        init_s_val = sym([]);
        the_spring = sym([]);
        active_direction = sym([]);
        the_damping = sym([]);
        input_val = sym([]);
        control_acc_val = sym([]);
        control_vel_val = sym([]);
        control_pos_val = sym([]);
        control_err0_val = sym([]);
        gains_val = [];
        fixed_val = sym([]);
        rom_order_val = sym([]);
        init_type_val = sym([]);
        rom_offset_val = sym([]);
        fit_type_val;
        spc_order;
    end
    
    properties (GetAccess = public, SetAccess=public)
        pipe;
        i_S = 1; % counter for executed functions of the full DDL input in the current (this) object
    end
    
    methods
        function self = dof_builder(source, q_index)
            self.source = source;
            self.template = source.template;
            self.pipe = source.template.joint.dof;
            self.q_index = q_index;
        end
        
        function self = equal2(self, equal2, n_segm, n_coeff) % [j_count, n_copy, nj_dof, i_dof_mult, val_or_l_rom diff_order coeff] x i_dof_mult -or- [i_joint, i_copy, i_dofAxis, i_coeff, curve_length, i_p, c] x n_coeff
            if nargin == 2
                n_coeff = 1 ;
            end
            self.equal2_val{n_segm}{n_coeff} = equal2;
            self.pipe.equal2{n_segm}{n_coeff} = equal2;
            self.i_S = self.i_S + 1;
        end
        
        function self = similar_to_dof(self, coeff, i_joint, i_dofAxis, i_copy) % note order change
            if nargin == 4
                i_copy = 1; % results in all mesh nodes having the same equal2 property
            end
            n_copy = 1 : numel(coeff);
            self = element_similar_to_dof(self, n_copy, coeff, ones(numel(n_copy),1).*i_joint, ones(numel(n_copy),1).*i_dofAxis, ones(numel(n_copy),1).*i_copy);
        end
        
        function self = element_similar_to_dof(self, n_copy, coeff, i_joint, i_dofAxis, i_copy) % note order change
            if nargin == 5
                i_copy = 1; % results in all mesh nodes having the same equal2 property
            end
            % [i_joint, i_copy, i_dofAxis, i_coeff, 0, 0, coeff]
            self.equal2_val{1}{1}(n_copy,:) = [ones(numel(n_copy),1).*i_joint, ones(numel(n_copy),1).*i_copy, ones(numel(n_copy),1).*i_dofAxis, ones(numel(n_copy),1).*nan, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*coeff];
            self.pipe.equal2{1}{1}(n_copy,:) = [ones(numel(n_copy),1).*i_joint, ones(numel(n_copy),1).*i_copy, ones(numel(n_copy),1).*i_dofAxis, ones(numel(n_copy),1).*nan, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*coeff];
            self.i_S = self.i_S + 1;
        end
        
        function self = coefficient_similar_to_dof_order(self, n_coeff, coeff, i_joint, i_dofAxis, i_coeff, i_copy) % note the order change
            if nargin == 5
                i_coeff = nan; % equal to the same coeff in the other joint/dof
            end
            if nargin == 6
                i_copy =  1; % results in all mesh nodes having the same equal2 property
            end
            n_copy = 1 : numel(coeff);
            self = element_coefficient_similar_to_dof_order(self, n_copy, n_coeff, coeff, i_joint, i_dofAxis, i_coeff, i_copy);
        end
        
        function self = element_coefficient_similar_to_dof_order(self, n_copy, n_coeff, coeff, i_joint, i_dofAxis, i_coeff, i_copy) % note the order change
            if nargin == 6
                i_coeff = nan; % equal to the same coeff in the other joint/dof
            end
            if nargin == 7
                i_copy =  1; % results in all mesh nodes having the same equal2 property
            end
            % [i_joint, i_copy, i_dofAxis, i_coeff, 0, 0, coeff]
            self.equal2_val{1}{n_coeff}(n_copy,:) = [ones(numel(n_copy),1).*i_joint, ones(numel(n_copy),1).*i_copy, ones(numel(n_copy),1).*i_dofAxis, ones(numel(n_copy),1).*i_coeff, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*coeff];
            self.pipe.equal2{1}{n_coeff}(n_copy,:) = [ones(numel(n_copy),1).*i_joint, ones(numel(n_copy),1).*i_copy, ones(numel(n_copy),1).*i_dofAxis, ones(numel(n_copy),1).*i_coeff, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*coeff];
            self.i_S = self.i_S + 1;
        end
        
        function self = coefficient_similar_to_dof_at_axial_location(self, n_coeff, coeff, i_joint, i_dofAxis, curve_length, i_copy) % note the order change
            if nargin == 5
                curve_length =  0; % equal to the other joint/dof at base
            end
            if nargin == 6
                i_copy = 1; % results in all mesh nodes having the same equal2 property
            end
            n_copy = 1 : numel(coeff);
             self = element_coefficient_similar_to_dof_at_axial_location(self, n_copy, n_coeff, coeff, i_joint, i_dofAxis, curve_length, i_copy);
        end
                
        function self = element_coefficient_similar_to_dof_at_axial_location(self, n_copy, n_coeff, coeff, i_joint, i_dofAxis, curve_length, i_copy) % note the order change
            if nargin == 6
                curve_length =  0; % equal to the other joint/dof at base
            end
            if nargin == 7
                i_copy = 1; % results in all mesh nodes having the same equal2 property
            end
            % [i_joint, i_copy, i_dofAxis, 0, curve_length, 0, coeff]
            self.equal2_val{1}{n_coeff}(n_copy,:) = [ones(numel(n_copy),1).*i_joint, ones(numel(n_copy),1).*i_copy, ones(numel(n_copy),1).*i_dofAxis, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*curve_length, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*coeff];
            self.pipe.equal2{1}{n_coeff}(n_copy,:) = [ones(numel(n_copy),1).*i_joint, ones(numel(n_copy),1).*i_copy, ones(numel(n_copy),1).*i_dofAxis, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*curve_length, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*coeff];
            self.i_S = self.i_S + 1;
        end
        
        function self = coefficient_similar_to_dof_at_tip(self, n_coeff, coeff, i_joint, i_dofAxis, i_copy) % note the order change
            if nargin == 5
                i_copy = 1; % results in all mesh nodes having the same equal2 property
            end
            n_copy = 1 : numel(coeff);
            self = element_coefficient_similar_to_dof_at_tip(self, n_copy, n_coeff, coeff, i_joint, i_dofAxis, i_copy);
        end
        
        function self = element_coefficient_similar_to_dof_at_tip(self, n_copy, n_coeff, coeff, i_joint, i_dofAxis, i_copy) % note the order change
            curve_length = nan; % equal to the other joint/dof at tip
            if nargin == 6
                i_copy = 1; % results in all mesh nodes having the same equal2 property
            end
            % [i_joint, i_copy, i_dofAxis, 0, curve_length, 0, coeff]
            self.equal2_val{1}{n_coeff}(n_copy,:) = [ones(numel(n_copy),1).*i_joint, ones(numel(n_copy),1).*i_copy, ones(numel(n_copy),1).*i_dofAxis, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*curve_length, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*coeff];
            self.pipe.equal2{1}{n_coeff}(n_copy,:) = [ones(numel(n_copy),1).*i_joint, ones(numel(n_copy),1).*i_copy, ones(numel(n_copy),1).*i_dofAxis, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*curve_length, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*coeff];
            self.i_S = self.i_S + 1;
        end
        
        function self = coefficient_similar_to_dof_derivative_at_axial_location(self, n_coeff, n_diffOrder, coeff, i_joint, i_dofAxis, curve_length, i_copy) % note the order change
            if nargin == 6
                curve_length =  0; % equal to the other joint/dof at base
            end
            if nargin == 7
                i_copy = 1; % results in all mesh nodes having the same equal2 property
            end
            n_copy = 1 : numel(coeff);
            self = element_coefficient_similar_to_dof_derivative_at_axial_location(self, n_copy, n_coeff, n_diffOrder, coeff, i_joint, i_dofAxis, curve_length, i_copy);
        end
        
        function self = element_coefficient_similar_to_dof_derivative_at_axial_location(self, n_copy, n_coeff, n_diffOrder, coeff, i_joint, i_dofAxis, curve_length, i_copy) % note the order change
            if nargin == 7
                curve_length =  0; % equal to the other joint/dof at base
            end
            if nargin == 8
                i_copy = 1; % results in all mesh nodes having the same equal2 property
            end
            % [i_joint, i_copy, i_dofAxis, 0, curve_length, n_diffOrder, coeff]
            self.equal2_val{1}{n_coeff}(n_copy,:) = [ones(numel(n_copy),1).*i_joint, ones(numel(n_copy),1).*i_copy, ones(numel(n_copy),1).*i_dofAxis, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*curve_length, ones(numel(n_copy),1).*n_diffOrder, ones(numel(n_copy),1).*coeff];
            self.pipe.equal2{1}{n_coeff}(n_copy,:) = [ones(numel(n_copy),1).*i_joint, ones(numel(n_copy),1).*i_copy, ones(numel(n_copy),1).*i_dofAxis, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*curve_length, ones(numel(n_copy),1).*n_diffOrder, ones(numel(n_copy),1).*coeff];
            self.i_S = self.i_S + 1;
        end
        
        function self = coefficient_similar_to_dof_derivative_at_tip(self, n_coeff, n_diffOrder, coeff, i_joint, i_dofAxis, i_copy) % note the order change
            if nargin == 6
                i_copy = 1; % results in all mesh nodes having the same equal2 property
            end
            n_copy = 1 : numel(coeff);
            self = element_coefficient_similar_to_dof_derivative_at_tip(self, n_copy, n_coeff, n_diffOrder, coeff, i_joint, i_dofAxis, i_copy);
        end
        
        function self = element_coefficient_similar_to_dof_derivative_at_tip(self, n_copy, n_coeff, n_diffOrder, coeff, i_joint, i_dofAxis, i_copy) % note the order change
            curve_length = nan ; % equal to the other joint/dof at tip
            if nargin == 7
                i_copy = 1; % results in all mesh nodes having the same equal2 property
            end
            % [i_joint, i_copy, i_dofAxis, 0, curve_length, n_diffOrder, coeff]
            self.equal2_val{1}{n_coeff}(n_copy,:) = [ones(numel(n_copy),1).*i_joint, ones(numel(n_copy),1).*i_copy, ones(numel(n_copy),1).*i_dofAxis, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*curve_length, ones(numel(n_copy),1).*n_diffOrder, ones(numel(n_copy),1).*coeff];
            self.pipe.equal2{1}{n_coeff}(n_copy,:) = [ones(numel(n_copy),1).*i_joint, ones(numel(n_copy),1).*i_copy, ones(numel(n_copy),1).*i_dofAxis, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*curve_length, ones(numel(n_copy),1).*n_diffOrder, ones(numel(n_copy),1).*coeff];
            self.i_S = self.i_S + 1;
        end
        
        function self = set_rom_coefficient(self, n_coeff, value)
            n_segm = 1 ;
            n_copy = 1 : numel(value);
            self = element_set_rom_segment_coefficient(self, n_copy, n_segm, n_coeff, value);
        end
        
        function self = set_rom_segment_coefficient(self, n_segm, n_coeff, value)
            n_copy = 1 : numel(value);
            self = element_set_rom_segment_coefficient(self, n_copy, n_segm, n_coeff, value);
        end
        
        function self = element_set_rom_coefficient(self, n_copy, n_coeff, value)
            n_segm = 1 ;
            self = element_set_rom_segment_coefficient(self, n_copy, n_segm, n_coeff, value);
        end
        
        function self = element_set_rom_segment_coefficient(self, n_copy, n_segm, n_coeff, value)
            % [nan, 0, 0, 0, value, 0, 1]
            for i_segm = n_segm
                for i_coeff = n_coeff
                    self.equal2_val{i_segm}{i_coeff}(n_copy,:) = [ones(numel(n_copy),1).*nan, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*value, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*1]; % ground fixed
                    self.pipe.equal2{i_segm}{i_coeff}(n_copy,:) = [ones(numel(n_copy),1).*nan, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*value, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*1];
                end
            end
            self.i_S = self.i_S + 1;
        end
        
        function self = base_value(self, value) % changes spring too
            n_copy = 1 : numel(value);
            self = element_base_value(self, n_copy, value);
        end
        
        function self = element_base_value(self, n_copy, value) % changes spring too
            % [nan, 0, 0, 0, value, 0, 1]
            self.equal2_val{1}{1}(n_copy,:) = [ones(numel(n_copy),1).*nan, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*value, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*1]; % ground fixed
            self.pipe.equal2{1}{1}(n_copy,:) = [ones(numel(n_copy),1).*nan, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*value, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*1];
            % self.pipe.spring.equal2(:,:,1) = [nan, 0, 0, 0, value, 0, 1];
            self.i_S = self.i_S + 1;
        end        
        
        function self = base_value_at_axial_location(self, value, curve_length) % changes spring too
            n_copy = 1 : numel(value);
            self = element_base_value_at_axial_location(self, n_copy, value, curve_length);
        end
        
        function self = element_base_value_at_axial_location(self, n_copy, value, curve_length) % changes spring too
            % [nan, 0, 0, 0, value, 0, 1]
            self.equal2_val{1}{1}(n_copy,:) = [ones(numel(n_copy),1).*nan, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*value, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*1]; % ground fixed
            self.pipe.equal2{1}{1}(n_copy,:) = [ones(numel(n_copy),1).*nan, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*value, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*1];
            % self.pipe.spring.equal2(:,:,1) = [nan, 0, 0, 0, value, 0, 1];
            self.rom_offset_val = -curve_length;
            self.pipe.rom_offset = -curve_length;
            self.i_S = self.i_S + 1;
        end      
        
        function self = base_director(self, director) % changes spring too
            n_copy = 1 : numel(director);
            self = element_base_director(self, n_copy, director);
        end
        
        function self = element_base_director(self, n_copy, director) % changes spring too
            % [nan, 0, 0, 0, director, 0, 1]
            self.equal2_val{1}{2}(n_copy,:) = [ones(numel(n_copy),1).*nan, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*director, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*1];
            self.pipe.equal2{1}{2}(n_copy,:) = [ones(numel(n_copy),1).*nan, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*director, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*1];
            % self.pipe.spring.equal2(:,:,2) = [nan, 0, 0, 0, director, 0, 1];
            self.i_S = self.i_S + 1;
        end
        
        function self = base_director_at_axial_location(self, director, curve_length) % changes spring too
            n_copy = 1 : numel(director);
            self = element_base_director_at_axial_location(self, n_copy, director, curve_length);
        end
        
        function self = element_base_director_at_axial_location(self, n_copy, director, curve_length) % changes spring too
            % [nan, 0, 0, 0, director, 0, 1]
            self.equal2_val{1}{2}(n_copy,:) = [ones(numel(n_copy),1).*nan, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*director, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*1];
            self.pipe.equal2{1}{2}(n_copy,:) = [ones(numel(n_copy),1).*nan, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*director, ones(numel(n_copy),1).*0, ones(numel(n_copy),1).*1];
            % self.pipe.spring.equal2(:,:,2) = [nan, 0, 0, 0, director, 0, 1];
            self.rom_offset_val = -curve_length;
            self.pipe.rom_offset = -curve_length;
            self.i_S = self.i_S + 1;
        end
        
        function self = axial_offset(self, offset) % doesn't changes spring_offset
            self.rom_offset_val = offset;
            self.pipe.rom_offset = offset;
            % self.pipe.spring.rom_offset = offset;
            self.i_S = self.i_S + 1;
        end
        
        function self = initial_value(self, init)
            self.init_val = init;
            self.pipe.init = init;
            self.i_S = self.i_S + 1;
        end
        
        function self = initial_value_from_kinematic_constraint(self)
            self.init_val = nan;
            self.pipe.init = nan;
            self.i_S = self.i_S + 1;
        end
        
        function self = initial_value_axial_locations(self,init_s)
            self.init_s_val = init_s;
            self.pipe.init_s = init_s;
            self.i_S = self.i_S + 1;
        end
        
        function spring = parallel_spring(self)
            self.the_spring = spring_builder(self);
            spring = self.the_spring;
            self.i_S = self.i_S + 1;
        end
        
        function self = parallel_elements_active_direction(self,dir)
            self.active_direction = dir;
            self.pipe.dir = dir;
            self.i_S = self.i_S + 1;
        end
        
        function damper = parallel_damper(self)
            self.the_damping = damper_builder(self);
            damper = self.the_damping;
            self.i_S = self.i_S + 1;
        end
        
        function self = direct_input(self, input_type, force_or_acc_val, vel_val, pos_val)
            switch input_type
                case 'force'
                    self.input_val = force_or_acc_val;
                    self.pipe.input = force_or_acc_val;
                case 'trajectory'
                    self.control_acc_val = force_or_acc_val;
                    self.pipe.control_acc = force_or_acc_val;
                    self.control_vel_val = vel_val;
                    self.pipe.control_vel = vel_val;
                    self.control_vel_val = pos_val;
                    self.pipe.control_vel = pos_val;
                    self.fixed_val = 1; % constraint: with Lagrange multiplier
                    self.pipe.fixed = 1;
                otherwise
                    self.input_val = force_or_acc_val;
                    self.pipe.input = force_or_acc_val;
            end
            self.i_S = self.i_S + 1;
        end
        
        function self = unknown_direct_input(self)
            self = self.direct_input('force', inf);
        end
        
        function self = direct_input_at_coefficient(self, n_coeff, input_type, force_or_acc_val, vel_val, pos_val)
            switch input_type
                case 'force'
                    self.input_val(:,n_coeff) = force_or_acc_val;
                    self.pipe.input(:,n_coeff) = force_or_acc_val;
                case 'trajectory'
                    self.control_acc_val(:,n_coeff)  = force_or_acc_val;
                    self.pipe.control_acc(:,n_coeff)  = force_or_acc_val;
                    self.control_vel_val(:,n_coeff)  = vel_val;
                    self.pipe.control_vel(:,n_coeff)  = vel_val;
                    self.control_vel_val(:,n_coeff)  = pos_val;
                    self.pipe.control_vel(:,n_coeff)  = pos_val;
                    self.fixed_val(:,n_coeff) = 1; % constraint: with Lagrange multiplier
                    self.pipe.fixed(:,n_coeff) = 1;
                otherwise
                    self.input_val(:,n_coeff) = force_or_acc_val;
                    self.pipe.input(:,n_coeff) = force_or_acc_val;
            end
            self.i_S = self.i_S + 1;
        end
        
        function self = unknown_direct_input_at_coefficient(self, n_coeff)
            self = self.direct_input_at_coefficient(n_coeff, 'force', inf);
        end
        
        function self = desired_state_trajectory(self, desired_acc, desired_vel, desired_pos, init_pos_error)
            self.control_acc_val = desired_acc;
            self.pipe.control_acc = desired_acc;
            self.control_vel_val = desired_vel;
            self.pipe.control_vel = desired_vel;
            self.control_pos_val = desired_pos;
            self.pipe.control_pos = desired_pos;
            self.control_err0_val = init_pos_error;
            self.pipe.control_err0 = init_pos_error;
            self.fixed_val = inf; % desired/known: no Lagrange multiplier
            self.pipe.fixed = inf;
            self.i_S = self.i_S + 1;
        end
        
        function self = desired_state_trajectory_at_coefficient(self, n_coeff, desired_acc, desired_vel, desired_pos, init_pos_error)
            self.control_acc_val(:,n_coeff)  = desired_acc;
            self.pipe.control_acc(:,n_coeff)  = desired_acc;
            self.control_vel_val(:,n_coeff)  = desired_vel;
            self.pipe.control_vel(:,n_coeff)  = desired_vel;
            self.control_vel_pos(:,n_coeff)  = desired_pos;
            self.pipe.control_pos(:,n_coeff)  = desired_pos;
            self.control_vel_err0(:,n_coeff)  = init_pos_error;
            self.pipe.control_err0(:,n_coeff)  = init_pos_error;
            self.fixed_val(:,n_coeff) = inf; % desired/known: no Lagrange multiplier
            self.pipe.fixed(:,n_coeff) = inf;
            self.i_S = self.i_S + 1;
        end
        
        function self = state_controller_gains(self, k0_vec, k1_vec, k_slide_vec, l_slide_vec)
            self.pipe.gains.k0 = k0_vec;
            self.pipe.gains.k1 = k1_vec;
            if nargin > 4
                self.pipe.gains.k_slide = k_slide_vec;
                self.pipe.gains.l_slide = l_slide_vec;
            else
                self.pipe.gains.k_slide =  0 * p_vec;
                self.pipe.gains.l_slide =  0 * p_vec;
            end
            self.gains_val = self.pipe.gains;
            self.i_S = self.i_S + 1;
        end
        
        function self = state_controller_gains_at_coefficient(self, n_coeff, k0_vec, k1_vec, k_slide_vec, l_slide_vec)
            self.pipe.gains.k0(:,n_coeff) = k0_vec;
            self.pipe.gains.k1(:,n_coeff) = k1_vec;
            if nargin > 5
                self.pipe.gains.k_slide(:,n_coeff) = k_slide_vec;
                self.pipe.gains.l_slide(:,n_coeff) = l_slide_vec;
            else
                self.pipe.gains.k_slide(:,n_coeff) =  0 * p_vec;
                self.pipe.gains.l_slide(:,n_coeff) =  0 * p_vec;
            end
            self.gains_val = self.pipe.gains;
            self.i_S = self.i_S + 1;
        end
                
        function self = rom_order(self, order)
            self.rom_order_val = order;
            i = numel(self.source.source.pipe.rom.order);
            if i < self.q_index
                self.source.source.pipe.rom.order(:, i+1 : self.q_index) = nan;
            end
            self.source.source.pipe.rom.order(self.q_index) = order;
            self.i_S = self.i_S + 1;
        end
        
        function self = not_rom(self)
            self.rom_order_val = 0;
            self.source.source.pipe.rom.order(self.q_index) = 0;
            self.i_S = self.i_S + 1;
        end
        
        function self = initial_value_fit_type(self, type, knots) % 'polynomial', 'spline_piecewise', 'spline_logistic_func'
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
            end
            self.fit_type_val = [type, knots];
            self.pipe.fit_type = [type, knots];
            self.i_S = self.i_S + 1;
        end
        
        function self = spline_continuity_order(self, value)
            self.spc_order = value;
            self.pipe.spc_order = value;
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
                self.source.source.pipe.dof(self.q_index) = self.pipe; % to be copied in joint struct, not tr
                self.source.i_S = 1 ; % reset i_S of the source object to start executing from 1st line of DSL input % reset i_S of the source object
                [varargout{1:nargout}] = builtin('subsref', self.source, S(2*self.i_S-1:end)); % pass the unexecuted lines to the source object
            end
        end
        
    end
end
