MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF37" > sprdmpF37_mex.mki
echo "CC=$CC" >> sprdmpF37_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF37_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF37_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF37_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF37_mex.mki
echo "CXX=$CXX" >> sprdmpF37_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF37_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF37_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF37_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF37_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF37_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF37_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF37_mex.mki
echo "Arch=$Arch" >> sprdmpF37_mex.mki
echo "LD=$LD" >> sprdmpF37_mex.mki
echo OMPFLAGS= >> sprdmpF37_mex.mki
echo OMPLINKFLAGS= >> sprdmpF37_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF37_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF37_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF37_mex.mk
