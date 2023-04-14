MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF48" > sprdmpF48_mex.mki
echo "CC=$CC" >> sprdmpF48_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF48_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF48_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF48_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF48_mex.mki
echo "CXX=$CXX" >> sprdmpF48_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF48_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF48_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF48_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF48_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF48_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF48_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF48_mex.mki
echo "Arch=$Arch" >> sprdmpF48_mex.mki
echo "LD=$LD" >> sprdmpF48_mex.mki
echo OMPFLAGS= >> sprdmpF48_mex.mki
echo OMPLINKFLAGS= >> sprdmpF48_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF48_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF48_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF48_mex.mk
