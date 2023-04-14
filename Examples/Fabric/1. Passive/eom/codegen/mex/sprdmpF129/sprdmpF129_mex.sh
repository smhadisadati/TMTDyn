MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF129" > sprdmpF129_mex.mki
echo "CC=$CC" >> sprdmpF129_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF129_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF129_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF129_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF129_mex.mki
echo "CXX=$CXX" >> sprdmpF129_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF129_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF129_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF129_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF129_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF129_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF129_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF129_mex.mki
echo "Arch=$Arch" >> sprdmpF129_mex.mki
echo "LD=$LD" >> sprdmpF129_mex.mki
echo OMPFLAGS= >> sprdmpF129_mex.mki
echo OMPLINKFLAGS= >> sprdmpF129_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF129_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF129_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF129_mex.mk
