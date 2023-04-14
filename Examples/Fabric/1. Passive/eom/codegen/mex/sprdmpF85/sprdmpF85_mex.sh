MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF85" > sprdmpF85_mex.mki
echo "CC=$CC" >> sprdmpF85_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF85_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF85_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF85_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF85_mex.mki
echo "CXX=$CXX" >> sprdmpF85_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF85_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF85_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF85_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF85_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF85_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF85_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF85_mex.mki
echo "Arch=$Arch" >> sprdmpF85_mex.mki
echo "LD=$LD" >> sprdmpF85_mex.mki
echo OMPFLAGS= >> sprdmpF85_mex.mki
echo OMPLINKFLAGS= >> sprdmpF85_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF85_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF85_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF85_mex.mk
