%% Animation:
% ====================================================

function [ r_anim , rjtip , rks , Qjtip , Qks , par ] = anim( t , z , par )
fprintf( 'animation... \n' )
par.elapsed_time = [ par.elapsed_time toc( par.timer ) ] ;
toc( par.timer )

addpath('./tmtdyn/tubeplot');

% Data:
sk = par.skip ;
p = par.pause ;
eps = 1e-6 ;

vars = par.var ;
[ par.n_mass_anim , ~ ] = size ( rjtipF_mex( vars , z(1,:)' , 0 , 0 , 0 ) ); % number of bodies
[ par.n_ks_anim , ~ ] = size ( rksF_mex( vars , z(1,:)' , 0 , 0 , 0 ) ); % number of spring/dampers
ss = length ( t ) ; % simulation steps

% temp1 = rjtipF_mex( vars , z(i,:) , 1 ) ;
% if ~ismember( nan , temp1(:,4) ) % no ROM
% 	par.n_animpoints = 1 ;
% end

is_rom = 0; % is there a ROM element?
for n_t = 1 : ss
    [ ~ , par_mex ] = dyn_mid_step( t(n_t) , z(n_t,:)' , par.par_mex ) ;
    vars = par_mex.var ;
    temp2 = rksF_mex( vars , z(n_t,:)' , 0 , 0 , 0 ) ; % [ xyz_b xyz_t Q_b Q_t radi ]
    for i_sd = 1 : par.n_ks_anim
        r_anim.sprdmp(i_sd).r(1:2,1:3,n_t) = [ temp2(i_sd,1:3) ; temp2(i_sd,4:6) ] ;
        r_anim.sprdmp(i_sd).Q(1:2,:,n_t) = [ temp2(i_sd,7:10) ; temp2(i_sd,11:14) ] ;
        r_anim.sprdmp(i_sd).radi = temp2(i_sd,15); % link radius for plotting
        if par.anim_frame
            r_anim.sprdmp(i_sd).r(1:2,1:12,n_t) = [ r_anim.sprdmp(i_sd).r(1:2,1:3,n_t) , ...
                                                  [ Q_rot( temp2(i_sd,7:10)' , [ 1 0 0 ] ) , ... 
                                                    Q_rot( temp2(i_sd,7:10)' , [ 0 1 0 ] ) , ...
                                                    Q_rot( temp2(i_sd,7:10)' , [ 0 0 1 ] ) ;
                                                    Q_rot( temp2(i_sd,11:14)' , [ 1 0 0 ] ) , ...  
                                                    Q_rot( temp2(i_sd,11:14)' , [ 0 1 0 ] ) , ... 
                                                    Q_rot( temp2(i_sd,11:14)' , [ 0 0 1 ] ) ] ] ;
        end 
    end
    for i_s = 1 : par.n_animpoints + 1
        s = ( 1 - eps ) / par.n_animpoints * ( i_s - 1 ) + eps ; % normalized length
        temp1 = rjtipF_mex( vars , z(n_t,:)' , s , 0 , 0 ) ; % [ xyz_b xyz_t Q_b Q_t radi ]
        for i_m = 1 : par.n_mass_anim
            if ~isnan( temp1(i_m,4) ) % rigid
                if i_s == 1 % only needed once for rigid links
                    r_anim.mass(i_m).r(1:2,1:3,n_t) = [ temp1(i_m,1:3) ; temp1(i_m,4:6) ] ; % both ends
                    r_anim.mass(i_m).Q(1:2,:,n_t) = [ temp1(i_m,7:10) ; temp1(i_m,11:14) ] ;
                    if par.anim_frame
                        r_anim.mass(i_m).r(1:2,1:12,n_t) = [ r_anim.mass(i_m).r(1:2,1:3,n_t) , ...
                                                           [ Q_rot( temp1(i_m,7:10)' , [ 1 0 0 ] ) , ... 
                                                             Q_rot( temp1(i_m,7:10)' , [ 0 1 0 ] ) , ... 
                                                             Q_rot( temp1(i_m,7:10)' , [ 0 0 1 ] ) ;
                                                             Q_rot( temp1(i_m,11:14)' , [ 1 0 0 ] ) , ... 
                                                             Q_rot( temp1(i_m,11:14)' , [ 0 1 0 ] ) , ... 
                                                             Q_rot( temp1(i_m,11:14)' , [ 0 0 1 ] ) ] ] ;
                    end
                end
            else % ROM
                is_rom = 1;
                r_anim.mass(i_m).r(i_s,1:3,n_t) = temp1(i_m,1:3) ;
                r_anim.mass(i_m).Q(i_s,:,n_t) = temp1(i_m,7:10) ;
                if par.anim_frame
                    r_anim.mass(i_m).r(i_s,1:12,n_t) = [ r_anim.mass(i_m).r(i_s,1:3,n_t) , ...
                                                       Q_rot( temp1(i_m,7:10)' , [ 1 0 0 ] ) , ... 
                                                       Q_rot( temp1(i_m,7:10)' , [ 0 1 0 ] ) , ... 
                                                       Q_rot( temp1(i_m,7:10)' , [ 0 0 1 ] ) ] ;                    
                end
            end
            r_anim.mass(i_m).radi = temp1(i_m,15); % link radius for plotting
        end
        if ~is_rom % quit loop if there is no continuum ROM element
            i_s = par.n_animpoints + 2 ;
        end
    end
end

rjtip = zeros ( par.n_mass_anim , 6 , ss );
rks = zeros ( par.n_ks_anim , 6 , ss );
Qjtip = zeros ( par.n_mass_anim , 8 , ss );
Qks = zeros ( par.n_ks_anim , 8 , ss );
for i_m = 1 : par.n_mass_anim
    rjtip(i_m,:,:) = [ r_anim.mass(i_m).r(1,1,:)   r_anim.mass(i_m).r(1,2,:)   r_anim.mass(i_m).r(1,3,:) , ...
                       r_anim.mass(i_m).r(end,1,:) r_anim.mass(i_m).r(end,2,:) r_anim.mass(i_m).r(end,3,:) ] ;
    Qjtip(i_m,:,:) = [ r_anim.mass(i_m).Q(1,1,:)   r_anim.mass(i_m).Q(1,2,:)   r_anim.mass(i_m).Q(1,3,:)   r_anim.mass(i_m).Q(1,4,:), ...
                       r_anim.mass(i_m).Q(end,1,:) r_anim.mass(i_m).Q(end,2,:) r_anim.mass(i_m).Q(end,3,:) r_anim.mass(i_m).Q(end,4,:) ] ;                   
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
    Qks(i_sd,:,:) = [ r_anim.sprdmp(i_sd).Q(1,1,:)   r_anim.sprdmp(i_sd).Q(1,2,:)   r_anim.sprdmp(i_sd).Q(1,3,:)   r_anim.sprdmp(i_sd).Q(1,4,:) , ...
                      r_anim.sprdmp(i_sd).Q(end,1,:) r_anim.sprdmp(i_sd).Q(end,2,:) r_anim.sprdmp(i_sd).Q(end,3,:) r_anim.sprdmp(i_sd).Q(end,4,:) ] ;
end
if par.n_mass_anim == 0 ; rjtip = rks ; Qjtip = Qks ; end
if par.n_ks_anim == 0 ; rks = rjtip ; end
window_xmin = min( [ reshape( rjtip(:,[ 1 4 ],:) , [ 1 numel( rjtip(:,[ 1 4 ],:) ) ] ) reshape( rks(:,[ 1 4 ],:) , [ 1 numel( rks(:,[ 1 4 ],:) ) ] ) ] );
window_xmax = max( [ reshape( rjtip(:,[ 1 4 ],:) , [ 1 numel( rjtip(:,[ 1 4 ],:) ) ] ) reshape( rks(:,[ 1 4 ],:) , [ 1 numel( rks(:,[ 1 4 ],:) ) ] ) ] );
window_ymin = min( [ reshape( rjtip(:,[ 2 5 ],:) , [ 1 numel( rjtip(:,[ 1 4 ],:) ) ] ) reshape( rks(:,[ 2 5 ],:) , [ 1 numel( rks(:,[ 2 5 ],:) ) ] ) ] );
window_ymax = max( [ reshape( rjtip(:,[ 2 5 ],:) , [ 1 numel( rjtip(:,[ 1 4 ],:) ) ] ) reshape( rks(:,[ 2 5 ],:) , [ 1 numel( rks(:,[ 2 5 ],:) ) ] ) ] );
window_zmin = min( [ reshape( rjtip(:,[ 3 6 ],:) , [ 1 numel( rjtip(:,[ 1 4 ],:) ) ] ) reshape( rks(:,[ 3 6 ],:) , [ 1 numel( rks(:,[ 3 6 ],:) ) ] ) ] );
window_zmax = max( [ reshape( rjtip(:,[ 3 6 ],:) , [ 1 numel( rjtip(:,[ 1 4 ],:) ) ] ) reshape( rks(:,[ 3 6 ],:) , [ 1 numel( rks(:,[ 3 6 ],:) ) ] ) ] );

ad = 1.2 * max( abs ( [ window_xmin-window_xmax window_ymin-window_ymax window_zmin-window_zmax ] / 2 ) ) + 1e-6 ;
axis_limits = [ window_xmin+window_xmax window_xmin+window_xmax ...
                window_ymin+window_ymax window_ymin+window_ymax ...
                window_zmin+window_zmax window_zmin+window_zmax ] / 2 ...
              + [ -1 1 -1 1 -1 1 ] * ad ;

window_diag = sqrt( ( window_xmax - window_xmin ) ^ 2 + ( window_ymax - window_ymin ) ^ 2 + ( window_zmax - window_zmin ) ^ 2 ) ;
scle = 0.05 * window_diag ;

% Animation:
clr = { 'black' , 'yellow' , 'cyan', 'red' , 'green' , 'blue' , 'magenta' };

for n_t = 1 : sk : ss % update the points
    if par.anim_frame == 2 || par.anim_frame == 12 % plot frames
        xyzview = subplot(3,4,[1:3,5:7,9:11]);
    end
    
    % bodies init.
    for i = 1 : par.n_mass_anim % creat lines ending to each joint
        if ~par.anim_line
            plot3( r_anim.mass(i).r(:,1,n_t) , r_anim.mass(i).r(:,2,n_t) , r_anim.mass(i).r(:,3,n_t) , 'LineWidth' , 2 ,'Color' , clr{mod(i,6)+1} ); % draw line
        else
            tubeplot( [ r_anim.mass(i).r(:,1,n_t) , r_anim.mass(i).r(:,2,n_t) , r_anim.mass(i).r(:,3,n_t) ]' , r_anim.mass(i).radi , clr{mod(i,6)+1} , par.anim_edge , 0 ) ; % draw tube
        end
        hold on
    end    
    % spring/dampers init.
    for i = 1 : par.n_ks_anim % creat lines ending to each joint
        if ~par.anim_line
            plot3( r_anim.sprdmp(i).r(:,1,n_t) , r_anim.sprdmp(i).r(:,2,n_t) , r_anim.sprdmp(i).r(:,3,n_t) , 'LineWidth' , 2 ,'Color' , clr{mod(i,6)+1} ); % draw dash-line
        else
            tubeplot( [ r_anim.sprdmp(i).r(:,1,n_t) , r_anim.sprdmp(i).r(:,2,n_t) , r_anim.sprdmp(i).r(:,3,n_t) ]' , r_anim.sprdmp(i).radi , clr{mod(i,6)+1} , par.anim_edge , 1 ) ; % draw wire frame tube
        end
        hold on
    end
    
    if par.anim_frame == 1 || par.anim_frame == 12 % plot frames
        % masses init.
        for i = 1 : par.n_mass_anim % creat lines ending to each joint
            plot3( r_anim.mass(i).r(1,1,n_t) + scle * [ 0 r_anim.mass(i).r(1,4,n_t) ] , ...
                   r_anim.mass(i).r(1,2,n_t) + scle * [ 0 r_anim.mass(i).r(1,5,n_t) ] , ...
                   r_anim.mass(i).r(1,3,n_t) + scle * [ 0 r_anim.mass(i).r(1,6,n_t) ] , 'Color' , 'red' );
            hold on
            plot3( r_anim.mass(i).r(end,1,n_t) + scle * [ 0 r_anim.mass(i).r(end,4,n_t) ] , ...
                   r_anim.mass(i).r(end,2,n_t) + scle * [ 0 r_anim.mass(i).r(end,5,n_t) ] , ...
                   r_anim.mass(i).r(end,3,n_t) + scle * [ 0 r_anim.mass(i).r(end,6,n_t) ] , 'Color' , 'red' );
            hold on
            plot3( r_anim.mass(i).r(1,1,n_t) + scle * [ 0 r_anim.mass(i).r(1,7,n_t) ] , ...
                   r_anim.mass(i).r(1,2,n_t) + scle * [ 0 r_anim.mass(i).r(1,8,n_t) ] , ...
                   r_anim.mass(i).r(1,3,n_t) + scle * [ 0 r_anim.mass(i).r(1,9,n_t) ] , 'Color' , 'blue' );
            hold on
            plot3( r_anim.mass(i).r(end,1,n_t) + scle * [ 0 r_anim.mass(i).r(end,7,n_t) ] , ...
                   r_anim.mass(i).r(end,2,n_t) + scle * [ 0 r_anim.mass(i).r(end,8,n_t) ] , ...
                   r_anim.mass(i).r(end,3,n_t) + scle * [ 0 r_anim.mass(i).r(end,9,n_t) ] , 'Color' , 'blue' );
            hold on
            plot3( r_anim.mass(i).r(1,1,n_t) + scle * [ 0 r_anim.mass(i).r(1,10,n_t) ] , ...
                   r_anim.mass(i).r(1,2,n_t) + scle * [ 0 r_anim.mass(i).r(1,11,n_t) ] , ...
                   r_anim.mass(i).r(1,3,n_t) + scle * [ 0 r_anim.mass(i).r(1,12,n_t) ] , 'Color' , 'green' );
            hold on
            plot3( r_anim.mass(i).r(end,1,n_t) + scle * [ 0 r_anim.mass(i).r(end,10,n_t) ] , ...
                   r_anim.mass(i).r(end,2,n_t) + scle * [ 0 r_anim.mass(i).r(end,11,n_t) ] , ...
                   r_anim.mass(i).r(end,3,n_t) + scle * [ 0 r_anim.mass(i).r(end,12,n_t) ] , 'Color' , 'green' );
            hold on
        end
        % spring/dampers init.
        for i = 1 : par.n_ks_anim % creat lines ending to each joint
            plot3( r_anim.sprdmp(i).r(1,1,n_t) + scle * [ 0 r_anim.sprdmp(i).r(1,4,n_t) ] , ...
                   r_anim.sprdmp(i).r(1,2,n_t) + scle * [ 0 r_anim.sprdmp(i).r(1,5,n_t) ] , ...
                   r_anim.sprdmp(i).r(1,3,n_t) + scle * [ 0 r_anim.sprdmp(i).r(1,6,n_t) ] , 'Color' , 'red' );
            hold on
            plot3( r_anim.sprdmp(i).r(2,1,n_t) + scle * [ 0 r_anim.sprdmp(i).r(2,4,n_t) ] , ...
                   r_anim.sprdmp(i).r(2,2,n_t) + scle * [ 0 r_anim.sprdmp(i).r(2,5,n_t) ] , ...
                   r_anim.sprdmp(i).r(2,3,n_t) + scle * [ 0 r_anim.sprdmp(i).r(2,6,n_t) ] , 'Color' , 'red' );
            hold on
            plot3( r_anim.sprdmp(i).r(1,1,n_t) + scle * [ 0 r_anim.sprdmp(i).r(1,7,n_t) ] , ...
                   r_anim.sprdmp(i).r(1,2,n_t) + scle * [ 0 r_anim.sprdmp(i).r(1,8,n_t) ] , ...
                   r_anim.sprdmp(i).r(1,3,n_t) + scle * [ 0 r_anim.sprdmp(i).r(1,9,n_t) ] , 'Color' , 'blue' );
            hold on
            plot3( r_anim.sprdmp(i).r(2,1,n_t) + scle * [ 0 r_anim.sprdmp(i).r(2,7,n_t) ] , ...
                   r_anim.sprdmp(i).r(2,2,n_t) + scle * [ 0 r_anim.sprdmp(i).r(2,8,n_t) ] , ...
                   r_anim.sprdmp(i).r(2,3,n_t) + scle * [ 0 r_anim.sprdmp(i).r(2,9,n_t) ] , 'Color' , 'blue' );
            hold on
            plot3( r_anim.sprdmp(i).r(1,1,n_t) + scle * [ 0 r_anim.sprdmp(i).r(1,10,n_t) ] , ...
                   r_anim.sprdmp(i).r(1,2,n_t) + scle * [ 0 r_anim.sprdmp(i).r(1,11,n_t) ] , ...
                   r_anim.sprdmp(i).r(1,3,n_t) + scle * [ 0 r_anim.sprdmp(i).r(1,12,n_t) ] , 'Color' , 'green' );
            hold on
            plot3( r_anim.sprdmp(i).r(2,1,n_t) + scle * [ 0 r_anim.sprdmp(i).r(2,10,n_t) ] , ...
                   r_anim.sprdmp(i).r(2,2,n_t) + scle * [ 0 r_anim.sprdmp(i).r(2,11,n_t) ] , ...
                   r_anim.sprdmp(i).r(2,3,n_t) + scle * [ 0 r_anim.sprdmp(i).r(2,12,n_t) ] , 'Color' , 'green' );
            hold on
        end
    end
    
    title( t(n_t) )
    axis equal ;
    axis ( axis_limits ); xlabel( 'x[m]' ) ; ylabel( 'y[m]' ) ; zlabel( 'z[m]' ) ;
    light( 'Position', [-1 -1 1] ) % add light at infinity with direction 'Position'
    lighting gouraud % {none, flat, gouraud} preferred lighting for a curved surface
    grid off
    hold off
    
    % side views
    if par.anim_frame == 2 || par.anim_frame == 12 % plot frames
        xyzview = get(xyzview,'Children');
        xzview = subplot(3,4,4); cla(xzview);
        copyobj(xyzview, xzview); view([0 -1 0]);
        axis equal ; axis ( axis_limits ); xlabel( 'x[m]' ) ; zlabel( 'z[m]' ) ;
        yzview = subplot(3,4,8); cla(yzview);
        copyobj(xyzview, yzview); view([-1 0 0]);
        axis equal ; axis ( axis_limits ); ylabel( 'y[m]' ) ; zlabel( 'z[m]' ) ;
        xyview = subplot(3,4,12); cla(xyview);
        copyobj(xyzview, xyview);
        axis equal ; axis ( axis_limits ); xlabel( 'x[m]' ) ; ylabel( 'y[m]' ) ; view(2);
    end
    
    if par.movie == 1 ; writeVideo( par.vid , getframe( gcf ) ) ; end
    pause( p );
    
end


function Qo = Q_mult( Q1 , Q2 )
% Q = [ q0 r1 r2 r3 ] ; % quaternion format
% Q1 & Q2 are cloumn vectors
Qo = [ Q1(1,1) -Q1(2,1) -Q1(3,1) -Q1(4,1) ;
       Q1(2,1)  Q1(1,1) -Q1(4,1)  Q1(3,1) ;
       Q1(3,1)  Q1(4,1)  Q1(1,1) -Q1(2,1) ;
       Q1(4,1) -Q1(3,1)  Q1(2,1)  Q1(1,1) ] * Q2 ;


function r_rot = Q_rot( Q , r )
rQ = [ 0 r ].' ;
r_rot = Q_mult( Q_mult( Q , rQ ) , Q_conj( Q ) ) ; % 4x1 vector
r_rot = r_rot(2:4,1)' ;


function Qo = Q_conj( Q )
% global unit_quat
% if ~unit_quat
% 	Qo = sym_simp( Qo / sqrt( Q.' * Q ) ) ;
% end
Qo = [ Q(1,1) ; -Q(2:4,1) ] ;


