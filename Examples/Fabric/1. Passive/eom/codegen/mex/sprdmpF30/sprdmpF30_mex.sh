MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF30" > sprdmpF30_mex.mki
echo "CC=$CC" >> sprdmpF30_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF30_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF30_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF30_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF30_mex.mki
echo "CXX=$CXX" >> sprdmpF30_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF30_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF30_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF30_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF30_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF30_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF30_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF30_mex.mki
echo "Arch=$Arch" >> sprdmpF30_mex.mki
echo "LD=$LD" >> sprdmpF30_mex.mki
echo OMPFLAGS= >> sprdmpF30_mex.mki
echo OMPLINKFLAGS= >> sprdmpF30_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF30_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF30_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF30_mex.mk
