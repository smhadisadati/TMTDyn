MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for cnstF3" > cnstF3_mex.mki
echo "CC=$CC" >> cnstF3_mex.mki
echo "CFLAGS=$CFLAGS" >> cnstF3_mex.mki
echo "CLIBS=$CLIBS" >> cnstF3_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> cnstF3_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> cnstF3_mex.mki
echo "CXX=$CXX" >> cnstF3_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> cnstF3_mex.mki
echo "CXXLIBS=$CXXLIBS" >> cnstF3_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> cnstF3_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> cnstF3_mex.mki
echo "LDFLAGS=$LDFLAGS" >> cnstF3_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> cnstF3_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> cnstF3_mex.mki
echo "Arch=$Arch" >> cnstF3_mex.mki
echo "LD=$LD" >> cnstF3_mex.mki
echo OMPFLAGS= >> cnstF3_mex.mki
echo OMPLINKFLAGS= >> cnstF3_mex.mki
echo "EMC_COMPILER=gcc" >> cnstF3_mex.mki
echo "EMC_CONFIG=optim" >> cnstF3_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f cnstF3_mex.mk
