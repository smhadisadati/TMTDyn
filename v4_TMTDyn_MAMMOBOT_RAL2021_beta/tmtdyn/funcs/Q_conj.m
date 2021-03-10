 function Qo = Q_conj( Q )
% global unit_quat
% if ~unit_quat
% 	Qo = smplfy( Qo / sqrt( Q.' * Q ) ) ;
% end

Qo = smplfy( [ Q(1,1) ; -Q(2:4,1) ] ) ;

