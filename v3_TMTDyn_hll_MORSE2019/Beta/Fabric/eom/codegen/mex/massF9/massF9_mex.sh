MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for massF9" > massF9_mex.mki
echo "CC=$CC" >> massF9_mex.mki
echo "CFLAGS=$CFLAGS" >> massF9_mex.mki
echo "CLIBS=$CLIBS" >> massF9_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> massF9_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> massF9_mex.mki
echo "CXX=$CXX" >> massF9_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> massF9_mex.mki
echo "CXXLIBS=$CXXLIBS" >> massF9_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> massF9_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> massF9_mex.mki
echo "LDFLAGS=$LDFLAGS" >> massF9_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> massF9_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> massF9_mex.mki
echo "Arch=$Arch" >> massF9_mex.mki
echo "LD=$LD" >> massF9_mex.mki
echo OMPFLAGS= >> massF9_mex.mki
echo OMPLINKFLAGS= >> massF9_mex.mki
echo "EMC_COMPILER=gcc" >> massF9_mex.mki
echo "EMC_CONFIG=optim" >> massF9_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f massF9_mex.mk
