function y = smoothV( x , step )

% y = x ; return

if nargin < 2
    step = 10 ;
end

[ ~ , n ] = size( x ) ;
for i = 1 : n
    y(:,i) = smooth( x(:,i) , step , 'moving' ) ;
end