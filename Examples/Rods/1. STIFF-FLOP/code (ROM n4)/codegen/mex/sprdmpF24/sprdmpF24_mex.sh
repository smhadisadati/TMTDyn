MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF24" > sprdmpF24_mex.mki
echo "CC=$CC" >> sprdmpF24_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF24_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF24_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF24_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF24_mex.mki
echo "CXX=$CXX" >> sprdmpF24_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF24_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF24_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF24_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF24_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF24_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF24_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF24_mex.mki
echo "Arch=$Arch" >> sprdmpF24_mex.mki
echo "LD=$LD" >> sprdmpF24_mex.mki
echo OMPFLAGS= >> sprdmpF24_mex.mki
echo OMPLINKFLAGS= >> sprdmpF24_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF24_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF24_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF24_mex.mk
