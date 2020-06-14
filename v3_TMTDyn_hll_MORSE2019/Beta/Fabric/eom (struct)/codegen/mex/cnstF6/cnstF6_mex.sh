MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for cnstF6" > cnstF6_mex.mki
echo "CC=$CC" >> cnstF6_mex.mki
echo "CFLAGS=$CFLAGS" >> cnstF6_mex.mki
echo "CLIBS=$CLIBS" >> cnstF6_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> cnstF6_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> cnstF6_mex.mki
echo "CXX=$CXX" >> cnstF6_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> cnstF6_mex.mki
echo "CXXLIBS=$CXXLIBS" >> cnstF6_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> cnstF6_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> cnstF6_mex.mki
echo "LDFLAGS=$LDFLAGS" >> cnstF6_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> cnstF6_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> cnstF6_mex.mki
echo "Arch=$Arch" >> cnstF6_mex.mki
echo "LD=$LD" >> cnstF6_mex.mki
echo OMPFLAGS= >> cnstF6_mex.mki
echo OMPLINKFLAGS= >> cnstF6_mex.mki
echo "EMC_COMPILER=gcc" >> cnstF6_mex.mki
echo "EMC_CONFIG=optim" >> cnstF6_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f cnstF6_mex.mk
