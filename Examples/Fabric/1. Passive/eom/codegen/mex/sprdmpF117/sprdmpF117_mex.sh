MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF117" > sprdmpF117_mex.mki
echo "CC=$CC" >> sprdmpF117_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF117_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF117_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF117_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF117_mex.mki
echo "CXX=$CXX" >> sprdmpF117_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF117_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF117_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF117_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF117_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF117_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF117_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF117_mex.mki
echo "Arch=$Arch" >> sprdmpF117_mex.mki
echo "LD=$LD" >> sprdmpF117_mex.mki
echo OMPFLAGS= >> sprdmpF117_mex.mki
echo OMPLINKFLAGS= >> sprdmpF117_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF117_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF117_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF117_mex.mk
