This package provides an example of Sliding Mode Control of a STIFF-FLOP module.
The STIFF-FLOP module is modelled based on Series Rigid Link (also known as Pseudo Rigid Body) kinematics as explained in this paper.:
- [S. M. H. Sadati et al., ‘TMTDyn: A Matlab package for modeling and control of hybrid rigid–continuum robots based on discretized lumped systems and reduced-order models’, The International Journal of Robotics Research, p. 0278364919881685, Jan. 2020, doi: 10.1177/0278364919881685.](https://www.researchgate.net/publication/335915427_TMTDyn_A_Matlab_Package_for_Modeling_and_Control_of_Hybrid_Rigid-Continuum_Robots_Based_on_Discretized_Lumped_System_and_Reduced-Order_Models?_sg=65yJ5EQJJgnjvr9ohuMjzS780X0XWanljwr8QWaN9auM8IJ2D-rcASJhffq-b1E0CrX7FtJ2bprcycJrhmQf5khwTs9hKQDCFU0oYW70.pYVS3qSCozpfAwCtsdbw2i-H_LzanR5IVV85KHV2xRN0TfJZIYS5s9mUhVDKTBzuDZk6j3ryf2rZeLnMW_0raw)

Installation:
- Just download the codes and run the examples
- For Matlab and external SUNDIALS solvers, you need to install SUNDIALS first. Some installation instructions are provided in tmtdyn/sundials folders. Detailed instructions are going to be available soon.

Usage:
- A list of implemented functions for the DSL (Domain Specific Language) interface is provided in the hll/Reference.m file
- See the results folder for saved videos and plots

Example file:
- festo_SRL_v0: Sliding Mode control based on a Series Rigid-Link model of a continuum manipulator with braided pneumatic chambers (STIFF-FLOP). 6-DOF joints with translational (strains) and z-x-y Euler angles rotation (curvature/torsion) are used.