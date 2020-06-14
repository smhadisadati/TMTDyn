MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for massF15" > massF15_mex.mki
echo "CC=$CC" >> massF15_mex.mki
echo "CFLAGS=$CFLAGS" >> massF15_mex.mki
echo "CLIBS=$CLIBS" >> massF15_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> massF15_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> massF15_mex.mki
echo "CXX=$CXX" >> massF15_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> massF15_mex.mki
echo "CXXLIBS=$CXXLIBS" >> massF15_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> massF15_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> massF15_mex.mki
echo "LDFLAGS=$LDFLAGS" >> massF15_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> massF15_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> massF15_mex.mki
echo "Arch=$Arch" >> massF15_mex.mki
echo "LD=$LD" >> massF15_mex.mki
echo OMPFLAGS= >> massF15_mex.mki
echo OMPLINKFLAGS= >> massF15_mex.mki
echo "EMC_COMPILER=gcc" >> massF15_mex.mki
echo "EMC_CONFIG=optim" >> massF15_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f massF15_mex.mk
