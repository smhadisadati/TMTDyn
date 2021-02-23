function [motor_in, tip_pos] = exp_v2( exp_case )

% extract
switch exp_case(1) % exp. cases
    case 1 % simple run
        
        % 3mm tendon pull
        % 5mm insertion
        % extend pressure 150KPa
        % extend pressure for catheter motion 5KPa
        % retract pressure 100KPa
        % retract pressure for catheter motion 5KPa
        
        rho_ex = [5, 0, 44;
            2, 0, 45;
            1, 0, 45
            0, 0, 45]; % ex load point
        l_ex = sqrt(rho_ex.^2*[1; 1; 1]);
        % kappa = 1/27e-3; % from experiment picture
        kappa = 1;
        
        data = ... % [t, kappa, l_c, l_s, l_ex, x_t, z_t]
            [1.54, 0, 4, 4, 0, 0, 4;
            1.81, 0, 1, 4, 0, 0, 4;
            2.81, 0, 7, 8, 0, 0, 8;
            3.56, 0, 4, 8, 0, 0, 8;
            3.81, 0, 14, 15, 0, 0, 15;
            4.56, 0, 10, 13, 0, 0, 13;
            5.06, 0, 19, 20, 0, 0, 20;
            5.81, 0, 15, 18, 0, 0, 18;
            6.31, 0, 24, 25, 0, 0, 25;
            7.06, 0, 20, 23, 0, 0, 23;
            7.56, 0, 25, 26, 0, 0, 26;
            7.81, 0, 30, 31, 0, 0, 31;
            8.31, 0, 25, 28, 0, 0, 28;
            9, 0, 34, 35, 0, 0, 35;
            9.5, 0, 31, 32, 0, 0, 32;
            10.25, 0, 39, 40, 0, 0, 40;
            11, 0, 37, 38, 0, 0, 38;
            11.5, 0, 44, 45, 0, 0, 45;
            12.5, 0, 41, 42, 0, 0, 42;
            13.75, kappa, 41, 42, 0, 10, 37;
            15, kappa, 45, 46, 0, 6.6, 48;
            15.5, kappa, 44, 45, 0, 6.6, 44;
            16.25, kappa, 50, 52, 0, 9.3, 53; % l_ex(1);
            17, kappa, 49, 50, 0, 7.5, 48; % l_ex(1);
            17.5, kappa, 55, 56, 0, 11.6, 58; % l_ex(1);
            18, kappa, 54, 55, 0, 9.3, 54; % l_ex(2);
            18.75, kappa, 62, 63, 0, 10.5, 59; % l_ex(3);
            20.5, kappa, 61, 62, 0, 8.7, 60; % l_ex(4);
            21.5, 0, 61, 62, l_ex(4), 3, 63;
            21.97, 0, 52, 54, l_ex(4), 2.7, 57;
            22.64, 0, 56, 57, l_ex(4), 2.3, 55;
            23.39, 0, 49, 50, l_ex(4), 1.6, 50;
            24.64, 0, 44, 45, l_ex(4), 1.1, 46;
            25.8, 0, 41, 44, 0, 1, 44;
            26.3, 0, 43, 44, 0, 1, 44;
            26, 0, 36, 41, 0, 1, 41;
            26.55, 0, 40, 41, 0, 1, 41];
        data(:,1) = data(:,1) - data(1,1);
        % tf = 25; % [s]
                
    case 2 % navigation
        rho_ex = [2, 0, 28]; % ex load point
        l_ex = sqrt(rho_ex.^2*[1; 1; 1]);
        % kappa = 1/27e-3; % from experiment picture
        kappa = 1;
        
        data = ... % [t, kappa, l_c, l_s, l_ex, x_t, z_t]
            [2, 0, 0, 4, 0, 0, 4;
            2.5, 0, 4, 12, 0, 0, 12;
            3, 0, 0, 12, 0, 0, 12
            3.5, 0, 8, 15, 0, 0, 15;
            4, 0, 5, 15, 0, 0, 15;
            5, 0, 16, 20, 0, 0, 20;
            6, 0, 12, 20, 0, 0, 20;
            7, 0, 21, 23, 0, 0, 23;
            8, 0, 18, 23, 0, 0, 23;
            9, kappa, 18, 23, 0, 6.7, 22;
            10, kappa, 26, 29, 0, 6.7, 26.2;
            11, kappa, 21, 29, 0, 6.7, 26;
            12, kappa, 31, 35, 0, 6.5, 31.5;
            12.5, kappa, 26, 35, l_ex, 6.5, 31.5
            13, kappa, 37, 39, l_ex, 6.3, 37.25;
            14, kappa, 32, 39, l_ex, 6.7, 35.3;
            15, 0, 32, 39, l_ex, 4, 34;
            16, 0, 44, 45, l_ex, 6.2, 45;
            16.5, 0, 39, 45, l_ex, 6, 45;
            18, -kappa, 39, 45, l_ex, 0, 41;
            20, -kappa, 50, 51, l_ex, 0, 48.5;
            21, -kappa, 43, 51, l_ex, 0, 45;
            22, -kappa, 54, 55, l_ex, 0, 53;
            22.5, -kappa, 48, 55, l_ex, 4.3, 49;
            23, -kappa, 59, 60, l_ex, 0, 58;
            25, -kappa, 52, 60, l_ex, 5, 53;
            26, -kappa, 64, 65, l_ex, 0, 64;
            27, -kappa, 58, 60, l_ex, 0, 60;
            27.5, -kappa, 69, 70, l_ex, 4.5, 64;
            28, -kappa, 62, 64, l_ex, 4.8, 61;
            28.5, -kappa, 74, 75, l_ex, 9, 67;
            29, -kappa, 66, 67, l_ex, 6.5, 65];
        %  31, 0, 66, 67, l_ex, 4.4, 68; % double contact from here
        %  32, 0, 58, 67, l_ex, 4, 64;
        %  33, 0, 50, 60, l_ex, 2, 60;];        
        data(:,1) = data(:,1) - data(1,1);
        % tf = 27; % [s]
        
end
temp_motor(:,[1,2,4,6,7]) = ... % [t l_c 0 l_s 0 l_ex kappa]
    [ data(:,1) data(:,3:5)*1e-3 data(:,2) ];
temp_motor(end,7) = 0;
temp_tube2(:,[1,2,4]) = [ data(:,1), data(:,[6,7])*1e-3 ]; % tip

% output
motor_in.pos = temp_motor;
tip_pos.tube2 = temp_tube2;

% plot
figure ;
subplot(2,3,1) ; plot( motor_in.pos(:,1), motor_in.pos(:,[2,4]), 'LineWidth', 2 ) ;
title('lin motor pos')
subplot(2,3,2) ; plot( motor_in.pos(:,1), motor_in.pos(:,7), 'LineWidth', 2 ) ;
title('kappa')
subplot(2,3,4) ; plot( motor_in.pos(:,1), motor_in.pos(:,6), 'LineWidth', 2 ) ;
title('L_s ext. load')
subplot(2,3,5) ; plot( tip_pos.tube2(:,1), tip_pos.tube2(:,2:4), 'LineWidth', 2 ) ;
title('tip pos')
subplot(2,3,[3,6]) ; plot3( tip_pos.tube2(:,2), tip_pos.tube2(:,3), tip_pos.tube2(:,4), 'LineWidth', 2 ) ;
xlabel( 'x' ); ylabel( 'y' ); zlabel( 'z' );

