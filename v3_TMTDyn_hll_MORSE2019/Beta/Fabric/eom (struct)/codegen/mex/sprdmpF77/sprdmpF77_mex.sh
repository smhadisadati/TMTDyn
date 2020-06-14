MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF77" > sprdmpF77_mex.mki
echo "CC=$CC" >> sprdmpF77_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF77_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF77_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF77_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF77_mex.mki
echo "CXX=$CXX" >> sprdmpF77_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF77_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF77_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF77_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF77_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF77_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF77_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF77_mex.mki
echo "Arch=$Arch" >> sprdmpF77_mex.mki
echo "LD=$LD" >> sprdmpF77_mex.mki
echo OMPFLAGS= >> sprdmpF77_mex.mki
echo OMPLINKFLAGS= >> sprdmpF77_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF77_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF77_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF77_mex.mk
