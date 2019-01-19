MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for massF1" > massF1_mex.mki
echo "CC=$CC" >> massF1_mex.mki
echo "CFLAGS=$CFLAGS" >> massF1_mex.mki
echo "CLIBS=$CLIBS" >> massF1_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> massF1_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> massF1_mex.mki
echo "CXX=$CXX" >> massF1_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> massF1_mex.mki
echo "CXXLIBS=$CXXLIBS" >> massF1_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> massF1_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> massF1_mex.mki
echo "LDFLAGS=$LDFLAGS" >> massF1_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> massF1_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> massF1_mex.mki
echo "Arch=$Arch" >> massF1_mex.mki
echo "LD=$LD" >> massF1_mex.mki
echo OMPFLAGS= >> massF1_mex.mki
echo OMPLINKFLAGS= >> massF1_mex.mki
echo "EMC_COMPILER=gcc" >> massF1_mex.mki
echo "EMC_CONFIG=optim" >> massF1_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f massF1_mex.mk
