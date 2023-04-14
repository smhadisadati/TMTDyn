MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF123" > sprdmpF123_mex.mki
echo "CC=$CC" >> sprdmpF123_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF123_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF123_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF123_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF123_mex.mki
echo "CXX=$CXX" >> sprdmpF123_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF123_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF123_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF123_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF123_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF123_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF123_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF123_mex.mki
echo "Arch=$Arch" >> sprdmpF123_mex.mki
echo "LD=$LD" >> sprdmpF123_mex.mki
echo OMPFLAGS= >> sprdmpF123_mex.mki
echo OMPLINKFLAGS= >> sprdmpF123_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF123_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF123_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF123_mex.mk
