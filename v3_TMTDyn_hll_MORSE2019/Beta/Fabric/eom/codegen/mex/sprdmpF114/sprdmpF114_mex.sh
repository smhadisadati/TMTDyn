MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF114" > sprdmpF114_mex.mki
echo "CC=$CC" >> sprdmpF114_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF114_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF114_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF114_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF114_mex.mki
echo "CXX=$CXX" >> sprdmpF114_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF114_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF114_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF114_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF114_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF114_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF114_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF114_mex.mki
echo "Arch=$Arch" >> sprdmpF114_mex.mki
echo "LD=$LD" >> sprdmpF114_mex.mki
echo OMPFLAGS= >> sprdmpF114_mex.mki
echo OMPLINKFLAGS= >> sprdmpF114_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF114_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF114_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF114_mex.mk
