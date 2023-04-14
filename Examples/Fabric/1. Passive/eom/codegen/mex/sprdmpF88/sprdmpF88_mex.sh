MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF88" > sprdmpF88_mex.mki
echo "CC=$CC" >> sprdmpF88_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF88_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF88_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF88_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF88_mex.mki
echo "CXX=$CXX" >> sprdmpF88_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF88_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF88_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF88_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF88_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF88_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF88_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF88_mex.mki
echo "Arch=$Arch" >> sprdmpF88_mex.mki
echo "LD=$LD" >> sprdmpF88_mex.mki
echo OMPFLAGS= >> sprdmpF88_mex.mki
echo OMPLINKFLAGS= >> sprdmpF88_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF88_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF88_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF88_mex.mk
