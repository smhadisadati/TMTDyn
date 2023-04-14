MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF70" > sprdmpF70_mex.mki
echo "CC=$CC" >> sprdmpF70_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF70_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF70_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF70_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF70_mex.mki
echo "CXX=$CXX" >> sprdmpF70_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF70_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF70_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF70_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF70_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF70_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF70_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF70_mex.mki
echo "Arch=$Arch" >> sprdmpF70_mex.mki
echo "LD=$LD" >> sprdmpF70_mex.mki
echo OMPFLAGS= >> sprdmpF70_mex.mki
echo OMPLINKFLAGS= >> sprdmpF70_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF70_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF70_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF70_mex.mk
