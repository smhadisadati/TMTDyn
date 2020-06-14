MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF128" > sprdmpF128_mex.mki
echo "CC=$CC" >> sprdmpF128_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF128_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF128_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF128_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF128_mex.mki
echo "CXX=$CXX" >> sprdmpF128_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF128_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF128_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF128_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF128_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF128_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF128_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF128_mex.mki
echo "Arch=$Arch" >> sprdmpF128_mex.mki
echo "LD=$LD" >> sprdmpF128_mex.mki
echo OMPFLAGS= >> sprdmpF128_mex.mki
echo OMPLINKFLAGS= >> sprdmpF128_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF128_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF128_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF128_mex.mk
