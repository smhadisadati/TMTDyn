MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for massF10" > massF10_mex.mki
echo "CC=$CC" >> massF10_mex.mki
echo "CFLAGS=$CFLAGS" >> massF10_mex.mki
echo "CLIBS=$CLIBS" >> massF10_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> massF10_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> massF10_mex.mki
echo "CXX=$CXX" >> massF10_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> massF10_mex.mki
echo "CXXLIBS=$CXXLIBS" >> massF10_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> massF10_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> massF10_mex.mki
echo "LDFLAGS=$LDFLAGS" >> massF10_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> massF10_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> massF10_mex.mki
echo "Arch=$Arch" >> massF10_mex.mki
echo "LD=$LD" >> massF10_mex.mki
echo OMPFLAGS= >> massF10_mex.mki
echo OMPLINKFLAGS= >> massF10_mex.mki
echo "EMC_COMPILER=gcc" >> massF10_mex.mki
echo "EMC_CONFIG=optim" >> massF10_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f massF10_mex.mk
