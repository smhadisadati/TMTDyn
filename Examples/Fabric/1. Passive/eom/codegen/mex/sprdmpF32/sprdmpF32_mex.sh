MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF32" > sprdmpF32_mex.mki
echo "CC=$CC" >> sprdmpF32_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF32_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF32_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF32_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF32_mex.mki
echo "CXX=$CXX" >> sprdmpF32_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF32_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF32_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF32_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF32_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF32_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF32_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF32_mex.mki
echo "Arch=$Arch" >> sprdmpF32_mex.mki
echo "LD=$LD" >> sprdmpF32_mex.mki
echo OMPFLAGS= >> sprdmpF32_mex.mki
echo OMPLINKFLAGS= >> sprdmpF32_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF32_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF32_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF32_mex.mk
