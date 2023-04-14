function [motor_in, tip_pos] = exp_v0( exp_case )

% setup specs
base_offset = [32, 0, 0;
               42, 0, 0] * 1e-3; % ref. tracker to insertion hole offset in final frame (tubes along z)
% base_offset = [33, -3, 0;
%                35, -3, 4] * 1e-3; % ref. tracker to insertion hole offset in final frame (tubes along z)
% inc to motion and direction adjustment
% note 1.0579 correction for angle!
step2motion_coeff = [1e3, 6144000, 614400/2/pi, -6144000, 614400/2/pi, 1, 1]; % t, n5_outlin, n6_outrot, n4_inlin, n1_inrot

% Aurora tracker
d_at = 2.3e-3; % diameter
l_at = 10e-3; % length

% tube dimensions
r_s = 0.5 * ... % tube 1 outer [ inner outer ] radius
    [ 1.37, 1.78 ;
      0.7, 1.1 ;
      0, 0 ] * 1e-3 ; % tube 3 inner

% extract
sync = [1, 1; 1, 1];
switch exp_case(1) % exp. cases
    case 1 % basic motions
        load ('exp/basics.mat' ) ; % basics_motor: t, n5_outlin, n6_outrot, n4_inlin, n1_inrot
                                   % basics_tip: t, Q0, Qx, Qy, Qz, x, y, z, ... (mid, tip, base, NA)
%         sync = [1, 1; numel(basics_motor(:,1)), numel(basics_tip(:,1))];
        sync = [4, 318; 377, 2399];
        temp_motor = basics_motor(sync(1,1):sync(2,1),:);
        temp_motor(end,7) = 0;
        temp_tube1 = basics_tip(sync(1,2):sync(2,2),[1,2:8]); % mid
        temp_tube2 = basics_tip(sync(1,2):sync(2,2),[1,9:15]); % tip
        backlash = [ 161, 0.6; 309, 0.6]; % data_point, caused_delay
        t_equil = [2.3, 8.5, 16.7, 22, 38.1, 43.1];
        t_init = [0, 6.1, 12, 33.7, 52];
        
    case 2 % random motions
        load ('exp/random.mat' ) ; % random_motor: t, n5_outlin, n6_outrot, n4_inlin, n1_inrot
                                   % random_tip: t, Q0, Qx, Qy, Qz, x, y, z, ... (mid, tip, base, NA)
%         sync = [1, 1; numel(random_motor(:,1)), numel(random_tip(:,1))];
        sync = [23, 294; 191, 1242];
        temp_motor = random_motor(sync(1,1):sync(2,1),:);
        temp_motor(end,7) = 0;
        temp_tube1 = random_tip(sync(1,2):sync(2,2),[1,2:8]); % mid
        temp_tube2 = random_tip(sync(1,2):sync(2,2),[1,9:15]); % tip
        backlash = [ 81, 0]; % data_point, caused_delay
        
end

% smooth
temp_motor(:,2:end) = smoothV( temp_motor(:,2:end) ) ;
temp_tube1(:,2:end) = smoothV( temp_tube1(:,2:end) ) ;
temp_tube2(:,2:end) = smoothV( temp_tube2(:,2:end) ) ;

% exp. plane prependicular and binormal directions
T = [Q_rot( temp_tube1(1,2:5) , [0, 0, 1] ); Q_rot( temp_tube2(1,2:5) , [0, 0, 1] )]; % tangents
B = cross(T(1,:), T(2,:)); % binormal: normal (inward) to exp plane (only for planar motion)
N = [cross(B, T(1,:)); cross(B, T(2,:))]; % normals: toward curve center

% conditioning
tube_t0 = temp_tube1(1,1);
tube1_inf = []; tube2_inf = [];
for i = 1 : numel( temp_tube1(:,1) )    
    % time offset/scale adjustment and add base offset
    temp_tube1(i,1) = ( temp_tube1(i,1) - tube_t0 ) / 8 / 40; % 8 samples with 40Hz
    temp_tube1(i,6:8) = temp_tube1(i,6:8) / 1e3 ; % mid segment
    temp_tube2(i,1) = ( temp_tube2(i,1) - tube_t0 ) / 8 / 40;
    temp_tube2(i,6:8) = temp_tube2(i,6:8) / 1e3 ; % tip segment
    % Aurora tracker offset
    sensor_offset{1}(i,:) = (d_at/2+r_s(1,2)) * N(1,:) + l_at/2 * T(1,:) ; 
    sensor_offset{2}(i,:) = (d_at/2+r_s(2,2)) * N(2,:) + l_at/2 * T(2,:) ;
    % find singular points
    if abs( temp_tube1(i,8) ) > 200
        tube1_inf = [tube1_inf, i];
    end
    if abs( temp_tube2(i,8) ) > 200
        tube2_inf = [tube2_inf, i];
    end
end
% remove singular points
temp_tube1(tube1_inf,:) = [];
temp_tube2(tube2_inf,:) = [];
sensor_offset{1}(tube1_inf,:) = [];
sensor_offset{2}(tube2_inf,:) = [];
% rotate frame (Q is not correct)
temp_tube1 = [temp_tube1(:,1:5), -temp_tube1(:,8), -temp_tube1(:,7)+temp_tube1(1,7), -temp_tube1(:,6)];
temp_tube2 = [temp_tube2(:,1:5), -temp_tube2(:,8), -temp_tube2(:,7)+temp_tube2(1,7), -temp_tube2(:,6)];
% sensor offset
temp_tube1(:,6:8) = temp_tube1(:,6:8) + base_offset(1,:) + 0*sensor_offset{1};
temp_tube2(:,6:8) = temp_tube2(:,6:8) + base_offset(2,:) + 0*sensor_offset{2};

