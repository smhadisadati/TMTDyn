@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2017b
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2017b\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=rksF_mex
set MEX_NAME=rksF_mex
set MEX_EXT=.mexw64
call setEnv.bat
echo # Make settings for rksF > rksF_mex.mki
echo CC=%COMPILER%>> rksF_mex.mki
echo CXX=%CXXCOMPILER%>> rksF_mex.mki
echo CFLAGS=%COMPFLAGS%>> rksF_mex.mki
echo CXXFLAGS=%CXXCOMPFLAGS%>> rksF_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> rksF_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> rksF_mex.mki
echo LINKER=%LINKER%>> rksF_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> rksF_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> rksF_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> rksF_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> rksF_mex.mki
echo OMPFLAGS= >> rksF_mex.mki
echo OMPLINKFLAGS= >> rksF_mex.mki
echo EMC_COMPILER=mingw64>> rksF_mex.mki
echo EMC_CONFIG=optim>> rksF_mex.mki
"C:\Program Files\MATLAB\R2017b\bin\win64\gmake" -B -f rksF_mex.mk
