function par = post_proc( t , z , rjtip , par )
fprintf( 'post-processing... \n' )
par.elapsed_time = [ par.elapsed_time toc( par.timer ) ] ;
toc( par.timer )

switch par.exp_case % exp. cases
    case 1 % fab78
        jj = 12 ; % body number from mesh import
        l_ref = 16.2e-2 ;
    case 2 % fab1112
        jj = 13 ;
        l_ref = 25.1e-2 ;
end

Err_vec = zeros( 1 , 3 ) ; 
par.r_fab = par.r_fab + rjtip(jj,4:6,1) ; % removing offset dueto meaurments
for i = 1 : numel( t )
    tip_sim(i,:) = rjtip(jj,4:6,i) ;
    % error analysis
    step = floor( t(i) / par.sample_t ) ;
    Err_vec(i,:) = par.r_fab(step,:) - tip_sim(i,:) ;
    Err_abs_all(i) = sqrt( Err_vec(i,:) * Err_vec(i,:)' ) ;    
end

% matching sim-exp
correction = max( abs( par.r_fab(:,1) - tip_sim(1,1) ) ) / max( abs( tip_sim(:,1) - tip_sim(1,1) ) )
tip_sim(:,[1,3]) = correction * ( tip_sim(:,[1,3]) - tip_sim(1,[1,3]) ) + tip_sim(1,[1,3]) ;
l_ref = correction * l_ref ;

Err_abs = mean( Err_abs_all )
Err_std = std( Err_abs_all )
Err_norm = Err_abs / l_ref * 100


figcompare = figure ;
subplot(1,2,1)
plot( par.t_exp , par.r_fab , '--' , t , tip_sim , par.linetype , 'LineWidth' , 2 ) ;
legend( 'x_{exp}' , 'y_{exp}' , 'z_{exp}' , 'x_{sim}' , 'y_{sim}' , 'z_{sim}' ) ; title( 'Sim.')

subplot(1,2,2)
plot( par.t_exp , par.r_fab , '--' , t , smoothV( tip_sim , 10 ) , par.linetype , 'LineWidth' , 2 ) ;
legend( 'x_{exp}' , 'y_{exp}' , 'z_{exp}' , 'x_{sim}' , 'y_{sim}' , 'z_{sim}' ) ; title( 'Sim.')

pause( 1 )
save( 'code/results/results_post_proc.mat' ) ; % save workspace

