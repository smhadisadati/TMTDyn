function r_rot = Q_rot( Q , rQ )
% rQ = [ 0 r ].' ;
r_rot = smplfy( Q_mult( Q_mult( Q , rQ ) , Q_conj( Q ) ) ) ; % 4x1 vector

