function par = post_proc( t , t_equil , z , z_equil , rjtip , rjtip_equil , Qjtip_all , Qjtip_equil_all , ...
    Phi_modal , M_modal , K_modal , V_modal , omega , xi , ...
    par )

fprintf( 'post-processing... \n' )
par.elapsed_time = [ par.elapsed_time toc( par.timer ) ] ;
toc( par.timer )

% robot dimensions
r_s = [ par.var(9:10); par.var(11:12); par.var(13:14) ];
l_b1 = par.var(37);
l_b2 = par.var(38);
l_b3 = par.var(39);
l_s1 = par.var(40);
l_s2 = par.var(41);
l_s3 = par.var(42);
kappa_t = par.var(end-14);

motor_in_sync = zeros(1,7);
tip_tube2_sync = zeros(1,4);

n_tube = numel( rjtip(:,1,1) );
for i = 1 : numel( t )
    tip_sim(i,:,1) = rjtip(1,4:6,i)-[0, 0, l_s1] ;
    tip_sim(i,:,2) = rjtip(2,4:6,i)-[0, 0, l_s1] ;
    motor_in_sync(i,1) = t(i);
    motor_in_sync(i,2:end) = interp1(par.user_pars.motor_in.pos(:,1), par.user_pars.motor_in.pos(:,2:end), t(i));
    tip_tube2_sync(i,1) = t(i);
    tip_tube2_sync(i,2:end) = interp1(par.user_pars.tip_pos.tube2(:,1), par.user_pars.tip_pos.tube2(:,2:end), t(i));
end

% error analysis
e_rV_t2 = tip_tube2_sync(:,2:4) - tip_sim(:,:,2) ;
e_rdV_t2 = sqrt( e_rV_t2.^2 * ones(3,1) ) ;
e_rdV_t2_ind = find(~isnan(e_rdV_t2)); e_rdV_t2 = e_rdV_t2(e_rdV_t2_ind);
e_r_t2 = sum( e_rdV_t2 ) / numel( e_rdV_t2_ind )
e_rP_t2 = sum( e_rdV_t2 ./ ( l_s2 + motor_in_sync(e_rdV_t2_ind,4) ) ) / numel( e_rdV_t2_ind ) % normalized tip MSE percentage

figure;
subplot(2,3,1); plot(t, motor_in_sync(:,[2,4]), 'LineWidth', 2);
legend('l_c', 'l_s') ; title( 'Linear Input' )
subplot(2,3,4); plot(t, kappa_t*motor_in_sync(:,7), 'LineWidth', 2);
legend('\kappa_c') ; title('Curvature Input')
for i = 1 : numel( tip_sim(1,1,:) )
    subplot(2,3,2+3*(i-1)); plot(t, tip_sim(:,:,i), 'LineWidth', 2); hold on
end
subplot(2,3,2);
legend( 'x_{sim}' , 'y_{sim}' , 'z_{sim}' ) ; title( 'Sheath Tip Position')
subplot(2,3,5); plot(t, tip_tube2_sync(:,2:4).*[1 1 1], '--', 'LineWidth', 2); hold on
legend( 'x_{sim}' , 'y_{sim}' , 'z_{sim}' , 'x_{exp}' , 'y_{exp}' , 'z_{exp}' ) ; title( 'Catheter Tip Position')
for i = 1 : numel( tip_sim(1,1,:) )
    subplot(2,3,[3,6]); plot3(tip_sim(:,1,i), tip_sim(:,2,i), tip_sim(:,3,i), 'LineWidth', 2); hold on
end
subplot(2,3,[3,6]); plot3(tip_tube2_sync(:,2), tip_tube2_sync(:,3), tip_tube2_sync(:,4), '--', 'LineWidth', 2); hold on
legend( 'Sheath_{sim}' , 'Cath._{sim}' , 'Cath._{exp}' ) ; title( 'Tip Positions')
axis equal ; xlabel( 'x[m]' ) ; ylabel( 'y[m]' ) ; zlabel( 'z[m]' ) ;
view([0 -1 0]);

pause( 1 )
save( './results/results_post_proc.mat' ) ; % save workspace



