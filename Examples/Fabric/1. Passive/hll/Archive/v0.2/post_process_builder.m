classdef post_process_builder
    
    properties (GetAccess = public, SetAccess = private)
        the_source ;
        
        animation ;
        video ;
        postprocess ;
        plot_points_val ;
        animation_report_time ;
        report_number ;
    end
    
    methods
        function self = post_process_builder(source)
            self.the_source = source;
        end
        
        function self = animate(self)
            self.animation = 1;
            self.the_source.pipe.Anim = 1;
        end
        
        function self = plot_points(self,anim_points)
            self.plot_points_val = anim_points;
            self.the_source.pipe.n_animpoints = anim_points;
        end
        
        function self = report_time_step(self,report_time)
            self.animation_report_time = report_time ;
            self.the_source.pipe.dt_anim_rep(1) = report_time;
        end
        
        function self = number_of_reports(self,report_number)
            self.report_number = report_number ;
            self.the_source.pipe.dt_anim_rep(2) = report_number;
        end
        
        function self = record_video(self)
            self.video = 1;
            self.the_source.pipe.movie = 1;
        end
        
        function self = run_user_code(self)
            self.postprocess = 1 ;
            self.the_source.pipe.post_process = 1;
        end
        
        function source = end(self)
            source = self.the_source;
        end
    end
end
