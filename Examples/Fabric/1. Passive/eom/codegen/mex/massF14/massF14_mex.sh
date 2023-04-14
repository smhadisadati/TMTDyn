MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for massF14" > massF14_mex.mki
echo "CC=$CC" >> massF14_mex.mki
echo "CFLAGS=$CFLAGS" >> massF14_mex.mki
echo "CLIBS=$CLIBS" >> massF14_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> massF14_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> massF14_mex.mki
echo "CXX=$CXX" >> massF14_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> massF14_mex.mki
echo "CXXLIBS=$CXXLIBS" >> massF14_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> massF14_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> massF14_mex.mki
echo "LDFLAGS=$LDFLAGS" >> massF14_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> massF14_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> massF14_mex.mki
echo "Arch=$Arch" >> massF14_mex.mki
echo "LD=$LD" >> massF14_mex.mki
echo OMPFLAGS= >> massF14_mex.mki
echo OMPLINKFLAGS= >> massF14_mex.mki
echo "EMC_COMPILER=gcc" >> massF14_mex.mki
echo "EMC_CONFIG=optim" >> massF14_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f massF14_mex.mk
