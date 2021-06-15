To begin, download the directory Zip-file...

This is the latest current version of the package with examples based on the following paper:
- [S. M. H. Sadati et al., ‘TMTDyn: A Matlab package for modeling and control of hybrid rigid–continuum robots based on discretized lumped systems and reduced-order models’, The International Journal of Robotics Research, p. 0278364919881685, Jan. 2020, doi: 10.1177/0278364919881685.](https://www.researchgate.net/publication/335915427_TMTDyn_A_Matlab_Package_for_Modeling_and_Control_of_Hybrid_Rigid-Continuum_Robots_Based_on_Discretized_Lumped_System_and_Reduced-Order_Models?_sg=65yJ5EQJJgnjvr9ohuMjzS780X0XWanljwr8QWaN9auM8IJ2D-rcASJhffq-b1E0CrX7FtJ2bprcycJrhmQf5khwTs9hKQDCFU0oYW70.pYVS3qSCozpfAwCtsdbw2i-H_LzanR5IVV85KHV2xRN0TfJZIYS5s9mUhVDKTBzuDZk6j3ryf2rZeLnMW_0raw)

Installation:
- Just download the codes and run the examples
- For Matlab and external SUNDIALS solvers, you need to install SUNDIALS first. Some installation instructions are provided in tmtdyn/sundials folders. Detailed instructions are going to be available soon.

Usage:
- A list of implemented functions for the DSL (Domain Specific Language) interface is provided in the hll/Reference.m file
- See the results folder for saved videos and plots

Examples:
- Exp1_SRL: Series Rigid-Link model of a continuum manipulator with braided pneumatic chambers (STIFF-FLOP). 6-DOF joints with translational (strains) and z-x-y Euler angles rotation (curvature/torsion) are used.
- Exp2_EBR: Euler Bernoulli beams with relative states (Piecewise Constant Strain model). Relative translations (strains) are similar to SRL for strains but the relative rotations (curvature/torsion) are based on discretized Variable Curvature kinematics.
- Exp2_EBR: Euler Bernoulli beams with absolute states (similar to Finite Element Analysis). Relative translations (strains) and rotations (curvature/torsion) are based on the inverse of the aforementioned discretized Variable Curvature kinematics.
- Exp3_ROM: General Reduced-Order Model (ROM) with Polynomial Shape (PS) parametrization. 6 polynomials are considered to model the strains and curvature/torsion. The polynomial coefficients are time-variant and considered as the dynamic system states.
- Exp3_ROM_Bishop: Reduced-Order Model (ROM) with Polynomial Shape (PS) parametrization and Bishop's curvilinear frame. 4 polynomials are considered to model the strains and correction twist angle. The curvilinear frame is derived from the curve Cartesian position. The correction twist angle transforms the curvilinear frame to the physical local frame. The polynomial coefficients are time-variant and considered as the dynamic system states.

