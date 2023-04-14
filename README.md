This code package derives and runs the dynamic model for MAMMOBOT: A Miniature Steerable Soft Growing Robot for Early Breast Cancer Detection.
MAMMOBOT is a novel miniature #eversion #growing cannula steered with a notched tendon-driven #catheter 

New TMTDyn features:
- Growing robot dynamic modeling
- Handling concentricity constraint
- Simple model of a tendon-driven catheter
- Supporting C-file generation for real-time simulation with a C-wrapper for [SUNDIALS CVODES solver](https://computing.llnl.gov/projects/sundials/cvodes): "Demo.c" file in the "eom/EOM_c" folder.

How to run:
- Run grow_2_2_E.m in Matlab (only for Matlab version 2018a and older!)
- Video results will be saved in the "results" folder

Notes:
- Parameters are prefixed (cannot be changed) at the moment!
- A new user-guide or Wiki page is under development for this new version. Meanwhile, please get in touch if you need to run the code with different parameters!
- Please read and cite the following article as a guide to the implemnetation:
[Pierre Berthet-Rayne, S.M.Hadi Sadati, Georgios Petrou, Neel Patel, Stamatia Giannarou, Daniel Richard Leff, Christos Bergeles, “MAMMOBOT: A Miniature Steerable Soft Growing Robot for Early Breast Cancer Detection,” IEEE Robotics and Automation Letters (RA-L), 2021.](https://www.researchgate.net/publication/349349993_MAMMOBOT_A_Miniature_Steerable_Soft_Growing_Robot_for_Early_Breast_Cancer_Detection)

Please cite our relevant papers if you decided to use this package or the methods presented in it:
- [S. M. H. Sadati et al., ‘TMTDyn: A Matlab package for modeling and control of hybrid rigid–continuum robots based on discretized lumped systems and reduced-order models’, The International Journal of Robotics Research, p. 0278364919881685, Jan. 2020, doi: 10.1177/0278364919881685.](https://www.researchgate.net/publication/335915427_TMTDyn_A_Matlab_Package_for_Modeling_and_Control_of_Hybrid_Rigid-Continuum_Robots_Based_on_Discretized_Lumped_System_and_Reduced-Order_Models?_sg=65yJ5EQJJgnjvr9ohuMjzS780X0XWanljwr8QWaN9auM8IJ2D-rcASJhffq-b1E0CrX7FtJ2bprcycJrhmQf5khwTs9hKQDCFU0oYW70.pYVS3qSCozpfAwCtsdbw2i-H_LzanR5IVV85KHV2xRN0TfJZIYS5s9mUhVDKTBzuDZk6j3ryf2rZeLnMW_0raw)
- [S.M.H. Sadat, A. Shiva, S. E. Naghibi, et al., “Reduced Order vs. Discretized Lumped System Models with Absolute and Relative States for Continuum Manipulators,” presented at the Robotics: Science and Systems (RSS), Freiburg, Germany, 2019.](https://www.researchgate.net/publication/332980482_Reduced_Order_vs_Discretized_Lumped_System_Models_with_Absolute_and_Relative_States_for_Continuum_Manipulators)
- [S. M. H. Sadati, S. Zschaler, and C. Bergeles, ‘A Matlab-Internal DSL for Modelling Hybrid Rigid–Continuum Robots with TMTDyn’, in 6th Workshop on Model-Driven Robot Software Engineering (MORSE), Munich, Germany, 2019, p. 9.
](https://www.researchgate.net/publication/334898974_A_Matlab-Internal_DSL_for_Modelling_Hybrid_Rigid-Continuum_Robots_with_TMTDyn?_sg=65yJ5EQJJgnjvr9ohuMjzS780X0XWanljwr8QWaN9auM8IJ2D-rcASJhffq-b1E0CrX7FtJ2bprcycJrhmQf5khwTs9hKQDCFU0oYW70.pYVS3qSCozpfAwCtsdbw2i-H_LzanR5IVV85KHV2xRN0TfJZIYS5s9mUhVDKTBzuDZk6j3ryf2rZeLnMW_0raw)
- [S.M.H. Sadati, S. Naghibi, and M. Naraghi, “An Automatic Algorithm to Derive Linear Vector Form of Lagrangian Equation of Motion with Collision and Constraint,” Procedia Computer Science, vol. 76, pp. 217–222, 2015.](https://www.researchgate.net/publication/290003554_An_Automatic_Algorithm_to_Derive_Linear_Vector_Form_of_Lagrangian_Equation_of_Motion_with_Collision_and_Constraint)
