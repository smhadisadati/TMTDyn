%% Animation:
% ====================================================

function rjtip = AnimEOM_G ( q , u , t , z , par )

% Data:
sk = par.skip ;
p = par.pause ;
qu = [ q , u ];

vars = par.symV ;
[ n , ~ ] = size ( rjtipF( vars , z(1,:) ) ); % number of bodies
ss = length ( t ); % simulation steps
sa = floor ( ( ss - 1 ) / sk ) + 2; % animation steps
rjtip = zeros ( n , 6 , sa );
parfor i = 1 : ss
    rjtip(:,:,i) = rjtipF( vars , z(i,:) ) ;
end

rjtip(:,:,end) = rjtipF( vars , z(end,:) ) ; % last point correctin!!!
rjtip = double ( rjtip );

% Windows set:
figure ; clf

window_xmin = min ( min ( rjtip(:,4,:) ) );
window_xmax = max ( max ( rjtip(:,4,:) ) );
window_ymin = min ( min ( rjtip(:,5,:) ) );
window_ymax = max ( max ( rjtip(:,5,:) ) );
window_zmin = min ( min ( rjtip(:,6,:) ) );
window_zmax = max ( max ( rjtip(:,6,:) ) );

ad = max( abs ( [ window_xmin window_xmax window_ymin window_ymax window_zmin window_zmax ] ) );

axis('equal')
axis ( [ window_xmin window_xmax window_ymin window_ymax window_zmin window_zmax ] ...
    + [ -ad ad -ad ad -ad ad ] );
xlabel('x [m]') , ylabel('y [m]') , zlabel('z [m]')

set(gcf,'Color',[1,1,1])


% Animation:
% does not draw the last body itself

clr = { 'blue' , 'red' , 'green' , 'magenta' , 'cyan' , 'yellow' , 'black' };

for i = 1 : n % creat lines ending to each joint

		xs = [ rjtip(i,1,1) , rjtip(i,4,1) ];
		ys = [ rjtip(i,2,1) , rjtip(i,5,1) ];
		zs = [ rjtip(i,3,1) , rjtip(i,6,1) ];
        
    if xs(1) - xs(2) ~= 0 || ys(1) - ys(2) ~= 0 || zs(1) - zs(2) ~= 0      
        ln(i) = line ( xs , ys , zs , ...
           'linewidth' , 2 , 'erase' , 'xor' ,'color' , clr{i-floor(i/8)*7} );    
    end

end

for i1 = 1 : sk : ss % update the points
    
    title( t(i1) );
    
    for i = 1 : n
        
        xs = [ rjtip(i,1,i1) , rjtip(i,4,i1) ];
        ys = [ rjtip(i,2,i1) , rjtip(i,5,i1) ];
        zs = [ rjtip(i,3,i1) , rjtip(i,6,i1) ];
		
        if xs(1) - xs(2) ~= 0 || ys(1) - ys(2) ~= 0 || zs(1) - zs(2) ~= 0            
            set( ln(i) , 'XData' , xs , 'YData' , ys , 'ZData' , zs );
        end
        
    end
            
    drawnow update
%     if mod( i1 - 1 , 100 ) == 0 ; pause ; end
    pause( p );

end


