MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF25" > sprdmpF25_mex.mki
echo "CC=$CC" >> sprdmpF25_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF25_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF25_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF25_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF25_mex.mki
echo "CXX=$CXX" >> sprdmpF25_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF25_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF25_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF25_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF25_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF25_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF25_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF25_mex.mki
echo "Arch=$Arch" >> sprdmpF25_mex.mki
echo "LD=$LD" >> sprdmpF25_mex.mki
echo OMPFLAGS= >> sprdmpF25_mex.mki
echo OMPLINKFLAGS= >> sprdmpF25_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF25_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF25_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF25_mex.mk
