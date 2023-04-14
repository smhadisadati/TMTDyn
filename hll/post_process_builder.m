classdef post_process_builder < handle
    
    properties (GetAccess = public, SetAccess = private)
        source ;
        
        animation ;
		animate_frame ;
        video ;
        anim_line_type ;
        fps_val ;
        postprocess ;
        plot_points_val ;
        anim_edge_val ;
        animation_report_time ;
        report_number ;
    end

    properties (GetAccess = public, SetAccess = public)
        i_S = 1; % counter for executed functions of the full DDL input in the current (this) object
    end
    
    methods
        function self = post_process_builder(source)
            self.source = source;
        end
        
        function self = animate(self, type, anim_frame, fps, axis_edges, circle_edges) % type = {'line', 'tube'}, anim_frame = {null 'none', 'show_frame', 'side_views', 'show_frame_side_views'}
			% animation on (1) or off (0)
            self.animation = 1;
            self.source.pipe.anim = 1;
            if nargin < 2
                type = 0; % simple line
            end
            switch type
                case 'line'
                    self.anim_line_type = 0;
                case 'tube'
                    self.anim_line_type = 1;
            end
            self.source.pipe.anim_line = self.anim_line_type;
            if nargin < 3
                anim_frame = 0; % nothing to show
            end
            switch anim_frame
                case 'show_frame'
					self.animate_frame = 1;
				case 'side_views'
					self.animate_frame = 2;
				case 'show_frame_side_views'
					self.animate_frame = 12;
				otherwise
					self.animate_frame = 0;
			end	
            self.source.pipe.anim_frame = self.animate_frame;
			if nargin > 3
                self.fps_val = fps;
                self.source.pipe.fps = fps;
			end
			if nargin > 4
                self.plot_points_val = axis_edges;
                self.source.pipe.n_animpoints = axis_edges;
			end
			if nargin > 5
                self.anim_edge_val = circle_edges;
                self.source.pipe.anim_edge = circle_edges;
			end
            self.i_S = self.i_S + 1;
        end
        
        function self = axis_edges(self,axis_edges)
			% number of back bone curve edges
            self.plot_points_val = axis_edges;
            self.source.pipe.n_animpoints = axis_edges;
            self.i_S = self.i_S + 1;
        end
        
        function self = cross_section_edges(self,circle_edges)
			% number of anim points
            self.anim_edge = circle_edges;
            self.source.pipe.anim_edge = circle_edges;
            self.i_S = self.i_S + 1;
        end
        
        function self = report_time_step(self,report_time)
			% anim report time, if 'inf' then (tf-t0)/dt_animStep(2)
            self.animation_report_time = report_time;
            self.report_number = 0;
            self.source.pipe.dt_anim_rep = [report_time, 0];
            self.i_S = self.i_S + 1;
        end
        
        function self = number_of_reports(self,report_number)
			% anim report time, if 'inf' then (tf-t0)/dt_animStep(2)
            self.animation_report_time = inf;
            self.report_number = report_number;
            self.source.pipe.dt_anim_rep = [inf, report_number];
            self.i_S = self.i_S + 1;
        end
        
        function self = record_video(self)
			% save movie[ ~ , rks , par ] = AnimEOM_mex( t , z , par );
            self.video = 1;
            self.source.pipe.movie = 1;
            self.i_S = self.i_S + 1;
        end
        
        function self = run_user_code(self)
			% post-process using user code in post_proc.m
            self.postprocess = 1 ;
            self.source.pipe.post_process = 1;
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
				self.source.i_S = 1 ; % reset i_S of the source object to start executing from 1st line of DSL input
                [varargout{1:nargout}] = builtin('subsref', self.source, S(2*self.i_S-1:end)); % pass the unexecuted lines to the source object
            end
        end
    end
end
