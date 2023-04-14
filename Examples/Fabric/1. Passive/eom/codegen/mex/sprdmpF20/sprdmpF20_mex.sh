MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF20" > sprdmpF20_mex.mki
echo "CC=$CC" >> sprdmpF20_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF20_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF20_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF20_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF20_mex.mki
echo "CXX=$CXX" >> sprdmpF20_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF20_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF20_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF20_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF20_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF20_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF20_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF20_mex.mki
echo "Arch=$Arch" >> sprdmpF20_mex.mki
echo "LD=$LD" >> sprdmpF20_mex.mki
echo OMPFLAGS= >> sprdmpF20_mex.mki
echo OMPLINKFLAGS= >> sprdmpF20_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF20_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF20_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF20_mex.mk
