function [ p , tip_pos , tip_RQ , f_ex , t_exp , t_exp_equil ] = sample_exp_data( var_vals , exp_case )
fprintf( 'exp. data... \n' )

l_s = var_vals(5) ;
l_f = var_vals(17) ;

% extract
switch exp_case(1) % exp. cases
    case 1 % simple actuation
        % time	Pres0	Pres1	Pres2	X_val	Y_val	Z_val	Q0_val 	Qx_val	Qy_val	Qz_val	X1_val	Y1_val	Z1_val	Q01_val Qx1_val	Qy1_val	Qz1_val
        load ('exp/NoLoad.mat' ) ;
        p = NoLoad(1:end,1) ; p(:,2:4) = 1e5 * smoothV( NoLoad(1:end,2:4) - NoLoad(1,2:4) ) ;
        f_ex = NoLoad(1:end,1) ; f_ex(:,2:7) = 0 ;
        tip_pos = NoLoad(1:end,1) ; tip_pos(:,2:4) = 1e-3 * smoothV( NoLoad(1:end,12:14) - NoLoad(1:end,5:7) ) ;
        tip_RQ = NoLoad(1:end,1) ; tip_RQ(:,2:5) = smoothV( NoLoad(1:end,15:18) ) ;
        t_exp = [ 7 13.45 20 24.5 29.4 33.4 37.5 42.9 49.2 ] ; % exp steps
        t_exp_equil = t_exp + 1.7 ; % exp steps
        
    case 2 % actuation and ext. force 1
        % Fx	Fy	Fz	Mx	My	Mz	time	Pres0	Pres1	Pres2	X_val	Y_val	Z_val	Q0_val 	Qx_val	Qy_val	Qz_val	X1_val	Y1_val	Z1_val	Q01_val 	Qx1_val	Qy1_val	Qz1_val	Fx	Fy	Fz	Mx	My	Mz
        load ('exp/Load1.mat' ) ;
        p = Load1(:,7) ; p(:,2:4) = 1e5 * smoothV( Load1(:,8:10) - Load1(1,8:10) ) ;
        f_ex = Load1(:,7) ; f_ex(:,2:4) = smoothV( Load1(:,25:27) - Load1(1,25:27) ) ; f_ex(:,5:7) = smoothV( Load1(:,28:30) - Load1(1,28:30) ) ;
        tip_pos = Load1(:,7) ; tip_pos(:,2:4) = 1e-3 * smoothV( Load1(:,18:20) - Load1(:,11:13) ) ;
        tip_RQ = Load1(:,7) ; tip_RQ(:,2:5) = smoothV( Load1(:,21:24) ) ;
        t_exp = [ 5 8.8 13.2 15 17.5 33 ] ;
        t_exp_equil = [ 8.9 15.7 18.1 26.7 30 33 36.3 42.4 44.8 52.4 ] ;
        
    case 3 % actuation and ext. force 2
        % time	Pres0	Pres1	Pres2	X_val	Y_val	Z_val	Q0_val 	Qx_val	Qy_val	Qz_val	X1_val	Y1_val	Z1_val	Q01_val Qx1_val	Qy1_val	Qz1_val	Fx	Fy	Fz	Mx	My	Mz
        load ('exp/Load2.mat' ) ;
        p = Load2(:,7) ; p(:,2:4) = 1e5 * smoothV( Load2(:,8:10) - Load2(1,8:10) ) ;
        f_ex = Load2(:,7) ; f_ex(:,2:4) = smoothV( Load2(:,25:27) - Load2(1,25:27) ) ; f_ex(:,5:7) = smoothV( Load2(:,28:30) - Load2(1,28:30) ) ;
        tip_pos = Load2(:,7) ; tip_pos(:,2:4) = 1e-3 * smoothV( Load2(:,18:20) - Load2(:,11:13) ) ;
        tip_RQ = Load2(:,7) ; tip_RQ(:,2:5) = smoothV( Load2(:,21:24) ) ;
        t_exp = [ 5 7.8 9.7 ] ;
        t_exp_equil = [ 7.6 9.7 17.3 19.6 30 32.9 ] ;
end
p(:,2:4) = 5 / 4 * ( p(:,2:4) - 0 * p(1,2:4) ) ;

% conditioning
% r_fo = [ 15-0.486 -0.657 157.20-12 ] * 1e-3 ;
r_fo = 1*[ 15-0.486 0 0 ] * 1e-3 ; % sensor offset
phi_b = 0 * pi / 180 ; Q_b = [ cos( phi_b / 2 ) sin( phi_b / 2 )*[ 0 0 1 ] ] ; % base polar offset
tip_RQ0 = Q_conj( tip_RQ(1,2:end) ) ;
tip_pos0 = tip_pos(1,2:4) ;
for i = 1 : numel( tip_RQ(:,1) )
    tip_RQ(i,2:end) = Q_mult( tip_RQ0 , tip_RQ(i,2:end) ) ;
    tip_pos(i,2:4) = tip_pos(i,2:4) - Q_rot( tip_RQ(i,2:end) , r_fo ) ; % tip sensor offset
    tip_pos(i,2:4) = tip_pos(i,2:4) - tip_pos0 + r_fo + [ 0 0 l_s+l_f ]; % init. lenght
    tip_pos(i,2:4) = Q_rot( Q_b , tip_pos(i,2:4) ) ;
    f_ex(i,2:4) = Q_rot( tip_RQ(i,2:end) , f_ex(i,2:4) ) * diag( 1 * ones(1,3) ) ;
    f_ex(i,5:7) = Q_rot( tip_RQ(i,2:end) , f_ex(i,5:7) )  * diag( 1e-3 * ones(1,3) ) ;
end

% plot
figure ;
subplot(2,2,1) ; plot( p(:,1) , p(:,2:4) ) ; title( 'p' ) ;
subplot(2,2,2) ; plot( tip_pos(1:end,1) , tip_pos(1:end,2:4) ) ; title( '\rho_{tip}' ) ;
subplot(2,2,3) ; plot( f_ex(:,1) , f_ex(:,2:4) ) ; title( 'f_{tip}' ) ;
subplot(2,2,4) ; plot( f_ex(:,1) , f_ex(:,5:7) ) ; title( '\tau_{tip}' ) ;

% test
% figure ; plot( tip_RQ(:,1) , tip_RQ(:,2:end) ) ;


function Qo = Q_mult( Q1 , Q2 )
% Q = [ q0 r1 r2 r3 ] ; % quaternion format
% Q1 & Q2 are cloumn vectors
Qo = [ Q1(1) -Q1(2) -Q1(3) -Q1(4) ;
       Q1(2)  Q1(1) -Q1(4)  Q1(3) ;
       Q1(3)  Q1(4)  Q1(1) -Q1(2) ;
       Q1(4) -Q1(3)  Q1(2)  Q1(1) ] * Q2' ;
Qo = Qo' ;
   
   
function r_rot = Q_rot( Q , rQ )
% rQ = [ 0 r ].' ;
r_rot = Q_mult( Q_mult( Q , [ 0 rQ ] ) , Q_conj( Q ) ) ; % 4x1 vector
r_rot = r_rot(2:end) ;
   

function Qo = Q_conj( Q )
Qo = [ Q(1) -Q(2:4) ] ;


function y = smoothV( x , step )

% y = x ; return

if nargin < 2
    step = 10 ;
end

[ ~ , n ] = size( x ) ;
for i = 1 : n
    y(:,i) = smooth( x(:,i) , step , 'moving' ) ;
end

