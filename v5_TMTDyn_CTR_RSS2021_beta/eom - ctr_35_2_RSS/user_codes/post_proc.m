function par = post_proc( t , t_equil , z , z_equil , rjtip , rjtip_equil , Qjtip_all , Qjtip_equil_all , ...
    Phi_modal , M_modal , K_modal , V_modal , omega , xi , ...
    par )

fprintf( 'post-processing... \n' )
par.elapsed_time = [ par.elapsed_time toc( par.timer ) ] ;
toc( par.timer )

% robot dimensions
r_s = [ par.var(8:9); par.var(8:9); par.var(8:9); par.var(8:9); 
        par.var(10:11); par.var(10:11); par.var(10:11);
        par.var(12:13) ];
l_b1 = par.var(36);
l_b2 = par.var(37);
l_b3 = par.var(38);
l_s1 = par.var(39);
l_s2 = par.var(40);
l_s3 = par.var(41);

% Aurora tracker
d_at = 2.3e-3; % diameter
l_at = 10e-3; % length

% exp_offset = [16, 0, 194] * 1e-3;
exp_offset = [0, 0, l_b2]; % l_b2
exp_coeff = [1, 1, 1, 1, 1, 1, 1];
motor_in_sync = zeros(1,7);
tip_tube1_sync = zeros(1,8);
tip_tube2_sync = zeros(1,8);

