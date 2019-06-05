MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF13" > sprdmpF13_mex.mki
echo "CC=$CC" >> sprdmpF13_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF13_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF13_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF13_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF13_mex.mki
echo "CXX=$CXX" >> sprdmpF13_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF13_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF13_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF13_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF13_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF13_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF13_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF13_mex.mki
echo "Arch=$Arch" >> sprdmpF13_mex.mki
echo "LD=$LD" >> sprdmpF13_mex.mki
echo OMPFLAGS= >> sprdmpF13_mex.mki
echo OMPLINKFLAGS= >> sprdmpF13_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF13_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF13_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF13_mex.mk
