classdef world_builder
    properties (GetAccess=public, SetAccess=private)
        tmtdyn;
        g_vector;
    end
    
    methods
        function self = world_builder(tmtdyn)
            self.tmtdyn = tmtdyn;
			self.g_vector = [ 0 , 0 , 0 ] ;
        end
        
        function self = g(self, g_vector) 
            self.g_vector = g_vector;
        end

		% reference to other elements of tmtdyn
		fucntion the_robot = robot(self)
            the_robot = self.tmtdyn.robot();
		end

		fucntion the_simulation = simulation(self)
            the_simulation = self.tmtdyn.simulation();
		end
        
    end
end
