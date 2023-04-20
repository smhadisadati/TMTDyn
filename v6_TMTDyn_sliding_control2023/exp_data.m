function [motor_in, tip_pos] = exp_data( exp_case )

% setup specs
base_sensor_pos = [0/2+5+2.4, 0, -5] * 1e-3; % ref. tracker to insertion hole offset in final frame (tubes along z)
                                             % sensor_thickness/2+hole_side_offset+outermost_tube_dia: assuming the tubes slide against the hole top wall
step2motion_coeff = [1e-3, -1, -473088/180/(614400/360)*pi/180, -1, -473088/180/(614400/360)*pi/180, 1, 1]; % t, outlin, outrot, inlin, inrot

% system backlash range: [ start end ], controls the initial backlash direction too
% backlash = [ -1.5e-3 0 ; 0 40*pi/180 ; 0 1.5e-3 ; -20*pi/180 70*pi/180 ; 0 0 ; 0 0 ] ; % [ outlin; outrot; inlin; inrot ]
backlash = [ -1.5e-3 0 ; -5*pi/180 13*pi/180 ; 0 1.5e-3 ; -15*pi/180 0 ; 0 0 ; 0 0 ] ; % [ outlin; outrot; inlin; inrot ]
init_input = zeros(1,6); % actual input initialization

% extract
sync_sample = [1, 1; 1, 1];
switch exp_case(1) % exp. cases
    case 1 % basic motions - new dataset
        load ('exp/basicsNew.mat' ) ; % basics_motor: t, outlin, outrot, inlin, inrot
                                   % basics_tip: t, Q0, Qx, Qy, Qz, x, y, z, ... (tip, base, mid)
        % figure; plot(basics_motor)
        % figure; plot(basics_tip(:,2:4))
        
        % sync_sample = [5163, 6547; 3088, 3627]; % [ motor ; Tracker] shorter span
        sync_sample = [5163, 17900; 3088, 8113]; % [ motor ; Tracker] % longer span
        sync_coeff = ( sync_sample(2,2) - sync_sample(2,1) ) / ( sync_sample(1,2) - sync_sample(1,1) ) ; % tracker to input time coeff
        
        % Extract samples to avoid repeated count of stationary points in error analysis:
%         samples = 4800:18500 ; % based on inputs
%         samples = 4800+[0:1849,3137:4477,7338:9613,10854:13600] ; % based on motor input time
        set_samp = 200; % settlment samples after motion finished
%         samples = [5204-set_samp:5291+set_samp,5873,6457-set_samp:6543+set_samp,7087,8031-set_samp:8119+set_samp,8611,9069-set_samp:9187+set_samp,9648,...
%             12149-set_samp:14336+set_samp,15023,15712-set_samp:17754+set_samp,18041] ; % based on motor input time
        samples = [5204-set_samp:5291+set_samp,5873,6457-set_samp:6543+set_samp,7087,8031-set_samp:8119+set_samp,8611,9069-set_samp:9187+set_samp,9648,...
            12149-set_samp:12907+set_samp,13226,13624-set_samp:14336+set_samp,15023,15712-set_samp:16423+set_samp,16728,17042-set_samp:17754+set_samp,18041] ; % based on motor input time
        samples(2,:) = floor( sync_coeff * ( samples - sync_sample(1,1) ) + 1.0*sync_sample(2,1) ) ; % for EM trackers, consider a correction factor here!
               
        temp_motor = basics_motor(samples(1,:),:);
        temp_motor(end,7) = 0;
        temp_tube1 = basics_tip(unique(samples(2,:)),[1,16:22]); % mid
        temp_tube2 = basics_tip(unique(samples(2,:)),[1,2:8]); % tip
        % figure; plot(temp_motor(:,2:end))
        % figure; plot(temp_tube1(:,2:end))
        % figure; plot(temp_tube2(:,2:end))
        
        backlash_dyn = [ 4300, 0.7; 6520, 0.1]; % [ data_point, caused_delay ]
        t_equil = [9, 37, 85, 122 ];
        t_init = [0, 31, 73, 108, 136];
        
    case 2 % random motions
        
end

% duration
tube_t0 = temp_tube1(1,1);
motor_t0 = temp_motor(1,1);
dt = ( temp_motor(end,1) - motor_t0 ) / 1e3 ; % exp duration in ms
t_coeff = ( temp_tube1(end,1) - tube_t0 ) / dt ; % for tracker based on motor inputs

% smooth
temp_motor(:,2:end) = smoothV( temp_motor(:,2:end) , 100 ) ;
temp_tube1(:,2:end) = smoothV( temp_tube1(:,2:end) , 100 ) ;
temp_tube2(:,2:end) = smoothV( temp_tube2(:,2:end) , 100 ) ;

