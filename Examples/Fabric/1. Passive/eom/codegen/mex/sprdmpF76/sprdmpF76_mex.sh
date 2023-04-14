MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF76" > sprdmpF76_mex.mki
echo "CC=$CC" >> sprdmpF76_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF76_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF76_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF76_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF76_mex.mki
echo "CXX=$CXX" >> sprdmpF76_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF76_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF76_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF76_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF76_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF76_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF76_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF76_mex.mki
echo "Arch=$Arch" >> sprdmpF76_mex.mki
echo "LD=$LD" >> sprdmpF76_mex.mki
echo OMPFLAGS= >> sprdmpF76_mex.mki
echo OMPLINKFLAGS= >> sprdmpF76_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF76_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF76_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF76_mex.mk
