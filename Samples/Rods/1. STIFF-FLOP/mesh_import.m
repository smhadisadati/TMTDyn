% DXFtool
function [ body , joint ] = mesh_import( mesh , par )
fprintf( 'mesh_import... \n' )
par.elapsed_time = [ par.elapsed_time toc( par.timer ) ] ;
toc( par.timer )

% initialize
mesh.joint(2).first = 0 ;
mesh.joint(2).second = 0 ;

[ ~ , ~ , ~ , mesh.joint ] = check( par , [] , [] , mesh.joint , [] , [] ) ;

% read file and plot
addpath( 'igesToolBox_edited' ) ;
% Compile the c-files
makeIGESmex ;
% Load parameter data from IGES-file.
lines = iges2matlab( mesh.file_name ) ;
% Plot the IGES object
iges_figure = plotIGES( lines ) ; hold on
pause( 1e-1 ) ;

% list the imported entities
points = zeros(1,5) ; % [ x_p y_p z_p i_b i_jl ]
points_mass = zeros(1,3) ; % [ x_p y_p z_p ]

i_b = 0 ;
i_j = 0 ;
i_p = 0 ;
n_jl = 0 ;
threshold = 1e12 ;
for i = 1 : numel( lines ) % find fixed points and masses
    if strcmp( lines{i}.name , 'LINE' )
        % smooth
%         lines{i}.p1(1:3) = floor( threshold * lines{i}.p1(1:3) ) / threshold ;
%         lines{i}.p2(1:3) = floor( threshold * lines{i}.p2(1:3) ) / threshold ;
        
        % defaults
        i_j = i_j + 1 ;
        i_jl = i_j ;
        n_jl = n_jl + 1 ;
        joint(i_jl) = mesh.joint(2) ;
        joint(i_jl).tr.trans = lines{i}.p1(1:3)' ;
        joint(i_jl).tr2nd.trans = lines{i}.p2(1:3)' ;
        
        % first mass
        [ is_px , i_px ] = ismember( lines{i}.p1(1) , points(:,1) ) ;
        if is_px == 0 % new point
            i_p = i_p + 1 ;
            points(i_p,:)= [ lines{i}.p1(1:3)' 0 i_jl ] ;
        else
            [ is_py , i_py ] = ismember( lines{i}.p1(2) , points(i_px,2) ) ;
            if is_py == 0 % new point
                i_p = i_p + 1 ;
                points(i_p,:)= [ lines{i}.p1(1:3)' 0 i_jl ] ;
            else
                [ is_pz , i_pz ] = ismember( lines{i}.p1(3) , points(i_px(i_py),3) ) ;
                if is_pz == 0 % new point
                    i_p = i_p + 1 ;
                    points(i_p,:)= [ lines{i}.p1(1:3)' 0 i_jl ] ;
                else
                    if points(i_px(i_py(i_pz)),4) == 0 % new mass
                        i_b = i_b + 1 ;
                        body(i_b) = mesh.body ;
                        points(i_px(i_py(i_pz)),4) = i_b ;
                        i_j = i_j + 1 ; % new dof joint
                        joint(i_j) = mesh.joint(1) ;
                        joint(i_j).second = i_b ;
                        joint(i_j).dof(1).init = lines{i}.p1(1) ;
                        joint(i_j).dof(2).init = lines{i}.p1(2) ;
                        joint(i_j).dof(3).init = lines{i}.p1(3) ;
						joint(points(i_px(i_py(i_pz)),5)).tr.trans = mesh.joint(2).tr.trans ;
                        joint(points(i_px(i_py(i_pz)),5)).first = i_b ; % correct first link connected to this point
                        points_mass(i_b,:) = lines{i}.p1(1:3)' ;
                    end
                    joint(i_jl).first = points(i_px(i_py(i_pz)),4) ; % correct current link
                    joint(i_jl).tr.trans = mesh.joint(2).tr.trans ;
                end
            end
        end
        
        % second mass
        [ is_px , i_px ] = ismember( lines{i}.p2(1) , points(:,1) ) ;
        if is_px == 0 % new point
            i_p = i_p + 1 ;
            points(i_p,:)= [ lines{i}.p2(1:3)' 0 i_jl ] ;
        else
            [ is_py , i_py ] = ismember( lines{i}.p2(2) , points(i_px,2) ) ;
            if is_py == 0 % new point
                i_p = i_p + 1 ;
                points(i_p,:)= [ lines{i}.p2(1:3)' 0 i_jl ] ;
            else
                [ is_pz , i_pz ] = ismember( lines{i}.p2(3) , points(i_px(i_py),3) ) ;
                if is_pz == 0 % new point
                    i_p = i_p + 1 ;
                    points(i_p,:)= [ lines{i}.p2(1:3)' 0 i_jl ] ;
                else
                    if points(i_px(i_py(i_pz)),4) == 0 % new mass
                        i_b = i_b + 1 ;
                        body(i_b) = mesh.body ;
                        points(i_px(i_py(i_pz)),4) = i_b ;
                        i_j = i_j + 1 ; % new dof joint
                        joint(i_j) = mesh.joint(1) ;
                        joint(i_j).second = i_b ;
                        joint(i_j).dof(1).init = lines{i}.p2(1) ;
                        joint(i_j).dof(2).init = lines{i}.p2(2) ;
                        joint(i_j).dof(3).init = lines{i}.p2(3) ;
                        joint(points(i_px(i_py(i_pz)),5)).second = i_b ; % correct first link connected to this point
                        joint(points(i_px(i_py(i_pz)),5)).tr2nd.trans = mesh.joint(2).tr2nd.trans ;
                        points_mass(i_b,:) = lines{i}.p2(1:3)' ;
                    end
                    joint(i_jl).second = points(i_px(i_py(i_pz)),4) ; % correct current link
                    joint(i_jl).tr2nd.trans = mesh.joint(2).tr2nd.trans ;
                end
            end
        end
        
    end
end

i_b
i_p
i_j
n_jl
for i = 1 : numel( lines ) % plot
    if strcmp( lines{i}.name , 'LINE' )        
        line( 'XData' , [ lines{i}.x1 lines{i}.x2 ] , ...
            'YData' , [ lines{i}.y1 lines{i}.y2 ] , ...
            'ZData' , [ lines{i}.z1 lines{i}.z2 ] , ...
            'Color' , 'red' ) ;
        hold on ;
    end
end
plot3( points(:,1) , points(:,2) , points(:,3) , 'x' ) ; hold on
plot3( points_mass(:,1) , points_mass(:,2) , points_mass(:,3) , 'ro' ) ; hold on
fprintf( 'close iges_import plot \n' )
pause()
close( iges_figure ) ;
pause(1e-1)


