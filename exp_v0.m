function [motor_in, tip_pos, tip_load, g_dir] = exp_v0( exp_case , l_s )

% extract
switch exp_case(1) % exp. cases
    case 1 % basic motions
        load ('exp/basic.mat' ) ; % t lw1 lw2 lw3 lw4 fw1 fw2 fw3 fw4 ty tx tz Qtx Qty Qtz dl_t
        temp_motor = basic(:,1); % time
        temp_motor(:,2:6) = basic(:,[2:5,16]) * 1e-3 ; % motor inputs
        temp_tube1 = basic(:,1); % time     
        temp_tube1(:,2:4) = basic(:,10:12) * 1e-3 ; % tube tip position 
        
        temp_tip_load = basic(:,1); % time
        temp_tip_load(:,2:4) = 0 ; % f_xyz
        temp_tip_load(:,5) = 1 ; % load tip no
        
        ssteps = 2e10 * [ 1 1 1 1 ] ; % smooth steps
        
        % postprocess
        temp_motor = temp_motor(4:end,:) - temp_motor(4,:) ; % remove bias
        temp_motor(:,6) = 15e-3 ; % initial introducer length
        temp_tube1 = temp_tube1(4:end,:) - temp_tube1(4,:) ; % remove bias
        temp_tube1(:,4) = temp_tube1(:,4) + l_s(2) + temp_motor(1,6); % adjust for tracker refrence position
        temp_tube1(:,2:4) = [ -temp_tube1(:,2) -temp_tube1(:,3) temp_tube1(:,4) ]; % align tracker frame with simulation frame
        
        g_dir = 1; % upward
        
    case 2 % umbrella shape pos. exp
        load ('exp/umbrella.mat' ) ; % t lw1 lw2 lw3 lw4 fw1 fw2 fw3 fw4 ty tx tz Qtx Qty Qtz dl_t
        temp_motor = umbrella(:,1); % time
        temp_motor(:,2:6) = 0.8 * umbrella(:,[2:5,16]) * 1e-3 ; % motor inputs
        temp_tube1 = umbrella(:,1); % time     
        temp_tube1(:,2:4) = umbrella(:,10:12) * 1e-3 ; % tube tip position 
        
        temp_tip_load = umbrella(:,1); % time
        temp_tip_load(:,2:4) = 0 ; % f_xyz
        temp_tip_load(:,5) = 1 ; % load tip no
        
        ssteps = 1e0 * [ 1 1 1 1 ] ; % smooth steps
        
        % postprocess
        temp_motor = temp_motor(4:end,:) - temp_motor(4,:) ; % remove bias
        temp_motor(:,6) = 1e-3 ; % initial introducer length
        temp_tube1 = temp_tube1(4:end,:) - temp_tube1(4,:) ; % remove bias
        temp_tube1(:,4) = temp_tube1(:,4) + l_s(2) + temp_motor(1,6); % adjust for tracker refrence position
        temp_tube1(:,2:4) = [ -temp_tube1(:,3) -temp_tube1(:,2) temp_tube1(:,4) ]; % align tracker frame with simulation frame
        
        g_dir = 1; % upward

    case 3 % introducer motion and weight
        load('exp/introducer_weight.mat') ; % t lw1 lw2 lw3 lw4 fw1 fw2 fw3 fw4 ty tx tz Qtx Qty Qtz dl_t
        temp_motor = introducer_weight(:,1); % time
        temp_motor(:,2:6) = introducer_weight(:,[2:5,16]) * 1e-3 ; % motor inputs
        temp_tube1 = introducer_weight(:,1); % time     
        temp_tube1(:,2:4) = introducer_weight(:,10:12) * 1e-3 ; % tube tip position 
        
        temp_tip_load = introducer_weight(:,1); % time
        temp_tip_load(:,2:4) = introducer_weight(:,17:19) * 9.81 * 1e-3 ; % f_xyz, gravity is upward in this frame
        temp_tip_load(:,5) = introducer_weight(:,20) ; % load tip no
        
        ssteps = [ 1 30 1 1 ] ; % smooth steps
        
        % postprocess
        % temp_motor = temp_motor - temp_motor(1,:) ; % remove bias
        temp_tube1 = temp_tube1(4:end,:) - temp_tube1(4,:) ; % remove bias
        temp_tube1(:,4) = temp_tube1(:,4) + l_s(2) + temp_motor(1,6); % adjust for tracker refrence position
        temp_tube1(:,2:4) = [ temp_tube1(:,2) temp_tube1(:,3) temp_tube1(:,4) ]; % align tracker frame with simulation frame
        
        g_dir = -1 ; % downward
        
    case 4 % tip force sensor load
        
        g_dir = -1 ; % downward
        
    case 5 % catheter weight and introducer motion
        load('exp/introducer_weight_new.mat') ; % t lw1 lw2 lw3 lw4 fw1 fw2 fw3 fw4 ty tx tz Qtx Qty Qtz dl_t
        temp_motor = introducer_weight_new(:,1); % time
        temp_motor(:,2:6) = introducer_weight_new(:,[2:5,16]) * 1e-3 ; % motor inputs
        temp_tube1 = introducer_weight_new(:,1); % time     
        temp_tube1(:,2:4) = introducer_weight_new(:,10:12) * 1e-3 ; % tube tip position 
        
        temp_tip_load = introducer_weight_new(:,1); % time
        temp_tip_load(:,2:4) = introducer_weight_new(:,17:19) * 9.81 * 1e-3 ; % f_xyz, gravity is upward in this frame
        temp_tip_load(:,5) = introducer_weight_new(:,20) ; % load tip no
        
        ssteps = [ 1 200 1 1 ] ; % smooth steps
        
        % postprocess
        % temp_motor = temp_motor - temp_motor(1,:) ; % remove bias
        temp_tube1 = temp_tube1(4:end,:) - temp_tube1(4,:) ; % remove bias
        temp_tube1(:,4) = temp_tube1(:,4) + l_s(2) + temp_motor(1,6); % adjust for tracker refrence position
        temp_tube1(:,2:4) = [ temp_tube1(:,3) -temp_tube1(:,2) temp_tube1(:,4) ]; % align tracker frame with simulation frame
        
        g_dir = -1 ; % downward
