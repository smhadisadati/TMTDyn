function X = pw2logF( X )
% convert piecewise to logistic function switches for smaller m_function files

global pw2lg par_sym par_var
X = sym( X ) ;

% % simplify piesewise function conditions by removing unnecessary (not possible) ones based on par.var
% X = simplify_piecewise( X , par_sym , par_var ) ;

if pw2lg % only if piecewise to logistic function conversion is selected
    
    [ a , b ] = size( X ) ; % matric dimensions
    
    for i = 1 : a % itterate rows
        
        for j = 1 : b % itterate columns
            
            x = children( X(i,j) ) ; % elements of piecewise function
            
            [ n_cond , n_col ] = size( x ) ; % piecewise function children elements

            if n_cond > 1 && n_col == 2 % it is a piecewise variable needing conversion if childs has two columns and more than 1 row!         

                y = x{1,1} ;
                
                for k = 2 : n_cond
                                            
                    y = y + x{k,1} ; % construct single term function
                                           
                end
                
                X(i,j) = smplfy( y ) ;
                
            end
            
        end
        
    end
        
end