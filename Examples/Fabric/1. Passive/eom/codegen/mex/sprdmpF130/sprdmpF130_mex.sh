MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF130" > sprdmpF130_mex.mki
echo "CC=$CC" >> sprdmpF130_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF130_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF130_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF130_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF130_mex.mki
echo "CXX=$CXX" >> sprdmpF130_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF130_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF130_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF130_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF130_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF130_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF130_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF130_mex.mki
echo "Arch=$Arch" >> sprdmpF130_mex.mki
echo "LD=$LD" >> sprdmpF130_mex.mki
echo OMPFLAGS= >> sprdmpF130_mex.mki
echo OMPLINKFLAGS= >> sprdmpF130_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF130_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF130_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF130_mex.mk
