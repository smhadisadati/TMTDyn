MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF122" > sprdmpF122_mex.mki
echo "CC=$CC" >> sprdmpF122_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF122_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF122_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF122_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF122_mex.mki
echo "CXX=$CXX" >> sprdmpF122_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF122_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF122_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF122_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF122_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF122_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF122_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF122_mex.mki
echo "Arch=$Arch" >> sprdmpF122_mex.mki
echo "LD=$LD" >> sprdmpF122_mex.mki
echo OMPFLAGS= >> sprdmpF122_mex.mki
echo OMPLINKFLAGS= >> sprdmpF122_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF122_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF122_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF122_mex.mk
