MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF40" > sprdmpF40_mex.mki
echo "CC=$CC" >> sprdmpF40_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF40_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF40_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF40_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF40_mex.mki
echo "CXX=$CXX" >> sprdmpF40_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF40_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF40_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF40_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF40_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF40_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF40_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF40_mex.mki
echo "Arch=$Arch" >> sprdmpF40_mex.mki
echo "LD=$LD" >> sprdmpF40_mex.mki
echo OMPFLAGS= >> sprdmpF40_mex.mki
echo OMPLINKFLAGS= >> sprdmpF40_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF40_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF40_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF40_mex.mk
