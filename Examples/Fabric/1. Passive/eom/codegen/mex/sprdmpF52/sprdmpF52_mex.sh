MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF52" > sprdmpF52_mex.mki
echo "CC=$CC" >> sprdmpF52_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF52_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF52_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF52_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF52_mex.mki
echo "CXX=$CXX" >> sprdmpF52_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF52_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF52_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF52_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF52_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF52_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF52_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF52_mex.mki
echo "Arch=$Arch" >> sprdmpF52_mex.mki
echo "LD=$LD" >> sprdmpF52_mex.mki
echo OMPFLAGS= >> sprdmpF52_mex.mki
echo OMPLINKFLAGS= >> sprdmpF52_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF52_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF52_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF52_mex.mk
