MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for massF5" > massF5_mex.mki
echo "CC=$CC" >> massF5_mex.mki
echo "CFLAGS=$CFLAGS" >> massF5_mex.mki
echo "CLIBS=$CLIBS" >> massF5_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> massF5_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> massF5_mex.mki
echo "CXX=$CXX" >> massF5_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> massF5_mex.mki
echo "CXXLIBS=$CXXLIBS" >> massF5_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> massF5_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> massF5_mex.mki
echo "LDFLAGS=$LDFLAGS" >> massF5_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> massF5_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> massF5_mex.mki
echo "Arch=$Arch" >> massF5_mex.mki
echo "LD=$LD" >> massF5_mex.mki
echo OMPFLAGS= >> massF5_mex.mki
echo OMPLINKFLAGS= >> massF5_mex.mki
echo "EMC_COMPILER=gcc" >> massF5_mex.mki
echo "EMC_CONFIG=optim" >> massF5_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f massF5_mex.mk
