function out = sprse( in )
global par_sparse
if par_sparse
    [row, vec, val] = find( in ) ;
    out = [row, vec, val] ;    
    if isempty( out )
        out = sym( [ 1, 1, 0 ] ) ;
    end
else
    out = in ;
end
