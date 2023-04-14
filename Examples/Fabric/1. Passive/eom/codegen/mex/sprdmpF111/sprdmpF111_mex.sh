MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF111" > sprdmpF111_mex.mki
echo "CC=$CC" >> sprdmpF111_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF111_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF111_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF111_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF111_mex.mki
echo "CXX=$CXX" >> sprdmpF111_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF111_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF111_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF111_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF111_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF111_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF111_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF111_mex.mki
echo "Arch=$Arch" >> sprdmpF111_mex.mki
echo "LD=$LD" >> sprdmpF111_mex.mki
echo OMPFLAGS= >> sprdmpF111_mex.mki
echo OMPLINKFLAGS= >> sprdmpF111_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF111_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF111_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF111_mex.mk
