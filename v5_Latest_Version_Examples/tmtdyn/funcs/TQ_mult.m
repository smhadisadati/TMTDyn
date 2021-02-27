function TQo = TQ_mult( TQ1 , TQ2 )
TQo = smplfy( [ Q_mult( TQ1(:,1) , TQ2(:,1) ) , ...
        TQ1(:,2)+Q_rot( TQ1(:,1) , TQ2(:,2) ) ] ) ;

   