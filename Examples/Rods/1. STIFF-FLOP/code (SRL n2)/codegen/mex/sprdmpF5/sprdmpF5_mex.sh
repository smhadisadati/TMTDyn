MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF5" > sprdmpF5_mex.mki
echo "CC=$CC" >> sprdmpF5_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF5_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF5_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF5_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF5_mex.mki
echo "CXX=$CXX" >> sprdmpF5_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF5_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF5_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF5_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF5_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF5_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF5_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF5_mex.mki
echo "Arch=$Arch" >> sprdmpF5_mex.mki
echo "LD=$LD" >> sprdmpF5_mex.mki
echo OMPFLAGS= >> sprdmpF5_mex.mki
echo OMPLINKFLAGS= >> sprdmpF5_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF5_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF5_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF5_mex.mk
