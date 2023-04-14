MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for massF3" > massF3_mex.mki
echo "CC=$CC" >> massF3_mex.mki
echo "CFLAGS=$CFLAGS" >> massF3_mex.mki
echo "CLIBS=$CLIBS" >> massF3_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> massF3_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> massF3_mex.mki
echo "CXX=$CXX" >> massF3_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> massF3_mex.mki
echo "CXXLIBS=$CXXLIBS" >> massF3_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> massF3_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> massF3_mex.mki
echo "LDFLAGS=$LDFLAGS" >> massF3_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> massF3_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> massF3_mex.mki
echo "Arch=$Arch" >> massF3_mex.mki
echo "LD=$LD" >> massF3_mex.mki
echo OMPFLAGS= >> massF3_mex.mki
echo OMPLINKFLAGS= >> massF3_mex.mki
echo "EMC_COMPILER=gcc" >> massF3_mex.mki
echo "EMC_CONFIG=optim" >> massF3_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f massF3_mex.mk
