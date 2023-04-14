MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF68" > sprdmpF68_mex.mki
echo "CC=$CC" >> sprdmpF68_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF68_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF68_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF68_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF68_mex.mki
echo "CXX=$CXX" >> sprdmpF68_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF68_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF68_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF68_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF68_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF68_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF68_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF68_mex.mki
echo "Arch=$Arch" >> sprdmpF68_mex.mki
echo "LD=$LD" >> sprdmpF68_mex.mki
echo OMPFLAGS= >> sprdmpF68_mex.mki
echo OMPLINKFLAGS= >> sprdmpF68_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF68_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF68_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF68_mex.mk