% sync. sim and exp data
n_tube = numel( rjtip(:,1,1) );
for i = 1 : numel( t )
    for ii = 1 : n_tube
        sensor_offset = Q_rot( Qjtip_all(ii,5:8,i)' , [0; -(d_at/2+r_s(ii,2)); 0; -l_at/2 ] ) ; % from tube tip to sensor center
        tip_sim(i,:,n_tube-ii+1) = rjtip(ii,4:6,i) - exp_offset + sensor_offset(2:4)' ;
    end
    motor_in_sync(i,1) = t(i);
    motor_in_sync(i,2:end) = interp1(par.user_pars.motor_in.pos(:,1), par.user_pars.motor_in.pos(:,2:end), t(i));
    tip_tube1_sync(i,1) = t(i);
    tip_tube1_sync(i,2:end) = interp1(par.user_pars.tip_pos.tube1(:,1), par.user_pars.tip_pos.tube1(:,2:end), t(i)) * ...
        diag(exp_coeff) + 0 * [0, 0, 0, 0, exp_offset];
    tip_tube2_sync(i,1) = t(i);
    tip_tube2_sync(i,2:end) = interp1(par.user_pars.tip_pos.tube2(:,1), par.user_pars.tip_pos.tube2(:,2:end), t(i)) * ...
        diag(exp_coeff) + 0 * [0, 0, 0, 0, exp_offset+[0, 0, 0]*1e-3] ;
end

% error analysis
e_rV_t1 = tip_tube1_sync(:,6:8) - tip_sim(:,:,4) ; % tip position error vector
e_rV_t2 = tip_tube2_sync(:,6:8) - tip_sim(:,:,3) ;
e_rdV_t1 = sqrt( e_rV_t1.^2 * ones(3,1) ) ; % eucledian dis error
e_rdV_t2 = sqrt( e_rV_t2.^2 * ones(3,1) ) ;
e_rdV_t1_ind = find(~isnan(e_rdV_t1)); e_rdV_t1 = e_rdV_t1(e_rdV_t1_ind); % remove NAN elements
e_rdV_t2_ind = find(~isnan(e_rdV_t2)); e_rdV_t2 = e_rdV_t2(e_rdV_t2_ind);
e_r_t1 = sum( e_rdV_t1 ) / numel( e_rdV_t1_ind ) % tip MSE: mean square error
e_r_t2 = sum( e_rdV_t2 ) / numel( e_rdV_t2_ind )
e_rPV_t1 = e_rdV_t1 ./ ( l_s1 + motor_in_sync(e_rdV_t1_ind,2) ) * 100; % normalized tip MSE percentage
e_rPV_t2 = e_rdV_t2 ./ ( l_s2 + motor_in_sync(e_rdV_t2_ind,4) ) * 100; % normalized tip MSE percentage
e_rP_t1 = sum( e_rPV_t1 ) / numel( e_rdV_t1_ind ) % normalized tip MSE percentage
e_rP_t2 = sum( e_rPV_t2 ) / numel( e_rdV_t2_ind ) % normalized tip MSE percentage

figure;
% inputs:
% subplot(2,4,1); plot(t, z(:,[1,i2]), 'LineWidth', 2); hold on
subplot(2,4,1); plot(t, motor_in_sync(:,[2,4]), '--', 'LineWidth', 2);
% legend('l_1', 'l_2', 'l_{1exp}', 'l_{2exp}') ; title( 'Linear Input' )
legend('l_{1exp}', 'l_{2exp}') ; title( 'Linear Input' ); xlabel('t[s]'); ylabel('u_l[m]')
% subplot(2,4,5); plot(t, z(:,[2,i2+1]), 'LineWidth', 2); hold on
subplot(2,4,5); plot(t, motor_in_sync(:,[3,5]), '--', 'LineWidth', 2);
% legend('\theta_1', '\theta_2', '\theta_{1exp}', '\theta_{2exp}') ; title('Rotational Input')
legend('\theta_{1exp}', '\theta_{2exp}') ; title('Rotational Input') ; xlabel('t[s]'); ylabel('u_\phi[rad]')
% pos. sim:
subplot(2,4,2); plot(t, tip_sim(:,:,4), 'LineWidth', 2); hold on
subplot(2,4,3); plot(t, tip_sim(:,:,3), 'LineWidth', 2); hold on
% pos. exp.:
subplot(2,4,2); plot(t, tip_tube1_sync(:,6:8).*[1 1 1], '--', 'LineWidth', 2); hold on
legend( 'x_{1}' , 'y_{1}' , 'z_{1}' , 'x_{1exp}' , 'y_{1exp}' , 'z_{1exp}' ) ; title( 'Tip 1 Positions'); xlabel('t[s]'); ylabel('xyz[m]')
subplot(2,4,3); plot(t, tip_tube2_sync(:,6:8).*[1 1 1], '--', 'LineWidth', 2); hold on
legend( 'x_{2}' , 'y_{2}' , 'z_{2}' , 'x_{2exp}' , 'y_{2exp}' , 'z_{2exp}' ) ; title( 'Tip 2 Positions'); xlabel('t[s]'); ylabel('xyz[m]')
% error:
subplot(2,4,6);
plot(t(e_rdV_t1_ind), e_rV_t1(e_rdV_t1_ind,:), '--' , t(e_rdV_t1_ind) , e_rdV_t1 , '-' , 'LineWidth', 2);
xlabel('t[s]'); ylabel('e[m]')
yyaxis right; plot(t(e_rdV_t1_ind) , e_rPV_t1 , '-' , 'LineWidth', 2);
legend( 'e_x' , 'e_y' , 'e_z' , '|e|' , '|e|%' ) ; title( 'Tip 1 Position Error'); xlabel('t[s]'); ylabel('e%')
subplot(2,4,7);
plot(t(e_rdV_t1_ind), e_rV_t2(e_rdV_t1_ind,:), '--' , t(e_rdV_t1_ind) , e_rdV_t2 , '-' , 'LineWidth', 2);
xlabel('t[s]'); ylabel('e[m]')
yyaxis right; plot(t(e_rdV_t1_ind) , e_rPV_t2 , '-' , 'LineWidth', 2);
legend( 'e_x' , 'e_y' , 'e_z' , '|e|' , '|e|%' ) ; title( 'Tip 2 Position Error'); xlabel('t[s]'); ylabel('e%')
% 3D:
for i = 1 : numel( tip_sim(1,1,:) )
    subplot(2,4,[4,8]); plot3(tip_sim(:,1,i), tip_sim(:,2,i), tip_sim(:,3,i), 'LineWidth', 2); hold on
end
subplot(2,4,[4,8]); plot3(tip_tube1_sync(:,6), tip_tube1_sync(:,7), tip_tube1_sync(:,8), '--', 'LineWidth', 2); hold on
subplot(2,4,[4,8]); plot3(tip_tube2_sync(:,6), tip_tube2_sync(:,7), tip_tube2_sync(:,8), '--', 'LineWidth', 2); hold on
legend( 'tube_{11}' , 'tube_{12}' , 'tube_{13}' , 'tube_{21}' , 'tube_{22}' , 'tube_{1exp}' , 'tube_{2exp}' , 'Location', 'north' ) ; title( 'Tip Positions')
axis equal ; zlim ( [0 1.1*max(tip_sim(:,3,3))] ); xlabel( 'x[m]' ) ; ylabel( 'y[m]' ) ; zlabel( 'z[m]' ) ;

pause( 1 )
save( './results/results_post_proc.mat' ) ; % save workspace


