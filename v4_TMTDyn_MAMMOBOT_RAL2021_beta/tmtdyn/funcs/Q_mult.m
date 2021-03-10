function Qo = Q_mult( Q1 , Q2 )
% Q = [ q0 r1 r2 r3 ] ; % quaternion format
% Q1 & Q2 are cloumn vectors
Qo = smplfy( ...
    [ Q1(1,1) -Q1(2,1) -Q1(3,1) -Q1(4,1) ;
      Q1(2,1)  Q1(1,1) -Q1(4,1)  Q1(3,1) ;
      Q1(3,1)  Q1(4,1)  Q1(1,1) -Q1(2,1) ;
      Q1(4,1) -Q1(3,1)  Q1(2,1)  Q1(1,1) ] * Q2 ) ;

