MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF109" > sprdmpF109_mex.mki
echo "CC=$CC" >> sprdmpF109_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF109_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF109_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF109_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF109_mex.mki
echo "CXX=$CXX" >> sprdmpF109_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF109_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF109_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF109_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF109_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF109_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF109_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF109_mex.mki
echo "Arch=$Arch" >> sprdmpF109_mex.mki
echo "LD=$LD" >> sprdmpF109_mex.mki
echo OMPFLAGS= >> sprdmpF109_mex.mki
echo OMPLINKFLAGS= >> sprdmpF109_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF109_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF109_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF109_mex.mk
