MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for rjtipF" > rjtipF_mex.mki
echo "CC=$CC" >> rjtipF_mex.mki
echo "CFLAGS=$CFLAGS" >> rjtipF_mex.mki
echo "CLIBS=$CLIBS" >> rjtipF_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> rjtipF_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> rjtipF_mex.mki
echo "CXX=$CXX" >> rjtipF_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> rjtipF_mex.mki
echo "CXXLIBS=$CXXLIBS" >> rjtipF_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> rjtipF_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> rjtipF_mex.mki
echo "LDFLAGS=$LDFLAGS" >> rjtipF_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> rjtipF_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> rjtipF_mex.mki
echo "Arch=$Arch" >> rjtipF_mex.mki
echo "LD=$LD" >> rjtipF_mex.mki
echo OMPFLAGS= >> rjtipF_mex.mki
echo OMPLINKFLAGS= >> rjtipF_mex.mki
echo "EMC_COMPILER=gcc" >> rjtipF_mex.mki
echo "EMC_CONFIG=optim" >> rjtipF_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f rjtipF_mex.mk
