MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF98" > sprdmpF98_mex.mki
echo "CC=$CC" >> sprdmpF98_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF98_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF98_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF98_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF98_mex.mki
echo "CXX=$CXX" >> sprdmpF98_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF98_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF98_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF98_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF98_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF98_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF98_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF98_mex.mki
echo "Arch=$Arch" >> sprdmpF98_mex.mki
echo "LD=$LD" >> sprdmpF98_mex.mki
echo OMPFLAGS= >> sprdmpF98_mex.mki
echo OMPLINKFLAGS= >> sprdmpF98_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF98_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF98_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF98_mex.mk
