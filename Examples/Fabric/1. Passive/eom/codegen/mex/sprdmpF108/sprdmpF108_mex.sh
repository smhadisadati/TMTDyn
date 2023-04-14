MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF108" > sprdmpF108_mex.mki
echo "CC=$CC" >> sprdmpF108_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF108_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF108_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF108_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF108_mex.mki
echo "CXX=$CXX" >> sprdmpF108_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF108_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF108_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF108_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF108_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF108_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF108_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF108_mex.mki
echo "Arch=$Arch" >> sprdmpF108_mex.mki
echo "LD=$LD" >> sprdmpF108_mex.mki
echo OMPFLAGS= >> sprdmpF108_mex.mki
echo OMPLINKFLAGS= >> sprdmpF108_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF108_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF108_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF108_mex.mk
