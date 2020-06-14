MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for massF16" > massF16_mex.mki
echo "CC=$CC" >> massF16_mex.mki
echo "CFLAGS=$CFLAGS" >> massF16_mex.mki
echo "CLIBS=$CLIBS" >> massF16_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> massF16_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> massF16_mex.mki
echo "CXX=$CXX" >> massF16_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> massF16_mex.mki
echo "CXXLIBS=$CXXLIBS" >> massF16_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> massF16_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> massF16_mex.mki
echo "LDFLAGS=$LDFLAGS" >> massF16_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> massF16_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> massF16_mex.mki
echo "Arch=$Arch" >> massF16_mex.mki
echo "LD=$LD" >> massF16_mex.mki
echo OMPFLAGS= >> massF16_mex.mki
echo OMPLINKFLAGS= >> massF16_mex.mki
echo "EMC_COMPILER=gcc" >> massF16_mex.mki
echo "EMC_CONFIG=optim" >> massF16_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f massF16_mex.mk
