MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for massF2" > massF2_mex.mki
echo "CC=$CC" >> massF2_mex.mki
echo "CFLAGS=$CFLAGS" >> massF2_mex.mki
echo "CLIBS=$CLIBS" >> massF2_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> massF2_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> massF2_mex.mki
echo "CXX=$CXX" >> massF2_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> massF2_mex.mki
echo "CXXLIBS=$CXXLIBS" >> massF2_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> massF2_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> massF2_mex.mki
echo "LDFLAGS=$LDFLAGS" >> massF2_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> massF2_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> massF2_mex.mki
echo "Arch=$Arch" >> massF2_mex.mki
echo "LD=$LD" >> massF2_mex.mki
echo OMPFLAGS= >> massF2_mex.mki
echo OMPLINKFLAGS= >> massF2_mex.mki
echo "EMC_COMPILER=gcc" >> massF2_mex.mki
echo "EMC_CONFIG=optim" >> massF2_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f massF2_mex.mk
