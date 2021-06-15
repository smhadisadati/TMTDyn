MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF29" > sprdmpF29_mex.mki
echo "CC=$CC" >> sprdmpF29_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF29_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF29_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF29_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF29_mex.mki
echo "CXX=$CXX" >> sprdmpF29_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF29_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF29_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF29_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF29_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF29_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF29_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF29_mex.mki
echo "Arch=$Arch" >> sprdmpF29_mex.mki
echo "LD=$LD" >> sprdmpF29_mex.mki
echo OMPFLAGS= >> sprdmpF29_mex.mki
echo OMPLINKFLAGS= >> sprdmpF29_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF29_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF29_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF29_mex.mk
