MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF101" > sprdmpF101_mex.mki
echo "CC=$CC" >> sprdmpF101_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF101_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF101_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF101_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF101_mex.mki
echo "CXX=$CXX" >> sprdmpF101_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF101_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF101_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF101_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF101_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF101_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF101_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF101_mex.mki
echo "Arch=$Arch" >> sprdmpF101_mex.mki
echo "LD=$LD" >> sprdmpF101_mex.mki
echo OMPFLAGS= >> sprdmpF101_mex.mki
echo OMPLINKFLAGS= >> sprdmpF101_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF101_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF101_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF101_mex.mk
