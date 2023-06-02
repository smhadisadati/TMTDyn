function [tspan, nz, z0, par_mex] = EOM_input()
tspan = [ 0          0.01           172 ] ;
nz = 34 ;
z0 = [ 2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0 ]' ;
temp = coder.load( 'user_pars.mat' );
par_mex.user_pars = temp.user_pars ;
par_mex.var = [ 2300                   6400               50000000           210000000000      16666666.66666667            70000000000                      0                  0.008                 0.0115                  0.014                    0.1                      1                  -9.81                      0                      0                  0.175                   0.16                      0                      0                      0                      0                      0                      0                      0                      0                      0 ] ;
par_mex.t_equil_i = [ 0 ] ;