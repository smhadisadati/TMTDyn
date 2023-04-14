classdef simulation_builder
    
    properties (GetAccess = public, SetAccess = private)
        name ;
        tmtdyn ;
        
        bodies = [];
    end
    
    methods
        function self = system_builder(tmtdyn, name)
            self.name = name;
            self.tmtdyn = tmtdyn;
        end
        
        function body = body(self)
            body = body_builder(self);
            self.bodies = [ self.bodies body ] ;
        end
        
		% reference to other elements of tmtdyn
		fucntion the_world = world(self)
            the_world = self.tmtdyn.world();
		end

		fucntion the_robot = robot(self)
            the_robot = self.tmtdyn.robot();
		end
     end
end
