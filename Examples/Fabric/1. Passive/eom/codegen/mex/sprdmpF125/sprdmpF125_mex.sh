MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF125" > sprdmpF125_mex.mki
echo "CC=$CC" >> sprdmpF125_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF125_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF125_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF125_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF125_mex.mki
echo "CXX=$CXX" >> sprdmpF125_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF125_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF125_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF125_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF125_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF125_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF125_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF125_mex.mki
echo "Arch=$Arch" >> sprdmpF125_mex.mki
echo "LD=$LD" >> sprdmpF125_mex.mki
echo OMPFLAGS= >> sprdmpF125_mex.mki
echo OMPLINKFLAGS= >> sprdmpF125_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF125_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF125_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF125_mex.mk
