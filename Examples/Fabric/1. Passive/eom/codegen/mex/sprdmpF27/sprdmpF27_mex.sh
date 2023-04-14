MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF27" > sprdmpF27_mex.mki
echo "CC=$CC" >> sprdmpF27_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF27_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF27_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF27_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF27_mex.mki
echo "CXX=$CXX" >> sprdmpF27_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF27_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF27_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF27_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF27_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF27_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF27_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF27_mex.mki
echo "Arch=$Arch" >> sprdmpF27_mex.mki
echo "LD=$LD" >> sprdmpF27_mex.mki
echo OMPFLAGS= >> sprdmpF27_mex.mki
echo OMPLINKFLAGS= >> sprdmpF27_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF27_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF27_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF27_mex.mk
