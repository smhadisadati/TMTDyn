function par = post_proc( t , t_equil , z , z_equil , rjtip , rjtip_equil , ...
	Phi_modal , M_modal , K_modal , V_modal , omega , xi , ...
	par )
fprintf( 'post-processing... \n' )
par.elapsed_time = [ par.elapsed_time toc( par.timer ) ] ;
toc( par.timer )

for i = 1 : numel( t )
    tip_sim(i,:) = rjtip(1,4:6,i) ;  
end


figcompare = figure ;
plot( t , tip_sim , par.linetype , 'LineWidth' , 2 ) ;
legend( 'x_{sim}' , 'y_{sim}' , 'z_{sim}' ) ; title( 'Sim.')

pause( 1 )
save( './results/results_post_proc.mat' ) ; % save workspace

