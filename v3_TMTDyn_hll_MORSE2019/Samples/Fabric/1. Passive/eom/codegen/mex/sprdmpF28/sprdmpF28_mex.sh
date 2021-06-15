MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF28" > sprdmpF28_mex.mki
echo "CC=$CC" >> sprdmpF28_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF28_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF28_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF28_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF28_mex.mki
echo "CXX=$CXX" >> sprdmpF28_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF28_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF28_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF28_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF28_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF28_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF28_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF28_mex.mki
echo "Arch=$Arch" >> sprdmpF28_mex.mki
echo "LD=$LD" >> sprdmpF28_mex.mki
echo OMPFLAGS= >> sprdmpF28_mex.mki
echo OMPLINKFLAGS= >> sprdmpF28_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF28_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF28_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF28_mex.mk
