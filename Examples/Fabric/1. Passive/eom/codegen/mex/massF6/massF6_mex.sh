MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for massF6" > massF6_mex.mki
echo "CC=$CC" >> massF6_mex.mki
echo "CFLAGS=$CFLAGS" >> massF6_mex.mki
echo "CLIBS=$CLIBS" >> massF6_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> massF6_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> massF6_mex.mki
echo "CXX=$CXX" >> massF6_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> massF6_mex.mki
echo "CXXLIBS=$CXXLIBS" >> massF6_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> massF6_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> massF6_mex.mki
echo "LDFLAGS=$LDFLAGS" >> massF6_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> massF6_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> massF6_mex.mki
echo "Arch=$Arch" >> massF6_mex.mki
echo "LD=$LD" >> massF6_mex.mki
echo OMPFLAGS= >> massF6_mex.mki
echo OMPLINKFLAGS= >> massF6_mex.mki
echo "EMC_COMPILER=gcc" >> massF6_mex.mki
echo "EMC_CONFIG=optim" >> massF6_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f massF6_mex.mk
