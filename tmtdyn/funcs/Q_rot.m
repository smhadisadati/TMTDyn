function r_rot = Q_rot( Q , rQ )
% rQ = [ 0 r ].' ; % 4x1

r_rot = smplfy( Q_mult( Q_mult( Q , rQ ) , Q_conj( Q ) ) ) ; % 4x1 vector

% r_rot(2:4,:) = smplfy( Q2R( Q ) * rQ(2:4,:) ) ; % 4x1 vector

