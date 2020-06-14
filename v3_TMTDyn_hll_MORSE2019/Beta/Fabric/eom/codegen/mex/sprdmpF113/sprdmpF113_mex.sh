MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF113" > sprdmpF113_mex.mki
echo "CC=$CC" >> sprdmpF113_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF113_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF113_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF113_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF113_mex.mki
echo "CXX=$CXX" >> sprdmpF113_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF113_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF113_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF113_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF113_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF113_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF113_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF113_mex.mki
echo "Arch=$Arch" >> sprdmpF113_mex.mki
echo "LD=$LD" >> sprdmpF113_mex.mki
echo OMPFLAGS= >> sprdmpF113_mex.mki
echo OMPLINKFLAGS= >> sprdmpF113_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF113_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF113_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF113_mex.mk
