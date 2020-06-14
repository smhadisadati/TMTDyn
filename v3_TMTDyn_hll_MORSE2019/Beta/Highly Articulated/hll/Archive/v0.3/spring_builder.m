classdef spring_builder < handle
    
    properties (GetAccess = public, SetAccess=private)
        the_source;
        pipe;
        
        coeff_val ;
        init_val ;
        compression_val ;
    end
    
    methods
        function self = spring_builder(source)
            self.the_source = source;
        end
        
        function self = coeff(self,coeff)
            self.coeff_val = coeff ;
            self.pipe.coeff = coeff;
        end
        
        function self = init(self,init)
            self.init_val = init ;
            self.pipe.init_val = init;
        end

        function self = init_from_configuration(self)
            self.init_val = nan ;
            self.pipe.init_val = nan;
        end
        
        function self = compr(self,compr)
            self.compression_val = compr ;
            self.pipe.compr = compr;
        end
        
        function varargout = subsref (self, S)
            try
                [varargout{1:nargout}] = builtin('subsref', self, S);
            catch
            	source.pipe.spring = self.pipe;
                [varargout{1:nargout}] = builtin('subsref', self.source, S);
            end
        end
        
    end
end
