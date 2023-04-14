MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF84" > sprdmpF84_mex.mki
echo "CC=$CC" >> sprdmpF84_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF84_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF84_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF84_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF84_mex.mki
echo "CXX=$CXX" >> sprdmpF84_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF84_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF84_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF84_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF84_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF84_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF84_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF84_mex.mki
echo "Arch=$Arch" >> sprdmpF84_mex.mki
echo "LD=$LD" >> sprdmpF84_mex.mki
echo OMPFLAGS= >> sprdmpF84_mex.mki
echo OMPLINKFLAGS= >> sprdmpF84_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF84_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF84_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF84_mex.mk
