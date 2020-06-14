MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF64" > sprdmpF64_mex.mki
echo "CC=$CC" >> sprdmpF64_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF64_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF64_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF64_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF64_mex.mki
echo "CXX=$CXX" >> sprdmpF64_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF64_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF64_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF64_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF64_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF64_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF64_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF64_mex.mki
echo "Arch=$Arch" >> sprdmpF64_mex.mki
echo "LD=$LD" >> sprdmpF64_mex.mki
echo OMPFLAGS= >> sprdmpF64_mex.mki
echo OMPLINKFLAGS= >> sprdmpF64_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF64_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF64_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF64_mex.mk
