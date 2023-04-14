@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2017b
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2017b\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=rjtipF_mex
set MEX_NAME=rjtipF_mex
set MEX_EXT=.mexw64
call setEnv.bat
echo # Make settings for rjtipF > rjtipF_mex.mki
echo CC=%COMPILER%>> rjtipF_mex.mki
echo CXX=%CXXCOMPILER%>> rjtipF_mex.mki
echo CFLAGS=%COMPFLAGS%>> rjtipF_mex.mki
echo CXXFLAGS=%CXXCOMPFLAGS%>> rjtipF_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> rjtipF_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> rjtipF_mex.mki
echo LINKER=%LINKER%>> rjtipF_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> rjtipF_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> rjtipF_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> rjtipF_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> rjtipF_mex.mki
echo OMPFLAGS= >> rjtipF_mex.mki
echo OMPLINKFLAGS= >> rjtipF_mex.mki
echo EMC_COMPILER=mingw64>> rjtipF_mex.mki
echo EMC_CONFIG=optim>> rjtipF_mex.mki
"C:\Program Files\MATLAB\R2017b\bin\win64\gmake" -B -f rjtipF_mex.mk
