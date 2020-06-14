MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF49" > sprdmpF49_mex.mki
echo "CC=$CC" >> sprdmpF49_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF49_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF49_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF49_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF49_mex.mki
echo "CXX=$CXX" >> sprdmpF49_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF49_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF49_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF49_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF49_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF49_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF49_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF49_mex.mki
echo "Arch=$Arch" >> sprdmpF49_mex.mki
echo "LD=$LD" >> sprdmpF49_mex.mki
echo OMPFLAGS= >> sprdmpF49_mex.mki
echo OMPLINKFLAGS= >> sprdmpF49_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF49_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF49_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF49_mex.mk
