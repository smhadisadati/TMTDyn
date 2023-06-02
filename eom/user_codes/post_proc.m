function par = post_proc( t , t_equil , z , z_equil , rjtip , rjtip_equil , Qjtip_all , Qjtip_equil_all , ...
    Phi_modal , M_modal , K_modal , V_modal , omega , xi , ...
    par )

fprintf( 'post-processing... \n' )
par.elapsed_time = [ par.elapsed_time toc( par.timer ) ] ;
toc( par.timer )

Err_vec = zeros( 1 , 3 ) ; 
for i = 1 : numel( t )
    tip_sim(i,:) = rjtip(end,4:6,i) ;
    % error analysis
    step = floor( t(i) / 0.05 ) ;
    Err_vec(i,:) = par.user_pars.tip_pos(step,2:4) - tip_sim(i,:) ;
    Err_abs_all(i) = sqrt( Err_vec(i,:) * Err_vec(i,:)' ) ;    
end

Err_abs = mean( Err_abs_all )
Err_std = std( Err_abs_all )
Err_norm = Err_abs / ( par.var(5) + par.var(17) ) * 100

figcompare = figure ;
subplot(1,2,1)
plot( par.user_pars.tip_pos(:,1) , par.user_pars.tip_pos(:,2:4) , '--' , t , tip_sim , '-' , 'LineWidth' , 2 ) ;
legend( 'x_{exp}' , 'y_{exp}' , 'z_{exp}' , 'x_{sim}' , 'y_{sim}' , 'z_{sim}' ) ; title( 'Sim.')

% tip_exp_ali = transformed ( par.tip_exp(:,2:4) ) ;
% figure  ;
% plot( par.tip_exp(:,1) , tip_exp_ali , '--' , t_all , tip_sim , linetype , 'LineWidth' , 2 ) ;
% legend( 'x_{exp}' , 'y_{exp}' , 'z_{exp}' , 'x_{sim}' , 'y_{sim}' , 'z_{sim}' ) ;

% for i = 1 : 3
%     tip_sim_avg(:,i) = smooth( tip_sim(:,i) , 'moving' , 31 ) ;
% end
% figure  ;
% plot( par.tip_exp(:,1) , par.tip_exp(:,2:4) , '--' , t_all , tip_sim_avg , linetype , 'LineWidth' , 2 ) ;
% legend( 'x_{exp}' , 'y_{exp}' , 'z_{exp}' , 'x_{sim}' , 'y_{sim}' , 'z_{sim}' ) ;

subplot(1,2,2)
windowSize = floor( 0.5 * par.n_datasample ) ;
tmp = windowSize ;
b_filter = (1/windowSize)*ones(1,windowSize);
a_filter = 1;
tip_sim_filter = filter( b_filter , a_filter , tip_sim ) ;
plot( par.user_pars.tip_pos(:,1) , par.user_pars.tip_pos(:,2:4) , '--' , t(tmp:end) , tip_sim_filter(tmp:end,:) , '-' , 'LineWidth' , 2 ) ;
legend( 'x_{exp}' , 'y_{exp}' , 'z_{exp}' , 'x_{sim}' , 'y_{sim}' , 'z_{sim}' ) ; title( 'Filtered')
% 
% subplot(1,2,2)
% tip_sim_smooth = smoothV( tip_sim , 0.5 * stepT ) ;
% plot( par.tip_exp(:,1) , par.tip_exp(:,2:4) , '--' , t_all , tip_sim_smooth , linetype , 'LineWidth' , 2 ) ;
% legend( 'x_{exp}' , 'y_{exp}' , 'z_{exp}' , 'x_{sim}' , 'y_{sim}' , 'z_{sim}' ) ;  title( 'Smooth')

pause( 1 )
save( 'results/results_post_proc.mat' ) ; % save workspace

