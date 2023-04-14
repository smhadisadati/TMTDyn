MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF124" > sprdmpF124_mex.mki
echo "CC=$CC" >> sprdmpF124_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF124_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF124_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF124_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF124_mex.mki
echo "CXX=$CXX" >> sprdmpF124_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF124_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF124_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF124_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF124_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF124_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF124_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF124_mex.mki
echo "Arch=$Arch" >> sprdmpF124_mex.mki
echo "LD=$LD" >> sprdmpF124_mex.mki
echo OMPFLAGS= >> sprdmpF124_mex.mki
echo OMPLINKFLAGS= >> sprdmpF124_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF124_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF124_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF124_mex.mk
