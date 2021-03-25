- Generated C files for EOM.m and EOM_Input.m in eom folder with Matlab coder.
- Copy the EOM folder from "~\eom\codegen\lib\EOM" to "~\tmtdyn\sundials_c\EOM (...)" folder

- Edit "Demo.c" (edited from sundials cvode "cvRoberts_dns.c" example) and "Demo.h" (edited from Matlab coder "main.h" example) according to your problem, i.e. set the number of system states (including the Lagrange multipliers and other unknowns) here:
#define STATES_NO RCONST(...)

- Copy "Demo.c" and "Demo.h" in EOM folder 
- run Ubuntu app
- cd to the EOM folder
cd "/mnt/c/Users/customer/MEGAsync/Hadi/Postdoc/2. KCL/2. Research/1. Model/TMTDyn_win/eom/EOM_c/Basics"

- compile all .c codes
g++ *.c -O3 -mtune=native -DNDEBUG -o Demo -I"/mnt/c/Program Files/MATLAB/R2019a/extern/include" -I/mnt/c/sundials-5.0.0-dev.1/instdir/include -L/mnt/c/sundials-5.0.0-dev.1/instdir/lib -lsundials_cvode -lsundials_nvecserial -lsundials_nvecmanyvector -lm /usr/lib/x86_64-linux-gnu/librt.so -Wl,-rpath,/mnt/c/sundials-5.0.0-dev.1/instdir/lib


- run generated file
./Demo

- the results are saved in result.txt file. copy it back to eom folder and contiue/repeat with matlab run