MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF4" > sprdmpF4_mex.mki
echo "CC=$CC" >> sprdmpF4_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF4_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF4_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF4_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF4_mex.mki
echo "CXX=$CXX" >> sprdmpF4_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF4_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF4_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF4_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF4_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF4_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF4_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF4_mex.mki
echo "Arch=$Arch" >> sprdmpF4_mex.mki
echo "LD=$LD" >> sprdmpF4_mex.mki
echo OMPFLAGS= >> sprdmpF4_mex.mki
echo OMPLINKFLAGS= >> sprdmpF4_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF4_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF4_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF4_mex.mk
