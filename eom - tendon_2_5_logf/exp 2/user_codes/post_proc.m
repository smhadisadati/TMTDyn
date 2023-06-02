function par = post_proc( t , t_equil , z , z_equil , rjtip , rjtip_equil , Qjtip_all , Qjtip_equil_all , ...
    Phi_modal , M_modal , K_modal , V_modal , omega , xi , ...
    par )

fprintf( 'post-processing... \n' )
par.elapsed_time = [ par.elapsed_time toc( par.timer ) ] ;
toc( par.timer )

% robot dimensions
l_s1 = par.var(16);
l_s2 = par.var(17);
d_ow = par.var(9) + par.var(10) ; % wire offsets diameter: 2*(r_s21+r_s22)/2

motor_in_sync = zeros(1,6);
tip_tube_sync = zeros(1,4);

n_tube = numel( rjtip(:,1,1) );
for i_t = 1 : numel(t) % rearrange rjtip
    for i_tube = 1 : n_tube
        rjtip_reshape(i_t,:,i_tube) = rjtip(i_tube,:,i_t) ;
    end
end

% t_sync = t ; % sync based on sim time
t_sync = par.user_pars.motor_in.pos(:,1) ; % sync based on exp time
for i = 1 : numel( t_sync )
    tip_sim_sync(i,:,1) = interp1(t, rjtip_reshape(:,4:6,1), t_sync(i), 'linear', 'extrap') ;
    motor_in_sync(i,1) = t_sync(i);
    motor_in_sync(i,2:end) = interp1(par.user_pars.motor_in.pos(:,1), par.user_pars.motor_in.pos(:,2:end), t_sync(i), 'linear', 'extrap');
    tip_tube_sync(i,1) = t_sync(i);
    tip_tube_sync(i,2:end) = interp1(par.user_pars.tip_pos.tube1(:,1), par.user_pars.tip_pos.tube1(:,2:end), t_sync(i), 'linear', 'extrap');
    
    %% curvature inputs
    q_u = motor_in_sync(i,2:end);
    l_w = q_u(1:4) + l_s2;
    
    % % 3 tendons
    % kappa = 2*sqrt(l(1)^2+l(2)^2+l(3)^2-l(1)*l(2)-l(1)*l(3)-l(2)*l(3))/(d*(l(1)+l(2)+l(3)));
    % phi = atan2(sqrt(3)*(l(2)+l(3)-2*l(1)),(3*(l(2)-l(3))));
    
    % 4 tendons
    l_b = ( l_w(1) + l_w(2) + l_w(3) + l_w(4) ) / 4;
    % l_b = l_s2;
    phi = atan2(l_w(2)-l_b,l_w(1)-l_b);
    kappa = ( l_b - l_w(1) ) / ( l_b * d_ow/2 * cos(phi) ) ;
    % model inputs
    kappa_x = kappa * sin( phi );
    kappa_y = kappa * cos( phi );
    kappa_xy(i,1:2) = [ kappa_x kappa_y ] ;
    
    if t_sync(i) > t(end) % sync up to sim time
        break
    end
    
end
i_end = i ;

% error analysis
e_rV_t2 = tip_tube_sync(:,2:4) - tip_sim_sync(:,:,1) ;
e_rdV_t2 = sqrt( e_rV_t2.^2 * ones(3,1) ) ;
e_rdV_t2_ind = find(~isnan(e_rdV_t2)); e_rdV_t2 = e_rdV_t2(e_rdV_t2_ind);
e_r_t2 = sum( e_rdV_t2 ) / numel( e_rdV_t2_ind )
e_rP_t2 = sum( e_rdV_t2 ./ ( l_s1 + motor_in_sync(e_rdV_t2_ind,5) ) ) / numel( e_rdV_t2_ind ) % normalized tip MSE percentage

figure;
subplot(2,4,1); plot(t_sync(1:i_end), motor_in_sync(:,2:5), 'LineWidth', 2);
title( 'tendon displacmenets' )
subplot(2,4,5); plot(t_sync(1:i_end), kappa_xy, 'LineWidth', 2);
legend( '\kappa_x' , '\kappa_y' ) ; title( 'initial curvatures' )
subplot(2,4,[2,6]) ; plot( t_sync(1:i_end), motor_in_sync(:,6), 'LineWidth', 2 ) ;
title('introducer displacement')
subplot(2,4,[3,7]); plot(t_sync(1:i_end), tip_sim_sync(:,:,1), 'LineWidth', 2); hold on
subplot(2,4,[3,7]); plot(t_sync(1:i_end), tip_tube_sync(:,2:4).*[1 1 1], '--', 'LineWidth', 2); hold on
legend( 'x_{sim}' , 'y_{sim}' , 'z_{sim}' , 'x_{exp}' , 'y_{exp}' , 'z_{exp}' ) ; title( 'Tip Position')
subplot(2,4,[4,8]); plot3(tip_sim_sync(:,1,1), tip_sim_sync(:,2,1), tip_sim_sync(:,3,1), 'LineWidth', 2); hold on
subplot(2,4,[4,8]); plot3(tip_tube_sync(:,2), tip_tube_sync(:,3), tip_tube_sync(:,4), '--', 'LineWidth', 2); hold on
legend( 'sim' , 'exp' , 'Location' , 'north' ) ; title( 'Tip Positions')
axis equal ; xlabel( 'x[m]' ) ; ylabel( 'y[m]' ) ; zlabel( 'z[m]' ) ;
% view([0 -1 0]);

pause( 1 )
save( './results/results_post_proc.mat' ) ; % save workspace



