MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF105" > sprdmpF105_mex.mki
echo "CC=$CC" >> sprdmpF105_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF105_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF105_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF105_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF105_mex.mki
echo "CXX=$CXX" >> sprdmpF105_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF105_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF105_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF105_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF105_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF105_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF105_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF105_mex.mki
echo "Arch=$Arch" >> sprdmpF105_mex.mki
echo "LD=$LD" >> sprdmpF105_mex.mki
echo OMPFLAGS= >> sprdmpF105_mex.mki
echo OMPLINKFLAGS= >> sprdmpF105_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF105_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF105_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF105_mex.mk
