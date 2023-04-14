function par = post_proc( t , z , rjtip , par )
fprintf( 'post-processing... \n' )
par.elapsed_time = [ par.elapsed_time toc( par.timer ) ] ;
toc( par.timer )

plot( t , z , 'LineWidth' , 2 ) ;

