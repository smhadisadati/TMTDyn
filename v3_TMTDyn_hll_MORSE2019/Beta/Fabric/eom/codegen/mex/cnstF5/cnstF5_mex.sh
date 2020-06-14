MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for cnstF5" > cnstF5_mex.mki
echo "CC=$CC" >> cnstF5_mex.mki
echo "CFLAGS=$CFLAGS" >> cnstF5_mex.mki
echo "CLIBS=$CLIBS" >> cnstF5_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> cnstF5_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> cnstF5_mex.mki
echo "CXX=$CXX" >> cnstF5_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> cnstF5_mex.mki
echo "CXXLIBS=$CXXLIBS" >> cnstF5_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> cnstF5_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> cnstF5_mex.mki
echo "LDFLAGS=$LDFLAGS" >> cnstF5_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> cnstF5_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> cnstF5_mex.mki
echo "Arch=$Arch" >> cnstF5_mex.mki
echo "LD=$LD" >> cnstF5_mex.mki
echo OMPFLAGS= >> cnstF5_mex.mki
echo OMPLINKFLAGS= >> cnstF5_mex.mki
echo "EMC_COMPILER=gcc" >> cnstF5_mex.mki
echo "EMC_CONFIG=optim" >> cnstF5_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f cnstF5_mex.mk
