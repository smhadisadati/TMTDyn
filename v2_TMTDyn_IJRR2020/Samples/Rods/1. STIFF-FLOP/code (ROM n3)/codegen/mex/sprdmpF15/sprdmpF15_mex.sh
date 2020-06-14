MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF15" > sprdmpF15_mex.mki
echo "CC=$CC" >> sprdmpF15_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF15_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF15_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF15_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF15_mex.mki
echo "CXX=$CXX" >> sprdmpF15_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF15_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF15_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF15_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF15_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF15_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF15_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF15_mex.mki
echo "Arch=$Arch" >> sprdmpF15_mex.mki
echo "LD=$LD" >> sprdmpF15_mex.mki
echo OMPFLAGS= >> sprdmpF15_mex.mki
echo OMPLINKFLAGS= >> sprdmpF15_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF15_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF15_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF15_mex.mk
