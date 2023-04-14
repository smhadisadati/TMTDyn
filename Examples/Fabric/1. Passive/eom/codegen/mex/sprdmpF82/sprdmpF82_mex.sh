MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF82" > sprdmpF82_mex.mki
echo "CC=$CC" >> sprdmpF82_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF82_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF82_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF82_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF82_mex.mki
echo "CXX=$CXX" >> sprdmpF82_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF82_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF82_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF82_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF82_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF82_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF82_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF82_mex.mki
echo "Arch=$Arch" >> sprdmpF82_mex.mki
echo "LD=$LD" >> sprdmpF82_mex.mki
echo OMPFLAGS= >> sprdmpF82_mex.mki
echo OMPLINKFLAGS= >> sprdmpF82_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF82_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF82_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF82_mex.mk
