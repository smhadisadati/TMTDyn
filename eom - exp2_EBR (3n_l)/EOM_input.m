function [tspan, nz, z0, par_mex] = EOM_input()
tspan = [ 7         0.01        54.65 ] ;
nz = 36 ;
z0 = [ 2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06       2e-06           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0 ]' ;
temp = coder.load( 'user_pars.mat' );
par_mex.user_pars = temp.user_pars ;
par_mex.var = [ 1820           120000           0.0045           0.0125            0.044              0.1              0.1              0.1            0.001            0.001            0.001                1                0                0             9.81          0.01347           0.0145           0.0075           0.0025           0.0085      1.504117308                0                0                0                0                0                0                0                0                0                0                0                0                1 ] ;
par_mex.t_equil_i = [ 7 ] ;