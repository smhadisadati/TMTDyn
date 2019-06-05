MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for rksF" > rksF_mex.mki
echo "CC=$CC" >> rksF_mex.mki
echo "CFLAGS=$CFLAGS" >> rksF_mex.mki
echo "CLIBS=$CLIBS" >> rksF_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> rksF_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> rksF_mex.mki
echo "CXX=$CXX" >> rksF_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> rksF_mex.mki
echo "CXXLIBS=$CXXLIBS" >> rksF_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> rksF_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> rksF_mex.mki
echo "LDFLAGS=$LDFLAGS" >> rksF_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> rksF_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> rksF_mex.mki
echo "Arch=$Arch" >> rksF_mex.mki
echo "LD=$LD" >> rksF_mex.mki
echo OMPFLAGS= >> rksF_mex.mki
echo OMPLINKFLAGS= >> rksF_mex.mki
echo "EMC_COMPILER=gcc" >> rksF_mex.mki
echo "EMC_CONFIG=optim" >> rksF_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f rksF_mex.mk
