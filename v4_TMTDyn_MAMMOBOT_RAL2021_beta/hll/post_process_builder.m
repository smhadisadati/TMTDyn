classdef post_process_builder < handle
    
    properties (GetAccess = public, SetAccess = private)
        source ;
        
        animation ;
		animate_frame
        video ;
        postprocess ;
        plot_points_val ;
        animation_report_time ;
        report_number ;
    end

    properties (GetAccess = public, SetAccess = public)
        i_S = 1;
    end
    
    methods
        function self = post_process_builder(source)
            self.source = source;
        end
        
        function self = animate(self, anim_frame)
			% animation on (1) or off (0)
            self.animation = 1;
            self.source.pipe.anim = 1;
			if nargin == 1
				anim_frame = 0;
			end
			switch anim_frame
				case 'show_frame'
					self.animate_frame = 1;
					self.source.pipe.anim_frame = 1;
				otherwise
					self.animate_frame = 0;
					self.source.pipe.anim_frame = 0;
			end	
            self.i_S = self.i_S + 1;
        end
        
        function self = plot_points(self,anim_points)
			% number of anim points
            self.plot_points_val = anim_points;
            self.source.pipe.n_animpoints = anim_points;
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
                [varargout{1:nargout}] = builtin('subsref', self, S);
            catch e
                if ~ strcmp (e.identifier, 'MATLAB:noSuchMethodOrField')
                    rethrow(e)
                end
                % e.message
				self.source.i_S = 1 ; % reset i_S of the source object
                [varargout{1:nargout}] = builtin('subsref', self.source, S(2*self.i_S-1:end));
            end
        end
    end
end
