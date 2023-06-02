function Qo = Q_mult( Q1 , Q2 )
% Q = [ q0 r1 r2 r3 ] ; % quaternion format
% Q1 & Q2 are cloumn vectors

n_col1 = numel( Q1(1,:) ) ;
n_col2 = numel( Q2(1,:) ) ;
if n_col1 > 1 && n_col2 > 1
    error( 'Either Q1 or Q2 can be a matrix (i.e. Jacobian or stiffness) but not both of them at the same time!' ) ;
end

if n_col1 > 1 % Q1 is a matrix
    Qo = sym( zeros( 4 , n_col1 ) ) ;
    
    for i = 1 : n_col1 % to handle rotation of jacobian and stiffness matrices with multiple columns
        Qo(:,i) = smplfy( ...
          [ Q1(1,i) -Q1(2,i) -Q1(3,i) -Q1(4,i) ;
            Q1(2,i)  Q1(1,i) -Q1(4,i)  Q1(3,i) ;
            Q1(3,i)  Q1(4,i)  Q1(1,i) -Q1(2,i) ;
            Q1(4,i) -Q1(3,i)  Q1(2,i)  Q1(1,i) ] * Q2 ) ;
    end
else % Q2 is a matrix
    Qo = smplfy( ...
          [ Q1(1,1) -Q1(2,1) -Q1(3,1) -Q1(4,1) ;
            Q1(2,1)  Q1(1,1) -Q1(4,1)  Q1(3,1) ;
            Q1(3,1)  Q1(4,1)  Q1(1,1) -Q1(2,1) ;
            Q1(4,1) -Q1(3,1)  Q1(2,1)  Q1(1,1) ] * Q2 ) ;
end

