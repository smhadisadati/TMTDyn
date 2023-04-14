The dynamic motion of a fabric sleeve worn on a rigid-link pendulum is modeled using the "TMTDyn" package. The system is described in "Fabric_v0_3.m" file. You may change the following parameter to run the different experimental cases.

% study specific parameters
par.exp_case = 2 ; % [ exp_case start_exp_sequence end_exp_sequence ]

The following parameters control different type of available analysis, plotting, and postprocessing.

% derivation
par.derive = 0 ; % set 1 to rederive in TMT
par.derive_collect = 0 ; % collect in 1: single struct., 2: seperte struct.s, 3: seperate func.s, 4: C func.s
par.derive_mex = 1 ; % use Matlab codegen, automatically sets par.derive_collect = 1
par.opv = true ; % optimize results

The system derivations are sometimes time-consuming. The derivations for the system is already provided in the "code" file, so you may set par.derive=0 and run the "Manip_v6_2.m" file in Matlab to see the results.

Please see the package Wiki page at https://github.com/hadisdt/TMTDyn/wiki/Example-2--Fabric-dynamics-worn-by-a-rigid-link-pendulum for more information. See some examples here: https://github.com/hadisdt/TMTDyn/tree/master/Samples
