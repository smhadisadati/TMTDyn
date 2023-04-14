MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for cnstF1" > cnstF1_mex.mki
echo "CC=$CC" >> cnstF1_mex.mki
echo "CFLAGS=$CFLAGS" >> cnstF1_mex.mki
echo "CLIBS=$CLIBS" >> cnstF1_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> cnstF1_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> cnstF1_mex.mki
echo "CXX=$CXX" >> cnstF1_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> cnstF1_mex.mki
echo "CXXLIBS=$CXXLIBS" >> cnstF1_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> cnstF1_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> cnstF1_mex.mki
echo "LDFLAGS=$LDFLAGS" >> cnstF1_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> cnstF1_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> cnstF1_mex.mki
echo "Arch=$Arch" >> cnstF1_mex.mki
echo "LD=$LD" >> cnstF1_mex.mki
echo OMPFLAGS= >> cnstF1_mex.mki
echo OMPLINKFLAGS= >> cnstF1_mex.mki
echo "EMC_COMPILER=gcc" >> cnstF1_mex.mki
echo "EMC_CONFIG=optim" >> cnstF1_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f cnstF1_mex.mk
