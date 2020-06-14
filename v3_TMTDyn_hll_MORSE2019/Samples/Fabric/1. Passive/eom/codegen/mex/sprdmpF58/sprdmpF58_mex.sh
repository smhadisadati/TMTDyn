MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF58" > sprdmpF58_mex.mki
echo "CC=$CC" >> sprdmpF58_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF58_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF58_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF58_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF58_mex.mki
echo "CXX=$CXX" >> sprdmpF58_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF58_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF58_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF58_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF58_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF58_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF58_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF58_mex.mki
echo "Arch=$Arch" >> sprdmpF58_mex.mki
echo "LD=$LD" >> sprdmpF58_mex.mki
echo OMPFLAGS= >> sprdmpF58_mex.mki
echo OMPLINKFLAGS= >> sprdmpF58_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF58_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF58_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF58_mex.mk