% step in inc to motion in mm & rad
motor_t0 = temp_motor(1,1);
temp_motor(:,1) = temp_motor(:,1) - motor_t0;
temp_motor = temp_motor ./ step2motion_coeff;
% motor accelerations
for i = 2 : numel( temp_motor(1,:) )
    temp_motor_vel(:,i) = [ 0; diff( temp_motor(:,i) ) ] / ( temp_motor(2,1) - temp_motor(1,1) ) ;
    temp_motor_acc(:,i) = [ 0; diff( temp_motor_vel(:,i) ) ] / ( temp_motor(2,1) - temp_motor(1,1) ) ;
end
temp_motor_vel(:,1) = temp_motor(:,1);
temp_motor_vel(:,2:end) = smoothV( temp_motor_vel(:,2:end) ) ;
temp_motor_acc(:,1) = temp_motor(:,1);
temp_motor_acc(:,2:end) = smoothV( temp_motor_acc(:,2:end) ) ;


% sync time!!!
% temp_tube1(:,1) = temp_tube1(:,1) * temp_motor(end,1) / temp_tube1(end,1);
% temp_tube2(:,1) = temp_tube2(:,1) * temp_motor(end,1) / temp_tube2(end,1);
temp_motor(:,1) = temp_motor(:,1) * temp_tube1(end,1) / temp_motor(end,1);

% cancel backlash
for i = numel( backlash(:,1) )
    temp_motor(backlash(i,1):end,1) = temp_motor(backlash(i,1):end,1) + backlash(i,2);
end

% output
tip_pos.tube1 = temp_tube1; % [t Q0 Qv1 Qv2 Qv3 x y z]
tip_pos.tube2 = temp_tube2;
motor_in.pos = temp_motor; % [t tube1_lin tube1_rot tube2_lin tube2_rot tube3_lin tube3_rot]
motor_in.vel = temp_motor_vel;
motor_in.acc = temp_motor_acc;

% plot
figure ;
subplot(2,5,1) ; plot( motor_in.pos(:,1), motor_in.pos(:,[2,4]), 'LineWidth', 2 ) ;
title('lin motor pos')
subplot(2,5,6) ; plot( motor_in.acc(:,1), motor_in.acc(:,[2,4]), 'LineWidth', 2 ) ;
title('lin motor ac')
subplot(2,5,2) ; plot( motor_in.pos(:,1), motor_in.pos(:,[3,5]), 'LineWidth', 2 ) ;
title('rot motor pos')
subplot(2,5,7) ; plot( motor_in.acc(:,1), motor_in.acc(:,[3,5]), 'LineWidth', 2 ) ;
title('rot motor ac')
subplot(2,5,3) ; plot( tip_pos.tube1(:,1), tip_pos.tube1(:,6:8), 'LineWidth', 2 ) ;
title('tube 1 pos')
subplot(2,5,8) ; plot( tip_pos.tube1(:,1), tip_pos.tube1(:,2:5), 'LineWidth', 2 );
title('tube 1 Q')
subplot(2,5,4) ; plot( tip_pos.tube2(:,1), tip_pos.tube2(:,6:8), 'LineWidth', 2 ) ;
title('tube 2 pos')
subplot(2,5,9) ; plot( tip_pos.tube2(:,1), tip_pos.tube2(:,2:5), 'LineWidth', 2 ) ;
title('tube 2 Q')
subplot(2,5,[5,10]) ;
plot3( tip_pos.tube1(:,6), tip_pos.tube1(:,7), tip_pos.tube1(:,8), 'LineWidth', 2 ) ; hold on
plot3( tip_pos.tube2(:,6), tip_pos.tube2(:,7), tip_pos.tube2(:,8), 'LineWidth', 2 ) ; hold on
title('tracker pos')
xlabel( 'x' ); ylabel( 'y' ); zlabel( 'z' );
axis equal
zlim([0, 0.12]);

% % sync test
% figure
% subplot(1,2,1) ; plot( motor_in.pos(:,2:end), 'LineWidth', 2 ) ;
% subplot(1,2,2) ; plot( tip_pos.tube1(:,6:end), 'LineWidth', 2 ) ; hold on
% subplot(1,2,2) ; plot( tip_pos.tube2(:,6:end), 'LineWidth', 2 ) ;


function Qo = Q_mult( Q1 , Q2 )
% Q = [ q0 r1 r2 r3 ] ; % quaternion format
% Q1 & Q2 are cloumn vectors
Qo = [ Q1(1) -Q1(2) -Q1(3) -Q1(4) ;
       Q1(2)  Q1(1) -Q1(4)  Q1(3) ;
       Q1(3)  Q1(4)  Q1(1) -Q1(2) ;
       Q1(4) -Q1(3)  Q1(2)  Q1(1) ] * Q2' ;
Qo = Qo' ; % row vector
   
   
function r_rot = Q_rot( Q , rQ )
% rQ = [ 0 r ].' ;
r_rot = Q_mult( Q_mult( Q , [ 0 rQ ] ) , Q_conj( Q ) ) ; % 4x1 vector
r_rot = r_rot(2:end) ;
   

function Qo = Q_conj( Q )
Qo = [ Q(1) -Q(2:4) ] ;


function y = smoothV( x )
% [ ~ , n ] = size( x ) ;
% for i = 1 : n
%     y(:,i) = smooth( x(:,i) , 'moving' , 5 ) ;
% end
y = x ;


