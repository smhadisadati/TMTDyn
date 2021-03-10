% DXFtool
function [ mesh_body , mesh_joint ] = mesh_import( body , joint , mesh , par )
fprintf( 'mesh_import... \n' )
par.elapsed_time = [ par.elapsed_time toc( par.timer ) ] ;
toc( par.timer )

n_b = numel( body ) ; % alreeady defined bodies

% initialize
mesh.joint(1).mainkin = 1 ;
mesh.joint(2).mainkin = 0 ;
mesh.joint(2).first = 0 ;
mesh.joint(2).second = 0 ;

[ ~ , ~ , mesh.body , mesh.joint ] = check( par , [] , mesh.body , mesh.joint , [] , [] ) ;

% read file and plot
addpath( './tmtdyn/igesToolBox_edited' ) ;

% Compile the c-files
makeIGESmex ;

% Load parameter data from IGES-file.
lines = iges2matlab( mesh.file_name ) ;

% transform lines
for i = 1 : numel( lines ) % find fixed points and masses
    if strcmp( lines{i}.name , 'LINE' )
        
        % init. geom.
        mesh.Q = [ 1 0 0 0 ].';
        mesh.TQ = [ 1 0 0 0 ; 0 0 0 0 ].';
        [ ~ , nj_tr ] = size( mesh.tr ) ; % number of transforamtions in a joint
        for i3 = 1 : nj_tr
            [ Q_temo , TQ_temo ] = TQ_mat( [ mesh.tr(i3).trans , mesh.tr(i3).rot ] );
            mesh.Q = Q_mult( mesh.Q , Q_temo ) ;
            mesh.TQ = TQ_mult( mesh.TQ , TQ_temo ) ;
        end
        
        TQ_p1 = TQ_mult( mesh.TQ , [ 1 0 0 0 ; 0 lines{i}.p1'*1e-3 ].' ) ; % mm to m
        TQ_p2 = TQ_mult( mesh.TQ , [ 1 0 0 0 ; 0 lines{i}.p2'*1e-3 ].' ) ; 
        
        lines_tr{i}.p1 = TQ_p1(2:4,2) ; % transformed
        lines_tr{i}.p2 = TQ_p2(2:4,2) ;
        
    end
end

% Plot the IGES object
plotIGES( lines ) ; hold on
view( [ -1 -1 2 ] ) ;
pause( 1e-1 ) ;

% list the imported entities
points = zeros(1,6) ; % [ x_p y_p z_p i_b i_jl end_no ]
points_mass = zeros(1,4) ; % [ x_p y_p z_p i_b ]

tol = mesh.tol ;

i_b = 0 ;
i_jd = 0 ;
i_p = 0 ;
i_jl = 0 ;
for i = 1 : numel( lines ) % find fixed points and masses
    if strcmp( lines{i}.name , 'LINE' )
                
        % defaults
        i_jl = i_jl + 1 ;
        joint_link(i_jl) = mesh.joint(2) ;
        joint_link(i_jl).tr.trans = lines{i}.p1(1:3)' ;
        joint_link(i_jl).tr2nd.trans = lines{i}.p2(1:3)' ;
        
        % first mass
        i_px = [] ; i_py = [] ; i_pz = [] ; 
        i_px = find( abs( lines{i}.p1(1) - points(:,1) ) < tol ) ;
        if isempty( i_px ) % new point
            i_p = i_p + 1 ;
            points(i_p,:)= [ lines{i}.p1(1:3)' 0 i_jl 1 ] ;
        else
            i_py = find( abs( lines{i}.p1(2) - points(i_px,2) ) < tol ) ;
            if isempty( i_py ) % new point
                i_p = i_p + 1 ;
                points(i_p,:)= [ lines{i}.p1(1:3)' 0 i_jl 1 ] ;
            else
                i_pz = find( abs( lines{i}.p1(3) - points(i_px(i_py),3) ) < tol ) ;
                if isempty( i_pz ) % new point
                    i_p = i_p + 1 ;
                    points(i_p,:)= [ lines{i}.p1(1:3)' 0 i_jl 1 ] ;
                else
                    if points(i_px(i_py(i_pz)),4) == 0 % new mass
                        i_b = i_b + 1 ;
                        mesh_body(i_b) = mesh.body ;
                        points(i_px(i_py(i_pz)),4) = i_b + n_b ;
                        i_jd = i_jd + 1 ; % new dof joint
                        mesh_joint(i_jd) = mesh.joint(1) ;
                        mesh_joint(i_jd).second = i_b + n_b ;
                        mesh_joint(i_jd).dof(1).init = lines_tr{i}.p1(1) ;
                        mesh_joint(i_jd).dof(2).init = lines_tr{i}.p1(2) ;
                        mesh_joint(i_jd).dof(3).init = lines_tr{i}.p1(3) ;
                        if points(i_px(i_py(i_pz)),6) == 1
                            joint_link(points(i_px(i_py(i_pz)),5)).first = i_b + n_b ; % correct first link connected to this point
                            joint_link(points(i_px(i_py(i_pz)),5)).tr.trans = mesh.joint(2).tr.trans ;
                        elseif points(i_px(i_py(i_pz)),6) == 2
                            joint_link(points(i_px(i_py(i_pz)),5)).second = i_b + n_b ; % correct first link connected to this point
                            joint_link(points(i_px(i_py(i_pz)),5)).tr2nd.trans = mesh.joint(2).tr2nd.trans ;
                        end
                        points_mass(i_b,:) = [ lines{i}.p1(1:3)' i_b+n_b ] ;
                    end
                    joint_link(i_jl).first = points(i_px(i_py(i_pz)),4) ; % correct current link
                    joint_link(i_jl).tr.trans = mesh.joint(2).tr.trans ;
                end
            end
        end
        
        % second mass
        i_px = [] ; i_py = [] ; i_pz = [] ; 
        i_px = find( abs( lines{i}.p2(1) - points(:,1) ) < tol ) ;
        if isempty( i_px ) % new point
            i_p = i_p + 1 ;
            points(i_p,:)= [ lines{i}.p2(1:3)' 0 i_jl 2 ] ;
        else
            i_py = find( abs( lines{i}.p2(2) - points(i_px,2) ) < tol ) ;
            if isempty( i_py ) % new point
                i_p = i_p + 1 ;
                points(i_p,:)= [ lines{i}.p2(1:3)' 0 i_jl 2 ] ;
            else
                i_pz = find( abs( lines{i}.p2(3) - points(i_px(i_py),3) ) < tol ) ;
                if isempty( i_pz ) % new point
                    i_p = i_p + 1 ;
                    points(i_p,:)= [ lines{i}.p2(1:3)' 0 i_jl 2 ] ;
                else
                    if points(i_px(i_py(i_pz)),4) == 0 % new mass
                        i_b = i_b + 1 ;
                        mesh_body(i_b) = mesh.body ;
                        points(i_px(i_py(i_pz)),4) = i_b + n_b ;
                        i_jd = i_jd + 1 ; % new dof joint
                        mesh_joint(i_jd) = mesh.joint(1) ;
                        mesh_joint(i_jd).second = i_b + n_b ;
                        mesh_joint(i_jd).dof(1).init = lines_tr{i}.p2(1) ;
                        mesh_joint(i_jd).dof(2).init = lines_tr{i}.p2(2) ;
                        mesh_joint(i_jd).dof(3).init = lines_tr{i}.p2(3) ;
                        if points(i_px(i_py(i_pz)),6) == 1
                            joint_link(points(i_px(i_py(i_pz)),5)).first = i_b + n_b ; % correct first link connected to this point
                            joint_link(points(i_px(i_py(i_pz)),5)).tr.trans = mesh.joint(2).tr.trans ;
                        elseif points(i_px(i_py(i_pz)),6) == 2
                            joint_link(points(i_px(i_py(i_pz)),5)).second = i_b + n_b ; % correct first link connected to this point
                            joint_link(points(i_px(i_py(i_pz)),5)).tr2nd.trans = mesh.joint(2).tr2nd.trans ;
                        end
                        points_mass(i_b,:) = [ lines{i}.p2(1:3)' i_b+n_b ] ;
                    end
                    joint_link(i_jl).second = points(i_px(i_py(i_pz)),4) ; % correct current link
                    joint_link(i_jl).tr2nd.trans = mesh.joint(2).tr2nd.trans ;
                end
            end
        end
        
    end
end

mesh_joint = [ mesh_joint joint_link ] ; % MK joints first

% report
i_b
i_p
i_jd
i_jl

plot3( points(:,1) , points(:,2) , points(:,3) , 'x' ) ; hold on
plot3( points_mass(:,1) , points_mass(:,2) , points_mass(:,3) , 'ro' ) ; hold on
% show mass number for reference
strValues = strtrim( cellstr( num2str( points_mass(:,4) , '%d' ) ) ) ;
text( points_mass(:,1) , points_mass(:,2) , points_mass(:,3) , strValues , 'VerticalAlignment' , 'bottom' ) ;
xlabel( 'x[m]' ) ; ylabel( 'y[m]' ) ; zlabel( 'z[m]' ) ;
view( [ -1 -1 2 ] ) ; axis equal ;

% fprintf( 'close iges_import plot \n' ) ; pause()
% close( iges_figure ) ;

pause(1e-1)


function [ Q , TQ ] = TQ_mat( r )
% Q = [ q0 r1 r2 r3 ] ; % quaternion format
% Q1 & Q2 are cloumn vectors

switch numel( r )                
        
    case 5 % single rotations: Euler angles
        i = double( r(4) );
        x = r(5);
        
        switch i
            case 1
                Q = [ cos( x / 2 ) sin( x / 2 )*[ 1 0 0 ] ].';
            case 2
                Q = [ cos( x / 2 ) sin( x / 2 )*[ 0 1 0 ] ].';
            case 3
                Q = [ cos( x / 2 ) sin( x / 2 )*[ 0 0 1 ] ].';
            otherwise
                Q = [ 1 0 0 0 ].';
        end
        
    case 6 % variable curvature with piecewise constant strain assumption in each elements
        Q = [ 1 r(4:6)/2 ].';
        
    case 7 % 4-element euler angle rot. vector
        Q = [ cos( r(4) / 2 ) sin( r(4) / 2 )*r(5:7)/sqrt( r(5:7) * r(5:7).' ) ].' ;

end

TQ = sym ( [ Q , [ 0 r(1:3) ].' ] ); % 4x4: Each QR contains a translation and then a rotation
Q = vpa( Q ) ;
TQ = vpa( TQ ) ;

function Qo = Q_mult( Q1 , Q2 )
% Q = [ q0 r1 r2 r3 ] ; % quaternion format
% Q1 & Q2 are cloumn vectors
Qo = [ Q1(1,1) -Q1(2,1) -Q1(3,1) -Q1(4,1) ;
       Q1(2,1)  Q1(1,1) -Q1(4,1)  Q1(3,1) ;
       Q1(3,1)  Q1(4,1)  Q1(1,1) -Q1(2,1) ;
       Q1(4,1) -Q1(3,1)  Q1(2,1)  Q1(1,1) ] * Q2 ;

function r_rot = Q_rot( Q , rQ )
% rQ = [ 0 r ].' ;
r_rot = Q_mult( Q_mult( Q , rQ ) , Q_conj( Q ) ) ; % 4x1 vector

function TQo = TQ_mult( TQ1 , TQ2 )
TQo = [ Q_mult( TQ1(:,1) , TQ2(:,1) ) , ...
        TQ1(:,2)+Q_rot( TQ1(:,1) , TQ2(:,2) ) ] ;
   
function Qo = Q_conj( Q )
Qo = [ Q(1,1) ; -Q(2:4,1) ] ;


