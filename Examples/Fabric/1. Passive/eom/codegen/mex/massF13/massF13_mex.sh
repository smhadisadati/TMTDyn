MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for massF13" > massF13_mex.mki
echo "CC=$CC" >> massF13_mex.mki
echo "CFLAGS=$CFLAGS" >> massF13_mex.mki
echo "CLIBS=$CLIBS" >> massF13_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> massF13_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> massF13_mex.mki
echo "CXX=$CXX" >> massF13_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> massF13_mex.mki
echo "CXXLIBS=$CXXLIBS" >> massF13_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> massF13_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> massF13_mex.mki
echo "LDFLAGS=$LDFLAGS" >> massF13_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> massF13_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> massF13_mex.mki
echo "Arch=$Arch" >> massF13_mex.mki
echo "LD=$LD" >> massF13_mex.mki
echo OMPFLAGS= >> massF13_mex.mki
echo OMPLINKFLAGS= >> massF13_mex.mki
echo "EMC_COMPILER=gcc" >> massF13_mex.mki
echo "EMC_CONFIG=optim" >> massF13_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f massF13_mex.mk
