MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF90" > sprdmpF90_mex.mki
echo "CC=$CC" >> sprdmpF90_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF90_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF90_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF90_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF90_mex.mki
echo "CXX=$CXX" >> sprdmpF90_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF90_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF90_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF90_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF90_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF90_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF90_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF90_mex.mki
echo "Arch=$Arch" >> sprdmpF90_mex.mki
echo "LD=$LD" >> sprdmpF90_mex.mki
echo OMPFLAGS= >> sprdmpF90_mex.mki
echo OMPLINKFLAGS= >> sprdmpF90_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF90_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF90_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF90_mex.mk