% conditioning#
tube1_inf = []; tube2_inf = [];
for i = 1 : numel( temp_tube1(:,1) )    
    % time offset/scale adjustment and add base offset
    temp_tube1(i,1) = ( temp_tube1(i,1) - tube_t0 ) / t_coeff;
    temp_tube1(i,6:8) = temp_tube1(i,6:8) / 1e3 ; % mid segment
    temp_tube2(i,1) = ( temp_tube2(i,1) - tube_t0 ) / t_coeff;
    temp_tube2(i,6:8) = temp_tube2(i,6:8) / 1e3 ; % tip segment
    % find singular points
    if abs( temp_tube1(i,8) ) > 1e6
        tube1_inf = [tube1_inf, i];
    end
    if abs( temp_tube2(i,8) ) > 1e6
        tube2_inf = [tube2_inf, i];
    end
end
% remove singular points
temp_tube1(tube1_inf,:) = [];
temp_tube2(tube2_inf,:) = [];
% rotate base frame (Q is diregarded so is not correct)
temp_tube1 = [temp_tube1(:,1:5), temp_tube1(:,8), (temp_tube1(:,7)-temp_tube1(1,7)), -temp_tube1(:,6)];
temp_tube2 = [temp_tube2(:,1:5), temp_tube2(:,8), (temp_tube2(:,7)-temp_tube2(1,7)), -temp_tube2(:,6)];
% sensor offset
temp_tube1(:,6:8) = temp_tube1(:,6:8) + base_sensor_pos ;
temp_tube2(:,6:8) = temp_tube2(:,6:8) + base_sensor_pos ;

% step in inc to motion in mm & rad
temp_motor = temp_motor - temp_motor(1,:);
temp_motor = temp_motor .* step2motion_coeff;

% input backlash
temp_input(:,1) = temp_motor(:,1) ; % actual input after backlash
for i_u = 2 : numel( temp_motor(1,:) ) % check all inputs
    temp_input(1,i_u) = init_input(i_u-1); % from actual input intiitalization
    for i = 2 : numel( temp_motor(:,1) ) % check all datapoints
        du = temp_motor(i,i_u) - temp_motor(i-1,i_u) ; % change in the motor input
        if temp_motor(i,i_u) < backlash(i_u-1,1) || ... % moves lower than backlash low range
                temp_motor(i,i_u) > backlash(i_u-1,2) % moves higher than backlash high range
            backlash(i_u-1,:) = backlash(i_u-1,:) + du ; % update backlash range
            temp_input(i,i_u) = temp_input(i-1,i_u) + du ; % update actual input
        else
            temp_input(i,i_u) = temp_input(i-1,i_u) ; % no change in the output value
        end
    end
end

% cancel backlash dynamic effect
for i = 1 : numel( backlash_dyn(:,1) )
    temp_input(backlash_dyn(i,1):end,1) = temp_input(backlash_dyn(i,1):end,1) + backlash_dyn(i,2);
end

% input accelerations
for i = 2 : numel( temp_input(1,:) )
    temp_motor_vel(:,i) = [ 0; diff( temp_input(:,i) ) ] / ( temp_input(2,1) - temp_input(1,1) ) ;
    temp_motor_acc(:,i) = [ 0; diff( temp_motor_vel(:,i) ) ] / ( temp_input(2,1) - temp_input(1,1) ) ;
end
temp_motor_vel(:,1) = temp_input(:,1);
temp_motor_vel(:,2:end) = smoothV( temp_motor_vel(:,2:end) ) ;
temp_motor_acc(:,1) = temp_input(:,1);
temp_motor_acc(:,2:end) = smoothV( temp_motor_acc(:,2:end) ) ;

% output
tip_pos.tube1 = temp_tube1; % [t Q0 Qv1 Qv2 Qv3 x y z]
tip_pos.tube2 = temp_tube2;
motor_in.pos = temp_input; % [t tube1_lin tube1_rot tube2_lin tube2_rot tube3_lin tube3_rot]
motor_in.vel = temp_motor_vel;
motor_in.acc = temp_motor_acc;

% plot
figure ;
subplot(2,5,1) ; plot( temp_motor(:,1), temp_motor(:,[2,4]) ) ; hold on
subplot(2,5,1) ; plot( motor_in.pos(:,1), motor_in.pos(:,[2,4]), 'LineWidth', 2 ) ;
title('lin motor pos')
subplot(2,5,6) ; plot( motor_in.acc(:,1), motor_in.acc(:,[2,4]), 'LineWidth', 2 ) ;
title('lin motor ac')
subplot(2,5,2) ; plot( temp_motor(:,1), temp_motor(:,[3,5]) ) ; hold on
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


function y = smoothV( x , steps )
if nargin < 2
    steps = 10 ;
end
[ ~ , n ] = size( x ) ;
for i = 1 : n
    y(:,i) = smooth( x(:,i) , 'moving' , steps ) ;
end
% y = x ;


