MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF75" > sprdmpF75_mex.mki
echo "CC=$CC" >> sprdmpF75_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF75_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF75_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF75_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF75_mex.mki
echo "CXX=$CXX" >> sprdmpF75_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF75_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF75_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF75_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF75_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF75_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF75_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF75_mex.mki
echo "Arch=$Arch" >> sprdmpF75_mex.mki
echo "LD=$LD" >> sprdmpF75_mex.mki
echo OMPFLAGS= >> sprdmpF75_mex.mki
echo OMPLINKFLAGS= >> sprdmpF75_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF75_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF75_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF75_mex.mk
