MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF39" > sprdmpF39_mex.mki
echo "CC=$CC" >> sprdmpF39_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF39_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF39_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF39_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF39_mex.mki
echo "CXX=$CXX" >> sprdmpF39_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF39_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF39_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF39_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF39_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF39_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF39_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF39_mex.mki
echo "Arch=$Arch" >> sprdmpF39_mex.mki
echo "LD=$LD" >> sprdmpF39_mex.mki
echo OMPFLAGS= >> sprdmpF39_mex.mki
echo OMPLINKFLAGS= >> sprdmpF39_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF39_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF39_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF39_mex.mk
