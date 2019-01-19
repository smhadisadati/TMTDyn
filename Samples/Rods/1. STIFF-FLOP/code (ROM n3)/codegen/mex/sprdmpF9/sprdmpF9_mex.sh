MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF9" > sprdmpF9_mex.mki
echo "CC=$CC" >> sprdmpF9_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF9_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF9_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF9_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF9_mex.mki
echo "CXX=$CXX" >> sprdmpF9_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF9_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF9_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF9_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF9_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF9_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF9_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF9_mex.mki
echo "Arch=$Arch" >> sprdmpF9_mex.mki
echo "LD=$LD" >> sprdmpF9_mex.mki
echo OMPFLAGS= >> sprdmpF9_mex.mki
echo OMPLINKFLAGS= >> sprdmpF9_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF9_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF9_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF9_mex.mk
