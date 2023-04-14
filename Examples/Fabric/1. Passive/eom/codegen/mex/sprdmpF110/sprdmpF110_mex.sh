MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF110" > sprdmpF110_mex.mki
echo "CC=$CC" >> sprdmpF110_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF110_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF110_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF110_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF110_mex.mki
echo "CXX=$CXX" >> sprdmpF110_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF110_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF110_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF110_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF110_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF110_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF110_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF110_mex.mki
echo "Arch=$Arch" >> sprdmpF110_mex.mki
echo "LD=$LD" >> sprdmpF110_mex.mki
echo OMPFLAGS= >> sprdmpF110_mex.mki
echo OMPLINKFLAGS= >> sprdmpF110_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF110_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF110_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF110_mex.mk
