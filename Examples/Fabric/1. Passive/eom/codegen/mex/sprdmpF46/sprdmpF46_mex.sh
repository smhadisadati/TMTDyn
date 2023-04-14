MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF46" > sprdmpF46_mex.mki
echo "CC=$CC" >> sprdmpF46_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF46_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF46_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF46_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF46_mex.mki
echo "CXX=$CXX" >> sprdmpF46_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF46_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF46_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF46_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF46_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF46_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF46_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF46_mex.mki
echo "Arch=$Arch" >> sprdmpF46_mex.mki
echo "LD=$LD" >> sprdmpF46_mex.mki
echo OMPFLAGS= >> sprdmpF46_mex.mki
echo OMPLINKFLAGS= >> sprdmpF46_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF46_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF46_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF46_mex.mk
