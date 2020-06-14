MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF100" > sprdmpF100_mex.mki
echo "CC=$CC" >> sprdmpF100_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF100_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF100_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF100_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF100_mex.mki
echo "CXX=$CXX" >> sprdmpF100_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF100_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF100_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF100_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF100_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF100_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF100_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF100_mex.mki
echo "Arch=$Arch" >> sprdmpF100_mex.mki
echo "LD=$LD" >> sprdmpF100_mex.mki
echo OMPFLAGS= >> sprdmpF100_mex.mki
echo OMPLINKFLAGS= >> sprdmpF100_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF100_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF100_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF100_mex.mk
