MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF44" > sprdmpF44_mex.mki
echo "CC=$CC" >> sprdmpF44_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF44_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF44_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF44_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF44_mex.mki
echo "CXX=$CXX" >> sprdmpF44_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF44_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF44_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF44_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF44_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF44_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF44_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF44_mex.mki
echo "Arch=$Arch" >> sprdmpF44_mex.mki
echo "LD=$LD" >> sprdmpF44_mex.mki
echo OMPFLAGS= >> sprdmpF44_mex.mki
echo OMPLINKFLAGS= >> sprdmpF44_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF44_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF44_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF44_mex.mk
