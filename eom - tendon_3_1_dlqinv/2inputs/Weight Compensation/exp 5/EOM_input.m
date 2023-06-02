function [tspan, nz, z0, par_mex] = EOM_input()
tspan = [ 0            0.1      1499.9614 ] ;
nz = 38 ;
z0 = [ 0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0 ]' ;
temp = coder.load( 'user_pars.mat' );
par_mex.user_pars = temp.user_pars ;
par_mex.var = [ 6400                   6400           210000000000           210000000000            70000000000            70000000000                      0                  0.008                 0.0115                  0.014                  0.005                      1                      0                      0                   9.81                   0.16                   0.16                      0                  0.045                      0                      0                      0                      0                      0                      0                      0                      0                      0                      0                   0.16                2000000                      0                      0 ] ;
par_mex.t_equil_i = [ 0 ] ;