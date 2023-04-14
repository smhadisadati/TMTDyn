classdef eom_derive_builder
    
    properties (GetAccess = public, SetAccess = private)
        the_source;
               
        derive;
        collection_type;
        derive_mex;
        eom_optimize;
    end
    
    methods
        function self = eom_derive_builder(source)
            self.the_source = source;
            self.derive = 1;
            source.pipe.derive = 1;
        end
        
        function self = derive_collect(self,collection_type)
            self.collection_type = collection_type;
            self.the_source.pipe.derive_collect = collection_type;
        end
        
        function self = mex(self)
            self.collection_type = 1 ;
            self.derive_mex = 1 ;
            self.the_source.pipe.derive_collect = 1;
            self.the_source.pipe.derive_mex = 1;
        end
        
        function self = optimize(self)
            self.eom_optimize = 1;
            self.the_source.pipe.opv = 1;
        end
        
        function source = end(self)
            source = self.the_source;
        end
    end
end
