MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF65" > sprdmpF65_mex.mki
echo "CC=$CC" >> sprdmpF65_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF65_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF65_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF65_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF65_mex.mki
echo "CXX=$CXX" >> sprdmpF65_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF65_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF65_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF65_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF65_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF65_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF65_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF65_mex.mki
echo "Arch=$Arch" >> sprdmpF65_mex.mki
echo "LD=$LD" >> sprdmpF65_mex.mki
echo OMPFLAGS= >> sprdmpF65_mex.mki
echo OMPLINKFLAGS= >> sprdmpF65_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF65_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF65_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF65_mex.mk
