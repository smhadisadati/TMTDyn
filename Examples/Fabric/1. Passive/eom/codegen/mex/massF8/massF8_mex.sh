MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for massF8" > massF8_mex.mki
echo "CC=$CC" >> massF8_mex.mki
echo "CFLAGS=$CFLAGS" >> massF8_mex.mki
echo "CLIBS=$CLIBS" >> massF8_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> massF8_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> massF8_mex.mki
echo "CXX=$CXX" >> massF8_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> massF8_mex.mki
echo "CXXLIBS=$CXXLIBS" >> massF8_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> massF8_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> massF8_mex.mki
echo "LDFLAGS=$LDFLAGS" >> massF8_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> massF8_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> massF8_mex.mki
echo "Arch=$Arch" >> massF8_mex.mki
echo "LD=$LD" >> massF8_mex.mki
echo OMPFLAGS= >> massF8_mex.mki
echo OMPLINKFLAGS= >> massF8_mex.mki
echo "EMC_COMPILER=gcc" >> massF8_mex.mki
echo "EMC_CONFIG=optim" >> massF8_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f massF8_mex.mk
