MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for massF12" > massF12_mex.mki
echo "CC=$CC" >> massF12_mex.mki
echo "CFLAGS=$CFLAGS" >> massF12_mex.mki
echo "CLIBS=$CLIBS" >> massF12_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> massF12_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> massF12_mex.mki
echo "CXX=$CXX" >> massF12_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> massF12_mex.mki
echo "CXXLIBS=$CXXLIBS" >> massF12_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> massF12_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> massF12_mex.mki
echo "LDFLAGS=$LDFLAGS" >> massF12_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> massF12_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> massF12_mex.mki
echo "Arch=$Arch" >> massF12_mex.mki
echo "LD=$LD" >> massF12_mex.mki
echo OMPFLAGS= >> massF12_mex.mki
echo OMPLINKFLAGS= >> massF12_mex.mki
echo "EMC_COMPILER=gcc" >> massF12_mex.mki
echo "EMC_CONFIG=optim" >> massF12_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f massF12_mex.mk
