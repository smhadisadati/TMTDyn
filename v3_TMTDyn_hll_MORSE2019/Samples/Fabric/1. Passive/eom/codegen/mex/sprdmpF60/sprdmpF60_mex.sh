MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF60" > sprdmpF60_mex.mki
echo "CC=$CC" >> sprdmpF60_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF60_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF60_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF60_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF60_mex.mki
echo "CXX=$CXX" >> sprdmpF60_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF60_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF60_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF60_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF60_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF60_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF60_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF60_mex.mki
echo "Arch=$Arch" >> sprdmpF60_mex.mki
echo "LD=$LD" >> sprdmpF60_mex.mki
echo OMPFLAGS= >> sprdmpF60_mex.mki
echo OMPLINKFLAGS= >> sprdmpF60_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF60_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF60_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF60_mex.mk
