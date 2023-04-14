MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for massF7" > massF7_mex.mki
echo "CC=$CC" >> massF7_mex.mki
echo "CFLAGS=$CFLAGS" >> massF7_mex.mki
echo "CLIBS=$CLIBS" >> massF7_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> massF7_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> massF7_mex.mki
echo "CXX=$CXX" >> massF7_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> massF7_mex.mki
echo "CXXLIBS=$CXXLIBS" >> massF7_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> massF7_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> massF7_mex.mki
echo "LDFLAGS=$LDFLAGS" >> massF7_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> massF7_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> massF7_mex.mki
echo "Arch=$Arch" >> massF7_mex.mki
echo "LD=$LD" >> massF7_mex.mki
echo OMPFLAGS= >> massF7_mex.mki
echo OMPLINKFLAGS= >> massF7_mex.mki
echo "EMC_COMPILER=gcc" >> massF7_mex.mki
echo "EMC_CONFIG=optim" >> massF7_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f massF7_mex.mk
