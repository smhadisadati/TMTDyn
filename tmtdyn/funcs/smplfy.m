function out = smplfy( in )
global par_simplify par_sym par_var

% simplify only symbolic parameters
if isa( in, 'sym' ) 
        
    % simplify piesewise function conditions by removing unnecessary (not possible) ones based on par.var
    in = simplify_piecewise( in , par_sym , par_var ) ;
    
    % simplify according to set instructions
    switch par_simplify(1)
        case 1 % 'symbolic'
            out = simplify( sym( in ) , 'Criterion' , 'preferReal' , 'Seconds' , par_simplify(2) ) ;
        case 2 % 'decimal'
            if isnan( par_simplify(2) )
                out = vpa( in ) ;
            else
                out = vpa( in , par_simplify(2) ) ;
            end
        case 12 % 'symbolic_decimal'
            out = simplify( vpa( in ) , 'Criterion' , 'preferReal' , 'Seconds' , par_simplify(2) ) ;
        otherwise
            out = in ;
    end
    % if ~isempty( symvar( out ) )
    %     assume( out , 'real' ) ;
    % end
else
    out = in ;
end


