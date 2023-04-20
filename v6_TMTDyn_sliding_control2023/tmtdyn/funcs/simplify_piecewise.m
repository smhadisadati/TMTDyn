% simplify piecewise multiplications
function out = simplify_piecewise( in , par_sym , par_var )
[ row , col ] = size( in ) ;
for i_row = 1 : row
    for i_col = 1 : col
        childs = children( in(i_row,i_col) ) ; % condition switches based on 1st copy of 1st dof (all dofs should have same condition switches)
        [ n_cond , n_col ] = size( childs ) ; % number of conditions
        if n_cond > 1 && n_col == 2 % it is a piecewise variable needing simplification if childs has two columns and more than 1 row!         
            out(i_row,i_col) = sym( nan ) ; % initiate output element with nan (to be handled later)
            for i_cond = 1 : n_cond
                if isa( childs{i_cond,2} , 'sym' )
                    out_test = piecewise( childs{i_cond,2} , 1 ) ; % test the condition
                    isValid = simplify( subs( out_test , par_sym , par_var ) ) ; % test for valid conditions
                    if ~isnan( isValid ) % only valid conditions result in non-nan
                        if isnan( out(i_row,i_col) ) % first piecewise terms
                            out(i_row,i_col) = piecewise( childs{i_cond,2} , childs{i_cond,1} ) ;
                        else % concatanate other piecewise terms
                            out(i_row,i_col) = piecewise( childs{i_cond,2} , childs{i_cond,1} , out(i_row,i_col) ) ;
                        end
                    end
                end
            end
        else            
            out(i_row,i_col) = in(i_row,i_col) ; % default for non-piecewise elements
        end
    end
end