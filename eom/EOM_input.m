function [tspan, nz, z0, par_mex] = EOM_input()
tspan = [ 0         0.01        52.62 ] ;
nz = 48 ;
z0 = [ 2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0 ]' ;
temp = coder.load( 'user_pars.mat' );
par_mex.user_pars = temp.user_pars ;
par_mex.var = [ 6450           80000000000           90000000000           60000000000           72000000000           81000000000           20000000000              0.000685               0.00089               0.00035               0.00055                     0                     0           80000000000           80000000000           90000000000           90000000000           90000000000           80000000000            4000000000            4000000000            4500000000            4500000000            4500000000            4000000000           60000000000           60000000000           60000000000           60000000000           60000000000           60000000000                     1                 -9.81                     0                     0                 0.194                 0.168                     0                 0.081                 0.143                     0                     1                     1                     0                   200                     0                 0.001                     0                     0                     0                     0                     0                     0                     0                     0                     0                     0                     0                     0                     0 ] ;
par_mex.t_equil_i = [ 0 ] ;