end

% smooth
temp_motor(:,2:end) = smoothV( temp_motor(:,2:end) , ssteps(1) ) ;
temp_tube1(:,2:end) = smoothV( temp_tube1(:,2:end) , ssteps(2) ) ;
temp_tip_load(:,2:end) = smoothV( temp_tip_load(:,2:end) , ssteps(3) ) ;

% motor accelerations
for i = 2 : numel( temp_motor(1,:) )
    temp_motor_vel(:,i) = [ 0; diff( temp_motor(:,i) ) ] / ( temp_motor(2,1) - temp_motor(1,1) ) ;
    temp_motor_acc(:,i) = [ 0; diff( temp_motor_vel(:,i) ) ] / ( temp_motor(2,1) - temp_motor(1,1) ) ;
end
temp_motor_vel(:,1) = temp_motor(:,1);
temp_motor_vel(:,2:end) = smoothV( temp_motor_vel(:,2:end) , ssteps(4) ) ;
temp_motor_acc(:,1) = temp_motor(:,1);
temp_motor_acc(:,2:end) = smoothV( temp_motor_acc(:,2:end) , ssteps(4) ) ;

% tube tip accelerations
for i = 2 : numel( temp_tube1(1,:) )
    temp_tube1_vel(:,i) = [ 0; diff( temp_tube1(:,i) ) ] / ( temp_tube1(2,1) - temp_tube1(1,1) ) ;
    temp_tube1_acc(:,i) = [ 0; diff( temp_tube1_vel(:,i) ) ] / ( temp_tube1(2,1) - temp_tube1(1,1) ) ;
end
temp_tube1_vel(:,1) = temp_tube1(:,1);
temp_tube1_vel(:,2:end) = smoothV( temp_tube1_vel(:,2:end) , ssteps(4) ) ;
temp_tube1_acc(:,1) = temp_tube1(:,1);
temp_tube1_acc(:,2:end) = smoothV( temp_tube1_acc(:,2:end) , ssteps(4) ) ;

% assign outputs
tip_pos.tube1 = temp_tube1;
tip_pos.tube1_vel = temp_tube1_vel;
tip_pos.tube1_acc = temp_tube1_acc;
motor_in.pos = temp_motor;
motor_in.vel = temp_motor_vel;
motor_in.acc = temp_motor_acc;
tip_load = temp_tip_load ;

% plot
figure ;
subplot(3,4,1) ; plot( motor_in.pos(:,1), motor_in.pos(:,2:5), 'LineWidth', 2 ) ;
title('tendon displacements')
subplot(3,4,5) ; plot( motor_in.vel(:,1), motor_in.vel(:,2:5), 'LineWidth', 2 ) ;
title('tendon velocity')
subplot(3,4,9) ; plot( motor_in.acc(:,1), motor_in.acc(:,2:5), 'LineWidth', 2 ) ;
title('tendon acceleration')
subplot(3,4,2) ; plot( motor_in.pos(:,1), motor_in.pos(:,6), 'LineWidth', 2 ) ;
title('introducer displacement')
subplot(3,4,6) ; plot( motor_in.pos(:,1), motor_in.vel(:,6), 'LineWidth', 2 ) ;
title('introducer velocity')
subplot(3,4,10) ; plot( motor_in.pos(:,1), motor_in.acc(:,6), 'LineWidth', 2 ) ;
title('introducer acceleration')
subplot(3,4,3) ; plot( tip_pos.tube1(:,1), tip_pos.tube1(:,2:4), 'LineWidth', 2 ) ;
title('robot tip position')
subplot(3,4,7) ; plot( tip_pos.tube1(:,1), tip_pos.tube1_vel(:,2:4), 'LineWidth', 2 ) ;
title('robot tip velocity')
subplot(3,4,11) ; plot( tip_pos.tube1(:,1), tip_pos.tube1_acc(:,2:4), 'LineWidth', 2 ) ;
title('robot tip acceleration')
subplot(3,4,12) ; plot( tip_load(:,1), tip_load(:,2:4), 'LineWidth', 2 ) ;
title('robot tip force')
subplot(3,4,[4,8]) ;
plot3( tip_pos.tube1(:,2), tip_pos.tube1(:,3), tip_pos.tube1(:,4), 'LineWidth', 2 ) ; hold on
title('robot tip')
xlabel( 'x' ); ylabel( 'y' ); zlabel( 'z' );
axis equal
% zlim([0, 0.12]);


function y = smoothV( x , step )

% y = x ; return

if nargin < 2
    step = 10 ;
end

[ ~ , n ] = size( x ) ;
for i = 1 : n
    y(:,i) = smooth( x(:,i) , step , 'moving' ) ;
end


