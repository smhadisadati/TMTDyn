MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF16" > sprdmpF16_mex.mki
echo "CC=$CC" >> sprdmpF16_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF16_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF16_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF16_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF16_mex.mki
echo "CXX=$CXX" >> sprdmpF16_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF16_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF16_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF16_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF16_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF16_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF16_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF16_mex.mki
echo "Arch=$Arch" >> sprdmpF16_mex.mki
echo "LD=$LD" >> sprdmpF16_mex.mki
echo OMPFLAGS= >> sprdmpF16_mex.mki
echo OMPLINKFLAGS= >> sprdmpF16_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF16_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF16_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF16_mex.mk
