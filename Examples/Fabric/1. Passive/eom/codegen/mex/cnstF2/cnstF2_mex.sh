MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for cnstF2" > cnstF2_mex.mki
echo "CC=$CC" >> cnstF2_mex.mki
echo "CFLAGS=$CFLAGS" >> cnstF2_mex.mki
echo "CLIBS=$CLIBS" >> cnstF2_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> cnstF2_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> cnstF2_mex.mki
echo "CXX=$CXX" >> cnstF2_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> cnstF2_mex.mki
echo "CXXLIBS=$CXXLIBS" >> cnstF2_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> cnstF2_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> cnstF2_mex.mki
echo "LDFLAGS=$LDFLAGS" >> cnstF2_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> cnstF2_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> cnstF2_mex.mki
echo "Arch=$Arch" >> cnstF2_mex.mki
echo "LD=$LD" >> cnstF2_mex.mki
echo OMPFLAGS= >> cnstF2_mex.mki
echo OMPLINKFLAGS= >> cnstF2_mex.mki
echo "EMC_COMPILER=gcc" >> cnstF2_mex.mki
echo "EMC_CONFIG=optim" >> cnstF2_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f cnstF2_mex.mk
