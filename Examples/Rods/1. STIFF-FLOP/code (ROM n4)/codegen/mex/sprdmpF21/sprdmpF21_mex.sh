MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF21" > sprdmpF21_mex.mki
echo "CC=$CC" >> sprdmpF21_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF21_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF21_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF21_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF21_mex.mki
echo "CXX=$CXX" >> sprdmpF21_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF21_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF21_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF21_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF21_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF21_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF21_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF21_mex.mki
echo "Arch=$Arch" >> sprdmpF21_mex.mki
echo "LD=$LD" >> sprdmpF21_mex.mki
echo OMPFLAGS= >> sprdmpF21_mex.mki
echo OMPLINKFLAGS= >> sprdmpF21_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF21_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF21_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF21_mex.mk
