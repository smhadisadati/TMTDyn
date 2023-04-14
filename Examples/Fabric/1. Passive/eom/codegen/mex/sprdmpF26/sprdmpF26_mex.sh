MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF26" > sprdmpF26_mex.mki
echo "CC=$CC" >> sprdmpF26_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF26_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF26_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF26_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF26_mex.mki
echo "CXX=$CXX" >> sprdmpF26_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF26_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF26_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF26_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF26_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF26_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF26_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF26_mex.mki
echo "Arch=$Arch" >> sprdmpF26_mex.mki
echo "LD=$LD" >> sprdmpF26_mex.mki
echo OMPFLAGS= >> sprdmpF26_mex.mki
echo OMPLINKFLAGS= >> sprdmpF26_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF26_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF26_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF26_mex.mk
