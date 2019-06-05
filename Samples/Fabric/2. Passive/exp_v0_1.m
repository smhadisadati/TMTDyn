function par = exp_v0_1( par )
fprintf( 'exp. data... \n' )
par.elapsed_time = [ par.elapsed_time toc( par.timer ) ] ;
toc( par.timer )

par.sample_t =  1 / 40 ; % 40Hz ;

smooth_step = 10 ;
% extract
switch par.exp_case % exp. cases
    case 1 % fab78
        load ('exp/fab78.mat' ) ;
        par.t_exp = ( 1 : numel( fab78{:,1} ) ) * par.sample_t ;
        par.r_arm =  smoothV( fab78{:,1:3} , smooth_step ) * 1e-3 ;
        par.r_fab =  smoothV( fab78{:,10:12} , smooth_step ) * 1e-3 ;
        
    case 2 % fab1112
        load ('exp/fab1112.mat' ) ;
        par.t_exp = ( 1 : numel( fab1112{:,1} ) ) * par.sample_t ;
        par.r_arm =  smoothV( fab1112{:,1:3} , smooth_step ) * 1e-3 ;
        par.r_fab =  smoothV( fab1112{:,7:9} , smooth_step ) * 1e-3 ;
        
end

% conditioning
par.r_arm = par.r_arm - par.r_arm(1,:) + 0 * [ 0 0 -par.var2(4) ] ;
par.r_fab = par.r_fab - par.r_fab(1,:) ; % adjustonce more before comparison

par.r_arm = [ -par.r_arm(:,2) par.r_arm(:,3) par.r_arm(:,1) ] ;
par.r_fab = [ -par.r_fab(:,2) par.r_fab(:,3) par.r_fab(:,1) ] ;

% constraint
temp = diff( par.r_arm ) / par.sample_t ;
temp = diff( [ temp ; temp(end,:) ] ) / par.sample_t ; % central difference
ddr_arm = [ temp ; temp(end,:) ] ;
ddr_arm_x = - 0 * ddr_arm(:,1) ; % 1: x, 3: z direction

% plot
figure ;
subplot(2,2,1) ; plot( par.t_exp ,par.r_arm ) ; title( 'arm' ) ;
subplot(2,2,2) ; plot( par.t_exp ,par.r_fab ) ; title( 'fab' ) ;
subplot(2,2,3) ; plot( par.t_exp ,ddr_arm ) ; title( 'arm acc.' ) ;
subplot(2,2,4) ; plot( par.t_exp ,ddr_arm_x ) ; title( 'projected arm acc.' ) ;

