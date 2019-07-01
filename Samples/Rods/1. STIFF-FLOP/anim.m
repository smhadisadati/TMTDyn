%% Animation:
% ====================================================

function [ r_anim , rjtip , rks , par ] = anim( t , z , par )
fprintf( 'animation... \n' )
par.elapsed_time = [ par.elapsed_time toc( par.timer ) ] ;
toc( par.timer )

% Data:
sk = par.skip ;
p = par.pause ;
eps = 1e-6 ;

vars = par.var ;
[ par.n_mass_anim , ~ ] = size ( rjtipF_mex( vars , z(1,:) , 0 ) ); % number of bodies
[ par.n_ks_anim , ~ ] = size ( rksF_mex( vars , z(1,:) , 0 ) ); % number of spring/dampers
ss = length ( t ) ; % simulation steps

% temp1 = rjtipF_mex( vars , z(i,:) , 1 ) ;
% if ~ismember( nan , temp1(:,4) ) % no ROM
% 	par.n_animpoints = 1 ;
% end

for i = 1 : ss
    temp2 = rksF_mex( vars , z(i,:) , 0 ) ;
    for i_s = 1 : par.n_animpoints + 1
        dl = ( 1 - eps ) / par.n_animpoints * ( i_s - 1 ) + eps ;
        for i_sd = 1 : par.n_ks_anim
            r_anim.sprdmp(i_sd).r(i_s,:,i) = ( temp2(i_sd,4:6) - temp2(i_sd,1:3) ) * dl + temp2(i_sd,1:3) ;
        end
        temp1 = rjtipF_mex( vars , z(i,:) , dl ) ;
        for i_m = 1 : par.n_mass_anim
            if ~isnan( temp1(i_m,4) ) % rigid
                r_anim.mass(i_m).r(i_s,:,i) = ( temp1(i_m,4:6) - temp1(i_m,1:3) ) * dl + temp1(i_m,1:3) ;
            else % ROM
                r_anim.mass(i_m).r(i_s,:,i) = temp1(i_m,1:3) ;
            end
        end
    end
end

rjtip = zeros ( par.n_mass_anim , 6 , ss );
rks = zeros ( par.n_ks_anim , 6 , ss );
for i_m = 1 : par.n_mass_anim
    rjtip(i_m,:,:) = [ r_anim.mass(i_m).r(1,1,:)   r_anim.mass(i_m).r(1,2,:)   r_anim.mass(i_m).r(1,3,:) , ...
                            r_anim.mass(i_m).r(end,1,:) r_anim.mass(i_m).r(end,2,:) r_anim.mass(i_m).r(end,3,:) ] ;
end

if par.anim ~= 1 % anim. on/off
    return ;
end

% Windows set:
figure( par.fig.anim ) ; % clf ;

% axis tight
axis equal
view( [ -1 -1 1 ] ) ;
xlabel('x [m]') , ylabel('y [m]') , zlabel('z [m]')
set(gcf,'Color',[1,1,1])

for i_sd = 1 : par.n_ks_anim
    rks(i_sd,:,:) = [ r_anim.sprdmp(i_sd).r(1,1,:)   r_anim.sprdmp(i_sd).r(1,2,:)   r_anim.sprdmp(i_sd).r(1,3,:) , ...
                           r_anim.sprdmp(i_sd).r(end,1,:) r_anim.sprdmp(i_sd).r(end,2,:) r_anim.sprdmp(i_sd).r(end,3,:) ] ;
end
if par.n_mass_anim == 0 ; rjtip = rks ; end
if par.n_ks_anim == 0 ; rks = rjtip ; end
window_xmin = min( [ reshape( rjtip(:,[ 1 4 ],:) , [ 1 numel( rjtip(:,[ 1 4 ],:) ) ] ) reshape( rks(:,[ 1 4 ],:) , [ 1 numel( rks(:,[ 1 4 ],:) ) ] ) ] );
window_xmax = max( [ reshape( rjtip(:,[ 1 4 ],:) , [ 1 numel( rjtip(:,[ 1 4 ],:) ) ] ) reshape( rks(:,[ 1 4 ],:) , [ 1 numel( rks(:,[ 1 4 ],:) ) ] ) ] );
window_ymin = min( [ reshape( rjtip(:,[ 2 5 ],:) , [ 1 numel( rjtip(:,[ 1 4 ],:) ) ] ) reshape( rks(:,[ 2 5 ],:) , [ 1 numel( rks(:,[ 2 5 ],:) ) ] ) ] );
window_ymax = max( [ reshape( rjtip(:,[ 2 5 ],:) , [ 1 numel( rjtip(:,[ 1 4 ],:) ) ] ) reshape( rks(:,[ 2 5 ],:) , [ 1 numel( rks(:,[ 2 5 ],:) ) ] ) ] );
window_zmin = min( [ reshape( rjtip(:,[ 3 6 ],:) , [ 1 numel( rjtip(:,[ 1 4 ],:) ) ] ) reshape( rks(:,[ 3 6 ],:) , [ 1 numel( rks(:,[ 3 6 ],:) ) ] ) ] );
window_zmax = max( [ reshape( rjtip(:,[ 3 6 ],:) , [ 1 numel( rjtip(:,[ 1 4 ],:) ) ] ) reshape( rks(:,[ 3 6 ],:) , [ 1 numel( rks(:,[ 3 6 ],:) ) ] ) ] );

ad = 1.2 * max( abs ( [ window_xmin-window_xmax window_ymin-window_ymax window_zmin-window_zmax ] / 2 ) ) ;
axis_limits =[ window_xmin+window_xmax window_xmin+window_xmax ...
    window_ymin+window_ymax window_ymin+window_ymax ...
    window_zmin+window_zmax window_zmin+window_zmax ] / 2 ...
    + [ -1 1 -1 1 -1 1 ] * ad ;

% Animation:
clr = { 'blue' , 'red' , 'green' , 'magenta' , 'cyan' , 'black' };

for n_t = 1 : sk : ss % update the points
    
    % masses init.
    for i = 1 : par.n_mass_anim % creat lines ending to each joint
        plot3( r_anim.mass(i).r(:,1,n_t) , r_anim.mass(i).r(:,2,n_t) , r_anim.mass(i).r(:,3,n_t) , 'LineWidth' , 2 ,'Color' , clr{mod(i,6)+1} );
        hold on
    end
    
    % spring/dampers init.
    for i = 1 : par.n_ks_anim % creat lines ending to each joint
        plot3( r_anim.sprdmp(i).r(:,1,n_t) , r_anim.sprdmp(i).r(:,2,n_t) , r_anim.sprdmp(i).r(:,3,n_t) , 'LineStyle' , ':' , 'LineWidth' , 2 ,'Color' , clr{mod(i,6)+1} );
        hold on
    end
    title( t(n_t) )
    axis ( axis_limits ); xlabel( 'x[m]' ) ; ylabel( 'y[m]' ) ; zlabel( 'z[m]' ) ;
    hold off
    
    if par.movie == 1 ; writeVideo( par.vid , getframe( gcf ) ) ; end
    pause( p );
    
end


