MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF45" > sprdmpF45_mex.mki
echo "CC=$CC" >> sprdmpF45_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF45_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF45_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF45_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF45_mex.mki
echo "CXX=$CXX" >> sprdmpF45_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF45_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF45_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF45_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF45_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF45_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF45_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF45_mex.mki
echo "Arch=$Arch" >> sprdmpF45_mex.mki
echo "LD=$LD" >> sprdmpF45_mex.mki
echo OMPFLAGS= >> sprdmpF45_mex.mki
echo OMPLINKFLAGS= >> sprdmpF45_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF45_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF45_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF45_mex.mk
