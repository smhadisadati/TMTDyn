MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for massF11" > massF11_mex.mki
echo "CC=$CC" >> massF11_mex.mki
echo "CFLAGS=$CFLAGS" >> massF11_mex.mki
echo "CLIBS=$CLIBS" >> massF11_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> massF11_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> massF11_mex.mki
echo "CXX=$CXX" >> massF11_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> massF11_mex.mki
echo "CXXLIBS=$CXXLIBS" >> massF11_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> massF11_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> massF11_mex.mki
echo "LDFLAGS=$LDFLAGS" >> massF11_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> massF11_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> massF11_mex.mki
echo "Arch=$Arch" >> massF11_mex.mki
echo "LD=$LD" >> massF11_mex.mki
echo OMPFLAGS= >> massF11_mex.mki
echo OMPLINKFLAGS= >> massF11_mex.mki
echo "EMC_COMPILER=gcc" >> massF11_mex.mki
echo "EMC_CONFIG=optim" >> massF11_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f massF11_mex.mk
