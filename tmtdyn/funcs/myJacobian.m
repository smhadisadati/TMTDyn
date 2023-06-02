function J = myJacobian( f , x )
global q_numdiff

if q_numdiff == 0 % analytical differentiation
    % a = numel( f ) ;
    % b = numel( x ) ;

    % % half parallel
    % J = sym( zeros( a , b ) ) ;
    % parfor i = 1 : a
    %     J(i,:) = jacobian( f(i) , x ) ;
    % end

    % % full parallel
    % ab = a * b ;
    % temp = sym( zeros( 1 , a * b ) ) ;
    % parfor ij = 1 : ab
    %     i = floor( ( ij - 1 ) / b ) + 1 ;
    %     j = mod( ij , b ) ; if j == 0 ; j = b ; end 
    %     temp(ij) = diff( f(i) , x(j) ) ;
    % end
    % J = reshape( temp , a , b ) ;

    % no change
    J = jacobian( f, x ) ;

    % simplify output
    J = smplfy( J ) ;

else % numerical differentiation
    dx = q_numdiff ;
    for i = 1 : numel( x )
        J(:,i) = ( subs( f , x(i) , x(i) + dx ) - subs( f , x(i) , x(i) - dx ) ) / 2 / dx ;
        % J(:,i) = ( subs( f , x(i) , x(i) * ( 1 + dt ) ) - subs( f , x(i) , x(i) * ( 1 - dt ) ) ) / 2 / dt / x(i) ;
    end
    
end