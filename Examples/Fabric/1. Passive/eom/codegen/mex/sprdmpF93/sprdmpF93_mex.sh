MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF93" > sprdmpF93_mex.mki
echo "CC=$CC" >> sprdmpF93_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF93_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF93_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF93_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF93_mex.mki
echo "CXX=$CXX" >> sprdmpF93_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF93_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF93_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF93_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF93_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF93_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF93_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF93_mex.mki
echo "Arch=$Arch" >> sprdmpF93_mex.mki
echo "LD=$LD" >> sprdmpF93_mex.mki
echo OMPFLAGS= >> sprdmpF93_mex.mki
echo OMPLINKFLAGS= >> sprdmpF93_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF93_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF93_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF93_mex.mk
