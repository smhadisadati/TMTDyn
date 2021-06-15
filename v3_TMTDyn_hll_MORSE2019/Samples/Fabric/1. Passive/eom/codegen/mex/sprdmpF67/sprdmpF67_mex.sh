MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF67" > sprdmpF67_mex.mki
echo "CC=$CC" >> sprdmpF67_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF67_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF67_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF67_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF67_mex.mki
echo "CXX=$CXX" >> sprdmpF67_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF67_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF67_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF67_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF67_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF67_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF67_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF67_mex.mki
echo "Arch=$Arch" >> sprdmpF67_mex.mki
echo "LD=$LD" >> sprdmpF67_mex.mki
echo OMPFLAGS= >> sprdmpF67_mex.mki
echo OMPLINKFLAGS= >> sprdmpF67_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF67_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF67_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF67_mex.mk
