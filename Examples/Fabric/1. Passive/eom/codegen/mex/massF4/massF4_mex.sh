MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for massF4" > massF4_mex.mki
echo "CC=$CC" >> massF4_mex.mki
echo "CFLAGS=$CFLAGS" >> massF4_mex.mki
echo "CLIBS=$CLIBS" >> massF4_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> massF4_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> massF4_mex.mki
echo "CXX=$CXX" >> massF4_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> massF4_mex.mki
echo "CXXLIBS=$CXXLIBS" >> massF4_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> massF4_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> massF4_mex.mki
echo "LDFLAGS=$LDFLAGS" >> massF4_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> massF4_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> massF4_mex.mki
echo "Arch=$Arch" >> massF4_mex.mki
echo "LD=$LD" >> massF4_mex.mki
echo OMPFLAGS= >> massF4_mex.mki
echo OMPLINKFLAGS= >> massF4_mex.mki
echo "EMC_COMPILER=gcc" >> massF4_mex.mki
echo "EMC_CONFIG=optim" >> massF4_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f massF4_mex.mk
