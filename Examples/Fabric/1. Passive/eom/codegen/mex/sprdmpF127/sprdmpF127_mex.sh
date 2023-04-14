MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF127" > sprdmpF127_mex.mki
echo "CC=$CC" >> sprdmpF127_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF127_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF127_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF127_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF127_mex.mki
echo "CXX=$CXX" >> sprdmpF127_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF127_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF127_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF127_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF127_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF127_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF127_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF127_mex.mki
echo "Arch=$Arch" >> sprdmpF127_mex.mki
echo "LD=$LD" >> sprdmpF127_mex.mki
echo OMPFLAGS= >> sprdmpF127_mex.mki
echo OMPLINKFLAGS= >> sprdmpF127_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF127_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF127_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF127_mex.mk
