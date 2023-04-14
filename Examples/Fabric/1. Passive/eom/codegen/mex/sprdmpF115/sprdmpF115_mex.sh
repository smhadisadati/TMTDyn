MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF115" > sprdmpF115_mex.mki
echo "CC=$CC" >> sprdmpF115_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF115_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF115_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF115_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF115_mex.mki
echo "CXX=$CXX" >> sprdmpF115_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF115_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF115_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF115_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF115_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF115_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF115_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF115_mex.mki
echo "Arch=$Arch" >> sprdmpF115_mex.mki
echo "LD=$LD" >> sprdmpF115_mex.mki
echo OMPFLAGS= >> sprdmpF115_mex.mki
echo OMPLINKFLAGS= >> sprdmpF115_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF115_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF115_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF115_mex.mk
