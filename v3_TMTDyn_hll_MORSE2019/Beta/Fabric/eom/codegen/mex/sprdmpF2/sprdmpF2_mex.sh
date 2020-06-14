MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF2" > sprdmpF2_mex.mki
echo "CC=$CC" >> sprdmpF2_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF2_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF2_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF2_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF2_mex.mki
echo "CXX=$CXX" >> sprdmpF2_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF2_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF2_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF2_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF2_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF2_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF2_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF2_mex.mki
echo "Arch=$Arch" >> sprdmpF2_mex.mki
echo "LD=$LD" >> sprdmpF2_mex.mki
echo OMPFLAGS= >> sprdmpF2_mex.mki
echo OMPLINKFLAGS= >> sprdmpF2_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF2_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF2_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF2_mex.mk
