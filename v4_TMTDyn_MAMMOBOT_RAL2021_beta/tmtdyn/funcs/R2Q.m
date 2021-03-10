function Q = R2Q( R )
Q = smplfy( ...
    [ sqrt( 1 + R(1,1) + R(2,2) + R(3,3) )/2 ;
      sign( R(3,2) - R(2,3) )*abs( sqrt( 1 + R(1,1) - R(2,2) - R(3,3) ) / 2 ) ;
      sign( R(1,3) - R(3,1) )*abs( sqrt( 1 - R(1,1) + R(2,2) - R(3,3) ) / 2 ) ;
      sign( R(2,1) - R(1,2) )*abs( sqrt( 1 - R(1,1) - R(2,2) + R(3,3) ) / 2 ) ] ) ;
