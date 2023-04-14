MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for cnstF4" > cnstF4_mex.mki
echo "CC=$CC" >> cnstF4_mex.mki
echo "CFLAGS=$CFLAGS" >> cnstF4_mex.mki
echo "CLIBS=$CLIBS" >> cnstF4_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> cnstF4_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> cnstF4_mex.mki
echo "CXX=$CXX" >> cnstF4_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> cnstF4_mex.mki
echo "CXXLIBS=$CXXLIBS" >> cnstF4_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> cnstF4_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> cnstF4_mex.mki
echo "LDFLAGS=$LDFLAGS" >> cnstF4_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> cnstF4_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> cnstF4_mex.mki
echo "Arch=$Arch" >> cnstF4_mex.mki
echo "LD=$LD" >> cnstF4_mex.mki
echo OMPFLAGS= >> cnstF4_mex.mki
echo OMPLINKFLAGS= >> cnstF4_mex.mki
echo "EMC_COMPILER=gcc" >> cnstF4_mex.mki
echo "EMC_CONFIG=optim" >> cnstF4_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f cnstF4_mex.mk
