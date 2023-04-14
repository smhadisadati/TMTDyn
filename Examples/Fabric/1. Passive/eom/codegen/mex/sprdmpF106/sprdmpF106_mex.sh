MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF106" > sprdmpF106_mex.mki
echo "CC=$CC" >> sprdmpF106_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF106_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF106_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF106_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF106_mex.mki
echo "CXX=$CXX" >> sprdmpF106_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF106_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF106_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF106_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF106_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF106_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF106_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF106_mex.mki
echo "Arch=$Arch" >> sprdmpF106_mex.mki
echo "LD=$LD" >> sprdmpF106_mex.mki
echo OMPFLAGS= >> sprdmpF106_mex.mki
echo OMPLINKFLAGS= >> sprdmpF106_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF106_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF106_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF106_mex.mk
