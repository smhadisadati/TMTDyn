MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF94" > sprdmpF94_mex.mki
echo "CC=$CC" >> sprdmpF94_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF94_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF94_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF94_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF94_mex.mki
echo "CXX=$CXX" >> sprdmpF94_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF94_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF94_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF94_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF94_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF94_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF94_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF94_mex.mki
echo "Arch=$Arch" >> sprdmpF94_mex.mki
echo "LD=$LD" >> sprdmpF94_mex.mki
echo OMPFLAGS= >> sprdmpF94_mex.mki
echo OMPLINKFLAGS= >> sprdmpF94_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF94_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF94_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF94_mex.mk
