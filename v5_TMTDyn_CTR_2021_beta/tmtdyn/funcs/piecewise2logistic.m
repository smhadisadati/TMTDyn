function X = piecewise2logistic( X )

global pw2lg

if pw2lg % only if piecewise to logistic function conversion is selected
    
    [ a , b ] = size( X ) ; % matric dimensions
    
    for i = 1 : a % itterate rows
        
        for j = 1 : b % itterate columns
            
            try
                x = children( X(i,j) ) ; % elements of piecewise function
            catch % if there is no children
                continue
            end
            
            [ c , ~ ] = size( x ) ; % piecewise function children elements
            y = x{1,1} ;
            
            for k = 2 : c
                
                if x{k,2} ~= symtrue % except symtrue (otherwise) case
                    
                    y = y + x{k,1} ; % construct single term function
                    
                end
                
            end
            
            X(i,j) = y ;
            
        end
        
    end
    
end