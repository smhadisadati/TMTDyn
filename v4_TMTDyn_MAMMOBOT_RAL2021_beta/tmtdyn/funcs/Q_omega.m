function omega = Q_omega( Q , dQ )
% same as 2*Q_conj*dQ but less computation
omega(2:4,:) = smplfy( 2 * ...
    [ -Q(2,1)  Q(1,1)  Q(4,1) -Q(3,1) ;
      -Q(3,1) -Q(4,1)  Q(1,1)  Q(2,1) ;
      -Q(4,1)  Q(3,1) -Q(2,1)  Q(1,1) ] * dQ ) ;
