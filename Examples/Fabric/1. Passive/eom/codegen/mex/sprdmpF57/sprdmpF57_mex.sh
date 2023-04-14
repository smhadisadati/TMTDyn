MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF57" > sprdmpF57_mex.mki
echo "CC=$CC" >> sprdmpF57_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF57_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF57_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF57_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF57_mex.mki
echo "CXX=$CXX" >> sprdmpF57_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF57_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF57_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF57_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF57_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF57_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF57_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF57_mex.mki
echo "Arch=$Arch" >> sprdmpF57_mex.mki
echo "LD=$LD" >> sprdmpF57_mex.mki
echo OMPFLAGS= >> sprdmpF57_mex.mki
echo OMPLINKFLAGS= >> sprdmpF57_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF57_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF57_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF57_mex.mk
