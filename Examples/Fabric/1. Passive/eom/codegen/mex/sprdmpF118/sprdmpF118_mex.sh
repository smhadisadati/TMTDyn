MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF118" > sprdmpF118_mex.mki
echo "CC=$CC" >> sprdmpF118_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF118_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF118_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF118_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF118_mex.mki
echo "CXX=$CXX" >> sprdmpF118_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF118_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF118_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF118_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF118_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF118_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF118_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF118_mex.mki
echo "Arch=$Arch" >> sprdmpF118_mex.mki
echo "LD=$LD" >> sprdmpF118_mex.mki
echo OMPFLAGS= >> sprdmpF118_mex.mki
echo OMPLINKFLAGS= >> sprdmpF118_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF118_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF118_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF118_mex.mk
